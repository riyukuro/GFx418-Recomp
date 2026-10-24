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

// The script number of a string (sfr_as2_07).
SF_NOINLINE bool StringToNumber(Number* result, const char* str);
// Value::GetCharacterNamePath as the exe has it out of line (sfr_as2_05).
SF_NOINLINE const ASString& Value_GetCharacterNamePath(const Value* pval, Environment* penv);

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
// MS2-FUNCTIONAL: branch layout differs; same behavior
// @0x1429912d0
Number Value::ToNumber(Environment* penv) const
{
    if (T.Type == NUMBER)
        return NV.NumberValue;
    else if (T.Type == INTEGER)
        return (Number)NV.Int32Value;
    else if (T.Type == STRING)
    {
        Number result;
        if (StringToNumber(&result, V.pStringNode->pData))
            return result;
        return NumberUtil::NaN();
    }
    else if (T.Type == NULLTYPE)
    {
        if (penv->GetVersion() <= 6)
            return 0;
        return NumberUtil::NaN();
    }
    else if (T.Type == BOOLEAN)
        return V.BooleanValue ? 1.0 : 0.0;
    else if (T.Type == CHARACTER)
        return NumberUtil::NaN();
    else if (T.Type == OBJECT || T.Type == FUNCTION)
    {
        if (T.Type == OBJECT && !V.pObjectValue)
            return 0;

        Value            val;
        ObjectInterface* pobj = ToObjectInterface_Call(penv);
        if (penv && pobj->GetMemberRaw(&penv->StringContext, penv->GetBuiltin(Builtin_valueOf), &val))
        {
            Number ret;
            if (penv->FuncCallNestingLevel++ < 255)
            {
                Value       result;
                FunctionRef func = val.ToFunction(penv);
                if (func.Function)
                    func.Invoke(FnCall(&result, pobj, penv, 0, 0));
                if (result.T.Type >= NULLTYPE && result.T.Type <= STRING)
                    ret = result.ToNumber(penv);
                else
                    ret = NumberUtil::NaN();
            }
            else
            {
                ret = NumberUtil::NaN();
                if (penv->IsVerboseActionErrors())
                    penv->LogScriptError("Stack overflow, max level of 255 nested calls of valueOf is reached.");
            }
            --penv->FuncCallNestingLevel;
            return ret;
        }
        if (T.Type == CHARACTER)
            return NumberUtil::NaN();
        const char* ptext = pobj->GetTextValue(penv);
        return ptext ? atof(ptext) : 0;
    }
    else if (T.Type == UNDEFINED || T.Type == UNSET)
    {
        unsigned version = penv->GetVersion();
        if (version > 0 && version <= 6)
            return 0;
        return NumberUtil::NaN();
    }
    return 0;
}

// An object (or clip, or function) is what its valueOf gives; without one, a clip is its target path and an object
// its text value or string. A function name becomes its function; the rest are primitive already.
// MS2-FUNCTIONAL: the FunctionRef copies and the result copy are scheduled differently; same behavior
// @0x142991850
Value Value::ToPrimitive(Environment* penv, hint h) const
{
    SF_UNUSED(h);
    if (T.Type == OBJECT || T.Type == CHARACTER || T.Type == FUNCTION)
    {
        Value            val;
        ObjectInterface* pobj = ToObjectInterface(penv);
        if (penv && pobj && pobj->GetMemberRaw(&penv->StringContext, penv->GetBuiltin(Builtin_valueOf), &val))
        {
            Value result;
            if (penv->FuncCallNestingLevel++ < 255)
            {
                FunctionRef func = val.ToFunction(penv);
                if (func.Function)
                    func.Invoke(FnCall(&result, pobj, penv, 0, 0));
            }
            else if (penv->IsVerboseActionErrors())
                penv->LogScriptError("Stack overflow, max level of 255 nested calls of valueOf is reached.");
            --penv->FuncCallNestingLevel;
            return result;
        }

        Value str;
        if (T.Type == CHARACTER && V.pCharHandle)
            str = Value(Value_GetCharacterNamePath(this, penv));
        else
        {
            const char* ptext = (T.Type == OBJECT && V.pObjectValue) ? V.pObjectValue->GetTextValue(penv) : 0;
            if (ptext)
                str = Value(penv->CreateString(ptext));
            else
                str = Value(ToStringImpl(penv, -1, false));
        }
        return str;
    }
    else if (T.Type == FUNCTIONNAME)
    {
        FunctionRef func = ResolveFunctionName(penv);
        if (func.Function)
            return Value(func);
    }
    return *this;
}

