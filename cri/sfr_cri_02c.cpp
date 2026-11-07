// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the CRI Movie 3.07.01 internals (criMvPly, the decoder
// and reader glue, 0x14002e548-0x140039ea8). Our own source, written from the exe; the leaked SDK copies were only used
// to name things. The Scaleform GFx Video code before it stays in sfr_cri_02 (VS2012). The CRI library was built with
// VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto,
// decltype, variadic templates, brace-init or nullptr). 0x1400356a0 and 0x140035800 are in sfr_cri_02d: they only
// byte-match compiled as C (/TC), as the exe's criMvPly objs were.
// MS2-UNIT: sfr_cri_02c
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14002e548-0x14002eb20 .text$mn
// MS2-RANGE: 0x14002f850-0x14002fbe0 .text$mn
// MS2-RANGE: 0x1400301d0-0x140030280 .text$mn
// MS2-RANGE: 0x140030b50-0x140030cb0 .text$mn
// MS2-RANGE: 0x140030e50-0x140031290 .text$mn
// MS2-RANGE: 0x1400313d0-0x140031990 .text$mn
// MS2-RANGE: 0x140031aa0-0x140032090 .text$mn
// MS2-RANGE: 0x140032650-0x140033030 .text$mn
// MS2-RANGE: 0x140033610-0x140033810 .text$mn
// MS2-RANGE: 0x140033d70-0x140034330 .text$mn
// MS2-RANGE: 0x1400344f0-0x140034730 .text$mn
// MS2-RANGE: 0x140034920-0x140034d40 .text$mn
// MS2-RANGE: 0x140034e70-0x1400356a0 .text$mn
// MS2-RANGE: 0x140035710-0x140035800 .text$mn
// MS2-RANGE: 0x1400359e0-0x1400361a0 .text$mn
// MS2-RANGE: 0x1400363b0-0x140036470 .text$mn
// MS2-RANGE: 0x140036590-0x140036710 .text$mn
// MS2-RANGE: 0x1400369e0-0x140036b80 .text$mn
// MS2-RANGE: 0x140036d50-0x140037400 .text$mn
// MS2-RANGE: 0x140037740-0x140037a40 .text$mn
// MS2-RANGE: 0x140038000-0x140039ea8 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// VS2008's <new> (use_ansi.h) adds /DEFAULTLIB:libcpmt under /MT. That static C++ library then wins over the hook DLL's
// msvcprt whenever this obj links first, and the link fails with a RuntimeLibrary mismatch. We only need placement new.
#define _USE_ANSI_CPP
#include "../include/cri/cri_movie.h"
#include <windows.h>
#include <new>
#include <string.h>
#include <stdlib.h>
#pragma function(memset)                        // the exe CRI objs call memset; they never inline it

extern "C" {
extern void* DAT_143b15f60;
extern CriUint8 DAT_143b27a48[0x20];
extern CriUint8 DAT_143b27a68[0x20];
extern CriUint8 DAT_143b27a88[];
extern void* DAT_143ffd550;
extern CriSint32 DAT_143ffd500;
extern CriUint8 DAT_143ffd504[0x48];
extern const char* DAT_143b27940;
extern const char* DAT_143b27aa8;
extern char DAT_143b27ab0[0x100];
extern const char* DAT_143b27bb0;
extern void* DAT_143b27bb8;
extern void* DAT_143b27bc0;
extern CriSint32 DAT_143b27bc8;
extern CriUint32 DAT_143b27bcc;
extern CriUint32 DAT_143b27bd0;
struct CriErrorText { CriSint32 code; const char* text; };
extern CriErrorText DAT_1431b97a0[];   // {code, text} pairs ending with {0, NULL}
extern const char DAT_1431b9820[];     // ":"
extern const void* DAT_143b27a40;
extern CriUint16 DAT_143b2794c;
extern CriSint32 DAT_143b27948;
extern CriUint8 DAT_143b27950[];
extern const void* DAT_1431b91b0[];
extern const void* DAT_1431b91d8[];
extern const void* DAT_1431b9170[];
extern const void* DAT_143149940[];
extern const void* DAT_1431b93b0[];
extern const void* DAT_1431b9360[];
extern const void* DAT_1431b9410[];
extern const void* DAT_1431b93c0[];
extern const void* DAT_143183b28[];
extern const void* DAT_1431b9080[];
extern const void* DAT_1431b9028[];
extern const void* DAT_1431b8fd0[];
extern const void* DAT_1431b8f18[];
extern const void* DAT_1431b8db0[];
extern const void* DAT_1431b9430[];
}

extern "C" const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);
struct CriMovieParsedChunk;

// ---- exe helpers this part calls (bound by address until their units are recovered)

void     FUN_14258b240(unsigned ms);                                    // Thread::MSleep
unsigned __int64 FUN_1425e3590(void);                                   // Timer::GetTicks
void     FUN_14257dc30(void* p);                                        // RefCountImpl::AddRef
void     FUN_14257dcb0(void* p);                                        // RefCountImpl::Release
void     FUN_14257dcd0(void* p);
void     FUN_14258a350(void* lock, CriSint32 spinCount, CriSint32 flags);
void     FUN_142582300(void* queue, CriSint32 count, CriSint32 flags);
void     FUN_14258a620(void* sync);
void     FUN_14258a810(void* sync);
void     FUN_142582530(void* queue);
void     FUN_14258a720(void* lock);
void     FUN_14257db50(void* p);
CriUint32 FUN_14257bdc0(void);
void*    FUN_14258a490(void* mem, void* createParams);                  // Thread::Thread(const CreateParams&)
void     FUN_14001d650(void* config, void* reader);                     // VideoReaderConfig::AttachReader
void*    FUN_140041d40(void* pheap);                                    // CriHeap over a MemoryHeap: create
void     FUN_140041dd0(void* criheap);                                  //   and destroy
void*    FUN_140041c00(void* mem);                                      // SystemTimerSyncObject::SystemTimerSyncObject
void*    FUN_14002a010(void* mem, void* pheap, void* psound);           // CriMvSound::CriMvSound(MemoryHeap*, VideoSound*)
void*    FUN_140029e40(void* mem, void* psync);                     // CriMvSystemTimer::CriMvSystemTimer(SyncObject*)
void*    FUN_14002abd0(void* mem, CriUint32 format, const CriUint32* psize, const void* ptexman, void* pplayer); // VideoImage ctor
extern "C" void     crimvply_occurUserError(void* player, const char* message, CriSint32 severity);
void     criUsfDmx_TerminateSupply(void* inputBuffer);
CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config);
void*    criSjRbf_Create(const void* config, void* work, CriSint32 workSize);
void*    criSj_CreateNamedRingBuffer(void* heap, CriUint32 size, CriUint32 flags, CriUint32 align, CriUint64 name);
CriSint32 criUsfDmx_CalculateWorkSizeWithWork(CriSint32 workCount);
CriSint32 criSjRbf_GetRequiredMemorySizeWithConfig(CriUint32 first, CriUint32 second, CriUint32 alignment, const CriUint32* flags);
CriSint32 FUN_140044400(void* decoder, CriUint32 first, CriUint32 second, CriUint32 third);
CriSint32 criMvPlyAmng_CalcAmngWorkSize(const void* params);
CriSint32 criSjUni_GetRequiredMemorySizeWithConfig(CriUint32 first, CriUint32 second, const CriUint32* flags);
void* crimvply_findAlphadecIfIF(CriSint32 codecId);
CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config);
void*    criUsfDmx_CreateWithWork(CriSint32 count, void* work, CriSint32 workSize);
void*    criSjUni_Create(const void* config, void* work, CriSint32 workSize);
CriSint32 criMvPlyAmng_CalcAudioDecoderWorkSize(const void* decoder, const CriUint32* config);
void     enterHandleCs(void* player);
void     leaveHandleCs(void* player);
struct CriMovieInputChunk;
CriUint32 crimvply_AllocateWorkBufferInCs(void* player, void* heap, void* work);
CriUint32 decideReadBufferExtSize(void* player);
void FUN_140037a40(const CriMovieInputChunk* current, const CriMovieInputChunk* previous, void* player);
void*    criMvPlyAmng_Create(void* player, void* heap, const void* params);
void*    criAlphaDec_Create(void* decoderInterface, void* heap, void* config);
void*    criVdec_Create(void* decoderInterface, void* heap, void* config);
void     FUN_140044de0(void* decoder, void* callback, void* context);
void     FUN_140044c10(void* decoder, CriUint32 mask);
void*    FUN_140039ea8(void* work, CriSint32 workSize);
void*    FUN_1400385c8(void* work, CriSint32 workSize);
void*    criUsfDmx_Create(void* heap, CriSint32 count);
void*    criSj_CreateUniversal(void* heap, CriUint32 kind, CriUint32 alignment);
void     criMvPly_Destroy(CriUint32* player);
void     initializeHandleParameters(void* player);
void*    crimvply_findVdecIF(CriSint32 codecId);
void*    criVdec_GetVdecCoreIf(void* decoderInterface);
extern "C" CriSint32 FUN_1400467b8(void* ringBuffer, CriSint32 query);
extern "C" void criSj_GetInputChunk(void* object, void* value);
extern "C" void criSj_PutInputChunk(void* streamJoint, const void* chunk, CriUint32 size);
void criSj_SplitChunk(const void* source, CriUint32 maximum, void* prefix, void* suffix);
void     criCs_Enter(_RTL_CRITICAL_SECTION* section);
void     criCs_Leave(_RTL_CRITICAL_SECTION* section);
void     criBaseVersion_ImplantVersionInformation(void);
char*    FUN_140046944(char* dst, size_t size, const char* src);
char*    FUN_14004698c(char* dst, size_t size, const char* src);
void     generateDecryptMask(const void* key);
CriBool  FUN_1400389f0(void* reader, const char* path, CriUint64* size, CriUint64* offset);
void     criErr_NotifyPrmArray(CriSint32 category, const char* message, CriSint32 value, CriSint32 flags, void* owner);
void     criErr_NotifyGeneric(CriSint32 category, const char* message, CriSint32 value);
void     crimvply_IncrementStateInCs(void* player);
void     FUN_140031290(void* player);
CriBool  freeMetaWorkInCs(void* player);
CriBool  executeDecHdrStageAnalizeHeader(void* player);
CriBool  executeDecHdrStageMetaGet(void* player);
CriBool  FUN_140031990(void* player);
CriUint32 FUN_1400358d0(void* output, const void* info);
void     FUN_140034d40(void* player, CriMovieInputChunk* output);
extern "C" CriBool  allocateMetaWork(void* player);
extern "C" CriBool  isEndStopProcessingProc(void* player);
CriSint32 criMvPlyAmng_IsEndAudioPlayback(void* decoder, void* player);
extern "C" void     criMvPlyAmng_ExecuteAudioServer(void* audioManager, void* player);
extern "C" void     resetHandle(void* player);
void     executeUsfServer(void* player);
void     executeMvPlyPrepServer(void* player);
CriBool  FUN_140033d70(void* player, const CriMovieInputChunk* input, CriUint8 outputIndex);
void     FUN_140041df0(void* manager, void* callback, void* userData);
extern "C" void FUN_140042700(void* trackSet, void* player);
void     FUN_140044330(CriUint64* decoder, void* callback, void* context);
CriSint32 FUN_140043a80(void* decoder, CriSint32 first, CriSint32 second, CriSint32 third);
CriBool  criMvPlyAmng_IsReadyAudioPlayback(void* trackSet, void* operation);
void     FUN_140044cc0(void* decoder, void* callback, void* userData);
void     FUN_140044c60(void* decoder, CriUint32 position, CriUint32 mode);
CriUint64 FUN_1400445d0(CriUint64* pair);
void*    FUN_140043c50(void** decoder);
void     FUN_140044210(CriUint64* pair, void* first, void* second);
void     FUN_1400441b0(CriUint64* pair, CriUint32 first, CriUint32 second);
extern "C" void     executeMvPlyPlayingServer(void* player);
CriBool  criMvPly_DecodeVideoInCs(void* player);
void     executeMvPlyDechdrServer(void* player);
void     executeUsfServer(void* player);
void     FUN_140034330(void* player, void* source, void* readBuffer, void* dataQueue);
extern "C" void     criUsfDmx_Stop(void* demux);
extern "C" void     criUsfDmx_Execute(void* demux);
extern "C" void*    criUtfRtv_Create(void* heap, void* data, CriUint32 size);
extern "C" CriUint32 FID_conflict_criUtfRtv_GetDataSint32Fn(const CriUtfRtvView* object, CriUint32 index, const char* key);
CriUint32 criUtfRtv_ConvFieldNameToNo(const CriUtfRtvView* object, const char* key);
extern "C" CriUint32 criUtfRtv_GetNumRecord(const CriUtfRtvView* object);
CriUint32 criUtfRtv_GetDataSint32Fn(const CriUtfRtvView* object, CriUint32 index, const char* key);
CriUint64 criUtfRtv_GetDataUint64(const CriUtfRtvView* object, CriUint32 index, CriUint32 value);
CriSint32 criUtfRtv_GetCellVal(const CriUtfRtvView* object, CriUint32 row, CriUint32 field, CriUtfRtvCell* cell);
extern "C" void     criUtfRtv_Destroy(CriUint64* table);
CriUint32 criUsfCmn_ParseUsfHeaderStd(const CriUint8* data, CriUint32 size, CriUsfStandardHeader* output);
CriBool  criAlphaDec_DecodeFrame(void* decoder);
CriBool  criVdec_DecodeFrame(void* decoder);
void     FUN_140044ae0(void* decoder);
CriBool  FUN_140032090(void* player);
CriBool  decodeMetaData(void* player);
CriBool  freeMetaWorkInCs(void* player);
CriBool  crimvply_StartInCs(void* player);
CriBool  allocateMetaWorkInCs(void* player);
void     FUN_140030cb0(void* player);
void     crimvply_StopInCs(void* player);
extern "C" void     crimvply_makeFrameInfoMembers(void* player, void* output, const void* frameInfo, CriUint64 firstWord, CriUint32 flags);
CriBool  criMvPly_DiscardNextFrame(void* player, void* output);
CriBool  criMvPly_LockFrameBuffer(void* player, void* yuvBuffers, void* output);
CriSint32 criVdec_GetStatus(void* decoder);
extern "C" CriSint32 criUsfDmx_GetStatus(void* demux);
CriSint32 criVdec_GetNumPictureData(void* decoder);
CriSint32 criAlphaDec_GetNumPictureData(void* decoder);
CriUint32 criVdec_GetNumDecPool(void* decoder);
CriUint32 criAlphaDec_GetNumDecPool(void* decoder);
void FUN_140044710(void* decoder);
void FUN_140043d90(void* decoder);
extern "C" void     criMvPlyAmng_TerminateSupply(void* audioManager);
void     criMvPlyAmng_Stop(void* audioManager);
void     criMvPlyAmng_ResetAudioSj(void* audioManager);
extern "C" void     criVdec_TerminateSupply(void* videoDecoder);
extern "C" void     criAlphaDec_TerminateSupply(void* alphaDecoder);
CriSint32 criAlphaDec_GetStatus(void* decoder);
void     criVdec_RequestStop(void* decoder);
void     criAlphaDec_RequestStop(void* decoder);
void     FUN_1400393f0(CriMvEasyPlayer* easyPlayer, CriSint32 a, CriSint32 b, CriSint32 c,
                       CriUint64 d, CriUint64 e);
CriSint32 FUN_140039330(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo);
CriBool  FUN_140039180(CriMvEasyPlayer* easyPlayer, CriSint32 updateTime, CriUint32* output);
void*    criMvPly_GetNextFrameInfo(void* player, void* output);
CriBool  criMvPly_LockFrameBuffer(void* player, void* movieYuvState, void* outputInfo);
CriBool  FUN_140035800(void* player, void* movieYuvState, void* outputInfo);
CriSint32 FUN_1400397a0(CriMvEasyPlayer* self, CriMvEasyPlayer* player, const CriMvFrameInfo* frameInfo,
                        CriUint64 count, CriUint64 unit, void* userData);
extern "C" void     criSj_PutChunk(void* queue, CriSint32 operation, void* chunk);
extern "C" void     criSj_UngetChunk(void* queue, CriSint32 operation, void* chunk);
CriUint32 executeSubtitleServer(void* player);
void     executeHeaderServer(void* player);
void     executeDiscardFrameServer(void* player);
void     updateInputBufferInfo(void* player);
CriUint32 criMvPlyAmng_GetWave16(void* manager, CriSint32 stream, void* player, CriUint32 format,
                          void* output, CriUint32 sampleCount, CriUint32* result);
CriUint32 criMvPlyAmng_GetWave32(void* manager, CriSint32 stream, void* player, CriUint32 format,
                          void* output, CriUint32 sampleCount, CriUint32* result);
void*    criAlphaDec_GetNextAlphaFrameInfo(void* decoder, void* frameInfo);
extern "C" void*    criAlphaDec_GetAlphaFramePointer(void* decoder, void* frameInfo);
void*    criVdec_GetNextFrameInfo(void* decoder, void* frameInfo);
void     criUsfDmx_Initialize(void);
void     criAtomic_Initialize(void);
void     criAtomic_Finalize(void);
void     criMvPlyAmng_Initialize(void);
void     criMvPlyAmng_Finalize(void);
void     criAlphaDec_Initialize(const void* decoderInterface);
void     criAlphaDec_Finalize(void* decoderInterface);
void     criVdec_Initialize(const void* decoderInterface);
void     criVdec_Finalize(void* decoderInterface);
void     criUsfDmx_Finalize(void);
void     criCs_Destroy(_RTL_CRITICAL_SECTION* section);
void*    criVdec_GetFramePointer(void* decoder, void* frameInfo);
void     criAlphaDec_ReleaseAlphaFramePointer(CriUint64* decoder, void* frameInfo);
void     criVdec_ReleaseFramePointer(void* decoder, void* frameInfo);
void     criVdec_GetOffsetConcatenated(void* decoder, CriUint32 frameId, void* count, void* unit);
CriSint32 criAlphaDec_CopyAlphaFrameBuffer(void* decoder, void* buffers, void* frameInfo);
void     criVdec_GetFramePoolInfo(void* decoder, void* a, void* b, void* c, void* d, void* e);
extern "C" void criUsfDmx_SetOutputSj(void* output, CriUint32 index, void* value, CriUint32 type, CriSint32 flags);
void     criVdec_Execute(CriUint64* decoder);
void     criAlphaDec_Execute(void* decoder);
extern "C" CriBool  FUN_1400467b8(void* queue, CriSint32 operation);
void     criSj_GetChunk(void* queue, CriSint32 operation, CriUint32 timeout, void* item);
void     criVdec_SetProcessorMask(void* decoder, CriUint32 count);
void     criAlphaDec_SetProcessorMask(CriUint64* decoder, CriUint32 count);
void     criVdec_SetDlgPara(void* decoder, CriUint32 count, void* streamInfo, void* outputInfo);
void     criAlphaDec_SetDlgPara(CriUint64* decoder, CriUint32 count, void* streamInfo, void* outputInfo);
extern "C" void     FUN_140032650(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed);
extern "C" void     retrieveAudioHeader(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed);
extern "C" void     FUN_140032db0(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed);
extern "C" void     retrieveSubtitleHeader(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed);
struct CriMovieStreamSlotView;
void     prepareNextHeaderIfCompleted(void* player, CriMovieStreamSlotView* slot);
void*    FUN_14002db40(void* thread, void* config);
CriSint32 criMvPlyAmng_CreateAudioDecoder(void* manager, void* player, void* source, const CriUint32* streamInfo,
                       CriUint32 stream, CriSint32 enable);
