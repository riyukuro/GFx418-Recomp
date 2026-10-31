// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the CRI Movie 3.07.01 internals (criMvPly, the decoder
// and reader glue, 0x14002e548-0x140039ea8). Our own source, written from the exe; the leaked SDK copies were only used
// to name things. The Scaleform GFx Video code before it stays in sfr_cri_02 (VS2012). The CRI library was built with
// VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto,
// decltype, variadic templates, brace-init or nullptr). 0x1400356a0 and 0x140035800 are in sfr_cri_02d: they only
// byte-match compiled as C (/TC), as the exe's criMvPly objs were.
// MS2-UNIT: sfr_cri_02c
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14002e548-0x140030cb0 .text$mn
// MS2-RANGE: 0x140030e50-0x140031290 .text$mn
// MS2-RANGE: 0x1400313d0-0x1400356a0 .text$mn
// MS2-RANGE: 0x140035710-0x140035800 .text$mn
// MS2-RANGE: 0x1400358d0-0x140036470 .text$mn
// MS2-RANGE: 0x140036590-0x140039ea8 .text$mn
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
extern const void* DAT_1431b95e8[];
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

const CriUint8* criUsfCmn_GetContents(const CriUint8* data, CriUint32 size, CriSint32* contentSize);
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
void*    FUN_140027f7c(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align, CriSint32 type);
void     FUN_14001d650(void* config, void* reader);                     // VideoReaderConfig::AttachReader
void*    FUN_140041d40(void* pheap);                                    // CriHeap over a MemoryHeap: create
void     FUN_140041dd0(void* criheap);                                  //   and destroy
void*    FUN_140041c00(void* mem);                                      // SystemTimerSyncObject::SystemTimerSyncObject
void*    FUN_14002a010(void* mem, void* pheap, void* psound);           // CriMvSound::CriMvSound(MemoryHeap*, VideoSound*)
void*    FUN_140029e40(void* mem, void* psync);                     // CriMvSystemTimer::CriMvSystemTimer(SyncObject*)
void*    FUN_14002abd0(void* mem, CriUint32 format, const CriUint32* psize, const void* ptexman, void* pplayer); // VideoImage ctor
void     FUN_140037950(void* player, const char* message, CriSint32 severity);
void     FUN_140044fdc(void* inputBuffer);
CriSint32 criSjRbf_CalculateWorkSize(const CriSint32* config);
void*    FUN_140045eec(const void* config, void* work, CriSint32 workSize);
void*    FUN_140046730(void* heap, CriSint32 size, CriSint32 flags, CriSint32 align, const char* name);
void*    FUN_140027ed8(void* heap, CriSint32 size, const char* name, CriSint32 align);
CriSint32 FUN_140044eb0(CriSint32 workCount);
CriSint32 FUN_140046604(CriUint32 first, CriUint32 second, CriUint32 alignment, const void* flags);
CriSint32 FUN_140044400(void* decoder, CriUint32 first, CriUint32 second, CriUint32 third);
CriSint32 FUN_140043a80(void* decoder, CriUint32 first, CriUint32 second, CriUint32 third);
CriSint32 FUN_140041ee0(const void* params);
CriSint32 FUN_140046420(CriUint32 first, CriUint32 second, const void* flags);
void* FUN_140030be0(CriSint32 codecId);
CriSint32 criSjUni_CalculateWorkSize(const CriSint32* config);
void*    FUN_140045144(CriSint32 count, void* work, CriSint32 workSize);
void*    FUN_1400459ec(const void* config, void* work, CriSint32 workSize);
CriSint32 FUN_140042150(const void* decoder, const CriUint32* config);
void     FUN_140037850(void* player);
void     FUN_140037880(void* player);
struct CriMovieInputChunk;
CriUint32 FUN_140030280(void* player, void* heap, void* work);
CriUint32 decideReadBufferExtSize(void* player);
void FUN_140037a40(const CriMovieInputChunk* current, const CriMovieInputChunk* previous, void* player);
void*    FUN_140041f70(void* player, void* heap, const CriMvStreamingParameters* params);
void*    FUN_140043af0(void* decoderInterface, void* heap, const void* config);
void*    FUN_140044470(void* decoderInterface, void* heap, const void* config);
void     FUN_140044de0(void* decoder, void* callback, void* context);
void     FUN_140044330(void* decoder, void* callback, void* context);
void     FUN_140044c10(void* decoder, CriUint32 mask);
CriHeap  FUN_140027fec(void* memory, CriSint32 size);
void*    FUN_140039ea8(void* work, CriSint32 workSize);
void*    FUN_1400385c8(void* work, CriSint32 workSize);
void*    FUN_1400452b4(CriHeap heap, CriSint32 count);
void*    FUN_1400464c8(CriHeap heap, CriSint32 kind, CriSint32 alignment);
void     FUN_14002f610(CriUint32* player);
void     FUN_14002f850(void* player);
void*    FUN_140030b50(CriSint32 codecId);
void*    FUN_140044e40(void* decoderInterface);
CriSint32 FUN_1400467b8(void* ringBuffer, CriSint32 query);
void FUN_140046804(void* object, void* value);
void FUN_140046814(void* streamJoint, const void* chunk, CriUint32 size);
void criSj_SplitChunk(const void* source, CriUint32 maximum, void* prefix, void* suffix);
void     FUN_140039f50(void* section);
void     FUN_140039f8c(void* section);
void     FUN_1400411f8(void);
char*    FUN_140046944(char* dst, size_t size, const char* src);
char*    FUN_14004698c(char* dst, size_t size, const char* src);
void     FUN_140038190(const void* key);
CriBool  FUN_1400389f0(void* reader, const char* path, CriUint64* size, CriUint64* offset);
void     FUN_140038ce4(CriSint32 category, const char* message, CriSint32 value, CriSint32 flags, void* owner);
void     FUN_140038e24(CriSint32 category, const char* message, CriSint32 value);
void     FUN_140031140(void* player);
void     FUN_140031290(void* player);
CriBool  FUN_140031f40(void* player);
CriBool  FUN_1400318f0(void* player);
CriBool  FUN_140032040(void* player);
CriBool  FUN_140031aa0(void* player);
CriBool  FUN_1400314d0(void* player);
CriSint32 FUN_140042d70(void* decoder, void* player);
void     FUN_1400428e0(void* audioManager, void* player);
void     FUN_140031570(void* player);
void     FUN_140034730(void* player);
void     FUN_140033810(void* player);
CriBool  FUN_140033d70(void* player, const CriMovieInputChunk* input, CriUint8 outputIndex);
void     FUN_140041df0(void* manager, void* callback, void* userData);
void     FUN_140042700(void* trackSet, void* player);
CriBool  FUN_140042cf0(void* trackSet, void* operation);
void     FUN_140044cc0(void* decoder, void* callback, void* userData);
void     FUN_140044c60(void* decoder, CriUint32 position, CriUint32 mode);
CriUint64 FUN_1400445d0(CriUint64* pair);
void*    FUN_140043c50(void** decoder);
void     FUN_140044210(CriUint64* pair, void* first, void* second);
void     FUN_1400441b0(CriUint64* pair, CriUint32 first, CriUint32 second);
void     FUN_1400344f0(void* player);
CriBool  FUN_140031410(void* player);
void     FUN_1400317b0(void* player);
void     FUN_140034730(void* player);
void     FUN_140034330(void* player, void* source, void* readBuffer, void* dataQueue);
void     FUN_1400453c4(void* demux);
void     FUN_1400458b8(void* demux);
void*    FUN_14003b348(void* heap, const void* data, CriUint32 size);
CriUint32 FUN_14003a85c(void* object, CriSint32 index, const char* key);
CriSint32 FUN_14003a3e0(void* object, const char* key);
CriSint32 FUN_14003a45c(void* object);
CriSint32 FUN_14003a894(void* object, CriSint32 index, const char* key);
void*    FUN_14003a648(void* object, CriSint32 index, CriSint32 value);
void     FUN_14003af50(void* object, CriSint32 row, CriSint32 field, CriUtfRtvCell* cell);
void     criUtfRtv_Destroy(CriUint64* table);
CriUint32 FUN_14003b3fc(const CriUint8* data, CriUint32 size, void* output);
CriBool  FUN_140043d40(void* decoder);
CriBool  FUN_1400446c0(void* decoder);
void     FUN_140044ae0(void* decoder);
CriBool  FUN_140032090(void* player);
CriBool  FUN_140033030(void* player);
CriBool  FUN_140031f40(void* player);
CriBool  FUN_140034960(void* player);
CriBool  FUN_140031ae0(void* player);
void     FUN_140030cb0(void* player);
void     FUN_140034b60(void* player);
void     FUN_140035260(void* player, void* output, const void* frameInfo, CriUint64 firstWord, CriUint32 flags);
CriBool  FUN_1400355b0(void* player, void* output);
CriBool  FUN_140035710(void* player, void* yuvBuffers, void* output);
CriSint32 FUN_140044630(void* decoder);
CriSint32 FUN_140044f8c(void* demux);
CriSint32 FUN_1400447d0(void* decoder);
CriSint32 FUN_140043e60(void* decoder);
CriUint32 FUN_140044820(void* decoder);
CriUint32 FUN_140043eb0(void* decoder);
void FUN_140044710(void* decoder);
void FUN_140043d90(void* decoder);
void     FUN_140042880(void* audioManager);
void     FUN_1400427b0(void* audioManager);
void     FUN_140042800(void* audioManager);
void     FUN_140044790(void* videoDecoder);
void     FUN_140043e20(void* alphaDecoder);
CriSint32 FUN_140043cb0(void* decoder);
void     FUN_140044750(void* decoder);
void     FUN_140043dd0(void* decoder);
void     FUN_1400393f0(CriMvEasyPlayer* easyPlayer, CriSint32 a, CriSint32 b, CriSint32 c,
                       CriUint64 d, CriUint64 e);
CriSint32 FUN_140039330(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo);
CriBool  FUN_140039180(CriMvEasyPlayer* easyPlayer, CriSint32 updateTime, CriUint32* output);
void*    FUN_140035c80(void* player, void* output);
CriBool  FUN_140035710(void* player, void* movieYuvState, void* outputInfo);
CriBool  FUN_140035800(void* player, void* movieYuvState, void* outputInfo);
CriSint32 FUN_1400397a0(CriMvEasyPlayer* self, CriMvEasyPlayer* player, const CriMvFrameInfo* frameInfo,
                        CriUint64 count, CriUint64 unit, void* userData);
void     FUN_1400467b0(void* queue, CriSint32 operation, void* chunk);
void     FUN_1400467a8(void* queue, CriSint32 operation, void* chunk);
CriUint32 FUN_140036650(void* player);
void     FUN_140036710(void* player);
void     FUN_1400369e0(void* player);
void     FUN_140034c20(void* player);
CriUint32 FUN_140042e40(void* manager, CriSint32 stream, void* player, CriUint32 format,
                          void* output, CriUint32 sampleCount, void* result);
CriUint32 FUN_140042ea0(void* manager, CriSint32 stream, void* player, CriUint32 format,
                          void* output, CriUint32 sampleCount, void* result);
void*    FUN_140043f10(void* decoder, void* frameInfo);
void*    FUN_140043fe0(void* decoder, void* frameInfo);
void*    FUN_140044870(void* decoder, void* frameInfo);
void     FUN_140044e84(void);
void     FUN_140039fc8(void);
void     FUN_14003a010(void);
void     FUN_140041ea0(void);
void     FUN_140041ec0(void);
void     FUN_140043a20(const void* decoderInterface);
void     FUN_140043a50(void* decoderInterface);
void     FUN_140044390(const void* decoderInterface);
void     FUN_1400443d0(void* decoderInterface);
void     FUN_140044ea8(void);
void     FUN_140039f00(void* section);
void*    FUN_1400449c0(void* decoder, void* frameInfo);
void     FUN_140044050(void* decoder, void* frameInfo);
void     FUN_140044a30(void* decoder, void* frameInfo);
void     FUN_140044b20(void* decoder, CriUint32 frameId, CriUint64* count, CriUint64* unit);
CriBool  FUN_140043f70(void* decoder, void* buffers, void* frameInfo);
void     FUN_140044b90(void* decoder, void* a, void* b, void* c, void* d, void* e);
void     FUN_140044fb0(void* output, CriUint32 index, void* value, CriUint32 type, CriUint32 flags);
void     FUN_140044680(void* decoder);
void     FUN_140043d00(void* decoder);
CriBool  FUN_1400467b8(void* queue, CriSint32 operation);
void     FUN_1400467a0(void* queue, CriSint32 operation, CriSint32 timeout, void* item);
void     FUN_140044d20(void* decoder, CriUint32 count);
void     FUN_140044270(void* decoder, CriUint32 count);
void     FUN_140044d70(void* decoder, CriUint32 count, void* streamInfo, void* outputInfo);
void     FUN_1400442c0(void* decoder, CriUint32 count, void* streamInfo, void* outputInfo);
void     FUN_140032650(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed);
void     FUN_140032a70(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed);
void     FUN_140032db0(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed);
void     FUN_140032b70(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed);
struct CriMovieStreamSlotView;
void     FUN_140033e60(void* player, CriMovieStreamSlotView* slot);
void*    FUN_14002db40(void* thread, void* config);
CriBool  FUN_140042270(void* manager, void* player, void* source, void* streamInfo,
                       CriUint32 stream, CriBool enable);
void     FUN_140041e30(void* manager, void (*callback)(void**, void*), void* player, CriBool enable);
CriBool  FUN_140037a10(void);
void     FUN_140037910(void* owner, const char* message, CriSint32 value);
CriUint32 FUN_140042f00(void* manager, CriSint32 stream, void* player, CriUint32 channels);
void     FUN_140042df0(void* manager, void* player, CriSint32 stream);
void     FUN_140042600(void* manager, void* decoder, CriSint32 stream);
CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* chunk, CriSint32 channel);
void     FUN_140036e30(void* player, CriMvSubtitleChunk* chunk);
void     FUN_1400363b0(void* player, void* chunk, CriUint32 type);
void     FUN_140036e80(void* player, CriMvSubtitleChunk* chunk);
void     FUN_140036f40(void* player, CriMvSubtitleChunk* chunk, void* outputInfo);
void     FUN_140046784(void* streamJoint);
void     FUN_140027fb4(void* heap, void* memory);
void     FUN_140044fa8(void* demux, void* value);
void     FUN_140044fd8(void* demux, CriUint8 value);
void     FUN_140044f28(void* demux);
void     FUN_140030c70(void* player);
CriBool  FUN_140031f00(void* player);
void     FUN_140044f9c(void* demux);
void     FUN_140046798(void* streamJoint);
void     FUN_1400420b0(void* manager, void* heap);
void     FUN_140043be0(void* decoder);
void     FUN_140044560(CriUint64* adapter);
void     FUN_140028074(void* heap);
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
    if (!FUN_140037a10)                      // the exe tests the function's address, which is never null
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
    if (!FUN_140037a10)                      // the exe tests the function's address, which is never null
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

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: the CRI VS2008 build has different code generation for this wrapper.
// @0x14002e628
int FUN_14002e628(CriSint32 alignment)
{
    return criHeap_DebugGetWorstExtraSize(alignment) + (int)sizeof(CriHeap);
}
#pragma optimize("", on)

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

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: CRI emits the empty helper as a short c2 return in its VS2008 build.
// @0x14002e6bc
void FUN_14002e6bc(CriFixedAllocator*)
{
}
#pragma optimize("", on)

// MS2-FUNCTIONAL: bump-allocate size bytes at the next align boundary.
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
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: preserves the executable's invalid-value store after its diagnostic call.
// @0x140031060
void FUN_140031060(void* player, CriSint32 value)
{
    if (value <= 0)
        FUN_140037950(player, "E10120701M : the parameter 'nframes' must be 1 or more.", 0);
    *(CriSint32*)((CriUint8*)player + 0xed8) = value;
}

