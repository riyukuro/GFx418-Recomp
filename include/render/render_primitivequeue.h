// Recovered Scaleform 4.1.18 Render: the render queue items of Render_Primitive. A queue item is an Interface
// (prepare, then emit to the HAL) plus a data pointer; Primitive draws a list of meshes with one fill, grouped into
// batches the mesh cache fills; the mask, filter and 3D view / projection primitives only change HAL state.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_PRIMITIVEQUEUE_H
#define MS2_SF_RENDER_PRIMITIVEQUEUE_H

#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_filters.h"

namespace Scaleform { namespace Render {

class RenderQueueProcessor;
class PrimitiveBatch;

class RenderQueueItem
{
public:
    enum QIPrepareResult
    {
        QIP_Done,        // ready to emit
        QIP_NeedCache    // the cache is full: emit what is queued, then prepare again
    };

    // The behaviour of a queued item; the item itself only carries the data pointer.
    class Interface
    {
    public:
        typedef RenderQueueItem::QIPrepareResult QIPrepareResult;

        virtual ~Interface() {}
        virtual QIPrepareResult Prepare(RenderQueueItem&, RenderQueueProcessor&, bool waitForCache)
        {
            SF_UNUSED(waitForCache);
            return QIP_Done;
        }
        virtual void            EmitToHAL(RenderQueueItem&, RenderQueueProcessor&) {}
    };

    RenderQueueItem() : pImpl(0), Data(0) {}
    RenderQueueItem(Interface* i, void* data) : pImpl(i), Data(data) {}

    void*      GetData() const      { return Data; }
    Interface* GetInterface() const { return pImpl; }

protected:
    Interface* pImpl;
    void*      Data;
};

// Walks the render queue for one HAL; only the HAL pointer (its first member) is read so far.
class RenderQueueProcessor
{
public:
    HAL* GetHAL() const { return pHAL; }

protected:
    HAL* pHAL;   // +0x00
};

// The meshes one fill draws, each with its matrix handle, split into batches that share a cache item.
class Primitive : public RefCountBase<Primitive, StatRender_Primitive_Mem>, public RenderQueueItem::Interface
{
    friend class PrimitiveBatch;
public:
    struct MeshEntry
    {
        HMatrix   M;
        Ptr<Mesh> pMesh;

    };

    HAL*                 pHAL;              // +0x18
    Ptr<PrimitiveFill>   pFill;             // +0x20
    List<PrimitiveBatch> Batches;           // +0x28
    const UByte          MatricesPerMesh;   // +0x38: the shape matrix plus one per fill texture
    ArrayLH<MeshEntry>   Meshes;            // +0x40
    // the first mesh index whose batch MeshIndex may be stale (an insert or remove happened below it)
    unsigned             ModifyIndex;       // +0x58

    Primitive(HAL* hal, PrimitiveFill* fill);
    ~Primitive();

    PrimitiveFill*      GetFill() const         { return pFill; }
    const VertexFormat* GetVertexFormat() const { return pFill->GetVertexFormat(); }

    bool     Insert(unsigned index, Mesh* mesh, const HMatrix& m);
    void     Remove(unsigned index, unsigned count);

    unsigned GetMeshCount() const               { return (unsigned)Meshes.GetSize(); }
    Mesh*    GetMesh(unsigned index) const      { return Meshes[index].pMesh; }
    void     SetMesh(unsigned index, Mesh* mesh);

    void     SetMatrix(unsigned index, const HMatrix& m) { Meshes[index].M = m; }
    HMatrix& GetMatrix(unsigned index)                   { return Meshes[index].M; }

    virtual QIPrepareResult Prepare(RenderQueueItem&, RenderQueueProcessor&, bool waitForCache);   // 0x1426d95c0
    virtual void            EmitToHAL(RenderQueueItem&, RenderQueueProcessor&);                    // 0x1426d9510

    // Brings the batch MeshIndex values up to date after inserts / removes.
    void UpdateMeshIndicies();
};

// A batch's link into its mesh cache item.
struct MeshCacheItemUseNode : public ListNode<MeshCacheItemUseNode>
{
    MeshCacheItem* pMeshItem;

    void ClearMeshItem()
    {
        if (pMeshItem)
        {
            RemoveNode();
            pMeshItem = 0;
        }
    }
};

// A run of a primitive's meshes drawn with one call (0x50 bytes, allocated on the primitive's heap).
class PrimitiveBatch : public ListNode<PrimitiveBatch>
{
    friend class Primitive;
public:
    enum BatchType
    {
        DP_Single,       // one mesh
        DP_Batch,        // several meshes merged into one draw
        DP_Instanced,    // one mesh drawn several times through hardware instancing
        DP_Virtual,      // not processed yet: no cache data reserved
        DP_Failed,       // mesh generation failed, nothing to draw
        DP_None,
        DP_DrawableCount = DP_Instanced + 1
    };

