// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 builtin class natives
// (Boolean prototype methods, the Math object functions, Date prototype getters/setters).
// MS2-UNIT: sfr_as2_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142444c40-0x142445480 .text$mn
// MS2-RANGE: 0x1423df8a0-0x1423dfef0 .text$mn
// MS2-RANGE: 0x1423e0090-0x1423e0260 .text$mn
// MS2-RANGE: 0x1424447c0-0x142444a00 .text$mn
// MS2-RANGE: 0x142444a00-0x142444bc0 .text$mn
// MS2-RANGE: 0x142444be0-0x142444c35 .text$mn
// MS2-RANGE: 0x142446cb0-0x142446d90 .text$mn
// MS2-RANGE: 0x1424eb700-0x1424eb7b0 .text$mn
// MS2-RANGE: 0x1424ed770-0x1424ed7b0 .text$mn
// MS2-RANGE: 0x142447090-0x142447310 .text$mn
// MS2-RANGE: 0x14252b580-0x14252b5a0 .text$mn
// MS2-RANGE: 0x1424ad030-0x1424ad0b0 .text$mn
// MS2-RANGE: 0x1424ad0b0-0x1424ad4d0 .text$mn
// MS2-RANGE: 0x1424c9270-0x1424c9630 .text$mn
// MS2-RANGE: 0x1424c91f0-0x1424c9270 .text$mn
// MS2-RANGE: 0x1424c9630-0x1424c96a0 .text$mn
// MS2-RANGE: 0x1423dbde0-0x1423dbe60 .text$mn
// MS2-RANGE: 0x1423dbea0-0x1423dc0b0 .text$mn
// MS2-RANGE: 0x1428eb050-0x1428ebd60 .text$mn
// MS2-RANGE: 0x1428ec0b0-0x1428ec780 .text$mn
// MS2-RANGE: 0x14292bdc0-0x14292bdf0 .text$mn
// MS2-RANGE: 0x142993ff0-0x142994160 .text$mn
// MS2-RANGE: 0x1428ec780-0x1428ed580 .text$mn
// MS2-RANGE: 0x1428ed580-0x1428ef8d0 .text$mn
// MS2-RANGE: 0x1428ef8d0-0x1428f1e30 .text$mn
// MS2-RANGE: 0x1428f1e30-0x1428f1e70 .text$mn
// MS2-RANGE: 0x1428f2040-0x1428f37a0 .text$mn
// MS2-RANGE: 0x1428f37a0-0x1428f40d0 .text$mn
// MS2-RANGE: 0x1428f40d0-0x1428f4610 .text$mn
// MS2-RANGE: 0x1428f4610-0x1428f4cd0 .text$mn
// MS2-RANGE: 0x1428f4cd0-0x1428f4e60 .text$mn
// MS2-RANGE: 0x1428f4e60-0x1428f5740 .text$mn
// MS2-RANGE: 0x1428f65c0-0x1428f6de0 .text$mn
// MS2-RANGE: 0x1428f7290-0x1428f73b0 .text$mn
// MS2-RANGE: 0x1428f7c10-0x1428f7d30 .text$mn
// MS2-RANGE: 0x1428f82d0-0x1428f83d0 .text$mn
// MS2-RANGE: 0x1428faed0-0x1428fafd0 .text$mn
// MS2-RANGE: 0x1428fbd10-0x1428fbdc0 .text$mn
// MS2-RANGE: 0x1428fbdc0-0x1428fbea0 .text$mn
// MS2-RANGE: 0x1428fbea0-0x1428fc080 .text$mn
// MS2-RANGE: 0x1428fc080-0x1428fc160 .text$mn
// MS2-RANGE: 0x1428f1e70-0x1428f2040 .text$mn
// MS2-RANGE: 0x1428f86b0-0x1428f8720 .text$mn
// MS2-RANGE: 0x1428f9ba0-0x1428f9cf0 .text$mn
// MS2-RANGE: 0x1428f5740-0x1428f65c0 .text$mn
// MS2-RANGE: 0x1428f6de0-0x1428f7290 .text$mn
// MS2-RANGE: 0x1428f8540-0x1428f86b0 .text$mn
// MS2-RANGE: 0x1428fafd0-0x1428fb110 .text$mn
// MS2-RANGE: 0x1428f74a0-0x1428f7580 .text$mn
// MS2-RANGE: 0x1428f7740-0x1428f7c10 .text$mn
// MS2-RANGE: 0x1428f9f50-0x1428fa620 .text$mn
// MS2-RANGE: 0x1428fa7a0-0x1428faed0 .text$mn
// MS2-RANGE: 0x1428f7d30-0x1428f7ed0 .text$mn
// MS2-RANGE: 0x1428f7ed0-0x1428f8540 .text$mn
// MS2-RANGE: 0x1428f73b0-0x1428f74a0 .text$mn
// MS2-RANGE: 0x1428f7580-0x1428f7740 .text$mn
// MS2-RANGE: 0x1428fb110-0x1428fbb70 .text$mn
// MS2-RANGE: 0x1428fbb80-0x1428fbc40 .text$mn
// MS2-RANGE: 0x1428fbb70-0x1428fbb80 .text$mn
// MS2-RANGE: 0x1428fbc40-0x1428fbc50 .text$mn
// MS2-RANGE: 0x1428fbc50-0x1428fbd10 .text$mn
// MS2-RANGE: 0x1428fc160-0x1428fdc00 .text$mn

#include <math.h>

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/as3/as3_support.h"
#include "../include/gfx/as3/obj/as3_obj_natives.h"
#include "../include/gfx/as3/as3_avm.h"
#include "../include/gfx/gfx_imemanager.h"
#include "../include/render/text_highlight.h"
#include "../include/gfx/gfx_imecandidateliststyle.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Boolean.prototype.toString(): "true" / "false" of the wrapped value.
// @0x1428f4cd0
void GAS_BooleanToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Boolean);
    BooleanObject* pthis = (BooleanObject*)(Object*)fn.ThisPtr;
    fn.Result->SetString(pthis->GetValue().ToString(fn.Env));
}

// Boolean.prototype.valueOf()
// @0x1428f4da0
void GAS_BooleanValueOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Boolean);
    BooleanObject* pthis = (BooleanObject*)(Object*)fn.ThisPtr;
    fn.Result->SetBool(pthis->GetValue().ToBool(fn.Env));
}

