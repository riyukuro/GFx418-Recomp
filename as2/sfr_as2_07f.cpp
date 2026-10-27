// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// the setters and visitors of the host value interface AS2ValueObjectInterface, and ObjectInterface::SetUserData.
// MS2-UNIT: sfr_as2_07f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297fb80-0x14297fba0 .text$mn
// MS2-RANGE: 0x1429803d0-0x142980445 .text$mn
// MS2-RANGE: 0x142980790-0x14298131d .text$mn
// MS2-RANGE: 0x1429813e0-0x1429814b5 .text$mn
// MS2-RANGE: 0x142981f00-0x14298236a .text$mn
// MS2-RANGE: 0x1429829c0-0x142982aee .text$mn
// MS2-RANGE: 0x14298be80-0x14298c087 .text$mn
// MS2-RANGE: 0x14298ca20-0x14298cc2d .text$mn
// MS2-RANGE: 0x142991d30-0x142991e0d .text$mn
// MS2-RANGE: 0x142994210-0x1429944ce .text$mn

// The exe calls Value::~Value out of line throughout this file.
// (inline AS2::Value dtor)
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_valueobjectinterface.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_valueinfo.h"
#include "../include/gfx/gfx_rendertree.h"

namespace Scaleform { namespace GFx {

// sfr_gfx_06
void ASCharacter_MatrixScaleAndRotate2x2(Render::Matrix2F& m, float sx, float sy, float radians);

namespace AS2 {

namespace {

// The body of ObjectInterface::SetUserData, which the exe also inlines into AS2ValueObjectInterface::SetUserData.
SF_FORCEINLINE void ObjectInterface_SetUserData(ObjectInterface* pthis, Movie* pmovieView, ASUserData* puserData,
                                                bool isdobj)
{
    if (pthis->pUserDataHolder)
        delete pthis->pUserDataHolder;
    pthis->pUserDataHolder = SF_HEAP_AUTO_NEW(pthis) ObjectInterface::UserDataHolder(pmovieView, puserData);
    if (puserData)
    {
        if (isdobj)
            ASUserData_SetLastObjectValue(puserData, reinterpret_cast<MovieImpl*>(pmovieView)->pObjectInterface,
                                          pthis->ToCharacter()->GetCharacterHandle(), isdobj);
        else
            ASUserData_SetLastObjectValue(puserData, reinterpret_cast<MovieImpl*>(pmovieView)->pObjectInterface,
                                          pthis, isdobj);
    }
}

} // namespace

// Drops the old user data holder and keeps puserData for the movie; the user data learns which object (or, for a
// character, which character handle) it belongs to.
// @0x14298cb60
void ObjectInterface::SetUserData(Movie* pmovieView, ASUserData* puserData, bool isdobj)
{
    ObjectInterface_SetUserData(this, pmovieView, puserData, isdobj);
}

} // namespace AS2

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
        // the character's own interface (not its AS object)
        pobj = static_cast<AS2::AvmCharacter*>(static_cast<InteractiveObject*>(pdobj)->GetAvmIntObj());
    }
    return pobj;
}

// Matrix3F::IsValid as the exe has it here: every element tested in turn (unrolled).
SF_FORCEINLINE bool VoiFinite(float v)
{
    return v >= -FLT_MAX && v <= FLT_MAX;
}

SF_FORCEINLINE bool VoiValid3D(const Render::Matrix3F& m)
{
    return VoiFinite(m.M[0][0]) && VoiFinite(m.M[0][1]) && VoiFinite(m.M[0][2]) && VoiFinite(m.M[0][3]) &&
           VoiFinite(m.M[1][0]) && VoiFinite(m.M[1][1]) && VoiFinite(m.M[1][2]) && VoiFinite(m.M[1][3]) &&
           VoiFinite(m.M[2][0]) && VoiFinite(m.M[2][1]) && VoiFinite(m.M[2][2]) && VoiFinite(m.M[2][3]);
}

SF_FORCEINLINE AS2::ArrayObject* VoiArray(void* pdata)
{
    return static_cast<AS2::ArrayObject*>(static_cast<AS2::ObjectInterface*>(pdata));
}

// A host string value that points at the caller's text (unmanaged).
class VoiStringValue : public Value
{
public:
    VoiStringValue(const char* ptext)
    {
        Type           = VT_String;
        mValue.pString = ptext;
    }
    VoiStringValue(const wchar_t* ptext)
    {
        Type            = VT_StringW;
        mValue.pStringW = ptext;
    }
};

