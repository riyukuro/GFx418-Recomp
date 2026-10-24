// Recovered Scaleform GFx 4.1.18 AS3: the virtual machine object (VM). Shared header of the src/ms2/scaleform units
// (sfr lane): append, do not reorder members.
//
// Layout from VM(FlashUI&, FileLoader&, StringManager&, ASRefCountCollector&) 0x1424dae90 (0x2d8 bytes) and the VM
// accessors (GetClassBoolean 0x142507e30, GetInternedNamespace 0x14250aa50, AddVMAbcFileWeak 0x1424eaf00). The 4.1.18
// VM has no Proxy namespace and no generic-class / alias tables; the execution stacks between +0x48 and +0x180 are kept
// opaque until recovered code needs their members. The vftable has two slots: the deleting destructor and one that
// returns 0.
#ifndef MS2_SF_GFX_AS3_VM_H
#define MS2_SF_GFX_AS3_VM_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes { namespace fl { class Array; class Boolean; class int_; class Number; class String; class uint; } }

// The VM's host interface (the movie's AS3 root implements it). 0x10 bytes, vftable 0x14317b648 (three slots); the
// byte code Tracer is one too (as3_tracer.h).
class FlashUI
{
public:
    // (sfr24) the debugger state; the Tracer runs with sStep
    enum StateType { sError, sBreakpoint, sPreStep, sStep };

    enum OutputMessageType
    {
        Output_Message,     // 0: trace()
        Output_Error,       // 1
        Output_Warning,     // 2: "not implemented" and other VM warnings
        Output_Action       // 3
    };

    // (sfr24) inline in the Tracer constructor 0x1424d9f30
    FlashUI() : CurrState(sError), NeedToCheck(false) {}
    virtual ~FlashUI() {}                                               // slot 0
    virtual void Output(OutputMessageType type, const char* msg) = 0;   // slot 1
    // (sfr24) called before each opcode while NeedToCheckOpCode()
    virtual bool OnOpCode(Abc::TCodeOffset offset) = 0;                 // slot 2

    StateType GetCurrState() const      { return CurrState; }
    bool      NeedToCheckOpCode() const { return NeedToCheck; }
    void      SetNeedToCheckOpCode(bool flag = true) { NeedToCheck = flag; }

protected:
    void SetCurrState(StateType s) { CurrState = s; }

    // (sfr24) not "State": MovieRoot derives from FlashUI, and GFx::State must stay visible in its members
    StateType CurrState;    // +0x08 (sfr24)
    bool      NeedToCheck;  // +0x0c (sfr24)
};
static_assert(sizeof(FlashUI) == 0x10, "FlashUI size");   // the deleting destructor 0x1424e2db0 frees 0x10
namespace Abc { class File; }
class XMLSupport;

// (appended, sfr19) the ABC files the VM loads on construction (the movie root's file list). vftable order from the
// VM constructor 0x1424dae90: GetSize is slot 1, GetFile(UPInt) slot 3.
class FileLoader
{
public:
    virtual ~FileLoader() {}                                            // slot 0
    virtual UPInt GetSize() const = 0;                                  // slot 1
    // overloads: MSVC gives the later declaration the earlier slot
    virtual const Ptr<Abc::File>& GetFile(UPInt n) = 0;                 // slot 3
    virtual const Abc::File* GetFile(const ASString& name) = 0;         // slot 2
    // (sfr33) no AddFile: the exe's empty loader (vftable 0x14317f470, MovieRoot) has these four slots only
};

namespace Instances { namespace fl { class GlobalObjectCPP; class Array; class XML; class XMLList; class QName; } }
namespace InstanceTraits { namespace fl { class GlobalObject; class Namespace; } }

class VM : public NewOverrideBase<StatMV_VM_VM_Mem>
{
public:
    VM(FlashUI& ui, FileLoader& loader, StringManager& string_manager, ASRefCountCollector& gc);
    virtual ~VM();                      // slot 0
    virtual void* Unk01() { return 0; } // slot 1 (returns 0)

