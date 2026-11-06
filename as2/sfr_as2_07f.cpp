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

// ToAvmCharacter as the exe inlines it here, with its own null test.
SF_FORCEINLINE AS2::AvmCharacter* VoiAvmChar(DisplayObject* pdobj)
{
    return !pdobj ? 0 : AS2::ToAvmCharacter(static_cast<InteractiveObject*>(pdobj));
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
        pobj = VoiAvmChar(pdobj);
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
// @0x1429943f0
void AS2ValueObjectInterface::VisitMembers(void* pdata, ObjVisitor* visitor, bool isdobj) const
{
    MovieImpl*            pmovie = pMovieRoot;
    AS2::MovieRoot*       proot = VoiRoot(pmovie);
    AS2::Environment*     penv  = VoiEnv(proot);
    AS2::ObjectInterface* pobj  = static_cast<AS2::ObjectInterface*>(pdata);
    if (isdobj)
    {
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pmovie);
        if (!pdobj)
            pobj = 0;
        else
            pobj = VoiAvmChar(pdobj);
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
// @0x142994280
void AS2ValueObjectInterface::VisitElements(void* pdata, ArrVisitor* visitor, unsigned idx, int count) const
{
    AS2::MovieRoot*   proot = VoiRoot(pMovieRoot);
    AS2::Environment* penv  = VoiEnv(proot);
    AS2::ArrayObject* parr  = VoiArray(pdata);
    Value             v;
    unsigned          size = parr->GetSize();
    if (idx >= size)
        return;
    if (count < 0)
        count = size - idx;
    unsigned end = Alg::Min(size, idx + count);
    for (unsigned i = idx; i < end; ++i)
    {
        const AS2::Value* pelem = parr->GetElementPtr(i);
        if (pelem)
            proot->ASValue2GFxValue(penv, *pelem, &v);
        else
            v.SetUndefined();
        visitor->Visit(i, v);
    }
}

// Applies the display properties set in info; the 2D ones go through the geometry the AS properties keep.
// @0x142980790
bool AS2ValueObjectInterface::SetDisplayInfo(void* pdata, const Value::DisplayInfo& cinfo)
{
    typedef Value::DisplayInfo DisplayInfo;
    CharacterHandle* pch = static_cast<CharacterHandle*>(pdata);
    DisplayObject*   pd  = pch->ResolveCharacter(pMovieRoot);
    if (!pd) return false;

    bool Update3DTransforms = false;

    bool       istf = (pd->GetType() == CharacterDef::TextField);
    TextField* ptf  = reinterpret_cast<TextField*>(pd);

    if (cinfo.IsFlagSet(DisplayInfo::V_edgeaaMode))
    {
        pd->GetRenderNode()->SetEdgeAAMode(cinfo.GetEdgeAAMode());
    }

    if (cinfo.IsFlagSet(DisplayInfo::V_alpha))
    {
        if (!NumberUtil::IsNaN(cinfo.GetAlpha()))
        {
            Render::Cxform cx = pd->GetCxform();
            cx.M[0][3] = float(cinfo.GetAlpha() / 100.);
            pd->SetCxform(cx);
            pd->SetAcceptAnimMoves(0);
        }
    }
    if (cinfo.IsFlagSet(DisplayInfo::V_visible))
    {
        pd->SetVisible(cinfo.GetVisible());
    }

    if (cinfo.IsFlagSet(DisplayInfo::V_z))
    {
        Double zval = cinfo.GetZ();
        if (NumberUtil::IsNaN(zval))
            zval = 0;
        if (NumberUtil::IsNEGATIVE_INFINITY(zval) || NumberUtil::IsPOSITIVE_INFINITY(zval))
            zval = 0;
        DisplayObjectBase::GeomDataType* tfgeomData = pd->pGeomData;
        if (zval != tfgeomData->Z)
        {
            tfgeomData->Z = zval;
            Update3DTransforms = true;
        }
    }

    if (cinfo.IsFlagSet(DisplayInfo::V_zscale))
    {
        Double newZScale = cinfo.GetZScale();
        if (NumberUtil::IsNaN(newZScale) ||
            NumberUtil::IsNEGATIVE_INFINITY(newZScale) || NumberUtil::IsPOSITIVE_INFINITY(newZScale))
        {
            newZScale = 100.;
        }
        DisplayObjectBase::GeomDataType* tfgeomData = pd->pGeomData;
        if (tfgeomData->ZScale != newZScale)
        {
            tfgeomData->ZScale = newZScale;
            Update3DTransforms = true;
        }
    }

    if (cinfo.IsFlagSet(DisplayInfo::V_xrotation))
    {
        Double rval = cinfo.GetXRotation();
        DisplayObjectBase::GeomDataType* tfgeomData = pd->pGeomData;
        if (rval != tfgeomData->XRotation)
        {
            Double r = fmod((Double)rval, (Double)360.);
            if (r > 180)
                r -= 360;
            else if (r < -180)
                r += 360;
            tfgeomData->XRotation = r;
            Update3DTransforms = true;
        }
    }

    if (cinfo.IsFlagSet(DisplayInfo::V_yrotation))
    {
        Double rval = cinfo.GetYRotation();
        DisplayObjectBase::GeomDataType* tfgeomData = pd->pGeomData;
        if (rval != tfgeomData->YRotation)
        {
            Double r = fmod((Double)rval, (Double)360.);
            if (r > 180)
                r -= 360;
            else if (r < -180)
                r += 360;
            tfgeomData->YRotation = r;
            Update3DTransforms = true;
        }
    }

    if (Update3DTransforms)
        pd->UpdateTransform3D();

    if (cinfo.IsFlagSet(DisplayInfo::V_FOV))
    {
        Double rval = cinfo.GetFOV();
        if (rval != pd->GetFOV())
        {
            Double r = fmod((Double)rval, (Double)180.);
            pd->SetFOV(r);
        }
    }
    {
        if (cinfo.IsFlagSet(DisplayInfo::V_projMatrix3D))
        {
            pd->SetProjectionMatrix3D(*cinfo.GetProjectionMatrix3D());
        }
        if (cinfo.IsFlagSet(DisplayInfo::V_viewMatrix3D))
        {
            pd->SetViewMatrix3D(*cinfo.GetViewMatrix3D());
        }
    }

    if (cinfo.IsFlagSet(DisplayInfo::V_x|DisplayInfo::V_y|DisplayInfo::V_rotation|
                       DisplayInfo::V_xscale|DisplayInfo::V_yscale))
    {
        if (istf)
        {
            ptf->FlagsRef() |= 0x2000;
            ptf->SetDirtyFlag();
        }

        pd->SetAcceptAnimMoves(0);
        DisplayObjectBase::GeomDataType* tfgeomData = pd->pGeomData;

        Render::Matrix2F m = pd->GetMatrix();

        // Not zeroed: the exe reads the unset coordinate from the uninitialised slot.
        struct { Double x, y; } pt;
        if (istf && cinfo.IsFlagSet(DisplayInfo::V_x|DisplayInfo::V_y))
        {
            Render::PointF tpt = ptf->TransformToTextRectSpace(cinfo);
            pt.x = tpt.x;
            pt.y = tpt.y;
        }
        else
        {
            if (cinfo.IsFlagSet(DisplayInfo::V_x))
                pt.x = cinfo.GetX();
            if (cinfo.IsFlagSet(DisplayInfo::V_y))
                pt.y = cinfo.GetY();
        }

        if (cinfo.IsFlagSet(DisplayInfo::V_rotation|DisplayInfo::V_xscale|DisplayInfo::V_yscale))
        {
            Render::Matrix2F om = tfgeomData->OrigMatrix;
            om.Tx() = m.Tx();
            om.Ty() = m.Ty();
            Double origRotation = om.GetRotationDouble();
            Double origXScale = om.GetXScaleDouble();
            Double origYScale = om.GetYScaleDouble();

            Double newXScale = tfgeomData->XScale / 100;
            Double newYScale = tfgeomData->YScale / 100;
            Double newRotation = SF_DEGTORAD(tfgeomData->Rotation);

            Double rval = cinfo.IsFlagSet(DisplayInfo::V_rotation) ? cinfo.GetRotation() : NumberUtil::NaN();
            if (!NumberUtil::IsNaN(rval))
            {
                newRotation = fmod((Double)rval, (Double)360.);
                if (newRotation > 180)
                    newRotation -= 360;
                else if (newRotation < -180)
                    newRotation += 360;
                tfgeomData->Rotation = newRotation;
                newRotation = SF_DEGTORAD(newRotation);
            }
            Double nx = cinfo.IsFlagSet(DisplayInfo::V_xscale) ? (cinfo.GetXScale()/100) : NumberUtil::NaN();
            if ((nx != newXScale) && !NumberUtil::IsNaNOrInfinity(nx))
            {
                tfgeomData->XScale = cinfo.GetXScale();
                if (origXScale == 0 || nx > 1E+16)
                {
                    nx = 0;
                    origXScale = 1;
                }
                newXScale = nx;
            }
            Double ny = cinfo.IsFlagSet(DisplayInfo::V_yscale) ? (cinfo.GetYScale()/100) : NumberUtil::NaN();
            if ((ny != newYScale) && !NumberUtil::IsNaNOrInfinity(ny))
            {
                tfgeomData->YScale = cinfo.GetYScale();
                if (origYScale == 0 || ny > 1E+16)
                {
                    ny = 0;
                    origYScale = 1;
                }
                newYScale = ny;
            }

            ASCharacter_MatrixScaleAndRotate2x2(om,
                float(newXScale/origXScale),
                float(newYScale/origYScale),
                float(newRotation - origRotation));

            m = om;
        }

        Double xval = cinfo.IsFlagSet(DisplayInfo::V_x) ? pt.x : NumberUtil::NaN();
        if (!NumberUtil::IsNaN(xval))
        {
            if (NumberUtil::IsNEGATIVE_INFINITY(xval) || NumberUtil::IsPOSITIVE_INFINITY(xval))
                xval = 0;
            tfgeomData->X = int(floor(Render::PixelsToTwips(xval)));
            m.Tx() = (float) tfgeomData->X;
        }
        Double yval = cinfo.IsFlagSet(DisplayInfo::V_y) ? pt.y : NumberUtil::NaN();
        if (!NumberUtil::IsNaN(yval))
        {
            if (NumberUtil::IsNEGATIVE_INFINITY(yval) || NumberUtil::IsPOSITIVE_INFINITY(yval))
                yval = 0;
            tfgeomData->Y = int(floor(Render::PixelsToTwips(yval)));
            m.Ty() = (float) tfgeomData->Y;
        }

        if (m.IsValid())
        {
            // The exe calls Is3D out of line (0x142513e50) and keeps the vtable in rbx across it, so its body was
            // visible to cl. The member pointer keeps the call and emits the body here.
            bool (DisplayObjectBase::*const is3d)() const = &DisplayObjectBase::Is3D;
            if ((pd->*is3d)())
                pd->UpdateTransform3D();
            else
                pd->SetMatrix(m);
        }

        if (istf)
        {
            if (cinfo.IsFlagSet(Value::DisplayInfo::V_x))
                tfgeomData->X = Alg::IRound(Render::PixelsToTwips(pt.x));
            if (cinfo.IsFlagSet(Value::DisplayInfo::V_y))
                tfgeomData->Y = Alg::IRound(Render::PixelsToTwips(pt.y));
        }
    }

    return true;
}

// Sets the 2D matrix (translation in pixels) and the AS geometry from it.
// @0x142981130
bool AS2ValueObjectInterface::SetDisplayMatrix(void* pdata, const Render::Matrix2F& mat)
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pch) return false;
    if (!mat.IsValid())
        return false;
    Render::Matrix2F m = mat;
    m.Tx() = m.Tx() * 20.f;
    m.Ty() = m.Ty() * 20.f;
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

// Sets the 3D matrix (translation in pixels) and the 3D AS geometry from it.
// @0x142981f00
bool AS2ValueObjectInterface::SetMatrix3D(void* pdata, const Render::Matrix3F& mat)
{
    DisplayObject* pch = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pch) return false;
    if (!VoiValid3D(mat))
        return false;

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

// @0x14298ca20
void AS2ValueObjectInterface::SetUserData(void* pdata, ASUserData* puserdata, bool isdobj)
{
    MovieImpl* pmovie = pMovieRoot;
    VoiEnv(VoiRoot(pmovie));
    AS2::ObjectInterface* pobj = VoiObject(pdata, pmovie, isdobj);
    if (pobj)
        AS2::ObjectInterface_SetUserData(pobj, pMovieRoot->AsMovie(), puserdata, isdobj);
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7AS2ValueObjectInterface_MemberVisitor@GFx@Scaleform@@6B@ 0x143222268
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