CriSint32 getInternalStatus(void* player);

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this accessor reads the status through getInternalStatus.
// @0x1400310b0
CriSint32 criMvPly_GetStatus(void* player)
{
    CriSint32 status = getInternalStatus(player);
    return status;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this wrapper preserves its status gate and frame-time update.
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

// MS2-FUNCTIONAL: forwards both frame queries and copies the returned YUV metadata into the player's saved frame.
// @0x140039cb0
CriBool FUN_140039cb0(CriMvEasyPlayer* easyPlayer, void* yuvBuffers,
                      CriMvFrameInfo* frameInfo, CriMvAlphaFrameInfo* alphaInfo, CriError& error)
{
    error = CRIERR_OK;
    CriBool result = FUN_140035710(easyPlayer->mvply, yuvBuffers, frameInfo);
    if (result == 1)
        FUN_140035800(easyPlayer->mvply, yuvBuffers, alphaInfo);
    if (result == 1)
        easyPlayer->frame_info = *frameInfo;
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this accessor is rebuilt with our VS2017 toolset.
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

// MS2-FUNCTIONAL: fetch a due video frame from CriMvPly and retain its metadata on the easy player.
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
    handle = FUN_140035c80(easyPlayer->mvply, &videoFrame);
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

// MS2-FUNCTIONAL: fetch video and optional alpha frame metadata and retain the alpha snapshot on the easy player.
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
    result = FUN_140035710(easyPlayer->mvply, yuvBuffers, outputInfo);
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

// MS2-FUNCTIONAL: restores CRI's alternating timestamp-error correction using the frame-rate and state fields it stores.
// @0x1400398a0
CriSint32 CriMvEasyPlayer::compareFrameTimeFluctuation(CriMvEasyPlayer* easyPlayer,
    CriMvFrameInfo* frameInfo, CriUint64 count, CriUint64 unit, void*)
{
    CriSint32* mode = (CriSint32*)((CriUint8*)easyPlayer + 0x3a8);
    if (*mode == 0)
        return 1;

    CriFloat32 base = *(CriFloat32*)((CriUint8*)easyPlayer + (*mode == 1 ? 0x70c : 0x710));
    CriFloat32 period = *(CriFloat32*)((CriUint8*)easyPlayer + 0x714) *
                        *(CriFloat32*)((CriUint8*)easyPlayer + 0x718);
    CriFloat32 center = base + period;

    CriUint64 frameCount = *(CriUint64*)((CriUint8*)frameInfo + 0x28);
    CriUint64 frameUnit = *(CriUint64*)((CriUint8*)frameInfo + 0x30);
    CriUint64 frameCycle = frameUnit * 600;
    CriUint64 systemCycle = unit * 600;
    CriUint64 frameQuotient = frameCount / frameCycle;
    CriUint64 systemQuotient = count / systemCycle;
    CriUint64 adjustedCount = count;
    if (frameQuotient > 1 && systemQuotient > 1)
    {
        CriUint64 cycles = (frameQuotient < systemQuotient ? frameQuotient : systemQuotient) - 1;
        frameCount -= frameCycle * cycles;
        adjustedCount -= systemCycle * cycles;
    }

    CriFloat32 frameCountFloat = (CriFloat32)(CriSint64)frameCount;
    CriFloat32 frameUnitFloat = (CriFloat32)(CriSint64)frameUnit;
    CriFloat32 systemCountFloat = (CriFloat32)(CriSint64)adjustedCount;
    CriFloat32 systemUnitFloat = (CriFloat32)(CriSint64)unit;
    if ((CriSint64)frameCount < 0) frameCountFloat += 18446744073709551616.0f;
    if ((CriSint64)frameUnit < 0) frameUnitFloat += 18446744073709551616.0f;
    if ((CriSint64)adjustedCount < 0) systemCountFloat += 18446744073709551616.0f;
    if ((CriSint64)unit < 0) systemUnitFloat += 18446744073709551616.0f;
    CriFloat32 frameTime = frameCountFloat * 1000.0f / frameUnitFloat;
    CriFloat32 systemTime = systemCountFloat * 1000.0f / systemUnitFloat;
    CriFloat32 delta = systemTime - frameTime;
    CriSint32* phase = (CriSint32*)((CriUint8*)easyPlayer + 0x708);
    if (*phase == 1)
    {
        CriFloat32 corrected = systemTime - period - frameTime;
        if (corrected >= 0.0f)
        {
            if (period > corrected)
                *phase = 2;
            return 1;
        }
        return 0;
    }
    if (*phase == 2)
    {
        CriFloat32 corrected = systemTime + center - frameTime;
        if (corrected < 0.0f)
        {
            if (-period < corrected)
                *phase = 1;
            return 0;
        }
        return 1;
    }
    if (delta < 0.0f)
    {
        if (period < delta)
            *phase = 1;
        return 0;
    }
    if (delta < center)
        *phase = 2;
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this helper is rebuilt with our VS2017 toolset.
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
// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this predicate is rebuilt with our VS2017 toolset.
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

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this frame-info copier is rebuilt with our VS2017 toolset.
// @0x1400358d0
CriUint32 FUN_1400358d0(void* output, const void* info)
{
    memset(((CriMvPlaneInfo*)output), 0, 0x40);
    CriUint32 planes = ((const CriMvFramePlaneSource*)info)->PlaneCount;
    if (planes != 0)
    {
        ((CriMvPlaneInfo*)output)[0].Buffer = ((const CriMvFramePlaneSource*)info)->Planes[0].Buffer;
        ((CriMvPlaneInfo*)output)[0].Stride = (CriSint32)((const CriMvFramePlaneSource*)info)->Planes[0].Height * (CriSint32)((const CriMvFramePlaneSource*)info)->Planes[0].Width;
        ((CriMvPlaneInfo*)output)[0].Height = ((const CriMvFramePlaneSource*)info)->Planes[0].Height;
    }
    if (planes > 1)
    {
        ((CriMvPlaneInfo*)output)[1].Buffer = ((const CriMvFramePlaneSource*)info)->Planes[1].Buffer;
        ((CriMvPlaneInfo*)output)[1].Stride = (CriSint32)((const CriMvFramePlaneSource*)info)->Planes[1].Height * (CriSint32)((const CriMvFramePlaneSource*)info)->Planes[1].Width;
        ((CriMvPlaneInfo*)output)[1].Height = ((const CriMvFramePlaneSource*)info)->Planes[1].Height;
    }
    if (planes > 2)
    {
        ((CriMvPlaneInfo*)output)[2].Buffer = ((const CriMvFramePlaneSource*)info)->Planes[2].Buffer;
        ((CriMvPlaneInfo*)output)[2].Stride = (CriSint32)((const CriMvFramePlaneSource*)info)->Planes[2].Height * (CriSint32)((const CriMvFramePlaneSource*)info)->Planes[2].Width;
        ((CriMvPlaneInfo*)output)[2].Height = ((const CriMvFramePlaneSource*)info)->Planes[2].Height;
    }
    return planes;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this plane updater is rebuilt with our VS2017 toolset.
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
    if (format == 0)
        *(CriUint32*)((CriUint8*)player + 0xe1c) = 2;
    else
        *(CriUint32*)((CriUint8*)player + 0xe1c) = 4;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this setter is rebuilt with our VS2017 toolset.
// @0x140037740
void FUN_140037740(void* player, CriUint32 value0, CriUint32 value1)
{
    ((CriMvStateFlags*)player)->Value0 = value0;
    ((CriMvStateFlags*)player)->Value1 = value1;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this setter is rebuilt with our VS2017 toolset.
// @0x140037780
void FUN_140037780(void* player, CriUint32 value)
{
    ((CriMvStateFlags*)player)->Value2 = value;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this state transition is rebuilt with our VS2017 toolset.
// @0x1400379b0
void crimvply_transitErrorState(void* player, void* message)
{
    if (message == message) {}               // the CRI unused-argument idiom: /Od loads it (the exe's dead load)
    if (player)
        ((CriMvErrorState*)player)->Error = 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: CRI Movie was built with VS2008; preserve the input-chunk state check from the executable.
// @0x140035000
CriBool isLockedInputChunk(const void* player)
{
    // The exe takes a pointer to the input-chunk state at +0xd90 and tests its lock flag at +8.
    const CriUint8* chunk = (const CriUint8*)player + 0xd90;
    return ((const CriSint32*)chunk)[2] == 0 ? 0 : 1;
}

// MS2-FUNCTIONAL: CRI Movie was built with VS2008; this transition helper is rebuilt with our VS2017 toolset.
// @0x140035050
void criMvPly_TerminateSupply(void* player)
{
    ((CriMvSupplyState*)player)->Terminated = 1;
    ((CriMvSupplyState*)player)->SupplyEnded = 1;
    FUN_140044fdc(((CriMvSupplyInputBuffer*)player)->InputBuffer);
}

// Resets a CriMvFrameInfo field by field, all four image planes included; pitch is left as is.
// @0x140035090
void FUN_140035090(void* record)
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

// MS2-FUNCTIONAL: return the next decoded video frame and release its decoder-owned record afterward.
// @0x1400355b0
CriBool FUN_1400355b0(void* player, void* output)
{
    FUN_140035090(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return 0;

    CriMvFrameInfo frame = {};
    void* frameToken = FUN_1400449c0(((CriMvDecoderHandleFields*)player)->VideoDecoder, &frame);
    if (!frameToken)
        return 0;

    FUN_140035260(player, output, &frame, (CriUint64)(uintptr_t)frameToken, frame.width);
    FUN_140044a30(((CriMvDecoderHandleFields*)player)->VideoDecoder, &frame);
    // the decoder frame's concatenated-movie index (+0xa8), not the frame id: it selects the stream slot
    ((CriMvPlyObj*)player)->num_audio_out = *(CriUint32*)((CriUint8*)&frame + 0xa8);
    return 1;
}

// MS2-FUNCTIONAL: return decoded video metadata and copy the frame's plane descriptors into YUV buffers.
// @0x140035710
CriBool FUN_140035710(void* player, void* yuvBuffers, void* output)
{
    FUN_140035090(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return 0;

    CriMvFrameInfo frame = {};
    void* frameToken = FUN_1400449c0(((CriMvDecoderHandleFields*)player)->VideoDecoder, &frame);
    if (!frameToken)
        return 0;

    FUN_140035260(player, output, &frame, (CriUint64)(uintptr_t)frameToken, frame.width);
    // the decoder frame's concatenated-movie index (+0xa8), not the frame id: it selects the stream slot
    ((CriMvPlyObj*)player)->num_audio_out = *(CriUint32*)((CriUint8*)&frame + 0xa8);
    FUN_1400358d0(yuvBuffers, &frame);
    return 1;
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
// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this stores its caller-supplied metadata allocator.
// @0x1400301d0
void criMvPly_SetMetaDataWorkAllocator(void* player, void* work, void* allocate, void* freeFn, CriSint32 metaFlag)
{
    if (metaFlag == metaFlag) {} // read and unused, as in the exe (CriMvEasyPlayer passes its meta_flag)
    ((CriMvMetadataAllocatorFields*)player)->Work = work;
    ((CriMvMetadataAllocatorFields*)player)->Allocate = allocate;
    ((CriMvMetadataAllocatorFields*)player)->Free = freeFn;
}

// MS2-FUNCTIONAL: the work-size helper combines the CRI RBF, demux, and two universal-jump-buffer requirements.
// @0x14002e9e0
CriSint32 FUN_14002e9e0(void)
{
    CriUint32 rbfConfig[6] = { 1, 0x2800, 0, 0x40, 0, 0 };
    CriSint32 total = 0x376c + 4 + criSjRbf_CalculateWorkSize((const CriSint32*)rbfConfig);
    total += 4 + FUN_140044eb0(8);
    CriUint32 uniConfig[3] = { 1, 0, 0x40 };
    total += criSjUni_CalculateWorkSize((const CriSint32*)uniConfig);
    uniConfig[2] = 4;
    return total + criSjUni_CalculateWorkSize((const CriSint32*)uniConfig);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// register the next output stream buffer with the demuxer, logging an error past the capacity
// @0x1400345e0
void FUN_1400345e0(void* player, void* value, CriUint32 type, CriUint32 flags)
{
    void* output = ((CriMovieOutputLogView*)player)->Output;
    CriUint32 count = ((CriMovieOutputLogView*)player)->Count;
    if (count >= ((CriMovieOutputLogView*)player)->Capacity)
        FUN_140037910(player, "E05063025M : Can't entry output sj to demux more than limit.", count);
    FUN_140044fb0(output, count, value, type, flags);
    ((CriMovieOutputLogView*)player)->Count++;
}

// MS2-FUNCTIONAL: detect terminal decoder errors and report them through the player error logger.
// @0x140034690
void FUN_140034690(void* player)
{
    void* videoDec = ((CriMvDecoderHandleFields*)player)->VideoDecoder;
    if (videoDec)
    {
        FUN_140044680(videoDec);
        if (FUN_140044630(videoDec) == 4)
        {
            crimvply_transitErrorState(player, (void*)"The internal status of Vdec is ERROR.");
            return;
        }
    }
    void* alphaDec = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
    if (alphaDec)
    {
        FUN_140043d00(alphaDec);
        if (FUN_140043cb0(alphaDec) == 4)
            crimvply_transitErrorState(player, (void*)"The internal status of AlphaDec is ERROR.");
    }
}

// MS2-FUNCTIONAL: accept decoded primary-stream metadata and decrement its pending record count.
// @0x1400340f0
CriBool FUN_1400340f0(void* player, const CriMovieInputChunk* input)
{
    CriMovieStreamSlotsView* state = (CriMovieStreamSlotsView*)player;
    CriMovieStreamSlotView* slot = &state->Ring.Slots[state->Selector.Current];
    if (!slot->Active)
        return 0;
    if (input->Size > 0x1f)
    {
        CriSint32 size = 0;
        CriMovieParsedChunk parsed = { criUsfCmn_GetContents(input->Data, input->Size, &size), size, 0 };
        FUN_140032650(player, slot, (CriUint32*)slot->PrimaryOutput, &parsed);
        --slot->PendingPrimary;
        FUN_140033e60(player, slot);
    }
    return 1;
}

// MS2-FUNCTIONAL: accept decoded subtitle-stream metadata and decrement its pending record count.
// @0x1400341d0
CriBool FUN_1400341d0(void* player, const CriMovieInputChunk* input)
{
    CriMovieStreamSlotsView* state = (CriMovieStreamSlotsView*)player;
    CriMovieStreamSlotView* slot = &state->Ring.Slots[state->Selector.Current];
    if (!slot->Active)
        return 0;
    if (input->Size > 0x1f)
    {
        CriSint32 size = 0;
        CriMovieParsedChunk parsed = { criUsfCmn_GetContents(input->Data, input->Size, &size), size, 0 };
        FUN_140032db0(player, slot, (CriUint32*)slot->SubtitleOutput, &parsed);
        --slot->PendingAlpha;
        FUN_140033e60(player, slot);
    }
    return 1;
}

// MS2-FUNCTIONAL: accept decoded alpha-stream metadata and decrement its pending record count.
// @0x140036d50
CriBool FUN_140036d50(void* player, const CriMovieInputChunk* input)
{
    CriMovieStreamSlotsView* state = (CriMovieStreamSlotsView*)player;
    CriMovieStreamSlotView* slot = &state->Ring.Slots[state->Selector.Current];
    if (!slot->Active)
        return 0;
    if (input->Size > 0x1f)
    {
        CriSint32 size = 0;
        CriMovieParsedChunk parsed = { criUsfCmn_GetContents(input->Data, input->Size, &size), size, 0 };
        FUN_140032b70(player, slot, (CriUint32*)slot->AlphaOutput, &parsed);
        --slot->PendingSubtitle;
        FUN_140033e60(player, slot);
    }
    return 1;
}

// MS2-FUNCTIONAL: initialize a new input stream, reset demux state, and seed the read queue.
// @0x1400361a0
void FUN_1400361a0(void* player, const void* inputData, CriUint32 inputSize)
{
    if (!player)
    {
        FUN_140037950(NULL, "E05121603M : CriMvPly handle is NULL.", 0);
        return;
    }
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)player;
    if (state->Status != 0 && state->Status != 7)
    {
        FUN_140037950(player, "E05121604M : Can't execute start function when CriMvPly handle status is not STOP/PLAYEND.", state->Status);
        return;
    }

    struct StartResetView
    {
        CriUint8 Reserved0[0x10];
        CriUint32 ResetTimer;
        CriUint8 Reserved14[0x8a4];
        CriUint32 HeaderSize;
    };
    struct BufferView { void* Data; CriUint32 Capacity; CriUint32 Reserved; };
    struct StartFlagView { CriUint8 Reserved[0x0c]; CriUint32 Reset; };
    struct StartRingView
    {
        CriUint8 Reserved0[0x2e8];
        CriUint32 SlotState;
        CriUint8 Reserved2[0x2dc];
        CriUint32 SlotCount;
        CriUint8 Reserved3[0x1c];
        CriUint16 CurrentSlot;
        CriUint16 Reserved4;
        CriUint32 SlotFlags;
        CriUint32 Phase;
    };
    ((StartResetView*)player)->ResetTimer = 0;
    ((StartResetView*)player)->HeaderSize = 0;
    memset(((CriMvPlyHeaderAnalysisFields*)player)->AnalyzedHeader, 0, sizeof(((CriMvPlyHeaderAnalysisFields*)player)->AnalyzedHeader));
    FUN_140044fa8(state->Demux, ((CriMvPlyInputQueueFields*)player)->InputBuffer);
    FUN_140044fb0(state->Demux, 0, ((CriMvPlyInputQueueFields*)player)->ReadBuffer, 0, (CriUint32)-1);
    FUN_140044fd8(state->Demux, 0);
    FUN_140044f9c(state->Demux);

    BufferView buffer = {};
    FUN_140046804(((CriMvPlyInputQueueFields*)player)->InputBuffer, &buffer);
    CriUint32 copySize = inputSize < buffer.Capacity ? inputSize : buffer.Capacity;
    if (copySize != 0)
        memcpy(buffer.Data, inputData, copySize);
    FUN_140046814(((CriMvPlyInputQueueFields*)player)->InputBuffer, &buffer, copySize);
    FUN_1400363b0(player, (void*)inputData, inputSize);

    ((CriMvReadBufferState*)player)->Mode = 1;
    memset(((CriMvPlyHeaderAnalysisFields*)player)->CurrentHeader, 0, 0x5c0);
    ((StartRingView*)player)->SlotState = 0;
    ((StartRingView*)player)->SlotCount = 0;
    ((StartRingView*)player)->CurrentSlot = 1;
    ((StartRingView*)player)->SlotFlags = 0;
    ((StartRingView*)player)->Phase = 0;
    ((StartFlagView*)player)->Reset = 0;
    state->Status = 1;
}

// MS2-FUNCTIONAL: replace the pending movie chunk and save the most recently enqueued record.
// @0x1400363b0
void FUN_1400363b0(void* player, void* chunk, CriUint32 type)
{
    CriMovieChunkQueueRecord item;
    CriMovieChunkQueueRecord stale;          // the replaced chunk is popped into its own record
    if ((CriUint32)FUN_1400467b8(((CriMovieQueueView*)player)->Queue, 0) > 0)
        FUN_1400467a0(((CriMovieQueueView*)player)->Queue, 0, -1, &stale);
    item.Chunk = chunk;
    item.Type = type;
    FUN_1400467b0(((CriMovieQueueView*)player)->Queue, 1, &item);
    memcpy(((CriMovieQueueView*)player)->LastChunk, &item, sizeof(item));
}

// MS2-FUNCTIONAL: forward video sizing and stream metadata to the video and alpha decoder interfaces.
// @0x1400377a0
void FUN_1400377a0(void* player, void* videoDecoder, void* alphaDecoder)
{
    FUN_140044d20(videoDecoder, ((CriUint32*)player)[0x8d0 / 4]);
    FUN_140044270(alphaDecoder, ((CriUint32*)player)[0x8d0 / 4]);
    FUN_140044d70(videoDecoder, ((CriUint32*)player)[0x8cc / 4], (CriUint32*)player + 0x8d4 / 4,
                  (CriUint32*)player + 0x9d4 / 4);
    FUN_1400442c0(alphaDecoder, ((CriUint32*)player)[0x8cc / 4], (CriUint32*)player + 0x8d4 / 4,
                  (CriUint32*)player + 0x9d4 / 4);
}

// MS2-FUNCTIONAL: the CRI Movie sub-audio helper forwards the caller's sizing inputs with flags set to zero.
// @0x140030f10
CriBool FUN_140030f10(void* player, void* source, CriUint32 stream)
{
    // The exe passes the stream's 16-byte entry at +0xb2c and reloads the source from the player.
    ((CriMovieAttachView*)player)->AttachedSource = source;
    CriBool attached = FUN_140042270(((CriMovieAttachView*)player)->Manager, player,
                                     ((CriMovieAttachView*)player)->AttachedSource,
                                     &((CriMovieAttachView*)player)->Streams[stream], stream, 1);
    if (!attached)
        return 0;
    if (FUN_140037a10() == 1)
        FUN_140041e30(((CriMovieAttachView*)player)->Manager, FUN_140038000, player, 1);
    return 1;
}

// MS2-FUNCTIONAL: the CRI Movie sub-audio helper sizes the player's audio track work area (exe passes only the two args).
// @0x140030ed0
CriSint32 criMvPly_CalcSubAudioWorkSize(void* player, void* source)
{
    CriSint32 size = 0;
    size = FUN_140042150(player, (const CriUint32*)source);
    return size;
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

// MS2-FUNCTIONAL: configure the movie's read queue, decoder interfaces, audio manager, and output stream.
// @0x140030280
CriUint32 FUN_140030280(void* player, void* heap, void* work)
{
    CriSint32 status = getInternalStatus(player);
    if (status != 0 && status != 2)
    {
        FUN_140037950(player, "E05063010M : Don't call criMvPly_AllocateWorkBuffer() at illigal status.", status);
        return 0;
    }
    if (((CriMvPlyStateTransitionFields*)player)->StartReady == 1)
        FUN_140030c70(player);

    memcpy((CriUint8*)player + 0xad8, ((const CriMvStreamingParameters*)work), sizeof(*((const CriMvStreamingParameters*)work)));
    memcpy((CriUint8*)player + 0xdf0, &heap, sizeof(heap));

    CriUint32 readSize = 0;
    CriUint32 readExtension = 0;
    CriUint32 memoryInput = 0;
    memcpy(&memoryInput, (CriUint8*)player + 0xd60, sizeof(memoryInput));
    if (memoryInput == 0)
    {
        if (((const CriMvStreamingParameters*)work)->read_buffer_size == 0xffffffff)
        {
            readSize = (CriUint32)((float)(((const CriMvStreamingParameters*)work)->max_bitrate / 8) * ((const CriMvStreamingParameters*)work)->buffering_time);
            if (readSize < ((const CriMvStreamingParameters*)work)->min_buffer_size)
                readSize = ((const CriMvStreamingParameters*)work)->min_buffer_size;
        }
        else
            readSize = ((const CriMvStreamingParameters*)work)->read_buffer_size;
        CriUint32 rounded = readSize + 0x800;
        readSize = (rounded / 0x800) * 0x800;
        readExtension = decideReadBufferExtSize((void*)((const CriMvStreamingParameters*)work));
        memcpy((CriUint8*)player + 0xdf8, &readSize, sizeof(readSize));
        memcpy((CriUint8*)player + 0xdfc, &readExtension, sizeof(readExtension));
        void* readBuffer = FUN_140046730(heap, (CriSint32)readSize, (CriSint32)readExtension,
                                         0x40, "CriMvPly: ReadBuf");
        memcpy((CriUint8*)player + 0xd88, &readBuffer, sizeof(readBuffer));
        if (!readBuffer)
        {
            FUN_140037950(player, "E05063012M : Can't create SJ for read buffer.", 0);
            FUN_140030c70(player);
            return 0;
        }
    }
    else
    {
        memcpy((CriUint8*)player + 0xdf8, &readSize, sizeof(readSize));
        memcpy((CriUint8*)player + 0xdfc, &readExtension, sizeof(readExtension));
        void* noBuffer = NULL;
        memcpy((CriUint8*)player + 0xd88, &noBuffer, sizeof(noBuffer));
    }

    if (memoryInput == 0)
    {
        memcpy((CriUint8*)player + 0xe48, &readSize, sizeof(readSize));
        memcpy((CriUint8*)player + 0xe4c, &readExtension, sizeof(readExtension));
        CriMovieInputChunk chunk = {};
        void* readBuffer = NULL;
        memcpy(&readBuffer, (CriUint8*)player + 0xd88, sizeof(readBuffer));
        FUN_1400467a0(readBuffer, 0, -1, &chunk);
        memcpy((CriUint8*)player + 0xe50, &chunk.Data, sizeof(chunk.Data));
        FUN_1400467a8(readBuffer, 0, &chunk);
    }

    if (((const CriMvStreamingParameters*)work)->num_video != 0)
    {
        CriUint32 videoCodec = 0;
        memcpy(&videoCodec, (const CriUint8*)((const CriMvStreamingParameters*)work) + 0x44, sizeof(videoCodec));
        void* decoderInterface = FUN_140030b50((CriSint32)videoCodec);
        if (!decoderInterface)
        {
            FUN_140037950(player, "E11030201M : Not found any avilable codec for the video stream. Attach a codec module before the Initialize function.", 0);
            FUN_140030c70(player);
            return 0;
        }
        CriUint32 codec = 0x40534656;
        CriUint32 zero = 0;
        memcpy((CriUint8*)player + 0xe00, &codec, sizeof(codec));
        memcpy((CriUint8*)player + 0xe04, &zero, sizeof(zero));
        struct DecoderConfig
        {
            CriUint32 Width, Height, PlayerFormat, PlayerPitch, StreamFormat;
            CriUint32 Reserved;
            void* OutputBuffer;
            CriUint32 BufferSize, BufferExtension;
        } videoConfig = {};
        videoConfig.Width = ((const CriMvStreamingParameters*)work)->video_prm[0].max_width;
        videoConfig.Height = ((const CriMvStreamingParameters*)work)->video_prm[0].max_height;
        memcpy(&videoConfig.PlayerFormat, (CriUint8*)player + 0xae4, sizeof(CriUint32));
        memcpy(&videoConfig.PlayerPitch, (CriUint8*)player + 0x640, sizeof(CriUint32));
        videoConfig.StreamFormat = ((const CriMvStreamingParameters*)work)->video_prm[0].num_frame_pools;
        if (memoryInput == 0)
        {
            memcpy(&videoConfig.OutputBuffer, (CriUint8*)player + 0xe50, sizeof(void*));
            memcpy(&videoConfig.BufferSize, (CriUint8*)player + 0xe48, sizeof(CriUint32));
            memcpy(&videoConfig.BufferExtension, (CriUint8*)player + 0xe4c, sizeof(CriUint32));
        }
        void* videoDecoder = FUN_140043af0(decoderInterface, heap, &videoConfig);
        memcpy((CriUint8*)player + 0xe08, &videoDecoder, sizeof(videoDecoder));
        if (!videoDecoder)
        {
            FUN_140037950(player, "E05063013M : Can't create Video decoder.", 0);
            FUN_140030c70(player);
            return 0;
        }
        if (FUN_140037a10() == 1)
            FUN_140044de0(videoDecoder, (void*)FUN_140037a40, player);
        CriUint32 processorMask = 0;
        memcpy(&processorMask, (const CriUint8*)((const CriMvStreamingParameters*)work) + 0x30, sizeof(processorMask));
        FUN_140044c10(videoDecoder, processorMask);

        if (((const CriMvStreamingParameters*)work)->num_alpha == 0)
        {
            void* noAlpha = NULL;
            memcpy((CriUint8*)player + 0xe40, &noAlpha, sizeof(noAlpha));
        }
        else
        {
            CriUint32 alphaCodec = 0;
            memcpy(&alphaCodec, (const CriUint8*)((const CriMvStreamingParameters*)work) + 0x280, sizeof(alphaCodec));
            void* alphaInterface = FUN_140030be0((CriSint32)alphaCodec);
            if (!alphaInterface)
            {
                FUN_140037950(player, "E11030701M : Not found any avilable codec for the alpha stream. Attach a codec module before the Initialize function", 0);
                FUN_140030c70(player);
                return 0;
            }
            DecoderConfig alphaConfig = {};
            alphaConfig.Width = ((const CriMvStreamingParameters*)work)->alpha_prm[0].max_width;
            alphaConfig.Height = ((const CriMvStreamingParameters*)work)->alpha_prm[0].max_height;
            memcpy(&alphaConfig.PlayerFormat, (CriUint8*)player + 0xae4, sizeof(CriUint32));
            memcpy(&alphaConfig.PlayerPitch, (CriUint8*)player + 0x894, sizeof(CriUint32));
            alphaConfig.StreamFormat = ((const CriMvStreamingParameters*)work)->video_prm[0].num_frame_pools;
            memcpy(&alphaConfig.OutputBuffer, (CriUint8*)player + 0xe50, sizeof(void*));
            memcpy(&alphaConfig.BufferSize, (CriUint8*)player + 0xe48, sizeof(CriUint32));
            memcpy(&alphaConfig.BufferExtension, (CriUint8*)player + 0xe4c, sizeof(CriUint32));
            void* alphaDecoder = FUN_140044470(alphaInterface, heap, &alphaConfig);
            memcpy((CriUint8*)player + 0xe40, &alphaDecoder, sizeof(alphaDecoder));
            if (!alphaDecoder)
            {
                FUN_140037950(player, "E08082100M : Can't create Alpha decoder.", 0);
                FUN_140030c70(player);
                return 0;
            }
            if (FUN_140037a10() == 1)
                FUN_140044330(alphaDecoder, (void*)FUN_140037a40, player);
        }
        void* alphaDecoder = NULL;
        memcpy(&alphaDecoder, (CriUint8*)player + 0xe40, sizeof(alphaDecoder));
        FUN_1400377a0(player, videoDecoder, alphaDecoder);
    }

    void* manager = FUN_140041f70(player, heap, ((const CriMvStreamingParameters*)work));
    memcpy((CriUint8*)player + 0xe10, &manager, sizeof(manager));
    if (!manager)
    {
        FUN_140037910(player, "E07090703M : Can't create CriMvPlyAmng handle", 0);
        FUN_140030c70(player);
        return 0;
    }
    if (((const CriMvStreamingParameters*)work)->track_play_audio >= 0)
    {
        const CriUint8* audioInfo = (const CriUint8*)((const CriMvStreamingParameters*)work) + 0x54 +
            (size_t)((const CriMvStreamingParameters*)work)->track_play_audio * 0x10;
        if (!FUN_140042270(manager, player, heap, (void*)audioInfo,
                           (CriUint32)((const CriMvStreamingParameters*)work)->track_play_audio, 0))
        {
            FUN_140030c70(player);
            return 0;
        }
        if (FUN_140037a10() == 1)
            FUN_140041e30(manager, FUN_140038000, player, 0);
    }
    void* output = FUN_1400464c8((CriHeap)heap, 0, 0x40);
    memcpy((CriUint8*)player + 0xe28, &output, sizeof(output));
    if (!output)
    {
        FUN_140037950(player, "E06102501M : Can't create Sj for subtitle data.", 0);
        FUN_140030c70(player);
        return 0;
    }
    memcpy((CriUint8*)player + 0xe34, (const CriUint8*)((const CriMvStreamingParameters*)work) + 0x258, sizeof(CriUint32));
    ((CriMvPlyStateTransitionFields*)player)->StartReady = 1;
    return 1;
}

// MS2-FUNCTIONAL: create the supplied-memory heap, store it in the player, then prepare its work buffers under lock.
// @0x140030e50
CriUint32 criMvPly_AllocateWorkBufferWithWork(void* player, void* memory, CriSint32 size, void* work)
{
    FUN_140037850(player);
    ((CriMvHeapWorkState*)player)->Heap = FUN_140027fec(memory, size);
    CriUint32 result = FUN_140030280(player, ((CriMvHeapWorkState*)player)->Heap, work);
    FUN_140037880(player);
    return result;
}

// MS2-FUNCTIONAL: absent decoder interfaces and missing core functions use the executable's divided-input fallback.
// @0x140037360
CriBool isAvailableDividedInputChunk(void* player)
{
    void* decoder;                           // declared before res: the two share a VC9 slot bucket (see p10/probe)
    void* core;
    CriBool res;
    res = 0;
    decoder = 0;
    core = 0;
    decoder = FUN_140030b50(*(CriSint32*)((CriUint8*)player + 0x44));
    if (!decoder)
        res = 1;
    else if (!(core = FUN_140044e40(decoder)))
        res = 1;
    else if (!*(void**)((CriUint8*)core + 0x10))
        res = 1;
    else
        res = (*(CriBool(__fastcall**)(void))((CriUint8*)core + 0x10))();
    return res;
}

// MS2-FUNCTIONAL: a divided decoder input uses the fixed extension; otherwise retain the configured minimum size.
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

// MS2-FUNCTIONAL: selects the active CRI read buffer and returns its available and bounded sizes.
// @0x140037050
void* FUN_140037050(void* player, CriUint32* available, CriUint32* bounded)
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

// MS2-FUNCTIONAL: report bytes in the current or selected CRI input buffer, including partially consumed chunks.
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

// MS2-FUNCTIONAL: enter the player's lock through the CRI critical-section wrapper.
// @0x140037850
void FUN_140037850(void* player)
{
    FUN_140039f50(*(void**)((CriUint8*)player + 0x20));
}

// MS2-FUNCTIONAL: leave the player's lock through the CRI critical-section wrapper.
// @0x140037880
void FUN_140037880(void* player)
{
    FUN_140039f8c(*(void**)((CriUint8*)player + 0x20));
}

// MS2-FUNCTIONAL: forward CRI's non-state-changing diagnostic through the shared error notifier.
// @0x140037910
void FUN_140037910(void* owner, const char* message, CriSint32 value)
{
    FUN_140038ce4(0, message, value, 0, owner);
}

// MS2-FUNCTIONAL: mark the movie player in error before forwarding the diagnostic.
// @0x140037950
void FUN_140037950(void* owner, const char* message, CriSint32 value)
{
    if (owner)
        ((CriMvErrorState*)owner)->Error = 1;
    FUN_140038ce4(0, message, value, 0, owner);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: convert the decoder's frame metadata into the 0x38-byte output info, taking the dimensions from the
// movie. This is not a plain copy: the decoder's +0x14 moves to +0x1c, and +0x14/+0x18/+0x34 come from the player.
// @0x140035480
void FUN_140035480(void* player, void* destination, const void* source)
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
// MS2-FUNCTIONAL: ask the alpha decoder to copy one frame into the caller's buffers and publish its metadata.
// @0x140035af0
CriBool FUN_140035af0(void* player, void* buffer, CriUint32 format, void* outputInfo)
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
    ret = FUN_140043f70(((CriMvDecoderHandleFields*)player)->AlphaDecoder, &buf, frameInfo);
    if (ret == 0)
    {
        FUN_140037910(NULL, "E08082104M : Cannot copy the alpha frame buffer to user's buffer.", 0);
        return 0;
    }
    FUN_140035480(player, outputInfo, frameInfo);
    return 1;
}

// MS2-FUNCTIONAL: release the alpha decoder frame using its copied frame descriptor when an alpha decoder exists.
// @0x140035a90
CriBool FUN_140035a90(void* player, const CriUint64* frameInfo)
{
    if (!((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        return 0;
    CriUint64 local[10];                     // only the first word is set, as in the exe (0x50-byte frame record)
    local[0] = *frameInfo;
    FUN_140044050(((CriMvDecoderHandleFields*)player)->AlphaDecoder, local);
    return 1;
}

// MS2-FUNCTIONAL: release the main decoder's current frame using the descriptor's first pointer.
// @0x140035a40
CriBool FUN_140035a40(void* player, const CriMvFrameInfo* frameInfo)
{
    void* localFrame[21];
    localFrame[0] = (void*)*(const CriUint64*)frameInfo;
    FUN_140044a30(*(void**)((CriUint8*)player + 0xe08), localFrame);
    return 1;
}

// MS2-FUNCTIONAL: drain and release every queued alpha frame from the player decoder.
// @0x140035bf0
void FUN_140035bf0(void* player)
{
    CriUint64 frameInfo[10];
    void* frame = NULL;
    frame = FUN_140043fe0(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
    while (frame != NULL)
    {
        FUN_140044050(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
        frame = FUN_140043fe0(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
    }
}

// MS2-FUNCTIONAL: forward the player's video decoder and all five caller outputs to its frame-pool query.
// @0x140036ed0
void criMvPly_GetFramePoolInfo(void* player, void* a, void* b, void* c, void* d, void* e)
{
    if (player == NULL)
        return;
    FUN_140044b90(((CriMvDecoderHandleFields*)player)->VideoDecoder, a, b, c, d, e);
}

// MS2-FUNCTIONAL: request the main audio stream's current data size from the movie audio manager.
// @0x1400360c0
CriUint32 criMvPly_GetDataSizeMainAudio(void* player, CriUint32 channels)
{
    CriUint32 size = FUN_140042f00(((CriMvSubAudioHandles*)player)->Manager, 0, player, channels);
    return size;
}

// MS2-FUNCTIONAL: request the secondary audio stream's current data size from the movie audio manager.
// @0x140036100
CriUint32 criMvPly_GetDataSizeSubAudio(void* player, CriUint32 channels)
{
    CriUint32 size = FUN_140042f00(((CriMvSubAudioHandles*)player)->Manager, 1, player, channels);
    return size;
}

// MS2-FUNCTIONAL: query the main audio stream's playback-complete state.
// @0x140036140
void criMvPly_IsEndMainAudioPlayback(void* player)
{
    FUN_140042df0(((CriMvSubAudioHandles*)player)->Manager, player, 0);
}

// MS2-FUNCTIONAL: query the secondary audio stream's playback-complete state.
// @0x140036170
void criMvPly_IsEndSubAudioPlayback(void* player)
{
    FUN_140042df0(((CriMvSubAudioHandles*)player)->Manager, player, 1);
}

// MS2-FUNCTIONAL: detach and clear the secondary audio decoder handle.
// @0x140030fd0
void criMvPly_DetachSubAudio(void* player)
{
    FUN_140042600(((CriMvSubAudioHandles*)player)->Manager, ((CriMvSubAudioHandles*)player)->Decoder, 1);
    ((CriMvSubAudioHandles*)player)->Decoder = NULL;
}

// MS2-FUNCTIONAL: select the next subtitle chunk matching a channel while consuming decoder control records.
// @0x140036b80
CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* output, CriSint32 channel)
{
    CriSint32 consumed = 0;
    memset(output, 0, sizeof(*output));
    if (!player)
        return 0;
    void* queue = ((CriMvSubtitleFields*)player)->Queue;
    if (!queue)
        return 0;

    CriMovieChunkQueueRecord record = {};
    struct SubtitleFrameCounter { CriUint8 Reserved[0xe30]; CriUint32 Value; };
    struct SubtitleMetadataView { CriUint8 Reserved[0x0c]; CriSint32 Channel; };
    CriUint8 parsedHeader[0x24] = {};
    CriUint8 subtitleInfo[0x38] = {};  // FUN_140036f40 fills 0x38 bytes
    while (FUN_1400467b8(queue, 1) != 0)
    {
        FUN_1400467a0(queue, 1, -1, &record);
        if (!record.Chunk)
            return consumed;
        CriUint32 size = record.Type;
        if (size < 0x20)
            return consumed;
        FUN_14003b3fc((const CriUint8*)record.Chunk, size, parsedHeader);
        CriUint8 type = parsedHeader[0x0f];
        if (type == 1 || type == 2)
        {
            if (type == 1)
            {
                CriMovieInputChunk input = { (const CriUint8*)record.Chunk, size, 0 };
                if (!FUN_140036d50(player, &input))
                {
                    FUN_1400467a8(queue, 1, &record);
                    return 0;
                }
                ++((SubtitleFrameCounter*)player)->Value;
            }
            FUN_1400467b0(queue, 0, &record);
        }
        else
        {
            CriMovieInputChunk input = { (const CriUint8*)record.Chunk, size, 0 };
            FUN_140036f40(player, (CriMvSubtitleChunk*)&input, subtitleInfo);
            CriSint32 chunkChannel = ((SubtitleMetadataView*)subtitleInfo)->Channel;
            if (channel == chunkChannel)
            {
                output->Data = (CriUint8*)record.Chunk;
                output->Size = size;
                return consumed;
            }
            FUN_1400467b0(queue, 0, &record);
        }
        ++consumed;
    }
    return consumed;
}

// MS2-FUNCTIONAL: decode a subtitle record and calculate its audio-synchronized presentation position.
// @0x140036f40
void FUN_140036f40(void* player, CriMvSubtitleChunk* chunk, void* outputInfo)
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
    FUN_140044b20(((CriMvDecoderHandleFields*)player)->VideoDecoder,
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
        FUN_140036e80(player, &chunk);
        return;
    }
    FUN_140036f40(player, &chunk, outputInfo);
    FUN_140036e80(player, &chunk);
}

// MS2-FUNCTIONAL: this CRI EasyFileReader utility is the executable's unsigned base-conversion parser.
// @0x140038bd0
CriUint64 FUN_140038bd0(void* reader, const CriChar8* text, CriChar8** end, CriSint32 radix)
{
    (void)reader;                            // the exe passes the reader through (a member call) and ignores it
    return _strtoui64(text, end, radix);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: forward CRI Base's two-argument notification to its shared error dispatch routine.
// @0x140038ddc
void criErr_Notify(CriSint32 category, const CriChar8* message)
{
    FUN_140038ce4(category, message, 0, 0, NULL);
}

// The three-argument notification: the category, message and value go through unchanged (the exe sets only the flags
// and owner).
// @0x140038df8
void FUN_140038df8(CriSint32 category, const CriChar8* message, CriSint32 value)
{
    FUN_140038ce4(category, message, value, 0, NULL);
}

// The four-argument notification: everything but the owner goes through unchanged.
// @0x140038e10
void FUN_140038e10(CriSint32 category, const CriChar8* message, CriSint32 value, CriSint32 flags)
{
    FUN_140038ce4(category, message, value, flags, NULL);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: enter the movie player's shared handle critical section.
// @0x1400378b0
void FUN_1400378b0(void* player)
{
    if (player == player) {}                 // the CRI unused-argument idiom: /Od loads player (the exe's dead load)
    FUN_140039f50(DAT_143ffd550);
}

// MS2-FUNCTIONAL: leave the movie player's shared handle critical section.
// @0x1400378e0
void FUN_1400378e0(void* player)
{
    if (player == player) {}                 // the CRI unused-argument idiom: /Od loads player (the exe's dead load)
    FUN_140039f8c(DAT_143ffd550);
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: publish the executable's CRI Critical Section runtime banner.
// @0x1400385b8
void FUN_1400385b8(void)
{
    DAT_143b27aa8 = "\nCRI Critical Section/PCx64 Ver.1.00.12 Build:Jan 13 2012 19:02:02\n";
}

// MS2-FUNCTIONAL: initialize CRI Error's shared lock and install its initial callback.
// @0x140038ca8
void FUN_140038ca8(void* callback)
{
    FUN_1400411f8();
    DAT_143b27bb0 = "\nCRI Error/PCx64 Ver.1.03.00 Build:Jan 13 2012 19:02:07\n";
    DAT_143b27bb8 = callback;
}

// MS2-FUNCTIONAL: dispatch through the optional callback while temporarily suppressing recursive dispatch, then update the appropriate counter.
// @0x140038ce4
void FUN_140038ce4(CriSint32 category, const char* message, CriSint32 value, CriSint32 flags, void* owner)
{
    FUN_1400411f8();
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

// The error-text lookup; inlined into FUN_140038e24, its early return is the exe's out-of-line found block.
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

// MS2-FUNCTIONAL: find the CRI error text by code, format its message, and send it through the shared dispatcher.
// @0x140038e24
void FUN_140038e24(CriSint32 category, const char* code, CriSint32 error)
{
    const char* description = criErr_GetErrorText(error);
    FUN_140046944(DAT_143b27ab0, 0x100, code);
    FUN_14004698c(DAT_143b27ab0, 0x100, DAT_1431b9820);
    FUN_14004698c(DAT_143b27ab0, 0x100, description);
    FUN_140038ce4(category, DAT_143b27ab0, 0, 0, NULL);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: construct a CRI Movie player and its work queues inside the supplied memory block.
// @0x14002eb20
void* FUN_14002eb20(void* work, CriSint32 workSize)
{
    if (DAT_143ffd500 < 1)
    {
        FUN_140037950(NULL, "E10051202M : criMvPly_Create was called without Initialization.", 0);
        return NULL;
    }
    if (!work || workSize < 0)
    {
        FUN_140037950(NULL, "E10051203M : Passed illegal memory or memory size to criMvPly_Create.", 0);
        return NULL;
    }
    CriFixedAllocator allocator = {};
    criFixedAllocator_Create(work, workSize, &allocator);
    CriUint32* words = (CriUint32*)criFixedAllocator_Allocate(&allocator, 0xf18, 4);
    if (!words)
    {
        FUN_140037950(NULL, "E10051204M : Can't allocate handle object memory.", 0xf18);
        return NULL;
    }
    memset(words, 0, 0xf18);
    struct HeapFields
    {
        CriUint8 Reserved0[0xdc0];
        CriHeap Heap;
        CriUint8 ReservedD28[8];
        void* HeapHandle;
        CriUint8 ReservedD38[8];
        void* LocalWork;
    };
    struct WorkFields { CriUint8 Reserved0[0x18]; void* CriticalWork; void* CriticalSection; };
    HeapFields* heapFields = (HeapFields*)words;
    WorkFields* workFields = (WorkFields*)words;

    workFields->CriticalWork = criFixedAllocator_Allocate(&allocator, 0x48, 4);
    if (!workFields->CriticalWork)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E10051205M : Can't allocate cs handle memory.", 0x48);
        return NULL;
    }
    workFields->CriticalSection = FUN_1400385c8(workFields->CriticalWork, 0x48);
    if (!workFields->CriticalSection)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E10051206M : Can't create CriticalSection for CRI Movie.", 0);
        return NULL;
    }

    words[0x376] = 0x2800;
    void* localBuffer = criFixedAllocator_Allocate(&allocator, 0x2800, 4);
    *(void**)((CriUint8*)words + 0xde0) = localBuffer;
    if (!localBuffer)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E10051207M : Can't allocate internal heap memory.", 0x2800);
        return NULL;
    }
    heapFields->HeapHandle = (void*)FUN_140027fec(localBuffer, 0x2800);
    if (!heapFields->HeapHandle)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E10051208M : Can't create internal heap handle.", 0);
        return NULL;
    }

    CriUint32 rbfConfig[6] = { 1, 0x2800, 0, 0x40, 0, 0 };
    CriSint32 inputSize = criSjRbf_CalculateWorkSize((const CriSint32*)rbfConfig);
    void* inputWork = criFixedAllocator_Allocate(&allocator, inputSize, 4);
    if (!inputWork)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E10051209M : Cannot allocate memory for input SJ to analyze header chunk.", inputSize);
        return NULL;
    }
    CriMvPlyInputQueueFields* queues = (CriMvPlyInputQueueFields*)words;
    queues->InputBuffer = FUN_140045eec(rbfConfig, inputWork, inputSize);
    if (!queues->InputBuffer)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E10051210M : Cannot create input SJ to analyze header chunk.", 0);
        return NULL;
    }

    words[0x35c] = 8;
    CriSint32 demuxSize = FUN_140044eb0(words[0x35c]);
    void* demuxWork = criFixedAllocator_Allocate(&allocator, demuxSize, 4);
    if (!demuxWork)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E10051201M : Cannot allocate memory for for UsfDemux.", demuxSize);
        return NULL;
    }
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)words;
    state->Demux = FUN_140045144((CriSint32)words[0x35c], demuxWork, demuxSize);
    if (!state->Demux)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E05063007M : Can't create UsfDemux Handle.", 0);
        return NULL;
    }

    CriUint32 outputConfig[3] = { 1, 0, 0x40 };
    CriSint32 outputSize = criSjUni_CalculateWorkSize((const CriSint32*)outputConfig);
    void* outputWork = criFixedAllocator_Allocate(&allocator, outputSize, 4);
    if (!outputWork)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E05063008M : Cannot allocate memory for output SJ to analyze header.", outputSize);
        return NULL;
    }
    queues->ReadBuffer = FUN_1400459ec(outputConfig, outputWork, outputSize);
    if (!queues->ReadBuffer)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E05063009M : Can't create output SJ to analyze header.", 0);
        return NULL;
    }

    CriUint32 memoryConfig[3] = { 1, 0, 4 };
    CriSint32 memorySize = criSjUni_CalculateWorkSize((const CriSint32*)memoryConfig);
    void* memoryWork = criFixedAllocator_Allocate(&allocator, memorySize, 4);
    if (!memoryWork)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E11112531M : Cannot allocate memory for input SJ to play from memory.", memorySize);
        return NULL;
    }
    struct MemoryQueueView { CriUint8 Reserved[0xda0]; void* Queue; };
    ((MemoryQueueView*)words)->Queue = FUN_1400459ec(memoryConfig, memoryWork, memorySize);
    if (!((MemoryQueueView*)words)->Queue)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E11112532M : Can't create input SJ to play from memory.", 0);
        return NULL;
    }
    ((CriMvReadBufferState*)words)->Mode = 0;
    FUN_14002f850(words);
    words[0] = 1;
    criMvPly_SetPcmFormat(words, 0);
    FUN_14002e6bc(&allocator);
    return words;
}

// MS2-FUNCTIONAL: estimate CRI Movie work memory for stream buffers and the selected decoders.
// @0x140037400
CriSint32 FUN_140037400(void* player, const CriMvStreamingParameters* params)
{
    const CriUint32* words = (const CriUint32*)params;
    CriUint32 overhead = words[0x2c / 4] + 8 + (params->track_play_audio < 0 ? 0u : 0xdu);
    CriUint32 total = overhead * 0x22 + 0x24;
    CriUint32 inputSize;
    if (params->track_play_audio == -1)
    {
        float estimate = ((float)(params->max_bitrate / 8)) * params->buffering_time;
        inputSize = (CriUint32)estimate;
        if (inputSize < params->min_buffer_size)
            inputSize = params->min_buffer_size;
    }
    else
        inputSize = params->read_buffer_size;

    CriUint32 padded = inputSize + 0x800;
    inputSize = (padded / 0x800) * 0x800;
    CriUint32 tail = decideReadBufferExtSize((void*)params);
    CriUint32 flags[2] = { 1, 1 };
    CriSint32 blockSize = FUN_140046604(inputSize, tail, 0x40, flags);
    total += blockSize;

    if (params->num_video != 0)
    {
        CriUint32 codecId = words[0x44 / 4];
        void* videoCodec = FUN_140030b50((CriSint32)codecId);
        if (!videoCodec)
        {
            FUN_140037950(player, "E11030202M : No available decoder is attached for the video stream. Attach a decoder module before the Initialize function.", 0);
            return -1;
        }
        total += FUN_140044400(videoCodec, words[0x1c / 4], words[0x20 / 4], words[0x28 / 4]);
        if (params->num_alpha != 0)
        {
            void* alphaCodec = FUN_140030be0((CriSint32)words[0x280 / 4]);
            if (!alphaCodec)
            {
                FUN_140037950(player, "E11030702M : Not found any avilable codec for the alpha stream. Attach a codec module before the Initialize function", 0);
                return -1;
            }
            total += FUN_140043a80(alphaCodec, params->alpha_prm[0].max_width,
                                   params->alpha_prm[0].max_height, params->video_prm[0].framerate);
        }
    }
    total += FUN_140041ee0(params);
    if (params->track_play_audio >= 0)
    {
        const CriUint8* audio = (const CriUint8*)params + 0x54 + (size_t)params->track_play_audio * 0x10;
        total += FUN_140042150(player, (const CriUint32*)audio);
    }
    flags[0] = flags[1] = 1;
    return total + FUN_140046420(0, 0x40, flags);
}

// MS2-FUNCTIONAL: copies the CRI decoded frame planes and stream dimensions into the public frame record.
// @0x140035260
void FUN_140035260(void* player, void* output, const void* frameInfo,
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

// MS2-FUNCTIONAL: update playback-frame timing statistics and the public frame-result state.
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
        CriUint64* counters = (CriUint64*)player->playback_info;
        ++counters[5];
        player->last_frame_result = 1;
    }
    else
    {
        if (validFrame == 1)
        {
            CriUint64 currentFrame = *(CriUint64*)player->playback_info;
            CriUint64 difference = currentFrame - player->unk658;
            CriUint64* counters = (CriUint64*)player->playback_info;
            if (difference == 1) ++counters[1];
            else if (difference == 2) ++counters[2];
            else if (difference == 3) ++counters[3];
            else if (difference != 0) ++counters[4];

            CriUint64 systemCount = 0;
            CriUint64 systemUnit = 1;
            player->GetTime(systemCount, systemUnit);
            CriFloat32 currentMs = (CriFloat32)systemCount / (CriFloat32)systemUnit;
            CriFloat32 frameMs = (CriFloat32)count / (CriFloat32)unit;
            CriFloat32 elapsed = (currentMs - frameMs) * 1000.0f;
            CriFloat32* timing = (CriFloat32*)player->playback_info;
            if (timing[14] < elapsed)
                timing[14] = elapsed;
            player->unk660 += elapsed;
            timing[15] = currentFrame == 0 ? player->unk660 : player->unk660 / (CriFloat32)currentFrame;
            player->unk658 = currentFrame;
            player->last_frame_result = 0;
        }
        else if (!player->modules_stopped)
        {
            CriUint64* counters = (CriUint64*)player->playback_info;
            ++counters[6];
            CriMvInputBufferInfo info = {};
            player->GetInputBufferInfo(info);
            player->last_frame_result = 2;
        }
        if (dropped != 0)
            player->last_frame_result = 3;
    }
}

// MS2-FUNCTIONAL: translate the active CRI stream slot into the public streaming-parameter record.
// @0x14002fbe0
void FUN_14002fbe0(void* player, CriMvStreamingParameters* output)
{
    memset(output, 0, sizeof(*output));
    if (((CriMvPlyStateTransitionFields*)player)->Status == 0 || ((CriMvPlyStateTransitionFields*)player)->Status == 1 || ((CriMvPlyStateTransitionFields*)player)->Status == 8 ||
        ((CriMvPlyStateTransitionFields*)player)->Status == 9 || ((CriMvPlyStateTransitionFields*)player)->Status == 10)
        return;

    CriMovieStreamSlotsView* slots = (CriMovieStreamSlotsView*)player;
    CriUint32* stream = NULL;
    if (*(CriUint32*)((CriUint8*)player + 0x5ec) == 0)
        stream = (CriUint32*)((CriMvPlyHeaderAnalysisFields*)player)->AnalyzedHeader;
    else
        stream = (CriUint32*)&slots->Ring.Slots[(*(CriUint32*)((CriUint8*)player + 0x5f0) % 2)];

    ((CriUint32*)output)[1] = *(CriUint32*)((CriUint8*)player + 0x8bc);
    ((CriUint32*)output)[2] = stream[0x0c / 4];
    ((CriUint32*)output)[3] = stream[0x04 / 4];
    ((CriUint32*)output)[4] = stream[0x08 / 4];
    ((CriUint32*)output)[5] = 0xffffffff;
    ((CriUint32*)output)[6] = stream[0x10 / 4];
    if (stream[0x14 / 4] == 0)
    {
        for (CriUint32 i = 7; i <= 0x12; ++i)
            ((CriUint32*)output)[i] = 0;
    }
    else
    {
        ((CriUint32*)output)[7] = stream[0x14 / 4];
        ((CriUint32*)output)[8] = stream[0x18 / 4];
        ((CriUint32*)output)[9] = stream[0x1c / 4];
        ((CriUint32*)output)[10] = stream[0x20 / 4];
        ((CriUint32*)output)[11] = 0;
        ((CriUint32*)output)[12] = stream[0x24 / 4];
        ((CriUint32*)output)[13] = stream[0x28 / 4];
        ((CriUint32*)output)[14] = stream[0x2c / 4];
        ((CriUint32*)output)[15] = stream[0x30 / 4];
        ((CriUint32*)output)[16] = stream[0x34 / 4];
        ((CriUint32*)output)[17] = stream[0x38 / 4];
        ((CriUint32*)output)[18] = stream[0x3c / 4];
    }

    CriUint32 firstAudio = 0xffffffff;
    for (CriUint32 i = 0; i < 0x20; ++i)
    {
        CriUint32* sourceAudio = stream + 0x50 / 4 + i * 4;
        CriUint32* outputAudio = ((CriUint32*)output) + 0x54 / 4 + i * 4;
        if (sourceAudio[1] == 0)
        {
            outputAudio[0] = outputAudio[1] = outputAudio[2] = outputAudio[3] = 0;
        }
        else
        {
            outputAudio[0] = sourceAudio[0];
            outputAudio[1] = sourceAudio[1];
            outputAudio[2] = sourceAudio[2];
            outputAudio[3] = *(CriUint32*)((CriUint8*)player + 0x8c4);
            if (firstAudio == 0xffffffff)
                firstAudio = i;
        }
    }
    output->num_audio = stream[0x4c / 4];
    output->track_play_audio = -1;
    if (output->num_audio != 0)
    {
        CriSint32 selected = *(CriSint32*)((CriUint8*)player + 0x8c8);
        if (selected == 100)
            output->track_play_audio = (CriSint32)firstAudio;
        else if (selected >= 0 && selected < 0x20 &&
                 stream[(0x54 + selected * 0x10) / 4] != 0)
            output->track_play_audio = selected;
    }

    ((CriUint32*)output)[0xa1] = stream[0x40 / 4] != 0;
    if (stream[0x250 / 4] != 0 && stream[0x258 / 4] == 1)
    {
        output->num_subtitle = stream[0x25c / 4];
        output->max_subtitle_size = stream[0x268 / 4];
    }
    output->channel_play_subtitle = -1;
    output->num_alpha = stream[0x270 / 4];
    output->alpha_prm[0].max_width = stream[0x274 / 4];
    output->alpha_prm[0].max_height = stream[0x278 / 4];
    output->alpha_prm[0].disp_width = stream[0x27c / 4];
    output->alpha_prm[0].disp_height = stream[0x280 / 4];
    output->alpha_prm[0].framerate = stream[0x284 / 4];
    output->alpha_prm[0].total_frames = stream[0x288 / 4];
    output->alpha_prm[0].alpha_type = stream[0x28c / 4];
    output->is_playable = 1;
    if (((CriUint32*)output)[0x11] == 2 && DAT_143b27948 == 0)
        output->is_playable = 0;
    // The exe copies eight alpha dwords (0x274-0x290) to +0x264, so the last lands at +0x280; +0x284 keeps the
    // stream[0x40] flag stored above.
    ((CriUint32*)output)[0xa0] = stream[0x290 / 4];
}

// MS2-FUNCTIONAL: derive the 32-byte CRI USM key bytes, their inverted copy and the byte mask from the key seed.
// @0x140038190
void FUN_140038190(const void* key)
{
    uintptr_t seed = (uintptr_t)key;
    CriSint8 signedByte4 = (CriSint8)(seed >> 32);
    CriUint8* bytes = DAT_143b27a48;   // the key bytes, read by the USM decryptor together with the inverted copy
    CriUint8* inverted = DAT_143b27a68;
    CriUint8* mask = DAT_143b27a88;
    bytes[0] = (CriUint8)seed;
    bytes[1] = (CriUint8)(seed >> 8);
    bytes[2] = (CriUint8)(seed >> 16);
    bytes[3] = (CriUint8)((seed >> 24) - 0x34);
    bytes[4] = (CriUint8)(signedByte4 - 7);
    bytes[5] = (CriUint8)((seed >> 40) ^ 0x13);
    bytes[6] = (CriUint8)((seed >> 48) + 0x61);
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
    bytes[20] = (CriUint8)(signedByte4 - 0x39);
    bytes[21] = (CriUint8)(bytes[5] - 0x13);
    bytes[22] = (CriUint8)(bytes[6] ^ 0xf3);
    bytes[23] = (CriUint8)(bytes[19] - bytes[15]);
    bytes[24] = (CriUint8)(bytes[21] + bytes[7]);
    bytes[25] = (CriUint8)('!' - bytes[19]);
    bytes[26] = (CriUint8)(bytes[20] ^ bytes[23]);
    bytes[27] = (CriUint8)(bytes[22] * 2);
    bytes[28] = (CriUint8)(bytes[23] + 0x44);
    bytes[29] = (CriUint8)(bytes[3] + bytes[4]);
    bytes[30] = (CriUint8)(bytes[5] - bytes[22]);
    bytes[31] = (CriUint8)(bytes[29] ^ bytes[19]);
    for (CriUint32 i = 0; i < 0x20; ++i)
        inverted[i] = (CriUint8)(bytes[i] ^ 0xff);
    static const CriUint8 alternate[4] = { 0x55, 0x52, 0x55, 0x43 };
    for (CriUint32 i = 0; i < 0x20; ++i)
        mask[i] = (i % 2 == 0) ? inverted[i] : alternate[(i % 8) / 2];
}

// MS2-FUNCTIONAL: retain the default USM decryption key and update the shared decryptor state.
// @0x1400379e0
void FUN_1400379e0(const void* key)
{
    DAT_143b27a40 = key;
    FUN_140038190(key);
}

// MS2-FUNCTIONAL: register or replace the decoder interfaces associated with a codec id.
// @0x14002e6e0
void FUN_14002e6e0(const CriMvCodecRegistrationEntry* registration)
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

// MS2-FUNCTIONAL: parse an MFS:<hex-address>.<hex-size> memory-file path into its two values.
// @0x1400389f0
CriBool FUN_1400389f0(void* reader, const char* path, CriUint64* size, CriUint64* offset)
{
    // As in the exe: no NULL checks, no length bound on either field, and an empty or
    // non-hex field parses as whatever _strtoui64 makes of it.
    char prefix[] = "MFS:";
    CriUint32 i;
    char text[0x20];
    for (i = 0; i < sizeof(prefix) - 1; ++i)
    {
        if (!path[i] || path[i] != prefix[i])
            return 0;
    }
    memset(text, 0, sizeof(text));
    for (CriSint32 n = 0; path[i] != '.'; ++n, ++i)
    {
        text[n] = path[i];
        if (!path[i])
            return 0;
    }
    *size = FUN_140038bd0(reader, text, NULL, 16);
    ++i;
    memset(text, 0, sizeof(text));
    for (CriSint32 n = 0; path[i]; ++i, ++n)
        text[n] = path[i];
    *offset = FUN_140038bd0(reader, text, NULL, 16);
    return 1;
}

// MS2-FUNCTIONAL: restore the CRI movie player defaults after allocating its working storage.
// @0x14002f850
void FUN_14002f850(void* player)
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

// MS2-FUNCTIONAL: allocate and initialize a CRI Movie player from the caller's Scaleform heap.
// @0x14002f1f0
void* FUN_14002f1f0(CriHeap heap)
{
    if (!DAT_143ffd500 || !heap)
    {
        FUN_140037950(NULL, "E09031803M : criMvPly_Create was called without Initialization.", 0);
        return NULL;
    }
    CriUint32* words = (CriUint32*)FUN_140027ed8(heap, 0xf18, "CriMvPly: HnObj", 4);
    if (!words)
    {
        FUN_140037950(NULL, "E05063001M : Can't allocate handle object memory.", 0xf18);
        return NULL;
    }
    memset(words, 0, 0xf18);
    words[0] = 1;
    struct HeapFields
    {
        CriUint8 Reserved0[0xdc0];
        CriHeap Heap;
        CriUint8 ReservedD28[8];
        void* HeapHandle;
        CriUint8 ReservedD38[8];
        void* LocalWork;
    };
    struct WorkFields { CriUint8 Reserved0[0x18]; void* CriticalWork; void* CriticalSection; };
    HeapFields* heapFields = (HeapFields*)words;
    WorkFields* workFields = (WorkFields*)words;
    heapFields->Heap = heap;
    *(CriHeap*)((CriUint8*)words + 0xde8) = heap;

    workFields->CriticalWork = FUN_140027ed8(heap, 0x48, "CriMvPly: CriCsWork", 4);
    if (!workFields->CriticalWork)
    {
        FUN_140027fb4(heap, words);
        FUN_140037950(NULL, "E08102001M : Can't allocate cs handle memory.", 0x48);
        return NULL;
    }
    workFields->CriticalSection = FUN_1400385c8(workFields->CriticalWork, 0x48);
    if (!workFields->CriticalSection)
    {
        FUN_140027fb4(heap, workFields->CriticalWork);
        FUN_140027fb4(heap, words);
        FUN_140037950(NULL, "E05081501M : Can't create CriticalSection for CRI Movie.", 0);
        return NULL;
    }

    words[0x376] = 0x2800;
    void* localBuffer = FUN_140027ed8(heap, 0x2800, "CriMvPly: LocalHeapBuf", 4);
    *(void**)((CriUint8*)words + 0xde0) = localBuffer;
    if (!localBuffer)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E05063002M : Can't allocate internal heap memory.", 0x2800);
        return NULL;
    }
    heapFields->HeapHandle = (void*)FUN_140027fec(localBuffer, words[0x376]);
    if (!heapFields->HeapHandle)
    {
        FUN_14002f610(words);
        FUN_140037910(NULL, "E05063005M : Can't create internal heap handle.", 0);
        return NULL;
    }
    words[0x372] = 0x2800;
    CriMvPlyInputQueueFields* queues = (CriMvPlyInputQueueFields*)words;
    queues->InputBuffer = FUN_140046730(heap, words[0x372], 0, 0x40, "CriMvPly: HeadAnalyInput");
    if (!queues->InputBuffer)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E05063006M : Can't create input SJ for header analyze input.", 0);
        return NULL;
    }
    words[0x35c] = 8;
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)words;
    state->Demux = FUN_1400452b4(heap, words[0x35c]);
    if (!state->Demux)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E05063007M : Can't create UsfDemux Handle.", 0);
        return NULL;
    }
    queues->ReadBuffer = FUN_1400464c8(heap, 0, 0x40);
    if (!queues->ReadBuffer)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E05063008M : Can't create output SJ for analyze header output.", 0);
        return NULL;
    }
    words[0x35d] = 0;
    struct MemoryQueueView { CriUint8 Reserved[0xda0]; void* Queue; };
    MemoryQueueView* memoryQueue = (MemoryQueueView*)words;
    memoryQueue->Queue = FUN_1400464c8(heap, 1, 4);
    if (!memoryQueue->Queue)
    {
        FUN_14002f610(words);
        FUN_140037950(NULL, "E05070601M : Can't create SJ for memory playback.", 0);
        return NULL;
    }
    ((CriMvReadBufferState*)words)->Mode = 0;
    FUN_14002f850(words);
    words[0] = 1;
    criMvPly_SetPcmFormat(words, 0);
    return words;
}

// MS2-FUNCTIONAL: release decoder queues, demux state, and heap-owned CRI Movie work areas.
// @0x14002f610
void FUN_14002f610(CriUint32* object)
{
    if (!object)
        return;
    object[0] = 0;   // the exe clears the first dword before the status check; Status is left as is
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)object;
    struct OwnedHeapFields
    {
        CriUint8 Reserved0[0xdc0];
        CriHeap Heap;
        CriUint8 ReservedD28[8];
        void* HeapHandle;
        CriUint8 ReservedD38[8];
        void* Work;
    };
    struct ObjectFields
    {
        CriUint8 Reserved0[0x18];
        void* Work;
        void* Reader;
    };
    if (state->Status != 0 && state->Status != 7)
        FUN_140037950(object, "E05063009M : Don't call criMvPly_Destroy() at illigal status", state->Status);
    FUN_140030c70(object);
    FUN_140031f00(object);
    if (((CriMvPlyInputQueueFields*)object)->ReadBuffer)
    {
        FUN_140046784(((CriMvPlyInputQueueFields*)object)->ReadBuffer);
        ((CriMvPlyInputQueueFields*)object)->ReadBuffer = NULL;
    }
    if (state->Demux)
    {
        FUN_140044f28(state->Demux);
        state->Demux = NULL;
    }
    if (((CriMvPlyInputQueueFields*)object)->InputBuffer)
    {
        FUN_140046784(((CriMvPlyInputQueueFields*)object)->InputBuffer);
        ((CriMvPlyInputQueueFields*)object)->InputBuffer = NULL;
    }
    struct MemoryQueueView { CriUint8 Reserved[0xda0]; void* Queue; };
    if (((MemoryQueueView*)object)->Queue)
    {
        FUN_140046784(((MemoryQueueView*)object)->Queue);
        ((MemoryQueueView*)object)->Queue = NULL;
    }
    OwnedHeapFields* heapFields = (OwnedHeapFields*)object;
    if (heapFields->HeapHandle)
    {
        FUN_140028074(heapFields->HeapHandle);
        heapFields->HeapHandle = NULL;
    }
    ObjectFields* owned = (ObjectFields*)object;
    if (owned->Reader)
    {
        void* reader = owned->Reader;
        owned->Reader = NULL;
        FUN_140039f00(reader);
    }
    if (heapFields->Heap && heapFields->Work)
    {
        void* work = heapFields->Work;
        heapFields->Work = NULL;
        FUN_140027fb4(heapFields->Heap, work);
    }
    if (heapFields->Heap && owned->Work)
    {
        void* work = owned->Work;
        owned->Work = NULL;
        FUN_140027fb4(heapFields->Heap, work);
    }
    if (heapFields->Heap)
        FUN_140027fb4(heapFields->Heap, object);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: initialize CRI Movie on the first reference and maintain its process reference count.
// @0x14002e7d0
void FUN_14002e7d0(void)
{
    DAT_143b27940 = "\ncriMvPly/PCx64 Ver.3.07.01 Build:Jan 20 2012 18:13:29\n";
    if (DAT_143ffd500 == 0)
    {
        CriSint32 i;
        memset(&DAT_143ffd500, 0, 0x58);
        FUN_140044e84();
        FUN_140039fc8();
        for (i = 0; i < DAT_143b2794c; ++i)
        {
            FUN_140044390(((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].VideoDecoderInterface);
            FUN_140043a20(((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].AlphaDecoderInterface);
        }
        FUN_140041ea0();
        DAT_143ffd550 = FUN_1400385c8(DAT_143ffd504, 0x48);
        if (!DAT_143ffd550)
            FUN_140037910(NULL, "E07020200M : Can't create critical section handle for library work.", 0);
    }
    ++DAT_143ffd500;
}

// MS2-FUNCTIONAL: release CRI Movie subsystems and decoder registrations on the final reference.
// @0x14002e8c0
void FUN_14002e8c0(void)
{
    --DAT_143ffd500;
    if (DAT_143ffd500 == 0)
    {
        CriSint32 i;
        FUN_140041ec0();
        for (i = 0; i < DAT_143b2794c; ++i)
        {
            FUN_140043a50(((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].AlphaDecoderInterface);
            FUN_1400443d0(((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].VideoDecoderInterface);
            ((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].CodecId = 0;
            ((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].VideoDecoderInterface = NULL;
            ((CriMvCodecRegistrationEntry*)DAT_143b27950)[i].AlphaDecoderInterface = NULL;
        }
        DAT_143b2794c = 0;
        FUN_14003a010();
        FUN_140044ea8();
        if (DAT_143ffd550 != NULL)
        {
            void* lock = DAT_143ffd550;
            FUN_140039f00(lock);
            DAT_143ffd550 = NULL;
        }
    }
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: find the registered video decoder interface, mapping codec zero to codec one.
// @0x140030b50
void* FUN_140030b50(CriSint32 codecId)
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

// MS2-FUNCTIONAL: find the registered alpha decoder interface, mapping codec zero to codec one.
// @0x140030be0
void* FUN_140030be0(CriSint32 codecId)
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

// MS2-FUNCTIONAL: service subtitles, header preparation, frame queues and audio for active players.
// @0x14002fb70
void FUN_14002fb70(void* player)
{
    CriSint32 status = getInternalStatus(player);
    if (status == 0 || status == 9 || status == 7 || status == 6)
        return;
    FUN_140036650(player);
    FUN_140036710(player);
    FUN_1400369e0(player);
    FUN_140034c20(player);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: report whether a default USM decryption key has been configured.
// @0x140037a10
CriBool FUN_140037a10(void)
{
    return DAT_143b27a40 == NULL ? 0 : 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: lock the player handle, apply its pending start transition, then unlock it.
// @0x140031100
void FUN_140031100(void* player)
{
    FUN_140037850(player);
    FUN_140031140(player);
    FUN_140037880(player);
}

// MS2-FUNCTIONAL: drain the two CRI input streams into the decoder read queue and return consumed tails.
// @0x140034330
void FUN_140034330(void* player, void* source, void* readBuffer, void* dataQueue)
{
    struct ReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; };
    if (((ReadModeView*)player)->Mode != 0)
        return;

    struct ChunkView { void* Data; CriUint32 Size; } chunk = {};
    struct BufferView { void* Data; CriUint32 Capacity; } buffer = {};
    CriSint32 copied = 0;
    while (FUN_1400467b8(readBuffer, 2) != 0)
        FUN_1400467a0(readBuffer, 2, -1, &chunk);

    while (FUN_1400467b8(readBuffer, 1) != 0)
    {
        FUN_140046804(dataQueue, &buffer);
        FUN_1400467a0(readBuffer, 1, -1, &chunk);
        if (buffer.Capacity < chunk.Size)
            FUN_140037910(player, "E08120301M : Illigal data size of analize header against demux data line.", buffer.Capacity);
        memcpy(buffer.Data, chunk.Data, chunk.Size);
        copied += chunk.Size;
        FUN_140046814(dataQueue, &buffer, chunk.Size);
    }

    while (FUN_1400467b8(source, 1) != 0)
    {
        FUN_140046804(dataQueue, &buffer);
        FUN_1400467a0(source, 1, -1, &chunk);
        if (buffer.Capacity < chunk.Size)
            FUN_140037910(player, "E08120302M : Illigal data size in read buffer data line of analize header.", buffer.Capacity);
        memcpy(buffer.Data, chunk.Data, chunk.Size);
        copied += chunk.Size;
        FUN_140046814(dataQueue, &buffer, chunk.Size);
        FUN_1400467b0(source, 0, &chunk);
    }
    (void)copied;
}

// MS2-FUNCTIONAL: validate the CRI Movie signature, reset the demux, and start ready decoders.
// @0x140034730
void FUN_140034730(void* player)
{
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)player;
    struct HeaderGateView { CriUint8 Reserved[0xd64]; CriSint32 HeaderChecked; };
    struct HeaderSizeView { CriUint8 Reserved[0x8b8]; CriUint32 Size; };
    void* demux = state->Demux;
    if (FUN_140044f8c(demux) == 4)
        crimvply_transitErrorState(player, (void*)"Status of demux is ERROR.");
    else if (state->Status != 2)
    {
        if (((HeaderGateView*)player)->HeaderChecked == 0 && state->Status == 1 &&
            ((HeaderSizeView*)player)->Size == 0)
        {
            CriMovieChunkQueueRecord record = {};
            FUN_1400467a0(((CriMvPlyInputQueueFields*)player)->InputBuffer, 1, -1, &record);
            if (!record.Chunk || record.Type < 4)
            {
                FUN_1400467a8(((CriMvPlyInputQueueFields*)player)->InputBuffer, 1, &record);
                return;
            }
            const CriUint8* signature = (const CriUint8*)record.Chunk;
            if (signature[0] != 'C' || signature[1] != 'R' ||
                signature[2] != 'I' || signature[3] != 'D')
            {
                FUN_1400467a8(((CriMvPlyInputQueueFields*)player)->InputBuffer, 1, &record);
                FUN_140037950(player, "E07020701M: Input is not CRI Movie data.", 0);
                return;
            }
            FUN_1400467a8(((CriMvPlyInputQueueFields*)player)->InputBuffer, 1, &record);
            ((HeaderGateView*)player)->HeaderChecked = 1;
        }
        if (((HeaderGateView*)player)->HeaderChecked == 1)
            FUN_1400458b8(demux);
        if (FUN_140044f8c(demux) == 2)
        {
            FUN_140042880(((CriMvDecoderHandleFields*)player)->AudioManager);
            if (((CriMvDecoderHandleFields*)player)->VideoDecoder)
            {
                FUN_140044790(((CriMvDecoderHandleFields*)player)->VideoDecoder);
                if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
                    FUN_140043e20(((CriMvDecoderHandleFields*)player)->AlphaDecoder);
            }
        }
    }
}

// MS2-FUNCTIONAL: parse sample rate, channel count, sample count, and buffer size from an audio header.
// @0x140032a70
void FUN_140032a70(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    CriUint32 suggestedSize4;
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    output[0] = FUN_14003a85c(document, 0, "sampling_rate");
    output[1] = FUN_14003a85c(document, 0, "num_channels");
    output[2] = FUN_14003a85c(document, 0, "total_samples");
    output[3] = FUN_14003a85c(document, 0, "ixsize");
    suggestedSize4 = FUN_14003a85c(document, 0, "ixsize\0");   // the same name; the exe keeps a second copy (0x143a47288)
    if (suggestedSize4 > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = suggestedSize4;
    criUtfRtv_Destroy((CriUint64*)document);
}

// parse channel and time-base metadata for a CRI Movie stream record.
// @0x140032b70
void FUN_140032b70(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    output[1] = FUN_14003a85c(document, 0, "num_channels");
    ((CriUint64*)output)[1] = FUN_14003a85c(document, 0, "time_unit");
    output[4] = 0x400;
    CriUint32 ixsize = FUN_14003a85c(document, 0, "ixsize");
    if (ixsize > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = ixsize;
    if (output[1] > 0 && ((CriUint64*)output)[1] > 0 && output[4] > 0)
        output[0] = 1;
    criUtfRtv_Destroy((CriUint64*)document);
}

// parse the cue metadata header and raise the required working-buffer size.
// @0x140032c70
void FUN_140032c70(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    output[1] = FUN_14003a85c(document, 0, "metadata_count");
    output[2] = FUN_14003a85c(document, 0, "metadata_size");
    output[3] = FUN_14003a85c(document, 0, "total_points");
    ((CriUint64*)output)[2] = FUN_14003a85c(document, 0, "time_unit");
    CriUint32 ixsize = FUN_14003a85c(document, 0, "ixsize");
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
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    CriUint32 rateNum = FUN_14003a85c(document, 0, "framerate_n");
    CriUint32 rateDenom = FUN_14003a85c(document, 0, "framerate_d");
    output[4] = (CriUint32)(((float)rateNum * 1000.0f) / (float)rateDenom);
    output[5] = FUN_14003a85c(document, 0, "total_frames");
    output[0] = FUN_14003a85c(document, 0, "width");
    output[1] = FUN_14003a85c(document, 0, "height");
    CriUint32 ixsize = FUN_14003a85c(document, 0, "ixsize");
    if (ixsize > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = ixsize;
    if (FUN_14003a3e0(document, "pre_padding") > 0)
        output[10] = FUN_14003a85c(document, 0, "pre_padding\0");   // the exe obj has its own copy of the literal
    else
        output[10] = 0x40;
    output[6] = FUN_14003a85c(document, 0, "alpha_type");
    output[7] = FUN_14003a85c(document, 0, "mpeg_codec");
    output[8] = FUN_14003a85c(document, 0, "metadata_count");
    output[9] = FUN_14003a85c(document, 0, "metadata_size");
    output[2] = FUN_14003a85c(document, 0, "disp_width");
    if (output[2] == 0)
        output[2] = output[0];
    output[3] = FUN_14003a85c(document, 0, "disp_height");
    if (output[3] == 0)
        output[3] = output[1];
    criUtfRtv_Destroy((CriUint64*)document);
}
#pragma optimize("", on)

// FUN_140033810's unaligned field accessors on the player state.
inline CriUint32 cri02c_Get32(CriUint8* state, size_t offset) { CriUint32 value; memcpy(&value, state + offset, sizeof(value)); return value; }
inline void* cri02c_GetPtr(CriUint8* state, size_t offset) { void* value; memcpy(&value, state + offset, sizeof(value)); return value; }
inline void cri02c_Put32(CriUint8* state, size_t offset, CriUint32 value) { memcpy(state + offset, &value, sizeof(value)); }

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: start demuxing for the prepared movie, push the stream headers to the
// decoders, and move the player to READY once enough frames are decoded.
// @0x140033810
void FUN_140033810(void* player)
{
    CriUint8* state = (CriUint8*)player;
    void* demux = cri02c_GetPtr(state, 0xd68);
    void* videoDecoder = cri02c_GetPtr(state, 0xe08);
    void* alphaDecoder = cri02c_GetPtr(state, 0xe40);
    if (cri02c_Get32(state, 0xad4) != 1)
        return;

    void* output = cri02c_Get32(state, 0xd60) == 0 ? cri02c_GetPtr(state, 0xd88) : cri02c_GetPtr(state, 0xda0);
    if (FUN_140044f8c(demux) == 0)
    {
        if (cri02c_Get32(state, 0xd60) == 1)
        {
            void* memoryInput = cri02c_GetPtr(state, 0xda0);
            FUN_140046798(memoryInput);
            FUN_1400467b0(memoryInput, 1, state + 0xda8);
            CriMovieInputChunk chunk;
            FUN_1400467a0(memoryInput, 1, (CriSint32)cri02c_Get32(state, 0xdb8), &chunk);
            FUN_1400467b0(memoryInput, 0, &chunk);
        }
        FUN_140044fa8(demux, output);
        FUN_140046798(cri02c_GetPtr(state, 0xd80));
        FUN_1400345e0(player, cri02c_GetPtr(state, 0xd80), 0x43524944, 0xffffffff);
        FUN_140041df0(cri02c_GetPtr(state, 0xe10), (void*)FUN_140033d70, player);
        FUN_140044cc0(videoDecoder, (void*)FUN_1400340f0, player);
        if (videoDecoder)
        {
            void* inputSj = (void*)FUN_1400445d0((CriUint64*)videoDecoder);
            if (inputSj == NULL)
                FUN_140037910(player, "E05063022M : Can't get input SJ of Video decoder.", 0);
            FUN_1400345e0(player, inputSj, cri02c_Get32(state, 0xe00), cri02c_Get32(state, 0xe04));
            FUN_140044710(videoDecoder);
            FUN_140044c60(videoDecoder, cri02c_Get32(state, 0xe5c), cri02c_Get32(state, 0xe58) - cri02c_Get32(state, 0xe5c));
            cri02c_Put32(state, 0xe30, 0);
            if (alphaDecoder)
            {
                if (cri02c_Get32(state, 0x884) == 1)
                    FUN_140044210((CriUint64*)cri02c_GetPtr(state, 0xe40), (void*)FUN_1400341d0, player);
                void* alphaInputSj = FUN_140043c50((void**)alphaDecoder);
                if (alphaInputSj == NULL)
                    FUN_140037910(player, "E08082103M : Can't get input SJ of Alpha decoder.", 0);
                FUN_1400345e0(player, alphaInputSj, cri02c_Get32(state, 0xe38), cri02c_Get32(state, 0xe3c));
                FUN_140043d90(alphaDecoder);
                FUN_1400441b0((CriUint64*)alphaDecoder, cri02c_Get32(state, 0xe60), cri02c_Get32(state, 0xe58) - cri02c_Get32(state, 0xe60));
            }
        }
        if (cri02c_GetPtr(state, 0xe10))
            FUN_140042700(cri02c_GetPtr(state, 0xe10), player);
        if (cri02c_GetPtr(state, 0xe28))
            FUN_1400345e0(player, cri02c_GetPtr(state, 0xe28), 0x40534254, 0);
        FUN_140044fd8(demux, 1);
        FUN_140044f9c(demux);
        if (cri02c_Get32(state, 0x10) == 1)
            FUN_140044fdc(demux);
    }

    if (videoDecoder)
    {
        CriSint32 status = FUN_140044630(videoDecoder);
        if (status == 1 || status == 0)
            return;
        CriUint32 required = cri02c_Get32(state, 0xed8) != 0xffffffff ? cri02c_Get32(state, 0xed8) : cri02c_Get32(state, 0xb04);
        if (FUN_140044820(videoDecoder) < required && FUN_1400447d0(videoDecoder) > 0)
            return;
        if ((CriSint32)cri02c_Get32(state, 0xe58) > 0 && cri02c_Get32(state, 0xe64) != 1)
            return;
        if (cri02c_GetPtr(state, 0xe40))
        {
            CriSint32 alphaStatus = FUN_140043cb0(cri02c_GetPtr(state, 0xe40));
            if (alphaStatus == 1 || alphaStatus == 0)
                return;
            if (FUN_140043eb0(cri02c_GetPtr(state, 0xe40)) < required && FUN_140043e60(cri02c_GetPtr(state, 0xe40)) > 0)
                return;
        }
    }
    if (FUN_140042cf0(cri02c_GetPtr(state, 0xe10), player) == 1)
        cri02c_Put32(state, 0x4, 4);
}

// MS2-FUNCTIONAL: apply the rolling CRI USM mask and its eight-block prefix transform to a chunk.
// @0x140037a40
void FUN_140037a40(const CriMovieInputChunk* current, const CriMovieInputChunk* previous, void* player)
{
    if (!current || !current->Data || current->Size < 0x40)
        return;
    CriUsfStandardHeader header = {};
    FUN_14003b3fc(current->Data, current->Size, &header);
    CriSint32 contentSize = 0;
    const CriUint8* contents = criUsfCmn_GetContents(current->Data, current->Size, &contentSize);
    if (!contents || contentSize <= 0)
        return;

    CriUint32 headerLength = header.Data[9];
    CriUint16 carriedLength16 = 0;
    memcpy(&carriedLength16, header.Data + 10, sizeof(carriedLength16));
    CriUint32 carriedLength = carriedLength16;
    CriUint32 previousLength = previous ? previous->Size : carriedLength;
    CriSint32 dataLength = (CriSint32)current->Size - 0x40 - (CriSint32)headerLength - (CriSint32)previousLength;
    CriSint32 transformLength = (CriSint32)current->Size - 0x40 - (CriSint32)headerLength - (CriSint32)carriedLength;
    if (transformLength <= 0x1ff || dataLength <= 0)
        return;

    CriUint8* data = (CriUint8*)contents + 0x40;
    CriUint8 rolling[0x20];
    CriUint8 prefixMask[0x20];
    CriUint8 feedback[0x20];
    memcpy(rolling, DAT_143b27a68, sizeof(rolling));
    memcpy(prefixMask, DAT_143b27a48, sizeof(prefixMask));
    memcpy(feedback, DAT_143b27a68, sizeof(feedback));

    for (CriUint32 offset = 0x100; offset < (CriUint32)transformLength; offset += 0x20)
    {
        for (CriUint32 i = 0; i < 0x20 && offset + i < (CriUint32)transformLength; ++i)
        {
            CriUint8* byte = data + offset + i;
            if (previous && offset + i >= (CriUint32)previousLength)
                byte = (CriUint8*)previous->Data + offset + i - previousLength;
            *byte ^= rolling[i];
            rolling[i] = *byte ^ feedback[i];
        }
    }

    for (CriUint32 round = 0; round < 8; ++round)
    {
        const CriUint8* block = data + 0x100 + round * 0x20;
        for (CriUint32 i = 0; i < 0x20; ++i)
            prefixMask[i] ^= block[i];
        for (CriUint32 i = 0; i < 0x20; ++i)
            data[round * 0x20 + i] ^= prefixMask[i];
    }

    if (previous)
    {
        CriUint8* buffer = NULL;
        CriUint32 prefix = 0, copyLength = 0;
        memcpy(&buffer, (CriUint8*)player + 0xe50, sizeof(buffer));
        memcpy(&prefix, (CriUint8*)player + 0xe48, sizeof(prefix));
        memcpy(&copyLength, (CriUint8*)player + 0xe4c, sizeof(copyLength));
        if (buffer && copyLength)
            memmove(buffer, buffer + prefix, copyLength);
    }
}

// MS2-FUNCTIONAL: consume USF metadata records and retain the seek, cue, and VFS table records.
// @0x140033030
CriBool FUN_140033030(void* player)
{
    CriMvPlyObj* movie = (CriMvPlyObj*)player;
    void* queue = NULL;
    memcpy(&queue, (CriUint8*)player + 0xd80, sizeof(queue));
    CriBool foundEnd = 0;
    CriMovieInputChunk chunk = {};
    for (;;)
    {
        if (FUN_1400467b8(queue, 1) == 0)
            return foundEnd;
        chunk = CriMovieInputChunk();
        FUN_1400467a0(queue, 1, -1, &chunk);
        if (chunk.Size < 0x20)
        {
            FUN_1400467a8(queue, 1, &chunk);
            continue;
        }

        CriUsfStandardHeader header = {};
        FUN_14003b3fc(chunk.Data, chunk.Size, &header);
        CriSint32 contentSize = 0;
        const CriUint8* contents = criUsfCmn_GetContents(chunk.Data, chunk.Size, &contentSize);
        CriUint32 tableId = 0;
        memcpy(&tableId, header.Data, sizeof(tableId));
        CriUint8 recordType = header.Data[15];
        if (recordType == 0)
        {
            FUN_1400467a8(queue, 1, &chunk);
            return 1;
        }
        if (recordType == 3)
        {
            CriUint32* metadataRecords = (CriUint32*)((CriUint8*)player + 0xe80);
            ++*metadataRecords;
            if (tableId == 0x40414c50)
            {
                memcpy((CriUint8*)player + 0xe98, &contents, sizeof(contents));
                memcpy((CriUint8*)player + 0xea0, &contentSize, sizeof(contentSize));
                void* table = FUN_14003b348(movie->utf_heap, contents, (CriUint32)contentSize);
                CriUint32 count = (CriUint32)FUN_14003a45c(table);
                memcpy((CriUint8*)player + 0xea4, &count, sizeof(count));
                criUtfRtv_Destroy((CriUint64*)table);
            }
            else if (tableId == 0x40435545)
            {
                // @CUE: fill the event table (allocated by FUN_140031da0) with each cue point's name, time,
                // type and parameter.
                struct EventLimitView { CriUint8 Reserved[0x8ac]; CriUint32 Count; CriUint64 TimeUnit; };
                memcpy((CriUint8*)player + 0xea8, &contents, sizeof(contents));
                memcpy((CriUint8*)player + 0xeb0, &contentSize, sizeof(contentSize));
                void* table = FUN_14003b348(movie->utf_heap, contents, (CriUint32)contentSize);
                movie->cuepoint.num_eventpoint = (CriUint32)FUN_14003a45c(table);
                if (movie->cuepoint.num_eventpoint < ((const EventLimitView*)player)->Count)
                    for (;;) {}
                CriSint32 nameField = FUN_14003a3e0(table, "name");
                CriSint32 paramField = FUN_14003a3e0(table, "parameter");
                CriSint32 timeField = FUN_14003a3e0(table, "time");
                for (CriUint32 i = 0; i < movie->cuepoint.num_eventpoint; ++i)
                {
                    CriUtfRtvCell cell;
                    FUN_14003af50(table, i, nameField, &cell);
                    CriMvEventPoint* event = &movie->cuepoint.eventtable[i];
                    CriChar8* data = NULL;
                    CriUint32 size = 0;
                    memcpy(&data, cell.Value, sizeof(data));
                    memcpy(&size, cell.Value + 8, sizeof(size));
                    event->size_name = size;
                    event->cue_name = size ? data : NULL;
                    event->time = (CriUint64)FUN_14003a648(table, i, timeField);
                    event->tunit = ((const EventLimitView*)player)->TimeUnit;
                    event->type = FUN_14003a894(table, i, "cue_type");
                    FUN_14003af50(table, i, paramField, &cell);
                    memcpy(&data, cell.Value, sizeof(data));
                    memcpy(&size, cell.Value + 8, sizeof(size));
                    event->size_param = size;
                    event->param_string = size ? data : NULL;
                    event->cnt_callback = 0;
                }
                criUtfRtv_Destroy((CriUint64*)table);
            }
            else if (tableId == 0x40534656)
            {
                memcpy((CriUint8*)player + 0xe88, &contents, sizeof(contents));
                memcpy((CriUint8*)player + 0xe90, &contentSize, sizeof(contentSize));
                void* table = FUN_14003b348(movie->utf_heap, contents, (CriUint32)contentSize);
                CriUint32 count = (CriUint32)FUN_14003a45c(table);
                memcpy((CriUint8*)player + 0xe94, &count, sizeof(count));
                criUtfRtv_Destroy((CriUint64*)table);
            }
        }
        else if (recordType == 2)
        {
            CriUint32 parsedCount = 0;
            memcpy(&parsedCount, (CriUint8*)player + 0xe80, sizeof(parsedCount));
            if (parsedCount != 0)
                foundEnd = 1;
        }
        FUN_1400467b0(queue, 2, &chunk);
        if (foundEnd)
            break;
    }

    CriUint32 memoryInputMode = 0;
    memcpy(&memoryInputMode, (CriUint8*)player + 0xd60, sizeof(memoryInputMode));
    if (memoryInputMode == 1)
    {
        CriUint64 inputPosition = 0;
        memcpy(&inputPosition, (CriUint8*)player + 0xda8, sizeof(inputPosition));
        CriUint32 consumed = (CriUint32)((CriUint32)(uintptr_t)chunk.Data - (CriUint32)inputPosition + chunk.Size);
        memcpy((CriUint8*)player + 0xdb8, &consumed, sizeof(consumed));
    }
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: parse one indexed CRI stream record and update its pending-record count.
// @0x140033d70
CriBool FUN_140033d70(void* player, const CriMovieInputChunk* input, CriUint8 outputIndex)
{
    CriMovieStreamSlotsView* state = (CriMovieStreamSlotsView*)player;
    CriMovieStreamSlotView* slot = &state->Ring.Slots[state->Selector.Current];
    if (!slot->Active)
        return 0;
    if (input->Size > 0x1f)
    {
        CriSint32 size = 0;
        CriMovieParsedChunk parsed = { criUsfCmn_GetContents(input->Data, input->Size, &size), size, 0 };
        CriUint32* streamOutput = (CriUint32*)((CriUint8*)slot + 0x50 + (size_t)outputIndex * 0x10);
        FUN_140032a70(player, slot, streamOutput, &parsed);
        --slot->Reserved2C4;
        FUN_140033e60(player, slot);
    }
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: compare video stream information and, when enabled, every plane's size pair.
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

// MS2-FUNCTIONAL: finish a stream slot once all its metadata records have arrived and rotate buffers.
// @0x140033e60
void FUN_140033e60(void* player, CriMovieStreamSlotView* slot)
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
        FUN_140037950(player, "E07092101M: Entried movie file can not be concatenated with playing file.", 0);
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
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    CriUint32 nLayout;
    if (FUN_14003a3e0(document, s_apszVideoHeaderColumns[0][0]) > 0)
    {
        output[9] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[0][0]);
        nLayout = 0;
    }
    else if (FUN_14003a3e0(document, s_apszVideoHeaderColumns[0][1]) > 0)
    {
        output[9] = 3;
        nLayout = 1;
    }
    else
    {
        output[9] = 0;
        nLayout = 0;
    }

    CriUint32 fpsNum = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[1][nLayout]);
    CriUint32 fpsDenom = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[2][nLayout]);
    output[4] = (CriUint32)(((float)fpsNum * 1000.0f) / (float)fpsDenom);
    output[5] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[3][nLayout]);
    output[0] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[4][nLayout]);
    output[1] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[5][nLayout]);
    CriUint32 ixsize = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[6][nLayout]);
    if (ixsize > ((WorkSizeView*)workInfo)->Size)
        ((WorkSizeView*)workInfo)->Size = ixsize;
    if (FUN_14003a3e0(document, s_apszVideoHeaderColumns[7][nLayout]) > 0)
        output[13] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[7][nLayout]);
    else
        output[13] = 0x40;
    output[6] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[8][nLayout]);
    if (output[6] == 0)
        output[6] = output[0];
    output[7] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[9][nLayout]);
    if (output[7] == 0)
        output[7] = output[1];
    output[8] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[10][nLayout]);
    output[10] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[11][nLayout]);
    output[11] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[12][nLayout]);
    output[12] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[13][nLayout]);
    output[2] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[14][nLayout]);
    if (output[2] == 0)
        output[2] = output[0];
    output[3] = FUN_14003a85c(document, 0, s_apszVideoHeaderColumns[15][nLayout]);
    if (output[3] == 0)
        output[3] = output[1];
    criUtfRtv_Destroy((CriUint64*)document);
}

