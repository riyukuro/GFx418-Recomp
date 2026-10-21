// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 from ResizeNoConstruct to the
// XML classes: the value setters and conversions, member setters, IME, Sound and XML objects.
// MS2-UNIT: sfr_as2_07
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297f2c0-0x14297f3d0 .text$mn
// MS2-RANGE: 0x14297fba0-0x14297fed0 .text$mn
// MS2-RANGE: 0x1429814c0-0x142981600 .text$mn
// MS2-RANGE: 0x142981b70-0x142981bb0 .text$mn
// MS2-RANGE: 0x142981bc0-0x142981bf0 .text$mn
// MS2-RANGE: 0x142981df0-0x142981f00 .text$mn
// MS2-RANGE: 0x1429889c0-0x142988a30 .text$mn
// MS2-RANGE: 0x142989d20-0x142989e90 .text$mn
// MS2-RANGE: 0x14298a3d0-0x14298a480 .text$mn
// MS2-RANGE: 0x14298a520-0x14298a5a0 .text$mn
// MS2-RANGE: 0x14298b9f0-0x14298ba60 .text$mn
// MS2-RANGE: 0x14298c9e0-0x14298ca20 .text$mn
// MS2-RANGE: 0x14298cc30-0x14298cc70 .text$mn
// MS2-RANGE: 0x14298cc80-0x14298cce0 .text$mn
// MS2-RANGE: 0x14298dc00-0x14298dcb0 .text$mn
// MS2-RANGE: 0x14298de30-0x14298dee0 .text$mn
// MS2-RANGE: 0x14298ee10-0x14298ee70 .text$mn
// MS2-RANGE: 0x142990240-0x1429902c0 .text$mn
// MS2-RANGE: 0x142990960-0x142990c30 .text$mn
// MS2-RANGE: 0x142990c40-0x142990cc0 .text$mn
// MS2-RANGE: 0x142990d00-0x142990dd0 .text$mn
// MS2-RANGE: 0x142990e40-0x142990ea0 .text$mn
// MS2-RANGE: 0x142990f20-0x142991050 .text$mn
// MS2-RANGE: 0x142991080-0x142991140 .text$mn
// MS2-RANGE: 0x142991190-0x1429912d0 .text$mn
// MS2-RANGE: 0x142991810-0x142991850 .text$mn
// MS2-RANGE: 0x142991c60-0x142991cd0 .text$mn
// MS2-RANGE: 0x142991d00-0x142991d30 .text$mn
// MS2-RANGE: 0x142991e10-0x142991e70 .text$mn
// MS2-RANGE: 0x1429923c0-0x142992540 .text$mn
// MS2-RANGE: 0x142992780-0x142992830 .text$mn
// MS2-RANGE: 0x142992e30-0x142992ee0 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/kernel/sf_std.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

namespace Scaleform { namespace GFx { namespace AS2 {

// The script number of a string: hex "0x..", octal "0..", else decimal; false unless the whole string was used.
SF_NOINLINE bool StringToNumber(Number* result, const char* str);

// The out-of-line watchpoint table helpers the exe calls (COMDATs of other units).
void WatchpointHash_Destruct(ASStringHash_GC<Object::Watchpoint>* phash); // exe 0x1429246b0
// GetCaseCheck / RemoveCaseCheck of the watchpoint table (exe 0x142949eb0 / 0x14297cae0).
const Object::Watchpoint* WatchpointHash_GetCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key,
                                                      bool caseSensitive);
void WatchpointHash_RemoveCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key,
                                    bool caseSensitive);

// @0x14297fba0
void Value::SetAsCharacter(InteractiveObject* pchar)
{
    SetAsCharacterHandle(pchar ? pchar->GetCharacterHandle() : 0);
}

// @0x14297fc00
void Value::SetAsCharacterHandle(CharacterHandle* pchar)
{
    if (T.Type != CHARACTER || V.pCharHandle != pchar)
    {
        DropRefs();
        T.Type        = CHARACTER;
        V.pCharHandle = pchar;
        if (pchar)
            pchar->AddRef();
    }
}

// @0x14297fc40
void Value::SetAsFunction(const FunctionRefBase& func)
{
    if (T.Type != FUNCTION || V.FunctionValue.Function != func.Function)
    {
        DropRefs();
        T.Type = FUNCTION;
        V.FunctionValue.Init(func);
    }
}

// @0x14297fcb0
void Value::SetAsObject(Object* pobj)
{
    if (pobj && pobj->IsFunction())
        SetAsFunction(pobj->ToFunction());
    else if (T.Type != OBJECT || V.pObjectValue != pobj)
    {
        DropRefs();
        T.Type         = OBJECT;
        V.pObjectValue = pobj;
        if (pobj)
            pobj->AddRef();
    }
}

// @0x14297fdb0
void Value::SetAsObjectInterface(ObjectInterface* pobj)
{
    if (pobj->IsASCharacter())
        SetAsCharacter(pobj->ToCharacter());
    else
        SetAsObject(pobj->ToASObject());
}

// @0x14297fe60
void Value::SetAsResolveHandler(const FunctionRefBase& func)
{
    DropRefs();
    T.Type = RESOLVEHANDLER;
    V.FunctionValue.Init(func);
}

// @0x1429889c0
bool Object::SetMemberFlags(ASStringContext* psc, const ASString& name, const UByte flags)
{
    Member member;
    if (FindMember(psc, name, &member))
    {
        member.mValue.T.PropFlags = flags;
        Members.Set(name, member);
        return true;
    }
    return false;
}

// MS2-FUNCTIONAL the exe keeps the constructor function in a register across Set_constructor (unity build)
// @0x14298a3d0
void FunctionObject::SetProtoAndCtor(ASStringContext* psc, Object* pprototype)
{
    Set__proto__(psc, pprototype);
    FunctionRef ctor = pprototype->Get_constructor(psc);
    if (!ctor.IsNull())
        Set_constructor(psc, ctor);
}

// MS2-FUNCTIONAL register permutation (rbx / rsi / rdi)
// @0x14298a520
void FunctionObject::SetPrototype(ASStringContext* psc, Object* pprototype)
{
    SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_prototype), Value(pprototype));
}

