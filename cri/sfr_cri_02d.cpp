// Recovered CRI Movie helpers from MapleStory2.exe, written from the executable's behavior: the functions of the /Od
// criMvPly objs in sfr_cri_02c's range that only byte-match as C. VS2008 /Od often keeps a value loaded after a call
// in r11 when it compiles C where it picks rax or rcx when it compiles C++ (cf. sfr_cri_03d). The rest of the criMvPly
// layer stays in sfr_cri_02c, which can't be C (cri_movie.h is C++). This unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1
// cl with /TC, cmake/ms2-unit-profiles.cmake): only string.h, C89 declarations at the top of each block, and the
// parameter types of the definitions in sfr_cri_02c, so a C++ compile (clang-cl) mangles every name as they do.
// MS2-UNIT: sfr_cri_02d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14002fbe0-0x1400301d0 .text$mn
// MS2-RANGE: 0x140030cb0-0x140030e50 .text$mn
// MS2-RANGE: 0x140031290-0x1400313d0 .text$mn
// MS2-RANGE: 0x140031990-0x140031aa0 .text$mn
// MS2-RANGE: 0x140032090-0x140032650 .text$mn
// MS2-RANGE: 0x140034330-0x1400344f0 .text$mn
// MS2-RANGE: 0x140034730-0x140034920 .text$mn
// MS2-RANGE: 0x140034d40-0x140034e70 .text$mn
// MS2-RANGE: 0x1400356a0-0x140035710 .text$mn
// MS2-RANGE: 0x140035800-0x1400359e0 .text$mn
// MS2-RANGE: 0x1400361a0-0x1400363b0 .text$mn
// MS2-RANGE: 0x140036470-0x140036590 .text$mn
// MS2-RANGE: 0x140036710-0x1400369e0 .text$mn
// MS2-RANGE: 0x140036b80-0x140036d50 .text$mn
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
typedef struct CriMvPlyStateView
{
    CriUint8  Reserved0[4];
    CriSint32 Status;                       // 0x04
    CriUint32 InternalFlags;                // 0x08
    CriUint8  Reserved0C[0xe10 - 0x0c];
    void*     AudioManager;                 // 0xe10
    CriUint8  ReservedE18[0xf10 - 0xe18];
    CriUint8  StopState;                    // 0xf10
} CriMvPlyStateView;
typedef struct CriMvPlyDemuxFields
{
    CriUint8 Reserved0[0xd60];
    CriSint32 ReadMode;                     // 0xd60
    CriUint8 ReservedD64[0xd68 - 0xd64];
    void* Demux;                            // 0xd68
    CriUint8 ReservedD70[0xd78 - 0xd70];
    void* InputBuffer;                      // 0xd78
    void* ReadBuffer;                       // 0xd80
    CriUint8 ReservedD88[0xda0 - 0xd88];
    void* MemoryInput;                      // 0xda0
    CriUint8 ReservedDA8[0xe78 - 0xda8];
    void* HeaderBuffer;                     // 0xe78
} CriMvPlyDemuxFields;
typedef struct CriMvPlaneInfo
{
    CriUint64 Buffer;
    CriSint32 Stride;
    CriUint32 Height;
} CriMvPlaneInfo;
typedef struct CriMvFramePlaneSourcePlane
{
    CriUint64 Buffer;
    CriUint32 Reserved;
    CriUint32 Width;
    CriUint32 Height;
    CriUint32 Reserved2;
} CriMvFramePlaneSourcePlane;
typedef struct CriMvFramePlaneSource
{
    CriUint8 Reserved0[0x38];
    CriUint32 PlaneCount;
    CriUint32 Reserved1;
    CriMvFramePlaneSourcePlane Planes[3];
} CriMvFramePlaneSource;
typedef struct CriMovieInputChunk
{
    const CriUint8* Data;
    CriUint32 Size;
    CriUint32 Reserved;
} CriMovieInputChunk;
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
typedef struct CriMovieChunkQueueRecord
{
    void* Chunk;
    CriUint32 Type;
    CriUint32 Reserved;
} CriMovieChunkQueueRecord;
typedef struct CriMvReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; } CriMvReadModeView;
typedef struct CriMvWriteBufferView { void* Data; CriUint32 Capacity; } CriMvWriteBufferView;
typedef struct CriMvUsfHeaderGateView { CriUint8 Reserved[0xd64]; CriSint32 HeaderChecked; } CriMvUsfHeaderGateView;
typedef struct CriMvUsfHeaderSizeView { CriUint8 Reserved[0x8b8]; CriUint32 Size; } CriMvUsfHeaderSizeView;
typedef struct CriMovieParsedChunk
{
    const CriUint8* Data;
    CriSint32 Size;
    CriUint32 Reserved;
} CriMovieParsedChunk;
typedef struct CriMvHeaderQueueView { CriUint8 Reserved[0xd80]; void* Queue; } CriMvHeaderQueueView;
typedef struct CriMvHeaderRingState
{
    CriUint8  Reserved[0x5e8];
    unsigned short CurrentIndex;            // 0x5e8
    CriUint8  Reserved2[6];
    CriUint32 Phase;                        // 0x5f0
} CriMvHeaderRingState;
typedef struct CriMvHeaderStreamEntry       // 0x2e0 bytes, from player + 0x28
{
    CriUint8  Reserved0[0x10];
    CriUint32 Field10;
    CriUint8  Reserved1[0x38];
    CriUint32 Field4c;
    CriUint8  Reserved2[0x200];
    CriUint32 Field250;
    CriUint8  Reserved3[0x1c];
    CriUint32 Field270;
    CriUint8  Reserved4[0x4c];
    CriUint32 State;                        // 0x2c0
    CriUint32 History0;
    CriUint32 History4;
    CriUint32 History8;
    CriUint32 HistoryC;
    CriUint32 History10;
    CriUint8  Reserved5[8];
} CriMvHeaderStreamEntry;
typedef struct CriMvHeaderStreamList { CriUint8 Reserved[0x28]; CriMvHeaderStreamEntry Entries[2]; } CriMvHeaderStreamList;
typedef struct CriMvStartMemoryView
{
    CriUint8  Reserved0[0x0c];
    CriUint32 Reset;                        // 0x0c
    CriUint32 ResetTimer;                   // 0x10
    CriUint8  Reserved14[0x28 - 0x14];
    CriUint8  CurrentHeader[0x5c0];         // 0x28
    unsigned short CurrentSlot;             // 0x5e8
    unsigned short Reserved5ea;
    CriUint32 SlotFlags;                    // 0x5ec
    CriUint32 Phase;                        // 0x5f0
    CriUint8  Reserved5f4[4];
    CriUint8  AnalyzedHeader[0x2c0];        // 0x5f8
    CriUint32 HeaderSize;                   // 0x8b8
} CriMvStartMemoryView;
typedef struct CriMvHeaderCountsView
{
    CriUint32 HeaderType;                   // 0x00
    CriUint32 Field4;                       // 0x04
    CriUint32 MinimumBuffer;                // 0x08
    CriUint32 AverageBitrate;               // 0x0c
    CriUint32 VideoCount;                   // 0x10
    CriUint8  Reserved14[0x4c - 0x14];
    CriUint32 AudioCount;                   // 0x4c
    CriUint8  Reserved50[0x200];
    CriUint32 SubtitleCount;                // 0x250
    CriUint8  Reserved254[0x1c];
    CriUint32 AlphaCount;                   // 0x270
    CriUint8  Reserved274[0x2c];
    CriUint32 CueCount;                     // 0x2a0
} CriMvHeaderCountsView;
typedef struct CriMvHeaderPlayerView
{
    CriUint8  Reserved0[0xdd0];
    void*     UtfHeap;                      // 0xdd0
    CriUint8  Reserveddd8[0xe38 - 0xdd8];
    CriUint32 TrackType;                    // 0xe38
    CriUint32 TrackSubType;                 // 0xe3c
} CriMvHeaderPlayerView;
typedef struct CriMvAnalyzedVideo { CriUint32 Words[0x38 / 4]; } CriMvAnalyzedVideo;
typedef struct CriMvAnalyzedAudio { CriUint32 Words[0x10 / 4]; } CriMvAnalyzedAudio;
typedef struct CriMvAnalyzedAlpha { CriUint32 Words[0x2c / 4]; } CriMvAnalyzedAlpha;
typedef struct CriMvAnalyzedHeader
{
    CriUint32          Present;             // 0x00
    CriUint32          Field04;             // 0x04
    CriUint32          Field08;             // 0x08
    CriUint32          Field0c;             // 0x0c
    CriUint32          Field10;             // 0x10
    CriMvAnalyzedVideo Video[1];            // 0x14
    CriUint32          AudioCount;          // 0x4c
    CriMvAnalyzedAudio Audio[0x20];         // 0x50
    CriUint32          SubtitleCount;       // 0x250
    CriUint8           Reserved254[4];
    CriUint32          Subtitle[0x18 / 4];  // 0x258
    CriUint32          AlphaCount;          // 0x270
    CriMvAnalyzedAlpha Alpha[1];            // 0x274
    CriUint8           Reserved2a0[8];
    CriUint8           CuePoint[0x18];      // 0x2a8
} CriMvAnalyzedHeader;
typedef struct CriMvStreamSlotView
{
    CriMvAnalyzedHeader Header;
    CriUint8            Reserved2c0[0x2e0 - 0x2c0];
} CriMvStreamSlotView;
typedef struct CriMvStreamParamsPlayerView
{
    CriUint32           Reserved0;
    CriUint32           Status;             // 0x04
    CriUint8            Reserved8[0x20];
    CriMvStreamSlotView Slots[2];           // 0x28
    CriUint8            Reserved5e8[4];
    CriUint32           SlotCount;          // 0x5ec
    CriUint32           SlotIndex;          // 0x5f0
    CriUint8            Reserved5f4[4];
    CriMvAnalyzedHeader Header;             // 0x5f8
    CriUint8            Reserved8b8[4];
    float               FrameRate;          // 0x8bc
    CriUint8            Reserved8c0[4];
    CriUint32           AudioOutput;        // 0x8c4
    CriSint32           AudioTrack;         // 0x8c8
} CriMvStreamParamsPlayerView;
typedef struct CriMvParamAudioView { CriUint32 Words[0x10 / 4]; } CriMvParamAudioView;
typedef struct CriMvStreamParamsView        // the public CriMvStreamingParameters record (0x288)
{
    CriUint32           Playable;           // 0x00
    float               BufferingTime;      // 0x04
    CriUint32           Head[5];            // 0x08
    CriUint32           Video[0x30 / 4];    // 0x1c
    CriUint32           NumAudio;           // 0x4c
    CriSint32           TrackPlayAudio;     // 0x50
    CriMvParamAudioView Audio[0x20];        // 0x54
    CriUint32           NumSubtitle;        // 0x254
    CriSint32           ChannelPlaySubtitle;// 0x258
    CriUint32           MaxSubtitleSize;    // 0x25c
    CriUint32           NumAlpha;           // 0x260
    CriUint32           Alpha[8];           // 0x264
    CriUint32           AlphaPlane;         // 0x284
} CriMvStreamParamsView;
typedef struct CriMvHeaderAnalysisView
{
    CriUint8  Reserved0[0x5f8];
    struct CriMvAnalyzedHeader AnalyzedHeader;  // 0x5f8
    CriSint32 HeaderCount;                  // 0x8b8
    CriUint8  Reserved8bc[0xd60 - 0x8bc];
    CriSint32 ReadMode;                     // 0xd60
    CriUint8  Reservedd64[0xdb8 - 0xd64];
    CriSint32 ReadBytes;                    // 0xdb8
} CriMvHeaderAnalysisView;
typedef struct CriMvVideoDecoderView { CriUint8 Reserved[0xe08]; void* VideoDecoder; } CriMvVideoDecoderView;
typedef struct CriUsfChunkHeader            // FUN_14003b3fc fills 0x24 bytes
{
    CriUint32 Reserved0[3];
    CriUint8  Reserved0C, Reserved0D, Reserved0E;
    CriUint8  Type;                         // 0x0f
    CriUint32 Reserved10[5];
} CriUsfChunkHeader;
typedef struct CriMvSubtitleItemInfo        // analyzeSubtitleInfo fills 0x38 bytes
{
    CriUint32 Reserved0[3];
    CriSint32 Channel;                      // 0x0c
    CriUint64 Reserved10[5];
} CriMvSubtitleItemInfo;
typedef struct CriMvSubtitleFrameCounter { CriUint8 Reserved[0xe30]; CriUint32 Value; } CriMvSubtitleFrameCounter;