// MS2-FUNCTIONAL: select the last seek-table entry whose frame id does not exceed the requested frame.
// @0x140033700
void FUN_140033700(void* player, const void* data, CriUint32 size, CriSint32 targetFrame,
                   void** outputData, CriSint32* outputFrame)
{
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, data, size);
    CriSint32 count = FUN_14003a45c(document);
    CriSint32 index = 0;
    CriSint32 frame = 0;
    void* selectedData = NULL;
    while (index < count &&
           (frame = FUN_14003a894(document, index, "ofs_frmid")) <= targetFrame)
    {
        selectedData = FUN_14003a648(document, index, 0);
        ++index;
    }
    *outputData = selectedData;
    *outputFrame = FUN_14003a894(document, index == 0 ? 0 : index - 1, "ofs_frmid");
    criUtfRtv_Destroy((CriUint64*)document);
}

// MS2-FUNCTIONAL: allocate and initialize the metadata stream using either the caller or CRI heap.
// @0x140031c40
CriBool FUN_140031c40(void* player, void* heap, CriUint32 size, CriUint32 alignment)
{
    struct MetaConfig
    {
        CriUint32 Mode;
        CriUint32 Size;
        CriUint32 Reserved8;
        CriUint32 Alignment;
        CriUint64 Reserved10;
    } config = { 1, size, 0, alignment, 0 };
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
    if (!heap)
    {
        CriSint32 workSize = criSjRbf_CalculateWorkSize((const CriSint32*)&config);
        void* allocation = ((MetadataView*)player)->Allocate(((MetadataView*)player)->Context, workSize);
        if (!allocation)
        {
            FUN_140037950(player, "E10052103M : NULL pointer is paased from the MetaWorkCallback by app.", 0);
            return 0;
        }
        ((MetadataView*)player)->Stream = FUN_140045eec(&config, allocation, workSize);
        ((MetadataView*)player)->Allocation = allocation;
        return 1;
    }

    ((MetadataView*)player)->Stream = FUN_140046730(heap, (CriSint32)size, 0, (CriSint32)alignment,
                                  "CriMvPly: MetaInput");
    if (!((MetadataView*)player)->Stream)
    {
        FUN_140037950(player, "E08120201M : Can't create meta SJ.", 0);
        return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: allocate the cue-point event table from the selected heap and clear all records.
// @0x140031da0
CriBool FUN_140031da0(void* player, void* heap)
{
    struct EventConfigView
    {
        CriUint8 Reserved0[0x898];
        CriSint32 Enabled;
        CriUint8 Reserved89C[0x8ac - 0x89c];
        CriUint32 Count;
        CriUint8 Reserved8B0[0xde8 - 0x8b0];
        void* Heap;
        CriUint8 ReservedDF0[0xec0 - 0xdf0];
        void* Table;
        CriUint8 ReservedEC8[0x40];
        void* ReleaseTable;
    };
    if (((EventConfigView*)player)->Enabled == 0)
    {
        ((EventConfigView*)player)->Table = NULL;
        return 1;
    }

    if (!heap)
    {
        struct AllocatorView
        {
            CriUint8 Reserved0[0xee8];
            void* (*Allocate)(void*, CriUint32);
            CriUint8 ReservedEF0[8];
            void* Context;
        };
        ((EventConfigView*)player)->Table = ((AllocatorView*)player)->Allocate(((AllocatorView*)player)->Context, ((EventConfigView*)player)->Count * 0x38 + 4);
        ((EventConfigView*)player)->ReleaseTable = ((EventConfigView*)player)->Table;
        if (!((EventConfigView*)player)->Table)
        {
            FUN_140037950(player, "E10052103M : NULL pointer is paased from the MetaWorkCallback by app.", 0);
            return 0;
        }
    }
    else
    {
        ((EventConfigView*)player)->Table = FUN_140027ed8(((EventConfigView*)player)->Heap, (CriSint32)(((EventConfigView*)player)->Count * 0x38),
                                     "CriMvPly: EventTable", 4);
        if (!((EventConfigView*)player)->Table)
        {
            FUN_140037950(player, "E09011601M : Can't allocate EventTable Memory.", 0);
            return 0;
        }
    }
    memset(((EventConfigView*)player)->Table, 0, (size_t)((EventConfigView*)player)->Count * 0x38);
    return 1;
}

// MS2-FUNCTIONAL: size and allocate the CRI Movie metadata and event work areas.
// @0x140031ae0
CriBool FUN_140031ae0(void* player)
{
    struct BaseSizeView { CriUint8 Reserved[0x63c]; CriSint32 Size; };
    struct FeatureSizeA { CriUint8 Reserved[0x868]; CriSint32 Enabled; };
    struct FeatureBytesA { CriUint8 Reserved[0x890]; CriSint32 Size; };
    struct FeatureSizeB { CriUint8 Reserved[0x898]; CriSint32 Enabled; };
    struct FeatureBytesB { CriUint8 Reserved[0x8a8]; CriSint32 Size; };
    struct WorkSizeView { CriUint8 Reserved[0xe74]; CriUint32 Size; };
    struct WorkHeapView { CriUint8 Reserved[0xde8]; void* Heap; };
    struct QueueView { CriUint8 Reserved[0xd78]; void* Input; void* Read; };
    struct MetaStreamView { CriUint8 Reserved[0xe78]; void* Stream; };
    if (((MetaStreamView*)player)->Stream)
        FUN_140031f00(player);

    CriSint32 workSize = ((BaseSizeView*)player)->Size + 0x800;
    if (((FeatureSizeA*)player)->Enabled != 0)
        workSize += ((FeatureBytesA*)player)->Size;
    if (((FeatureSizeB*)player)->Enabled != 0)
        workSize += ((FeatureBytesB*)player)->Size;
    CriSint32 queued = FUN_1400467b8(((QueueView*)player)->Read, 1) +
                       FUN_1400467b8(((QueueView*)player)->Input, 1);
    if (workSize < queued)
        workSize = queued;
    ((WorkSizeView*)player)->Size = (CriUint32)workSize;

    void* heap = ((WorkHeapView*)player)->Heap;
    if (!FUN_140031c40(player, heap, (CriUint32)workSize, 0x40))
        return 0;
    if (!FUN_140031da0(player, heap))
    {
        FUN_140031f00(player);
        return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: expose the next decoded file-read record when the movie state permits a read.
// @0x140034d40
void FUN_140034d40(void* player, CriMovieInputChunk* output)
{
    struct PlayerStateC { CriUint8 Reserved[0x0c]; CriSint32 Value; };
    struct ReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; };
    struct ReadRecordView { CriUint8 Reserved[0xd90]; CriMovieInputChunk Record; };
    struct ReadSizeView { CriUint8 Reserved[0xd98]; CriSint32 Size; };
    memset(output, 0, sizeof(*output));
    CriSint32 status = getInternalStatus(player);
    if (((ReadModeView*)player)->Mode == 1 || ((PlayerStateC*)player)->Value == 1 ||
        status == 0 || status == 2 || (status >= 6 && status <= 10))
        return;
    CriSint32 lockState = isLockedInputChunk(player);
    void* source = FUN_140037050(player, NULL, NULL);
    if (!source || lockState == 1)
        return;
    ReadRecordView* current = (ReadRecordView*)player;
    FUN_1400467a0(source, 0, -1, &current->Record);
    if (((ReadSizeView*)player)->Size != 0)
        *output = current->Record;
}

// MS2-FUNCTIONAL: refresh the player's pending byte counts from the selected input stream.
// @0x140034c20
void FUN_140034c20(void* player)
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
    CriSint32 status = getInternalStatus(player);
    if (status >= 0 && status <= 1)
        return;
    CriUint32 available = 0;
    CriUint32 mode = 0;
    void* source = FUN_140037050(player, &available, &mode);
    if (!source)
        return;
    CriSint32 remaining;
    if (((ReadModeView*)player)->Mode == 1)
        remaining = ((ReadProgressView*)player)->StreamBytes - FUN_1400467b8(source, 0);
    else
        remaining = available - FUN_1400467b8(source, 0) - ((ReadProgressView*)player)->BufferedBytes;
    ((InputStatsView*)player)->Available = available;
    ((InputStatsView*)player)->Remaining = remaining;
    ((InputStatsView*)player)->Mode = mode;
}

// MS2-FUNCTIONAL: initialize analyzed stream counts from the CRI Movie file header.
// @0x140032420
void FUN_140032420(void* player, void* streamInfo, const CriMovieParsedChunk* parsed)
{
    struct StreamInfoView
    {
        CriUint32 HeaderType;
        CriUint32 Field4;
        CriUint32 MinimumBuffer;
        CriUint32 AverageBitrate;
        CriUint32 VideoCount;
        CriUint8 Reserved14[0x4c - 0x14];
        CriUint32 IndexedAudioCount;
        CriUint8 Reserved50[0x200];
        CriUint32 SubtitleCount;
        CriUint8 Reserved254[0x1c];
        CriUint32 AlphaCount;
        CriUint8 Reserved274[0x2c];
        CriUint32 CueCount;
    };
    struct TrackModeView { CriUint8 Reserved[0xe38]; CriUint32 Type; CriUint32 SubType; };
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    memset(streamInfo, 0, 0x2c0);
    StreamInfoView* info = (StreamInfoView*)streamInfo;
    info->MinimumBuffer = FUN_14003a85c(document, 0, "minbuf");
    info->AverageBitrate = FUN_14003a85c(document, 0, "avbps");
    CriSint32 count = FUN_14003a45c(document);
    for (CriSint32 i = 0; i < count; ++i)
    {
        CriSint32 streamId = FUN_14003a85c(document, i, "stmid");
        if (streamId == 0x40414c50)
        {
            if (++info->AlphaCount > 1)
                info->AlphaCount = 1;
            ((TrackModeView*)player)->Type = 0x40414c50;
            ((TrackModeView*)player)->SubType = 0;
        }
        else if (streamId == 0x40435545)
            ++info->CueCount;
        else if (streamId == 0x40534254)
            ++info->SubtitleCount;
        else if (streamId == 0x40534641)
        {
            if (++info->IndexedAudioCount > 0x20)
                info->IndexedAudioCount = 0x20;
        }
        else if (streamId == 0x40534656)
        {
            if (++info->VideoCount > 1)
                info->VideoCount = 1;
        }
    }
    criUtfRtv_Destroy((CriUint64*)document);
}

// MS2-FUNCTIONAL: consume CRI Movie header and stream records until the file's end marker arrives.
// @0x140032090
CriSint32 FUN_140032090(void* player)
{
    struct ReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; };
    struct HeaderCountView { CriUint8 Reserved[0x8b8]; CriSint32 Count; };
    struct ReadByteCountView { CriUint8 Reserved[0xdb8]; CriSint32 Count; };
    CriMovieChunkQueueRecord record = {};
    CriUint8 parsedHeader[0x24] = {};
    CriSint32 contentSize = 0;
    CriSint32 consumedBytes = 0;
    CriSint32 completed = 0;
    CriUint32* streamInfo = (CriUint32*)((CriMvPlyHeaderAnalysisFields*)player)->AnalyzedHeader;
    void* queue = ((CriMvPlyInputQueueFields*)player)->ReadBuffer;

    for (;;)
    {
        if (FUN_1400467b8(queue, 1) == 0)
            return completed;
        FUN_1400467a0(queue, 1, -1, &record);
        if (record.Type < 0x20)
        {
            FUN_1400467a8(queue, 1, &record);
            return completed;
        }

        memset(parsedHeader, 0, sizeof(parsedHeader));
        FUN_14003b3fc((const CriUint8*)record.Chunk, record.Type, parsedHeader);
        const CriUint8* contents = criUsfCmn_GetContents((const CriUint8*)record.Chunk,
                                                  record.Type, &contentSize);
        CriUint32 streamId = 0;
        memcpy(&streamId, parsedHeader, sizeof(streamId));
        if (((HeaderCountView*)player)->Count == 0)
        {
            if (streamId != 0x43524944)
            {
                FUN_140037950(player, "E05063020M : Input file is not USF file.", (CriSint32)streamId);
                FUN_1400467a8(queue, 1, &record);
                return completed;
            }
            streamInfo[0] = 1;
        }

        CriMovieParsedChunk parsed = { contents, contentSize, 0 };
        if (streamId == 0x43524944)
            FUN_140032420(player, streamInfo, &parsed);
        else if (parsedHeader[0x0f] == 1)
        {
            CriUint8 index = parsedHeader[0x0c];
            if (streamId == 0x40414c50)
            {
                if (index == 0)
                    FUN_140032db0(player, streamInfo, streamInfo + 0x9d, &parsed);
            }
            else if (streamId == 0x40435545)
                FUN_140032c70(player, streamInfo, streamInfo + 0xaa, &parsed);
            else if (streamId == 0x40534254)
                FUN_140032b70(player, streamInfo, streamInfo + 0x96, &parsed);
            else if (streamId == 0x40534641)
            {
                if (index < 0x20)
                    FUN_140032a70(player, streamInfo,
                                 streamInfo + 0x14 + (CriUint32)index * 4, &parsed);
            }
            else if (streamId == 0x40534656 && index == 0)
                FUN_140032650(player, (CriSint64*)streamInfo, streamInfo + 5, &parsed);
        }
        else if (parsedHeader[0x0f] == 2)
            completed = 1;

        FUN_1400467b0(queue, 2, &record);
        consumedBytes += (CriSint32)record.Type;
        ++((HeaderCountView*)player)->Count;
        if (completed)
            break;
    }
    if (((ReadModeView*)player)->Mode == 1)
        ((ReadByteCountView*)player)->Count = consumedBytes;
    return 1;
}

// MS2-FUNCTIONAL: return a partially consumed input chunk to its source queue after playback uses it.
// @0x140034e70
void FUN_140034e70(void* player, const CriMovieInputChunk* input, CriUint32 maximum)
{
    struct ReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; };
    struct ReadCurrentView { CriUint8 Reserved[0xd90]; CriMovieInputChunk Current; };
    if (((ReadModeView*)player)->Mode == 1 || !input->Data || input->Size == 0)
        return;
    CriSint32 status = getInternalStatus(player);
    if (status == 0 || status == 2 || status == 8)
    {
        ((ReadCurrentView*)player)->Current.Data = NULL;
        ((ReadCurrentView*)player)->Current.Size = 0;
        return;
    }

    void* source = FUN_140037050(player, NULL, NULL);
    if (!source)
    {
        FUN_140037950(player, "E05063026M : Can't exec criMvPly_PutInputChunk() before AllocateWorkBuffer.", 0);
        return;
    }
    CriMovieInputChunk* current = &((ReadCurrentView*)player)->Current;
    if (current->Data != input->Data || current->Size != input->Size)
    {
        FUN_140037950(player, "E05063027M : Chunk is not same to one by criMvPly_GetInputChunk().",
                      (CriSint32)(uintptr_t)input->Data);
        return;
    }

    CriMovieInputChunk suffix = {};
    criSj_SplitChunk(current, maximum, current, &suffix);
    FUN_1400467a8(source, 0, &suffix);
    FUN_1400467b0(source, 1, current);
    current->Data = NULL;
    current->Size = 0;
}

