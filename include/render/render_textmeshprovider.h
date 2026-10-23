// Recovered Scaleform 4.1.18 Render: TextMeshProvider, the mesh provider of one text field (Render_TextMeshProvider).
// CreateMeshData turns a TextLayout into entries (glyphs, backgrounds, underlines, images, ...), sorts them into
// layers of one kind and texture, and GetData tessellates a layer on request of the mesh cache. Vector glyphs get a
// VectorGlyphShape of their own, shared through the glyph cache.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout checked against the ctor 0x1426e1940 / dtor 0x1426e1b40 (0xe0 bytes, vftable 0x143193f50: the MeshProvider
// part comes first, the list links at +0x08), the TextMeshEntry dtor loop 0x1426e19f0 (pFill +0x08), the
// TextMeshLayer dtor 0x1426e1ad0 and generateRasterMesh 0x1426e7110 (EntryData +0x10).
#ifndef MS2_SF_RENDER_TEXTMESHPROVIDER_H
#define MS2_SF_RENDER_TEXTMESHPROVIDER_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_meshprovider.h"
#include "ms2/scaleform/include/render/render_textlayout.h"
#include "ms2/scaleform/include/render/render_font.h"
#include "ms2/scaleform/include/render/render_glyphshape.h"
#include "ms2/scaleform/include/render/render_textlayertype.h"

namespace Scaleform { namespace Render {

class Image;
class Viewport;
class GlyphCache;
class GlyphRaster;
class GlyphShape;
class TessBase;
class TextureGlyph;
class FontCacheHandle;
class Renderer2DImpl;
class TextPrimitiveBundle;
class BundleEntry;
class TextMeshProvider;
class Fence;
struct GlyphNode;
struct TextNotifier;

// What identifies a shared vector glyph: the face, the glyph, its hinting and the faux style / outline.
struct VectorGlyphKey
{
    FontCacheHandle* pFont;          // +0x00
    UInt16           GlyphIndex;     // +0x08
    UInt8            HintedVector;   // +0x0a
    UInt8            HintedRaster;   // +0x0b
    UInt16           Flags;          // +0x0c, only the bold / italic bits
    UInt16           Outline;        // +0x0e

    VectorGlyphKey() : pFont(0), GlyphIndex(0), HintedVector(0), HintedRaster(0), Flags(0), Outline(0) {}
    VectorGlyphKey(FontCacheHandle* font, unsigned glyphIndex, unsigned hintedVector, unsigned hintedRaster,
                   unsigned flags, unsigned outline)
        : pFont(font), GlyphIndex((UInt16)glyphIndex), HintedVector((UInt8)hintedVector),
          HintedRaster((UInt8)hintedRaster), Flags((UInt16)(flags & (Font::FF_Bold | Font::FF_Italic))),
          Outline((UInt16)outline)
    {
    }

    UPInt GetHashValue() const
    {
        return (((UPInt)pFont) >> 6) ^ (UPInt)pFont ^ (UPInt)GlyphIndex ^ (UPInt)HintedVector ^
               (UPInt)HintedRaster ^ (UPInt)Flags ^ (UPInt)Outline;
    }
    bool operator==(const VectorGlyphKey& o) const
    {
        return pFont == o.pFont && GlyphIndex == o.GlyphIndex && HintedVector == o.HintedVector &&
               HintedRaster == o.HintedRaster && Flags == o.Flags && Outline == o.Outline;
    }
};

// The shape of one vector glyph, kept by the glyph cache and meshed through its own keys.
struct VectorGlyphShape : public MeshProvider_KeySupport, public ListNode<VectorGlyphShape>
{
    VectorGlyphKey   Key;
    Ptr<GlyphShape>  pShape;
    Ptr<GlyphRaster> pRaster;
    RectF            Bounds;
    GlyphCache*      pCache;

    VectorGlyphShape() {}
    VectorGlyphShape(GlyphCache* cache) : pCache(cache) {}
    ~VectorGlyphShape() {}

    virtual void     OnEvict(MeshBase* mesh);
    virtual bool     GetData(MeshBase* mesh, VertexOutput* out, unsigned meshGenFlags);
    virtual RectF    GetIdentityBounds() const;
    virtual RectF    GetBounds(const Matrix2F& m) const;
    virtual RectF    GetCorrectBounds(const Matrix2F& m, float morphRatio, StrokeGenerator* gen,
                                      const ToleranceParams* tol) const;
    virtual bool     HitTestShape(const Matrix2F& m, float x, float y, float morphRatio, StrokeGenerator* gen,
                                  const ToleranceParams* tol) const;
    virtual unsigned GetLayerCount() const;
    virtual unsigned GetFillCount(unsigned layer, unsigned meshGenFlags) const;
    virtual void     GetFillData(FillData* data, unsigned layer, unsigned fillIndex, unsigned meshGenFlags);
    virtual void     GetFillMatrix(MeshBase* mesh, Matrix2F* matrix, unsigned layer, unsigned fillIndex,
                                   unsigned meshGenFlags);