// @0x1428fb110
void MathCtorFunction::Abs(const FnCall& fn)
{
    fn.Result->SetNumber(fabs(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb1a0
void MathCtorFunction::Acos(const FnCall& fn)
{
    fn.Result->SetNumber(acos(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb220
void MathCtorFunction::Asin(const FnCall& fn)
{
    fn.Result->SetNumber(asin(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb2a0
void MathCtorFunction::Atan(const FnCall& fn)
{
    fn.Result->SetNumber(atan(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb320
void MathCtorFunction::Ceil(const FnCall& fn)
{
    fn.Result->SetNumber(ceil(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb3a0
void MathCtorFunction::Cos(const FnCall& fn)
{
    fn.Result->SetNumber(cos(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb420
void MathCtorFunction::Exp(const FnCall& fn)
{
    fn.Result->SetNumber(exp(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb4a0
void MathCtorFunction::Floor(const FnCall& fn)
{
    fn.Result->SetNumber(floor(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb520
void MathCtorFunction::Log(const FnCall& fn)
{
    fn.Result->SetNumber(log(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb5a0
void MathCtorFunction::Sin(const FnCall& fn)
{
    fn.Result->SetNumber(sin(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb620
void MathCtorFunction::Sqrt(const FnCall& fn)
{
    fn.Result->SetNumber(sqrt(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb6a0
void MathCtorFunction::Tan(const FnCall& fn)
{
    fn.Result->SetNumber(tan(fn.Arg(0).ToNumber(fn.Env)));
}

// @0x1428fb720
void MathCtorFunction::Atan2(const FnCall& fn)
{
    Number y = fn.Arg(0).ToNumber(fn.Env);
    Number x = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(atan2(y, x));
}

// @0x1428fb800
void MathCtorFunction::Max(const FnCall& fn)
{
    Number a = fn.Arg(0).ToNumber(fn.Env);
    Number b = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(a > b ? a : b);
}

// @0x1428fb8d0
void MathCtorFunction::Min(const FnCall& fn)
{
    Number a = fn.Arg(0).ToNumber(fn.Env);
    Number b = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(a < b ? a : b);
}

// @0x1428fb9a0
void MathCtorFunction::Pow(const FnCall& fn)
{
    Number base     = fn.Arg(0).ToNumber(fn.Env);
    Number exponent = fn.Arg(1).ToNumber(fn.Env);
    fn.Result->SetNumber(pow(base, exponent));
}

// Uniform in [0, 1].
// @0x1428fba80
void MathCtorFunction::Random(const FnCall& fn)
{
    MovieImpl* proot = ((DisplayObjectBase*)fn.Env->Target)->GetMovieImpl();
    fn.Result->SetNumber(Number(Math::GetNextRandom(proot)) / Number(0xFFFFFFFFu));
}

// @0x1428fbae0
void MathCtorFunction::Round(const FnCall& fn)
{
    fn.Result->SetNumber(floor(fn.Arg(0).ToNumber(fn.Env) + 0.5));
}

// ---- Array ----

// A new array holding this array's elements followed by the arguments (arrays are flattened one level).
// @0x1428f4e60
void ArrayObject::ArrayConcat(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    pthis->LengthValueOverriden = false;
    Ptr<ArrayObject> ao = *static_cast<ArrayObject*>(fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_Array)));
    if (ao)
    {
        ao->Concat(fn.Env, pthis);
        for (int i = 0; i < fn.NArgs; i++)
            ao->Concat(fn.Env, fn.Arg(i));
    }
    fn.Result->SetAsObject(ao.GetPtr());
}

// The elements as strings joined by the argument (default ",").
// @0x1428f4fd0
void ArrayObject::ArrayJoin(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    pthis->LengthValueOverriden = false;
    StringBuffer sbuffer(fn.Env->GetHeap());
    if (fn.NArgs == 0)
    {
        pthis->JoinToString(fn.Env, &sbuffer, ",");
    }
    else
    {
        ASString sa0(fn.Arg(0).ToString(fn.Env));
        pthis->JoinToString(fn.Env, &sbuffer, sa0.ToCStr());
    }
    fn.Result->SetString(fn.Env->CreateString(sbuffer.ToCStr(), sbuffer.GetSize()));
}

// Removes and returns the last element.
// @0x1428f5170
void ArrayObject::ArrayPop(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    pthis->LengthValueOverriden = false;
    if (pthis->GetSize())
    {
        Value* pval = pthis->GetElementPtr(pthis->GetSize() - 1);
        if (pval)
            *fn.Result = *pval;
        else
            fn.Result->SetUndefined();
        pthis->PopBack();
    }
    else
    {
        fn.Result->SetUndefined();
    }
}

// Appends the arguments; returns the new length.
// @0x1428f5240
void ArrayObject::ArrayPush(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    pthis->LengthValueOverriden = false;
    for (int i = 0; i < fn.NArgs; i++)
        pthis->PushBack(fn.Arg(i));
    fn.Result->SetInt(pthis->GetSize());
}

// Reverses in place and returns this (Flash 8 behaviour; documented as Void).
// @0x1428f5340
void ArrayObject::ArrayReverse(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    pthis->LengthValueOverriden = false;
    pthis->Reverse();
    fn.Result->SetAsObject(pthis);
}

// Removes and returns the first element.
// @0x1428f53e0
void ArrayObject::ArrayShift(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    if (pthis->GetSize() == 0)
    {
        fn.Result->SetUndefined();
        return;
    }
    pthis->LengthValueOverriden = false;
    Value* pval = pthis->GetElementPtr(0);
    if (pval)
        *fn.Result = *pval;
    else
        fn.Result->SetUndefined();
    pthis->PopFront();
}

// A new array of the elements [start, end); negative indexes count from the end.
// @0x1428f5530
void ArrayObject::ArraySlice(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    pthis->LengthValueOverriden = false;
    int start = 0;
    int end   = pthis->GetSize();
    if (fn.NArgs >= 1)
    {
        start = fn.Arg(0).ToInt32(fn.Env);
        if (start < 0)
            start += pthis->GetSize();
        if (start < 0)
            start = 0;
        if (start > pthis->GetSize())
            start = pthis->GetSize();
    }
    if (fn.NArgs >= 2)
    {
        end = fn.Arg(1).ToInt32(fn.Env);
        if (end < 0)
            end += pthis->GetSize();
        if (end < 0)
            end = 0;
        if (end > pthis->GetSize())
            end = pthis->GetSize();
    }

    Ptr<ArrayObject> ao = *static_cast<ArrayObject*>(fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_Array)));
    if (ao)
    {
        for (int i = start; i < end; i++)
        {
            if (pthis->GetElementPtr(i) != 0)
                ao->PushBack(*pthis->GetElementPtr(i));
            else
                ao->PushBack();
        }
    }
    fn.Result->SetAsObject(ao.GetPtr());
}

// splice(start, [deleteCount], [items...]): returns the removed elements as a new array.
// @0x1428f65c0
// MS2-FUNCTIONAL same code with rsi/rdi swapped and the r14/r15 saves placed before the loop test (register allocation)
void ArrayObject::ArraySplice(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    if (fn.NArgs == 0)
    {
        fn.Result->SetUndefined();
        return;
    }

    pthis->LengthValueOverriden = false;
    int start = fn.Arg(0).ToInt32(fn.Env);
    if (start < 0)
        start += pthis->GetSize();
    if (start < 0)
        start = 0;
    if (start > pthis->GetSize())
        start = pthis->GetSize();

    int count = pthis->GetSize() - start;
    if (fn.NArgs >= 2)
    {
        count = fn.Arg(1).ToInt32(fn.Env);
        if (count < 0)
            count = 0;
        if (start + count >= pthis->GetSize())
            count = pthis->GetSize() - start;
    }

    int              i;
    Ptr<ArrayObject> ao = *static_cast<ArrayObject*>(fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_Array)));
    if (ao)
    {
        for (i = 0; i < count; i++)
        {
            if (pthis->GetElementPtr(start + i) != 0)
                ao->PushBack(*pthis->GetElementPtr(start + i));
            else
                ao->PushBack();
        }
        fn.Result->SetAsObject(ao.GetPtr());

        if (count)
            pthis->RemoveElements(start, count);

        if (fn.NArgs >= 3)
        {
            pthis->InsertEmpty(start, fn.NArgs - 2);
            for (i = 2; i < fn.NArgs; i++)
                pthis->SetElement(start + i - 2, fn.Arg(i));
        }
    }
}

// valueOf is the same as toString.
// @0x1428f6880
void ArrayObject::ArrayValueOf(const FnCall& fn)
{
    ArrayToString(fn);
}

// Inserts the arguments at the front; returns the new length.
// @0x1428f6a10
void ArrayObject::ArrayUnshift(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    pthis->LengthValueOverriden = false;
    if (fn.NArgs > 0)
    {
        pthis->InsertEmpty(0, fn.NArgs);
        for (int i = 0; i < fn.NArgs; i++)
            pthis->SetElement(i, fn.Arg(i));
    }
    fn.Result->SetInt(pthis->GetSize());
}

// The elements joined by ","; an array nested 256 deep in itself gives "".
// @0x1428f6b30
void ArrayObject::ArrayToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;

    RecursionGuard rg(pthis);
    if (pthis->RecursionLimitReached())
    {
        fn.Result->SetString(fn.Env->GetBuiltin(ASBuiltin_empty_));
    }
    else
    {
        StringBuffer sbuffer(fn.Env->GetHeap());
        pthis->JoinToString(fn.Env, &sbuffer, ",");
        fn.Result->SetString(fn.Env->CreateString(sbuffer.ToCStr(), sbuffer.GetSize()));
    }
}

// ---- Filters ----

// A new DropShadowFilter holding a copy of this one's filter.
// @0x1428f6cc0
void DropShadowFilterProto::Clone(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, DropShadowFilter);
    BitmapFilterObject* pthis = (BitmapFilterObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<Object> pfilter =
        *fn.Env->OperatorNew(fn.Env->GetSC()->pContext->FlashFiltersPackage, fn.Env->GetBuiltin(ASBuiltin_DropShadowFilter), 0);
    BitmapFilterObject* pnew = static_cast<BitmapFilterObject*>(pfilter.GetPtr());
    pnew->SetFilter(pthis->GetFilter()->Clone(Memory::GetHeapByAddress(pthis)));
    fn.Result->SetAsObject(pfilter);
}

// A new GlowFilter holding a copy of this one's filter.
// @0x1428f7290
void GlowFilterProto::Clone(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, GlowFilter);
    BitmapFilterObject* pthis = (BitmapFilterObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<Object> pfilter =
        *fn.Env->OperatorNew(fn.Env->GetSC()->pContext->FlashFiltersPackage, fn.Env->GetBuiltin(ASBuiltin_GlowFilter), 0);
    BitmapFilterObject* pnew = static_cast<BitmapFilterObject*>(pfilter.GetPtr());
    pnew->SetFilter(pthis->GetFilter()->Clone(Memory::GetHeapByAddress(pthis)));
    fn.Result->SetAsObject(pfilter);
}

// A new BlurFilter holding a copy of this one's filter.
// @0x1428f7c10
void BlurFilterProto::Clone(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, BlurFilter);
    BitmapFilterObject* pthis = (BitmapFilterObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<Object> pfilter =
        *fn.Env->OperatorNew(fn.Env->GetSC()->pContext->FlashFiltersPackage, fn.Env->GetBuiltin(ASBuiltin_BlurFilter), 0);
    BitmapFilterObject* pnew = static_cast<BitmapFilterObject*>(pfilter.GetPtr());
    pnew->SetFilter(pthis->GetFilter()->Clone(Memory::GetHeapByAddress(pthis)));
    fn.Result->SetAsObject(pfilter);
}

// A new BevelFilter sharing this one's render filter.
// @0x1428f82d0
void BevelFilterProto::Clone(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, BevelFilter);
    BitmapFilterObject* pthis = (BitmapFilterObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<Object> pfilter =
        *fn.Env->OperatorNew(fn.Env->GetSC()->pContext->FlashFiltersPackage, fn.Env->GetBuiltin(ASBuiltin_BevelFilter), 0);
    BitmapFilterObject* pnew = static_cast<BitmapFilterObject*>(pfilter.GetPtr());
    pnew->SetFilter(pthis->GetFilter());
    fn.Result->SetAsObject(pfilter);
}

// A new ColorMatrixFilter sharing this one's render filter.
// @0x1428faed0
void ColorMatrixFilterProto::Clone(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, ColorMatrixFilter);
    BitmapFilterObject* pthis = (BitmapFilterObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<Object> pfilter = *fn.Env->OperatorNew(fn.Env->GetSC()->pContext->FlashFiltersPackage,
                                               fn.Env->GetBuiltin(ASBuiltin_ColorMatrixFilter), 0);
    BitmapFilterObject* pnew = static_cast<BitmapFilterObject*>(pfilter.GetPtr());
    pnew->SetFilter(pthis->GetFilter());
    fn.Result->SetAsObject(pfilter);
}

// ---- AsBroadcaster ----

// @0x1428fbd10
void AsBroadcasterProto::AddListener(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    ObjectInterface* plistener = fn.Arg(0).ToObjectInterface(fn.Env);
    AsBroadcaster::AddListener(fn.Env, fn.ThisPtr, plistener);
    fn.Result->SetBool(true);
}

// @0x1428fbdc0
// MS2-FUNCTIONAL the inlined broadcast computes the argument count and stack index before the callback setup (scheduling)
void AsBroadcasterProto::BroadcastMessage(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    ASString eventName = fn.Arg(0).ToString(fn.Env);
    // AsBroadcaster::BroadcastMessage, inlined.
    if (fn.ThisPtr)
    {
        class LocalInvokeCallback : public AsBroadcaster::InvokeCallback
        {
        public:
            int NArgs;
            int FirstArgBottomIndex;

            LocalInvokeCallback(int nargs, int firstArg) : NArgs(nargs), FirstArgBottomIndex(firstArg) {}

            virtual void Invoke(Environment* penv, ObjectInterface* pthis, const FunctionRef& method)
            {
                Value result;
                method.Invoke(FnCall(&result, pthis, penv, NArgs, FirstArgBottomIndex));
            }
        } callback(fn.NArgs - 1, fn.Env->GetTopIndex() - 1);
        AsBroadcaster::BroadcastMessageWithCallback(fn.Env, fn.ThisPtr, eventName, &callback);
    }
    fn.Result->SetUndefined();
}

// @0x1428fbea0
// MS2-FUNCTIONAL same inlined listener search, different register allocation and result flag placement
void AsBroadcasterProto::RemoveListener(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    ObjectInterface* plistener = fn.Arg(0).ToObjectInterface(fn.Env);
    Environment*     penv = fn.Env;
    bool             removed = false;
    // AsBroadcaster::RemoveListener, inlined.
    if (fn.ThisPtr && plistener)
    {
        Value listeners;
        if (fn.ThisPtr->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin__listeners), &listeners))
        {
            Object* pobj = listeners.ToObject(penv);
            if (pobj && pobj->GetObjectType() == Object_Array)
            {
                Ptr<ArrayObject> parray = static_cast<ArrayObject*>(pobj);
                for (int i = (int)parray->GetSize() - 1; i >= 0; --i)
                {
                    Value* pelem = parray->GetElementPtr(i);
                    if (pelem && pelem->ToObjectInterface_Call(penv) == plistener)
                    {
                        parray->RemoveElements(i, 1);
                        removed = true;
                        break;
                    }
                }
            }
        }
    }
    fn.Result->SetBool(removed);
}

// @0x1428fc080
void AsBroadcasterCtorFunction::Initialize(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    ObjectInterface* pobj = fn.Arg(0).ToObjectInterface(fn.Env);
    fn.Result->SetUndefined();
    ASStringContext* psc = fn.Env->GetSC();
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    AsBroadcaster::InitializeInstance(psc, pobj);
}

// cl's /GS heuristic guards the address-taken Matrix2F locals and temporaries of these natives; the exe frames carry
// no cookie (only the ones passing the matrix to an out-of-line member do).
#define MS2_AS2_NOGS __declspec(safebuffers)

// ---- Color ----

// Color.getRGB(): the add row of the target's transform as 0xRRGGBB.
// @0x1428ed450
// MS2-FUNCTIONAL same operations; the exe's register allocation differs (negated add-row bytes via imul on two lanes)
void ColorProto::GetRGB(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Color);
    ColorObject* pthis = (ColorObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<InteractiveObject> pchar = pthis->pCharacter;
    if (!pchar)
        return;
    Render::Cxform cx = pchar->GetCxform();
    SInt32 r = (SInt32)(SInt64)cx.M[1][0];
    SInt32 g = (SInt32)(SInt64)cx.M[1][1];
    SInt32 b = (SInt32)(SInt64)cx.M[1][2];
    fn.Result->SetInt(((-(r << 16)) & 0xff0000) | ((-(g << 8)) & 0xff00) | ((-b) & 0xff));
}

// Color.setRGB(rgb): zeroes the multipliers and sets the add row.
// @0x1428ed2a0
void ColorProto::SetRGB(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Color);
    ColorObject* pthis = (ColorObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<InteractiveObject> pchar = pthis->pCharacter;
    if (fn.NArgs < 1 || !pchar)
        return;
    UInt32 rgb = (UInt32)(SInt64)fn.Arg(0).ToNumber(fn.Env);
    Render::Cxform cx = pchar->GetCxform();
    cx.M[0][0] = cx.M[0][1] = cx.M[0][2] = 0;
    cx.M[1][0] = (float)((rgb >> 16) & 0xff);
    cx.M[1][1] = (float)((rgb >> 8) & 0xff);
    cx.M[1][2] = (float)(rgb & 0xff);
    cx.Normalize();
    pchar->SetCxform(cx);
    pchar->SetAcceptAnimMoves(false);
}

// Color.getTransform(): an object with the ra/ga/ba/aa multipliers in percent and rb/gb/bb/ab adds in 0..255.
// @0x1428eccf0
// MS2-FUNCTIONAL the exe keeps the null test of the new object's release at the end (cl drops it after the member calls here)
MS2_AS2_NOGS void ColorProto::GetTransform(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Color);
    ColorObject* pthis = (ColorObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<InteractiveObject> pchar = pthis->pCharacter;
    if (!pchar)
        return;
    Render::Cxform cx = pchar->GetCxform();
    Ptr<Object>    pobj = Pickable<Object>(SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env));
    ASStringContext* psc = fn.Env->GetSC();
#define MS2_AS2_PUT(name, expr) pobj->SetMemberRaw(psc, psc->CreateConstString(name), Value(Number(expr)), PropFlags())
    MS2_AS2_PUT("ba", cx.M[0][2] * 100.0f);
    MS2_AS2_PUT("ga", cx.M[0][1] * 100.0f);
    MS2_AS2_PUT("ra", cx.M[0][0] * 100.0f);
    MS2_AS2_PUT("aa", cx.M[0][3] * 100.0f);
    MS2_AS2_PUT("bb", cx.M[1][2] * 255.0f);
    MS2_AS2_PUT("gb", cx.M[1][1] * 255.0f);
    MS2_AS2_PUT("rb", cx.M[1][0] * 255.0f);
    MS2_AS2_PUT("ab", cx.M[1][3] * 255.0f);
#undef MS2_AS2_PUT
    fn.Result->SetAsObject(pobj);
}

// Color.setTransform(obj): reads the same members back; absent ones keep the current value.
// @0x1428ec780
void ColorProto::SetTransform(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Color);
    ColorObject* pthis = (ColorObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<InteractiveObject> pchar = pthis->pCharacter;
    if (fn.NArgs < 1 || !pchar)
        return;
    ObjectInterface* pobj = fn.Arg(0).ToObjectInterface(fn.Env);
    if (!pobj)
        return;

    Render::Cxform   cx = pchar->GetCxform();
    Value            val;
    ASStringContext* psc = fn.Env->GetSC();
#define MS2_AS2_GET(name, dst, div)                                                    if (pobj->GetMemberRaw(psc, psc->CreateConstString(name), &val))                    dst = (float)val.ToNumber(fn.Env) / div
    MS2_AS2_GET("ba", cx.M[0][2], 100.0f);
    MS2_AS2_GET("ga", cx.M[0][1], 100.0f);
    MS2_AS2_GET("ra", cx.M[0][0], 100.0f);
    MS2_AS2_GET("aa", cx.M[0][3], 100.0f);
    MS2_AS2_GET("bb", cx.M[1][2], 255.0f);
    MS2_AS2_GET("gb", cx.M[1][1], 255.0f);
    MS2_AS2_GET("rb", cx.M[1][0], 255.0f);
    MS2_AS2_GET("ab", cx.M[1][3], 255.0f);
#undef MS2_AS2_GET
    pchar->SetCxform(cx);
    pchar->SetAcceptAnimMoves(false);
}

// ---- LoadVars ----

// @0x1428ec0b0
// MS2-FUNCTIONAL the exe tests the this-class check after loading the environment and tail-calls the error path (branch layout)
void LoadVarsProto::AddRequestHeader(const FnCall& fn)
{
    if (!fn.CheckThisPtr(ObjectInterface::Object_LoadVars))
        fn.ThisPtrError("LoadVars");
    else
    {
        Log* plog = fn.Env->GetTarget()->GetLog();
        if (plog)
            plog->LogMessageById(LogChannel_Script | LogMessage_Error, "LoadVars.addRequestHeader is not implemented.");
    }
}

// LoadVars.decode(string): unescapes the string and loads its name=value pairs into the object.
// @0x1428ec130
// MS2-FUNCTIONAL same calls; cl orders the null-guarded this conversion differently around the string temporaries
void LoadVarsProto::Decode(const FnCall& fn)
{
    if (fn.NArgs <= 0)
        return;
    MS2_AS2_CHECK_THIS(fn, LoadVars);
    Object* pthis = (Object*)fn.ThisPtr;
    ASString src = fn.Arg(0).ToString(fn.Env);
    String   data;
    ASUtils::Unescape(src.ToCStr(), src.GetLength(), &data);
    if (pthis)
        LoadVariables(fn.Env, pthis, data);
}

// @0x1428ec290
void LoadVarsProto::GetBytesLoaded(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, LoadVars);
    LoadVarsObject* pthis = (LoadVarsObject*)fn.ThisPtr;
    Number          loaded = pthis->BytesLoaded;
    if (loaded < 0)
        fn.Result->SetUndefined();
    else
        fn.Result->SetNumber(loaded);
}

// @0x1428ec330
void LoadVarsProto::GetBytesTotal(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, LoadVars);
    LoadVarsObject* pthis = (LoadVarsObject*)fn.ThisPtr;
    Number          total = pthis->BytesTotal;
    if (total < 0)
        fn.Result->SetUndefined();
    else
        fn.Result->SetNumber(total);
}

// LoadVars.load(url): queues the load, false without an url.
// @0x1428ec3d0
// MS2-FUNCTIONAL same calls; register allocation of the this conversion and the url string differs
void LoadVarsProto::Load(const FnCall& fn)
{
    if (fn.NArgs == 0)
    {
        fn.Result->SetBool(false);
        return;
    }
    MS2_AS2_CHECK_THIS(fn, LoadVars);
    LoadVarsObject* pthis = (LoadVarsObject*)fn.ThisPtr;
    ASString        url = fn.Arg(0).ToString(fn.Env);
    pthis->BytesLoaded = 0;
    fn.Env->GetAS2Root()->AddVarLoadQueueEntry(pthis, url.ToCStr(), LoadQueueEntry::LM_None);
    fn.Result->SetBool(true);
}

// @0x1428ec510
// MS2-FUNCTIONAL the exe tests the this-class check after loading the environment and tail-calls the error path (branch layout)
void LoadVarsProto::Send(const FnCall& fn)
{
    if (!fn.CheckThisPtr(ObjectInterface::Object_LoadVars))
        fn.ThisPtrError("LoadVars");
    else
    {
        Log* plog = fn.Env->GetTarget()->GetLog();
        if (plog)
            plog->LogMessageById(LogChannel_Script | LogMessage_Error, "LoadVars.send is not implemented.");
    }
}

// @0x1428ec590
// MS2-FUNCTIONAL the exe tests the this-class check after loading the environment and tail-calls the error path (branch layout)
void LoadVarsProto::SendAndLoad(const FnCall& fn)
{
    if (!fn.CheckThisPtr(ObjectInterface::Object_LoadVars))
        fn.ThisPtrError("LoadVars");
    else
    {
        Log* plog = fn.Env->GetTarget()->GetLog();
        if (plog)
            plog->LogMessageById(LogChannel_Script | LogMessage_Error, "LoadVars.sendAndLoad is not implemented.");
    }
}

// LoadVars.toString's member visitor (namespace scope so the exe's vftable slot can name its Visit).
class LoadVarsStringVisitor : public ObjectInterface::MemberVisitor
{
public:
    Environment* pEnv;
    String*      pString;

    // @0x142993ff0
    virtual void Visit(const ASString& name, const Value& val, UByte flags)
    {
        StringBuffer buf(Memory::GetGlobalHeap());
        String       escaped;
        ASUtils::Escape(name.ToCStr(), name.GetSize(), &escaped);
        buf.AppendString(escaped.ToCStr(), escaped.GetSize());
        buf.AppendString("=");
        escaped.Clear();
        ASString valStr = val.ToString(pEnv);
        ASUtils::Escape(valStr.ToCStr(), valStr.GetSize(), &escaped);
        buf.AppendString(escaped.ToCStr(), escaped.GetSize());
        buf.AppendString("&");
        *pString = buf;
    }
};

// LoadVars.toString(): the members as url-encoded name=value pairs joined by &.
// @0x1428ec610
// MS2-FUNCTIONAL same calls; the result string node is built with different operand order (CreateString inline)
void LoadVarsProto::ToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, LoadVars);

    Object* pthis = (Object*)fn.ThisPtr;
    String  result;
    LoadVarsStringVisitor visitor;
    visitor.pEnv = fn.Env;
    visitor.pString = &result;
    pthis->VisitMembers(fn.Env->GetSC(), &visitor, 0);
    result.Remove(result.GetLength() - 1, 1);
    fn.Result->SetString(fn.Env->CreateString(result.ToCStr(), result.GetSize()));
}

// ---- MovieClipLoader ----

// @0x1428eb340
// MS2-FUNCTIONAL same flow; the exe inlines the argument-stack lookups and the character check in a different order
void MovieClipLoaderProto::LoadClip(const FnCall& fn)
{
    fn.Result->SetBool(false);
    if (fn.NArgs < 2)
        return;
    MovieClipLoader* pmcl = 0;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == ObjectInterface::Object_MovieClipLoader)
        pmcl = (MovieClipLoader*)fn.ThisPtr;
    ASString               url = fn.Arg(0).ToString(fn.Env);
    Ptr<InteractiveObject> ptarget;
    if (fn.Arg(1).IsCharacter())
        ptarget = fn.Arg(1).ToCharacter(fn.Env);
    else
    {
        ASString path = fn.Arg(1).ToString(fn.Env);
        ptarget = fn.Env->FindTarget(path, 0);
    }
    MovieRoot* proot = fn.Env->GetAS2Root();
    if (ptarget)
        proot->AddLoadQueueEntry(ptarget, url.ToCStr(), LoadQueueEntry::LM_None, pmcl);
    else
    {
        bool         caseSensitive = fn.Env->GetTarget()->GetVersion() > 6;
        const char*  ptail;
        ASString     tname = fn.Arg(1).ToString(fn.Env);
        if (MovieRoot::ParseLevelName(tname.ToCStr(), &ptail, caseSensitive) == -1)
            return;
        ASString lname = fn.Arg(1).ToString(fn.Env);
        proot->AddLoadQueueEntry(lname.ToCStr(), url.ToCStr(), fn.Env, LoadQueueEntry::LM_None, pmcl);
    }
    fn.Result->SetBool(true);
}

// @0x1428eb6d0
// MS2-FUNCTIONAL same flow; the exe's inlined argument lookups and level/path dispatch are scheduled differently
void MovieClipLoaderProto::UnloadClip(const FnCall& fn)
{
    fn.Result->SetBool(false);
    if (fn.NArgs < 1)
        return;
    Ptr<InteractiveObject> ptarget;
    const Value&           arg = fn.Arg(0);
    if (arg.IsCharacter())
        ptarget = arg.ToCharacter(fn.Env);
    else if (arg.IsNumber())
        ptarget = fn.Env->GetAS2Root()->GetLevelMovie(arg.ToInt32(fn.Env));
    else
    {
        ASString path = arg.ToString(fn.Env);
        ptarget = fn.Env->FindTarget(path, 0);
    }
    if (!ptarget)
        return;
    fn.Env->GetAS2Root()->AddLoadQueueEntry(ptarget, "", LoadQueueEntry::LM_None, 0);
    fn.Result->SetBool(true);
}

// @0x1428eb050
// MS2-FUNCTIONAL same members and calls; the exe's argument lookup and hash probe are scheduled differently
void MovieClipLoaderProto::GetProgress(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    fn.Result->SetUndefined();
    MS2_AS2_CHECK_THIS(fn, MovieClipLoader);
    MovieClipLoader* pthis = (MovieClipLoader*)fn.ThisPtr;
    Ptr<Object>      pobj = Pickable<Object>(SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env));
    ASString         target = fn.Arg(0).ToString(fn.Env);
    MovieClipLoader::ProgressDesc* pdesc = pthis->ProgressInfo.Get(String(target.ToCStr()));
    if (pdesc)
    {
        ASStringContext* psc = fn.Env->GetSC();
        pobj->SetMemberRaw(psc, psc->CreateConstString("bytesLoaded"), Value(pdesc->LoadedBytes), PropFlags());
        pobj->SetMemberRaw(psc, psc->CreateConstString("bytesTotal"), Value(pdesc->TotalBytes), PropFlags());
    }
    fn.Result->SetAsObject(pobj);
}

// Global trace(): logs the argument; an object with a toString function is converted by it. Text is cut at 2000
// bytes and carriage returns become line feeds.
// @0x1428f6de0
// MS2-FUNCTIONAL same logic; the exe branches around the length clamp and keeps it in a 64-bit register (cl uses cmov here)
void GAS_GlobalTrace(const FnCall& fn)
{
    ObjectInterface* pobj = fn.Arg(0).ToObjectInterface(fn.Env);
    if (pobj)
    {
        Value method;
        if (pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->GetBuiltin(ASBuiltin_toString), &method) && method.IsFunction())
        {
            Value result;
            GAS_Invoke(method, &result, pobj, fn.Env, 0, fn.Env->GetTopIndex(), 0);
            fn.LogScriptMessage("%s\n", result.ToString(fn.Env).ToCStr());
            return;
        }
    }
    ASString text = fn.Arg(0).ToString(fn.Env);
    char     buf[2000];
    unsigned len = text.GetSize();
    if (len >= 2000)
        len = 1999;
    strncpy_s(buf, 2000, text.ToCStr(), len);
    if (len < 2000)
        buf[len] = 0;
    for (char* p = buf; *p; ++p)
        if (*p == '\r')
            *p = '\n';
    fn.LogScriptMessage(text.GetSize() >= 2000 ? "%s..." : "%s\n", buf);
}

// BitmapData.loadBitmap(linkageId): a bitmap holding the image resource exported with the id, null without one.
// @0x1428f1e70
// MS2-FUNCTIONAL same calls; register allocation and the resource-release epilogue are scheduled differently
void BitmapDataCtorFunction::LoadBitmapA(const FnCall& fn)
{
    fn.Result->SetNull();
    if (fn.NArgs < 1)
        return;
    ASString           id = fn.Arg(0).ToString(fn.Env);
    InteractiveObject* ptarget = fn.Env->GetTarget();
    Ptr<ImageResource> pimg = ptarget->GetMovieImpl()->GetImageResourceByLinkageId(ptarget->GetResourceMovieDef(), id.ToCStr());
    if (!pimg)
    {
        fn.Env->LogScriptWarning("BitmapData::LoadBitmap: LoadMovieImageCallback failed to load image \"%s\"", id.ToCStr());
        return;
    }
    Ptr<MovieDefImpl> pdef = ptarget->GetResourceMovieDef();
    Ptr<BitmapData>   pbitmap = *SF_HEAP_NEW(fn.Env->GetHeap()) BitmapData(fn.Env);
    pbitmap->SetImage(fn.Env, pimg, pdef);
    fn.Result->SetAsObject(pbitmap);
}

// Global parseInt(string, radix): the radix is 8 or 16 for a 0 / 0x prefix when not given, NaN for a radix outside 2..36
// or text without digits.
// @0x1428f70b0
// MS2-FUNCTIONAL same logic; register allocation and argument-stack lookup scheduling differ
void GAS_GlobalParseInt(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    ASString text = fn.Arg(0).ToString(fn.Env);
    int      radix = 10;
    int      skip = 0;
    if (fn.NArgs >= 2)
    {
        radix = fn.Arg(1).ToInt32(fn.Env);
        if (radix < 2 || radix > 36)
        {
            fn.Result->SetNumber(NumberUtil::NaN());
            return;
        }
    }
    else if (text.GetSize() > 1 && text.ToCStr()[0] == '0')
    {
        radix = 8;
        skip = 1;
        if (text.ToCStr()[1] == 'x' || text.ToCStr()[1] == 'X')
        {
            radix = 16;
            skip = 2;
        }
    }
    char* pend = 0;
    int   val = (int)strtol(text.ToCStr() + skip, &pend, radix);
    if (text.ToCStr() + skip == pend && radix != 8)
        fn.Result->SetNumber(NumberUtil::NaN());
    else
        fn.Result->SetInt(val);
}

// Global ifFrameLoaded(frame): true when the frame has been loaded in this (or the target) clip.
// @0x1428f74a0
void GAS_GlobalIfFrameLoaded(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    fn.Result->SetBool(false);
    Sprite* psprite;
    if (!fn.ThisPtr)
        psprite = (Sprite*)fn.Env->GetTarget();
    else
    {
        if (fn.ThisPtr->GetObjectType() != ObjectInterface::Object_Sprite)
            return;
        psprite = (Sprite*)fn.ThisPtr;
    }
    if (!psprite)
        return;
    int frame = fn.Arg(0).ToInt32(fn.Env);
    if (frame < (int)psprite->GetLoadingFrame())
        fn.Result->SetBool(true);
}

// ---- Global IME functions ----

// Global imecommand(command, parameter): forwards to the movie's IME manager.
// @0x1428f8540
// MS2-FUNCTIONAL same calls; register allocation of the movie/IME temporaries differs
void GAS_GlobalIMECommand(const FnCall& fn)
{
    if (fn.NArgs < 2)
        return;
    MovieImpl*          pmovie = fn.Env->GetTarget()->GetMovieImpl();
    Ptr<IMEManagerBase> pime = pmovie->GetIMEManager();
    if (pime)
    {
        ASString param = fn.Arg(1).ToString(fn.Env);
        ASString command = fn.Arg(0).ToString(fn.Env);
        pime->IMECommand(reinterpret_cast<Movie*>(pmovie), command.ToCStr(), param.ToCStr());
    }
}

// Global getInputLanguage(): the IME's input language, "UNKNOWN" without an IME.
// @0x1428fafd0
// MS2-FUNCTIONAL same calls; register allocation of the movie/IME temporaries differs
void GAS_GlobalGetInputLanguage(const FnCall& fn)
{
    if (!fn.Env)
        return;
    Ptr<IMEManagerBase> pime = fn.Env->GetTarget()->GetMovieImpl()->GetIMEManager();
    ASString            lang = fn.Env->CreateConstString("UNKNOWN");
    if (pime)
        lang = fn.Env->CreateString(pime->GetInputLanguage());
    fn.Result->SetString(lang);
}

// Global ASnative(800, 2): the native mouse button state test (sfr_as2_05), undefined for any other pair.
void GAS_ASnativeMouseButtonStates(const FnCall& fn);

// @0x1428f7d30
// MS2-FUNCTIONAL same logic; the exe's argument lookups and reference handling are scheduled differently
void GAS_GlobalASnative(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs < 2)
        return;
    unsigned a = fn.Arg(0).ToUInt32(fn.Env);
    unsigned b = fn.Arg(1).ToUInt32(fn.Env);
    if (a != 800 || b != 2)
        return;
    Ptr<CFunctionObject> pfunc =
        SF_HEAP_NEW(fn.Env->GetHeap()) CFunctionObject(fn.Env->GetSC(), GAS_ASnativeMouseButtonStates);
    fn.Result->SetAsFunction(FunctionRef(pfunc));
}

// ASSetPropFlags's member visitor (namespace scope so the exe's vftable slot can name its Visit).
class ASSetPropFlagsVisitor : public ObjectInterface::MemberVisitor
{
public:
    ObjectInterface* pObj;
    ASStringContext* pSC;
    UByte            SetTrue;
    UByte            SetFalse;

    // @0x1428f7bb0
    virtual void Visit(const ASString& name, const Value& val, UByte flags)
    {
        pObj->SetMemberFlags(pSC, name, (UByte)((~SetFalse & flags) | SetTrue));
    }
};

// Global ASSetPropFlags(object, names, setTrue[, setFalse]): sets / clears the DontEnum/DontDelete/ReadOnly bits of the
// named members (a comma separated string or an array), of all members for null names.
// @0x1428f7740
// MS2-FUNCTIONAL same logic; the exe's argument decoding and visitor setup are scheduled differently
void GAS_GlobalASSetPropFlags(const FnCall& fn)
{

    UByte            version = fn.Env->GetVersion();
    ObjectInterface* pobj = fn.Arg(0).ToObjectInterface(fn.Env);
    if (!pobj)
        return;

    Ptr<ArrayObject> props;
    int              setFalseDefault = 0;
    const Value&     names = fn.Arg(1);
    if (names.IsString())
    {
        ASString list = names.ToString(fn.Env);
        props = StringProto::StringSplit(fn.Env, list, ",", 0x3fffffff);
        setFalseDefault = -1;
    }
    else if (names.IsObject())
    {
        Object* pn = names.ToObject(fn.Env);
        if (pn && pn->GetObjectType() == ObjectInterface::Object_Array)
            props = static_cast<ArrayObject*>(pn);
        else if (pn && pn->GetObjectType() == ObjectInterface::Object_String)
        {
            ASString list = names.ToString(fn.Env);
            props = StringProto::StringSplit(fn.Env, list, ",", 0x3fffffff);
        }
        else
            return;
        setFalseDefault = -1;
    }
    else if (!names.IsNull())
        return;

    UByte setTrue = (UByte)(fn.Arg(2).ToInt32(fn.Env) & 7);
    UByte setFalse;
    if (fn.NArgs == 3)
        setFalse = (UByte)((version == 5 ? setFalseDefault : 0) & 7);
    else
        setFalse = (UByte)(fn.Arg(3).ToUInt32(fn.Env) & 7);

    ASStringContext* psc = fn.Env->GetSC();
    if (!props)
    {
        ASSetPropFlagsVisitor visitor;
        visitor.pObj = pobj;
        visitor.pSC = psc;
        visitor.SetTrue = setTrue;
        visitor.SetFalse = setFalse;
        pobj->VisitMembers(psc, &visitor, 0xc, 0);
    }
    else
    {
        for (int i = 0; i < props->GetSize(); i++)
        {
            Value* pv = props->GetElementPtr(i);
            if (!pv)
                continue;
            ASString name = pv->ToString(fn.Env);
            Member   m;
            if (pobj->FindMember(psc, name, &m))
                pobj->SetMemberFlags(psc, name, (UByte)((~setFalse & m.mValue.T.PropFlags) | setTrue));
        }
    }
}

// ---- Global IME candidate list style ----
}}} // namespace Scaleform::GFx::AS2
// Bodies of the exe called here, by their addresses.
bool FUN_1425b4570(void* pime, Scaleform::GFx::IMECandidateListStyle* pstyle);       // IMEManagerBase::GetCandidateListStyle
bool FUN_1425b4de0(void* pime, const Scaleform::GFx::IMECandidateListStyle& style);  // IMEManagerBase::SetCandidateListStyle
namespace Scaleform { namespace GFx { namespace AS2 {

// Global getIMECandidateListStyle(): an object with the style members that are set.
// @0x1428fa7a0
// MS2-FUNCTIONAL same members and conversions; the exe's temporaries and branch layout differ
void GAS_GlobalGetIMECandidateListStyle(const FnCall& fn)
{
    Ptr<IMEManagerBase> pime = fn.Env->GetTarget()->GetMovieImpl()->GetIMEManager();
    if (!pime)
        return;
    IMECandidateListStyle style;
    if (!FUN_1425b4570(pime, &style))
        return;
    Ptr<Object>      pobj = SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);
    ASStringContext* psc = fn.Env->GetSC();
    if (style.HasTextColor())
        pobj->SetMemberRaw(psc, psc->CreateConstString("textColor"), Value((Number)style.GetTextColor()), PropFlags());
    if (style.HasBackgroundColor())
        pobj->SetMemberRaw(psc, psc->CreateConstString("backgroundColor"), Value((Number)style.GetBackgroundColor()), PropFlags());
    if (style.HasIndexBackgroundColor())
        pobj->SetMemberRaw(psc, psc->CreateConstString("indexBackgroundColor"), Value((Number)style.GetIndexBackgroundColor()), PropFlags());
    if (style.HasSelectedTextColor())
        pobj->SetMemberRaw(psc, psc->CreateConstString("selectedTextColor"), Value((Number)style.GetSelectedTextColor()), PropFlags());
    if (style.HasSelectedBackgroundColor())
        pobj->SetMemberRaw(psc, psc->CreateConstString("selectedTextBackgroundColor"), Value((Number)style.GetSelectedBackgroundColor()), PropFlags());
    if (style.HasSelectedIndexBackgroundColor())
        pobj->SetMemberRaw(psc, psc->CreateConstString("selectedIndexBackgroundColor"), Value((Number)style.GetSelectedIndexBackgroundColor()), PropFlags());
    if (style.HasFontSize())
        pobj->SetMemberRaw(psc, psc->CreateConstString("fontSize"), Value((Number)style.GetFontSize()), PropFlags());
    if (style.HasReadingWindowTextColor())
        pobj->SetMemberRaw(psc, psc->CreateConstString("readingWindowTextColor"), Value((Number)style.GetReadingWindowTextColor()), PropFlags());
    if (style.HasReadingWindowBackgroundColor())
        pobj->SetMemberRaw(psc, psc->CreateConstString("readingWindowBackgroundColor"), Value((Number)style.GetReadingWindowBackgroundColor()), PropFlags());
    if (style.HasReadingWindowFontSize())
        pobj->SetMemberRaw(psc, psc->CreateConstString("readingWindowFontSize"), Value((Number)style.GetReadingWindowFontSize()), PropFlags());
    fn.Result->SetAsObject(pobj);
}

// Global setIMECandidateListStyle(object): the numeric members of the object become the style.
// @0x1428f9f50
// MS2-FUNCTIONAL same members and conversions; the exe's temporaries and branch layout differ
void GAS_GlobalSetIMECandidateListStyle(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    Ptr<IMEManagerBase> pime = fn.Env->GetTarget()->GetMovieImpl()->GetIMEManager();
    if (!pime)
        return;
    Object* pobjArg = fn.Arg(0).ToObject(fn.Env);
    if (!pobjArg)
        return;
    Ptr<Object>         holder = pobjArg;
    ObjectInterface*    pobj = pobjArg;
    ASStringContext*    psc = fn.Env->GetSC();
    IMECandidateListStyle style;
    Value               val;
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("textColor"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetTextColor((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("backgroundColor"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetBackgroundColor((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("indexBackgroundColor"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetIndexBackgroundColor((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("selectedTextColor"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetSelectedTextColor((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("selectedTextBackgroundColor"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetSelectedBackgroundColor((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("selectedIndexBackgroundColor"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetSelectedIndexBackgroundColor((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("fontSize"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetFontSize((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("readingWindowTextColor"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetReadingWindowTextColor((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("readingWindowBackgroundColor"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetReadingWindowBackgroundColor((UInt32)(SInt64)n);
    }
    if (pobj->GetMemberRaw(psc, psc->CreateConstString("readingWindowFontSize"), &val))
    {
        Number n = val.ToNumber(fn.Env);
        if (!NumberUtil::IsNaNOrInfinity(n))
            style.SetReadingWindowFontSize((UInt32)(SInt64)n);
    }
    FUN_1425b4de0(pime, style);
}

// ---- TextField IME composition string styles ----
}}} // namespace Scaleform::GFx::AS2
// Bodies of the exe called here (not recovered yet), by their addresses.
Scaleform::GFx::AS2::TextFieldObject* FUN_142956410(Scaleform::GFx::AS2::AvmTextField* ptextField);   // AvmTextField::GetTextFieldASObject
void FUN_142981750(Scaleform::GFx::AS2::TextFieldObject* pobj, const Scaleform::GFx::Text::IMEStyle* pstyle); // TextFieldObject::SetIMECompositionStringStyles
Scaleform::Render::Text::HighlightInfo FUN_14296e9f0(const Scaleform::GFx::AS2::FnCall& fn, unsigned index,
                                                     const Scaleform::Render::Text::HighlightInfo& base);   // TextFieldProto::ParseStyle
void FUN_142968610(const Scaleform::GFx::AS2::FnCall& fn, const Scaleform::Render::Text::HighlightInfo& info); // TextFieldProto::MakeStyle
namespace Scaleform { namespace GFx { namespace AS2 {

// The category of an IME style name (exe 0x1429487e0).
int GFx_StringToIMEStyleCategory(const ASString& name);

// The IME styles as the text field object stores them (Text::IMEStyle, 0x54 bytes): a highlight look per category.
struct IMEStyleData
{
    enum { SC_MaxNum = 5 };
    Render::Text::HighlightInfo HighlightStyles[SC_MaxNum];
    UByte                       PresenceMask;
    IMEStyleData() : PresenceMask(0) {}
    bool HasElement(UPInt n) const { return (PresenceMask & (1 << n)) != 0; }
};

// The text field object of this (a text field or its AS object), referenced.
static Ptr<TextFieldObject> GetThisTextFieldObject(const FnCall& fn)
{
    if (!fn.ThisPtr)
        return 0;
    if (fn.ThisPtr->GetObjectType() == ObjectInterface::Object_TextField)
        return FUN_142956410((AvmTextField*)fn.ThisPtr);
    if (fn.ThisPtr->GetObjectType() == ObjectInterface::Object_TextFieldASObject)
        return (TextFieldObject*)fn.ThisPtr;
    return 0;
}

// TextField.setIMECompositionStringStyle(category, style)
// @0x1428eb900
// MS2-FUNCTIONAL same sequence; the exe copies the highlight records field by field and keeps the temporaries in different slots
void TextFieldProto::SetIMECompositionStringStyle(const FnCall& fn)
{
    Ptr<TextFieldObject> ptf = GetThisTextFieldObject(fn);
    if (!ptf || fn.NArgs < 1)
        return;
    ASString                 name = fn.Arg(0).ToString(fn.Env);
    int cat = GFx_StringToIMEStyleCategory(name);
    if (cat < IMEStyleData::SC_MaxNum)
    {
        IMEStyleData  newStyle;
        IMEStyleData* pold = (IMEStyleData*)ptf->GetIMECompositionStringStyles();
        if (pold)
            newStyle = *pold;
        newStyle.HighlightStyles[cat] = FUN_14296e9f0(fn, 1, newStyle.HighlightStyles[cat]);
        newStyle.PresenceMask |= (UByte)(1 << cat);
        FUN_142981750(ptf, (const Text::IMEStyle*)&newStyle);
    }
}

// TextField.getIMECompositionStringStyle(category)
// @0x1428ebbd0
// MS2-FUNCTIONAL same sequence; temporaries and release order differ
void TextFieldProto::GetIMECompositionStringStyle(const FnCall& fn)
{
    fn.Result->SetUndefined();
    Ptr<TextFieldObject> ptf = GetThisTextFieldObject(fn);
    if (!ptf || fn.NArgs < 1)
        return;
    IMEStyleData* pstyles = (IMEStyleData*)ptf->GetIMECompositionStringStyles();
    ASString      name = fn.Arg(0).ToString(fn.Env);
    int           cat = GFx_StringToIMEStyleCategory(name);
    if (pstyles && cat < IMEStyleData::SC_MaxNum && pstyles->HasElement(cat))
        FUN_142968610(fn, pstyles->HighlightStyles[cat]);
}

// ---- Global escape functions ----

// @0x1428f7ed0
// MS2-FUNCTIONAL same calls; the exe loads the string manager before the result string's data/size (operand scheduling)
void GAS_GlobalEscape(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs == 1)
    {
        ASString src = fn.Arg(0).ToString(fn.Env);
        String   result;
        ASUtils::Escape(src.ToCStr(), src.GetSize(), &result);
        fn.Result->SetString(fn.Env->CreateString(result.ToCStr(), result.GetSize()));
    }
}

// @0x1428f8020
// MS2-FUNCTIONAL same calls; the exe loads the string manager before the result string's data/size (operand scheduling)
void GAS_GlobalUnescape(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs == 1)
    {
        ASString src = fn.Arg(0).ToString(fn.Env);
        String   result;
        ASUtils::Unescape(src.ToCStr(), src.GetSize(), &result);
        fn.Result->SetString(fn.Env->CreateString(result.ToCStr(), result.GetSize()));
    }
}

// @0x1428f8170
// MS2-FUNCTIONAL same calls; the exe loads the string manager before the result string's data/size (operand scheduling)
void GAS_GlobalEscapeSpecialHTML(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs == 1)
    {
        ASString src = fn.Arg(0).ToString(fn.Env);
        String   result;
        String::EscapeSpecialHTML(src.ToCStr(), src.GetLength(), &result);
        fn.Result->SetString(fn.Env->CreateString(result.ToCStr(), result.GetSize()));
    }
}

// @0x1428f83d0
// MS2-FUNCTIONAL same calls; the exe loads the string manager before the result string's data/size (operand scheduling)
void GAS_GlobalUnescapeSpecialHTML(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (fn.NArgs == 1)
    {
        ASString src = fn.Arg(0).ToString(fn.Env);
        String   result;
        String::UnescapeSpecialHTML(src.ToCStr(), src.GetLength(), &result);
        fn.Result->SetString(fn.Env->CreateString(result.ToCStr(), result.GetSize()));
    }
}

// ---- StyleSheet ----
// Bodies of the exe called here (not recovered yet), by their addresses; the style manager is opaque.
}}} // namespace Scaleform::GFx::AS2
void FUN_142609630(void* pstyleManager);                              // Text::StyleManager::Clear
bool FUN_14260b7f0(void* pstyleManager, const char* pcss, unsigned size); // Text::StyleManager::ParseCSS
namespace Scaleform { namespace GFx { namespace AS2 {

// StyleSheet.clear()
// @0x1428f86b0
void StyleSheetProto::Clear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, StyleSheet);
    StyleSheetObject* pthis = (StyleSheetObject*)fn.ThisPtr;
    if (pthis)
        FUN_142609630(pthis->Data68);
}

// StyleSheet.parseCSS(text): false without a text or a parse error.
// @0x1428f9ba0
void StyleSheetProto::ParseCSS(const FnCall& fn)
{
    if (fn.CheckThisPtr(ObjectInterface::Object_StyleSheet))
    {
        StyleSheetObject* pthis = (StyleSheetObject*)fn.ThisPtr;
        if (!pthis)
            return;
        if (fn.NArgs < 1)
        {
            fn.Result->SetBool(false);
            return;
        }
        Value    arg(fn.Arg(0));
        ASString css = arg.ToString(fn.Env);
        fn.Result->SetBool(FUN_14260b7f0(pthis->Data68, css.ToCStr(), css.GetSize()));
    }
    else
        fn.ThisPtrError("StyleSheet");
}

// Array.sort([compareFunction], [options]): sorts a copy and swaps it in, or returns a copy / 0 for a duplicate.
// @0x1428f5740
// MS2-FUNCTIONAL same sequence; the exe keeps the argument/functor temporaries in different registers
void ArrayObject::ArraySort(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;
    pthis->LengthValueOverriden = false;

    FunctionRef sortFunc;
    int         flags = 0;
    if (fn.NArgs >= 1)
    {
        if (fn.Arg(0).IsFunction())
        {
            sortFunc = fn.Arg(0).ToFunction(fn.Env);
            if (fn.NArgs >= 2)
                flags = fn.Arg(1).ToInt32(fn.Env);
        }
        else
            flags = fn.Arg(0).ToInt32(fn.Env);
    }

    Ptr<ArrayObject> pnew = *static_cast<ArrayObject*>(fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_Array)));
    pnew->ShallowCopyFrom(*pthis);

    ArraySortFunctor sf(fn.ThisPtr, flags, sortFunc, fn.Env, pthis->LogPtr);
    Alg::ArrayAdaptor<Value*> adaptor(pnew->Elements.GetDataPtr(), pnew->Elements.GetSize());
    if (!Alg::QuickSortSlicedSafe(adaptor, 0, pnew->Elements.GetSize(), sf))
        fn.Env->LogScriptError("Array.sort - sorting failed, check your sort functor");

    bool duplicate = false;
    if (flags & SortFlags_UniqueSort)
    {
        for (int i = 1; i < pnew->GetSize(); i++)
            if (sf.Compare(pnew->Elements[i - 1], pnew->Elements[i]) == 0)
            {
                duplicate = true;
                break;
            }
    }
    if (duplicate)
    {
        fn.Result->SetInt(0);
        ArrayObjectElements_Resize(&pnew->Elements, 0);
    }
    else if (flags & SortFlags_ReturnIndexedArray)
    {
        pnew->MakeDeepCopy(fn.Env->GetHeap());
        fn.Result->SetAsObject(pnew);
    }
    else
    {
        pthis->ShallowCopyFrom(*pnew);
        ArrayObjectElements_Resize(&pnew->Elements, 0);
        fn.Result->SetAsObject(pthis);
    }
}

// Array.sortOn(fieldNames, [options]): sorts by the named members of the elements, one option word per field.
// @0x1428f5d60
// MS2-FUNCTIONAL same sequence; the exe's functor array construction and temporaries are scheduled differently
void ArrayObject::ArraySortOn(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;
    ArrayCC<ASString> fields(fn.Env->GetBuiltin(ASBuiltin_Array));
    ArrayLH<int>      options;
    if (fn.NArgs == 0)
    {
        fn.Result->SetUndefined();
        return;
    }
    pthis->LengthValueOverriden = false;

    ASString dummy = fn.Env->GetBuiltin(ASBuiltin_Array);
    Object* parr = fn.Arg(0).ToObject(fn.Env);
    if (parr && parr->GetObjectType() == Object_Array)
    {
        ArrayObject* pa = static_cast<ArrayObject*>(parr);
        for (int i = 0; i < pa->GetSize(); i++)
        {
            if (Value* pv = pa->GetElementPtr(i))
                fields.PushBack(pv->ToString(fn.Env));
            else
                fields.PushBack(dummy);
        }
    }
    else
        fields.PushBack(fn.Arg(0).ToString(fn.Env));

    options.Resize(fields.GetSize());
    for (UPInt i = 0; i < options.GetSize(); i++)
        options[i] = 0;
    int flags = 0;
    if (fn.NArgs >= 2)
    {
        Object* po = fn.Arg(1).ToObject(fn.Env);
        if (po && po->GetObjectType() == Object_Array)
        {
            ArrayObject* pa = static_cast<ArrayObject*>(po);
            for (int i = 0; i < pa->GetSize() && (UPInt)i < fields.GetSize(); i++)
                if (Value* pv = pa->GetElementPtr(i))
                    options[i] = pv->ToInt32(fn.Env);
        }
        else
        {
            flags = fn.Arg(1).ToInt32(fn.Env);
            for (UPInt i = 0; i < fields.GetSize(); i++)
                options[i] = flags;
        }
    }

    Ptr<ArrayObject> pnew = *static_cast<ArrayObject*>(fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_Array)));
    ArrayObjectElements_Resize(&pnew->Elements, pthis->Elements.GetSize());
    for (UPInt i = 0; i < pnew->Elements.GetSize(); i++)
        pnew->Elements[i] = pthis->Elements[i];

    ArraySortOnFunctor sf(fn.ThisPtr, &fields, fn.Env, pthis->LogPtr);
    sf.GetFunctorArray().Resize(fields.GetSize());
    for (UPInt i = 0; i < fields.GetSize(); i++)
        sf.GetFunctorArray()[i] = ArraySortFunctor(fn.ThisPtr, options[i], FunctionRef(), fn.Env, pthis->LogPtr);
    Alg::ArrayAdaptor<Value*> adaptor(pnew->Elements.GetDataPtr(), pnew->Elements.GetSize());
    Alg::QuickSortSlicedSafe(adaptor, 0, pnew->Elements.GetSize(), sf);

    bool duplicate = false;
    if (flags & SortFlags_UniqueSort)
    {
        for (int i = 1; i < pnew->GetSize(); i++)
            if (sf.Compare(pnew->Elements[i - 1], pnew->Elements[i]) == 0)
            {
                duplicate = true;
                break;
            }
    }
    if (duplicate)
    {
        fn.Result->SetInt(0);
    }
    else if (flags & SortFlags_ReturnIndexedArray)
    {
        pnew->MakeDeepCopy(fn.Env->GetHeap());
        fn.Result->SetAsObject(pnew);
    }
    else
    {
        ArrayObjectElements_Resize(&pthis->Elements, pnew->Elements.GetSize());
        for (UPInt i = 0; i < pnew->Elements.GetSize(); i++)
            pthis->Elements[i] = pnew->Elements[i];
        ArrayObjectElements_Resize(&pnew->Elements, 0);
        fn.Result->SetAsObject(pthis);
    }
}

// ---- Matrix ----

// "(a=.., b=.., c=.., d=.., tx=.., ty=..)" with six significant digits.
// @0x1428ed580
void MatrixProto::ToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    MatrixObject::GASMatrixArray matrix;
    pthis->GetMatrixAsValuesArray(fn.Env->GetSC(), &matrix);
    // The primitives are temporaries, so keep their strings referenced while the text is built.
    ASString mxs[6] = {matrix[0].ToPrimitive(fn.Env).ToString(fn.Env, 6), matrix[1].ToPrimitive(fn.Env).ToString(fn.Env, 6),
                       matrix[2].ToPrimitive(fn.Env).ToString(fn.Env, 6), matrix[3].ToPrimitive(fn.Env).ToString(fn.Env, 6),
                       matrix[4].ToPrimitive(fn.Env).ToString(fn.Env, 6), matrix[5].ToPrimitive(fn.Env).ToString(fn.Env, 6)};
    String str;
    str += "(a=";
    str += mxs[0].ToCStr();
    str += ", b=";
    str += mxs[1].ToCStr();
    str += ", c=";
    str += mxs[2].ToCStr();
    str += ", d=";
    str += mxs[3].ToCStr();
    str += ", tx=";
    str += mxs[4].ToCStr();
    str += ", ty=";
    str += mxs[5].ToCStr();
    str += ")";
    fn.Result->SetString(fn.Env->GetSC()->CreateString(str.ToCStr(), str.GetSize()));
}

// @0x1428ed9e0
MS2_AS2_NOGS void MatrixProto::Clone(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
    {
        fn.Result->SetUndefined();
        return;
    }
    Ptr<MatrixObject> m = *SF_HEAP_NEW(fn.Env->GetHeap()) MatrixObject(fn.Env);
    m->SetMatrix(fn.Env, pthis->GetMatrix(fn.Env));
    fn.Result->SetAsObject(m.GetPtr());
}

// this = this followed by the argument matrix.
// @0x1428edaf0
void MatrixProto::Concat(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    if (fn.NArgs > 0)
    {
        Object* arg = fn.Arg(0).ToObject(fn.Env);
        if (arg->GetObjectType() == ObjectInterface::Object_Matrix)
        {
            Render::Matrix2F m = pthis->GetMatrix(fn.Env);
            m.Append(((MatrixObject*)arg)->GetMatrix(fn.Env));
            pthis->SetMatrix(fn.Env, m);
        }
    }
}

// createBox(scaleX, scaleY, [rotation], [tx], [ty])
// @0x1428edc40
void MatrixProto::CreateBox(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    if (fn.NArgs > 1)
    {
        Render::Matrix2F m;
        float sx = (float)fn.Arg(0).ToNumber(fn.Env);
        float sy = (float)fn.Arg(1).ToNumber(fn.Env);
        float r  = 0;
        float tx = 0;
        float ty = 0;
        if (fn.NArgs > 2)
        {
            r = (float)fn.Arg(2).ToNumber(fn.Env);
            if (fn.NArgs > 3)
            {
                tx = (float)fn.Arg(3).ToNumber(fn.Env);
                if (fn.NArgs > 4)
                    ty = (float)fn.Arg(4).ToNumber(fn.Env);
            }
        }
        Matrix2F_AppendRotation(&m, r);
        m.AppendScaling(sx, sy);
        Matrix2F_AppendTranslation(m, tx, ty);
        pthis->SetMatrix(fn.Env, m);
    }
}

// createGradientBox(width, height, [rotation], [tx], [ty]): the box is centred on (tx, ty) + size / 2.
// @0x1428edfc0
void MatrixProto::CreateGradientBox(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    if (fn.NArgs > 1)
    {
        Render::Matrix2F m;
        float w  = (float)fn.Arg(0).ToNumber(fn.Env);
        float h  = (float)fn.Arg(1).ToNumber(fn.Env);
        float r  = 0;
        float tx = w / 2;
        float ty = h / 2;
        if (fn.NArgs > 2)
        {
            r = (float)fn.Arg(2).ToNumber(fn.Env);
            if (fn.NArgs > 3)
            {
                tx += (float)fn.Arg(3).ToNumber(fn.Env);
                if (fn.NArgs > 4)
                    ty += (float)fn.Arg(4).ToNumber(fn.Env);
            }
        }
        w *= GASGradientBoxMagicNumber;
        h *= GASGradientBoxMagicNumber;
        Matrix2F_AppendRotation(&m, r);
        m.AppendScaling(w, h);
        Matrix2F_AppendTranslation(m, tx, ty);
        pthis->SetMatrix(fn.Env, m);
    }
}

// The argument point mapped without the translation.
// @0x1428ee370
// MS2-FUNCTIONAL the exe keeps both inlined Mul operands live in xmm6/xmm7 across the temp release (unity-build register allocation, as Point.distance)
MS2_AS2_NOGS void MatrixProto::DeltaTransformPoint(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    Object* arg = 0;
    if (fn.NArgs > 0 && (arg = fn.Arg(0).ToObject(fn.Env)) != 0 &&
        arg->GetObjectType() == ObjectInterface::Object_Point)
    {
        Render::Matrix2F m = pthis->GetMatrix(fn.Env);
        Value            ptprop[Point_NumProperties];
        ((PointObject*)arg)->GetProperties(fn.Env->GetSC(), ptprop);
        Ptr<PointObject> ppt = *SF_HEAP_NEW(fn.Env->GetHeap()) PointObject(fn.Env);
        Value            nptprop[Point_NumProperties];
        Value            x1 = Value(Number(m.Sx()));
        x1.Mul(fn.Env, ptprop[Point_X]);
        nptprop[Point_X] = Value(Number(m.Shx()));
        nptprop[Point_X].Mul_Call(fn.Env, ptprop[Point_Y]);
        nptprop[Point_X].Add(fn.Env, x1);
        x1 = Value(Number(m.Shy()));
        x1.Mul(fn.Env, ptprop[Point_X]);
        nptprop[Point_Y] = Value(Number(m.Sy()));
        nptprop[Point_Y].Mul_Call(fn.Env, ptprop[Point_Y]);
        nptprop[Point_Y].Add(fn.Env, x1);
        ppt->SetProperties_Call(fn.Env->GetSC(), nptprop);
        fn.Result->SetAsObject(ppt.GetPtr());
    }
}

// @0x1428ee770
MS2_AS2_NOGS void MatrixProto::Identity(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    pthis->SetMatrix(fn.Env, Render::Matrix2F());
}

// @0x1428ee800
MS2_AS2_NOGS void MatrixProto::Invert(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    pthis->SetMatrix(fn.Env, Matrix2F_Invert(pthis->GetMatrix(fn.Env)));
}

// @0x1428ee8b0
void MatrixProto::Rotate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    if (fn.NArgs > 0)
    {
        float            r = (float)fn.Arg(0).ToNumber(fn.Env);
        Render::Matrix2F m(pthis->GetMatrix(fn.Env));
        Matrix2F_AppendRotation(&m, r);
        pthis->SetMatrix(fn.Env, m);
    }
}

// @0x1428ee9e0
MS2_AS2_NOGS void MatrixProto::Scale(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    if (fn.NArgs > 1)
    {
        float            sx = (float)fn.Arg(0).ToNumber(fn.Env);
        float            sy = (float)fn.Arg(1).ToNumber(fn.Env);
        Render::Matrix2F m(pthis->GetMatrix(fn.Env));
        m.AppendScaling(sx, sy);
        pthis->SetMatrix(fn.Env, m);
    }
}

// The argument point mapped by the matrix.
// @0x1428eeb50
// MS2-FUNCTIONAL the exe keeps both inlined Mul operands live in xmm6/xmm7 across the temp release (unity-build register allocation, as Point.distance)
MS2_AS2_NOGS void MatrixProto::TransformPoint(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    Object* arg = 0;
    if (fn.NArgs > 0 && (arg = fn.Arg(0).ToObject(fn.Env)) != 0 &&
        arg->GetObjectType() == ObjectInterface::Object_Point)
    {
        Render::Matrix2F m = pthis->GetMatrix(fn.Env);
        Value            ptprop[Point_NumProperties];
        ((PointObject*)arg)->GetProperties(fn.Env->GetSC(), ptprop);
        Ptr<PointObject> ppt = *SF_HEAP_NEW(fn.Env->GetHeap()) PointObject(fn.Env);
        Value            nptprop[Point_NumProperties];
        Value            x1 = Value(Number(m.Sx()));
        x1.Mul(fn.Env, ptprop[Point_X]);
        Value x2 = Value(Number(m.Shx()));
        x2.Mul(fn.Env, ptprop[Point_Y]);
        nptprop[Point_X] = Value(Number(m.Tx()));
        nptprop[Point_X].Add(fn.Env, x1);
        nptprop[Point_X].Add(fn.Env, x2);
        x1 = Value(Number(m.Shy()));
        x1.Mul(fn.Env, ptprop[Point_X]);
        x2 = Value(Number(m.Sy()));
        x2.Mul(fn.Env, ptprop[Point_Y]);
        nptprop[Point_Y] = Value(Number(m.Ty()));
        nptprop[Point_Y].Add(fn.Env, x1);
        nptprop[Point_Y].Add(fn.Env, x2);
        ppt->SetProperties_Call(fn.Env->GetSC(), nptprop);
        fn.Result->SetAsObject(ppt.GetPtr());
    }
}

// @0x1428ef010
MS2_AS2_NOGS void MatrixProto::Translate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Matrix);
    MatrixObject* pthis = (MatrixObject*)fn.ThisPtr;
    if (!pthis)
        return;
    if (fn.NArgs > 1)
    {
        float            tx = (float)fn.Arg(0).ToNumber(fn.Env);
        float            ty = (float)fn.Arg(1).ToNumber(fn.Env);
        Render::Matrix2F m(pthis->GetMatrix(fn.Env));
        Matrix2F_AppendTranslation(m, tx, ty);
        pthis->SetMatrix(fn.Env, m);
    }
}

// ---- ColorTransform ----

// this = argument transform applied first, then this one. Plain objects are read through their members.
// @0x1428ef180
void ColorTransformProto::Concat(const FnCall& fn)
{
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p != 0)
        {
            MS2_AS2_CHECK_THIS(fn, ColorTransform);
            ColorTransformObject* pthis = (ColorTransformObject*)fn.ThisPtr;
            if (p->GetObjectType() == ObjectInterface::Object_ColorTransform)
            {
                ColorTransformObject* pparam = (ColorTransformObject*)p;
                pthis->mColorTransform.Prepend(pparam->mColorTransform);
            }
            else
            {
                Value c[GFxColorTransform_NumProperties];
                GFxObject_GetColorTransformProperties(fn.Env, p, c);
                Render::Cxform ct;
                ct.M[0][0] = (float)c[GFxColorTransform_RedMultiplier].ToNumber(fn.Env);
                ct.M[0][1] = (float)c[GFxColorTransform_GreenMultiplier].ToNumber(fn.Env);
                ct.M[0][2] = (float)c[GFxColorTransform_BlueMultiplier].ToNumber(fn.Env);
                ct.M[0][3] = (float)c[GFxColorTransform_AlphaMultiplier].ToNumber(fn.Env);
                ct.M[1][0] = (float)c[GFxColorTransform_RedOffset].ToNumber(fn.Env);
                ct.M[1][1] = (float)c[GFxColorTransform_GreenOffset].ToNumber(fn.Env);
                ct.M[1][2] = (float)c[GFxColorTransform_BlueOffset].ToNumber(fn.Env);
                ct.M[1][3] = (float)c[GFxColorTransform_AlphaOffset].ToNumber(fn.Env);
                pthis->mColorTransform.Prepend(ct);
            }
        }
    }
}

// "(redMultiplier=.., ..., alphaOffset=..)" with six significant digits.
// @0x1428ef400
void ColorTransformProto::ToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, ColorTransform);
    ColorTransformObject*  pthis = (ColorTransformObject*)fn.ThisPtr;
    const Render::Cxform& ct    = pthis->mColorTransform;

    ASString ps[8] = {Value(Number(ct.M[0][0])).ToString(fn.Env, 6), Value(Number(ct.M[0][1])).ToString(fn.Env, 6),
                      Value(Number(ct.M[0][2])).ToString(fn.Env, 6), Value(Number(ct.M[0][3])).ToString(fn.Env, 6),
                      Value(Number(ct.M[1][0])).ToString(fn.Env, 6), Value(Number(ct.M[1][1])).ToString(fn.Env, 6),
                      Value(Number(ct.M[1][2])).ToString(fn.Env, 6), Value(Number(ct.M[1][3])).ToString(fn.Env, 6)};

    StringBuffer str;
    str.AppendString("(redMultiplier=");
    str.AppendString(ps[0].ToCStr());
    str.AppendString(", greenMultiplier=");
    str.AppendString(ps[1].ToCStr());
    str.AppendString(", blueMultiplier=");
    str.AppendString(ps[2].ToCStr());
    str.AppendString(", alphaMultiplier=");
    str.AppendString(ps[3].ToCStr());
    str.AppendString(", redOffset=");
    str.AppendString(ps[4].ToCStr());
    str.AppendString(", greenOffset=");
    str.AppendString(ps[5].ToCStr());
    str.AppendString(", blueOffset=");
    str.AppendString(ps[6].ToCStr());
    str.AppendString(", alphaOffset=");
    str.AppendString(ps[7].ToCStr());
    str.AppendString(")");

    fn.Result->SetString(fn.Env->GetSC()->CreateString(str.ToCStr(), str.GetSize()));
}

// ---- Rectangle ----

// @0x1428ef8d0
void RectangleProto::Clone(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    RectangleObject*     pthis = (RectangleObject*)fn.ThisPtr;
    Ptr<RectangleObject> pr    = *SF_HEAP_NEW(fn.Env->GetHeap()) RectangleObject(fn.Env);
    Value                params[Rectangle_NumProperties];
    pthis->GetProperties(fn.Env->GetSC(), params);
    pr.GetPtr()->SetProperties(fn.Env->GetSC(), params);
    fn.Result->SetAsObject(pr.GetPtr());
}

// Whether (x, y) lies inside; the right and bottom edges are open, as in the Flash player.
// @0x1428efa40
void RectangleProto::Contains(const FnCall& fn)
{
    if (fn.NArgs > 1)
    {
        Value px = fn.Arg(0);
        Value py = fn.Arg(1);
        MS2_AS2_CHECK_THIS(fn, Rectangle);
        RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
        ASRect           r;
        pthis->GetProperties(fn.Env, r);
        Number x = px.ToNumber(fn.Env);
        Number y = py.ToNumber(fn.Env);
        if (NumberUtil::IsNaN(x) || NumberUtil::IsNaN(y))
        {
            fn.Result->SetBool(false);
            return;
        }
        if (x == r.x2)
            x += 1.0;
        if (y == r.y2)
            y += 1.0;
        fn.Result->SetBool(r.Contains(x, y));
    }
    else
    {
        fn.Result->SetBool(false);
    }
}

// Like Contains with a point; undefined when the argument is neither a Point nor has x and y.
// @0x1428efc90
void RectangleProto::ContainsPoint(const FnCall& fn)
{
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p)
        {
            MS2_AS2_CHECK_THIS(fn, Rectangle);
            RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
            ASRect           r;
            Value            ptv[Point_NumProperties];
            pthis->GetProperties(fn.Env, r);
            GFxObject_GetPointProperties(fn.Env, p, ptv);
            if (p->GetObjectType() != ObjectInterface::Object_Point &&
                (ptv[Point_X].IsUndefined() || ptv[Point_Y].IsUndefined()))
                return;
            GASPoint pt(GASPoint::NoInit);
            ((PointObject*)p)->GetProperties(fn.Env, pt);
            Number x = pt.x, y = pt.y;
            if (NumberUtil_IsNaN(x) || NumberUtil_IsNaN(y))
            {
                fn.Result->SetBool(false);
                return;
            }
            if (x == r.x2)
                x += 1.0;
            if (y == r.y2)
                y += 1.0;
            fn.Result->SetBool(r.Contains(x, y));
        }
    }
}

// @0x1428eff60
void RectangleProto::ContainsRectangle(const FnCall& fn)
{
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p)
        {
            MS2_AS2_CHECK_THIS(fn, Rectangle);
            RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
            ASRect           r1;
            Value            r2v[Rectangle_NumProperties];
            pthis->GetProperties(fn.Env, r1);
            GFxObject_GetRectangleProperties(fn.Env, p, r2v);
            if (r2v[Rectangle_X].IsUndefined() || r2v[Rectangle_Y].IsUndefined() ||
                r2v[Rectangle_Width].IsUndefined() || r2v[Rectangle_Height].IsUndefined())
                return;
            ASRect r2(r2v[Rectangle_X].ToNumber(fn.Env), r2v[Rectangle_Y].ToNumber(fn.Env),
                      Render::Size<Number>(r2v[Rectangle_Width].ToNumber(fn.Env), r2v[Rectangle_Height].ToNumber(fn.Env)));
            fn.Result->SetBool(r1.Contains(r2));
        }
    }
}

// @0x1428f0220
void RectangleProto::Equals(const FnCall& fn)
{
    bool ret = false;
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p && p->GetObjectType() == ObjectInterface::Object_Rectangle)
        {
            MS2_AS2_CHECK_THIS(fn, Rectangle);
            RectangleObject*     pthis = (RectangleObject*)fn.ThisPtr;
            Ptr<RectangleObject> pr    = (RectangleObject*)p;
            ASRect               r1, r2;
            pthis->GetProperties(fn.Env, r1);
            pr->GetProperties(fn.Env, r2);
            // Edge order x1, x2, y1, y2 (the shared Rect::operator== compares y1 second).
            if (IsRectValid(r1) && IsRectValid(r2))
                ret = (r1.x1 == r2.x1 && r1.x2 == r2.x2 && r1.y1 == r2.y1 && r1.y2 == r2.y2);
        }
    }
    fn.Result->SetBool(ret);
}

// Grows every edge outward by (dx, dy).
// @0x1428f03e0
void RectangleProto::Inflate(const FnCall& fn)
{
    Value dw, dh;
    if (fn.NArgs > 0)
    {
        dw = fn.Arg(0);
        if (fn.NArgs > 1)
            dh = fn.Arg(1);
    }
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
    ASRect           r;
    pthis->GetProperties(fn.Env, r);
    r.Expand(dw.ToNumber(fn.Env), dh.ToNumber(fn.Env));
    pthis->SetProperties(fn.Env, r);
}

// @0x1428f05f0
void RectangleProto::InflatePoint(const FnCall& fn)
{
    if (fn.NArgs > 0)
    {
        MS2_AS2_CHECK_THIS(fn, Rectangle);
        RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
        Object*          p     = fn.Arg(0).ToObject(fn.Env);
        if (!p)
        {
            pthis->SetProperties(fn.Env->GetSC(), Rectangle_NaNParams);
            return;
        }
        ASRect   r;
        GASPoint pt(GASPoint::NoInit);
        pthis->GetProperties(fn.Env, r);
        GFxObject_GetPointProperties(fn.Env, p, pt);
        r.Expand(pt.x, pt.y);
        pthis->SetProperties(fn.Env, r);
    }
}

// New rectangle of the overlap; all zero when there is none or it has no area.
// @0x1428f0760
// MS2-FUNCTIONAL the exe keeps the argument rect in registers across IsRectValid (unity build: it sees the body)
void RectangleProto::Intersection(const FnCall& fn)
{
    ASRect ret(0, 0, 0, 0);
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p)
        {
            ASRect r1;
            Value  r2v[Rectangle_NumProperties];
            pthis->GetProperties(fn.Env, r1);
            GFxObject_GetRectangleProperties(fn.Env, p, r2v);
            ASRect r2(r2v[Rectangle_X].ToNumber(fn.Env), r2v[Rectangle_Y].ToNumber(fn.Env),
                      Render::Size<Number>(r2v[Rectangle_Width].ToNumber(fn.Env), r2v[Rectangle_Height].ToNumber(fn.Env)));
            if (!IsRectValid(r2))
            {
                ret.SetRect(0, 0, 0, 0);
            }
            else
            {
                r1.IntersectRect(&ret, r2);
                if (!IsRectValid(ret) || ret.Width() == 0 || ret.Height() == 0)
                    ret.SetRect(0, 0, 0, 0);
            }
        }
    }
    Ptr<RectangleObject> pr = *SF_HEAP_NEW(fn.Env->GetHeap()) RectangleObject(fn.Env);
    pr.GetPtr()->SetProperties(fn.Env, ret);
    fn.Result->SetAsObject(pr.GetPtr());
}

// @0x1428f0b20
// MS2-FUNCTIONAL the exe keeps the argument rect in registers across IsRectValid (unity build: it sees the body)
void RectangleProto::Intersects(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    bool             ret   = false;
    RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p)
        {
            ASRect r1;
            Value  r2v[Rectangle_NumProperties];
            pthis->GetProperties(fn.Env, r1);
            GFxObject_GetRectangleProperties(fn.Env, p, r2v);
            ASRect r2(r2v[Rectangle_X].ToNumber(fn.Env), r2v[Rectangle_Y].ToNumber(fn.Env),
                      Render::Size<Number>(r2v[Rectangle_Width].ToNumber(fn.Env), r2v[Rectangle_Height].ToNumber(fn.Env)));
            ASRect r(0, 0, 0, 0);
            if (!IsRectValid(r1) || !IsRectValid(r2))
            {
                ret = false;
            }
            else
            {
                r1.IntersectRect(&r, r2);
                ret = true;
                if (!IsRectValid(r) || r.Width() == 0 || r.Height() == 0)
                    ret = false;
            }
        }
    }
    fn.Result->SetBool(ret);
}

// True when width or height is NaN or zero.
// @0x1428f0e60
void RectangleProto::IsEmpty(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    bool             ret   = false;
    RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
    Value            params[Rectangle_NumProperties];
    pthis->GetProperties(fn.Env->GetSC(), params);
    if (NumberUtil::IsNaN(params[Rectangle_Width].ToNumber(fn.Env)) ||
        NumberUtil::IsNaN(params[Rectangle_Height].ToNumber(fn.Env)))
    {
        ret = true;
    }
    else
    {
        // The exe reads x and y as well but builds the rect from the size alone (origin 0, 0).
        params[Rectangle_X].ToNumber(fn.Env);
        params[Rectangle_Y].ToNumber(fn.Env);
        ASRect r(Render::Size<Number>(params[Rectangle_Width].ToNumber(fn.Env), params[Rectangle_Height].ToNumber(fn.Env)));
        // No area: edges crossed or touching (the shared Rect::IsEmpty only tests equality).
        ret = r.x1 >= r.x2 || r.y1 >= r.y2;
    }
    fn.Result->SetBool(ret);
}

// Moves x and y; width and height stay.
// MS2-FUNCTIONAL the exe keeps dy's type byte in a register and sets the temp's type before the ToNumber calls
// (unity-build alias knowledge)
// @0x1428f1040
void RectangleProto::Offset(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    Value dx, dy;
    if (fn.NArgs > 0)
    {
        dx = fn.Arg(0);
        if (fn.NArgs > 1)
            dy = fn.Arg(1);
    }
    RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
    Value            params[Rectangle_NumProperties];
    pthis->GetProperties(fn.Env->GetSC(), params);
    params[Rectangle_X] = params[Rectangle_X].ToNumber(fn.Env) + dx.ToNumber(fn.Env);
    params[Rectangle_Y] = params[Rectangle_Y].ToNumber(fn.Env) + dy.ToNumber(fn.Env);
    pthis->SetProperties(fn.Env->GetSC(), params);
}

// Offset by a point; x and y become NaN when the argument is not point-like.
// @0x1428f12e0
void RectangleProto::OffsetPoint(const FnCall& fn)
{
    if (fn.NArgs > 0)
    {
        MS2_AS2_CHECK_THIS(fn, Rectangle);
        RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
        Object*          p     = fn.Arg(0).ToObject(fn.Env);
        Value            params[Rectangle_NumProperties];
        if (!p)
        {
            pthis->GetProperties(fn.Env->GetSC(), params);
            params[Rectangle_X] = NumberUtil::NaN();
            params[Rectangle_Y] = NumberUtil::NaN();
            pthis->SetProperties(fn.Env->GetSC(), params);
            return;
        }
        Value ptv[Point_NumProperties];
        GFxObject_GetPointProperties(fn.Env, p, ptv);
        if (p->GetObjectType() != ObjectInterface::Object_Point &&
            (ptv[Point_X].IsUndefined() || ptv[Point_Y].IsUndefined()))
        {
            pthis->GetProperties(fn.Env->GetSC(), params);
            params[Rectangle_X] = NumberUtil::NaN();
            params[Rectangle_Y] = NumberUtil::NaN();
            pthis->SetProperties(fn.Env->GetSC(), params);
            return;
        }
        pthis->GetProperties(fn.Env->GetSC(), params);
        params[Rectangle_X] = params[Rectangle_X].ToNumber(fn.Env) + ptv[Point_X].ToNumber(fn.Env);
        params[Rectangle_Y] = params[Rectangle_Y].ToNumber(fn.Env) + ptv[Point_Y].ToNumber(fn.Env);
        pthis->SetProperties(fn.Env->GetSC(), params);
    }
}

// @0x1428f1710
void RectangleProto::SetEmpty(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
    pthis->SetProperties(fn.Env, ASRect(0, 0, 0, 0));
}

// "(x=.., y=.., width=.., height=..)" with six significant digits.
// @0x1428f1780
// MS2-FUNCTIONAL fn and the -1 length swap rsi/rdi and the string manager is loaded before str (register allocation)
void RectangleProto::ToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    RectangleObject* pthis = (RectangleObject*)fn.ThisPtr;
    if (!pthis)
        return;
    Value params[Rectangle_NumProperties];
    pthis->GetProperties(fn.Env->GetSC(), params);
    ASString ps[4] = {params[Rectangle_X].ToString(fn.Env, 6), params[Rectangle_Y].ToString(fn.Env, 6),
                      params[Rectangle_Width].ToString(fn.Env, 6), params[Rectangle_Height].ToString(fn.Env, 6)};
    String   str;
    str += "(x=";
    str += ps[0].ToCStr();
    str += ", y=";
    str += ps[1].ToCStr();
    str += ", width=";
    str += ps[2].ToCStr();
    str += ", height=";
    str += ps[3].ToCStr();
    str += ")";
    fn.Result->SetString(fn.Env->GetSC()->CreateString(str.ToCStr(), str.GetSize()));
}

// New rectangle enclosing both (NaN edges count as 0); NaN without an argument.
// @0x1428f1a60
void RectangleProto::Union(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Rectangle);
    RectangleObject*     pthis = (RectangleObject*)fn.ThisPtr;
    Ptr<RectangleObject> pr    = *SF_HEAP_NEW(fn.Env->GetHeap()) RectangleObject(fn.Env);
    fn.Result->SetAsObject(pr.GetPtr());
    if (fn.NArgs > 0)
    {
        ASRect  ret(NumberUtil::NaN(), NumberUtil::NaN(), NumberUtil::NaN(), NumberUtil::NaN());
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p)
        {
            ASRect r1;
            Value  r2v[Rectangle_NumProperties];
            pthis->GetProperties(fn.Env, r1);
            GFxObject_GetRectangleProperties(fn.Env, p, r2v);
            ASRect r2(r2v[Rectangle_X].ToNumber(fn.Env), r2v[Rectangle_Y].ToNumber(fn.Env),
                      Render::Size<Number>(r2v[Rectangle_Width].ToNumber(fn.Env), r2v[Rectangle_Height].ToNumber(fn.Env)));
            ValidateRect(&r1);
            ValidateRect(&r2);
            r1.UnionRect(&ret, r2);
            if (NumberUtil::IsNaN(r2v[Rectangle_X].ToNumber(fn.Env)))
                ret.x1 = NumberUtil::NaN();
            if (NumberUtil::IsNaN(r2v[Rectangle_Y].ToNumber(fn.Env)))
                ret.y1 = NumberUtil::NaN();
        }
        pr.GetPtr()->SetProperties(fn.Env, ret);
    }
    else
    {
        pr.GetPtr()->SetProperties(fn.Env->GetSC(), Rectangle_NaNParams);
    }
}

// ---- Point ----

// Sum of this and another point (any object with x and y); NaN, NaN without an argument.
// @0x1428f2040
void PointProto::Add(const FnCall& fn)
{
    Ptr<PointObject> retpt = *SF_HEAP_NEW(fn.Env->GetHeap()) PointObject(fn.Env);
    bool             set   = false;
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p)
        {
            MS2_AS2_CHECK_THIS(fn, Point);
            PointObject* pthis = (PointObject*)fn.ThisPtr;
            GASPoint     pt1(GASPoint::NoInit), pt2(GASPoint::NoInit);
            pthis->GetProperties(fn.Env, pt1);
            GFxObject_GetPointProperties(fn.Env, p, pt2);
            pt1.x += pt2.x;
            pt1.y += pt2.y;
            retpt->SetProperties(fn.Env, pt1);
            set = true;
        }
    }
    if (!set)
        retpt->SetProperties(fn.Env->GetSC(), Point_NanParams);
    fn.Result->SetAsObject(retpt.GetPtr());
}

// @0x1428f2250
void PointProto::Clone(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Point);
    PointObject*     pthis = (PointObject*)fn.ThisPtr;
    Ptr<PointObject> ppt   = *SF_HEAP_NEW(fn.Env->GetHeap()) PointObject(fn.Env);
    ASStringContext* psc   = fn.Env->GetSC();
    Value            params[Point_NumProperties];
    pthis->GetProperties(psc, params);
    ppt.GetPtr()->SetProperties(psc, params);
    fn.Result->SetAsObject(ppt.GetPtr());
}

// @0x1428f2430
void PointProto::Equals(const FnCall& fn)
{
    bool ret = false;
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p && p->GetObjectType() == ObjectInterface::Object_Point)
        {
            MS2_AS2_CHECK_THIS(fn, Point);
            PointObject* pthis = (PointObject*)fn.ThisPtr;
            GASPoint     pt1(GASPoint::NoInit), pt2(GASPoint::NoInit);
            pthis->GetProperties(fn.Env, pt1);
            GFxObject_GetPointProperties(fn.Env, p, pt2);
            ret = (pt1 == pt2);
        }
    }
    fn.Result->SetBool(ret);
}

// Scales this point to the given length.
// @0x1428f2570
void PointProto::Normalize(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Point);
    PointObject* pthis = (PointObject*)fn.ThisPtr;
    if (fn.NArgs > 0)
    {
        Value    p = fn.Arg(0);
        GASPoint pt1(GASPoint::NoInit);
        pthis->GetProperties(fn.Env, pt1);
        Number m = p.ToNumber(fn.Env) / sqrt(pt1.x * pt1.x + pt1.y * pt1.y);
        pt1.x *= m;
        pt1.y *= m;
        pthis->SetProperties(fn.Env, pt1);
    }
    else
    {
        pthis->SetProperties(fn.Env->GetSC(), Point_NanParams);
    }
}

// @0x1428f2790
// MS2-FUNCTIONAL the exe keeps dy's type byte in a register across the calls (unity-build alias knowledge)
void PointProto::Offset(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Point);
    PointObject* pthis = (PointObject*)fn.ThisPtr;
    Value        dx, dy;
    if (fn.NArgs > 0)
    {
        dx = fn.Arg(0);
        if (fn.NArgs > 1)
            dy = fn.Arg(1);
    }
    GASPoint pt1(GASPoint::NoInit);
    pthis->GetProperties(fn.Env, pt1);
    Number offy = dy.ToNumber(fn.Env); // Point::Offset(dx, dy) arguments, evaluated right to left
    Number offx = dx.ToNumber(fn.Env);
    pt1.x += offx;
    pt1.y += offy;
    pthis->SetProperties(fn.Env, pt1);
}

// @0x1428f2970
void PointProto::Subtract(const FnCall& fn)
{
    Ptr<PointObject> retpt = *SF_HEAP_NEW(fn.Env->GetHeap()) PointObject(fn.Env);
    bool             set   = false;
    if (fn.NArgs > 0)
    {
        Object* p = fn.Arg(0).ToObject(fn.Env);
        if (p)
        {
            MS2_AS2_CHECK_THIS(fn, Point);
            PointObject* pthis = (PointObject*)fn.ThisPtr;
            GASPoint     pt1(GASPoint::NoInit), pt2(GASPoint::NoInit);
            pthis->GetProperties(fn.Env, pt1);
            GFxObject_GetPointProperties(fn.Env, p, pt2);
            pt1.x -= pt2.x;
            pt1.y -= pt2.y;
            retpt->SetProperties(fn.Env, pt1);
            set = true;
        }
    }
    if (!set)
        retpt->SetProperties(fn.Env->GetSC(), Point_NanParams);
    fn.Result->SetAsObject(retpt.GetPtr());
}

// "(x=.., y=..)" with six significant digits.
// @0x1428f2b90
void PointProto::ToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Point);
    PointObject* pthis = (PointObject*)fn.ThisPtr;
    if (!pthis)
        return;
    Value params[Point_NumProperties];
    pthis->GetProperties(fn.Env->GetSC(), params);
    ASString ps[2] = {params[Point_X].ToString(fn.Env, 6), params[Point_Y].ToString(fn.Env, 6)};
    String   str;
    str += "(x=";
    str += ps[Point_X].ToCStr();
    str += ", y=";
    str += ps[Point_Y].ToCStr();
    str += ")";
    fn.Result->SetString(fn.Env->GetSC()->CreateString(str.ToCStr(), str.GetSize()));
}