// MS2-FUNCTIONAL: discard handled command chunks while returning ordinary input records to the stream.
// @0x140033610
void FUN_140033610(void* player)
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
        FUN_1400467a0(work, 1, -1, &chunk);
        if (chunk.Size >= 0x20)
        {
            FUN_14003b3fc((const CriUint8*)chunk.Data, chunk.Size, &header);
            p = criUsfCmn_GetContents((const CriUint8*)chunk.Data, chunk.Size, &length);
            if (((CriUint8*)&header)[0xf] != 2 && ((CriUint8*)&header)[0xf] != 3)
            {
                FUN_1400467a8(work, 1, &chunk);
                break;
            }
            FUN_1400467b0(work, 2, &chunk);
        }
        else
        {
            FUN_1400467a8(work, 1, &chunk);
            break;
        }
    }
}

// MS2-FUNCTIONAL: release the player's output stream, decoder work area, and callback-owned buffers.
// @0x140031f40
CriBool FUN_140031f40(void* player)
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
        FUN_140046784(((CleanupView*)player)->StreamJoint);
        ((CleanupView*)player)->StreamJoint = NULL;
        if (((CleanupView*)player)->CallbackBuffer)
            ((CleanupView*)player)->Release(((CleanupView*)player)->ReleaseContext, ((CleanupView*)player)->CallbackBuffer);
    }
    if (((CleanupView*)player)->Work)
    {
        if (((CleanupView*)player)->WorkReleaseBuffer)
            ((CleanupView*)player)->Release(((CleanupView*)player)->ReleaseContext, ((CleanupView*)player)->WorkReleaseBuffer);
        else if (((CleanupView*)player)->Heap)
            FUN_140027fb4(((CleanupView*)player)->Heap, ((CleanupView*)player)->Work);
        ((CleanupView*)player)->Work = NULL;
    }
    return 1;
}