    StringManager&          GetStringManager() const    { return StringManagerRef; }
    const XMLSupport&       GetXMLSupport() const       { return *XMLSupport_; }   // (appended, sfr15)
    ASRefCountCollector&    GetGC() const               { return *GC; }
    RefCountCollector<StatMV_ActionScript_Mem>* GetGCPtr() const;
    MemoryHeap*             GetMemoryHeap() const       { return MHeap; }
    // (appended, sfr19) remembers file (not owned) unless the VM is being destroyed. 0x1424eaf00
    void AddVMAbcFileWeak(VMAbcFile* file);
    // (appended, sfr19) adds tr to the VM's class set under its name and namespace. 0x1425210e0
    void RegisterClassTraits(ClassTraits::Traits& tr);
    FlashUI&                GetUI() const               { return UI; }
    Pickable<Instances::fl::Array> MakeArray() const;    // 0x142516270
    Pickable<Instances::fl::Object> MakeObject() const;  // 0x142516600 (appended, sfr15)
    FileLoader&             GetFileLoader() const       { return Loader; }
    bool                    IsException() const         { return HandleException; }

    // The call stack as text, one frame per line, each line prefixed with line_pref.
    void GetStackTraceASString(ASString& result, const char* line_pref = "\t");

    // The string conversion of v (ToString semantics).
    ASString AsString(const Value& v);              // 0x1424ed770

    // Script errors: the ids the recovered code throws (the Flash Player error numbers).
    enum ErrorID
    {
        eNotImplementedError        = 1001,
        eConvertNullToObjectError   = 1009,
        eInvalidEnumError           = 1058,
        eWrongArgumentCountError    = 1063,
        eInvalidRangeError          = 1125,
        eNullArgumentError          = 1507,
        eInvalidArgumentError       = 1508,
        eShellCompressedDataError   = 1509,
        eParamRangeError            = 2006,
        eNullPointerError           = 2007,
        // (appended, sfr13)
        eCheckTypeFailedError       = 1034,
        eVectorFixedError           = 1126,
        // (appended, sfr14)
        eIllegalWriteError          = 1074,
        eInvalidBitmapData          = 2015,
        eInvalidPrecisionError      = 1002,
        eInvokeOnIncompatibleObjectError = 1004,
        // (appended, sfr15)
        eInvalidRadixError          = 1003,
        eUndefinedVarError          = 1065,
        eCallOfNonFunctionError     = 1006,
        eConstructOfNonFunctionError = 1007,
        eStackOverflowError         = 1023,
        eFunctionConstructorError   = 1066,
        eMathNotFunctionError       = 1075,
        eWriteSealedError           = 1056,
        eMathNotConstructorError    = 1076,
        // (appended, sfr17)
        eInvalidURIError            = 1052,
        // (appended, sfr19)
        eMustBeChildError           = 2025,
        eAddObjectItselfError       = 2024,
        eIllegalOperationError      = 2077,
        eEOFError                   = 2030,
        eOutOfRangeError            = 1506,
        eSceneNotFound              = 2108,
        eFrameLabelNotFoundInScene  = 2109,
        eInvalidEnumParamError      = 2008,
        // (appended, sfr19 Vector)
        eCorruptABCError            = 1107,
        eCoerceArgumentCountError   = 1112,
        eWrongTypeArgCountError     = 1128,
        // (appended, sfr19 Traits::Add2VT)
        eIllegalOverrideError       = 1053,
        // (appended, sfr19 E4X)
        eXMLAssignmentToIndexedXMLNotAllowed = 1087,
        eXMLIllegalCyclicalLoop     = 1118,
        eXMLAssigmentOneItemLists   = 1089,
        // (appended, sfr22)
        eXMLOnlyWorksWithOneItemLists = 1086,
        eXMLInvalidName             = 1117,
        eXMLNamespaceWithPrefixAndNoURI = 1098,
        // (appended, sfr33)
        eConvertUndefinedToObjectError = 1010,
        eNotConstructorError        = 1115
    };

    // An error being thrown: its id and the formatted message (0x10 bytes).
    class Error
    {
    public:
        Error(ErrorID id, VM& vm);                      // 0x1424d6b90
        Error(ErrorID id, VM& vm, const char* arg1);    // 0x1424d7850
        Error(ErrorID id, VM& vm, const char* arg1, const char* arg2);   // 0x1424d7690
        Error(ErrorID id, VM& vm, const char* arg1, int arg2, int arg3, int arg4);   // 0x1424d7bf0
        Error(ErrorID id, VM& vm, int arg1, int arg2);  // 0x1424d74d0
        Error(ErrorID id, VM& vm, int arg1);            // 0x1424d7330 (appended, sfr15)
        Error(ErrorID id, VM& vm, const Value& arg1, const char* arg2);   // 0x1424d7130 (appended, sfr19)
        Error(ErrorID id, VM& vm, const Value& arg1);   // 0x1424d6f40 (appended, sfr19)
        Error(ErrorID id, VM& vm, const Value& arg1, const Value& arg2);  // 0x1424d6cf0 (appended, sfr19)
        Error(ErrorID id, VM& vm, const char* arg1, const Value& arg2);   // 0x1424d79f0 (appended, sfr19)

