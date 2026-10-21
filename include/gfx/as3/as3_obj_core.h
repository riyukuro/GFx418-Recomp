// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, the core top-level classes
// (Object, Array, Boolean, Number, int, uint, String, Math, Date, RegExp, QName, XML, XMLList, Catch and the Error
// family): their class traits, instance traits and class objects. Our own declarations, written from the exe.
// Type strings are the exe's (the 4.1.18 build is not consistent about the "fl::" part). Methods marked @ without a
// body here are defined in the AS3_Obj_All units.
#ifndef MS2_SCALEFORM_GFX_AS3_OBJ_CORE_H
#define MS2_SCALEFORM_GFX_AS3_OBJ_CORE_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl
{
    extern const ClassInfo ObjectCI;
    extern const ClassInfo ArrayCI;
    extern const ClassInfo BooleanCI;
    extern const ClassInfo CatchCI;
    extern const ClassInfo DateCI;
    extern const ClassInfo ErrorCI;
    extern const ClassInfo MathCI;
    extern const ClassInfo NamespaceCI;
    extern const ClassInfo NumberCI;
    extern const ClassInfo QNameCI;
    extern const ClassInfo RegExpCI;
    extern const ClassInfo StringCI;
    extern const ClassInfo XMLCI;
    extern const ClassInfo XMLListCI;
    extern const ClassInfo int_CI;
    extern const ClassInfo uintCI;
    extern const ClassInfo ArgumentErrorCI;
    extern const ClassInfo DefinitionErrorCI;
    extern const ClassInfo EvalErrorCI;
    extern const ClassInfo RangeErrorCI;
    extern const ClassInfo ReferenceErrorCI;
    extern const ClassInfo SecurityErrorCI;
    extern const ClassInfo SyntaxErrorCI;
    extern const ClassInfo TypeErrorCI;
    extern const ClassInfo URIErrorCI;
    extern const ClassInfo UninitializedErrorCI;
    extern const ClassInfo VerifyErrorCI;
}

namespace InstanceTraits { namespace fl { class Namespace; } }

// Array storage: a dense part (ValueA) plus a hash for the indices past it. 0x68 bytes.
class SparseArray
{
public:
    explicit SparseArray(MemoryHeap* heap)
        : Length(0), ValueHLowInd(0), ValueHHighInd(0), ValueA(heap), ValueH(heap)
    {
    }

public:
    UPInt                   Length;         // +0x00
    UPInt                   ValueHLowInd;   // +0x08
    UPInt                   ValueHHighInd;  // +0x10
    Value                   DefaultValue;   // +0x18
    ValueArrayDH            ValueA;         // +0x38
    HashDH<UPInt, Value>    ValueH;         // +0x58
};

