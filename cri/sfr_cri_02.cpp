// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the rest of the Scaleform GFx 4.1.18 Video player glue
// (VideoPlayerImpl, the decoders and readers over CRI, from 0x14002a0e0), then the CRI Movie 3.07.01 internals.
// Our own source, written from the exe; the leaked SDK copies were only used to name things.
// The CRI part was built by CRI with VS2008 SP1 and the Video add-on lib with VS2012; both can only be functional
// with our toolset.
// MS2-UNIT: sfr_cri_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14002a0e0-0x140039ea8 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/video/video_video.h"
#include "../include/cri/cri_movie.h"
#include "../include/video/video_videoplayerimpl.h"
#include "../include/kernel/sf_file.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include <new>

// ---- exe helpers this part calls (bound by address until their units are recovered)

void     FUN_14258b240(unsigned ms);                                    // Thread::MSleep
unsigned __int64 FUN_1425e3590(void);                                   // Timer::GetTicks
void     FUN_14257dc30(void* p);                                        // RefCountImpl::AddRef
void     FUN_14257dcb0(void* p);                                        // RefCountImpl::Release
void*    FUN_14258a490(void* mem, void* createParams);                  // Thread::Thread(const CreateParams&)
void*    FUN_140027f7c(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align, CriSint32 type);
void     FUN_14001d650(void* config, void* reader);                     // VideoReaderConfig::AttachReader
void*    FUN_140041d40(void* pheap);                                    // CriHeap over a MemoryHeap: create
void     FUN_140041dd0(void* criheap);                                  //   and destroy
void*    FUN_140041c00(void* mem);                                      // SystemTimerSyncObject::SystemTimerSyncObject
void*    FUN_14002a000(void* mem, void* pheap, void* psound);           // CriMvSound::CriMvSound(MemoryHeap*, VideoSound*)
void*    FUN_14002d970(void* mem, void* pconfig);                       // VideoReader::VideoReader(VideoReaderConfig*)
void*    FUN_140029e40(void* mem, void* psync);                     // CriMvSystemTimer::CriMvSystemTimer(SyncObject*)
void     FUN_142586530(void* pstr, const char* p, Scaleform::UPInt size); // String::AssignString
void*    FUN_14002abd0(void* mem, int format, const void* psize, void* ptexman, void* pplayer); // VideoImage ctor
void     FUN_140037950(void* player, const char* message, int severity);
void     FUN_140044fdc(void* inputBuffer);
CriSint32 FUN_140045ed0(const void* config);
CriSint32 FUN_140044eb0(CriSint32 workCount);
CriSint32 FUN_140045910(const void* config);
CriSint32 FUN_140042150(void* player, void* source, void* work, CriUint32 size, CriSint32 flags);
void     FUN_140037850(void* player);
void     FUN_140037880(void* player);
CriUint32 FUN_140030280(void* player, void* heap, void* work);
CriHeap  FUN_140027fec(void* memory, CriSint32 size);

// ==== CRI heap backed object allocation ============================================================================

// The CRI allocator keeps its heap pointer in the eight bytes immediately after each object.
// MS2-FUNCTIONAL: CRI's VS2008 build uses a different compiler toolset from our build.
// @0x14002e548
void* CriAllocator::operator new(size_t size, CriHeap heap, CriHeapType type, const CriChar8* name, CriUint32 align)
{
    CriUint32 allocationSize = (CriUint32)size + sizeof(CriHeap);
    void* memory = FUN_140027f7c(heap, (CriSint32)allocationSize, name, (CriSint32)align, (CriSint32)type);
    if (memory)
    {
        memset(memory, 0, allocationSize);
        *(CriHeap*)((CriUint8*)memory + size) = heap;
    }
    return memory;
}

// MS2-FUNCTIONAL: CRI's VS2008 compiler does not emit the sized-delete lowering used by our toolset.
// @0x14002e5b0
void CriAllocator::operator delete(void* memory, size_t size)
{
    criHeap_Free(*(CriHeap*)((CriUint8*)memory + size), memory);
}

// MS2-FUNCTIONAL: the CRI VS2008 build has different code generation for this wrapper.
// @0x14002e608
void CriAllocator::operator delete(void* memory, CriHeap heap)
{
    criHeap_Free(heap, memory);
}

// MS2-FUNCTIONAL: the CRI VS2008 build has different code generation for this wrapper.
// @0x14002e628
int FUN_14002e628(CriSint32 alignment)
{
    return criHeap_DebugGetWorstExtraSize(alignment) + (int)sizeof(CriHeap);
}

// MS2-FUNCTIONAL: the CRI VS2008 build has different code generation for these allocator wrappers.
// @0x14002e63c
void* CriAllocator::operator new(size_t size, CriHeap heap)
{
    return CriAllocator::operator new(size, heap, CRIHEAP_TYPE_FIX, "CriAu_new", 0x10);
}

// MS2-FUNCTIONAL: the CRI VS2008 build uses a different compiler toolset from our build.
// @0x14002e660
void* CriAllocator::operator new(size_t size, CriHeap heap, CriHeapType type)
{
    return CriAllocator::operator new(size, heap, type, "CriAu_new", 0x10);
}

