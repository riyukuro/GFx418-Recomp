// Recovered Scaleform GFx 4.1.18 AS3: the VM object model (collectable base, objects, classes, traits, slots,
// multinames, namespaces, functions). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder
// members or virtuals.
//
// Layouts are the exe's. They follow the later 4.x object model with these 4.1.18 differences:
//   - the collectable base (RefCountBaseGC) is 0x20 bytes, so every collectable class is 8 bytes smaller than in 4.3
//     (Object 0x38, Class 0x50, Traits 0xc0, InstanceTraits/ClassTraits::Traits 0xc8, CTraits 0xe8, Namespace 0x60)
//   - the collectable base carries three introspection virtuals (slots 1-3: IsAS3Object, GetAS3ObjectType,
//     GetAS3ObjectName) before the destructor (slot 4) and Finalize_GC (slot 5), so own virtuals start at slot 6
//   - Class has one more word at +0x40 (set to 1 by the constructor) between ParentClass and pPrototype
//   - Object has no HasProperty / GetDescendants / ExecutePropertyUnsafe virtuals and one more slot (15, returns 0)
//     after AddDynamicSlotValuePair; InstanceTraits::Traits has no AddInterfaceSlots2This virtual
// Verified against: Object(VM&) 0x1424d93a0, Class(ClassTraits::Traits&) 0x1424d6ac0, the ClassTraits factories
// (0x1423dd550..), FunctionBase(InstanceTraits::Traits&) 0x1423ed140, Multiname(Namespace&, const Value&) 0x1424d8a90
// and the vftables they store. Members marked "unverified" follow 4.x and no recovered code reads them yet.
#ifndef MS2_SF_GFX_AS3_OBJ_H
#define MS2_SF_GFX_AS3_OBJ_H

#include "ms2/scaleform/include/gfx/as3/as3_value.h"
#include "ms2/scaleform/include/kernel/sf_autoptr.h"
#include "ms2/scaleform/include/gfx/as3/as3_gc.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class VM;
class VMFile;
class VMAbcFile;
class VMAppDomain;
class Traits;
class Class;
class Object;
class Multiname;
class PropRef;
class SlotInfo;
class VTable;
class NamespaceInstanceFactory;

namespace Instances
{
    class FunctionBase;
    class Function;
    class ThunkFunction;
    class Namespace;
    namespace fl
    {
        class Object;
        class XMLList;
        class GlobalObject;
        class GlobalObjectScript;
    }
}
namespace InstanceTraits { class Traits; class CTraits; class Interface; namespace fl { class Object; class Namespace; } }
namespace ClassTraits    { class Traits; }

namespace Abc
{
    class TraitInfo;
    class ClassInfo;
    class Multiname;
    class HasTraits;    // (appended, sfr19)

    enum MultinameKind
    {
        MN_QName        = 0x07,
        MN_QNameA       = 0x0D,
        MN_RTQName      = 0x0F,
        MN_RTQNameA     = 0x10,
        MN_RTQNameL     = 0x11,
        MN_RTQNameLA    = 0x12,
        MN_Multiname    = 0x09,
        MN_MultinameA   = 0x0E,
        MN_MultinameL   = 0x1B,
        MN_MultinameLA  = 0x1C,
        MN_Typename     = 0x1D
    };
}

// ==== collectable base ===============================================================================================

// Every object the AS3 garbage collector manages. 0x20 bytes (see as3_gc.h).
class GASRefCountBase : public RefCountBaseGC<StatMV_ActionScript_Mem>
{
public:
    typedef RefCountBaseGC<StatMV_ActionScript_Mem> BaseType;

    GASRefCountBase(Collector* gc) : BaseType(gc) { }
    // (appended, sfr19) the weak proxy of an object that has one is told it died. 0x1424de190
    virtual ~GASRefCountBase();
};

// (appended, sfr19) VMAbcFile (a GASRefCountBase) is not modeled; SlotInfo::File releases through the base, which
// is what the exe does (the Traits ctor 0x1424daa20 needs the slot table's destructor).
template <>
inline void SPtr<VMAbcFile>::Release()
{
    if (pObject)
    {
        if ((UPInt)pObject & 1)
            pObject = (ObjType*)((UPInt)pObject - 1);
        else
            reinterpret_cast<GASRefCountBase*>(pObject)->Release();
    }
}

// ==== slot indices ===================================================================================================

// Index into an object's slot values, 0-based.
class SlotIndex
{
public:
    explicit SlotIndex(UPInt ind) : Index(ind) { }
    UPInt Get() const { return Index; }
private:
    UPInt Index;
};

// 0-based position of a slot in its traits' slot table.
class AbsoluteIndex
{
public:
    AbsoluteIndex() : Index(-1) { }
    explicit AbsoluteIndex(SPInt ind) : Index(ind) { }
    SPInt Get() const       { return Index; }
    bool  IsValid() const   { return Index >= 0; }
private:
    SPInt Index;
};

