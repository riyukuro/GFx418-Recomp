// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_TagLoaders: the rest of the tag
// loaders (DefineBitsJPEG3, morph shapes, lossless bitmaps, exports, scale9 grids, the GFx external image / font
// texture / sub image tags, scene and frame labels) and the compiler-generated helpers emitted with them (folded
// deleting destructors, array / hash template members, the LoadProcess readers).
// Third source of queue unit sfr_gfx_04 (sfr_gfx_04b is the second; sf-remaining2 cluster 1).
// MS2-UNIT: sfr_gfx_04x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425c48e0-0x1425c4b70 .text$mn
// MS2-RANGE: 0x1425c4d00-0x1425c4db0 .text$mn
// MS2-RANGE: 0x1425c5bb0-0x1425c5d70 .text$mn
// MS2-RANGE: 0x1425c80e0-0x1425c8250 .text$mn
// MS2-RANGE: 0x1425c8250-0x1425c8550 .text$mn
// MS2-RANGE: 0x1425c8580-0x1425c8670 .text$mn
// MS2-RANGE: 0x1425c86a0-0x1425c88d0 .text$mn
// MS2-RANGE: 0x1425c8b50-0x1425c8ca0 .text$mn
// MS2-RANGE: 0x1425c8d10-0x1425c8fe0 .text$mn
// MS2-RANGE: 0x1425c90f0-0x1425c9190 .text$mn
// MS2-RANGE: 0x1425c9280-0x1425c92ab .text$mn
// MS2-PIN: ??_7ExtraData@JPEG@Render@Scaleform@@6B@ 0x14318a288
// MS2-PIN: ??_7TextureGlyph@Render@Scaleform@@6B@ 0x14318a2b0
// MS2-PIN: ??_7?$RefCountBase@VTextureGlyph@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318a2a8

#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/gfx/gfx_fontresource.h"
#include "../include/gfx/gfx_shapeswf.h"
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

// A DefineMorphShape character (0x38 bytes; not recovered yet): constructed and read here, used as the Resource it is.
class MorphCharacterDef : public NewOverrideBase<StatMD_CharDefs_Mem>
{
    UByte Data[0x38];

public:
    MorphCharacterDef();
    void Read(LoadProcess* p, const TagInfo& tagInfo, bool withStyle);

    Resource* GetResource() { return reinterpret_cast<Resource*>(this); }
};

enum { Tag_DefineBitsJpeg4 = 90 };

// DefineBitsJPEG3 / 4: a JPEG followed by its zlib-compressed alpha plane, kept compressed in memory.
// MS2-FUNCTIONAL 0x1425c48e0: same reads, checks, log text and objects; register allocation and the null-heap
// fallback differ.
// @0x1425c48e0
void SF_STDCALL GFx_DefineBitsJpeg3Loader(LoadProcess* p, const TagInfo& tagInfo)
{
    ResourceId rid(p->ReadU16());
    UInt32     alphaOffset = p->ReadU32();
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
    ResourceId rid(p->ReadU16());
    p->LogParse("  ShapeMorphLoader: id = %d\n", rid.GetIdIndex());

    MorphCharacterDef* pmorph = SF_HEAP_NEW(p->GetLoadHeap()) MorphCharacterDef();
    pmorph->Read(p, tagInfo, true);
    p->AddResource(rid, pmorph ? pmorph->GetResource() : 0);
    if (pmorph)
        pmorph->GetResource()->Release();
}

// ExportAssets: the exported symbol names of the file's characters.
// MS2-FUNCTIONAL 0x1425c5bb0: same reads, lookups and log text; the id read and the string release inline
// differently.
// @0x1425c5bb0
void SF_STDCALL GFx_ExportLoader(LoadProcess* p, const TagInfo&)
{
    unsigned count = p->ReadU16();
    p->LogParse("  export: count = %d\n", count);
    for (unsigned i = 0; i < count; i++)
    {
        UInt16   id = p->GetStream()->ReadU16();
        StringDH symbolName(p->GetLoadHeap());
        p->GetStream()->ReadString(&symbolName);
        p->LogParse("  export: id = %d, name = %s\n", id, symbolName.ToCStr());

        ResourceHandle hres;
        if (p->GetResourceHandle(&hres, ResourceId(id)))
            p->ExportResource(symbolName, ResourceId(id), hres);
        else
            p->LogError("Don't know how to export Resource '%s'", symbolName.ToCStr());
    }
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
    return p->ReadU32();
}

} // namespace GFx
} // namespace Scaleform
