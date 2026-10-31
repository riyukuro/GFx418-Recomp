// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 movie root and display objects,
// the upper half of sfr_as3_16's range (split with cx18 at 0x1424e2040). Our own source, written from the exe.
// MS2-UNIT: sfr_as3_16z
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424e2040-0x1424e20e0 .text$mn
// MS2-RANGE: 0x1424e2150-0x1424e2210 .text$mn
// MS2-RANGE: 0x1424e2290-0x1424e2330 .text$mn
// MS2-RANGE: 0x1424e2420-0x1424e28e0 .text$mn
// MS2-RANGE: 0x1424e29a0-0x1424e2bb0 .text$mn
// MS2-RANGE: 0x1424e2c90-0x1424e2d20 .text$mn
// MS2-RANGE: 0x1424e2d80-0x1424e3020 .text$mn
// MS2-RANGE: 0x1424e3260-0x1424e3290 .text$mn
// MS2-RANGE: 0x1424e33f0-0x1424e3580 .text$mn
// MS2-RANGE: 0x1424e35e0-0x1424e3690 .text$mn
// MS2-RANGE: 0x1424e3830-0x1424e3bd0 .text$mn
// MS2-RANGE: 0x1424e3c30-0x1424e3cc0 .text$mn
// MS2-RANGE: 0x1424e3d60-0x1424e3e50 .text$mn
// MS2-RANGE: 0x1424e3eb0-0x1424e4290 .text$mn
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
#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp weak-ref bodies inline (as3_value.h)
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
#include "ms2/scaleform/include/gfx/as3/as3_support.h"
#undef GetObject

// VM: runs the queued code (unrecovered).

// vftables of the data_rdata unit (Sd_ structs there)
struct Sd_14317c488;
extern Sd_14317c488 DAT_14317c488;     // ShapeObject +0x18
struct Sd_14317c498;
extern Sd_14317c498 DAT_14317c498;     // ShapeObject +0x90
struct Sd_14317c560;
extern Sd_14317c560 DAT_14317c560;     // AvmBitmap
struct Sd_14317c7d8;
extern Sd_14317c7d8 DAT_14317c7d8;     // AvmBitmap +0x18
struct Sd_14317c7e8;
extern Sd_14317c7e8 DAT_14317c7e8;     // AvmBitmap +0x90

// global C++ helpers defined in other units
void FUN_1424dcce0(void* p);
void FUN_1424dcc30(void* p);
void FUN_1424dcdd0(void* p);
void FUN_1424aa0f0(void* p);            // Text::TextFormat::~TextFormat
namespace Scaleform { namespace GFx { namespace AS3 { class VM; class Multiname; }}}
bool FUN_142522a60(Scaleform::GFx::AS3::VM* vm, void* file);

// ArrayDataBase destructors the exe calls out of line (instantiated elsewhere)
namespace Scaleform {
typedef ArrayDataBase<GFx::AS3::SPtr<GFx::ASStringNode>, AllocatorLH<GFx::AS3::SPtr<GFx::ASStringNode>, 2>, ArrayDefaultPolicy> SfrAdbStr;
typedef ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, 340>, ArrayDefaultPolicy> SfrAdbNsSet;
typedef ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, 340>, ArrayDefaultPolicy> SfrAdbCtr;
typedef ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, 340>, ArrayDefaultPolicy> SfrAdbFile;
typedef ArrayDataBase<GFx::AS3::Abc::MethodBodyInfo::Exception, AllocatorLH<GFx::AS3::Abc::MethodBodyInfo::Exception, 340>, ArrayDefaultPolicy> SfrAdbExc;
typedef ArrayDataBase<ArrayLH_POD<UInt64, 338, ArrayDefaultPolicy>, AllocatorLH<ArrayLH_POD<UInt64, 338, ArrayDefaultPolicy>, 340>, ArrayDefaultPolicy> SfrAdbPod;
template<> SF_NOINLINE SfrAdbStr::~ArrayDataBase();      // 0x1424dc440
template<> SF_NOINLINE SfrAdbNsSet::~ArrayDataBase();      // 0x1424dc530
template<> SF_NOINLINE SfrAdbCtr::~ArrayDataBase();      // 0x1424dc5b0
template<> SF_NOINLINE SfrAdbFile::~ArrayDataBase();      // 0x1424dc6b0
template<> SF_NOINLINE SfrAdbExc::~ArrayDataBase();      // 0x1424dc800
template<> SF_NOINLINE SfrAdbPod::~ArrayDataBase();      // 0x1424dc3d0
typedef HashSetBase<GFx::AS3::SPtr<GFx::AS3::GASRefCountBase>, FixedSizeHash<GFx::AS3::SPtr<GFx::AS3::GASRefCountBase> >, FixedSizeHash<GFx::AS3::SPtr<GFx::AS3::GASRefCountBase> >, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::GASRefCountBase>, 2>, HashsetCachedEntry<GFx::AS3::SPtr<GFx::AS3::GASRefCountBase>, FixedSizeHash<GFx::AS3::SPtr<GFx::AS3::GASRefCountBase> >> > SfrHsGc;
typedef HashSetBase<GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript>, FixedSizeHash<GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript> >, FixedSizeHash<GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript> >, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript>, 2>, HashsetCachedEntry<GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript>, FixedSizeHash<GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript> >> > SfrHsGos;
typedef HashSetBase<Render::Text::TextFormatPtrWrapper<Render::Text::ParagraphFormat>, Render::Text::TextFormatPtrWrapper<Render::Text::ParagraphFormat>::HashFunctor, Render::Text::TextFormatPtrWrapper<Render::Text::ParagraphFormat>::HashFunctor, AllocatorLH<Render::Text::TextFormatPtrWrapper<Render::Text::ParagraphFormat>, 78>, HashsetCachedEntry<Render::Text::TextFormatPtrWrapper<Render::Text::ParagraphFormat>, Render::Text::TextFormatPtrWrapper<Render::Text::ParagraphFormat>::HashFunctor> > SfrHsPf;
typedef HashSetBase<Render::Text::TextFormatPtrWrapper<Render::Text::TextFormat>, Render::Text::TextFormatPtrWrapper<Render::Text::TextFormat>::HashFunctor, Render::Text::TextFormatPtrWrapper<Render::Text::TextFormat>::HashFunctor, AllocatorLH<Render::Text::TextFormatPtrWrapper<Render::Text::TextFormat>, 78>, HashsetCachedEntry<Render::Text::TextFormatPtrWrapper<Render::Text::TextFormat>, Render::Text::TextFormatPtrWrapper<Render::Text::TextFormat>::HashFunctor> > SfrHsTf;
template<> SF_NOINLINE SfrHsGc::~HashSetBase();      // 0x1424dd1a0
template<> SF_NOINLINE SfrHsGos::~HashSetBase();      // 0x1424dd250
template<> SF_NOINLINE SfrHsPf::~HashSetBase();      // 0x1424dd300
template<> SF_NOINLINE SfrHsTf::~HashSetBase();      // 0x1424dd3b0
} // namespace Scaleform

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

// @0x1424e6d90
void AvmDisplayObjContainer::AddChild(DisplayObjectBase* ch)
{
    if (ch->GetParent())
        AvmDisplayObjContainer::FromBase(static_cast<DisplayObjContainer*>(ch->GetParent())->GetAvmDispContainer())
            ->RemoveChild(ch);
    // the SDK's DisplayList::GetCount returns an unsigned
    DisplayList& dl = GetDisplayObjContainer()->mDisplayList;
    dl.AddEntryAtIndex(GetDisplayObjContainer(), unsigned(dl.GetCount()), ch);
    dl.Flags |= DisplayList::Flags_DepthToIndexInvalid | DisplayList::Flags_MayContainForeignElems;
    ch->pParent = GetDisplayObjContainer();
    ch->Depth   = -1;
    ch->SetUnloaded(false);
    ch->SetUnloading(false);
    if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsInPlayList())
        AvmInteractiveObj::FromBase(static_cast<InteractiveObject*>(ch)->GetAvmIntObj())->MoveBranchInPlayList();
    // the SDK's ToAvmDisplayObj(ch->CharToScriptableObject()): null-safe casts, then the call with no test
    DisplayObjectBase* const psobj = ch->IsScriptableObject() ? ch : NULL;
    static_cast<AvmDisplayObj*>(psobj ? psobj->GetAvmObjImpl() : NULL)->OnAdded(false);
}

// @0x1424e6e90
void AvmDisplayObjContainer::AddChildAt(DisplayObjectBase* ch, unsigned index)
{
    if (ch->GetParent())
        AvmDisplayObjContainer::FromBase(static_cast<DisplayObjContainer*>(ch->GetParent())->GetAvmDispContainer())
            ->RemoveChild(ch);
    // the SDK's DisplayList::GetCount returns an unsigned
    const unsigned count = unsigned(GetDisplayObjContainer()->mDisplayList.GetCount());
    if (index > count)
        index = count;
    GetDisplayObjContainer()->mDisplayList.AddEntryAtIndex(GetDisplayObjContainer(), index, ch);
    ch->pParent = GetDisplayObjContainer();
    ch->Depth   = -1;
    ch->SetUnloaded(false);
    ch->SetUnloading(false);
    if (ch->IsInteractiveObject() && static_cast<InteractiveObject*>(ch)->IsInPlayList())
        AvmInteractiveObj::FromBase(static_cast<InteractiveObject*>(ch)->GetAvmIntObj())->MoveBranchInPlayList();
    // the SDK's ToAvmDisplayObj(ch->CharToScriptableObject()): null-safe casts, then the call with no test
    DisplayObjectBase* const psobj = ch->IsScriptableObject() ? ch : NULL;
    static_cast<AvmDisplayObj*>(psobj ? psobj->GetAvmObjImpl() : NULL)->OnAdded(false);
}

