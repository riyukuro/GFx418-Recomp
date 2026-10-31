// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_FontResource. The fonts a movie
// defines (FontData: DefineFont / DefineFont2 / DefineFont3 and DefineFontInfo tags, glyph shapes, code / advance /
// kerning tables), their texture glyph tables (TextureGlyphData), the binding copy of a font whose texture glyphs
// look their images up in a movie binding (FontDataBound), and the font resources of bound movies and of the system
// font provider (FontResource, under a GFxSystemFontResourceKey library key).
// MS2-UNIT: sfr_gfx_08j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426535f0-0x1426589f0 .text$mn

#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/gfx/gfx_fontresource.h"
#include "../include/gfx/gfx_shapeswf.h"
#include "../include/gfx/gfx_fontprovider.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/render/render_textureglyph.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_alg.h"
#include "../include/kernel/sf_std.h"
#include "../kernel/sf_log.h"
#include "../kernel/sf_sysalloc.h"

extern "C" void FUN_14015b310(void*, unsigned long long);

namespace Scaleform {

template<class T> static SF_FORCEINLINE T* Sfr08jDeleteTail(T* p, unsigned flags, UPInt size)
{
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            FUN_14015b310(p, size);
    }
    return p;
}

namespace GFx {

// ---- the library key of a system font: provider, lower-case name and style ----

// 0x28 bytes (vftable 0x143190fd0).
class GFxSystemFontResourceKey : public RefCountBase<GFxSystemFontResourceKey, Stat_Default_Mem>
{
public:
    Ptr<FontProvider> pFontProvider; // +0x10
    String            FontName;      // +0x18 lower case
    unsigned          FontFlags;     // +0x20 the style bits only

    GFxSystemFontResourceKey(const char* pfontName, unsigned fontFlags, FontProvider* pfontProvider)
    {
        FontName      = String(pfontName).ToLower(); // font names are case-insensitive
        FontFlags     = fontFlags & Render::Font::FF_Style_Mask;
        pFontProvider = pfontProvider;
    }
};

// The key interface of GFxSystemFontResourceKey handles (vftable 0x143190ad0; the exe's one instance is 0x143a2f690).
class GFxSystemFontResourceKeyInterface : public ResourceKey::KeyInterface
{
public:
    typedef ResourceKey::KeyHandle KeyHandle;

    // @0x1426535c0
    virtual void AddRef(KeyHandle hdata) { ((GFxSystemFontResourceKey*)hdata)->AddRef(); }
    // @0x1426535d0
    virtual void Release(KeyHandle hdata) { ((GFxSystemFontResourceKey*)hdata)->Release(); }
    // @0x1426535e0
    virtual ResourceKey::KeyType GetKeyType(KeyHandle) const { return ResourceKey::Key_None; }
    virtual UPInt GetHashCode(KeyHandle hdata) const;
    virtual bool  KeyEquals(KeyHandle hdata, const ResourceKey& other);
};

// @0x1426535f0
UPInt GFxSystemFontResourceKeyInterface::GetHashCode(KeyHandle hdata) const
{
    GFxSystemFontResourceKey* pkey = (GFxSystemFontResourceKey*)hdata;
    UPInt hashCode = String::BernsteinHashFunctionCIS(pkey->FontName.ToCStr(), pkey->FontName.GetSize());
    return pkey->FontFlags ^ ((UPInt)pkey->pFontProvider.GetPtr() >> 7) ^ (UPInt)pkey->pFontProvider.GetPtr() ^
           hashCode;
}

// @0x142653640
bool GFxSystemFontResourceKeyInterface::KeyEquals(KeyHandle hdata, const ResourceKey& other)
{
    if (this != other.GetKeyInterface())
        return false;
    GFxSystemFontResourceKey* pthisKey  = (GFxSystemFontResourceKey*)hdata;
    GFxSystemFontResourceKey* potherKey = (GFxSystemFontResourceKey*)other.GetKeyData();
    return strcmp(pthisKey->FontName.ToCStr(), potherKey->FontName.ToCStr()) == 0 &&
           pthisKey->pFontProvider == potherKey->pFontProvider && pthisKey->FontFlags == potherKey->FontFlags;
}

// The exe instance 0x143a2f690. External: sfr_atexit_01 tears it down as DAT_143a2f690.
GFxSystemFontResourceKeyInterface GFxSystemFontResourceKeyInterface_Instance;

// @0x1426536b0
void* FUN_1426536b0(GFxSystemFontResourceKeyInterface* p, unsigned flags)
{
    p->GFxSystemFontResourceKeyInterface::~GFxSystemFontResourceKeyInterface();
    if (flags & 1)
        ::operator delete(p, 8);
    return p;
}

// ---- texture glyphs bound to the images of a movie binding ----

// Gives every texture glyph that only has a bind index the image of that index (0x10 bytes, vftable 0x143190f28).
class TextureGlyphBinder : public TextureGlyphData::TextureGlyphVisitor
{
public:
    ResourceBinding* pBinding; // +0x8

    TextureGlyphBinder(ResourceBinding* pbinding) : pBinding(pbinding) {}

