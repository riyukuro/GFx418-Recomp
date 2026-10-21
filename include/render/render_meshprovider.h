// Recovered Scaleform 4.1.18 Render: the mesh providers the tree nodes get their meshes from, only as far as the
// recovered units use them so far (a provider's reference count, through the MeshProvider subobject at +0x10).
// The shape cache nodes (sfr_render_03f) add the rest of the MeshProvider slots and the ShapeMeshProvider layout
// (its members are out of line in the 03d unit: ctor 0x142629fa0, GetStrokeStyle 0x14262bf30).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_MESHPROVIDER_H
#define MS2_SF_RENDER_MESHPROVIDER_H

#include "../kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_arraystaticbuff.h"
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

// Source of the meshes of one shape (vftable 0x14318f0c0). GetData is the only slot without a default.
class MeshProvider
{
public:
    virtual ~MeshProvider() {}
    virtual void AddRef() {}
    virtual void Release() {}
    // (appended for the shape cache nodes, sfr_render_03f; defaults from the shape mesh provider, sfr_render_03d)
    virtual bool     GetData(MeshBase* mesh, VertexOutput* out, unsigned meshGenFlags) = 0;                  // 3
    virtual void     OnEvict(MeshBase*) {}                                                                  // 4
    virtual RectF    GetIdentityBounds() const { return GetBounds(Matrix2F::Identity); }                    // 5
    virtual RectF    GetBounds(const Matrix2F&) const { return RectF(); }                                  // 6
    virtual RectF    GetCorrectBounds(const Matrix2F&, float, StrokeGenerator*, const ToleranceParams*) const
    {
        return RectF();
    }                                                                                                       // 7
    virtual bool     HitTestShape(const Matrix2F&, float, float, float, StrokeGenerator*,
                                  const ToleranceParams*) const { return false; }                          // 8
    virtual unsigned GetLayerCount() const { return 1; }                                                   // 9
    virtual unsigned GetFillCount(unsigned, unsigned) const { return 0; }                                  // 10
    virtual void     GetFillData(FillData*, unsigned, unsigned, unsigned) {}                               // 11
    virtual void     GetFillMatrix(MeshBase*, Matrix2F*, unsigned, unsigned, unsigned) {}                  // 12
    virtual bool     IsValid() const { return true; }                                                      // 13
};

// A reference counted provider: RefCountBase at +0, MeshProvider at +0x10.
class MeshProvider_RCImpl : public RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>, public MeshProvider
{
public:
    virtual void AddRef() { RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>::AddRef(); }
    virtual void Release() { RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>::Release(); }
};

// the provider's link to its cached mesh keys; dropping it releases the keys (releaseCache 0x142696690, Render_MeshKey)
class MeshKeySetHandle
{
public:
    MeshKeyManager* volatile pManager;   // shared with the render thread
    MeshKeySet* volatile     pKeySet;

    MeshKeySetHandle() : pManager(0), pKeySet(0) {}
    ~MeshKeySetHandle() { releaseCache(); }

    void releaseCache();
};

// A provider whose meshes are keyed by scale (shapes and their bound copies).
class MeshProvider_KeySupport : public MeshProvider_RCImpl
{
public:
    MeshProvider_KeySupport() {}
    ~MeshProvider_KeySupport() {}

    MeshKeySetHandle hKeySet;   // +0x18
};

struct MorphShapeData;

class ShapeMeshProvider : public MeshProvider_KeySupport
{
public:
    // one drawing layer of the shape: its fills, or a single stroke style
    // the image scale9 slicing a fill layer qualifies for
    enum I9gType
    {
        I9gNone,
        I9gNormalSlice,    // one image rectangle
        I9gMergedSlice     // nine adjacent image rectangles of one image
    };

    struct DrawLayerType
    {
        unsigned StartPos;
        unsigned StartFill;        // first entry in FillToStyleTable
        unsigned FillCount;
        unsigned StrokeStyle;      // 1-based, 0 for a fill layer
        unsigned Image9GridType;
    };

    ArrayLH_POD<DrawLayerType> DrawLayers;         // +0x28
    ArrayLH_POD<unsigned>      FillToStyleTable;   // +0x40
    Ptr<ShapeDataInterface>    pShapeData;         // +0x58
    Ptr<MorphShapeData>        pMorphData;         // +0x60
    __declspec(align(16)) RectF IdentityBounds;    // +0x70 (16-aligned in 4.1.18: the object is 0x90)
    bool                       GradientMorph;      // +0x80
    bool                       Strokes;            // +0x81