void FUN_140028074(void* heap);
CriBool allocateMetaWork(void* player);
void FUN_140034330(void* player, void* source, void* readBuffer, void* dataQueue);
void criUsfDmx_Stop(void* demux);
void criUsfDmx_Execute(void* demux);
CriSint32 criUsfDmx_GetStatus(void* demux);
void crimvply_transitErrorState(void* player, void* message);
void crimvply_occurUserError(void* owner, const char* message, CriSint32 value);
void criMvPlyAmng_TerminateSupply(void* audioManager);
void criVdec_TerminateSupply(void* decoder);
void criAlphaDec_TerminateSupply(void* decoder);
void criUsfDmx_Start(void* demux);
void criUsfDmx_SetInputSj(void* demux, void* value);
void FUN_140044fb0(void* output, CriUint32 index, void* value, CriUint32 type, CriUint32 flags);
void criUsfDmx_SetThrououtSwitch(void* demux, CriUint8 value);
void criSj_Reset(void* streamJoint);
void* criMvPly_GetInputSj(void* player, CriUint32* available, CriUint32* bounded);
void FUN_1400467a0(void* queue, CriSint32 operation, CriSint32 timeout, void* item);
void criSj_UngetChunk(void* queue, CriSint32 operation, void* chunk);
CriSint32 FUN_1400467b8(void* ringBuffer, CriSint32 query);
void criSj_GetInputChunk(void* object, void* value);
void criMvPly_AddInputMemory(void* player, void* chunk, CriUint32 type);
void FUN_140046814(void* streamJoint, const void* chunk, CriUint32 size);
void crimvply_occurFatalError(void* owner, const char* message, CriSint32 value);
void criSj_PutChunk(void* queue, CriSint32 operation, void* chunk);
CriUint32 FUN_14003b3fc(const CriUint8* data, CriUint32 size, void* output);
const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);
void retrieveHeaderInfo(void* player, void* stream, const struct CriMovieParsedChunk* parsed);
struct CriUtfRtvView;
struct CriMvStreamingParameters;
extern CriSint32 DAT_143b27948;
void*     criUtfRtv_Create(void* heap, void* data, CriUint32 size);                                     /* 14003b348 */
CriUint32 FID_conflict_criUtfRtv_GetDataSint32Fn(const struct CriUtfRtvView* object, CriUint32 index, const char* key); /* 14003a85c */
CriUint32 criUtfRtv_GetNumRecord(const struct CriUtfRtvView* object);                                  /* 14003a45c */
void      criUtfRtv_Destroy(CriUint64* table);                                                         /* 14003a108 */
void retrieveAudioHeader(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
void FUN_140032650(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
void retrieveSubtitleHeader(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
void FUN_140032db0(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
void retrieveCuePointHeader(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
CriBool recordSubtitleHeader(void* player, const CriMovieInputChunk* input);
CriBool isEndStopProcessingProc(void* player);
void resetHandle(void* player);
void executeMvPlyPrepServer(void* player);
void executeMvPlyPlayingServer(void* player);
void executeVideoServer(void* player);
void executeUsfServer(void* player);
void criMvPlyAmng_ExecuteAudioServer(void* audioManager, void* player);
CriSint32 getInternalStatus(void* player);
CriBool isLockedInputChunk(const void* player);
void criMvPlyAmng_Destroy(void* manager, void* heap);
void criAlphaDec_Destroy(void* decoder);
void criVdec_Destroy(CriUint64* adapter);
void criSj_Destroy(void* streamJoint);
CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* chunk, CriSint32 channel);
void releaseSubtitleChunk(void* player, CriMvSubtitleChunk* chunk);
void ungetSubtitleChunk(void* player, CriMvSubtitleChunk* chunk);
void analyzeSubtitleInfo(void* player, CriMvSubtitleChunk* chunk, void* outputInfo);
CriBool criMvPly_IsSetDefaultDecryptionKey(void);
void crimvply_makeFrameInfoMembers(void* player, void* output, const void* frameInfo, CriUint64 firstWord, CriUint32 flags);
void crimvply_makeAlphaFrameInfoMembers(void* player, void* destination, const void* source);
void* criAlphaDec_GetAlphaFramePointer(void* decoder, void* frameInfo);
void crimvply_clearAlphaFrameInfoMembers(void* info);
CriBool crimvply_isUnderGetFrameCondition(void* player);
void crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(void* player, const struct CriMvAlphaDecoderFrameInfo* info);
// the C names bind to sfr_cri_02c's C++ definitions in the full exe (alias.py pairs only FUN_<va> names by their VA);
// the hook DLL's ms2sym.obj already maps them to the exe addresses; the C++ callers' mangled names of this unit's two
// definitions (sfr_cri_02c, sfr_cri_07) bind to the plain C names the same way
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:?FUN_140030cb0@@YAXPEAX@Z=FUN_140030cb0")
#pragma comment(linker, "/alternatename:?FUN_140031290@@YAXPEAX@Z=FUN_140031290")
#pragma comment(linker, "/alternatename:?FUN_140031990@@YAJPEAX@Z=FUN_140031990")
#pragma comment(linker, "/alternatename:?criMvPly_GetStreamingParameters@@YAXPEAXPEAUCriMvStreamingParameters@@@Z=criMvPly_GetStreamingParameters")
#pragma comment(linker, "/alternatename:?retrieveHeaderInfo@@YAXPEAX0PEBUCriMovieParsedChunk@@@Z=retrieveHeaderInfo")
#pragma comment(linker, "/alternatename:?FUN_140032090@@YAJPEAX@Z=FUN_140032090")
#pragma comment(linker, "/alternatename:?FUN_140034330@@YAXPEAX000@Z=FUN_140034330")
#pragma comment(linker, "/alternatename:?executeUsfServer@@YAXPEAX@Z=executeUsfServer")
#pragma comment(linker, "/alternatename:?FUN_140034d40@@YAXPEAXPEAUCriMovieInputChunk@@@Z=FUN_140034d40")
#pragma comment(linker, "/alternatename:getInternalStatus=?getInternalStatus@@YAJPEAX@Z")
#pragma comment(linker, "/alternatename:isLockedInputChunk=?isLockedInputChunk@@YAJPEBX@Z")
#pragma comment(linker, "/alternatename:?criMvPly_GetSubtitle@@YAXPEAX0K0@Z=criMvPly_GetSubtitle")
#pragma comment(linker, "/alternatename:?FUN_1400356a0@@YAXPEAX00PEBUCriMvFrameInfo@@PEBX@Z=FUN_1400356a0")
#pragma comment(linker, "/alternatename:?FUN_140035800@@YAJPEAX00@Z=FUN_140035800")
#pragma comment(linker, "/alternatename:?FUN_1400358d0@@YAKPEAXPEBX@Z=FUN_1400358d0")
#pragma comment(linker, "/alternatename:?criMvPly_StartMemory@@YAXPEAXPEBXK@Z=criMvPly_StartMemory")
#pragma comment(linker, "/alternatename:?executeHeaderServer@@YAXPEAX@Z=executeHeaderServer")
#pragma comment(linker, "/alternatename:?FUN_140036b80@@YAJPEAXPEAUCriMvSubtitleChunk@@J@Z=FUN_140036b80")
#pragma comment(linker, "/alternatename:crimvply_clearAlphaFrameInfoMembers=?crimvply_clearAlphaFrameInfoMembers@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:crimvply_isUnderGetFrameCondition=?crimvply_isUnderGetFrameCondition@@YAJPEAX@Z")
#pragma comment(linker, "/alternatename:crimvply_updateMvPlyYuvBuffersFromAlphadecInfo=?crimvply_updateMvPlyYuvBuffersFromAlphadecInfo@@YAXPEAXPEBUCriMvAlphaDecoderFrameInfo@@@Z")
#endif

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// translate the active CRI stream slot into the public streaming-parameter record
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): sti, oaud, i, vinfo, vprm, track, defTrack,
// oalph, info, alph, sno.
// @0x14002fbe0
void criMvPly_GetStreamingParameters(void* player, struct CriMvStreamingParameters* output)
{
    CriMvAnalyzedHeader* info;
    CriUint32* vinfo;
    CriUint32* vprm;
    CriUint32 i;
    CriUint32 defTrack;
    CriUint32* track;
    CriUint32* oaud;
    CriUint32* sti;
    CriUint32* alph;
    CriUint32* oalph;
    CriUint32 sno;
    memset(output, 0, 0x288);
    if (((CriMvStreamParamsPlayerView*)player)->Status == 0 || ((CriMvStreamParamsPlayerView*)player)->Status == 1 ||
        ((CriMvStreamParamsPlayerView*)player)->Status == 8 || ((CriMvStreamParamsPlayerView*)player)->Status == 9 ||
        ((CriMvStreamParamsPlayerView*)player)->Status == 10)
        return;
    if (((CriMvStreamParamsPlayerView*)player)->SlotCount == 0)
        info = &((CriMvStreamParamsPlayerView*)player)->Header;
    else {
        sno = ((CriMvStreamParamsPlayerView*)player)->SlotIndex % 2;
        info = &((CriMvStreamParamsPlayerView*)player)->Slots[sno].Header;
    }
    ((CriMvStreamParamsView*)output)->BufferingTime = ((CriMvStreamParamsPlayerView*)player)->FrameRate;
    ((CriMvStreamParamsView*)output)->Head[0] = info->Field0c;
    ((CriMvStreamParamsView*)output)->Head[1] = info->Field04;
    ((CriMvStreamParamsView*)output)->Head[2] = info->Field08;
    ((CriMvStreamParamsView*)output)->Head[3] = 0xffffffff;
    ((CriMvStreamParamsView*)output)->Head[4] = info->Field10;
    vinfo = info->Video[0].Words;
    vprm = ((CriMvStreamParamsView*)output)->Video;
    if (vinfo[0] > 0)
    {
        vprm[0] = vinfo[0];
        vprm[1] = vinfo[1];
        vprm[2] = vinfo[2];
        vprm[3] = vinfo[3];
        vprm[4] = 0;
        vprm[5] = vinfo[4];
        vprm[6] = vinfo[5];
        vprm[7] = vinfo[6];
        vprm[8] = vinfo[7];
        vprm[9] = vinfo[8];
        vprm[10] = vinfo[9];
        vprm[11] = vinfo[10];
    }
    else
    {
        vprm[0] = 0;
        vprm[1] = 0;
        vprm[4] = 0;
        vprm[5] = 0;
        vprm[6] = 0;
        vprm[7] = 0;
        vprm[8] = 0;
        vprm[9] = 0;
        vprm[10] = 0;
        vprm[11] = 0;
    }
    if (vinfo[11] > 0)
        ((CriMvStreamParamsView*)output)->AlphaPlane = 1;
    else
        ((CriMvStreamParamsView*)output)->AlphaPlane = 0;
    defTrack = 0xffffffff;
    for (i = 0; i < 0x20; i++)
    {
        track = info->Audio[i].Words;
        oaud = ((CriMvStreamParamsView*)output)->Audio[i].Words;
        if (track[1] > 0)
        {
            oaud[0] = track[0];
            oaud[1] = track[1];
            oaud[2] = track[2];
            oaud[3] = ((CriMvStreamParamsPlayerView*)player)->AudioOutput;
            if (defTrack == 0xffffffff)
                defTrack = i;
        }
        else
        {
            oaud[0] = 0;
            oaud[1] = 0;
            oaud[2] = 0;
            oaud[3] = 0;
        }
    }
    ((CriMvStreamParamsView*)output)->NumAudio = info->AudioCount;
    ((CriMvStreamParamsView*)output)->TrackPlayAudio = -1;
    if (((CriMvStreamParamsView*)output)->NumAudio > 0)
    {
        if (((CriMvStreamParamsPlayerView*)player)->AudioTrack == 100)
            ((CriMvStreamParamsView*)output)->TrackPlayAudio = defTrack;
        else if (((CriMvStreamParamsPlayerView*)player)->AudioTrack >= 0 && ((CriMvStreamParamsPlayerView*)player)->AudioTrack < 0x20)
        {
            track = info->Audio[((CriMvStreamParamsPlayerView*)player)->AudioTrack].Words;
            if (track[1] > 0)
                ((CriMvStreamParamsView*)output)->TrackPlayAudio = ((CriMvStreamParamsPlayerView*)player)->AudioTrack;
        }
    }
    sti = info->Subtitle;
    if (info->SubtitleCount > 0 && sti[0] == 1)
    {
        ((CriMvStreamParamsView*)output)->NumSubtitle = sti[1];
        ((CriMvStreamParamsView*)output)->MaxSubtitleSize = sti[4];
    }
    ((CriMvStreamParamsView*)output)->ChannelPlaySubtitle = -1;
    ((CriMvStreamParamsView*)output)->Playable = 1;
    if (vprm[10] == 2 && DAT_143b27948 == 0)
        ((CriMvStreamParamsView*)output)->Playable = 0;
    ((CriMvStreamParamsView*)output)->NumAlpha = info->AlphaCount;
    alph = info->Alpha[0].Words;
    oalph = ((CriMvStreamParamsView*)output)->Alpha;
    oalph[0] = alph[0];
    oalph[1] = alph[1];
    oalph[2] = alph[2];
    oalph[3] = alph[3];
    oalph[4] = alph[4];
    oalph[5] = alph[5];
    oalph[6] = alph[6];
    oalph[7] = alph[7];
}

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
        criSj_Destroy(*(void**)((CriUint8*)player + 0xe28));
        *(void**)((CriUint8*)player + 0xe28) = 0;
    }
    if (*(void**)((CriUint8*)player + 0xe10))
    {
        criMvPlyAmng_Destroy(*(void**)((CriUint8*)player + 0xe10), heap);
        *(void**)((CriUint8*)player + 0xe10) = 0;
    }
    if (*(void**)((CriUint8*)player + 0xe40))
    {
        criAlphaDec_Destroy(*(void**)((CriUint8*)player + 0xe40));
        *(void**)((CriUint8*)player + 0xe40) = 0;
    }
    if (*(void**)((CriUint8*)player + 0xe08))
    {
        criVdec_Destroy(*(CriUint64**)((CriUint8*)player + 0xe08));
        *(void**)((CriUint8*)player + 0xe08) = 0;
    }
    handle = *(void**)((CriUint8*)player + 0xd88);
    if (handle)
    {
        criSj_Destroy(handle);
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

// advance decoder and audio processing according to the CRI Movie state machine
// @0x140031290
void FUN_140031290(void* player)
{
    CriSint32 status;
    status = getInternalStatus(player);
    if (status == 0 || status == 9 || status == 7 || status == 6)
        return;

    if (((CriMvPlyStateView*)player)->Status != 1)
        executeUsfServer(player);
    executeVideoServer(player);

    if (((CriMvPlyStateView*)player)->Status == 8)
    {
        if (isEndStopProcessingProc(player) == 1)
        {
            if (isLockedInputChunk(player) == 1)
            {
                ((CriMvPlyStateView*)player)->StopState = 3;
                return;
            }
            resetHandle(player);
            ((CriMvPlyStateView*)player)->Status = 9;
            ((CriMvPlyStateView*)player)->StopState = 5;
            ((CriMvPlyStateView*)player)->InternalFlags = 0;
        }
        return;
    }

    if (((CriMvPlyStateView*)player)->AudioManager)
        criMvPlyAmng_ExecuteAudioServer(((CriMvPlyStateView*)player)->AudioManager, player);
    status = getInternalStatus(player);
    switch (status)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        executeMvPlyPrepServer(player);
        break;
    case 5:
        executeMvPlyPlayingServer(player);
        break;
    }
}

// reset the demux and its output stream after the player update completes
// @0x140031990
CriBool FUN_140031990(void* player)
{
    void* demux;
    demux = ((CriMvPlyDemuxFields*)player)->Demux;
    if (allocateMetaWork(player) != 1)
        return 0;
    FUN_140034330(player, ((CriMvPlyDemuxFields*)player)->InputBuffer, ((CriMvPlyDemuxFields*)player)->ReadBuffer,
                  ((CriMvPlyDemuxFields*)player)->HeaderBuffer);
    criUsfDmx_Stop(demux);
    criSj_Reset(((CriMvPlyDemuxFields*)player)->ReadBuffer);
    if (((CriMvPlyDemuxFields*)player)->ReadMode == 0)
        criUsfDmx_SetInputSj(demux, ((CriMvPlyDemuxFields*)player)->HeaderBuffer);
    else
        criUsfDmx_SetInputSj(demux, ((CriMvPlyDemuxFields*)player)->MemoryInput);
    FUN_140044fb0(demux, 0, ((CriMvPlyDemuxFields*)player)->ReadBuffer, 0, (CriUint32)-1);
    criUsfDmx_SetThrououtSwitch(demux, 0);
    criUsfDmx_Start(demux);
    criUsfDmx_Execute(demux);
    return 1;
}

// consume CRI Movie header and stream records until the file's end marker arrives
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): sti, contentsInfo, vinfo, readBytes, track,
// queue, completed, usfHead, hdr, info, alph.
// @0x140032090
CriSint32 FUN_140032090(void* player)
{
    void* queue = ((CriMvPlyDemuxFields*)player)->ReadBuffer;
    CriSint32 completed = 0;
    CriSint32 readBytes = 0;
    CriUsfChunkHeader hdr;
    CriMvAnalyzedHeader* info = &((CriMvHeaderAnalysisView*)player)->AnalyzedHeader;
    CriMovieChunkQueueRecord usfHead;
    CriMovieParsedChunk contentsInfo;
    CriMvAnalyzedAudio* track;
    CriMvAnalyzedVideo* vinfo;
    void* sti;
    CriMvAnalyzedAlpha* alph;
    while ((CriUint32)FUN_1400467b8(queue, 1) > 0)
    {
        FUN_1400467a0(queue, 1, -1, &usfHead);
        if (usfHead.Type >= 0x20)
        {
            FUN_14003b3fc((const CriUint8*)usfHead.Chunk, usfHead.Type, &hdr);
            contentsInfo.Data = criUsfCmn_GetContents((const CriUint8*)usfHead.Chunk, usfHead.Type, &contentsInfo.Size);
            if (((CriMvHeaderAnalysisView*)player)->HeaderCount == 0)
            {
                if (hdr.Reserved0[0] == 0x43524944)
                    info->Present = 1;
                else
                {
                    crimvply_occurUserError(player, "E05063020M : Input file is not USF file.", hdr.Reserved0[0]);
                    criSj_UngetChunk(queue, 1, &usfHead);
                    return completed;
                }
            }
            if (hdr.Reserved0[0] == 0x43524944)
                retrieveHeaderInfo(player, info, &contentsInfo);
            else if (hdr.Type == 1)
            {
                switch (hdr.Reserved0[0])
                {
                case 0x40534641:
                    if (hdr.Reserved0C < 0x20)
                    {
                        track = &info->Audio[hdr.Reserved0C];
                        retrieveAudioHeader(player, info, (CriUint32*)track, &contentsInfo);
                    }
                    break;
                case 0x40534656:
                    if (hdr.Reserved0C < 1)
                    {
                        vinfo = &info->Video[hdr.Reserved0C];
                        FUN_140032650(player, info, (CriUint32*)vinfo, &contentsInfo);
                    }
                    break;
                case 0x40534254:
                    sti = info->Subtitle;
                    retrieveSubtitleHeader(player, info, (CriUint32*)sti, &contentsInfo);
                    break;
                case 0x40414c50:
                    if (hdr.Reserved0C < 1)
                    {
                        alph = &info->Alpha[hdr.Reserved0C];
                        FUN_140032db0(player, info, (CriUint32*)alph, &contentsInfo);
                    }
                    break;
                case 0x40435545:
                    retrieveCuePointHeader(player, info, (CriUint32*)info->CuePoint, &contentsInfo);
                    break;
                }
            }
            else if (hdr.Type == 2)
                completed = 1;
            criSj_PutChunk(queue, 2, &usfHead);
            readBytes += usfHead.Type;
            ((CriMvHeaderAnalysisView*)player)->HeaderCount++;
        }
        else
            criSj_UngetChunk(queue, 1, &usfHead);
        if (completed == 1)
        {
            if (((CriMvHeaderAnalysisView*)player)->ReadMode == 1)
                ((CriMvHeaderAnalysisView*)player)->ReadBytes = readBytes;
            break;
        }
    }
    return completed;
}

// initialize analyzed stream counts from the CRI Movie file header
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): count, recPos, records, streamId.
// @0x140032420
void retrieveHeaderInfo(void* player, void* streamInfo, const struct CriMovieParsedChunk* parsed)
{
    CriUint32 streamId;
    void* records;
    CriUint32 recPos;
    CriUint32 count;
    records = criUtfRtv_Create(((CriMvHeaderPlayerView*)player)->UtfHeap, (void*)parsed->Data, parsed->Size);
    memset(streamInfo, 0, 0x2c0);
    ((CriMvHeaderCountsView*)streamInfo)->Field4 = 0;
    ((CriMvHeaderCountsView*)streamInfo)->MinimumBuffer = FID_conflict_criUtfRtv_GetDataSint32Fn((const struct CriUtfRtvView*)records, 0, "minbuf");
    ((CriMvHeaderCountsView*)streamInfo)->AverageBitrate = FID_conflict_criUtfRtv_GetDataSint32Fn((const struct CriUtfRtvView*)records, 0, "avbps");
    count = criUtfRtv_GetNumRecord((const struct CriUtfRtvView*)records);
    for (recPos = 0; recPos < count; recPos++)
    {
        streamId = FID_conflict_criUtfRtv_GetDataSint32Fn((const struct CriUtfRtvView*)records, recPos, "stmid");
        switch (streamId)
        {
        case 0x40534641:
            ((CriMvHeaderCountsView*)streamInfo)->AudioCount++;
            if (((CriMvHeaderCountsView*)streamInfo)->AudioCount > 0x20)
                ((CriMvHeaderCountsView*)streamInfo)->AudioCount = 0x20;
            break;
        case 0x40534656:
            ((CriMvHeaderCountsView*)streamInfo)->VideoCount++;
            if (((CriMvHeaderCountsView*)streamInfo)->VideoCount > 1)
                ((CriMvHeaderCountsView*)streamInfo)->VideoCount = 1;
            break;
        case 0x40534254:
            ((CriMvHeaderCountsView*)streamInfo)->SubtitleCount++;
            break;
        case 0x40414c50:
            ((CriMvHeaderCountsView*)streamInfo)->AlphaCount++;
            if (((CriMvHeaderCountsView*)streamInfo)->AlphaCount > 1)
                ((CriMvHeaderCountsView*)streamInfo)->AlphaCount = 1;
            ((CriMvHeaderPlayerView*)player)->TrackType = 0x40414c50;
            ((CriMvHeaderPlayerView*)player)->TrackSubType = 0;
            break;
        case 0x40435545:
            ((CriMvHeaderCountsView*)streamInfo)->CueCount++;
            break;
        }
    }
    criUtfRtv_Destroy((CriUint64*)records);
}

