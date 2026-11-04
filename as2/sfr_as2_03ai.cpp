// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 clip event handlers of a placed
// object: AvmSwfEvent::AttachTo (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_03ai
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142931dc0-0x14293200f .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_eventid.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// An allocation of Size bytes from pHeap, for an object larger than its modelled class.
struct AvmSwfEventSizedAlloc
{
    MemoryHeap* pHeap;
    UPInt       Size;
};

}}} // namespace Scaleform::GFx::AS2

#pragma warning(disable : 4291) // no matching delete: the exe frees nothing if the ctor throws
inline void* operator new(size_t, Scaleform::GFx::AS2::AvmSwfEventSizedAlloc a)
{
    return a.pHeap->Alloc(a.Size);
}

namespace Scaleform { namespace GFx { namespace AS2 {

// A parsed clip event of a placed object (onClipEvent): the event id (+0x00, 0x14 bytes) and its action bytes.
// Only the members read here.
class AvmSwfEvent
{
public:
    EventId           Event;         // +0x00
    ActionBufferData* pActionOpData; // +0x18

    void AttachTo(InteractiveObject* pchar) const;
};

// The number of set bits of v.
static SF_FORCEINLINE UByte AvmSwfEvent_BitCount(UInt32 v)
{
    v = ((v >> 1) & 0x55555555) + (v & 0x55555555);
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
    v = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
    return UByte(v % 255);
}

// The handler becomes an event-kind function of the character's environment, set once per bit of the event id.
// MS2-FUNCTIONAL: the exe releases the handler before the saved registers are restored (the zero-bit path jumps
// straight to its dtor); ours restores rbx first.
// @0x142931dc0
void AvmSwfEvent::AttachTo(InteractiveObject* pchar) const
{
    ActionBufferData* pdata = pActionOpData;
    if (!pdata || pdata->GetLength() < 1 || !**reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(pdata) + 0x10))
        return;
    AvmCharacter* pavm = !pchar ? 0 : ToAvmCharacter(pchar);
    Environment*  penv = pavm->GetASEnvironment();
    MemoryHeap*   pheap = penv->GetSC()->GetHeap();
    Ptr<ActionBuffer> pbuf = *new (pheap) ActionBuffer(penv->GetSC(), pActionOpData);
    ActionBuffer::ExecuteType type;
    switch (Event.Id)
    {
    case 1:
    case 4:
    case 0x200:
    case 0x40000:
        type = ActionBuffer::Exec_SpecialEvent;
        break;
    default:
        type = ActionBuffer::Exec_Event;
        break;
    }
    // The function object is 0xd0 bytes in the exe; the header models only its first 0x78.
    Value handler(FunctionRef(*::new (AvmSwfEventSizedAlloc{pheap, 0xd0})
                                  AsFunctionObject(penv, pbuf, 0, pActionOpData->GetLength(), 0, type)));
    unsigned bits = AvmSwfEvent_BitCount(Event.Id);
    if (bits == 1)
        pavm->SetSingleClipEventHandler(Event, handler);
    else
    {
        for (unsigned n = 0, bit = 1; n < bits; bit <<= 1)
            if (Event.Id & bit)
            {
                EventId one = Event;
                one.Id      = bit;
                ++n;
                pavm->SetSingleClipEventHandler(one, handler);
            }
    }
}

}}} // namespace Scaleform::GFx::AS2
