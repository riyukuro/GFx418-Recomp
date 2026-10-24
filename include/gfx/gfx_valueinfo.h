// Recovered Scaleform 4.1.18 GFx: the nested helper classes of GFx::Value that gfx_value.h only declares: the
// member and element visitors of ObjectInterface::VisitMembers / VisitElements, and the display properties
// Get/SetDisplayInfo exchange. Kept out of gfx_value.h so its many includers do not pull in the render matrices.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
#ifndef MS2_SF_GFX_VALUEINFO_H
#define MS2_SF_GFX_VALUEINFO_H

#include "gfx_value.h"
#include "../render/render_matrix4x4.h"
#include "../render/render_constants.h"

namespace Scaleform { namespace GFx {

// Receives each member VisitMembers enumerates (Visit is slot 2).
class Value::ObjectInterface::ObjVisitor
{
public:
    virtual ~ObjVisitor() {}
    virtual bool IncludeAS3PublicMembers() const { return false; }
    virtual void Visit(const char* name, const Value& val) = 0;
};

// Receives each element VisitElements enumerates (Visit is slot 1).
class Value::ObjectInterface::ArrVisitor
{
public:
    virtual ~ArrVisitor() {}
    virtual void Visit(unsigned idx, const Value& val) = 0;
};

// The display properties of a display object value: pixels, percent and degrees, with a bit per field that is set.
// 0xe0 bytes (the matrices are 16-aligned).
class Value::DisplayInfo
{
public:
    enum Flags
    {
        V_x            = 0x0001,
        V_y            = 0x0002,
        V_rotation     = 0x0004,
        V_xscale       = 0x0008,
        V_yscale       = 0x0010,
        V_alpha        = 0x0020,
        V_visible      = 0x0040,
        V_z            = 0x0080,
        V_xrotation    = 0x0100,
        V_yrotation    = 0x0200,
        V_zscale       = 0x0400,
        V_FOV          = 0x0800,
        V_projMatrix3D = 0x1000,
        V_viewMatrix3D = 0x2000,
        V_edgeaaMode   = 0x4000
    };

    Double                X, Y;               // +0x00
    Double                Rotation;           // +0x10
    Double                XScale, YScale;     // +0x18
    Double                Alpha;              // +0x28
    bool                  Visible;            // +0x30
    Double                Z;                  // +0x38
    Double                XRotation;          // +0x40
    Double                YRotation;          // +0x48
    Double                ZScale;             // +0x50
    Double                FOV;                // +0x58
    Render::Matrix3F      ViewMatrix3D;       // +0x60
    Render::Matrix4F      ProjectionMatrix3D; // +0x90
    Render::EdgeAAMode    EdgeAAMode;         // +0xd0
    UInt16                VarsSet;            // +0xd4

    bool IsFlagSet(unsigned flags) const { return (VarsSet & flags) != 0; }
};
static_assert(offsetof(Value::DisplayInfo, Visible) == 0x30, "DisplayInfo::Visible");
static_assert(offsetof(Value::DisplayInfo, ViewMatrix3D) == 0x60, "DisplayInfo::ViewMatrix3D");
static_assert(offsetof(Value::DisplayInfo, ProjectionMatrix3D) == 0x90, "DisplayInfo::ProjectionMatrix3D");
static_assert(offsetof(Value::DisplayInfo, EdgeAAMode) == 0xd0, "DisplayInfo::EdgeAAMode");
static_assert(offsetof(Value::DisplayInfo, VarsSet) == 0xd4, "DisplayInfo::VarsSet");
static_assert(sizeof(Value::DisplayInfo) == 0xe0, "DisplayInfo size");

}} // namespace Scaleform::GFx

#endif