// (appended, sfr19) 0-based position among a traits' own slots (Traits::AddSetSlot 0x1424e93b0 takes it as 32 bits).
class RelativeIndex
{
public:
    explicit RelativeIndex(UInt32 ind) : Index(ind) { }
    UInt32 Get() const { return Index; }
private:
    UInt32 Index;
};

// 1-based slot index as ABC byte code uses it (0 = none).
class GlobalSlotIndex
{
public:
    explicit GlobalSlotIndex(UInt32 ind) : Index(ind) { }
    UInt32 Get() const      { return Index; }
    bool  IsValid() const   { return Index > 0; }
private:
    UInt32 Index;
};

// ==== slots ==========================================================================================================

// One property of a traits object. 0x30 bytes (unverified).
class SlotInfo
{
public:
    enum Attribute
    {
        aNone       = 0,
        aReadOnly   = 1,
        aDontEnum   = 2,    // (sfr19) was swapped with aReadOnly: AddDynamicSlotValuePair tests a == 2 for DontEnum
        aDontDelete = 4,
        aInternal   = 8,
        aCppBinding = 16    // (appended, sfr19) Traits::AddSlotCPP / AddSlot(MemberInfo)
    };

    enum BindingType
    {
        BT_Unknown,
        BT_ValueArray,
        BT_Value,
        BT_ObjectAS,
        BT_ObjectCpp,
        BT_Boolean,
        BT_Int,
        BT_UInt,
        BT_Number,
        BT_String,
        BT_Code = 11,   // (sfr19) one past 4.x: VTable::AddMethod 0x1424e8ed0 tests Code/Get/Set as 0xb/0xc/0xd
        BT_Get,
        BT_Set,
        BT_GetSet,
        BT_ConstChar
    };

    // (appended, sfr19) an unnamed, unbound placeholder slot (Traits::AddSetSlot 0x1424e93b0).
    // (appended, sfr19) an empty unbound slot. Inline body in as3_vmabcfile.h.
    inline SlotInfo();
    // (sfr19) out of line in the exe; both copy the bit fields one at a time.
    SlotInfo(const SlotInfo& other);                // 0x1424d99f0
    ~SlotInfo();                                    // 0x1424def30
    SlotInfo& operator=(const SlotInfo& other);     // 0x1424e0b80

    // (appended, sfr19) a slot of namespace ns (taken over) and class ctraits; unbound (ValueInd -1) until Bind.
    // Inline body in as3_vmabcfile.h (the SPtr<VMAbcFile> member needs the complete type).
    inline SlotInfo(Pickable<const Instances::Namespace> ns, const ClassTraits::Traits* ctraits, int a = aDontEnum,
                    const Ptr<ASStringNode>& name = NULL);
    // (appended, sfr19) a slot declared by trait ti of an ABC file. Inline body in as3_vmabcfile.h.
    inline SlotInfo(Pickable<const Instances::Namespace> ns, VMAbcFile& file, const Abc::TraitInfo& ti,
                    int a = aDontEnum, const Ptr<ASStringNode>& name = NULL);

    // (appended, sfr19) where the value lives: binding kind and index.
    void Bind(BindingType dt, AbsoluteIndex offset)
    {
        BindType = dt;
        ValueInd = static_cast<SInt32>(offset.Get());
    }

    // +0x00 attribute and binding bit fields (sfr19: was one SInt32 Bits; the copies mask 1/2/4/8/0x10/0x3e0/0x7fffc00)
    UInt32                                  ReadOnly:1;
    UInt32                                  DontEnum:1;
    UInt32                                  DontDelete:1;
    UInt32                                  Internal:1;
    UInt32                                  CppBinding:1;
    SInt32                                  BindType:5;
    SInt32                                  ValueInd:17;
    SPtr<const Instances::Namespace>    pNs;        // +0x08
    SPtr<const ClassTraits::Traits>         CTraits;    // +0x10
    SPtr<VMAbcFile>                         File;       // +0x18
    const Abc::TraitInfo*                   TI;         // +0x20
    Ptr<ASStringNode>                       Name;       // +0x28

    // (appended, sfr13) what a slot value is read for: plain get, or a call.
    enum ValTarget { valGet, valExecute };
};

// Hash functor of the slot name set.
class ASStringNodePtrHashFunc
{
public:
    UPInt operator()(const Ptr<ASStringNode>& data) const { return (UPInt)data->HashFlags; }
};

// The slot table of a traits object. 0x30 bytes.
class Slots
{
public:
    // One table entry: the name, the index of the previous slot with the same name (-1: none) and the slot.
    // 0x40 bytes (sfr19: Slots::Add 0x1424e6670 writes Key +0x00, Prev +0x08, Value +0x10).
    struct Pair
    {
        Pair(const SlotInfo& v, const Ptr<ASStringNode>& k) : Key(k), Prev(-1), Value(v) {}

        Ptr<ASStringNode>   Key;
        SPInt               Prev;
        SlotInfo            Value;
    };

