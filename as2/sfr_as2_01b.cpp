// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 StyleSheet prototype methods
// (getStyle, getStyleNames, load, setStyle, transform) and TextField.getFontList.
// MS2-UNIT: sfr_as2_01b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1428f8720-0x1428f9630 .text$mn
// MS2-RANGE: 0x1428f9630-0x1428f99f0 .text$mn
// MS2-RANGE: 0x1428f99f0-0x1428f9ba0 .text$mn
// MS2-RANGE: 0x1428f9cf0-0x1428f9f50 .text$mn
// MS2-RANGE: 0x1428fa620-0x1428fa7a0 .text$mn
// MS2-RANGE: 0x1428ebd60-0x1428ec0b0 .text$mn
// MS2-RANGE: 0x142993090-0x142993261 .text$mn
// MS2-RANGE: 0x142993270-0x142993802 .text$mn
// MS2-RANGE: 0x142993dc0-0x142993f5c .text$mn
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
// MS2-PIN: ??_7ResourceVisitor@MovieDef@GFx@Scaleform@@6B@ 0x143169d08
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7?$RefCountBase@VASCSSFileLoader@AS2@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7ASCSSFileLoader@AS2@GFx@Scaleform@@6B@ 0x1432172f0
// MS2-PIN: ??_7CSSFileLoaderAndParserImpl@AS2@GFx@Scaleform@@6B@ 0x143222848
// MS2-PIN: ??_7CSSStringBuilder@AS2@GFx@Scaleform@@6B@ 0x143222860
// MS2-PIN: ??_7CSSTextFormatLoader@AS2@GFx@Scaleform@@6B@ 0x143222870
// MS2-PIN: ??_7FontNamesVisitor@AS2@GFx@Scaleform@@6B@ 0x143221cb0

#include <stdlib.h>
#include <string.h>

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_loadqueue.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_fontlib.h"
#include "../include/gfx/gfx_fontprovider.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_styledtext.h"

// Text::StyleManager bodies (text_stylesheet.h does not mix with the AS2 headers).
const void* FUN_142609e60(const void* pstyleManager);                                // StyleManager::GetStyles
void FUN_1426095a0(void* pstyleManager, int type, const char* name, Scaleform::UPInt len); // StyleManager::ClearStyle
bool FUN_14260b7f0(void* pstyleManager, const char* pcss, unsigned size);            // StyleManager::ParseCSS

namespace Scaleform { namespace GFx { namespace AS2 {

using Render::Text::StyleManagerBase;

// The StyleHash table GetStyles returns: entries of 0x28 bytes (a free entry has Next == -2).
struct StyleHashEntryView
{
    SPInt  NextInChain; // +0
    int    Type;        // +8 StyleKey::Type
    String Value;       // +0x10 StyleKey::Value
    UPInt  HashValue;   // +0x18
    void*  pStyle;      // +0x20
};
struct StyleHashTableView
{
    UPInt              EntryCount;
    UPInt              SizeMask;
    StyleHashEntryView Entries[1];
};

// Appends each visited member as a CSS declaration ("font-size:12;") to a rule string.
class CSSStringBuilder : public ObjectInterface::MemberVisitor
{
public:
    Environment* pEnv;  // +8
    String*      pCSS;  // +0x10

    CSSStringBuilder(Environment* penv, String* pcss) : pEnv(penv), pCSS(pcss) {}

    virtual void Visit(const ASString& name, const Value& val, UByte flags);
};

// @0x142993090
void CSSStringBuilder::Visit(const ASString& name, const Value& val, UByte flags)
{
    SF_UNUSED(flags);
    const char* pname = name.ToCStr();
    const char* pcss;
    if (!strcmp(pname, "fontFamily"))          pcss = "font-family";
    else if (!strcmp(pname, "fontSize"))       pcss = "font-size";
    else if (!strcmp(pname, "fontStyle"))      pcss = "font-style";
    else if (!strcmp(pname, "fontWeight"))     pcss = "font-weight";
    else if (!strcmp(pname, "letterSpacing"))  pcss = "letter-spacing";
    else if (!strcmp(pname, "marginLeft"))     pcss = "margin-left";
    else if (!strcmp(pname, "marginRight"))    pcss = "margin-right";
    else if (!strcmp(pname, "textAlign"))      pcss = "text-align";
    else if (!strcmp(pname, "textDecoration")) pcss = "text-decoration";
    else if (!strcmp(pname, "textIndent"))     pcss = "text-indent";
    else                                       pcss = pname;
    pCSS->AppendString(pcss);
    pCSS->AppendString(":");
    ASString str = val.ToString(pEnv);
    pCSS->AppendString(str.ToCStr());
    pCSS->AppendString(";");
}

// Sets the visited style members (AS names, CSS values) on a TextFormat object.
class CSSTextFormatLoader : public ObjectInterface::MemberVisitor
{
public:
    Environment*      pEnv;     // +8
    TextFormatObject* pFormat;  // +0x10

