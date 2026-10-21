// Recovered Scaleform 4.1.18 GFx: the ActionScript support state (LoadStates pAS2Support / pAS3Support), as the
// tag readers of the loader call it. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Only the loader slots called by recovered units are named; slots 1..12 (movie / memory context / character
// creation, the frame tag allocators and the DoAction readers) are placeholders until their callers are recovered.
#ifndef MS2_SF_GFX_ASSUPPORT_H
#define MS2_SF_GFX_ASSUPPORT_H

#include "gfx_state.h"
#include "gfx_stream.h"
#include "gfx_characterdef.h"

namespace Scaleform { namespace GFx {

class ButtonDef;
class LoadProcess;
class MemoryContext;
struct MemoryParams;
class MovieImpl;
class DisplayObjectBase;
class InteractiveObject;
struct CharacterCreateInfo;

class ASSupport : public State
{
public:
    virtual MovieImpl* CreateMovie(MemoryContext* memContext) = 0;
private:
    virtual void Slot02() = 0; // CreateASIMEManager
public:
    virtual MemoryContext* CreateMemoryContext(const char* heapName, const MemoryParams& memParams, bool debugHeap) = 0;
    // A new instance of the character ccinfo describes, bound to ccinfo's movie (slot 4, named for sfr_gfx_06d).
    virtual DisplayObjectBase* CreateCharacterInstance(MovieImpl* proot, const CharacterCreateInfo& ccinfo,
                                                       InteractiveObject* pparent, ResourceId rid,
                                                       CharacterDef::CharacterDefType type = CharacterDef::Unknown) = 0;
private:
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
