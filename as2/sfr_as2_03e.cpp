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


namespace Scaleform { namespace Render { namespace Text {
void TextFormat_SetFontSize(TextFormat* pfmt, float pixels); // the exe calls the out-of-line copy (sfr_as2_07p)
}}}

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
#pragma intrinsic(strcmp)                     // the exe expands every strcmp in SetMember

// @0x142987710
bool TextFormatObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    Value v(val);

    if (!strcmp(name.ToCStr(), "align"))
    {
        ASString s = val.ToString(penv);
        const char* ps = s.ToCStr();
        if (!strcmp(ps, "left"))
            GetParagraphFormat().SetAlignment(Render::Text::ParagraphFormat::Align_Left);
        else if (!strcmp(ps, "right"))
            GetParagraphFormat().SetAlignment(Render::Text::ParagraphFormat::Align_Right);
        else if (!strcmp(ps, "center"))
            GetParagraphFormat().SetAlignment(Render::Text::ParagraphFormat::Align_Center);
        else if (!strcmp(ps, "justify"))
            GetParagraphFormat().SetAlignment(Render::Text::ParagraphFormat::Align_Justify);
        else
        {
            GetParagraphFormat().ClearAlignment();
            v.SetNull();
        }
    }
    else if (!strcmp(name.ToCStr(), "blockIndent"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetParagraphFormat().ClearBlockIndent();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            GetParagraphFormat().SetBlockIndent((unsigned)ClampTwips(n, 0));
        }
    }
    else if (!strcmp(name.ToCStr(), "bold"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetTextFormat().ClearBold();
            v.SetNull();
        }
        else
        {
            bool b = val.ToBool(penv);
            v.SetBool(b);
            GetTextFormat().SetBold(b);
        }
    }
    else if (!strcmp(name.ToCStr(), "bullet"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetParagraphFormat().ClearBullet();
            v.SetNull();
        }
        else
        {
            bool b = val.ToBool(penv);
            v.SetBool(b);
            GetParagraphFormat().SetBullet(b);
        }
    }
    else if (!strcmp(name.ToCStr(), "color"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetTextFormat().ClearColor();
            v.SetNull();
        }
        else
        {
            unsigned c = (unsigned)val.ToInt32(penv);
            v.SetNumber((double)c);
            GetTextFormat().SetColor32(c);
        }
    }
    else if (!strcmp(name.ToCStr(), "font"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetTextFormat().ClearFontList();
            v.SetNull();
        }
        else
        {
            ASString s = val.ToString(penv);
            v.SetString(s);
            GetTextFormat().SetFontList(s.ToCStr());
        }
    }
    else if (!strcmp(name.ToCStr(), "indent"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetParagraphFormat().ClearIndent();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            GetParagraphFormat().SetIndent(ClampTwips(n, -TextFormatMaxTwips));
        }
    }
    else if (!strcmp(name.ToCStr(), "italic"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetTextFormat().ClearItalic();
            v.SetNull();
        }
        else
        {
            bool b = val.ToBool(penv);
            v.SetBool(b);
            GetTextFormat().SetItalic(b);
        }
    }
    else if (!strcmp(name.ToCStr(), "leading"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetParagraphFormat().ClearLeading();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            GetParagraphFormat().SetLeading(ClampTwips(n, -TextFormatMaxTwips));
        }
    }
    else if (!strcmp(name.ToCStr(), "leftMargin"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetParagraphFormat().ClearLeftMargin();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            GetParagraphFormat().SetLeftMargin((unsigned)ClampTwips(n, 0));
        }
    }
    else if (!strcmp(name.ToCStr(), "rightMargin"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetParagraphFormat().ClearRightMargin();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            GetParagraphFormat().SetRightMargin((unsigned)ClampTwips(n, 0));
        }
    }
    else if (!strcmp(name.ToCStr(), "size"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetTextFormat().ClearFontSize();
            v.SetNull();
        }
        else
        {
            int n = val.ToInt32(penv);
            v.SetNumber((double)n);
            if (n >= 0)
            {
                if (n < 0x80)
                    Render::Text::TextFormat_SetFontSize(&GetTextFormat(), (float)(unsigned)n);
                else
                    GetTextFormat().SetFontSizeInFixp(0x9ec); // 127 pixels
            }
        }
    }
    else if (!strcmp(name.ToCStr(), "tabStops"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetParagraphFormat().ClearTabStops();
            v.SetNull();
        }
        else if (val.GetType() == Value::OBJECT && val.ToObject(penv)->GetObjectType() == Object_Array)
        {
            ArrayObject* parr  = static_cast<ArrayObject*>(val.ToObject(penv));
            GetParagraphFormat().BeginTabStops((unsigned)parr->GetSize());
            int count = parr->GetSize();
            for (int i = 0; i < count; i++)
            {
                double stop = parr->GetElementPtr(i)->ToNumber(penv);
                parr->SetElement(i, Value((Number)(double)(unsigned)(long long)stop));
                GetParagraphFormat().SetTabStopsElement((unsigned)i, (unsigned)(long long)stop);
            }
            return Object::SetMember(penv, name, Value(parr), flags);
        }
    }
    else if (!strcmp(name.ToCStr(), "underline"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetTextFormat().ClearUnderline();
            v.SetNull();
        }
        else
        {
            bool b = val.ToBool(penv);
            v.SetBool(b);
            GetTextFormat().SetUnderline(b);
        }
    }
    else if (!strcmp(name.ToCStr(), "url"))
    {
        if (val.IsUndefined() || val.IsNull())
        {
            GetTextFormat().ClearUrl();
            v.SetNull();
        }
        else
        {
            ASString s = val.ToString(penv);
            v.SetString(s);
            GetTextFormat().SetUrl(s.ToCStr());
        }
    }
    else
    {
        if (penv->GetVersion() >= 8)
        {
            if (!strcmp(name.ToCStr(), "letterSpacing"))
            {
                if (val.IsUndefined() || val.IsNull())
                {
                    GetTextFormat().ClearLetterSpacing();
                    v.SetNull();
                }
                else
                {
                    int n = val.ToInt32(penv);
                    v.SetNumber((double)n);
                    GetTextFormat().SetLetterSpacing((float)ClampTwips(n, -TextFormatMaxTwips));
                }
            }
            else if (!strcmp(name.ToCStr(), "kerning"))
            {
                if (val.IsUndefined() || val.IsNull())
                {
                    GetTextFormat().ClearKerning();
                    v.SetNull();
                }
                else
                {
                    bool b = val.ToBool(penv);
                    v.SetBool(b);
                    GetTextFormat().SetKerning(b);
                }
            }
        }
        if (penv->CheckExtensions() && !strcmp(name.ToCStr(), "alpha"))
        {
            if (val.IsUndefined() || val.IsNull())
            {
                GetTextFormat().ClearAlpha();
                v.SetNull();
            }
            else
            {
                int n = val.ToInt32(penv);
                v.SetNumber((double)n);
                int percent = n < 0 ? 0 : (n > 100 ? 100 : n);
                GetTextFormat().SetAlpha((UInt8)(int)(((double)percent * 255.0) / 100.0));
            }
        }
    }
    return Object::SetMember(penv, name, v, flags);
}
#pragma function(strcmp)

}}} // namespace Scaleform::GFx::AS2
