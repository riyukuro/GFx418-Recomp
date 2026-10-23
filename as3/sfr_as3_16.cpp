// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 virtual machine core. Our own
// source, written from the exe.
// MS2-UNIT: sfr_as3_16
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424dc870-0x1424eb700 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// ==== slots ==========================================================================================================

// @0x1424def30
SlotInfo::~SlotInfo()
{
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

}}} // namespace Scaleform::GFx::AS3
