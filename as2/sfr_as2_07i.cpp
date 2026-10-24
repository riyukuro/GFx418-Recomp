// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// a clip's single event handlers, the text field variable binding, the walk over a sprite's members, the action
// queue iterator and the AS2 side of a movie's shutdown.
// MS2-UNIT: sfr_as2_07i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298a620-0x14298a871 .text$mn
// MS2-RANGE: 0x14298ee90-0x14298efd7 .text$mn
// MS2-RANGE: 0x142992880-0x1429928ff .text$mn
// MS2-RANGE: 0x142992c40-0x142992e29 .text$mn
// MS2-RANGE: 0x142994190-0x142994201 .text$mn
// MS2-RANGE: 0x142994710-0x1429947e1 .text$mn
// MS2-RANGE: 0x142995180-0x142995273 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/render/text_docview.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

typedef ArrayLH<Value, StatMV_ActionScript_Mem> HandlerArray;

// MovieRoot's sprites that have a hit area (+0x628; the member is not recovered in as2_movieroot.h yet).
typedef ArrayLH<Ptr<Sprite>, StatMV_ActionScript_Mem> SpritesWithHitAreaArray;

SF_FORCEINLINE SpritesWithHitAreaArray& SpritesWithHitAreaOf(MovieRoot* proot)
{
    return *reinterpret_cast<SpritesWithHitAreaArray*>(reinterpret_cast<UByte*>(proot) + 0x628);
}

// The ExternalInterface callbacks of a movie, the pointer at MovieRoot+0x78.
typedef HashNode<ASString, MovieRoot::InvokeAliasInfo, ASStringHashFunctor> InvokeAliasNode;
typedef HashLH<ASString, MovieRoot::InvokeAliasInfo, ASStringHashFunctor, StatMV_ASString_Mem, InvokeAliasNode,
               HashsetNodeEntry<InvokeAliasNode, InvokeAliasNode::NodeHashF> >
    InvokeAliasHash;

// Hands the named children of a sprite to an AS member visitor as character values.
struct ChildClipVisitor : public DisplayList::MemberVisitor
{
    ObjectInterface::MemberVisitor* pVisitor;
    unsigned                        VisitFlags;

    ChildClipVisitor(ObjectInterface::MemberVisitor* pvisitor, unsigned visitFlags)
        : pVisitor(pvisitor), VisitFlags(visitFlags)
    {
    }
    // MS2-FUNCTIONAL: the null character branch is laid out differently; same behavior
    // @0x142994190
    virtual void Visit(const ASString& name, InteractiveObject* pch)
    {
        pVisitor->Visit(name, Value(pch), (UByte)VisitFlags);
    }
};

} // namespace

// Adds a handler for exactly one event (key events are kept without their key code).
// MS2-FUNCTIONAL: hash lookup and insertion codegen differ; same behavior
// @0x14298a620
void AvmCharacter::SetSingleClipEventHandler(const EventId& id, const Value& handler)
{
    EventId       key = (id.Id == EventId::Event_KeyDown || id.Id == EventId::Event_KeyUp) ? EventId(id.Id) : id;
    HandlerArray* phandlers = EventHandlers.Get(key);
    if (phandlers)
        phandlers->PushBack(handler);
    else
    {
        HandlerArray* parr = SF_HEAP_AUTO_NEW(this) HandlerArray();
        parr->PushBack(handler);
        EventHandlers.Set(id, *parr);
        delete parr;
    }
}

// The AS2 half of a movie goes away: its clips with a hit area, its render tree, the callbacks, the global
// context's classes, the queued actions; then a full collection.
// MS2-FUNCTIONAL: the context release and the collection are scheduled differently; same behavior
// @0x14298ee90
void MovieRoot::Shutdown()
{
    SpritesWithHitAreaOf(this).Clear();
    *reinterpret_cast<Ptr<Render::TreeContainer>*>(Unrecovered_28) = 0;
    pMouseListener = 0;
    InvokeAliasHash*& paliases = *reinterpret_cast<InvokeAliasHash**>(Unrecovered_78);
    if (paliases)
        delete paliases;
    paliases = 0;
    ExternalIntfRetVal.SetUndefined();

    pGlobalContext->PreClean(true);
    pGlobalContext->pMovieRoot = 0;
    GlobalContext* pgc = pGlobalContext;
    pgc->pGlobal       = 0;
    pgc->RegisteredClasses.Clear();
    pgc->BuiltinClassesRegistry.Clear();
    pgc->Prototypes.Clear();
    pgc->pMovieRoot = 0;

    ActionQueueIterator iter(&GetActionQueue());
    while (iter.getNext())
        ;

    MemContext->ASGC->ForceCollect();
}