// fmod into (-180, 180].
SF_FORCEINLINE Double VoiNormalizeAngle(Double a)
{
    a = fmod(a, 360.);
    if (a > 180.)
        a += -360.;
    else if (a < -180.)
        a += 360.;
    return a;
}

} // namespace

// Hands the members VisitMembers enumerates to the host's visitor as host values. 0x20 bytes; vftable 0x143222268.
class AS2ValueObjectInterface_MemberVisitor : public AS2::ObjectInterface::MemberVisitor
{
public:
    AS2::MovieRoot*                  pMovieRoot; // +0x08
    AS2::Environment*                pEnv;       // +0x10
    Value::ObjectInterface::ObjVisitor* pVisitor; // +0x18

    AS2ValueObjectInterface_MemberVisitor(AS2::MovieRoot* proot, AS2::Environment* penv,
                                          Value::ObjectInterface::ObjVisitor* pvisitor)
        : pMovieRoot(proot), pEnv(penv), pVisitor(pvisitor)
    {
    }

    // @0x142994210
    virtual void Visit(const ASString& name, const AS2::Value& val, UByte flags)
    {
        SF_UNUSED(flags);
        Value v;
        pMovieRoot->ASValue2GFxValue(pEnv, val, &v);
        pVisitor->Visit(name.ToCStr(), v);
    }
};

// Converts the host value and stores it under name on the object (or the character's AS object).
// MS2-FUNCTIONAL: branch vs cmove null-cast of the character interface, CreateString operand scheduling
// @0x1429829c0
bool AS2ValueObjectInterface::SetMember(void* pdata, const char* name, const Value& value, bool isdobj)
{
    MovieImpl*            pmovie = pMovieRoot;
    AS2::MovieRoot*       proot = VoiRoot(pmovie);
    AS2::Environment*     penv  = VoiEnv(proot);
    AS2::ObjectInterface* pobj  = VoiObject(pdata, pmovie, isdobj);
    if (!pobj)
        return false;
    AS2::Value asval;
    proot->Value2ASValue(value, &asval);
    return pobj->SetMember(penv, penv->CreateString(name), asval);
}

// Hands each member of the object to the visitor.
// MS2-FUNCTIONAL: the visitor is the named class above (the exe's is a local struct of the same layout)
// @0x1429943f0
void AS2ValueObjectInterface::VisitMembers(void* pdata, ObjVisitor* visitor, bool isdobj) const
{
    AS2::MovieRoot*       proot = VoiRoot(pMovieRoot);
    AS2::Environment*     penv  = VoiEnv(proot);
    AS2::ObjectInterface* pobj  = static_cast<AS2::ObjectInterface*>(pdata);
    if (isdobj)
    {
        pobj                 = 0;
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
        if (pdobj)
            pobj = static_cast<AS2::AvmCharacter*>(static_cast<InteractiveObject*>(pdobj)->GetAvmIntObj());
    }
    AS2ValueObjectInterface_MemberVisitor shim(proot, penv, visitor);
    pobj->VisitMembers(&penv->StringContext, &shim,
                       AS2::ObjectInterface::VisitMember_Prototype | AS2::ObjectInterface::VisitMember_ChildClips, 0);
}

// @0x14297fb80
bool AS2ValueObjectInterface::SetArraySize(void* pdata, unsigned sz)
{
    VoiArray(pdata)->Resize(sz);
    return true;
}

// @0x1429813e0
bool AS2ValueObjectInterface::SetElement(void* pdata, unsigned idx, const Value& value)
{
    AS2::ArrayObject* parr = VoiArray(pdata);
    AS2::Value        asval;
    VoiRoot(pMovieRoot)->Value2ASValue(value, &asval);
    // ArrayObject::SetElementSafe (0x142981560), inlined
    int i = (int)idx;
    parr->LengthValueOverriden = false;
    if (i >= parr->GetSize())
        parr->Resize(i + 1);
    if (!parr->Elements[i])
        parr->Elements[i] = SF_HEAP_AUTO_NEW(parr) AS2::Value();
    *parr->Elements[i] = asval;
    return true;
}

