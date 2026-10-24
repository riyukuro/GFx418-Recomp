// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 member setters of the bitmap
// filters and the ColorTransform of sfr_as2_06 (gap recovery, lane sfr31).
// MS2-UNIT: sfr_as2_06h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142985100-0x1429854e0 .text$mn
// MS2-RANGE: 0x142985570-0x1429856b8 .text$mn
// MS2-RANGE: 0x1429856c0-0x1429858bb .text$mn
// MS2-RANGE: 0x1429858c0-0x142985b43 .text$mn
// MS2-RANGE: 0x142985b50-0x142985ee2 .text$mn
// MS2-RANGE: 0x142986170-0x142986432 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/kernel/sf_std.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The mode flag of the filter set or cleared by a boolean.
static SF_FORCEINLINE void FilterParams_SetModeFlag(Render::BlurFilterParams& p, unsigned flag, bool on)
{
    if (on)
        p.Mode |= flag;
    else
        p.Mode &= ~flag;
}

// MS2-FUNCTIONAL: the exe compares the names with inlined byte loops in a different order
// @0x142985100
bool BevelFilterObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    const char* pname = name.ToCStr();
    if (strcmp(pname, "angle") == 0)
    {
        SetAngle((float)(short)val.ToInt32(penv));
        return true;
    }
    if (strcmp(pname, "blurX") == 0)
    {
        float v = (float)val.ToNumber(penv) * 20.0f;
        writableFilterParams().BlurX = v;
        return true;
    }
    if (strcmp(pname, "blurY") == 0)
    {
        float v = (float)val.ToNumber(penv) * 20.0f;
        writableFilterParams().BlurY = v;
        return true;
    }
    if (strcmp(pname, "distance") == 0)
    {
        SetDistance((float)(short)val.ToInt32(penv));
        return true;
    }
    if (strcmp(pname, "highlightAlpha") == 0)
    {
        float v = (float)val.ToNumber(penv) * 255.0f;
        writableFilterParams().Colors[0].SetAlpha((UByte)(int)v);
        return true;
    }
    if (strcmp(pname, "highlightColor") == 0)
    {
        UInt32 c = val.ToUInt32(penv);
        Render::BlurFilterParams& p = writableFilterParams();
        p.Colors[0].SetColor(c, p.Colors[0].GetAlpha());
        return true;
    }
    if (strcmp(pname, "shadowAlpha") == 0)
    {
        float v = (float)val.ToNumber(penv) * 255.0f;
        writableFilterParams().Colors[1].SetAlpha((UByte)(int)v);
        return true;
    }
    if (strcmp(pname, "shadowColor") == 0)
    {
        UInt32 c = val.ToUInt32(penv);
        Render::BlurFilterParams& p = writableFilterParams();
        p.Colors[1].SetColor(c, p.Colors[1].GetAlpha());
        return true;
    }
    if (strcmp(pname, "knockout") == 0)
    {
        bool on = val.ToBool(penv);
        FilterParams_SetModeFlag(writableFilterParams(), Render::BlurFilterParams::Mode_Knockout, on);
        return true;
    }
    if (strcmp(pname, "quality") == 0)
    {
        double v = val.ToNumber(penv);
        writableFilterParams().Passes = (int)(SInt64)v;
        return true;
    }
    if (strcmp(pname, "strength") == 0)
    {
        double v = val.ToNumber(penv);
        writableFilterParams().Strength = (float)v;
        return true;
    }
    if (strcmp(pname, "type") == 0)
    {
        ASString s = val.ToString(penv);
        bool inner = strcmp(s.ToCStr(), "inner") == 0;
        FilterParams_SetModeFlag(writableFilterParams(), Render::BlurFilterParams::Mode_Inner, inner);
        return true;
    }
    return Object::SetMember(penv, name, val, flags);
}

// MS2-FUNCTIONAL: the exe compares the names with inlined byte loops
// @0x142985570
bool BlurFilterObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    const char* pname = name.ToCStr();
    if (strcmp(pname, "blurX") == 0)
    {
        float v = (float)val.ToNumber(penv) * 20.0f;
        writableFilterParams().BlurX = v;
        return true;
    }
    if (strcmp(pname, "blurY") == 0)
    {
        float v = (float)val.ToNumber(penv) * 20.0f;
        writableFilterParams().BlurY = v;
        return true;
    }
    if (strcmp(pname, "quality") == 0)
    {
        double v = val.ToNumber(penv);
        writableFilterParams().Passes = (int)(short)(int)v;
        return true;
    }
    return Object::SetMember(penv, name, val, flags);
}

