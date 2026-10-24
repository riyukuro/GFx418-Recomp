// Recovered Scaleform 4.1.18 Render Text core: the character/paragraph format records shared by every text
// object (TextFormat 0x48, ParagraphFormat 0x20), their pointer wrapper for the format caches, image descriptors
// of <IMG> runs, and the per-document Allocator (format caches + paragraph ids; NewParagraphId +0x28, pHeap +0x30).
// Layouts are those of the exe (StyledText ctor/Allocator::AllocateParagraph). The out-of-line members (Merge,
// Intersection, the tab-stop helpers, the format caches) belong to Text_Core (unit sfr_render_03).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_CORE_H
#define MS2_SF_RENDER_TEXT_CORE_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_hash.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"
#include "ms2/scaleform/include/kernel/sf_range.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_image.h"
#include "ms2/scaleform/include/render/render_stats.h"

namespace Scaleform { namespace Render { namespace Text {

// text geometry is kept in twips (1/20 pixel)
template<typename T> T FixpToPixels(T x) { return T((x) / T(20.)); }
template<typename T> T PixelsToFixp(T x) { return T((x) * T(20.)); }
template<> inline float  FixpToPixels(float x)  { return x * 0.05f; }
template<> inline double FixpToPixels(double x) { return x * 0.05; }

class Paragraph;
class FontManagerBase;

}  // namespace Text
class Font;
namespace Text {

// Outline of a resolved font reference (Text_FontManager, recovered with the font manager).
class FontHandle : public RefCountBase<FontHandle, StatRender_Text_Mem>
{
public:
    bool operator==(const FontHandle& f) const;

    // (appended for Text_Core, sfr_render_03) the fields the format comparisons read
    FontManagerBase* pFontManager;      // +0x10
    unsigned         FontFlags;         // +0x18 style bits forced on the face
    StringLH         FontName;          // +0x20
    float            FontScaleFactor;   // +0x28
    Font*            pFont;             // +0x30 (a counted reference, released by ~FontHandle 0x1425b5e40)

    // (appended for Text_DocView, sfr_render_03b) the forced style bits
    enum
    {
        FF_Italic     = 0x1,    // Font::FF_Italic
        FF_Bold       = 0x2,    // Font::FF_Bold
        FF_BoldItalic = 0x3,
        FF_Style_Mask = 0x3,
        FF_NoAutoFit  = 0x20
    };
    Font*    GetFont() const           { return pFont; }
    bool     IsFauxBold() const        { return (FontFlags & FF_Bold) != 0; }
    bool     IsFauxItalic() const      { return (FontFlags & FF_Italic) != 0; }
    unsigned GetFauxFontStyle() const  { return FontFlags & FF_Style_Mask; }
    bool     IsAutoFitDisabled() const { return (FontFlags & FF_NoAutoFit) != 0; }
    float    GetFontScaleFactor() const { return FontScaleFactor; }

    // (appended for the static text, sfr_gfx_05d) a handle on pfont; name is kept only when it differs from the
    // font's own (always inlined, as in the GFx::FontHandle ctor 0x1425b5800; the inline body is in
    // gfx/gfx_fonthandle.h, where Font is complete)
    inline FontHandle(FontManagerBase* pmgr, Font* pfont, const char* name = 0, unsigned flags = 0);
    virtual ~FontHandle(); // 0x1425b5e40

    // (appended for the font manager, sfr_gfx_07g) the name the handle was asked for (the font's own when none was
    // kept), the font's flags with the forced style bits, and the member-wise copy (the font referenced once more);
    // the inline bodies are in gfx/gfx_fonthandle.h
    inline const char* GetFontName() const;
    inline unsigned    GetFontFlags() const;
    inline FontHandle(const FontHandle& src);
    // the style bits of the font and the forced ones
    inline unsigned GetFontStyle() const;
};

// An image placed in text: the image and its placement (baseline in image pixels, screen size in twips).
struct ImageDesc : public RefCountBaseNTS<ImageDesc, StatRender_Text_Mem>
{
    typedef Matrix2F MatrixType;

    Ptr<Image> pImage;
    float      BaseLineX, BaseLineY;
    float      ScreenWidth, ScreenHeight;
    MatrixType Matrix;

    ImageDesc() : BaseLineX(0), BaseLineY(0), ScreenWidth(0), ScreenHeight(0) {}

