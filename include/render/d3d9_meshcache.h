// Recovered Scaleform 4.1.18 Render: the D3D9 mesh cache (D3D9_MeshCache section of sfr_d3d9_01,
// 0x142738e60-0x14273c230). Written from the exe; names from the SDK headers.
// Cache items live in D3D vertex / index buffers, each carved up by an AllocAddr in 16-byte units; the high byte of an
// allocator address is the buffer's index in its set. Reserve buffers are created up front, chunk buffers on demand
// (and given back at the end of a frame when the cache has more room than it needs). D3D event queries are the fences
// that keep evicted items alive while the GPU may still read them.
//
// Layouts (exe): Render::MeshBuffer 0x30 (vftable 0x14319dd88), D3D9::MeshBuffer 0x48 (0x14319ddd8), the buffer
// templates 0x50 (VertexBuffer 0x14319de38, IndexBuffer 0x14319de88), MeshBufferSet 0x48 (0x14319de00; VB set
// 0x14319deb0, IB set 0x14319dec0), D3D9::MeshCacheItem 0x88, D3D9::RenderSync 0xb8 (0x14319dd90), D3D9::MeshCache
// 0x2e0 (0x14319ded0 / MeshCacheConfig 0x14319df48).
#ifndef MS2_SF_RENDER_D3D9_MESHCACHE_H
#define MS2_SF_RENDER_D3D9_MESHCACHE_H

#include <d3d9.h>
#include "ms2/scaleform/include/render/render_meshcache.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_stats.h"

namespace Scaleform { namespace Render {

// shifts count indices by delta while copying them (0x1426b9130)
void ConvertIndices(UInt16* dest, UInt16* src, unsigned count, UInt16 delta);

// A HAL buffer the mesh cache allocates items in (base of the platform buffers).
class MeshBuffer : public ListNode<MeshBuffer>, public NewOverrideBase<StatRender_Mesh_Mem>
{
public:
    enum AllocType
    {
        AT_None,
        AT_Reserve,   // made at Initialize from MemReserve, kept for the cache's life
        AT_Chunk,     // made when the reserve ran out, may be given back
        AT_Direct
    };

    MeshBuffer(UPInt size, AllocType type, unsigned arena)
        : Arena(arena), Type(type), Size(size), pData(0) { }
    virtual ~MeshBuffer() { }

    UPInt     GetSize() const { return Size; }
    AllocType GetType() const { return Type; }

    unsigned  Arena;   // +0x18
    AllocType Type;    // +0x1c
    UPInt     Size;    // +0x20
    UByte*    pData;   // +0x28, while locked
};

namespace D3D9 {

class MeshCache;
class MeshBuffer;

// The D3D9 part of a cache item: where its vertices and indices sit.
class MeshCacheItem : public Render::MeshCacheItem
{
    friend class MeshCache;

public:
    static MeshCacheItem* Create(MeshType type, MeshCacheListSet* cacheList, MeshBaseContent& mc,
                                 MeshBuffer* vb, MeshBuffer* ib, unsigned vertexOffset, UPInt vertexAllocSize,
                                 unsigned vertexCount, unsigned indexOffset, UPInt indexAllocSize, unsigned indexCount)
    {
        MeshCacheItem* p = (MeshCacheItem*)Render::MeshCacheItem::Create(type, cacheList, sizeof(MeshCacheItem), mc,
                                                                         vertexAllocSize + indexAllocSize,
                                                                         vertexCount, indexCount);
        if (p)
        {
            p->pVertexBuffer  = vb;
            p->pIndexBuffer   = ib;
            p->VBAllocOffset  = vertexOffset;
            p->VBAllocSize    = vertexAllocSize;
            p->IBAllocOffset  = indexOffset;
            p->IBAllocSize    = indexAllocSize;
        }
        return p;
    }

    MeshBuffer* pVertexBuffer;   // +0x58
    MeshBuffer* pIndexBuffer;    // +0x60
    UPInt       VBAllocOffset;   // +0x68
    UPInt       VBAllocSize;     // +0x70
    UPInt       IBAllocOffset;   // +0x78
    UPInt       IBAllocSize;     // +0x80
};

// A vertex or index buffer of the cache.
class MeshBuffer : public Render::MeshBuffer
{
public:
    enum BufferType
    {
        Buffer_Vertex,
        Buffer_Index
    };

    UPInt       Index;       // +0x30, slot in its set
    MeshBuffer* pNextLock;   // +0x38, chain of the buffers locked this frame
    unsigned    Flags;       // +0x40, BufferCreateFlags of the cache

