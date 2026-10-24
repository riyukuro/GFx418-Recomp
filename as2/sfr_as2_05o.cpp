// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Environment::FindVariable of
// sfr_as2_05 (gap recovery, lane sfr36): the resolution of a variable path ("a.b", "/a/b:c", "_parent.x").
// MS2-UNIT: sfr_as2_05o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142945010-0x142945b1e .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"

#include <string.h>

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// Splits a path at any of the delimiter characters; the set can change between tokens. Every call eats one
// delimiter: two delimiters in a row give an empty token.
class PathTokenizer
{
    const char*       Str;
    const char* const EndStr;
    const char*       Delimiters;
    ASString          Token;

public:
    PathTokenizer(ASStringContext* psc, const char* str, UPInt size, const char* delim)
        : Str(str), EndStr(str + size), Delimiters(delim), Token(psc->GetBuiltin(ASBuiltin_empty_)) {}

    const char* SetDelimiters(const char* delim)
    {
        Delimiters = delim;
        return delim;
    }
    bool NextToken(char* psep)
    {
        if (Str >= EndStr)
            return false;
        const char* ptoken = Str;
        while (Str < EndStr && !strchr(Delimiters, *Str))
            Str++;
        *psep = *Str;
        if (ptoken != Str && Str <= EndStr)
            Token = ASString(Token.GetManager()->CreateStringNode(ptoken, (UPInt)(Str - ptoken)));
        else
            Token = ASString(Token.GetManager()->GetEmptyStringNode());
        ++Str;
        return true;
    }
    const ASString& GetToken() const { return Token; }
};

// ".." or "_parent": a step up from the current target.
inline bool IsRelativePathToken(ASStringContext* psc, const ASString& token)
{
    return psc->GetBuiltin(ASBuiltin_dotdot_) == token ||
           psc->GetBuiltin(ASBuiltin__parent).CompareBuiltIn_CaseCheck(token, psc->IsCaseSensitive());
}

} // namespace

// Walks the path one name at a time from the target (a leading '/' starts at the root, a leading '.' allows only
// slashes): characters through their relative targets, anything else through its members (primitives via a
// temporary object), properties by their getters. Optionally keeps the last character on the path, the owner of
// the result and the last name. With onlyTargets every step has to be a character.
// MS2-FUNCTIONAL: the tokenizer and PrimitiveToTempObject are inlined; register allocation differs.
// @0x142945010
bool Environment::FindVariable(const GetVarParams& params, bool onlyTargets, ASString* pvarName) const
{
    if (params.VarName.GetSize() == 0)
    {
        if (params.pResult)
            params.pResult->SetAsCharacter(Target);
        return true;
    }

    static const char* const onlySlashesDelim = ":/";
    static const char* const regularDelim     = ":./";

    Environment* penv         = const_cast<Environment*>(this);
    Value        current;
    bool         currentFound = false;
    const char*  p            = params.VarName.ToCStr();
    UPInt        plength      = params.VarName.GetSize();
    const char*  delim        = regularDelim;

    if (params.pOwnerValue)
        params.pOwnerValue->SetUndefined();
    if (params.ppNewTarget)
        *params.ppNewTarget = 0;

    if (*p == '/')
    {
        current.SetAsCharacter(Target->GetTopParent());
        currentFound = true;
        p++;
        plength--;
        delim = onlySlashesDelim;
        if (params.pOwnerValue)
            *params.pOwnerValue = current;
    }
    else if (*p == '.')
        delim = onlySlashesDelim;

    PathTokenizer parser(penv->GetSC(), p, plength, delim);
    char          sep        = 0;
    bool          firstToken = true;
    while (parser.NextToken(&sep))
    {
        const ASString& token = parser.GetToken();
        if (token.GetSize())
        {
            if (pvarName)
                *pvarName = token;
            Value member;
            bool  memberFound = false;
            if (current.IsCharacter() || (!currentFound && IsRelativePathToken(penv->GetSC(), token)))
            {
                if (!currentFound)
                {
                    // A relative path with nothing resolved yet starts at the innermost with object, if that is a
                    // character, or else at the target.
                    if (params.pWithStack && params.pWithStack->GetSize() > 0)
                    {
                        ObjectInterface* obj =
                            (*params.pWithStack)[params.pWithStack->GetSize() - 1].GetObjectInterface();
                        if (obj->IsASCharacter())
                            current.SetAsCharacter(obj->ToCharacter());
                    }
                    if (current.IsUndefined())
                        current.SetAsCharacter(Target);
                    currentFound = true;
                }
                InteractiveObject* m = current.ToCharacter(this);
                if (m)
                {
                    m = ToAvmCharacter(m)->GetRelativeTarget(token, firstToken);
                    if (m)
                    {
                        member.SetAsCharacter(m);
                        memberFound = true;
                    }
                }
            }
            if (!memberFound)
            {
                if (!currentFound)
                    memberFound = GetVariableRaw(GetVarParams(token, &member, params.pWithStack));
                else
                {
                    if (current.IsNumber() || current.IsBoolean() || current.IsString())
                        current = penv->PrimitiveToTempObject(current);
                    if (!current.IsObject() && !current.IsCharacter() && !current.IsFunction())
                    {
                        member.SetUndefined();
                        memberFound = false;
                    }
                    else
                    {
                        ObjectInterface* iobj = current.ToObjectInterface(this);
                        if (iobj)
                        {
                            memberFound = iobj->GetMember(penv, token, &member);
                            if (!memberFound)
                                member.SetUndefined();
                        }
                    }
                }
            }
            if (params.pOwnerValue)
                *params.pOwnerValue = current;
            if ((onlyTargets && !member.IsCharacter()) || !memberFound)
            {
                current.SetUndefined();
                currentFound = false;
                if (parser.NextToken(&sep))
                {
                    // Not the last name: there is no owner or target either.
                    if (params.pOwnerValue)
                        params.pOwnerValue->SetUndefined();
                    if (params.ppNewTarget)
                        *params.ppNewTarget = 0;
                    if (pvarName)
                        *pvarName = GetBuiltin(ASBuiltin_empty_);
                }
                break;
            }

            if (member.IsProperty())
                member.GetPropertyValue(penv, current.ToObjectInterface(this), &current);
            else
                current = member;
            currentFound = memberFound;
        }
        if (delim == onlySlashesDelim)
        {
            if (sep == ':')
            {
                delim = parser.SetDelimiters(regularDelim);
                if (params.ppNewTarget && current.IsCharacter())
                    *params.ppNewTarget = current.ToCharacter(this);
            }
        }
        else if (sep == '.')
        {
            if (params.ppNewTarget && current.IsCharacter())
                *params.ppNewTarget = current.ToCharacter(this);
        }
        if (sep == '/')
            delim = parser.SetDelimiters(onlySlashesDelim);
        firstToken = false;
    }
    if (params.ppNewTarget && current.IsCharacter())
        *params.ppNewTarget = current.ToCharacter(this);
    // The owner can only be an object, a character or a function.
    if (params.pOwnerValue && !params.pOwnerValue->IsObject() && !params.pOwnerValue->IsCharacter() &&
        !params.pOwnerValue->IsFunction())
        params.pOwnerValue->SetUndefined();
    if (!currentFound)
        return false;
    if (params.pResult)
        *params.pResult = current;
    return true;
}

}}} // namespace Scaleform::GFx::AS2
