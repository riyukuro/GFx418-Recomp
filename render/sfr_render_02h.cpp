// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the screen-to-world TU
// (Render_ScreenToWorld): un-projecting a normalized screen point onto an object's plane, with the 4x4 inverse it
// keeps as a COMDAT.
// Queue unit sfr_render_02 is split along its original sources (sfr_render_02 Matrix2x4 + CxForm, 02b Gradients,
// 02c Filters, 02d TGA reader, 02e DDS reader, 02f PNG reader, 02g JPEG reader, 02h ScreenToWorld).
// MS2-UNIT: sfr_render_02h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142602c20-0x142603a30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_screentoworld.h"

namespace Scaleform { namespace Render {

// Element (row, col) of a 4x4 taken column-major: po = M * v over the stored transpose.
#define SF_S2W_M(pa, r, c) (pa)[(c) * 4 + (r)]

// @0x1426037c0
void ScreenToWorld::GetWorldPoint(PointF* ptOut)
{
    Point3F p;
    GetWorldPoint(&p);
    ptOut->x = p.x;
    ptOut->y = p.y;
}

// @0x1426032f0
void ScreenToWorld::GetWorldPoint(Point3F* ptOut)
{
    if (Sx == FLT_MAX || Sy == FLT_MAX)
        return;

    Matrix4F invModelView, modelView;

    // clip space -> view space
    MatInvProj.SetInverse(MatProj);
    // view space -> model space
    modelView = Matrix3F(MatView, MatWorld);
    invModelView.SetInverse(modelView);

    const float* invMV   = invModelView;
    const float* invProj = MatInvProj;
    const float* proj    = MatProj;

    float nearClip[4], farClip[4];
    float nearView[4], farView[4];
    float nearObj[4], farObj[4];

    // two view-space z planes projected to clip space (a far one for precision)
    VectorMult(nearClip, proj, 0, 0, -0.5f, 1);
    VectorMult(farClip, proj, 0, 0, -100.0f, 1);

    // the screen point on both planes back in view space
    VectorMult(nearView, invProj, Sx * nearClip[3], Sy * nearClip[3], nearClip[2] * nearClip[3], nearClip[3]);
    VectorMult(farView, invProj, Sx * farClip[3], Sy * farClip[3], farClip[2] * farClip[3], farClip[3]);
    VectorInvHomog(nearView);
    VectorInvHomog(farView);

    VectorMult(nearObj, invMV, nearView);
    VectorMult(farObj, invMV, farView);

    // where the ray crosses z = 0
    float dx = farObj[0] - nearObj[0];
    float dy = farObj[1] - nearObj[1];
    float dz = farObj[2] - nearObj[2];
    float t  = (dz != 0) ? -nearObj[2] / dz : 0.0f;

    LastX = ptOut->x = nearObj[0] + t * dx;
    LastY = ptOut->y = nearObj[1] + t * dy;
    ptOut->z = nearObj[2] + t * dz;
}

// @0x142603920
void ScreenToWorld::VectorMult(float* po, const float* pa, float x, float y, float z, float w)
{
    po[0] = SF_S2W_M(pa, 0, 0) * x + SF_S2W_M(pa, 1, 0) * y + SF_S2W_M(pa, 2, 0) * z + SF_S2W_M(pa, 3, 0) * w;
    po[1] = SF_S2W_M(pa, 0, 1) * x + SF_S2W_M(pa, 1, 1) * y + SF_S2W_M(pa, 2, 1) * z + SF_S2W_M(pa, 3, 1) * w;
    po[2] = SF_S2W_M(pa, 0, 2) * x + SF_S2W_M(pa, 1, 2) * y + SF_S2W_M(pa, 2, 2) * z + SF_S2W_M(pa, 3, 2) * w;
    po[3] = SF_S2W_M(pa, 0, 3) * x + SF_S2W_M(pa, 1, 3) * y + SF_S2W_M(pa, 2, 3) * z + SF_S2W_M(pa, 3, 3) * w;
}

// @0x142603820
void ScreenToWorld::VectorMult(float* po, const float* pa, const float* v)
{
    po[0] = SF_S2W_M(pa, 0, 0) * v[0] + SF_S2W_M(pa, 1, 0) * v[1] + SF_S2W_M(pa, 2, 0) * v[2] + SF_S2W_M(pa, 3, 0) * v[3];
    po[1] = SF_S2W_M(pa, 0, 1) * v[0] + SF_S2W_M(pa, 1, 1) * v[1] + SF_S2W_M(pa, 2, 1) * v[2] + SF_S2W_M(pa, 3, 1) * v[3];
    po[2] = SF_S2W_M(pa, 0, 2) * v[0] + SF_S2W_M(pa, 1, 2) * v[1] + SF_S2W_M(pa, 2, 2) * v[2] + SF_S2W_M(pa, 3, 2) * v[3];
    po[3] = SF_S2W_M(pa, 0, 3) * v[0] + SF_S2W_M(pa, 1, 3) * v[1] + SF_S2W_M(pa, 2, 3) * v[2] + SF_S2W_M(pa, 3, 3) * v[3];
}

// @0x1426037f0
void ScreenToWorld::VectorInvHomog(float* v)
{
    v[0] *= v[3];
    v[1] *= v[3];
    v[2] *= v[3];
    v[3] = 1;
}

}} // namespace Scaleform::Render
