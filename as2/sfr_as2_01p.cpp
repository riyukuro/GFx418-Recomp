// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 (gap recovery of sfr_as2_01):
// the two steps that ready a new script call or object: the registers of a call frame (this, the arguments coerced
// to the parameter types, then ...rest or arguments), and the slot values a class or script declares.
// MS2-UNIT: sfr_as2_01p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14252b5a0-0x14252c09c .text$mn
// MS2-RANGE: 0x14252c0e0-0x14252c4d3 .text$mn

#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp weak-ref bodies inline (as3_value.h)
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// Helpers of other units, bound by address. The members among them keep the member call convention (this, then the
// result).
UPInt  Sfr31ResolveClassTraits(UPInt vm, UPInt file, UPInt mn);                      // VM: the class traits mn names
void   Sfr31VMRaiseError(UPInt vm, const unsigned long* error, UPInt classInfo);        // VM: raise as class ci
Value* Sfr33GetDefaultValue(VM* vm, Value* result, const ClassTraits::Traits& tr);     // VM: default of tr
char*  Sfr27SlotSetValueObj(const SlotInfo* si, char* ok, VM* vm, const Value* v, Object* obj);  // set slot
}}}
Scaleform::GFx::AS3::Instances::Namespace* FUN_142415c20(Scaleform::GFx::AS3::InstanceTraits::fl::Namespace* self,
                                                         Scaleform::GFx::AS3::Abc::NamespaceKind kind,
                                                         const Scaleform::GFx::ASString& uri,
                                                         const Scaleform::GFx::AS3::Value& prefix);  // the interned namespace {kind, uri}