    UPInt GetHashValue() const { return Key.GetHashValue(); }
    bool  operator==(const VectorGlyphShape& o) const { return Key == o.Key; }

    bool generateNullVectorMesh(VertexOutput* verOut);
};

// The per-kind payload of an entry (0x18 bytes; coordinates are x1, y1, x2, y2).
struct GlyphRasterEnt  { float Coord[4]; const GlyphNode* pGlyph; };
struct GlyphTextureEnt { float Coord[4]; const TextureGlyph* pGlyph; };
struct GlyphVectorEnt  { Font* pFont; UInt16 GlyphIndex; UInt16 Flags; float FontSize; float x, y; };
struct BackgroundEnt   { float Coord[4]; UInt32 BorderColor; };
struct SelectionEnt    { float Coord[4]; };
struct UnderlineEnt    { unsigned Style; float x, y; float Len; };
struct TextImageEnt    { float Coord[4]; Image* pImage; };
struct MaskEnt         { float Coord[4]; };

union TextEntryUnion
{
    GlyphRasterEnt  RasterData;
    GlyphTextureEnt PackedData;
    GlyphVectorEnt  VectorData;
    BackgroundEnt   BackgroundData;
    SelectionEnt    SelectionData;
    UnderlineEnt    UnderlineData;
    TextImageEnt    ImageData;
    MaskEnt         MaskData;
};

// An entry while CreateMeshData collects and sorts them (0x30 bytes; EntryIdx keeps the sort stable).
struct TmpTextMeshEntry
{
    UInt16         LayerType;   // +0x00
    UInt16         TextureId;   // +0x02
    unsigned       EntryIdx;    // +0x04
    UInt32         mColor;      // +0x08
    PrimitiveFill* pFill;       // +0x10
    TextEntryUnion EntryData;   // +0x18
};

struct TmpTextMeshLayer
{
    TextLayerType  Type;
    unsigned       Start;
    unsigned       Count;
    PrimitiveFill* pFill;
};

// A kept entry (0x28 bytes).
struct TextMeshEntry
{
    UInt16             LayerType;   // +0x00
    UInt16             TextureId;   // +0x02
    UInt32             mColor;      // +0x04
    Ptr<PrimitiveFill> pFill;       // +0x08
    TextEntryUnion     EntryData;   // +0x10
};

// Scratch storage of CreateMeshData.
struct TmpTextStorage
{
    LinearHeap                         LHeap;
    ArrayPaged<TmpTextMeshEntry, 6, 4> Entries;
    ArrayPaged<TmpTextMeshLayer, 4, 4> Layers;

    TmpTextStorage(MemoryHeap* heap) : LHeap(heap), Entries(&LHeap), Layers(&LHeap) {}
};

// A run of entries of one kind drawn as one mesh (0x40 bytes).
struct TextMeshLayer
{
    TextLayerType         Type;        // +0x00
    unsigned              Start;       // +0x04
    unsigned              Count;       // +0x08
    Ptr<Mesh>             pMesh;       // +0x10
    Ptr<MeshKey>          pMeshKey;    // +0x18, vector glyphs only
    Ptr<VectorGlyphShape> pShape;      // +0x20
    HMatrix               M;           // +0x28
    Ptr<PrimitiveFill>    pFill;       // +0x30
    float                 SizeScale;   // +0x38

