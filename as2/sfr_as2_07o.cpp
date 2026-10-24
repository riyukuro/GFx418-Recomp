// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// the action executor for WaitForFrame and WaitForFrame2, which skips the following actions while the frame has not
// loaded yet.
// MS2-UNIT: sfr_as2_07o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142994a10-0x142994ba5 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {
// The members of the action buffer's execution context the executor reads, at the exe's offsets (as sfr_as2_06z2).
struct ExecContextView
{
    Environment*          pEnv;            // +0x00
    InteractiveObject*    pOriginalTarget; // +0x08
    const UByte*          pBuffer;         // +0x10
    void*                 pPrevLog;        // +0x18
    int                   StopPC;          // +0x20
    int                   NextPC;          // +0x24
    int                   PC;              // +0x28
    MemoryHeap*           pHeap;           // +0x30 with stack holder
    const WithStackArray* pWithStack;      // +0x38
    ActionLogger          LogF;            // +0x40
    UByte                 Version;         // +0x60
    UByte                 ExecType;        // +0x61
    UByte                 Flags;           // +0x62 bit 0: verbose action errors, bit 1: verbose actions

    bool IsVerboseActionErrors() const { return (Flags & 1) != 0; }
};
static_assert(offsetof(ExecContextView, NextPC) == 0x24, "next pc");
static_assert(offsetof(ExecContextView, LogF) == 0x40, "logger");
static_assert(offsetof(ExecContextView, Flags) == 0x62, "flags");

const int Action_WaitForFrame = 0x8a;

// The protected parts of ActionBuffer the executor uses.
struct ActionBufferAccess : ActionBuffer
{
    static unsigned GetLength(const ActionBuffer* pbuf)
    {
        return (pbuf->*&ActionBufferAccess::pBufferData)->GetLength();
    }
    static bool ResolveFrame(ActionBuffer* pbuf, Environment* penv, const Value& frame, unsigned* pframe)
    {
        return (pbuf->*&ActionBufferAccess::ResolveFrameNumber)(penv, frame, 0, pframe);
    }
};
} // namespace

// The frame (a number in the action, or a value on the stack for WaitForFrame2) and the count of actions to skip
// when that frame of the target sprite is not loaded.
// MS2-FUNCTIONAL: the exe inlines the stack pop and the action length walk; same behavior
// @0x142994a10
void FUN_142994a10(void* pctx, ActionBuffer* pbuf, int actionId)
{
    ExecContextView& ctx     = *static_cast<ExecContextView*>(pctx);
    Environment*     penv    = ctx.pEnv;
    unsigned         frame   = 0;
    Sprite*          psprite = 0;
    if (!penv->IsInvalidTarget && penv->Target->IsSprite())
        psprite = static_cast<Sprite*>(penv->Target);

    bool  resolved;
    UByte skipCount;
    if (actionId == Action_WaitForFrame)
    {
        resolved  = true;
        frame     = *reinterpret_cast<const UInt16*>(ctx.pBuffer + ctx.PC + 3);
        skipCount = ctx.pBuffer[ctx.PC + 5];
    }
    else
    {
        resolved  = ActionBufferAccess::ResolveFrame(pbuf, penv, penv->Top(0), &frame);
        skipCount = ctx.pBuffer[ctx.PC + 3];
        penv->Drop1();
    }

    if (!psprite || !resolved)
        return;

    unsigned frameCount = psprite->pDef->GetFrameCount();
    if (frameCount != 0 && frame >= frameCount)
        frame = frameCount - 1;
    if (psprite->GetLoadingFrame() > frame)
        return;

    // Not loaded yet: skip the next skipCount actions (an action >= 0x80 has a 16-bit length after its code).
    const unsigned length = ActionBufferAccess::GetLength(pbuf);
    const unsigned start  = (unsigned)ctx.NextPC;
    unsigned       pc     = start;
    for (unsigned i = 0; i < skipCount; ++i)
    {
        if (pc >= length)
            break;
        if (ctx.pBuffer[pc] & 0x80)
            pc += 3 + *reinterpret_cast<const UInt16*>(ctx.pBuffer + pc + 1);
        else
            pc += 1;
    }
    if (pc < length)
        ctx.NextPC = (int)pc;
    else if (ctx.IsVerboseActionErrors())
        ctx.LogF.LogScriptError("WaitForFrame branch to offset %d - this section only runs to %d", start,
                                ctx.StopPC);
}

}}} // namespace Scaleform::GFx::AS2
