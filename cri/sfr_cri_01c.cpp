// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the CRI Movie 3.07.01 "easy player" layer (CriMvEasyPlayer,
// 0x14001d7a0-0x140025090), the CriMv C++ wrappers and CRI Heap 1.21.02 (0x140026db0-0x140028360). Our own source,
// written from the exe; the leaked SDK copies were only used to name things. The Scaleform GFx Video code these runs
// sit between stays in sfr_cri_01 (VS2012). The CRI library was built with VS2008 SP1, and so is this unit
// (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto, decltype, variadic templates, brace-init
// or nullptr).
// MS2-UNIT: sfr_cri_01c
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14001d7a0-0x140025090 .text$mn
// MS2-RANGE: 0x140026db0-0x140028360 .text$mn
// MS2-PIN: ??_7CriMvEasyPlayer@@6B@ 0x1431b8a40
// MS2-PIN: ??_GCriMvEasyPlayer@@MEAAPEAXI@Z 0x140024f40
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/cri/cri_movie.h"
#include <string.h>

// The VS2008 build has no /GS cookies in these frames; VS2008 itself has no safebuffers (and puts no cookie in them).
#if defined(_MSC_VER) && _MSC_VER >= 1600
#define CRIMVEASY_SAFEBUFFERS __declspec(safebuffers)
#else
#define CRIMVEASY_SAFEBUFFERS
#endif

// ==== CRI Movie easy player ==========================================================================================
// CriMvEasyPlayer (0x14001d7a0-0x140025090). The CRI objects of this layer were compiled /Od, so the section is built
// with optimization off; the VS2008 code generator picks other registers for some int stores (those are functional).

// Player handle module (criMvPly, sfr_cri_02), error notification and the update lock.
// C3: the definitions' names and signatures
void criFixedAllocator_Create(void *, unsigned long, struct CriFixedAllocator *);
void * criFixedAllocator_Allocate(struct CriFixedAllocator *, unsigned long, unsigned long);
void criMvPly_SetMetaDataWorkAllocator(void *, void *, void *, void *, long);
unsigned long criMvPly_AllocateWorkBuffer(void *, void *, void *);
unsigned long criMvPly_AllocateWorkBufferWithWork(void *, void *, long, void *);
long criMvPly_CalcSubAudioWorkSize(void *, void *);
void criMvPly_DetachSubAudio(void *);
void criMvPly_SetAudioTrack(void *, unsigned long);
long criMvPly_GetStatus(void *);
void criMvPly_TerminateSupply(void *);
unsigned long criMvPly_GetDataSizeMainAudio(void *, unsigned long);
unsigned long criMvPly_GetDataSizeSubAudio(void *, unsigned long);
void criMvPly_SetSubtitleChannel(void *, unsigned long);
void criMvPly_GetSubtitle(void *, void *, unsigned long, void *);
void criMvPly_GetNextSubtitleInfo(void *, void *);
long criMvPly_PeekInputBufferData(void *);
void criMvPly_SetPcmFormat(void *, long);
void criErr_Notify(long, char const *);
void criCs_Destroy(struct _RTL_CRITICAL_SECTION *);
unsigned long criAtomic_TestAndSet(unsigned long *, unsigned long);
void criUtfRtv_Destroy(unsigned __int64 *);
unsigned long FID_conflict_criUtfRtv_GetDataSint32Fn(struct CriUtfRtvView const *, unsigned long, char const *);
void * criUtfRtv_Create(void *, void *, unsigned long);
unsigned char const * criUsfCmn_GetContents(unsigned char const *, unsigned long, long *);
long criVmpv_CalcMovieHandleWork(long);
unsigned long criVmpv_GetMaxNumberOfHandles(void);
// C3: the definitions' names and signatures
void FUN_14002e6bc(struct CriFixedAllocator *);
void FUN_14002e7d0(void);
void FUN_14002e8c0(void);
long FUN_14002e9e0(void);
void * FUN_14002eb20(void *, long);
void * FUN_14002f1f0(struct _criheap_struct *);
void FUN_14002f610(unsigned long *);
void FUN_14002fb70(void *);
void FUN_14002fbe0(void *, struct CriMvStreamingParameters *);
void FUN_140030c70(void *);
long FUN_140030f10(void *, void *, unsigned long);
void FUN_140031020(void *, unsigned long);
void FUN_140031060(void *, long);
void FUN_140031100(void *);
void FUN_140031250(void *);
long FUN_1400313d0(void *);
void FUN_140031470(void *);
void FUN_140033700(void *, void const *, unsigned long, long, void **, long *);
long FUN_140034920(void *);
void FUN_140034b20(void *);
void FUN_140034d40(void *, struct CriMovieInputChunk *);
void FUN_140034e70(void *, struct CriMovieInputChunk const *, unsigned long);
unsigned long FUN_140035f00(void *, unsigned long, void *, unsigned long, void *);
unsigned long FUN_140035f70(void *, unsigned long, void *, unsigned long, void *);
unsigned long FUN_140035fe0(void *, unsigned long, void *, unsigned long, void *);
unsigned long FUN_140036050(void *, unsigned long, void *, unsigned long, void *);
void FUN_1400361a0(void *, void const *, unsigned long);
void FUN_1400363b0(void *, void *, unsigned long);
long FUN_140037400(void *, struct CriMvStreamingParameters const *);
void FUN_140037740(void *, unsigned long, unsigned long);
void FUN_140037780(void *, unsigned long);
void FUN_1400379e0(void const *);
void FUN_140039f50(struct _RTL_CRITICAL_SECTION *);
void FUN_140039f8c(struct _RTL_CRITICAL_SECTION *);
void FUN_14003b6e0(void);
void FUN_14003b720(struct CriMvSubAudioTrackState *, long, long const *, long const *);
void FUN_14003b880(void);
long FUN_14003b8b0(void *, unsigned char *, unsigned long, unsigned long, void *);
void FUN_14003bb60(void *, unsigned char *, unsigned long, unsigned long, void const *, void const *, void const *);
long FUN_14003bf80(unsigned long, void *, unsigned long);
void * FUN_14003c060(unsigned long *);
void * FUN_1400411e0(unsigned long *);
void FUN_1400411f8(void);
extern "C" {
void*     FUN_140038ce4(CriSint32 level, const CriChar8* msg, CriSint32 p1, CriSint32 p2, void* p3);
int       sprintf_s(char* buf, size_t size, const char* fmt, ...);
void*     FUN_1400385c8(void* work, CriUint32 work_size);
CriBool   FUN_140036140(CriMvPly mvply);
CriBool   FUN_140036170(CriMvPly mvply);
}

extern const CriChar8* DAT_143b277b8;   // version string of the last created player
extern CriUint32 DAT_143b278c8;         // live player count

extern CriUint32 DAT_143b278c4;         // CriMv library init count
extern CriChar8  DAT_143b277c0[0x100];  // last error message

#pragma optimize("", off)
#pragma function(memset, memcpy, strlen)

static const CriChar8 crimveasy_version_str[] = "\nCRI Movie/PCx64 Ver.3.07.01 Build:Jan 20 2012 18:13:31\n";

