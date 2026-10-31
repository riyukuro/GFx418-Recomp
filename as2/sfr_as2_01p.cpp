// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 (gap recovery of sfr_as2_01):
// the two steps that ready a new script call or object: the registers of a call frame (this, the arguments coerced
// to the parameter types, then ...rest or arguments), and the slot values a class or script declares.
// MS2-UNIT: sfr_as2_01p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14252b5a0-0x14252c09c .text$mn
// MS2-RANGE: 0x14252c0e0-0x14252c4d3 .text$mn

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
Instances::Namespace* FUN_142415c20(InstanceTraits::fl::Namespace* self, Abc::NamespaceKind kind, const ASString& uri,
                                    const Value& prefix);  // the interned namespace {kind, uri}

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
inline Value TypeDefaultValue(VM& vm, VMAbcFile& file, const Abc::TraitInfo& ti)
{
    const Abc::Multiname mn = file.GetAbcFile().Const_Pool.GetMultiname(ti.Ind);
    const ClassTraits::Traits* ctr = reinterpret_cast<const ClassTraits::Traits*>(Sfr31ResolveClassTraits(
        reinterpret_cast<UPInt>(&vm), reinterpret_cast<UPInt>(&file), reinterpret_cast<UPInt>(&mn)));
    if (!ctr)
        return Value::GetUndefined();
    Value v;
    Sfr33GetDefaultValue(&vm, &v, *ctr);
    return v;
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

// MS2-FUNCTIONAL: the exe inlines Slots::GetSlotInfo and keeps a never-taken any-type test before it resolves the
// slot type
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
            si = ind.IsValid() ? &GetSlotInfo(ind) : NULL;
        }
        if (!si)
            continue;

        const Value v = ti.default_value.ValueIndex >= 1 ? DetailValue(file, ti.default_value)
                                                         : TypeDefaultValue(GetVM(), file, ti);
        char ok;
        Sfr27SlotSetValueObj(si, &ok, &GetVM(), &v, &for_obj);
        if (!ok)
        {
            --vm.InInitializer;
            return false;
        }
    }
    --vm.InInitializer;
    return true;
}

}}} // namespace Scaleform::GFx::AS3
