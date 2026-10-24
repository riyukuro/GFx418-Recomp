// Recovered Scaleform 4.1.18 GFx: static text (the DefineText / DefineText2 tags). StaticTextDef holds the glyph runs
// as read from the file; StaticTextCharacter, its instance, turns them into a LineBuffer once and draws it as a text
// node. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// gfx_statictext.h is the opaque declaration of the other include tree (the AS3 units); this is the full one.
// Bodies: GFx_StaticText (sfr_gfx_05d, 0x1425df980..0x1425e33f0).
//   StaticTextDef 0x70 bytes, vftable 0x14318c5e0; StaticTextCharacter 0x180 bytes, vftable 0x14318c630 (80 slots,
//   the LogBase one at +0x18: 0x14318c8b0).
#ifndef MS2_SF_GFX_STATICTEXTCHARACTER_H
#define MS2_SF_GFX_STATICTEXTCHARACTER_H

#include "gfx_displayobject.h"
#include "gfx_rendertree.h"
#include "gfx_characterdef.h"
#include "gfx_resource.h"
#include "gfx_fontlib.h"
#include "../kernel/sf_array.h"
#include "../kernel/sf_std.h"
#include "../render/render_matrix2x4.h"
#include "../render/render_color.h"
#include "../render/text_linebuffer.h"
#include "../render/text_filterdesc.h"
#include "../render/text_highlight.h"

namespace Scaleform { namespace GFx {

class LoadProcess;
class Stream;
class StaticTextSnapshotData;

using Render::Color;
using Render::Text::TextFilter;

// Allocation stat of the movie view text (the snapshot selection).
enum { StatMV_StaticText_Mem = StatGroup_GFxMovieView + 5 };

// One run of glyphs with its style (0x40 bytes).
class StaticTextRecord : public NewOverrideBase<StatMD_CharDefs_Mem>
{
public:
    class GlyphEntry
    {
    public:
        unsigned GlyphIndex;
        float    GlyphAdvance;

        GlyphEntry() : GlyphIndex(~0u), GlyphAdvance(0) {}
    };

    ArrayLH<GlyphEntry, StatMD_CharDefs_Mem> Glyphs;      // +0x00
    ResourcePtr<FontResource>                pFont;       // +0x18
    Color                                    ColorV;      // +0x28
    Render::PointF                           Offset;      // +0x2c
    float                                    TextHeight;  // +0x34
    UInt16                                   FontId;      // +0x38

    StaticTextRecord() : Offset(0.0f, 0.0f), TextHeight(1.0f), FontId(0) {}

    // Reads glyphCount (index, advance) pairs.
    void  Read(Stream* in, int glyphCount, int glyphBits, int advanceBits);
    float GetCumulativeAdvance() const;
};

// The runs of a text definition, owned (0x18 bytes).
class StaticTextRecordList
{
public:
    ArrayLH<StaticTextRecord*, StatMD_CharDefs_Mem> Records;

    ~StaticTextRecordList() { Clear(); }

    void              Clear();
    StaticTextRecord* AddRecord();
    UPInt             GetSize() const { return Records.GetSize(); }
};

class StaticTextDef : public CharacterDef
{
public:
    enum
    {
        Flags_AAReadability = 1,
        Flags_HasInstances  = 2
    };

    RectF                TextRect;     // +0x20
    Matrix2F             MatrixPriv;   // +0x30
    StaticTextRecordList TextRecords;  // +0x50
    UByte                Flags;        // +0x68

    StaticTextDef() : Flags(0) {}

    void Read(LoadProcess* p, TagType tagType);

    virtual unsigned         GetResourceTypeCode() const { return MakeTypeCode(RT_TextDef); }
    virtual CharacterDefType GetType() const { return StaticText; }
    // Flash tests the text box only, also for shape hit tests.
    virtual bool             DefPointTestLocal(const PointF& pt, bool testShape = 0,
                                               const DisplayObjectBase* pinst = 0) const;
    virtual RectF            GetBoundsLocal(float = 0) const { return TextRect; }

    bool IsAAForReadability() const { return (Flags & Flags_AAReadability) != 0; }
    bool HasInstances() const       { return (Flags & Flags_HasInstances) != 0; }
    void SetHasInstances()          { Flags |= Flags_HasInstances; }
};

class StaticTextCharacter : public DisplayObject
{
    friend class StaticTextSnapshotData;

    Ptr<StaticTextDef> pDef;        // +0x90
    Matrix2F           OrigMatrix;  // +0xa0 the placement; the node gets it with MatrixPriv prepended

public:
    enum
    {
        Flags_FontsResolved = 1,
        Flags_NextFrame     = 2
    };
    typedef Render::Text::Highlighter Highlighter;
    typedef Render::Text::LineBuffer  LineBuffer;

    LineBuffer TextGlyphRecords;    // +0xc0
    TextFilter Filter;              // +0x120

    // The selection of the text snapshot (0x38 bytes).
    class HighlightDesc : public NewOverrideBase<StatMV_StaticText_Mem>
    {
        Highlighter HighlightManager;

    public:
        Highlighter& GetManager()                       { return HighlightManager; }
        void         Invalidate()                       { HighlightManager.Invalidate(); }
        void         Validate()                         { HighlightManager.Validate(); }
        bool         IsValid() const                    { return HighlightManager.IsValid(); }
        void         SetSelectColor(const Color& color) { HighlightManager.SetSelectColor(color); }
    } * pHighlight;                 // +0x170

    UInt8 Flags;                    // +0x178

    StaticTextCharacter(StaticTextDef* pdef, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot,
                        InteractiveObject* parent, ResourceId id);
    virtual ~StaticTextCharacter();

    virtual Ptr<Render::TreeNode> CreateRenderNode(Render::ContextImpl::Context& context) const;
    virtual const Matrix&         GetMatrix() const;
    virtual void                  SetMatrix(const Matrix& m);
    virtual void                  SetFilters(const Render::FilterSet* filters);
    virtual RectF                 GetBounds(const Matrix& transform) const;
    virtual RectF                 GetRectBounds(const Matrix& transform) const;
    virtual bool                  PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;
    virtual TopMostResult         GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);
    virtual CharacterDef*         GetCharacterDef() const;
    virtual void                  AdvanceFrame(bool nextFrame, float framePos);
    virtual CharacterDef::CharacterDefType GetType() const;

    virtual void SetTextFilters(const TextFilter& f);

    bool           HasHighlights() const { return pHighlight != 0; }
    HighlightDesc* CreateTextHighlighter();
    HighlightDesc* GetTextHighlighter() { return pHighlight; }
    StaticTextDef* GetStaticTextDef() const { return pDef; }

    void RecreateVisibleTextLayout();
};

}} // namespace Scaleform::GFx

namespace Scaleform { namespace Render {

// A leaf node drawing a text layout (the render tree of gfx_rendertree.h cannot see the TextLayout headers).
class TreeText : public TreeNode
{
public:
    class NodeData : public TreeNode::NodeData
    {
    public:
        NodeData(); // 0x14264e580

        void* Data90[4]; // +0x90 the layout
    };

    void SetLayout(const TextLayout::Builder& builder); // 0x1426510e0
};

}} // namespace Scaleform::Render

namespace Scaleform { namespace GFx {

// The tag loader (Tag_DefineText, Tag_DefineText2).
void SF_STDCALL GFx_DefineTextLoader(LoadProcess* p, const TagInfo& tagInfo);

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::Render::TreeText::NodeData) == 0xb0, "NodeData size");

#endif
