// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_19
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142523170-0x14252b580 .text$mn
// MS2-RANGE: 0x14252c7e0-0x142542820 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Reserve@?$ArrayDataBase@UPair@Slots@AS3@GFx@Scaleform@@U?$AllocatorLH@UPair@Slots@AS3@GFx@Scaleform@@$0BEM@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x142523170 ; probe
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@$0BED@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142523530 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@UASStringNode@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@UASStringNode@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425235d0 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142523670 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142523710 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425238f0 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@VASString@GFx@Scaleform@@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BED@@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x142523a30 ; order
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425422c0 ; unique
// MS2-PINS-END tplpin
#define SF_AS3_AVMBUTTON_MODEL
#define SF_AS3_SHAPEOBJECT_MODEL   // ShapeObject / AvmBitmap from the SDK MI layout (as3_avm.h)
#define MS2_AS3_ASSIGN_NOALIAS
#define MS2_AS3_READARGS_NOALIAS   // ReadArgs ctor keeps no pointer to the object (as3_readargs.h)
#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp weak-ref bodies inline (as3_value.h)
// The exe's exec_esc_xattr (0x142538700) did not see XML::EscapeElementValue's body (as3_obj_fl.h).
#define SFR_AS3_ESCAPE_NO_INLINE
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/gfx_input.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_stickyvarnode.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/as3/as3_stage.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
#include "ms2/scaleform/include/gfx/as3/as3_valueobjectinterface.h"
#include "ms2/scaleform/include/gfx/gfx_button.h"
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_tracer.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/gfx/gfx_valueinfo.h"
#include <cmath>

namespace Scaleform {
// Out of line in the exe (0x1423e85f0): AS3ValueObjectInterface::SetMember calls it rather than inlining it.
template <> SF_NOINLINE void MsgFormat::FormatD1<const char*>(const char* const& v);
// Out of line in sfr_as3_15 (0x1424dc7a0): VTable::Names' storage, released by AutoPtr<VTable>::Reset.
template <> ArrayDataBase<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy>::~ArrayDataBase();
// Out of line in sfr_as3_15 (0x1424dc730): the weak display-object lists the depth hash's AutoPtr values own.
template <> ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR { class State; } }}}
// Value::AssignUnsafe as the SDK writes it (prefetch, memcpy, AddRef); the exe expands it inline in the tracer.
// ValueAssignCopies is the name as3_value.h befriends (sfr_as3_03 holds the other members).
namespace Scaleform { namespace GFx { namespace AS3 {
struct ValueAssignCopies
{
    static __forceinline void ReleaseStrong19(Value& v) { v.ReleaseInternal(); }
    // Value::PickUnsafe(Object*) (out of line in sfr_as3_18; the SCU inlines it into 0x14253bef0).
    static __forceinline void PickUnsafeObject19(Value& to, Object* v)
    {
        to.SetKind(Value::kObject);
        to.value = v;
    }
    // Value::Pick(Class*) (the SCU inlines it into exec_newclass 0x14253c470).
    static __forceinline void PickClass19(Value& to, Class* v)
    {
        to.Release();
        to.SetKind(Value::kClass);
        to.value = v;
    }
    // Value::Assign(const ASString&) as the SDK writes it, for the out-of-line operator= copy (FUN_1424e0d40).
    static SF_INLINE void AssignString19(Value& to, const ASString& v)
    {
        to.Release();
        if (v.GetNode() == v.GetNode()->GetManager()->GetNullStringNode())
        {
            to.value = (ASStringNode*)NULL;
            to.SetKind(Value::kObject);
        }
        else
        {
            to.SetKind(Value::kString);
            to.value = v.GetNode();
            to.AddRefString();
        }
    }
    // Value::AssignUnsafe(Object*), which the exe inlines into the call opcodes' slot read.
    static __forceinline void AssignUnsafeObject19(Value& to, Object* v)
    {
        to.SetKind(Value::kObject);
        to.value = v;
        if (v)
            v->AddRef();
    }
    static SF_INLINE void AssignUnsafeCopy(Value& v, const Value& other)
    {
        if (&other != &v)
        {
            SIMD::PrefetchObj(&other);
            memcpy(&v, &other, sizeof(Value));
            v.AddRef();
        }
    }
    // Value::Convert2Boolean as the SDK writes it, for the inline copy in Sfr31ValueToBool.
    static SF_INLINE bool Convert2Boolean(const Value& v)
    {
        bool result = false;
        switch (v.GetKind())
        {
        case Value::kUndefined:
            result = false;
            break;
        case Value::kBoolean:
            result = v.value;
            break;
        case Value::kInt:
            result = v.value.VS._1.VInt != 0;
            break;
        case Value::kUInt:
            result = v.value.VS._1.VUInt != 0;
            break;
        case Value::kNumber:
            if (v.IsNaN() || v.IsPOSITIVE_ZERO() || v.IsNEGATIVE_ZERO())
                result = false;
            else
                result = true;
            break;
        case Value::kString:
            if (v.value.VS._1.VStr)
                result = v.value.VS._1.VStr->Size != 0;
            else
                result = false;
            break;
        case Value::kNamespace:
            result = false;
            break;
        case Value::kFunction:
        case Value::kObject:
        case Value::kClass:
        case Value::kThunkFunction:
            if (v.IsNull())
                result = false;
            else
                result = true;
            break;
        case Value::kThunkClosure:
        case Value::kVTableIndClosure:
            result = true;
            break;
        case Value::kThunk:
        case Value::kVTableInd:
            result = true;
            break;
        default:
            break;
        }
        return result;
    }
    // Value::PickUnsafe(Value&) as the SDK writes it: other is moved bitwise and left undefined.
    static SF_INLINE void PickUnsafeCopy(Value& v, Value& other)
    {
        SIMD::PrefetchObj(&other);
        memcpy(&v, &other, sizeof(Value));
        other.SetFlags(0);
    }
    // Value::ReleaseInternal (0x142521f00) is private; the tracer calls it out of line.
    static void ReleaseInternal(Value& v) { v.ReleaseInternal(); }
};
}}}
namespace Scaleform { extern template void ArrayData<Ptr<GFx::InteractiveObject>, AllocatorLH<Ptr<GFx::InteractiveObject>, GFx::AS3::StatMV_ActionScript_Mem>, ArrayDefaultPolicy>::Resize(UPInt); typedef ArrayData<Ptr<GFx::InteractiveObject>, AllocatorLH<Ptr<GFx::InteractiveObject>, GFx::AS3::StatMV_ActionScript_Mem>, ArrayDefaultPolicy> Sfr19RolloverData; }   // RolloverStack, 0x1425245c0
namespace Scaleform { extern template void ArrayDataCC<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy>::Resize(UPInt); typedef ArrayDataCC<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy> Sfr19NamesData; }   // VTable::NamesT, 0x142524470 (instantiated at the end)
namespace Scaleform {
// TU-local forceinline copies of the DynAttrs Hash::Set chain (the exe's LTCG inlines it into newobject).
typedef GFx::AS3::Object::DynAttrsType::BaseType Sfr19DynHash;
typedef Sfr19DynHash::NodeRef Sfr19DynNodeRef;
typedef decltype(((Sfr19DynHash*)0)->mHash) Sfr19DynSet;
typedef Sfr19DynSet::BaseType Sfr19DynSetBase;
template<> template<> __forceinline void Sfr19DynSetBase::Set<Sfr19DynNodeRef>(void* pheapAddr, const Sfr19DynNodeRef& key)
{
    UPInt h   = HashNode<GFx::AS3::Object::DynAttrsKey, GFx::AS3::Value, GFx::AS3::Object::DynAttrsKeyHashFunctor>::NodeHashF()(key);
    SPInt idx = (SPInt)-1;
    if (pTable != 0)
        idx = findIndexCore(key, h & pTable->SizeMask);
    if (idx >= 0)
        E(idx).Value = key;
    else
        add(pheapAddr, key, h);
}
template<> template<> __forceinline void Sfr19DynSet::Set<Sfr19DynNodeRef>(const Sfr19DynNodeRef& key) { BaseType::Set(this, key); }
template<> __forceinline void Sfr19DynHash::Set(const GFx::AS3::Object::DynAttrsKey& key, const GFx::AS3::Value& value)
{
    NodeRef e(key, value);
    mHash.Set(e);
}
}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_1425247f0(UPInt* a, UPInt n); }}}
namespace Scaleform { extern template void ArrayDataDH<UPInt, AllocatorDH_POD<UPInt, GFx::AS3::StatMV_VM>, ArrayDefaultPolicy>::Resize(UPInt); typedef ArrayDataDH<UPInt, AllocatorDH_POD<UPInt, GFx::AS3::StatMV_VM>, ArrayDefaultPolicy> Sfr19PosData; }   // Tracer TCodeOffset arrays, 0x142524870
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_1425248e0(UPInt* a, const void* addr, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524c30(UPInt* a, const void* addr, UPInt n); }}}
namespace Scaleform { typedef ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, 340>, ArrayDefaultPolicy> Sfr19TraitsArr; extern template void Sfr19TraitsArr::ResizeNoConstruct(const void*, UPInt); } // (C3) FUN_142524af0, instantiated below
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524680(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524710(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_1425244e0(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524a30(UPInt* a, const void* addr, UPInt n); }}}
inline void FUN_14251cd30(Scaleform::GFx::AS3::TR::State* state, Scaleform::GFx::AS3::Value* popped) { ::new (static_cast<void*>(popped)) Scaleform::GFx::AS3::Value(state->PopOpValue()); }   // State::PopOpValue
namespace Scaleform { namespace GFx { namespace AS3 { void* FUN_1424e6aa0(Tracer*, const void*, unsigned long long, int, bool); } } }
inline void FUN_1424e6aa0(Scaleform::UPInt tracer, void* state, Scaleform::UInt64 pos, int a, bool b) { Scaleform::GFx::AS3::FUN_1424e6aa0(reinterpret_cast<Scaleform::GFx::AS3::Tracer*>(tracer), state, pos, a, b); }
inline void FUN_1424d6cf0(void* err, int id, void* vm, const void* a1, const void* a2) { ::new (err) Scaleform::GFx::AS3::VM::Error(static_cast<Scaleform::GFx::AS3::VM::ErrorID>(id), *static_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::Value*>(a1), *static_cast<const Scaleform::GFx::AS3::Value*>(a2)); }   // VM::Error::Error(id, vm, Value, Value)
inline void FUN_1424d6f40(void* err, int id, void* vm, const void* a1) { ::new (err) Scaleform::GFx::AS3::VM::Error(static_cast<Scaleform::GFx::AS3::VM::ErrorID>(id), *static_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::Value*>(a1)); }   // VM::Error::Error(id, vm, Value)
inline void FUN_1424d79f0(void* err, int id, void* vm, const char* a1, const void* a2) { ::new (err) Scaleform::GFx::AS3::VM::Error(static_cast<Scaleform::GFx::AS3::VM::ErrorID>(id), *static_cast<Scaleform::GFx::AS3::VM*>(vm), a1, *static_cast<const Scaleform::GFx::AS3::Value*>(a2)); }   // VM::Error::Error(id, vm, char*, Value)
namespace Scaleform { namespace GFx { namespace AS3 { __declspec(noinline) void Sfr31ButtonSetStateObject(UPInt self, int state, UPInt obj); } } }   // AvmButton::SetStateObject
void FUN_1424ffc10(Scaleform::UPInt a, Scaleform::UPInt b, Scaleform::UPInt c, int d, const Scaleform::GFx::AS3::Value* e);
void FUN_1424f03f0(unsigned char*, Scaleform::MemoryHeap*);
inline void FUN_1424f03f0(unsigned char* self, void* heap) { ::FUN_1424f03f0(self, static_cast<Scaleform::MemoryHeap*>(heap)); }
inline void FUN_14241a500(Scaleform::UPInt traits, Scaleform::UPInt* ret, Scaleform::UPInt t) { ::new (static_cast<void*>(ret)) Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array>(reinterpret_cast<Scaleform::GFx::AS3::InstanceTraits::fl::Array*>(traits)->MakeInstance(*reinterpret_cast<Scaleform::GFx::AS3::InstanceTraits::fl::Array*>(t))); }   // InstanceTraits::Array::MakeInstance
void FUN_14241d980(Scaleform::GFx::AS3::SparseArray*, Scaleform::GFx::AS3::ValueStack*, unsigned long long);
inline void FUN_14241d980(Scaleform::UPInt arr, Scaleform::UPInt stack, Scaleform::UInt32 n) { ::FUN_14241d980(reinterpret_cast<Scaleform::GFx::AS3::SparseArray*>(arr), reinterpret_cast<Scaleform::GFx::AS3::ValueStack*>(stack), n); }
inline void* FUN_14250fa80(const Scaleform::GFx::AS3::Traits* tr) { return &tr->GetVT(); }   // Traits::GetVT
inline void FUN_1424e6aa0(Scaleform::UPInt tracer, Scaleform::UPInt a, Scaleform::SPInt idx, int b, int c) { Scaleform::GFx::AS3::FUN_1424e6aa0(reinterpret_cast<Scaleform::GFx::AS3::Tracer*>(tracer), reinterpret_cast<const void*>(a), static_cast<unsigned long long>(idx), b, c != 0); }
namespace Scaleform { namespace GFx { namespace AS3 { using ::FUN_1424e6aa0; } } }
inline void FUN_14241fe30(void* arr, Scaleform::UInt32 size) { static_cast<Scaleform::GFx::AS3::SparseArray*>(arr)->Resize(size); }   // Array::SetLength
inline bool FUN_142514000(Scaleform::UPInt tracer, const void* v) { return reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->IsBooleanType(*static_cast<const Scaleform::GFx::AS3::Value*>(v)); }   // Tracer::IsBooleanType
inline bool FUN_142514470(Scaleform::UPInt tracer, const void* v) { return reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->IsNumberType(*static_cast<const Scaleform::GFx::AS3::Value*>(v)); }   // Tracer::IsNumberType
inline bool FUN_142514c30(Scaleform::UPInt tracer, const void* v) { return reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->IsSIntType(*static_cast<const Scaleform::GFx::AS3::Value*>(v)); }   // Tracer::IsIntType
inline bool FUN_142514e10(Scaleform::UPInt tracer, const void* v) { return reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->IsStringType(*static_cast<const Scaleform::GFx::AS3::Value*>(v)); }   // Tracer::IsStringType
inline bool FUN_1425150c0(Scaleform::UPInt tracer, const void* v) { return reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->IsUIntType(*static_cast<const Scaleform::GFx::AS3::Value*>(v)); }   // Tracer::IsUIntType
inline bool FUN_142514510(Scaleform::UPInt tracer, void* traits) { return reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->IsNumericType(static_cast<const Scaleform::GFx::AS3::Traits*>(traits)); }   // Tracer::IsNumericType
inline bool FUN_142514a80(Scaleform::UPInt tracer, void* traits) { return reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->IsPrimitiveType(static_cast<const Scaleform::GFx::AS3::Traits*>(traits)); }   // Tracer::IsPrimitiveType
// TR::State::GetValueTraits (0x14250fe80, private) is Sfr33TRStateAccess19::ValueTraits below
Scaleform::GFx::AS3::Instances::Namespace* FUN_142415c20(Scaleform::GFx::AS3::InstanceTraits::fl::Namespace* self, Scaleform::GFx::AS3::Abc::NamespaceKind kind, const Scaleform::GFx::ASString& uri, const Scaleform::GFx::AS3::Value& prefix);   // GetInternedInstance (lookup only)
namespace Scaleform { namespace GFx { namespace AS3 { void Sfr31VMRaiseError(unsigned long long, const unsigned long*, unsigned long long); } } }
inline void FUN_14252ecb0(void* vm, const void* error, const void* classInfo) { Scaleform::GFx::AS3::Sfr31VMRaiseError(reinterpret_cast<unsigned long long>(vm), static_cast<const unsigned long*>(error), reinterpret_cast<unsigned long long>(classInfo)); }
inline char* FUN_1424f1a30(void* v, void* ok, unsigned long* out) { ::new (ok) Scaleform::GFx::AS3::CheckResult(static_cast<const Scaleform::GFx::AS3::Value*>(v)->Convert2UInt32(*out)); return static_cast<char*>(ok); }   // Value::Convert2UInt32
inline char* FUN_1424f0d30(void* v, void* ok, long* out) { ::new (ok) Scaleform::GFx::AS3::CheckResult(static_cast<const Scaleform::GFx::AS3::Value*>(v)->Convert2Int32(*out)); return static_cast<char*>(ok); }   // Value::Convert2SInt32 (CheckResult returned in *ok)
inline void FUN_1424d9640(void* ra, Scaleform::GFx::AS3::VM* vm, void* state, Scaleform::UInt32 argc) { ::new (ra) Scaleform::GFx::AS3::TR::ReadArgs(*vm, *static_cast<Scaleform::GFx::AS3::TR::State*>(state), argc); }   // TR::ReadArgs::ReadArgs
inline void FUN_1424dea90(void* ra) { static_cast<Scaleform::GFx::AS3::TR::ReadArgs*>(ra)->~ReadArgs(); }   // TR::ReadArgs::~ReadArgs
inline void FUN_1424d9530(void* ra, Scaleform::GFx::AS3::VM* vm, Scaleform::UInt32 argc) { ::new (ra) Scaleform::GFx::AS3::ReadArgs(*vm, argc); }   // ReadArgs::ReadArgs
inline void FUN_1424de9e0(void* ra) { static_cast<Scaleform::GFx::AS3::ReadArgs*>(ra)->~ReadArgs(); }   // ReadArgs::~ReadArgs
namespace Scaleform { namespace GFx { namespace AS3 { bool FUN_1425146d0(VM&, const Value&, const ClassTraits::Traits&); } } }
inline bool FUN_1425146d0(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* v, const void* traits) { return Scaleform::GFx::AS3::FUN_1425146d0(*vm, *v, *static_cast<const Scaleform::GFx::AS3::ClassTraits::Traits*>(traits)); }
namespace Scaleform { namespace GFx { namespace AS3 { using ::FUN_1425146d0; } } }
inline Scaleform::UPInt FUN_14250fa80(Scaleform::UPInt traits) { return reinterpret_cast<Scaleform::UPInt>(&reinterpret_cast<const Scaleform::GFx::AS3::Traits*>(traits)->GetVT()); }   // Traits::GetVT
void FUN_142500260(Scaleform::GFx::AS3::VM* vm, Scaleform::UInt32 index, Scaleform::UPInt traits, Scaleform::GFx::AS3::Value* obj);
namespace Scaleform { namespace GFx { namespace AS3 { void Sfr33FindObjProperty(PropRef&, VM&, const Value&, const Multiname&, int); } } }
inline void FUN_142501b00(Scaleform::GFx::AS3::PropRef* prop, Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* obj, const Scaleform::GFx::AS3::Multiname* mn, int mode) { Scaleform::GFx::AS3::Sfr33FindObjProperty(*prop, *vm, *obj, *mn, mode); }
namespace Scaleform { namespace GFx { namespace AS3 { const Scaleform::ArrayLH_POD<unsigned long long, 338, Scaleform::ArrayDefaultPolicy>& Sfr33CallFrameGetCode(CallFrame&); } } }
inline Scaleform::UPInt FUN_142508330(void* frame) { return reinterpret_cast<Scaleform::UPInt>(&Scaleform::GFx::AS3::Sfr33CallFrameGetCode(*static_cast<Scaleform::GFx::AS3::CallFrame*>(frame))); }
int FUN_142519a00(Scaleform::GFx::AS3::VM* vm, Scaleform::UPInt index, void* frame);
namespace Scaleform { namespace GFx { namespace AS3 { ClassTraits::Traits* Sfr33SlotDataType(const SlotInfo*, VM*); } } }
inline Scaleform::GFx::AS3::ClassTraits::Traits* FUN_1425085b0(const Scaleform::GFx::AS3::SlotInfo* si, Scaleform::GFx::AS3::VM* vm) { return Scaleform::GFx::AS3::Sfr33SlotDataType(si, vm); }
inline void FUN_142508720(const Scaleform::GFx::AS3::SlotInfo* si, Scaleform::GFx::ASString* name, Scaleform::GFx::AS3::VM* vm) { ::new (static_cast<void*>(name)) Scaleform::GFx::ASString(si->GetDataTypeName(*vm)); }   // its name
char* FUN_14250e770(const Scaleform::GFx::AS3::SlotInfo*, char*, Scaleform::GFx::AS3::Value*, Scaleform::GFx::AS3::Object*);
inline void FUN_14250e770(const void* si, void* ok, Scaleform::GFx::AS3::Value* result, Scaleform::GFx::AS3::Object* obj) { ::FUN_14250e770(static_cast<const Scaleform::GFx::AS3::SlotInfo*>(si), static_cast<char*>(ok), result, obj); }
// Tracer: OrigOpcodePos.PushBack(*pos), through the real ArrayDataDH<UPInt>::PushBack (0x14251f710, called out of line)
typedef Scaleform::ArrayDataDH<Scaleform::UPInt, Scaleform::AllocatorDH_POD<Scaleform::UPInt, 328>, Scaleform::ArrayDefaultPolicy> Sfr19OpcodePosData;
#define FUN_14251f710(arr, pos) ((reinterpret_cast<Sfr19OpcodePosData*>(arr)->*static_cast<void (Sfr19OpcodePosData::*)(const Scaleform::UPInt&)>(&Sfr19OpcodePosData::PushBack))(*(pos)))
inline void FUN_1424e0b80(void* dst, const void* src) { *static_cast<Scaleform::GFx::AS3::SlotInfo*>(dst) = *static_cast<const Scaleform::GFx::AS3::SlotInfo*>(src); }   // SlotInfo::operator=
inline void FUN_1426150b0(Scaleform::UPInt doc) { reinterpret_cast<Scaleform::Render::Text::DocView*>(doc)->SetAutoSizeX(); }   // DocView::SetAutoSizeX
inline void FUN_1426150d0(Scaleform::UPInt doc) { reinterpret_cast<Scaleform::Render::Text::DocView*>(doc)->SetAutoSizeY(); }   // DocView::SetAutoSizeY
inline void FUN_1425bc060(Scaleform::UPInt tf) { reinterpret_cast<Scaleform::GFx::TextField*>(tf)->SetDirtyFlag(); }   // TextField::SetDirtyFlag
inline void FUN_142511b00(Scaleform::UPInt tracer, Scaleform::UPInt* now, Scaleform::UPInt* old) { reinterpret_cast<Scaleform::GFx::AS3::Tracer*>(tracer)->InitializeBlock(*reinterpret_cast<Scaleform::GFx::AS3::TR::Block*>(now), *reinterpret_cast<const Scaleform::GFx::AS3::TR::Block*>(old)); }   // Tracer: merge block states
char* FUN_142516c40(Scaleform::UPInt tracer, void* buf, Scaleform::UPInt* now, Scaleform::UPInt* old) { ::new (buf) Scaleform::GFx::AS3::CheckResult(reinterpret_cast<Scaleform::GFx::AS3::Tracer*>(tracer)->MergeBlock(*reinterpret_cast<Scaleform::GFx::AS3::TR::Block*>(now), *reinterpret_cast<const Scaleform::GFx::AS3::TR::Block*>(old))); return static_cast<char*>(buf); }   // Tracer: merge, result flag
namespace Scaleform { namespace GFx { namespace AS3 { void Sfr31ClassTraitsCleanup(unsigned long long); } } }
namespace Scaleform { namespace GFx { void ASUserData_SetLastObjectValue(ASUserData* puserData, void* pobjIfc, void* pdata, bool isdobj); } }
inline void FUN_1425303b0(Scaleform::UPInt entry) { Scaleform::GFx::AS3::Sfr31ClassTraitsCleanup(entry); }
// ArrayBase<ArrayData<VMAbcFile*>>::Clear. Kept as an extern alias: with the real member's COMDAT in this TU,
// cl regallocs Sfr31ShutdownRegistered without the exe's r14 save (matched -> functional).
void FUN_1424ef2a0(Scaleform::UPInt array);
inline int FUN_1425de200(int mouseState) { return Scaleform::GFx::Button::GetButtonState(static_cast<Scaleform::GFx::ButtonRecord::MouseState>(mouseState)); }   // MouseState -> ButtonState
inline void FUN_1425048d0(Scaleform::UPInt movieRoot, const void* gfxValue, Scaleform::GFx::AS3::Value* out) { reinterpret_cast<Scaleform::GFx::AS3::MovieRoot*>(movieRoot)->GFxValue2ASValue(*static_cast<const Scaleform::GFx::Value*>(gfxValue), out); }   // MovieRoot::GFxValue2ASValue
inline void FUN_1424213b0(Scaleform::UPInt sparseArray, Scaleform::UInt32 ind, const Scaleform::GFx::AS3::Value* v) { reinterpret_cast<Scaleform::GFx::AS3::SparseArray*>(sparseArray)->Set(ind, *v); }   // SparseArray::Set
inline void FUN_1423dfa20(void* obj) { static_cast<const Scaleform::GFx::AS3::RefCountBaseGC<323>*>(obj)->ReleaseInternal(); }                                                                                                  // GC release of an object whose count reached its floor
Scaleform::GFx::AS3::ClassTraits::Traits** FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self, const Scaleform::GFx::ASString& name, const Scaleform::GFx::AS3::Instances::Namespace& ns);   // MultinameHash::Get
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142415520(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP*, const Scaleform::GFx::ASString&, const Scaleform::GFx::AS3::Instances::Namespace&);
inline Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142415520(void* globalObject, const Scaleform::GFx::ASString* name, const Scaleform::GFx::AS3::Instances::Namespace* ns) { return ::FUN_142415520(static_cast<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP*>(globalObject), *name, *ns); }
inline void FUN_14251ccc0(Scaleform::GFx::AS3::TR::State* state, Scaleform::UPInt n) { state->PopOp(n); }   // State::PopOp
inline void FUN_14251fcd0(Scaleform::UPInt tracer, Scaleform::UPInt regIndex) { reinterpret_cast<Scaleform::GFx::AS3::Tracer*>(tracer)->PushNewOpCodeArg(regIndex); }                    // Tracer: note register write
inline bool* FUN_1424f1390(Scaleform::GFx::AS3::Value* v, void* tmpNode, void* strOut) { ::new (tmpNode) Scaleform::GFx::AS3::CheckResult(v->Convert2String(*static_cast<Scaleform::GFx::ASString*>(strOut))); return static_cast<bool*>(tmpNode); }   // Value::ToStringValue style conversion
// Value::operator=(const ASString&), out of line in the exe. Its callers here see the body (exec_esc_xattr 0x142538700 keeps
// the new string node in rbx across the call), so it is defined here.
inline SF_NOINLINE Scaleform::GFx::AS3::Value& FUN_1424e0d40(Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::ASString& str) { Scaleform::GFx::AS3::ValueAssignCopies::AssignString19(v, str); return v; }
unsigned long long* FUN_1424e0860(unsigned long long*, unsigned long long);
inline void FUN_1424e0860(void* out, unsigned long long value) { ::FUN_1424e0860(static_cast<unsigned long long*>(out), value); }
// ArrayDH<Value>::Resize growth, through the real ArrayDataBase<Value, AllocatorDH>::ResizeNoConstruct (0x1424201a0, called out of line)
typedef Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value, 2>, Scaleform::ArrayDefaultPolicy> Sfr19ValueArrayData;
#define FUN_1424201a0(arr, heap, n) ((static_cast<Sfr19ValueArrayData*>(static_cast<void*>(arr))->*static_cast<void (Sfr19ValueArrayData::*)(const void*, Scaleform::UPInt)>(&Sfr19ValueArrayData::ResizeNoConstruct))((heap), (n)))
inline void FUN_142521f00(void* value) { Scaleform::GFx::AS3::ValueAssignCopies::ReleaseInternal(*static_cast<Scaleform::GFx::AS3::Value*>(value)); }                                                    // Value::ReleaseInternal
inline Scaleform::SPInt FUN_1425f9200(void* list, void* obj) { return static_cast<const Scaleform::GFx::DisplayList*>(list)->FindDisplayIndex(static_cast<const Scaleform::GFx::DisplayObjectBase*>(obj)); }                          // DisplayList::FindDisplayIndex(const DisplayObjectBase*)
inline bool FUN_1425fb480(void* list, void* owner, Scaleform::UPInt i1, Scaleform::UPInt i2) { return static_cast<Scaleform::GFx::DisplayList*>(list)->SwapEntriesAtIndexes(static_cast<Scaleform::GFx::DisplayObjectBase*>(owner), i1, i2); }   // DisplayList::SwapEntriesAtIndexes
inline void FUN_142517ed0(void* avmInteractiveObj) { static_cast<Scaleform::GFx::AS3::AvmInteractiveObj*>(avmInteractiveObj)->MoveBranchInPlayList(); }                                     // AvmInteractiveObj::MoveBranchInPlayList
int FUN_142520380(void* ctx, void* multiname);                                    // Tracer: number of run-time operands a multiname takes off the stack
void FUN_1425201f0(void* ctx, void* multiname);                                      // exec: resolve runtime multiname operands from the stack
inline unsigned char* FUN_14250ef80(unsigned char* ret, Scaleform::UPInt vm, Scaleform::UPInt traits, void* result, const void* obj, const void* multiname, int target) { ::new (static_cast<void*>(ret)) Scaleform::GFx::AS3::CheckResult(Scaleform::GFx::AS3::GetSuperProperty(*reinterpret_cast<Scaleform::GFx::AS3::VM*>(vm), reinterpret_cast<const Scaleform::GFx::AS3::Traits*>(traits), *static_cast<Scaleform::GFx::AS3::Value*>(result), *static_cast<const Scaleform::GFx::AS3::Value*>(obj), *static_cast<const Scaleform::GFx::AS3::Multiname*>(multiname), static_cast<Scaleform::GFx::AS3::SlotInfo::ValTarget>(target))); return ret; } // GetSuperProperty
namespace Scaleform { namespace GFx { namespace AS3 { void Sfr33VMFindProperty(VM&, PropRef&, const Multiname&); } } }
inline void FUN_142502570(Scaleform::UPInt vm, void* propRef, void* multiname) { Scaleform::GFx::AS3::Sfr33VMFindProperty(*reinterpret_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<Scaleform::GFx::AS3::PropRef*>(propRef), *static_cast<const Scaleform::GFx::AS3::Multiname*>(multiname)); }
void FUN_14252c640(Scaleform::UPInt tracer, Scaleform::UPInt* pos);                      // Tracer: advance over padding/labels at pos
inline void FUN_1425212f0(Scaleform::UPInt tracer, Scaleform::UPInt pos) { reinterpret_cast<Scaleform::GFx::AS3::Tracer*>(tracer)->RegisterOrigOpCode(pos); }                                              // Tracer: per-opcode bookkeeping
inline void FUN_1424d7690(void* err, int id, void* vm, const char* a, const char* b) { ::new (err) Scaleform::GFx::AS3::VM::Error(static_cast<Scaleform::GFx::AS3::VM::ErrorID>(id), *static_cast<Scaleform::GFx::AS3::VM*>(vm), a, b); }   // VM::Error::Error(id, vm, char*, char*)
inline Scaleform::UPInt FUN_142507f60(Scaleform::UPInt vm, const void* value) { return reinterpret_cast<Scaleform::UPInt>(&reinterpret_cast<const Scaleform::GFx::AS3::VM*>(vm)->GetClassTraits(*static_cast<const Scaleform::GFx::AS3::Value*>(value))); }   // class traits of a value
void FUN_142500260(Scaleform::UPInt vm, unsigned int a, Scaleform::UPInt traits, void* value, unsigned int n, void* args);   // VM: call helper on a value with n arguments
inline Scaleform::UPInt FUN_1425081f0(Scaleform::UPInt vm) { return reinterpret_cast<Scaleform::UPInt>(&reinterpret_cast<const Scaleform::GFx::AS3::VM*>(vm)->GetClassVector()); }   // VM: class-traits factory
inline Scaleform::UPInt FUN_142563380(Scaleform::UPInt factory, Scaleform::UPInt traits) { return reinterpret_cast<Scaleform::UPInt>(&reinterpret_cast<Scaleform::GFx::AS3::Classes::fl_vec::Vector*>(factory)->Resolve2Vector(*reinterpret_cast<const Scaleform::GFx::AS3::ClassTraits::Traits*>(traits))); }   // class traits for traits
// SPtr<Namespace>::operator=(Namespace*) stays out of line in the exe (0x1423f1840): call it through a member pointer.
inline void FUN_1423f1840(void* slot, Scaleform::UPInt obj)
{
    typedef Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace> P;
    P& (P::*const f)(Scaleform::GFx::AS3::Instances::Namespace*) = &P::operator=;
    (static_cast<P*>(slot)->*f)(reinterpret_cast<Scaleform::GFx::AS3::Instances::Namespace*>(obj));
}   // assign a refcounted object into a slot
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { struct Sfr33NsAccess19 { static SF_FORCEINLINE void* Make(void* mem, UPInt vm, UPInt factory, int kind, void* uri, const void* prefix) { return ::new (mem) Namespace(*reinterpret_cast<VM*>(vm), reinterpret_cast<NamespaceInstanceFactory*>(factory), static_cast<Abc::NamespaceKind>(kind), *static_cast<const ASString*>(uri), *static_cast<const Value*>(prefix)); } }; } } } }   // Instances::Namespace ctor (0x1423edb60, protected)
// the class-traits cache's Remove, through the real Hash<MultinameHash<ClassTraits::Traits*>::Key, .., AllocatorDH>::Remove
// (0x142522350, called out of line; the exe's cache is the DH hash)
typedef Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits*, Scaleform::GFx::AS3::StatMV_VM_VM_Mem>::Key Sfr19CtKey;
typedef Scaleform::HashDH<Sfr19CtKey, Scaleform::GFx::AS3::ClassTraits::Traits*, Sfr19CtKey::HashFunctor, Scaleform::GFx::AS3::StatMV_VM_VM_Mem>::BaseType Sfr19CtHash;
#define FUN_142522350(hash, key) ((static_cast<Sfr19CtHash*>(static_cast<void*>(hash))->*static_cast<void (Sfr19CtHash::*)(const Sfr19CtKey&)>(&Sfr19CtHash::Remove))(*static_cast<const Sfr19CtKey*>(static_cast<void*>(key))))
__declspec(noalias) bool FUN_142506000(const Scaleform::GFx::AS3::MovieRoot*, Scaleform::GFx::AS3::Value*, const char*);
inline bool FUN_142506000(Scaleform::UPInt root, void* valueOut, Scaleform::UPInt path) { return ::FUN_142506000(reinterpret_cast<const Scaleform::GFx::AS3::MovieRoot*>(root), static_cast<Scaleform::GFx::AS3::Value*>(valueOut), reinterpret_cast<const char*>(path)); }
// ValueArray::PushBack, through the real ArrayBase<ArrayDataDH<Value>>::PushBack (0x14241e430, called out of line)
typedef Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value, 2>, Scaleform::ArrayDefaultPolicy> > Sfr19ValueArray;
#define FUN_14241e430(arr, v) ((static_cast<Sfr19ValueArray*>(static_cast<void*>(arr))->*static_cast<void (Sfr19ValueArray::*)(const Scaleform::GFx::AS3::Value&)>(&Sfr19ValueArray::PushBack))(*(v)))
extern "C" const Scaleform::StringDataPtr DAT_143a2dd40;   // "scaleform.gfx", the namespace of the GFx extension classes
namespace Scaleform { namespace GFx { namespace AS3 { ClassTraits::Traits* FUN_14250f9a0(VM&, VMAbcFile&, const Abc::ClassInfo&); } } }
inline Scaleform::UPInt FUN_14250f9a0(Scaleform::UPInt vm, Scaleform::UPInt link, Scaleform::UPInt entry) { return reinterpret_cast<Scaleform::UPInt>(Scaleform::GFx::AS3::FUN_14250f9a0(*reinterpret_cast<Scaleform::GFx::AS3::VM*>(vm), *reinterpret_cast<Scaleform::GFx::AS3::VMAbcFile*>(link), *reinterpret_cast<const Scaleform::GFx::AS3::Abc::ClassInfo*>(entry))); }
namespace Scaleform { namespace GFx { namespace AS3 { using ::FUN_14250f9a0; } } }
// (0x1423eb030 is HashSetBase<..MultinameHash<ClassTraits::Traits*, 329>..>::add<NodeRef>, reached through TClassTraitsCache::Add)
namespace Scaleform { namespace GFx { namespace AS3 { InstanceTraits::Traits& FUN_14250a060(VM&, const Value&); } } }
inline Scaleform::UPInt FUN_14250a060(Scaleform::UPInt vm, void* value) { return reinterpret_cast<Scaleform::UPInt>(&Scaleform::GFx::AS3::FUN_14250a060(*reinterpret_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::Value*>(value))); }
namespace Scaleform { namespace GFx { namespace AS3 { using ::FUN_14250a060; } } }
Scaleform::GFx::AS3::Object* FUN_14250a550(Scaleform::GFx::AS3::VM&);
inline Scaleform::UPInt FUN_14250a550(Scaleform::UPInt vm) { return reinterpret_cast<Scaleform::UPInt>(::FUN_14250a550(*reinterpret_cast<Scaleform::GFx::AS3::VM*>(vm))); }
inline void FUN_1424d7130(void* err, int id, void* vm, const void* value, const char* s) { ::new (err) Scaleform::GFx::AS3::VM::Error(static_cast<Scaleform::GFx::AS3::VM::ErrorID>(id), *static_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::Value*>(value), s); }   // VM::Error::Error(id, vm, Value, char*)
void FUN_142508bd0(Scaleform::UPInt obj, void* out, int hint);   // Object::GetDefaultValue-style conversion to a primitive
namespace Scaleform { namespace GFx { namespace AS3 { char* FUN_14250d2f0(char*, VM&, const Value&, const Multiname&, Value&); } } }
inline Scaleform::UInt8* FUN_14250d2f0(void* ret, Scaleform::UPInt vm, void* obj, void* mn, void* result) { return reinterpret_cast<Scaleform::UInt8*>(Scaleform::GFx::AS3::FUN_14250d2f0(static_cast<char*>(ret), *reinterpret_cast<Scaleform::GFx::AS3::VM*>(vm), *static_cast<const Scaleform::GFx::AS3::Value*>(obj), *static_cast<const Scaleform::GFx::AS3::Multiname*>(mn), *static_cast<Scaleform::GFx::AS3::Value*>(result))); }
namespace Scaleform { namespace GFx { namespace AS3 { using ::FUN_14250d2f0; } } }
void FUN_1424d2890(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (8-byte key)
void FUN_1424d2be0(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (int to AutoPtr map)
void FUN_1424d2d50(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (4-byte key)
void FUN_1424d2eb0(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (4-byte key to SPtr)
void FUN_1424d3030(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (pointer key to Resource)
void FUN_1424d3200(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (8-byte key to SPtr)
void FUN_1424d3380(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (multiname key to SPtr)
void FUN_1424d3530(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (ASStringNode pointer)
void FUN_1424d3870(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (ASString to Value)
void FUN_1424d5020(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (SPtr key)
Scaleform::UInt64 FUN_1424e0f00(void* self, void* key);   // multiname key hash functor
void FUN_1424dc730(void* arr);   // ~ArrayDataBase<WeakPtr<DisplayObject>>
void FUN_1424dcb40(void* node);   // ~HashNode<ASString,Value>
void FUN_1425a4030(void* res);   // Resource::Release
void FUN_1424eef00(void* tbl, Scaleform::UPInt heap);   // HashSetBase::CheckExpand
void FUN_1424eeff0(void* tbl, Scaleform::UPInt heap);   // HashSetBase::CheckExpand (dynamic attributes)
void FUN_1424d5390(void* dst, void* src);   // HashNode<DynAttrsKey,Value> copy constructor
void FUN_1424dcac0(void* node);   // ~HashNode<DynAttrsKey,Value>
bool FUN_1425149a0(const Scaleform::GFx::AS3::ClassTraits::Traits&, const Scaleform::GFx::AS3::ClassTraits::Traits&);
inline bool FUN_1425149a0(Scaleform::UPInt traits, Scaleform::UPInt src) { return ::FUN_1425149a0(*reinterpret_cast<const Scaleform::GFx::AS3::ClassTraits::Traits*>(traits), *reinterpret_cast<const Scaleform::GFx::AS3::ClassTraits::Traits*>(src)); }
namespace Scaleform { namespace GFx { namespace AS3 { bool FUN_142514560(const InstanceTraits::Traits*, const InstanceTraits::Traits*); } } }
inline bool FUN_142514560(Scaleform::UPInt src, Scaleform::UPInt dst) { return Scaleform::GFx::AS3::FUN_142514560(reinterpret_cast<const Scaleform::GFx::AS3::InstanceTraits::Traits*>(src), reinterpret_cast<const Scaleform::GFx::AS3::InstanceTraits::Traits*>(dst)); }
namespace Scaleform { namespace GFx { namespace AS3 { using ::FUN_142514560; } } }

inline void FUN_14250b240(Scaleform::UPInt link, Scaleform::UPInt* out, Scaleform::SPInt idx) { ::new (static_cast<void*>(out)) Scaleform::GFx::ASString(reinterpret_cast<Scaleform::GFx::AS3::VMAbcFile*>(link)->GetInternedString(static_cast<Scaleform::UPInt>(idx))); }   // VMAbcFile::GetInternedString (hidden return)
namespace Scaleform { namespace GFx { namespace AS3 { void* Sfr33LazyGet80a(void**); } } }
inline Scaleform::UPInt FUN_142507b80(Scaleform::UPInt traitsOwner) { return reinterpret_cast<Scaleform::UPInt>(Scaleform::GFx::AS3::Sfr33LazyGet80a(reinterpret_cast<void**>(traitsOwner))); }
namespace Scaleform { namespace GFx { namespace AS3 { ASString FUN_14250f330(ASString name, const ThunkInfo& ti, bool closure); } } }   // type name for a thunk value
namespace Scaleform { namespace GFx { namespace AS3 { ASString FUN_14250fc60(ASString name, const VTable& vt, UInt32 ind, bool closure); } } }   // type name for a vtable-method value
void* FUN_142416720(const void* self);   // InstanceTraits::Function: its VM-side owner
inline void FUN_1424fef00(void* vm, void* callee, const void* thisVal, void* result, unsigned argc, const void* args, unsigned flag) { static_cast<Scaleform::GFx::AS3::VM*>(vm)->ExecuteInternalUnsafe(*static_cast<const Scaleform::GFx::AS3::Value*>(callee), *static_cast<const Scaleform::GFx::AS3::Value*>(thisVal), *static_cast<Scaleform::GFx::AS3::Value*>(result), argc, static_cast<const Scaleform::GFx::AS3::Value*>(args), flag != 0); }
inline Scaleform::UPInt* FUN_1425ddd50(Scaleform::UPInt button, Scaleform::UPInt* out, int state) { ::new (static_cast<void*>(out)) Scaleform::Ptr<Scaleform::Render::TreeContainer>(reinterpret_cast<Scaleform::GFx::Button*>(button)->CreateStateRenderContainer(static_cast<Scaleform::GFx::Button::ButtonState>(state))); return out; }   // Button::CreateStateRenderContainer
inline Scaleform::UPInt FUN_14250dbc0(Scaleform::UPInt container) { return reinterpret_cast<const Scaleform::Render::TreeContainer*>(container)->GetSize(); }   // TreeContainer::GetSize
inline void FUN_14261cf50(Scaleform::UPInt container, Scaleform::UPInt pos, Scaleform::UPInt count) { reinterpret_cast<Scaleform::Render::TreeContainer*>(container)->Remove(pos, count); }   // TreeContainer::Remove
inline unsigned char FUN_14261c690(Scaleform::UPInt container, Scaleform::UPInt pos, Scaleform::UPInt node) { return reinterpret_cast<Scaleform::Render::TreeContainer*>(container)->Insert(pos, reinterpret_cast<Scaleform::Render::TreeNode*>(node)); }   // TreeContainer::Insert
inline Scaleform::UPInt FUN_1425f26c0(Scaleform::UPInt displayObject) { return reinterpret_cast<Scaleform::UPInt>(reinterpret_cast<const Scaleform::GFx::DisplayObjectBase*>(displayObject)->GetRenderNode()); }   // DisplayObjectBase::GetRenderNode
// Access view: the render Entry helpers are protected.
struct Sfr31EntryAccess : Scaleform::Render::ContextImpl::Entry
{
    using Entry::destroyHelper;
    using Entry::addToPropagateImpl;
    using Entry::getWritableData;
};
bool FUN_142522a60(Scaleform::GFx::AS3::VM*, void*);
inline char FUN_142522a60(Scaleform::UPInt owner, Scaleform::UPInt traits) { return ::FUN_142522a60(reinterpret_cast<Scaleform::GFx::AS3::VM*>(owner), reinterpret_cast<void*>(traits)); }
void FUN_1424ef7b0(Scaleform::UPInt hash);   // hash Clear (stride 0x18, refcounted member at +0x20)
void FUN_1424ef860(Scaleform::UPInt hash);   // hash Clear (stride 0x18, refcounted member at +0x20)
void FUN_1424ef5b0(Scaleform::UPInt hash);   // hash Clear
void FUN_1424ef500(Scaleform::UPInt hash);   // hash Clear (stride 0x20, refcounted member at +0x28)
void FUN_1424ef450(Scaleform::UPInt hash);   // hash Clear (stride 0x20, refcounted member at +0x28)
inline char* FUN_1424ff910(char* ret, Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Multiname* mn, const Scaleform::GFx::AS3::Value* obj, Scaleform::GFx::AS3::Value* result, unsigned argc, const void* args) { ::new (static_cast<void*>(ret)) Scaleform::GFx::AS3::CheckResult(Scaleform::GFx::AS3::ExecutePropertyUnsafe(*vm, *mn, *obj, *result, argc, static_cast<const Scaleform::GFx::AS3::Value*>(args))); return ret; }   // ExecutePropertyUnsafe
inline void FUN_142403310(Scaleform::UPInt obj, Scaleform::GFx::ASString* inout) { reinterpret_cast<Scaleform::GFx::AS3::Instances::fl::XMLList*>(obj)->AS3toXMLString(*inout); }   // XMLList-style toString
inline void FUN_14251fb90(void* tr, int op, Scaleform::UPInt arg) { static_cast<Scaleform::GFx::AS3::Tracer*>(tr)->PushNewOpCode(static_cast<Scaleform::GFx::AS3::Abc::Code::OpCode>(op), arg); }   // Tracer: record a rewritten opcode for a register
char* FUN_14250e2d0(const void*, void*, Scaleform::GFx::AS3::VM*, Scaleform::GFx::AS3::Value*, const Scaleform::GFx::AS3::Value*, void*, int);
inline unsigned char* FUN_14250e2d0(Scaleform::UPInt slotRef, void* ret, void* vm, Scaleform::GFx::AS3::Value* out, const Scaleform::GFx::AS3::Value* thisObj, const void* vt, unsigned b) { return reinterpret_cast<unsigned char*>(::FUN_14250e2d0(reinterpret_cast<const void*>(slotRef), ret, static_cast<Scaleform::GFx::AS3::VM*>(vm), out, thisObj, const_cast<void*>(vt), static_cast<int>(b))); }
Scaleform::GFx::AS3::GlobalSlotIndex* FUN_1424161e0(const Scaleform::GFx::AS3::Instances::Namespace*, Scaleform::GFx::AS3::GlobalSlotIndex*, Scaleform::GFx::AS3::GlobalSlotIndex);
inline void FUN_1424161e0(Scaleform::UPInt obj, void* out, Scaleform::UInt32 idx) { ::FUN_1424161e0(reinterpret_cast<const Scaleform::GFx::AS3::Instances::Namespace*>(obj), static_cast<Scaleform::GFx::AS3::GlobalSlotIndex*>(out), Scaleform::GFx::AS3::GlobalSlotIndex(idx)); }
inline Scaleform::UPInt FUN_1425fc530(Scaleform::UPInt container, unsigned idx) { return reinterpret_cast<Scaleform::UPInt>(reinterpret_cast<const Scaleform::GFx::DisplayObjContainer*>(container)->GetChildAt(idx)); }   // DisplayObjContainer::GetChildAt
//
Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo* FUN_142443d90(Scaleform::GFx::AS3::Instances::fl_display::Loader*);
inline Scaleform::UPInt FUN_142443d90(Scaleform::UPInt loader) { return reinterpret_cast<Scaleform::UPInt>(::FUN_142443d90(reinterpret_cast<Scaleform::GFx::AS3::Instances::fl_display::Loader*>(loader))); }
inline void FUN_1425a3850(void* resource) { static_cast<Scaleform::GFx::Resource*>(resource)->AddRef(); }   // Resource::AddRef
namespace Scaleform { namespace GFx { namespace AS3 { void* Sfr33IdWordHashGet(const unsigned char*, const unsigned long long&); } } }
inline void* FUN_1425059f0(void* map, const Scaleform::UPInt* key) { return Scaleform::GFx::AS3::Sfr33IdWordHashGet(static_cast<const unsigned char*>(map), *key); }
namespace Scaleform { struct MS2_LoadedMovieDefInfo { Ptr<GFx::MovieDefImpl> pMovieDef; unsigned UseCnt; MS2_LoadedMovieDefInfo(GFx::MovieDefImpl* def) : pMovieDef(def), UseCnt(1) {} }; typedef HashNode<GFx::MovieDefImpl*, MS2_LoadedMovieDefInfo, IdentityHash<GFx::MovieDefImpl*> > MS2_LoadedMovieDefNode; typedef HashsetNodeEntry<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF> MS2_LoadedMovieDefEntry; template<> MS2_LoadedMovieDefEntry::HashsetNodeEntry(const MS2_LoadedMovieDefEntry&); } static inline void FUN_1424d54f0(void* dst, void* src) { ::new (dst) Scaleform::MS2_LoadedMovieDefEntry(*static_cast<const Scaleform::MS2_LoadedMovieDefEntry*>(src)); }   // the real entry copy ctor (0x1424d54f0, sfr_as3_15's COMDAT), out of line as in the exe
// through the real ArrayBase<ArrayData<WeakPtr<DisplayObject>>>::RemoveAt (0x1425224f0, called out of line)
typedef Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>, Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>, 2>, Scaleform::ArrayDefaultPolicy> > Sfr19WeakDispArray;
#define FUN_1425224f0(arr, idx) ((static_cast<Sfr19WeakDispArray*>(static_cast<void*>(arr))->*static_cast<void (Sfr19WeakDispArray::*)(Scaleform::UPInt)>(&Sfr19WeakDispArray::RemoveAt))(idx))
inline void FUN_14261d270(void* node, int mode) { static_cast<Scaleform::Render::TreeNode*>(node)->SetEdgeAAMode(static_cast<Scaleform::Render::EdgeAAMode>(mode)); }   // TreeNode::SetEdgeAAMode
inline const void* FUN_1425f1d00(void* dispObj) { return &static_cast<const Scaleform::GFx::DisplayObjectBase*>(dispObj)->GetCxform(); }   // DisplayObjectBase::GetCxform
inline void FUN_1425f4060(void* dispObj, const void* cx) { static_cast<Scaleform::GFx::DisplayObjectBase*>(dispObj)->SetCxform(*static_cast<const Scaleform::Render::Cxform*>(cx)); }   // DisplayObjectBase::SetCxform
inline void FUN_1425bc060(void* textField) { static_cast<Scaleform::GFx::TextField*>(textField)->SetDirtyFlag(); }   // TextField::SetDirtyFlag
inline void FUN_1425be970(void* textField, void* ret, const void* displayInfo) { ::new (ret) Scaleform::Render::PointF(static_cast<const Scaleform::GFx::TextField*>(textField)->TransformToTextRectSpace(*static_cast<const Scaleform::GFx::Value::DisplayInfo*>(displayInfo))); }   // TextField::TransformToTextRectSpace
namespace Scaleform { namespace GFx { void ASCharacter_MatrixScaleAndRotate2x2(Render::Matrix2F& m, float sx, float sy, float radians); } }   // sfr_gfx_06, 0x1425f0dd0
inline double FUN_1425e3ee0() { return Scaleform::GFx::NumberUtil::NaN(); }   // the "no value" double (NaN)
inline void FUN_1424f1e50(Scaleform::UPInt state, Scaleform::UPInt traits, int nullType) { reinterpret_cast<Scaleform::GFx::AS3::TR::State*>(state)->ConvertOpTo(*reinterpret_cast<Scaleform::GFx::AS3::InstanceTraits::Traits*>(traits), static_cast<Scaleform::GFx::AS3::Value::TraceNullType>(nullType)); }   // TR::State::ConvertOpTo
inline int FUN_1424eea80(Scaleform::UPInt tracer, Scaleform::UPInt traits) { return reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->CanBeNull(*reinterpret_cast<const Scaleform::GFx::AS3::InstanceTraits::Traits*>(traits)); }   // Tracer::CanBeNull
bool FUN_1424f8b00(void* tr, int op, void* state, const Scaleform::GFx::AS3::Traits* t, const Scaleform::GFx::AS3::Multiname* pmn, int ind);   // trace a get on a name
bool FUN_1424f92f0(void* tr, int op, const Scaleform::GFx::AS3::Traits* t, void* unused, const Scaleform::GFx::AS3::Multiname* pmn, int ind);   // trace a set on a name
bool FUN_1424f7540(void* tr, int op, void* state, void* pinfo, int ind);   // trace a call on a name
bool FUN_1424f7cc0(Scaleform::UPInt tracer, void* state, int idx, bool a, int b, bool c);   // trace find/getlex
inline void FUN_1424f9180(void* tr) { static_cast<Scaleform::GFx::AS3::Tracer*>(tr)->PopPrevValue(); }   // Tracer: drop the code of the last pushed value
// TR::State::GetPropertyType (0x14250cf20, private) is Sfr33TRStateAccess19::PropType below
namespace Scaleform { namespace GFx { namespace AS3 { int FUN_14250c990(const void*, unsigned long long); } } }
inline int FUN_14250c990(Scaleform::UPInt tracer, Scaleform::UPInt pos) { return Scaleform::GFx::AS3::FUN_14250c990(reinterpret_cast<const void*>(tracer), pos); }
namespace Scaleform { namespace GFx { namespace AS3 { using ::FUN_14250c990; } } }
inline void FUN_14251f930(void* tr, int op) { static_cast<Scaleform::GFx::AS3::Tracer*>(tr)->PushNewOpCode(static_cast<Scaleform::GFx::AS3::Abc::Code::OpCode>(op)); }   // Tracer: emit opcode op
inline void FUN_14251fa10(void* tr, int op, Scaleform::UPInt arg1, Scaleform::UPInt arg2) { static_cast<Scaleform::GFx::AS3::Tracer*>(tr)->PushNewOpCode(static_cast<Scaleform::GFx::AS3::Abc::Code::OpCode>(op), arg1, arg2); }   // Tracer: emit opcode op with two arguments
inline void FUN_1424d8ec0(void* mn, Scaleform::UPInt link, Scaleform::UPInt entry) { ::new (mn) Scaleform::GFx::AS3::Multiname(*reinterpret_cast<Scaleform::GFx::AS3::VMAbcFile*>(link), *reinterpret_cast<const Scaleform::GFx::AS3::Abc::Multiname*>(entry)); }   // Multiname::Multiname(VMAbcFile&, Abc::Multiname&)
inline void FUN_1424dee30(void* r) { static_cast<Scaleform::GFx::AS3::TR::ReadValueMnObject*>(r)->~ReadValueMnObject(); }   // TR::ReadValueMnObject::~ReadValueMnObject (0x90 record)
inline void FUN_1424ded40(void* r) { static_cast<Scaleform::GFx::AS3::TR::ReadMnObject*>(r)->~ReadMnObject(); }   // TR::ReadMnObject::~ReadMnObject (0x70 record)
void FUN_1424debc0(void* r);   // ReadArgsMnObject::~ReadArgsMnObject
inline void FUN_14251cc80(Scaleform::UPInt tracer) { reinterpret_cast<Scaleform::GFx::AS3::Tracer*>(tracer)->PopNewOpCode(); }   // Tracer: close the block at a label
// TR::State::RefineOpCodeStack1 / RefineOpCodeStack2 / RefineOpCodeReg1 (0x142520e60 / 0x142520f30 / 0x142520d80, private: as3_readargs.h befriends this accessor)
namespace Scaleform { namespace GFx { namespace AS3 { namespace TR { struct Sfr33TRStateAccess19 { static SF_FORCEINLINE void Stack1(UPInt s, UPInt t, int op) { reinterpret_cast<State*>(s)->RefineOpCodeStack1(*reinterpret_cast<InstanceTraits::Traits*>(t), static_cast<Abc::Code::OpCode>(op)); }
    static SF_FORCEINLINE void Stack2(UPInt s, UPInt t, int op) { reinterpret_cast<State*>(s)->RefineOpCodeStack2(*reinterpret_cast<InstanceTraits::Traits*>(t), static_cast<Abc::Code::OpCode>(op)); } static SF_FORCEINLINE void Reg1(UPInt s, UPInt t, int op, unsigned int idx) { reinterpret_cast<State*>(s)->RefineOpCodeReg1(*reinterpret_cast<InstanceTraits::Traits*>(t), static_cast<Abc::Code::OpCode>(op), static_cast<int>(idx)); } static SF_FORCEINLINE void* ValueTraits(const void* s, const void* v) { return const_cast<AS3::Traits*>(static_cast<const State*>(s)->GetValueTraits(*static_cast<const AS3::Value*>(v))); } static SF_FORCEINLINE const char* PropType(void* s, char* ret, const void* t, const void* si, AS3::Value& v) { ::new (ret) CheckResult(static_cast<const State*>(s)->GetPropertyType(static_cast<const AS3::Traits*>(t), *static_cast<const SlotInfo*>(si), v)); return ret; } }; } } } }
inline void FUN_1424f1ed0(Scaleform::UPInt state, unsigned int ind, Scaleform::UPInt traits, int nullType) { reinterpret_cast<Scaleform::GFx::AS3::TR::State*>(state)->ConvertRegisterTo(ind, *reinterpret_cast<Scaleform::GFx::AS3::InstanceTraits::Traits*>(traits), static_cast<Scaleform::GFx::AS3::Value::TraceNullType>(nullType)); }   // TR::State::ConvertRegisterTo
inline void FUN_14251bdc0(Scaleform::UPInt vm, void* value) { reinterpret_cast<Scaleform::GFx::AS3::VM*>(vm)->OutputError(*static_cast<const Scaleform::GFx::AS3::Value*>(value)); }   // VM: flush a pending value
inline Scaleform::UPInt FUN_1425f26c0(void* displayObjectBase) { return reinterpret_cast<Scaleform::UPInt>(static_cast<const Scaleform::GFx::DisplayObjectBase*>(displayObjectBase)->GetRenderNode()); } // DisplayObjectBase::GetRenderNode
inline void FUN_1424d7850(void* err, int id, void* vm, const char* s) { ::new (err) Scaleform::GFx::AS3::VM::Error(static_cast<Scaleform::GFx::AS3::VM::ErrorID>(id), *static_cast<Scaleform::GFx::AS3::VM*>(vm), s); }   // VM::Error::Error(id, vm, char*)
inline void FUN_1424e42c0(Scaleform::UPInt root, const Scaleform::GFx::AS3::Value* v, void* gfxValue) { reinterpret_cast<const Scaleform::GFx::AS3::MovieRoot*>(root)->ASValue2GFxValue(*v, static_cast<Scaleform::GFx::Value*>(gfxValue)); }   // MovieRoot::ASValue2GFxValue
inline void FUN_142545310(Scaleform::UPInt entry, void* out) { ::new (out) Scaleform::StringDataPtr(reinterpret_cast<const Scaleform::GFx::AS3::Abc::StringView*>(entry)->ToStringDataPtr()); }   // constant-pool string entry -> (chars, length)

namespace Scaleform { namespace GFx { namespace AS3 {
void FUN_142501e80(void* state, void* propRef, void* multiname, void* a, void* b);   // Tracer: resolve a multiname to a property reference
// Defined below under their recovered names (the callers used to spell them FUN_<va>, which never linked).
char* Sfr27SlotSetValueThis(const SlotInfo* si, char* ret, VM* vm, const Value* v, const Value* thisV, VTable* vt);
char* Sfr27SlotSetValueObj(const SlotInfo* si, char* ret, VM* vm, const Value* v, Object* obj);
char* Sfr27SetPropertyOfValue(char* ret, VM* vm, const Value* obj, const Multiname* mn, const Value* v);
void  Sfr31TraceNoteJump(UPInt tr, SPInt base, UPInt blk, SInt32 off, SInt32 arg);
__declspec(noinline) void Sfr31ValueToBool(Value* v);   // the exe calls it out of line
void  Sfr31ButtonSwitchStateIntl(UPInt self, int state);
char  Sfr31TracerCommonOp(UPInt tracer, unsigned char op, UPInt* pos, UPInt state);
void  Sfr31StateTraceOp(UPInt state, unsigned char op, UPInt* pos);
UPInt Sfr31ResolveClassTraits(UPInt vmAddr, UPInt link, UPInt entry);
//void  FUN_142524af0(UPInt* a, const void* addr, UPInt n);   // = Sfr19TraitsArr::ResizeNoConstruct
//
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 { namespace ClassTraits {

// @0x1425274f0
void Traits::SetInstanceTraits(Pickable<InstanceTraits::Traits> itr)
{
    // SDK SetIsInterface(itr->IsInterface()); our shared header only has the argument-less setter.
    Flags = (Flags & ~static_cast<SPInt>(AS3::Traits::IsInterfaceMask))
        | (-static_cast<SPInt>(itr->IsInterface()) & AS3::Traits::IsInterfaceMask);
    ITraits = itr;
}

}}}} // namespace Scaleform::GFx::AS3::ClassTraits

namespace Scaleform { namespace GFx { namespace AS3 {

// An Error built by the exe's constructors (VM::Error::Error is functional in sfr_as3_15, so it is not linkable from here).
struct Sfr31Err
{
    UPInt Id, Message;    // VM::Error (0x10 bytes); an array would make every Sfr31Err local a /GS buffer
    Sfr31Err(VM::ErrorID id, VM& vm, const Value& a)               { FUN_1424d6f40(&Id, id, &vm, &a); }
    Sfr31Err(VM::ErrorID id, VM& vm, const Value& a, const Value& b) { FUN_1424d6cf0(&Id, id, &vm, &a, &b); }
    Sfr31Err(VM::ErrorID id, VM& vm, const char* a, const Value& b) { FUN_1424d79f0(&Id, id, &vm, a, &b); }
    ~Sfr31Err()                         { Get().~Error(); }
    VM::Error& Get()                    { return *reinterpret_cast<VM::Error*>(&Id); }
    operator const VM::Error&()         { return Get(); }
};


// Out-of-line copies of header inlines that the exe emits as COMDATs; taking the address forces ours (pinned below).
void (Value::* volatile sfr27KeepSetUInt32)(UInt32) = &Value::SetUInt32;

// @0x14252e560
void Value::Swap(Value& other)
{
    const UInt32 flags = other.Flags;
    const Extra bonus = other.Bonus;
    const VU val = other.value;
    other.Flags = Flags;
    other.Bonus = Bonus;
    other.value = value;
    Flags = flags;
    Bonus = bonus;
    value = val;
}

// @0x142532280
void Object::constructor(Value& result)
{
    result.Assign(&GetTraits().GetConstructor());
}

// @0x142540bb0
void Class::prototypeGet(Value& result)
{
    result.Assign(&GetPrototype());
}

// Converts the value in place to a Number through Convert2NumberInline; the exe calls SetNumber (0x142421f20)
// out of line here, so it goes through a member pointer.
// @0x14252f6d0
CheckResult Value::ToNumberValueInline()
{
    Number result;
    CheckResult r(true);
    if (Convert2NumberInline(result))
    {
        void (Value::*set)(Number) = &Value::SetNumber;
        (this->*set)(result);
    }
    else
        r = false;
    return r;
}

// ToInt32 in place: Convert2Int32 (objects through their hintNone primitive) then SetSInt32, as in the exe.
// @0x14252f670
CheckResult Value::ToInt32Value()
{
    bool ok;
    SInt32 result;
    if (Convert2Int32(result))
    {
        SetSInt32(result);
        ok = true;
    }
    else
        ok = false;
    return ok;
}

// ToUInt32 in place: Convert2UInt32 then SetUInt32, as in the exe.
// @0x14252fe80
CheckResult Value::ToUInt32Value()
{
    CheckResult ok(true);
    UInt32 result;
    if (Convert2UInt32(result))
        SetUInt32(result);
    else
        ok = false;
    return ok;
}

// @0x14252fe10
CheckResult Value::ToStringValue(StringManager& stringManager)
{
    CheckResult result(true);
    ASString string = stringManager.CreateEmptyString();
    if (Convert2String(string))
        FUN_1424e0d40(*this, string);
    else
        result = false;
    return result;
}

// The exe takes the absolute index as 32 bits (mov r14d, edx), as in Slots::SetKey.
// @0x142527560
void SlotContainerType::SetKey(AbsoluteIndex ind, const ASString& k)
{
    const UPInt index = static_cast<UInt32>(ind.Get());

    if (VArray[index].Key.GetPtr() == k.GetNode())
        // The same key.
        return;

    // Set new value.
    {
        ASStringNode* node = k.GetNode();
        VArray[index].Key = node;
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
    }
}

// @0x1425276d0
__declspec(noinline) void Slots::SetKey(AbsoluteIndex ind, const ASString& key)
{
    const UPInt ownIndex = static_cast<UInt32>(ind.Get()) - FirstOwnSlotNum;
    ASStringNode* const node = key.GetNode();
    if (VArray[ownIndex].Key.GetPtr() == node)
        return;

    VArray[ownIndex].Key = node;
    SetType::Iterator it = Set.Find(node);
    if (!it.IsEnd())
    {
        VArray[ownIndex].Prev = static_cast<const SetType::ConstIterator&>(it)->Second;
        it->Second = static_cast<UInt32>(FirstOwnSlotNum + ownIndex);
    }
    else
    {
        Set.Add(node, static_cast<UInt32>(FirstOwnSlotNum + ownIndex));
        VArray[ownIndex].Prev = -1;
    }
}

namespace TR {

// The Tracer reaches the VM and the abc file through a short pointer chain.
static inline UPInt TrRd(UPInt base, UPInt off) { return *reinterpret_cast<const UPInt*>(base + off); }
static inline UPInt TrAbcLink(UPInt tracer) { return TrRd(TrRd(tracer, 0x20), 0x28); }
static inline UPInt TrVM(UPInt tracer) { return TrRd(TrAbcLink(tracer), 0x20); }
static inline UPInt TrFile(UPInt tracer) { return TrRd(TrAbcLink(tracer), 0x28); }
static inline InstanceTraits::Traits& TrITraits(UPInt tracer, UPInt vmOff)
{
    return *reinterpret_cast<InstanceTraits::Traits*>(TrRd(TrRd(TrVM(tracer), vmOff), 0xc0));
}

// The exe pushes tracer values without releasing the temporary (the tag is known to need no release).
struct TrScratch
{
    template <class A> explicit TrScratch(const A& a) { new (&buf0) Value(a); }
    template <class A, class B> TrScratch(A& a, const B& b) { new (&buf0) Value(a, b); }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&buf0); }
    UPInt buf0, buf1, buf2, buf3;
};

// Tracer number value: tag first, then the payload (the exe fills the tag before reading the pool).
struct TrNumScratch
{
    explicit TrNumScratch(Value::KindType k) { w0 = static_cast<UInt32>(k); w1 = 0; }
    void SetInt(SInt32 v) { i = v; }
    void SetUInt(UInt32 v) { i = static_cast<SInt32>(v); }
    void SetNumber(double v) { d = v; }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1;
    union { SInt32 i; double d; };
    UPInt w3;
};

// Tracer value with a traits pointer: the exe zeroes the second word before storing the tag.
struct TrTraitsScratch
{
    TrTraitsScratch()
    {
        w1 = 0;
        w0 = static_cast<UInt32>(Value::kInstanceTraits);
    }
    // Value(tr, isNull): the null type sits above the kind bits (SetTraceNullType).
    explicit TrTraitsScratch(Value::TraceNullType isNull)
    {
        w1 = 0;
        w0 = static_cast<UInt32>(Value::kInstanceTraits) | (static_cast<UInt32>(isNull) << 5);
    }
    void SetTraits(InstanceTraits::Traits& tr) { w2 = reinterpret_cast<UPInt>(&tr); }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1, w2, w3;
};

// @0x142528e20
void State::SetRegister(AbsoluteIndex ind, const Value& v)
{
    const UInt32 i = static_cast<UInt32>(ind.Get());
    Registers[i].Assign(v);
    RegChanged[i >> 3] |= static_cast<UInt8>(1 << (i & 7));
}

// @0x14253fde0
void State::SetLocal0()
{
    SetRegister(AbsoluteIndex(0), OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253fe30
void State::SetLocal1()
{
    SetRegister(AbsoluteIndex(1), OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253fe80
void State::SetLocal2()
{
    SetRegister(AbsoluteIndex(2), OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253fed0
void State::SetLocal3()
{
    SetRegister(AbsoluteIndex(3), OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253ff20
void State::SetLocalN(UInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    Registers[ind].Assign(OpStack[OpStack.GetSize() - 1]);
    RegChanged[ind >> 3] |= static_cast<UInt8>(1 << (ind & 7));
    FUN_14251ccc0(this, 1);
}

// @0x14253f4a0
void State::PushScope()
{
    ScopeStack.PushBack(OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253f2f0
void State::PushByte(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrScratch t(static_cast<SInt32>(static_cast<char>(arg))); OpStack.PushBack(t.Get()); }
}

// @0x14253f640
void State::PushShort(SInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrScratch t(static_cast<SInt32>(arg)); OpStack.PushBack(t.Get()); }
}

// @0x14253f3b0
void State::PushInt(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kInt); t.SetInt(pool->ConstInt[ind]); OpStack.PushBack(t.Get()); }
}

// @0x14253f770
void State::PushUInt(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kUInt); t.SetUInt(pool->ConstUInt[ind]); OpStack.PushBack(t.Get()); }
}

// @0x14253f340
void State::PushDouble(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kNumber); t.SetNumber(pool->GetDouble(ind)); OpStack.PushBack(t.Get()); }
}

// @0x1425395f0
void State::PushObject(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x1f8)); OpStack.PushBack(t.Get()); }
}

// @0x14253c1a0
void State::PushObject2(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x1f8)); OpStack.PushBack(t.Get()); }
}

// @0x14253c8b0
void State::PushFunction(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x208)); OpStack.PushBack(t.Get()); }
}

// State::PushOp (OpStack.PushBack). Through the inline call the exe takes the OpStack address before it builds the
// pushed Value.
static inline void TrPushOp(State* st, const Value& v)
{
    st->GetOpStack().PushBack(v);
}

// @0x14253a630
void State::PushBoolean2(UInt32 a, UInt32 b)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(a));
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(b));
    TrPushOp(this, Value(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x210), Value::NotNull));
}

// @0x142538f20
void State::PushITraits(InstanceTraits::Traits* tr)
{
    { TrTraitsScratch t; t.SetTraits(*tr); OpStack.PushBack(t.Get()); }
}

// @0x14253bdf0
void State::KillRegister(UInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Value& undef = Value::GetUndefined();
    Registers[ind].Assign(undef);
    const UInt32 sh = ind & 7;
    RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] | (1u << sh));
    RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] & ~(1u << sh));
}


// ---- Tracer opcode handlers (free functions: `this` is the TR::State, ABI identical to the exe's member form) ----
struct StV
{
    explicit StV(void* st) : s(reinterpret_cast<UPInt>(st)) { }
    UPInt Tracer() const { return TrRd(s, 0); }
    Value* Ops() const { return reinterpret_cast<Value*>(TrRd(s, 0x38)); }
    UPInt NumOps() const { return TrRd(s, 0x40); }
    Value& Top() const { return Ops()[NumOps() - 1]; }
    Value& Below() const { return Ops()[NumOps() - 2]; }
    ArrayDH<Value>& OpStack() const { return *reinterpret_cast<ArrayDH<Value>*>(s + 0x38); }
    // The tracer's opcode array; its last entry is the opcode being specialized.
    UInt64& LastOp() const
    {
        UPInt* arr = reinterpret_cast<UPInt*>(TrRd(Tracer(), 0x28));
        return reinterpret_cast<UInt64*>(arr[0])[arr[1] - 1];
    }
    const UInt8* Code() const { return reinterpret_cast<const UInt8*>(TrRd(Tracer(), 0x50)); }
    UPInt s;
};

// The popped operand lives in raw storage: PopOpValue fills it in and the exe releases it at the end.
// Storage of a popped Value (filled by PopOpValue). The empty ctor keeps cl from treating it as a /GS buffer.
struct TrPopped
{
    TrPopped() {}
    Value& Get() { return *reinterpret_cast<Value*>(&w0); }
    UPInt w0, w1, w2, w3;
};

// Raw storage of a TR::ReadArgs (0x140 bytes), built and destroyed by the exe's own functions.
struct TrReadArgsRaw
{
    TrReadArgsRaw(VM* vm, void* st, UInt32 argc) { FUN_1424d9640(buf, vm, st, argc); }
    ~TrReadArgsRaw() { FUN_1424dea90(buf); }
    UInt8 buf[0x140];
};

// The tracer's ReadArgsObject: the call arguments, then the object they are called on.
struct TrReadArgsObject : public TR::ReadArgs
{
    TrReadArgsObject(VM& vm, State& st, UInt32 argc) : TR::ReadArgs(vm, st, argc), ArgObject(st.PopOpValue())
    {
        ++ReadNum;
    }
    Value ArgObject;
};

// The tracer's ReadArgsObjectValue: the call arguments, the object, then one more popped value.
struct TrReadArgsObjectValue : public TrReadArgsObject
{
    TrReadArgsObjectValue(VM& vm, State& st, UInt32 argc) : TrReadArgsObject(vm, st, argc), ArgValue(st.PopOpValue())
    {
        ++ReadNum;
    }
    Value ArgValue;
};

// @0x14253af70
void Sfr27TraceIfTrueFalse(State* st, UInt64* pos, int op)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    if (FUN_142514000(tracer, &s.OpStack().Back()))
    {
        UPInt* ops = reinterpret_cast<UPInt*>(TrRd(tracer, 0x28));
        reinterpret_cast<UInt64*>(ops[0])[ops[1] - 1] = static_cast<UInt64>(op != 0x11) + 0x33;
    }
    const int off = Abc::ReadS24<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), *pos);
    FUN_14251ccc0(st, 1);
    Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), off, -1);
}

// The second operand's index is s.NumOps() reduced in place, so cl emits sub rdx,2 (ops[NumOps() - 2] gives
// add rdx,-2).
static inline Value& TrOpBelow(Value* ops, UPInt size)
{
    size -= 2;
    return ops[size];
}

// @0x14253ad00
void Sfr27TraceIfCompare(State* st, UInt64* pos, UInt32 op)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    int code = static_cast<int>(op);
    Value* const ops = s.Ops();
    const UPInt n = s.NumOps();
    if (FUN_142514c30(tracer, &ops[n - 1]) && FUN_142514c30(tracer, &TrOpBelow(ops, s.NumOps())))
    {
        switch (code)
        {
        case 0xc: code = 0x8a; break;
        case 0xd: code = 0x8b; break;
        case 0xe: code = 0x8c; break;
        case 0xf: code = 0x8d; break;
        case 0x13: case 0x19: code = 0x8e; break;
        case 0x18: code = 0x8f; break;
        case 0x17: code = 0x9c; break;
        case 0x16: code = 0x9d; break;
        case 0x15: code = 0x9e; break;
        case 0x14: case 0x1a: code = 0x9f; break;
        }
        UPInt* opArr = reinterpret_cast<UPInt*>(TrRd(tracer, 0x28));
        reinterpret_cast<UInt64*>(opArr[0])[opArr[1] - 1] = static_cast<UInt32>(code);
    }
    else if (FUN_142514470(tracer, &ops[n - 1]) && FUN_142514470(tracer, &TrOpBelow(ops, s.NumOps())))
    {
        switch (code)
        {
        case 0xc: code = 200; break;
        case 0xd: code = 0xc9; break;
        case 0xe: code = 0xca; break;
        case 0xf: code = 0xcb; break;
        case 0x13: case 0x19: code = 0xcc; break;
        case 0x18: code = 0xcd; break;
        case 0x17: code = 0xbc; break;
        case 0x16: code = 0xbd; break;
        case 0x15: code = 0xbe; break;
        case 0x14: case 0x1a: code = 0xbf; break;
        }
        UPInt* opArr = reinterpret_cast<UPInt*>(TrRd(tracer, 0x28));
        reinterpret_cast<UInt64*>(opArr[0])[opArr[1] - 1] = static_cast<UInt32>(code);
    }
    const int off = Abc::ReadS24<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), *pos);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), off, -1);
}

// @0x14253bd80
void Sfr27TraceJump(State* st, UInt64* pos)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    const int off = Abc::ReadS24<UInt8>(s.Code(), *pos);
    Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), off, -1);
    FUN_1424e6aa0(tracer, st, *pos, 1, 1);
}

// @0x142540750
void Sfr27TraceLookupSwitch(State* st, UInt64* pos)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    FUN_14251ccc0(st, 1);
    const UPInt base = TrRd(tracer, 0x38);
    int off = Abc::ReadS24<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), *pos);
    Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), static_cast<int>(base - *pos) + off, 1);
    const int caseCount = Abc::ReadU30<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), *pos);
    FUN_14251fcd0(tracer, static_cast<SPInt>(caseCount));
    for (int i = 0; i <= caseCount; ++i)
    {
        off = Abc::ReadS24<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), *pos);
        Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), static_cast<int>(base - *pos) + off, i + 3);
    }
    FUN_1424e6aa0(tracer, st, *pos, 1, 1);
}

// State::ConvertOpTo inlined into the tracer's convert cases: the top is re-read through GetOpStack().Back(), and the
// Value temporary is built before Assign's this is loaded, as in the exe.
static __forceinline void TrConvertTopTo(State& st, InstanceTraits::Traits& tr, Value::TraceNullType isNull)
{
    st.GetOpStack().Back().Assign(Value(tr, isNull));
}

// @0x14253bb30
void Sfr27TraceTopBoolean(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), static_cast<UInt32>(arg));
    TrConvertTopTo(*st, TrITraits(s.Tracer(), 0x210), Value::NotNull);
}

// @0x14253f260
void Sfr27TraceCheckNumericOp(State* st)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    void* tr = TR::Sfr33TRStateAccess19::ValueTraits(st, &s.OpStack().Back());
    const UPInt vm = TrVM(tracer);
    if (tr != reinterpret_cast<void*>(TrRd(TrRd(vm, 0x210), 0xc0)) &&
        tr != reinterpret_cast<void*>(TrRd(vm, 0x278)) && tr != reinterpret_cast<void*>(TrRd(vm, 0x270)))
    {
        if (!FUN_142514510(tracer, tr))
        {
            FUN_14251ccc0(st, 1);
            return;
        }
    }
    UPInt* ops = reinterpret_cast<UPInt*>(TrRd(tracer, 0x28));
    reinterpret_cast<UInt64*>(ops[0])[ops[1] - 1] = 0x6b;
    FUN_14251ccc0(st, 1);
}

// @0x142538280
void Sfr27TraceDup2Check(State* st)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    void* tr = TR::Sfr33TRStateAccess19::ValueTraits(st, &s.OpStack().Back());
    const UPInt vm = TrVM(tracer);
    if (tr == reinterpret_cast<void*>(TrRd(TrRd(vm, 0x210), 0xc0)) ||
        tr == reinterpret_cast<void*>(TrRd(vm, 0x278)) || tr == reinterpret_cast<void*>(TrRd(vm, 0x270)) ||
        FUN_142514510(tracer, tr))
    {
        UPInt* ops = reinterpret_cast<UPInt*>(TrRd(tracer, 0x28));
        reinterpret_cast<UInt64*>(ops[0])[ops[1] - 1] = 0x69;
    }
    s.OpStack().PushBack(Value::GetUndefined());
    ValueAssignCopies::AssignUnsafeCopy(s.OpStack().Back(), s.OpStack()[s.OpStack().GetSize() - 2]);
}

// Two operands popped, one value of a builtin type pushed.
// @0x14253ab60
void Sfr27TracePop2PushInt(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x220));
    s.OpStack().PushBack(t.Get());
}

// @0x14253d3d0
void Sfr27TracePop2PushObject(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
}

// @0x14253c030
void Sfr27TraceNewArray(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, argc);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x238));
    s.OpStack().PushBack(t.Get());
}

// @0x14253cd00
void Sfr27TraceNewObject(State* st, UInt32 propCount)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), propCount);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, propCount * 2);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
}

// A tracer reader of a compile-time multiname and a value (inlined): the reader fields, the file, the ABC
// multiname entry, then the value popped off the operand stack.
struct Sfr27ReadMnCt
{
    __forceinline Sfr27ReadMnCt(State* st, UPInt tracer, UPInt idx)
    {
        state = st;
        pops = 0;
        const UPInt link = TrAbcLink(tracer);
        file = link;
        vm = TrRd(link, 0x20);
        const UPInt abc = TrRd(link, 0x28);
        UPInt e;
        if (idx == 0)
            e = abc + 0xe8;
        else
            e = idx * 0x10 + TrRd(abc, 0xb8);
        mn = reinterpret_cast<const Abc::Multiname*>(e);
    }
    UPInt vm;                   // +0x00
    State* state;               // +0x08
    int pops;                   // +0x10
    UPInt file;                 // +0x18
    const Abc::Multiname* mn;   // +0x20
};
struct Sfr27ReadMnCtValue : Sfr27ReadMnCt
{
    __forceinline Sfr27ReadMnCtValue(State* st, UPInt tracer, UPInt idx)
        : Sfr27ReadMnCt(st, tracer, idx), val(st->PopOpValue())
    {
        ++pops;
    }
    Value val;                  // +0x28
};

// The first operand popped and dropped after noting a register/operand read.
// @0x142532f20
void Sfr27TracePopNote(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), arg);
    Sfr27ReadMnCtValue args(st, s.Tracer(), arg);
}

// @0x1425379f0
void Sfr27TraceConvertTopBoolean(State* st)
{
    StV s(st);
    Value& top = st->GetOpStack().Back();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        Sfr31ValueToBool(&top);
        return;
    }
    TrConvertTopTo(*st, TrITraits(s.Tracer(), 0x210), Value::NotNull);
}

// @0x142537ab0
void Sfr27TraceConvertTopNumber(State* st)
{
    StV s(st);
    Value& top = st->GetOpStack().Back();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        top.ToNumberValueInline();
        return;
    }
    TrConvertTopTo(*st, TrITraits(s.Tracer(), 0x218), Value::NotNull);
}

// @0x142537b70
void Sfr27TraceConvertTopInt(State* st)
{
    StV s(st);
    Value& top = st->GetOpStack().Back();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        SInt32 result;
        if (top.Convert2Int32(result))
            top.SetSInt32(result);
        return;
    }
    TrConvertTopTo(*st, TrITraits(s.Tracer(), 0x220), Value::NotNull);
}

// @0x142537e00
void Sfr27TraceConvertTopUInt(State* st)
{
    StV s(st);
    Value& top = st->GetOpStack().Back();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        UInt32 result;
        if (top.Convert2UInt32(result))
            top.SetUInt32(result);
        return;
    }
    TrConvertTopTo(*st, TrITraits(s.Tracer(), 0x228), Value::NotNull);
}


// State::ConvertOpTo / ConvertRegisterTo inlined (the store order matches). The exe tail-calls the weak-proxy free
// (jmp [rax+0x60]); MS2_AS3_ASSIGN_NOALIAS gives that to Top* and Reg*. Pop2* go through TrConvertTopTo (Size
// loaded before Data, as in the exe) but still end in call; ret: the popped Value's address escapes as
// PopOpValue's sret. The tail call needs __declspec(noalias) on State::PopOpValue in as3_readargs.h.
static inline void TrConvertOp(Value& v, InstanceTraits::Traits& tr, Value::TraceNullType isNull)
{
    v.Assign(Value(tr, isNull));
}

#define SFR27_TOP_OP(Name, Off, Null) \
    void State::Name() \
    { \
        TrConvertOp(OpStack[OpStack.GetSize() - 1], TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Null); \
    }
#define SFR27_POP2_OP(Name, Off) \
    void State::Name() \
    { \
        Value popped(PopOpValue()); \
        TrConvertTopTo(*this, TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Value::NotNull); \
    }
#define SFR27_REG_OP(Name, Off) \
    void State::Name(UInt32 ind) \
    { \
        TrConvertOp(Registers[ind], TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Value::NotNull); \
    }

// dxns / dxnslate: the method must set the SETS_DXNS flag (and XML support must be enabled).
// Inlined into both ops; the tracer is re-read through State each time, and each failure throws on its own.
static SF_INLINE void TraceCheckSetsDxns(State* st, const char* disabledName, UInt32 arg, bool pop)
{
    if (*reinterpret_cast<const char*>(TrRd(TrRd(TrAbcLink(TrRd(reinterpret_cast<UPInt>(st), 0)), 0x20), 0x40) + 0x20) == 0)
    {
        VM& vm = *reinterpret_cast<VM*>(TrRd(TrAbcLink(TrRd(reinterpret_cast<UPInt>(st), 0)), 0x20));
        vm.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), vm, disabledName));
        return;
    }
    if (pop)
        FUN_14251ccc0(st, 1);
    else
        FUN_14251fcd0(TrRd(reinterpret_cast<UPInt>(st), 0), arg);
    const UPInt link = TrAbcLink(TrRd(reinterpret_cast<UPInt>(st), 0));
    const UPInt file = TrRd(link, 0x28);
    const int methodIndex = *reinterpret_cast<const int*>(TrRd(TrRd(reinterpret_cast<UPInt>(st), 0), 0x20) + 0x30);
    const UPInt method = TrRd(TrRd(file, 0x170), static_cast<SPInt>(methodIndex) * 8);
    const int bodyIndex = *reinterpret_cast<const int*>(method + 0x18);
    const UPInt body = TrRd(TrRd(file, 0xf8), static_cast<SPInt>(bodyIndex) * 8);
    if ((*reinterpret_cast<const UInt8*>(body) & 0x40) == 0)
    {
        VM& vm = *reinterpret_cast<VM*>(TrRd(link, 0x20));
        vm.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), vm, "does not have the SETS_DXNS flag set"));
    }
}

// @0x142532670
SFR27_TOP_OP(TopNumber, 0x218, Value::NotNull)
// @0x142532710
SFR27_TOP_OP(TopInt, 0x220, Value::NotNull)
// @0x1425327b0
SFR27_TOP_OP(TopString, 0x230, Value::NullOrNot)
// @0x142532850
SFR27_POP2_OP(Pop2Boolean, 0x210)
// @0x142532930
SFR27_POP2_OP(Pop2Number, 0x218)
// @0x142532a10
SFR27_POP2_OP(Pop2Int, 0x220)
// @0x142532af0
SFR27_POP2_OP(Pop2UInt, 0x228)
// @0x142537c50
SFR27_REG_OP(RegNumber, 0x218)
// @0x142537ce0
SFR27_REG_OP(RegInt, 0x220)
// @0x142537d70
SFR27_REG_OP(RegUInt, 0x228)

// @0x1425383d0
void Sfr27TraceDxns(State* st, UInt32 arg) { TraceCheckSetsDxns(st, "dxns", arg, false); }
// @0x142538490
void Sfr27TraceDxnsLate(State* st) { TraceCheckSetsDxns(st, "dxnslate", 0, true); }

} // namespace TR

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace AS3 {

// @0x14252ec90
void VM::ThrowArgumentError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ArgumentErrorCI); }
// @0x14252eca0
void VM::ThrowError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ErrorCI); }
// @0x14252efc0
void VM::ThrowEvalError(const Error& e) { FUN_14252ecb0(this, &e, &fl::EvalErrorCI); }
// @0x14252f1a0
void VM::ThrowRangeError(const Error& e) { FUN_14252ecb0(this, &e, &fl::RangeErrorCI); }
// @0x14252f1b0
void VM::ThrowReferenceError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ReferenceErrorCI); }
// @0x14252f1e0
void VM::ThrowTypeError(const Error& e) { FUN_14252ecb0(this, &e, &fl::TypeErrorCI); }
// @0x14252f1f0
void VM::ThrowURIError(const Error& e) { FUN_14252ecb0(this, &e, &fl::URIErrorCI); }
// @0x14252f210
void VM::ThrowVerifyError(const Error& e) { FUN_14252ecb0(this, &e, &fl::VerifyErrorCI); }

// ---- Small vftable-slot functions of the exe's .rdata (data_rdata_sf_b references them by FUN_<va>) ----

// Sets the "dirty" flag of the movie behind the object's owner.
// @0x1425262d0
void FUN_1425262d0(char* self) { *(*reinterpret_cast<char**>(*reinterpret_cast<char**>(self + 0x40) + 0x20) + 0xb0) = 1; }
// Hands a GFx::Value to MovieRoot::GFxValue2ASValue with the object's own Value slot as the output.
// @0x142527390
void FUN_142527390(char* self, const void* gfxValue) { FUN_1425048d0(reinterpret_cast<UPInt>(self), gfxValue, reinterpret_cast<Value*>(self + 0x58)); }
// @0x1425282c0
void FUN_1425282c0(void*) {}
// Raises or lowers a nesting counter of the movie behind the object's owner.
// @0x14252e530
void FUN_14252e530(char* self, bool enter)
{
    UInt8& n = *reinterpret_cast<UInt8*>(*reinterpret_cast<char**>(*reinterpret_cast<char**>(self + 0x40) + 0x20) + 0xb1);
    n = enter ? UInt8(n + 1) : UInt8(n - 1);
}

// Interface casts of AvmButton / AvmTextField (null stays null). Their 0x30 / 0x40 adjustor thunks come from the compiler (below).
// @0x14252f220
void* FUN_14252f220(char* p) { return p ? p + 0x40 : nullptr; }
// @0x14252f290
UPInt FUN_14252f290(void*) { return 0; }
// @0x14252f2b0
UPInt FUN_14252f2b0(void*) { return 0; }
// @0x14252f300
UPInt FUN_14252f300(void*) { return 0; }
// @0x14252f320
void* FUN_14252f320(char* p) { return p ? p + 0x30 : nullptr; }
// @0x14252f3b0
void* FUN_14252f3b0(char* p) { return p ? p + 0x30 : nullptr; }
// @0x14252f3e0
UPInt FUN_14252f3e0(void*) { return 0; }
// @0x14252f440
UPInt FUN_14252f440(void*) { return 0; }
// @0x14252f460
UPInt FUN_14252f460(void*) { return 0; }
// @0x14252f4c0
void* FUN_14252f4c0(char* p) { return p ? p + 0x40 : nullptr; }

// AvmButton / AvmTextField come from the SDK MI layout (SF_AS3_AVMBUTTON_MODEL), as in sfr_as3_17 / 18. Copy-constructing
// them stores the vptrs, so cl emits their vftables and with them its own adjustor thunks (sub rcx,N; jmp member),
// which are the exe ones in this range. The thunk targets stay the leaves above at their exe VAs.
void Sfr19EmitAvmVftables(void* p, const AvmButton* pbtn, void* q, const AvmTextField* ptxt)
{
    new (p) AvmButton(*pbtn);
    new (q) AvmTextField(*ptxt);
}
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmDisplayObj@AS3@GFx@Scaleform@@6B@ 0x14317c160
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cb30
// MS2-PIN: ??_7AvmButtonBase@GFx@Scaleform@@6B@ 0x14317db08
// MS2-PIN: ??_7AvmTextFieldBase@GFx@Scaleform@@6B@ 0x14317e508
// MS2-PIN: ??_7AvmButton@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317dbe0
// MS2-PIN: ??_7AvmButton@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317dcb0
// MS2-PIN: ??_7AvmButton@AS3@GFx@Scaleform@@6B@ 0x14317dd68
// MS2-PIN: ??_7AvmTextField@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ea80
// MS2-PIN: ??_7AvmTextField@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317eb50
// MS2-PIN: ??_7AvmTextField@AS3@GFx@Scaleform@@6B@ 0x14317ec08

// @0x142530fb0
void FUN_142530fb0(void*) {}
// @0x1425310d0
bool FUN_1425310d0(void*) { return false; }
// @0x142531250
void FUN_142531250(void*) {}

// ---- Interpreter opcode handlers (free functions; the VM is the first argument as in the exe) ----

// Raw storage of a (TR::)ReadArgs: constructed and destroyed by the exe's own out-of-line functions.
struct RA
{
    RA(VM* vm, UInt32 argc) { FUN_1424d9530(buf, vm, argc); }
    ~RA() { FUN_1424de9e0(buf); }
    ValueStack& Stk() { return **reinterpret_cast<ValueStack**>(buf + 8); }
    UInt32 ArgNum() const { return *reinterpret_cast<const UInt32*>(buf + 0x10); }
    const Value* Argv() { return ArgNum() > 8 ? *reinterpret_cast<const Value**>(buf + 0x118) : reinterpret_cast<const Value*>(buf + 0x18); }
    UInt8 buf[0x140];
};

// null or undefined where an object is needed: TypeError 1009 / 1010
static inline void ExecRequireObject(VM& vm, const Value& v)
{
    const UInt32 k = static_cast<UInt32>(v.GetKind());
    if (k == 0 || (k - 0xc < 4 && v.GetGASRefCountBase() == NULL))
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(k - 0xc < 4 ? 0x3f1 : 0x3f2), vm));
}

// VM::Convert check used by astype/coerce handlers (returns whether value can be converted to the traits).

// TypeError 1009 / 1010 for a null or undefined operand.
static __forceinline void Sfr27ThrowNullOrUndefined(VM& vm, const Value& v)
{
    vm.ThrowTypeError(VM::Error(v.IsNull() ? static_cast<VM::ErrorID>(0x3f1) : static_cast<VM::ErrorID>(0x3f2), vm));
}

// The class operand popped: a value not convertible to its type becomes null.
// SDK VM::exec_astypelate shape: early returns from both ThrowTypeError calls.
// @0x142533300
void Sfr27ExecAsType(VM* vm)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value* below = stk.GetTopPtr() - 1;
    Value y;
    y.Pick(stk);
    if (y.GetKind() != Value::kClass)
    {
        if (y.IsNullOrUndefined())
        {
            return vm->ThrowTypeError(VM::Error(
                y.IsNull() ? static_cast<VM::ErrorID>(0x3f1) : static_cast<VM::ErrorID>(0x3f2),
                *vm
                ));
        }

        return vm->ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x411), *vm));
    }

    if (!FUN_1425146d0(vm, below, &y.AsClass().GetTraits()))
        below->SetNull();
}

// SDK ReadArgsObject / ReadArgsObjectValue (AS3_VMRead.h): the call arguments, then the object (StackReader::CheckObject inlined), then the function.
struct Sfr27ReadArgsObject : public ReadArgs { SF_INLINE Sfr27ReadArgsObject(VM& vm, UInt32 n) : ReadArgs(vm, n), ArgObject(OpStack) { if (ArgObject.IsNullOrUndefined()) { const VM::ErrorID id = ArgObject.IsNull() ? static_cast<VM::ErrorID>(0x3f1) : static_cast<VM::ErrorID>(0x3f2); VM& vm = VMRef; vm.ThrowTypeError(VM::Error(id, vm)); } }
    SF_INLINE const Value* GetCallArgs() const { return ArgNum <= 8 ? FixedArgs : CallArgs.GetDataPtr(); } Value ArgObject; };
struct Sfr27ReadArgsObjectValue : public Sfr27ReadArgsObject { SF_INLINE Sfr27ReadArgsObjectValue(VM& vm, UInt32 n) : Sfr27ReadArgsObject(vm, n), value(OpStack) {} const Value value; };
static SF_INLINE void Sfr27Execute(VM* vm, const Value& func, const Value& _this, unsigned argc, const Value* argv)   // VM::Execute (result left on the stack)
{ Value result = Value::GetUndefined(); vm->ExecuteInternalUnsafe(func, _this, result, argc, argv, true); }
// call: function, receiver and argc arguments popped; the result is dropped.
// VM::exec_call with the SDK ReadArgsObjectValue reader and the inline VM::Execute.
// @0x142533680
void Sfr27ExecCallVoid(VM* vm, UInt32 argc)
{
    Sfr27ReadArgsObjectValue args(*vm, argc);   // VM::exec_call
    if (vm->IsException())
        return;
    Sfr27Execute(vm, args.value, args.ArgObject, argc, args.GetCallArgs());
}

// callmethod: receiver and argc arguments popped; the method comes from the receiver's method table.
// MS2-FUNCTIONAL 0x142533980: regalloc only: the exe saves rbx in the rdx home slot (ours the r9 home) and pops the object via r9 (ours r8).
// @0x142533980
void Sfr27ExecCallMethod(VM* vm, UInt32 methodIndex, UInt32 argc)
{
    Sfr27ReadArgsObject args(*vm, argc);   // VM::exec_callmethod
    //
    //
    //
    if (vm->IsException())
        return;
    const UPInt traits = reinterpret_cast<UPInt>(&vm->GetValueTraits(args.ArgObject));
    const UPInt vt = FUN_14250fa80(traits);
    const Value& m = *reinterpret_cast<Value*>(*reinterpret_cast<UPInt*>(vt + 8) + methodIndex * 0x20ULL);
    Value func;
    vm->ExecuteInternalUnsafe(m, args.ArgObject, func, 0, NULL, false);
    if (!vm->IsException())
    {
        Sfr27Execute(vm, func, args.ArgObject, argc, args.GetCallArgs());
        //
    }
}


static inline UPInt VmRd(VM* vm, UPInt off) { return *reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(vm) + off); }

// Push a copy of v on the VM's operand stack (VM +0x50 is the top-of-stack pointer).
static __forceinline Value* ExecPushCopy(VM* vm, const Value& v)
{
    Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    ++cur;
    return new (cur) Value(v);
}

// getscopeobject: the scope entry of the frame at index.
// @0x142539af0
void Sfr27ExecGetScopeObject(VM* vm, void* frame, UInt32 index)
{
    UPInt* scopes = *reinterpret_cast<UPInt**>(reinterpret_cast<UPInt>(frame) + 0x38);
    if (scopes == NULL || static_cast<UPInt>(index) >= scopes[1])
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x7d6), *vm));
        return;
    }
    ExecPushCopy(vm, reinterpret_cast<Value*>(scopes[0])[index]);
}

// getouterscope-style read of the VM scope stack at the frame's scope base plus index.
// @0x142539e20
void Sfr27ExecGetScopeStack(VM* vm, void* frame, UInt32 index)
{
    const UPInt pos = static_cast<UPInt>(index) + *reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(frame) + 8);
    if (pos >= VmRd(vm, 0x168))
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x7d6), *vm));
        return;
    }
    ExecPushCopy(vm, reinterpret_cast<Value*>(VmRd(vm, 0x160))[pos]);
    *reinterpret_cast<UInt32*>(VmRd(vm, 0x50)) &= 0xfffffeff;
}


// The frame's global object: the bottom scope, else the frame's this object (NULL when this is not an object).
static __forceinline Object* ExecFrameGlobalObject(UPInt frame)
{
    const UPInt* scopes = *reinterpret_cast<const UPInt* const*>(frame + 0x38);
    if (scopes != NULL && scopes[1] != 0)
        return *reinterpret_cast<Object* const*>(scopes[0] + 0x10);
    const Value* self = *reinterpret_cast<Value* const*>(*reinterpret_cast<const UPInt*>(frame + 0x18) + 8);
    return static_cast<UInt32>(self->GetKind()) - 0xc <= 3 ? reinterpret_cast<Object*>(self->GetGASRefCountBase()) : NULL;
}

// SDK VM::GetGlobalObject: the innermost call frame's (VM +0x78 frames, 64 per page of 0xa8-byte frames) global
// object; NULL with no call frame.
static __forceinline Object* ExecGlobalObject(VM* vm)
{
    const UPInt count = VmRd(vm, 0x78);
    if (count != 0)
    {
        const UPInt i = count - 1;
        return ExecFrameGlobalObject((i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8));
    }
    return NULL;
}

// SDK Slots::GetSlotInfo, inline: a parent's slot through the parent, an own slot from VArray.
static __forceinline const SlotInfo& ExecSlotInfo(const Slots& s, AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Value;
}

static __forceinline const SlotInfo& ExecGlobalSlotOf(Object* obj, UInt32 slot)
{
    Traits& tr = obj->GetTraits();
    return ExecSlotInfo(tr, AbsoluteIndex(static_cast<SPInt>(slot) - 1 + static_cast<UInt32>(tr.FirstOwnSlotInd.Get())));
}

// getglobalslot: pushes undefined, then loads the global object's slot into it.
// @0x142539490
void Sfr27ExecGetGlobalSlot(VM* vm, UInt32 slot)
{
    ExecPushCopy(vm, Value::GetUndefined());
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    Object* obj = ExecGlobalObject(vm);
    char result;    // the getter's CheckResult return slot, not read
    FUN_14250e770(&ExecGlobalSlotOf(obj, slot), &result, top, obj);
}

// The SDK ReadObjectRef: the object on top of the stack, by reference (null or undefined throws).
struct ExecReadObjectRef : public StackReader
{
    SF_INLINE ExecReadObjectRef(VM& vm) : StackReader(vm), ArgObject(*OpStack.GetTopPtr())
    {
        CheckObject(ArgObject);
    }
    // StackReader::CheckObject, inline.
    SF_INLINE void CheckObject(const Value& v) const
    {
        if (v.IsNullOrUndefined())
            GetVM().ThrowTypeError(VM::Error(v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError, GetVM()));
    }
    Value& ArgObject;
};

// getslot (VM::exec_getabsslot): the object on top of the stack is replaced by the value of its slot.
// @0x142538f50
void Sfr27ExecGetSlot(VM* vm, SPInt slot)
{
    ExecReadObjectRef args(*vm);
    if (vm->IsException())
        return;
    const Value _this(args.ArgObject, PickValue);
    Object& obj = *_this.GetObject();
    const Traits& tr = obj.GetTraits();
    char result;    // the getter's CheckResult return slot, not read (DoNotCheck)
    FUN_14250e770(&ExecSlotInfo(tr, AbsoluteIndex(slot - 1)), &result, &args.ArgObject, &obj);
}

// setglobalslot: the value on top of the stack is stored into the global object's slot and popped.
// @0x14253fc90
void Sfr27ExecSetGlobalSlot(VM* vm, UInt32 slot)
{
    Object* obj = ExecGlobalObject(vm);
    char result;    // the setter's CheckResult return slot, not read
    Traits& tr = obj->GetTraits();
    const AbsoluteIndex ind(static_cast<SPInt>(slot) - 1 + static_cast<UInt32>(tr.FirstOwnSlotInd.Get()));
    VM& ovm = obj->GetVM();
    const SlotInfo& si = ExecSlotInfo(tr, ind);
    Sfr27SlotSetValueObj(&si, &result, &ovm, reinterpret_cast<Value*>(VmRd(vm, 0x50)), obj);
    Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    cur->~Value();
    --cur;
}

// getslot for objects whose slots follow the traits' first own slot.
// @0x14253a2d0
void Sfr27ExecGetOwnSlot(VM* vm, UInt32 slot)
{
    ExecReadObjectRef args(*vm);
    if (vm->IsException())
        return;
    const Value _this(args.ArgObject, PickValue);
    Object& obj = *_this.GetObject();
    const Traits& tr = obj.GetTraits();
    char result;    // the getter's CheckResult return slot, not read (DoNotCheck)
    FUN_14250e770(&ExecSlotInfo(tr, AbsoluteIndex(static_cast<SPInt>(slot) - 1 + static_cast<UInt32>(tr.FirstOwnSlotInd.Get()))), &result, &args.ArgObject, &obj);
}

// The SDK ReadValueObject: the value, then the object it is stored on (null or undefined throws).
struct ExecReadValueObject : public StackReader
{
    SF_INLINE ExecReadValueObject(VM& vm) : StackReader(vm), ArgValue(OpStack), ArgObject(OpStack)
    {
        CheckObject(ArgObject);
    }
    SF_INLINE ~ExecReadValueObject() {}
    // StackReader::CheckObject, inline.
    SF_INLINE void CheckObject(const Value& v) const
    {
        if (v.IsNullOrUndefined())
            GetVM().ThrowTypeError(VM::Error(v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError, GetVM()));
    }
    Value ArgValue;
    Value ArgObject;
};

// setslot: value and object popped, the object's slot receives the value.
// @0x14253faa0
void Sfr27ExecSetSlot(VM* vm, SPInt slot)
{
    ExecReadValueObject args(*vm);
    if (vm->IsException())
        return;
    Object* obj = reinterpret_cast<Object*>(args.ArgObject.GetGASRefCountBase());
    char result;    // the setter's CheckResult return slot, not read
    Sfr27SlotSetValueObj(&ExecSlotInfo(obj->GetTraits(), AbsoluteIndex(slot - 1)), &result, &obj->GetVM(), &args.ArgValue, obj);
}


// ---- SlotInfo::SetSlotValue (two entry points: with the receiver's Value and VTable, or with the Object) ----

// MS2-FUNCTIONAL 0x142529030: SDK SlotInfo::SetSlotValue shape (one switch, error temps in the throw); the exe frame is 0x10 larger (setter Value shares the 0x432 error slot), tests ReadOnly as a byte and reloads the BindType dword, so slots and registers differ
// Store v into slot si of the object held by thisV (setters run with thisV as receiver).
// @0x142529030
char* Sfr27SlotSetValueThis(const SlotInfo* si, char* ret, VM* vm, const Value* v, const Value* thisV, VTable* vt)
{
    if (si->ReadOnly && !(static_cast<int>(VmRd(vm, 0x30)) > 0))
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData, *thisV));
        *ret = 0;
        return ret;
    }
    Value coerced;
    if (v->GetKind() == Value::kClass || si->BindType > 10)
        coerced.Assign(*v);
    else
    {
        ClassTraits::Traits* ct = FUN_1425085b0(si, vm);
        if (ct == NULL)
        {
            vm->ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3f6), *vm, Value(si->GetDataTypeName(*vm), Value::InlineStr)));
            *ret = 0;
            return ret;
        }
        if (!ct->Coerce(*v, coerced))
        {
            vm->ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x40a), *vm, *v, Value(si->GetDataTypeName(*vm), Value::InlineStr)));
            *ret = 0;
            return ret;
        }
    }
    const UInt32 ind = si->ValueInd;
    switch (si->BindType)
    {
    case SlotInfo::BT_ValueArray:
        reinterpret_cast<Value*>(*reinterpret_cast<UPInt*>(reinterpret_cast<UPInt>(thisV->GetGASRefCountBase()) + 0xa8))[ind].Assign(coerced);
        break;
    case SlotInfo::BT_Value:
        reinterpret_cast<Value*>(reinterpret_cast<UPInt>(thisV->GetGASRefCountBase()) + ind)->Assign(coerced);
        break;
    case SlotInfo::BT_ObjectAS:
        reinterpret_cast<STPtr*>(reinterpret_cast<UPInt>(thisV->GetGASRefCountBase()) + ind)->SetValue(coerced);
        break;
    case SlotInfo::BT_ObjectCpp:
    {
        UPInt* slot = reinterpret_cast<UPInt*>(reinterpret_cast<UPInt>(thisV->GetGASRefCountBase()) + ind);
        const UPInt np = reinterpret_cast<const UPInt*>(&coerced)[2];
        if (np != *slot)
        {
            const UPInt old = *slot;
            if (old != 0)
            {
                if (old & 1)
                    *slot = old - 1;
                else
                {
                    UInt32* rc = reinterpret_cast<UInt32*>(old + 0x10);
                    if ((*rc & 0x3fffff) != 0)
                    {
                        --*rc;
                        FUN_1423dfa20(reinterpret_cast<void*>(old));
                    }
                }
            }
            if (np != 0)
            {
                UInt32* rc = reinterpret_cast<UInt32*>(np + 0x10);
                *rc = (*rc + 1) & 0x8fbfffff;
            }
            *slot = np;
        }
        break;
    }
    case SlotInfo::BT_Boolean:
        *reinterpret_cast<UInt8*>(reinterpret_cast<UPInt>(thisV->GetGASRefCountBase()) + ind) = static_cast<UInt8>(reinterpret_cast<const UPInt*>(&coerced)[2]);
        break;
    case SlotInfo::BT_Int:
    case SlotInfo::BT_UInt:
        *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(thisV->GetGASRefCountBase()) + ind) = static_cast<UInt32>(reinterpret_cast<const UPInt*>(&coerced)[2]);
        break;
    case SlotInfo::BT_Number:
        *reinterpret_cast<double*>(reinterpret_cast<UPInt>(thisV->GetGASRefCountBase()) + ind) = *reinterpret_cast<const double*>(&reinterpret_cast<const UPInt*>(&coerced)[2]);
        break;
    case SlotInfo::BT_String:
    {
        ASStringNode** slot = reinterpret_cast<ASStringNode**>(reinterpret_cast<UPInt>(thisV->GetGASRefCountBase()) + ind);
        ASStringNode* old = *slot;
        ASStringNode* ns = reinterpret_cast<ASStringNode*>(reinterpret_cast<const UPInt*>(&coerced)[2]);
        if (old != NULL)
            old->Release();
        *slot = ns;
        if (ns != NULL)
            ns->AddRef();
        break;
    }
    case 10: case SlotInfo::BT_Get:
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData, *thisV));
        *ret = 0;
        return ret;
    case SlotInfo::BT_Set: case SlotInfo::BT_GetSet:
    {
        if (vt == NULL)
            vt = reinterpret_cast<VTable*>(FUN_14250fa80(reinterpret_cast<UPInt>(&vm->GetValueTraits(*thisV))));
        Value setter = vt->GetValue(AbsoluteIndex(ind + 1));
        const UInt32 sk = static_cast<UInt32>(setter.GetKind());
        if (sk < 0xc && sk - 5 > 2)
        {
            vm->ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3ee), *vm, setter));
            *ret = 0;
            return ret;
        }
        Value result(Value::GetUndefined());
        vm->ExecuteInternalUnsafe(setter, *thisV, result, 1, &coerced, false);
        if (vm->IsException())
        {
            *ret = 0;
            return ret;
        }
        break;
    }
    case SlotInfo::BT_Code:
    {
        const UInt32 k = static_cast<UInt32>(thisV->GetKind());
        const bool primitive = k < 5 || k == 10;
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(primitive ? 0x420 : 0x40d), *vm, si->Name->pData, *thisV));
        *ret = 0;
        return ret;
    }
    default:
        *ret = 0;
        return ret;
    }
    *ret = 1;
    return ret;
}

// MS2-FUNCTIONAL 0x142529720: SDK SlotInfo::SetSlotValue(Object*) shape; the exe cross-jumps the two coerce-error tails the other way, keeps the setter Value in another slot, and tests ReadOnly as a byte, so the layout and slots differ
// The same for an Object receiver; the error texts name the object's traits.
// @0x142529720
char* Sfr27SlotSetValueObj(const SlotInfo* si, char* ret, VM* vm, const Value* v, Object* obj)
{
    if (si->ReadOnly && !(static_cast<int>(VmRd(vm, 0x30)) > 0))
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData, obj->GetTraits().GetName().ToCStr()));
        *ret = 0;
        return ret;
    }
    Value coerced;
    if (v->GetKind() == Value::kClass || si->BindType > 10)
        coerced.Assign(*v);
    else
    {
        ClassTraits::Traits* ct = FUN_1425085b0(si, vm);
        if (ct == NULL)
        {
            vm->ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3f6), *vm, Value(si->GetDataTypeName(*vm), Value::InlineStr)));
            *ret = 0;
            return ret;
        }
        if (!ct->Coerce(*v, coerced))
        {
            vm->ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x40a), *vm, *v, Value(si->GetDataTypeName(*vm), Value::InlineStr)));
            *ret = 0;
            return ret;
        }
    }
    const UInt32 ind = si->ValueInd;
    switch (si->BindType)
    {
    case SlotInfo::BT_ValueArray:
        reinterpret_cast<Value*>(*reinterpret_cast<UPInt*>(reinterpret_cast<UPInt>(obj) + 0xa8))[ind].Assign(coerced);
        break;
    case SlotInfo::BT_Value:
        reinterpret_cast<Value*>(reinterpret_cast<UPInt>(obj) + ind)->Assign(coerced);
        break;
    case SlotInfo::BT_ObjectAS:
        reinterpret_cast<STPtr*>(reinterpret_cast<UPInt>(obj) + ind)->SetValue(coerced);
        break;
    case SlotInfo::BT_ObjectCpp:
    {
        UPInt* slot = reinterpret_cast<UPInt*>(reinterpret_cast<UPInt>(obj) + ind);
        const UPInt np = reinterpret_cast<const UPInt*>(&coerced)[2];
        if (np != *slot)
        {
            const UPInt old = *slot;
            if (old != 0)
            {
                if (old & 1)
                    *slot = old - 1;
                else
                {
                    UInt32* rc = reinterpret_cast<UInt32*>(old + 0x10);
                    if ((*rc & 0x3fffff) != 0)
                    {
                        --*rc;
                        FUN_1423dfa20(reinterpret_cast<void*>(old));
                    }
                }
            }
            if (np != 0)
            {
                UInt32* rc = reinterpret_cast<UInt32*>(np + 0x10);
                *rc = (*rc + 1) & 0x8fbfffff;
            }
            *slot = np;
        }
        break;
    }
    case SlotInfo::BT_Boolean:
        *reinterpret_cast<UInt8*>(reinterpret_cast<UPInt>(obj) + ind) = static_cast<UInt8>(reinterpret_cast<const UPInt*>(&coerced)[2]);
        break;
    case SlotInfo::BT_Int:
    case SlotInfo::BT_UInt:
        *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(obj) + ind) = static_cast<UInt32>(reinterpret_cast<const UPInt*>(&coerced)[2]);
        break;
    case SlotInfo::BT_Number:
        *reinterpret_cast<double*>(reinterpret_cast<UPInt>(obj) + ind) = *reinterpret_cast<const double*>(&reinterpret_cast<const UPInt*>(&coerced)[2]);
        break;
    case SlotInfo::BT_String:
    {
        ASStringNode** slot = reinterpret_cast<ASStringNode**>(reinterpret_cast<UPInt>(obj) + ind);
        ASStringNode* old = *slot;
        ASStringNode* ns = reinterpret_cast<ASStringNode*>(reinterpret_cast<const UPInt*>(&coerced)[2]);
        if (old != NULL)
            old->Release();
        *slot = ns;
        if (ns != NULL)
            ns->AddRef();
        break;
    }
    case 10: case SlotInfo::BT_Get:
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData, obj->GetTraits().GetName().ToCStr()));
        break;
    case SlotInfo::BT_Set: case SlotInfo::BT_GetSet:
    {
        Value setter = reinterpret_cast<VTable*>(FUN_14250fa80(reinterpret_cast<UPInt>(&obj->GetTraits())))->GetValue(AbsoluteIndex(ind + 1));
        const UInt32 sk = static_cast<UInt32>(setter.GetKind());
        if (sk < 0xc && sk - 5 > 2)
        {
            vm->ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3ee), *vm, setter));
            *ret = 0;
            return ret;
        }
        Value result(Value::GetUndefined());
        vm->ExecuteInternalUnsafe(setter, Value(obj), result, 1, &coerced, false);
        if (vm->IsException())
        {
            *ret = 0;
            return ret;
        }
        break;
    }
    case SlotInfo::BT_Code:
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x40d), *vm, si->Name->pData, obj->GetTraits().GetName().ToCStr()));
        *ret = 0;
        return ret;
    default:
        *ret = 0;
        return ret;
    }
    *ret = 1;
    return ret;
}


// throw: the exception object is taken off the stack, then the frame's handler table is searched.
// MS2-FUNCTIONAL 0x142540850: register order only: the exe holds the old exception Flags in edx, ours in r9d.
// @0x142540850
int Sfr27ExecThrow(VM* vm, UInt64* pc, CallFrame* frame)
{
    vm->ExceptionObj.Pick(*reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48));
    const UInt64* const* code = reinterpret_cast<const UInt64* const*>(FUN_142508330(frame));
    return FUN_142519a00(vm, pc - *code, frame);
}

// Value(const ASString&) as the exe inlines it (the out-of-line one is 0x1424dbf70); same body as sfr_as3_18's.
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

// typeof: the value on top of the stack is replaced by the name of its type.
// @0x142540910
void Sfr27ExecTypeOf(VM* vm)
{
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    SPInt idx;
    switch (top->GetKind())
    {
    case 0: idx = 1; break;
    case 1: idx = 6; break;
    case 2: case 3: case 4: idx = 7; break;
    case 10:
        idx = top->GetGASRefCountBase() == NULL ? 10 : 8;
        break;
    case 5: case 7: case 0xe: case 0xf: case 0x10: case 0x11: idx = 9; break;
    case 0xb: case 0xc:
    {
        const UPInt traits = reinterpret_cast<UPInt>(&vm->GetValueTraits(*top));
        const int tt = *reinterpret_cast<const int*>(traits + 0x70);
        idx = (tt == 0xd || tt == 0xe) ? 11 : 10;
        break;
    }
    default: idx = 0xc; break;
    }
    top->Assign(Value(vm->GetStringManager().GetBuiltin(static_cast<BuiltinType>(idx)), Value::InlineStr));
}


// A PropRef that found nothing: no this value, or an empty dynamic/closure tag.
static inline bool PropRefNotFound(const PropRef& p)
{
    const UPInt w = reinterpret_cast<UPInt>(p.pValue);
    return p.This.GetKind() == Value::kUndefined || w == 1 || w == 2;
}

// Object.SetProperty: a fixed slot, an existing dynamic value, or a new dynamic property.
// LTCG knows the lookup only reads the this-Value, so the exe releases it without a kind test (dtor-less holder).
union Sfr31SelfValueHolder { Value v; Sfr31SelfValueHolder(Object* o) : v(o, Value::InlineObj) {} ~Sfr31SelfValueHolder() {} };
// MS2-FUNCTIONAL 0x142528a50: regalloc only: the exe holds value in r14 and the zero/traits register in r15 (ours swaps them)
// @0x142528a50
CheckResult Object::SetProperty(const Multiname& prop_name, const Value& value)
{
    VM& vm = GetVM();
    PropRef prop;
    {
        Sfr31SelfValueHolder self(this);
        FUN_142501b00(&prop, &GetVM(), &self.v, &prop_name, 1);
        FUN_142521f00(&self.v);
    }
    const UPInt pv = reinterpret_cast<UPInt>(prop.pValue);
    if (prop.This.GetKind() != Value::kUndefined && pv != 1 &&
        !((static_cast<UInt8>(pv >> 1) & 1) != 0 && (pv & ~static_cast<UPInt>(2)) == 0))
    {
        bool result = true;
        switch (pv & 3)
        {
        case 0:
        {
            char r;
            result = *reinterpret_cast<const CheckResult*>(Sfr27SlotSetValueThis(prop.pSI, &r, &vm, &value, &prop.This, NULL));
        }
            break;
        case 1:
            reinterpret_cast<Value*>(pv & ~static_cast<UPInt>(1))->Assign(value);
            break;
        case 2:
            result = false;
            break;
        default:
            break;
        }
        return CheckResult(result);
    }
    Traits& tr = GetTraits();
    if (tr.IsDynamic() && prop_name.ContainsNamespace(vm.GetPublicNamespace()))
    {
        AddDynamicSlotValuePair(prop_name.Name, value);
        return CheckResult(true);
    }
    vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x420), vm, prop_name.Name, tr.GetName().ToCStr()));
    return CheckResult(false);
}

// MS2-FUNCTIONAL 0x142528810: regalloc/slots only: the exe holds ret in rbx, _this and the result bool in rdi (ours swaps them), saves rbx in the rdx home and puts the error temps 0x10 higher; same frame size
// setproperty on any value: special-property objects take it themselves, the rest go through the property lookup.
static __forceinline CheckResult Sfr31SetPropertyInl(VM& vm, const Value& _this, const Multiname& prop_name, const Value& value)
{
    if (static_cast<UInt32>(_this.GetKind()) - 0xc <= 3)
    {
        Object* o = reinterpret_cast<Object*>(_this.GetGASRefCountBase());
        const Traits& tr = o->GetTraits(); const BuiltinTraitsType tt = tr.GetTraitsType();
        if (tr.IsArrayLike() || ((tt == Traits_XML || tt == Traits_XMLList) && tr.IsInstanceTraits()))
            //
            return o->SetProperty(prop_name, value);
    }
    PropRef prop;
    FUN_142501b00(&prop, &vm, &_this, &prop_name, 1);
    if (prop.This.GetKind() != Value::kUndefined && reinterpret_cast<UPInt>(prop.pValue) != 1 &&
        !((static_cast<UInt8>(reinterpret_cast<UPInt>(prop.pValue) >> 1) & 1) != 0 && (reinterpret_cast<UPInt>(prop.pValue) & ~static_cast<UPInt>(2)) == 0))
    {
        bool result = true;
        switch (reinterpret_cast<UPInt>(prop.pValue) & 3)
        {
        case 0:
        {
            char r;
            result = *reinterpret_cast<const CheckResult*>(Sfr27SlotSetValueThis(prop.pSI, &r, &vm, &value, &prop.This, NULL));
        }
            break;
        case 1:
            reinterpret_cast<Value*>(reinterpret_cast<UPInt>(prop.pValue) & ~static_cast<UPInt>(1))->Assign(value);
            break;
        case 2:
            result = false;
            break;
        default:
            break;
        }
        return CheckResult(result);
    }
    if (static_cast<UInt32>(_this.GetKind()) - 0xc <= 3)
    {
        Object* o = reinterpret_cast<Object*>(_this.GetGASRefCountBase());
        if ((static_cast<UInt8>(static_cast<UPInt>(o->GetTraits().Flags) >> 1) & 1) != 0 && prop_name.ContainsNamespace(vm.GetPublicNamespace()))
        {
            o->AddDynamicSlotValuePair(prop_name.Name, value);
            return CheckResult(true);
        }
    }
    vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x420), vm, prop_name.Name, vm.GetValueTraits(_this).GetName().ToCStr()));
    return CheckResult(false);
}
// @0x142528810
char* Sfr27SetPropertyOfValue(char* ret, VM* vm, const Value* obj, const Multiname* mn, const Value* v)
{
    new (ret) CheckResult(Sfr31SetPropertyInl(*vm, *obj, *mn, *v));
    return ret;
}

// A run-time multiname taken from a QName object: its name and namespace.
// @0x1425273b0
__declspec(noinline) void Sfr27MultinameFromQName(Multiname* mn, const Value* v)
{
    const UPInt q = reinterpret_cast<UPInt>(v->GetGASRefCountBase());
    mn->Name.Assign(*reinterpret_cast<const ASString*>(q + 0x38));
    if (mn->Name.GetKind() == Value::kString)
    {
        ASString name(mn->Name.AsString());
        if (name.GetSize() != 0 && name.GetBuffer()[0] == '*')
            mn->Name.Assign(name.GetManager()->CreateEmptyString());
    }
    mn->Obj = reinterpret_cast<GASRefCountBase*>(*reinterpret_cast<UPInt*>(q + 0x40));
    *reinterpret_cast<UInt32*>(mn) &= 0xfffffff9;
}

// @0x142528cc0
void Multiname::SetRTNameUnsafe(const Value& v)
{
    const UInt32 k = static_cast<UInt32>(v.GetKind());
    if (k - 0xc <= 3 && v.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(v.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
        {
            Sfr27MultinameFromQName(this, &v);
            return;
        }
    }
    Name.AssignUnsafe(v);
    PostProcessName(false);
}

// Multiname::PostProcessName(false) (0x14251cef0, sfr_as3_18), as the exe inlines it into the constructor below.
static __forceinline void Sfr19PostProcessName(Multiname& mn)
{
    if (!mn.Name.IsString())
        return;
    ASString n = mn.Name.AsString();
    if (n.GetSize() == 0)
        return;
    ASStringManager* sm = n.GetManager();
    // the two renames to the empty name share one assignment
    if (n[0] == '*')
        goto empty_name;
    if (n[0] == '@')
    {
        mn.Kind = static_cast<Abc::MultinameKind>(mn.Kind | 8);
        if (n.GetSize() == 2 && n[1] == '*')
        {
        empty_name:
            FUN_1424e0d40(mn.Name, ASString(sm->GetEmptyStringNode()));
        }
        else
            FUN_1424e0d40(mn.Name, ASString(n.SubstringNode(1, n.GetSize())));
    }
}

// Multiname(Namespace&, const Value&) (0x1424d8a90, sfr_as3_15) with SetRTNameUnsafe and PostProcessName, as the
// exe inlines them into exec_in.
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
    Sfr19PostProcessName(*this);
}



// setslot for objects whose slots follow the traits' first own slot.
// @0x1425402a0
void Sfr27ExecSetOwnSlot(VM* vm, UInt32 slot)
{
    ExecReadValueObject args(*vm);
    if (vm->IsException())
        return;
    Object* obj = reinterpret_cast<Object*>(args.ArgObject.GetGASRefCountBase());
    char result;    // the setter's CheckResult return slot, not read
    Sfr27SlotSetValueObj(&ExecGlobalSlotOf(obj, slot), &result, &obj->GetVM(), &args.ArgValue, obj);
}

// initslot: setslot with read-only checks off (the VM is counted as inside an initializer).
// @0x14253b420
void Sfr27ExecInitSlot(VM* vm, SPInt slot)
{
    ExecReadValueObject args(*vm);
    if (vm->IsException())
        return;
    int& inInitializer = *reinterpret_cast<int*>(reinterpret_cast<UPInt>(vm) + 0x30);
    ++inInitializer;
    Object* obj = reinterpret_cast<Object*>(args.ArgObject.GetGASRefCountBase());
    char result;    // the setter's CheckResult return slot, not read
    Sfr27SlotSetValueObj(&ExecSlotInfo(obj->GetTraits(), AbsoluteIndex(slot - 1)), &result, &obj->GetVM(), &args.ArgValue, obj);
    --inInitializer;
}


// Makes room for n more values, moving to a new page when the current one is full.
// @0x1425241f0
void ValueStack::Reserve(UInt16 n)
{
    if (pCurrent + n < pCurrentPage->Values + pCurrentPage->PageSize)
    {
        pStack = pCurrent + 1;
    }
    else
    {
        Page* p = NewPage(n);

        p->pNext = NULL;
        p->pPrev = pCurrentPage;
        pCurrentPage->pNext = p;

        pCurrentPage->pCurrent = pCurrent;
        pCurrentPage->pFirst = pStack;

        pCurrentPage = p;

        pStack = pCurrentPage->Values;
        pCurrent = pCurrentPage->Values;
        --pCurrent;
    }
    ReservedNum = n;
    ++pCurrentPage->ReservationNum;
}

// Reserves the num registers of a new call frame.
// @0x1425240e0
void ValueRegisterFile::Reserve(UInt16 num)
{
    UInt16 currSize = 0;

    if (Unk00 + num <= pCurrentPage->PageSize)
    {
        currSize = static_cast<UInt16>(Unk00 - (pRF - pCurrentPage->Values));
        pRF = pCurrentPage->Values + Unk00;
        Unk00 = Unk00 + num;
    }
    else
    {
        Page* p = NewPage(num);

        p->pNext = NULL;
        p->pPrev = pCurrentPage;
        pCurrentPage->pNext = p;
        pCurrentPage->ReservedNum = Unk00;
        pCurrentPage->pCurrent = pRF;
        pCurrentPage = p;

        pRF = pCurrentPage->Values;
        Unk00 = num;
    }

    Page* page = pCurrentPage;
    GetReservations(page)[page->CurrPos++] = currSize;

    for (UInt32 i = 0; i < num; ++i)
        Construct<Value>(pRF + i);
}


// The class traits registered under name and namespace; looked up in the global object's classes on a miss
// (and then cached).
void FUN_1424e5e80(TClassTraitsCache* self, const ASString& name, const Instances::Namespace& ns,
                   ClassTraits::Traits* const& v);   // TClassTraitsCache::Add, out of line (sfr_as3_16z)

// @0x1425251e0
ClassTraits::Traits* Sfr27GetClassTraitsByName(VM* vm, const ASString* name, const Instances::Namespace* ns)
{
    TClassTraitsCache* set = &vm->ClassTraitsSet;
    ClassTraits::Traits** found = FUN_142414ac0(set, *name, *ns);
    if (found != NULL && *found != NULL)
        return *found;
    ClassTraits::Traits* ct = FUN_142415520(reinterpret_cast<void*>(VmRd(vm, 0x298)), name, ns);
    ClassTraits::Traits* added = ct;
    if (ct == NULL)
        return NULL;
    FUN_1424e5e80(set, *name, *ns, added);
    return ct;
}


// The traits' slot ind receives v for obj (the exe expands Slots::GetSlotInfo here, as ExecSlotInfo does).
// @0x142529eb0
__declspec(noinline) char* Sfr27TraitsSetSlotValue(Traits* tr, char* ret, SPInt ind, Value* v, Object* obj)
{
    Sfr27SlotSetValueObj(&ExecSlotInfo(*tr, AbsoluteIndex(ind)), ret, &tr->GetVM(), v, obj);
    return ret;
}

// Object slot number slot (1-based, counted from the traits' first own slot) receives v.
// @0x142528f80
char* Sfr27ObjectSetSlotValue(Object* obj, char* ret, UInt32 slot, Value* v)
{
    Traits& tr = obj->GetTraits();
    Sfr27TraitsSetSlotValue(&tr, ret, static_cast<SPInt>(slot) - 1 + static_cast<UInt32>(tr.FirstOwnSlotInd.Get()), v, obj);
    return ret;
}

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// AS3 Array object: sets its length (GFx::Value::ObjectInterface::SetArraySize).
// @0x1425265d0
bool AS3ValueObjectInterface::SetArraySize(void* pdata, unsigned size)
{
    using namespace AS3;
    const UPInt obj = reinterpret_cast<UPInt>(pdata);
    reinterpret_cast<Instances::fl::Array*>(obj)->Resize(size);
    return true;
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {

// The tag bits an object address carries for this value (no exe address of its own: inlined everywhere).
Value::ObjectTag Value::GetObjectTag() const
{
    switch (GetKind())
    {
    case kFunction:  return otFunction;
    case kObject:    return otObject;
    case kClass:     return otClass;
    case kNamespace: return otNamespace;
    default:         break;
    }
    return otInvalid;
}

void STPtr::AddRef() const
{
    if (pObject)
        GetRawAddr()->AddRef();
}

// A pointer the collector killed (bit 0 set; the object is already freed) is only untagged, not released
// (exe STPtr::SetValue 0x14252a640: and ~6; test cl,1; jne skip).
void STPtr::Release() const
{
    if (pObject)
    {
        ObjType* addr = GetAddrNoTag();
        if ((UPInt)addr & 1)
            pObject = (ObjType*)((UPInt)addr - 1 + GetObjectTag((UPInt)pObject));
        else
            addr->Release();
    }
}


// The button's up state receives obj.
// @0x14252a4e0
void AvmButton::SetUpStateObject(DisplayObject* ch) { Scaleform::GFx::AS3::Sfr31ButtonSetStateObject(reinterpret_cast<Scaleform::UPInt>(this), 0, reinterpret_cast<Scaleform::UPInt>(ch)); }

// The same for the over state.
// @0x1425287b0
void AvmButton::SetOverStateObject(DisplayObject* ch) { Scaleform::GFx::AS3::Sfr31ButtonSetStateObject(reinterpret_cast<Scaleform::UPInt>(this), 1, reinterpret_cast<Scaleform::UPInt>(ch)); }

// The same for the down state.
// @0x1425272f0
void AvmButton::SetDownStateObject(DisplayObject* ch) { Scaleform::GFx::AS3::Sfr31ButtonSetStateObject(reinterpret_cast<Scaleform::UPInt>(this), 2, reinterpret_cast<Scaleform::UPInt>(ch)); }

// The same for the hit-test state.
// @0x142527490
void AvmButton::SetHitStateObject(DisplayObject* ch) { Scaleform::GFx::AS3::Sfr31ButtonSetStateObject(reinterpret_cast<Scaleform::UPInt>(this), 3, reinterpret_cast<Scaleform::UPInt>(ch)); }

// Two bounds with -1 meaning the default (0 and 1000); the second is stored twice.
// @0x1425287c0
void ASRefCountCollector::SetParams(unsigned lo, unsigned hi)
{
    char* const self = reinterpret_cast<char*>(this);
    if (lo != -1)
        *reinterpret_cast<int*>(self + 0xac) = lo;
    else
        *reinterpret_cast<int*>(self + 0xac) = 0;
    if (hi != -1)
        *reinterpret_cast<int*>(self + 0xa8) = *reinterpret_cast<int*>(self + 0x8c) = hi;
    else
        *reinterpret_cast<int*>(self + 0xa8) = *reinterpret_cast<int*>(self + 0x8c) = 1000;
}

// Hands arg to the helper with the table 200 bytes into the file's constant block.
// @0x142531510
void Sfr31HandOffToFileBlock(UPInt self, UPInt arg)
{
    FUN_1424ffc10(self, *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x20) + 0x78) + 0x10) + 200,
                  arg, 0, 0);
}

// Calls the helper object's virtual 0x58 with the owner and its +0x50 field (result discarded).
// @0x142538810
void Sfr31CallHelperVirtual(UPInt self)
{
    typedef void (*Fn)(UPInt helper, void* ret, UPInt owner, UPInt arg);
    UPInt helper = *reinterpret_cast<UPInt*>(self + 0x40);
    UPInt ret;
    (*reinterpret_cast<Fn*>(*reinterpret_cast<UPInt*>(helper) + 0x58))(helper, &ret, self, *reinterpret_cast<UPInt*>(self + 0x50));
}

// Flags the object (virtual 0x30 with 0x20000) after the global init helper, and caches its field 0x60.
// @0x142524350
void Sfr31FlagAndCacheField(UPInt self, UPInt* obj)
{
    typedef void (*Fn)(UPInt* obj, int flags);
    FUN_1424f03f0(reinterpret_cast<unsigned char*>(self), obj);
    (*reinterpret_cast<Fn*>(*obj + 0x30))(obj, 0x20000);
    *reinterpret_cast<UPInt*>(self + 0x28) = obj[0xc];
}


// Stage::SetOrientation: the orientation string (+0x120) is replaced.
// @0x142528770
void Stage::SetOrientation(const ASString& orientation)
{
    *reinterpret_cast<ASString*>(reinterpret_cast<char*>(this) + 0x120) = orientation;
}

// ShapeDataInterface::SkipPathData: reads (virtual 0x48) until it reports the end.
// @0x14252c850
void Sfr31SkipPathData(UPInt self, void* pos)
{
    typedef int (*Fn)(UPInt self, void* pos, void* out);
    char out[24];
    while ((*reinterpret_cast<Fn*>(*reinterpret_cast<UPInt*>(self) + 0x48))(self, pos, out) != 0)
    {
    }
}


// Stores np into a tagged GC reference slot (odd values are weak marks); the old target is released.
static void Sfr31AssignGcRef(UPInt* slot, UPInt np)
{
    if (np != *slot)
    {
        const UPInt old = *slot;
        if (old != 0)
        {
            if ((old & 1) != 0)
                *slot = old - 1;
            else
            {
                UInt32* rc = reinterpret_cast<UInt32*>(old + 0x10);
                if ((*rc & 0x3fffff) != 0)
                {
                    --*rc;
                    FUN_1423dfa20(reinterpret_cast<void*>(old));
                }
            }
        }
        if (np != 0)
        {
            UInt32* rc = reinterpret_cast<UInt32*>(np + 0x10);
            *rc = (*rc + 1) & 0x8fbfffff;
        }
        *slot = np;
    }
}

// Stores the new GC reference at +8 and clears the word after it.
// @0x142526340
void AvmDisplayObj::SetAS3ObjCollectible(Instances::fl_display::DisplayObject* p)
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    const UPInt np = reinterpret_cast<UPInt>(p);
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 8), np);
    *reinterpret_cast<UPInt*>(self + 0x10) = 0;
}

// Stores the new GC reference at +8 and clears the two low flag bits of the first word.
// @0x142528d20
void Sfr31SetGcRefClearFlags(UInt32* self, UPInt np)
{
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 2), np);
    *self &= 0xfffffffc;
}

// Stores the new GC reference at +8.
// @0x142540bd0
void Sfr31SetGcRef(UPInt self, UPInt np)
{
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 8), np);
}

// Replaces the resource at +0xc0 (the new one is referenced first).
// @0x1425274b0
void Sfr31SetResource(UPInt self, Resource* res)
{
    if (res)
        res->AddRef();
    Resource*& cur = *reinterpret_cast<Resource**>(self + 0xc0);
    if (cur)
        cur->Release();
    cur = res;
}

// AvmBitmap::SetResourceMovieDef: the movie def (a resource) at +0xc8 is replaced.
// @0x142528e70
void AvmBitmap::SetResourceMovieDef(MovieDefImpl* pdefImpl)
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    Resource* def = reinterpret_cast<Resource*>(pdefImpl);
    if (def)
        def->AddRef();
    Resource*& cur = *reinterpret_cast<Resource**>(self + 0xc8);
    if (cur)
        cur->Release();
    cur = def;
}

// The copy/rename helpers are shared out-of-line code.
// @0x142528f20
void Slots::SetSlotInfo(AbsoluteIndex ind, const ASString& k, const SlotInfo& v)
{
    FUN_1424e0b80(&VArray[static_cast<UInt32>(ind.Get()) - FirstOwnSlotNum].Value, &v);
    SetKey(ind, k);
}

// Tracer::SkipOrigOpCode: a position inside the code gets its register state noted before moving on.
// @0x14252c7e0
void Sfr31TracerSkipOrigOpCode(UPInt tracer, UPInt* pos, UPInt next)
{
    if (*pos < *reinterpret_cast<UPInt*>(tracer + 0x58))
    {
        FUN_14251f710(tracer + 0x70, pos);
        *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(tracer + 0xd0) + *pos * 8) =
            *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(tracer + 0x28) + 8);
    }
    *pos = next;
}


// Re-reads the autosize flags of the text field (+0x18) into its document view and marks it dirty.
// The text field view: IsAutoSize / IsWordWrap as the SDK's inline TextField accessors.
struct Sfr31AutosizeTextField
{
    UInt8 pad0[0xe0];
    UInt8* pDocument;   // +0xe0
    UInt8 pad1[0xfc - 0xe8];
    UInt32 Flags;       // +0xfc
    bool IsAutoSize() const { return (Flags & 1) != 0; }
    bool IsWordWrap() const { return (pDocument[0x149] & 8) != 0; }
};

// AvmTextField::UpdateAutosizeSettings.
// @0x142530fc0
void Sfr31UpdateAutosizeSettings(UPInt self)
{
    Sfr31AutosizeTextField* ptf = *reinterpret_cast<Sfr31AutosizeTextField**>(self + 0x18);
    const bool autoSizeByX = (ptf->IsAutoSize() && !ptf->IsWordWrap());
    const bool autoSizeByY = (ptf->IsAutoSize());
    if (autoSizeByX)
        FUN_1426150b0(reinterpret_cast<UPInt>(ptf->pDocument));
    else
        ptf->pDocument[0x149] &= 0xfe;
    if (autoSizeByY)
        FUN_1426150d0(reinterpret_cast<UPInt>(ptf->pDocument));
    else
        ptf->pDocument[0x149] &= 0xfd;
    ptf->Flags |= 0x2000;
    FUN_1425bc060(reinterpret_cast<UPInt>(ptf));
}

// TR::Block::GetFrom: the code offset the block starts at (+0x20).
static SF_INLINE UPInt Sfr31TrBlockFrom(const TR::Block& b) { return *reinterpret_cast<const UPInt*>(reinterpret_cast<const UInt8*>(&b) + 0x20); }
// Tracer::GetBlock: the last block that does not start after offset.
static SF_INLINE TR::Block* Sfr31TrGetBlock(TR::Block* block, UPInt offset)
{
    while (block != NULL && offset < Sfr31TrBlockFrom(*block))
        block = block->pPrev;
    return block;
}

// Tracer::UpdateBlock: entering the block that starts at bcp makes it the current one; its entry state is joined
// from the previous block's (InitializeBlock) or, once initialized, merged with it (false when MergeBlock throws).
// @0x142531040
CheckResult Tracer::UpdateBlock(UPInt bcp)
{
    const TR::Block& prevBlock = *CurrBlock;
    TR::Block* nextBlock = Sfr31TrGetBlock(Blocks.pPrev, bcp);

    if (nextBlock && Sfr31TrBlockFrom(*nextBlock) == bcp)
    {
        TR::Block* pBlock = nextBlock;
        CurrBlock = pBlock;
        if (pBlock->Flags & 1)
        {
            if (pBlock != &prevBlock)
            {
                if (!MergeBlock(*pBlock, prevBlock))
                    return false;
            }
        }
        else
            InitializeBlock(*pBlock, prevBlock);
    }

    return true;
}

// Runs the shutdown of every registered entry (+0x2c0 array of +0x2c8 items), then empties the array.
// @0x142530d50
void Sfr31ShutdownRegistered(UPInt self)
{
    const UPInt n = *reinterpret_cast<UPInt*>(self + 0x2c8);
    const UInt8 saved = *reinterpret_cast<UInt8*>(self + 9);
    *reinterpret_cast<UInt8*>(self + 9) = 1;
    for (UPInt i = 0; i < n; ++i)
        FUN_1425303b0(reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x2c0))[i]);
    FUN_1424ef2a0(self + 0x2c0);
    *reinterpret_cast<UInt8*>(self + 9) = saved;
}

// Runs the slot (kind bits 5..9 are not a getter unless the caller asked for one) through the invoke helper.
// The ASString copy is written as a node pointer whose copy is passed (as the const ASString& of VTable::SetMethod):
// with a real ASString local the exe's rbx-kept node is reloaded after the call, since the callee chain makes an
// indirect call (String dtor) and an escaped local is reloaded.
// @0x1425311c0
__declspec(noinline) void Traits::UpdateVT(const SlotInfo& si, const Value& v, SlotInfo::BindingType argc)
{
    const UPInt traits = FUN_14250fa80(reinterpret_cast<UPInt>(this));
    const SPInt index = si.ValueInd;
    const SInt32 bt = si.BindType;
    if (bt != SlotInfo::BT_Code || argc == bt)
    {
        ASStringNode* const node = si.Name.GetPtr();   // ASString name(node): the copy below holds it, node stays in a register
        ASStringNode* name = node; node->AddRef();
        reinterpret_cast<VTable*>(traits)->SetMethod(AbsoluteIndex(index), v, argc, reinterpret_cast<const ASString&>(name)); node->Release();
    }
}

// Looks the name up in the own slots and invokes the newest one whose namespace is an interface namespace. The
// slot comes from the inline Slots::GetSlotInfo (ExecSlotInfo); the previous index from GetPrevSlotIndex one level in.
// @0x1425310e0
void Traits::UpdateVT4IM(const ASString& name, const Instances::Namespace& ns, const Value& v, SlotInfo::BindingType argc)
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    if (reinterpret_cast<UPInt>(&ns) != *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x78) + 0x1d0))
        return;
    const Slots& slots = *reinterpret_cast<const Slots*>(self + 0x20);
    SPInt i = *slots.FindSlotValues(name);
    do
    {
        const SlotInfo* si = &ExecSlotInfo(slots, AbsoluteIndex(i));
        if (reinterpret_cast<const Instances::Namespace* const*>(si)[1]->GetIsInterface())   // pNs
        {
            UpdateVT(*si, v, argc);
            return;
        }
        if (static_cast<UPInt>(i) < slots.FirstOwnSlotNum)
            i = slots.Parent->GetPrevSlotIndex(i);
        else
            i = slots.VArray[i - slots.FirstOwnSlotNum].Prev;
    } while (i >= 0);
}


// TR::State::SwapOp: the two topmost operand stack values trade places (State::OpStack at +0x38). The top index is
// computed once; the stack data is re-read after each Assign.
// @0x14252e800
void Sfr31StateSwapOp(UPInt state)
{
    ArrayDH<Value>& ops = *reinterpret_cast<ArrayDH<Value>*>(state + 0x38);
    const UPInt i = ops.GetSize() - 1;
    Value top(ops[i]);
    ops[i].Assign(ops[i - 1]);
    ops[i - 1].Assign(top);
}

// AvmDisplayObj::SwitchAS3ObjPtrType: type 1 makes the object reference strong, anything else weak.
// @0x14252e900
void Sfr31SwitchAS3ObjPtrType(UPInt self, int type)
{
    UPInt* strong = reinterpret_cast<UPInt*>(self + 8);
    AvmDisplayObj* avm = reinterpret_cast<AvmDisplayObj*>(self);
    if (type == 1)
    {
        avm->SetAS3ObjCollectible(avm->GetAS3Obj());
        return;
    }
    avm->pAS3RawPtr = avm->GetAS3Obj();
    const UPInt s = *strong;
    if (s != 0)
    {
        if (((s & 1) == 0) && (*reinterpret_cast<UInt32*>(s + 0x10) & 0x3fffff) != 0)
        {
            --*reinterpret_cast<UInt32*>(s + 0x10);
            FUN_1423dfa20(reinterpret_cast<void*>(s));
        }
        *strong = 0;
    }
}

// AvmButton::SwitchState: unless the owner is being destroyed or already removed, the mouse state is
// translated and handed to SwitchStateIntl.
// @0x14252e980
void AvmButton::SwitchState(ButtonRecord::MouseState mouseState)
{
    const UPInt self = reinterpret_cast<UPInt>(this) + 0x40;
    const DisplayObjectBase* owner = *reinterpret_cast<DisplayObjectBase**>(self - 0x28);
    if (!owner->IsUnloaded() && !owner->IsUnloading())
    {
        const int st = FUN_1425de200(mouseState);
        Sfr31ButtonSwitchStateIntl(self - 0x40, st);
    }
}

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// AS3ValueObjectInterface::SetElement: stores the converted value at the array index.
// Raw-offset model.
// @0x142527300
bool AS3ValueObjectInterface::SetElement(void* pdata, unsigned ind, const Value& value)
{
    using namespace AS3;
    const UPInt self = reinterpret_cast<UPInt>(this);
    const UPInt array = reinterpret_cast<UPInt>(pdata);
    const void* gfxValue = &value;
    const UPInt root = *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 8) + 0x18);
    AS3::Value v;
    FUN_1425048d0(root, gfxValue, &v);
    FUN_1424213b0(array + 0x38, ind, &v);
    return true;
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// AS3ValueObjectInterface::ToString: the value's string form is copied into out.
// Raw-offset model.
// @0x14252fd40
void AS3ValueObjectInterface::ToString(String* out, const Value& thisVal) const
{
    using namespace AS3;
    const UPInt self = reinterpret_cast<UPInt>(this);
    const UPInt root = *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 8) + 0x18);
    AS3::Value v;
    FUN_1425048d0(root, &thisVal, &v);
    ASString s(reinterpret_cast<ASStringNode*>(*reinterpret_cast<UPInt*>(root + 0x348) + 0x40));
    v.Convert2String(s);
    out->AssignString(s.ToCStr(), s.GetSize());
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {

}}} // namespace Scaleform::GFx::AS3

// ---- display-object setters and small helpers (sfr31) ----
inline void FUN_1425f4090(void* obj) { static_cast<Scaleform::GFx::DisplayObjectBase*>(obj)->SetDirtyFlag(); }
inline Scaleform::UInt64 FUN_1425e3560(void) { return Scaleform::Timer::GetRawTicks(); }
namespace Scaleform { namespace GFx { unsigned FUN_142622510(char*); } }
inline Scaleform::SInt32 FUN_142622510(Scaleform::UPInt obj) { return static_cast<Scaleform::SInt32>(Scaleform::GFx::FUN_142622510(reinterpret_cast<char*>(obj))); }
namespace Scaleform { namespace GFx { using ::FUN_142622510; } }
namespace Scaleform { namespace GFx { unsigned long long FUN_1426224d0(char*); } }
inline Scaleform::SInt64 FUN_1426224d0(Scaleform::UPInt obj) { return static_cast<Scaleform::SInt64>(Scaleform::GFx::FUN_1426224d0(reinterpret_cast<char*>(obj))); }
namespace Scaleform { namespace GFx { using ::FUN_1426224d0; } }
namespace Scaleform { namespace GFx { void FUN_142623560(char*, unsigned long long); } }
inline void FUN_142623560(Scaleform::UPInt obj, Scaleform::UInt64 delta) { Scaleform::GFx::FUN_142623560(reinterpret_cast<char*>(obj), delta); }
namespace Scaleform { namespace GFx { using ::FUN_142623560; } }
namespace Scaleform { namespace GFx { void FUN_1426244e0(char*, int); } }
inline void FUN_1426244e0(Scaleform::UPInt obj, Scaleform::SInt32 v) { Scaleform::GFx::FUN_1426244e0(reinterpret_cast<char*>(obj), v); }
namespace Scaleform { namespace GFx { using ::FUN_1426244e0; } }
namespace Scaleform { namespace GFx { void FUN_142624450(char*, unsigned long long); } }
inline void FUN_142624450(Scaleform::UPInt obj, Scaleform::SInt64 v) { Scaleform::GFx::FUN_142624450(reinterpret_cast<char*>(obj), static_cast<unsigned long long>(v)); }
namespace Scaleform { namespace GFx { using ::FUN_142624450; } }
inline Scaleform::GFx::AS3::Value* FUN_14250a490(Scaleform::UPInt tracer, Scaleform::GFx::AS3::Value* out, Scaleform::UPInt state) { ::new (static_cast<void*>(out)) Scaleform::GFx::AS3::Value(reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->GetGlobalObject(*reinterpret_cast<const Scaleform::GFx::AS3::TR::State*>(state))); return out; }

namespace Scaleform { namespace GFx {

// @0x1425265f0
void InteractiveObject::SetBlendMode(Render::BlendMode mode)
{
    DisplayObjectBase::SetBlendMode(mode);
    FUN_1425f4090(this);
}

namespace AS3 {

static inline UPInt Sfr31Rd(UPInt base, UPInt off) { return *reinterpret_cast<const UPInt*>(base + off); }
static inline void Sfr31Wr(UPInt base, UPInt off, UPInt v) { *reinterpret_cast<UPInt*>(base + off) = v; }

// @0x1425262e0
void Sfr31AvmDisplayObjSetAS3Obj(UPInt self, UPInt obj)
{
    if (Sfr31Rd(Sfr31Rd(self, 0x18), 0x38) != 0) { reinterpret_cast<AvmDisplayObj*>(self)->SetAS3ObjCollectible(reinterpret_cast<Instances::fl_display::DisplayObject*>(obj)); return; }
    *reinterpret_cast<UPInt*>(self + 0x10) = obj;
    UPInt old = Sfr31Rd(self, 8);
    if (old != 0)
    {
        if (((old & 1) == 0) && ((*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0))
        {
            *reinterpret_cast<UInt32*>(old + 0x10) -= 1;
            FUN_1423dfa20(reinterpret_cast<void*>(old));
        }
        *reinterpret_cast<UPInt*>(self + 8) = 0;
    }
}

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// @0x1425266c0
bool AS3ValueObjectInterface::SetCxform(void* pdata, const Render::Cxform& cxform)
{
    using namespace AS3;
    const UPInt obj = reinterpret_cast<UPInt>(pdata);
    const Render::Cxform* cx = &cxform;
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) != 0))
    {
        DisplayObjectBase* d = *reinterpret_cast<DisplayObjectBase**>(obj + 0x58);
        d->SetCxform(*cx);
        typedef void (*Fn)(void*, SInt32);
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(d), 0), 0x188))(d, 0);
        return true;
    }
    return false;
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {

// TR::State::PushOp (OpStack.PushBack). Going through the inline call puts the OpStack address in rcx before the
// pushed value's in rdx, as in the exe.
static inline void Sfr31StatePushOp(UPInt st, const Value& v)
{
    reinterpret_cast<ArrayDH<Value>*>(st + 0x38)->PushBack(v);
}

// @0x142539420
void Sfr31StatePushTyped(UPInt st)
{
    Sfr31StatePushOp(st, reinterpret_cast<const Tracer*>(Sfr31Rd(st, 0))->GetGlobalObject(*reinterpret_cast<const TR::State*>(st)));
}

// The syncing object: vtable slot 1 returns the render-side object it mirrors to (or null).
struct Sfr31SyncView
{
    virtual void Slot0();
    virtual UPInt GetTarget();
};

// @0x142526430
void Sfr31SyncSetInt(UPInt* self, SInt32 val)
{
    UPInt o = reinterpret_cast<Sfr31SyncView*>(self)->GetTarget();
    if (o != 0 && val != FUN_142622510(o))
    {
        UInt64 t = FUN_1425e3560();
        FUN_142623560(o, t - self[0x38]);
        self[0x38] = t;
        FUN_1426244e0(o, val);
    }
}

// @0x1425263b0
void Sfr31SyncSetInt64(UPInt* self, SInt64 val)
{
    UPInt o = reinterpret_cast<Sfr31SyncView*>(self)->GetTarget();
    if (o != 0 && val != FUN_1426224d0(o))
    {
        UInt64 t = FUN_1425e3560();
        FUN_142623560(o, t - self[0x38]);
        self[0x38] = t;
        FUN_142624450(o, val);
    }
}

// The SDK PropRef::SetSlotValue shape (AS3_Object.cpp): a result flag set per tag, then one store.
// @0x142528fb0
char* Sfr31PropRefSetSlotValue(UPInt self, char* ret, UPInt vm, const Value* v)
{
    // PropRef: the low two bits of the first word tag a SlotInfo (0), a Value (1) or a missing property (2).
    const UPInt w = Sfr31Rd(self, 0);
    char result = 1;
    switch (w & 3)
    {
    case 0:
    {
        char tmp;   // CheckResult
        result = *Sfr27SlotSetValueThis(reinterpret_cast<const SlotInfo*>(w), &tmp, reinterpret_cast<VM*>(vm), v, reinterpret_cast<const Value*>(self + 0x10), 0);
        break;
    }
    case 1:
        reinterpret_cast<Value*>(w & ~UPInt(1))->Assign(*v);
        break;
    case 2:
        result = 0;
        break;
    default:
        break;
    }
    *ret = result;
    return ret;
}

}}} // namespace Scaleform::GFx::AS3

// ---- tracer pushes, display-list index, VM pop/pushundefined (sfr31) ----
namespace Scaleform { namespace GFx { namespace AS3 { InstanceTraits::Traits* Sfr33GetActivationInstanceTraits(VMAbcFile&, const Abc::MethodBodyInfo*, void*); } } }
inline Scaleform::UPInt FUN_142506f00(Scaleform::UPInt link, Scaleform::UPInt traits, Scaleform::GFx::ASString* name) { return reinterpret_cast<Scaleform::UPInt>(Scaleform::GFx::AS3::Sfr33GetActivationInstanceTraits(*reinterpret_cast<Scaleform::GFx::AS3::VMAbcFile*>(link), reinterpret_cast<const Scaleform::GFx::AS3::Abc::MethodBodyInfo*>(traits), name)); }
inline Scaleform::UPInt FUN_14250ae60(Scaleform::UPInt link, Scaleform::UPInt ind) { return reinterpret_cast<Scaleform::UPInt>(&reinterpret_cast<Scaleform::GFx::AS3::VMAbcFile*>(link)->GetInternedNamespace(ind)); }
inline Scaleform::GFx::AS3::Value* FUN_1423ef9b0(Scaleform::GFx::AS3::Value* out, Scaleform::UPInt x) { ::new (static_cast<void*>(out)) Scaleform::GFx::AS3::Value(reinterpret_cast<Scaleform::GFx::AS3::Instances::Namespace*>(x)); return out; }
namespace Scaleform { namespace GFx { namespace AS3 { const ClassTraits::Traits* FUN_14250d760(VM&, const Multiname&); } } }
inline Scaleform::UPInt FUN_14250d760(Scaleform::UPInt root, Scaleform::UPInt pos) { return reinterpret_cast<Scaleform::UPInt>(Scaleform::GFx::AS3::FUN_14250d760(*reinterpret_cast<Scaleform::GFx::AS3::VM*>(root), *reinterpret_cast<const Scaleform::GFx::AS3::Multiname*>(pos))); }
namespace Scaleform { namespace GFx { namespace AS3 { using ::FUN_14250d760; } } }
inline void FUN_14257dcd0(void* obj) { static_cast<const Scaleform::RefCountNTSImpl*>(obj)->Release(); }
void FUN_1424efe30(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* a, Scaleform::GFx::AS3::Value* b);

namespace Scaleform { namespace GFx { namespace AS3 {

// A tracer value holding a pointer at +0x10 (the exe stores the kind and clears the second word).
struct TrPtrScratch
{
    TrPtrScratch(UInt32 kind) { w1 = 0; w0 = kind; }
    TrPtrScratch(UInt32 kind, UPInt p) { w1 = 0; w2 = p; w0 = kind; }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1, w2, w3;
};

// @0x14253be60
void Sfr31StatePushNs(UPInt st)
{
    UPInt ns;
    {
        ASString name(reinterpret_cast<ASStringNode*>(Sfr31Rd(Sfr31Rd(Sfr31Rd(st, 0), 0x20), 0x70)));
        const UPInt own = Sfr31Rd(Sfr31Rd(st, 0), 0x20);
        const UPInt link = Sfr31Rd(own, 0x28);
        ns = FUN_142506f00(link, *reinterpret_cast<const UPInt*>(Sfr31Rd(Sfr31Rd(link, 0x28), 0x170) + static_cast<SPInt>(*reinterpret_cast<const SInt32*>(own + 0x30)) * 8), &name);
    }
    TrPtrScratch t(8, ns);
    reinterpret_cast<TR::State*>(st)->GetOpStack().PushBack(t.Get());
}

// @0x14253f410
void Sfr31StatePushPool(UPInt st, UInt32 ind)
{
    FUN_14251fcd0(Sfr31Rd(st, 0), ind);
    Instances::Namespace* ns = reinterpret_cast<Instances::Namespace*>(FUN_14250ae60(Sfr31Rd(Sfr31Rd(Sfr31Rd(st, 0), 0x20), 0x28), ind));
    Sfr31StatePushOp(st, Value(ns));
}

// Instance traits seen through their vtable: slot 16 (+0x80) is the subtype test.
#define SFR31_VPAD4(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3();
struct Sfr31TraitsVtView
{
    SFR31_VPAD4(a) SFR31_VPAD4(b) SFR31_VPAD4(c) SFR31_VPAD4(d)
    virtual char IsSubtypeOf(UPInt tr);
};

// CTraits::SupportsInterface: a recorded interface's traits equal to, or derived from, tr (state array at +0xd0, 0x30 bytes each).
// @0x14252e480
bool InstanceTraits::CTraits::SupportsInterface(const InstanceTraits::Traits& other) const
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    const UPInt tr = reinterpret_cast<UPInt>(&other);
    const UPInt root = Sfr31Rd(self, 0x78);
    for (UPInt i = 0; i < Sfr31Rd(self, 0xd8); ++i)
    {
        UPInt t = FUN_14250d760(root, Sfr31Rd(self, 0xd0) + i * 0x30);
        if (t != 0)
        {
            UPInt p = Sfr31Rd(t, 0xc0);
            if (p == tr || reinterpret_cast<Sfr31TraitsVtView*>(p)->IsSubtypeOf(tr) != 0)
                return true;
        }
    }
    return false;
}

// ASUserData view: SetLastObjectValue is a member call (exe 0x142575f10).
struct Sfr31UserDataView
{
    void FUN_142575f10(UPInt movie, UPInt owner, bool isdobj)
    {
        ::Scaleform::GFx::ASUserData_SetLastObjectValue(reinterpret_cast<::Scaleform::GFx::ASUserData*>(this),
            reinterpret_cast<void*>(movie), reinterpret_cast<void*>(owner), isdobj);
    }
};

// Instances::fl::Object view: pUserDataHolder at +0x30.
struct Sfr31ObjectUserDataView
{
    UInt8 Pad[0x30];
    UPInt* pUserDataHolder;
    void SetUserData(UPInt pmovieView, UPInt puserData, bool isdobj);
};

// Object::SetUserData: replace the 16-byte holder {movie, userdata}; the user data records this object.
// @0x14252a5a0
void Sfr31ObjectUserDataView::SetUserData(UPInt pmovieView, UPInt puserData, bool isdobj)
{
    if (pUserDataHolder != 0)
        Memory::pGlobalHeap->Free(pUserDataHolder);
    AllocInfo ai(0x151, 0, 0);   // StatMV_VM_Instance_Mem, as in AS3ValueObjectInterface::SetUserData
    UPInt* h = static_cast<UPInt*>(Memory::pGlobalHeap->AllocAutoHeap(this, 0x10, &ai));
    if (h != 0) { h[0] = pmovieView; h[1] = puserData; }
    pUserDataHolder = h;
    if (puserData != 0)
        reinterpret_cast<Sfr31UserDataView*>(puserData)->FUN_142575f10(Sfr31Rd(pmovieView, 0x38), reinterpret_cast<UPInt>(this), isdobj);
}

} // namespace AS3

// AS3ValueObjectInterface::SetUserData (vftable slot 36): the AS3 object pdata gets a new {movie, user data} holder.
// @0x14252a4f0
void AS3ValueObjectInterface::SetUserData(void* pdata, ASUserData* puserdata, bool isdobj)
{
    using namespace AS3;
    const UPInt self = reinterpret_cast<UPInt>(pdata);
    const UPInt b = reinterpret_cast<UPInt>(puserdata);
    if (self != 0)
    {
        const UPInt a = reinterpret_cast<UPInt>(pMovieRoot);
        if (Sfr31Rd(self, 0x30) != 0)
            Memory::pGlobalHeap->Free(reinterpret_cast<void*>(Sfr31Rd(self, 0x30)));
        AllocInfo ai(0x151, 0, 0);
        UPInt* h = static_cast<UPInt*>(Memory::pGlobalHeap->AllocAutoHeap(reinterpret_cast<void*>(self), 0x10, &ai));
        if (h != 0) { h[0] = a; h[1] = b; }
        *reinterpret_cast<UPInt**>(self + 0x30) = h;
        if (b != 0)
            reinterpret_cast<Sfr31UserDataView*>(b)->FUN_142575f10(Sfr31Rd(a, 0x38), self, isdobj);
    }
}

namespace AS3 {

// @0x142526610
bool AvmDisplayObjContainer::SetChildIndex(DisplayObjectBase* ch, unsigned index)
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    const UPInt holder = Sfr31Rd(self, 0x18);
    if (index < *reinterpret_cast<const UInt32*>(holder + 0xe0))
    {
        DisplayList* dl = reinterpret_cast<DisplayList*>(holder + 0xd8);
        SPInt at = dl->FindDisplayIndex(ch);
        if (at >= 0)
        {
            if (ch != 0)
                ++*reinterpret_cast<SInt32*>(reinterpret_cast<UPInt>(ch) + 8);
            dl->RemoveEntryAtIndex(reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(self, 0x18)), static_cast<UPInt>(at));
            dl->AddEntryAtIndex(reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(self, 0x18)), index, ch);
            typedef void (*Fn)(void*, SInt32);
            reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(ch), 0), 0x188))(ch, 0);
            *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(ch) + 0x30) = 0;
            *reinterpret_cast<SInt32*>(reinterpret_cast<UPInt>(ch) + 0x2c) = -1;
            *(reinterpret_cast<UInt8*>(dl) + 0x28) |= 3;
            FUN_14257dcd0(ch);
            return true;
        }
    }
    return false;
}

// pop: with a running frame flag clear the exe's slow helper pops, otherwise the top is released inline.
// @0x14253f920
void Sfr31ExecPop(VM* vm)
{
    const UPInt i = VmRd(vm, 0x78) - 1;
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    if (*reinterpret_cast<const char*>((i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8)) != 0)
    {
        Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
        cur->~Value();
        --cur;
    }
    else
        FUN_1424efe30(vm, top, top);
}

// @0x14253f9e0
void Sfr31ExecPushUndefined(VM* vm)
{
    const UPInt i = VmRd(vm, 0x78) - 1;
    if (*reinterpret_cast<const char*>((i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8)) == 0)
        ExecPushCopy(vm, Value::GetUndefined());
}


}}} // namespace Scaleform::GFx::AS3

// ---- tracer pops with ReadArgs, TextField text, invoke alias, cursor type, action queue (sfr31) ----
namespace Scaleform { namespace GFx { namespace AS3 {
using namespace TR;

// The exe compiled TR::ReadArgs::ReadArgs and ~ReadArgs (0x1424d9640, 0x1424dea90; ours in sfr_as3_15) in this TU, so
// it keeps the popped object's Flags in ebx across the weak-ref Free; MS2_AS3_READARGS_NOALIAS gives the same shape.
// @0x142537710
void Sfr31TraceCallPop(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsObject args(*reinterpret_cast<VM*>(TrVM(s.Tracer())), *st, argc);
}

// The tracer's ReadValue and ReadValueObject (inlined in the exe): each popped value bumps the read count.
struct TrReadValue : public TR::StackReader
{
    TrReadValue(VM& vm, State& st) : TR::StackReader(vm, st), ArgValue(st.PopOpValue())
    {
        ++Num;
    }
    Value ArgValue;
};

struct TrReadValueObject : public TrReadValue
{
    TrReadValueObject(VM& vm, State& st) : TrReadValue(vm, st), ArgObject(st.PopOpValue())
    {
        ++Num;
    }
    Value ArgObject;
};

// @0x1425401a0
void Sfr31TracePop2Note(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), arg);
    TrReadValueObject args(*reinterpret_cast<VM*>(TrVM(s.Tracer())), *st);
}

// setInterval/setTimeout: appends the extra call arguments to the IntervalTimer's Params (ArrayLH<Value> at +0x38).
// The callers are setInterval (0x14242a1a4) and setTimeout (0x14242af14).
// @0x1425264b0
void IntervalTimer::SetArguments(unsigned num, const Value* argArr)
{
    for (unsigned i = 0; i < num; ++i)
        Params.PushBack(argArr[i]);
}

// @0x142540a90
const MovieRoot::ActionEntry* MovieRoot::ActionQueueIterator::getNext()
{
    if (pActionQueue->ModId != ModId)
    {
        // new actions were added - restart
        ModId = pActionQueue->ModId;
        pCurEntry = (pRootEntry) ? pRootEntry->pNextEntry : pActionQueue->Entries[Level].pActionRoot;
    }

    ActionEntry* pentry = pCurEntry;
    if (pCurEntry)
    {
        if (pCurEntry == pActionQueue->Entries[Level].pInsertEntry)
        {
            if (pCurEntry->pNextEntry)
                pActionQueue->Entries[Level].pInsertEntry = pCurEntry->pNextEntry;
            else
                pActionQueue->Entries[Level].pInsertEntry = pRootEntry;
        }
        if (pCurEntry == pActionQueue->Entries[Level].pActionRoot)
            pActionQueue->Entries[Level].pActionRoot = pCurEntry->pNextEntry;
        else if (pRootEntry)
            pRootEntry->pNextEntry = pCurEntry->pNextEntry;
        pCurEntry = pCurEntry->pNextEntry;
    }
    if (pActionQueue->Entries[Level].pActionRoot == NULL)
    {
        pActionQueue->Entries[Level].pInsertEntry = NULL;
        pActionQueue->Entries[Level].pLastEntry = NULL;
    }
    if (pLastEntry)
    {
        pLastEntry->pNextEntry = NULL;
        pActionQueue->AddToFreeList(pLastEntry); // release entry
        ++pActionQueue->ModId;
        ModId = pActionQueue->ModId;
    }
    pLastEntry = pentry;
    return pentry;
}

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// A text assignment through the host interface: TextFields take it directly, anything else gets text/htmlText.
// @0x14252a360
bool AS3ValueObjectInterface::SetText(void* pdata, const wchar_t* text, bool html)
{
    using namespace AS3;
    UPInt* self = reinterpret_cast<UPInt*>(this);
    const UPInt obj = reinterpret_cast<UPInt>(pdata);
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) != 0))
    {
        TextField* tf = *reinterpret_cast<TextField**>(obj + 0x58);
        typedef SInt32 (*Kind)(void*);
        if ((*reinterpret_cast<Kind* const*>(tf))[0x258 / 8](tf) != 4)
        {
            struct RawGfxValue { UPInt iface; UInt32 type; const wchar_t* str; } v = { 0, 7, text };
            typedef bool (*Set)(void*, UPInt, const char*, void*, bool);
            bool r = (*reinterpret_cast<Set* const*>(self))[0x28 / 8](self, obj, html ? "htmlText" : "text", &v, true);
            if ((static_cast<UByte>(v.type >> 6) & 1) != 0)
            {
                typedef void (*Rel)(void*, void*, const wchar_t*);
                (*reinterpret_cast<Rel* const*>(v.iface))[0x10 / 8](reinterpret_cast<void*>(v.iface), &v, v.str);
            }
            return r;
        }
        tf->SetText(text, html);
        return true;
    }
    return false;
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {

// The alias table is a HashSet of (ASString, Value) pairs; the lookup is the SDK's findIndexCore.
struct Sfr31AliasEntry
{
    SPInt NextInChain;
    ASStringNode* Key;
    UPInt Rest[4];
};
struct Sfr31AliasTable
{
    UPInt EntryCount;
    UPInt SizeMask;
    Sfr31AliasEntry& E(UPInt index) { return reinterpret_cast<Sfr31AliasEntry*>(this + 1)[index]; }
};

static inline SPInt Sfr31AliasFindIndexCore(const Sfr31AliasTable* pTable, ASStringNode* const& key, UPInt hashValue)
{
    UPInt index = hashValue;
    const Sfr31AliasEntry* e = &const_cast<Sfr31AliasTable*>(pTable)->E(index);
    if (e->NextInChain == -2 || (e->Key->HashFlags & pTable->SizeMask) != index)
        return -1;
    for (;;)
    {
        if ((e->Key->HashFlags & pTable->SizeMask) == hashValue && e->Key == key)
            return index;
        index = e->NextInChain;
        if (index == UPInt(-1))
            break;
        e = &const_cast<Sfr31AliasTable*>(pTable)->E(index);
    }
    return -1;
}

static inline SPInt Sfr31AliasFindIndex(Sfr31AliasTable* pTable, ASStringNode* const& key)
{
    if (!pTable)
        return -1;
    const UPInt hashValue = key->HashFlags & pTable->SizeMask;
    return Sfr31AliasFindIndexCore(pTable, key, hashValue);
}

// @0x142525400
Value* Sfr31ResolveInvokeAlias(UPInt root, const char* name)
{
    if (Sfr31Rd(root, 0x80) != 0)
    {
        ASString key(reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateStringNode(name));
        Sfr31AliasTable* const tbl = *reinterpret_cast<Sfr31AliasTable**>(Sfr31Rd(root, 0x80));
        const SPInt index = Sfr31AliasFindIndex(tbl, key.GetNode());
        const UPInt ent = index >= 0 ? reinterpret_cast<UPInt>(&tbl->E(index).Key) : 0;
        return ent != 0 ? reinterpret_cast<Value*>(ent + 8) : 0;
    }
    return 0;
}

// @0x142528620
void MovieRoot::SetMouseCursorType(const ASString& cursor, UInt32 mouse)
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    const ASString* name = &cursor;
    const char* s = name->ToCStr();
    UInt32 v = ~0u;
    if (strcmp(s, "arrow") == 0) v = 0;
    else if (strcmp(s, "button") == 0) v = 3;
    else if (strcmp(s, "hand") == 0) v = 1;
    else if (strcmp(s, "ibeam") == 0) v = 2;
    SInt32* p0;
    SInt32* p1;
    if (mouse >= 4)
    {
        p0 = reinterpret_cast<SInt32*>(0x40);
        p1 = reinterpret_cast<SInt32*>(0x44);
    }
    else
    {
        p0 = reinterpret_cast<SInt32*>(Sfr31Rd(self, 0x10) + 0x12a0 + static_cast<UPInt>(mouse) * 0x50);
        p1 = reinterpret_cast<SInt32*>(Sfr31Rd(self, 0x10) + 0x12a4 + static_cast<UPInt>(mouse) * 0x50);
    }
    typedef void (*Fn)(UPInt, UInt32, SInt32);
    reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(self, 0), 0x18))(self, mouse, v);
    *p1 = v;
    *p0 = v;
}

const SlotInfo* FindFixedSlot(VM& vm, const Traits& tr, const Multiname& mn, UPInt& ind, Object* obj);   // 0x142500f90

// batch 18
// LinearHeap::allocFromLastPage: bump-allocates from the last page, or (when that page is untouched) replaces it with one
// big enough for the request.
// @0x142532060
void* Sfr31LinearHeapAllocFromLastPage(UPInt self, UPInt n)
{
    UPInt page = Sfr31Rd(self, 0x18);
    UPInt used = Sfr31Rd(page, 0x10);
    if (static_cast<SPInt>(Sfr31Rd(page, 8) - used) >= static_cast<SPInt>(n))
    {
        Sfr31Wr(page, 0x10, used + n);
        return reinterpret_cast<void*>(Sfr31Rd(Sfr31Rd(self, 0x18), 0x10) - n);
    }
    if (used == Sfr31Rd(page, 0))
    {
        if (Sfr31Rd(page, 0) != 0)
            reinterpret_cast<MemoryHeap*>(Sfr31Rd(self, 0))->Free(reinterpret_cast<void*>(Sfr31Rd(page, 0)));
        UPInt pageSize = Sfr31Rd(self, 8);
        UPInt total = n - 1 + pageSize;
        total -= total % pageSize;
        UPInt p = reinterpret_cast<UPInt>(reinterpret_cast<MemoryHeap*>(Sfr31Rd(self, 0))->Alloc(total, static_cast<const AllocInfo*>(0)));
        UPInt cur = Sfr31Rd(self, 0x18);
        Sfr31Wr(cur, 0x10, p);
        Sfr31Wr(Sfr31Rd(self, 0x18), 0, p);
        Sfr31Wr(Sfr31Rd(self, 0x18), 8, Sfr31Rd(Sfr31Rd(self, 0x18), 0) + total);
        Sfr31Wr(Sfr31Rd(self, 0x18), 0x10, Sfr31Rd(Sfr31Rd(self, 0x18), 0x10) + n);
        return reinterpret_cast<void*>(Sfr31Rd(Sfr31Rd(self, 0x18), 0));
    }
    return 0;
}

// SetSuperProperty: stores v through the parent traits' fixed slot for the multiname; false when there is no such slot.
// @0x14252a150
CheckResult SetSuperProperty(VM& vm, const Traits* tr, const Value& obj, const Multiname& mn, const Value& v)
{
    if (tr == 0)
        tr = &vm.GetValueTraits(obj);
    const Traits* parent = tr->GetParent();
    if (parent != 0)
    {
        UPInt ind = 0;
        const SlotInfo* si = FindFixedSlot(vm, *parent, mn, ind, 0);
        char res;
        return CheckResult(si != 0 && *Sfr27SlotSetValueThis(si, &res, &vm, &v, &obj, static_cast<VTable*>(FUN_14250fa80(parent))) != 0);
    }
    return false;
}

// Tracer: records a position to retrace after the target of a jump (backward jumps only note the target's position).
// Forward jumps push a Recalculate {position before the current one, arg} onto PosToRecalculate.
// @0x14252c9f0
void Sfr31TraceNoteJump(UPInt tr, SPInt base, UPInt blk, SInt32 off, SInt32 arg)
{
    SPInt idx = off + base;
    if (off < 0)
    {
        FUN_14251fcd0(tr, Sfr31Rd(Sfr31Rd(tr, 0xd0) + idx * 8, 0) - Sfr31Rd(Sfr31Rd(tr, 0x28), 8) + static_cast<SPInt>(arg));
        return;
    }
    FUN_1424e6aa0(tr, blk, idx, 0, 1);
    FUN_14251fcd0(tr, idx);
    Tracer::Recalculate r;
    r.pos = Sfr31Rd(Sfr31Rd(tr, 0x28), 8) - 1;
    r.base = static_cast<int>(arg);
    reinterpret_cast<ArrayDH_POD<Tracer::Recalculate, StatMV_VM>*>(tr + 0xb0)->PushBack(r);   // PosToRecalculate
}

}}}
void FUN_1424162b0(const Scaleform::GFx::AS3::Instances::Namespace* self, Scaleform::GFx::AS3::Value& name,
                   Scaleform::GFx::AS3::GlobalSlotIndex ind);   // Namespace::GetNextPropertyName (sfr_as3_04)
void FUN_142416600(Scaleform::GFx::AS3::Instances::Namespace* self, Scaleform::GFx::AS3::Value& value,
                   Scaleform::GFx::AS3::GlobalSlotIndex ind);   // Namespace::GetNextPropertyValue (sfr_as3_04)
namespace Scaleform { namespace GFx { namespace AS3 {

// batch 19
// nextname/nextvalue share the shape: the index on top is consumed, the object below becomes the name/value.
// SDK ToType<SInt32> (AS3_CodeExecute.h): converts in place, a failed conversion yields a static dummy.
static __forceinline SInt32& Sfr31ToTypeSInt32(Value& v, bool& success)
{
    static SInt32 tmp;
    if (success)
    {
        SInt32 result;
        if (v.Convert2Int32(result))
        {
            v.SetSInt32(result);
            success = true;
        }
        else
            success = false;
    }
    return success ? *reinterpret_cast<SInt32*>(reinterpret_cast<UPInt>(&v) + 0x10) : tmp;
}

// nextname/nextvalue (SDK exec_nextname: SH2<1, Value, SInt32>): the index on top is consumed, the object below
// becomes the name/value; a Namespace is not an Object and is asked directly.
// SDK SH2<1, Value, SInt32>: _2 converted in place from the top, _1 the value below it, the top popped.
struct Sfr31SH2ValueSInt32
{
    __forceinline Sfr31SH2ValueSInt32(Value*& top)
    : Success(true)
    , _2(Sfr31ToTypeSInt32(top[0], Success))
    , _1(top[-1])
    {
        top->~Value();
        --top;
    }
    bool Success;
    SInt32 _2;
    Value& _1;
    bool IsOK() const { return Success; }
};

static __forceinline void Sfr31ExecNextCommon(VM* vm, bool wantValue)
{
    Sfr31SH2ValueSInt32 stack(*reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50));
    if (stack.IsOK())
    {
        if (stack._1.IsNamespace())
        {
            if (wantValue)
                ::FUN_142416600(stack._1.GetNamespace(), stack._1, GlobalSlotIndex(static_cast<UInt32>(stack._2)));
            else
                ::FUN_1424162b0(stack._1.GetNamespace(), stack._1, GlobalSlotIndex(static_cast<UInt32>(stack._2)));
        }
        else
        {
            Object* obj = *reinterpret_cast<Object**>(reinterpret_cast<UPInt>(&stack._1) + 0x10);
            if (wantValue)
                obj->GetNextPropertyValue(stack._1, GlobalSlotIndex(static_cast<UInt32>(stack._2)));
            else
                obj->GetNextPropertyName(stack._1, GlobalSlotIndex(static_cast<UInt32>(stack._2)));
        }
    }
}

// @0x14253d2f0
void Sfr27ExecNextName(VM* vm) { Sfr31ExecNextCommon(vm, false); }

// @0x14253d440
void Sfr27ExecNextValue(VM* vm) { Sfr31ExecNextCommon(vm, true); }

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// As the wchar_t SetText, for a UTF-8 string; a TextField also has its html flag (+0xfc bit 1) synced to the request.
// @0x14252a230
bool AS3ValueObjectInterface::SetText(void* pdata, const char* text, bool html)
{
    using namespace AS3;
    UPInt* self = reinterpret_cast<UPInt*>(this);
    const UPInt obj = reinterpret_cast<UPInt>(pdata);
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) != 0))
    {
        TextField* tf = *reinterpret_cast<TextField**>(obj + 0x58);
        typedef SInt32 (*Kind)(void*);
        if ((*reinterpret_cast<Kind* const*>(tf))[0x258 / 8](tf) != 4)
        {
            struct RawGfxValue { UPInt iface; UInt32 type; const char* str; } v = { 0, 6, text };
            typedef bool (*Set)(void*, UPInt, const char*, void*, bool);
            bool r = (*reinterpret_cast<Set* const*>(self))[0x28 / 8](self, obj, html ? "htmlText" : "text", &v, true);
            if ((static_cast<UByte>(v.type >> 6) & 1) != 0)
            {
                typedef void (*Rel)(void*, void*, const char*);
                (*reinterpret_cast<Rel* const*>(v.iface))[0x10 / 8](reinterpret_cast<void*>(v.iface), &v, v.str);
            }
            return r;
        }
        UInt32& flags = *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(tf) + 0xfc);
        const bool cur = (static_cast<UByte>(flags >> 1) & 1) != 0;
        if (html)
        {
            if (!cur)
                flags |= 2;
        }
        else if (cur)
            flags &= 0xfffffffd;
        tf->SetTextValue(text, html, true);
        return true;
    }
    return false;
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {

// newarray: a new Array filled from the n values on the operand stack, pushed.
// @0x14253c0f0
void Sfr31ExecNewArray(UPInt vm, UInt32 n)
{
    UPInt traits = Sfr31Rd(Sfr31Rd(vm, 0x238), 0xc0);
    UPInt arr;
    FUN_14241a500(traits, &arr, traits);
    FUN_14241d980(arr + 0x38, vm + 0x48, n);
    Value v;
    ValueAssignCopies::PickUnsafeObject19(v, reinterpret_cast<Object*>(arr));
    ExecPushCopy(reinterpret_cast<VM*>(vm), v);
}

// newcatch: a new Catch scope object for the exception handler (file a, exception info b), pushed on the operand stack.
// @0x14253c200
void Sfr31ExecPushInterfaceInstance(UPInt vm, UPInt a, UPInt b)
{
    UPInt owner = Sfr31Rd(Sfr31Rd(vm, 0x240), 0xc0);
    UPInt tbl = Sfr31Rd(owner, 0x80);
    if (tbl == 0)
    {
        typedef void (*Init)(UPInt);
        reinterpret_cast<Init>(Sfr31Rd(Sfr31Rd(owner, 0), 0x68))(owner);
        tbl = Sfr31Rd(owner, 0x80);
    }
    // Classes::fl::Catch::MakeInstanceTraits builds the catch scope's traits; the exe makes a Catch instance of them (0x14241a5b0)
    // and drops the traits reference before the instance is pushed.
    struct M { static __forceinline Pickable<Instances::fl::Catch> Make(UPInt cls, UPInt file, UPInt info)
    {
        SPtr<InstanceTraits::fl::Catch> tr = reinterpret_cast<Classes::fl::Catch*>(cls)->MakeInstanceTraits(
            *reinterpret_cast<VMAbcFile*>(file), *reinterpret_cast<const Abc::MethodBodyInfo::ExceptionInfo*>(info));
        return tr->MakeInstance(*tr);
    } };
    Pickable<Instances::fl::Catch> inst = M::Make(tbl, a, b);
    Value v;
    ValueAssignCopies::PickUnsafeObject19(v, inst.GetPtr());
    ExecPushCopy(reinterpret_cast<VM*>(vm), v);
}


// ---- batch 20: raw models of the ArrayDataBase Reserve / ResizeNoConstruct / Resize instances (Data +0, Size +8, Capacity +0x10)
// Kinds of element teardown run by the shrinking path.
enum { Sfr31ElNone, Sfr31ElStrNode, Sfr31ElStrNodeTag, Sfr31ElRcFree, Sfr31ElObj, Sfr31ElValue, Sfr31ElFree, Sfr31ElSPtr };

static void Sfr31ArrReserve(UPInt* a, const void* addr, UPInt n, UPInt esz, UInt32 id, MemoryHeap* dh)
{
    UPInt cap = 0;
    if (n != 0)
    {
        cap = (n + 3) & ~static_cast<UPInt>(3);
        if (a[0] != 0)
        {
            a[0] = reinterpret_cast<UPInt>(Memory::Realloc(reinterpret_cast<void*>(a[0]), cap * esz));
            a[2] = cap;
            return;
        }
        if (dh != 0)
            a[0] = reinterpret_cast<UPInt>(Memory::AllocInHeap(dh, cap * esz, AllocInfo(id, 0, 0)));
        else
            a[0] = reinterpret_cast<UPInt>(Memory::AllocAutoHeap(addr, cap * esz, AllocInfo(id, 0, 0)));
    }
    else if (a[0] != 0)
    {
        Memory::Free(reinterpret_cast<void*>(a[0]));
        a[0] = 0;
    }
    a[2] = cap;
}

static void Sfr31ArrTearDown(UPInt slot, int kind)
{
    const UPInt el = Sfr31Rd(slot, 0);
    switch (kind)
    {
    case Sfr31ElStrNode:
    {
        int* rc = reinterpret_cast<int*>(el + 0x18);
        if (--*rc == 0)
            reinterpret_cast<ASStringNode*>(el)->ReleaseNode();
        break;
    }
    case Sfr31ElStrNodeTag:
        if (el != 0)
        {
            if ((el & 1) == 0)
            {
                int* rc = reinterpret_cast<int*>(el + 0x18);
                if (--*rc == 0)
                    reinterpret_cast<ASStringNode*>(el)->ReleaseNode();
            }
            else
                Sfr31Wr(slot, 0, el - 1);
        }
        break;
    case Sfr31ElRcFree:
        if (el != 0 && --*reinterpret_cast<int*>(el) == 0)
            Memory::Free(reinterpret_cast<void*>(el));
        break;
    case Sfr31ElObj:
        if (el != 0)
            FUN_14257dcd0(reinterpret_cast<void*>(el));
        break;
    case Sfr31ElFree:
        Memory::Free(reinterpret_cast<void*>(el));
        break;
    case Sfr31ElSPtr:   // ConstructorMov<SPtr<T>>::DestructArray: a killed (tagged) pointer is untagged, not released
        reinterpret_cast<SPtr<GASRefCountBase>*>(slot)->~SPtr();
        break;
    default:
        break;
    }
}

// Shrink (destroy the tail, release spare capacity) or grow (reserve n + n/4); Size is set to n.
static void Sfr31ArrResizeNC(UPInt* a, const void* addr, UPInt n, UPInt esz, UInt32 id, MemoryHeap* dh, int kind)
{
    const UPInt old = a[1];
    UPInt want = n;
    bool doReserve;
    if (n < old)
    {
        if (kind == Sfr31ElValue)
        {
            AS3::Value* v = reinterpret_cast<AS3::Value*>(a[0]);
            for (UPInt i = old; i > n; --i)
                v[i - 1].~Value();
        }
        else
        {
            for (UPInt i = old; i > n; --i)
                Sfr31ArrTearDown(a[0] + (i - 1) * esz, kind);
        }
        doReserve = n < (a[2] >> 1);
    }
    else
    {
        doReserve = n >= a[2];
        want = n + (n >> 2);
    }
    if (doReserve)
        Sfr31ArrReserve(a, addr, want, esz, id, dh);
    a[1] = n;
}

// ---- batch 21
static inline void Sfr31ReleaseStr(UPInt node)
{
    int* rc = reinterpret_cast<int*>(node + 0x18);
    if (--*rc == 0)
        reinterpret_cast<ASStringNode*>(node)->ReleaseNode();
}

typedef void (*Sfr31VFn1)(UPInt);
typedef void (*Sfr31VFn3)(UPInt, UPInt, UPInt);

namespace {
// Ptr<ShapeMeshProvider> (RefCountBase at +0x10 of the provider): operator= AddRefs the new one, Releases the old one.
struct Sfr31ShapePtr
{
    UPInt pObject;
    void operator=(UPInt p)
    {
        if (p != 0)
            reinterpret_cast<Sfr31VFn1>(Sfr31Rd(Sfr31Rd(p + 0x10, 0), 8))(p + 0x10);
        if (pObject != 0)
            reinterpret_cast<Sfr31VFn1>(Sfr31Rd(Sfr31Rd(pObject + 0x10, 0), 0x10))(pObject + 0x10);
        pObject = p;
    }
};
struct Sfr31TreeShapeNodeData { UInt8 Pad[0x90]; Sfr31ShapePtr pShape; };

struct Sfr31TreeShapeEntry
{
    UInt8 Pad[0x28];
    void* pPropagateNext;
    bool hasPropagate() const { return pPropagateNext != 0; }
    void SetShape(UPInt pshape);
};
}

// ShapeMeshProvider holder of a TreeShape (render tree entry): swap the provider, queue the entry for propagation.
// @0x142528eb0
void Sfr31TreeShapeEntry::SetShape(UPInt pshape)
{
    Sfr31TreeShapeNodeData* pdata = reinterpret_cast<Sfr31TreeShapeNodeData*>(reinterpret_cast<Sfr31EntryAccess*>(this)->getWritableData(0x400));
    pdata->pShape = pshape;
    if (!hasPropagate())
        reinterpret_cast<Sfr31EntryAccess*>(this)->addToPropagateImpl();
}

// ShapeObject::SetRatio: only when its render node is a shape node.
// Raw-offset model.
// @0x142528da0
void ShapeObject::SetRatio(float ratio)
{   const UPInt self = reinterpret_cast<UPInt>(this);
    const UPInt node = FUN_1425f26c0(reinterpret_cast<void*>(self));
    if (node == 0)
        return;
    const UPInt page = node & ~static_cast<UPInt>(0xfff);
    const UInt32 idx = static_cast<UInt32>(static_cast<SPInt>(node - page - 0x38) / 0x38);
    const UPInt info = Sfr31Rd(Sfr31Rd(page, 0x20), 0x28 + static_cast<UPInt>(idx) * 8);
    if (*reinterpret_cast<const SInt16*>(info + 8) == 3)
    {
        UPInt data = reinterpret_cast<UPInt>(reinterpret_cast<Sfr31EntryAccess*>(Sfr31Rd(self, 0x48))->getWritableData(0x10));
        *reinterpret_cast<float*>(data + 0x98) = ratio;
    }
}

// SDK IsXMLObject / IsXMLListObject (Object*), inline here: a builtin object of type ty, not a user subclass.
static inline bool Sfr31IsObjectOfTraitsType(Object* obj, BuiltinTraitsType ty)
{
    return obj != NULL && obj->GetTraits().GetTraitsType() == ty && obj->GetTraits().IsInstanceTraits();
}

// checkfilter: the top of the operand stack must be an XML or XMLList instance, else TypeError 1123
// (VM::ThrowTypeError inlined, the message names the value's traits).
// @0x142536ab0
void Sfr31ExecCheckFilter(UPInt vm)
{
    const UPInt top = Sfr31Rd(vm, 0x50);
    const Value& tv = *reinterpret_cast<const Value*>(top);
    if ((tv.IsObject() && Sfr31IsObjectOfTraitsType(tv.GetObject(), Traits_XML))
        || (tv.IsObject() && Sfr31IsObjectOfTraitsType(tv.GetObject(), Traits_XMLList)))   // IsXMLObject || IsXMLListObject
        return;
    VM& v = *reinterpret_cast<VM*>(vm);
    v.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x463), v,   // eFilterError (1123)
        v.GetValueTraits(*reinterpret_cast<const Value*>(top)).GetName().ToCStr()));
}

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// Push the elements [start, start + count) of the array storage (clamped to its length) into an interface object,
// each converted into one GFx::Value.
// @0x142531550
void AS3ValueObjectInterface::VisitElements(void* pdata, ArrVisitor* visitor, unsigned start, int count) const
{
    using namespace AS3;
    const UPInt self = reinterpret_cast<UPInt>(this);
    const UPInt arr = reinterpret_cast<UPInt>(pdata);
    const UPInt out = reinterpret_cast<UPInt>(visitor);
    SparseArray* sa = reinterpret_cast<SparseArray*>(arr + 0x38);
    const UInt32 len = static_cast<UInt32>(sa->GetSize());
    const UPInt root = Sfr31Rd(Sfr31Rd(self, 8), 0x18);
    if (start >= len)
        return;
    if (count < 0)
        count = static_cast<int>(len - start);
    GFx::Value gv;
    const UInt32 end = Alg::Min(len, start + static_cast<UInt32>(count));
    for (UInt32 i = start; i < end; ++i)
    {
        const AS3::Value& v = sa->At(i);
        FUN_1424e42c0(root, &v, &gv);
        typedef void (*Set)(UPInt, UInt32, const GFx::Value&);   // the interface's element setter (slot 1)
        reinterpret_cast<Set>(Sfr31Rd(Sfr31Rd(out, 0), 8))(out, i, gv);
    }
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {

// VMAbcFile::GetInternedString: the pool string through the VM's StringManager (the exe reloads the tracer from
// the State for each chain).
static __forceinline ASString TrInternedString(State* st, UInt32 index)
{
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(StV(st).Tracer()) + 0x30);
    const StringDataPtr sd = pool->GetString(index);
    return reinterpret_cast<VM*>(TrVM(StV(st).Tracer()))->GetStringManager().CreateString(sd.ToCStr(), sd.GetSize());
}

// Tracer: push the constant-pool string index as a String value (the empty string becomes a null object).
// @0x14253f690
void Sfr31TracePushString(State* st, UInt32 index)
{
    FUN_14251fcd0(StV(st).Tracer(), index);
    const ASString str = TrInternedString(st, index);
    StV(st).OpStack().PushBack(Value(str, Value::InlineStr));
}

} } } // namespace Scaleform::GFx::AS3

namespace Scaleform {
// Traits' vtable holder (Traits::pVTable): the out-of-line Reset its callers in sfr_as3_16 / sfr_as3_18 declare,
// emitted here as an explicit instantiation of the sf_autoptr.h body. The VTable destructor is implicit and inlined.
// @0x142524290
template void AutoPtr<GFx::AS3::VTable>::Reset(GFx::AS3::VTable* p, bool owner);
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {
// ---- batch 22
static SF_FORCEINLINE void Sfr31PushByte(UPInt* a, UInt8 b)
{
    // ArrayData<UByte, AllocatorGH>::PushBack; Reserve (0x142522c70) uses the global heap, not the array's own
    typedef ArrayDataBase<UByte, AllocatorGH<UByte, 2>, ArrayDefaultPolicy> BytesData;
    BytesData* const d = reinterpret_cast<BytesData*>(a);
    d->ResizeNoConstruct(d, d->Size + 1);
    d->Data[d->Size - 1] = b;
}

// ArrayData::PushBack(const T&): the pushed value is materialized before the Reserve call.
static SF_FORCEINLINE void Sfr31PushByteRef(UPInt* a, const UInt8& b)
{
    typedef ArrayDataBase<UByte, AllocatorGH<UByte, 2>, ArrayDefaultPolicy> BytesData;
    BytesData* const d = reinterpret_cast<BytesData*>(a);
    d->ResizeNoConstruct(d, d->Size + 1);
    d->Data[d->Size - 1] = b;
}

// Variable-length integer writer: the low two bits of the first byte give the byte count - 1.
// MS2-FUNCTIONAL 0x142531bf0: SDK WriteUInt30 shape; two byte stores swap base/index operand order ([rax+rbx-1] vs [rbx+rax-1])
// @0x142531bf0
UPInt Sfr31WriteVarint(UPInt** arr, UInt32 v)
{
    // PathDataEncoder<ContainerType>::WriteUInt30; *arr is the encoder's Data pointer
    const UInt8 b0 = UInt8(v << 2);
    if (v <= 0x3f)
    {
        Sfr31PushByteRef(*arr, b0);
        return 1;
    }
    if (v <= 0x3fff)
    {
        Sfr31PushByteRef(*arr, b0 | 1);
        Sfr31PushByteRef(*arr, UInt8 (v >> 6));
        return 2;
    }
    if (v <= 0x3fffff)
    {
        Sfr31PushByteRef(*arr, b0 | 2);
        Sfr31PushByteRef(*arr, UInt8 (v >> 6));
        Sfr31PushByteRef(*arr, UInt8 (v >> 14));
        return 3;
    }
    Sfr31PushByteRef(*arr, b0 | 3);
    Sfr31PushByteRef(*arr, UInt8 (v >> 6));
    Sfr31PushByteRef(*arr, UInt8 (v >> 14));
    Sfr31PushByteRef(*arr, UInt8 (v >> 22));
    return 4;
}

// Record writer: emits a leading 0 byte on the first record, then a 1 tag and three varints.
// ShapeDataFloatEncoder::StartLayer: the layer tag written through an encoder of its own.
static SF_FORCEINLINE void Sfr31StartLayer(UPInt self)
{
    UPInt* encoder = reinterpret_cast<UPInt*>(Sfr31Rd(self, 0x48));
    Sfr31PushByteRef(encoder, UInt8(0));
    *reinterpret_cast<int*>(self + 0x10) = 1;
}
// ShapeDataFloatEncoder::StartPath: encoder is the PathDataEncoder's Data pointer; the path tag goes through it too.
// @0x14252c8b0
void Sfr31WriteRecord3(UPInt self, UInt32 a, UInt32 b, UInt32 c)
{
    UPInt* encoder = reinterpret_cast<UPInt*>(Sfr31Rd(self, 0x48));
    if (*reinterpret_cast<int*>(self + 0x10) == 0)
        Sfr31StartLayer(self);
    Sfr31PushByteRef(encoder, UInt8(1));
    Sfr31WriteVarint(&encoder, a);
    Sfr31WriteVarint(&encoder, b);
    Sfr31WriteVarint(&encoder, c);
    *reinterpret_cast<int*>(self + 0x10) = 2;
}

// Constructs an instance of classObj; on an exception or a null/undefined result the out pointer is cleared and the
// exception dropped, else FUN_1424e0860 stores the object.
// @0x142531f40
bool ASVM::_constructInstance(SPtr<Object>& pobj, Object* classObj, unsigned argc, const Value* argv)
{
    bool result;
    Value res;
    classObj->Construct(res, argc, argv, true);
    if (IsException() || res.IsNullOrUndefined())
    {
        pobj = NULL;
        if (IsException())
            HandleException = false;
        result = false;
    }
    else
    {
        FUN_1424e0860(&pobj, reinterpret_cast<UPInt>(res.GetObject()));
        result = true;
    }
    return result;
}

// ArrayDataDH<Value>::PushBack with its ResizeNoConstruct (0x1424201a0) out of line.
static SF_INLINE void Sfr31PushScope(ArrayDataDH<Value, AllocatorDH<Value, 2>, ArrayDefaultPolicy>& d, const Value& val)
{
    FUN_1424201a0(&d, const_cast<MemoryHeap*>(d.pHeap), d.Size + 1);
    new (d.Data + d.Size - 1) Value(val);
}

// Traits::StoreScopeStack: appends copies of scope entries [start, n) onto the stored scope array.
// @0x14252cad0
void Sfr31StoreScopeStack(UPInt self, UPInt start, UPInt* src)
{
    const ArrayDH<Value>& ss = *reinterpret_cast<const ArrayDH<Value>*>(src);
    ArrayDH<Value>& initScope = *reinterpret_cast<ArrayDH<Value>*>(self + 0xa0);
    ArrayDataDH<Value, AllocatorDH<Value, 2>, ArrayDefaultPolicy>& d = *reinterpret_cast<ArrayDataDH<Value, AllocatorDH<Value, 2>, ArrayDefaultPolicy>*>(self + 0xa0);
    const UPInt size = ss.GetSize();
    initScope.Reserve(reinterpret_cast<const ArrayDH<Value>*>(self + 0xa0)->GetSize() + size);
    for (UPInt i = start; i < size; ++i)
        Sfr31PushScope(d, ss[i]);
}

// exec_esc_xattr: converts the top of stack to a string and replaces it with its XML-escaped form.
// Value::ToStringValue (SDK), inlined in the exe
static __forceinline CheckResult Sfr31ToStringValue(AS3::Value& v, ASStringManager& mgr)
{
    CheckResult rc = true;
    ASString r = mgr.CreateEmptyString();
    if (v.Convert2String(r))
        FUN_1424e0d40(v, r);
    else
        rc = false;
    return rc;
}
// @0x142538700
void Sfr31ExecEscXAttr(UPInt vm)
{
    const UPInt sm = Sfr31Rd(vm, 0x10);
    AS3::Value* top = reinterpret_cast<AS3::Value*>(Sfr31Rd(vm, 0x50));
    if (Sfr31ToStringValue(*top, *reinterpret_cast<ASStringManager*>(Sfr31Rd(sm, 0x1e8))))
    {
        StringBuffer buf(Memory::pGlobalHeap);
        Instances::fl::XML::EscapeElementValue(buf, top->AsString());
        FUN_1424e0d40(*top, reinterpret_cast<ASStringManager*>(Sfr31Rd(sm, 0x1e8))->CreateString(buf.ToCStr(), buf.GetSize()));
    }
}
// ---- batch 23
// The call arguments, then the object they are called on, left on the stack (SDK ReadArgsObjectRef).
struct Sfr31ReadArgsObjectRef : public AS3::ReadArgs
{
    Sfr31ReadArgsObjectRef(VM& vm, UInt32 argc) : AS3::ReadArgs(vm, argc), ArgObject(*OpStack.GetTopPtr())
    {
        CheckObject(ArgObject);
    }
    // The inline VM::ThrowTypeError.
    static void ThrowTypeError(VM& vm, const VM::Error& e) { FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI); }
    // StackReader::CheckObject, inline: a null or undefined object is a TypeError.
    void CheckObject(const Value& v) const
    {
        if (v.IsNullOrUndefined())
        {
            // eConvertNullToObjectError / eConvertUndefinedToObjectError
            const VM::ErrorID id = v.IsNull() ? static_cast<VM::ErrorID>(0x3f1) : static_cast<VM::ErrorID>(0x3f2);
            VM& vm = VMRef;
            ThrowTypeError(vm, VM::Error(id, vm));
        }
    }
    const Value* GetCallArgs() const { return ArgNum > 8 ? CallArgs.GetDataPtr() : FixedArgs; }
    UInt32 GetCallArgsNum() const { return ArgNum; }
    const Value& ArgObject;     // +0x138
};

// The call arguments, then the object they are called on, popped (SDK ReadArgsObject).
struct Sfr31ReadArgsObject : public AS3::ReadArgs
{
    __forceinline Sfr31ReadArgsObject(VM& vm, UInt32 argc) : AS3::ReadArgs(vm, argc), ArgObject(OpStack)
    {
        CheckObject(ArgObject);
    }
    // StackReader::CheckObject, inline: a null or undefined object is a TypeError.
    void CheckObject(const Value& v) const
    {
        if (v.IsNullOrUndefined())
        {
            // eConvertNullToObjectError / eConvertUndefinedToObjectError
            const VM::ErrorID id = v.IsNull() ? static_cast<VM::ErrorID>(0x3f1) : static_cast<VM::ErrorID>(0x3f2);
            VM& vm = VMRef;
            Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(id, vm));
        }
    }
    const Value* GetCallArgs() const { return ArgNum > 8 ? CallArgs.GetDataPtr() : FixedArgs; }
    Value ArgObject;            // +0x138
};

// Calls the object below the arguments with an undefined this; the result replaces the object on the stack. A null or
// undefined object is TypeError 1009/1010 (raised in the reader's constructor).
// @0x142533fd0
void Sfr31CallOnObjectArg(UPInt vmAddr, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsObjectRef args(vm, argc);
    if (!vm.IsException())
    {
        args.ArgObject.GetObject()->Call(Value::GetUndefined(), const_cast<Value&>(args.ArgObject), argc, args.GetCallArgs());
    }
}

// applytype: the object below the arguments must be a Class; it is replaced by the Class its ApplyTypeArgs returns.
// @0x142532dc0
void Sfr31CallClassArg(UPInt vmAddr, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsObjectRef args(vm, argc);
    if (vm.IsException())
        return;
    if (!args.ArgObject.IsClass())
        // eTypeAppOfNonParamType
        return Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(static_cast<VM::ErrorID>(0x467), vm));
    const_cast<Value&>(args.ArgObject).Assign(&const_cast<Value&>(args.ArgObject).AsClass().ApplyTypeArgs(args.GetCallArgsNum(), args.GetCallArgs()));
}

// The top of the operand stack is converted to an int index and popped; the new top's object is queried at that index and
// the top replaced by the resulting uint.
// VM::exec_hasnext.
// @0x14253abd0
void Sfr31ExecIndexedQuery(UPInt vm)
{
    Sfr31SH2ValueSInt32 stack(*reinterpret_cast<Value**>(vm + 0x50));
    if (!stack.IsOK())
        return;
    stack._1 = Value(stack._1.GetObject()->GetNextDynPropIndex(GlobalSlotIndex(static_cast<UInt32>(stack._2))).Get());
}
// ---- batch 24
// Value -> Boolean conversion used by the tracer, in place.
// @0x14252f4f0
void Sfr31ValueToBool(Value* v)
{
    v->SetBool(ValueAssignCopies::Convert2Boolean(*v));   // Value::ToBooleanValue
}

typedef UPInt (*Sfr31Fn2)(UPInt);
struct Sfr31SubVtbl { void* f0; Sfr31Fn2 f1; };

// splitBounds: SwapChildren's inlined copy tests the two bounds in separate ifs (the SDK text); the out-of-line SwapChildrenAt
// matches with one || test.
static __forceinline bool Sfr31SwapChildrenTail(UPInt owner, unsigned i1, unsigned i2, bool splitBounds)
{
    const UPInt list = owner + 0xd8;
    if (splitBounds)
    {
        if (i1 >= Sfr31Rd(list, 8))
            return false;
        if (i2 >= Sfr31Rd(list, 8))
            return false;
    }
    else if (i1 >= Sfr31Rd(list, 8) || i2 >= Sfr31Rd(list, 8))
        return false;
    if (!FUN_1425fb480(reinterpret_cast<void*>(list), reinterpret_cast<void*>(owner), i1, i2))
        return false;
    const UPInt data = Sfr31Rd(list, 0);
    const UPInt c1 = Sfr31Rd(data, static_cast<UPInt>(i1) * 0x10);
    const UPInt c2 = Sfr31Rd(data, static_cast<UPInt>(i2) * 0x10);
    typedef void (*Fn)(UPInt, UInt32);
    if (c1 != 0)
    {
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(c1, 0), 0x188))(c1, 0);
        *reinterpret_cast<UInt32*>(c1 + 0x30) = 0;
        *reinterpret_cast<UInt32*>(c1 + 0x2c) = 0xffffffffu;
    }
    if (c2 != 0)
    {
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(c2, 0), 0x188))(c2, 0);
        *reinterpret_cast<UInt32*>(c2 + 0x30) = 0;
        *reinterpret_cast<UInt32*>(c2 + 0x2c) = 0xffffffffu;
    }
    *reinterpret_cast<UInt8*>(list + 0x28) |= 3;
    if ((UByte)(*reinterpret_cast<const UInt16*>(c1 + 0x6a) >> 7) & 1)
    {
        const UPInt sub = c1 + static_cast<UPInt>(*reinterpret_cast<const UInt8*>(c1 + 0x6d)) * 4;
        const UPInt r = (*reinterpret_cast<Sfr31SubVtbl* const*>(sub))->f1(sub);
        FUN_142517ed0(reinterpret_cast<void*>(r != 0 ? r - 0x30 : 0));
    }
    if ((UByte)(*reinterpret_cast<const UInt16*>(c2 + 0x6a) >> 7) & 1)
    {
        const UPInt sub = c2 + static_cast<UPInt>(*reinterpret_cast<const UInt8*>(c2 + 0x6d)) * 4;
        const UPInt r = (*reinterpret_cast<Sfr31SubVtbl* const*>(sub))->f1(sub);
        FUN_142517ed0(reinterpret_cast<void*>(r != 0 ? r - 0x30 : 0));
    }
    return true;
}

// AvmDisplayObjContainer::SwapChildren: swaps two children of the display list.
// SDK: AvmDisplayObjContainer::SwapChildren (AS3_AvmDisplayObjContainer.cpp), SwapChildrenAt inlined.
// @0x14252e590
bool AvmDisplayObjContainer::SwapChildren(DisplayObjectBase* pch1, DisplayObjectBase* pch2)
{
    const UPInt self = reinterpret_cast<UPInt>(this);
    void* const displayList = reinterpret_cast<void*>(Sfr31Rd(self, 0x18) + 0xd8);
    SPInt origIndex1 = FUN_1425f9200(displayList, pch1);
    SPInt origIndex2 = FUN_1425f9200(displayList, pch2);
    return Sfr31SwapChildrenTail(Sfr31Rd(self, 0x18), (unsigned)origIndex1, (unsigned)origIndex2, true);
}

// AvmDisplayObjContainer::SwapChildrenAt
// @0x14252e6d0
bool AvmDisplayObjContainer::SwapChildrenAt(unsigned i1, unsigned i2)
{
    return Sfr31SwapChildrenTail(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x18), i1, i2, false);
}
// ---- batch 25
// Strict equality of two values (ECMA-262 section 11.9.6).
// @0x14252cbf0
bool StrictEqual(const Value& x, const Value& y)
{
    // (ECMA-262 section 11.9.6.1)
    if (x.GetKind() != y.GetKind())
    {
        if (x.IsNumeric() && y.IsNumeric())
        {
            if (x.IsUInt())
            {
                switch (y.GetKind())
                {
                case Value::kInt:
                    if (y.AsInt() < 0)
                        return false;

                    return x.AsUInt() == static_cast<UInt32>(y.AsInt());
                case Value::kNumber:
                    return x.AsUInt() == y.AsNumber();
                default:
                    break;
                }
            }
            else if(x.IsInt())
            {
                switch (y.GetKind())
                {
                case Value::kUInt:
                    if (x.AsInt() < 0)
                        return false;

                    return static_cast<UInt32>(x.AsInt()) == y.AsUInt();
                case Value::kNumber:
                    return x.AsInt() == y.AsNumber();
                default:
                    break;
                }
            }
            else if(x.IsNumber())
            {
                switch (y.GetKind())
                {
                case Value::kInt:
                    return x.AsNumber() == y.AsInt();
                case Value::kUInt:
                    return x.AsNumber() == y.AsUInt();
                default:
                    break;
                }
            }
        }
        else
            return false;
    }

    switch(x.GetKind())
    {
    case Value::kUndefined:
        // (ECMA-262 section 11.9.6.2)
        return true;
    case Value::kBoolean:
        // (ECMA-262 section 11.9.6.12)
        return x.AsBool() == y.AsBool();
    case Value::kInt:
        return x.AsInt() == y.AsInt();
    case Value::kUInt:
        return x.AsUInt() == y.AsUInt();
    case Value::kNumber:
        return x.AsNumber() == y.AsNumber();
    case Value::kString:
        // (ECMA-262 section 11.9.6.11)
        return x.AsStringNode() == y.AsStringNode();
    case Value::kNamespace:
        return &x.AsNamespace() == &y.AsNamespace();
    case Value::kFunction:
    case Value::kObject:
    case Value::kClass:
    case Value::kThunkFunction:
        if (x.GetObject() == y.GetObject())
            return true;

        break;
    case Value::kThunkClosure:
        if (x.GetClosure() == y.GetClosure())
        {
            if (&x.AsThunk() == &y.AsThunk())
                return true;
        }

        break;
    case Value::kVTableIndClosure:
        if (x.GetClosure() == y.GetClosure())
        {
            if (x.GetVTableInd() == y.GetVTableInd())
                return true;
        }

        break;
    case Value::kVTableInd:
        return x.GetVTableInd() == y.GetVTableInd() && &x.GetTraits() == &y.GetTraits();
    case Value::kThunk:
        return &x.AsThunk() == &y.AsThunk();
    default:
        SF_ASSERT(false);
    }

    return false;
}

// Tracer ops taking the two counts of a call and pushing an object value.
// MS2-FUNCTIONAL 0x142533cb0: register/slot only: the exe saves rbx in the rdx home slot (ours the r9 home) and loads the
// ReadArgs vm argument through rdx after lea rcx,[args]. An unused 4th parameter and a named VM& do not change either.
// @0x142533cb0
void Sfr31TraceCallPushObject(State* st, UInt32 a, UInt32 b)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), a);
    FUN_14251fcd0(s.Tracer(), b);
    TrReadArgsObject args(*reinterpret_cast<VM*>(TrVM(s.Tracer())), *st, b);
    TrTraitsScratch t(Value::NullOrNot);
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
}

// MS2-FUNCTIONAL 0x142535540: register/slot only: the exe saves rbx in the rdx home slot (ours the r9 home) and loads the
// ReadArgs vm argument through rdx after lea rcx,[args]. An unused 4th parameter and a named VM& do not change either.
// @0x142535540
void Sfr31TraceCallPushObjectB(State* st, UInt32 a, UInt32 b)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), a);
    FUN_14251fcd0(s.Tracer(), b);
    TrReadArgsObject args(*reinterpret_cast<VM*>(TrVM(s.Tracer())), *st, b);
    TrTraitsScratch t(Value::NullOrNot);
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
}

struct Sfr31MnCtx
{
    UPInt vm;
    State* st;
    int pops;
};

static inline const Abc::Multiname& Sfr31MnEntry(UPInt abcLink, UInt32 idx)
{
    const UPInt file = TrRd(abcLink, 0x28);
    return *reinterpret_cast<const Abc::Multiname*>(idx == 0 ? file + 0xe8 : static_cast<UPInt>(idx) * 0x10 + TrRd(file, 0xb8));
}

// Holds a Multiname whose destructor runs through the exe's out-of-line copy.
struct Sfr31MnSlot
{
    union { Multiname mn; };
    Sfr31MnSlot(VMAbcFile& file, const Abc::Multiname& e) : mn(file, e) {}
    ~Sfr31MnSlot() { mn.~Multiname(); }
};

// The multiname reader's context with its ABC file.
struct Sfr31MnCtx4
{
    UPInt vm;
    State* st;
    int pops;
    UPInt file;
};

// A Multiname in raw storage, destroyed through the exe's out-of-line ~Multiname.
struct Sfr31MnRaw
{
    Sfr31MnRaw(VMAbcFile& file, const Abc::Multiname& e) { ::new (&w0) Multiname(file, e); }
    ~Sfr31MnRaw() { Get().~Multiname(); }
    Multiname& Get() { return *reinterpret_cast<Multiname*>(&w0); }
    UPInt w0, w1, w2, w3, w4, w5;
};

// The multiname entry for a 64-bit index (the exe tests the zero-extended index as a quadword).
static inline const Abc::Multiname& Sfr31MnEntryW(UPInt abcLink, UPInt idx)
{
    const UPInt file = TrRd(abcLink, 0x28);
    return *reinterpret_cast<const Abc::Multiname*>(idx == 0 ? file + 0xe8 : idx * 0x10 + TrRd(file, 0xb8));
}

// TR::ReadMnObject with its destructor inlined (the header's is the exe's out-of-line 0x1424ded40): the reader
// fields, the multiname read off the stack, then the popped object.
struct Sfr31ReadMn
{
    __forceinline Sfr31ReadMn(State* st, UPInt link, UPInt idx)
        : ctx{TrRd(link, 0x20), st, 0, link}, mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntryW(link, idx))
    {
        ctx.pops += FUN_142520380(&ctx, &mn.Get());
    }
    Sfr31MnCtx4 ctx;    // +0x00
    Sfr31MnRaw mn;      // +0x20
};
struct Sfr31ReadMnObject : Sfr31ReadMn
{
    __forceinline Sfr31ReadMnObject(State* st, UPInt link, UPInt idx) : Sfr31ReadMn(st, link, idx), obj(st->PopOpValue())
    {
        ++ctx.pops;
    }
    Value obj;          // +0x50
};

// Tracer op with a multiname: notes the name operand(s), pops the object and pushes an object value.
// @0x142537f00
void Sfr31TraceMnPopPush(State* st, UInt32 idx)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    Sfr31ReadMnObject args(st, TrAbcLink(s.Tracer()), idx);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x210));
    s.OpStack().PushBack(t.Get());
}

// Tracer op with a multiname that pops the object and the value without pushing.
// TR::ReadValueMnObject likewise (the header's destructor is the exe's out-of-line 0x1424dee30): the reader fields
// and the popped value, the file and the multiname read off the stack, then the popped object.
struct Sfr31ReadValue
{
    __forceinline Sfr31ReadValue(State* st, UPInt vm) : ctx{vm, st, 0}, val(st->PopOpValue())
    {
        ++ctx.pops;
    }
    Sfr31MnCtx ctx;     // +0x00
    Value val;          // +0x18
};
struct Sfr31ReadValueMn : Sfr31ReadValue
{
    __forceinline Sfr31ReadValueMn(State* st, UPInt link, UPInt idx)
        : Sfr31ReadValue(st, TrRd(link, 0x20)), file(link), mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntryW(link, idx))
    {
        ctx.pops += FUN_142520380(&ctx, &mn.Get());
    }
    UPInt file;         // +0x38
    Sfr31MnRaw mn;      // +0x40
};
struct Sfr31ReadValueMnObject : Sfr31ReadValueMn
{
    __forceinline Sfr31ReadValueMnObject(State* st, UPInt link, UPInt idx) : Sfr31ReadValueMn(st, link, idx), obj(st->PopOpValue())
    {
        ++ctx.pops;
    }
    Value obj;          // +0x70
};

// @0x14253b640
void Sfr31TraceMnPop2(State* st, UInt32 idx)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    Sfr31ReadValueMnObject args(st, TrAbcLink(s.Tracer()), idx);
}
// ---- batch 26
static void Sfr31ThrowIfNotObject(VM& vm, const UInt32* v)
{
    const UInt32 k = (v[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    if ((v[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        VM::Error e(static_cast<VM::ErrorID>((k < 4 ? (obj != 0) : 1u) + 0x3f1), vm);
        vm.ThrowTypeError(e);
    }
}

// Constructs the named class into a scratch value; a non-null object result is moved into *out, else *out is cleared.
static __forceinline CheckResult Sfr31ConstructOrClearImpl(UPInt self, UPInt* out, const char* gname, UInt32 argc, const Value* argv)
{
    VM& vm = *reinterpret_cast<VM*>(self);
    Value tmp;
    vm.Construct(gname, tmp, argc, argv, true);
    if (!vm.IsException() && !tmp.IsNullOrUndefined())
    {
        FUN_1424e0860(out, Sfr31Rd(reinterpret_cast<UPInt>(&tmp), 0x10));
        return true;
    }
    *reinterpret_cast<SPtr<Object>*>(out) = static_cast<Object*>(NULL);
    if (vm.IsException())
        vm.HandleException = false;
    return false;
}

// The exe returns the CheckResult by value; each path destroys the scratch value before its own return.
// @0x142532130
CheckResult VM::constructBuiltinObject(SPtr<Object>& pobj, const char* gname, unsigned argc, const Value* argv)
{
    return Sfr31ConstructOrClearImpl(reinterpret_cast<UPInt>(this), reinterpret_cast<UPInt*>(&pobj), gname, argc, argv);
}

// pushscope: the (non-null) object on top of the operand stack moves onto the scope stack. An undefined or null
// object throws and stays on the operand stack.
// @0x14253f4e0
void Sfr31ExecPushWith(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    ValueStack& ops = ValueStack::Of(vm);
    Value& v = *ops.GetTopPtr();
    if (v.IsNullOrUndefined())
    {
        vm.ThrowTypeError(VM::Error(v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError, vm));
        return;
    }
    vm.ScopeStack.PushBack(Value::GetUndefined());
    ValueAssignCopies::PickUnsafeCopy(vm.ScopeStack.Back(), v);
    ops.GetTopPtr()->~Value();
    ops.Release(1);
}

// Tracer op: replaces the popped value with the instance traits it denotes (primitives collapse to the Object traits).
// The traits value may be null (NullOrNot), as in the exe.
// @0x1425331a0
void Sfr31TraceTopInstanceTraits(State* st)
{
    StV s(st);
    const Value v(st->PopOpValue());
    const UPInt p = reinterpret_cast<UPInt>(&v);
    UPInt tr;
    switch (v.GetKind())
    {
    case Value::kInstanceTraits:
        tr = Sfr31Rd(p, 0x10);
        break;
    case Value::kClassTraits:
        tr = Sfr31Rd(Sfr31Rd(p, 0x10), 0xc0);
        break;
    case 0xd:
        tr = Sfr31Rd(Sfr31Rd(Sfr31Rd(p, 0x10), 0x20), 0xc0);
        break;
    default:
        tr = 0;
        break;
    }
    if (tr != 0)
    {
        const UPInt tracer = s.Tracer();
        if (FUN_142514a80(tracer, reinterpret_cast<void*>(tr)))
            tr = Sfr31Rd(Sfr31Rd(TrVM(tracer), 0x1f8), 0xc0);
        s.Top().Assign(Value(*reinterpret_cast<InstanceTraits::Traits*>(tr), Value::NullOrNot));
    }
}
// ---- batch 27
struct Sfr31RawTraitsVal
{
    UInt32 w0;
    UPInt w1, w2, w3;
};

struct Sfr31TracePropRef
{
    UPInt f, x;
    Value v;
    Sfr31TracePropRef() : f(0), x(0) {}
};

// PropRef holder whose Value destructor clears a weak ref as the exe does: flags first, then Bonus and VS._1 in one 16-byte zero store.
struct Sfr31PropRefW
{
    UPInt f, x;
    union { UPInt Align; UByte Buf[sizeof(Value)]; };
    __forceinline Sfr31PropRefW() : f(0), x(0) { ::new (Buf) Value(); }
    Value& V() { return *reinterpret_cast<Value*>(Buf); }
    __forceinline ~Sfr31PropRefW()
    {
        Value& v = V();
        if (!v.IsRefCounted())
            return;
        if (v.IsWeakRef())
        {
            (*reinterpret_cast<WeakProxy**>(Buf + 8))->Release();
            *reinterpret_cast<UInt32*>(Buf) &= ~0x21fu;
            _mm_storeu_si128(reinterpret_cast<__m128i*>(Buf + 8), _mm_setzero_si128());
            *reinterpret_cast<UPInt*>(Buf + 0x18) = 0;
        }
        else
            FUN_142521f00(&v);
    }
};

// PropRef::IsAsValue / IsAsObject: the tag bit as a bool (as in PropRef::operator bool, 0x1424e0e20)
static inline bool Sfr31PRTag(UPInt p, UPInt mask) { return (p & mask) != 0; }

// Tracer find-property core: resolves the multiname and pushes the property value, or the Object traits when unresolved.
static __forceinline void Sfr31TraceFindProp(State* st, UInt32 idx, Value::TraceNullType nt)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    Sfr31ReadMn args(st, TrAbcLink(s.Tracer()), idx);
    Multiname& mn = args.mn.Get();
    Sfr31TracePropRef pr;
    UInt32 t1;
    UPInt t2;
    FUN_142501e80(st, &pr, &mn, &t1, &t2);
    Value& res = pr.v;
    const UPInt f = pr.f;
    if (!((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || (Sfr31PRTag(f, 1) && (f & ~static_cast<UPInt>(1)) == 0) ||
          (Sfr31PRTag(f, 2) && (f & ~static_cast<UPInt>(2)) == 0)))
        s.OpStack().PushBack(res);
    else
        s.OpStack().PushBack(Value(*reinterpret_cast<InstanceTraits::Traits*>(Sfr31Rd(Sfr31Rd(TrVM(s.Tracer()), 0x1f8), 0xc0)), nt));
}

// MS2-FUNCTIONAL 0x142538840: same lookup and branches; only the not-found Value's lea rdx is scheduled before its stores (exe: after)
// @0x142538840
void Sfr31TraceFindPropA(State* st, UInt32 idx) { Sfr31TraceFindProp(st, idx, Value::NullOrNot); }

// MS2-FUNCTIONAL 0x142538bc0: same lookup and branches; only the not-found Value's lea rdx is scheduled before its stores (exe: after)
// @0x142538bc0
void Sfr31TraceFindPropB(State* st, UInt32 idx) { Sfr31TraceFindProp(st, idx, Value::NotNull); }

// Tracer op: an operand of a type-describing kind becomes its instance traits, anything else is pushed back as it was.
// MS2-FUNCTIONAL 0x142536dd0: scheduling only. With MS2_AS3_READARGS_NOALIAS only the ReadArgs ctor's vm argument load
// order differs: the exe chains it through rcx and loads lea rcx,[args] last. A named VM& and a named State& do not move it.
// @0x142536dd0
void Sfr31TraceTypeOperand(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsObject args(*reinterpret_cast<VM*>(TrVM(s.Tracer())), *st, argc);
    const Value& v = args.ArgObject;
    const UPInt p = reinterpret_cast<UPInt>(&v);
    switch (v.GetKind())
    {
    case Value::kInstanceTraits:
        s.OpStack().PushBack(Value(*reinterpret_cast<InstanceTraits::Traits*>(Sfr31Rd(p, 0x10)), Value::NotNull));
        break;
    case Value::kClassTraits:
        s.OpStack().PushBack(Value(*reinterpret_cast<InstanceTraits::Traits*>(Sfr31Rd(Sfr31Rd(p, 0x10), 0xc0)), Value::NotNull));
        break;
    case 0xd:
        s.OpStack().PushBack(Value(*reinterpret_cast<InstanceTraits::Traits*>(Sfr31Rd(Sfr31Rd(Sfr31Rd(p, 0x10), 0x20), 0xc0)), Value::NotNull));
        break;
    default:
        s.OpStack().PushBack(v);
        break;
    }
}
// ---- batch 28
struct Sfr31ExecMnCtx
{
    UPInt vm;
    UPInt stack;
    UPInt file;
};

static inline void Sfr31ThrowIfNullOperand(UPInt vmAddr, const UInt32* v)
{
    const UInt32 k = (v[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    if ((v[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        VM::Error e(static_cast<VM::ErrorID>((k < 4 ? (obj != 0) : 1u) + 0x3f1), *reinterpret_cast<VM*>(vmAddr));
        reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(e);
    }
}

// Takes the Value on top of the operand stack bitwise, without touching refcounts.
static inline void Sfr31TakeTop(UPInt vmAddr, Sfr31RawTraitsVal& out)
{
    const UPInt top = Sfr31Rd(vmAddr, 0x50);
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&out)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(vmAddr, 0x50, top - 0x20);
}

// ---- batch 29
typedef UPInt* (*Sfr31VFnName)(UPInt self, UPInt* out);

// VM::CheckObject: a TypeError when the value is undefined or a null object.
static __forceinline void Sfr31CheckObject(const Value& v, UPInt vmAddr)
{
    const UInt32 k = *reinterpret_cast<const UInt32*>(&v) & 0x1f;
    const UInt32 ko = k - 0xc;
    if (k == 0 || (ko <= 3 && Sfr31Rd(reinterpret_cast<UPInt>(&v), 0x10) == 0))
    {
        const UInt32 id = (ko <= 3 ? (Sfr31Rd(reinterpret_cast<UPInt>(&v), 0x10) != 0) : 1u) + 0x3f1;
        VM& vm = *reinterpret_cast<VM*>(vmAddr);
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(id), vm));
    }
}

// The exec reader of a multiname and the object under it (SDK ReadMnObject): the reader fields, the multiname read
// off the stack, then a reference to the object left on the stack.
struct Sfr31ExecStackReader
{
    __forceinline Sfr31ExecStackReader(UPInt file) : vm(Sfr31Rd(file, 0x20)), stack(Sfr31Rd(file, 0x20) + 0x48), file(file) {}
    UPInt vm;               // +0x00
    UPInt stack;            // +0x08
    UPInt file;             // +0x10
};
struct Sfr31ExecReadMnObject : Sfr31ExecStackReader
{
    __forceinline Sfr31ExecReadMnObject(UPInt link, UPInt idx)
        : Sfr31ExecStackReader(link), mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntryW(file, idx))
    {
        FUN_1425201f0(this, &mn.Get());
        obj = reinterpret_cast<const Value*>(Sfr31Rd(stack, 8));
    }
    Sfr31MnRaw mn;          // +0x18
    const Value* obj;       // +0x48
};

// The exe calls Multiname's implicit destructor (0x1423f1060) out of line here.
struct Sfr31MnBox
{
    Sfr31MnBox(VMAbcFile& file, const Abc::Multiname& e) { ::new (&w0) Multiname(file, e); }
    ~Sfr31MnBox() { Get().Multiname::~Multiname(); }
    Multiname& Get() { return *reinterpret_cast<Multiname*>(&w0); }
    void* w0; void* w1; UPInt w2, w3, w4, w5;
};
// SDK ReadMn: the exec reader fields, then the multiname read off the stack.
struct Sfr31ExecReadMn : Sfr31ExecStackReader
{
    __forceinline Sfr31ExecReadMn(UPInt link, UPInt idx)
        : Sfr31ExecStackReader(link), mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntryW(file, idx))
    {
        FUN_1425201f0(this, &mn.Get());
    }
    Sfr31MnBox mn;          // +0x18
    void* pad;              // +0x48
};

// ReferenceError 0x429 (eUndefinedVarError) naming the multiname.
// getlex-style resolve: pushes the value the multiname resolves to, or raises a ReferenceError naming it.
// The exe returns the ThrowReferenceError from its branch (its own epilog) and clears the weak ref with one movdqu (Sfr31PropRefW).
// @0x142538d30
void Sfr31ExecGetLex(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ExecReadMn rd(file, idx);
    Sfr31MnBox& mn = rd.mn;
    if (vm.IsException())
        return;
    Sfr31PropRefW pr;
    FUN_142502570(vmAddr, &pr, &mn.Get());
    const UPInt f = pr.f;
    if ((*reinterpret_cast<const UInt32*>(&pr.V()) & 0x1f) == 0 || f == 1 || ((static_cast<UInt8>(f >> 1) & 1) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x429), vm, *reinterpret_cast<const Value*>(&mn.w2)));
    ExecPushCopy(&vm, pr.V());
}

// getdescendants: the XML support reads the descendants of the object; when it declines, pops the operand and raises a TypeError naming the traits.
// @0x142539230
void Sfr31ExecDeleteProp(UPInt vmAddr, UPInt file, UInt32 idx)
{
    Sfr31ExecReadMnObject args(file, idx);
    Sfr31CheckObject(*args.obj, args.vm);
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        if (!reinterpret_cast<VM*>(vmAddr)->GetXMLSupport().GetDescendants(*const_cast<Value*>(args.obj), args.mn.Get()))
        {
            Value* top = reinterpret_cast<Value*>(Sfr31Rd(vmAddr, 0x50));
            top->~Value();
            Sfr31Wr(vmAddr, 0x50, Sfr31Rd(vmAddr, 0x50) - 0x20);
            VM& vm = *reinterpret_cast<VM*>(vmAddr);
            vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f8), vm, vm.GetValueTraits(*args.obj).GetName().ToCStr()));
        }
    }
}

// The SDK ReadValueMn / ReadValueMnObject: the popped value, the file, the multiname read off the stack, then the popped
// object (null or undefined throws).
struct Sfr31ExecReadValueMn : public Scaleform::GFx::AS3::StackReader
{
    __forceinline Sfr31ExecReadValueMn(UPInt link, UInt32 idx)
        : Scaleform::GFx::AS3::StackReader(*reinterpret_cast<VM*>(Sfr31Rd(link, 0x20))), ArgValue(OpStack), File(*reinterpret_cast<VMAbcFile*>(link))
        , ArgMN(File, Sfr31MnEntryW(reinterpret_cast<UPInt>(&File), idx))
    {
        FUN_1425201f0(this, &ArgMN.Get());
    }
    Value ArgValue;         // +0x10
    VMAbcFile& File;        // +0x30 (MnReader)
    Sfr31MnBox ArgMN;       // +0x38
};
struct Sfr31ExecReadValueMnObject : public Sfr31ExecReadValueMn
{
    __forceinline Sfr31ExecReadValueMnObject(UPInt link, UInt32 idx) : Sfr31ExecReadValueMn(link, idx), ArgObject(OpStack)
    {
        CheckObject(ArgObject);
    }
    // StackReader::CheckObject, inline.
    SF_INLINE void CheckObject(const Value& v) const
    {
        if (v.IsNullOrUndefined())
            GetVM().ThrowTypeError(VM::Error(v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError, GetVM()));
    }
    const Value ArgObject;  // +0x68
};

// initproperty: pops the value and the object, resolves the multiname and initializes the property.
// @0x14253ffa0
void Sfr31ExecInitProperty(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ExecReadValueMnObject args(file, idx);
    if (vm.IsException())
        return;
    char result;    // the setter's CheckResult return slot, not read
    Sfr27SetPropertyOfValue(&result, &vm, &args.ArgObject, &args.ArgMN.Get(), &args.ArgValue);
}

// setproperty: pops the value and the object, resolves the multiname and stores the value (with the VM's counter at +0x30 raised
// around the store).
// @0x14253b790
void Sfr31ExecSetProperty(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ExecReadValueMnObject args(file, idx);
    if (vm.IsException())
        return;
    int& inInitializer = *reinterpret_cast<int*>(vmAddr + 0x30);
    ++inInitializer;
    char result;    // the setter's CheckResult return slot, not read
    Sfr27SetPropertyOfValue(&result, &vm, &args.ArgObject, &args.ArgMN.Get(), &args.ArgValue);
    --inInitializer;
}

// The SDK ReadMnObjectRef: the file, the multiname read off the stack, then a reference to the object on top of the stack
// (null or undefined throws).
struct Sfr31ExecReadMnS : public Scaleform::GFx::AS3::StackReader
{
    __forceinline Sfr31ExecReadMnS(UPInt link, UInt32 idx)
        : Scaleform::GFx::AS3::StackReader(*reinterpret_cast<VM*>(Sfr31Rd(link, 0x20))), File(*reinterpret_cast<VMAbcFile*>(link))
        , ArgMN(File, Sfr31MnEntryW(reinterpret_cast<UPInt>(&File), idx))
    {
        FUN_1425201f0(this, &ArgMN.Get());
    }
    VMAbcFile& File;        // +0x10 (MnReader)
    Sfr31MnBox ArgMN;       // +0x18
};
struct Sfr31ExecReadMnObjectRef : public Sfr31ExecReadMnS
{
    __forceinline Sfr31ExecReadMnObjectRef(UPInt link, UInt32 idx) : Sfr31ExecReadMnS(link, idx), ArgObject(*OpStack.GetTopPtr())
    {
        CheckObject(ArgObject);
    }
    SF_INLINE void CheckObject(const Value& v) const
    {
        if (v.IsNullOrUndefined())
            GetVM().ThrowTypeError(VM::Error(v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError, GetVM()));
    }
    Value& ArgObject;       // +0x48
};

// getsuper: replaces the object on top of the stack with its named property, read through the current frame's super traits.
// @0x14253a430
void Sfr31ExecGetSuper(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ExecReadMnObjectRef args(file, idx);
    if (vm.IsException())
        return;
    const Value _this(args.ArgObject, PickValue);
    const UPInt n = Sfr31Rd(vmAddr, 0x78) - 1;
    const Traits* ot = *reinterpret_cast<const Traits* const*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (n >> 6) * 8) + 0x40 + (n & 0x3f) * 0xa8);
    if (!GetSuperProperty(vm, ot, args.ArgObject, _this, args.ArgMN.Get()))
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x40b), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
}

// ---- batch 30
// Tracer op: the popped operand becomes the traits describing its class: the Object traits for a null value, otherwise the
// traits of its dynamic class (or its instance traits when it is a class/function traits holder).
// MS2-FUNCTIONAL 0x14253d160: the exe keeps st in r14, the popped Value's kind in esi and its Flags in ebx across the
// GetValueTraits call (0x14250ffc0), so it knew that callee does not write v (mod/ref). Ours reloads the Flags after the
// call and derives the kind from them. The exe also stores each pushed traits value in its own arm.
// @0x14253d160
void Sfr31TraceOperandClassTraits(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    const Value v(st->PopOpValue());
    const UPInt tracer = s.Tracer();
    UPInt tr;
    switch (v.GetKind())
    {
    case Value::kUndefined:
        tr = Sfr31Rd(TrVM(tracer), 0x278);
        break;
    case Value::kInstanceTraits:
        tr = Sfr31Rd(reinterpret_cast<UPInt>(&v), 0x10);
        break;
    case Value::kClassTraits:
        tr = Sfr31Rd(reinterpret_cast<UPInt>(&v), 0x10);
        break;
    default:
        tr = reinterpret_cast<UPInt>(&reinterpret_cast<VM*>(TrVM(tracer))->GetValueTraits(v));
        break;
    }
    if (tr != 0 && tr == Sfr31Rd(TrVM(tracer), 0x1f0))
        tr = Sfr31Rd(TrVM(tracer), 0x1f8);
    const Traits& t = *reinterpret_cast<const Traits*>(tr);
    if (t.GetTraitsType() == Traits_Dictionary && t.IsInstanceTraits())
        s.OpStack().PushBack(Value(TrITraits(tracer, 0x1f8), Value::NullOrNot));
    else if (t.IsArrayLike())
        s.OpStack().PushBack(Value(TrITraits(tracer, 0x228), Value::NotNull));
    else
        s.OpStack().PushBack(Value(TrITraits(tracer, 0x230), Value::NullOrNot));
}

// Tracer::GetBlock: the last block (+0x110) whose start (+0x20) is not after pos, walking back through +0.
static __forceinline UPInt Sfr31GetBlock(UPInt tr, UPInt pos)
{
    UPInt b = Sfr31Rd(tr, 0x110);
    while (b != 0 && pos < Sfr31Rd(b, 0x20))
        b = Sfr31Rd(b, 0);
    return b;
}

// Tracer::UpdateBlock: entering a block at pos merges or initializes its state from the current block (+0x68).
static __forceinline bool Sfr31UpdateBlock(UPInt tr, UPInt pos)
{
    const UPInt prev = Sfr31Rd(tr, 0x68);
    const UPInt next = Sfr31GetBlock(tr, pos);
    if (next != 0 && Sfr31Rd(next, 0x20) == pos)
    {
        Sfr31Wr(tr, 0x68, next);
        if (*reinterpret_cast<const UInt8*>(next + 0x10) & 1)
        {
            if (next != prev)
            {
                if (!reinterpret_cast<Tracer*>(tr)->MergeBlock(*reinterpret_cast<TR::Block*>(next), *reinterpret_cast<const TR::Block*>(prev)))
                    return false;
            }
        }
        else
            FUN_142511b00(tr, reinterpret_cast<UPInt*>(next), reinterpret_cast<UPInt*>(prev));
    }
    return true;
}

// Traces the code of the block containing pos, merging block states, and keeps tracing opcodes until the code ends or a halt is raised.
// @0x142530220
void Sfr31TraceBlock(UPInt tr, UPInt pos, UPInt block)
{
    const UPInt b = Sfr31GetBlock(tr, pos);
    Sfr31Wr(tr, 0x68, b);
    if (*reinterpret_cast<const UInt8*>(b + 0x10) & 1)
    {
        if (b != block)
        {
            if (!reinterpret_cast<Tracer*>(tr)->MergeBlock(*reinterpret_cast<TR::Block*>(b), *reinterpret_cast<const TR::Block*>(block)))
                return;
        }
    }
    else
        FUN_142511b00(tr, reinterpret_cast<UPInt*>(b), reinterpret_cast<UPInt*>(block));
    // the SDK opcode (Code::OpCode, 32-bit): the op handlers are called through casts that take it at full width
    UInt32 op = 0;
    while (pos < Sfr31Rd(tr, 0x58))
    {
        if (*reinterpret_cast<const UInt8*>(TrVM(tr) + 0x180) != 0)
            return;
        if (!Sfr31UpdateBlock(tr, pos))
            return;
        FUN_14252c640(tr, &pos);
        if (pos >= Sfr31Rd(tr, 0x58))
            break;
        FUN_1425212f0(tr, pos);
        const UInt8 byte_code = reinterpret_cast<const UInt8*>(Sfr31Rd(tr, 0x50))[pos++];
        op = byte_code;
        if (reinterpret_cast<char (*)(UPInt, UInt32, UPInt*, UPInt)>(&Sfr31TracerCommonOp)(tr, op, &pos, Sfr31Rd(Sfr31Rd(tr, 0x68), 0x18)))
            continue;
        if (*reinterpret_cast<const UInt8*>(TrVM(tr) + 0x180) != 0)
            return;
        reinterpret_cast<void (*)(UPInt, UInt32, UPInt*)>(&Sfr31StateTraceOp)(Sfr31Rd(Sfr31Rd(tr, 0x68), 0x18), op, &pos);
    }
}
// ---- batch 31
typedef UPInt (*Sfr31VFnGet)(UPInt self);

// Tracer getdescendants: raises a verify error when XML support is absent, else the object operand becomes an XMLList-typed value.
// @0x1425390a0
void Sfr31TraceGetDescendants(State* st, UInt32 idx)
{
    StV s(st);
    const UPInt vm = TrVM(s.Tracer());
    const UPInt helper = Sfr31Rd(vm, 0x40);
    if (*reinterpret_cast<const UInt8*>(helper + 0x20) == 0)
    {
        VM& v = *reinterpret_cast<VM*>(vm);
        v.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), v, "getdescendants"));
        return;
    }
    FUN_14251fcd0(s.Tracer(), idx);
    Sfr31ReadMnObject args(st, TrAbcLink(s.Tracer()), idx);
    const UPInt xml = Sfr31Rd(TrVM(s.Tracer()), 0x40);
    InstanceTraits::Traits& tr = *reinterpret_cast<InstanceTraits::Traits*>((*reinterpret_cast<Sfr31VFnGet*>(Sfr31Rd(xml, 0) + 0x98))(xml));
    s.OpStack().PushBack(Value(tr, Value::NotNull));
}
// ---- batch 32
// The constant-pool name of a multiname entry.
static __forceinline const Abc::StringView& Sfr31MnNameView(UPInt file, UPInt entry)
{
    return *reinterpret_cast<const Abc::StringView*>(Sfr31Rd(Sfr31Rd(file, 0x28), 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8);
}

// istype-style op: replaces the top value with whether it is an instance of the named class; names resolved at compile time are rejected.
// @0x14253bbe0
void Sfr31ExecIsTypeNamed(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& cvm = *reinterpret_cast<VM*>(Sfr31Rd(file, 0x20));
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntryW(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    if ((flags & 3) == 1 || (static_cast<UInt8>(flags >> 2) & 1) != 0)
    {
        const StringDataPtr sv = Sfr31MnNameView(file, entry).ToStringDataPtr();
        String name(sv.ToCStr(), sv.GetSize());
        cvm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x436), cvm, name.ToCStr(), "compile time"));
    }
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(reinterpret_cast<UPInt>(&cvm), 0x50));
    const UPInt tr = Sfr31ResolveClassTraits(vmAddr, file, entry);
    if (tr == 0)
    {
        VM& vm = *reinterpret_cast<VM*>(vmAddr);
        const StringDataPtr sv = Sfr31MnNameView(file, entry).ToStringDataPtr();
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f6), vm, sv.ToCStr()));
    }
    else
        top->SetBool(FUN_1425146d0(reinterpret_cast<VM*>(vmAddr), top, reinterpret_cast<const void*>(tr)));
}
// ---- batch 33
enum Sfr31Kind8 : UInt8 {};
// The instanceof test proper: whether the class (or, for a function, its prototype) is on the value's traits chain.
static __forceinline bool Sfr31InstanceOfChain(UPInt vmAddr, Value* v, const Value& cls, UInt32 flags)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UPInt chain = FUN_142507f60(vmAddr, v);
    const UPInt target = reinterpret_cast<UPInt>(&vm.GetValueTraits(cls));
    if (static_cast<Sfr31Kind8>(flags & 0x1f) == static_cast<Sfr31Kind8>(0xd))
    {
        for (; chain != 0; chain = Sfr31Rd(chain, 0x88))
            if (chain == target)
                return true;
        return false;
    }
    typedef void (*Fn)(UPInt);
    UPInt proto = Sfr31Rd(target, 0x80);
    if (proto == 0)
    {
        (*reinterpret_cast<Fn*>(Sfr31Rd(target, 0) + 0x68))(target);
        proto = Sfr31Rd(target, 0x80);
    }
    for (; chain != 0; chain = Sfr31Rd(chain, 0x88))
    {
        UPInt c = Sfr31Rd(chain, 0x80);
        if (c == 0)
        {
            (*reinterpret_cast<Fn*>(Sfr31Rd(chain, 0) + 0x68))(chain);
            c = Sfr31Rd(chain, 0x80);
        }
        if (reinterpret_cast<UPInt>(&reinterpret_cast<Class*>(c)->GetPrototype()) == proto)
            return true;
    }
    return false;
}

// instanceof: pops the class operand and replaces the top value with whether the class (or its prototype) is on the value's traits chain.
// MS2-FUNCTIONAL 0x14253b990: same blocks and calls, one tail-merged SetBool as in the exe; register allocation differs: the exe
// keeps the class Value's weak pointer in rbx and the stack Value in r15 and saves all six callee-saved registers in the prolog,
// while ours keeps the weak pointer in rbp and shrink-wraps rbx/rdi/r14.
// @0x14253b990
void Sfr31ExecInstanceOf(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    struct RawPair { void* a; void* b; };
    struct RawVal { UInt32 w0; void* w1; RawPair v; };
    Value* below;
    RawVal cls;
    void* weak;
    {
        const UPInt top = Sfr31Rd(vmAddr, 0x50);
        const RawVal& src = *reinterpret_cast<const RawVal*>(top);
        cls.w0 = src.w0;
        below = reinterpret_cast<Value*>(top - 0x20);
        weak = src.w1;
        cls.w1 = weak;
        cls.v = src.v;
        Sfr31Wr(vmAddr, 0x50, top - 0x20);
    }
    if ((cls.w0 & 0x1f) - 0xd > 1)
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x410), vm));
    else
    {
        const UInt32 bk = *reinterpret_cast<const UInt32*>(below) & 0x1f;
        below->SetBool((bk == 0 || (bk - 0xc <= 3 && Sfr31Rd(reinterpret_cast<UPInt>(below), 0x10) == 0)) ? false
                       : Sfr31InstanceOfChain(vmAddr, below, *reinterpret_cast<const Value*>(&cls), cls.w0));
    }
    if (static_cast<Sfr31Kind8>(cls.w0 & 0x1f) > static_cast<Sfr31Kind8>(9))
    {
        if ((static_cast<UInt8>(cls.w0 >> 9) & 1) != 0)
        {
            int* rc = static_cast<int*>(weak);
            if (--*rc == 0)
                Memory::pGlobalHeap->Free(rc);
        }
        else
            FUN_142521f00(&cls);
    }
}
// ---- batch 34
// astype-style op: replaces the top value with null when it is an instance of the named class; names resolved at compile time are rejected.
// @0x142532ff0
void Sfr31ExecAsTypeNamed(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& cvm = *reinterpret_cast<VM*>(Sfr31Rd(file, 0x20));
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntryW(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    if ((flags & 3) == 1 || (static_cast<UInt8>(flags >> 2) & 1) != 0)
    {
        const StringDataPtr sv = Sfr31MnNameView(file, entry).ToStringDataPtr();
        String name(sv.ToCStr(), sv.GetSize());
        cvm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x436), cvm, name.ToCStr(), "compile time"));
    }
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(reinterpret_cast<UPInt>(&cvm), 0x50));
    if (*reinterpret_cast<const UInt8*>(vmAddr + 0x180) != 0)
        return;
    const UPInt tr = Sfr31ResolveClassTraits(vmAddr, file, entry);
    if (tr == 0 || tr == FUN_142507f60(vmAddr, top))
    {
        VM& vm = *reinterpret_cast<VM*>(vmAddr);
        const StringDataPtr sv = Sfr31MnNameView(file, entry).ToStringDataPtr();
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f6), vm, sv.ToCStr()));
    }
    else
        top->SetNull();
}

// Raises verify error 0x42c naming two conflicting objects; an object whose name is the empty string is reported as null.
// SDK Tracer::ThrowMergeTypeError shape: the Values are temporaries of the Error, built right to left.
// @0x14252efe0
void Sfr31RaiseNameConflict(UPInt tr, UPInt a, UPInt b)
{
    VM& vm = *reinterpret_cast<VM*>(TrVM(tr));
    const Traits& ta = *reinterpret_cast<const Traits*>(a);
    const Traits& tb = *reinterpret_cast<const Traits*>(b);
    vm.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x42c), vm,
        Value(ta.GetName(), Value::InlineStr), Value(tb.GetName(), Value::InlineStr)));
}
// ---- batch 35
// Native with a required object argument: the popped value is handed to the owner's helper through its virtual call along with the remaining arguments.
// MS2-FUNCTIONAL 0x142537810: register only: the exe loads the popped object's Flags through edx, ours through ecx.
// @0x142537810
void Sfr31ExecOwnerCall(UPInt vmAddr, UPInt owner, UInt32 n)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsObject args(vm, n);
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt helper = Sfr31Rd(Sfr31Rd(owner, 0x40), 0x88);
        if (helper != 0)
        {
            typedef void (*Fn)(UPInt, UPInt, const Value*, UInt32, const Value*);
            (*reinterpret_cast<Fn*>(Sfr31Rd(helper, 0) + 0x78))(helper, Sfr31Rd(owner, 0x40), &args.ArgObject, n, args.GetCallArgs());
        }
    }
}
// ---- batch 36
// Native with a required object argument: the helper is invoked with the argument's traits and the remaining arguments.
// @0x142533df0
void Sfr31ExecCallWithTraits(UPInt vmAddr, UInt32 a, UInt32 n)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsObject args(vm, n);
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const Traits& tr = vm.GetValueTraits(args.ArgObject);
        FUN_142500260(vmAddr, a, reinterpret_cast<UPInt>(&tr), &args.ArgObject, n, const_cast<Value*>(args.GetCallArgs()));
    }
}

// Tracer op: the first argument's type picks the class traits (null/undefined -> Object) that are pushed.
// The vector-class resolve is written out (not via the UPInt FUN_ wrappers) so cl moves the class pointer into rcx before
// the traits into rdx, as the exe does.
// @0x142532bd0
void Sfr31TraceArgClassTraits(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    const UPInt vm = TrVM(s.Tracer());
    TrReadArgsObject args(*reinterpret_cast<VM*>(vm), *st, argc);
    const UPInt bp = reinterpret_cast<UPInt>(&args);
    const UPInt p = *reinterpret_cast<const UInt32*>(bp + 0x18) <= Sfr31Rd(bp, 0x128) ? Sfr31Rd(bp, 0x120) : bp + 0x20;
    const Value& a = *reinterpret_cast<const Value*>(p);
    UPInt tr = 0;
    switch (a.GetKind())
    {
    case Value::kUndefined:
        tr = Sfr31Rd(vm, 0x1f8);
        break;
    case Value::kClassTraits:
        tr = Sfr31Rd(p, 0x10);
        break;
    case Value::kObject:
        if (a.IsNull())
            tr = Sfr31Rd(vm, 0x1f8);
        break;
    case Value::kClass:
        tr = Sfr31Rd(Sfr31Rd(p, 0x10), 0x20);
        break;
    }
    UPInt out = Sfr31Rd(vm, 0x1f8);
    if (tr != 0)
    {
        if (tr == Sfr31Rd(vm, 0x220))
            out = Sfr31Rd(vm, 0x250);
        else if (tr == Sfr31Rd(vm, 0x228))
            out = Sfr31Rd(vm, 0x258);
        else if (tr == Sfr31Rd(vm, 0x218))
            out = Sfr31Rd(vm, 0x260);
        else if (tr == Sfr31Rd(vm, 0x230))
            out = Sfr31Rd(vm, 0x268);
        else
            out = reinterpret_cast<UPInt>(&reinterpret_cast<Classes::fl_vec::Vector&>(const_cast<Class&>(
                reinterpret_cast<VM*>(vm)->GetClassVector())).Resolve2Vector(*reinterpret_cast<const ClassTraits::Traits*>(tr)));
    }
    Sfr31RawTraitsVal v;
    v.w1 = 0;
    v.w2 = out;
    v.w0 = 9;
    s.OpStack().PushBack(*reinterpret_cast<const Value*>(&v));
}
// ---- batch 37
// Pops the operand stack top: a Namespace value becomes the target's namespace slot; anything else is converted to a string and a
// non-empty result creates a new Namespace for the slot.
// @0x142538560
void Sfr31ExecPushNamespace(UPInt vm, UPInt target)
{
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(vm, 0x50));
    const UInt32* tw = reinterpret_cast<const UInt32*>(top);
    if ((tw[0] & 0x1f) == 0xb)
        FUN_1423f1840(reinterpret_cast<void*>(target + 0x58), Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10));
    else
    {
        const UPInt mgr = Sfr31Rd(Sfr31Rd(vm, 0x10), 0x1e8);
        ASString str(reinterpret_cast<ASStringNode*>(mgr + 0x40));
        const bool ok = top->Convert2String(str);
        if (ok && *reinterpret_cast<const UInt32*>(Sfr31Rd(reinterpret_cast<UPInt>(&str), 0) + 0x20) != 0)
        {
            // SF_HEAP_AUTO_NEW(tr) Instances::fl::Namespace(...): the ctor's prefix argument is evaluated before the allocation.
            const Value& prefix = Value::GetUndefined();
            AllocInfo ai(0x148, 0, 0);   // StatMV_VM_Instance_Mem-family id the exe passes
            const UPInt tr = Sfr31Rd(Sfr31Rd(vm, 0x200), 0xc0);
            void* mem = Memory::pGlobalHeap->AllocAutoHeap(reinterpret_cast<void*>(tr), 0x60, &ai);
            const UPInt ns = mem != 0
                ? reinterpret_cast<UPInt>(Instances::Sfr33NsAccess19::Make(mem, Sfr31Rd(tr, 0x78), Sfr31Rd(tr, 0xe8), 0, &str, &prefix))
                : 0;
            const UPInt old = Sfr31Rd(target, 0x58);
            if (ns != old)
            {
                if (old != 0 && (old & 1) == 0 && (*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0)
                {
                    --*reinterpret_cast<UInt32*>(old + 0x10);
                    FUN_1423dfa20(reinterpret_cast<void*>(old));
                }
                Sfr31Wr(target, 0x58, ns);
            }
        }
    }
    reinterpret_cast<Value*>(Sfr31Rd(vm, 0x50))->~Value();
    Sfr31Wr(vm, 0x50, Sfr31Rd(vm, 0x50) - 0x20);
}

// ---- batch 38
// Remove only reads the key, so the exe (LTCG) releases its name and namespace from registers: dtor-less holder.
union Sfr31CtKeyHolder { Sfr19CtKey k; Sfr31CtKeyHolder(const ASString& n, const Instances::Namespace* p) : k(n, p) {} ~Sfr31CtKeyHolder() {} };
// Removes every class traits held in the array at +0xa0 from the owner's multiname hash, then clears the array.
// MS2-FUNCTIONAL 0x142530de0: regalloc: same code shape and length; exe swaps rbx/rdi for the ctr/pns and node registers and hoists the set-address load above the key stores
// @0x142530de0
void Sfr31UnregisterClassTraits(UPInt self)
{
    const UPInt size = Sfr31Rd(self, 0xa8);
    for (UPInt i = 0; i < size; ++i)
    {
        ClassTraits::Traits& ctr = *reinterpret_cast<ClassTraits::Traits*>(Sfr31Rd(Sfr31Rd(self, 0xa0), i * 8));
        if (Sfr31Rd(reinterpret_cast<UPInt>(&ctr), 0xc0) != 0)
        {
            // fast way: remove the entry by the instance traits' name and namespace
            InstanceTraits::Traits& itr = ctr.GetInstanceTraits();
            const ASString str_name = itr.GetName();
            const Instances::Namespace& ns = itr.GetNamespace();
            ASStringNode* const node = str_name.GetNode();
            const Instances::Namespace* const pns = &ns;
            Sfr31CtKeyHolder key(str_name, pns);
            FUN_142522350(reinterpret_cast<void*>(Sfr31Rd(self, 0x20) + 0x1c8), &key.k);
            if (pns != NULL)
            {
                if ((reinterpret_cast<UPInt>(pns) & 1) != 0)
                    key.k.pNs.GetRawRef() = reinterpret_cast<const Instances::Namespace*>(reinterpret_cast<UPInt>(pns) - 1);
                else
                    pns->Release();
            }
            node->Release();
        }
        else
        {
            // slow way: scan the hash for the entry holding this traits
            Sfr19CtHash& set = *reinterpret_cast<Sfr19CtHash*>(Sfr31Rd(self, 0x20) + 0x1c8);
            for (Sfr19CtHash::Iterator it = set.Begin(); !it.IsEnd(); ++it)
            {
                if (it->Second == &ctr)
                {
                    FUN_142522350(&set, const_cast<Sfr19CtKey*>(&it->First));
                    break;
                }
            }
        }
    }
    (reinterpret_cast<Sfr19TraitsArr*>(self + 0xa0)->*static_cast<void (Sfr19TraitsArr::*)(const void*, UPInt)>(&Sfr19TraitsArr::ResizeNoConstruct))(reinterpret_cast<const void*>(self + 0xa0), 0);
}

// ---- batch 39
static inline void Sfr31ReleaseRawVal(UPInt* v)
{
    UInt32* w = reinterpret_cast<UInt32*>(v);
    if ((w[0] & 0x1f) <= 9)
        return;
    if (((w[0] >> 9) & 1) == 0)
    {
        FUN_142521f00(v);
        return;
    }
    int* rc = reinterpret_cast<int*>(v[1]);
    if (--*rc == 0)
        Memory::pGlobalHeap->Free(rc);
}

// VM::MakeArray (0x142516270), inlined in the AS3_All.cpp SCU.
static SF_FORCEINLINE Pickable<Instances::fl::Array> Sfr31MakeArray(UPInt vm)
{
    InstanceTraits::fl::Array& itr = *reinterpret_cast<InstanceTraits::fl::Array*>(Sfr31Rd(Sfr31Rd(vm, 0x238), 0xc0));
    return itr.MakeInstance(itr);
}

// Value(Pickable<Array>) as the exe inlines it here (AS3_All.cpp SCU: Value::PickUnsafe(Object*) is visible).
template <> SF_FORCEINLINE Value::Value(Pickable<Instances::fl::Array> v) : Flags(0)
{
    SetKind(kObject);
    value = static_cast<Object*>(v.GetPtr());
}

// Resizes the array stored at a variable path, creating a new array of that length when the variable is not an Array.
// MS2-FUNCTIONAL 0x14252b3a0: frame layout: exe keeps parray in a frame slot (0xa0 frame, r12 saved in a home slot); ours puts it in rcx's home slot (0x90 frame); body otherwise the same
// @0x14252b3a0
bool Sfr31SetArraySize(UPInt root, UPInt path, int size, UInt32 flags)
{
    MovieRoot& mr = *reinterpret_cast<MovieRoot*>(root);
    const char* ppathToVar = reinterpret_cast<const char*>(path);
    const unsigned count = static_cast<unsigned>(size);
    Value retVal;
    if (FUN_142506000(root, &retVal, path) && retVal.IsObject())
    {
        Object* pobj = retVal.GetObject();
        if (pobj && pobj->GetTraits().GetTraitsType() == Traits_Array && pobj->GetTraits().IsInstanceTraits())
        {
            // Array already exists - just resize
            SparseArray& sa = *reinterpret_cast<SparseArray*>(reinterpret_cast<UPInt>(pobj) + 0x38);
            if (count != unsigned(sa.GetSize()))
                FUN_14241fe30(&sa, count);
            return true;
        }
    }
    // no array found - allocate new one, resize and set (VM::MakeArray inlined)
    Pickable<Instances::fl::Array> parray = Sfr31MakeArray(Sfr31Rd(root, 0x48));
    FUN_14241fe30(reinterpret_cast<void*>(reinterpret_cast<UPInt>(parray.GetPtr()) + 0x38), count);
    Value val(parray);
    GFx::Value gfxval;
    mr.ASValue2GFxValue(val, &gfxval);
    return mr.SetVariable(ppathToVar, gfxval, static_cast<MovieRoot::SetVarTypeArg>(flags));
}

// ---- batch 40
// pushwith: the (non-null) top of the operand stack moves onto the scope stack and is marked as a with-scope.
// The SDK shape: IsNullOrUndefined, a pushed undefined that PickUnsafe fills, then the reloaded top's dtor.
// @0x14253f7d0
void Sfr31ExecPushWithScope(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Value& v = **reinterpret_cast<Value**>(vmAddr + 0x50);
    if (v.IsNullOrUndefined())
    {
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(v.IsNull() ? 1009 : 1010), vm));
        return;
    }
    FUN_14241e430(reinterpret_cast<void*>(vmAddr + 0x160), &Value::GetUndefined());
    Value& back = vm.ScopeStack[vm.ScopeStack.GetSize() - 1];
    Value*& sp = *reinterpret_cast<Value**>(vmAddr + 0x50);
    ValueAssignCopies::PickUnsafeCopy(back, v);
    sp->~Value();
    --sp;
    back.SetWith(true);
}

// newclass (State::exec_newclass): pops one operand and pushes the class traits of class entry idx; scaleform.gfx
// classes resolve by name, others are the file's user-defined traits, and int, uint, Number and Boolean are not null.
// @0x14253c2f0
void Sfr31TraceClassTraitsFromIndex(State* st, UInt32 idx)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    FUN_14251ccc0(st, 1);
    const UPInt file = Sfr31Rd(Sfr31Rd(s.Tracer(), 0x20), 0x28);
    const UPInt abc = Sfr31Rd(file, 0x28);
    const UPInt cls = Sfr31Rd(Sfr31Rd(abc, 0x140), static_cast<UPInt>(idx) * 8);
    const SPInt mnIdx = *reinterpret_cast<const int*>(cls + 0x24);
    const UPInt mn = mnIdx == 0 ? abc + 0xe8 : mnIdx * 0x10 + Sfr31Rd(abc, 0xb8);
    const Instances::Namespace& ns = *reinterpret_cast<const Instances::Namespace*>(FUN_14250ae60(file, *reinterpret_cast<const int*>(mn + 4)));
    const ASString& uri = ns.GetUri();
    const bool gfx = uri.GetSize() >= DAT_143a2dd40.GetSize() && strncmp(uri.ToCStr(), DAT_143a2dd40.ToCStr(), DAT_143a2dd40.GetSize()) == 0;
    ClassTraits::Traits* ctr;
    if (gfx)
        ctr = reinterpret_cast<ClassTraits::Traits*>(Sfr31ResolveClassTraits(Sfr31Rd(Sfr31Rd(Sfr31Rd(s.Tracer(), 0x20), 0x28), 0x20), file, mn));
    else
        ctr = reinterpret_cast<ClassTraits::Traits*>(FUN_14250f9a0(Sfr31Rd(Sfr31Rd(Sfr31Rd(s.Tracer(), 0x20), 0x28), 0x20), file, cls));
    if (!ctr)
        ctr = reinterpret_cast<ClassTraits::Traits*>(Sfr31Rd(Sfr31Rd(Sfr31Rd(Sfr31Rd(s.Tracer(), 0x20), 0x28), 0x20), 0x1f8));
    // Tracer::CanBeNull: int, uint, Number and Boolean instances are never null.
    const UPInt it = reinterpret_cast<UPInt>(&ctr->GetInstanceTraits());
    const UPInt tvm = Sfr31Rd(Sfr31Rd(Sfr31Rd(s.Tracer(), 0x20), 0x28), 0x20);
    const bool notNull = it == Sfr31Rd(Sfr31Rd(tvm, 0x220), 0xc0) || it == Sfr31Rd(Sfr31Rd(tvm, 0x228), 0xc0) ||
                         it == Sfr31Rd(Sfr31Rd(tvm, 0x218), 0xc0) || it == Sfr31Rd(Sfr31Rd(tvm, 0x210), 0xc0);
    s.OpStack().PushBack(Value(*ctr, notNull ? Value::NotNull : Value::NullOrNot));
}

// VM::Resolve2ClassTraits' body over raw addresses. Written straight into the member, cl pushes rbx/rsi in the prolog
// where the exe saves them to the home slots; through this forceinline helper the member matches.
static SF_FORCEINLINE UPInt Sfr31FindClassTraitsByMn(UPInt vm, UPInt mn)
{
    UPInt found = FUN_14250d760(vm, mn);
    if (found == 0)
    {
        ASString str(reinterpret_cast<ASStringNode*>(Sfr31Rd(Sfr31Rd(vm, 0x10), 0x1e8) + 0x40));
        if (!reinterpret_cast<const Value*>(mn + 0x10)->Convert2String(str))
            return 0;
        ClassTraits::Traits* ct = FUN_142415520(reinterpret_cast<void*>(Sfr31Rd(vm, 0x298)), &str, reinterpret_cast<const Instances::Namespace*>(Sfr31Rd(mn, 8)));
        found = reinterpret_cast<UPInt>(ct);
        // the VM's class traits cache (+0x1c8): MultinameHash::Add copies the key (ASString + SPtr<Namespace>) and calls add<NodeRef> 0x1423eb030
        if (ct != 0)
            reinterpret_cast<TClassTraitsCache*>(vm + 0x1c8)->Add(str, *reinterpret_cast<const Instances::Namespace*>(Sfr31Rd(mn, 8)), ct);
    }
    return found;
}

// Finds the class traits for a multiname; unregistered ones are looked up on the global object by name and cached in the hash.
// @0x142525270
const ClassTraits::Traits* VM::Resolve2ClassTraits(const Multiname& mn)
{
    return reinterpret_cast<const ClassTraits::Traits*>(Sfr31FindClassTraitsByMn(reinterpret_cast<UPInt>(this), reinterpret_cast<UPInt>(&mn)));
}

// Tracer op: pops the call arguments and two operands and pushes the instance traits of the second one; the int, uint,
// Number and Boolean traits are pushed as NotNull, any other as NullOrNot.
// MS2-FUNCTIONAL 0x142533470: the exe compiled TR::ReadArgs::ReadArgs and ~ReadArgs (0x1424d9640, 0x1424dea90; ours in
// sfr_as3_15) in this TU, so it schedules the second ++ReadNum after the vm load and keeps each popped Value's Flags in ebx
// across the weak-ref Free. Ours reloads them from memory (same cause as 0x142536dd0).
// @0x142533470
void Sfr31TraceTraitsOfSecond(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsObjectValue args(*reinterpret_cast<VM*>(TrVM(s.Tracer())), *st, argc);
    InstanceTraits::Traits& itr = FUN_14250a060(*reinterpret_cast<VM*>(TrVM(s.Tracer())), args.ArgValue);
    const UPInt tracer = s.Tracer();
    const bool notNull = &itr == &TrITraits(tracer, 0x220) || &itr == &TrITraits(tracer, 0x228) ||
        &itr == &TrITraits(tracer, 0x218) || &itr == &TrITraits(tracer, 0x210);
    s.OpStack().PushBack(Value(itr, notNull ? Value::NotNull : Value::NullOrNot));
}

// Value(Object*) inline, as sfr_as3_17 defines it.
SF_FORCEINLINE Value::Value(Object* v, InlineObjType)
    : Flags(kObject)
    , value(v)
{
    if (v)
        v->AddRef();
}

// findproperty-style resolve: pushes the property's value, or the VM's fallback object when it does not resolve.
// The weak-ref clear of the PropRef value is one 16-byte zero store in the exe (Sfr31PropRefW).
// @0x1425389b0
void Sfr31ExecFindPropOrGlobal(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ExecReadMn rd(file, idx);
    Sfr31MnBox& mn = rd.mn;
    if (vm.IsException())
        return;
    Sfr31PropRefW pr;
    FUN_142502570(vmAddr, &pr, &mn.Get());
    const UPInt f = pr.f;
    if ((*reinterpret_cast<const UInt32*>(&pr.V()) & 0x1f) == 0 || f == 1 || ((static_cast<UInt8>(f >> 1) & 1) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
        ExecPushCopy(&vm, Value(FUN_14250a550(vm), Value::InlineObj));
    else
        ExecPushCopy(&vm, pr.V());
}

// Verifies that the top of the operand stack is usable as the scope object named by the multiname (name check, class lookup, type check).
// @0x142536b90
void Sfr31ExecCheckScopeObject(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& cvm = *reinterpret_cast<VM*>(Sfr31Rd(file, 0x20));
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntryW(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    if ((flags & 3) == 1 || (static_cast<UInt8>(flags >> 2) & 1) != 0)
    {
        const StringDataPtr sv = Sfr31MnNameView(file, entry).ToStringDataPtr();
        String name(sv.ToCStr(), sv.GetSize());
        cvm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x436), cvm, name.ToCStr(), "compile time"));
    }
    const UPInt top = Sfr31Rd(reinterpret_cast<UPInt>(&cvm), 0x50);
    if (*reinterpret_cast<const UInt8*>(vmAddr + 0x180) != 0)
        return;
    const ClassTraits::Traits* tr = reinterpret_cast<const ClassTraits::Traits*>(Sfr31ResolveClassTraits(vmAddr, file, entry));
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    if (tr != NULL)
    {
        Value& v = *reinterpret_cast<Value*>(top);
        if (!tr->Coerce(v, v))
            vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x40a), vm, v, tr->GetName().ToCStr()));
    }
    else
    {
        const StringDataPtr sv = Sfr31MnNameView(file, entry).ToStringDataPtr();
        vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42d), vm, sv.ToCStr(), "any object on the scope stack"));
    }
}

// Value::Convert2PrimitiveValueUnsafe with hintNone, inlined here in the exe.
static __forceinline bool Sfr31Convert2Primitive(const Value& self, Value& result)
{
    if (self.IsPrimitive() || (self.IsObject() && self.GetObject() == NULL))
        result.Assign(self);
    else
    {
        switch (self.GetKind())
        {
        case Value::kNamespace:
            // The exe calls the out-of-line operator= (0x1424e0d40).
            (result.*static_cast<Value& (Value::*)(const ASString&)>(&Value::operator=))(self.GetNamespace()->GetUri());
            return true;
        case Value::kThunk:
        case Value::kThunkClosure:
        case Value::kVTableInd:
        case Value::kVTableIndClosure:
            result.SetNumber(0.0);
            return true;
        default:
            break;
        }
        FUN_142508bd0(reinterpret_cast<UPInt>(self.GetObject()), &result, 0);
        if (self.GetObject()->GetVM().IsException())
            return false;
    }
    return true;
}


// Converts a value in place to its primitive form (objects through their conversion hook); *ok tells whether it succeeded.
// MS2-FUNCTIONAL 0x14252f790: SDK ToPrimitiveValue with Convert2PrimitiveValueUnsafe inlined; same calls, but &local
// reaches out-of-TU callees here, so cl reloads the source and local Flags/Bonus where the exe keeps them in ebx/rdx
// (and saves r14 for the result byte).
// @0x14252f790
UInt8* Sfr31ValueToPrimitive(Value* v, UInt8* ok)
{
    // SDK Value::ToPrimitiveValue.
    Value local = Value::GetUndefined();
    bool result = false;
    if (Sfr31Convert2Primitive(*v, local))
    {
        v->Swap(local);
        result = true;
    }
    *ok = result;
    return ok;
}

// deleteproperty: replaces the top value (the object) with whether the property named by the multiname was deleted.
// @0x142538040
void Sfr31ExecIn(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ExecReadMnObjectRef args(file, idx);
    if (vm.IsException())
        return;
    const Value& name = *reinterpret_cast<const Value*>(&args.ArgMN.w2);
    bool result = false;
    if (vm.GetXMLSupport().IsEnabled() && name.IsObject() && name.GetObject() != NULL)
    {
        const Traits& tr = name.GetObject()->GetTraits();
        if (tr.GetTraitsType() == Traits_XMLList && tr.IsInstanceTraits())
            return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x45f), vm, vm.GetValueTraits(name).GetName().ToCStr()));
    }
    if (args.ArgObject.IsPrimitive())
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x460), vm, name, args.ArgObject));
    if (args.ArgObject.IsObject())
    {
        Object* obj = args.ArgObject.GetObject();
        if (obj->GetTraits().IsDynamic())
            result = obj->DeleteProperty(args.ArgMN.Get());
        if (vm.IsException())
            return;
    }
    args.ArgObject.SetBool(result);
}

// getproperty-style op: moves the object off the stack top, reads the named property into the slot and raises a ReferenceError
// when a primitive has no such property.
// @0x142539be0
void Sfr31ExecGetProp(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ExecReadMnObjectRef args(file, idx);
    if (vm.IsException())
        return;
    Value _this(args.ArgObject, PickValue);
    char r;
    if (!*FUN_14250d2f0(&r, vm, _this, args.ArgMN.Get(), args.ArgObject))
    {
        if (vm.IsException())
            return;
        if (_this.IsPrimitive())
            return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42d), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2), _this));
    }
}

// ---- batch 41
static inline UPInt Sfr31HashCap(UPInt n)
{
    UPInt c = 8;
    while (c < n)
        c <<= 1;
    return c;
}

static inline UInt64 Sfr31Sdbm(const void* p, int len)
{
    const UInt8* b = static_cast<const UInt8*>(p);
    UInt64 h = 5381;
    for (int i = len - 1; i >= 0; --i)
        h = h * 65599 + b[i];
    return h;
}

static inline void Sfr31DropSPtr(UPInt slot)
{
    const UPInt v = Sfr31Rd(slot, 0);
    if (v == 0)
        return;
    if ((v & 1) == 0)
    {
        UInt32* rc = reinterpret_cast<UInt32*>(v + 0x10);
        if ((*rc & 0x3fffff) != 0)
        {
            --*rc;
            FUN_1423dfa20(reinterpret_cast<void*>(v));
        }
    }
    else
        Sfr31Wr(slot, 0, v - 1);
}

static inline void Sfr31DropStrNode(UPInt slot)
{
    const UPInt n = Sfr31Rd(slot, 0);
    if (n != 0)
        Sfr31ReleaseStr(n);
}

static inline void Sfr31DropResource(UPInt slot)
{
    const UPInt r = Sfr31Rd(slot, 0);
    if (r != 0)
        FUN_1425a4030(reinterpret_cast<void*>(r));
}

// AutoPtr<ArrayLH<...>> entry: pointer at +0x10, owned flag at +0x18.
static inline void Sfr31DropAutoPtr(UPInt e)
{
    const UPInt a = Sfr31Rd(e, 0x10);
    if (a != 0)
    {
        if (*reinterpret_cast<UInt8*>(e + 0x18) != 0)
        {
            *reinterpret_cast<UInt8*>(e + 0x18) = 0;
            FUN_1424dc730(reinterpret_cast<void*>(a));
            Memory::pGlobalHeap->Free(reinterpret_cast<void*>(a));
        }
        Sfr31Wr(e, 0x10, 0);
    }
    *reinterpret_cast<UInt8*>(e + 0x18) = 0;
}

typedef void* (*Sfr31VAlloc)(UPInt self, UPInt size, void* info);

// Allocates and empties a hash table body of cap entries (header: count at +0, mask at +8, entries from +0x10).
static inline UPInt Sfr31HashNew(UPInt heap, UPInt cap, UPInt stride, UInt32 id, int mode)
{
    UPInt t;
    if (mode == 2)
        t = reinterpret_cast<UPInt>(Memory::AllocAutoHeap(reinterpret_cast<const void*>(heap), cap * stride + 0x10, AllocInfo(id, 0, 0)));
    else
    {
        UInt32 info[2] = { id, 0 };
        const UPInt self = (mode == 1) ? reinterpret_cast<UPInt>(Memory::pGlobalHeap) : heap;
        t = reinterpret_cast<UPInt>(reinterpret_cast<Sfr31VAlloc>(Sfr31Rd(Sfr31Rd(self, 0), 0x50))(self, cap * stride + 0x10, info));
    }
    Sfr31Wr(t, 0, 0);
    Sfr31Wr(t, 8, cap - 1);
    for (UPInt i = 0; i < cap; ++i)
        Sfr31Wr(t + 0x10, i * stride, UPInt(-2));
    return t;
}

// Chained insert into a hash table whose entries cache the slot index (next at +0, slot at +8, key and value at +0x10).
static inline void Sfr31HashAddCached(UPInt* nt, UPInt heap, UInt64 hash, UPInt k0, UPInt k1)
{
    FUN_1424eef00(nt, heap);
    ++*reinterpret_cast<SPInt*>(*nt);
    const UPInt mask = Sfr31Rd(*nt, 8);
    const UPInt idx = hash & mask;
    const UPInt base = *nt + 0x10;
    const UPInt nat = base + idx * 0x20;
    const UPInt oldNext = Sfr31Rd(nat, 0);
    if (oldNext == UPInt(-2))
    {
        Sfr31Wr(nat, 0, UPInt(-1));
        Sfr31Wr(nat, 0x10, k0);
        Sfr31Wr(nat, 0x18, k1);
    }
    else
    {
        UPInt fr = idx;
        do
            fr = (fr + 1) & mask;
        while (Sfr31Rd(base + fr * 0x20, 0) != UPInt(-2));
        const UPInt free = base + fr * 0x20;
        const UPInt slot = Sfr31Rd(nat, 8);
        Sfr31Wr(free, 0, oldNext);
        Sfr31Wr(free, 8, slot);
        Sfr31Wr(free, 0x10, Sfr31Rd(nat, 0x10));
        Sfr31Wr(free, 0x18, Sfr31Rd(nat, 0x18));
        if (slot == idx)
            Sfr31Wr(nat, 0, fr);
        else
        {
            UPInt p = base + slot * 0x20;
            UPInt nx = Sfr31Rd(p, 0);
            while (nx != idx)
            {
                p = base + nx * 0x20;
                nx = Sfr31Rd(p, 0);
            }
            Sfr31Wr(p, 0, fr);
            Sfr31Wr(nat, 0, UPInt(-1));
        }
        Sfr31Wr(nat, 0x10, k0);
        Sfr31Wr(nat, 0x18, k1);
    }
    Sfr31Wr(nat, 8, idx);
}

// Dynamic-attribute node (key {id, name string}, Value) assignment over an existing node.
static inline void Sfr31DynNodeAssign(UPInt dst, UPInt src)
{
    *reinterpret_cast<UInt32*>(dst) = *reinterpret_cast<const UInt32*>(src);
    const UPInt nn = Sfr31Rd(src, 8);
    ++*reinterpret_cast<int*>(nn + 0x18);
    Sfr31ReleaseStr(Sfr31Rd(dst, 8));
    Sfr31Wr(dst, 8, nn);
    reinterpret_cast<Value*>(dst + 0x10)->Assign(*reinterpret_cast<const Value*>(src + 0x10));
}

// ---- batch 42
// Tracer::ValueIsOfType(const Value&, const ClassTraits::Traits&): class traits and classes test their class traits,
// any other value the instance traits Tracer::GetInstanceTraits gives it (VM::GetInstanceTraits inlined; the cases are
// in the exe's block order).
// @0x142531260
bool Sfr31SetTraitsForValue(UPInt st, const UInt32* v, UPInt traits)
{
    // Tracer::ValueIsOfType with Tracer::GetInstanceTraits and VM::GetInstanceTraits inlined.
    const UPInt pv = reinterpret_cast<UPInt>(v);
    const int k = static_cast<int>(v[0] & 0x1f);
    switch (k)
    {
    case 9:     // kClassTraits
        return FUN_1425149a0(traits, Sfr31Rd(pv, 0x10));
    case 0xd:   // kClass
        return FUN_1425149a0(traits, Sfr31Rd(Sfr31Rd(pv, 0x10), 0x20));
    default:
        break;
    }
    UPInt itr;
    if ((k >= 0xc && k <= 0xf) && Sfr31Rd(pv, 0x10) == 0)
        itr = Sfr31Rd(Sfr31Rd(Sfr31Rd(Sfr31Rd(st, 0x20), 0x28), 0x20), 0x270);   // Tracer null type
    else
    {
        switch (k)
        {
        case 0:     // kUndefined: the class type
            itr = Sfr31Rd(Sfr31Rd(Sfr31Rd(Sfr31Rd(Sfr31Rd(st, 0x20), 0x28), 0x20), 0x1f0), 0xc0);
            break;
        case 8:     // kInstanceTraits
            itr = Sfr31Rd(pv, 0x10);
            break;
        case 9:     // kClassTraits
            itr = Sfr31Rd(Sfr31Rd(pv, 0x10), 0xc0);
            break;
        default:
        {
            const UPInt vm = Sfr31Rd(Sfr31Rd(Sfr31Rd(st, 0x20), 0x28), 0x20);
            switch (k)
            {
            case 1: itr = Sfr31Rd(Sfr31Rd(vm, 0x210), 0xc0); break;
            case 2: itr = Sfr31Rd(Sfr31Rd(vm, 0x220), 0xc0); break;
            case 3: itr = Sfr31Rd(Sfr31Rd(vm, 0x228), 0xc0); break;
            case 4: itr = Sfr31Rd(Sfr31Rd(vm, 0x218), 0xc0); break;
            case 10:
                if (Sfr31Rd(pv, 0x10) != 0)
                    itr = Sfr31Rd(Sfr31Rd(vm, 0x230), 0xc0);
                else
                    itr = Sfr31Rd(Sfr31Rd(vm, 0x1f8), 0xc0);
                break;
            case 0xb: itr = Sfr31Rd(Sfr31Rd(vm, 0x200), 0xc0); break;
            case 0xc:
            case 0xe:
            case 0xf:
            {
                const UPInt obj = Sfr31Rd(pv, 0x10);
                if ((k >= 0xc && k <= 0xf) && obj == 0)
                    itr = Sfr31Rd(Sfr31Rd(vm, 0x1f8), 0xc0);
                else
                    itr = Sfr31Rd(obj, 0x20);
                break;
            }
            case 0xd:
            {
                const UPInt obj = Sfr31Rd(pv, 0x10);
                if ((k >= 0xc && k <= 0xf) && obj == 0)
                    itr = Sfr31Rd(Sfr31Rd(vm, 0x1f8), 0xc0);
                else
                    itr = Sfr31Rd(Sfr31Rd(obj, 0x20), 0xc0);
                break;
            }
            case 5:
            case 0x10: itr = Sfr31Rd(Sfr31Rd(vm, 0x208), 0xc8); break;
            case 7:
            case 0x11: itr = Sfr31Rd(Sfr31Rd(vm, 0x208), 0xe0); break;
            case 8: itr = Sfr31Rd(pv, 0x10); break;
            case 9:
                itr = Sfr31Rd(Sfr31Rd(pv, 0x10), 0xc0);
                if (itr == 0)
                    itr = Sfr31Rd(vm, 0x278);
                break;
            default: itr = Sfr31Rd(vm, 0x278); break;
            }
            break;
        }
        }
    }
    return FUN_142514560(itr, Sfr31Rd(traits, 0xc0));
}

// VM::GetClassTraits as the exe inlines it into Resolve2ClassTraits: the cache lookup, the global object's
// classes on a miss, and the cache Add (MultinameHash::Add) expanded too.
static __forceinline ClassTraits::Traits* Sfr31GetClassTraitsInl(VM* vm, const ASString& name, const Instances::Namespace& ns)
{
    ClassTraits::Traits** found = FUN_142414ac0(&vm->ClassTraitsSet, name, ns);
    if (found != NULL && *found != NULL)
        return *found;
    ClassTraits::Traits* ct = FUN_142415520(reinterpret_cast<void*>(VmRd(vm, 0x298)), &name, &ns);
    ClassTraits::Traits* added = ct;
    if (ct != NULL)
        vm->ClassTraitsSet.Add(name, ns, added);
    return ct;
}
// The public namespace for a package URI (the VM's public namespace for the empty URI); the URI string dies here.
static __forceinline Pickable<Instances::Namespace> Sfr31PublicNsOf(VM* vm, const ASString& uri)   // VM::MakeInternedNamespace
{
    if (uri.IsEmpty())
        return Pickable<Instances::Namespace>(vm->PublicNamespace.GetPtr(), PickValue);
    return static_cast<InstanceTraits::fl::Namespace&>(vm->GetClassTraitsNamespace().GetInstanceTraits())
                                                          .MakeInternedInstance(Abc::NS_Public, uri, Value::GetUndefined());
}
static __forceinline Pickable<Instances::Namespace> Sfr31PublicNsOf(VM* vm, const char* pkg)
{ if (!pkg) pkg = ""; return Sfr31PublicNsOf(vm, vm->GetStringManager().CreateString(pkg)); }
// The class traits of a class description: its package namespace plus its name, resolved through the VM's class traits cache.
// VM::GetClassTraits(ClassInfo): MakeInternedNamespace (Pickable, uri overload) + single-return if block, info re-read
// @0x142525ca0
ClassTraits::Traits* Sfr31GetClassTraitsByInfo(VM* vm, UPInt info)
{
    ClassTraits::Traits* r = NULL;
    if (Sfr31Rd(info, 0x18) != 0)
    {
        const SPtr<Instances::Namespace> ns = Sfr31PublicNsOf(vm, reinterpret_cast<const char*>(Sfr31Rd(Sfr31Rd(info, 0x18), 0x10)));
        r = Sfr31GetClassTraitsInl(vm, vm->GetStringManager().CreateConstString(reinterpret_cast<const char*>(Sfr31Rd(Sfr31Rd(info, 0x18), 8))), *ns.GetPtr());
    }
    //
    //
    return r;
}

// VMAbcFile::GetMultiname(ind): index 0 is the file's any-type multiname.
static inline UPInt Sfr31MnEntryAt(UPInt link, int ind)
{
    return reinterpret_cast<UPInt>(&reinterpret_cast<const Abc::ConstPool*>(Sfr31Rd(link, 0x28) + 0x30)->GetMultiname(ind));
}
// ---- batch 43
// Resolves the class traits named by a multiname entry; the Vector.<T> cases map to the specialised builtin traits.
// MS2-FUNCTIONAL 0x142524f60: the exe's GetMultiname re-tests idx as an int (ours tests the SPInt) and loads the name node into rcx for the void compare and shared dtor tail
// @0x142524f60
UPInt Sfr31ResolveClassTraits(UPInt vmAddr, UPInt link, UPInt entry)
{
    if (entry == Sfr31Rd(link, 0x28) + 0xe8)
        return Sfr31Rd(vmAddr, 0x1f0);
    VM* vm = reinterpret_cast<VM*>(vmAddr);
    const ASString name(reinterpret_cast<VMAbcFile*>(link)->GetInternedString(static_cast<UPInt>(*reinterpret_cast<const int*>(entry + 8))));
    UPInt r;
    if (name == *reinterpret_cast<const ASString*>(Sfr31Rd(vmAddr, 0x10) + 0x18))
        r = Sfr31Rd(vmAddr, 0x1f8);
    else
    {
        const Instances::Namespace& ns = *reinterpret_cast<const Instances::Namespace*>(FUN_14250ae60(link, *reinterpret_cast<const int*>(entry + 4)));
        r = reinterpret_cast<UPInt>(Sfr31GetClassTraitsInl(vm, name, ns));
        if (r == Sfr31Rd(vmAddr, 0x248))
        {
            const int idx = *reinterpret_cast<const int*>(entry + 0xc);
            UPInt r2; if (idx == 0) r2 = Sfr31Rd(vmAddr, 0x1f8); else r2 = Sfr31ResolveClassTraits(vmAddr, link, Sfr31MnEntryAt(link, idx));
            if (r2 != 0)
            {
                if (r2 == Sfr31Rd(vmAddr, 0x220))
                    r = Sfr31Rd(vmAddr, 0x250);
                else if (r2 == Sfr31Rd(vmAddr, 0x228))
                    r = Sfr31Rd(vmAddr, 0x258);
                else if (r2 == Sfr31Rd(vmAddr, 0x218))
                    r = Sfr31Rd(vmAddr, 0x260);
                else if (r2 == Sfr31Rd(vmAddr, 0x230))
                    r = Sfr31Rd(vmAddr, 0x268);
                else if (Sfr31Rd(r2, 0xc0) != 0)
                    r = FUN_142563380(FUN_142507b80(Sfr31Rd(r, 0xc0)), r2);
            }
        }
    }
    return r;
}
// ---- batch 44
// setsuper: pops the value and the object, then stores through the parent traits' fixed slot or raises a ReferenceError.
// The exe inlines SetSuperProperty (0x14252a150) here.
static __forceinline CheckResult Sfr31SetSuperPropertyInl(VM& vm, const Traits* tr, const Value& obj, const Multiname& mn, const Value& v)
{
    if (tr == 0)
        tr = &vm.GetValueTraits(obj);
    const Traits* parent = tr->GetParent();
    if (parent != 0)
    {
        UPInt ind = 0;
        const SlotInfo* si = FindFixedSlot(vm, *parent, mn, ind, 0);
        char res;
        return CheckResult(si != 0 && *Sfr27SlotSetValueThis(si, &res, &vm, &v, &obj, static_cast<VTable*>(FUN_14250fa80(parent))) != 0);
    }
    return false;
}
// @0x142540490
void Sfr31ExecSetSuper(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ExecReadValueMnObject args(file, idx);
    if (vm.IsException())
        return;
    const UPInt n = Sfr31Rd(vmAddr, 0x78) - 1;
    const Traits* ot = *reinterpret_cast<const Traits* const*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (n >> 6) * 8) + 0x40 + (n & 0x3f) * 0xa8);
    if (!Sfr31SetSuperPropertyInl(vm, ot, args.ArgObject, args.ArgMN.Get(), args.ArgValue))
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x40b), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
}
// ---- batch 45
// Native with a required object argument: the current frame's parent-traits helper is invoked with the remaining arguments.
// @0x1425363e0
void Sfr31ExecCallSuper(UPInt vmAddr, UInt32 a, UInt32 n)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsObject args(vm, n);
    if (vm.IsException())
        return;
    // the running frame's origination traits, else the object's own
    const UPInt cnt = Sfr31Rd(vmAddr, 0x78) - 1;
    const Traits* ot = *reinterpret_cast<const Traits* const*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (cnt >> 6) * 8) + 0x40 + (cnt & 0x3f) * 0xa8);
    if (ot == NULL)
        ot = &vm.GetValueTraits(args.ArgObject);
    const Traits* parent_tr = ot->GetParent();
    if (parent_tr == NULL)
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x40b), vm, "Couldn't find parent property"));
    FUN_142500260(vmAddr, a, reinterpret_cast<UPInt>(parent_tr), &args.ArgObject, n, const_cast<Value*>(args.GetCallArgs()));
}
// ---- batch 46
ASString FUN_14250bc60(const Traits& tr);
const char* AsString(Abc::NamespaceKind kind);   // 0x1424ed700
inline const char* FUN_1424ed700(Abc::NamespaceKind kind) { return AsString(kind); }

// The name a value's type shows under in messages (VM::describeTypeEx): the builtin names, qualified class names or the
// kind-specific forms.
// MS2-FUNCTIONAL 0x1425322c0: SDK describeTypeEx switch; Function/ThunkFunction fields read raw, codegen differs
// @0x1425322c0
ASString* Sfr31ValueTypeName(UPInt vmAddr, ASString* out, const UInt32* v)
{
    const Value& value = *reinterpret_cast<const Value*>(v);
    const StringManager& sm = *reinterpret_cast<const StringManager*>(Sfr31Rd(vmAddr, 0x10));
    ASStringNode* node;
    switch (value.GetKind())
    {
    case Value::kUndefined:
        node = sm.GetBuiltin(AS3Builtin_undefined).GetNode();
        break;
    case Value::kBoolean:
        node = sm.GetBuiltin(AS3Builtin_boolean).GetNode();
        break;
    case Value::kInt:
        node = sm.GetStringManager()->CreateConstStringNode("int", 3, 0);
        break;
    case Value::kUInt:
        node = sm.GetStringManager()->CreateConstStringNode("uint", 4, 0);
        break;
    case Value::kNumber:
        node = sm.GetBuiltin(AS3Builtin_number).GetNode();
        break;
    case Value::kString:
        if (value.GetStringNode())
            node = sm.GetBuiltin(AS3Builtin_string).GetNode();
        else
            node = sm.GetBuiltin(AS3Builtin_null).GetNode();
        break;
    case Value::kThunk:
        new (out) ASString(FUN_14250f330(sm.GetBuiltin(AS3Builtin_empty_), value.AsThunk(), false));
        return out;
    case Value::kThunkFunction:
    {
        const UPInt tf = reinterpret_cast<UPInt>(&value.AsThunkFunction());
        const Traits& otr = *reinterpret_cast<const Traits*>(Sfr31Rd(tf, 0x48));
        new (out) ASString(FUN_14250f330(FUN_14250bc60(otr), *reinterpret_cast<const ThunkInfo*>(Sfr31Rd(tf, 0x40)), false));
        return out;
    }
    case Value::kVTableInd:
        new (out) ASString(FUN_14250fc60(sm.GetBuiltin(AS3Builtin_empty_), value.GetTraits().GetVT(), value.GetVTableInd(), false));
        return out;
    case Value::kVTableIndClosure:
    {
        const SInt32 ind = value.GetVTableInd();
        const VTable& vt = value.GetClosure()->GetTraits().GetVT();
        new (out) ASString(FUN_14250fc60(FUN_14250bc60(value.GetClosure()->GetTraits()), vt, ind, true));
        return out;
    }
    case Value::kFunction:
    {
        const UPInt f = reinterpret_cast<UPInt>(&value.AsFunction());
        const UPInt ftr = Sfr31Rd(f, 0x20);
        const Traits& otr = *reinterpret_cast<const Traits*>(FUN_142416720(reinterpret_cast<const void*>(ftr)));
        const ASString name = reinterpret_cast<const Traits*>(Sfr31Rd(f, 0x20))->GetName();
        new (out) ASString(FUN_14250bc60(otr) + "::" + name);
        return out;
    }
    case Value::kObject:
        if (value.GetObject())
            new (out) ASString(FUN_14250bc60(value.GetObject()->GetTraits()));
        else
        {
            node = sm.GetBuiltin(AS3Builtin_null).GetNode();
            break;
        }
        return out;
    case Value::kClass:
        if (value.GetObject())
            new (out) ASString(FUN_14250bc60(value.GetObject()->GetTraits()).AppendCharNode('$'));
        else
        {
            node = sm.GetBuiltin(AS3Builtin_null).GetNode();
            break;
        }
        return out;
    case Value::kNamespace:
    {
        const Instances::Namespace& ns = value.AsNamespace();
        ASString result = sm.CreateConstString(AsString(ns.GetKind()));
        if (!ns.GetUri().IsEmpty())
        {
            result += " ";
            result += ns.GetUri();
        }
        new (out) ASString(result);
        return out;
    }
    case Value::kThunkClosure:
        new (out) ASString(FUN_14250f330(FUN_14250bc60(value.GetClosure()->GetTraits()), value.AsThunk(), true));
        return out;
    default:
        node = sm.GetBuiltin(AS3Builtin_empty_).GetNode();
        break;
    }
    new (out) ASString(node);
    return out;
}

// ---- batch 47
// Storage for a Value whose dtor expands Value::ReleaseInternal in place (as sfr_as3_17's Sfr33InlineReleaseValue).
struct Sfr19InlineReleaseValue
{
    union
    {
        UPInt Align;
        UByte Buf[sizeof(Value)];
    };
    Value& Get() { return *reinterpret_cast<Value*>(Buf); }
    static void ReleaseGC(Object* p)
    {
        if (!(reinterpret_cast<UPInt>(p) & 1) && p)
            p->Release();
    }
    __forceinline ~Sfr19InlineReleaseValue()
    {
        Value& v = Get();
        if (!v.IsRefCounted())
            return;
        if (v.IsWeakRef())
        {
            (*reinterpret_cast<WeakProxy**>(Buf + 0x08))->Release();
            return;
        }
        switch (v.GetKind())
        {
        case Value::kString:
            (*reinterpret_cast<ASStringNode**>(Buf + 0x10))->Release();
            break;
        case Value::kNamespace:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kObject:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kClass:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kFunction:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kThunkFunction:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x10));
            break;
        case Value::kThunkClosure:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x18));
            break;
        case Value::kVTableIndClosure:
            ReleaseGC(*reinterpret_cast<Object**>(Buf + 0x18));
            break;
        default:
            break;
        }
    }
};
// Value(Pickable<Object>): a picked kObject (no AddRef); the dtor is the kObject arm of Value::ReleaseInternal.
struct Sfr19PickedObjectValue
{
    UInt32  Flags;
    UPInt   Bonus;
    Object* Obj;
    UPInt   Pad;
    __forceinline explicit Sfr19PickedObjectValue(Object* p) : Flags(Value::kObject), Bonus(0), Obj(p) {}
    const Value& Get() const { return *reinterpret_cast<const Value*>(this); }
    __forceinline ~Sfr19PickedObjectValue() { Sfr19InlineReleaseValue::ReleaseGC(Obj); }
};
// The SDK Object::AddDynamicSlotValuePair(const ASString&), which the exe inlines (LTCG) into newobject.
struct Sfr19DynObj : public Object
{
    __forceinline void AddDyn(const ASString& prop_name, const Value& v, SlotInfo::Attribute a = SlotInfo::aNone)
    {
        DynAttrs.Set(DynAttrsKey(prop_name, a == SlotInfo::aDontEnum), v);
    }
};
// newobject: builds a plain Object from n name/value pairs popped off the operand stack and pushes it.
// MS2-FUNCTIONAL 0x14253cdc0: SDK VM::exec_newobject shape with the exe's inlined Hash::Set, ~Value and PushBack; regalloc differs
// (the exe keeps the count in rbx/r12 and zero in r14, ours r12/esi; the SDK up-counting loop does not become the exe's count-down here)
// @0x14253cdc0
void Sfr31ExecNewObject(UPInt vmAddr, UInt32 n)
{
    InstanceTraits::Interface* tr = reinterpret_cast<InstanceTraits::Interface*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x1f8), 0xc0));
    Pickable<Instances::fl::Object> o = tr->MakeInstance(*tr);
    for (UInt32 i = n; i != 0; --i)
    {
        Sfr19InlineReleaseValue value;
        ::new (value.Buf) Value(ValueStack::Of(*reinterpret_cast<VM*>(vmAddr)));
        Sfr19InlineReleaseValue name;
        ::new (name.Buf) Value(ValueStack::Of(*reinterpret_cast<VM*>(vmAddr)));
        static_cast<Sfr19DynObj*>(static_cast<Object*>(o.GetPtr()))->AddDyn(name.Get().AsString(), value.Get());
    }
    // OpStack.PushBack(o): the Value(Pickable) temporary is a picked kObject (no AddRef), released after the copy.
    Sfr19PickedObjectValue tmp(o.GetPtr());
    ExecPushCopy(reinterpret_cast<VM*>(vmAddr), tmp.Get());
}
// ---- batch 48
// The SDK ReadArgsMn: the call arguments, the file, then the multiname read off the stack.
struct Sfr31ReadArgsMn : public AS3::ReadArgs
{
    __forceinline Sfr31ReadArgsMn(UPInt link, UInt32 argc, UInt32 idx)
        : AS3::ReadArgs(*reinterpret_cast<VM*>(Sfr31Rd(link, 0x20)), argc), File(*reinterpret_cast<VMAbcFile*>(link))
        , ArgMN(File, Sfr31MnEntryW(reinterpret_cast<UPInt>(&File), idx))
    {
        FUN_1425201f0(this, &ArgMN.Get());
    }
    VMAbcFile& File;        // +0x140
    Sfr31MnBox ArgMN;       // +0x148
};
// The SDK ReadArgsMnObject: then the object the call is made on, popped (null or undefined throws).
struct Sfr31ReadArgsMnObject : public Sfr31ReadArgsMn
{
    __forceinline Sfr31ReadArgsMnObject(UPInt link, UInt32 argc, UInt32 idx) : Sfr31ReadArgsMn(link, argc, idx), ArgObject(OpStack)
    {
        CheckObject(ArgObject);
    }
    void CheckObject(const Value& v) const
    {
        if (v.IsNullOrUndefined())
        {
            const VM::ErrorID id = v.IsNull() ? static_cast<VM::ErrorID>(0x3f1) : static_cast<VM::ErrorID>(0x3f2);
            VM& vm = VMRef;
            Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(id, vm));
        }
    }
    const Value* GetCallArgs() const { return ArgNum > 8 ? CallArgs.GetDataPtr() : FixedArgs; }
    Value ArgObject;        // +0x178
};

// callsuper (VM::exec_callsuper), shared by the two instantiations: pops the arguments, the multiname and the receiver, reads
// the named property through the frame's super traits and calls it (callsupervoid discards the result, callsuper keeps it).
static __forceinline void Sfr31CallSuperBody(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc, bool discard)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsMnObject args(file, argc, idx);
    if (vm.IsException())
        return;
    Value func;
    const UPInt n = Sfr31Rd(vmAddr, 0x78) - 1;
    const Traits* ot = *reinterpret_cast<const Traits* const*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (n >> 6) * 8) + 0x40 + (n & 0x3f) * 0xa8);
    if (!GetSuperProperty(vm, ot, func, args.ArgObject, args.ArgMN.Get(), SlotInfo::valExecute))
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42e), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
    {
        const Value* argv = args.GetCallArgs();
        Value result(Value::GetUndefined());
        vm.ExecuteInternalUnsafe(func, args.ArgObject, result, argc, argv, discard);
    }
}

// callsupervoid opcode: calls a method of the super class on the popped receiver and discards the result.
// @0x142535af0
void Sfr31ExecCallSuperArgsA(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc) { Sfr31CallSuperBody(vmAddr, file, idx, argc, true); }

// callsuper opcode: the same call, keeping the result.
// @0x142536660
void Sfr31ExecCallSuperArgsB(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc) { Sfr31CallSuperBody(vmAddr, file, idx, argc, false); }
// ---- batch 49
// VTable::SetMethodName's body over raw addresses (inlined into the member below).
struct Sfr31VTNamesView { UPInt Pad[4]; Scaleform::Sfr19NamesData Names; };
static SF_FORCEINLINE void Sfr31StoreSlotName(UPInt vt, UInt32 idx, int kind, const UPInt* name)
{
#define Names (reinterpret_cast<ArrayCC<ASString, StatMV_VM_VTable_Mem>&>(reinterpret_cast<Sfr31VTNamesView*>(vt)->Names))
    const ASString& nm = *reinterpret_cast<const ASString*>(name); const AbsoluteIndex ind(idx);
    if (ind.Get() >= Names.GetSize())
        Names.Resize(ind.Get() + 1);
    switch (kind)
    {
    case 0xb:
        Names[ind.Get()] = nm;
        break;
    case 0xc:
    {
        String s = String("get ") + String(nm.ToCStr(), nm.GetSize());
        ASString& d = Names[ind.Get()];
        d.AssignNode(d.GetManager()->CreateStringNode(s.ToCStr(), s.GetSize()));
        break;
    }
    case 0xd:
    {
        if (idx + 1 >= Names.GetSize())
            Names.Resize(idx + 1 + 1);
        String s = String("set ") + String(nm.ToCStr(), nm.GetSize());
        ASString& d = Names[idx + 1];
        d.AssignNode(d.GetManager()->CreateStringNode(s.ToCStr(), s.GetSize()));
        break;
    }
    default:
        break;
    }
#undef Names
}

// Stores the accessor-prefixed name for a slot: kind 0xb keeps the name, 0xc stores "get " + name at idx, 0xd stores "set " + name at idx + 1.
// MS2-FUNCTIONAL 0x1425283c0: regalloc and CSE: the exe recomputes idx + 1 in the set case (ours keeps it in edi from the first Resize), so the registers and the set-path String slot differ
// @0x1425283c0
__declspec(noinline) void VTable::SetMethodName(AbsoluteIndex ind, SlotInfo::BindingType dt, const ASString& name)
{
    Sfr31StoreSlotName(reinterpret_cast<UPInt>(this), static_cast<UInt32>(ind.Get()), dt, reinterpret_cast<const UPInt*>(&name));
}

// VTable::SetMethod's body over raw addresses (inlined into the member below).
static SF_FORCEINLINE void Sfr31StoreSlotValue(UPInt vt, UPInt idx, const Value* v, int kind, const UPInt* name)
{
    Value* cell = 0;
    switch (kind)
    {
    case 0xb:
    case 0xc:
        cell = reinterpret_cast<Value*>(Sfr31Rd(vt, 8) + static_cast<UPInt>(static_cast<UInt32>(idx)) * 0x20);
        break;
    case 0xd:
        cell = reinterpret_cast<Value*>(Sfr31Rd(vt, 8) + static_cast<UPInt>(static_cast<UInt32>(idx) + 1) * 0x20);
        break;
    }
    reinterpret_cast<VTable*>(vt)->SetMethodName(AbsoluteIndex(static_cast<SPInt>(idx)), static_cast<SlotInfo::BindingType>(kind), *reinterpret_cast<const ASString*>(name));
    if ((*reinterpret_cast<const UInt32*>(v) & 0x1f) == 2)
        cell->Assign(Value(*reinterpret_cast<const SInt32*>(reinterpret_cast<const char*>(v) + 0x10), *reinterpret_cast<const Traits*>(Sfr31Rd(vt, 0)),
                           Value::kMethodInd));
    else
        cell->Assign(*v);
}

// Records a value in the slot table: the name goes in through the accessor-name store, then the value cell at the slot (or slot + 1 for setters) is assigned.
// A method index (kind 2) is stored as a kMethodInd Value bound to the table's traits. The exe calls the name store out of line.
// @0x1425282d0
__declspec(noinline) void VTable::SetMethod(AbsoluteIndex ind, const Value& m, SlotInfo::BindingType dt, const ASString& name)
{
    Sfr31StoreSlotValue(reinterpret_cast<UPInt>(this), static_cast<UPInt>(ind.Get()), &m, dt, reinterpret_cast<const UPInt*>(&name));
}
// ---- batch 50
// ArrayData::Resize, which cl keeps out of line here; the exe has it inline in both branches.
static SF_INLINE void Sfr31ResizeStateChars(ArrayData<Button::CharToRec, AllocatorLH<Button::CharToRec, Stat_Default_Mem>, ArrayDefaultPolicy>& a, UPInt newSize)
{
    UPInt oldSize = a.Size;
    a.ResizeNoConstruct(&a, newSize);
    if (newSize > oldSize)
        AllocatorLH<Button::CharToRec, Stat_Default_Mem>::ConstructArray(a.Data + oldSize, newSize - oldSize);
}
// Puts the display object into the button's render container for the state (rebuilding the container first), records it in the state's
// mask-stack slot and, when that state is the current one, switches to it.
// The container is a Ptr (created when missing, emptied otherwise); the state's records are the StateCharArray.
// @0x142529f70
void Sfr31ButtonSetStateObject(UPInt self, int state, UPInt obj)
{
    const UPInt btn = Sfr31Rd(self, 0x18);
    if (state != 3)
    {
        Ptr<Render::TreeContainer> pcont = *reinterpret_cast<Render::TreeContainer**>(btn + (static_cast<UPInt>(state) + 7) * 0x20);
        if (!pcont)
            pcont = reinterpret_cast<Button*>(btn)->CreateStateRenderContainer(static_cast<Button::ButtonState>(state));
        else
            pcont->Remove(0, pcont->GetSize());
        const UPInt cont = reinterpret_cast<UPInt>(pcont.GetPtr());
        if (Sfr31Rd(obj, 0x38) != 0 && (Sfr31Rd(obj, 0x38) != btn || Sfr31Rd(FUN_1425f26c0(obj), 0x20) != cont))
        {
            const UPInt owner = Sfr31Rd(obj, 0x38);
            const UPInt sub = owner == 0 ? 0 : owner + *reinterpret_cast<const UInt8*>(owner + 0x6d) * 4;
            typedef unsigned char (*Fn)(UPInt, UPInt);
            if ((*reinterpret_cast<Fn*>(Sfr31Rd(sub, 0) + 0xa8))(sub, obj) != 0)
                Sfr31Wr(obj, 0x38, btn);
        }
        if (Sfr31Rd(FUN_1425f26c0(obj), 0x20) == 0)
            pcont->Add(reinterpret_cast<DisplayObjectBase*>(obj)->GetRenderNode());
    }
    ArrayData<Button::CharToRec, AllocatorLH<Button::CharToRec, Stat_Default_Mem>, ArrayDefaultPolicy>& chars =
        *reinterpret_cast<ArrayData<Button::CharToRec, AllocatorLH<Button::CharToRec, Stat_Default_Mem>, ArrayDefaultPolicy>*>(btn + static_cast<UPInt>(state) * 0x20 + 0xe8);
    if (obj != 0)
    {
        Sfr31ResizeStateChars(chars, 1);
        chars.Data[0].Char = reinterpret_cast<DisplayObjectBase*>(obj);
    }
    else
        Sfr31ResizeStateChars(chars, 0);
    if (FUN_1425de200(*reinterpret_cast<const int*>(btn + 0x168)) == state)
        Sfr31ButtonSwitchStateIntl(self, state);
}
}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// ---- batch 51
// Applies a 2x4 matrix to the display object behind a value (movie-clip-like kinds only): the matrix goes to the object with its
// translation in twips, and the position, scale and rotation properties are re-derived from it.
// SDK: AS3ValueObjectInterface::SetDisplayMatrix (AS3_GFxValueImpl.cpp).
// @0x1425270e0
bool AS3ValueObjectInterface::SetDisplayMatrix(void* pdata, const Render::Matrix2F& mat)
{
    using namespace AS3;
    const UPInt valueObj = reinterpret_cast<UPInt>(pdata);
    const UPInt info = Sfr31Rd(valueObj, 0x20);
    if (!((*reinterpret_cast<const SInt32*>(info + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<const UInt8*>(info + 0x68) >> 5)) & 1) != 0)))
        return false;
    DisplayObjectBase* obj = reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(valueObj, 0x58));
    if (!mat.IsValid())
        return false;
    Render::Matrix2F tm = mat;
    tm.Tx() = PixelsToTwips(tm.Tx());
    tm.Ty() = PixelsToTwips(tm.Ty());
    obj->SetMatrix(tm);
    DisplayObjectBase::GeomDataType gd;
    obj->GetGeomData(gd);
    gd.X = int(mat.Tx());
    gd.Y = int(mat.Ty());
    gd.XScale = mat.GetXScaleDouble() * (Double)100.;
    gd.YScale = mat.GetYScaleDouble() * (Double)100.;
    gd.Rotation = (mat.GetRotationDouble() * (Double)180.) / SF_MATH_PI;
    obj->SetGeomData(gd);
    return true;
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {
// ---- batch 52
// call-style opcode on the popped value: a null operand is a TypeError; an object kind is dispatched through its own call slot with the
// remaining arguments; class kinds and everything else raise TypeErrors naming the offender.
// MS2-FUNCTIONAL 0x142536f40: 674 B vs the exe 677; SDK exec_construct form, the only diff is register allocation (the exe holds
// kind - kObject in r8d, ours in ecx)
// @0x142536f40
void Sfr31ExecCallValue(UPInt vmAddr, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsObjectRef args(vm, argc);
    if (vm.IsException())
        return;
    if (args.ArgObject.IsNullOrUndefined())
        return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f1), vm));
    const Value::KindType kind = args.ArgObject.GetKind();
    if (kind == Value::kVTableInd || kind == Value::kVTableIndClosure)
        return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x428), vm, Value(vm.GetValueTraits(args.ArgObject).GetName(), Value::InlineStr)));
    if (!args.ArgObject.IsObject())
        return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x45b), vm, args.ArgObject));
    args.ArgObject.GetObject()->Construct(const_cast<Value&>(args.ArgObject), argc, args.GetCallArgs());
}
// ---- batch 53
// Tears down a class traits' member tables: unregisters it, empties its arrays and hashes, and takes every traits recorded in the
// slot-name hash out of the owner's registration list.
typedef SPtr<GASRefCountBase> Sfr31GcPtr;
typedef HashSetBase<Sfr31GcPtr, FixedSizeHash<Sfr31GcPtr>, FixedSizeHash<Sfr31GcPtr>, AllocatorLH<Sfr31GcPtr, 2>,
                    HashsetCachedEntry<Sfr31GcPtr, FixedSizeHash<Sfr31GcPtr> > > Sfr31GcPtrSet;
typedef AbcMultinameHash<SPtr<Instances::Namespace>, 340>::Key Sfr31NsKey;
typedef HashNode<Sfr31NsKey, SPtr<Instances::Namespace>, FixedSizeHash<Sfr31NsKey> > Sfr31NsNode;
typedef HashSetBase<Sfr31NsNode, Sfr31NsNode::NodeHashF, Sfr31NsNode::NodeAltHashF, AllocatorLH<Sfr31NsKey, 340>,
                    HashsetCachedNodeEntry<Sfr31NsNode, Sfr31NsNode::NodeHashF> > Sfr31NsSet;
typedef HashNode<unsigned long, SPtr<InstanceTraits::Function>, FixedSizeHash<unsigned long> > Sfr31FnNode;
typedef HashSetBase<Sfr31FnNode, Sfr31FnNode::NodeHashF, Sfr31FnNode::NodeAltHashF, AllocatorLH<unsigned long, 340>,
                    HashsetCachedNodeEntry<Sfr31FnNode, Sfr31FnNode::NodeHashF> > Sfr31FnSet;

#pragma inline_depth(0)
// MS2-FUNCTIONAL 0x1425303b0: regalloc and jump threading: the exe keeps zero in r15 (and saves an unused r14, so a 0x30 frame) and does not thread the null-table GlobalObjects iterator (rsi=0 then test rsi); the indexed opcode loop gives the exe's rdi count / rbx offset (71 -> 67)
// @0x1425303b0
void Sfr31ClassTraitsCleanup(UPInt self)
{
    // VMAbcFile::UnRegister; the member Clears / Resizes are out of line in the exe (inline_depth 0 here).
    UPInt* const f = reinterpret_cast<UPInt*>(self);
    if (!::FUN_142522a60(reinterpret_cast<VM*>(f[0x20 / 8]), f))
        return;
    Sfr31UnregisterClassTraits(self);
    typedef ArrayData<UInt64, AllocatorLH_POD<UInt64, 338>, ArrayDefaultPolicy> OpCodeData;
    const UPInt nOps = f[0xc0 / 8];
    for (UPInt k = 0; k < nOps; ++k)
        reinterpret_cast<OpCodeData*>(f[0xb8 / 8] + k * 0x18)->Resize(0);
    reinterpret_cast<ArrayData<ArrayLH_POD<UInt64, 338, ArrayDefaultPolicy>, AllocatorLH<ArrayLH_POD<UInt64, 338, ArrayDefaultPolicy>, 340>, ArrayDefaultPolicy>*>(f + 0xb8 / 8)->Resize(0);
    reinterpret_cast<Sfr31GcPtrSet*>(f + 0x38 / 8)->Sfr31GcPtrSet::~HashSetBase();
    // GlobalObjects iteration; VM::UnregisterGlobalObject inlined.
    SPInt i = 0;
    UPInt* hs;
    if (f[0x70 / 8] == 0)
        hs = NULL;
    else
    {
        const UPInt t = f[0x70 / 8];
        UPInt i0 = 0;
        while (i0 <= *reinterpret_cast<UPInt*>(t + 8) && *reinterpret_cast<SPInt*>(t + 0x10 + i0 * 0x18) == -2)
            ++i0;
        i = static_cast<SPInt>(i0);
        hs = reinterpret_cast<UPInt*>(self + 0x70);
    }
    while (hs != NULL && *hs != 0 && i <= *reinterpret_cast<SPInt*>(*hs + 8))
    {
        UPInt* const vm = reinterpret_cast<UPInt*>(f[0x20 / 8]);
        const UPInt val = *reinterpret_cast<UPInt*>(*hs + 0x20 + i * 0x18);
        const UPInt n = vm[0x1b0 / 8];
        for (UPInt j = 0; j < n; ++j)
        {
            UPInt* const data = reinterpret_cast<UPInt*>(vm[0x1a8 / 8]);
            if (data[j] != val)
                continue;
            if (n == 1)
            {
                if ((vm[0x1b8 / 8] & ~static_cast<UPInt>(1)) > 0)
                {
                    if (data != NULL)
                    {
                        Memory::pGlobalHeap->Free(data);
                        vm[0x1a8 / 8] = 0;
                    }
                    vm[0x1b8 / 8] = 0;
                }
                vm[0x1b0 / 8] = 0;
            }
            else
            {
                memmove(data + j, data + j + 1, (n - j) * 8 - 8);
                --vm[0x1b0 / 8];
            }
            break;
        }
        const UPInt mask = *reinterpret_cast<UPInt*>(*hs + 8);
        if (i <= static_cast<SPInt>(mask))
        {
            ++i;
            while (static_cast<UPInt>(i) <= mask && *reinterpret_cast<SPInt*>(*hs + 0x10 + i * 0x18) == -2)
                ++i;
        }
    }
    reinterpret_cast<Sfr31GcPtrSet*>(f + 0x70 / 8)->Clear();
    reinterpret_cast<ArrayDataBase<SPtr<VMAbcFile>, AllocatorLH<SPtr<VMAbcFile>, 340>, ArrayDefaultPolicy>*>(f + 0x78 / 8)->ResizeNoConstruct(f + 0x78 / 8, 0);
    reinterpret_cast<Sfr31NsSet*>(f + 0x30 / 8)->Sfr31NsSet::~HashSetBase();
    reinterpret_cast<ArrayData<SPtr<NamespaceSet>, AllocatorLH<SPtr<NamespaceSet>, 2>, ArrayDefaultPolicy>*>(f + 0x40 / 8)->Resize(0);
    reinterpret_cast<ArrayDataBase<SPtr<ASStringNode>, AllocatorLH<SPtr<ASStringNode>, 2>, ArrayDefaultPolicy>*>(f + 0x58 / 8)->ResizeNoConstruct(f + 0x58 / 8, 0);
    reinterpret_cast<Sfr31FnSet*>(f + 0x90 / 8)->Clear();
    reinterpret_cast<Sfr31FnSet*>(f + 0x98 / 8)->Sfr31FnSet::~HashSetBase();
    reinterpret_cast<ArrayData<Abc::MethodBodyInfo::Exception, AllocatorLH<Abc::MethodBodyInfo::Exception, 340>, ArrayDefaultPolicy>*>(f + 0xd0 / 8)->Resize(0);
}
#pragma inline_depth()
// ---- batch 54
static inline void Sfr31ContAdd(UPInt c, UPInt n) { reinterpret_cast<Render::TreeContainer*>(c)->Add(reinterpret_cast<Render::TreeNode*>(n)); }   // TreeContainer::Add
static inline UPInt Sfr31SubObj(UPInt o) { return o + *reinterpret_cast<const UInt8*>(o + 0x6d) * 4; }
static inline UPInt Sfr31VCall0(UPInt self, UPInt off)
{
    typedef UPInt (*Fn)(UPInt);
    return (*reinterpret_cast<Fn* const*>(self))[off / 8](self);
}

// Moves the button's state objects: every other state's object is detached from the button, then the object of the requested state is
// attached to its render container (once) and the container is appended to the button's own.
// IsUnloaded/IsUnloading and TreeContainer::Add are the SDK inlines (DisplayObjectBase view; the exe keeps the two Flags tests separate)
// @0x14252e9d0
void Sfr31ButtonSwitchStateIntl(UPInt self, int state)
{
    const UPInt btn = Sfr31Rd(self, 0x18);
    //
    if (reinterpret_cast<const GFx::DisplayObjectBase*>(btn)->IsUnloaded() || reinterpret_cast<const GFx::DisplayObjectBase*>(btn)->IsUnloading())
        return;
    UPInt c = Sfr31VCall0(btn, 0x1f8);
    if (FUN_14250dbc0(c) != 0)
    {
        c = Sfr31VCall0(btn, 0x1f8);
        FUN_14261cf50(c, 0, 1);
    }
    typedef UPInt (*Fn2)(UPInt, UPInt);
    for (unsigned s = 0; s < 3; ++s)
    {
        const SPInt si = static_cast<int>(s);   // (ButtonState)i
        if (Sfr31Rd(btn, si * 0x20 + 0xf0) > 0)
        {
            const UPInt first = Sfr31Rd(Sfr31Rd(btn, si * 0x20 + 0xe8), 0);
            const UPInt io = (*reinterpret_cast<const UInt8*>(first + 0x6b) & 1) != 0 ? first : 0;
            const UPInt br = (static_cast<UInt8>(*reinterpret_cast<const UInt16*>(io + 0x6a) >> 9) & 1) != 0 ? io : 0;
            const UPInt owner = Sfr31Rd(io, 0x38);
            if (s != static_cast<unsigned>(state) && owner != 0)
            {
                const UPInt sub = Sfr31SubObj(owner);
                (*reinterpret_cast<Fn2* const*>(sub))[0xa8 / 8](sub, io);
                Sfr31Wr(io, 0x38, 0);
                if (br != 0)
                {
                    const UPInt l = Sfr31VCall0(Sfr31SubObj(br), 8);
                    FUN_142517ed0(reinterpret_cast<void*>(l != 0 ? l - 0x30 : 0));
                }
            }
        }
    }
    if (Sfr31Rd(btn, static_cast<UPInt>(state) * 0x20 + 0xf0) <= 0)
        return;
    const UPInt first = Sfr31Rd(Sfr31Rd(btn, static_cast<UPInt>(state) * 0x20 + 0xe8), 0);
    const UPInt io = (*reinterpret_cast<const UInt8*>(first + 0x6b) & 1) != 0 ? first : 0;
    const UPInt br = (static_cast<UInt8>(*reinterpret_cast<const UInt16*>(io + 0x6a) >> 9) & 1) != 0 ? io : 0;
    const UPInt cont = Sfr31Rd(btn, (static_cast<UPInt>(state) + 7) * 0x20);
    if (cont != 0)
        ++*reinterpret_cast<UPInt*>(cont + 8);
    const UPInt parent = Sfr31Rd(io, 0x38);
    if (parent != 0 && (parent != btn || Sfr31Rd(FUN_1425f26c0(io), 0x20) != cont))
    {
        const UPInt owner = Sfr31Rd(io, 0x38);
        const UPInt sub = owner == 0 ? 0 : Sfr31SubObj(owner);
        (*reinterpret_cast<Fn2* const*>(sub))[0xa8 / 8](sub, io);
    }
    if (Sfr31Rd(FUN_1425f26c0(io), 0x20) == 0)
        Sfr31ContAdd(cont, FUN_1425f26c0(io));
    if (Sfr31Rd(io, 0x38) == 0)
    {
        Sfr31Wr(io, 0x38, btn);
        if (br != 0)
        {
            const UPInt l = Sfr31VCall0(Sfr31SubObj(br), 8);
            FUN_142517ed0(reinterpret_cast<void*>(l != 0 ? l - 0x30 : 0));
            typedef void (*Fn3)(UPInt, UPInt);
            for (UPInt i = 0; i < Sfr31Rd(br, 0xe0); ++i)
            {
                const UPInt child = Sfr31Rd(Sfr31Rd(br, 0xd8) + i * 0x10, 0);
                if ((static_cast<UInt8>(*reinterpret_cast<const UInt16*>(child + 0x6a) >> 10) & 1) != 0)
                {
                    // Sprite::GotoFrame(0), then SetPlayState(State_Playing)
                    (*reinterpret_cast<Fn3* const*>(child))[0x340 / 8](child, 0);
                    (*reinterpret_cast<Fn3* const*>(child))[0x360 / 8](child, 0);
                }
            }
        }
    }
    const UPInt own = Sfr31VCall0(btn, 0x1f8);
    Sfr31ContAdd(own, cont);
    if (cont != 0 && --*reinterpret_cast<UPInt*>(cont + 8) == 0)
        reinterpret_cast<Sfr31EntryAccess*>(cont)->destroyHelper();
}
// VM::GetInternedNamespace(NS_Public, pkg): a reference, no AddRef (the URI string dies here).
static __forceinline Instances::Namespace& Sfr31PublicNsRef(VM* vm, const char* pkg)
{
    if (!pkg) pkg = "";
    const ASString uri = vm->GetStringManager().CreateString(pkg);
    if (uri.IsEmpty())
        return *vm->PublicNamespace.GetPtr();
    return *FUN_142415c20(&static_cast<InstanceTraits::fl::Namespace&>(vm->GetClassTraitsNamespace().GetInstanceTraits()), Abc::NS_Public, uri, Value::GetUndefined());
}
// ---- batch 55
// Raises an error: instantiates the error class named by the ClassInfo (resolved through the class traits cache), constructs it
// with the message and error id, stores it as the pending exception and sets the halt flag.
// VM::ThrowErrorInternal(e, ti): Resolve2ClassTraits inlined (GetInternedNamespace, CreateConstString, GetClassTraits).
// @0x14252ecb0
void Sfr31VMRaiseError(UPInt vmAddr, const UInt32* err, UPInt classInfo)
{
    VM* const vm = reinterpret_cast<VM*>(vmAddr);
    const UPInt ti = classInfo;   // const TypeInfo& ti
    const Instances::Namespace& ns = Sfr31PublicNsRef(vm, reinterpret_cast<const char*>(Sfr31Rd(ti, 0x10)));
    //
    const ClassTraits::Traits* ctr = Sfr31GetClassTraitsInl(vm, vm->GetStringManager().CreateConstString(reinterpret_cast<const char*>(Sfr31Rd(ti, 8))), ns);
    Value obj;
    InstanceTraits::Traits& itr = ctr->GetInstanceTraits();
    itr.MakeObject(obj, itr);
    const Value argv[2] = {Value(*reinterpret_cast<const ASString*>(err + 2), Value::InlineStr), Value(static_cast<SInt32>(err[0]))};
    obj.GetObject()->AS3Constructor(2, argv);
    vm->Throw(obj);
}
// ---- batch 56
// Checks that a value converts to a string: null-ish operands convert directly; otherwise the object's public toString is invoked
// and its result converted. Writes the success flag through ret.
// MS2-FUNCTIONAL 0x14252f9b0: SDK AS3::ToString body with the inlined Multiname(ns, Value) ctor; the r / name-temp /
// Multiname stack slots are rotated vs the exe
// @0x14252f9b0
char* Sfr31ValueToStringCheck(char* ret, VM* vm, Value* v, void* strOut)
{
    // SDK AS3::ToString(VM&, const Value&, ASString&) (AS3_Object.cpp).
    const Value& _this = *v;
    ASString& result = *static_cast<ASString*>(strOut);
    if (_this.IsNullOrUndefined())
    {
        if (!_this.Convert2String(result))
        {
            *ret = 0;
            return ret;
        }
    }
    else
    {
        Value r;
        Multiname name(vm->GetPublicNamespace(), Value(vm->GetStringManager().CreateConstString("toString"), Value::InlineStr), Multiname::InlineAssignTag());

        if (!ExecutePropertyUnsafe(*vm, name, _this, r, 0, NULL))
        {
            *ret = 0;
            return ret;
        }

        if (!r.IsString() && !r.Convert2String(result))
        {
            *ret = 0;
            return ret;
        }
    }

    *ret = 1;
    return ret;
}

// v = sm.CreateString(buf): the exe's LTCG knows Value::Assign does not write the ASString temp, so the temp's
// release uses the node it already holds in a register; a separate node copy gives cl the same.
static __forceinline void Sfr19AssignNewString(Value& v, StringManager& sm, const StringBuffer& buf)
{
    ASStringNode* const node = sm.GetStringManager()->CreateStringNode(buf.ToCStr(), buf.GetSize());
    ASStringNode* tmp = node;
    node->AddRef();
    v.Assign(*reinterpret_cast<const ASString*>(&tmp));
    node->Release();
}

// The exe inlines IsXMLObject/IsXMLListObject (sfr_as3_18) and XMLList::AS3toXMLString() here.
static __forceinline bool Sfr19IsXMLKindObject(const Value& v, int tt)
{
    if (!v.IsObject())
        return false;
    Object* obj = v.GetObject();
    return obj && static_cast<int>(obj->GetTraits().GetTraitsType()) == tt && obj->GetTraits().IsInstanceTraits();
}

// Converts a value in place to an XML-escaped string for element content. Null/undefined operands raise TypeError
// 1009/1010.
// MS2-FUNCTIONAL 0x14252fef0: SDK XMLSupportImpl::ToXMLString shape; v/vm/result register roles are permuted vs the exe,
// and the exe tests ToPrimitiveValue's returned CheckResult (the SDK form) where ours tests ok (that form re-merges the tails)
// @0x14252fef0
CheckResult XMLSupportImpl::ToXMLString(VM& vm, Value& v) const
{
    if (v.IsNullOrUndefined())
    {
        vm.ThrowTypeError(VM::Error(
            v.IsNull() ? VM::eConvertNullToObjectError : VM::eConvertUndefinedToObjectError,
            vm
            ));
        return false;
    }

    StringManager& sm = vm.GetStringManager();
    const Value::KindType k = v.GetKind();

    switch (k)
    {
    case Value::kBoolean:
    case Value::kInt:
    case Value::kUInt:
    case Value::kNumber:
        return v.ToStringValue(sm);
    case Value::kString:
        {
            StringBuffer buf;
            Instances::fl::XML::EscapeElementValue(buf, v.AsString());
            Sfr19AssignNewString(v, sm, buf);
        }
    default:
        if (Sfr19IsXMLKindObject(v, Traits_XML))
        {
            Instances::fl::XML* xml = static_cast<Instances::fl::XML*>(v.GetObject());
            StringBuffer buf;
            xml->ToXMLString(buf, 0, NULL, NULL);
            Sfr19AssignNewString(v, sm, buf);
        }
        else if (Sfr19IsXMLKindObject(v, Traits_XMLList))
        {
            Instances::fl::XMLList* xml_list = static_cast<Instances::fl::XMLList*>(v.GetObject());
            ASString result(xml_list->GetTraits().GetVM().GetStringManager().CreateEmptyString());
            xml_list->AS3toXMLString(result);
            v = result;
        }
        else
        {
            UInt8 ok;
            Sfr31ValueToPrimitive(&v, &ok);
            if (!ok || !v.IsPrimitive())
                return false;

            v.ToStringValue(sm).DoNotCheck();

            StringBuffer buf;
            Instances::fl::XML::EscapeElementValue(buf, v.AsString());
            Sfr19AssignNewString(v, sm, buf);
        }
        break;
    }

    return true;
}

// ---- batch 57
// Number to decimal string (ECMAScript style): integers print plainly, NaN/Infinity by name, other values with %.16g
// (integer digit count up to 21 for 1e16..1e21); exponents lose leading zeros and small negative exponents expand to 0.000ddd form. Returns the length.
// The SDK 4.3 SF_ECMA_dtostr (AS3_Value.cpp), comments dropped.
// @0x142525f20
SPInt Sfr31NumberToChars(char* buffer, int bufflen, double val)
{
    int intVal = static_cast<int>(val);
    if (val == intVal)
    {
        _itoa_s(intVal, buffer, bufflen, 10);   // SFitoa
        return SFstrlen(buffer);
    }
    SF_ASSERT(bufflen >= 40);
    if (NumberUtil::IsNaN(val))
    {
        memcpy(buffer, "NaN", 4);
        return 3;
    }
    if (NumberUtil::IsPOSITIVE_INFINITY(val))
    {
        memcpy(buffer, "Infinity", sizeof("Infinity"));
        return sizeof("Infinity")-1;
    }
    if (NumberUtil::IsNEGATIVE_INFINITY(val))
    {
        memcpy(buffer, "-Infinity", sizeof("-Infinity"));
        return sizeof("-Infinity")-1;
    }
    char  temp[40] = { 0 };
    char  *d, *s;
    char   format[] = "%.16g";
    Double absVal = fabs(val);
    if ((absVal >= 1.0e16) && (absVal < 1.0e21))
    {
        format[3] = '7';
        if (absVal >= 1.0e17)
        {
            format[3] = '8';
            if (absVal >= 1.0e18)
            {
                format[3] = '9';
                if (absVal >= 1.0e19)
                {
                    format[2] = '2';
                    format[3] = '0';
                    if (absVal >= 1.0e20)
                    {
                        format[2] = '2';
                        format[3] = '1';
                    }
                }
            }
        }
    }
    const int nc1 = (int)SFsprintf(temp, sizeof(temp), format, static_cast<double>(val));
    {
        bool have_e = false;
        for (int i = 0; i < nc1; ++i)
        {
            if (temp[i] == 'e')
            {
                have_e = true;
                break;
            }
        }
        if (!have_e)
        {
            int dot_pos = 0;
            bool have_dot = false;
            for (; temp[dot_pos] != 0; ++dot_pos)
            {
                char c = temp[dot_pos];
                if (c == '.' || c == ',')
                {
                    have_dot = true;
                    break;
                }
            }
            if (have_dot && temp[nc1 - 1] != '0')
            {
                int i = nc1 - 2;
                for (; i > dot_pos; --i)
                {
                    if (temp[i] != '0')
                        break;
                }
                if (i < nc1 - 2 && i != dot_pos)
                    temp[i + 1] = 0;
            }
        }
    }
    bool negativeExponent = false;
    int  exponentValue = 0;
    for (d = buffer, s = temp; *s != 0; s++)
    {
        if (*s == ',')
        {
            *d++ = '.';
            continue;
        }
        if (*s == 'e')
        {
            *d++ = *s++;
            if (*s == '-' || *s == '+')
            {
                if (*s == '-')
                    negativeExponent = true;
                *d++ = *s++;
            }
            while (*s == '0')
                s++;
            while((*s >='0') && (*s <= '9'))
            {
                exponentValue = exponentValue * 10 + (*s - '0');
                *d++ = *s++;
            }
            break;
        }
        *d++ = *s;
    }
    if (negativeExponent && (exponentValue > 0) && (exponentValue <= 6))
    {
        s = temp; d = buffer;
        if (*s == '-')
        {
            s++;
            d++;
        }
        if ((*s >= '1') && (*s <= '9') && (d[1] == '.'))
        {
            *d++ = '0';
            *d++ = '.';
            for (int zeroCount = 1; zeroCount < exponentValue; zeroCount++)
                *d++ = '0';
            while(*s != 'e')
            {
                SF_ASSERT(*s != 0);
                if ((*s >= '0') && (*s <= '9'))
                {
                    *d++ = *s;
                }
                s++;
            }
        }
    }
    *d = 0;
    return d - buffer;
}

// The tracer's ReadObject (inlined in the exe): the popped object, released at each return.
struct TrReadObject19 : public TR::StackReader
{
    TrReadObject19(VM& vm, State& st) : TR::StackReader(vm, st), ArgObject(st.PopOpValue())
    {
        ++Num;
    }
    Value ArgObject;
};

// Slots::GetSlotInfo (sfr_as3_04 0x142416fb0), one level inline here as in the exe.
static SF_INLINE const SlotInfo& Sfr19GetSlotInfo(const Slots& s, AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Value;
}

// Value(const ASString&) as the exe inlines it here: a null string becomes a null object (the payload copied as one
// 16-byte union).
struct TrStrValue19
{
    struct Pair { void* a; void* b; };
    TrStrValue19(const ASString& str)
    {
        w0 = static_cast<UInt32>(Value::kString);
        w1 = 0;
        w2 = reinterpret_cast<UPInt>(str.GetNode());
        if (str.GetNode() == str.GetManager()->GetNullStringNode())
        {
            Pair p;
            p.a = NULL;
            w0 = static_cast<UInt32>(Value::kObject);
            *reinterpret_cast<Pair*>(&w2) = p;
        }
        else
            str.GetNode()->AddRef();
    }
    ~TrStrValue19() { Get().~Value(); }
    Value& Get() { return *reinterpret_cast<Value*>(&w0); }
    UInt32 w0;
    UPInt w1, w2, w3;
};

// A traced Value(traits, null type): second word zeroed, then the payload, then the tag.
struct TrTypedScratch19
{
    TrTypedScratch19(UInt32 tag, UPInt p) { w1 = 0; w2 = p; w0 = tag; }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1, w2, w3;
};

// ---- batch 58
// Tracer getslot: pops the object, resolves its traits and pushes the declared type of the slot (nullability from the declared
// instance traits); an unresolvable slot type is a verify error, an unknown object type pushes undefined.
// MS2-FUNCTIONAL 0x142539f30: SDK exec_getslot shape on a raw-offset model; the popped object's flags/kind are snapshot locals with an explicit release tail (the exe's SCU mod/ref keeps them in esi/[rbp+0x6f]); left: st/slot/kind register permutation, CanBeNull mask (exe btr), xorps-zeroed string temp (913 vs 914 bytes)
// Sfr19GetSlotInfo with FirstOwnSlotNum read once by the caller (the exe keeps it in a register across the calls).
static SF_INLINE const SlotInfo& Sfr19GetSlotInfoF(const Slots& s, AbsoluteIndex ind, UPInt first)
{
    if (ind < first)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - static_cast<UInt32>(first)].Value;
}

// TrReadObject19 without the Value dtor: the exe (AS3 one SCU) keeps the popped flags in a register across the
// calls and releases from that snapshot, which a plain Value member cannot give across out-of-TU calls.
struct TrReadObjectSnap19 : public TR::StackReader
{
    TrReadObjectSnap19(VM& vm, State& st) : TR::StackReader(vm, st)
    {
        new (Buf) Value(st.PopOpValue());
        ++Num;
    }
    Value& Arg() { return *reinterpret_cast<Value*>(Buf); }
    union
    {
        UPInt Align;
        UByte Buf[sizeof(Value)];
    };
};
static __forceinline void TrReleaseSnap19(Value& v, UInt32 k, UInt32 flags)
{
    if (k > 9)
    {
        if (static_cast<UInt8>(flags >> 9) & 1)
            (*reinterpret_cast<WeakProxy**>(reinterpret_cast<UByte*>(&v) + 0x08))->Release();
        else
            FUN_142521f00(&v);
    }
}

// @0x142539f30
void Sfr31TraceGetSlot(State* st, UInt32 slot)
{
    FUN_14251fcd0(TrRd(reinterpret_cast<UPInt>(st), 0), slot);
    TrReadObjectSnap19 args(*reinterpret_cast<VM*>(TrVM(TrRd(reinterpret_cast<UPInt>(st), 0))), *st);
    const UPInt tracer = TrRd(reinterpret_cast<UPInt>(st), 0);
    const UInt32 flags = *reinterpret_cast<const UInt32*>(&args.Arg());
    const UInt32 k = flags & 0x1f;
    UPInt tr;
    switch (k)
    {
    case 0:
        tr = TrRd(TrVM(tracer), 0x278);
        break;
    case 8:
        tr = reinterpret_cast<UPInt>(&args.Arg().GetInstanceTraits());
        break;
    case 9:
        tr = reinterpret_cast<UPInt>(&args.Arg().GetClassTraits());
        break;
    default:
        tr = reinterpret_cast<UPInt>(&reinterpret_cast<VM*>(TrVM(tracer))->GetValueTraits(args.Arg()));
        break;
    }
    if (tr != 0)
    {
        if (tr == TrRd(TrVM(tracer), 0x1f0))
            tr = TrRd(TrVM(tracer), 0x1f8);
    }
    if (tr != 0)
    {
        const UPInt first = TrRd(tr, 0x20);
        if (slot <= TrRd(tr, 0x38) + first)
        {
            const SPInt aind = static_cast<SPInt>(slot) - 1 + static_cast<UInt32>(TrRd(tr, 0x50));
            const SlotInfo& si = Sfr19GetSlotInfoF(*reinterpret_cast<Traits*>(tr), AbsoluteIndex(aind), first);
            const SlotInfo& si2 = Sfr19GetSlotInfoF(*reinterpret_cast<Traits*>(tr), AbsoluteIndex(aind), first);
            ClassTraits::Traits* ctr = FUN_1425085b0(&si2, reinterpret_cast<VM*>(TrRd(tr, 0x78)));
            if (ctr == NULL)
            {
#define SFR19_VM (*reinterpret_cast<VM*>(TrVM(TrRd(reinterpret_cast<UPInt>(st), 0))))
                SFR19_VM.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3f6), SFR19_VM, TrStrValue19(si.GetDataTypeName(SFR19_VM)).Get()));
#undef SFR19_VM
                TrReleaseSnap19(args.Arg(), k, flags);
                return;
            }
            InstanceTraits::Traits& itr = *reinterpret_cast<InstanceTraits::Traits*>(TrRd(reinterpret_cast<UPInt>(ctr), 0xc0));
            const UPInt aux = TrRd(reinterpret_cast<UPInt>(&si), 0x20);
            const bool isClass = (*reinterpret_cast<const UInt32*>(&si) & 0x3e0) == 0x20 ||
                                 (aux != 0 && (*reinterpret_cast<const UInt8*>(aux) & 0xf) == 4);
            if (isClass)
                TrPushOp(st, TrTypedScratch19(((static_cast<UInt32>(st->CanBeNull(itr)) << 5) & ~0x100u) | 9, reinterpret_cast<UPInt>(ctr)).Get());
            else
                TrPushOp(st, TrTypedScratch19(((static_cast<UInt32>(st->CanBeNull(itr)) << 5) & ~0x100u) | 8, reinterpret_cast<UPInt>(&itr)).Get());
        }
        else
        {
            TrTypedScratch19 t(0x48, TrRd(TrRd(TrVM(tracer), 0x1f8), 0xc0));
            TrPushOp(st, t.Get());
        }
        TrReleaseSnap19(args.Arg(), k, flags);
        return;
    }
    TrPushOp(st, Value());
    TrReleaseSnap19(args.Arg(), k, flags);
}

// ---- batch 59
// Tracer::SubstituteGetlocal: the peephole for "increment/decrement; convert; setlocal N" on register N. When the
// register's known type matches, the sequence becomes one specialized opcode and the register is converted. Returns
// whether the sequence was consumed.
// The Tracer fields it reads: the byte code text and the original opcode positions.
struct Sfr31TrSubstView
{
    UInt8 pad0[0x50];
    const UInt8* pCode;             // +0x50
    UInt8 pad1[0x70 - 0x58];
    Scaleform::Sfr19PosData OrigOpcodePos;   // +0x70
};
// Tracer::GetValueTraits(v) (super_tr false), as the exe inlines it.
static __forceinline const Traits* Sfr31TrValueTraitsOf(UPInt tracer, const Value& v)
{
    const Traits* result;
    switch (v.GetKind())
    {
    case Value::kUndefined:
        result = reinterpret_cast<const Traits*>(Sfr31Rd(TrVM(tracer), 0x278));
        break;
    case Value::kInstanceTraits:
        result = &v.GetInstanceTraits();
        break;
    case Value::kClassTraits:
        result = &v.GetClassTraits();
        break;
    default:
        result = &reinterpret_cast<VM*>(TrVM(tracer))->GetValueTraits(v);
    }
    if (result && result == reinterpret_cast<const Traits*>(Sfr31Rd(TrVM(tracer), 0x1f0)))
        result = reinterpret_cast<const Traits*>(Sfr31Rd(TrVM(tracer), 0x1f8));
    return result;
}
// MS2-FUNCTIONAL 0x14252cd80: SDK SubstituteGetlocal; only regalloc differs (st in r14, the exe r15)
// @0x14252cd80
bool Sfr31TracerOptRegIncDec(UPInt tracer, UPInt* bcp, UPInt ccp, UPInt state, UInt32 regInd)
{
    Sfr31TrSubstView& tr = *reinterpret_cast<Sfr31TrSubstView*>(tracer);
    State& st = *reinterpret_cast<State*>(state);
    const int src_reg_num = static_cast<int>(regInd);
    const Value& reg = reinterpret_cast<const Value*>(Sfr31Rd(state, 0x18))[static_cast<UInt32>(src_reg_num)];
    const int next_opcode = tr.pCode[ccp++];
    bool check_setlocal = false;
    int drop_num = 0;

    switch (next_opcode)
    {
    case 0x91:  // op_increment
    case 0x93:  // op_decrement
    case 0xc0:  // op_increment_i
    case 0xc1:  // op_decrement_i
        check_setlocal = true;
        break;
    default:
        break;
    }

    if (check_setlocal)
    {
        tr.OrigOpcodePos.PushBack(ccp);
        ++drop_num;
        int current_opcode = tr.pCode[ccp++];
        BuiltinTraitsType result_dt = Traits_Unknown;

        switch (current_opcode)
        {
        case 0x73:  // op_convert_i
            result_dt = Traits_SInt;
            break;
        case 0x74:  // op_convert_u
            result_dt = Traits_UInt;
            break;
        case 0x75:  // op_convert_d
            result_dt = Traits_Number;
            break;
        default:
            break;
        }

        if (result_dt == Traits_Unknown)
        {
            switch (next_opcode)
            {
            case 0xc0:
            case 0xc1:
                result_dt = Traits_SInt;
                break;
            default:
                result_dt = Traits_Number;
                break;
            }
        }
        else
        {
            tr.OrigOpcodePos.PushBack(ccp);
            ++drop_num;
            current_opcode = tr.pCode[ccp++];
        }

        int dest_reg_num = 0;
        bool is_setlocal = true;

        switch (current_opcode)
        {
        case 0x63:  // op_setlocal
            dest_reg_num = Abc::ReadU30<UInt8>(tr.pCode, ccp);
            break;
        case 0xd4:
            dest_reg_num = 0;
            break;
        case 0xd5:
            dest_reg_num = 1;
            break;
        case 0xd6:
            dest_reg_num = 2;
            break;
        case 0xd7:
            dest_reg_num = 3;
            break;
        default:
            is_setlocal = false;
            break;
        }

        if (is_setlocal && dest_reg_num == src_reg_num)
        {
            BuiltinTraitsType reg_dt = Traits_Number;
            const Traits* reg_tr = Sfr31TrValueTraitsOf(tracer, reg);

            if (reg_tr && reg_tr->IsInstanceTraits())
                reg_dt = reg_tr->GetTraitsType();

            switch (next_opcode)
            {
            case 0x91:
            case 0xc0:
                if (reg_dt == result_dt)
                {
                    switch (reg_dt)
                    {
                    case Traits_SInt:
                        FUN_14251fb90(&tr, 0x0a, src_reg_num);  // op_inclocal_ti
                        st.RegInt(src_reg_num);
                        break;
                    case Traits_UInt:
                        FUN_14251fb90(&tr, 0x37, src_reg_num);  // op_inclocal_tu
                        st.RegUInt(src_reg_num);
                        break;
                    case Traits_Number:
                        FUN_14251fb90(&tr, 0x92, src_reg_num);  // op_inclocal
                        st.RegNumber(src_reg_num);
                        break;
                    default:
                        break;
                    }
                }
                else if (result_dt == Traits_SInt)
                {
                    FUN_14251fb90(&tr, 0xc2, src_reg_num);  // op_inclocal_i
                    st.RegInt(src_reg_num);
                }
                else
                {
                    FUN_14251fb90(&tr, 0x92, src_reg_num);
                    st.RegNumber(src_reg_num);
                }
                Sfr31TracerSkipOrigOpCode(tracer, bcp, ccp);
                return true;
            case 0x93:
            case 0xc1:
                if (reg_dt == result_dt)
                {
                    switch (reg_dt)
                    {
                    case Traits_SInt:
                        FUN_14251fb90(&tr, 0x0b, src_reg_num);  // op_declocal_ti
                        st.RegInt(src_reg_num);
                        break;
                    case Traits_UInt:
                        FUN_14251fb90(&tr, 0x38, src_reg_num);  // op_declocal_tu
                        st.RegUInt(src_reg_num);
                        break;
                    case Traits_Number:
                        FUN_14251fb90(&tr, 0x94, src_reg_num);  // op_declocal
                        st.RegNumber(src_reg_num);
                        break;
                    default:
                        break;
                    }
                }
                else if (result_dt == Traits_SInt)
                {
                    FUN_14251fb90(&tr, 0xc3, src_reg_num);  // op_declocal_i
                    st.RegInt(src_reg_num);
                }
                else
                {
                    FUN_14251fb90(&tr, 0x94, src_reg_num);
                    st.RegNumber(src_reg_num);
                }
                Sfr31TracerSkipOrigOpCode(tracer, bcp, ccp);
                return true;
            default:
                break;
            }
        }
        else
        {
            tr.OrigOpcodePos.Resize(tr.OrigOpcodePos.Size - drop_num);
        }
    }

    return false;
}

// ---- batch 60
// exec_in: pops the object; the name below it is replaced by whether the object has that property. A null object is a TypeError.
// PropRef::operator bool (0x1424e0e20, sfr_as3_16), as the exe inlines it into exec_in.
static inline bool Sfr19PropFound(const PropRef& prop)
{
    const UPInt p = reinterpret_cast<UPInt>(prop.pValue);
    return !(prop.This.IsUndefined() || (Sfr31PRTag(p, 1) && (p & ~static_cast<UPInt>(1)) == 0) ||
             (Sfr31PRTag(p, 2) && (p & ~static_cast<UPInt>(2)) == 0));
}

// The operands of exec_in: the object popped off the top into _2, the name below it (_1) left in place.
// _2 sits in a union so it has no dtor: ExecIn caches the object's flags and weak proxy up front and
// releases it by hand at each exit, as the LTCG build does with them held in registers.
struct Sfr19ExecInArgs
{
    __forceinline Sfr19ExecInArgs(ValueStack& vs) : _2(vs), _1(*vs.GetTopPtr()) { }
    __forceinline ~Sfr19ExecInArgs() { }
    union { Value _2; };
    Value& _1;
};
// MS2-FUNCTIONAL 0x14253b020: same size and code; only the prolog differs: the exe (LTCG) loads the popped object (movups) and its Bonus before storing the Flags copy, ours after
// Value::IsNullOrUndefined, the 4.2 form (IsNull tests objects only, into a result).
static __forceinline bool Sfr19IsNullOrUndef(const Value& v)
{
    if (v.GetKind() == Value::kUndefined)
        return true;
    bool result;
    if (v.IsObject())
        result = v.GetObject() == NULL;
    else
        result = false;
    return result;
}
// The release of the popped object at each exit (the SH2 dtor), from its flags and weak proxy cached up front.
struct Sfr19ExecInRelease
{
    __forceinline Sfr19ExecInRelease(Value& v, UInt32 f, WeakProxy* wp) : V(v), Of(f), Wp(wp) { }
    __forceinline ~Sfr19ExecInRelease()
    {
        if ((Of & 0x1f) > 9)
        {
            if (static_cast<UInt8>(Of >> 9) & 1)
                Wp->Release();
            else
                ValueAssignCopies::ReleaseStrong19(V);
        }
    }
    Value& V;
    const UInt32 Of;
    WeakProxy* const Wp;
};
// @0x14253b020
void Sfr31ExecIn(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr19ExecInArgs stack(ValueStack::Of(vm));
    Value& obj = stack._2;
    Value& name = stack._1;
    const UInt32 of = *reinterpret_cast<const UInt32*>(&obj);
    WeakProxy* const owp = *reinterpret_cast<WeakProxy* const*>(reinterpret_cast<const char*>(&obj) + 8);
    Sfr19ExecInRelease release(obj, of, owp);
    if (Sfr19IsNullOrUndef(obj))
        return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f1), vm));
    const bool isObj = Value::IsObject(static_cast<Value::KindType>(of & 0x1f));
    Multiname prop_name(vm.GetPublicNamespace(), name, Multiname::InlineCtorTag());
    if (isObj)
    {
        Object* o = obj.GetObject();
        const Traits& tr = o->GetTraits();
        if (tr.IsArrayLike() || (tr.GetTraitsType() == Traits_XML && tr.IsInstanceTraits()))
        {
            Value value = Value::GetUndefined();
            name.SetBool(o->GetProperty(prop_name, value));
            return;
        }
    }
    PropRef prop;
    FUN_142501b00(&prop, &vm, &obj, &prop_name, 0);
    name.SetBool(Sfr19PropFound(prop));
}

// ---- batch 61
// exec_getclass-style op: the operand must be a class object (or null when the entry has no base); the class entry resolves to its
// class object, except classes in the "scaleform.gfx" package, which must exist as a property of the global object.
// Value::AssignUnsafe(const Value&) (0x1424edce0), inlined: the same definition as sfr_as3_17's (a Value friend).
struct Sfr17ValueInline
{
    static __forceinline void Assign(Value& self, const Value& other)
    {
        self.Release();
        SIMD::PrefetchObj(&other);
        memcpy(&self, &other, sizeof(Value));
        self.AddRef();
    }
};

// Multiname(Namespace&, const Value&) with AssignUnsafe inlined too, as exec_newclass has it (sfr_as3_17d has the same).
__forceinline Multiname::Multiname(Instances::Namespace& ns, const Value& name, InlineAssignTag)
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
    Sfr17ValueInline::Assign(Name, name);
    // PostProcessName(false) (0x14251cef0, sfr_as3_18) inlined, in the SDK switch form (AS3_Object.cpp)
    if (Name.IsString())
    {
        const ASString n = Name.AsString();
        if (!n.IsEmpty())
        {
            ASStringManager* sm = n.GetManager();
            switch (n[0])
            {
            case '@':
                Kind = static_cast<Abc::MultinameKind>(Kind | 8);
                if (n.GetSize() == 2 && n[1] == '*')
                    FUN_1424e0d40(Name, ASString(sm->GetEmptyStringNode()));
                else
                    FUN_1424e0d40(Name, ASString(n.SubstringNode(1, n.GetSize())));
                break;
            case '*':
                FUN_1424e0d40(Name, ASString(sm->GetEmptyStringNode()));
                break;
            default:
                break;
            }
        }
    }
}

// The same with the QName branch (Sfr27MultinameFromQName) inlined too, as ResolveStickyVariables has it.
__forceinline Multiname::Multiname(Instances::Namespace& ns, const Value& name, InlineQNameTag)
    : Kind(static_cast<Abc::MultinameKind>(0))
    , Obj(&ns)
{
    const UInt32 k = static_cast<UInt32>(name.GetKind());
    if (k - 0xc <= 3 && name.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(name.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
        {
            // SetFromQName: the QName's local name and namespace (QName::LocalName +0x38, Ns +0x40).
            const UPInt q = reinterpret_cast<UPInt>(name.GetGASRefCountBase());
            FUN_1424e0d40(Name, *reinterpret_cast<const ASString*>(q + 0x38));
            // PostProcessName(true): '@' is a plain character in a QName name.
            if (Name.IsString())
            {
                const ASString qn = Name.AsString();
                if (!qn.IsEmpty())
                {
                    ASStringManager* sm = qn.GetManager();
                    if (qn[0] == '*')
                        FUN_1424e0d40(Name, sm->CreateEmptyString());
                }
            }
            // SPtr::SetPtr, inline
            GASRefCountBase* const ns = *reinterpret_cast<GASRefCountBase* const*>(q + 0x40);
            GASRefCountBase*& o = Obj.GetRawRef();
            if (ns != o)
            {
                if (o)
                {
                    if (reinterpret_cast<UPInt>(o) & 1)
                        o = reinterpret_cast<GASRefCountBase*>(reinterpret_cast<UPInt>(o) - 1);
                    else
                        o->Release();
                }
                if (ns)
                    ns->AddRef();
                o = ns;
            }
            Kind = static_cast<Abc::MultinameKind>(Kind & ~6);
            return;
        }
    }
    Sfr17ValueInline::Assign(Name, name);
    // PostProcessName(false) (0x14251cef0, sfr_as3_18) inlined: the three renames share one assignment
    if (Name.IsString())
    {
        ASString n = Name.AsString();
        if (n.GetSize() != 0)
        {
            if (n[0] == '*')
                goto empty_name;
            if (n[0] == '@')
            {
                Kind = static_cast<Abc::MultinameKind>(Kind | 8);
                if (n.GetSize() == 2 && n[1] == '*')
                {
                empty_name:
                    FUN_1424e0d40(Name, ASString(n.GetManager()->GetEmptyStringNode()));
                }
                else
                    FUN_1424e0d40(Name, ASString(n.SubstringNode(1, n.GetSize())));
            }
        }
    }
}

// MS2-FUNCTIONAL 0x14253c470: SDK exec_newclass form; the remaining diff is register allocation (the
// interned namespace / global object held in other callee-saved regs) and the placement of the inlined
// PostProcessName blocks (the exe hoists the string manager load and moves SubstringNode to the end).
// @0x14253c470
void Sfr31ExecClassEntry(UPInt vmAddr, UPInt link, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    VMAbcFile& file = *reinterpret_cast<VMAbcFile*>(link);
    const UPInt abc = Sfr31Rd(link, 0x28);
    // file.GetClasses().Get(v)
    const UPInt class_info = reinterpret_cast<const UPInt*>(Sfr31Rd(abc, 0x140))[idx];
    Value& value = *reinterpret_cast<Value*>(Sfr31Rd(vmAddr, 0x50));
    if (value.IsNullOrUndefined())
    {
        // class_info.HasSuperClass()
        if (*reinterpret_cast<const int*>(class_info + 0x28) != 0)
            return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f1), vm));
    }
    else
    {
        if (!value.IsClass())
            return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f1), vm));
    }
    // class_info.GetName(file.GetConstPool())
    const SPInt mnIdx = *reinterpret_cast<const int*>(class_info + 0x24);
    const UPInt name = mnIdx == 0 ? abc + 0xe8 : mnIdx * 0x10 + Sfr31Rd(abc, 0xb8);
    Instances::Namespace& t_ns = file.GetInternedNamespace(*reinterpret_cast<const int*>(name + 4));
    const ASString& t_uri = *reinterpret_cast<const ASString*>(reinterpret_cast<UPInt>(&t_ns) + 0x30);
    const StringDataPtr t_str(t_uri.ToCStr(), t_uri.GetSize());
    const StringDataPtr scaleform_gfx("scaleform.gfx");
    if (t_str.GetSize() >= scaleform_gfx.GetSize() && strncmp(t_str.ToCStr(), scaleform_gfx.ToCStr(), scaleform_gfx.GetSize()) == 0)
    {
        const ASString t_name = file.GetInternedString(*reinterpret_cast<const int*>(name + 8));
        if (!reinterpret_cast<Object*>(vm.GlobalObject.GetPtr())->GetProperty(Multiname(t_ns, Value(t_name, Value::InlineStr), Multiname::InlineAssignTag()), value))
            return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42d), vm, t_name.ToCStr(), scaleform_gfx.ToCStr()));
    }
    else
    {
        ClassTraits::Traits& cud = *reinterpret_cast<ClassTraits::Traits*>(FUN_14250f9a0(vmAddr, link, class_info));
        const UPInt itr = Sfr31Rd(reinterpret_cast<UPInt>(&cud), 0xc0);
        if (Sfr31Rd(itr, 0x80) != 0)
            value = reinterpret_cast<Class*>(Sfr31Rd(itr, 0x80));
        else
        {
            SPtr<Class> made = cud.FUN_142419e50();
            ValueAssignCopies::PickClass19(value, made.GetPtr());
            made.GetRawRef() = NULL;
        }
    }
}

// ---- batch 62
// 3x4 matrix variant of SetDisplayMatrix (movie-clip-like kinds only): the matrix goes to the object with its translation in twips and
// the 3D position, z scale and the two rotations are re-derived from it.
// SDK Matrix3x4<T>::IsValid (Render_Matrix3x4.h): the SF_ISFINITE chain over the twelve elements, unrolled as the SDK writes it.
static SF_INLINE bool Sfr31FiniteF(float v) { return v >= -FLT_MAX && v <= FLT_MAX; }
static SF_INLINE bool Sfr31Matrix3FIsValid(const Render::Matrix3F& m)
{
    return Sfr31FiniteF(m.M[0][0]) && Sfr31FiniteF(m.M[0][1]) && Sfr31FiniteF(m.M[0][2]) && Sfr31FiniteF(m.M[0][3])
        && Sfr31FiniteF(m.M[1][0]) && Sfr31FiniteF(m.M[1][1]) && Sfr31FiniteF(m.M[1][2]) && Sfr31FiniteF(m.M[1][3])
        && Sfr31FiniteF(m.M[2][0]) && Sfr31FiniteF(m.M[2][1]) && Sfr31FiniteF(m.M[2][2]) && Sfr31FiniteF(m.M[2][3]);
}
}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// SDK: AS3ValueObjectInterface::SetMatrix3D (AS3_GFxValueImpl.cpp).
// @0x1425278d0
bool AS3ValueObjectInterface::SetMatrix3D(void* pdata, const Render::Matrix3F& mat)
{
    using namespace AS3;
    const UPInt valueObj = reinterpret_cast<UPInt>(pdata);
    const UPInt info = Sfr31Rd(valueObj, 0x20);
    if (!((*reinterpret_cast<const SInt32*>(info + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<const UInt8*>(info + 0x68) >> 5)) & 1) != 0)))
        return false;
    DisplayObjectBase* pd = reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(valueObj, 0x58));
    if (!Sfr31Matrix3FIsValid(mat))
        return false;
    Render::Matrix3F tm = mat;
    tm.Tx() = PixelsToTwips(tm.Tx());
    tm.Ty() = PixelsToTwips(tm.Ty());
    tm.Tz() = PixelsToTwips(tm.Tz());
    pd->SetMatrix3D(tm);
    DisplayObjectBase::GeomDataType gd;
    pd->GetGeomData(gd);
    gd.Z = mat.Tz();
    gd.ZScale = mat.GetZScale() * (Double)100.;
    float xr, yr;
    mat.GetRotation(&xr, &yr, NULL);
    gd.XRotation = SF_RADTODEG(xr);
    gd.YRotation = SF_RADTODEG(yr);
    pd->SetGeomData(gd);
    return true;
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {
// ---- batch 63
// Super-property getter-and-call opcode: pops the receiver, resolves the frame's parent-slot accessor, runs it to get a function and
// calls that with the popped arguments.
// MS2-FUNCTIONAL 0x142535f40: SDK exec_callsupergetter form; the only diff is register allocation (the exe holds the parent
// traits in rdx, ours in rcx) and the order of two argument stores before the getter call
static __forceinline void Sfr19Execute(VM& vm, const Value& func, const Value& _this, unsigned argc, const Value* argv, bool discard_result);
// @0x142535f40
void Sfr31ExecCallParentSlot(UPInt vmAddr, UInt32 slotIdx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsObject args(vm, argc);
    if (vm.IsException())
        return;
    // the running frame's origination traits, else the object's own
    const UPInt cnt = Sfr31Rd(vmAddr, 0x78) - 1;
    const Traits* ot = *reinterpret_cast<const Traits* const*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (cnt >> 6) * 8) + 0x40 + (cnt & 0x3f) * 0xa8);
    if (ot == NULL)
        ot = &vm.GetValueTraits(args.ArgObject);
    const Traits* parent_tr = ot->GetParent();
    if (parent_tr == NULL)
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x40b), vm, "Couldn't find parent property"));
    const Value funct_getter(static_cast<SInt32>(slotIdx), *parent_tr, Value::kVTableInd);
    Value funct;
    vm.ExecuteInternalUnsafe(funct_getter, args.ArgObject, funct, 0, NULL, false);
    if (vm.IsException())
        return;
    Sfr19Execute(vm, funct, args.ArgObject, argc, args.GetCallArgs(), false);
}
// ---- batch 64
// callstatic opcode: pops the receiver, then runs the method body of the file's method idx on it with the popped arguments in a new
// call frame (the frame is named after the receiver's traits plus " callstatic").
// MS2-FUNCTIONAL 0x142535680: 1112 B vs the exe 1124; SDK exec_callstatic form, the rest is register allocation and scheduling inside
// the inlined VM::AddFrame (the exe spills argc, keeps the body index sign-extended in r13 and computes argv after the name)
// @0x142535680
void Sfr31ExecCallStatic(UPInt vmAddr, UPInt file, SInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsObject args(vm, argc);
    if (vm.IsException())
        return;
    {
        // file.GetMethodBodyInfoInd(ind): the method_info's body index
        const SInt32 mbiInd = *reinterpret_cast<const SInt32*>(reinterpret_cast<const UPInt*>(Sfr31Rd(Sfr31Rd(file, 0x28), 0xf8))[idx] + 8);
        const Traits& tr = args.ArgObject.GetObject()->GetTraits();
        vm.AddFrame(Value::GetUndefined(), *reinterpret_cast<VMAbcFile*>(file), mbiInd, args.ArgObject, argc, args.GetCallArgs(), false,
                    *reinterpret_cast<const ScopeStackType*>(reinterpret_cast<UPInt>(&tr) + 0xa0), tr, tr.GetName() + " callstatic");
    }
}
// ---- batch 65
// getlex-style opcode on a compile-time name: resolves the multiname (no runtime parts) against the scope stack and pushes the property's
// value; a non-compile-time name is a TypeError and an unresolved one a ReferenceError.
static __forceinline CheckResult Sfr19GetSlotValueUnsafe(const PropRef& prop, VM& vm, Value& value, SlotInfo::ValTarget vt);
// getlex opcode (SDK exec_getlex): finds the scope object holding the compile-time multiname and pushes the property value.
// @0x142539650
void Sfr31ExecGetLexStatic(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& cvm = *reinterpret_cast<VM*>(Sfr31Rd(file, 0x20));
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntryW(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    if ((flags & 3) == 1 || (static_cast<UInt8>(flags >> 2) & 1) != 0)
    {
        const StringDataPtr sv = Sfr31MnNameView(file, entry).ToStringDataPtr();
        String name(sv.ToCStr(), sv.GetSize());
        cvm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x436), cvm, name.ToCStr(), "compile time"));
    }
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    if (vm.IsException())
        return;
    Sfr31MnBox mn(*reinterpret_cast<VMAbcFile*>(file), *reinterpret_cast<const Abc::Multiname*>(entry));
    PropRef prop;
    FUN_142502570(vmAddr, &prop, &mn.Get());
    if (Sfr19PropFound(prop))
    {
        Value value;
        if (!Sfr19GetSlotValueUnsafe(prop, vm, value, SlotInfo::valGet))
            return;
        ValueStack::Of(vm).PushBack(value);
    }
    else
    {
        StringDataPtr sv = Sfr31MnNameView(file, entry).ToStringDataPtr();
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42d), vm, sv.ToCStr(), "any object on the scope stack"));
    }
}
// ---- batch 66
// hasnext2 opcode: registers objReg/idxReg hold the object and the enumeration index; advances the index (walking the prototype chain
// when the own properties are exhausted), stores both back and pushes whether another property exists.
// VM::GetRegister / SetRegister: the register file's current page is the word at VM+0x148.
static __forceinline Value& Sfr19GetRegister(VM& vm, AbsoluteIndex ind)
{
    return reinterpret_cast<Value*>(*reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(&vm) + 0x148))[ind.Get()];
}
static __forceinline void Sfr19SetRegister(VM& vm, AbsoluteIndex ind, const Value& v)
{
    Sfr19GetRegister(vm, ind).Assign(v);
}

// MS2-FUNCTIONAL 0x14253a6a0: SDK exec_hasnext2 form with the bool pushes merged into one tail, as the exe has them;
// the exe keeps its Value temps 8 bytes lower in a 0x58 frame and allocates other registers
// @0x14253a6a0
void Sfr31ExecHasNext2(UPInt vmAddr, UInt32 object_reg, UInt32 index_reg)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    const AbsoluteIndex reg_ind(index_reg);
    const AbsoluteIndex obj_ind(object_reg);
    Value& obj_value = Sfr19GetRegister(vm, obj_ind);

    if (index_reg == object_reg)
        return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x464), vm));

    if (obj_value.IsNullOrUndefined())
        return ValueStack::Of(vm).PushBack(Value(false));

    UInt32 v = 0;
    if (!Sfr19GetRegister(vm, reg_ind).Convert2UInt32(v))
        return;

    GlobalSlotIndex slot_ind(v);
    bool result;

    if (obj_value.IsObject())
    {
        Object& obj = obj_value;

        GlobalSlotIndex ind = obj.GetNextDynPropIndex(slot_ind);
        Object* cur_obj = &obj;

        const Traits* cur_tr = &obj.GetTraits();
        while (cur_tr && !ind.IsValid())
        {
            cur_obj = &const_cast<Class&>(cur_tr->GetConstructor()).GetPrototype();
            ind = cur_obj->GetNextDynPropIndex(GlobalSlotIndex(0));
            cur_tr = cur_tr->GetParent();
        }

        if (ind.IsValid())
        {
            if (cur_obj != &obj)
                Sfr19SetRegister(vm, obj_ind, Value(cur_obj, Value::InlineObj));
        }
        else
            Sfr19SetRegister(vm, obj_ind, Value::GetNull());

        Sfr19SetRegister(vm, reg_ind, Value(ind.Get()));
        result = ind.IsValid();
    }
    else
    {
        if (obj_value.IsNamespace())
        {
            GlobalSlotIndex ind(0);
            ::FUN_1424161e0(obj_value.GetNamespace(), &ind, slot_ind);
            Sfr19SetRegister(vm, reg_ind, Value(ind.Get()));
            result = ind.IsValid();
            goto push;
        }

        GlobalSlotIndex ind = slot_ind;

        const Traits* cur_tr = &vm.GetValueTraits(obj_value);
        Object* cur_obj = NULL;

        if (cur_tr->GetTraitsType() == Traits_Namespace && cur_tr->IsInstanceTraits())
        {
            switch (ind.Get())
            {
            case 0:
            case 1:
                Sfr19SetRegister(vm, reg_ind, Value(ind.Get() + 1));
                result = true;
                goto push;
            default:
                break;
            }
        }

        do {
            cur_obj = &const_cast<Class&>(cur_tr->GetConstructor()).GetPrototype();
            ind = cur_obj->GetNextDynPropIndex(GlobalSlotIndex(0));
            cur_tr = cur_tr->GetParent();
        }
        while (cur_tr && !ind.IsValid());

        if (ind.IsValid())
            Sfr19SetRegister(vm, obj_ind, Value(cur_obj, Value::InlineObj));
        else
            Sfr19SetRegister(vm, obj_ind, Value::GetNull());

        Sfr19SetRegister(vm, reg_ind, Value(ind.Get()));
        result = ind.IsValid();
    }
push:
    ValueStack::Of(vm).PushBack(Value(result));
}
// ---- batch 67
// constructprop opcode: the receiver stays on the operand stack; a class named by a static multiname is constructed directly, otherwise
// the property is looked up on the receiver and the value found is constructed with the popped arguments.
static __forceinline CheckResult Sfr19GetSlotValueUnsafe(const PropRef& prop, VM& vm, Value& value, SlotInfo::ValTarget vt);
// The SDK ReadArgsMnObjectRef: the call arguments and the multiname, then a reference to the object left on top of the stack
// (null or undefined throws).
struct Sfr31ReadArgsMnObjectRef : public Sfr31ReadArgsMn
{
    __forceinline Sfr31ReadArgsMnObjectRef(UPInt link, UInt32 argc, UInt32 idx) : Sfr31ReadArgsMn(link, argc, idx), ArgObject(*OpStack.GetTopPtr())
    {
        CheckObject(ArgObject);
    }
    void CheckObject(const Value& v) const
    {
        if (v.IsNullOrUndefined())
        {
            const VM::ErrorID id = v.IsNull() ? static_cast<VM::ErrorID>(0x3f1) : static_cast<VM::ErrorID>(0x3f2);
            VM& vm = VMRef;
            Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(id, vm));
        }
    }
    const Value* GetCallArgs() const { return ArgNum > 8 ? CallArgs.GetDataPtr() : FixedArgs; }
    Value& ArgObject;
};
// @0x1425371f0
void Sfr31ExecConstructProp(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsMnObjectRef args(file, argc, idx);
    if (vm.IsException())
        return;
    // IsQName: the exe reads the namespace kind bits as a 2-bit field (and al, 3), not through Multiname::IsQName (and eax, 3).
    struct KindBits { UInt32 ns : 2; };
    if (reinterpret_cast<const KindBits*>(&args.ArgMN.Get())->ns <= 1)
    {
        const ClassTraits::Traits* ctr = reinterpret_cast<VM*>(vmAddr)->Resolve2ClassTraits(args.ArgMN.Get());
        if (ctr)
        {
            InstanceTraits::Traits& itr = ctr->GetInstanceTraits();
            itr.GetConstructor().Construct(args.ArgObject, argc, args.GetCallArgs());
            return;
        }
    }
    PropRef prop;
    FUN_142501b00(&prop, &vm, &args.ArgObject, &args.ArgMN.Get(), 0);
    if (Sfr19PropFound(prop))
    {
        Value value;
        if (!Sfr19GetSlotValueUnsafe(prop, vm, value, SlotInfo::valGet))
            return;
        if (value.IsNullOrUndefined())
            return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f1), vm));
        const Value::KindType kind = value.GetKind();
        if (kind == Value::kVTableInd || kind == Value::kVTableIndClosure)
            return vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x428), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
        value.GetObject()->Construct(args.ArgObject, argc, args.GetCallArgs());
    }
    else
        return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42d), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2), args.ArgObject));
}
// ---- batch 68

// newfunction opcode: builds the closure scope (the running frame's saved scope followed by what the innermost frame pushed on the scope
// stack), creates the Function of method methodInd on the Function class and pushes it.
// MS2-FUNCTIONAL 0x14253c910: raw-offset model with the exe shape (ss = *saved, inlined Value release); the exe keeps the global object in rbx and the Function traits in rdi (ours swaps them) and the frame count in r9 (992 vs 1004 bytes)
// @0x14253c910
void Sfr31ExecNewFunction(UPInt vmAddr, UPInt frame, UInt32 methodInd)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    const ArrayDH<Value>* saved = reinterpret_cast<const ArrayDH<Value>*>(Sfr31Rd(frame, 0x38));
    VMAbcFile& file = *reinterpret_cast<VMAbcFile*>(Sfr31Rd(frame, 0x28));
    ArrayDH<Value> ss(reinterpret_cast<MemoryHeap*>(Sfr31Rd(vmAddr, 0x38)));
    if (saved != 0 && saved->GetSize() != 0)
        ss = *saved;
    const UPInt nFrames = Sfr31Rd(vmAddr, 0x78);
    const UPInt scopeEnd = Sfr31Rd(vmAddr, 0x168);
    const UPInt base = nFrames == 0 ? 0
        : Sfr31Rd(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), ((nFrames - 1) >> 6) * 8) + ((nFrames - 1) & 0x3f) * 0xa8, 8);
    for (UPInt i = base; i < scopeEnd; ++i)
        ss.PushBack(*reinterpret_cast<const Value*>(Sfr31Rd(vmAddr, 0x160) + i * 0x20));
    // GetGlobalObject: the frame count is read again
    UPInt gos;
    const UPInt nFrames2 = Sfr31Rd(vmAddr, 0x78);
    if (nFrames2 == 0)
        gos = 0;
    else
    {
        const UPInt top = Sfr31Rd(Sfr31Rd(vmAddr, 0x90), ((nFrames2 - 1) >> 6) * 8) + ((nFrames2 - 1) & 0x3f) * 0xa8;
        const ArrayDH<Value>* sv = reinterpret_cast<const ArrayDH<Value>*>(Sfr31Rd(top, 0x38));
        if (sv != 0 && sv->GetSize() != 0)
            gos = Sfr31Rd(reinterpret_cast<UPInt>(&(*sv)[0]), 0x10);
        else
        {
            const UPInt p = Sfr31Rd(Sfr31Rd(top, 0x18), 8);
            if (((*reinterpret_cast<const UInt32*>(p) & 0x1f) - 0xc) <= 3)
                gos = Sfr31Rd(p, 0x10);
            else
                gos = 0;
        }
    }
    const UPInt ftr = Sfr31Rd(Sfr31Rd(vmAddr, 0x208), 0xc0);
    UPInt cls = Sfr31Rd(ftr, 0x80);
    if (cls == 0)
    {
        typedef void (*MakeFn)(UPInt);
        reinterpret_cast<MakeFn>(Sfr31Rd(Sfr31Rd(ftr, 0), 0x68))(ftr);
        cls = Sfr31Rd(ftr, 0x80);
    }
    Pickable<Instances::Function> funct = reinterpret_cast<const Classes::Function*>(cls)->FUN_14241a7d0(
        file, methodInd, ss, *reinterpret_cast<Instances::fl::GlobalObjectScript*>(gos));
    Sfr19InlineReleaseValue vs;
    Value& v = *::new (vs.Buf) Value();
    v.PickUnsafe(funct.GetPtr());
    ExecPushCopy(&vm, v);
}
}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// The AvmDisplayObj interface of a display object (its avm sub-object's virtual at +0x28).
struct Sfr19AvmSub { virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3(); virtual void V4(); virtual UPInt GetAvm(); };
static __forceinline UPInt Sfr19GetAvmIntf(UPInt dobj)
{
    return reinterpret_cast<Sfr19AvmSub*>(dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4)->GetAvm();
}

// ---- batch 69
// AS3ValueObjectInterface::SetMember: sets the named member of an object from a GFx value. "*" is the any-name and a leading "@" makes
// the name an attribute. A name that is already a child of a display object is refused with a log message.
// MS2-FUNCTIONAL 0x142527d60: raw-offset model; the exe spills gfxValue/name to other frame slots in the prolog, the
// PostProcessName rename branches are laid out in another order, and the name Value / Multiname sit in other slots
// @0x142527d60
bool AS3ValueObjectInterface::SetMember(void* pdata, const char* name, const Value& value, bool)
{
    using namespace AS3;
    const UPInt self = reinterpret_cast<UPInt>(this);
    Object* obj = static_cast<Object*>(pdata);
    const void* gfxValue = &value;
    const UPInt root = Sfr31Rd(Sfr31Rd(self, 8), 0x18);
    VM& vm = *reinterpret_cast<VM*>(Sfr31Rd(root, 0x48));
    ASStringManager* mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348));
    Multiname mn(*reinterpret_cast<Instances::Namespace*>(Sfr31Rd(reinterpret_cast<UPInt>(&vm), 0x1d0)),
                 AS3::Value(ASString(mgr->CreateStringNode(name)), AS3::Value::InlineStr), Multiname::InlineAssignTag());
    const UPInt otraits = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x20);
    if (*reinterpret_cast<const int*>(otraits + 0x70) - 0x17U < 6
        && (static_cast<UByte>(~static_cast<UByte>(*reinterpret_cast<const UByte*>(otraits + 0x68) >> 5)) & 1) != 0)
    {
        // the display object is read without a null test, as the exe does
        const UPInt pd = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x58);
        const UPInt dobj = (static_cast<UByte>(static_cast<UInt16>(*reinterpret_cast<const UInt16*>(pd + 0x6a) >> 9)) & 1) ? pd : 0;
        UPInt owner;
        UPInt avm;
        if (dobj != 0 && (avm = Sfr19GetAvmIntf(dobj)) != 0)
            owner = avm - 0x28;
        else
            owner = 0x18;
        ASString key(reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateStringNode(name));
        DisplayList* dl = reinterpret_cast<DisplayList*>(Sfr31Rd(owner, 0) + 0xd8);
        DisplayObject* ch = dl->GetDisplayObjectByName(key, true);
        if (ch != NULL)
        {
            const UPInt sub = reinterpret_cast<UPInt>(ch) + *reinterpret_cast<const UByte*>(reinterpret_cast<UPInt>(ch) + 0x6d) * 4;
            typedef void (*MakeAvmFn)(UPInt, bool);
            reinterpret_cast<MakeAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 0x78))(sub, true);
            UPInt avmObj = Sfr31Rd(sub, 0x10);
            if (avmObj == 0)
                avmObj = Sfr31Rd(sub, 8);
            if (avmObj & 1)
                avmObj -= 1;
            if (avmObj != 0)
            {
                String msg;
                Scaleform::Format(msg, "Property '{0}' already exists as a DisplayObject. SetMember aborted.", name);
                typedef void (*LogFn)(UPInt, int, const char*);
                reinterpret_cast<LogFn>(Sfr31Rd(Sfr31Rd(root + 0x28, 0), 8))(root + 0x28, 1, msg.ToCStr());
                return false;
            }
        }
    }
    AS3::Value val;
    FUN_1425048d0(root, gfxValue, &val);
    if (!obj->SetProperty(mn, val))
    {
        const UPInt vmAddr = reinterpret_cast<UPInt>(&vm);
        if (*reinterpret_cast<UByte*>(vmAddr + 0x180) != 0)
        {
            *reinterpret_cast<UByte*>(vmAddr + 0x180) = 0;
            vm.OutputError(*reinterpret_cast<AS3::Value*>(vmAddr + 0x188));
            reinterpret_cast<AS3::Value*>(vmAddr + 0x188)->SetUndefined();
        }
        return false;
    }
    return true;
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {
// ---- batch 70
// The AS3 object the display object part of an interface object (at dobj) carries; created on first use.
static UPInt Sfr31AvmObjOfDisplay(UPInt dobj)
{
    const UPInt sub = dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4;
    typedef void (*MakeAvmFn)(UPInt, int);
    reinterpret_cast<MakeAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 0x78))(sub, 1);
    UPInt avmObj = Sfr31Rd(sub, 0x10);
    if (avmObj == 0)
        avmObj = Sfr31Rd(sub, 8);
    if (avmObj & 1)
        avmObj -= 1;
    return avmObj;
}

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// Slots::GetSlotNameNode / GetSlotInfo (SDK AS3_Traits.h inlines): a parent's slot goes through the parent's out-of-line copy.
static __forceinline ASStringNode* Sfr19SlotNameNode(const AS3::Slots& s, AS3::AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotNameNode(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Key;
}
// AvmDisplayObjContainer::GetAS3ChildAt (0x142505cc0, sfr_as3_17), inlined by the exe; the SPtr result is a temporary.
static __forceinline AS3::SPtr<AS3::Instances::fl_display::DisplayObject> Sfr19GetAS3ChildAtSPtr(AS3::AvmDisplayObjContainer* pcurr, unsigned index)
{
    DisplayObjectBase* ch = pcurr->GetDisplayObjContainer()->GetChildAt(index);
    if (ch)
    {
        AS3::AvmDisplayObj* pavm = AS3::ToAvmDisplayObj(ch);
        pavm->CreateASInstance(true);
        return pavm->GetAS3Obj();
    }
    return NULL;
}
static __forceinline AS3::Instances::fl_display::DisplayObject* Sfr19GetAS3ChildAt(AS3::AvmDisplayObjContainer* pcurr, unsigned index)
{
    return Sfr19GetAS3ChildAtSPtr(pcurr, index);
}
// SPtr::Release: a tagged pointer is untagged in place, else the object released.
static __forceinline void Sfr19ReleaseSPtrSlot(AS3::Object*& p)
{
    if (reinterpret_cast<UPInt>(p) & 1)
        p = reinterpret_cast<AS3::Object*>(reinterpret_cast<UPInt>(p) - 1);
    else if (p)
        p->Release();
}
// Value(Object*) whose dtor expands Value::ReleaseInternal in place (the exe's LTCG inlines it here).
struct Sfr19ObjectValue
{
    union
    {
        UPInt Align;
        UByte Buf[sizeof(AS3::Value)];
    };
    __forceinline explicit Sfr19ObjectValue(AS3::Object* p) { ::new (Buf) AS3::Value(p); }
    AS3::Value& Get() { return *reinterpret_cast<AS3::Value*>(Buf); }
    __forceinline ~Sfr19ObjectValue()
    {
        AS3::Value& v = Get();
        if (!v.IsRefCounted())
            return;
        if (v.IsWeakRef())
        {
            // Value::ReleaseWeakRefSCU
            AS3::WeakProxy*& wp = *reinterpret_cast<AS3::WeakProxy**>(Buf + 0x08);
            wp->Release();
            wp = NULL;
            *reinterpret_cast<UPInt*>(Buf + 0x10) = 0;
            *reinterpret_cast<UPInt*>(Buf + 0x18) = 0;
            *reinterpret_cast<UInt32*>(Buf) &= ~0x200u;
            *reinterpret_cast<UInt32*>(Buf) &= ~0x1fu;
            return;
        }
        switch (v.GetKind())
        {
        case AS3::Value::kString:
            (*reinterpret_cast<ASStringNode**>(Buf + 0x10))->Release();
            break;
        case AS3::Value::kNamespace:
        case AS3::Value::kObject:
        case AS3::Value::kClass:
        case AS3::Value::kFunction:
        case AS3::Value::kThunkFunction:
            Sfr19ReleaseSPtrSlot(*reinterpret_cast<AS3::Object**>(Buf + 0x10));
            break;
        case AS3::Value::kThunkClosure:
        case AS3::Value::kVTableIndClosure:
            Sfr19ReleaseSPtrSlot(*reinterpret_cast<AS3::Object**>(Buf + 0x18));
            break;
        default:
            break;
        }
    }
};
// Traits::CIterator::operator++: stops at the end.
static __forceinline void Sfr19NextSlot(const AS3::Slots& s, AS3::AbsoluteIndex& ind)
{
    if (ind < s.GetSlotInfoNum())
        ind = AS3::AbsoluteIndex(ind.Get() + 1);
}
static __forceinline const AS3::SlotInfo& Sfr19SlotInfo(const AS3::Slots& s, AS3::AbsoluteIndex ind)
{
    if (ind < s.FirstOwnSlotNum)
        return s.Parent->GetSlotInfo(ind);
    return s.VArray[static_cast<UInt32>(ind.Get()) - s.FirstOwnSlotNum].Value;
}

// AS3ValueObjectInterface::VisitMembers: the visitor receives the dynamic members, the public non-method slots (when it asks for them)
// and, for a display object container, its children by name.
// MS2-FUNCTIONAL 0x142531630: SDK VisitMembers shape with the exe's inlined slot accessors, GetAS3ChildAt and ~Value; regalloc, stack slots and the inline Value(Object*) ctor differ
// @0x142531630
void AS3ValueObjectInterface::VisitMembers(void* pdata, ObjVisitor* visitor, bool) const
{
    using namespace AS3;
    const UPInt self = reinterpret_cast<UPInt>(this);
    const UPInt root = Sfr31Rd(Sfr31Rd(self, 8), 0x18);
    Object* obj = static_cast<Object*>(pdata);

    const Object::DynAttrsType* dynAttrs = obj->GetDynamicAttrs();
    if (dynAttrs)
    {
        Object::DynAttrsType::ConstIterator it = dynAttrs->Begin();
        for (; !it.IsEnd(); ++it)
        {
            GFx::Value val;
            const ASString& name = it->First.Name;
            const AS3::Value& asval = it->Second;
            FUN_1424e42c0(root, &asval, &val);
            visitor->Visit(name.ToCStr(), val);
        }
    }

    if (visitor->IncludeAS3PublicMembers())
    {
        const Traits& t = obj->GetTraits();
        for (AbsoluteIndex ind(0); !(static_cast<UInt32>(ind.Get()) >= t.GetSlotInfoNum()); Sfr19NextSlot(t, ind))
        {
            GFx::Value val;
            ASString name(Sfr19SlotNameNode(t, ind));
            const SlotInfo& slotInfo = Sfr19SlotInfo(t, ind);
            const int bt = static_cast<int>(slotInfo.BindType);
            if (bt == 0xb || bt > 0xc)
                continue;
            if (static_cast<int>(slotInfo.pNs->GetKind()) != 0)
                continue;
            AS3::Value asval;
            char ok;
            FUN_14250e770(&slotInfo, &ok, &asval, obj);
            FUN_1424e42c0(root, &asval, &val);
            visitor->Visit(name.ToCStr(), val);
        }
    }
    const UPInt otraits = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x20);
    if (*reinterpret_cast<const int*>(otraits + 0x70) - 0x17U > 5 || ((~(*reinterpret_cast<const UByte*>(otraits + 0x68) >> 5)) & 1) == 0)
        return;
    UPInt dobj = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x58);
    if (dobj != 0 && !((*reinterpret_cast<const UInt16*>(dobj + 0x6a) >> 9) & 1))
        dobj = 0;
    AvmDisplayObjContainer* pcurr = dobj != 0
        ? AvmDisplayObjContainer::FromBase(reinterpret_cast<DisplayObjContainer*>(dobj)->GetAvmDispContainer()) : NULL;
    for (unsigned i = 0; i < static_cast<unsigned>(pcurr->GetDisplayObjContainer()->mDisplayList.GetCount()); i++)
    {
        Instances::fl_display::DisplayObject* pchild = Sfr19GetAS3ChildAt(pcurr, i);
        ASString name = pchild->pDispObj->GetName();
        Sfr19ObjectValue asval(pchild);
        GFx::Value val;
        FUN_1424e42c0(root, &asval.Get(), &val);
        visitor->Visit(name.ToCStr(), val);
    }
}

}} // namespace Scaleform::GFx
namespace Scaleform { namespace GFx { namespace AS3 {
// ---- batch 71
// callpropvoid opcode: the receiver is popped, the property looked up on it (a missing one is an error unless the object is dynamic) and
// the value found called with the popped arguments, the result dropped.
// PropRef::GetSlotValueUnsafe (0x14250e200, sfr_as3_18), which the exe inlines into the call opcodes.
static __forceinline CheckResult Sfr19GetSlotValueUnsafe(const PropRef& prop, VM& vm, Value& value, SlotInfo::ValTarget vt)
{
    bool ok = true;
    const UPInt w = reinterpret_cast<UPInt>(prop.pValue);
    switch (w & 3)
    {
    case 0:
    {
        char r;     // the callee's result slot
        ok = *reinterpret_cast<const bool*>(FUN_14250e2d0(prop.pSI, &r, &vm, &value, &prop.This, NULL, vt));
        break;
    }
    case 1:
        ValueAssignCopies::AssignUnsafeCopy(value, *reinterpret_cast<const Value*>(w & ~static_cast<UPInt>(1)));
        break;
    case 2:
        ValueAssignCopies::AssignUnsafeObject19(value, reinterpret_cast<Object*>(w & ~static_cast<UPInt>(2)));
        break;
    }
    return CheckResult(ok);
}

// VM::Execute: the call with its result dropped unless it goes on the stack (the SDK inline).
static __forceinline void Sfr19Execute(VM& vm, const Value& func, const Value& _this, unsigned argc, const Value* argv, bool discard_result = false)
{
    Value result = Value::GetUndefined();
    vm.ExecuteInternalUnsafe(func, _this, result, argc, argv, !discard_result);
}

// @0x142534eb0
void Sfr31ExecCallPropVoid(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsMnObject args(file, argc, idx);
    if (vm.IsException())
        return;
    PropRef prop;
    FUN_142501b00(&prop, &vm, &args.ArgObject, &args.ArgMN.Get(), 2);
    if (Sfr19PropFound(prop))
    {
        Value value;
        if (!Sfr19GetSlotValueUnsafe(prop, vm, value, SlotInfo::valExecute))
            return;
        if (value.IsNullOrUndefined())
        {
            Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(static_cast<VM::ErrorID>(0x3ee), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
            return;
        }
        Sfr19Execute(vm, value, args.ArgObject, argc, args.GetCallArgs(), true);
    }
    else
    {
        if (vm.GetValueTraits(args.ArgObject).IsDynamic())
        {
            Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(static_cast<VM::ErrorID>(0x3ee), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
            return;
        }
        else
            return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42d), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2), args.ArgObject));
    }
}
// ---- batch 72
// callproplex opcode: the receiver is popped, the property looked up on it (a missing one is an error unless the object is dynamic) and
// the value found called with undefined as this and the popped arguments; the result is pushed.
// @0x142534820
void Sfr31ExecCallPropLex(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsMnObject args(file, argc, idx);
    if (vm.IsException())
        return;
    PropRef prop;
    FUN_142501b00(&prop, &vm, &args.ArgObject, &args.ArgMN.Get(), 2);
    if (Sfr19PropFound(prop))
    {
        Value value;
        if (!Sfr19GetSlotValueUnsafe(prop, vm, value, SlotInfo::valExecute))
            return;
        if (value.IsNullOrUndefined())
        {
            Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(static_cast<VM::ErrorID>(0x3ee), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
            return;
        }
        Sfr19Execute(vm, value, Value::GetUndefined(), argc, args.GetCallArgs());
    }
    else
    {
        if (vm.GetValueTraits(args.ArgObject).IsDynamic())
        {
            Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(static_cast<VM::ErrorID>(0x3ee), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
            return;
        }
        else
            return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42d), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2), args.ArgObject));
    }
}
// ---- batch 73
// Value's destructor where the exe dropped ReleaseWeakRef's clearing stores as dead (the slot is not read again).
static SF_FORCEINLINE void Sfr31DropValue(Value& v)
{
    if (v.IsRefCounted())
    {
        if (v.IsWeakRef())
            (*reinterpret_cast<WeakProxy**>(reinterpret_cast<char*>(&v) + 8))->Release();
        else
            FUN_142521f00(&v);
    }
}
// MovieRoot::SetArray: copies count elements of the given kind (0 int, 1 double, 2 float as number, 3 char* string, 4 wchar_t* string,
// 5 GFx::Value) into the Array found at the variable path (a new one is created and stored when the variable is no Array).
// MS2-FUNCTIONAL 0x14252acc0: SDK SetVariableArray shape; the exe inlines retVal's ReleaseInternal as a kind jump table and builds the
// not-found Value by a movups copy; the rest is register allocation
// @0x14252acc0
bool Sfr31SetArray(UPInt root, int type, UPInt path, UInt32 index, const void* pdata, UInt32 count, UInt32 setType)
{
    MovieRoot& mr = *reinterpret_cast<MovieRoot*>(root);
    const char* ppathToVar = reinterpret_cast<const char*>(path);
    SPtr<Instances::fl::Array> parray;
    Value retVal;
    if (FUN_142506000(root, &retVal, path) && retVal.IsObject())
    {
        Object* pobj = retVal.GetObject();
        if (pobj && pobj->GetTraits().GetTraitsType() == Traits_Array && pobj->GetTraits().IsInstanceTraits())
            parray = static_cast<Instances::fl::Array*>(pobj);
    }
    bool found = true;
    if (!parray)
    {
        parray = Sfr31MakeArray(Sfr31Rd(root, 0x48));
        found = false;
    }
    SparseArray& sa = *reinterpret_cast<SparseArray*>(reinterpret_cast<UPInt>(parray.GetPtr()) + 0x38);
    if (count + index > unsigned(sa.GetSize()))
        FUN_14241fe30(&sa, count + index);
    union VBuf { VBuf() {} ~VBuf() {} Value v; } vb;
    switch (type)
    {
    case 0:
    {
        const SInt32* parr = static_cast<const SInt32*>(pdata);
        for (unsigned i = 0; i < count; ++i)
        {
            Value* v = ::new (static_cast<void*>(&vb.v)) Value(parr[i]);
            sa.Set(i + index, *v);
            Sfr31DropValue(*v);
        }
        break;
    }
    case 2:
    {
        const float* parr = static_cast<const float*>(pdata);
        for (unsigned i = 0; i < count; ++i)
        {
            Value* v = ::new (static_cast<void*>(&vb.v)) Value(Value::Number(parr[i]));
            sa.Set(i + index, *v);
            Sfr31DropValue(*v);
        }
        break;
    }
    case 1:
    {
        const Double* parr = static_cast<const Double*>(pdata);
        for (unsigned i = 0; i < count; ++i)
        {
            Value* v = ::new (static_cast<void*>(&vb.v)) Value(Value::Number(parr[i]));
            sa.Set(i + index, *v);
            Sfr31DropValue(*v);
        }
        break;
    }
    case 5:
    {
        const GFx::Value* parr = static_cast<const GFx::Value*>(pdata);
        for (unsigned i = 0; i < count; ++i)
        {
            Value* v = ::new (static_cast<void*>(&vb.v)) Value();
            FUN_1425048d0(root, &parr[i], v);
            sa.Set(i + index, *v);
            Sfr31DropValue(*v);
        }
        break;
    }
    case 3:
    {
        const char* const* parr = static_cast<const char* const*>(pdata);
        for (unsigned i = 0; i < count; ++i)
        {
            const ASString str(reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateStringNode(parr[i]));
            Value* v = ::new (static_cast<void*>(&vb.v)) Value(str, Value::InlineStr);
            sa.Set(i + index, *v);
            v->~Value();
        }
        break;
    }
    case 4:
    {
        const wchar_t* const* parr = static_cast<const wchar_t* const*>(pdata);
        for (unsigned i = 0; i < count; ++i)
        {
            const ASString str(reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateStringNode(parr[i]));
            Value* v = ::new (static_cast<void*>(&vb.v)) Value(str, Value::InlineStr);
            sa.Set(i + index, *v);
            v->~Value();
        }
        break;
    }
    }
    if (!found)
    {
        Value val(parray, PickValue);
        GFx::Value gfxval;
        mr.ASValue2GFxValue(val, &gfxval);
        return mr.SetVariable(ppathToVar, gfxval, static_cast<MovieRoot::SetVarTypeArg>(setType));
    }
    return true;
}

// ---- batch 74
// callproperty opcode: the receiver is popped, the property looked up on it (a missing one is an error unless the object is dynamic) and
// the value found called with the popped arguments, the result pushed.
// @0x142534100
void Sfr31ExecCallProperty(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31ReadArgsMnObject args(file, argc, idx);
    if (vm.IsException())
        return;
    PropRef prop;
    FUN_142501b00(&prop, &vm, &args.ArgObject, &args.ArgMN.Get(), 2);
    if (Sfr19PropFound(prop))
    {
        Value value;
        if (!Sfr19GetSlotValueUnsafe(prop, vm, value, SlotInfo::valExecute))
            return;
        if (value.IsNullOrUndefined())
            return Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(static_cast<VM::ErrorID>(0x3ee), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
        Sfr19Execute(vm, value, args.ArgObject, argc, args.GetCallArgs());
    }
    else
    {
        if (vm.GetValueTraits(args.ArgObject).IsDynamic() || args.ArgObject.IsPrimitive())
        {
            Sfr31ReadArgsObjectRef::ThrowTypeError(vm, VM::Error(static_cast<VM::ErrorID>(0x3ee), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2)));
            return;
        }
        else
            return vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x42d), vm, *reinterpret_cast<const Value*>(&args.ArgMN.w2), args.ArgObject));
    }
}
// ---- batch 75
// The AS3 flavor of a SetVariable value waiting for its target, as the resolver walks it (see Sfr31AvmStickyVarNode).
struct Sfr31StickyNodeView
{
    void* const* VTbl;              // +0x00 scalar deleting destructor, Assign
    ASString Name;                  // +0x08
    Sfr31StickyNodeView* pNext;     // +0x10
    bool     Permanent;             // +0x18
    Value    Val;                   // +0x20
};

// The display object's interface part (at +[0x6d]*4); slot 1 is GetAvmObjImpl (a virtual call, as DisplayObject::GetAvmObjImpl).
struct Sfr31AvmObjHolder
{
    virtual void  Slot0() = 0;
    virtual UPInt GetAvmObjImpl() = 0;
};

// Value(ASString, InlineStr) whose dtor expands Value::ReleaseInternal in place (the exe's LTCG inlines the kind switch here).
struct Sfr31InlineStrValue : Sfr19InlineReleaseValue
{
    __forceinline explicit Sfr31InlineStrValue(const ASString& s) { ::new (Buf) Value(s, Value::InlineStr); }
};

// MovieRoot: applies the sticky variables kept for a display object (SetVariable calls made before the object existed) to its AS3 object.
// The ones not marked permanent are dropped from the object's chain (and the chain from the table when none is left).
// MS2-FUNCTIONAL 0x142525500: SDK body (AS3_MovieRoot.cpp) with the QName Multiname ctor and the name temp's ReleaseInternal
// inlined; what remains is the register choice (exe r14 root / r15 path / r13 zero / r12 node) and the exe keeping the
// QName name copy in a slot.
// @0x142525500
void Sfr31ResolveStickyVariables(UPInt root, UPInt dobj)
{
    UPInt handle = Sfr31Rd(dobj, 0x70);
    if (handle == 0)
        handle = reinterpret_cast<UPInt>(reinterpret_cast<DisplayObject*>(dobj)->GetCharacterHandle());
    const ASString& path = *reinterpret_cast<const ASString*>(handle + 0x18);              // CharacterHandle::NamePath
    // ToAvmInteractiveObj(pch)->GetAS3Obj(): the AvmDisplayObj sits 0x30 below the interface GetAvmObjImpl returns.
    const UPInt sub = dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4;
    const UPInt avm = reinterpret_cast<Sfr31AvmObjHolder*>(sub)->GetAvmObjImpl();
    const UPInt avmDisp = avm ? avm - 0x30 : 0;
    union
    {
        UPInt   v;
        Object* p;
    } u;
    Object* const raw = *reinterpret_cast<Object* const*>(avmDisp + 0x10);        // pAS3RawPtr
    u.p = raw ? raw : *reinterpret_cast<Object* const*>(avmDisp + 0x08);         // pAS3CollectiblePtr
    if (u.v & 1)
        u.v -= 1;
    typedef ASStringHash<MovieImpl::StickyVarNode*> StickyHash;
    // pMovieImpl->StickyVariables, re-read at each use as in the SDK
#define MS2_STICKY (*reinterpret_cast<StickyHash*>(Sfr31Rd(root, 0x10) + 0x2e08))
    MovieImpl::StickyVarNode* _pnode = 0;
    Sfr31StickyNodeView *p, *pnext, *pnode;
    Object* const pobj = u.p;

    if (MS2_STICKY.Get(path, &_pnode))
    {
        pnode = reinterpret_cast<Sfr31StickyNodeView*>(_pnode);
        Sfr31StickyNodeView* ppermanent = 0;
        Sfr31StickyNodeView* ppermanentTail = 0;

        p = pnode;

        while (p)
        {
            Multiname propname(reinterpret_cast<VM*>(Sfr31Rd(root, 0x48))->GetPublicNamespace(),
                               Sfr31InlineStrValue(p->Name).Get(), Multiname::InlineQNameTag());
            pobj->SetProperty(propname, p->Val);
            pnext = p->pNext;

            if (p->Permanent)
            {
                if (!ppermanent)
                    ppermanent = p;
                else
                    ppermanentTail->pNext = p;

                ppermanentTail = p;
                p->pNext = 0;
            }
            else
            {
                typedef void (*DelFn)(Sfr31StickyNodeView*, int);
                reinterpret_cast<DelFn>(p->VTbl[0])(p, 1);
            }

            p = pnext;
        }

        if (ppermanent)
        {
            if (ppermanent != pnode)
                MS2_STICKY.Set(path, reinterpret_cast<MovieImpl::StickyVarNode*>(ppermanent));
        }
        else
            MS2_STICKY.Remove(path);
    }
}
#undef MS2_STICKY
//
//
//
//
//
//
//
//
//
//
// ---- batch 76
// The display object part's AS3 object (without creating it): the pointer at +0x10, else the one at +0x8, minus the tag bit.
static inline UPInt Sfr31DispAvmPeek(UPInt dobj)
{
    const UPInt sub = dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4;
    UPInt p = Sfr31Rd(sub, 0x10);
    if (p == 0)
        p = Sfr31Rd(sub, 8);
    return (p & 1) ? p - 1 : p;
}

// True when the AS3 object of dobj belongs to the movie definition def.
static inline bool Sfr31DispBelongsTo(UPInt dobj, UPInt def)
{
    const UPInt avmObj = Sfr31DispAvmPeek(dobj);
    if (avmObj == 0)
        return false;
    const UPInt traits = Sfr31Rd(avmObj, 0x20);
    typedef UPInt (*FileFn)(UPInt);
    const UPInt file = reinterpret_cast<FileFn>(Sfr31Rd(Sfr31Rd(traits, 0), 0x50))(traits);
    return file != 0 && Sfr31Rd(Sfr31Rd(file, 0x28), 0x188) == def;
}

// Drops the display objects of the movie definition def from an array of display object pointers (data, size, capacity).
static void Sfr31DropDispOfDef(UPInt* arr, UPInt def)
{
    UPInt i = 0;
    while (i < arr[1])
    {
        UPInt* data = reinterpret_cast<UPInt*>(arr[0]);
        const UPInt elem = data[i];
        if (elem == 0)
        {
            ++i;
            continue;
        }
        ++*reinterpret_cast<int*>(elem + 8);
        if (!Sfr31DispBelongsTo(elem, def))
            ++i;
        else if (arr[1] == 1)
            reinterpret_cast<Scaleform::Sfr19RolloverData*>(arr)->Resize(0);
        else
        {
            FUN_14257dcd0(reinterpret_cast<void*>(elem));
            data = reinterpret_cast<UPInt*>(arr[0]);
            memmove(data + i, data + i + 1, (arr[1] - i) * 8 - 8);
            --arr[1];
        }
        FUN_14257dcd0(reinterpret_cast<void*>(elem));
    }
}

// MovieRoot: a Loader's content goes away (unload): the content gets its unload event, the loaded movie definition is unregistered when
// its last user left (the objects, listeners, timers, fonts and root display objects of it are dropped too when asked to) and the
// text format caches are flushed.
// MS2-FUNCTIONAL 0x1425305f0: SDK 4.2 shape (SPtr loaderInfo/content, Ptr defimpl, typed LoadedMovieDefs/event-chain hashes);
// the exe inlines RemoveLoadedMovieDef as a bool and keeps this in r12, so registers and the frame (0x90 vs 0x80) still differ
// @0x1425305f0
void MovieRoot::UnloadMovie(Instances::fl_display::Loader* ploader, bool dropAll, bool flagRoot)
{
    typedef Instances::fl_display::LoaderInfo LoaderInfo;
    SPtr<LoaderInfo> li = reinterpret_cast<LoaderInfo*>(FUN_142443d90(reinterpret_cast<UPInt>(ploader)));
    SPtr<DisplayObject> cd;
    if (li)
    {
        cd = li->GetContentDispObj();
        SPtr<Instances::fl_events::Event> ev = li->CreateEventObject(ASString(reinterpret_cast<ASStringManager*>(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x348))->CreateConstStringNode("unload", 6, 0)), false, false);
        li->DispatchEventObject(ev.GetPtr(), li->GetContentDispObj());
    }
    ploader->ResetContent();
    for (UPInt n = Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x10), 0x34a0); n != 0; n = Sfr31Rd(n, 8))
        if (Sfr31Rd(Sfr31Rd(n, 0x20), 0x28) == reinterpret_cast<UPInt>(ploader))
            *reinterpret_cast<UByte*>(Sfr31Rd(n, 0x20) + 0x25) = 1;
    for (UPInt n = Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x10), 0x20); n != 0; n = Sfr31Rd(n, 8))
        if (Sfr31Rd(n, 0x28) == reinterpret_cast<UPInt>(ploader))
            *reinterpret_cast<UByte*>(n + 0x25) = 1;
    const UPInt owner = Sfr31Rd(reinterpret_cast<UPInt>(ploader), 0x58);
    if (!cd && owner != 0 && *reinterpret_cast<const UInt32*>(owner + 0xe0) > 0)
        cd = reinterpret_cast<DisplayObject*>(FUN_1425fc530(owner, 0));
    if (cd)
    {
        const UPInt cur = reinterpret_cast<UPInt>(cd.GetPtr());
        typedef void (*VFn)(UPInt);
        typedef UPInt (*VFnR)(UPInt);
        cd->OnEventUnload();
        cd->ForceShutdown();
        Ptr<MovieDefImpl> defimpl = cd->GetResourceMovieDef();
        const UPInt def = reinterpret_cast<UPInt>(defimpl.GetPtr());
        if (defimpl)
        {
            typedef HashSetBase<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF, MS2_LoadedMovieDefNode::NodeAltHashF,
                                AllocatorLH<GFx::MovieDefImpl*, 2>, MS2_LoadedMovieDefEntry> LoadedSet;
            LoadedSet* set = reinterpret_cast<LoadedSet*>(reinterpret_cast<UPInt>(this) + 0x6e8);
            MovieDefImpl* const key = reinterpret_cast<MovieDefImpl*>(def);
            bool last = false;
            unsigned* pcnt = static_cast<unsigned*>(FUN_1425059f0(set, &def));
            if (pcnt && --pcnt[2] == 0)
            {
                set->RemoveAlt(key);
                last = true;
            }
            if (dropAll && last)
            {
                // objects registered per movie definition: drop the ones that belong to def
                typedef ArrayLH<WeakPtr<DisplayObject>, 2> Chain;
                typedef HashNode<int, AutoPtr<Chain>, IdentityHash<int> > ChainNode;
                typedef HashSetBase<ChainNode, ChainNode::NodeHashF, ChainNode::NodeAltHashF, AllocatorLH<int, 2>,
                                    HashsetNodeEntry<ChainNode, ChainNode::NodeHashF> > ChainHash;
                ChainHash& chains = *reinterpret_cast<ChainHash*>(reinterpret_cast<UPInt>(this) + 0x150);
                for (ChainHash::Iterator iter = chains.Begin(); iter != chains.End(); ++iter)
                {
                    Chain* chain = iter->Second.GetPtr();
                    if (chain)
                    {
                        for (UPInt i = 0; i < chain->GetSize(); )
                        {
                            Ptr<DisplayObject> dob = (*chain)[i];
                            if (dob)
                            {
                                typedef UPInt (*ResFn)(UPInt);
                                const UPInt d = reinterpret_cast<UPInt>(dob.GetPtr());
                                if (dob->GetResourceMovieDef() == defimpl)
                                {
                                    FUN_1425224f0(reinterpret_cast<UPInt*>(chain), i);
                                    continue;
                                }
                            }
                            ++i;
                        }
                    }
                }
                const UPInt stage = Sfr31Rd(reinterpret_cast<UPInt>(this), 0x158);
                UPInt disp = 0;
                if (stage != 0)
                {
                    const UPInt sub = stage + *reinterpret_cast<const UByte*>(stage + 0x6d) * 4;
                    typedef UPInt (*GetAvmFn)(UPInt);
                    const UPInt avm = reinterpret_cast<GetAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 0x28))(sub);
                    if (avm != 0)
                    {
                        disp = Sfr31Rd(avm - 0x30, 0);
                        if (disp == 0)
                            disp = Sfr31Rd(avm - 0x38, 0);
                        if (disp & 1)
                            disp -= 1;
                    }
                }
                if (disp != 0)
                    reinterpret_cast<Instances::fl_events::EventDispatcher*>(disp)->RemoveListenersForMovieDef(reinterpret_cast<MovieDefImpl*>(def));
                reinterpret_cast<MovieImpl*>(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x10))->ShutdownTimersForMovieDef(reinterpret_cast<MovieDefImpl*>(def));
                reinterpret_cast<MovieImpl*>(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x10))->UnregisterFonts(reinterpret_cast<MovieDefImpl*>(def));
                for (int g = 0; g < 4; ++g)
                {
                    const UPInt base = reinterpret_cast<UPInt>(this) + 0x360 + g * 0xe0;
                    Sfr31DropDispOfDef(reinterpret_cast<UPInt*>(base), def);
                    const UPInt single = Sfr31Rd(base, 0x18);
                    if (single != 0 && Sfr31DispBelongsTo(single, def))
                    {
                        FUN_14257dcd0(reinterpret_cast<void*>(single));
                        Sfr31Wr(base, 0x18, 0);
                    }
                }
            }
        }
        // the display object part of cur gives up its AS3 object
        const UPInt sub = cur + *reinterpret_cast<const UByte*>(cur + 0x6d) * 4;
        Sfr31Wr(sub, 0x10, Sfr31DispAvmPeek(cur));
        const UPInt held = Sfr31Rd(sub, 8);
        if (held != 0)
        {
            if ((held & 1) == 0 && (*reinterpret_cast<UInt32*>(held + 0x10) & 0x3fffff) != 0)
            {
                --*reinterpret_cast<UInt32*>(held + 0x10);
                FUN_1423dfa20(reinterpret_cast<void*>(held));
            }
            Sfr31Wr(sub, 8, 0);
        }
        if (owner != 0)
        {
            reinterpret_cast<DisplayList*>(owner + 0xd8)->Clear(reinterpret_cast<DisplayObjectBase*>(owner));
            FUN_1425f4090(reinterpret_cast<void*>(owner));
        }
    }
    if (flagRoot)
        *reinterpret_cast<UByte*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x48), 0x18) + 0xb0) = 1;
    if (Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x40), 0x28))
    {
        reinterpret_cast<Render::Text::Allocator*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x40), 0x28))->FlushTextFormatCache(false);
        reinterpret_cast<Render::Text::Allocator*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(this), 0x40), 0x28))->FlushParagraphFormatCache(false);
    }
}
// ---- batch 77
static inline double Sfr31DblAt(const unsigned char* base, UPInt off) { return *reinterpret_cast<const double*>(base + off); }
static inline bool Sfr31NotNaN(double v) { return v == v; }

// Wraps an angle in degrees into (-180, 180].
static inline double Sfr31WrapDeg(double v)
{
    const double m = fmod(v, 360.0);
    if (m <= 180.0)
        return m < -180.0 ? m + 360.0 : m;
    return m - 360.0;
}

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// AS3ValueObjectInterface::SetDisplayInfo (vftable slot 20): applies the fields of a DisplayInfo to the display object of
// an AS3 DisplayObject node (pdata). The exe calls it through the vftable (this=rcx, pdata=rdx, info=r8).
// MS2-FUNCTIONAL 0x142526730: same field order and twips rounding; the text rect space DisplayInfo scratch and the stale-value paths use NaN
// @0x142526730
bool AS3ValueObjectInterface::SetDisplayInfo(void* pdata, const Value::DisplayInfo& info)
{
    using namespace AS3;
    const UPInt node = reinterpret_cast<UPInt>(pdata);
    const unsigned char* d = reinterpret_cast<const unsigned char*>(&info);
    const UPInt traits = Sfr31Rd(node, 0x20);
    if (*reinterpret_cast<const UInt32*>(traits + 0x70) - 0x11u > 0xb || ((*reinterpret_cast<const UByte*>(traits + 0x68) >> 5) & 1) != 0)
        return false;
    const UPInt self = Sfr31Rd(node, 0x58);
    void* const dob = reinterpret_cast<void*>(self);
    const UPInt vt = Sfr31Rd(self, 0);
    typedef UPInt (*VfPtr)(void*);
    typedef void (*VfVoid)(void*);
    typedef void (*VfPtrArg)(void*, const void*);
    typedef void (*VfInt)(void*, int);
    typedef double (*VfDbl)(void*);
    typedef void (*VfDblArg)(void*, double);
    const bool notText = static_cast<int>(reinterpret_cast<VfPtr>(Sfr31Rd(vt, 0x258))(dob)) != 4;
    bool changed = false;
    UInt16 f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    const double nan = FUN_1425e3ee0();
    if ((f >> 14) & 1)
        FUN_14261d270(reinterpret_cast<void*>(FUN_1425f26c0(dob)), *reinterpret_cast<const int*>(d + 0xd0));
    const double alpha = Sfr31DblAt(d, 0x28);
    if (((f >> 5) & 1) && Sfr31NotNaN(alpha))
    {
        alignas(16) UInt32 cx[8];   // a Cxform: SetCxform copies it with movaps
        memcpy(cx, FUN_1425f1d00(dob), sizeof(cx));
        *reinterpret_cast<float*>(cx + 3) = static_cast<float>(alpha / 100.0);
        FUN_1425f4060(dob, cx);
        reinterpret_cast<VfInt>(Sfr31Rd(vt, 0x188))(dob, 0);
    }
    f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    if ((f >> 6) & 1)
        reinterpret_cast<VfInt>(Sfr31Rd(vt, 0x1a0))(dob, d[0x30]);
    const UPInt data = Sfr31Rd(self, 0x50);
    f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    if ((f >> 7) & 1)
    {
        double z = Sfr31DblAt(d, 0x38) * 20.0;
        if (!Sfr31NotNaN(z) || z == HUGE_VAL || z == -HUGE_VAL)
            z = 0.0;
        double* slot = reinterpret_cast<double*>(data + 0x40);
        if (z != *slot)
        {
            *slot = z;
            changed = true;
        }
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if ((f >> 10) & 1)
    {
        double s = Sfr31DblAt(d, 0x50);
        if (!Sfr31NotNaN(s) || s == HUGE_VAL || s == -HUGE_VAL)
            s = 100.0;
        double* slot = reinterpret_cast<double*>(data + 0x48);
        if (*slot != s)
        {
            *slot = s;
            changed = true;
        }
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if (((f >> 8) & 1) && Sfr31DblAt(d, 0x40) != *reinterpret_cast<double*>(data + 0x50))
    {
        *reinterpret_cast<double*>(data + 0x50) = Sfr31WrapDeg(Sfr31DblAt(d, 0x40));
        changed = true;
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if (((f >> 9) & 1) && Sfr31DblAt(d, 0x48) != *reinterpret_cast<double*>(data + 0x58))
    {
        *reinterpret_cast<double*>(data + 0x58) = Sfr31WrapDeg(Sfr31DblAt(d, 0x48));
        changed = true;
    }
    if (changed)
        reinterpret_cast<VfVoid>(Sfr31Rd(vt, 0x58))(dob);
    if ((*reinterpret_cast<const UInt16*>(d + 0xd4) >> 11) & 1)
    {
        const double fov = Sfr31DblAt(d, 0x58);
        if (fov != reinterpret_cast<VfDbl>(Sfr31Rd(vt, 0x120))(dob))
            reinterpret_cast<VfDblArg>(Sfr31Rd(vt, 0x118))(dob, fmod(fov, 180.0));
    }
    f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    if ((f >> 12) & 1)
    {
        reinterpret_cast<VfPtrArg>(Sfr31Rd(vt, 0x38))(dob, d + 0x90);
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if ((f >> 13) & 1)
    {
        reinterpret_cast<VfPtrArg>(Sfr31Rd(vt, 0x48))(dob, d + 0x60);
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if ((f & 0x1f) == 0)
        return true;
    if (!notText)
    {
        *reinterpret_cast<UInt32*>(self + 0xfc) |= 0x2000;
        FUN_1425bc060(dob);
    }
    reinterpret_cast<VfInt>(Sfr31Rd(vt, 0x188))(dob, 0);
    const UPInt geom = Sfr31Rd(self, 0x50);   // reread: the calls above can allocate the geometry data (exe 0x142526b46)
    typedef const float* (*MatFn)(void*);
    alignas(16) float m[8];   // a Matrix2F (aligned like the exe frame slot)
    memcpy(m, reinterpret_cast<MatFn>(Sfr31Rd(vt, 0x10))(dob), sizeof(m));
    double x, y;
    if (notText || (f & 3) == 0)
    {
        x = (f & 1) ? Sfr31DblAt(d, 0) : nan;
        y = ((f >> 1) & 1) ? Sfr31DblAt(d, 8) : nan;
    }
    else
    {
        alignas(16) float tr[56] = {};
        FUN_1425be970(dob, tr, d);
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
        x = tr[0];
        y = tr[1];
    }
    int* const pd = reinterpret_cast<int*>(geom);
    if (f & 0x1c)
    {
        const double a = static_cast<float>(pd[0xc]);
        const double b = static_cast<float>(pd[8]);
        const double c = static_cast<float>(pd[0xd]);
        const double e = static_cast<float>(pd[9]);
        const double rot0 = atan2(a, b);
        const double sx0 = sqrt(b * b + a * a);
        const double sy0 = sqrt(e * e + c * c);
        double rad = *reinterpret_cast<double*>(pd + 6) * 3.141592653589793;
        double xs = *reinterpret_cast<double*>(pd + 2) / 100.0;
        double ys = *reinterpret_cast<double*>(pd + 4) / 100.0;
        const double rotIn = (f & 4) ? Sfr31DblAt(d, 0x10) : nan;
        if (Sfr31NotNaN(rotIn))
        {
            const double w = Sfr31WrapDeg(rotIn);
            *reinterpret_cast<double*>(pd + 6) = w;
            rad = w * 3.141592653589793;
        }
        double xdiv = sx0, ydiv = sy0;
        const double nx = ((*reinterpret_cast<const UInt16*>(d + 0xd4) >> 3) & 1) ? Sfr31DblAt(d, 0x18) / 100.0 : nan;
        if (nx != xs && Sfr31NotNaN(nx) && nx - nx == 0.0)
        {
            *reinterpret_cast<double*>(pd + 2) = Sfr31DblAt(d, 0x18);
            if (sx0 == 0.0 || nx > 1e16)
            {
                xs = 0.0;
                xdiv = 1.0;
            }
            else
                xs = nx;
        }
        const double ny = ((*reinterpret_cast<const UInt16*>(d + 0xd4) >> 4) & 1) ? Sfr31DblAt(d, 0x20) / 100.0 : nan;
        if (ny != ys && Sfr31NotNaN(ny) && ny - ny == 0.0)
        {
            *reinterpret_cast<double*>(pd + 4) = Sfr31DblAt(d, 0x20);
            if (sy0 == 0.0 || ny > 1e16)
            {
                ys = 0.0;
                ydiv = 1.0;
            }
            else
                ys = ny;
        }
        GFx::ASCharacter_MatrixScaleAndRotate2x2(*reinterpret_cast<Render::Matrix2F*>(m), static_cast<float>(xs / xdiv), static_cast<float>(ys / ydiv), static_cast<float>(rad / 180.0 - rot0));
    }
    // x/y hold the text rect space position on the text path (exe xmm11/xmm10, 0x142526edb).
    if (Sfr31NotNaN((f & 1) ? x : nan))
    {
        double v = (f & 1) ? x : nan;
        if (v == HUGE_VAL || v == -HUGE_VAL)
            v = 0.0;
        v = floor(v * 20.0);
        pd[0] = static_cast<int>(v);
        m[3] = static_cast<float>(static_cast<int>(v));
    }
    if (Sfr31NotNaN(((f >> 1) & 1) ? y : nan))
    {
        double v = ((f >> 1) & 1) ? y : nan;
        if (v == HUGE_VAL || v == -HUGE_VAL)
            v = 0.0;
        v = floor(v * 20.0);
        pd[1] = static_cast<int>(v);
        m[7] = static_cast<float>(static_cast<int>(v));
    }
    if (reinterpret_cast<const Render::Matrix2x4<float>*>(m)->IsValid())
    {
        if (reinterpret_cast<DisplayObjectBase*>(self)->Is3D())
            reinterpret_cast<VfVoid>(Sfr31Rd(vt, 0x58))(dob);
        else
            reinterpret_cast<VfPtrArg>(Sfr31Rd(vt, 0x18))(dob, m);
    }
    if (!notText)
    {
        if (f & 1)
        {
            double v = x * 20.0;
            v = v <= 0.0 ? v - 0.5 : v + 0.5;
            pd[0] = static_cast<int>(v);
        }
        if ((f >> 1) & 1)
        {
            double v = y * 20.0;
            v = v <= 0.0 ? v - 0.5 : v + 0.5;
            pd[1] = static_cast<int>(v);
        }
    }
    return true;
}

}} // namespace Scaleform::GFx
// Tracer::GetValueTraits (sfr_as3_18)
inline Scaleform::UPInt FUN_14250ff00(Scaleform::UPInt tracer, const Scaleform::GFx::AS3::Value& v, bool super_tr) { return reinterpret_cast<Scaleform::UPInt>(reinterpret_cast<const Scaleform::GFx::AS3::Tracer*>(tracer)->GetValueTraits(v, super_tr)); }
namespace Scaleform { namespace GFx { namespace AS3 {
// ---- batch 78

// The traits of a tracer value: kinds 8/9 carry them, undefined has the VM's Object-less default, and the builtin Class
// traits stand for Object.
static UPInt Sfr31TrTraitsOfVal(UPInt vmA, UInt32* v)
{
    const UInt32 k = v[0] & 0x1f;
    UPInt tr;
    if (k == 0)
        tr = Sfr31Rd(vmA, 0x278);
    else if (k == 8 || k == 9)
        tr = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    else
        tr = reinterpret_cast<UPInt>(&reinterpret_cast<VM*>(vmA)->GetValueTraits(*reinterpret_cast<const Value*>(v)));
    if (tr != 0 && tr == Sfr31Rd(vmA, 0x1f0))
        tr = Sfr31Rd(vmA, 0x1f8);
    return tr;
}

static void Sfr31TrPushTraits(UPInt state, UInt32 flags, UPInt traits)
{
    TrTraitsScratch t;
    t.w0 = flags;
    t.SetTraits(*reinterpret_cast<InstanceTraits::Traits*>(traits));
    reinterpret_cast<ArrayDH<Value>*>(state + 0x38)->PushBack(t.Get());
}

// Tracer::TraceCommonOp: per-opcode specialization of the ops that need no block structure: property get/set/call ops on
// names with a known fixed slot become slot or vtable accesses, the convert ops vanish for operands of the target type,
// getlocal/kill update the register model. Returns whether the original opcode was consumed.
// MS2-FUNCTIONAL 0x14252d100: raw-offset model; codegen differs from the exe
// @0x14252d100
char Sfr31TracerCommonOp(UPInt tracer, unsigned char op, UPInt* pos, UPInt state)
{
    const UInt8* code = reinterpret_cast<const UInt8*>(Sfr31Rd(tracer, 0x50));
    const UPInt link = TrAbcLink(tracer);
    const UPInt vmA = TrRd(link, 0x20);
    UInt8* const stk = reinterpret_cast<UInt8*>(Sfr31Rd(state, 0x38));
    UInt32* const top = reinterpret_cast<UInt32*>(stk + Sfr31Rd(state, 0x40) * 0x20 - 0x20);
    UPInt p;
    switch (op)
    {
    case 4:
    case 0x66:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        alignas(8) UInt8 R[0x70];
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0, vmA);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 8, state);
        *reinterpret_cast<int*>(R + 0x10) = 0;
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0x18, link);
        FUN_1424d8ec0(R + 0x20, link, reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx)));
        *reinterpret_cast<int*>(R + 0x10) += FUN_142520380(R, R + 0x20);
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x50));
        ++*reinterpret_cast<int*>(R + 0x10);
        const UPInt tr = FUN_14250ff00(tracer, *reinterpret_cast<const Value*>(R + 0x50), op == 4);
        const bool ok = FUN_1424f8b00(reinterpret_cast<void*>(tracer), op, reinterpret_cast<void*>(state),
                                      reinterpret_cast<const Traits*>(tr), reinterpret_cast<const Multiname*>(R + 0x20),
                                      static_cast<int>(idx));
        if (ok)
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        FUN_1424ded40(R);
        return ok;
    }
    case 5:
    case 0x61:
    case 0x68:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        alignas(8) UInt8 R[0x90];
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0, vmA);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 8, state);
        *reinterpret_cast<int*>(R + 0x10) = 0;
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x18));
        ++*reinterpret_cast<int*>(R + 0x10);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0x38, link);
        FUN_1424d8ec0(R + 0x40, link, reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx)));
        *reinterpret_cast<int*>(R + 0x10) += FUN_142520380(R, R + 0x40);
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x70));
        ++*reinterpret_cast<int*>(R + 0x10);
        const UPInt tr = FUN_14250ff00(tracer, *reinterpret_cast<const Value*>(R + 0x70), op == 5);
        UInt32* val = reinterpret_cast<UInt32*>(R + 0x18);
        const UPInt vt = Sfr31TrTraitsOfVal(vmA, val);
        const bool ok = FUN_1424f92f0(reinterpret_cast<void*>(tracer), op, reinterpret_cast<const Traits*>(tr),
                                      reinterpret_cast<void*>(vt), reinterpret_cast<const Multiname*>(R + 0x40),
                                      static_cast<int>(idx));
        if (ok)
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        FUN_1424dee30(R);
        return ok;
    }
    case 8:
    {
        const UInt32 reg = Abc::ReadU30<UInt8>(code, *pos);
        reinterpret_cast<State*>(state)->SetRegister(AbsoluteIndex(reg), Value::GetUndefined());
        *reinterpret_cast<UInt8*>(Sfr31Rd(state, 0x78) + (reg >> 3)) &= static_cast<UInt8>(~(1 << (reg & 7)));
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    }
    case 0x45:
    case 0x46:
    case 0x4c:
    case 0x4e:
    case 0x4f:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        const UInt32 argc = Abc::ReadU30<UInt8>(code, p);
        alignas(8) UInt8 R[0x198];
        FUN_1424d9640(R, reinterpret_cast<VM*>(vmA), reinterpret_cast<void*>(state), argc);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0x140, link);
        FUN_1424d8ec0(R + 0x148, link, reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx)));
        *reinterpret_cast<int*>(R + 0x10) += FUN_142520380(R, R + 0x148);
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x178));
        ++*reinterpret_cast<int*>(R + 0x10);
        const bool ok = FUN_1424f7540(reinterpret_cast<void*>(tracer), op, reinterpret_cast<void*>(state), R,
                                      static_cast<int>(idx));
        if (ok)
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        FUN_1424debc0(R);
        return ok;
    }
    case 0x4a:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        const UInt32 argc = Abc::ReadU30<UInt8>(code, p);
        alignas(8) UInt8 R[0x198];
        FUN_1424d9640(R, reinterpret_cast<VM*>(vmA), reinterpret_cast<void*>(state), argc);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0x140, link);
        FUN_1424d8ec0(R + 0x148, link, reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx)));
        *reinterpret_cast<int*>(R + 0x10) += FUN_142520380(R, R + 0x148);
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x178));
        ++*reinterpret_cast<int*>(R + 0x10);
        const UInt32 mnw = *reinterpret_cast<UInt32*>(R + 0x148);
        UInt32* obj = reinterpret_cast<UInt32*>(R + 0x178);
        const UPInt objPtr = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x10);
        bool generic = (mnw & 3) == 1 || ((mnw >> 2) & 1) != 0;
        bool done = false;
        if (!generic)
        {
            if (((obj[0] >> 10) & 1) == 0)
            {
                if (argc != 0)
                    generic = true;
                else
                {
                    const UPInt tr = Sfr31TrTraitsOfVal(vmA, obj);
                    UPInt slotInd = 0;
                    const SlotInfo* si = FindFixedSlot(*reinterpret_cast<VM*>(vmA), *reinterpret_cast<const Traits*>(tr),
                                                       *reinterpret_cast<const Multiname*>(R + 0x148), slotInd, 0);
                    if (!si)
                        generic = true;
                    else
                    {
                        FUN_14251fb90(reinterpret_cast<void*>(tracer), 0xb6, static_cast<SPInt>(static_cast<UInt32>(slotInd) + 1));
                        FUN_14251fb90(reinterpret_cast<void*>(tracer), 0x42, 0);
                        TrPopped res;
                        res.w0 = 0;
                        res.w1 = 0;
                        res.w2 = 0;
                        res.w3 = 0;
                        char okb[8];
                        const char* r = Scaleform::GFx::AS3::TR::Sfr33TRStateAccess19::PropType(reinterpret_cast<void*>(state), okb, reinterpret_cast<const void*>(tr),
                                                      si, res.Get());
                        if (*r == 0)
                        {
                            res.Get().~Value();
                            FUN_1424debc0(R);
                            return 0;
                        }
                        reinterpret_cast<ArrayDH<Value>*>(state + 0x38)->PushBack(res.Get());
                        res.Get().~Value();
                        done = true;
                    }
                }
            }
            else
            {
                const UInt32 k = obj[0] & 0x1f;
                UPInt it;
                if (k == 9)
                {
                    FUN_14251fb90(reinterpret_cast<void*>(tracer), 0x42, static_cast<SPInt>(argc));
                    it = Sfr31Rd(objPtr, 0xc0);
                    Sfr31TrPushTraits(state, 8, it);
                    done = true;
                }
                else if (k == 0xd)
                {
                    FUN_14251fb90(reinterpret_cast<void*>(tracer), 0x42, static_cast<SPInt>(argc));
                    it = Sfr31Rd(Sfr31Rd(objPtr, 0x20), 0xc0);
                    Sfr31TrPushTraits(state, 8, it);
                    done = true;
                }
                else
                    generic = true;
            }
        }
        if (generic)
        {
            FUN_14251fa10(reinterpret_cast<void*>(tracer), 0x4a, idx, argc);
            Sfr31TrPushTraits(state, 8, Sfr31Rd(Sfr31Rd(vmA, 0x1f8), 0xc0));
            done = true;
        }
        if (done)
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        FUN_1424debc0(R);
        return done;
    }
    case 0x5d:
    {
        p = *pos;
        const int idx = static_cast<int>(Abc::ReadU30<UInt8>(code, p));
        const UInt8 c = code[p];
        UPInt q = p + 1;
        const int r = FUN_14250c990(tracer, p);
        if (c == 'f')
        {
            Abc::ReadU30<UInt8>(code, q);
            if (FUN_1424f7cc0(tracer, reinterpret_cast<void*>(state), idx, true, r, true))
            {
                Sfr31TracerSkipOrigOpCode(tracer, pos, q);
                return 1;
            }
        }
        else if (FUN_1424f7cc0(tracer, reinterpret_cast<void*>(state), idx, false, r, true))
        {
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            return 1;
        }
    }
    // fall through: the plain find-property trace
    case 0x5e:
    case 0x60:
    {
        p = *pos;
        const int idx = static_cast<int>(Abc::ReadU30<UInt8>(code, p));
        if (FUN_1424f7cc0(tracer, reinterpret_cast<void*>(state), idx, op == 0x60, 2, false))
        {
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            return 1;
        }
        return 0;
    }
    case 0x62:
    {
        p = *pos;
        const UInt32 reg = Abc::ReadU30<UInt8>(code, p);
        return Sfr31TracerOptRegIncDec(tracer, pos, p, state, reg);
    }
    case 0xd0:
    case 0xd1:
    case 0xd2:
    case 0xd3:
        return Sfr31TracerOptRegIncDec(tracer, pos, *pos, state, op - 0xd0u);
    case 100:
    {
        const UInt8 c = code[*pos];
        p = *pos + 1;
        if (c == 'l')
        {
            Sfr31StatePushTyped(state);
            FUN_14251f930(reinterpret_cast<void*>(tracer), 0x6e);
            const UInt32 slot = Abc::ReadU30<UInt8>(code, p);
            Sfr31TraceGetSlot(reinterpret_cast<State*>(state), slot);
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            return 1;
        }
        if (c != '+')
            return 0;
        UPInt* posArr = reinterpret_cast<UPInt*>(tracer + 0x70);
        reinterpret_cast<Scaleform::Sfr19PosData*>(posArr)->Resize(posArr[1] + 1);
        reinterpret_cast<UPInt*>(posArr[0])[posArr[1] - 1] = p;
        const UInt8 d = code[p++];
        if (d == 'm')
        {
            FUN_14251f930(reinterpret_cast<void*>(tracer), 0x6f);
            Sfr31StatePushTyped(state);
            Sfr31StateSwapOp(state);
            const UInt32 slot = Abc::ReadU30<UInt8>(code, p);
            Sfr31TracePop2Note(reinterpret_cast<State*>(state), slot);
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            return 1;
        }
        reinterpret_cast<Scaleform::Sfr19PosData*>(posArr)->Resize(posArr[1] - 1);
        return 0;
    }
    case 0x70:
    case 0x85:
    {
        const UInt32 k = top[0] & 0x1f;
        if (op == 0x85 && k == 10)
            return 1;
        const UInt32 kk = k - 0xc;
        if ((kk > 3 || Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10) != 0) && !FUN_142514e10(tracer, top))
            return 0;
        int nn = 2;
        if (op == 0x85)
            nn = (kk < 4 ? (Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10) != 0 ? 1 : 0) : 1) + 1;
        FUN_1424f1e50(state, Sfr31Rd(Sfr31Rd(vmA, 0x230), 0xc0), nn);
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    }
    case 0x73:
        if (!FUN_142514c30(tracer, top))
            return 0;
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x74:
        if (!FUN_1425150c0(tracer, top))
            return 0;
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x75:
        if (!FUN_142514470(tracer, top))
            return 0;
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x76:
        if (!FUN_142514000(tracer, top))
            return 0;
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x80:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx));
        UInt8* const endp = stk + Sfr31Rd(state, 0x40) * 0x20;
        UInt32* const tv = reinterpret_cast<UInt32*>(endp - 0x20);
        const UPInt tr = Sfr31ResolveClassTraits(vmA, link, entry);
        if (tr == 0)
        {
            UPInt sv[2];
            FUN_142545310(Sfr31Rd(TrFile(tracer), 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8, sv);
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d7850(eb, 0x3f6, reinterpret_cast<void*>(vmA), reinterpret_cast<const char*>(sv[0]));
            reinterpret_cast<VM*>(vmA)->ThrowVerifyError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
            return 1;
        }
        const UPInt it = Sfr31Rd(tr, 0xc0);
        const UInt32 k = tv[0] & 0x1f;
        bool nullable = false;
        if (k == 0)
        {
            if (it != Sfr31Rd(Sfr31Rd(vmA, 0x1f0), 0xc0) && it != Sfr31Rd(Sfr31Rd(vmA, 0x220), 0xc0) &&
                it != Sfr31Rd(Sfr31Rd(vmA, 0x228), 0xc0) && it != Sfr31Rd(Sfr31Rd(vmA, 0x218), 0xc0) &&
                it != Sfr31Rd(Sfr31Rd(vmA, 0x210), 0xc0) && it != Sfr31Rd(vmA, 0x278) &&
                it != Sfr31Rd(Sfr31Rd(vmA, 0x230), 0xc0))
            {
                UPInt* posArr = reinterpret_cast<UPInt*>(tracer + 0x90);
                if (posArr[1] != 0)
                {
                    UPInt* ops = reinterpret_cast<UPInt*>(Sfr31Rd(tracer, 0x28));
                    UInt64* arr = reinterpret_cast<UInt64*>(ops[0]);
                    if (*reinterpret_cast<int*>(&arr[reinterpret_cast<UPInt*>(posArr[0])[posArr[1] - 1]]) == 0x21)
                    {
                        arr[ops[1] - 1] = 0x20;
                        FUN_1424f1e50(state, it, 1);
                        Sfr31TracerSkipOrigOpCode(tracer, pos, p);
                        return 1;
                    }
                }
            }
        }
        else if (k - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(tv), 0x10) == 0)
            nullable = true;
        if (!nullable && !Sfr31SetTraitsForValue(tracer, tv, tr))
        {
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            FUN_14251fb90(reinterpret_cast<void*>(tracer), 0x80, static_cast<SPInt>(idx));
            FUN_1424f1e50(state, it, 2);
            return 1;
        }
        int nt = FUN_1424eea80(tracer, it);
        if ((tv[0] & 0x1f) - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(tv), 0x10) == 0)
            nt = 1;
        FUN_1424f1e50(state, it, nt);
        Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        return 1;
    }
    case 0x82:
        if (FUN_142514c30(tracer, top) || FUN_1425150c0(tracer, top))
        {
            FUN_14251f930(reinterpret_cast<void*>(tracer), 0x75);
            if ((top[0] & 0x1f) - 2 > 1)
                FUN_1424f1e50(state, Sfr31Rd(Sfr31Rd(vmA, 0x218), 0xc0), 0);
            else
                reinterpret_cast<Value*>(top)->ToNumberValueInline();
            return 1;
        }
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x87:
    {
        TrPopped pv;
        FUN_14251cd30(reinterpret_cast<State*>(state), &pv.Get());
        const UInt32 k = pv.w0 & 0x1f;
        UPInt ct = pv.w2;
        if (k == 0xd)
            ct = Sfr31Rd(ct, 0x20);
        if ((k == 9 || k == 0xd) && ct != 0)
        {
            UInt32* t2 = reinterpret_cast<UInt32*>(stk + Sfr31Rd(state, 0x40) * 0x20 - 0x20);
            if (((t2[0] & 0x1f) - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(t2), 0x10) == 0) ||
                Sfr31SetTraitsForValue(tracer, t2, ct))
            {
                FUN_1424f9180(reinterpret_cast<void*>(tracer));
                Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
                FUN_1424f1e50(state, Sfr31Rd(ct, 0xc0), 2);
                pv.Get().~Value();
                return 1;
            }
        }
        reinterpret_cast<ArrayDH<Value>*>(state + 0x38)->PushBack(pv.Get());
        pv.Get().~Value();
        return 0;
    }
    case 0xa0:
    {
        TrPopped b;
        TrPopped a;
        FUN_14251cd30(reinterpret_cast<State*>(state), &b.Get());
        FUN_14251cd30(reinterpret_cast<State*>(state), &a.Get());
        const UPInt ta = Sfr31TrTraitsOfVal(vmA, reinterpret_cast<UInt32*>(&a));
        const UPInt tb = Sfr31TrTraitsOfVal(vmA, reinterpret_cast<UInt32*>(&b));
        const UPInt strT = Sfr31Rd(Sfr31Rd(vmA, 0x230), 0xc0);
        UInt32 flags = 8;
        UPInt owner;
        if (ta == strT || tb == strT)
        {
            FUN_14251f930(reinterpret_cast<void*>(tracer), 0xa0);
            owner = Sfr31Rd(vmA, 0x230);
            flags = 0x48;
        }
        else
        {
            bool number = false;
            if (FUN_142514470(tracer, &a) && FUN_142514470(tracer, &b))
            {
                FUN_14251f930(reinterpret_cast<void*>(tracer), 0x7c);
                number = true;
            }
            else if (code[*pos] == 0x75)
            {
                FUN_14251f930(reinterpret_cast<void*>(tracer), 0x9b);
                Sfr31TracerSkipOrigOpCode(tracer, pos, *pos + 1);
                number = true;
            }
            else if (FUN_142514c30(tracer, &a) && FUN_142514c30(tracer, &b))
            {
                FUN_14251f930(reinterpret_cast<void*>(tracer), 0x79);
                owner = Sfr31Rd(vmA, 0x220);
            }
            else
            {
                FUN_14251f930(reinterpret_cast<void*>(tracer), 0xa0);
                if (FUN_142514a80(tracer, reinterpret_cast<void*>(ta)) && FUN_142514a80(tracer, reinterpret_cast<void*>(tb)))
                    number = true;
                else
                {
                    owner = Sfr31Rd(vmA, 0x1f8);
                    flags = 0x48;
                }
            }
            if (number)
                owner = Sfr31Rd(vmA, 0x218);
        }
        Sfr31TrPushTraits(state, flags, Sfr31Rd(owner, 0xc0));
        a.Get().~Value();
        b.Get().~Value();
        return 1;
    }
    }
    return 0;
}
// ---- batch 79
static inline UPInt Sfr31VmTr(UPInt vmA, UPInt off) { return Sfr31Rd(Sfr31Rd(vmA, off), 0xc0); }

// The opcode table's operand class for the opcodes TR::State handles by default: 0 none, 1 one U30, 2 two U30, -1 unusable.
static int Sfr31StateOpClass(unsigned char op)
{
    switch (op)
    {
    case 0x02: case 0x22: case 0x3f: case 0x54: case 0x69: case 0x6b:
    case 0x79: case 0x7a: case 0x7b: case 0x7c: case 0x7d: case 0x7e: case 0x7f:
    case 0x98: case 0x99:
        return 0;
    case 0x0a: case 0x0b: case 0x33: case 0x34: case 0x67:
    case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f:
    case 0x9c: case 0x9d: case 0x9e: case 0x9f:
    case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xba: case 0xbb:
    case 0xbc: case 0xbd: case 0xbe: case 0xbf:
    case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce:
        return 1;
    default:
        return -1;
    }
}

static void Sfr31StateBadOp(UPInt vmA, const char* name)
{
    VM& vm = *reinterpret_cast<VM*>(vmA);
    vm.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), vm, name));
}

// TR::State::TraceOp: the opcodes of the tracer that are not common to every state. The stack and register effects are
// modeled by the per-opcode handlers; unusable opcodes raise a verify error naming them.
// MS2-FUNCTIONAL 0x14253d520: raw-offset model; dispatches to the recovered per-opcode handlers; codegen differs from the exe
// @0x14253d520
void Sfr31StateTraceOp(UPInt state, unsigned char op, UPInt* pos)
{
    State* const st = reinterpret_cast<State*>(state);
    const UPInt tracer = Sfr31Rd(state, 0);
    const UInt8* const code = reinterpret_cast<const UInt8*>(Sfr31Rd(tracer, 0x50));
    const UPInt vmA = TrVM(tracer);
    StV s(st);
    Sfr31Wr(state, 0x10, *pos - 1);
    FUN_14251f930(reinterpret_cast<void*>(tracer), op);
    switch (op)
    {
    case 3:
        FUN_14251ccc0(st, 1);
        return;
    case 4: case 5: case 0x45: case 0x46: case 0x4a: case 0x4c: case 0x4e: case 0x4f: case 0x61: case 0x66:
    case 0x77: case 0x78: case 0x80: case 0x82: case 0xa0:
        return;
    case 6:
        Sfr27TraceDxns(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 7:
        Sfr27TraceDxnsLate(st);
        return;
    case 8:
        st->KillRegister(static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 9:
        FUN_1424e6aa0(tracer, st, *pos - 1, 0, 1);
        FUN_14251cc80(tracer);
        return;
    case 0xc: case 0xd: case 0xe: case 0xf: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
    case 0x19: case 0x1a:
        Sfr27TraceIfCompare(st, reinterpret_cast<UInt64*>(pos), op);
        return;
    case 0x10:
        Sfr27TraceJump(st, reinterpret_cast<UInt64*>(pos));
        return;
    case 0x47:
        FUN_1424e6aa0(tracer, st, *pos, 1, 1);
        return;
    case 0x11: case 0x12:
        Sfr27TraceIfTrueFalse(st, reinterpret_cast<UInt64*>(pos), op);
        return;
    case 0x1b:
        Sfr27TraceLookupSwitch(st, reinterpret_cast<UInt64*>(pos));
        return;
    case 0x1c:
    {
        TrPopped p;
        FUN_14251cd30(st, &p.Get());
        reinterpret_cast<ArrayDH<Value>*>(state + 0x58)->PushBack(p.Get());
        p.Get().~Value();
        *reinterpret_cast<UInt32*>(Sfr31Rd(state, 0x58) + Sfr31Rd(state, 0x60) * 0x20 - 0x20) |= 0x100;
        return;
    }
    case 0x1d:
        FUN_1424201a0(reinterpret_cast<void*>(state + 0x58), reinterpret_cast<void*>(Sfr31Rd(state, 0x70)),
                      Sfr31Rd(state, 0x60) - 1);
        return;
    case 0x1e:
        Sfr31TraceOperandClassTraits(st);
        return;
    case 0x1f:
        Sfr27TracePop2PushInt(st);
        return;
    case 0x20:
        s.OpStack().PushBack(Value::GetNull());
        return;
    case 0x21:
        s.OpStack().PushBack(Value::GetUndefined());
        return;
    case 0x23:
        Sfr27TracePop2PushObject(st);
        return;
    case 0x24:
    {
        const UInt32 b = code[*pos];
        ++*pos;
        st->PushByte(b);
        return;
    }
    case 0x25:
        st->PushShort(Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x26:
    case 0x27:
    {
        const bool b = op == 0x26;
        TrScratch t(b);
        s.OpStack().PushBack(t.Get());
        return;
    }
    case 0x28:
    {
        TrNumScratch t(Value::kNumber);
        t.SetNumber(FUN_1425e3ee0());
        s.OpStack().PushBack(t.Get());
        return;
    }
    case 0x29:
        Sfr27TraceCheckNumericOp(st);
        return;
    case 0x2a:
        Sfr27TraceDup2Check(st);
        return;
    case 0x2b:
        Sfr31StateSwapOp(state);
        return;
    case 0x2c:
        Sfr31TracePushString(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x2d:
        st->PushInt(Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x2e:
        st->PushUInt(Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x2f:
        st->PushDouble(Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x30:
        st->PushScope();
        return;
    case 0x31:
        Sfr31StatePushPool(state, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x32:
    {
        const UInt32 a = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        const UInt32 b = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        FUN_14251fcd0(tracer, a);
        FUN_14251fcd0(tracer, b);
        TrTraitsScratch t;
        t.SetTraits(TrITraits(tracer, 0x210));
        s.OpStack().PushBack(t.Get());
        return;
    }
    case 0x35: Sfr31StateBadOp(vmA, "exec_li8"); return;
    case 0x36: Sfr31StateBadOp(vmA, "exec_li16"); return;
    case 0x37: Sfr31StateBadOp(vmA, "exec_li32"); return;
    case 0x38: Sfr31StateBadOp(vmA, "exec_lf32"); return;
    case 0x39: Sfr31StateBadOp(vmA, "exec_lf64"); return;
    case 0x3a: Sfr31StateBadOp(vmA, "exec_si8"); return;
    case 0x3b: Sfr31StateBadOp(vmA, "exec_si16"); return;
    case 0x3c: Sfr31StateBadOp(vmA, "exec_si32"); return;
    case 0x3d: Sfr31StateBadOp(vmA, "exec_sf32"); return;
    case 0x3e: Sfr31StateBadOp(vmA, "exec_sf64"); return;
    case 0x50: Sfr31StateBadOp(vmA, "exec_sxi1"); return;
    case 0x51: Sfr31StateBadOp(vmA, "exec_sxi8"); return;
    case 0x52: Sfr31StateBadOp(vmA, "exec_sxi16"); return;
    case 0x40:
        st->PushFunction(static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x41:
        Sfr31TraceTraitsOfSecond(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x42:
        Sfr31TraceTypeOperand(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x43:
    case 0x44:
    {
        const UInt32 a = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        const UInt32 b = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        if (op == 0x43)
            Sfr31TraceCallPushObject(st, a, b);
        else
            Sfr31TraceCallPushObjectB(st, a, b);
        return;
    }
    case 0x48:
        FUN_14251ccc0(st, 1);
        FUN_1424e6aa0(tracer, st, *pos, 1, 1);
        return;
    case 0x49:
        Sfr31TraceCallPop(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x53:
        Sfr31TraceArgClassTraits(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x55:
        Sfr27TraceNewObject(st, Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x56:
        Sfr27TraceNewArray(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x57:
        Sfr31StatePushNs(state);
        return;
    case 0x58:
        Sfr31TraceClassTraitsFromIndex(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x59:
        Sfr31TraceGetDescendants(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x5a:
    case 0x60:
        st->PushObject(static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x5d:
        Sfr31TraceFindPropB(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x5e:
        Sfr31TraceFindPropA(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x62:
    {
        const UInt32 idx = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        FUN_14251fcd0(tracer, idx);
        s.OpStack().PushBack(*reinterpret_cast<const Value*>(Sfr31Rd(state, 0x18) + static_cast<UPInt>(idx) * 0x20));
        return;
    }
    case 0x63:
        st->SetLocalN(static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x64:
        Sfr31StatePushTyped(state);
        return;
    case 0x65:
    {
        const UInt32 idx = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        FUN_14251fcd0(tracer, idx);
        s.OpStack().PushBack(*reinterpret_cast<const Value*>(Sfr31Rd(state, 0x58) + static_cast<UPInt>(idx) * 0x20));
        *reinterpret_cast<UInt32*>(&s.Top()) &= 0xfffffeffu;
        return;
    }
    case 0x68:
        Sfr31TraceMnPop2(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x6a:
        Sfr31TraceMnPopPush(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x6c:
        Sfr31TraceGetSlot(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x6d:
        Sfr31TracePop2Note(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x6e:
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        s.OpStack().PushBack(Value::GetUndefined());
        return;
    case 0x6f:
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        FUN_14251ccc0(st, 1);
        return;
    case 0x70:
    case 0x95:
        st->TopString();
        return;
    case 0x85:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) != 10)
            st->TopString();
        return;
    case 0x71:
    case 0x72:
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x230), 0);
        return;
    case 0x73:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) < 5 || (*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) == 10)
        {
            Sfr27TraceConvertTopInt(st);
            return;
        }
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x220), 0);
        return;
    case 0x97:
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x220), 0);
        return;
    case 0x74:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) < 5 || (*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) == 10)
        {
            Sfr27TraceConvertTopUInt(st);
            return;
        }
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x228), 0);
        return;
    case 0x75:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) < 5 || (*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) == 10)
        {
            Sfr27TraceConvertTopNumber(st);
            return;
        }
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x218), 0);
        return;
    case 0x76:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) < 5 || (*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) == 10)
        {
            Sfr27TraceConvertTopBoolean(st);
            return;
        }
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x210), 0);
        return;
    case 0xb2:
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x210), 0);
        return;
    case 0x86:
        Sfr27TracePopNote(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x87:
    {
        TrPopped p;
        FUN_14251cd30(st, &p.Get());
        const UPInt pv = reinterpret_cast<UPInt>(&p.Get());
        const UInt32 k = *reinterpret_cast<const UInt32*>(pv) & 0x1f;
        UPInt tr = Sfr31Rd(pv, 0x10);
        if (k == 9)
            tr = Sfr31Rd(tr, 0xc0);
        else if (k == 0xd)
            tr = Sfr31Rd(Sfr31Rd(tr, 0x20), 0xc0);
        else if (k != 8)
            tr = 0;
        if (tr != 0)
        {
            if (FUN_142514a80(tracer, reinterpret_cast<void*>(tr)))
                tr = Sfr31VmTr(vmA, 0x1f8);
            FUN_1424f1e50(state, tr, 2);
        }
        p.Get().~Value();
        return;
    }
    case 0x90: TR::Sfr33TRStateAccess19::Stack1(state, Sfr31VmTr(vmA, 0x218), 0x54); return;
    case 0x91:
    case 0x93:
        st->TopNumber();
        return;
    case 0x92:
    case 0x94:
        FUN_1424f1ed0(state, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)), Sfr31VmTr(vmA, 0x218), 0);
        return;
    case 0x96: TR::Sfr33TRStateAccess19::Stack1(state, Sfr31VmTr(vmA, 0x210), 0x22); return;
    case 0x9b: TR::Sfr33TRStateAccess19::Stack2(state, Sfr31VmTr(vmA, 0x218), 0x7c); return;
    case 0xa1: TR::Sfr33TRStateAccess19::Stack2(state, Sfr31VmTr(vmA, 0x218), 0x7d); return;
    case 0xa2: TR::Sfr33TRStateAccess19::Stack2(state, Sfr31VmTr(vmA, 0x218), 0x7e); return;
    case 0xa3: TR::Sfr33TRStateAccess19::Stack2(state, Sfr31VmTr(vmA, 0x218), 0x7f); return;
    case 0xa4:
    case 0xa7:
    {
        TrPopped p;
        FUN_14251cd30(st, &p.Get());
        FUN_1424f1e50(state, Sfr31VmTr(vmA, op == 0xa4 ? 0x218 : 0x228), 0);
        p.Get().~Value();
        return;
    }
    case 0xa5: case 0xa6: case 0xa8: case 0xa9: case 0xaa:
        st->Pop2Int();
        return;
    case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: case 0xb0: case 0xb1: case 0xb3: case 0xb4:
        st->Pop2Boolean();
        return;
    case 0xc0: TR::Sfr33TRStateAccess19::Stack1(state, Sfr31VmTr(vmA, 0x220), 0x98); return;
    case 0xc1: TR::Sfr33TRStateAccess19::Stack1(state, Sfr31VmTr(vmA, 0x220), 0x99); return;
    case 0xc2:
        TR::Sfr33TRStateAccess19::Reg1(state, Sfr31VmTr(vmA, 0x220), 10, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0xc3:
        TR::Sfr33TRStateAccess19::Reg1(state, Sfr31VmTr(vmA, 0x220), 0xb, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0xc4: TR::Sfr33TRStateAccess19::Stack1(state, Sfr31VmTr(vmA, 0x220), 0x3f); return;
    case 0xc5: TR::Sfr33TRStateAccess19::Stack2(state, Sfr31VmTr(vmA, 0x220), 0x79); return;
    case 0xc6: TR::Sfr33TRStateAccess19::Stack2(state, Sfr31VmTr(vmA, 0x220), 0x7a); return;
    case 0xc7: TR::Sfr33TRStateAccess19::Stack2(state, Sfr31VmTr(vmA, 0x220), 0x7b); return;
    case 0xd0: case 0xd1: case 0xd2: case 0xd3:
        s.OpStack().PushBack(*reinterpret_cast<const Value*>(Sfr31Rd(state, 0x18) + static_cast<UPInt>(op - 0xd0) * 0x20));
        return;
    case 0xd4: st->SetLocal0(); return;
    case 0xd5: st->SetLocal1(); return;
    case 0xd6: st->SetLocal2(); return;
    case 0xd7: st->SetLocal3(); return;
    case 0xef:
    {
        FUN_14251fcd0(tracer, code[*pos]);
        ++*pos;
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        FUN_14251fcd0(tracer, code[*pos]);
        ++*pos;
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    }
    case 0xf0:
    case 0xf1:
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0xf2:
        Abc::ReadU30<UInt8>(code, *pos);
        return;
    default:
    {
        const int cls = Sfr31StateOpClass(op);
        if (cls == 0)
            return;
        if (cls == 1)
        {
            FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
            return;
        }
        static const char hex[] = "0123456789ABCDEF";
        char name[8] = { 'O', 'P', '_', '0', 'x', hex[op >> 4], hex[op & 15], 0 };
        Sfr31StateBadOp(vmA, name);
        return;
    }
    }
}
// ---- batch 80
// Pushes a new Instance of the traits found through the owner's name onto the VM's value stack (vm + 0x50 points at the top).
// Object(Traits&) / Instance(Traits&): the exe inlines both here (out of line in sfr_as3_15). The Instance copy
// is the tagged member template, so cl does not emit a second ??0Instance (LNK2005 with sfr_as3_15).
inline Object::Object(Traits& t)
    : GASRefCountBase(&t.GetVM().GetGC())
    , pTraits(&t)
    , pUserDataHolder(NULL)
{
}
struct Sfr31InstanceInlineTag {};
template <class Tag> __forceinline Instance::Instance(InstanceTraits::Traits& t, Tag)
    : Object(t)
{
    t.ConstructTail(*this);
}

// The inlined Instance ctor emits these vftables here (as sfr_as3_15/16 do).
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7GASRefCountBase@AS3@GFx@Scaleform@@6B@ 0x14313f398
// MS2-PIN: ??_7Object@AS3@GFx@Scaleform@@6B@ 0x14317b098
// MS2-PIN: ??_7Instance@AS3@GFx@Scaleform@@6B@ 0x14313f4d8
// @0x14253bef0
void Sfr31PushNewInstanceOfOwner(UPInt vm, UPInt own)
{
    UPInt tr;
    {
        ASString name(reinterpret_cast<ASStringNode*>(Sfr31Rd(own, 0x70)));
        const UPInt link = Sfr31Rd(own, 0x28);
        tr = FUN_142506f00(link, *reinterpret_cast<const UPInt*>(Sfr31Rd(Sfr31Rd(link, 0x28), 0x170) + static_cast<SPInt>(*reinterpret_cast<const SInt32*>(own + 0x30)) * 8), &name);
    }
    InstanceTraits::Traits& traits = *reinterpret_cast<InstanceTraits::Traits*>(tr);
    struct A { static __forceinline void* Alloc(const InstanceTraits::Traits& t)
    {
        AllocInfo info(StatMV_VM_Instance_Mem, NULL, 0);
        return t.GetVM().GetMemoryHeap()->Alloc(t.GetMemSize(), &info);
    } };
    void* mem = A::Alloc(traits);
    Instance* obj = mem != NULL ? new (mem) Instance(traits, Sfr31InstanceInlineTag()) : NULL;
    Value v;
    ValueAssignCopies::PickUnsafeObject19(v, obj);
    const UPInt top = Sfr31Rd(vm, 0x50) + 0x20;
    Sfr31Wr(vm, 0x50, top);
    new (reinterpret_cast<void*>(top)) Value(v);
}
// ---- batch 81
// The AVM flavor of a SetVariable value waiting for its target (0x40 bytes; the base lives in the player unit).
struct Sfr31AvmStickyVarNode
{
    const void* const* VTbl;    // +0x00 two slots: scalar deleting destructor, Assign (a function table kept here, not a C++ vftable)
    ASString Name;              // +0x08
    void*    pNext;             // +0x10
    bool     Permanent;         // +0x18
    Value    Val;               // +0x20
};

static void* Sfr31AvmStickyDelete(Sfr31AvmStickyVarNode* n, unsigned flags)
{
    n->Val.~Value();
    n->Name.~ASString();
    if (flags & 1)
        SF_FREE(n);
    return n;
}

static void Sfr31AvmStickyAssign(Sfr31AvmStickyVarNode* n, const Sfr31AvmStickyVarNode* o)
{
    n->Name = o->Name;
    n->Permanent = o->Permanent;
    n->Val = o->Val;
}

static const void* const Sfr31AvmStickyTable[2] = { reinterpret_cast<const void*>(&Sfr31AvmStickyDelete),
                                                    reinterpret_cast<const void*>(&Sfr31AvmStickyAssign) };

// SF_Std.h SFstrrchr
static SF_FORCEINLINE const char* Sfr31Strrchr(const char* str, char c)
{
    UPInt len = strlen(str);
    for (UPInt i = len; i > 0; i--)
        if (str[i] == c)
            return str + i;
    return 0;   // the exe build has no str[0] test
}

// MovieRoot::ExtractPathAndName, inlined into SetVariable in the exe
static SF_FORCEINLINE bool Sfr31ExtractPathAndName(UPInt root, const char* fullPath, ASString* ppath, ASString* pname)
{
    int colonIndex = -1;
    const char* p;
    if ((p = Sfr31Strrchr(fullPath, '.')) != 0)
        colonIndex = int(p - fullPath);
    else
        return false;
    *pname = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateString(fullPath + colonIndex + 1);
    *ppath = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateString(fullPath, colonIndex);
    return true;
}

// Object vftable view: slot 6 (+0x30) is SetProperty (CheckResult by sret); called as call [rax+0x30] like the exe
struct Sfr31SetPropHolder { virtual void S0()=0; virtual void S1()=0; virtual void S2()=0; virtual void S3()=0; virtual void S4()=0; virtual void S5()=0;
                            virtual CheckResult SetProp(const Multiname&, const Value&) = 0; };
// MovieRoot::SetVariable: sets the member after the last '.' of the path on the object the rest of the path resolves to
// ("root" when there is no dot). setType 1 keeps the value for a target that does not exist yet, 2 keeps it permanently.
// MS2-FUNCTIONAL 0x14252a700: frame slot only. Same length and op-for-op; the exe keeps the target ASString in the +0x10 home slot, ours at rbp-0x79, so 81 bytes of slot offsets differ.
// @0x14252a700
char Sfr31MovieRootSetVariable(UPInt root, const char* path, const void* gfxValue, int setType)
{
    ASString target(reinterpret_cast<ASStringNode*>(Sfr31Rd(root, 0x160)));   // builtin empty string
    ASString member(reinterpret_cast<ASStringNode*>(Sfr31Rd(root, 0x160)));
    if (!Sfr31ExtractPathAndName(root, path, &target, &member))
    {
        member = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateString(path);
        target = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateString("root");
    }
    Value targetVal;
    if (!FUN_142506000(root, &targetVal, reinterpret_cast<UPInt>(target.ToCStr())))
        return 0;

    Multiname mn(*reinterpret_cast<Instances::Namespace*>(Sfr31Rd(Sfr31Rd(root, 0x48), 0x1d0)), Value(member, Value::InlineStr),
                 Multiname::InlineAssignTag());

    Value converted;
    FUN_1425048d0(root, gfxValue, &converted);
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(&targetVal), 0x10);
    char result = reinterpret_cast<Sfr31SetPropHolder*>(obj)->SetProp(mn, converted);
    if (((result == 0 && setType != 0) || setType == 2) && member.GetSize() != 0)
    {
        // SDK: SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) StickyVarNode(name, v, permanent), added when the allocation worked
        MovieRoot::StickyVarNode* pnode = SF_HEAP_NEW(reinterpret_cast<MovieImpl*>(Sfr31Rd(root, 0x10))->GetMovieHeap())
            MovieRoot::StickyVarNode(member, converted, setType == 2);
        if (pnode)
            reinterpret_cast<MovieImpl*>(Sfr31Rd(root, 0x10))->AddStickyVariableNode(target, pnode);
    }
    const UPInt vm = Sfr31Rd(root, 0x48);
    if (*reinterpret_cast<const UByte*>(vm + 0x180) != 0)
    {
        *reinterpret_cast<UByte*>(vm + 0x180) = 0;
        FUN_14251bdc0(vm, reinterpret_cast<void*>(vm + 0x188));
        reinterpret_cast<Value*>(vm + 0x188)->SetUndefined();
    }
    return result;
}
}}} // namespace Scaleform::GFx::AS3

// INST-Reserve-BEGIN
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SlotContainerType::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SlotContainerType::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long const*,Scaleform::AllocatorDH<long const*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<double const*,Scaleform::AllocatorDH<double const*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object*,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH_POD<unsigned int,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State*,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State*,328>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::ClassInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::ClassInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MetadataInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
struct Sfr31Rec24 { Scaleform::UInt64 a, b, c; };
struct Sfr31Rec64 { Scaleform::UInt64 a[8]; };
template void Scaleform::ArrayDataBase<const Scaleform::UInt8*,Scaleform::AllocatorDH<const Scaleform::UInt8*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::ASStringNode*,Scaleform::AllocatorGH<Scaleform::GFx::ASStringNode*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::DisplayObject*,Scaleform::AllocatorGH<Scaleform::GFx::DisplayObject*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value*,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value*,331>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Sfr31Rec24,Scaleform::AllocatorLH<Sfr31Rec24,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Sfr31Rec64,Scaleform::AllocatorLH<Sfr31Rec64,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>,328>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// INST-Reserve-END

// INST-HashRaw-BEGIN
template void Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeHashF,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::UInt32,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode*,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase*,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::setRawCapacity(void*, Scaleform::UPInt);
// INST-HashRaw-END

// INST-Resize-BEGIN
template void Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> >::Resize(Scaleform::UPInt);
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::UInt8,Scaleform::AllocatorLH<Scaleform::UInt8,2>,Scaleform::ArrayDefaultPolicy> >::Resize(Scaleform::UPInt);
// INST-Resize-END

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
// Vtable-only virtuals present at the executable addresses below.
// @0x142525c90
void Scaleform::GFx::DisplayObjectBase::Restart() {}
// @0x142526720
void Scaleform::GFx::InteractiveObject::SetDisplayCallback(void (SF_CDECL* callback)(void*), void* userPtr)
{
    pDisplayCallback = callback;
    DisplayCallbackUserPtr = userPtr;
}
// @0x1425274a0
void Scaleform::GFx::AS3::IntervalTimer::SetId(int id) { Id = id; }
// @0x1425287f0
void Scaleform::GFx::InteractiveObject::SetPause(bool) {}
// @0x142528800
void Scaleform::GFx::InteractiveObject::SetPlayState(Scaleform::GFx::PlayState) {}
// @0x142528d90
void Scaleform::GFx::DisplayObjectBase::SetRatio(float) {}
// @0x142529f40
void Scaleform::GFx::DisplayObjectBase::SetStateChangeFlags(Scaleform::UByte) {}
// @0x142529f50
void Scaleform::GFx::InteractiveObject::SetStateChangeFlags(Scaleform::UByte flags)
{
    Flags = (Flags & 0xfff0ffffu) | ((static_cast<Scaleform::UInt32>(flags) & 0x0fu) << 16);
}
// @0x14252c8a0
void Scaleform::GFx::AS3::IntervalTimer::Start(Scaleform::GFx::MovieImpl* proot)
{
    const auto* movieBytes = reinterpret_cast<const unsigned char*>(proot);
    InvokeTime = *reinterpret_cast<const Scaleform::UInt64*>(movieBytes + 0x268) + Interval;
}
// @0x14252c9c0
void Scaleform::GFx::InteractiveObject::StopActiveSounds(Scaleform::GFx::ASSoundIntf*) {}
// @0x14252c9d0
void Scaleform::GFx::InteractiveObject::StopActiveSounds(Scaleform::GFx::SoundResource*) {}
// @0x14252c9e0
void Scaleform::GFx::InteractiveObject::StopActiveSounds() {}
// @0x14252e520
bool Scaleform::GFx::AS3::InstanceTraits::Traits::SupportsInterface(const Scaleform::GFx::AS3::InstanceTraits::Traits&) const { return false; }
// @0x14252fee0
Scaleform::GFx::AS3::CheckResult Scaleform::GFx::AS3::XMLSupport::ToXMLString(Scaleform::GFx::AS3::VM&, Scaleform::GFx::AS3::Value&) const
{
    return Scaleform::GFx::AS3::CheckResult(false);
}
// @0x142540ba0
void Scaleform::GFx::AS3::Class::lengthGet(Scaleform::SInt32& result)
{
    result = *reinterpret_cast<const Scaleform::SInt32*>(reinterpret_cast<const unsigned char*>(this) + 0x40);
}

// MS2-PIN: ?SetUInt32@Value@AS3@GFx@Scaleform@@QEAAXK@Z 0x14252a460

// The out-of-line array COMDATs of this range, on the real element types (header templates, so attributed by
// byte match or MS2-PIN rather than by tag).
namespace Scaleform {
// The exe calls the Value range destructor out of line from the ResizeNoConstruct bodies (0x1424f6d50, sfr_as3_17).
extern template void ConstructorMov<GFx::AS3::Value>::DestructArray(GFx::AS3::Value*, UPInt);
template void ArrayDataBase<GFx::AS3::Value, AllocatorGH<GFx::AS3::Value, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524e20
template void ArrayDataBase<GFx::AS3::Value, AllocatorLH<GFx::AS3::Value, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524ec0
template void ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524cd0
template void ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, Stat_Default_Mem>, ArrayDefaultPolicy>::Reserve(const void* pheapAddr, UPInt newCapacity);   // 0x142523990
template void ArrayDataBase<Ptr<GFx::InteractiveObject>, AllocatorDH<Ptr<GFx::InteractiveObject>, GFx::StatMV_Other_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524990
template void ArrayDataBase<GFx::AS3::SPtr<GFx::ASStringNode>, AllocatorLH<GFx::AS3::SPtr<GFx::ASStringNode>, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524a30
template void ArrayData<ArrayLH_POD<UPInt, GFx::AS3::StatMV_VM_AbcFile_Mem>, AllocatorLH<ArrayLH_POD<UPInt, GFx::AS3::StatMV_VM_AbcFile_Mem>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x1425244e0
template void ArrayData<GFx::AS3::Abc::MethodBodyInfo::Exception, AllocatorLH<GFx::AS3::Abc::MethodBodyInfo::Exception, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x142524710
template void ArrayDataBase<GFx::AS3::Abc::MethodBodyInfo::Exception, AllocatorLH<GFx::AS3::Abc::MethodBodyInfo::Exception, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::Reserve(const void* pheapAddr, UPInt newCapacity);   // 0x142523b70
// Out of line in the exe (ICF-folded with the SPtr<const Namespace> instance at 0x1424f6c90, sfr_as3_17).
template <> void ConstructorMov<GFx::AS3::SPtr<GFx::AS3::NamespaceSet> >::DestructArray(GFx::AS3::SPtr<GFx::AS3::NamespaceSet>* p, UPInt count);
template void ArrayData<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, Stat_Default_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x142524680
}
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@VValue@AS3@GFx@Scaleform@@U?$AllocatorGH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142524e20
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@VValue@AS3@GFx@Scaleform@@U?$AllocatorLH@VValue@AS3@GFx@Scaleform@@$0BEL@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142524ec0
// MS2-PIN: ?Resize@?$ArrayData@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x142524680
// MS2-PIN: ?Reserve@?$ArrayDataBase@UException@MethodBodyInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH@UException@MethodBodyInfo@Abc@AS3@GFx@Scaleform@@$0BFE@@6@UArrayDefaultPolicy@6@@Scaleform@@QEAAXPEBX_K@Z 0x142523b70
namespace Scaleform {
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, Stat_Default_Mem>, ArrayDefaultPolicy>::Reserve(const void* pheapAddr, UPInt newCapacity);   // 0x142523850
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524b90 (MovieRoot::AbcFiles)
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524c30 (VMAbcFile::Children)
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524af0 (VMAbcFile::LoadedClasses)
// The sf_array.h body, not inlined into the NamesT Resize below (the exe calls it there).
template <> SF_NOINLINE void ArrayDataBase<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize)   // 0x142524d80
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
template void ArrayDataCC<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x142524470 (VTable::NamesT)
template void ArrayData<Ptr<GFx::InteractiveObject>, AllocatorLH<Ptr<GFx::InteractiveObject>, GFx::AS3::StatMV_ActionScript_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x1425245c0 (RolloverStack)
template void ArrayData<UPInt, AllocatorLH_POD<UPInt, GFx::AS3::StatMV_VM_AbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x1425247f0
template void ArrayDataDH<UPInt, AllocatorDH_POD<UPInt, GFx::AS3::StatMV_VM>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x142524870 (Tracer TCodeOffset arrays)
template void ArrayDataBase<GFx::Button::CharToRec, AllocatorLH<GFx::Button::CharToRec, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x1425248e0 (Button::StateCharArray)
}
// MS2-PIN: ?Resize@?$ArrayDataCC@VASString@GFx@Scaleform@@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEL@@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAX_K@Z 0x142524470

// The out-of-line HashSetBase::setRawCapacity COMDATs of this range, on the node/allocator/entry types of the add
// instances in sfr_as3_15 (the same typedefs, repeated here).
namespace Scaleform {
template<class N, class A, class E>
struct MS2_HashSetOf
{
    typedef HashSetBase<N, typename N::NodeHashF, typename N::NodeAltHashF, A, E> Type;
};
typedef HashSetBase<const void*, FixedSizeHash<const void*>, FixedSizeHash<const void*>, AllocatorGH<const void*, 2>,
                    HashsetCachedEntry<const void*, FixedSizeHash<const void*> > > MS2_ObjPtrSet;
typedef HashNode<int, AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2> >, IdentityHash<int> > MS2_DepthToObjsNode;
typedef MS2_HashSetOf<MS2_DepthToObjsNode, AllocatorLH<int, 2>,
                      HashsetNodeEntry<MS2_DepthToObjsNode, MS2_DepthToObjsNode::NodeHashF> >::Type MS2_DepthToObjsSet;
struct MS2_SlotPos
{
    SPInt       Ind;
    const void* pSlots;

    MS2_SlotPos(const MS2_SlotPos& other) : Ind(other.Ind), pSlots(other.pSlots) {}
    MS2_SlotPos& operator=(const MS2_SlotPos& other)
    {
        Ind    = other.Ind;
        pSlots = other.pSlots;
        return *this;
    }
};
typedef HashNode<UInt32, MS2_SlotPos, FixedSizeHash<UInt32> > MS2_SlotPosNode;
typedef MS2_HashSetOf<MS2_SlotPosNode, AllocatorDH<UInt32, 2>,
                      HashsetCachedNodeEntry<MS2_SlotPosNode, MS2_SlotPosNode::NodeHashF> >::Type MS2_SlotPosSet;
typedef HashNode<UInt32, GFx::AS3::SPtr<GFx::AS3::InstanceTraits::Function>, FixedSizeHash<UInt32> > MS2_FunctionTraitsNode;
typedef MS2_HashSetOf<MS2_FunctionTraitsNode, AllocatorLH<UInt32, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_FunctionTraitsNode, MS2_FunctionTraitsNode::NodeHashF> >::Type
    MS2_FunctionTraitsSet;
typedef HashNode<GFx::AS3::GASRefCountBase*, GFx::AS3::WeakProxy*, FixedSizeHash<GFx::AS3::GASRefCountBase*> > MS2_WeakProxyNode;
typedef MS2_HashSetOf<MS2_WeakProxyNode, AllocatorGH<GFx::AS3::GASRefCountBase*, 2>,
                      HashsetCachedNodeEntry<MS2_WeakProxyNode, MS2_WeakProxyNode::NodeHashF> >::Type MS2_WeakProxySet;
// (MS2_LoadedMovieDefInfo and MS2_LoadedMovieDefNode are declared at the top, with the entry copy ctor.)
//
//
//
//
//
//
//
typedef MS2_HashSetOf<MS2_LoadedMovieDefNode, AllocatorLH<GFx::MovieDefImpl*, 2>,
                      HashsetNodeEntry<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF> >::Type
    MS2_LoadedMovieDefSet;
typedef HashNode<const GFx::AS3::Abc::MethodBodyInfo*, GFx::AS3::SPtr<GFx::AS3::InstanceTraits::Traits>,
                 FixedSizeHash<const GFx::AS3::Abc::MethodBodyInfo*> > MS2_ActivationTraitsNode;
typedef MS2_HashSetOf<MS2_ActivationTraitsNode, AllocatorLH<const GFx::AS3::Abc::MethodBodyInfo*, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_ActivationTraitsNode, MS2_ActivationTraitsNode::NodeHashF> >::Type
    MS2_ActivationTraitsSet;
typedef GFx::AS3::AbcMultinameHash<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace> >::Key MS2_AbcNsKey;
typedef HashNode<MS2_AbcNsKey, GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>, FixedSizeHash<MS2_AbcNsKey> > MS2_AbcNsNode;
typedef MS2_HashSetOf<MS2_AbcNsNode, AllocatorLH<MS2_AbcNsKey, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_AbcNsNode, MS2_AbcNsNode::NodeHashF> >::Type MS2_AbcNsSet;
typedef HashNode<GFx::ASString, GFx::AS3::Value, GFx::ASStringHashFunctor> MS2_StringValueNode;
typedef MS2_HashSetOf<MS2_StringValueNode, AllocatorLH<GFx::ASString, GFx::StatMV_ASString_Mem>,
                      HashsetNodeEntry<MS2_StringValueNode, MS2_StringValueNode::NodeHashF> >::Type MS2_StringValueSet;
// The entry's node destructor is the out-of-line 0x1424dcb40 in the exe.
template<> inline void HashsetNodeEntry<MS2_StringValueNode, MS2_StringValueNode::NodeHashF>::Clear()
{
    FUN_1424dcb40(&Value);
    NextInChain = -2;
}
typedef GFx::AS3::SPtr<GFx::AS3::GASRefCountBase> MS2_GCRootPtr;
typedef HashSetBase<MS2_GCRootPtr, FixedSizeHash<MS2_GCRootPtr>, FixedSizeHash<MS2_GCRootPtr>, AllocatorLH<MS2_GCRootPtr, 2>,
                    HashsetCachedEntry<MS2_GCRootPtr, FixedSizeHash<MS2_GCRootPtr> > > MS2_GCRootSet;

extern template void MS2_ObjPtrSet::add<const void*>(void*, const void* const&, UPInt);
extern template void MS2_ObjPtrSet::Clear();
template<class T> struct MS2_SetValueOf;
template<class C, class H, class AH, class A, class E>
struct MS2_SetValueOf<HashSetBase<C, H, AH, A, E> >
{
    typedef C Type;
};
typedef decltype(GFx::AS3::Object::DynAttrsType::mHash)::BaseType MS2_DynAttrsSet;
typedef decltype(GFx::AS3::Slots::SetType::mHash)::BaseType MS2_SlotNameSet;
extern template void MS2_DepthToObjsSet::add<MS2_DepthToObjsNode>(void*, const MS2_DepthToObjsNode&, UPInt);
extern template void MS2_DepthToObjsSet::Clear();
extern template void MS2_SlotPosSet::add<MS2_SlotPosNode>(void*, const MS2_SlotPosNode&, UPInt);
extern template void MS2_FunctionTraitsSet::add<MS2_FunctionTraitsNode>(void*, const MS2_FunctionTraitsNode&, UPInt);
extern template void MS2_FunctionTraitsSet::Clear();
extern template void MS2_WeakProxySet::CheckExpand(void*);
extern template void MS2_LoadedMovieDefSet::add<MS2_LoadedMovieDefNode>(void*, const MS2_LoadedMovieDefNode&, UPInt);
extern template void MS2_ActivationTraitsSet::add<MS2_ActivationTraitsNode>(void*, const MS2_ActivationTraitsNode&, UPInt);
extern template void MS2_ActivationTraitsSet::Clear();
extern template void MS2_DynAttrsSet::CheckExpand(void*);
extern template void MS2_AbcNsSet::add<MS2_AbcNsNode>(void*, const MS2_AbcNsNode&, UPInt);
extern template void MS2_AbcNsSet::Clear();
extern template void MS2_SlotNameSet::add<MS2_SetValueOf<MS2_SlotNameSet>::Type>(void*, const MS2_SetValueOf<MS2_SlotNameSet>::Type&, UPInt);
extern template void MS2_SlotNameSet::Clear();
extern template void MS2_StringValueSet::add<MS2_StringValueNode>(void*, const MS2_StringValueNode&, UPInt);
extern template void MS2_GCRootSet::add<MS2_GCRootPtr>(void*, const MS2_GCRootPtr&, UPInt);
extern template void MS2_GCRootSet::Clear();
extern template MS2_FunctionTraitsSet::~HashSetBase();
extern template MS2_ActivationTraitsSet::~HashSetBase();
extern template MS2_AbcNsSet::~HashSetBase();
extern template MS2_GCRootSet::~HashSetBase();
extern template UPInt FixedSizeHash<MS2_AbcNsKey>::operator()(const MS2_AbcNsKey&) const;
template void MS2_ObjPtrSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142540c40
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@H$01@2@V?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142540e40
template void MS2_DepthToObjsSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142540e40
template void MS2_SlotPosSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142540fc0
template void MS2_FunctionTraitsSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142541170
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@PEAVGASRefCountBase@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425415a0
template void MS2_WeakProxySet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x1425415a0
template void MS2_LoadedMovieDefSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x1425418d0
template void MS2_ActivationTraitsSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142541a60
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UDynAttrsKey@Object@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142541ca0
template void decltype(GFx::AS3::Object::DynAttrsType::mHash)::BaseType::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142541ca0
template void MS2_AbcNsSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142541fe0
template void decltype(GFx::AS3::Slots::SetType::mHash)::BaseType::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142542170
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142542450
template void MS2_StringValueSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142542450
template void MS2_GCRootSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x1425425e0
}
// MS2-PIN: ??_7StickyVarNode@MovieImpl@GFx@Scaleform@@6B@ 0x14317ca50
// MS2-PIN: ??_7StickyVarNode@MovieRoot@AS3@GFx@Scaleform@@6B@ 0x14317d8c8
