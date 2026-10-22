// Recovered Scaleform 4.1.18 Render: the platform independent part of the mesh cache (Render_MeshCache). Cache
// items hold the tessellated vertices / indices of one batch of meshes (or one complex mesh) in the HAL's buffers;
// they move between the frame lists of a MeshCacheListSet, oldest last. Meshes are tessellated into the staging
// buffer first, a ring of recently generated meshes from which batches are copied together.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout checked against the ctor 0x1426da4a0 (0xa8 bytes, vftables 0x143193be8 / 0x143193c60), Create
// 0x1426db220 and the staging buffer ctor 0x1426da550. The function bodies are in sfr_render_07g.
#ifndef MS2_SF_RENDER_MESHCACHE_H
#define MS2_SF_RENDER_MESHCACHE_H

#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_hash.h"
#include "ms2/scaleform/kernel/sf_allocaddr.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_vertex.h"
#include "ms2/scaleform/include/render/render_primitivequeue.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_sync.h"

namespace Scaleform { namespace Render {

class MeshCacheItem;
class MeshCache;
class MeshCacheListSet;

typedef UInt16 IndexType;

// the caches a render queue keeps locked while it fills them
enum CacheType
{
    Cache_Mesh,
    Cache_Glyph,
    Cache_Count
};

// what the render queue knows of its caches: one pointer per type and a bit per locked one
class RQCacheInterface
{
    CacheBase* pCaches[Cache_Count];   // +0x00
    unsigned   LockFlags;              // +0x10

public:
    RQCacheInterface() : LockFlags(0) { pCaches[Cache_Mesh] = pCaches[Cache_Glyph] = 0; }

    void       SetCache(CacheType t, CacheBase* cache) { pCaches[t] = cache; }
    CacheBase* GetCache(CacheType t) const             { return pCaches[t]; }
    void       SetCacheLocked(CacheType t)             { LockFlags |= 1u << t; }
    void       ClearCacheLocked(CacheType t)           { LockFlags &= ~(1u << t); }
};

// a view of count pointers spaced stride bytes apart
template<class T>
struct StrideArray
{
    T*    pData;
    UPInt Size;
    UPInt Stride;

    StrideArray(T* data, UPInt size) : pData(data), Size(size), Stride(sizeof(T)) { }

    UPInt GetSize() const           { return Size; }
    T&    operator[](UPInt i) const { return *(T*)((UByte*)pData + i * Stride); }
};

// the frame lists of a cache, newest use first
enum MeshCacheListType
{
    MCL_Uncached,       // just allocated, not drawn yet
    MCL_InFlight,       // prepared for the queue that is being drawn
    MCL_ThisFrame,      // drawn this frame
    MCL_PrevFrame,      // drawn last frame
    MCL_LRUTail,        // older, the first to evict
    MCL_PendingFree,    // evicted while the GPU may still read it
    MCL_ItemCount
};

// One cache entry (0x58 bytes plus the platform part, followed by its mesh pointers).
class MeshCacheItem : public ListNode<MeshCacheItem>
{
    friend class MeshCacheListSet;

    MeshCacheListSet*  pCacheList;   // +0x10
    MeshCacheListType  ListType;     // +0x18

public:
    enum MeshType
    {
        Mesh_Regular,
        Mesh_Complex,
        Mesh_Destroyed
    };

    MeshType                    Type;               // +0x1c
    List<MeshCacheItemUseNode>  PrimitiveBatches;   // +0x20, the batches drawing this item
    unsigned                    HashKey;            // +0x30
    unsigned                    MeshCount;          // +0x34
    MeshBase**                  pMeshes;            // +0x38, stored right after the item
    UPInt                       AllocSize;          // +0x40
    unsigned                    VertexCount;        // +0x48
    unsigned                    IndexCount;         // +0x4c
    Ptr<Fence>                  GPUFence;           // +0x50

    // the meshes an item is looked up by, with their xor-of-addresses hash
    struct MeshBaseContent
    {
        StrideArray<MeshBase*> Meshes;    // +0x00
        unsigned               HashKey;   // +0x18

        MeshBaseContent(MeshBase** meshes, unsigned meshCount);   // 0x1426da3e0

        unsigned  GetMeshCount() const          { return (unsigned)Meshes.GetSize(); }
        MeshBase* operator[](unsigned i) const  { return Meshes[i]; }
    };
    struct MeshContent : public MeshBaseContent
    {
        MeshContent(Mesh** meshes, unsigned meshCount) : MeshBaseContent((MeshBase**)meshes, meshCount) { }

        Mesh* operator[](unsigned i) const { return (Mesh*)Meshes[i]; }
    };

    class HashFunctor
    {
    public:
        UPInt operator()(MeshCacheItem* p) const          { return p->HashKey; }
        UPInt operator()(const MeshBaseContent& c) const  { return c.HashKey; }
    };
    typedef MeshBaseContent AltLookupKey;

