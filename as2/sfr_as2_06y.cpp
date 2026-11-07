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
#include "../include/render/render_twips.h"
#include "../include/gfx/gfx_asutils.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {
// GASGradientBoxMagicNumber: a "box" matrix maps the 32768 twips square of the gradient onto the given pixel size.
const float GradientBoxScale = 1.0f / 1638.4f;

// The SDK's header-inline ObjectInterface::GetConstMemberRaw.
SF_FORCEINLINE bool GetConstMemberRawInline(ObjectInterface& obj, ASStringContext* psc, const char* pname, Value* val)
{
    return obj.GetMemberRaw(psc, ASString(psc->CreateConstString(pname)), val);
}

// The SDK's Alg::Clamp (Max(minVal, Min(v, maxVal))).
template<class T> SF_INLINE const T ClampT(const T v, const T minVal, const T maxVal)
{
    return Alg::PMax<T>(minVal, Alg::PMin<T>(v, maxVal));
}
}

// Arguments: fillType, colors, alphas, ratios, matrix [, spreadMethod, interpolationMethod, focalPointRatio]. The
// matrix is a Matrix object, a {matrixType: "box", x, y, w, h, r} object or an {a, b, d, e, g, h} object (3x3 form,
// pixels). The fill gets the gradient and the inverse of the matrix in twips, prefixed by the gradient square.
// MS2-FUNCTIONAL: SDK body, 26 bytes short: box-path xmm10/xmm11 swap and fillTypeStr/matrix frame slots differ.
// @0x14298efe0
void AvmSprite::SpriteCreateGradient(const FnCall& fn, Render::ComplexFill* complexFill)
{
    Object* arg = 0;
    if (fn.NArgs > 0)
    {
        ASString fillTypeStr(fn.Arg(0).ToString(fn.Env));

        if (fn.NArgs > 1 && (arg = fn.Arg(1).ToObject(fn.Env)) != NULL &&
            arg->GetObjectType() == ObjectInterface::Object_Array)
        {
            const ArrayObject* colors = (const ArrayObject*)arg;
            if (fn.NArgs > 2 && (arg = fn.Arg(2).ToObject(fn.Env)) != NULL &&
                arg->GetObjectType() == ObjectInterface::Object_Array)
            {
                const ArrayObject* alphas = (const ArrayObject*)arg;
                if (fn.NArgs > 3 && (arg = fn.Arg(3).ToObject(fn.Env)) != NULL &&
                    arg->GetObjectType() == ObjectInterface::Object_Array)
                {
                    const ArrayObject* ratios = (const ArrayObject*)arg;
                    if (fn.NArgs > 4 &&
                        colors->GetSize() > 0 &&
                        colors->GetSize() == alphas->GetSize() &&
                        colors->GetSize() == ratios->GetSize())
                    {
                        Render::Matrix2F matrix;
                        Value v;
                        ASStringContext *psc = fn.Env->GetSC();

                        arg = fn.Arg(4).ToObject(fn.Env);

                        if (arg->GetObjectType() == ObjectInterface::Object_Matrix)
                        {
                            matrix = ((MatrixObject*)arg)->GetMatrix(fn.Env);
                        }
                        else
                        {
                            if (GetConstMemberRawInline(*arg, psc, "matrixType", &v) &&
                                v.ToString(fn.Env) == "box")
                            {
                                float x = 0;
                                float y = 0;
                                float w = 100;
                                float h = 100;
                                float r = 0;
                                if (GetConstMemberRawInline(*arg, psc, "x", &v)) x = (float)v.ToNumber(fn.Env);
                                if (GetConstMemberRawInline(*arg, psc, "y", &v)) y = (float)v.ToNumber(fn.Env);
                                if (GetConstMemberRawInline(*arg, psc, "w", &v)) w = (float)v.ToNumber(fn.Env);
                                if (GetConstMemberRawInline(*arg, psc, "h", &v)) h = (float)v.ToNumber(fn.Env);
                                if (GetConstMemberRawInline(*arg, psc, "r", &v)) r = (float)v.ToNumber(fn.Env);

                                x += w / 2;
                                y += h / 2;
                                w *= GradientBoxScale;
                                h *= GradientBoxScale;

                                // The exe calls AppendRotation (0x1425f0ec0) out of line.
                                Render::Matrix2F& (Render::Matrix2F::*const appendRotation)(float) =
                                    &Render::Matrix2F::AppendRotation;
                                (matrix.*appendRotation)(r);
                                matrix.AppendScaling(w, h);
                                matrix.AppendTranslation(x, y);
                            }
                            else
                            {
                                // The matrix is transposed: a d g / b e h; c, f and i are not used.
                                if (GetConstMemberRawInline(*arg, psc, "a", &v)) matrix.Sx() = (float)v.ToNumber(fn.Env) * GradientBoxScale;
                                if (GetConstMemberRawInline(*arg, psc, "d", &v)) matrix.Shx() = (float)v.ToNumber(fn.Env) * GradientBoxScale;
                                if (GetConstMemberRawInline(*arg, psc, "g", &v)) matrix.Tx() = (float)v.ToNumber(fn.Env);
                                if (GetConstMemberRawInline(*arg, psc, "b", &v)) matrix.Shy() = (float)v.ToNumber(fn.Env) * GradientBoxScale;
                                if (GetConstMemberRawInline(*arg, psc, "e", &v)) matrix.Sy() = (float)v.ToNumber(fn.Env) * GradientBoxScale;
                                if (GetConstMemberRawInline(*arg, psc, "h", &v)) matrix.Ty() = (float)v.ToNumber(fn.Env);
                            }
                        }

                        // The spread method is read but not used.
                        bool  linearRGB       = false;
                        float focalPointRatio = 0;
                        if (fn.NArgs > 5)
                        {
                            ASString str(fn.Arg(5).ToString(fn.Env));

                            if (fn.NArgs > 6)
                            {
                                linearRGB = fn.Arg(6).ToString(fn.Env) == "linearRGB";
                                if (fn.NArgs > 7)
                                {
                                    if (NumberUtil::IsNaN(focalPointRatio))
                                        focalPointRatio = 0;
                                    else if (focalPointRatio < -1) focalPointRatio = -1;
                                    else if (focalPointRatio >  1) focalPointRatio =  1;
                                }
                            }
                        }

                        // Create the gradient itself.
                        Render::GradientType gradType = Render::GradientLinear;
                        if (fillTypeStr == "radial")
                        {
                            gradType = Render::GradientRadial;
                            if (focalPointRatio != 0)
                                gradType = Render::GradientFocalPoint;
                        }
                        // The gradient data lives in the global heap: it is a ResourceLib key.
                        complexFill->pGradient = *SF_NEW Render::GradientData(gradType, (UInt16)colors->GetSize(), linearRGB);

                        if (complexFill->pGradient)
                        {
                            complexFill->pGradient->SetFocalRatio(focalPointRatio);

                            for (int i = 0; i < colors->GetSize(); i++)
                            {
                                unsigned rgba = colors->GetElementPtr(i)->ToUInt32(fn.Env) | 0xFF000000;

                                // Alpha is clamped to the 0 to 100 range.
                                float alpha = ((float)alphas->GetElementPtr(i)->ToNumber(fn.Env)) * 255.0f / 100.0f;
                                rgba &= 0xFFFFFF;
                                rgba |= unsigned(ClampT(alpha, 0.0f, 255.0f)) << 24;

                                float ratio = (float)ratios->GetElementPtr(i)->ToNumber(fn.Env);
                                ratio = ClampT(ratio, 0.0f, 255.0f);

                                Render::GradientRecord& record = complexFill->pGradient->At(i);
                                record.Ratio = (UByte)ratio;
                                record.ColorV = rgba;
                            }

                            matrix.Tx() = Render::PixelsToTwips(matrix.Tx());
                            matrix.Ty() = Render::PixelsToTwips(matrix.Ty());
                            complexFill->ImageMatrix.SetIdentity();

                            if (gradType == Render::GradientLinear)
                            {
                                complexFill->ImageMatrix.AppendScaling(1.0f / 32768.F);
                                complexFill->ImageMatrix.AppendTranslation(0.5F, 0.F);
                            }
                            else
                            {
                                complexFill->ImageMatrix.AppendScaling(1.0f / 32768.F);
                                complexFill->ImageMatrix.AppendTranslation(0.5F, 0.5F);
                            }
                            // The exe calls Prepend (0x142445bc0) out of line.
                            Render::Matrix2F& (Render::Matrix2F::*const prepend)(const Render::Matrix2F&) =
                                &Render::Matrix2F::Prepend;
                            (complexFill->ImageMatrix.*prepend)(matrix.GetInverse());
                        }
                    }
                }
            }
        }
    }
}

}}} // namespace Scaleform::GFx::AS2
