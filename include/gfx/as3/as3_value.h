// Recovered Scaleform GFx 4.1.18 AS3: the tagged Value, the GC smart pointers (SPtr / STPtr), the native class and
// method descriptors (TypeInfo / ClassInfo / MemberInfo / ThunkInfo) and the AS3 builtin string table. Shared header of
// the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// Value is 0x20 bytes: { UInt32 Flags; WeakProxy* (weak references); two-word payload }. Flags bits 0-4 are the kind,
// 5-6 the tracer's null state, 8 "with", 9 weak reference, 10 artificial class, 11 super call. Kinds above kClassTraits
// are reference counted (the out-of-line AddRefInternal / ReleaseInternal), kinds above kString are collectable.
// ThunkInfo is 0x28 bytes. The 4.1.18 ClassInfo carries the type fields itself (TypeInfo, 0x20 bytes) followed by the
// factory, the four counts and the four tables (0x50 bytes, e.g. DefinitionError at 0x14313dda0, Error at
// 0x14313dd50, whose Parent points to the parent's descriptor).
#ifndef MS2_SF_GFX_AS3_VALUE_H
#define MS2_SF_GFX_AS3_VALUE_H

#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/kernel/sf_hash.h"
#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/kernel/sf_alg.h"
#include "ms2/scaleform/include/gfx/gfx_asstring.h"
#include "ms2/scaleform/include/gfx/gfx_asutils.h"
#include "ms2/scaleform/include/kernel/sf_math.h"
#include "ms2/scaleform/include/render/render_twips.h"

// GFx code converts with the Render twips helpers unqualified.
namespace Scaleform { namespace GFx {
using Render::TwipsToPixels;
using Render::PixelsToTwips;
}}

// Message building in the natives: a C string or a String followed by an ASString gives a String.
namespace Scaleform {
inline String operator+(const char* l, const GFx::ASString& r)
{
    return String(l) + String(r.ToCStr(), r.GetSize());
}
inline String operator+(const String& l, const GFx::ASString& r)
{
    return l + String(r.ToCStr(), r.GetSize());
}
}

namespace Scaleform { namespace GFx { namespace AS3 {

// Allocation statistics ids of the AS3 VM (the GFxMovieView group, 0x140 + n).
enum StatAS3Values
{
    StatMV_ActionScript_Mem     = 0x143,
    StatMV_VM                   = 0x148,
    StatMV_VM_VM_Mem            = 0x149,
    StatMV_VM_CallFrame_Mem     = 0x14a,
    StatMV_VM_VTable_Mem        = 0x14b,
    StatMV_VM_SlotInfo_Mem      = 0x14c,
    StatMV_VM_SlotInfoHash_Mem  = 0x14d,
    StatMV_VM_CTraits_Mem       = 0x14e,
    StatMV_VM_Class_Mem         = 0x14f,
    StatMV_VM_ITraits_Mem       = 0x150,
    StatMV_VM_Instance_Mem      = 0x151,
    StatMV_VM_AbcFile_Mem       = 0x152,
    StatMV_VM_AbcConstPool_Mem  = 0x153,
    StatMV_VM_VMAbcFile_Mem     = 0x154,
    StatMV_VM_Tracer_Mem        = 0x155
};

class Object;
class Class;
class VM;
class Traits;
class Value;
class GASRefCountBase;
class WeakProxy;

namespace Instances
{
    class Function;
    class FunctionBase;
    class ThunkFunction;
    class Namespace;
    namespace fl { class GlobalObject; class GlobalObjectCPP; }
}
namespace InstanceTraits { class Traits; }
namespace ClassTraits    { class Traits; }

namespace Abc
{
    // Offset of an instruction in a method body.
    typedef UPInt TCodeOffset;

    // ABC namespace kinds.
    enum NamespaceKind
    {
        NS_Undefined = -1,
        NS_Public,
        NS_Protected,
        NS_StaticProtected,
        NS_Private,
        NS_Explicit,
        NS_PackageInternal
    };
}

// ==== builtin strings ================================================================================================

// Indices of the AS3 builtin strings, in the order of the exe's static name table.
enum BuiltinType
{
    AS3Builtin_empty_,          // ""
    AS3Builtin_undefined,
    AS3Builtin_null,
    AS3Builtin_void,
    AS3Builtin_true,
    AS3Builtin_false,
    AS3Builtin_boolean,
    AS3Builtin_number,
    AS3Builtin_string,
    AS3Builtin_function,
    AS3Builtin_object,
    AS3Builtin_xml,
    AS3Builtin_unknown,
    AS3Builtin_hitArea,
    AS3Builtin_comma_,          // ","
    AS3Builtin_zero,            // "0"
    AS3Builtin_NaN,
    AS3Builtin_Infinity,
    AS3Builtin_negInfinity,     // "-Infinity"
    AS3Builtin_objectPrefix_,   // "[object "
    AS3Builtin_closeBracket_,   // "]"
    AS3Builtin_namespace,
    AS3Builtin_global,
    AS3Builtin_length,
    AS3Builtin_toString,
    AS3Builtin_valueOf,
    AS3Builtin_Class,
    AS3Builtin_Date,
    AS3Builtin_activate,
    AS3Builtin_added,
    AS3Builtin_addedToStage,
    AS3Builtin_removed,
    AS3Builtin_removedFromStage,
    AS3Builtin_deactivate,
    AS3Builtin_enterFrame,
    AS3Builtin_frameConstructed,
    AS3Builtin_exitFrame,
    AS3Builtin_timer,
    AS3Builtin_timerComplete,
    AS3Builtin_complete,
    AS3Builtin_progress,
    AS3Builtin_open,
    AS3Builtin_init,
    AS3Builtin_render,
    AS3Builtin_resize,
    AS3Builtin_mouseCursorChange,
    AS3Builtin_click,
    AS3Builtin_doubleClick,
    AS3Builtin_mouseDown,
    AS3Builtin_mouseMove,
    AS3Builtin_mouseOut,
    AS3Builtin_mouseOver,
    AS3Builtin_mouseUp,
    AS3Builtin_mouseWheel,
    AS3Builtin_rollOut,
    AS3Builtin_rollOver,
    AS3Builtin_keyDown,
    AS3Builtin_keyUp,
    AS3Builtin_textInput,
    AS3Builtin_change,
    AS3Builtin_scroll,
    AS3BuiltinConst_Count_
};

// The AS3 builtin string table plus the manager that makes new strings. 0x1f8 bytes.
class StringManager
{
public:
    ASStringNodeHolder  Builtins[AS3BuiltinConst_Count_];   // +0x000
    ASStringManager*    pStringManager;                     // +0x1e8
    const char**        pStaticStrings;                     // +0x1f0

