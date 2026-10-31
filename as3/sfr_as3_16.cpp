// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 virtual machine core. Our own
// source, written from the exe.
// MS2-UNIT: sfr_as3_16
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424dc870-0x1424ddb00 .text$mn
// MS2-RANGE: 0x1424ddb00-0x1424ddb74 .text$mn
// MS2-RANGE: 0x1424ddb74-0x1424ddb80 .text$mn
// MS2-RANGE: 0x1424ddbee-0x1424ddcb0 .text$mn
// MS2-RANGE: 0x1424ddcb0-0x1424ddce0 .text$mn
// MS2-RANGE: 0x1424ddd4f-0x1424de0e0 .text$mn
// MS2-RANGE: 0x1424de0e0-0x1424e0a70 .text$mn
// MS2-RANGE: 0x1424e0b40-0x1424e2040 .text$mn
// MS2-RANGE: 0x1424e2210-0x1424e2290 .text$mn
// MS2-RANGE: 0x1424e2330-0x1424e2390 .text$mn
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
// MS2-RANGE: 0x1424e3e50-0x1424e3eb0 .text$mn
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
// MS2-FUNCTIONAL 0x1424e0e50: builds a temporary for each side and concatenates them, releasing both temporary strings afterward.
// @0x1424e0e50
String operator+(const char* left, const GFx::ASString& right)
{
    return String(left) + String(right.ToCStr(), right.GetSize());
}
}