namespace Instances { namespace fl
{
    // 0xa0 bytes.
    class Array : public Instance
    {
    public:
        explicit Array(InstanceTraits::Traits& t);
        // @0x142414d00
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::Array"; }
        // @0x14240bc90
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142421ff0
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);
        // @0x142416730
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);
        // @0x1424159a0
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);
        // @0x142409060
        virtual CheckResult DeleteProperty(const Multiname& prop_name);
        // @0x1423f5550
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        // @0x142416200
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;
        // @0x142416100
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;
        // @0x142416520
        virtual void GetNextPropertyValue(Value& value, GlobalSlotIndex ind);

    public:
        SparseArray SA;     // +0x38

    public:
        // native methods
        // @0x142429290
        void lengthGet(UInt32& result);
        // @0x142429480
        void lengthSet(const Value& result, UInt32);
    };
    // Instance of the Catch scope of an exception handler. 0x38 bytes.
    class Catch : public Instance
    {
    public:
        explicit Catch(InstanceTraits::Traits& t);
        // @0x142414d80
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::Catch"; }
    };

    // 0x48 bytes.
    class Date : public Instance
    {
    public:
        explicit Date(InstanceTraits::Traits& t);
        // @0x142414dd0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::Date"; }
        // @0x1423f5650
        virtual void AS3Constructor(unsigned argc, const Value* argv);

    public:
        Value::Number   TimeValue;  // +0x38 ms since 1970-01-01 UTC
        SInt32          LocalTZA;   // +0x40

    public:
        // native methods
        // @0x1424037b0
        void AS3valueOf(Value::Number& result);
    };

    // 0x58 bytes.
    class Error : public Instance
    {
    public:
        explicit Error(InstanceTraits::Traits& t);
        Error(InstanceTraits::Traits& t, int id, const ASString& msg);
        // @0x142414e20
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::Error"; }
        // @0x1423f5770
        virtual void AS3Constructor(unsigned argc, const Value* argv);

    public:
        ASString    message;        // +0x38
        ASString    name;           // +0x40
        SInt32      ID;             // +0x48
        ASString    StackTrace;     // +0x50

    public:
        // native methods
        // @0x1424282e0
        void errorIDGet(SInt32& result);
        // @0x142428c80
        void getStackTrace(ASString& result);
        // @0x14242b1e0
        void toStringProto(ASString& result);
    };

    // 0x48 bytes.
    class QName : public Instance
    {
    public:
        explicit QName(InstanceTraits::Traits& t);
        QName(InstanceTraits::Traits& t, const ASString& local, Instances::Namespace* ns);
        // @0x142414fa0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::QName"; }
        // @0x14240c010
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x1423f5ae0
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        // @0x142416330
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;
        // @0x142416180
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;
        // @0x142416630
        virtual void GetNextPropertyValue(Value& value, GlobalSlotIndex ind);

    public:
        ASString                    LocalName;  // +0x38
        SPtr<Instances::Namespace>  Ns;         // +0x40

    public:
        // native methods
        // @0x142403820
        void AS3valueOf(SPtr<Instances::fl::QName>& result);
        // @0x142429490
        void localNameGet(ASString& result);
    };

    // 0x60 bytes.
    class RegExp : public Instance
    {
    public:
        explicit RegExp(InstanceTraits::Traits& t);
        // @0x142415010
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::RegExp"; }
        // @0x1423f5d90
        virtual void AS3Constructor(unsigned argc, const Value* argv);

    public:
        void*       CompRegExp;     // +0x38 compiled pattern (pcre)
        SInt32      MatchOffset;    // +0x40
        SInt32      MatchLength;    // +0x44
        String      Pattern;        // +0x48
        bool        IsGlobal;       // +0x50
        SInt32      LastIndex;      // +0x54
        int         OptionFlags;    // +0x58
        bool        HasNamedGroups; // +0x5c

    public:
        // native methods
        // @0x1423f9300
        void AS3exec(SPtr<Instances::fl::Object>& result, const ASString&);
        // @0x142428130
        void dotallGet(bool& result);
        // @0x142428490
        void extendedGet(bool& result);
        // @0x142428da0
        void globalGet(bool& result);
        // @0x142428e00
        void ignoreCaseGet(bool& result);
        // @0x1424291b0
        void lastIndexGet(SInt32& result);
        // @0x1424291c0
        void lastIndexSet(const Value& result, SInt32);
        // @0x142429910
        void multilineGet(bool& result);
        // @0x14242b010
        void sourceGet(ASString& result);
    };

    // 0x68 bytes.
    class XMLList : public Instance
    {
    public:
        explicit XMLList(InstanceTraits::Traits& t);
        // @0x142415160
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::XMLList"; }
        // @0x14240c440
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142422a20
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);
        // @0x142416b90
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);
        // @0x142415a40
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);
        // @0x142409340
        virtual CheckResult DeleteProperty(const Multiname& prop_name);
        // @0x1423f63b0
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        // @0x142416430
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;
        // @0x1424161c0
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;
        // @0x1424166c0
        virtual void GetNextPropertyValue(Value& value, GlobalSlotIndex ind);

    public:
        ArrayLH<SPtr<Instances::fl::Object> >   List;               // +0x38 the XML items
        SPtr<AS3::Object>                       TargetObject;       // +0x50
        ASStringNode*                           TargetProperty;     // +0x58
        SPtr<Instances::Namespace>              TargetNamespace;    // +0x60

    public:
        // native methods
        // @0x1423fb880
        void AS3length(SInt32& result);
        // @0x142429ea0
        void prototypeGet(SPtr<Instances::fl::XMLList>& result);
        // @0x142429fa0
        void prototypeSet(const Value& result, const Value&);
    };
}}

