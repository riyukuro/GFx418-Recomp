// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 virtual machine core. Our own
// source, written from the exe.
// MS2-UNIT: sfr_as3_16
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424dc870-0x1424dd500 .text$mn
// MS2-RANGE: 0x1424dda00-0x1424ddb00 .text$mn
// MS2-RANGE: 0x1424ddb00-0x1424ddb74 .text$mn
// MS2-RANGE: 0x1424ddb74-0x1424ddb80 .text$mn
// MS2-RANGE: 0x1424ddbee-0x1424ddcb0 .text$mn
// MS2-RANGE: 0x1424ddcb0-0x1424ddce0 .text$mn
// MS2-RANGE: 0x1424ddd4f-0x1424de0e0 .text$mn
// MS2-RANGE: 0x1424de0e0-0x1424e0a70 .text$mn
// MS2-RANGE: 0x1424e0b40-0x1424e2040 .text$mn
// MS2-RANGE: 0x1424e2210-0x1424e2290 .text$mn
// MS2-RANGE: 0x1424e28e0-0x1424e29a0 .text$mn
// MS2-RANGE: 0x1424e2bb0-0x1424e2c10 .text$mn
// MS2-RANGE: 0x1424e3020-0x1424e3150 .text$mn
// MS2-RANGE: 0x1424e3150-0x1424e31e0 .text$mn
// MS2-RANGE: 0x1424e31e0-0x1424e3260 .text$mn
// MS2-RANGE: 0x1424e3290-0x1424e3380 .text$mn
// MS2-RANGE: 0x1424e3380-0x1424e33f0 .text$mn
// MS2-RANGE: 0x1424e3580-0x1424e35e0 .text$mn
// MS2-RANGE: 0x1424e3690-0x1424e3750 .text$mn
// MS2-RANGE: 0x1424e3750-0x1424e37a0 .text$mn
// MS2-RANGE: 0x1424e3bd0-0x1424e3c30 .text$mn
// MS2-RANGE: 0x1424e3cc0-0x1424e3d60 .text$mn
// MS2-RANGE: 0x1424e3950-0x1424e3a00 .text$mn
// MS2-RANGE: 0x1424e3d60-0x1424e3de0 .text$mn
// MS2-RANGE: 0x1424e3e50-0x1424e3eb0 .text$mn
// MS2-RANGE: 0x1424e4190-0x1424e4290 .text$mn
// MS2-RANGE: 0x1424e4290-0x1424e42c0 .text$mn
// MS2-RANGE: 0x1424e46f0-0x1424e4f40 .text$mn
// MS2-RANGE: 0x1424e4f40-0x1424e5500 .text$mn
// MS2-RANGE: 0x1424e5500-0x1424e5510 .text$mn
// MS2-RANGE: 0x1424e5510-0x1424e5660 .text$mn
// MS2-RANGE: 0x1424e5660-0x1424e56f0 .text$mn
// MS2-RANGE: 0x1424e56f0-0x1424e5e80 .text$mn
// MS2-RANGE: 0x1424e63b0-0x1424e6670 .text$mn
// MS2-RANGE: 0x1424e6670-0x1424e6990 .text$mn
// MS2-RANGE: 0x1424e6990-0x1424e6aa0 .text$mn
// MS2-RANGE: 0x1424e6f90-0x1424e7140 .text$mn
// MS2-RANGE: 0x1424e7f40-0x1424e8060 .text$mn
// MS2-RANGE: 0x1424e8060-0x1424e80f0 .text$mn
// MS2-RANGE: 0x1424e8c20-0x1424e8e20 .text$mn
// MS2-RANGE: 0x1424e8ed0-0x1424e9010 .text$mn
// MS2-RANGE: 0x1424e9010-0x1424e9090 .text$mn
// MS2-RANGE: 0x1424e9090-0x1424e9210 .text$mn
// MS2-RANGE: 0x1424e9210-0x1424e9330 .text$mn
// MS2-RANGE: 0x1424e9330-0x1424e9370 .text$mn
// MS2-RANGE: 0x1424e9370-0x1424e9380 .text$mn
// MS2-RANGE: 0x1424e9380-0x1424e93b0 .text$mn
// MS2-RANGE: 0x1424e93b0-0x1424e9670 .text$mn
// MS2-RANGE: 0x1424e9670-0x1424e9740 .text$mn
// MS2-RANGE: 0x1424e9740-0x1424e9830 .text$mn
// MS2-RANGE: 0x1424e9830-0x1424e9910 .text$mn
// MS2-RANGE: 0x1424e9910-0x1424e9a50 .text$mn
// MS2-RANGE: 0x1424e9a50-0x1424e9b40 .text$mn
// MS2-RANGE: 0x1424e9b40-0x1424eab60 .text$mn
// MS2-RANGE: 0x1424eaf00-0x1424eaf80 .text$mn
// MS2-RANGE: 0x1424eb610-0x1424eb640 .text$mn
// MS2-RANGE: 0x1424eb640-0x1424eb6b0 .text$mn
// MS2-RANGE: 0x1424eb6b0-0x1424eb700 .text$mn
#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp weak-ref bodies inline (as3_value.h)
#define MS2_AS3_PROPREF_DTOR_OUTLINE   // PropRef::~PropRef 0x1424de8f0 is defined here (as3_obj.h)
#define MS2_AS3_ASSIGN_NOALIAS   // one SCU in the exe: Assign/ReleaseInternal/getNext touch no caller memory (as3_value.h, as3_asvm.h)
#define SF_AS3_SHAPEOBJECT_MODEL   // ShapeObject / AvmBitmap from the SDK MI layout (as3_avm.h)
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/as3_tracer.h"
#include "ms2/scaleform/include/gfx/as3/as3_moviedefrootnode.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_udbase.h"
#include "ms2/scaleform/include/gfx/as2/as2_object.h"   // ASUserData
#include "ms2/scaleform/include/gfx/as3/as3_loadqueue.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_taskmanager.h"
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/as3_avmloader.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/gfx_shapedef.h"
#include "ms2/scaleform/include/gfx/gfx_asstringhash.h"
#include "ms2/scaleform/include/render/text_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_stage.h"
#include <algorithm>
#include <vector>
#undef GetObject   // windows.h

SF_NOINLINE void FUN_1424dc9f0(void* self);
namespace Scaleform {
// LoadQueueEntry's mBytes destructor is the out-of-line 0x1424dc9f0 in the exe.
namespace GFx { template<> inline AutoPtr<ArrayPOD<UByte> >::~AutoPtr() { FUN_1424dc9f0(this); } }

// The Multiname array destructor stays out of line in the exe (CTraits::~CTraits calls it).
// @0x1424dc870
template<> SF_NOINLINE ArrayDataBase<GFx::AS3::Multiname, AllocatorLH<GFx::AS3::Multiname, 2>, ArrayDefaultPolicy>::~ArrayDataBase()
{
    AllocatorType::DestructArray(Data, Size);
    AllocatorType::Free(Data);
}

// The weak display-object array destructor is the out-of-line 0x1424dc730 (instantiated in sfr_as3_15).
template<> SF_NOINLINE ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, 2>,
                                     ArrayDefaultPolicy>::~ArrayDataBase();
// The display-object list assignment is the SDK 4.3 one: the source keeps its pointer and only loses the ownership.
// BEHAVIOUR FIX: the header's copy assignment also clears the source pointer; the exe's 0x1424e0340 does not.
template<> AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy> >&
AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy> >::operator=(const AutoPtr& p)
{
    if (this != &p)
    {
        bool owner = p.Owner;
        AutoPtr& src = const_cast<AutoPtr&>(p);
        src.Owner = false;
        Reset(src.pObject);
        Owner = owner;
    }
    return *this;
}
// Traits' vtable holder releases through the out-of-line 0x142524290.
template<> SF_NOINLINE void AutoPtr<GFx::AS3::VTable>::Reset(GFx::AS3::VTable* p, bool owner);
// The exe inlines the whole slot-table PushBack (resize included) into SlotContainerType::Add and Slots::Add.
// Both PushBack levels need forcing; with only the ArrayBase level, the Data load moves past the Size store.
template<> __forceinline void ArrayDataBase<GFx::AS3::Slots::Pair, AllocatorLH<GFx::AS3::Slots::Pair,
    GFx::AS3::StatMV_VM_SlotInfo_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)
{
    UPInt oldSize = Size;
    if (newSize < oldSize)
    {
        AllocatorType::DestructArray(Data + newSize, oldSize - newSize);
        if (newSize < (Policy.GetCapacity() >> 1))
            Reserve(pheapAddr, newSize);
    }
    else if (newSize >= Policy.GetCapacity())
    {
        Reserve(pheapAddr, newSize + (newSize >> 2));
    }
    Size = newSize;
}
template<> __forceinline void ArrayData<GFx::AS3::Slots::Pair, AllocatorLH<GFx::AS3::Slots::Pair,
    GFx::AS3::StatMV_VM_SlotInfo_Mem>, ArrayDefaultPolicy>::PushBack(const GFx::AS3::Slots::Pair& val)
{
    BaseType::ResizeNoConstruct(this, this->Size + 1);
    AllocatorType::Construct(this->Data + this->Size - 1, val);
}
template<> __forceinline void ArrayBase<ArrayData<GFx::AS3::Slots::Pair, AllocatorLH<GFx::AS3::Slots::Pair,
    GFx::AS3::StatMV_VM_SlotInfo_Mem>, ArrayDefaultPolicy> >::PushBack(const GFx::AS3::Slots::Pair& val)
{
    Data.PushBack(val);
}
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {
// (sfg) the call readers' implicit destructors (AS3_VMRead.h; 4.1 layout: ReadArgsMn also derives from MnReader).
class Sfr16MnReader
{
    VMAbcFile& File;
};
struct Sfr16ReadArgsObject : public ReadArgs
{
    Value ArgObject;                    // +0x138
};
struct Sfr16ReadArgsMn : public ReadArgs, public Sfr16MnReader
{
    Multiname ArgMN;                    // +0x140
};
struct Sfr16ReadArgsMnObject : public Sfr16ReadArgsMn
{
    const Value ArgObject;              // +0x170
};
namespace TR {
struct Sfr16ReadArgsObject : public ReadArgs
{
    Value ArgObject;                    // +0x140
};
struct Sfr16ReadArgsMn : public ReadArgs, public MnReader
{
    Multiname ArgMN;                    // +0x148
};
struct Sfr16ReadArgsMnObject : public Sfr16ReadArgsMn
{
    const Value ArgObject;              // +0x178
};
} // namespace TR
}}} // Scaleform::GFx::AS3

// TR::ReadArgsMnObject::~ReadArgsMnObject
// @0x1424debc0
void FUN_1424debc0(void* self)
{
    static_cast<Scaleform::GFx::AS3::TR::Sfr16ReadArgsMnObject*>(self)->~Sfr16ReadArgsMnObject();
}

// ReadArgsMnObject::~ReadArgsMnObject
// @0x1424deb40
void FUN_1424deb40(void* self)
{
    static_cast<Scaleform::GFx::AS3::Sfr16ReadArgsMnObject*>(self)->~Sfr16ReadArgsMnObject();
}

// ReadArgsObject::~ReadArgsObject
// @0x1424dec40
void FUN_1424dec40(void* self)
{
    static_cast<Scaleform::GFx::AS3::Sfr16ReadArgsObject*>(self)->~Sfr16ReadArgsObject();
}

// TR::ReadArgsObject::~ReadArgsObject
// @0x1424decc0
void FUN_1424decc0(void* self)
{
    static_cast<Scaleform::GFx::AS3::TR::Sfr16ReadArgsObject*>(self)->~Sfr16ReadArgsObject();
}

namespace Scaleform {
// Builds a temporary for each side and concatenates them, releasing both temporary strings afterward.
// @0x1424e0e50
String operator+(const char* left, const GFx::ASString& right)
{
    return String(left) + String(right.ToCStr(), right.GetSize());
}
}

// ASMovieRootBase::~ASMovieRootBase (0x1424dd4d0) is inline (gfx_displayobject.h); FUN_1424de650 below emits it.

namespace Scaleform { namespace GFx { namespace AS3 {
// ASVM::~ASVM (0x1424dd500) is implicit (as3_asvm.h); it is emitted with the vftable in sfr_as3_15.
}}} // namespace Scaleform::GFx::AS3

void FUN_1424de460(long long* owner);

// MovieRoot is only partially modeled, so keep its destructor out of the class vtable and recover the owned fields
// from the exe's offsets. The four MouseState rollover arrays use ArrayLH's data/size/capacity prefix.
void FUN_1424dcd40(void* self);
namespace Scaleform { void DestroyMovieRootDisplayObjects(void* set); }
// The vftables the inlined MovieRoot/ASMovieRootBase and Tracer destructors store.
namespace Scaleform { namespace GFx { namespace AS3 {
extern const void* DAT_14317d8d8[];     // MovieRoot
extern const void* DAT_14317da88[];     // MovieRoot at +0x28
extern const void* DAT_14317daa0[];     // MovieRoot at +0x38
extern const void* DAT_14317afe8[];     // ASMovieRootBase at +0x38
extern const void* DAT_14317b938[];     // Tracer
}}}

// MS2-FUNCTIONAL 0x1424de650: releases the modeled smart-pointer members, string builtins, action queue, mouse stacks,
// and ASMovieRootBase; the opaque LoadedMovieDefs table is still cleared only by its own owner path.
// @0x1424de650
extern "C" void FUN_1424de650(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    *reinterpret_cast<const void***>(bytes + 0x00) = Scaleform::GFx::AS3::DAT_14317d8d8;
    *reinterpret_cast<const void***>(bytes + 0x28) = Scaleform::GFx::AS3::DAT_14317da88;
    *reinterpret_cast<const void***>(bytes + 0x38) = Scaleform::GFx::AS3::DAT_14317daa0;
    FUN_1424dcd40(bytes + 0x6e8);

    auto* heap = Scaleform::Memory::pGlobalHeap;
    for (unsigned i = 4; i-- != 0;)
    {
        auto* state = bytes + 0x360 + i * sizeof(Scaleform::GFx::AS3::MovieRoot::MouseState);
        if (auto* over = *reinterpret_cast<void**>(state + 0x18))
            static_cast<const Scaleform::RefCountNTSImpl*>(over)->Release();
        auto** rollover = *reinterpret_cast<void***>(state);
        const auto count = *reinterpret_cast<Scaleform::UPInt*>(state + 8);
        for (Scaleform::UPInt j = count; rollover && j != 0; --j)
            if (rollover[j - 1])
                static_cast<const Scaleform::RefCountNTSImpl*>(rollover[j - 1])->Release();
        if (rollover)
            heap->Free(rollover);
    }

    auto* strings = reinterpret_cast<Scaleform::GFx::AS3::StringManager*>(bytes + 0x160);
    if (strings->pStringManager)
        strings->pStringManager->ReleaseBuiltinArray(strings->Builtins, Scaleform::GFx::AS3::AS3BuiltinConst_Count_);
    if (auto* stage = *reinterpret_cast<void**>(bytes + 0x158))
        static_cast<const Scaleform::RefCountNTSImpl*>(stage)->Release();
    Scaleform::DestroyMovieRootDisplayObjects(bytes + 0x150);
    reinterpret_cast<Scaleform::GFx::AS3::MovieRoot::ActionQueueType*>(bytes + 0x88)->~ActionQueueType();
    reinterpret_cast<Scaleform::GFx::AS3::Value*>(bytes + 0x58)->~Value();

    auto** pAvm = reinterpret_cast<Scaleform::GFx::AS3::ASVM**>(bytes + 0x48);
    if (*pAvm && *reinterpret_cast<bool*>(bytes + 0x50))
        delete *pAvm;
    *pAvm = nullptr;
    *reinterpret_cast<bool*>(bytes + 0x50) = false;

    FUN_1424de460(reinterpret_cast<long long*>(bytes + 0x40));
    *reinterpret_cast<const void***>(bytes + 0x38) = Scaleform::GFx::AS3::DAT_14317afe8;
    reinterpret_cast<Scaleform::GFx::AS3::FlashUI*>(bytes + 0x28)->Scaleform::GFx::AS3::FlashUI::~FlashUI();
    reinterpret_cast<Scaleform::GFx::ASMovieRootBase*>(self)->Scaleform::GFx::ASMovieRootBase::~ASMovieRootBase();
}

