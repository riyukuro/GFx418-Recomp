// Recovered Scaleform 4.1.18 Render: mesh keys (Render_MeshKey) and the outline of the meshes they cache
// (Render_Primitive / Render_Scale9Grid), as far as the shape cache nodes use them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// A MeshKey names one tessellation of a provider layer at a given scale (key data derived from the view matrix);
// the keys of one provider sit in its MeshKeySet. Out of line elsewhere: MeshKey::Release 0x1426962c0,
// Match 0x142695f00, CalcMatrixKey 0x142695140, GetKeySize 0x142695eb0; MeshKeyManager::CreateMatchingKey
// 0x142695660 (key set) / 0x1426957b0 (provider); Scale9GridData::MakeMeshKey 0x142693fd0. The meshes themselves
// are recovered in sfr_render_04f.
#ifndef MS2_SF_RENDER_MESHKEY_H
#define MS2_SF_RENDER_MESHKEY_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_meshprovider.h"
#include "ms2/scaleform/include/render/render_containers.h"

namespace Scaleform { namespace Render {

class Renderer2DImpl;
class PrimitiveFillManager;
class PrimitiveFill;
class Image;
class HAL;
struct VertexFormat;

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

    // (appended for the mesh keys, sfr_render_05d) key floats of a scale9 mesh
    enum { MeshKeySize = 13 };
};

// Where a mesh sits in the staging buffer after mesh generation, when it is there at all (StagingBufferSize != 0);
// the counts stay valid after the mesh is swapped out. Pinned meshes cannot be swapped out.
struct MeshStagingNode : public ListNode<MeshStagingNode>
{
    UPInt    StagingBufferSize;          // +0x18 of the mesh
    UPInt    StagingBufferOffset;
    UPInt    StagingBufferIndexOffset;
    unsigned PinCount;
    unsigned VertexCount;
    unsigned IndexCount;

    MeshStagingNode()
        : StagingBufferSize(0), StagingBufferOffset(0), StagingBufferIndexOffset(0),
          PinCount(0), VertexCount(0), IndexCount(0)
    {
    }
    virtual ~MeshStagingNode() { }
    virtual void OnStagingNodeEvict() { StagingBufferSize = 0; }
};

// how busy the cached copies of a mesh are (fences considered); higher is busier
enum MeshUseStatus
{
    MUS_Uncached = 0
};

class MeshCacheItem
{
public:
    // what a cache item holds
    enum MeshContentType
    {
        Mesh_Regular = 0,
        Mesh_Complex = 1
    };

    void          NotifyMeshRelease(MeshBase* mesh);   // 0x1426dbe00
    MeshUseStatus GetUseStatus() const;                // 0x1426dbce0
};

// What a provider's GetData writes the tessellated vertices and indices to. Each Fill is one vertex set drawn with
// one fill style (two merged ones for EdgeAA); BeginOutput gets them all first so the storage can be sized.
class VertexOutput
{
public:
    struct Fill
    {
        unsigned            VertexCount;
        unsigned            IndexCount;
        const VertexFormat* pFormat;
        unsigned            FillIndex0, FillIndex1;   // provider fill indices
        unsigned            MergeFlags;               // FillMergeFlags
        unsigned            MeshIndex;                // GetData only
    };

    virtual ~VertexOutput() { }
    virtual bool BeginOutput(const Fill* fills, unsigned fillCount, const Matrix2F& vertexMatrix) = 0;
    virtual void EndOutput() = 0;
    virtual void SetVertices(unsigned fillIndex, unsigned vertexOffset, void* vertices, unsigned vertexCount) = 0;
    virtual void SetIndices(unsigned fillIndex, unsigned indexOffset, UInt16* indices, unsigned indexCount) = 0;
};

// A cached mesh: the provider layer it tessellates and the view it was built for (0xa0 bytes; vftables
// 0x143191948 / 0x143191958).
class MeshBase : public RefCountBase<MeshBase, StatRender_Mesh_Mem>, public MeshStagingNode
{
    Renderer2DImpl*     pRenderer2D;   // +0x50
    Ptr<MeshProvider>   pProvider;     // +0x58
public:
    Ptr<Scale9GridData> pScale9Grid;   // +0x60
private:
    Matrix2F            ViewMatrix;    // +0x70
    float               MorphRatio;    // +0x90
    unsigned            Layer;         // +0x94
    unsigned            MGFlags;       // +0x98

public:
    MeshBase(Renderer2DImpl* renderer, MeshProvider* provider, const Matrix2F& viewMatrix, float morphRatio,
             unsigned layer, unsigned meshGenFlags);

    MeshProvider*   GetProvider() const     { return pProvider; }
    void            ClearProvider()         { pProvider.Clear(); }
    void            OnEvictProviderNotify() { if (pProvider) pProvider->OnEvict(this); }

