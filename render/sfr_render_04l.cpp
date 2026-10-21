// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text node TU
// (Render_TreeText): TreeText::NodeData (layout rebuild and bounds in PropagateUp, the TreeCacheText it is drawn by),
// the text setters that forward to the document view, and the conversion between the public Filter description and
// the view's TextFilter.
// MS2-UNIT: sfr_render_04l
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14264e460-0x1426519d0 .text$mn

#include "ms2/scaleform/include/render/render_treetext.h"
#include "ms2/scaleform/include/render/render_treecachetext.h"
#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/text_filterdesc.h"
#include "ms2/scaleform/include/render/text_docview.h"
#include "ms2/scaleform/include/render/text_linebuffer.h"
#include <math.h>

namespace Scaleform { namespace Render {

// ***** TreeText::NodeData

// @0x14264e580
TreeText::NodeData::NodeData() : BaseClass(ET_Text), TextFlags(0) {}

// @0x14264e4e0
TreeText::NodeData::NodeData(NonlocalCloneArg<NodeData> src)
    : BaseClass(NonlocalCloneArg<BaseClass>(*src.pC)), pDocView(src->pDocView), pLayout(src->pLayout),
      TextFlags(src->TextFlags)
{
}

// @0x14264e5c0
TreeText::NodeData::~NodeData() {}

// MS2-FUNCTIONAL: stack layout of the bounds and block order around the inlined 3D EncloseTransform differ
// @0x14264f550
bool TreeText::NodeData::PropagateUp(Entry* entry) const
{
    RectF bounds, parentBounds;

    if (pDocView)
    {
        if (pDocView->IsReformatReq())
            pDocView->Format();

        // a changed document gets a new layout of its visible part
        if (TextFlags & TextFlags_RebuildLayout)
        {
            TextLayout::Builder builder(Memory::GetGlobalHeap());
            pDocView->CreateVisibleTextLayout(builder);

            TreeText* text = (TreeText*)entry;
            NodeData* data = text->GetWritableData(Change_TextLayout);
            data->pLayout  = *SF_HEAP_AUTO_NEW(this) TextLayout(builder);
            data->TextFlags &= ~TextFlags_RebuildLayout;
        }
    }

    if (pLayout)
    {
        bounds = pLayout->GetBounds();

        // the filters grow the local bounds before they go to the parent space
        expandByFilterBounds(&bounds, false);
        if (!Is3D())
            M2D().EncloseTransform(&parentBounds, bounds);
        else
            parentBounds = M3D().EncloseTransform(bounds);
    }

    if (bounds != AproxLocalBounds || parentBounds != bounds)
    {
        TreeText* text = (TreeText*)entry;
        NodeData* data = text->GetWritableData(Change_AproxBounds);
        data->AproxLocalBounds  = bounds;
        data->AproxParentBounds = parentBounds;
        return IsVisible();
    }
    return false;
}

// @0x142651890
TreeCacheNode* TreeText::NodeData::updateCache(TreeCacheNode* parent, TreeCacheNode* insert, TreeNode* node,
                                               UInt16 depth) const
{
    TreeCacheText* cache = (TreeCacheText*)node->GetRenderData();
    if (!cache)
    {
        // a mask node's text is part of the mask from the start (the sort key depends on it)
        unsigned flags = (Flags & (NF_Visible | NF_MaskNode)) | ((Flags & NF_MaskNode) << 1);
        flags |= parent->GetFlags() & (NF_PartOfMask | NF_PartOfScale9);

        // drawn in 3D when any cache node above is
        bool           is3D  = false;
        TreeCacheNode* above = parent;
        while (above && !is3D)
        {
            is3D |= above->GetNodeData()->Is3D();
            above = above->GetParent();
        }
        cache = SF_HEAP_AUTO_NEW(parent) TreeCacheText((TreeText*)node, parent->pRenderer2D, flags | (is3D ? NF_3D : 0));
        if (!cache)
            return 0;
        node->SetRenderData(cache);
    }

    cache->UpdateInsertIntoParent(parent, insert, this, depth);
    return cache;
}

// @0x14264e810
TreeNode* TreeText::NodeData::CloneCreate(Context* context) const
{
    return context->CreateEntry<TreeText>(NonlocalCloneArg<NodeData>(*this));
}

// ***** TreeText

// @0x14264f510
void TreeText::NotifyLayoutChanged()
{
    NodeData* data = GetWritableData(Change_TextLayout);
    data->TextFlags |= NodeData::TextFlags_RebuildLayout;
    AddToPropagate();
}

// @0x1426510e0
void TreeText::SetLayout(const TextLayout::Builder& builder)
{
    NodeData* data = GetWritableData(Change_TextLayout);
    data->pLayout  = *SF_HEAP_AUTO_NEW(this) TextLayout(builder);
    AddToPropagate();
}

// @0x14264fad0
void TreeText::SetAAMode(AAMode mode)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        if (mode == AA_Readability)
            data->pDocView->SetAAForReadability();
        else
            data->pDocView->ClearAAForReadability();
    }
    NotifyLayoutChanged();
}