// Drain the two CRI input streams into the decoder read queue.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): dst, written, chunk.
// @0x140034330
void FUN_140034330(void* player, void* source, void* readBuffer, void* dataQueue)
{
    CriMovieChunkQueueRecord chunk;
    CriSint32 written;
    CriMvWriteBufferView dst;
    written = 0;
    if (((CriMvReadModeView*)player)->Mode != 0)
        return;
    while ((CriUint32)FUN_1400467b8(readBuffer, 2) > 0)
        FUN_1400467a0(readBuffer, 2, -1, &chunk);
    while ((CriUint32)FUN_1400467b8(readBuffer, 1) > 0)
    {
        criSj_GetInputChunk(dataQueue, &dst);
        FUN_1400467a0(readBuffer, 1, -1, &chunk);
        if (chunk.Type > dst.Capacity)
            crimvply_occurFatalError(player, "E08120301M : Illigal data size of analize header against demux data line.", dst.Capacity);
        memcpy(dst.Data, chunk.Chunk, chunk.Type);
        written += chunk.Type;
        FUN_140046814(dataQueue, &dst, chunk.Type);
    }
    while ((CriUint32)FUN_1400467b8(source, 1) > 0)
    {
        criSj_GetInputChunk(dataQueue, &dst);
        FUN_1400467a0(source, 1, -1, &chunk);
        if (chunk.Type > dst.Capacity)
            crimvply_occurFatalError(player, "E08120302M : Illigal data size in read buffer data line of analize header.", dst.Capacity);
        memcpy(dst.Data, chunk.Chunk, chunk.Type);
        written += chunk.Type;
        FUN_140046814(dataQueue, &dst, chunk.Type);
        criSj_PutChunk(source, 0, &chunk);
    }
}