    typedef ArrayLH<Pair, StatMV_VM_SlotInfo_Mem>                                           SlotContainerType;
    typedef HashUncachedLH<Ptr<ASStringNode>, UInt32, ASStringNodePtrHashFunc,
                           StatMV_VM_SlotInfoHash_Mem>                                       SetType;

    // (appended, sfr19) an empty table (inlined by the Traits ctor 0x1424daa20).
    Slots() : FirstOwnSlotNum(0), Parent(NULL) {}

    // (appended, sfr19) appends slot v named k (chained to the previous slot of that name); its index counts the
    // parent's slots (FirstOwnSlotNum). 0x1424e6670
protected:
    AbsoluteIndex Add(const ASString& k, const SlotInfo& v);
    // (appended, sfr19) renames own slot ind to k (rechaining both names). 0x1425276d0
    void SetKey(AbsoluteIndex ind, const ASString& k);
public:
    // (appended, sfr19) slot ind of this table (not of a parent).
    SlotInfo& GetOwnSlotInfo(AbsoluteIndex ind)
    {
        return VArray[static_cast<UInt32>(ind.Get()) - FirstOwnSlotNum].Value;
    }
    // (appended, sfr19) the index of the newest slot named k (older ones chain through GetPrevSlotIndex), or NULL.
    // 0x142502c30
    const UInt32* FindSlotValues(const ASString& k) const;
    // (appended, sfr19) slots of this table and its parents.
    UPInt GetSlotInfoNum() const { return FirstOwnSlotNum + VArray.GetSize(); }
    // (appended, sfr19) slot ind, own or a parent's (the out-of-line copy 0x142416fb0 is the parent call).
    const SlotInfo& GetSlotInfo(AbsoluteIndex ind) const
    {
        if (ind.Get() < 0 || static_cast<UPInt>(ind.Get()) < FirstOwnSlotNum)
            return Parent->GetSlotInfo(ind);
        return VArray[static_cast<UInt32>(ind.Get()) - FirstOwnSlotNum].Value;
    }
    // (appended, sfr19) the previous slot of the same name as slot ind, or -1 (out-of-line copy 0x14250cc30).
    SPInt GetPrevSlotIndex(SPInt ind) const;  // 0x14250cc30

    UPInt               FirstOwnSlotNum;    // +0x00
    const Slots*        Parent;             // +0x08
    SlotContainerType   VArray;             // +0x10
    SetType             Set;                // +0x28
};

// (appended, sfr19; moved from sfr_as3_15) hash functor of the string node -> index maps: the stored HashFlags.
class ASStringNodeHashFunc
{
public:
    UPInt operator()(ASStringNode* const& data) const { return data->HashFlags; }
};

// (appended, sfr19) a stand-alone named slot table: slots in order plus name -> last index. 0x28 bytes.
class SlotContainerType
{
public:
    typedef Slots::Pair                                                                     Pair;
    typedef HashUncachedLH<ASStringNode*, SPInt, ASStringNodeHashFunc, StatMV_VM_SlotInfoHash_Mem> SetType;

    // appends v named k, chained to the previous slot of that name. 0x1424e63b0
    AbsoluteIndex Add(const ASString& k, const SlotInfo& v);
    // updates this slot's key and the key-to-slot index. 0x142527560
    void SetKey(AbsoluteIndex ind, const ASString& k);

    UPInt                                           Size;       // +0x00
    ArrayLH<Pair, StatMV_VM_SlotInfo_Mem>           VArray;     // +0x08
    SetType                                         KVHashSet;  // +0x20
};

// Method closures of a traits object. 0x20 bytes (unverified).
class VTable : public NewOverrideBase<StatMV_VM_VTable_Mem>
{
public:
    // (appended, sfr19) method m (a method index: kInt) bound as dt; returns the index of its slot (the getter's
    // for a get/set pair). 0x1424e8ed0
    AbsoluteIndex AddMethod(const Value& m, SlotInfo::BindingType dt, const ASString& name);
    // (appended, sfr19) records the name of method slot ind (debug bookkeeping). 0x1425283c0
    void SetMethodName(AbsoluteIndex ind, SlotInfo::BindingType dt, const ASString& name);
    // (appended, sfr19) method slot ind (the setter's place for BT_Set) = m (a method index: kInt). 0x1425282d0
    void SetMethod(AbsoluteIndex ind, const Value& m, SlotInfo::BindingType dt, const ASString& name);

    Traits& GetTraits() const { return *pTraits; }

    Traits*                                 pTraits;    // +0x00
    ArrayLH<Value, StatMV_VM_VTable_Mem>    VTMethods;  // +0x08
};

// ==== traits =========================================================================================================

enum BuiltinTraitsType
{
    Traits_Unknown,
    Traits_Boolean,
    Traits_SInt,
    Traits_UInt,
    Traits_Number,
    Traits_String,
    Traits_Namespace,
    Traits_Array,
    Traits_Date,
    Traits_Function,
    Traits_Dictionary,
    Traits_Vector_object,
    Traits_QName,
    Traits_XML,
    Traits_XMLList,
    Traits_Activation,
    Traits_Catch,

