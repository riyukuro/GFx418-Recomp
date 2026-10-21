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

// Reference to a function object plus the local frame it closes over (0x18 bytes). Flags: 1 = the function
// is held without a count (internal), 2 = the frame is held weakly.
class FunctionRefBase
{
public:
    enum FuncRef_Flags
    {
        FuncRef_Internal = 1,
        FuncRef_Weak     = 2
    };

    FunctionObject* Function;    // +0x00
    LocalFrame*     pLocalFrame; // +0x08
    UByte           Flags;       // +0x10

    bool IsNull() const { return Function == 0; }

    void Init(FunctionObject* poriginal = 0, UByte flags = 0);
    void Init(FunctionObject& original, UByte flags = 0);
    void Init(const FunctionRefBase& orig, UByte flags = 0);
    void DropRefs();
    void SetLocalFrame(LocalFrame* localFrame, bool weakRef = 0);
    void Assign(const FunctionRefBase& orig);

    FunctionObject* operator->() const { return Function; }
    FunctionObject& operator*() const  { return *Function; }
    FunctionObject* GetObjectPtr() const { return Function; }

    // The function and the frame (defined in sfr_as2_02).
    template<class Functor> void ForEachChild_GC(ASRefCountBaseType::Collector* prcc) const;
};

class FunctionRef : public FunctionRefBase
{
public:
    FunctionRef(FunctionObject* poriginal = 0) { Init(poriginal); }
    FunctionRef(FunctionObject& original) { Init(original); }
    FunctionRef(const FunctionRef& orig) { Init(orig); }
    ~FunctionRef() { DropRefs(); }

    const FunctionRef& operator=(const FunctionRef& orig)
    {
        Assign(orig);
        return *this;
    }
};

// ActionScript 2 value. 0x20 bytes; strings/objects/functions (Type >= STRING) hold references.
class Value
{
public:
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
    Value(const ASString& str)
    {
        T.Type        = STRING;
        V.pStringNode = str.GetNode();
        V.pStringNode->AddRef();
    }

    ~Value()
    {
        if (T.Type >= STRING)
            DropRefs();
    }

    const Value& operator=(const Value& v); // exe 0x1429267a0

    // Releases the reference held by a STRING/OBJECT/CHARACTER/FUNCTION/PROPERTY value (exe 0x142939780).
    void DropRefs();

    type GetType() const { return (type)T.Type; }

    bool IsUndefined() const { return T.Type == UNDEFINED || T.Type == UNSET; }
    bool IsNull() const      { return T.Type == NULLTYPE; }
    bool IsBoolean() const   { return T.Type == BOOLEAN; }
    bool IsNumber() const    { return T.Type == NUMBER || T.Type == INTEGER; }
    bool IsString() const    { return T.Type == STRING; }
    bool IsObject() const    { return T.Type == OBJECT; }
    bool IsCharacter() const { return T.Type == CHARACTER; }
    bool IsFunction() const  { return T.Type == FUNCTION; }
    bool IsProperty() const  { return T.Type == PROPERTY; }

    Number   ToNumber(Environment* penv) const;                         // exe 0x1429912d0
    SInt32   ToInt32(Environment* penv) const;                          // exe 0x142991210
    bool     ToBool(const Environment* penv) const;                     // exe 0x142990f20
    Object*  ToObject(const Environment* penv) const;                   // exe 0x142991660
    AvmCharacter*    ToAvmCharacter(const Environment* penv) const;     // exe 0x142990d60
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
    void SetAsObject(Object* pobj); // exe 0x14297fcb0

    // Arithmetic in place (the script operators).
    void Add(Environment* penv, const Value& v); // exe 0x14292e180
    void Sub(Environment* penv, const Value& v) { SetNumber(ToNumber(penv) - v.ToNumber(penv)); }
    void Mul(Environment* penv, const Value& v) { SetNumber(ToNumber(penv) * v.ToNumber(penv)); }
    // The out-of-line copy of Mul (exe 0x142968f90): some unity-build call sites call it instead of inlining.
    void Mul_Call(Environment* penv, const Value& v);

    Value ToPrimitive(Environment* penv, hint h = NoHint) const; // exe 0x142991850

    // The function reference, object or property held (defined in sfr_as2_02).
    template<class Functor> void ForEachChild_GC(ASRefCountBaseType::Collector* prcc) const;
};

// Getter/setter pair of an addProperty member. 0x50 bytes.
struct ValueProperty : public ASRefCountBase<ValueProperty>
{
    FunctionRef GetterMethod; // +0x20
    FunctionRef SetterMethod; // +0x38

    ValueProperty(ASRefCountCollector* pcc, const FunctionRef& getterMethod, const FunctionRef& setterMethod);
};

// Object member: the value with its property flags stored in the value's second byte.
class Member
{
public:
    Value mValue;

    Member() {}
    Member(const Value& value, const PropFlags flags = PropFlags()) : mValue(value)
    {
        mValue.T.PropFlags = flags.Flags;
    }

    const Value& GetMemberValue() const { return mValue; }
    Value&       GetMemberValue()       { return mValue; }
    PropFlags    GetMemberFlags() const { return PropFlags(mValue.T.PropFlags); }
    void         SetMemberFlags(const PropFlags flags) { mValue.T.PropFlags = flags.Flags; }
};

}}} // namespace Scaleform::GFx::AS2

#endif