    MeshBuffer(UPInt size, AllocType type, unsigned arena, unsigned flags)
        : Render::MeshBuffer(size, type, arena), Flags(flags) { }

    virtual bool       allocBuffer(IDirect3DDevice9* device) = 0;
    virtual bool       DoLock() = 0;
    virtual void       Unlock() = 0;
    virtual BufferType GetBufferType() const = 0;

    // the buffer's memory, mapped on first use and queued on locked so it is unmapped at UnlockBuffers
    UByte* Lock(MeshBuffer*& locked)
    {
        if (!pData)
        {
            if (!DoLock())
                return 0;
            pNextLock = locked;
            locked    = this;
        }
        return pData;
    }

    // the cache's buffers of one kind, indexed by the high byte of their allocator addresses
    class LockList
    {
    public:
        MeshBuffer* pFirst;
        LockList() : pFirst(0) { }
        void UnlockAll()
        {
            for (MeshBuffer* p = pFirst; p; p = p->pNextLock)
                p->Unlock();
            pFirst = 0;
        }
    };
};

// The buffers of one kind (vertex or index) with the allocator over their space.
class MeshBufferSet
{
public:
    typedef MeshBuffer::AllocType AllocType;

    ArrayLH<MeshBuffer*> Buffers;       // +0x08
    AllocAddr            Allocator;     // +0x20
    UPInt                Granularity;   // +0x38
    UPInt                TotalSize;     // +0x40

    MeshBufferSet(MemoryHeap* heap, UPInt granularity) : Allocator(heap), Granularity(granularity), TotalSize(0) { }
    virtual ~MeshBufferSet() { }

    virtual MeshBuffer* CreateBuffer(UPInt size, AllocType type, unsigned arena, MemoryHeap* heap,
                                     IDirect3DDevice9* device, unsigned flags) = 0;

    AllocAddr& GetAllocator()                      { return Allocator; }
    UPInt      GetGranularity() const              { return Granularity; }
    void       SetGranularity(UPInt granularity)   { Granularity = granularity; }
    UPInt      GetTotalSize() const                { return TotalSize; }

    // takes the buffer's space out of the allocator; the buffer itself stays alive
    void DestroyBuffer(MeshBuffer* buffer, bool deleteBuffer = true)
    {
        Allocator.RemoveSegment(buffer->Index << 24, (buffer->Size + 15) >> 4);
        TotalSize -= buffer->Size;
        Buffers[buffer->Index] = 0;
        if (deleteBuffer)
            delete buffer;
    }
    // true when some buffer is larger than size (so the item could fit once the cache is emptied)
    bool CheckAllocationSize(UPInt size)
    {
        UPInt largest = 0;
        for (UPInt i = 0; i < Buffers.GetSize(); i++)
        {
            if (Buffers[i]->Size > size)
                return true;
            if (Buffers[i]->Size > largest)
                largest = Buffers[i]->Size;
        }
        return false;
    }
    // all buffers (type AT_None) or those of one type
    void DestroyBuffers(AllocType type = MeshBuffer::AT_None);   // 0x14273a060

    // an item's space: false when nothing fits
    bool Alloc(UPInt size, MeshBuffer** buffer, UPInt* offset);   // 0x1427397c0
    UPInt Free(UPInt size, MeshBuffer* buffer, UPInt offset)
    {
        return Allocator.Free((buffer->Index << 24) | (offset >> 4), (size + 15) >> 4) << 4;
    }
};

// A D3D buffer of the kind B (IDirect3DVertexBuffer9 / IDirect3DIndexBuffer9).
template<class B>
class MeshBufferImpl : public MeshBuffer
{
public:
    Ptr<B> pBuffer;   // +0x48

    MeshBufferImpl(UPInt size, AllocType type, unsigned arena, unsigned flags)
        : MeshBuffer(size, type, arena, flags) { }

    virtual bool DoLock()
    {
        DWORD lockFlags = (Flags & 1) ? D3DLOCK_NOOVERWRITE : 0;
        return SUCCEEDED(pBuffer->Lock(0, (UINT)Size, (void**)&pData, lockFlags));
    }
    virtual void Unlock()
    {
        if (pData)
        {
            pBuffer->Unlock();
            pData = 0;
        }
    }

    DWORD GetUsage() const { return ((Flags & 1) ? D3DUSAGE_DYNAMIC : 0) | D3DUSAGE_WRITEONLY; }
};

class VertexBuffer : public MeshBufferImpl<IDirect3DVertexBuffer9>
{
public:
    VertexBuffer(UPInt size, AllocType type, unsigned arena, unsigned flags)
        : MeshBufferImpl<IDirect3DVertexBuffer9>(size, type, arena, flags) { }