namespace Scaleform { namespace GFx {
// MS2-FUNCTIONAL 0x1424dd4d0: releases pASSupport and then runs the RefCountImplCore base destructor, matching the exe's order.
// @0x1424dd4d0
ASMovieRootBase::~ASMovieRootBase() = default;
}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS3 {
// MS2-FUNCTIONAL 0x1424dd500: releases the ASVM's owned builtin-class references, then delegates VM cleanup to its base.
// @0x1424dd500
ASVM::~ASVM() = default;
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
extern const void* DAT_14317b648[];     // the empty interface base (ASMovieRootBase +0x28, Tracer)
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
    *reinterpret_cast<const void***>(bytes + 0x28) = Scaleform::GFx::AS3::DAT_14317b648;
    reinterpret_cast<Scaleform::GFx::ASMovieRootBase*>(self)->Scaleform::GFx::ASMovieRootBase::~ASMovieRootBase();
}

extern "C" void FUN_142530d50(Scaleform::UPInt self);
extern "C" void FUN_1424dfbf0(void* self);
void FUN_1424dc8e0(void* self);
void FUN_1424de240(long long* state);
extern "C" Scaleform::SPInt FUN_1424e1040(void* self, const Scaleform::UInt32* value);
namespace Scaleform { namespace GFx { namespace AS3 {
void* DeleteAs3_1424e3eb0(void* self, unsigned flags);
void* DeleteAs3_1424e3890(void* self, unsigned flags);
void* DeleteAs3_1424e4190(void* self, unsigned flags);
}}}

// VMAbcFile's non-deleting teardown follows the same member cleanup sequence as its scalar deleting dtor.
// MS2-FUNCTIONAL 0x1424dfa30: delegates to that recovered sequence with flags 0 so the object storage stays live.
// @0x1424dfa30
extern "C" void FUN_1424dfa30(void* self)
{
    Scaleform::GFx::AS3::DeleteAs3_1424e3eb0(self, 0);
}

// The stage display object: its members release in reverse order, then DisplayObjContainer's dtor.
// @0x1424defe0
Scaleform::GFx::AS3::Stage::~Stage() {}

// MS2-FUNCTIONAL 0x1424e0290: reuses the XMLSupportImpl member/base teardown with the free flag clear.
// @0x1424e0290
extern "C" void FUN_1424e0290(void* self)
{
    Scaleform::GFx::AS3::DeleteAs3_1424e4190(self, 0);
}


// A copied frame gives back what its constructor reserved: the operand stack reservation (an emptied page with a
// predecessor goes back to the reserved list and the values still on it move down onto the predecessor), the
// registers of the method body, and the scope stack. The operand values stay on the stack for the caller.
// MS2-FUNCTIONAL 0x1424dde10: OpStack/RegisterFile ReleaseReserved written out (exe: both inline); same steps.
// @0x1424dde10
Scaleform::GFx::AS3::CallFrame::~CallFrame()
{
    if (pRegisterFile && pScopeStack && ACopy)
    {
        using Scaleform::GFx::AS3::Value;
        using Scaleform::GFx::AS3::ValueStack;
        const Scaleform::GFx::AS3::Abc::MethodBodyInfo& body =
            *pFile->GetAbcFile().MethodBodies.Info[static_cast<Scaleform::UPInt>(MBIIndex)];
        ValueStack& stack = ValueStack::Of(pFile->GetVM());
        ValueStack::Page* page = stack.pCurrentPage;
        --page->ReservationNum;
        stack.ReservedNum = PrevReservedNum;
        if (page->ReservationNum == 0 && page->pPrev)
        {
            Value* const top = stack.pCurrent;
            ValueStack::Page* prev = page->pPrev;
            stack.pCurrentPage = prev;
            prev->pNext = NULL;
            stack.pCurrent = prev->pCurrent;
            stack.pStack = prev->pFirst;
            page->pNext = stack.pReserved;
            page->pFirst = NULL;
            stack.pReserved = page;
            for (Value* v = page->Values; v <= top; ++v)
            {
                ++stack.pCurrent;
                memcpy(static_cast<void*>(stack.pCurrent), v, sizeof(Value));
                *reinterpret_cast<Scaleform::UInt32*>(v) = 0;   // moved out: the old slot is undefined
            }
        }
        else
            stack.pStack = PrevFirstStackPos;
        static_cast<ValueRegisterFile*>(pRegisterFile)->ReleaseReserved(static_cast<Scaleform::UInt16>(body.local_reg_count));
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
    *reinterpret_cast<const void***>(bytes) = Scaleform::GFx::AS3::DAT_14317b648;
}

namespace {
using Sfr16U64 = unsigned long long;

Sfr16U64 Sfr16Hash32(const unsigned char* p)
{
    return (Sfr16U64)p[0] + (Sfr16U64)(0ULL - 0x476f700348970ffbULL) +
        (Sfr16U64)p[1] * 0x1003fULL + (Sfr16U64)p[2] * 0x1003fULL * 0x1003fULL +
        (Sfr16U64)p[3] * 0x1003fULL * 0x1003fULL * 0x1003fULL;
}

Sfr16U64 Sfr16Hash64(const unsigned char* p)
{
    return (Sfr16U64)p[0] + (Sfr16U64)(0ULL - 0x514d9afbc3e934fbULL) +
        (Sfr16U64)p[1] * 0x1003fULL + (Sfr16U64)p[2] * 0x1003fULL * 0x1003fULL +
        (Sfr16U64)p[3] * 0x1003fULL * 0x1003fULL * 0x1003fULL +
        (Sfr16U64)p[4] * 0xfc5d1543ec5f01ULL + (Sfr16U64)p[5] * (0ULL - 0x64cfd3d7e9d39ec1ULL) +
        (Sfr16U64)p[6] * 0x5d02f409d62aee81ULL + (Sfr16U64)p[7] * (0ULL - 0x283c1b695cee4e41ULL);
}

Sfr16U64 Sfr16HashStringNode(const unsigned char* p)
{
    static const Sfr16U64 weights[40] = {
        1ULL, 0x1003fULL, 0x1003fULL * 0x1003fULL, 0x1003fULL * 0x1003fULL * 0x1003fULL,
        0xfc5d1543ec5f01ULL, 0ULL - 0x64cfd3d7e9d39ec1ULL, 0x5d02f409d62aee81ULL,
        0ULL - 0x283c1b695cee4e41ULL, 0ULL - 0x2341bdc2ce641ffULL, 0x5950f7eab156c23fULL,
        0ULL - 0xd284be79967327fULL, 0x772db89a0d1b92bfULL, 0xcda7b04cc881d01ULL,
        0ULL - 0x5b36ed498d7fdcc1ULL, 0ULL - 0x5fcdf299af38537fULL, 0x79b79cf58da473bfULL,
        0ULL - 0x6edad1edb0c883ffULL, 0ULL - 0x19c75a4705577bc1ULL, 0x4da9c32e33b78b81ULL,
        0ULL - 0x200ac3e9ba53ab41ULL, 0x59700f277a27db01ULL, 0x11bb34deeacfe53fULL,
        0ULL - 0x6e0f12545197957fULL, 0ULL - 0x2809d457a9ccca41ULL, 0x513d14a06c593a01ULL,
        0x12a87fd3e3f6463fULL, 0x174b591b5fda4981ULL, 0x14a64d96e03916bfULL,
        0x6283f85a44cb9901ULL, 0x36d46302871ba73fULL, 0ULL - 0x1eb91b4518f2d77fULL,
        0x552d310c04bdf7bfULL, 0x272b16b3227ef801ULL, 0ULL - 0x45b2476b8abff7c1ULL,
        0ULL - 0x6e4b1e371cfef87fULL, 0ULL - 0x42b38c8f1b3e2741ULL,
        0x9414d8a24735701ULL, 0ULL - 0x6b63c68db09c96c1ULL,
        0ULL - 0x341b8d7b0d4a197fULL, 0ULL - 0x6042de925ebb4641ULL
    };
    Sfr16U64 hash = 0ULL - 0x6127841818c65cfbULL;
    for (unsigned i = 0; i < 40; ++i)
        hash += (Sfr16U64)p[i] * weights[i];
    return hash;
}
} // namespace

// Value hash used by the AS3 hash-set adapters. The tag and payload cases follow the exe's switch.
// MS2-FUNCTIONAL 0x1424e1040: hash polynomial is evaluated by loops rather than the exe's unrolled arithmetic.
// @0x1424e1040
extern "C" Scaleform::SPInt FUN_1424e1040(void*, const Scaleform::UInt32* words)
{
    const auto* bytes = reinterpret_cast<const unsigned char*>(words);
    const Scaleform::UInt32 tag = words[0] & 0x1f;
    const auto* payload = bytes + 0x10;
    Sfr16U64 hash = 0;
    switch (tag)
    {
    case 1:
        hash = payload[0] != 0;
        break;
    case 2:
    case 3:
        hash = Sfr16Hash32(payload);
        break;
    case 4:
        hash = Sfr16Hash64(payload);
        break;
    case 5:
        hash = Sfr16HashStringNode(*reinterpret_cast<const unsigned char* const*>(payload));
        break;
    case 7:
    case 0x11:
        hash = Sfr16Hash32(payload) ^ Sfr16Hash64(payload + 8);
        break;
    case 0x0b:
    case 0x0c:
    case 0x0d:
    case 0x0e:
    case 0x0f:
        if (*reinterpret_cast<const Sfr16U64*>(payload) != 0)
            hash = Sfr16Hash64(payload);
        break;
    case 0x10:
    {
        const auto* node = *reinterpret_cast<const unsigned char* const*>(payload);
        hash = Sfr16HashStringNode(node) ^ Sfr16Hash64(payload + 8);
        break;
    }
    default:
        if (tag == 0x0a)
        {
            auto* object = *reinterpret_cast<void* const*>(payload);
            if (object)
                hash = *reinterpret_cast<const Scaleform::UInt32*>(static_cast<const unsigned char*>(object) + 0x1c) & 0xffffff;
        }
        break;
    }
    return static_cast<Scaleform::SPInt>(hash + tag);
}

// ValueRegisterFile teardown: free the reserved pages, release the register values, then free the current page.
// The exe's UInt16 index steps by 0xffff (0x1424dfba0 add si,r14w with r14d = 0xffff), so the loop ends after
// register 0: only that one is released.
// MS2-FUNCTIONAL 0x1424dfaf0: uses the Value destructor and the VM heap's free slot; iteration lowering differs.
// @0x1424dfaf0
extern "C" void FUN_1424dfaf0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
    while (void* page = *reinterpret_cast<void**>(bytes + 0x18))
    {
        *reinterpret_cast<void**>(bytes + 0x18) = *reinterpret_cast<void**>(static_cast<unsigned char*>(page) + 0x10);
        reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(Scaleform::Memory::pGlobalHeap, page);
    }

    auto count = *reinterpret_cast<const Scaleform::UInt16*>(bytes);
    auto* values = *reinterpret_cast<Scaleform::GFx::AS3::Value**>(bytes + 8);
    if (count != 0)
        values[0].~Value();

    void* page = *reinterpret_cast<void**>(bytes + 0x10);
    if (page)
        reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(Scaleform::Memory::pGlobalHeap, page);
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
    FUN_142530d50(reinterpret_cast<Scaleform::UPInt>(this));
    // The exe's GlobalObjects is ArrayLH<GlobalObject*>: its data is freed without releasing the (unowned) elements.
    // as3_vm.h still declares SPtr elements (shared with the as3_17/18 lanes), so empty it here; the member dtor then only frees Data.
    reinterpret_cast<Scaleform::UPInt*>(&GlobalObjects)[1] = 0; // Size (+0x1b0)
}
}}} // namespace Scaleform::GFx::AS3

