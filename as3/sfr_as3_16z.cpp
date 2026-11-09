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
// MS2-RANGE: 0x1424e3830-0x1424e3950 .text$mn
// MS2-RANGE: 0x1424e3a00-0x1424e3bd0 .text$mn
// MS2-RANGE: 0x1424e3c30-0x1424e3cc0 .text$mn
// MS2-RANGE: 0x1424e3de0-0x1424e3e50 .text$mn
// MS2-RANGE: 0x1424e3eb0-0x1424e4190 .text$mn
// MS2-RANGE: 0x1424e42c0-0x1424e46f0 .text$mn
// MS2-RANGE: 0x1424e5e80-0x1424e63b0 .text$mn
// MS2-RANGE: 0x1424e6aa0-0x1424e6f90 .text$mn
// MS2-RANGE: 0x1424e7140-0x1424e7f40 .text$mn
// MS2-RANGE: 0x1424e80f0-0x1424e8c20 .text$mn
// MS2-RANGE: 0x1424e8e20-0x1424e8ed0 .text$mn
// MS2-RANGE: 0x1424eab60-0x1424eaf00 .text$mn
// MS2-RANGE: 0x1424eaf80-0x1424eb610 .text$mn
// MS2-RANGE: 0x1424dbf70-0x1424dbfc0 .text$mn
// The Avm* deleting destructors free only on a global delete, and AvmButton / AvmTextField / AvmStaticText are modeled.
#define SF_AS3_AVM_INPLACE_DELETE
#define SF_AS3_AVMBUTTON_MODEL
#define SF_AS3_SHAPEOBJECT_MODEL
#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp weak-ref bodies inline (as3_value.h)
#define MS2_SF_FUNCTIONBASE_DTOR_OUTLINE   // UserDefinedFunction is outside the SCU: its ??_G calls ~FunctionBase (as3_obj.h)
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
#include "ms2/scaleform/include/render/render_statebag.h"
namespace Scaleform { namespace GFx { class ASSoundIntf; }
// 0x1425dcaf0, a bare ret: the exe folds the empty body the callers below call out of line into this instance.
// Declared as a specialization, so cl calls it by name instead of inlining the header's empty body.
template<> void ConstructorMov<GFx::ASSoundIntf*>::Construct(void*); }
#undef GetObject
// VM: runs the queued code (unrecovered).

// ShapeObject / AvmBitmap (SF_AS3_SHAPEOBJECT_MODEL): copies of sfr_as3_16's destructors (0x1424ddb00 / 0x1424deeb0,
// inline there under cl), which the exe's AS3_All SCU inlines into the deleting destructors below. clang: call 16's.
#if !defined(__clang__)
__forceinline Scaleform::GFx::AS3::AvmBitmap::~AvmBitmap() { AvmObjOffset = 0; }
__forceinline Scaleform::GFx::AS3::ShapeObject::~ShapeObject() { AvmObjOffset = 0; }
#endif
// global C++ helpers defined in other units
void FUN_1424dcce0(void* p);
void FUN_1424dcc30(void* p);
void FUN_1424dcdd0(void* p);
void FUN_1424aa0f0(void* p);            // Text::TextFormat::~TextFormat
namespace Scaleform { namespace GFx { namespace AS3 { class VM; class Multiname; }}}
namespace Scaleform { namespace Render { extern const void* const TreeShapeNodeDataVTable[]; }} // gfx_rendertree.h
bool FUN_142522a60(Scaleform::GFx::AS3::VM* vm, void* file);

// ArrayDataBase destructors the exe calls out of line (instantiated elsewhere)
namespace Scaleform {
// The Value array copy ctor (0x1424d5310, explicit instantiation in sfr_as3_15): the exe calls it out of line from
// Tracer::AddBlock (FUN_1424e6aa0) for the state's register, op and scope stacks.
template <> ArrayDataDH<GFx::AS3::Value, AllocatorDH<GFx::AS3::Value, 2>, ArrayDefaultPolicy>::ArrayDataDH(
    const ArrayDataDH<GFx::AS3::Value, AllocatorDH<GFx::AS3::Value, 2>, ArrayDefaultPolicy>& a);
// The event chains' ResizeNoConstruct (0x142524cd0, explicit instantiation in sfr_as3_19): the exe calls it out of line
// from EventChains::AddToChain's PushBack.
template<> SF_NOINLINE void ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, Stat_Default_Mem>,
    ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);
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
template<> SF_NOINLINE void ConstructorMov<GFx::AS3::Value>::DestructArray(GFx::AS3::Value* p, UPInt count);      // 0x1424f6d50
typedef decltype(static_cast<GFx::AS3::AbcMultinameHash<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace> >::TContainer*>(0)->mHash)::BaseType SfrHsNs;
template<> SF_NOINLINE SfrHsNs::~HashSetBase();      // 0x1424dcf10
template<> SF_NOINLINE void SfrHsNs::Clear();      // 0x1424ef5b0
// The display-object list assignment is sfr_as3_16's specialization (0x1424e0340).
template<> AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy> >&
AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy> >::operator=(const AutoPtr& p);
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
        Chains.Add(evtId, chain);
    }
    else
        chain = pentry->GetPtr();
    if (FindObjectIndexInChain(chain, obj) == SF_MAX_UPINT)
        chain->PushBack(WeakPtr<DisplayObject>(obj));
}

__declspec(noinline) void* DeleteAs3_1424e2420(void* p, unsigned flags);   // ActionEntry's deleting dtor (below)

