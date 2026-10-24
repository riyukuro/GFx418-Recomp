// Recovered Scaleform 4.1.18 GFx AS2: the ActionScript 2 value (0x20 bytes: type byte, property flags byte,
// payload at +8), function references and member property flags.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_VALUE_H
#define MS2_SF_GFX_AS2_VALUE_H

#include "as2_actiontypes.h"

namespace Scaleform { namespace GFx {

class CharacterHandle;

namespace AS2 {

struct ValueProperty;

// Property attribute bits of an object member (1 byte).
class PropFlags
{
public:
    enum PropFlagConstants
    {
        PropFlag_ReadOnly   = 0x04,
        PropFlag_DontDelete = 0x02,
        PropFlag_DontEnum   = 0x01,
        PropFlag_Mask       = 0x07
    };

    UByte Flags;

    PropFlags() : Flags(0) {}
    PropFlags(UByte flags) : Flags(flags) {}
    PropFlags(bool readOnly, bool dontDelete, bool dontEnum)
        : Flags((UByte)((readOnly ? PropFlag_ReadOnly : 0) | (dontDelete ? PropFlag_DontDelete : 0) |
                        (dontEnum ? PropFlag_DontEnum : 0)))
    {
    }

    bool  GetDontEnum() const    { return (Flags & PropFlag_DontEnum) != 0; }
    bool  GetDontDelete() const  { return (Flags & PropFlag_DontDelete) != 0; }
    bool  GetReadOnly() const    { return (Flags & PropFlag_ReadOnly) != 0; }
    UByte GetFlags() const       { return Flags; }
};

// Reference to a function object plus the local frame it closes over (0x18 bytes). Flags: 1 = the frame is held
// weakly (SetLocalFrame, exe 0x142981e70), 2 = the function is held without a count (internal).
class FunctionRefBase
{
public:
    enum FuncRef_Flags
    {
        FuncRef_Weak     = 1,
        FuncRef_Internal = 2
    };

    FunctionObject* Function;    // +0x00
    LocalFrame*     pLocalFrame; // +0x08
    UByte           Flags;       // +0x10

    bool IsNull() const { return Function == 0; }

    inline void Init(FunctionObject* poriginal = 0, UByte flags = 0); // as2_object.h
    inline void Init(FunctionObject& original, UByte flags = 0); // as2_object.h: adopts the reference
    inline void Init(const FunctionRefBase& orig, UByte flags = 0); // as2_object.h
    inline void DropRefs(); // as2_action.h
    void SetLocalFrame(LocalFrame* localFrame, bool weakRef = 0);
    void Assign(const FunctionRefBase& orig);

    FunctionObject* operator->() const { return Function; }
    FunctionObject& operator*() const  { return *Function; }
    FunctionObject* GetObjectPtr() const { return Function; }

    // The function and the frame (defined in sfr_as2_02).
    template<class Functor> void ForEachChild_GC(ASRefCountBaseType::Collector* prcc) const;
    // Both are collected objects: nothing to release before collection.
    void Finalize_GC() {}
};

class FunctionRef : public FunctionRefBase
{
public:
    SF_FORCEINLINE FunctionRef(FunctionObject* poriginal = 0) { Init(poriginal); }
    SF_FORCEINLINE FunctionRef(FunctionObject& original) { Init(original); }
    SF_FORCEINLINE FunctionRef(const FunctionRef& orig) { Init(orig); }
    SF_FORCEINLINE FunctionRef(const FunctionRefBase& orig) { Init(orig); }
    SF_FORCEINLINE ~FunctionRef() { DropRefs(); }

    // Calls the function in its local frame.
    inline void Invoke(const FnCall& fn, const char* pmethodName = 0) const; // as2_object.h

    SF_FORCEINLINE const FunctionRef& operator=(const FunctionRef& orig)
    {
        Assign(orig);
        return *this;
    }
};

// ActionScript 2 value. 0x20 bytes; strings/objects/functions (Type >= STRING) hold references.
class Value
{
public:
    // Heap allocated values (array elements) come from the Scaleform heaps.
    SF_MEMORY_REDEFINE_NEW(Value, StatMV_ActionScript_Mem)