// ASRefCountCollector::ForceCollect inlined through the movie root's collector pointer.
// MS2-FUNCTIONAL 0x1424de240: same stores; the exe keeps the zero in esi across Collect (FrameCnt = 0 from it) and tail-calls the Stats observer release.
// @0x1424de240
void FUN_1424de240(long long* state)
{
    using namespace Scaleform::GFx::AS3;
    auto* gc = reinterpret_cast<ASRefCountCollector*>(*state);
    if (gc->SuspendCnt > 0)
        return;

    const unsigned roots = static_cast<unsigned>(gc->GetRootsCount());
    ASRefCountCollector::Stats stats = {};
    gc->Collect(&stats);
    gc->FrameCnt = 0;
    gc->LastRootCount = roots;
    gc->PeakRootCount = Scaleform::Alg::Max(gc->PeakRootCount, roots);
    if (gc->Flags & ASRefCountCollector::Flags_RequireMoreCollect)
        gc->CollectionScheduledFlags = 1;
}

// MS2-FUNCTIONAL 0x1424de460: applies the same root range reset to the nested MovieRoot and releases the owning reference.
// @0x1424de460
void FUN_1424de460(long long* owner)
{
    using namespace Scaleform::GFx::AS3;
    auto* gc = *reinterpret_cast<ASRefCountCollector**>(*owner + 0x20);
    if (gc->SuspendCnt == 0)
    {
        const unsigned roots = static_cast<unsigned>(gc->GetRootsCount());
        ASRefCountCollector::Stats stats = {};
        gc->Collect(&stats);
        gc->FrameCnt = 0;
        gc->LastRootCount = roots;
        gc->PeakRootCount = Scaleform::Alg::Max(gc->PeakRootCount, roots);
        if (gc->Flags & ASRefCountCollector::Flags_RequireMoreCollect)
            gc->CollectionScheduledFlags = 1;
    }
    if (*owner != 0)
        reinterpret_cast<Scaleform::RefCountImpl*>(*owner)->Release();
}

// MS2-FUNCTIONAL 0x1424e0940: copies scalar state, retains the interned name and namespace, and assigns the embedded AS3 Value.
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
    *reinterpret_cast<unsigned long long*>(dst + 0x60) = *reinterpret_cast<const unsigned long long*>(src + 0x60);
    *reinterpret_cast<unsigned short*>(dst + 0x68) = *reinterpret_cast<const unsigned short*>(src + 0x68);

    using NamespacePtr = Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>;
    *reinterpret_cast<NamespacePtr*>(dst + 0x58) = *reinterpret_cast<const NamespacePtr*>(src + 0x58);

    auto* oldName = *reinterpret_cast<Scaleform::GFx::ASStringNode**>(dst + 0x70);
    if (oldName)
    {
        const auto raw = reinterpret_cast<Scaleform::UPInt>(oldName);
        if ((raw & 1) == 0)
        {
            if (--oldName->RefCount == 0)
                oldName->ReleaseNode();
        }
        else
            *reinterpret_cast<Scaleform::UPInt*>(dst + 0x70) = raw - 1;
    }

    auto* newName = *reinterpret_cast<Scaleform::GFx::ASStringNode* const*>(src + 0x70);
    if (newName)
        ++newName->RefCount;
    *reinterpret_cast<Scaleform::GFx::ASStringNode**>(dst + 0x70) = newName;
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