void     criMvPlyAmng_SetDecryptCallback(void* manager, void* callback, void* player, CriSint32 enable);
CriBool  criMvPly_IsSetDefaultDecryptionKey(void);
extern "C" void     crimvply_occurFatalError(void* owner, const char* message, CriSint32 value);
CriUint32 criMvPlyAmng_GetDataSizeWave(void* manager, CriSint32 stream, void* player, CriUint32 channels);
CriSint32 criMvPlyAmng_IsEndAudioPlaybackById(void* manager, void* player, CriSint32 stream);
void     criMvPlyAmng_DestroyAudioDecoder(void* manager, void* decoder, CriSint32 stream);
CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* chunk, CriSint32 channel);
extern "C" void     releaseSubtitleChunk(void* player, CriMvSubtitleChunk* chunk);
extern "C" void     criMvPly_AddInputMemory(void* player, void* chunk, CriUint32 type);
extern "C" void     ungetSubtitleChunk(void* player, CriMvSubtitleChunk* chunk);
extern "C" void     analyzeSubtitleInfo(void* player, CriMvSubtitleChunk* chunk, void* outputInfo);
extern "C" void     criSj_Destroy(void* streamJoint);
extern "C" void     criUsfDmx_SetInputSj(void* demux, void* value);
extern "C" void     criUsfDmx_SetThrououtSwitch(void* demux, CriUint8 value);
void     criUsfDmx_Destroy(void* demux);
void     FUN_140030c70(void* player);
CriBool  freeMetaWork(void* player);
extern "C" void     criUsfDmx_Start(void* demux);
extern "C" void     criSj_Reset(void* streamJoint);
extern "C" void     criMvPlyAmng_Destroy(void* manager, void* heap);
extern "C" void     criAlphaDec_Destroy(void* decoder);
extern "C" void     criVdec_Destroy(CriUint64* adapter);
void     FUN_142584540(void* event, CriSint32 timeout);
void     FUN_14258b260(void* event);
void     FUN_14258aca0(void* lock);
void     FUN_14258bb70(void* lock);
void     FUN_142583d50(void* event);
CriSint32 FUN_14258bc20(void* condition, void* lock, CriSint32 timeout);
struct CriMvRequestNode;
struct CriMvRequestPoolView;
CriMvRequestNode* FUN_14002d890(CriMvRequestPoolView* pool);
void     FUN_14002e140(void* queue, CriUint32 operation, void* request, void* a, void* b, void* c);
void     FUN_140029bf0(void* array, void* source, CriUint64 capacity);
void     FUN_140029c90(void* array, void* source, CriUint64 capacity);
void     FUN_140029d30(void* array, void* source, CriUint64 capacity);
void     FUN_14002afe0(CriUint64* array);
void     FUN_14002d3f0(void* allocation);
void     FUN_14002a4a0(CriUint64* array, const CriUint64* source, CriUint64 count);
void     FUN_140006f50(void* array, void* source, CriUint64 capacity);
void     FUN_1400051c0(void* array, void* source, CriUint64 capacity);
void     FUN_142584950(void* destination, const void* source);
CriUint64* FUN_14002ba30(CriUint64* destination, const CriUint64* source);
CriUint64* FUN_14002c550(CriUint64* destination, const CriUint64* source);
void     FUN_14002aa30(CriUint64* array, CriUint64 length);
void     FUN_14000bd60(void* array, CriUint64 length);
void     FUN_14001d720(void* manager, void* reader);
void     FUN_1425845e0(void* event, CriSint32 timeout);
void     FUN_142579470(void* object);
void     FUN_142585580(void* destination, const void* source);
void     FUN_142584ce0(void* string);
void     FUN_14000bc40(void* destination, void* source, CriUint64 capacity);
void     FUN_140007370(void* destination, CriUint64 first, CriUint64 second);

struct CriMvRequestNode
{
    CriMvRequestNode* Next;
    CriMvRequestNode* Previous;
    CriUint32 Operation;
    CriUint32 Reserved;
    void* Request;
    void* ArgumentA;
    void* ArgumentB;
    void* ArgumentC;
};

struct CriMvRequestBlock
{
    CriMvRequestNode Nodes[0x7f];
    CriMvRequestBlock* NextBlock;
};

struct CriMvRequestPoolView
{
    CriMvRequestBlock* FirstBlock;
    CriMvRequestBlock* LastBlock;
    CriUint32 NodesInLastBlock;
    CriUint32 Reserved;
    CriMvRequestNode* FreeList;
};

struct CriMovieAttachStream
{
    CriUint8 Data[0x10];
};

struct CriMovieAttachView
{
    CriUint8 Reserved[0xB2C];
    CriMovieAttachStream Streams[0x2E];
    CriUint8 StreamsTail[4];
    void* Manager;
    CriUint8 ReservedE18[8];
    void* AttachedSource;
};

struct CriMovieOutputLogView
{
    CriUint8 Padding[0xD68];
    void* Output;
    CriUint32 Capacity;
    CriUint32 Count;
};

struct CriMovieQueueView
{
    CriUint8 Padding[0xDA0];
    void* Queue;
    CriUint8 LastChunk[0x10];
};

struct CriMovieChunkQueueRecord
{
    void* Chunk;
    CriUint32 Type;
    CriUint32 Reserved;
};

struct CriMovieStreamSlotView
{
    CriUint8 Prefix[0x14];
    CriUint8 PrimaryOutput[0x258 - 0x14];
    CriUint8 AlphaOutput[0x274 - 0x258];
    CriUint8 SubtitleOutput[0x2C0 - 0x274];
    CriSint32 Active;
    CriSint32 Reserved2C4;
    CriSint32 PendingPrimary;
    CriSint32 PendingSubtitle;
    CriSint32 PendingAlpha;
    CriSint32 PendingAuxiliary;
    CriUint64 NextDataOffset;
};

union CriMovieStreamSlotsView
{
    struct
    {
        CriUint8 Prefix[0x28];
        CriMovieStreamSlotView Slots[4];
    } Ring;
    struct
    {
        CriUint8 IndexPrefix[0x5E8];
        CriUint16 Current;
    } Selector;
};

struct CriMovieInputChunk
{
    const CriUint8* Data;
    CriUint32 Size;
    CriUint32 Reserved;
};

struct CriMovieParsedChunk
{
    const CriUint8* Data;
    CriSint32 Size;
    CriUint32 Reserved;
};

struct CriMvRequestQueueView
{
    CriUint8 Reserved0[0x68];
    CriMvRequestNode* Head;
    CriMvRequestNode* Tail;
    CriUint8 Lock[0x28];
    CriUint8 Event[1];
};

struct CriMvRequestManagerView
{
    CriUint8 Reserved0[0x28];
    void* ActiveReader;
    CriUint8 Reserved1[0x28];
    CriMvRequestNode* FreeList;
    CriUint8 Reserved2[8];
    CriMvRequestNode* Head;
    CriMvRequestNode* Tail;
    CriUint8 Lock[0x28];
    CriUint8 Event[0x58];
    void* StopEvent;
};

struct CriMvReaderRequestView
{
    CriUint8 Reserved0[8];
    void* Queue;
    CriUint8 Reserved1[8];
    CriUint32 OpenPending;
    CriUint32 Reserved2;
    CriUint32 ClosePending;
    CriUint32 ReadPending;
    CriUint64 ReadSize;
    CriUint64 ReadPosition;
    CriUint64 FileSize;
};

struct CriMvReaderThreadConfigView
{
    CriUint8 Reserved0[0x38];
    CriUint8 IOEnabled;
    CriUint8 Reserved1[0x2f];
    CriMvRequestNode* Head;
    CriMvRequestNode* Tail;
    CriUint8 Lock[0x28];
    CriUint8 Event[0x60];
    CriUint8 Condition[8];
    void* Reader;
};

struct CriVideoRecordCopyView
{
    CriUint32 Type;
    CriUint32 Reserved0;
    CriUint64 Name;
    CriUint32 Flags;
    CriUint32 Reserved1;
    CriUint64 NestedStrings[3];
};

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// @0x140038000
void FUN_140038000(void** record, void* userData)
{
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): p, length, scramble, i, ptr, ctx.
    CriUint8* p;
    CriSint32 length;
    CriUint32 i;
    const CriUint8* scramble;
    CriUint8* ptr;
    void* ctx = userData;
    scramble = DAT_143b27a88;
    if (!criMvPly_IsSetDefaultDecryptionKey)                      // the exe tests the function's address, which is never null
        return;
    if (ctx == ctx) {}                       // the CRI unused-argument idiom: /Od loads it (the exe's dead load)
    p = (CriUint8*)criUsfCmn_GetContents((const CriUint8*)record[0], *(CriUint32*)((CriUint8*)record + 8), &length);
    if ((CriUint32)length < 0x140)
        return;
    ptr = p;
    for (i = 0x140; i < (CriUint32)length; i++)
        ptr[i] ^= scramble[i % 0x20];
}

// @0x1400380d0
void FUN_1400380d0(void** record, void* userData)
{
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): p, length, i, ptr, ctx.
    // count2 and state are unused; the exe frame still reserves their slots.
    CriUint8* p;
    CriSint32 length;
    CriUint32 i;
    CriSint32 count2;
    CriUint8* ptr;
    void* state;
    void* ctx = userData;
    if (!criMvPly_IsSetDefaultDecryptionKey)                      // the exe tests the function's address, which is never null
        return;
    if (ctx == ctx) {}                       // the CRI unused-argument idiom: /Od loads it (the exe's dead load)
    p = (CriUint8*)criUsfCmn_GetContents((const CriUint8*)record[0], *(CriUint32*)((CriUint8*)record + 8), &length);
    p += 0x10;
    length -= 0x10;
    ptr = p;
    for (i = 0; i < (CriUint32)length; i++)
        ptr[i] ^= 0xff;
}
#pragma optimize("", on)

// ==== CRI heap backed object allocation ============================================================================
#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os): the r11 prologue
// The CRI allocator keeps its heap pointer in the eight bytes immediately after each object.
// @0x14002e548
void* CriAllocator::operator new(size_t size, CriHeap heap, CriHeapType type, const CriChar8* name, CriUint32 align)
{
    CriUint32 allocationSize = (CriUint32)size + sizeof(CriHeap);
    void* memory = criHeap_Alloc(heap, (CriSint32)allocationSize, name, (CriSint32)align, (CriSint32)type);
    if (memory == NULL)
        return memory;                       // the null result goes straight back in rax (no separate return path)
    memset(memory, 0, allocationSize);
    *(CriHeap*)((CriUint8*)memory + size) = heap;
    return memory;
}
#pragma optimize("", on)
// @0x14002e5b0
void CriAllocator::operator delete(void* memory, size_t size)
{
    criHeap_Free(*(CriHeap*)((CriUint8*)memory + size), memory);
}

