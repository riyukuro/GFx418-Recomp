// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// a member set on a character: the standard properties, the GFx extension ones (topmostLevel, noAdvance,
// focusGroupMask and the 3D members), then __proto__ and the clip's AS object.
// MS2-UNIT: sfr_as2_07l
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142982d20-0x142983312 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/render/render_matrix4x4.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// The GFx extension members of the MemberTable that only a movie with extensions enabled may set.
const int Member_topmostLevel   = 89;
const int Member_noAdvance      = 90;
const int Member_focusGroupMask = 91;
const int Member_z              = 110;
const int Member_zscale         = 111;
const int Member_xrotation      = 112;
const int Member_yrotation      = 113;
const int Member_matrix3d       = 114;
const int Member_perspfov       = 115;

// A name that may spell a standard member: flagged so, or "_..." whose lowercase twin is flagged.
inline bool MayBeStandardMember(const ASString& name)
{
    if ((name.GetHashFlags() >> 29) & 1)
        return true;
    if (name.GetLength() != 0 && name.GetCharAt(0) == '_')
    {
        ASString lower(name.ToLowerNode());
        if ((lower.GetHashFlags() >> 28) & 1)
            return true;
    }
    return false;
}

} // namespace

// MS2-FUNCTIONAL: the extension cases are laid out differently and the matrix copy is scheduled differently; same
// behavior
// @0x142982d20
bool AvmCharacter::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (MayBeStandardMember(name))
    {
        StandardMember member = GetStandardMemberConstant(name);
        if (SetStandardMember(member, val, false))
            return true;

        switch ((int)member)
        {
        case Member_topmostLevel:
            if (GetASEnvironment()->CheckExtensions())
            {
                if (val.ToBool(GetASEnvironment()))
                    pDispObj->Flags |= DisplayObjectBase::Mask_TopmostLevel;
                else
                    pDispObj->Flags &= ~DisplayObjectBase::Mask_TopmostLevel;
                if (pDispObj->IsTopmostLevelFlagSet())
                    pDispObj->GetMovieImpl()->AddTopmostLevelCharacter(pDispObj);
                else
                    pDispObj->GetMovieImpl()->RemoveTopmostLevelCharacter(pDispObj);
            }
            break;
        case Member_noAdvance:
            if (GetASEnvironment()->CheckExtensions())
            {
                bool noAdvance = val.ToBool(GetASEnvironment());
                if (noAdvance != pDispObj->IsNoAdvanceLocalFlagSet())
                {
                    pDispObj->SetNoAdvanceLocalFlag(noAdvance);
                    pDispObj->ModifyOptimizedPlayList();
                    InteractiveObject* pparent = pDispObj->GetParent();
                    if (pparent && !pparent->IsNoAdvanceLocalFlagSet())
                        pDispObj->PropagateNoAdvanceLocalFlag();
                }
            }
            break;
        case Member_focusGroupMask:
            if (GetASEnvironment()->CheckExtensions() && !val.IsUndefined())
                pDispObj->PropagateFocusGroupMask(val.ToUInt32(GetASEnvironment()));
            break;
        case Member_z:
            if (GetASEnvironment()->CheckExtensions())
                pDispObj->SetZ(val.ToNumber(GetASEnvironment()));
            break;
        case Member_zscale:
            if (GetASEnvironment()->CheckExtensions())
                pDispObj->SetZScale(val.ToNumber(GetASEnvironment()));
            break;
        case Member_xrotation:
            if (GetASEnvironment()->CheckExtensions())
                pDispObj->SetXRotation(val.ToNumber(GetASEnvironment()));
            break;
        case Member_yrotation:
            if (GetASEnvironment()->CheckExtensions())
                pDispObj->SetYRotation(val.ToNumber(GetASEnvironment()));
            break;
        case Member_matrix3d:
            if (GetASEnvironment()->CheckExtensions())
            {
                // An array of up to 16 numbers, column by column; anything but an object clears the 3D state.
                Object* pobj = val.ToObject(penv);
                if (!pobj)
                    pDispObj->Clear3D();
                else if (pobj->GetObjectType() == Object::Object_Array)
                {
                    ArrayObject*     parr = static_cast<ArrayObject*>(val.ToObjectInterface_Call(penv));
                    Render::Matrix4F m;
                    float*           pm = &m.M[0][0];
                    for (int i = 0; i < parr->GetSize(); ++i)
                    {
                        const Value* pv = parr->GetElementPtr(i);
                        if (pv && pv->IsNumber())
                            pm[i] = (float)pv->ToNumber(penv);
                    }
                    m.Transpose();
                    pDispObj->SetMatrix3D(Render::Matrix3F(m));
                }
            }
            break;
        case Member_perspfov:
            if (GetASEnvironment()->CheckExtensions())
                pDispObj->SetFOV(val.ToNumber(GetASEnvironment()));
            break;
        default:
            break;
        }
    }

    if (penv->GetBuiltin(ASBuiltin___proto__).CompareBuiltIn_CaseCheck(name, penv->IsCaseSensitive()) &&
        val.T.Type != Value::UNSET)
        Set__proto__(&penv->StringContext, val.ToObject(0));

    Object* pobj = GetASObject();
    if (pobj)
        return pobj->SetMember(penv, name, val, flags);
    return false;
}

}}} // namespace Scaleform::GFx::AS2
