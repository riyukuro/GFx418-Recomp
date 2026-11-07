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

// Environment::Top() / Top1(), inlined: the stack top and the slot below it.
SF_FORCEINLINE Value& LzTop0(Environment* penv) { return *penv->Stack.pCurrent; }
SF_FORCEINLINE Value& LzTop1(Environment* penv)
{
    return *((penv->Stack.pCurrent > penv->Stack.pPageStart) ? (penv->Stack.pCurrent - 1) : penv->Stack.pPrevPageTop);
}

// Value::ToStringVersioned (exe 0x1429923c0), inlined: undefined is "" up to SWF 6.
SF_FORCEINLINE ASString ToStringVersionedInline(const Value& val, Environment* penv, unsigned version)
{
    if (val.IsUndefined())
    {
        if (version > 0 && version <= 6)
            return penv->GetBuiltin(ASBuiltin_empty_);
        return penv->GetBuiltin(ASBuiltin_undefined);
    }
    return val.ToStringImpl(penv, -1, 0);
}

// Value::ToCharacter (exe 0x1429910b0), inlined.
SF_FORCEINLINE InteractiveObject* ToCharacterInline(const Value& val, const Environment* penv)
{
    if (val.T.Type == Value::CHARACTER && penv && val.V.pCharHandle)
    {
        DisplayObject* pdisp = val.V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
        if (pdisp)
            return pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
    }
    return 0;
}

// Environment::SetTarget / SetInvalidTarget, inlined.
SF_FORCEINLINE void SetTargetInline(Environment* penv, InteractiveObject* ptarget)
{
    penv->IsInvalidTarget = false;
    penv->Target          = ptarget;
    penv->StringContext.UpdateVersion(ptarget->GetVersion());
}
SF_FORCEINLINE void SetInvalidTargetInline(Environment* penv, InteractiveObject* ptarget)
{
    penv->IsInvalidTarget = true;
    penv->Target          = ptarget;
}

// Pixels to twips.
const float PixelsToTwips = 20.0f;
} // namespace

// Pops a target (a character or a path) and makes it the current target; an empty path is the original target,
// one that does not resolve leaves the original target marked invalid.
// MS2-FUNCTIONAL: SDK body with the inlined resolve/SetTarget/pop, 758 vs 747; the exe falls from the convert
// into the string branch without re-testing the type and swaps rsi/rdi (nested and comma forms placed it worse)
// @0x14298bb90
void FUN_14298bb90(void* pctx)
{
    ExecContextView&   ctx    = *static_cast<ExecContextView*>(pctx);
    InteractiveObject* target = 0;

    Value targetVal = LzTop0(ctx.pEnv);
    if (!targetVal.IsString() && !targetVal.IsCharacter())
        targetVal.SetString(ToStringVersionedInline(targetVal, ctx.pEnv, ctx.Version));

    if (targetVal.IsString())
    {
        if (targetVal.ToString(ctx.pEnv).IsEmpty())
            target = ctx.pOriginalTarget;
        else
        {
            Value val;
            ctx.pEnv->GetVariable(LzTop0(ctx.pEnv).ToString(ctx.pEnv), &val, ctx.pWithStack, &target);
            if (ctx.IsVerboseAction())
            {
                ASString s1(LzTop0(ctx.pEnv).ToStringImpl(ctx.pEnv, -1, true));
                if (target)
                    ctx.LogF.LogAction("-- ActionSetTarget2: %s (%d)\n", s1.ToCStr(), (UInt16)target->Id);
                else
                    ctx.LogF.LogAction("-- ActionSetTarget2: %s - no target found\n", s1.ToCStr());
            }
        }
    }
    else if (targetVal.IsCharacter())
        target = ToCharacterInline(LzTop0(ctx.pEnv), ctx.pEnv);

    if (!target)
    {
        if (ctx.IsVerboseActionErrors())
        {
            ASString sv(targetVal.ToStringImpl(ctx.pEnv, -1, true));
            ctx.LogF.LogScriptError("SetTarget2(tellTarget) with invalid target '%s'.", sv.ToCStr());
        }
        SetInvalidTargetInline(ctx.pEnv, ctx.pOriginalTarget);
    }
    else
        SetTargetInline(ctx.pEnv, target);
    ctx.pEnv->Drop1();
}

// Stack: target, lockCenter, constrain [, x1, y1, x2, y2 when constrained]. The bounds are in pixels.
// MS2-FUNCTIONAL: LTCG store-merge/regalloc: the exe zeroes the DragState points with three qword stores (ours one movups), orders the pEnv load in the error path differently and has no loop-alignment nop before the Drop(4) loop
// @0x14298fea0
void FUN_14298fea0(void* pctx)
{
    ExecContextView&     ctx  = *static_cast<ExecContextView*>(pctx);
    MovieImpl::DragState st;

    bool lockCenter = LzTop1(ctx.pEnv).ToBool(ctx.pEnv);
    st.pCharacter   = ctx.pEnv->FindTargetByValue(LzTop0(ctx.pEnv));
    if (!st.pCharacter && ctx.IsVerboseActionErrors())
        ctx.LogF.LogScriptError("StartDrag of invalid target '%s'.", LzTop0(ctx.pEnv).ToStringImpl(ctx.pEnv, -1, true).ToCStr());

    st.Bound = ctx.pEnv->Top(2).ToBool(ctx.pEnv);
    if (st.Bound)
    {
        st.BoundLT.x = (float)ctx.pEnv->Top(6).ToNumber(ctx.pEnv) * PixelsToTwips;
        st.BoundLT.y = (float)ctx.pEnv->Top(5).ToNumber(ctx.pEnv) * PixelsToTwips;
        st.BoundRB.x = (float)ctx.pEnv->Top(4).ToNumber(ctx.pEnv) * PixelsToTwips;
        st.BoundRB.y = (float)ctx.pEnv->Top(3).ToNumber(ctx.pEnv) * PixelsToTwips;
        ctx.pEnv->Drop(4);
    }

    if (st.pCharacter)
    {
        st.InitCenterDelta(lockCenter);
        if (MovieImpl* pmovie = ctx.pEnv->GetTarget()->GetMovieImpl())
            pmovie->SetDragState(st);
    }
    ctx.pEnv->Stack.Pop3();
}

}}} // namespace Scaleform::GFx::AS2