// Distance between two points; undefined when neither argument is a Point.
// @0x1428f2e40
// MS2-FUNCTIONAL the exe keeps both Sub operands live across the temp release and saves xmm7 (unity-build register allocation)
void PointCtorFunction::Distance(const FnCall& fn)
{
    fn.Result->SetNumber(NumberUtil::NaN());
    if (fn.NArgs > 1)
    {
        Object* p1 = fn.Arg(0).ToObject(fn.Env);
        Object* p2 = fn.Arg(1).ToObject(fn.Env);
        if (p1 && p2)
        {
            if (p1->GetObjectType() != ObjectInterface::Object_Point &&
                p2->GetObjectType() != ObjectInterface::Object_Point)
            {
                fn.Result->SetUndefined();
            }
            else
            {
                Value o1[Point_NumProperties], o2[Point_NumProperties];
                GFxObject_GetPointProperties(fn.Env, p1, o1);
                GFxObject_GetPointProperties(fn.Env, p2, o2);
                Value xd = o2[Point_X];
                xd.Sub(fn.Env, o1[Point_X]);
                xd.Mul(fn.Env, xd);
                Value yd = o2[Point_Y];
                yd.Sub(fn.Env, o1[Point_Y]);
                yd.Mul(fn.Env, yd);
                xd.Add(fn.Env, yd);
                Number d = Value(Number(sqrt(xd.ToNumber(fn.Env)))).ToNumber(fn.Env);
                fn.Result->SetNumber(d);
            }
        }
    }
}

