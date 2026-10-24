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

// Queues a C function of the character with params.
static inline void SetCFunctionAction(MovieRoot::ActionEntry* pe, InteractiveObject* pch, CFunctionPtr pfunc,
                                      const Array<Value>& params)
{
    pe->Type          = MovieRoot::ActionEntry::Entry_CFunction;
    pe->pCharacter    = pch;
    pe->pActionBuffer = 0;
    pe->CFunction     = pfunc;
    pe->FunctionParams = params;
}

// Queues a clip event of the character.
static inline void SetEventAction(MovieRoot::ActionEntry* pe, InteractiveObject* pch, UInt32 id)
{
    pe->Type          = MovieRoot::ActionEntry::Entry_Event;
    pe->pCharacter    = pch;
    pe->pActionBuffer = 0;
    pe->mEventId      = EventId(id);
}

// MS2-FUNCTIONAL: the queued entries are filled member by member and the session counter is reached by address.
// @0x14296ab10
unsigned AvmSprite::OnAddingDisplayObject(const CharacterCreateInfo& ccinfo, InteractiveObject* pch,
                                          const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                          const void* pinitSource, bool placeObject)
{
    Sprite*    pspriteCh   = pch->IsSprite() ? static_cast<Sprite*>(pch) : 0;
    bool       needsOnLoad = true;
    MovieRoot* proot       = GetAS2Root();

    if (peventHandlers)
    {
        for (UPInt i = 0, n = peventHandlers->GetSize(); i < n; ++i)
        {
            reinterpret_cast<const AvmSwfEvent*>((*peventHandlers)[i])->AttachTo(pch);
            if (pspriteCh && reinterpret_cast<const AvmSwfEvent*>((*peventHandlers)[i])->Event.IsButtonEvent())
            {
                MovieClipObject* pmc = static_cast<AvmSprite*>(static_cast<AvmCharacter*>(
                    static_cast<AvmInteractiveObjBase*>(pspriteCh->GetAvmObjImpl())))->GetMovieClipObject();
                if (pmc)
                    pmc->HasButtonHandlers = true;
            }
            // An onClipEvent(initialize) of a placed object runs before its frame actions.
            const AvmSwfEvent* pev = reinterpret_cast<const AvmSwfEvent*>((*peventHandlers)[i]);
            if (placeObject && pev->Event.Id == EventId::Event_Initialize && pev->pActionOpData &&
                pev->pActionOpData->GetBufferPtr())
            {
                MovieRoot::ActionEntry* pe = proot->InsertEmptyAction(ActionPriority::AP_Initialize);
                if (pe)
                    SetEventAction(pe, pch, EventId::Event_Initialize);
            }
        }
    }

    GlobalContext*  pcontext    = GetGC();
    FunctionRef     ctorFunc;
    const String*   psymbolName = pch->GetResourceMovieDef()->GetNameOfExportedResource(ccinfo.pCharDef->GetId());
    MovieRoot::ActionQueueType& queue = proot->GetActionQueue();
    unsigned        prevSession = queue.Field_a0;
    unsigned        sessionId   = ++*reinterpret_cast<unsigned*>(&queue.Field_a8);
    queue.Field_a0              = sessionId;
    bool            constructed = false;

    if (psymbolName)
    {
        ASString symbolName = GetASEnvironment()->GetSC()->CreateString(psymbolName->ToCStr(),
                                                                         psymbolName->GetSize());
        const FunctionRef* pctor =
            pcontext->RegisteredClasses.GetCaseCheck(symbolName, GetASEnvironment()->IsCaseSensitive());
        if (pctor)
        {
            ctorFunc = *pctor;
            // The instance gets the class prototype first, then onClipEvent(construct), the initObject members and
            // the constructor call.
            {
                Array<Value> params;
                params.PushBack(Value(ctorFunc));
                MovieRoot::ActionEntry* pe = proot->InsertEmptyAction(ActionPriority::AP_Initialize);
                if (pe)
                    SetCFunctionAction(pe, pch, AvmSprite::InitializeClassInstance, params);
                pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
                if (pe)
                    SetEventAction(pe, pch, EventId::Event_Construct);
                needsOnLoad = false;

                if (GetDispObj()->GetVersion() >= 6 && pinitSource)
                {
                    params.Resize(0);
                    Value initObj;
                    initObj.SetAsObjectInterface((ObjectInterface*)pinitSource);
                    params.PushBack(initObj);
                    pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
                    if (pe)
                        SetCFunctionAction(pe, pch, AvmSprite::InitObjectMembers, params);
                }
                constructed = true;
                pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
                if (pe)
                {
                    pe->Type          = MovieRoot::ActionEntry::Entry_Function;
                    pe->pCharacter    = pch;
                    pe->pActionBuffer = 0;
                    pe->Function      = ctorFunc;
                }
            }
        }
        else if (placeObject)
        {
            // The class may be registered later (an #initclip of a later frame): look it up when the action runs.
            Array<Value> params;
            params.PushBack(Value(symbolName));
            MovieRoot::ActionEntry* pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
            if (pe)
                SetCFunctionAction(pe, pch, FUN_142943480, params);
            needsOnLoad = false;
        }
    }

    if (placeObject)
    {
        if (needsOnLoad)
        {
            MovieRoot::ActionEntry* pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
            if (pe)
                SetEventAction(pe, pch, EventId::Event_Construct);
        }
    }
    else if (!constructed && GetDispObj()->GetVersion() >= 6 && pinitSource)
    {
        Value initObj;
        initObj.SetAsObjectInterface((ObjectInterface*)pinitSource);
        Array<Value> params;
        params.PushBack(initObj);
        MovieRoot::ActionEntry* pe = proot->InsertEmptyAction(ActionPriority::AP_Construct);
        if (pe)
            SetCFunctionAction(pe, pch, AvmSprite::InitObjectMembers, params);
    }

    queue.Field_a0 = prevSession;
    return sessionId;
}

}}} // namespace Scaleform::GFx::AS2
