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
        : pFontProvider(pfontProvider), FontName(String(pfontName).ToLower()),
          FontFlags(fontFlags & Render::Font::FF_Style_Mask)
    {
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
        operator delete(p);
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
        operator delete(p);
    return p;
}

// @0x142654d90
void* FUN_142654d90(TextureGlyphData::TextureGlyphVisitor* p, unsigned flags)
{
    p->TextureGlyphData::TextureGlyphVisitor::~TextureGlyphVisitor();
    if (flags & 1)
        operator delete(p);
    return p;
}

// ---- the character ranges of a font, for the font manager's diagnostics ----

namespace {

struct Range
{
    UInt16 First, Last;
};

struct RangeLess
{
    bool operator()(const Range& a, const Range& b) const { return a.First < b.First; }
};

} // namespace

// "0x41-0x5a, 0x61-0x7a, ...": at most five pieces, then " (truncated)".
// @0x142654f20
static String BuildStringFromRanges(const Array<Range>& ranges)
{
    String result;
    UInt16 first  = 0;
    bool   none   = true;
    int    pieces = 0;
    UPInt  i;
    for (i = 0; i < ranges.GetSize(); ++i)
    {
        if (i == 0)
        {
            first = ranges[0].First;
            none  = false;
        }
        else if ((unsigned)ranges[i - 1].Last + 1 < ranges[i].First)
        {
            char buf[512];
            if (first == ranges[i - 1].Last)
                Format(StringDataPtr(buf, sizeof(buf)), "0x{0:x}", first);
            else
                Format(StringDataPtr(buf, sizeof(buf)), "0x{0:x}-0x{1:x}", first, ranges[i - 1].Last);
            if (pieces)
                result += ", ";
            result += buf;
            if (++pieces >= 5)
                break;
            first = ranges[i].First;
        }
    }
    if (i >= ranges.GetSize() && !none)
    {
        char buf[512];
        Format(StringDataPtr(buf, sizeof(buf)), "0x{0:x}-0x{1:x}", first, ranges[ranges.GetSize() - 1].Last);
        if (pieces)
            result += ", ";
        result += buf;
    }
    if (i < ranges.GetSize())
        result += " (truncated)";
    return result;
}

// ---- FontData ----