// The point at the given length and angle (radians) from the origin.
// @0x1428f3530
void PointCtorFunction::Polar(const FnCall& fn)
{
    Ptr<PointObject> ppt = *SF_HEAP_NEW(fn.Env->GetHeap()) PointObject(fn.Env);
    bool             set = false;
    if (fn.NArgs > 1)
    {
        Value  length = fn.Arg(0);
        Value  angle  = fn.Arg(1);
        Number l      = length.ToNumber(fn.Env);
        Number a      = angle.ToNumber(fn.Env);
        Double sa     = sin(a);
        Double ca     = cos(a);
        ppt->SetProperties(fn.Env, GASPoint(l * ca, l * sa));
        set = true;
    }
    if (!set)
        ppt->SetProperties(fn.Env->GetSC(), Point_NanParams);
    fn.Result->SetAsObject(ppt.GetPtr());
}

// The point f of the way from the second point to the first.
// @0x1428f3240
void PointCtorFunction::Interpolate(const FnCall& fn)
{
    Ptr<PointObject> ppt = *SF_HEAP_NEW(fn.Env->GetHeap()) PointObject(fn.Env);
    bool             set = false;
    if (fn.NArgs > 2)
    {
        Object* p1 = fn.Arg(0).ToObject(fn.Env);
        Object* p2 = fn.Arg(1).ToObject(fn.Env);
        Value   f  = fn.Arg(2);
        if (p1 && p2)
        {
            GASPoint pt1(GASPoint::NoInit), pt2(GASPoint::NoInit);
            GFxObject_GetPointProperties(fn.Env, p1, pt1);
            GFxObject_GetPointProperties(fn.Env, p2, pt2);
            Number   ptf = f.ToNumber(fn.Env);
            GASPoint ip((pt1.x - pt2.x) * ptf + pt2.x, (pt1.y - pt2.y) * ptf + pt2.y);
            ppt->SetProperties(fn.Env, ip);
            set = true;
        }
    }
    if (!set)
        ppt->SetProperties(fn.Env->GetSC(), Point_NanParams);
    fn.Result->SetAsObject(ppt.GetPtr());
}