    virtual void Visit(unsigned index, TextureGlyph* ptextureGlyph);
};

// @0x142657c70
void TextureGlyphBinder::Visit(unsigned index, TextureGlyph* ptextureGlyph)
{
    SF_UNUSED(index);
    if (!ptextureGlyph->pImage && ptextureGlyph->BindIndex != ~0u)
    {
        ResourceBindData resData;
        pBinding->GetResourceData(&resData, ptextureGlyph->BindIndex);
        if (resData.pResource && (resData.pResource->GetResourceTypeCode() & 0xff00) == 0x100)
        {
            ptextureGlyph->pImage    = ((ImageResource*)resData.pResource.GetPtr())->GetImage();
            ptextureGlyph->BindIndex = ~0u;
        }
    }
}

// @0x142654d60
void* FUN_142654d60(TextureGlyphBinder* p, unsigned flags)
{
    p->TextureGlyphBinder::~TextureGlyphBinder();
    if (flags & 1)
        ::operator delete(p, 0x10);
    return p;
}

// @0x142654d90
void* FUN_142654d90(TextureGlyphData::TextureGlyphVisitor* p, unsigned flags)
{
    p->TextureGlyphData::TextureGlyphVisitor::~TextureGlyphVisitor();
    if (flags & 1)
        ::operator delete(p, 8);
    return p;
}

// ---- the character ranges of a font, for the font manager's diagnostics ----

namespace {

