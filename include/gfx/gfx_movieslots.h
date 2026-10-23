// Recovered Scaleform 4.1.18 GFx: the Movie vftable slots the AS3 natives call on the movie (MovieImpl implements
// Movie at offset 0; our MovieImpl is not polymorphic). Slot offsets from the exe's call sites (sfr17).
#ifndef MS2_SF_GFX_MOVIESLOTS_H
#define MS2_SF_GFX_MOVIESLOTS_H

#include "gfx_movieimpl.h"

namespace Scaleform { namespace GFx {

class __declspec(novtable) MovieSlots418
{
public:
    // The stage's view scale mode and alignment (the AS3 Stage.scaleMode / Stage.align values).
    enum ScaleModeType
    {
        SM_NoScale,
        SM_ShowAll,
        SM_ExactFit,
        SM_NoBorder
    };
    enum AlignType
    {
        Align_Center,
        Align_TopCenter,
        Align_BottomCenter,
        Align_CenterLeft,
        Align_CenterRight,
        Align_TopLeft,
        Align_TopRight,
        Align_BottomLeft,
        Align_BottomRight
    };

    virtual void Slot00() = 0;
    virtual MovieDef* GetMovieDef() const = 0;                                                  // 1 (+0x08)
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual UInt64 GetASTimerMs() const = 0;          // 10 (+0x50)
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void SetViewScaleMode(ScaleModeType) = 0;                                           // 13 (+0x68)
    virtual ScaleModeType GetViewScaleMode() const = 0;                                         // 14 (+0x70)
    virtual void SetViewAlignment(AlignType) = 0;                                               // 15 (+0x78)
    virtual AlignType GetViewAlignment() const = 0;                                             // 16 (+0x80)
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void Slot21() = 0;
    virtual void Slot22() = 0;
    virtual void Slot23() = 0;
    virtual void Slot24() = 0;
    virtual void Slot25() = 0;
    virtual void Slot26() = 0;
    virtual void Slot27() = 0;
    virtual void Slot28() = 0;
    virtual void Slot29() = 0;
    virtual void Slot30() = 0;
    virtual void Slot31() = 0;
    virtual void Slot32() = 0;
    virtual void Slot33() = 0;
    virtual void Slot34() = 0;
    virtual void Slot35() = 0;
    virtual void Slot36() = 0;
    virtual void Slot37() = 0;
    virtual void Slot38() = 0;
    virtual void Slot39() = 0;
    virtual void Slot40() = 0;
    virtual void Slot41() = 0;
    virtual void Slot42() = 0;
    virtual unsigned GetMouseCursorCount() const = 0;                                           // 43 (+0x158)
    virtual void Slot44() = 0;
    virtual unsigned GetControllerCount() const = 0;                                            // 45 (+0x168)
    virtual void Slot46() = 0;
    virtual MemoryHeap* GetHeap() const = 0;                                                    // 47 (+0x178)
    virtual void ForceCollectGarbage() = 0;                                                     // 48 (+0x180)
    virtual void PrintObjectsReport(UInt32 flags, Log* log, const char* swfName) = 0;           // 49 (+0x188)
    virtual void Slot50() = 0;
    virtual void Slot51() = 0;
    virtual void Slot52() = 0;
    virtual bool SetControllerFocusGroup(unsigned controllerIdx, unsigned focusGroupIndex) = 0; // 53 (+0x1a8)
    virtual unsigned GetControllerFocusGroup(unsigned controllerIdx) const = 0;                 // 54 (+0x1b0)
    virtual void Slot55() = 0;
    virtual void Slot56() = 0;
    virtual void Slot57() = 0;
    virtual void Slot58() = 0;
    virtual void Slot59() = 0;
    virtual void Slot60() = 0;
    virtual void Slot61() = 0;
    virtual void Slot62() = 0;
    virtual void Slot63() = 0;
    virtual void Slot64() = 0;
    virtual void SetVerboseAction(bool verboseAction) = 0;                                      // 65 (+0x208)
};

inline MovieSlots418* AsMovieSlots(MovieImpl* pmovie)
{
    return reinterpret_cast<MovieSlots418*>(pmovie);
}

}} // namespace Scaleform::GFx

#endif