// @0x14002e608
void CriAllocator::operator delete(void* memory, CriHeap heap)
{
    criHeap_Free((CriHeap)heap, memory);
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// @0x14002e628
int FUN_14002e628(CriSint32 alignment)
{
    return criHeap_DebugGetWorstExtraSize(alignment) + (int)sizeof(CriHeap);
}
#pragma optimize("", on)

// @0x14002e63c
void* CriAllocator::operator new(size_t size, CriHeap heap)
{
    return CriAllocator::operator new(size, heap, CRIHEAP_TYPE_FIX, "CriAu_new", 0x10);
}

// @0x14002e660
void* CriAllocator::operator new(size_t size, CriHeap heap, CriHeapType type)
{
    return CriAllocator::operator new(size, heap, type, "CriAu_new", 0x10);
}

// @0x14002e680
void* CriAllocator::operator new(size_t size, CriHeap heap, const CriChar8* name, CriUint32 align)
{
    return CriAllocator::operator new(size, heap, CRIHEAP_TYPE_FIX, name, align);
}

// @0x14002e6b0
void CRIAPI criFixedAllocator_Create(void* begin, CriUint32 size, CriFixedAllocator* allocator)
{
    allocator->Begin = (CriUint8*)begin;
    allocator->Current = (CriUint8*)begin;
    allocator->Size = size;
}

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// @0x14002e6bc
void criFixedAllocator_Destroy(CriFixedAllocator*)
{
}
#pragma optimize("", on)

// Bump-allocate size bytes at the next align boundary.
// @0x14002e6c0
void* CRIAPI criFixedAllocator_Allocate(CriFixedAllocator* allocator, CriUint32 size, CriUint32 align)
{
    size_t current = (size_t)allocator->Current;
    // The exe sign-extends size and adds align - 1 as a 32-bit value.
    size_t aligned = (current + (align - 1)) / align * align;
    allocator->Current = (CriUint8*)(aligned + (CriSint32)size);
    return (void*)aligned;
}
// ==== CRI Movie player state and frame-buffer helpers ===============================================================

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// @0x140031020
void FUN_140031020(void* player, CriUint32 value)
{
    *(CriUint32*)((CriUint8*)player + 0x8c4) = value;
}

// @0x140031040
void criMvPly_SetAudioTrack(void* player, CriUint32 track)
{
    *(CriUint32*)((CriUint8*)player + 0x8c8) = track;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Preserves the executable's invalid-value store after its diagnostic call.
// @0x140031060
void criMvPly_SetNumberOfFramesForPrep(void* player, CriSint32 value)
{
    if (value <= 0)
        crimvply_occurUserError(player, "E10120701M : the parameter 'nframes' must be 1 or more.", 0);
    *(CriSint32*)((CriUint8*)player + 0xed8) = value;
}

CriSint32 getInternalStatus(void* player);

// The CRI Movie library was built with VS2008; this accessor reads the status through getInternalStatus.
// @0x1400310b0
CriSint32 criMvPly_GetStatus(void* player)
{
    CriSint32 status = getInternalStatus(player);
    return status;
}

// The CRI Movie library was built with VS2008; this wrapper preserves its status gate and frame-time update.
// @0x140039c10
CriSint32 FUN_140039c10(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo, CriError& error)
{
    error = CRIERR_OK;
    CriSint32 status = criMvPly_GetStatus(easyPlayer->mvply);
    switch (status)                          // VC9 /Od folds the shared case body into a range test
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return 0;
    }
    CriSint32 onTime = FUN_140039330(easyPlayer, frameInfo);
    FUN_1400393f0(easyPlayer, onTime, onTime, 0,
                  *(const CriUint64*)((const CriUint8*)frameInfo + 0x28),
                  *(const CriUint64*)((const CriUint8*)frameInfo + 0x30));
    return onTime;
}

// Forwards both frame queries and copies the returned YUV metadata into the player's saved frame.
// @0x140039cb0
CriBool FUN_140039cb0(CriMvEasyPlayer* easyPlayer, void* yuvBuffers,
                      CriMvFrameInfo* frameInfo, CriMvAlphaFrameInfo* alphaInfo, CriError& error)
{
    error = CRIERR_OK;
    CriBool result = criMvPly_LockFrameBuffer(easyPlayer->mvply, yuvBuffers, frameInfo);
    if (result == 1)
        FUN_140035800(easyPlayer->mvply, yuvBuffers, alphaInfo);
    if (result == 1)
        easyPlayer->frame_info = *frameInfo;
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// @0x1400310e0
CriSint32 getInternalStatus(void* player)
{
    return *(CriSint32*)((CriUint8*)player + 4);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// The built-in frame-time comparison, a CriMvEasyPlayer member in the exe: it ignores this, the player argument and
// the user data (the /Od dead loads), and reports whether the system time has reached the frame's time.
// @0x1400397a0
__declspec(noinline) CriSint32 FUN_1400397a0(CriMvEasyPlayer* self, CriMvEasyPlayer* player,
                                              const CriMvFrameInfo* frameInfo, CriUint64 count, CriUint64 unit,
                                              void* userData)
{
    CriSint32 result = 0;
    if (player == player) {}                 // the CRI unused-argument idiom: /Od loads it (the exe's dead load)
    if (userData == userData) {}
    CriUint64 frameNum = *(const CriUint64*)((const CriUint8*)frameInfo + 0x28);
    CriUint64 fUnit = *(const CriUint64*)((const CriUint8*)frameInfo + 0x30);
    CriFloat32 frameTime = (CriFloat32)frameNum * 1000.0f / (CriFloat32)fUnit;
    CriFloat32 sysTime = (CriFloat32)count * 1000.0f / (CriFloat32)unit;
    if (sysTime >= frameTime)
        result = 1;
    return result;
}

// Selects the player's comparison callback (+0x620, user data +0x628) or the built-in frame-time comparison.
// count and unit start uninitialized, as in the exe: GetTime always sets both.
// @0x140039330
CriSint32 FUN_140039330(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo)
{
    typedef CriSint32(__fastcall* CompareCallback)(CriMvEasyPlayer*, const CriMvFrameInfo*, CriUint64, CriUint64, void*);
    CriUint64 count;
    CriUint64 unit;
    CriSint32 res = 0;
    easyPlayer->GetTime(count, unit, CriMv::ErrorContainer);
    if (*(CompareCallback*)((CriUint8*)easyPlayer + 0x620))
        res = (*(CompareCallback*)((CriUint8*)easyPlayer + 0x620))(easyPlayer, frameInfo, count, unit,
                                                                     *(void**)((CriUint8*)easyPlayer + 0x628));
    else
        res = FUN_1400397a0(easyPlayer, easyPlayer, frameInfo, count, unit, *(void**)((CriUint8*)easyPlayer + 0x628));
    return res;
}

// Fetch a due video frame from CriMvPly and retain its metadata on the easy player.
// @0x140039180
CriBool FUN_140039180(CriMvEasyPlayer* easyPlayer, CriSint32 updateTime, CriUint32* output)
{
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): onTime, videoFrame, hasFrame, result, handle,
    // state.
    CriBool result = 0;
    CriSint32 state;
    void* handle;
    CriMvFrameInfo videoFrame;               // left uninitialised, as in the exe
    CriBool hasFrame;
    CriBool onTime;
    *output = 0;
    if (easyPlayer->pause_flag == 1)
        return result;
    if (easyPlayer->unk724 == 1)
        return result;
    state = criMvPly_GetStatus(easyPlayer->mvply);
    switch (state)
    {
    case 0: case 1: case 2: case 3: case 4:
        return result;
    }
    handle = criMvPly_GetNextFrameInfo(easyPlayer->mvply, &videoFrame);
    hasFrame = handle != NULL;
    onTime = FUN_140039330(easyPlayer, &videoFrame);
    if (hasFrame == 1 && onTime == 1)
        result = 1;
    if (updateTime == 1)
        FUN_1400393f0(easyPlayer, onTime, hasFrame, 0, videoFrame.time, videoFrame.tunit);
    if (result == 1)
        easyPlayer->frame_info = videoFrame;
    return result;
}

// Fetch video and optional alpha frame metadata and retain the alpha snapshot on the easy player.
// @0x140039010
CriBool FUN_140039010(CriMvEasyPlayer* easyPlayer, void* yuvBuffers, void* outputInfo, CriUint32* output)
{
    struct AlphaFrameCopy { CriUint8* imageptr; CriUint64 rest[6]; };   // the 0x38-byte alpha frame info
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): alphaInfo, ready, result.
    AlphaFrameCopy alphaInfo;
    CriBool result = 0;
    CriBool ready = 0;
    *output = 0;
    if (FUN_140039180(easyPlayer, 0, output) != 1)
        return result;
    result = criMvPly_LockFrameBuffer(easyPlayer->mvply, yuvBuffers, outputInfo);
    if (result == 1)
    {
        ready = FUN_140035800(easyPlayer->mvply, yuvBuffers, &alphaInfo);
        if (ready == 1)
            *(AlphaFrameCopy*)easyPlayer->alpha_frame_info = alphaInfo;
    }
    if (ready != 1)                          // no alpha frame: only the image pointer is cleared
        ((AlphaFrameCopy*)easyPlayer->alpha_frame_info)->imageptr = NULL;
    return result;
}

// Restore CRI's alternating timestamp-error correction using the frame-rate and state fields it stores.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): floor = system time / 600 s,
// final = corrected error, coded = frame unit, extra = error, bound = frame time / 600 s,
// dest = system ms, inter = period, left = base threshold, fn = frame count, gap = center,
// leave = result, event = frame ms.
// @0x1400398a0
CriSint32 CriMvEasyPlayer::compareFrameTimeFluctuation(CriMvEasyPlayer* easyPlayer,
    CriMvFrameInfo* frameInfo, CriUint64 count, CriUint64 unit, void* usrobj)
{
    CriUint64 floor;
    CriFloat32 final;
    CriUint64 coded;
    CriFloat32 extra;
    CriUint64 bound;
    CriFloat32 dest;
    CriFloat32 inter;
    CriUint64 cycles;
    CriFloat32 left;
    CriUint64 fn;
    CriFloat32 gap;
    CriSint32 leave;
    CriFloat32 event;
    if (usrobj == usrobj) {}
    leave = 0;
    if (easyPlayer->timer_type == MVEASY_TIMER_NONE)
        return 1;
    if (easyPlayer->timer_type == MVEASY_TIMER_SYSTEM)
        left = easyPlayer->compare_frame_prm0;
    else
        left = easyPlayer->compare_frame_prm1;
    gap = left + easyPlayer->compare_frame_prm2 * easyPlayer->compare_frame_prm3;
    inter = easyPlayer->compare_frame_prm2 * easyPlayer->compare_frame_prm3;

    fn = frameInfo->time;
    coded = frameInfo->tunit;
    bound = fn / (coded * 600);
    floor = count / (unit * 600);
    if (bound >= 2 && floor >= 2)
    {
        if (bound <= floor)
            cycles = bound - 1;
        else
            cycles = floor - 1;
        fn -= coded * 600 * cycles;
        count -= unit * 600 * cycles;
    }

    event = (CriFloat32)fn * 1000.0f / (CriFloat32)coded;
    dest = (CriFloat32)count * 1000.0f / (CriFloat32)unit;
    extra = dest - event;
    switch (easyPlayer->compare_frame_count)
    {
    case 1:
        final = dest - inter - event;
        if (final >= 0.0f)
        {
            leave = 1;
            if (inter > final)
                easyPlayer->compare_frame_count = 2;
        }
        break;
    case 2:
        final = dest + gap - event;
        if (final >= 0.0f)
            leave = 1;
        else if (final > -inter)
            easyPlayer->compare_frame_count = 1;
        break;
    default:
        if (extra >= 0.0f)
        {
            leave = 1;
            if (gap > extra)
                easyPlayer->compare_frame_count = 2;
        }
        else if (extra > inter)
            easyPlayer->compare_frame_count = 1;
    }
    return leave;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// @0x1400351c0
void crimvply_clearAlphaFrameInfoMembers(void* info)
{
    *(CriUint64*)((CriUint8*)info + 0x00) = 0;
    *(CriSint32*)((CriUint8*)info + 0x08) = -1;
    *(CriSint32*)((CriUint8*)info + 0x0c) = 0;
    *(CriSint32*)((CriUint8*)info + 0x10) = 0;
    *(CriSint32*)((CriUint8*)info + 0x14) = 0;
    *(CriSint32*)((CriUint8*)info + 0x18) = 0;
    *(CriSint32*)((CriUint8*)info + 0x1c) = 0;
    *(CriUint64*)((CriUint8*)info + 0x20) = 0;
    *(CriUint64*)((CriUint8*)info + 0x28) = 1;
    *(CriSint32*)((CriUint8*)info + 0x30) = -1;
    *(CriSint32*)((CriUint8*)info + 0x34) = 0;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// @0x140035560
CriBool crimvply_isUnderGetFrameCondition(void* player)
{
    if (*(CriSint32*)((CriUint8*)player + 8) == 1)
        return 0;
    CriSint32 status = getInternalStatus(player);
    if (status != 5 && status != 4)
        return 0;
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// @0x1400359e0
void crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(void* player, const CriMvAlphaDecoderFrameInfo* info)
{
    if (info->PlaneIndex != -1)
    {
        ((CriMvYuvBufferState*)player)->Plane.Buffer = info->Buffer;
        ((CriMvYuvBufferState*)player)->Plane.Stride = (CriSint32)info->Height * (CriSint32)info->Stride;
        ((CriMvYuvBufferState*)player)->Plane.Height = info->Height;
    }
}

// @0x140036450
void criMvPly_SetSubtitleChannel(void* player, CriUint32 channel)
{
    *(CriUint32*)((CriUint8*)player + 0xe34) = channel;
}

// @0x1400372c0
void criMvPly_SetPcmFormat(void* player, CriSint32 format)
{
    *(CriSint32*)((CriUint8*)player + 0xe18) = format;
    if (format == 0)
        *(CriUint32*)((CriUint8*)player + 0xe1c) = 2;
    else
        *(CriUint32*)((CriUint8*)player + 0xe1c) = 4;
}

// @0x140037740
void criMvPly_SetSeekPosition(void* player, CriUint32 value0, CriUint32 value1)
{
    ((CriMvStateFlags*)player)->Value0 = value0;
    ((CriMvStateFlags*)player)->Value1 = value1;
}

// @0x140037780
void criMvPly_SetSeekAlphaPosition(void* player, CriUint32 value)
{
    ((CriMvStateFlags*)player)->Value2 = value;
}

// @0x1400379b0
extern "C" void crimvply_transitErrorState(void* player, void* message)
{
    if (message == message) {}               // the CRI unused-argument idiom: /Od loads it (the exe's dead load)
    if (player)
        ((CriMvErrorState*)player)->Error = 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// CRI Movie was built with VS2008; preserve the input-chunk state check from the executable.
// @0x140035000
CriBool isLockedInputChunk(const void* player)
{
    // The exe takes a pointer to the input-chunk state at +0xd90 and tests its lock flag at +8.
    const CriUint8* chunk = (const CriUint8*)player + 0xd90;
    return ((const CriSint32*)chunk)[2] == 0 ? 0 : 1;
}

// @0x140035050
void criMvPly_TerminateSupply(void* player)
{
    ((CriMvSupplyState*)player)->Terminated = 1;
    ((CriMvSupplyState*)player)->SupplyEnded = 1;
    criUsfDmx_TerminateSupply(((CriMvSupplyInputBuffer*)player)->InputBuffer);
}

// Resets a CriMvFrameInfo field by field, all four image planes included; pitch is left as is.
// @0x140035090
void crimvply_clearFrameInfoMembers(void* record)
{
    CriSint32 i;
    CriMvImageBufferInfo* buf;
    ((CriMvFrameInfo*)record)->imageptr = NULL;
    ((CriMvFrameInfo*)record)->frame_id = -1;
    ((CriMvFrameInfo*)record)->cnt_concatenated_movie = 0;
    ((CriMvFrameInfo*)record)->width = 0;
    ((CriMvFrameInfo*)record)->height = 0;
    ((CriMvFrameInfo*)record)->disp_width = 0;
    ((CriMvFrameInfo*)record)->disp_height = 0;
    ((CriMvFrameInfo*)record)->framerate = 0;
    ((CriMvFrameInfo*)record)->time = 0;
    ((CriMvFrameInfo*)record)->tunit = 1;
    ((CriMvFrameInfo*)record)->frame_id_per_data = -1;
    ((CriMvFrameInfo*)record)->csc_flag = 0;
    ((CriMvFrameInfo*)record)->alpha_type = 0;
    ((CriMvFrameInfo*)record)->num_images = 0;
    for (i = 0; i < 4; i++) {
        buf = &((CriMvFrameInfo*)record)->image_info[i];
        buf->imageptr = NULL;
        buf->line_pitch = 0;
        buf->line_size = 0;
        buf->num_lines = 0;
        buf->bufsize = 0;
    }
}

// return the next decoded video frame and release its decoder-owned record afterward.
// @0x1400355b0
CriBool criMvPly_DiscardNextFrame(void* player, void* output)
{
    void* decoder;
    CriBool result;
    CriMvFrameInfo info;
    void* handle;
    result = 0;
    decoder = ((CriMvDecoderHandleFields*)player)->VideoDecoder;
    crimvply_clearFrameInfoMembers(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return 0;

    handle = criVdec_GetFramePointer(decoder, &info);
    if (handle)
    {
        crimvply_makeFrameInfoMembers(player, output, &info, (CriUint64)(uintptr_t)handle, info.width);
        criVdec_ReleaseFramePointer(decoder, &info);
        // the decoder frame's concatenated-movie index (+0xa8), not the frame id: it selects the stream slot
        ((CriMvPlyObj*)player)->num_audio_out = *(CriUint32*)((CriUint8*)&info + 0xa8);
        result = 1;
    }
    return result;
}

// return decoded video metadata and copy the frame's plane descriptors into YUV buffers.
// @0x140035710
CriBool criMvPly_LockFrameBuffer(void* player, void* yuvBuffers, void* output)
{
    CriBool result = 0;
    crimvply_clearFrameInfoMembers(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return 0;

    CriMvFrameInfo frameInfo;
    void* handle = criVdec_GetFramePointer(((CriMvDecoderHandleFields*)player)->VideoDecoder, &frameInfo);
    if (handle)
    {
        crimvply_makeFrameInfoMembers(player, output, &frameInfo, (CriUint64)(uintptr_t)handle, frameInfo.width);
        // the decoder frame's concatenated-movie index (+0xa8), not the frame id: it selects the stream slot
        ((CriMvPlyObj*)player)->num_audio_out = *(CriUint32*)((CriUint8*)&frameInfo + 0xa8);
        FUN_1400358d0(yuvBuffers, &frameInfo);
        result = 1;
    }
    return result;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// CRI Base's null-safe Windows critical-section wrapper: reports failure when the call raises an SEH exception.
// @0x140039dd4
CriBool criCsWin_InitializeCriticalSection(LPCRITICAL_SECTION section)
{
    CriBool result = 1;
    if (section == NULL)
        return 0;
    __try
    {
        InitializeCriticalSection(section);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        result = 0;
    }
    return result;
}

// CRI Base's null-safe Windows critical-section wrapper: reports failure when the call raises an SEH exception.
// @0x140039dfc
CriBool criCsWin_DeleteCriticalSection(LPCRITICAL_SECTION section)
{
    CriBool result = 1;
    if (section == NULL)
        return 0;
    __try
    {
        DeleteCriticalSection(section);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        result = 0;
    }
    return result;
}

// CRI Base's null-safe Windows critical-section wrapper: reports failure when the call raises an SEH exception.
// @0x140039e24
CriBool FUN_140039e24(LPCRITICAL_SECTION section)
{
    CriBool result = 1;
    if (section == NULL)
        return 0;
    __try
    {
        EnterCriticalSection(section);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        result = 0;
    }
    return result;
}

// CRI Base's null-safe Windows critical-section wrapper: reports failure when the call raises an SEH exception.
// @0x140039e4c
CriBool FUN_140039e4c(LPCRITICAL_SECTION section)
{
    CriBool result = 1;
    if (section == NULL)
        return 0;
    __try
    {
        LeaveCriticalSection(section);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        result = 0;
    }
    return result;
}

// CRI Base: true when the calling thread holds the critical section (+0x28 owner thread, +0x2c depth).
// @0x140039e74
CriBool criCs_IsInCriticalSection(const void* state)
{
    const CriUint8* bytes = (const CriUint8*)state;
    CriBool result = 0;
    if (*(const CriSint32*)(bytes + 0x2c) <= result)
        return 0;
    result = GetCurrentThreadId() == *(const DWORD*)(bytes + 0x28);
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// The CRI Movie library was built with VS2008; this stores its caller-supplied metadata allocator.
// @0x1400301d0
void criMvPly_SetMetaDataWorkAllocator(void* player, void* work, void* allocate, void* freeFn, CriSint32 metaFlag)
{
    if (metaFlag == metaFlag) {} // read and unused, as in the exe (CriMvEasyPlayer passes its meta_flag)
    ((CriMvMetadataAllocatorFields*)player)->Work = work;
    ((CriMvMetadataAllocatorFields*)player)->Allocate = allocate;
    ((CriMvMetadataAllocatorFields*)player)->Free = freeFn;
}

// the work-size helper combines the CRI RBF, demux, and two universal-jump-buffer requirements.
// the local names place them in the exe's stack slots (cl 15 orders /Od locals by name hash).
// @0x14002e9e0
CriSint32 criMvPly_CalcHandleWorkSize(void)
{
    struct RbfConfig { CriUint32 Mode; CriUint32 Size; CriUint32 Reserved8; CriUint32 Alignment; CriUint64 Reserved10; };
    struct UniConfig { CriUint32 Mode; CriUint32 Reserved4; CriUint32 Alignment; };
    CriSint32 rbfSize;
    RbfConfig rbfParam;
    CriSint32 total;
    UniConfig uniConfigB;
    CriSint32 demuxLen;
    total = 0;
    total += 0xf1c;
    total += 0x4c;
    total += 0x2804;
    memset(&rbfParam, 0, sizeof(rbfParam));
    rbfParam.Mode = 1;
    rbfParam.Reserved10 = 0;
    rbfParam.Size = 0x2800;
    rbfParam.Reserved8 = 0;
    rbfParam.Alignment = 0x40;
    rbfSize = criSjRbf_CalculateWorkSize((const CriSint32*)&rbfParam);
    total = total + rbfSize + 4;
    demuxLen = criUsfDmx_CalculateWorkSizeWithWork(8);
    total = total + demuxLen + 4;
    memset(&uniConfigB, 0, sizeof(uniConfigB));
    uniConfigB.Mode = 1;
    uniConfigB.Reserved4 = 0;
    uniConfigB.Alignment = 0x40;
    total += criSjUni_CalculateWorkSize((const CriSint32*)&uniConfigB);
    memset(&uniConfigB, 0, sizeof(uniConfigB));
    uniConfigB.Mode = 1;
    uniConfigB.Reserved4 = 0;
    uniConfigB.Alignment = 4;
    total += criSjUni_CalculateWorkSize((const CriSint32*)&uniConfigB);
    return total;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// register the next output stream buffer with the demuxer, logging an error past the capacity
// @0x1400345e0
void criMvPly_SetDemuxOutputSj(void* player, void* value, CriUint32 type, CriUint32 flags)
{
    void* output = ((CriMovieOutputLogView*)player)->Output;
    CriUint32 count = ((CriMovieOutputLogView*)player)->Count;
    if (count >= ((CriMovieOutputLogView*)player)->Capacity)
        crimvply_occurFatalError(player, "E05063025M : Can't entry output sj to demux more than limit.", count);
    criUsfDmx_SetOutputSj(output, count, value, type, flags);
    ((CriMovieOutputLogView*)player)->Count++;
}

// Detect terminal decoder errors and report them through the player error logger.
// @0x140034690
extern "C" void executeVideoServer(void* player)
{
    void* videoDec = ((CriMvDecoderHandleFields*)player)->VideoDecoder;
    if (videoDec)
    {
        criVdec_Execute((CriUint64*)videoDec);
        if (criVdec_GetStatus(videoDec) == 4)
        {
            crimvply_transitErrorState(player, (void*)"The internal status of Vdec is ERROR.");
            return;
        }
    }
    void* alphaDec = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
    if (alphaDec)
    {
        criAlphaDec_Execute(alphaDec);
        if (criAlphaDec_GetStatus(alphaDec) == 4)
            crimvply_transitErrorState(player, (void*)"The internal status of AlphaDec is ERROR.");
    }
}

// accept decoded primary-stream metadata and decrement its pending record count.
// @0x1400340f0
CriBool FUN_1400340f0(void* player, const CriMovieInputChunk* input)
{
    CriUint32* output;
    CriMovieParsedChunk parsed;
    CriMovieStreamSlotsView* state = (CriMovieStreamSlotsView*)player;
    CriMovieStreamSlotView* slot = &state->Ring.Slots[state->Selector.Current];
    if (!slot->Active)
        return 0;
    else if (input->Size >= 0x20)
    {
        parsed.Data = criUsfCmn_GetContents(input->Data, input->Size, &parsed.Size);
        output = (CriUint32*)slot->PrimaryOutput;
        FUN_140032650(state, slot, output, &parsed);
        --slot->PendingPrimary;
        prepareNextHeaderIfCompleted(state, slot);
    }
    return 1;
}

// accept decoded subtitle-stream metadata and decrement its pending record count.
// @0x1400341d0
CriBool FUN_1400341d0(void* player, const CriMovieInputChunk* input)
{
    CriMovieParsedChunk parsed;
    CriMovieStreamSlotsView* state = (CriMovieStreamSlotsView*)player;
    CriMovieStreamSlotView* slot = &state->Ring.Slots[state->Selector.Current];
    if (!slot->Active)
        return 0;
    else if (input->Size >= 0x20)
    {
        parsed.Data = criUsfCmn_GetContents(input->Data, input->Size, &parsed.Size);
        CriUint32* output = (CriUint32*)slot->SubtitleOutput;
        FUN_140032db0(state, slot, output, &parsed);
        --slot->PendingAlpha;
        prepareNextHeaderIfCompleted(state, slot);
    }
    return 1;
}

// accept decoded alpha-stream metadata and decrement its pending record count.
// @0x140036d50
extern "C" CriBool recordSubtitleHeader(void* player, const CriMovieInputChunk* input)
{
    CriUint32* dst;
    CriMovieParsedChunk meta;
    CriMovieStreamSlotView* slot =
        &((CriMovieStreamSlotsView*)player)->Ring.Slots[((CriMovieStreamSlotsView*)player)->Selector.Current];
    if (!slot->Active)
        return 0;
    else if (input->Size >= 0x20)
    {
        meta.Data = criUsfCmn_GetContents(input->Data, input->Size, &meta.Size);
        dst = (CriUint32*)slot->AlphaOutput;
        retrieveSubtitleHeader(player, slot, dst, &meta);
        --slot->PendingSubtitle;
        prepareNextHeaderIfCompleted(player, slot);
    }
    return 1;
}

// Replace the pending movie chunk and save the most recently enqueued record.
// @0x1400363b0
extern "C" void criMvPly_AddInputMemory(void* player, void* chunk, CriUint32 type)
{
    CriMovieChunkQueueRecord item;
    CriMovieChunkQueueRecord stale;          // the replaced chunk is popped into its own record
    if ((CriUint32)FUN_1400467b8(((CriMovieQueueView*)player)->Queue, 0) > 0)
        criSj_GetChunk(((CriMovieQueueView*)player)->Queue, 0, -1, &stale);
    item.Chunk = chunk;
    item.Type = type;
    criSj_PutChunk(((CriMovieQueueView*)player)->Queue, 1, &item);
    memcpy(((CriMovieQueueView*)player)->LastChunk, &item, sizeof(item));
}

// Forward video sizing and stream metadata to the video and alpha decoder interfaces.
// @0x1400377a0
void setProcessorParams(void* player, void* videoDecoder, void* alphaDecoder)
{
    criVdec_SetProcessorMask(videoDecoder, ((CriUint32*)player)[0x8d0 / 4]);
    criAlphaDec_SetProcessorMask((CriUint64*)alphaDecoder, ((CriUint32*)player)[0x8d0 / 4]);
    criVdec_SetDlgPara(videoDecoder, ((CriUint32*)player)[0x8cc / 4], (CriUint32*)player + 0x8d4 / 4,
                  (CriUint32*)player + 0x9d4 / 4);
    criAlphaDec_SetDlgPara((CriUint64*)alphaDecoder, ((CriUint32*)player)[0x8cc / 4], (CriUint32*)player + 0x8d4 / 4,
                  (CriUint32*)player + 0x9d4 / 4);
}

// The CRI Movie sub-audio helper forwards the caller's sizing inputs with flags set to zero.
// @0x140030f10
CriBool criMvPly_AttachSubAudio(void* player, void* source, CriUint32 stream)
{
    // The exe passes the stream's 16-byte entry at +0xb2c and reloads the source from the player.
    ((CriMovieAttachView*)player)->AttachedSource = source;
    CriBool attached = criMvPlyAmng_CreateAudioDecoder(((CriMovieAttachView*)player)->Manager, player,
                                     ((CriMovieAttachView*)player)->AttachedSource,
                                     (const CriUint32*)(&((CriMovieAttachView*)player)->Streams[stream]), stream, 1);
    if (!attached)
        return 0;
    if (criMvPly_IsSetDefaultDecryptionKey() == 1)
        criMvPlyAmng_SetDecryptCallback(((CriMovieAttachView*)player)->Manager, (void*)FUN_140038000, player, 1);
    return 1;
}

// The CRI Movie sub-audio helper sizes the player's audio track work area (exe passes only the two args).
// @0x140030ed0
CriSint32 criMvPly_CalcSubAudioWorkSize(void* player, void* source)
{
    CriSint32 size = 0;
    size = criMvPlyAmng_CalcAudioDecoderWorkSize(player, (const CriUint32*)source);
    return size;
}

// Retain CRI's critical-section bracket around work-buffer preparation.
// @0x140030230
CriUint32 criMvPly_AllocateWorkBuffer(void* player, void* heap, void* work)
{
    enterHandleCs(player);
    CriUint32 result = crimvply_AllocateWorkBufferInCs(player, heap, work);
    leaveHandleCs(player);
    return result;
}

// Create the supplied-memory heap, store it in the player, then prepare its work buffers under lock.
// @0x140030e50
CriUint32 criMvPly_AllocateWorkBufferWithWork(void* player, void* memory, CriSint32 size, void* work)
{
    enterHandleCs(player);
    ((CriMvHeapWorkState*)player)->Heap = criHeap_Create(memory, size);
    CriUint32 result = crimvply_AllocateWorkBufferInCs(player, ((CriMvHeapWorkState*)player)->Heap, work);
    leaveHandleCs(player);
    return result;
}

// Absent decoder interfaces and missing core functions use the executable's divided-input fallback.
// @0x140037360
CriBool isAvailableDividedInputChunk(void* player)
{
    void* decoder;                           // declared before res: the two share a VC9 slot bucket (see p10/probe)
    void* core;
    CriBool res;
    res = 0;
    decoder = 0;
    core = 0;
    decoder = crimvply_findVdecIF(*(CriSint32*)((CriUint8*)player + 0x44));
    if (!decoder)
        res = 1;
    else if (!(core = criVdec_GetVdecCoreIf(decoder)))
        res = 1;
    else if (!*(void**)((CriUint8*)core + 0x10))
        res = 1;
    else
        res = (*(CriBool(__fastcall**)(void))((CriUint8*)core + 0x10))();
    return res;
}

// A divided decoder input uses the fixed extension; otherwise retain the configured minimum size.
// @0x140037310
CriUint32 decideReadBufferExtSize(void* player)
{
    CriUint32 size;
    if (isAvailableDividedInputChunk(player) == 1)
        size = 0x2800;
    else
    {
        size = *(CriUint32*)((CriUint8*)player + 0x0c);
        if (size < 0x2800)
            size = 0x2800;
    }
    return size;
}

// Selects the active CRI read buffer and returns its available and bounded sizes.
// @0x140037050
extern "C" void* criMvPly_GetInputSj(void* player, CriUint32* available, CriUint32* bounded)
{
    void* buffer = NULL;
    CriUint32 first = 0;
    CriUint32 second = 0;
    if (((CriMvReadBufferState*)player)->Mode == 0)
    {
        if (getInternalStatus(player) == 1)
        {
            if (((CriMvReadBufferState*)player)->BufferMode == 0)
            {
                buffer = ((CriMvReadBufferState*)player)->ReadyBuffer;
                first = ((CriMvReadBufferState*)player)->DataAvailable;
                second = ((CriMvReadBufferState*)player)->DataAvailable;
            }
            else
            {
                buffer = ((CriMvReadBufferState*)player)->Buffer;
                first = ((CriMvReadBufferState*)player)->BufferSize;
                second = ((CriMvReadBufferState*)player)->BufferSize;
            }
        }
        else
        {
            buffer = ((CriMvReadBufferState*)player)->ReadBuffer;
            first = ((CriMvReadBufferState*)player)->ReadBufferSize;
            second = (CriUint32)((float)(((CriMvReadBufferState*)player)->AverageReadSize / 8)
                                 * ((CriMvReadBufferState*)player)->ReadRate);
            if (second > first)
                second = first;
        }
    }
    else
    {
        buffer = ((CriMvReadBufferState*)player)->CurrentBuffer;
        first = 0;
        second = 0;
    }
    if (available != NULL)
        *available = first;
    if (bounded != NULL)
        *bounded = second;
    return buffer;
}

// Report bytes in the current or selected CRI input buffer, including partially consumed chunks.
// @0x1400371d0
CriSint32 criMvPly_PeekInputBufferData(void* player)
{
    CriSint32 result = 0;
    void* buffer;
    if (((CriMvReadBufferState*)player)->Mode == 0)
    {
        if (getInternalStatus(player) == 1)
        {
            if (((CriMvReadBufferState*)player)->BufferMode == 0)
                buffer = ((CriMvReadBufferState*)player)->ReadyBuffer;
            else
                buffer = ((CriMvReadBufferState*)player)->Buffer;
        }
        else
        {
            buffer = ((CriMvReadBufferState*)player)->ReadBuffer;
        }
    }
    else
    {
        buffer = ((CriMvReadBufferState*)player)->CurrentBuffer;
    }
    if (buffer != NULL)
    {
        if (((CriMvReadBufferState*)player)->Mode == 1)
            result = ((CriMvReadBufferState*)player)->CurrentOffset
                   - FUN_1400467b8(((CriMvReadBufferState*)player)->CurrentBuffer, 0);
        else
            result = FUN_1400467b8(buffer, 1);
    }
    return result;
}

// Enter the player's lock through the CRI critical-section wrapper.
// @0x140037850
void enterHandleCs(void* player)
{
    criCs_Enter((_RTL_CRITICAL_SECTION*)(*(void**)((CriUint8*)player + 0x20)));
}

// Leave the player's lock through the CRI critical-section wrapper.
// @0x140037880
void leaveHandleCs(void* player)
{
    criCs_Leave((_RTL_CRITICAL_SECTION*)(*(void**)((CriUint8*)player + 0x20)));
}

// Forward CRI's non-state-changing diagnostic through the shared error notifier.
// @0x140037910
extern "C" void crimvply_occurFatalError(void* owner, const char* message, CriSint32 value)
{
    criErr_NotifyPrmArray(0, message, value, 0, owner);
}

// Mark the movie player in error before forwarding the diagnostic.
// @0x140037950
extern "C" void crimvply_occurUserError(void* owner, const char* message, CriSint32 value)
{
    if (owner)
        ((CriMvErrorState*)owner)->Error = 1;
    criErr_NotifyPrmArray(0, message, value, 0, owner);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Convert the decoder's frame metadata into the 0x38-byte output info, taking the dimensions from the
// movie. This is not a plain copy: the decoder's +0x14 moves to +0x1c, and +0x14/+0x18/+0x34 come from the player.
// @0x140035480
extern "C" void crimvply_makeAlphaFrameInfoMembers(void* player, void* destination, const void* source)
{
    struct FrameView
    {
        CriUint64 Field00;
        CriUint32 Field08;
        CriUint32 Field0C;
        CriUint32 Field10;
        CriUint32 Field14;
        CriUint32 Field18;
        CriUint32 Field1C;
        CriUint64 Field20;
        CriUint64 Field28;
        CriUint32 Field30;
        CriUint32 Field34;
    };
    ((FrameView*)destination)->Field00 = ((const FrameView*)source)->Field00;
    ((FrameView*)destination)->Field08 = ((const FrameView*)source)->Field08;
    ((FrameView*)destination)->Field0C = ((const FrameView*)source)->Field0C;
    ((FrameView*)destination)->Field10 = ((const FrameView*)source)->Field10;
    ((FrameView*)destination)->Field1C = ((const FrameView*)source)->Field14;
    ((FrameView*)destination)->Field20 = ((const FrameView*)source)->Field20;
    ((FrameView*)destination)->Field28 = ((const FrameView*)source)->Field28;
    ((FrameView*)destination)->Field30 = ((const FrameView*)source)->Field30;
    ((FrameView*)destination)->Field34 = ((const CriMvAlphaMovieDimensions*)player)->DisplayWidth;
    ((FrameView*)destination)->Field14 = ((const CriMvAlphaMovieDimensions*)player)->Width;
    ((FrameView*)destination)->Field18 = ((const CriMvAlphaMovieDimensions*)player)->Height;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Ask the alpha decoder to copy one frame into the caller's buffers and publish its metadata.
// @0x140035af0
CriBool criMvPly_GetAlphaFrame(void* player, void* buffer, CriUint32 format, void* outputInfo)
{
    struct DimensionsView { CriUint8 Reserved[0x60c]; CriUint32 Width; CriUint32 Height; };
    struct BufferRequest { void* Buffer; CriUint32 Width; CriUint32 Height; CriUint32 Format; };
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): frameInfo, ret, buf.
    CriUint64 frameInfo[10];                 // the 0x50-byte alpha frame record, filled by the decoder
    BufferRequest buf;
    CriSint32 ret = 0;
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder == NULL || !crimvply_isUnderGetFrameCondition(player))
        return 0;
    buf.Buffer = buffer;
    buf.Width = ((DimensionsView*)player)->Width;
    buf.Height = ((DimensionsView*)player)->Height;
    buf.Format = format;
    ret = criAlphaDec_CopyAlphaFrameBuffer(((CriMvDecoderHandleFields*)player)->AlphaDecoder, &buf, frameInfo);
    if (ret == 0)
    {
        crimvply_occurFatalError(NULL, "E08082104M : Cannot copy the alpha frame buffer to user's buffer.", 0);
        return 0;
    }
    crimvply_makeAlphaFrameInfoMembers(player, outputInfo, frameInfo);
    return 1;
}

// Release the alpha decoder frame using its copied frame descriptor when an alpha decoder exists.
// @0x140035a90
CriBool criMvPly_UnlockAlphaFrameBuffer(void* player, const CriUint64* frameInfo)
{
    if (!((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        return 0;
    CriUint64 local[10];                     // only the first word is set, as in the exe (0x50-byte frame record)
    local[0] = *frameInfo;
    criAlphaDec_ReleaseAlphaFramePointer((CriUint64*)((CriMvDecoderHandleFields*)player)->AlphaDecoder, local);
    return 1;
}

// Release the main decoder's current frame using the descriptor's first pointer.
// @0x140035a40
CriBool criMvPly_UnlockFrameBuffer(void* player, const CriMvFrameInfo* frameInfo)
{
    void* localFrame[21];
    localFrame[0] = (void*)*(const CriUint64*)frameInfo;
    criVdec_ReleaseFramePointer(*(void**)((CriUint8*)player + 0xe08), localFrame);
    return 1;
}

// Drain and release every queued alpha frame from the player decoder.
// @0x140035bf0
void flushAlphaFrame(void* player)
{
    CriUint64 frameInfo[10];
    void* frame = NULL;
    frame = criAlphaDec_GetAlphaFramePointer(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
    while (frame != NULL)
    {
        criAlphaDec_ReleaseAlphaFramePointer((CriUint64*)((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
        frame = criAlphaDec_GetAlphaFramePointer(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
    }
}

// Forward the player's video decoder and all five caller outputs to its frame-pool query.
// @0x140036ed0
void criMvPly_GetFramePoolInfo(void* player, void* a, void* b, void* c, void* d, void* e)
{
    if (player == NULL)
        return;
    criVdec_GetFramePoolInfo(((CriMvDecoderHandleFields*)player)->VideoDecoder, a, b, c, d, e);
}

// Request the main audio stream's current data size from the movie audio manager.
// @0x1400360c0
CriUint32 criMvPly_GetDataSizeMainAudio(void* player, CriUint32 channels)
{
    CriUint32 size = criMvPlyAmng_GetDataSizeWave(((CriMvSubAudioHandles*)player)->Manager, 0, player, channels);
    return size;
}

// Request the secondary audio stream's current data size from the movie audio manager.
// @0x140036100
CriUint32 criMvPly_GetDataSizeSubAudio(void* player, CriUint32 channels)
{
    CriUint32 size = criMvPlyAmng_GetDataSizeWave(((CriMvSubAudioHandles*)player)->Manager, 1, player, channels);
    return size;
}

// Query the main audio stream's playback-complete state.
// @0x140036140
CriBool criMvPly_IsEndMainAudioPlayback(void* player)
{
    return criMvPlyAmng_IsEndAudioPlaybackById(((CriMvSubAudioHandles*)player)->Manager, player, 0);
}

// Query the secondary audio stream's playback-complete state.
// @0x140036170
CriBool criMvPly_IsEndSubAudioPlayback(void* player)
{
    return criMvPlyAmng_IsEndAudioPlaybackById(((CriMvSubAudioHandles*)player)->Manager, player, 1);
}

// Detach and clear the secondary audio decoder handle.
// @0x140030fd0
void criMvPly_DetachSubAudio(void* player)
{
    criMvPlyAmng_DestroyAudioDecoder(((CriMvSubAudioHandles*)player)->Manager, ((CriMvSubAudioHandles*)player)->Decoder, 1);
    ((CriMvSubAudioHandles*)player)->Decoder = NULL;
}

// Decode a subtitle record and calculate its audio-synchronized presentation position.
// @0x140036f40
extern "C" void analyzeSubtitleInfo(void* player, CriMvSubtitleChunk* chunk, void* outputInfo)
{
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): p, length, ptr, curTime, tunit.
    const CriUint8* p;
    CriSint32 length;
    const CriSint32* ptr;
    CriUint64 curTime;
    CriUint64 tunit;
    p = criUsfCmn_GetContents(chunk->Data, chunk->Size, &length);
    ptr = (const CriSint32*)p;
    ((CriMvSubtitleInfo*)outputInfo)->channel_no = ptr[0];
    ((CriMvSubtitleInfo*)outputInfo)->time_unit = ptr[1];
    ((CriMvSubtitleInfo*)outputInfo)->in_time_per_data = ptr[2];
    ((CriMvSubtitleInfo*)outputInfo)->duration_time = ptr[3];
    ((CriMvSubtitleInfo*)outputInfo)->data_size = ptr[4];
    ((CriMvSubtitleInfo*)outputInfo)->dataptr = (CriUint8*)(ptr + 5);
    ((CriMvSubtitleInfo*)outputInfo)->cnt_concatenated_movie = ((CriMvSubtitleFields*)player)->SubtitleIndex;
    criVdec_GetOffsetConcatenated(((CriMvDecoderHandleFields*)player)->VideoDecoder,
                  ((CriMvSubtitleInfo*)outputInfo)->cnt_concatenated_movie, &curTime, &tunit);
    ((CriMvSubtitleInfo*)outputInfo)->in_time = curTime / tunit * ((CriMvSubtitleInfo*)outputInfo)->time_unit
                                               + ((CriMvSubtitleInfo*)outputInfo)->in_time_per_data;
}

// obtain the next valid subtitle's decoded metadata and return its chunk to the queue afterward.
// @0x140036590
void criMvPly_GetNextSubtitleInfo(void* player, void* outputInfo)
{
    memset(outputInfo, 0, 0x38);
    *(CriUint64*)((CriUint8*)outputInfo + 0x10) = 1;
    if (!player)
        return;
    if (!((CriMvSubtitleFields*)player)->Queue)
        return;
    CriMvSubtitleChunk chunk;  // FUN_140036b80 clears it
    FUN_140036b80(player, &chunk, ((CriMvSubtitleFields*)player)->SubtitleChannel);
    if (!chunk.Data || chunk.Size < 0x20)
    {
        ungetSubtitleChunk(player, &chunk);
        return;
    }
    analyzeSubtitleInfo(player, &chunk, outputInfo);
    ungetSubtitleChunk(player, &chunk);
}

// This CRI EasyFileReader utility is the executable's unsigned base-conversion parser.
// @0x140038bd0
CriUint64 FUN_140038bd0(void* reader, const CriChar8* text, CriChar8** end, CriSint32 radix)
{
    (void)reader;                            // the exe passes the reader through (a member call) and ignores it
    return _strtoui64(text, end, radix);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// Forward CRI Base's two-argument notification to its shared error dispatch routine.
// @0x140038ddc
void criErr_Notify(CriSint32 category, const CriChar8* message)
{
    criErr_NotifyPrmArray(category, message, 0, 0, NULL);
}

// The three-argument notification: the category, message and value go through unchanged (the exe sets only the flags
// and owner).
// @0x140038df8
void FUN_140038df8(CriSint32 category, const CriChar8* message, CriSint32 value)
{
    criErr_NotifyPrmArray(category, message, value, 0, NULL);
}

// The four-argument notification: everything but the owner goes through unchanged.
// @0x140038e10
void FUN_140038e10(CriSint32 category, const CriChar8* message, CriSint32 value, CriSint32 flags)
{
    criErr_NotifyPrmArray(category, message, value, flags, NULL);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Enter the movie player's shared handle critical section.
// @0x1400378b0
void enterCriticalSection(void* player)
{
    if (player == player) {}                 // the CRI unused-argument idiom: /Od loads player (the exe's dead load)
    criCs_Enter((_RTL_CRITICAL_SECTION*)DAT_143ffd550);
}

// Leave the movie player's shared handle critical section.
// @0x1400378e0
void leaveCriticalSection(void* player)
{
    if (player == player) {}                 // the CRI unused-argument idiom: /Od loads player (the exe's dead load)
    criCs_Leave((_RTL_CRITICAL_SECTION*)DAT_143ffd550);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// Publish the executable's CRI Critical Section runtime banner.
// @0x1400385b8
void criCs_GetVersionString(void)
{
    DAT_143b27aa8 = "\nCRI Critical Section/PCx64 Ver.1.00.12 Build:Jan 13 2012 19:02:02\n";
}

// Initialize CRI Error's shared lock and install its initial callback.
// @0x140038ca8
void criErr_SetCallback(void* callback)
{
    criBaseVersion_ImplantVersionInformation();
    DAT_143b27bb0 = "\nCRI Error/PCx64 Ver.1.03.00 Build:Jan 13 2012 19:02:07\n";
    DAT_143b27bb8 = callback;
}

// Dispatch through the optional callback while temporarily suppressing recursive dispatch, then update the appropriate counter.
// @0x140038ce4
void criErr_NotifyPrmArray(CriSint32 category, const char* message, CriSint32 value, CriSint32 flags, void* owner)
{
    criBaseVersion_ImplantVersionInformation();
    typedef void (*CriErrorCallback)(const char*, CriSint32, CriSint32, void*);
    CriErrorCallback notify = (CriErrorCallback)DAT_143b27bb8;
    CriErrorCallback secondary = (CriErrorCallback)DAT_143b27bc0;
    if (secondary)
    {
        DAT_143b27bb8 = NULL;
        DAT_143b27bc0 = NULL;
        secondary(message, value, flags, owner);
        DAT_143b27bb8 = (void*)notify;
        DAT_143b27bc0 = (void*)secondary;
    }
    if (DAT_143b27bc8 == 1 && category == 1)
        ++DAT_143b27bd0;
    else
    {
        ++DAT_143b27bcc;
        if (notify)
            notify(message, value, flags, owner);
    }
}

// The error-text lookup; inlined into criErr_NotifyGeneric, its early return is the exe's out-of-line found block.
static __inline const char* criErr_GetErrorText(CriSint32 error)
{
    CriSint32 i;
    for (i = 0; DAT_1431b97a0[i].text != NULL; i++)
    {
        if (DAT_1431b97a0[i].code == error)
            return DAT_1431b97a0[i].text;
    }
    return "Unknown Error.";
}

// Find the CRI error text by code, format its message, and send it through the shared dispatcher.
// @0x140038e24
void criErr_NotifyGeneric(CriSint32 category, const char* code, CriSint32 error)
{
    const char* description = criErr_GetErrorText(error);
    FUN_140046944(DAT_143b27ab0, 0x100, code);
    FUN_14004698c(DAT_143b27ab0, 0x100, DAT_1431b9820);
    FUN_14004698c(DAT_143b27ab0, 0x100, description);
    criErr_NotifyPrmArray(category, DAT_143b27ab0, 0, 0, NULL);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)

// Copies the CRI decoded frame planes and stream dimensions into the public frame record.
// @0x140035260
extern "C" void crimvply_makeFrameInfoMembers(void* player, void* output, const void* frameInfo,
                   CriUint64 firstWord, CriUint32 flags)
{
    struct PlaneSource { CriUint64 data; CriUint32 width; CriUint32 lines; CriUint32 pitch; };
    struct FrameSource {
        CriUint64 token; CriUint32 frameId; CriUint32 width; CriUint32 height; CriUint32 pitch;
        CriUint64 displayWidth; CriUint64 displayHeight; CriUint32 frameSize; CriUint8 reserved0[12];
        CriUint32 planeCount; CriUint8 reserved1[4]; PlaneSource planes[4]; CriUint8 reserved2[8];
        CriUint32 textureWidth; CriUint32 textureHeight;
    };
    struct PlaneOutput { CriUint64 data; CriUint32 size; CriUint32 pitch; CriUint32 width; CriUint32 lines; };
    struct FrameOutput {
        CriUint64 token; CriUint32 frameId; CriUint32 width; CriUint32 height; CriUint32 flags;
        CriUint32 playerWidth; CriUint32 playerHeight; CriUint32 pitch; CriUint32 reserved0;
        CriUint64 displayWidth; CriUint64 displayHeight; CriUint32 textureWidth; CriUint32 frameSize;
        CriUint32 textureHeight; CriUint32 playerFormat; CriSint32 planeCount; CriUint32 reserved1;
        PlaneOutput planes[4];
    };
    ((FrameOutput*)output)->token = firstWord;
    ((FrameOutput*)output)->frameId = ((const FrameSource*)frameInfo)->frameId;
    ((FrameOutput*)output)->textureWidth = ((const FrameSource*)frameInfo)->textureWidth;
    ((FrameOutput*)output)->width = ((const FrameSource*)frameInfo)->width;
    ((FrameOutput*)output)->height = ((const FrameSource*)frameInfo)->height;
    ((FrameOutput*)output)->flags = flags;
    ((FrameOutput*)output)->pitch = ((const FrameSource*)frameInfo)->pitch;
    ((FrameOutput*)output)->displayWidth = ((const FrameSource*)frameInfo)->displayWidth;
    ((FrameOutput*)output)->displayHeight = ((const FrameSource*)frameInfo)->displayHeight;
    ((FrameOutput*)output)->frameSize = ((const FrameSource*)frameInfo)->frameSize;
    ((FrameOutput*)output)->textureHeight = ((const FrameSource*)frameInfo)->textureHeight;
    memcpy(&((FrameOutput*)output)->playerWidth, (const CriUint8*)player + 0xafc, sizeof(CriUint32));
    memcpy(&((FrameOutput*)output)->playerHeight, (const CriUint8*)player + 0xb00, sizeof(CriUint32));
    memcpy(&((FrameOutput*)output)->playerFormat, (const CriUint8*)player + 0xd54, sizeof(CriUint32));
    ((FrameOutput*)output)->planes[0].data = 0;
    ((FrameOutput*)output)->planes[1].data = 0;
    ((FrameOutput*)output)->planes[2].data = 0;
    ((FrameOutput*)output)->planes[3].data = 0;
    ((FrameOutput*)output)->planeCount = ((const FrameSource*)frameInfo)->planeCount;
    for (CriSint32 i = 0; i < ((FrameOutput*)output)->planeCount; ++i)
    {
        PlaneOutput* dest = &((FrameOutput*)output)->planes[i];
        dest->data = ((const FrameSource*)frameInfo)->planes[i].data;
        dest->pitch = ((const FrameSource*)frameInfo)->planes[i].pitch;
        dest->width = ((const FrameSource*)frameInfo)->planes[i].width;
        dest->lines = ((const FrameSource*)frameInfo)->planes[i].lines;
        dest->size = dest->pitch * dest->lines;
    }
}

// The playback statistics at CriMvEasyPlayer+0x668, as the exe reads them field by field.
struct PlaybackStatsView
{
    CriUint64  frames;          // 0x668
    CriUint64  skipped[4];      // 0x670: 1, 2, 3 and more frames since the last one
    CriUint64  late;            // 0x690
    CriUint64  starved;         // 0x698
    CriFloat32 maxDelay;        // 0x6a0
    CriFloat32 avgDelay;        // 0x6a4
};
#define MS2_PLAYBACK_STATS(p) (*(PlaybackStatsView*)(p)->playback_info)

// Update playback-frame timing statistics and the public frame-result state.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): res, elapsed, cur, step, units, gap, info.
// @0x1400393f0
void FUN_1400393f0(CriMvEasyPlayer* player, CriSint32 onTime, CriSint32 validFrame,
                   CriSint32 dropped, CriUint64 count, CriUint64 unit)
{
    if (onTime == 1 && validFrame == 1 && player->unk650 == 0)
    {
        player->unk650 = 1;
    }
    else if (onTime == 0)
    {
        ++MS2_PLAYBACK_STATS(player).late;
        player->last_frame_result = 1;
    }
    else
    {
        if (validFrame == 1)
        {
            CriUint64 res;
            CriFloat32 elapsed;
            CriFloat32 cur;
            CriFloat32 step;
            CriUint64 units;
            CriUint64 gap;
            gap = MS2_PLAYBACK_STATS(player).frames - player->unk658;
            switch (gap)
            {
            case 0:
                break;
            case 1:
                ++MS2_PLAYBACK_STATS(player).skipped[0];
                break;
            case 2:
                ++MS2_PLAYBACK_STATS(player).skipped[1];
                break;
            case 3:
                ++MS2_PLAYBACK_STATS(player).skipped[2];
                break;
            default:
                ++MS2_PLAYBACK_STATS(player).skipped[3];
                break;
            }
            player->GetTime(res, units, CriMv::ErrorContainer);
            cur = (CriFloat32)res / (CriFloat32)units;
            step = (CriFloat32)count / (CriFloat32)unit;
            elapsed = (cur - step) * 1000.0f;
            if (elapsed > MS2_PLAYBACK_STATS(player).maxDelay)
                MS2_PLAYBACK_STATS(player).maxDelay = elapsed;
            player->unk660 += elapsed;
            if (MS2_PLAYBACK_STATS(player).frames == 0)
                MS2_PLAYBACK_STATS(player).avgDelay = player->unk660;
            else
                MS2_PLAYBACK_STATS(player).avgDelay = player->unk660 / (CriFloat32)MS2_PLAYBACK_STATS(player).frames;
            player->unk658 = MS2_PLAYBACK_STATS(player).frames;
            player->last_frame_result = 0;
        }
        else if (!player->modules_stopped)
        {
            CriMvInputBufferInfo info;
            ++MS2_PLAYBACK_STATS(player).starved;
            player->GetInputBufferInfo(info, CriMv::ErrorContainer);
            player->last_frame_result = 2;
        }
        if (dropped != 0)
            player->last_frame_result = 3;
    }
}

// Derive the 32-byte CRI USM key bytes, their inverted copy and the byte mask from the key seed.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): dst, i, mask, bytes, src.
// @0x140038190
void generateDecryptMask(const void* key)
{
    const CriUint8* src;
    CriUint8* bytes;
    CriUint8* mask;
    CriUint32 i;
    CriUint8* dst;
    bytes = DAT_143b27a48;   // the key bytes, read by the USM decryptor together with the inverted copy
    dst = DAT_143b27a68;
    mask = DAT_143b27a88;
    bytes[0] = (CriUint8)((CriUint64)key & 0xff);
    bytes[1] = (CriUint8)(((CriUint64)key >> 8) & 0xff);
    bytes[2] = (CriUint8)(((CriUint64)key >> 16) & 0xff);
    bytes[3] = (CriUint8)((((CriUint64)key >> 24) - 0x34) & 0xff);
    bytes[4] = (CriUint8)((((CriUint64)key >> 32) + 0xf9) & 0xff);
    bytes[5] = (CriUint8)((((CriUint64)key >> 40) ^ 0x13) & 0xff);
    bytes[6] = (CriUint8)((((CriUint64)key >> 48) + 0x61) & 0xff);
    bytes[7] = (CriUint8)(bytes[0] ^ 0xff);
    bytes[8] = (CriUint8)(bytes[2] + bytes[1]);
    bytes[9] = (CriUint8)(bytes[1] - bytes[7]);
    bytes[10] = (CriUint8)(bytes[2] ^ 0xff);
    bytes[11] = (CriUint8)(bytes[1] ^ 0xff);
    bytes[12] = (CriUint8)(bytes[11] + bytes[9]);
    bytes[13] = (CriUint8)(bytes[8] - bytes[3]);
    bytes[14] = (CriUint8)(bytes[13] ^ 0xff);
    bytes[15] = (CriUint8)(bytes[10] - bytes[11]);
    bytes[16] = (CriUint8)(bytes[8] - bytes[15]);
    bytes[17] = (CriUint8)(bytes[16] ^ bytes[7]);
    bytes[18] = (CriUint8)(bytes[15] ^ 0xff);
    bytes[19] = (CriUint8)(bytes[3] ^ 0x10);
    bytes[20] = (CriUint8)(bytes[4] - 0x32);
    bytes[21] = (CriUint8)(bytes[5] + 0xed);
    bytes[22] = (CriUint8)(bytes[6] ^ 0xf3);
    bytes[23] = (CriUint8)(bytes[19] - bytes[15]);
    bytes[24] = (CriUint8)(bytes[21] + bytes[7]);
    bytes[25] = (CriUint8)('!' - bytes[19]);
    bytes[26] = (CriUint8)(bytes[20] ^ bytes[23]);
    bytes[27] = (CriUint8)(bytes[22] + bytes[22]);
    bytes[28] = (CriUint8)(bytes[23] + 0x44);
    bytes[29] = (CriUint8)(bytes[3] + bytes[4]);
    bytes[30] = (CriUint8)(bytes[5] - bytes[22]);
    bytes[31] = (CriUint8)(bytes[29] ^ bytes[19]);
    for (i = 0; i < 0x20; i++)
        dst[i] = (CriUint8)(bytes[i] ^ 0xff);
    src = (const CriUint8*)"URUC";
    for (i = 0; i < 0x20; i++)
    {
        if (i % 2 == 0)
            mask[i] = dst[i];
        else
            mask[i] = src[(i % 8) / 2];
    }
}

// Retain the default USM decryption key and update the shared decryptor state.
// @0x1400379e0
void criMvPly_SetDefaultDecryptionKey(const void* key)
{
    DAT_143b27a40 = key;
    generateDecryptMask(key);
}

// Register or replace the decoder interfaces associated with a codec id.
// @0x14002e6e0
void criMvPly_AttachCodec(const CriMvCodecRegistrationEntry* registration)
{
    // The exe scans the whole table (no break) and keeps a flag for a new entry.
    CriUint16 index = DAT_143b2794c;
    CriSint32 added = 1;
    CriUint16 i;
    for (i = 0; i < DAT_143b2794c; ++i)
    {
        if (((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].CodecId == registration->CodecId)
        {
            index = i;
            added = 0;
        }
    }
    ((CriMvCodecRegistrationEntry*)DAT_143b27950)[index].CodecId = registration->CodecId;
    ((CriMvCodecRegistrationEntry*)DAT_143b27950)[index].VideoDecoderInterface = registration->VideoDecoderInterface;
    ((CriMvCodecRegistrationEntry*)DAT_143b27950)[index].AlphaDecoderInterface = registration->AlphaDecoderInterface;
    if (added == 1)
        ++DAT_143b2794c;
}

// Parse an MFS:<hex-address>.<hex-size> memory-file path into its two values.
// @0x1400389f0
CriBool FUN_1400389f0(void* reader, const char* path, CriUint64* size, CriUint64* offset)
{
    // As in the exe: no NULL checks, no length bound on either field, and an empty or
    // non-hex field parses as whatever _strtoui64 makes of it.
    // Typed buffers: the exe has no /GS cookie here. The names pick the exe's VC9 /Od stack slots
    // (work/vc9/p10/probe): tag, text, i.
    struct MfsPrefix { char c0, c1, c2, c3, c4; };
    struct MfsText { CriUint64 q[4]; };
    static const MfsPrefix kPrefix = { 'M', 'F', 'S', ':', 0 };
    MfsText text;
    MfsPrefix tag = kPrefix;
    CriUint32 i;
    for (i = 0; i < sizeof(tag) - 1; ++i)
    {
        if (!path[i] || path[i] != ((char*)&tag)[i])
            return 0;
    }
    memset(&text, 0, sizeof(text));
    for (CriSint32 n = 0; path[i] != '.'; ++n, ++i)
    {
        ((char*)&text)[n] = path[i];
        if (!path[i])
            return 0;
    }
    *size = FUN_140038bd0(reader, (char*)&text, NULL, 16);
    ++i;
    memset(&text, 0, sizeof(text));
    for (CriSint32 n = 0; path[i]; ++i, ++n)
        ((char*)&text)[n] = path[i];
    *offset = FUN_140038bd0(reader, (char*)&text, NULL, 16);
    return 1;
}

// Restore the CRI movie player defaults after allocating its working storage.
// @0x14002f850
void initializeHandleParameters(void* player)
{
    CriUint32 i;
    ((float*)player)[0x8bc / 4] = 1.0f;
    ((CriUint32*)player)[0x8c4 / 4] = 0x4000;
    ((CriUint32*)player)[0x8c8 / 4] = 100;
    ((CriUint32*)player)[0xe30 / 4] = 0xffffffff;
    memset(((CriMvPlyHeaderAnalysisFields*)player)->CurrentHeader, 0, 0x5c0);
    for (i = 0; i < 2; ++i)
        ((CriMovieStreamSlotsView*)player)->Ring.Slots[i].Active = 0;
    *(CriUint16*)((CriUint8*)player + 0x5e8) = 1;
    ((CriUint32*)player)[0x5ec / 4] = 0;
    ((CriUint32*)player)[0x5f0 / 4] = 0;
    ((CriUint32*)player)[0x8cc / 4] = 3;
    for (i = 0; i < 0x40; ++i)
    {
        ((CriUint32*)player)[0x8d0 / 4] = 0xffffffff;
        ((CriUint32*)((CriUint8*)player + 0x8d4))[i] = 0x5a5a5a5a;
        ((CriUint32*)((CriUint8*)player + 0x9d4))[i] = 0x5a5a5a5a;
    }
    ((CriUint32*)player)[0xd64 / 4] = 0;
    ((CriUint32*)player)[0xf14 / 4] = 0;
    ((CriUint32*)player)[0xe58 / 4] = 0;
    ((CriUint32*)player)[0xe5c / 4] = 0;
    ((CriUint32*)player)[0xe60 / 4] = 0;
    ((CriUint32*)player)[0xe64 / 4] = 0;
    ((CriUint32*)player)[0xe68 / 4] = 0;
    ((CriUint32*)player)[0xe6c / 4] = 0;
    ((CriUint32*)player)[0xe70 / 4] = 0;
    ((CriUint32*)player)[0xe80 / 4] = 0;
    *(void**)((CriUint8*)player + 0xe78) = NULL;
    *(void**)((CriUint8*)player + 0xe88) = NULL;
    ((CriUint32*)player)[0xe90 / 4] = 0;
    ((CriUint32*)player)[0xe94 / 4] = 0;
    *(void**)((CriUint8*)player + 0xe98) = NULL;
    ((CriUint32*)player)[0xea0 / 4] = 0;
    ((CriUint32*)player)[0xea4 / 4] = 0;
    *(void**)((CriUint8*)player + 0xea8) = NULL;
    ((CriUint32*)player)[0xeb0 / 4] = 0;
    ((CriUint32*)player)[0xec8 / 4] = 0;
    ((CriUint32*)player)[0xecc / 4] = 0;
    ((CriUint32*)player)[0xed0 / 4] = 0;
    ((float*)player)[0xed4 / 4] = 0.8f;
    *(CriUint64*)((CriUint8*)player + 0xee0) = 0;
    *(CriUint64*)((CriUint8*)player + 0xee8) = 0;
    *(CriUint64*)((CriUint8*)player + 0xef0) = 0;
    *(CriUint64*)((CriUint8*)player + 0xef8) = 0;
    *(CriUint64*)((CriUint8*)player + 0xf00) = 0;
    *(CriUint64*)((CriUint8*)player + 0xf08) = 0;
    ((CriUint32*)player)[0xed8 / 4] = 0xffffffff;
    *(CriUint8*)((CriUint8*)player + 0xf10) = 0;
}

#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Initialize CRI Movie on the first reference and maintain its process reference count.
// @0x14002e7d0
void criMvPly_Initialize(void)
{
    DAT_143b27940 = "\ncriMvPly/PCx64 Ver.3.07.01 Build:Jan 20 2012 18:13:29\n";
    if (DAT_143ffd500 == 0)
    {
        CriSint32 i;
        memset(&DAT_143ffd500, 0, 0x58);
        criUsfDmx_Initialize();
        criAtomic_Initialize();
        for (i = 0; i < DAT_143b2794c; ++i)
        {
            criVdec_Initialize(((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].VideoDecoderInterface);
            criAlphaDec_Initialize(((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].AlphaDecoderInterface);
        }
        criMvPlyAmng_Initialize();
        DAT_143ffd550 = FUN_1400385c8(DAT_143ffd504, 0x48);
        if (!DAT_143ffd550)
            crimvply_occurFatalError(NULL, "E07020200M : Can't create critical section handle for library work.", 0);
    }
    ++DAT_143ffd500;
}

// Release CRI Movie subsystems and decoder registrations on the final reference.
// @0x14002e8c0
void criMvPly_Finalize(void)
{
    --DAT_143ffd500;
    if (DAT_143ffd500 == 0)
    {
        CriSint32 i;
        criMvPlyAmng_Finalize();
        for (i = 0; i < DAT_143b2794c; ++i)
        {
            criAlphaDec_Finalize(((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].AlphaDecoderInterface);
            criVdec_Finalize(((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].VideoDecoderInterface);
            ((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].CodecId = 0;
            ((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].VideoDecoderInterface = NULL;
            ((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].AlphaDecoderInterface = NULL;
        }
        DAT_143b2794c = 0;
        criAtomic_Finalize();
        criUsfDmx_Finalize();
        if (DAT_143ffd550 != NULL)
        {
            void* lock = DAT_143ffd550;
            criCs_Destroy((_RTL_CRITICAL_SECTION*)lock);
            DAT_143ffd550 = NULL;
        }
    }
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Find the registered video decoder interface, mapping codec zero to codec one.
// @0x140030b50
void* crimvply_findVdecIF(CriSint32 codecId)
{
    void* decoder = NULL;
    CriSint32 i;
    if (codecId == 0)
        codecId = 1;
    for (i = 0; i < DAT_143b2794c; ++i)
    {
        if (((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].CodecId == codecId)
        {
            decoder = ((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].VideoDecoderInterface;
            break;
        }
    }
    return decoder;
}

// Find the registered alpha decoder interface, mapping codec zero to codec one.
// @0x140030be0
void* crimvply_findAlphadecIfIF(CriSint32 codecId)
{
    void* result = NULL;
    CriSint32 i;
    if (codecId == 0)
        codecId = 1;
    for (i = 0; i < DAT_143b2794c; ++i)
    {
        if (((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].CodecId == codecId)
        {
            result = ((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].AlphaDecoderInterface;
            break;
        }
    }
    return result;
}

// Service subtitles, header preparation, frame queues and audio for active players.
// @0x14002fb70
void criMvPly_Update(void* player)
{
    CriSint32 status = getInternalStatus(player);
    if (status == 0 || status == 9 || status == 7 || status == 6)
        return;
    executeSubtitleServer(player);
    executeHeaderServer(player);
    executeDiscardFrameServer(player);
    updateInputBufferInfo(player);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Report whether a default USM decryption key has been configured.
// @0x140037a10
CriBool criMvPly_IsSetDefaultDecryptionKey(void)
{
    return DAT_143b27a40 == NULL ? 0 : 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Lock the player handle, apply its pending start transition, then unlock it.
// @0x140031100
void FUN_140031100(void* player)
{
    enterHandleCs(player);
    crimvply_IncrementStateInCs(player);
    leaveHandleCs(player);
}

// Parse sample rate, channel count, sample count, and buffer size from an audio header.
// @0x140032a70
extern "C" void retrieveAudioHeader(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    CriUint32 suggestedSize4;
    void* document = criUtfRtv_Create(((CriMvPlyObj*)player)->utf_heap, (void*)parsed->Data, parsed->Size);
    output[0] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "sampling_rate");
    output[1] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "num_channels");
    output[2] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "total_samples");
    output[3] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "ixsize");
    suggestedSize4 = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "ixsize\0");   // the same name; the exe keeps a second copy (0x143a47288)
    if (suggestedSize4 > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = suggestedSize4;
    criUtfRtv_Destroy((CriUint64*)document);
}

// parse channel and time-base metadata for a CRI Movie stream record.
// @0x140032b70
extern "C" void retrieveSubtitleHeader(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = criUtfRtv_Create(((CriMvPlyObj*)player)->utf_heap, (void*)parsed->Data, parsed->Size);
    output[1] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "num_channels");
    ((CriUint64*)output)[1] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "time_unit");
    output[4] = 0x400;
    CriUint32 ixsize = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "ixsize");
    if (ixsize > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = ixsize;
    if (output[1] > 0 && ((CriUint64*)output)[1] > 0 && output[4] > 0)
        output[0] = 1;
    criUtfRtv_Destroy((CriUint64*)document);
}

// parse the cue metadata header and raise the required working-buffer size.
// @0x140032c70
extern "C" void retrieveCuePointHeader(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = criUtfRtv_Create(((CriMvPlyObj*)player)->utf_heap, (void*)parsed->Data, parsed->Size);
    output[1] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "metadata_count");
    output[2] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "metadata_size");
    output[3] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "total_points");
    ((CriUint64*)output)[2] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "time_unit");
    CriUint32 ixsize = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "ixsize");
    if (ixsize > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = ixsize;
    if (output[1] == 1 && output[2] > 0 && output[3] > 0 && ((CriUint64*)output)[2] > 0)
        output[0] = 1;
    criUtfRtv_Destroy((CriUint64*)document);
}

// parse video dimensions, timing, codec, alpha, and metadata information.
// @0x140032db0
void FUN_140032db0(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = criUtfRtv_Create(((CriMvPlyObj*)player)->utf_heap, (void*)parsed->Data, parsed->Size);
    CriUint32 rateNum = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "framerate_n");
    CriUint32 rateDenom = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "framerate_d");
    output[4] = (CriUint32)(((float)rateNum * 1000.0f) / (float)rateDenom);
    output[5] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "total_frames");
    output[0] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "width");
    output[1] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "height");
    CriUint32 ixsize = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "ixsize");
    if (ixsize > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = ixsize;
    if ((CriSint32)criUtfRtv_ConvFieldNameToNo((const CriUtfRtvView*)document, "pre_padding") > 0)
        output[10] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "pre_padding\0");   // the exe obj has its own copy of the literal
    else
        output[10] = 0x40;
    output[6] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "alpha_type");
    output[7] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "mpeg_codec");
    output[8] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "metadata_count");
    output[9] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "metadata_size");
    output[2] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "disp_width");
    if (output[2] == 0)
        output[2] = output[0];
    output[3] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, "disp_height");
    if (output[3] == 0)
        output[3] = output[1];
    criUtfRtv_Destroy((CriUint64*)document);
}
#pragma optimize("", on)


#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// parse one indexed CRI stream record and update its pending-record count.
// @0x140033d70
CriBool FUN_140033d70(void* player, const CriMovieInputChunk* input, CriUint8 outputIndex)
{
    CriUint32* output;
    CriMovieParsedChunk parsed;
    CriMovieStreamSlotsView* state = (CriMovieStreamSlotsView*)player;
    CriMovieStreamSlotView* slot = &state->Ring.Slots[state->Selector.Current];
    if (!slot->Active)
        return 0;
    else if (input->Size >= 0x20)
    {
        parsed.Data = criUsfCmn_GetContents(input->Data, input->Size, &parsed.Size);
        output = (CriUint32*)((CriUint8*)slot + 0x50 + (size_t)outputIndex * 0x10);
        retrieveAudioHeader(state, slot, output, &parsed);
        --slot->Reserved2C4;
        prepareNextHeaderIfCompleted(state, slot);
    }
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Compare video stream information and, when enabled, every plane's size pair.
// @0x140033ff0
CriBool FUN_140033ff0(void* player, const void* leftValue, const void* rightValue)
{
    struct PlaneInfo { CriSint32 First; CriSint32 Second; CriUint8 Reserved[8]; };
    struct StreamInfo
    {
        CriUint8 Reserved0[0x14];
        CriSint32 Field14;
        CriSint32 Field18;
        CriUint8 Reserved1C[8];
        CriSint32 Field24;
        CriUint8 Reserved28[0x24];
        CriUint32 PlaneCount;   // 0x4c
        PlaneInfo Planes[8];    // 0x50
    };
    struct CompareModeView { CriUint8 Reserved[0xb28]; CriSint32 Mode; };
    if (((const StreamInfo*)leftValue)->Field18 != ((const StreamInfo*)rightValue)->Field18 || ((const StreamInfo*)leftValue)->Field14 != ((const StreamInfo*)rightValue)->Field14 ||
        ((const StreamInfo*)leftValue)->Field24 != ((const StreamInfo*)rightValue)->Field24)
        return 0;
    if (((CompareModeView*)player)->Mode >= 0)
    {
        if (((const StreamInfo*)leftValue)->PlaneCount != ((const StreamInfo*)rightValue)->PlaneCount)
            return 0;
        for (CriUint32 i = 0; i < ((const StreamInfo*)leftValue)->PlaneCount; ++i)
        {
            if (((const StreamInfo*)leftValue)->Planes[i].First != ((const StreamInfo*)rightValue)->Planes[i].First ||
                ((const StreamInfo*)leftValue)->Planes[i].Second != ((const StreamInfo*)rightValue)->Planes[i].Second)
                return 0;
        }
    }
    return 1;
}

// Finish a stream slot once all its metadata records have arrived and rotate buffers.
// @0x140033e60
void prepareNextHeaderIfCompleted(void* player, CriMovieStreamSlotView* slot)
{
    struct RotationGateView { CriUint8 Reserved[0xb28]; CriSint32 BufferCount; };
    struct StreamCounterView { CriUint8 Reserved[0x5ec]; CriUint32 Count; };
    if (slot->PendingPrimary != 0 || slot->PendingSubtitle != 0 ||
        slot->PendingAlpha != 0 || slot->PendingAuxiliary != 0)
        return;
    if (((RotationGateView*)player)->BufferCount >= 0 && slot->Reserved2C4 != 0)
        return;
    // the other slot of the two-slot ring: its data offset plus its primary data size (+0x58)
    slot->NextDataOffset = ((CriMovieStreamSlotsView*)player)->Ring.Slots[(((CriMovieStreamSlotsView*)player)->Selector.Current + 1) % 2].NextDataOffset;
    slot->NextDataOffset += *(CriUint32*)(((CriMovieStreamSlotsView*)player)->Ring.Slots[(((CriMovieStreamSlotsView*)player)->Selector.Current + 1) % 2].PrimaryOutput + 0x44);
    if (!FUN_140033ff0(player, ((CriMvPlyHeaderAnalysisFields*)player)->AnalyzedHeader, slot))
        crimvply_occurUserError(player, "E07092101M: Entried movie file can not be concatenated with playing file.", 0);
    slot->Active = 0;
    ((CriMovieStreamSlotsView*)player)->Selector.Current++;
    ((CriMovieStreamSlotsView*)player)->Selector.Current %= 2;
    ((StreamCounterView*)player)->Count++;
}
#pragma optimize("", on)

// Column names of the video header, as {current, legacy} pairs (exe 0x143a47150). A header without "mpeg_codec" but
// with "fps_cyc" is the legacy layout and is read through the second name of each pair.
static const CriChar8* s_apszVideoHeaderColumns[16][2] = {
    {"mpeg_codec", "fps_cyc"},         {"framerate_n", "fps_cyc"},       {"framerate_d", "fps_int"},
    {"total_frames", "pic_num"},       {"width", "pxl_ew"},              {"height", "pxl_eh"},
    {"ixsize", "pic_max"},             {"pre_padding", "pre_padding"},   {"mat_width", "pxl_dw"},
    {"mat_height", "pxl_dh"},          {"scrn_width", "scrn_width"},     {"mpeg_dcprec", "mpeg_dcprec"},
    {"metadata_count", "metadata_count"}, {"metadata_size", "metadata_size"}, {"disp_width", "pxl_dw"},
    {"disp_height", "pxl_dh"},
};

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// parse MPEG and legacy video metadata fields into the stream record.
// @0x140032650
void FUN_140032650(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = criUtfRtv_Create(((CriMvPlyObj*)player)->utf_heap, (void*)parsed->Data, parsed->Size);
    CriUint32 nLayout;
    if ((CriSint32)criUtfRtv_ConvFieldNameToNo((const CriUtfRtvView*)document, s_apszVideoHeaderColumns[0][0]) > 0)
    {
        output[9] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[0][0]);
        nLayout = 0;
    }
    else if ((CriSint32)criUtfRtv_ConvFieldNameToNo((const CriUtfRtvView*)document, s_apszVideoHeaderColumns[0][1]) > 0)
    {
        output[9] = 3;
        nLayout = 1;
    }
    else
    {
        output[9] = 0;
        nLayout = 0;
    }

    CriUint32 fpsNum = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[1][nLayout]);
    CriUint32 fpsDenom = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[2][nLayout]);
    output[4] = (CriUint32)(((float)fpsNum * 1000.0f) / (float)fpsDenom);
    output[5] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[3][nLayout]);
    output[0] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[4][nLayout]);
    output[1] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[5][nLayout]);
    CriUint32 ixsize = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[6][nLayout]);
    if (ixsize > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = ixsize;
    if ((CriSint32)criUtfRtv_ConvFieldNameToNo((const CriUtfRtvView*)document, s_apszVideoHeaderColumns[7][nLayout]) > 0)
        output[13] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[7][nLayout]);
    else
        output[13] = 0x40;
    output[6] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[8][nLayout]);
    if (output[6] == 0)
        output[6] = output[0];
    output[7] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[9][nLayout]);
    if (output[7] == 0)
        output[7] = output[1];
    output[8] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[10][nLayout]);
    output[10] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[11][nLayout]);
    output[11] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[12][nLayout]);
    output[12] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[13][nLayout]);
    output[2] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[14][nLayout]);
    if (output[2] == 0)
        output[2] = output[0];
    output[3] = FID_conflict_criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, 0, s_apszVideoHeaderColumns[15][nLayout]);
    if (output[3] == 0)
        output[3] = output[1];
    criUtfRtv_Destroy((CriUint64*)document);
}