// Hands count elements from idx (to the end for a negative count) to the visitor; holes are undefined.
// MS2-FUNCTIONAL: register allocation (rsi vs rdi for the visitor)
// @0x142994280
void AS2ValueObjectInterface::VisitElements(void* pdata, ArrVisitor* visitor, unsigned idx, int count) const
{
    AS2::MovieRoot*   proot = VoiRoot(pMovieRoot);
    AS2::Environment* penv  = VoiEnv(proot);
    AS2::ArrayObject* parr  = VoiArray(pdata);
    Value             v;
    unsigned          size = parr->GetSize();
    if (idx < size)
    {
        if (count < 0)
            count = size - idx;
        unsigned end = Alg::Min(size, idx + count);
        for (; idx < end; ++idx)
        {
            const AS2::Value* pelem = parr->GetElementPtr(idx);
            if (pelem)
                proot->ASValue2GFxValue(penv, *pelem, &v);
            else
                v.SetUndefined();
            visitor->Visit(idx, v);
        }
    }
}

// Applies the display properties set in info; the 2D ones go through the geometry the AS properties keep.
// MS2-FUNCTIONAL: exe calls DisplayObjectBase::Is3D out of line (0x142513e50); xmm register allocation and frame size differ
// @0x142980790
bool AS2ValueObjectInterface::SetDisplayInfo(void* pdata, const Value::DisplayInfo& info)
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pch)
        return false;

    bool is3D = false;
    bool isTF = pch->GetType() == CharacterDef::TextField;
    if (info.IsFlagSet(Value::DisplayInfo::V_edgeaaMode))
        pch->GetRenderNode()->SetEdgeAAMode(info.EdgeAAMode);
    if (info.IsFlagSet(Value::DisplayInfo::V_alpha) && !NumberUtil::IsNaN(info.Alpha))
    {
        Render::Cxform cx = pch->GetCxform();
        cx.M[0][3]        = float(info.Alpha / 100.);
        pch->SetCxform(cx);
        pch->SetAcceptAnimMoves(false);
    }
    if (info.IsFlagSet(Value::DisplayInfo::V_visible))
        pch->SetVisible(info.Visible);
    if (info.IsFlagSet(Value::DisplayInfo::V_z))
    {
        Double z = info.Z;
        if (NumberUtil::IsNaN(z))
            z = 0;
        if (NumberUtil::IsNEGATIVE_INFINITY(z) || NumberUtil::IsPOSITIVE_INFINITY(z))
            z = 0;
        if (z != pch->pGeomData->Z)
        {
            pch->pGeomData->Z = z;
            is3D              = true;
        }
    }
    if (info.IsFlagSet(Value::DisplayInfo::V_zscale))
    {
        Double zscale = info.ZScale;
        if (NumberUtil::IsNaN(zscale) || NumberUtil::IsNEGATIVE_INFINITY(zscale) ||
            NumberUtil::IsPOSITIVE_INFINITY(zscale))
            zscale = 100.;
        if (pch->pGeomData->ZScale != zscale)
        {
            pch->pGeomData->ZScale = zscale;
            is3D                   = true;
        }
    }
    if (info.IsFlagSet(Value::DisplayInfo::V_xrotation) && info.XRotation != pch->pGeomData->XRotation)
    {
        pch->pGeomData->XRotation = VoiNormalizeAngle(info.XRotation);
        is3D                      = true;
    }
    if (info.IsFlagSet(Value::DisplayInfo::V_yrotation) && info.YRotation != pch->pGeomData->YRotation)
    {
        pch->pGeomData->YRotation = VoiNormalizeAngle(info.YRotation);
        is3D                      = true;
    }
    if (is3D)
        pch->UpdateTransform3D();
    if (info.IsFlagSet(Value::DisplayInfo::V_FOV))
    {
        Double fov = info.FOV;
        if (fov != pch->GetFOV())
            pch->SetFOV(fmod(fov, 180.));
    }
    if (info.IsFlagSet(Value::DisplayInfo::V_projMatrix3D))
        pch->SetProjectionMatrix3D(info.ProjectionMatrix3D);
    if (info.IsFlagSet(Value::DisplayInfo::V_viewMatrix3D))
        pch->SetViewMatrix3D(info.ViewMatrix3D);

    if (info.IsFlagSet(Value::DisplayInfo::V_x | Value::DisplayInfo::V_y | Value::DisplayInfo::V_rotation |
                       Value::DisplayInfo::V_xscale | Value::DisplayInfo::V_yscale))
    {
        if (isTF)
        {
            TextField* ptf = reinterpret_cast<TextField*>(pch);
            ptf->FlagsRef() |= 0x2000;
            ptf->SetDirtyFlag();
        }
        pch->SetAcceptAnimMoves(false);
        DisplayObjectBase::GeomDataType& geom = *pch->pGeomData;
        Render::Matrix2F                 m    = pch->GetMatrix();

        Double newX = 0, newY = 0;
        if (!isTF || !info.IsFlagSet(Value::DisplayInfo::V_x | Value::DisplayInfo::V_y))
        {
            if (info.IsFlagSet(Value::DisplayInfo::V_x))
                newX = info.X;
            if (info.IsFlagSet(Value::DisplayInfo::V_y))
                newY = info.Y;
        }
        else
        {
            Render::PointF pt = reinterpret_cast<TextField*>(pch)->TransformToTextRectSpace(info);
            newX              = pt.x;
            newY              = pt.y;
        }

        if (info.IsFlagSet(Value::DisplayInfo::V_rotation | Value::DisplayInfo::V_xscale |
                           Value::DisplayInfo::V_yscale))
        {
            Render::Matrix2F om          = geom.OrigMatrix;
            om.Tx()                      = m.Tx();
            om.Ty()                      = m.Ty();
            Double           origRotation = geom.OrigMatrix.GetRotationDouble();
            Double           origXScale   = geom.OrigMatrix.GetXScaleDouble();
            Double           origYScale   = geom.OrigMatrix.GetYScaleDouble();
            Double           newRotation  = geom.Rotation * SF_MATH_PI;
            Double           newXScale    = geom.XScale / 100.;
            Double           newYScale    = geom.YScale / 100.;

            Double r = info.IsFlagSet(Value::DisplayInfo::V_rotation) ? info.Rotation : NumberUtil::NaN();
            if (!NumberUtil::IsNaN(r))
            {
                geom.Rotation = VoiNormalizeAngle(r);
                newRotation   = geom.Rotation * SF_MATH_PI;
            }
            Double xs = info.IsFlagSet(Value::DisplayInfo::V_xscale) ? info.XScale / 100. : NumberUtil::NaN();
            if (xs != newXScale && !NumberUtil::IsNaNOrInfinity(xs))
            {
                geom.XScale = info.XScale;
                if (origXScale == 0 || xs > 1e16)
                {
                    newXScale  = 0;
                    origXScale = 1;
                }
                else
                    newXScale = xs;
            }
            Double ys = info.IsFlagSet(Value::DisplayInfo::V_yscale) ? info.YScale / 100. : NumberUtil::NaN();
            if (ys != newYScale && !NumberUtil::IsNaNOrInfinity(ys))
            {
                geom.YScale = info.YScale;
                if (origYScale == 0 || ys > 1e16)
                {
                    newYScale  = 0;
                    origYScale = 1;
                }
                else
                    newYScale = ys;
            }
            ASCharacter_MatrixScaleAndRotate2x2(om, float(newXScale / origXScale), float(newYScale / origYScale),
                                                float(newRotation / 180. - origRotation));
            m = om;
        }

        Double x = info.IsFlagSet(Value::DisplayInfo::V_x) ? newX : NumberUtil::NaN();
        if (!NumberUtil::IsNaN(x))
        {
            if (NumberUtil::IsNEGATIVE_INFINITY(x) || NumberUtil::IsPOSITIVE_INFINITY(x))
                x = 0;
            geom.X  = int(floor(x * 20.));
            m.Tx() = float(geom.X);
        }
        Double y = info.IsFlagSet(Value::DisplayInfo::V_y) ? newY : NumberUtil::NaN();
        if (!NumberUtil::IsNaN(y))
        {
            if (NumberUtil::IsNEGATIVE_INFINITY(y) || NumberUtil::IsPOSITIVE_INFINITY(y))
                y = 0;
            geom.Y  = int(floor(y * 20.));
            m.Ty() = float(geom.Y);
        }
        if (m.IsValid())
        {
            if (pch->Is3D())
                pch->UpdateTransform3D();
            else
                pch->SetMatrix(m);
        }
        if (isTF)
        {
            // The text field keeps the requested position, rounded to twips.
            if (info.IsFlagSet(Value::DisplayInfo::V_x))
            {
                Double tx = newX * 20.;
                geom.X    = int(tx > 0 ? tx + 0.5 : tx - 0.5);
            }
            if (info.IsFlagSet(Value::DisplayInfo::V_y))
            {
                Double ty = newY * 20.;
                geom.Y    = int(ty > 0 ? ty + 0.5 : ty - 0.5);
            }
        }
    }
    return true;
}

