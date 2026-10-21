// Recovered Scaleform GFx 4.1.18: LoadProcess, the loader task that parses one SWF file into a MovieDataDef.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
// The layout (0x420 bytes) was checked against the exe's tag loaders (GFx_AS3Support: DoAbcLoader, SymbolClassLoader).
// Only the members and inline helpers the recovered units use are spelled out; the rest stay declared but unnamed.
#ifndef MS2_SF_GFX_LOADPROCESS_H
#define MS2_SF_GFX_LOADPROCESS_H

#include "GFx/GFx_LoaderImpl.h"
#include "GFx/GFx_MovieDef.h"
#include "GFx/GFx_Stream.h"

namespace Scaleform { namespace GFx {

class MovieBindProcess;
class TempBindData;

class LoadProcess : public LoaderTask, public LogBase<LoadProcess>
{
public:
    typedef MovieDataDef::LoadTaskData LoadTaskData;

    enum LoadStateType
    {
        LS_LoadingFrames,
        LS_LoadFinished,
        LS_LoadCanceled,
        LS_LoadError
    };

    // +0x20 LogBase<LoadProcess> (one byte, padded)
    unsigned                    ParseFlags;         // +0x28
    Ptr<MovieBindProcess>       pBindProcess;       // +0x30
    Ptr<LoadTaskData>           pLoadData;          // +0x38
    MovieDataDef*               pDataDef_Unsafe;    // +0x40
    SWFProcessInfo              ProcessInfo;        // +0x50 (Stream first)
    void*                       pJpegTables;        // +0x360 Ptr<Render::JPEG::TablesHeader>
    unsigned                    LoadFlags;          // +0x368
    unsigned                    ImportIndex;        // +0x36c
    TempBindData*               pTempBindData;      // +0x370
    unsigned                    ImportDataCount;    // +0x378
    unsigned                    ResourceDataCount;  // +0x37c
    unsigned                    FontDataCount;      // +0x380
    ImportData*                 pImportDataLast;    // +0x388
    ImportData*                 pImportData;        // +0x390
    ResourceDataNode*           pResourceData;      // +0x398
    ResourceDataNode*           pResourceDataLast;  // +0x3a0
    FontDataUseNode*            pFontData;          // +0x3a8
    FontDataUseNode*            pFontDataLast;      // +0x3b0
    LoadStateType               LoadState;          // +0x3b8
    TimelineIODef*              pTimelineDef;       // +0x3c0
    Array<ExecuteTag*, Stat_Default_Mem, ArrayConstPolicy<32, 16, false> > FrameTags[2];  // +0x3c8
    Array<ExecuteTag*, Stat_Default_Mem, ArrayConstPolicy<32, 16, false> > InitActionTags; // +0x3f8
    unsigned                    ASInitActionTagsNum;// +0x410
    Stream*                     pAltStream;         // +0x418

    LoadProcess(MovieDataDef* pdataDef, LoadStates* pstates, unsigned loadFlags);
    virtual ~LoadProcess();

    LoadTaskData*   GetLoadTaskData() const     { return pLoadData; }
    MovieDataDef*   GetDataDef() const          { return pDataDef_Unsafe; }
    const char*     GetFileURL() const          { return pDataDef_Unsafe->pData->GetFileURL(); }
    MemoryHeap*     GetLoadHeap() const         { return pLoadData->GetHeap(); }

    Stream*         GetStream()                 { return pAltStream ? pAltStream : &ProcessInfo.Stream; }

    Log*            GetLog() const              { return pLoadStates->pLog ? pLoadStates->pLog->GetLog() : 0; }
    bool            IsVerboseParse() const      { return (ParseFlags & ParseControl::VerboseParse) != 0; }

    void*           AllocTagMemory(UPInt bytes) { return pLoadData->AllocTagMemory(bytes); }

    void            ExportResource(const String& symbol, ResourceId rid, const ResourceHandle& hres)
    {
        pLoadData->ExportResource(symbol, rid, hres);
    }
    bool            GetResourceHandle(ResourceHandle* phandle, ResourceId rid) const
    {
        return pLoadData->GetResourceHandle(phandle, rid);
    }

    // Init actions of the current frame (DoInitAction / DoAbc tags).
    void            AddInitAction(ExecuteTag* ptag)
    {
        InitActionTags.PushBack(ptag);
        ++ASInitActionTagsNum;
    }
};

}} // namespace Scaleform::GFx

#endif
