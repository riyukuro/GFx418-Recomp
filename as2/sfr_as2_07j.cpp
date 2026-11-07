// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// the conversions of a script value to a number, a primitive and a string (an object is asked through its valueOf /
// toString), and a host GFx::Value turned into a script value.
// MS2-UNIT: sfr_as2_07j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429912d0-0x142991660 .text$mn
// MS2-RANGE: 0x142991850-0x142991c5d .text$mn
// MS2-RANGE: 0x142991e70-0x14299238a .text$mn
// MS2-RANGE: 0x142992ee0-0x142993062 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/gfx/gfx_value.h"
#include <stdlib.h>

// Value::SetNumber as the exe has it out of line (folded with a copy of another unit).
void FUN_14000d250(Scaleform::GFx::AS2::Value* value, double number);

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {
struct ToNumberInlineTag {};
enum { ToNumber_MAX_RECURSION_LEVEL = 255 };
// Environment::RecursionGuardStart (SDK), inlined.
SF_INLINE bool ToNumberRecursionGuardStart(Environment* penv)
{
    return (penv->FuncCallNestingLevel++ < ToNumber_MAX_RECURSION_LEVEL);
}
}

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it here.
static SF_FORCEINLINE void ToNumberSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
{
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->Release();
    p->pLocalFrame = localFrame;
    if (weakRef)
        p->Flags |= FunctionRefBase::FuncRef_Weak;
    else
        p->Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->AddRef();
}

// FunctionRefBase::Init(orig) with the SetLocalFrame call expanded.
template<>
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, ToNumberInlineTag)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        ToNumberSetLocalFrame(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

namespace {
// ASString::AssignNode, inlined (the exe shares its tail with the other cases).
struct ToStringAssignAccess : ASString
{
    static SF_FORCEINLINE void AssignNode(ASString& s, ASStringNode* pnode)
    {
        ToStringAssignAccess& t = static_cast<ToStringAssignAccess&>(s);
        pnode->AddRef();
        t.pNode->Release();
        t.pNode = pnode;
    }
    // ASString::operator=, inlined.
    static SF_FORCEINLINE void AssignFrom(ASString& s, const ASString& src)
    {
        AssignNode(s, static_cast<const ToStringAssignAccess&>(src).pNode);
    }
};
// Value::ToFunction (exe 0x142991190), inlined.
struct ToNumberValueAccess : Value
{
    static SF_FORCEINLINE FunctionRef ToFunction(const Value& v, const Environment* penv)
    {
        switch (v.T.Type)
        {
        case FUNCTIONNAME:
            return static_cast<const ToNumberValueAccess&>(v).ResolveFunctionName(penv);
        case FUNCTION:
            return FunctionRef(v.V.FunctionValue, ToNumberInlineTag());
        default:;
        }
        return FunctionRef();
    }
};
}

// The script number of a string (sfr_as2_07).
SF_NOINLINE __declspec(noalias) bool StringToNumber(Number* result, const char* str);
// Value::GetCharacterNamePath as the exe has it out of line (sfr_as2_05).
SF_NOINLINE __declspec(noalias) const ASString& Value_GetCharacterNamePath(const Value* pval, Environment* penv);

namespace {

// Builtin strings of the conversions that ASBuiltinType does not name yet.
const int Builtin_badtype_ = 47; // the string of a value of no known type
const int Builtin_null     = 52;
const int Builtin_true     = 53;
const int Builtin_false    = 54;
const int Builtin_valueOf  = 87;

} // namespace

// Undefined is 0 up to SWF 6 and NaN after it, null 0 before SWF 7; an object is the number its valueOf gives (or
// that of its text value).
// @0x1429912d0
Number Value::ToNumber(Environment* penv) const
{
    if (T.Type == NUMBER)
    {
        return NV.NumberValue;
    }
    else if (T.Type == INTEGER)
    {
        return (Number)NV.Int32Value;
    }
    else if (T.Type == STRING)
    {
        Number num;
        if (!StringToNumber(&num, V.pStringNode->pData))
        {
            num = NumberUtil::NaN();
        }
        return num;
    }
    else if (T.Type == NULLTYPE)
    {
        unsigned version = penv->GetVersion();
        if (version <= 6)
            return 0;
        else
            return NumberUtil::NaN();
    }
    else if (T.Type == BOOLEAN)
    {
        return V.BooleanValue ? (Number)1 : (Number)0;
    }
    else if (T.Type == CHARACTER)
    {
        return NumberUtil::NaN();
    }
    else if (((T.Type == OBJECT) && V.pObjectValue) || (T.Type == FUNCTION))
    {
        Value            toValueFunc;
        ObjectInterface* piobj = ToObjectInterface_Call(penv);
        if (penv && piobj->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(Builtin_valueOf), &toValueFunc))
        {
            Number retVal;
            if (ToNumberRecursionGuardStart(penv))
            {
                Value       result;
                FunctionRef func(ToNumberValueAccess::ToFunction(toValueFunc, penv));
                if (func.Function)
                {
                    FnCall fnCall(&result, piobj, penv, 0, 0);
                    func.Function->Invoke(fnCall, func.pLocalFrame, NULL);
                }
                if (result.T.Type >= NULLTYPE && result.T.Type <= STRING)
                    retVal = result.ToNumber(penv);
                else
                    retVal = NumberUtil::NaN();
            }
            else
            {
                retVal = NumberUtil::NaN();
                if (penv->IsVerboseActionErrors())
                    penv->LogScriptError("Stack overflow, max level of 255 nested calls of valueOf is reached.");
            }
            --penv->FuncCallNestingLevel;
            return retVal;
        }
        else
        {
            if (T.Type == CHARACTER)
                return NumberUtil::NaN();
            const char* ptextval = piobj->GetTextValue(penv);
            if (ptextval)
            {
                return (Number)atof(ptextval);
            }
        }
        return 0;
    }
    else if (IsUndefined())
    {
        unsigned version = penv->GetVersion();
        if (version > 0 && version <= 6)
            return 0;
        else
            return NumberUtil::NaN();
    }
    else
    {
        return 0;
    }
}

