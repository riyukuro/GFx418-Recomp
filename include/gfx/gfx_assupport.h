// Recovered Scaleform 4.1.18 GFx: the ActionScript support state (LoadStates pAS2Support / pAS3Support), as the
// tag readers of the loader call it. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Only the loader slots called by recovered units are named; slots 1..12 (movie / memory context / character
// creation, the frame tag allocators and the DoAction readers) are placeholders until their callers are recovered.
#ifndef MS2_SF_GFX_ASSUPPORT_H
#define MS2_SF_GFX_ASSUPPORT_H

#include "gfx_state.h"
#include "gfx_moviedef.h"   // (appended) StateBag::SetAS3Support
#include "gfx_stream.h"
#include "gfx_characterdef.h"
#include "gfx_asimemanager.h"

namespace Scaleform { namespace GFx {

class ButtonDef;
class LoadProcess;
class MemoryContext;
struct MemoryParams;
class MovieImpl;
class DisplayObjectBase;
class InteractiveObject;
struct CharacterCreateInfo;
class PlaceObject2Tag;
class PlaceObject3Tag;
class RemoveObjectTag;
class RemoveObject2Tag;

class ASSupport : public State
{
public:
    virtual MovieImpl* CreateMovie(MemoryContext* memContext) = 0;
    // (named for sfr_as3_01) slot 2
    virtual Ptr<ASIMEManager> CreateASIMEManager() = 0;
    virtual MemoryContext* CreateMemoryContext(const char* heapName, const MemoryParams& memParams, bool debugHeap) = 0;
    // A new instance of the character ccinfo describes, bound to ccinfo's movie (slot 4, named for sfr_gfx_06d).
    virtual DisplayObjectBase* CreateCharacterInstance(MovieImpl* proot, const CharacterCreateInfo& ccinfo,
                                                       InteractiveObject* pparent, ResourceId rid,
                                                       CharacterDef::CharacterDefType type = CharacterDef::Unknown) = 0;
    // (named for sfr_as3_01) slots 5, 6
    virtual void  DoActions() = 0;
    virtual UByte GetAVMVersion() const = 0;
    // (sfr_gfx_04b) the AVM's own place / remove tags, in the tag memory of p; dataSz counts the event handler
    // pointer slot (slots 7..10)
    virtual PlaceObject2Tag*  AllocPlaceObject2Tag(LoadProcess* p, UPInt dataSz, UInt8 swfVer) = 0;
    virtual PlaceObject3Tag*  AllocPlaceObject3Tag(LoadProcess* p, UPInt dataSz)               = 0;
    virtual RemoveObjectTag*  AllocRemoveObjectTag(LoadProcess* p)                             = 0;
    virtual RemoveObject2Tag* AllocRemoveObject2Tag(LoadProcess* p)                            = 0;
private:
public:
    // (sfr_gfx_04b) the DoAction / DoInitAction tags (slots 11, 12)
    virtual void DoActionLoader(LoadProcess* p, const TagInfo& tagInfo)     = 0;
    virtual void DoInitActionLoader(LoadProcess* p, const TagInfo& tagInfo) = 0;

public:
    // The action records of DefineButton / the condition actions of DefineButton2 (slots 13, 14).
    virtual void ReadButtonActions(LoadProcess* p, ButtonDef* pbuttonDef, TagType tagType)           = 0;
    virtual void ReadButton2ActionConditions(LoadProcess* p, ButtonDef* pbuttonDef, TagType tagType) = 0;
};

// (appended for the game's GFxManager)
inline void StateBag::SetAS3Support(ASSupport* ptr) { SetState(State::State_AS3Support, ptr); }

}} // namespace Scaleform::GFx

#endif