    float GetScreenWidth() const  { return ScreenWidth; }
    float GetScreenHeight() const { return ScreenHeight; }
    float GetBaseLineX() const    { return BaseLineX; }
    float GetBaseLineY() const    { return BaseLineY; }
    // (appended for the line buffer, sfr_render_04d)
    float GetXScale() const       { return Matrix.GetXScale(); }
    float GetYScale() const       { return Matrix.GetYScale(); }
};

// The attributes of an HTML <IMG> tag on top of the image descriptor.
struct HTMLImageTagDesc : public ImageDesc
{
    StringLH Url;
    StringLH Id;
    int      VSpace, HSpace;    // twips
    unsigned ParaId;
    enum
    {
        Align_BaseLine,
        Align_Right,
        Align_Left
    };
    UByte Alignment;

    HTMLImageTagDesc() : VSpace(0), HSpace(0), ParaId(~0u), Alignment(Align_BaseLine) {}
    ~HTMLImageTagDesc();

    UPInt GetHash() const;
    bool operator==(const HTMLImageTagDesc& f) const
    {
        return Url == f.Url && Id == f.Id && VSpace == f.VSpace && HSpace == f.HSpace && ParaId == f.ParaId &&
               Alignment == f.Alignment;
    }
};

// Character format. Every property has a "present" bit, so a format can be partial and merged over another.
class TextFormat : public NewOverrideBase<StatRender_Text_Mem>
{
public:
    struct HashFunctor
    {
        UPInt operator()(const TextFormat& data) const;
    };
    friend struct HashFunctor;

private:
    mutable unsigned RefCount;                  // +0x00

protected:
    StringDH               FontList;            // +0x08 comma separated font names
    StringDH               Url;                 // +0x18
    Ptr<HTMLImageTagDesc>  pImageDesc;          // +0x28
    Ptr<FontHandle>        pFontHandle;         // +0x30 when the font is referenced by id
    UInt32                 ColorV;              // +0x38 AARRGGBB
    SInt16                 LetterSpacing;       // +0x3c twips
    UInt16                 FontSize;            // +0x3e twips

    enum
    {
        Format_Bold      = 0x1,
        Format_Italic    = 0x2,
        Format_Underline = 0x4,
        Format_Kerning   = 0x8
    };
    UInt8 FormatFlags;                          // +0x40

    enum
    {
        PresentMask_Color          = 1,
        PresentMask_LetterSpacing  = 2,
        PresentMask_FontList       = 4,
        PresentMask_FontSize       = 8,
        PresentMask_Bold           = 0x10,
        PresentMask_Italic         = 0x20,
        PresentMask_Underline      = 0x40,
        PresentMask_Kerning        = 0x80,
        PresentMask_Url            = 0x100,
        PresentMask_ImageDesc      = 0x200,
        PresentMask_Alpha          = 0x400,
        PresentMask_FontHandle     = 0x800,
        PresentMask_SingleFontName = 0x1000
    };
    UInt16 PresentMask;                         // +0x42

public:
    TextFormat(MemoryHeap* pheap)
        : RefCount(1), FontList(pheap), Url(pheap), ColorV(0xFF000000u), LetterSpacing(0), FontSize(0),
          FormatFlags(0), PresentMask(0)
    {
    }
    TextFormat(const TextFormat& src, MemoryHeap* pheap = NULL)
        : RefCount(1), FontList((pheap) ? pheap : src.GetHeap(), src.FontList),
          Url((pheap) ? pheap : src.GetHeap(), src.Url), pImageDesc(src.pImageDesc),
          pFontHandle(src.pFontHandle), ColorV(src.ColorV), LetterSpacing(src.LetterSpacing),
          FontSize(src.FontSize), FormatFlags(src.FormatFlags), PresentMask(src.PresentMask)
    {
    }
    ~TextFormat() {}

    void     AddRef() const      { ++RefCount; }
    void     Release() const     { if (--RefCount == 0) delete this; }
    unsigned GetRefCount() const { return RefCount; }

    MemoryHeap* GetHeap() const { return FontList.GetHeap(); }

    bool IsBold() const      { return (FormatFlags & Format_Bold) != 0; }
    bool IsItalic() const    { return (FormatFlags & Format_Italic) != 0; }
    bool IsUnderline() const { return (FormatFlags & Format_Underline) != 0; }
    bool IsKerning() const   { return (FormatFlags & Format_Kerning) != 0; }