// MS2-FUNCTIONAL: the CRI VS2008 build uses a different compiler toolset from our build.
// @0x14002e680
void* CriAllocator::operator new(size_t size, CriHeap heap, const CriChar8* name, CriUint32 align)
{
    return CriAllocator::operator new(size, heap, CRIHEAP_TYPE_FIX, name, align);
}

// MS2-FUNCTIONAL: this internal CRI helper was built with VS2008.
// @0x14002e6b0
void CRIAPI criFixedAllocator_Create(void* begin, CriUint32 size, CriFixedAllocator* allocator)
{
    allocator->Begin = (CriUint8*)begin;
    allocator->Current = (CriUint8*)begin;
    allocator->Size = size;
}

// MS2-FUNCTIONAL: CRI emits the empty helper as a short c2 return in its VS2008 build.
// @0x14002e6bc
void FUN_14002e6bc(CriFixedAllocator*)
{
}

// MS2-FUNCTIONAL: the CRI VS2008 build uses a different register allocation for this allocator.
// @0x14002e6c0
void* CRIAPI criFixedAllocator_Allocate(CriFixedAllocator* allocator, CriUint32 size, CriUint32 align)
{
    size_t current = (size_t)allocator->Current;
    size_t aligned = (current + align - 1) / align * align;
    allocator->Current = (CriUint8*)(aligned + size);
    return (void*)aligned;
}

