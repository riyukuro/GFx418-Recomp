// Recovered CRI Movie helpers from MapleStory2.exe, written from the executable's behavior: the five functions of the
// /Od criMvPly objs whose exe objs were compiled as C. VS2008 /Od keeps a value loaded after a call in r11 when it
// compiles C and in rax when it compiles C++ (FUN_14003cff0 also takes its switch temp through r11b), and these five
// only byte-match as C. The rest of those objs is in sfr_cri_03, which
// can't be C (cri_movie.h is C++). This unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1 cl with /TC,
// cmake/ms2-unit-profiles.cmake): no headers, C89 declarations at the top of each block, and the parameter types of
// the definitions in sfr_cri_02c/03/03a/03b, so a C++ compile (clang-cl) mangles every name as they do.
// MS2-UNIT: sfr_cri_03d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14003c390-0x14003c8d0 .text$mn
// MS2-RANGE: 0x14003cff0-0x14003d4b0 .text$mn
// MS2-RANGE: 0x14003ed40-0x14003eeb0 .text$mn
// MS2-RANGE: 0x140042270-0x140042600 .text$mn
// MS2-RANGE: 0x140042700-0x1400427b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

typedef unsigned char CriUint8;
typedef unsigned long CriUint32;
typedef long CriSint32;

// the C++ units define these with C linkage (extern "C"), so the clang-cl C++ compile declares them so too
#ifdef __cplusplus
#define CRI_C_LINKAGE extern "C"
#else
#define CRI_C_LINKAGE
#endif

struct CriUsfStandardHeader;
typedef struct CriUsfHeaderFields { CriUint32 ChunkId, Size, Word08; CriUint8 Byte0C, Byte0D, Byte0E, Kind; CriUint32 Words[5]; } CriUsfHeaderFields;
typedef struct CriVideoQueueFields { CriUint8 Reserved00[0x180]; void* InputQueue; } CriVideoQueueFields;

CRI_C_LINKAGE void criSj_GetChunk(void* object, CriSint32 operation, CriUint32 limit, void* output);
CRI_C_LINKAGE void criSj_UngetChunk(void* object, CriSint32 operation, void* chunk);
CRI_C_LINKAGE void criSj_PutChunk(void* object, CriSint32 operation, void* chunk);
CRI_C_LINKAGE CriSint32 FUN_1400467b8(void* object, CriSint32 query);
CRI_C_LINKAGE void criMvPly_SetDemuxOutputSj(void* player, void* value, CriUint32 type, CriUint32 flags);
CRI_C_LINKAGE CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, struct CriUsfStandardHeader* header);
CRI_C_LINKAGE CriSint32 FUN_14003eeb0(const void* input);
CRI_C_LINKAGE CriSint32 FUN_14003d6c0(const void* input);
CRI_C_LINKAGE void crivmpv_occurFatalError(void* owner, const char* message, CriUint32 value);
CRI_C_LINKAGE void mvPlyAdec_StartAudioDecoder(CriSint32* state, void* input);
CRI_C_LINKAGE void FUN_140043970(void* track, void* player);
CRI_C_LINKAGE void FUN_14003d550(void* handle);
// the C name binds to sfr_cri_03a's C++ definition in the full exe (the FUN_<va> names above are aliased by their VA; this
// one has none, so the link left it to a trap stub); the hook DLL's ms2sym.obj already maps it to the exe address
#ifndef MS2_HOOK_DLL
#endif

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
typedef struct DemuxPlayerFields
{
    CriUint8 Reserved00[0x180];
    void* Queue;
    CriUint32 Chunks;
    CriUint32 Chunks2;
    CriUint8 Reserved190[0x18];
    CriSint32 Phase;
    CriSint32 PhaseFlag;
    CriSint32 Metas;
    CriUint8 Reserved1b4[0x4c];
    CriSint32 (*HeaderCallback)(void*, void*);
    void* HeaderArg;
    void (*EndCallback)(void*);
    void* EndArg;
} DemuxPlayerFields;