// select the last seek-table entry whose frame id does not exceed the requested frame.
// @0x140033700
void criMvPly_CalcSeekPosition(void* player, const void* data, CriUint32 size, CriSint32 targetFrame,
                   void** outputData, CriSint32* outputFrame)
{
    CriSint32 current;
    CriSint32 count;
    void* document;
    CriSint32 frameId;
    CriSint32 entry = 0;
    void* out = NULL;
    document = criUtfRtv_Create(((CriMvPlyObj*)player)->utf_heap, (void*)data, size);
    count = criUtfRtv_GetNumRecord((const CriUtfRtvView*)document);
    for (current = 0; current < count; current++)
    {
        frameId = criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, current, "ofs_frmid");
        if (targetFrame >= frameId)
        {
            entry = current;
            out = (void*)criUtfRtv_GetDataUint64((const CriUtfRtvView*)document, current, 0);
        }
        else
            break;
    }
    *outputData = out;
    *outputFrame = criUtfRtv_GetDataSint32Fn((const CriUtfRtvView*)document, entry, "ofs_frmid\0");   // the exe keeps a second copy (0x143a47438)
    criUtfRtv_Destroy((CriUint64*)document);
}

// allocate and initialize the metadata stream using either the caller or CRI heap.
// @0x140031c40
CriBool allocateMetaSjiInCs(void* player, void* heap, CriUint32 size, CriUint32 alignment)
{
    struct MetaConfig
    {
        CriUint32 Mode;
        CriUint32 Size;
        CriUint32 Reserved8;
        CriUint32 Alignment;
        CriUint64 Reserved10;
    };
    struct MetadataView
    {
        CriUint8 Reserved0[0xe78];
        void* Stream;
        CriUint8 ReservedE80[0x68];
        void* (*Allocate)(void*, CriSint32);
        CriUint8 ReservedEF0[8];
        void* Context;
        void* Allocation;
    };
    CriSint32 workSize;
    void* allocation;
    MetaConfig param;
    if (heap)
    {
        ((MetadataView*)player)->Stream = criSj_CreateNamedRingBuffer(heap, (CriSint32)size, 0, (CriSint32)alignment,
                                      (CriUint64)"CriMvPly: MetaInput");
        if (!((MetadataView*)player)->Stream)
        {
            crimvply_occurUserError(player, "E08120201M : Can't create meta SJ.", 0);
            return 0;
        }
    }
    else
    {
        memset(&param, 0, sizeof(param));
        param.Mode = 1;
        param.Reserved10 = 0;
        param.Size = size;
        param.Reserved8 = 0;
        param.Alignment = alignment;
        workSize = criSjRbf_CalculateWorkSize((const CriSint32*)&param);
        allocation = ((MetadataView*)player)->Allocate(((MetadataView*)player)->Context, workSize);
        if (!allocation)
        {
            crimvply_occurUserError(player, "E10052103M : NULL pointer is paased from the MetaWorkCallback by app.", 0);
            return 0;
        }
        ((MetadataView*)player)->Stream = criSjRbf_Create(&param, allocation, workSize);
        ((MetadataView*)player)->Allocation = allocation;
    }
    return 1;
}

