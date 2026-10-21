// Recovered Scaleform 4.1.18 GFx: the ActionScript support state (LoadStates pAS2Support / pAS3Support), as the
// tag readers of the loader call it. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Only the loader slots called by recovered units are named; slots 1..12 (movie / memory context / character
// creation, the frame tag allocators and the DoAction readers) are placeholders until their callers are recovered.
#ifndef MS2_SF_GFX_ASSUPPORT_H
#define MS2_SF_GFX_ASSUPPORT_H

#include "gfx_state.h"
#include "gfx_stream.h"

namespace Scaleform { namespace GFx {

class ButtonDef;
class LoadProcess;

class ASSupport : public State
{
    virtual void Slot01() = 0; // CreateMovie
    virtual void Slot02() = 0; // CreateASIMEManager
    virtual void Slot03() = 0; // CreateMemoryContext
    virtual void Slot04() = 0; // CreateCharacterInstance
    virtual void Slot05() = 0; // DoActions
    virtual void Slot06() = 0; // GetAVMVersion
    virtual void Slot07() = 0; // AllocPlaceObject2Tag
    virtual void Slot08() = 0; // AllocPlaceObject3Tag
    virtual void Slot09() = 0; // AllocRemoveObjectTag
    virtual void Slot10() = 0; // AllocRemoveObject2Tag
    virtual void Slot11() = 0; // DoActionLoader
    virtual void Slot12() = 0; // DoInitActionLoader

public:
    // The action records of DefineButton / the condition actions of DefineButton2 (slots 13, 14).
    virtual void ReadButtonActions(LoadProcess* p, ButtonDef* pbuttonDef, TagType tagType)           = 0;
    virtual void ReadButton2ActionConditions(LoadProcess* p, ButtonDef* pbuttonDef, TagType tagType) = 0;
};

}} // namespace Scaleform::GFx

#endif
