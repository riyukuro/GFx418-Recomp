// Recovered Scaleform 4.1.18 GFx: StaticTextSnapshotData, the static text of a clip gathered for the text snapshot API.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Only the members called from recovered units so far; the class layout is not recovered yet.
#ifndef MS2_SF_GFX_TEXTSNAPSHOT_H
#define MS2_SF_GFX_TEXTSNAPSHOT_H

namespace Scaleform { namespace GFx {

class StaticTextCharacter;

class StaticTextSnapshotData
{
public:
    // Appends the glyph runs of one static text field (0x1425e0720).
    void Add(StaticTextCharacter* ptext);
};

}} // namespace Scaleform::GFx

#endif
