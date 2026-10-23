// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, preparing primitives in
// the render queue (Render_PrimitiveProcessor): converting a Primitive's virtual batches into cache-sized batches,
// filling the mesh cache for them and drawing the prepared ones through the HAL.
// Queue unit sfr_render_07 is split along its original sources (07p Render_PrimitiveProcessor).
// MS2-UNIT: sfr_render_07p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426d9510-0x1426da160 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_primitiveprocessor.h"

namespace Scaleform { namespace Render {

// ----- Primitive queue item

// @0x1426d9510
void Primitive::EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp)
{
    if (qp.GetQueueEmitFilter() != RenderQueueProcessor::QPF_All)
        return;

    PrimitivePrepareBuffer* prepareBuffer = (PrimitivePrepareBuffer*)qp.GetPrepareItemBuffer();
    PrimitiveEmitBuffer*    emitBuffer    = (PrimitiveEmitBuffer*)qp.GetEmitItemBuffer();
    emitToHAL(&item, prepareBuffer, emitBuffer, qp.GetHAL());
}

// @0x1426d95c0
Primitive::QIPrepareResult Primitive::Prepare(RenderQueueItem& item, RenderQueueProcessor& qp, bool waitForCache)
{
    if (qp.GetQueuePrepareFilter() != RenderQueueProcessor::QPF_All)
        return RenderQueueItem::QIP_Done;
    return prepare(&item, (PrimitivePrepareBuffer*)qp.GetPrepareItemBuffer(),
                   (PrimitiveEmitBuffer*)qp.GetEmitItemBuffer(), qp.GetHAL(), qp.GetMeshCache(), waitForCache);
}

// @0x1426da0a0
Primitive::QIPrepareResult Primitive::prepare(void* item, PrimitivePrepareBuffer* prepareBuffer,
                                              PrimitiveEmitBuffer* emitBuffer, HAL* hal, MeshCache* cache,
                                              bool waitForCache)
{
    if (!prepareBuffer->IsProcessing(item))
        prepareBuffer->StartPrimitive(item, this, emitBuffer, hal, cache);
    return prepareBuffer->ProcessPrimitive(waitForCache);
}

// @0x1426da020
void Primitive::emitToHAL(void* item, PrimitivePrepareBuffer* prepareBuffer, PrimitiveEmitBuffer* emitBuffer,
                          HAL* hal)
{
    PrimitiveBatch *drawStart, *drawEnd;

    if (!emitBuffer->IsEmitting(item))
    {
        drawStart = Batches.GetFirst();
        emitBuffer->StartEmitting(item, drawStart);
    }
    else
    {
        drawStart = emitBuffer->pDraw;
    }

    if (!prepareBuffer->IsProcessing(item))
    {
        drawEnd = Batches.GetLast()->pNext;
    }
    else
    {
        // drawing stops at the batch being prepared, the next call goes on from there
        drawEnd           = prepareBuffer->pPrepare;
        emitBuffer->pDraw = drawEnd;
    }

    if (ModifyIndex < GetMeshCount())
        UpdateMeshIndicies();
    hal->DrawProcessedPrimitive(this, drawStart, drawEnd);
}

// ----- PrimitivePrepareBuffer

// @0x1426d9990
void PrimitivePrepareBuffer::StartPrimitive(void* item, Primitive* p, PrimitiveEmitBuffer* emitBuffer, HAL* hal,
                                            MeshCache* cache)
{
    RQPrepareBuffer::StartProcessing(item);
    pEmitBuffer = emitBuffer;
    pHal        = hal;
    pCache      = cache;
    pPrimitive  = p;

    pSourceVFormat = p->GetVertexFormat();
    if (pSourceVFormat)
    {
        pHal->MapVertexFormat(p->GetFill()->GetType(), pSourceVFormat, &pSingleVFormat, &pBatchVFormat,
                              &pInstancedVFormat, MeshCacheItem::Mesh_Regular);
    }
    else
    {
        pSingleVFormat = pBatchVFormat = pInstancedVFormat = 0;
    }

    State      = PS_Loop;
    pConvert   = p->Batches.GetFirst();
    pPrepare   = pPrepareTail = pConvert;
    Converting = false;
}

// Walks the batches in two steps that may interleave: the converted ones up to pPrepareTail are brought into the
// cache (a batch whose meshes some item already holds just links to it) and moved to the in-flight list; the next
// virtual batch is then converted. Running out of cache space returns QIP_NeedCache, keeping the position.
// MS2-FUNCTIONAL: register allocation only: the exe keeps the 32-bit instance-adjusted mesh count in r14d across the hash lookup, ours spills it to the StrideArray and reloads it
// @0x1426d96b0
PrimitivePrepareBuffer::QIPrepareResult PrimitivePrepareBuffer::ProcessPrimitive(bool waitForCache)
{
    List<PrimitiveBatch>& batches = getPrimitive()->Batches;

    while (!batches.IsNull(pPrepare))
    {
        while (pPrepare != pPrepareTail)
        {
            if (!pPrepare->GetCacheItem())
            {
                MeshCacheItem::MeshContent mc(pPrepare);

                if (pPrepare->Type != PrimitiveBatch::DP_Failed)
                {
                    MeshCacheItem* pitem;
                    if ((State == PS_Loop) && pCache->BatchCacheItemHash.GetAlt(mc, &pitem))
                    {
                        // an item holds these meshes already
                        pPrepare->MeshNode.SetMeshItem(pitem);
                    }
                    else if (!pCache->PreparePrimitive(pPrepare, mc, waitForCache))
                    {
                        State = PS_NeedCache;
                        return RenderQueueItem::QIP_NeedCache;
                    }
                }

                State = PS_Loop;
                // once one batch is in, return quickly next time so it can be drawn
                waitForCache = false;
            }

            if (MeshCacheItem* item = pPrepare->GetCacheItem())
                item->MoveToCacheListFront(MCL_InFlight);
            pPrepare = pPrepare->pNext;
        }

        if (!Converting)
        {
            while (!batches.IsNull(pConvert) && !pConvert->IsVirtual())
            {
                pPrepareTail = pConvert;
                pConvert     = pConvert->pNext;
            }

            if (batches.IsNull(pConvert))
            {
                pPrepareTail = pConvert;
                continue;
            }

            if (!batchConvertBegin())
                continue;
        }

        batchConvertStep();
    }

    return RenderQueueItem::QIP_Done;
}

// The front of pConvert's meshes becomes one batch, as many as fit the cache limits, possibly followed by a run of
// one repeated mesh (instanced) or one mesh that must stay alone (large, failed, or no batch format). A batch
// taking all of pConvert reuses it and tries to merge with its neighbours; otherwise new batches are inserted in
// front of pConvert, which keeps the rest.
// @0x1426d9b90
void PrimitivePrepareBuffer::batchConvertStep()
{
    unsigned                  totalVerticesSize = 0, totalIndexCount = 0;
    Mesh*                     prevMesh          = 0;
    unsigned                  tailRepeatCount   = 0;
    bool                      largeTailMesh     = false;
    bool                      meshTooBigFail    = false;
    PrimitiveBatch::BatchType tailMeshType      = PrimitiveBatch::DP_Batch;
    const MeshCacheParams&    params            = pCache->GetParams();

    // lowered to 1 to give a single large mesh its own batch
    unsigned instancingThreshold = params.InstancingThreshold;
    unsigned batchVertexSize     = pBatchVFormat ? pBatchVFormat->Size : 0;
    bool     instancingSupported = pInstancedVFormat ? true : false;

    Primitive*            primitive     = pConvert->pPrimitive;
    Primitive::MeshEntry* convertMeshes = &primitive->Meshes[pConvert->MeshIndex];

    unsigned meshIndex;
    unsigned originalConvertMeshCount = pConvert->MeshCount;

    for (meshIndex = 0; meshIndex < originalConvertMeshCount; meshIndex++)
    {
        Mesh* mesh = convertMeshes[meshIndex].pMesh;

        // count the run of one mesh at the tail, it may become an instanced batch
        if (mesh != prevMesh)
        {
            if (instancingSupported && (tailRepeatCount >= instancingThreshold))
                break;
            tailRepeatCount = 1;
        }
        else
        {
            if (instancingSupported)
            {
                if (tailRepeatCount == params.MaxBatchInstances)
                    break;
                tailRepeatCount++;
                if (tailRepeatCount >= params.MaxBatchInstances)
                {
                    meshIndex++;
                    break;
                }
            }
            else
            {
                tailRepeatCount++;
            }
        }

        if (!mesh->IndexCount)
        {
            // not tessellated yet
            MeshCache::MeshResult mr =
                pCache->GenerateMesh(mesh, pSourceVFormat, pSingleVFormat, pBatchVFormat, false);

            if (!mr.Succeded() && (mr.Value != MeshCache::MeshResult::Fail_LargeMesh_NeedCache))
            {
                if (mr.Value == MeshCache::MeshResult::Fail_LargeMesh_TooBig)
                    meshTooBigFail = true;
                // a large mesh that missed this frame is tried again later, the others fail for good
                if (mr.Value != MeshCache::MeshResult::Fail_LargeMesh_ThisFrame)
                    tailMeshType = PrimitiveBatch::DP_Failed;
            }
        }

        if (mesh->LargeMesh || (tailMeshType == PrimitiveBatch::DP_Failed) || !pBatchVFormat)
        {
            // a batch of its own, after the batch so far
            instancingThreshold = 1;
            largeTailMesh       = true;
            meshIndex++;
            break;
        }

        if (((totalIndexCount + mesh->IndexCount) > params.MaxIndicesInBatch) ||
            ((totalVerticesSize + mesh->VertexCount * batchVertexSize) > params.MaxVerticesSizeInBatch) ||
            (meshIndex >= params.MaxBatchInstances))
        {
            // full; this mesh is not part of the batch, nor of the tail run
            if (mesh == prevMesh)
                tailRepeatCount--;
            break;
        }

        totalIndexCount   += mesh->IndexCount;
        totalVerticesSize += mesh->VertexCount * batchVertexSize;
        prevMesh = mesh;
    }

    // extend the tail run as far as instancing allows
    Mesh*    mesh            = convertMeshes[meshIndex - 1].pMesh;
    unsigned repeatMeshIndex = meshIndex;

    if (instancingSupported)
    {
        while ((repeatMeshIndex < pConvert->MeshCount) && (convertMeshes[repeatMeshIndex].pMesh == mesh) &&
               (tailRepeatCount < params.MaxBatchInstances))
        {
            tailRepeatCount++;
            repeatMeshIndex++;
        }
    }
    else
    {
        if (tailRepeatCount > 1)
            tailRepeatCount = 0;
    }

    // the tail gets its own batch past the threshold, or when the whole run is one mesh
    if ((tailRepeatCount >= instancingThreshold) || ((repeatMeshIndex == tailRepeatCount) && (tailRepeatCount != 1)))
        meshIndex = repeatMeshIndex;
    else
        tailRepeatCount = 0;

    unsigned frontMeshCount = meshIndex - tailRepeatCount;

    if (frontMeshCount)
    {
        PrimitiveBatch* result;

        if ((meshIndex == pConvert->MeshCount) && !tailRepeatCount)
        {
            // all of pConvert fits: reuse it, merging with the previous and next batch where possible
            pConvert->Type = PrimitiveBatch::DP_Batch;

            if (pPrepareTail != pConvert)
            {
                PrimitiveBatch* prev = pConvert->pPrev;
                attemptMergeBatches(prev, pConvert, prev, pConvert, totalVerticesSize, totalIndexCount);
            }
            if (!getPrimitive()->Batches.IsNull(pConvert->pNext))
                attemptMergeBatches(pConvert, pConvert->pNext, pConvert->pNext, pConvert, totalVerticesSize,
                                    totalIndexCount);
            // (a merge moves pConvert)
            result = pConvert;
        }
        else
        {
            PrimitiveBatch* newChunk = PrimitiveBatch::Create(pConvert->pPrimitive, PrimitiveBatch::DP_Batch,
                                                              pConvert->MeshIndex, frontMeshCount);
            result = newChunk;

            pConvert->InsertNodeBefore(newChunk);
            pConvert->MeshIndex += frontMeshCount;
            pConvert->MeshCount -= frontMeshCount;

            patchEmitDrawStartIfEq(pConvert, newChunk);
            if (pPrepare == pConvert)
                pPrepare = newChunk;
        }

        if (result->MeshCount == 1)
        {
            result->Type    = PrimitiveBatch::DP_Single;
            result->pFormat = pSingleVFormat;
        }
        else
        {
            result->pFormat = pBatchVFormat;
        }

        pPrepareTail = pConvert;
    }

    if (tailRepeatCount)
    {
        if ((tailRepeatCount > 1) && (tailMeshType != PrimitiveBatch::DP_Failed))
            tailMeshType = PrimitiveBatch::DP_Instanced;
        else if (!meshTooBigFail)
            tailMeshType = PrimitiveBatch::DP_Single;

        PrimitiveBatch* newChunk =
            PrimitiveBatch::Create(pConvert->pPrimitive, tailMeshType, pConvert->MeshIndex, tailRepeatCount);
        newChunk->LargeMesh = largeTailMesh;

        if (tailMeshType == PrimitiveBatch::DP_Instanced)
            newChunk->pFormat = pInstancedVFormat;
        else if ((tailMeshType == PrimitiveBatch::DP_Single) || (tailMeshType == PrimitiveBatch::DP_Failed))
            newChunk->pFormat = pSingleVFormat;

        pConvert->InsertNodeBefore(newChunk);
        pConvert->MeshIndex += tailRepeatCount;
        pConvert->MeshCount -= tailRepeatCount;

        patchEmitDrawStartIfEq(pConvert, newChunk);
        if (pPrepare == pConvert)
            pPrepare = newChunk;

        // nothing left of pConvert
        if (pConvert->MeshCount == 0)
        {
            pConvert->RemoveAndFree();
            pConvert = newChunk;
        }
        pPrepareTail = newChunk;
    }

    if (meshIndex >= originalConvertMeshCount)
        Converting = false;
}

// @0x1426d9a40
bool PrimitivePrepareBuffer::attemptMergeBatches(PrimitiveBatch* pfirst, PrimitiveBatch* psecond,
                                                 PrimitiveBatch* pother, PrimitiveBatch* pknown,
                                                 unsigned& knownVerticesSize, unsigned& knownIndexCount)
{
    if (pother->LargeMesh || !pBatchVFormat ||
        ((pother->Type != PrimitiveBatch::DP_Batch) && (pother->Type != PrimitiveBatch::DP_Single)))
        return false;

    const MeshCacheParams& params = pCache->GetParams();
    unsigned totalMeshCount = pfirst->MeshCount + psecond->MeshCount;
    if (totalMeshCount > params.MaxBatchInstances)
        return false;

    unsigned otherVertexCount, otherIndexCount;
    pother->CalcMeshSizes(&otherVertexCount, &otherIndexCount);

    if (((knownVerticesSize + otherVertexCount * pBatchVFormat->Size) > params.MaxVerticesSizeInBatch) ||
        ((knownIndexCount + otherIndexCount) > params.MaxIndicesInBatch))
        return false;

    pknown->MeshCount = totalMeshCount;
    pknown->MeshIndex = pfirst->MeshIndex;
    pknown->Type      = PrimitiveBatch::DP_Batch;
    pknown->ClearCacheItem();

    pother->RemoveAndFree();

    patchEmitDrawStartIfEq(pfirst, pknown);
    if (pPrepare == pfirst)
        pPrepare = pknown;
    pConvert = pknown;

    knownVerticesSize += otherVertexCount * pBatchVFormat->Size;
    knownIndexCount   += otherIndexCount;

    // the rest of the step would work on stale indices: finish converting this batch
    Converting = false;
    return false;
}

}} // namespace Scaleform::Render
