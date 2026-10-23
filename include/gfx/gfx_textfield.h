// Recovered Scaleform 4.1.18 GFx: TextField (dynamic / input text instances). Shared header of the src/ms2/scaleform
// units (sfr lane): append, do not reorder.
// OPAQUE for now: 0x148 bytes and the constructor (as the AS3 character factory allocates and builds it); the full
// declaration comes with the GFx_TextField units. Used through its DisplayObjectBase part (offset 0).
#ifndef MS2_SF_GFX_TEXTFIELD_H
#define MS2_SF_GFX_TEXTFIELD_H

#include "ms2/scaleform/include/gfx/gfx_characterdef.h"
#include "ms2/scaleform/include/gfx/gfx_displayobject.h"

namespace Scaleform { namespace GFx {

// The edit text definition (a struct in 4.1.18, as the TextField constructor's mangled name has it); members
// unrecovered.
struct TextFieldDef : public CharacterDef
{
};

class TextField
{
public:
    TextField(TextFieldDef* def, MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* parent,
              ResourceId id);
    operator DisplayObjectBase*() { return reinterpret_cast<DisplayObjectBase*>(this); }

    // Selection (AS2 Selection natives, sfr_as2_02).
    SPInt GetCaretIndex() const;                         // exe 0x1425b7e70
    UPInt GetBeginIndex() const;                         // exe 0x1425b7df0
    UPInt GetEndIndex() const;                           // exe 0x1425b8220
    void  SetSelection(SPInt beginIndex, SPInt endIndex); // exe 0x1425bcfc0

private:
    UByte Unrecovered[0x148];
};

}} // namespace Scaleform::GFx

#endif
