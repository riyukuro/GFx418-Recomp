// Recovered Scaleform 4.1.18 Render: the font cache handles (Render_FontCacheHandle, sfr_render_07k). The renderer's
// manager hands every Font that reaches the glyph cache a handle; a font that dies moves its handle to the kill list,
// and the render thread drops those handles' glyphs from the cache when it processes the list.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout checked against RegisterFont 0x1426d4930 and destroyFontList_NTS 0x1426d49f0.
#ifndef MS2_SF_RENDER_FONTCACHEHANDLE_H
#define MS2_SF_RENDER_FONTCACHEHANDLE_H

#include "ms2/scaleform/kernel/sf_list.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/include/render/render_font.h"

namespace Scaleform { class MemoryHeap; }

namespace Scaleform { namespace Render {

class GlyphCache;

// One per renderer; the lock guards both lists, as fonts die on any thread. 0x68 bytes.
class FontCacheHandleManager : public RefCountBase<FontCacheHandleManager, Stat_Default_Mem>
{
    friend class FontCacheHandleRef;

public:
    FontCacheHandleManager(MemoryHeap* renderHeap, GlyphCache* cache = 0) : pRenderHeap(renderHeap), pCache(cache) { }
    ~FontCacheHandleManager() { DestroyAllFonts(); }

    // drops the glyphs of the fonts that died since the last call
    void ProcessKillList();
    // drops every handle; the renderer is shutting down
    void DestroyAllFonts();

    // the font's handle, made (and listed live) on first use; 0 when out of memory
    FontCacheHandle* RegisterFont(Font* font);

private:
    enum FontListType
    {
        Font_LiveList,
        Font_KillList,
        Font_List_Count
    };

    // a font died: its handle moves to the kill list (FontCacheHandleRef::releaseFont)
    void fontLost(FontCacheHandleRef* href);
    // empties one list, the caller holding the lock
    void destroyFontList_NTS(FontListType type);

    Lock                  FontLock;                  // +0x10
    List<FontCacheHandle> Fonts[Font_List_Count];    // +0x38
    MemoryHeap*           pRenderHeap;               // +0x58
    GlyphCache*           pCache;                    // +0x60
};

// 0x20 bytes, from the render heap
class FontCacheHandle : public ListNode<FontCacheHandle>, public NewOverrideBase<StatRender_Font_Mem>
{
public:
    FontCacheHandle(FontCacheHandleManager* manager, Font* font) : pManager(manager), pFont(font) { }

    FontCacheHandleManager* pManager;   // +0x10
    Font*                   pFont;      // +0x18: 0 once the font died
};

}} // namespace Scaleform::Render

#endif