    virtual bool allocBuffer(IDirect3DDevice9* device)
    {
        return device->CreateVertexBuffer((UINT)Size, GetUsage(), 0, D3DPOOL_DEFAULT, &pBuffer.GetRawRef(), 0) == D3D_OK;
    }
    virtual BufferType GetBufferType() const { return Buffer_Vertex; }
};

class IndexBuffer : public MeshBufferImpl<IDirect3DIndexBuffer9>
{
public:
    IndexBuffer(UPInt size, AllocType type, unsigned arena, unsigned flags)
        : MeshBufferImpl<IDirect3DIndexBuffer9>(size, type, arena, flags) { }

    virtual bool allocBuffer(IDirect3DDevice9* device)
    {
        return device->CreateIndexBuffer((UINT)Size, GetUsage(), D3DFMT_INDEX16, D3DPOOL_DEFAULT, &pBuffer.GetRawRef(), 0)
               == D3D_OK;
    }
    virtual BufferType GetBufferType() const { return Buffer_Index; }
};

// The set of buffers of type T; a set holds at most 256 buffers.
template<class T>
class MeshBufferSetImpl : public MeshBufferSet
{
public:
    MeshBufferSetImpl(MemoryHeap* heap, UPInt granularity) : MeshBufferSet(heap, granularity) { }

    virtual MeshBuffer* CreateBuffer(UPInt size, AllocType type, unsigned arena, MemoryHeap* heap,
                                     IDirect3DDevice9* device, unsigned flags)
    {
        return Create(size, type, arena, heap, device, flags, *this);
    }

    // MeshBufferImpl::Create in the SDK
    static T* Create(UPInt size, AllocType type, unsigned arena, MemoryHeap* heap, IDirect3DDevice9* device,
                     unsigned flags, MeshBufferSet& mbs)
    {
        UPInt index = 0;
        while ((index < mbs.Buffers.GetSize()) && mbs.Buffers[index])
            index++;
        if (index == 256)
            return 0;

        size = ((size + 16 - 1) >> 4) << 4;

        T* p = SF_HEAP_NEW(heap) T(size, type, arena, flags);
        if (!p) return 0;

        if (!p->allocBuffer(device))
        {
            delete p;
            return 0;
        }
        p->Index = index;

        mbs.Allocator.AddSegment(index << 24, size >> 4);
        mbs.TotalSize += size;

        if (index == mbs.Buffers.GetSize())
            mbs.Buffers.PushBack(p);
        else
            mbs.Buffers[index] = p;

        return p;
    }
};

typedef MeshBufferSetImpl<VertexBuffer> VertexBufferSet;
typedef MeshBufferSetImpl<IndexBuffer>  IndexBufferSet;

// The fences: an end-of-frame event query each frame, a fresh query for every inserted fence.
class RenderSync : public Render::RenderSync
{
    friend class MeshCache;

public:
    RenderSync() : pNextEndFrameFence(0) { }

    // false when the device has no event queries (the cache then does without fences)
    bool SetDevice(IDirect3DDevice9* device);   // 0x14273b070

    virtual void BeginFrame();                                                       // 0x142739bd0
    virtual bool EndFrame();                                                         // 0x14273a580
    virtual void KickOffFences(FenceType) { }                                        // 0x14273ab70
    virtual bool IsPending(FenceType waitType, UInt64 handle, const FenceFrame& parent);   // 0x14273ab20
    virtual void WaitFence(FenceType waitType, UInt64 handle, const FenceFrame& parent);   // 0x14273b3c0
    virtual UInt64 SetFence();                                                       // 0x14273b110
    virtual void ReleaseFence(UInt64 handle);                                        // 0x14273ae10

private:
    IDirect3DQuery9*       pNextEndFrameFence;   // +0xa8
    Ptr<IDirect3DDevice9>  pDevice;              // +0xb0
};

class HAL;

// The D3D9 mesh cache.
class MeshCache : public Render::MeshCache
{
    friend class HAL;

public:
    enum { MinSupportedGranularity = 16 * 1024 };

    MeshCache(MemoryHeap* heap, const MeshCacheParams& params);   // 0x142738e60
    ~MeshCache();                                                 // 0x142739170

    bool Initialize(IDirect3DDevice9* device, bool dynamicBuffers);   // 0x14273a880
    void Reset();                                                     // 0x14273aec0