        ErrorID         GetErrorID() const  { return ID; }
        const ASString& GetMessage() const  { return Message; }

    private:
        ErrorID     ID;         // +0x0
        ASString    Message;    // +0x8
    };

    // Raise e as an instance of the named error class.
    void ThrowArgumentError(const Error& e);        // 0x14252ec90
    void ThrowError(const Error& e);                // 0x14252eca0
    void ThrowEvalError(const Error& e);            // 0x14252efc0
    void ThrowMemoryError(const Error& e);          // 0x14252efd0
    void ThrowRangeError(const Error& e);           // 0x14252f1a0
    void ThrowReferenceError(const Error& e);       // 0x14252f1b0
    void ThrowSecurityError(const Error& e);        // 0x14252f1c0
    void ThrowSyntaxError(const Error& e);          // 0x14252f1d0
    void ThrowTypeError(const Error& e);            // 0x14252f1e0
    void ThrowURIError(const Error& e);             // 0x14252f1f0
    void ThrowUninitializedError(const Error& e);   // 0x14252f200
    void ThrowVerifyError(const Error& e);          // 0x14252f210

    // Raise v itself (an error object made by the caller).
    void Throw(const Value& v)  { HandleException = true; ExceptionObj.Assign(v); }
    // (sfr_as3_09) calls func on _this with argv; result receives the return value (0x1424fef00)
    void ExecuteInternalUnsafe(const Value& func, const Value& _this, Value& result, unsigned argc, const Value* argv,
                               bool discard_result);
    // (sfr_as3_09) prints the error e with its stack trace through the FlashUI (0x14251bdc0)
    void OutputError(const Value& e);
    // (sfr_as3_09) drops the pending exception after printing it
    void OutputAndIgnoreException();     // 0x14246c440
    // (appended, sfr19) ExecuteInternalUnsafe keeping the result; an exception is printed and dropped. 0x142500620
    void Execute_IgnoreExceptionUnsafe(const Value& func, const Value& _this, Value& result, unsigned argc,
                                       const Value* argv);
    // (appended, sfr19) runs the interpreter until the call stack drops below max_stack_depth frames. 0x1424fa5b0
    int ExecuteCode(unsigned max_stack_depth = 1);
    // (appended, sfr22) pushes a frame that runs method body mbi_ind of file on _this, or throws a stack overflow
    // once 128 frames are on the call stack. Only inlined (Instances::Function::Execute 0x14240a1c0); the body is
    // in as3_callframe.h.
    void AddFrame(const Value& invoker, VMAbcFile& file, SInt32 mbi_ind, const Value& _this, unsigned argc,
                  const Value* argv, bool discard_result, const ScopeStackType& saved_scope, const Traits& ot,
                  const ASString& name);

    // A new instance of the global class gname constructed with argv, stored in result; extCall marks a call from
    // C++ rather than from script (0x1424f0750).
    void Construct(const char* gname, Value& result, unsigned argc, const Value* argv, bool extCall);

    // A new instance of the builtin class gname ("flash.geom.Point"), constructed with argv. False on an exception.
    template <class C>
    CheckResult ConstructBuiltinObject(SPtr<C>& pobj, const char* gname, unsigned argc = 0, const Value* argv = NULL)
    {
        return constructBuiltinObject(reinterpret_cast<SPtr<Object>&>(pobj), gname, argc, argv);
    }
    CheckResult constructBuiltinObject(SPtr<Object>& pobj, const char* gname, unsigned argc, const Value* argv); // 0x142532130
    // The class object of the global class gname ("flash.geom.Vector3D"); NULL when there is none.
    Class* GetClass(const StringDataPtr& gname);    // 0x142507be0
    // (appended, sfr17) the instance traits of v's type (the traits of the boxed class for primitives).
    const InstanceTraits::Traits& GetInstanceTraits(const Value& v) const;  // 0x14250a900