// Makes the Namespace instances of one VM and keeps the set of the namespaces it made (one per kind/uri/prefix).
// 0x20 bytes. vftable 0x143140af8.
class NamespaceInstanceFactory : public RefCountBase<NamespaceInstanceFactory, StatMV_VM_ITraits_Mem>
{
public:
    explicit NamespaceInstanceFactory(InstanceTraits::fl::Namespace* itr)
        : pNamespaceInstanceTraits(itr)
    {
    }

public:
    typedef HashSetLH<Instances::Namespace*, FixedSizeHash<Instances::Namespace*>, FixedSizeHash<Instances::Namespace*>,
                      Stat_Default_Mem, HashsetEntry<Instances::Namespace*, FixedSizeHash<Instances::Namespace*> > >
        NamespaceSetType;

    NamespaceSetType                NamespaceSet;               // +0x10
    InstanceTraits::fl::Namespace*  pNamespaceInstanceTraits;   // +0x18
};

namespace InstanceTraits { namespace fl
{
    class Array : public CTraits
    {
    public:
        Array(VM& vm, const ClassInfo& ci);
        // @0x142414cf0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Array"; }
        // @0x14241bd80
        virtual void MakeObject(Value& result, Traits& t);
    };

    class Boolean : public CTraits
    {
    public:
        Boolean(VM& vm, const ClassInfo& ci);
        // @0x142414d30
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Boolean"; }
        // @0x14241be20
        virtual void MakeObject(Value& result, Traits& t);
    };

    class Catch : public CTraits
    {
    public:
        Catch(VM& vm, const ClassInfo& ci);
        // @0x142414d70
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::Catch"; }
        // @0x14241be30
        virtual void MakeObject(Value& result, Traits& t);
    };

    class Date : public CTraits
    {
    public:
        Date(VM& vm, const ClassInfo& ci);
        // @0x142414dc0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Date"; }
        // @0x14241beb0
        virtual void MakeObject(Value& result, Traits& t);
    };

    class Error : public CTraits
    {
    public:
        Error(VM& vm, const ClassInfo& ci);
        // @0x142414e10
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Error"; }
        // @0x14241bf20
        virtual void MakeObject(Value& result, Traits& t);
    };

    class Namespace : public CTraits
    {
    public:
        Namespace(VM& vm, const ClassInfo& ci);
        // @0x142414ef0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::Namespace"; }
        // @0x14241c040
        virtual void MakeObject(Value& result, Traits& t);

    public:
        Ptr<NamespaceInstanceFactory> InstanceFactory;    // +0xe8
    };

    class Number : public CTraits
    {
    public:
        Number(VM& vm, const ClassInfo& ci);
        // @0x142414f20
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Number"; }
        // @0x14241c050
        virtual void MakeObject(Value& result, Traits& t);
    };

    class QName : public CTraits
    {
    public:
        QName(VM& vm, const ClassInfo& ci);
        // @0x142414f90
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::QName"; }
        // @0x14241c0c0
        virtual void MakeObject(Value& result, Traits& t);
    };

    class RegExp : public CTraits
    {
    public:
        RegExp(VM& vm, const ClassInfo& ci);
        // @0x142415000
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::RegExp"; }
        // @0x14241c160
        virtual void MakeObject(Value& result, Traits& t);
    };

    class String : public CTraits
    {
    public:
        String(VM& vm, const ClassInfo& ci);
        // @0x142415050
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::String"; }
        // @0x14241c1f0
        virtual void MakeObject(Value& result, Traits& t);
    };