    CSSTextFormatLoader(Environment* penv, TextFormatObject* pformat) : pEnv(penv), pFormat(pformat) {}

    // The paragraph format fields this writes (ParagraphFormat has no setters for them).
    struct ParaView
    {
        UByte  Unrecovered[0x12];
        SInt16 Indent;       // +0x12
        UInt16 Unused14;
        UInt16 LeftMargin;   // +0x16
        UInt16 RightMargin;  // +0x18
        UInt16 PresentMask;  // +0x1a
    };

    static bool Is(const char* pconst, const char* pval, unsigned len, unsigned maxLen)
    {
        return strncmp(pconst, pval, (len < maxLen) ? len : maxLen) == 0;
    }

    virtual void Visit(const ASString& name, const Value& val, UByte flags);
};

// @0x142993270
void CSSTextFormatLoader::Visit(const ASString& name, const Value& val, UByte flags)
{
    SF_UNUSED(flags);
    ASString      str   = val.ToString(pEnv);
    const char*   pval  = str.ToCStr();
    unsigned      len   = str.GetSize();
    const char*   pname = name.ToCStr();
    char*         pend  = 0;
    Render::Text::TextFormat& fmt  = pFormat->GetTextFormat();
    ParaView&                 para = *(ParaView*)&pFormat->GetParagraphFormat();

    if (!strcmp(pname, "color"))
        fmt.SetColor32((UInt32)strtol(pval + 1, &pend, 16));
    else if (!strcmp(pname, "display"))
        ;
    else if (!strcmp(pname, "fontFamily"))
        fmt.SetFontList(pval, len);
    else if (!strcmp(pname, "fontSize"))
        fmt.SetFontSize((float)SFstrtod(pval, &pend));
    else if (!strcmp(pname, "fontStyle"))
    {
        if (Is("normal", pval, len, 4))
            fmt.SetItalic(false);
        else if (Is("italic", pval, len, 9))
            fmt.SetItalic(true);
    }
    else if (!strcmp(pname, "fontWeight"))
    {
        if (Is("normal", pval, len, 6))
            fmt.SetBold(false);
        else if (Is("bold", pval, len, 4))
            fmt.SetBold(true);
    }
    else if (!strcmp(pname, "kerning"))
    {
        if (Is("false", pval, len, 5))
            fmt.SetKerning(false);
        else if (Is("true", pval, len, 4))
            fmt.SetKerning(true);
    }
    else if (!strcmp(pname, "letterSpacing"))
        fmt.SetLetterSpacing((float)SFstrtod(pval, &pend));
    else if (!strcmp(pname, "marginLeft"))
    {
        para.PresentMask |= 0x10;
        para.LeftMargin = (UInt16)(SInt64)SFstrtod(pval, &pend);
    }
    else if (!strcmp(pname, "marginRight"))
    {
        para.PresentMask |= 0x20;
        para.RightMargin = (UInt16)(SInt64)SFstrtod(pval, &pend);
    }
    else if (!strcmp(pname, "textAlign"))
    {
        // alignment bits 0x600 (left 0, right 1, justify 2, center 3), present bit 1
        if (Is("left", pval, len, 4))
            para.PresentMask = (UInt16)((para.PresentMask & 0xf9ff) | 1);
        else if (Is("center", pval, len, 6))
            para.PresentMask |= 0x601;
        else if (Is("right", pval, len, 5))
            para.PresentMask = (UInt16)((para.PresentMask & 0xfbff) | 0x201);
        else if (Is("justify", pval, len, 7))
            para.PresentMask = (UInt16)((para.PresentMask & 0xfdff) | 0x401);
    }
    else if (!strcmp(pname, "textDecoration"))
    {
        if (Is("none", pval, len, 4))
            fmt.SetUnderline(false);
        else if (Is("underline", pval, len, 9))
            fmt.SetUnderline(true);
    }
    else if (!strcmp(pname, "textIndent"))
    {
        para.PresentMask |= 4;
        para.Indent = (SInt16)(int)SFstrtod(pval, &pend);
    }
}

static void SetStringMember(Environment* penv, Object* pobj, const char* pname, const ASString& str)
{
    pobj->SetMember(penv, penv->CreateString(pname), Value(str));
}

static void SetNumberMember(Environment* penv, Object* pobj, const char* pname, Number n)
{
    pobj->SetMember(penv, penv->CreateString(pname), Value(n));
}

// StyleSheet.prototype.getStyle(name): an object with the style's properties under their AS names, or undefined.
// MS2-FUNCTIONAL: the member values are set through local helpers instead of the exe's inlined temporaries.
// @0x1428f8720
void StyleSheetProto::GetStyle(const FnCall& fn)
{
    if (!fn.CheckThisPtr(ObjectInterface::Object_StyleSheet))
    {
        fn.ThisPtrError("StyleSheet");
        return;
    }
    StyleSheetObject* pthis = (StyleSheetObject*)fn.ThisPtr;
    if (!pthis)
        return;
    if (fn.NArgs < 1)
    {
        fn.Result->SetUndefined();
        return;
    }

    ASString name = fn.Arg(0).ToString(fn.Env);
    StyleManagerBase* pmgr = (StyleManagerBase*)pthis->Data68;
    const Render::Text::Style* pstyle;
    if (name.GetSize() != 0 && name.ToCStr()[0] == '.')
        pstyle = pmgr->GetStyle(StyleManagerBase::CSS_Class, name.ToCStr() + 1, name.GetSize() - 1);
    else
        pstyle = pmgr->GetStyle(StyleManagerBase::CSS_Tag, name.ToCStr(), name.GetSize());
    if (!pstyle)
    {
        fn.Result->SetUndefined();
        return;
    }

    Environment* penv = fn.Env;
    Ptr<Object>  pobj = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    const Render::Text::TextFormat&      tf = pstyle->mTextFormat;
    const Render::Text::ParagraphFormat& pf = pstyle->mParagraphFormat;

    if (tf.IsColorSet())
    {
        static const char hex[] = "0123456789ABCDEF";
        String color;
        color.AppendChar('#');
        UInt32 c = tf.GetColor32();
        color.AppendChar(hex[((c >> 16) & 0xff) >> 4]);
        color.AppendChar(hex[(c >> 16) & 0xf]);
        color.AppendChar(hex[((c >> 8) & 0xff) >> 4]);
        color.AppendChar(hex[(c >> 8) & 0xf]);
        color.AppendChar(hex[(c & 0xff) >> 4]);
        color.AppendChar(hex[c & 0xf]);
        SetStringMember(penv, pobj, "color", penv->CreateString(color.ToCStr(), color.GetSize()));
    }
    if (tf.IsFontListSet())
    {
        const String& fonts = tf.GetFontList();
        SetStringMember(penv, pobj, "fontFamily", penv->CreateString(fonts.ToCStr(), fonts.GetSize()));
    }
    if (tf.IsFontSizeSet())
        SetNumberMember(penv, pobj, "fontSize", (Number)tf.GetFontSize());
    if (tf.IsItalicSet())
        SetStringMember(penv, pobj, "fontStyle", penv->CreateString(tf.IsItalic() ? "italic" : "normal"));
    if (tf.IsBoldSet())
        SetStringMember(penv, pobj, "fontWeight", penv->CreateString(tf.IsBold() ? "bold" : "normal"));
    if (tf.IsKerningSet())
        SetStringMember(penv, pobj, "kerning", penv->CreateString(tf.IsKerning() ? "true" : "false"));
    if (tf.IsLetterSpacingSet())
        SetNumberMember(penv, pobj, "letterSpacing", (Number)(SInt16)(tf.GetLetterSpacingInFixp() / 20));
    if (pf.IsLeftMarginSet())
        SetNumberMember(penv, pobj, "marginLeft", (Number)pf.GetLeftMargin());
    if (pf.IsRightMarginSet())
        SetNumberMember(penv, pobj, "marginRight", (Number)pf.GetRightMargin());
    if (pf.IsAlignmentSet())
    {
        const char* palign;
        switch (pf.GetAlignment())
        {
        case Render::Text::ParagraphFormat::Align_Left:   palign = "left"; break;
        case Render::Text::ParagraphFormat::Align_Center: palign = "center"; break;
        case Render::Text::ParagraphFormat::Align_Right:  palign = "right"; break;
        default:                                          palign = "justify"; break;
        }
        SetStringMember(penv, pobj, "textAlign", penv->CreateString(palign));
    }
    if (tf.IsUnderlineSet())
        SetStringMember(penv, pobj, "textDecoration", penv->CreateString(tf.IsUnderline() ? "underline" : "none"));
    if (pf.IsIndentSet())
        SetNumberMember(penv, pobj, "textIndent", (Number)pf.GetIndent());

    fn.Result->SetAsObject(pobj);
}

// StyleSheet.prototype.getStyleNames(): an array of the style names (class styles with their leading '.').
// MS2-FUNCTIONAL: walks the style hash through a layout view; the exe inlines the hash iterator.
// @0x1428f9630
void StyleSheetProto::GetStyleNames(const FnCall& fn)
{
    if (!fn.CheckThisPtr(ObjectInterface::Object_StyleSheet))
    {
        fn.ThisPtrError("StyleSheet");
        return;
    }
    StyleSheetObject* pthis = (StyleSheetObject*)fn.ThisPtr;
    if (!pthis)
        return;

    Ptr<ArrayObject> parr = *static_cast<ArrayObject*>(fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_Array)));
    String           name;
    const StyleHashTableView* ptable = *(const StyleHashTableView* const*)FUN_142609e60(pthis->Data68);
    if (ptable)
    {
        for (UPInt i = 0; i <= ptable->SizeMask; ++i)
        {
            const StyleHashEntryView& e = ptable->Entries[i];
            if (e.NextInChain == -2)
                continue;
            name.Clear();
            if (e.Type == StyleManagerBase::CSS_Class)
                name.AppendChar('.');
            name += e.Value;
            parr->PushBack(Value(fn.Env->CreateString(name.ToCStr(), name.GetSize())));
        }
    }
    fn.Result->SetAsObject(parr);
}

// The loader Load queues: reads the CSS file and parses it into the sheet (sfr_as2_03ad / sfr_as2_06 bodies).
class CSSFileLoaderAndParserImpl : public ASCSSFileLoader
{
public:
    UByte    Unrecovered_10[8];
    wchar_t* Buffer;
    int      BufferLen;

