// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_FL_H
#define MS2_SF_GFX_AS3_OBJ_FL_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// E4X in-scope namespace list (as3_obj_e4x.h).
class NamespaceArray;

namespace InstanceTraits { class ThunkFunction; }
namespace InstanceTraits { namespace fl { class GlobalObject; } }   // (sfr24) GlobalObjectCPP's ctor
namespace Classes { class Function; }
namespace Classes { namespace fl { class Object; } }

namespace Instances {
    // A native thunk wrapped in a function object. 0x50 bytes.
    class ThunkFunction : public Instances::FunctionBase
    {
        friend class Classes::Function;
        friend class Classes::fl::Object;   // (appended, sfr22) Object::Construct inlines MakeThunkFunction

    protected:
        // (appended, sfr19)
        ThunkFunction(InstanceTraits::Traits& t, const ThunkInfo& thunk, const Traits& ot)
            : FunctionBase(t)
            , Function(thunk)
            , OriginationTraits(&ot)
        {
        }

    public:
        // (appended, sfr19) also visits the origination traits. 0x14240c160
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // (appended, sfr19) slot 21. 0x14240ad20
        virtual void ExecuteUnsafe(const Value& _this, Value& result, unsigned argc, const Value* argv);
        // (appended, sfr19) slot 22. 0x14240a9a0
        virtual void Execute(const Value& _this, unsigned argc, const Value* argv, bool discard_result = false);

        // @0x1424291d0
        void length(Value& result, unsigned, const Value*);

        const ThunkInfo& GetThunk() const { return Function; }
        // (appended, sfr19) the traits the thunk came from (a prototype's class).
        const Traits& GetOriginationTraits() const { return *OriginationTraits; }

    protected:
        const ThunkInfo& Function;              // +0x40 (sfr17)
        SPtr<const Traits> OriginationTraits;   // +0x48 (sfr19)
    };

    // (appended, sfr19) a thunk function that checks the type of 'this' before the call. 0x58 bytes.
    class CheckTypeTF : public ThunkFunction
    {
        friend class Classes::Function;

    protected:
        CheckTypeTF(InstanceTraits::Traits& t, const ThunkInfo& thunk, const Class& data_type, const Traits& ot)
            : ThunkFunction(t, thunk, ot)
            , DataTypeClass(data_type)
        {
        }

    public:
        // slot 21. 0x14240aac0
        virtual void ExecuteUnsafe(const Value& _this, Value& result, unsigned argc, const Value* argv);
        // slot 22. 0x142409fd0
        virtual void Execute(const Value& _this, unsigned argc, const Value* argv, bool discard_result = false);

    private:
        const Class& DataTypeClass;             // +0x50
    };

    // (appended, sfr22) a function closure of ABC code over the scope stack it was made in. 0x88 bytes,
    // vftable 0x14313f9b8 (constructor 0x1423ed090).
    class Function : public FunctionBase
    {
    public:
        // (appended, sfr22) a closure over ss called on stored_this unless given a this. 0x1423ed090
        Function(InstanceTraits::Traits& t, const ScopeStackType& ss, const Value& stored_this, const ASString& name);
        // (appended, sfr22) 0x1423f0eb0
        ~Function();

        // @0x14240bea0
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // (appended, sfr22) slot 21: runs the call to completion. 0x14240ac30
        virtual void ExecuteUnsafe(const Value& _this, Value& result, unsigned argc, const Value* argv);
        // (appended, sfr22) slot 22: pushes a call frame of the method body on the bound or the given this.
        // 0x14240a1c0
        virtual void Execute(const Value& _this, unsigned argc, const Value* argv, bool discard_result = false);
        // (appended, sfr22) slot 15: the scope stack the closure was made in. 0x142416ff0
        virtual void* Unk15();
        // (appended, sfr22) slot 23: the parameter count of the method of the closure's body. 0x142415e70
        virtual UInt32 GetMaxParamNum() const;

    private:
        ScopeStackType  StoredScopeStack;   // +0x40
        Value           StoredThis;         // +0x60 'this' for a call that passes none (undefined unless bound)
        ASString        Name;               // +0x80
    };
}