// @0x1424eae40
void MovieRoot::ActionQueueType::AddToFreeList(ActionEntry* pentry)
{
    // ActionEntry::ClearAction, with the exe's out-of-line SetUndefined (the SCU would inline it here)
    pentry->Type         = ActionEntry::Entry_None;
    pentry->pCharacter   = NULL;
    pentry->pAS3Obj      = NULL;
    pentry->CFunction    = NULL;
    (pentry->Function.*&Value::SetUndefined)();
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
// scripts of the play list and moves the manual actions behind them. The root is read before the nextFrame test: cl
// sinks the loads past it, but nextFrame stays live over them, which gives the exe's r8 and its rbx save in the prolog.
// @0x1424eb260
void FrameCounter::AdvanceFrame(bool nextFrame, float framePos)
{
    SF_UNUSED(framePos);
    MovieRoot* proot = static_cast<MovieRoot*>(GetMovieImpl()->pASMovieRoot);
    if (nextFrame)
    {
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
    ::new (pudf) UserDefinedFunction(pudf->GetInstanceTraits(), NULL, NULL);
}

// GFx::Value as the exe lays it out (the members are private to the value).
struct Unk_As3_16zGFxValueRaw
{
    GFx::Value::ObjectInterface* pObjectInterface;   // +0x00
    UInt32                       Type;               // +0x08
    void*                        pData;              // +0x10
    UPInt                        DataAux;            // +0x18 closures: the thunk or the vtable index
};

// GFx::Value::IsManagedValue: the VTC_ManagedBit flag.
static inline bool IsManagedValue16z(const Unk_As3_16zGFxValueRaw* v)
{
    return (v->Type >> 6) & 1;
}

// v as a host value. A requested type (convert bit) wins; otherwise the kind decides: plain values keep their type,
// objects, classes and functions become objects (display objects and arrays get their own type), closures stay
// closures, a null reference is null and everything else is converted to a string. Strings, objects and closures
// are managed through the movie's object interface; a failed conversion is reported and leaves NaN.
// @0x1424e42c0
void MovieRoot::ASValue2GFxValue(const Value& v, GFx::Value* pdestVal) const
{
    Unk_As3_16zGFxValueRaw* dest = reinterpret_cast<Unk_As3_16zGFxValueRaw*>(pdestVal);
    int toType;
    unsigned vtableIndClosure = 0;
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
            vtableIndClosure = 1;
            toType = v.GetClosure() ? GFx::Value::VT_Closure : GFx::Value::VT_Null;
            break;
        default:
            toType = GFx::Value::VT_String;
            break;
        }
        if (v.IsNull())
            toType = GFx::Value::VT_Null;
    }

    if (IsManagedValue16z(dest))   // VTC_ManagedBit: drop the old reference
    {
        dest->pObjectInterface->ObjectRelease(pdestVal, dest->pData);
        dest->pObjectInterface = NULL;
    }

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
        if (!v.Convert2Number(*reinterpret_cast<Double*>(&dest->pData)))
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
            dest->pObjectInterface = static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface);
            static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface)->ObjectAddRef(pdestVal, dest->pData);
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
            dest->pObjectInterface = static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface);
            static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface)->ObjectAddRef(pdestVal, dest->pData);
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
            dest->pObjectInterface = static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface);
            static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface)->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    case GFx::Value::VT_Closure:
        {
            // Bit 1 of the object pointer tells a vtable index closure from a thunk closure.
            const UPInt closure = reinterpret_cast<UPInt>(v.GetClosure());
            dest->Type    = GFx::Value::VT_Closure | GFx::Value::VTC_ManagedBit;
            dest->pData   = reinterpret_cast<void*>(closure | (vtableIndClosure ? 2 : 0));
            dest->DataAux = vtableIndClosure ? UPInt(SPInt(v.GetVTableInd())) : reinterpret_cast<UPInt>(&v.AsThunk());
            dest->pObjectInterface = static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface);
            static_cast<GFx::Value::ObjectInterface*>(pMovieImpl->pObjectInterface)->ObjectAddRef(pdestVal, dest->pData);
        }
        break;
    default:
        break;
    }
}

// The loaded-movie-def hash (+0x6e8): the value an identity-hashed key maps to, and the add of a new node.
void* Sfr33IdWordHashGet(const UByte* self, const UPInt& key);       // 0x1425059f0
static inline void* FUN_1425059f0(const void* self, const UPInt& key) { return Sfr33IdWordHashGet(static_cast<const UByte*>(self), key); }
}}} // namespace Scaleform::GFx::AS3
// The LoadedMovieDefs hash's node/set types (as in sfr_as3_15, which holds the add<NodeRef> instance, 0x1424d4220).
namespace Scaleform {
struct MS2_LoadedMovieDefInfo
{
    Ptr<GFx::MovieDefImpl> pMovieDef;
    unsigned               UseCnt;

