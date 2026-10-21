// Recovered Scaleform 4.1.18 Render Text: FontManagerBase, the font lookup interface the text views resolve
// TextFormat font names through (implemented by GFx::FontManager).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXT_FONTMANAGER_H
#define MS2_SF_RENDER_TEXT_FONTMANAGER_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/include/render/render_stats.h"
#include "ms2/scaleform/include/render/text_core.h"

namespace Scaleform { namespace Render { namespace Text {

class FontManagerBase : public RefCountBase<FontManagerBase, StatRender_Text_Mem>
{
    friend class FontHandle;

public:
    // where a font search looked, for the "font not found" log
    struct FontSearchPathInfo
    {
        FontSearchPathInfo(int indent = 0) : Indent(indent) {}
        int          Indent;
        StringBuffer Info;
    };

    virtual ~FontManagerBase() {}
    virtual FontHandle* CreateFontHandle(const char* pfontName, unsigned matchFontFlags, bool allowListOfFonts = true,
                                         FontSearchPathInfo* searchInfo = NULL) = 0;
    virtual FontHandle* GetEmptyFont() = 0;
    virtual void        CleanCache()   = 0;

    FontHandle* CreateFontHandle(const char* pfontName, bool bold, bool italic, bool device,
                                 bool allowListOfFonts = true, FontSearchPathInfo* searchInfo = NULL)
    {
        // Font::FF_Bold 2, FF_Italic 1, FF_DeviceFont 0x10
        unsigned matchFontFlags = (bold ? 0x2u : 0) | (italic ? 0x1u : 0) | (device ? 0x10u : 0);
        return CreateFontHandle(pfontName, matchFontFlags, allowListOfFonts, searchInfo);
    }
};

}}} // namespace Scaleform::Render::Text

#endif
