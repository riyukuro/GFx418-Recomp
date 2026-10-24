// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextField style helpers of
// sfr_as2_06 (gap recovery, lane sfr24): a highlight style to and from an AS object of textColor, backgroundColor,
// underlineColor and underlineStyle.
// MS2-UNIT: sfr_as2_06s3
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142968610-0x1429689d4 .text$mn
// MS2-RANGE: 0x14296e9f0-0x14296ef85 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/render/text_highlight.h"

#include <string.h>

namespace Scaleform { namespace GFx { namespace AS2 {

// MS2-FUNCTIONAL: register allocation differs.
// @0x142968610
void TextFieldProto::MakeStyle(const FnCall& fn, const Render::Text::HighlightInfo& info)
{
    Ptr<Object> pobj = *SF_HEAP_NEW(fn.Env->GetHeap()) Object(fn.Env);

    if (info.HasUnderlineStyle())
    {
        const char* pstyle = 0;
        switch (info.GetUnderlineStyle())
        {
        case Render::Text::HighlightInfo::Underline_Single:         pstyle = "single"; break;
        case Render::Text::HighlightInfo::Underline_Thick:          pstyle = "thick"; break;
        case Render::Text::HighlightInfo::Underline_Dotted:         pstyle = "dotted"; break;
        case Render::Text::HighlightInfo::Underline_DitheredSingle: pstyle = "ditheredSingle"; break;
        case Render::Text::HighlightInfo::Underline_DitheredThick:  pstyle = "ditheredThick"; break;
        default: break;
        }
        if (pstyle)
        {
            ASString style = fn.Env->CreateConstString(pstyle);
            pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("underlineStyle"), Value(style));
        }
    }
    if (info.HasUnderlineColor())
        pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("underlineColor"),
                           Value(Number(info.UnderlineColor.ToColor32() & 0xFFFFFF)));
    if (info.HasBackgroundColor())
        pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("backgroundColor"),
                           Value(Number(info.BackgroundColor.ToColor32() & 0xFFFFFF)));
    if (info.HasTextColor())
        pobj->SetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("textColor"),
                           Value(Number(info.TextColor.ToColor32() & 0xFFFFFF)));

    fn.Result->SetAsObject(pobj);
}

// MS2-FUNCTIONAL: register allocation differs.
// @0x14296e9f0
Render::Text::HighlightInfo TextFieldProto::ParseStyle(const FnCall& fn, unsigned index,
                                                       const Render::Text::HighlightInfo& base)
{
    Render::Text::HighlightInfo info = base;
    if (fn.NArgs >= 1)
    {
        Ptr<Object> pobj = fn.Arg(index).ToObject(fn.Env);
        if (pobj)
        {
            Value val;
            if (pobj->GetMember(fn.Env, fn.Env->CreateConstString("textColor"), &val))
            {
                if (strcmp(val.ToString(fn.Env).ToCStr(), "none") == 0)
                    info.ClearTextColor();
                else if (!NumberUtil::IsNaNOrInfinity(val.ToNumber(fn.Env)))
                    info.SetTextColor(Render::Color(val.ToUInt32(fn.Env) | 0xFF000000));
            }
            if (pobj->GetMember(fn.Env, fn.Env->CreateConstString("backgroundColor"), &val))
            {
                if (strcmp(val.ToString(fn.Env).ToCStr(), "none") == 0)
                    info.ClearBackgroundColor();
                else if (!NumberUtil::IsNaNOrInfinity(val.ToNumber(fn.Env)))
                    info.SetBackgroundColor(Render::Color(val.ToUInt32(fn.Env) | 0xFF000000));
            }
            if (pobj->GetMember(fn.Env, fn.Env->CreateConstString("underlineColor"), &val))
            {
                if (strcmp(val.ToString(fn.Env).ToCStr(), "none") == 0)
                    info.ClearUnderlineColor();
                else if (!NumberUtil::IsNaNOrInfinity(val.ToNumber(fn.Env)))
                    info.SetUnderlineColor(Render::Color(val.ToUInt32(fn.Env) | 0xFF000000));
            }
            if (pobj->GetMember(fn.Env, fn.Env->CreateConstString("underlineStyle"), &val))
            {
                ASString    style  = val.ToString(fn.Env);
                const char* pstyle = style.ToCStr();
                if (strcmp(pstyle, "dotted") == 0)
                    info.SetDottedUnderline();
                else if (strcmp(pstyle, "single") == 0)
                    info.SetSingleUnderline();
                else if (strcmp(pstyle, "thick") == 0)
                    info.SetThickUnderline();
                else if (strcmp(pstyle, "ditheredSingle") == 0)
                    info.SetDitheredSingleUnderline();
                else if (strcmp(pstyle, "ditheredThick") == 0)
                    info.SetDitheredThickUnderline();
                else
                    info.ClearUnderlineStyle();
            }
        }
    }
    return info;
}

}}} // namespace Scaleform::GFx::AS2