    Traits_DisplayObject_Begin,
    Traits_DisplayObject = Traits_DisplayObject_Begin,
    Traits_InteractiveObject,
    Traits_Shape,
    Traits_MorphShape,
    Traits_AVM1Movie,
    Traits_Bitmap,
    // from here on: display object containers
    Traits_DisplayObjectContainer,
    Traits_Sprite,
    Traits_MovieClip,
    Traits_Stage,
    Traits_Loader,
    Traits_SimpleButton,
    Traits_DisplayObject_End
};

// Type of an object or of a class: its slots, method table, size and constructor. 0xc0 bytes. vftable 0x14317b210
// (14 slots; GetName / GetQualifiedName pure).
class Traits : public GASRefCountBase, public Slots
{
public:
    enum QNameFormat { qnfWithColons, qnfWithDot };

    enum
    {
        ArrayLikeMask   = 0x01,
        ObjectTypeMask  = 0x02,     // dynamic objects
        IsInterfaceMask = 0x04,
        HasTailMask     = 0x08,
        IsAbcObjectMask = 0x10,
        IsClassMask     = 0x20,
        IsFinalMask     = 0x40,
        TmpBitMask      = 0x80
    };

    virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    // @0x142505e20
    virtual const char* GetAS3ObjectType() const { return "Traits"; }
    // @0x1423df460
    virtual String GetAS3ObjectName() const { return GetQualifiedName().ToCStr(); }
    virtual ~Traits();

    // slots 6..13
    virtual bool IsGlobal() const;
    virtual ASString GetName() const = 0;
    virtual ASString GetQualifiedName(QNameFormat f = qnfWithColons) const = 0;
    virtual unsigned GetFixedMemSize() const;
    virtual VMAbcFile* GetFilePtr() const;
    virtual CheckResult SetupSlotValues(Object& for_obj) const;
    virtual Instances::fl::GlobalObjectScript* GetGlobalObjectScript() const;
protected:
    virtual void InitOnDemand() const;

public:
    VM&             GetVM() const           { return *pVM; }
    BuiltinTraitsType GetTraitsType() const { return TraitsType; }
    const Traits*   GetParent() const       { return pParent; }
    unsigned        GetMemSize() const      { return MemSize; }

    bool IsDynamic() const          { return (Flags & ObjectTypeMask) != 0; }
    bool IsArrayLike() const        { return (Flags & ArrayLikeMask) != 0; }
    bool IsClassTraits() const      { return (Flags & IsClassMask) != 0; }
    bool IsInstanceTraits() const   { return (Flags & IsClassMask) == 0; }
    bool IsInterface() const        { return (Flags & IsInterfaceMask) != 0; }
    bool HasTail() const            { return (Flags & HasTailMask) != 0; }
    bool IsAbcObject() const        { return (Flags & IsAbcObjectMask) != 0; }
    bool IsFinal() const            { return (Flags & IsFinalMask) != 0; }

    void SetIsInterface()           { Flags |= IsInterfaceMask; }

    // The class object, created on first use.
    Class& GetConstructor() const
    {
        if (!pConstructor)
            InitOnDemand();
        return *pConstructor;
    }

    void SetConstructor(Pickable<Class> c)  { pConstructor = c; }
    // (appended, sfr19) a shared class object (0x142421ac0).
    void SetConstructor(Class& c);
    void SetMemSize(unsigned sz)            { MemSize = sz; }

    // Raw memory for one instance (MemSize bytes) from the VM heap.
    void* Alloc() const;

    // (appended, sfr19) fills the slot values of a new instance (0x1424f0a50).
    void ConstructTail(Object& obj) const;
    // (appended, sfr19) releases the slot values of a dying instance. 0x1424f6de0
    void DestructTail(Object& obj) const;

