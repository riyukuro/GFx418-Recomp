// Recovered CRI Movie helpers from MapleStory2.exe, written from the executable's behavior: the two functions of the /Od
// criMvPly objs whose exe objs were compiled as C. VS2008 /Od keeps a value loaded after a call in r11 when it compiles
// C and in rax when it compiles C++, and these two only byte-match as C. The rest of those objs is in sfr_cri_03, which
// can't be C (cri_movie.h is C++). This unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1 cl with /TC,
// cmake/ms2-unit-profiles.cmake): no headers, C89 declarations at the top of each block, and the parameter types of
// the definitions in sfr_cri_02c/03/03a/03b, so a C++ compile (clang-cl) mangles every name as they do.
// MS2-UNIT: sfr_cri_03d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
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

void FUN_1400467a0(void* object, CriSint32 operation, CriUint32 limit, void* output);
void FUN_1400467a8(void* object, CriSint32 operation, void* chunk);
void FUN_1400467b0(void* object, CriSint32 operation, void* chunk);
CriSint32 FUN_1400467b8(void* object, CriSint32 query);
void FUN_1400345e0(void* player, void* value, CriUint32 type, CriUint32 flags);
CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, struct CriUsfStandardHeader* header);
CriSint32 FUN_14003eeb0(const void* input);
CriSint32 FUN_14003d6c0(const void* input);
void FUN_1400410d0(void* owner, const char* message, CriUint32 value);
void FUN_140043550(CriSint32* state, void* input);
void FUN_140043970(void* track, void* player);
// the C name binds to sfr_cri_03a's C++ definition in the full exe (the FUN_<va> names above are aliased by their VA; this
// one has none, so the link left it to a trap stub); the hook DLL's ms2sym.obj already maps it to the exe address
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:criUsfCmn_ParseUsfHeaderStd=?criUsfCmn_ParseUsfHeaderStd@@YAKPEBEKPEAUCriUsfStandardHeader@@@Z")
#endif

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
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
        FUN_1400467a0(stream, 2, 0xffffffff, &cur);
        if (FUN_14003eeb0(&cur) == 0)
        {
            if (FUN_14003d6c0(&cur) != 0)
            {
                if ((CriUint32)FUN_1400467b8(stream, 2) > 0)
                {
                    FUN_1400467a0(stream, 2, 0xffffffff, &second);
                    criUsfCmn_ParseUsfHeaderStd(cur.Data, cur.Size, (struct CriUsfStandardHeader*)&uhdr);
                    if (cur.Size + second.Size < uhdr.Size + 8)
                        FUN_1400410d0(0, "E08121602M : Video chunk might not be demuxed properly.\n", 0);
                }
                else
                {
                    FUN_1400467a8(stream, 2, &cur);
                    break;
                }
            }
            FUN_1400467b0(stream, 0, &cur);
            if (second.Data != 0)
                FUN_1400467b0(stream, 0, &second);
            count = count + 1;
        }
        else
        {
            FUN_1400467a8(stream, 2, &cur);
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
        FUN_1400345e0(player, ((AudioTrackSet*)trackSet)->Configuration,
                      ((TrackControl*)((AudioTrackSet*)trackSet)->Tracks[0])->Control, (CriUint32)-1);
    }
    for (index = 0; index < ((AudioTrackSet*)trackSet)->Count; ++index)
    {
        FUN_140043550((CriSint32*)((AudioTrackSet*)trackSet)->Tracks[index], player);
        if (((PlayerState*)player)->ParameterUpdateEnabled > 0)
            FUN_140043970(((AudioTrackSet*)trackSet)->Tracks[index], player);
    }
}
#pragma optimize("", on)
