// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the font cache handles
// (Render_FontCacheHandle): the renderer's registry of the fonts the glyph cache holds glyphs of, and the font side
// of the link that hands a dying font's handle to the render thread.
// Queue unit sfr_render_07 is split along its original sources (07k Render_FontCacheHandle).
// MS2-UNIT: sfr_render_07k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426d4780-0x1426d4bf0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_fontcachehandle.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_glyphcache.h"

namespace Scaleform { namespace Render {

// ----- FontCacheHandleManager

// @0x1426d4780
void FontCacheHandleManager::DestroyAllFonts()
{
    Lock::Locker lock(&FontLock);
    destroyFontList_NTS(Font_KillList);
    destroyFontList_NTS(Font_LiveList);
}

// @0x1426d4880
void FontCacheHandleManager::ProcessKillList()
{
    Lock::Locker lock(&FontLock);
    destroyFontList_NTS(Font_KillList);
}

// @0x1426d4930
FontCacheHandle* FontCacheHandleManager::RegisterFont(Font* font)
{
    // the font holds the manager, so the manager outlives the font's handle
    if (!font->hRef.pManager)
    {
        AddRef();
        font->hRef.pManager = this;
    }
    if (!font->hRef.pFontHandle)
    {
        Lock::Locker lock(&FontLock);
        font->hRef.pFontHandle = SF_HEAP_NEW(pRenderHeap) FontCacheHandle(this, font);
        if (!font->hRef.pFontHandle)
            return 0;
        Fonts[Font_LiveList].PushBack(font->hRef.pFontHandle);
    }
    return font->hRef.pFontHandle;
}

// @0x1426d49f0
void FontCacheHandleManager::destroyFontList_NTS(FontListType type)
{
    List<FontCacheHandle>& fonts = Fonts[type];
    if (fonts.IsEmpty())
        return;

    bool             freedSlots = false;
    FontCacheHandle* handle     = fonts.GetFirst();
    while (!fonts.IsNull(handle))
    {
        FontCacheHandle* next = handle->pNext;
        if (type != Font_KillList)
        {
            // a live font: cut it loose, it registers again with the next renderer
            handle->pFont->hRef.pFontHandle = 0;
            handle->pFont->hRef.releaseFont_NoNotify();
            handle->pFont = 0;
        }
        else if (pCache)
        {
            // a dead font: its glyphs go
            pCache->CleanUpFont(handle);
            freedSlots = true;
        }
        delete handle;
        handle = next;
    }
    fonts.Clear();
    if (freedSlots)
        pCache->MergeCacheSlots();
}

// @0x1426d4ac0
void FontCacheHandleManager::fontLost(FontCacheHandleRef* href)
{
    Lock::Locker lock(&FontLock);
    FontCacheHandle* handle = href->pFontHandle;
    if (handle)
    {
        handle->RemoveNode();
        Fonts[Font_KillList].PushBack(handle);
        handle->pFont = 0;
    }
}

// ----- FontCacheHandleRef

// @0x1426d4b40
void FontCacheHandleRef::releaseFont()
{
    FontCacheHandleManager* manager = pManager.Exchange_NoSync(0);
    if (manager)
    {
        manager->fontLost(this);
        manager->Release();
    }
}

// @0x1426d4bd0
void FontCacheHandleRef::releaseFont_NoNotify()
{
    FontCacheHandleManager* manager = pManager.Exchange_NoSync(0);
    if (manager)
        manager->Release();
}

}} // namespace Scaleform::Render