// (appended, sfr19) the traits of AS3 (ABC) function closures; GetFunctionName names an anonymous one
// "Function-<hex id>" (body in sfr_as3_04). A VMAbcFile caches them by method index.
namespace InstanceTraits {
    class Function : public CTraits
    {
    public:
        // (appended, sfr22) the traits of a closure of method mi of file; its body's own slots come first.
        // 0x1423ecfa0
        Function(VMAbcFile& file, const ClassInfo& ci, SInt32 mi, Instances::fl::GlobalObjectScript* gos);
        // (appended, sfr22) traits that belong to no ABC file. 0x1423ecf50
        Function(VM& vm, const ClassInfo& ci);

        // (appended, sfr22) sizeof(Instances::Function). 0x142415ad0
        virtual unsigned GetFixedMemSize() const;
        // (appended, sfr22) 0x14241bf50
        virtual void MakeObject(Value& result, Traits& t);

        ASString GetFunctionName(const Value& _this) const;
        SInt32 GetMethodInfoInd() const { return MethodInfoInd; }
        // (appended, sfr22) @0x14240be40
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;

    public:
        SInt32 MethodInfoInd;   // +0xe8
        // (appended, sfr22)
        SPtr<VMAbcFile>                         File;   // +0xf0
        SPtr<Instances::fl::GlobalObjectScript> GOS;    // +0xf8

    private:
        // (appended, sfr22) the "prototype" slot and the apply/call/length methods. 0x14241e5d0
        void RegisterSlots();
    };
}

// (appended, sfr19) the traits of the class Function keep the traits of the native function kinds.
namespace ClassTraits {
    class Function : public Traits
    {
    public:
        // (appended, sfr22) also makes the class Function and the traits of the native function kinds. 0x1423eca40
        Function(VM& vm, const ClassInfo& ci);

        InstanceTraits::Traits& GetThunkTraits() const         { return *ThunkTraits; }
        InstanceTraits::ThunkFunction& GetThunkFunctionTraits() const { return *ThunkFunctionTraits; }
        InstanceTraits::Traits& GetMethodIndTraits() const     { return *MethodIndTraits; }
        InstanceTraits::Traits& GetVTableTraits() const        { return *VTableTraits; }
        // (appended, sfr22) @0x14240bdb0
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // (appended, sfr22) function kinds (and objects with function instance traits) pass as they are.
        // @0x142406140
        virtual bool Coerce(const Value& value, Value& result) const;
        // @0x1424062f0
        bool CoerceValue(const Value& value, Value& result) const;

    private:
        SPtr<InstanceTraits::Traits>        ThunkTraits;            // +0xc8
        SPtr<InstanceTraits::ThunkFunction> ThunkFunctionTraits;    // +0xd0
        SPtr<InstanceTraits::Traits>        MethodIndTraits;        // +0xd8
        SPtr<InstanceTraits::Traits>        VTableTraits;           // +0xe0
    };
}

// (appended, sfr19) the class Function makes the function objects of native thunks.
namespace Classes {
    class Function : public Class
    {
    public:
        // (appended, sfr22)
        explicit Function(ClassTraits::Traits& t) : Class(t) {}

        const ClassTraits::Function& GetClassTraits() const
        {
            return static_cast<const ClassTraits::Function&>(Class::GetClassTraits());
        }

        // 0x14241c600
        Pickable<Instances::ThunkFunction> MakeThunkFunction(const ThunkInfo& thunk, const Traits& ot) const;
        // 0x142419d90
        Pickable<Instances::CheckTypeTF> MakeCheckTypeInstance(const Class& data_type, const ThunkInfo& thunk,
                                                               const Traits& ot) const;
        // (appended, sfr22) slot 12: a function body source throws error 1066; new Function() is a plain class construct. 0x1424071c0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // (appended, sfr22) slot 10: Function(...) is new Function(...). 0x1424057a0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // (appended, sfr22) slot 24. 0x142417c30
        virtual void InitPrototype(AS3::Object& obj) const;
        // (appended, sfr22) slot 25: the prototype is an empty function. 0x14241c500
        virtual Pickable<AS3::Object> MakePrototype() const;
    };
}

