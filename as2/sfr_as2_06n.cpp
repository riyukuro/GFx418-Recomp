// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr31): Environment::SetVariable.
// MS2-UNIT: sfr_as2_06n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298cce0-0x14298cfab .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

inline bool Environment::IsVerboseAction() const
{
    return (GetTarget()->GetMovieImpl()->Flags & MovieImpl::Flag_VerboseAction) != 0;
}

// The SDK's Value::ToDebugString.
static SF_FORCEINLINE ASString ToDebugString06(const Value& v, Environment* penv) { return v.ToStringImpl(penv, -1, true); }

// The SDK's IsPath, which caches the path test in the string's flags.
static SF_FORCEINLINE bool IsPath06(const ASString& varPath)
{
    if (varPath.GetHashFlags() & ASString::Flag_PathCheck)
        return 1;
    const char* pstr = varPath.ToCStr();
    if (strchr(pstr, ':') != NULL || strchr(pstr, '/') != NULL || strchr(pstr, '.') != NULL)
    {
        varPath.SetPathFlags(ASString::Flag_PathCheck | 0);
        return 1;
    }
    else
    {
        varPath.SetPathFlags(ASString::Flag_PathCheck | ASString::Flag_IsNotPath);
        return 0;
    }
}

// The SDK's Value::ToCharacter.
static SF_FORCEINLINE InteractiveObject* ToCharacter06(const Value& v, Environment* penv)
{
    if (v.GetType() == Value::CHARACTER && penv)
    {
        if (v.V.pCharHandle)
        {
            DisplayObject* dob = v.V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
            return (dob) ? (dob->IsInteractiveObject() ? static_cast<InteractiveObject*>(dob) : NULL) : NULL;
        }
    }
    return 0;
}

// The SDK's Value::ToObjectInterface with ToAvmCharacter inlined.
static SF_FORCEINLINE ObjectInterface* ToObjectInterface06(const Value& v, Environment* penv)
{
    if (v.GetType() == Value::CHARACTER)
        return ToAvmCharacter(ToCharacter06(v, penv));
    return v.ToObject(penv);
}

// A variable by name or path: a plain name goes to SetVariableRaw, a path to the object its owner part resolves to.
// MS2-FUNCTIONAL: register allocation: the exe holds this/varname/0 in rbx/rdi/rsi (ours rdi/rsi/rbx) and re-reads
// the debug string node after LogAction; the code is otherwise the same (713 of 716 bytes).
// @0x14298cce0
bool Environment::SetVariable(const ASString& varname, const Value& val, const WithStackArray* pwithStack,
                              bool doDisplayErrors)
{
    if (IsVerboseAction())
    {
        ASString vs(ToDebugString06(Value(val), this));
        LogAction("-------------- %s = %s\n", varname.ToCStr(), vs.ToCStr());
    }

    if (((UByte)(varname.GetHashFlags() >> 25) & 1) || !IsPath06(varname))
    {
        SetVariableRaw(varname, val, pwithStack);
        return true;
    }
    else
    {
        Value    owner;
        ASString var(GetBuiltin(ASBuiltin_empty_));
        Value    curval;
        FindVariable(GetVarParams(varname, &curval, pwithStack, 0, &owner), false, &var);
        if (!owner.IsUndefined())
        {
            ObjectInterface* pobj = ToObjectInterface06(owner, this);
            if (pobj)
            {
                pobj->SetMember(this, var, val);
                return true;
            }
        }
        else
        {
            if (doDisplayErrors && IsVerboseActionErrors())
                LogScriptError("SetVariable failed: can't resolve the path \"%s\"", varname.ToCStr());
        }
    }
    return false;
}

}}} // namespace Scaleform::GFx::AS2