namespace Scaleform { namespace GFx { namespace AS3 { void Sfr31ShutdownRegistered(UPInt self); }}} // sfr_as3_19
extern "C" void FUN_1424dfbf0(void* self);
void FUN_1424dc8e0(void* self);
void FUN_1424de240(long long* state);
namespace Scaleform { namespace GFx { namespace AS3 {
void* DeleteAs3_1424e3890(void* self, unsigned flags);
}}}


// The stage display object: its members release in reverse order, then DisplayObjContainer's dtor.
// __forceinline so that the deleting dtor below inlines it, as the exe does; the out-of-line copy is still emitted.
// @0x1424defe0
__forceinline Scaleform::GFx::AS3::Stage::~Stage() {}

namespace Scaleform { namespace GFx { namespace AS3 {
// The deleting destructor (vftable slot 0); ~Stage is inlined into it.
// @0x1424e3950
void* DeleteAs3_1424e3950(void* p, unsigned flags)
{
    static_cast<Stage*>(p)->Stage::~Stage();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::pGlobalHeap->Free(p);
        else
            ::operator delete(p, 0x130);
    }
    return p;
}
}}} // namespace Scaleform::GFx::AS3

// The members release themselves, then XMLSupport's (inline) and GASRefCountBase's dtors. __forceinline so that the
// deleting dtor below inlines it, as the exe does; the out-of-line copy is still emitted.
// @0x1424e0290
__forceinline Scaleform::GFx::AS3::XMLSupportImpl::~XMLSupportImpl()
{
}

namespace Scaleform { namespace GFx { namespace AS3 {
// The deleting destructor (vftable slot 4); ~XMLSupportImpl is inlined into it.
// @0x1424e4190
void* DeleteAs3_1424e4190(void* p, unsigned flags)
{
    static_cast<XMLSupportImpl*>(p)->XMLSupportImpl::~XMLSupportImpl();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::pGlobalHeap->Free(p);
        else
            ::operator delete(p, 0x48);
    }
    return p;
}
}}} // namespace Scaleform::GFx::AS3
// MS2-PIN: ??_7FlashUI@AS3@GFx@Scaleform@@6B@ 0x14317b648
// MS2-PIN: ??_7XMLSupport@AS3@GFx@Scaleform@@6B@ 0x14317b7b8
// MS2-PIN: ??_7XMLSupportImpl@AS3@GFx@Scaleform@@6B@ 0x14317f9e0


// A copied frame gives back what its constructor reserved: the operand stack reservation (an emptied page with a
// predecessor goes back to the reserved list and the values still on it move down onto the predecessor), the
// registers of the method body, and the scope stack. The operand values stay on the stack for the caller.
// MS2-FUNCTIONAL 0x1424dde10: both ReleaseReserved inlined as in the exe; left: register naming (exe zero in r15)
// and the register loop (exe re-indexes pRF by the UInt16 i each pass, ours strength-reduces it).
// @0x1424dde10
Scaleform::GFx::AS3::CallFrame::~CallFrame()
{
    if (pRegisterFile && pScopeStack && ACopy)
    {
        using Scaleform::GFx::AS3::Value;
        using Scaleform::GFx::AS3::ValueStack;
        // ValueStack::ReleaseReserved, which has no out-of-line copy in the exe: the frame's reservation ends, and an
        // emptied page with a predecessor goes back to the reserved list, its values moved onto the predecessor.
        Value* const first = PrevFirstStackPos;
        const Scaleform::UInt16 prevReservedNum = PrevReservedNum;
        ValueStack& st = ValueStack::Of(pFile->GetVM());
        --st.pCurrentPage->ReservationNum;
        st.ReservedNum = prevReservedNum;
        if (st.pCurrentPage->ReservationNum == 0 && st.pCurrentPage->pPrev)
        {
            Value* const top = st.pCurrent;
            ValueStack::Page* const page = st.pCurrentPage;
            st.pCurrentPage = page->pPrev;
            st.pCurrentPage->pNext = NULL;
            st.pCurrent = st.pCurrentPage->pCurrent;
            st.pStack = st.pCurrentPage->pFirst;
            page->pNext = st.pReserved;
            page->pFirst = NULL;
            st.pReserved = page;
            for (Value* v = page->Values; v <= top; ++v)
                new (++st.pCurrent) Value(*v, PickValue);
        }
        else
            st.pStack = first;
        const Scaleform::GFx::AS3::Abc::MethodBodyInfo& body =
            *pFile->GetAbcFile().MethodBodies.Info[static_cast<Scaleform::UPInt>(MBIIndex)];
        // ValueRegisterFile::ReleaseReserved (0x142521fb0), inlined
        ValueRegisterFile& rf = *static_cast<ValueRegisterFile*>(pRegisterFile);
        const Scaleform::UInt16 num = static_cast<Scaleform::UInt16>(body.local_reg_count);
        for (Scaleform::UInt16 i = 0; i < num; ++i)
            rf.pRF[i].Release();
        rf.Unk00 -= num;
        ValueRegisterFile::Page* cur = rf.pCurrentPage;
        --cur->CurrPos;
        rf.pRF -= ValueRegisterFile::GetReservations(cur)[cur->CurrPos];
        if (rf.Unk00 == 0 && rf.pCurrentPage->pPrev)
        {
            rf.Unk02 = Scaleform::Alg::Max(rf.pCurrentPage->PageSize, rf.Unk02);
            ValueRegisterFile::Page* prev = rf.pCurrentPage->pPrev;
            rf.pCurrentPage->pPrev = NULL;
            rf.pCurrentPage->pNext = rf.pReservedPage;
            rf.pReservedPage = rf.pCurrentPage;
            rf.pCurrentPage = prev;
            prev->pNext = NULL;
            rf.Unk00 = rf.pCurrentPage->ReservedNum;
            rf.pRF = rf.pCurrentPage->pCurrent;
        }
        ClearScopeStack();
    }
}

// The tracer frees its temporary states, their three Value arrays, the block list, and its scratch arrays.
// MS2-FUNCTIONAL 0x1424df070: follows the exe's state/list ownership; template-array teardown is expressed via headers.
// @0x1424df070
extern "C" void FUN_1424df070(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    auto* heap = Scaleform::Memory::pGlobalHeap;   // the exe frees through Memory::pGlobalHeap
    *reinterpret_cast<const void***>(bytes) = Scaleform::GFx::AS3::DAT_14317b938;
    auto* sentinel = reinterpret_cast<unsigned char*>(bytes + 0x110);
    auto* node = *reinterpret_cast<unsigned char**>(bytes + 0x118);
    while (node && node != sentinel)
    {
        auto* next = *reinterpret_cast<unsigned char**>(node + 8);
        heap->Free(node);
        node = next;
    }
    *reinterpret_cast<unsigned char**>(bytes + 0x110) = sentinel;
    *reinterpret_cast<unsigned char**>(bytes + 0x118) = sentinel;

    auto* states = *reinterpret_cast<Scaleform::GFx::AS3::TR::State***>(bytes + 0xf0);
    const auto stateCount = *reinterpret_cast<Scaleform::UPInt*>(bytes + 0xf8);
    for (Scaleform::UPInt i = 0; i < stateCount; ++i)
    {
        auto* state = reinterpret_cast<unsigned char*>(states[i]);
        if (!state)
            continue;
        for (Scaleform::UPInt off : {Scaleform::UPInt(0x18), Scaleform::UPInt(0x38), Scaleform::UPInt(0x58)})
        {
            auto* values = *reinterpret_cast<Scaleform::GFx::AS3::Value**>(state + off);
            const auto count = *reinterpret_cast<Scaleform::UPInt*>(state + off + 8);
            for (Scaleform::UPInt j = 0; values && j < count; ++j)
                values[j].~Value();
            if (values)
                heap->Free(values);
        }
        void* changed = *reinterpret_cast<void**>(state + 0x78);
        if (changed)
            heap->Free(changed);
        heap->Free(state);
    }

    using PosArray = Scaleform::ArrayDH_POD<Scaleform::UPInt, Scaleform::GFx::AS3::StatMV_VM>;
    using RecalcArray = Scaleform::ArrayDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate, Scaleform::GFx::AS3::StatMV_VM>;
    using StateArray = Scaleform::ArrayDH<Scaleform::GFx::AS3::TR::State*, Scaleform::GFx::AS3::StatMV_VM>;
    using CatchArray = Scaleform::ArrayDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>, Scaleform::GFx::AS3::StatMV_VM>;
    reinterpret_cast<CatchArray*>(bytes + 0x120)->~CatchArray();
    reinterpret_cast<StateArray*>(bytes + 0xf0)->~StateArray();
    reinterpret_cast<PosArray*>(bytes + 0xd0)->~PosArray();
    reinterpret_cast<RecalcArray*>(bytes + 0xb0)->~RecalcArray();
    reinterpret_cast<PosArray*>(bytes + 0x90)->~PosArray();
    reinterpret_cast<PosArray*>(bytes + 0x70)->~PosArray();
    reinterpret_cast<Scaleform::GFx::AS3::FlashUI*>(bytes)->Scaleform::GFx::AS3::FlashUI::~FlashUI();
}

namespace {
// SDK Value::HashFunctor::SDBM_Hash body; the exe unrolls it for each constant size.
SF_FORCEINLINE Scaleform::UPInt Sfr16SdbmHash(const void* data_in, Scaleform::UPInt size, Scaleform::UPInt seed = 5381)
{
    const Scaleform::UByte* data = (const Scaleform::UByte*)data_in;
    Scaleform::UPInt h = seed;
    while (size > 0)
    {
        size--;
        h = (h << 16) + (h << 6) - h + (Scaleform::UPInt)data[size];
    }
    return h;
}
} // namespace

// Value hash used by the AS3 hash-set adapters (SDK body).
// @0x1424e1040
Scaleform::UPInt Scaleform::GFx::AS3::Value::HashFunctor::operator()(const Scaleform::GFx::AS3::Value& v) const
{
    const Value::KindType kind = v.GetKind();
    UPInt result = 0;

    switch (kind)
    {
    case Value::kUndefined:
        break;
    case Value::kBoolean:
        result = v.AsBool() ? 1 : 0;
        break;
    case Value::kInt:
    case Value::kUInt:
        {
            SInt32 lv = v.AsInt();
            result = Sfr16SdbmHash(&lv, sizeof(lv));
        }
        break;
    case Value::kNumber:
        {
            Value::Number lv = v.AsNumber();
            result = Sfr16SdbmHash(&lv, sizeof(lv));
        }
        break;
    case Value::kString:
        if (v.GetStringNode())
            result = v.GetStringNode()->HashFlags & ASConstString::Flag_HashMask;
        else
            result = 0;
        break;
    case Value::kVTableInd:
        {
            SInt32 lv = v.GetVTableInd();
            const Traits* tr = &v.GetTraits();
            result = Sfr16SdbmHash(&lv, sizeof(lv)) ^ Sfr16SdbmHash(&tr, sizeof(tr));
        }
        break;
    case Value::kVTableIndClosure:
        {
            SInt32 lv = v.GetVTableInd();
            const Object* cv = v.GetClosure();
            result = Sfr16SdbmHash(&lv, sizeof(lv)) ^ Sfr16SdbmHash(&cv, sizeof(cv));
        }
        break;
    case Value::kThunk:
        result = Sfr16SdbmHash(&v.AsThunk(), sizeof(ThunkInfo));
        break;
    case Value::kFunction:
    case Value::kObject:
    case Value::kClass:
    case Value::kNamespace:
    case Value::kThunkFunction:
        if (v.GetObject())
        {
            const Object* lv = v.GetObject();
            result = Sfr16SdbmHash(&lv, sizeof(lv));
        }
        else
            result = 0;
        break;
    case Value::kThunkClosure:
        {
            const Object* cv = v.GetClosure();
            result = Sfr16SdbmHash(&v.AsThunk(), sizeof(ThunkInfo)) ^ Sfr16SdbmHash(&cv, sizeof(cv));
        }
        break;
    default:
        break;
    }

    result += kind;
    return result;
}

// ValueRegisterFile teardown: free the reserved pages, release the register values, then free the current page.
// The UInt16 index counts down (--i wraps to 0xffff), so the loop ends after register 0: only that one is released.
// @0x1424dfaf0
extern "C" void FUN_1424dfaf0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    while (*reinterpret_cast<void**>(bytes + 0x18))
    {
        void* page = *reinterpret_cast<void**>(bytes + 0x18);
        *reinterpret_cast<void**>(bytes + 0x18) = *reinterpret_cast<void**>(static_cast<unsigned char*>(page) + 0x10);
        reinterpret_cast<void (*)(void*, void*)>((*reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap))[12])(
            Scaleform::Memory::pGlobalHeap, page);
    }

    for (Scaleform::UInt16 i = 0; i < *reinterpret_cast<const Scaleform::UInt16*>(bytes); --i)
        (*reinterpret_cast<Scaleform::GFx::AS3::Value**>(bytes + 8))[i].~Value();

    if (void* page = *reinterpret_cast<void**>(bytes + 0x10))
        reinterpret_cast<void (*)(void*, void*)>((*reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap))[12])(
            Scaleform::Memory::pGlobalHeap, page);
}

// ValueStack teardown: release live values and free each distinct current or reserved page once.
// MS2-FUNCTIONAL 0x1424dfbf0: pointer bookkeeping uses a temporary vector instead of the exe's local hash table.
// @0x1424dfbf0
extern "C" void FUN_1424dfbf0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    using Page = Scaleform::GFx::AS3::ValueStack::Page;
    std::vector<Page*> pages;

    Page* page = *reinterpret_cast<Page**>(bytes + 0x20);
    while (page)
    {
        Page* next = page->pNext;
        if (std::find(pages.begin(), pages.end(), page) == pages.end())
            pages.push_back(page);
        page = next;
    }

    page = *reinterpret_cast<Page**>(bytes + 0x18);
    auto* top = *reinterpret_cast<Scaleform::GFx::AS3::Value**>(bytes + 8);
    while (page)
    {
        auto* first = page->Values;
        while (reinterpret_cast<Scaleform::UPInt>(top) >= reinterpret_cast<Scaleform::UPInt>(first))
        {
            top->~Value();
            --top;
        }
        // a page already on the reserved list ends the walk
        if (std::find(pages.begin(), pages.end(), page) != pages.end())
            break;
        pages.push_back(page);
        page = page->pPrev;
        if (page)
            top = page->pCurrent;
    }

    auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
    for (Page* owned : pages)
        reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(Scaleform::Memory::pGlobalHeap, owned);
}

namespace Scaleform { namespace GFx { namespace AS3 {
// The execution stacks and the GC guard are destroyed after the other members, in reverse declaration order.
VMOpStackWords::~VMOpStackWords() { FUN_1424dfbf0(W); }
VMCallStackWords::~VMCallStackWords() { FUN_1424dc8e0(W); }
VMDefaultFrameWords::~VMDefaultFrameWords() { reinterpret_cast<CallFrame*>(W)->~CallFrame(); }
VMRegisterFileWords::~VMRegisterFileWords() { FUN_1424dfaf0(W); }
VMGCGuard::~VMGCGuard() { FUN_1424de240(reinterpret_cast<long long*>(&pGC)); }

// MS2-FUNCTIONAL 0x1424df380: marks the VM as destroying and shuts down registered ABCs before member teardown.
// @0x1424df380
VM::~VM()
{
    InDestructor = true;
    Scaleform::GFx::AS3::Sfr31ShutdownRegistered(reinterpret_cast<Scaleform::UPInt>(this));
    // The exe's GlobalObjects is ArrayLH<GlobalObject*>: its data is freed without releasing the (unowned) elements.
    // as3_vm.h still declares SPtr elements (shared with the as3_17/18 lanes), so empty it here; the member dtor then only frees Data.
    reinterpret_cast<Scaleform::UPInt*>(&GlobalObjects)[1] = 0; // Size (+0x1b0)
}
}}} // namespace Scaleform::GFx::AS3

// ASRefCountCollector::ForceCollect (no stats observer, no flags), inlined into both callers below.
static __forceinline void Sfr16ForceCollect(Scaleform::GFx::AS3::ASRefCountCollector* gc)
{
    using namespace Scaleform::GFx::AS3;
    if (gc->SuspendCnt > 0)
        return;

    const unsigned roots = static_cast<unsigned>(gc->GetRootsCount());
    ASRefCountCollector::Stats stats;
    stats.RootsNumber = stats.RootsFreedTotal = 0;
    gc->Collect(&stats);
    gc->FrameCnt = 0;
    gc->PeakRootCount = Scaleform::Alg::Max(gc->PeakRootCount, roots);
    gc->LastRootCount = roots;
    if (gc->Flags & ASRefCountCollector::Flags_RequireMoreCollect)
        gc->CollectionScheduledFlags = 1;
}

