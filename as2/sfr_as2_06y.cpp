// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 drawing API: the gradient of
// beginGradientFill / lineGradientStyle (gap recovery of sfr_as2_06).
// MS2-UNIT: sfr_as2_06y
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14298efe0-0x14298fe4e .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
// render_gradients.h uses Alg::Lerp from kernel/sf_alg.h, which shares its include guard with the
// include/kernel/sf_alg.h this unit already pulled in.
namespace Scaleform { namespace Alg {
template<class T> SF_INLINE T Lerp(T a, T b, T f) { return (b - a) * f + a; }
}}
#include "../include/render/render_gradients.h"
#include "../include/render/render_shapedata.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {
// A "box" matrix maps the 32768 twips square of the gradient onto the given pixel size.
const float GradientBoxScale = 20.0f / 32768.0f;
}

// Arguments: fillType, colors, alphas, ratios, matrix [, spreadMethod, interpolationMethod]. The matrix is a
// Matrix object, a {matrixType: "box", x, y, w, h, r} object or an {a, b, d, e, g, h} object (3x3 form, pixels).
// The fill gets the gradient and the inverse of the matrix in twips, prefixed by the gradient square.
// MS2-FUNCTIONAL: the exe calls the matrix rotation and prepend out of line and keeps the matrix halves in xmm pairs
// @0x14298efe0
void AvmSprite::SpriteCreateGradient(const FnCall& fn, Render::ComplexFill* pfill)
{
    if (fn.NArgs < 1)
        return;
    ASString fillType = fn.Arg(0).ToString(fn.Env);
    if (fn.NArgs < 2)
        return;
    Object* pcolors = fn.Arg(1).ToObject(fn.Env);
    if (!pcolors || pcolors->GetObjectType() != Object::Object_Array || fn.NArgs < 3)
        return;
    Object* palphas = fn.Arg(2).ToObject(fn.Env);
    if (!palphas || palphas->GetObjectType() != Object::Object_Array || fn.NArgs < 4)
        return;
    Object* pratios = fn.Arg(3).ToObject(fn.Env);
    if (!pratios || pratios->GetObjectType() != Object::Object_Array || fn.NArgs < 5)
        return;
    ArrayObject* colors = static_cast<ArrayObject*>(pcolors);
    ArrayObject* alphas = static_cast<ArrayObject*>(palphas);
    ArrayObject* ratios = static_cast<ArrayObject*>(pratios);
    int          count  = colors->GetSize();
    if (count < 1 || count != alphas->GetSize() || count != ratios->GetSize())
        return;

    Environment*     penv = fn.Env;
    ASStringContext* psc  = penv->GetSC();
    Render::Matrix2F matrix;
    Value            v;
    Object*          pmatrixObj = fn.Arg(4).ToObject(penv);
    if (pmatrixObj->GetObjectType() == Object::Object_Matrix)
        matrix = static_cast<MatrixObject*>(pmatrixObj)->GetMatrix(penv);
    else if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("matrixType"), &v) &&
             v.ToString(fn.Env) == "box")
    {
        float x = 0, y = 0, w = 100, h = 100, r = 0;
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("x"), &v))
            x = (float)v.ToNumber(fn.Env);
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("y"), &v))
            y = (float)v.ToNumber(fn.Env);
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("w"), &v))
            w = (float)v.ToNumber(fn.Env);
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("h"), &v))
            h = (float)v.ToNumber(fn.Env);
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("r"), &v))
            r = (float)v.ToNumber(fn.Env);
        float sx = w * GradientBoxScale;
        float sy = h * GradientBoxScale;
        matrix.AppendRotation(r);
        matrix.M[0][0] *= sx; matrix.M[0][1] *= sx; matrix.M[0][2] *= sx;
        matrix.M[1][0] *= sy; matrix.M[1][1] *= sy; matrix.M[1][2] *= sy;
        matrix.Tx() = matrix.Tx() * sx + w * 0.5f + x;
        matrix.Ty() = matrix.Ty() * sy + h * 0.5f + y;
    }
    else
    {
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("a"), &v))
            matrix.Sx() = (float)v.ToNumber(fn.Env) * GradientBoxScale;
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("d"), &v))
            matrix.Shx() = (float)v.ToNumber(fn.Env) * GradientBoxScale;
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("g"), &v))
            matrix.Tx() = (float)v.ToNumber(fn.Env);
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("b"), &v))
            matrix.Shy() = (float)v.ToNumber(fn.Env) * GradientBoxScale;
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("e"), &v))
            matrix.Sy() = (float)v.ToNumber(fn.Env) * GradientBoxScale;
        if (pmatrixObj->GetMemberRaw(psc, psc->CreateConstString("h"), &v))
            matrix.Ty() = (float)v.ToNumber(fn.Env);
    }

    // The spread method is read but not used; only linearRGB interpolation is.
    bool linearRGB = false;
    if (fn.NArgs > 5)
    {
        ASString spreadMethod = fn.Arg(5).ToString(fn.Env);
        if (fn.NArgs > 6)
        {
            ASString interpolation = fn.Arg(6).ToString(fn.Env);
            linearRGB              = strcmp(interpolation.ToCStr(), "linearRGB") == 0;
        }
    }

    bool radial = fillType == "radial";
    pfill->pGradient =
        *SF_NEW Render::GradientData(radial ? Render::GradientRadial : Render::GradientLinear, (UInt16)count, linearRGB);
    Render::GradientData* pgradient = pfill->pGradient;
    if (!pgradient)
        return;
    pgradient->SetFocalRatio(0);
    for (int i = 0; i < colors->GetSize(); i++)
    {
        UInt32 rgb   = colors->GetElementPtr(i)->ToUInt32(fn.Env);
        float  alpha = (float)alphas->GetElementPtr(i)->ToNumber(fn.Env) * 255.0f / 100.0f;
        if (alpha >= 255.0f)
            alpha = 255.0f;
        float ratio = (float)ratios->GetElementPtr(i)->ToNumber(fn.Env);
        if (ratio >= 255.0f)
            ratio = 255.0f;
        Render::GradientRecord& rec = pgradient->At(i);
        rec.Ratio                   = (UByte)(int)(ratio >= 0.0f ? ratio : 0.0f);
        rec.ColorV.Raw              = ((UInt32)(SInt64)(alpha >= 0.0f ? alpha : 0.0f) << 24) | (rgb & 0xFFFFFF);
    }

    matrix.Tx() *= 20.0f;
    matrix.Ty() *= 20.0f;
    pfill->ImageMatrix.SetIdentity();
    pfill->ImageMatrix.AppendScaling(1.0f / 32768.0f);
    pfill->ImageMatrix.Tx() += 0.5f;
    pfill->ImageMatrix.Ty() += radial ? 0.5f : 0.0f;
    pfill->ImageMatrix.Prepend(matrix.GetInverse());
}

}}} // namespace Scaleform::GFx::AS2