namespace Scaleform { namespace GFx { namespace AS3 {

namespace {

const VM::ErrorID eClassNotFoundError = static_cast<VM::ErrorID>(1014);

// The global object a call without a this runs on: the bottom of the saved scope, else the object in register 0.
inline Object* GlobalOfFrame(const ScopeStackType* scope, const Value& reg0)
{
    if (scope && scope->GetSize() != 0)
        return (*scope)[0].GetObject();
    return reg0.IsObject() ? reg0.GetObject() : NULL;
}

// The innermost register set of a register file (ValueRegisterFile keeps it private; +0x08).
inline Value* RegistersOf(void* prf)
{
    return *reinterpret_cast<Value**>(static_cast<UByte*>(prf) + 0x08);
}

// A method closure of obj (kVTableIndClosure, not a super call), built through a layout view: Value's closure
// constructor calls the out-of-line AddRefClosure, which the exe expands inline everywhere.
inline Value VTableIndClosure(Object* obj, SInt32 ind)
{
    struct Raw { UInt32 Flags; void* Bonus; SInt64 Ind; Object* Obj; };
    const Raw r = { Value::kVTableIndClosure, NULL, ind, obj };
    if (obj)
        obj->AddRef();
    return Value(*reinterpret_cast<const Value*>(&r), Value::NotRefCounted);
}

inline Value DetailValue(VMAbcFile& file, const Abc::ValueDetail& d)
{
    return file.GetDetailValue(d);
}

// The value a slot without a default starts with: the default of its declared type, undefined for an unknown one.
__forceinline Value* TypeDefaultValue(Value* result, VM& vm, VMAbcFile& file, const Abc::TraitInfo& ti)
{
    const Abc::File& f = file.GetAbcFile();
    // A non-POD copy of the type name: the SDK's Multiname has a ctor, so its address-taken copy is no /GS buffer.
    class TypeName
    {
        Abc::MultinameFlagKind Kind;
        Abc::SInd              Ind;
        Abc::SInd              NameIndex;
        Abc::SInd              NextIndex;
    public:
        explicit TypeName(const Abc::Multiname& x)
            : Kind(x.Kind), Ind(x.Ind), NameIndex(x.NameIndex), NextIndex(x.NextIndex) {}
        const Abc::Multiname* operator&() const { return reinterpret_cast<const Abc::Multiname*>(this); }
    };
    const TypeName mn(ti.GetType() == Abc::TraitInfo::tSlot || ti.GetType() == Abc::TraitInfo::tConst
                          ? f.Const_Pool.GetMultiname(ti.Ind)
                          : f.Const_Pool.GetMultiname(f.AS3_Classes.Info[ti.Ind]->inst_info.name_ind));
    if (&mn != &f.Const_Pool.AnyType)
    {
        const ClassTraits::Traits* ctr = reinterpret_cast<const ClassTraits::Traits*>(Sfr31ResolveClassTraits(
            reinterpret_cast<UPInt>(&vm), reinterpret_cast<UPInt>(&file), reinterpret_cast<UPInt>(&mn)));
        if (ctr)
            return Sfr33GetDefaultValue(&vm, result, *ctr);
    }
    return ::new (result) Value(Value::GetUndefined());
}

} // namespace

// MS2-FUNCTIONAL: AddDynamicSlotValuePair, Value::GetUndefined and VM::MakeArray are inlined by the exe, and its
// callee value is built in place
// @0x14252b5a0
void CallFrame::SetupRegisters(const Abc::MethodInfo& mi, const Value& _this, unsigned argc, const Value* argv)
{
    Value*   regs = RegistersOf(pRegisterFile);
    unsigned reg  = 1;

    regs[0] = _this.IsNullOrUndefined() ? Value(GlobalOfFrame(pSavedScope, regs[0])) : _this;

    const UPInt param_count = mi.ParamTypes.GetSize();
    const UPInt first_opt   = param_count - mi.OptionalParams.GetSize();
    for (unsigned i = 0; i < param_count; ++i)
    {
        const Abc::ConstPool&      cp = pFile->GetAbcFile().Const_Pool;
        const Abc::Multiname&      mn = cp.GetMultiname(mi.ParamTypes[i]);
        const ClassTraits::Traits* tr = reinterpret_cast<const ClassTraits::Traits*>(Sfr31ResolveClassTraits(
            reinterpret_cast<UPInt>(&pFile->GetVM()), reinterpret_cast<UPInt>(pFile), reinterpret_cast<UPInt>(&mn)));
        if (!tr)
        {
            VM&             vm = pFile->GetVM();
            const VM::Error e(eClassNotFoundError, vm, cp.ConstStr[mn.NameIndex].ToStringDataPtr().ToCStr());
            Sfr31VMRaiseError(reinterpret_cast<UPInt>(&vm), reinterpret_cast<const unsigned long*>(&e),
                              reinterpret_cast<UPInt>(&fl::ReferenceErrorCI));
            return;
        }

        Value v = Value::GetUndefined();
        if (i < argc)
        {
            if (!tr->Coerce(argv[i], v))
            {
                VM&             vm = pFile->GetVM();
                const VM::Error e(VM::eCheckTypeFailedError, vm, argv[i], tr->GetName().ToCStr());
                Sfr31VMRaiseError(reinterpret_cast<UPInt>(&vm), reinterpret_cast<const unsigned long*>(&e),
                                  reinterpret_cast<UPInt>(&fl::TypeErrorCI));
                return;
            }
        }
        else if (mi.HasOptionalParams() && i >= first_opt)
        {
            const Abc::ValueDetail& d = mi.OptionalParams[i - first_opt];
            if (!tr->Coerce(DetailValue(*pFile, d), v))
            {
                VM&             vm = pFile->GetVM();
                const VM::Error e(VM::eCheckTypeFailedError, vm, DetailValue(*pFile, d), tr->GetName().ToCStr());
                Sfr31VMRaiseError(reinterpret_cast<UPInt>(&vm), reinterpret_cast<const unsigned long*>(&e),
                                  reinterpret_cast<UPInt>(&fl::TypeErrorCI));
                return;
            }
        }
        else if (tr != pFile->GetVM().TraitsClassClass.GetPtr())
        {
            // a missing argument without a default
            VM&             vm = pFile->GetVM();
            const VM::Error e(VM::eWrongArgumentCountError, vm, Name->pData, (int)first_opt, (int)param_count,
                              (int)argc);
            Sfr31VMRaiseError(reinterpret_cast<UPInt>(&vm), reinterpret_cast<const unsigned long*>(&e),
                              reinterpret_cast<UPInt>(&fl::ArgumentErrorCI));
            return;
        }
        regs[reg++] = v;
    }

    if (mi.Flags & Abc::MethodInfo::fNEED_REST)
    {
        // ...rest: the arguments past the parameters
        InstanceTraits::fl::Array& itr = static_cast<InstanceTraits::fl::Array&>(
            pFile->GetVM().GetClassTraitsArray().GetInstanceTraits());
        Pickable<Instances::fl::Array> parr = itr.MakeInstance(itr);
        Instances::fl::Array*          rest = parr.GetPtr();
        regs[reg] = Value(parr);
        if (argc > param_count)
            rest->SA.Append(argc - (unsigned)param_count, argv + param_count);
    }
    else if (mi.Flags & Abc::MethodInfo::fNEED_ARGUMENTS)
    {
        // arguments: every argument, the coerced value where there is a parameter, and the callee
        InstanceTraits::fl::Array& itr = static_cast<InstanceTraits::fl::Array&>(
            pFile->GetVM().GetClassTraitsArray().GetInstanceTraits());
        Pickable<Instances::fl::Array> parr = itr.MakeInstance(itr);
        Instances::fl::Array*          args = parr.GetPtr();
        regs[reg] = Value(parr);
        for (unsigned i = 0; i < argc; ++i)
            args->SA.PushBack(i < reg - 1 ? regs[i + 1] : argv[i]);

        Value callee;
        if (Invoker.GetKind() == Value::kVTableInd)
            callee = VTableIndClosure(_this.GetObject(), Invoker.GetVTableInd());
        else
            callee = Invoker;
        args->AddDynamicSlotValuePair(pFile->GetVM().GetStringManager().GetStringManager()->CreateConstString(
                                          "callee", 6),
                                      callee);
    }
}

// MS2-FUNCTIONAL: the exe's AS3_All.cpp SCU also inlines Value::GetUndefined (its guarded local static, 0x80 bytes)
// as the namespace lookup's prefix argument. Ours calls it, because sfr_as3_18 defines it out of line and the static
// is internal there. The rest (inline Slots::GetSlotInfo, VM::GetDefaultValue with its any-type test, one shared
// value temporary, SCU AddRef bodies) follows the SDK.
// @0x14252c0e0
CheckResult Traits::SetupSlotValues(VMAbcFile& file, const Abc::HasTraits& t, Object& for_obj) const
{
    VM& vm = GetVM();
    ++vm.InInitializer;
    for (unsigned i = 0; i < t.obj_traits.GetSize(); ++i)
    {
        const Abc::File&      abc = file.GetAbcFile();
        const Abc::ConstPool& cp  = abc.Const_Pool;
        const Abc::TraitInfo& ti  = *abc.Traits.TraitInfos[t.obj_traits[i]];
        if (ti.GetType() != Abc::TraitInfo::tSlot && ti.GetType() != Abc::TraitInfo::tConst)
            continue;

        const Abc::Multiname      mn  = cp.GetMultiname(ti.name_ind);
        const Abc::NamespaceInfo& nsi = mn.Ind == 0 ? cp.any_namespace : cp.ConstNamespace[mn.Ind];
        const Instances::Namespace* ns;
        {
            const ASString uri =
                GetVM().GetStringManager().GetStringManager()->CreateString(nsi.NameURI.ToCStr(),
                                                                             nsi.NameURI.GetSize());
            if (uri.IsEmpty() && nsi.Kind == Abc::NS_Public)
                ns = &GetVM().GetPublicNamespace();
            else
                ns = FUN_142415c20(&static_cast<InstanceTraits::fl::Namespace&>(
                                       GetVM().GetClassTraitsNamespace().GetInstanceTraits()),
                                   nsi.Kind, uri, Value::GetUndefined());
        }

        const SlotInfo* si;
        {
            const AbsoluteIndex ind = FindSlotInfoIndex(file.GetInternedString(mn.NameIndex), *ns);
            si = ind.IsValid() ? (ind.Get() < FirstOwnSlotNum ? &Parent->GetSlotInfo(ind)
                                                              : &VArray[static_cast<UInt32>(ind.Get()) -
                                                                        FirstOwnSlotNum].Value)
                               : NULL;
        }
        if (!si)
            continue;

        // The slot's start value, built in place (the exe constructs both kinds into one temporary).
        union ValueSlot
        {
            ValueSlot() {}
            ~ValueSlot() {}
            Value v;
        } slot;
        const Value* v = ti.default_value.ValueIndex > 0 ? ::new (&slot.v) Value(file.GetDetailValue(ti.default_value))
                                                         : TypeDefaultValue(&slot.v, GetVM(), file, ti);
        bool ok;
        const char r = *Sfr27SlotSetValueObj(si, reinterpret_cast<char*>(&ok), &GetVM(), v, &for_obj);
        slot.v.~Value();
        if (!r)
        {
            --vm.InInitializer;
            return false;
        }
    }
    --vm.InInitializer;
    return true;
}

}}} // namespace Scaleform::GFx::AS3
