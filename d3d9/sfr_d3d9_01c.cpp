// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the D3D9 mesh cache TU
// (D3D9_MeshCache): vertex / index buffer sets carved into 16-byte allocator units, the D3D9 mesh cache built on
// them, and the D3D9 event-query fences it uses to keep buffers alive while the GPU reads them.
// Queue unit sfr_d3d9_01 is split along its original sources (sfr_d3d9_01c D3D9_MeshCache).
// MS2-UNIT: sfr_d3d9_01c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142738e60-0x14273c230 .text$mn


#include "ms2/scaleform/include/render/d3d9_meshcache.h"

// @0x142739110 and @0x142739120 are the inline MeshBuffer destructors; @0x142739260, @0x1427392d0, @0x142739460 and
// @0x142739750 are the deleting destructors of the vertex / index buffer templates, @0x1427394d0 and @0x142739520
// those of D3D9::MeshBuffer and Render::MeshBuffer, @0x142739340, @0x1427393a0 and @0x142739570 those of the buffer
// sets (@0x142739130 the set destructor), @0x1427395d0 the MeshCache's (@0x142739254 its MeshCacheConfig thunk) and
// @0x1427396e0 the RenderSync's.

namespace Scaleform { namespace Render { namespace D3D9 {

// ==== MeshBufferSet ==================================================================================================

// @0x1427397c0
bool MeshBufferSet::Alloc(UPInt size, MeshBuffer** buffer, UPInt* offset)
{
    UPInt addr = Allocator.Alloc((size + 15) >> 4);
    if (addr == ~UPInt(0))
        return false;
    *buffer = Buffers[addr >> 24];
    *offset = (addr & 0xFFFFFF) << 4;
    return true;
}

// @0x14273a060
void MeshBufferSet::DestroyBuffers(AllocType type)
{
    for (UPInt i = 0; i < Buffers.GetSize(); i++)
    {
        if (Buffers[i] && (type == MeshBuffer::AT_None || Buffers[i]->GetType() == type))
            DestroyBuffer(Buffers[i]);
    }
}

// ==== RenderSync =====================================================================================================

// @0x14273b070
bool RenderSync::SetDevice(IDirect3DDevice9* device)
{
    if (!device)
    {
        ReleaseOutstandingFrames();
        return true;
    }
    IDirect3DQuery9* query = 0;
    HRESULT hr = device->CreateQuery(D3DQUERYTYPE_EVENT, &query);
    if (query)
    {
        query->Release();
        pDevice = device;
    }
    return SUCCEEDED(hr);
}

// @0x142739bd0
void RenderSync::BeginFrame()
{
    if (pDevice)
    {
        if (FAILED(pDevice->CreateQuery(D3DQUERYTYPE_EVENT, &pNextEndFrameFence)))
            pNextEndFrameFence = 0;
        Render::RenderSync::BeginFrame();
    }
}

// @0x14273a580
bool RenderSync::EndFrame()
{
    if (!pDevice)
        return true;
    if (!Render::RenderSync::EndFrame())
        return false;
    if (pNextEndFrameFence)
        pNextEndFrameFence->Issue(D3DISSUE_END);
    pNextEndFrameFence->Release();
    pNextEndFrameFence = 0;
    return true;
}

// @0x14273ab20
bool RenderSync::IsPending(FenceType, UInt64 handle, const FenceFrame&)
{
    if (!handle || FenceFrames.IsEmpty())
        return false;
    if (handle == (UInt64)pNextEndFrameFence)
        return true;
    return ((IDirect3DQuery9*)handle)->GetData(0, 0, 0) == S_FALSE;
}

// @0x14273b3c0
void RenderSync::WaitFence(FenceType, UInt64 handle, const FenceFrame&)
{
    if (!handle)
        return;
    IDirect3DQuery9* query = (IDirect3DQuery9*)handle;
    // the frame's own fence has not been issued yet: issue it now and start a new one for the rest of the frame
    if (query == pNextEndFrameFence)
    {
        query->Issue(D3DISSUE_END);
        query = pNextEndFrameFence;
        if (FAILED(pDevice->CreateQuery(D3DQUERYTYPE_EVENT, &pNextEndFrameFence)))
            pNextEndFrameFence = 0;
    }
    unsigned tries = 0;
    while (query->GetData(0, 0, D3DGETDATA_FLUSH) == S_FALSE && ++tries < 10)
        Sleep(1);
}

// @0x14273b110
UInt64 RenderSync::SetFence()
{
    if (pNextEndFrameFence)
        pNextEndFrameFence->AddRef();
    return (UInt64)pNextEndFrameFence;
}

// @0x14273ae10
void RenderSync::ReleaseFence(UInt64 handle)
{
    if (handle)
        ((IDirect3DQuery9*)handle)->Release();
}

// ==== MeshCache ======================================================================================================

// MS2-FUNCTIONAL: member-init scheduling and register allocation of the inlined set constructors
// @0x142738e60
MeshCache::MeshCache(MemoryHeap* heap, const MeshCacheParams& params)
    : Render::MeshCache(heap, params), CacheList(this), BufferCreateFlags(0),
      VertexBuffers(heap, vbGranularity(params.MemGranularity)),
      IndexBuffers(heap, ibGranularity(params.MemGranularity, vbGranularity(params.MemGranularity))),
      Locked(false), VBSizeEvictedInLock(0)
{
    adjustMeshCacheParams(&Params, 0);
}

// @0x142739170
MeshCache::~MeshCache()
{
    Reset();
}

// MS2-FUNCTIONAL: block layout of the failure paths
// @0x14273a880
bool MeshCache::Initialize(IDirect3DDevice9* device, bool dynamicBuffers)
{
    adjustMeshCacheParams(&Params, device);
    if (!RSync.SetDevice(device))
        dynamicBuffers = false;
    BufferCreateFlags = dynamicBuffers;

    if (!StagingBuffer.Initialize(pHeap, Params.StagingBufferSize))
        return false;
    if (!createStaticVertexBuffers(device))
    {
        Reset();
        return false;
    }
    pDevice = device;
    if (Params.MemReserve && !allocCacheBuffers(Params.MemReserve, MeshBuffer::AT_Reserve))
    {
        Reset();
        return false;
    }
    return true;
}

// @0x14273aec0
void MeshCache::Reset()
{
    RSync.ReleaseOutstandingFrames();
    if (pDevice)
    {
        CacheList.EvictAll();
        VertexBuffers.DestroyBuffers();
        IndexBuffers.DestroyBuffers();
        ChunkBuffers.Clear();
    }
    pInstancingVertexBuffer.Clear();
    pMaskEraseBatchVertexBuffer.Clear();
    pDevice.Clear();
    StagingBuffer.Reset();
}

// MS2-FUNCTIONAL: block layout of the restore paths
// @0x14273b150
bool MeshCache::SetParams(const MeshCacheParams& params)
{
    MeshCacheParams p(params);
    adjustMeshCacheParams(&p, pDevice);

    if (pDevice)
    {
        CacheList.EvictAll();
        if (Params.StagingBufferSize != p.StagingBufferSize && !StagingBuffer.Initialize(pHeap, p.StagingBufferSize))
        {
            // keep the old ring when the new one cannot be had
            StagingBuffer.Initialize(pHeap, Params.StagingBufferSize);
            return false;
        }
        if (Params.MemReserve != p.MemReserve || Params.MemGranularity != p.MemGranularity)
        {
            destroyBuffers();
            if (p.MemReserve && !allocCacheBuffers(p.MemReserve, MeshBuffer::AT_Reserve))
            {
                if (Params.MemReserve)
                    allocCacheBuffers(Params.MemReserve, MeshBuffer::AT_Reserve);
                return false;
            }
            UPInt vbg = vbGranularity(p.MemGranularity);
            VertexBuffers.SetGranularity(vbg);
            IndexBuffers.SetGranularity(ibGranularity(p.MemGranularity, vbg));
        }
    }
    Params = p;
    return true;
}

// @0x142739c30
void MeshCache::ClearCache()
{
    CacheList.EvictAll();
    VertexBuffers.DestroyBuffers(MeshBuffer::AT_Chunk);
    IndexBuffers.DestroyBuffers(MeshBuffer::AT_Chunk);
    ChunkBuffers.Clear();
}

// MS2-FUNCTIONAL: block layout of the inlined pending-buffer and chunk-trim loops
// @0x14273a190
void MeshCache::EndFrame()
{
    GetRenderSync()->EndFrame();
    CacheList.EndFrame();
    CacheList.EvictPendingFree(IndexBuffers.GetAllocator());
    CacheList.EvictPendingFree(VertexBuffers.GetAllocator());
    destroyPendingBuffers();

    // give chunk buffers back while the cache holds a quarter more than the last frames used
    UPInt expected = CacheList.GetSlotSize(MCL_PrevFrame) +
                     Alg::Min(CacheList.GetSlotSize(MCL_LRUTail), Params.LRUTailSize);
    SPInt extra = (SPInt)(getTotalSize() - (expected + expected / 4));
    if (extra > (SPInt)Params.MemGranularity)
    {
        while (!ChunkBuffers.IsEmpty() && extra > (SPInt)Params.MemGranularity)
        {
            MeshBuffer* p = (MeshBuffer*)ChunkBuffers.GetLast();
            p->RemoveNode();
            extra -= p->GetSize();

            MeshBufferSet& mbs = (p->GetBufferType() == MeshBuffer::Buffer_Vertex)
                                     ? (MeshBufferSet&)VertexBuffers : (MeshBufferSet&)IndexBuffers;
            bool allEvicted = evictMeshesInBuffer(&CacheList.GetSlot(MCL_Uncached), MCL_ItemCount, p);
            mbs.DestroyBuffer(p, allEvicted);
            if (!allEvicted)
                PendingDestructionBuffers.PushBack(p);
        }
    }
}

// @0x14273ab80
bool MeshCache::LockBuffers()
{
    Locked              = true;
    VBSizeEvictedInLock = 0;
    if (pRQCaches)
        pRQCaches->SetCacheLocked(Cache_Mesh);
    return true;
}

// @0x14273b360
void MeshCache::UnlockBuffers()
{
    LockedBuffers.UnlockAll();
    Locked = false;
    if (pRQCaches)
        pRQCaches->ClearCacheLocked(Cache_Mesh);
}

// MS2-FUNCTIONAL: register allocation and branch layout of the fence test
// @0x14273a5e0
UPInt MeshCache::Evict(Render::MeshCacheItem* pbatch, AllocAddr* allocator, MeshBase* skipMesh)
{
    MeshCacheItem* p = (MeshCacheItem*)pbatch;

    // the GPU may still draw from it: keep the space until the fence has passed
    if (UsesDynamicMeshes() && p->GPUFence && p->GPUFence->IsPending(FenceType_Vertex))
    {
        p->Destroy(skipMesh, false);
        CacheList.PushFront(MCL_PendingFree, p);
        return 0;
    }

    UPInt vbfree = p->pVertexBuffer ? VertexBuffers.Free(p->VBAllocSize, p->pVertexBuffer, p->VBAllocOffset) : 0;
    UPInt ibfree = p->pIndexBuffer ? IndexBuffers.Free(p->IBAllocSize, p->pIndexBuffer, p->IBAllocOffset) : 0;
    UPInt result;
    if (allocator)
        result = (allocator == &VertexBuffers.GetAllocator()) ? vbfree : ibfree;
    else
        result = vbfree + ibfree;

    VBSizeEvictedInLock += (unsigned)p->VBAllocSize;
    p->Destroy(skipMesh, true);
    return result;
}

// MS2-FUNCTIONAL: stack layout of the staging prep and register allocation of the copy loop
// @0x14273abb0
bool MeshCache::PreparePrimitive(PrimitiveBatch* batch, MeshCacheItem::MeshContent& mc, bool waitForCache)
{
    Primitive* prim = batch->GetPrimitive();

    if (mc.GetMeshCount() && mc[0]->LargeMesh)
    {
        MeshResult r = GenerateMesh(mc[0], prim->GetVertexFormat(), batch->pFormat, 0, waitForCache);
        if (r.Succeded())
            batch->MeshNode.SetMeshItem(mc[0]->CacheItems[0]);
        return r.Value != MeshResult::Fail_LargeMesh_NeedCache;
    }

    unsigned vertexCount, indexCount;
    batch->CalcMeshSizes(&vertexCount, &indexCount);

    Render::MeshCacheItem* item = 0;
    UByte*     vertexDataStart;
    IndexType* indexDataStart;
    AllocResult res = AllocCacheItem(&item, &vertexDataStart, &indexDataStart, MeshCacheItem::Mesh_Regular, mc,
                                     batch->pFormat->Size * vertexCount, vertexCount, indexCount, waitForCache, 0);
    if (res != Alloc_Success)
        return res != Alloc_Fail;
    batch->MeshNode.SetMeshItem(item);

    // copy the batch's meshes out of the staging buffer, converting the vertices and offsetting the indices
    StagingBufferPrep prep(this, mc, prim->GetVertexFormat(), false);
    UByte*   staging     = StagingBuffer.GetBuffer();
    unsigned indexDelta  = 0;
    for (unsigned i = 0; i < mc.GetMeshCount(); i++)
    {
        Mesh* mesh = mc[i];
        void* convertArgs[1] = { &i };
        ConvertVertices_Buffered(*prim->GetVertexFormat(), staging + mesh->StagingBufferOffset, *batch->pFormat,
                                 vertexDataStart, mesh->VertexCount, convertArgs);
        ConvertIndices(indexDataStart, (UInt16*)(staging + mesh->StagingBufferIndexOffset), mesh->IndexCount,
                       (UInt16)indexDelta);
        vertexDataStart += batch->pFormat->Size * mesh->VertexCount;
        indexDataStart  += mesh->IndexCount;
        indexDelta      += mesh->VertexCount;
    }
    return true;
}

// MS2-FUNCTIONAL: register allocation and block layout of the clean-up path
// @0x142739840
MeshCache::AllocResult MeshCache::AllocCacheItem(Render::MeshCacheItem** item, UByte** vertexDataStart,
                                                 IndexType** indexDataStart, MeshCacheItem::MeshType meshType,
                                                 MeshCacheItem::MeshBaseContent& mc, UPInt vertexBufferSize,
                                                 unsigned vertexCount, unsigned indexCount, bool waitForCache,
                                                 const VertexFormat*)
{
    if (!AreBuffersLocked() && !LockBuffers())
        return Alloc_StateError;

    UPInt       vbOffset = 0, ibOffset = 0;
    MeshBuffer* vb = 0;
    MeshBuffer* ib = 0;
    AllocResult result = Alloc_Fail;
    UPInt       ibSize = indexCount * sizeof(IndexType);

    if (!allocBuffer(&vbOffset, &vb, VertexBuffers, vertexBufferSize, waitForCache))
    {
        // too big when no buffer could ever hold it
        if (!VertexBuffers.CheckAllocationSize(vertexBufferSize))
            result = Alloc_Fail_TooBig;
    }
    else if (!allocBuffer(&ibOffset, &ib, IndexBuffers, ibSize, waitForCache))
    {
        if (!IndexBuffers.CheckAllocationSize(ibSize))
            result = Alloc_Fail_TooBig;
    }
    else
    {
        UByte* vdata = vb->Lock(LockedBuffers.pFirst);
        UByte* idata = ib->Lock(LockedBuffers.pFirst);
        if (vdata && idata)
        {
            MeshCacheItem* p = MeshCacheItem::Create(meshType, &CacheList, mc, vb, ib, (unsigned)vbOffset,
                                                     vertexBufferSize, vertexCount, (unsigned)ibOffset, ibSize,
                                                     indexCount);
            *item = p;
            if (p)
            {
                *vertexDataStart = vdata + vbOffset;
                *indexDataStart  = (IndexType*)(idata + ibOffset);
                return Alloc_Success;
            }
            result = Alloc_StateError;
        }
    }

    // give back what was taken
    if (vb)
        VertexBuffers.GetAllocator().Free((vb->Index << 24) | (vbOffset >> 4), (vertexBufferSize + 15) >> 4);
    if (ib)
        IndexBuffers.GetAllocator().Free((ib->Index << 24) | (ibOffset >> 4), (indexCount * 2 + 15) >> 4);
    return result;
}

// @0x14273a780
void MeshCache::GetStats(Stats* stats)
{
    Stats empty;
    for (unsigned i = 0; i < MeshBuffer_StatCount; i++)
    {
        empty.UsedSize[i]  = 0;
        empty.TotalSize[i] = 0;
    }
    *stats = empty;
    stats->TotalSize[MeshBuffer_GpuMem | MeshBuffer_Vertex] = VertexBuffers.GetTotalSize();
    stats->UsedSize[MeshBuffer_GpuMem | MeshBuffer_Vertex]  = VertexBuffers.GetAllocator().GetFreeSize() << 4;
    stats->TotalSize[MeshBuffer_GpuMem | MeshBuffer_Index]  = IndexBuffers.GetTotalSize();
    stats->UsedSize[MeshBuffer_GpuMem | MeshBuffer_Index]   = IndexBuffers.GetAllocator().GetFreeSize() << 4;
}

// MS2-FUNCTIONAL: block layout of the eviction fall-backs
// @0x14273b590
bool MeshCache::allocBuffer(UPInt* offset, MeshBuffer** buffer, MeshBufferSet& mbs, UPInt size, bool waitForCache)
{
    if (mbs.Alloc(size, buffer, offset))
        return true;

    if (!CacheList.EvictPendingFree(mbs.GetAllocator()))
    {
        bool done = false;
        if (getTotalSize() + MinSupportedGranularity <= Params.MemLimit)
        {
            // below the limit: trim the LRU tail to its size, then add a chunk buffer
            if (CacheList.EvictLRUTillLimit(CacheList.GetSlot(MCL_LRUTail), mbs.GetAllocator(), size,
                                            Params.LRUTailSize))
                done = true;
            else
            {
                UPInt allocSize = mbs.GetGranularity();
                if (size > allocSize)
                    return false;
                allocSize = Alg::Min(allocSize, Params.MemLimit - VertexBuffers.GetTotalSize() -
                                                    IndexBuffers.GetTotalSize());
                if (size <= allocSize)
                {
                    MeshBuffer* p = mbs.CreateBuffer(allocSize, MeshBuffer::AT_Chunk, 0, pHeap, pDevice,
                                                     BufferCreateFlags);
                    if (p)
                    {
                        ChunkBuffers.PushBack(p);
                        done = true;
                    }
                }
            }
        }

        if (!done && !CacheList.EvictLRU(CacheList.GetSlot(MCL_LRUTail), mbs.GetAllocator(), size))
        {
            if (VBSizeEvictedInLock > Params.VBLockEvictSizeLimit)
                return false;

            // take last frame's items whose fences have passed
            MeshCacheListSet::ListSlot& prev = CacheList.GetSlot(MCL_PrevFrame);
            for (;;)
            {
                MeshCacheItem* p = (MeshCacheItem*)prev.GetFirst();
                if (prev.IsNull(p))
                    break;
                if (UsesDynamicMeshes() && p->GPUFence && p->GPUFence->IsPending(FenceType_Vertex))
                    continue;
                if (Evict(p, &mbs.GetAllocator()) >= size)
                {
                    done = true;
                    break;
                }
            }

            if (!done)
            {
                if (!waitForCache)
                    return false;
                // this frame's items, waiting on their fences
                MeshCacheListSet::ListSlot& cur = CacheList.GetSlot(MCL_ThisFrame);
                for (;;)
                {
                    MeshCacheItem* p = (MeshCacheItem*)cur.GetFirst();
                    if (cur.IsNull(p))
                        return false;
                    if (UsesDynamicMeshes() && p->GPUFence && p->GPUFence->IsPending(FenceType_Vertex))
                        p->GPUFence->WaitFence(FenceType_Vertex);
                    if (Evict(p, &mbs.GetAllocator()) >= size)
                        break;
                }
            }
        }
    }
    return mbs.Alloc(size, buffer, offset);
}

// @0x14273b870
bool MeshCache::allocCacheBuffers(UPInt size, MeshBuffer::AllocType type, unsigned arena)
{
    UPInt vbsize = vbGranularity(size);
    MeshBuffer* vb = VertexBuffers.CreateBuffer(vbsize, type, arena, pHeap, pDevice, BufferCreateFlags);
    if (!vb)
        return false;
    if (!IndexBuffers.CreateBuffer((size & ~(UPInt)15) - vbsize, type, arena, pHeap, pDevice, BufferCreateFlags))
    {
        VertexBuffers.DestroyBuffer(vb);
        return false;
    }
    return true;
}

// @0x14273bf30
void MeshCache::destroyBuffers(MeshBuffer::AllocType type)
{
    CacheList.EvictAll();
    VertexBuffers.DestroyBuffers(type);
    IndexBuffers.DestroyBuffers(type);
    ChunkBuffers.Clear();
}

// @0x14273bf90
void MeshCache::destroyPendingBuffers()
{
    // a buffer stays while an evicted item in it waits on its fence
    List<Render::MeshBuffer> stillPending;
    Render::MeshBuffer* p = PendingDestructionBuffers.GetFirst();
    while (!PendingDestructionBuffers.IsNull(p))
    {
        Render::MeshBuffer* next = p->pNext;
        p->RemoveNode();

        MeshCacheListSet::ListSlot& pendingFree = CacheList.GetSlot(MCL_PendingFree);
        Render::MeshCacheItem* it = pendingFree.GetFirst();
        for (; !pendingFree.IsNull(it); it = it->pNext)
        {
            MeshCacheItem* item = (MeshCacheItem*)it;
            if ((item->pVertexBuffer == p || item->pIndexBuffer == p) && item->GPUFence &&
                item->GPUFence->IsPending(FenceType_Vertex))
                break;
        }
        if (pendingFree.IsNull(it))
            delete p;
        else
            stillPending.PushFront(p);
        p = next;
    }
    PendingDestructionBuffers.PushListToFront(stillPending);
}

// MS2-FUNCTIONAL: register allocation of the slot loop
// @0x14273c0e0
bool MeshCache::evictMeshesInBuffer(MeshCacheListSet::ListSlot* plist, UPInt count, MeshBuffer* pbuffer)
{
    bool pending = false;
    for (unsigned i = 0; i < count; i++)
    {
        MeshCacheListSet::ListSlot& list = plist[i];
        MeshCacheItem* p = (MeshCacheItem*)list.GetFirst();
        while (!list.IsNull(p))
        {
            if (p->pVertexBuffer != pbuffer && p->pIndexBuffer != pbuffer)
            {
                p = (MeshCacheItem*)p->pNext;
                continue;
            }
            if (Evict(p) == 0)
            {
                // left pending: drop just its space in this buffer
                pending = true;
                if (p->pVertexBuffer == pbuffer)
                {
                    VertexBuffers.Free(p->VBAllocSize, p->pVertexBuffer, p->VBAllocOffset);
                    p->pVertexBuffer = 0;
                }
                if (p->pIndexBuffer == pbuffer)
                {
                    IndexBuffers.Free(p->IBAllocSize, p->pIndexBuffer, p->IBAllocOffset);
                    p->pIndexBuffer = 0;
                }
            }
            p = (MeshCacheItem*)list.GetFirst();
        }
    }
    return !pending;
}

// @0x14273b480
void MeshCache::adjustMeshCacheParams(MeshCacheParams* params, IDirect3DDevice9* device)
{
    D3DCAPS9 caps;
    if (device && SUCCEEDED(device->GetDeviceCaps(&caps)))
    {
        // instancing needs vs_3_0, and ten constants per instance
        if (caps.VertexShaderVersion < D3DVS_VERSION(3, 0))
            params->InstancingThreshold = 0;
        unsigned instances = params->MaxBatchInstances;
        if (instances > 30)
            instances = 30;
        unsigned constLimit = (caps.MaxVertexShaderConst - 1) / 10;
        params->MaxBatchInstances = (instances < constLimit) ? instances : constLimit;
    }
    if (params->VBLockEvictSizeLimit < 256 * 1024)
        params->VBLockEvictSizeLimit = 256 * 1024;
    UPInt minStaging = ((UPInt)params->MaxVerticesSizeInBatch + 2 * (UPInt)params->MaxIndicesInBatch) * 2;
    if (minStaging > params->StagingBufferSize)
        params->StagingBufferSize = minStaging;
}

// MS2-FUNCTIONAL: the exe inlines the instancing buffer (unrolled fill) before the tail call
// @0x14273bd30
bool MeshCache::createStaticVertexBuffers(IDirect3DDevice9* device)
{
    return createInstancingVertexBuffer(device) && createMaskEraseBatchVertexBuffer(device);
}

// MS2-FUNCTIONAL: the exe unrolls the index fill into 30 stores; ours is vectorised
// @0x14273b9b0
bool MeshCache::createInstancingVertexBuffer(IDirect3DDevice9* device)
{
    // the instance index of each of the 30 instances a batch may hold
    if (device->CreateVertexBuffer(30 * sizeof(UInt32), D3DUSAGE_WRITEONLY, 0, D3DPOOL_DEFAULT,
                                   &pInstancingVertexBuffer.GetRawRef(), 0) != D3D_OK)
        return false;
    UInt32* p = 0;
    if (FAILED(pInstancingVertexBuffer->Lock(0, 30 * sizeof(UInt32), (void**)&p, 0)))
    {
        pInstancingVertexBuffer.Clear();
        return false;
    }
    for (unsigned i = 0; i < 30; i++)
        p[i] = i;
    pInstancingVertexBuffer->Unlock();
    return true;
}

// MS2-FUNCTIONAL: the exe lays out the quad fill differently (unroll and scheduling)
// @0x14273bba0
bool MeshCache::createMaskEraseBatchVertexBuffer(IDirect3DDevice9* device)
{
    // 30 unit quads, two triangles each, the quad's index in the third byte
    struct EraseVertex
    {
        SInt16 x, y;
        UByte  index;
        UByte  pad[3];
    };
    if (device->CreateVertexBuffer(30 * 6 * sizeof(EraseVertex), D3DUSAGE_WRITEONLY, 0, D3DPOOL_DEFAULT,
                                   &pMaskEraseBatchVertexBuffer.GetRawRef(), 0) != D3D_OK)
        return false;
    EraseVertex* p = 0;
    if (FAILED(pMaskEraseBatchVertexBuffer->Lock(0, 30 * 6 * sizeof(EraseVertex), (void**)&p, 0)))
    {
        pMaskEraseBatchVertexBuffer.Clear();
        return false;
    }
    for (unsigned i = 0; i < 30; i++)
    {
        unsigned v = i * 6;
        p[v + 0].x = 0; p[v + 0].y = 1; p[v + 0].index = (UByte)i;
        p[v + 1].x = 0; p[v + 1].y = 0; p[v + 1].index = (UByte)i;
        p[v + 2].x = 1; p[v + 2].y = 0; p[v + 2].index = (UByte)i;
        p[v + 3].x = 0; p[v + 3].y = 1; p[v + 3].index = (UByte)i;
        p[v + 4].x = 1; p[v + 4].y = 0; p[v + 4].index = (UByte)i;
        p[v + 5].x = 1; p[v + 5].y = 1; p[v + 5].index = (UByte)i;
    }
    pMaskEraseBatchVertexBuffer->Unlock();
    return true;
}

}}} // namespace Scaleform::Render::D3D9