    // (appended, sfr19) slot and method registration from a C++ ClassInfo.
    void AddSlot(const MemberInfo& mi);                         // 0x1424e9910
    // (appended, sfr19) the other slot adders; dt/offset bind the slot, const_ makes it read only. AddSlotCPP marks a
    // C++ member binding.
    AbsoluteIndex AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, VMAbcFile& file,
                          const Abc::TraitInfo& ti, bool const_);                               // 0x1424e9670
    void AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, const ClassTraits::Traits* tr,
                 SlotInfo::BindingType dt, AbsoluteIndex offset, bool const_);                  // 0x1424e9740
    void AddSlot(const ASString& name, Pickable<const Instances::Namespace> ns, SlotInfo::BindingType dt,
                 AbsoluteIndex offset, bool const_ = false);                                    // 0x1424e9830
    void AddSlotCPP(const ASString& name, Pickable<const Instances::Namespace> ns, const ClassTraits::Traits* tr,
                    SlotInfo::BindingType dt, AbsoluteIndex offset, bool const_);               // 0x1424e9a50
    void Add2VT(const ClassInfo& ci, const ThunkInfo& func);    // 0x1424e56f0
    // (appended, sfr19) own slot ind (ABC slot id order; the gap before it is padded with unnamed slots) declared by
    // trait ti; not bound. 0x1424e93b0
    SlotInfo& AddSetSlot(RelativeIndex ind, const ASString& name, Pickable<const Instances::Namespace> ns,
                         VMAbcFile& file, const Abc::TraitInfo& ti, bool const_ = false);
    // (appended, sfr19) method v bound as bt into the virtual table through slot si (a new VT entry when si is
    // unbound; a getter and a setter merge into BT_GetSet). 0x1424e5510
    void Add2VT(SlotInfo& si, const Value& v, SlotInfo::BindingType bt);
    // (appended, sfr19) a new slot nsi named name, then bound to method v; the interface record of a public method
    // follows it. 0x1424e5660
    void Add2VT(const ASString& name, const Instances::Namespace& ns, const SlotInfo& nsi, const Value& v,
                SlotInfo::BindingType bt);
    // (appended, sfr19) o pushed onto the stored scope stack the class's methods run in. 0x1424e5500
    void Add2StoredScopeStack(const Value& o);
    // (appended, sfr19) the method table, created on first use. 0x14250fa80
    VTable& GetVT() const;
    // (appended, sfr19) overrides the VT method of slot si (unless a plain method would be replaced by an
    // accessor). 0x1425311c0
    void UpdateVT(const SlotInfo& si, const Value& v, SlotInfo::BindingType bt);
    // (appended, sfr19) a public method also updates the VT record of the interface slot of the same name.
    // 0x1425310e0
    void UpdateVT4IM(const ASString& name, const Instances::Namespace& ns, const Value& v, SlotInfo::BindingType bt);
    // (appended, sfr19) the slots and methods of ABC traits (ones with a slot id first, then the rest in order); false
    // after the VerifyError of an illegal override. The instance size follows from parent_size. 0x1424e9b40
    CheckResult AddSlots(const Abc::HasTraits& traits, VMAbcFile& file, unsigned parent_size);
    // (appended, sfr19) how a slot declared with type mn stores its value. 0x1425075e0
    SlotInfo::BindingType GetBindingType(VMAbcFile& file, const Abc::Multiname& mn) const;
    // (appended, sfr19) MemSize from parent_size and the own value slots. 0x1424ee490
    void CalculateMemSize(unsigned parent_size);

protected:
    // (appended, sfr19) the parent is only referenced here; derived ctors copy its slots with CopyParentTraits.
    Traits(VM& vm, const Traits* pt, bool isDynamic, bool isFinal);    // 0x1424daa20
    // (appended, sfr19) takes over the parent's slot table, first own slot and fixed value slot count
    // (0x1425115f0; name ours).
    void CopyParentTraits();

public:
    AbsoluteIndex           FirstOwnSlotInd;        // +0x50
    UPInt                   FixedValueSlotNumber;   // +0x58
    unsigned                MemSize;                // +0x60
    mutable SPInt           Flags;                  // +0x68
    BuiltinTraitsType       TraitsType;             // +0x70
    VM*                     pVM;                    // +0x78
    SPtr<Class>             pConstructor;           // +0x80
    SPtr<const Traits>      pParent;                // +0x88
    mutable AutoPtr<VTable> pVTable;                // +0x90
    ValueArrayDH            InitScope;              // +0xa0
};

namespace InstanceTraits
{
    // Traits of instances. 0xc8 bytes. vftable 0x14317b300 (17 slots).
    class Traits : public AS3::Traits
    {
    public:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142505e30
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Traits"; }
        virtual ASString GetQualifiedName(QNameFormat f = qnfWithColons) const;

        // slots 14..16
        virtual void MakeObject(Value& result, Traits& t);
        virtual void AS3Constructor(const AS3::Traits& ot, const Value& _this, unsigned argc, const Value* argv) const;
        virtual bool SupportsInterface(const Traits&) const;
        // (appended, sfr19) 0x1424df2f0
        virtual ~Traits();

    protected:
        // (appended, sfr19)
        Traits(Pickable<Instances::Namespace> ns, VM& vm, const AS3::Traits* pt, bool isDynamic, bool isFinal); // 0x1424dad50

    public:
        Instances::Namespace& GetNamespace() const { return *Ns; }

        SPtr<Instances::Namespace> Ns;          // +0xc0
    };

    // Traits of instances of a C++ class described by a ClassInfo. 0xe8 bytes. vftable 0x14317b3a0.
    class CTraits : public Traits
    {
    public:
        CTraits(VM& vm, const ClassInfo& ci);
        // @0x142414d40
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::CTraits"; }
        virtual ~CTraits();
        virtual ASString GetName() const;
        virtual bool SupportsInterface(const Traits&) const;

    protected:
        // Adds an interface the C++ class implements (0x142446010).
        void RegisterImplementedInterface(const Multiname& mn);

    public:
        const ClassInfo&                        CI;                     // +0xc8
        ArrayLH<Multiname>                      ImplementsInterfaces;   // +0xd0
    };

