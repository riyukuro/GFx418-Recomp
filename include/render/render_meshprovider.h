// Recovered Scaleform 4.1.18 Render: the mesh providers the tree nodes get their meshes from, only as far as the
// recovered units use them so far (a provider's reference count, through the MeshProvider subobject at +0x10).
// The shape cache nodes (sfr_render_03f) add the rest of the MeshProvider slots and the ShapeMeshProvider layout
// (its members are out of line in the 03d unit: ctor 0x142629fa0, GetStrokeStyle 0x14262bf30).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_MESHPROVIDER_H
#define MS2_SF_RENDER_MESHPROVIDER_H

#include "../kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_shapedata.h"

namespace Scaleform { namespace Render {

class MeshBase;
class VertexOutput;
class StrokeGenerator;
class FillData;
class MeshKeyManager;
class MeshKeySet;
struct ToleranceParams;

// Source of the meshes of one shape. Only the reference counting slots are declared.
class MeshProvider
{
public:
    virtual ~MeshProvider() {}
    virtual void AddRef() {}
    virtual void Release() {}
    // (appended for the shape cache nodes, sfr_render_03f)
    virtual bool     GetData(MeshBase* mesh, VertexOutput* out, unsigned meshGenFlags)                    = 0;  // 3
    virtual void     OnEvict(MeshBase* mesh)                                                             = 0;  // 4
    virtual RectF    GetIdentityBounds() const                                                           = 0;  // 5
    virtual RectF    GetBounds(const Matrix2F& m) const                                                  = 0;  // 6
    virtual RectF    GetCorrectBounds(const Matrix2F& m, float morphRatio, StrokeGenerator* gen,
                                      const ToleranceParams* tol) const                                  = 0;  // 7
    virtual bool     HitTestShape(const Matrix2F& m, float x, float y, float morphRatio, StrokeGenerator* gen,
                                  const ToleranceParams* tol) const                                      = 0;  // 8
    virtual unsigned GetLayerCount() const                                                               = 0;  // 9
    virtual unsigned GetFillCount(unsigned layer, unsigned meshGenFlags) const                           = 0;  // 10
    virtual void     GetFillData(FillData* data, unsigned layer, unsigned fillIndex, unsigned meshGenFlags) = 0; // 11
    virtual void     GetFillMatrix(MeshBase* mesh, Matrix2F* matrix, unsigned layer, unsigned fillIndex,
                                   unsigned meshGenFlags)                                                = 0;  // 12
};

// A reference counted provider: RefCountBase at +0, MeshProvider at +0x10.
class MeshProvider_RCImpl : public RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>, public MeshProvider
{
public:
    virtual void AddRef() { RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>::AddRef(); }
    virtual void Release() { RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>::Release(); }
};

// A provider whose meshes are keyed by scale (shapes and their bound copies).
class MeshProvider_KeySupport : public MeshProvider_RCImpl
{
public:
    // the provider's link to its cached mesh keys (+0x18)
    struct KeySetHandle
    {
        MeshKeyManager* pManager;
        MeshKeySet*     pKeySet;
    };
    KeySetHandle hKeySet;
};

class ShapeMeshProvider : public MeshProvider_KeySupport
{
public:
    // one drawing layer of the shape: its fills, or a single stroke style
    struct DrawLayerType
    {
        unsigned StartPos;
        unsigned StartFill;
        unsigned FillCount;
        unsigned StrokeStyle;      // 1-based, 0 for a fill layer
        unsigned Image9GridType;
    };

    ArrayLH<DrawLayerType>   DrawLayers;         // +0x28
    ArrayLH<unsigned>        FillToStyleTable;   // +0x40
    Ptr<ShapeDataInterface>  pShapeData;         // +0x58
    Ptr<ShapeDataInterface>  pMorphData;         // +0x60
    void*                    pReserved68;
    RectF                    IdentityBounds;     // +0x70
    bool                     GradientMorph;      // +0x80
    bool                     Strokes;            // +0x81

    void GetStrokeStyle(unsigned idx, StrokeStyleType* style, float morphRatio) const;

    unsigned GetLayerStroke(unsigned layer) const { return DrawLayers[layer].StrokeStyle; }
    bool     HasGradientMorph() const             { return GradientMorph; }
};

}} // namespace Scaleform::Render

#endif