// An object (or clip, or function) is what its valueOf gives; without one, a clip is its target path and an object
// its text value or string. A function name becomes its function; the rest are primitive already.
// MS2-FUNCTIONAL: the exe (LTCG) treats CreateStringNode and ToStringImpl as non-throwing here, so it has no UNDEFINED store and no DropRefs type checks on ret; same behavior
// @0x142991850
Value Value::ToPrimitive(Environment* penv, hint h) const
{
    SF_UNUSED(h);
    if ((T.Type == OBJECT) || (T.Type == CHARACTER) || (T.Type == FUNCTION))
    {
        Value            toValueFunc;
        ObjectInterface* piobj = ToObjectInterface(penv);

        if (penv && piobj && piobj->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(Builtin_valueOf), &toValueFunc))
        {
            Value result;
            if (ToNumberRecursionGuardStart(penv))
            {
                FunctionRef func(ToNumberValueAccess::ToFunction(toValueFunc, penv));
                if (func.Function)
                {
                    FnCall fnCall(&result, piobj, penv, 0, 0);
                    func.Function->Invoke(fnCall, func.pLocalFrame, NULL);
                }
            }
            else
            {
                if (penv->IsVerboseActionErrors())
                    penv->LogScriptError("Stack overflow, max level of 255 nested calls of valueOf is reached.");
            }
            --penv->FuncCallNestingLevel;

            return result;
        }
        else
        {
            Value       ret;
            const char* pstr;

            if ((T.Type == CHARACTER) && V.pCharHandle)
            {
                ret.SetString(Value_GetCharacterNamePath(this, penv));
            }
            else if ((T.Type == OBJECT) && V.pObjectValue &&
                     (pstr = V.pObjectValue->GetTextValue(penv)) != 0)
            {
                ret.SetString(penv->CreateString(pstr));
            }
            else
            {
                ret.SetString(ToString(penv));
            }
            return ret;
        }
    }
    else if (T.Type == FUNCTIONNAME)
    {
        FunctionRef funcRef = ResolveFunctionName(penv);
        if (!funcRef.IsNull())
        {
            return funcRef;
        }
    }

    return *this;
}