    // (appended, sfr15) the class objects of the core classes (out of line; built on demand by the traits).
    Classes::fl::Array&   GetClassArray() const;      // 0x142507df0
    Classes::fl::Boolean& GetClassBoolean() const;    // 0x142507e30
    Classes::fl::int_&    GetClassSInt() const;       // 0x142507e70
    Classes::fl::Number&  GetClassNumber() const;     // 0x142507eb0
    Classes::fl::String&  GetClassString() const;     // 0x142507ef0
    Classes::fl::uint&    GetClassUInt() const;       // 0x142508100
    // (appended, sfr16) the Vector.<Number> class object (Classes::fl_vec::Vector_double is not recovered)
    Class& GetClassVectorNumber() const;    // 0x142508230
    // (appended, sfr19) the Vector.<int>, Vector.<uint> and Vector.<String> class objects
    Class& GetClassVectorSInt() const;      // 0x142508270
    Class& GetClassVectorString() const;    // 0x1425082b0
    Class& GetClassVectorUInt() const;      // 0x1425082f0
    // (appended, sfr19) the Vector class object (the generic __AS3__.vec.Vector)
    Class& GetClassVector() const;          // 0x1425081f0
    // (appended, sfr19) the class traits of v's type (Object for null). 0x142507f60
    const ClassTraits::Traits& GetClassTraits(const Value& v) const;
    // (appended, sfr19) the interned namespace of a kind and name (NULL: the empty name) (0x142516400).
    Pickable<Instances::Namespace> MakeInternedNamespace(Abc::NamespaceKind kind, const char* name) const;
    // (appended, sfr19) the same by an ASString or a StringDataPtr URI (0x1425162a0 / 0x142516340).
    Pickable<Instances::Namespace> MakeInternedNamespace(Abc::NamespaceKind kind, const ASString& uri) const;
    Pickable<Instances::Namespace> MakeInternedNamespace(Abc::NamespaceKind kind, const StringDataPtr& uri) const;
    // (appended, sfr19) a new (not interned) namespace instance (0x1425164c0).
    Pickable<Instances::Namespace> MakeNamespace(Abc::NamespaceKind kind, const ASString& uri, const Value& prefix) const;
    // Namespace instances interned by their kind and URI (0x14250aa50 / 0x14250aac0 / 0x14250ab50).
    Instances::Namespace& GetInternedNamespace(Abc::NamespaceKind kind, const ASString& uri) const;
    Instances::Namespace& GetInternedNamespace(Abc::NamespaceKind kind, const StringDataPtr& uri) const;
    Instances::Namespace& GetInternedNamespace(Abc::NamespaceKind kind, const char* uri) const;

    Instances::Namespace& GetPublicNamespace() const    { return *PublicNamespace; }
    // (appended, sfr19) the default xml namespace of the running call frame (frames are 0xa8 bytes, 64 to a
    // page; the call stack's size is Unk070[1], its page table Unk070[4]).
    Instances::Namespace* GetDefXMLNamespace() const
    {
        const UPInt i = Unk070[1] - 1;
        return *reinterpret_cast<Instances::Namespace* const*>(
            reinterpret_cast<const char* const*>(Unk070[4])[i >> 6] + (i & 0x3f) * 0xa8 + 0x58);
    }
    Instances::Namespace& GetAS3Namespace() const       { return *AS3Namespace; }
    Instances::Namespace& GetVectorNamespace() const    { return *VectorNamespace; }

