// Recovered CRI Movie helpers from MapleStory2.exe, written from the executable's behavior: the functions of the /Od
// criMvPly objs in sfr_cri_02c's range that only byte-match as C. VS2008 /Od often keeps a value loaded after a call
// in r11 when it compiles C where it picks rax or rcx when it compiles C++ (cf. sfr_cri_03d). The rest of the criMvPly
// layer stays in sfr_cri_02c, which can't be C (cri_movie.h is C++). This unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1
// cl with /TC, cmake/ms2-unit-profiles.cmake): only string.h, C89 declarations at the top of each block, and the
// parameter types of the definitions in sfr_cri_02c, so a C++ compile (clang-cl) mangles every name as they do.
// MS2-UNIT: sfr_cri_02d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140030cb0-0x140030e50 .text$mn
// MS2-RANGE: 0x1400356a0-0x140035710 .text$mn
// MS2-RANGE: 0x140035800-0x1400358d0 .text$mn
// MS2-RANGE: 0x140036470-0x140036590 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <string.h>
#pragma function(memset, memcpy)                // the exe CRI objs call memset and memcpy here

typedef unsigned char CriUint8;
typedef unsigned long CriUint32;
typedef long CriSint32;
typedef unsigned __int64 CriUint64;
typedef CriSint32 CriBool;

struct CriMvFrameInfo;
struct CriMvAlphaDecoderFrameInfo;
typedef struct CriMvDecoderHandleFields { CriUint8 Reserved00[0xe40]; void* AlphaDecoder; } CriMvDecoderHandleFields;
typedef struct CriMvSubtitleFields
{
    CriUint8 Reserved[0xe28];
    void* Queue;
    CriSint32 SubtitleIndex;
    CriSint32 SubtitleChannel;
} CriMvSubtitleFields;
typedef struct CriMvSubtitleChunk
{
    const CriUint8* Data;
    CriUint32 Size;
    CriUint32 Reserved;
} CriMvSubtitleChunk;

void FUN_140028074(void* heap);
void FUN_1400420b0(void* manager, void* heap);
void FUN_140043be0(void* decoder);
void FUN_140044560(CriUint64* adapter);
void FUN_140046784(void* streamJoint);
CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* chunk, CriSint32 channel);
void FUN_140036e30(void* player, CriMvSubtitleChunk* chunk);
void FUN_140036e80(void* player, CriMvSubtitleChunk* chunk);
void FUN_140036f40(void* player, CriMvSubtitleChunk* chunk, void* outputInfo);
CriBool FUN_140037a10(void);
void FUN_140035260(void* player, void* output, const void* frameInfo, CriUint64 firstWord, CriUint32 flags);
void FUN_140035480(void* player, void* destination, const void* source);
void* FUN_140043fe0(void* decoder, void* frameInfo);
void crimvply_clearAlphaFrameInfoMembers(void* info);
CriBool crimvply_isUnderGetFrameCondition(void* player);
void crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(void* player, const struct CriMvAlphaDecoderFrameInfo* info);
// the C names bind to sfr_cri_02c's C++ definitions in the full exe (alias.py pairs only FUN_<va> names by their VA);
// the hook DLL's ms2sym.obj already maps them to the exe addresses; the C++ callers' mangled names of this unit's two
// definitions (sfr_cri_02c, sfr_cri_07) bind to the plain C names the same way
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:?FUN_140030cb0@@YAXPEAX@Z=FUN_140030cb0")
#pragma comment(linker, "/alternatename:?criMvPly_GetSubtitle@@YAXPEAX0K0@Z=criMvPly_GetSubtitle")
#pragma comment(linker, "/alternatename:?FUN_1400356a0@@YAXPEAX00PEBUCriMvFrameInfo@@PEBX@Z=FUN_1400356a0")
#pragma comment(linker, "/alternatename:?FUN_140035800@@YAJPEAX00@Z=FUN_140035800")
#pragma comment(linker, "/alternatename:crimvply_clearAlphaFrameInfoMembers=?crimvply_clearAlphaFrameInfoMembers@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:crimvply_isUnderGetFrameCondition=?crimvply_isUnderGetFrameCondition@@YAJPEAX@Z")
#pragma comment(linker, "/alternatename:crimvply_updateMvPlyYuvBuffersFromAlphadecInfo=?crimvply_updateMvPlyYuvBuffersFromAlphadecInfo@@YAXPEAXPEBUCriMvAlphaDecoderFrameInfo@@@Z")
#endif

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// release every CRI Movie player subsystem and clear its owned state
// @0x140030cb0
void FUN_140030cb0(void* player)
{
    void* heap;
    void* handle;
    CriUint8* dst;
    heap = *(void**)((CriUint8*)player + 0xdf0);
    if (*(void**)((CriUint8*)player + 0xe28))
    {
        FUN_140046784(*(void**)((CriUint8*)player + 0xe28));
        *(void**)((CriUint8*)player + 0xe28) = 0;
    }
    if (*(void**)((CriUint8*)player + 0xe10))
    {
        FUN_1400420b0(*(void**)((CriUint8*)player + 0xe10), heap);
        *(void**)((CriUint8*)player + 0xe10) = 0;
    }
    if (*(void**)((CriUint8*)player + 0xe40))
    {
        FUN_140043be0(*(void**)((CriUint8*)player + 0xe40));
        *(void**)((CriUint8*)player + 0xe40) = 0;
    }
    if (*(void**)((CriUint8*)player + 0xe08))
    {
        FUN_140044560(*(CriUint64**)((CriUint8*)player + 0xe08));
        *(void**)((CriUint8*)player + 0xe08) = 0;
    }
    handle = *(void**)((CriUint8*)player + 0xd88);
    if (handle)
    {
        FUN_140046784(handle);
        *(CriUint32*)((CriUint8*)player + 0xdf8) = 0;
        *(CriUint32*)((CriUint8*)player + 0xdfc) = 0;
        *(void**)((CriUint8*)player + 0xd88) = 0;
    }
    dst = (CriUint8*)player + 0xad8;
    memset(dst, 0, 0x288);
    if (*(void**)((CriUint8*)player + 0xee0))
    {
        FUN_140028074(*(void**)((CriUint8*)player + 0xee0));
        *(void**)((CriUint8*)player + 0xee0) = 0;
    }
    *(CriUint32*)((CriUint8*)player + 0xad4) = 0;
}