    const ASString& GetBuiltin(BuiltinType btype) const { return (const ASString&)Builtins[btype]; }
    ASStringManager* GetStringManager() const   { return pStringManager; }
    MemoryHeap*      GetHeap() const            { return pStringManager->GetHeap(); }
    ASString CreateConstString(const char* pstr) const { return pStringManager->CreateConstString(pstr); }
    ASString CreateString(const char* pstr) const { return ASString(pStringManager->CreateStringNode(pstr)); }
    ASString CreateString(const char* pstr, UPInt length) const { return pStringManager->CreateString(pstr, length); }
    ASString CreateString(const String& str) const
    {
        return ASString(pStringManager->CreateStringNode(str.ToCStr(), str.GetSize()));
    }
    ASStringNode* GetEmptyStringNode() const    { return pStringManager->GetEmptyStringNode(); }
    ASString      CreateEmptyString() const     { return ASString(pStringManager->GetEmptyStringNode()); }
    ASStringNode* GetNullStringNode() const     { return pStringManager->GetNullStringNode(); }
    ASString      CreateNullString() const      { return ASString(pStringManager->GetNullStringNode()); }
};

// ==== GC smart pointer ===============================================================================================

// Counted pointer to a collectable object. While the collector tears down a cycle it sets bit 0 of the stored pointer:
// the next Release() then only clears the mark.
template <typename T>
class SPtr
{
    friend class Value;
public:
    typedef T       ObjType;
    typedef SPtr<T> SelfType;

    SPtr(ObjType* p = NULL) : pObject(p)            { AddRef(); }
    SPtr(const SelfType& other) : pObject(other.pObject) { AddRef(); }
    SPtr(SelfType& other, PickType) : pObject(other.pObject) { other.pObject = NULL; }
    SPtr(Pickable<ObjType> v) : pObject(v.GetPtr()) { }
    ~SPtr()                                         { Release(); }

    SelfType& operator=(const SelfType& other)      { return Set(other); }
    SelfType& operator=(ObjType* p)                 { return SetPtr(p); }
    SelfType& operator=(Pickable<ObjType> v)        { return Pick(v); }

    SelfType& Pick(SelfType& other)
    {
        if (&other != this)
        {
            Release();
            pObject = other.pObject;
            other.pObject = NULL;
        }
        return *this;
    }
    SelfType& Pick(Pickable<ObjType> v)
    {
        if (v.GetPtr() != pObject)
        {
            Release();
            pObject = v.GetPtr();
        }
        return *this;
    }
    SelfType& Pick(ObjType* p)
    {
        if (p != pObject)
        {
            Release();
            pObject = p;
        }
        return *this;
    }
    SelfType& SetPtr(ObjType* p)
    {
        if (p != pObject)
        {
            Release();
            if (p)
                p->AddRef();
            pObject = p;
        }
        return *this;
    }
    SelfType& Set(const SelfType& other)
    {
        if (&other != this)
        {
            Release();
            other.AddRef();
            pObject = other.pObject;
        }
        return *this;
    }

    ObjType*  operator->() const    { return pObject; }
    ObjType&  operator*() const     { return *pObject; }
    ObjType*& GetRawRef()           { return pObject; }
    ObjType** GetRawPtr() const     { return &pObject; }
    ObjType*  GetPtr() const        { return pObject; }
    operator ObjType*() const       { return pObject; }

private:
    void AddRef() const
    {
        if (pObject)
            pObject->AddRef();
    }
    void Release()
    {
        if (pObject)
        {
            if ((UPInt)pObject & 1)
                pObject = (ObjType*)((UPInt)pObject - 1);
            else
                pObject->Release();
        }
    }

    mutable ObjType* pObject;
};

// ==== native class and method descriptors ============================================================================

typedef Pickable<ClassTraits::Traits> (*TTraitsFactory)(VM& vm);

// The type part of a native class descriptor. 0x20 bytes.
struct TypeInfo
{
    enum
    {
        CompileTime     = 0x1,
        DynamicObject   = 0x2,
        Abc             = 0x4,
        Final           = 0x8
    };

    bool IsCompileTime() const          { return (Flags & CompileTime) != 0; }
    bool IsDynamicObject() const        { return (Flags & DynamicObject) != 0; }
    bool IsAbcObject() const            { return (Flags & Abc) != 0; }
    bool IsFinalType() const            { return (Flags & Final) != 0; }
    const char* GetName() const         { return Name; }
    const char* GetPkgName() const      { return PkgName; }
    const TypeInfo* GetParent() const   { return Parent; }

    UPInt           Flags;      // +0x00
    const char*     Name;       // +0x08
    const char*     PkgName;    // +0x10
    const TypeInfo* Parent;     // +0x18
};

// A boolean result that tells whether an exception was raised (false). Only the bool is stored.
class CheckResult
{
public:
    CheckResult(bool r) : Result(r) { }
    CheckResult(const CheckResult& other) : Result(other.Result) { }
    ~CheckResult() { }   // user-declared (empty): returned results are non-trivial temporaries, as in the exe

    void DoNotCheck() const             { }
    operator bool() const               { return Result; }
    bool operator==(bool v) const       { return Result == v; }
    bool operator!() const              { return !Result; }
    CheckResult& operator=(bool v)      { Result = v; return *this; }

private:
    CheckResult& operator=(const CheckResult& other);