// MovieRoot::AddStickyVariable: keeps name = val under path until its target exists (permanently for
// Movie::SV_Permanent, 2).
// @0x1424eab60
void Sfr21AddStickyVariable(MovieRoot* self, const ASString& path, const ASString& name, const Value& val,
                            int setType)
{
    if (name.GetSize() == 0)
        return;
    // the SDK reads pMovieImpl at each use (the exe keeps self, not the MovieImpl, in a register)
    MovieRoot::StickyVarNode* pnode = SF_HEAP_NEW(self->pMovieImpl->GetMovieHeap())
        MovieRoot::StickyVarNode(name, val, setType == 2);
    if (pnode)
        self->pMovieImpl->AddStickyVariableNode(path, pnode);
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

void FUN_142423b90(Value* v);   // Value::SetUndefined, out of line in the exe
__declspec(noinline) void* DeleteAs3_1424e2420(void* p, unsigned flags);   // ActionEntry's deleting dtor (below)

// @0x1424eae40
void MovieRoot::ActionQueueType::AddToFreeList(ActionEntry* pentry)
{
    // ActionEntry::ClearAction, with the exe's out-of-line SetUndefined (the SCU would inline it here)
    pentry->Type         = ActionEntry::Entry_None;
    pentry->pCharacter   = NULL;
    pentry->pAS3Obj      = NULL;
    pentry->CFunction    = NULL;
    FUN_142423b90(&pentry->Function);
    pentry->pNLoadInitCL = NULL;
    if (FreeEntriesCount < 50)
    {
        pentry->pNextEntry = pFreeEntry;
        pFreeEntry         = pentry;
        ++FreeEntriesCount;
    }
    else
        DeleteAs3_1424e2420(pentry, 1);   // delete pentry
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
        proot->pAVM->ExecuteCode(proot->ASFramesToExecute);
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
    ::new (pvoi) AS3ValueObjectInterface(NULL);
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
void* Sfr33IdWordHashGet(const UByte* self, const UPInt& key);       // 0x1425059f0
static inline void* FUN_1425059f0(const void* self, const UPInt& key) { return Sfr33IdWordHashGet(static_cast<const UByte*>(self), key); }
void FUN_1424d4220(void* self, void* pheapAddr, const void* nodeRef, UPInt hashValue);

// A use of pdefImpl: an entry already listed counts one more use; otherwise one is added (holding the definition)
// with a single use.
// MS2-FUNCTIONAL: register allocation only (exe keeps the key in rbx and copies it to rdi for the Ptr); the hash
// lookup and add are called through their exe addresses
// @0x1424e8e20
void MovieRoot::AddLoadedMovieDef(MovieDefImpl* pdefImpl)
{
    struct Info { Ptr<MovieDefImpl> pMovieDef; unsigned UseCnt; };
    struct NodeRef { MovieDefImpl* const* pFirst; const Info* pSecond; };
    // the key is the pointer itself: the lookup gets the parameter's address. The exe's lookup is a template
    // instance cl could see did not write the key; ours is an address call, so the copy keeps it in a register.
    MovieDefImpl* const def = pdefImpl;
    Info* pinfo = static_cast<Info*>(FUN_1425059f0(&LoadedMovieDefs, reinterpret_cast<const UPInt&>(pdefImpl)));
    if (pinfo)
    {
        ++pinfo->UseCnt;
        return;
    }
    Info info = { def, 1 };
    NodeRef ref = { &pdefImpl, &info };
    FUN_1424d4220(&LoadedMovieDefs, &LoadedMovieDefs, &ref, reinterpret_cast<UPInt>(pdefImpl));
}

// MovieRoot::AddInvokeAlias: maps alias to the closure invoked for it, creating the alias hash (+0x80) on first use.
// The AS3 MovieRoot header has no declaration, so it is a free function taking the root.
// @0x1424e8ae0
void Sfr21AddInvokeAlias(MovieRoot* self, const ASString& alias, const Value& closure)
{
    ASStringHash<Value>*& aliases = reinterpret_cast<ASStringHash<Value>*&>(self->pInvokeAliases);
    if (!aliases)
        aliases = SF_NEW ASStringHash<Value>();
    aliases->Set(alias, closure);
}

// ASRefCountCollector::AdvanceFrame: a movie's frame of the shared collector. A movie that has not seen the latest
// collection restarts its count; one behind the collector's frame count just counts. Otherwise the collector advances
// and collects when the roots outgrow the limit (or, every MaxFramesBetweenCollections frames, the preset count), then
// sets the next limit from the roots left (at least 0.7 of them, at least the peak).
// MS2-FUNCTIONAL: free function in place of the ASRefCountCollector member (not declared in as3_gc.h)
// @0x1424eaf80
void Sfr21ASGCAdvanceFrame(ASRefCountCollector* gc, unsigned* movieFrameCnt, unsigned* movieLastCollectFrame,
                           ASRefCountCollector::StatsObserver* statsObserver)
{
    if (*movieLastCollectFrame != gc->LastCollectionFrameNum)
    {
        *movieLastCollectFrame = gc->LastCollectionFrameNum;
        *movieFrameCnt = 1;
        return;
    }
    if (*movieFrameCnt < gc->FrameCnt)
    {
        ++*movieFrameCnt;
        return;
    }
    ++gc->TotalFramesCount;
    unsigned frames = ++gc->FrameCnt;
    const unsigned roots = (unsigned)gc->GetRootsCount();
    unsigned peak = roots;
    if (peak < gc->PeakRootCount)
        peak = gc->PeakRootCount;
    gc->PeakRootCount = peak;
    if (!gc->SuspendCnt &&
        ((gc->PresetMaxRootCount != 0 && roots > gc->MaxRootCount) ||
         (gc->MaxFramesBetweenCollections != 0 && frames >= gc->MaxFramesBetweenCollections &&
          roots > gc->PresetMaxRootCount)))
    {
        frames = 0;
        ASRefCountCollector::Stats stats;
        stats.pObserver = statsObserver;
        stats.RootsNumber = 0;
        stats.RootsFreedTotal = 0;
        gc->Collect(&stats);
        unsigned limit;
        if (gc->PresetMaxRootCount < stats.RootsFreedTotal)
        {
            gc->PeakRootCount = roots;
            limit = gc->PresetMaxRootCount;
            peak = roots;
        }
        else
        {
            limit = gc->MaxRootCount;
            peak = gc->PeakRootCount;
        }
        gc->FrameCnt = 0;
        gc->LastPeakRootCount = peak;
        gc->LastCollectedRoots = stats.RootsFreedTotal;
        unsigned left = roots - stats.RootsFreedTotal;
        if (left < limit)
            left = limit;
        const unsigned scaled = (unsigned)(SInt64)((double)left * 0.7);
        if (peak < scaled)
            left = scaled;
        gc->MaxRootCount = left;
        gc->LastCollectionFrameNum = gc->TotalFramesCount;
        frames = gc->FrameCnt;
    }
    gc->LastRootCount = roots;
    *movieFrameCnt = frames;
    *movieLastCollectFrame = gc->LastCollectionFrameNum;
}

void Sfr33CollectorQueue(UByte* gc, RefCountImpl* stats);            // 0x142504630, ASRefCountCollector::ForceCollect
static inline void FUN_142504630(ASRefCountCollector* gc, void* stats) { Sfr33CollectorQueue(reinterpret_cast<UByte*>(gc), static_cast<RefCountImpl*>(stats)); }

// MovieRoot::AdvanceFrame: until the main movie's loader events are done, fires its loaderInfo init (once), progress
// (each full frame, or once loading has finished) and complete events. An invalidated stage gets its RENDER events run
// right away. A full frame runs a collection System.gc scheduled, then advances the collector.
// MS2-FUNCTIONAL: the scheduled collection is called through its exe address
// @0x1424eb2f0
void MovieRoot::AdvanceFrame(bool nextFrame)
{
    void* advanceStats = *reinterpret_cast<void* const*>(&pMovieImpl->pAdvanceStats);
    if (!(MainLoaderInfoEventsState & 2))
    {
        MovieDefImpl* md = pMovieImpl->pMainMovie->GetResourceMovieDef();
        DisplayObjContainer* rt = GetRootMovie418(NULL);
        SPtr<Instances::fl_display::DisplayObject> as3obj = ToAvmDisplayObj(AsDisplayObject(rt))->GetAS3Obj();
        if (as3obj && as3obj->HasLoaderInfo())
        {
            if (!(MainLoaderInfoEventsState & 1))
            {
                as3obj->pLoaderInfo->ExecuteInitEvent(reinterpret_cast<GFx::DisplayObject*>(rt));
                MainLoaderInfoEventsState |= 1;
            }
            const bool loadingFinished = md->GetLoadingFrame() >= md->GetFrameCount();
            if (nextFrame || loadingFinished)
                as3obj->pLoaderInfo->ExecuteProgressEvent(md->pBindData->GetBytesLoaded(),
                                                          md->GetDataDef()->GetFileBytes());
            if (loadingFinished)
            {
                as3obj->pLoaderInfo->ExecuteCompleteEvent();
                MainLoaderInfoEventsState |= 2;
            }
        }
        else
            MainLoaderInfoEventsState |= 2;
    }
    if (StageInvalidated)
    {
        reinterpret_cast<EventChains*>(&mEventChains)->QueueEvents(static_cast<EventId::IdCode>(0x1000013));   // Event_Render
        DoActions();
        StageInvalidated = false;
    }
    if (nextFrame)
    {
        ASRefCountCollector* gc = MemContext->ASGC;
        if (gc)
        {
            if (gc->CollectionScheduledFlags)
            {
                gc->CollectionScheduledFlags = 0;
                FUN_142504630(gc, advanceStats);
            }
            Sfr21ASGCAdvanceFrame(gc, &NumAdvancesSinceCollection, &LastCollectionFrame,
                                  static_cast<ASRefCountCollector::StatsObserver*>(advanceStats));
        }
    }
}

// AvmSprite::AdvanceFrame: drags the sprite with the mouse; on a full frame (unless its frame is already queued) a
// playing sprite moves on, and a new frame runs its init actions and frame tags, flags the frame for execution and
// puts the sprite back on the optimized play list. Looping back to frame 0 unloads the marked children.
// @0x1424eb130
void AvmSprite::AdvanceFrame(bool nextFrame, float framePos)
{
    SF_UNUSED(framePos);
    Ptr<Sprite> spr = GetSprite();
    if (spr->IsAdvanceDisabled() || spr->IsUnloading())
        return;
    if (GetMovieImpl()->IsMouseSupportEnabled())
        spr->DoMouseDrag();
    if (nextFrame && !(SprFlags & Flag_NeedExecuteFrame))
    {
        unsigned currentFrame = spr->GetCurrentFrame();
        if (spr->GetPlayState() == State_Playing)
        {
            const unsigned currentFrame0 = currentFrame;
            spr->IncrementFrameAndCheckForLoop();
            currentFrame = spr->GetCurrentFrame();
            if (currentFrame != currentFrame0)
            {
                ExecuteInitActionFrameTags(currentFrame);
                spr->ExecuteFrameTags(currentFrame);
                SprFlags |= Flag_NeedExecuteFrame;
                if (GetSprite()->IsInPlayList())
                    GetSprite()->AddToOptimizedPlayList();
            }
        }
        if (currentFrame == 0)
            GetSprite()->mDisplayList.UnloadMarkedObjects(GetSprite());
    }
}

// Add: the "+" operator. Two XML objects are joined by the VM's XML support; with a string operand both sides are
// concatenated as strings; two other primitives are summed as numbers; anything else is first made primitive.
// MS2-FUNCTIONAL: functional recovery
// @0x1424e5f50
CheckResult Add(StringManager& sm, Value& result, const Value& l, const Value& r)
{
    if (l.IsObject() && r.IsObject() && l.GetObject() && r.GetObject())
    {
        Object* obj = l.GetObject();
        const XMLSupport& xmls = obj->GetVM().GetXMLSupport();
        if (xmls.Add(result, *l.GetObject(), *r.GetObject()))
            return true;
    }

    if (l.IsString() || r.IsString())
    {
        ASString left(sm.CreateEmptyString());
        ASString right(sm.CreateEmptyString());
        if (l.Convert2String(left) && r.Convert2String(right))
        {
            result = left + right;
            return true;
        }
        return false;
    }

    if (l.IsPrimitive() && r.IsPrimitive())
    {
        Value::Number lnum = 0.0;
        Value::Number rnum = 0.0;
        if (l.Convert2NumberInline(lnum) && r.Convert2NumberInline(rnum))
        {
            result.SetNumber(lnum + rnum);
            return true;
        }
        return false;
    }

    Value lprim;
    Value rprim;
    if (l.Convert2PrimitiveValueUnsafe(lprim) && r.Convert2PrimitiveValueUnsafe(rprim))
        return Add(sm, result, lprim, rprim);
    return false;
}

// (sfr21) Slots keeps its table edits protected; the free AddInterfaceSlots below reaches them through this view.
struct Sfr21SlotsAccess : Slots
{
    using Slots::Add;
    using Slots::FindSlotInfoIndex;
    using Slots::FindAddOwnSlotInfo;
};

ClassTraits::Traits** Sfr33ClassTraitsCacheGet(TClassTraitsCache* hash, const Multiname& mn);   // 0x142505aa0, MultinameHash::Get
const ClassTraits::Traits* FUN_14250d760(VM& vm, const Multiname& mn);                // the traits that define mn
}}} // namespace Scaleform::GFx::AS3
void* FUN_142501310(Scaleform::GFx::AS3::VM& vm, void* scope, const Scaleform::GFx::AS3::Multiname& mn); // class traits of mn on one scope
namespace Scaleform { namespace GFx { namespace AS3 {
void FUN_14252ecb0(VM* vm, const VM::Error* error, const void* classInfo);            // raise as an instance of the class
namespace fl { extern const ClassInfo VerifyErrorCI; }

// A slot namespace sns answers to ns: same kind, protected ones by kind alone, private ones by identity, the rest by
// uri.
static bool Sfr21SlotNsMatches(const Instances::Namespace& sns, const Instances::Namespace& ns)
{
    if (sns.GetKind() != ns.GetKind())
        return false;
    if (sns.GetKind() == Abc::NS_Protected)
        return true;
    return sns.GetKind() == Abc::NS_Private ? &sns == &ns : sns.GetUri().GetNode() == ns.GetUri().GetNode();
}

// The slot of self named name in namespace ns (own or a parent's), or -1.
static SPInt Sfr21FindSlotByNs(const Traits& self, const ASString& name, const Instances::Namespace& ns)
{
    const UInt32* first = self.FindSlotValues(name);
    if (!first)
        return -1;
    for (SPInt ind = *first; ind >= 0; ind = self.GetPrevSlotIndex(ind))
    {
        if (Sfr21SlotNsMatches(*self.GetSlotInfo(AbsoluteIndex(ind)).pNs, ns))
            return ind;
    }
    return -1;
}

// Traits::AddInterfaceSlots: for every interface the ABC class implements (its instance traits, then the parent
// interfaces), each interface slot not yet present gets an alias of the public slot of that name, or for an
// interface class a copy bound to the interface's methods. VerifyError 1014 for an unknown interface, 1122 when a
// class does not implement an interface method.
// MS2-FUNCTIONAL: free function in place of the Traits member (not declared in as3_obj.h)
// @0x1424e80f0
void Sfr21AddInterfaceSlots(Traits* self, VMAbcFile& file, const Abc::ClassInfo& info)
{
    VM& vm = self->GetVM();
    Sfr21SlotsAccess& slots = static_cast<Sfr21SlotsAccess&>(static_cast<Slots&>(*self));
    const Abc::Instance::Interfaces& ifaces = info.inst_info.implemented_interfaces;
    for (UPInt i = 0; i < ifaces.info.GetSize(); ++i)
    {
        Multiname mn(file, file.GetAbcFile().Const_Pool.GetMultiname(ifaces.info[i]));

        ClassTraits::Traits* ctr = NULL;
        if (mn.IsAnyType())
            ctr = vm.TraitsClassClass;
        else
        {
            ClassTraits::Traits** pctr = Sfr33ClassTraitsCacheGet(&vm.ClassTraitsSet, mn);
            ctr = pctr ? *pctr : NULL;
        }
        if (!ctr)
        {
            const Traits* owner = reinterpret_cast<const Traits*>(FUN_14250d760(vm, mn));
            const VMAbcFile* ownerFile = owner ? owner->GetFilePtr() : NULL;
            for (UPInt g = vm.GlobalObjects.GetSize(); g != 0; --g)
            {
                const Traits& scope = reinterpret_cast<Object*>(vm.GlobalObjects[g - 1].GetPtr())->GetTraits();
                if (owner && ownerFile != scope.GetFilePtr())
                    continue;
                ctr = static_cast<ClassTraits::Traits*>(::FUN_142501310(vm, const_cast<Traits*>(&scope), mn));
                if (ctr)
                    break;
            }
        }
        InstanceTraits::Traits* itr = ctr ? ctr->ITraits.GetPtr() : NULL;
        if (!itr)
        {
            VM::Error err(static_cast<VM::ErrorID>(1014), vm, mn.Name);
            FUN_14252ecb0(&vm, &err, &fl::VerifyErrorCI);
            return;
        }

        const AS3::Traits& it = *itr;
        for (UPInt s = 0; s < it.GetSlotInfoNum(); ++s)
        {
            ASString name(it.GetSlotNameNode(AbsoluteIndex(s)));
            const SlotInfo& isi = it.GetSlotInfo(AbsoluteIndex(s));
            const Instances::Namespace& ins = *isi.pNs;
            if (Sfr21FindSlotByNs(*self, name, ins) >= 0)
                continue;

            const AbsoluteIndex pub = slots.FindSlotInfoIndex(name, vm.GetPublicNamespace());
            if (pub.Get() >= 0)
            {
                // Alias the public slot under the interface namespace.
                SlotInfo alias(self->GetSlotInfo(pub));
                alias.pNs = isi.pNs;
                slots.Add(name, alias);
                continue;
            }
            if (!info.inst_info.IsInterface())
            {
                VM::Error err(static_cast<VM::ErrorID>(1122), vm, name.ToCStr());
                FUN_14252ecb0(&vm, &err, &fl::VerifyErrorCI);
                return;
            }

            // An interface method: mark its namespace and copy the slot, bound to the interface's methods.
            const SlotInfo::BindingType bt = static_cast<SlotInfo::BindingType>(isi.BindType);
            *reinterpret_cast<UPInt*>(reinterpret_cast<char*>(const_cast<Instances::Namespace*>(&ins)) + 0x20) |= 0x10;
            SPInt ind = Sfr21FindSlotByNs(*self, name, ins);
            if (ind < 0)
                ind = slots.Add(name, isi).Get();
            SlotInfo& si = self->GetOwnSlotInfo(AbsoluteIndex(ind));
            ASString siName(si.Name.GetPtr());
            const VTable& ivt = itr->GetVT();
            switch (bt)
            {
            case SlotInfo::BT_Code:
            case SlotInfo::BT_Get:
                si.Bind(bt, self->GetVT().AddMethod(ivt.VTMethods[isi.ValueInd], bt, siName));
                break;
            case SlotInfo::BT_Set:
                si.Bind(SlotInfo::BT_Set,
                        self->GetVT().AddMethod(ivt.VTMethods[isi.ValueInd + 1], SlotInfo::BT_Set, siName));
                break;
            case SlotInfo::BT_GetSet:
                si.Bind(SlotInfo::BT_Get,
                        self->GetVT().AddMethod(ivt.VTMethods[isi.ValueInd], SlotInfo::BT_Get, siName));
                si.Bind(SlotInfo::BT_Set,
                        self->GetVT().AddMethod(ivt.VTMethods[isi.ValueInd + 1], SlotInfo::BT_Set, siName));
                break;
            default:
                break;
            }
        }

        // The parent interface of an ABC interface (InstanceTraits::UserDefined keeps its ClassInfo at +0xd8).
        const AS3::Traits* parent = itr->GetParent();
        if (parent && parent->IsAbcObject())
            Sfr21AddInterfaceSlots(self, file,
                                   **reinterpret_cast<const Abc::ClassInfo* const*>(
                                       reinterpret_cast<const char*>(parent) + 0xd8));
    }
}

class Tracer;

// TClassTraitsCache::Add, out of line (MultinameHash::Add is inline in the header; a free function at its exe
// address). The value is taken by const reference, as the SDK's Add does.
// @0x1424e5e80
void FUN_1424e5e80(TClassTraitsCache* self, const ASString& name, const Instances::Namespace& ns,
                   ClassTraits::Traits* const& v)
{
    self->Add(name, ns, v);
}

// An ArrayLH<SPtr<Instances::Namespace> > at +0x20 grown by one namespace (the exe's Resize calls the Namespace
// DestructArray 0x1424094f0 and Reserve 0x14241f880). No caller or reference is left in the exe.
// @0x1424e62f0
void FUN_1424e62f0(void* self, Instances::Namespace* p)
{
    reinterpret_cast<ArrayLH<SPtr<Instances::Namespace> >*>(static_cast<char*>(self) + 0x20)
        ->PushBack(SPtr<Instances::Namespace>(p));
}

// TR::Block (0x28 bytes, Tracer heap): a ListNode, then the block's flags, type, entry state and code offset.
struct Sfr21TrBlock
{
    Sfr21TrBlock* pPrev;    // +0x00
    Sfr21TrBlock* pNext;    // +0x08
    UInt32        Flags;    // +0x10 bit 0: not dead
    UInt32        Type;     // +0x14 1: tDead
    void*         pState;   // +0x18 TR::State*, NULL until the block is reached
    UPInt         From;     // +0x20
};

// TR::State's members are private (as3_readargs.h): the same layout, for the copy.
struct Sfr21TrState
{
    void*          pTracer;     // +0x00
    UPInt          BCP;         // +0x08
    UPInt          OpcodeCP;    // +0x10
    ArrayDH<Value> Registers;   // +0x18
    ArrayDH<Value> OpStack;     // +0x38
    ArrayDH<Value> ScopeStack;  // +0x58
    UInt8*         RegChanged;  // +0x78
    UInt32         BitCount;    // +0x80
};

// The last block (walking back from the list's end) that starts at or before from.
static Sfr21TrBlock* Sfr21TracerGetBlock(Tracer* self, UPInt from)
{
    Sfr21TrBlock* block = *reinterpret_cast<Sfr21TrBlock**>(reinterpret_cast<char*>(self) + 0x110);
    while (block && from < block->From)
        block = block->pPrev;
    return block;
}

// The SDK's SF_HEAP_NEW of a Block (whose ctor sets the not-dead bit): the heap new is non-throwing, so the
// ctor runs only on a non-NULL allocation.
struct Sfr21NewTrBlock : Sfr21TrBlock
{
    Sfr21NewTrBlock(UPInt f, UInt32 type, void* st) { Flags |= 1; Type = type; pState = st; From = f; }
    void* operator new(size_t size, MemoryHeap* heap) throw() { return heap->Alloc(size, (const AllocInfo*)0); }
    void operator delete(void*, MemoryHeap*) {}
};

static void Sfr21InsertBlockAfter(Sfr21TrBlock* block, Sfr21TrBlock* node)
{
    node->pPrev = block->pNext->pPrev;
    node->pNext = block->pNext;
    block->pNext->pPrev = node;
    block->pNext = node;
}

// Tracer::AddBlock(st, from, type, checkOpCode): the block starting at from with a copy of st as its entry state
// (NULL past the code's end). A label or debug opcode at from keeps a tDead block alive.
// MS2-FUNCTIONAL: Tracer members private; raw offsets
// @0x1424e6aa0
void* FUN_1424e6aa0(Tracer* self, const void* st, UPInt from, int type, bool checkOpCode)
{
    char* t = reinterpret_cast<char*>(self);
    if (from >= *reinterpret_cast<UPInt*>(t + 0x58))
        return NULL;

    bool is_dead = type == 1;
    Sfr21TrBlock* block = Sfr21TracerGetBlock(self, from);
    bool onlyCreateState = false;
    if (block && from == block->From)
    {
        if (block->pState)
            return block;
        onlyCreateState = true;
    }

    if (checkOpCode)
    {
        const UInt8 op = (*reinterpret_cast<const UInt8**>(t + 0x50))[from];
        if (op == 9 || (op >= 0xef && op <= 0xf1))   // op_label, op_debug, op_debugline, op_debugfile
            is_dead = false;
    }

    MemoryHeap* heap = *reinterpret_cast<MemoryHeap**>(t + 0x18);
    const Sfr21TrState& src = *static_cast<const Sfr21TrState*>(st);
    Sfr21TrState* state = static_cast<Sfr21TrState*>(heap->Alloc(sizeof(Sfr21TrState), (const AllocInfo*)0));
    if (state)
    {
        state->pTracer  = src.pTracer;
        state->BCP      = src.BCP;
        state->OpcodeCP = src.OpcodeCP;
        ::new (&state->Registers) ArrayDH<Value>(src.Registers);
        ::new (&state->OpStack) ArrayDH<Value>(src.OpStack);
        ::new (&state->ScopeStack) ArrayDH<Value>(src.ScopeStack);
        state->BitCount = src.BitCount;
        const UPInt bytes = (src.BitCount + 7) >> 3;
        AllocInfo info(0x155, 0, 0);
        state->RegChanged = static_cast<UInt8*>(
            Memory::pGlobalHeap->GetAllocHeap(src.RegChanged)->Alloc(bytes, &info));
        memcpy(state->RegChanged, src.RegChanged, bytes);
    }
    reinterpret_cast<ArrayDH<void*>*>(t + 0xf0)->PushBack(state);

    if (type == 1 && !is_dead)
        type = 0;

    if (onlyCreateState)
    {
        block->Type |= type;
        block->pState = state;
        return block;
    }

    Sfr21TrBlock* node = new (heap) Sfr21NewTrBlock(from, type, state);
    Sfr21InsertBlockAfter(block, node);
    if (type == 1)
        node->Flags &= ~1u;
    return node;
}

// Tracer::AddBlock(from): a block (without a state yet) starting at from, unless one already does.
// @0x1424e6cf0
void FUN_1424e6cf0(Tracer* self, UPInt from)
{
    Sfr21TrBlock* block = Sfr21TracerGetBlock(self, from);
    if (block && from == block->From)
        return;

    MemoryHeap* heap = *reinterpret_cast<MemoryHeap**>(reinterpret_cast<char*>(self) + 0x18);
    Sfr21TrBlock* node = new (heap) Sfr21NewTrBlock(from, 0, NULL);
    Sfr21InsertBlockAfter(block, node);
}

// ---- scalar deleting destructors whose classes are not recovered (or whose destructors are inlined elsewhere) ----
// The exe's destructor helpers, called through their addresses.
extern "C" {
void FUN_1423dfa20(void* p);            // RefCountBaseGC::ReleaseInternal
void FUN_142521f00(void* v);            // Value::ReleaseInternal
void FUN_1424dc350(void* p);
void FUN_1424dc260(void* p);
void FUN_1424dd500(void* p);            // ASVM::~ASVM
void FUN_1425456e0(void* p);            // Abc::File::~File
void FUN_14257eb30(void* p);
void FUN_1424f6d50(void* begin, void* end); // Value array destruct
void FUN_1424dc630(void* p);
void FUN_1424de650(void* p);            // MovieRoot::~MovieRoot
void FUN_1423f0720(void* p);            // ArrayDataBase<SPtr<Namespace>,..,2> dtor (already instantiated here)
void FUN_142626160(void* p);
void FUN_1424df070(void* p);            // Tracer::~Tracer
void FUN_1424df220(void* p);            // ClassTraits::Traits::~Traits
void FUN_1424df380(void* p);            // VM::~VM
void FUN_1424ef5b0(void* p);
void FUN_1424dcf10(void* p);
}

static inline char* Sfr21At(void* p, UPInt off) { return static_cast<char*>(p) + off; }
static inline void* Sfr21Mem(void* p, UPInt off) { return *reinterpret_cast<void**>(Sfr21At(p, off)); }
// The base vftables the inlined base destructors store before the out-of-line base destructor runs.
extern const void* DAT_14313f368[];     // RefCountBaseGC<323>
extern const void* DAT_14317bf80[];     // AvmDisplayObjBase
extern const void* DAT_14317ca60[];     // AvmInteractiveObj
extern const void* DAT_14317c9f8[];     // RefCountBase<ASIntervalTimerIntf, 323>
extern const void* DAT_14317b798[];     // FileLoader
extern const void* DAT_14317c9e0[];     // GFx::MovieDefRootNode
extern const void* DAT_14317b7b8[];     // XMLSupport
extern const void* DAT_14317afe8[];     // empty interface (0x1424e2e70)
extern const void* DAT_14317b040[];     // RefCountCollector<323>
extern const void* DAT_14317b750[];     // VMAbcFile
extern const void* DAT_14317bc40[];     // TreeShape::NodeData
extern const void* DAT_14317bde0[];     // ASMovieRootBase
// ShapeObject (79 slots, data_rdata_sf_b). Not a DAT_14317c210 extern: that name binds to sfr_as3_15's one-slot
// ??_7ShapeObject view table in the fullexe.
extern void* const ShapeObject_vftable[];
extern const void* DAT_14317c9d0[];     // Text::Allocator
extern const void* DAT_14317d220[];     // Stage
extern const void* DAT_14317d5f0[];     // Stage +0x18
extern const void* DAT_14317d8a8[];     // ASVM::AbcFileWithMovieDef
extern const void* DAT_14317d8c0[];     // AS3::MovieDefRootNode
extern const void* DAT_14317de60[];     // AvmLoader
extern const void* DAT_14317e228[];     // AvmLoader +0x18
extern const void* DAT_14317e330[];     // AvmLoader +0x140
extern const void* DAT_14317e3e8[];     // AvmLoader +0x150
extern const void* DAT_14317f778[];     // Classes::UDBase
extern const void* DAT_14317f848[];     // empty class (0x1424e2c90, 0x1424e3a00)
extern const void* DAT_14317f9e0[];     // XMLSupportImpl
static inline void Sfr21GVft(void* p, UPInt off, const void* const* vft)
{
    *reinterpret_cast<const void* const**>(Sfr21At(p, off)) = vft;
}
// the AvmInteractiveObj part's inlined destructor in front of ~AvmDisplayObj
static void Sfr21GAvmInteractive(void* p)
{
    Sfr21GVft(p, 0x40, DAT_14317bf80);
    Sfr21GVft(p, 0x30, DAT_14317bf80);
    Sfr21GVft(p, 0, DAT_14317ca60);
    static_cast<Scaleform::GFx::AS3::AvmDisplayObj*>(p)->Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj();
}
// flags & 4 is a ::delete through the deleting dtor: the global sized delete, not the class's heap Free
static void Sfr21GFree(void* p, unsigned flags, UPInt size)
{
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::pGlobalHeap->Free(p);
        else
            ::operator delete(p, size);
    }
}
// the in-place Avm* objects: their class operator delete does nothing, so only a ::delete frees them
static void Sfr21GInPlaceFree(void* p, unsigned flags, UPInt size)
{
    if ((flags & 5) == 5)
        ::operator delete(p, size);
}
static void Sfr21GPtr(void* p, UPInt off)    { if (void* m = Sfr21Mem(p, off)) reinterpret_cast<Scaleform::RefCountImpl*>(m)->Release(); }
static void Sfr21GPtrNTS(void* p, UPInt off) { if (void* m = Sfr21Mem(p, off)) reinterpret_cast<const Scaleform::RefCountNTSImpl*>(m)->Release(); }
static void Sfr21GRes(void* p, UPInt off)    { if (void* m = Sfr21Mem(p, off)) reinterpret_cast<Scaleform::GFx::Resource*>(m)->Release(); }
// virtual Release (slot 2) of an interface member
static void Sfr21GVRel(void* p, UPInt off)
{
    if (void* m = Sfr21Mem(p, off))
        (*reinterpret_cast<void (***)(void*)>(m))[2](m);
}
// SPtr<GASRefCountBase>: tagged (bit 0) pointers are weak; the count lives in the low 22 bits of +0x10
static void Sfr21GSPtr(void* p, UPInt off)
{
    reinterpret_cast<SPtr<GASRefCountBase>*>(Sfr21At(p, off))->~SPtr();
}
// Value: object kinds (>9) release their reference; weak references drop the shared counter
static void Sfr21GValue(void* p, UPInt off)
{
    reinterpret_cast<Value*>(Sfr21At(p, off))->~Value();
}
static void Sfr21GCollector(void* p)
{
    static_cast<Scaleform::GFx::AS3::ASRefCountCollector*>(p)->Collect(0);
    Sfr21GPtr(p, 0x80);
    FUN_1424dcce0(Sfr21At(p, 0x70));
    Sfr21GVft(p, 0x48, DAT_14313f368);
    static_cast<Scaleform::GFx::AS3::ASRefCountCollector*>(p)->Roots.ClearAndRelease();
    static_cast<Scaleform::RefCountImplCore*>(p)->Scaleform::RefCountImplCore::~RefCountImplCore();
}
static void Sfr21GShapeData(void* p)
{
    FUN_1424dc350(Sfr21At(p, 0x30));
    FUN_1424dc260(Sfr21At(p, 0x18));
    static_cast<Scaleform::RefCountImplCore*>(p)->Scaleform::RefCountImplCore::~RefCountImplCore();
}
static void Sfr21GNodeData(void* p)
{
    if (Sfr21Mem(p, 0x40))
        FUN_142626160(Sfr21At(p, 0x40));
    FUN_14257eb30(p);
}

// ASRefCountCollector
// @0x1424e2290
void* DeleteAs3_1424e2290(void* p, unsigned flags) { Sfr21GVft(p, 0, DAT_14317b040); Sfr21GCollector(p); Sfr21GFree(p, flags, 0xb8); return p; }

// @0x1424e2420
void* DeleteAs3_1424e2420(void* p, unsigned flags)
{
    Sfr21GPtr(p, 0x60);
    Sfr21GValue(p, 0x38);
    Sfr21GSPtr(p, 0x18);
    Sfr21GPtrNTS(p, 0x10);
    Sfr21GFree(p, flags, 0x68);
    return p;
}

// Text::Allocator
// @0x1424e2520
void* DeleteAs3_1424e2520(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, DAT_14317c9d0);
    FUN_1424aa0f0(Sfr21At(p, 0x38));
    reinterpret_cast<Scaleform::SfrHsPf*>(Sfr21At(p, 0x18))->~HashSetBase();
    reinterpret_cast<Scaleform::SfrHsTf*>(Sfr21At(p, 0x10))->~HashSetBase();
    static_cast<Scaleform::RefCountNTSImplCore*>(p)->Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore();
    Sfr21GFree(p, flags, 0x88);
    return p;
}

// InstanceTraits::Anonimous
// @0x1424e25b0
void* DeleteAs3_1424e25b0(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::InstanceTraits::CTraits*>(p)->Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(); Sfr21GFree(p, flags, 0xe8); return p; }

// AvmBitmap
// @0x1424e2610
void* DeleteAs3_1424e2610(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, reinterpret_cast<const void* const*>(&::DAT_14317c560));
    Sfr21GVft(p, 0x18, reinterpret_cast<const void* const*>(&::DAT_14317c7d8));
    Sfr21GVft(p, 0x90, reinterpret_cast<const void* const*>(&::DAT_14317c7e8));
    *Sfr21At(p, 0x6d) = 0;
    Sfr21GRes(p, 0xc8);
    Sfr21GRes(p, 0xc0);
    reinterpret_cast<Scaleform::GFx::AS3::AvmDisplayObj*>(Sfr21At(p, 0x90))->Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj();
    static_cast<Scaleform::GFx::DisplayObject*>(p)->Scaleform::GFx::DisplayObject::~DisplayObject();
    Sfr21GFree(p, flags, 0xd0);
    return p;
}