    MS2_LoadedMovieDefInfo(GFx::MovieDefImpl* def) : pMovieDef(def), UseCnt(1) {}
};
typedef HashNode<GFx::MovieDefImpl*, MS2_LoadedMovieDefInfo, IdentityHash<GFx::MovieDefImpl*> > MS2_LoadedMovieDefNode;
typedef HashSetBase<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF, MS2_LoadedMovieDefNode::NodeAltHashF,
                    AllocatorLH<GFx::MovieDefImpl*, 2>,
                    HashsetNodeEntry<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF> >
    MS2_LoadedMovieDefSet;
extern template void MS2_LoadedMovieDefSet::add<MS2_LoadedMovieDefNode::NodeRef>(void*, const MS2_LoadedMovieDefNode::NodeRef&,
                                                                               UPInt);
} // namespace Scaleform
namespace Scaleform { namespace GFx { namespace AS3 {

// A use of pdefImpl: an entry already listed counts one more use; otherwise one is added (holding the definition)
// with a single use.
// MS2-FUNCTIONAL: register allocation only (exe keeps the key in rbx and copies it to rdi for the Ptr); the hash
// lookup is called through its exe address; the add is the hash's own Add (add<NodeRef>, 0x1424d4220)
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
    reinterpret_cast<MS2_LoadedMovieDefSet&>(LoadedMovieDefs)
        .Add(&LoadedMovieDefs, reinterpret_cast<const MS2_LoadedMovieDefNode::NodeRef&>(ref));
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
// A free function in place of the ASRefCountCollector member (not declared in as3_gc.h).
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
    ++gc->FrameCnt;
    const unsigned roots = (unsigned)gc->GetRootsCount();
    gc->PeakRootCount = Alg::Max(gc->PeakRootCount, roots);
    if (!(gc->SuspendCnt > 0) &&
        ((gc->PresetMaxRootCount != 0 && roots > gc->MaxRootCount) ||
         (gc->MaxFramesBetweenCollections != 0 && gc->FrameCnt >= gc->MaxFramesBetweenCollections &&
          roots > gc->PresetMaxRootCount)))
    {
        ASRefCountCollector::Stats stats = { statsObserver, 0, 0 };
        gc->Collect(&stats);
        if (stats.RootsFreedTotal > gc->PresetMaxRootCount)
        {
            gc->PeakRootCount = roots;
            gc->MaxRootCount  = gc->PresetMaxRootCount;
        }
        gc->FrameCnt = 0;
        gc->LastPeakRootCount = gc->PeakRootCount;
        gc->LastCollectedRoots = stats.RootsFreedTotal;
        gc->MaxRootCount = Alg::Max(gc->MaxRootCount, roots - stats.RootsFreedTotal);
        const unsigned scaled = (unsigned)(SInt64)((double)gc->MaxRootCount * 0.7);
        if (gc->PeakRootCount < scaled)
            gc->MaxRootCount = scaled;
        gc->LastCollectionFrameNum = gc->TotalFramesCount;
    }
    gc->LastRootCount = roots;
    *movieFrameCnt = gc->FrameCnt;
    *movieLastCollectFrame = gc->LastCollectionFrameNum;
}

void Sfr33CollectorQueue(UByte* gc, RefCountImpl* stats);            // 0x142504630, ASRefCountCollector::ForceCollect
static inline void FUN_142504630(ASRefCountCollector* gc, void* stats) { Sfr33CollectorQueue(reinterpret_cast<UByte*>(gc), static_cast<RefCountImpl*>(stats)); }

// The SDK's inline ToAvmDisplayObjContainer (AS3_AvmDisplayObjContainer.h); NULL in, NULL out.
static inline AvmDisplayObjContainer* ToAvmDisplayObjContainer16z(DisplayObjContainer* pobj)
{
    if (!pobj)
        return NULL;
    AvmDisplayObjContainerBase* b = pobj->GetAvmDispContainer();
    return b ? static_cast<AvmDisplayObjContainer*>(b) : NULL;
}

// Runs the collection System.gc scheduled (inline in the SDK collector).
static inline void RunScheduledCollection16z(ASRefCountCollector* gc, void* stats)
{
    if (gc->CollectionScheduledFlags)
    {
        gc->CollectionScheduledFlags = 0;
        FUN_142504630(gc, stats);
    }
}

// MovieRoot::AdvanceFrame: until the main movie's loader events are done, fires its loaderInfo init (once), progress
// (each full frame, or once loading has finished) and complete events. An invalidated stage gets its RENDER events run
// right away. A full frame runs a collection System.gc scheduled, then advances the collector.
// The scheduled collection (ASRefCountCollector::ForceCollect) is called through its exe address.
// @0x1424eb2f0
void MovieRoot::AdvanceFrame(bool nextFrame)
{
    if (!(MainLoaderInfoEventsState & 2))
    {
        MovieDefImpl* md = pMovieImpl->pMainMovie->GetResourceMovieDef();
        DisplayObjContainer* rt = GetRootMovie418(NULL);
        SPtr<Instances::fl_display::DisplayObject> as3obj = ToAvmDisplayObjContainer16z(rt)->GetAS3Obj();
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
    if (nextFrame && MemContext->ASGC)
    {
        RunScheduledCollection16z(MemContext->ASGC, *reinterpret_cast<void* const*>(&pMovieImpl->pAdvanceStats));
        Sfr21ASGCAdvanceFrame(MemContext->ASGC, &NumAdvancesSinceCollection, &LastCollectionFrame,
                              static_cast<ASRefCountCollector::StatsObserver*>(*reinterpret_cast<void* const*>(&pMovieImpl->pAdvanceStats)));
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
            // the exe calls the out-of-line Value::operator=(const ASString&) (0x1424e0d40)
            (result.*static_cast<Value& (Value::*)(const ASString&)>(&Value::operator=))(left + right);
            return true;
        }
        return false;
    }

    if (l.IsPrimitive() && r.IsPrimitive())
    {
        Value::Number lnum = 0.0;
        Value::Number rnum = 0.0;
        if (!l.Convert2NumberInline(lnum))
            return false;
        if (!r.Convert2NumberInline(rnum))
            return false;
        (result.*&Value::SetNumber)(lnum + rnum);   // the exe calls the out-of-line SetNumber (0x142421f20)
        return true;
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
void Sfr31VMRaiseError(UPInt vm, const unsigned long* error, UPInt classInfo);      // 0x14252ecb0, raise as an instance of the class
namespace fl { extern const ClassInfo VerifyErrorCI; }

// Unit-local copies of the Slots inlines the exe expands here (GetSlotInfo 0x142416fb0 / GetSlotNameNode 0x14250dce0
// one level deep, FindSlotInfoIndex 0x142502b20, the SDK CIterator).
static __forceinline const SlotInfo& Sfr21GetSlotInfo(const Slots& s, AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Value;
}
static __forceinline ASStringNode* Sfr21GetSlotNameNode(const Slots& s, AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotNameNode(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Key.GetPtr();
}
static __forceinline AbsoluteIndex Sfr21FindSlotInfoIndex(const Slots& s, const ASString& name,
                                                          const Instances::Namespace& ns)
{
    if (const UInt32* values = s.FindSlotValues(name))
    {
        for (SPInt ind = *values; ind >= 0; )
        {
            const AbsoluteIndex index(ind);
            const Instances::Namespace& cur_ns = *Sfr21GetSlotInfo(s, index).pNs;
            if (cur_ns.GetKind() == ns.GetKind())
            {
                switch (ns.GetKind())
                {
                case Abc::NS_Protected:
                    return index;
                case Abc::NS_Private:
                    if (&ns == &cur_ns)
                        return index;
                    break;
                default:
                    if (cur_ns.GetUri().GetNode() == ns.GetUri().GetNode())
                        return index;
                    break;
                }
            }
            if (static_cast<UPInt>(ind) < s.FirstOwnSlotNum)
                ind = s.Parent->GetPrevSlotIndex(ind);
            else
                ind = s.VArray[static_cast<UPInt>(ind) - s.FirstOwnSlotNum].Prev;
        }
    }
    return AbsoluteIndex(-1);
}
static __forceinline const SlotInfo* Sfr21FindSlotInfo(const Slots& s, const ASString& name,
                                                       const Instances::Namespace& ns)
{
    const AbsoluteIndex ind = Sfr21FindSlotInfoIndex(s, name, ns);
    return ind.IsValid() ? &Sfr21GetSlotInfo(s, ind) : NULL;
}
// Multiname::IsAnyType (0x1424198d0) as the exe inlines it here.
static __forceinline bool Sfr21IsAnyType(const Multiname& mn)
{
    return mn.Name.IsNullOrUndefined() || (mn.Name.IsString() && mn.Name.AsString().IsEmpty());
}
struct Sfr21SlotIter
{
    explicit Sfr21SlotIter(const Slots& p) : Ind(0), Parent(&p) {}
    bool IsEnd() const { return static_cast<UInt32>(Ind.Get()) >= Parent->GetSlotInfoNum(); }
    void Next()
    {
        if (Ind < Parent->GetSlotInfoNum())
            Ind = AbsoluteIndex(Ind.Get() + 1);
    }
    AbsoluteIndex Ind;
    const Slots*  Parent;
};

// Traits::AddInterfaceSlots: for every interface the ABC class implements (its instance traits, then the parent
// interfaces), each interface slot not yet present gets an alias of the public slot of that name, or for an
// interface class a copy bound to the interface's methods. VerifyError 1014 for an unknown interface, 1122 when a
// class does not implement an interface method.
// The interface slot loop is the SDK 4.3 InstanceTraits::Traits::AddInterfaceSlots body.
// MS2-FUNCTIONAL: free function in place of the Traits member (not declared in as3_obj.h); the outer interface
// resolution keeps its own register allocation (the exe holds self in r12 and forms &Slots after the lookup)
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
        if (Sfr21IsAnyType(mn))
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
            Sfr31VMRaiseError(reinterpret_cast<UPInt>(&vm), reinterpret_cast<const unsigned long*>(&err),
                              reinterpret_cast<UPInt>(&fl::VerifyErrorCI));
            return;
        }

        for (Sfr21SlotIter it(*itr); !it.IsEnd(); it.Next())
        {
            ASString interfaceSlotName(Sfr21GetSlotNameNode(*it.Parent, it.Ind));
            const SlotInfo& interfaceSlot = Sfr21GetSlotInfo(*it.Parent, it.Ind);

            const SlotInfo* thisSlot = Sfr21FindSlotInfo(slots, interfaceSlotName, *interfaceSlot.pNs);
            if (!thisSlot)
            {
                const AbsoluteIndex pub = slots.FindSlotInfoIndex(interfaceSlotName, vm.GetPublicNamespace());
                thisSlot = pub.IsValid() ? &Sfr21GetSlotInfo(slots, pub) : NULL;
                if (thisSlot)
                {
                    // Alias the public slot under the interface namespace.
                    SlotInfo newSlot(*thisSlot);
                    newSlot.pNs = &*interfaceSlot.pNs;
                    slots.Add(interfaceSlotName, newSlot);
                }
                else
                {
                    if (info.inst_info.IsInterface())
                    {
                        // An interface method: mark its namespace and copy the slot, bound to the interface's
                        // methods.
                        SlotInfo::BindingType binding_type = static_cast<SlotInfo::BindingType>(interfaceSlot.BindType);
                        AbsoluteIndex ind(-1);
                        *reinterpret_cast<UPInt*>(reinterpret_cast<char*>(
                            const_cast<Instances::Namespace*>(interfaceSlot.pNs.GetPtr())) + 0x20) |= 0x10;

                        ind = Sfr21FindSlotInfoIndex(slots, interfaceSlotName, *interfaceSlot.pNs);
                        if (!ind.IsValid())
                            ind = slots.Add(interfaceSlotName, interfaceSlot);
                        SlotInfo& si = self->GetOwnSlotInfo(ind);

                        switch (binding_type)
                        {
                        case SlotInfo::BT_Code:
                        case SlotInfo::BT_Get:
                            {
                                const Value& vt_value = itr->GetVT().VTMethods[interfaceSlot.ValueInd];
                                si.Bind(binding_type, self->GetVT().AddMethod(vt_value, binding_type,
                                                                              ASString(si.Name.GetPtr())));
                            }
                            break;
                        case SlotInfo::BT_Set:
                            {
                                const Value& vt_value = itr->GetVT().VTMethods[interfaceSlot.ValueInd + 1];
                                si.Bind(binding_type, self->GetVT().AddMethod(vt_value, binding_type,
                                                                              ASString(si.Name.GetPtr())));
                            }
                            break;
                        case SlotInfo::BT_GetSet:
                            {
                                binding_type = SlotInfo::BT_Get;
                                const Value& vt_value = itr->GetVT().VTMethods[interfaceSlot.ValueInd];
                                si.Bind(binding_type, self->GetVT().AddMethod(vt_value, binding_type,
                                                                              ASString(si.Name.GetPtr())));
                            }
                            {
                                binding_type = SlotInfo::BT_Set;
                                const Value& vt_value = itr->GetVT().VTMethods[interfaceSlot.ValueInd + 1];
                                si.Bind(binding_type, self->GetVT().AddMethod(vt_value, binding_type,
                                                                              ASString(si.Name.GetPtr())));
                            }
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        VM::Error err(static_cast<VM::ErrorID>(1122), vm, interfaceSlotName.ToCStr());
                        Sfr31VMRaiseError(reinterpret_cast<UPInt>(&vm), reinterpret_cast<const unsigned long*>(&err),
                                          reinterpret_cast<UPInt>(&fl::VerifyErrorCI));
                        return;
                    }
                }
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

    // TR::State(const State&): member copies; the register-changed bits get their own block from the same heap.
    Sfr21TrState(const Sfr21TrState& src)
        : pTracer(src.pTracer), BCP(src.BCP), OpcodeCP(src.OpcodeCP), Registers(src.Registers), OpStack(src.OpStack),
          ScopeStack(src.ScopeStack), BitCount(src.BitCount)
    {
        const UInt32 bitCount = BitCount;
        MemoryHeap* heap = Memory::GetHeapByAddress(src.RegChanged);
        const UPInt bytes = (bitCount + 7) >> 3;
        RegChanged = static_cast<UInt8*>(Memory::AllocInHeap(heap, bytes, AllocInfo(0x155, 0, 0)));
        memcpy(RegChanged, src.RegChanged, bytes);
    }
    void* operator new(size_t size, MemoryHeap* heap) throw() { return heap->Alloc(size, (const AllocInfo*)0); }
    void operator delete(void*, MemoryHeap*) {}
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
// The opcode test is the SDK's switch over the int-sized Code::OpCode (a UInt8 operand lets cl fold the
// op_debug..op_debugfile range). Tracer members are private, so raw offsets are used.
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
        enum Sfr16zOpCode { op_label = 0x09, op_debug = 0xef, op_debugline = 0xf0, op_debugfile = 0xf1 };
        const Sfr16zOpCode curr_opcode = static_cast<Sfr16zOpCode>((*reinterpret_cast<const UInt8**>(t + 0x50))[from]);
        switch (curr_opcode)
        {
        case op_label:
        case op_debug:
        case op_debugline:
        case op_debugfile:
            is_dead = false;
            break;
        default:
            break;
        }
    }

    // The heap is read from the tracer at each use (no local), as in the exe.
    Sfr21TrState* state = new (*reinterpret_cast<MemoryHeap**>(t + 0x18)) Sfr21TrState(*static_cast<const Sfr21TrState*>(st));
    reinterpret_cast<ArrayDH<void*>*>(t + 0xf0)->PushBack(state);

    if (type == 1 && !is_dead)
        type = 0;

    if (onlyCreateState)
    {
        block->Type |= type;
        block->pState = state;
        return block;
    }

    Sfr21TrBlock* node = new (*reinterpret_cast<MemoryHeap**>(t + 0x18)) Sfr21NewTrBlock(from, type, state);
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
#ifdef MS2_HOOK_DLL
void FUN_14257eb30(void* p);
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" void __identifier("??1EntryData@ContextImpl@Render@Scaleform@@UEAA@XZ")(void* p);
#define FUN_14257eb30 __identifier("??1EntryData@ContextImpl@Render@Scaleform@@UEAA@XZ")
#endif
void FUN_1424dc630(void* p);
void FUN_1424de650(void* p);            // MovieRoot::~MovieRoot
typedef ArrayDataBase<SPtr<Instances::Namespace>, AllocatorLH<SPtr<Instances::Namespace>, 2>, ArrayDefaultPolicy> Sfr16zNsArr; // (C3) FUN_1423f0720 = its dtor
void FUN_1424df070(void* p);            // Tracer::~Tracer
void FUN_1424df380(void* p);            // VM::~VM
}

static inline char* Sfr21At(void* p, UPInt off) { return static_cast<char*>(p) + off; }
static inline void* Sfr21Mem(void* p, UPInt off) { return *reinterpret_cast<void**>(Sfr21At(p, off)); }
// The base vftables the inlined base destructors store before the out-of-line base destructor runs.
extern const void* DAT_14317c9e0[];     // GFx::MovieDefRootNode
extern const void* DAT_14317afe8[];     // empty interface (0x1424e2e70)
#ifdef MS2_HOOK_DLL
extern const void* DAT_14317b750[];     // VMAbcFile
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const void* __identifier("??_7VMAbcFile@AS3@GFx@Scaleform@@6B@")[];     // VMAbcFile
#define DAT_14317b750 __identifier("??_7VMAbcFile@AS3@GFx@Scaleform@@6B@")
#endif
#ifdef MS2_HOOK_DLL
extern const void* DAT_14317bde0[];     // ASMovieRootBase
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const void* __identifier("??_7ASMovieRootBase@GFx@Scaleform@@6B@")[];     // ASMovieRootBase
#define DAT_14317bde0 __identifier("??_7ASMovieRootBase@GFx@Scaleform@@6B@")
#endif
//
//
extern const void* DAT_14317d8a8[];     // ASVM::AbcFileWithMovieDef
#ifdef MS2_HOOK_DLL
extern const void* DAT_14317d8c0[];     // AS3::MovieDefRootNode
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const void* __identifier("??_7MovieDefRootNode@AS3@GFx@Scaleform@@6B@")[];     // AS3::MovieDefRootNode
#define DAT_14317d8c0 __identifier("??_7MovieDefRootNode@AS3@GFx@Scaleform@@6B@")
#endif
extern const void* DAT_14317de60[];     // AvmLoader
extern const void* DAT_14317e228[];     // AvmLoader +0x18
extern const void* DAT_14317e330[];     // AvmLoader +0x140
extern const void* DAT_14317e3e8[];     // AvmLoader +0x150
extern const void* DAT_14317f848[];     // empty class (0x1424e2c90, 0x1424e3a00)
static inline void Sfr21GVft(void* p, UPInt off, const void* const* vft)
{
    *reinterpret_cast<const void* const**>(Sfr21At(p, off)) = vft;
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
static void Sfr21GShapeData(void* p)
{
    FUN_1424dc350(Sfr21At(p, 0x30));
    FUN_1424dc260(Sfr21At(p, 0x18));
    static_cast<Scaleform::RefCountImplCore*>(p)->Scaleform::RefCountImplCore::~RefCountImplCore();
}
// StateData::destroyBag_NotEmpty is protected; this view only names it.
struct Sfr21StateDataAccess : Scaleform::Render::StateData
{
    static void DestroyBag(Scaleform::Render::StateData* bag) { (bag->*&Sfr21StateDataAccess::destroyBag_NotEmpty)(); }
};
static void Sfr21GNodeData(void* p)
{
    if (Sfr21Mem(p, 0x40))
        Sfr21StateDataAccess::DestroyBag(reinterpret_cast<Scaleform::Render::StateData*>(Sfr21At(p, 0x40)));
    FUN_14257eb30(p);
}

// ASRefCountCollector
// @0x1424e2290
void* DeleteAs3_1424e2290(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::RefCountCollector<323>*>(p)->Scaleform::GFx::AS3::RefCountCollector<323>::~RefCountCollector(); Sfr21GFree(p, flags, 0xb8); return p; }

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
    static_cast<Scaleform::Render::Text::Allocator*>(p)->Scaleform::Render::Text::Allocator::~Allocator();
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
    static_cast<Scaleform::GFx::AS3::AvmBitmap*>(p)->Scaleform::GFx::AS3::AvmBitmap::~AvmBitmap();
    Sfr21GFree(p, flags, 0xd0);
    return p;
}
//
//
//
//
//
//
//

// AvmInteractiveObj-family wrappers: never heap-freed (the sized-delete path only); the implicit destructors inline
// @0x1424e26d0
void* DeleteAs3_1424e26d0(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::AvmButton*>(p)->Scaleform::GFx::AS3::AvmButton::~AvmButton(); Sfr21GInPlaceFree(p, flags, 0x48); return p; }

// @0x1424e2760
void* DeleteAs3_1424e2760(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::AvmDisplayObj*>(p)->Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(); Sfr21GInPlaceFree(p, flags, 0x30); return p; }

// @0x1424e27d0
void* DeleteAs3_1424e27d0(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::AvmDisplayObjContainer*>(p)->Scaleform::GFx::AS3::AvmDisplayObjContainer::~AvmDisplayObjContainer(); Sfr21GInPlaceFree(p, flags, 0x48); return p; }

// @0x1424e29a0
void* DeleteAs3_1424e29a0(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::AvmSprite*>(p)->Scaleform::GFx::AS3::AvmSprite::~AvmSprite(); Sfr21GInPlaceFree(p, flags, 0x68); return p; }

// @0x1424e2a10
void* DeleteAs3_1424e2a10(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::AvmDisplayObjContainer*>(p)->Scaleform::GFx::AS3::AvmDisplayObjContainer::~AvmDisplayObjContainer(); Sfr21GInPlaceFree(p, flags, 0x48); return p; }

// @0x1424e2ac0
void* DeleteAs3_1424e2ac0(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::AvmTextField*>(p)->Scaleform::GFx::AS3::AvmTextField::~AvmTextField(); Sfr21GInPlaceFree(p, flags, 0x48); return p; }

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
void* DeleteAs3_1424e2d80(void* p, unsigned flags) { static_cast<FileLoader*>(p)->FileLoader::~FileLoader(); if (flags & 1) ::operator delete(p, 8); return p; }

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
    ConstructorMov<Value>::DestructArray(static_cast<Value*>(Sfr21Mem(p, 0x38)), reinterpret_cast<UPInt>(Sfr21Mem(p, 0x40)));
    Memory::pGlobalHeap->Free(Sfr21Mem(p, 0x38));
    Sfr21GSPtr(p, 0x30);
    Sfr21GValue(p, 0x10);
    static_cast<ASIntervalTimerIntf*>(p)->ASIntervalTimerIntf::~ASIntervalTimerIntf();
    Sfr21GFree(p, flags, 0x70);
    return p;
}

// @0x1424e3260
void* DeleteAs3_1424e3260(void* p, unsigned flags)
{
    static_cast<FileLoader*>(p)->FileLoader::~FileLoader();
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
    reinterpret_cast<Sfr16zNsArr*>(Sfr21At(p, 0x20))->Sfr16zNsArr::~Sfr16zNsArr();
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
    Sfr21GVft(p, 0, Scaleform::Render::TreeShapeNodeDataVTable);
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
    static_cast<Scaleform::GFx::AS3::ShapeObject*>(p)->Scaleform::GFx::AS3::ShapeObject::~ShapeObject();
    Sfr21GFree(p, flags, 0xd0);
    return p;
}
//
//
//
//
//
//
//

// The Stage deleting dtor (0x1424e3950) is in sfr_as3_16, next to ~Stage.

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
    static_cast<Scaleform::GFx::AS3::Traits*>(p)->Scaleform::GFx::AS3::Traits::~Traits();
    Sfr21GFree(p, flags, 0xc8);
    return p;
}

// The UDBase deleting dtor (0x1424e3d60) is in sfr_as3_16, next to ~UDBase.

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
    reinterpret_cast<Scaleform::SfrHsNs*>(Sfr21At(p, 0x30))->Clear();
    reinterpret_cast<Scaleform::SfrHsNs*>(Sfr21At(p, 0x30))->~HashSetBase();
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

// XMLSupport (its inline dtor stores the vptr, then GASRefCountBase's dtor runs)
// @0x1424e4120
void* DeleteAs3_1424e4120(void* p, unsigned flags) { static_cast<Scaleform::GFx::AS3::XMLSupport*>(p)->Scaleform::GFx::AS3::XMLSupport::~XMLSupport(); Sfr21GFree(p, flags, 0x28); return p; }

// The XMLSupportImpl deleting dtor (0x1424e4190) is in sfr_as3_16, next to ~XMLSupportImpl.



// ==== AvmSprite::AddDisplayObject ====================================================================================

extern "C" {
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

}}} // namespace Scaleform::GFx::AS3
Scaleform::GFx::AS3::Value& FUN_1424e0d40(Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::ASString& str);   // Value = ASString (sfr_as3_19)
namespace Scaleform { namespace GFx { namespace AS3 {
void Sfr27MultinameFromQName(Multiname* mn, const Value* v);   // 0x1425273b0 (sfr_as3_19)

// Multiname::PostProcessName(false) (0x14251cef0), as the exe inlines it into the constructor below.
static __forceinline void Sfr16zPostProcessName(Multiname& mn)
{
    if (!mn.Name.IsString())
        return;
    ASString n = mn.Name.AsString();
    if (n.GetSize() == 0)
        return;
    if (n[0] == '*')
        FUN_1424e0d40(mn.Name, ASString(n.GetManager()->GetEmptyStringNode()));
    else if (n[0] == '@')
    {
        mn.Kind = static_cast<Abc::MultinameKind>(mn.Kind | 8);
        if (n.GetSize() == 2 && n[1] == '*')
            FUN_1424e0d40(mn.Name, ASString(n.GetManager()->GetEmptyStringNode()));
        else
            FUN_1424e0d40(mn.Name, ASString(n.SubstringNode(1, n.GetSize())));
    }
}

// Multiname(Namespace&, const Value&) (0x1424d8a90) with SetRTNameUnsafe and PostProcessName, as the exe inlines
// them into AddDisplayObject (the same body as sfr_as3_19's copy).
__forceinline Multiname::Multiname(Instances::Namespace& ns, const Value& name, InlineCtorTag)
    : Kind(static_cast<Abc::MultinameKind>(0))
    , Obj(&ns)
{
    const UInt32 k = static_cast<UInt32>(name.GetKind());
    if (k - 0xc <= 3 && name.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(name.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
        {
            Sfr27MultinameFromQName(this, &name);
            return;
        }
    }
    Name.AssignUnsafe(name);
    Sfr16zPostProcessName(*this);
}

// Value(const ASString&) (0x1424dbf70) as the exe inlines it here (the sfr_as3_17d copy).
SF_FORCEINLINE Value::Value(const ASString& v, InlineStrType)
    : Flags(kString)
    , value(v.GetNode())
{
    if (v.GetNode() == v.GetManager()->GetNullStringNode())
    {
        SetKind(kObject);
        value = (Object*)NULL;
    }
    else
        value.VS._1.VStr->AddRef();
}

struct Sfr16zCCInfo { void* pCharDef; void* pBindDefImpl; void* pResource; };   // CharacterCreateInfo
// ResourceId by value: its copy constructor makes the caller pass a pointer to a temporary.
struct Sfr16zRId { unsigned Id; Sfr16zRId(unsigned id) : Id(id) {} Sfr16zRId(const Sfr16zRId& o) : Id(o.Id) {} };
typedef Sfr16zCCInfo (Scaleform::GFx::MovieDefImpl::*Sfr16zGetCCIFn)(Sfr16zRId);

// Places character pos.CharacterId at pos.Depth: an object of the same character, name and creation frame already there
// is moved instead (its AS3 name property reset on the parent); else a new instance is created, named, added to the
// display list, given its AS3 object (the name property set on this sprite before the constructor runs) and its
// children, and told it was added.
// CharPosInfo: ColorTransform +0, pFilters +0x40, Depth +0x4c, CharacterId +0x50, ClassName +0x58, BlendMode +0x64,
// Flags +0x62 (0x08 HasCxform, 0x80 HasBlendMode, 0x100 HasClassName); 0x68 bytes.
// The flag tests are written (UByte)(Flags >> N) & 1, which gives the exe's movzx/shr/test.
// MS2-FUNCTIONAL: SDK 4.2 statement order on raw display object offsets. The exe also inlines Value::AssignUnsafe in
// both Multiname constructors (cl tail-duplicates it and merges the AddRef arms), copies newPos member by member (ours
// is a memcpy), and keeps createFrame on the stack (ours holds it in r12, so the saved registers differ).
// @0x1424e7140
DisplayObjectBase* AvmSprite::AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                               const ArrayLH<SwfEvent*, StatMD_Tags_Mem>*, const void*,
                                               unsigned createFrame, unsigned long addFlags,
                                               CharacterCreateInfo* pcharCreateOverride, InteractiveObject* origChar)
{
    const char* P        = reinterpret_cast<const char*>(&pos);
    void*       pdefImpl = Sfr21Mem(pDispObj, 0xb0);
    char*       thisSpr  = reinterpret_cast<char*>(pDispObj);
    bool placeObject              = (addFlags & 4) != 0;
    bool replaceIfDepthIsOccupied = (addFlags & 1) != 0;

    int    type = 0;
    Sfr16zCCInfo ccinfo;
    if (pcharCreateOverride)
        ccinfo = *reinterpret_cast<Sfr16zCCInfo*>(pcharCreateOverride);
    else
        ccinfo = (static_cast<Scaleform::GFx::MovieDefImpl*>(pdefImpl)->*reinterpret_cast<Sfr16zGetCCIFn>(
            &Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo))(Sfr16zRId(*reinterpret_cast<const unsigned*>(P + 0x50)));
    if (!ccinfo.pCharDef)
    {
        if (*reinterpret_cast<const UByte*>(P + 0x63) & 1)
        {
            struct { void* pResource; void* pBinding; } resBindData = { NULL, NULL };
            bool found;
            {
                String className(*reinterpret_cast<const char* const*>(P + 0x58));
                found = static_cast<MovieImpl*>(Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x10))->FindExportedResource(static_cast<MovieDefImpl*>(pdefImpl),
                    reinterpret_cast<ResourceBindData*>(&resBindData), className);
            }
            if (found)
            {
                // Resource::RT_CharacterDef_Bit
                if (Sfr21VCall<unsigned>(resBindData.pResource, 0x10) & 0x8000)
                    ccinfo.pCharDef = resBindData.pResource;
                else
                    ccinfo.pResource = resBindData.pResource;
                ccinfo.pBindDefImpl = Sfr21Mem(resBindData.pBinding, 0x48);
            }
            if (resBindData.pResource)
                reinterpret_cast<Scaleform::GFx::Resource*>(resBindData.pResource)->Release();
        }
        if (!ccinfo.pCharDef)
        {
            // An image resource placed on the stage becomes a Bitmap character.
            if (ccinfo.pResource && (Sfr21VCall<unsigned>(ccinfo.pResource, 0x10) & 0xff00) == 0x100)
            {
                type = 8;
                if (!ccinfo.pBindDefImpl)
                    ccinfo.pBindDefImpl = pdefImpl;
            }
            else
            {
                reinterpret_cast<DisplayObjectBase*>(pDispObj)->LogError("Sprite::AddDisplayObject(): unknown cid = %d\n",
                    unsigned(*reinterpret_cast<const UInt16*>(P + 0x50)));
                return NULL;
            }
        }
    }