// MS2-FUNCTIONAL: the exe builds the matrix order table on the stack
// @0x1429856c0
bool ColorMatrixFilterObject::SetMember(Environment* penv, const ASString& name, const Value& val,
                                        const PropFlags& flags)
{
    if (strcmp(name.ToCStr(), "matrix") != 0)
        return Object::SetMember(penv, name, val, flags);

    Object* pobj = val.ToObject(penv);
    Render::Filter* f = GetFilter();
    if (!f || f->GetFilterType() != Render::Filter_ColorMatrix)
        return false;
    if (pobj && pobj->InstanceOf(penv, penv->GetPrototype(ASBuiltin_Array), true))
    {
        // The AS matrix is row-major 4x5 (four multipliers then the offset per row).
        const unsigned order[Render::ColorMatrixFilter::ColorMatrixEntries] =
            { 0, 1, 2, 3, 16, 4, 5, 6, 7, 17, 8, 9, 10, 11, 18, 12, 13, 14, 15, 19 };
        Render::ColorMatrixFilter* pcm = static_cast<Render::ColorMatrixFilter*>(f);
        ArrayObject* parr = static_cast<ArrayObject*>(pobj);
        for (int i = 0; i < parr->GetSize(); ++i)
            (*pcm)[order[i]] = (float)parr->GetElementPtr(i)->ToNumber(penv);
    }
    return true;
}

// MS2-FUNCTIONAL: the exe compares the names with inlined byte loops and strcmp
// @0x1429858c0
bool ColorTransformObject::SetMember(Environment* penv, const ASString& name, const Value& val,
                                     const PropFlags& flags)
{
    const char* pname = name.ToCStr();
    if (strcmp(pname, "redMultiplier") == 0)
        mColorTransform.M[0][0] = (float)val.ToNumber(penv);
    else if (strcmp(pname, "greenMultiplier") == 0)
        mColorTransform.M[0][1] = (float)val.ToNumber(penv);
    else if (strcmp(pname, "blueMultiplier") == 0)
        mColorTransform.M[0][2] = (float)val.ToNumber(penv);
    else if (strcmp(pname, "alphaMultiplier") == 0)
        mColorTransform.M[0][3] = (float)val.ToNumber(penv);
    else if (strcmp(pname, "redOffset") == 0)
        mColorTransform.M[1][0] = (float)val.ToNumber(penv);
    else if (strcmp(pname, "greenOffset") == 0)
        mColorTransform.M[1][1] = (float)val.ToNumber(penv);
    else if (strcmp(pname, "blueOffset") == 0)
        mColorTransform.M[1][2] = (float)val.ToNumber(penv);
    else if (strcmp(pname, "alphaOffset") == 0)
        mColorTransform.M[1][3] = (float)val.ToNumber(penv);
    else if (strcmp(pname, "rgb") == 0)
    {
        mColorTransform.M[0][0] = 0;
        mColorTransform.M[0][1] = 0;
        mColorTransform.M[0][2] = 0;
        UInt64 r = 0, g = 0, b = 0;
        if (!NumberUtil::IsNaN(val.ToNumber(penv)))
        {
            UInt64 rgb = (UInt64)val.ToNumber(penv);
            b = rgb & 0xff;
            r = (rgb >> 16) & 0xff;
            g = (rgb >> 8) & 0xff;
        }
        mColorTransform.M[1][0] = (float)r;
        mColorTransform.M[1][1] = (float)g;
        mColorTransform.M[1][2] = (float)b;
    }
    else
        return Object::SetMember(penv, name, val, flags);
    return true;
}