// pull one demuxed chunk from a video player's input queue and advance its decode state machine
// @0x14003cff0
CriSint32 FUN_14003cff0(void* player)
{
    typedef struct Chunk { const CriUint8* Data; CriUint32 Size; CriSint32 Reserved; } Chunk;
    // locals named so vc9's name-hash slot order matches the exe's
    CriSint32 code;
    Chunk chunk;
    Chunk second;
    CriUsfHeaderFields header;
    CriUsfHeaderFields uhdr;
    CriSint32 accepted;
    CriSint32 lane;
    code = 0;
    if ((CriUint32)FUN_1400467b8(((DemuxPlayerFields*)player)->Queue, 1) <= 0)
        return code;
    criSj_GetChunk(((DemuxPlayerFields*)player)->Queue, 1, 0xffffffff, &chunk);
    second.Data = 0;
    criUsfCmn_ParseUsfHeaderStd(chunk.Data, chunk.Size, (struct CriUsfStandardHeader*)&header);
    switch (header.Kind)
    {
    case 0:
        ((DemuxPlayerFields*)player)->Phase = 3;
        if (FUN_14003d6c0(&chunk) != 0)
        {
            if ((CriUint32)FUN_1400467b8(((DemuxPlayerFields*)player)->Queue, 1) > 0)
            {
                criSj_GetChunk(((DemuxPlayerFields*)player)->Queue, 1, 0xffffffff, &second);
                criUsfCmn_ParseUsfHeaderStd(chunk.Data, chunk.Size, (struct CriUsfStandardHeader*)&uhdr);
                if (chunk.Size + second.Size < uhdr.Size + 8)
                {
                    crivmpv_occurFatalError(0, "E07111401M : Video chunk might not be demuxed properly..\n", 0);
                }
                else
                {
                    criSj_PutChunk(((DemuxPlayerFields*)player)->Queue, 2, &chunk);
                    criSj_PutChunk(((DemuxPlayerFields*)player)->Queue, 2, &second);
                }
            }
            else
            {
                criSj_UngetChunk(((DemuxPlayerFields*)player)->Queue, 1, &chunk);
                return code;
            }
        }
        else
        {
            criSj_PutChunk(((DemuxPlayerFields*)player)->Queue, 2, &chunk);
        }
        ((DemuxPlayerFields*)player)->Chunks = ((DemuxPlayerFields*)player)->Chunks + 1;
        ((DemuxPlayerFields*)player)->Chunks2 = ((DemuxPlayerFields*)player)->Chunks2 + 1;
        code = 1;
        break;
    case 1:
        ((DemuxPlayerFields*)player)->Phase = 1;
        if (((DemuxPlayerFields*)player)->HeaderCallback != 0)
        {
            accepted = ((DemuxPlayerFields*)player)->HeaderCallback(((DemuxPlayerFields*)player)->HeaderArg, &chunk);
            if (accepted == 1)
            {
            }
            else
            {
                criSj_UngetChunk(((DemuxPlayerFields*)player)->Queue, 1, &chunk);
                return code;
            }
        }
        break;
    case 3:
        ((DemuxPlayerFields*)player)->Phase = 2;
        if (FUN_14003d6c0(&chunk) != 0)
        {
            if ((CriUint32)FUN_1400467b8(((DemuxPlayerFields*)player)->Queue, 1) > 0)
            {
                criSj_GetChunk(((DemuxPlayerFields*)player)->Queue, 1, 0xffffffff, &second);
                criUsfCmn_ParseUsfHeaderStd(chunk.Data, chunk.Size, (struct CriUsfStandardHeader*)&uhdr);
                if (chunk.Size + second.Size < uhdr.Size + 8)
                    crivmpv_occurFatalError(0, "E08121601M : Video meta chunk might not be demuxed properly.\n", 0);
            }
            else
            {
                criSj_UngetChunk(((DemuxPlayerFields*)player)->Queue, 1, &chunk);
                return code;
            }
        }
        break;
    case 2:
        if (((DemuxPlayerFields*)player)->Phase == 1)
        {
            ((DemuxPlayerFields*)player)->PhaseFlag = 0;
            if (((DemuxPlayerFields*)player)->EndCallback != 0)
                ((DemuxPlayerFields*)player)->EndCallback(((DemuxPlayerFields*)player)->EndArg);
        }
        if (((DemuxPlayerFields*)player)->Phase == 3)
        {
            FUN_14003d550(player);
            ((DemuxPlayerFields*)player)->Metas = ((DemuxPlayerFields*)player)->Metas + 1;
        }
        break;
    }
    switch (header.Kind)
    {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
        if (((DemuxPlayerFields*)player)->Chunks == 0)
            lane = 0;
        else
            lane = 2;
        criSj_PutChunk(((DemuxPlayerFields*)player)->Queue, lane, &chunk);
        if (second.Data != 0)
            criSj_PutChunk(((DemuxPlayerFields*)player)->Queue, lane, &second);
        break;
    }
    return code;
}