    bool  markedForRemove = false;
    char* pexistingChar = reinterpret_cast<char*>(reinterpret_cast<Scaleform::GFx::DisplayList*>(thisSpr + 0xd8)->GetDisplayObjectAtDepth(
        *reinterpret_cast<const int*>(P + 0x4c), &markedForRemove));

    unsigned frame = (createFrame == ~0u) ? Sfr21VCall<unsigned>(thisSpr, 0x328) : createFrame;   // GetCurrentFrame
    if (placeObject)
    {
        // AcceptAnimMoves +0x178, ContinueAnimation +0x180, SetAcceptAnimMoves +0x188
        if (pexistingChar)
        {
            if (!Sfr21VCall<bool>(pexistingChar, 0x178) && Sfr21VCall<bool>(pexistingChar, 0x180))
                Sfr21VCall<void, bool>(pexistingChar, 0x188, true);
        }
        if (!markedForRemove && pexistingChar && !Sfr21VCall<bool>(pexistingChar, 0x178))
            return NULL;

        if (pexistingChar && *reinterpret_cast<int*>(pexistingChar + 0x2c) >= -1 &&
            *reinterpret_cast<unsigned*>(pexistingChar + 0x28) == *reinterpret_cast<const unsigned*>(P + 0x50))
        {
            ASString originalName(static_cast<ASStringNode*>(Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x160)));   // builtin ""
            if ((UByte)(*reinterpret_cast<UInt16*>(pexistingChar + 0x6a) >> 7) & 1)
                originalName = reinterpret_cast<Scaleform::GFx::DisplayObject*>(pexistingChar)->GetOriginalName();

            if (!((UByte)(*reinterpret_cast<UInt16*>(pexistingChar + 0x6a) >> 7) & 1) ||
                (name.IsEmpty() && originalName.IsEmpty()) ||
                (name.IsEmpty() && ((UByte)(*reinterpret_cast<UByte*>(pexistingChar + 0x88) >> 1) & 1)) ||   // instance-based name
                (!name.IsEmpty() && originalName.GetNode() == name.GetNode()))
            {
                if (*reinterpret_cast<unsigned*>(pexistingChar + 0x30) == frame)
                {
                    char newPos[0x68];
                    memcpy(newPos, P, sizeof(newPos));
                    if (void* filters = Sfr21Mem(newPos, 0x40))
                        reinterpret_cast<Scaleform::RefCountImpl*>(filters)->AddRef();
                    if (!((UByte)(*reinterpret_cast<const UInt16*>(P + 0x62) >> 7) & 1) && Sfr21VCall<int>(pexistingChar, 0x68))   // GetBlendMode
                    {
                        *reinterpret_cast<UInt16*>(newPos + 0x62) |= 0x80;
                        newPos[0x64] = 0;
                    }
                    if (!((UByte)(*reinterpret_cast<const UInt16*>(P + 0x62) >> 3) & 1) && !reinterpret_cast<DisplayObjectBase*>(pexistingChar)->GetCxform().IsIdentity())
                    {
                        *reinterpret_cast<UInt16*>(newPos + 0x62) |= 8;
                        reinterpret_cast<Scaleform::Render::Cxform*>(newPos)->SetIdentity();
                    }
                    reinterpret_cast<Scaleform::GFx::DisplayObjContainer*>(thisSpr)->MoveDisplayObject(*reinterpret_cast<const Scaleform::GFx::CharPosInfo*>(newPos));

                    // The object is reused: its name property on the AS3 parent is set again.
                    if (*reinterpret_cast<UByte*>(pexistingChar + 0x6b) & 1)
                    {
                        AvmDisplayObj* avmEexistObj = reinterpret_cast<AvmDisplayObj*>(Sfr21Avm(pexistingChar));
                        Instances::fl_display::DisplayObject* as3existObjParent = avmEexistObj->GetAS3Parent();
                        if (!((UByte)(*reinterpret_cast<UByte*>(pexistingChar + 0x88) >> 1) & 1) && as3existObjParent)
                        {
                            const ASString& nm = reinterpret_cast<Scaleform::GFx::DisplayObject*>(pexistingChar)->GetName();
                            reinterpret_cast<Object*>(as3existObjParent)->SetProperty(
                                Multiname(static_cast<VM*>(Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x48))->GetPublicNamespace(), Value(nm, Value::InlineStr), Multiname::InlineCtorTag()),
                                Value(reinterpret_cast<Object*>(avmEexistObj->GetAS3Obj())));
                        }
                    }
                    if (void* filters = Sfr21Mem(newPos, 0x40))
                        reinterpret_cast<Scaleform::RefCountImpl*>(filters)->Release();
                    return NULL;
                }
                replaceIfDepthIsOccupied = true;
            }
        }
    }
    else
        replaceIfDepthIsOccupied = true;
    ::Scaleform::ConstructorMov<::Scaleform::GFx::ASSoundIntf*>::Construct(thisSpr);   // SetDirtyFlag

