// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 collector traversals
// (ForEachChild_GC of the collectable classes and of every built-in prototype, for the release, mark-in-cycle and
// scan-in-use passes) and the Stage function stub.
// MS2-UNIT: sfr_as2_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1428fdc00-0x1428fe7e0 .text$mn
// MS2-RANGE: 0x1428fec90-0x1428fed10 .text$mn
// MS2-RANGE: 0x142901ae0-0x142901d20 .text$mn
// MS2-RANGE: 0x142902200-0x1429023e0 .text$mn
// MS2-RANGE: 0x1429027a0-0x142902880 .text$mn
// MS2-RANGE: 0x142903350-0x1429033c0 .text$mn
// MS2-RANGE: 0x14290bed0-0x142914500 .text$mn
// MS2-RANGE: 0x142915690-0x1429159d0 .text$mn
// MS2-RANGE: 0x142915d80-0x142915f40 .text$mn
// MS2-RANGE: 0x1429166b0-0x142916a70 .text$mn
// MS2-RANGE: 0x142916e60-0x142917460 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/gfx_asstringhash.h"

namespace Scaleform { namespace GFx { namespace AS2 {

typedef ASRefCountBaseType::Collector Collector;

// Day of the year at which each month ends, for common and leap years.
static const int DateMonthEnds[2][12] = {
    {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};

void DateProto::DateGetUTCSeconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((pthis->Time % 60000) / 1000));
}

void DateProto::DateGetUTCYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Year - 1900));
}

// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fdd50
void DateProto::DateSetUTCDate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int day = (int)fn.Arg(0).ToNumber(fn.Env);
    for (int m = 0; m < 12; m++)
    {
        if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][m])
        {
            int delta = day - (pthis->JDate - (m ? DateMonthEnds[IsLeapYear(pthis->Year)][m - 1] : 0)) - 1;
            pthis->JDate += delta;
            pthis->Date += SInt64(delta) * SInt64(86400000);
            pthis->UpdateLocal();
            return;
        }
    }
}

// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fdef0
void DateProto::DateSetUTCFullYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int year = (int)fn.Arg(0).ToNumber(fn.Env);
    if (pthis->JDate >= 60)
        pthis->JDate += IsLeapYear(year) - IsLeapYear(pthis->Year);
    pthis->Date = SInt64(pthis->Time) + SInt64(Date_StartOfYear(year) + pthis->JDate) * SInt64(86400000);
    pthis->Year = year;
    pthis->UpdateLocal();
}

void DateProto::DateSetUTCHours(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int hours = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta = (hours - pthis->Time / 3600000) * 3600000;
    pthis->Date += delta;
    pthis->Time += delta;
    pthis->UpdateLocal();
}

void DateProto::DateSetUTCMilliseconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int ms    = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta = ms - pthis->Time % 1000;
    pthis->Date += delta;
    pthis->Time += delta;
    pthis->UpdateLocal();
}

void DateProto::DateSetUTCMinutes(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int minutes = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta   = (minutes - (pthis->Time % 3600000) / 60000) * 60000;
    pthis->Date += delta;
    pthis->Time += delta;
    pthis->UpdateLocal();
}

// Moves the date by whole months: the day within the month is not clamped.
void DateProto::DateSetUTCMonth(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int month = (int)fn.Arg(0).ToNumber(fn.Env);
    for (int m = 0; m < 12; m++)
    {
        if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][m])
        {
            int delta = DateMonthEnds[Date_IsLeapYear(pthis->Year)][month] -
                        DateMonthEnds[Date_IsLeapYear(pthis->Year)][m];
            pthis->JDate += delta;
            pthis->Date += SInt64(delta) * SInt64(86400000);
            pthis->UpdateLocal();
            return;
        }
    }
}

void DateProto::DateSetUTCSeconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int seconds = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta   = (seconds - (pthis->Time % 60000) / 1000) * 1000;
    pthis->Date += delta;
    pthis->Time += delta;
    pthis->UpdateLocal();
}

