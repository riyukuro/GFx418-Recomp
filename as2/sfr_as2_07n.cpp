// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// the common body of setInterval and setTimeout, which makes the timer and hands it to the movie.
// MS2-UNIT: sfr_as2_07n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297f3d0-0x14297fab2 .text$mn

#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform {
// The Value array grows out of line (0x14297e710, explicit instantiation in sfr_as2_07).
template<> void ArrayDataBase<GFx::AS2::Value, AllocatorGH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::ResizeNoConstruct(
    const void* pheapAddr, UPInt newSize);
}

namespace Scaleform { namespace GFx { namespace AS2 {

struct SetLocalFrameInlineTag {};

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it in Value::ToFunction here.
static SF_FORCEINLINE void FunctionRefSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
{
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->Release();
    p->pLocalFrame = localFrame;
    if (weakRef)
        p->Flags |= FunctionRefBase::FuncRef_Weak;
    else
        p->Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->AddRef();
}

// FunctionRefBase::Init(orig) with the SetLocalFrame call expanded.
template<class Tag>
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, Tag)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        FunctionRefSetLocalFrame(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

// Value::ToFunction (as2_object.h) with the frame copy above, its cases as a switch.
struct ValueAccess : Value
{
    using Value::ResolveFunctionName;
};
static SF_FORCEINLINE FunctionRef ValueToFunction(const Value& v, const Environment* penv)
{
    switch (v.GetType())
    {
    case Value::FUNCTION:
        return FunctionRef(v.V.FunctionValue, SetLocalFrameInlineTag());
    case Value::FUNCTIONNAME:
        return static_cast<const ValueAccess&>(v).ResolveFunctionName(penv);
    }
    return FunctionRef();
}

// The out-of-line constructors (0x14291cf60 / 0x14291d030 in sfr_as2_03r), inlined into Set as in the exe.
__forceinline IntervalTimer::IntervalTimer(const FunctionRefBase& fn, ASStringContext* psc, InlineCtorTag)
    : Function(fn), MethodName(psc->GetBuiltin(ASBuiltin_empty_)), Interval(0), InvokeTime(0), Id(0), Active(true),
      Unrecovered_79(false)
{
}
__forceinline IntervalTimer::IntervalTimer(InteractiveObject* ptarget, const ASString& method, InlineCtorTag)
    : pTarget(ptarget), MethodName(method), Interval(0), InvokeTime(0), Id(0), Active(true), Unrecovered_79(false)
{
}

// @0x14297f3d0
void IntervalTimer::Set(const FnCall& fn, bool isTimeout)
{
    fn.Result->SetUndefined();
    if (fn.NArgs < 2)
        return;
    Ptr<IntervalTimer> ptimer;
    int                nextArg = 1;
    MemoryHeap*        pheap   = fn.Env->GetHeap();

    if (fn.Arg(0).IsFunction())
    {
        // setInterval(func, ms, ...)
        ptimer = *SF_HEAP_NEW(pheap) IntervalTimer(ValueToFunction(fn.Arg(0), fn.Env), fn.Env->GetSC(), InlineCtorTag());
    }
    else if (fn.Arg(0).IsObject())
    {
        // setInterval(obj, "method", ms, ...)
        ptimer = *SF_HEAP_NEW(pheap) IntervalTimer(fn.Arg(0).ToObject(fn.Env), fn.Arg(1).ToString(fn.Env));
        ++nextArg;
    }
    else if (fn.Arg(0).IsCharacter())
    {
        // setInterval(mc, "method", ms, ...)
        ptimer = *SF_HEAP_NEW(pheap)
            IntervalTimer(fn.Arg(0).ToCharacter(fn.Env), fn.Arg(1).ToString(fn.Env), InlineCtorTag());
        ++nextArg;
    }
    else
        return;

    if (fn.NArgs <= nextArg) // no interval given
        return;

    // The timer keeps the movie's root alive by its handle.
    if (fn.Env->GetTarget())
        ptimer->Character = fn.Env->GetTarget()->GetTopParent()->GetCharacterHandle();
    ptimer->Interval       = UInt64(fn.Arg(nextArg++).ToNumber(fn.Env)) * 1000; // ms to mks
    ptimer->Unrecovered_79 = isTimeout;
    for (int i = nextArg; i < fn.NArgs; ++i)
        ptimer->Params.PushBack(fn.Arg(i));

    MovieImpl* pmovie = fn.Env->GetTarget()->GetMovieImpl();
    int        id     = pmovie->AddIntervalTimer(ptimer);
    fn.Result->SetNumber(Number(id));
    ptimer->Start(pmovie);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7IntervalTimer@AS2@GFx@Scaleform@@6B@ 0x14321bd70
// MS2-PIN: ??_7RefCountImplCore@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7RefCountImpl@Scaleform@@6B@ 0x142dc9d58
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
// ASIntervalTimerIntf's is the table ~IntervalTimer (0x1429259d0) stores last before ~RefCountImplCore;
// slot 0 is its deleting destructor 0x1424e21a0.
// MS2-PIN: ??_7ASIntervalTimerIntf@GFx@Scaleform@@6B@ 0x14317c9f8
// MS2-PIN: ??_7?$RefCountBase@VASIntervalTimerIntf@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
