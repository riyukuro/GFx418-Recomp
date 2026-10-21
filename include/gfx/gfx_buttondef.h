// Recovered Scaleform 4.1.18 GFx: the button definition (its state records, actions and sounds); CharacterDef is in
// gfx_characterdef.h.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Bodies: GFx_ButtonDef (sfr_gfx_08g).
#ifndef MS2_SF_GFX_BUTTONDEF_H
#define MS2_SF_GFX_BUTTONDEF_H

#include "gfx_characterdef.h"
#include "gfx_resource.h"
#include "gfx_stream.h"
#include "../kernel/sf_array.h"
#include "../kernel/sf_memory.h"
#include "../render/render_constants.h"
#include "../render/render_cxform.h"
#include "../render/render_filters.h"
#include "../render/render_matrix2x4.h"
#include "../render/render_types2d.h"

namespace Scaleform { namespace GFx {

class LoadProcess;
class ButtonSoundDef;

using Render::Cxform;
using Render::Matrix2F;

// The 9-slice scaling grid of a button or sprite.
struct Scale9Grid : public NewOverrideBase<Stat_Default_Mem>
{
    RectF Rect;
};

// One character shown by a button in some of its states (0x60 bytes).
class ButtonRecord
{
public:
    enum MouseState
    {
        MouseUp,
        MouseDown,
        MouseOver
    };

    enum RecordFlags
    {
        Mask_HitTest = 1,
        Mask_Down    = 2,
        Mask_Over    = 4,
        Mask_Up      = 8,
        Mask_All     = Mask_HitTest | Mask_Down | Mask_Over | Mask_Up
    };

    Matrix2F               ButtonMatrix; // +0
    Cxform                 ButtonCxform; // +0x20
    Ptr<Render::FilterSet> pFilters;     // +0x40
    ResourceId             CharacterId;  // +0x48
    UInt16                 Depth;        // +0x4c
    Render::BlendMode      BlendMode;    // +0x50
    UByte                  Flags;        // +0x54 RecordFlags

    ButtonRecord() : Flags(0) {}

    // Reads one record; false on the null record that ends the list.
    bool Read(LoadProcess* p, TagType tagType);

    bool IsHitTest() const { return (Flags & Mask_HitTest) != 0; }
    bool IsDown() const    { return (Flags & Mask_Down) != 0; }
    bool IsOver() const    { return (Flags & Mask_Over) != 0; }
    bool IsUp() const      { return (Flags & Mask_Up) != 0; }
};

// Actions of a button event; read by the ActionScript support (the AS2 one; AS3 buttons have none).
class ButtonActionBase : public RefCountBase<ButtonActionBase, StatMD_CharDefs_Mem>
{
protected:
    virtual ~ButtonActionBase() {}

public:
    virtual void Read(Stream* pin, TagType tagType, unsigned actionLength) = 0;
};

// A button definition (0x68 bytes, vftable 0x1431914b0).
class ButtonDef : public CharacterDef
{
    friend class Button;

protected:
    ButtonSoundDef*                                    pSound;        // +0x20
    ArrayLH<ButtonRecord, StatMD_CharDefs_Mem>          ButtonRecords; // +0x28
    ArrayLH<Ptr<ButtonActionBase>, StatMD_CharDefs_Mem> ButtonActions; // +0x40
    Scale9Grid*                                        pScale9Grid;   // +0x58
    bool                                               Menu;          // +0x60

public:
    ButtonDef();
    virtual ~ButtonDef();

    // Reads DefineButton, DefineButton2 or the ButtonSound tag of this button.
    void Read(LoadProcess* p, TagType tagType);

    virtual CharacterDefType GetType() const { return Button; }
    // A button's bounds depend on its state.
    virtual RectF GetBoundsLocal(float = 0) const { return RectF(); }

    virtual unsigned GetResourceTypeCode() const { return MakeTypeCode(RT_ButtonDef); }

    const ButtonRecord& GetRecordAt(UPInt i) const { return ButtonRecords[i]; }
    UPInt               GetRecordsCount() const    { return ButtonRecords.GetSize(); }

    const ButtonActionBase* GetButtonAction(UPInt i) const { return ButtonActions[i].GetPtr(); }
    UPInt                   GetButtonActionsCount() const  { return ButtonActions.GetSize(); }

    void AddButtonAction(ButtonActionBase* pact);
};

}} // namespace Scaleform::GFx

#endif