extern "C" void FUN_142521f00(void*);
extern void FUN_142626160(void*);
extern void FUN_14257eb30(void*);
namespace Scaleform {
// out of line in the exe (0x14241e430, sfr_as3_04)
typedef ArrayDataDH<GFx::AS3::Value, AllocatorDH<GFx::AS3::Value, 2>, ArrayDefaultPolicy> Sfr16ValueDataDH;
template<> SF_NOINLINE void ArrayBase<Sfr16ValueDataDH>::PushBack(const GFx::AS3::Value& val);
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {
    // The executable keeps ModifyOptimizedPlayList out of line at 0x142517e70; its body is recovered in sfr_as3_18.
    void Sfr34_ModifyOptimizedPlayList(InteractiveObject* p);

// ==== slots ==========================================================================================================

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
        FUN_142626160(static_cast<char*>(node) + 0x40);
    FUN_14257eb30(node);
    if (flags & 1)
        ::operator delete(node, 0x90);
    return node;
}

// MS2-FUNCTIONAL: the exe calls the SPtr<Namespace>/SPtr<VMAbcFile> assignments out of line (0x1424e0550,
// 0x1424e08d0) and inlines the SPtr<Traits> one; ours inlines all three.
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

// MS2-FUNCTIONAL: the exe inlines the ArrayLH PushBack/resize path in full (unity TU inlining budget); ours
// calls it.
// @0x1424e63b0
AbsoluteIndex SlotContainerType::Add(const ASString& k, const SlotInfo& v)
{
    const UPInt ind = VArray.GetSize();

    VArray.PushBack(Pair(v, Ptr<ASStringNode>(k.GetNode())));
    ++Size;

    ASStringNode* node = k.GetNode();
    SetType::Iterator it = KVHashSet.Find(node);
    if (it.IsEnd())
    {
        KVHashSet.Add(node, ind);
        VArray[ind].Prev = -1;
    }
    else
    {
        VArray[ind].Prev = it->Second;
        it->Second = ind;
    }

    return AbsoluteIndex(ind);
}

// MS2-FUNCTIONAL: the exe inlines the ArrayLH PushBack/resize path in full (unity TU inlining budget); ours
// calls it.
// @0x1424e6670
AbsoluteIndex Slots::Add(const ASString& k, const SlotInfo& v)
{
    const UPInt ind = VArray.GetSize();

    VArray.PushBack(Pair(v, Ptr<ASStringNode>(k.GetNode())));

    SetType::Iterator it = Set.Find(Ptr<ASStringNode>(k.GetNode()));
    if (it.IsEnd())
    {
        Set.Add(Ptr<ASStringNode>(k.GetNode()), static_cast<UInt32>(FirstOwnSlotNum + ind));
        VArray[ind].Prev = -1;
    }
    else
    {
        VArray[ind].Prev = it->Second;
        it->Second = static_cast<UInt32>(FirstOwnSlotNum + ind);
    }

    return AbsoluteIndex(FirstOwnSlotNum + ind);
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
    // @0x1424df350
    UDBase::~UDBase()
    {
        // The traits pointer carries a tag in bit 0; the Class base is destroyed implicitly after this body.
        reinterpret_cast<const Traits*>(reinterpret_cast<UPInt>(pTraits.GetPtr()) & ~UPInt(1))->DestructTail(*this);
    }
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

// MS2-FUNCTIONAL: same calls as the exe; cl reloads wp after NotifyObjectDied and keys Remove from the Get key's slot.
// @0x1424de190
GASRefCountBase::~GASRefCountBase()
{
    if (HasWeakRef())
    {
        Collector* rcc = GetCollector();
        WeakProxy* wp = NULL;
        if (Sfr16WProxyGet(reinterpret_cast<Sfr16WProxyHash&>(rcc->WProxyHash), this, &wp) && wp)
        {
            wp->NotifyObjectDied();
            wp->Release();
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

// MS2-FUNCTIONAL: inlining differs: the exe inlines the InitScope ArrayDH dtor and calls AutoPtr<VTable>::Reset
// out of line (0x142524290); cl does the opposite.
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
AbsoluteIndex VTable::AddMethod(const Value& m, SlotInfo::BindingType dt, const ASString& name)
{
    UPInt ind = 0;

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

// MS2-FUNCTIONAL: exe inlines IsXMLListObject(Object*) and the same-kind XML/QName checks
// @0x1424e46f0
CheckResult AbstractEqual(bool& result, const Value& l, const Value& r)
{
    const Value::KindType lk = l.GetKind();

    if (IsXMLListObject(l))
        return GetXMLSupportOf(l).EqualsXMLList(result, *reinterpret_cast<Instances::fl::XMLList*>(l.GetObject()), r);

    const Value::KindType rk = r.GetKind();

    if (IsXMLListObject(r))
        return GetXMLSupportOf(r).EqualsXMLList(result, *reinterpret_cast<Instances::fl::XMLList*>(r.GetObject()), l);

    if (lk == rk)
    {
        switch (lk)
        {
        case Value::kUndefined:
            result = true;
            break;
        case Value::kBoolean:
            result = (l.AsBool() && r.AsBool()) || (!l.AsBool() && !r.AsBool());
            break;
        case Value::kInt:
        case Value::kUInt:
            result = l.AsInt() == r.AsInt();
            break;
        case Value::kNumber:
            if (l.IsNaN() || r.IsNaN())
                result = false;
            else
                result = l.AsNumber() == r.AsNumber();
            break;
        case Value::kThunk:
        case Value::kString:
            result = l.GetStringNode() == r.GetStringNode();
            break;
        case Value::kNamespace:
        {
            const Instances::Namespace* lns = l.GetNamespace();
            const Instances::Namespace* rns = r.GetNamespace();
            result = lns && rns && lns->GetUri() == rns->GetUri() && lns->GetKind() == rns->GetKind();
            break;
        }
        case Value::kVTableInd:
            result = l.GetVTableInd() == r.GetVTableInd() && &l.GetTraits() == &r.GetTraits();
            break;
        case Value::kThunkClosure:
            result = l.GetClosure() == r.GetClosure() && &l.AsThunk() == &r.AsThunk();
            break;
        case Value::kVTableIndClosure:
            result = l.GetClosure() == r.GetClosure() && l.GetVTableInd() == r.GetVTableInd();
            break;
        default:
            result = l.GetObject() == r.GetObject();
            if (!result && l.IsObject())
            {
                if (IsXMLObject(l) && IsXMLObject(r))
                    return GetXMLSupportOf(l).EqualsXML(result, *reinterpret_cast<Instances::fl::XML*>(l.GetObject()),
                                                        *reinterpret_cast<Instances::fl::XML*>(r.GetObject()));
                if (IsQNameObject(l) && IsQNameObject(r))
                    return GetXMLSupportOf(l).EqualsQName(result, *reinterpret_cast<Instances::fl::QName*>(l.GetObject()),
                                                          *reinterpret_cast<Instances::fl::QName*>(r.GetObject()));
            }
            break;
        }
        return true;
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
    if (lk == Value::kUndefined && r.IsObject())
    {
        result = r.IsNull();
        return true;
    }
    if (l.IsObject() && rk == Value::kUndefined)
    {
        result = l.IsNull();
        return true;
    }

    // Number/String == Object: the object's primitive value
    if ((lk == Value::kString || lk == Value::kNumber) && r.IsObject())
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
    if (l.IsObject() && (rk == Value::kString || rk == Value::kNumber))
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
    if (lk == Value::kThunk || lk == Value::kMethodInd || lk == Value::kThunkClosure || lk == Value::kVTableIndClosure ||
        rk == Value::kThunk || rk == Value::kMethodInd || rk == Value::kThunkClosure || rk == Value::kVTableIndClosure)
    {
        result = false;
        return true;
    }

    // Boolean/int/uint == anything: compare as Number
    if (lk == Value::kNumber)
    {
        if (rk == Value::kNumber)
            return true;
        Value::Number n;
        if (!r.Convert2NumberInline(n))
            return false;
        Value num(n);
        return AbstractEqual(result, l, num);
    }
    Value::Number n;
    if (!l.Convert2NumberInline(n))
        return false;
    Value num(n);
    return AbstractEqual(result, num, r);
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
        return SlotInfo::BT_GetSet;
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

// MS2-FUNCTIONAL: our TU inlines VTable::AddMethod (0x1424e8ed0, defined below), which the exe calls; the get/set
// merge also rewrites the unchanged ValueInd there.
// @0x1424e5510
void Traits::Add2VT(SlotInfo& si, const Value& v, SlotInfo::BindingType bt)
{
    VTable& vt = GetVT();

    si.CppBinding = 1;
    const AbsoluteIndex ind(si.ValueInd);
    if (ind.IsValid())
    {
        const SlotInfo::BindingType cur_bt = static_cast<SlotInfo::BindingType>(si.BindType);
        // a plain method is not replaced by an accessor
        if (cur_bt == SlotInfo::BT_Code && bt != SlotInfo::BT_Code)
            return;
        vt.SetMethod(ind, v, bt, ASString(si.Name.GetPtr()));

        const SlotInfo::BindingType new_bt = GetNewBT(cur_bt, bt);
        if (new_bt != cur_bt)
            si.Bind(new_bt, ind);
    }
    else
        si.Bind(bt, vt.AddMethod(v, bt, ASString(si.Name.GetPtr())));
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
// build differently (it also skips a redundant 5-bit mask of the attributes).
// @0x1424e9670
AbsoluteIndex Traits::AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, VMAbcFile& file,
                              const Abc::TraitInfo& ti, bool const_)
{
    return Add(name, SlotInfo(ns, file, ti, (const_ ? SlotInfo::aReadOnly : SlotInfo::aNone) | SlotInfo::aDontEnum,
                              name.GetNode()));
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also skips a redundant 5-bit mask of the attributes).
// @0x1424e9740
void Traits::AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, const ClassTraits::Traits* tr,
                     SlotInfo::BindingType dt, AbsoluteIndex offset, bool const_)
{
    const AbsoluteIndex ind = Add(name, SlotInfo(ns, tr, (const_ ? SlotInfo::aReadOnly : SlotInfo::aNone) |
                                                             SlotInfo::aDontEnum, name.GetNode()));
    GetOwnSlotInfo(ind).Bind(dt, offset);
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also skips a redundant 5-bit mask of the attributes).
// @0x1424e9830
void Traits::AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, SlotInfo::BindingType dt,
                     AbsoluteIndex offset, bool const_)
{
    const AbsoluteIndex ind = Add(name, SlotInfo(ns, NULL, (const_ ? SlotInfo::aReadOnly : SlotInfo::aNone) |
                                                             SlotInfo::aDontEnum, name.GetNode()));
    GetOwnSlotInfo(ind).Bind(dt, offset);
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also skips a redundant 5-bit mask of the attributes).
// @0x1424e9910
void Traits::AddSlot(const MemberInfo& mi)
{
    VM& vm = GetVM();
    const int attr = SlotInfo::aDontEnum | SlotInfo::aCppBinding | (mi.Const ? SlotInfo::aReadOnly : SlotInfo::aNone);
    ASString name = vm.GetStringManager().CreateConstString(mi.Name);

    const AbsoluteIndex ind =
        Add(name, SlotInfo(Pickable<const Instances::Namespace>(vm.PublicNamespace.GetPtr(), PickValue), NULL, attr,
                           name.GetNode()));
    GetOwnSlotInfo(ind).Bind(static_cast<SlotInfo::BindingType>(mi.BT), AbsoluteIndex(mi.Offset));
}

// MS2-FUNCTIONAL: same operations; the exe allocates registers and schedules the inlined SlotInfo bit-field
// build differently (it also skips a redundant 5-bit mask of the attributes).
// @0x1424e9a50
void Traits::AddSlotCPP(const ASString& name, Pickable<const Instances::Namespace> ns, const ClassTraits::Traits* tr,
                        SlotInfo::BindingType dt, AbsoluteIndex offset, bool const_)
{
    const AbsoluteIndex ind = Add(name, SlotInfo(ns, tr, (const_ ? SlotInfo::aReadOnly : SlotInfo::aNone) |
                                                             SlotInfo::aDontEnum | SlotInfo::aCppBinding,
                                                 name.GetNode()));
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

// MS2-FUNCTIONAL 0x1424dda00: clears queued actions, releases each recycled ActionEntry's references, then frees the same nodes.
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
    , CharSwitched(false)
    , BytesLoaded(0)
    , FirstFrameLoaded(false)
{
    bool stripped = false;
    if (InteractiveObject* pmain = pMovieImpl->pMainMovie)
        stripped = (pmain->GetResourceMovieDef()->GetSWFFlags() & 0x10) != 0; // MovieInfo::SWF_Stripped
    pPreloadTask = *SF_NEW MoviePreloadTask(pMovieImpl, pqueueEntry->URL, stripped, pqueueEntry->QuietOpen);
    Ptr<TaskManager> ptm = *static_cast<TaskManager*>(pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager));
    ptm->AddTask(pPreloadTask);

    // A newer load of the same Loader / URLLoader replaces the pending ones.
    LoadQueueEntry* pentry = static_cast<LoadQueueEntry*>(pQueueEntry);
    for (LoadQueueEntryMT* p = pmovieImpl->pLoadQueueMTHead; p; p = p->GetNext())
    {
        LoadQueueEntry* pother = static_cast<LoadQueueEntry*>(p->GetQueueEntry());
        if ((pother->mLoader && pother->mLoader == pentry->mLoader) ||
            (pother->mURLLoader && pother->mURLLoader == pentry->mURLLoader))
            pother->Canceled = true;
    }
}

// MS2-FUNCTIONAL: the exe inlines LoadQueueEntryMT_LoadMovie's ctor (with TaskManager/Ptr handling); ours inlines
// it from the same definition, with its own register allocation
// @0x1424e8c20
void MovieRoot::AddLoadQueueEntryMT(LoadQueueEntry* pentry)
{
    MemoryHeap* pheap = pMovieImpl->GetMovieHeap();
    LoadQueueEntryMT* pentryMT;
    if (pentry->Type & GFx::LoadQueueEntry::LTF_VarsFlag)
        pentryMT = SF_HEAP_NEW(pheap) LoadQueueEntryMT_LoadVars(pentry, pMovieImpl);
    else if (pentry->Type & GFx::LoadQueueEntry::LTF_BinaryFlag)
        pentryMT = SF_HEAP_NEW(pheap) LoadQueueEntryMT_LoadBinary(pentry, pMovieImpl);
    else
        pentryMT = SF_HEAP_NEW(pheap) LoadQueueEntryMT_LoadMovie(pentry, pMovieImpl);
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
    bool sync = false;
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
PropRef::~PropRef()
{
}

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
// MS2-FUNCTIONAL 0x1424dea90: releases the CallArgs values, eight FixedArgs, and the StackReader references in the same order; cl inlines their member destructors.
// @0x1424dea90
ReadArgs::~ReadArgs() {}

// MS2-FUNCTIONAL 0x1424ded40: releases ArgObject and the inherited multiname/string references; the compiler inlines the same member cleanup differently.
// @0x1424ded40
ReadMnObject::~ReadMnObject() {}

// MS2-FUNCTIONAL 0x1424dedc0: releases ArgValue with Value's destructor; the compiler emits it as a leaf inline sequence.
// @0x1424dedc0
SF_NOINLINE ReadValue::~ReadValue() {}

// MS2-FUNCTIONAL 0x1424dee30: releases ArgObject before the ReadValueMn base and its ArgValue/multiname members; codegen differs.
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
// MS2-FUNCTIONAL: preserves the exe's XML/XMLList type checks, list allocation, and flattened append behavior; helper calls change codegen.
// @0x1424e6990
bool XMLSupportImpl::Add(Value& result, Object& l, Object& r) const
{
    const bool leftXML = IsXMLObject(&l);
    const bool leftList = IsXMLListObject(&l);
    const bool rightXML = IsXMLObject(&r);
    const bool rightList = IsXMLListObject(&r);
    if ((!leftXML && !leftList) || (!rightXML && !rightList))
        return false;

    InstanceTraits::fl::XMLList& listTraits =
        *static_cast<InstanceTraits::fl::XMLList*>(GetITraitsXMLList());
    Pickable<Instances::fl::XMLList> list = listTraits.MakeInstance(listTraits);
    if (leftXML)
        list->Append(static_cast<Instances::fl::XML*>(&l));
    else
        list->Append(static_cast<Instances::fl::XMLList&>(l));
    if (rightXML)
        list->Append(static_cast<Instances::fl::XML*>(&r));
    else
        list->Append(static_cast<Instances::fl::XMLList&>(r));
    result.Pick(list);
    return true;
}

}}} // namespace Scaleform::GFx::AS3

// AvmLoader's multiple-inheritance teardown, including its AS3 subobject.
// MS2-FUNCTIONAL 0x1424ddc40: clears the loader state and tears down the same modeled bases; the compiler orders vft stores differently.
// @0x1424ddc40
Scaleform::GFx::AS3::AvmLoader::~AvmLoader()
{
    reinterpret_cast<Scaleform::UInt8*>(this)[0x6d] = 0;
}

// Invokes an object-like value with no arguments and an undefined receiver.
// MS2-FUNCTIONAL 0x1424e1a20: preserves the kind range, undefined result initialization, owning VM lookup, and zero-argument call.
// @0x1424e1a20
Scaleform::GFx::AS3::Value* FUN_1424e1a20(const Scaleform::GFx::AS3::Value* func,
                                         Scaleform::GFx::AS3::Value* result)
{
    using namespace Scaleform::GFx::AS3;
    new (result) Value();
    if (Value::IsObject(func->GetKind()))
    {
        Object& object = *const_cast<Value*>(func);
        object.GetTraits().GetVM().ExecuteInternalUnsafe(*func, Value::GetUndefined(), *result, 0, nullptr, false);
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
// MS2-FUNCTIONAL: releases pages last-first and destroys each occupied CallFrame; only register allocation differs.
// @0x1424dc8e0
void FUN_1424dc8e0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    auto numPages = *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x10);
    if (numPages)
    {
        const auto size = *reinterpret_cast<Scaleform::UPInt*>(bytes + 8);
        const Scaleform::UPInt fullPages = size >> 6;
        auto** page = *reinterpret_cast<void***>(bytes + 0x20) + numPages - 1;
        do
        {
            const Scaleform::UPInt index = numPages - 1;
            *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x10) = index;
            Scaleform::UPInt used = index < fullPages ? 0x40 : (index == fullPages ? size & 0x3f : 0);
            auto* frame = static_cast<unsigned char*>(*page) + used * 0xa8;
            while (used)
            {
                frame -= 0xa8;
                reinterpret_cast<Scaleform::GFx::AS3::CallFrame*>(frame)->~CallFrame();
                --used;
            }
            auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
            reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(Scaleform::Memory::pGlobalHeap, *page);
            numPages = *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x10);
            --page;
        } while (numPages);
        *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x10) = static_cast<Scaleform::UPInt>(-1);
        auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
        reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(
            Scaleform::Memory::pGlobalHeap, *reinterpret_cast<void**>(bytes + 0x20));
    }
    *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x18) = 0;
    *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x10) = 0;
    *reinterpret_cast<Scaleform::UPInt*>(bytes + 8) = 0;
    *reinterpret_cast<void**>(bytes + 0x20) = 0;
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
void FUN_1424dcb40(void* self)
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
using SfrCx18ClassTraitsCopyAssignment = SfrCx18ClassTraitsNode& (SfrCx18ClassTraitsNode::*)(
    const SfrCx18ClassTraitsNode&);
