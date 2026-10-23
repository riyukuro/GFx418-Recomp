// Recovered Scaleform 4.1.18 Render: the render queue (Render_Queue, sfr_render_07j). The renderer appends items at
// the head of a ring of RenderQueueItems; a RenderQueueProcessor prepares them in order (filling the mesh / glyph
// caches) and emits the prepared ones to its HAL from the tail, emitting early whenever a cache runs full.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout checked against the ctors 0x1426dfff0 / 0x1426e0010 and BeginFrame 0x1426e00c0.
#ifndef MS2_SF_RENDER_QUEUE_H
#define MS2_SF_RENDER_QUEUE_H

#include "ms2/scaleform/include/render/render_primitivequeue.h"
#include "ms2/scaleform/include/render/render_meshcache.h"

namespace Scaleform { namespace Render {

// A ring of items: Head is the next free slot, Tail the oldest item not emitted yet; one slot always stays empty.
class RenderQueue
{
    unsigned         QueueSize;      // +0x00
    RenderQueueItem* pQueue;         // +0x08
    unsigned         QueueHead;      // +0x10
    unsigned         QueueTail;      // +0x14
    bool             HeadReserved;   // +0x18

public:
    enum { DefaultQueueSize = 256 };

    RenderQueue();
    ~RenderQueue();

    bool Initialize(UPInt itemCount = DefaultQueueSize);
    void Shutdown();

    // the head slot to fill, or 0 while the ring is full; AdvanceHead publishes it
    RenderQueueItem* ReserveHead();
    void AdvanceHead()
    {
        HeadReserved = false;
        if (++QueueHead == QueueSize)
            QueueHead = 0;
    }

    RenderQueueItem* GetTailItem() { return pQueue + QueueTail; }
    // clears the tail item and moves past it
    void AdvanceTail();

    class Iterator
    {
        RenderQueue* pQueue;     // +0x00
        unsigned     QueuePos;   // +0x08

    public:
        Iterator(RenderQueue* queue = 0, unsigned pos = 0) : pQueue(queue), QueuePos(pos) { }
        Iterator(const Iterator& other) : pQueue(other.pQueue), QueuePos(other.QueuePos) { }

        void operator=(const Iterator& other)
        {
            pQueue   = other.pQueue;
            QueuePos = other.QueuePos;
        }
        bool operator==(const Iterator& other) const { return QueuePos == other.QueuePos; }
        bool operator!=(const Iterator& other) const { return QueuePos != other.QueuePos; }

        void operator++()
        {
            if (++QueuePos == pQueue->QueueSize)
                QueuePos = 0;
        }

        RenderQueueItem* GetItem() const  { return pQueue->pQueue + QueuePos; }
        bool             IsAtTail() const { return QueuePos == pQueue->QueueTail; }
        bool             IsAtHead() const { return QueuePos == pQueue->QueueHead; }
    };

    Iterator GetHead() { return Iterator(this, QueueHead); }
    Iterator GetTail() { return Iterator(this, QueueTail); }
};

// Scratch space an item may use while it is being prepared / emitted; pItem tells which item owns it.
struct RQPrepareBuffer
{
    enum { BufferSize = sizeof(void*) * 24 };

    bool  IsProcessing(void* item) const { return item == pItem; }
    void  StartProcessing(void* item)    { pItem = item; }
    void  ClearItem()                    { pItem = 0; }
    void* GetItem() const                { return pItem; }

private:
    void* pItem;
};

struct RQEmitBuffer
{
    enum { BufferSize = sizeof(void*) * 8 };

    bool  IsEmitting(void* item) const { return item == pItem; }
    void  StartEmitting(void* item)    { pItem = item; }
    void  ClearItem()                  { pItem = 0; }
    void* GetItem() const              { return pItem; }

private:
    void* pItem;
};

// Walks one RenderQueue for its HAL. 0x148 bytes.
class RenderQueueProcessor
{
public:
    enum QueueProcessMode
    {
        QPM_Any,   // prepare what is ready, never wait for the GPU
        QPM_One,   // prepare at least one item, waiting for the caches if needed
        QPM_All    // prepare everything queued, waiting as often as needed
    };

    enum QueueProcessFilter
    {
        QPF_All,       // every item
        QPF_Filters    // only the filter primitives
    };

    RenderQueueProcessor(RenderQueue& queue, HAL* hal);
    ~RenderQueueProcessor();

    HAL*       GetHAL() const       { return pHAL; }
    MeshCache* GetMeshCache() const { return (MeshCache*)Caches.GetCache(Cache_Mesh); }

    void BeginFrame();
    // prepares and emits everything queued
    void Flush();
    void ProcessQueue(QueueProcessMode mode);

    QueueProcessFilter GetQueuePrepareFilter() const              { return QueuePrepareFilter; }
    void               SetQueuePrepareFilter(QueueProcessFilter f) { QueuePrepareFilter = f; }
    QueueProcessFilter GetQueueEmitFilter() const                 { return QueueEmitFilter; }
    void               SetQueueEmitFilter(QueueProcessFilter f)    { QueueEmitFilter = f; }

    RQPrepareBuffer*  GetPrepareItemBuffer() { return &PrepareItemBuffer; }
    RQEmitBuffer*     GetEmitItemBuffer()    { return &EmitItemBuffer; }
    RQCacheInterface& GetQueueCachesRef()    { return Caches; }

private:
    // emits every prepared item, then the current one if it was prepared in part
    void drawProcessedPrimitives();
    void resetBufferItems()
    {
        EmitItemBuffer.ClearItem();
        PrepareItemBuffer.ClearItem();
    }
    void operator=(const RenderQueueProcessor&) { }

    HAL*                  pHAL;                 // +0x00
    RQCacheInterface      Caches;               // +0x08
    RenderQueue&          Queue;                // +0x20
    MeshCache::QueueMode  QueueMode;            // +0x28
    QueueProcessFilter    QueuePrepareFilter;   // +0x2c
    QueueProcessFilter    QueueEmitFilter;      // +0x30
    RenderQueue::Iterator CurrentItem;          // +0x38: the next item to prepare
    union
    {
        RQPrepareBuffer PrepareItemBuffer;                             // +0x48
        UByte           PrepareItemBufferBytes[RQPrepareBuffer::BufferSize];
    };
    union
    {
        RQEmitBuffer EmitItemBuffer;                                   // +0x108
        UByte        EmitItemBufferBytes[RQEmitBuffer::BufferSize];
    };
};

}} // namespace Scaleform::Render

// (sfr_render_06g) the HAL embeds the queue: see render_primitivequeue.h
#include "ms2/scaleform/include/render/render_hal.h"

#endif
