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