    struct Range { UInt16 start,end; };
    struct RangeLess  { bool operator()(const Range& r1, const Range& r2) const { return r1.start < r2.start; } };
} // namespace

// @0x142654f20
static String BuildStringFromRanges(const Array<Range>& ranges)
{
    String ret;
    char buff[512];
    int countPrinted = 0;
    bool lastPrinted = true;
    UInt16 start = 0;
    UPInt i = 0;
    for(; i < ranges.GetSize(); ++i)
    {
        if (i == 0)
        {
            start = ranges[i].start;
            lastPrinted = false;
        }
        else
        {
            if (ranges[i].start > ranges[i-1].end + 1)
            {
                if (start == ranges[i-1].end)
                    Format(StringDataPtr(buff, sizeof(buff)), "0x{0:x}", start);
                else
                    Format(StringDataPtr(buff, sizeof(buff)), "0x{0:x}-0x{1:x}", start, ranges[i-1].end);
                lastPrinted = true;
                if (countPrinted)
                    ret += ", ";
                ret += buff;
                countPrinted++;
                if (countPrinted > 4)
                    break;
                start = ranges[i].start;
                lastPrinted = false;
            }
        }
    }
    if (!lastPrinted)
    {
        Format(StringDataPtr(buff, sizeof(buff)), "0x{0:x}-0x{1:x}", start, ranges[ranges.GetSize()-1].end);
        if (countPrinted)
            ret += ", ";
        ret += buff;
    }
    if ( i < ranges.GetSize() )
        ret += " (truncated)";
    return ret;
}

// ---- FontData ----

// @0x1426540b0
FontData::FontData(const char* name, unsigned fontFlags) : Render::Font(fontFlags), Name(0)
{
    Name = (char*)SF_ALLOC(SFstrlen(name) + 1, StatMD_Fonts_Mem);
    if (Name)
        SFstrcpy(Name, SFstrlen(name) + 1, name);

    Flags |= 0x2000; // SetHasLayout(1)
}

// @0x1426541a0
FontData::FontData() : Render::Font(0), Name(0) {}

// @0x142654770
FontData::~FontData()
{
    Glyphs.Resize(0);
    if (Name)
    {
        SF_FREE(Name);
        Name = 0;
    }
}

// @0x142654b50
void* FUN_142654b50(FontData* p, unsigned flags)
{
    p->FontData::~FontData();
    return Sfr08jDeleteTail(p, flags, sizeof(FontData));
}

// @0x142655db0
const char* FontData::GetName() const { return Name; }

// @0x142655b80
int FontData::GetGlyphIndex(UInt16 code)
{
    UInt16 glyphIndex;
    if (CodeTable.Get(code, &glyphIndex))
    {
        return glyphIndex;
    }
    return -1;
}

// @0x142655620
float FontData::GetAdvance(unsigned glyphIndex) const
{
    if (IsMissingGlyph(glyphIndex))
        return GetNominalGlyphWidth();
    if (AdvanceTable.GetSize() == 0)
    {
        // the exe warns once here (the message is compiled out)
        static bool logged = false;
        if (!logged)
            logged = true;
        return GetNominalGlyphWidth();
    }
    if (glyphIndex < AdvanceTable.GetSize())
        return AdvanceTable[glyphIndex].Advance;
    return 0;
}

// @0x142655cb0
float FontData::GetKerningAdjustment(unsigned lastCode, unsigned thisCode) const
{
    float       adjustment;
    KerningPair k;
    k.Char0 = (UInt16)lastCode;
    k.Char1 = (UInt16)thisCode;
    if (KerningPairs.Get(k, &adjustment))
    {
        return adjustment;
    }
    return 0;
}

// @0x142655c50
float FontData::GetGlyphWidth(unsigned glyphIndex) const
{
    if (IsMissingGlyph(glyphIndex))
        return GetNominalGlyphWidth();
    if (glyphIndex < AdvanceTable.GetSize())
    {
        float w = AdvanceTable[glyphIndex].Width / 20.0f;
        if (w != 0)
            return w;
    }
    return GetAdvance(glyphIndex);
}

// @0x142655b20
float FontData::GetGlyphHeight(unsigned glyphIndex) const
{
    if (IsMissingGlyph(glyphIndex) || AdvanceTable.GetSize() == 0)
        return GetNominalGlyphHeight();
    if (glyphIndex < AdvanceTable.GetSize())
        return AdvanceTable[glyphIndex].Height / 20.0f;
    return 0;
}

// @0x142655980
RectF& FontData::GetGlyphBounds(unsigned glyphIndex, RectF* prect) const
{
    if (IsMissingGlyph(glyphIndex))
    {
        prect->x1 = prect->y1 = 0;
        prect->SetWidth(GetGlyphWidth(glyphIndex));
        prect->SetHeight(GetGlyphHeight(glyphIndex));
    }
    else if (glyphIndex < AdvanceTable.GetSize())
    {
        const AdvanceEntry& e = AdvanceTable[glyphIndex];
        float w = float(e.Width)/20.f;
        if (w == 0)
            w = e.Advance;
        float h = float(e.Height)/20.f;
        prect->x1 = float(e.Left)/20.f;
        prect->y1  = float(e.Top)/20.f;
        prect->SetWidth(w);
        prect->SetHeight(h);
    }
    else
    {
        prect->Clear();
        if (glyphIndex < Glyphs.GetSize() && Glyphs[glyphIndex])
        {
            RectF bounds(0);
            Glyphs[glyphIndex]->ComputeBound(&bounds);
            if (bounds.IsNormal())
                *prect = RectF(bounds.x1, bounds.y1, bounds.GetSize());
        }
    }
    return *prect;
}

// @0x142655e40
const Render::TextureGlyph* FontData::GetTextureGlyph(unsigned glyphIndex) const
{
    if (pTGData && glyphIndex < pTGData->GetTextureGlyphCount())
        return &pTGData->GetTextureGlyph(glyphIndex);
    return 0;
}

// @0x142655f10
void* FontData::GetTextureGlyphData() const { return pTGData.GetPtr(); }

// @0x142657c30
void FontData::SetTextureGlyphData(void* pdata) { pTGData = (TextureGlyphData*)pdata; }

// @0x142655f30
float FontData::GetTextureGlyphHeight() const
{
    if (pTGData)
        return (float)(pTGData->GetNominalSize() * 1024.0 / 1536.0);
    return 0;
}

// @0x142655df0
const Render::ShapeDataInterface* FontData::GetPermanentGlyphShape(unsigned glyphIndex) const
{
    if (glyphIndex < Glyphs.GetSize())
        return Glyphs[glyphIndex];
    return 0;
}

// @0x1426558b0
int FontData::GetCharValue(unsigned glyphIndex) const
{
    for (HashIdentityLH<UInt16, UInt16, 0x105>::ConstIterator it = CodeTable.Begin(); it != CodeTable.End(); ++it)
    {
        if (it->Second == glyphIndex)
            return it->First;
    }
    return -1;
}

// @0x142655c30
unsigned FontData::GetGlyphShapeCount() const { return (unsigned)Glyphs.GetSize(); }

// @0x142655f90
bool FontData::HasVectorOrRasterGlyphs() const { return CodeTable.GetSize() != 0; }

// @0x142655690
String FontData::GetCharRanges() const
{
    Array<Range> ranges;
    CodeTableType::ConstIterator it = CodeTable.Begin();
    UInt16 rangeStart = 0, prevValue = 0;
    bool rangeStarted = false;
    while( it != CodeTable.End() )
    {
        if (!rangeStarted)
        {
            rangeStart = it->First;
            rangeStarted = true;
        }
        else
        {
            if (prevValue != it->First-1)
            {
                Range range;
                range.start = rangeStart;
                range.end = prevValue;
                ranges.PushBack(range);
                rangeStarted = false;
                continue;
            }
        }
        prevValue = it->First;
        ++it;
    }
    if (rangeStarted)
    {
        Range range;
        range.start = rangeStart;
        range.end = prevValue;
        ranges.PushBack(range);
    }
    Alg::QuickSort(ranges, RangeLess());
    return BuildStringFromRanges(ranges);
}

// @0x1426570f0
void FontData::ReadCodeTable(Stream* in)
{
    in->LogParse("reading code table at offset %d\n", in->Tell());

    CodeTable.SetCapacity(Glyphs.GetSize());
    if (AreWideCodes())
    {
        // Code table is made of UInt16's.
        for (UPInt i = 0, n = Glyphs.GetSize(); i < n; i++)
            CodeTable.Add(in->ReadU16(), (UInt16)i);
    }
    else
    {
        // Code table is made of bytes.
        for (UPInt i = 0, n = Glyphs.GetSize(); i < n; i++)
            CodeTable.Add(in->ReadU8(), (UInt16)i);
    }
}

// @0x142657290
void FontData::ReadFontInfo(Stream* in, TagType tagType)
{
    if (Name)
    {
        SF_FREE(Name);
        Name = NULL;
    }

    Name = in->ReadStringWithLength(in->GetHeap());

    UByte flags = in->ReadU8();

    UByte langCode = 0;
    if (tagType == 0x3e) // Tag_DefineFontInfo2
    {
        langCode = in->ReadU8(); // Language code
        langCode = langCode; // suppress warning
    }

    bool pixelAlignedChars  =  ((flags & 0x20) != 0);
    bool shiftJisFlag        = ((flags & 0x10) != 0);
    bool ansiFlag            = ((flags & 0x08) != 0);

    if (shiftJisFlag)  SetCodePage(FF_CodePage_ShiftJis);
    else if (ansiFlag) SetCodePage(FF_CodePage_Ansi);
    else               SetCodePage(FF_CodePage_Unicode);
    SF_UNUSED(pixelAlignedChars);

    SetItalic       ((flags & 0x04) != 0);
    SetBold         ((flags & 0x02) != 0);
    SetWideCodes    ((flags & 0x01) != 0);

    if (in->IsVerboseParse())
    {
        if (tagType == 0xd) // Tag_DefineFontInfo
            in->LogParse("reading DefineFontInfo\n");
        else
            in->LogParse("reading DefineFontInfo2\n");
        in->LogParse("  Name = %s\n", Name ? Name : "(none)");

        const char* pcodePage = "Unicode";
        if (GetCodePage() == FF_CodePage_ShiftJis)
            pcodePage = "ShiftJIS";
        else if (GetCodePage() == FF_CodePage_Ansi)
            pcodePage = "ANSI";

        in->LogParse("  CodePage = %s, Italic = %d, Bold = %d\n",
            pcodePage, IsItalic(), IsBold());
        if (tagType == 0x3e)
            in->LogParse("  LangCode = %d\n", langCode);
    }

    ReadCodeTable(in);
}

// MS2-FUNCTIONAL 0x142655fe0: register allocation and frame (0x118 vs 0xf8); the exe calls 0x142657480 out of line in the DefineFont branch
// @0x142655fe0
void FontData::Read(LoadProcess* p, const TagInfo& tagInfo)
{
    Stream *    pin = p->GetStream();
    bool        isLoadingFontShapes = p->IsLoadingFontShapes();
    MemoryHeap* pheap = p->GetLoadHeap();

    // No AddRef() here, to avoid cycle.
    // OwningMovie is our owner, so it has a ref to us.
    //OwningMovie = p->GetDataDef();    

    if (tagInfo.TagType == (TagType)10)
    {
        pin->LogParse("reading DefineFont\n");

        int tableBase = pin->Tell();

        // Read the glyph offsets.  Offsets
        // are measured from the start of the
        // offset table.
        Array<int>    offsets;
        offsets.PushBack(pin->ReadU16());
        pin->LogParse("offset[0] = %d\n", offsets[0]);
        int count = offsets[0] >> 1;
        for (int i = 1; i < count; i++)
        {
            UInt16 off = pin->ReadU16();
            if (off == 0)
            {
                // special case for tag with stripped font shapes
                isLoadingFontShapes = false;
                break;
            }
            offsets.PushBack(off);
            pin->LogParse("offset[%d] = %d\n", i, offsets[i]);
        }

        Glyphs.Resize(count);
      //  TextureGlyphs.Resize(Glyphs.GetSize());

        if (isLoadingFontShapes)
        {
            // Read the glyph shapes.
            for (int i = 0; i < count; i++)
            {
                // Seek to the start of the shape data.
                int newPos = tableBase + offsets[i];
                pin->SetPosition(newPos);
                
                SPInt shapeDataLen;
                if (i + 1 < count)
                    shapeDataLen = offsets[i + 1] - offsets[i];
                else
                    shapeDataLen = tagInfo.TagDataOffset + tagInfo.TagLength - newPos;

                // Create & read the shape.
                Ptr<ConstShapeNoStyles> s = *SF_HEAP_NEW_ID(pheap, 0x104 /* StatMD_ShapeData_Mem */) ConstShapeNoStyles;
                s->Read(p, (TagType)2, (unsigned)shapeDataLen, false);

                Glyphs[i] = s;
            }
        }
        else
            SetGlyphShapesStripped();
    }
    else if ((tagInfo.TagType == (TagType)0x30) || (tagInfo.TagType == (TagType)0x4b))
    {
        if (tagInfo.TagType == (TagType)0x30)
            pin->LogParse("reading DefineFont2: ");
        else
            pin->LogParse("reading DefineFont3: ");

        bool    hasLayout = (pin->ReadUInt(1) != 0);
        SetHasLayout(hasLayout);

        bool shiftJisFlag        = (pin->ReadUInt(1) != 0);
        bool pixelAlignedChars   = (pin->ReadUInt(1) != 0);
        bool ansiFlag            = (pin->ReadUInt(1) != 0);

        if (shiftJisFlag)  SetCodePage(FF_CodePage_ShiftJis);
        else if (ansiFlag) SetCodePage(FF_CodePage_Ansi);
        else               SetCodePage(FF_CodePage_Unicode);
        
        SetPixelAligned(pixelAlignedChars);
        
        bool    wideOffsets = (pin->ReadUInt(1) != 0);
        SetWideCodes(pin->ReadUInt(1) != 0);
        SetItalic(pin->ReadUInt(1) != 0);
        SetBold(pin->ReadUInt(1) != 0);
        UByte   langCode = pin->ReadU8(); // Language code

        // Inhibit warning.
        langCode = langCode;

        Name = pin->ReadStringWithLength(p->GetLoadHeap());

        int glyphCount = pin->ReadU16();

        if (pin->IsVerboseParse())
        {
            pin->LogParse("  Name = %s, %d glyphs\n", Name ? Name : "(none)", glyphCount);

            const char* pcodePage = "Unicode";
            if (GetCodePage() == FF_CodePage_ShiftJis)
                pcodePage = "ShiftJIS";
            else if (GetCodePage() == FF_CodePage_Ansi)
                pcodePage = "ANSI";

            pin->LogParse("  HasLayout = %d, CodePage = %s, Italic = %d, Bold = %d\n", 
                (int)hasLayout, pcodePage, IsItalic(), IsBold());
            pin->LogParse("  LangCode = %d\n", langCode);
        }

        
        int tableBase = pin->Tell();

        // Read the glyph offsets.  Offsets
        // are measured from the start of the
        // offset table.
        Array<int>    offsets;
        int fontCodeOffset;

        int offsetsCount = glyphCount;
        if (glyphCount > 0)
        {
            // check for the first offset. If it is 0 then shapes
            // were stripped from the tag.
            unsigned off0 = (wideOffsets) ? (unsigned)pin->ReadU32() : (unsigned)pin->ReadU16();
            if (off0 == 0)
            {
                // special case for tags with stripped font shapes
                isLoadingFontShapes = false;
                offsetsCount = 0;
            }
            else
            {
                offsets.PushBack(off0);
                //pin->LogParse("offset[0] = %d\n", offsets[0]);
            }
        }
        if (wideOffsets)
        {
            // 32-bit offsets.
            for (int i = 1; i < offsetsCount; i++)
            {
                offsets.PushBack(pin->ReadU32());
                //pin->LogParse("offset[%d] = %d\n", i, offsets[i]);
            }
            fontCodeOffset = pin->ReadU32();
        }
        else
        {
            // 16-bit offsets.
            for (int i = 1; i < offsetsCount; i++)
            {
                offsets.PushBack(pin->ReadU16());
                //pin->LogParse("offset[%d] = %d\n", i, offsets[i]);
            }
            fontCodeOffset = pin->ReadU16();
        }

        Glyphs.Resize(glyphCount);
    //    TextureGlyphs.Resize(Glyphs.GetSize());

        if (isLoadingFontShapes)
        {
            TagType fontGlyphShapeTag = (tagInfo.TagType == (TagType)0x30) ?
                                           (TagType)0x16 : tagInfo.TagType;

            if (hasLayout)
            {
                AdvanceTable.Resize(glyphCount);
            }

            // Read the glyph shapes.
            for (int i = 0; i < glyphCount; i++)
            {
                // Seek to the start of the shape data.
                int newPos = tableBase + offsets[i];
                // if we're seeking backwards, then that looks like a bug.
                pin->SetPosition(newPos);

                SPInt shapeDataLen;
                if (i + 1 < glyphCount)
                    shapeDataLen = offsets[i + 1] - offsets[i];
                else
                    shapeDataLen = fontCodeOffset - offsets[i];

                // Create & read the shape.
                Ptr<ConstShapeNoStyles> s = *SF_HEAP_NEW_ID(pheap, StatMD_Fonts_Mem) ConstShapeNoStyles;
                if (!s->Read(p, fontGlyphShapeTag, (unsigned)shapeDataLen, false))
                {
                    // error occurred; correct number of glyphs and break
                    glyphCount = i;
                    AdvanceTable.Resize(i);
                    Glyphs.Resize(i);
                    return;
                }

                Glyphs[i] = s;

                if (hasLayout)
                {
                    RectF bounds;
                    s->ComputeBound(&bounds);
                    AdvanceEntry& ge = AdvanceTable[i];
                    if (bounds.IsNormal())
                    {
                        float left = bounds.x1;
                        float top  = bounds.y1;
                        float w = bounds.Width();
                        float h = bounds.Height();
                        /*
                            */
                        ge.Left    = (SInt16)(left * 20.f);
                        ge.Top     = (SInt16)(top * 20.f);
                        ge.Width   = (UInt16)(w * 20.f);
                        ge.Height  = (UInt16)(h * 20.f);
                    }
                    else
                    {
                        ge.Left  = ge.Top = 0;
                        ge.Width = ge.Height = 0;
                    }
                }
                //@DBG
                //RectF bounds;
                //s->ComputeBound(&bounds);
                //if (bounds.IsNormal())
                //{
                //    pin->LogParse("  chidx = %d, bounds = (%f, %f, {%f, %f}\n", 
                //        (int)i, bounds.x1, bounds.y1, bounds.Width(), bounds.Height());
                //}
            }

            int currentPosition = pin->Tell();
            if (fontCodeOffset + tableBase != currentPosition)
            {
                // Bad offset!  Don't try to read any more.
                return;
            }
        }
        else
        {
            // Skip the shape data.
            int newPos = tableBase + fontCodeOffset;
            if (newPos >= pin->GetTagEndPosition())
            {
                // No layout data!
                return;
            }

            pin->SetPosition(newPos);
            SetGlyphShapesStripped();
        }

        ReadCodeTable(pin);

        // Read layout info for the glyphs.
        if (hasLayout)
        {
            // Multiplier used for scaling.
            // In SWF 8, font shape constant resolution (tag 75) was increased by 20.
            float sfactor = (tagInfo.TagType == (TagType)0x4b)  ? 1.0f / 20.0f : 1.0f;

            Ascent = (float) pin->ReadS16() * sfactor;
            Descent = (float) pin->ReadS16() * sfactor;
            Leading = (float) pin->ReadS16() * sfactor;
            
            if (pin->IsVerboseParse())
            {
                pin->LogParse("  Ascent = %d, Descent = %d, Leading = %d\n", 
                    (int)Ascent, (int)Descent, (int)Leading);
            }

            // Advance table; i.E. how wide each character is.
            if (AdvanceTable.GetSize() != Glyphs.GetSize())
                AdvanceTable.Resize(Glyphs.GetSize());
            for (UPInt i = 0, n = AdvanceTable.GetSize(); i < n; i++)
            {
                AdvanceEntry& ge = AdvanceTable[i];
                ge.Advance = (float) pin->ReadU16() * sfactor;
            }

            // Bounds table.
            //BoundsTable.Resize(Glyphs.GetSize());    // kill
            RectF  dummyRect;
            {for (UPInt i = 0, n = Glyphs.GetSize(); i < n; i++)
            {
                //BoundsTable[i].Read(pin);  // kill
                pin->ReadRect(&dummyRect);                   
            }}

            // Kerning pairs.
            int kerningCount = pin->ReadU16();
            if (pin->IsVerboseParse())
            {
                pin->LogParse("  KerningCount = %d\n", (int)kerningCount);
            }
            for (int i = 0; i < kerningCount; i++)
            {
                int off = pin->Tell();
                if (off >= tagInfo.TagDataOffset + tagInfo.TagLength)
                {
                    pin->LogError("Corrupted file %s, kerning table of the font '%s' is longer than tagLength.",
                                  pin->GetFileName().ToCStr(), (Name) ? Name : "<noname>");
                    break;
                }

                UInt16  char0, char1;
                if (AreWideCodes())
                {
                    char0 = pin->ReadU16();
                    char1 = pin->ReadU16();
                }
                else
                {
                    char0 = pin->ReadU8();
                    char1 = pin->ReadU8();
                }
                float   adjustment = (float) pin->ReadS16() * sfactor;

                KerningPair k;
                k.Char0 = char0;
                k.Char1 = char1;

                if (pin->IsVerboseParse())
                    pin->LogParse("     Pair: %d - %d,\tadj = %d\n", (int)char0, (int)char1, (int)adjustment);

                // Remember this adjustment; we can look it up quickly
                // later using the character pair as the key.
                KerningPairs.Add(k, adjustment);
            }
        }
        if (!isLoadingFontShapes && AdvanceTable.GetSize() > 0)
        {
            // reset glyphRects if no FontShapes loaded
            for (UPInt i = 0, n = AdvanceTable.GetSize(); i < n; i++)
            {
                AdvanceEntry& ge = AdvanceTable[i];
                ge.Left = ge.Top = ge.Height = ge.Width = 0;
            }
        }
    }
}

// ---- TextureGlyphData ----

// @0x142654480
TextureGlyphData::TextureGlyphData(const TextureGlyphData& src)
    : RefCountBaseNTS<TextureGlyphData, StatMD_Fonts_Mem>(), PackTextureConfig(src.PackTextureConfig),
      FileCreation(src.FileCreation)
{
    TextureGlyphs.Resize(src.TextureGlyphs.GetSize());
    for (UPInt i = 0, n = src.TextureGlyphs.GetSize(); i < n; ++i)
    {
        TextureGlyphs[i] = src.TextureGlyphs[i];
    }
    ImageResourceHash::ConstIterator iter = src.GlyphsTextures.Begin();
    for (; iter != src.GlyphsTextures.End(); ++iter)
    {
        GlyphsTextures.Set(iter->First, iter->Second);
    }
}

// @0x142654dc0
void TextureGlyphData::AddTexture(ResourceId textureId, const ResourceHandle& rh)
{
    ResourcePtr<ImageResource> pimage;
    pimage.SetFromHandle(rh);
    GlyphsTextures.Set(textureId, pimage);
}

// @0x142654e60
void TextureGlyphData::AddTexture(ResourceId textureId, ImageResource* pimageRes)
{
    GlyphsTextures.Set(textureId, ResourcePtr<ImageResource>(pimageRes));
}

// @0x142654ec0
void TextureGlyphData::AddTextureGlyph(unsigned glyphIndex, const TextureGlyph& glyph)
{
    if (TextureGlyphs.GetSize() <= glyphIndex)
    {
        TextureGlyphs.Resize(glyphIndex + 1);
        if (TextureGlyphs.GetSize() <= glyphIndex)
            return;
    }
    TextureGlyphs[glyphIndex] = glyph;
}

// The empty glyph handed out past the end (0x143a2f650; sfr_atexit_01's FUN_142cc9540 is its exit dtor).
extern "C" TextureGlyph DAT_143a2f650;
TextureGlyph DAT_143a2f650;

// MS2-FUNCTIONAL 0x142655e80: the exe builds the empty glyph on first use (thread-safe guard, atexit FUN_142cc9540);
// here it is a namespace-scope object
// @0x142655e80
SF_NOINLINE const TextureGlyph& TextureGlyphData::GetTextureGlyph(unsigned glyphIndex) const
{
    if (glyphIndex < TextureGlyphs.GetSize())
        return TextureGlyphs[glyphIndex];
    return DAT_143a2f650;
}

// @0x142657d70
void TextureGlyphData::VisitTextureGlyphs(TextureGlyphVisitor* pvisitor)
{
    for (UPInt i = 0, n = TextureGlyphs.GetSize(); i < n; ++i)
        pvisitor->Visit((unsigned)i, &TextureGlyphs[i]);
}

// @0x142657de0
void TextureGlyphData::VisitTextures(TexturesVisitor* pvisitor, ResourceBinding* pbinding)
{
    ImageResourceHash::ConstIterator iter = GlyphsTextures.Begin();
    for (; iter != GlyphsTextures.End(); ++iter)
    {
        Resource* pres = (*pbinding)[iter->Second];
        pvisitor->Visit(iter->First, (ImageResource*)pres);
    }
}

// @0x142657f70
void TextureGlyphData::WipeTextureGlyphs()
{
    TextureGlyph defaultTg;
    for (UPInt i = 0, n = TextureGlyphs.GetSize(); i < n; i++)
        TextureGlyphs[i] = defaultTg;
}

} // namespace GFx