// @0x14264f0a0
void TreeText::Init(Text::Allocator* allocator, Text::FontManagerBase* fontManager, Log* log)
{
    NodeData* data = GetWritableData(Change_TextLayout);
    if (!data->pDocView)
    {
        data->pDocView = *SF_HEAP_AUTO_NEW(this) Text::DocView(allocator, fontManager, log);

        Text::TextFormat textFormat(Memory::GetHeapByAddress(this));
        textFormat.InitByDefaultValues();
        data->pDocView->SetDefaultTextFormat(textFormat);

        Text::ParagraphFormat paraFormat;
        paraFormat.InitByDefaultValues();
        data->pDocView->SetDefaultParagraphFormat(paraFormat);
        SetAAMode(AA_Animation);
    }
}

// @0x14264f2f0
void TreeText::Init(Text::DocView* docView)
{
    NodeData* data = GetWritableData(Change_TextLayout);
    data->pDocView = docView;
}

// @0x1426512e0
void TreeText::SetText(const char* utf8, UPInt lengthInBytes)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->SetText(utf8, lengthInBytes);
    NotifyLayoutChanged();
}

// @0x142651370
void TreeText::SetText(const wchar_t* str, UPInt lengthInChars)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->SetText(str, lengthInChars);
    NotifyLayoutChanged();
}

// @0x142651220
void TreeText::SetText(const String& str)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->SetText(str.ToCStr(), str.GetLength());
    NotifyLayoutChanged();
}

// @0x14264ef00
String TreeText::GetText() const
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        return data->pDocView->GetText();
    return "";
}

// @0x142650f80
void TreeText::SetHtmlText(const char* utf8, UPInt lengthInBytes, Text::StyledText::HTMLImageTagInfoArray* imageInfos)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->ParseHtml(utf8, lengthInBytes, false, imageInfos);
    NotifyLayoutChanged();
}

// @0x142651030
void TreeText::SetHtmlText(const wchar_t* str, UPInt lengthInChars,
                           Text::StyledText::HTMLImageTagInfoArray* imageInfos)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->ParseHtml(str, lengthInChars, false, imageInfos);
    NotifyLayoutChanged();
}

// @0x142650ea0
void TreeText::SetHtmlText(const String& str, Text::StyledText::HTMLImageTagInfoArray* imageInfos)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->ParseHtml(str.ToCStr(), str.GetLength(), false, imageInfos);
    NotifyLayoutChanged();
}

// @0x14264ee80
String TreeText::GetHtmlText() const
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        return data->pDocView->GetHtml();
    return "";
}

// @0x14264fed0
void TreeText::SetBounds(const RectF& r)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->SetViewRect(r);
    NotifyLayoutChanged();
}

// @0x14264eb50
RectF TreeText::GetBounds() const
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        return data->pDocView->GetViewRect();
    return RectF();
}

// @0x1426517f0
void TreeText::UpdateDefaultTextFormat(Text::DocView* view, const Text::TextFormat& fmt)
{
    const Text::TextFormat* current = view->GetDefaultTextFormat();
    view->SetDefaultTextFormat(current->Merge(fmt));
}

// @0x1426517b0
void TreeText::UpdateDefaultParagraphFormat(Text::DocView* view, const Text::ParagraphFormat& fmt)
{
    const Text::ParagraphFormat* current = view->GetDefaultParagraphFormat();
    view->SetDefaultParagraphFormat(current->Merge(fmt));
}