// AvmInteractiveObj-family wrappers: never heap-freed (the sized-delete path only)
// MS2-FUNCTIONAL: scalar deleting destructor calling the exe's out-of-line ~AvmDisplayObj through its address
// @0x1424e26d0
void* DeleteAs3_1424e26d0(void* p, unsigned flags) { Sfr21GAvmInteractive(p); Sfr21GInPlaceFree(p, flags, 0x48); return p; }

// @0x1424e2760
void* DeleteAs3_1424e2760(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::AvmDisplayObj*>(p)->Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(); Sfr21GInPlaceFree(p, flags, 0x30); return p; }

// MS2-FUNCTIONAL: scalar deleting destructor calling the exe's out-of-line ~AvmDisplayObj through its address
// @0x1424e27d0
void* DeleteAs3_1424e27d0(void* p, unsigned flags) { Sfr21GAvmInteractive(p); Sfr21GInPlaceFree(p, flags, 0x48); return p; }

// @0x1424e29a0
void* DeleteAs3_1424e29a0(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::AvmSprite*>(p)->Scaleform::GFx::AS3::AvmSprite::~AvmSprite(); Sfr21GInPlaceFree(p, flags, 0x68); return p; }

// MS2-FUNCTIONAL: scalar deleting destructor calling the exe's out-of-line ~AvmDisplayObj through its address
// @0x1424e2a10
void* DeleteAs3_1424e2a10(void* p, unsigned flags) { Sfr21GAvmInteractive(p); Sfr21GInPlaceFree(p, flags, 0x48); return p; }

