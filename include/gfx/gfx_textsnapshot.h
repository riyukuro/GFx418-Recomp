// Recovered Scaleform 4.1.18 GFx: StaticTextSnapshotData, the static text of a clip gathered for the text snapshot API.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// 0x28 bytes (embedded in the AS2 TextSnapshot object at +0x68). Bodies: sfr_gfx_05d.cpp (GFx_StaticText).
#ifndef MS2_SF_GFX_TEXTSNAPSHOT_H
#define MS2_SF_GFX_TEXTSNAPSHOT_H

#include "../kernel/sf_string.h"
#include "../kernel/sf_array.h"
#include "../kernel/sf_refcount.h"
#include "../render/render_color.h"
#include "../render/render_matrix2x4.h"

namespace Scaleform { namespace Render {
class Font;
}}

namespace Scaleform { namespace GFx {

class StaticTextCharacter;

class StaticTextSnapshotData
{
public:
    ~StaticTextSnapshotData(); // 0x1424aa050

    // Appends the glyph runs of one static text field (0x1425e0720).
    void Add(StaticTextCharacter* ptext);

    // Script queries (TextSnapshot natives). Character ranges are [start, end).
    UPInt  GetCharCount() const;                                            // 0x1425e1360
    // Index of the first match at or after start, -1 if none (FindTextA: the name collides with the Win32 macro
    // in the original build).
    int    FindTextA(UPInt start, const char* query, bool caseSensitive) const; // 0x1425e1020
    String GetSelectedText(bool inclLineEndings) const;                     // 0x1425e1570
    String GetSubString(UPInt start, UPInt end, bool inclLineEndings) const; // 0x1425e1740
    bool   IsSelected(UPInt start, UPInt end) const;                        // 0x1425e1bc0
    void   SetSelectColor(const Render::Color& color);                      // 0x1425e2b40
    void   SetSelected(UPInt start, UPInt end, bool selected) const;        // 0x1425e2bb0

    // (appended for the static text, sfr_gfx_05d) the layout and the rest of the queries

    // Called per glyph by Visit with the glyph's placement filled in (0x68 bytes).
    class GlyphVisitor
    {
        friend class StaticTextSnapshotData;

    public:
        virtual ~GlyphVisitor() {}
        virtual void OnVisit() = 0;

        UPInt                   GetRunIndex() const { return RunIdx; }
        const Render::Color&    GetColor() const    { return ColorValue; }
        float                   GetHeight() const   { return Height; }
        const Render::Matrix2F& GetMatrix() const   { return Matrix; }
        const Render::RectF&    GetCorners() const  { return Corners; }
        bool                    IsSelected() const  { return bSelected; }

    private:
        Render::Matrix2F Matrix;      // +0x10 glyph origin and the character's rotation
        Render::RectF    Corners;     // +0x30 glyph bounds through Matrix
        void*            pGlyph;      // +0x40 (never set)
        Render::Font*    pFont;       // +0x48
        UPInt            RunIdx;      // +0x50 index of the glyph within its visited run
        float            Height;      // +0x58 font size
        Render::Color    ColorValue;  // +0x5c
        bool             bSelected;   // +0x60
    };

    StaticTextSnapshotData();                                               // 0x1425e0400

    // The character index under (x, y) (stage coordinates), or near it within closedist; -1 if none.
    int  HitTestTextNearPos(float x, float y, float closedist) const;       // 0x1425e1840
    // Calls pvisitor for each glyph with index in [start, end).
    void Visit(GlyphVisitor* pvisitor, UPInt start, UPInt end) const;       // 0x1425e2e00

private:
    struct CharRef
    {
        Ptr<StaticTextCharacter> pChar;
        UPInt                    CharCount;  // characters the field contributed to SnapshotString
    };

    ArrayLH<CharRef> StaticTextCharRefs;  // +0x00
    StringLH         SnapshotString;      // +0x18 all the text, '\n' between lines that start a new row
    Render::Color    SelectColor;         // +0x20
};

}} // namespace Scaleform::GFx

#endif
