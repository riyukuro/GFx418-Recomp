// Recovered Scaleform 4.1.18 GFx: ImageFileHandlerRegistry, the loader state that holds the image file handlers. It is a
// State and a Render::ImageFileHandlerRegistry. Code that reads an image through it upcasts to the Render base at +0x18
// (null-checked; GFxAtlasCache 0x1422f78bf) and calls ReadImage through the Render vftable (slot 1).
// gfx_imagecreator.h and gfx_loaderimpl.h only forward-declare it.
#ifndef MS2_SF_GFX_IMAGEFILEHANDLERREGISTRY_H
#define MS2_SF_GFX_IMAGEFILEHANDLERREGISTRY_H

#include "ms2/scaleform/include/gfx/gfx_state.h"
#include "ms2/scaleform/include/gfx/gfx_moviedef.h"   // (appended) StateBag::SetImageFileHandlerRegistry
#include "ms2/scaleform/include/render/render_imagefile.h"

namespace Scaleform { namespace GFx {

class ImageFileHandlerRegistry : public State, public Render::ImageFileHandlerRegistry
{
public:
    // (appended for the game's GFxManager; /Od COMDAT there) an empty registry the handlers are added to.
    ImageFileHandlerRegistry() : State(State_ImageFileHandlerRegistry), Render::ImageFileHandlerRegistry(0) {}

    void AddHandler(Render::ImageFileHandler* handler);
};

inline void StateBag::SetImageFileHandlerRegistry(ImageFileHandlerRegistry* ptr)
{
    SetState(State::State_ImageFileHandlerRegistry, ptr);
}

}} // namespace Scaleform::GFx

#endif