// MS2-FUNCTIONAL: scalar deleting destructor calling the exe's out-of-line ~AvmDisplayObj through its address
// @0x1424e2ac0
void* DeleteAs3_1424e2ac0(void* p, unsigned flags) { Sfr21GAvmInteractive(p); Sfr21GInPlaceFree(p, flags, 0x48); return p; }

// InstanceTraits::CTraits
// @0x1424e2b50
void* DeleteAs3_1424e2b50(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::InstanceTraits::CTraits*>(p)->Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(); Sfr21GFree(p, flags, 0xe8); return p; }

// @0x1424e2c90
void* DeleteAs3_1424e2c90(void* p, unsigned flags) { Sfr21GVft(p, 0, DAT_14317f848); Sfr21GFree(p, flags, 0x10); return p; }

// ContextImpl::EntryData
// @0x1424e2ce0
void* DeleteAs3_1424e2ce0(void* p, unsigned flags)
{
    FUN_14257eb30(p);
    if (flags & 1)
        ::operator delete(p, 0x10);
    return p;
}

// an empty interface (8 bytes), operator delete
// @0x1424e2d80
void* DeleteAs3_1424e2d80(void* p, unsigned flags) { Sfr21GVft(p, 0, DAT_14317b798); if (flags & 1) ::operator delete(p, 8); return p; }