    // (appended for sfr_render_07o) out of line in the exe (0x1426e1ad0), called by the layer array's loops
    SF_NOINLINE ~TextMeshLayer();
};

// The state of the glyph run addGlyph works on.
struct GlyphRunData
{
    TextFieldParam            Param;
    RectF                     Bounds;
    Font*                     pFont;
    FontCacheHandle*          pFontHandle;
    float                     FontSize;
    unsigned                  VectorSize;
    unsigned                  RasterSize;
    float                     NomWidth;
    float                     NomHeight;
    float                     TexHeight;
    UInt32                    mColor;
    float                     NewLineX;
    float                     NewLineY;
    RectF                     GlyphBounds;
    Matrix2F                  DirMtx;
    Matrix2F                  InvMtx;
    float                     HeightRatio;
    unsigned                  HintedNomHeight;
    const ShapeDataInterface* pShape;
    const GlyphRaster*        pRaster;
};

class TextMeshProvider : public ListNode<TextMeshProvider>, public MeshProvider
{
public:
    enum BatchFlags
    {
        BF_Valid           = 0x0001,
        BF_InUseList       = 0x0002,
        BF_InPinList       = 0x0004,
        BF_Clip            = 0x0008,
        BF_Creating        = 0x0010,
        BF_Created         = 0x0020,
        BF_HasVectorGlyphs = 0x0040,
        BF_HasUnderlines   = 0x0080,
        BF_HasMask         = 0x0100,
        BF_DistField       = 0x0200
    };

    TextMeshProvider(GlyphCache* cache);
    ~TextMeshProvider();

    void Clear();
    void ClearEntries();

    const TextMeshLayer& GetLayer(unsigned idx) const { return Layers[idx]; }
    TextMeshLayer&       GetLayer(unsigned idx)       { return Layers[idx]; }
    const TextMeshEntry& GetEntry(const TextMeshLayer& layer, unsigned idx) const { return Entries[layer.Start + idx]; }

    // the glyph queue / mesh cache side
    void AddNotifier(TextNotifier* notifier);
    void SetInUseList(bool f) { if (f) Flags |= BF_InUseList; else Flags &= ~BF_InUseList; }
    void SetInPinList(bool f) { if (f) Flags |= BF_InPinList; else Flags &= ~BF_InPinList; }
    void ClearInList()        { Flags &= ~(BF_InUseList | BF_InPinList); }
    bool IsInUseList() const  { return (Flags & (BF_InUseList | BF_InPinList)) == BF_InUseList; }
    bool IsInPinList() const  { return (Flags & (BF_InUseList | BF_InPinList)) == BF_InPinList; }
    bool IsInList() const     { return (Flags & (BF_InUseList | BF_InPinList)) != 0; }

    bool HasVectorGlyphs() const  { return (Flags & BF_HasVectorGlyphs) != 0; }
    bool HasDistanceField() const { return (Flags & BF_DistField) != 0; }

    void   PinSlots();
    void   UnpinSlots();
    void   OnEvictSlots();
    bool   IsInUse() const { return GetMeshUseStatus() >= MUS_InUse; }
    void   AddToInUseList();
    Fence* GetLatestFence() const;

    bool NeedsUpdate(const HMatrix& m, const Matrix4F& m4, const Viewport& vp, const TextFieldParam& param) const;
    bool CreateMeshData(const TextLayout* layout, Renderer2DImpl* ren, const HMatrix& m, const Matrix4F& m4,
                        const Viewport& vp, unsigned meshGenFlags);
    // set by CreateMeshData, reset by Clear
    bool IsCreated() const { return (Flags & BF_Created) != 0; }

    float GetHeightRatio() const { return HeightRatio; }

    // MeshProvider
    virtual unsigned GetLayerCount() const { return (unsigned)Layers.GetSize(); }
    virtual bool     GetData(MeshBase* mesh, VertexOutput* out, unsigned meshGenFlags);
    virtual unsigned GetFillCount(unsigned, unsigned) const { return 1; }
    virtual void     GetFillData(FillData* data, unsigned layer, unsigned fillIndex, unsigned meshGenFlags);
    virtual void     GetFillMatrix(MeshBase* mesh, Matrix2F* matrix, unsigned layer, unsigned fillIndex,
                                   unsigned meshGenFlags)
    {
        matrix->SetIdentity();
    }

    // the text primitive bundle's pins (held while the layers are prepared)
    void Pin()   { PinCount++; }
    void Unpin() { PinCount--; }

    TextPrimitiveBundle* GetBundle() const { return pBundle; }
    void                 ClearBundle()     { SetBundle(0, 0); }
    void SetBundle(TextPrimitiveBundle* bundle, BundleEntry* entry)
    {
        pBundle      = bundle;
        pBundleEntry = entry;
    }

    MeshUseStatus GetMeshUseStatus() const;
    bool          HasMask() const { return (Flags & BF_HasMask) != 0; }

    // the cumulative mask clear bounds (shapes and masks sticking out); cached so removal can find it
    HMatrix UpdateMaskClearBounds(HMatrix viewMat);
    HMatrix GetMaskClearBounds() const;

