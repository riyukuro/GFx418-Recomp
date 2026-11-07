// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmSprite::OnAddingDisplayObject
// of sfr_as2_06 (gap recovery, lane sfr24): a child put on the display list gets its clip events, and the class
// registered for its export name (or the initObject of attachMovie) is queued as actions of a new session.
// MS2-UNIT: sfr_as2_06s5
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14296ab10-0x14296b2a8 .text$mn

#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_eventid.h"
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// A parsed clip event of a placed object (onClipEvent): the event and its action bytes. Only the members read here.
class AvmSwfEvent
{
public:
    EventId           Event;         // +0x00
    ActionBufferData* pActionOpData; // +0x18

    // Binds the handler to the character's clip events (exe 0x142931dc0).
    void AttachTo(InteractiveObject* pch) const;
};

// AvmSprite::FindClassAndInitializeClassInstance (gap of sfr_as2_05)
void FUN_142943480(const FnCall& fn);

// ActionBufferData::IsNull of the SDK: no actions (pBuffer and BufferLen are protected, read through a view).
struct AvmActionBufferDataView
{
    UByte    Base[0x10];
    UByte*   pBuffer;   // +0x10
    unsigned BufferLen; // +0x18
};
static SF_FORCEINLINE bool ActionDataIsNull(const ActionBufferData* pdata)
{
    const AvmActionBufferDataView* p = reinterpret_cast<const AvmActionBufferDataView*>(pdata);
    return p->BufferLen < 1 || p->pBuffer[0] == 0;
}

// ActionQueueType::StartNewSession of the SDK: Field_a0 is CurrentSessionId, the low half of Field_a8 LastSessionId.
static SF_FORCEINLINE unsigned StartNewSession(MovieRoot::ActionQueueType& queue, unsigned* pprevSessionId)
{
    if (pprevSessionId)
        *pprevSessionId = queue.Field_a0;
    queue.Field_a0 = ++*reinterpret_cast<unsigned*>(&queue.Field_a8);
    return queue.Field_a0;
}

// ActionEntry::SetAction of the SDK (header inlines there): an event, a function or a C function of the character.
static SF_FORCEINLINE void SetAction(MovieRoot::ActionEntry* pe, InteractiveObject* pcharacter, const EventId id)
{
    pe->Type          = MovieRoot::ActionEntry::Entry_Event;
    pe->pCharacter    = pcharacter;
    pe->pActionBuffer = 0;
    pe->mEventId      = id;
}

static SF_FORCEINLINE void SetAction(MovieRoot::ActionEntry* pe, InteractiveObject* pcharacter,
                                     const FunctionRef& function, const Array<Value>* params = 0)
{
    pe->Type          = MovieRoot::ActionEntry::Entry_Function;
    pe->pCharacter    = pcharacter;
    pe->pActionBuffer = 0;
    pe->Function      = function;
    if (params)
        pe->FunctionParams = *params;
}

static SF_FORCEINLINE void SetAction(MovieRoot::ActionEntry* pe, InteractiveObject* pcharacter,
                                     const CFunctionPtr function, const Array<Value>* params = 0)
{
    pe->Type          = MovieRoot::ActionEntry::Entry_CFunction;
    pe->pCharacter    = pcharacter;
    pe->pActionBuffer = 0;
    pe->CFunction     = function;
    if (params)
        pe->FunctionParams = *params;
}