// drain the demuxed chunk queue of a video player, counting the chunks it consumes
// @0x14003ed40
CriSint32 FUN_14003ed40(void* player)
{
    typedef struct Chunk { const CriUint8* Data; CriUint32 Size; CriSint32 Reserved; } Chunk;
    // locals named so vc9's name-hash slot order matches the exe's
    CriSint32 count;
    CriUsfHeaderFields uhdr;
    void* stream;
    Chunk cur;
    Chunk second;
    count = 0;
    stream = ((CriVideoQueueFields*)player)->InputQueue;
    while ((CriUint32)FUN_1400467b8(stream, 2) > 0)
    {
        second.Data = 0;
        criSj_GetChunk(stream, 2, 0xffffffff, &cur);
        if (FUN_14003eeb0(&cur) == 0)
        {
            if (FUN_14003d6c0(&cur) != 0)
            {
                if ((CriUint32)FUN_1400467b8(stream, 2) > 0)
                {
                    criSj_GetChunk(stream, 2, 0xffffffff, &second);
                    criUsfCmn_ParseUsfHeaderStd(cur.Data, cur.Size, (struct CriUsfStandardHeader*)&uhdr);
                    if (cur.Size + second.Size < uhdr.Size + 8)
                        crivmpv_occurFatalError(0, "E08121602M : Video chunk might not be demuxed properly.\n", 0);
                }
                else
                {
                    criSj_UngetChunk(stream, 2, &cur);
                    break;
                }
            }
            criSj_PutChunk(stream, 0, &cur);
            if (second.Data != 0)
                criSj_PutChunk(stream, 0, &second);
            count = count + 1;
        }
        else
        {
            criSj_UngetChunk(stream, 2, &cur);
            break;
        }
    }
    return count;
}

typedef struct AudioTrackSet { void* Tracks[2]; CriSint32 Count; void* Configuration; } AudioTrackSet;
typedef struct TrackControl { CriUint32 Reserved; CriUint32 Control; } TrackControl;
typedef struct PlayerState { CriUint8 Reserved00[0xe58]; CriSint32 ParameterUpdateEnabled; } PlayerState;

// reset every audio track in a player and apply updated decoder parameters when enabled
// @0x140042700
void FUN_140042700(void* trackSet, void* player)
{
    CriSint32 index;
    if (((AudioTrackSet*)trackSet)->Tracks[0])
    {
        criMvPly_SetDemuxOutputSj(player, ((AudioTrackSet*)trackSet)->Configuration,
                      ((TrackControl*)((AudioTrackSet*)trackSet)->Tracks[0])->Control, (CriUint32)-1);
    }
    for (index = 0; index < ((AudioTrackSet*)trackSet)->Count; ++index)
    {
        mvPlyAdec_StartAudioDecoder((CriSint32*)((AudioTrackSet*)trackSet)->Tracks[index], player);
        if (((PlayerState*)player)->ParameterUpdateEnabled > 0)
            FUN_140043970(((AudioTrackSet*)trackSet)->Tracks[index], player);
    }
}
#pragma optimize("", on)

