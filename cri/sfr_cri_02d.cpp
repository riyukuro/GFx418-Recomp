// Recovered CRI Movie helpers from MapleStory2.exe, written from the executable's behavior: the functions of the /Od
// criMvPly objs in sfr_cri_02c's range that only byte-match as C. VS2008 /Od often keeps a value loaded after a call
// in r11 when it compiles C where it picks rax or rcx when it compiles C++ (cf. sfr_cri_03d). The rest of the criMvPly
// layer stays in sfr_cri_02c, which can't be C (cri_movie.h is C++). This unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1
// cl with /TC, cmake/ms2-unit-profiles.cmake): only string.h, C89 declarations at the top of each block, and the
// parameter types of the definitions in sfr_cri_02c, so a C++ compile (clang-cl) mangles every name as they do.
// MS2-UNIT: sfr_cri_02d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14002eb20-0x14002f850 .text$mn
// MS2-RANGE: 0x14002fbe0-0x1400301d0 .text$mn
// MS2-RANGE: 0x140030280-0x140030b50 .text$mn
// MS2-RANGE: 0x140030cb0-0x140030e50 .text$mn
// MS2-RANGE: 0x140031290-0x1400313d0 .text$mn
// MS2-RANGE: 0x140031990-0x140031aa0 .text$mn
// MS2-RANGE: 0x140032090-0x140032650 .text$mn
// MS2-RANGE: 0x140033030-0x140033610 .text$mn
// MS2-RANGE: 0x140033810-0x140033d70 .text$mn
// MS2-RANGE: 0x140034330-0x1400344f0 .text$mn
// MS2-RANGE: 0x140034730-0x140034920 .text$mn
// MS2-RANGE: 0x140034d40-0x140034e70 .text$mn
// MS2-RANGE: 0x1400356a0-0x140035710 .text$mn
// MS2-RANGE: 0x140035800-0x1400359e0 .text$mn
// MS2-RANGE: 0x1400361a0-0x1400363b0 .text$mn
// MS2-RANGE: 0x140036470-0x140036590 .text$mn
// MS2-RANGE: 0x140036710-0x1400369e0 .text$mn
// MS2-RANGE: 0x140036b80-0x140036d50 .text$mn
// MS2-RANGE: 0x140037400-0x140037740 .text$mn
// MS2-RANGE: 0x140037a40-0x140038000 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <string.h>
#pragma function(memset, memcpy)                // the exe CRI objs call memset and memcpy here

typedef unsigned char CriUint8;
typedef unsigned short CriUint16;
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
typedef struct _criheap_struct* CriHeap;
typedef struct CriMvOwnedResourceView
{
    CriUint32 State;                            /* 0x000 */
    CriSint32 Status;                           /* 0x004 */
    CriUint8 Reserved008[0x10];
    void* Work;                                 /* 0x018 */
    struct _RTL_CRITICAL_SECTION* Lock;         /* 0x020 */
    CriUint8 Reserved028[0xd38];
    CriSint32 ReadMode;                         /* 0xd60 */
    CriUint8 Reservedd64[4];
    void* Demux;                                /* 0xd68 */
    CriUint32 DemuxStreams;                     /* 0xd70 */
    CriUint32 Fieldd74;                         /* 0xd74 */
    void* InputBuffer;                          /* 0xd78 */
    void* ReadBuffer;                           /* 0xd80 */
    CriUint8 Reservedd88[0x18];
    void* MemoryQueue;                          /* 0xda0 */
    CriUint8 Reservedda8[0x18];
    CriHeap Heap;                               /* 0xdc0 */
    CriUint32 InputBufferSize;                  /* 0xdc8 */
    CriUint8 Reserveddcc[4];
    CriHeap HeapHandle;                         /* 0xdd0 */
    CriUint32 LocalHeapSize;                    /* 0xdd8 */
    CriUint8 Reservedddc[4];
    void* MetaWork;                             /* 0xde0 */
    CriHeap UserHeap;                           /* 0xde8 */
} CriMvOwnedResourceView;
typedef struct CriFixedAllocator { CriUint8* Begin; CriUint8* Current; CriUint32 Size; } CriFixedAllocator;
typedef struct CriSjRbfConfigView { CriSint32 Version; CriUint32 Size; CriSint32 Reserved08; CriSint32 Align; void* Name; } CriSjRbfConfigView;
typedef struct CriSjUniConfigView { CriSint32 Version; CriSint32 Mode; CriSint32 Chunks; } CriSjUniConfigView;
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
// the C++ units define these with C linkage (extern "C"), so the clang-cl C++ compile declares them so too
#ifdef __cplusplus
#define CRI_C_LINKAGE extern "C"
#else
#define CRI_C_LINKAGE
#endif
CRI_C_LINKAGE CriUint32 decideReadBufferExtSize(void* params);
CRI_C_LINKAGE CriSint32 criSjRbf_GetRequiredMemorySizeWithConfig(CriUint32 size, CriUint32 extSize, CriUint32 alignment, const CriUint32* config);
CRI_C_LINKAGE void*     crimvply_findVdecIF(CriSint32 codecId);
CRI_C_LINKAGE CriSint32 FUN_140044400(void* decoder, CriUint32 width, CriUint32 height, CriUint32 pools);
CRI_C_LINKAGE void*     crimvply_findAlphadecIfIF(CriSint32 codecId);
CRI_C_LINKAGE CriSint32 FUN_140043a80(void* decoder, CriSint32 width, CriSint32 height, CriSint32 pools);
CRI_C_LINKAGE CriSint32 criMvPlyAmng_CalcAmngWorkSize(const void* params);
CRI_C_LINKAGE CriSint32 criMvPlyAmng_CalcAudioDecoderWorkSize(const void* player, const CriUint32* audio);
CRI_C_LINKAGE CriSint32 criSjUni_GetRequiredMemorySizeWithConfig(CriUint32 size, CriUint32 alignment, const CriUint32* config);
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
typedef struct CriUsfChunkHeader            // criUsfCmn_ParseUsfHeaderStd fills 0x24 bytes
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