// ForceCollect through the movie root's collector pointer.
// MS2-FUNCTIONAL 0x1424de240: same code, but the exe tail-calls the Stats observer release.
// @0x1424de240
void FUN_1424de240(long long* state)
{
    Sfr16ForceCollect(reinterpret_cast<Scaleform::GFx::AS3::ASRefCountCollector*>(*state));
}

// ForceCollect on the nested MovieRoot's collector, then the owning reference is released.
// @0x1424de460
void FUN_1424de460(long long* owner)
{
    Sfr16ForceCollect(*reinterpret_cast<Scaleform::GFx::AS3::ASRefCountCollector**>(*owner + 0x20));
    if (*owner != 0)
        reinterpret_cast<Scaleform::RefCountImpl*>(*owner)->Release();
}

// The exe keeps this SPtr assignment out of line; FUN_1424e0940 calls it.
template<> SF_NOINLINE inline Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>&
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>::operator=(
    const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>& other)
{
    return Set(other);
}

// Tagged ASStringNode pointer assignment (odd = unowned) inlined into FUN_1424e0940.
static inline void Sfr16AssignName(Scaleform::GFx::ASStringNode** dstName, Scaleform::GFx::ASStringNode* const* srcName)
{
    if (srcName != dstName)
    {
        if (Scaleform::GFx::ASStringNode* oldName = *dstName)
        {
            const auto raw = reinterpret_cast<Scaleform::UPInt>(oldName);
            if (raw & 1)
                *reinterpret_cast<Scaleform::UPInt*>(dstName) = raw - 1;
            else
                oldName->Release();
        }
        Scaleform::GFx::ASStringNode* newName = *srcName;
        if (newName)
        {
            newName->AddRef();
            newName = *srcName;
        }
        *dstName = newName;
    }
}

// Copies scalar state, retains the interned name and namespace, and assigns the embedded AS3 Value.
// @0x1424e0940
unsigned char* FUN_1424e0940(unsigned char* dst, const unsigned char* src)
{
    if (dst == src)
        return dst;

    dst[0] = src[0];
    dst[1] = 1;
    dst[2] = src[2];
    *reinterpret_cast<unsigned long long*>(dst + 8) = *reinterpret_cast<const unsigned long long*>(src + 8);
    *reinterpret_cast<unsigned long long*>(dst + 0x10) = *reinterpret_cast<const unsigned long long*>(src + 0x10);
    *reinterpret_cast<unsigned long long*>(dst + 0x18) = *reinterpret_cast<const unsigned long long*>(src + 0x18);
    *reinterpret_cast<unsigned long long*>(dst + 0x20) = *reinterpret_cast<const unsigned long long*>(src + 0x20);
    *reinterpret_cast<unsigned long long*>(dst + 0x28) = *reinterpret_cast<const unsigned long long*>(src + 0x28);
    *reinterpret_cast<unsigned*>(dst + 0x30) = *reinterpret_cast<const unsigned*>(src + 0x30);
    *reinterpret_cast<unsigned long long*>(dst + 0x38) = *reinterpret_cast<const unsigned long long*>(src + 0x38);
    *reinterpret_cast<unsigned long long*>(dst + 0x40) = *reinterpret_cast<const unsigned long long*>(src + 0x40);
    *reinterpret_cast<unsigned long long*>(dst + 0x48) = *reinterpret_cast<const unsigned long long*>(src + 0x48);
    *reinterpret_cast<unsigned long long*>(dst + 0x50) = *reinterpret_cast<const unsigned long long*>(src + 0x50);
    using NamespacePtr = Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>;
    *reinterpret_cast<NamespacePtr*>(dst + 0x58) = *reinterpret_cast<const NamespacePtr*>(src + 0x58);
    *reinterpret_cast<unsigned long long*>(dst + 0x60) = *reinterpret_cast<const unsigned long long*>(src + 0x60);
    *reinterpret_cast<unsigned short*>(dst + 0x68) = *reinterpret_cast<const unsigned short*>(src + 0x68);

    Sfr16AssignName(reinterpret_cast<Scaleform::GFx::ASStringNode**>(dst + 0x70),
        reinterpret_cast<Scaleform::GFx::ASStringNode* const*>(src + 0x70));
    *reinterpret_cast<unsigned*>(dst + 0x78) = *reinterpret_cast<const unsigned*>(src + 0x78);
    *reinterpret_cast<unsigned*>(dst + 0x7c) = *reinterpret_cast<const unsigned*>(src + 0x7c);
    *reinterpret_cast<unsigned long long*>(dst + 0x80) = *reinterpret_cast<const unsigned long long*>(src + 0x80);
    reinterpret_cast<Scaleform::GFx::AS3::Value*>(dst + 0x88)->Assign(
        *reinterpret_cast<const Scaleform::GFx::AS3::Value*>(src + 0x88));
    return dst;
}

extern "C" void FUN_14015b310(void*, Scaleform::UPInt);

namespace {
void* Sfr16ScalarDeletingDtor(void* self, unsigned int flags)
{
    static_cast<Scaleform::RefCountImplCore*>(self)->Scaleform::RefCountImplCore::~RefCountImplCore();
    if (flags & 1)
    {
        if ((flags & 4) == 0)
        {
            auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
            reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(Scaleform::Memory::pGlobalHeap, self);
        }
        else
        {
            FUN_14015b310(self, 0x10);
        }
    }
    return self;
}


// Same as Sfr16ScalarDeletingDtor for the classes whose base is RefCountNTSImplCore.
void* Sfr16ScalarDeletingDtorNts(void* self, unsigned int flags)
{
    static_cast<Scaleform::RefCountNTSImplCore*>(self)->Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1)
    {
        if ((flags & 4) == 0)
        {
            auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
            reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(Scaleform::Memory::pGlobalHeap, self);
        }
        else
        {
            FUN_14015b310(self, 0x10);
        }
    }
    return self;
}
}

// The exe contains byte-identical generic scalar-deleting destructor copies with ambiguous owners.
// @0x1424e1c20
extern "C" void* Sfr16ScalarDeletingDtor_1424e1c20(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtor(self, flags); }
// @0x1424e1c80
extern "C" void* Sfr16ScalarDeletingDtor_1424e1c80(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtor(self, flags); }
// @0x1424e1ce0
extern "C" void* Sfr16ScalarDeletingDtor_1424e1ce0(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtor(self, flags); }
// @0x1424e1d40
extern "C" void* Sfr16ScalarDeletingDtor_1424e1d40(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtor(self, flags); }
// @0x1424e1da0
extern "C" void* Sfr16ScalarDeletingDtor_1424e1da0(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtor(self, flags); }
// @0x1424e1e00
extern "C" void* Sfr16ScalarDeletingDtor_1424e1e00(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtor(self, flags); }
// @0x1424e1e60
extern "C" void* Sfr16ScalarDeletingDtor_1424e1e60(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtorNts(self, flags); }
// @0x1424e1ec0
extern "C" void* Sfr16ScalarDeletingDtor_1424e1ec0(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtorNts(self, flags); }
// @0x1424e1f20
extern "C" void* Sfr16ScalarDeletingDtor_1424e1f20(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtor(self, flags); }
// @0x1424e1f80
extern "C" void* Sfr16ScalarDeletingDtor_1424e1f80(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtor(self, flags); }
// @0x1424e1fe0
extern "C" void* Sfr16ScalarDeletingDtor_1424e1fe0(void* self, unsigned int flags) { return Sfr16ScalarDeletingDtorNts(self, flags); }

extern void FUN_14257eb30(void*);
struct Sfr36StateAccess : Scaleform::Render::StateData
{
    using StateData::destroyBag_NotEmpty;
};
namespace Scaleform {
// out of line in the exe (0x14241e430, sfr_as3_04)
typedef ArrayDataDH<GFx::AS3::Value, AllocatorDH<GFx::AS3::Value, 2>, ArrayDefaultPolicy> Sfr16ValueDataDH;
template<> SF_NOINLINE void ArrayBase<Sfr16ValueDataDH>::PushBack(const GFx::AS3::Value& val);
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {
    // The executable keeps ModifyOptimizedPlayList out of line at 0x142517e70; its body is recovered in sfr_as3_18.
    void Sfr34_ModifyOptimizedPlayList(InteractiveObject* p);

// ==== slots ==========================================================================================================

// The exe keeps these two SPtr assignments out of line; SlotInfo::operator= calls them.
template<> SF_NOINLINE inline SPtr<const Instances::Namespace>& SPtr<const Instances::Namespace>::operator=(
    const SPtr<const Instances::Namespace>& other)
{
    return Set(other);
}
template<> SF_NOINLINE inline SPtr<VMAbcFile>& SPtr<VMAbcFile>::operator=(const SPtr<VMAbcFile>& other)
{
    return Set(other);
}

// @0x1424def30
SlotInfo::~SlotInfo()
{
}

// The exe releases the embedded context bag before the entry-data members, then conditionally frees the node.
// The generic deleting dtor has no recovered concrete owner type in our headers; the node is 0x90 bytes.
// @0x1424e1bd0
void* FUN_1424e1bd0(void* node, unsigned int flags)
{
    if (*reinterpret_cast<void**>(static_cast<char*>(node) + 0x40))
        reinterpret_cast<Sfr36StateAccess*>(static_cast<char*>(node) + 0x40)->destroyBag_NotEmpty();
    FUN_14257eb30(node);
    if (flags & 1)
        ::operator delete(node, 0x90);
    return node;
}

// The SPtr<Namespace>/SPtr<VMAbcFile> assignments are the out-of-line specializations above; SPtr<Traits> inlines.
// @0x1424e0b80
SlotInfo& SlotInfo::operator=(const SlotInfo& other)
{
    if (this != &other)
    {
        ReadOnly   = other.ReadOnly;
        DontEnum   = other.DontEnum;
        DontDelete = other.DontDelete;
        Internal   = other.Internal;
        CppBinding = other.CppBinding;
        BindType   = other.BindType;
        pNs        = other.pNs;
        CTraits    = other.CTraits;
        File       = other.File;
        TI         = other.TI;
        ValueInd   = other.ValueInd;
        Name       = other.Name;
    }

    return *this;
}

// @0x1424e63b0
AbsoluteIndex SlotContainerType::Add(const ASString& k, const SlotInfo& v)
{
    UPInt result;

    {
        result = VArray.GetSize();
        VArray.PushBack(Pair(v, Ptr<ASStringNode>(k.GetNode())));
        ++Size;
    }

    ASStringNode* node = k.GetNode();

    const SPInt index = static_cast<SPInt>(result);
    SetType::Iterator it = KVHashSet.Find(node);
    if (it.IsEnd())
    {
        KVHashSet.Add(node, index);
        VArray[index].Prev = -1;
    }
    else
    {
        const SPInt cur_ind = it->Second;
        VArray[index].Prev = cur_ind;
        it->Second = index;
    }

    return AbsoluteIndex(result);
}

// @0x1424e6670
AbsoluteIndex Slots::Add(const ASString& k, const SlotInfo& v)
{
    UPInt result;

    result = VArray.GetSize();
    VArray.PushBack(Pair(v, Ptr<ASStringNode>(k.GetNode())));

    ASStringNode* node = k.GetNode();

    const SPInt index = static_cast<SPInt>(result);
    SetType::Iterator it = Set.Find(node);
    if (it.IsEnd())
    {
        Set.Add(node, static_cast<UInt32>(index + FirstOwnSlotNum));
        VArray[index].Prev = -1;
    }
    else
    {
        const SPInt cur_ind = it->Second;
        VArray[index].Prev = cur_ind;
        it->Second = static_cast<UInt32>(index + FirstOwnSlotNum);
    }

    return AbsoluteIndex(result + FirstOwnSlotNum);
}

// ==== objects ========================================================================================================

// MS2-FUNCTIONAL: the exe inlines Value(Class*) and the string overload of AddDynamicSlotValuePair (one unity TU);
// here Value(Class*) lives in sfr_as3_15.
// @0x1424e6f90
void Class::AddConstructor(Object& obj) const
{
    obj.AddDynamicSlotValuePair(GetVM().GetStringManager().CreateConstString("constructor"),
                                Value(const_cast<Class*>(this)), SlotInfo::aDontEnum);
}

// @0x1424e7f40
void Object::AddDynamicSlotValuePair(const ASString& prop_name, const Value& v, SlotInfo::Attribute a)
{
    DynAttrs.Set(DynAttrsKey(prop_name, a == SlotInfo::aDontEnum), v);
}

// @0x1424e8060
void Object::AddDynamicSlotValuePair(const Value& prop_name, const Value& v, SlotInfo::Attribute a)
{
    ASString name = GetVM().GetStringManager().CreateEmptyString();
    if (prop_name.Convert2String(name))
        AddDynamicSlotValuePair(name, v, a);
}

// ==== destructors ===================================================================================================

namespace Classes {
    // __forceinline so that the deleting dtor below inlines it, as the exe does; the out-of-line copy is still emitted.
    // @0x1424df350
    __forceinline UDBase::~UDBase()
    {
        // The traits pointer carries a tag in bit 0; the Class base is destroyed implicitly after this body.
        reinterpret_cast<const Traits*>(reinterpret_cast<UPInt>(pTraits.GetPtr()) & ~UPInt(1))->DestructTail(*this);
    }
}

// The UDBase deleting destructor (vftable slot 0); ~UDBase is inlined into it.
// @0x1424e3d60
void* DeleteAs3_1424e3d60(void* p, unsigned flags)
{
    static_cast<Classes::UDBase*>(p)->Classes::UDBase::~UDBase();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::pGlobalHeap->Free(p);
        else
            ::operator delete(p, 0x50);
    }
    return p;
}

// The user data an application attached to an object (GFx::Value::SetUserData) and the movie it was set from.
// 0x10 bytes.
class Object::UserDataHolder : public NewOverrideBase<StatMV_ActionScript_Mem>
{
public:
    Movie*      pMovieView; // +0x00
    ASUserData* pUserData;  // +0x08

    // Drops the weak reference of the user data and tells it that the object is gone.
    void NotifyDestroy(Object* pthis) const
    {
        if (pUserData)
        {
            ASUserData_SetLastObjectValue(pUserData, 0, 0, false);
            pUserData->OnDestroy(pMovieView, pthis);
        }
    }
};

// WProxyHash.Get is the out-of-line word-keyed Hash::Get instance (0x1425058c0, defined in sfr_as3_17);
// its Remove is the GASRefCountBase*-keyed instance (0x1425221d0, sfr_as3_18).
bool Sfr33WordHashGet(const HashLH<UPInt, UPInt>& h, const UPInt& key, UPInt* pvalue);
}}} // namespace Scaleform::GFx::AS3
namespace Scaleform {
typedef Hash<GFx::AS3::GASRefCountBase*, GFx::AS3::WeakProxy*, FixedSizeHash<GFx::AS3::GASRefCountBase*>,
             AllocatorGH<GFx::AS3::GASRefCountBase*, Stat_Default_Mem> > Sfr16WProxyHash;
template<> SF_NOINLINE void Sfr16WProxyHash::Remove(GFx::AS3::GASRefCountBase* const& key);
} // namespace Scaleform
namespace Scaleform { namespace GFx { namespace AS3 {
static inline bool Sfr16WProxyGet(const Sfr16WProxyHash& h, GASRefCountBase* const& key, WeakProxy** pvalue)
{
    return Sfr33WordHashGet(reinterpret_cast<const HashLH<UPInt, UPInt>&>(h), reinterpret_cast<const UPInt&>(key),
                            reinterpret_cast<UPInt*>(pvalue));
}

// The barrier keeps the pObject store ahead of the RefCount decrement, as the exe has it (no code emitted).
// @0x1424de190
GASRefCountBase::~GASRefCountBase()
{
    if (HasWeakRef())
    {
        Collector* rcc = GetCollector();
        WeakProxy* p = NULL;
        {
            WeakProxy* wp = NULL;
            if (Sfr16WProxyGet(reinterpret_cast<Sfr16WProxyHash&>(rcc->WProxyHash), this, &wp))
                p = wp;
        }
        if (p)
        {
            p->NotifyObjectDied();
            _ReadWriteBarrier();
            p->Release();
            reinterpret_cast<Sfr16WProxyHash&>(rcc->WProxyHash).Remove(this);
        }
    }
}

// @0x1424de820
Object::~Object()
{
    if (pUserDataHolder)
    {
        pUserDataHolder->NotifyDestroy(this);
        delete pUserDataHolder;
    }
}

// @0x1424de2e0
Instance::~Instance()
{
    reinterpret_cast<const Traits*>(reinterpret_cast<UPInt>(pTraits.GetPtr()) & ~UPInt(1))->DestructTail(*this);
}

// @0x1424de0e0
Class::~Class()
{
}

// pVTable's release is the out-of-line AutoPtr<VTable>::Reset (0x142524290, declared above).
// @0x1424df220
Traits::~Traits()
{
}

namespace InstanceTraits
{
    // @0x1424df2f0
    Traits::~Traits()
    {
    }