namespace Render {

// @0x142654a10
TextureGlyph& TextureGlyph::operator=(const TextureGlyph& src)
{
    pImage    = src.pImage;
    UvBounds  = src.UvBounds;
    UvOrigin  = src.UvOrigin;
    BindIndex = src.BindIndex;
    return *this;
}

} // namespace Render

namespace GFx {

// ---- FontDataBound ----

// @0x142654210
FontDataBound::FontDataBound(Render::Font* pfont, ResourceBinding* pbinding)
    : Render::Font(*pfont), pFont(pfont), pTGData()
{
    // make a copy of TextureGlyphData and resolve image resources in it.
    const TextureGlyphData* srcTGData = static_cast<const TextureGlyphData*>(pfont->GetTextureGlyphData());
    pTGData = *SF_HEAP_AUTO_NEW(this) TextureGlyphData(*srcTGData);

    TextureGlyphBinder binder(pbinding);
    pTGData->VisitTextureGlyphs(&binder);
}

// @0x142654bb0
void* FUN_142654bb0(FontDataBound* p, unsigned flags)
{
    p->FontDataBound::~FontDataBound();
    return Sfr08jDeleteTail(p, flags, sizeof(FontDataBound));
}

// @0x142655dc0
const char* FontDataBound::GetName() const { return pFont->GetName(); }
// @0x142655c10
int FontDataBound::GetGlyphIndex(UInt16 code) { return pFont->GetGlyphIndex(code); }
// @0x142655680
float FontDataBound::GetAdvance(unsigned glyphIndex) const { return pFont->GetAdvance(glyphIndex); }
// @0x142655d80
float FontDataBound::GetKerningAdjustment(unsigned lastCode, unsigned thisCode) const
{
    return pFont->GetKerningAdjustment(lastCode, thisCode);
}
// @0x142655ca0
float FontDataBound::GetGlyphWidth(unsigned glyphIndex) const { return pFont->GetGlyphWidth(glyphIndex); }
// @0x142655b70
float FontDataBound::GetGlyphHeight(unsigned glyphIndex) const { return pFont->GetGlyphHeight(glyphIndex); }
// @0x142655b10
RectF& FontDataBound::GetGlyphBounds(unsigned glyphIndex, RectF* prect) const
{
    return pFont->GetGlyphBounds(glyphIndex, prect);
}
// @0x142655fd0
bool FontDataBound::IsHintedVectorGlyph(unsigned glyphIndex, unsigned hintedSize) const
{
    return pFont->IsHintedVectorGlyph(glyphIndex, hintedSize);
}
// @0x142655fc0
bool FontDataBound::IsHintedRasterGlyph(unsigned glyphIndex, unsigned hintedSize) const
{
    return pFont->IsHintedRasterGlyph(glyphIndex, hintedSize);
}
// @0x142655e60
const TextureGlyph* FontDataBound::GetTextureGlyph(unsigned glyphIndex) const
{
    if (pTGData && glyphIndex < pTGData->GetTextureGlyphCount())
        return &pTGData->GetTextureGlyph(glyphIndex);
    return 0;
}
// @0x142655f20
void* FontDataBound::GetTextureGlyphData() const { return pTGData.GetPtr(); }
// @0x142655f60
float FontDataBound::GetTextureGlyphHeight() const { return pFont->GetTextureGlyphHeight(); }
// @0x142655e10
const Render::ShapeDataInterface* FontDataBound::GetPermanentGlyphShape(unsigned glyphIndex) const
{
    return pFont->GetPermanentGlyphShape(glyphIndex);
}
// @0x142655e30
bool FontDataBound::GetTemporaryGlyphShape(unsigned glyphIndex, unsigned hintedSize, Render::GlyphShape* shape)
{
    return pFont->GetTemporaryGlyphShape(glyphIndex, hintedSize, shape);
}
// @0x142655c20
bool FontDataBound::GetGlyphRaster(unsigned glyphIndex, unsigned hintedSize, Render::GlyphRaster* raster)
{
    return pFont->GetGlyphRaster(glyphIndex, hintedSize, raster);
}
// @0x142655970
int FontDataBound::GetCharValue(unsigned glyphIndex) const { return pFont->GetCharValue(glyphIndex); }
// @0x142655c40
unsigned FontDataBound::GetGlyphShapeCount() const { return pFont->GetGlyphShapeCount(); }
// @0x142655fb0
bool FontDataBound::HasVectorOrRasterGlyphs() const { return pFont->HasVectorOrRasterGlyphs(); }
// @0x142655890
String FontDataBound::GetCharRanges() const { return pFont->GetCharRanges(); }
// @0x142655de0
float FontDataBound::GetNominalGlyphWidth() const { return pFont->GetNominalGlyphWidth(); }
// @0x142655dd0
float FontDataBound::GetNominalGlyphHeight() const { return pFont->GetNominalGlyphHeight(); }

// ---- FontResource ----

// @0x142654350
FontResource::FontResource(Render::Font* pfont, const ResourceKey& key) : pFont(), pBinding(0), FontKey()
{
    pFont        = pfont;
    FontKey      = key;
    LowerCaseTop = UpperCaseTop = 0;
}

// @0x142654400
FontResource::FontResource(Render::Font* pfont, ResourceBinding* pbinding) : pFont(), pBinding(pbinding), FontKey()
{
    pFont        = pfont;
    LowerCaseTop = UpperCaseTop = 0;
}

// @0x1426548f0
FontResource::~FontResource() {}

// @0x142654c40
void* FUN_142654c40(FontResource* p, unsigned flags)
{
    p->FontResource::~FontResource();
    return Sfr08jDeleteTail(p, flags, sizeof(FontResource));
}

// @0x142655d90
ResourceKey FontResource::GetKey() { return FontKey; }

// @0x1426554d0
ResourceKey FontResource::CreateFontResourceKey(const char* pfontName, unsigned fontFlags, FontProvider* pfontProvider)
{
    Ptr<GFxSystemFontResourceKey> pkey = *SF_NEW GFxSystemFontResourceKey(pfontName, fontFlags, pfontProvider);
    return ResourceKey(&GFxSystemFontResourceKeyInterface_Instance, pkey.GetPtr());
}

// @0x142654cd0
void* FUN_142654cd0(GFxSystemFontResourceKey* p, unsigned flags)
{
    p->GFxSystemFontResourceKey::~GFxSystemFontResourceKey();
    return Sfr08jDeleteTail(p, flags, sizeof(GFxSystemFontResourceKey));
}

// @0x142655240
FontResource* FontResource::CreateFontResource(const char* pfontName, unsigned fontFlags, FontProvider* pfontProvider,
                                               ResourceWeakLib* plib)
{
    ResourceKey             fontKey = CreateFontResourceKey(pfontName, fontFlags, pfontProvider);
    ResourceLib::BindHandle bh;
    FontResource*           pfontRes = 0;
    if (plib->BindResourceKey(&bh, fontKey) == ResourceLib::RS_NeedsResolve)
    {
        Ptr<Render::Font> pfont = *pfontProvider->CreateFont(pfontName, fontFlags);
        if (pfont)
            pfontRes = SF_NEW FontResource(pfont.GetPtr(), fontKey);
        if (pfontRes)
            bh.ResolveResource(pfontRes);
        else
            bh.CancelResolve("");
    }
    else
        pfontRes = (FontResource*)bh.WaitForResolve();
    return pfontRes;
}

// @0x142657940
void FontResource::ResolveTextureGlyphs()
{
    if (pFont->GetTextureGlyphData())
        pFont = *SF_HEAP_AUTO_NEW(this) FontDataBound(pFont.GetPtr(), pBinding);
}

// @0x142658230
UInt16 FontResource::calcTopBound(UInt16 code)
{
    RectF bounds(0);
    int   glyphIndex = pFont->GetGlyphIndex(code);
    if (glyphIndex != -1)
    {
        pFont->GetGlyphBounds(glyphIndex, &bounds);
        return (UInt16)(int)(-bounds.y1);
    }
    return 0;
}

// @0x142658080
void FontResource::calcLowerUpperTop(Log* log)
{
    SInt16 lowerCaseTop = 0;
    SInt16 upperCaseTop = 0;
    if (pFont && LowerCaseTop == 0 && UpperCaseTop == 0)
    {
        const UByte upperCaseCandidates[] = "HEFTUVWXZ";
        const UByte lowerCaseCandidates[] = "zxvwy";

        const UByte* p;
        for (p = upperCaseCandidates; *p; ++p)
        {
            upperCaseTop = calcTopBound(*p);
            if (upperCaseTop)
                break;
        }

        if (upperCaseTop)
        {
            for (p = lowerCaseCandidates; *p; ++p)
            {
                lowerCaseTop = calcTopBound(*p);
                if (lowerCaseTop)
                    break;
            }
        }
    }
    if (lowerCaseTop && upperCaseTop)
    {
        LowerCaseTop = lowerCaseTop;
        UpperCaseTop = upperCaseTop;
    }
    else
    {
        if (log)
            log->LogWarning("Font '%s%s%s' has no hinting chars "
                            "(any of 'HEFTUVWXZ' and 'zxvwy'). Auto-Hinting disabled.",
                            GetName(),
                            pFont->IsBold() ? " Bold" : "",
                            pFont->IsItalic() ? " Italic" : "");
        LowerCaseTop = -1;
        UpperCaseTop = -1;
    }
}

// ---- RefCountImpl leftovers of the unit (vftable and count only) ----

// @0x142654a90
void* FUN_142654a90(RefCountImplCore* p, unsigned flags)
{
    p->RefCountImplCore::~RefCountImplCore();
    return Sfr08jDeleteTail(p, flags, 0x10);
}

// @0x142654af0
void* FUN_142654af0(RefCountImplCore* p, unsigned flags)
{
    p->RefCountImplCore::~RefCountImplCore();
    return Sfr08jDeleteTail(p, flags, 0x10);
}

} // namespace GFx
} // namespace Scaleform