CRI_C_LINKAGE CriBool allocateMetaWork(void* player);
CRI_C_LINKAGE void FUN_140034330(void* player, void* source, void* readBuffer, void* dataQueue);
CRI_C_LINKAGE void criUsfDmx_Stop(void* demux);
CRI_C_LINKAGE void criUsfDmx_Execute(void* demux);
CRI_C_LINKAGE CriSint32 criUsfDmx_GetStatus(void* demux);
CRI_C_LINKAGE void crimvply_transitErrorState(void* player, void* message);
CRI_C_LINKAGE void crimvply_occurUserError(void* owner, const char* message, CriSint32 value);
CRI_C_LINKAGE void criMvPlyAmng_TerminateSupply(void* audioManager);
CRI_C_LINKAGE void criVdec_TerminateSupply(void* decoder);
CRI_C_LINKAGE void criAlphaDec_TerminateSupply(void* decoder);
CRI_C_LINKAGE void criUsfDmx_Start(void* demux);
CRI_C_LINKAGE void criUsfDmx_SetInputSj(void* demux, void* value);
CRI_C_LINKAGE void criUsfDmx_SetOutputSj(void* demux, CriUint32 index, void* stream, CriUint32 flags, CriSint32 limit);
#ifdef __cplusplus
CRI_C_LINKAGE void criUsfDmx_SetThrououtSwitch(void* demux, CriUint8 value);  // the C++ name of sfr_cri_03b's definition
#else
CRI_C_LINKAGE void criUsfDmx_SetThrououtSwitch(void* demux, CriBool value);   // the exe C callers pass a 32-bit switch (mov edx,1)
#endif
CRI_C_LINKAGE void criSj_Reset(void* streamJoint);
CRI_C_LINKAGE void* criMvPly_GetInputSj(void* player, CriUint32* available, CriUint32* bounded);
CRI_C_LINKAGE void criSj_UngetChunk(void* queue, CriSint32 operation, void* chunk);
CRI_C_LINKAGE CriSint32 FUN_1400467b8(void* ringBuffer, CriSint32 query);
CRI_C_LINKAGE void criSj_GetInputChunk(void* object, void* value);
CRI_C_LINKAGE void criMvPly_AddInputMemory(void* player, void* chunk, CriUint32 type);
CRI_C_LINKAGE void criSj_PutInputChunk(void* streamJoint, const void* chunk, CriUint32 size);
CRI_C_LINKAGE void crimvply_occurFatalError(void* owner, const char* message, CriSint32 value);
CRI_C_LINKAGE void criSj_PutChunk(void* queue, CriSint32 operation, void* chunk);
CRI_C_LINKAGE const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);
typedef struct CriUsfStandardHeader CriUsfStandardHeader;
CRI_C_LINKAGE CriBool criMvPly_IsSetDefaultDecryptionKey(void);
CRI_C_LINKAGE CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, CriUsfStandardHeader* header);
CRI_C_LINKAGE void retrieveHeaderInfo(void* player, void* stream, const struct CriMovieParsedChunk* parsed);
struct CriUtfRtvView;
struct CriMvStreamingParameters;
struct _RTL_CRITICAL_SECTION;
CRI_C_LINKAGE void FUN_140030c70(void* player);
CRI_C_LINKAGE CriBool freeMetaWork(void* player);
CRI_C_LINKAGE void criUsfDmx_Destroy(void* demux);
CRI_C_LINKAGE void criCs_Destroy(struct _RTL_CRITICAL_SECTION* section);
void* FUN_1400385c8(void* work, CriSint32 size);
CRI_C_LINKAGE void* criSj_CreateNamedRingBuffer(void* heap, CriUint32 size, CriUint32 flags, CriUint32 align, CriUint64 name);
CRI_C_LINKAGE void* criUsfDmx_Create(void* heap, CriSint32 streams);
CRI_C_LINKAGE void* criSj_CreateUniversal(void* heap, CriUint32 mode, CriUint32 count);
CRI_C_LINKAGE void initializeHandleParameters(void* player);
CRI_C_LINKAGE void criMvPly_SetPcmFormat(void* player, CriSint32 format);
CRI_C_LINKAGE void criMvPly_Destroy(CriUint32* object);
CRI_C_LINKAGE void criFixedAllocator_Create(void* begin, CriUint32 size, CriFixedAllocator* allocator);
CRI_C_LINKAGE void criFixedAllocator_Destroy(CriFixedAllocator* allocator);
CRI_C_LINKAGE void* criFixedAllocator_Allocate(CriFixedAllocator* allocator, CriUint32 size, CriUint32 align);
CRI_C_LINKAGE CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config);
CRI_C_LINKAGE void* criSjRbf_Create(const void* config, void* work, CriSint32 workSize);
CRI_C_LINKAGE CriSint32 criUsfDmx_CalculateWorkSizeWithWork(CriSint32 workCount);
CRI_C_LINKAGE void* criUsfDmx_CreateWithWork(CriSint32 count, void* work, CriSint32 workSize);
CRI_C_LINKAGE CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config);
CRI_C_LINKAGE void* criSjUni_Create(const void* config, void* work, CriSint32 workSize);
extern CriSint32 DAT_143ffd500;
#ifdef __cplusplus
extern "C" {
#endif
CriHeap criHeap_Create(void* ptr, CriSint32 size);
void* criHeap_AllocFix(CriHeap heap, CriSint32 size, const char* name, CriSint32 align);
void criHeap_Destroy(CriHeap heap);
CriSint32 criHeap_Free(CriHeap heap, void* ptr);
#ifdef __cplusplus
}
#endif
extern CriSint32 DAT_143b27948;
extern CriUint8 DAT_143b27a48[0x20];
extern CriUint8 DAT_143b27a68[0x20];
CRI_C_LINKAGE void*     criUtfRtv_Create(void* heap, void* data, CriUint32 size);                                     /* 14003b348 */
CRI_C_LINKAGE CriUint32 FID_conflict_criUtfRtv_GetDataSint32Fn(const struct CriUtfRtvView* object, CriUint32 index, const char* key); /* 14003a85c */
CRI_C_LINKAGE CriUint32 criUtfRtv_GetNumRecord(const struct CriUtfRtvView* object);                                  /* 14003a45c */
CRI_C_LINKAGE void      criUtfRtv_Destroy(CriUint64* table);                                                         /* 14003a108 */
typedef struct CriUtfRtvCell                // criUtfRtv_GetCellVal output: a string cell's pointer and length
{
    CriUint64 Type;                         // a byte in CRI; no char array, so no /GS cookie
    const char* Data;
    CriUint32 Size;
    CriUint32 Reserved14;
} CriUtfRtvCell;
CRI_C_LINKAGE CriUint32 criUtfRtv_ConvFieldNameToNo(const struct CriUtfRtvView* table, const char* name);
CRI_C_LINKAGE CriSint32 criUtfRtv_GetCellVal(const struct CriUtfRtvView* table, CriUint32 row, CriUint32 field, CriUtfRtvCell* cell);
CRI_C_LINKAGE CriUint64 criUtfRtv_GetDataUint64(const struct CriUtfRtvView* table, CriUint32 row, CriUint32 field);
CRI_C_LINKAGE CriUint32 criUtfRtv_GetDataSint32Fn(const struct CriUtfRtvView* table, CriUint32 row, const char* name);
typedef struct CriMvEventEntry              // the cue event table entries (0x38 bytes)
{
    const char* Name;
    CriUint32 NameSize;
    CriUint32 Reserved0c;
    CriUint64 Time;
    CriUint64 TimeUnit;
    CriUint32 Type;
    CriUint32 Reserved24;
    const char* Param;
    CriUint32 ParamSize;
    CriUint32 Callbacks;
} CriMvEventEntry;
typedef struct CriMvMetaPlayerView
{
    CriUint8 Reserved0[0x8ac];
    CriUint32 CueLimit;                     // 0x8ac
    CriUint64 TimeUnit;                     // 0x8b0
    CriUint8 Reserved8b8[0xd60 - 0x8b8];
    CriUint32 InputMode;                    // 0xd60
    CriUint8 Reservedd64[0xd80 - 0xd64];
    void* MetaSj;                           // 0xd80
    CriUint8 Reservedd88[0xda8 - 0xd88];
    CriUint64 InputBase;                    // 0xda8
    CriUint8 Reserveddb0[8];
    CriUint32 Consumed;                     // 0xdb8
    CriUint8 Reserveddbc[0xdd0 - 0xdbc];
    void* UtfHeap;                          // 0xdd0
    CriUint8 Reserveddd8[0xe80 - 0xdd8];
    CriUint32 MetaCount;                    // 0xe80
    CriUint32 Reservede84;
    const CriUint8* SfvData;                // 0xe88
    CriSint32 SfvSize;                      // 0xe90
    CriUint32 SfvCount;                     // 0xe94
    const CriUint8* AlpData;                // 0xe98
    CriSint32 AlpSize;                      // 0xea0
    CriUint32 AlpCount;                     // 0xea4
    const CriUint8* CueData;                // 0xea8
    CriSint32 CueSize;                      // 0xeb0
    CriUint32 Reservedeb4;
    CriUint32 CueCount;                     // 0xeb8
    CriUint32 Reservedebc;
    CriMvEventEntry* Events;                // 0xec0
} CriMvMetaPlayerView;
CRI_C_LINKAGE void retrieveAudioHeader(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
CRI_C_LINKAGE void FUN_140032650(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
CRI_C_LINKAGE void retrieveSubtitleHeader(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
CRI_C_LINKAGE void FUN_140032db0(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
CRI_C_LINKAGE void retrieveCuePointHeader(void* player, void* workInfo, CriUint32* output, const struct CriMovieParsedChunk* parsed);
CRI_C_LINKAGE CriBool recordSubtitleHeader(void* player, const CriMovieInputChunk* input);
CRI_C_LINKAGE CriBool isEndStopProcessingProc(void* player);
CRI_C_LINKAGE void resetHandle(void* player);
CRI_C_LINKAGE void executeMvPlyPrepServer(void* player);
CRI_C_LINKAGE void executeMvPlyPlayingServer(void* player);
CRI_C_LINKAGE void executeVideoServer(void* player);
CRI_C_LINKAGE void executeUsfServer(void* player);
CRI_C_LINKAGE void criMvPlyAmng_ExecuteAudioServer(void* audioManager, void* player);
CRI_C_LINKAGE CriSint32 getInternalStatus(void* player);
CRI_C_LINKAGE CriBool isLockedInputChunk(const void* player);
CRI_C_LINKAGE void criMvPlyAmng_Destroy(void* manager, void* heap);
CRI_C_LINKAGE void criAlphaDec_Destroy(void* decoder);
CRI_C_LINKAGE void criVdec_Destroy(CriUint64* adapter);
CRI_C_LINKAGE void criSj_Destroy(void* streamJoint);
CRI_C_LINKAGE CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* chunk, CriSint32 channel);
CRI_C_LINKAGE void releaseSubtitleChunk(void* player, CriMvSubtitleChunk* chunk);
CRI_C_LINKAGE void ungetSubtitleChunk(void* player, CriMvSubtitleChunk* chunk);
CRI_C_LINKAGE void analyzeSubtitleInfo(void* player, CriMvSubtitleChunk* chunk, void* outputInfo);
CRI_C_LINKAGE CriBool criMvPly_IsSetDefaultDecryptionKey(void);
CRI_C_LINKAGE void crimvply_makeFrameInfoMembers(void* player, void* output, const void* frameInfo, CriUint64 firstWord, CriUint32 flags);
CRI_C_LINKAGE void crimvply_makeAlphaFrameInfoMembers(void* player, void* destination, const void* source);
CRI_C_LINKAGE void* criAlphaDec_GetAlphaFramePointer(void* decoder, void* frameInfo);
CRI_C_LINKAGE void crimvply_clearAlphaFrameInfoMembers(void* info);
CRI_C_LINKAGE CriBool crimvply_isUnderGetFrameCondition(void* player);
CRI_C_LINKAGE void crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(void* player, const struct CriMvAlphaDecoderFrameInfo* info);
typedef struct CriMvPrepServerView         // the player fields executeMvPlyPrepServer reads
{
    CriUint32 Reserved0;
    CriUint32 Status;                       // 0x004
    CriUint8  Reserved8[0x8];
    CriUint32 TerminateRequested;           // 0x010
    CriUint8  Reserved14[0x884 - 0x14];
    CriUint32 AlphaCallbackMode;            // 0x884
    CriUint8  Reserved888[0xad4 - 0x888];
    CriUint32 HeaderReady;                  // 0xad4
    CriUint8  ReservedAd8[0xb04 - 0xad8];
    CriUint32 MinDecodedPictures;           // 0xb04
    CriUint8  ReservedB08[0xd60 - 0xb08];
    CriUint32 ReadMode;                     // 0xd60
    CriUint32 ReservedD64;
    void*     Demux;                        // 0xd68
    CriUint8  ReservedD70[0x10];
    void*     ReadBuffer;                   // 0xd80
    void*     HeaderBuffer;                 // 0xd88
    CriUint8  ReservedD90[0x10];
    void*     MemoryInput;                  // 0xda0
    CriMovieInputChunk MemoryChunk;         // 0xda8
    CriUint32 MemoryHeaderSize;             // 0xdb8
    CriUint8  ReservedDbc[0xe00 - 0xdbc];
    CriUint32 VideoType;                    // 0xe00
    CriUint32 VideoFlags;                   // 0xe04
    void*     VideoDecoder;                 // 0xe08
    void*     AudioManager;                 // 0xe10
    CriUint8  ReservedE18[0x10];
    void*     SubtitleSj;                   // 0xe28
    CriUint32 SubtitleFrames;               // 0xe30
    CriUint32 ReservedE34;
    CriUint32 AlphaType;                    // 0xe38
    CriUint32 AlphaFlags;                   // 0xe3c
    void*     AlphaDecoder;                 // 0xe40
    CriUint8  ReservedE48[0x10];
    CriSint32 HeaderEnd;                    // 0xe58
    CriUint32 VideoHeaderEnd;               // 0xe5c
    CriUint32 AlphaHeaderEnd;               // 0xe60
    CriUint32 HeaderDone;                   // 0xe64
    CriUint8  ReservedE68[0xed8 - 0xe68];
    CriUint32 RequiredPictures;             // 0xed8
} CriMvPrepServerView;
CRI_C_LINKAGE void criMvPly_SetDemuxOutputSj(void* player, void* value, CriUint32 type, CriUint32 flags);
CRI_C_LINKAGE void FUN_140041df0(void* audioManager, void* callback, void* userData);
CRI_C_LINKAGE void FUN_140044cc0(void* decoder, void* callback, void* userData);
CRI_C_LINKAGE void FUN_140044210(CriUint64* decoder, void* callback, void* userData);
CRI_C_LINKAGE CriUint64 FUN_1400445d0(CriUint64* decoder);
CRI_C_LINKAGE void* FUN_140043c50(void** decoder);
CRI_C_LINKAGE void FUN_140044710(void* decoder);
CRI_C_LINKAGE void FUN_140043d90(void* decoder);
CRI_C_LINKAGE void FUN_140044c60(void* decoder, CriUint32 offset, CriUint32 size);
CRI_C_LINKAGE void FUN_1400441b0(CriUint64* decoder, CriUint32 offset, CriUint32 size);
void FUN_140042700(void* trackSet, void* player);
CRI_C_LINKAGE void criUsfDmx_TerminateSupply(void* demux);
CRI_C_LINKAGE CriSint32 criVdec_GetStatus(void* decoder);
CRI_C_LINKAGE CriUint32 criVdec_GetNumDecPool(void* decoder);
CRI_C_LINKAGE CriSint32 criVdec_GetNumPictureData(void* decoder);
CRI_C_LINKAGE CriSint32 criAlphaDec_GetStatus(void* decoder);
CRI_C_LINKAGE CriUint32 criAlphaDec_GetNumDecPool(void* decoder);
CRI_C_LINKAGE CriSint32 criAlphaDec_GetNumPictureData(void* decoder);
CRI_C_LINKAGE CriSint32 criMvPlyAmng_IsReadyAudioPlayback(void* audioManager, void* player);
CRI_C_LINKAGE CriSint32 FUN_140033d70(void* player, const CriMovieInputChunk* chunk, CriUint8 last);
CRI_C_LINKAGE CriSint32 FUN_1400340f0(void* player, const CriMovieInputChunk* chunk);
CRI_C_LINKAGE CriSint32 FUN_1400341d0(void* player, const CriMovieInputChunk* chunk);
// the C names bind to sfr_cri_02c's C++ definitions in the full exe (alias.py pairs only FUN_<va> names by their VA);
// the hook DLL's ms2sym.obj already maps them to the exe addresses; the C++ callers' mangled names of this unit's two
// definitions (sfr_cri_02c, sfr_cri_07) bind to the plain C names the same way
#ifndef MS2_HOOK_DLL
#endif

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// construct a CRI Movie player and its work queues inside the supplied memory block
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe).
// @0x14002eb20
CRI_C_LINKAGE void* criMvPly_CreateWithWork(void* work, CriSint32 workSize)
{
    void* outWBuf;
    void* inputWork;
    CriFixedAllocator allocator;
    CriSint32 outSjSize;
    CriSint32 sjSize;
    CriSjRbfConfigView params;
    CriSjUniConfigView outputConfig;
    void* demuxWork;
    CriSint32 size1;
    CriMvOwnedResourceView* object;
    CriSint32 sz;
    void* buf1;
    if (DAT_143ffd500 <= 0) {
        crimvply_occurUserError(NULL, "E10051202M : criMvPly_Create was called without Initialization.", 0);
        return NULL;
    }
    if (work == NULL || workSize < 0) {
        crimvply_occurUserError(NULL, "E10051203M : Passed illegal memory or memory size to criMvPly_Create.", 0);
        return NULL;
    }
    criFixedAllocator_Create(work, workSize, &allocator);
    object = (CriMvOwnedResourceView*)criFixedAllocator_Allocate(&allocator, 0xf18, 4);
    if (object == NULL) {
        crimvply_occurUserError(NULL, "E10051204M : Can't allocate handle object memory.", 0xf18);
        return NULL;
    }
    memset(object, 0, 0xf18);
    object->Status = 0;
    object->Heap = NULL;
    object->UserHeap = NULL;
    object->Work = criFixedAllocator_Allocate(&allocator, 0x48, 4);
    if (object->Work == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E10051205M : Can't allocate cs handle memory.", 0x48);
        return NULL;
    }
    object->Lock = (struct _RTL_CRITICAL_SECTION*)FUN_1400385c8(object->Work, 0x48);
    if (object->Lock == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E10051206M : Can't create CriticalSection for CRI Movie.", 0);
        return NULL;
    }
    object->LocalHeapSize = 0x2800;
    object->MetaWork = criFixedAllocator_Allocate(&allocator, object->LocalHeapSize, 4);
    if (object->MetaWork == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E10051207M : Can't allocate internal heap memory.", 0x2800);
        return NULL;
    }
    object->HeapHandle = criHeap_Create(object->MetaWork, object->LocalHeapSize);
    if (object->HeapHandle == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E10051208M : Can't create internal heap handle.", 0);
        return NULL;
    }
    object->InputBufferSize = 0x2800;
    memset(&params, 0, sizeof(params));
    params.Version = 1;
    params.Name = NULL;
    params.Size = object->InputBufferSize;
    params.Reserved08 = 0;
    params.Align = 0x40;
    sjSize = criSjRbf_CalculateWorkSize((const CriSint32*)&params);
    inputWork = criFixedAllocator_Allocate(&allocator, sjSize, 4);
    if (inputWork == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E10051209M : Cannot allocate memory for input SJ to analyze header chunk.", sjSize);
        return NULL;
    }
    object->InputBuffer = criSjRbf_Create(&params, inputWork, sjSize);
    if (object->InputBuffer == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E10051210M : Cannot create input SJ to analyze header chunk.", 0);
        return NULL;
    }
    object->DemuxStreams = 8;
    size1 = criUsfDmx_CalculateWorkSizeWithWork(object->DemuxStreams);
    demuxWork = criFixedAllocator_Allocate(&allocator, size1, 4);
    if (demuxWork == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E10051201M : Cannot allocate memory for for UsfDemux.", size1);
        return NULL;
    }
    object->Demux = criUsfDmx_CreateWithWork(object->DemuxStreams, demuxWork, size1);
    if (object->Demux == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E05063007M : Can't create UsfDemux Handle.", 0);
        return NULL;
    }
    memset(&outputConfig, 0, sizeof(outputConfig));
    outputConfig.Version = 1;
    outputConfig.Mode = 0;
    outputConfig.Chunks = 0x40;
    outSjSize = criSjUni_CalculateWorkSize((const CriSint32*)&outputConfig);
    outWBuf = criFixedAllocator_Allocate(&allocator, outSjSize, 4);
    if (outWBuf == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E05063008M : Cannot allocate memory for output SJ to analyze header.", outSjSize);
        return NULL;
    }
    object->ReadBuffer = criSjUni_Create(&outputConfig, outWBuf, outSjSize);
    if (object->ReadBuffer == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E05063009M : Can't create output SJ to analyze header.", 0);
        return NULL;
    }
    object->Fieldd74 = 0;
    memset(&outputConfig, 0, sizeof(outputConfig));
    outputConfig.Version = 1;
    outputConfig.Mode = 0;
    outputConfig.Chunks = 4;
    sz = criSjUni_CalculateWorkSize((const CriSint32*)&outputConfig);
    buf1 = criFixedAllocator_Allocate(&allocator, sz, 4);
    if (buf1 == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E11112531M : Cannot allocate memory for input SJ to play from memory.", sz);
        return NULL;
    }
    object->MemoryQueue = criSjUni_Create(&outputConfig, buf1, sz);
    if (object->MemoryQueue == NULL) {
        criMvPly_Destroy((CriUint32*)object);
        crimvply_occurUserError(NULL, "E11112532M : Can't create input SJ to play from memory.", 0);
        return NULL;
    }
    object->ReadMode = 0;
    initializeHandleParameters(object);
    object->State = 1;
    criMvPly_SetPcmFormat(object, 0);
    criFixedAllocator_Destroy(&allocator);
    return object;
}

// allocate and initialize a CRI Movie player from the caller's heap
// @0x14002f1f0
CRI_C_LINKAGE void* criMvPly_CreateWithConfig(CriHeap heap)
{
    CriMvOwnedResourceView* ply;
    if (DAT_143ffd500 <= 0) {
        crimvply_occurUserError(NULL, "E09031803M : criMvPly_Create was called without Initialization.", 0);
        return NULL;
    }
    if (heap == NULL)
        return NULL;
    ply = (CriMvOwnedResourceView*)criHeap_AllocFix(heap, 0xf18, "CriMvPly: HnObj", 4);
    if (ply == NULL) {
        crimvply_occurUserError(NULL, "E05063001M : Can't allocate handle object memory.", 0xf18);
        return NULL;
    }
    memset(ply, 0, 0xf18);
    ply->Status = 0;
    ply->Heap = heap;
    ply->UserHeap = heap;
    ply->Work = criHeap_AllocFix(heap, 0x48, "CriMvPly: CriCsWork", 4);
    if (ply->Work == NULL) {
        criHeap_Free(heap, ply);
        crimvply_occurUserError(NULL, "E08102001M : Can't allocate cs handle memory.", 0x48);
        return NULL;
    }
    ply->Lock = (struct _RTL_CRITICAL_SECTION*)FUN_1400385c8(ply->Work, 0x48);
    if (ply->Lock == NULL) {
        criHeap_Free(heap, ply->Work);
        criHeap_Free(heap, ply);
        crimvply_occurUserError(NULL, "E05081501M : Can't create CriticalSection for CRI Movie.", 0);
        return NULL;
    }
    ply->LocalHeapSize = 0x2800;
    ply->MetaWork = criHeap_AllocFix(heap, 0x2800, "CriMvPly: LocalHeapBuf", 4);
    if (ply->MetaWork == NULL) {
        criMvPly_Destroy((CriUint32*)ply);
        crimvply_occurUserError(NULL, "E05063002M : Can't allocate internal heap memory.", 0x2800);
        return NULL;
    }
    ply->HeapHandle = criHeap_Create(ply->MetaWork, ply->LocalHeapSize);
    if (ply->HeapHandle == NULL) {
        criMvPly_Destroy((CriUint32*)ply);
        crimvply_occurFatalError(NULL, "E05063005M : Can't create internal heap handle.", 0);
        return NULL;
    }
    ply->InputBufferSize = 0x2800;
    ply->InputBuffer = criSj_CreateNamedRingBuffer(heap, ply->InputBufferSize, 0, 0x40, (CriUint64)"CriMvPly: HeadAnalyInput");
    if (ply->InputBuffer == NULL) {
        criMvPly_Destroy((CriUint32*)ply);
        crimvply_occurUserError(NULL, "E05063006M : Can't create input SJ for header analyze input.", 0);
        return NULL;
    }
    ply->DemuxStreams = 8;
    ply->Demux = criUsfDmx_Create(heap, ply->DemuxStreams);
    if (ply->Demux == NULL) {
        criMvPly_Destroy((CriUint32*)ply);
        crimvply_occurUserError(NULL, "E05063007M : Can't create UsfDemux Handle.", 0);
        return NULL;
    }
    ply->ReadBuffer = criSj_CreateUniversal(heap, 0, 0x40);
    if (ply->ReadBuffer == NULL) {
        criMvPly_Destroy((CriUint32*)ply);
        crimvply_occurUserError(NULL, "E05063008M : Can't create output SJ for analyze header output.", 0);
        return NULL;
    }
    ply->Fieldd74 = 0;
    ply->MemoryQueue = criSj_CreateUniversal(heap, 1, 4);
    if (ply->MemoryQueue == NULL) {
        criMvPly_Destroy((CriUint32*)ply);
        crimvply_occurUserError(NULL, "E05070601M : Can't create SJ for memory playback.", 0);
        return NULL;
    }
    ply->ReadMode = 0;
    initializeHandleParameters(ply);
    ply->State = 1;
    criMvPly_SetPcmFormat(ply, 0);
    return ply;
}

// release decoder queues, demux state, and heap-owned CRI Movie work areas
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): sjrb, insj, cs, sjmemory, heap, objwork.
// @0x14002f610
CRI_C_LINKAGE void criMvPly_Destroy(CriUint32* object)
{
    void* sjrb;
    void* insj;
    struct _RTL_CRITICAL_SECTION* cs;
    void* sjmemory;
    CriHeap heap;
    void* objwork;
    if (object == NULL)
        return;
    ((CriMvOwnedResourceView*)object)->State = 0;   /* Status is left as is */
    if (((CriMvOwnedResourceView*)object)->Status != 0 && ((CriMvOwnedResourceView*)object)->Status != 7)
        crimvply_occurUserError(object, "E05063009M : Don't call criMvPly_Destroy() at illigal status",
                                ((CriMvOwnedResourceView*)object)->Status);
    FUN_140030c70(object);
    freeMetaWork(object);
    sjrb = ((CriMvOwnedResourceView*)object)->ReadBuffer;
    if (sjrb != NULL) {
        criSj_Destroy(sjrb);
        ((CriMvOwnedResourceView*)object)->ReadBuffer = NULL;
    }
    if (((CriMvOwnedResourceView*)object)->Demux != NULL) {
        criUsfDmx_Destroy(((CriMvOwnedResourceView*)object)->Demux);
        ((CriMvOwnedResourceView*)object)->Demux = NULL;
    }
    insj = ((CriMvOwnedResourceView*)object)->InputBuffer;
    if (insj != NULL) {
        criSj_Destroy(insj);
        ((CriMvOwnedResourceView*)object)->InputBuffer = NULL;
    }
    sjmemory = ((CriMvOwnedResourceView*)object)->MemoryQueue;
    if (sjmemory != NULL) {
        criSj_Destroy(sjmemory);
        ((CriMvOwnedResourceView*)object)->MemoryQueue = NULL;
    }
    if (((CriMvOwnedResourceView*)object)->HeapHandle != NULL) {
        criHeap_Destroy(((CriMvOwnedResourceView*)object)->HeapHandle);
        ((CriMvOwnedResourceView*)object)->HeapHandle = NULL;
    }
    heap = ((CriMvOwnedResourceView*)object)->Heap;
    if (heap != NULL && ((CriMvOwnedResourceView*)object)->MetaWork != NULL) {
        criHeap_Free(heap, ((CriMvOwnedResourceView*)object)->MetaWork);
        ((CriMvOwnedResourceView*)object)->MetaWork = NULL;
    }
    cs = ((CriMvOwnedResourceView*)object)->Lock;
    if (cs != NULL) {
        ((CriMvOwnedResourceView*)object)->Lock = NULL;
        criCs_Destroy(cs);
    }
    objwork = ((CriMvOwnedResourceView*)object)->Work;
    if (heap != NULL && objwork != NULL) {
        ((CriMvOwnedResourceView*)object)->Work = NULL;
        criHeap_Free(heap, objwork);
    }
    if (heap != NULL)
        criHeap_Free(heap, object);
}

// translate the active CRI stream slot into the public streaming-parameter record
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): sti, oaud, i, vinfo, vprm, track, defTrack,
// oalph, info, alph, sno.
// @0x14002fbe0
CRI_C_LINKAGE void criMvPly_GetStreamingParameters(void* player, struct CriMvStreamingParameters* output)
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

