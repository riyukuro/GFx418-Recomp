// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the render queue
// (Render_Queue): the ring of queued render items and the processor that prepares them into the caches and emits
// them to the HAL.
// Queue unit sfr_render_07 is split along its original sources (07j Render_Queue).
// MS2-UNIT: sfr_render_07j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426dffe0-0x1426e0080 .text$mn
// MS2-RANGE: 0x1426e0090-0x1426e0560 .text$mn
// (0x1426e0080 between them is the out-of-line RefCountImplCore::operator= COMDAT, SF_MemItem)
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_queue.h"

namespace Scaleform { namespace Render {

// ----- RenderQueue

// @0x1426dfff0
RenderQueue::RenderQueue()
    : QueueSize(0), pQueue(0), QueueHead(0), QueueTail(0), HeadReserved(false)
{
}

// @0x1426e0050
RenderQueue::~RenderQueue()
{
    Shutdown();
}

// @0x1426e0220
bool RenderQueue::Initialize(UPInt itemCount)
{
    // one slot always stays empty, so fewer than two can hold nothing
    if (itemCount < 2)
        return false;

    pQueue    = (RenderQueueItem*)SF_HEAP_AUTO_ALLOC(this, itemCount * sizeof(RenderQueueItem));
    QueueSize = (unsigned)itemCount;
    if (!pQueue)
        return false;

    for (unsigned i = 0; i < QueueSize; i++)
        new (pQueue + i) RenderQueueItem();
    return true;
}

// @0x1426e0420
void RenderQueue::Shutdown()
{
    if (pQueue)
    {
        SF_FREE(pQueue);
        pQueue = 0;
    }
}

// @0x1426e03e0
RenderQueueItem* RenderQueue::ReserveHead()
{
    // one slot stays empty so that a full ring differs from an empty one
    if (QueueHead <= QueueTail)
    {
        if (QueueTail - QueueHead == 1)
            return 0;
    }
    else if (QueueSize + QueueTail == QueueHead + 1)
    {
        return 0;
    }
    HeadReserved = true;
    return pQueue + QueueHead;
}

// @0x1426e0090
void RenderQueue::AdvanceTail()
{
    pQueue[QueueTail].Clear();
    if (++QueueTail == QueueSize)
        QueueTail = 0;
}

// ----- RQCacheInterface

// @0x1426e0450
void RQCacheInterface::UnlockCaches()
{
    for (unsigned i = 0; i < Cache_Count; i++)
    {
        if ((LockFlags & (1u << i)) && pCaches[i])
            pCaches[i]->UnlockBuffers();
    }
}

// ----- RenderQueueProcessor

// @0x1426e0010
RenderQueueProcessor::RenderQueueProcessor(RenderQueue& queue, HAL* hal)
    : pHAL(hal), Queue(queue), QueueMode(MeshCache::QM_WaitForFences), QueuePrepareFilter(QPF_All), QueueEmitFilter(QPF_All)
{
    PrepareItemBuffer.ClearItem();
    EmitItemBuffer.ClearItem();
}

// @0x1426dffe0
RenderQueueProcessor::~RenderQueueProcessor()
{
}

// @0x1426e00c0
void RenderQueueProcessor::BeginFrame()
{
    MeshCache& meshCache = pHAL->GetMeshCache();
    QueueMode = meshCache.GetQueueMode();
    meshCache.SetRQCacheInterface(&Caches);
    CurrentItem = Queue.GetTail();
}

// @0x1426e0110
void RenderQueueProcessor::Flush()
{
    ProcessQueue(QPM_All);
    resetBufferItems();
}

// @0x1426e02b0
void RenderQueueProcessor::ProcessQueue(QueueProcessMode mode)
{
    bool waitForCache = false;
    if (mode != QPM_Any)
    {
        if (QueueMode == MeshCache::QM_WaitForFences)
            waitForCache = true;
        else if (Caches.AnyCacheLocked())
            Caches.UnlockCaches();
    }

    while (CurrentItem != Queue.GetHead())
    {
        RenderQueueItem* item = CurrentItem.GetItem();
        RenderQueueItem::QIPrepareResult result;
        while ((result = item->Prepare(*this, waitForCache)) != RenderQueueItem::QIP_Done)
        {
            if (result == RenderQueueItem::QIP_NeedCache)
                waitForCache = true;
            drawProcessedPrimitives();
        }
        // one item was asked for: the rest only go as far as they can without waiting
        if (mode == QPM_One)
            waitForCache = false;
        ++CurrentItem;
    }

    if (QueueMode != MeshCache::QM_ExtendLocks || !Caches.AnyCacheLocked())
        drawProcessedPrimitives();
}

// @0x1426e04b0
void RenderQueueProcessor::drawProcessedPrimitives()
{
    RenderQueue& queue = Queue;
    if (Caches.AnyCacheLocked())
        Caches.UnlockCaches();

    while (queue.GetTail() != CurrentItem)
    {
        RenderQueueItem* item = queue.GetTailItem();
        item->EmitToHAL(*this);
        queue.AdvanceTail();
    }

    // the current item was prepared in part (a cache ran full): emit what it has so far
    if (queue.GetHead() != CurrentItem)
    {
        RenderQueueItem* item = queue.GetTailItem();
        item->EmitToHAL(*this);
    }
}

}} // namespace Scaleform::Render