// The character at an index as a one character string; "" when out of range.
// @0x1428f37a0
void StringProto::StringCharAt(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    const ASString& str    = ((StringObject*)fn.ThisPtr)->sValue;
    ASString        result = fn.Env->GetSC()->GetBuiltin(ASBuiltin_empty_);
    int             index  = (int)fn.Arg(0).ToNumber(fn.Env);
    if (index >= 0 && index < (int)str.GetLength())
        result = ASString(result.AppendCharNode(str.GetCharAt(index)));
    fn.Result->SetString(result);
}

// The character code at an index; NaN when out of range or without an argument.
// @0x1428f3910
void StringProto::StringCharCodeAt(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    const ASString& str = ((StringObject*)fn.ThisPtr)->sValue;
    if (fn.NArgs >= 1)
    {
        int index = (int)fn.Arg(0).ToNumber(fn.Env);
        if (index >= 0 && index < (int)str.GetLength())
        {
            fn.Result->SetNumber(Number(str.GetCharAt(index)));
            return;
        }
    }
    fn.Result->SetNumber(NumberUtil::NaN());
}

// The string followed by every argument converted to a string.
// @0x1428f3a40
void StringProto::StringConcat(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    StringBuffer  buf(pthis->sValue.ToCStr(), pthis->sValue.GetSize(), Memory::pGlobalHeap);
    for (int i = 0; i < fn.NArgs; i++)
    {
        ASString arg = fn.Arg(i).ToString(fn.Env);
        buf.AppendString(arg.ToCStr());
    }
    fn.Result->SetString(fn.Env->GetSC()->CreateString(buf.ToCStr(), buf.GetSize()));
}