    CSSFileLoaderAndParserImpl() : Buffer(0), BufferLen(0) {}
    virtual ~CSSFileLoaderAndParserImpl();
    virtual void Load(const String& fileName, FileOpener* opener);
    virtual void Init(Environment* penv, Object* sheet);
};

// StyleSheet.prototype.load(url): queues the CSS load; true once queued, false without an argument.
// @0x1428f99f0
void StyleSheetProto::Load(const FnCall& fn)
{
    if (!fn.CheckThisPtr(ObjectInterface::Object_StyleSheet))
    {
        fn.ThisPtrError("StyleSheet");
        return;
    }
    StyleSheetObject* pthis = (StyleSheetObject*)fn.ThisPtr;
    if (!pthis)
        return;
    if (fn.NArgs == 0)
    {
        fn.Result->SetBool(false);
        return;
    }

    ASString url = fn.Arg(0).ToString(fn.Env);
    // the style manager's State (+0x28): Loading
    *(int*)&pthis->Data68[5] = 1;
    Ptr<ASCSSFileLoader> ploader = *SF_NEW CSSFileLoaderAndParserImpl();
    fn.Env->GetAS2Root()->AddCssLoadQueueEntry(pthis, ploader, url.ToCStr());
    fn.Result->SetBool(true);
}

// StyleSheet.prototype.setStyle(name, style): replaces the style with the object's properties as CSS, or removes it
// when the style is missing or null.
// @0x1428f9cf0
void StyleSheetProto::SetStyle(const FnCall& fn)
{
    if (!fn.CheckThisPtr(ObjectInterface::Object_StyleSheet))
    {
        fn.ThisPtrError("StyleSheet");
        return;
    }
    StyleSheetObject* pthis = (StyleSheetObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 1)
        return;

    if (fn.NArgs < 2 || fn.Arg(1).IsNull()) // the exe tests type NULLTYPE (0x1428f9d60 cmp byte ptr [rax],1)
    {
        ASString name = fn.Arg(0).ToString(fn.Env);
        if (name.GetSize() != 0)
            FUN_1426095a0(pthis->Data68, name.ToCStr()[0] == '.', name.ToCStr(), SF_MAX_UPINT);
        return;
    }

    ASString name   = fn.Arg(0).ToString(fn.Env);
    Object*  pstyle = fn.Arg(1).ToObject(fn.Env);
    if (pstyle)
    {
        String css;
        css.AppendString(name.ToCStr());
        css.AppendChar('{');
        CSSStringBuilder builder(fn.Env, &css);
        pstyle->VisitMembers(fn.Env->GetSC(), &builder, 0, 0);
        css.AppendChar('}');
        FUN_14260b7f0(pthis->Data68, css.ToCStr(), (unsigned)css.GetSize());
    }
}

// StyleSheet.prototype.transform(style): a TextFormat with the style object's properties.
// @0x1428fa620
void StyleSheetProto::Transform(const FnCall& fn)
{
    if (!fn.CheckThisPtr(ObjectInterface::Object_StyleSheet))
    {
        fn.ThisPtrError("StyleSheet");
        return;
    }
    StyleSheetObject* pthis = (StyleSheetObject*)fn.ThisPtr;
    if (!pthis || fn.NArgs < 1)
        return;

    Object* pstyle = fn.Arg(0).ToObject(fn.Env);
    if (!pstyle)
        return;
    Ptr<Object> pformat = *fn.Env->OperatorNew(fn.Env->GetBuiltin(ASBuiltin_TextFormat));
    CSSTextFormatLoader loader(fn.Env, (TextFormatObject*)pformat.GetPtr());
    pstyle->VisitMembers(fn.Env->GetSC(), &loader, 0, 0);
    fn.Result->SetAsObject(pformat);
}

// Collects the names of the fonts a movie defines.
class FontNamesVisitor : public MovieDef::ResourceVisitor
{
public:
    StringHash<String>* pNames;