// The player fields that crimvply_AllocateWorkBufferInCs fills in.
typedef struct CriMvAllocWorkView
{
    CriUint8 Reserved0[0x640];
    CriUint32 VideoPitch;                    // 0x640
    CriUint8 Reserved644[0x894 - 0x644];
    CriUint32 AlphaPitch;                    // 0x894
    CriUint8 Reserved898[0xad4 - 0x898];
    CriSint32 StartReady;                    // 0xad4
    CriMvStreamParamsView Params;            // 0xad8
    CriSint32 InputMode;                     // 0xd60: 0 = read buffer, otherwise memory input
    CriUint8 ReservedD64[0xd88 - 0xd64];
    void* ReadBuffer;                        // 0xd88
    CriUint8 ReservedD90[0xdf0 - 0xd90];
    void* Heap;                              // 0xdf0
    CriUint32 ReadSize;                      // 0xdf8
    CriUint32 ReadExtension;                 // 0xdfc
    CriUint32 VideoTag;                      // 0xe00
    CriUint32 VideoTagHigh;                  // 0xe04
    void* VideoDecoder;                      // 0xe08
    void* AudioManager;                      // 0xe10
    CriUint8 ReservedE18[0xe28 - 0xe18];
    void* SubtitleSj;                        // 0xe28
    CriUint8 ReservedE30[4];
    CriSint32 SubtitleChannel;               // 0xe34
    CriUint8 ReservedE38[8];
    void* AlphaDecoder;                      // 0xe40
    CriUint32 ChunkSize;                     // 0xe48
    CriUint32 ChunkExtension;                // 0xe4c
    const CriUint8* ChunkData;               // 0xe50
} CriMvAllocWorkView;
// The decoder configuration passed to the video and alpha decoder Create calls.
typedef struct CriMvDecoderConfig
{
    CriUint32 Width, Height, PlayerFormat, PlayerPitch, StreamFormat;
    CriUint32 Reserved;
    const CriUint8* OutputBuffer;
    CriUint32 BufferSize, BufferExtension;
} CriMvDecoderConfig;
// CriMvVideoParameters (0x30) and CriMvAlphaParameters (0x1c)
typedef struct CriMvAllocVideoView { CriUint32 MaxWidth, MaxHeight, DispWidth, DispHeight, NumFramePools, Framerate, TotalFrames, Unk1c[5]; } CriMvAllocVideoView;
typedef struct CriMvAllocAlphaView { CriUint32 MaxWidth, MaxHeight, DispWidth, DispHeight, Framerate, TotalFrames, AlphaType; } CriMvAllocAlphaView;
CRI_C_LINKAGE void criSj_GetChunk(void* object, CriSint32 operation, CriUint32 limit, void* output);
CRI_C_LINKAGE void* criAlphaDec_Create(void* implementation, void* heap, void* parameter);
CRI_C_LINKAGE void* criVdec_Create(void* implementation, void* heap, void* parameter);
CRI_C_LINKAGE CriSint32 criMvPly_IsSetDefaultDecryptionKey(void);
CRI_C_LINKAGE void FUN_140044de0(void* decoder, void* first, void* second);
CRI_C_LINKAGE void FUN_140044c10(void* decoder, CriUint32 mask);
CRI_C_LINKAGE void FUN_140044330(CriUint64* pair, void* first, void* second);
CRI_C_LINKAGE void FUN_140037a40(const CriMovieInputChunk* current, const CriMovieInputChunk* previous, void* player);
CRI_C_LINKAGE void FUN_140038000(void** record, void* userData);
CRI_C_LINKAGE void setProcessorParams(void* player, void* videoDecoder, void* alphaDecoder);
CRI_C_LINKAGE void* criMvPlyAmng_Create(void* owner, void* heap, const void* config);
CRI_C_LINKAGE CriSint32 criMvPlyAmng_CreateAudioDecoder(void* manager, void* player, void* source, const CriUint32* streamInfo,
    CriUint32 track, CriSint32 flags);