// Two digit years count from 1900.
// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fe670
void DateProto::DateSetUTCYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int year = (int)fn.Arg(0).ToNumber(fn.Env);
    if (year < 100 && year >= 0)
        year += 1900;
    if (pthis->JDate >= 60)
        pthis->JDate += IsLeapYear(year) - IsLeapYear(pthis->Year);
    pthis->Date = SInt64(pthis->Time) + SInt64(Date_StartOfYear(year) + pthis->JDate) * SInt64(86400000);
    pthis->Year = year;
    pthis->UpdateLocal();
}

void DateProto::DateValueOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Date));
}

// Number.prototype.toString([radix])
void GAS_NumberToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Number);
    NumberObject* pthis = (NumberObject*)(Object*)fn.ThisPtr;
    int radix = 10;
    if (fn.NArgs > 0)
        radix = (int)fn.Arg(0).ToNumber(fn.Env);
    fn.Result->SetString(fn.Env->CreateString(pthis->ToString(radix)));
}

// Number.prototype.valueOf()
void GAS_NumberValueOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Number);
    NumberObject* pthis = (NumberObject*)(Object*)fn.ThisPtr;
    fn.Result->SetNumber(pthis->GetValue().ToNumber(fn.Env));
}

void ObjectProto::HasOwnProperty(const FnCall& fn)
{
    fn.Result->SetBool(fn.ThisPtr->HasMember(fn.Env->GetSC(), fn.Arg(0).ToString(fn.Env), false));
}

// True for an own member that is not hidden from for..in.
void ObjectProto::IsPropertyEnumerable(const FnCall& fn)
{
    if (fn.NArgs >= 1)
    {
        ASString prop(fn.Arg(0).ToString(fn.Env));
        bool     rv = fn.ThisPtr->HasMember(fn.Env->GetSC(), prop, false);
        if (rv)
        {
            Member m;
            fn.ThisPtr->FindMember(fn.Env->GetSC(), prop, &m);
            if (m.GetMemberFlags().GetDontEnum())
                rv = false;
        }
        fn.Result->SetBool(rv);
    }
    else
        fn.Result->SetBool(false);
}

void ObjectProto::Unwatch_(const FnCall& fn)
{
    if (fn.NArgs >= 1)
        fn.Result->SetBool(fn.ThisPtr->Unwatch(fn.Env->GetSC(), fn.Arg(0).ToString(fn.Env)));
    else
        fn.Result->SetBool(false);
}

void FunctionProto::ToString(const FnCall& fn)
{
    fn.Result->SetString(fn.Env->GetBuiltin(ASBuiltin_typeFunction_));
}

// The Stage methods that do nothing in GFx.
void GFx_StageFuncStub(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// Instantiates ForEachChild_GC of a class for the three collector passes.
#define MS2_AS2_GC_FOR_EACH_CHILD(Class)                                                                        \
    template void Class::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector * prcc) const;           \
    template void Class::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector * prcc) const;       \
    template void Class::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector * prcc) const;

template<class Functor>
void FunctionRefBase::ForEachChild_GC(Collector* prcc) const
{
    if (Function)
        Functor::Call(prcc, Function);
    if (pLocalFrame)
        Functor::Call(prcc, pLocalFrame);
}
MS2_AS2_GC_FOR_EACH_CHILD(FunctionRefBase)

template<class Functor>
void Value::ForEachChild_GC(Collector* prcc) const
{
    if (IsFunction())
        V.FunctionValue.template ForEachChild_GC<Functor>(prcc);
    else if (IsObject() && V.pObjectValue)
        Functor::Call(prcc, V.pObjectValue);
    else if (IsProperty())
        Functor::Call(prcc, V.pProperty);
}
MS2_AS2_GC_FOR_EACH_CHILD(Value)