    UInt32 GetColor32() const { return ColorV; }
    UInt8  GetAlpha() const   { return UInt8((ColorV >> 24) & 0xFF); }

    float    GetLetterSpacing() const   { return FixpToPixels(LetterSpacing); } // whole pixels (SInt16 math)
    unsigned GetFontSizeInFixp() const  { return FontSize; }
    float    GetFontSize() const        { return FixpToPixels((float)FontSize); }

    const String& GetFontList() const;
    FontHandle*   GetFontHandle() const { return (IsFontHandleSet()) ? pFontHandle : NULL; }

    void SetImageDesc(HTMLImageTagDesc* pimage) { pImageDesc = pimage; PresentMask |= PresentMask_ImageDesc; }
    // the conditional goes through a temporary Ptr (the exe's out-of-line copy AddRefs and Releases)
    HTMLImageTagDesc* GetImageDesc() const { return (IsImageDescSet()) ? pImageDesc : NULL; }
    void ClearImageDesc() { pImageDesc = NULL; PresentMask &= ~PresentMask_ImageDesc; }

    const String& GetUrl() const { return Url; }

    bool IsBoldSet() const           { return (PresentMask & PresentMask_Bold) != 0; }
    bool IsItalicSet() const         { return (PresentMask & PresentMask_Italic) != 0; }
    bool IsUnderlineSet() const      { return (PresentMask & PresentMask_Underline) != 0; }
    bool IsKerningSet() const        { return (PresentMask & PresentMask_Kerning) != 0; }
    bool IsFontSizeSet() const       { return (PresentMask & PresentMask_FontSize) != 0; }
    bool IsFontListSet() const       { return (PresentMask & PresentMask_FontList) != 0; }
    bool IsSingleFontNameSet() const { return (PresentMask & PresentMask_SingleFontName) != 0; }
    bool IsFontHandleSet() const     { return (PresentMask & PresentMask_FontHandle) != 0; }
    bool IsImageDescSet() const      { return (PresentMask & PresentMask_ImageDesc) != 0; }
    bool IsColorSet() const          { return (PresentMask & PresentMask_Color) != 0; }
    bool IsAlphaSet() const          { return (PresentMask & PresentMask_Alpha) != 0; }
    bool IsLetterSpacingSet() const  { return (PresentMask & PresentMask_LetterSpacing) != 0; }
    bool IsUrlSet() const            { return (PresentMask & PresentMask_Url) != 0 && Url.GetLength() != 0; }
    bool IsUrlCleared() const        { return (PresentMask & PresentMask_Url) != 0 && Url.GetLength() == 0; }

    TextFormat Merge(const TextFormat& fmt) const;
    TextFormat Intersection(const TextFormat& fmt) const;

    bool IsFontSame(const TextFormat& fmt) const;
    bool IsHTMLFontTagSame(const TextFormat& fmt) const;
    void InitByDefaultValues();

    // Setters used by the style sheet; the flag ones are out of line (exe 0x142607d90 SetBold, 0x1426082a0 SetItalic,
    // 0x1426084d0 SetUnderline, 0x142608330 SetKerning).
    void SetBold(bool bold = true);
    void SetItalic(bool italic = true);
    void SetUnderline(bool underline = true);
    void SetKerning(bool kerning = true);
    // Sets the RGB part; the alpha is kept.
    void SetColor32(UInt32 color)
    {
        ColorV = (ColorV & 0xFF000000u) | (color & 0xFFFFFFu);
        PresentMask |= PresentMask_Color;
    }
    void SetLetterSpacing(float pixels)
    {
        LetterSpacing = (SInt16)PixelsToFixp(pixels);
        PresentMask |= PresentMask_LetterSpacing;
    }
    // Sizes past the 16 bit twips range clamp to 0xFFFF.
    void SetFontSize(float pixels)
    {
        FontSize = (pixels < FixpToPixels(65536.0f)) ? (UInt16)PixelsToFixp(pixels) : (UInt16)0xFFFFu;
        PresentMask |= PresentMask_FontSize;
    }
    void SetFontList(const char* pfontList, UPInt fontListSz = SF_MAX_UPINT); // exe 0x142607f40

    // (appended for Text_Core, sfr_render_03)
    bool operator==(const TextFormat& f) const;

