// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// the display info of a clip for the host (GFx::Value::GetDisplayInfo).
// MS2-UNIT: sfr_as2_05v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14294a5b0-0x14294a8f0 .text$mn

#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/as2/as2_valueobjectinterface.h"
#include "../include/gfx/gfx_characterdef.h"
#include "../include/gfx/gfx_displayobject.h"

void FUN_1425b8e60(void* ptf, void* pinfo); // TextField: the display info of a text field (its text rect space)

namespace Scaleform { namespace GFx {

namespace {

// Value::DisplayInfo as the getter fills it.
struct DiDisplayInfo
{
    Double   X, Y;               // +0x00 pixels
    Double   Rotation;           // +0x10
    Double   XScale, YScale;     // +0x18
    Double   Alpha;              // +0x28 percent
    bool     Visible;            // +0x30
    Double   Z;                  // +0x38
    Double   XRotation;          // +0x40
    Double   YRotation;          // +0x48
    Double   ZScale;             // +0x50
    Double   FOV;                // +0x58
    Matrix3F ViewMatrix3D;       // +0x60
    Matrix4F ProjectionMatrix3D; // +0x90
    UInt32   EdgeAAMode;         // +0xd0
    UInt16   VarsSet;            // +0xd4 V_* bits of the fields set
};
static_assert(offsetof(DiDisplayInfo, ViewMatrix3D) == 0x60, "DisplayInfo::ViewMatrix3D");
static_assert(offsetof(DiDisplayInfo, ProjectionMatrix3D) == 0x90, "DisplayInfo::ProjectionMatrix3D");
static_assert(offsetof(DiDisplayInfo, VarsSet) == 0xd4, "DisplayInfo::VarsSet");

} // namespace

// Position, scales, rotations (pixels / percent / degrees), alpha, visibility, the field of view, the 3D matrices
// and the edge AA mode of the character pdata; a text field gives its own position fields.
// MS2-FUNCTIONAL: DisplayInfo is written through a layout view (DisplayInfo::Set inlined in the exe); Z stays in twips
// as in the exe
// @0x14294a5b0
bool AS2ValueObjectInterface::GetDisplayInfo(void* pdata, Value::DisplayInfo* pinfo) const
{
    DisplayObject* pd = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pd)
        return false;
    DiDisplayInfo* info = reinterpret_cast<DiDisplayInfo*>(pinfo);

    DisplayObjectBase::GeomDataType geomData;
    pd->GetGeomData(geomData);
    if (pd->GetType() == CharacterDef::TextField)
        FUN_1425b8e60(pd, pinfo);
    else
    {
        const Double x     = Double(geomData.X) * 0.05;
        const Double y     = Double(geomData.Y) * 0.05;
        const float  alpha = reinterpret_cast<const float*>(&pd->GetCxform())[3] * 100.0f;
        info->Visible   = pd->GetVisible();
        info->VarsSet  |= 0x7ff;
        info->X         = x;
        info->Y         = y;
        info->Rotation  = geomData.Rotation;
        info->Alpha     = Double(alpha);
        info->XScale    = geomData.XScale;
        info->YScale    = geomData.YScale;
        info->XRotation = geomData.XRotation;
        info->YRotation = geomData.YRotation;
        info->ZScale    = geomData.ZScale;
        info->Z         = geomData.Z;
    }

    const Double fov = pd->GetFOV();
    info->VarsSet |= 0x800;
    info->FOV = fov;
    Matrix4F matProj;
    if (pd->GetProjectionMatrix3D(&matProj, false))
    {
        info->VarsSet |= 0x1000;
        info->ProjectionMatrix3D = matProj;
    }
    Matrix3F matView;
    if (pd->GetViewMatrix3D(&matView, false))
    {
        info->VarsSet |= 0x2000;
        info->ViewMatrix3D = matView;
    }
    const unsigned edgeAA = pd->GetRenderNode()->GetEdgeAAMode();
    info->VarsSet |= 0x4000;
    info->EdgeAAMode = edgeAA;
    return true;
}

}} // namespace Scaleform::GFx
