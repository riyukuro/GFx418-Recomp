// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextFormat object members (gap
// recovery of sfr_as2_05 / sfr_as2_07).
// MS2-UNIT: sfr_as2_03e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142954350-0x142954360 .text$mn
// MS2-RANGE: 0x142987710-0x142988380 .text$mn

namespace Scaleform { class Range; } // gfx_textfield.h (WIP header) names Range before declaring it
#define MS2_AS2_TEXTSNAPSHOT_CTOR_INLINE // MovieClip.getTextSnapshot inlines the TextSnapshotObject ctor
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/gfx/gfx_event.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/video/video_statebag.h"
#include "../include/kernel/sf_alg.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/render/render_twips.h"
#include "../include/render/render_screentoworld.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"
#include "../include/render/text_fontmanager.h"
#include "../include/render/render_font.h"


namespace Scaleform { namespace GFx { namespace AS2 {

// @0x142954350
Object::ObjectType TextFormatObject::GetObjectType() const
{
    return Object_TextFormat;
}

// Largest value of the twips properties (0x2d0 = 720).
static const int TextFormatMaxTwips = 0x2d0;

static int ClampTwips(int value, int lo)
{
    if (value < lo)
        return lo;
    if (value > TextFormatMaxTwips)
        return TextFormatMaxTwips;
    return value;
}

// @0x142987710
// MS2-FUNCTIONAL: the property chain is written as direct comparisons; the exe compares the names one character at a time
bool TextFormatObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    Value v(val);
    const char* pname = name.ToCStr();
    Render::Text::TextFormat&      tf = GetTextFormat();
    Render::Text::ParagraphFormat& pf = GetParagraphFormat();
    const bool clear = val.IsUndefined() || val.IsNull();