static SfrCx18ClassTraitsCopyAssignment SfrCx18ForceClassTraitsCopyAssignment =
    static_cast<SfrCx18ClassTraitsCopyAssignment>(&SfrCx18ClassTraitsNode::operator=);
// MS2-FUNCTIONAL: destroys every occupied node and frees the table; the template expansion has different frame/unwind codegen.
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
// MS2-FUNCTIONAL: releases occupied ASString/Value nodes and frees the backing table; template branch lowering differs.
// @0x1424dd110
template SfrCx18ASStringValueSet::~HashSetBase();
}


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

// Clears the cached namespace-trait entries and releases the table.
// MS2-FUNCTIONAL: applies the same tagged SPtr refcount release and clears each occupied entry before freeing the table.
// @0x1424dcc30
void FUN_1424dcc30(void* self)
{
    auto* table = static_cast<Scaleform::UInt64*>(self);
    if (*table)
    {
        Scaleform::UInt64 offset = 0;
        Scaleform::UInt64 count = *reinterpret_cast<Scaleform::UInt64*>(*table + 8) + 1;
        do
        {
            auto* entry = reinterpret_cast<Scaleform::UInt64*>(*table + offset);
            if (entry[2] != static_cast<Scaleform::UInt64>(-2))
            {
                Scaleform::UInt64 value = entry[5];
                if (value)
                {
                    if ((value & 1) == 0)
                    {
                        auto* refs = reinterpret_cast<Scaleform::UInt32*>(value + 0x10);
                        if ((*refs & 0x3fffff) != 0)
                        {
                            --*refs;
                            reinterpret_cast<const Scaleform::GFx::AS3::ASRefCountBaseType*>(value)->ReleaseInternal();
                        }
                    }
                    else
                        entry[5] = value - 1;
                }
                entry[2] = static_cast<Scaleform::UInt64>(-2);
            }
            offset += 0x20;
            --count;
        } while (count);
        auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
        reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(
            Scaleform::Memory::pGlobalHeap, reinterpret_cast<void*>(*table));
        *table = 0;
    }
}

