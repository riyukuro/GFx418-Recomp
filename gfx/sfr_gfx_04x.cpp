// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TagLoaders: the rest of the tag
// loaders (DefineBitsJPEG3, morph shapes, lossless bitmaps, exports, scale9 grids, the GFx external image / font
// texture / sub image tags, scene and frame labels) and the compiler-generated helpers emitted with them (folded
// deleting destructors, array / hash template members, the LoadProcess readers).
// Third source of queue unit sfr_gfx_04 (sfr_gfx_04b is the second; sf-remaining2 cluster 1).
// MS2-UNIT: sfr_gfx_04x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425c48e0-0x1425c4b70 .text$mn
// MS2-RANGE: 0x1425c4d00-0x1425c4db0 .text$mn
// MS2-RANGE: 0x1425c5340-0x1425c57b0 .text$mn
// MS2-RANGE: 0x1425c5bb0-0x1425c5d70 .text$mn
// MS2-RANGE: 0x1425c5d70-0x1425c6180 .text$mn
// MS2-RANGE: 0x1425c66d0-0x1425c6950 .text$mn
// MS2-RANGE: 0x1425c6950-0x1425c6b50 .text$mn
// MS2-RANGE: 0x1425c6b50-0x1425c7840 .text$mn
// MS2-RANGE: 0x1425c7840-0x1425c7a50 .text$mn
// MS2-RANGE: 0x1425c7a50-0x1425c7ba0 .text$mn
// MS2-RANGE: 0x1425c7ca0-0x1425c8010 .text$mn
// MS2-RANGE: 0x1425c80e0-0x1425c8250 .text$mn
// MS2-RANGE: 0x1425c8250-0x1425c8550 .text$mn
// MS2-RANGE: 0x1425c8580-0x1425c8670 .text$mn
// MS2-RANGE: 0x1425c86a0-0x1425c88d0 .text$mn
// MS2-RANGE: 0x1425c8970-0x1425c8b20 .text$mn
// MS2-RANGE: 0x1425c8b50-0x1425c8ca0 .text$mn
// MS2-RANGE: 0x1425c8d10-0x1425c8fe0 .text$mn
// MS2-RANGE: 0x1425c90f0-0x1425c9190 .text$mn
// MS2-RANGE: 0x1425c9280-0x1425c92ab .text$mn
// MS2-PIN: ??_7ExtraData@JPEG@Render@Scaleform@@6B@ 0x14318a288
// MS2-PIN: ??_7TextureGlyph@Render@Scaleform@@6B@ 0x14318a2b0
// MS2-PIN: ??_7?$RefCountBase@VTextureGlyph@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318a2a8
// MS2-PIN: ??_7GFxInitImportActions@GFx@Scaleform@@6B@ 0x14318a370
// MS2-PIN: ??_7ImageFileInfo@GFx@Scaleform@@6B@ 0x14318a268
// MS2-PIN: ??_7SubImageResourceInfo@GFx@Scaleform@@6B@ 0x14318a278
// MS2-PIN: ??_7?$RefCountBaseNTS@USubImageResourceInfo@GFx@Scaleform@@$01@Scaleform@@6B@ 0x14318a270
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BAF@@Scaleform@@6B@ 0x14318a2b8
// MS2-PIN: ??_7?$RefCountBaseNTS@VTextureGlyphData@GFx@Scaleform@@$0BAF@@Scaleform@@6B@ 0x14318a2c0
// MS2-PIN: ??_7TextureGlyphData@GFx@Scaleform@@6B@ 0x14318a2c8
// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68

#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/gfx/gfx_fontresource.h"
#include "../include/gfx/gfx_shapeswf.h"
#include "../include/gfx/gfx_morphcharacter.h"
#include "../include/gfx/gfx_scale9grid.h"
#include "../include/gfx/gfx_spritedef.h"
#include "../include/gfx/gfx_buttondef.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/render/render_jpeg.h"
#include "../include/render/render_textureglyph.h"
#include "../include/render/render_imagefile.h"
#include "../kernel/sf_sysalloc.h"

extern "C" void  FUN_14015b310(void*, unsigned long long);
extern "C" char  DAT_14318b240[]; // the ICF-shared vftable of the empty interface bases