    enum type
    {
        UNDEFINED,
        NULLTYPE,
        BOOLEAN,
        NUMBER,
        INTEGER,
        // Types from here on own a reference (DropRefs).
        STRING,
        OBJECT,
        CHARACTER,
        FUNCTION,
        PROPERTY,
        UNSET,
        FUNCTIONNAME,
        RESOLVEHANDLER
    };

    enum hint
    {
        NoHint,
        HintToNumber,
        HintToString
    };

    struct TypeDesc
    {
        UByte Type;      // +0
        UByte PropFlags; // +1
    };
    struct ValueType : public TypeDesc
    {
        union
        {
            ASStringNode*    pStringNode;
            Object*          pObjectValue;
            CharacterHandle* pCharHandle;
            ValueProperty*   pProperty;
            FunctionRefBase  FunctionValue;
            bool             BooleanValue;
        };
    };
    struct NumericType : public TypeDesc
    {
        union
        {
            SInt32 Int32Value;
            UInt32 UInt32Value;
            Number NumberValue;
        };
    };

    union
    {
        TypeDesc    T;
        ValueType   V;
        NumericType NV;
    };

    Value() { T.Type = UNDEFINED; }
    Value(const Value& v);              // exe 0x1429237f0
    Value(Object* pobj);                // exe 0x142923cb0
    inline Value(InteractiveObject* pcharacter); // as2_avmcharacter.h
    Value(bool val)   { T.Type = BOOLEAN; V.BooleanValue = val; }
    Value(Number val) { T.Type = NUMBER; NV.NumberValue = val; }
    Value(int val)    { T.Type = INTEGER; NV.Int32Value = val; }
    // A value of a type without payload (UNSET, NULLTYPE, ...).
    explicit Value(type typeVal) { T.Type = (UByte)typeVal; }
    inline Value(const FunctionRef& func); // as2_object.h
    // A native function object for func (exe 0x142923bf0; appended for sfr_video_01).
    Value(ASStringContext* psc, CFunctionPtr func);
    // A getter/setter property (ValueProperty allocated in pheap).
    inline Value(const FunctionRef& getter, const FunctionRef& setter, MemoryHeap* pheap, ASRefCountCollector* pcc);
    Value(const ASString& str)
    {
        T.Type        = STRING;
        V.pStringNode = str.GetNode();
        V.pStringNode->AddRef();
    }

    // (sfr22) Some exe TUs never inline it and call 0x1429260b0 (sfr_as2_03): those define
    // MS2_AS2_VALUE_DTOR_CALL before the includes.
#ifdef MS2_AS2_VALUE_DTOR_CALL
    ~Value();
#else
    ~Value()
    {
        if (T.Type >= STRING)
            DropRefs();
    }
#endif

    void operator=(const Value& v); // exe 0x1429267a0

    // Releases the reference held by a STRING/OBJECT/CHARACTER/FUNCTION/PROPERTY value (exe 0x142939780).
    void DropRefs(); // exe 0x142939780

    type GetType() const { return (type)T.Type; }

    bool IsUndefined() const { return T.Type == UNDEFINED || T.Type == UNSET; }
    bool IsNull() const      { return T.Type == NULLTYPE; }
    bool IsSet() const       { return T.Type != UNSET; }
    bool IsBoolean() const   { return T.Type == BOOLEAN; }
    bool IsNumber() const    { return T.Type == NUMBER || T.Type == INTEGER; }
    bool IsString() const    { return T.Type == STRING; }
    bool IsObject() const    { return T.Type == OBJECT; }
    bool IsCharacter() const { return T.Type == CHARACTER; }
    bool IsFunction() const  { return T.Type == FUNCTION || T.Type == FUNCTIONNAME; }
    bool IsFunctionObject() const { return T.Type == FUNCTION; }
    bool IsFunctionName() const { return T.Type == FUNCTIONNAME; }
    bool IsProperty() const  { return T.Type == PROPERTY; }