    bool Result;
};

// What a virtual table entry is.
enum TCodeType
{
    CT_Method   = 0U,
    CT_Get      = 1U,
    CT_Set      = 2U
};

// A native method: the thunk that unboxes the arguments, its result type, name and namespace, and its kind and
// argument counts packed in one word. 0x28 bytes.
struct ThunkInfo
{
    typedef void (*TThunkFunc)(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc,
                               const Value* argv);

    TThunkFunc      Method;         // +0x00
    const TypeInfo* ResultType;     // +0x08
    const char*     Name;           // +0x10
    const char*     NamespaceName;  // +0x18
    TCodeType       CodeType_ : 3;  // +0x20
    unsigned        MinArgNum_ : 3;
    unsigned        MaxArgNum_ : 10;

    TCodeType GetCodeType() const   { return CodeType_; }
    unsigned  GetMinArgNum() const  { return MinArgNum_; }
    unsigned  GetMaxArgNum() const  { return MaxArgNum_; }

    static void EmptyFunc(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc,
                          const Value* argv);
};

// ==== Value ==========================================================================================================

enum StrongRefType { StrongRefValue };
class ValueStack;
class ValueRegisterFile;

class Value
{
public:
    typedef Double Number;

    // Order matters: the predicates below compare kinds.
    enum KindType
    {
        kUndefined = 0,
        kBoolean,
        kInt,
        kUInt,
        kNumber,
        kThunk,
        kMethodInd,
        kVTableInd,
        kInstanceTraits,    // tracer only
        kClassTraits,       // tracer only
        // reference counted from here on
        kString,
        kNamespace,
        kObject,
        kClass,
        kFunction,
        kThunkFunction,
        kThunkClosure,
        kVTableIndClosure
    };

    enum Hint { hintNone, hintNumber, hintString };
    enum TraceNullType { NotNull, Null, NullOrNot };
    enum NotRefCountedType { NotRefCounted };

    // Bits 1-2 of a tagged object address (bit 0 belongs to the collector).
    enum ObjectTag { otInvalid = -1, otObject = 0, otClass = 2, otFunction = 4, otNamespace = 6, ObjectTagMask = 0x06 };

    enum
    {
        kindMask        = 0x1F,
        valueTypeMask   = 0x60,
        valueTypeOffset = 5,
        withMask        = 0x100,
        weakRefMask     = 0x200,
        artClassMask    = 0x400,
        superCallMask   = 0x800
    };

public:
    SF_INLINE Value(const Value& other) : Flags(other.Flags), Bonus(other.Bonus), value(other.value) { other.AddRef(); }
    SF_INLINE Value(const Value& other, NotRefCountedType) : Flags(other.Flags), Bonus(other.Bonus), value(other.value) { }
    Value(ValueStack& v);
    Value(const Value& other, StrongRefType);

    SF_INLINE Value() : Flags(kUndefined) { }
    SF_INLINE Value(SInt32 v, const Traits& tr, KindType k) : Flags(k), value(v, tr) { }
    SF_INLINE explicit Value(bool v) : Flags(kBoolean), value(v) { }
    SF_INLINE explicit Value(SInt32 v) : Flags(kInt), value(v) { }
    SF_INLINE explicit Value(UPInt v) : Flags(kUInt), value(static_cast<UInt32>(v)) { }
    SF_INLINE explicit Value(UInt32 v) : Flags(kUInt), value(v) { }
    SF_INLINE explicit Value(Number v) : Flags(kNumber), value(v) { }
    SF_INLINE Value(const ThunkInfo& v) : Flags(kThunk), value(v) { }
    Value(const ASString& v);
    Value(ASStringNode* v);

    template <typename OT> explicit Value(const SPtr<OT>& v) : Flags(kUndefined) { AssignUnsafe(v); }
    template <typename OT> Value(SPtr<OT>& v, PickType) : Flags(kUndefined) { PickUnsafe(v); }
    explicit Value(Object* v);
    explicit Value(Class* v);
    explicit Value(Instances::Function* v);
    explicit Value(Instances::ThunkFunction* v);
    explicit Value(Instances::Namespace* v);
    SF_INLINE Value(Object* p, const ThunkInfo& f) : Flags(kThunkClosure), value(p, f) { AddRefClosure(); }
    SF_INLINE Value(Object* p, SInt32 ind, bool super) : Flags(kVTableIndClosure), value(p, ind)
    {
        AddRefClosure();
        SetSuperCall(super);
    }
    ~Value() { Release(); }

    // Tracer values.
    SF_INLINE Value(InstanceTraits::Traits& tr, TraceNullType isNull) : Flags(kInstanceTraits), value(tr)
    {
        SetTraceNullType(isNull);
        SetWith(false);
    }
    SF_INLINE Value(ClassTraits::Traits& tr, TraceNullType isNull) : Flags(kClassTraits), value(tr)
    {
        SetTraceNullType(isNull);
        SetWith(false);
    }

    // Pick constructors: take over other's reference (other becomes undefined).
    SF_INLINE Value(Value& other, PickType) : Flags(other.Flags), Bonus(other.Bonus), value(other.value) { other.SetFlags(0); }
    SF_INLINE Value(Object* p, const ThunkInfo& f, PickType) : Flags(kThunkClosure), value(p, f) { }
    template <typename OT> Value(Pickable<OT> v) : Flags(0) { PickUnsafe(v); }

public:
    void Assign(const Value& other);
    void AssignUnsafe(const Value& other);

    SF_INLINE void Assign(bool v)               { Release(); SetKind(kBoolean); value = v; }
    SF_INLINE void AssignUnsafe(bool v)         { SetKind(kBoolean); value = v; }
    SF_INLINE void Assign(SInt32 v)             { Release(); SetKind(kInt); value = v; }
    SF_INLINE void AssignUnsafe(SInt32 v)       { SetKind(kInt); value = v; }
    SF_INLINE void Assign(UInt32 v)             { Release(); SetKind(kUInt); value = v; }
    SF_INLINE void AssignUnsafe(UInt32 v)       { SetKind(kUInt); value = v; }
    SF_INLINE void Assign(Number v)             { Release(); SetKind(kNumber); value = v; }
    SF_INLINE void AssignUnsafe(Number v)       { SetKind(kNumber); value = v; }
    SF_INLINE void Assign(const ThunkInfo& v)   { Release(); SetKind(kThunk); value = v; }
    SF_INLINE void AssignUnsafe(const ThunkInfo& v) { SetKind(kThunk); value = v; }

