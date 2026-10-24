// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// the member lookup of a movie clip, shared by GetMember and GetMemberRaw.
// MS2-UNIT: sfr_as2_05q
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14294bff0-0x14294c67a .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/render/render_matrix4x4.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// The 3D members past the enum of as2_avmcharacter.h, and _version.
const AvmCharacter::StandardMember M_xrotation = static_cast<AvmCharacter::StandardMember>(110);
const AvmCharacter::StandardMember M_yrotation = static_cast<AvmCharacter::StandardMember>(111);
const AvmCharacter::StandardMember M_z         = static_cast<AvmCharacter::StandardMember>(112);
const AvmCharacter::StandardMember M_zscale    = static_cast<AvmCharacter::StandardMember>(113);
const AvmCharacter::StandardMember M_matrix3d  = static_cast<AvmCharacter::StandardMember>(114);
const AvmCharacter::StandardMember M_fov       = static_cast<AvmCharacter::StandardMember>(115);
const AvmCharacter::StandardMember M__version  = static_cast<AvmCharacter::StandardMember>(116);

// Puts newProto in place of the prototype of pobj and hands back the old one.
inline Ptr<Object> ExchangeProto(Object* pobj, Object* newProto)
{
    Ptr<Object> old = pobj->pProto;
    pobj->pProto    = newProto;
    return old;
}

} // namespace

// The clip's own members come before its children, the children before the prototype: the clip object is looked
// up with its prototype taken away for the while.
// MS2-FUNCTIONAL: the standard member test is inlined in the exe (string node flags, lowercase node); the 3D getters
// return float there
// @0x14294bff0
bool AvmSprite::GetMember(Environment* penv, ASStringContext* psc, const ASString& name, Value* pval)
{
    if (IsStandardMember(name))
    {
        StandardMember member = GetStandardMemberConstant(name);
        if (GetStandardMember(member, pval, 0))
            return true;

        switch (member)
        {
        case M_transform:
            {
                Ptr<TransformObject> ptransform =
                    *SF_HEAP_NEW(GetASEnvironment()->GetHeap()) TransformObject(GetASEnvironment(), pDispObj);
                pval->SetAsObject(ptransform);
                return true;
            }
        case M__version:
            if (IsLevelMovie())
            {
                pval->SetString(GetASEnvironment()->CreateConstString("WIN 8,0,0,0"));
                return true;
            }
            break;
        case M_xrotation:
            pval->SetNumber(pDispObj->GetXRotation());
            return true;
        case M_yrotation:
            pval->SetNumber(pDispObj->GetYRotation());
            return true;
        case M_z:
            pval->SetNumber(pDispObj->GetZ());
            return true;
        case M_zscale:
            pval->SetNumber(pDispObj->GetZScale());
            return true;
        case M_matrix3d:
            {
                Render::Matrix3F m3d = pDispObj->GetMatrix3D();
                Render::Matrix4F mat4(m3d);
                mat4.Transpose();
                Ptr<ArrayObject> parray = *SF_HEAP_NEW(penv->GetHeap()) ArrayObject(GetASEnvironment());
                parray->Resize(16);
                for (int i = 0; i < 16; i++)
                    parray->SetElement(i, Value(Number(mat4.Data()[i])));
                pval->SetAsObject(parray);
                return true;
            }
        case M_fov:
            pval->SetNumber(pDispObj->GetFOV());
            return true;
        default:
            break;
        }
    }

    if ((penv && name == penv->GetBuiltin(ASBuiltin___proto__)) ||
        (psc && name == psc->GetBuiltin(ASBuiltin___proto__)))
    {
        pval->SetAsObject(Get__proto__());
        return true;
    }

    if (pMovieClipObj)
    {
        Ptr<Object> savedProto = ExchangeProto(pMovieClipObj, 0);
        bool rv = false;
        if (penv && pMovieClipObj->GetMember(penv, name, pval))
            rv = true;
        else if (psc && pMovieClipObj->GetMemberRaw(psc, name, pval))
            rv = true;
        ExchangeProto(pMovieClipObj, savedProto);
        if (rv)
            return true;
    }

    DisplayObject* pch = GetSprite()->mDisplayList.GetDisplayObjectByName(name, Env.IsCaseSensitive());
    if (pch && pch->IsInteractiveObject())
    {
        pval->SetAsCharacter(static_cast<InteractiveObject*>(pch));
        return true;
    }
    if (Object* pproto = Get__proto__())
    {
        if (penv && pproto->GetMember(penv, name, pval))
            return true;
        if (psc && pproto->GetMemberRaw(psc, name, pval))
            return true;
    }

    if (name.GetLength() > 0 && name.ToCStr()[0] == '_')
    {
        Environment::GetVarParams params(name, pval);
        Bool3W rv = Env.CheckGlobalAndLevels(params);
        if (rv.IsDefined())
            return rv.IsTrue();
    }
    return false;
}

}}} // namespace Scaleform::GFx::AS2
