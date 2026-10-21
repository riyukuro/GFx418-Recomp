// Recovered Scaleform 4.1.18 GFx: LoadProcess, the loader task that parses one SWF file into a MovieDataDef, as seen
// by the tag readers of this include tree (gfx_loadprocess.h is the declaration of the other tree, used by the AS3
// units). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Layout (0x420 bytes) from the exe's tag readers; only the members the recovered units use are named.
#ifndef MS2_SF_GFX_LOADPROC_H
#define MS2_SF_GFX_LOADPROC_H

#include "gfx_loaderimpl.h"
#include "gfx_log.h"
#include "gfx_moviedef.h"
#include "gfx_stream.h"
#include "../kernel/sf_array.h"

namespace Scaleform { namespace GFx {

class SoundStreamDef;

// The timeline a sprite definition is loaded into. Only its streaming sound and loading frame (vftable slots 16..18)
// are used so far; the CharacterDef / TimelineDef slots before them are not named yet.
class TimelineIODef : public Resource
{
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

public:
    // The streaming sound of the timeline (SoundStreamHead / SoundStreamBlock tags of a sprite).
    virtual SoundStreamDef* GetSoundStream() const               = 0;
    virtual void            SetSoundStream(SoundStreamDef* pdef) = 0;
    virtual unsigned        GetLoadingFrame() const              = 0;
};

class DisplayObjContainer;
class TimelineSnapshot;

struct ActionPriority
{
    enum Priority
    {
        AP_Highest = 0,
        AP_Initialize = 0,
        AP_Construct,
        AP_Frame,
        AP_Normal = AP_Frame,
        AP_Load,
        AP_Lowest = AP_Load
    };
};

// A tag run when its frame is reached (placed in the loader's tag memory; vftable 0x14313ba68).
class ExecuteTag
{
public:
    virtual ~ExecuteTag() {}

    virtual void Execute(DisplayObjContainer*) {}
    virtual void ExecuteWithPriority(DisplayObjContainer* m, ActionPriority::Priority) { Execute(m); }
    virtual bool IsRemoveTag() const { return false; }
    virtual bool IsActionTag() const { return false; }
    virtual bool IsInitImportActionsTag() const { return false; }
    virtual void AddToTimelineSnapshot(TimelineSnapshot*, unsigned) {}
    virtual void Trace(const char*) {}
};

class LoadProcess : public LoaderTask, public LogBase<LoadProcess>
{
public:
    enum LoadStateType
    {
        LS_LoadingRoot   = 0,
        LS_LoadingSprite = 1 // between DefineSprite and its end tag
    };

    // The stream of the tag being read: the SWF stream, or another one while a nested block is parsed.
    Stream* GetStream() { return pAltStream ? pAltStream : &ProcessStream; }

    unsigned GetLoadingFrame() const { return pLoadData->GetLoadingFrame(); }
    // A streaming sound block belongs to the frame of the timeline being loaded.
    unsigned GetLoadingFrameForStreamSound() const
    {
        if (LoadState == LS_LoadingSprite)
            return pTimelineDef->GetLoadingFrame();
        return GetLoadingFrame();
    }

    Log* GetLog() const { return pLoadStates->pLog ? pLoadStates->pLog->GetLog() : 0; }

    LoadStates*          GetLoadStates() const { return pLoadStates; }
    MemoryHeap*          GetLoadHeap() const   { return pLoadData->GetHeap(); }
    const ExporterInfo*  GetExporterInfo() const { return pLoadData->GetExporterInfo(); }

    // Byte-aligned readers of the current stream (exe 0x14258ec50, 0x1425c8c20).
    UInt16 ReadU16() { return GetStream()->ReadU16(); }
    UInt32 ReadU32() { return GetStream()->ReadU32(); }

    bool GetResourceHandle(ResourceHandle* phandle, ResourceId rid) const
    {
        return pLoadData->GetResourceHandle(phandle, rid);
    }

    // Adds a resource created per binding from resData (exe 0x142637b60).
    ResourceHandle AddDataResource(ResourceId rid, const ResourceData& resData);

    // The streaming sound of the timeline being loaded.
    SoundStreamDef* GetSoundStream() const
    {
        if (LoadState == LS_LoadingSprite)
            return pTimelineDef->GetSoundStream();
        return pLoadData->GetSoundStream();
    }
    void SetSoundStream(SoundStreamDef* pdef)
    {
        if (LoadState == LS_LoadingSprite)
            pTimelineDef->SetSoundStream(pdef);
        else
            pLoadData->SetSoundStream(pdef);
    }

    // A tag constructed in the tag memory of the movie.
    template<class T>
    T* AllocTag()
    {
        return new (pLoadData->AllocTagMemory(sizeof(T))) T;
    }
    void AddExecuteTag(ExecuteTag* ptag) { FrameTags[LoadState].PushBack(ptag); }

    // SWF FileAttributes flags of the file.
    enum FileAttrFlags
    {
        FileAttr_UseNetwork        = 0x01,
        FileAttr_UseActionScript3  = 0x08,
        FileAttr_HasMetadata       = 0x10
    };
    unsigned GetFileAttributes() const { return pLoadData->GetFileAttributes(); }

    // exe 0x1425c8ca0
    UByte ReadU8()            { return GetStream()->ReadU8(); }
    int   Tell()              { return GetStream()->Tell(); }
    void  SetPosition(int pos) { GetStream()->SetPosition(pos); }

private:
    // +0x20 LogBase<LoadProcess>
    unsigned                        ParseFlags;      // +0x28
    void*                           pBindProcess;    // +0x30 Ptr<MovieBindProcess>
    Ptr<MovieDataDef::LoadTaskData> pLoadData;       // +0x38
    MovieDataDef*                   pDataDef_Unsafe; // +0x40
    UByte                           Unknown48[8];    // +0x48
    Stream                          ProcessStream;   // +0x50 first member of the SWF process info
    UByte                           Unknown2C0[0xf8]; // +0x2c0 rest of the process info, JPEG tables, data lists
    LoadStateType                   LoadState;       // +0x3b8
    TimelineIODef*                  pTimelineDef;    // +0x3c0
    // Tags of the frame being loaded, of the root timeline [0] and of the sprite being loaded [1].
    Array<ExecuteTag*, Stat_Default_Mem, ArrayConstPolicy<32, 16, false> > FrameTags[2]; // +0x3c8
    Array<ExecuteTag*, Stat_Default_Mem, ArrayConstPolicy<32, 16, false> > InitActionTags; // +0x3f8
    unsigned                        ASInitActionTagsNum; // +0x410
    Stream*                         pAltStream;      // +0x418
};

}} // namespace Scaleform::GFx

#endif