// @0x14264ff60
void TreeText::SetColor(Color c, UPInt startPos, UPInt endPos)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        Text::TextFormat fmt(data->pDocView->GetHeap());
        fmt.SetColorARGB(c.ToColor32());
        data->pDocView->SetTextFormat(fmt, startPos, endPos);
        UpdateDefaultTextFormat(data->pDocView, fmt);
    }
    NotifyLayoutChanged();
}

// @0x142650740
void TreeText::SetFont(const char* fontName, UPInt startPos, UPInt endPos)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        Text::TextFormat fmt(data->pDocView->GetHeap());
        fmt.SetFontName(fontName);
        data->pDocView->SetTextFormat(fmt, startPos, endPos);
        UpdateDefaultTextFormat(data->pDocView, fmt);
    }
    NotifyLayoutChanged();
}

// @0x1426509b0
void TreeText::SetFontSize(float fontSize, UPInt startPos, UPInt endPos)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        Text::TextFormat fmt(data->pDocView->GetHeap());
        fmt.SetFontSize(fontSize);
        data->pDocView->SetTextFormat(fmt, startPos, endPos);
        UpdateDefaultTextFormat(data->pDocView, fmt);
    }
    NotifyLayoutChanged();
}

// @0x142650c20
void TreeText::SetFontStyle(FontStyle style, UPInt startPos, UPInt endPos)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        Text::TextFormat fmt(data->pDocView->GetHeap());
        switch (style)
        {
        case Normal:
            fmt.SetBold(false);
            fmt.SetItalic(false);
            break;
        case Bold:
            fmt.SetBold(true);
            fmt.SetItalic(false);
            break;
        case Italic:
            fmt.SetBold(false);
            fmt.SetItalic(true);
            break;
        case BoldItalic:
            fmt.SetBold(true);
            fmt.SetItalic(true);
            break;
        }
        data->pDocView->SetTextFormat(fmt, startPos, endPos);
        UpdateDefaultTextFormat(data->pDocView, fmt);
    }
    NotifyLayoutChanged();
}

// @0x142651400
void TreeText::SetUnderline(bool underline, UPInt startPos, UPInt endPos)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        Text::TextFormat fmt(data->pDocView->GetHeap());
        fmt.SetUnderline(underline);
        data->pDocView->SetTextFormat(fmt, startPos, endPos);
        UpdateDefaultTextFormat(data->pDocView, fmt);
    }
    NotifyLayoutChanged();
}

// @0x142651180
void TreeText::SetMultiline(bool multiline)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        if (multiline)
            data->pDocView->SetMultiline();
        else
            data->pDocView->ClearMultiline();
    }
    NotifyLayoutChanged();
}

// @0x142651710
void TreeText::SetWordWrap(bool wordWrap)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        if (wordWrap)
            data->pDocView->SetWordWrap();
        else
            data->pDocView->ClearWordWrap();
    }
    NotifyLayoutChanged();
}

// @0x14264fb70
void TreeText::SetAlignment(Alignment alignment)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        Text::ParagraphFormat::AlignType align;
        switch (alignment)
        {
        case Align_Right:   align = Text::ParagraphFormat::Align_Right; break;
        case Align_Center:  align = Text::ParagraphFormat::Align_Center; break;
        case Align_Justify: align = Text::ParagraphFormat::Align_Justify; break;
        default:            align = Text::ParagraphFormat::Align_Left; break;
        }
        Text::ParagraphFormat fmt;
        fmt.SetAlignment(align);
        data->pDocView->SetParagraphFormat(fmt);
        UpdateDefaultParagraphFormat(data->pDocView, fmt);
    }
    NotifyLayoutChanged();
}

// @0x14264e9b0
TreeText::Alignment TreeText::GetAlignment() const
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        // the format at the start of the text
        Text::ParagraphFormat fmt;
        data->pDocView->GetStyledText()->GetTextAndParagraphFormat(0, &fmt, 0);
        if (fmt.IsAlignmentSet())
        {
            switch (fmt.GetAlignment())
            {
            case Text::ParagraphFormat::Align_Right:   return Align_Right;
            case Text::ParagraphFormat::Align_Center:  return Align_Center;
            case Text::ParagraphFormat::Align_Justify: return Align_Justify;
            default:;
            }
        }
        return Align_Left;
    }
    return Align_Left;
}