    ClassTraits::Traits& GetClassTraitsClassClass() const   { return *TraitsClassClass; }
    ClassTraits::Traits& GetClassTraitsObject() const       { return *TraitsObject; }
    ClassTraits::Traits& GetClassTraitsNamespace() const    { return *TraitsNamespace; }
    ClassTraits::Traits& GetClassTraitsFunction() const     { return *TraitsFunction; }
    ClassTraits::Traits& GetClassTraitsBoolean() const      { return *TraitsBoolean; }
    ClassTraits::Traits& GetClassTraitsNumber() const       { return *TraitsNumber; }
    ClassTraits::Traits& GetClassTraitsSInt() const         { return *TraitsInt; }
    ClassTraits::Traits& GetClassTraitsUInt() const         { return *TraitsUint; }
    ClassTraits::Traits& GetClassTraitsString() const       { return *TraitsString; }
    ClassTraits::Traits& GetClassTraitsArray() const        { return *TraitsArray; }
    ClassTraits::Traits& GetClassTraitsNull() const         { return *TraitsNull; }
    ClassTraits::Traits& GetClassTraitsVoid() const         { return *TraitsVoid; }
    // (appended, sfr19) +0x270/+0x278 hold the instance traits of null and void (InstanceTraits::Anonimous/Void)
    InstanceTraits::Traits& GetITraitsNull() const { return *reinterpret_cast<InstanceTraits::Traits*>(TraitsNull.GetPtr()); }
    InstanceTraits::Traits& GetITraitsVoid() const { return *reinterpret_cast<InstanceTraits::Traits*>(TraitsVoid.GetPtr()); }
    // (appended, sfr33) the loaded ABC file whose source is name. 0x142502d00
    SPtr<VMAbcFile> FindVMAbcFileWeak(const char* name) const;
    // (appended, sfr33) appends every loaded ABC file to destArray; the count added (none while being destroyed).
    // 0x142507210
    UPInt GetAllLoadedAbcFiles(Scaleform::Array<SPtr<VMAbcFile> >* destArray) const;

public:
    bool                                    Initialized;        // +0x008
    bool                                    InDestructor;       // +0x009
    StringManager&                          StringManagerRef;   // +0x010
    ASRefCountCollector*                    GC;                 // +0x018
    FlashUI&                                UI;                 // +0x020
    FileLoader&                             Loader;             // +0x028
    UPInt                                   InInitializer;      // +0x030
    MemoryHeap*                             MHeap;              // +0x038
    SPtr<XMLSupport>                        XMLSupport_;        // +0x040
    UPInt                                   OpStack[5];         // +0x048 value stack (current page at +0x060)
    UPInt                                   Unk070[5];          // +0x070 zeroed by the constructor
    UPInt                                   CallStack[0x15];    // +0x098 paged call frame array (ctor 0x1424d6900)
    UPInt                                   RegisterFile[4];    // +0x140 (current page at +0x150)
    ArrayDH<Value>                          ScopeStack;         // +0x160
    bool                                    HandleException;    // +0x180
    Value                                   ExceptionObj;       // +0x188
    ArrayLH<SPtr<Instances::fl::GlobalObject> > GlobalObjects;  // +0x1a8
    VMAppDomain*                            SystemDomain;       // +0x1c0 (an SPtr; VMAppDomain is not modeled yet)
    TClassTraitsCache                       ClassTraitsSet;     // +0x1c8 class traits by {name, ns} (Resolve2Vector 0x142563380)
    SPtr<Instances::Namespace>          PublicNamespace;    // +0x1d0
    SPtr<Instances::Namespace>          AS3Namespace;       // +0x1d8
    SPtr<Instances::Namespace>          VectorNamespace;    // +0x1e0
    SPtr<Instances::Namespace>          XMLNamespace;       // +0x1e8
    SPtr<ClassTraits::Traits>               TraitsClassClass;   // +0x1f0
    SPtr<ClassTraits::Traits>               TraitsObject;       // +0x1f8
    SPtr<ClassTraits::Traits>               TraitsNamespace;    // +0x200
    SPtr<ClassTraits::Traits>               TraitsFunction;     // +0x208
    SPtr<ClassTraits::Traits>               TraitsBoolean;      // +0x210
    SPtr<ClassTraits::Traits>               TraitsNumber;       // +0x218
    SPtr<ClassTraits::Traits>               TraitsInt;          // +0x220
    SPtr<ClassTraits::Traits>               TraitsUint;         // +0x228
    SPtr<ClassTraits::Traits>               TraitsString;       // +0x230
    SPtr<ClassTraits::Traits>               TraitsArray;        // +0x238
    SPtr<ClassTraits::Traits>               Traits240;          // +0x240 Catch (ClassTraits::fl::Catch)
    SPtr<ClassTraits::Traits>               TraitsVector;       // +0x248
    SPtr<ClassTraits::Traits>               TraitsVector_int;   // +0x250
    SPtr<ClassTraits::Traits>               TraitsVector_uint;  // +0x258
    SPtr<ClassTraits::Traits>               TraitsVector_double; // +0x260
    SPtr<ClassTraits::Traits>               TraitsVector_String; // +0x268
    SPtr<ClassTraits::Traits>               TraitsNull;         // +0x270
    SPtr<ClassTraits::Traits>               TraitsVoid;         // +0x278
    SPtr<InstanceTraits::Traits>            NoFunctionTraits;   // +0x280 (0x100-byte traits)
    SPtr<InstanceTraits::Traits>            ActivationTraits;   // +0x288 (0xd0-byte traits)
    SPtr<InstanceTraits::fl::GlobalObject>  TraitaGlobalObject; // +0x290
    SPtr<Instances::fl::GlobalObjectCPP>    GlobalObject;       // +0x298 (0xd8 bytes)
    Value                                   GlobalObjectValue;  // +0x2a0
    ArrayLH_POD<VMAbcFile*, StatMV_VM_VM_Mem> VMAbcFilesWeak;   // +0x2c0
};