    void SetFontList(const String& fontList);
    void SetFontList(const wchar_t* pfontList, UPInt fontListSz = SF_MAX_UPINT);
    // a single face name (the list setters decide whether it holds one)
    void SetFontName(const String& fontName);
    void SetFontName(const char* pfontName, UPInt fontNameSz = SF_MAX_UPINT);
    void SetFontName(const wchar_t* pfontName, UPInt fontNameSz = SF_MAX_UPINT);
    void SetFontHandle(FontHandle* pfontHandle);
    void ClearFontHandle()
    {
        pFontHandle = NULL;
        PresentMask &= ~PresentMask_FontHandle;
    }

    // the whole AARRGGBB value (SetColor32 keeps the alpha)
    void SetColorARGB(UInt32 color)
    {
        ColorV = color;
        PresentMask |= PresentMask_Color;
    }
    void SetAlpha(UInt8 alpha)
    {
        ColorV = (ColorV & 0xFFFFFFu) | (UInt32(alpha) << 24);
        PresentMask |= PresentMask_Alpha;
    }
    void ClearAlpha()
    {
        ColorV |= 0xFF000000u;
        PresentMask &= ~PresentMask_Alpha;
    }

    SInt16 GetLetterSpacingInFixp() const { return LetterSpacing; }
    void   SetLetterSpacingInFixp(SInt16 twips)
    {
        LetterSpacing = twips;
        PresentMask |= PresentMask_LetterSpacing;
    }
    void ClearLetterSpacing()
    {
        LetterSpacing = 0;
        PresentMask &= ~PresentMask_LetterSpacing;
    }
    void SetFontSizeInFixp(unsigned twips)
    {
        FontSize = (UInt16)twips;
        PresentMask |= PresentMask_FontSize;
    }

    void SetUrl(const String& url);
    void SetUrl(const char* purl, UPInt urlSz = SF_MAX_UPINT);
    void SetUrl(const wchar_t* purl, UPInt urlSz = SF_MAX_UPINT);
    void ClearUrl()
    {
        Url.Clear();
        PresentMask &= ~PresentMask_Url;
    }

    // Drop one property's value and present bit (the AS2 TextFormat object assigns null/undefined).
    void ClearBold()     { FormatFlags &= ~Format_Bold; PresentMask &= ~PresentMask_Bold; }
    void ClearItalic()   { FormatFlags &= ~Format_Italic; PresentMask &= ~PresentMask_Italic; }
    void ClearUnderline(){ FormatFlags &= ~Format_Underline; PresentMask &= ~PresentMask_Underline; }
    void ClearKerning()  { FormatFlags &= ~Format_Kerning; PresentMask &= ~PresentMask_Kerning; }
    void ClearColor()
    {
        ColorV = 0xFF000000u;
        PresentMask &= ~PresentMask_Color;
    }
    void ClearFontSize()
    {
        FontSize = 0;
        PresentMask &= ~PresentMask_FontSize;
    }
    // The list text stays, only the present bits go.
    void ClearFontList() { PresentMask &= ~(PresentMask_FontList | PresentMask_SingleFontName); }

private:
    // after the font list changed: whether it names one face
    void UpdateSingleFontName()
    {
        if (!SFstrchr(FontList.ToCStr(), ','))
            PresentMask |= PresentMask_SingleFontName;
        else
            PresentMask &= ~PresentMask_SingleFontName;
    }
public:
};

// (appended for Text_Core, sfr_render_03)
inline bool FontHandle::operator==(const FontHandle& f) const
{
    return pFontManager == f.pFontManager && pFont == f.pFont && FontFlags == f.FontFlags &&
           FontName == f.FontName && FontScaleFactor == f.FontScaleFactor;
}

// an unset list reads as the empty string

// A format pointer as stored in the format caches (hashed and compared by value).
template<class T>
class TextFormatPtrWrapper
{
public:
    Ptr<T> pFormat;

    TextFormatPtrWrapper() {}
    TextFormatPtrWrapper(T* ptr) : pFormat(ptr) {}
    TextFormatPtrWrapper(const TextFormatPtrWrapper& orig) : pFormat(orig.pFormat) {}
    // (appended for Text_Core, sfr_render_03) takes the source pointer once, before the release
    TextFormatPtrWrapper& operator=(const TextFormatPtrWrapper& p) { pFormat = p.pFormat.GetPtr(); return *this; }

    struct HashFunctor
    {
        UPInt operator()(const TextFormatPtrWrapper<T>& data) const
        {
            typename T::HashFunctor h;
            return h.operator()(*data.pFormat);
        }
    };

