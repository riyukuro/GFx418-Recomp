// Recovered Scaleform 4.1.18 Render: TreeText, the display tree node of a text field (Render_TreeText). Its NodeData
// holds the document view the text is formatted by and the text layout built from it; the setters forward to the
// view and mark the layout for a rebuild, which PropagateUp performs. The render side caches the node as a
// TreeCacheText.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// TreeText::NodeData is 0xb0 bytes: pDocView +0x90, pLayout +0x98, TextFlags +0xa0; vftable 0x143190620. Bodies in
// sfr_render_04l.
#ifndef MS2_SF_RENDER_TREETEXT_H
#define MS2_SF_RENDER_TREETEXT_H

#include "ms2/scaleform/include/render/render_treenode.h"
#include "ms2/scaleform/include/render/render_textlayout.h"
#include "ms2/scaleform/include/render/text_docview.h"

namespace Scaleform { namespace Render {

class TreeText : public TreeNode
{
public:
    // the change bit a layout or document change is published under
    enum { Change_TextLayout = 0x00000400 };

    class NodeData : public ContextData_ImplMixin<NodeData, TreeNode::NodeData>
    {
        typedef ContextData_ImplMixin<NodeData, TreeNode::NodeData> BaseClass;

    public:
        Ptr<Text::DocView> pDocView;    // +0x90
        Ptr<TextLayout>    pLayout;     // +0x98, released before the view
        enum
        {
            TextFlags_RebuildLayout = 0x01
        };
        UInt8 TextFlags;                // +0xa0

        NodeData();
        NodeData(NonlocalCloneArg<NodeData> src);
        ~NodeData();

        virtual bool PropagateUp(Entry* entry) const;

        virtual TreeCacheNode* updateCache(TreeCacheNode* parent, TreeCacheNode* insert,
                                           TreeNode* node, UInt16 depth) const;

        virtual TreeNode* CloneCreate(Context* context) const;
    };

    SF_RENDER_CONTEXT_ENTRY_INLINES(NodeData)

    void              SetLayout(const TextLayout::Builder& builder);
    const TextLayout* GetLayout() const { return GetReadOnlyData()->pLayout; }
    Text::DocView*    GetDocView() const { return GetReadOnlyData()->pDocView; }

    // a new document view, or one made elsewhere
    void Init(Text::Allocator* allocator, Text::FontManagerBase* fontManager, Log* log = 0);
    void Init(Text::DocView* docView);

    void  SetBounds(const RectF& r);
    RectF GetBounds() const;

    // a zero alpha turns the border / background off
    void SetBorderColor(const Color& color);
    void SetBorderColor(UInt32 color);
    void SetBackgroundColor(const Color& color);
    void SetBackgroundColor(UInt32 color);

    enum Alignment
    {
        Align_Left,
        Align_Default = Align_Left,
        Align_Right,
        Align_Center,
        Align_Justify
    };
    void      SetAlignment(Alignment alignment);
    Alignment GetAlignment() const;

    enum VAlignment
    {
        VAlign_Top,
        VAlign_Default = VAlign_Top,
        VAlign_Center,
        VAlign_Bottom
    };
    void SetVAlignment(VAlignment alignment);

    // the lengths default to a null terminated string
    void   SetText(const char* utf8, UPInt lengthInBytes = SF_MAX_UPINT);
    void   SetText(const wchar_t* str, UPInt lengthInChars = SF_MAX_UPINT);
    void   SetText(const String& str);
    String GetText() const;

    void   SetHtmlText(const char* utf8, UPInt lengthInBytes = SF_MAX_UPINT,
                       Text::StyledText::HTMLImageTagInfoArray* imageInfos = 0);
    void   SetHtmlText(const wchar_t* str, UPInt lengthInChars = SF_MAX_UPINT,
                       Text::StyledText::HTMLImageTagInfoArray* imageInfos = 0);
    void   SetHtmlText(const String& str, Text::StyledText::HTMLImageTagInfoArray* imageInfos = 0);
    String GetHtmlText() const;

    // formats over [startPos, endPos), the whole text by default
    void SetColor(Color c, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    void SetFont(const char* fontName, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    void SetFontSize(float fontSize, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);

    enum FontStyle
    {
        Normal,
        Bold,
        Italic,
        BoldItalic,
        ItalicBold = BoldItalic
    };
    void SetFontStyle(FontStyle style, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);
    void SetUnderline(bool underline, UPInt startPos = 0, UPInt endPos = SF_MAX_UPINT);

    void SetMultiline(bool multiline);
    void SetWordWrap(bool wordWrap);

    enum AAMode
    {
        AA_Animation,
        AA_Readability
    };
    void SetAAMode(AAMode mode);

    enum FilterType
    {
        Filter_Unknown    = 0,
        Filter_DropShadow = 1,
        Filter_Blur       = 2,
        Filter_Glow       = 3
    };
    enum FilterFlagsType
    {
        FilterFlag_KnockOut   = 0x20,
        FilterFlag_HideObject = 0x40,
        FilterFlag_FineBlur   = 0x80
    };

    // One text filter in pixels / percent / degrees; blur combines with one glow or drop shadow. 0x20 bytes.
    struct Filter
    {
        unsigned Type;
        union
        {
            struct
            {
                float BlurX, BlurY;
                float Strength;
            } Blur;
            struct
            {
                float  BlurX, BlurY;
                float  Strength;
                UInt32 Color;
                UInt8  Flags;
            } Glow;
            struct
            {
                float  BlurX, BlurY;
                float  Strength;
                UInt32 Color;
                UInt8  Flags;
                float  Angle;
                float  Distance;
            } DropShadow;
        };

        Filter(); // out of line, 0x1425b57e0 (sfr_gfx_03e)
        Filter(FilterType type) : Type(type) { InitByDefaultValues(); }

        void InitByDefaultValues();
    };

    void  SetFilters(const Filter* filters, UPInt count = 1);
    UPInt GetFilters(Filter* buffer, UPInt bufferCount);
    void  ClearFilters();

    SizeF GetTextSize();

    // the layout is rebuilt on the next propagation
    void NotifyLayoutChanged();

private:
    void UpdateDefaultTextFormat(Text::DocView* view, const Text::TextFormat& fmt);
    void UpdateDefaultParagraphFormat(Text::DocView* view, const Text::ParagraphFormat& fmt);
};

// The text node creations allocate 0xb0 bytes of node data.
static_assert(sizeof(TreeText::NodeData) == 0xb0, "TreeText::NodeData size");

}} // namespace Scaleform::Render

#endif