// indexOf(text, start): character index of the first match at or after start, -1 when there is none.
// @0x1428f3be0
void StringProto::StringIndexOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
    {
        fn.Result->SetNumber(-1);
        return;
    }
    ASString text = fn.Arg(0).ToString(fn.Env);
    if (text.GetLength() == 0)
    {
        fn.Result->SetNumber(0);
        return;
    }
    const char* ptext = text.ToCStr();
    const char* pstr  = pthis->sValue.ToCStr();
    int         start = 0;
    if (fn.NArgs > 1)
        start = (int)fn.Arg(1).ToNumber(fn.Env);
    UInt32 first = UTF8Util::DecodeNextChar(&ptext);
    for (int i = 0;; i++)
    {
        UInt32 c = UTF8Util::DecodeNextChar(&pstr);
        if (c == 0)
        {
            fn.Result->SetNumber(-1);
            return;
        }
        if (i >= start && c == first)
        {
            const char* p = pstr;
            const char* q = ptext;
            UInt32      a, b;
            do
            {
                a = UTF8Util::DecodeNextChar(&p);
                b = UTF8Util::DecodeNextChar(&q);
            } while (a && b && a == b);
            if (b == 0)
            {
                Value* presult = fn.Result;
                if (presult->T.Type >= Value::STRING)
                    presult->DropRefs();
                presult->T.Type        = Value::INTEGER;
                presult->NV.Int32Value = i;
                return;
            }
            if (a == 0)
            {
                Value* presult = fn.Result;
                if (presult->T.Type >= Value::STRING)
                    presult->DropRefs();
                presult->T.Type        = Value::INTEGER;
                presult->NV.Int32Value = -1;
                return;
            }
        }
    }
}