    void* asSupport = Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x18);
    char* ch = (*reinterpret_cast<char* (**)(void*, void*, void*, void*, const unsigned*, int)>(
        *static_cast<char**>(asSupport) + 0x20))(asSupport, Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x10), &ccinfo, thisSpr,
        reinterpret_cast<const unsigned*>(P + 0x50), type);   // CreateCharacterInstance
    char* intObj  = ((UByte)(*reinterpret_cast<UInt16*>(ch + 0x6a) >> 7) & 1) ? ch : NULL;
    bool  nameSet = false;
    *reinterpret_cast<UInt16*>(ch + 0x6a) &= ~1;   // SetScale9GridExists(false)
    if (intObj)
    {
        if (!name.IsEmpty())
        {
            reinterpret_cast<DisplayObject*>(intObj)->SetOriginalName(name);
            nameSet = true;
        }
        if (origChar)
            Sfr21VCall<void, InteractiveObject*>(intObj, 0x2c0, origChar);   // CloneInternalData
    }
    if (!(addFlags & 4))
        Sfr21VCall<void, bool>(ch, 0x188, false);
    else
        *reinterpret_cast<UInt16*>(ch + 0x88) |= 1;   // timeline object
    *reinterpret_cast<unsigned*>(ch + 0x30) = frame;

    addFlags &= ~1u;
    if (replaceIfDepthIsOccupied)
        addFlags |= 1;
    if (*reinterpret_cast<const UByte*>(P + 0x63) & 1)
        reinterpret_cast<AvmDisplayObj*>(Sfr21Avm(ch))->InitClassName(*reinterpret_cast<const char* const*>(P + 0x58));
    reinterpret_cast<DisplayList*>(thisSpr + 0xd8)->AddDisplayObject(reinterpret_cast<DisplayObjectBase*>(pDispObj), pos,
        reinterpret_cast<DisplayObjectBase*>(ch), addFlags);

    AvmDisplayObj* avmObj = reinterpret_cast<AvmDisplayObj*>(Sfr21Avm(ch));
    if (avmObj->CreateASInstanceNoCtor(false))
    {
        if (!((UByte)(*reinterpret_cast<UInt16*>(ch + 0x88) >> 1) & 1) && avmObj->GetAS3Parent())
        {
            // init name property before calling ctor
            reinterpret_cast<Object*>(GetAS3Obj())->SetProperty(
                Multiname(static_cast<VM*>(Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x48))->GetPublicNamespace(), Value(name, Value::InlineStr), Multiname::InlineCtorTag()),
                Value(reinterpret_cast<Object*>(avmObj->GetAS3Obj())));
            if (static_cast<VM*>(Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x48))->IsException())
            {
                static_cast<VM*>(Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x48))->OutputAndIgnoreException();
                *reinterpret_cast<UInt16*>(reinterpret_cast<char*>(pDispObj) + 0x88) |= 0x20;   // execution aborted
            }
        }
        avmObj->CallCtor(true);

        // A sprite gets its children now.
        if ((UByte)(*reinterpret_cast<UInt16*>(ch + 0x6a) >> 10) & 1)
        {
            char* a = Sfr21Avm(ch);
            if (!(a[0x60] & AvmSprite::Flag_ChildrenCreated))
            {
                char* sp = static_cast<char*>(Sfr21Mem(a, 0x18));
                if (!reinterpret_cast<InteractiveObject*>(sp)->IsInPlayList() && Sfr21Mem(sp, 0x38) &&
                    static_cast<InteractiveObject*>(Sfr21Mem(sp, 0x38))->IsInPlayList())
                {
                    reinterpret_cast<AvmDisplayObj*>(a)->GetAvmParent()->InsertChildToPlayList(reinterpret_cast<InteractiveObject*>(sp));
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
    }

    if (nameSet)
        Sfr21VCall<void, void*>(Sfr21Mem(pDispObj, 0x20), 0xf0, intObj);   // ResolveStickyVariables
    if (intObj && nameSet)
    {
        if (name.GetNode() == Sfr21Mem(Sfr21Mem(pDispObj, 0x20), 0x1c8))   // builtin "hitArea"
            reinterpret_cast<Sprite*>(thisSpr)->SetHitArea(reinterpret_cast<Sprite*>(intObj));
    }
    if (intObj)
    {
        char* base = Sfr21VCall<char*>(Sfr21Avm(intObj), 8);         // ToAvmInteractiveObjBase
        Sfr21VCall<void, bool>(base ? base - 0x30 : NULL, 0x98, true);   // OnAdded
    }
    reinterpret_cast<const Scaleform::RefCountNTSImpl*>(ch)->Release();
    return reinterpret_cast<DisplayObjectBase*>(ch);
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace Render {

}} // namespace Scaleform::Render
namespace Scaleform { namespace GFx { namespace AS3 {
void* Sfr31LinearHeapAllocFromLastPage(UPInt self, UPInt n);   // 0x142532060, LinearHeap::allocFromLastPage
}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace Render {

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
        void* p = GFx::AS3::Sfr31LinearHeapAllocFromLastPage(reinterpret_cast<UPInt>(self), size);
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
    return GFx::AS3::Sfr31LinearHeapAllocFromLastPage(reinterpret_cast<UPInt>(self), size);
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
// (sfg) ASIntervalTimerIntf's vftable and deleting destructor (0x1424e21a0).
struct __declspec(novtable) Unk_As3_16zTimerIntfProbe : ASIntervalTimerIntf
{
    Unk_As3_16zTimerIntfProbe();
};
Unk_As3_16zTimerIntfProbe::Unk_As3_16zTimerIntfProbe() {}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7FileLoader@AS3@GFx@Scaleform@@6B@ 0x14317b798
// MS2-PIN: ??_7Allocator@Text@Render@Scaleform@@6B@ 0x14317c9d0
// MS2-PIN: ??_GFrameCounter@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2de0
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
// MS2-PIN: ??_GASIntervalTimerIntf@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e21a0
// MS2-PIN: ??_7?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14317b040
// MS2-PIN: ??_7Root@?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14317b010
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7?$RefCountBase@V?$RefCountCollector@$0BED@@AS3@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
// MS2-PIN: ??_7ASIntervalTimerIntf@GFx@Scaleform@@6B@ 0x14317c9f8
// MS2-PIN: ??_7?$RefCountBase@VASIntervalTimerIntf@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317c9f8
// MS2-PIN: ??_7ShapeObject@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317c210
// MS2-PIN: ??_7ShapeObject@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317c488
// MS2-PIN: ??_7ShapeObject@AS3@GFx@Scaleform@@6B@ 0x14317c498
// MS2-PIN: ??_7AvmBitmap@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317c560
// MS2-PIN: ??_7AvmBitmap@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317c7d8
// MS2-PIN: ??_7AvmBitmap@AS3@GFx@Scaleform@@6B@ 0x14317c7e8

namespace Scaleform { namespace GFx { namespace AS3 {
// Defined outside sfr_as3_15: the exe's callers there (GamePadAnalogEvent::toString 0x1424cc0f0) reload the string
// node after the call, as cl does for a body it cannot see.
// @0x1424dbf70
SF_NOINLINE Value::Value(const ASString& v)
    : Flags(kString)
    , value(v.GetNode())
{
    if (v.GetNode() == v.GetManager()->GetNullStringNode())
    {
        SetKind(kObject);
        value = (Object*)NULL;
    }
    else
        value.VS._1.VStr->AddRef();
}
}}} // namespace Scaleform::GFx::AS3
// MS2-PIN: ??_7XMLSupport@AS3@GFx@Scaleform@@6B@ 0x14317b7b8