// Hash<UPInt, UPInt> dtor: clears a cached hash table and releases its backing block.
// @0x1424dcce0
void FUN_1424dcce0(void* self)
{
    static_cast<Scaleform::Hash<Scaleform::UPInt, Scaleform::UPInt>*>(self)->~Hash();
}

// HashLH<Ptr<Resource>, UPInt> dtor: releases each text-format font Resource key, then frees the table.
// @0x1424dcd40
void FUN_1424dcd40(void* self)
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
// Clears VMAbcFile::ActivationTraitsCacheTable: same body as FUN_1424dcc30 (0x20-byte cached entries, SPtr value at
// +0x18). Not the AbcMultinameHash<SPtr<Namespace>> set destructor (that one is 0x1424dcf10, 0x28-byte entries).
// MS2-FUNCTIONAL: applies the same tagged SPtr refcount release and clears each occupied entry before freeing the table.
// @0x1424dcdd0
void FUN_1424dcdd0(void* self)
{
    auto* table = static_cast<Scaleform::UInt64*>(self);
    if (*table)
    {
        Scaleform::UInt64 offset = 0;
        Scaleform::UInt64 count = *reinterpret_cast<Scaleform::UInt64*>(*table + 8) + 1;
        do
        {
            auto* entry = reinterpret_cast<Scaleform::UInt64*>(*table + offset);
            if (entry[2] != static_cast<Scaleform::UInt64>(-2))
            {
                Scaleform::UInt64 value = entry[5];
                if (value)
                {
                    if ((value & 1) == 0)
                    {
                        auto* refs = reinterpret_cast<Scaleform::UInt32*>(value + 0x10);
                        if ((*refs & 0x3fffff) != 0)
                        {
                            --*refs;
                            reinterpret_cast<const Scaleform::GFx::AS3::ASRefCountBaseType*>(value)->ReleaseInternal();
                        }
                    }
                    else
                        entry[5] = value - 1;
                }
                entry[2] = static_cast<Scaleform::UInt64>(-2);
            }
            offset += 0x20;
            --count;
        } while (count);
        auto** heapVtable = *reinterpret_cast<void***>(Scaleform::Memory::pGlobalHeap);
        reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(
            Scaleform::Memory::pGlobalHeap, reinterpret_cast<void*>(*table));
        *table = 0;
    }
}
// @0x1424e0f00
template Scaleform::UPInt Scaleform::FixedSizeHash<Sfr16NamespaceHashKey>::operator()(
    const Sfr16NamespaceHashKey&) const;

