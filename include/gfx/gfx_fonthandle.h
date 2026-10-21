// Recovered Scaleform 4.1.18 GFx: FontHandle, the GFx flavour of a resolved font reference (it also keeps the movie
// the font came from alive). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// 0x40 bytes, vftable 0x143189e70 (Render::Text::FontHandle's: 0x1431899e8). The exe's out-of-line ctor is
// 0x1425b5800 and its deleting dtor 0x1425b61f0 (GFx_FontManager); GFx_StaticText inlines the ctor.
#ifndef MS2_SF_GFX_FONTHANDLE_H
#define MS2_SF_GFX_FONTHANDLE_H

#include "gfx_resource.h"
#include "../render/render_font.h"
#include "../render/text_core.h"

namespace Scaleform { namespace Render { namespace Text {

inline FontHandle::FontHandle(FontManagerBase* pmgr, Font* pfont, const char* name, unsigned flags)
    : pFontManager(pmgr), FontFlags(flags), FontScaleFactor(1.0f)
{
    if (pfont)
        pfont->AddRef();
    pFont = pfont;
    if (name && String::CompareNoCase(pfont->GetName(), name) != 0)
        FontName = name;
}

}}} // namespace Scaleform::Render::Text

namespace Scaleform { namespace GFx {

class FontHandle : public Render::Text::FontHandle
{
public:
    // The source movie argument of the exe's ctor is left out: the recovered callers pass none.
    FontHandle(Render::Text::FontManagerBase* pmgr, Render::Font* pfont, const char* name = 0, unsigned flags = 0)
        : Render::Text::FontHandle(pmgr, pfont, name, flags)
    {
    }

    Ptr<Resource> pSourceMovieDef; // +0x38 a Ptr<MovieDef> (MovieDef derives from Resource first)
};

}} // namespace Scaleform::GFx

#endif