template<class Functor>
void Object::ForEachChild_GC(Collector* prcc) const
{
    ASStringHash_GC<Member>::ConstIterator it = Members.Begin();
    while (it != Members.End())
    {
        const Value& value = it->Second.GetMemberValue();
        value.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
    ResolveHandler.template ForEachChild_GC<Functor>(prcc);
    if (pWatchpoints)
    {
        ASStringHash_GC<Watchpoint>::ConstIterator wit = pWatchpoints->Begin();
        while (wit != pWatchpoints->End())
        {
            const Watchpoint& wp = wit->Second;
            wp.template ForEachChild_GC<Functor>(prcc);
            ++wit;
        }
    }
    if (pProto)
        Functor::Call(prcc, pProto);
}
MS2_AS2_GC_FOR_EACH_CHILD(Object)

template<class Functor>
void LocalFrame::ForEachChild_GC(Collector* prcc) const
{
    ASStringHash_GC<Value>::ConstIterator it = Variables.Begin();
    while (it != Variables.End())
    {
        const Value& value = it->Second;
        value.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
    if (PrevFrame)
        Functor::Call(prcc, PrevFrame);
    Callee.template ForEachChild_GC<Functor>(prcc);
    Caller.template ForEachChild_GC<Functor>(prcc);
}
MS2_AS2_GC_FOR_EACH_CHILD(LocalFrame)

template<class Functor>
void ArrayObject::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    UPInt i, n;
    for (i = 0, n = Elements.GetSize(); i < n; i++)
    {
        Value* pval = Elements[i];
        if (pval)
            pval->template ForEachChild_GC<Functor>(prcc);
    }
}
template void ArrayObject::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector* prcc) const;
template void ArrayObject::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector* prcc) const;

// The mark pass copy, which the exe does not inline into the prototype (the other two it does).
template<>
__declspec(noinline) void ArrayObject::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector* prcc) const
{
    Object::template ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(prcc);
    UPInt i, n;
    for (i = 0, n = Elements.GetSize(); i < n; i++)
    {
        Value* pval = Elements[i];
        if (pval)
            pval->template ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(prcc);
    }
}

MS2_AS2_GC_FOR_EACH_CHILD(SuperObject)

// Never inlined into the prototype in the exe.
template<class Functor>
__declspec(noinline) void TransformObject::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    if (Matrix)
        Functor::Call(prcc, Matrix);
    if (pColorTransform)
        Functor::Call(prcc, pColorTransform);
    if (PixelBounds)
        Functor::Call(prcc, PixelBounds);
}
MS2_AS2_GC_FOR_EACH_CHILD(TransformObject)

template<class Functor>
void MouseCtorFunction::ForEachChild_GC(Collector* prcc) const
{
    SetCursorTypeFunc.template ForEachChild_GC<Functor>(prcc);
    if (pListenersArray)
        Functor::Call(prcc, pListenersArray);
    CFunctionObject::template ForEachChild_GC<Functor>(prcc);
}
MS2_AS2_GC_FOR_EACH_CHILD(MouseCtorFunction)

template<class Functor>
void SharedObjectCtorFunction::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    ASStringHash_GC<SharedObjectPtr>::ConstIterator it = SharedObjects.Begin();
    while (it != SharedObjects.End())
    {
        const SharedObjectPtr& pobj = it->Second;
        pobj.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
}
MS2_AS2_GC_FOR_EACH_CHILD(SharedObjectCtorFunction)

// The built-in prototypes.
#define MS2_AS2_GC_PROTOTYPE(Class) MS2_AS2_GC_FOR_EACH_CHILD(Prototype<Class>)