    // @0x1424ddd90
    CTraits::~CTraits()
    {
    }

    // @0x1424de960
    RTraits::~RTraits()
    {
    }
}

// ==== virtual table ==================================================================================================

// @0x1424e8ed0
SF_NOINLINE AbsoluteIndex VTable::AddMethod(const Value& m, SlotInfo::BindingType dt, const ASString& name)
{
    UPInt ind;

    switch (dt)
    {
    case SlotInfo::BT_Code:
        ind = VTMethods.GetSize();
        VTMethods.PushDefault();
        break;
    case SlotInfo::BT_Get:
        ind = VTMethods.GetSize();
        VTMethods.PushDefault();
        // the setter's place
        VTMethods.PushDefault();
        break;
    case SlotInfo::BT_Set:
        // the getter's place
        VTMethods.PushDefault();
        ind = VTMethods.GetSize();
        VTMethods.PushDefault();
        break;
    default:
        ind = 0;
        break;
    }

    SetMethodName(AbsoluteIndex(ind), dt, name);

    if (m.GetKind() == Value::kInt)
        VTMethods[ind] = Value(m.AsInt(), GetTraits(), Value::kMethodInd);
    else
        VTMethods[ind] = m;

    return AbsoluteIndex(VTMethods.GetSize() - (dt == SlotInfo::BT_Code ? 1 : 2));
}

// ==== values =========================================================================================================

// @0x1424e9330
void Value::AddRefInternal() const
{
    switch (GetKind())
    {
    case kString:
        AddRefString();
        break;
    case kNamespace:
    case kObject:
    case kClass:
    case kFunction:
    case kThunkFunction:
        if (value.VS._1.VObj)
            value.VS._1.VObj->AddRef();
        break;
    case kThunkClosure:
    case kVTableIndClosure:
        if (value.VS._2.VObj)
            value.VS._2.VObj->AddRef();
        break;
    default:
        break;
    }
}

// @0x1424e9370
void Value::AddRefWeakRef() const
{
    Bonus.pWeakProxy->AddRef();
}

// The E4X operands of AbstractEqual: XMLList on either side, XML against anything, XML/QName pairs.
static inline const XMLSupport& GetXMLSupportOf(const Value& v)
{
    return v.GetObject()->GetVM().GetXMLSupport();
}

// The exe's SCU inlined the sfr_as3_18 checks IsXMLListObject (0x1425157c0), IsXMLObject (0x1425157f0) and
// IsQNameObject (0x142514bf0) into the operand tests below; this is their body for an object value.
static SF_INLINE bool Sfr16IsTraitsObject(const Value& v, BuiltinTraitsType tt)
{
    bool result = false;
    if (v.IsObject() && v.GetObject())
    {
        const Traits& tr = v.GetObject()->GetTraits();
        if (tr.GetTraitsType() == tt && tr.IsInstanceTraits())
            result = true;
    }
    return result;
}

// The method and closure kinds, as a switch: the exe tests each side with cl's case-range tree (< kThunk, <= kMethodInd,
// kThunkClosure..kVTableIndClosure).
static SF_INLINE bool Sfr16IsMethodKind(Value::KindType k)
{
    switch (k)
    {
    case Value::kThunk:
    case Value::kMethodInd:
    case Value::kThunkClosure:
    case Value::kVTableIndClosure:
        return true;
    default:
        return false;
    }
}

// MS2-FUNCTIONAL: closer (2076 bytes, exe 2120). The exe keeps l in rsi and r in rdi (ours swaps them), writes the
// CheckResult byte at each return where ours shares one tail, and lays out the Boolean case and the Number/String
// conversion arms in another order.
// @0x1424e46f0
CheckResult AbstractEqual(bool& result, const Value& l, const Value& r)
{
    const Value::KindType lk = l.GetKind();

    if (Sfr16IsTraitsObject(l, Traits_XMLList))
        return GetXMLSupportOf(l).EqualsXMLList(result, *reinterpret_cast<Instances::fl::XMLList*>(l.GetObject()), r);

    const Value::KindType rk = r.GetKind();

    if (Sfr16IsTraitsObject(r, Traits_XMLList))
        return GetXMLSupportOf(r).EqualsXMLList(result, *reinterpret_cast<Instances::fl::XMLList*>(r.GetObject()), l);

    if (lk == rk)
    {
        switch (lk)
        {
        case Value::kUndefined:
            result = true;
            return true;
        case Value::kNumber:
            if (l.IsNaN() || r.IsNaN())
                result = false;
            else
                result = l.AsNumber() == r.AsNumber();
            return true;
        case Value::kThunk:
        case Value::kString:
            result = l.GetStringNode() == r.GetStringNode();
            return true;
        case Value::kNamespace:
        {
            const Instances::Namespace* lns = l.GetNamespace();
            const Instances::Namespace* rns = r.GetNamespace();
            result = lns && rns && *lns == *rns;
            return true;
        }
        case Value::kBoolean:
            result = (l.AsBool() && r.AsBool()) || (!l.AsBool() && !r.AsBool());
            return true;
        case Value::kInt:
        case Value::kUInt:
            result = l.AsInt() == r.AsInt();
            return true;
        case Value::kVTableInd:
            result = l.GetVTableInd() == r.GetVTableInd() && &l.GetTraits() == &r.GetTraits();
            return true;
        case Value::kThunkClosure:
            result = l.GetClosure() == r.GetClosure() && &l.AsThunk() == &r.AsThunk();
            return true;
        case Value::kVTableIndClosure:
            result = l.GetClosure() == r.GetClosure() && l.GetVTableInd() == r.GetVTableInd();
            return true;
        default:
            result = l.GetObject() == r.GetObject();
            if (!result)
            {
                if (Sfr16IsTraitsObject(l, Traits_XML) && Sfr16IsTraitsObject(r, Traits_XML))
                    return GetXMLSupportOf(l).EqualsXML(result, *reinterpret_cast<Instances::fl::XML*>(l.GetObject()),
                                                        *reinterpret_cast<Instances::fl::XML*>(r.GetObject()));
                if (Sfr16IsTraitsObject(l, Traits_QName) && Sfr16IsTraitsObject(r, Traits_QName))
                    return GetXMLSupportOf(l).EqualsQName(result, *reinterpret_cast<Instances::fl::QName*>(l.GetObject()),
                                                          *reinterpret_cast<Instances::fl::QName*>(r.GetObject()));
            }
            return true;
        }
    }

    // null == undefined
    if ((lk == Value::kUndefined && r.IsNull()) || (rk == Value::kUndefined && l.IsNull()))
    {
        result = true;
        return true;
    }

    // Number == String
    if (lk == Value::kNumber && rk == Value::kString)
    {
        Value::Number n;
        if (!r.Convert2NumberInline(n))
            return false;
        result = l.AsNumber() == n;
        return true;
    }
    if (lk == Value::kString && rk == Value::kNumber)
    {
        Value::Number n;
        if (!l.Convert2NumberInline(n))
            return false;
        result = n == r.AsNumber();
        return true;
    }

    // XML == anything
    if (IsXMLObject(l))
    {
        bool stop = true;
        if (!GetXMLSupportOf(l).EqualsXML(stop, result, *reinterpret_cast<Instances::fl::XML*>(l.GetObject()), r))
            return false;
        if (stop)
            return true;
    }
    else if (IsXMLObject(r))
    {
        bool stop = true;
        if (!GetXMLSupportOf(r).EqualsXML(stop, result, *reinterpret_cast<Instances::fl::XML*>(r.GetObject()), l))
            return false;
        if (stop)
            return true;
    }

    // undefined == object
    if (lk == Value::kUndefined && Value::IsObject(rk))
    {
        result = r.IsNull();
        return true;
    }
    if (Value::IsObject(lk) && rk == Value::kUndefined)
    {
        result = l.IsNull();
        return true;
    }

    // Number/String == Object: the object's primitive value
    if ((lk == Value::kString || lk == Value::kNumber) && Value::IsObject(rk))
    {
        if (r.IsNull())
        {
            result = false;
            return true;
        }
        Value prim;
        if (!r.Convert2PrimitiveValueUnsafe(prim))
            return false;
        return AbstractEqual(result, l, prim);
    }
    if (Value::IsObject(lk) && (rk == Value::kString || rk == Value::kNumber))
    {
        if (l.IsNull())
        {
            result = false;
            return true;
        }
        Value prim;
        if (!l.Convert2PrimitiveValueUnsafe(prim))
            return false;
        return AbstractEqual(result, prim, r);
    }

    // methods and closures equal nothing of another kind
    if (Sfr16IsMethodKind(lk) || Sfr16IsMethodKind(rk))
    {
        result = false;
        return true;
    }

    // Boolean/int/uint == anything: compare as Number
    if (lk != Value::kNumber)
    {
        Value::Number n;
        if (!l.Convert2NumberInline(n))
            return false;
        Value num(n);
        return AbstractEqual(result, num, r);
    }
    if (rk != Value::kNumber)
    {
        Value::Number n;
        if (!r.Convert2NumberInline(n))
            return false;
        Value num(n);
        return AbstractEqual(result, l, num);
    }
    return true;
}

// ECMA-262 11.8.5: undefined3 when either side is NaN.
// MS2-FUNCTIONAL: exe shares one release tail for both temporaries; our inlined conversions are longer
// @0x1424e4f40
CheckResult AbstractLessThan(Boolean3& result, const Value& l, const Value& r)
{
    Value _1;
    Value _2;

    if (!l.Convert2PrimitiveValueUnsafe(_1, Value::hintNumber) || !r.Convert2PrimitiveValueUnsafe(_2, Value::hintNumber))
        return false;

    const Value::KindType k1 = _1.GetKind();
    const Value::KindType k2 = _2.GetKind();

    if (k1 == Value::kInt && k2 == Value::kInt)
    {
        result = _1.AsInt() < _2.AsInt() ? true3 : false3;
        return true;
    }
    if (k1 == Value::kUInt && k2 == Value::kUInt)
    {
        result = _1.AsUInt() < _2.AsUInt() ? true3 : false3;
        return true;
    }
    if (k1 == Value::kString && k2 == Value::kString && _1.AsStringNode() && _2.AsStringNode())
    {
        result = _1.AsString() < _2.AsString() ? true3 : false3;
        return true;
    }

    if (!_1.ToNumberValueInline() || !_2.ToNumberValueInline())
        return false;

    Boolean3 r3 = undefined3;
    if (!_1.IsNaN() && !_2.IsNaN())
        r3 = _1.AsNumber() < _2.AsNumber() ? true3 : false3;
    result = r3;
    return true;
}

// ==== traits =========================================================================================================

namespace fl { extern const char* NS_AS3; }

// A getter added to a setter (or the reverse) makes a get/set pair; anything else keeps the binding.
static SlotInfo::BindingType GetNewBT(SlotInfo::BindingType bt, SlotInfo::BindingType new_bt)
{
    if ((bt == SlotInfo::BT_Get && new_bt == SlotInfo::BT_Set) || (bt == SlotInfo::BT_Set && new_bt == SlotInfo::BT_Get))
        bt = SlotInfo::BT_GetSet;

    return bt;
}

// Whether a slot of namespace a is the one named in namespace b: protected namespaces always are, private ones only
// themselves, the rest by uri.
static bool IsSameNamespace(const Instances::Namespace& a, const Instances::Namespace& b)
{
    if (a.GetKind() != b.GetKind())
        return false;
    if (a.GetKind() == Abc::NS_Protected)
        return true;
    if (a.GetKind() == Abc::NS_Private)
        return &a == &b;
    return a.GetUri().GetNode() == b.GetUri().GetNode();
}

// The namespace a native method is registered in: its own (the AS3 one, or interned by uri), else the package of a
// nameless class, else public.
static Pickable<const Instances::Namespace> GetMethodNamespace(VM& vm, const ClassInfo& ci, const ThunkInfo& func)
{
    const char* ns_name = func.NamespaceName;
    if (ns_name && *ns_name)
    {
        if (ns_name == fl::NS_AS3 || strcmp(ns_name, fl::NS_AS3) == 0)
            return Pickable<const Instances::Namespace>(&vm.GetAS3Namespace(), PickValue);
        return vm.MakeInternedNamespace(Abc::NS_Public, ns_name);
    }
    if ((ci.Name == NULL || *ci.Name == '\0') && ci.PkgName && *ci.PkgName)
        return vm.MakeInternedNamespace(Abc::NS_Public, ci.PkgName);
    return Pickable<const Instances::Namespace>(&vm.GetPublicNamespace(), PickValue);
}

// @0x1424e5500
void Traits::Add2StoredScopeStack(const Value& o)
{
    // The exe tail-calls the out-of-line ArrayDH<Value>::PushBack (sfr_as3_04); the SF_NOINLINE specialization
    // declaration above keeps it out of line (under MS2_AS3_SCU cl would otherwise inline it).
    InitScope.PushBack(o);
}

// MS2-FUNCTIONAL: SDK body (new_bt reused for the GetNewBT result, empty getter/setter else-if). What is left: the
// exe keeps the name temp's node in a saved register across SetMethod and AddMethod (its SCU knew they leave the
// temp alone; SetMethod is out of line in another unit here). VTable::AddMethod is SF_NOINLINE below: the exe
// calls it.
// @0x1424e5510
void Traits::Add2VT(SlotInfo& si, const Value& v, SlotInfo::BindingType new_bt)
{
    VTable& vt = GetVT();
    AbsoluteIndex method_ind(si.ValueInd);

    si.CppBinding = true;

    if (method_ind.IsValid())
    {
        const SlotInfo::BindingType bt = static_cast<SlotInfo::BindingType>(si.BindType);

        if (bt == SlotInfo::BT_Code && new_bt != bt)
        {
            return;
        } else if ((bt == SlotInfo::BT_GetSet || bt == SlotInfo::BT_Get || bt == SlotInfo::BT_Set) && new_bt == SlotInfo::BT_Code)
        {
        }

        vt.SetMethod(method_ind, v, new_bt, ASString(si.Name.GetPtr()));

        new_bt = GetNewBT(bt, new_bt);
        if (new_bt != bt)
            si.Bind(new_bt, method_ind);
    } else
    {
        si.Bind(new_bt, vt.AddMethod(v, new_bt, ASString(si.Name.GetPtr())));
    }
}

// @0x1424e5660
void Traits::Add2VT(const ASString& name, const Instances::Namespace& ns, const SlotInfo& nsi, const Value& v,
                    SlotInfo::BindingType bt)
{
    const AbsoluteIndex ind = Add(name, nsi);
    SlotInfo& si = GetOwnSlotInfo(ind);
    UpdateVT4IM(name, ns, v, bt);
    Add2VT(si, v, bt);
}

// MS2-FUNCTIONAL: the exe inlines VM::MakeInternedNamespace, UpdateVT4IM and UpdateVT (with VTable::SetMethod) from
// the same unity TU; ours calls them.
// @0x1424e56f0
void Traits::Add2VT(const ClassInfo& ci, const ThunkInfo& func)
{
    VM& vm = GetVM();
    const ASString name = vm.GetStringManager().CreateConstString(func.Name);
    bool ok = true;

    {
        SlotInfo::BindingType bt = SlotInfo::BT_Code;
        switch (func.GetCodeType())
        {
        case CT_Method: bt = SlotInfo::BT_Code; break;
        case CT_Get:    bt = SlotInfo::BT_Get;  break;
        case CT_Set:    bt = SlotInfo::BT_Set;  break;
        }

        const Value v(func);
        const SlotInfo nsi(GetMethodNamespace(vm, ci, func), NULL, SlotInfo::aDontEnum, name.GetNode());
        const Instances::Namespace& ns = *nsi.pNs;

        // the slot of this name in this namespace, own or inherited
        SPInt ind = -1;
        if (const UInt32* values = FindSlotValues(name))
        {
            for (ind = *values; ind >= 0; ind = GetPrevSlotIndex(ind))
            {
                if (IsSameNamespace(*GetSlotInfo(AbsoluteIndex(ind)).pNs, ns))
                    break;
            }
        }

        if (ind < 0)
            Add2VT(name, ns, nsi, v, bt);
        else
        {
            const SlotInfo& si = GetSlotInfo(AbsoluteIndex(ind));
            const SlotInfo::BindingType cur_bt = static_cast<SlotInfo::BindingType>(si.BindType);

            if (cur_bt != SlotInfo::BT_Unknown && (cur_bt < SlotInfo::BT_Code || cur_bt > SlotInfo::BT_GetSet))
                ok = false;
            else if (GetNewBT(cur_bt, bt) == bt)
            {
                // an override
                UpdateVT4IM(name, ns, v, bt);
                UpdateVT(si, v, bt);
            }
            else
                Add2VT(name, ns, si, v, bt);
        }
    }

    if (!ok)
        vm.ThrowVerifyError(VM::Error(VM::eIllegalOverrideError, vm, name.ToCStr(), GetName().ToCStr()));
}

// MS2-FUNCTIONAL: same operations; the SlotInfo bit-field build and the inlined release of the placeholder's
// SPtrs are scheduled differently (as in AddSlot).
// @0x1424e93b0
SlotInfo& Traits::AddSetSlot(RelativeIndex ind, const ASString& name, Pickable<const Instances::Namespace> ns,
                             VMAbcFile& file, const Abc::TraitInfo& ti, bool const_)
{
    const UInt32 abs_ind = static_cast<UInt32>(FirstOwnSlotInd.Get() + ind.Get());

    // slot ids may skip: the gap gets unnamed placeholders
    while (GetSlotInfoNum() < abs_ind)
        Add(GetVM().GetStringManager().CreateEmptyString(), SlotInfo());

    AbsoluteIndex result(abs_ind);
    if (abs_ind == GetSlotInfoNum())
        result = Add(name, SlotInfo(ns, file, ti, (const_ ? SlotInfo::aReadOnly : SlotInfo::aNone) |
                                                      SlotInfo::aDontEnum, name.GetNode()));
    else
    {
        GetOwnSlotInfo(result) = SlotInfo(ns, file, ti, (const_ ? SlotInfo::aReadOnly : SlotInfo::aNone) |
                                                            SlotInfo::aDontEnum, name.GetNode());
        SetKey(result, name);
    }

    return GetOwnSlotInfo(result);
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also stores the flag word earlier).
// @0x1424e9670
AbsoluteIndex Traits::AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, VMAbcFile& file,
                              const Abc::TraitInfo& ti, bool const_)
{
    int attr = const_ ? (SlotInfo::aDontEnum | SlotInfo::aReadOnly) : SlotInfo::aDontEnum;

    return Add(name, SlotInfo(ns, file, ti, attr, name.GetNode()));
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also stores the flag word earlier).
// @0x1424e9740
void Traits::AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, const ClassTraits::Traits* tr,
                     SlotInfo::BindingType dt, AbsoluteIndex offset, bool const_)
{
    int attr = const_ ? (SlotInfo::aDontEnum | SlotInfo::aReadOnly) : SlotInfo::aDontEnum;

    const AbsoluteIndex ind = Add(name, SlotInfo(ns, tr, attr, name.GetNode()));
    GetOwnSlotInfo(ind).Bind(dt, offset);
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also stores the flag word earlier).
// @0x1424e9830
void Traits::AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, SlotInfo::BindingType dt,
                     AbsoluteIndex offset, bool const_)
{
    int attr = const_ ? (SlotInfo::aDontEnum | SlotInfo::aReadOnly) : SlotInfo::aDontEnum;

    const AbsoluteIndex ind = Add(name, SlotInfo(ns, NULL, attr, name.GetNode()));
    GetOwnSlotInfo(ind).Bind(dt, offset);
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also stores the flag word earlier).
// @0x1424e9910
void Traits::AddSlot(const MemberInfo& mi)
{
    VM& vm = GetVM();
    int attr = (mi.Const != 0) ? (SlotInfo::aDontEnum | SlotInfo::aReadOnly) : SlotInfo::aDontEnum;
    attr |= SlotInfo::aCppBinding;
    ASString name = vm.GetStringManager().CreateConstString(mi.Name);

    const AbsoluteIndex ind =
        Add(name, SlotInfo(Pickable<const Instances::Namespace>(vm.PublicNamespace.GetPtr(), PickValue), NULL, attr,
                           name.GetNode()));
    GetOwnSlotInfo(ind).Bind(static_cast<SlotInfo::BindingType>(mi.BT), AbsoluteIndex(mi.Offset));
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also stores the flag word earlier).
// @0x1424e9a50
void Traits::AddSlotCPP(const ASString& name, Pickable<const Instances::Namespace> ns, const ClassTraits::Traits* tr,
                        SlotInfo::BindingType dt, AbsoluteIndex offset, bool const_)
{
    int attr = const_ ? (SlotInfo::aDontEnum | SlotInfo::aReadOnly) : SlotInfo::aDontEnum;
    attr |= SlotInfo::aCppBinding;

    const AbsoluteIndex ind = Add(name, SlotInfo(ns, tr, attr, name.GetNode()));
    GetOwnSlotInfo(ind).Bind(dt, offset);
}