// E4X hooks of the VM (VM+0x40). The VM starts with this base (vftable 0x14317b7b8, no RTTI; its hooks do nothing)
// and swaps in the XML library's XMLSupportImpl, which overrides them. (appended, sfr15)
class XMLSupport : public GASRefCountBase
{
public:
    // (appended, sfr19) only inlined (VM constructor 0x1424dae90)
    XMLSupport(VM& vm, bool enabled = false) : GASRefCountBase(vm.GetGCPtr()), Enabled(enabled) {}
    virtual ~XMLSupport();                                                                              // slot 4
    virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;                                       // slot 0, 0x142504510 (appended, sfr19)

    // overloads: MSVC gives the later declaration the earlier slot
    virtual CheckResult EqualsXML(bool& result, Instances::fl::XML& l, Instances::fl::XML& r) const;    // slot 7
    virtual CheckResult EqualsXML(bool& stop, bool& result, Instances::fl::XML& l, const Value& r) const;  // slot 6
    virtual CheckResult EqualsXMLList(bool& result, Instances::fl::XMLList& l, const Value& v) const;   // slot 8
    virtual CheckResult EqualsQName(bool& result, Instances::fl::QName& l, Instances::fl::QName& r) const; // slot 9
    virtual bool Add(Value& result, Object& l, Object& r) const;                                        // slot 10
    virtual CheckResult ToXMLString(VM& vm, Value& v) const;                                            // slot 11
    virtual void DescribeType(VM& vm, SPtr<Instances::fl::XML>& result, const Value& value) const;      // slot 12
    virtual CheckResult GetDescendants(Value& v, const Multiname& mn) const;                            // slot 13
    virtual const ClassTraits::Traits* GetClassTraitsQName() const;                                     // slot 14
    virtual InstanceTraits::Traits* GetITraitsQName() const;                                            // slot 15
    virtual const ClassTraits::Traits* GetClassTraitsXML() const;                                       // slot 16
    virtual InstanceTraits::Traits* GetITraitsXML() const;                                              // slot 17
    virtual const ClassTraits::Traits* GetClassTraitsXMLList() const;                                   // slot 18
    virtual InstanceTraits::Traits* GetITraitsXMLList() const;                                          // slot 19
    // (appended, sfr22) GlobalObjectCPP constructor 0x1423ed260
    bool IsEnabled() const { return Enabled; }

private:
    bool                        Enabled;        // +0x20 (appended, sfr19)
};

// (appended, sfr19) the E4X-enabled support: makes and registers the QName, XML and XMLList class traits.
// vftable 0x14317f9e0 (no RTTI).
class XMLSupportImpl : public XMLSupport
{
public:
    XMLSupportImpl(VM& vm);     // 0x1424dc160
    virtual ~XMLSupportImpl();                                                                          // 0x1424e4190
    virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;                                       // 0x142504520
    // E4X-enabled VM override of the base no-op.
    virtual bool Add(Value& result, Object& l, Object& r) const;                                        // 0x1424e6990

private:
    VM*                         pVM;            // +0x28
    SPtr<ClassTraits::Traits>   TraitsQName;    // +0x30
    SPtr<ClassTraits::Traits>   TraitsXML;      // +0x38
    SPtr<ClassTraits::Traits>   TraitsXMLList;  // +0x40
};

// The collector every object of this VM registers with.
inline RefCountCollector<StatMV_ActionScript_Mem>* VM::GetGCPtr() const
{
    return GC;
}

}}} // namespace Scaleform::GFx::AS3

#endif