namespace Instances { namespace fl {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class GlobalObject : public Instances::fl::Object
    {
    public:
        // (appended, sfr22) 0x1423ed230
        GlobalObject(InstanceTraits::Traits& t);
        // (appended, sfr22) user-declared: the sdtors re-store the vftable (0x1423f32b0)
        virtual ~GlobalObject() {}
        // (appended, sfr19)
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::GlobalObject"; }
        // (appended, sfr19) slot 21: runs the script behind the global object; nothing for the C++ one. 0x14240a4a0
        virtual void Execute() { }
    protected:
        // (appended, sfr19) global objects are not constructible (body in sfr_as3_03).
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // (appended, sfr22) global objects are not callable either. 0x1424058a0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
    };

    // MS2-FUNCTIONAL: the registration hash at +0x38 is kept opaque (sfr22: the other members follow the exe's constructor
    // 0x1423ed260)
    class GlobalObjectCPP : public Instances::fl::GlobalObject
    {
    public:
        // (appended, sfr22) registers the builtin classes, binds the core ones and adds the global functions and
        // constants. 0x1423ed260
        GlobalObjectCPP(VM& vm, InstanceTraits::fl::GlobalObject& t);
        // (appended, sfr22) 0x1423f0fc0
        virtual ~GlobalObjectCPP();
        // (appended, sfr22) a fixed slot named after class cl in the public namespace, holding cl. 0x142403ca0
        void AddFixedSlot(Class& cl);
        // (appended, sfr22) a fixed slot prop_name/ns of type ctr holding v, also registered as a class of the VM; index
        // receives its slot index. 0x142403d70
        const SlotInfo& AddFixedSlotValuePair(const ASString& prop_name, Pickable<const Instances::Namespace> ns,
                                              const ClassTraits::Traits* ctr, const Value& v, UPInt& index);
        // (appended, sfr22) visits the class traits table. 0x14240bf10
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // (appended, sfr19)
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::GlobalObjectCPP"; }
        // (appended, sfr19) binds a registered builtin class on its first public lookup. 0x142418be0
        virtual const SlotInfo* InitializeOnDemand(const SlotInfo* si, const ASString& name,
                                                   const Instances::Namespace& ns, UPInt& index);
        // @0x142427bd0
        void clearInterval(const Value& result, UInt32);
        // @0x142427bf0
        void clearTimeout(const Value& result, UInt32);
        // @0x142427cf0
        void decodeURI(ASString& result, const ASString&);
        // @0x142427e00
        void decodeURIComponent(ASString& result, const ASString&);
        // @0x142428110
        void describeType(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x142428140
        void encodeURI(ASString& result, const ASString&);
        // @0x142428210
        void encodeURIComponent(ASString& result, const ASString&);
        // @0x1424282f0
        void escape(Value& result, unsigned, const Value*);
        // @0x142428460
        void escapeMultiByte(ASString& result, const ASString&);
        // @0x142428890
        void fscommand(Value& result, unsigned, const Value*);
        // @0x142428a80
        void getDefinitionByName(Value& result, const ASString&);
        // @0x142428b70
        void getQualifiedClassName(ASString& result, const Value&);
        // @0x142428be0
        void getQualifiedSuperclassName(Value& result, const Value&);
        // @0x142428d70
        void getTimer(SInt32& result);
        // @0x142428f30
        void isFinite(bool& result, Value::Number);
        // @0x142428f60
        void isNaN(bool& result, Value::Number);
        // @0x142428fa0
        void isXMLName(bool& result, const Value&);
        // @0x142429af0
        void parseFloat(Value::Number& result, const ASString&);
        // @0x142429bd0
        void parseInt(Value& result, unsigned, const Value*);
        // @0x142429dc0
        void print(Value& result, unsigned, const Value*);
        // @0x14242a0c0
        void setInterval(Value& result, unsigned, const Value*);
        // @0x14242ae30
        void setTimeout(Value& result, unsigned, const Value*);
        // @0x14242b410
        void trace(Value& result, unsigned, const Value*);
        // @0x14242b590
        void unescape(Value& result, unsigned, const Value*);
        // @0x14242b700
        void unescapeMultiByte(ASString& result, const ASString&);

        // (appended, sfr22)
        void*                   CIRegistrationHash;     // +0x38 builtin ClassInfo by name (not recovered)
        const Value::Number     PositiveInfinity;       // +0x40
        const Value::Number     NegativeInfinity;       // +0x48
        const Value::Number     NaN;                    // +0x50
        const Value             undefined;              // +0x58
        const UInt32            HIDE_NSURI_METHODS;     // +0x78
        const UInt32            INCLUDE_BASES;          // +0x7c
        const UInt32            INCLUDE_INTERFACES;     // +0x80
        const UInt32            INCLUDE_VARIABLES;      // +0x84
        const UInt32            INCLUDE_ACCESSORS;      // +0x88
        const UInt32            INCLUDE_METHODS;        // +0x8c
        const UInt32            INCLUDE_METADATA;       // +0x90
        const UInt32            INCLUDE_CONSTRUCTOR;    // +0x94
        const UInt32            INCLUDE_TRAITS;         // +0x98
        const UInt32            USE_ITRAITS;            // +0x9c
        const UInt32            HIDE_OBJECT;            // +0xa0
        const UInt32            FLASH10_FLAGS;          // +0xa4
        ValueArray              Values;                 // +0xa8 the fixed slot values
        ArrayLH<SPtr<ClassTraits::Traits> > CTraits;    // +0xc0
    };