    if (!strcmp(pname, "align"))
    {
        ASString s = val.ToString(penv);
        const char* ps = s.ToCStr();
        if (!strcmp(ps, "left"))
            pf.SetAlignment(Render::Text::ParagraphFormat::Align_Left);
        else if (!strcmp(ps, "right"))
            pf.SetAlignment(Render::Text::ParagraphFormat::Align_Right);
        else if (!strcmp(ps, "center"))
            pf.SetAlignment(Render::Text::ParagraphFormat::Align_Center);
        else if (!strcmp(ps, "justify"))
            pf.SetAlignment(Render::Text::ParagraphFormat::Align_Justify);
        else
        {
            pf.ClearAlignment();
            v.SetNull();
        }
    }
    else if (!strcmp(pname, "blockIndent"))
    {
        if (clear)
        {
            pf.ClearBlockIndent();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            pf.SetBlockIndent((unsigned)ClampTwips(n, 0));
        }
    }
    else if (!strcmp(pname, "bold"))
    {
        if (clear)
        {
            tf.ClearBold();
            v.SetNull();
        }
        else
        {
            bool b = val.ToBool(penv);
            v.SetBool(b);
            tf.SetBold(b);
        }
    }
    else if (!strcmp(pname, "bullet"))
    {
        if (clear)
        {
            pf.ClearBullet();
            v.SetNull();
        }
        else
        {
            bool b = val.ToBool(penv);
            v.SetBool(b);
            pf.SetBullet(b);
        }
    }
    else if (!strcmp(pname, "color"))
    {
        if (clear)
        {
            tf.ClearColor();
            v.SetNull();
        }
        else
        {
            unsigned c = (unsigned)val.ToInt32(penv);
            v.SetNumber((double)c);
            tf.SetColor32(c);
        }
    }
    else if (!strcmp(pname, "font"))
    {
        if (clear)
        {
            tf.ClearFontList();
            v.SetNull();
        }
        else
        {
            ASString s = val.ToString(penv);
            v.SetString(s);
            tf.SetFontList(s.ToCStr());
        }
    }
    else if (!strcmp(pname, "indent"))
    {
        if (clear)
        {
            pf.ClearIndent();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            pf.SetIndent(ClampTwips(n, -TextFormatMaxTwips));
        }
    }
    else if (!strcmp(pname, "italic"))
    {
        if (clear)
        {
            tf.ClearItalic();
            v.SetNull();
        }
        else
        {
            bool b = val.ToBool(penv);
            v.SetBool(b);
            tf.SetItalic(b);
        }
    }
    else if (!strcmp(pname, "leading"))
    {
        if (clear)
        {
            pf.ClearLeading();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            pf.SetLeading(ClampTwips(n, -TextFormatMaxTwips));
        }
    }
    else if (!strcmp(pname, "leftMargin"))
    {
        if (clear)
        {
            pf.ClearLeftMargin();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            pf.SetLeftMargin((unsigned)ClampTwips(n, 0));
        }
    }
    else if (!strcmp(pname, "rightMargin"))
    {
        if (clear)
        {
            pf.ClearRightMargin();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            pf.SetRightMargin((unsigned)ClampTwips(n, 0));
        }
    }
    else if (!strcmp(pname, "size"))
    {
        if (clear)
            tf.ClearFontSize();
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            if (n >= 0)
            {
                if (n < 0x80)
                    tf.SetFontSize((float)n);
                else
                    tf.SetFontSizeInFixp(0x9ec); // 127 pixels
            }
        }
    }
    else if (!strcmp(pname, "tabStops"))
    {
        if (clear)
        {
            pf.ClearTabStops();
            v.SetNull();
        }
        else if (val.GetType() == Value::OBJECT)
        {
            Object* pobj = val.ToObject(penv);
            if (pobj->GetObjectType() == Object_Array)
            {
                ArrayObject* parr  = static_cast<ArrayObject*>(pobj);
                int          count = parr->GetSize();
                pf.BeginTabStops((unsigned)count);
                for (int i = 0; i < count; i++)
                {
                    double stop = parr->GetElementPtr(i)->ToNumber(penv);
                    parr->SetElement(i, Value((Number)(double)(unsigned)(long long)stop));
                    pf.SetTabStopsElement((unsigned)i, (unsigned)(long long)stop);
                }
                Value arr(pobj);
                return Object::SetMember(penv, name, arr, flags);
            }
        }
    }
    else if (!strcmp(pname, "underline"))
    {
        if (clear)
        {
            tf.ClearUnderline();
            v.SetNull();
        }
        else
        {
            bool b = val.ToBool(penv);
            v.SetBool(b);
            tf.SetUnderline(b);
        }
    }
    else if (!strcmp(pname, "url"))
    {
        if (clear)
        {
            tf.ClearUrl();
            v.SetNull();
        }
        else
        {
            ASString s = val.ToString(penv);
            v.SetString(s);
            tf.SetUrl(s.ToCStr());
        }
    }
    else
    {
        if (penv->GetVersion() >= 8)
        {
            if (!strcmp(pname, "letterSpacing"))
            {
                if (clear)
                {
                    tf.ClearLetterSpacing();
                    v.SetNull();
                }
                else
                {
                    int n = val.ToInt32(penv);
                    v.SetNumber((double)n);
                    tf.SetLetterSpacing((float)ClampTwips(n, -TextFormatMaxTwips));
                }
            }
            else if (!strcmp(pname, "kerning"))
            {
                if (clear)
                {
                    tf.ClearKerning();
                    v.SetNull();
                }
                else
                {
                    bool b = val.ToBool(penv);
                    v.SetBool(b);
                    tf.SetKerning(b);
                }
            }
        }
        if (penv->CheckExtensions() && !strcmp(pname, "alpha"))
        {
            if (clear)
            {
                tf.ClearAlpha();
                v.SetNull();
            }
            else
            {
                int n = val.ToInt32(penv);
                v.SetNumber((double)n);
                int percent = n < 0 ? 0 : (n > 100 ? 100 : n);
                tf.SetAlpha((UInt8)(int)(((double)percent * 255.0) / 100.0));
            }
        }
    }
    return Object::SetMember(penv, name, v, flags);
}

}}} // namespace Scaleform::GFx::AS2
