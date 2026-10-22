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

namespace Scaleform { namespace GFx { namespace AS3 {

// The VM's host interface (the movie's AS3 root implements it). Only the slots the recovered code calls.
class FlashUI
{
public:
    enum OutputMessageType
    {
        Output_Message,     // 0: trace()
        Output_Error,       // 1
        Output_Warning,     // 2: "not implemented" and other VM warnings
        Output_Action       // 3
    };

    virtual ~FlashUI() {}                                               // slot 0
    virtual void Output(OutputMessageType type, const char* msg) = 0;   // slot 1
};
class FileLoader;
class XMLSupport;

namespace Instances { namespace fl { class GlobalObjectCPP; class Array; } }
namespace InstanceTraits { namespace fl { class GlobalObject; } }

class VM : public NewOverrideBase<StatMV_VM_VM_Mem>
{
public:
    VM(FlashUI& ui, FileLoader& loader, StringManager& string_manager, ASRefCountCollector& gc);
    virtual ~VM();                      // slot 0
    virtual void* Unk01() { return 0; } // slot 1 (returns 0)

    StringManager&          GetStringManager() const    { return StringManagerRef; }
    ASRefCountCollector&    GetGC() const               { return *GC; }
    RefCountCollector<StatMV_ActionScript_Mem>* GetGCPtr() const;
    MemoryHeap*             GetMemoryHeap() const       { return MHeap; }
    FlashUI&                GetUI() const               { return UI; }
    Pickable<Instances::fl::Array> MakeArray() const;    // 0x142516270
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
        eInvalidBitmapData          = 2015
    };

    // An error being thrown: its id and the formatted message (0x10 bytes).
    class Error
    {
    public:
        Error(ErrorID id, VM& vm);                      // 0x1424d6b90
        Error(ErrorID id, VM& vm, const char* arg1);    // 0x1424d7850
        Error(ErrorID id, VM& vm, const char* arg1, const char* arg2);   // 0x1424d7690
        Error(ErrorID id, VM& vm, const char* arg1, int arg2, int arg3, int arg4);   // 0x1424d7bf0

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

    Instances::Namespace& GetPublicNamespace() const    { return *PublicNamespace; }
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
    SPtr<VMAppDomain>                       SystemDomain;       // +0x1c0
    SPtr<VMAppDomain>                       CurrentDomain;      // +0x1c8
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
    SPtr<ClassTraits::Traits>               Traits240;          // +0x240 QName or Catch (unverified)
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
    ArrayLH_POD<VMAbcFile*>                 VMAbcFilesWeak;     // +0x2c0
};

// The collector every object of this VM registers with.
inline RefCountCollector<StatMV_ActionScript_Mem>* VM::GetGCPtr() const
{
    return GC;
}

}}} // namespace Scaleform::GFx::AS3

#endif