// allocate the cue-point event table from the selected heap and clear all records.
// @0x140031da0
CriBool allocateMetaCueTableInCs(void* player, void* heap)
{
    struct EventConfigView
    {
        CriUint8 Reserved0[0x898];
        CriUint32 Enabled;
        CriUint8 Reserved89C[0x8ac - 0x89c];
        CriUint32 Count;
        CriUint8 Reserved8B0[0xde8 - 0x8b0];
        void* Heap;
        CriUint8 ReservedDF0[0xec0 - 0xdf0];
        void* Table;
        CriUint8 ReservedEC8[0x40];
        void* ReleaseTable;
    };
    CriUint32 size;
    void* allocation;
    if (((EventConfigView*)player)->Enabled <= 0)
    {
        ((EventConfigView*)player)->Table = NULL;
        return 1;
    }

    if (heap)
    {
        ((EventConfigView*)player)->Table = criHeap_AllocFix((CriHeap)((EventConfigView*)player)->Heap,
                                     (CriSint32)(((EventConfigView*)player)->Count * (size_t)0x38),
                                     "CriMvPly: EventTable", 4);
    }
    else
    {
        struct AllocatorView
        {
            CriUint8 Reserved0[0xee8];
            void* (*Allocate)(void*, CriUint32);
            CriUint8 ReservedEF0[8];
            void* Context;
        };
        size = (CriUint32)(((EventConfigView*)player)->Count * (size_t)0x38 + 4);
        allocation = ((AllocatorView*)player)->Allocate(((AllocatorView*)player)->Context, size);
        if (!allocation)
        {
            crimvply_occurUserError(player, "E10052103M : NULL pointer is paased from the MetaWorkCallback by app.", 0);
            return 0;
        }
        ((EventConfigView*)player)->Table = allocation;
        ((EventConfigView*)player)->ReleaseTable = allocation;
    }
    if (!((EventConfigView*)player)->Table)
    {
        crimvply_occurUserError(player, "E09011601M : Can't allocate EventTable Memory.", 0);
        return 0;
    }
    memset(((EventConfigView*)player)->Table, 0, (size_t)((EventConfigView*)player)->Count * 0x38);
    return 1;
}

