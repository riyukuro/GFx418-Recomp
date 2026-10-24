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

// A variable by name or path: a plain name goes to SetVariableRaw, a path to the object its owner part resolves to.
// MS2-FUNCTIONAL: the cached path test and the string releases are inlined differently
// @0x14298cce0
bool Environment::SetVariable(const ASString& varname, const Value& val, const WithStackArray* pwithStack,
                              bool doDisplayErrors)
{
    if (IsVerboseAction())
        LogAction("-------------- %s = %s\n", varname.ToCStr(), val.ToDebugString(this).ToCStr());

    unsigned flags = varname.GetHashFlags();
    if (!((flags >> 25) & 1))
    {
        if (!(flags & ASString::Flag_PathCheck))
        {
            const char* pstr = varname.ToCStr();
            if (!strchr(pstr, ':') && !strchr(pstr, '/') && !strchr(pstr, '.'))
            {
                varname.SetPathFlags(ASString::Flag_PathCheck | ASString::Flag_IsNotPath);
                SetVariableRaw(varname, val, pwithStack);
                return true;
            }
            varname.SetPathFlags(ASString::Flag_PathCheck);
        }
        Value        owner;
        Value        result;
        ASString     memberName(GetBuiltin(ASBuiltin_empty_));
        GetVarParams params(varname, &result, pwithStack, 0, &owner, 0);
        FindVariable(params, false, &memberName);
        if (owner.IsUndefined())
        {
            if (doDisplayErrors && IsVerboseActionErrors())
                LogScriptError("SetVariable failed: can't resolve the path \"%s\"", varname.ToCStr());
            return false;
        }
        ObjectInterface* piface;
        if (owner.IsCharacter())
        {
            InteractiveObject* pchar = owner.ToCharacter(this);
            piface                   = pchar ? ToAvmCharacter(pchar) : 0;
        }
        else
            piface = owner.ToObject(this);
        if (!piface)
            return false;
        piface->SetMember(this, memberName, val, PropFlags(0));
        return true;
    }
    SetVariableRaw(varname, val, pwithStack);
    return true;
}

}}} // namespace Scaleform::GFx::AS2