CRI_C_LINKAGE void criMvPlyAmng_SetDecryptCallback(void* manager, void* callback, void* userData, CriSint32 stream);

// Configure the movie's read queue, decoder interfaces, audio manager, and output stream.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): aprm, inp (video parameters), mode (status),
// bound (read extension), fsize (read size), chunk, load (video interface), fmt (video config),
// lane (alpha interface), fill (alpha config), done.
// @0x140030280
CRI_C_LINKAGE CriUint32 crimvply_AllocateWorkBufferInCs(void* player, void* heap, void* work)
{
    const CriMvAllocAlphaView* aprm;
    const CriMvAllocVideoView* inp;
    CriSint32 mode;
    CriUint32 bound;
    CriUint32 fsize;
    CriMovieInputChunk chunk;
    void* load;
    CriMvDecoderConfig fmt;
    void* lane;
    CriMvDecoderConfig fill;
    CriSint32 done;
#define MS2_ALLOC_PLAYER ((CriMvAllocWorkView*)player)
#define MS2_ALLOC_WORK ((const CriMvStreamParamsView*)work)
    mode = getInternalStatus(player);
    if (mode != 0 && mode != 2)
    {
        crimvply_occurUserError(player, "E05063010M : Don't call criMvPly_AllocateWorkBuffer() at illigal status.", mode);
        return 0;
    }
    if (MS2_ALLOC_PLAYER->StartReady == 1)
        FUN_140030c70(player);
    MS2_ALLOC_PLAYER->Params = *MS2_ALLOC_WORK;
    MS2_ALLOC_PLAYER->Heap = heap;
    if (MS2_ALLOC_PLAYER->InputMode == 0)
    {
        if (MS2_ALLOC_WORK->Head[3] == 0xffffffff)
        {
            fsize = (CriUint32)((float)(MS2_ALLOC_WORK->Head[0] / 8) * MS2_ALLOC_WORK->BufferingTime);
            if (fsize < MS2_ALLOC_WORK->Head[2])
                fsize = MS2_ALLOC_WORK->Head[2];
        }
        else
            fsize = MS2_ALLOC_WORK->Head[3];
        fsize = (fsize + 0x800) / 0x800 * 0x800;
        bound = decideReadBufferExtSize(work);
        MS2_ALLOC_PLAYER->ReadSize = fsize;
        MS2_ALLOC_PLAYER->ReadExtension = bound;
        MS2_ALLOC_PLAYER->ReadBuffer = criSj_CreateNamedRingBuffer(heap, fsize, bound, 0x40, (CriUint64)"CriMvPly: ReadBuf");
        if (MS2_ALLOC_PLAYER->ReadBuffer == NULL)
        {
            crimvply_occurUserError(player, "E05063012M : Can't create SJ for read buffer.", 0);
            FUN_140030c70(player);
            return 0;
        }
    }
    else
    {
        fsize = 0;
        bound = 0;
        MS2_ALLOC_PLAYER->ReadSize = 0;
        MS2_ALLOC_PLAYER->ReadExtension = 0;
        MS2_ALLOC_PLAYER->ReadBuffer = NULL;
    }
    if (MS2_ALLOC_PLAYER->InputMode == 0)
    {
        MS2_ALLOC_PLAYER->ChunkSize = fsize;
        MS2_ALLOC_PLAYER->ChunkExtension = bound;
        criSj_GetChunk(MS2_ALLOC_PLAYER->ReadBuffer, 0, 0xffffffff, &chunk);
        MS2_ALLOC_PLAYER->ChunkData = chunk.Data;
        criSj_UngetChunk(MS2_ALLOC_PLAYER->ReadBuffer, 0, &chunk);
    }
    if (MS2_ALLOC_WORK->Head[4] > 0)
    {
        load = NULL;
        inp = (const CriMvAllocVideoView*)MS2_ALLOC_WORK->Video;
        load = crimvply_findVdecIF((CriSint32)inp->Unk1c[3]);
        if (load == NULL)
        {
            crimvply_occurUserError(player, "E11030201M : Not found any avilable codec for the video stream. Attach a codec module before the Initialize function.", 0);
            FUN_140030c70(player);
            return 0;
        }
        MS2_ALLOC_PLAYER->VideoTag = 0x40534656;
        MS2_ALLOC_PLAYER->VideoTagHigh = 0;
        memset(&fmt, 0, sizeof(fmt));
        fmt.Width = inp->MaxWidth;
        fmt.Height = inp->MaxHeight;
        fmt.StreamFormat = inp->NumFramePools;
        fmt.PlayerFormat = MS2_ALLOC_PLAYER->Params.Head[1];
        fmt.PlayerPitch = MS2_ALLOC_PLAYER->VideoPitch;
        if (MS2_ALLOC_PLAYER->InputMode == 0)
        {
            fmt.OutputBuffer = MS2_ALLOC_PLAYER->ChunkData;
            fmt.BufferSize = MS2_ALLOC_PLAYER->ChunkSize;
            fmt.BufferExtension = MS2_ALLOC_PLAYER->ChunkExtension;
        }
        else
        {
            fmt.OutputBuffer = NULL;
            fmt.BufferSize = 0;
            fmt.BufferExtension = 0;
        }
        MS2_ALLOC_PLAYER->VideoDecoder = criVdec_Create(load, heap, &fmt);
        if (MS2_ALLOC_PLAYER->VideoDecoder == NULL)
        {
            crimvply_occurUserError(player, "E05063013M : Can't create Video decoder.", 0);
            FUN_140030c70(player);
            return 0;
        }
        if (criMvPly_IsSetDefaultDecryptionKey() == 1)
            FUN_140044de0(MS2_ALLOC_PLAYER->VideoDecoder, (void*)FUN_140037a40, player);
        FUN_140044c10(MS2_ALLOC_PLAYER->VideoDecoder, MS2_ALLOC_WORK->Video[5]);
        if (MS2_ALLOC_WORK->NumAlpha > 0)
        {
            lane = NULL;
            aprm = (const CriMvAllocAlphaView*)MS2_ALLOC_WORK->Alpha;
            lane = crimvply_findAlphadecIfIF(*(const CriSint32*)((const CriUint8*)aprm + 0x1c));
            if (lane == NULL)
            {
                crimvply_occurUserError(player, "E11030701M : Not found any avilable codec for the alpha stream. Attach a codec module before the Initialize function", 0);
                FUN_140030c70(player);
                return 0;
            }
            memset(&fill, 0, sizeof(fill));
            fill.Width = aprm->MaxWidth;
            fill.Height = aprm->MaxHeight;
            fill.StreamFormat = inp->NumFramePools;
            fill.PlayerFormat = MS2_ALLOC_PLAYER->Params.Head[1];
            fill.PlayerPitch = MS2_ALLOC_PLAYER->AlphaPitch;
            fill.OutputBuffer = MS2_ALLOC_PLAYER->ChunkData;
            fill.BufferSize = MS2_ALLOC_PLAYER->ChunkSize;
            fill.BufferExtension = MS2_ALLOC_PLAYER->ChunkExtension;
            MS2_ALLOC_PLAYER->AlphaDecoder = criAlphaDec_Create(lane, heap, &fill);
            if (MS2_ALLOC_PLAYER->AlphaDecoder == NULL)
            {
                crimvply_occurUserError(player, "E08082100M : Can't create Alpha decoder.", 0);
                FUN_140030c70(player);
                return 0;
            }
            if (criMvPly_IsSetDefaultDecryptionKey() == 1)
                FUN_140044330((CriUint64*)MS2_ALLOC_PLAYER->AlphaDecoder, (void*)FUN_140037a40, player);
        }
        else
            MS2_ALLOC_PLAYER->AlphaDecoder = NULL;
        setProcessorParams(player, MS2_ALLOC_PLAYER->VideoDecoder, MS2_ALLOC_PLAYER->AlphaDecoder);
    }
    MS2_ALLOC_PLAYER->AudioManager = criMvPlyAmng_Create(player, heap, work);
    if (MS2_ALLOC_PLAYER->AudioManager == NULL)
    {
        crimvply_occurFatalError(player, "E07090703M : Can't create CriMvPlyAmng handle", 0);
        FUN_140030c70(player);
        return 0;
    }
    if (MS2_ALLOC_WORK->TrackPlayAudio >= 0)
    {
        done = criMvPlyAmng_CreateAudioDecoder(MS2_ALLOC_PLAYER->AudioManager, player, heap,
            MS2_ALLOC_WORK->Audio[MS2_ALLOC_WORK->TrackPlayAudio].Words,
            MS2_ALLOC_WORK->TrackPlayAudio, 0);
        if (done == 0)
        {
            FUN_140030c70(player);
            return 0;
        }
        if (criMvPly_IsSetDefaultDecryptionKey() == 1)
            criMvPlyAmng_SetDecryptCallback(MS2_ALLOC_PLAYER->AudioManager, (void*)FUN_140038000, player, 0);
    }
    MS2_ALLOC_PLAYER->SubtitleSj = criSj_CreateUniversal(heap, 0, 0x40);
    if (MS2_ALLOC_PLAYER->SubtitleSj == NULL)
    {
        crimvply_occurUserError(player, "E06102501M : Can't create Sj for subtitle data.", 0);
        FUN_140030c70(player);
        return 0;
    }
    MS2_ALLOC_PLAYER->SubtitleChannel = MS2_ALLOC_WORK->ChannelPlaySubtitle;
    MS2_ALLOC_PLAYER->StartReady = 1;
    return 1;
#undef MS2_ALLOC_WORK
#undef MS2_ALLOC_PLAYER
}