// size and allocate the CRI Movie metadata and event work areas.
// @0x140031ae0
CriBool allocateMetaWorkInCs(void* player)
{
    struct BaseSizeView { CriUint8 Reserved[0x63c]; CriSint32 Size; };
    struct FeatureSizeA { CriUint8 Reserved[0x868]; CriUint32 Enabled; };
    struct FeatureBytesA { CriUint8 Reserved[0x890]; CriSint32 Size; };
    struct FeatureSizeB { CriUint8 Reserved[0x898]; CriUint32 Enabled; };
    struct FeatureBytesB { CriUint8 Reserved[0x8a8]; CriSint32 Size; };
    struct WorkSizeView { CriUint8 Reserved[0xe74]; CriSint32 Size; };
    struct WorkHeapView { CriUint8 Reserved[0xde8]; void* Heap; };
    struct QueueView { CriUint8 Reserved[0xd78]; void* Input; void* Read; };
    struct MetaStreamView { CriUint8 Reserved[0xe78]; void* Stream; };
    CriSint32 queued;
    if (((MetaStreamView*)player)->Stream)
        freeMetaWork(player);

    ((WorkSizeView*)player)->Size = ((BaseSizeView*)player)->Size + 0x800;
    if (((FeatureSizeA*)player)->Enabled > 0)
        ((WorkSizeView*)player)->Size += ((FeatureBytesA*)player)->Size;
    if (((FeatureSizeB*)player)->Enabled > 0)
        ((WorkSizeView*)player)->Size += ((FeatureBytesB*)player)->Size;
    queued = FUN_1400467b8(((QueueView*)player)->Read, 1) +
             FUN_1400467b8(((QueueView*)player)->Input, 1);
    if (((WorkSizeView*)player)->Size < queued)
        ((WorkSizeView*)player)->Size = queued;

    if (!allocateMetaSjiInCs(player, ((WorkHeapView*)player)->Heap, (CriUint32)((WorkSizeView*)player)->Size, 0x40))
        return 0;
    if (!allocateMetaCueTableInCs(player, ((WorkHeapView*)player)->Heap))
    {
        freeMetaWork(player);
        return 0;
    }
    return 1;
}

// refresh the player's pending byte counts from the selected input stream.
// @0x140034c20
void updateInputBufferInfo(void* player)
{
    struct ReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; };
    struct InputStatsView { CriUint8 Reserved[0xec8]; CriSint32 Available; CriSint32 Remaining; CriSint32 Mode; };
    struct ReadProgressView
    {
        CriUint8 Reserved0[0xd98];
        CriSint32 BufferedBytes;
        CriUint8 ReservedDC[0xdb0 - 0xd9c];
        CriSint32 StreamBytes;
    };
    ((InputStatsView*)player)->Available = 0;
    ((InputStatsView*)player)->Remaining = 0;
    ((InputStatsView*)player)->Mode = 0;
    // criMvPly_GetInputSj always writes both counts
    CriSint32 playStatus = getInternalStatus(player);
    switch (playStatus)
    {
    case 0:
    case 1:
        return;
    }
    CriUint32 dataSize;
    CriUint32 limit;
    void* source = criMvPly_GetInputSj(player, &dataSize, &limit);
    if (!source)
        return;
    CriSint32 leftBytes;
    if (((ReadModeView*)player)->Mode == 1)
        leftBytes = ((ReadProgressView*)player)->StreamBytes - FUN_1400467b8(source, 0);
    else
        leftBytes = dataSize - FUN_1400467b8(source, 0) - ((ReadProgressView*)player)->BufferedBytes;
    ((InputStatsView*)player)->Available = dataSize;
    ((InputStatsView*)player)->Remaining = leftBytes;
    ((InputStatsView*)player)->Mode = limit;
}