// The field's autoSize goes to its document: the width only follows the text when it does not wrap.
// MS2-FUNCTIONAL: flag reads are scheduled differently; same behavior
// @0x142992880
void AvmTextField::UpdateAutosizeSettings()
{
    TextField*             ptf      = static_cast<TextField*>(pDispObj);
    const bool             autoSize = (ptf->GetFlags418() & TextField::Flags_AutoSize) != 0;
    Render::Text::DocView* pdoc     = ptf->GetDocument();
    if (autoSize && !pdoc->IsWordWrap())
        pdoc->SetAutoSizeX();
    else
        pdoc->ClearAutoSizeX();
    if (autoSize)
        ptf->GetDocument()->SetAutoSizeY();
    else
        ptf->GetDocument()->ClearAutoSizeY();
    ptf->FlagsRef() |= TextField::Flags_NeedUpdateGeomData;
    ptf->SetDirtyFlag();
}

// The bound variable's value, when it changed since last seen, becomes the field's text; false when there is no
// such variable (the text is then emptied) or nothing changed.
// MS2-FUNCTIONAL: the Value temporaries are released in a different order; same behavior
// @0x142992c40
bool AvmTextField::UpdateTextFromVariable()
{
    if (VariableName.GetSize() == 0)
        return true;
    TextField* ptf = static_cast<TextField*>(pDispObj);
    ptf->FlagsRef() |= TextField::Flags_ForceAdvance;
    Environment* penv = GetASEnvironment();
    if (!penv)
        return false;
    Value val;
    if (penv->GetVariable(VariableName, &val))
    {
        if (!val.IsEqual(penv, VariableVal))
        {
            VariableVal = val;
            ptf->SetTextValue(val.ToString(penv).ToCStr(), false, false);
            return true;
        }
    }
    else
        ptf->SetTextValue("", false, false);
    return false;
}

// The field's text goes to the bound variable.
// @0x142992d80
void AvmTextField::UpdateVariable()
{
    if (VariableName.GetSize() == 0)
        return;
    Environment* penv = GetASEnvironment();
    if (!penv)
        return;
    VariableVal.SetString(static_cast<TextField*>(pDispObj)->GetText(false));
    penv->SetVariable(VariableName, VariableVal, 0, true);
}

// The child clips (with VisitMember_ChildClips) come first, then the members of the clip's AS object.
// @0x142994710
void AvmSprite::VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags,
                             const ObjectInterface* instance) const
{
    SF_UNUSED(instance);
    if (visitFlags & VisitMember_ChildClips)
    {
        ChildClipVisitor childVisitor(pvisitor, visitFlags);
        static_cast<Sprite*>(pDispObj)->mDisplayList.VisitMembers(&childVisitor);
    }
    Ptr<Object> pobj = GetASObject();
    if (pobj)
        pobj->VisitMembers(psc, pvisitor, visitFlags, this);
}

// The next queued action in priority order, taken off the queue; the one handed out before goes to the free list.
// A change of the queue under the iterator restarts it at the first priority.
// @0x142995180
const MovieRoot::ActionEntry* MovieRoot::ActionQueueIterator::getNext()
{
    if (pActionQueue->ModId != ModId)
    {
        CurrentPrio = 0;
        ModId       = pActionQueue->ModId;
    }
    ActionEntry* pcurEntry = pActionQueue->Levels[CurrentPrio].pActionRoot;
    while (!pcurEntry)
    {
        if (++CurrentPrio >= ActionQueueType::AL_Count)
            break;
        pcurEntry = pActionQueue->Levels[CurrentPrio].pActionRoot;
    }
    if (pcurEntry)
    {
        if (pcurEntry == pActionQueue->Levels[CurrentPrio].pInsertEntry)
            pActionQueue->Levels[CurrentPrio].pInsertEntry = pcurEntry->pNextEntry;
        pActionQueue->Levels[CurrentPrio].pActionRoot = pcurEntry->pNextEntry;
        pcurEntry->pNextEntry                         = 0;
    }
    if (!pActionQueue->Levels[CurrentPrio].pActionRoot)
    {
        pActionQueue->Levels[CurrentPrio].pInsertEntry = 0;
        pActionQueue->Levels[CurrentPrio].pLastEntry   = 0;
    }
    if (pLastEntry)
        pActionQueue->AddToFreeList(pLastEntry);
    pLastEntry = pcurEntry;
    return pcurEntry;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7MemberVisitor@DisplayList@GFx@Scaleform@@6B@ 0x143215358