// @0x14298dc00
void ObjectInterface::Set__constructor__(ASStringContext* psc, const FunctionRef& ctorFunc)
{
    SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin___constructor__), Value(ctorFunc),
                 PropFlags(PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum));
}

// @0x14298de30
void ObjectInterface::Set_constructor(ASStringContext* psc, const FunctionRef& ctorFunc)
{
    SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_constructor), Value(ctorFunc),
                 PropFlags(PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum));
}

// @0x142990240
void Value::StringConcat(Environment* penv, const ASString& str)
{
    ASString result(ToString(penv) + str);
    DropRefs();
    T.Type        = STRING;
    V.pStringNode = result.GetNode();
    V.pStringNode->AddRef();
}

// @0x142990a10
bool StringToNumber(Number* result, const char* str)
{
    char*  tail = 0;
    size_t len  = strlen(str);
    if (str[0] == '0' && SFtolower(str[1]) == 'x')
        *result = (Number)strtol(str, &tail, 0);
    else if (strcspn(str, ".eE") != len)
        *result = SFstrtod(str, &tail);
    else
    {
        const char* p    = str;
        int         sign = 1;
        if (*p == '-')
        {
            sign = -1;
            p++;
            len--;
        }
        else if (*p == '+')
        {
            p++;
            len--;
        }
        if (*p == '0' && strspn(p, "01234567") == len)
            *result = (Number)(strtol(p, &tail, 8) * sign);
        else
            *result = SFstrtod(p, &tail) * sign;
    }
    return tail != str && *tail == 0;
}

// @0x142990be0
void Value::Sub(Environment* penv, int v2)
{
    Number v1 = ToNumber(penv);
    if (T.Type >= STRING)
        DropRefs();
    T.Type         = NUMBER;
    NV.NumberValue = v1 - (Number)v2;
}

// @0x142990c60
Object* ObjectInterface::ToASObject()
{
    return IsASObject() ? static_cast<Object*>(this) : 0;
}

// @0x142990c90
const Object* ObjectInterface::ToASObject() const
{
    return IsASObject() ? static_cast<const Object*>(this) : 0;
}

// @0x142990d60
AvmCharacter* Value::ToAvmCharacter(const Environment* penv) const
{
    InteractiveObject* pchar = ToCharacter(penv);
    return pchar ? GFx::AS2::ToAvmCharacter(pchar) : 0;
}

// @0x142990f20
bool Value::ToBool(const Environment* penv) const
{
    if (T.Type == STRING)
    {
        if (V.pStringNode->Size == 0)
            return false;
        if (penv->GetVersion() <= 6)
        {
            Number num;
            if (!StringToNumber(&num, V.pStringNode->pData) || NumberUtil::IsNaN(num))
                return false;
            return num != 0;
        }
        return true;
    }
    else if (T.Type == NUMBER)
    {
        if (NumberUtil::IsNaN(NV.NumberValue))
            return false;
        return NV.NumberValue != 0;
    }
    else if (T.Type == INTEGER)
        return NV.Int32Value != 0;
    else if (T.Type == BOOLEAN)
        return V.BooleanValue;
    else if (T.Type == OBJECT)
        return V.pObjectValue != 0;
    else if (T.Type == CHARACTER)
        return ToCharacter(penv) != 0;
    else if (T.Type == FUNCTION)
        return V.FunctionValue.Function != 0;
    else if (T.Type == FUNCTIONNAME)
        return true;
    return false;
}