// @0x142651660
void TreeText::SetVAlignment(VAlignment alignment)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        Text::DocView::ViewVAlignment align;
        switch (alignment)
        {
        case VAlign_Bottom: align = Text::DocView::VAlign_Bottom; break;
        case VAlign_Center: align = Text::DocView::VAlign_Center; break;
        default:            align = Text::DocView::VAlign_Top; break;
        }
        data->pDocView->SetVAlignment(align);
    }
    NotifyLayoutChanged();
}

// @0x14264fe40
void TreeText::SetBorderColor(UInt32 color)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->SetBorderColor(color);
    NotifyLayoutChanged();
}

// @0x14264fdb0
void TreeText::SetBorderColor(const Color& color)
{
    SetBorderColor(color.ToColor32());
}

// @0x14264fd20
void TreeText::SetBackgroundColor(UInt32 color)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
        data->pDocView->SetBackgroundColor(color);
    NotifyLayoutChanged();
}

// @0x14264fc90
void TreeText::SetBackgroundColor(const Color& color)
{
    SetBackgroundColor(color.ToColor32());
}

// @0x14264f340
void TreeText::Filter::InitByDefaultValues()
{
    // the values of a fresh TextFilter, in pixels, percent and degrees
    Text::TextFilter tf;
    Blur.BlurX          = tf.BlurX;
    Blur.BlurY          = tf.BlurY;
    Blur.Strength       = tf.BlurStrength * 100.f;
    DropShadow.Flags    = (UInt8)(tf.ShadowFlags | FilterFlag_FineBlur);
    DropShadow.Color    = (tf.ShadowParams.Colors[0].ToColor32() & 0xFFFFFF) | ((UInt32)tf.ShadowAlpha << 24);
    DropShadow.Angle    = tf.ShadowAngle / 10.f;
    DropShadow.Distance = Text::FixpToPixels(tf.ShadowDistance);
}

// @0x1426501c0
void TreeText::SetFilters(const Filter* filters, UPInt count)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        Text::TextFilter tf;
        for (UPInt i = 0; i < count; ++i)
        {
            const Filter& f = filters[i];
            switch (f.Type)
            {
            case Filter_Blur:
                tf.BlurX        = Text::PixelsToFixp(f.Blur.BlurX);
                tf.BlurY        = Text::PixelsToFixp(f.Blur.BlurY);
                tf.BlurStrength = f.Blur.Strength / 100.f;
                break;
            case Filter_DropShadow:
                tf.ShadowFlags           = f.DropShadow.Flags;
                tf.ShadowParams.BlurX    = Text::PixelsToFixp(f.DropShadow.BlurX);
                tf.ShadowParams.BlurY    = Text::PixelsToFixp(f.DropShadow.BlurY);
                tf.ShadowParams.Strength = f.DropShadow.Strength / 100.f;
                tf.ShadowAlpha           = Color(f.DropShadow.Color).GetAlpha();
                tf.ShadowAngle           = float(f.DropShadow.Angle * 3.1415926535897932 / 180.0);
                tf.ShadowDistance        = (SInt16)Text::PixelsToFixp(f.DropShadow.Distance);
                tf.ShadowParams.Colors[0] = f.DropShadow.Color;
                tf.ShadowParams.Offset.x  = cosf(tf.ShadowAngle) * tf.ShadowDistance;
                tf.ShadowParams.Offset.y  = sinf(tf.ShadowAngle) * tf.ShadowDistance;
                break;
            case Filter_Glow:
                // a shadow without offset
                tf.ShadowFlags           = f.Glow.Flags;
                tf.ShadowParams.BlurX    = Text::PixelsToFixp(f.Glow.BlurX);
                tf.ShadowParams.BlurY    = Text::PixelsToFixp(f.Glow.BlurY);
                tf.ShadowParams.Strength = f.Glow.Strength / 100.f;
                tf.ShadowAlpha           = Color(f.Glow.Color).GetAlpha();
                tf.ShadowAngle           = 0;
                tf.ShadowDistance        = 0;
                tf.ShadowParams.Colors[0] = f.Glow.Color;
                tf.ShadowParams.Offset.x  = cosf(tf.ShadowAngle) * tf.ShadowDistance;
                tf.ShadowParams.Offset.y  = sinf(tf.ShadowAngle) * tf.ShadowDistance;
                break;
            default:
                break;
            }
        }
        data->pDocView->SetFilters(tf);
    }
    NotifyLayoutChanged();
}