// C linkage in the C++ compile (clang-cl) too, as the other units declare them
#ifdef __cplusplus
extern "C" {
#endif
void* criHeap_AllocFix(void* heap, CriSint32 size, const char* name, CriSint32 align);
void* memset(void* dest, int value, unsigned __int64 count);
extern CriUint32 DAT_143b27c60;
#ifdef __cplusplus
}
#endif
#pragma function(memset)                     // the exe calls memset out of line
void criVmpv_Destroy(void* handle);
CRI_C_LINKAGE void* criSj_CreateUniversal(void* heap, CriUint32 first, CriUint32 second);
CRI_C_LINKAGE CriSint32 createMpvHn(void* handle, void* heap, CriUint32 width, CriUint32 height, CriUint32 frames);
CRI_C_LINKAGE CriSint32 decideInternalFramePoolNum(CriSint32 count);
CRI_C_LINKAGE unsigned __int64 SJRBF_Create(unsigned __int64 source, unsigned int first, unsigned int second);
CRI_C_LINKAGE void FUN_140041110(void* owner, const char* message, CriUint32 value);
// the C names bind to sfr_cri_03's C++ definitions, and its C++ caller's name to the C definition below
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:criVmpv_Destroy=?criVmpv_Destroy@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?criVmpv_Create@@YAPEAXPEAXPEBK@Z=criVmpv_Create")
#endif

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
typedef struct VmpvFields
{
    CriUint8 Reserved00[8];
    CriSint32 Active;
    CriUint8 Reserved0C[4];
    void* Heap;
    CriSint32 Status;
    CriUint8 Reserved1C[0xc];
    CriUint32 Width;
    CriUint32 Height;
    CriUint32 Frames;
    CriUint32 PoolBase;
    CriUint32 Format;
    CriUint32 PoolNum;
    CriUint32 FrameBytes;
    CriUint8 Reserved44[4];
    CriUint8* Records;
    CriUint32 RecordBytes;
    CriUint8 Reserved54[4];
    void* FrameSj;
    CriUint8 Reserved60[0x10];
    void* Pending;
    CriUint8 Reserved78[0x108];
    void* InputSj;
    CriUint8 Reserved188[0x28];
    CriSint32 Queued;
    CriSint32 Lanes[8][2];
    CriSint32 LaneCount;
    CriUint8 Reserved1f8[0x28];
    void* Decoder;
    void* Source;
    CriUint32 OptionA;
    CriUint32 OptionB;
    CriSint32 Word238;
    CriSint32 Word23C;
} VmpvFields;