// Data traits (slot, class, function, const) may carry a slot id.
static bool HasSlotID(const Abc::TraitInfo& ti)
{
    const Abc::TraitInfo::Type type = ti.GetType();
    return type == Abc::TraitInfo::tSlot || (type >= Abc::TraitInfo::tClass && type <= Abc::TraitInfo::tConst);
}

static bool IsCodeTrait(const Abc::TraitInfo& ti)
{
    const Abc::TraitInfo::Type type = ti.GetType();
    return (type >= Abc::TraitInfo::tMethod && type <= Abc::TraitInfo::tSetter) || type == Abc::TraitInfo::tFunction;
}

// The declared type of a slot or const; a class trait is typed by its class's name.
static const Abc::Multiname& GetTypeName(const Abc::File& f, const Abc::TraitInfo& ti)
{
    const Abc::TraitInfo::Type type = ti.GetType();
    if (type == Abc::TraitInfo::tSlot || type == Abc::TraitInfo::tConst)
        return f.Const_Pool.GetMultiname(ti.Ind);
    return f.Const_Pool.GetMultiname(f.AS3_Classes.Info[ti.Ind]->inst_info.name_ind);
}

// How trait ti binds; classes and consts are read only.
static SlotInfo::BindingType GetTraitBT(const Traits& tr, VMAbcFile& file, const Abc::TraitInfo& ti, bool& const_)
{
    switch (ti.GetType())
    {
    case Abc::TraitInfo::tMethod:
    case Abc::TraitInfo::tFunction:
        return SlotInfo::BT_Code;
    case Abc::TraitInfo::tGetter:
        return SlotInfo::BT_Get;
    case Abc::TraitInfo::tSetter:
        return SlotInfo::BT_Set;
    case Abc::TraitInfo::tClass:
    case Abc::TraitInfo::tConst:
        const_ = true;
        // no break
    case Abc::TraitInfo::tSlot:
        return tr.GetBindingType(file, GetTypeName(file.GetAbcFile(), ti));
    }
    return SlotInfo::BT_ValueArray;
}

// Method v (named name in nsi's namespace) overrides the slot of that name and namespace, or gets a new one. False
// when that slot is not a method.
static bool RegisterWithVT(Traits& tr, const ASString& name, const SlotInfo& nsi, const Value& v,
                           SlotInfo::BindingType bt)
{
    const Instances::Namespace& ns = *nsi.pNs;

    SPInt ind = -1;
    if (const UInt32* values = tr.FindSlotValues(name))
    {
        for (ind = *values; ind >= 0; ind = tr.GetPrevSlotIndex(ind))
        {
            if (IsSameNamespace(*tr.GetSlotInfo(AbsoluteIndex(ind)).pNs, ns))
                break;
        }
    }

    if (ind < 0)
    {
        tr.Add2VT(name, ns, nsi, v, bt);
        return true;
    }

    const SlotInfo& si = tr.GetSlotInfo(AbsoluteIndex(ind));
    const SlotInfo::BindingType cur_bt = static_cast<SlotInfo::BindingType>(si.BindType);
    if (cur_bt != SlotInfo::BT_Unknown && (cur_bt < SlotInfo::BT_Code || cur_bt > SlotInfo::BT_GetSet))
        return false;

    if (GetNewBT(cur_bt, bt) == bt)
    {
        tr.UpdateVT4IM(name, ns, v, bt);
        tr.UpdateVT(si, v, bt);
    }
    else
        tr.Add2VT(name, ns, si, v, bt);
    return true;
}

// MS2-FUNCTIONAL: same operations; the exe inlines UpdateVT4IM/UpdateVT (with VTable::SetMethod) and
// VM::ThrowVerifyError from the same unity TU, ours calls them.
// @0x1424e9b40
CheckResult Traits::AddSlots(const Abc::HasTraits& traits, VMAbcFile& file, unsigned parent_size)
{
    VM& vm = file.GetVM();

    // slots with an id, in any order
    for (UInt32 i = 0; i < traits.obj_traits.GetSize(); ++i)
    {
        const Abc::TraitInfo& ti = *file.GetAbcFile().Traits.TraitInfos[traits.obj_traits[i]];
        if (!HasSlotID(ti))
            continue;
        const Abc::Multiname& mn = file.GetAbcFile().Const_Pool.GetMultiname(ti.name_ind);
        if (ti.SlotId == 0)
            continue;

        bool const_ = false;
        const SlotInfo::BindingType bt = GetTraitBT(*this, file, ti, const_);
        const ASString name = file.GetInternedString(mn.NameIndex);
        SlotInfo& si = AddSetSlot(RelativeIndex(ti.SlotId - 1), name,
                                  Pickable<const Instances::Namespace>(&file.GetInternedNamespace(mn), PickValue),
                                  file, ti, const_);

        const SlotInfo::BindingType cur_bt = static_cast<SlotInfo::BindingType>(si.BindType);
        bool ok;
        if (IsCodeTrait(ti))
        {
            ok = cur_bt == SlotInfo::BT_Unknown || (cur_bt >= SlotInfo::BT_Code && cur_bt <= SlotInfo::BT_GetSet);
            if (ok)
                Add2VT(si, Value(static_cast<SInt32>(ti.Ind)), bt);
        }
        else
        {
            ok = cur_bt == SlotInfo::BT_Unknown;
            if (ok)
                si.Bind(bt, AbsoluteIndex(-1));
        }

        if (!ok)
        {
            vm.ThrowVerifyError(VM::Error(VM::eIllegalOverrideError, vm, name.ToCStr(), GetName().ToCStr()));
            return false;
        }
    }

    // the other members and the methods, in order
    bool result = true;
    for (UInt32 i = 0; i < traits.obj_traits.GetSize(); ++i)
    {
        const Abc::TraitInfo& ti = *file.GetAbcFile().Traits.TraitInfos[traits.obj_traits[i]];
        if (HasSlotID(ti) && ti.SlotId != 0)
            continue;

        const Abc::Multiname& mn = file.GetAbcFile().Const_Pool.GetMultiname(ti.name_ind);
        const AbsoluteIndex offset(IsCodeTrait(ti) ? -1 : static_cast<SPInt>(FixedValueSlotNumber++));
        bool const_ = false;
        const SlotInfo::BindingType bt = GetTraitBT(*this, file, ti, const_);
        const ASString name = file.GetInternedString(mn.NameIndex);
        Instances::Namespace& ns = file.GetInternedNamespace(mn);
        const SlotInfo nsi(Pickable<const Instances::Namespace>(&ns, PickValue), file, ti,
                           const_ ? (SlotInfo::aDontEnum | SlotInfo::aReadOnly) : SlotInfo::aDontEnum,
                           (GetQualifiedName() + "/" + name).GetNode());

        if (IsCodeTrait(ti))
            result = RegisterWithVT(*this, name, nsi, Value(static_cast<SInt32>(ti.Ind)), bt);
        else
        {
            const AbsoluteIndex ind = Add(name, nsi);
            SlotInfo& si = GetOwnSlotInfo(ind);
            if (si.BindType == SlotInfo::BT_Unknown)
                si.Bind(bt, offset);
            else
                result = false;
        }

        if (!result)
        {
            vm.ThrowVerifyError(VM::Error(VM::eIllegalOverrideError, vm, name.ToCStr(), GetName().ToCStr()));
            return false;
        }
    }

    CalculateMemSize(parent_size);
    return result;
}

// ==== virtual machine ================================================================================================

// @0x1424eaf00
void VM::AddVMAbcFileWeak(VMAbcFile* file)
{
    if (!InDestructor)
        VMAbcFilesWeak.PushBack(file);
}

// @0x1424eb610
void* Traits::Alloc() const
{
    AllocInfo info(StatMV_VM_Instance_Mem, NULL, 0);
    return GetVM().GetMemoryHeap()->Alloc(MemSize, &info);
}

// @0x1424eb640
ValueRegisterFile::Page* ValueRegisterFile::AllocPage(UInt16 pageSize)
{
    if (pageSize > MaxAllocatedPageSize)
        MaxAllocatedPageSize = static_cast<UInt16>((pageSize + 64) / 64 * 64);
    else
        MaxAllocatedPageSize = Alg::Max<UInt16>(MaxAllocatedPageSize, 64);

    const UInt16 size = MaxAllocatedPageSize;
    Page* p = static_cast<Page*>(SF_HEAP_AUTO_ALLOC(this, sizeof(Page) - sizeof(Value) +
                                                         (sizeof(Value) + sizeof(UInt16)) * size));
    p->PageSize    = size;
    p->ReservedNum = 0;
    p->CurrPos     = 0;
    p->pCurrent    = NULL;
    return p;
}

// @0x1424eb6b0
ValueStack::Page* ValueStack::AllocPage(UInt16 pageSize)
{
    const UInt16 size = Alg::Max<UInt16>(pageSize, 64);
    Page* p = static_cast<Page*>(SF_HEAP_AUTO_ALLOC(this, sizeof(Page) + sizeof(Value) * (size - 1)));
    p->PageSize       = size;
    p->ReservationNum = 0;
    return p;
}

// ==== the load queue ====

// Clears queued actions, releases each recycled ActionEntry's references, then frees the same nodes.
// @0x1424dda00
MovieRoot::ActionQueueType::~ActionQueueType()
{
    Clear();
    for (ActionEntry* pcur = pFreeEntry; pcur; )
    {
        ActionEntry* pnext = pcur->pNextEntry;
        delete pcur;
        pcur = pnext;
    }
}

// @0x1424de310
LoadQueueEntry::~LoadQueueEntry()
{
    if (NotifyLoadInitCInterface)
        NotifyLoadInitCInterface = 0;
}

// Inlined into MovieRoot::AddLoadQueueEntryMT in the exe.
inline LoadQueueEntryMT_LoadMovie::LoadQueueEntryMT_LoadMovie(LoadQueueEntry* pqueueEntry, MovieImpl* pmovieImpl)
    : LoadQueueEntryMT(pqueueEntry, pmovieImpl)
{
    CharSwitched     = false;
    FirstFrameLoaded = false;
    BytesLoaded      = 0;
    bool stripped = false;
    if (InteractiveObject* pmain = pMovieImpl->pASMovieRoot->GetMovieImpl()->pMainMovie)
        stripped = (pmain->GetResourceMovieDef()->GetSWFFlags() & 0x10) != 0; // MovieInfo::SWF_Stripped
    pPreloadTask = *SF_NEW MoviePreloadTask(pMovieImpl, pqueueEntry->URL, stripped, pqueueEntry->QuietOpen);
    Ptr<TaskManager> ptm = *static_cast<TaskManager*>(pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager));
    ptm->AddTask(pPreloadTask);
}

