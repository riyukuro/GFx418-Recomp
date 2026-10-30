// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the mesh cache base
// (Render_MeshCache): cache items and their frame lists, the staging ring and the vertex outputs that write the
// tessellated meshes either into the staging ring or straight into a cache item.
// Queue unit sfr_render_07 is split along its original sources (07g Render_MeshCache).
// MS2-UNIT: sfr_render_07g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426da160-0x1426dc560 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_meshcache.h"
#include "ms2/scaleform/include/render/render_primitive.h"

namespace Scaleform { namespace Render {

// Writes a mesh into the staging ring, or, for a mesh too large to batch, straight into its own cache item
// (vftable 0x143193c80, 0x58 bytes).
class MeshVertexOutput : public VertexOutput
{
public:
    MeshVertexOutput(Mesh* mesh, MeshCache* cache, const VertexFormat* sourceFormat,
                     const VertexFormat* singleFormat, const VertexFormat* batchFormat, bool waitForCache)
        : pCache(cache), WaitForCache(waitForCache), pMesh(mesh), pSourceFormat(sourceFormat),
          pSingleFormat(singleFormat), pBatchFormat(batchFormat), Result(MeshCache::MeshResult::Fail_General),
          pVertexDataStart(0), pIndexDataStart(0)
    {
    }

    virtual bool BeginOutput(const Fill* fills, unsigned fillCount, const Matrix2F& vertexMatrix);
    virtual void EndOutput()
    {
        if (Result.IsLargeMesh())
            pCache->PostUpdateMesh(BatchData);
    }
    virtual void SetVertices(unsigned fillIndex, unsigned vertexOffset, void* vertices, unsigned vertexCount);
    virtual void SetIndices(unsigned fillIndex, unsigned indexOffset, UInt16* indices, unsigned indexCount);

    MeshCache*              pCache;             // +0x08
    bool                    WaitForCache;       // +0x10
    Mesh*                   pMesh;              // +0x18
    const VertexFormat*     pSourceFormat;      // +0x20
    const VertexFormat*     pSingleFormat;      // +0x28, the format of a large mesh's own item
    const VertexFormat*     pBatchFormat;       // +0x30
    MeshCache::MeshResult   Result;             // +0x38
    UByte*                  pVertexDataStart;   // +0x40
    IndexType*              pIndexDataStart;    // +0x48
    MeshCacheItem*          BatchData;          // +0x50, the large mesh's item
};

// Writes a complex mesh into its cache item, every fill converted to the format of its fill record (vftable
// 0x143193ca8, 0x48 bytes).
class ComplexMeshVertexOutput : public VertexOutput
{
public:
    ComplexMeshVertexOutput(ComplexMesh* mesh, MeshCache* cache, HAL* hal, bool waitForCache)
        : pMesh(mesh), pCache(cache), pHAL(hal), WaitForCache(waitForCache), AllocState(MeshCache::Alloc_StateError)
    {
    }

    virtual bool BeginOutput(const Fill* fills, unsigned fillCount, const Matrix2F& vertexMatrix);
    virtual void EndOutput() { pCache->PostUpdateMesh(pMesh->pCacheMeshItem); }
    virtual void SetVertices(unsigned fillIndex, unsigned vertexOffset, void* vertices, unsigned vertexCount);
    virtual void SetIndices(unsigned fillIndex, unsigned indexOffset, UInt16* indices, unsigned indexCount)
    {
        if (AllocState == MeshCache::Alloc_Success)
        {
            ComplexMesh::FillRecord& fr = pMesh->FillRecords[fillIndex];
            memcpy(pIndexDataStart + fr.IndexOffset + indexOffset, indices, indexCount * sizeof(UInt16));
        }
    }