    Number   ToNumber(Environment* penv) const;                         // exe 0x1429912d0
    SF_NOINLINE SInt32 ToInt32(Environment* penv) const;                // exe 0x142991210
    UInt32   ToUInt32(Environment* penv) const;                         // exe 0x142992440
    SF_NOINLINE bool ToBool(const Environment* penv) const;             // exe 0x142990f20
    Object*  ToObject(const Environment* penv) const;                   // exe 0x142991660
    SF_NOINLINE AvmCharacter* ToAvmCharacter(const Environment* penv) const; // exe 0x142990d60
    inline ObjectInterface* ToObjectInterface(const Environment* penv) const; // as2_avmcharacter.h
    inline const ASString&  GetCharacterNamePath(Environment* penv) const;    // as2_avmcharacter.h
    MS2_AS2_SCU ASString ToStringImpl(Environment* penv, int precision, bool debug) const; // exe 0x142991e70
    ASString ToString(Environment* penv, int precision = -1) const { return ToStringImpl(penv, precision, 0); }

    // These two (and SetBool) release unconditionally.
    void SetUndefined()
    {
        DropRefs();
        T.Type = UNDEFINED;
    }
    void SetNull()
    {
        DropRefs();
        T.Type = NULLTYPE;
    }
    void SetUnset()
    {
        DropRefs();
        T.Type = UNSET;
    }
    void SetNumber(Number val)
    {
        if (T.Type >= STRING)
            DropRefs();
        T.Type         = NUMBER;
        NV.NumberValue = val;
    }
    void SetInt(int val)
    {
        if (T.Type >= STRING)
            DropRefs();
        T.Type        = INTEGER;
        NV.Int32Value = val;
    }
    void SetUInt(unsigned val)
    {
        if (T.Type >= STRING)
            DropRefs();
        T.Type         = INTEGER;
        NV.UInt32Value = val;
    }
    void SetBool(bool val)
    {
        DropRefs();
        T.Type         = BOOLEAN;
        V.BooleanValue = val;
    }
    void SetString(const ASString& str)
    {
        if (T.Type >= STRING)
            DropRefs();
        T.Type        = STRING;
        V.pStringNode = str.GetNode();
        V.pStringNode->AddRef();
    }
    SF_NOINLINE void SetAsObject(Object* pobj); // exe 0x14297fcb0 (the exe calls it, never inlines it)

    // Conversion in place to a number / string (the string one of the SWF version: undefined is "" up to 6).
    void ConvertToNumber(Environment* penv);                            // exe 0x142935b50
    void ConvertToString(Environment* penv);                            // exe 0x142935b90
    void ConvertToStringVersioned(Environment* penv, unsigned version); // exe 0x142935be0

    // Arithmetic in place (the script operators).
    void Add(Environment* penv, const Value& v); // exe 0x14292e180
    void Add(Environment* penv, int v2);         // exe 0x14292e460
    void Sub(Environment* penv, const Value& v) { SetNumber(ToNumber(penv) - v.ToNumber(penv)); }
    void Mul(Environment* penv, const Value& v) { SetNumber(ToNumber(penv) * v.ToNumber(penv)); }
    // The out-of-line copy of Sub (exe 0x142990b70).
    void Sub_Call(Environment* penv, const Value& v);
    // Number division, NaN for 0 / 0 and a signed infinity for x / 0 (exe 0x142938ae0).
    void Div(Environment* penv, const Value& v);
    // The out-of-line copy of Mul (exe 0x142968f90): some unity-build call sites call it instead of inlining.
    void Mul_Call(Environment* penv, const Value& v);
    // The value of a PROPERTY: its getter called on pthis; false without a getter (exe 0x142954a50).
    bool GetPropertyValue(Environment* penv, ObjectInterface* pthis, Value* value) const;
    // Runs the setter of a PROPERTY on pthis (exe 0x14298a260).
    void SetPropertyValue(Environment* penv, ObjectInterface* pthis, const Value& val);

    Value ToPrimitive(Environment* penv, hint h = NoHint) const; // exe 0x142991850

    // The script == (exe 0x142965570).
    bool  IsEqual(Environment* penv, const Value& v) const;
    // The script comparisons: action 0 is ==, -1 <, 1 >; a boolean, or undefined when the operands do not compare
    // (exe 0x142935200).
    Value Compare(Environment* penv, const Value& v, int action) const;
    // The function held or named (FUNCTIONNAME), else a null reference. Out of line in the exe (0x142991190); the
    // unity build inlines it at some call sites.
    inline FunctionRef ToFunction(const Environment* penv) const; // as2_object.h