    Renderer2DImpl* GetRenderer() const     { return pRenderer2D; }
    const Matrix2F& GetViewMatrix() const   { return ViewMatrix; }
    float           GetMorphRatio() const   { return MorphRatio; }
    unsigned        GetLayer() const        { return Layer; }
    unsigned        GetMeshGenFlags() const { return MGFlags; }

    Scale9GridData* GetScale9Grid() const   { return pScale9Grid; }
    void            SetScale9Grid(Scale9GridData* data) { pScale9Grid = data; }

    virtual bool    IsEvicted() const { return StagingBufferSize == 0; }
};

// A simple mesh, cached in one or more mesh cache items (0xf0 bytes; vftables 0x143191968 / 0x143191978).
class Mesh : public MeshBase
{
public:
    ArrayReserveLH_Mov<MeshCacheItem*> CacheItems;     // +0xa0, items do not hold a reference
    Matrix2F                           VertexMatrix;   // +0xc0
    bool                               LargeMesh;      // +0xe0

    Mesh(Renderer2DImpl* renderer, MeshProvider* provider, const Matrix2F& viewMatrix, float morphRatio,
         unsigned layer, unsigned meshGenFlags);
    ~Mesh();

    virtual void OnStagingNodeEvict()
    {
        MeshBase::OnStagingNodeEvict();
        if (CacheItems.GetSize() == 0)
            OnEvictProviderNotify();
    }
    virtual bool IsEvicted() const { return CacheItems.GetSize() == 0 && !StagingBufferSize; }

    MeshUseStatus GetUseStatus() const;
};

// A mesh of several fills tessellated together into one cache item (0x140 bytes; vftables 0x1431919d8 /
// 0x1431919e8). Meshes with image fills sit in the renderer's update list so their fills follow texture changes.
class ComplexMesh : public MeshBase
{
public:
    struct UpdateNode : public ListNode<UpdateNode>
    {
        UpdateNode() { pNext = pPrev = 0; }
    };

    // one fill style of the tessellated data
    struct FillRecord
    {
        Ptr<PrimitiveFill>  pFill;
        const VertexFormat* pFormats[2];          // single / instanced
        unsigned            IndexOffset;
        unsigned            IndexCount;
        UPInt               VertexByteOffset;
        unsigned            VertexCount;
        unsigned            FillMatrixIndex[2];
        unsigned            MergeFlags;
    };

    ComplexMesh(Renderer2DImpl* renderer, MeshProvider* provider, PrimitiveFillManager* fillManager,
                const Matrix2F& viewMatrix, float morphRatio, unsigned layer, unsigned meshGenFlags);
    ~ComplexMesh();

    virtual bool IsEvicted() const { return !pCacheMeshItem && !StagingBufferSize; }

    unsigned GetFillCount(unsigned layer, unsigned meshGenFlags) const
    {
        return GetProvider()->GetFillCount(layer, meshGenFlags);
    }

    // Sizes FillRecords to the tessellated fills and creates their primitive fills; returns the vertex buffer
    // size and the vertex / index totals the cache item needs.
    bool InitFillRecords(const VertexOutput::Fill* fills, unsigned fillCount, const Matrix2F& vertexMatrix,
                         HAL* hal, UPInt* vbSize, unsigned* vertexCount, unsigned* indexCount);

    void updateFillMatrixCache(const Matrix2F& vertexMatrix);
    bool updateFills();

    UpdateNode            UpdateListNode;    // +0xa0
    PrimitiveFillManager* pFillManager;      // +0xb0
    MeshCacheItem*        pCacheMeshItem;    // +0xb8
    bool                  AllocTooBig;       // +0xc0
    Matrix2F              VertexMatrix;      // +0xd0
    ArrayLH<FillRecord>   FillRecords;       // +0xf0
    ArrayLH<Matrix2F>     FillMatrixCache;   // +0x108, the provider fill matrices with VertexMatrix prepended
    ArrayLH<Ptr<Image> >  GradientImages;    // +0x120, keeps gradient textures alive for regeneration
};

class MeshKey;

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

    MeshKey() : pKeySet(0), Size(0), Flags(0), UseCount(1) {}

    static unsigned GetKeySize(unsigned flags);
    // the scale key of m (x scale, y scale, skew); with m2 also the rotation-free matrix of the same scale. False
    // for a degenerate m.
    static bool     CalcMatrixKey(const Matrix2F& m, float* key, Matrix2F* m2);
    static bool     CalcMatrixKey_NonOpt(const Matrix2F& m, float* key, Matrix2F* m2);

    bool Match(unsigned layer, unsigned flags, const float* keyData, const ToleranceParams& cfg) const;

    void AddRef() { ++UseCount; }
    void Release();
    bool NotInUse() const { return UseCount == 0; }

    MeshKeySet* GetKeySet() const { return pKeySet; }