// The LoadMovie entry's cancel loop reads the head through this root's pMovieImpl, after the inlined ctor.
// @0x1424e8c20
void MovieRoot::AddLoadQueueEntryMT(LoadQueueEntry* pentry)
{
    LoadQueueEntryMT* pentryMT;
    if (pentry->Type & GFx::LoadQueueEntry::LTF_VarsFlag)
        pentryMT = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) LoadQueueEntryMT_LoadVars(pentry, pMovieImpl);
    else if (pentry->Type & GFx::LoadQueueEntry::LTF_BinaryFlag)
        pentryMT = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) LoadQueueEntryMT_LoadBinary(pentry, pMovieImpl);
    else
    {
        pentryMT = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) LoadQueueEntryMT_LoadMovie(pentry, pMovieImpl);
        if (pentryMT)
        {
            // A newer load of the same Loader / URLLoader replaces the pending ones.
            LoadQueueEntry* pnew = static_cast<LoadQueueEntry*>(pentryMT->GetQueueEntry());
            for (LoadQueueEntryMT* p = pMovieImpl->pLoadQueueMTHead; p; p = p->GetNext())
            {
                LoadQueueEntry* pother = static_cast<LoadQueueEntry*>(p->GetQueueEntry());
                if ((pother->mLoader && pother->mLoader == pnew->mLoader) ||
                    (pother->mURLLoader && pother->mURLLoader == pnew->mURLLoader))
                    pother->Canceled = true;
            }
        }
    }
    if (pentryMT)
        pMovieImpl->AddLoadQueueEntryMT(pentryMT);
    else
        delete pentry;
}

// @0x1424e9010
void MovieRoot::AddNewLoadQueueEntry(Instances::fl_utils::ByteArray* bytes, Instances::fl_display::Loader* loader,
                                     GFx::LoadQueueEntry::LoadMethod method)
{
    LoadQueueEntry* pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) LoadQueueEntry(bytes, loader, method);
    if (pentry)
        pMovieImpl->AddLoadQueueEntry(pentry);
}

// An image protocol URL ("img://") loaded synchronously is processed at once; other URLs go to the loader thread
// when there is a task manager.
// MS2-FUNCTIONAL: the exe inlines the entry's ctor and keeps the TaskManager Ptr in a flag-guarded temporary
// @0x1424e9090
void MovieRoot::AddNewLoadQueueEntry(Instances::fl_net::URLRequest* urlRequest, Instances::fl_display::Loader* loader,
                                     GFx::LoadQueueEntry::LoadMethod method)
{
    LoadQueueEntry* pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) LoadQueueEntry(urlRequest, loader, method);
    if (!pentry)
        return;
    bool sync;
    const bool image = LoaderImpl::IsProtocolImage(pentry->URL, NULL, &sync);
    if (image && sync)
    {
        Ptr<LoadStates> pls = *SF_NEW LoadStates(pMovieImpl->pMainMovieDef->pLoaderImpl,
                                                 pMovieImpl->GetStateBag()->GetStateBagImpl());
        ProcessLoadQueueEntry418(pentry, pls);
        delete pentry;
        return;
    }
    if (pentry->URL.GetLength() != 0 && !image &&
        Ptr<State>(*pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager)))
        AddLoadQueueEntryMT(pentry);
    else
        pMovieImpl->AddLoadQueueEntry(pentry);
}

// @0x1424e9210
void MovieRoot::AddNewLoadQueueEntry(Instances::fl_net::URLRequest* urlRequest, Instances::fl_net::URLLoader* loader,
                                     GFx::LoadQueueEntry::LoadMethod method)
{
    LoadQueueEntry* pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) LoadQueueEntry(urlRequest, loader, method);
    if (!pentry)
        return;
    pentry->Type = loader->IsLoadingBinary() ? GFx::LoadQueueEntry::LT_LoadBinary : GFx::LoadQueueEntry::LT_LoadText;
    if (pentry->URL.GetLength() != 0 &&
        Ptr<State>(*pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager)))
        AddLoadQueueEntryMT(pentry);
    else
        pMovieImpl->AddLoadQueueEntry(pentry);
}

// Only the This member Value is released (its SCU ~Value inlines).
// @0x1424de8f0
inline PropRef::~PropRef()
{
}
// odr-uses the inline destructor, so this unit emits its copy
static void (* const pSfr16PropRefDtor)(PropRef*) = [](PropRef* p) { p->~PropRef(); };

// @0x1424e0b40
PropRef& PropRef::operator=(PropRef&& other)
{
    // The exe copies the union once per member (pSI, pValue, pObject).
    pSI = other.pSI;
    pValue = other.pValue;
    pObject = other.pObject;
    SlotIndex = other.SlotIndex;
    This.Assign(other.This);
    return *this;
}

// PropRef::IsAsValue / IsAsObject: the tag bit as a bool
static inline bool Sfr16PropRefTag(const Value* p, UPInt mask) { return (reinterpret_cast<UPInt>(p) & mask) != 0; }

// @0x1424e0e20
PropRef::operator bool() const
{
    // SDK 4.2 PropRef::IsFound: the ValueFlag (1) and ObjectFlag (2) tags with a null pointer are "not found"
    return !(This.IsUndefined() ||
             (Sfr16PropRefTag(pValue, 1) && (reinterpret_cast<UPInt>(pValue) & ~UPInt(1)) == 0) ||
             (Sfr16PropRefTag(pValue, 2) && (reinterpret_cast<UPInt>(pValue) & ~UPInt(2)) == 0));
}

// The two ReadArgs variants own a heap-backed copy of their argument values.
// MS2-FUNCTIONAL: the executable calls ArrayDH<Value>::~ArrayDH out of line; this TU inlines that release sequence.
// @0x1424de9e0
ReadArgs::~ReadArgs() = default;

namespace TR {
// Releases the CallArgs values, eight FixedArgs, and the StackReader references in the same order; cl inlines their member destructors.
// @0x1424dea90
ReadArgs::~ReadArgs() {}

// Releases ArgObject and the inherited multiname/string references.
// @0x1424ded40
ReadMnObject::~ReadMnObject() {}

// Releases ArgValue with Value's destructor.
// @0x1424dedc0
SF_NOINLINE ReadValue::~ReadValue() {}

// Releases ArgObject before the ReadValueMn base and its ArgValue/multiname members.
// @0x1424dee30
ReadValueMnObject::~ReadValueMnObject() {}
}

// The base VM has no E4X implementation.
// @0x1424e6980
bool XMLSupport::Add(Value&, Object&, Object&) const
{
    return false;
}

// E4X addition flattens XML and XMLList operands into a newly allocated XMLList.
// @0x1424e6990
bool XMLSupportImpl::Add(Value& result, Object& l, Object& r) const
{
    const Traits& ltr = l.GetTraits();
    const Traits& rtr = r.GetTraits();
    const BuiltinTraitsType ltt = ltr.GetTraitsType();
    const BuiltinTraitsType rtt = rtr.GetTraitsType();
    if ((ltt == Traits_XML || ltt == Traits_XMLList) && ltr.IsInstanceTraits() &&
        (rtt == Traits_XML || rtt == Traits_XMLList) && rtr.IsInstanceTraits())
    {
        InstanceTraits::fl::XMLList& listTraits =
            *static_cast<InstanceTraits::fl::XMLList*>(GetITraitsXMLList());
        Pickable<Instances::fl::XMLList> list = listTraits.MakeInstance(listTraits);
        switch (ltt)
        {
        case Traits_XML:
            list->Append(static_cast<Instances::fl::XML*>(&l));
            break;
        case Traits_XMLList:
            list->Append(static_cast<Instances::fl::XMLList&>(l));
            break;
        default:
            break;
        }
        switch (rtt)
        {
        case Traits_XML:
            list->Append(static_cast<Instances::fl::XML*>(&r));
            break;
        case Traits_XMLList:
            list->Append(static_cast<Instances::fl::XMLList&>(r));
            break;
        default:
            break;
        }
        result.Pick(list);
        return true;
    }
    return false;
}

}}} // namespace Scaleform::GFx::AS3

// AvmLoader's multiple-inheritance teardown, including its AS3 subobject.
// Clears the loader state and tears down the same modeled bases.
// @0x1424ddc40
Scaleform::GFx::AS3::AvmLoader::~AvmLoader()
{
    AvmObjOffset = 0;
}

// Invokes an object-like value with no arguments and an undefined receiver. The VM and the undefined receiver are
// named locals: that gives the exe's argument order (r9 before r8).
// @0x1424e1a20
Scaleform::GFx::AS3::Value* FUN_1424e1a20(const Scaleform::GFx::AS3::Value* func,
                                         Scaleform::GFx::AS3::Value* result)
{
    using namespace Scaleform::GFx::AS3;
    new (result) Value();
    if (Value::IsObject(func->GetKind()))
    {
        Object& object = *const_cast<Value*>(func);
        VM& vm = object.GetTraits().GetVM();
        const Value& undef = Value::GetUndefined();
        vm.ExecuteInternalUnsafe(*func, undef, *result, 0, nullptr, false);
    }
    return result;
}

// Releases the rollover references in reverse order, then the raw heap array.
// A rollover array of NTS-refcounted objects followed by the last hovered one; the implicit dtor releases the
// last hovered object, then the array from its end.
struct Unk_As3_16RolloverState
{
    Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::RefCountNTSImpl> > Rollover;  // +0x00
    Scaleform::Ptr<Scaleform::RefCountNTSImpl>                      LastHover; // +0x18
};

// @0x1424de510
void FUN_1424de510(void* self)
{
    static_cast<Unk_As3_16RolloverState*>(self)->~Unk_As3_16RolloverState();
}

// MS2-PIN: ?Sfr34_ModifyOptimizedPlayList@AS3@GFx@Scaleform@@YAXPEAVInteractiveObject@23@@Z 0x142517e70
// @0x1424e9380
void FUN_1424e9380(Scaleform::GFx::ASMovieRootBase*, Scaleform::GFx::DisplayObject* pcont)
{
    if (*reinterpret_cast<void**>(reinterpret_cast<Scaleform::UPInt>(pcont) + 0x38) == NULL)
    {
        Scaleform::GFx::InteractiveObject* interactive =
            reinterpret_cast<Scaleform::GFx::InteractiveObject*>(pcont);
        interactive->AddToPlayList();
        Scaleform::GFx::AS3::Sfr34_ModifyOptimizedPlayList(interactive);
    }
}

// Out-of-line SPtr copy and raw-pointer assignments from the surrounding AS3 cache and trait code.
// @0x1424e0550
template Scaleform::GFx::AS3::SPtr<const Scaleform::GFx::AS3::Instances::Namespace>&
Scaleform::GFx::AS3::SPtr<const Scaleform::GFx::AS3::Instances::Namespace>::operator=(
    const Scaleform::GFx::AS3::SPtr<const Scaleform::GFx::AS3::Instances::Namespace>&);
// @0x1424e05c0
template Scaleform::GFx::AS3::SPtr<const Scaleform::GFx::AS3::ClassTraits::Traits>&
Scaleform::GFx::AS3::SPtr<const Scaleform::GFx::AS3::ClassTraits::Traits>::operator=(
    const Scaleform::GFx::AS3::SPtr<const Scaleform::GFx::AS3::ClassTraits::Traits>&);
// @0x1424e08d0
template Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>&
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>::operator=(
    const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>&);
// @0x1424e0630
template Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>&
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>::operator=(
    const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>&);
// @0x1424e06a0
template Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>&
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>::operator=(
    const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>&);
// @0x1424e0710
template Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>&
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>::SetPtr(
    Scaleform::GFx::AS3::GASRefCountBase*);
// @0x1424e0780
template Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>&
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>::operator=(
    const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>&);
// @0x1424e07f0
template Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>&
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>::operator=(
    const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>&);


// ArrayPagedBase<CallFrame, 6, 64, AllocatorPagedCC<CallFrame, 329>>::ClearAndRelease.
struct Sfr16CallFramePages
{
    void* Pad00;
    Scaleform::UPInt Size;      // +0x08
    Scaleform::UPInt NumPages;  // +0x10
    Scaleform::UPInt MaxPages;  // +0x18
    Scaleform::GFx::AS3::CallFrame** Pages; // +0x20
};
// @0x1424dc8e0
void FUN_1424dc8e0(void* self)
{
    using Scaleform::UPInt;
    using Scaleform::GFx::AS3::CallFrame;
    Sfr16CallFramePages* a = static_cast<Sfr16CallFramePages*>(self);
    if (a->NumPages)
    {
        CallFrame** blk = a->Pages + a->NumPages - 1;
        const UPInt numDataPages = (a->Size > 0 ? a->Size >> 6 : 0);
        while (a->NumPages--)
        {
            const UPInt freeCount = (a->NumPages < numDataPages ? 64 : (a->NumPages == numDataPages ? (a->Size & 63) : 0));
            CallFrame* p = *blk + freeCount - 1;
            for (UPInt i = 0; i < freeCount; ++i, --p)
                p->~CallFrame();
            Scaleform::Memory::pGlobalHeap->Free(*blk);
            --blk;
        }
        Scaleform::Memory::pGlobalHeap->Free(a->Pages);
    }
    a->Size = a->NumPages = a->MaxPages = 0;
    a->Pages = 0;
}

// Releases an owned ArrayPOD allocation before clearing the wrapper's pointer and owner flag.
// @0x1424dc9f0
void FUN_1424dc9f0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    void* object = *reinterpret_cast<void**>(bytes);
    if (object)
    {
        if (bytes[8])
        {
            bytes[8] = 0;
            void* data = *reinterpret_cast<void**>(object);
            if (data)
            {
                auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
                reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(Scaleform::Memory::pGlobalHeap, data);
            }
            auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
            reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(Scaleform::Memory::pGlobalHeap, object);
        }
        *reinterpret_cast<void**>(bytes) = 0;
    }
    bytes[8] = 0;
}

// (sfg) a 0x10-byte trivially destructible payload; only the 0x28-byte cached node entry matters here.
struct Unk_As3_16HashPayload16 { Scaleform::UPInt A, B; };

// HashLH<UPInt, 16-byte POD> dtor: clears the chained entries to the free sentinel, then releases the table block.
// @0x1424dca60
void FUN_1424dca60(void* self)
{
    static_cast<Scaleform::HashLH<Scaleform::UPInt, Unk_As3_16HashPayload16>*>(self)->~HashLH();
}

// HashNode<DynAttrsKey, Value> releases the Value union and its ASString key.
// @0x1424dcac0
void FUN_1424dcac0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    reinterpret_cast<Scaleform::GFx::AS3::Value*>(bytes + 0x10)->~Value();
    auto* name = *reinterpret_cast<Scaleform::GFx::ASStringNode**>(bytes + 8);
    if (--name->RefCount == 0)
        name->ReleaseNode();
}

// HashNode<ASString, Value> releases its Value payload and string key.
// @0x1424dcb40
SF_NOINLINE void FUN_1424dcb40(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    reinterpret_cast<Scaleform::GFx::AS3::Value*>(bytes + 8)->~Value();
    auto* name = *reinterpret_cast<Scaleform::GFx::ASStringNode**>(bytes);
    if (--name->RefCount == 0)
        name->ReleaseNode();
}

// Value::~Value (the SCU Release: weak proxy drop or ReleaseInternal).
// @0x1424dd460
void FUN_1424dd460(void* self)
{
    static_cast<Scaleform::GFx::AS3::Value*>(self)->~Value();
}