namespace Scaleform {

// ---- array / hash members of the font texture glyphs, the frame labels and the imports ----

// @0x1425c80e0
template ArrayDataBase<Render::TextureGlyph, AllocatorGH<Render::TextureGlyph, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
// @0x1425c8150
template ArrayDataBase<Render::TextureGlyph, AllocatorLH<Render::TextureGlyph, 261>, ArrayDefaultPolicy>::~ArrayDataBase();

typedef HashNode<GFx::ResourceId, GFx::ResourcePtr<GFx::ImageResource>, FixedSizeHash<GFx::ResourceId> >
    Sfr04xImageNode;
// @0x1425c81c0
template HashSetBase<Sfr04xImageNode, Sfr04xImageNode::NodeHashF, Sfr04xImageNode::NodeAltHashF,
                     AllocatorLH<GFx::ResourceId, 261>,
                     HashsetCachedNodeEntry<Sfr04xImageNode, Sfr04xImageNode::NodeHashF> >::~HashSetBase();

// @0x1425c8d10
template void ArrayDataBase<GFx::MovieDataDef::FrameLabelInfo, AllocatorDH<GFx::MovieDataDef::FrameLabelInfo, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x1425c8db0
template void ArrayDataBase<GFx::ImportData::Symbol, AllocatorLH<GFx::ImportData::Symbol, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x1425c8e50
template void ArrayDataBase<Render::TextureGlyph, AllocatorGH<Render::TextureGlyph, 2>, ArrayDefaultPolicy>::Reserve(
    const void*, UPInt);
// @0x1425c8ef0
template void ArrayDataBase<Render::TextureGlyph, AllocatorLH<Render::TextureGlyph, 261>, ArrayDefaultPolicy>::Reserve(
    const void*, UPInt);

// ---- folded deleting destructors (the exe keeps one copy per base destructor and object size) ----

// The scalar deleting destructor tail: free on the global heap, or the sized delete of the /4 flag.
template<class T>
static SF_FORCEINLINE T* Sfr04xDeleteTail(T* p, unsigned flags, UPInt size)
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

// A 0x10-byte RefCountImpl (vftable and count only).
// @0x1425c8290
void* FUN_1425c8290(RefCountImplCore* p, unsigned flags)
{
    p->RefCountImplCore::~RefCountImplCore();
    return Sfr04xDeleteTail(p, flags, 0x10);
}

// @0x1425c82f0
void* FUN_1425c82f0(RefCountImplCore* p, unsigned flags)
{
    p->RefCountImplCore::~RefCountImplCore();
    return Sfr04xDeleteTail(p, flags, 0x10);
}

// A 0x10-byte RefCountNTSImpl.
// @0x1425c8350
void* FUN_1425c8350(RefCountNTSImplCore* p, unsigned flags)
{
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    return Sfr04xDeleteTail(p, flags, 0x10);
}

// @0x1425c83b0
void* FUN_1425c83b0(RefCountNTSImplCore* p, unsigned flags)
{
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    return Sfr04xDeleteTail(p, flags, 0x10);
}

// @0x1425c8410
void* FUN_1425c8410(RefCountNTSImplCore* p, unsigned flags)
{
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    return Sfr04xDeleteTail(p, flags, 0x10);
}

// ShapeDataBase (0x20 bytes): nothing of its own to release.
// @0x1425c86a0
void* FUN_1425c86a0(RefCountImplCore* p, unsigned flags)
{
    p->RefCountImplCore::~RefCountImplCore();
    return Sfr04xDeleteTail(p, flags, 0x20);
}

namespace GFx {

// @0x1425c8470
void* FUN_1425c8470(ConstShapeWithStyles* p, unsigned flags)
{
    p->ConstShapeWithStyles::~ConstShapeWithStyles();
    return Sfr04xDeleteTail(p, flags, sizeof(ConstShapeWithStyles));
}

// The exe's ImageFileInfo destructor is inlined here: the two names, then the base.
// @0x1425c8580
void* FUN_1425c8580(ImageFileInfo* p, unsigned flags)
{
    p->ExportName.~String();
    p->FileName.~String();
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    return Sfr04xDeleteTail(p, flags, sizeof(ImageFileInfo));
}

// @0x1425c8630
void* FUN_1425c8630(PlaceObject2Tag* p, unsigned flags)
{
    p->PlaceObject2Tag::~PlaceObject2Tag();
    if (flags & 1)
        ::operator delete(p, 0x10);
    return p;
}

// SubImageResourceInfo (0x30 bytes, vftable 0x14318a278): the image resource it cuts from at +0x18.
// @0x1425c8700
void* FUN_1425c8700(RefCountNTSImplCore* p, unsigned flags)
{
    Resource* pimage = *reinterpret_cast<Resource**>(reinterpret_cast<UByte*>(p) + 0x18);
    if (pimage)
        pimage->Release();
    p->RefCountNTSImplCore::~RefCountNTSImplCore();
    return Sfr04xDeleteTail(p, flags, 0x30);
}

// @0x1425c8860
void* FUN_1425c8860(TextureGlyphData* p, unsigned flags)
{
    p->TextureGlyphData::~TextureGlyphData();
    return Sfr04xDeleteTail(p, flags, sizeof(TextureGlyphData));
}

} // namespace GFx

namespace Render {

// @0x1425c87f0
void* FUN_1425c87f0(TextureGlyph* p, unsigned flags)
{
    p->TextureGlyph::~TextureGlyph();
    return Sfr04xDeleteTail(p, flags, sizeof(TextureGlyph));
}

namespace JPEG {

// @0x1425c8250
void FUN_1425c8250(ExtraData* p)
{
    p->ExtraData::~ExtraData();
}

// ExtraData (0x20 bytes, vftable 0x14318a288).
// @0x1425c84d0
void* FUN_1425c84d0(ExtraData* p, unsigned flags)
{
    p->ExtraData::~ExtraData();
    return Sfr04xDeleteTail(p, flags, sizeof(ExtraData));
}

// TablesHeader (0x20 bytes, vftable 0x14318a298).
// @0x1425c8770
void* FUN_1425c8770(TablesHeader* p, unsigned flags)
{
    p->TablesHeader::~TablesHeader();
    return Sfr04xDeleteTail(p, flags, sizeof(TablesHeader));
}

}} // namespace Render::JPEG

// The empty interface bases: back to the shared base vftable, then the sized delete.
static SF_FORCEINLINE void* Sfr04xDeleteInterface(void* p, unsigned flags)
{
    *(void**)p = DAT_14318b240;
    if (flags & 1)
        ::operator delete(p, 8);
    return p;
}

// SysAllocBase
// @0x1425c90f0
void* FUN_1425c90f0(SysAllocBase* p, unsigned flags)
{
    return Sfr04xDeleteInterface(p, flags);
}

// SysAlloc
// @0x1425c9130
void* FUN_1425c9130(SysAlloc* p, unsigned flags)
{
    return Sfr04xDeleteInterface(p, flags);
}

namespace GFx {

// ExecuteTag
// @0x1425c9280
void* FUN_1425c9280(ExecuteTag* p, unsigned flags)
{
    return Sfr04xDeleteInterface(p, flags);
}

// ---- the loaders ----

// The image file readers of the load: a state, the render registry after it at +0x18.
class ImageFileHandlerRegistry : public State, public Render::ImageFileHandlerRegistry
{
};

// The JPEG with a zlib alpha plane (gfx_imagesupport.h, sfr_gfx_08h; that header's include tree cannot be mixed with
// this one): its constructor only, the object is used as the Render::Image it is.
class MemoryBufferJpegImageWithZlibAlphas : public NewOverrideBase<Stat_Default_Mem>
{
    UByte Data[0x48];

public:
    MemoryBufferJpegImageWithZlibAlphas(ZlibSupportBase* zlib, Render::JPEG::AbstractReader* reader,
                                        unsigned alphaPos, Render::ImageFormat format, const Render::ImageSize& size,
                                        unsigned use, Render::ImageUpdateSync* sync, File* file, UPInt length);