// MS2-FUNCTIONAL: reset a stopped CRI Movie player and reinitialize its demux output stream.
// @0x140034960
CriBool FUN_140034960(void* player)
{
    struct PlayerResetView
    {
        CriUint8 Reserved0[4];
        CriSint32 Status;
        CriUint32 InternalFlags;
        CriSint32 OpenLock;
        CriUint32 ResetTimer;
        CriUint8 Reserved14[0x14];
        CriUint8 CurrentHeader[0x5c0];
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
    if (!player)
    {
        FUN_140037950(NULL, "E05121601M : CriMvPly handle is NULL.", 0);
        return 0;
    }

    PlayerResetView* state = (PlayerResetView*)player;
    if (state->Status != 0 && state->Status != 7)
    {
        FUN_140037950(player, "E05121602M : Can't execute start function when CriMvPly handle status is not STOP/PLAYEND.", state->Status);
        return 0;
    }

    state->ResetTimer = 0;
    state->HeaderSize = 0;
    memset(state->AnalyzedHeader, 0, sizeof(state->AnalyzedHeader));
    state->ReadMode = 0;
    FUN_140044fa8(state->Demux, state->InputStream);
    FUN_140044fb0(state->Demux, 0, state->OutputStream, 0, (CriUint32)-1);
    FUN_140044fd8(state->Demux, 0);
    FUN_140044f9c(state->Demux);
    memset(state->CurrentHeader, 0, sizeof(state->CurrentHeader));
    state->HeaderSize = 0;
    state->CurrentSlot = 1;
    state->SlotCount = 0;
    state->FrameCount = 0;
    state->InputCount0 = 0;
    state->InputCount1 = 0;
    state->InputCount2 = 0;
    state->OpenLock = 0;
    state->Status = 1;
    return 1;
}

// MS2-FUNCTIONAL: reset the demux and its output stream after the player update completes.
// @0x140031990
CriBool FUN_140031990(void* player)
{
    if (FUN_140031aa0(player) != 1)
        return 0;
    struct ReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; };
    struct MemoryInputView { CriUint8 Reserved[0xda0]; void* Input; };
    FUN_140034330(player, ((CriMvPlyInputQueueFields*)player)->InputBuffer, ((CriMvPlyInputQueueFields*)player)->ReadBuffer, ((CriMvPlyInputQueueFields*)player)->HeaderBuffer);
    FUN_1400453c4(((CriMvPlyStateTransitionFields*)player)->Demux);
    FUN_140046798(((CriMvPlyInputQueueFields*)player)->ReadBuffer);
    if (((ReadModeView*)player)->Mode == 0)
        FUN_140044fa8(((CriMvPlyStateTransitionFields*)player)->Demux, ((CriMvPlyInputQueueFields*)player)->HeaderBuffer);
    else
        FUN_140044fa8(((CriMvPlyStateTransitionFields*)player)->Demux, ((MemoryInputView*)player)->Input);
    FUN_140044fb0(((CriMvPlyStateTransitionFields*)player)->Demux, 0, ((CriMvPlyInputQueueFields*)player)->ReadBuffer, 0, (CriUint32)-1);
    FUN_140044fd8(((CriMvPlyStateTransitionFields*)player)->Demux, 0);
    FUN_140044f9c(((CriMvPlyStateTransitionFields*)player)->Demux);
    FUN_1400458b8(((CriMvPlyStateTransitionFields*)player)->Demux);
    return 1;
}