namespace Scaleform { namespace GFx { namespace Video {

#define SF_VIDEO_ERR CriMv::ErrorContainer

// The VideoPlayer methods below are the Video add-on lib (prebuilt with VS2012), so none of them can be exact.

// ==== VideoDecoderThrd ===============================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002a160
void VideoDecoderThrd::StopDecoding(VideoPlayer* pplayer)
{
    DecodeLock.DoLock();
    int idx = -1;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        if (Players[i] == pplayer)
        {
            idx = (int)i;
            break;
        }
    }
    if (idx != -1)
        static_cast<VideoPlayerImpl*>(pplayer)->pPlayer->Stop();
    DecodeLock.Unlock();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002a1e0
bool VideoDecoderThrd::IsDecodingStopped(VideoPlayer* pplayer)
{
    DecodeLock.DoLock();
    int idx = -1;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        if (Players[i] == pplayer)
        {
            idx = (int)i;
            break;
        }
    }
    DecodeLock.Unlock();
    return idx == -1;
}

// ==== VideoPlayerImpl: texture ======================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); the VideoImage constructor is inlined there
// @0x14002ad80
VideoImage* VideoPlayerImpl::CreateTexture(Render::TextureManager* ptexman)
{
    if ((Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking) && ptexman)
    {
        unsigned size[2] = { Width, Height };
        PauseLocked = true;
        void* mem = pHeap->Alloc(0x48);
        if (mem)
            return (VideoImage*)FUN_14002abd0(mem, 0xc9 /* Image_Y8_U2_V2 */, size, ptexman, this);
    }
    return NULL;
}

// ==== VideoDecoderSmp ================================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002b3d0
void VideoDecoderSmp::StartDecoding(VideoPlayer* pplayer)
{
    Players.PushBack(static_cast<VideoPlayerImpl*>(pplayer));
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002b450
void VideoDecoderSmp::GetReadBufferInfo(void* pinfo)
{
    Array<VideoPlayer::ReadBufferInfo>& info = *(Array<VideoPlayer::ReadBufferInfo>*)pinfo;
    info.Clear();
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        VideoPlayer::ReadBufferInfo rbinfo;
        Players[i]->GetReadBufferInfo(&rbinfo);
        info.PushBack(rbinfo);
    }
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002beb0
bool VideoDecoderSmp::ExecuteDecode(VideoPlayer* pplayer)
{
    int idx = -1;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        if (Players[i] == pplayer)
        {
            idx = (int)i;
            break;
        }
    }
    if (idx == -1)
        return false;
    if (static_cast<VideoPlayerImpl*>(pplayer)->pPlayer->ExecuteDecode(SF_VIDEO_ERR))
        return true;
    Players.RemoveAt(idx);
    return false;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002bf70
void VideoDecoderSmp::PauseDecoding(bool pause)
{
    if (Paused && pause)
        return;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        VideoPlayerImpl* pplayer = Players[i];
        if (pause)
        {
            // Players the application paused itself stay paused when decoding resumes.
            if (pplayer->PauseFlag)
            {
                PausedPlayers.PushBack(pplayer);
                continue;
            }
        }
        else
        {
            int idx = -1;
            for (UPInt j = 0; j < PausedPlayers.GetSize(); j++)
            {
                if (PausedPlayers[j] == pplayer)
                {
                    idx = (int)j;
                    break;
                }
            }
            if (idx != -1)
            {
                PausedPlayers.RemoveAt(idx);
                continue;
            }
        }
        pplayer->Pause(pause);
    }
    Paused = pause;
}

// ==== VideoDecoderThrd ===============================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002b270
VideoDecoderThrd::VideoDecoderThrd(MemoryHeap* pheap, Thread::ThreadPriority priority)
    : pHeap(pheap), pDecodeThread(NULL), ThreadPriority(priority), DecodeLock(0)
{
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002b2e0
VideoDecoderThrd::~VideoDecoderThrd()
{
    if (pDecodeThread)
        FUN_14257dcb0(pDecodeThread);
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002bb00
int VideoDecoderThrd::DecodeFunc(Thread*, void* obj)
{
    VideoDecoderThrd* pdecoder = (VideoDecoderThrd*)obj;
    for (;;)
    {
        pdecoder->DecodeLock.DoLock();
        if (pdecoder->Players.GetSize() == 1)
        {
            VideoPlayerImpl* pplayer = pdecoder->Players[0];
            pdecoder->DecodeLock.Unlock();
            if (!pplayer->pPlayer->ExecuteDecode(SF_VIDEO_ERR))
            {
                pdecoder->DecodeLock.DoLock();
                pdecoder->Players.RemoveAt(0);
                if (pdecoder->Players.GetSize() == 0)
                {
                    if (pdecoder->pDecodeThread)
                        FUN_14257dcb0(pdecoder->pDecodeThread);
                    pdecoder->pDecodeThread = NULL;
                    pdecoder->DecodeLock.Unlock();
                    return 0;
                }
                pdecoder->DecodeLock.Unlock();
            }
        }
        else
        {
            Array<VideoPlayerImpl*> players(pdecoder->Players);
            pdecoder->DecodeLock.Unlock();

            Array<UPInt> finished;
            for (UPInt i = 0; i < players.GetSize(); i++)
            {
                if (!players[i]->pPlayer->ExecuteDecode(SF_VIDEO_ERR))
                    finished.PushBack(i);
            }
            if (finished.GetSize())
            {
                pdecoder->DecodeLock.DoLock();
                for (UPInt j = 0; j < finished.GetSize(); j++)
                    pdecoder->Players.RemoveAt(finished[j] - j);
                if (pdecoder->Players.GetSize() == 0)
                {
                    if (pdecoder->pDecodeThread)
                        FUN_14257dcb0(pdecoder->pDecodeThread);
                    pdecoder->pDecodeThread = NULL;
                    pdecoder->DecodeLock.Unlock();
                    return 0;
                }
                pdecoder->DecodeLock.Unlock();
            }
        }
        FUN_14258b240(1);
    }
}

// The thread creation parameters (Thread::CreateParams).
struct VideoThreadCreateParams
{
    int       (*ThreadFunction)(Thread*, void*);
    void*     UserHandle;
    UPInt     StackSize;
    int       Processor;
    int       InitialState;
    int       Priority;
};

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c0e0
void VideoDecoderThrd::StartDecoding(VideoPlayer* pplayer)
{
    DecodeLock.DoLock();
    int idx = -1;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        if (Players[i] == pplayer)
        {
            idx = (int)i;
            break;
        }
    }
    if (idx != -1)
    {
        DecodeLock.Unlock();
        return;
    }
    Players.PushBack(static_cast<VideoPlayerImpl*>(pplayer));
    DecodeLock.Unlock();

    if (!pDecodeThread)
    {
        VideoThreadCreateParams params = { DecodeFunc, this, 0x10000, -1, 0, ThreadPriority };
        void* mem = pHeap->Alloc(0x60);
        RefCountImpl* pthread = mem ? (RefCountImpl*)FUN_14258a490(mem, &params) : NULL;
        if (pDecodeThread)
            FUN_14257dcb0(pDecodeThread);
        pDecodeThread = pthread;
        // Thread::Start(Running), Thread::SetThreadName
        typedef bool (*StartFunc)(RefCountImpl*, int);
        typedef void (*SetNameFunc)(RefCountImpl*, const char*);
        if ((*reinterpret_cast<StartFunc**>(pthread))[5](pthread, 1) && pDecodeThread)
            (*reinterpret_cast<SetNameFunc**>(pDecodeThread))[7](pDecodeThread, "Scaleform Video Decoder");
    }
}

// ==== VideoPlayerImpl ================================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); the owned objects' constructors are inlined there
// @0x14002b530
bool VideoPlayerImpl::Init(Video* pvideo, TaskManager*, FileOpenerBase* pfileOpener, Log* plog)
{
    if (plog)
        FUN_14257dc30(plog);
    if (pLog)
        FUN_14257dcb0(pLog);
    pLog = plog;

    if (pvideo)
    {
        VideoSoundSystem* psoundSystem = pvideo->pSoundSystem;
        if (psoundSystem)
        {
            Ptr<VideoSound> pinterface    = *psoundSystem->Create();
            Ptr<VideoSound> psubinterface = *psoundSystem->Create();

            void* mem = pHeap->Alloc(0x50);
            VideoPlayerSound* psound = mem ? (VideoPlayerSound*)FUN_14002a000(mem, pHeap, pinterface) : NULL;
            if (pSound)
                pSound->Release();
            pSound = psound;

            mem = pHeap->Alloc(0x50);
            psound = mem ? (VideoPlayerSound*)FUN_14002a000(mem, pHeap, psubinterface) : NULL;
            if (pSubSound)
                pSubSound->Release();
            pSubSound = psound;
        }
    }

    VideoDecoder* pdecoder = pvideo ? pvideo->pDecoder.GetPtr() : NULL;
    if (pdecoder)
        pdecoder->AddRef();
    if (pDecoder)
        pDecoder->Release();
    pDecoder = pdecoder;
    if (!pDecoder)
    {
        pDecoder = SF_HEAP_NEW(pHeap) VideoDecoderSmp;
    }

    if (pvideo)
    {
        VideoReader* preader = pvideo->pReaderConfig->CreateReader();
        if (pReader)
            pReader->Release();
        pReader = preader;
    }
    else
    {
        void* mem = pHeap->Alloc(0x40);
        VideoReaderConfig* pconfig = mem ? ::new(mem) VideoReaderConfigSmp(pHeap, pfileOpener) : NULL;
        mem = pHeap->Alloc(0x50);
        VideoReader* preader = mem ? (VideoReader*)FUN_14002d970(mem, pconfig) : NULL;
        if (pReader)
            pReader->Release();
        pReader = preader;
        if (pconfig)
            pconfig->Release();
    }

    void* mem = pHeap->Alloc(0x48);
    VideoPlayer::SyncObject* psyncObj = mem ? (VideoPlayer::SyncObject*)FUN_140041c00(mem) : NULL;
    mem = pHeap->Alloc(0x20);
    CriMvSystemTimer* ptimer = mem ? (CriMvSystemTimer*)FUN_140029e40(mem, psyncObj) : NULL;
    if (pTimer)
        pTimer->Release();
    pTimer = ptimer;

    pPlayer = CriMvEasyPlayer::Create((CriHeap)pCriHeap,
                                      pReader ? (CriMvFileReaderInterface*)((UByte*)pReader + 0x10) : NULL,
                                      pTimer ? static_cast<CriMvSystemTimerInterface*>(pTimer) : NULL,
                                      pSound ? (CriMvSoundInterface*)((UByte*)pSound + 0x10) : NULL,
                                      SF_VIDEO_ERR);
    if (pSound && UseAudioTimer)
        pPlayer->SetMasterTimer(CriMvEasyPlayer::MVEASY_TIMER_AUDIO, SF_VIDEO_ERR);
    else
        pPlayer->SetMasterTimer(CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
    Stat = Stopped;
    if (psyncObj)
        psyncObj->Release();
    return true;
}

// The cue point a CRI event point describes: "name=value,name=value" parameters.
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); a constructor of CuePoint there
// @0x14002c2b0
static VideoPlayer::CuePoint* ConstructCuePoint(VideoPlayer::CuePoint* pcue, const CriMvEventPoint* pevent)
{
    ::new(&pcue->Name) String();
    ::new(&pcue->Params) Array<VideoPlayer::CuePointParam>();
    pcue->Name = pevent->cue_name;
    pcue->Type = pevent->type == 0 ? VideoPlayer::NavigationCuePoint : VideoPlayer::EventCuePoint;
    pcue->Time = (UInt32)pevent->time;
    const char* p = pevent->param_string;
    if (p)
    {
        VideoPlayer::CuePointParam param;
        while (p)
        {
            const char* peq = strchr(p, '=');
            if (!peq)
            {
                param.Name = p;
                pcue->Params.PushBack(param);
                break;
            }
            FUN_142586530(&param.Name, p, peq - p);
            p = peq + 1;
            const char* pcomma = strchr(p, ',');
            if (!pcomma)
            {
                param.Value = p;
                pcue->Params.PushBack(param);
                break;
            }
            FUN_142586530(&param.Value, p, pcomma - p);
            pcue->Params.PushBack(param);
            p = pcomma + 1;
        }
    }
    return pcue;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c5f0
VideoPlayerImpl::~VideoPlayerImpl()
{
    StopAndWait();
    if (pSubSound)
        pPlayer->DetachSubAudioInterface(SF_VIDEO_ERR);
    if (pPlayer)
        pPlayer->Destroy(SF_VIDEO_ERR);
    pPlayer = NULL;
    if (pTimer)
        pTimer->Release();
    pTimer = NULL;
    if (pSound)
        pSound->Release();
    pSound = NULL;
    if (pSubSound)
        pSubSound->Release();
    pSubSound = NULL;
    if (pReader)
        pReader->Release();
    pReader = NULL;
    FUN_140041dd0(pCriHeap);
    if (pLog)
        FUN_14257dcb0(pLog);
    if (pDecoder)
        pDecoder->Release();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c730
VideoPlayer::Status VideoPlayerImpl::GetStatus()
{
    return Stat;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c740
bool VideoPlayerImpl::IsTextureReady()
{
    return UpdateTextureCalled && FrameOnTime;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c7a0
void VideoPlayerImpl::CuePointCallback(CriMvEasyPlayer*, CriMvEventPoint* eventinfo, void* usrobj)
{
    if (!usrobj)
        return;
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)usrobj;
    VideoPlayer::CuePoint cue;
    pplayer->CurrentCuePoints.PushBack(*ConstructCuePoint(&cue, eventinfo));
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c810
VideoPlayerImpl::VideoPlayerImpl(MemoryHeap* pheap)
    : pPlayer(NULL), Stat(NotInitialized), pTimer(NULL), pReader(NULL), pSound(NULL), pSubSound(NULL),
      Width(~0u), Height(~0u), HasAlpha(false), CurrentFrame(0), StartFrame(0), StatusAfterStop(Finished),
      PauseFlag(0), LoopFlag(0), UpdateTextureCalled(false), FrameOnTime(false), PauseLocked(false),
      PausePending(false), SubtitleChannel(-1), DecodeHeaderTimeout(0), UseAudioTimer(true), pDecoder(NULL),
      pHeap(pheap), pLog(NULL)
{
    pCriHeap = FUN_140041d40(pheap);
}

// Puts the player back to the state of a newly opened file (Open and the SetSyncObject restart).
static inline void ResetForOpen(VideoPlayerImpl* p)
{
    p->StopAndWait();
    p->pPlayer->SetCuePointCallback(NULL, NULL, SF_VIDEO_ERR);
    p->CurrentCuePoints.Clear();
    p->StartFrame      = 0;
    p->CurrentFrame    = 0;
    p->Stat            = VideoPlayer::Opening;
    p->StatusAfterStop = VideoPlayer::Finished;
    p->PauseFlag       = 0;
    p->UpdateTextureCalled = false;
    p->SubtitleChannel = -1;
    memset(&p->StmPrm, 0, sizeof(p->StmPrm));
    memset(&p->FrameInfo, 0, sizeof(p->FrameInfo));
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c930
void VideoPlayerImpl::Open(const char* url)
{
    ResetForOpen(this);
    pPlayer->SetFile((CriChar8*)url, SF_VIDEO_ERR);
    pPlayer->DecodeHeader(SF_VIDEO_ERR);
    pDecoder->StartDecoding(this);
    if (pSubSound)
        pPlayer->AttachSubAudioInterface((CriMvSoundInterface*)((UByte*)pSubSound + 0x10), SF_VIDEO_ERR);
    OpenTicks = FUN_1425e3590();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002ca30
void VideoPlayerImpl::GetVideoInfo(VideoInfo* info)
{
    if (!(Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking))
        return;

    info->Width         = StmPrm.video_prm[0].disp_width;
    info->Height        = StmPrm.video_prm[0].disp_height;
    info->FrameRate     = StmPrm.video_prm[0].framerate;
    info->AudioDataRate = StmPrm.num_audio > 0 ? StmPrm.audio_prm[0].sampling_rate : 0;
    info->TotalFrames   = StmPrm.video_prm[0].total_frames;
    info->SubtitleChannelsNumber = StmPrm.num_subtitle;
    info->MaxSubtitleLen         = StmPrm.max_subtitle_size;

    if (info->AudioTracks.GetSize() == 0)
    {
        for (int i = 0; i < CRIMV_MAX_AUDIO_NUM; i++)
        {
            const CriMvAudioParameters& aprm = StmPrm.audio_prm[i];
            if (aprm.num_channel)
            {
                AudioTrackInfo track;
                track.Index          = i;
                track.SampleRate     = aprm.sampling_rate;
                track.ChannelsNumber = aprm.num_channel;
                track.TotalSamples   = aprm.total_samples;
                info->AudioTracks.PushBack(track);
            }
        }
    }

    if (info->CuePoints.GetSize() == 0)
    {
        CriMvCuePointInfo* pcueinfo = pPlayer->GetCuePointInfo(SF_VIDEO_ERR);
        if (pcueinfo)
        {
            for (unsigned i = 0; i < pcueinfo->num_eventpoint; i++)
            {
                CuePoint cue;
                info->CuePoints.PushBack(*ConstructCuePoint(&cue, &pcueinfo->eventtable[i]));
            }
            pPlayer->SetCuePointCallback(CuePointCallback, this, SF_VIDEO_ERR);
        }
    }
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002cd40
void VideoPlayerImpl::SetSyncObject(SyncObject* psyncObj)
{
    if (Stat == Opening || Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking || Stat == Stopping)
    {
        // Switching clocks while a movie is open restarts it from its header.
        ResetForOpen(this);
        if (!psyncObj)
        {
            void* mem = pHeap->Alloc(0x48);
            Ptr<SyncObject> ps = *(mem ? (SyncObject*)FUN_140041c00(mem) : NULL);
            pTimer->pSyncObj = ps;
            pPlayer->SetMasterTimer(pSound && UseAudioTimer ? CriMvEasyPlayer::MVEASY_TIMER_AUDIO
                                                             : CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
        }
        else
        {
            pTimer->pSyncObj = psyncObj;
            pPlayer->SetMasterTimer(CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
        }
        pPlayer->DecodeHeader(SF_VIDEO_ERR);
        pDecoder->StartDecoding(this);
        OpenTicks = FUN_1425e3590();
        return;
    }

    if (!psyncObj)
    {
        if (pTimer->pSyncObj)
            return;
        void* mem = pHeap->Alloc(0x48);
        Ptr<SyncObject> ps = *(mem ? (SyncObject*)FUN_140041c00(mem) : NULL);
        pTimer->SetSyncObject(ps);
        pPlayer->SetMasterTimer(pSound && UseAudioTimer ? CriMvEasyPlayer::MVEASY_TIMER_AUDIO
                                                         : CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
    }
    else if (pTimer->pSyncObj != psyncObj)
    {
        pTimer->SetSyncObject(psyncObj);
        pPlayer->SetMasterTimer(CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
    }
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002cfe0
void VideoPlayerImpl::GetCurrentCuePoints(Array<CuePoint>* cuePoints)
{
    if (CurrentCuePoints.GetSize() > 0)
    {
        *cuePoints = CurrentCuePoints;
        CurrentCuePoints.Clear();
    }
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d020
bool VideoPlayer::LoadVideoInfo(const char* url, VideoInfo* pinfo, FileOpenerBase* pfileOpener)
{
    bool ok = false;
    struct { unsigned Flags; UPInt MinAlign, Granularity, Reserve, Threshold, Limit, HeapId, Arena; } desc =
        { 0, 16, 16 * 1024, 16 * 1024, ~UPInt(0), 0, 8 /* HeapId_Video */, 0 };
    MemoryHeap* pheap = Memory::GetGlobalHeap()->CreateHeap("_VideoInfo_Heap", *(const HeapDesc*)&desc);
    void* mem = pheap->Alloc(sizeof(VideoPlayerImpl));
    VideoPlayerImpl* pplayer = mem ? ::new(mem) VideoPlayerImpl(pheap) : NULL;
    pplayer->Init(NULL, NULL, pfileOpener, NULL);
    pplayer->Open(url);
    while (pplayer->GetStatus() == Opening)
        pplayer->Decode();
    if (pplayer->GetStatus() == Ready)
    {
        ok = true;
        pplayer->GetVideoInfo(pinfo);
    }
    pplayer->Destroy();
    pheap->Release();
    return ok;
}

// ==== VideoReader ====================================================================================================

// The reader's file: a Scaleform File held as a thread-safe reference.
static inline File* ReaderFile(RefCountImpl* pfile) { return (File*)pfile; }

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d230
CriSint64 VideoReader::Seek(CriSint64 size, SeekOrigin offset)
{
    switch (offset)
    {
    case SEEK_FROM_CURRENT: Position = FilePos;  break;
    case SEEK_FROM_END:     Position = FileSize; break;
    default:                Position = 0;        break;
    }
    Position += size;
    return Position;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d4f0
void VideoReader::OpenFile(const char* fname)
{
    File* pfile = pReaderConfig->pFileOpener->OpenFile(fname, FileConstants::Open_Read | FileConstants::Open_Buffered,
                                                       FileConstants::Mode_ReadWrite);
    if (pFile)
        pFile->Release();
    pFile = (RefCountImpl*)pfile;
    if (pfile && pfile->IsValid())
    {
        FileSize   = ReaderFile(pFile)->GetLength();
        OpenStatus = ASYNC_STATUS_COMPLETE;
    }
    else
    {
        OpenStatus  = ASYNC_STATUS_ERROR;
        ReadStatus  = ASYNC_STATUS_ERROR;
        CloseStatus = ASYNC_STATUS_ERROR;
    }
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d590
void VideoReader::CloseFile()
{
    if (pFile && !ReaderFile(pFile)->Close())
        CloseStatus = ASYNC_STATUS_ERROR;
    else
        CloseStatus = ASYNC_STATUS_COMPLETE;
    if (pFile)
        pFile->Release();
    pFile = NULL;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d5e0
void VideoReader::ReadFile(UByte* buffer, SInt64 size)
{
    if (pFile && ReaderFile(pFile)->IsValid())
    {
        if (!pReaderConfig->IOEnabled)
        {
            ReadSize   = 0;
            ReadStatus = ASYNC_STATUS_COMPLETE;
            return;
        }
        if (FilePos != Position)
        {
            if (ReaderFile(pFile)->LSeek(Position, File::Seek_Set) == -1)
            {
                ReadStatus = ASYNC_STATUS_ERROR;
                return;
            }
            FilePos = Position;
        }
        SInt64 toread = (FilePos + size > FileSize) ? FileSize - FilePos : size;
        int    nread  = ReaderFile(pFile)->Read(buffer, (int)toread);
        if (nread != -1)
        {
            ReadSize   = nread;
            ReadStatus = ASYNC_STATUS_COMPLETE;
            FilePos   += nread;
            Position   = FilePos;
            return;
        }
    }
    ReadStatus = ASYNC_STATUS_ERROR;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d970
VideoReader::VideoReader(VideoReaderConfig* pconfig)
    : pReaderConfig(pconfig), pFile(NULL), ReadSize(0)
{
    FUN_14001d650(pconfig, this);
    OpenStatus  = ASYNC_STATUS_STOP;
    ReadStatus  = ASYNC_STATUS_STOP;
    CloseStatus = ASYNC_STATUS_STOP;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d430
VideoReader::~VideoReader()
{
    pReaderConfig->DetachReader(this);
    if (pFile)
        pFile->Release();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002da70
void VideoReader::Open(CriChar8* fname)
{
    FileSize = -1;
    ReadSize = 0;
    FilePos  = 0;
    Position = 0;
    OpenFile((const char*)fname);
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002da90
void VideoReader::Close(void)
{
    CloseFile();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002dae0
void VideoReader::Read(CriUint8* buffer, CriSint64 req_size)
{
    while (!pReaderConfig->IOEnabled)
        FUN_14258b240(50);
    ReadFile(buffer, req_size);
}

// ==== VideoReaderConfigSmp ===========================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002df50
VideoReader* VideoReaderConfigSmp::CreateReader()
{
    void* mem = pHeap->Alloc(sizeof(VideoReader));
    return mem ? ::new(mem) VideoReader(this) : NULL;
}

}}} // namespace Scaleform::GFx::Video

// ==== CRI Movie player state and frame-buffer helpers ===============================================================

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this accessor is rebuilt with our VS2017 toolset.
// @0x140031020
void FUN_140031020(void* player, CriUint32 value)
{
    *(CriUint32*)((CriUint8*)player + 0x8c4) = value;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this accessor is rebuilt with our VS2017 toolset.
// @0x140031040
void criMvPly_SetAudioTrack(void* player, CriUint32 track)
{
    *(CriUint32*)((CriUint8*)player + 0x8c8) = track;
}

// MS2-FUNCTIONAL: preserves the executable's invalid-value store after its diagnostic call.
// @0x140031060
void FUN_140031060(void* player, CriSint32 value)
{
    if (value < 1)
        FUN_140037950(player, "E10120701M: the parameter nframe must be greater than 0", 0);
    *(CriSint32*)((CriUint8*)player + 0xed8) = value;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this accessor is rebuilt with our VS2017 toolset.
// @0x1400310b0
CriSint32 criMvPly_GetStatus(void* player)
{
    return *(CriSint32*)((CriUint8*)player + 4);
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this accessor is rebuilt with our VS2017 toolset.
// @0x1400310e0
CriSint32 getInternalStatus(void* player)
{
    return *(CriSint32*)((CriUint8*)player + 4);
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this helper is rebuilt with our VS2017 toolset.
// @0x1400351c0
void crimvply_clearAlphaFrameInfoMembers(void* info)
{
    memset(info, 0, 0x40);
    *(CriSint32*)((CriUint8*)info + 0x08) = -1;
    *(CriUint32*)((CriUint8*)info + 0x28) = 1;
    *(CriSint32*)((CriUint8*)info + 0x30) = -1;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this predicate is rebuilt with our VS2017 toolset.
// @0x140035560
CriBool crimvply_isUnderGetFrameCondition(void* player)
{
    if (*(CriSint32*)((CriUint8*)player + 8) == 1)
        return 0;
    CriSint32 status = *(CriSint32*)((CriUint8*)player + 4);
    return status == 4 || status == 5;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this frame-info copier is rebuilt with our VS2017 toolset.
// @0x1400358d0
CriUint32 FUN_1400358d0(void* output, const void* info)
{
    CriMvPlaneInfo* out = (CriMvPlaneInfo*)output;
    const CriMvFramePlaneSource* in = (const CriMvFramePlaneSource*)info;
    memset(out, 0, 0x40);
    CriUint32 planes = in->PlaneCount;
    if (planes != 0)
    {
        out[0].Buffer = in->Planes[0].Buffer;
        out[0].Stride = (CriSint32)in->Planes[0].Height * (CriSint32)in->Planes[0].Width;
        out[0].Height = in->Planes[0].Height;
    }
    if (planes > 1)
    {
        out[1].Buffer = in->Planes[1].Buffer;
        out[1].Stride = (CriSint32)in->Planes[1].Height * (CriSint32)in->Planes[1].Width;
        out[1].Height = in->Planes[1].Height;
    }
    if (planes > 2)
    {
        out[2].Buffer = in->Planes[2].Buffer;
        out[2].Stride = (CriSint32)in->Planes[2].Height * (CriSint32)in->Planes[2].Width;
        out[2].Height = in->Planes[2].Height;
    }
    return planes;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this plane updater is rebuilt with our VS2017 toolset.
// @0x1400359e0
void crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(void* player, const CriMvAlphaDecoderFrameInfo* info)
{
    if (info->PlaneIndex != -1)
    {
        CriMvPlaneInfo* dst = &((CriMvYuvBufferState*)player)->Plane;
        dst->Buffer = info->Buffer;
        dst->Stride = (CriSint32)info->Height * (CriSint32)info->Stride;
        dst->Height = info->Height;
    }
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this setter is rebuilt with our VS2017 toolset.
// @0x140036450
void criMvPly_SetSubtitleChannel(void* player, CriUint32 channel)
{
    *(CriUint32*)((CriUint8*)player + 0xe34) = channel;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this setter is rebuilt with our VS2017 toolset.
// @0x1400372c0
void criMvPly_SetPcmFormat(void* player, CriSint32 format)
{
    *(CriSint32*)((CriUint8*)player + 0xe18) = format;
    *(CriUint32*)((CriUint8*)player + 0xe1c) = format == 0 ? 2 : 4;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this setter is rebuilt with our VS2017 toolset.
// @0x140037740
void FUN_140037740(void* player, CriUint32 value0, CriUint32 value1)
{
    CriMvStateFlags* state = (CriMvStateFlags*)player;
    state->Value0 = value0;
    state->Value1 = value1;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this setter is rebuilt with our VS2017 toolset.
// @0x140037780
void FUN_140037780(void* player, CriUint32 value)
{
    ((CriMvStateFlags*)player)->Value2 = value;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this state transition is rebuilt with our VS2017 toolset.
// @0x1400379b0
void* crimvply_transitErrorState(void* player, void* fallback)
{
    if (player)
    {
        ((CriMvErrorState*)player)->Error = 1;
        return player;
    }
    return fallback;
}

// MS2-FUNCTIONAL: CRI Movie was built with VS2008; preserve the input-chunk state check from the executable.
// @0x140035000
CriBool isLockedInputChunk(const void* player)
{
    return ((const CriMvInputLockState*)player)->Locked != 0;
}

// MS2-FUNCTIONAL: CRI Movie was built with VS2008; this transition helper is rebuilt with our VS2017 toolset.
// @0x140035050
void criMvPly_TerminateSupply(void* player)
{
    CriMvSupplyState* state = (CriMvSupplyState*)player;
    state->SupplyEnded = 1;
    state->Terminated = 1;
    FUN_140044fdc(((CriMvSupplyInputBuffer*)player)->InputBuffer);
}

// MS2-FUNCTIONAL: initializes the observed 0x90-byte next-frame record and its two sentinel fields.
// @0x140035090
void FUN_140035090(void* record)
{
    memset(record, 0, 0x90);
    *(CriSint32*)((CriUint8*)record + 8) = -1;
    *(CriUint32*)((CriUint8*)record + 0x30) = 1;
    *(CriSint32*)((CriUint8*)record + 0x3c) = -1;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; preserve its null-safe Windows critical-section wrapper.
// @0x140039dd4
CriBool criCsWin_InitializeCriticalSection(LPCRITICAL_SECTION section)
{
    if (section)
        InitializeCriticalSection(section);
    return section != NULL;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; preserve its null-safe Windows critical-section wrapper.
// @0x140039dfc
CriBool criCsWin_DeleteCriticalSection(LPCRITICAL_SECTION section)
{
    if (section)
        DeleteCriticalSection(section);
    return section != NULL;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; preserve its null-safe Windows critical-section wrapper.
// @0x140039e24
CriBool FUN_140039e24(LPCRITICAL_SECTION section)
{
    if (section)
        EnterCriticalSection(section);
    return section != NULL;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; preserve its null-safe Windows critical-section wrapper.
// @0x140039e4c
CriBool FUN_140039e4c(LPCRITICAL_SECTION section)
{
    if (section)
        LeaveCriticalSection(section);
    return section != NULL;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this ownership check is rebuilt with our VS2017 toolset.
// @0x140039e74
CriBool criCs_IsInCriticalSection(const void* state)
{
    const CriUint8* bytes = (const CriUint8*)state;
    CriSint32 depth = *(const CriSint32*)(bytes + 0x2c);
    if (depth < 1)
        return 0;
    return GetCurrentThreadId() == *(const DWORD*)(bytes + 0x28);
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this stores its caller-supplied metadata allocator.
// @0x1400301d0
void criMvPly_SetMetaDataWorkAllocator(void* player, void* work, void* allocate, void* freeFn)
{
    CriMvMetadataAllocatorFields* fields = (CriMvMetadataAllocatorFields*)player;
    fields->Work = work;
    fields->Allocate = allocate;
    fields->Free = freeFn;
}

// MS2-FUNCTIONAL: the work-size helper combines the CRI RBF, demux, and two universal-jump-buffer requirements.
// @0x14002e9e0
CriSint32 FUN_14002e9e0(void)
{
    CriUint32 rbfConfig[6] = { 1, 0x2800, 0, 0x40, 0, 0 };
    CriSint32 total = 0x376c + 4 + FUN_140045ed0(rbfConfig);
    total += 4 + FUN_140044eb0(8);
    CriUint32 uniConfig[3] = { 1, 0, 0x40 };
    total += FUN_140045910(uniConfig);
    uniConfig[2] = 4;
    return total + FUN_140045910(uniConfig);
}

// MS2-FUNCTIONAL: the CRI Movie sub-audio helper forwards the caller's sizing inputs with flags set to zero.
// @0x140030ed0
CriSint32 criMvPly_CalcSubAudioWorkSize(void* player, void* source, void* work, CriUint32 size)
{
    return FUN_140042150(player, source, work, size, 0);
}

// MS2-FUNCTIONAL: retain CRI's critical-section bracket around work-buffer preparation.
// @0x140030230
CriUint32 criMvPly_AllocateWorkBuffer(void* player, void* heap, void* work)
{
    FUN_140037850(player);
    CriUint32 result = FUN_140030280(player, heap, work);
    FUN_140037880(player);
    return result;
}

// MS2-FUNCTIONAL: create the supplied-memory heap, store it in the player, then prepare its work buffers under lock.
// @0x140030e50
CriUint32 criMvPly_AllocateWorkBufferWithWork(void* player, void* memory, CriSint32 size, void* work)
{
    FUN_140037850(player);
    CriHeap heap = FUN_140027fec(memory, size);
    ((CriMvHeapWorkState*)player)->Heap = heap;
    CriUint32 result = FUN_140030280(player, heap, work);
    FUN_140037880(player);
    return result;
}

// MS2-PIN: ??_7VideoPlayer@Video@GFx@Scaleform@@6B@ 0x1431b8e30
// MS2-PIN: ??_7VideoPlayerImpl@Video@GFx@Scaleform@@6B@ 0x1431b9260
// MS2-PIN: ??_7VideoDecoderSmp@Video@GFx@Scaleform@@6B@ 0x1431b9170
// MS2-PIN: ??_7VideoDecoderThrd@Video@GFx@Scaleform@@6B@ 0x1431b9200
// MS2-PIN: ??_7VideoReader@Video@GFx@Scaleform@@6BRefCountImplCore@Scaleform@@@ 0x1431b93b0
// MS2-PIN: ??_7VideoReader@Video@GFx@Scaleform@@6BCriMvFileReaderInterface@@@ 0x1431b9360
// MS2-PIN: ??_7VideoReaderConfigSmp@Video@GFx@Scaleform@@6B@ 0x1431b91d8
