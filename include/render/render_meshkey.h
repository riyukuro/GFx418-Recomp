// Recovered Scaleform 4.1.18 Render: mesh keys (Render_MeshKey) and the outline of the meshes they cache
// (Render_Primitive / Render_Scale9Grid), as far as the shape cache nodes use them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// A MeshKey names one tessellation of a provider layer at a given scale (key data derived from the view matrix);
// the keys of one provider sit in its MeshKeySet. Out of line elsewhere: MeshKey::Release 0x1426962c0,
// Match 0x142695f00, CalcMatrixKey 0x142695140, GetKeySize 0x142695eb0; MeshKeyManager::CreateMatchingKey
// 0x142695660 (key set) / 0x1426957b0 (provider); Scale9GridData::MakeMeshKey 0x142693fd0; the Mesh ctor 0x14266bc40
// (0xf0 bytes) and the ComplexMesh ctor 0x14266ba80 (0x140 bytes).
#ifndef MS2_SF_RENDER_MESHKEY_H
#define MS2_SF_RENDER_MESHKEY_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_meshprovider.h"

namespace Scaleform { namespace Render {

class Renderer2DImpl;
class PrimitiveFillManager;

// what a mesh is generated for (the meshGenFlags of the providers)
enum MeshGenFlags
{
    Mesh_EdgeAA = 0x01,
    Mesh_Mask   = 0x02,
    Mesh_Scale9 = 0x08
};

// tessellation tolerances (Renderer2DImpl keeps one at +0xcd8)
struct ToleranceParams;

// The scale9 setup a mesh is built for: the grid rectangle, the shape bounds and the three matrices (0x90 bytes).
class Scale9GridData : public RefCountBase<Scale9GridData, Stat_Default_Mem>
{
public:
    RectF    S9Rect;      // +0x10
    RectF    Bounds;      // +0x20
    Matrix2F ShapeMtx;    // +0x30
    Matrix2F Scale9Mtx;   // +0x50
    Matrix2F ViewMtx;     // +0x70

    // filled in by the caller (TreeCacheShapeLayer::calcMeshKey)
    Scale9GridData()
        : S9Rect(RectF::NoInit), Bounds(RectF::NoInit), ShapeMtx(NoInit), Scale9Mtx(NoInit), ViewMtx(NoInit)
    {
    }

    void MakeMeshKey(float* keyData) const;
};

// A cached mesh. Only the scale9 slot is laid out.
class MeshBase : public RefCountBase<MeshBase, StatRender_Mem>
{
    UByte Unk_Members[0x60 - 0x10];        // renderer, provider, view matrix, morph ratio, layer, flags, ...
public:
    Ptr<Scale9GridData> pScale9Grid;       // +0x60

    void SetScale9Grid(Scale9GridData* data) { pScale9Grid = data; }
};

class Mesh : public MeshBase
{
    UByte Unk_MeshMembers[0xf0 - 0x68];
public:
    Mesh(Renderer2DImpl* renderer, MeshProvider* provider, const Matrix2F& viewMatrix, float morphRatio,
         unsigned layer, unsigned meshGenFlags);
};

class ComplexMesh : public MeshBase
{
    UByte Unk_ComplexMembers[0x140 - 0x68];
public:
    ComplexMesh(Renderer2DImpl* renderer, MeshProvider* provider, PrimitiveFillManager* fillManager,
                const Matrix2F& viewMatrix, float morphRatio, unsigned layer, unsigned meshGenFlags);
};

// the keys of one provider; a MeshProvider delegating to it
class MeshKeySet : public MeshProvider
{
};

class MeshKey : public ListNode<MeshKey>
{
public:
    enum { MaxKeySize = 20 };

    enum KeyFlags
    {
        KF_Fill          = 0x0001,
        KF_Stroke        = 0x0002,
        KF_StrokeHinted  = 0x0003,
        KF_KeyTypeMask   = 0x0007,
        KF_Scale9Grid    = 0x0010,
        KF_NormalStroke  = 0x0020,   // uniform scaling may share the mesh
        KF_EdgeAA        = 0x0040,
        KF_Mask          = 0x0080,
        KF_GradientMorph = 0x0100,
        KF_Degenerate    = 0x8000    // singular matrix: any key matches
    };

    static unsigned GetKeySize(unsigned flags);
    static bool     CalcMatrixKey(const Matrix2F& m, float* key, Matrix2F* m2);

    bool Match(unsigned layer, unsigned flags, const float* keyData, const ToleranceParams& cfg) const;

    void AddRef() { ++UseCount; }
    void Release();

    MeshKeySet* GetKeySet() const { return pKeySet; }

    MeshKeySet*   pKeySet;    // +0x10
    Ptr<MeshBase> pMesh;      // +0x18
    UInt16        Size;
    UInt16        Flags;
    unsigned      UseCount;
    float         Data[1];
};

class MeshKeyManager : public RefCountBase<MeshKeyManager, StatRender_Mem>
{
public:
    MeshKey* CreateMatchingKey(MeshKeySet* keySet, unsigned layer, unsigned flags, const float* keyData,
                               const ToleranceParams& cfg);
    MeshKey* CreateMatchingKey(MeshProvider_KeySupport* provider, unsigned layer, unsigned flags,
                               const float* keyData, const ToleranceParams& cfg);
};

}} // namespace Scaleform::Render

#endif