// MS2-FUNCTIONAL: drive the file-open metadata phase until the demux is prepared for playback.
// @0x1400317b0
void FUN_1400317b0(void* player)
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
        if (FUN_1400318f0(player) != 1)
            break;
        if (((MetaHeapView*)player)->Heap == NULL && ((AllocatorView*)player)->Allocate == NULL)
        {
            ((InputReadyView*)player)->Ready = 0;
            FUN_140033610(player);
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
        if (FUN_140032040(player) == 1)
            ((CriMvPlyStateTransitionFields*)player)->Status = 2;
        break;
    }
    ((LockView*)player)->Value = 0;
}

// advance a completed video decoder (and its alpha decoder) through the metadata and stop phases
// @0x1400344f0
void FUN_1400344f0(void* player)
{
    if (((CriMvDecoderHandleFields*)player)->VideoDecoder)
    {
        if (FUN_140044630(((CriMvDecoderHandleFields*)player)->VideoDecoder) != 3)
            return;
        if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        {
            FUN_140035bf0(player);
            if (FUN_140043cb0(((CriMvDecoderHandleFields*)player)->AlphaDecoder) != 3)
            {
                ((CriMvPlyStateTransitionFields*)player)->StopState = 2;
                return;
            }
        }
    }

    if (FUN_140042d70(((CriMvDecoderHandleFields*)player)->AudioManager, player) != 1)
    {
        ((CriMvPlyStateTransitionFields*)player)->StopState = 4;
        return;
    }
    if (isLockedInputChunk(player) == 1)
        ((CriMvPlyStateTransitionFields*)player)->StopState = 3;
    else
    {
        FUN_140031570(player);
        ((CriMvPlyStateTransitionFields*)player)->Status = 6;
        ((CriMvPlyStateTransitionFields*)player)->StopState = 5;
    }
}

