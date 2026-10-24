// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 movie root and display objects,
// the upper half of sfr_as3_16's range (split with cx18 at 0x1424e2040). Our own source, written from the exe.
// MS2-UNIT: sfr_as3_16z
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424e2040-0x1424e2bb0 .text$mn
// MS2-RANGE: 0x1424e2c10-0x1424e3020 .text$mn
// MS2-RANGE: 0x1424e3260-0x1424e3580 .text$mn
// MS2-RANGE: 0x1424e35e0-0x1424e3690 .text$mn
// MS2-RANGE: 0x1424e37a0-0x1424e3bd0 .text$mn
// MS2-RANGE: 0x1424e3c30-0x1424e3cc0 .text$mn
// MS2-RANGE: 0x1424e3d60-0x1424e4290 .text$mn
// MS2-RANGE: 0x1424e42c0-0x1424e46f0 .text$mn
// MS2-RANGE: 0x1424e5e80-0x1424e63b0 .text$mn
// MS2-RANGE: 0x1424e6aa0-0x1424e6f90 .text$mn
// MS2-RANGE: 0x1424e7140-0x1424e7f40 .text$mn
// MS2-RANGE: 0x1424e80f0-0x1424e8c20 .text$mn
// MS2-RANGE: 0x1424e8e20-0x1424e8ed0 .text$mn
// MS2-RANGE: 0x1424eab60-0x1424eaf00 .text$mn
// MS2-RANGE: 0x1424eaf80-0x1424eb610 .text$mn
// The Avm* deleting destructors free only on a global delete, and AvmButton / AvmTextField / AvmStaticText are modeled.
#define SF_AS3_AVM_INPLACE_DELETE
#define SF_AS3_AVMBUTTON_MODEL
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_udbase.h"
#include "ms2/scaleform/include/gfx/as2/as2_object.h"
#include "ms2/scaleform/include/gfx/as3/as3_loadqueue.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_taskmanager.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_framecounter.h"
#include "ms2/scaleform/include/gfx/as3/as3_stickyvarnode.h"
#include "ms2/scaleform/include/gfx/as3/as3_eventchains.h"
#include "ms2/scaleform/include/gfx/as3/as3_valueobjectinterface.h"
#include "ms2/scaleform/include/gfx/as3/as3_userdefinedfunction.h"
#undef GetObject

// VM: runs the queued code (unrecovered).
extern "C" void FUN_1424fa5b0(void* vm, unsigned count);

namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL: same calls and stores; the exe lays out the frame and the parent lookup differently.
// @0x1424e6d90
void AvmDisplayObjContainer::AddChild(DisplayObjectBase* ch)
{
    if (ch->GetParent())
        AvmDisplayObjContainer::FromBase(static_cast<DisplayObjContainer*>(ch->GetParent())->GetAvmDispContainer())
            ->RemoveChild(ch);
    DisplayObjContainer* pcont = GetDisplayObjContainer();
    pcont->mDisplayList.AddEntryAtIndex(pcont, pcont->mDisplayList.GetCount(), ch);
    pcont->mDisplayList.Flags |= DisplayList::Flags_DepthToIndexInvalid | DisplayList::Flags_MayContainForeignElems;
    ch->pParent = pcont;
    ch->Depth   = -1;
    ch->SetUnloaded(false);
    ch->SetUnloading(false);
    if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsInPlayList())
        ToAvmInteractiveObj(static_cast<InteractiveObject*>(ch))->MoveBranchInPlayList();
    if (ch->IsScriptableObject())
        ToAvmDisplayObj(ch)->OnAdded(false);
}

// @0x1424e6e90
void AvmDisplayObjContainer::AddChildAt(DisplayObjectBase* ch, unsigned index)
{
    if (ch->GetParent())
        AvmDisplayObjContainer::FromBase(static_cast<DisplayObjContainer*>(ch->GetParent())->GetAvmDispContainer())
            ->RemoveChild(ch);
    DisplayObjContainer* pcont = GetDisplayObjContainer();
    unsigned count = static_cast<unsigned>(pcont->mDisplayList.GetCount());
    if (index > count)
        index = count;
    pcont->mDisplayList.AddEntryAtIndex(pcont, index, ch);
    ch->pParent = pcont;
    ch->Depth   = -1;
    ch->SetUnloaded(false);
    ch->SetUnloading(false);
    if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsInPlayList())
        ToAvmInteractiveObj(static_cast<InteractiveObject*>(ch))->MoveBranchInPlayList();
    if (ch->IsScriptableObject())
        ToAvmDisplayObj(ch)->OnAdded(false);
}

// MovieRoot::AddStickyVariable: keeps name = val under path until its target exists (permanently for
// Movie::SV_Permanent, 2).
// @0x1424eab60
void Sfr21AddStickyVariable(MovieRoot* self, const ASString& path, const ASString& name, const Value& val,
                            int setType)
{
    if (name.GetSize() == 0)
        return;
    MovieImpl* pmovie = self->pMovieImpl;
    MovieRoot::StickyVarNode* pnode = SF_HEAP_NEW(pmovie->GetMovieHeap())
        MovieRoot::StickyVarNode(name, val, setType == 2);
    if (pnode)
        pmovie->AddStickyVariableNode(path, pnode);
}

// @0x1424eac70
void EventChains::AddToChain(EventId::IdCode evtId, DisplayObject* obj)
{
    Chain*                     chain;
    Scaleform::AutoPtr<Chain>* pentry = Chains.Get(evtId);
    if (!pentry)
    {
        chain = SF_HEAP_AUTO_NEW(this) Chain();
        Chains.Add(evtId, Scaleform::AutoPtr<Chain>(chain));
    }
    else
        chain = pentry->GetPtr();
    if (FindObjectIndexInChain(chain, obj) == SF_MAX_UPINT)
        chain->PushBack(WeakPtr<DisplayObject>(obj));
}