    void Assign(const ASString& v);
    void AssignUnsafe(const ASString& v);
    void Assign(ASStringNode* v);
    void AssignUnsafe(ASStringNode* v);
    template <typename OT> void Assign(const SPtr<OT>& v)       { Assign(v.GetPtr()); }
    template <typename OT> void AssignUnsafe(const SPtr<OT>& v) { AssignUnsafe(v.GetPtr()); }
    void Assign(Object* v);
    void AssignUnsafe(Object* v);
    void Assign(Class* v);
    void AssignUnsafe(Class* v);
    SF_INLINE void Assign(Instances::Function* v)       { Release(); AssignUnsafe(v); }
    SF_INLINE void AssignUnsafe(Instances::Function* v) { SetKind(kFunction); value.VS._1.VFunct = v; if (v) AddRefInternal(); }
    SF_INLINE void Assign(Instances::ThunkFunction* v)       { Release(); AssignUnsafe(v); }
    SF_INLINE void AssignUnsafe(Instances::ThunkFunction* v) { SetKind(kThunkFunction); value.VS._1.VThunkFunct = v; if (v) AddRefInternal(); }
    SF_INLINE void Assign(Instances::Namespace* v)       { Release(); AssignUnsafe(v); }
    SF_INLINE void AssignUnsafe(Instances::Namespace* v) { SetKind(kNamespace); value.VS._1.VNs = v; if (v) AddRefInternal(); }

    Value& operator=(const Value& other)                { Assign(other); return *this; }
    Value& operator=(const ThunkInfo& v)                { Assign(v); return *this; }
    Value& operator=(const ASString& v)                 { Assign(v); return *this; }
    Value& operator=(ASStringNode* v)                   { Assign(v); return *this; }
    Value& operator=(Object* v)                         { Assign(v); return *this; }
    Value& operator=(Class* v)                          { Assign(v); return *this; }
    Value& operator=(Instances::Function* v)            { Assign(v); return *this; }
    Value& operator=(Instances::ThunkFunction* v)       { Assign(v); return *this; }
    Value& operator=(Instances::Namespace* v)           { Assign(v); return *this; }
    template <typename OT> Value& operator=(const SPtr<OT>& v) { Assign(v); return *this; }

    // Take over a reference (saves an AddRef / Release pair).
    template <typename OT> void Pick(SPtr<OT>& v)           { Pick(v.GetPtr()); v.pObject = NULL; }
    template <typename OT> void PickUnsafe(SPtr<OT>& v)     { PickUnsafe(v.GetPtr()); v.pObject = NULL; }
    template <typename OT> void Pick(Pickable<OT> v)        { Pick(v.GetPtr()); }
    template <typename OT> void PickUnsafe(Pickable<OT> v)  { PickUnsafe(v.GetPtr()); }
    void Pick(Value& other);
    void PickUnsafe(Value& other);
    void Pick(Object* v);
    void PickUnsafe(Object* v);
    void Pick(Class* v);
    void PickUnsafe(Class* v);
    void Pick(Instances::Function* v);
    void PickUnsafe(Instances::Function* v);
    void Pick(Instances::FunctionBase* v);
    void PickUnsafe(Instances::FunctionBase* v);
    void Pick(Instances::ThunkFunction* v);
    void PickUnsafe(Instances::ThunkFunction* v);
    void Pick(Instances::Namespace* v);
    void PickUnsafe(Instances::Namespace* v);
    void Pick(ValueStack& v);
    void PickUnsafe(ValueStack& v);
    template <typename OT> Value& operator=(Pickable<OT> v) { Pick(v); return *this; }

    // Setters by type (the Unsafe forms skip the Release of a value known not to be counted).
    void SetUndefined()                     { Release(); SetKind(kUndefined); }
    SF_INLINE void SetUndefinedUnsafe()     { SetKind(kUndefined); }
    void SetNull()                          { Release(); SetKind(kObject); value = (Object*)NULL; }
    SF_INLINE void SetNullUnsafe()          { SetKind(kObject); value = (Object*)NULL; }
    void SetBool(bool v)                    { Release(); SetKind(kBoolean); value = v; }
    SF_INLINE void SetBoolUnsafe(bool v)    { SetKind(kBoolean); value = v; }
    void SetSInt32(SInt32 v)                { Release(); SetKind(kInt); value = v; }
    SF_INLINE void SetSInt32Unsafe(SInt32 v){ SetKind(kInt); value = v; }
    void SetUPInt(UPInt v)                  { Release(); SetKind(kUInt); value = static_cast<UInt32>(v); }
    SF_INLINE void SetUPIntUnsafe(UPInt v)  { SetKind(kUInt); value = static_cast<UInt32>(v); }
    void SetUInt32(UInt32 v)                { Release(); SetKind(kUInt); value = v; }
    SF_INLINE void SetUInt32Unsafe(UInt32 v){ SetKind(kUInt); value = v; }
    void SetNumber(Number v)                { Release(); SetKind(kNumber); value = v; }
    SF_INLINE void SetNumberUnsafe(Number v){ SetKind(kNumber); value = v; }

    // Flag bits, set or cleared without a branch.
    SF_INLINE void SetWith(bool v = true)           { Flags = (Flags & ~withMask) | (-static_cast<SInt32>(v) & withMask); }
    SF_INLINE void SetWeakRef(bool v = true)        { Flags = (Flags & ~weakRefMask) | (-static_cast<SInt32>(v) & weakRefMask); }
    SF_INLINE void SetArtificialClass(bool v = true){ Flags = (Flags & ~artClassMask) | (-static_cast<SInt32>(v) & artClassMask); }
    SF_INLINE void SetSuperCall(bool v = true)      { Flags = (Flags & ~superCallMask) | (-static_cast<SInt32>(v) & superCallMask); }
    SF_INLINE void SetTraceNullType(TraceNullType v)
    {
        Flags = (Flags & ~valueTypeMask) | (static_cast<UInt32>(v) << valueTypeOffset);
    }