// @0x1424e2e70
void* DeleteAs3_1424e2e70(void* p, unsigned flags) { Sfr21GVft(p, 0, DAT_14317afe8); if (flags & 1) ::operator delete(p, 8); return p; }

// TextImageDesc
// @0x1424e2ea0
void* DeleteAs3_1424e2ea0(void* p, unsigned flags)
{
    Sfr21GVRel(p, 0x10);
    static_cast<Scaleform::RefCountNTSImplCore*>(p)->Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore();
    Sfr21GFree(p, flags, 0x50);
    return p;
}

// IntervalTimer
// @0x1424e2f10
void* DeleteAs3_1424e2f10(void* p, unsigned flags)
{
    FUN_1424f6d50(Sfr21Mem(p, 0x38), Sfr21Mem(p, 0x40));
    Memory::pGlobalHeap->Free(Sfr21Mem(p, 0x38));
    Sfr21GSPtr(p, 0x30);
    Sfr21GValue(p, 0x10);
    Sfr21GVft(p, 0, DAT_14317c9f8);
    static_cast<Scaleform::RefCountImplCore*>(p)->Scaleform::RefCountImplCore::~RefCountImplCore();
    Sfr21GFree(p, flags, 0x70);
    return p;
}

// @0x1424e3260
void* DeleteAs3_1424e3260(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, DAT_14317b798);
    if (flags & 1)
        ::operator delete(p, 8);
    return p;
}

