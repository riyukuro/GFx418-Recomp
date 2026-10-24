// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 virtual machine core. Our own
// source, written from the exe.
// MS2-UNIT: sfr_as3_16
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424dc870-0x1424eb700 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_udbase.h"
#include "ms2/scaleform/include/gfx/as2/as2_object.h"   // ASUserData
#include "ms2/scaleform/include/gfx/as3/as3_loadqueue.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_taskmanager.h"
#undef GetObject   // windows.h

namespace Scaleform { namespace GFx { namespace AS3 {
    // The executable keeps ModifyOptimizedPlayList out of line at 0x142517e70; its body is recovered in sfr_as3_18.
    void Sfr34_ModifyOptimizedPlayList(InteractiveObject* p);

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

// ==== destructors ===================================================================================================

namespace Classes {
    // MS2-FUNCTIONAL: the executable calls the same tail cleanup directly; this definition reaches it through GetTraits().
    // @0x1424df350
    UDBase::~UDBase()
    {
        GetTraits().DestructTail(*this);
        Class::~Class();
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

// MS2-FUNCTIONAL: the exe calls WProxyHash.Get out of line (0x1425058c0); cl inlines it.
// @0x1424de190
GASRefCountBase::~GASRefCountBase()
{
    if (HasWeakRef())
    {
        Collector* rcc = GetCollector();
        WeakProxy* wp = NULL;
        if (rcc->WProxyHash.Get(this, &wp) && wp)
        {
            wp->NotifyObjectDied();
            wp->Release();
            rcc->WProxyHash.Remove(this);
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

    // MS2-FUNCTIONAL: the exe calls the ArrayDataBase<Multiname> dtor out of line (0x1424dc870); cl inlines it.
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

// MS2-FUNCTIONAL ??1LoadQueueEntry@AS3@GFx@Scaleform@@UEAA@XZ: the exe calls AutoPtr<ArrayPOD<UByte> >'s dtor out of
// line (0x1424dc9f0); ours inlines it
// @0x1424e3020 (??_G)
LoadQueueEntry::~LoadQueueEntry()
{
    NotifyLoadInitCInterface = NULL;
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

// MS2-FUNCTIONAL: the default destructor inlines the contained Value cleanup that the executable calls through its
// helper; the cleanup is equivalent, but the leaf/frame differs.
// @0x1424de8f0
PropRef::~PropRef() = default;

// @0x1424e0b40
PropRef& PropRef::operator=(PropRef&& other)
{
    pValue = other.pValue;
    SlotIndex = other.SlotIndex;
    This.Assign(other.This);
    return *this;
}

// @0x1424e0e20
PropRef::operator bool() const
{
    const UPInt tagged = reinterpret_cast<UPInt>(pValue);
    return (static_cast<UInt32>(This.GetKind()) & 0x1f) != 0 && tagged != 1 &&
           ((tagged & 2) == 0 || (tagged & ~UPInt(2)) != 0);
}

// The two ReadArgs variants own a heap-backed copy of their argument values.
// MS2-FUNCTIONAL: the executable calls ArrayDH<Value>::~ArrayDH out of line; this TU inlines that release sequence.
// @0x1424de9e0
ReadArgs::~ReadArgs() = default;

namespace TR {
// MS2-FUNCTIONAL: the executable calls ArrayDH<Value>::~ArrayDH out of line; this TU inlines that release sequence.
// @0x1424dea90
ReadArgs::~ReadArgs() = default;
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
        list->Apppend(static_cast<Instances::fl::XML*>(&l));
    else
        list->Append(static_cast<Instances::fl::XMLList&>(l));
    if (rightXML)
        list->Apppend(static_cast<Instances::fl::XML*>(&r));
    else
        list->Append(static_cast<Instances::fl::XMLList&>(r));
    result.Pick(list);
    return true;
}

}}} // namespace Scaleform::GFx::AS3

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

// The VM and call-frame code keeps this array destructor out of line in the executable.
// @0x1424dc870
template Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,
                                  Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname, 2>,
                                  Scaleform::ArrayDefaultPolicy>::~ArrayDataBase();

// These three assignments are the copy-assignment instantiations used by SlotInfo's Namespace, Traits and VMAbcFile.
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

extern "C" void* DAT_143b15f60;
extern "C" void FUN_1424dde10(void*);

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
                FUN_1424dde10(frame);
                --used;
            }
            auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, *page);
            numPages = *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x10);
            --page;
        } while (numPages);
        *reinterpret_cast<Scaleform::UPInt*>(bytes + 0x10) = static_cast<Scaleform::UPInt>(-1);
        auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(
            DAT_143b15f60, *reinterpret_cast<void**>(bytes + 0x20));
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
                auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
                reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, data);
            }
            auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
            reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, object);
        }
        *reinterpret_cast<void**>(bytes) = 0;
    }
    bytes[8] = 0;
}

// Clears the chained hash table's entries to the free sentinel, then releases the table block.
// MS2-FUNCTIONAL: clears the same 0x28-byte entry chain and frees the backing block; loop register allocation differs.
// @0x1424dca60
void FUN_1424dca60(void* self)
{
    auto** table = static_cast<void**>(self);
    if (*table)
    {
        auto* bytes = static_cast<unsigned char*>(*table);
        Scaleform::UPInt count = *reinterpret_cast<Scaleform::UPInt*>(bytes + 8) + 1;
        for (Scaleform::UPInt i = 0; i < count; ++i)
        {
            auto* next = reinterpret_cast<Scaleform::UPInt*>(bytes + i * 0x28 + 0x10);
            if (*next != static_cast<Scaleform::UPInt>(-2))
                *next = static_cast<Scaleform::UPInt>(-2);
        }
        auto** heapVtable = *reinterpret_cast<void***>(DAT_143b15f60);
        reinterpret_cast<void (*)(void*, void*)>(heapVtable[12])(DAT_143b15f60, *table);
        *table = nullptr;
    }
}

// MS2-PIN: ??_G?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@MEAAPEAXI@Z 0x1424e3750
// MS2-PIN: ?Add@XMLSupportImpl@AS3@GFx@Scaleform@@UEBA_NAEAVValue@234@AEAVObject@234@1@Z 0x1424e6990