    MeshKeySet*   pKeySet;    // +0x10
    Ptr<MeshBase> pMesh;      // +0x18
    UInt16        Size;
    UInt16        Flags;
    unsigned      UseCount;
    float         Data[1];
};

// The keys of one provider (0x38 bytes). It stands in for the provider towards the meshes, forwarding to it while
// the provider lives (pDelegate is cleared under the manager's lock when it goes away).
class MeshKeySet : public ListNode<MeshKeySet>, public MeshProvider, public NewOverrideBase<StatRender_Mem>
{
    friend class MeshKeyManager;
public:
    inline MeshKeySet(MeshKeyManager* manager, MeshProvider_KeySupport* provider);
    inline ~MeshKeySet();

    MeshKey* CreateKey(const float* keyData, unsigned flags);
    void     DestroyKey(MeshKey* key);
    void     DestroyAllKeys();

    virtual void     OnEvict(MeshBase* mesh);
    virtual bool     GetData(MeshBase* mesh, VertexOutput* out, unsigned meshGenFlags)
    {
        return pDelegate->GetData(mesh, out, meshGenFlags);
    }
    virtual RectF    GetIdentityBounds() const { return pDelegate->GetIdentityBounds(); }
    virtual RectF    GetBounds(const Matrix2F& m) const { return pDelegate->GetBounds(m); }
    virtual RectF    GetCorrectBounds(const Matrix2F& m, float morphRatio, StrokeGenerator* gen,
                                      const ToleranceParams* tol) const
    {
        return pDelegate->GetCorrectBounds(m, morphRatio, gen, tol);
    }
    virtual bool     HitTestShape(const Matrix2F& m, float x, float y, float morphRatio, StrokeGenerator* gen,
                                  const ToleranceParams* tol) const
    {
        return pDelegate->HitTestShape(m, x, y, morphRatio, gen, tol);
    }
    virtual unsigned GetLayerCount() const { return pDelegate->GetLayerCount(); }
    virtual unsigned GetFillCount(unsigned layer, unsigned meshGenFlags) const
    {
        return pDelegate->GetFillCount(layer, meshGenFlags);
    }
    virtual void     GetFillData(FillData* data, unsigned layer, unsigned fillIndex, unsigned meshGenFlags)
    {
        pDelegate->GetFillData(data, layer, fillIndex, meshGenFlags);
    }
    virtual void     GetFillMatrix(MeshBase* mesh, Matrix2F* matrix, unsigned layer, unsigned fillIndex,
                                   unsigned meshGenFlags)
    {
        pDelegate->GetFillMatrix(mesh, matrix, layer, fillIndex, meshGenFlags);
    }
    virtual bool     IsValid() const { return pDelegate != 0; }

    bool IsEmpty() const { return Meshes.IsEmpty(); }

private:
    MeshKey* findMatchingKey(unsigned layer, unsigned flags, const float* keyData, const ToleranceParams& cfg);
    void     releaseDelegate_RenderThread();

    Ptr<MeshKeyManager>      pManager;    // +0x18
    MeshProvider_KeySupport* pDelegate;   // +0x20
    List<MeshKey>            Meshes;      // +0x28
};

// Owns the key sets of all providers (0x60 bytes). Key sets of providers that went away wait on the kill list
// until the render thread frees them.
class MeshKeyManager : public RefCountBase<MeshKeyManager, StatRender_Mem>
{
    friend class MeshKeySet;
    friend class MeshKeySetHandle;
public:
    MeshKeyManager(MemoryHeap* renderHeap) : pRenderHeap(renderHeap) {}
    ~MeshKeyManager() { DestroyAllKeys(); }

    void     ProcessKillList();
    void     DestroyAllKeys();
    MeshKey* CreateMatchingKey(MeshKeySet* keySet, unsigned layer, unsigned flags, const float* keyData,
                               const ToleranceParams& cfg);
    MeshKey* CreateMatchingKey(MeshProvider_KeySupport* provider, unsigned layer, unsigned flags,
                               const float* keyData, const ToleranceParams& cfg);

private:
    enum KeySetListType
    {
        KeySet_LiveList,
        KeySet_KillList,
        KeySet_List_Count
    };

    Lock* getLock() { return &KeySetLock; }
    void  providerLost(MeshKeySetHandle& handle);
    void  destroyKeySet(MeshKeySet* keySet);
    void  destroyKeySetList_NTS(KeySetListType type);

    Lock             KeySetLock;                   // +0x10
    List<MeshKeySet> KeySets[KeySet_List_Count];   // +0x38
    MemoryHeap*      pRenderHeap;                  // +0x58
};

inline MeshKeySet::MeshKeySet(MeshKeyManager* manager, MeshProvider_KeySupport* provider)
    : pManager(manager), pDelegate(provider)
{
}
inline MeshKeySet::~MeshKeySet()
{
    DestroyAllKeys();
}

}} // namespace Scaleform::Render

#endif