namespace Scaleform {
using SfrCx18DisplayObjectArray = ArrayLH<WeakPtr<GFx::DisplayObject>, 2, ArrayDefaultPolicy>;
using SfrCx18DisplayObjectList = AutoPtr<SfrCx18DisplayObjectArray>;
using SfrCx18DisplayObjectNode = HashNode<int, SfrCx18DisplayObjectList, IdentityHash<int> >;
using SfrCx18DisplayObjectSet = HashSetBase<SfrCx18DisplayObjectNode,
    SfrCx18DisplayObjectNode::NodeHashF, SfrCx18DisplayObjectNode::NodeAltHashF,
    AllocatorLH<int, 2>, HashsetNodeEntry<SfrCx18DisplayObjectNode, SfrCx18DisplayObjectNode::NodeHashF> >;
// The entry Clear stays out of line in the exe (0x1424ef970, instantiated in sfr_as3_17).
template<> SF_NOINLINE void HashsetNodeEntry<SfrCx18DisplayObjectNode, SfrCx18DisplayObjectNode::NodeHashF>::Clear();
using SfrCx18DynAttrsNode = HashNode<GFx::AS3::Object::DynAttrsKey, GFx::AS3::Value,
    GFx::AS3::Object::DynAttrsKeyHashFunctor>;
using SfrCx18DynAttrsSet = HashSetBase<SfrCx18DynAttrsNode, SfrCx18DynAttrsNode::NodeHashF,
    SfrCx18DynAttrsNode::NodeAltHashF, AllocatorLH<GFx::AS3::Object::DynAttrsKey, 2>,
    HashsetCachedNodeEntry<SfrCx18DynAttrsNode, SfrCx18DynAttrsNode::NodeHashF> >;
using SfrCx18AbcNamespaceHash = GFx::AS3::AbcMultinameHash<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>, 340>;
using SfrCx18AbcNamespaceNode = HashNode<SfrCx18AbcNamespaceHash::Key,
    GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>, FixedSizeHash<SfrCx18AbcNamespaceHash::Key> >;
using SfrCx18AbcNamespaceSet = HashSetBase<SfrCx18AbcNamespaceNode, SfrCx18AbcNamespaceNode::NodeHashF,
    SfrCx18AbcNamespaceNode::NodeAltHashF, AllocatorLH<SfrCx18AbcNamespaceHash::Key, 340>,
    HashsetCachedNodeEntry<SfrCx18AbcNamespaceNode, SfrCx18AbcNamespaceNode::NodeHashF> >;
using SfrCx18ClassTraitsHash = GFx::AS3::MultinameHash<GFx::AS3::ClassTraits::Traits*, 329>;
using SfrCx18ClassTraitsNode = HashNode<SfrCx18ClassTraitsHash::Key, GFx::AS3::ClassTraits::Traits*,
    SfrCx18ClassTraitsHash::Key::HashFunctor>;
using SfrCx18ClassTraitsSet = HashSetBase<SfrCx18ClassTraitsNode, SfrCx18ClassTraitsNode::NodeHashF,
    SfrCx18ClassTraitsNode::NodeAltHashF, AllocatorDH<SfrCx18ClassTraitsNode, 329>,
    HashsetCachedNodeEntry<SfrCx18ClassTraitsNode, SfrCx18ClassTraitsNode::NodeHashF> >;
using SfrCx18GASRefValue = GFx::AS3::SPtr<GFx::AS3::GASRefCountBase>;
using SfrCx18GASRefSet = HashSetBase<SfrCx18GASRefValue, FixedSizeHash<SfrCx18GASRefValue>,
    FixedSizeHash<SfrCx18GASRefValue>, AllocatorLH<SfrCx18GASRefValue, 2>,
    HashsetCachedEntry<SfrCx18GASRefValue, FixedSizeHash<SfrCx18GASRefValue> > >;
using SfrCx18GlobalScriptValue = GFx::AS3::SPtr<GFx::AS3::Instances::fl::GlobalObjectScript>;
using SfrCx18GlobalScriptSet = HashSetBase<SfrCx18GlobalScriptValue, FixedSizeHash<SfrCx18GlobalScriptValue>,
    FixedSizeHash<SfrCx18GlobalScriptValue>, AllocatorLH<SfrCx18GlobalScriptValue, 2>,
    HashsetCachedEntry<SfrCx18GlobalScriptValue, FixedSizeHash<SfrCx18GlobalScriptValue> > >;
using SfrCx18ParagraphFormat = Render::Text::ParagraphFormatPtr;
using SfrCx18ParagraphFormatSet = HashSetBase<SfrCx18ParagraphFormat, SfrCx18ParagraphFormat::HashFunctor,
    SfrCx18ParagraphFormat::HashFunctor, AllocatorLH<SfrCx18ParagraphFormat, 78>,
    HashsetCachedEntry<SfrCx18ParagraphFormat, SfrCx18ParagraphFormat::HashFunctor> >;
using SfrCx18TextFormat = Render::Text::TextFormatPtr;
using SfrCx18TextFormatSet = HashSetBase<SfrCx18TextFormat, SfrCx18TextFormat::HashFunctor,
    SfrCx18TextFormat::HashFunctor, AllocatorLH<SfrCx18TextFormat, 78>,
    HashsetCachedEntry<SfrCx18TextFormat, SfrCx18TextFormat::HashFunctor> >;
using SfrCx18ASStringValueNode = HashNode<GFx::ASString, GFx::AS3::Value, GFx::ASStringHashFunctor>;
using SfrCx18ASStringValueSet = HashSetBase<SfrCx18ASStringValueNode, SfrCx18ASStringValueNode::NodeHashF,
    SfrCx18ASStringValueNode::NodeAltHashF, AllocatorLH<GFx::ASString, 324>,
    HashsetNodeEntry<SfrCx18ASStringValueNode, SfrCx18ASStringValueNode::NodeHashF> >;
// The entry's node destructor is the out-of-line 0x1424dcb40 in the exe.
template<> inline void HashsetNodeEntry<SfrCx18ASStringValueNode, SfrCx18ASStringValueNode::NodeHashF>::Clear()
{
    FUN_1424dcb40(&Value);
    NextInChain = -2;
}
using SfrCx18ClassTraitsCopyAssignment = SfrCx18ClassTraitsNode& (SfrCx18ClassTraitsNode::*)(
    const SfrCx18ClassTraitsNode&);
static SfrCx18ClassTraitsCopyAssignment SfrCx18ForceClassTraitsCopyAssignment =
    static_cast<SfrCx18ClassTraitsCopyAssignment>(&SfrCx18ClassTraitsNode::operator=);
// @0x1424dcbb0
template SfrCx18DisplayObjectSet::~HashSetBase();
void DestroyMovieRootDisplayObjects(void* set)
{
    static_cast<SfrCx18DisplayObjectSet*>(set)->~HashSetBase();
}
// MS2-FUNCTIONAL: releases the occupied dynamic-property nodes and frees their table; template expansion changes unwind codegen.
// @0x1424dce80
template SfrCx18DynAttrsSet::~HashSetBase();
// MS2-FUNCTIONAL: destroys occupied namespace intern entries and frees the hash table; template unwind code differs.
// @0x1424dcf10
template SfrCx18AbcNamespaceSet::~HashSetBase();
// @0x1424e0480
template void SfrCx18ClassTraitsNode::operator=(const SfrCx18ClassTraitsNode::NodeRef&);
// @0x1424dcfc0
template SfrCx18ClassTraitsSet::~HashSetBase();
// @0x1424dd1a0
template SfrCx18GASRefSet::~HashSetBase();
// @0x1424dd250
template SfrCx18GlobalScriptSet::~HashSetBase();
// MS2-FUNCTIONAL: releases the same cached format references and backing table; the template expansion has different unwind code.
// @0x1424dd300
template SfrCx18ParagraphFormatSet::~HashSetBase();
// MS2-FUNCTIONAL: releases the same cached format references and backing table; the template expansion has different unwind code.
// @0x1424dd3b0
template SfrCx18TextFormatSet::~HashSetBase();
// MS2-FUNCTIONAL: same code and size as the exe; only the loop index and table registers (rbx/rdi) are swapped.
// @0x1424dd110
template SfrCx18ASStringValueSet::~HashSetBase();
}

// The VMAbcFile member arrays whose destructors the exe calls out of line (instantiated elsewhere).
namespace Scaleform {
typedef ArrayDataBase<GFx::AS3::SPtr<GFx::ASStringNode>, AllocatorLH<GFx::AS3::SPtr<GFx::ASStringNode>, 2>, ArrayDefaultPolicy> Sfr16AdbStr;
typedef ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, 340>, ArrayDefaultPolicy> Sfr16AdbNsSet;
typedef ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, 340>, ArrayDefaultPolicy> Sfr16AdbCtr;
typedef ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, 340>, ArrayDefaultPolicy> Sfr16AdbFile;
typedef ArrayDataBase<GFx::AS3::Abc::MethodBodyInfo::Exception, AllocatorLH<GFx::AS3::Abc::MethodBodyInfo::Exception, 340>, ArrayDefaultPolicy> Sfr16AdbExc;
typedef ArrayDataBase<ArrayLH_POD<UInt64, 338, ArrayDefaultPolicy>, AllocatorLH<ArrayLH_POD<UInt64, 338, ArrayDefaultPolicy>, 340>, ArrayDefaultPolicy> Sfr16AdbPod;
template<> SF_NOINLINE Sfr16AdbStr::~ArrayDataBase();      // 0x1424dc440
template<> SF_NOINLINE Sfr16AdbNsSet::~ArrayDataBase();    // 0x1424dc530
template<> SF_NOINLINE Sfr16AdbCtr::~ArrayDataBase();      // 0x1424dc5b0
template<> SF_NOINLINE Sfr16AdbFile::~ArrayDataBase();     // 0x1424dc6b0
template<> SF_NOINLINE Sfr16AdbExc::~ArrayDataBase();      // 0x1424dc800
template<> SF_NOINLINE Sfr16AdbPod::~ArrayDataBase();      // 0x1424dc3d0
}
bool FUN_142522a60(Scaleform::GFx::AS3::VM* vm, void* file);
void FUN_1424dcc30(void* self);
void FUN_1424dcdd0(void* self);
extern const void* DAT_14317b750[];     // VMAbcFile

// VMAbcFile's non-deleting teardown: the member cleanup sequence its scalar deleting dtor (0x1424e3eb0) inlines.
// Every member teardown is an out-of-line call in the exe.
#pragma inline_depth(0)
// @0x1424dfa30
extern "C" void FUN_1424dfa30(void* self)
{
    using namespace Scaleform;
    char* p = static_cast<char*>(self);
    *reinterpret_cast<const void* const**>(p) = DAT_14317b750;
    ::FUN_142522a60(*reinterpret_cast<GFx::AS3::VM**>(p + 0x20), self);
    reinterpret_cast<Sfr16AdbExc*>(p + 0xd0)->Sfr16AdbExc::~ArrayDataBase();
    reinterpret_cast<Sfr16AdbPod*>(p + 0xb8)->Sfr16AdbPod::~ArrayDataBase();
    reinterpret_cast<Sfr16AdbCtr*>(p + 0xa0)->Sfr16AdbCtr::~ArrayDataBase();
    FUN_1424dcc30(p + 0x98);
    FUN_1424dcdd0(p + 0x90);
    reinterpret_cast<Sfr16AdbFile*>(p + 0x78)->Sfr16AdbFile::~ArrayDataBase();
    reinterpret_cast<SfrCx18GlobalScriptSet*>(p + 0x70)->SfrCx18GlobalScriptSet::~HashSetBase();
    reinterpret_cast<Sfr16AdbStr*>(p + 0x58)->Sfr16AdbStr::~ArrayDataBase();
    reinterpret_cast<Sfr16AdbNsSet*>(p + 0x40)->Sfr16AdbNsSet::~ArrayDataBase();
    reinterpret_cast<SfrCx18GASRefSet*>(p + 0x38)->SfrCx18GASRefSet::~HashSetBase();
    reinterpret_cast<SfrCx18AbcNamespaceSet*>(p + 0x30)->Clear();
    reinterpret_cast<SfrCx18AbcNamespaceSet*>(p + 0x30)->SfrCx18AbcNamespaceSet::~HashSetBase();
    if (void* m = *reinterpret_cast<void**>(p + 0x28))
        reinterpret_cast<RefCountImpl*>(m)->Release();
    reinterpret_cast<GFx::AS3::GASRefCountBase*>(self)->GFx::AS3::GASRefCountBase::~GASRefCountBase();
}
#pragma inline_depth()


// Assigns a tagged AS3 reference and transfers the old/new reference counts.
// @0x1424e0860
Scaleform::UInt64* FUN_1424e0860(Scaleform::UInt64* self, Scaleform::UInt64 value)
{
    const Scaleform::UInt64 cur = *self;
    if (value != cur)
    {
        if (cur)
        {
            if (cur & 1)
                *self = cur - 1;
            else
            {
                auto* refs = reinterpret_cast<Scaleform::UInt32*>(cur + 0x10);
                if ((*refs & 0x3fffff) != 0)
                    --*refs, reinterpret_cast<const Scaleform::GFx::AS3::ASRefCountBaseType*>(cur)->ReleaseInternal();
            }
        }
        if (value)
        {
            auto* refs = reinterpret_cast<Scaleform::UInt32*>(value + 0x10);
            *refs = (*refs + 1U) & 0x8fbfffff;
        }
        *self = value;
    }
    return self;
}

// VMAbcFile::FunctionTraitsCache dtor (HashLH<UInt32, SPtr<InstanceTraits::Function> >): releases each cached
// traits reference, then frees the table.
// @0x1424dcc30
void FUN_1424dcc30(void* self)
{
    using namespace Scaleform::GFx::AS3;
    static_cast<Scaleform::HashLH<Scaleform::UInt32, SPtr<InstanceTraits::Function>,
        Scaleform::FixedSizeHash<Scaleform::UInt32>, StatMV_VM_VMAbcFile_Mem>*>(self)->~HashLH();
}

// Hash<UPInt, UPInt> dtor: clears a cached hash table and releases its backing block.
// @0x1424dcce0
void FUN_1424dcce0(void* self)
{
    static_cast<Scaleform::Hash<Scaleform::UPInt, Scaleform::UPInt>*>(self)->~Hash();
}

// HashLH<Ptr<Resource>, UPInt> dtor: releases each text-format font Resource key, then frees the table.
// @0x1424dcd40
__declspec(noinline) void FUN_1424dcd40(void* self)
{
    static_cast<Scaleform::HashLH<Scaleform::Ptr<Scaleform::GFx::Resource>, Scaleform::UPInt> *>(self)->~HashLH();
}

using Sfr16NamespaceHashKey = Scaleform::GFx::AS3::AbcMultinameHash<
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 340>::Key;
using Sfr16NamespaceMapNode = Scaleform::HashNode<Sfr16NamespaceHashKey,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>,
    Scaleform::FixedSizeHash<Sfr16NamespaceHashKey>>;
using Sfr16NamespaceMap = Scaleform::HashSetBase<Sfr16NamespaceMapNode,
    Sfr16NamespaceMapNode::NodeHashF, Sfr16NamespaceMapNode::NodeAltHashF,
    Scaleform::AllocatorLH<Sfr16NamespaceHashKey, 340>,
    Scaleform::HashsetCachedEntry<Sfr16NamespaceMapNode, Sfr16NamespaceMapNode::NodeHashF>>;
// VMAbcFile::ActivationTraitsCache dtor (HashLH<Abc::MbiInd, SPtr<InstanceTraits::Traits> >; MbiInd is a UInt32
// index): same body as FUN_1424dcc30. Not the AbcMultinameHash<SPtr<Namespace>> set destructor (0x1424dcf10).
// @0x1424dcdd0
void FUN_1424dcdd0(void* self)
{
    using namespace Scaleform::GFx::AS3;
    static_cast<Scaleform::HashLH<Scaleform::UInt32, SPtr<InstanceTraits::Traits>,
        Scaleform::FixedSizeHash<Scaleform::UInt32>, StatMV_VM_VMAbcFile_Mem>*>(self)->~HashLH();
}
// @0x1424e0f00
template Scaleform::UPInt Scaleform::FixedSizeHash<Sfr16NamespaceHashKey>::operator()(
    const Sfr16NamespaceHashKey&) const;

// `inline` under cl only: sfr_render_06d keeps the implicit operator= (MS2_SF_STROKESTYLE_IMPLICIT_ASSIGN) and cl emits
// it there as a COMDAT-any copy with the same bytes, so this one must be COMDAT-any too (no LNK2005 in the fullexe).
// clang-cl does not emit an unreferenced inline, so the hook DLL build keeps the plain definition.
#if defined(__clang__)
#define SFR16_STROKE_ASSIGN
#else
#define SFR16_STROKE_ASSIGN inline
#endif

namespace Scaleform { namespace Render {
// @0x1424e0cb0
SFR16_STROKE_ASSIGN StrokeStyleType& StrokeStyleType::operator=(const StrokeStyleType& other)
{
    Width = other.Width;
    Units = other.Units;
    Flags = other.Flags;
    Miter = other.Miter;
    Color = other.Color;
    pFill = other.pFill;
    pDashes = other.pDashes;
    return *this;
}
}} // namespace Scaleform::Render
// Calls the inline operator= above out of line (inline_depth 0), so cl emits its body in this unit. Nothing calls it.
#pragma inline_depth(0)
void MS2_Sfr16EmitStrokeAssign(Scaleform::Render::StrokeStyleType* dst, const Scaleform::Render::StrokeStyleType* src)
{
    *dst = *src;
}
#pragma inline_depth()

