// Recovered CRI Movie helpers from MapleStory2.exe, written from the executable's behavior: the three functions of the
// /Od criMvPly objs whose exe objs were compiled as C. VS2008 /Od keeps a value loaded after a call in r11 when it
// compiles C and in rax when it compiles C++ (FUN_14003cff0 also takes its switch temp through r11b), and these three
// only byte-match as C. The rest of those objs is in sfr_cri_03, which
// can't be C (cri_movie.h is C++). This unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1 cl with /TC,
// cmake/ms2-unit-profiles.cmake): no headers, C89 declarations at the top of each block, and the parameter types of
// the definitions in sfr_cri_02c/03/03a/03b, so a C++ compile (clang-cl) mangles every name as they do.
// MS2-UNIT: sfr_cri_03d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14003cff0-0x14003d4b0 .text$mn
// MS2-RANGE: 0x14003ed40-0x14003eeb0 .text$mn
// MS2-RANGE: 0x140042700-0x1400427b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

typedef unsigned char CriUint8;
typedef unsigned long CriUint32;
typedef long CriSint32;

struct CriUsfStandardHeader;
typedef struct CriUsfHeaderFields { CriUint32 ChunkId, Size, Word08; CriUint8 Byte0C, Byte0D, Byte0E, Kind; CriUint32 Words[5]; } CriUsfHeaderFields;
typedef struct CriVideoQueueFields { CriUint8 Reserved00[0x180]; void* InputQueue; } CriVideoQueueFields;

void criSj_GetChunk(void* object, CriSint32 operation, CriUint32 limit, void* output);
void criSj_UngetChunk(void* object, CriSint32 operation, void* chunk);
void criSj_PutChunk(void* object, CriSint32 operation, void* chunk);
CriSint32 FUN_1400467b8(void* object, CriSint32 query);
void criMvPly_SetDemuxOutputSj(void* player, void* value, CriUint32 type, CriUint32 flags);
CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, struct CriUsfStandardHeader* header);
CriSint32 FUN_14003eeb0(const void* input);
CriSint32 FUN_14003d6c0(const void* input);
void FUN_1400410d0(void* owner, const char* message, CriUint32 value);
void mvPlyAdec_StartAudioDecoder(CriSint32* state, void* input);
void FUN_140043970(void* track, void* player);
void FUN_14003d550(void* handle);
// the C name binds to sfr_cri_03a's C++ definition in the full exe (the FUN_<va> names above are aliased by their VA; this
// one has none, so the link left it to a trap stub); the hook DLL's ms2sym.obj already maps it to the exe address
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:criUsfCmn_ParseUsfHeaderStd=?criUsfCmn_ParseUsfHeaderStd@@YAKPEBEKPEAUCriUsfStandardHeader@@@Z")
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
                    FUN_1400410d0(0, "E07111401M : Video chunk might not be demuxed properly..\n", 0);
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
                    FUN_1400410d0(0, "E08121601M : Video meta chunk might not be demuxed properly.\n", 0);
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
                        FUN_1400410d0(0, "E08121602M : Video chunk might not be demuxed properly.\n", 0);
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
