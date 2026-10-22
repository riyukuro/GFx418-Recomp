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
namespace InstanceTraits { class Traits; class CTraits; class Interface; namespace fl { class Object; } }
namespace ClassTraits    { class Traits; }

namespace Abc
{
    class TraitInfo;
    class ClassInfo;
    class Multiname;

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
};

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
        aDontEnum   = 1,
        aReadOnly   = 2,
        aDontDelete = 4,
        aInternal   = 8
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
        BT_Code,
        BT_Get,
        BT_Set,
        BT_GetSet,
        BT_ConstChar
    };

    SInt32                                  Bits;       // +0x00 attribute and binding bit fields
    SInt32                                  Padding01;  // +0x04
    SPtr<const Instances::Namespace>    pNs;        // +0x08
    SPtr<const ClassTraits::Traits>         CTraits;    // +0x10
    SPtr<VMAbcFile>                         File;       // +0x18
    const Abc::TraitInfo*                   TI;         // +0x20
    Ptr<ASStringNode>                       Name;       // +0x28
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
    // One table entry: the slot and the index of the previous slot with the same name.
    struct Pair
    {
        SlotInfo    Value;
        SPInt       Prev;
    };

    typedef ArrayLH<Pair, StatMV_VM_SlotInfo_Mem>                                           SlotContainerType;
    typedef HashUncachedLH<Ptr<ASStringNode>, UInt32, ASStringNodePtrHashFunc,
                           StatMV_VM_SlotInfoHash_Mem>                                       SetType;

    UPInt               FirstOwnSlotNum;    // +0x00
    const Slots*        Parent;             // +0x08
    SlotContainerType   VArray;             // +0x10
    SetType             Set;                // +0x28
};

// Method closures of a traits object. 0x20 bytes (unverified).
class VTable : public NewOverrideBase<StatMV_VM_VTable_Mem>
{
public:
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
    void SetMemSize(unsigned sz)            { MemSize = sz; }

    // Raw memory for one instance (MemSize bytes) from the VM heap.
    void* Alloc() const;

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

    // Traits of an interface implemented in C++. vftable 0x14313f870 (keeps the CTraits type string).
    class Interface : public CTraits
    {
    public:
        Interface(VM& vm, const ClassInfo& ci);
        virtual void MakeObject(Value& result, Traits& t);
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
        };
    }
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

        SPtr<InstanceTraits::Traits> ITraits;   // +0xc0
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

    // True when ns is the namespace, or one of the namespace set, the name is qualified with (0x1424f0b70).
    bool ContainsNamespace(const Instances::Namespace& ns) const;

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
        VM&                 GetVM() const       { return VMRef; }

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
        // native methods
        // @0x1424292a0
        void lengthGet(UInt32& result);

    protected:
        SPtr<AS3::Object>   Prototype;      // +0x38
    };
}

}}} // namespace Scaleform::GFx::AS3

#endif