    Render::Image* GetImage() { return reinterpret_cast<Render::Image*>(this); }
};

__declspec(noinline) UInt32 FUN_1425c8c20(LoadProcess* p); // LoadProcess::ReadU32, out of line (defined below)

enum { Tag_DefineBitsJpeg4 = 90 };

// DefineBitsJPEG3 / 4: a JPEG followed by its zlib-compressed alpha plane, kept compressed in memory.
// MS2-FUNCTIONAL 0x1425c48e0: same reads, checks, log text and objects; register allocation and the null-heap
// fallback differ.
// @0x1425c48e0
void SF_STDCALL GFx_DefineBitsJpeg3Loader(LoadProcess* p, const TagInfo& tagInfo)
{
    ResourceId rid(p->ReadU16());
    UInt32     alphaOffset = FUN_1425c8c20(p);
    if (tagInfo.TagType == Tag_DefineBitsJpeg4)
    {
        UInt16 deblocking = p->ReadU16();
        p->LogParse("  GFx_DefineBitsJpeg4Loader: charid = %d pos = %d deblocking = %d\n", rid.GetIdIndex(),
                    p->Tell(), deblocking);
    }
    else
        p->LogParse("  GFx_DefineBitsJpeg3Loader: charid = %d pos = %d\n", rid.GetIdIndex(), p->Tell());

    Render::ImageSource*          psource   = 0;
    Ptr<ImageFileHandlerRegistry> pregistry = p->GetLoadStates()->GetImageFileHandlerRegistry();
    if (!pregistry)
        p->LogError("Image file handler registry is not installed - can't load jpeg image data");
    else
    {
        ZlibSupportBase* pzlib = p->GetLoadStates()->pZlibSupport;
        if (!pzlib)
            p->LogError("ZlibState is not set - can't load zipped image data");
        else
        {
            Render::JPEG::AbstractReader* preader = static_cast<Render::JPEG::AbstractReader*>(
                static_cast<Render::ImageFileHandlerRegistry*>(pregistry)->GetReader(Render::ImageFile_JPEG));
            if (!preader)
                p->LogError("Jpeg System is not installed - can't load jpeg image data");
            else
            {
                UPInt       length = tagInfo.TagLength + tagInfo.TagDataOffset - p->Tell();
                File*       pfile  = p->GetUnderlyingFile();
                MemoryHeap* pheap  = p->GetLoadHeap();
                if (!pheap)
                    pheap = Memory::pGlobalHeap;
                MemoryBufferJpegImageWithZlibAlphas* pimage = SF_HEAP_NEW(pheap) MemoryBufferJpegImageWithZlibAlphas(
                    pzlib, preader, alphaOffset, Render::Image_R8G8B8A8, Render::ImageSize(), 0, 0, pfile, length);
                psource = preader->CreateWrapperImageSource(pimage ? pimage->GetImage() : 0);
                if (pimage)
                    pimage->GetImage()->Release();
            }
        }
    }
    p->AddImageResource(rid, psource);
    if (psource)
        psource->Release();
}

// DefineMorphShape / DefineMorphShape2.
// @0x1425c4d00
void SF_STDCALL GFx_DefineShapeMorphLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    UInt16 characterId = p->ReadU16();
    p->LogParse("  ShapeMorphLoader: id = %d\n", characterId);

