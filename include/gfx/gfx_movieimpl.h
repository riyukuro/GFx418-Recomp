// Recovered Scaleform 4.1.18 GFx: the movie implementation (MovieImpl), as far as the recovered units call into it.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder. The bases (Movie :
// RefCountBase, StateBag) are not recovered yet; their words are kept as placeholders up to the members read.
#ifndef MS2_SF_GFX_MOVIEIMPL_H
#define MS2_SF_GFX_MOVIEIMPL_H

#include "../kernel/sf_refcount.h"

namespace Scaleform { namespace GFx {

class ASMovieRootBase;
class DisplayObjectBase;
class InteractiveObject;
class MovieDefImpl;
class FontManager;
}
class MemoryHeap;
namespace GFx {

class MovieImpl
{
public:
    void*            MovieBase_Unrecovered[3]; // +0x00 RefCountBase vftable + count, StateBag vftable
    ASMovieRootBase* pASMovieRoot;             // +0x18 Ptr<ASMovieRootBase>: the AVM specific root
    void*            Unrecovered_20[4];        // +0x20
    MemoryHeap*      pHeap;                    // +0x40 the movie's heap
    void*            Unrecovered_48;           // +0x48
    InteractiveObject* pMainMovie;             // +0x50 _level0
    void*            Unrecovered_58[0x5b1];    // +0x58
    // A character the timeline keeps advancing even when stopped (MS2 build; Sprite::CheckAdvanceStatus).
    DisplayObjectBase* pKeepAdvancingChar;     // +0x2de0
    void*            Unrecovered_2de8[0xf];    // +0x2de8

    // Keyboard focus state of one focus group (one per controller group; 0x60 bytes, 16-aligned).
    struct FocusGroupDescr
    {
        UByte   Unrecovered_00[0x28];      // +0x00 focus rect node, tabable array
        mutable WeakPtr<InteractiveObject> LastFocused;   // +0x28 the focused character
        UByte   Unrecovered_30[0x20];      // +0x30 modal clip, last focus key, last focused rect
        bool    FocusRectShown;            // +0x50 the focus rectangle is up (focus moved by keyboard)
        UByte   Unrecovered_51[0xf];
    };
    FocusGroupDescr  FocusGroups[16];          // +0x2e60
    UInt32           Unrecovered_3460;         // +0x3460
    UByte            FocusGroupIndexes[16];    // +0x3464 controller index -> focus group
    UByte            Unrecovered_3474[0x1c];   // +0x3474
    UInt32           Flags;                    // +0x3490

    enum FlagsType
    {
        Flag_NoInvisibleAdvance = 0x800,       // _global.noInvisibleAdvance: hidden clips stop advancing
        Shift_AlwaysEnableKeyboardPress = 26,  // two bits: 0 undefined, 1 true, 2 false, 3 read as -1
        Shift_DisableFocusRolloverEvent = 28   // two bits, the same encoding
    };
    bool IsNoInvisibleAdvanceFlagSet() const { return (Flags & Flag_NoInvisibleAdvance) != 0; }
    // _focusrect rollover events suppressed (disableFocusRolloverEvent extension property).
    bool IsDisableFocusRolloverEvent() const
    {
        int v = (Flags >> Shift_DisableFocusRolloverEvent) & 3;
        if (v == 3)
            v = -1;
        return v == 1;
    }
    // Enter/Space press a focused clip that is not a button (alwaysEnableKeyboardPress extension property).
    bool IsAlwaysEnableKeyboardPress() const
    {
        int v = (Flags >> Shift_AlwaysEnableKeyboardPress) & 3;
        if (v == 3)
            v = -1;
        return v == 1;
    }
    // Defined where InteractiveObject is complete (sfr_gfx_05b).
    inline bool IsFocused(const InteractiveObject* ch, unsigned controllerIdx) const;
    bool IsFocusRectShown(unsigned controllerIdx) const
    {
        return FocusGroups[FocusGroupIndexes[controllerIdx]].FocusRectShown;
    }

    // Removes the setInterval/setTimeout timer with the given id (exe 0x14256e0d0).
    void ClearIntervalTimer(int id);
};

// The root of one loaded movie's sprite tree; leading members only (the font manager, bytes loaded and so on).
class MovieDefRootNode
{
public:
    virtual ~MovieDefRootNode();         // vftable +0x00

    MovieDefRootNode* pPrev;             // +0x08 ListNode
    MovieDefRootNode* pNext;             // +0x10
    unsigned          SpriteRefCount;    // +0x18
    MovieDefImpl*     pDefImpl;          // +0x20
    unsigned          LoadingFrame;      // +0x28
    unsigned          BytesLoaded;       // +0x2c
    bool              ImportFlag;        // +0x30 the root of an import: its loading state is the parent's
    FontManager*      pFontManager;      // +0x38 Ptr<FontManager>
};

}} // namespace Scaleform::GFx

#endif