    class XML : public CTraits
    {
    public:
        XML(VM& vm, const ClassInfo& ci);
        // @0x142415110
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::XML"; }
        // @0x14241c230
        virtual void MakeObject(Value& result, Traits& t);
    };

    class XMLList : public CTraits
    {
    public:
        XMLList(VM& vm, const ClassInfo& ci);
        // @0x142415150
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::XMLList"; }
        // @0x14241c2b0
        virtual void MakeObject(Value& result, Traits& t);
    };

    class int_ : public CTraits
    {
    public:
        int_(VM& vm, const ClassInfo& ci);
        // @0x142415190
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::int_"; }
        // @0x14241c330
        virtual void MakeObject(Value& result, Traits& t);
    };

    class uint : public CTraits
    {
    public:
        uint(VM& vm, const ClassInfo& ci);
        // @0x1424151c0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::uint"; }
        // @0x14241c340
        virtual void MakeObject(Value& result, Traits& t);
    };

}}

namespace Classes { namespace fl
{
    class Object : public Class
    {
    public:
        Object(ClassTraits::Traits& t);
        // @0x142414f40
        virtual const char* GetAS3ObjectType() const { return "Classes::Object"; }
        // @0x142405a40
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407560
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142417f60
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class Array : public Class
    {
    public:
        Array(ClassTraits::Traits& t);
        // @0x142414ce0
        virtual const char* GetAS3ObjectType() const { return "Classes::Array"; }
        // @0x1424054e0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142417800
        virtual void InitPrototype(AS3::Object& obj) const;
        // @0x14241c350
        virtual Pickable<AS3::Object> MakePrototype() const;

    public:
        UInt32  CASEINSENSITIVE;       // +0x50
        UInt32  DESCENDING;            // +0x54
        UInt32  UNIQUESORT;            // +0x58
        UInt32  RETURNINDEXEDARRAY;    // +0x5c
        UInt32  NUMERIC;               // +0x60
    };

    class Boolean : public Class
    {
    public:
        Boolean(ClassTraits::Traits& t);
        // @0x142414d20
        virtual const char* GetAS3ObjectType() const { return "Classes::Boolean"; }
        // @0x1424055c0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407120
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142417a30
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class Catch : public Class
    {
    public:
        Catch(ClassTraits::Traits& t);
        // @0x142414d60
        virtual const char* GetAS3ObjectType() const { return "Classes::fl::Catch"; }
    };

    class Date : public Class
    {
    public:
        Date(ClassTraits::Traits& t);
        // @0x142414db0
        virtual const char* GetAS3ObjectType() const { return "Classes::Date"; }
        // @0x142405670
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x14241c400
        virtual Pickable<AS3::Object> MakePrototype() const;
    };

    class Error : public Class
    {
    public:
        Error(ClassTraits::Traits& t);
        // @0x142414e00
        virtual const char* GetAS3ObjectType() const { return "Classes::Error"; }
        // @0x142405780
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142417b40
        virtual void InitPrototype(AS3::Object& obj) const;
        // @0x14241c4d0
        virtual Pickable<AS3::Object> MakePrototype() const;

        // native methods
        // @0x142428b20
        void getErrorMessage(ASString& result, SInt32);
    };

    class Math : public Class
    {
    public:
        Math(ClassTraits::Traits& t);
        // @0x142414eb0
        virtual const char* GetAS3ObjectType() const { return "Classes::Math"; }
        // @0x1424059b0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x1424072f0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);