// MovieRoot
// @0x1424e33f0
void* DeleteAs3_1424e33f0(void* p, unsigned flags) { FUN_1424de650(p); Sfr21GFree(p, flags, 0x6f8); return p; }

// NamespaceSet
// @0x1424e3450
void* DeleteAs3_1424e3450(void* p, unsigned flags)
{
    FUN_1423f0720(Sfr21At(p, 0x20));
    static_cast<Scaleform::GFx::AS3::GASRefCountBase*>(p)->Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase();
    Sfr21GFree(p, flags, 0x38);
    return p;
}

// TreeNode::NodeData
// @0x1424e34c0
void* DeleteAs3_1424e34c0(void* p, unsigned flags)
{
    Sfr21GNodeData(p);
    if (flags & 1)
        ::operator delete(p, 0x90);
    return p;
}

// TreeShape::NodeData
// @0x1424e3510
void* DeleteAs3_1424e3510(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, DAT_14317bc40);
    if (char* s = static_cast<char*>(Sfr21Mem(p, 0x90)))
        (*reinterpret_cast<void (***)(void*)>(s + 0x10))[2](s + 0x10);
    Sfr21GNodeData(p);
    if (flags & 1)
        ::operator delete(p, 0xa0);
    return p;
}

// InstanceTraits::Prototype
// @0x1424e3630
void* DeleteAs3_1424e3630(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::InstanceTraits::CTraits*>(p)->Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(); Sfr21GFree(p, flags, 0xe8); return p; }

// ShapeObject
// @0x1424e3890
void* DeleteAs3_1424e3890(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, ShapeObject_vftable);
    Sfr21GVft(p, 0x18, reinterpret_cast<const void* const*>(&::DAT_14317c488));
    Sfr21GVft(p, 0x90, reinterpret_cast<const void* const*>(&::DAT_14317c498));
    *Sfr21At(p, 0x6d) = 0;
    Sfr21GPtrNTS(p, 0xc8);
    Sfr21GRes(p, 0xc0);
    reinterpret_cast<Scaleform::GFx::AS3::AvmDisplayObj*>(Sfr21At(p, 0x90))->Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj();
    static_cast<Scaleform::GFx::DisplayObject*>(p)->Scaleform::GFx::DisplayObject::~DisplayObject();
    Sfr21GFree(p, flags, 0xd0);
    return p;
}

// Stage
// MS2-FUNCTIONAL: scalar deleting destructor written out against raw member offsets; the class is not recovered
// @0x1424e3950
void* DeleteAs3_1424e3950(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, DAT_14317d220);
    Sfr21GVft(p, 0x18, DAT_14317d5f0);
    char* node = static_cast<char*>(Sfr21Mem(p, 0x120));
    if (--*reinterpret_cast<int*>(node + 0x18) == 0)
        reinterpret_cast<Scaleform::GFx::ASStringNode*>(node)->ReleaseNode();
    Sfr21GPtrNTS(p, 0x118);
    Sfr21GPtrNTS(p, 0x110);
    static_cast<Scaleform::GFx::DisplayObjContainer*>(p)->Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer();
    Sfr21GFree(p, flags, 0x130);
    return p;
}

// @0x1424e3a00
void* DeleteAs3_1424e3a00(void* p, unsigned flags) { Sfr21GVft(p, 0, DAT_14317f848); Sfr21GFree(p, flags, 0x10); return p; }

// Tracer
// @0x1424e3b90
void* DeleteAs3_1424e3b90(void* p, unsigned flags)
{
    FUN_1424df070(p);
    if (flags & 1)
        ::operator delete(p, 0x140);
    return p;
}

// a ClassTraits::Traits subclass with one SPtr
// @0x1424e3c30
void* DeleteAs3_1424e3c30(void* p, unsigned flags)
{
    Sfr21GSPtr(p, 0xc0);
    FUN_1424df220(p);
    Sfr21GFree(p, flags, 0xc8);
    return p;
}

// UDBase
// @0x1424e3d60
void* DeleteAs3_1424e3d60(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, DAT_14317f778);
    reinterpret_cast<const Scaleform::GFx::AS3::Traits*>(reinterpret_cast<UPInt>(Sfr21Mem(p, 0x20)) & ~UPInt(1))->DestructTail(*static_cast<Scaleform::GFx::AS3::Object*>(p));
    static_cast<Scaleform::GFx::AS3::Class*>(p)->Scaleform::GFx::AS3::Class::~Class();
    Sfr21GFree(p, flags, 0x50);
    return p;
}

// VMAbcFile (its destructor is inlined here in the exe)
// @0x1424e3eb0
void* DeleteAs3_1424e3eb0(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, DAT_14317b750);
    ::FUN_142522a60(static_cast<VM*>(Sfr21Mem(p, 0x20)), p);
    reinterpret_cast<Scaleform::SfrAdbExc*>(Sfr21At(p, 0xd0))->~ArrayDataBase();
    reinterpret_cast<Scaleform::SfrAdbPod*>(Sfr21At(p, 0xb8))->~ArrayDataBase();
    reinterpret_cast<Scaleform::SfrAdbCtr*>(Sfr21At(p, 0xa0))->~ArrayDataBase();
    FUN_1424dcc30(Sfr21At(p, 0x98));
    FUN_1424dcdd0(Sfr21At(p, 0x90));
    reinterpret_cast<Scaleform::SfrAdbFile*>(Sfr21At(p, 0x78))->~ArrayDataBase();
    reinterpret_cast<Scaleform::SfrHsGos*>(Sfr21At(p, 0x70))->~HashSetBase();
    reinterpret_cast<Scaleform::SfrAdbStr*>(Sfr21At(p, 0x58))->~ArrayDataBase();
    reinterpret_cast<Scaleform::SfrAdbNsSet*>(Sfr21At(p, 0x40))->~ArrayDataBase();
    reinterpret_cast<Scaleform::SfrHsGc*>(Sfr21At(p, 0x38))->~HashSetBase();
    FUN_1424ef5b0(Sfr21At(p, 0x30));
    FUN_1424dcf10(Sfr21At(p, 0x30));
    Sfr21GPtr(p, 0x28);
    static_cast<Scaleform::GFx::AS3::GASRefCountBase*>(p)->Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase();
    Sfr21GFree(p, flags, 0xe8);
    return p;
}

// a heap-held Value
// @0x1424e3fc0
void* DeleteAs3_1424e3fc0(void* p, unsigned flags)
{
    Sfr21GValue(p, 0);
    if (flags & 1)
        ::operator delete(p, 0x20);
    return p;
}

// InstanceTraits::Void
// @0x1424e4040
void* DeleteAs3_1424e4040(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::InstanceTraits::CTraits*>(p)->Scaleform::GFx::AS3::InstanceTraits::CTraits::~CTraits(); Sfr21GFree(p, flags, 0xe8); return p; }

// XMLSupport
// @0x1424e4120
void* DeleteAs3_1424e4120(void* p, unsigned flags) { Sfr21GVft(p, 0, DAT_14317b7b8); static_cast<Scaleform::GFx::AS3::GASRefCountBase*>(p)->Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(); Sfr21GFree(p, flags, 0x28); return p; }

// XMLSupportImpl
// @0x1424e4190
void* DeleteAs3_1424e4190(void* p, unsigned flags)
{
    Sfr21GVft(p, 0, DAT_14317f9e0);
    Sfr21GSPtr(p, 0x40);
    Sfr21GSPtr(p, 0x38);
    Sfr21GSPtr(p, 0x30);
    Sfr21GVft(p, 0, DAT_14317b7b8);
    static_cast<Scaleform::GFx::AS3::GASRefCountBase*>(p)->Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase();
    Sfr21GFree(p, flags, 0x48);
    return p;
}



// ==== AvmSprite::AddDisplayObject ====================================================================================