// validate the CRI Movie signature, reset the demux, and start ready decoders
// Local names pick the exe's VC9 /Od stack slots: dmx, record.
// @0x140034730
void executeUsfServer(void* player)
{
    CriMovieChunkQueueRecord record;
    void* dmx;
    dmx = ((CriMvPlyDemuxFields*)player)->Demux;
    if (criUsfDmx_GetStatus(dmx) == 4)
    {
        crimvply_transitErrorState(player, (void*)"Status of demux is ERROR.");
        return;
    }
    if (((CriMvPlyStateView*)player)->Status == 2)
        return;
    if (((CriMvUsfHeaderGateView*)player)->HeaderChecked == 0 && ((CriMvPlyStateView*)player)->Status == 1 &&
        ((CriMvUsfHeaderSizeView*)player)->Size == 0)
    {
        FUN_1400467a0(((CriMvPlyDemuxFields*)player)->InputBuffer, 1, -1, &record);
        if (record.Chunk == 0 || record.Type < 4)
        {
            criSj_UngetChunk(((CriMvPlyDemuxFields*)player)->InputBuffer, 1, &record);
            return;
        }
        else if (((CriUint8*)record.Chunk)[0] == 'C' && ((CriUint8*)record.Chunk)[1] == 'R' &&
                 ((CriUint8*)record.Chunk)[2] == 'I' && ((CriUint8*)record.Chunk)[3] == 'D')
        {
            criSj_UngetChunk(((CriMvPlyDemuxFields*)player)->InputBuffer, 1, &record);
            ((CriMvUsfHeaderGateView*)player)->HeaderChecked = 1;
        }
        else
        {
            criSj_UngetChunk(((CriMvPlyDemuxFields*)player)->InputBuffer, 1, &record);
            crimvply_occurUserError(player, "E07020701M: Input is not CRI Movie data.", 0);
            return;
        }
    }
    if (((CriMvUsfHeaderGateView*)player)->HeaderChecked == 1)
        criUsfDmx_Execute(dmx);
    if (criUsfDmx_GetStatus(dmx) == 2)
    {
        criMvPlyAmng_TerminateSupply(((CriMvPlyStateView*)player)->AudioManager);
        if (((CriMvVideoDecoderView*)player)->VideoDecoder)
        {
            criVdec_TerminateSupply(((CriMvVideoDecoderView*)player)->VideoDecoder);
            if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
                criAlphaDec_TerminateSupply(((CriMvDecoderHandleFields*)player)->AlphaDecoder);
        }
    }
}