    // (appended for Text_Core, sfr_render_03) the caches compare the formats, not the pointers
    bool operator==(const T* p) const { return *pFormat == *p; }
    bool operator==(const TextFormatPtrWrapper& p) const { return *pFormat == *p.pFormat; }
};
typedef TextFormatPtrWrapper<TextFormat> TextFormatPtr;

// Paragraph format; alignment, display and bullet live in the high bits of PresentMask.
class ParagraphFormat : public NewOverrideBase<StatRender_Text_Mem>
{
public:
    struct HashFunctor
    {
        UPInt operator()(const ParagraphFormat& data) const;
    };
    friend struct HashFunctor;

    enum AlignType
    {
        Align_Left    = 0,
        Align_Right   = 1,
        Align_Justify = 2,
        Align_Center  = 3
    };
    enum DisplayType
    {
        Display_Inline = 0,
        Display_Block  = 1,
        Display_None   = 2
    };

private:
    mutable unsigned RefCount;                  // +0x00

protected:
    unsigned* pTabStops;                        // +0x08 [count, stops in twips...]
    UInt16    BlockIndent;                      // +0x10
    SInt16    Indent;
    SInt16    Leading;
    UInt16    LeftMargin;
    UInt16    RightMargin;                      // +0x18

    enum
    {
        PresentMask_Alignment   = 0x01,
        PresentMask_BlockIndent = 0x02,
        PresentMask_Indent      = 0x04,
        PresentMask_Leading     = 0x08,
        PresentMask_LeftMargin  = 0x10,
        PresentMask_RightMargin = 0x20,
        PresentMask_TabStops    = 0x40,
        PresentMask_Bullet      = 0x80,
        PresentMask_Display     = 0x100,

        Mask_Align    = 0x600,
        Shift_Align   = 9,
        Mask_Display  = 0x1800,
        Shift_Display = 11,
        Mask_Bullet   = 0x8000
    };
    UInt16 PresentMask;                         // +0x1a

public:
    ParagraphFormat()
        : RefCount(1), pTabStops(NULL), BlockIndent(0), Indent(0), Leading(0), LeftMargin(0), RightMargin(0),
          PresentMask(0)
    {
    }
    ParagraphFormat(const ParagraphFormat& src)
        : RefCount(1), pTabStops(NULL), BlockIndent(src.BlockIndent), Indent(src.Indent), Leading(src.Leading),
          LeftMargin(src.LeftMargin), RightMargin(src.RightMargin), PresentMask(src.PresentMask)
    {
        CopyTabStops(src.pTabStops);
    }
    ~ParagraphFormat() { FreeTabStops(); }

    void     AddRef() const      { ++RefCount; }
    void     Release() const     { if (--RefCount == 0) delete this; }
    unsigned GetRefCount() const { return RefCount; }

    bool      IsAlignmentSet() const { return (PresentMask & PresentMask_Alignment) != 0; }
    AlignType GetAlignment() const   { return (AlignType)((PresentMask & Mask_Align) >> Shift_Align); }

    bool IsBulletSet() const { return (PresentMask & PresentMask_Bullet) != 0; }
    bool IsBullet() const    { return IsBulletSet() && (PresentMask & Mask_Bullet) != 0; }

    unsigned GetBlockIndent() const   { return BlockIndent; }
    bool     IsBlockIndentSet() const { return (PresentMask & PresentMask_BlockIndent) != 0; }
    int      GetIndent() const        { return Indent; }
    bool     IsIndentSet() const      { return (PresentMask & PresentMask_Indent) != 0; }
    int      GetLeading() const       { return Leading; }
    bool     IsLeadingSet() const     { return (PresentMask & PresentMask_Leading) != 0; }
    unsigned GetLeftMargin() const    { return LeftMargin; }
    bool     IsLeftMarginSet() const  { return (PresentMask & PresentMask_LeftMargin) != 0; }
    unsigned GetRightMargin() const   { return RightMargin; }
    bool     IsRightMarginSet() const { return (PresentMask & PresentMask_RightMargin) != 0; }

    const unsigned* GetTabStops(unsigned* pnum) const;
    const unsigned* GetTabStops() const { return pTabStops; }
    bool            IsTabStopsSet() const { return (PresentMask & PresentMask_TabStops) != 0; }