// copy the decoded frame metadata and add the alpha frame metadata when available
// @0x1400356a0
void FUN_1400356a0(void* player, void* output, void* alphaOutput,
                   const struct CriMvFrameInfo* frameInfo, const void* alphaInfo)
{
    FUN_140035260(player, output, frameInfo, *(const CriUint64*)frameInfo,
                  *(const CriUint32*)((const CriUint8*)frameInfo + 0x0c));
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        FUN_140035480(player, alphaOutput, alphaInfo);
}

// get the current alpha frame only while the movie is in a frame-producing state
// @0x140035800
CriBool FUN_140035800(void* player, void* movieYuvState, void* outputInfo)
{
    CriBool result;
    CriUint64 frameInfo[10];
    void* frame;
    result = 0;
    crimvply_clearAlphaFrameInfoMembers(outputInfo);
    if (!((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        return 0;
    if (!crimvply_isUnderGetFrameCondition(player))
        return 0;
    frame = FUN_140043fe0(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
    if (frame != 0)
    {
        FUN_140035480(player, outputInfo, frameInfo);
        crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(movieYuvState,
            (const struct CriMvAlphaDecoderFrameInfo*)frameInfo);
        result = 1;
    }
    return result;
}

// read the selected USF subtitle chunk, decode its metadata, and copy its text into caller storage
// @0x140036470
void criMvPly_GetSubtitle(void* player, void* destination, CriUint32 capacity, void* outputInfo)
{
    CriMvSubtitleChunk chunk;  // FUN_140036b80 clears it
    CriUint32 count;
    memset(outputInfo, 0, 0x38);
    ((CriUint64*)outputInfo)[2] = 1;
    if (!player)
        return;
    if (!((CriMvSubtitleFields*)player)->Queue)
        return;
    FUN_140036b80(player, &chunk, ((CriMvSubtitleFields*)player)->SubtitleChannel);
    if (!chunk.Data || chunk.Size < 0x20)
    {
        FUN_140036e80(player, &chunk);
        return;
    }
    FUN_140036f40(player, &chunk, outputInfo);
    FUN_140037a10();
    memset(destination, 0, capacity);
    if (((CriUint32*)outputInfo)[2] > capacity)
        count = capacity;
    else
        count = ((CriUint32*)outputInfo)[2];
    memcpy(destination, *(void**)outputInfo, count);
    FUN_140036e30(player, &chunk);
}
#pragma optimize("", on)