    void GetStrokeStyle(unsigned idx, StrokeStyleType* style, float morphRatio) const;

    unsigned GetLayerStroke(unsigned layer) const { return DrawLayers[layer].StrokeStyle; }
    bool     HasGradientMorph() const             { return GradientMorph; }

    // (appended for sfr_render_03d, the unit of the bodies)
    ShapeMeshProvider(ShapeDataInterface* shape, ShapeDataInterface* shapeMorph = 0);
    ~ShapeMeshProvider() {}

    void AttachShape(ShapeDataInterface* shape, ShapeDataInterface* shapeMorph = 0);

    virtual bool     GetData(MeshBase* mesh, VertexOutput* out, unsigned meshGenFlags);
    virtual void     OnEvict(MeshBase*) {}
    virtual RectF    GetIdentityBounds() const { return IdentityBounds; }
    virtual RectF    GetBounds(const Matrix2F& m) const;
    virtual RectF    GetCorrectBounds(const Matrix2F& m, float morphRatio, StrokeGenerator* gen,
                                      const ToleranceParams* tol) const;
    virtual bool     HitTestShape(const Matrix2F& m, float x, float y, float morphRatio, StrokeGenerator* gen,
                                  const ToleranceParams* tol) const;
    virtual unsigned GetLayerCount() const { return (unsigned)DrawLayers.GetSize(); }
    virtual unsigned GetFillCount(unsigned layer, unsigned) const { return DrawLayers[layer].FillCount; }
    virtual void     GetFillData(FillData* data, unsigned layer, unsigned fillIndex, unsigned meshGenFlags);
    virtual void     GetFillMatrix(MeshBase* mesh, Matrix2F* matrix, unsigned layer, unsigned fillIndex,
                                   unsigned meshGenFlags);

    unsigned GetFillStyleCount() const   { return pShapeData->GetFillStyleCount(); }
    unsigned GetStrokeStyleCount() const { return pShapeData->GetStrokeStyleCount(); }
    void     GetFillStyle(unsigned idx, FillStyleType* style, float morphRatio) const;
    unsigned GetLayerStartPos(unsigned layer) const { return DrawLayers[layer].StartPos; }
    unsigned GetStyleByFillIdx(unsigned layer, unsigned fillIndex) const
    {
        return FillToStyleTable[DrawLayers[layer].StartFill + fillIndex];
    }
    bool                      HasStrokes() const   { return Strokes; }
    const ShapeDataInterface* GetShapeData() const { return pShapeData; }

private:
    void         createMorphData();
    void         acquireShapeData();
    bool         checkI9gMergedSlice() const;
    bool         checkI9gLayer(const DrawLayerType& layer) const;
    void         perceiveImage9GridLayers();
    RectF        getLayerBounds(unsigned layer) const;
    ComplexFill* getComplexFill(unsigned layer, unsigned fillIndex, unsigned* imgFillStyle) const;
    Matrix2F     getMorphMatrix(unsigned layer, unsigned fillIndex) const;

    // (appended for sfr_render_03d) one non-empty path of the shape while the draw layers are built
    struct TmpPathInfoType
    {
        unsigned ShapeLayer;   // count of the layer starts before it
        unsigned Pos;          // where its path record starts
        unsigned Styles[3];    // fill 0, fill 1, stroke
        unsigned EdgeCount;
    };
    typedef ArrayStaticBuffPOD<TmpPathInfoType, 32> TmpPathsArray;

    void countComplexFills(const TmpPathsArray& paths, UPInt i1, UPInt i2, DrawLayerType* layer);
    void createDrawLayers(const TmpPathsArray& paths, UPInt i1, UPInt i2);
};

// The two ends of a morph re-encoded with matching path records (built by ShapeMeshProvider::createMorphData).
struct MorphShapeData : public RefCountBase<MorphShapeData, Stat_Default_Mem>
{
    typedef ArrayLH_POD<UByte> ContainerType;

    Ptr<ShapeDataInterface>            pMorphTo;     // +0x10
    ContainerType                      Container1;   // +0x18
    ContainerType                      Container2;   // +0x30
    ShapeDataFloatTempl<ContainerType> ShapeData1;   // +0x48
    ShapeDataFloatTempl<ContainerType> ShapeData2;   // +0xb0

    MorphShapeData(ShapeDataInterface* morphTo);
};

}} // namespace Scaleform::Render

#endif