// MS2-PIN: ??_7FontData@GFx@Scaleform@@6B@ 0x143190b18
// MS2-PIN: ??_7FontDataBound@GFx@Scaleform@@6B@ 0x143190bd0
// MS2-PIN: ??_7FontResource@GFx@Scaleform@@6B@ 0x143190c88
// MS2-PIN: ??_7GFxSystemFontResourceKey@GFx@Scaleform@@6B@ 0x143190fd0
// MS2-PIN: ??_7GFxSystemFontResourceKeyInterface@GFx@Scaleform@@6B@ 0x143190ad0
// MS2-PIN: ??_7TextureGlyphBinder@GFx@Scaleform@@6B@ 0x143190f28
// MS2-PIN: ??_7TextureGlyphVisitor@TextureGlyphData@GFx@Scaleform@@6B@ 0x143190b08
// MS2-PIN: ??_7KeyInterface@ResourceKey@GFx@Scaleform@@6B@ 0x14318b240
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EP@@Scaleform@@6B@ 0x1431901f0
// MS2-PIN: ??_7?$RefCountBase@VFont@Render@Scaleform@@$0EP@@Scaleform@@6B@ 0x1431902b0
// MS2-PIN: ??_7Font@Render@Scaleform@@6B@ 0x1431901f8
// MS2-PIN: ??_7?$RefCountBase@VTextureGlyph@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318a2a8
// MS2-PIN: ??_7TextureGlyph@Render@Scaleform@@6B@ 0x14318a2b0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BAF@@Scaleform@@6B@ 0x14318a2b8
// MS2-PIN: ??_7?$RefCountBaseNTS@VTextureGlyphData@GFx@Scaleform@@$0BAF@@Scaleform@@6B@ 0x14318a2c0
// MS2-PIN: ??_7TextureGlyphData@GFx@Scaleform@@6B@ 0x14318a2c8
// MS2-PIN: ??_7ConstShapeNoStyles@GFx@Scaleform@@6B@ 0x14318b708
// MS2-PIN: ??_7?$RefCountBase@VGFxSystemFontResourceKey@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143190fc8
