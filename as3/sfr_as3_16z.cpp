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

namespace Scaleform { namespace GFx {
// The wide copy keeps its string node; the characters are decoded once. Inline like in sfr_as2_04, which is what
// emits the vftable and the deleting destructor here too.
inline MovieImpl::WideStringStorage::WideStringStorage(ASStringNode* pnode) : pNode(pnode)
{
    pNode->AddRef();
    UTF8Util::DecodeString(pData, pNode->pData, pNode->Size);
}

inline MovieImpl::WideStringStorage::~WideStringStorage()
{
    pNode->Release();
}
}} // namespace Scaleform::GFx

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

// GFx::Value as the exe lays it out (the members are private to the value).
struct Unk_As3_16zGFxValueRaw
{
    GFx::Value::ObjectInterface* pObjectInterface;   // +0x00
    UInt32                       Type;               // +0x08
    void*                        pData;              // +0x10
    UPInt                        DataAux;            // +0x18 closures: the thunk or the vtable index
};

// v as a host value. A requested type (convert bit) wins; otherwise the kind decides: plain values keep their type,
// objects, classes and functions become objects (display objects and arrays get their own type), closures stay
// closures, a null reference is null and everything else is converted to a string. Strings, objects and closures
// are managed through the movie's object interface; a failed conversion is reported and leaves NaN.
// MS2-FUNCTIONAL: the exe builds the wide string storage inline and keeps the closure kind in a register flag
// @0x1424e42c0
void MovieRoot::ASValue2GFxValue(const Value& v, GFx::Value* pdestVal) const
{
    Unk_As3_16zGFxValueRaw* dest = reinterpret_cast<Unk_As3_16zGFxValueRaw*>(pdestVal);
    unsigned toType;
    bool vtableIndClosure = false;
    if (dest->Type & GFx::Value::VTC_ConvertBit)
        toType = dest->Type & 0xf;
    else
    {
        switch (v.GetKind())
        {
        case Value::kUndefined: toType = GFx::Value::VT_Undefined; break;
        case Value::kBoolean:   toType = GFx::Value::VT_Boolean; break;
        case Value::kInt:       toType = GFx::Value::VT_Int; break;
        case Value::kUInt:      toType = GFx::Value::VT_UInt; break;
        case Value::kNumber:    toType = GFx::Value::VT_Number; break;
        case Value::kObject:
        case Value::kClass:
        case Value::kFunction:
        case Value::kThunkFunction:
            toType = v.GetObject() ? GFx::Value::VT_Object : GFx::Value::VT_Null;
            break;
        case Value::kThunkClosure:
            toType = v.GetClosure() ? GFx::Value::VT_Closure : GFx::Value::VT_Null;
            break;
        case Value::kVTableIndClosure:
            vtableIndClosure = true;
            toType = v.GetClosure() ? GFx::Value::VT_Closure : GFx::Value::VT_Null;
            break;
        default:
            toType = GFx::Value::VT_String;
            break;
        }
        if (v.IsNull())
            toType = GFx::Value::VT_Null;
    }

    if ((dest->Type >> 6) & 1)   // VTC_ManagedBit: drop the old reference
    {
        dest->pObjectInterface->ObjectRelease(pdestVal, dest->pData);
        dest->pObjectInterface = NULL;
    }

    GFx::Value::ObjectInterface* iface = static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface);
    switch (toType)
    {
    case GFx::Value::VT_Undefined:
    case GFx::Value::VT_Null:
        dest->Type = toType;
        break;
    case GFx::Value::VT_Boolean:
        dest->Type = toType;
        *reinterpret_cast<bool*>(&dest->pData) = v.AsBool();
        break;
    case GFx::Value::VT_Int:
        dest->Type = toType;
        if (!v.Convert2Int32(*reinterpret_cast<SInt32*>(&dest->pData)))
        {
            pAVM->OutputAndIgnoreException();
            *reinterpret_cast<Double*>(&dest->pData) = NumberUtil::NaN();
        }
        break;
    case GFx::Value::VT_UInt:
        dest->Type = toType;
        if (!v.Convert2UInt32(*reinterpret_cast<UInt32*>(&dest->pData)))
        {
            pAVM->OutputAndIgnoreException();
            *reinterpret_cast<Double*>(&dest->pData) = NumberUtil::NaN();
        }
        break;
    case GFx::Value::VT_Number:
        dest->Type = toType;
        if (!v.Convert2NumberInline(*reinterpret_cast<Double*>(&dest->pData)))
        {
            pAVM->OutputAndIgnoreException();
            *reinterpret_cast<Double*>(&dest->pData) = NumberUtil::NaN();
        }
        break;
    case GFx::Value::VT_String:
        {
            ASString str(pAVM->GetStringManager().GetBuiltin(AS3Builtin_empty_));
            if (!v.Convert2String(str))
                pAVM->OutputAndIgnoreException();
            // The node's text pointer is its first field, so the node is the managed string.
            dest->pData            = str.GetNode();
            dest->Type             = GFx::Value::VT_String | GFx::Value::VTC_ManagedBit;
            dest->pObjectInterface = iface;
            iface->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    case GFx::Value::VT_StringW:
        {
            ASString str(pAVM->GetStringManager().GetBuiltin(AS3Builtin_empty_));
            if (!v.Convert2String(str))
                pAVM->OutputAndIgnoreException();
            ASStringNode* pnode = str.GetNode();
            const unsigned len = str.GetLength() + 1;
            void* pmem = pMovieImpl->GetMovieHeap()->Alloc(
                sizeof(MovieImpl::WideStringStorage) - 1 + sizeof(wchar_t) * len);
            dest->Type = GFx::Value::VT_StringW | GFx::Value::VTC_ManagedBit;
            Ptr<MovieImpl::WideStringStorage> pwstr = *::new (pmem) MovieImpl::WideStringStorage(pnode);
            dest->pData            = pwstr->pData;
            dest->pObjectInterface = iface;
            iface->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    case GFx::Value::VT_Object:
        {
            Object* obj = v.GetObject();
            const Traits& tr = obj->GetTraits();
            const BuiltinTraitsType tt = tr.GetTraitsType();
            UInt32 type = GFx::Value::VT_Object;
            if (UInt32(tt - Traits_DisplayObject_Begin) < UInt32(Traits_DisplayObject_End - Traits_DisplayObject_Begin) &&
                tr.IsInstanceTraits())
                type = GFx::Value::VT_DisplayObject;
            else if (tt == Traits_Array && tr.IsInstanceTraits())
                type = GFx::Value::VT_Array;
            dest->pData            = obj;
            dest->Type             = type | GFx::Value::VTC_ManagedBit;
            dest->pObjectInterface = iface;
            iface->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    case GFx::Value::VT_Closure:
        {
            // Bit 1 of the object pointer tells a vtable index closure from a thunk closure.
            dest->Type    = GFx::Value::VT_Closure | GFx::Value::VTC_ManagedBit;
            dest->pData   = reinterpret_cast<void*>(reinterpret_cast<UPInt>(v.GetClosure()) | (vtableIndClosure ? 2 : 0));
            dest->DataAux = vtableIndClosure ? UPInt(SPInt(v.GetVTableInd())) : reinterpret_cast<UPInt>(&v.AsThunk());
            dest->pObjectInterface = iface;
            iface->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    default:
        break;
    }
}

// The loaded-movie-def hash (+0x6e8): the value an identity-hashed key maps to, and the add of a new node.
void* FUN_1425059f0(const void* self, const UPInt& key);
void FUN_1424d4220(void* self, void* pheapAddr, const void* nodeRef, UPInt hashValue);

// A use of pdefImpl: an entry already listed counts one more use; otherwise one is added (holding the definition)
// with a single use.
// MS2-FUNCTIONAL: the hash lookup and add are called through their exe addresses
// @0x1424e8e20
void MovieRoot::AddLoadedMovieDef(MovieDefImpl* pdefImpl)
{
    struct Info { Ptr<MovieDefImpl> pMovieDef; unsigned UseCnt; };
    struct NodeRef { MovieDefImpl* const* pFirst; const Info* pSecond; };
    UPInt key = reinterpret_cast<UPInt>(pdefImpl);
    Info* pinfo = static_cast<Info*>(FUN_1425059f0(&LoadedMovieDefs, key));
    if (pinfo)
    {
        ++pinfo->UseCnt;
        return;
    }
    Info info;
    info.pMovieDef = pdefImpl;
    info.UseCnt = 1;
    NodeRef ref = { &pdefImpl, &info };
    FUN_1424d4220(&LoadedMovieDefs, &LoadedMovieDefs, &ref, reinterpret_cast<UPInt>(pdefImpl));
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
// MS2-PIN: ??_GWideStringStorage@MovieImpl@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e40a0