// return a partially consumed input chunk to its source queue after playback uses it.
// @0x140034e70
void criMvPly_PutInputChunk(void* player, const CriMovieInputChunk* input, CriUint32 maximum)
{
    struct ReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; };
    CriMovieInputChunk* current;
    CriMovieInputChunk leftChunk;
    CriSint32 status;
    void* source;
    if (((ReadModeView*)player)->Mode == 1)
        return;
    if (!input->Data || input->Size == 0)
        return;
    status = getInternalStatus(player);
    switch (status)
    {
    case 0:
    case 2:
    case 8:
        current = (CriMovieInputChunk*)((CriUint8*)player + 0xd90);
        current->Data = NULL;
        current->Size = 0;
        return;
    }

    source = criMvPly_GetInputSj(player, NULL, NULL);
    if (!source)
    {
        crimvply_occurUserError(player, "E05063026M : Can't exec criMvPly_PutInputChunk() before AllocateWorkBuffer.", 0);
        return;
    }
    if (input->Size == 0)
        return;
    current = (CriMovieInputChunk*)((CriUint8*)player + 0xd90);
    if (current->Data != input->Data || current->Size != input->Size)
    {
        crimvply_occurUserError(player, "E05063027M : Chunk is not same to one by criMvPly_GetInputChunk().",
                      (CriSint32)(uintptr_t)input->Data);
        return;
    }

    criSj_SplitChunk(current, maximum, current, &leftChunk);
    criSj_UngetChunk(source, 0, &leftChunk);
    criSj_PutChunk(source, 1, current);
    current->Data = NULL;
    current->Size = 0;
}

// Discard handled command chunks while returning ordinary input records to the stream.
// @0x140033610
void discardMetaData(void* player)
{
    struct ChunkView { void* Data; CriUint32 Size; };
    // the parsed USF chunk header (0x24 bytes); no byte array, so /GS adds no cookie, as in the exe
    struct UsfChunkHeader { CriUint32 Words[9]; };   // byte 0xf is the chunk type
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): p, length, work, chunk, header.
    const CriUint8* p;
    CriSint32 length;
    void* work;
    ChunkView chunk;
    UsfChunkHeader header;
    work = ((CriMvPlyInputQueueFields*)player)->ReadBuffer;
    while ((CriUint32)FUN_1400467b8(work, 1) > 0)
    {
        criSj_GetChunk(work, 1, -1, &chunk);
        if (chunk.Size >= 0x20)
        {
            criUsfCmn_ParseUsfHeaderStd((const CriUint8*)chunk.Data, chunk.Size, (CriUsfStandardHeader*)(&header));
            p = criUsfCmn_GetContents((const CriUint8*)chunk.Data, chunk.Size, &length);
            if (((CriUint8*)&header)[0xf] != 2 && ((CriUint8*)&header)[0xf] != 3)
            {
                criSj_UngetChunk(work, 1, &chunk);
                break;
            }
            criSj_PutChunk(work, 2, &chunk);
        }
        else
        {
            criSj_UngetChunk(work, 1, &chunk);
            break;
        }
    }
}

// Release the player's output stream, decoder work area, and callback-owned buffers.
// @0x140031f40
CriBool freeMetaWorkInCs(void* player)
{
    struct CleanupView
    {
        CriUint8 Reserved0[0xde8];
        void* Heap;
        CriUint8 ReservedDF0[0xe78 - 0xdf0];
        void* StreamJoint;
        CriUint8 ReservedE80[0xec0 - 0xe80];
        void* Work;
        CriUint8 ReservedEC8[0xef0 - 0xec8];
        void (*Release)(void*, void*);
        void* ReleaseContext;
        void* CallbackBuffer;
        void* WorkReleaseBuffer;
    };
    if (((CleanupView*)player)->StreamJoint)
    {
        criSj_Destroy(((CleanupView*)player)->StreamJoint);
        ((CleanupView*)player)->StreamJoint = NULL;
        if (((CleanupView*)player)->CallbackBuffer)
            ((CleanupView*)player)->Release(((CleanupView*)player)->ReleaseContext, ((CleanupView*)player)->CallbackBuffer);
    }
    if (((CleanupView*)player)->Work)
    {
        if (((CleanupView*)player)->WorkReleaseBuffer)
            ((CleanupView*)player)->Release(((CleanupView*)player)->ReleaseContext, ((CleanupView*)player)->WorkReleaseBuffer);
        else if (((CleanupView*)player)->Heap)
            criHeap_Free((CriHeap)((CleanupView*)player)->Heap, ((CleanupView*)player)->Work);
        ((CleanupView*)player)->Work = NULL;
    }
    return 1;
}

// Reset a stopped CRI Movie player and reinitialize its demux output stream.
// @0x140034960
CriBool crimvply_StartInCs(void* player)
{
    struct PlayerResetHeader
    {
        CriUint8 Data[0x2c0];
        CriUint32 Size;
        CriUint8 Reserved2C4[0x1c];
    };
    struct PlayerResetView
    {
        CriUint8 Reserved0[4];
        CriSint32 Status;
        CriUint32 InternalFlags;
        CriSint32 OpenLock;
        CriUint32 ResetTimer;
        CriUint8 Reserved14[0x14];
        PlayerResetHeader Headers[2];
        CriUint16 CurrentSlot;
        CriUint8 Reserved5EA[2];
        CriUint32 SlotCount;
        CriUint32 FrameCount;
        CriUint8 Reserved5F4[4];
        CriUint8 AnalyzedHeader[0x2c0];
        CriUint32 HeaderSize;
        CriUint8 Reserved8BC[0xd60 - 0x8bc];
        CriUint32 ReadMode;
        CriUint8 ReservedD64[4];
        void* Demux;
        CriUint8 ReservedD70[8];
        void* InputStream;
        void* OutputStream;
        CriUint8 ReservedD88[0x140];
        CriUint32 InputCount0;
        CriUint32 InputCount1;
        CriUint32 InputCount2;
    };
    // the exe reads the demux before the NULL check
    void* demux = ((PlayerResetView*)player)->Demux;
    if (!player)
    {
        crimvply_occurUserError(player, "E05121601M : CriMvPly handle is NULL.", 0);
        return 0;
    }
    if (((PlayerResetView*)player)->Status != 0 && ((PlayerResetView*)player)->Status != 7)
    {
        crimvply_occurUserError(player, "E05121602M : Can't execute start function when CriMvPly handle status is not STOP/PLAYEND.",
                      ((PlayerResetView*)player)->Status);
        return 0;
    }
    ((PlayerResetView*)player)->ResetTimer = 0;
    ((PlayerResetView*)player)->HeaderSize = 0;
    memset(((PlayerResetView*)player)->AnalyzedHeader, 0, sizeof(((PlayerResetView*)player)->AnalyzedHeader));
    ((PlayerResetView*)player)->ReadMode = 0;
    criUsfDmx_SetInputSj(demux, ((PlayerResetView*)player)->InputStream);
    criUsfDmx_SetOutputSj(demux, 0, ((PlayerResetView*)player)->OutputStream, 0, (CriUint32)-1);
    criUsfDmx_SetThrououtSwitch(demux, 0);
    criUsfDmx_Start(demux);
    memset(((PlayerResetView*)player)->Headers, 0, sizeof(((PlayerResetView*)player)->Headers));
    ((PlayerResetView*)player)->Headers[0].Size = 0;
    ((PlayerResetView*)player)->Headers[1].Size = 0;
    ((PlayerResetView*)player)->CurrentSlot = 1;
    ((PlayerResetView*)player)->SlotCount = 0;
    ((PlayerResetView*)player)->FrameCount = 0;
    ((PlayerResetView*)player)->InputCount0 = 0;
    ((PlayerResetView*)player)->InputCount1 = 0;
    ((PlayerResetView*)player)->InputCount2 = 0;
    ((PlayerResetView*)player)->OpenLock = 0;
    ((PlayerResetView*)player)->Status = 1;
    return 1;
}

// Drive the file-open metadata phase until the demux is prepared for playback.
// @0x1400317b0
void executeMvPlyDechdrServer(void* player)
{
    struct LockView { CriUint8 Reserved[0x0c]; CriSint32 Value; };
    struct OpenPhaseView { CriUint8 Reserved[0xe70]; CriSint32 Phase; };
    struct MetaHeapView { CriUint8 Reserved[0xde8]; void* Heap; };
    struct AllocatorView { CriUint8 Reserved[0xee8]; void* Allocate; };
    struct InputReadyView { CriUint8 Reserved[0x638]; CriSint32 Ready; };
    ((LockView*)player)->Value = 1;
    if (isLockedInputChunk(player) == 1)
        return;
    switch (((OpenPhaseView*)player)->Phase)
    {
    case 0:
        if (executeDecHdrStageAnalizeHeader(player) != 1)
            break;
        if (((MetaHeapView*)player)->Heap == NULL && ((AllocatorView*)player)->Allocate == NULL)
        {
            ((InputReadyView*)player)->Ready = 0;
            discardMetaData(player);
        }
        if ((CriUint32)((InputReadyView*)player)->Ready > 0)
            ((OpenPhaseView*)player)->Phase = 1;
        else
        {
            ((OpenPhaseView*)player)->Phase = 3;
            ((CriMvPlyStateTransitionFields*)player)->Status = 2;
            break;
        }
        // fall through
    case 1:
        if (FUN_140031990(player) != 1)
            break;
        ((OpenPhaseView*)player)->Phase = 2;
        // fall through
    case 2:
        if (executeDecHdrStageMetaGet(player) == 1)
            ((CriMvPlyStateTransitionFields*)player)->Status = 2;
        break;
    }
    ((LockView*)player)->Value = 0;
}

// advance a completed video decoder (and its alpha decoder) through the metadata and stop phases
// @0x1400344f0
extern "C" void executeMvPlyPlayingServer(void* player)
{
    if (((CriMvDecoderHandleFields*)player)->VideoDecoder)
    {
        if (criVdec_GetStatus(((CriMvDecoderHandleFields*)player)->VideoDecoder) != 3)
            return;
        if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        {
            flushAlphaFrame(player);
            if (criAlphaDec_GetStatus(((CriMvDecoderHandleFields*)player)->AlphaDecoder) != 3)
            {
                ((CriMvPlyStateTransitionFields*)player)->StopState = 2;
                return;
            }
        }
    }

    if (criMvPlyAmng_IsEndAudioPlayback(((CriMvDecoderHandleFields*)player)->AudioManager, player) != 1)
    {
        ((CriMvPlyStateTransitionFields*)player)->StopState = 4;
        return;
    }
    if (isLockedInputChunk(player) == 1)
        ((CriMvPlyStateTransitionFields*)player)->StopState = 3;
    else
    {
        resetHandle(player);
        ((CriMvPlyStateTransitionFields*)player)->Status = 6;
        ((CriMvPlyStateTransitionFields*)player)->StopState = 5;
    }
}

// Copy the selected analyzed-header or input-buffer remainder into the read queue.
// @0x1400342b0
void copyDataFromHeadAnalyToReadBuffer(void* player)
{
    void* source;
    if (((CriMvPlyInputQueueFields*)player)->PendingData > 0)
        return;
    if ((CriUint32)((CriMvPlyObj*)player)->seekinfo_flag > 0)
        source = ((CriMvPlyInputQueueFields*)player)->HeaderBuffer;
    else
        source = ((CriMvPlyInputQueueFields*)player)->InputBuffer;
    FUN_140034330(player, source, ((CriMvPlyInputQueueFields*)player)->ReadBuffer, ((CriMvPlyInputQueueFields*)player)->DataQueue);
}

// Reset the player's demux, streams, audio manager, and seek metadata for a new open.
// Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): read, chunk, queue.
// @0x140031570
extern "C" void resetHandle(void* player)
{
    struct ResetView
    {
        CriUint8 Reserved0[0xd60];
        CriSint32 ReadMode;                 // 0xd60
        CriUint32 HeaderChecked;            // 0xd64
        void* Demux;                        // 0xd68
        CriUint32 Reserved70;
        CriUint32 OutputCount;              // 0xd74
        void* InputBuffer;                  // 0xd78
        void* ReadBuffer;                   // 0xd80
        void* DataQueue;                    // 0xd88
        CriMovieInputChunk CurrentRead;     // 0xd90
        void* MemoryInput;                  // 0xda0
        CriUint8 Reservedda8[0xe10 - 0xda8];
        void* AudioManager;                 // 0xe10
        CriUint8 Reservede18[0xe58 - 0xe18];
        CriUint32 Counters[7];              // 0xe58
        CriUint8 Reservede74[0xe80 - 0xe74];
        CriUint32 MetaCount;                // 0xe80
        CriUint32 Reservede84;
        const CriUint8* SfvData;            // 0xe88
        CriSint32 SfvSize;                  // 0xe90
        CriUint32 SfvCount;                 // 0xe94
        const CriUint8* AlpData;            // 0xe98
        CriSint32 AlpSize;                  // 0xea0
        CriUint32 AlpCount;                 // 0xea4
        const CriUint8* CueData;            // 0xea8
        CriSint32 CueSize;                  // 0xeb0
        CriUint8 Reservedeb4[0xf14 - 0xeb4];
        CriUint32 DecoderError;             // 0xf14
    };
    void* queue;
    CriMovieInputChunk* chunk;
    void* read;
    ((ResetView*)player)->ReadMode = 0;
    if (((ResetView*)player)->AudioManager)
        criMvPlyAmng_Stop(((ResetView*)player)->AudioManager);
    if (((ResetView*)player)->Demux)
        criUsfDmx_Stop(((ResetView*)player)->Demux);
    criSj_Reset(((ResetView*)player)->InputBuffer);
    criSj_Reset(((ResetView*)player)->MemoryInput);
    queue = ((ResetView*)player)->DataQueue;
    if (queue)
        criSj_Reset(queue);
    read = ((ResetView*)player)->ReadBuffer;
    if (read)
        criSj_Reset(read);
    if (((ResetView*)player)->AudioManager)
        criMvPlyAmng_ResetAudioSj(((ResetView*)player)->AudioManager);
    chunk = &((ResetView*)player)->CurrentRead;
    chunk->Data = NULL;
    chunk->Size = 0;
    ((ResetView*)player)->HeaderChecked = 0;
    ((ResetView*)player)->OutputCount = 0;
    ((ResetView*)player)->DecoderError = 0;
    ((ResetView*)player)->Counters[0] = 0;
    ((ResetView*)player)->Counters[1] = 0;
    ((ResetView*)player)->Counters[2] = 0;
    ((ResetView*)player)->Counters[3] = 0;
    ((ResetView*)player)->Counters[4] = 0;
    ((ResetView*)player)->Counters[5] = 0;
    ((ResetView*)player)->Counters[6] = 0;
    ((ResetView*)player)->MetaCount = 0;
    ((ResetView*)player)->SfvData = NULL;
    ((ResetView*)player)->SfvSize = 0;
    ((ResetView*)player)->SfvCount = 0;
    ((ResetView*)player)->AlpData = NULL;
    ((ResetView*)player)->AlpSize = 0;
    ((ResetView*)player)->AlpCount = 0;
    ((ResetView*)player)->CueData = NULL;
    ((ResetView*)player)->CueSize = 0;
}

// perform the executable's pending start/stop state transition on the player.
// @0x140031140
void crimvply_IncrementStateInCs(void* player)
{
    // +0x0c is the open-phase read lock executeMvPlyDechdrServer sets; +0x08 (InternalFlags) is the stop request.
    struct OpenLockView { CriUint8 Reserved[0x0c]; CriSint32 Value; };
    CriSint32 status = getInternalStatus(player);
    switch (status)
    {
    case 2:
        if (((CriMvPlyStateTransitionFields*)player)->StartReady != 1)
        {
            crimvply_occurUserError(player, "E05063019M : Can't start movie without work buffer.", 0);
            break;
        }
        copyDataFromHeadAnalyToReadBuffer(player);
        criUsfDmx_Stop(((CriMvPlyStateTransitionFields*)player)->Demux);
        ((OpenLockView*)player)->Value = 0;
        ((CriMvPlyStateTransitionFields*)player)->Status = 3;
        break;
    case 4:
        ((CriMvPlyStateTransitionFields*)player)->Status = 5;
        break;
    case 6:
        ((CriMvPlyStateTransitionFields*)player)->LastFrame = -1;
        ((CriMvPlyStateTransitionFields*)player)->Status = 7;
        ((CriMvPlyStateTransitionFields*)player)->StopState = 0;
        break;
    case 9:
        ((CriMvPlyStateTransitionFields*)player)->LastFrame = -1;
        ((CriMvPlyStateTransitionFields*)player)->Status = 0;
        ((CriMvPlyStateTransitionFields*)player)->StopState = 0;
        break;
    }
}

// Run the CRI movie player once under its per-player critical section.
// @0x140031250
void criMvPly_Execute(void* player)
{
    enterHandleCs(player);
    FUN_140031290(player);
    leaveHandleCs(player);
}

// Invoke each configured decoder's frame-decode callback.
// @0x140031410
CriBool criMvPly_DecodeVideoInCs(void* player)
{
    if (!player)
        return 0;
    CriBool result = criVdec_DecodeFrame(((CriMvDecoderHandleFields*)player)->VideoDecoder);
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        criAlphaDec_DecodeFrame(((CriMvDecoderHandleFields*)player)->AlphaDecoder);
    return result;
}

// Ask the primary video decoder to skip its current frame.
// @0x1400314a0
void FUN_1400314a0(void* player)
{
    FUN_140044ae0(((CriMvDecoderHandleFields*)player)->VideoDecoder);
}

// Report whether both decoder backends have completed their stop processing.
// @0x1400314d0
extern "C" CriBool isEndStopProcessingProc(void* player)
{
    void* videoDecoder = ((CriMvDecoderHandleFields*)player)->VideoDecoder;
    void* alphaDecoder = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;   // after videoDecoder: same VC9 slot bucket
    CriBool result = 0;
    if (videoDecoder && criVdec_GetStatus(videoDecoder))
    {
        ((CriMvPlyStateTransitionFields*)player)->StopState = 1;
        return result;
    }
    if (alphaDecoder && criAlphaDec_GetStatus(alphaDecoder))
    {
        ((CriMvPlyStateTransitionFields*)player)->StopState = 2;
        return result;
    }
    result = 1;
    return result;
}

// Decode a video frame while holding the global CRI movie-player lock.
// @0x1400313d0
CriBool criMvPly_DecodeVideo(void* player)
{
    enterCriticalSection(player);
    CriBool result = criMvPly_DecodeVideoInCs(player);
    leaveCriticalSection(player);
    return result;
}

// Process a pending video-server frame and update decoder progress.
// @0x140031470
void criMvPly_DecodeHeader(void* player)
{
    executeUsfServer(player);
    executeMvPlyDechdrServer(player);
}

// Expose the next subtitle chunk only after the movie player leaves its setup states.
// @0x140036650
CriUint32 executeSubtitleServer(void* player)
{
    CriUint32 res = 0;
    CriMvSubtitleChunk subtitle;
    CriSint32 status;                        // declared after subtitle: same VC9 slot bucket, lower slot
    memset(&subtitle, 0, sizeof(subtitle));
    if (!player)
        return 0;
    if (!((CriMvSubtitleFields*)player)->Queue)
        return 0;
    status = getInternalStatus(player);
    if (status == 0 || status == 1 || status == 2 || status == 3 || status == 4)
        return 0;

    res = (CriUint32)FUN_140036b80(player, &subtitle, ((CriMvSubtitleFields*)player)->SubtitleChannel);
    ungetSubtitleChunk(player, &subtitle);
    return res;
}

