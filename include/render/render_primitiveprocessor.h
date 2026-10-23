// Recovered Scaleform 4.1.18 Render: preparing a Primitive's batches in the render queue (Render_PrimitiveProcessor,
// sfr_render_07p). The prepare buffer first converts the virtual batches into fixed batches sized by the mesh cache
// limits (merging with a neighbour where it fits, splitting repeated meshes into instanced batches), then has the
// cache fill every batch; the emit buffer remembers where drawing stopped when the cache ran full mid-primitive.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Both buffers live in the RenderQueueProcessor's scratch space (+0x48 / +0x108); layout checked against
// StartPrimitive 0x1426d9990 and Primitive::EmitToHAL 0x1426d9510.
#ifndef MS2_SF_RENDER_PRIMITIVEPROCESSOR_H
#define MS2_SF_RENDER_PRIMITIVEPROCESSOR_H

#include "ms2/scaleform/include/render/render_queue.h"

namespace Scaleform { namespace Render {

class PrimitiveEmitBuffer;

class PrimitivePrepareBuffer : public RQPrepareBuffer
{
    friend class Primitive;
public:
    typedef RenderQueueItem::QIPrepareResult QIPrepareResult;

    // takes over the buffer for p's batches
    void            StartPrimitive(void* item, Primitive* p, PrimitiveEmitBuffer* emitBuffer, HAL* hal,
                                   MeshCache* cache);   // 0x1426d9990
    // converts and caches batches until all are ready (QIP_Done) or the cache is full (QIP_NeedCache); called
    // again for the same primitive after the batches so far were drawn
    QIPrepareResult ProcessPrimitive(bool waitForCache);   // 0x1426d96b0

private:
    enum ProcessorState
    {
        PS_Loop,
        PS_NeedCache
    };

    PrimitiveEmitBuffer* pEmitBuffer;         // +0x08
    HAL*                 pHal;                // +0x10
    MeshCache*           pCache;              // +0x18
    Primitive*           pPrimitive;          // +0x20
    const VertexFormat*  pSourceVFormat;      // +0x28, the format the meshes are generated in
    const VertexFormat*  pSingleVFormat;      // +0x30, the formats they are drawn with
    const VertexFormat*  pBatchVFormat;       // +0x38
    const VertexFormat*  pInstancedVFormat;   // +0x40
    ProcessorState       State;               // +0x48
    PrimitiveBatch*      pPrepare;            // +0x50, the next batch to cache
    PrimitiveBatch*      pPrepareTail;        // +0x58, the end of the converted batches
    PrimitiveBatch*      pConvert;            // +0x60, the next batch to convert
    bool                 Converting;          // +0x68, pConvert is converted in part

    PrimitivePrepareBuffer() { }

    Primitive* getPrimitive() const { return pPrimitive; }

    bool batchConvertBegin()
    {
        Primitive* p = pConvert->pPrimitive;
        if (p->ModifyIndex < p->GetMeshCount())
            p->UpdateMeshIndicies();
        if (pConvert->MeshCount == 0)
            return false;
        Converting = true;
        return true;
    }
    // converts the next run of pConvert into one or two fixed batches
    void batchConvertStep();   // 0x1426d9b90
    // merges pother into pknown when the two batches [pfirst, psecond] fit in one; returns false either way
    bool attemptMergeBatches(PrimitiveBatch* pfirst, PrimitiveBatch* psecond, PrimitiveBatch* pother,
                             PrimitiveBatch* pknown, unsigned& knownVerticesSize,
                             unsigned& knownIndexCount);   // 0x1426d9a40
    inline void patchEmitDrawStartIfEq(PrimitiveBatch* check, PrimitiveBatch* drawStart);
};

class PrimitiveEmitBuffer : public RQEmitBuffer
{
    friend class Primitive;
    friend class PrimitivePrepareBuffer;

    // the first batch of the item not drawn yet
    PrimitiveBatch* pDraw;   // +0x08

    PrimitiveEmitBuffer() { }

public:
    void StartEmitting(void* item, PrimitiveBatch* drawStart)
    {
        RQEmitBuffer::StartEmitting(item);
        pDraw = drawStart;
    }
};

inline void PrimitivePrepareBuffer::patchEmitDrawStartIfEq(PrimitiveBatch* check, PrimitiveBatch* drawStart)
{
    if (pEmitBuffer->IsEmitting(GetItem()) && pEmitBuffer->pDraw == check)
        pEmitBuffer->pDraw = drawStart;
}

}} // namespace Scaleform::Render

#endif