// The string of a value: numbers with the given precision (-1 for the default), an object its toString's result (not
// asked in debug mode), else its text value, a clip its target path.
// @0x142991e70
ASString Value::ToStringImpl(Environment* penv, int precision, bool debug) const
{
    ASString stringVal(penv->GetBuiltin(ASBuiltin_empty_));

    switch (T.Type)
    {
    case STRING:
    {
        ToStringAssignAccess::AssignNode(stringVal, V.pStringNode);
    }
    break;

    case NUMBER:
    {
        char buf[64];
        stringVal =
            penv->CreateString(NumberUtil::ToString(NV.NumberValue, buf, sizeof(buf), (precision < 0) ? 10 : -precision));
    }
    break;
    case INTEGER:
    {
        char buf[64];
        stringVal = penv->CreateString(NumberUtil::IntToString(NV.Int32Value, buf, sizeof(buf)));
    }
    break;
    case UNSET:
    case UNDEFINED:
    {
        stringVal = penv->GetBuiltin(ASBuiltin_undefined);
    }
    break;
    case NULLTYPE:
    {
        stringVal = penv->GetBuiltin(Builtin_null);
    }
    break;
    case BOOLEAN:
    {
        stringVal = penv->GetBuiltin(V.BooleanValue ? Builtin_true : Builtin_false);
    }
    break;
    case OBJECT:
    case CHARACTER:
    {
        union StrHolder { ASString s; StrHolder() {} ~StrHolder() {} } resultStr;
        Value            toStringFunc;
        ObjectInterface* piobj = ToObjectInterface_Call(penv);

        if (!debug && piobj && piobj->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_toString), &toStringFunc))
        {
            if (ToNumberRecursionGuardStart(penv))
            {
                Value       result;
                FunctionRef func(ToNumberValueAccess::ToFunction(toStringFunc, penv));
                if (func.Function)
                {
                    FnCall fnCall(&result, piobj, penv, 0, 0);
                    func.Function->Invoke(fnCall, func.pLocalFrame, NULL);
                }
                ::new (&resultStr.s) ASString(result.ToStringImpl(penv, -1, false));
                ToStringAssignAccess::AssignFrom(stringVal, resultStr.s);
                resultStr.s.~ASString();
            }
            else
            {
                stringVal = penv->GetBuiltin(ASBuiltin_typeObject_);
                if (penv->IsVerboseActionErrors())
                    penv->LogScriptError("Stack overflow, max level of 255 nested calls of toString is reached.");
            }
            --penv->FuncCallNestingLevel;
        }
        else
        {
            const char* ptext;

            if ((T.Type == OBJECT) && V.pObjectValue && (ptext = V.pObjectValue->GetTextValue(penv)) != 0)
            {
                stringVal = penv->CreateString(ptext);
            }
            else if ((T.Type == CHARACTER) && V.pCharHandle)
            {
                stringVal = Value_GetCharacterNamePath(this, penv);
            }
            else
            {
                stringVal = penv->GetBuiltin(ASBuiltin_objectObject_);
            }
        }
    }
    break;
    case FUNCTION:
    case FUNCTIONNAME:
    {
        stringVal = penv->GetBuiltin(ASBuiltin_typeFunction_);
    }
    break;
    case PROPERTY:
    {
        stringVal = penv->CreateConstString("[property]");
    }
    break;
    case RESOLVEHANDLER:
    {
        stringVal = penv->CreateConstString("[resolveHandler]");
    }
    break;
    default:
    {
        stringVal = penv->GetBuiltin(Builtin_badtype_);
    }
    }
    return stringVal;
}

// A host value as a script value: managed strings keep their node, the others are made in the movie's string
// manager; objects and arrays are the AS objects they were made from, display objects their character handles.
// @0x142992ee0
void MovieRoot::Value2ASValue(const GFx::Value& gfxVal, Value* pdestVal)
{
    switch (gfxVal.GetType())
    {
    case GFx::Value::VT_Undefined:
        pdestVal->SetUndefined();
        break;
    case GFx::Value::VT_Null:
        pdestVal->SetNull();
        break;
    case GFx::Value::VT_Boolean:
        pdestVal->SetBool(gfxVal.mValue.BValue);
        break;
    case GFx::Value::VT_Int:
        pdestVal->SetInt_Call(gfxVal.mValue.IValue);
        break;
    case GFx::Value::VT_UInt:
        pdestVal->SetUInt_Call(gfxVal.mValue.UIValue);
        break;
    case GFx::Value::VT_Number:
        FUN_14000d250(pdestVal, gfxVal.mValue.NValue);
        break;
    case GFx::Value::VT_String:
    {
        if (gfxVal.IsManagedValue())
            pdestVal->SetString(
                ASString(reinterpret_cast<ASStringNode*>(const_cast<char**>(gfxVal.mValue.pStringManaged))));
        else
            pdestVal->SetString(ASString(GetStringManager()->pStringManager->CreateStringNode(gfxVal.mValue.pString)));
        break;
    }
    case GFx::Value::VT_StringW:
    {
        if (gfxVal.IsManagedValue())
            pdestVal->SetString(ASString(
                *reinterpret_cast<ASStringNode* const*>(reinterpret_cast<const UByte*>(gfxVal.mValue.pStringW) - 8)));
        else
            pdestVal->SetString(
                ASString(GetStringManager()->pStringManager->CreateStringNode(gfxVal.mValue.pStringW, -1)));
        break;
    }
    case GFx::Value::VT_Object:
    case GFx::Value::VT_Array:
        pdestVal->SetAsObject(static_cast<Object*>(static_cast<ObjectInterface*>(gfxVal.mValue.pData)));
        break;
    case GFx::Value::VT_DisplayObject:
        pdestVal->SetAsCharacterHandle(static_cast<CharacterHandle*>(gfxVal.mValue.pData));
        break;
    default:
        break;
    }
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