    ComplexMesh*            pMesh;              // +0x08
    MeshCache*              pCache;             // +0x10
    HAL*                    pHAL;               // +0x18
    bool                    WaitForCache;       // +0x20
    const Fill*             pFills;             // +0x28
    MeshCache::AllocResult  AllocState;         // +0x30
    UByte*                  pVertexDataStart;   // +0x38
    IndexType*              pIndexDataStart;    // +0x40
};

// @0x1426da3e0
MeshCacheItem::MeshBaseContent::MeshBaseContent(MeshBase** meshes, unsigned meshCount)
    : Meshes(meshes, meshCount)
{
    UPInt key = 0;
    for (UPInt i = 0; i < meshCount; i++)
        key ^= ((UPInt)meshes[i]) >> 5;
    HashKey = (unsigned)key;
}

// @0x1426da4a0
MeshCache::MeshCache(MemoryHeap* heap, const MeshCacheParams& params)
    : pHeap(heap), pRQCaches(0), Params(params), Thrashing(0)
{
}

// @0x1426da580
MeshCache::StagingBufferPrep::StagingBufferPrep(MeshCache* cache, MeshCacheItem::MeshContent& mc,
                                                const VertexFormat* format, bool canCopyData,
                                                MeshCacheItem* skipItem)
    : pCache(cache), MC(mc)
{
    MeshStagingBuffer& sb        = cache->StagingBuffer;
    unsigned           meshCount = mc.GetMeshCount();
    unsigned           i;

    for (i = 0; i < meshCount; i++)
    {
        Mesh* mesh = MC[i];
        if (sb.IsCached(mesh))
        {
            sb.PinMesh(mesh);
            PinnedFlagArray[i] = true;
        }
        else
            PinnedFlagArray[i] = false;
    }

    if (canCopyData)
    {
        // meshes some other item holds are copied from there
        for (i = 0; i < meshCount; i++)
        {
            Mesh* mesh = MC[i];
            if (PinnedFlagArray[i])
                continue;
            if (mesh->CacheItems.GetSize() == 0 ||
                (mesh->CacheItems.GetSize() == 1 && mesh->CacheItems[0] == skipItem))
            {
                if (!sb.IsCached(mesh))
                    pCache->GenerateMesh(mesh, format, 0, 0, false);
                sb.PinMesh(mesh);
            }
        }
    }
    else
    {
        for (i = 0; i < meshCount; i++)
        {
            if (!PinnedFlagArray[i])
            {
                Mesh* mesh = MC[i];
                if (!sb.IsCached(mesh))
                    pCache->GenerateMesh(mesh, format, 0, 0, false);
                sb.PinMesh(mesh);
            }
        }
    }
}

// @0x1426da810
MeshCache::~MeshCache()
{
}

// @0x1426da8e0
MeshCache::StagingBufferPrep::~StagingBufferPrep()
{
    MeshStagingBuffer& sb = pCache->StagingBuffer;
    for (unsigned i = 0; i < MC.GetMeshCount(); i++)
    {
        if (sb.IsCached(MC[i]))
            sb.UnpinMesh(MC[i]);
    }
}

// @0x1426daae0
bool MeshStagingBuffer::AllocateBufferSpace(UPInt* offset, UPInt size)
{
    if (size > PinSizeLimit)
        return false;

    while (!MeshList.IsEmpty())
    {
        MeshStagingNode* head    = MeshList.GetFirst();
        MeshStagingNode* tail    = MeshList.GetLast();
        UPInt            headEnd = head->StagingBufferOffset + head->StagingBufferSize;
        UPInt            tailOff = tail->StagingBufferOffset;
        UPInt            space;

        if (headEnd <= tailOff)
            space = tailOff - headEnd;
        else
        {
            // the free part wraps: the end of the ring first, then its start
            if (BufferSize - headEnd >= size)
            {
                *offset = headEnd;
                return true;
            }
            space = tailOff;
        }
        if (space >= size)
        {
            *offset = tailOff - space;
            return true;
        }

        // the oldest mesh goes, a pinned one slides down to the head instead
        tail->RemoveNode();
        if (tail->PinCount)
        {
            if (space)
            {
                memmove(pBuffer + tail->StagingBufferOffset - space, pBuffer + tail->StagingBufferOffset,
                        tail->StagingBufferSize);
                tail->StagingBufferIndexOffset -= space;
                tail->StagingBufferOffset      -= space;
            }
            MeshList.PushFront(tail);
        }
        else
            tail->OnStagingNodeEvict();
    }
    *offset = 0;
    return true;
}

// @0x1426dac30
bool MeshStagingBuffer::AllocateMesh(Mesh* mesh, UPInt vertexCount, UPInt vertexSize, UPInt indexCount)
{
    UPInt vbSize = vertexCount * vertexSize;
    UPInt size   = (vbSize + indexCount * sizeof(IndexType) + 15) & ~UPInt(15);
    UPInt offset;

    if (!AllocateBufferSpace(&offset, size))
        return false;

    mesh->StagingBufferIndexOffset = offset + vbSize;
    mesh->VertexCount              = (unsigned)vertexCount;
    mesh->IndexCount               = (unsigned)indexCount;
    mesh->StagingBufferOffset      = offset;
    mesh->StagingBufferSize        = size;
    MeshList.PushFront(mesh);
    return true;
}

// @0x1426dade0
bool ComplexMeshVertexOutput::BeginOutput(const Fill* fills, unsigned fillCount, const Matrix2F& vertexMatrix)
{
    UPInt    vbSize;
    unsigned vertexCount, indexCount;

    if (!pMesh->InitFillRecords(fills, fillCount, vertexMatrix, pHAL, &vbSize, &vertexCount, &indexCount))
    {
        pMesh->AllocTooBig = true;
        return false;
    }

    MeshCacheItem*                 item;
    MeshCacheItem::MeshBaseContent mc((MeshBase**)&pMesh, 1);
    AllocState = pCache->AllocCacheItem(&item, &pVertexDataStart, &pIndexDataStart, MeshCacheItem::Mesh_Complex,
                                        mc, vbSize, vertexCount, indexCount, WaitForCache, 0);
    pFills = fills;
    if (AllocState == MeshCache::Alloc_Fail_TooBig)
        pMesh->AllocTooBig = true;
    return AllocState == MeshCache::Alloc_Success;
}

// MS2-FUNCTIONAL: register allocation of the inlined AllocateMesh (vertex/index count registers, pMesh and vbSize
// spill slots swapped); same instructions otherwise
// @0x1426daee0
bool MeshVertexOutput::BeginOutput(const Fill* fills, unsigned fillCount, const Matrix2F& vertexMatrix)
{
    SF_UNUSED(fillCount);

    if (pMesh->LargeMesh || (!pBatchFormat && pSingleFormat) ||
        (pBatchFormat && fills->VertexCount * pBatchFormat->Size > pCache->Params.NoBatchVerticesSizeThreshold))
    {
        // too large to batch: the mesh gets an item of its own
        MeshCacheItem::MeshBaseContent mc((MeshBase**)&pMesh, 1);
        unsigned vbSize    = pSingleFormat->Size * fills->VertexCount;
        pMesh->VertexCount = fills->VertexCount;
        pMesh->IndexCount  = fills->IndexCount;
        pMesh->LargeMesh   = true;

        MeshCache::AllocResult ar =
            pCache->AllocCacheItem(&BatchData, &pVertexDataStart, &pIndexDataStart, MeshCacheItem::Mesh_Regular,
                                   mc, vbSize, fills->VertexCount, fills->IndexCount, WaitForCache, pSingleFormat);
        if (ar == MeshCache::Alloc_Success)
        {
            Result = MeshCache::MeshResult::Success_LargeMesh;
            pCache->MoveToCacheListFront(MCL_ThisFrame, BatchData);
        }
        else if (ar == MeshCache::Alloc_Fail)
            Result = MeshCache::MeshResult::Fail_LargeMesh_NeedCache;
        else if (ar == MeshCache::Alloc_Fail_TooBig)
            Result = MeshCache::MeshResult::Fail_LargeMesh_TooBig;
        else if (ar == MeshCache::Alloc_Fail_ThisFrame)
            Result = MeshCache::MeshResult::Fail_LargeMesh_ThisFrame;
    }
    else
    {
        if (pCache->StagingBuffer.AllocateMesh(pMesh, fills->VertexCount, pSourceFormat->Size, fills->IndexCount))
            Result = MeshCache::MeshResult::Success_Staging;
        else
            Result = MeshCache::MeshResult::Fail_Staging_NoBuffer;
    }

    pMesh->VertexMatrix = vertexMatrix;
    return Result.Succeded();
}

// @0x1426db220
MeshCacheItem* MeshCacheItem::Create(MeshType type, MeshCacheListSet* pcacheList, UPInt classSize,
                                     MeshBaseContent& content, UPInt allocSize, unsigned vertexCount,
                                     unsigned indexCount)
{
    MeshCache* cache     = pcacheList->GetCache();
    UPInt      itemSize  = (classSize + 7) & ~UPInt(7);
    unsigned   meshCount = content.GetMeshCount();

    MeshCacheItem* p = (MeshCacheItem*)SF_HEAP_ALLOC(cache->pHeap, itemSize + meshCount * sizeof(MeshBase*),
                                                     StatRender_MeshCacheMgmt_Mem);
    if (!p)
        return 0;

    p->Type       = type;
    p->pCacheList = pcacheList;
    p->HashKey    = content.HashKey;
    p->MeshCount  = meshCount;
    p->pMeshes    = (MeshBase**)((UByte*)p + itemSize);
    for (unsigned i = 0; i < meshCount; i++)
        p->pMeshes[i] = content[i];
    p->PrimitiveBatches.Clear();
    p->AllocSize   = allocSize;
    p->VertexCount = vertexCount;
    p->IndexCount  = indexCount;
    p->GPUFence.NullWithoutRelease();

    if (type == Mesh_Regular)
    {
        for (unsigned i = 0; i < meshCount; i++)
            ((Mesh*)content[i])->CacheItems.Add_NoDuplicate(p);
        cache->BatchCacheItemHash.Add(p);
    }
    else
        ((ComplexMesh*)p->pMeshes[0])->pCacheMeshItem = p;

    pcacheList->PushFront(MCL_Uncached, p);
    return p;
}

// @0x1426db4b0
void MeshCacheItem::Destroy(MeshBase* skipMesh, bool freeMemory)
{
    pCacheList->RemoveNode(this);

    if ((Type == Mesh_Regular) || (Type == Mesh_Complex))
    {
        for (MeshCacheItemUseNode* n = PrimitiveBatches.GetFirst(); !PrimitiveBatches.IsNull(n); n = n->pNext)
            n->pMeshItem = 0;
        PrimitiveBatches.Clear();
    }

    if (Type == Mesh_Regular)
    {
        GetCache()->BatchCacheItemHash.Remove(this);

        // the meshes may go away when they lose the item
        unsigned i;
        for (i = 0; i < MeshCount; i++)
            if (pMeshes[i] != skipMesh)
                pMeshes[i]->AddRef();
        for (i = 0; i < MeshCount; i++)
            if (pMeshes[i] != skipMesh)
                ((Mesh*)pMeshes[i])->RemoveMeshCacheItem(this);
        for (i = 0; i < MeshCount; i++)
            if (pMeshes[i] != skipMesh)
                pMeshes[i]->Release();
    }
    else if (Type == Mesh_Complex)
    {
        if (pMeshes[0] != skipMesh)
            ((ComplexMesh*)pMeshes[0])->RemoveMeshCacheItem(this);
    }

    Type = Mesh_Destroyed;
    if (freeMemory)
    {
        GPUFence = 0;
        SF_FREE(this);
    }
}

// @0x1426db7d0
void MeshCacheListSet::EndFrame()
{
    PushListToFront(MCL_LRUTail, MCL_PrevFrame);
    PushListToFront(MCL_PrevFrame, MCL_ThisFrame);
}

// @0x1426db8d0
void MeshCacheListSet::EvictAll()
{
    for (unsigned i = 0; i < MCL_ItemCount; i++)
    {
        if (i == MCL_PendingFree)
            continue;
        while (!Slots[i].IsEmpty())
            pCache->Evict(Slots[i].GetFirst());
    }

    // the pending ones wait for the GPU first
    while (!Slots[MCL_PendingFree].IsEmpty())
    {
        MeshCacheItem* p = Slots[MCL_PendingFree].GetFirst();
        while (!Slots[MCL_PendingFree].IsNull(p))
        {
            if (p->GPUFence && p->GPUFence->IsPending(FenceType_Vertex))
                p->GPUFence->WaitFence(FenceType_Vertex);
            pCache->Evict(p);
            p = Slots[MCL_PendingFree].GetFirst();
        }
    }
}

// @0x1426db9c0
bool MeshCacheListSet::EvictLRU(ListSlot& list, AllocAddr& a, UPInt size)
{
    MeshCacheItem* p = list.GetLast();
    while (!list.IsNull(p))
    {
        pCache->Thrashing++;
        if (pCache->Evict(p, &a) >= size)
            return true;
        p = list.GetLast();
    }
    return false;
}

// @0x1426dba40
bool MeshCacheListSet::EvictLRUTillLimit(ListSlot& list, AllocAddr& a, UPInt size, UPInt limit)
{
    MeshCacheItem* p = list.GetLast();
    while (!list.IsNull(p) && list.Size > limit)
    {
        pCache->Thrashing++;
        if (pCache->Evict(p, &a) >= size)
            return true;
        p = list.GetLast();
    }
    return false;
}

// @0x1426dbac0
bool MeshCacheListSet::EvictPendingFree(AllocAddr& a)
{
    ListSlot&      pending = Slots[MCL_PendingFree];
    MeshCacheItem* p       = pending.GetFirst();
    while (!pending.IsNull(p))
    {
        MeshCacheItem* next = p->pNext;
        pCache->Evict(p, &a);
        p = next;
    }
    return false;
}

// @0x1426dbb30
MeshCacheItem* MeshCacheItem::FindMeshSourceBatch(Mesh* mesh, unsigned* prevVertexCount, unsigned* prevIndexCount,
                                                  MeshCacheItem* skipItem)
{
    MeshCacheItem* src   = 0;
    MeshCacheItem* const* items = mesh->CacheItems.GetBuffer();
    for (unsigned i = 0; i < mesh->CacheItems.GetSize(); i++)
    {
        MeshCacheItem* item = items[i];
        if (item && item != skipItem)
        {
            src = item;
            break;
        }
    }

    *prevVertexCount = 0;
    *prevIndexCount  = 0;
    for (unsigned i = 0; i < src->MeshCount; i++)
    {
        Mesh* m = (Mesh*)src->pMeshes[i];
        if (mesh == m)
            break;
        *prevVertexCount += m->VertexCount;
        *prevIndexCount  += m->IndexCount;
    }
    return src;
}

// @0x1426dbbe0
MeshCache::MeshResult MeshCache::GenerateMesh(Mesh* mesh, const VertexFormat* sourceFormat,
                                              const VertexFormat* singleFormat, const VertexFormat* batchFormat,
                                              bool waitForCache)
{
    MeshVertexOutput out(mesh, this, sourceFormat, singleFormat, batchFormat, waitForCache);
    mesh->GetProvider()->GetData(mesh, &out, mesh->GetMeshGenFlags());
    return out.Result;
}

MeshUseStatus MeshCache::GetItemUseStatus(const MeshCacheItem* item)
{
    switch (item->GetListType())
    {
    case MCL_InFlight:  return MUS_InUse;
    case MCL_ThisFrame: return MUS_ThisFrame;
    case MCL_PrevFrame: return MUS_PrevFrame;
    case MCL_LRUTail:   return MUS_LRUTail;
    default:            return MUS_Uncached;
    }
}

// @0x1426dbce0
MeshUseStatus MeshCacheItem::GetUseStatus() const
{
    return GetCache()->GetItemUseStatus(this);
}

// @0x1426dbd00
bool MeshStagingBuffer::Initialize(MemoryHeap* heap, UPInt size)
{
    if (pBuffer && size != BufferSize)
        Reset();
    pBuffer = (UByte*)SF_HEAP_ALLOC(heap, size, StatRender_MeshStaging_Mem);
    if (!pBuffer)
        return false;
    BufferSize      = size;
    PinSizeLimit    = size >> 1;
    TotalPinnedSize = 0;
    return true;
}

// @0x1426dbd90
void MeshCache::MoveToCacheListFront(MeshCacheListType list, MeshCacheItem* p)
{
    if (p)
        p->MoveToCacheListFront(list);
}

// @0x1426dbe00
void MeshCacheItem::NotifyMeshRelease(MeshBase* mesh)
{
    GetCache()->Evict(this, 0, mesh);
}

// @0x1426dbe30
bool MeshCache::PrepareComplexMesh(ComplexMesh* mesh, bool waitForCache)
{
    if (!mesh || mesh->AllocTooBig)
        return true;

    if (!mesh->pCacheMeshItem)
    {
        ComplexMeshVertexOutput out(mesh, this, mesh->pFillManager->GetHAL(), waitForCache);
        mesh->GetProvider()->GetData(mesh, &out, mesh->GetMeshGenFlags());
        if (out.AllocState == Alloc_Fail)
            return false;
        if (out.AllocState != Alloc_Success)
            return true;
    }
    if (mesh->pCacheMeshItem)
        MoveToCacheListFront(MCL_InFlight, mesh->pCacheMeshItem);
    return true;
}

// @0x1426dbef0
void MeshStagingBuffer::Reset()
{
    if (!pBuffer)
        return;

    while (!MeshList.IsEmpty())
    {
        MeshStagingNode* p = MeshList.GetFirst();
        p->StagingBufferOffset      = 0;
        p->StagingBufferIndexOffset = 0;
        p->RemoveNode();
        p->OnStagingNodeEvict();
    }
    SF_FREE(pBuffer);
    pBuffer         = 0;
    BufferSize      = 0;
    TotalPinnedSize = 0;
}

// @0x1426dbfd0
void MeshVertexOutput::SetIndices(unsigned fillIndex, unsigned indexOffset, UInt16* indices, unsigned indexCount)
{
    if (fillIndex != 0 || !Result.Succeded())
        return;

    if (!Result.IsLargeMesh())
        memcpy(pCache->StagingBuffer.GetBuffer() + pMesh->StagingBufferIndexOffset + indexOffset * sizeof(UInt16),
               indices, indexCount * sizeof(UInt16));
    else
        pCache->SetLargeMeshIndices(BatchData, pSourceFormat, indexOffset, indices, indexCount, pSingleFormat,
                                    (UByte*)pIndexDataStart);
}

// @0x1426dc050
bool MeshCache::SetLargeMeshIndices(MeshCacheItem*, const VertexFormat*, UPInt indexOffset, const UInt16* indices,
                                    unsigned indexCount, const VertexFormat*, UByte* destStart)
{
    memcpy(destStart + indexOffset * sizeof(UInt16), indices, indexCount * sizeof(UInt16));
    return true;
}

// @0x1426dc080
bool MeshCache::SetLargeMeshVertices(MeshCacheItem*, const VertexFormat* sourceFormat, UPInt vertexOffset,
                                     UByte* vertices, unsigned vertexCount, const VertexFormat* destFormat,
                                     UByte* destStart)
{
    ConvertVertices_Buffered(*sourceFormat, vertices, *destFormat, destStart + vertexOffset * destFormat->Size,
                             vertexCount);
    return true;
}

// @0x1426dc0c0
void MeshCacheItemUseNode::SetMeshItem(MeshCacheItem* p)
{
    if (pMeshItem)
        RemoveNode();
    pMeshItem = p;
    if (p)
        p->PrimitiveBatches.PushFront(this);
}

// @0x1426dc110
void MeshCache::SetRQCacheInterface(RQCacheInterface* rqCaches)
{
    if (pRQCaches == rqCaches)
        return;
    if (pRQCaches)
    {
        pRQCaches->ClearCacheLocked(Cache_Mesh);
        pRQCaches->SetCache(Cache_Mesh, 0);
    }
    pRQCaches = rqCaches;
    if (rqCaches)
    {
        rqCaches->SetCache(Cache_Mesh, this);
        if (AreBuffersLocked())
            pRQCaches->SetCacheLocked(Cache_Mesh);
    }
}

// @0x1426dc160
void ComplexMeshVertexOutput::SetVertices(unsigned fillIndex, unsigned vertexOffset, void* vertices,
                                          unsigned vertexCount)
{
    if (AllocState != MeshCache::Alloc_Success)
        return;
    ComplexMesh::FillRecord& fr = pMesh->FillRecords[fillIndex];
    ConvertVertices_Buffered(*pFills[fillIndex].pFormat, vertices, *fr.pFormats[0],
                             pVertexDataStart + fr.VertexByteOffset + vertexOffset * fr.pFormats[0]->Size,
                             vertexCount);
}

// @0x1426dc1c0
void MeshVertexOutput::SetVertices(unsigned fillIndex, unsigned vertexOffset, void* vertices, unsigned vertexCount)
{
    if (fillIndex != 0 || !Result.Succeded())
        return;

    if (!Result.IsLargeMesh())
        memcpy(pCache->StagingBuffer.GetBuffer() + pMesh->StagingBufferOffset + vertexOffset * pSourceFormat->Size,
               vertices, vertexCount * pSourceFormat->Size);
    else
        pCache->SetLargeMeshVertices(BatchData, pSourceFormat, vertexOffset, (UByte*)vertices, vertexCount,
                                     pSingleFormat, pVertexDataStart);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7CacheBase@Render@Scaleform@@6B@ 0x143192d88
// MS2-PIN: ??_7MeshCacheConfig@Render@Scaleform@@6B@ 0x143193bc8
// MS2-PIN: ??_7MeshCache@Render@Scaleform@@6BCacheBase@12@@ 0x143193be8
// MS2-PIN: ??_7MeshCache@Render@Scaleform@@6BMeshCacheConfig@12@@ 0x143193c60
// MS2-PIN: ??_7VertexOutput@Render@Scaleform@@6B@ 0x143193ba0
// MS2-PIN: ??_7MeshVertexOutput@Render@Scaleform@@6B@ 0x143193c80
// MS2-PIN: ??_7ComplexMeshVertexOutput@Render@Scaleform@@6B@ 0x143193ca8