    // An E4X node. The base class is also the node of kind kNone; the element, attribute, text, comment and
    // processing-instruction nodes derive from it (as3_obj_e4x.h). 0x48 bytes; vftable 0x1431429d0 (57 slots).
    class XML : public Instances::fl::Object
    {
    public:
        enum Kind { kNone, kElement, kText, kComment, kInstruction, kAttr };

        // Text is the empty string. 0x1423efc90
        explicit XML(InstanceTraits::Traits& t);
        // 0x1423efce0
        XML(InstanceTraits::Traits& t, const ASString& text, XML* parent = NULL);
        // ??_G 0x1423f4bd0
        virtual ~XML() {}

        // @0x14240c240
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142415120
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::XML"; }
        // @0x142422070
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);
        // @0x142409100
        virtual CheckResult DeleteProperty(const Multiname& prop_name);
        // @0x1424163b0
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;
        // @0x1424161a0
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;
        // @0x142416670
        virtual void GetNextPropertyValue(Value& value, GlobalSlotIndex ind);

        // The E4X node interface (slots 21-56). The overloads sit in reverse declaration order (23/24, 37/38).
        // @0x142415c00
        virtual const NamespaceArray* GetInScopeNamespaces() const { return NULL; }
        // @0x142403fe0
        virtual void AddInScopeNamespace(const Instances::Namespace& ns) {}
        // @0x142404d70
        virtual void AppendChild(const SPtr<XML>& child) {}
        // @0x142404d60
        virtual CheckResult AppendChild(const Value& child) { return true; }
        // @0x142425a20
        virtual void ToString(StringBuffer& buf, SInt32 ident);
        // @0x142425d00
        virtual void ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                 const NamespaceArray* usedNotDeclared);
        // @0x142415d80
        virtual Kind GetKind() const { return kNone; }
        // @0x142409a60
        virtual Boolean3 EqualsInternal(const XML& other);
        // @0x142417690
        virtual bool HasSimpleContent() const { return false; }
        // @0x142417320
        virtual bool HasOwnProperty(const ASString& p) { return false; }
        // @0x142415fc0
        virtual const ASString& GetName() const { return Text; }
        // the public namespace. 0x142415fd0
        virtual const Instances::Namespace& GetNamespace() const;
        // @0x142421c30
        virtual void SetNamespace(Instances::Namespace& ns) {}
        // @0x142421b40
        virtual void SetNamespace2(Instances::Namespace& ns) {}
        // the public namespace. 0x142415700
        virtual Instances::Namespace& GetCurrNamespace() const;
        // @0x1424087b0
        virtual Pickable<XML> DeepCopy(XML* parent);
        // (sfr22) declared in this order: the overloads' vftable slots run in reverse (Kind form at +0x128).
        // @0x142415300
        virtual void GetChildren(Instances::fl::XMLList& list, const Multiname& prop_name) {}
        // @0x142415310
        virtual void GetChildren(Instances::fl::XMLList& list, Kind k, const ASString* name = NULL) {}
        // the index in Parent's children. 0x1424152a0
        virtual CheckResult GetChildIndex(UPInt& ind) const { return false; }
        // @0x1424157c0
        virtual void GetDescendants(Instances::fl::XMLList& list, const Multiname& prop_name) {}
        // @0x142419260
        virtual CheckResult InsertChildAt(UPInt pos, const Value& child) { return false; }
        // @0x142419190
        virtual CheckResult InsertChildAfter(const Value& child1, const Value& child2) { return false; }
        // @0x1424197e0
        virtual CheckResult InsertChildBefore(const Value& child1, const Value& child2) { return false; }
        // all children when child is NULL. 0x142408f40
        virtual void DeleteChildren(XML* child) {}
        // @0x142408ec0
        virtual void DeleteByIndex(UPInt ind) {}
        // @0x1424151d0
        virtual void GetAttributes(Instances::fl::XMLList& list) {}
        // @0x142416c40
        virtual SPtr<Instances::fl::QName> GetQName() { return SPtr<Instances::fl::QName>(); }
        // @0x14241d570
        virtual void Normalize() {}
        // lp: the node at which the lookup stops. 0x14240b200
        virtual Instances::Namespace* FindNamespaceByPrefix(const ASString& prefix, XML* lp) const;
        // @0x14240b380
        virtual Instances::Namespace* FindNamespaceByURI(const ASString& uri, XML* lp) const;
        // the prefixes used below this node and not declared up to lp. 0x142420260
        virtual void ResolveNamespaces(HashSetDH<ASString>& nr, XML* lp) const {}
        // @0x14241efc0
        virtual XML* RemoveNamespace(const Value& ns) { return this; }
        // @0x14241f190
        virtual CheckResult Replace(const Multiname& prop_name, const Value& value) { return true; }
        // @0x1423f6860
        virtual CheckResult AS3Replace(const Multiname& prop_name, const Value& value) { return true; }
        // @0x142421770
        virtual void SetChildren(const Value& value) {}
        // Declared after the node interface so that MSVC appends this new overload as the last slot (56)
        // instead of grouping it with the Object override below.
        // this node itself for the name "0". 0x1424168a0
        virtual CheckResult GetProperty(const Multiname& prop_name, Instances::fl::XMLList& list);
        // @0x142416800
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);