// release decoded video and alpha frames up to the subtitle end frame count.
// @0x1400369e0
void executeDiscardFrameServer(void* player)
{
    struct AlphaFrame
    {
        CriUint8* imageptr;
        CriSint32 frame_id;     // +0x08
        CriUint32 width;
        CriUint32 height;
        CriUint32 Reserved14;
        CriUint64 Reserved18[7];
    };
    struct SubtitleEndState
    {
        CriUint8 Reserved[0xe58];
        CriSint32 Count;     // +0xe58
        CriSint32 Reserved2[2];
        CriSint32 VideoDone; // +0xe64
        CriSint32 AlphaDone; // +0xe68
    };
    AlphaFrame alpha;
    CriMvFrameInfo videoFrame;
    if (((SubtitleEndState*)player)->Count <= 0)
        return;
    if (((SubtitleEndState*)player)->VideoDone == 1 &&
        (((CriMvDecoderHandleFields*)player)->AlphaDecoder == NULL || ((SubtitleEndState*)player)->AlphaDone == 1))
        return;

    if (((SubtitleEndState*)player)->VideoDone != 1)
    {
        while (criVdec_GetNextFrameInfo(((CriMvDecoderHandleFields*)player)->VideoDecoder, &videoFrame))
        {
            if (videoFrame.frame_id >= ((SubtitleEndState*)player)->Count)
            {
                ((SubtitleEndState*)player)->VideoDone = 1;
                break;
            }
            else
            {
                criVdec_GetFramePointer(((CriMvDecoderHandleFields*)player)->VideoDecoder, &videoFrame);
                criVdec_ReleaseFramePointer(((CriMvDecoderHandleFields*)player)->VideoDecoder, &videoFrame);
            }
        }
    }

    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder != NULL && ((SubtitleEndState*)player)->AlphaDone != 1)
    {
        while (criAlphaDec_GetNextAlphaFrameInfo(((CriMvDecoderHandleFields*)player)->AlphaDecoder, &alpha))
        {
            if (alpha.frame_id >= ((SubtitleEndState*)player)->Count)
            {
                ((SubtitleEndState*)player)->AlphaDone = 1;
                return;
            }
            else
            {
                criAlphaDec_GetAlphaFramePointer(((CriMvDecoderHandleFields*)player)->AlphaDecoder, &alpha);
                criAlphaDec_ReleaseAlphaFramePointer((CriUint64*)((CriMvDecoderHandleFields*)player)->AlphaDecoder, &alpha);
            }
        }
    }
}

// Discard the player's pending subtitle chunk.
// @0x140036e30
extern "C" void releaseSubtitleChunk(void* player, CriMvSubtitleChunk* chunk)
{
    if (player == NULL)
        return;
    if (((CriMvSubtitleFields*)player)->Queue == NULL)
        return;
    criSj_PutChunk(((CriMvSubtitleFields*)player)->Queue, 0, chunk);
}

// Return a subtitle chunk to the head of the player's subtitle queue.
// @0x140036e80
extern "C" void ungetSubtitleChunk(void* player, CriMvSubtitleChunk* chunk)
{
    if (player == NULL)
        return;
    if (((CriMvSubtitleFields*)player)->Queue == NULL)
        return;
    criSj_UngetChunk(((CriMvSubtitleFields*)player)->Queue, 1, chunk);
}

// Release the main and current alpha frame held by the easy player.
// @0x140038fa0
CriSint32 FUN_140038fa0(void* easyPlayer, const CriMvFrameInfo* frameInfo, CriError* error)
{
    *error = CRIERR_OK;
    criMvPly_UnlockFrameBuffer(((CriMvEasyPlayerFrameFields*)easyPlayer)->PlayerHandle, frameInfo);
    if (*(CriUint64*)((CriMvEasyPlayerFrameFields*)easyPlayer)->AlphaFrameInfo)
        criMvPly_UnlockAlphaFrameBuffer(((CriMvEasyPlayerFrameFields*)easyPlayer)->PlayerHandle,
                      (const CriUint64*)((CriMvEasyPlayerFrameFields*)easyPlayer)->AlphaFrameInfo);
    return 1;
}

// Discard the next decoded frame and clear the current-frame bookkeeping.
// @0x140039110
CriSint32 FUN_140039110(void* easyPlayer, CriMvFrameInfo* frameInfo, CriError* error)
{
    *error = CRIERR_OK;
    CriSint32 result = criMvPly_DiscardNextFrame(((CriMvEasyPlayerFrameFields*)easyPlayer)->PlayerHandle, frameInfo);
    FUN_1400393f0((CriMvEasyPlayer*)easyPlayer, 0, 0, 1, 0, 0);
    return result;
}

// Apply the analyzed movie header after a successful decoder analysis pass.
// @0x1400318f0
CriBool executeDecHdrStageAnalizeHeader(void* player)
{
    struct HeaderCopy { CriUint8 Bytes[0x2c0]; };   // the header is copied as a struct (through a /Od temp)
    CriBool analyzed = FUN_140032090(player);
    if (((CriMvPlyObj*)player)->decoder_error == 1)
        return 0;
    if (analyzed != 1)
        return 0;
    *(HeaderCopy*)((CriMvPlyHeaderAnalysisFields*)player)->CurrentHeader =
        *(const HeaderCopy*)((CriMvPlyHeaderAnalysisFields*)player)->AnalyzedHeader;
    ((CriMvPlyHeaderAnalysisFields*)player)->HeaderParameter = 0;
    return 1;
}

// Complete the metadata stage only when parsing succeeds without a decoder error.
// @0x140032040
CriBool executeDecHdrStageMetaGet(void* player)
{
    // The exe parses the queued header chunks first, then reports a decoder error.
    CriBool headerDone = decodeMetaData(player);
    if (((CriMvPlyObj*)player)->decoder_error == 1)
        return 0;
    if (headerDone != 1)
        return 0;
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // the exe built these lock wrappers without optimization (/Od)
// Run the metadata-work cleanup under the player's handle critical section.
// @0x140031f00
CriBool freeMetaWork(void* player)
{
    enterHandleCs(player);
    CriBool result = freeMetaWorkInCs(player);
    leaveHandleCs(player);
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // the exe built these lock wrappers without optimization (/Od)
// Enter the player's handle lock around the requested CRI Movie transition.
// @0x140034920
CriBool criMvPly_Start(void* player)
{
    enterHandleCs(player);
    CriBool result = crimvply_StartInCs(player);
    leaveHandleCs(player);
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Destroy player-owned decoders and queues under the player's handle lock.
// @0x140030c70
void FUN_140030c70(void* player)
{
    enterHandleCs(player);
    FUN_140030cb0(player);
    leaveHandleCs(player);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // the exe built these lock wrappers without optimization (/Od)
// Perform the player update under its handle critical section.
// @0x140031aa0
extern "C" CriBool allocateMetaWork(void* player)
{
    enterHandleCs(player);
    CriBool result = allocateMetaWorkInCs(player);
    leaveHandleCs(player);
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Request both video decoders to stop and move the player into stop-pending state.
// @0x140034b60
void crimvply_StopInCs(void* player)
{
    if (((CriMvPlyStateTransitionFields*)player)->Status == 0)
        ((CriMvPlyStateTransitionFields*)player)->Status = 0;
    else if (((CriMvPlyStateTransitionFields*)player)->Status == 7)
        ((CriMvPlyStateTransitionFields*)player)->Status = 0;
    else if (((CriMvPlyStateTransitionFields*)player)->Status == 9 || ((CriMvPlyStateTransitionFields*)player)->Status == 6)
    {
    }
    else
    {
        ((CriMvPlyStateTransitionFields*)player)->InternalFlags = 1;
        ((CriMvPlyStateTransitionFields*)player)->Status = 8;
        void* videoDec = ((CriMvDecoderHandleFields*)player)->VideoDecoder;
        if (videoDec)
            criVdec_RequestStop(videoDec);
        void* alphaDec = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
        if (alphaDec)
            criAlphaDec_RequestStop(alphaDec);
    }
}

// Stop the player under its handle critical section.
// @0x140034b20
void criMvPly_Stop(void* player)
{
    enterHandleCs(player);
    crimvply_StopInCs(player);
    leaveHandleCs(player);
}

// Fetch a 16-bit waveform block from the main audio stream.
// @0x140035f00
CriUint32 criMvPly_GetWave16(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    CriUint32 count = criMvPlyAmng_GetWave16(((CriMvDecoderHandleFields*)player)->AudioManager, 0, player,
                                    format, output, sampleCount, (CriUint32*)result);
    return count;
}

// Fetch a 32-bit waveform block from the main audio stream.
// @0x140035f70
CriUint32 criMvPly_GetWave32(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    CriUint32 count = criMvPlyAmng_GetWave32(((CriMvDecoderHandleFields*)player)->AudioManager, 0, player,
                                    format, output, sampleCount, (CriUint32*)result);
    return count;
}

// Fetch a 16-bit waveform block from the secondary audio stream.
// @0x140035fe0
CriUint32 criMvPly_GetSubAudioWave16(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    CriUint32 count = criMvPlyAmng_GetWave16(((CriMvDecoderHandleFields*)player)->AudioManager, 1, player,
                                    format, output, sampleCount, (CriUint32*)result);
    return count;
}

// Fetch a 32-bit waveform block from the secondary audio stream.
// @0x140036050
CriUint32 criMvPly_GetSubAudioWave32(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    CriUint32 count = criMvPlyAmng_GetWave32(((CriMvDecoderHandleFields*)player)->AudioManager, 1, player,
                                    format, output, sampleCount, (CriUint32*)result);
    return count;
}

// Request the next alpha-frame metadata record when the alpha decoder is present.
// @0x140035e90
CriBool getNextAlphaFrameInfo(void* player, void* frameInfo)
{
    void* frame = NULL;
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder == NULL)
        return 0;
    frame = criAlphaDec_GetNextAlphaFrameInfo(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
    if (frame == NULL)
        return 0;
    return 1;
}

// Advance the alpha decoder to the requested frame, releasing frames skipped en route.
// @0x140035db0
CriBool syncAlphaFrameWithVideo(void* player, CriSint32 targetFrame, void* frameInfo)
{
    void* alpha = NULL;
    CriBool ok = getNextAlphaFrameInfo(player, frameInfo);
    if (ok == 0)
        return 0;
    while (targetFrame > *(CriSint32*)((CriUint8*)frameInfo + 8))
    {
        alpha = criAlphaDec_GetAlphaFramePointer(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
        if (alpha != NULL)
            criAlphaDec_ReleaseAlphaFramePointer((CriUint64*)((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
        else
            return 0;
        // the decoder rewrote frameInfo: compare the frame it now holds, not the one read above
        if (*(CriSint32*)((CriUint8*)frameInfo + 8) + 1 == targetFrame)
        {
            alpha = criAlphaDec_GetNextAlphaFrameInfo(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
            if (alpha == NULL)
                return 0;
            break;
        }
    }
    return 1;
}

// Pair the next video frame with its matching alpha frame when the alpha decoder is ready.
// @0x140035c80
void* criMvPly_GetNextFrameInfo(void* player, void* output)
{
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): videoFrame, videoToken, alphaFrame, result.
    CriMvFrameInfo videoFrame;               // left uninitialised, as in the exe; the decoder fills it
    void* videoToken;
    CriUint64 alphaFrame[10];                // the 0x50-byte alpha frame record
    CriSint32 result;
    crimvply_clearFrameInfoMembers(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return NULL;
    videoToken = criVdec_GetNextFrameInfo(((CriMvDecoderHandleFields*)player)->VideoDecoder, &videoFrame);
    if (videoToken != NULL)
    {
        if (((CriMvDecoderHandleFields*)player)->AlphaDecoder != NULL
            && criAlphaDec_GetStatus(((CriMvDecoderHandleFields*)player)->AlphaDecoder) == 3)
        {
            crimvply_occurUserError(player, "E08092600M : Alpha channel is longer than video frame. should be same.", 0);
            return NULL;
        }
        if (((CriMvDecoderHandleFields*)player)->AlphaDecoder != NULL)
        {
            result = syncAlphaFrameWithVideo(player, videoFrame.frame_id, alphaFrame);
            if (result == 0)
                return NULL;
        }
        crimvply_makeFrameInfoMembers(player, output, &videoFrame, (CriUint64)(uintptr_t)videoToken, 0);
    }
    return videoToken;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// Return the ordinary or suppressed CRI error count selected by the API flag.
// @0x140038eec
CriUint32 criErr_GetErrorCount(CriSint32 type)
{
    switch (type)
    {
    case 0:
        return DAT_143b27bcc;
    case 1:
        return DAT_143b27bd0;
    default:
        criErr_NotifyGeneric(0, "E09012703B", -2);
        return 0;
    }
}

// Reset one of CRI Error's two counters or report the invalid selector.
// @0x140038f24
void criErr_ResetErrorCount(CriSint32 type)
{
    switch (type)
    {
    case 0:
        DAT_143b27bcc = 0;
        break;
    case 1:
        DAT_143b27bd0 = 0;
        break;
    default:
        criErr_NotifyGeneric(0, "E09012704B", -2);
        break;
    }
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Publish the callback and user object used to compare decoded frame times.
// @0x140039750
void CriMvEasyPlayer::SetCompareFrameTimeCallback(
    CriSint32 (*callback)(CriMvEasyPlayer*, CriMvFrameInfo*, CriUint64, CriUint64, void*),
    void* userObject, CriError& error)
{
    error = CRIERR_OK;
    typedef CriSint32 (*CompareCallback)(CriMvEasyPlayer*, CriMvFrameInfo*, CriUint64, CriUint64, void*);
    *(CompareCallback*)((CriUint8*)this + 0x620) = callback;
    *(void**)((CriUint8*)this + 0x628) = userObject;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Query the easy player's next frame using the standard one-frame offset.
// @0x140038f60
CriSint32 CriMvEasyPlayer::IsNextFrameOnTime(CriError& error)
{
    const CriSint32 checkDelay = 1;
    CriSint32 result = FUN_140039180(this, checkDelay, (CriUint32*)&error);
    return result;
}

// Release the optional alpha frame and the associated main video frame.
// @0x140039d80
CriSint32 CriMvEasyPlayer::UnlockFrameBufferWithAlpha(const CriMvFrameInfo* frameInfo,
                                                       const CriMvAlphaFrameInfo* alphaInfo,
                                                       CriError& error)
{
    error = CRIERR_OK;
    criMvPly_UnlockAlphaFrameBuffer(mvply, (const CriUint64*)alphaInfo);
    criMvPly_UnlockFrameBuffer(mvply, frameInfo);
    return 1;
}
#pragma optimize("", on)

// The CRI Movie critical-section create: a tail call into CRI Base's criCs_Create (FUN_140039ea8, sfr_cri_03).
// @0x1400385c8
void* FUN_1400385c8(void* work, CriSint32 workSize)
{
    return FUN_140039ea8(work, workSize);
}

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Allocate the 0x40-byte memory reader from its CRI heap and initialize its state.
// @0x1400385d0
CriMvEasyFileReaderMem* CriMvEasyFileReaderMem::Create(CriHeap heap)
{
    CriMvEasyFileReaderMem* reader = new(heap, "CriMvEasyFileReaderMem", 4) CriMvEasyFileReaderMem();
    if (reader == NULL)
        return NULL;
    reader->Data = NULL;
    reader->FileSize = -1;
    reader->Position = 0;
    reader->ReadSize = 0;
    reader->Heap = heap;
    reader->OpenState = ASYNC_STATUS_STOP;
    reader->ReadState = ASYNC_STATUS_STOP;
    reader->CloseState = ASYNC_STATUS_STOP;
    return reader;
}

// Initialize the CRI file-reader base before the derived memory-reader vtable is installed.
// @0x140038c10
CriMvEasyFileReaderMem::CriMvEasyFileReaderMem()
    : CriMvFileReaderInterface()
{
}

// Open MFS:<hex-address>.<hex-size> memory-file names.
// @0x140038720
void CriMvEasyFileReaderMem::Open(CriChar8* fname)
{
    // The exe leaves the parsing to FUN_1400389f0 and only stores its two results.
    CriBool result = 1;
    CriUint64 address;
    CriUint64 size;
    OpenState = ASYNC_STATUS_BUSY;
    result = FUN_1400389f0(this, fname, &address, &size);
    if (result == 1)
    {
        Data = (CriUint8*)address;
        FileSize = (CriSint64)size;
    }
    else
    {
        OpenState = ASYNC_STATUS_ERROR;
        return;
    }
    OpenState = ASYNC_STATUS_COMPLETE;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Clear the current memory file and report the completed close state.
// @0x1400387b0
void CriMvEasyFileReaderMem::Close(void)
{
    CloseState = ASYNC_STATUS_BUSY;
    FileSize = -1;
    Data = NULL;
    Position = 0;
    ReadSize = 0;
    CloseState = ASYNC_STATUS_COMPLETE;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
#pragma function(memcpy)                        // this row calls memcpy; the small copies elsewhere stay inline
// copy up to the remaining file size and publish the byte count as the read result.
// @0x140038810
void CriMvEasyFileReaderMem::Read(CriUint8* buffer, CriSint64 req_size)
{
    CriUint8* source;
    ReadState = ASYNC_STATUS_BUSY;
    if (Position + req_size > FileSize)
        req_size = FileSize - Position;
    source = Data + Position;
    memcpy(buffer, source, (size_t)req_size);
    ReadSize = req_size;
    Position = Position + req_size;
    ReadState = ASYNC_STATUS_COMPLETE;
}
#pragma intrinsic(memcpy)
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Return the current memory-file open status.
// @0x1400388d0
CriMvFileReaderInterface::AsyncStatus CriMvEasyFileReaderMem::GetOpenStatus(void)
{
    return OpenState;
}

// Return the current memory-file close status.
// @0x140038910
CriMvFileReaderInterface::AsyncStatus CriMvEasyFileReaderMem::GetCloseStatus(void)
{
    return CloseState;
}

// Return the current memory-file read status.
// @0x1400388f0
CriMvFileReaderInterface::AsyncStatus CriMvEasyFileReaderMem::GetReadStatus(void)
{
    return ReadState;
}

// Return the size of the most recent memory-file read.
// @0x140038930
CriSint64 CriMvEasyFileReaderMem::GetReadSize(void)
{
    return (CriSint64)ReadSize;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Adjust the memory-file position according to the CRI seek origin.
// @0x140038950
CriSint64 CriMvEasyFileReaderMem::Seek(CriSint64 size, CriMvFileReaderInterface::SeekOrigin origin)
{
    switch (origin)
    {
    case SEEK_FROM_BEGIN:
        Position = size;
        break;
    case SEEK_FROM_CURRENT:
        Position += size;
        break;
    default:
        Position = FileSize + size;
        break;
    }
    return (CriSint64)origin;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Return the configured memory-file size.
// @0x1400389d0
CriSint64 CriMvEasyFileReaderMem::GetFileSize(void)
{
    return FileSize;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Clang drops the own vftable store (0x1431b9588) of this empty body; the inlined base dtor overwrites it anyway.
// The derived memory reader has no resources beyond its base reader state.
// @0x140038c80
CriMvEasyFileReaderMem::~CriMvEasyFileReaderMem()
{
}

// Destroy the reader and release its CRI heap allocation when requested.
// @0x140038c40
void* FUN_140038c40(CriMvEasyFileReaderMem* reader, CriUint32 flags)
{
    reader->CriMvEasyFileReaderMem::~CriMvEasyFileReaderMem();  // non-virtual
    if ((flags & 1) != 0)
        CriAllocator::operator delete(reader, (size_t)0x40);
    return reader;
}

// Destroy the reader through its virtual deleting destructor.
// @0x1400386c0
void CriMvEasyFileReaderMem::Destroy(void)
{
    delete this;
}
#pragma optimize("", on)
// MS2-PIN: ?executeMvPlyPrepServer@@YAXPEAX@Z 0x140033810
// MS2-PIN: ?FUN_140033d70@@YAJPEAXPEBUCriMovieInputChunk@@E@Z 0x140033d70