    MeshCacheItemUseNode MeshNode;    // +0x10
    BatchType            Type;        // +0x28
    const VertexFormat*  pFormat;     // +0x30
    bool                 LargeMesh;   // +0x38

protected:
    Primitive*           pPrimitive;  // +0x40
    unsigned             MeshCount;   // +0x48
    unsigned             MeshIndex;   // +0x4c

public:
    void Init(Primitive* p, BatchType type, unsigned meshIndex, unsigned meshCount)
    {
        MeshNode.pMeshItem = 0;
        Type       = type;
        pFormat    = 0;
        LargeMesh  = false;
        pPrimitive = p;
        MeshCount  = meshCount;
        MeshIndex  = meshIndex;
    }

    unsigned   GetMeshCount() const { return MeshCount; }
    Primitive* GetPrimitive() const { return pPrimitive; }
    bool       IsVirtual() const    { return Type == DP_Virtual; }
    bool       IsInstanced() const  { return Type == DP_Instanced; }
    void       ClearCacheItem()     { MeshNode.ClearMeshItem(); }

    static PrimitiveBatch* Create(Primitive* p, BatchType type, unsigned meshIndex, unsigned meshCount);
    void RemoveAndFree();
    // Vertex and index totals of the batch (one mesh for an instanced batch).
    void CalcMeshSizes(unsigned* totalVertices, unsigned* totalIndices);
};

// Mask areas, one matrix each.
class MaskPrimitive : public RefCountBase<MaskPrimitive, StatRender_Primitive_Mem>, public RenderQueueItem::Interface
{
public:
    enum MaskAreaType
    {
        Mask_Combinable,
        Mask_Clipped
    };

    void Insert(UPInt index, const HMatrix& m);
    void Remove(UPInt index, UPInt count);

private:
    HAL*             pHAL;        // +0x18
    MaskAreaType     Type;        // +0x20
    ArrayLH<HMatrix> MaskAreas;   // +0x28
};

class RenderTarget;

// A filtered subtree: the filters, the area matrix and up to two cached render targets of the result.
class FilterPrimitive : public RefCountBase<FilterPrimitive, StatRender_Primitive_Mem>,
                        public RenderQueueItem::Interface
{
public:
    enum CacheState
    {
        Cache_Uncached,    // render the filter from scratch
        Cache_PreTarget,   // the step before the final target is cached
        Cache_Target,      // the final result is cached, draw it as a textured quad
        Cache_Count
    };
    enum { MaximumCachedResults = 2 };

    ~FilterPrimitive();

    void Insert(UPInt index, const HMatrix& m);
    void Remove(UPInt index, UPInt count);

    CacheState GetCacheState() const { return Caching; }
    void GetCacheResults(RenderTarget** results, unsigned count);
    void SetCacheResults(CacheState state, RenderTarget** results, unsigned count);

    virtual void            EmitToHAL(RenderQueueItem&, RenderQueueProcessor&);   // 0x14266d830
    virtual QIPrepareResult Prepare(RenderQueueItem&, RenderQueueProcessor&, bool waitForCache);

private:
    HAL*              pHAL;                                 // +0x18
    Ptr<FilterSet>    pFilters;                             // +0x20
    HMatrix           FilterArea;                           // +0x28
    CacheState        Caching;                              // +0x30
    Ptr<RenderTarget> CacheResults[MaximumCachedResults];   // +0x38
    bool              MaskPresent;                          // +0x48
};

// Sets (or, when cleared, pops) the HAL's 3D view matrix.
class ViewMatrix3DPrimitive : public RefCountBase<ViewMatrix3DPrimitive, StatRender_Primitive_Mem>,
                              public RenderQueueItem::Interface
{
public:
    virtual void EmitToHAL(RenderQueueItem&, RenderQueueProcessor&);

private:
    HAL*     pHAL;             // +0x18
    Matrix3F ViewMatrix;       // +0x20
    bool     bHasViewMatrix;   // +0x50
};

// Sets (or, when cleared, pops) the HAL's 3D projection matrix.
class ProjectionMatrix3DPrimitive : public RefCountBase<ProjectionMatrix3DPrimitive, StatRender_Primitive_Mem>,
                                    public RenderQueueItem::Interface
{
public:
    virtual void EmitToHAL(RenderQueueItem&, RenderQueueProcessor&);

private:
    HAL*     pHAL;                   // +0x18
    Matrix4F ProjectionMatrix;       // +0x20
    bool     bHasProjectionMatrix;   // +0x60
};

}} // namespace Scaleform::Render

#endif