// @0x14264ec20
UPInt TreeText::GetFilters(Filter* buffer, UPInt bufferCount)
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        const Text::TextFilter& tf = data->pDocView->GetFilters();

        UPInt n = 0;
        if ((tf.BlurX != 0 || tf.BlurY != 0) && n < bufferCount)
        {
            buffer[n].Type          = Filter_Blur;
            buffer[n].Blur.BlurX    = Text::FixpToPixels(tf.BlurX);
            buffer[n].Blur.BlurY    = Text::FixpToPixels(tf.BlurY);
            buffer[n].Blur.Strength = tf.BlurStrength * 100.f;
            ++n;
        }
        if ((tf.ShadowParams.BlurX != 0 || tf.ShadowParams.BlurY != 0) && n < bufferCount)
        {
            // an offset makes it a drop shadow, otherwise a glow
            if (tf.ShadowAngle != 0 || tf.ShadowDistance != 0)
            {
                buffer[n].Type                = Filter_DropShadow;
                buffer[n].DropShadow.Flags    = (UInt8)tf.ShadowFlags;
                buffer[n].DropShadow.BlurX    = Text::FixpToPixels(tf.ShadowParams.BlurX);
                buffer[n].DropShadow.BlurY    = Text::FixpToPixels(tf.ShadowParams.BlurY);
                buffer[n].DropShadow.Strength = tf.ShadowParams.Strength * 100.f;
                buffer[n].DropShadow.Color    = (tf.ShadowParams.Colors[0].ToColor32() & 0xFFFFFF) |
                                                ((UInt32)tf.ShadowAlpha << 24);
                buffer[n].DropShadow.Angle    = float(tf.ShadowAngle * 180.0 / 3.1415926535897932);
                buffer[n].DropShadow.Distance = Text::FixpToPixels(tf.ShadowDistance);
                ++n;
            }
            else
            {
                buffer[n].Type          = Filter_Glow;
                buffer[n].Glow.Flags    = (UInt8)tf.ShadowFlags;
                buffer[n].Glow.BlurX    = Text::FixpToPixels(tf.ShadowParams.BlurX);
                buffer[n].Glow.BlurY    = Text::FixpToPixels(tf.ShadowParams.BlurY);
                buffer[n].Glow.Strength = tf.ShadowParams.Strength * 100.f;
                buffer[n].Glow.Color    = (tf.ShadowParams.Colors[0].ToColor32() & 0xFFFFFF) |
                                          ((UInt32)tf.ShadowAlpha << 24);
                ++n;
            }
        }
        return n;
    }
    return 0;
}

// @0x14264e6f0
void TreeText::ClearFilters()
{
    Filter none;
    SetFilters(&none, 1);
}

// @0x14264ef80
SizeF TreeText::GetTextSize()
{
    const NodeData* data = GetReadOnlyData();
    if (data->pDocView)
    {
        SizeF size(data->pDocView->GetTextWidth(), data->pDocView->GetTextHeight());
        // the gutter on both sides
        size.Width += GFX_TEXT_GUTTER * 2;
        size.Height += GFX_TEXT_GUTTER * 2;
        return size;
    }
    return SizeF(0, 0);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7RefCountNTSImpl@Scaleform@@6B@ 0x1431093f0
// MS2-PIN: ??_7EntryData@ContextImpl@Render@Scaleform@@6B@ 0x14317b6d0
// MS2-PIN: ??_7NodeData@TreeNode@Render@Scaleform@@6B@ 0x14317b700
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0EO@@Scaleform@@6B@ 0x143184c98
// MS2-PIN: ??_7?$RefCountBaseNTS@UTextFilter@Text@Render@Scaleform@@$0EO@@Scaleform@@6B@ 0x143189a00
// MS2-PIN: ??_7TextFilter@Text@Render@Scaleform@@6B@ 0x1431899f8
// MS2-PIN: ??_7?$ContextData_ImplMixin@VNodeData@TreeText@Render@Scaleform@@V1TreeNode@34@@ContextImpl@Render@Scaleform@@6B@ 0x1431905d0
// MS2-PIN: ??_7NodeData@TreeText@Render@Scaleform@@6B@ 0x143190620
// MS2-PIN: ??_GNodeData@TreeNode@Render@Scaleform@@UEAAPEAXI@Z 0x14264e620
