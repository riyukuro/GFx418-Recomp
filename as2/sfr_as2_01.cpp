// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 builtin class natives
// (Boolean prototype methods, the Math object functions, Date prototype getters/setters).
// MS2-UNIT: sfr_as2_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1428ed580-0x1428ef8d0 .text$mn
// MS2-RANGE: 0x1428ef8d0-0x1428f1e30 .text$mn
// MS2-RANGE: 0x1428f1e30-0x1428f1e70 .text$mn
// MS2-RANGE: 0x1428f2040-0x1428f37a0 .text$mn
// MS2-RANGE: 0x1428f37a0-0x1428f40d0 .text$mn
// MS2-RANGE: 0x1428f40d0-0x1428f4610 .text$mn
// MS2-RANGE: 0x1428f4610-0x1428f4cd0 .text$mn
// MS2-RANGE: 0x1428f4cd0-0x1428f4e60 .text$mn
// MS2-RANGE: 0x1428f73b0-0x1428f74a0 .text$mn
// MS2-RANGE: 0x1428f7580-0x1428f7740 .text$mn
// MS2-RANGE: 0x1428fb110-0x1428fbb70 .text$mn
// MS2-RANGE: 0x1428fbb80-0x1428fbc40 .text$mn
// MS2-RANGE: 0x1428fbc50-0x1428fbd10 .text$mn
// MS2-RANGE: 0x1428fc160-0x1428fdc00 .text$mn

#include <math.h>

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_date.h"
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

namespace Scaleform { namespace GFx { namespace AS2 {

// Boolean wrapper object. 0x70 bytes.
class BooleanObject : public Object
{
public:
    bool bValue; // +0x68
};

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

class Math
{
public:
    // Next value of the movie's random generator (exe 0x142953f50).
    static UInt32 GetNextRandom(MovieImpl* proot);
};

// The Math object's functions; every argument goes through ToNumber.
class MathCtorFunction
{
    static void Abs(const FnCall& fn);
    static void Acos(const FnCall& fn);
    static void Asin(const FnCall& fn);
    static void Atan(const FnCall& fn);
    static void Ceil(const FnCall& fn);
    static void Cos(const FnCall& fn);
    static void Exp(const FnCall& fn);
    static void Floor(const FnCall& fn);
    static void Log(const FnCall& fn);
    static void Sin(const FnCall& fn);
    static void Sqrt(const FnCall& fn);
    static void Tan(const FnCall& fn);
    static void Atan2(const FnCall& fn);
    static void Max(const FnCall& fn);
    static void Min(const FnCall& fn);
    static void Pow(const FnCall& fn);
    static void Random(const FnCall& fn);
    static void Round(const FnCall& fn);
};

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

// ---- Matrix ----

// cl's /GS heuristic guards the address-taken Matrix2F locals and temporaries of these natives; the exe frames carry
// no cookie (only the ones passing the matrix to an out-of-line member do).
#define MS2_AS2_NOGS __declspec(safebuffers)

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
// MS2-FUNCTIONAL the exe keeps the argument rect in registers across IsRectValid (unity build: it sees the body)
// @0x1428f0760
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

// MS2-FUNCTIONAL the exe keeps the argument rect in registers across IsRectValid (unity build: it sees the body)
// @0x1428f0b20
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
// MS2-FUNCTIONAL fn and the -1 length swap rsi/rdi and the string manager is loaded before str (register allocation)
// @0x1428f1780
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

// MS2-FUNCTIONAL the exe keeps dy's type byte in a register across the calls (unity-build alias knowledge)
// @0x1428f2790
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

// The global clearInterval()/clearTimeout() functions.
class IntervalTimer
{
public:
    static void ClearInterval(const FnCall& fn);
    static void ClearTimeout(const FnCall& fn);
};

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

}}} // namespace Scaleform::GFx::AS2
