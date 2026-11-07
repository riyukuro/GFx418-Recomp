// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 FnCall constructor taking the
// this value (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03u
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291be60-0x14291c005 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The LTCG-folded temp ref: no clearing dtor, released by hand.
union FnCallRefHolder
{
    FunctionRefBase v;
    SF_FORCEINLINE FnCallRefHolder() {}
    SF_FORCEINLINE ~FnCallRefHolder() {}
};
struct FnCallValueAccess : Value
{
    using Value::ResolveFunctionName;
};

// MS2-FUNCTIONAL: the function ref is built by hand in a union temp, as the exe (LTCG) folds ToFunction and
// ~FunctionRef, and its fields are kept in locals across Assign. Left: the exe takes the weak flag as a setne bool
// and keeps the default case's fields as reloads from the zeroed temp; ours folds both (regalloc and flag stores).
// @0x14291be60
FnCall::FnCall(Value* res, const Value& thisVal, Environment* penv, int nargs, int firstArgBottomIndex)
    : Result(res), ThisPtr(thisVal.ToObjectInterface(penv)), Env(penv), NArgs(nargs),
      FirstArgBottomIndex(firstArgBottomIndex)
{
    if (thisVal.GetType() == Value::FUNCTION || thisVal.GetType() == Value::FUNCTIONNAME)
    {
        FnCallRefHolder h;
        FunctionObject* f;
        LocalFrame*     lf;
        UByte           fl;
        switch (thisVal.GetType())
        {
        case Value::FUNCTION:
        {
            const FunctionRefBase& orig = thisVal.V.FunctionValue;
            f  = orig.Function;
            fl = 0;
            h.v.Flags    = fl;
            h.v.Function = f;
            if (f)
                f->AddRef();
            lf = 0;
            h.v.pLocalFrame = lf;
            if (orig.pLocalFrame)
            {
                lf = orig.pLocalFrame;
                h.v.pLocalFrame = lf;
                if (orig.Flags & FunctionRefBase::FuncRef_Weak)
                    fl |= FunctionRefBase::FuncRef_Weak;
                else
                    fl &= ~FunctionRefBase::FuncRef_Weak;
                h.v.Flags = fl;
                if (!(fl & FunctionRefBase::FuncRef_Weak))
                    lf->AddRef();
            }
            break;
        }
        case Value::FUNCTIONNAME:

            ::new (&h.v) FunctionRef(static_cast<const FnCallValueAccess&>(thisVal).ResolveFunctionName(penv));
            fl = h.v.Flags;
            lf = h.v.pLocalFrame;
            f  = h.v.Function;
            break;
        default:
            ::new (&h.v) FunctionRef();
            fl = h.v.Flags;
            lf = h.v.pLocalFrame;
            f  = h.v.Function;
            break;
        }
        ThisFunctionRef.Assign(h.v);
        if (!(fl & FunctionRefBase::FuncRef_Internal) && f)
            f->Release();
        if (!(fl & FunctionRefBase::FuncRef_Weak) && lf)
            lf->Release();
    }
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