    static MeshCacheItem* Create(MeshType type, MeshCacheListSet* cacheList, UPInt classSize,
                                 MeshBaseContent& content, UPInt allocSize, unsigned vertexCount,
                                 unsigned indexCount);
    void                  Destroy(MeshBase* skipMesh = 0, bool freeMemory = true);

    // the item mesh's data can be copied from and the vertex / index counts in front of the mesh there
    static MeshCacheItem* FindMeshSourceBatch(Mesh* mesh, unsigned* prevVertexCount, unsigned* prevIndexCount,
                                              MeshCacheItem* skipItem);

    void              NotifyMeshRelease(MeshBase* mesh);
    MeshUseStatus     GetUseStatus() const;
    MeshCacheListType GetListType() const { return ListType; }
    inline MeshCache* GetCache() const;
    inline void       MoveToCacheListFront(MeshCacheListType list);

    bool Equals(const StrideArray<MeshBase*>& meshes) const
    {
        if (MeshCount != (unsigned)meshes.GetSize())
            return false;
        for (unsigned i = 0; i < MeshCount; ++i)
            if (pMeshes[i] != meshes[i])
                return false;
        return true;
    }
};

inline bool operator==(MeshCacheItem* item, const MeshCacheItem::AltLookupKey& key)
{
    return item->Equals(key.Meshes);
}

// The frame lists with the bytes each one holds.
class MeshCacheListSet
{
public:
    struct ListSlot : public List<MeshCacheItem>
    {
        UPInt Size;
        ListSlot() : Size(0) { }
    };

private:
    MeshCache* pCache;                  // +0x00
    ListSlot   Slots[MCL_ItemCount];    // +0x08, 0x18 each

public:
    MeshCacheListSet(MeshCache* cache) : pCache(cache) { }

    void PushFront(MeshCacheListType type, MeshCacheItem* p)
    {
        p->ListType = type;
        Slots[type].PushFront(p);
        Slots[type].Size += p->AllocSize;
    }
    void RemoveNode(MeshCacheItem* p)
    {
        p->RemoveNode();
        Slots[p->ListType].Size -= p->AllocSize;
    }
    // moves all of from in front of to
    void PushListToFront(MeshCacheListType to, MeshCacheListType from)
    {
        ListSlot& src = Slots[from];
        for (MeshCacheItem* p = src.GetFirst(); !src.IsNull(p); p = p->pNext)
            p->ListType = to;
        Slots[to].PushListToFront(src);
        Slots[to].Size += src.Size;
        src.Size = 0;
    }

    MeshCache* GetCache() const                         { return pCache; }
    ListSlot&  GetSlot(MeshCacheListType type)          { return Slots[type]; }
    UPInt      GetSlotSize(MeshCacheListType type) const { return Slots[type].Size; }

    // evict from the tail until an eviction frees size bytes in a (false when the list ran out first)
    bool EvictLRU(ListSlot& list, AllocAddr& a, UPInt size);
    // the same, stopping once the list holds no more than limit bytes
    bool EvictLRUTillLimit(ListSlot& list, AllocAddr& a, UPInt size, UPInt limit);
    bool EvictPendingFree(AllocAddr& a);
    void EvictAll();
    void EndFrame();
};

inline MeshCache* MeshCacheItem::GetCache() const { return pCacheList->GetCache(); }

inline void MeshCacheItem::MoveToCacheListFront(MeshCacheListType list)
{
    pCacheList->RemoveNode(this);
    pCacheList->PushFront(list, this);
}

// The staging ring (0x30 bytes). New meshes go in at the head; making room evicts from the tail, sliding pinned
// meshes along to the head instead.
class MeshStagingBuffer
{
    UByte*                 pBuffer;           // +0x00
    UPInt                  BufferSize;        // +0x08
    UPInt                  TotalPinnedSize;   // +0x10
    UPInt                  PinSizeLimit;      // +0x18, half the buffer
    List<MeshStagingNode>  MeshList;          // +0x20, newest first

    bool AllocateBufferSpace(UPInt* offset, UPInt size);

public:
    MeshStagingBuffer() : pBuffer(0), BufferSize(0), TotalPinnedSize(0), PinSizeLimit(0) { }
    ~MeshStagingBuffer() { Reset(); }

    bool   Initialize(MemoryHeap* heap, UPInt size);
    void   Reset();

    UByte* GetBuffer() const     { return pBuffer; }
    UPInt  GetBufferSize() const { return BufferSize; }

    bool IsCached(MeshBase* mesh) const { return mesh->StagingBufferSize != 0; }
    void PinMesh(MeshBase* mesh)
    {
        if (!mesh->PinCount)
            TotalPinnedSize += mesh->StagingBufferSize;
        mesh->PinCount++;
    }
    void UnpinMesh(MeshBase* mesh)
    {
        mesh->PinCount--;
        if (!mesh->PinCount)
            TotalPinnedSize -= mesh->StagingBufferSize;
    }

    bool AllocateMesh(Mesh* mesh, UPInt vertexCount, UPInt vertexSize, UPInt indexCount);
};

// The cache base the HAL mesh caches derive from.
class MeshCache : public CacheBase, public MeshCacheConfig
{
public:
    typedef HashSetLH<MeshCacheItem*, MeshCacheItem::HashFunctor> CacheItemHashType;