// @0x1429910b0
InteractiveObject* Value::ToCharacter(const Environment* penv) const
{
    if (T.Type == CHARACTER && penv && V.pCharHandle)
    {
        DisplayObject* pdisp = V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
        if (pdisp)
            return pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
    }
    return 0;
}

// @0x142991110
ASString Value::ToDebugString(Environment* penv) const
{
    return ToStringImpl(penv, -1, 1);
}

// @0x142991210
SInt32 Value::ToInt32(Environment* penv) const
{
    if (T.Type == INTEGER)
        return NV.Int32Value;

    Number v = ToNumber(penv);
    if (NumberUtil::IsNaNOrInfinity(v) || v == 0)
        return 0;
    if (v >= -2147483648.0 && v <= 2147483647.0)
        return (SInt32)v;

    UInt32 uv = (UInt32)fmod(floor(fabs(v)), 4294967296.0);
    if (v < 0)
        return -(SInt32)uv;
    return (SInt32)uv;
}

// MS2-FUNCTIONAL the exe keeps the null test of the delete after the size check
// @0x142992780
bool Object::Unwatch(ASStringContext* psc, const ASString& prop)
{
    if (pWatchpoints && WatchpointHash_GetCaseCheck(pWatchpoints, prop, psc->IsCaseSensitive()))
    {
        WatchpointHash_RemoveCaseCheck(pWatchpoints, prop, psc->IsCaseSensitive());
        ASStringHash_GC<Watchpoint>* pwatchpoints = pWatchpoints;
        if (pwatchpoints->GetSet().GetSize() == 0)
        {
            if (pwatchpoints)
            {
                WatchpointHash_Destruct(pwatchpoints);
                SF_FREE(pwatchpoints);
            }
            pWatchpoints = 0;
        }
        return true;
    }
    return false;
}

// @0x142991c60
FunctionRef Value::ToResolveHandler() const
{
    if (T.Type == RESOLVEHANDLER)
        return V.FunctionValue;
    return FunctionRef();
}

// @0x1429923c0
ASString Value::ToStringVersioned(Environment* penv, unsigned version) const
{
    if (IsUndefined())
    {
        if (version > 0 && version <= 6)
            return penv->GetBuiltin(ASBuiltin_empty_);
        return penv->GetBuiltin(ASBuiltin_undefined);
    }
    return ToStringImpl(penv, -1, 0);
}

// @0x142992440
UInt32 Value::ToUInt32(Environment* penv) const
{
    if (T.Type == INTEGER)
        return NV.UInt32Value;

    Number v = ToNumber(penv);
    if (NumberUtil::IsNaNOrInfinity(v) || v == 0)
        return 0;
    if (v >= 0 && v <= 4294967295.0)
        return (UInt32)v;

    UInt32 uv = (UInt32)fmod(floor(fabs(v)), 4294967296.0);
    if (v < 0)
        uv = 0u - uv;
    return uv;
}


// @0x142981b70
void Value::SetInt_Call(int val)
{
    SetInt(val);
}

// @0x142981bc0
void Environment::SetInvalidTarget(InteractiveObject* ptarget)
{
    Target          = ptarget;
    IsInvalidTarget = true;
    StringContext.UpdateVersion(ptarget->GetVersion());
}

// @0x142981df0
void Environment::SetLocal(const ASString& varname, const Value& val)
{
    if (LocalFrames.GetSize() == 0)
        return;
    if (!LocalFrames[LocalFrames.GetSize() - 1])
        return;

    Value* pvalue = const_cast<Value*>(FindLocal(varname));
    if (!pvalue)
        AddLocal(varname, val);
    else
        *pvalue = val;
}

// @0x142981e70
void FunctionRefBase::SetLocalFrame(LocalFrame* localFrame, bool weakRef)
{
    if (pLocalFrame && !(Flags & FuncRef_Weak))
        pLocalFrame->Release();
    pLocalFrame = localFrame;
    if (weakRef)
        Flags |= FuncRef_Weak;
    else
        Flags &= ~FuncRef_Weak;
    if (pLocalFrame && !(Flags & FuncRef_Weak))
        pLocalFrame->AddRef();
}

// @0x14298b9f0
void Value::SetString_Call(const ASString& str)
{
    SetString(str);
}

// @0x14298ba30
void Environment::SetTarget(InteractiveObject* ptarget)
{
    Target          = ptarget;
    IsInvalidTarget = false;
    StringContext.UpdateVersion(ptarget->GetVersion());
}

// @0x14298c9e0
void Value::SetUInt_Call(unsigned val)
{
    SetUInt(val);
}

// @0x14298cc30
void BooleanObject::SetValue(Environment* penv, const Value& v)
{
    BValue = v.ToBool(penv);
}

// @0x14298cc50
void NumberObject::SetValue(Environment* penv, const Value& v)
{
    NumberValue = v.ToNumber(penv);
}

