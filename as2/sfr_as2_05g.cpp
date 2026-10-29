// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 host value interface getters
// (gap recovery of sfr_as2_05; lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14294bbb0-0x14294bd7f .text$mn
// MS2-RANGE: 0x142956270-0x142956375 .text$mn

#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/as2/as2_valueobjectinterface.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_textfield.h"

namespace Scaleform { namespace GFx {

namespace {

SF_FORCEINLINE AS2::MovieRoot* VoiRoot(MovieImpl* pmovieRoot)
{
    return static_cast<AS2::MovieRoot*>(pmovieRoot->pASMovieRoot);
}

// The environment of _level0, where the host's strings and conversions are made.
SF_FORCEINLINE AS2::Environment* VoiEnv(AS2::MovieRoot* proot)
{
    AvmDisplayObjBase* pmain = proot->pMovieImpl->pMainMovie->GetAvmObjImpl();
    return static_cast<AS2::AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmain))->GetASEnvironment();
}

// The script object of a value: the object itself, or the AS object of its character (0 when the character is
// gone).
SF_FORCEINLINE AS2::ObjectInterface* VoiObject(void* pdata, MovieImpl* pmovieRoot, bool isdobj)
{
    AS2::ObjectInterface* pobj = static_cast<AS2::ObjectInterface*>(pdata);
    if (isdobj)
    {
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pmovieRoot);
        if (!pdobj)
            return 0;
        pobj = static_cast<AS2::AvmCharacter*>(static_cast<InteractiveObject*>(pdobj)->GetAvmIntObj());
    }
    return pobj;
}

} // namespace

// The text (or the HTML text) of a text field; other characters give the text / htmlText member.
// MS2-FUNCTIONAL: instruction scheduling
// @0x142956270
bool AS2ValueObjectInterface::GetText(void* pdata, Value* pval, bool ishtml) const
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pch)
        return false;
    if (pch->GetType() != CharacterDef::TextField)
        return GetMember(pdata, ishtml ? "htmlText" : "text", pval, true);
    AS2::MovieRoot*   proot = VoiRoot(pMovieRoot);
    AS2::Environment* penv  = VoiEnv(proot);
    proot->ASValue2GFxValue(penv, AS2::Value(reinterpret_cast<TextField*>(pch)->GetText(ishtml)), pval);
    return true;
}

// Reads a member (resolving properties) and converts it to a host value; clears pval on failure.
// MS2-FUNCTIONAL: instruction scheduling
// @0x14294bbb0
bool AS2ValueObjectInterface::GetMember(void* pdata, const char* name, Value* pval, bool isdobj) const
{
    AS2::MovieRoot*       proot = VoiRoot(pMovieRoot);
    AS2::Environment*     penv  = VoiEnv(proot);
    AS2::ObjectInterface* pobj  = VoiObject(pdata, pMovieRoot, isdobj);
    if (!pobj)
    {
        if (pval)
            pval->SetUndefined();
        return false;
    }
    AS2::Value asval;
    if (!pobj->GetMember(penv, penv->CreateString(name), &asval))
    {
        if (pval)
        {
            pval->SetUndefined();
        }
        return false;
    }
    if (asval.GetType() == AS2::Value::PROPERTY)
    {
        AS2::ObjectInterface* pthis = 0;
        if (pobj->GetObjectType() - 6U < 0x27)
            if (AS2::Object* po = pobj->ToASObject())
                pthis = po;
        if (pobj->GetObjectType() - 2U < 4)
            if (AS2::AvmCharacter* pc = pobj->ToAvmCharacter())
                pthis = pc;
        asval.GetPropertyValue(penv, pthis, &asval);
    }
    proot->ASValue2GFxValue(penv, asval, pval);
    return true;
}

} }