namespace Scaleform { namespace Render {
// @0x1424e0cb0
StrokeStyleType& StrokeStyleType::operator=(const StrokeStyleType& other)
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

namespace Scaleform { namespace GFx { namespace AS3 {
// The ABC files are released last-loaded first, then the array and the GFx root-node base go.
// @0x1424de580
MovieDefRootNode::~MovieDefRootNode()
{
    for (SPInt i = (SPInt)AbcFiles.GetSize() - 1; i >= 0; --i)
        AbcFiles[i] = NULL;
}
}}} // namespace Scaleform::GFx::AS3

Scaleform::GFx::AS3::Value& (Scaleform::GFx::AS3::Value::* const pSfr16ValueStringAssign)(
    const Scaleform::GFx::ASString&) =
    static_cast<Scaleform::GFx::AS3::Value& (Scaleform::GFx::AS3::Value::*)(const Scaleform::GFx::ASString&)>(
        &Scaleform::GFx::AS3::Value::operator=);

using Sfr16DisplayObjectWeakArray = Scaleform::ArrayLH<
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>, 2, Scaleform::ArrayDefaultPolicy>;
// The display object map destructor (0x1424dcbb0) is the SfrCx18DisplayObjectSet instantiation above.

// MS2-FUNCTIONAL 0x1424e0340: transfers the source pointer and owner flag, releasing an owned destination first; the executable uses the same ownership behavior.
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
// MS2-FUNCTIONAL ??4Value@AS3@GFx@Scaleform@@QEAAAEAV0123@AEBVASString@23@@Z: the emitted inline overload delegates to Value::Assign(const ASString&) and preserves the same clear, namespace-retain, and string-reference behavior.
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
namespace Scaleform { namespace GFx { namespace AS3 {
extern void* const ShapeObject_vftable[];
extern void* const ShapeObject_vftable_18[];
extern void* const ShapeObject_vftable_90[];
extern void* const AvmBitmap_vftable[];
extern void* const AvmBitmap_vftable_18[];
extern void* const AvmBitmap_vftable_90[];
}}}

// AvmBitmap (a ShapeObject sibling): clear the AvmObjOffset byte, reinstall its three vftables, release the image
// and definition resources, then the AvmDisplayObj and DisplayObject bases.
// MS2-FUNCTIONAL 0x1424ddb00: AvmBitmap is not recovered; the teardown is written against raw member offsets.
// @0x1424ddb00
extern "C" void FUN_1424ddb00(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    bytes[0x6d] = 0;
    *reinterpret_cast<void* const**>(bytes + 0x00) = Scaleform::GFx::AS3::AvmBitmap_vftable;
    *reinterpret_cast<void* const**>(bytes + 0x18) = Scaleform::GFx::AS3::AvmBitmap_vftable_18;
    *reinterpret_cast<void* const**>(bytes + 0x90) = Scaleform::GFx::AS3::AvmBitmap_vftable_90;
    reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::Resource>*>(bytes + 0xc8)->~Ptr();
    reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::Resource>*>(bytes + 0xc0)->~Ptr();
    reinterpret_cast<Scaleform::GFx::AS3::AvmDisplayObj*>(bytes + 0x90)->Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj();
    reinterpret_cast<Scaleform::GFx::DisplayObject*>(bytes)->Scaleform::GFx::DisplayObject::~DisplayObject();
}

// MS2-FUNCTIONAL 0x1424deeb0: release ShapeObject's own drawing and definition references, then its bases.
// @0x1424deeb0
namespace Scaleform { namespace GFx { namespace AS3 {
ShapeObject::~ShapeObject()
{
    auto* bytes = reinterpret_cast<unsigned char*>(this);
    bytes[0x6d] = 0;
    *reinterpret_cast<void* const**>(bytes + 0x00) = ShapeObject_vftable;
    *reinterpret_cast<void* const**>(bytes + 0x18) = ShapeObject_vftable_18;
    *reinterpret_cast<void* const**>(bytes + 0x90) = ShapeObject_vftable_90;
    reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::DrawingContext>*>(bytes + 0xc8)->~Ptr();
    reinterpret_cast<Scaleform::Ptr<Scaleform::GFx::ShapeBaseCharacterDef>*>(bytes + 0xc0)->~Ptr();
    reinterpret_cast<AvmDisplayObj*>(bytes + 0x90)->AvmDisplayObj::~AvmDisplayObj();
    reinterpret_cast<Scaleform::GFx::DisplayObject*>(bytes)->DisplayObject::~DisplayObject();
}
}}}

// MS2-FUNCTIONAL 0x1424ddcb0: AvmMovieClip has no additional state; release the AvmSprite base.
// @0x1424ddcb0
extern "C" void FUN_1424ddcb0(void* self)
{
    auto* bytes = static_cast<unsigned char*>(self);
    *reinterpret_cast<void* const**>(bytes + 0x00) = Scaleform::GFx::AS3::AvmMovieClip_vftable;
    *reinterpret_cast<void* const**>(bytes + 0x30) = Scaleform::GFx::AS3::AvmMovieClip_vftable_30;
    *reinterpret_cast<void* const**>(bytes + 0x40) = Scaleform::GFx::AS3::AvmMovieClip_vftable_40;
    *reinterpret_cast<void* const**>(bytes + 0x48) = Scaleform::GFx::AS3::AvmMovieClip_vftable_48;
    reinterpret_cast<Scaleform::GFx::AS3::AvmSprite*>(self)->Scaleform::GFx::AS3::AvmSprite::~AvmSprite();
}

// MS2-PIN: FUN_1424ddcb0 0x1424ddcb0
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
// MS2-PIN: ??_7ShapeObject@AS3@GFx@Scaleform@@6B@ 0x14317c210
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317de60
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317e228
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317e330
// MS2-PIN: ??_7AvmLoader@AS3@GFx@Scaleform@@6B@ 0x14317e3e8

// Trap-stub pass (sfr21): vftable slots and adjustor thunks the full exe names but nothing defined.
namespace Scaleform { namespace GFx { namespace AS3 {

void* DeleteAs3_1424e2610(void* p, unsigned flags);
void* DeleteAs3_1424e26d0(void* p, unsigned flags);
void* DeleteAs3_1424e2a10(void* p, unsigned flags);
void* DeleteAs3_1424e2ac0(void* p, unsigned flags);
void* DeleteAs3_1424e33f0(void* p, unsigned flags);
void* DeleteAs3_1424e3890(void* p, unsigned flags);

// The object's own AS3 constructor.
// @0x1424e42a0
void InstanceTraits::Traits::AS3Constructor(const AS3::Traits&, const Value& _this, unsigned argc, const Value* argv) const
{
    _this.GetObject()->AS3Constructor(argc, argv);
}

// @0x1424e5470
bool AvmDisplayObjContainer::ActsAsButton() const { return false; }

// No AS3 object yet: a button; otherwise whether it has a mouse/button listener.
// @0x1424e5480
bool AvmInteractiveObj::ActsAsButton() const
{
    Instances::fl_display::DisplayObject* obj = GetAS3Obj();
    if (!obj)
        return true;
    return obj->HasButtonHandlers();
}

// @0x1424e54b0
bool AvmSprite::ActsAsButton() const
{
    if (SprFlags & Flag_ButtonMode)
        return true;
    if (!GetAS3Obj())
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
// @0x1424e1a98
SFR21_DTHUNK(FUN_1424e1a98, 0x18, DeleteAs3_1424e2610)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1aa4
SFR21_DTHUNK(FUN_1424e1aa4, 0x90, DeleteAs3_1424e2610)
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
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1b94
SFR21_DTHUNK(FUN_1424e1b94, 0x18, DeleteAs3_1424e3890)
// MS2-FUNCTIONAL: adjustor thunk
// @0x1424e1ba0
SFR21_DTHUNK(FUN_1424e1ba0, 0x90, DeleteAs3_1424e3890)
#undef SFR21_DTHUNK
// MS2-PIN: ??_GASMovieRootBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2210
// MS2-PIN: ??_GASVM@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2330
// MS2-PIN: ??_GAvmLoader@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e28e0
// MS2-PIN: ??_GMovieDefRootNode@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3290
// MS2-PIN: ??_GMovieDefRootNode@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3380
// MS2-PIN: ??_GVM@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e3e50
// MS2-PIN: ??_7Stage@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317d220
// MS2-PIN: ??_7Stage@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317d5f0
