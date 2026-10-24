// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 host value interface getters
// (gap recovery of sfr_as2_05; lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14294b250-0x14294b2df .text$mn
// MS2-RANGE: 0x142956be0-0x142956c7c .text$mn
// MS2-RANGE: 0x142958290-0x14295836f .text$mn

#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
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

// The 3D matrix of the character pdata with the translation in pixels.
// MS2-FUNCTIONAL: instruction scheduling of the element copies
// @0x14294b250
bool AS2ValueObjectInterface::GetMatrix3D(void* pdata, Render::Matrix3F* pmat) const
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pch)
        return false;
    Render::Matrix3F m = pch->GetMatrix3D();
    m.Tx()             = Render::TwipsToPixels(m.Tx());
    m.Ty()             = Render::TwipsToPixels(m.Ty());
    *pmat              = m;
    return true;
}

// The host user data of the object (or of the AS object of the character).
// MS2-FUNCTIONAL: register allocation / null-cast form of the resolved character interface
// @0x142956be0
ASUserData* AS2ValueObjectInterface::GetUserData(void* pdata, bool isdobj) const
{
    VoiEnv(VoiRoot(pMovieRoot));
    AS2::ObjectInterface* pobj = VoiObject(pdata, pMovieRoot, isdobj);
    if (pobj && pobj->pUserDataHolder)
        return pobj->pUserDataHolder->pUserData;
    return 0;
}

// The matrix of the character in the world with the translation in pixels.
// MS2-FUNCTIONAL: instruction scheduling of the element copies
// @0x142958290
bool AS2ValueObjectInterface::GetWorldMatrix(void* pdata, Render::Matrix2F* pmat) const
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pch)
        return false;
    Render::Matrix2F m;
    pch->GetWorldMatrix(&m);
    m.Tx() = Render::TwipsToPixels(m.Tx());
    m.Ty() = Render::TwipsToPixels(m.Ty());
    *pmat  = m;
    return true;
}

}} // namespace Scaleform::GFx