// MS2-FUNCTIONAL: SDK order now, 1918 bytes against the exe's 1944. The exe keeps `this` in r14 after the loop, gives
// hasConstructEvent/initSourceUsed home slots, and rebuilds the zero for each entry store; ours keeps a zero in r15 and
// spills `this`, and the AddRef in Value(FunctionRef) goes through memory (inc [rax+0x18]) instead of ecx.
// @0x14296ab10
unsigned AvmSprite::OnAddingDisplayObject(const CharacterCreateInfo& ccinfo, InteractiveObject* pscriptCh,
                                          const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                          const void* pinitSource, bool placeObject)
{
    Sprite* pspriteCh = pscriptCh->IsSprite() ? static_cast<Sprite*>(pscriptCh) : 0;

    bool       hasConstructEvent = true; // onConstruct always fires: there is no telling whether it exists
    MovieRoot* asroot            = GetAS2Root();
    if (pscriptCh && peventHandlers)
    {
        for (UPInt i = 0, n = peventHandlers->GetSize(); i < n; i++)
        {
            reinterpret_cast<const AvmSwfEvent*>((*peventHandlers)[i])->AttachTo(pscriptCh);
            // A button handler puts the sprite in button mode.
            if (pspriteCh && reinterpret_cast<const AvmSwfEvent*>((*peventHandlers)[i])->Event.IsButtonEvent())
            {
                MovieClipObject* pmc = static_cast<AvmSprite*>(static_cast<AvmCharacter*>(
                    static_cast<AvmInteractiveObjBase*>(pspriteCh->GetAvmObjImpl())))->GetMovieClipObject();
                if (pmc)
                    pmc->HasButtonHandlers = true;
            }

            if (placeObject)
            {
                if (reinterpret_cast<const AvmSwfEvent*>((*peventHandlers)[i])->Event.Id == EventId::Event_Initialize)
                {
                    ActionBufferData* pactionOpData =
                        reinterpret_cast<const AvmSwfEvent*>((*peventHandlers)[i])->pActionOpData;
                    if (pactionOpData && !ActionDataIsNull(pactionOpData))
                    {
                        MovieRoot::ActionEntry* pe = asroot->InsertEmptyAction(ActionPriority::AP_Initialize);
                        if (pe)
                            SetAction(pe, pscriptCh, EventId(EventId::Event_Initialize));
                    }
                }
            }
        }
    }

    // The class registered for the export name.
    unsigned sessionId = 0;
    if (pscriptCh)
    {
        GlobalContext* gctxt = GetGC();

        FunctionRef   ctorFunc;
        const String* psymbolName =
            pscriptCh->GetResourceMovieDef()->GetNameOfExportedResource(ccinfo.pCharDef->GetId());

        MovieRoot::ActionQueueType& queue = asroot->GetActionQueue();
        unsigned oldSessionId;
        sessionId = StartNewSession(queue, &oldSessionId);

        bool initSourceUsed = false;

        if (psymbolName)
        {
            ASString symbolName = GetASEnvironment()->CreateString(*psymbolName);

            const FunctionRef* pctor =
                gctxt->RegisteredClasses.GetCaseCheck(symbolName, GetASEnvironment()->IsCaseSensitive());
            if (pctor)
            {
                ctorFunc = *pctor;
                // First the initializer of the instance: it gives pscriptCh the class prototype.
                MovieRoot::ActionEntry* pe = asroot->InsertEmptyAction(ActionPriority::AP_Initialize);
                Array<Value> params;
                params.PushBack(ctorFunc);
                if (pe)
                    SetAction(pe, pscriptCh, AvmSprite::InitializeClassInstance, &params);

                // Then the construct event.
                {
                    MovieRoot::ActionEntry* pe = asroot->InsertEmptyAction(ActionPriority::AP_Construct);
                    if (pe)
                        SetAction(pe, pscriptCh, EventId(EventId::Event_Construct));
                    hasConstructEvent = false;
                }

                // The init properties (SWF 6+).
                if (GetDispObj()->GetVersion() >= 6 && pinitSource && pscriptCh)
                {
                    params.Resize(0);
                    Value v;
                    v.SetAsObjectInterface(const_cast<ObjectInterface*>(
                        reinterpret_cast<const ObjectInterface*>(pinitSource)));
                    params.PushBack(v);
                    MovieRoot::ActionEntry* pe = asroot->InsertEmptyAction(ActionPriority::AP_Construct);
                    if (pe)
                        SetAction(pe, pscriptCh, AvmSprite::InitObjectMembers, &params);
                }
                initSourceUsed = true;

                // Then the constructor call.
                pe = asroot->InsertEmptyAction(ActionPriority::AP_Construct);
                if (pe)
                    SetAction(pe, pscriptCh, ctorFunc);
            }
            else if (placeObject)
            {
                // The class may be registered later (an #initclip of a later frame): look it up when the action runs.
                Array<Value> params;
                params.PushBack(Value(symbolName));
                MovieRoot::ActionEntry* pe = asroot->InsertEmptyAction(ActionPriority::AP_Construct);
                if (pe)
                    SetAction(pe, pscriptCh, FUN_142943480, &params);
                hasConstructEvent = false;
            }
        }
        if (placeObject)
        {
            if (hasConstructEvent)
            {
                // No class registered: only onClipEvent(construct).
                MovieRoot::ActionEntry* pe = asroot->InsertEmptyAction(ActionPriority::AP_Construct);
                if (pe)
                    SetAction(pe, pscriptCh, EventId(EventId::Event_Construct));
            }
        }
        else if (!initSourceUsed)
        {
            // attachMovie or duplicateMovieClip with no registered class: the init properties (SWF 6+).
            if (GetDispObj()->GetVersion() >= 6 && pinitSource && pscriptCh)
            {
                Array<Value> params;
                Value        v;
                v.SetAsObjectInterface(const_cast<ObjectInterface*>(
                    reinterpret_cast<const ObjectInterface*>(pinitSource)));
                params.PushBack(v);
                MovieRoot::ActionEntry* pe = asroot->InsertEmptyAction(ActionPriority::AP_Construct);
                if (pe)
                    SetAction(pe, pscriptCh, AvmSprite::InitObjectMembers, &params);
            }
        }
        queue.Field_a0 = oldSessionId;
    }
    return sessionId;
}

}}} // namespace Scaleform::GFx::AS2