namespace Scaleform { namespace GFx { namespace AS3 {
// The ABC files are released last-loaded first, then the array and the GFx root-node base go.
// @0x1424de580
MovieDefRootNode::~MovieDefRootNode()
{
    for (SPInt i = (SPInt)AbcFiles.GetSize() - 1; i >= 0; --i)
        AbcFiles[i] = NULL;
}
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// Value::Assign(const ASString&) (0x1424ed9d0, out of line in sfr_as3_17). The exe's operator= below has it
// inlined, so its body is visible here too. sfr_as3_17 defines it inline SF_NOINLINE, so the two copies are COMDATs.
SF_FORCEINLINE void Value::Assign(const ASString& v)
{
    Release();
    if (v.GetNode() == v.GetNode()->GetManager()->GetNullStringNode())
    {
        value = (ASStringNode*)NULL;
        SetKind(kObject);
    }
    else
    {
        SetKind(kString);
        value = v.GetNode();
        AddRefString();
    }
}
}}} // namespace Scaleform::GFx::AS3

Scaleform::GFx::AS3::Value& (Scaleform::GFx::AS3::Value::* const pSfr16ValueStringAssign)(
    const Scaleform::GFx::ASString&) =
    static_cast<Scaleform::GFx::AS3::Value& (Scaleform::GFx::AS3::Value::*)(const Scaleform::GFx::ASString&)>(
        &Scaleform::GFx::AS3::Value::operator=);

using Sfr16DisplayObjectWeakArray = Scaleform::ArrayLH<
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>, 2, Scaleform::ArrayDefaultPolicy>;
// The display object map destructor (0x1424dcbb0) is the SfrCx18DisplayObjectSet instantiation above.

// Transfers the source pointer and owner flag, releasing an owned destination first.
// @0x1424e0340
Scaleform::AutoPtr<Sfr16DisplayObjectWeakArray>&
    (Scaleform::AutoPtr<Sfr16DisplayObjectWeakArray>::* const pSfr16AutoPtrAssign)(
        const Scaleform::AutoPtr<Sfr16DisplayObjectWeakArray>&) =
    static_cast<Scaleform::AutoPtr<Sfr16DisplayObjectWeakArray>&
        (Scaleform::AutoPtr<Sfr16DisplayObjectWeakArray>::*)(
            const Scaleform::AutoPtr<Sfr16DisplayObjectWeakArray>&)>(
        &Scaleform::AutoPtr<Sfr16DisplayObjectWeakArray>::operator=);

// MS2-PIN: ??_G?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@MEAAPEAXI@Z 0x1424e3750
// MS2-PIN: ?Add@XMLSupportImpl@AS3@GFx@Scaleform@@UEBA_NAEAVValue@234@AEAVObject@234@1@Z 0x1424e6990
// MS2-PIN: ??4?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@QEAAXAEBUNodeRef@01@@Z 0x1424e0480
// MS2-PIN: ??4?$SPtr@$$CBVNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x1424e0550
// MS2-PIN: ??_GClass@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2bb0
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@H$01@2@V?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x1424dcbb0
// MS2-PIN: ??_GLoadQueueEntry@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3150
// MS2-PIN: ??_GLoadQueueEntryMT_LoadMovie@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e31e0
// MS2-PIN: ??_GObject@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3580
// MS2-PIN: ??_GRTraits@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3690
// MS2-PIN: ??4?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@QEAAAEAU01@AEBU01@@Z 0x1424e0420
// MS2-PIN: ??4?$SPtr@VFunction@InstanceTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x1424e0630
// MS2-PIN: ??4?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x1424e06a0
// MS2-PIN: ??4?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x1424e0780
// MS2-PIN: ??4?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBV0123@@Z 0x1424e07f0
// MS2-PIN: ?SetPtr@?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@QEAAAEAV1234@PEAVGASRefCountBase@234@@Z 0x1424e0710
// MS2-PIN: ??1?$HashSetBase@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VParagraphFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@QEAA@XZ 0x1424dd300
// MS2-PIN: ??1?$HashSetBase@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@U51234@U?$AllocatorLH@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@$0EO@@4@V?$HashsetCachedEntry@V?$TextFormatPtrWrapper@VTextFormat@Text@Render@Scaleform@@@Text@Render@Scaleform@@UHashFunctor@1234@@4@@Scaleform@@QEAA@XZ 0x1424dd3b0
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorDH@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@$0BEJ@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$MultinameHash@PEAVTraits@ClassTraits@AS3@GFx@Scaleform@@$0BEJ@@AS3@GFx@Scaleform@@PEAVTraits@ClassTraits@345@UHashFunctor@12345@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x1424dcfc0
// MS2-PIN: ??1?$HashSetBase@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGASRefCountBase@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@QEAA@XZ 0x1424dd1a0
// MS2-PIN: ??1?$HashSetBase@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@V54@U?$AllocatorLH@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@V?$FixedSizeHash@V?$SPtr@VGlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@@4@@4@@Scaleform@@QEAA@XZ 0x1424dd250
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UDynAttrsKey@Object@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x1424dce80
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@345@V?$FixedSizeHash@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@@5@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@$0BFE@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@345@V?$FixedSizeHash@UKey@?$AbcMultinameHash@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@AS3@GFx@Scaleform@@@5@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x1424dcf10
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x1424dd110
// MS2-FUNCTIONAL ??_GLoadQueueEntry@AS3@GFx@Scaleform@@UEAAPEAXI@Z: generated wrapper runs the recovered destructor and same delete-flag free path; compiler separates the wrapper from cleanup.
// MS2-PIN: ??_GLoadQueueEntry@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3020
// MS2-PIN: ??4Value@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBVASString@23@@Z 0x1424e0d40
// MS2-PIN: ??4?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAAEAV01@AEBV01@@Z 0x1424e0340
// MS2-PIN: ?FUN_1424debc0@@YAXPEAX@Z 0x1424debc0
// MS2-PIN: ?FUN_1424deb40@@YAXPEAX@Z 0x1424deb40
// MS2-PIN: ?FUN_1424dec40@@YAXPEAX@Z 0x1424dec40
// MS2-PIN: ?FUN_1424decc0@@YAXPEAX@Z 0x1424decc0
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1c20 0x1424e1c20
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1c80 0x1424e1c80
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1ce0 0x1424e1ce0
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1d40 0x1424e1d40
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1da0 0x1424e1da0
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1e00 0x1424e1e00
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1e60 0x1424e1e60
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1ec0 0x1424e1ec0
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1f20 0x1424e1f20
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1f80 0x1424e1f80
// MS2-PIN: Sfr16ScalarDeletingDtor_1424e1fe0 0x1424e1fe0
// AvmBitmap / ShapeObject over the SDK MI class model (SF_AS3_SHAPEOBJECT_MODEL, as3_avm.h): the compiler
// installs the three vftables (0x14317c560 / c7d8 / c7e8 and 0x14317c210 / c488 / c498) and releases the two
// Ptr members, the AvmDisplayObj part and the DisplayObject base. The body only clears AvmObjOffset: the AS3
// part is a base here, not one DisplayObjectBase destroys.
// Both are `inline` under cl: sfr_as3_16z carries copies of them for its deleting destructors (the exe's one
// AS3_All SCU inlines them there), so these are COMDAT-any and do not clash with those (LNK2005).
// MS2_Sfr16EmitShapeDtors below keeps them emitted here. clang-cl ignores inline_depth: plain definitions there.
#if defined(__clang__)
#define SFR16_SHAPE_DTOR
#else
#define SFR16_SHAPE_DTOR inline
#endif
// @0x1424ddb00
SFR16_SHAPE_DTOR Scaleform::GFx::AS3::AvmBitmap::~AvmBitmap()
{
    AvmObjOffset = 0;
}

// @0x1424deeb0
SFR16_SHAPE_DTOR Scaleform::GFx::AS3::ShapeObject::~ShapeObject()
{
    AvmObjOffset = 0;
}
// Calls both destructors above out of line (inline_depth 0), so cl emits them in this unit. Nothing calls it.
#pragma inline_depth(0)
void MS2_Sfr16EmitShapeDtors(Scaleform::GFx::AS3::AvmBitmap* b, Scaleform::GFx::AS3::ShapeObject* s)
{
    b->Scaleform::GFx::AS3::AvmBitmap::~AvmBitmap();
    s->Scaleform::GFx::AS3::ShapeObject::~ShapeObject();
}
#pragma inline_depth()
//
//
//
//
//

// AvmMovieClip has no additional state; release the AvmSprite base.
// @0x1424ddcb0
Scaleform::GFx::AS3::AvmMovieClip::~AvmMovieClip()
{
}
//
//

//
// MS2-PIN: ??_7AvmMovieClip@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14313bcd8
// MS2-PIN: ??_7AvmMovieClip@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14313bdd0
// MS2-PIN: ??_7AvmMovieClip@AS3@GFx@Scaleform@@6BAvmDisplayObjContainer@123@@ 0x14313be88
// MS2-PIN: ??_7AvmMovieClip@AS3@GFx@Scaleform@@6BAvmSpriteBase@23@@ 0x14313bf48
// MS2-PIN: ??_7ASMovieRootBase@GFx@Scaleform@@6B@ 0x14317bde0
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7GASRefCountBase@AS3@GFx@Scaleform@@6B@ 0x14313f398
// MS2-PIN: ??_7Traits@AS3@GFx@Scaleform@@6B@ 0x14317b210
// MS2-PIN: ??_7Traits@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b300
// MS2-PIN: ??_7CTraits@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b3a0
// MS2-PIN: ??_7RTraits@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14317b428
// MS2-PIN: ??_7Object@AS3@GFx@Scaleform@@6B@ 0x14317b098
// MS2-PIN: ??_7Instance@AS3@GFx@Scaleform@@6B@ 0x14313f4d8
// MS2-PIN: ??_7Class@AS3@GFx@Scaleform@@6B@ 0x14317b140
// MS2-PIN: ??_7VM@AS3@GFx@Scaleform@@6B@ 0x14317b858
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7MovieDefRootNode@GFx@Scaleform@@6B@ 0x14317c9e0
// MS2-PIN: ??_7UDBase@Classes@AS3@GFx@Scaleform@@6B@ 0x14317f778
// MS2-PIN: ??_7MovieDefRootNode@AS3@GFx@Scaleform@@6B@ 0x14317d8c0
// MS2-PIN: ??_7LoadQueueEntry@GFx@Scaleform@@6B@ 0x14317c9d8
// MS2-PIN: ??_7ASVM@AS3@GFx@Scaleform@@6B@ 0x14317d8b0
// MS2-PIN: ??_7LoadQueueEntry@AS3@GFx@Scaleform@@6B@ 0x14317d888
// MS2-PIN: ??_7LoadQueueEntryMT_LoadMovie@AS3@GFx@Scaleform@@6B@ 0x14317d890
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
//
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317de60
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317e228
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317e330
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B@ 0x14317e3e8
// MS2-PIN: ??_7ShapeObject@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317c210
// MS2-PIN: ??_7ShapeObject@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317c488
// MS2-PIN: ??_7ShapeObject@AS3@GFx@Scaleform@@6B@ 0x14317c498
// MS2-PIN: ??_7AvmBitmap@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317c560
// MS2-PIN: ??_7AvmBitmap@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317c7d8
// MS2-PIN: ??_7AvmBitmap@AS3@GFx@Scaleform@@6B@ 0x14317c7e8
// Trap-stub pass (sfr21): vftable slots and adjustor thunks the full exe names but nothing defined.
namespace Scaleform { namespace GFx { namespace AS3 {

void* DeleteAs3_1424e2610(void* p, unsigned flags);
void* DeleteAs3_1424e26d0(void* p, unsigned flags);
void* DeleteAs3_1424e2a10(void* p, unsigned flags);
void* DeleteAs3_1424e2ac0(void* p, unsigned flags);
void* DeleteAs3_1424e33f0(void* p, unsigned flags);
void* DeleteAs3_1424e3890(void* p, unsigned flags);
// @0x1424e4290
void Object::AS3Constructor(unsigned, const Value*) {}   // the base does nothing; the traits call the object's own
// @0x1424e42a0
void InstanceTraits::Traits::AS3Constructor(const AS3::Traits&, const Value& _this, unsigned argc, const Value* argv) const
{
    _this.GetObject()->AS3Constructor(argc, argv);
}

// @0x1424e5470
bool AvmDisplayObjContainer::ActsAsButton() const { return false; }

// No AS3 object yet: a button; otherwise whether it has a mouse/button listener.
// AvmDisplayObj::HasAS3Obj (SDK header inline).
static __forceinline bool Sfr16HasAS3Obj(const AvmDisplayObj* p) { return p->pAS3RawPtr || p->pAS3CollectiblePtr.pObject; }

// @0x1424e5480
bool AvmInteractiveObj::ActsAsButton() const
{
    if (Sfr16HasAS3Obj(this))
        return GetAS3Obj()->HasButtonHandlers();
    return true;
}

// @0x1424e54b0
bool AvmSprite::ActsAsButton() const
{
    if (SprFlags & Flag_ButtonMode)
        return true;
    if (!Sfr16HasAS3Obj(this))
        return false;
    return AvmInteractiveObj::ActsAsButton();
}

}}} // namespace Scaleform::GFx::AS3

// Constant vftable slots and their adjustor thunks.
// @0x1424e5460
bool FUN_1424e5460(Scaleform::UPInt) { return true; }
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e5464
bool FUN_1424e5464(Scaleform::UPInt self) { return FUN_1424e5460(self - 0x10); }
// MS2-FUNCTIONAL: the exe's slot is `xor al, al`
// @0x1424e54f0
bool FUN_1424e54f0(Scaleform::UPInt) { return false; }
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e54f4
bool FUN_1424e54f4(Scaleform::UPInt self) { return FUN_1424e54f0(self - 0x10); }

// Scalar-deleting-destructor adjustor thunks into sfr_as3_16z.
#define SFR21_DTHUNK(name, off, target) \
    void* name(Scaleform::UPInt self, unsigned flags) { return Scaleform::GFx::AS3::target(reinterpret_cast<void*>(self - off), flags); }
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1ab0
SFR21_DTHUNK(FUN_1424e1ab0, 0x30, DeleteAs3_1424e26d0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1abc
SFR21_DTHUNK(FUN_1424e1abc, 0x40, DeleteAs3_1424e26d0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1b40
SFR21_DTHUNK(FUN_1424e1b40, 0x30, DeleteAs3_1424e2a10)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1b4c
SFR21_DTHUNK(FUN_1424e1b4c, 0x40, DeleteAs3_1424e2a10)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1b58
SFR21_DTHUNK(FUN_1424e1b58, 0x30, DeleteAs3_1424e2ac0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1b64
SFR21_DTHUNK(FUN_1424e1b64, 0x40, DeleteAs3_1424e2ac0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1b7c
SFR21_DTHUNK(FUN_1424e1b7c, 0x28, DeleteAs3_1424e33f0)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1b88
SFR21_DTHUNK(FUN_1424e1b88, 0x38, DeleteAs3_1424e33f0)
#undef SFR21_DTHUNK
// MS2-PIN: ??_GASMovieRootBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2210
// MS2-PIN: ??_GAvmLoader@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e28e0
// MS2-PIN: ??_GMovieDefRootNode@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3290
// MS2-PIN: ??_GMovieDefRootNode@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3380
// MS2-PIN: ??_GVM@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3e50
// MS2-PIN: ??_7Stage@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317d220
// MS2-PIN: ??_7Stage@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317d5f0
// MS2-PIN: ??_EAvmBitmap@AS3@GFx@Scaleform@@WBI@EAAPEAXI@Z 0x1424e1a98
// MS2-PIN: ??_EAvmBitmap@AS3@GFx@Scaleform@@WJA@EAAPEAXI@Z 0x1424e1aa4
// MS2-PIN: ??_EShapeObject@AS3@GFx@Scaleform@@WBI@EAAPEAXI@Z 0x1424e1b94
// MS2-PIN: ??_EShapeObject@AS3@GFx@Scaleform@@WJA@EAAPEAXI@Z 0x1424e1ba0