// MS2-FUNCTIONAL: copy the selected analyzed-header or input-buffer remainder into the read queue.
// @0x1400342b0
void FUN_1400342b0(void* player)
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

// MS2-FUNCTIONAL: reset the player's demux, streams, audio manager, and seek metadata for a new open.
// @0x140031570
void FUN_140031570(void* player)
{
    struct ResetView
    {
        CriUint8 Reserved0[0xd60];
        CriSint32 ReadMode;
        CriUint32 HeaderChecked;
        void* Demux;
        CriUint32 Reserved70;
        CriUint32 OutputCount;
        void* InputBuffer;
        void* ReadBuffer;
        void* DataQueue;
        CriMovieInputChunk CurrentRead;
        void* MemoryInput;
    };
    struct CounterResetView { CriUint8 Reserved[0xe58]; CriUint8 Counters[0x1c]; };
    struct HeaderResetView { CriUint8 Reserved[0xe80]; CriUint32 Value; };
    CriMvPlyObj* movie = (CriMvPlyObj*)player;
    ((ResetView*)player)->ReadMode = 0;
    if (((CriMvDecoderHandleFields*)player)->AudioManager)
        FUN_1400427b0(((CriMvDecoderHandleFields*)player)->AudioManager);
    if (((ResetView*)player)->Demux)
        FUN_1400453c4(((ResetView*)player)->Demux);
    FUN_140046798(((ResetView*)player)->InputBuffer);
    FUN_140046798(((ResetView*)player)->MemoryInput);
    if (((ResetView*)player)->DataQueue)
        FUN_140046798(((ResetView*)player)->DataQueue);
    if (((ResetView*)player)->ReadBuffer)
        FUN_140046798(((ResetView*)player)->ReadBuffer);
    if (((CriMvDecoderHandleFields*)player)->AudioManager)
        FUN_140042800(((CriMvDecoderHandleFields*)player)->AudioManager);
    ((ResetView*)player)->CurrentRead.Data = NULL;
    ((ResetView*)player)->CurrentRead.Size = 0;
    ((ResetView*)player)->HeaderChecked = 0;
    ((ResetView*)player)->OutputCount = 0;
    movie->decoder_error = 0;
    memset(((CounterResetView*)player)->Counters, 0, sizeof(((CounterResetView*)player)->Counters));
    ((HeaderResetView*)player)->Value = 0;
    memset(&movie->seektbl, 0, 0x2c);
}

// MS2-FUNCTIONAL: perform the executable's pending start/stop state transition on the player.
// @0x140031140
void FUN_140031140(void* player)
{
    // +0x0c is the open-phase read lock FUN_1400317b0 sets; +0x08 (InternalFlags) is the stop request.
    struct OpenLockView { CriUint8 Reserved[0x0c]; CriSint32 Value; };
    CriSint32 status = ((CriMvPlyStateTransitionFields*)player)->Status;
    if (status == 2)
    {
        if (((CriMvPlyStateTransitionFields*)player)->StartReady == 1)
        {
            FUN_1400342b0(player);
            FUN_1400453c4(((CriMvPlyStateTransitionFields*)player)->Demux);
            ((OpenLockView*)player)->Value = 0;
            ((CriMvPlyStateTransitionFields*)player)->Status = 3;
        }
        else
            FUN_140037950(player, "E05063019M : Can't start movie without work buffer.", 0);
    }
    else if (status == 4)
        ((CriMvPlyStateTransitionFields*)player)->Status = 5;
    else if (status == 6)
    {
        ((CriMvPlyStateTransitionFields*)player)->LastFrame = -1;
        ((CriMvPlyStateTransitionFields*)player)->Status = 7;
        ((CriMvPlyStateTransitionFields*)player)->StopState = 0;
    }
    else if (status == 9)
    {
        ((CriMvPlyStateTransitionFields*)player)->LastFrame = -1;
        ((CriMvPlyStateTransitionFields*)player)->Status = 0;
        ((CriMvPlyStateTransitionFields*)player)->StopState = 0;
    }
}