// MS2-FUNCTIONAL: ClearAction inlined with another register and frame layout than the exe.
// @0x1424eae40
void MovieRoot::ActionQueueType::AddToFreeList(ActionEntry* pentry)
{
    pentry->ClearAction();
    if (FreeEntriesCount < 50)
    {
        pentry->pNextEntry = pFreeEntry;
        pFreeEntry         = pentry;
        ++FreeEntriesCount;
    }
    else
        delete pentry;
}

// Runs the frame: the class constructors still queued, the two highest action levels, then queues the frame
// scripts of the play list and moves the manual actions behind them.
// MS2-FUNCTIONAL: same calls in the same order; the exe saves its registers in another frame layout.
// @0x1424eb260
void FrameCounter::AdvanceFrame(bool nextFrame, float framePos)
{
    SF_UNUSED(framePos);
    if (!nextFrame)
        return;
    MovieRoot* proot = static_cast<MovieRoot*>(GetMovieImpl()->pASMovieRoot);
    if (proot->ASFramesToExecute)
    {
        FUN_1424fa5b0(proot->pAVM, 1);
        if (proot->pAVM->HandleException)
            proot->pAVM->HandleException = false;
        proot->ASFramesToExecute = 0;
    }
    proot->ExecuteActionQueue(MovieRoot::AL_Highest);
    proot->ExecuteActionQueue(MovieRoot::AL_High);
    QueueFrameActions();
    proot->RequeueActionQueue(MovieRoot::AL_Manual, MovieRoot::AL_Frame);
}

// Not exe code: the stage builds its frame counter inline (sfr_as3_18), but FrameCounter's deleting destructor lies in
// this unit's range; constructing one here emits it.
void Unk_As3_16zConstructFrameCounter(void* p, MovieDefImpl* pdefImpl, ASMovieRootBase* pasRoot)
{
    new (p) FrameCounter(pdefImpl, pasRoot, NULL, ResourceId());
}

// Not exe code: the AS3 parts are built by sfr_as3_15's out-of-line constructors and destroyed through their vftables;
// running their inline destructors here emits the vftables and with them the deleting destructors of this range.
void Unk_As3_16zDestroyAvmParts(AvmInteractiveObj* pio, AvmButton* pbtn, AvmTextField* ptxt, AvmStaticText* pst)
{
    pio->AvmInteractiveObj::~AvmInteractiveObj();
    pbtn->AvmButton::~AvmButton();
    ptxt->AvmTextField::~AvmTextField();
    pst->AvmStaticText::~AvmStaticText();
}

// Not exe code: the same for interfaces whose objects are built inline or in other units.
void Unk_As3_16zDestroyInterfaces(AS3ValueObjectInterface* pvoi, GFx::Value::ObjectInterface* poi, FlashUI* pui,
                                  UserDefinedFunction* pudf)
{
    pvoi->AS3ValueObjectInterface::~AS3ValueObjectInterface();
    new (pvoi) AS3ValueObjectInterface(NULL);
    poi->GFx::Value::ObjectInterface::~ObjectInterface();
    pui->FlashUI::~FlashUI();
    pudf->UserDefinedFunction::~UserDefinedFunction();
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {

// Not exe code: abstract probes whose constructors run the implicit constructors of the GFx Avm*Base interfaces, which
// emits their vftables and the deleting destructors of this range.
struct Unk_As3_16zButtonBaseProbe : AvmButtonBase { Unk_As3_16zButtonBaseProbe(); };
struct Unk_As3_16zTextFieldBaseProbe : AvmTextFieldBase { Unk_As3_16zTextFieldBaseProbe(); };
struct Unk_As3_16zSpriteBaseProbe : AvmSpriteBase { Unk_As3_16zSpriteBaseProbe(); };
Unk_As3_16zButtonBaseProbe::Unk_As3_16zButtonBaseProbe() {}
Unk_As3_16zTextFieldBaseProbe::Unk_As3_16zTextFieldBaseProbe() {}
Unk_As3_16zSpriteBaseProbe::Unk_As3_16zSpriteBaseProbe() {}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_GFrameCounter@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2de0
// MS2-FUNCTIONAL 0x1424e3ac0: the exe's ??_G inlines the weak-reference release of mValue, ours calls it.
// MS2-PIN: ??_GStickyVarNode@MovieRoot@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3ac0
// MS2-PIN: ??_GAvmButtonBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2730
// MS2-PIN: ??_GAvmDisplayObjBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e27a0
// MS2-PIN: ??_GAvmDisplayObjContainerBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2830
// MS2-PIN: ??_GAvmInteractiveObj@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2860
// MS2-PIN: ??_GAvmInteractiveObjBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e28b0
// MS2-PIN: ??_GAvmSpriteBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e29e0
// MS2-PIN: ??_GAvmStaticText@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2a70
// MS2-PIN: ??_GAvmTextFieldBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2b20
// MS2-PIN: ??_GAS3ValueObjectInterface@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2150
// MS2-PIN: ??_GObjectInterface@Value@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e35e0
// MS2-PIN: ??_GFlashUI@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2db0
// MS2-FUNCTIONAL 0x1424e3de0: the exe inlines ~FunctionBase into the deleting destructor, ours calls it.
// MS2-PIN: ??_GUserDefinedFunction@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3de0
