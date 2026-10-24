// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18, the packed path record writers of
// PathDataEncoder over ArrayLH_POD<UByte, 2>: the glyph outline shapes of the WinAPI font provider (sfr_render_04o,
// ExternalFontWinAPI::decomposeGlyphOutline) are packed through them, and the exe keeps the instances in that TU.
// Ninth source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426499b0-0x14264ba40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "../include/render/render_shapedata.h"

namespace Scaleform { namespace Render {

typedef PathDataEncoder<ArrayLH_POD<UByte, 2> > GlyphPathEncoder;

// @0x1426499b0
template unsigned GlyphPathEncoder::WriteEndPath();
// @0x142649a20
template unsigned GlyphPathEncoder::WriteHLine(int x);
// @0x142649c40
template unsigned GlyphPathEncoder::WriteLine(int x, int y);
// @0x14264a240
template unsigned GlyphPathEncoder::WriteQuad(int cx, int cy, int ax, int ay);
// @0x14264b390
template unsigned GlyphPathEncoder::WriteSInt30(int v);
// @0x14264b6f0
template unsigned GlyphPathEncoder::WriteUInt15(unsigned v);
// @0x14264b820
template unsigned GlyphPathEncoder::WriteVLine(int y);

}} // namespace Scaleform::Render