    // Exchange without reference counting.
    void Swap(Value& other);

public:
    operator ASStringNode*() const              { return value; }
    operator ASString() const                   { return ASString(value); }
    operator bool&()                            { return value.operator bool&(); }
    operator bool() const                       { return value.operator bool(); }
    operator SInt32&()                          { return value; }
    operator SInt32() const                     { return value; }
    operator UInt32&()                          { return value; }
    operator UInt32() const                     { return value.operator UInt32(); }
    operator Number&()                          { return value; }
    operator Number() const                     { return value; }
    operator SPtr<Object>() const;
    operator Object&() const                    { return *static_cast<Object*>(value); }
    operator Class&() const                     { return *static_cast<Class*>(value); }
    operator Instances::Function&() const       { return *static_cast<Instances::Function*>(value); }
    operator const ThunkInfo&() const           { return value; }
    operator Instances::ThunkFunction&() const  { return *static_cast<Instances::ThunkFunction*>(value); }
    operator Instances::Namespace&() const      { return *static_cast<Instances::Namespace*>(value); }

    bool&   AsBool()                            { return value; }
    bool    AsBool() const                      { return value; }
    SInt32& AsInt()                             { return value; }
    SInt32  AsInt() const                       { return value; }
    UInt32& AsUInt()                            { return value; }
    UInt32  AsUInt() const                      { return value.operator UInt32(); }
    Number& AsNumber()                          { return value; }
    Number  AsNumber() const                    { return value; }
    ASStringNode* AsStringNode() const          { return value; }
    ASString AsString() const                   { return ASString(value); }
    Object* GetObject() const                   { return value.VS._1.VObj; }
    GASRefCountBase* GetGASRefCountBase() const { return (GASRefCountBase*)value.VS._1.VObj; }
    Instances::Namespace* GetNamespace() const  { return value.VS._1.VNs; }
    Object* GetClosure() const                  { return value.VS._2.VObj; }
    GASRefCountBase** AsGASRefCountBasePtrPtr() const;
    GASRefCountBase** AsClosurePtrPtr() const;
    Class&       AsClass()                      { return *value.VS._1.VClass; }
    const Class& AsClass() const                { return *value.VS._1.VClass; }
    Instances::Function&       AsFunction()     { return *static_cast<Instances::Function*>(value); }
    const Instances::Function& AsFunction() const { return *static_cast<const Instances::Function*>(value); }
    const ThunkInfo& AsThunk() const            { return value; }
    const Instances::ThunkFunction& AsThunkFunction() const { return *static_cast<const Instances::ThunkFunction*>(value); }
    const Instances::Namespace& AsNamespace() const { return *static_cast<const Instances::Namespace*>(value); }
    SF_INLINE const Traits& GetTraits() const   { return value.GetTraits(); }

    static const Value& GetUndefined();
    static const Value& GetNull();

    bool IsWeakRef() const                      { return (Flags & weakRefMask) != 0; }
    bool IsValidWeakRef() const;
    bool MakeWeakRef();     // true when the state changed
    bool MakeStrongRef();   // true when the state changed

    SF_INLINE KindType GetKind() const          { return static_cast<KindType>(Flags & kindMask); }
    ObjectTag GetObjectTag() const;
    ASStringNode* GetStringNode() const         { return value; }
    SInt32 GetMethodInd() const                 { return value; }
    SInt32 GetVTableInd() const                 { return value; }

    TraceNullType GetTraceNullType() const      { return static_cast<TraceNullType>((Flags & valueTypeMask) >> valueTypeOffset); }
    bool GetWith() const                        { return (Flags & withMask) != 0; }
    bool IsArtificialClass() const              { return (Flags & artClassMask) != 0; }
    bool IsSuperCall() const                    { return (Flags & superCallMask) != 0; }
    bool IsTraceNull() const                    { return GetTraceNullType() == Null; }
    SF_INLINE InstanceTraits::Traits& GetInstanceTraits() const { return *value.VS._1.ITr; }
    SF_INLINE ClassTraits::Traits& GetClassTraits() const       { return *value.VS._1.CTr; }
    bool IsTraceNullOrUndefined() const         { return IsTraceNull() || IsUndefined(); }

public:
    // ECMA-262 conversions. The CheckResult forms return false when an exception was raised (result untouched).
    CheckResult Convert2PrimitiveValueUnsafe(Value& result, Hint hint = hintNone) const;
    CheckResult ToPrimitiveValue()
    {
        Value v = GetUndefined();
        bool result = false;
        if (Convert2PrimitiveValueUnsafe(v))
        {
            Swap(v);
            result = true;
        }
        return result;
    }
    bool Convert2Boolean() const;
    void ToBooleanValue()                       { SetBool(Convert2Boolean()); }
    SF_INLINE CheckResult Convert2NumberInline(Number& result) const
    {
        KindType kind = GetKind();
        switch (kind)
        {
        case kNumber:
            result = value;
            break;
        case kUndefined:
            result = NumberUtil::NaN();
            break;
        case kBoolean:
            result = value.VS._1.VBool ? 1.0 : NumberUtil::POSITIVE_ZERO();
            break;
        case kInt:
            result = static_cast<Number>(value.VS._1.VInt);
            break;
        case kUInt:
            result = static_cast<Number>(value.VS._1.VUInt);
            break;
        default:
            return Convert2NumberInternal(result, kind);
        }
        return true;
    }
    CheckResult Convert2Number(Number& result) const;
    CheckResult ToNumberValueInline();
    CheckResult ToNumberValue();
    CheckResult Convert2Int32(SInt32& result) const;
    CheckResult ToInt32Value();
    CheckResult Convert2UInt32(UInt32& result) const;
    CheckResult ToUInt32Value();
    CheckResult Convert2String(ASString& result) const;
    CheckResult Convert2String(StringBuffer& result) const;
    CheckResult ToStringValue(StringManager& sm);