// expose the next decoded file-read record when the movie state permits a read
// @0x140034d40
void FUN_140034d40(void* player, CriMovieInputChunk* output)
{
    CriMovieInputChunk* record;
    CriSint32 status;
    void* source;
    output->Data = 0;
    output->Size = 0;
    if (((CriMvPlyDemuxFields*)player)->ReadMode == 1)
        return;
    if (*(CriSint32*)((CriUint8*)player + 0x0c) == 1)   // the open-phase read lock
        return;
    status = getInternalStatus(player);
    switch (status)
    {
    case 0:
    case 2:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        return;
    }
    source = criMvPly_GetInputSj(player, 0, 0);
    if (!source)
        return;
    if (isLockedInputChunk(player) == 1)
        return;
    record = (CriMovieInputChunk*)((CriUint8*)player + 0xd90);
    FUN_1400467a0(source, 0, -1, record);
    if (record->Size == 0)
    {
        output->Data = 0;
        output->Size = 0;
    }
    else
    {
        output->Data = record->Data;
        output->Size = record->Size;
    }
}

// copy the decoded frame metadata and add the alpha frame metadata when available
// @0x1400356a0
void FUN_1400356a0(void* player, void* output, void* alphaOutput,
                   const struct CriMvFrameInfo* frameInfo, const void* alphaInfo)
{
    crimvply_makeFrameInfoMembers(player, output, frameInfo, *(const CriUint64*)frameInfo,
                  *(const CriUint32*)((const CriUint8*)frameInfo + 0x0c));
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        crimvply_makeAlphaFrameInfoMembers(player, alphaOutput, alphaInfo);
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
    frame = criAlphaDec_GetAlphaFramePointer(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
    if (frame != 0)
    {
        crimvply_makeAlphaFrameInfoMembers(player, outputInfo, frameInfo);
        crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(movieYuvState,
            (const struct CriMvAlphaDecoderFrameInfo*)frameInfo);
        result = 1;
    }
    return result;
}

// copy the decoded frame's plane descriptors (buffer, size, height) into the caller's YUV buffer description
// @0x1400358d0
CriUint32 FUN_1400358d0(void* output, const void* info)
{
    memset(output, 0, 0x40);
    if (((const CriMvFramePlaneSource*)info)->PlaneCount >= 1)
    {
        ((CriMvPlaneInfo*)output)[0].Buffer = ((const CriMvFramePlaneSource*)info)->Planes[0].Buffer;
        ((CriMvPlaneInfo*)output)[0].Stride = ((const CriMvFramePlaneSource*)info)->Planes[0].Height * ((const CriMvFramePlaneSource*)info)->Planes[0].Width;
        ((CriMvPlaneInfo*)output)[0].Height = ((const CriMvFramePlaneSource*)info)->Planes[0].Height;
    }
    if (((const CriMvFramePlaneSource*)info)->PlaneCount >= 2)
    {
        ((CriMvPlaneInfo*)output)[1].Buffer = ((const CriMvFramePlaneSource*)info)->Planes[1].Buffer;
        ((CriMvPlaneInfo*)output)[1].Stride = ((const CriMvFramePlaneSource*)info)->Planes[1].Height * ((const CriMvFramePlaneSource*)info)->Planes[1].Width;
        ((CriMvPlaneInfo*)output)[1].Height = ((const CriMvFramePlaneSource*)info)->Planes[1].Height;
    }
    if (((const CriMvFramePlaneSource*)info)->PlaneCount >= 3)
    {
        ((CriMvPlaneInfo*)output)[2].Buffer = ((const CriMvFramePlaneSource*)info)->Planes[2].Buffer;
        ((CriMvPlaneInfo*)output)[2].Stride = ((const CriMvFramePlaneSource*)info)->Planes[2].Height * ((const CriMvFramePlaneSource*)info)->Planes[2].Width;
        ((CriMvPlaneInfo*)output)[2].Height = ((const CriMvFramePlaneSource*)info)->Planes[2].Height;
    }
    return ((const CriMvFramePlaneSource*)info)->PlaneCount;
}

// initialize a new input stream, reset demux state, and seed the read queue
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): len, buf, demux.
// @0x1400361a0
void criMvPly_StartMemory(void* player, const void* inputData, CriUint32 inputSize)
{
    void* demux = ((CriMvPlyDemuxFields*)player)->Demux;
    CriMvWriteBufferView buf;
    CriUint32 len;
    if (player == 0)
    {
        crimvply_occurUserError(player, "E05121603M : CriMvPly handle is NULL.", 0);
        return;
    }
    if (((CriMvPlyStateView*)player)->Status != 0 && ((CriMvPlyStateView*)player)->Status != 7)
    {
        crimvply_occurUserError(player, "E05121604M : Can't execute start function when CriMvPly handle status is not STOP/PLAYEND.", ((CriMvPlyStateView*)player)->Status);
        return;
    }
    ((CriMvStartMemoryView*)player)->ResetTimer = 0;
    ((CriMvStartMemoryView*)player)->HeaderSize = 0;
    memset(((CriMvStartMemoryView*)player)->AnalyzedHeader, 0, sizeof(((CriMvStartMemoryView*)player)->AnalyzedHeader));
    criUsfDmx_SetInputSj(demux, ((CriMvPlyDemuxFields*)player)->InputBuffer);
    FUN_140044fb0(demux, 0, ((CriMvPlyDemuxFields*)player)->ReadBuffer, 0, (CriUint32)-1);
    criUsfDmx_SetThrououtSwitch(demux, 0);
    criUsfDmx_Start(demux);
    criSj_GetInputChunk(((CriMvPlyDemuxFields*)player)->InputBuffer, &buf);
    if (buf.Capacity > inputSize)
        len = inputSize;
    else
        len = buf.Capacity;
    memcpy(buf.Data, inputData, len);
    FUN_140046814(((CriMvPlyDemuxFields*)player)->InputBuffer, &buf, len);
    criMvPly_AddInputMemory(player, (void*)inputData, inputSize);
    ((CriMvPlyDemuxFields*)player)->ReadMode = 1;
    memset(((CriMvStartMemoryView*)player)->CurrentHeader, 0, sizeof(((CriMvStartMemoryView*)player)->CurrentHeader));
    ((CriMvHeaderStreamList*)player)->Entries[0].State = 0;
    ((CriMvHeaderStreamList*)player)->Entries[1].State = 0;
    ((CriMvStartMemoryView*)player)->CurrentSlot = 1;
    ((CriMvStartMemoryView*)player)->SlotFlags = 0;
    ((CriMvStartMemoryView*)player)->Phase = 0;
    ((CriMvStartMemoryView*)player)->Reset = 0;
    ((CriMvPlyStateView*)player)->Status = 1;
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
        ungetSubtitleChunk(player, &chunk);
        return;
    }
    analyzeSubtitleInfo(player, &chunk, outputInfo);
    criMvPly_IsSetDefaultDecryptionKey();
    memset(destination, 0, capacity);
    if (((CriUint32*)outputInfo)[2] > capacity)
        count = capacity;
    else
        count = ((CriUint32*)outputInfo)[2];
    memcpy(destination, *(void**)outputInfo, count);
    releaseSubtitleChunk(player, &chunk);
}