// Sets the 2D matrix (translation in pixels) and the AS geometry from it.
// MS2-FUNCTIONAL: instruction scheduling of the vtable load and matrix stores
// @0x142981130
bool AS2ValueObjectInterface::SetDisplayMatrix(void* pdata, const Render::Matrix2F& mat)
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (pch && mat.IsValid())
    {
        Render::Matrix2F m = mat;
        m.Tx()             = m.Tx() * 20.f;
        m.Ty()             = m.Ty() * 20.f;
        pch->SetMatrix(m);

        DisplayObjectBase::GeomDataType gd;
        pch->GetGeomData(gd);
        gd.X        = int(mat.Tx());
        gd.Y        = int(mat.Ty());
        gd.XScale   = mat.GetXScaleDouble() * 100.;
        gd.YScale   = mat.GetYScaleDouble() * 100.;
        gd.Rotation = mat.GetRotationDouble() * 180. / SF_MATH_PI;
        pch->SetGeomData(gd);
        return true;
    }
    return false;
}

// Sets the 3D matrix (translation in pixels) and the 3D AS geometry from it.
// MS2-FUNCTIONAL: instruction scheduling of the vtable load and matrix stores
// @0x142981f00
bool AS2ValueObjectInterface::SetMatrix3D(void* pdata, const Render::Matrix3F& mat)
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (pch && VoiValid3D(mat))
    {
        Render::Matrix3F m = mat;
        m.Tx()             = m.Tx() * 20.f;
        m.Ty()             = m.Ty() * 20.f;
        pch->SetMatrix3D(m);

        DisplayObjectBase::GeomDataType gd;
        pch->GetGeomData(gd);
        gd.Z      = mat.Tz();
        gd.ZScale = mat.GetZScale() * 100.;
        float xr, yr;
        mat.GetRotation(&xr, &yr, 0);
        gd.XRotation = xr * 180. / SF_MATH_PI;
        gd.YRotation = yr * 180. / SF_MATH_PI;
        pch->SetGeomData(gd);
        return true;
    }
    return false;
}