        // native methods
        // @0x1424274f0
        void abs(Value::Number& result, Value::Number);
        // @0x142427540
        void acos(Value::Number& result, Value::Number);
        // @0x142427a60
        void asin(Value::Number& result, Value::Number);
        // @0x142427b90
        void atan(Value::Number& result, Value::Number);
        // @0x142427a80
        void atan2(Value::Number& result, Value::Number, Value::Number);
        // @0x142427bb0
        void ceil(Value::Number& result, Value::Number);
        // @0x142427c10
        void cos(Value::Number& result, Value::Number);
        // @0x142428470
        void exp(Value::Number& result, Value::Number);
        // @0x1424284a0
        void floor(Value::Number& result, Value::Number);
        // @0x1424294d0
        void log(Value::Number& result, Value::Number);
        // @0x142429d40
        void pow(Value::Number& result, Value::Number, Value::Number);
        // @0x142429fb0
        void random(Value::Number& result);
        // @0x142429fe0
        void round(Value::Number& result, Value::Number);
        // @0x14242afc0
        void sin(Value::Number& result, Value::Number);
        // @0x14242b090
        void sqrt(Value::Number& result, Value::Number);
        // @0x14242b0b0
        void tan(Value::Number& result, Value::Number);

    public:
        Value::Number LN10;      // +0x50
        Value::Number E;
        Value::Number LN2;
        Value::Number LOG10E;
        Value::Number LOG2E;
        Value::Number PI;
        Value::Number SQRT1_2;
        Value::Number SQRT2;   // +0x88
    };

    class Namespace : public Class
    {
    public:
        Namespace(ClassTraits::Traits& t);
        // @0x142414ee0
        virtual const char* GetAS3ObjectType() const { return "Classes::Namespace"; }
        // @0x142405a00
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407340
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142417d40
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class Number : public Class
    {
    public:
        Number(ClassTraits::Traits& t);
        // @0x142414f10
        virtual const char* GetAS3ObjectType() const { return "Classes::Number"; }
        // @0x142405a20
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407480
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142417e50
        virtual void InitPrototype(AS3::Object& obj) const;

    public:
        Value::Number NaN;                  // +0x50
        Value::Number NEGATIVE_INFINITY;
        Value::Number POSITIVE_INFINITY;
        Value::Number MIN_VALUE;
        Value::Number MAX_VALUE;            // +0x70
    };

    class QName : public Class
    {
    public:
        QName(ClassTraits::Traits& t);
        // @0x142414f80
        virtual const char* GetAS3ObjectType() const { return "Classes::QName"; }
        // @0x142405a60
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x1424076a0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142418070
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class RegExp : public Class
    {
    public:
        RegExp(ClassTraits::Traits& t);
        // @0x142414ff0
        virtual const char* GetAS3ObjectType() const { return "Classes::RegExp"; }
        // @0x142405a80
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142418160
        virtual void InitPrototype(AS3::Object& obj) const;
        // @0x14241c560
        virtual Pickable<AS3::Object> MakePrototype() const;
    };

    class String : public Class
    {
    public:
        String(ClassTraits::Traits& t);
        // @0x142415040
        virtual const char* GetAS3ObjectType() const { return "Classes::String"; }
        // @0x142405ae0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407730
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142418250
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class XML : public Class
    {
    public:
        XML(ClassTraits::Traits& t);
        // @0x142415100
        virtual const char* GetAS3ObjectType() const { return "Classes::fl::XML"; }
        // @0x142405b00
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x1424077a0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142418390
        virtual void InitPrototype(AS3::Object& obj) const;

        // native methods
        // @0x1423ff120
        void settings(SPtr<Instances::fl::Object>& result);

    public:
        bool    ignoreComments;                 // +0x50
        bool    ignoreProcessingInstructions;
        bool    ignoreWhitespace;
        bool    prettyPrinting;
        SInt32  prettyIndent;                   // +0x54
    };

    class XMLList : public Class
    {
    public:
        XMLList(ClassTraits::Traits& t);
        // @0x142415140
        virtual const char* GetAS3ObjectType() const { return "Classes::XMLList"; }
        // @0x142405b90
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407bf0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x1424184b0
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class int_ : public Class
    {
    public:
        int_(ClassTraits::Traits& t);
        // @0x142415180
        virtual const char* GetAS3ObjectType() const { return "Classes::int_"; }
        // @0x142405bb0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407c80
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x1424185d0
        virtual void InitPrototype(AS3::Object& obj) const;

    public:
        SInt32  MIN_VALUE;  // +0x50
        SInt32  MAX_VALUE;  // +0x54
    };