// build a VMPV handle with its decoder instance, frame pool, and stream joints
// @0x14003c390
void* criVmpv_Create(void* heap, const CriUint32* config)
{
    // locals named so vc9's name-hash slot order matches the exe's (names that share a bucket are declared in
    // reverse slot order): width, height, frames, the MPEG source and its two options
    CriUint32 width = config[0];
    CriUint32 height = config[1];
    CriUint32 chunks = config[4];
    void* input = *(void* const*)(config + 6);
    CriUint32 total = config[8];
    CriUint32 size = config[9];
    VmpvFields* hn;
    CriUint32 i;
    if (!heap)
        return 0;
    hn = (VmpvFields*)criHeap_AllocFix(heap, 600, "CriVmpv: HnObj", 4);
    if (!hn)
    {
        FUN_140041110(0, "E05070701M : Can't allocate vmpv handle object memory.", 600);
        return 0;
    }
    memset(hn, 0, 600);
    hn->Heap = heap;
    if (createMpvHn(hn, heap, width, height, chunks) != 1)
    {
        criVmpv_Destroy(hn);
        return 0;
    }
    hn->InputSj = criSj_CreateUniversal(heap, 0, 0x20);
    if (hn->InputSj == 0)
    {
        crivmpv_occurFatalError(0, "E05070702M : Can't create SJ for input video.", 0);
        criVmpv_Destroy(hn);
        return 0;
    }
    hn->Width = width;
    hn->Height = height;
    hn->Frames = decideInternalFramePoolNum(chunks);
    hn->PoolBase = DAT_143b27c60;
    hn->Format = 0x7512;
    hn->PoolNum = hn->Frames;
    hn->FrameBytes = ((hn->Width + 0xf) / 0x10 * 0x10 + 0x7f) / 0x80 * 0x80 * ((hn->Height + 0x1f) / 0x20 * 0x20)
                   + ((hn->Width + 0xf) / 0x10 * 0x10 / 2 + 0x7f) / 0x80 * 0x80 * ((hn->Height + 0x1f) / 0x20 * 0x20 / 2) * 2;
    hn->RecordBytes = 200;
    hn->Records = (CriUint8*)criHeap_AllocFix(heap, hn->RecordBytes * hn->PoolNum, "CriVmpv: FrmPoolInfoAry", 4);
    if (hn->Records == 0)
    {
        FUN_140041110(0, "E05092801M : Can't allocate frame pool info array memory.", hn->RecordBytes * hn->PoolNum);
        criVmpv_Destroy(hn);
        return 0;
    }
    memset(hn->Records, 0, hn->RecordBytes * hn->PoolNum);
    for (i = 0; i < hn->PoolNum; i++)
    {
        *(void**)(hn->Records + (unsigned __int64)i * 200) = criHeap_AllocFix(heap, hn->FrameBytes, "CriVmpv: FrmPoolBuf", 0x800);
        if (*(void**)(hn->Records + (unsigned __int64)i * 200) == 0)
        {
            FUN_140041110(0, "E05070902M : Can't allocate frame pool memory.", hn->FrameBytes);
            criVmpv_Destroy(hn);
            return 0;
        }
        *(CriUint32*)(hn->Records + (unsigned __int64)i * 200 + 8) = hn->FrameBytes;
    }
    hn->FrameSj = criSj_CreateUniversal(heap, 0, hn->PoolNum);
    if (hn->FrameSj == 0)
    {
        crivmpv_occurFatalError(0, "E05070903M : Can't create frame pool SJ.", 0);
        criVmpv_Destroy(hn);
        return 0;
    }
    hn->Pending = 0;
    hn->Queued = 0;
    for (i = 0; i < 8; i++)
    {
        hn->Lanes[i][0] = 0;
        hn->Lanes[i][1] = 0;
    }
    hn->LaneCount = 0;
    if (input != 0)
        hn->Decoder = (void*)SJRBF_Create((unsigned __int64)input, total, size);
    else
        hn->Decoder = 0;
    hn->Source = input;
    hn->OptionA = total;
    hn->OptionB = size;
    hn->Word238 = 0;
    hn->Word23C = 0;
    hn->Status = 0;
    hn->Active = 1;
    return hn;
}
#pragma optimize("", on)

CRI_C_LINKAGE void criMvPlyAmng_DestroyAudioDecoder(void* manager, void* heap, CriSint32 decoderIndex);
CRI_C_LINKAGE void* criSj_CreateNamedRingBuffer(void* heap, CriUint32 first, CriUint32 second, CriUint32 third, unsigned __int64 name);
CRI_C_LINKAGE unsigned __int64* criAdec_Create(unsigned __int64 heap, unsigned int channels, unsigned int mode);
CRI_C_LINKAGE void FUN_1400534d0(void* decoder);
CRI_C_LINKAGE void criAdec_SetInputSj(__int64 decoder, unsigned __int64 input);
CRI_C_LINKAGE void criAdec_SetOutputSj(__int64 decoder, unsigned int channel, unsigned __int64 output);
CRI_C_LINKAGE void crimvply_occurFatalError(void* owner, const char* message, CriSint32 value);
CRI_C_LINKAGE void crimvply_occurUserError(void* owner, const char* message, CriSint32 value);
#ifndef MS2_HOOK_DLL
#endif

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
typedef struct AudioStreamFields { CriUint8 Reserved00[0x64c]; struct { CriUint32 Enabled; CriUint8 Reserved04[0xc]; } Streams[1]; } AudioStreamFields;
typedef struct AudioOwnerFields { CriUint8 Reserved00[0xe18]; CriUint32 OutputMode; CriUint32 Width; } AudioOwnerFields;
typedef struct AudioDecoderFields
{
    CriUint32 State;
    CriUint32 Signature;
    CriUint32 StreamIndex;
    CriUint8 Reserved0C[4];
    void* Decoder;
    CriUint32 ChannelCount;
    CriUint32 ChannelFormat;
    CriUint32 WorkCount;
    CriUint8 Reserved24[4];
    void* InputJoint;
    void* Outputs[8];
    CriUint32 Sizes[8];
    CriSint32 Word90;
    CriUint8 Reserved94[4];
} AudioDecoderFields;

