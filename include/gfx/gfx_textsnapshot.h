// Recovered Scaleform 4.1.18 GFx: StaticTextSnapshotData, the static text of a clip gathered for the text snapshot API.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Only the members called from recovered units so far; the class layout is not recovered yet.
#ifndef MS2_SF_GFX_TEXTSNAPSHOT_H
#define MS2_SF_GFX_TEXTSNAPSHOT_H

#include "../kernel/sf_string.h"
#include "../render/render_color.h"

namespace Scaleform { namespace GFx {

class StaticTextCharacter;

class StaticTextSnapshotData
{
public:
    ~StaticTextSnapshotData(); // 0x1424aa050

    // Appends the glyph runs of one static text field (0x1425e0720).
    void Add(StaticTextCharacter* ptext);

    // Script queries (TextSnapshot natives). Character ranges are [start, end).
    UPInt  GetCharCount() const;                                            // 0x1425e1360
    // Index of the first match at or after start, -1 if none (FindTextA: the name collides with the Win32 macro
    // in the original build).
    int    FindTextA(UPInt start, const char* query, bool caseSensitive) const; // 0x1425e1020
    String GetSelectedText(bool inclLineEndings) const;                     // 0x1425e1570
    String GetSubString(UPInt start, UPInt end, bool inclLineEndings) const; // 0x1425e1740
    bool   IsSelected(UPInt start, UPInt end) const;                        // 0x1425e1bc0
    void   SetSelectColor(const Render::Color& color);                      // 0x1425e2b40
    void   SetSelected(UPInt start, UPInt end, bool selected) const;        // 0x1425e2bb0
};

}} // namespace Scaleform::GFx

#endif