    // (appended, sfr19) Traits of runtime-made instances that carry their own name (function/activation objects).
    // 0xd0 bytes. vftable 0x14317b428.
    class RTraits : public Traits
    {
    public:
        RTraits(VM& vm, const ASString& n, Pickable<Instances::Namespace> ns, const AS3::Traits* pt, bool isDynamic, bool isFinal); // 0x1424d94b0
        // @0x142414fb0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::RTraits"; }
        virtual ASString GetName() const;           // 0x14250bc20
        virtual unsigned GetFixedMemSize() const;   // 0x142509d10
        virtual ~RTraits();                         // (appended, sfr19) 0x1424de960
        virtual void MakeObject(Value& result, Traits& t);  // 0x142516570

    public:
        ASString                                Name;                   // +0xc8
    };

    // Traits of an interface implemented in C++. vftable 0x14313f870 (keeps the CTraits type string).
    class Interface : public CTraits
    {
    public:
        Interface(VM& vm, const ClassInfo& ci);
        virtual void MakeObject(Value& result, Traits& t);

        // (appended, sfr19) a new plain object of t.
        // @0x14241aaf0
        Pickable<Instances::fl::Object> MakeInstance(Interface& t);
    };

    namespace fl
    {
        // Traits of plain Object instances. vftable 0x14313f650.
        class Object : public CTraits
        {
        public:
            Object(VM& vm, const ClassInfo& ci);
            // @0x142414f50
            virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::Object"; }
            virtual void MakeObject(Value& result, Traits& t);

            // (appended, sfr19) a new instance of t.
            // @0x14241ac70
            Pickable<Instances::fl::Object> MakeInstance(Object& t);

        public:
            // @0x1423fa9e0 (appended, sfr15)
            static void AS3hasOwnProperty(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
            // @0x1423fd170 (appended, sfr15)
            static void AS3propertyIsEnumerable(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
            // @0x1423e4060 (appended, sfr15)
            static void AS3isPrototypeOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
            // @0x1423e4490 (appended, sfr15)
            static void isPrototypeOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
            // @0x1423e41c0 (appended, sfr15)
            static void setPropertyIsEnumerableProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        };
    }

    // (appended, sfr19) Traits that make no objects: those of class prototype objects, whose constructor is the
    // class (or Object's class). vftable 0x14317b4b0.
    class Prototype : public CTraits
    {
    public:
        Prototype(VM& vm, const ClassInfo& ci);             // 0x1424d9410
        Prototype(VM& vm, const ClassInfo& ci, Class& c);   // 0x1424d9470

        virtual void MakeObject(Value& result, Traits& t) { SF_UNUSED2(result, t); }  // 0x142516560
    };
}

namespace ClassTraits
{
    // Traits of class objects. 0xc8 bytes. vftable 0x14317b288 (15 slots).
    class Traits : public AS3::Traits
    {
    public:
        Traits(VM& vm, const ClassInfo& ci);

        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142415070
        virtual const char* GetAS3ObjectType() const { return "ClassTraits"; }
        // @0x1423df4a0
        virtual String GetAS3ObjectName() const { return GetQualifiedName().ToCStr(); }
        virtual ASString GetName() const;
        virtual ASString GetQualifiedName(QNameFormat f = qnfWithColons) const;
    protected:
        virtual void InitOnDemand() const;
    public:
        // slot 14
        virtual bool Coerce(const Value& value, Value& result) const;

        InstanceTraits::Traits& GetInstanceTraits() const { return *ITraits; }
        void SetInstanceTraits(Pickable<InstanceTraits::Traits> itr);

    protected:
        // (appended, sfr19) adds the slots every class object has (0x1425216d0).
        void RegisterSlots();
    public:

        SPtr<InstanceTraits::Traits> ITraits;   // +0xc0
    };

    // (appended, sfr19) traits of the class Class; coercion keeps the value as is.
    class ClassClass : public Traits
    {
    public:
        ClassClass(VM& vm);
        virtual bool Coerce(const Value& value, Value& result) const;
    };
}

// ==== objects ========================================================================================================

// Base of everything a script can reference: dynamic properties on top of the traits' fixed slots. 0x38 bytes.
// vftable 0x14317b098 (21 slots).
class Object : public GASRefCountBase
{
public:
    // Key of a dynamic property: its name and DontEnum-style flags.
    struct DynAttrsKey
    {
        // (appended, sfr15) lookup key from a bare name; equality is by name only.
        DynAttrsKey(const ASString& name) : Flags(0), Name(name) {}
        // (appended, sfr19) with DoNotEnum (bit 0) and the other flags.
        DynAttrsKey(const ASString& name, UInt32 flags) : Flags(flags), Name(name) {}
        bool operator==(const DynAttrsKey& other) const { return Name.GetNode() == other.Name.GetNode(); }
        void SetDoNotEnum(bool v) const { Flags = (Flags & ~1u) | (UInt32(-SInt32(v)) & 1u); }