extern "C" {
extern "C" void* FUN_1425cf500(void* defImpl, void* ccinfo, const unsigned* id);         // MovieDefImpl::GetCharacterCreateInfo
void  FUN_1425dcaf0(void* sprite);                                            // Sprite::SetDirtyFlag (empty)
void  FUN_1425f7f70(void* io);                                                // InteractiveObject::AddToPlayList
}
}}} // namespace Scaleform::GFx::AS3
// instantiated in sfr_as3_18 (0x142516210), called out of line
namespace Scaleform { namespace GFx {
extern template void LogBase<DisplayObjectBase>::LogError(const char* pfmt, ...) const;
}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {

template <class R> static inline R Sfr21VCall(void* obj, UPInt off)
{
    return (*reinterpret_cast<R (**)(void*)>(*static_cast<char**>(obj) + off))(obj);
}
template <class R, class A> static inline R Sfr21VCall(void* obj, UPInt off, A a)
{
    return (*reinterpret_cast<R (**)(void*, A)>(*static_cast<char**>(obj) + off))(obj, a);
}

// The AS3 part of a display object (the byte at +0x6d holds its offset in dwords).
static inline char* Sfr21Avm(void* obj) { return Sfr21At(obj, UPInt(*reinterpret_cast<UByte*>(Sfr21At(obj, 0x6d))) * 4); }

// Places character pos.CharacterId at pos.Depth: an object of the same character, name and creation frame already there
// is moved instead (its AS3 name property reset on the parent); else a new instance is created, named, added to the
// display list, given its AS3 object (the name property set on this sprite before the constructor runs) and its
// children, and told it was added.
// CharPosInfo: ColorTransform +0, pFilters +0x40, Depth +0x4c, CharacterId +0x50, ClassName +0x58, BlendMode +0x64,
// Flags +0x62 (0x08 HasCxform, 0x80 HasBlendMode, 0x100 HasClassName); 0x68 bytes.
// MS2-FUNCTIONAL: written against raw display object offsets and the exe's helpers; the ASString counting is ours
// @0x1424e7140
DisplayObjectBase* AvmSprite::AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                               const ArrayLH<SwfEvent*, StatMD_Tags_Mem>*, const void*,
                                               unsigned createFrame, unsigned long addFlags,
                                               CharacterCreateInfo* pcharCreateOverride, InteractiveObject* origChar)
{
    const char* P       = reinterpret_cast<const char*>(&pos);
    char*       spr     = reinterpret_cast<char*>(pDispObj);
    char*       root    = static_cast<char*>(Sfr21Mem(spr, 0x20));
    void*       defImpl = Sfr21Mem(spr, 0xb0);
    VM*         vm      = static_cast<VM*>(Sfr21Mem(root, 0x48));
    unsigned    id      = *reinterpret_cast<const unsigned*>(P + 0x50);
    const bool  hasClassName = (*reinterpret_cast<const UInt16*>(P + 0x62) & 0x100) != 0;
    const char* className    = *reinterpret_cast<const char* const*>(P + 0x58);
    int         type    = 0;

    struct CCInfo { void* pCharDef; void* pBindDefImpl; void* pResource; } cc;
    if (pcharCreateOverride)
        memcpy(&cc, pcharCreateOverride, sizeof(cc));
    else
    {
        CCInfo tmp;
        memcpy(&cc, FUN_1425cf500(defImpl, &tmp, &id), sizeof(cc));
    }
    if (!cc.pCharDef)
    {
        if (hasClassName)
        {
            struct { void* pResource; void* pBinding; } bind = { NULL, NULL };
            bool found;
            {
                String symbol(className);
                found = static_cast<MovieImpl*>(Sfr21Mem(root, 0x10))->FindExportedResource(static_cast<MovieDefImpl*>(defImpl), reinterpret_cast<ResourceBindData*>(&bind), symbol);
            }
            if (found)
            {
                // Resource::RT_CharacterDef_Bit
                if (Sfr21VCall<unsigned>(bind.pResource, 0x10) & 0x8000)
                    cc.pCharDef = bind.pResource;
                else
                    cc.pResource = bind.pResource;
                cc.pBindDefImpl = Sfr21Mem(bind.pBinding, 0x48);
            }
            if (bind.pResource)
                reinterpret_cast<Scaleform::GFx::Resource*>(bind.pResource)->Release();
        }
        if (!cc.pCharDef)
        {
            // An image resource placed on the stage becomes a Bitmap character.
            if (!cc.pResource || (Sfr21VCall<unsigned>(cc.pResource, 0x10) & 0xff00) != 0x100)
            {
                reinterpret_cast<DisplayObjectBase*>(spr)->LogError("Sprite::AddDisplayObject(): unknown cid = %d\n", unsigned(UInt16(id)));
                return NULL;
            }
            type = 8;
            if (!cc.pBindDefImpl)
                cc.pBindDefImpl = defImpl;
        }
    }

    bool  markedForRemove = false;
    char* ex = reinterpret_cast<char*>(reinterpret_cast<Scaleform::GFx::DisplayList*>(spr + 0xd8)->GetDisplayObjectAtDepth(*reinterpret_cast<const int*>(P + 0x4c), &markedForRemove));
    if (createFrame == ~0u)
        createFrame = Sfr21VCall<unsigned>(spr, 0x328);   // GetCurrentFrame

    bool replace = (addFlags & 1) != 0;
    if (!(addFlags & 4))
        replace = true;
    else
    {
        // AcceptAnimMoves +0x178, ContinueAnimation +0x180, SetAcceptAnimMoves +0x188
        if (ex && !Sfr21VCall<bool>(ex, 0x178) && Sfr21VCall<bool>(ex, 0x180))
            Sfr21VCall<void, bool>(ex, 0x188, true);
        if (!markedForRemove && ex && !Sfr21VCall<bool>(ex, 0x178))
            return NULL;
        if (ex && *reinterpret_cast<int*>(ex + 0x2c) >= -1 && *reinterpret_cast<unsigned*>(ex + 0x28) == id)
        {
            const bool    isInteractive = *reinterpret_cast<SByte*>(ex + 0x6a) < 0;
            ASStringNode* orig;
            if (isInteractive)
                ::new (static_cast<void*>(&orig)) ASString(reinterpret_cast<Scaleform::GFx::DisplayObject*>(ex)->GetOriginalName());
            else
            {
                orig = static_cast<ASStringNode*>(Sfr21Mem(root, 0x160));   // builtin ""
                orig->AddRef();
            }
            bool same;
            if (!isInteractive)
                same = true;
            else if (name.GetSize() == 0)
                same = orig->Size == 0 || (*reinterpret_cast<UByte*>(ex + 0x88) & 2) != 0;   // instance-based name
            else
                same = orig == name.GetNode();
            orig->Release();

            if (same)
            {
                if (*reinterpret_cast<unsigned*>(ex + 0x30) == createFrame)
                {
                    char np[0x68];
                    memcpy(np, P, sizeof(np));
                    if (void* filters = Sfr21Mem(np, 0x40))
                        reinterpret_cast<Scaleform::RefCountImpl*>(filters)->AddRef();
                    UInt16& flags = *reinterpret_cast<UInt16*>(np + 0x62);
                    if (!(flags & 0x80) && Sfr21VCall<int>(ex, 0x68))   // GetBlendMode
                    {
                        np[0x64] = 0;
                        flags |= 0x80;
                    }
                    if (!(*reinterpret_cast<const UInt16*>(P + 0x62) & 8) && !reinterpret_cast<DisplayObjectBase*>(ex)->GetCxform().IsIdentity())
                    {
                        flags |= 8;
                        reinterpret_cast<Scaleform::Render::Cxform*>(np)->SetIdentity();
                    }
                    reinterpret_cast<Scaleform::GFx::DisplayObjContainer*>(spr)->MoveDisplayObject(*reinterpret_cast<const Scaleform::GFx::CharPosInfo*>(np));

                    // The object is reused: its name property on the AS3 parent is set again.
                    if (*reinterpret_cast<UByte*>(ex + 0x6b) & 1)
                    {
                        AvmDisplayObj* avm = reinterpret_cast<AvmDisplayObj*>(Sfr21Avm(ex));
                        Instances::fl_display::DisplayObject* parent = avm->GetAS3Parent();
                        if (!(*reinterpret_cast<UByte*>(ex + 0x88) & 2) && parent)
                        {
                            ASStringNode* nm;
                            ::new (static_cast<void*>(&nm)) ASString(reinterpret_cast<Scaleform::GFx::DisplayObject*>(ex)->GetName());
                            {
                                Multiname mn(vm->GetPublicNamespace(), Value(ASString(nm)));
                                reinterpret_cast<Object*>(parent)->SetProperty(
                                    mn, Value(reinterpret_cast<Object*>(avm->GetAS3Obj())));
                            }
                            nm->Release();
                        }
                    }
                    if (void* filters = Sfr21Mem(np, 0x40))
                        reinterpret_cast<Scaleform::RefCountImpl*>(filters)->Release();
                    return NULL;
                }
                replace = true;
            }
        }
    }

    FUN_1425dcaf0(spr);
    void* asSupport = Sfr21Mem(root, 0x18);
    char* ch = (*reinterpret_cast<char* (**)(void*, void*, void*, void*, const unsigned*, int)>(
        *static_cast<char**>(asSupport) + 0x20))(asSupport, Sfr21Mem(root, 0x10), &cc, spr, &id, type);   // CreateCharacterInstance
    char* io = *reinterpret_cast<SByte*>(ch + 0x6a) < 0 ? ch : NULL;
    *reinterpret_cast<UInt16*>(ch + 0x6a) &= ~1;
    bool nameSet = false;
    if (io)
    {
        nameSet = name.GetSize() != 0;
        if (nameSet)
            reinterpret_cast<DisplayObject*>(io)->SetOriginalName(name);
        if (origChar)
            Sfr21VCall<void, InteractiveObject*>(io, 0x2c0, origChar);   // CloneInternalData
    }
    if (!(addFlags & 4))
        Sfr21VCall<void, bool>(ch, 0x188, false);
    else
        *reinterpret_cast<UInt16*>(ch + 0x88) |= 1;   // timeline object
    *reinterpret_cast<unsigned*>(ch + 0x30) = createFrame;
    unsigned listFlags = unsigned(addFlags) & ~1u;
    if (replace)
        listFlags |= 1;
    if (hasClassName)
        reinterpret_cast<AvmDisplayObj*>(Sfr21Avm(ch))->InitClassName(className);
    reinterpret_cast<DisplayList*>(spr + 0xd8)->AddDisplayObject(reinterpret_cast<DisplayObjectBase*>(spr), pos, reinterpret_cast<DisplayObjectBase*>(ch), listFlags);

    AvmDisplayObj* avm = reinterpret_cast<AvmDisplayObj*>(Sfr21Avm(ch));
    if (avm->CreateASInstanceNoCtor(false))
    {
        if (!(*reinterpret_cast<UByte*>(ch + 0x88) & 2) && avm->GetAS3Parent())
        {
            {
                Multiname mn(vm->GetPublicNamespace(), Value(name));
                reinterpret_cast<Object*>(GetAS3Obj())->SetProperty(mn, Value(reinterpret_cast<Object*>(avm->GetAS3Obj())));
            }
            if (vm->IsException())
            {
                vm->OutputAndIgnoreException();
                *reinterpret_cast<UInt16*>(spr + 0x88) |= 0x20;   // execution aborted
            }
        }
        avm->CallCtor(true);

        // A sprite gets its children now.
        char* a = reinterpret_cast<char*>(avm);
        if ((*reinterpret_cast<UInt16*>(ch + 0x6a) & 0x400) && !(a[0x60] & AvmSprite::Flag_ChildrenCreated))
        {
            char* sp = static_cast<char*>(Sfr21Mem(a, 0x18));
            char* parent = static_cast<char*>(Sfr21Mem(sp, 0x38));
            if (!reinterpret_cast<InteractiveObject*>(sp)->IsInPlayList() && parent && reinterpret_cast<InteractiveObject*>(parent)->IsInPlayList())
            {
                avm->GetAvmParent()->InsertChildToPlayList(reinterpret_cast<InteractiveObject*>(sp));
                reinterpret_cast<InteractiveObject*>(sp)->ModifyOptimizedPlayList();
            }
            if (!(sp[0x140] & 8))
                reinterpret_cast<Sprite*>(sp)->DefaultOnEventLoad();
            if (*reinterpret_cast<UByte*>(sp + 0x6d))
            {
                void* x = Sfr21VCall<void*>(Sfr21Avm(sp), 0x10);
                Sfr21VCall<void, bool>(x, 0xe0, false);
            }
            a[0x60] |= AvmSprite::Flag_ChildrenCreated;
        }
    }

    if (nameSet)
        Sfr21VCall<void, void*>(root, 0xf0, io);   // ResolveStickyVariables
    if (io)
    {
        if (nameSet && name.GetNode() == Sfr21Mem(root, 0x1c8))   // builtin "hitArea"
            reinterpret_cast<Sprite*>(spr)->SetHitArea(reinterpret_cast<Sprite*>(io));
        char* base = Sfr21VCall<char*>(Sfr21Avm(io), 8);         // ToAvmInteractiveObjBase
        Sfr21VCall<void, bool>(base ? base - 0x30 : NULL, 0x98, true);   // OnAdded
    }
    reinterpret_cast<const Scaleform::RefCountNTSImpl*>(ch)->Release();
    return reinterpret_cast<DisplayObjectBase*>(ch);
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace Render {

void* FUN_142532060(void* self, UPInt n);   // LinearHeap::allocFromLastPage

// LinearHeap::Alloc (header inline, an exe COMDAT): rounds size up to pointer size and bump-allocates from the last
// page; past it, moves to the next page slot, creating the 64-slot pool on first use and doubling it when full.
// The heap is laid out { pHeap, Granularity, pPagePool, pLastPage, MaxPages } with 0x18-byte page slots.
// @0x1424eb4d0
void* Sfr21LinearHeapAlloc(void* self, UPInt size)
{
    struct PageType { UByte* pStart; UByte* pEnd; UByte* pFree; };
    struct Heap { MemoryHeap* pHeap; UPInt Granularity; PageType* pPagePool; PageType* pLastPage; UPInt MaxPages; };
    Heap* h = static_cast<Heap*>(self);
    size = (size + sizeof(UPInt) - 1) & ~(sizeof(UPInt) - 1);
    if (h->pLastPage)
    {
        void* p = FUN_142532060(self, size);
        if (p)
            return p;
        ++h->pLastPage;
    }
    else
    {
        h->pLastPage = h->pPagePool =
            static_cast<PageType*>(h->pHeap->Alloc(64 * sizeof(PageType), static_cast<const AllocInfo*>(0)));
        memset(h->pPagePool, 0, 64 * sizeof(PageType));
        h->MaxPages = 64;
    }
    if (h->pLastPage - h->pPagePool >= SPInt(h->MaxPages))
    {
        UPInt     used = h->pLastPage - h->pPagePool;
        PageType* pool = static_cast<PageType*>(
            h->pHeap->Alloc(h->MaxPages * 2 * sizeof(PageType), static_cast<const AllocInfo*>(0)));
        memcpy(pool, h->pPagePool, h->MaxPages * sizeof(PageType));
        memset(pool + h->MaxPages, 0, h->MaxPages * sizeof(PageType));
        h->pHeap->Free(h->pPagePool);
        h->pPagePool = pool;
        h->MaxPages *= 2;
        h->pLastPage = h->pPagePool + used;
    }
    return FUN_142532060(self, size);
}

}} // namespace Scaleform::Render

namespace Scaleform { namespace GFx {

// Not exe code: abstract probes whose constructors run the implicit constructors of the GFx Avm*Base interfaces, which
// emits their vftables and the deleting destructors of this range. novtable: the probes' own tables are not emitted.
struct __declspec(novtable) Unk_As3_16zButtonBaseProbe : AvmButtonBase { Unk_As3_16zButtonBaseProbe(); };
struct __declspec(novtable) Unk_As3_16zTextFieldBaseProbe : AvmTextFieldBase { Unk_As3_16zTextFieldBaseProbe(); };
struct __declspec(novtable) Unk_As3_16zSpriteBaseProbe : AvmSpriteBase { Unk_As3_16zSpriteBaseProbe(); };
Unk_As3_16zButtonBaseProbe::Unk_As3_16zButtonBaseProbe() {}
Unk_As3_16zTextFieldBaseProbe::Unk_As3_16zTextFieldBaseProbe() {}
Unk_As3_16zSpriteBaseProbe::Unk_As3_16zSpriteBaseProbe() {}
// (sfg) and the GC collector's: RefCountCollector<323>'s vftable and deleting destructor (0x1424e2040).
struct __declspec(novtable) Unk_As3_16zCollectorProbe : AS3::RefCountCollector<AS3::StatMV_ActionScript_Mem>
{
    Unk_As3_16zCollectorProbe();
};
Unk_As3_16zCollectorProbe::Unk_As3_16zCollectorProbe() {}
// (sfg) RefCountBase<ASIntervalTimerIntf, 323>'s vftable and deleting destructor (0x1424e21a0).
struct __declspec(novtable) Unk_As3_16zTimerIntfProbe : ASIntervalTimerIntf
{
    Unk_As3_16zTimerIntfProbe();
};
Unk_As3_16zTimerIntfProbe::Unk_As3_16zTimerIntfProbe() {}

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
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7FunctionBase@Instances@AS3@GFx@Scaleform@@6B@ 0x14313f8f8
// MS2-PIN: ??_7FlashUI@AS3@GFx@Scaleform@@6B@ 0x14317b648
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmDisplayObjContainerBase@GFx@Scaleform@@6B@ 0x14317c0a0
// MS2-PIN: ??_7AvmSpriteBase@GFx@Scaleform@@6B@ 0x14317c898
// MS2-PIN: ??_7WideStringStorage@MovieImpl@GFx@Scaleform@@6B@ 0x14317ca48
// MS2-PIN: ??_7ObjectInterface@Value@GFx@Scaleform@@6B@ 0x14317bc90
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
// MS2-PIN: ??_7AvmButtonBase@GFx@Scaleform@@6B@ 0x14317db08
// MS2-PIN: ??_7AvmTextFieldBase@GFx@Scaleform@@6B@ 0x14317e508
// MS2-PIN: ??_7AvmStaticText@AS3@GFx@Scaleform@@6B@ 0x14317e9b8
// MS2-PIN: ??_7FrameCounter@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317e608
// MS2-PIN: ??_7FrameCounter@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317e9a0
// MS2-PIN: ??_7StickyVarNode@MovieImpl@GFx@Scaleform@@6B@ 0x14317ca50
// MS2-PIN: ??_7StickyVarNode@MovieRoot@AS3@GFx@Scaleform@@6B@ 0x14317d8c8
// MS2-PIN: ??_7AS3ValueObjectInterface@GFx@Scaleform@@6B@ 0x14317eff8
// MS2-PIN: ??_7UserDefinedFunction@AS3@GFx@Scaleform@@6B@ 0x14317ef38
// MS2-PIN: ??_7?$RefCountBase@VWideStringStorage@MovieImpl@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317ca40

// ==== the base-class no-op virtuals the vftables of this range name ==================================================
namespace Scaleform { namespace GFx {

// DisplayObjContainer's default: containers that cannot take timeline children add nothing.
// @0x1424e7f30
DisplayObjectBase* DisplayObjContainer::AddDisplayObject(const CharPosInfo&, const ASString&,
                                                         const ArrayLH<SwfEvent*, StatMD_Tags_Mem>*, const void*, unsigned,
                                                         unsigned long, CharacterCreateInfo*, InteractiveObject*)
{
    return 0;
}

// @0x1424eb250
void DisplayObjectBase::AdvanceFrame(bool, float)
{
}

}} // namespace Scaleform::GFx
// MS2-PIN: ??_G?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2040
// MS2-FUNCTIONAL 0x1424e21a0: the exe stores the vftable and calls ~RefCountImpl (0x14257db40); our kernel RefCountImpl has no destructor of its own, so ours calls ~RefCountImplCore.
// MS2-PIN: ??_G?$RefCountBase@VASIntervalTimerIntf@GFx@Scaleform@@$0BED@@Scaleform@@UEAAPEAXI@Z 0x1424e21a0
// MS2-PIN: ??_7?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14317b040
// MS2-PIN: ??_7Root@?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14317b010
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7?$RefCountBase@V?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
// MS2-PIN: ??_7?$RefCountBase@VASIntervalTimerIntf@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