// @0x14298cc80
void StringObject::SetValue(Environment* penv, const Value& v)
{
    ASString s(v.ToString(penv));
    sValue = s.ToCStr();
}

// @0x142990c40
void FnCall::ThisPtrError_Call(const char* pclassName) const
{
    ThisPtrError(pclassName);
}

// @0x142990d00
AvmCharacter* ObjectInterface::ToAvmCharacter()
{
    return IsASCharacter() ? static_cast<AvmCharacter*>(this) : 0;
}

// @0x142990d30
const AvmCharacter* ObjectInterface::ToAvmCharacter() const
{
    return IsASCharacter() ? static_cast<const AvmCharacter*>(this) : 0;
}

// @0x142990e40
const AvmSprite* ObjectInterface::ToAvmSprite() const
{
    return GetObjectType() == Object_Sprite ? static_cast<const AvmSprite*>(this) : 0;
}

// @0x142990e70
AvmSprite* ObjectInterface::ToAvmSprite()
{
    return GetObjectType() == Object_Sprite ? static_cast<AvmSprite*>(this) : 0;
}

// @0x142991080
const InteractiveObject* ObjectInterface::ToCharacter() const
{
    return IsASCharacter() ? static_cast<const AvmCharacter*>(this)->GetDispObj() : 0;
}

// @0x142991190
FunctionRef Value::ToFunction_Call(const Environment* penv) const
{
    switch (T.Type)
    {
    case FUNCTION:
        return V.FunctionValue;
    case FUNCTIONNAME:
        return ResolveFunctionName(penv);
    }
    return FunctionRef();
}

// @0x142991810
ObjectInterface* Value::ToObjectInterface_Call(const Environment* penv) const
{
    return ToObjectInterface(penv);
}

// @0x142991d00
Sprite* ObjectInterface::ToSprite_Call()
{
    return ToSprite();
}

// @0x142991e10
const char* NumberObject::ToString_Call(int radix)
{
    return ToString(radix);
}


// @0x1429814c0
void ArrayObject::SetElement(int i, const Value& val)
{
    if (i >= 0 && i < GetSize())
    {
        LengthValueOverriden = false;
        if (!Elements[i])
            Elements[i] = SF_HEAP_AUTO_NEW(this) Value();
        *Elements[i] = val;
    }
}

// @0x142981560
void ArrayObject::SetElementSafe(int i, const Value& val)
{
    LengthValueOverriden = false;
    if (i >= GetSize())
        Resize(i + 1);
    if (!Elements[i])
        Elements[i] = SF_HEAP_AUTO_NEW(this) Value();
    *Elements[i] = val;
}

// @0x14298ee10
void ArrayObject::ShallowCopyFrom(const ArrayObject& ao)
{
    ArrayObjectElements_Resize(&Elements, ao.Elements.GetSize());
    for (UPInt i = 0, n = Elements.GetSize(); i < n; i++)
        Elements[i] = ao.Elements[i];
}

// @0x142990960
ASString StringProto::StringSubstring(const ASString& self, int start, int length)
{
    if (length == 0)
        return ASString(self.GetManager()->GetEmptyStringNode());

    if (start < 0)
        start = 0;

    int utf8Len = self.GetLength();
    if (start >= utf8Len)
        return ASString(self.GetManager()->GetEmptyStringNode());

    if (length < 0 || start + length > utf8Len)
        length = utf8Len - start;

    return ASString(self.SubstringNode(start, start + length));
}

// @0x142990b70
void Value::Sub_Call(Environment* penv, const Value& v)
{
    Number lhs = ToNumber(penv);
    Number rhs = v.ToNumber(penv);
    SetNumber(lhs - rhs);
}

// @0x142992e30
void ValidateRect(ASRect* r)
{
    if (NumberUtil::IsNaN(r->x1))
        r->x1 = 0;
    if (NumberUtil::IsNaN(r->x2))
        r->x2 = 0;
    if (NumberUtil::IsNaN(r->y1))
        r->y1 = 0;
    if (NumberUtil::IsNaN(r->y2))
        r->y2 = 0;
}

// @0x142989d20
void PointObject::SetProperties_Call(ASStringContext* psc, const Value params[Point_NumProperties])
{
    SetProperties(psc, params);
}

// MS2-FUNCTIONAL the exe stores the number of the temporary value before its type
// @0x142989db0
void PointObject::SetProperties(Environment* penv, const GASPoint& pt)
{
    SetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_x), Value(pt.x));
    SetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_y), Value(pt.y));
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// @0x14297f2c0
template void GFx::ASStringHash_GC<GFx::AS2::Member>::Set(const GFx::ASString&, const GFx::AS2::Member&);

// @0x142992500
template GFx::AS2::Value* GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Top(unsigned) const;

} // namespace Scaleform