    // MeshCacheConfig
    virtual bool SetParams(const MeshCacheParams& params);   // 0x14273b150
    virtual void ClearCache();                               // 0x142739c30

    // Render::MeshCache
    virtual QueueMode GetQueueMode() const    { return QM_ExtendLocks; }   // 0x14273a770
    virtual void      BeginFrame()            { GetRenderSync()->BeginFrame(); }   // 0x142739bc0
    virtual void      EndFrame();                                          // 0x14273a190
    virtual bool      LockBuffers();                                       // 0x14273ab80
    virtual void      UnlockBuffers();                                     // 0x14273b360
    virtual bool      AreBuffersLocked() const { return Locked; }          // 0x142739bb0

    virtual UPInt Evict(Render::MeshCacheItem* p, AllocAddr* allocator = 0, MeshBase* skipMesh = 0);   // 0x14273a5e0
    virtual bool  PreparePrimitive(PrimitiveBatch* batch, MeshCacheItem::MeshContent& mc,
                                   bool waitForCache);                                                // 0x14273abb0
    virtual AllocResult AllocCacheItem(Render::MeshCacheItem** item, UByte** vertexDataStart,
                                       IndexType** indexDataStart, MeshCacheItem::MeshType meshType,
                                       MeshCacheItem::MeshBaseContent& mc, UPInt vertexBufferSize,
                                       unsigned vertexCount, unsigned indexCount, bool waitForCache,
                                       const VertexFormat* destFormat);                               // 0x142739840
    virtual void GetStats(Stats* stats);                                                              // 0x14273a780

    RenderSync* GetRenderSync() { return &RSync; }

private:
    // the item's buffer space in one set: evicts (and with waitForCache waits on fences) until it fits, may add a
    // chunk buffer; false when the item cannot be placed this frame
    bool allocBuffer(UPInt* offset, MeshBuffer** buffer, MeshBufferSet& mbs, UPInt size,
                     bool waitForCache);                                                  // 0x14273b590
    bool allocCacheBuffers(UPInt size, MeshBuffer::AllocType type, unsigned arena = 0);  // 0x14273b870
    void destroyBuffers(MeshBuffer::AllocType type = MeshBuffer::AT_None);               // 0x14273bf30
    void destroyPendingBuffers();                                                         // 0x14273bf90
    bool evictMeshesInBuffer(MeshCacheListSet::ListSlot* plist, UPInt count, MeshBuffer* pbuffer);   // 0x14273c0e0
    void adjustMeshCacheParams(MeshCacheParams* params, IDirect3DDevice9* device);       // 0x14273b480

    bool createStaticVertexBuffers(IDirect3DDevice9* device);          // 0x14273bd30
    bool createInstancingVertexBuffer(IDirect3DDevice9* device);       // 0x14273b9b0
    bool createMaskEraseBatchVertexBuffer(IDirect3DDevice9* device);   // 0x14273bba0

    UPInt getTotalSize() const      { return VertexBuffers.GetTotalSize() + IndexBuffers.GetTotalSize(); }
    bool  UsesDynamicMeshes() const { return (BufferCreateFlags & 1) != 0; }

    Ptr<IDirect3DDevice9>        pDevice;                           // +0xa8
    MeshCacheListSet             CacheList;                         // +0xb0
    RenderSync                   RSync;                             // +0x148
    unsigned                     BufferCreateFlags;                 // +0x200
    VertexBufferSet              VertexBuffers;                     // +0x208
    IndexBufferSet               IndexBuffers;                      // +0x250
    bool                         Locked;                            // +0x298
    UPInt                        VBSizeEvictedInLock;               // +0x2a0
    MeshBuffer::LockList         LockedBuffers;                     // +0x2a8
    List<Render::MeshBuffer>     ChunkBuffers;                      // +0x2b0
    List<Render::MeshBuffer>     PendingDestructionBuffers;         // +0x2c0
    Ptr<IDirect3DVertexBuffer9>  pInstancingVertexBuffer;           // +0x2d0
    Ptr<IDirect3DVertexBuffer9>  pMaskEraseBatchVertexBuffer;       // +0x2d8

    // the vertex buffers get 5/9 of each granule, the index buffers the rest
    static UPInt vbGranularity(UPInt granularity) { return ((granularity >> 4) * 5 / 9) << 4; }
    static UPInt ibGranularity(UPInt granularity, UPInt vbg) { return ((granularity >> 4) - (vbg >> 4)) << 4; }
};

}}} // namespace Scaleform::Render::D3D9

#endif
