// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// the out-of-line copies the exe keeps of small inline members: the member visitors of for..in, SharedObject.flush
// and the init object of attachMovie, the session walk of the action queue, and TextFormat::SetFontSize.
// MS2-UNIT: sfr_as2_07p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429938d0-0x142993dc0 .text$mn
// MS2-RANGE: 0x142993f60-0x142993fc8 .text$mn
// MS2-RANGE: 0x142995280-0x14299536c .text$mn
// MS2-RANGE: 0x142981610-0x142981642 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_sharedobject.h"
#include "../include/kernel/sf_hash.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/render/text_core.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The member visitors below are made only by code that is not recovered yet (ActionBuffer's Enumerate 0x142939920,
// SharedObject.flush 0x142945b20), so they are declared here with their layouts; their vftables are 0x1432205f0
// and 0x1432227f8.

// for..in: every enumerable member name goes on the stack.
struct EnumerateOpVisitor : public ObjectInterface::MemberVisitor
{
    Environment*  pEnv; // +0x08
    ActionLogger* pLog; // +0x10 set when actions are traced

    EnumerateOpVisitor(Environment* penv, ActionLogger* plog) : pEnv(penv), pLog(plog) {}
    virtual void Visit(const ASString& name, const Value& val, UByte flags);
};

// @0x142993d50
void EnumerateOpVisitor::Visit(const ASString& name, const Value&, UByte)
{
    pEnv->Push(name);
    if (pLog)
        pLog->LogAction("---enumerate - Push: %s\n", name.ToCStr());
}

// SharedObject.flush: hands the data members to the writer, objects and arrays as nested scopes. Each object is
// written once: VisitedObjects stops the walk at objects already seen.
struct SharedObjectFlushVisitor : public ObjectInterface::MemberVisitor
{
    typedef HashUncached<Object*, Object*, IdentityHash<Object*> > ObjectSet;

    ObjectSet            VisitedObjects; // +0x08
    Environment*         pEnv;           // +0x10
    SharedObjectVisitor* pWriter;        // +0x18

    SharedObjectFlushVisitor(Environment* penv, SharedObjectVisitor* pwriter) : pEnv(penv), pWriter(pwriter) {}
    virtual void Visit(const ASString& name, const Value& val, UByte flags);
};

// MS2-FUNCTIONAL: same length and calls; one commuted and (hash & mask) in the inlined Hash lookup
// @0x1429938d0
void SharedObjectFlushVisitor::Visit(const ASString& name, const Value& val, UByte)
{
    const String sname(name.ToCStr(), name.GetSize());
    switch (val.GetType())
    {
    case Value::NUMBER:
    case Value::INTEGER:
        {
            DoubleFormatter f(val.ToNumber(pEnv));
            f.Convert();
            const String v(f, f.GetSize());
            pWriter->AddProperty(sname, v, GFx::Value::VT_Number);
        }
        break;
    case Value::STRING:
        {
            const String v(val.ToString(pEnv).ToCStr());
            pWriter->AddProperty(sname, v, GFx::Value::VT_String);
        }
        break;
    case Value::UNDEFINED:
        {
            const String v("");
            pWriter->AddProperty(sname, v, GFx::Value::VT_Undefined);
        }
        break;
    case Value::BOOLEAN:
        {
            const String v(val.ToBool(pEnv) ? "true" : "false");
            pWriter->AddProperty(sname, v, GFx::Value::VT_Boolean);
        }
        break;
    case Value::NULLTYPE:
        {
            const String v("");
            pWriter->AddProperty(sname, v, GFx::Value::VT_Null);
        }
        break;
    case Value::OBJECT:
        {
            Object* pobj = val.ToObject(pEnv);
            if (VisitedObjects.Get(pobj) == 0)
            {
                VisitedObjects.Add(pobj, pobj);
                if (pobj->GetObjectType() == ObjectInterface::Object_Array)
                {
                    pWriter->PushArray(sname);
                    pobj->VisitMembers(pEnv->GetSC(), this, 0);
                    pWriter->PopArray();
                }
                else
                {
                    pWriter->PushObject(sname);
                    pobj->VisitMembers(pEnv->GetSC(), this, 0);
                    pWriter->PopObject();
                }
            }
        }
        break;
    default:
        break;
    }
}