    SF_INLINE void Clean()
    {
        Release();
        SetFlags(0);
    }

public:
    SF_INLINE bool IsNull() const
    {
        bool result;
        if (IsObject())
            result = value.VS._1.VObj == NULL;
        else
            result = false;
        return result;
    }

    static bool IsInt(const KindType k)             { return k == kInt || k == kUInt; }
    bool IsInt() const                              { return IsInt(GetKind()); }
    static bool IsIntStrict(const KindType k)       { return k == kInt; }
    bool IsIntStrict() const                        { return IsIntStrict(GetKind()); }
    static bool IsBool(const KindType k)            { return k == kBoolean; }
    bool IsBool() const                             { return IsBool(GetKind()); }
    static bool IsUInt(const KindType k)            { return k == kInt || k == kUInt; }
    bool IsUInt() const                             { return IsUInt(GetKind()); }
    static bool IsUIntStrict(const KindType k)      { return k == kUInt; }
    bool IsUIntStrict() const                       { return IsUIntStrict(GetKind()); }
    static bool IsNumber(const KindType k)          { return k == kNumber; }
    bool IsNumber() const                           { return IsNumber(GetKind()); }
    static bool IsString(const KindType k)          { return k == kString; }
    bool IsString() const                           { return IsString(GetKind()); }
    static bool IsUndefined(const KindType k)       { return k == kUndefined; }
    bool IsUndefined() const                        { return IsUndefined(GetKind()); }
    bool IsNullOrUndefined() const                  { return IsUndefined(GetKind()) || IsNull(); }
    static bool IsFunction(const KindType k)        { return k == kFunction; }
    bool IsFunction() const                         { return IsFunction(GetKind()); }
    static bool IsObjectStrict(const KindType k)    { return k == kObject; }
    bool IsObjectStrict() const                     { return IsObjectStrict(GetKind()); }
    static bool IsClass(const KindType k)           { return k == kClass; }
    bool IsClass() const                            { return IsClass(GetKind()); }
    // Single-part object kinds: kObject .. kThunkFunction.
    static bool IsObject(const KindType k)          { return k > kNamespace && k < kThunkClosure; }
    bool IsObject() const                           { return IsObject(GetKind()); }
    static bool IsThunk(const KindType k)           { return k == kThunk; }
    bool IsThunk() const                            { return IsThunk(GetKind()); }
    static bool HasThunk(const KindType k)          { return k == kThunk || k == kThunkClosure; }
    bool HasThunk() const                           { return HasThunk(GetKind()); }
    static bool IsThunkFunction(const KindType k)   { return k == kThunkFunction; }
    bool IsThunkFunction() const                    { return IsThunkFunction(GetKind()); }
    static bool IsNamespace(const KindType k)       { return k == kNamespace; }
    bool IsNamespace() const                        { return IsNamespace(GetKind()); }
    static bool IsThunkClosure(const KindType k)    { return k == kThunkClosure; }
    bool IsThunkClosure() const                     { return IsThunkClosure(GetKind()); }
    static bool IsMethodInd(const KindType k)       { return k == kMethodInd; }
    bool IsMethodInd() const                        { return IsMethodInd(GetKind()); }
    static bool IsVTableInd(const KindType k)       { return k == kVTableInd; }
    bool IsVTableInd() const                        { return IsVTableInd(GetKind()); }
    static bool IsVTableIndClosure(const KindType k){ return k == kVTableIndClosure; }
    bool IsVTableIndClosure() const                 { return IsVTableIndClosure(GetKind()); }
    // Two-part kinds (object + method).
    static bool IsClosure(const KindType k)         { return k > kThunkFunction; }
    bool IsClosure() const                          { return IsClosure(GetKind()); }
    static bool IsCallable(const KindType k)
    {
        return IsClosure(k) || IsFunction(k) || IsThunk(k) || IsThunkFunction(k) || IsMethodInd(k) || IsVTableInd(k) ||
               k == kObject || k == kClass;
    }
    bool IsCallable() const                         { return IsCallable(GetKind()); }
    static bool IsNumeric(const KindType k)         { return k > kBoolean && k < kThunk; }
    bool IsNumeric() const                          { return IsNumeric(GetKind()); }
    static bool IsPrimitive(const KindType k)       { return k < kThunk || k == kString; }
    bool IsPrimitive() const                        { return IsPrimitive(GetKind()); }
    static bool IsRefCounted(const KindType k)      { return k > kClassTraits; }
    bool IsRefCounted() const                       { return IsRefCounted(GetKind()); }
    bool IsGarbageCollectable() const               { return GetKind() > kString; }
    static bool IsTraits(const KindType k)          { return k == kInstanceTraits || k == kClassTraits; }
    bool IsTraits() const                           { return IsTraits(GetKind()); }
    static bool IsClassTraits(const KindType k)     { return k == kClassTraits; }
    bool IsClassTraits() const                      { return IsClassTraits(GetKind()); }
    static bool IsInstanceTraits(const KindType k)  { return k == kInstanceTraits; }
    bool IsInstanceTraits() const                   { return IsInstanceTraits(GetKind()); }

    bool IsNaN() const;
    bool IsPOSITIVE_INFINITY() const;
    bool IsNEGATIVE_INFINITY() const;
    bool IsNaNOrInfinity() const;
    bool IsPOSITIVE_ZERO() const;
    bool IsNEGATIVE_ZERO() const;
    bool IsNaN_OR_NP_ZERO() const;

    bool operator==(const Value& other) const;

    struct HashFunctor
    {
        static UPInt SDBM_Hash(const void* data_in, UPInt size, UPInt seed = 5381);
        UPInt operator()(const Value& key) const;
    };

