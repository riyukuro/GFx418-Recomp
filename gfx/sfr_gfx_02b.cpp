// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 font provider state (Win32 GDI).
// Second source of queue unit sfr_gfx_02 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_02b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14259d970-0x14259dc90 .text$mn

#include "../include/gfx/gfx_fontprovider.h"

namespace Scaleform { namespace GFx {

// @0x14259dab0
FontProvider::~FontProvider()
{
}

// The renderer's provider comes from the global heap.
// @0x14259d970
FontProviderWin32::FontProviderWin32(HDC dc)
    : FontProvider(*new Render::FontProviderWinAPI(dc))
{
}

// @0x14259da10
FontProviderWin32::FontProviderWin32(HDC dc, MemoryHeap* heap)
    : FontProvider(*new (heap) Render::FontProviderWinAPI(dc))
{
}

// @0x14259dc30
void FontProviderWin32::SetHinting(const char* name, Render::Font::NativeHintingRange vectorRange,
                                   Render::Font::NativeHintingRange rasterRange, unsigned maxVectorHintedSize,
                                   unsigned maxRasterHintedSize)
{
    GetWinAPI()->SetHinting(name, vectorRange, rasterRange, maxVectorHintedSize, maxRasterHintedSize);
}

// @0x14259dc40
void FontProviderWin32::SetHintingAllFonts(Render::Font::NativeHintingRange vectorRange,
                                           Render::Font::NativeHintingRange rasterRange, unsigned maxVectorHintedSize,
                                           unsigned maxRasterHintedSize)
{
    GetWinAPI()->SetHintingAllFonts(vectorRange, rasterRange, maxVectorHintedSize, maxRasterHintedSize);
}

}} // namespace Scaleform::GFx

// The exe's lb5 labels of the two deleting destructors are swapped (the bodies are identical): the one in the
// FontProvider vftable (0x143184ef0) is 0x14259daf0. 0x14259dc40 is labelled GetCSSData (identical-code folding).
// The inline virtual forwarders sit after the deleting destructors (0x14259dbf0..0x14259dc20); 0x14259d960, which lb5
// calls FontProvider::LoadFontNames, is not the vftable slot and is left outside this unit's range.
// MS2-PIN: ?CreateFontA@FontProvider@GFx@Scaleform@@UEAAPEAVFont@Render@3@PEBDI@Z 0x14259dbf0
// MS2-PIN: ?CreateFontA@FontProviderWin32@GFx@Scaleform@@UEAAPEAVFont@Render@3@PEBDI@Z 0x14259dc00
// MS2-PIN: ?LoadFontNames@FontProvider@GFx@Scaleform@@UEAAXAEAV?$StringHash@VString@Scaleform@@U?$AllocatorGH@VString@Scaleform@@$01@2@@3@@Z 0x14259dc10
// MS2-PIN: ?LoadFontNames@FontProviderWin32@GFx@Scaleform@@UEAAXAEAV?$StringHash@VString@Scaleform@@U?$AllocatorGH@VString@Scaleform@@$01@2@@3@@Z 0x14259dc20
// MS2-PIN: ??_7FontProvider@GFx@Scaleform@@6B@ 0x143184ef0
// MS2-PIN: ??_7FontProviderWin32@GFx@Scaleform@@6B@ 0x143184f08
// MS2-PIN: ??_GFontProvider@GFx@Scaleform@@UEAAPEAXI@Z 0x14259daf0
// MS2-PIN: ??_GFontProviderWin32@GFx@Scaleform@@UEAAPEAXI@Z 0x14259db70
// MS2-PIN: ?SetHintingAllFonts@FontProviderWin32@GFx@Scaleform@@QEAAXW4NativeHintingRange@Font@Render@3@0II@Z 0x14259dc40
// MS2-PIN: ?SetHinting@FontProviderWin32@GFx@Scaleform@@QEAAXPEBDW4NativeHintingRange@Font@Render@3@1II@Z 0x14259dc30
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