MS2_AS2_GC_PROTOTYPE(AmpMarker)
MS2_AS2_GC_PROTOTYPE(ArrayObject)
MS2_AS2_GC_PROTOTYPE(Selection)
MS2_AS2_GC_PROTOTYPE(ColorMatrixFilterObject)
MS2_AS2_GC_PROTOTYPE(SharedObject)
MS2_AS2_GC_PROTOTYPE(BevelFilterObject)
MS2_AS2_GC_PROTOTYPE(BlurFilterObject)
MS2_AS2_GC_PROTOTYPE(GlowFilterObject)
MS2_AS2_GC_PROTOTYPE(DropShadowFilterObject)
MS2_AS2_GC_PROTOTYPE(BitmapFilterObject)
MS2_AS2_GC_PROTOTYPE(BooleanObject)
MS2_AS2_GC_PROTOTYPE(TextSnapshotObject)
MS2_AS2_GC_PROTOTYPE(DateObject)
MS2_AS2_GC_PROTOTYPE(StringObject)
MS2_AS2_GC_PROTOTYPE(ExternalInterface)
MS2_AS2_GC_PROTOTYPE(ColorObject)
MS2_AS2_GC_PROTOTYPE(MouseObject)
MS2_AS2_GC_PROTOTYPE(NumberObject)
MS2_AS2_GC_PROTOTYPE(KeyObject)
MS2_AS2_GC_PROTOTYPE(AsBroadcaster)
MS2_AS2_GC_PROTOTYPE(Math)
MS2_AS2_GC_PROTOTYPE(ButtonObject)
MS2_AS2_GC_PROTOTYPE(BitmapData)
MS2_AS2_GC_PROTOTYPE(TextFieldObject)
MS2_AS2_GC_PROTOTYPE(StageObject)
MS2_AS2_GC_PROTOTYPE(PointObject)
MS2_AS2_GC_PROTOTYPE(RectangleObject)
MS2_AS2_GC_PROTOTYPE(MatrixObject)
MS2_AS2_GC_PROTOTYPE(LoadVarsObject)
MS2_AS2_GC_PROTOTYPE(Object)
MS2_AS2_GC_PROTOTYPE(MovieClipLoader)
MS2_AS2_GC_PROTOTYPE(StyleSheetObject)
MS2_AS2_GC_PROTOTYPE(MovieClipObject)
MS2_AS2_GC_PROTOTYPE(TextFormatObject)
MS2_AS2_GC_PROTOTYPE(ColorTransformObject)
MS2_AS2_GC_PROTOTYPE(TransformObject)

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// The string-keyed hashes of AS2: insertion of a node or a node reference, exact and case-insensitive lookup. The
// other insertions are not instantiated here yet: the exe calls their entry copy and node assignment out of line.
#define MS2_AS2_STRING_HASH_ADD(U, K)                                                                            \
    template void GFx::ASStringHash_GC<U>::SetType::add<K>(void*, const K&, UPInt);
#define MS2_AS2_STRING_HASH_FIND(U)                                                                              \
    template SPInt GFx::ASStringHash_GC<U>::SetType::findIndexAlt<GFx::ASString>(const GFx::ASString&) const;   \
    template SPInt GFx::ASStringHash_GC<U>::SetType::findIndexAlt<GFx::ASStringNoCaseKey>(                      \
        const GFx::ASStringNoCaseKey&) const;

MS2_AS2_STRING_HASH_ADD(GFx::AS2::SharedObjectPtr, GFx::ASStringHash_GC<GFx::AS2::SharedObjectPtr>::NodeType)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::Value, GFx::ASStringHash_GC<GFx::AS2::Value>::NodeType)
MS2_AS2_STRING_HASH_ADD(char, GFx::ASStringHash_GC<char>::NodeType::NodeRef)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::SharedObjectPtr, GFx::ASStringHash_GC<GFx::AS2::SharedObjectPtr>::NodeType::NodeRef)
MS2_AS2_STRING_HASH_ADD(GFx::AS2::Value, GFx::ASStringHash_GC<GFx::AS2::Value>::NodeType::NodeRef)
MS2_AS2_STRING_HASH_FIND(GFx::AS2::Object::Watchpoint)
MS2_AS2_STRING_HASH_FIND(GFx::AS2::FunctionRef)
MS2_AS2_STRING_HASH_FIND(GFx::AS2::Member)
MS2_AS2_STRING_HASH_FIND(GFx::AS2::Value)

} // namespace Scaleform

// MS2-PIN: ??_7SharedObjectPtr@AS2@GFx@Scaleform@@6B@ 0x14321dd78