// release every CRI Movie player subsystem and clear its owned state
// @0x140030cb0
CRI_C_LINKAGE void FUN_140030cb0(void* player)
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
        criHeap_Destroy(*(CriHeap*)((CriUint8*)player + 0xee0));
        *(void**)((CriUint8*)player + 0xee0) = 0;
    }
    *(CriUint32*)((CriUint8*)player + 0xad4) = 0;
}

// advance decoder and audio processing according to the CRI Movie state machine
// @0x140031290
CRI_C_LINKAGE void FUN_140031290(void* player)
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
CRI_C_LINKAGE CriBool FUN_140031990(void* player)
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
    criUsfDmx_SetOutputSj(demux, 0, ((CriMvPlyDemuxFields*)player)->ReadBuffer, 0, (CriUint32)-1);
    criUsfDmx_SetThrououtSwitch(demux, 0);
    criUsfDmx_Start(demux);
    criUsfDmx_Execute(demux);
    return 1;
}

// consume CRI Movie header and stream records until the file's end marker arrives
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): sti, contentsInfo, vinfo, readBytes, track,
// queue, completed, usfHead, hdr, info, alph.
// @0x140032090
CRI_C_LINKAGE CriSint32 FUN_140032090(void* player)
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
        criSj_GetChunk(queue, 1, -1, &usfHead);
        if (usfHead.Type >= 0x20)
        {
            criUsfCmn_ParseUsfHeaderStd((const CriUint8*)usfHead.Chunk, usfHead.Type, (CriUsfStandardHeader*)&hdr);
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
CRI_C_LINKAGE void retrieveHeaderInfo(void* player, void* streamInfo, const struct CriMovieParsedChunk* parsed)
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

// Consume USF metadata records and keep the SFV, ALP and CUE tables; the CUE table fills the event entries.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe).
// @0x140033030
CRI_C_LINKAGE CriBool decodeMetaData(void* player)
{
    const CriUint8* payload;
    CriSint32 clen;
    void* records;
    void* sj;
    CriBool end;
    CriMovieInputChunk ck;
    CriUint32 hdr[9];                       // criUsfCmn_ParseUsfHeaderStd fills 0x24 bytes; the record type is byte 15
    sj = ((CriMvMetaPlayerView*)player)->MetaSj;
    end = 0;
    while ((CriUint32)FUN_1400467b8(sj, 1) > 0)
    {
        criSj_GetChunk(sj, 1, -1, &ck);
        if (ck.Size >= 0x20)
        {
            criUsfCmn_ParseUsfHeaderStd(ck.Data, ck.Size, (CriUsfStandardHeader*)hdr);
            payload = criUsfCmn_GetContents(ck.Data, ck.Size, &clen);
            if (((CriUint8*)hdr)[15] == 0)
            {
                end = 1;
                criSj_UngetChunk(sj, 1, &ck);
                return end;
            }
            else if (((CriUint8*)hdr)[15] == 3)
            {
                ((CriMvMetaPlayerView*)player)->MetaCount++;
                switch (hdr[0])
                {
                case 0x40534656:
                    ((CriMvMetaPlayerView*)player)->SfvData = payload;
                    ((CriMvMetaPlayerView*)player)->SfvSize = clen;
                    records = criUtfRtv_Create(((CriMvMetaPlayerView*)player)->UtfHeap, (void*)payload, clen);
                    ((CriMvMetaPlayerView*)player)->SfvCount = criUtfRtv_GetNumRecord((const struct CriUtfRtvView*)records);
                    criUtfRtv_Destroy((CriUint64*)records);
                    break;
                case 0x40414c50:
                    ((CriMvMetaPlayerView*)player)->AlpData = payload;
                    ((CriMvMetaPlayerView*)player)->AlpSize = clen;
                    records = criUtfRtv_Create(((CriMvMetaPlayerView*)player)->UtfHeap, (void*)payload, clen);
                    ((CriMvMetaPlayerView*)player)->AlpCount = criUtfRtv_GetNumRecord((const struct CriUtfRtvView*)records);
                    criUtfRtv_Destroy((CriUint64*)records);
                    break;
                case 0x40435545:
                {
                    CriUint32 i;
                    CriUint32 params;
                    CriUint32 name;
                    CriUint32 pos;
                    CriUtfRtvCell cell;
                    ((CriMvMetaPlayerView*)player)->CueData = payload;
                    ((CriMvMetaPlayerView*)player)->CueSize = clen;
                    records = criUtfRtv_Create(((CriMvMetaPlayerView*)player)->UtfHeap, (void*)payload, clen);
                    ((CriMvMetaPlayerView*)player)->CueCount = criUtfRtv_GetNumRecord((const struct CriUtfRtvView*)records);
                    if (((CriMvMetaPlayerView*)player)->CueCount < ((CriMvMetaPlayerView*)player)->CueLimit)
                        for (;;) {}
                    name = criUtfRtv_ConvFieldNameToNo((const struct CriUtfRtvView*)records, "name");
                    params = criUtfRtv_ConvFieldNameToNo((const struct CriUtfRtvView*)records, "parameter");
                    pos = criUtfRtv_ConvFieldNameToNo((const struct CriUtfRtvView*)records, "time");
                    for (i = 0; i < ((CriMvMetaPlayerView*)player)->CueCount; i++)
                    {
                        criUtfRtv_GetCellVal((const struct CriUtfRtvView*)records, i, name, &cell);
                        ((CriMvMetaPlayerView*)player)->Events[i].NameSize = cell.Size;
                        if (cell.Size)
                            ((CriMvMetaPlayerView*)player)->Events[i].Name = cell.Data;
                        else
                            ((CriMvMetaPlayerView*)player)->Events[i].Name = 0;
                        ((CriMvMetaPlayerView*)player)->Events[i].Time = criUtfRtv_GetDataUint64((const struct CriUtfRtvView*)records, i, pos);
                        ((CriMvMetaPlayerView*)player)->Events[i].TimeUnit = ((CriMvMetaPlayerView*)player)->TimeUnit;
                        ((CriMvMetaPlayerView*)player)->Events[i].Type = criUtfRtv_GetDataSint32Fn((const struct CriUtfRtvView*)records, i, "cue_type");
                        criUtfRtv_GetCellVal((const struct CriUtfRtvView*)records, i, params, &cell);
                        ((CriMvMetaPlayerView*)player)->Events[i].ParamSize = cell.Size;
                        if (cell.Size)
                            ((CriMvMetaPlayerView*)player)->Events[i].Param = cell.Data;
                        else
                            ((CriMvMetaPlayerView*)player)->Events[i].Param = 0;
                        ((CriMvMetaPlayerView*)player)->Events[i].Callbacks = 0;
                    }
                    criUtfRtv_Destroy((CriUint64*)records);
                    break;
                }
                }
            }
            else if (((CriUint8*)hdr)[15] == 2)
            {
                if (((CriMvMetaPlayerView*)player)->MetaCount > 0)
                    end = 1;
            }
            criSj_PutChunk(sj, 2, &ck);
        }
        else
            criSj_UngetChunk(sj, 1, &ck);
        if (end == 1)
        {
            if (((CriMvMetaPlayerView*)player)->InputMode == 1)
                ((CriMvMetaPlayerView*)player)->Consumed = (CriUint32)((CriUint64)ck.Data - ((CriMvMetaPlayerView*)player)->InputBase + ck.Size);
            break;
        }
    }
    return end;
}

// Start demuxing the prepared movie, hand the stream headers to the decoders, and move the player to READY once
// enough frames are decoded. Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe).
// @0x140033810
CRI_C_LINKAGE void executeMvPlyPrepServer(void* player)
{
    void* videoDecoder;
    void* adecSj;
    void* output;
    void* adec;
    CriUint32 required;
    void* demux;
    CriMovieInputChunk inputChunk;
    void* vSj;
    CriSint32 vdecStatus;
    CriSint32 adecStatus;
    demux = ((CriMvPrepServerView*)player)->Demux;
    videoDecoder = ((CriMvPrepServerView*)player)->VideoDecoder;
    adec = ((CriMvPrepServerView*)player)->AlphaDecoder;
    if (((CriMvPrepServerView*)player)->HeaderReady != 1)
        return;
    if (((CriMvPrepServerView*)player)->ReadMode == 0)
        output = ((CriMvPrepServerView*)player)->HeaderBuffer;
    else
        output = ((CriMvPrepServerView*)player)->MemoryInput;
    if (criUsfDmx_GetStatus(demux) == 0)
    {
        if (((CriMvPrepServerView*)player)->ReadMode == 1)
        {
            criSj_Reset(((CriMvPrepServerView*)player)->MemoryInput);
            criSj_PutChunk(((CriMvPrepServerView*)player)->MemoryInput, 1, &((CriMvPrepServerView*)player)->MemoryChunk);
            criSj_GetChunk(((CriMvPrepServerView*)player)->MemoryInput, 1, ((CriMvPrepServerView*)player)->MemoryHeaderSize, &inputChunk);
            criSj_PutChunk(((CriMvPrepServerView*)player)->MemoryInput, 0, &inputChunk);
        }
        criUsfDmx_SetInputSj(demux, output);
        criSj_Reset(((CriMvPrepServerView*)player)->ReadBuffer);
        criMvPly_SetDemuxOutputSj(player, ((CriMvPrepServerView*)player)->ReadBuffer, 0x43524944, 0xffffffff);
        FUN_140041df0(((CriMvPrepServerView*)player)->AudioManager, (void*)FUN_140033d70, player);
        FUN_140044cc0(videoDecoder, (void*)FUN_1400340f0, player);
        if (videoDecoder != 0)
        {
            vSj = (void*)FUN_1400445d0((CriUint64*)videoDecoder);
            if (vSj == 0)
                crimvply_occurFatalError(player, "E05063022M : Can't get input SJ of Video decoder.", 0);
            criMvPly_SetDemuxOutputSj(player, vSj, ((CriMvPrepServerView*)player)->VideoType, ((CriMvPrepServerView*)player)->VideoFlags);
            FUN_140044710(videoDecoder);
            FUN_140044c60(videoDecoder, ((CriMvPrepServerView*)player)->VideoHeaderEnd, ((CriMvPrepServerView*)player)->HeaderEnd - ((CriMvPrepServerView*)player)->VideoHeaderEnd);
            ((CriMvPrepServerView*)player)->SubtitleFrames = 0;
            if (adec != 0)
            {
                if (((CriMvPrepServerView*)player)->AlphaCallbackMode == 1)
                    FUN_140044210((CriUint64*)((CriMvPrepServerView*)player)->AlphaDecoder, (void*)FUN_1400341d0, player);
                adecSj = FUN_140043c50((void**)adec);
                if (adecSj == 0)
                    crimvply_occurFatalError(player, "E08082103M : Can't get input SJ of Alpha decoder.", 0);
                criMvPly_SetDemuxOutputSj(player, adecSj, ((CriMvPrepServerView*)player)->AlphaType, ((CriMvPrepServerView*)player)->AlphaFlags);
                FUN_140043d90(adec);
                FUN_1400441b0((CriUint64*)adec, ((CriMvPrepServerView*)player)->AlphaHeaderEnd, ((CriMvPrepServerView*)player)->HeaderEnd - ((CriMvPrepServerView*)player)->AlphaHeaderEnd);
            }
        }
        if (((CriMvPrepServerView*)player)->AudioManager != 0)
            FUN_140042700(((CriMvPrepServerView*)player)->AudioManager, player);
        if (((CriMvPrepServerView*)player)->SubtitleSj != 0)
            criMvPly_SetDemuxOutputSj(player, ((CriMvPrepServerView*)player)->SubtitleSj, 0x40534254, 0);
        criUsfDmx_SetThrououtSwitch(demux, 1);
        criUsfDmx_Start(demux);
        if (((CriMvPrepServerView*)player)->TerminateRequested == 1)
            criUsfDmx_TerminateSupply(demux);
    }
    if (videoDecoder != 0)
    {
        vdecStatus = criVdec_GetStatus(videoDecoder);
        if (vdecStatus == 1 || vdecStatus == 0)
            return;
        if (((CriMvPrepServerView*)player)->RequiredPictures != 0xffffffff)
            required = ((CriMvPrepServerView*)player)->RequiredPictures;
        else
            required = ((CriMvPrepServerView*)player)->MinDecodedPictures;
        if (criVdec_GetNumDecPool(videoDecoder) < required && criVdec_GetNumPictureData(videoDecoder) > 0)
            return;
        if (((CriMvPrepServerView*)player)->HeaderEnd > 0 && ((CriMvPrepServerView*)player)->HeaderDone != 1)
            return;
        if (((CriMvPrepServerView*)player)->AlphaDecoder != 0)
        {
            adecStatus = criAlphaDec_GetStatus(((CriMvPrepServerView*)player)->AlphaDecoder);
            if (adecStatus == 1 || adecStatus == 0)
                return;
            if (criAlphaDec_GetNumDecPool(((CriMvPrepServerView*)player)->AlphaDecoder) < required && criAlphaDec_GetNumPictureData(((CriMvPrepServerView*)player)->AlphaDecoder) > 0)
                return;
        }
    }
    if (criMvPlyAmng_IsReadyAudioPlayback(((CriMvPrepServerView*)player)->AudioManager, player) != 1)
        return;
    ((CriMvPrepServerView*)player)->Status = 4;
}

// Drain the two CRI input streams into the decoder read queue.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): dst, written, chunk.
// @0x140034330
CRI_C_LINKAGE void FUN_140034330(void* player, void* source, void* readBuffer, void* dataQueue)
{
    CriMovieChunkQueueRecord chunk;
    CriSint32 written;
    CriMvWriteBufferView dst;
    written = 0;
    if (((CriMvReadModeView*)player)->Mode != 0)
        return;
    while ((CriUint32)FUN_1400467b8(readBuffer, 2) > 0)
        criSj_GetChunk(readBuffer, 2, -1, &chunk);
    while ((CriUint32)FUN_1400467b8(readBuffer, 1) > 0)
    {
        criSj_GetInputChunk(dataQueue, &dst);
        criSj_GetChunk(readBuffer, 1, -1, &chunk);
        if (chunk.Type > dst.Capacity)
            crimvply_occurFatalError(player, "E08120301M : Illigal data size of analize header against demux data line.", dst.Capacity);
        memcpy(dst.Data, chunk.Chunk, chunk.Type);
        written += chunk.Type;
        criSj_PutInputChunk(dataQueue, &dst, chunk.Type);
    }
    while ((CriUint32)FUN_1400467b8(source, 1) > 0)
    {
        criSj_GetInputChunk(dataQueue, &dst);
        criSj_GetChunk(source, 1, -1, &chunk);
        if (chunk.Type > dst.Capacity)
            crimvply_occurFatalError(player, "E08120302M : Illigal data size in read buffer data line of analize header.", dst.Capacity);
        memcpy(dst.Data, chunk.Chunk, chunk.Type);
        written += chunk.Type;
        criSj_PutInputChunk(dataQueue, &dst, chunk.Type);
        criSj_PutChunk(source, 0, &chunk);
    }
}

// validate the CRI Movie signature, reset the demux, and start ready decoders
// Local names pick the exe's VC9 /Od stack slots: dmx, record.
// @0x140034730
CRI_C_LINKAGE void executeUsfServer(void* player)
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
        criSj_GetChunk(((CriMvPlyDemuxFields*)player)->InputBuffer, 1, -1, &record);
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
CRI_C_LINKAGE void FUN_140034d40(void* player, CriMovieInputChunk* output)
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
    criSj_GetChunk(source, 0, -1, record);
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
CRI_C_LINKAGE void FUN_1400356a0(void* player, void* output, void* alphaOutput,
                   const struct CriMvFrameInfo* frameInfo, const void* alphaInfo)
{
    crimvply_makeFrameInfoMembers(player, output, frameInfo, *(const CriUint64*)frameInfo,
                  *(const CriUint32*)((const CriUint8*)frameInfo + 0x0c));
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        crimvply_makeAlphaFrameInfoMembers(player, alphaOutput, alphaInfo);
}

// get the current alpha frame only while the movie is in a frame-producing state
// @0x140035800
CRI_C_LINKAGE CriBool FUN_140035800(void* player, void* movieYuvState, void* outputInfo)
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
CRI_C_LINKAGE CriUint32 FUN_1400358d0(void* output, const void* info)
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
CRI_C_LINKAGE void criMvPly_StartMemory(void* player, const void* inputData, CriUint32 inputSize)
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
    criUsfDmx_SetOutputSj(demux, 0, ((CriMvPlyDemuxFields*)player)->ReadBuffer, 0, (CriUint32)-1);
    criUsfDmx_SetThrououtSwitch(demux, 0);
    criUsfDmx_Start(demux);
    criSj_GetInputChunk(((CriMvPlyDemuxFields*)player)->InputBuffer, &buf);
    if (buf.Capacity > inputSize)
        len = inputSize;
    else
        len = buf.Capacity;
    memcpy(buf.Data, inputData, len);
    criSj_PutInputChunk(((CriMvPlyDemuxFields*)player)->InputBuffer, &buf, len);
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
CRI_C_LINKAGE void criMvPly_GetSubtitle(void* player, void* destination, CriUint32 capacity, void* outputInfo)
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
CRI_C_LINKAGE void executeHeaderServer(void* player)
{
    CriSint32 res;
    void* stream;
    CriMovieInputChunk chunk;
    CriMvHeaderStreamEntry* target;
    CriUint32 info[12];                     // criUsfCmn_ParseUsfHeaderStd fills 0x24 bytes; 12 dwords give the exe 0x98 frame
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
        criSj_GetChunk(stream, 1, -1, &chunk);
        if (chunk.Size >= 0x20)
        {
            criUsfCmn_ParseUsfHeaderStd(chunk.Data, chunk.Size, (CriUsfStandardHeader*)info);
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
CRI_C_LINKAGE CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* output, CriSint32 channel)
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
        criSj_GetChunk(sj, 1, -1, &record);
        if (record.Chunk == NULL || record.Type < 0x20)
            break;
        criUsfCmn_ParseUsfHeaderStd((const CriUint8*)record.Chunk, record.Type, (CriUsfStandardHeader*)&headerInfo);
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

// Work memory for one playback: stream-joint ring buffers sized from the bitrate, the video and alpha decoders, audio and subtitles.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe).
// @0x140037400
CRI_C_LINKAGE CriSint32 criMvPly_CalcPlaybackWorkSize(void* player, const CriMvStreamParamsView* params)
{
    CriSint32 sizes;
    CriSint32 dec;
    CriSint32 chk;
    CriUint32 count2[2];
    CriSint32 cur;
    CriSint32 cnt;
    CriSint32 idx;
    CriUint32 tail;
    CriUint32 size;
    CriSint32 blocks;
    CriSint32 bytes;
    CriSint32 num1;
    void* head;
    const CriUint32* info;
    const CriUint32* adx;
    void* hinfo;

    bytes = 0;
    if (player == player) {}                 // VC9 folds the test but keeps the exe's dead load of player
    num1 = params->Video[4] + (params->TrackPlayAudio >= 0 ? 0xd : 0) + 8;
    sizes = 0x24;
    sizes += num1 * (CriUint64)0x22;
    bytes += sizes;
    if (params->Head[3] == 0xffffffff)
    {
        size = (CriUint32)((float)(params->Head[0] / 8) * params->BufferingTime);
        if (size < params->Head[2])
            size = params->Head[2];
    }
    else
        size = params->Head[3];
    size = (size + 0x800) / 0x800 * 0x800;
    tail = decideReadBufferExtSize((void*)params);
    count2[0] = 1;
    count2[1] = 1;
    blocks = criSjRbf_GetRequiredMemorySizeWithConfig(size, tail, 0x40, count2);
    bytes += blocks;
    if (params->Head[4] > 0)
    {
        info = params->Video;
        head = 0;
        head = crimvply_findVdecIF((CriSint32)info[10]);
        if (head == 0)
        {
            crimvply_occurUserError(player, "E11030202M : No available decoder is attached for the video stream. Attach a decoder module before the Initialize function.", 0);
            return -1;
        }
        chk = FUN_140044400(head, info[0], info[1], info[4]);
        bytes += chk;
        if (params->NumAlpha > 0)
        {
            adx = params->Alpha;
            hinfo = crimvply_findAlphadecIfIF((CriSint32)adx[7]);
            if (hinfo == 0)
            {
                crimvply_occurUserError(player, "E11030702M : Not found any avilable codec for the alpha stream. Attach a codec module before the Initialize function", 0);
                return -1;
            }
            cur = FUN_140043a80(hinfo, adx[0], adx[1], info[4]);
            bytes += cur;
        }
    }
    dec = criMvPlyAmng_CalcAmngWorkSize(params);
    bytes += dec;
    if (params->TrackPlayAudio >= 0)
    {
        idx = criMvPlyAmng_CalcAudioDecoderWorkSize(player, params->Audio[params->TrackPlayAudio].Words);
        bytes += idx;
    }
    count2[0] = 1;
    count2[1] = 1;
    cnt = criSjUni_GetRequiredMemorySizeWithConfig(0, 0x40, count2);
    bytes += cnt;
    return bytes;
}

// apply the rolling CRI USM mask and its eight-block prefix transform to a chunk.
// As C (VC9 /TC) the inner goto is one jmp, as in the exe; C++ adds a second. The local names pick the exe's VC9 /Od stack slots,
// and the locals from 0x68 up sit in one nested block as in the exe. The mask local is named xor for its slot; the clang DLL build
// compiles as C++, where xor is an operator keyword.
#ifdef __cplusplus
#define CRI02D_XOR xormask
#else
#define CRI02D_XOR xor
#endif
typedef struct Cri02dUsfChunkHeader
{
    CriUint32 Signature;
    CriUint32 ChunkSize;
    CriUint8 Reserved8;
    CriUint8 DataOffset;
    CriUint16 PaddingSize;
    CriUint32 Reserved[6];
} Cri02dUsfChunkHeader;
// 0x20 mask bytes with no byte array, so /GS adds no cookie, as in the exe
typedef struct Cri02dMaskBlock
{
    CriUint8 First;
    CriUint8 Second;
    CriUint16 Third;
    CriUint32 Rest[7];
} Cri02dMaskBlock;
typedef struct Cri02dMaskPlayerView
{
    CriUint8 Reserved0[0xe48];
    CriUint32 CarryOffset;
    CriUint32 CarryLength;
    CriUint8* CarryBuffer;
} Cri02dMaskPlayerView;
// @0x140037a40
CRI_C_LINKAGE void FUN_140037a40(const CriMovieInputChunk* current, const CriMovieInputChunk* previous, void* player)
{
    CriMovieInputChunk payload;
    Cri02dUsfChunkHeader usfhdr;
    Cri02dMaskPlayerView* mv = (Cri02dMaskPlayerView*)player;
    CriUint32 begin = 0x40;
    if (mv == mv) {}
    if (!criMvPly_IsSetDefaultDecryptionKey)        // the exe tests the function's address, which is never null
        return;
    payload.Data = criUsfCmn_GetContents(current->Data, current->Size, (CriSint32*)&payload.Size);
    criUsfCmn_ParseUsfHeaderStd(current->Data, current->Size, (CriUsfStandardHeader*)&usfhdr);
    payload.Size = usfhdr.ChunkSize - begin - usfhdr.DataOffset;
    if (previous != NULL)
        payload.Size -= previous->Size;
    else
        payload.Size -= usfhdr.PaddingSize;
    {
    CriUint32 blkcnt;
    CriMovieInputChunk pc;
    CriUint32 unit;
    CriMovieInputChunk body;
    CriUint32 bsz = 0x20;
    CriUint32 hsize = 0x100;
    Cri02dMaskBlock CRI02D_XOR = {0};
    Cri02dMaskBlock key = {0};
    Cri02dMaskBlock xor2 = {0};
    CriUint32 bidx = 0;
    CriUint8* dptr = NULL;
    CriUint8* data = NULL;
    CriUint32 elen = usfhdr.ChunkSize - usfhdr.DataOffset - begin - usfhdr.PaddingSize;
    CriUint32 ri;
    CriUint32 boff;
    CriUint32 ofs;
    if (elen < 0x200)
        return;
    memcpy(&CRI02D_XOR, DAT_143b27a48, 0x20);
    memcpy(&key, DAT_143b27a68, 0x20);
    memcpy(&xor2, DAT_143b27a68, 0x20);
    body = payload;
    body.Data += begin;
    if (previous != NULL)
    {
        pc.Data = previous->Data;
        pc.Size = previous->Size - usfhdr.PaddingSize;
    }
    else
    {
        pc.Data = NULL;
        pc.Size = 0;
    }
    dptr = (CriUint8*)body.Data;
    data = dptr;
    ofs = 0;
    boff = ofs;
    bidx = hsize;
    blkcnt = (elen - hsize) / bsz + 1;
    for (unit = 0; unit < blkcnt; unit++)
    {
        for (ri = 0; ri < bsz; ri++)
        {
            if (bidx >= elen)
                goto done;
            if (bidx >= body.Size)
            {
                data = (CriUint8*)pc.Data;
                boff = bidx - body.Size;
            }
            else
                boff = bidx;
            data[boff] ^= ((CriUint8*)&key)[ri];
            ((CriUint8*)&key)[ri] = data[boff] ^ ((CriUint8*)&xor2)[ri];
            bidx++;
        }
    }
done:
    bidx = 0;
    dptr = (CriUint8*)body.Data;
    data = dptr;
    ofs = 0;
    boff = ofs;
    for (unit = 0; unit < 8; unit++)
    {
        for (ri = 0; ri < bsz; ri++)
        {
            ofs = bidx + hsize + ri;
            ((CriUint8*)&CRI02D_XOR)[ri] ^= dptr[ofs];
        }
        for (ri = 0; ri < bsz; ri++)
        {
            boff = bidx;
            data[boff] ^= ((CriUint8*)&CRI02D_XOR)[ri];
            bidx++;
        }
    }
    if (previous != NULL)
        memcpy(mv->CarryBuffer, mv->CarryBuffer + mv->CarryOffset, mv->CarryLength);
    }
}
#pragma optimize("", on)