// MS2-FUNCTIONAL: the exe compares the names with inlined byte loops in a different order
// @0x142985b50
bool DropShadowFilterObject::SetMember(Environment* penv, const ASString& name, const Value& val,
                                       const PropFlags& flags)
{
    const char* pname = name.ToCStr();
    if (strcmp(pname, "alpha") == 0)
    {
        float v = (float)val.ToNumber(penv) * 255.0f;
        writableFilterParams().Colors[0].SetAlpha((UByte)(int)v);
        return true;
    }
    if (strcmp(pname, "angle") == 0)
    {
        SetAngle((float)(short)val.ToInt32(penv));
        return true;
    }
    if (strcmp(pname, "blurX") == 0)
    {
        float v = (float)val.ToNumber(penv) * 20.0f;
        writableFilterParams().BlurX = v;
        return true;
    }
    if (strcmp(pname, "blurY") == 0)
    {
        float v = (float)val.ToNumber(penv) * 20.0f;
        writableFilterParams().BlurY = v;
        return true;
    }
    if (strcmp(pname, "color") == 0)
    {
        UInt32 c = val.ToUInt32(penv);
        Render::BlurFilterParams& p = writableFilterParams();
        p.Colors[0].SetColor(c, p.Colors[0].GetAlpha());
        return true;
    }
    if (strcmp(pname, "distance") == 0)
    {
        SetDistance((float)(short)val.ToInt32(penv));
        return true;
    }
    if (strcmp(pname, "hideObject") == 0)
    {
        bool on = val.ToBool(penv);
        FilterParams_SetModeFlag(writableFilterParams(), Render::BlurFilterParams::Mode_HideObject, on);
        return true;
    }
    if (strcmp(pname, "inner") == 0)
    {
        bool on = val.ToBool(penv);
        FilterParams_SetModeFlag(writableFilterParams(), Render::BlurFilterParams::Mode_Inner, on);
        return true;
    }
    if (strcmp(pname, "knockout") == 0)
    {
        bool on = val.ToBool(penv);
        FilterParams_SetModeFlag(writableFilterParams(), Render::BlurFilterParams::Mode_Knockout, on);
        return true;
    }
    if (strcmp(pname, "quality") == 0)
    {
        double v = val.ToNumber(penv);
        writableFilterParams().Passes = (int)(SInt64)v;
        return true;
    }
    if (strcmp(pname, "strength") == 0)
    {
        double v = val.ToNumber(penv);
        writableFilterParams().Strength = (float)v;
        return true;
    }
    return Object::SetMember(penv, name, val, flags);
}

// MS2-FUNCTIONAL: the exe compares the names with inlined byte loops in a different order
// @0x142986170
bool GlowFilterObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    const char* pname = name.ToCStr();
    if (strcmp(pname, "alpha") == 0)
    {
        float v = (float)val.ToNumber(penv) * 255.0f;
        writableFilterParams().Colors[0].SetAlpha((UByte)(int)v);
        return true;
    }
    if (strcmp(pname, "blurX") == 0)
    {
        float v = (float)val.ToNumber(penv) * 20.0f;
        writableFilterParams().BlurX = v;
        return true;
    }
    if (strcmp(pname, "blurY") == 0)
    {
        float v = (float)val.ToNumber(penv) * 20.0f;
        writableFilterParams().BlurY = v;
        return true;
    }
    if (strcmp(pname, "color") == 0)
    {
        UInt32 c = val.ToUInt32(penv);
        Render::BlurFilterParams& p = writableFilterParams();
        p.Colors[0].SetColor(c, p.Colors[0].GetAlpha());
        return true;
    }
    if (strcmp(pname, "inner") == 0)
    {
        bool on = val.ToBool(penv);
        FilterParams_SetModeFlag(writableFilterParams(), Render::BlurFilterParams::Mode_Inner, on);
        return true;
    }
    if (strcmp(pname, "knockout") == 0)
    {
        bool on = val.ToBool(penv);
        FilterParams_SetModeFlag(writableFilterParams(), Render::BlurFilterParams::Mode_Knockout, on);
        return true;
    }
    if (strcmp(pname, "quality") == 0)
    {
        double v = val.ToNumber(penv);
        writableFilterParams().Passes = (int)(SInt64)v;
        return true;
    }
    if (strcmp(pname, "strength") == 0)
    {
        double v = val.ToNumber(penv);
        writableFilterParams().Strength = (float)v;
        return true;
    }
    return Object::SetMember(penv, name, val, flags);
}

}}} // namespace Scaleform::GFx::AS2