// MS2-FUNCTIONAL: the VS2008 build keeps an EH state slot for the placement new (this profile has no EH)
// @0x14001d7a0
CRIMVEASY_SAFEBUFFERS CriMvEasyPlayer* CriMvEasyPlayer::Create(void* work, CriUint32 work_size, CriMvFileReaderInterface* freader,
                                         CriMvSystemTimerInterface* stimer, CriMvSoundInterface* sound,
                                         CriError& err)
{
    CriMvWorkAllocator walloc;
    CriHeap heap;
    void* heap_work;
    CriSint32 ply_work_size;
    CriMvEasyPlayer* mveasy;
    CriUint32 heap_work_size;
    CriMvSoundInterface::PcmFormat fmt;

    DAT_143b277b8 = crimveasy_version_str;
    err = CRIERR_OK;
    if (CriMv::IsLibraryInitialized() == 0)
    {
        FUN_140038ce4(0, "E09031802M: Need to call CriMv::Initialize() before CriMvEasyPlayer::Create().", 0, 0,
                      NULL);
        err = CRIERR_NG;
        return NULL;
    }
    criFixedAllocator_Create(work, work_size, (CriFixedAllocator *)&walloc);
    heap_work_size = 0x818;
    heap_work = criFixedAllocator_Allocate((CriFixedAllocator *)&walloc, heap_work_size, 4);
    heap = criHeap_Create(heap_work, heap_work_size);
    mveasy = new(heap, "CriMvEasyPlayer", 4) CriMvEasyPlayer;
    if (mveasy == NULL)
    {
        err = CRIERR_NG;
        return NULL;
    }
    mveasy->heap = NULL;
    mveasy->freader = freader;
    mveasy->stimer = stimer;
    mveasy->sound = sound;
    mveasy->work_heap = heap;
    DAT_143b278c8 = DAT_143b278c8 + 1;
    mveasy->freader_file = freader;
    mveasy->freader_mem = CriMvEasyFileReaderMem::Create(heap);
    if (mveasy->freader_mem == NULL)
    {
        err = CRIERR_NG;
        mveasy->Destroy();
        return NULL;
    }
    mveasy->cs_work = criFixedAllocator_Allocate((CriFixedAllocator *)&walloc, 0x48, 4);
    if (mveasy->cs_work == NULL)
    {
        err = CRIERR_NG;
        mveasy->Destroy();
        return NULL;
    }
    mveasy->cs = FUN_1400385c8(mveasy->cs_work, 0x48);
    if (mveasy->cs_work == NULL)
    {
        err = CRIERR_NG;
        mveasy->Destroy();
        return NULL;
    }
    ply_work_size = FUN_14002e9e0();
    mveasy->mvply_work = criFixedAllocator_Allocate((CriFixedAllocator *)&walloc, ply_work_size, 4);
    if (mveasy->mvply_work != NULL)
    {
        mveasy->mvply = (CriMvPly)FUN_14002eb20(mveasy->mvply_work, ply_work_size);
    }
    if (mveasy->mvply == NULL)
    {
        err = CRIERR_NG;
        mveasy->Destroy();
        return NULL;
    }
    FUN_140031020(mveasy->mvply, 8000);
    if (mveasy->sound != NULL)
    {
        fmt = mveasy->sound->GetPcmFormat();
        if (fmt == CriMvSoundInterface::PCM_FORMAT_FLOAT32)
        {
            criMvPly_SetPcmFormat(mveasy->mvply, 1);
        }
        else
        {
            criMvPly_SetPcmFormat(mveasy->mvply, 0);
        }
    }
    mveasy->subaudio = NULL;
    mveasy->resetPlayback();
    FUN_14002e6bc((CriFixedAllocator *)&walloc);
    return mveasy;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001dba0
CRIMVEASY_SAFEBUFFERS CriSint32 CriMvEasyPlayer::CalcPlaybackWorkSize(const CriMvStreamingParameters* stmprm, CriError& err)
{
    CriMvStreamingParameters prm;
    CriSint32 audio_size5;
    CriBool ok3;
    CriSint32 size = 0;
    CriSint32 subtitle_size4;
    CriSint32 ply_size;

    err = CRIERR_OK;
    if (stmprm == NULL)
    {
        ok3 = GetHeaderInfo(&prm);
        if (ok3 == 0)
        {
            return -1;
        }
    }
    else
    {
        memcpy(&prm, stmprm, sizeof(prm));
    }
    subtitle_size4 = prm.max_subtitle_size + 4;
    size += subtitle_size4;
    ply_size = FUN_140037400(mvply, &prm) + 4;
    size += ply_size;
    if (this->stmprm.track_play_audio != -1 && sound != NULL)
    {
        size += (size_t)0x24;
        if (isAvailableCenterVoice(&prm) == 1)
        {
            audio_size5 = criMvPly_CalcSubAudioWorkSize(mvply, &prm.audio_prm[center_voice_track]);
            size += audio_size5 + (size_t)0x1a4;
        }
        if (subaudio_track != -1 && prm.audio_prm[subaudio_track].num_channel != 0)
        {
            audio_size5 = criMvPly_CalcSubAudioWorkSize(mvply, &prm.audio_prm[subaudio_track]);
            size += audio_size5 + (size_t)0x1a4;
        }
    }
    return size;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001dd80
void CriMvEasyPlayer::SetPlaybackWork(void* work, CriUint32 work_size, CriError& err)
{
    err = CRIERR_OK;
    playback_work = work;
    playback_work_size = work_size;
}

// MS2-FUNCTIONAL: the VS2008 build keeps an EH state slot for the placement new (this profile has no EH)
// @0x14001de20
CriMvEasyPlayer* CriMvEasyPlayer::Create(CriHeap heap, CriMvFileReaderInterface* freader,
                                         CriMvSystemTimerInterface* stimer, CriMvSoundInterface* sound,
                                         CriError& err)
{
    CriMvEasyPlayer* mveasy;
    CriMvSoundInterface::PcmFormat fmt;

    DAT_143b277b8 = crimveasy_version_str;
    err = CRIERR_OK;
    if (CriMv::IsLibraryInitialized() == 0)
    {
        FUN_140038ce4(0, "E09031802M: Need to call CriMv::Initialize() before CriMvEasyPlayer::Create().", 0, 0,
                      NULL);
        err = CRIERR_NG;
        return NULL;
    }
    mveasy = new(heap, "CriMvEasyPlayer", 4) CriMvEasyPlayer;
    if (mveasy == NULL)
    {
        err = CRIERR_NG;
        return NULL;
    }
    mveasy->heap = heap;
    mveasy->freader = freader;
    mveasy->stimer = stimer;
    mveasy->sound = sound;
    DAT_143b278c8 = DAT_143b278c8 + 1;
    mveasy->cs_work = criHeap_AllocFix(heap, 0x48, "CriMvEasyPlayer: CriCsWork", 4);
    if (mveasy->cs_work == NULL)
    {
        err = CRIERR_NG;
        mveasy->Destroy();
        return NULL;
    }
    mveasy->cs = FUN_1400385c8(mveasy->cs_work, 0x48);
    if (mveasy->cs_work == NULL)
    {
        err = CRIERR_NG;
        mveasy->Destroy();
        return NULL;
    }
    mveasy->mvply = (CriMvPly)FUN_14002f1f0(heap);
    if (mveasy->mvply == NULL)
    {
        err = CRIERR_NG;
        mveasy->Destroy();
        return NULL;
    }
    FUN_140031020(mveasy->mvply, 8000);
    mveasy->freader_file = freader;
    mveasy->freader_mem = CriMvEasyFileReaderMem::Create(heap);
    if (mveasy->freader_mem == NULL)
    {
        err = CRIERR_NG;
        mveasy->Destroy();
        return NULL;
    }
    if (mveasy->sound != NULL)
    {
        fmt = mveasy->sound->GetPcmFormat();
        if (fmt == CriMvSoundInterface::PCM_FORMAT_FLOAT32)
        {
            criMvPly_SetPcmFormat(mveasy->mvply, 1);
        }
        else
        {
            criMvPly_SetPcmFormat(mveasy->mvply, 0);
        }
    }
    mveasy->subaudio = NULL;
    mveasy->resetPlayback();
    return mveasy;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001ddd0
void CriMvEasyPlayer::SetMetaDataWorkAllocator(void* (*allocfunc)(void* obj, CriUint32 size),
                                               void (*freefunc)(void* obj, void* mem), void* obj,
                                               CriMvMetaFlag meta_flag)
{
    criMvPly_SetMetaDataWorkAllocator(mvply, allocfunc, freefunc, obj, meta_flag);
}

// @0x14001e160
void CriMvEasyPlayer::ResetAllParameters(CriError& err)
{
    err = CRIERR_OK;
    Status stat = GetStatus();
    if (stat != MVEASY_STATUS_STOP && stat != MVEASY_STATUS_PLAYEND)
    {
        err = CRIERR_NG;
        return;
    }
    resetPlayback();
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001e1c0
void CriMvEasyPlayer::resetPlayback(void)
{
    timer_type = MVEASY_TIMER_SYSTEM;
    status_after_stop = MVEASY_STATUS_STOP;
    stmprm_flag = 0;
    num_frame_pools = 1;
    loop_flag = 0;
    pause_flag = 0;
    user_time_count = 0;
    user_time_unit = 1;
    file_read_pos = 0;
    file_read_end = -1;
    unk4a0 = 0;
    memory_playback_type = 1;
    data_type = 0;
    unk4c0 = 0;
    unk5e4 = 0;
    modules_stopped = 0;
    file_request_state = 0;
    memset(fname, 0, sizeof(fname));
    file_offset = 0;
    file_range = -1;
    data_ptr = NULL;
    data_size = 0;
    center_channel = 4;
    center_voice_track = -1;
    attached_center_voice_track = -1;
    subaudio_track = -1;
    attached_subaudio_track = -1;
    buffering_time = 0.0f;
    max_bitrate = 0;
    max_chunk_size = 0;
    min_buffer_size = 0;
    read_buffer_size = -1;
    subtitle_channel = -1;
    audio_track = 100;
    seek_frame_id = 0;
    seek_offset = 0;
    SetFileRequestCallback(NULL, NULL);
    SetCuePointCallback(NULL, NULL);
    SetStopCompleteCallback(NULL, NULL);
    playback_work = NULL;
    playback_work_size = 0;
    work_heap = NULL;
    sound_heap = NULL;
    unk6f0 = 0;
    if (mvply != NULL)
    {
        mvply->reload_threshold = 0.8f;
        mvply->unked8 = -1;
        criMvPly_SetAudioTrack(mvply, audio_track);
    }
    resetHandleParameters();
    initializeCompareFrameParameters();
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001e500
void CriMvEasyPlayer::resetHandleParameters(void)
{
    req_decode_header = 0;
    req_prepare = 0;
    unk724 = 0;
    unk5e8 = 0;
    unk4c4 = 0;
    if (filereq_func != NULL)
    {
        file_request_state = 0;
    }
    else if (unk4a0 != 0 && data_type != 0)
    {
        file_request_state = 1;
    }
    num_audio_channel = 0;
    unk3c8 = 0;
    time0_count = 0;
    time0_unit = 1;
    time1_count = 0;
    time1_unit = 1;
    time2_count = 0;
    time2_unit = 1;
    unk650 = 0;
    unk658 = 0;
    unk660 = 0.0f;
    unk658 = 0;
    memset(playback_info, 0, sizeof(playback_info));
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001e680
void CriMvEasyPlayer::initializeCompareFrameParameters(void)
{
    compare_frame_count = 0;
    SetCompareFrameTimeCallback(compareFrameTimeFluctuation, NULL);
    compare_frame_prm0 = 1.0f;
    compare_frame_prm1 = 5.4f;
    compare_frame_prm2 = 1.0f;
    compare_frame_prm3 = 1.0f;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001e720
void CriMvEasyPlayer::Destroy(CriError& err)
{
    CriSint32 locked1;
    void* cs_tmp;
    CriMvPly ply1;
    void* cs_work_tmp;
    CriMvEasyFileReaderMem* fr3;

    err = CRIERR_OK;
    locked1 = criAtomic_TestAndSet((unsigned long *)&destroy_lock, 1);
    if (locked1 == 1)
    {
        notifyErrorB(this,
                     "E11021601M: CriMvEasyPlayer::Destroy is called during a call of CriMvEasyPlayer::ExecuteDecode.",
                     0);
    }
    else
    {
        criAtomic_TestAndSet((unsigned long *)&destroy_lock, 0);
    }
    if (freader_mem != NULL)
    {
        fr3 = freader_mem;
        fr3->Destroy();
        freader_mem = NULL;
    }
    if (cs != NULL)
    {
        FUN_140039f50((_RTL_CRITICAL_SECTION *)cs);
    }
    ply1 = mvply;
    mvply = NULL;
    FUN_14002f610((unsigned long *)ply1);
    if (work_heap != NULL)
    {
        criHeap_Destroy(work_heap);
        work_heap = NULL;
    }
    if (cs != NULL)
    {
        FUN_140039f8c((_RTL_CRITICAL_SECTION *)cs);
    }
    cs_tmp = cs;
    if (cs_tmp != NULL)
    {
        cs = NULL;
        criCs_Destroy((_RTL_CRITICAL_SECTION *)cs_tmp);
    }
    cs_work_tmp = cs_work;
    if (heap != NULL && cs_work_tmp != NULL)
    {
        cs_work = NULL;
        criHeap_Free(heap, cs_work_tmp);
    }
    DAT_143b278c8 = DAT_143b278c8 - 1;
    if (heap != NULL)
    {
        delete this;
    }
}

// MS2-FUNCTIONAL: VS2008 /Od lowers the switch with its own jump-table layout
// @0x14001e940
CriMvEasyPlayer::Status CriMvEasyPlayer::GetStatus(CriError& err)
{
    Status stat;
    err = CRIERR_OK;
    CriSint32 plystat = criMvPly_GetStatus(mvply);
    if (error_flag == 1)
    {
        return MVEASY_STATUS_ERROR;
    }
    switch (plystat)
    {
    case 1:
        stat = MVEASY_STATUS_DECHDR;
        break;
    case 2:
        stat = MVEASY_STATUS_WAIT_PREP;
        break;
    case 3:
        stat = MVEASY_STATUS_PREP;
        break;
    case 4:
        stat = MVEASY_STATUS_READY;
        break;
    case 5:
    case 6:
        stat = MVEASY_STATUS_PLAYING;
        break;
    case 7:
        stat = MVEASY_STATUS_PLAYEND;
        break;
    case 8:
    case 9:
    case 10:
        stat = status_after_stop;
        break;
    default:
        stat = MVEASY_STATUS_STOP;
        break;
    }
    return stat;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001ea50
CriUint32 CriMvEasyPlayer::crimveasy_SupplyPcmDataByFloat32(void* obj, CriUint32 nch, CriFloat32* sample[],
                                                           CriUint32 nsmpl)
{
    CriUint32 i;
    CriUint32 n;
    CriMvEasyPlayer* mveasy = (CriMvEasyPlayer*)obj;
    if (mveasy == NULL)
    {
        return 0;
    }
    if (sample == NULL)
    {
        mveasy->setNormalErrorStatus("E090040802M: Cannot write sound data into the app's sound buffer.");
        return 0;
    }
    for (i = 0; i < nch; i++)
    {
        memset(sample[i], 0, nsmpl * sizeof(CriFloat32));
    }
    n = crimveasy_GetWave32(mveasy, nch, sample, nsmpl);
    if (n == 0)
    {
        return 0;
    }
    return n;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001eb20
CriUint32 CriMvEasyPlayer::crimveasy_SupplyPcmDataBySint16(void* obj, CriUint32 nch, CriSint16* sample[],
                                                          CriUint32 nsmpl)
{
    CriUint32 i;
    CriUint32 n;
    CriMvEasyPlayer* mveasy = (CriMvEasyPlayer*)obj;
    if (mveasy == NULL)
    {
        return 0;
    }
    if (sample == NULL)
    {
        mveasy->setNormalErrorStatus("E090040801M: Cannot write sound data into the app's sound buffer.");
        return 0;
    }
    for (i = 0; i < nch; i++)
    {
        memset(sample[i], 0, nsmpl * sizeof(CriSint16));
    }
    n = crimveasy_GetWave16(mveasy, nch, sample, nsmpl);
    if (n == 0)
    {
        return 0;
    }
    return n;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001ebe0
CriUint32 CriMvEasyPlayer::crimveasy_CalcAvailableNumSmpls(CriMvEasyPlayer* mveasy)
{
    CriUint32 cv_n0;
    CriUint32 n;
    CriBool cv_end;
    CriUint32 main_n;
    CriBool main_endVal;
    main_endVal = 1;
    cv_end = 1;
    main_endVal = FUN_140036140(mveasy->mvply);
    main_n = criMvPly_GetDataSizeMainAudio(mveasy->mvply, mveasy->num_audio_channel);
    if (mveasy->attached_center_voice_track == -1)
    {
        n = main_n;
    }
    else
    {
        cv_end = FUN_140036170(mveasy->mvply);
        cv_n0 = criMvPly_GetDataSizeSubAudio(mveasy->mvply, 1);
        if (main_endVal == 1)
        {
            n = cv_n0;
        }
        else if (cv_end == 1)
        {
            n = main_n;
        }
        else
        {
            n = (main_n > cv_n0) ? cv_n0 : main_n;
        }
    }
    return n;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001ecc0
CRIMVEASY_SAFEBUFFERS CriUint32 CriMvEasyPlayer::crimveasy_GetWave16(CriMvEasyPlayer* mveasy, CriUint32 nch, CriSint16* sample[],
                                              CriUint32 nsmpl)
{
    CriSint32 stat;
    CriBool main_end2;
    CriSint16* cvbuf;
    CriUint64 cv_time2;     // unused, keeps the exe stack slots
    CriUint64 time3;
    CriUint32 availb;
    CriBool cv_end0;
    CriUint32 src_2;
    CriSint16* buf2[8];
    CriUint32 i;
    CriUint32 nsmpl_out_;

    nsmpl_out_ = 0;
    main_end2 = 1;
    cv_end0 = 1;
    if (mveasy == NULL)
    {
        return 0;
    }
    if (mveasy->sound == NULL)
    {
        return 0;
    }
    if (mveasy->stmprm.track_play_audio == -1)
    {
        return 0;
    }
    stat = criMvPly_GetStatus(mveasy->mvply);
    if (stat == 0 || stat == 1 || stat == 2)
    {
        return 0;
    }
    for (i = 0; i < 8; i++)
    {
        buf2[i] = NULL;
    }
    for (i = 0; i < nch; i++)
    {
        src_2 = i;
        if (mveasy->num_audio_channel != mveasy->unk3c8 && i >= mveasy->center_channel)
        {
            src_2 = i + 1;
            if (src_2 >= nch)
            {
                src_2 = i;
            }
        }
        buf2[i] = sample[src_2];
    }
    cvbuf = sample[mveasy->center_channel];
    main_end2 = FUN_140036140(mveasy->mvply);
    if (mveasy->attached_center_voice_track != -1)
    {
        cv_end0 = FUN_140036170(mveasy->mvply);
    }
    availb = crimveasy_CalcAvailableNumSmpls(mveasy);
    if (availb == 0)
    {
        return 0;
    }
    nsmpl = (nsmpl > availb) ? availb : nsmpl;
    if (main_end2 == 0)
    {
        nsmpl_out_ = FUN_140035f00(mveasy->mvply, mveasy->num_audio_channel, buf2, nsmpl, &time3);
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            if (buf2[i] != NULL)
            {
                memset(buf2[i], 0, nsmpl * sizeof(CriSint16));
            }
        }
    }
    if (mveasy->attached_center_voice_track != -1)
    {
        if (cv_end0 == 0)
        {
            nsmpl_out_ = FUN_140035fe0(mveasy->mvply, 1, &cvbuf, nsmpl, &time3);
        }
        else
        {
            memset(cvbuf, 0, nsmpl * sizeof(CriFloat32));
        }
    }
    else if (mveasy->num_audio_channel != mveasy->unk3c8)
    {
        memset(cvbuf, 0, nsmpl * sizeof(CriSint16));
    }
    return nsmpl_out_;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001f060
CRIMVEASY_SAFEBUFFERS CriUint32 CriMvEasyPlayer::crimveasy_GetWave32(CriMvEasyPlayer* mveasy, CriUint32 nch, CriFloat32* sample[],
                                              CriUint32 nsmpl)
{
    CriSint32 stat;
    CriBool main_end2;
    CriFloat32* cvbuf;
    CriUint64 cv_time2;     // unused, keeps the exe stack slots
    CriUint64 time3;
    CriUint32 availb;
    CriBool cv_end0;
    CriUint32 src_2;
    CriFloat32* buf2[8];
    CriUint32 i;
    CriUint32 nsmpl_out_;

    nsmpl_out_ = 0;
    main_end2 = 1;
    cv_end0 = 1;
    if (mveasy == NULL)
    {
        return 0;
    }
    if (mveasy->sound == NULL)
    {
        return 0;
    }
    if (mveasy->stmprm.track_play_audio == -1)
    {
        return 0;
    }
    stat = criMvPly_GetStatus(mveasy->mvply);
    if (stat == 0 || stat == 1 || stat == 2)
    {
        return 0;
    }
    for (i = 0; i < 8; i++)
    {
        buf2[i] = NULL;
    }
    for (i = 0; i < nch; i++)
    {
        src_2 = i;
        if (mveasy->num_audio_channel != mveasy->unk3c8 && i >= mveasy->center_channel)
        {
            src_2 = i + 1;
            if (src_2 >= nch)
            {
                src_2 = i;
            }
        }
        buf2[i] = sample[src_2];
    }
    cvbuf = sample[mveasy->center_channel];
    main_end2 = FUN_140036140(mveasy->mvply);
    if (mveasy->attached_center_voice_track != -1)
    {
        cv_end0 = FUN_140036170(mveasy->mvply);
    }
    availb = crimveasy_CalcAvailableNumSmpls(mveasy);
    if (availb == 0)
    {
        return 0;
    }
    nsmpl = (nsmpl > availb) ? availb : nsmpl;
    if (main_end2 == 0)
    {
        nsmpl_out_ = FUN_140035f70(mveasy->mvply, mveasy->num_audio_channel, buf2, nsmpl, &time3);
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            if (buf2[i] != NULL)
            {
                memset(buf2[i], 0, nsmpl * sizeof(CriFloat32));
            }
        }
    }
    if (mveasy->attached_center_voice_track != -1)
    {
        if (cv_end0 == 0)
        {
            nsmpl_out_ = FUN_140036050(mveasy->mvply, 1, &cvbuf, nsmpl, &time3);
        }
        else
        {
            memset(cvbuf, 0, nsmpl * sizeof(CriFloat32));
        }
    }
    else if (mveasy->num_audio_channel != mveasy->unk3c8)
    {
        memset(cvbuf, 0, nsmpl * sizeof(CriFloat32));
    }
    return nsmpl_out_;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001f400
CriUint32 CriMvEasyPlayer::crimveasy_SupplySubAudioDataByFloat32(void* obj, CriUint32 nch, CriFloat32* sample[],
                                                                CriUint32 nsmpl)
{
    CriUint32 i;
    CriUint32 n;
    CriMvEasyPlayer* mveasy = (CriMvEasyPlayer*)obj;
    if (mveasy == NULL)
    {
        return 0;
    }
    for (i = 0; i < nch; i++)
    {
        memset(sample[i], 0, nsmpl * sizeof(CriFloat32));
    }
    n = crimveasy_GetSubAudioWave32(mveasy, nch, sample, nsmpl);
    if (n == 0)
    {
        return 0;
    }
    return n;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001f4b0
CRIMVEASY_SAFEBUFFERS CriUint32 CriMvEasyPlayer::crimveasy_GetSubAudioWave32(CriMvEasyPlayer* mveasy, CriUint32 nch, CriFloat32* sample[],
                                                      CriUint32 nsmpl)
{
    CriSint32 stat6;
    CriUint32 sub_nch3;
    CriUint64 unused_;      // unused, keeps the exe stack slots
    CriUint64 time2;
    CriUint32 avail;
    CriUint32 src;
    CriFloat32* buf[8];
    CriUint32 i3;
    CriUint32 nsmpl_out;

    if (mveasy == NULL)
    {
        return 0;
    }
    if (mveasy->subaudio == NULL)
    {
        return 0;
    }
    if (mveasy->attached_subaudio_track == -1)
    {
        return 0;
    }
    stat6 = criMvPly_GetStatus(mveasy->mvply);
    if (stat6 == 0 || stat6 == 1 || stat6 == 2)
    {
        return 0;
    }
    sub_nch3 = mveasy->stmprm.audio_prm[mveasy->attached_subaudio_track].num_channel;
    if (sub_nch3 == 0)
    {
        return 0;
    }
    for (i3 = 0; i3 < nch; i3++)
    {
        src = i3;
        buf[i3] = sample[src];
    }
    avail = criMvPly_GetDataSizeSubAudio(mveasy->mvply, sub_nch3);
    if (nsmpl > avail)
    {
        nsmpl = avail;
    }
    if (nsmpl == 0)
    {
        return 0;
    }
    nsmpl_out = FUN_140036050(mveasy->mvply, sub_nch3, buf, nsmpl, &time2);
    return nsmpl_out;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001f660
CriUint32 CriMvEasyPlayer::crimveasy_SupplySubAudioDataBySint16(void* obj, CriUint32 nch, CriSint16* sample[],
                                                               CriUint32 nsmpl)
{
    CriUint32 i;
    CriUint32 n;
    CriMvEasyPlayer* mveasy = (CriMvEasyPlayer*)obj;
    if (mveasy == NULL)
    {
        return 0;
    }
    for (i = 0; i < nch; i++)
    {
        memset(sample[i], 0, nsmpl * sizeof(CriSint16));
    }
    n = crimveasy_GetSubAudioWave16(mveasy, nch, sample, nsmpl);
    if (n == 0)
    {
        return 0;
    }
    return n;
}

// The 16-bit sub audio path tests the main sound and track like the CRI build does.
// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001f700
CRIMVEASY_SAFEBUFFERS CriUint32 CriMvEasyPlayer::crimveasy_GetSubAudioWave16(CriMvEasyPlayer* mveasy, CriUint32 nch, CriSint16* sample[],
                                                      CriUint32 nsmpl)
{
    CriSint32 stat6;
    CriUint32 sub_nch3;
    CriUint64 unused_;      // unused, keeps the exe stack slots
    CriUint64 time2;
    CriUint32 avail;
    CriUint32 src;
    CriSint16* buf[8];
    CriUint32 i3;
    CriUint32 nsmpl_out;

    if (mveasy == NULL)
    {
        return 0;
    }
    if (mveasy->sound == NULL)
    {
        return 0;
    }
    if (mveasy->stmprm.track_play_audio == -1)
    {
        return 0;
    }
    stat6 = criMvPly_GetStatus(mveasy->mvply);
    if (stat6 == 0 || stat6 == 1 || stat6 == 2)
    {
        return 0;
    }
    sub_nch3 = mveasy->stmprm.audio_prm[mveasy->attached_subaudio_track].num_channel;
    if (sub_nch3 == 0)
    {
        return 0;
    }
    for (i3 = 0; i3 < nch; i3++)
    {
        src = i3;
        buf[i3] = sample[src];
    }
    avail = criMvPly_GetDataSizeSubAudio(mveasy->mvply, sub_nch3);
    if (nsmpl > avail)
    {
        nsmpl = avail;
    }
    if (nsmpl == 0)
    {
        return 0;
    }
    nsmpl_out = FUN_140035fe0(mveasy->mvply, sub_nch3, buf, nsmpl, &time2);
    return nsmpl_out;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001f8b0
void CriMvEasyPlayer::Update(CriError& err)
{
    err = CRIERR_OK;
    CriSint32 locked = criAtomic_TestAndSet((unsigned long *)&update_lock, 1);
    if (locked == 1)
    {
        return;
    }
    executeUpdate(err);
    criAtomic_TestAndSet((unsigned long *)&update_lock, 0);
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001f920
void CriMvEasyPlayer::executeUpdate(CriError& err)
{
    CriSint32 ply_status;
    if (error_flag != 1)
    {
        if (mvply->decoder_error == 1)
        {
            setNormalErrorStatus("E09031001M: Decoder core error.");
            error_flag = 1;
        }
        if (sound != NULL && stmprm.track_play_audio != -1)
        {
            if (sound->GetStatus() == CriMvSoundInterface::STATUS_ERROR)
            {
                setNormalErrorStatus("E09031002M: Sound Output module error.");
                error_flag = 1;
            }
        }
    }
    if (error_flag == 1)
    {
        ply_status = criMvPly_GetStatus(mvply);
        switch (ply_status)
        {
        case 6:
        case 9:
            if (isFileReaderIdle() == 0)
            {
                break;
            }
            executeFileCloseServer();
            if (detachOutputs() == 1)
            {
                completeStop(ply_status);
            }
            break;
        }
    }
    else
    {
        executeFileOpenServer();
        executeCuePointServer();
        updateStatus(err);
        supplyDataFromStreamer();
        reinputDataForLooping();
        FUN_14002fb70(mvply);
        executeFileReadServer();
        surveilTerminationInput();
        executeFileCloseServer();
        ply_status = criMvPly_GetStatus(mvply);
        if (ply_status == 1)
        {
            FUN_140031470(mvply);
        }
        status_after_stop = GetStatus();
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001fb00
void CriMvEasyPlayer::updateStatus(CriError& err)
{
    CriSint32 track_;
    CriUint64 count9;
    CriUint64 unit;
    CriFloat32 now;
    TimerType timer;
    CriFloat32 frame_end;
    CriSint32 ply_status2;

    ply_status2 = criMvPly_GetStatus(mvply);
    switch (ply_status2)
    {
    case 2:
        if (req_decode_header == 1)
        {
            // still waiting for the header request to complete
        }
        else
        {
            setupPlayback();
            if (error_flag == 1)
            {
                err = CRIERR_NG;
                break;
            }
            setupSeekPosition();
            FUN_140031100(mvply);
        }
        break;
    case 4:
        if (req_prepare == 1)
        {
            // still waiting for the prepare request to complete
        }
        else
        {
            unk724 = 1;
            FUN_140031100(mvply);
        }
        break;
    case 6:
        if (modules_stopped == 0)
        {
            timer = GetMasterTimer();
            if (timer == MVEASY_TIMER_SYSTEM || (timer == MVEASY_TIMER_AUDIO && stimer != NULL))
            {
                GetTime(count9, unit);
                frame_end = (CriFloat32)(frame_info.frame_id + 1) / (CriFloat32)frame_info.framerate * 1000.0f *
                            1000.0f;
                now = (CriFloat32)(count9 * 1000) / (CriFloat32)unit;
                if (frame_end > now)
                {
                    unk6f0 = 1;
                    break;
                }
            }
        }
    case 9:
        requestStopModules();
        if (isFileReaderIdle() == 0)
        {
            break;
        }
        if (detachOutputs() == 1)
        {
            completeStop(ply_status2);
        }
        break;
    case 5:
        if (unk650 == 1 && pause_flag == 0)
        {
            *(CriUint64*)playback_info = *(CriUint64*)playback_info + 1;
        }
        track_ = stmprm.track_play_audio;
        FUN_14002fbe0(mvply, &stmprm);
        if (mvply->num_audio_out > 0)
        {
            stmprm.track_play_audio = track_;
        }
        break;
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x14001fdc0
void CriMvEasyPlayer::setupSeekPosition(void)
{
    CriSint32 alpha_frame_id4;
    CriSint32 frame_id;
    CriUint64 offset;
    CriUint64 alpha_offset;

    if (mvply->seekinfo_flag == 0)
    {
        if (mvply->seek_mode == 3)
        {
            FUN_140037740(mvply, seek_frame_id, seek_frame_id);
            FUN_140037780(mvply, seek_frame_id);
        }
        else
        {
            seek_frame_id = 0;
            FUN_140037740(mvply, seek_frame_id, 0);
        }
    }
    else if (seek_offset == 0 && seek_frame_id <= 0)
    {
        seek_frame_id = 0;
        FUN_140037740(mvply, seek_frame_id, 0);
    }
    else if (seek_frame_id >= mvply->total_frames)
    {
        seek_frame_id = 0;
        seek_offset = 0;
        FUN_140037740(mvply, seek_frame_id, 0);
    }
    else if (seek_offset != 0)
    {
        freader->Seek(seek_offset + file_offset, CriMvFileReaderInterface::SEEK_FROM_BEGIN);
        file_read_pos = seek_offset;
        FUN_140037740(mvply, seek_frame_id, seek_frame_id);
    }
    else
    {
        frame_id = 0;
        offset = 0;
        alpha_frame_id4 = 0;
        alpha_offset = 0;
        seek_offset = 0;
        FUN_140033700(mvply, mvply->seektbl, mvply->num_seektbl, seek_frame_id, (void **)&offset, &frame_id);
        seek_offset = offset;
        if (mvply->seektbl_alpha != NULL)
        {
            FUN_140033700(mvply, mvply->seektbl_alpha, mvply->num_seektbl_alpha, seek_frame_id, (void **)&alpha_offset,
                          &alpha_frame_id4);
            if (alpha_offset < offset)
            {
                seek_offset = alpha_offset;
            }
        }
        if (frame_id > 0 || alpha_frame_id4 > 0)
        {
            freader->Seek(seek_offset + file_offset, CriMvFileReaderInterface::SEEK_FROM_BEGIN);
            file_read_pos = seek_offset;
        }
        FUN_140037740(mvply, seek_frame_id, frame_id);
        FUN_140037780(mvply, alpha_frame_id4);
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140020140
CRIMVEASY_SAFEBUFFERS CriBool CriMvEasyPlayer::setupPlayback(void)
{
    CriUint32 sub_rate3;
    CriMvSoundInterface::PcmFormat sub_fmtLo;
    CriUint32 sub_nch;
    CriUint32 rest;
    CriUint32 rate9;
    CriMvSoundInterface::PcmFormat fmt;
    CriBool use_heap2;
    CriSint32 ply_work_size9;
    CriMvWorkAllocator walloc;
    void* ply_work;

    if (stmprm_flag != 1)
    {
        GetHeaderInfo(&stmprm);
    }
    if (stmprm.is_playable == 0)
    {
        setNormalErrorStatus("E08020501M: This movie is not playable on this platform.");
        return 0;
    }
    use_heap2 = (heap != NULL) ? 1 : 0;
    memset(&walloc, 0, sizeof(walloc));
    if (use_heap2 == 0)
    {
        criFixedAllocator_Create(playback_work, playback_work_size, (CriFixedAllocator *)&walloc);
    }
    stmprm.channel_play_subtitle = subtitle_channel;
    if (stmprm.max_subtitle_size > 0)
    {
        if (use_heap2 == 1)
        {
            subtitle_buf = (CriUint8*)criHeap_AllocFix(heap, stmprm.max_subtitle_size, "CriMvEasy: SubtitleBuffer", 4);
        }
        else
        {
            subtitle_buf = (CriUint8*)criFixedAllocator_Allocate((CriFixedAllocator *)&walloc, stmprm.max_subtitle_size, 4);
        }
        if (subtitle_buf == NULL)
        {
            setNormalErrorStatus("E07020101M: Failed allocate subtitle buffer.");
            return 0;
        }
    }
    if (use_heap2 == 0)
    {
        ply_work_size9 = FUN_140037400(mvply, &stmprm);
        ply_work = criFixedAllocator_Allocate((CriFixedAllocator *)&walloc, ply_work_size9, 4);
        if (criMvPly_AllocateWorkBufferWithWork(mvply, ply_work, ply_work_size9, &stmprm) != 1)
        {
            setNormalErrorStatus("E10052101M: Failed criMvPly_AllocateWorkBufferWithWork().");
            return 0;
        }
    }
    else if (criMvPly_AllocateWorkBuffer(mvply, heap, &stmprm) != 1)
    {
        setNormalErrorStatus("E07020201M: Failed criMvPly_AllocateWorkBuffer().");
        return 0;
    }
    if (stmprm.track_play_audio != -1 && sound != NULL)
    {
        if (use_heap2 == 0)
        {
            rest = walloc.size - (CriUint32)(walloc.cur - walloc.top);
            sound_heap = criHeap_Create(walloc.cur, rest);
        }
        else
        {
            sound_heap = heap;
        }
        num_audio_channel = stmprm.audio_prm[stmprm.track_play_audio].num_channel;
        unk3c8 = adjustNumTrackAudioOut();
        rate9 = stmprm.audio_prm[stmprm.track_play_audio].sampling_rate;
        if (sound->CreateOutput(sound_heap, unk3c8, rate9) == 0)
        {
            setNormalErrorStatus("E07020102M: Failed create SoundOutput.");
            return 0;
        }
        fmt = sound->GetPcmFormat();
        if (fmt == CriMvSoundInterface::PCM_FORMAT_FLOAT32)
        {
            sound->SetCallbackGetFloat32PcmData(crimveasy_SupplyPcmDataByFloat32, this);
        }
        else
        {
            sound->SetCallbackGetSint16PcmData(crimveasy_SupplyPcmDataBySint16, this);
        }
        if (isAvailableCenterVoice(&stmprm) == 1 && attachCenterVoice() != 1)
        {
            setNormalErrorStatus("E07020202M: Failed attach Center Voice.");
            return 0;
        }
        if (isAvailableSubAudio(&stmprm) == 1)
        {
            if (attachSubAudioHandle(sound_heap) != 1)
            {
                setNormalErrorStatus("E08012401M: Failed attach SubAudio handle.");
                return 0;
            }
            sub_nch = stmprm.audio_prm[subaudio_track].num_channel;
            sub_rate3 = stmprm.audio_prm[subaudio_track].sampling_rate;
            if (subaudio->CreateOutput(sound_heap, sub_nch, sub_rate3) == 0)
            {
                setNormalErrorStatus("E08012402M: Failed create SoundOutput.");
                return 0;
            }
            sub_fmtLo = subaudio->GetPcmFormat();
            if (sub_fmtLo == CriMvSoundInterface::PCM_FORMAT_FLOAT32)
            {
                subaudio->SetCallbackGetFloat32PcmData(crimveasy_SupplySubAudioDataByFloat32, this);
            }
            else
            {
                subaudio->SetCallbackGetSint16PcmData(crimveasy_SupplySubAudioDataBySint16, this);
            }
        }
    }
    return 1;
}

// @0x140020790
CriUint32 CriMvEasyPlayer::adjustNumTrackAudioOut(void)
{
    CriUint32 num;
    if (num_audio_channel == 5)
    {
        num = 6;
    }
    else if (num_audio_channel == 7)
    {
        num = 8;
    }
    else
    {
        num = num_audio_channel;
    }
    return num;
}

// @0x1400207f0
void CriMvEasyPlayer::startModules(void)
{
    if (stimer != NULL)
    {
        stimer->Start();
    }
    if (stmprm.num_audio > 0 && stmprm.track_play_audio != -1 && sound != NULL)
    {
        sound->Start();
    }
    if (stmprm.num_audio > 0 && attached_subaudio_track != -1 && subaudio != NULL)
    {
        subaudio->Start();
    }
}

// @0x1400208c0
void CriMvEasyPlayer::requestStopModules(void)
{
    if (modules_stopped == 1)
    {
        return;
    }
    if (stimer != NULL)
    {
        stimer->Stop();
    }
    if (sound != NULL && stmprm.track_play_audio != -1)
    {
        sound->Stop();
    }
    if (subaudio != NULL && attached_subaudio_track != -1)
    {
        subaudio->Stop();
    }
    modules_stopped = 1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x1400209a0
CriBool CriMvEasyPlayer::isFileReaderIdle(void)
{
    CriBool idle = 1;

    if (freader != NULL && data_type == 1)
    {
        CriMvFileReaderInterface::AsyncStatus open_status = freader->GetOpenStatus();
        if (file_opened == 1 && open_status == CriMvFileReaderInterface::ASYNC_STATUS_COMPLETE)
        {
            CriMvFileReaderInterface::AsyncStatus read_status = freader->GetReadStatus();
            if (file_reading == 0 || read_status == CriMvFileReaderInterface::ASYNC_STATUS_COMPLETE)
            {
                if (file_closing != 1)
                {
                    unk4c0 = 5;
                    freader->Close();
                    file_closing = 1;
                }
            }
            else
            {
                idle = 0;
                unk6f0 = 4;
            }
        }
        else if (unk4c0 == 1)
        {
            unk4c0 = 0;
        }
    }
    return idle;
}

// @0x140020ae0
CriBool CriMvEasyPlayer::detachOutputs(void)
{
    if (sound != NULL && stmprm.track_play_audio != -1)
    {
        CriMvSoundInterface::Status sound_status = sound->GetStatus();
        if (sound_status == CriMvSoundInterface::STATUS_STOP || sound_status == CriMvSoundInterface::STATUS_ERROR)
        {
            sound->SetCallbackGetFloat32PcmData(NULL, NULL);
            sound->SetCallbackGetSint16PcmData(NULL, NULL);
        }
        else
        {
            unk6f0 = 2;
            return 0;
        }
    }
    if (subaudio != NULL && attached_subaudio_track != -1)
    {
        CriMvSoundInterface::Status sub_status = subaudio->GetStatus();
        if (sub_status == CriMvSoundInterface::STATUS_STOP || sub_status == CriMvSoundInterface::STATUS_ERROR)
        {
            subaudio->SetCallbackGetFloat32PcmData(NULL, NULL);
            subaudio->SetCallbackGetSint16PcmData(NULL, NULL);
        }
        else
        {
            unk6f0 = 3;
            return 0;
        }
    }
    if (freader != NULL && data_type == 1 && (file_opened == 1 || file_closing == 1))
    {
        CriMvFileReaderInterface::AsyncStatus close_status = freader->GetCloseStatus();
        if (close_status == CriMvFileReaderInterface::ASYNC_STATUS_COMPLETE)
        {
            file_closing = 0;
            file_opened = 0;
            file_read_pos = 0;
            file_read_end = -1;
            if (modules_stopped == 1)
            {
                unk4c0 = 0;
            }
            else
            {
                unk4c0 = 1;
            }
        }
        else if (close_status == CriMvFileReaderInterface::ASYNC_STATUS_ERROR)
        {
            file_closing = 0;
            file_opened = 0;
            file_read_pos = 0;
            file_read_end = -1;
            notifyErrorB(this, "E07012302M: File Close Error", 0);
        }
        else
        {
            unk6f0 = 5;
            return 0;
        }
    }
    return 1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140020db0
void CriMvEasyPlayer::completeStop(CriSint32 ply_status)
{
    CriSint32 locked;
    locked = criAtomic_TestAndSet((unsigned long *)&destroy_lock, 1);
    if (locked == 0)
    {
        modules_stopped = 0;
        releasePlaybackResources();
        if (ply_status == 6)
        {
            resetHandleParameters();
        }
        pause_flag = 0;
        FUN_140031100(mvply);
        if (error_flag == 1)
        {
            error_flag = 0;
        }
        unk6f0 = 0;
        if (stopcmpl_func != NULL)
        {
            stopcmpl_func(this, stopcmpl_usrobj);
        }
        criAtomic_TestAndSet((unsigned long *)&destroy_lock, 0);
    }
    else
    {
        unk6f0 = 6;
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140020eb0
void CriMvEasyPlayer::releasePlaybackResources(void)
{
    CriBool use_heap;
    use_heap = (heap != NULL) ? 1 : 0;
    if (subtitle_buf != NULL)
    {
        if (use_heap == 1)
        {
            criHeap_Free(heap, subtitle_buf);
        }
        subtitle_buf = NULL;
    }
    if (sound != NULL)
    {
        sound->DestroyOutput();
    }
    if (subaudio != NULL)
    {
        subaudio->DestroyOutput();
    }
    detachCenterVoice();
    detachSubAudioHandle();
    if (use_heap == 0 && sound_heap != NULL)
    {
        criHeap_Destroy(sound_heap);
        sound_heap = NULL;
    }
    FUN_140030c70(mvply);
    num_audio_channel = 0;
    unk3c8 = 0;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, uint64/float conversion sequence)
// @0x140021000
void CriMvEasyPlayer::SyncMasterTimer(CriError& err)
{
    CriUint64 count3;
    CriUint64 sys_unit;
    CriUint64 unit4;
    CriUint64 sys_count;
    TimerType timer;
    Status status6;

    count3 = 0;
    unit4 = 1;
    sys_count = 0;
    sys_unit = 1;
    err = CRIERR_OK;
    if (unk724 == 1 && pause_flag == 0)
    {
        startModules();
        unk724 = 0;
    }
    status6 = GetStatus();
    if (status6 == MVEASY_STATUS_STOP || status6 == MVEASY_STATUS_PLAYEND || status6 == MVEASY_STATUS_ERROR ||
        modules_stopped == 1)
    {
        return;
    }
    if (stimer != NULL)
    {
        stimer->GetTime(sys_count, sys_unit);
    }
    timer = GetMasterTimer();
    switch (timer)
    {
    case MVEASY_TIMER_AUDIO:
        calcAudioTime(&count3, &unit4, sys_count, sys_unit);
        user_time_count = count3;
        user_time_unit = unit4;
        break;
    case MVEASY_TIMER_SYSTEM:
        user_time_count = sys_count;
        user_time_unit = sys_unit;
        break;
    default:
        user_time_count = 0;
        user_time_unit = 1;
        break;
    }
    time0_count = sys_count;
    time0_unit = sys_unit;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, uint64/float conversion sequence)
// @0x1400211d0
void CriMvEasyPlayer::calcAudioTime(CriUint64* count, CriUint64* unit, CriUint64 sys_count, CriUint64 sys_unit)
{
    CriBool extrapolate;
    CriUint64 extra3;
    CriUint64 snd_unitVal;
    CriMvSoundInterface::Status status_;
    CriUint64 snd_count;
    CriFloat32 elapsedVal;

    snd_count = 0;
    snd_unitVal = 1;
    extrapolate = 0;
    status_ = sound->GetStatus();
    if (status_ == CriMvSoundInterface::STATUS_STOP)
    {
        user_time_count = time2_count;
        user_time_unit = time2_unit;
        return;
    }
    sound->GetTime(snd_count, snd_unitVal);
    extra3 = 0;
    if (criMvPly_GetStatus(mvply) == 5 && FUN_140036140(mvply) == 1)
    {
        extrapolate = 1;
    }
    else if (criMvPly_GetStatus(mvply) == 6)
    {
        extrapolate = 1;
    }
    if (extrapolate != 0 && snd_count == time2_count && stimer != NULL)
    {
        if (time1_count == 0)
        {
            time1_count = time0_count;
            time1_unit = time0_unit;
        }
        elapsedVal = (CriFloat32)(sys_count - time1_count) / (CriFloat32)time1_unit;
        extra3 = (CriUint64)(elapsedVal * (CriFloat32)snd_unitVal);
    }
    *count = snd_count + extra3;
    *unit = snd_unitVal;
    time2_count = snd_count;
    time2_unit = snd_unitVal;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, uint64/float conversion sequence)
// @0x140021450
CriBool CriMvEasyPlayer::ExecuteDecode(CriError& err)
{
    CriBool res = 1;
    CriSint32 locked;
    Status status;

    err = CRIERR_OK;
    status = GetStatus();
    if (status == MVEASY_STATUS_STOP || status == MVEASY_STATUS_PLAYEND)
    {
        res = 0;
    }
    locked = criAtomic_TestAndSet((unsigned long *)&destroy_lock, 1);
    if (locked == 1)
    {
        return res;
    }
    FUN_140039f50((_RTL_CRITICAL_SECTION *)cs);
    if (mvply != NULL)
    {
        FUN_140031250(mvply);
        FUN_1400313d0(mvply);
    }
    FUN_140039f8c((_RTL_CRITICAL_SECTION *)cs);
    criAtomic_TestAndSet((unsigned long *)&destroy_lock, 0);
    return res;
}

// @0x140021530
void CriMvEasyPlayer::SetFile(CriChar8* fname, CriError& err)
{
    err = CRIERR_OK;
    SetFileRange(fname, 0, -1);
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order)
// @0x140021580
void CriMvEasyPlayer::SetData(CriUint8* dataptr, CriUint32 datasize, CriError& err)
{
    CriUint32 filesize_;
    void* node0;
    void* hdr;
    CriUint32 hdr_size0;

    err = CRIERR_OK;
    if (*dataptr == 'C' && *(dataptr + 1) == 'R' && *(dataptr + 2) == 'I' && *(dataptr + 3) == 'D')
    {
        hdr = (void*)criUsfCmn_GetContents(dataptr, datasize, (long *)&hdr_size0);
        node0 = criUtfRtv_Create(mvply->utf_heap, hdr, hdr_size0);
        filesize_ = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView *)node0, 0, "filesize");
        criUtfRtv_Destroy((unsigned __int64 *)node0);
        if (datasize > filesize_)
        {
            datasize = filesize_;
        }
    }
    unk4a0 = 2;
    if (memory_playback_type == 1 || mvply->unkda0 == NULL)
    {
        data_type = 1;
        sprintf_s(fname, 0x100, "MFS:%016X.%016X", dataptr, datasize);
    }
    else
    {
        data_type = 2;
        data_ptr = dataptr;
        data_size = datasize;
        memset(fname, 0, 0x100);
    }
    file_request_state = 1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order)
// @0x140021720
void CriMvEasyPlayer::SetFileRange(CriChar8* fname, CriUint64 offset, CriSint64 range, CriError& err)
{
    CriSint32 len;
    err = CRIERR_OK;
    if (freader != NULL)
    {
        unk4a0 = 1;
        data_type = 1;
        len = (CriSint32)strlen(fname);
        if (len > 0x100)
        {
            len = 0xff;
        }
        memset(this->fname, 0, 0x100);
        memcpy(this->fname, fname, len);
        file_offset = offset;
        file_range = range;
        file_request_state = 1;
        data_ptr = NULL;
        data_size = 0;
    }
    else
    {
        setErrorMessage("E09031801M: File name could be set to the EasyPlayer without FileReaderInterface.",
                        this->fname);
        err = CRIERR_NG;
    }
}

// @0x140021850
void CriMvEasyPlayer::SetPreviousDataAgain(CriError& err)
{
    if (data_type == 0)
    {
        err = CRIERR_NG;
        setErrorMessage("E10112201M: Movie data was not set yet.", NULL);
        setNormalErrorStatus(DAT_143b277c0);
        return;
    }
    err = CRIERR_OK;
    file_request_state = 1;
}

// @0x1400218d0
void CriMvEasyPlayer::DecodeHeader(CriError& err)
{
    err = CRIERR_OK;
    req_decode_header = 1;
    CriBool ok = startInputAndDecoding();
    if (ok == 0)
    {
        err = CRIERR_NG;
    }
}

// @0x140021930
void CriMvEasyPlayer::Prepare(CriError& err)
{
    err = CRIERR_OK;
    req_prepare = 1;
    if (req_decode_header == 1)
    {
        req_decode_header = 0;
        return;
    }
    CriBool ok = startInputAndDecoding();
    if (ok == 0)
    {
        err = CRIERR_NG;
    }
}

// @0x1400219b0
void CriMvEasyPlayer::Start(CriError& err)
{
    err = CRIERR_OK;
    if (req_prepare == 1 || req_decode_header == 1)
    {
        req_decode_header = 0;
        req_prepare = 0;
        return;
    }
    CriBool ok = startInputAndDecoding();
    if (ok == 0)
    {
        err = CRIERR_NG;
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice for int stores, stack slot order, float conversion sequence)
// @0x140021a30
CriBool CriMvEasyPlayer::startInputAndDecoding(void)
{
    CriBool ok;
    unk5e4 = 0;
    modules_stopped = 0;
    unk724 = 0;
    user_time_count = 0;
    user_time_unit = 1;
    memset(&subtitle_info, 0, sizeof(subtitle_info));
    subtitle_start_ms = 0.0f;
    subtitle_end_ms = 0.0f;
    if (file_request_state == 0 && filereq_func != NULL)
    {
        filereq_func(this, filereq_usrobj);
    }
    if (file_request_state == 0)
    {
        setErrorMessage("E09031805M: Movie data was not set.", " ");
        setNormalErrorStatus(DAT_143b277c0);
        return 0;
    }
    if (data_type == 2)
    {
        FUN_1400361a0(mvply, data_ptr, data_size);
    }
    else if (data_type == 1)
    {
        unk4c4 = 1;
        unk4c0 = 1;
        ok = FUN_140034920(mvply);
        if (ok == 0)
        {
            return 0;
        }
    }
    status_after_stop = GetStatus();
    return 1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140021bf0
void CriMvEasyPlayer::Stop(CriError& err)
{
    err = CRIERR_OK;
    if (error_flag == 1)
    {
        CriSint32 plystat = criMvPly_GetStatus(mvply);
        if (plystat == 0 || plystat == 7)
        {
            error_flag = 0;
        }
    }
    if (GetStatus() != MVEASY_STATUS_STOP)
    {
        requestStopModules();
        FUN_140034b20(mvply);
    }
    resetHandleParameters();
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140021c90
void CriMvEasyPlayer::Pause(CriBool sw, CriError& err)
{
    err = CRIERR_OK;
    pause_flag = sw;
    if (stimer != NULL)
    {
        stimer->Pause(sw);
    }
    if (stmprm.track_play_audio != -1 && sound != NULL)
    {
        sound->Pause(sw);
    }
    if (subaudio != NULL)
    {
        subaudio->Pause(sw);
    }
}

// @0x140021d70
CriBool CriMvEasyPlayer::IsPaused(CriError& err)
{
    err = CRIERR_OK;
    return pause_flag;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140021da0
void CriMvEasyPlayer::SetMasterTimer(TimerType type, CriError& err)
{
    err = CRIERR_OK;
    timer_type = type;
}

// @0x140021dd0
CriMvEasyPlayer::TimerType CriMvEasyPlayer::GetMasterTimer(CriError& err)
{
    TimerType type;
    err = CRIERR_OK;
    switch (timer_type)
    {
    case MVEASY_TIMER_NONE:
        type = MVEASY_TIMER_NONE;
        break;
    case MVEASY_TIMER_AUDIO:
        if (GetStatus() == MVEASY_STATUS_STOP || GetStatus() == MVEASY_STATUS_DECHDR)
        {
            type = MVEASY_TIMER_AUDIO;
        }
        else if (stmprm.num_audio > 0 && stmprm.track_play_audio != -1 && sound != NULL)
        {
            type = MVEASY_TIMER_AUDIO;
        }
        else
        {
            type = MVEASY_TIMER_SYSTEM;
        }
        break;
    default:
        if (stimer != NULL)
        {
            type = MVEASY_TIMER_SYSTEM;
        }
        else
        {
            type = MVEASY_TIMER_NONE;
        }
        break;
    }
    if (type == MVEASY_TIMER_AUDIO && sound == NULL)
    {
        type = MVEASY_TIMER_SYSTEM;
    }
    if (type == MVEASY_TIMER_SYSTEM && stimer == NULL)
    {
        type = MVEASY_TIMER_NONE;
    }
    return type;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140021ef0
void CriMvEasyPlayer::SetNumberOfFramePools(CriUint32 npools, CriError& err)
{
    err = CRIERR_OK;
    num_frame_pools = npools;
}

// @0x140021f20
void CriMvEasyPlayer::SetBufferingTime(CriFloat32 sec, CriError& err)
{
    err = CRIERR_OK;
    buffering_time = sec;
}

// @0x140021f60
void CriMvEasyPlayer::SetReloadThresholdTime(CriFloat32 sec, CriError& err)
{
    err = CRIERR_OK;
    mvply->reload_threshold = sec;
}

// @0x140021fa0
void CriMvEasyPlayer::GetInputBufferInfo(CriMvInputBufferInfo& ibuf_info, CriError& err)
{
    err = CRIERR_OK;
    ibuf_info.buffer_size = mvply->ibuf_info.buffer_size;
    ibuf_info.data_size = mvply->ibuf_info.data_size;
    ibuf_info.reload_threshold = mvply->ibuf_info.reload_threshold;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice for int stores, stack slot order, float conversion sequence)
// @0x140022010
void CriMvEasyPlayer::SetMaxBitrate(CriUint32 max_bitrate, CriError& err)
{
    err = CRIERR_OK;
    this->max_bitrate = max_bitrate;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice for int stores, stack slot order, float conversion sequence)
// @0x140022040
void CriMvEasyPlayer::SetMaxChunkSize(CriUint32 max_chunk_size, CriError& err)
{
    err = CRIERR_OK;
    this->max_chunk_size = max_chunk_size;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice for int stores, stack slot order, float conversion sequence)
// @0x140022070
void CriMvEasyPlayer::SetMinBufferSize(CriUint32 min_buffer_size, CriError& err)
{
    err = CRIERR_OK;
    this->min_buffer_size = min_buffer_size;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice for int stores, stack slot order, float conversion sequence)
// @0x1400220a0
void CriMvEasyPlayer::SetReadBufferSize(CriSint32 size, CriError& err)
{
    err = CRIERR_OK;
    read_buffer_size = size;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x1400220d0
void CriMvEasyPlayer::SetAudioTrack(CriSint32 track, CriError& err)
{
    err = CRIERR_OK;
    if (sound == NULL)
    {
        return;
    }
    audio_track = track;
    criMvPly_SetAudioTrack(mvply, track);
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140022130
void CriMvEasyPlayer::SetLoopFlag(CriBool flag, CriError& err)
{
    err = CRIERR_OK;
    loop_flag = flag;
}

// @0x140022160
CriBool CriMvEasyPlayer::GetLoopFlag(CriError& err)
{
    err = CRIERR_OK;
    return loop_flag;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice for int stores, stack slot order, float conversion sequence)
// @0x140022190
void CriMvEasyPlayer::GetTime(CriUint64& count, CriUint64& unit, CriError& err)
{
    Status statusVal;
    CriFloat32 seek_timeVal;
    TimerType timer;
    CriUint64 seek_count;
    CriUint32 framerate_;
    CriFloat32 frame_sec2;

    err = CRIERR_OK;
    count = user_time_count;
    unit = user_time_unit;
    statusVal = GetStatus();
    if (statusVal == MVEASY_STATUS_PLAYING && seek_frame_id > 0)
    {
        framerate_ = stmprm.video_prm[0].framerate;
        seek_timeVal = (CriFloat32)seek_frame_id * 1000.0f / (CriFloat32)framerate_;
        timer = GetMasterTimer();
        if (timer == MVEASY_TIMER_AUDIO)
        {
            frame_sec2 = 0.0333667f;
            seek_timeVal = (seek_timeVal + frame_sec2) / frame_sec2 * frame_sec2;
        }
        seek_count = (CriUint64)(seek_timeVal * (CriFloat32)unit);
        count = count + seek_count;
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order)
// @0x140022310
CriBool CriMvEasyPlayer::GetHeaderInfo(CriMvStreamingParameters* stmprm, CriError& err)
{
    CriBool ok;
    ok = GetMovieInfo(*stmprm, err);
    if (ok == 0)
    {
        return ok;
    }
    if (max_bitrate > 0 && max_bitrate > stmprm->max_bitrate)
    {
        stmprm->max_bitrate = max_bitrate;
    }
    if (max_chunk_size > 0 && max_chunk_size > stmprm->max_chunk_size)
    {
        stmprm->max_chunk_size = max_chunk_size;
    }
    if (min_buffer_size > 0 && min_buffer_size > stmprm->min_buffer_size)
    {
        stmprm->min_buffer_size = min_buffer_size;
    }
    if (read_buffer_size != -1)
    {
        stmprm->read_buffer_size = read_buffer_size;
    }
    return ok;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order)
// @0x140022420
CriBool CriMvEasyPlayer::GetMovieInfo(CriMvStreamingParameters& stmprm, CriError& err)
{
    CriSint32 ply_status;
    err = CRIERR_OK;
    ply_status = criMvPly_GetStatus(mvply);
    switch (ply_status)
    {
    case 0:
    case 1:
    case 10:
        return 0;
    }
    if (mvply->decoder_error == 1)
    {
        return 0;
    }
    FUN_14002fbe0(mvply, &stmprm);
    if (buffering_time > 0.0f)
    {
        stmprm.buffering_time = buffering_time;
    }
    else
    {
        stmprm.buffering_time = 1.0f * (CriFloat32)DAT_143b278c8;
    }
    stmprm.video_prm[0].num_frame_pools = num_frame_pools;
    if (sound == NULL)
    {
        stmprm.track_play_audio = -1;
    }
    return 1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140022540
void CriMvEasyPlayer::SetStreamingParameters(CriMvStreamingParameters* stmprm, CriError& err)
{
    err = CRIERR_OK;
    this->stmprm = *stmprm;
    stmprm_flag = 1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x1400225b0
void CriMvEasyPlayer::SetSubtitleChannel(CriSint32 channel, CriError& err)
{
    err = CRIERR_OK;
    subtitle_channel = channel;
    if (channel == -1 && mvply != NULL)
    {
        criMvPly_SetSubtitleChannel(mvply, -1);
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, dead jumps after returns)
// @0x140022610
CriUint32 CriMvEasyPlayer::GetSubtitleOnTime(CriUint8* bufptr, CriUint32 bufsize, CriError& err)
{
    CriUint64 unit;
    CriFloat32 end_ms;
    TimerType ttype;
    CriUint64 count;
    CriFloat32 start_ms9;
    CriUint32 sizec = 0;
    CriFloat32 now_ms7;
    CriMvSubtitleInfo infoc;
    if (subtitle_buf == NULL && criMvPly_GetStatus(mvply) == 5 && stmprm.num_subtitle > 0)
    {
        setNormalErrorStatus("E09092901M: Internal subtitle buffer is not allocated. "
                             "Check if CriMvStreamingParameters::max_subtitle_size is adequate size.");
    }
    if (subtitle_buf == NULL)
    {
        return 0;
    }
    if (GetStatus() != MVEASY_STATUS_PLAYING)
    {
        return 0;
    }
    if (unk724 == 1)
    {
        return 0;
    }
    err = CRIERR_OK;
    if (bufptr != NULL)
    {
        memset(bufptr, 0, bufsize);
    }
    if (mvply != NULL)
    {
        criMvPly_SetSubtitleChannel(mvply, subtitle_channel);
    }
    ttype = GetMasterTimer();
    GetTime(count, unit, err);
    now_ms7 = (CriFloat32)count * 1000.0f / (CriFloat32)unit;
    if (ttype == MVEASY_TIMER_NONE)
    {
        criMvPly_GetNextSubtitleInfo(mvply, &infoc);
        if (infoc.dataptr != NULL)
        {
            criMvPly_GetSubtitle(mvply, subtitle_buf, stmprm.max_subtitle_size, &subtitle_info);
            subtitle_start_ms = (CriFloat32)infoc.in_time * 1000.0f / (CriFloat32)infoc.time_unit;
            subtitle_end_ms = (CriFloat32)(infoc.in_time + infoc.duration_time) * 1000.0f / (CriFloat32)infoc.time_unit;
            sizec = (bufsize < subtitle_info.data_size) ? bufsize : subtitle_info.data_size;
            memcpy(bufptr, subtitle_buf, sizec);
            return sizec;
        }
        else if (subtitle_info.dataptr != NULL && subtitle_info.channel_no == subtitle_channel)
        {
            sizec = (bufsize < subtitle_info.data_size) ? bufsize : subtitle_info.data_size;
            memcpy(bufptr, subtitle_buf, sizec);
            return sizec;
        }
        else
        {
            subtitle_info = infoc;
            memset(bufptr, 0, bufsize);
            return 0;
        }
    }
    if (subtitle_info.dataptr != NULL && subtitle_info.channel_no == subtitle_channel
        && now_ms7 >= subtitle_start_ms && subtitle_end_ms > now_ms7)
    {
        sizec = (bufsize < subtitle_info.data_size) ? bufsize : subtitle_info.data_size;
        memcpy(bufptr, subtitle_buf, sizec);
        return sizec;
    }
    criMvPly_GetNextSubtitleInfo(mvply, &infoc);
    if (infoc.dataptr == NULL)
    {
        subtitle_info = infoc;
        memset(bufptr, 0, bufsize);
        return 0;
    }
    start_ms9 = (CriFloat32)infoc.in_time * 1000.0f / (CriFloat32)infoc.time_unit;
    end_ms = (CriFloat32)(infoc.in_time + infoc.duration_time) * 1000.0f / (CriFloat32)infoc.time_unit;
    if (now_ms7 >= start_ms9)
    {
        criMvPly_GetSubtitle(mvply, subtitle_buf, stmprm.max_subtitle_size, &subtitle_info);
        subtitle_start_ms = start_ms9;
        subtitle_end_ms = end_ms;
        sizec = (bufsize < subtitle_info.data_size) ? bufsize : subtitle_info.data_size;
        memcpy(bufptr, subtitle_buf, sizec);
    }
    else
    {
        memset(bufptr, 0, bufsize);
        sizec = 0;
    }
    return sizec;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, vcall operand order)
// @0x140022d00
void CriMvEasyPlayer::supplyDataFromStreamer(void)
{
    CriMvFileReaderInterface::AsyncStatus rstat;
    CriSint64 rsize;
    if (mvply == NULL || freader == NULL)
    {
        return;
    }
    if (data_type != 1)
    {
        return;
    }
    if (isEndReadFile() == 1)
    {
        return;
    }
    if (file_reading == 1)
    {
        rstat = freader->GetReadStatus();
        if (rstat == CriMvFileReaderInterface::ASYNC_STATUS_COMPLETE)
        {
            rsize = freader->GetReadSize();
            file_read_pos += rsize;
            file_reading = 0;
            FUN_140034e70(mvply, (const CriMovieInputChunk *)&readck, (CriUint32)rsize);
            if (isEndReadFile() == 1)
            {
                return;
            }
        }
        else if (rstat == CriMvFileReaderInterface::ASYNC_STATUS_ERROR)
        {
            file_reading = 0;
            if (readck.data != NULL)
            {
                FUN_140034e70(mvply, (const CriMovieInputChunk *)&readck, 0);
                readck.data = NULL;
            }
            if (error_flag != 1)
            {
                setErrorMessage("E07020601M: File Open Error - ", fname);
                setNormalErrorStatus(DAT_143b277c0);
            }
            notifyErrorB(this, "E07012301M: Read Error", 0);
            return;
        }
        else if (file_opened == 0 && file_closing == 0)
        {
            file_reading = 0;
            FUN_140034e70(mvply, (const CriMovieInputChunk *)&readck, 0);
        }
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, vcall operand order)
// @0x140022f20
void CriMvEasyPlayer::executeFileReadServer(void)
{
    CriSint64 req_size;
    CriSint64 remain;
    if (mvply == NULL || freader == NULL)
    {
        return;
    }
    if (data_type != 1)
    {
        return;
    }
    if (isEndReadFile() == 1)
    {
        return;
    }
    if (file_reading == 1 || error_flag == 1)
    {
        return;
    }
    if (unk4c0 == 3 && mvply->ibuf_info.data_size <= mvply->ibuf_info.reload_threshold)
    {
        FUN_140034d40(mvply, (CriMovieInputChunk *)&readck);
        req_size = readck.size;
        if (req_size > 0)
        {
            remain = file_read_end - file_read_pos;
            if (req_size > remain)
            {
                req_size = remain;
            }
            freader->Read(readck.data, req_size);
            file_reading = 1;
        }
        else
        {
            FUN_140034e70(mvply, (const CriMovieInputChunk *)&readck, 0);
        }
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, vcall operand order)
// @0x1400230a0
void CriMvEasyPlayer::reinputDataForLooping(void)
{
    if (loop_flag == 0)
    {
        return;
    }
    if (data_type == 1)
    {
        if (file_read_end != -1 && file_read_pos >= file_read_end && freader != NULL)
        {
            freader->Seek(file_offset, CriMvFileReaderInterface::SEEK_FROM_BEGIN);
            file_read_pos = 0;
            unk5e8 = unk5e8 + 1;
        }
    }
    else
    {
        CriBool empty = criMvPly_PeekInputBufferData(mvply);
        if (empty == 0)
        {
            FUN_1400363b0(mvply, data_ptr, data_size);
            unk5e8 = unk5e8 + 1;
        }
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, vcall operand order)
// @0x1400231d0
void CriMvEasyPlayer::surveilTerminationInput(void)
{
    if (data_type == 2)
    {
        CriSint32 ply_status = criMvPly_GetStatus(mvply);
        switch (ply_status)
        {
        case 3:
        case 4:
        case 5:
            break;
        default:
            return;
        }
    }
    if (unk4c4 == 1)
    {
        return;
    }
    if (isEndReadFile() == 0)
    {
        return;
    }
    if (unk5e4 == 1)
    {
        return;
    }
    if (filereq_func != NULL)
    {
        filereq_func(this, filereq_usrobj);
    }
    else if (data_type == 2)
    {
        file_request_state = 0;
    }
    if (file_request_state == 1)
    {
        if (data_type == 2)
        {
            FUN_1400363b0(mvply, data_ptr, data_size);
        }
        else
        {
            unk4c4 = 1;
            unk4c0 = 4;
        }
    }
    else
    {
        criMvPly_TerminateSupply(mvply);
        unk5e4 = 1;
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023330
CriBool CriMvEasyPlayer::isEndReadFile(void)
{
    CriBool end = 0;
    if (data_type == 2)
    {
        if (criMvPly_PeekInputBufferData(mvply) == 0)
        {
            end = 1;
        }
    }
    else if (data_type == 1 && file_read_end != -1 && file_read_pos >= file_read_end)
    {
        end = 1;
    }
    return end;
}

// @0x1400233c0
void CriMvEasyPlayer::executeFileCloseServer(void)
{
    CriMvFileReaderInterface::AsyncStatus close_status;
    if (freader == NULL || data_type == 2)
    {
        return;
    }
    if (unk4c0 == 4 && freader != NULL)
    {
        unk4c0 = 5;
        freader->Close();
        file_closing = 1;
    }
    if (unk4c0 == 5 && freader != NULL && data_type == 1)
    {
        close_status = freader->GetCloseStatus();
        switch (close_status)
        {
        case CriMvFileReaderInterface::ASYNC_STATUS_COMPLETE:
            file_closing = 0;
            file_opened = 0;
            file_read_pos = 0;
            file_read_end = -1;
            if (modules_stopped == 1)
            {
                unk4c0 = 0;
                unk4c4 = 0;
            }
            else
            {
                unk4c0 = 1;
            }
            break;
        case CriMvFileReaderInterface::ASYNC_STATUS_ERROR:
            file_closing = 0;
            file_opened = 0;
            file_read_pos = 0;
            file_read_end = -1;
            notifyErrorB(this, "E07050101M: File Close Error", 0);
            break;
        }
    }
}

// @0x1400235a0
void CriMvEasyPlayer::executeFileOpenServer(void)
{
    if (unk4c4 == 0)
    {
        return;
    }
    if (unk4c0 == 1)
    {
        if (data_type == 2)
        {
            return;
        }
        if (unk4a0 == 1)
        {
            freader = freader_file;
        }
        else if (unk4a0 == 2)
        {
            freader = freader_mem;
        }
        if (freader != NULL)
        {
            file_opened = 1;
            unk4c0 = 2;
            freader->Open(fname);
        }
    }
    if (unk4c0 == 2 && freader != NULL && file_opened == 1)
    {
        CriMvFileReaderInterface::AsyncStatus ostat = freader->GetOpenStatus();
        if (ostat == CriMvFileReaderInterface::ASYNC_STATUS_COMPLETE)
        {
            if (file_read_end == -1 && file_closing == 0)
            {
                CriSint64 fsize = freader->GetFileSize();
                if (fsize <= 0)
                {
                    setNormalErrorStatus("E10090802M: CriMvFileReaderInterface::GetFileSize gave an invalid value");
                    return;
                }
                if (file_range < 0)
                {
                    file_read_end = fsize - file_offset;
                }
                else
                {
                    if ((CriSint64)(file_offset + file_range) > fsize)
                    {
                        setNormalErrorStatus("E10090801M: Given file range overruns the file size. "
                                             "Check the parameters of SetFileRange() ");
                        return;
                    }
                    file_read_end = file_range;
                }
                freader->Seek(file_offset, CriMvFileReaderInterface::SEEK_FROM_BEGIN);
            }
            unk4c0 = 3;
            unk4c4 = 0;
            file_request_state = 0;
        }
        else if (ostat == CriMvFileReaderInterface::ASYNC_STATUS_ERROR)
        {
            unk4c4 = 0;
            file_request_state = 0;
            file_closing = 0;
            file_opened = 0;
            file_read_pos = 0;
            file_read_end = -1;
            unk4c0 = 0;
            if (error_flag != 1)
            {
                setErrorMessage("E07020601M: File Open Error - ", fname);
                setNormalErrorStatus(DAT_143b277c0);
            }
        }
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x1400238f0
void CriMvEasyPlayer::ReplaceCenterVoice(CriSint32 track, CriError& err)
{
    err = CRIERR_OK;
    if (sound == NULL)
    {
        return;
    }
    center_voice_track = track;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023940
CriBool CriMvEasyPlayer::isAvailableCenterVoice(const CriMvStreamingParameters* stmprm)
{
    if (center_voice_track < 0 || center_voice_track >= CRIMV_MAX_AUDIO_NUM)
    {
        return 0;
    }
    if (center_voice_track == stmprm->track_play_audio)
    {
        return 0;
    }
    if (stmprm->audio_prm[center_voice_track].num_channel != 1)
    {
        return 0;
    }
    if (stmprm->audio_prm[stmprm->track_play_audio].num_channel < center_channel + 1)
    {
        return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x1400239e0
CriBool CriMvEasyPlayer::isAvailableSubAudio(const CriMvStreamingParameters* stmprm)
{
    if (subaudio == NULL)
    {
        return 0;
    }
    if (subaudio_track < 0 || subaudio_track >= CRIMV_MAX_AUDIO_NUM)
    {
        return 0;
    }
    if (stmprm->audio_prm[subaudio_track].num_channel == 0)
    {
        return 0;
    }
    if (subaudio_track == stmprm->track_play_audio)
    {
        return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023a70
CriBool CriMvEasyPlayer::attachCenterVoice(void)
{
    CriBool ok = FUN_140030f10(mvply, heap, center_voice_track);
    if (ok == 1)
    {
        attached_center_voice_track = center_voice_track;
    }
    return ok;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023ad0
void CriMvEasyPlayer::detachCenterVoice(void)
{
    criMvPly_DetachSubAudio(mvply);
    attached_center_voice_track = -1;
}

// @0x140023b10
void CriMvEasyPlayer::AttachSubAudioInterface(CriMvSoundInterface* subsound, CriError& err)
{
    CriSint32 plystat;
    err = CRIERR_OK;
    plystat = criMvPly_GetStatus(mvply);
    switch (plystat)
    {
    case 0:
    case 1:
    case 2:
    case 7:
        break;
    default:
        err = CRIERR_NG;
        setNormalErrorStatus("E08012501M: AttachSubAudioInterface() was called on invalid movie handle state.");
        return;
    }
    if (subsound == NULL)
    {
        subaudio = NULL;
    }
    else if (subsound == sound)
    {
        err = CRIERR_NG;
        setNormalErrorStatus("E08012502M: AttachSubAudioInterface(): SubAudio interface is similar to MainAudio interface.");
    }
    else
    {
        subaudio = subsound;
    }
}

// @0x140023bf0
void CriMvEasyPlayer::DetachSubAudioInterface(CriError& err)
{
    err = CRIERR_OK;
    subaudio = NULL;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023c20
void CriMvEasyPlayer::SetSubAudioTrack(CriSint32 track, CriError& err)
{
    err = CRIERR_OK;
    subaudio_track = track;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023c50
CriSint32 CriMvEasyPlayer::GetSubAudioTrack(CriError& err)
{
    CriMvStreamingParameters stmprm;
    err = CRIERR_OK;
    if (GetMovieInfo(stmprm) == 0)
    {
        return -1;
    }
    if (subaudio_track < 0 || subaudio_track >= CRIMV_MAX_AUDIO_NUM)
    {
        return -1;
    }
    if (stmprm.audio_prm[subaudio_track].num_channel == 0)
    {
        return -1;
    }
    if (subaudio_track == stmprm.track_play_audio)
    {
        return -1;
    }
    return subaudio_track;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023d20
CriBool CriMvEasyPlayer::attachSubAudioHandle(CriHeap heap)
{
    CriBool ok = FUN_140030f10(mvply, heap, subaudio_track);
    if (ok == 1)
    {
        attached_subaudio_track = subaudio_track;
    }
    return ok;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023d80
void CriMvEasyPlayer::detachSubAudioHandle(void)
{
    criMvPly_DetachSubAudio(mvply);
    attached_subaudio_track = -1;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023dc0
void CriMvEasyPlayer::SetFileRequestCallback(void (*func)(CriMvEasyPlayer* mveasy, void* usrobj),
                                             void* usrobj, CriError& err)
{
    err = CRIERR_OK;
    filereq_func = func;
    filereq_usrobj = usrobj;
}

// @0x140023e10
void CriMvEasyPlayer::SetSeekPosition(CriSint32 frame_id, CriError& err)
{
    SetSeekFrameAndOffset(frame_id, 0, err);
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023e50
void CriMvEasyPlayer::SetSeekFrameAndOffset(CriSint32 frame_id, CriUint64 offset, CriError& err)
{
    err = CRIERR_OK;
    seek_frame_id = frame_id;
    seek_offset = offset;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023ea0
void CriMvEasyPlayer::GetPlaybackInfo(void* info, CriError& err)
{
    err = CRIERR_OK;
    memcpy(info, playback_info, sizeof(playback_info));
}

// @0x140023ef0
CriSint32 CriMvEasyPlayer::GetLastFrameResult(CriError& err)
{
    err = CRIERR_OK;
    return last_frame_result;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140023f20
void CriMvEasyPlayer::SetNumberOfFramesForPrep(CriUint32 nframes, CriError& err)
{
    err = CRIERR_OK;
    if (mvply != NULL)
    {
        FUN_140031060(mvply, nframes);
    }
}

// MS2-FUNCTIONAL: VS2008 converts the unsigned 64-bit operands to float with its own sequence
// @0x140023f70
CriSint32 CriMvEasyPlayer::CalcFrameIdFromTime(CriUint64 count, CriUint64 unit, CriError& err)
{
    CriUint32 framerate;
    CriSint32 frame_id = -1;
    err = CRIERR_OK;
    if (unit == 0)
    {
        return frame_id;
    }
    framerate = mvply->framerate;
    frame_id = (CriSint32)((CriFloat32)count * (CriFloat32)framerate / (CriFloat32)unit / 1000.0f);
    if (frame_id == 0)
    {
        err = CRIERR_NG;
    }
    return frame_id;
}

// MS2-FUNCTIONAL: VS2008 converts the unsigned 64-bit operands to and from float with its own sequence
// @0x140024040
CriUint64 CriMvEasyPlayer::CalcTimeFromFrameId(CriSint32 frame_id, CriUint64 unit, CriError& err)
{
    CriUint32 framerate2;
    CriUint64 count = 0;
    err = CRIERR_OK;
    if (unit == 0 || frame_id < 0)
    {
        return count;
    }
    framerate2 = mvply->framerate;
    count = (CriUint64)((CriFloat32)frame_id * 1000.0f * (CriFloat32)unit / (CriFloat32)framerate2);
    return count;
}

// @0x140024120
CriSint32 CriMvEasyPlayer::SearchNextEventPointByTime(CriUint64 count, CriUint64 unit, CriSint32 type,
                                                      CriMvEventPoint* eventinfo, CriError& err)
{
    // VC9 lays the locals out by a hash of their names; these names give the exe's slots.
    CriMvEventPoint* p;             // the event point being checked
    CriUint32 i;
    CriFloat32 ms;                  // the requested time in ms
    CriFloat32 time;                // the event point's time in ms
    CriMvCuePointInfo* cueinfo;
    CriSint32 frame_id = -1;
    err = CRIERR_OK;
    memset(eventinfo, 0, sizeof(CriMvEventPoint));
    eventinfo->tunit = 1;
    if (unit == 0)
    {
        err = CRIERR_NG;
        return frame_id;
    }
    cueinfo = &mvply->cuepoint;
    if (cueinfo == NULL)
    {
        err = CRIERR_NG;
        return frame_id;
    }
    ms = (CriFloat32)count * 1000.0f / (CriFloat32)unit;
    for (i = 0; i < cueinfo->num_eventpoint; i++)
    {
        p = &cueinfo->eventtable[i];
        time = (CriFloat32)p->time * 1000.0f / (CriFloat32)p->tunit;
        if (ms >= time)
        {
            continue;
        }
        if (p->type != type && type != -1)
        {
            continue;
        }
        *eventinfo = *p;
        break;
    }
    if (i == cueinfo->num_eventpoint)
    {
        return frame_id;
    }
    frame_id = CalcFrameIdFromTime(eventinfo->time, eventinfo->tunit);
    return frame_id;
}

// @0x140024360
CriSint32 CriMvEasyPlayer::SearchPrevEventPointByTime(CriUint64 count, CriUint64 unit, CriSint32 type,
                                                      CriMvEventPoint* eventinfo, CriError& err)
{
    // VC9 lays the locals out by a hash of their names; these names give the exe's slots.
    CriMvEventPoint* p;             // the event point being checked
    CriUint32 i;
    CriFloat32 ms;                  // the requested time in ms
    CriFloat32 ep_ms;               // the event point's time in ms
    CriMvEventPoint* best;          // the last matching event point before the requested time
    CriMvCuePointInfo* cueinfo;
    CriSint32 frame_id = -1;
    err = CRIERR_OK;
    memset(eventinfo, 0, sizeof(CriMvEventPoint));
    eventinfo->tunit = 1;
    if (unit == 0)
    {
        err = CRIERR_NG;
        return frame_id;
    }
    cueinfo = &mvply->cuepoint;
    best = NULL;
    if (cueinfo == NULL)
    {
        err = CRIERR_NG;
        return frame_id;
    }
    ms = (CriFloat32)count * 1000.0f / (CriFloat32)unit;
    for (i = 0; i < cueinfo->num_eventpoint; i++)
    {
        p = &cueinfo->eventtable[i];
        ep_ms = (CriFloat32)p->time * 1000.0f / (CriFloat32)p->tunit;
        if (ms > ep_ms)
        {
            if (p->type == type || type == -1)
            {
                best = p;
            }
        }
        else
        {
            break;
        }
    }
    if (best == NULL)
    {
        return frame_id;
    }
    *eventinfo = *best;
    frame_id = CalcFrameIdFromTime(eventinfo->time, eventinfo->tunit);
    return frame_id;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x1400245b0
CriMvCuePointInfo* CriMvEasyPlayer::GetCuePointInfo(CriError& err)
{
    err = CRIERR_OK;
    if (mvply->cuepoint.num_eventpoint == 0 || mvply->cuepoint.eventtable == NULL)
    {
        return NULL;
    }
    return &mvply->cuepoint;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024610
void CriMvEasyPlayer::SetCuePointCallback(void (*func)(CriMvEasyPlayer* mveasy, CriMvEventPoint* eventinfo, void* usrobj),
                                          void* usrobj,
                                          CriError& err)
{
    err = CRIERR_OK;
    cuepoint_func = func;
    cuepoint_usrobj = usrobj;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, frame size)
// @0x140024660
void CriMvEasyPlayer::executeCuePointServer(void)
{
    if (mvply->cuepoint.num_eventpoint == 0 || mvply->cuepoint.eventtable == NULL)
    {
        return;
    }
    if (cuepoint_func == NULL)
    {
        return;
    }
    if (GetStatus() != MVEASY_STATUS_PLAYING)
    {
        return;
    }
    CriMvCuePointInfo* cueinfo = &mvply->cuepoint;
    CriUint64 count;
    CriUint64 unit;
    GetTime(count, unit);
    if (unit == 0)
    {
        return;
    }
    CriFloat32 now_ms = (CriFloat32)count * 1000.0f / (CriFloat32)unit;
    CriUint32 framerate = stmprm.video_prm[0].framerate;
    if (framerate == 0)
    {
        return;
    }
    CriFloat32 seek_ms = (CriFloat32)seek_frame_id * 1000.0f / (CriFloat32)framerate * 1000.0f;
    CriMvEventPoint* ep;
    CriFloat32 ep_ms;
    if (loop_flag == 1)
    {
        CriUint32 total_frames = stmprm.video_prm[0].total_frames;
        CriFloat32 movie_ms = (CriFloat32)total_frames * 1000.0f / (CriFloat32)framerate * 1000.0f;
        CriUint32 loop_cnt = 0;
        if (0.1f > movie_ms)
        {
            return;
        }
        CriUint32 first = (CriUint32)(now_ms / movie_ms);
        if (first > 0)
        {
            first = first - 1;
        }
        CriUint32 last = first + 3;
        for (loop_cnt = first; loop_cnt < last; loop_cnt++)
        {
            if (movie_ms > now_ms - movie_ms * (CriFloat32)loop_cnt)
            {
                break;
            }
        }
        if (loop_cnt == last)
        {
            return;
        }
        CriFloat32 local_ms = now_ms - movie_ms * (CriFloat32)loop_cnt;
        CriUint32 i;
        for (i = 0; i < cueinfo->num_eventpoint; i++)
        {
            ep = &cueinfo->eventtable[i];
            if (ep->cnt_callback < loop_cnt && cuepoint_func != NULL)
            {
                cuepoint_func(this, ep, cuepoint_usrobj);
                ep->cnt_callback = ep->cnt_callback + 1;
            }
        }
        for (i = 0; i < cueinfo->num_eventpoint; i++)
        {
            ep = &cueinfo->eventtable[i];
            if (ep->tunit == 0)
            {
                return;
            }
            if (ep->cnt_callback > loop_cnt)
            {
                continue;
            }
            ep_ms = (CriFloat32)ep->time * 1000.0f / (CriFloat32)ep->tunit;
            if (loop_cnt == 0 && seek_ms > ep_ms)
            {
                ep->cnt_callback = ep->cnt_callback + 1;
                continue;
            }
            if (ep_ms > local_ms)
            {
                break;
            }
            if (cuepoint_func != NULL)
            {
                cuepoint_func(this, ep, cuepoint_usrobj);
                ep->cnt_callback = ep->cnt_callback + 1;
            }
        }
    }
    else
    {
        for (CriUint32 j = 0; j < cueinfo->num_eventpoint; j++)
        {
            ep = &cueinfo->eventtable[j];
            if (ep->tunit == 0)
            {
                return;
            }
            if (ep->cnt_callback == 0)
            {
                ep_ms = (CriFloat32)ep->time * 1000.0f / (CriFloat32)ep->tunit;
                if (seek_ms > ep_ms)
                {
                    continue;
                }
                if (ep_ms > now_ms)
                {
                    return;
                }
                if (cuepoint_func != NULL)
                {
                    cuepoint_func(this, ep, cuepoint_usrobj);
                    ep->cnt_callback = ep->cnt_callback + 1;
                }
            }
        }
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024bf0
void CriMvEasyPlayer::SetStopCompleteCallback(void (*func)(CriMvEasyPlayer* mveasy, void* usrobj), void* usrobj,
                                              CriError& err)
{
    err = CRIERR_OK;
    stopcmpl_func = func;
    stopcmpl_usrobj = usrobj;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024c40
void CriMvEasyPlayer::SetUsableProcessors_PC(int num_threads, const unsigned long* affinity_masks, int priority,
                                             CriError& err)
{
    CriSint32 i2;
    CriMvPly ply = mvply;
    CriSint32 priorities[128];
    err = CRIERR_OK;
    if (ply == NULL)
    {
        return;
    }
    for (i2 = 0; i2 < num_threads; i2++)
    {
        priorities[i2] = priority;
    }
    FUN_14003b720((CriMvSubAudioTrackState *)ply, num_threads, (const long *)affinity_masks, priorities);
}

// @0x140024d00
void CriMvEasyPlayer::setNormalErrorStatus(const CriChar8* msg)
{
    error_flag = 1;
    requestStopModules();
    criErr_Notify(0, msg);
}

// @0x140024d40
void CriMvEasyPlayer::notifyErrorA(void* obj, const CriChar8* msg, CriSint32 p1)
{
    FUN_140038ce4(0, msg, p1, 0, obj);
}

// @0x140024d90
void CriMvEasyPlayer::notifyErrorB(void* obj, const CriChar8* msg, CriSint32 p1)
{
    FUN_140038ce4(0, msg, p1, 0, obj);
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024de0
void CriMvEasyPlayer::setErrorMessage(const CriChar8* msg, const CriChar8* detail)
{
    CriSint32 len = (CriSint32)strlen(msg);
    memset(DAT_143b277c0, 0, 0x100);
    strcpy_s(DAT_143b277c0, 0x100, msg);
    if (detail != NULL)
    {
        strncat_s(DAT_143b277c0, 0x100, detail, (CriUint32)(0x100 - len - 1));
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024e80
CriMvEasyPlayer::CriMvEasyPlayer()
{
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024ea0
CriMvEasyPlayer::~CriMvEasyPlayer()
{
}

// @0x140024ec0
void FUN_140024ec0(void* obj)
{
    FUN_1400379e0(obj);
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024ee0
void CriMvEasyPlayer::SetMemoryPlaybackType(CriSint32 type, CriError& err)
{
    err = CRIERR_OK;
    memory_playback_type = type;
}

// @0x140024f10
void CriMvEasyPlayer::DeferFileRequest(CriError& err)
{
    err = CRIERR_OK;
    file_request_state = 2;
}

namespace CriMv {

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024f80
void Initialize_Common(void)
{
    DAT_143b278c4 = DAT_143b278c4 + 1;
    if (DAT_143b278c4 == 1)
    {
        FUN_14002e7d0();
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140024fb0
void Finalize(CriError& err)
{
    err = CRIERR_OK;
    DAT_143b278c4 = DAT_143b278c4 - 1;
    if (DAT_143b278c4 == 0)
    {
        FUN_14002e8c0();
    }
}

// @0x140024ff0
CriBool IsLibraryInitialized(void)
{
    if (DAT_143b278c4 >= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140025010
CriSint32 CalcHandleWorkSize(CriError& err)
{
    CriSint32 size = 0;
    err = CRIERR_OK;
    size += (size_t)0x24;
    size += (size_t)0x74e;
    size += (size_t)0x66;
    size += 0x40;
    size += 0x48;
    size += FUN_14002e9e0() + 4;
    return size;
}

} // namespace CriMv

// ==== CRI Movie C++ wrappers (0x140026db0-0x140027048) ============================================================
// Thin CriMv / CriMvEasyPlayer entry points over the player core (criMvPly, sfr_cri_02) and the Mana decoder; same
// VS2008 /Od objects as the easy player.

extern "C" {
}

namespace CriMv {

// @0x140026db0
void InitializeFrame32bitARGB(void)
{
    FUN_14003b880();
}

} // namespace CriMv

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140026dd0
CriBool CriMvEasyPlayer::GetFrameOnTimeAs32bitARGB(CriUint8* imagebuf, CriUint32 pitch, CriUint32 bufsize,
                                                   CriMvFrameInfo& frameinfo, CriError& err)
{
    CriBool ret = 0;
    err = CRIERR_OK;
    if (isNextFrameOnTime(0, err) != 1)
    {
        return ret;
    }
    ret = FUN_14003b8b0(mvply, imagebuf, pitch, bufsize, &frameinfo);
    return ret;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140026e60
CriSint32 CriMvEasyPlayer::CopyFrameToBufferARGB32(CriUint8* dstbuf, CriUint32 dstpitch, CriUint32 dstbufsize,
                                                   const CriMvYuvBuffers* srcbufs, const CriMvFrameInfo* src_vinf,
                                                   const CriMvAlphaFrameInfo* src_ainf, CriError& err)
{
    err = CRIERR_OK;
    FUN_14003bb60(mvply, dstbuf, dstpitch, dstbufsize, srcbufs, src_vinf, src_ainf);
    return 0;
}

namespace CriMv {

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140026ed0
void Initialize(CriError& err)
{
    CriUint32 max_num;
    void* work = FUN_14003c060(&max_num);
    if (work == NULL)
    {
        work = FUN_1400411e0(&max_num);
        CriUint32 work_size = criVmpv_CalcMovieHandleWork(max_num);
        SetupMovieHandleWork(max_num, work, work_size, err);
    }
    InitializeMana(err);
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140026f40
void AttachSofdecDecoder(CriError& err)
{
    err = CRIERR_OK;
    FUN_14003b6e0();
}

// @0x140026f70
void FUN_140026f70(void)
{
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140026f80
CriUint32 CalcMovieHandleWork(CriUint32 max_num, CriError& err)
{
    err = CRIERR_OK;
    CriUint32 size = criVmpv_CalcMovieHandleWork(max_num);
    return size;
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140026fc0
void SetupMovieHandleWork(CriUint32 max_num, void* work, CriUint32 work_size, CriError& err)
{
    err = CRIERR_OK;
    CriBool ok = FUN_14003bf80(max_num, work, work_size);
    if (ok != 1)
    {
        err = CRIERR_NG;
    }
}

// MS2-FUNCTIONAL: VS2008 /Od code generation (register choice, stack slot order, add/sub vs inc/dec)
// @0x140027020
CriUint32 GetMaxNumberOfHandles(CriError& err)
{
    err = CRIERR_OK;
    CriUint32 num = criVmpv_GetMaxNumberOfHandles();
    return num;
}

} // namespace CriMv

#pragma intrinsic(memset, memcpy, strlen)
#pragma optimize("", on)

// ==== CRI Heap (0x140027048-0x140028360) ===========================================================================
// CRI Heap/PCx64 1.21.02: a first-fit block allocator over a caller-supplied buffer, compiled optimized (C). The
// serialized entry points wrap the plain ones in one global critical section (criCs, sfr_cri_02).

#include <stdarg.h>

extern "C" {
void*  FUN_140039ea8(void* work, CriSint32 work_size);
__declspec(dllimport) int  __stdcall wvsprintfA(char* buf, const char* fmt, va_list args);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char* str);
}

extern const CriChar8* DAT_143b278d0;      // version string of the heap library
extern CriSint32 DAT_143b278d8;            // criHeap_Initialize count
extern void*     DAT_143b278e0;            // the global critical section
extern CriUint8  DAT_143b278f0[0x48];      // its work area
extern const CriHeapVtbl DAT_143a46430;    // serialized entry points
extern const CriHeapVtbl DAT_143a46450;    // plain entry points
extern const CriChar8* const DAT_143a46470;     // "(no name)"
extern const CriChar8* const DAT_143a46478[2];  // block state names: FREE, ALOC
extern const CriChar8* const DAT_143a46488[4];  // block type names: NONE, FIX, TEMP, ...

#define CRIHEAP_HEADER_SIZE     0x22                        // sizeof(CriHeapBlock)
#define CRIHEAP_BLOCK_SIZE      (CRIHEAP_HEADER_SIZE + 4)   // with the back-offset dword
#define CRIHEAP_ALIGN           8
#define CRIHEAP_ALIGN_UP(p)     (((CriUint64)(p) + (CRIHEAP_ALIGN - 1)) & ~(CriUint64)(CRIHEAP_ALIGN - 1))

static const CriChar8* const criheap_version = "\nCRI Heap/PCx64 Ver.1.21.02 Build:Jan 13 2012 19:02:05\n";

// Address of the block's data.
static __inline CriUint8* criheap_GetDataAddress(CriHeapBlock* blk)
{
    return (CriUint8*)blk + CRIHEAP_BLOCK_SIZE + blk->alignspc;
}

// Stores the data-to-header offset in the dword in front of the data.
static __inline void criheap_SetBackOffset(CriHeapBlock* blk)
{
    // The exe finds the dword by aligning the header end up to 8 (the data is always 8-aligned, so it is data - 4).
    *((CriUint32*)CRIHEAP_ALIGN_UP((CriUint8*)blk + CRIHEAP_HEADER_SIZE + blk->alignspc) - 1) =
        blk->alignspc + CRIHEAP_BLOCK_SIZE;
}

// Whole size of a block: header, alignment space, data and trailing gap.
static __inline CriSint32 criheap_GetBlockSize(CriHeapBlock* blk)
{
    return blk->gap + blk->memsize + blk->alignspc + CRIHEAP_BLOCK_SIZE;
}

// Alignment space that puts the data of a block at adr on 8 (the exe tests the remainder at run time).
static __inline CriSint32 criheap_CalcDefaultAlignSpace(CriUint64 adr)
{
    CriSint32 spc = (CriSint32)((adr + CRIHEAP_BLOCK_SIZE) & 7);
    if (spc != 0)
    {
        spc = CRIHEAP_ALIGN - spc;
    }
    return spc;
}

// Alignment space that puts the block's data on align (at least 8).
static __inline CriUint16 criheap_CalcAlignSpace(CriHeapBlock* blk, CriSint32 align)
{
    CriSint32 a = (align < CRIHEAP_ALIGN) ? CRIHEAP_ALIGN : align;
    CriUint32 rem = (CriUint32)(((CriUint64)blk + CRIHEAP_BLOCK_SIZE) % (CriUint64)(CriSint64)a);
    if (rem != 0)
    {
        rem = a - rem;
    }
    return rem;
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: CRI Heap was compiled optimized by an older MSVC; VS2017 schedules and allocates registers differently
// @0x140027148
static CriHeap criheap_InitializeHandle(CriHeap heap, CriSint32 size)
{
    CriUint8* top = (CriUint8*)heap + sizeof(struct _criheap_struct);
    CriHeapBlock* blk;
    CriSint64 pad;

    heap->totalsize = size;
    blk = (CriHeapBlock*)CRIHEAP_ALIGN_UP(top);
    pad = (CriUint8*)blk - top;
    memset(blk, 0, CRIHEAP_HEADER_SIZE);
    blk->alignspc = (CriUint16)criheap_CalcDefaultAlignSpace((CriUint64)blk);
    blk->nextblock = NULL;
    blk->type = CRIHEAP_TYPE_NONE;
    blk->gap = 0;
    blk->memsize = size - (CriUint16)(blk->alignspc + CRIHEAP_BLOCK_SIZE) - pad - (CriSint32)sizeof(struct _criheap_struct);
    criheap_SetBackOffset(blk);
    heap->topblock = blk;
    heap->taleblock = blk;
    heap->currentsize = pad + (CriSint32)sizeof(struct _criheap_struct);
    heap->peaksize = pad + (CriSint32)sizeof(struct _criheap_struct);
    return heap;
}

// Front-to-back search for a FIX block: a freed block of exactly this size and alignment, or the free area.
// @0x140027278
__inline CriHeapBlock* criheap_SearchFixBlock(CriHeap heap, CriSint32 size, CriUint16 align)
{
    CriHeapBlock* blk = heap->topblock;
    do
    {
        if (!blk->used)
        {
            if (blk->memsize == size && blk->alignspc == criheap_CalcAlignSpace(blk, align))
            {
                return blk;
            }
            if (blk->type == CRIHEAP_TYPE_NONE)
            {
                return blk;
            }
        }
        blk = blk->nextblock;
    } while (blk != NULL);
    return NULL;
}

// Back-to-front search for a TEMPORARY block.
// MS2-FUNCTIONAL: CRI Heap was compiled optimized by an older MSVC; VS2017 schedules and allocates registers differently
// @0x1400272e0
static CriHeapBlock* criheap_SearchTemporaryBlock(CriHeap heap, CriSint32 size, CriUint16 align)
{
    CriHeapBlock* blk = heap->taleblock;
    do
    {
        if (!blk->used)
        {
            CriSint32 space = blk->memsize + blk->gap + blk->alignspc;
            if (criheap_CalcAlignSpace(blk, align) + size <= space
                && (blk->type == CRIHEAP_TYPE_NONE || blk->type == CRIHEAP_TYPE_TEMPORARY))
            {
                return blk;
            }
            if (blk->memsize == size && blk->alignspc == criheap_CalcAlignSpace(blk, align)
                && blk->type == CRIHEAP_TYPE_TEMPORARY)
            {
                return blk;
            }
        }
        blk = blk->prevblock;
    } while (blk != NULL);
    return NULL;
}

// @0x1400273b8
__forceinline CriHeapBlock* criheap_SearchBlock(CriHeap heap, CriSint32 type, CriSint32 size, CriUint16 align)
{
    CriHeapBlock* blk = NULL;
    switch (type)
    {
    case CRIHEAP_TYPE_FIX:
        blk = criheap_SearchFixBlock(heap, size, align);
        break;
    case CRIHEAP_TYPE_TEMPORARY:
        blk = criheap_SearchTemporaryBlock(heap, size, align);
        break;
    case CRIHEAP_TYPE_DYNAMIC:
        criErr_Notify(0, "E2009030950:Dynamic memory allocation is not supported yet.");
        break;
    default:
        criErr_Notify(0, "E2009030951:Specified memory allocation method is invalid.");
        break;
    }
    return blk;
}

// Cuts a FIX block from the front of a free block; the rest becomes a new free block behind it.
// MS2-FUNCTIONAL: CRI Heap was compiled optimized by an older MSVC; VS2017 schedules and allocates registers differently
// @0x1400274e0
static CriHeapBlock* criheap_DivideFixBlock(CriHeap heap, CriHeapBlock* blk, CriSint32 size, const CriChar8* name,
                                            CriSint32 align)
{
    CriSint32 blksize = criheap_GetBlockSize(blk);
    CriUint16 alignspc = (CriUint16)criheap_CalcAlignSpace(blk, align);
    CriSint32 offset = alignspc + size + CRIHEAP_BLOCK_SIZE;
    CriSint32 hdrpad = criheap_CalcDefaultAlignSpace(0);
    CriHeapBlock* rest;
    CriUint16 gap;

    if (criheap_GetBlockSize(blk) < hdrpad + offset + CRIHEAP_BLOCK_SIZE)
    {
        return NULL;
    }
    rest = (CriHeapBlock*)CRIHEAP_ALIGN_UP((CriUint8*)blk + offset);
    gap = (CriUint16)((CriUint16)(CriUint64)rest - (CriUint16)(CriUint64)((CriUint8*)blk + offset));
    offset += gap;
    memset(rest, 0, CRIHEAP_HEADER_SIZE);
    rest->alignspc = (CriUint16)criheap_CalcDefaultAlignSpace((CriUint64)rest);
    rest->prevblock = blk;
    rest->memsize = blksize - rest->alignspc - offset - CRIHEAP_BLOCK_SIZE;
    rest->nextblock = blk->nextblock;
    blk->alignspc = alignspc;
    blk->memsize = size;
    blk->nextblock = rest;
    blk->nameadr = name;
    blk->type = CRIHEAP_TYPE_FIX;
    blk->gap = gap;
    blk->used = 1;
    criheap_SetBackOffset(blk);
    if (rest->nextblock == NULL)
    {
        heap->taleblock = rest;
    }
    else
    {
        rest->nextblock->prevblock = rest;
    }
    return blk;
}

// Cuts a TEMPORARY block from the back of a free block (or takes all of it when no header fits).
// @0x140027638
static CriHeapBlock* criheap_DivideTemporaryBlock(CriHeap heap, CriHeapBlock* blk, CriSint32 size,
                                                  const CriChar8* name, CriSint32 align)
{
    CriUint8* end = (blk->nextblock != NULL) ? (CriUint8*)blk->nextblock : (CriUint8*)heap + heap->totalsize;
    CriUint8* last = end - (CriUint32)size;
    CriSint32 a = (align > CRIHEAP_ALIGN) ? align : CRIHEAP_ALIGN;
    CriUint8* data;
    CriUint16 gap;
    CriHeapBlock* tmp;

    if (a % CRIHEAP_ALIGN != 0)
    {
        a = (a * CRIHEAP_ALIGN - 0x40) / CRIHEAP_ALIGN;
    }
    data = (CriUint8*)(((CriUint64)last / (CriUint64)(CriSint64)a) * (CriUint64)(CriSint64)a);
    gap = (CriUint16)((CriUint16)(CriUint64)last - (CriUint16)(CriUint64)data);
    tmp = (CriHeapBlock*)(((CriUint64)data - CRIHEAP_BLOCK_SIZE) & ~(CriUint64)7);
    if ((CriUint8*)tmp < criheap_GetDataAddress(blk))
    {
        if (blk->type == CRIHEAP_TYPE_NONE)
        {
            return NULL;
        }
        blk->alignspc = (CriUint16)((CriUint16)(data - (CriUint8*)blk) - CRIHEAP_BLOCK_SIZE);
        blk->memsize = size;
        blk->type = CRIHEAP_TYPE_TEMPORARY;
        blk->gap = gap;
        blk->nameadr = name;
        blk->used = 1;
        criheap_SetBackOffset(blk);
        return blk;
    }
    tmp->alignspc = (CriUint16)((CriUint16)(data - (CriUint8*)tmp) - CRIHEAP_BLOCK_SIZE);
    tmp->memsize = size;
    tmp->type = CRIHEAP_TYPE_TEMPORARY;
    tmp->nextblock = blk->nextblock;
    tmp->prevblock = blk;
    tmp->gap = gap;
    tmp->nameadr = name;
    tmp->used = 1;
    criheap_SetBackOffset(tmp);
    blk->alignspc = (CriUint16)criheap_CalcDefaultAlignSpace((CriUint64)blk);
    if (blk->nextblock != NULL)
    {
        blk->nextblock->prevblock = tmp;
    }
    blk->nextblock = tmp;
    blk->gap = 0;
    blk->memsize = (CriSint32)((CriUint8*)tmp - (CriUint8*)blk) - (CriUint16)(blk->alignspc + CRIHEAP_BLOCK_SIZE);
    if (tmp->nextblock == NULL)
    {
        heap->taleblock = tmp;
    }
    return tmp;
}

// @0x1400277c0
static void* criheap_Alloc(CriHeap heap, CriSint32 type, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    CriHeapBlock* blk;
    CriUint16 alignspc;

    if (size < 0)
    {
        return NULL;
    }
    blk = criheap_SearchBlock(heap, type, size, align);
    if (blk == NULL)
    {
        return NULL;
    }
    alignspc = criheap_CalcAlignSpace(blk, align);
    if (size == blk->memsize && alignspc == blk->alignspc)
    {
        if (blk->type == CRIHEAP_TYPE_NONE)
        {
            return NULL;
        }
        blk->nameadr = name;
        blk->type = (CriUint8)type;
        blk->used = 1;
        criheap_SetBackOffset(blk);
    }
    else
    {
        switch (type)
        {
        case CRIHEAP_TYPE_FIX:
            blk = criheap_DivideFixBlock(heap, blk, size, name, align);
            break;
        case CRIHEAP_TYPE_TEMPORARY:
            blk = criheap_DivideTemporaryBlock(heap, blk, size, name, align);
            break;
        default:
            return NULL;
        }
    }
    if (blk == NULL)
    {
        return NULL;
    }
    heap->currentsize += criheap_GetBlockSize(blk);
    if (heap->peaksize < heap->currentsize)
    {
        heap->peaksize = heap->currentsize;
    }
    return criheap_GetDataAddress(blk);
}

// @0x140027974
void* criheap_AllocFixNoLock(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    return criheap_Alloc(heap, CRIHEAP_TYPE_FIX, size, name, align);
}

// @0x140027994
void* criheap_AllocTemporaryNoLock(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    return criheap_Alloc(heap, CRIHEAP_TYPE_TEMPORARY, size, name, align);
}

// @0x1400279b4
void* criheap_AllocDynamicNoLock(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    return criheap_Alloc(heap, CRIHEAP_TYPE_DYNAMIC, size, name, align);
}

// Releases a block and merges it with free neighbours.
// @0x1400279e8
static void criheap_FreeBlock(CriHeap heap, CriHeapBlock* blk)
{
    CriHeapBlock* next;
    CriHeapBlock* prev;
    CriHeapBlock* nextnext;
    CriHeapBlock* cur;

    if (blk->used == 1)
    {
        heap->currentsize += -CRIHEAP_BLOCK_SIZE - blk->gap - blk->alignspc - blk->memsize;
    }
    prev = blk->prevblock;
    next = blk->nextblock;
    nextnext = NULL;
    if (next != NULL)
    {
        nextnext = next->nextblock;
    }
    blk->used = 0;
    if (prev != NULL && !prev->used)
    {
        prev->nextblock = next;
        prev->memsize += criheap_GetBlockSize(blk);
        if (next != NULL)
        {
            next->prevblock = prev;
        }
        if (prev->nextblock == NULL)
        {
            heap->taleblock = prev;
        }
        cur = prev;
    }
    else
    {
        cur = blk;
    }
    if (next != NULL && !next->used)
    {
        cur->nextblock = next->nextblock;
        cur->memsize += criheap_GetBlockSize(next);
        if (next->nextblock != NULL)
        {
            next->nextblock->prevblock = cur;
        }
        // The exe tests which block absorbed next before it tests for the tail; both store the same block.
        if (cur == blk)
        {
            if (nextnext == NULL)
            {
                heap->taleblock = blk;
            }
        }
        else if (nextnext == NULL)
        {
            heap->taleblock = cur;
        }
        if (next->type == CRIHEAP_TYPE_NONE)
        {
            cur->type = CRIHEAP_TYPE_NONE;
        }
        if (next->nameadr == NULL)
        {
            cur->nameadr = NULL;
        }
        criheap_SetBackOffset(cur);
    }
}

// Frees a block; a FIX block in front of the free area is folded into it with the free blocks before it.
// @0x140027ae4
static CriSint32 criheap_Free(CriHeap heap, CriHeapBlock* blk)
{
    CriSint32 size = blk->memsize;
    CriHeapBlock* next;

    if (blk->type == CRIHEAP_TYPE_TEMPORARY)
    {
        criheap_FreeBlock(heap, blk);
        return size;
    }
    else if (blk->type == CRIHEAP_TYPE_FIX)
    {
        heap->currentsize += -CRIHEAP_BLOCK_SIZE - blk->gap - blk->alignspc - size;
        next = blk->nextblock;
        if (next != NULL && next->type == CRIHEAP_TYPE_NONE)
        {
            CriUint8* end = (CriUint8*)next + (CriUint32)criheap_GetBlockSize(next);
            while (blk->prevblock != NULL && blk->prevblock->used != 1)
            {
                blk = blk->prevblock;
            }
            blk->used = 0;
            blk->type = CRIHEAP_TYPE_NONE;
            blk->alignspc = (CriUint16)criheap_CalcDefaultAlignSpace((CriUint64)blk);
            blk->gap = 0;
            blk->nameadr = NULL;
            blk->memsize = (CriSint32)(end - (CriUint8*)blk) - (CriUint16)(blk->alignspc + CRIHEAP_BLOCK_SIZE);
            blk->nextblock = next->nextblock;
            if (blk->nextblock != NULL)
            {
                blk->nextblock->prevblock = blk;
            }
            else
            {
                heap->taleblock = blk;
            }
        }
        else
        {
            blk->used = 0;
            if (next == NULL)
            {
                blk->type = CRIHEAP_TYPE_NONE;
                blk->nameadr = NULL;
            }
        }
    }
    else
    {
        return -1;
    }
    return size;
}

// @0x140027be4 (external: data_data_game's table takes it as FUN_140027be4)
CriSint32 criheap_FreeNoLock(CriHeap heap, void* ptr)
{
    if (ptr == NULL)
    {
        criErr_Notify(0, "E08062600H:Pointer was NULL.");
        return 0;
    }
    if ((CriUint8*)heap <= (CriUint8*)ptr && (CriUint8*)heap + heap->totalsize >= (CriUint8*)ptr)
    {
        return criheap_Free(heap, (CriHeapBlock*)((CriUint8*)ptr - ((CriUint32*)ptr)[-1]));
    }
    criErr_Notify(0, "E08021402H:Bad pointer was appointed.");
    return 0;
}
#pragma optimize("", on)

extern "C" {

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// @0x140027048
void FUN_140027048(void)
{
    if (DAT_143b278e0 != NULL)
    {
        criCs_Destroy((_RTL_CRITICAL_SECTION *)DAT_143b278e0);
        DAT_143b278e0 = NULL;
    }
}

// @0x140027c2c
CriSint32 CRIAPI criHeap_EnterCriticalSection(void)
{
    if (DAT_143b278e0 == NULL)
    {
        criErr_Notify(0, "E08052300H:CRI Heap is not initialized.");
        return -1;
    }
    FUN_140039f50((_RTL_CRITICAL_SECTION *)DAT_143b278e0);
    return 0;
}

// @0x140027c5c
CriSint32 CRIAPI criHeap_LeaveCriticalSection(void)
{
    if (DAT_143b278e0 == NULL)
    {
        criErr_Notify(0, "E08052301H:CRI Heap is not initialized.");
        return -1;
    }
    FUN_140039f8c((_RTL_CRITICAL_SECTION *)DAT_143b278e0);
    return 0;
}

// @0x140027dd0
CriSint32 CRIAPI criHeap_DebugGetWorstExtraSize(CriSint32 alignment)
{
    if (alignment < CRIHEAP_ALIGN)
    {
        alignment = CRIHEAP_ALIGN;
    }
    return alignment + CRIHEAP_BLOCK_SIZE + CRIHEAP_ALIGN;
}

// @0x140027de0
void* FUN_140027de0(void* obj, const CriChar8* msg, CriSint32 p1)
{
    return FUN_140038ce4(0, msg, p1, 0, obj);
}

// @0x140027df8
static CriSint32 criheap_DebugPrintf(const CriChar8* format, ...)
{
    char buf[0x200];
    va_list args;
    va_start(args, format);
    wvsprintfA(buf, format, args);
    OutputDebugStringA(buf);
    va_end(args);
    return 0;
}

// The library initialization without the reference count.
// @0x140027e5c
void FUN_140027e5c(void)
{
    DAT_143b278d0 = criheap_version;
    FUN_1400411f8();
    DAT_143b278e0 = FUN_140039ea8(DAT_143b278f0, sizeof(DAT_143b278f0));
    if (DAT_143b278e0 == NULL)
    {
        criErr_Notify(0, "E08021401H:Faild to create critical section.");
    }
}

// The exe updates the init count in memory and reads it back (a volatile access).
// @0x140027ea4
__declspec(noinline) void CRIAPI criHeap_Finalize(void)
{
    (*(volatile CriSint32*)&DAT_143b278d8)--;
    if (*(volatile CriSint32*)&DAT_143b278d8 == 0 && DAT_143b278e0 != NULL)
    {
        criCs_Destroy((_RTL_CRITICAL_SECTION *)DAT_143b278e0);
        DAT_143b278e0 = NULL;
    }
}

// @0x140027ed8
void* CRIAPI criHeap_AllocFix(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    if (heap->vtbl->AllocFix != NULL)
    {
        return heap->vtbl->AllocFix(heap, size, name, align);
    }
    FUN_140038ce4(0, "E05063002H", 0, 0, NULL);
    return NULL;
}

// @0x140027f0c
void* CRIAPI criHeap_AllocTemporary(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    if (heap->vtbl->AllocTemporary != NULL)
    {
        return heap->vtbl->AllocTemporary(heap, size, name, align);
    }
    FUN_140038ce4(0, "E05063003H", 0, 0, NULL);
    return NULL;
}

// @0x140027f44
void* CRIAPI criHeap_AllocDynamic(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    if (heap->vtbl->AllocDynamic != NULL)
    {
        return heap->vtbl->AllocDynamic(heap, size, name, align);
    }
    FUN_140038ce4(0, "E05063004H", 0, 0, NULL);
    return NULL;
}

// @0x140027f7c
void* CRIAPI criHeap_Alloc(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align, CriSint32 type)
{
    if (type == CRIHEAP_TYPE_FIX)
    {
        return criHeap_AllocFix(heap, size, name, align);
    }
    if (type == CRIHEAP_TYPE_TEMPORARY)
    {
        return criHeap_AllocTemporary(heap, size, name, align);
    }
    criErr_Notify(0, "E08032601H:Invalid allocation type.");
    return NULL;
}

// @0x140027fb4
CriSint32 CRIAPI criHeap_Free(CriHeap heap, void* ptr)
{
    if (heap->vtbl->Free != NULL)
    {
        return heap->vtbl->Free(heap, ptr);
    }
    FUN_140038ce4(0, "E05063005H", 0, 0, NULL);
    return 0;
}

// @0x140027fec
CriHeap CRIAPI criHeap_Create(void* ptr, CriSint32 size)
{
    CriHeap heap;
    if (size <= (CriSint32)sizeof(struct _criheap_struct))
    {
        return NULL;
    }
    memset(ptr, 0, sizeof(struct _criheap_struct));
    heap = criheap_InitializeHandle((CriHeap)ptr, size);
    heap->vtbl = &DAT_143a46430;
    return heap;
}

// @0x140028030
CriHeap CRIAPI criHeap_CreateNoSerialize(void* ptr, CriSint32 size)
{
    CriHeap heap;
    if (size <= (CriSint32)sizeof(struct _criheap_struct))
    {
        return NULL;
    }
    memset(ptr, 0, sizeof(struct _criheap_struct));
    heap = criheap_InitializeHandle((CriHeap)ptr, size);
    heap->vtbl = &DAT_143a46450;
    return heap;
}

// @0x140028074
void CRIAPI criHeap_Destroy(CriHeap heap)
{
    CriHeapBlock* blk = heap->topblock;
    do
    {
        CriHeapBlock* next = blk->nextblock;
        criheap_FreeBlock(heap, blk);
        blk = next;
    } while (blk != NULL);
}

// @0x1400280a4
void* FUN_1400280a4(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    void* mem;
    criHeap_EnterCriticalSection();
    mem = criheap_Alloc(heap, CRIHEAP_TYPE_FIX, size, name, align);
    criHeap_LeaveCriticalSection();
    return mem;
}

// @0x140028100
void* FUN_140028100(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    void* mem;
    criHeap_EnterCriticalSection();
    mem = criheap_Alloc(heap, CRIHEAP_TYPE_TEMPORARY, size, name, align);
    criHeap_LeaveCriticalSection();
    return mem;
}

// @0x14002815c
void* FUN_14002815c(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align)
{
    void* mem;
    criHeap_EnterCriticalSection();
    mem = criheap_Alloc(heap, CRIHEAP_TYPE_DYNAMIC, size, name, align);
    criHeap_LeaveCriticalSection();
    return mem;
}

// @0x1400281b8
CriSint32 FUN_1400281b8(CriHeap heap, void* ptr)
{
    CriSint32 size;
    criHeap_EnterCriticalSection();
    size = criheap_FreeNoLock(heap, ptr);
    criHeap_LeaveCriticalSection();
    return size;
}

// MS2-FUNCTIONAL: CRI Heap was compiled optimized by an older MSVC; VS2017 schedules and allocates registers differently
// @0x1400281ec
void CRIAPI criHeap_DebugPrintBlockInformationAll(CriHeap heap)
{
    CriSint32 no = 0;
    CriHeapBlock* blk = heap->topblock;
    CriSint32 total = (CriSint32)((CriUint32)(CriUint64)blk - (CriUint32)(CriUint64)heap);
    do
    {
        no++;
        total += blk->alignspc + blk->gap + blk->memsize + CRIHEAP_BLOCK_SIZE;
        criheap_DebugPrintf("%05d: MBLK:%08xH(%08xH) ", no, (CriUint32)(CriUint64)blk,
                            (CriUint16)(blk->alignspc + CRIHEAP_BLOCK_SIZE));
        criheap_DebugPrintf("PTR:%08xH(%08xH) ", (CriUint32)(CriUint64)((CriUint8*)blk + CRIHEAP_BLOCK_SIZE + blk->alignspc), blk->memsize);
        criheap_DebugPrintf("%s %s ", DAT_143a46488[blk->type], DAT_143a46478[blk->used]);
        criheap_DebugPrintf("\"%s\"\r\n", (blk->nameadr != NULL) ? blk->nameadr : DAT_143a46470);
        blk = blk->nextblock;
    } while (blk != NULL);
    criheap_DebugPrintf("TotalMemory = %08xH CurrentMemory = %08xH PeakSize = %08xH\r\n\r\n", total,
                        heap->currentsize, heap->peaksize);
}

// The exe updates the init count in memory and reads it back (a volatile access).
// @0x1400282e0
__declspec(noinline) void CRIAPI criHeap_Initialize(void)
{
    (*(volatile CriSint32*)&DAT_143b278d8)++;
    if (*(volatile CriSint32*)&DAT_143b278d8 == 1)
    {
        DAT_143b278d0 = criheap_version;
        FUN_1400411f8();
        DAT_143b278e0 = FUN_140039ea8(DAT_143b278f0, sizeof(DAT_143b278f0));
        if (DAT_143b278e0 == NULL)
        {
            criErr_Notify(0, "E08021401H:Faild to create critical section.");
        }
    }
}
#pragma optimize("", on)

} // extern "C"
