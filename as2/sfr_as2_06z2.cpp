// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 action executors for
// SetTarget2 (tellTarget by value) and StartDrag (gap recovery of sfr_as2_06).
// MS2-UNIT: sfr_as2_06z2
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298bb90-0x14298be7b .text$mn
// MS2-RANGE: 0x14298fea0-0x142990205 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {
// The members of the action buffer's execution context these executors read, at the exe's offsets.
struct ExecContextView
{
    Environment*          pEnv;            // +0x00
    InteractiveObject*    pOriginalTarget; // +0x08
    void*                 pBuffer;         // +0x10
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
    bool IsVerboseAction() const { return (Flags & 2) != 0; }
};
static_assert(offsetof(ExecContextView, pWithStack) == 0x38, "with stack");
static_assert(offsetof(ExecContextView, LogF) == 0x40, "logger");
static_assert(offsetof(ExecContextView, Version) == 0x60, "version");
static_assert(offsetof(ExecContextView, Flags) == 0x62, "flags");

// Pixels to twips.
const float PixelsToTwips = 20.0f;
} // namespace

// Pops a target (a character or a path) and makes it the current target; an empty path is the original target,
// one that does not resolve leaves the original target marked invalid.
// MS2-FUNCTIONAL: the exe inlines the character resolve, SetTarget/SetInvalidTarget and the stack pop
// @0x14298bb90
void FUN_14298bb90(void* pctx)
{
    ExecContextView&   ctx     = *static_cast<ExecContextView*>(pctx);
    Environment*       penv    = ctx.pEnv;
    InteractiveObject* ptarget = 0;
    Value              target  = penv->Top(0);

    if (target.IsCharacter())
        ptarget = penv->Top(0).ToCharacter(penv);
    else
    {
        if (!target.IsString())
        {
            if (target.IsUndefined())
                target.ConvertToStringVersioned(penv, ctx.Version);
            else
                target.SetString(target.ToString(penv));
        }
        if (target.ToString(penv).IsEmpty())
            ptarget = ctx.pOriginalTarget;
        else
        {
            Value val;
            penv->GetVariable(penv->Top(0).ToString(penv), &val, ctx.pWithStack, &ptarget);
            if (ctx.IsVerboseAction())
            {
                ASString name = penv->Top(0).ToStringImpl(penv, -1, true);
                if (ptarget)
                    ctx.LogF.LogAction("-- ActionSetTarget2: %s (%d)\n", name.ToCStr(), (UInt16)ptarget->Id);
                else
                    ctx.LogF.LogAction("-- ActionSetTarget2: %s - no target found\n", name.ToCStr());
            }
        }
    }

    if (ptarget)
        penv->SetTarget(ptarget);
    else
    {
        if (ctx.IsVerboseActionErrors())
            ctx.LogF.LogScriptError("SetTarget2(tellTarget) with invalid target '%s'.",
                                    target.ToStringImpl(penv, -1, true).ToCStr());
        penv->SetInvalidTarget(ctx.pOriginalTarget);
    }
    penv->Drop1();
}

// Stack: target, lockCenter, constrain [, x1, y1, x2, y2 when constrained]. The bounds are in pixels.
// MS2-FUNCTIONAL: the exe reads the stack slots and stores the drag state through inlined copies
// @0x14298fea0
void FUN_14298fea0(void* pctx)
{
    ExecContextView&     ctx  = *static_cast<ExecContextView*>(pctx);
    Environment*         penv = ctx.pEnv;
    MovieImpl::DragState st;

    bool lockCenter = penv->Top(1).ToBool(penv);
    st.pCharacter   = penv->FindTargetByValue(penv->Top(0));
    if (!st.pCharacter && ctx.IsVerboseActionErrors())
        ctx.LogF.LogScriptError("StartDrag of invalid target '%s'.", penv->Top(0).ToStringImpl(penv, -1, true).ToCStr());

    st.Bound = penv->Top(2).ToBool(penv);
    if (st.Bound)
    {
        st.BoundLT.x = (float)penv->Top(6).ToNumber(penv) * PixelsToTwips;
        st.BoundLT.y = (float)penv->Top(5).ToNumber(penv) * PixelsToTwips;
        st.BoundRB.x = (float)penv->Top(4).ToNumber(penv) * PixelsToTwips;
        st.BoundRB.y = (float)penv->Top(3).ToNumber(penv) * PixelsToTwips;
        penv->Drop(4);
    }

    if (st.pCharacter)
    {
        st.InitCenterDelta(lockCenter);
        if (MovieImpl* pmovie = penv->GetTarget()->GetMovieImpl())
            pmovie->SetDragState(st);
    }
    penv->Drop(3);
}

}}} // namespace Scaleform::GFx::AS2