    Ptr<MorphCharacterDef> morph = *SF_HEAP_NEW(p->GetLoadHeap()) MorphCharacterDef;
    morph->Read(p, tagInfo, true);
    p->AddResource(ResourceId(characterId), morph.GetPtr());
}

// ExportAssets: the exported symbol names of the file's characters.
// @0x1425c5bb0
void SF_STDCALL GFx_ExportLoader(LoadProcess* p, const TagInfo&)
{
    unsigned count = p->ReadU16();
    p->LogParse("  export: count = %d\n", count);
    for (unsigned i = 0; i < count; i++)
    {
        UInt16   id = p->ReadU16();
        StringDH symbolName(p->GetLoadHeap());

        p->GetStream()->ReadString(&symbolName);

        p->LogParse("  export: id = %d, name = %s\n", id, symbolName.ToCStr());

        ResourceId     rid(id);
        ResourceHandle hres;
        if (p->GetResourceHandle(&hres, rid))
            p->ExportResource(symbolName, rid, hres);
        else
            p->LogError("Don't know how to export Resource '%s'", symbolName.ToCStr());
    }
}

// The zlib-compressed bitmap source of DefineBitsLossless (gfx_imagesupport.h, sfr_gfx_08h; not includable here): its
// constructor only, the object is used as the Render::ImageSource it is.
class ZlibImageSource : public NewOverrideBase<Stat_Default_Mem>
{
    UByte Data[0x50];

public:
    enum SourceBitmapDataFormat
    {
        ColorMappedRGB,
        RGB16,
        RGB24,
        ColorMappedRGBA,
        RGBA
    };

    ZlibImageSource(ZlibSupportBase* zlib, File* file, const Render::Size<unsigned long>& size,
                    SourceBitmapDataFormat bmpFormatId, Render::ImageFormat format, UInt16 colorTableSize,
                    UInt64 uncompressedLen);