// allocate and wire one CRI audio decoder into the manager's channel table
// @0x140042270
CRI_C_LINKAGE CriSint32 criMvPlyAmng_CreateAudioDecoder(void* manager, void* owner, void* heap, const CriUint32* decoderConfig,
                      CriUint32 streamIndex, CriSint32 decoderIndex)
{
    // locals named so vc9's name-hash slot order matches the exe's (names that share a bucket are declared in
    // reverse slot order): the chunk bytes, the channel, the audio decoder, the per-channel samples, the handle and
    // the stream bytes
    CriUint32 chk;
    CriUint32 i;
    void* ptr;
    AudioDecoderFields* hn;
    CriUint32 size;
    CriUint32 bytes;
    if (((AudioStreamFields*)owner)->Streams[streamIndex].Enabled <= 0)
        return 0;
    hn = (AudioDecoderFields*)criHeap_AllocFix(heap, 0x98, "CriMvPly: CriMvPlyAdecObj", 4);
    ((AudioTrackSet*)manager)->Tracks[decoderIndex] = hn;
    if (hn == 0)
    {
        criMvPlyAmng_DestroyAudioDecoder(manager, heap, decoderIndex);
        crimvply_occurUserError(owner, "E07090702M : Can't allocate CriMvPlyAdec handle.", 8);
        return 0;
    }
    memset(hn, 0, 0x98);
    hn->State = 1;
    hn->Word90 = 0;
    hn->Signature = 0x40534641;
    hn->StreamIndex = streamIndex;
    hn->ChannelCount = decoderConfig[1];
    hn->ChannelFormat = decoderConfig[0];
    hn->WorkCount = decoderConfig[3];
    if (((AudioOwnerFields*)owner)->OutputMode == 0)
        ptr = criAdec_Create((unsigned __int64)heap, hn->ChannelCount, 0);
    else
        ptr = criAdec_Create((unsigned __int64)heap, hn->ChannelCount, 1);
    hn->Decoder = ptr;
    if (ptr == 0)
    {
        criMvPlyAmng_DestroyAudioDecoder(manager, heap, decoderIndex);
        crimvply_occurFatalError(owner, "E05063014M : Can't create Audio decoder.", 0);
        return 0;
    }
    FUN_1400534d0(ptr);
    hn->InputJoint = ((AudioTrackSet*)manager)->Configuration;
    for (i = 0; i < hn->ChannelCount; i++)
    {
        size = ((AudioOwnerFields*)owner)->Width * 0xc80 / decoderConfig[1];
        bytes = decoderConfig[3] * ((AudioOwnerFields*)owner)->Width + size * ((AudioOwnerFields*)owner)->Width;
        chk = ((AudioOwnerFields*)owner)->Width * 0x840;
        hn->Sizes[i] = bytes + chk;
        hn->Outputs[i] = criSj_CreateNamedRingBuffer(heap, bytes, chk, 4, (unsigned __int64)"CriMvPly: AoutBuf");
        if (hn->Outputs[i] == 0)
        {
            criMvPlyAmng_DestroyAudioDecoder(manager, heap, decoderIndex);
            crimvply_occurFatalError(owner, "E05063018M : Can't create SJ for output audio.", 0);
            return 0;
        }
    }
    criAdec_SetInputSj((__int64)ptr, (unsigned __int64)hn->InputJoint);
    for (i = 0; i < hn->ChannelCount; i++)
        criAdec_SetOutputSj((__int64)ptr, i, (unsigned __int64)hn->Outputs[i]);
    ((AudioTrackSet*)manager)->Count = ((AudioTrackSet*)manager)->Count + 1;
    return 1;
}
#pragma optimize("", on)
