// Recovered CRI Movie helpers from MapleStory2.exe, written from the executable's behavior: the two functions of the /Od
// criMvPly objs in sfr_cri_02c's range that only byte-match as C. VS2008 /Od keeps a value loaded after a call in r11
// when it compiles C and in rax when it compiles C++ (cf. sfr_cri_03d). The rest of the criMvPly layer stays in
// sfr_cri_02c, which can't be C (cri_movie.h is C++). This unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1 cl with /TC,
// cmake/ms2-unit-profiles.cmake): no headers, C89 declarations at the top of each block, and the parameter types of
// the definitions in sfr_cri_02c, so a C++ compile (clang-cl) mangles every name as they do.
// MS2-UNIT: sfr_cri_02d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1400356a0-0x140035710 .text$mn
// MS2-RANGE: 0x140035800-0x1400358d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

typedef unsigned char CriUint8;
typedef unsigned long CriUint32;
typedef long CriSint32;
typedef unsigned __int64 CriUint64;
typedef CriSint32 CriBool;

struct CriMvFrameInfo;
struct CriMvAlphaDecoderFrameInfo;
typedef struct CriMvDecoderHandleFields { CriUint8 Reserved00[0xe40]; void* AlphaDecoder; } CriMvDecoderHandleFields;

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
#pragma comment(linker, "/alternatename:?FUN_1400356a0@@YAXPEAX00PEBUCriMvFrameInfo@@PEBX@Z=FUN_1400356a0")
#pragma comment(linker, "/alternatename:?FUN_140035800@@YAJPEAX00@Z=FUN_140035800")
#pragma comment(linker, "/alternatename:crimvply_clearAlphaFrameInfoMembers=?crimvply_clearAlphaFrameInfoMembers@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:crimvply_isUnderGetFrameCondition=?crimvply_isUnderGetFrameCondition@@YAJPEAX@Z")
#pragma comment(linker, "/alternatename:crimvply_updateMvPlyYuvBuffersFromAlphadecInfo=?crimvply_updateMvPlyYuvBuffersFromAlphadecInfo@@YAXPEAXPEBUCriMvAlphaDecoderFrameInfo@@@Z")
#endif

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
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
#pragma optimize("", on)