    Render::ImageSource* GetSource() { return reinterpret_cast<Render::ImageSource*>(this); }
};

enum
{
    Tag_DefineBitsLossless = 20,
    Tag_ImportAssets2      = 71
};

// DefineBitsLossless / DefineBitsLossless2: a color-mapped or direct bitmap, zlib-compressed; decompressed when used.
// MS2-FUNCTIONAL 0x1425c5340: same reads, formats, log text and objects; the exe duplicates the source creation per
// format.
// @0x1425c5340
void SF_STDCALL GFx_DefineBitsLossless2Loader(LoadProcess* p, const TagInfo& tagInfo)
{
    ResourceId rid(p->ReadU16());
    UByte      bitmapFormat = p->GetStream()->ReadU8();
    UInt16     width        = p->ReadU16();
    UInt16     height       = p->ReadU16();
    p->LogParse("  DefBitsLossless2: tagInfo.TagType = %d, id = %d, fmt = %d, w = %d, h = %d\n", tagInfo.TagType,
                rid.GetIdIndex(), bitmapFormat, width, height);

    Render::ImageSource* psource = 0;
    ZlibSupportBase*     pzlib   = p->GetLoadStates()->pZlibSupport;
    if (!pzlib)
        p->LogError("Error: GFxZlibState is not set - can't load zipped image data\n");
    else
    {
        ZlibImageSource::SourceBitmapDataFormat sourceFormat;
        Render::ImageFormat                     format;
        UInt16                                  colorTableSize = 0;
        bool                                    known          = true;
        if (tagInfo.TagType == Tag_DefineBitsLossless)
        {
            format = Render::Image_R8G8B8;
            switch (bitmapFormat)
            {
            case 3:
                colorTableSize = (UInt16)(p->ReadU8() + 1);
                sourceFormat   = ZlibImageSource::ColorMappedRGB;
                break;
            case 4: sourceFormat = ZlibImageSource::RGB16; break;
            case 5: sourceFormat = ZlibImageSource::RGB24; break;
            default: known = false; break;
            }
        }
        else
        {
            format = Render::Image_R8G8B8A8;
            switch (bitmapFormat)
            {
            case 3:
                colorTableSize = (UInt16)(p->ReadU8() + 1);
                sourceFormat   = ZlibImageSource::ColorMappedRGBA;
                break;
            case 4: sourceFormat = ZlibImageSource::RGB16; break;
            case 5: sourceFormat = ZlibImageSource::RGBA; break;
            default: known = false; break;
            }
        }
        if (known)
        {
            UPInt length = tagInfo.TagLength + tagInfo.TagDataOffset - p->Tell();
            Render::Size<unsigned long> size(width, height);
            ZlibImageSource* psrc = SF_NEW ZlibImageSource(pzlib, p->GetUnderlyingFile(), size, sourceFormat, format,
                                                           colorTableSize, length);
            psource = psrc ? psrc->GetSource() : 0;
        }
    }
    p->AddImageResource(rid, psource);
    if (psource)
        psource->Release();
}

// The InitActions placeholder of an import: the imported file's actions run there.
// @0x1425c8b80
bool GFxInitImportActions::IsInitImportActionsTag() const
{
    return true;
}

// ImportAssets / ImportAssets2: the symbols another file supplies, bound when that file is loaded.
// MS2-FUNCTIONAL 0x1425c5d70: same reads, calls, log text and objects; register assignment (rsi/r14, edi/esi) and the
// hoisted -1 of the string release differ.
// @0x1425c5d70
void SF_STDCALL GFx_ImportLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    Stream* pin = p->GetStream();

    String sourceUrl;
    pin->ReadString(&sourceUrl);

    if (tagInfo.TagType == Tag_ImportAssets2)
    {
        unsigned val = p->ReadU16(); // reserved, 1
        SF_UNUSED(val);
    }

    int count = pin->ReadU16();

    p->LogParse(((tagInfo.TagType != Tag_ImportAssets2) ? "  importAssets: SourceUrl = %s, count = %d\n"
                                                        : "  importAssets2: SourceUrl = %s, count = %d\n"),
                sourceUrl.ToCStr(), count);

    ImportData* pimportData = p->AllocMovieDefClass<ImportData>();
    pimportData->Frame      = p->GetLoadingFrame();
    pimportData->SourceUrl  = sourceUrl;

    // Get the imports.
    for (int i = 0; i < count; i++)
    {
        String symbolName;
        UInt16 id = pin->ReadU16();

        pin->ReadString(&symbolName);
        p->LogParse("  import: id = %d, name = %s\n", id, symbolName.ToCStr());

        // And add ResourceId so that it's handle can be referenced by new load operations.
        ResourceHandle rh = p->AddNewResourceHandle(ResourceId(id));
        // Add import symbol to data.
        pimportData->AddSymbol(symbolName.ToCStr(), id, rh.GetBindIndex());
    }

    // Pass completed ImportData to GFxMovieDataDef.
    p->AddImportData(pimportData);

    // Add InitAction import tag, so that init actions are processed correctly.
    GFxInitImportActions* ptag = p->AllocTag<GFxInitImportActions>();
    ptag->ImportIndex          = pimportData->ImportIndex;
    p->AddInitImportAction(ptag);
}

