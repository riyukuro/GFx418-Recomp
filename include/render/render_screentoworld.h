// Recovered Scaleform 4.1.18 Render: ScreenToWorld, which maps a normalized screen point back through the
// projection, view and world matrices onto the object's z = 0 plane (3D hit testing).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// 0x100 bytes: Sx/Sy +0x00, LastX/LastY +0x08, MatProj +0x10, MatView +0x50, MatWorld +0x80, MatInvProj +0xb0.
// Bodies in sfr_render_02h (Render_ScreenToWorld).
#ifndef MS2_SF_RENDER_SCREENTOWORLD_H
#define MS2_SF_RENDER_SCREENTOWORLD_H

#include <float.h>
#include "ms2/scaleform/include/render/render_matrix4x4.h"

namespace Scaleform { namespace Render {

class ScreenToWorld
{
public:
    ScreenToWorld() : Sx(FLT_MAX), Sy(FLT_MAX), LastX(FLT_MAX), LastY(FLT_MAX) {}

    // nsx/nsy in -1..1; screen y points down, clip space y up
    void SetNormalizedScreenCoords(float nsx, float nsy) { Sx = nsx; Sy = -nsy; }
    void SetView(const Matrix3F& m) { MatView = m; }
    void SetProjection(const Matrix4F& m) { MatProj = m; }
    void SetWorld(const Matrix3F& m) { MatWorld = m; }

    void GetWorldPoint(PointF* ptOut);
    void GetWorldPoint(Point3F* ptOut);

    PointF GetLastWorldPoint() const { return PointF(LastX, LastY); }

private:
    void VectorMult(float* po, const float* pa, float x, float y, float z, float w);
    void VectorMult(float* po, const float* pa, const float* v);
    void VectorInvHomog(float* v);

    float    Sx, Sy;
    float    LastX, LastY;
    Matrix4F MatProj;
    Matrix3F MatView;
    Matrix3F MatWorld;
    Matrix4F MatInvProj;
};

}} // namespace Scaleform::Render

#endif
