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

// A parsed clip event of a placed object: the event id (+0x00, 0x14 bytes) and its action bytes.
struct AvmSwfEventView
{
    EventId           Event;       // +0x00
    UByte             Pad[4];
    ActionBufferData* pActionOpData; // +0x18
};

// MS2-FUNCTIONAL: AvmSwfEvent is not modelled; the event is read as its view. The handler becomes an event-kind
// function of the character's environment, set once per bit of the event id.
// @0x142931dc0
void AvmSwfEvent_AttachTo(AvmSwfEventView* pevent, InteractiveObject* pchar)
{
    ActionBufferData* pdata = pevent->pActionOpData;
    if (!pdata || !pdata->GetLength() || !**reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(pdata) + 0x10))
        return;
    AvmCharacter* pavm = pchar ? ToAvmCharacter(pchar) : 0;
    Environment*  penv = pavm->GetASEnvironment();
    ActionBuffer* pbuf = new (penv->GetSC()->GetHeap()) ActionBuffer(penv->GetSC(), pdata);
    UInt32        id   = pevent->Event.Id;
    ActionBuffer::ExecuteType type =
        (id == 1 || id == 4 || id == 0x200 || id == 0x40000) ? ActionBuffer::Exec_SpecialEvent : ActionBuffer::Exec_Event;
    Value handler(FunctionRef(*::new (penv->GetSC()->GetHeap()) AsFunctionObject(penv, pbuf, 0, pdata->GetLength(), 0, type)));
    unsigned bits = 0;
    for (UInt32 m = id; m; m &= m - 1)
        ++bits;
    if (bits == 1)
        pavm->SetSingleClipEventHandler(pevent->Event, handler);
    else
    {
        UInt32 bit = 1;
        for (unsigned n = 0; n < bits; bit <<= 1)
            if (id & bit)
            {
                EventId one = pevent->Event;
                one.Id      = bit;
                pavm->SetSingleClipEventHandler(one, handler);
                ++n;
            }
    }
    if (pbuf)
        pbuf->Release();
}

}}} // namespace Scaleform::GFx::AS2