    class uint : public Class
    {
    public:
        uint(ClassTraits::Traits& t);
        // @0x1424151b0
        virtual const char* GetAS3ObjectType() const { return "Classes::uint"; }
        // @0x142405bd0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407d30
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x1424186e0
        virtual void InitPrototype(AS3::Object& obj) const;

    public:
        UInt32  MIN_VALUE;  // +0x50
        UInt32  MAX_VALUE;  // +0x54
    };

}}

namespace ClassTraits { namespace fl
{
    class ArgumentError : public Traits
    {
    public:
        ArgumentError(VM& vm);
        // @0x142414cc0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ArgumentError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Array : public Traits
    {
    public:
        Array(VM& vm);
        // @0x142414cd0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl::Array"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Boolean : public Traits
    {
    public:
        Boolean(VM& vm);
        // @0x142414d10
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Boolean"; }
        // @0x1424060c0
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Catch : public Traits
    {
    public:
        Catch(VM& vm);
        // @0x142414d50
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Catch"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Date : public Traits
    {
    public:
        Date(VM& vm);
        // @0x142414da0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Date"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class DefinitionError : public Traits
    {
    public:
        DefinitionError(VM& vm);
        // @0x142414de0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::DefinitionError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Error : public Traits
    {
    public:
        Error(VM& vm);
        // @0x142414df0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Error"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class EvalError : public Traits
    {
    public:
        EvalError(VM& vm);
        // @0x142414e30
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::EvalError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class int_ : public Traits
    {
    public:
        int_(VM& vm);
        // @0x142415170
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::int_"; }
        // @0x1424062d0
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Math : public Traits
    {
    public:
        Math(VM& vm);
        // @0x142414ea0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Math"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Namespace : public Traits
    {
    public:
        Namespace(VM& vm);
        // @0x142414ed0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Namespace"; }
        // @0x1424061b0
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Number : public Traits
    {
    public:
        Number(VM& vm);
        // @0x142414f00
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Number"; }
        // @0x142406210
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Object : public Traits
    {
    public:
        Object(VM& vm);
        // @0x142414f30
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Object"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class QName : public Traits
    {
    public:
        QName(VM& vm);
        // @0x142414f70
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl::QName"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class RangeError : public Traits
    {
    public:
        RangeError(VM& vm);
        // @0x142414fc0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::RangeError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ReferenceError : public Traits
    {
    public:
        ReferenceError(VM& vm);
        // @0x142414fd0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ReferenceError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class RegExp : public Traits
    {
    public:
        RegExp(VM& vm);
        // @0x142414fe0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::RegExp"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SecurityError : public Traits
    {
    public:
        SecurityError(VM& vm);
        // @0x142415020
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SecurityError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class String : public Traits
    {
    public:
        String(VM& vm);
        // @0x142415030
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::String"; }
        // @0x142406220
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SyntaxError : public Traits
    {
    public:
        SyntaxError(VM& vm);
        // @0x142415060
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SyntaxError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TypeError : public Traits
    {
    public:
        TypeError(VM& vm);
        // @0x142415080
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TypeError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class uint : public Traits
    {
    public:
        uint(VM& vm);
        // @0x1424151a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::uint"; }
        // @0x1424062e0
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class UninitializedError : public Traits
    {
    public:
        UninitializedError(VM& vm);
        // @0x1424150a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::UninitializedError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URIError : public Traits
    {
    public:
        URIError(VM& vm);
        // @0x142415090
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URIError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class VerifyError : public Traits
    {
    public:
        VerifyError(VM& vm);
        // @0x1424150e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::VerifyError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class XML : public Traits
    {
    public:
        XML(VM& vm);
        // @0x1424150f0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl::XML"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class XMLList : public Traits
    {
    public:
        XMLList(VM& vm);
        // @0x142415130
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl::XMLList"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

}}


}}} // namespace Scaleform::GFx::AS3

#endif