    // Lets a Hash rebuild its key from a node.
    template <typename U, typename HashF>
    Value(const HashNode<Value, U, HashF>& node) : Flags(node.First.Flags), Bonus(node.First.Bonus), value(node.First.value)
    {
        node.First.AddRef();
    }

private:
    friend class ValueRegisterFile;     // (appended, sfr19) ReleaseReserved releases registers in place
    friend struct ValueAssignCopies;    // (appended, sfr22) the exe's out-of-line Assign copies (sfr_as3_03)
    friend class CallFrame;             // (appended, sfr33) ClearOpStack releases the popped values in place

    SF_INLINE void AddRefString() const         { value.VS._1.VStr->AddRef(); }
    void AddRefObject() const;
    void AddRefClosure() const;
    SF_INLINE void AddRefMethodClosure() const
    {
        AddRefClosure();
        AddRefObject();
    }
    void AddRefInternal() const;
    void ReleaseInternal();
    void AddRefWeakRef() const;
    void ReleaseWeakRef();
    SF_INLINE void AddRef() const
    {
        if (IsRefCounted())
        {
            if (IsWeakRef())
                AddRefWeakRef();
            else
                AddRefInternal();
        }
    }
    SF_INLINE void Release()
    {
        if (IsRefCounted())
        {
            if (IsWeakRef())
                ReleaseWeakRef();
            else
                ReleaseInternal();
        }
    }
    GASRefCountBase* GetWeakBase() const;

    static UInt32 GetFlags(KindType v)          { return static_cast<UInt32>(v); }
    void SetFlags(UInt32 flags)                 { Flags = flags; }
    SF_INLINE void SetKind(KindType v)          { Flags = (Flags & ~kindMask) | static_cast<UInt32>(v); }

    CheckResult Convert2NumberInternal(Number& result, KindType kind) const;

private:
    // The weak proxy of a weak reference (NULL otherwise).
    union Extra
    {
        Extra() : pWeakProxy(NULL) { }
        Extra(WeakProxy* v) : pWeakProxy(v) { }
        WeakProxy* pWeakProxy;
    };
    union V1U
    {
        bool                        VBool;
        SInt32                      VInt;
        UInt32                      VUInt;
        ASStringNode*               VStr;
        Object*                     VObj;
        Class*                      VClass;
        Instances::Function*        VFunct;
        const ThunkInfo*            VThunk;
        Instances::ThunkFunction*   VThunkFunct;
        Instances::Namespace*       VNs;
        InstanceTraits::Traits*     ITr;
        ClassTraits::Traits*        CTr;
    };
    union V2U
    {
        Object*         VObj;       // closure object
        const Traits*   pTraits;    // method / vtable index owner
    };
    struct VStruct
    {
        V1U _1;
        V2U _2;
    };
    // Both words take part in the hash, so every constructor writes the part it uses only.
    union VU
    {
    public:
        VU() { }
        VU(bool v)                          { VS._1.VBool = v; }
        VU(SInt32 v)                        { VS._1.VInt = v; }
        VU(UInt32 v)                        { VS._1.VUInt = v; }
        VU(Number v)                        { VNumber = v; }
        VU(ASStringNode* v)                 { VS._1.VStr = v; }
        VU(Object* v)                       { VS._1.VObj = v; }
        VU(Class* v)                        { VS._1.VClass = v; }
        VU(Instances::Function* v)          { VS._1.VFunct = v; }
        VU(const ThunkInfo& v)              { VS._1.VThunk = &v; }
        VU(Instances::ThunkFunction* v)     { VS._1.VThunkFunct = v; }
        VU(Instances::Namespace* v)         { VS._1.VNs = v; }
        VU(InstanceTraits::Traits& tr)      { VS._1.ITr = &tr; }
        VU(ClassTraits::Traits& tr)         { VS._1.CTr = &tr; }
        VU(Object* p, const ThunkInfo& f)   { VS._2.VObj = p; VS._1.VThunk = &f; }
        VU(Object* p, SInt32 v)             { VS._2.VObj = p; VS._1.VInt = v; }
        VU(SInt32 v, const Traits& tr)      { VS._2.pTraits = &tr; VS._1.VInt = v; }

        operator bool&()                            { return VS._1.VBool; }
        operator bool() const                       { return VS._1.VBool; }
        operator SInt32&()                          { return VS._1.VInt; }
        operator SInt32() const                     { return VS._1.VInt; }
        operator UInt32&()                          { return VS._1.VUInt; }
        operator UInt32() const                     { return VS._1.VUInt; }
        operator UPInt() const                      { return VS._1.VUInt; }
        operator Number&()                          { return VNumber; }
        operator Number() const                     { return VNumber; }
        operator ASStringNode*() const              { return VS._1.VStr; }
        operator Object*() const                    { return VS._1.VObj; }
        operator Class*() const                     { return VS._1.VClass; }
        operator Instances::Function*() const       { return VS._1.VFunct; }
        operator const ThunkInfo&() const           { return *VS._1.VThunk; }
        operator Instances::ThunkFunction*() const  { return VS._1.VThunkFunct; }
        operator Instances::Namespace*() const      { return VS._1.VNs; }
        Instances::Function* GetFunct() const       { return VS._1.VFunct; }
        const Traits& GetTraits() const             { return *VS._2.pTraits; }

        Number  VNumber;
        VStruct VS;
    };

    UInt32  Flags;      // +0x00
    Extra   Bonus;      // +0x08
    VU      value;      // +0x10
};

inline Value::ObjectTag GetObjectTag(UPInt addr)
{
    return (Value::ObjectTag)(addr & Value::ObjectTagMask);
}

// A counted pointer to the collectable part of a value, with the value's object tag in bits 1-2.
class STPtr
{
    friend class Value;
public:
    typedef GASRefCountBase ObjType;
    typedef STPtr           SelfType;

    STPtr() : pObject(NULL) { }
    STPtr(const Value& v) : pObject(MakeAddr(v))        { AddRef(); }
    STPtr(const SelfType& other) : pObject(other.pObject) { AddRef(); }
    ~STPtr()                                            { Release(); }

    SelfType& operator=(const SelfType& other)          { return Set(other); }
    SelfType& operator=(const Value& v)                 { return SetValue(v); }