// parse the next USF header chunk into the current stream entry and record its history fields
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): payload, res, stream, phase, chunk, target, info.
// @0x140036710
void executeHeaderServer(void* player)
{
    CriSint32 res;
    void* stream;
    CriMovieInputChunk chunk;
    CriMvHeaderStreamEntry* target;
    CriUint32 info[12];                     // FUN_14003b3fc fills 0x24 bytes; 12 dwords give the exe 0x98 frame
    CriMovieParsedChunk payload;
    CriUint32 phase;
    if (player == 0 || ((CriMvHeaderQueueView*)player)->Queue == 0)
        return;
    res = getInternalStatus(player);
    if (res == 0 || res == 1 || res == 2)
        return;
    phase = ((CriMvHeaderRingState*)player)->Phase % 2;
    if (phase == ((CriMvHeaderRingState*)player)->CurrentIndex)
        return;
    if (((CriMvHeaderStreamList*)player)->Entries[((CriMvHeaderRingState*)player)->CurrentIndex].State == 1)
        return;
    memset(&payload, 0, sizeof(payload));
    stream = ((CriMvHeaderQueueView*)player)->Queue;
    if ((CriUint32)FUN_1400467b8(stream, 1) > 0)
    {
        FUN_1400467a0(stream, 1, -1, &chunk);
        if (chunk.Size >= 0x20)
        {
            FUN_14003b3fc(chunk.Data, chunk.Size, info);
            payload.Data = criUsfCmn_GetContents(chunk.Data, chunk.Size, &payload.Size);
            if (info[0] == 0x43524944)
            {
                target = &((CriMvHeaderStreamList*)player)->Entries[((CriMvHeaderRingState*)player)->CurrentIndex];
                retrieveHeaderInfo(player, target, &payload);
                ((CriMvHeaderStreamList*)player)->Entries[((CriMvHeaderRingState*)player)->CurrentIndex].History0 = target->Field4c;
                ((CriMvHeaderStreamList*)player)->Entries[((CriMvHeaderRingState*)player)->CurrentIndex].History4 = target->Field10;
                ((CriMvHeaderStreamList*)player)->Entries[((CriMvHeaderRingState*)player)->CurrentIndex].History8 = target->Field250;
                ((CriMvHeaderStreamList*)player)->Entries[((CriMvHeaderRingState*)player)->CurrentIndex].HistoryC = target->Field270;
                ((CriMvHeaderStreamList*)player)->Entries[((CriMvHeaderRingState*)player)->CurrentIndex].History10 = 0;
                ((CriMvHeaderStreamList*)player)->Entries[((CriMvHeaderRingState*)player)->CurrentIndex].State = 1;
            }
        }
        criSj_PutChunk(stream, 0, &chunk);
    }
}