// DefineScalingGrid: the 9-slice grid of a sprite or button defined before.
// MS2-FUNCTIONAL 0x1425c66d0: same reads, checks, log text and grid store; cl duplicates the grid-pointer store per
// allocation branch and keeps the button branch inline, the exe merges the store and moves that branch after the return.
// @0x1425c66d0
void SF_STDCALL GFx_Scale9GridLoader(LoadProcess* p, const TagInfo&)
{
    Stream* pin = p->GetStream();

    RectF    r(0);
    unsigned refId = pin->ReadU16();
    pin->ReadRect(&r);

    if (pin->IsVerboseParse())
    {
        p->LogParse("Scale9GridLoader, id=%d, x1=%d, y1=%d, x2=%d, y2=%d\n",
            refId, int(r.x1), int(r.y1), int(r.x2), int(r.y2));
    }

    if (r.x1 >= r.x2)
    {
        p->LogWarning("Scale9Grid for resource=%d has negative width %f", refId, (r.x2 - r.x1) / 20);
        return;
    }

    if (r.y1 >= r.y2)
    {
        p->LogWarning("Scale9Grid for resource=%d has negative height %f", refId, (r.y2 - r.y1) / 20);
        return;
    }

    ResourceHandle handle;
    if (p->GetLoadTaskData()->GetResourceHandle(&handle, ResourceId(refId)))
    {
        Resource* rptr = handle.GetResourcePtr();
        if (rptr)
        {
            if (rptr->GetResourceType() == Resource::RT_SpriteDef)
            {
                SpriteDef* sp = static_cast<SpriteDef*>(rptr);
                if (!sp->pScale9Grid)
                    sp->pScale9Grid = SF_HEAP_AUTO_NEW(sp) Scale9Grid;
                *sp->pScale9Grid = r;
            }
            else if (rptr->GetResourceType() == Resource::RT_ButtonDef)
            {
                ButtonDef* b = static_cast<ButtonDef*>(rptr);
                b->SetScale9Grid(r);
            }
        }
    }
}

class ImageFileResourceCreator
{
public:
    static ResourceData CreateImageFileResourceData(ImageFileInfo* prfi);
};

// The image file a movie refers to: bound later through the resource library.
// @0x1425c8970
ResourceHandle SF_STDCALL GFx_CreateImageFileResourceHandle(LoadProcess* p, ResourceId rid, const char* pfilename,
                                                            const char* pexportName, UInt16 fileFormat,
                                                            UInt16 targetWidth, UInt16 targetHeight)
{
    ImageFileInfo* pfi = SF_NEW ImageFileInfo;
    pfi->FileName      = pfilename;
    pfi->ExportName    = pexportName;
    pfi->pExporterInfo = p->GetLoadTaskData()->GetExporterInfo();
    pfi->Format        = (FileTypeConstants::FileFormatType)fileFormat;
    pfi->TargetWidth   = targetWidth;
    pfi->TargetHeight  = targetHeight;
    if ((rid.GetIdValue() & ResourceId::IdType_Bit_TypeMask) == ResourceId::IdType_FontImage)
        pfi->Use = Resource::Use_FontTexture;
    ResourceHandle rh = p->AddDataResource(rid, ImageFileResourceCreator::CreateImageFileResourceData(pfi));
    if (pfi)
        pfi->Release();
    return rh;
}

// DefineExternalImage / DefineExternalImage2: a bitmap kept in a file of its own.
// MS2-FUNCTIONAL 0x1425c6950: same reads, log text and handle; the string releases inline differently.
// @0x1425c6950
void SF_STDCALL GFx_DefineExternalImageLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    Stream* in       = p->GetStream();
    UInt32  id       = in->ReadU32();
    UInt16  format   = p->ReadU16();
    UInt16  width    = p->ReadU16();
    UInt16  height   = p->ReadU16();
    String  exportName, fileName;
    in->ReadStringWithLength(&exportName);
    in->ReadStringWithLength(&fileName);
    in->LogParse("  DefineExternalImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', exp = '%s', w = %d, "
                 "h = %d\n",
                 tagInfo.TagType, id, format, fileName.ToCStr(), exportName.ToCStr(), width, height);
    GFx_CreateImageFileResourceHandle(p, ResourceId(id & 0x9ffff), fileName.ToCStr(), exportName.ToCStr(), format,
                                      width, height);
}