// MS2-FUNCTIONAL: run the CRI movie player once under its per-player critical section.
// @0x140031250
void FUN_140031250(void* player)
{
    FUN_140037850(player);
    FUN_140031290(player);
    FUN_140037880(player);
}

// MS2-FUNCTIONAL: invoke each configured decoder's frame-decode callback.
// @0x140031410
CriBool FUN_140031410(void* player)
{
    if (!player)
        return 0;
    CriBool result = FUN_1400446c0(((CriMvDecoderHandleFields*)player)->VideoDecoder);
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        FUN_140043d40(((CriMvDecoderHandleFields*)player)->AlphaDecoder);
    return result;
}

// MS2-FUNCTIONAL: ask the primary video decoder to skip its current frame.
// @0x1400314a0
void FUN_1400314a0(void* player)
{
    FUN_140044ae0(((CriMvDecoderHandleFields*)player)->VideoDecoder);
}

// MS2-FUNCTIONAL: report whether both decoder backends have completed their stop processing.
// @0x1400314d0
CriBool FUN_1400314d0(void* player)
{
    void* videoDecoder = ((CriMvDecoderHandleFields*)player)->VideoDecoder;
    void* alphaDecoder = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;   // after videoDecoder: same VC9 slot bucket
    CriBool result = 0;
    if (videoDecoder && FUN_140044630(videoDecoder))
    {
        ((CriMvPlyStateTransitionFields*)player)->StopState = 1;
        return result;
    }
    if (alphaDecoder && FUN_140043cb0(alphaDecoder))
    {
        ((CriMvPlyStateTransitionFields*)player)->StopState = 2;
        return result;
    }
    result = 1;
    return result;
}

// MS2-FUNCTIONAL: decode a video frame while holding the global CRI movie-player lock.
// @0x1400313d0
CriBool FUN_1400313d0(void* player)
{
    FUN_1400378b0(player);
    CriBool result = FUN_140031410(player);
    FUN_1400378e0(player);
    return result;
}

// MS2-FUNCTIONAL: process a pending video-server frame and update decoder progress.
// @0x140031470
void FUN_140031470(void* player)
{
    FUN_140034730(player);
    FUN_1400317b0(player);
}

// MS2-FUNCTIONAL: consume a queued CRID subtitle header and update the alternate subtitle stream slot.
// @0x140036710
void FUN_140036710(void* player)
{
    if (!player)
        return;
    struct SubtitleQueueView { CriUint8 Reserved[0xd80]; void* Queue; };
    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    void* queue = ((SubtitleQueueView*)player)->Queue;
    if (!queue)
        return;
    CriSint32 status = getInternalStatus(player);
    if (status == 0 || status == 1 || status == 2)
        return;

    struct SubtitleRingState
    {
        CriUint8 Reserved[0x5e8];
        CriUint16 CurrentIndex;
        CriUint8 Reserved2[6];
        CriUint32 Phase;
    };
    struct SubtitleStreamEntry
    {
        CriUint8 Reserved0[0x10];
        CriUint32 Field10;
        CriUint8 Reserved1[0x38];
        CriUint32 Field4c;
        CriUint8 Reserved2[0x200];
        CriUint32 Field250;
        CriUint8 Reserved3[0x1c];
        CriUint32 Field270;
        CriUint8 Reserved4[0x4c];
        CriUint32 State;
        CriUint32 History0;
        CriUint32 History4;
        CriUint32 History8;
        CriUint32 HistoryC;
        CriUint32 History10;
        CriUint8 Reserved5[8];
    };
    struct SubtitleStreamList { CriUint8 Reserved[0x28]; SubtitleStreamEntry Entries[2]; };
    SubtitleRingState* ring = (SubtitleRingState*)player;
    if ((ring->Phase % 2) == ring->CurrentIndex)
        return;
    SubtitleStreamEntry* target = &((SubtitleStreamList*)player)->Entries[ring->CurrentIndex];
    if (target->State == 1)
        return;

    CriMovieInputChunk chunk = {};
    if (FUN_1400467b8(queue, 1) && (FUN_1400467a0(queue, 1, -1, &chunk), chunk.Size > 0x1f))
    {
        CriUint32 parsed[14] = {};
        FUN_14003b3fc(chunk.Data, chunk.Size, parsed);
        if (parsed[0] == 0x43524944)
        {
            CriSint32 contentSize = 0;
            CriMovieParsedChunk header = { criUsfCmn_GetContents(chunk.Data, chunk.Size, &contentSize), contentSize, 0 };
            FUN_140032420(player, target, &header);
            target->History0 = target->Field4c;
            target->History4 = target->Field10;
            target->History8 = target->Field250;
            target->HistoryC = target->Field270;
            target->History10 = 0;
            target->State = 1;
        }
        FUN_1400467b0(queue, 0, &chunk);
    }
}

// MS2-FUNCTIONAL: expose the next subtitle chunk only after the movie player leaves its setup states.
// @0x140036650
CriUint32 FUN_140036650(void* player)
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
    FUN_140036e80(player, &subtitle);
    return res;
}

// MS2-FUNCTIONAL: drain subtitle decoder queues whose frame indices have fallen behind playback.
// @0x1400369e0
void FUN_1400369e0(void* player)
{
    struct VideoFrameView { CriUint8 Reserved[0x100]; CriSint32 Index; };
    struct AlphaFrameView { CriUint8 Reserved[0xb0]; CriSint32 Index; };
    VideoFrameView videoFrame = {};
    AlphaFrameView alphaFrame = {};
    struct SubtitleEndState
    {
        CriUint8 Reserved[0xe58];
        CriSint32 Count;     // +0xe58
        CriSint32 Reserved2[2];
        CriSint32 VideoDone; // +0xe64
        CriSint32 AlphaDone; // +0xe68
    };
    SubtitleEndState* state = (SubtitleEndState*)player;
    CriSint32 subtitleCount = state->Count;
    if (subtitleCount <= 0)
        return;

    if (state->VideoDone != 1)
    {
        void* decoder = ((CriMvDecoderHandleFields*)player)->VideoDecoder;
        while (FUN_140044870(decoder, &videoFrame))
        {
            if (subtitleCount <= videoFrame.Index)
            {
                state->VideoDone = 1;
                break;
            }
            FUN_1400449c0(decoder, &videoFrame);
            FUN_140044a30(decoder, &videoFrame);
        }
    }

    void* alphaDecoder = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
    if (alphaDecoder && state->AlphaDone != 1)
    {
        while (FUN_140043f10(alphaDecoder, &alphaFrame))
        {
            if (subtitleCount <= alphaFrame.Index)
            {
                state->AlphaDone = 1;
                return;
            }
            FUN_140043fe0(alphaDecoder, &alphaFrame);
            FUN_140044050(alphaDecoder, &alphaFrame);
        }
    }
}

// MS2-FUNCTIONAL: discard the player's pending subtitle chunk.
// @0x140036e30
void FUN_140036e30(void* player, CriMvSubtitleChunk* chunk)
{
    if (player == NULL)
        return;
    if (((CriMvSubtitleFields*)player)->Queue == NULL)
        return;
    FUN_1400467b0(((CriMvSubtitleFields*)player)->Queue, 0, chunk);
}

// MS2-FUNCTIONAL: return a subtitle chunk to the head of the player's subtitle queue.
// @0x140036e80
void FUN_140036e80(void* player, CriMvSubtitleChunk* chunk)
{
    if (player == NULL)
        return;
    if (((CriMvSubtitleFields*)player)->Queue == NULL)
        return;
    FUN_1400467a8(((CriMvSubtitleFields*)player)->Queue, 1, chunk);
}

// MS2-FUNCTIONAL: release the main and current alpha frame held by the easy player.
// @0x140038fa0
CriSint32 FUN_140038fa0(void* easyPlayer, const CriMvFrameInfo* frameInfo, CriError* error)
{
    *error = CRIERR_OK;
    FUN_140035a40(((CriMvEasyPlayerFrameFields*)easyPlayer)->PlayerHandle, frameInfo);
    if (*(CriUint64*)((CriMvEasyPlayerFrameFields*)easyPlayer)->AlphaFrameInfo)
        FUN_140035a90(((CriMvEasyPlayerFrameFields*)easyPlayer)->PlayerHandle,
                      (const CriUint64*)((CriMvEasyPlayerFrameFields*)easyPlayer)->AlphaFrameInfo);
    return 1;
}

// MS2-FUNCTIONAL: discard the next decoded frame and clear the current-frame bookkeeping.
// @0x140039110
CriSint32 FUN_140039110(void* easyPlayer, CriMvFrameInfo* frameInfo, CriError* error)
{
    *error = CRIERR_OK;
    CriSint32 result = FUN_1400355b0(((CriMvEasyPlayerFrameFields*)easyPlayer)->PlayerHandle, frameInfo);
    FUN_1400393f0((CriMvEasyPlayer*)easyPlayer, 0, 0, 1, 0, 0);
    return result;
}

// MS2-FUNCTIONAL: apply the analyzed movie header after a successful decoder analysis pass.
// @0x1400318f0
CriBool FUN_1400318f0(void* player)
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

// MS2-FUNCTIONAL: complete the metadata stage only when parsing succeeds without a decoder error.
// @0x140032040
CriBool FUN_140032040(void* player)
{
    // The exe parses the queued header chunks first, then reports a decoder error.
    CriBool headerDone = FUN_140033030(player);
    if (((CriMvPlyObj*)player)->decoder_error == 1)
        return 0;
    if (headerDone != 1)
        return 0;
    return 1;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // the exe built these lock wrappers without optimization (/Od)
// MS2-FUNCTIONAL: run the metadata-work cleanup under the player's handle critical section.
// @0x140031f00
CriBool FUN_140031f00(void* player)
{
    FUN_140037850(player);
    CriBool result = FUN_140031f40(player);
    FUN_140037880(player);
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // the exe built these lock wrappers without optimization (/Od)
// MS2-FUNCTIONAL: enter the player's handle lock around the requested CRI Movie transition.
// @0x140034920
CriBool FUN_140034920(void* player)
{
    FUN_140037850(player);
    CriBool result = FUN_140034960(player);
    FUN_140037880(player);
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: destroy player-owned decoders and queues under the player's handle lock.
// @0x140030c70
void FUN_140030c70(void* player)
{
    FUN_140037850(player);
    FUN_140030cb0(player);
    FUN_140037880(player);
}
#pragma optimize("", on)

#pragma optimize("", off)                    // the exe built these lock wrappers without optimization (/Od)
// MS2-FUNCTIONAL: perform the player update under its handle critical section.
// @0x140031aa0
CriBool FUN_140031aa0(void* player)
{
    FUN_140037850(player);
    CriBool result = FUN_140031ae0(player);
    FUN_140037880(player);
    return result;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: request both video decoders to stop and move the player into stop-pending state.
// @0x140034b60
void FUN_140034b60(void* player)
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
            FUN_140044750(videoDec);
        void* alphaDec = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
        if (alphaDec)
            FUN_140043dd0(alphaDec);
    }
}

// MS2-FUNCTIONAL: stop the player under its handle critical section.
// @0x140034b20
void FUN_140034b20(void* player)
{
    FUN_140037850(player);
    FUN_140034b60(player);
    FUN_140037880(player);
}

// MS2-FUNCTIONAL: fetch a 16-bit waveform block from the main audio stream.
// @0x140035f00
CriUint32 FUN_140035f00(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    CriUint32 count = FUN_140042e40(((CriMvDecoderHandleFields*)player)->AudioManager, 0, player,
                                    format, output, sampleCount, result);
    return count;
}

// MS2-FUNCTIONAL: fetch a 32-bit waveform block from the main audio stream.
// @0x140035f70
CriUint32 FUN_140035f70(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    CriUint32 count = FUN_140042ea0(((CriMvDecoderHandleFields*)player)->AudioManager, 0, player,
                                    format, output, sampleCount, result);
    return count;
}

// MS2-FUNCTIONAL: fetch a 16-bit waveform block from the secondary audio stream.
// @0x140035fe0
CriUint32 FUN_140035fe0(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    CriUint32 count = FUN_140042e40(((CriMvDecoderHandleFields*)player)->AudioManager, 1, player,
                                    format, output, sampleCount, result);
    return count;
}

// MS2-FUNCTIONAL: fetch a 32-bit waveform block from the secondary audio stream.
// @0x140036050
CriUint32 FUN_140036050(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    CriUint32 count = FUN_140042ea0(((CriMvDecoderHandleFields*)player)->AudioManager, 1, player,
                                    format, output, sampleCount, result);
    return count;
}

// MS2-FUNCTIONAL: request the next alpha-frame metadata record when the alpha decoder is present.
// @0x140035e90
CriBool FUN_140035e90(void* player, void* frameInfo)
{
    void* frame = NULL;
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder == NULL)
        return 0;
    frame = FUN_140043f10(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
    if (frame == NULL)
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: advance the alpha decoder to the requested frame, releasing frames skipped en route.
// @0x140035db0
CriBool FUN_140035db0(void* player, CriSint32 targetFrame, void* frameInfo)
{
    void* alpha = NULL;
    CriBool ok = FUN_140035e90(player, frameInfo);
    if (ok == 0)
        return 0;
    while (targetFrame > *(CriSint32*)((CriUint8*)frameInfo + 8))
    {
        alpha = FUN_140043fe0(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
        if (alpha != NULL)
            FUN_140044050(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
        else
            return 0;
        // the decoder rewrote frameInfo: compare the frame it now holds, not the one read above
        if (*(CriSint32*)((CriUint8*)frameInfo + 8) + 1 == targetFrame)
        {
            alpha = FUN_140043f10(((CriMvDecoderHandleFields*)player)->AlphaDecoder, frameInfo);
            if (alpha == NULL)
                return 0;
            break;
        }
    }
    return 1;
}

// MS2-FUNCTIONAL: pair the next video frame with its matching alpha frame when the alpha decoder is ready.
// @0x140035c80
void* FUN_140035c80(void* player, void* output)
{
    // Local names pick the exe's VC9 /Od stack slots (work/vc9/p10/probe): videoFrame, videoToken, alphaFrame, result.
    CriMvFrameInfo videoFrame;               // left uninitialised, as in the exe; the decoder fills it
    void* videoToken;
    CriUint64 alphaFrame[10];                // the 0x50-byte alpha frame record
    CriSint32 result;
    FUN_140035090(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return NULL;
    videoToken = FUN_140044870(((CriMvDecoderHandleFields*)player)->VideoDecoder, &videoFrame);
    if (videoToken != NULL)
    {
        if (((CriMvDecoderHandleFields*)player)->AlphaDecoder != NULL
            && FUN_140043cb0(((CriMvDecoderHandleFields*)player)->AlphaDecoder) == 3)
        {
            FUN_140037950(player, "E08092600M : Alpha channel is longer than video frame. should be same.", 0);
            return NULL;
        }
        if (((CriMvDecoderHandleFields*)player)->AlphaDecoder != NULL)
        {
            result = FUN_140035db0(player, videoFrame.frame_id, alphaFrame);
            if (result == 0)
                return NULL;
        }
        FUN_140035260(player, output, &videoFrame, (CriUint64)(uintptr_t)videoToken, 0);
    }
    return videoToken;
}
#pragma optimize("", on)

#pragma optimize("s", on)                     // this exe CRI obj was built for size (/Os)
// MS2-FUNCTIONAL: return the ordinary or suppressed CRI error count selected by the API flag.
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
        FUN_140038e24(0, "E09012703B", -2);
        return 0;
    }
}

// MS2-FUNCTIONAL: reset one of CRI Error's two counters or report the invalid selector.
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
        FUN_140038e24(0, "E09012704B", -2);
        break;
    }
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: publish the callback and user object used to compare decoded frame times.
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
// MS2-FUNCTIONAL: query the easy player's next frame using the standard one-frame offset.
// @0x140038f60
CriSint32 CriMvEasyPlayer::IsNextFrameOnTime(CriError& error)
{
    const CriSint32 checkDelay = 1;
    CriSint32 result = isNextFrameOnTime(checkDelay, error);
    return result;
}

// MS2-FUNCTIONAL: release the optional alpha frame and the associated main video frame.
// @0x140039d80
CriSint32 CriMvEasyPlayer::UnlockFrameBufferWithAlpha(const CriMvFrameInfo* frameInfo,
                                                       const CriMvAlphaFrameInfo* alphaInfo,
                                                       CriError& error)
{
    error = CRIERR_OK;
    FUN_140035a90(mvply, (const CriUint64*)alphaInfo);
    FUN_140035a40(mvply, frameInfo);
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
// MS2-FUNCTIONAL: allocate the 0x40-byte memory reader from its CRI heap and initialize its state.
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

// MS2-FUNCTIONAL: initialize the CRI file-reader base before the derived memory-reader vtable is installed.
// @0x140038c10
CriMvEasyFileReaderMem::CriMvEasyFileReaderMem()
    : CriMvFileReaderInterface()
{
}

// MS2-FUNCTIONAL: open MFS:<hex-address>.<hex-size> memory-file names.
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
// MS2-FUNCTIONAL: clear the current memory file and report the completed close state.
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
// MS2-FUNCTIONAL: copy up to the remaining file size and publish the byte count as the read result.
// @0x140038810
void CriMvEasyFileReaderMem::Read(CriUint8* buffer, CriSint64 req_size)
{
    ReadState = ASYNC_STATUS_BUSY;
    CriUint64 count = (CriUint64)req_size;
    if (FileSize < Position + (CriSint64)count)
        count = (CriUint64)(FileSize - Position);
    memcpy(buffer, Data + Position, (size_t)count);
    ReadSize = count;
    Position += (CriSint64)count;
    ReadState = ASYNC_STATUS_COMPLETE;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: return the current memory-file open status.
// @0x1400388d0
CriMvFileReaderInterface::AsyncStatus CriMvEasyFileReaderMem::GetOpenStatus(void)
{
    return OpenState;
}

// MS2-FUNCTIONAL: return the current memory-file close status.
// @0x140038910
CriMvFileReaderInterface::AsyncStatus CriMvEasyFileReaderMem::GetCloseStatus(void)
{
    return CloseState;
}

// MS2-FUNCTIONAL: return the current memory-file read status.
// @0x1400388f0
CriMvFileReaderInterface::AsyncStatus CriMvEasyFileReaderMem::GetReadStatus(void)
{
    return ReadState;
}

// MS2-FUNCTIONAL: return the size of the most recent memory-file read.
// @0x140038930
CriSint64 CriMvEasyFileReaderMem::GetReadSize(void)
{
    return (CriSint64)ReadSize;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// MS2-FUNCTIONAL: adjust the memory-file position according to the CRI seek origin.
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
// MS2-FUNCTIONAL: return the configured memory-file size.
// @0x1400389d0
CriSint64 CriMvEasyFileReaderMem::GetFileSize(void)
{
    return FileSize;
}
#pragma optimize("", on)

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Clang drops the own vftable store (0x1431b9588) of this empty body; the inlined base dtor overwrites it anyway.
// MS2-FUNCTIONAL: the derived memory reader has no resources beyond its base reader state.
// @0x140038c80
CriMvEasyFileReaderMem::~CriMvEasyFileReaderMem()
{
}

// MS2-FUNCTIONAL: destroy the reader and release its CRI heap allocation when requested.
// @0x140038c40
void* FUN_140038c40(CriMvEasyFileReaderMem* reader, CriUint32 flags)
{
    reader->CriMvEasyFileReaderMem::~CriMvEasyFileReaderMem();  // non-virtual
    if ((flags & 1) != 0)
        CriAllocator::operator delete(reader, (size_t)0x40);
    return reader;
}

// MS2-FUNCTIONAL: destroy the reader through its virtual deleting destructor.
// @0x1400386c0
void CriMvEasyFileReaderMem::Destroy(void)
{
    delete this;
}
#pragma optimize("", on)
// MS2-PIN: ?FUN_140033810@@YAXPEAX@Z 0x140033810
// MS2-PIN: ?FUN_140033d70@@YAJPEAXPEBUCriMovieInputChunk@@E@Z 0x140033d70