// lastIndexOf(text, start): character index of the last match at or before start, -1 when there is none.
// @0x1428f3e70
void StringProto::StringLastIndexOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
    {
        fn.Result->SetNumber(-1);
        return;
    }
    ASString str  = pthis->sValue;
    ASString text = fn.Arg(0).ToString(fn.Env);
    if (text.GetLength() == 0)
    {
        fn.Result->SetNumber(str.GetLength());
        return;
    }
    const char* pstr  = str.ToCStr();
    const char* ptext = text.ToCStr();
    int         start = 0x7ffffff;
    if (fn.NArgs > 1)
        start = (int)fn.Arg(1).ToNumber(fn.Env);
    int    last  = -1;
    UInt32 first = UTF8Util::DecodeNextChar(&ptext);
    for (int i = 0;; i++)
    {
        UInt32 c = UTF8Util::DecodeNextChar(&pstr);
        if (c == 0)
            break;
        if (i <= start && c == first)
        {
            const char* p = pstr;
            const char* q = ptext;
            UInt32      a, b;
            do
            {
                a = UTF8Util::DecodeNextChar(&p);
                b = UTF8Util::DecodeNextChar(&q);
            } while (a && b && a == b);
            if (b == 0)
                last = i;
            if (a == 0)
                break;
        }
    }
    fn.Result->SetInt(last);
}

// split(delimiter, limit): the pieces as an Array.
// @0x1428f4420
void StringProto::StringSplit(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    ASString      search(fn.Env->GetSC()->GetBuiltin(ASBuiltin_empty_));
    const char*   psearch = 0;
    if (fn.NArgs >= 1)
    {
        search  = fn.Arg(0).ToString(fn.Env);
        psearch = search.ToCStr();
    }
    int limit = 0x3fffffff;
    if (fn.NArgs >= 2)
    {
        limit = (int)fn.Arg(1).ToNumber(fn.Env);
        if (limit < 0)
            limit = 0;
    }
    Ptr<ArrayObject> parr = StringSplit(fn.Env, pthis->sValue, psearch, limit);
    fn.Result->SetAsObject(parr.GetPtr());
}

// localeCompare(text, ignoreCase): a Scaleform extension, undefined unless the movie enabled them.
// @0x1428f40d0
void StringProto::StringLocaleCompare(const FnCall& fn)
{
    fn.Result->SetUndefined();
    if (!fn.Env->CheckExtensions())
        return;
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    ASString text          = fn.Arg(0).ToString(fn.Env);
    bool     caseSensitive = true;
    if (fn.NArgs >= 2)
        caseSensitive = !fn.Arg(1).ToBool(fn.Env);
    fn.Result->SetNumber(
        Number(pthis->sValue.LocaleCompare_CaseCheck(text.ToCStr(), text.GetLength(), caseSensitive)));
}

// slice(start, end): negative bounds count from the end; "" when end comes before start.
// @0x1428f4240
void StringProto::StringSlice(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis  = (StringObject*)fn.ThisPtr;
    int           start  = 0;
    int           length = -1;
    if (fn.NArgs >= 1)
    {
        start = (int)fn.Arg(0).ToNumber(fn.Env);
        if (start < 0)
            start += pthis->sValue.GetLength();
    }
    if (fn.NArgs >= 2)
    {
        int end = (int)fn.Arg(1).ToNumber(fn.Env);
        if (end < 0)
            end += pthis->sValue.GetLength();
        if (end < start)
        {
            fn.Result->SetString(fn.Env->GetSC()->GetBuiltin(ASBuiltin_empty_));
            return;
        }
        length = end - start;
    }
    fn.Result->SetString(StringSubstring(pthis->sValue, start, length));
}

// substr(start, length): a negative start counts from the end, a negative length gives "".
// @0x1428f4610
void StringProto::StringSubstr(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    int start  = 0;
    int length = -1;
    if (fn.NArgs >= 1)
    {
        start = (int)fn.Arg(0).ToNumber(fn.Env);
        if (start < 0)
            start += pthis->sValue.GetLength();
    }
    if (fn.NArgs >= 2)
    {
        length = (int)fn.Arg(1).ToNumber(fn.Env);
        if (length < 0)
            length = 0;
    }
    fn.Result->SetString(StringSubstring(pthis->sValue, start, length));
}

// substring(start, end): the bounds are swapped when end < start, negative ones count as 0.
// @0x1428f47b0
void StringProto::StringSubstring(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    int start  = 0;
    int length = -1;
    if (fn.NArgs >= 1)
        start = (int)fn.Arg(0).ToNumber(fn.Env);
    if (fn.NArgs >= 2)
    {
        int end = (int)fn.Arg(1).ToNumber(fn.Env);
        if (end < start)
        {
            if (start >= (int)pthis->sValue.GetLength())
            {
                fn.Result->SetString(fn.Env->GetSC()->GetBuiltin(ASBuiltin_empty_));
                return;
            }
            int t = start;
            start = end;
            end   = t;
        }
        if (start < 0)
            start = 0;
        length = end - start;
    }
    fn.Result->SetString(StringSubstring(pthis->sValue, start, length));
}

// @0x1428f4980
void StringProto::StringToLowerCase(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    ASString      result(pthis->sValue.ToLowerNode());
    fn.Result->SetString(result);
}

// @0x1428f4a20
void StringProto::StringToString(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    fn.Result->SetString(pthis->sValue);
}

// @0x1428f4aa0
void StringProto::StringToUpperCase(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    ASString      result(pthis->sValue.ToUpperNode());
    fn.Result->SetString(result);
}

// @0x1428f4b40
void StringProto::StringValueOf(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, String);
    StringObject* pthis = (StringObject*)fn.ThisPtr;
    fn.Result->SetString(pthis->sValue);
}

// String.fromCharCode(c0, c1, ...).
// @0x1428f4bc0
void StringCtorFunction::StringFromCharCode(const FnCall& fn)
{
    StringBuffer buf(Memory::pGlobalHeap);
    for (int i = 0; i < fn.NArgs; i++)
        buf.AppendChar((UInt32)fn.Arg(i).ToNumber(fn.Env));
    fn.Result->SetString(fn.Env->GetSC()->CreateString(buf.ToCStr(), buf.GetSize()));
}

// Placeholder natives of classes whose methods are not supported: they return undefined.
// @0x1428ef8b0
void GFx_KeyFuncStub(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// @0x1428f1e30
void GFx_BitmapDataFuncStub(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// @0x1428f1e50
void GFx_FuncStub(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// @0x1428f4e40
void GFx_MouseFuncStub(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// Global parseFloat(): NaN when the string does not start with a number.
// @0x1428f73b0
void GAS_GlobalParseFloat(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    ASString    text  = fn.Arg(0).ToString(fn.Env);
    const char* pstr  = text.ToCStr();
    char*       pend  = 0;
    Number      val   = SFstrtod(pstr, &pend);
    if (pend == pstr)
        val = NumberUtil::NaN();
    fn.Result->SetNumber(val);
}

// Global isNaN(); true without an argument.
// @0x1428f7580
void GAS_GlobalIsNaN(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Result->SetBool(true);
        return;
    }
    fn.Result->SetBool(NumberUtil::IsNaN(fn.Arg(0).ToNumber(fn.Env)));
}

// Global isFinite(); false without an argument.
// @0x1428f7650
void GAS_GlobalIsFinite(const FnCall& fn)
{
    if (fn.NArgs < 1)
    {
        fn.Result->SetBool(false);
        return;
    }
    Number val = fn.Arg(0).ToNumber(fn.Env);
    if (NumberUtil::IsNaN(val) || NumberUtil::IsNEGATIVE_INFINITY(val) || NumberUtil::IsPOSITIVE_INFINITY(val))
        fn.Result->SetBool(false);
    else
        fn.Result->SetBool(true);
}

// ASSetPropFlagsVisitor's scalar deleting destructor (vtable slot 0 of GAS_GlobalASSetPropFlags' visitor, no .pdata).
// MS2-FUNCTIONAL: free-function form of the local class's compiler-generated destructor.
// @0x1428f7be0
void* FUN_1428f7be0(void* self, unsigned flags)
{
    ((ObjectInterface::MemberVisitor*)self)->ObjectInterface::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(self, (size_t)0x20);
    return self;
}

// LoadVarsStringVisitor scalar deleting destructor (vtable slot 0, no .pdata), 0x18 bytes.
// MS2-FUNCTIONAL: free-function form of the local class's compiler-generated destructor.
// @0x14292bdc0
void* FUN_14292bdc0(void* self, unsigned flags)
{
    ((ObjectInterface::MemberVisitor*)self)->ObjectInterface::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(self, (size_t)0x18);
    return self;
}

// The global updateAfterEvent() does nothing.
// @0x1428f8530
void FUN_1428f8530(const FnCall&) {}

// The global clearInterval()/clearTimeout() functions.
class IntervalTimer
{
public:
    static void ClearInterval(const FnCall& fn);
    static void ClearTimeout(const FnCall& fn);

private:
    // Defined with the timer object (sfr_as2_07n); setInterval / setTimeout below forward to it.
    static void Set(const FnCall& fn, bool isTimeout);
    friend void FUN_1428fbb70(const FnCall& fn);
    friend void FUN_1428fbc40(const FnCall& fn);
};

// The global setInterval(): an interval timer.
// @0x1428fbb70
void FUN_1428fbb70(const FnCall& fn)
{
    IntervalTimer::Set(fn, false);
}

// The global setTimeout(): a one-shot timer.
// @0x1428fbc40
void FUN_1428fbc40(const FnCall& fn)
{
    IntervalTimer::Set(fn, true);
}

// @0x1428fbb80
void IntervalTimer::ClearInterval(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    MovieImpl* pmovie = ((DisplayObjectBase*)fn.Env->Target)->GetMovieImpl();
    Number     id     = fn.Arg(0).ToNumber(fn.Env);
    if (!NumberUtil::IsNaN(id))
        pmovie->ClearIntervalTimer(int(id));
}

// @0x1428fbc50
void IntervalTimer::ClearTimeout(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    MovieImpl* pmovie = ((DisplayObjectBase*)fn.Env->Target)->GetMovieImpl();
    Number     id     = fn.Arg(0).ToNumber(fn.Env);
    if (!NumberUtil::IsNaN(id))
        pmovie->ClearIntervalTimer(int(id));
}

// Day of the year at which each month ends, for common and leap years.
static const int DateMonthEnds[2][12] = {
    {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};

// @0x1428fc160
void DateProto::DateGetDate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][0])
    {
        fn.Result->SetNumber(Number(pthis->LJDate + 1));
        return;
    }
    for (int m = 1; m < 12; m++)
    {
        if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m])
        {
            fn.Result->SetNumber(Number(pthis->LJDate + 1 - DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m - 1]));
            return;
        }
    }
    fn.Result->SetNumber(-1);
}

// 1 Jan 1970 was a Thursday.
// @0x1428fc350
void DateProto::DateGetDay(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((int(pthis->LDate / 86400000) + 4) % 7));
}

// @0x1428fc410
void DateProto::DateGetFullYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->LYear));
}

// @0x1428fc490
void DateProto::DateGetHours(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->LTime / 3600000));
}

// @0x1428fc520
void DateProto::DateGetMilliseconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->LTime % 1000));
}

// @0x1428fc5c0
void DateProto::DateGetMinutes(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((pthis->LTime % 3600000) / 60000));
}

// @0x1428fc680
void DateProto::DateGetMonth(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    for (int m = 0; m < 12; m++)
    {
        if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m])
        {
            fn.Result->SetNumber(Number(m));
            return;
        }
    }
    fn.Result->SetNumber(-1);
}

// @0x1428fc7e0
void DateProto::DateGetSeconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((pthis->LTime % 60000) / 1000));
}

// @0x1428fc8a0
void DateProto::DateGetTime(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Date));
}

// Minutes UTC is ahead of local time.
// @0x1428fc920
void DateProto::DateGetTimezoneOffset(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(-pthis->LocalOffset / 60000));
}

// @0x1428fc9b0
void DateProto::DateGetYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->LYear - 1900));
}

// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fca40
void DateProto::DateSetDate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int day = (int)fn.Arg(0).ToNumber(fn.Env);
    for (int m = 0; m < 12; m++)
    {
        if (pthis->LJDate < DateMonthEnds[Date_IsLeapYear(pthis->LYear)][m])
        {
            int delta = day - (pthis->LJDate - (m ? DateMonthEnds[IsLeapYear(pthis->LYear)][m - 1] : 0)) - 1;
            pthis->LJDate += delta;
            pthis->LDate += SInt64(delta) * SInt64(86400000);
            pthis->UpdateGMT();
            return;
        }
    }
}

// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fcbf0
void DateProto::DateSetFullYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int year = (int)fn.Arg(0).ToNumber(fn.Env);
    if (pthis->LJDate >= 60)
        pthis->LJDate += IsLeapYear(year) - IsLeapYear(pthis->LYear);
    pthis->LDate = SInt64(pthis->LTime) + SInt64(Date_StartOfYear(year) + pthis->LJDate) * SInt64(86400000);
    pthis->LYear = year;
    pthis->UpdateGMT();
}

// @0x1428fcd60
void DateProto::DateSetHours(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int hours = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta = (hours - pthis->LTime / 3600000) * 3600000;
    pthis->LDate += delta;
    pthis->LTime += delta;
    pthis->UpdateGMT();
}

// @0x1428fce60
void DateProto::DateSetMilliseconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int ms    = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta = ms - pthis->LTime % 1000;
    pthis->LDate += delta;
    pthis->LTime += delta;
    pthis->UpdateGMT();
}

// @0x1428fcf60
void DateProto::DateSetMinutes(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int minutes = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta   = (minutes - (pthis->LTime % 3600000) / 60000) * 60000;
    pthis->LDate += delta;
    pthis->LTime += delta;
    pthis->UpdateGMT();
}

// Keeps the day of the month, clamped to the length of the new month.
// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fd070
void DateProto::DateSetMonth(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int month = (int)fn.Arg(0).ToNumber(fn.Env);
    DateGetDate(fn);
    int day        = (int)fn.Result->ToNumber(fn.Env);
    int oldDay     = pthis->LJDate;
    int monthStart = 0;
    if (month > 0)
        monthStart = DateMonthEnds[IsLeapYear(pthis->LYear)][month - 1];
    int monthLength = DateMonthEnds[IsLeapYear(pthis->LYear)][month] - monthStart;
    if (day > monthLength)
        day = monthLength;
    pthis->LJDate = monthStart + day - 1;
    pthis->LDate += SInt64(pthis->LJDate - oldDay) * SInt64(86400000);
    fn.Result->SetUndefined();
}

// @0x1428fd230
void DateProto::DateSetSeconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int seconds = (int)fn.Arg(0).ToNumber(fn.Env);
    int delta   = (seconds - (pthis->LTime % 60000) / 1000) * 1000;
    pthis->LDate += delta;
    pthis->LTime += delta;
    pthis->UpdateGMT();
}

// @0x1428fd340
void DateProto::DateSetTime(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    pthis->SetDate((SInt64)fn.Arg(0).ToNumber(fn.Env));
}

// Two digit years count from 1900.
// MS2-FUNCTIONAL the exe keeps values in r10/r11 across the IsLeapYear calls (unity build: the callee is compiled
// earlier in the same TU, so its register use is known); a call into another unit has to assume the full ABI.
// @0x1428fd400
void DateProto::DateSetYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (fn.NArgs < 1)
        return;
    int year = (int)fn.Arg(0).ToNumber(fn.Env);
    if (year < 100 && year >= 0)
        year += 1900;
    if (pthis->LJDate >= 60)
        pthis->LJDate += IsLeapYear(year) - IsLeapYear(pthis->LYear);
    pthis->LDate = SInt64(pthis->LTime) + SInt64(Date_StartOfYear(year) + pthis->LJDate) * SInt64(86400000);
    pthis->LYear = year;
    pthis->UpdateGMT();
}

// @0x1428fd580
void DateProto::DateGetUTCDate(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][0])
    {
        fn.Result->SetNumber(Number(pthis->JDate + 1));
        return;
    }
    for (int m = 1; m < 12; m++)
    {
        if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][m])
        {
            fn.Result->SetNumber(Number(pthis->JDate + 1 - DateMonthEnds[Date_IsLeapYear(pthis->Year)][m - 1]));
            return;
        }
    }
    fn.Result->SetNumber(-1);
}