        // (appended, sfr19) this node is named by prop_name (E4X name and namespace matching). 0x14241ca70
        bool Matches(const Multiname& prop_name) const;
        // (appended, sfr19) a new list targeting the prop_name child of this node: the name's namespace (or the
        // default one) replaced by the in-scope namespace with its URI; untargeted unless the name is a string.
        // 0x14241c880
        Pickable<XMLList> MakeXMLListInstance(const Multiname& mn);
        // (appended, sfr19) ident spaces, up to ten per append. 0x142404e10
        static void AddIndent(StringBuffer& buf, SInt32 ident);
        // (appended, sfr19) s with the five XML entities escaped. 0x142409f00
        static void EscapeElementValue(StringBuffer& buf, const ASString& s);
        // (appended, sfr19) s with the attribute entities (and tab/newline/return) escaped. 0x142409d80
        static void EscapeAttributeValue(StringBuffer& buf, const ASString& s);
        // (appended, sfr19) out of line. 0x142421f80
        void SetParent(XML* p);

    public:
        ASString    Text;       // +0x38 the name of an element/attribute/PI, the content of a text/comment
        SPtr<XML>   Parent;     // +0x40

    public:
        // @0x1423f6b10
        void AS3addNamespace(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423f6d10
        void AS3appendChild(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423f6de0
        void AS3attribute(SPtr<Instances::fl::XMLList>& result, const Value&);
        // @0x1423f7120
        void AS3attributes(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f7580
        void AS3child(SPtr<Instances::fl::XMLList>& result, const Value&);
        // @0x1423f7920
        void AS3childIndex(SInt32& result);
        // @0x1423f7a10
        void AS3children(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f7cd0
        void AS3comments(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f8170
        void AS3contains(bool& result, const Value&);
        // @0x1423f8270
        void AS3copy(SPtr<Instances::fl::XML>& result);
        // @0x1423f8600
        void AS3descendants(Value& result, unsigned, const Value*);
        // @0x1423f8aa0
        void AS3elements(Value& result, unsigned, const Value*);
        // @0x1423fa9a0
        void AS3hasComplexContent(bool& result);
        // @0x1423fac40
        void AS3hasOwnProperty(bool& result, const ASString&);
        // @0x1423fac60
        void AS3hasSimpleContent(bool& result);
        // @0x1423fad50
        void AS3inScopeNamespaces(SPtr<Instances::fl::Array>& result);
        // @0x1423fb270
        void AS3insertChildAfter(Value& result, const Value&, const Value&);
        // @0x1423fb360
        void AS3insertChildBefore(Value& result, const Value&, const Value&);
        // @0x1423fb870
        void AS3length(SInt32& result);
        // @0x1423fb890
        void AS3localName(ASString& result);
        // @0x1423fc360
        void AS3name(SPtr<Instances::fl::QName>& result);
        // @0x1423fc4b0
        void AS3namespaceDeclarations(SPtr<Instances::fl::Array>& result);
        // @0x1423fc960
        void AS3namespace_(Value& result, unsigned, const Value*);
        // @0x1423fca80
        void AS3nodeKind(ASString& result);
        // @0x1423fcb70
        void AS3normalize(SPtr<Instances::fl::XML>& result);
        // @0x1423fcc70
        void AS3parent(Value& result);
        // @0x1423fcdb0
        void AS3prependChild(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fcec0
        void AS3processingInstructions(Value& result, unsigned, const Value*);
        // @0x1423fd4f0
        void AS3propertyIsEnumerable(Value& result, unsigned, const Value*);
        // @0x1423fd7f0
        void AS3removeNamespace(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fdca0
        void AS3replace(SPtr<Instances::fl::XML>& result, const Value&, const Value&);
        // @0x1423fe250
        void AS3setChildren(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fe3e0
        void AS3setLocalName(const Value& result, const Value&);
        // @0x1423fe620
        void AS3setName(const Value& result, const Value&);
        // @0x1423fe930
        void AS3setNamespace(const Value& result, const Value&);
        // @0x1424018e0
        void AS3text(SPtr<Instances::fl::XMLList>& result);
        // @0x1424018c0 (sfr22)
        SPtr<Instances::fl::XMLList> AS3text();
        // (appended, sfr22) the value-returning forms the exe calls
        // @0x1423f6dc0
        SPtr<Instances::fl::XMLList> AS3attribute(const Value& arg);
        // @0x1423f7100
        SPtr<Instances::fl::XMLList> AS3attributes();
        // @0x1423f7560
        SPtr<Instances::fl::XMLList> AS3child(const Value& propertyName);
        // @0x1423f79f0
        SPtr<Instances::fl::XMLList> AS3children();
        // @0x1423f7cb0
        SPtr<Instances::fl::XMLList> AS3comments();
        // @0x1423fad30
        SPtr<Instances::fl::Array> AS3inScopeNamespaces();
        // @0x1423fc340
        SPtr<Instances::fl::QName> AS3name();
        // @0x1423fc490
        SPtr<Instances::fl::Array> AS3namespaceDeclarations();
        // @0x142402b70
        void AS3toString(ASString& result);
        // @0x142403250
        void AS3toXMLString(ASString& result);
        // @0x142403960
        void AS3valueOf(SPtr<Instances::fl::XML>& result);
        // @0x142429df0
        void prototypeGet(SPtr<Instances::fl::XMLList>& result);
        // @0x142429f90
        void prototypeSet(const Value& result, const Value&);
    };

}}

}}} // namespace Scaleform::GFx::AS3

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::Function) == 0xe8, "Function size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::Function) == 0x50, "Function size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::Function) == 0x100, "Function size");
static_assert(sizeof(Scaleform::GFx::AS3::Instances::fl::XML) == 0x48, "XML size");

#endif