// The init object visitor of sfr_as2_06e (AvmSprite::InitObjectMembers), whose Visit is inline there: the layout
// and the out-of-line copy the vftable 0x143221988 holds.
struct InitObjectVisitorCopy : public ObjectInterface::MemberVisitor
{
    Environment*       pEnv;       // +0x08
    InteractiveObject* pCharacter; // +0x10

    virtual void Visit(const ASString& name, const Value& val, UByte flags);
};

// @0x142993f60
void InitObjectVisitorCopy::Visit(const ASString& name, const Value& val, UByte)
{
    InteractiveObject* pch = pCharacter;
    static_cast<AvmCharacter*>(!pch ? 0 : pch->GetAvmIntObj())->SetMember(pEnv, name, val);
}

// The session walk of MovieRoot::DoActionsForSession (sfr_as2_05, which inlines it): the iterator layout and the
// exe's out-of-line copy of its getNext. Entries of the session are unlinked and handed out; the one handed out
// last goes back to the free list.
struct ActionQueueSessionIteratorState
{
    typedef MovieRoot::ActionQueueType ActionQueueType;
    typedef MovieRoot::ActionEntry     ActionEntry;

    int              ModId;        // +0x00
    ActionQueueType* pActionQueue; // +0x08
    ActionEntry*     pLastEntry;   // +0x10
    int              CurrentPrio;  // +0x18
    UByte            Pad_1c[4];    // (the end of the plain ActionQueueIterator)
    unsigned         SessionId;    // +0x20
};

// @0x142995280
const MovieRoot::ActionEntry* ActionQueueSessionIterator_getNext(ActionQueueSessionIteratorState* pit)
{
    typedef ActionQueueSessionIteratorState::ActionQueueType ActionQueueType;
    typedef ActionQueueSessionIteratorState::ActionEntry     ActionEntry;

    if (pit->pActionQueue->ModId != pit->ModId)
    {
        pit->CurrentPrio = 0;
        pit->ModId       = pit->pActionQueue->ModId;
    }
    ActionEntry* pentry = 0;
    for (; pit->CurrentPrio < ActionQueueType::AL_Count; ++pit->CurrentPrio)
    {
        ActionEntry* pprev = 0;
        for (pentry = pit->pActionQueue->Levels[pit->CurrentPrio].pActionRoot; pentry;
             pprev = pentry, pentry = pentry->pNextEntry)
        {
            if (pentry->SessionId == pit->SessionId)
                break;
        }
        if (pentry)
        {
            if (!pprev)
                pit->pActionQueue->Levels[pit->CurrentPrio].pActionRoot = pentry->pNextEntry;
            else
                pprev->pNextEntry = pentry->pNextEntry;
            if (!pentry->pNextEntry)
                pit->pActionQueue->Levels[pit->CurrentPrio].pLastEntry = pprev;
            if (pentry == pit->pActionQueue->Levels[pit->CurrentPrio].pInsertEntry)
                pit->pActionQueue->Levels[pit->CurrentPrio].pInsertEntry =
                    !pentry->pNextEntry ? pprev : pentry->pNextEntry;
            pentry->pNextEntry = 0;
            break;
        }
    }
    if (pit->pLastEntry)
        pit->pActionQueue->AddToFreeList(pit->pLastEntry);
    pit->pLastEntry = pentry;
    return pentry;
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace Render { namespace Text {

// The out-of-line copy of TextFormat::SetFontSize, which the header inlines.
// @0x142981610
void TextFormat_SetFontSize(TextFormat* pfmt, float pixels)
{
    pfmt->SetFontSize(pixels);
}

}}} // namespace Scaleform::Render::Text

// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