    SelfType& SetValue(const Value& v)
    {
        ObjType* addr = MakeAddr(v);
        if (addr != pObject)
        {
            Release();
            pObject = addr;
            AddRef();
        }
        return *this;
    }
    SelfType& Set(const SelfType& other)
    {
        if (&other != this)
        {
            Release();
            other.AddRef();
            pObject = other.pObject;
        }
        return *this;
    }

    void GetValue(Value& v);
    void GetValueUnsafe(Value& v);
    ObjType* GetPtr() const     { return pObject; }
    operator ObjType*() const   { return pObject; }

private:
    ObjType* GetAddrNoTag() const   { return (ObjType*)((UPInt)pObject & ~Value::ObjectTagMask); }
    ObjType* GetRawAddr() const     { return (ObjType*)((UPInt)GetAddrNoTag() & ~1); }
    static ObjType* MakeAddr(const Value& v)
    {
        ObjType* addr = NULL;
        if (v.IsObject() || v.IsNamespace())
        {
            GASRefCountBase* vv = v.GetGASRefCountBase();
            if (vv)
                addr = (ObjType*)((UPInt)vv | v.GetObjectTag());
        }
        return addr;
    }
    void AddRef() const;
    void Release() const;

    mutable ObjType* pObject;
};

typedef ArrayLH<Value>  ValueArray;
typedef ArrayDH<Value>  ValueArrayDH;
typedef ValueArrayDH    ScopeStackType;
typedef ArrayLH<Instances::fl::GlobalObject*> TGlobalObjects;

SF_INLINE bool Value::IsNaN() const                 { return NumberUtil::IsNaN(value.VNumber); }
SF_INLINE bool Value::IsPOSITIVE_INFINITY() const   { return NumberUtil::IsPOSITIVE_INFINITY(value.VNumber); }
SF_INLINE bool Value::IsNEGATIVE_INFINITY() const   { return NumberUtil::IsNEGATIVE_INFINITY(value.VNumber); }
SF_INLINE bool Value::IsNaNOrInfinity() const       { return NumberUtil::IsNaNOrInfinity(value.VNumber); }
SF_INLINE bool Value::IsPOSITIVE_ZERO() const       { return NumberUtil::IsPOSITIVE_ZERO(value.VNumber); }
SF_INLINE bool Value::IsNEGATIVE_ZERO() const       { return NumberUtil::IsNEGATIVE_ZERO(value.VNumber); }
SF_INLINE bool Value::IsNaN_OR_NP_ZERO() const      { return IsNaN() || IsPOSITIVE_ZERO() || IsNEGATIVE_ZERO(); }

SF_INLINE Value::Number MakeValueNumber(double v)   { return v; }

inline bool IsNamespaceObject(const Value& v)       { return v.IsNamespace(); }
bool IsQNameObject(const Value& v);
bool IsXMLObject(Object* obj);
inline bool IsXMLObject(const Value& v)             { return v.IsObject() && IsXMLObject(v.GetObject()); }
bool IsXMLListObject(Object* obj);
inline bool IsXMLListObject(const Value& v)         { return v.IsObject() && IsXMLListObject(v.GetObject()); }

// ECMA-262 11.9.6 (no exceptions) and 11.9.3 / 11.6.1 / 11.8.5 (false on an exception).
bool StrictEqual(const Value& x, const Value& y);
CheckResult AbstractEqual(bool& result, const Value& l, const Value& r);
CheckResult Add(StringManager& sm, Value& result, const Value& l, const Value& r);
enum Boolean3 { undefined3, true3, false3 };
CheckResult AbstractLessThan(Boolean3& result, const Value& l, const Value& r);

// The object at a tagged address (tag in bits 1-2).
Value GetAbsObject(UPInt addr);

// Strict equality, also for weak references.
inline bool Value::operator==(const Value& other) const
{
    return StrictEqual(*this, other);
}

inline Value::TraceNullType CanBeNull(const Value& _1, const Value& _2)
{
    const Value::TraceNullType tn1 = _1.GetTraceNullType();
    const Value::TraceNullType tn2 = _2.GetTraceNullType();
    if (tn1 == tn2)
        return tn1;
    return Value::NullOrNot;
}

// Native member variable of a C++ class: name, byte offset in the instance, binding kind. 0x10 bytes.
struct MemberInfo
{
    const char* Name;           // +0x00
    // +0x08 (sfr19: bit fields; Traits::AddSlot 0x1424e9910 reads Offset as bits 0-15, the binding as 16-20 and
    // const as bit 21)
    UInt32      Offset:16;
    SInt32      BT:5;           // SlotInfo::BindingType
    UInt32      Const:1;
};

// Descriptor of a native class: its type (the TypeInfo part, 0x20 bytes) followed by the traits factory and the
// method / member tables. 0x50 bytes.
struct ClassInfo : public TypeInfo
{
    TTraitsFactory      Factory;            // +0x20
    UInt8               ClassMethodNum;     // +0x28
    UInt8               ClassMemberNum;     // +0x29
    UInt8               InstanceMethodNum;  // +0x2a
    UInt8               InstanceMemberNum;  // +0x2b
    const ThunkInfo*    ClassMethod;        // +0x30
    const MemberInfo*   ClassMember;        // +0x38
    const ThunkInfo*    InstanceMethod;     // +0x40
    const MemberInfo*   InstanceMember;     // +0x48

    const ClassInfo* GetParentInfo() const { return static_cast<const ClassInfo*>(Parent); }
};

// Specialized out of line in sfr_as3_15 (@0x1424d2590); declared so no other unit instantiates the generic one.
template <> void Value::AssignUnsafe<Instances::fl::GlobalObjectCPP>(const SPtr<Instances::fl::GlobalObjectCPP>& v);

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace Alg {

// Values swap without reference counting.
template <>
SF_INLINE void Swap<GFx::AS3::Value>(GFx::AS3::Value& l, GFx::AS3::Value& r)
{
    l.Swap(r);
}

}} // namespace Scaleform::Alg

#endif
