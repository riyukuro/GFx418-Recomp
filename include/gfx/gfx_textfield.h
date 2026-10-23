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

    // (appended, sfr19) IME (AS3 IME manager, sfr_as3_20).
    bool IsReadOnly() const;                             // exe 0x1425b9b10
    // The IME may write into it: not IME-disabled, not read-only, not a password field.
    bool IsIMEEnabled() const
    {
        return !IsIMEDisabledFlag() && !IsReadOnly() && !IsPassword();
    }
    // Gives the candidate list movie the field's font (exe 0x1425bbd70).
    void SetCandidateListFont(DisplayObject* pcandidateList);
    bool IsIMEDisabledFlag() const { return (GetFlags418() & 0x800) != 0; }
    bool IsPassword() const        { return (GetFlags418() & 0x4) != 0; }
    UInt32 GetFlags418() const     { return *reinterpret_cast<const UInt32*>(Unrecovered + 0xfc); }  // +0xfc Flags

private:
    UByte Unrecovered[0x148];
};

}} // namespace Scaleform::GFx

#endif
