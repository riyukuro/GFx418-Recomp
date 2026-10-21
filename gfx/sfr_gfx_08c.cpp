// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ImageResource (the resource
// library key of an image file: the file info plus the states and heap the image is loaded with).
// Third source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426be7c0-0x1426beae0 .text$mn   (0x1426beae0..: D3D9 render queue items and HAL, not this TU)

#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_resource.h"
#include "../include/kernel/sf_memory.h"

namespace Scaleform { namespace GFx {

// Creates images for the loader (0x20 bytes).
class ImageCreator : public State
{
    void* pTextureManager; // +0x18
};

// File info of an image resource; the image dimensions follow the base fields.
struct ImageFileInfo : public ResourceFileInfo
{
};

class ImageResource : public Resource
{
public:
    static ResourceKey CreateImageFileKey(ImageFileInfo* pfileInfo, FileOpener* pfileOpener,
                                          ImageCreator* pimageCreator, MemoryHeap* pimageHeap);
};

// The key handle (0x30 bytes). The heap is part of the key so that equal files loaded into different heaps stay
// separate resources.
class ImageFileInfoKeyData : public RefCountBase<ImageFileInfoKeyData, Stat_Default_Mem>
{
    Ptr<FileOpener>   pFileOpener;   // +0x10
    Ptr<ImageCreator> pImageCreator; // +0x18
    MemoryHeap*       pImageHeap;    // +0x20

public:
    Ptr<ImageFileInfo> pFileInfo; // +0x28

    ImageFileInfoKeyData(ImageFileInfo* pfileInfo, FileOpener* pfileOpener, ImageCreator* pimageCreator,
                         MemoryHeap* pimageHeap)
    {
        pFileInfo     = pfileInfo;
        pFileOpener   = pfileOpener;
        pImageCreator = pimageCreator;
        pImageHeap    = pimageHeap;
    }

    bool operator==(const ImageFileInfoKeyData& other) const
    {
        return pFileOpener == other.pFileOpener && pImageCreator == other.pImageCreator &&
               pImageHeap == other.pImageHeap && pFileInfo->FileName == other.pFileInfo->FileName;
    }

    UPInt GetHashCode() const
    {
        return pFileInfo->GetHashCode() ^ (UPInt)pFileOpener.GetPtr() ^ ((UPInt)pFileOpener.GetPtr() >> 7) ^
               (UPInt)pImageCreator.GetPtr() ^ ((UPInt)pImageCreator.GetPtr() >> 7) ^ (UPInt)pImageHeap ^
               ((UPInt)pImageHeap >> 7);
    }
};

class ImageFileKeyInterface : public ResourceKey::KeyInterface
{
public:
    typedef ResourceKey::KeyHandle KeyHandle;

    virtual void AddRef(KeyHandle hdata) { ((ImageFileInfoKeyData*)hdata)->AddRef(); }
    virtual void Release(KeyHandle hdata) { ((ImageFileInfoKeyData*)hdata)->Release(); }
    virtual ResourceKey::KeyType GetKeyType(KeyHandle) const { return ResourceKey::Key_File; }
    virtual UPInt GetHashCode(KeyHandle hdata) const;
    virtual bool  KeyEquals(KeyHandle hdata, const ResourceKey& other);
    virtual const char* GetFileURL(KeyHandle hdata) const;
};

static ImageFileKeyInterface ImageFileKeyInterface_Instance;

// @0x1426be7c0
UPInt ImageFileKeyInterface::GetHashCode(KeyHandle hdata) const
{
    return ((ImageFileInfoKeyData*)hdata)->GetHashCode();
}

// @0x1426be810
bool ImageFileKeyInterface::KeyEquals(KeyHandle hdata, const ResourceKey& other)
{
    if (other.GetKeyInterface() != this)
        return false;
    return *(ImageFileInfoKeyData*)hdata == *(ImageFileInfoKeyData*)other.GetKeyData();
}

// @0x1426be880
const char* ImageFileKeyInterface::GetFileURL(KeyHandle hdata) const
{
    return ((ImageFileInfoKeyData*)hdata)->pFileInfo->FileName.ToCStr();
}

// @0x1426be9c0
ResourceKey ImageResource::CreateImageFileKey(ImageFileInfo* pfileInfo, FileOpener* pfileOpener,
                                              ImageCreator* pimageCreator, MemoryHeap* pimageHeap)
{
    MemoryHeap*               pheap = pimageHeap ? pimageHeap : Memory::GetGlobalHeap();
    Ptr<ImageFileInfoKeyData> pdata =
        *SF_HEAP_NEW(pheap) ImageFileInfoKeyData(pfileInfo, pfileOpener, pimageCreator, pimageHeap);
    return ResourceKey(&ImageFileKeyInterface_Instance, pdata.GetPtr());
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7KeyInterface@ResourceKey@GFx@Scaleform@@6B@ 0x14318b240
// MS2-PIN: ??_7ImageFileKeyInterface@GFx@Scaleform@@6B@ 0x143192a20
// MS2-PIN: ??_7?$RefCountBase@VImageFileInfoKeyData@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143192a58
// MS2-PIN: ??_7ImageFileInfoKeyData@GFx@Scaleform@@6B@ 0x143192a60
// MS2-PIN: ??_GImageFileKeyInterface@GFx@Scaleform@@UEAAPEAXI@Z 0x1426be8a0
// MS2-PIN: ??_G?$RefCountBase@VImageFileInfoKeyData@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1426be8d0