// @0x1426540b0
FontData::FontData(const char* name, unsigned fontFlags) : Render::Font(fontFlags), Name(0)
{
    UPInt size = SFstrlen(name) + 1;
    Name       = (char*)SF_ALLOC(size, StatMD_Fonts_Mem);
    if (Name)
        strcpy_s(Name, size, name);
    Flags |= 0x2000; // FF_HasLayout
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

// MS2-FUNCTIONAL 0x142655b80: the hash lookup result is materialized through the found-value pointer (cmove); same lookup and default
// @0x142655b80
int FontData::GetGlyphIndex(UInt16 code)
{
    const UInt16* pindex = CodeTable.Get(code);
    return pindex ? *pindex : -1;
}

// MS2-FUNCTIONAL 0x142655620: the exe compares the 16-bit index with an imm16 cmp where our compiler loads 0xffff into a register; same logic
// @0x142655620
float FontData::GetAdvance(unsigned glyphIndex) const
{
    if ((UInt16)glyphIndex == 0xffff)
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

// MS2-FUNCTIONAL 0x142655cb0: register allocation and the 0xffff compare form differ; same kerning-pair lookup
// @0x142655cb0
float FontData::GetKerningAdjustment(unsigned lastCode, unsigned thisCode) const
{
    KerningPair k;
    k.Char0            = (UInt16)lastCode;
    k.Char1            = (UInt16)thisCode;
    const float* padj = KerningPairs.Get(k);
    return padj ? *padj : 0;
}

// MS2-FUNCTIONAL 0x142655c50: the exe compares the 16-bit index with an imm16 cmp; same logic
// @0x142655c50
float FontData::GetGlyphWidth(unsigned glyphIndex) const
{
    if ((UInt16)glyphIndex == 0xffff)
        return GetNominalGlyphWidth();
    if (glyphIndex < AdvanceTable.GetSize())
    {
        float w = AdvanceTable[glyphIndex].Width / 20.0f;
        if (w != 0)
            return w;
    }
    return GetAdvance(glyphIndex);
}

// MS2-FUNCTIONAL 0x142655b20: the exe compares the 16-bit index with an imm16 cmp; same logic
// @0x142655b20
float FontData::GetGlyphHeight(unsigned glyphIndex) const
{
    if ((UInt16)glyphIndex == 0xffff || AdvanceTable.GetSize() == 0)
        return GetNominalGlyphHeight();
    if (glyphIndex < AdvanceTable.GetSize())
        return AdvanceTable[glyphIndex].Height / 20.0f;
    return 0;
}

// @0x142655980
RectF& FontData::GetGlyphBounds(unsigned glyphIndex, RectF* prect) const
{
    if ((UInt16)glyphIndex == 0xffff)
    {
        prect->x1 = prect->y1 = 0;
        prect->SetWidth(GetGlyphWidth(glyphIndex));
        prect->SetHeight(GetGlyphHeight(glyphIndex));
    }
    else if (glyphIndex < AdvanceTable.GetSize())
    {
        const AdvanceEntry& e = AdvanceTable[glyphIndex];
        float w = e.Width / 20.0f;
        if (w == 0)
            w = e.Advance;
        float h   = e.Height / 20.0f;
        prect->x1 = e.Left / 20.0f;
        prect->SetWidth(w);
        prect->y1 = e.Top / 20.0f;
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

// MS2-FUNCTIONAL 0x142655690: our compiler splits the function into chunks with a different frame (0x68 vs 0x50); same range building
// @0x142655690
String FontData::GetCharRanges() const
{
    Array<Range> ranges;
    bool         inRange = false;
    UInt16       first = 0, last = 0;
    for (HashIdentityLH<UInt16, UInt16, 0x105>::ConstIterator it = CodeTable.Begin(); it != CodeTable.End(); ++it)
    {
        UInt16 code = it->First;
        if (!inRange)
        {
            first = last = code;
            inRange      = true;
        }
        else if (code == last + 1)
            last = code;
        else
        {
            Range r = { first, last };
            ranges.PushBack(r);
            first = last = code;
        }
    }
    if (inRange)
    {
        Range r = { first, last };
        ranges.PushBack(r);
    }
    Alg::QuickSortSliced(ranges, 0, ranges.GetSize(), RangeLess());
    return BuildStringFromRanges(ranges);
}

// @0x1426570f0
void FontData::ReadCodeTable(Stream* in)
{
    in->LogParse("reading code table at offset %d\n", in->Tell());

    UPInt glyphCount = Glyphs.GetSize();
    CodeTable.SetCapacity(glyphCount);
    if (Flags & 0x4000) // wide codes
    {
        for (UPInt i = 0; i < glyphCount; ++i)
        {
            UInt16 code = in->ReadU16();
            CodeTable.Add(code, (UInt16)i);
        }
    }
    else
    {
        for (UPInt i = 0; i < glyphCount; ++i)
        {
            UInt16 code = in->ReadU8();
            CodeTable.Add(code, (UInt16)i);
        }
    }
}

// @0x142657290
void FontData::ReadFontInfo(Stream* in, TagType tagType)
{
    if (Name)
    {
        SF_FREE(Name);
        Name = 0;
    }
    Name = in->ReadStringWithLength(in->GetHeap());

    UByte flags    = in->ReadU8();
    UByte langCode = 0;
    if (tagType == 0x3e) // DefineFontInfo2
        langCode = in->ReadU8();

    Flags &= ~0x300u;
    if (flags & 0x10)
        Flags |= 0x200; // Shift-JIS
    else if (flags & 0x8)
        Flags |= 0x100; // ANSI
    if (flags & 0x4)
        Flags |= 0x1;
    else
        Flags &= ~0x1u;
    if (flags & 0x2)
        Flags |= 0x2;
    else
        Flags &= ~0x2u;
    if (flags & 0x1)
        Flags |= 0x4000;
    else
        Flags &= ~0x4000u;

    if (in->IsVerboseParse())
    {
        in->LogParse(tagType == 0xd ? "reading DefineFontInfo\n" : "reading DefineFontInfo2\n");
        in->LogParse("  Name = %s\n", Name ? Name : "(none)");
        unsigned codePage = Flags & 0x300;
        in->LogParse("  CodePage = %s, Italic = %d, Bold = %d\n",
                     codePage == 0x200 ? "ShiftJIS" : (codePage == 0x100 ? "ANSI" : "Unicode"), Flags & 1,
                     (Flags >> 1) & 1);
        if (tagType == 0x3e)
            in->LogParse("  LangCode = %d\n", langCode);
    }

    ReadCodeTable(in);
}

// @0x142655fe0
void FontData::Read(LoadProcess* p, const TagInfo& tagInfo)
{
    TagType     tagType = tagInfo.TagType;
    Stream*     in      = p->GetStream();
    MemoryHeap* heap    = p->GetLoadHeap();
    bool        ok      = true;

    if (tagType == 10) // DefineFont
    {
        in->LogParse("reading DefineFont\n");

        int           tableBase = in->Tell();
        Array<UInt32> offsets;
        offsets.PushBack(in->ReadU16());
        in->LogParse("offset[0] = %d\n", offsets[0]);
        int count = offsets[0] >> 1;
        for (int i = 1; i < count; ++i)
        {
            UInt16 off = in->ReadU16();
            if (off == 0)
            {
                ok = false;
                break;
            }
            offsets.PushBack(off);
            in->LogParse("offset[%d] = %d\n", i, offsets[i]);
        }

        Glyphs.Resize(count);
        if (!ok)
            Flags |= 0x1000; // glyph shapes stripped
        else
        {
            for (int i = 0; i < count; ++i)
            {
                in->SetPosition(tableBase + offsets[i]);
                int len = (i + 1 < count) ? (int)(offsets[i + 1] - offsets[i])
                                          : (int)(tagInfo.TagDataOffset + tagInfo.TagLength - (offsets[i] + tableBase));
                Ptr<ShapeDataBase> pshape = *SF_HEAP_NEW(heap) ConstShapeNoStyles();
                pshape->Read(p, (TagType)2, len, false);
                Glyphs[i] = pshape;
            }
        }
        return;
    }

    if (tagType != 0x30 && tagType != 0x4b) // DefineFont2 / DefineFont3
        return;

    in->LogParse(tagType == 0x30 ? "reading DefineFont2: " : "reading DefineFont3: ");

    bool hasLayout = in->ReadUInt(1) != 0;
    if (hasLayout)
        Flags |= 0x2000;
    else
        Flags &= ~0x2000u;
    unsigned shiftJis  = in->ReadUInt(1);
    unsigned smallText = in->ReadUInt(1);
    unsigned ansi      = in->ReadUInt(1);
    if (shiftJis)
        Flags = (Flags & ~0x100u) | 0x200;
    else if (ansi)
        Flags = (Flags & ~0x200u) | 0x100;
    else
        Flags &= ~0x300u;
    if (smallText)
        Flags |= 0x8000;
    else
        Flags &= ~0x8000u;
    bool wideOffsets = in->ReadUInt(1) != 0;
    if (in->ReadUInt(1))
        Flags |= 0x4000;
    else
        Flags &= ~0x4000u;
    if (in->ReadUInt(1))
        Flags |= 0x1;
    else
        Flags &= ~0x1u;
    if (in->ReadUInt(1))
        Flags |= 0x2;
    else
        Flags &= ~0x2u;

    UByte langCode = in->ReadU8();
    Name           = in->ReadStringWithLength(heap);
    unsigned glyphCount = in->ReadU16();
    if (in->IsVerboseParse())
    {
        in->LogParse("  Name = %s, %d glyphs\n", Name ? Name : "(none)", glyphCount);
        unsigned codePage = Flags & 0x300;
        in->LogParse("  HasLayout = %d, CodePage = %s, Italic = %d, Bold = %d\n", hasLayout,
                     codePage == 0x200 ? "ShiftJIS" : (codePage == 0x100 ? "ANSI" : "Unicode"), Flags & 1,
                     (Flags >> 1) & 1);
        in->LogParse("  LangCode = %d\n", langCode);
    }

    int           tableBase = in->Tell();
    Array<UInt32> offsets;
    unsigned      n = 0;
    if (glyphCount)
    {
        UInt32 first = wideOffsets ? in->ReadU32() : in->ReadU16();
        if (first == 0)
            ok = false;
        else
        {
            offsets.PushBack(first);
            n = glyphCount;
        }
    }
    for (unsigned i = 1; i < n; ++i)
        offsets.PushBack(wideOffsets ? in->ReadU32() : in->ReadU16());
    UInt32 fontCodeOffset = wideOffsets ? in->ReadU32() : in->ReadU16();

    Glyphs.Resize(glyphCount);
    if (!ok)
    {
        int pos = tableBase + (int)fontCodeOffset;
        if (pos >= in->GetTagEndPosition())
            return;
        in->SetPosition(pos);
        Flags |= 0x1000; // glyph shapes stripped
    }
    else
    {
        TagType shapeTag = (tagType == 0x30) ? (TagType)0x16 : tagType;
        if (hasLayout)
            AdvanceTable.Resize(glyphCount);
        for (unsigned i = 0; i < glyphCount; ++i)
        {
            in->SetPosition(tableBase + offsets[i]);
            UInt32 next = (i + 1 < glyphCount) ? offsets[i + 1] : fontCodeOffset;
            Ptr<ShapeDataBase> pshape = *SF_HEAP_NEW(heap) ConstShapeNoStyles();
            if (!pshape->Read(p, shapeTag, next - offsets[i], false))
            {
                AdvanceTable.Resize(i);
                Glyphs.Resize(i);
                return;
            }
            Glyphs[i] = pshape;

            if (hasLayout)
            {
                RectF bounds(0);
                pshape->ComputeBound(&bounds);
                AdvanceEntry& e = AdvanceTable[i];
                if (bounds.IsNormal())
                {
                    e.Left   = (SInt16)(bounds.x1 * 20.0f);
                    e.Top    = (SInt16)(bounds.y1 * 20.0f);
                    e.Width  = (UInt16)(SInt16)((bounds.x2 - bounds.x1) * 20.0f);
                    e.Height = (UInt16)(SInt16)((bounds.y2 - bounds.y1) * 20.0f);
                }
                else
                {
                    e.Left = e.Top = 0;
                    e.Width = e.Height = 0;
                }
            }
        }
        if (tableBase + (int)fontCodeOffset != in->Tell())
            return;
    }

    ReadCodeTable(in);

    if (hasLayout)
    {
        float scale = (tagType == 0x4b) ? 0.05f : 1.0f;
        Ascent      = (float)(SInt16)in->ReadU16() * scale;
        Descent     = (float)(SInt16)in->ReadU16() * scale;
        Leading     = (float)(SInt16)in->ReadU16() * scale;
        if (in->IsVerboseParse())
            in->LogParse("  Ascent = %d, Descent = %d, Leading = %d\n", (int)Ascent, (int)Descent, (int)Leading);

        if (AdvanceTable.GetSize() != Glyphs.GetSize())
            AdvanceTable.Resize(Glyphs.GetSize());
        for (UPInt i = 0; i < AdvanceTable.GetSize(); ++i)
            AdvanceTable[i].Advance = (float)(SInt16)in->ReadU16() * scale;

        // the glyph bounds are not kept
        RectF dummy(0);
        for (UPInt i = 0; i < Glyphs.GetSize(); ++i)
            in->ReadRect(&dummy);

        int kerningCount = in->ReadU16();
        if (in->IsVerboseParse())
            in->LogParse("  KerningCount = %d\n", kerningCount);
        for (int k = 0; k < kerningCount; ++k)
        {
            if (in->Tell() >= (int)(tagInfo.TagDataOffset + tagInfo.TagLength))
            {
                in->LogError("Corrupted file %s, kerning table of the font '%s' is longer than tagLength.",
                             in->GetFileName().ToCStr(), Name ? Name : "<noname>");
                break;
            }
            KerningPair kp;
            if (Flags & 0x4000)
            {
                kp.Char0 = in->ReadU16();
                kp.Char1 = in->ReadU16();
            }
            else
            {
                kp.Char0 = in->ReadU8();
                kp.Char1 = in->ReadU8();
            }
            float adjustment = (float)(SInt16)in->ReadU16() * scale;
            if (in->IsVerboseParse())
                in->LogParse("     Pair: %d - %d,\tadj = %d\n", kp.Char0, kp.Char1, (int)adjustment);
            KerningPairs.Add(kp, adjustment);
        }
    }

    if (!ok)
    {
        for (UPInt i = 0; i < AdvanceTable.GetSize(); ++i)
        {
            AdvanceEntry& e = AdvanceTable[i];
            e.Left = e.Top = 0;
            e.Width = e.Height = 0;
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
    for (UPInt i = 0; i < src.TextureGlyphs.GetSize(); ++i)
        TextureGlyphs[i] = src.TextureGlyphs[i];
    for (ImageResourceHash::ConstIterator it = src.GlyphsTextures.Begin(); it != src.GlyphsTextures.End(); ++it)
        GlyphsTextures.Set(it->First, it->Second);
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
    if (glyphIndex >= TextureGlyphs.GetSize())
    {
        TextureGlyphs.Resize(glyphIndex + 1);
        if (glyphIndex >= TextureGlyphs.GetSize())
            return;
    }
    TextureGlyphs[glyphIndex] = glyph;
}

// MS2-FUNCTIONAL 0x142655e80: the empty glyph past the end is a function-local static (thread-safe init + atexit)
// @0x142655e80
const TextureGlyph& TextureGlyphData::GetTextureGlyph(unsigned glyphIndex) const
{
    if (glyphIndex < TextureGlyphs.GetSize())
        return TextureGlyphs[glyphIndex];
    static TextureGlyph dummyTextureGlyph;
    return dummyTextureGlyph;
}

// @0x142657d70
void TextureGlyphData::VisitTextureGlyphs(TextureGlyphVisitor* pvisitor)
{
    for (UPInt i = 0; i < TextureGlyphs.GetSize(); ++i)
        pvisitor->Visit((unsigned)i, &TextureGlyphs[i]);
}

// @0x142657de0
void TextureGlyphData::VisitTextures(TexturesVisitor* pvisitor, ResourceBinding* pbinding)
{
    for (ImageResourceHash::Iterator it = GlyphsTextures.Begin(); it != GlyphsTextures.End(); ++it)
    {
        ImageResource* pimageRes;
        if (it->Second.IsIndex())
        {
            ResourceBindData resData;
            pbinding->GetResourceData(&resData, it->Second.GetBindIndex());
            pimageRes = (ImageResource*)resData.pResource.GetPtr();
        }
        else
            pimageRes = (ImageResource*)it->Second.GetResourcePtr();
        pvisitor->Visit(it->First, pimageRes);
    }
}

// @0x142657f70
void TextureGlyphData::WipeTextureGlyphs()
{
    TextureGlyph emptyGlyph;
    for (UPInt i = 0; i < TextureGlyphs.GetSize(); ++i)
        TextureGlyphs[i] = emptyGlyph;
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
    pTGData = *SF_HEAP_AUTO_NEW(this) TextureGlyphData(*(TextureGlyphData*)pfont->GetTextureGlyphData());
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

// MS2-FUNCTIONAL 0x142657940: different nonvolatile register (rbp vs r15) and branch layout; same resolve loop
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
    if (pFont && LowerCaseTop == 0 && UpperCaseTop == 0)
    {
        const char upperCaseTopChars[] = "HEFTUVWXZ";
        const char lowerCaseTopChars[] = "zxvwy";
        UInt16     upperCaseTop        = 0;
        for (const char* p = upperCaseTopChars; *p; ++p)
        {
            upperCaseTop = calcTopBound(*p);
            if (upperCaseTop)
                break;
        }
        if (upperCaseTop)
        {
            for (const char* p = lowerCaseTopChars; *p; ++p)
            {
                SInt16 lowerCaseTop = (SInt16)calcTopBound(*p);
                if (lowerCaseTop)
                {
                    LowerCaseTop = lowerCaseTop;
                    UpperCaseTop = (SInt16)upperCaseTop;
                    return;
                }
            }
        }
    }
    if (log)
        log->LogWarning("Font '%s%s%s' has no hinting chars (any of 'HEFTUVWXZ' and 'zxvwy'). Auto-Hinting disabled.",
                        pFont->GetName(), pFont->IsBold() ? " Bold" : "", pFont->IsItalic() ? " Italic" : "");
    LowerCaseTop = -1;
    UpperCaseTop = -1;
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