// The string of a value: numbers with the given precision (-1 for the default), an object its toString's result (not
// asked in debug mode), else its text value, a clip its target path.
// MS2-FUNCTIONAL: branch layout and string refcount scheduling differ; same behavior
// @0x142991e70
ASString Value::ToStringImpl(Environment* penv, int precision, bool debug) const
{
    ASString stringVal = penv->GetBuiltin(ASBuiltin_empty_);
    switch (T.Type)
    {
    case UNDEFINED:
    case UNSET:
        stringVal = penv->GetBuiltin(ASBuiltin_undefined);
        break;
    case NULLTYPE:
        stringVal = penv->GetBuiltin(Builtin_null);
        break;
    case BOOLEAN:
        stringVal = penv->GetBuiltin(V.BooleanValue ? Builtin_true : Builtin_false);
        break;
    case NUMBER:
    {
        char buffer[64];
        stringVal = penv->CreateString(
            NumberUtil::ToString(NV.NumberValue, buffer, sizeof(buffer), (precision < 0) ? 10 : -precision));
        break;
    }
    case INTEGER:
    {
        char buffer[64];
        stringVal = penv->CreateString(NumberUtil::IntToString(NV.Int32Value, buffer, sizeof(buffer)));
        break;
    }
    case STRING:
        stringVal.AssignNode(V.pStringNode);
        break;
    case OBJECT:
    case CHARACTER:
    {
        Value            val;
        ObjectInterface* pobj = ToObjectInterface_Call(penv);
        if (!debug && pobj && pobj->GetMemberRaw(&penv->StringContext, penv->GetBuiltin(ASBuiltin_toString), &val))
        {
            if (penv->FuncCallNestingLevel++ < 255)
            {
                Value       result;
                FunctionRef func = val.ToFunction(penv);
                if (func.Function)
                    func.Invoke(FnCall(&result, pobj, penv, 0, 0));
                stringVal = result.ToStringImpl(penv, -1, false);
            }
            else
            {
                stringVal = penv->GetBuiltin(ASBuiltin_typeObject_);
                if (penv->IsVerboseActionErrors())
                    penv->LogScriptError("Stack overflow, max level of 255 nested calls of toString is reached.");
            }
            --penv->FuncCallNestingLevel;
            break;
        }
        const char* ptext = (T.Type == OBJECT && V.pObjectValue) ? V.pObjectValue->GetTextValue(penv) : 0;
        if (ptext)
            stringVal = penv->CreateString(ptext);
        else if (T.Type == CHARACTER && V.pCharHandle)
            stringVal = Value_GetCharacterNamePath(this, penv);
        else
            stringVal = penv->GetBuiltin(ASBuiltin_objectObject_);
        break;
    }
    case FUNCTION:
    case FUNCTIONNAME:
        stringVal = penv->GetBuiltin(ASBuiltin_typeFunction_);
        break;
    case PROPERTY:
        stringVal = penv->CreateConstString("[property]");
        break;
    case RESOLVEHANDLER:
        stringVal = penv->CreateConstString("[resolveHandler]");
        break;
    default:
        stringVal = penv->GetBuiltin(Builtin_badtype_);
        break;
    }
    return stringVal;
}

// A host value as a script value: managed strings keep their node, the others are made in the movie's string
// manager; objects and arrays are the AS objects they were made from, display objects their character handles.
// MS2-FUNCTIONAL: the setter tail calls are laid out differently; same behavior
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
        ASStringNode* pnode = gfxVal.IsManagedValue()
                                  ? reinterpret_cast<ASStringNode*>(const_cast<char**>(gfxVal.mValue.pStringManaged))
                                  : GetStringManager()->pStringManager->CreateStringNode(gfxVal.mValue.pString);
        pdestVal->SetString(ASString(pnode));
        break;
    }
    case GFx::Value::VT_StringW:
    {
        ASStringNode* pnode =
            gfxVal.IsManagedValue()
                ? *reinterpret_cast<ASStringNode* const*>(reinterpret_cast<const UByte*>(gfxVal.mValue.pStringW) - 8)
                : GetStringManager()->pStringManager->CreateStringNode(gfxVal.mValue.pStringW, -1);
        pdestVal->SetString(ASString(pnode));
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