// Select the next subtitle chunk matching a channel while consuming decoder control records.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): count, sj, record, headerInfo, accepted, item.
// @0x140036b80
CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* output, CriSint32 channel)
{
    CriSint32 count;
    CriMovieChunkQueueRecord record;
    void* sj;
    CriUsfChunkHeader headerInfo;
    CriMvSubtitleItemInfo item;
    CriBool accepted;
    count = 0;
    memset(output, 0, sizeof(*output));
    if (player == NULL)
        return 0;
    if (((CriMvSubtitleFields*)player)->Queue == NULL)
        return 0;
    sj = ((CriMvSubtitleFields*)player)->Queue;
    for (;;)
    {
        FUN_1400467a0(sj, 1, -1, &record);
        if (record.Chunk == NULL || record.Type < 0x20)
            break;
        FUN_14003b3fc((const CriUint8*)record.Chunk, record.Type, &headerInfo);
        if (headerInfo.Type == 1 || headerInfo.Type == 2)
        {
            if (headerInfo.Type == 1)
            {
                accepted = recordSubtitleHeader(player, (const CriMovieInputChunk*)&record);
                if (accepted == 0)
                {
                    criSj_UngetChunk(sj, 1, &record);
                    return 0;
                }
                ++((CriMvSubtitleFrameCounter*)player)->Value;
            }
            criSj_PutChunk(sj, 0, &record);
            ++count;
        }
        else
        {
            analyzeSubtitleInfo(player, (CriMvSubtitleChunk*)&record, &item);
            if (channel != item.Channel)
            {
                criSj_PutChunk(sj, 0, &record);
                ++count;
            }
            else
            {
                output->Data = (const CriUint8*)record.Chunk;
                output->Size = record.Type;
                break;
            }
        }
    }
    return count;
}
#pragma optimize("", on)