        mutable UInt32  Flags;
        ASString        Name;
    };
    struct DynAttrsKeyHashFunctor
    {
        UPInt operator()(const DynAttrsKey& key) const { return key.Name.GetHash(); }
    };
    typedef HashLH<DynAttrsKey, Value, DynAttrsKeyHashFunctor> DynAttrsType;
    class UserDataHolder;

    explicit Object(Traits& t);
protected:
    explicit Object(VM& vm);

public:
    virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    // @0x1423df5b0
    virtual bool IsAS3Object() const { return true; }
    // @0x142505e10
    virtual const char* GetAS3ObjectType() const { return "Object"; }
    // @0x1423df430
    virtual String GetAS3ObjectName() const { return ""; }
    virtual ~Object();

    // slots 6..20
    virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);
    virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);
    virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);
    virtual CheckResult DeleteProperty(const Multiname& prop_name);
    virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
    virtual void AS3Constructor(unsigned argc, const Value* argv);
    virtual void Construct(Value& result, unsigned argc, const Value* argv, bool extCall = false) = 0;
    virtual void InitInstance(bool extCall = false);
    virtual void AddDynamicSlotValuePair(const Value& prop_name, const Value& v,
                                         SlotInfo::Attribute a = SlotInfo::aNone);
    virtual void* Unk15();      // returns 0 (no later 4.x counterpart)
    virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;
    virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;
    virtual void GetNextPropertyValue(Value& value, GlobalSlotIndex ind);
    virtual PropRef FindDynamicSlot(const Multiname& mn);
    virtual const SlotInfo* InitializeOnDemand(const SlotInfo* si, const ASString& name,
                                               const Instances::Namespace& ns, UPInt& index);

    Traits& GetTraits() const   { return *pTraits; }
    VM&     GetVM() const       { return pTraits->GetVM(); }
    // (appended, sfr15)
    const DynAttrsType* GetDynamicAttrs() const { return &DynAttrs; }

    // (appended, sfr13) a dynamic property by string name (0x1424e7f40).
    void AddDynamicSlotValuePair(const ASString& prop_name, const Value& v, SlotInfo::Attribute a = SlotInfo::aNone);

protected:
    SPtr<Traits>        pTraits;            // +0x20
    DynAttrsType        DynAttrs;           // +0x28
    UserDataHolder*     pUserDataHolder;    // +0x30
};

// Instance of an AS3 class. 0x38 bytes.
class Instance : public Object
{
public:
    explicit Instance(InstanceTraits::Traits& t);
    virtual ~Instance();

    // Heap new/delete plus placement new into Traits::Alloc() memory.
    SF_MEMORY_REDEFINE_NEW(Instance, StatType)
    SF_MEMORY_DEFINE_PLACEMENT_NEW
protected:
    explicit Instance(VM& vm);

public:
    virtual void Construct(Value& result, unsigned argc, const Value* argv, bool extCall = false);

    InstanceTraits::Traits& GetInstanceTraits() const
    {
        return static_cast<InstanceTraits::Traits&>(GetTraits());
    }
};

// Class object: constructs instances, owns the prototype. 0x50 bytes. vftable 0x14317b140 (26 slots).
class Class : public Object
{
public:
    explicit Class(ClassTraits::Traits& t);

    virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    // @0x142414d90
    virtual const char* GetAS3ObjectType() const { return "Class"; }
    virtual ~Class();
    virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
    virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);

    // slots 21..25
    virtual CheckResult PreInit(const Value& _this) const;
    virtual void PostInit(const Value& _this, unsigned argc, const Value* argv) const;
    virtual Class& ApplyTypeArgs(unsigned argc, const Value* argv);
    virtual void InitPrototype(AS3::Object& obj) const;
    virtual Pickable<Object> MakePrototype() const;

    ClassTraits::Traits& GetClassTraits() const
    {
        return static_cast<ClassTraits::Traits&>(GetTraits());
    }
    InstanceTraits::Traits& GetInstanceTraits() const
    {
        return GetClassTraits().GetInstanceTraits();
    }
    Class* GetParentClass() const { return ParentClass; }
    // (appended, sfr15) the prototype object, made on first use (0x14250d4c0).
    Object& GetPrototype();
    // (appended, sfr19) obj.constructor = this (not enumerable). 0x1424e6f90
    void AddConstructor(Object& obj) const;

    // native methods
    // @0x142540ba0
    void lengthGet(SInt32& result);
    // @0x142540bb0
    void prototypeGet(Value& result);
    // @0x142542a60
    void toString(ASString& result);

protected:
    SPtr<Class>     ParentClass;    // +0x38
    UInt32          Unk40;          // +0x40 set to 1 by the constructor
    SPtr<Object>    pPrototype;     // +0x48
};

// Class whose call operator constructs (Class(x) == new Class(x)).
class ClassCallConstruct : public Class
{
public:
    explicit ClassCallConstruct(ClassTraits::Traits& t) : Class(t) { }

    virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
};

// ==== names ==========================================================================================================