// FontTextureInfo: the glyph textures of the fonts, packed by the exporter into image files.
// MS2-FUNCTIONAL 0x1425c6b50: same reads, log text, glyph table and texture binding; the array growth and the
// reference counting inline differently.
// @0x1425c6b50
void SF_STDCALL GFx_FontTextureInfoLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    MemoryHeap* pheap = p->GetLoadHeap();
    Stream*     in    = p->GetStream();

    UInt32 textureId = in->ReadU32();
    UInt16 format    = in->ReadU16();
    String fileName;
    in->ReadStringWithLength(&fileName);
    UInt16 textureWidth  = in->ReadU16();
    UInt16 textureHeight = in->ReadU16();
    UByte  padPixels     = in->ReadU8();
    UInt16 nominalSize   = in->ReadU16();
    if (in->IsVerboseParse())
        in->LogParse("  FontTextureInfo: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', w = %d, h = %d\n",
                     tagInfo.TagType, textureId, format, fileName.ToCStr(), textureWidth, textureHeight);

    ResourceId     tid(textureId);
    ResourceHandle rh = GFx_CreateImageFileResourceHandle(p, tid, fileName.ToCStr(), "", format, textureWidth,
                                                          textureHeight);

    unsigned numTexGlyphs = in->ReadU16();
    if (in->IsVerboseParse())
        in->LogParse("  PadPixels = %d, nominal glyph size = %d, numTexGlyphs = %d\n", padPixels, nominalSize,
                     numTexGlyphs);

    Array<Render::TextureGlyph> texGlyphs;
    for (unsigned i = 0; i < numTexGlyphs; i++)
    {
        Render::RectF  uvBounds;
        Render::PointF uvOrigin;
        uvBounds.x1 = in->ReadFloat();
        uvBounds.y1 = in->ReadFloat();
        uvBounds.x2 = in->ReadFloat();
        uvBounds.y2 = in->ReadFloat();
        uvOrigin.x  = in->ReadFloat();
        uvOrigin.y  = in->ReadFloat();
        if (in->IsVerboseParse())
        {
            in->LogParse("  TEXGLYPH[%d]: uvBnd.x1 = %f, uvBnd.y1 = %f, uvBnd.x2 = %f, uvBnd.y2 = %f\n", i,
                         (double)uvBounds.x1, (double)uvBounds.y1, (double)uvBounds.x2, (double)uvBounds.y2);
            in->LogParse("                uvOrigin.x = %f, uvOrigin.y = %f\n", (double)uvOrigin.x,
                         (double)uvOrigin.y);
        }

        Render::TextureGlyph tg;
        if (rh.IsIndex())
            tg.BindIndex = rh.GetBindIndex();
        else if (Resource* pres = rh.GetResourcePtr())
        {
            if ((pres->GetResourceTypeCode() & Resource::RT_TypeCode_Mask) ==
                (Resource::RT_Image << Resource::RT_TypeCode_Shift))
                tg.pImage = static_cast<Render::Image*>(static_cast<ImageResource*>(pres)->GetImage());
        }
        tg.UvBounds = uvBounds;
        tg.UvOrigin = uvOrigin;
        texGlyphs.PushBack(tg);
    }

    unsigned numFonts = in->ReadU16();
    if (in->IsVerboseParse())
        in->LogParse("  NumFonts = %d\n", numFonts);
    for (unsigned i = 0; i < numFonts; i++)
    {
        UInt16        fontId = in->ReadU16();
        Render::Font* pfont  = p->GetFontData(ResourceId(fontId));
        if (!pfont)
            continue;

        TextureGlyphData* ptgd = (TextureGlyphData*)pfont->GetTextureGlyphData();
        if (ptgd)
            ptgd->AddRef();
        else
        {
            ptgd = SF_HEAP_NEW(pheap) TextureGlyphData(pfont->GetGlyphShapeCount(), true);
            if (ptgd)
            {
                TextureGlyphData::TextureConfig config;
                config.NominalSize   = nominalSize;
                config.PadPixels     = padPixels;
                config.TextureWidth  = textureWidth;
                config.TextureHeight = textureHeight;
                ptgd->SetTextureConfig(config);
                pfont->SetTextureGlyphData(ptgd);
            }
        }
        if (ptgd)
            ptgd->AddTexture(tid, rh);

        unsigned numGlyphsInFont = in->ReadU16();
        for (unsigned j = 0; j < numGlyphsInFont; j++)
        {
            UInt16 glyphIndex    = in->ReadU16();
            UInt16 texGlyphIndex = in->ReadU16();
            if (ptgd)
                ptgd->AddTextureGlyph(glyphIndex, texGlyphs[texGlyphIndex]);
        }
        if (ptgd)
            ptgd->Release();
    }
    in->LogParse("\n");
}

// DefineExternalGradientImage: a gradient image kept in a file of its own.
// MS2-FUNCTIONAL 0x1425c7840: same reads, log text and handle; the three inlined Stream::ReadU16 bodies schedule differently.
// @0x1425c7840
void SF_STDCALL GFx_DefineExternalGradientImageLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    Stream*  pin              = p->GetStream();

    unsigned    gradientId       = pin->ReadU16();
    unsigned    bitmapResourceId = gradientId | ResourceId::IdType_GradientImage;
    UInt16      bitmapFormat     = pin->ReadU16();
    UInt16      gradSize         = pin->ReadU16();

    String   imageFileName;
    pin->ReadStringWithLength(&imageFileName);

    pin->LogParse("  DefineExternalGradientImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', size = %d\n",
        tagInfo.TagType,
        bitmapResourceId,
        bitmapFormat,
        imageFileName.ToCStr(),
        gradSize);

    // Register image resource data.
    GFx_CreateImageFileResourceHandle(p, ResourceId(bitmapResourceId),
                                      imageFileName.ToCStr(), "", bitmapFormat,
                                      0, 0);
}