// MS2-FUNCTIONAL 0x142739d80: shrink-wrapping of the early return and the buffer constructor's store order
// MS2-FUNCTIONAL 0x142739ef0: shrink-wrapping of the early return and the buffer constructor's store order
// MS2-PIN: ??1MeshBufferSet@D3D9@Render@Scaleform@@UEAA@XZ 0x142739130
// MS2-PIN: ??_G?$MeshBufferImpl@UIDirect3DIndexBuffer9@@@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x142739260
// MS2-PIN: ??_G?$MeshBufferImpl@UIDirect3DVertexBuffer9@@@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x1427392d0
// MS2-PIN: ??_G?$MeshBufferSetImpl@VIndexBuffer@D3D9@Render@Scaleform@@@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x142739340
// MS2-PIN: ??_G?$MeshBufferSetImpl@VVertexBuffer@D3D9@Render@Scaleform@@@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x1427393a0
// MS2-PIN: ??_GIndexBuffer@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x142739460
// MS2-PIN: ??_GMeshCache@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x1427395d0
// MS2-PIN: ??_GRenderSync@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x1427396e0
// MS2-PIN: ??_GVertexBuffer@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x142739750
// MS2-PIN: ?CreateBuffer@?$MeshBufferSetImpl@VIndexBuffer@D3D9@Render@Scaleform@@@D3D9@Render@Scaleform@@UEAAPEAVMeshBuffer@234@_KW4AllocType@534@IPEAVMemoryHeap@4@PEAUIDirect3DDevice9@@I@Z 0x142739d80
// MS2-PIN: ?CreateBuffer@?$MeshBufferSetImpl@VVertexBuffer@D3D9@Render@Scaleform@@@D3D9@Render@Scaleform@@UEAAPEAVMeshBuffer@234@_KW4AllocType@534@IPEAVMemoryHeap@4@PEAUIDirect3DDevice9@@I@Z 0x142739ef0
// MS2-PIN: ?DoLock@?$MeshBufferImpl@UIDirect3DIndexBuffer9@@@D3D9@Render@Scaleform@@UEAA_NXZ 0x14273a110
// MS2-PIN: ?DoLock@?$MeshBufferImpl@UIDirect3DVertexBuffer9@@@D3D9@Render@Scaleform@@UEAA_NXZ 0x14273a150
// MS2-PIN: ??_7?$RefCountBase@VRenderSync@Render@Scaleform@@$01@Scaleform@@6B@ 0x14319dd80
// MS2-PIN: ??_7MeshBuffer@Render@Scaleform@@6B@ 0x14319dd88
// MS2-PIN: ??_7RenderSync@D3D9@Render@Scaleform@@6B@ 0x14319dd90
// MS2-PIN: ??_7MeshBuffer@D3D9@Render@Scaleform@@6B@ 0x14319ddd8
// MS2-PIN: ??_7MeshBufferSet@D3D9@Render@Scaleform@@6B@ 0x14319de00
// MS2-PIN: ??_7?$MeshBufferImpl@UIDirect3DVertexBuffer9@@@D3D9@Render@Scaleform@@6B@ 0x14319de10
// MS2-PIN: ??_7VertexBuffer@D3D9@Render@Scaleform@@6B@ 0x14319de38
// MS2-PIN: ??_7?$MeshBufferImpl@UIDirect3DIndexBuffer9@@@D3D9@Render@Scaleform@@6B@ 0x14319de60
// MS2-PIN: ??_7IndexBuffer@D3D9@Render@Scaleform@@6B@ 0x14319de88
// MS2-PIN: ??_7?$MeshBufferSetImpl@VVertexBuffer@D3D9@Render@Scaleform@@@D3D9@Render@Scaleform@@6B@ 0x14319deb0
// MS2-PIN: ??_7?$MeshBufferSetImpl@VIndexBuffer@D3D9@Render@Scaleform@@@D3D9@Render@Scaleform@@6B@ 0x14319dec0
// MS2-PIN: ??_7MeshCache@D3D9@Render@Scaleform@@6BCacheBase@23@@ 0x14319ded0
// MS2-PIN: ??_7MeshCache@D3D9@Render@Scaleform@@6BMeshCacheConfig@23@@ 0x14319df48
// MS2-PIN: ??_7RenderSync@Render@Scaleform@@6B@ 0x143193f08