    // The function reference, object or property held (defined in sfr_as2_02).
    template<class Functor> void ForEachChild_GC(ASRefCountBaseType::Collector* prcc) const;
    // Release before collection: strings, characters and names drop their references, the collected objects
    // (objects, functions, properties) are left to the collector.
    void Finalize_GC()
    {
        if (T.Type == FUNCTION)
            V.FunctionValue.Finalize_GC();
        else if (T.Type >= STRING && T.Type != OBJECT && T.Type != PROPERTY)
            DropRefs();
    }

    // (appended for sfr_as2_07)
    // The character of a CHARACTER value, 0 once it is gone or not interactive (exe 0x1429910b0).
    InteractiveObject* ToCharacter(const Environment* penv) const;
    // The handler of a RESOLVEHANDLER value, else a null reference (exe 0x142991c60).
    FunctionRef ToResolveHandler() const;
    // The string with the debug spelling of objects (exe 0x142991110).
    ASString ToDebugString(Environment* penv) const;
    // undefined is "" up to SWF 6 (exe 0x1429923c0).
    ASString ToStringVersioned(Environment* penv, unsigned version) const;
    // Appends str to the string of this value (exe 0x142990240).
    void StringConcat(Environment* penv, const ASString& str);
    void Sub(Environment* penv, int v2); // exe 0x142990be0
    void SetAsCharacterHandle(CharacterHandle* pchar);  // exe 0x14297fc00
    void SetAsCharacter(InteractiveObject* pchar);      // exe 0x14297fba0
    void SetAsObjectInterface(ObjectInterface* pobj);   // exe 0x14297fdb0
    SF_NOINLINE void SetAsFunction(const FunctionRefBase& func); // exe 0x14297fc40
    void SetAsResolveHandler(const FunctionRefBase& func); // exe 0x14297fe60
    // The exe's out-of-line copies of the inline setters and conversions.
    void             SetString_Call(const ASString& str);                       // exe 0x14298b9f0
    void             SetInt_Call(int val);                                      // exe 0x142981b70
    void             SetUInt_Call(unsigned val);                                // exe 0x14298c9e0
    ObjectInterface* ToObjectInterface_Call(const Environment* penv) const;     // exe 0x142991810
    FunctionRef      ToFunction_Call(const Environment* penv) const;            // exe 0x142991190

protected:
    // The function of a FUNCTIONNAME value, looked up by name (exe 0x14297ec30).
    MS2_AS2_SCU FunctionRef ResolveFunctionName(const Environment* penv) const;
};

// Getter/setter pair of an addProperty member. 0x50 bytes.
struct ValueProperty : public ASRefCountBase<ValueProperty>
{
    FunctionRef GetterMethod; // +0x20
    FunctionRef SetterMethod; // +0x38

    ValueProperty(ASRefCountCollector* pcc, const FunctionRef& getterMethod, const FunctionRef& setterMethod);

protected:
    virtual void ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const;
    virtual void Finalize_GC();
};

inline Value::Value(const FunctionRef& getter, const FunctionRef& setter, MemoryHeap* pheap, ASRefCountCollector* pcc)
{
    T.Type      = PROPERTY;
    V.pProperty = new (pheap) ValueProperty(pcc, getter, setter);
}

// Object member: the value with its property flags stored in the value's second byte.
class Member
{
public:
    Value mValue;

    Member() { mValue.T.PropFlags = 0; }
    Member(const Value& value, const PropFlags flags = PropFlags()) : mValue(value)
    {
        mValue.T.PropFlags = flags.Flags;
    }
    // The value copy leaves the flags out.
    Member(const Member& m) : mValue(m.mValue) { mValue.T.PropFlags = m.mValue.T.PropFlags; }
    // So does the value assignment.
    void operator=(const Member& m)
    {
        mValue             = m.mValue;
        mValue.T.PropFlags = m.mValue.T.PropFlags;
    }

    const Value& GetMemberValue() const { return mValue; }
    Value&       GetMemberValue()       { return mValue; }
    PropFlags    GetMemberFlags() const { return PropFlags(mValue.T.PropFlags); }
    void         SetMemberFlags(const PropFlags flags) { mValue.T.PropFlags = flags.Flags; }
    void         Finalize_GC() { mValue.Finalize_GC(); }
};

}}} // namespace Scaleform::GFx::AS2

#endif