    static unsigned CalcVectorParams(TextMeshLayer& layer, const TextMeshEntry& ent, const Matrix2F& scalingMtx,
                                     float sizeScale, const HMatrix& m, Renderer2DImpl* ren, unsigned meshGenFlags,
                                     float* keyData);

private:
    struct CmpEntries
    {
        const GlyphCache* pCache;
        CmpEntries(GlyphCache* c) : pCache(c) {}
        bool operator()(const TmpTextMeshEntry& a, const TmpTextMeshEntry& b) const;
    };

    void addLayer(TmpTextStorage& storage, TextLayerType type, unsigned start, unsigned count);
    void addLayer(TmpTextStorage& storage, UPInt start, UPInt end);
    void addVectorGlyph(TmpTextStorage& storage, UInt32 color, FontCacheHandle* font, UInt16 glyphIndex,
                        UInt16 flags, float fontSize, float x, float y);
    void addRasterGlyph(TmpTextStorage& storage, TextLayerType type, GlyphRunData& data, UInt32 color,
                        GlyphNode* node, float screenSize, bool snap, float stretch);
    void addTextureGlyph(TmpTextStorage& storage, const TextureGlyph* tgl, GlyphRunData& data, UInt32 color);
    void addBackground(TmpTextStorage& storage, UInt32 color, UInt32 borderColor, const RectF& rect);
    void addSelection(TmpTextStorage& storage, UInt32 color, const RectF& rect);
    void addCursor(TmpTextStorage& storage, UInt32 color, const RectF& rect);
    void addUnderline(TmpTextStorage& storage, UInt32 color, TextUnderlineStyle style, float x, float y, float len);
    void addImage(TmpTextStorage& storage, const GlyphRunData& data, Image* img, float scaleX, float scaleY,
                  float baseLine, bool snap);
    void addMask(TmpTextStorage& storage);
    void sortEntries(TmpTextStorage& storage);

    static float calcHeightRatio(const HMatrix& m, const Matrix4F& m4, const Viewport& vp);

    bool addGlyph(TmpTextStorage& storage, GlyphRunData& data, unsigned glyphIndex, bool fauxBold, bool fauxItalic,
                  bool snap, unsigned meshGenFlags);
    void createVectorGlyph(unsigned layerIdx, Renderer2DImpl* ren, const HMatrix& m, unsigned meshGenFlags);

    struct VertexCountType
    {
        unsigned VStart;
        unsigned IStart;
        VertexCountType() : VStart(0), IStart(0) {}
    };

    void setMeshData(TessBase* tess, VertexOutput* verOut, const UInt32* colors, VertexCountType& verCount);
    bool generateNullVectorMesh(VertexOutput* verOut);
    bool generateRectangle(Renderer2DImpl* ren, VertexOutput* verOut, const Matrix2F& mtx, const float* coord,
                           UInt32 fillColor, UInt32 borderColor, unsigned meshGenFlags);
    bool generateSelection(Renderer2DImpl* ren, VertexOutput* verOut, const TextMeshLayer& layer,
                           const Matrix2F& mtx, unsigned meshGenFlags);
    bool clipGlyphRect(RectF& chr, RectF& tex) const;
    bool generateRasterMesh(VertexOutput* verOut, const TextMeshLayer& layer);
    bool generatePackedMesh(VertexOutput* verOut, const TextMeshLayer& layer);
    bool generateImageMesh(VertexOutput* verOut, const TextMeshLayer& layer);
    bool generateUnderlines(Renderer2DImpl* ren, VertexOutput* verOut, const TextMeshLayer& layer,
                            const Matrix2F& mtx, unsigned meshGenFlags);
    bool generateMask(VertexOutput* verOut, const TextMeshLayer& layer);

    float snapX(const GlyphRunData& data) const;
    float snapY(const GlyphRunData& data) const;

    GlyphCache*                pCache;         // +0x18
    unsigned                   Flags;          // +0x20
    ArrayDH_POD<TextNotifier*> Notifiers;      // +0x28
    ArrayDH<TextMeshEntry>     Entries;        // +0x48
    ArrayDH<TextMeshLayer>     Layers;         // +0x68
    // the text primitive bundle's state
    UPInt                      PinCount;       // +0x88
    TextPrimitiveBundle*       pBundle;        // +0x90
    BundleEntry*               pBundleEntry;   // +0x98
    float                      HeightRatio;    // +0xa0
    RectF                      ClipBox;        // +0xb0 (16-aligned)
    RectF                      ClearBox;       // +0xc0
    Renderer2DImpl*            pRenderer;      // +0xd0
    HMatrix                    ClearBounds;    // +0xd8
};

}} // namespace Scaleform::Render

#endif