    FontNamesVisitor(StringHash<String>* pnames) : pNames(pnames) {}

    virtual void Visit(MovieDef*, Resource* presource, ResourceId, const char*);
};

// @0x142993dc0
void FontNamesVisitor::Visit(MovieDef*, Resource* presource, ResourceId, const char*)
{
    if (presource->GetResourceType() == Resource::RT_Font)
    {
        String name(((FontResource*)presource)->GetName());
        pNames->Set(name, name);
    }
}

// TextField.getFontList(): the names of the movie's fonts, the font library's and the font provider's.
// MS2-FUNCTIONAL: the font name hash is walked with its iterator; the exe inlines it.
// @0x1428ebd60
void TextFieldCtorFunction::GetFontList(const FnCall& fn)
{
    StringHash<String> fontnames;
    MovieImpl*         proot = fn.Env->GetMovieImpl();
    FontNamesVisitor   visitor(&fontnames);
    ((MovieInterface418*)proot)->GetMovieDef()->VisitResources(&visitor, MovieDef::ResVisit_Fonts);

    StateBag*    pstates  = proot->GetStateBag();
    Ptr<FontLib> pfontlib = pstates->GetFontLib();
    if (pfontlib)
        pfontlib->LoadFontNames(fontnames);
    Ptr<FontProvider> pprovider = *(FontProvider*)pstates->GetStateAddRef(State::State_FontProvider);
    if (pprovider)
        pprovider->LoadFontNames(fontnames);

    Ptr<ArrayObject> parr = *SF_HEAP_NEW(fn.Env->GetHeap()) ArrayObject(fn.Env);
    for (StringHash<String>::ConstIterator it = fontnames.Begin(); it != fontnames.End(); ++it)
        parr->PushBack(Value(fn.Env->CreateString(it->First.ToCStr(), it->First.GetSize())));
    fn.Result->SetAsObject(parr);
}

}}} // namespace Scaleform::GFx::AS2