    bool        IsDisplaySet() const { return (PresentMask & PresentMask_Display) != 0; }
    DisplayType GetDisplay() const   { return (DisplayType)((PresentMask & Mask_Display) >> Shift_Display); }

    ParagraphFormat  Merge(const ParagraphFormat& fmt) const;
    ParagraphFormat  Intersection(const ParagraphFormat& fmt) const;
    ParagraphFormat& operator=(const ParagraphFormat& src);

    void InitByDefaultValues();

protected:
    void AllocTabStops(unsigned num);
    void FreeTabStops();
    bool TabStopsEqual(const unsigned* psrcTabStops) const;
    void CopyTabStops(const unsigned* psrcTabStops);

public:
    // Setters used by the style sheet.
    void SetAlignment(AlignType align)
    {
        PresentMask = (UInt16)((PresentMask & ~Mask_Align) | ((align << Shift_Align) & Mask_Align));
        PresentMask |= PresentMask_Alignment;
    }
    void SetDisplay(DisplayType display)
    {
        PresentMask = (UInt16)((PresentMask & ~Mask_Display) | ((display << Shift_Display) & Mask_Display));
        PresentMask |= PresentMask_Display;
    }
    void SetIndent(int value)           { Indent = (SInt16)value; PresentMask |= PresentMask_Indent; }
    void SetLeading(int value)          { Leading = (SInt16)value; PresentMask |= PresentMask_Leading; }
    void SetLeftMargin(unsigned value)  { LeftMargin = (UInt16)value; PresentMask |= PresentMask_LeftMargin; }
    void SetRightMargin(unsigned value) { RightMargin = (UInt16)value; PresentMask |= PresentMask_RightMargin; }

    // (appended for Text_Core, sfr_render_03)
    bool operator==(const ParagraphFormat& f) const
    {
        return PresentMask == f.PresentMask && BlockIndent == f.BlockIndent && Indent == f.Indent &&
               Leading == f.Leading && LeftMargin == f.LeftMargin && RightMargin == f.RightMargin &&
               TabStopsEqual(f.pTabStops);
    }

    void SetBullet(bool bullet = true)
    {
        if (bullet)
            PresentMask |= Mask_Bullet;
        else
            PresentMask &= ~Mask_Bullet;
        PresentMask |= PresentMask_Bullet;
    }
    void ClearBullet()       { PresentMask &= ~(Mask_Bullet | PresentMask_Bullet); }
    void SetBlockIndent(unsigned value) { BlockIndent = (UInt16)value; PresentMask |= PresentMask_BlockIndent; }
    void ClearBlockIndent()  { BlockIndent = 0; PresentMask &= ~PresentMask_BlockIndent; }
    void ClearIndent()       { Indent = 0; PresentMask &= ~PresentMask_Indent; }
    void ClearLeading()      { Leading = 0; PresentMask &= ~PresentMask_Leading; }
    void ClearLeftMargin()   { LeftMargin = 0; PresentMask &= ~PresentMask_LeftMargin; }
    void ClearRightMargin()  { RightMargin = 0; PresentMask &= ~PresentMask_RightMargin; }

    // tab stops in twips; num 0 / an empty array clears them
    void SetTabStops(unsigned num, ...);
    void SetTabStops(const unsigned* psrcTabStops);
    void SetTabStopsElement(unsigned idx, unsigned val);
    void ClearTabStops()
    {
        FreeTabStops();
        PresentMask &= ~PresentMask_TabStops;
    }
    // a fresh table of num stops (filled with SetTabStopsElement), marked present
    void BeginTabStops(unsigned num)
    {
        AllocTabStops(num);
        PresentMask |= PresentMask_TabStops;
    }
    void ClearAlignment() { PresentMask &= ~(Mask_Align | PresentMask_Alignment); }
};

typedef TextFormatPtrWrapper<ParagraphFormat> ParagraphFormatPtr;

// Per-document text allocator: interns formats in two caches, allocates paragraphs and their text, hands out
// paragraph ids.
class Allocator : public RefCountBaseNTS<Allocator, StatRender_Text_Mem>
{
public:
    enum FlagsEnum
    {
        Flags_Global = 0x1      // shared allocator: font handles are not kept
    };

protected:
    enum
    {
        InitialFormatCacheCap    = 100,
        FormatCacheCapacityDelta = 10
    };