// What a sub-image request holds (sfr_gfx_07e).
struct SubImageResourceInfo : public RefCountBaseNTS<SubImageResourceInfo, Stat_Default_Mem>
{
    ResourceId         ImageId;        // +0x10
    Ptr<ImageResource> pImageResource; // +0x18
    Render::ImageRect  Rect;           // +0x20
};

class SubImageResourceCreator
{
public:
    static ResourceData CreateSubImageResourceData(SubImageResourceInfo* pinfo);
};

// DefineSubImage: a rectangle of an image defined before, created per binding.
// @0x1425c7a50
void SF_STDCALL GFx_DefineSubImageLoader(LoadProcess* p, const TagInfo&)
{
    unsigned bitmapResourceId   = p->ReadU16();
    unsigned baseImageId        = p->ReadU16();
    UInt16   left               = p->ReadU16();
    UInt16   top                = p->ReadU16();
    UInt16   right              = p->ReadU16();
    UInt16   bottom             = p->ReadU16();

    Ptr<SubImageResourceInfo> psubimage = *SF_NEW SubImageResourceInfo;
    psubimage->ImageId = ResourceId(baseImageId | ResourceId::IdType_DynFontImage);
    psubimage->Rect = Render::ImageRect(left, top, right, bottom);

    ResourceData rdata = SubImageResourceCreator::CreateSubImageResourceData(psubimage);
    p->AddDataResource(ResourceId(bitmapResourceId), rdata);
}

// DefineSceneAndFrameLabelData: the scenes of the main timeline and their frame labels (only the first such tag).
// @0x1425c7ca0
void SF_STDCALL GFx_DefineSceneAndFrameLabelDataLoader(LoadProcess* p, const TagInfo&)
{
    if (p->HasScenes()) // not first call, ignore
        return;

    Stream* in         = p->GetStream();
    UInt32  sceneCount = in->ReadVU32();

    p->LogParse("  Scene and Frame Label Data, numscenes = %d\n", sceneCount);

    for (UInt32 i = 0; i < sceneCount; ++i)
    {
        UInt32   off = in->ReadVU32();
        StringDH name(p->GetLoadHeap());
        in->ReadString(&name);

        p->LogParse("   Scene[%d] = { %d, \"%s\" }\n", i, off, name.ToCStr());
        p->AddScene(name, off);
    }
    UInt32 frameLabelCount = in->ReadVU32();
    p->LogParse("  frameLabelCount = %d\n", frameLabelCount);
    unsigned                 sceneIdx = 0;
    MovieDataDef::SceneInfo* curScene = p->GetScene(sceneIdx);
    for (UInt32 i = 0; i < frameLabelCount; ++i)
    {
        UInt32   num = in->ReadVU32();
        StringDH label(p->GetLoadHeap());
        in->ReadString(&label);

        p->LogParse("   Label[%d] = { %d, \"%s\" }\n", i, num, label.ToCStr());

        // check if this frame within the current scene
        MovieDataDef::SceneInfo* nextScene;
        while ((nextScene = p->GetScene(sceneIdx + 1)) != NULL && num >= nextScene->Offset)
        {
            curScene->NumFrames = nextScene->Offset;
            curScene            = nextScene;
            ++sceneIdx;
        }
        curScene->AddFrameLabel(label, num);
    }
    curScene->NumFrames = p->GetTotalFrames() - curScene->Offset;
}

// ---- LoadProcess helpers ----

// The file under the tag stream, positioned at the stream's read position; the stream re-reads it afterwards.
// @0x1425c8b50
File* LoadProcess::GetUnderlyingFile()
{
    return GetStream()->GetUnderlyingFile();
}

// @0x1425c8bb0
template void LogBase<LoadProcess>::LogWarning(const char* pfmt, ...) const;

// @0x1425c8c20
UInt32 FUN_1425c8c20(LoadProcess* p)
{
    return p->GetStream()->ReadU32(); // LoadProcess::ReadU32, out of line
}

} // namespace GFx
} // namespace Scaleform

// MS2-FUNCTIONAL: empty vtable slot (`ret 0`, no .pdata); referenced by data_data_game.
// @0x1425c6940
void FUN_1425c6940() {}

// MS2-FUNCTIONAL: vtable slot without .pdata: GFx tag 1004 (DefineGradientMap) loader: warns through the LoadProcess log at this + 0x20 and ignores the tag.
// @0x1425c7a40
void FUN_1425c7a40(void* self)
{
    ((Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>*)((Scaleform::UByte*)self + 0x20))->LogWarning("Deprecated tag 1004 - DefineGradientMapLoader encountered, ignored");
}
