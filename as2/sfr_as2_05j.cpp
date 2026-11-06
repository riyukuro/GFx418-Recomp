// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 GAS_Invoke with the receiver
// as a value, gap function of sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142946a80-0x142946d00 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

struct SetLocalFrameInlineTag {};

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it here.
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

// Value::ToFunction with the cases as a switch.
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

// @0x142946a80
bool GAS_Invoke(const Value& method, Value* presult, const Value& thisVal, Environment* penv, int nargs,
                int firstArgBottomIndex, const char* pmethodName)
{
    FunctionRef func = ValueToFunction(method, penv);
    if (presult)
        presult->SetUndefined();
    if (!func.IsNull())
    {
        func.Invoke(FnCall(presult, thisVal, penv, nargs, firstArgBottomIndex), pmethodName);
        return true;
    }
    if (penv && penv->IsVerboseActionErrors())
    {
        if (thisVal.ToCharacter(penv))
            penv->LogScriptError("Invoked method %s.%s is not a function",
                                 thisVal.ToCharacter(penv)->GetCharacterHandle()->NamePath.ToCStr(),
                                 pmethodName ? pmethodName : "<unknown>");
        else
            penv->LogScriptError("Invoked method %s is not a function", pmethodName ? pmethodName : "<unknown>");
    }
    return false;
}

} } }
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