// @0x1429803d0
bool AS2ValueObjectInterface::SetCxform(void* pdata, const Render::Cxform& cx)
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (pch && (pch->GetType() == CharacterDef::TextField || pch->IsSprite()))
    {
        pch->SetCxform(cx);
        pch->SetAcceptAnimMoves(false);
        return true;
    }
    return false;
}

// Sets the text (or HTML text) of a text field; other characters get the text / htmlText member.
// @0x14298be80
bool AS2ValueObjectInterface::SetText(void* pdata, const char* ptext, bool ishtml)
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pch)
        return false;
    if (pch->GetType() != CharacterDef::TextField)
    {
        VoiStringValue val(ptext);
        return SetMember(pdata, ishtml ? "htmlText" : "text", val, true);
    }
    TextField* ptf   = reinterpret_cast<TextField*>(pch);
    UInt32&    flags   = ptf->FlagsRef();
    bool       washtml = ((flags >> 1) & 1) != 0;
    if (ishtml)
    {
        if (!washtml)
            flags |= 0x2;
    }
    else if (washtml)
        flags &= ~0x2u;
    ptf->SetTextValue(ptext, ishtml, true);
    return true;
}

// @0x14298bfa0
bool AS2ValueObjectInterface::SetText(void* pdata, const wchar_t* ptext, bool ishtml)
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pch)
        return false;
    if (pch->GetType() != CharacterDef::TextField)
    {
        VoiStringValue val(ptext);
        return SetMember(pdata, ishtml ? "htmlText" : "text", val, true);
    }
    reinterpret_cast<TextField*>(pch)->SetText(ptext, ishtml);
    return true;
}

// @0x142991d30
void AS2ValueObjectInterface::ToString(String* pstr, const Value& thisVal) const
{
    AS2::MovieRoot*   proot = VoiRoot(pMovieRoot);
    AS2::Environment* penv  = VoiEnv(proot);
    AS2::Value        asval;
    proot->Value2ASValue(thisVal, &asval);
    *pstr = String(asval.ToString(penv).ToCStr());
}

// MS2-FUNCTIONAL: register allocation / null-cast form of the resolved character interface
// @0x14298ca20
void AS2ValueObjectInterface::SetUserData(void* pdata, ASUserData* puserdata, bool isdobj)
{
    VoiEnv(VoiRoot(pMovieRoot));
    AS2::ObjectInterface* pobj = VoiObject(pdata, pMovieRoot, isdobj);
    if (pobj)
        AS2::ObjectInterface_SetUserData(pobj, pMovieRoot->AsMovie(), puserdata, isdobj);
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7AS2ValueObjectInterface_MemberVisitor@GFx@Scaleform@@6B@ 0x143222268
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