// Run-time multiname: kind, namespace (or namespace set) and name. 0x30 bytes.
class Multiname
{
public:
    Multiname(Instances::Namespace& ns, const Value& name = Value::GetUndefined());
    Multiname(const Multiname& other);
    // From a qualified name "pkg.Name" (0x1424d9040).
    Multiname(VM& vm, const StringDataPtr& qname);
    // (appended, sfr19) run-time name from a value: a QName object, a string or number, or another object's text (0x1424d8cb0).
    Multiname(VM& vm, const Value& name);
    // (appended, sfr19) multiname mn of an ABC file's constant pool, its strings and namespaces interned (0x1424d8ec0).
    Multiname(VMAbcFile& file, const Abc::Multiname& mn);

    // True when ns is the namespace, or one of the namespace set, the name is qualified with (0x1424f0b70).
    bool ContainsNamespace(const Instances::Namespace& ns) const;
    // (appended, sfr19) turns a numeric or "@"-prefixed name into its canonical form (0x14251cef0).
    void PostProcessName(bool isAttr);

    Abc::MultinameKind      Kind;   // +0x00
    SPtr<GASRefCountBase>   Obj;    // +0x08 namespace or namespace set
    Value                   Name;   // +0x10
};

// Result of a property lookup. 0x30 bytes (unverified).
class PropRef
{
public:
    // Not found.
    PropRef() : pValue(0), SlotIndex(0) { }
    // A dynamic value of obj (the pointer is tagged with bit 0).
    PropRef(Object* obj, Value* v) : pValue(reinterpret_cast<Value*>(reinterpret_cast<UPInt>(v) | 1)), This(obj) { }

    union
    {
        const SlotInfo* pSI;
        Value*          pValue;
        Object*         pObject;
    };
    UPInt   SlotIndex;  // +0x08
    Value   This;       // +0x10

    // (appended, sfr13) the found property's value, getters not run for valGet (0x14250e200).
    CheckResult GetSlotValueUnsafe(VM& vm, Value& value, SlotInfo::ValTarget vt = SlotInfo::valGet) const;
};

// The number a string spells, if it is one (0x14250ee30).
CheckResult GetStrNumber(ASStringNode* str, Value::Number& result);
// The array index a name spells, if it is one (0x142507390).
CheckResult GetArrayInd(const Multiname& prop_name, UInt32& ind);

// ==== instances ======================================================================================================

namespace Instances
{
    namespace fl
    {
        // Plain AS3 Object instance. 0x38 bytes. vftable 0x14313f590.
        class Object : public Instance
        {
        public:
            explicit Object(InstanceTraits::Traits& t);
        protected:
            explicit Object(VM& vm);
        public:
            // @0x142414f60
            virtual const char* GetAS3ObjectType() const { return "Instances::fl::Object"; }
        };
    }

    // AS3 Namespace. 0x60 bytes. vftable 0x143140070 (7 slots).
    class Namespace : public GASRefCountBase
    {
        friend class InstanceTraits::fl::Namespace;
    public:
        Namespace(VM& vm, Abc::NamespaceKind kind, const char* uri);
    protected:
        Namespace(VM& vm, NamespaceInstanceFactory* pfactory, Abc::NamespaceKind kind, const ASString& uri,
                  const Value& prefix);

    public:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142414ec0
        virtual const char* GetAS3ObjectType() const { return "Namespace"; }
        virtual String GetAS3ObjectName() const;
        virtual ~Namespace();
        // slot 6
        virtual void AS3Constructor(unsigned argc, const Value* argv);

        Abc::NamespaceKind  GetKind() const     { return (Abc::NamespaceKind)Kind; }
        const ASString&     GetUri() const      { return Uri; }
        const Value&        GetPrefix() const   { return Prefix; }
        VM&                 GetVM() const       { return VMRef; }
        // (appended, sfr19) the second namespace of an interface method's VT record.
        bool                GetIsInterface() const  { return IsInterface != 0; }

    protected:
        SPInt                           Kind:4;         // +0x20
        UPInt                           IsInterface:1;
        VM&                             VMRef;          // +0x28
        ASString                        Uri;            // +0x30
        Ptr<NamespaceInstanceFactory>   pFactory;       // +0x38
        Value                           Prefix;         // +0x40
    };

    // Base of callable objects. 0x40 bytes.
    class FunctionBase : public fl::Object
    {
    protected:
        explicit FunctionBase(InstanceTraits::Traits& t);

    public:
        // (appended, sfr19) Call runs slot 21 into a temporary (body in sfr_as3_03).
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // slot 21
        virtual void ExecuteUnsafe(const Value& _this, Value& result, unsigned argc, const Value* argv);
        // slot 22 (0x142407230)
        virtual void Execute(const Value& _this, unsigned argc, const Value* argv, bool discard_result = false);
        // slot 23: the declared parameter count, the AS3 length (the base body is shared with an empty function)
        virtual UInt32 GetMaxParamNum() const;

        // native methods
        // @0x1424292a0
        void lengthGet(UInt32& result);

    protected:
        SPtr<AS3::Object>   Prototype;      // +0x38
    };
}

}}} // namespace Scaleform::GFx::AS3

#endif