// @0x1428fd770
void DateProto::DateGetUTCDay(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((int(pthis->Date / 86400000) + 4) % 7));
}

// @0x1428fd830
void DateProto::DateGetUTCFullYear(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Year));
}

// @0x1428fd8b0
void DateProto::DateGetUTCHours(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Time / 3600000));
}

// @0x1428fd940
void DateProto::DateGetUTCMilliseconds(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number(pthis->Time % 1000));
}

// @0x1428fd9e0
void DateProto::DateGetUTCMinutes(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    fn.Result->SetNumber(Number((pthis->Time % 3600000) / 60000));
}

// @0x1428fdaa0
void DateProto::DateGetUTCMonth(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Date);
    DateObject* pthis = (DateObject*)fn.ThisPtr;
    for (int m = 0; m < 12; m++)
    {
        if (pthis->JDate < DateMonthEnds[Date_IsLeapYear(pthis->Year)][m])
        {
            fn.Result->SetNumber(Number(m));
            return;
        }
    }
    fn.Result->SetNumber(-1);
}

// ---- Matrix helper ----

// The out-of-line copy of Matrix2x4::SetInverse the Matrix natives call.
// @0x142446cb0
void Matrix2F_SetInverse(Render::Matrix2F* m, const Render::Matrix2F& src)
{
    float det = src.M[0][0] * src.M[1][1] - src.M[0][1] * src.M[1][0];
    if (det == 0)
    {
        m->SetIdentity();
        m->M[0][3] = -src.M[0][3];
        m->M[1][3] = -src.M[1][3];
    }
    else
    {
        float inv = 1 / det;
        m->M[0][0] = src.M[1][1] * inv;
        m->M[1][1] = src.M[0][0] * inv;
        m->M[0][1] = -src.M[0][1] * inv;
        m->M[1][0] = -src.M[1][0] * inv;
        m->M[0][3] = -(m->M[0][0] * src.M[0][3] + m->M[0][1] * src.M[1][3]);
        m->M[1][3] = -(m->M[1][0] * src.M[0][3] + m->M[1][1] * src.M[1][3]);
    }
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// ---- AS3Support tag allocation ----

// @0x1423dbf30
PlaceObject2Tag* AS3Support::AllocPlaceObject2Tag(LoadProcess* p, UPInt dataSz, UInt8 swfVer)
{
    return p->AllocTag<PlaceObject2Tag>(dataSz);
}

// @0x1423dbf90
PlaceObject3Tag* AS3Support::AllocPlaceObject3Tag(LoadProcess* p, UPInt dataSz)
{
    return p->AllocTag<PlaceObject3Tag>(dataSz);
}

// @0x1423dbff0
RemoveObject2Tag* AS3Support::AllocRemoveObject2Tag(LoadProcess* p)
{
    return p->AllocTag<RemoveObject2Tag>();
}

// @0x1423dc050
RemoveObjectTag* AS3Support::AllocRemoveObjectTag(LoadProcess* p)
{
    return p->AllocTag<RemoveObjectTag>();
}


// @0x14252b580
void DisplayObjectBase::SetVisible(bool visible)
{
    SetVisibleFlag(visible);
    SetDirtyFlag();
}
}} // namespace Scaleform::GFx
// MS2-PIN: ??_7LocalInvokeCallback@?6??BroadcastMessage@AsBroadcasterProto@AS2@GFx@Scaleform@@SAXAEBVFnCall@345@@Z@6B@ 0x143221850
// MS2-PIN: ??_7LoadVarsStringVisitor@AS2@GFx@Scaleform@@6B@ 0x1432223c8
// ---- fl_display instance makers: a new instance of the traits' class ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace InstanceTraits { namespace fl_display {
// @0x142444c40
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<AVM1Movie::InstanceType> AVM1Movie::MakeInstance(AVM1Movie& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142444cb0
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<Bitmap::InstanceType> Bitmap::MakeInstance(Bitmap& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142444d30
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<BitmapData::InstanceType> BitmapData::MakeInstance(BitmapData& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142444db0
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<DisplayObject::InstanceType> DisplayObject::MakeInstance(DisplayObject& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142444e00
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<DisplayObjectContainer::InstanceType> DisplayObjectContainer::MakeInstance(DisplayObjectContainer& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142444e80
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<FrameLabel::InstanceType> FrameLabel::MakeInstance(FrameLabel& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142444f10
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<Graphics::InstanceType> Graphics::MakeInstance(Graphics& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142444f90
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<InteractiveObject::InstanceType> InteractiveObject::MakeInstance(InteractiveObject& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445010
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<Loader::InstanceType> Loader::MakeInstance(Loader& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445090
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<LoaderInfo::InstanceType> LoaderInfo::MakeInstance(LoaderInfo& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445110
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<MorphShape::InstanceType> MorphShape::MakeInstance(MorphShape& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445180
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<MovieClip::InstanceType> MovieClip::MakeInstance(MovieClip& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445200
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<Scene::InstanceType> Scene::MakeInstance(Scene& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445280
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<Shape::InstanceType> Shape::MakeInstance(Shape& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445300
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<SimpleButton::InstanceType> SimpleButton::MakeInstance(SimpleButton& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445380
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<Sprite::InstanceType> Sprite::MakeInstance(Sprite& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x142445400
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<Stage::InstanceType> Stage::MakeInstance(Stage& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
}}}}} // namespace Scaleform::GFx::AS3::InstanceTraits::fl_display

// ---- fl_text instance makers ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace InstanceTraits { namespace fl_text {
// @0x1424ad0b0
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<CSMSettings::InstanceType> CSMSettings::MakeInstance(CSMSettings& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424ad130
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<Font::InstanceType> Font::MakeInstance(Font& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424ad200
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<StaticText::InstanceType> StaticText::MakeInstance(StaticText& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424ad270
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<StyleSheet::InstanceType> StyleSheet::MakeInstance(StyleSheet& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424ad300
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<TextField::InstanceType> TextField::MakeInstance(TextField& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424ad370
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<TextFormat::InstanceType> TextFormat::MakeInstance(TextFormat& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424ad3c0
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<TextLineMetrics::InstanceType> TextLineMetrics::MakeInstance(TextLineMetrics& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424ad450
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<TextSnapshot::InstanceType> TextSnapshot::MakeInstance(TextSnapshot& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
}}}}} // namespace Scaleform::GFx::AS3::InstanceTraits::fl_text

// ---- fl_gfx instance makers ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace InstanceTraits { namespace fl_gfx {
// @0x1424c9270
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<FocusEventEx::InstanceType> FocusEventEx::MakeInstance(FocusEventEx& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424c92f0
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<GamePadAnalogEvent::InstanceType> GamePadAnalogEvent::MakeInstance(GamePadAnalogEvent& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424c9360
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<IMECandidateListStyle::InstanceType> IMECandidateListStyle::MakeInstance(IMECandidateListStyle& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424c9400
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<IMEEventEx::InstanceType> IMEEventEx::MakeInstance(IMEEventEx& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424c9490
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<KeyboardEventEx::InstanceType> KeyboardEventEx::MakeInstance(KeyboardEventEx& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424c9510
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<MouseCursorEvent::InstanceType> MouseCursorEvent::MakeInstance(MouseCursorEvent& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424c95b0
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<MouseEventEx::InstanceType> MouseEventEx::MakeInstance(MouseEventEx& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
// @0x1424c9630
// MS2-FUNCTIONAL the exe inlines the instance constructor; cl calls it
Pickable<TextEventEx::InstanceType> TextEventEx::MakeInstance(TextEventEx& t)
{
    return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
}
}}}}} // namespace Scaleform::GFx::AS3::InstanceTraits::fl_gfx

// ---- LogBase instances ----
namespace Scaleform { namespace GFx {
// @0x1424ad030
template void LogBase<LogState>::LogScriptWarning(const char* pfmt, ...) const;
// @0x1424c91f0
template void LogBase<DisplayObjectBase>::LogScriptWarning(const char* pfmt, ...) const;
}} // namespace Scaleform::GFx

// ---- AS3 collectable refcount ----
namespace Scaleform { namespace GFx { namespace AS3 {

// The last reference is gone: finalize and delete, or park the object in the collector for a cycle check.
// @0x1423dfa20
// An object still linked into the collector's work list (a collection is running) is only marked DelayedRelease,
// finalizer or not: Collect frees it itself.
// MS2-FUNCTIONAL register allocation differs
template<int Stat>
void RefCountBaseGC<Stat>::ReleaseInternal() const
{
    if (IsRefCntZero())
    {
        if (HasFinalize())
            const_cast<RefCountBaseGC*>(this)->Finalize_GC();
        if (IsInList())
        {
            RefCount |= Flag_DelayedRelease;
            return;
        }
        RefCount &= ~(Mask_State << Shift_State);
        if (IsInRootList())
        {
            if (!IsInList())
            {
                pRCC->RemoveFromRoots(this);
                RefCount &= ~Flag_InRootList;
                if (!IsInList())
                    RootIndex = ~0u;
            }
            else
                RemoveFromList();
        }
        else if (IsInList())
            RemoveFromList();
        delete const_cast<RefCountBaseGC*>(this);
    }
    else if (GetState() != 3)
    {
        SetState(3);
        if (!IsInList() && !IsInRootList())
            pRCC->AddRoot(this);
    }
}
template void RefCountBaseGC<StatMV_ActionScript_Mem>::ReleaseInternal() const;

// @0x1423dfba0
template<int Stat>
void RefCountCollector<Stat>::RemoveRoot(const BaseType* p)
{
    if (!p->IsInRootList() || p->IsInList())
        return;
    UInt32 idx = p->RootIndex;
    if ((UPInt)(idx + 1) != Roots.GetSize())
    {
        Roots[idx] = (const BaseType*)((FirstFreeRootIndex << 1) | 1);
        FirstFreeRootIndex = idx;
    }
    else
        Roots.Resize(idx);
    p->RefCount &= ~BaseType::Flag_InRootList;
    if (!p->IsInList())
        p->RootIndex = ~0u;
}

// @0x1423df980
// MS2-FUNCTIONAL same transitions; the exe reloads *pchild after the decrement instead of keeping the pointer in a register
template<int Stat>
void RefCountCollector<Stat>::ReleaseChildCall(RefCountCollector* prcc, const BaseType** pchild)
{
    --(*pchild)->RefCount;
    if ((*pchild)->IsRefCntZero())
    {
        prcc->RemoveRoot(*pchild);
        (*pchild)->RefCount |= BaseType::Flag_DelayedRelease;
        if (!(*pchild)->IsInList())
            prcc->AddToList(*pchild);
    }
    else
        (*pchild)->ReleaseInternal();
}
template void RefCountCollector<StatMV_ActionScript_Mem>::RemoveRoot(const BaseType* p);
template void RefCountCollector<StatMV_ActionScript_Mem>::ReleaseChildCall(RefCountCollector* prcc, const BaseType** pchild);

}}} // namespace Scaleform::GFx::AS3

// ---- AS3 class traits factory ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace ClassTraits { namespace fl {
// @0x1423e0090
// MS2-FUNCTIONAL the exe inlines the Math constructor (traits, instance traits and the Math class object); cl calls it
Pickable<Traits> Math::MakeClassTraits(VM& vm)
{
    return Pickable<Traits>(new(vm.GetMemoryHeap()) Math(vm));
}
}}}}} // namespace Scaleform::GFx::AS3::ClassTraits::fl

// ---- AS3 display instance set-up ----
// AvmDisplayObj::GetAS3Root, MovieRoot::AddScriptableMovieClip.
Scaleform::GFx::AS3::MovieRoot* FUN_142505ee0(const Scaleform::GFx::AS3::AvmDisplayObj* pavm);
void FUN_1424e9380(Scaleform::GFx::AS3::MovieRoot* proot, Scaleform::GFx::DisplayObject* pcont);
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_display {
// A script-created shape gets its stage object right away.
// @0x1424447c0
// MS2-FUNCTIONAL the exe inlines CreateStageObject; cl calls the virtual
void Shape::InitInstance(bool extCall)
{
    if (!extCall)
        CreateStageObject();
}
// @0x142444890
// MS2-FUNCTIONAL the exe inlines CreateStageObject; cl calls the virtual
void SimpleButton::InitInstance(bool extCall)
{
    if (!extCall)
        CreateStageObject();
}
// A script-created sprite also registers as scriptable; a movie clip always marks its display object.
// @0x142444a00
// MS2-FUNCTIONAL the exe inlines CreateStageObject; cl calls the virtual
void Sprite::InitInstance(bool extCall)
{
    if (!extCall)
    {
        CreateStageObject();
        FUN_1424e9380(FUN_142505ee0(ToAvmDisplayObj(pDispObj)), pDispObj);
    }
    if (IsMovieClip())
        pDispObj->GFx::DisplayObjectBase::Flags |= GFx::DisplayObjectBase::Mask_MovieClip;
}
// @0x142444be0
bool MovieClip::IsMovieClip() const
{
    return true;
}
// @0x142444bf0
bool Sprite::IsMovieClip() const
{
    return false;
}
}}}}} // namespace Scaleform::GFx::AS3::Instances::fl_display

// The out-of-line NumberUtil::IsNaN that the unity build's AS2 call sites call.
namespace Scaleform { namespace GFx { namespace AS2 {
// @0x142444c00
bool NumberUtil_IsNaN(Double v)
{
    return NumberUtil::IsNaN(v);
}
}}} // namespace Scaleform::GFx::AS2

// ---- collector root buffer: out-of-line page buffer copies ----
namespace Scaleform {
typedef const GFx::AS3::ASRefCountBaseType* GCRootPtr;
typedef ArrayPagedBase<GCRootPtr, 10, 5, AllocatorPagedLH_POD<GCRootPtr, Stat_Default_Mem> > GCRootBase;
// @0x1423dfc30
template void GCRootBase::Resize(UPInt newSize);
// @0x1423df8a0
template bool GCRootBase::PushBackSafe(const GCRootBase::ValueType& val);
} // namespace Scaleform

// ---- Matrix2x4 out-of-line copies ----
namespace Scaleform { namespace Render {

// p mapped through the inverse of this matrix.
// @0x1424471c0
template<class T>
void Matrix2x4<T>::TransformByInverse(Point<T>* result, const Point<T>& p) const
{
    Matrix2x4 m(*this);
    m.Invert();
    result->x = m.M[0][0] * p.x + m.M[0][1] * p.y + m.M[0][3];
    result->y = m.M[1][0] * p.x + m.M[1][1] * p.y + m.M[1][3];
}
// MS2-FUNCTIONAL 0x1424471c0: same arithmetic; cl schedules the inverse's operands differently
template void Matrix2x4<float>::TransformByInverse(Point<float>*, const Point<float>&) const;
// @0x142447090
// MS2-FUNCTIONAL 0x142447090: same arithmetic; cl schedules the inverse's operands differently
template Point<float> Matrix2x4<float>::TransformByInverse(const Point<float>&) const;
// @0x1424eb700
template Matrix2x4<float>& Matrix2x4<float>::AppendScaling(float, float);

}} // namespace Scaleform::Render

// ---- AS3 VM string conversion ----
namespace Scaleform { namespace GFx { namespace AS3 {

// A class without type parameters is its own application.
// @0x1424eb770
Class& Class::ApplyTypeArgs(unsigned, const Value*)
{
    return *this;
}

// The value converted to a string (the empty string when it cannot be).
// @0x1424ed770
ASString VM::AsString(const Value& v)
{
    ASString result = GetStringManager().CreateEmptyString();
    v.Convert2String(result);
    return result;
}

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ?LogScriptWarning@?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@GFx@Scaleform@@QEBAXPEBDZZ 0x1424c91f0
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68
// MS2-PIN: ??_7PlaceObject2Tag@GFx@Scaleform@@6B@ 0x14313bb00
// MS2-PIN: ??_7PlaceObject3Tag@GFx@Scaleform@@6B@ 0x14313bb60
// MS2-PIN: ??_7RemoveObject2Tag@GFx@Scaleform@@6B@ 0x14313bbc0
// MS2-PIN: ??_7RemoveObjectTag@GFx@Scaleform@@6B@ 0x14313bc10
// MS2-PIN: ??_7StaticText@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x14316a510
// MS2-PIN: ?TransformByInverse@?$Matrix2x4@M@Render@Scaleform@@QEBA?AV?$Point@M@23@AEBV423@@Z 0x142447090
// MS2-PIN: ??_7ASSetPropFlagsVisitor@AS2@GFx@Scaleform@@6B@ 0x143214fb8
// MS2-PIN: ?Resize@?$ArrayPagedBase@PEBV?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@$09$04U?$AllocatorPagedLH_POD@PEBV?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@$01@4@@Scaleform@@QEAAX_K@Z 0x1423dfc30
// MS2-PIN: ?PushBackSafe@?$ArrayPagedBase@PEBV?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@$09$04U?$AllocatorPagedLH_POD@PEBV?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@$01@4@@Scaleform@@QEAA_NAEBQEBV?$RefCountBaseGC@$0BED@@AS3@GFx@2@@Z 0x1423df8a0
// MS2-PIN: ?allocatePageSafe@?$ArrayPagedBase@PEBV?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@$09$04U?$AllocatorPagedLH_POD@PEBV?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@$01@4@@Scaleform@@AEAA_N_K@Z 0x1423dfe30