    typedef HashSetLH<TextFormatPtr, TextFormatPtr::HashFunctor, TextFormatPtr::HashFunctor, StatRender_Text_Mem>
        TextFormatStorageType;
    typedef HashSetLH<ParagraphFormatPtr, ParagraphFormatPtr::HashFunctor, ParagraphFormatPtr::HashFunctor,
                      StatRender_Text_Mem>
        ParagraphFormatStorageType;

    TextFormatStorageType      TextFormatStorage;           // +0x10
    ParagraphFormatStorageType ParagraphFormatStorage;      // +0x18
    unsigned                   TextFormatStorageCap;        // +0x20
    unsigned                   ParagraphFormatStorageCap;   // +0x24
    UInt32                     NewParagraphId;              // +0x28
    MemoryHeap*                pHeap;                       // +0x30
    TextFormat                 EntryTextFormat;             // +0x38
    UInt8                      Flags;

public:
    Allocator(MemoryHeap* pheap, UInt8 flags = 0)
        : TextFormatStorageCap(InitialFormatCacheCap), ParagraphFormatStorageCap(InitialFormatCacheCap),
          NewParagraphId(1), pHeap(pheap), EntryTextFormat(pheap), Flags(flags)
    {
    }
    ~Allocator() {}

    MemoryHeap* GetHeap() const { return pHeap; }

    wchar_t* AllocText(UPInt numChar)
    {
        return (wchar_t*)SF_HEAP_ALLOC(pHeap, numChar * sizeof(wchar_t), StatRender_Text_Mem);
    }
    wchar_t* ReallocText(wchar_t* pstr, UPInt oldLength, UPInt newLength)
    {
        SF_UNUSED(oldLength);
        if (!pstr)
            return AllocText(newLength);
        return (wchar_t*)SF_REALLOC(pstr, newLength * sizeof(wchar_t), StatRender_Text_Mem);
    }
    void FreeText(wchar_t* pstr) { SF_HEAP_FREE(pHeap, pstr); }

    TextFormat*      AllocateTextFormat(const TextFormat& srcfmt);
    TextFormat*      AllocateDefaultTextFormat() { return AllocateTextFormat(EntryTextFormat); }
    ParagraphFormat* AllocateParagraphFormat(const ParagraphFormat& srcfmt);

    Paragraph* AllocateParagraph();
    Paragraph* AllocateParagraph(const Paragraph& srcPara);

    UInt32 AllocateParagraphId() { return NewParagraphId++; }
    UInt32 GetNextParagraphId()  { return NewParagraphId; }

    // (appended for Text_Core, sfr_render_03) drop the cached formats nobody else holds; true if any went
    bool FlushTextFormatCache(bool noAllocationsAllowed = false);
    bool FlushParagraphFormatCache(bool noAllocationsAllowed = false);
};

// (appended for Text_DocView, sfr_render_03b) a value computed once per format pass
template<typename T>
struct CachedPrimValue
{
    mutable T      Value;
    mutable UInt16 FormatCounter;

    CachedPrimValue() : FormatCounter(0) {}
    CachedPrimValue(T v) : Value(v), FormatCounter(0) {}

    void SetValue(T v, UInt16 counter) { Value = v; FormatCounter = counter; }
    operator T() const { return Value; }
    bool IsValid(UInt16 fmtCnt) { return FormatCounter == fmtCnt; }
};

// (appended for GFx Text_EditorKit, sfr_gfx_07) a value tagged with the format pass it was computed in; the value is
// 16-aligned (the editor's cached RectF spans 0x20 bytes)
template<typename T>
class CachedValue
{
    __declspec(align(16)) T Value;
    mutable UInt16 FormatCounter;

public:
    CachedValue() : FormatCounter(0) {}
    CachedValue(const T& v) : Value(v), FormatCounter(0) {}

    void SetValue(const T& v, UInt16 counter) { Value = v; FormatCounter = counter; }
    bool IsValid(UInt16 counter) const { return FormatCounter == counter; }
    void Invalidate() { --FormatCounter; }

    T&       operator*()        { return Value; }
    const T& operator*() const  { return Value; }
    T*       operator->()       { return &Value; }
    const T* operator->() const { return &Value; }
};

}}} // namespace Scaleform::Render::Text

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::Render::Text::Allocator) == 0x88, "Allocator size");
static_assert(sizeof(Scaleform::Render::Text::ParagraphFormat) == 0x20, "ParagraphFormat size");
static_assert(sizeof(Scaleform::Render::Text::TextFormat) == 0x48, "TextFormat size");

#endif
