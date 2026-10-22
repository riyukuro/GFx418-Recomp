// Recovered Scaleform 4.1.18 GFx: ImageResource, the resource wrapper of an image (bitmaps of the SWF, image files
// loaded as movies, gradients and font textures). Shared header of the src/ms2/scaleform units (sfr lane): append, do
// not reorder.
//
// Layout (0x68 bytes, vftable 0x143149bf8) from MovieDataDef::LoadTaskData::InitImageFileMovieDef.
#ifndef MS2_SF_GFX_IMAGERESOURCE_H
#define MS2_SF_GFX_IMAGERESOURCE_H

#include "gfx_resource.h"
#include "../render/render_image.h"

namespace Scaleform { namespace GFx {

class FileOpener;
class ImageCreator;

class ImageResource : public Resource
{
protected:
    // An Image is held through Delegate (whose references count on this resource); an image source is held
    // directly with a reference of its own.
    Render::ImageBase* pImage; // +0x18

    // The image as a Render::Image that keeps this resource alive (vftable 0x143149b10).
    class ImageDelegate : public Render::ImageDelegate
    {
        ImageResource* GetImageResource()
        {
            return (ImageResource*)((UByte*)this - offsetof(ImageResource, Delegate));
        }

    public:
        virtual void AddRef()  { GetImageResource()->AddRef(); }  // exe 0x142440e40
        virtual void Release() { GetImageResource()->Release(); } // exe 0x142446130
    } Delegate; // +0x20

    ResourceKey Key;     // +0x50 the file data, for image files
    ResourceUse UseType; // +0x60

public:
    ImageResource(Render::Image* pimage, ResourceUse use = Use_Bitmap) : pImage(0)
    {
        SetImage(pimage);
        UseType = use;
    }
    // (sfr_gfx_07e) an image file's image, with its key
    ImageResource(Render::Image* pimage, const ResourceKey& key, ResourceUse use = Use_Bitmap) : pImage(0)
    {
        SetImage(pimage);
        Key     = key;
        UseType = use;
    }
    ~ImageResource(); // exe 0x14243d330, out of line (sfr_as3_06): both deleting dtors call it

    const Render::ImageBase* GetImage() const { return pImage; }
    Render::ImageBase*       GetImage()       { return pImage; }

    void SetImageSource(Render::ImageSource* pimageSrc)
    {
        if (pImage && pImage != &Delegate)
            pImage->Release();
        pImage          = pimageSrc;
        Delegate.pImage = 0;
        if (pImage)
            pImage->AddRef();
    }
    void SetImage(Render::Image* pimage)
    {
        if (pImage && pImage != &Delegate)
            pImage->Release();
        Delegate.pImage = pimage;
        pImage          = &Delegate;
    }

    // (sfr_gfx_07e) the library key of an image file (exe 0x1426be9c0, sfr_gfx_08c)
    static ResourceKey CreateImageFileKey(ImageFileInfo* pfileInfo, FileOpener* pfileOpener,
                                          ImageCreator* pimageCreator, MemoryHeap* pimageHeap);

    virtual ResourceId GetBaseImageId() { return ResourceId(0); }

    virtual ResourceKey GetKey()                    { return Key; }
    virtual ResourceUse GetImageUse()               { return UseType; }
    virtual unsigned    GetResourceTypeCode() const { return MakeTypeCode(RT_Image, UseType); }
};

}} // namespace Scaleform::GFx

#endif
