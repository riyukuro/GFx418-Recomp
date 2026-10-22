// Recovered Scaleform 4.1.18 GFx: the Movie vftable slots the AS3 natives call on the movie (MovieImpl implements
// Movie at offset 0; our MovieImpl is not polymorphic). Slot offsets from the exe's call sites (sfr17).
#ifndef MS2_SF_GFX_MOVIESLOTS_H
#define MS2_SF_GFX_MOVIESLOTS_H

#include "gfx_movieimpl.h"

namespace Scaleform { namespace GFx {

class __declspec(novtable) MovieSlots418
{
public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
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
    virtual void Slot43() = 0;
    virtual void Slot44() = 0;
    virtual unsigned GetControllerCount() const = 0;                                            // 45 (+0x168)
    virtual void Slot46() = 0;
    virtual MemoryHeap* GetHeap() const = 0;                                                    // 47 (+0x178)
    virtual void Slot48() = 0;
    virtual void Slot49() = 0;
    virtual void Slot50() = 0;
    virtual void Slot51() = 0;
    virtual void Slot52() = 0;
    virtual bool SetControllerFocusGroup(unsigned controllerIdx, unsigned focusGroupIndex) = 0; // 53 (+0x1a8)
    virtual unsigned GetControllerFocusGroup(unsigned controllerIdx) const = 0;                 // 54 (+0x1b0)
};

inline MovieSlots418* AsMovieSlots(MovieImpl* pmovie)
{
    return reinterpret_cast<MovieSlots418*>(pmovie);
}

}} // namespace Scaleform::GFx

#endif