    MemoryHeap*        pHeap;                // +0x10
    RQCacheInterface*  pRQCaches;            // +0x18
    MeshCacheParams    Params;               // +0x20
    MeshStagingBuffer  StagingBuffer;        // +0x68
    CacheItemHashType  BatchCacheItemHash;   // +0x98
    UInt32             Thrashing;            // +0xa0, evictions counted for the profiler

    enum QueueMode
    {
        QM_WaitForFences,
        QM_ExtendLocks
    };

    // Keeps the meshes of a batch in the staging buffer while their data is copied: pins the ones already there,
    // generates the missing ones (with canCopyData only those no other item can provide) and unpins all at the end.
    class StagingBufferPrep
    {
        MeshCache*                   pCache;                 // +0x00
        MeshCacheItem::MeshContent&  MC;                     // +0x08
        bool                         PinnedFlagArray[256];   // +0x10

    public:
        StagingBufferPrep(MeshCache* cache, MeshCacheItem::MeshContent& mc, const VertexFormat* format,
                          bool canCopyData, MeshCacheItem* skipItem = 0);
        ~StagingBufferPrep();
    };

    struct MeshResult
    {
        enum ResultType
        {
            Success_Staging          = 0,
            Success_LargeMesh        = 1,
            Fail_Staging_NoBuffer    = 2,
            Fail_LargeMesh_NeedCache = 3,
            Fail_LargeMesh_TooBig    = 5,
            Fail_General             = 6,
            Fail_LargeMesh_ThisFrame = 7
        };

        MeshResult(ResultType v) : Value(v) { }

        bool IsLargeMesh() const { return (Value & Success_LargeMesh) != 0; }
        bool Succeded() const    { return Value <= Success_LargeMesh; }

        ResultType Value;
    };

    enum AllocResult
    {
        Alloc_Fail,
        Alloc_Fail_TooBig,
        Alloc_Fail_ThisFrame,
        Alloc_Success,
        Alloc_StateError
    };

    enum StatType
    {
        MeshBuffer_Common    = 0,
        MeshBuffer_Vertex    = 1,
        MeshBuffer_Index     = 2,
        MeshBuffer_GpuMem    = 4,
        MeshBuffer_StatCount = 7
    };
    struct Stats
    {
        UPInt TotalSize[MeshBuffer_StatCount];
        UPInt UsedSize[MeshBuffer_StatCount];
    };

    MeshCache(MemoryHeap* heap, const MeshCacheParams& params);
    virtual ~MeshCache();

    void SetRQCacheInterface(RQCacheInterface* rqCaches);

    virtual QueueMode GetQueueMode() const { return QM_WaitForFences; }
    virtual void      BeginFrame() { }
    virtual void      EndFrame() = 0;
    virtual bool      LockBuffers() { return false; }
    virtual void      UnlockBuffers() { }
    virtual bool      AreBuffersLocked() const { return false; }
    virtual MeshUseStatus GetItemUseStatus(const MeshCacheItem* item);

    virtual const MeshCacheParams& GetParams() const { return Params; }

    void MoveToCacheListFront(MeshCacheListType list, MeshCacheItem* p); // 0x1426dbd90

    // frees the item's space (into allocator when given); returns the size of the free block it ended up in
    virtual UPInt Evict(MeshCacheItem* p, AllocAddr* allocator = 0, MeshBase* skipMesh = 0) = 0;
    virtual bool  PreparePrimitive(PrimitiveBatch* batch, MeshCacheItem::MeshContent& mc, bool waitForCache) = 0;
    virtual bool  SetLargeMeshVertices(MeshCacheItem* item, const VertexFormat* sourceFormat, UPInt vertexOffset,
                                       UByte* vertices, unsigned vertexCount, const VertexFormat* destFormat,
                                       UByte* destStart);
    virtual bool  SetLargeMeshIndices(MeshCacheItem* item, const VertexFormat* sourceFormat, UPInt indexOffset,
                                      const UInt16* indices, unsigned indexCount, const VertexFormat* destFormat,
                                      UByte* destStart);

    MeshResult GenerateMesh(Mesh* mesh, const VertexFormat* sourceFormat, const VertexFormat* singleFormat,
                            const VertexFormat* batchFormat, bool waitForCache);
    bool       PrepareComplexMesh(ComplexMesh* mesh, bool waitForCache);

    virtual AllocResult AllocCacheItem(MeshCacheItem** item, UByte** vertexDataStart, IndexType** indexDataStart,
                                       MeshCacheItem::MeshType meshType, MeshCacheItem::MeshBaseContent& mc,
                                       UPInt vertexBufferSize, unsigned vertexCount, unsigned indexCount,
                                       bool waitForCache, const VertexFormat* destFormat) = 0;
    virtual void PostUpdateMesh(MeshCacheItem*) { }
    virtual void GetStats(Stats*) { }
};

}} // namespace Scaleform::Render

#endif
