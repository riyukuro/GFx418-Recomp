// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the rest of the Scaleform GFx 4.1.18 Video player glue
// (VideoPlayerImpl, the decoders and readers over CRI, 0x14002a0e0-0x14002e548). Our own source, written from the exe;
// the leaked SDK copies were only used to name things. This part of the Video add-on lib is VS2008 SP1 code, so the
// unit builds with cl 15.00.30729 and the vc11 options (MS2-TOOLSET: vc9v, cmake/ms2-unit-profiles.cmake). Keep it
// C++03: no auto, nullptr, range-for, __declspec(safebuffers), alias `using`, explicit conversion operators or variadic
// templates. clang-cl compiles it as before. The CRI Movie 3.07.01 internals after it (VS2008 SP1) are
// sfr_cri_02c.
// MS2-UNIT: sfr_cri_02
// MS2-TOOLSET: vc9v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14002a0e0-0x14002e548 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/video/video_video.h"
#include "../include/cri/cri_movie.h"
#include "../include/video/video_videoplayerimpl.h"
#include "../include/kernel/sf_file.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include <new>
#include <cstring>
#include <cstdlib>
#include <intrin.h>

extern "C" {
extern void* DAT_143b15f60;
extern CriUint8 DAT_143b27a48[0x20];
extern CriUint8 DAT_143b27a68[0x20];
extern CriUint8 DAT_143b27a88[];
extern void* DAT_143ffd550;
extern CriSint32 DAT_143ffd500;
extern CriUint8 DAT_143ffd504[0x48];
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
extern unsigned char DAT_142dc9d48[];
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
void     FUN_14258a350(void* lock, bool recursive, bool lockNow);   // Mutex::Mutex
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
void     FUN_142586530(void* pstr, const char* p, Scaleform::UPInt size); // String::AssignString
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
CriSint32 FUN_1400397a0(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo,
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
namespace Scaleform { namespace GFx { namespace Video { void FUN_14002e2a0(void* object); }}}
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

struct CriMovieAttachView
{
    CriUint8 StreamInfo[0xB2C];
    CriUint8 StreamInfoTail[0x2E4];
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

// The VideoReader seen from its CRI file reader interface (+0x10): +0x18 is VideoReader::ReadSize, +0x1c..+0x24 the
// open/close/read statuses (1 = busy), +0x28 Position, +0x30 FilePos, +0x38 FileSize.
struct CriMvReaderRequestView
{
    CriUint8 Reserved0[8];
    void* Queue;
    CriUint8 Reserved1[8];
    CriUint32 ReadBytes;
    CriUint32 OpenPending;
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


namespace Scaleform { namespace GFx { namespace Video {

#define SF_VIDEO_ERR CriMv::ErrorContainer

// The VideoPlayer methods below are the Video add-on lib (VS2008 SP1 code, built with vc9v).

// ==== VideoDecoderThrd ===============================================================================================

// VideoDecoderSmp::FindPlayer, inlined at every use.
static inline int FindPlayer(Array<VideoPlayerImpl*>& players, VideoPlayerImpl* pplayer)
{
    for (UPInt i = 0; i < players.GetSize(); ++i)
    {
        if (players[i] == pplayer)
            return (int)i;
    }
    return -1;
}

// @0x14002a160
void VideoDecoderThrd::StopDecoding(VideoPlayer* pp)
{
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)pp;
    Lock::Locker lock(&DecodeLock);
    if (FindPlayer(Players, pplayer) != -1)
        pplayer->pPlayer->Stop();
}

// @0x14002a1e0
bool VideoDecoderThrd::IsDecodingStopped(VideoPlayer* pp)
{
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)pp;
    Lock::Locker lock(&DecodeLock);
    return FindPlayer(Players, pplayer) == -1;
}

// ==== VideoPlayerImpl: texture ======================================================================================

// MS2-FUNCTIONAL: the VideoImage constructor is inlined there
// @0x14002ad80
VideoImage* VideoPlayerImpl::CreateTexture(Render::TextureManager* ptexman)
{
    if ((Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking) && ptexman)
    {
        unsigned size[2] = { Width, Height };
        PauseLocked = true;
        void* mem = pHeap->Alloc(0x48);
        if (mem)
            return (VideoImage*)FUN_14002abd0(mem, 0xc9 /* Image_Y8_U2_V2 */, (const CriUint32*)size, ptexman, this);
    }
    return NULL;
}

// ==== VideoDecoderSmp ================================================================================================

// @0x14002b3d0
void VideoDecoderSmp::StartDecoding(VideoPlayer* pplayer)
{
    Players.PushBack(static_cast<VideoPlayerImpl*>(pplayer));
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002b450
void VideoDecoderSmp::GetReadBufferInfo(void* pinfo)
{
    Array<VideoPlayer::ReadBufferInfo>& info = *(Array<VideoPlayer::ReadBufferInfo>*)pinfo;
    info.Clear();
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        VideoPlayer::ReadBufferInfo rbinfo;
        Players[i]->GetReadBufferInfo(&rbinfo);
        info.PushBack(rbinfo);
    }
}

// @0x14002beb0
bool VideoDecoderSmp::ExecuteDecode(VideoPlayer* pp)
{
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)pp;
    int idx = FindPlayer(Players, pplayer);
    if (idx == -1)
        return false;
    if (!pplayer->pPlayer->ExecuteDecode(SF_VIDEO_ERR))
    {
        Players.RemoveAt(idx);
        return false;
    }
    return true;
}

// @0x14002bf70
void VideoDecoderSmp::PauseDecoding(bool pause)
{
    if (Paused && pause)
        return;
    for (UPInt i = 0; i < Players.GetSize(); ++i)
    {
        VideoPlayerImpl* pplayer = Players[i];
        // Players the application paused itself stay paused when decoding resumes.
        if (pause && pplayer->PauseFlag)
        {
            PausedPlayers.PushBack(pplayer);
            continue;
        }
        if (!pause)
        {
            int idx = FindPlayer(PausedPlayers, pplayer);
            if (idx != -1)
            {
                PausedPlayers.RemoveAt(idx);
                continue;
            }
        }
        pplayer->Pause(pause);
    }
    Paused = pause;
}

// ==== VideoDecoderThrd ===============================================================================================

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002b270
VideoDecoderThrd::VideoDecoderThrd(MemoryHeap* pheap, Thread::ThreadPriority priority)
    : pHeap(pheap), pDecodeThread(NULL), ThreadPriority(priority), DecodeLock(0)
{
}

// The implicit ~VideoDecoderSmp skips the exe's store of its vftable 0x1431b9170 before the two player arrays are freed:
// nothing virtual runs between it and ~RefCountNTSImplCore, so the store is dead.
// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002b2e0
__declspec(noinline) VideoDecoderThrd::~VideoDecoderThrd()
{
    if (pDecodeThread)
        FUN_14257dcb0(pDecodeThread);
}

// @0x14002bb00
int VideoDecoderThrd::DecodeFunc(Thread*, void* obj)
{
    VideoDecoderThrd* pdecoder = (VideoDecoderThrd*)obj;
    while (1)
    {
        pdecoder->DecodeLock.DoLock();
        if (pdecoder->Players.GetSize() == 1)
        {
            VideoPlayerImpl* pplayer = pdecoder->Players[0];
            pdecoder->DecodeLock.Unlock();
            if (!pplayer->pPlayer->ExecuteDecode(SF_VIDEO_ERR))
            {
                Lock::Locker lock(&pdecoder->DecodeLock);
                pdecoder->Players.RemoveAt(0);
                if (pdecoder->Players.GetSize() == 0)
                {
                    if (pdecoder->pDecodeThread)
                        FUN_14257dcb0(pdecoder->pDecodeThread);
                    pdecoder->pDecodeThread = NULL;
                    break;
                }
            }
        }
        else
        {
            Array<VideoPlayerImpl*> players(pdecoder->Players);
            pdecoder->DecodeLock.Unlock();
            Array<UPInt> finished;
            for (UPInt i = 0; i < players.GetSize(); ++i)
            {
                CriMvEasyPlayer* pcriPlayer = players[i]->pPlayer;
                if (!pcriPlayer->ExecuteDecode(SF_VIDEO_ERR))
                    finished.PushBack(i);
            }
            if (finished.GetSize() > 0)
            {
                Lock::Locker lock(&pdecoder->DecodeLock);
                for (UPInt j = 0; j < finished.GetSize(); ++j)
                    pdecoder->Players.RemoveAt(finished[j] - j);
                if (pdecoder->Players.GetSize() == 0)
                {
                    if (pdecoder->pDecodeThread)
                        FUN_14257dcb0(pdecoder->pDecodeThread);
                    pdecoder->pDecodeThread = NULL;
                    break;
                }
            }
        }
        FUN_14258b240(1);
    }
    return 0;
}

// The thread creation parameters (Thread::CreateParams).
struct VideoThreadCreateParams
{
    int       (*ThreadFunction)(Thread*, void*);
    void*     UserHandle;
    UPInt     StackSize;
    int       Processor;
    int       InitialState;
    int       Priority;
};

// MS2-FUNCTIONAL: the Thread::Start call loads its arguments in the other order
// @0x14002c0e0
void VideoDecoderThrd::StartDecoding(VideoPlayer* pp)
{
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)pp;
    {
        Lock::Locker lock(&DecodeLock);
        if (FindPlayer(Players, pplayer) != -1)
            return;
        Players.PushBack(pplayer);
    }

    if (!pDecodeThread)
    {
        VideoThreadCreateParams params = { DecodeFunc, this, 0x10000, -1, 0, ThreadPriority };
        void* mem = pHeap->Alloc(0x60);
        RefCountImpl* pthread = mem ? (RefCountImpl*)FUN_14258a490(mem, &params) : NULL;
        if (pDecodeThread)
            FUN_14257dcb0(pDecodeThread);
        pDecodeThread = pthread;
        // Thread::Start(Running), Thread::SetThreadName
        typedef bool (*StartFunc)(RefCountImpl*, int);
        typedef void (*SetNameFunc)(RefCountImpl*, const char*);
        if ((*reinterpret_cast<StartFunc**>(pthread))[5](pthread, 1) && pDecodeThread)
            (*reinterpret_cast<SetNameFunc**>(pDecodeThread))[7](pDecodeThread, "Scaleform Video Decoder");
    }
}

// ==== VideoPlayerImpl ================================================================================================

// MS2-FUNCTIONAL: the owned objects' constructors are inlined there
// @0x14002b530
bool VideoPlayerImpl::Init(Video* pvideo, TaskManager*, FileOpenerBase* pfileOpener, Log* plog)
{
    if (plog)
        FUN_14257dc30(plog);
    if (pLog)
        FUN_14257dcb0(pLog);
    pLog = plog;

    if (pvideo)
    {
        VideoSoundSystem* psoundSystem = pvideo->pSoundSystem;
        if (psoundSystem)
        {
            Ptr<VideoSound> pinterface    = *psoundSystem->Create();
            Ptr<VideoSound> psubinterface = *psoundSystem->Create();

            void* mem = pHeap->Alloc(0x50);
            VideoPlayerSound* psound = mem ? (VideoPlayerSound*)FUN_14002a010(mem, pHeap, pinterface) : NULL;
            pSound = *psound;

            mem = pHeap->Alloc(0x50);
            psound = mem ? (VideoPlayerSound*)FUN_14002a010(mem, pHeap, psubinterface) : NULL;
            pSubSound = *psound;
        }
    }

    VideoDecoder* pdecoder = pvideo ? pvideo->pDecoder.GetPtr() : NULL;
    if (pdecoder)
        pdecoder->AddRef();
    if (pDecoder)
        pDecoder->Release();
    pDecoder = pdecoder;
    if (!pDecoder)
    {
        pDecoder = SF_HEAP_NEW(pHeap) VideoDecoderSmp;
    }

    if (pvideo)
    {
        VideoReader* preader = pvideo->pReaderConfig->CreateReader();
        pReader = *preader;
    }
    else
    {
        void* mem = pHeap->Alloc(0x40);
        VideoReaderConfig* pconfig = mem ? ::new(mem) VideoReaderConfigSmp(pHeap, pfileOpener) : NULL;
        mem = pHeap->Alloc(0x50);
        VideoReader* preader = mem ? ::new(mem) VideoReader(pconfig) : NULL;
        pReader = *preader;
        if (pconfig)
            pconfig->Release();
    }

    void* mem = pHeap->Alloc(0x48);
    VideoPlayer::SyncObject* psyncObj = mem ? (VideoPlayer::SyncObject*)FUN_140041c00(mem) : NULL;
    mem = pHeap->Alloc(0x20);
    CriMvSystemTimer* ptimer = mem ? (CriMvSystemTimer*)FUN_140029e40(mem, psyncObj) : NULL;
    pTimer = *ptimer;

    pPlayer = CriMvEasyPlayer::Create((CriHeap)pCriHeap,
                                      pReader ? (CriMvFileReaderInterface*)((UByte*)pReader.GetPtr() + 0x10) : NULL,
                                      pTimer ? static_cast<CriMvSystemTimerInterface*>(pTimer.GetPtr()) : NULL,
                                      pSound ? (CriMvSoundInterface*)((UByte*)pSound.GetPtr() + 0x10) : NULL,
                                      SF_VIDEO_ERR);
    if (pSound && UseAudioTimer)
        pPlayer->SetMasterTimer(CriMvEasyPlayer::MVEASY_TIMER_AUDIO, SF_VIDEO_ERR);
    else
        pPlayer->SetMasterTimer(CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
    Stat = Stopped;
    if (psyncObj)
        psyncObj->Release();
    return true;
}

// The cue point a CRI event point describes: "name=value,name=value" parameters.
// MS2-FUNCTIONAL: a constructor of CuePoint there
// @0x14002c2b0
static VideoPlayer::CuePoint* ConstructCuePoint(VideoPlayer::CuePoint* pcue, const CriMvEventPoint* pevent)
{
    ::new(&pcue->Name) String();
    ::new(&pcue->Params) Array<VideoPlayer::CuePointParam>();
    pcue->Name = pevent->cue_name;
    pcue->Type = pevent->type == 0 ? VideoPlayer::NavigationCuePoint : VideoPlayer::EventCuePoint;
    pcue->Time = (UInt32)pevent->time;
    const char* p = pevent->param_string;
    if (p)
    {
        VideoPlayer::CuePointParam param;
        while (p)
        {
            const char* peq = strchr(p, '=');
            if (!peq)
            {
                param.Name = p;
                pcue->Params.PushBack(param);
                break;
            }
            FUN_142586530(&param.Name, p, peq - p);
            p = peq + 1;
            const char* pcomma = strchr(p, ',');
            if (!pcomma)
            {
                param.Value = p;
                pcue->Params.PushBack(param);
                break;
            }
            FUN_142586530(&param.Value, p, pcomma - p);
            pcue->Params.PushBack(param);
            param.Name.Clear();
            param.Value.Clear();
            p = pcomma + 1;
        }
    }
    return pcue;
}

// @0x14002c5f0
VideoPlayerImpl::~VideoPlayerImpl()
{
    StopAndWait();
    if (pSubSound)
        pPlayer->DetachSubAudioInterface(SF_VIDEO_ERR);
    if (pPlayer)
        pPlayer->Destroy(SF_VIDEO_ERR);
    pPlayer = NULL;
    pTimer.Clear();
    pSound.Clear();
    pSubSound.Clear();
    pReader.Clear();
    FUN_140041dd0(pCriHeap);
    if (pLog)
        FUN_14257dcb0(pLog);
    if (pDecoder)
        pDecoder->Release();
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002c730
VideoPlayer::Status VideoPlayerImpl::GetStatus()
{
    return Stat;
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002c740
bool VideoPlayerImpl::IsTextureReady()
{
    return UpdateTextureCalled && FrameOnTime;
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002c7a0
void VideoPlayerImpl::CuePointCallback(CriMvEasyPlayer*, CriMvEventPoint* eventinfo, void* usrobj)
{
    if (!usrobj)
        return;
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)usrobj;
    VideoPlayer::CuePoint cue;
    pplayer->CurrentCuePoints.PushBack(*ConstructCuePoint(&cue, eventinfo));
}

// @0x14002c810
VideoPlayerImpl::VideoPlayerImpl(MemoryHeap* pheap)
    : pPlayer(NULL), Stat(NotInitialized), pTimer(), pReader(), pSound(), pSubSound(),
      Width(~0u), Height(~0u), HasAlpha(false), CurrentFrame(0), StartFrame(0), StatusAfterStop(Finished),
      PauseFlag(0), LoopFlag(0), UpdateTextureCalled(false), FrameOnTime(false), PauseLocked(false),
      PausePending(false), SubtitleChannel(-1), DecodeHeaderTimeout(0), UseAudioTimer(true), pDecoder(NULL),
      pHeap(pheap), pLog(NULL)
{
    pCriHeap = FUN_140041d40(pheap);
}

// Puts the player back to the state of a newly opened file (Open and the SetSyncObject restart).
static __forceinline void ResetForOpen(VideoPlayerImpl* p)
{
    p->StopAndWait();
    p->pPlayer->SetCuePointCallback(NULL, NULL, SF_VIDEO_ERR);
    p->CurrentCuePoints.Clear();
    p->StartFrame      = 0;
    p->CurrentFrame    = 0;
    p->Stat            = VideoPlayer::Opening;
    p->StatusAfterStop = VideoPlayer::Finished;
    p->PauseFlag       = 0;
    p->UpdateTextureCalled = false;
    p->SubtitleChannel = -1;
    memset(&p->StmPrm, 0, sizeof(p->StmPrm));
    memset(&p->FrameInfo, 0, sizeof(p->FrameInfo));
}

// @0x14002c930
void VideoPlayerImpl::Open(const char* url)
{
    ResetForOpen(this);
    pPlayer->SetFile((CriChar8*)url, SF_VIDEO_ERR);
    pPlayer->DecodeHeader(SF_VIDEO_ERR);
    pDecoder->StartDecoding(this);
    if (pSubSound)
        pPlayer->AttachSubAudioInterface((CriMvSoundInterface*)((UByte*)pSubSound.GetPtr() + 0x10), SF_VIDEO_ERR);
    OpenTicks = FUN_1425e3590();
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002ca30
void VideoPlayerImpl::GetVideoInfo(VideoInfo* info)
{
    if (!(Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking))
        return;

    info->Width         = StmPrm.video_prm[0].max_width;
    info->Height        = StmPrm.video_prm[0].max_height;
    info->FrameRate     = StmPrm.video_prm[0].framerate;
    info->AudioDataRate = StmPrm.num_audio > 0 ? StmPrm.audio_prm[0].sampling_rate : 0;
    info->TotalFrames   = StmPrm.video_prm[0].total_frames;
    info->SubtitleChannelsNumber = StmPrm.num_subtitle;
    info->MaxSubtitleLen         = StmPrm.max_subtitle_size;

    if (info->AudioTracks.GetSize() == 0)
    {
        for (int i = 0; i < CRIMV_MAX_AUDIO_NUM; i++)
        {
            const CriMvAudioParameters& aprm = StmPrm.audio_prm[i];
            if (aprm.num_channel)
            {
                AudioTrackInfo track;
                track.Index          = i;
                track.SampleRate     = aprm.sampling_rate;
                track.ChannelsNumber = aprm.num_channel;
                track.TotalSamples   = aprm.total_samples;
                info->AudioTracks.PushBack(track);
            }
        }
    }

    if (info->CuePoints.GetSize() == 0)
    {
        CriMvCuePointInfo* pcueinfo = pPlayer->GetCuePointInfo(SF_VIDEO_ERR);
        if (pcueinfo)
        {
            for (unsigned i = 0; i < pcueinfo->num_eventpoint; i++)
            {
                CuePoint cue;
                info->CuePoints.PushBack(*ConstructCuePoint(&cue, &pcueinfo->eventtable[i]));
            }
            pPlayer->SetCuePointCallback(CuePointCallback, this, SF_VIDEO_ERR);
        }
    }
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002cd40
void VideoPlayerImpl::SetSyncObject(SyncObject* psyncObj)
{
    if (Stat == Opening || Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking || Stat == Stopping)
    {
        // Switching clocks while a movie is open restarts it from its header.
        ResetForOpen(this);
        if (!psyncObj)
        {
            void* mem = pHeap->Alloc(0x48);
            Ptr<SyncObject> ps = *(mem ? (SyncObject*)FUN_140041c00(mem) : NULL);
            pTimer->pSyncObj = ps;
            pPlayer->SetMasterTimer(pSound && UseAudioTimer ? CriMvEasyPlayer::MVEASY_TIMER_AUDIO
                                                             : CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
        }
        else
        {
            pTimer->pSyncObj = psyncObj;
            pPlayer->SetMasterTimer(CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
        }
        pPlayer->DecodeHeader(SF_VIDEO_ERR);
        pDecoder->StartDecoding(this);
        OpenTicks = FUN_1425e3590();
        return;
    }

    if (!psyncObj)
    {
        if (pTimer->pSyncObj)
            return;
        void* mem = pHeap->Alloc(0x48);
        Ptr<SyncObject> ps = *(mem ? (SyncObject*)FUN_140041c00(mem) : NULL);
        pTimer->SetSyncObject(ps);
        pPlayer->SetMasterTimer(pSound && UseAudioTimer ? CriMvEasyPlayer::MVEASY_TIMER_AUDIO
                                                         : CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
    }
    else if (pTimer->pSyncObj != psyncObj)
    {
        pTimer->SetSyncObject(psyncObj);
        pPlayer->SetMasterTimer(CriMvEasyPlayer::MVEASY_TIMER_SYSTEM, SF_VIDEO_ERR);
    }
}

// @0x14002cfe0
void VideoPlayerImpl::GetCurrentCuePoints(Array<CuePoint>* cuePoints)
{
    if (CurrentCuePoints.GetSize() > 0)
    {
        *cuePoints = CurrentCuePoints;
        CurrentCuePoints.Clear();
    }
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002d020
bool VideoPlayer::LoadVideoInfo(const char* url, VideoInfo* pinfo, FileOpenerBase* pfileOpener)
{
    bool ok = false;
    struct { unsigned Flags; UPInt MinAlign, Granularity, Reserve, Threshold, Limit, HeapId, Arena; } desc =
        { 0, 16, 16 * 1024, 16 * 1024, ~UPInt(0), 0, 8 /* HeapId_Video */, 0 };
    MemoryHeap* pheap = Memory::GetGlobalHeap()->CreateHeap("_VideoInfo_Heap", *(const HeapDesc*)&desc);
    void* mem = pheap->Alloc(sizeof(VideoPlayerImpl));
    VideoPlayerImpl* pplayer = mem ? ::new(mem) VideoPlayerImpl(pheap) : NULL;
    pplayer->Init(NULL, NULL, pfileOpener, NULL);
    pplayer->Open(url);
    while (pplayer->GetStatus() == Opening)
        pplayer->Decode();
    if (pplayer->GetStatus() == Ready)
    {
        ok = true;
        pplayer->GetVideoInfo(pinfo);
    }
    pplayer->Destroy();
    pheap->Release();
    return ok;
}

// ==== VideoReader ====================================================================================================

// The reader's file: a Scaleform File held as a thread-safe reference.
static inline File* ReaderFile(RefCountImpl* pfile) { return (File*)pfile; }

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002d230
CriSint64 VideoReader::Seek(CriSint64 size, SeekOrigin offset)
{
    switch (offset)
    {
    case SEEK_FROM_CURRENT: Position = FilePos;  break;
    case SEEK_FROM_END:     Position = FileSize; break;
    default:                Position = 0;        break;
    }
    Position += size;
    return Position;
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002d4f0
void VideoReader::OpenFile(const char* fname)
{
    File* pfile = pReaderConfig->pFileOpener->OpenFile(fname, FileConstants::Open_Read | FileConstants::Open_Buffered,
                                                       FileConstants::Mode_ReadWrite);
    if (pFile)
        pFile->Release();
    pFile = (RefCountImpl*)pfile;
    if (pfile && pfile->IsValid())
    {
        FileSize   = ReaderFile(pFile)->GetLength();
        OpenStatus = ASYNC_STATUS_COMPLETE;
    }
    else
    {
        OpenStatus  = ASYNC_STATUS_ERROR;
        ReadStatus  = ASYNC_STATUS_ERROR;
        CloseStatus = ASYNC_STATUS_ERROR;
    }
}

// @0x14002d590
void VideoReader::CloseFile()
{
    if (pFile && !ReaderFile(pFile)->Close())
        CloseStatus = ASYNC_STATUS_ERROR;
    else
        CloseStatus = ASYNC_STATUS_COMPLETE;
    if (pFile)
        pFile->Release();
    pFile = NULL;
}

// @0x14002d5e0
void VideoReader::ReadFile(UByte* buffer, SInt64 size)
{
    if (pFile && ReaderFile(pFile)->IsValid())
    {
        if (!pReaderConfig->IOEnabled)
        {
            ReadSize   = 0;
            ReadStatus = ASYNC_STATUS_COMPLETE;
            return;
        }
        if (FilePos != Position)
        {
            if (ReaderFile(pFile)->LSeek(Position, File::Seek_Set) == -1)
            {
                ReadStatus = ASYNC_STATUS_ERROR;
                return;
            }
            FilePos = Position;
        }
        SInt64 toread = (FilePos + size > FileSize) ? FileSize - FilePos : size;
        int    nread  = ReaderFile(pFile)->Read(buffer, (int)toread);
        if (nread != -1)
        {
            ReadSize   = nread;
            ReadStatus = ASYNC_STATUS_COMPLETE;
            FilePos   += nread;
            Position   = FilePos;
            return;
        }
    }
    ReadStatus = ASYNC_STATUS_ERROR;
}

// MS2-FUNCTIONAL: the exe AddRefs the config inline (non-atomic inc [config+8]), not via RefCountImpl::AddRef
// @0x14002ddd0
void* FUN_14002ddd0(void* object, VideoReaderConfig* config)
{
    void** fields = (void**)object;
    *((CriUint32*)object + 2) = 1;
    fields[0] = (void*)DAT_1431b93b0;
    fields[2] = (void*)DAT_1431b9360;
    if (config)
        FUN_14257dc30(config);
    fields[3] = config;
    fields[4] = NULL;
    *((CriUint32*)object + 10) = 0;
    FUN_14001d650(config, object);
    *((CriUint32*)object + 11) = 0;
    fields[0] = (void*)DAT_1431b9410;
    *((CriUint32*)object + 13) = 0;
    fields[2] = (void*)DAT_1431b93c0;
    *((CriUint32*)object + 12) = 0;
    return object;
}

// Lazily start the threaded reader service and allocate a reader on the configured heap. As in the exe, the new thread
// is started without a null check.
// MS2-FUNCTIONAL: the Thread::Start call loads its arguments in the other order, as in StartDecoding
// @0x14002e050
VideoReader* VideoReaderConfigThrd::CreateReader()
{
    typedef void* (*AllocFunc)(void*, size_t, const void*);
    typedef bool (*StartFunc)(void*, int);   // Thread::Start(Running)
    typedef void (*SetNameFunc)(void*, const char*);
    void** config = (void**)this;
    if (!config[31])
    {
        VideoThreadCreateParams params = { (int (*)(Thread*, void*))FUN_14002db40, this, 0x10000, -1, 0, 1 };
        void* memory = (*(AllocFunc*)(*(CriUint8**)config[2] + 0x50))(config[2], 0x60, NULL);
        void* thread = memory ? FUN_14258a490(memory, &params) : NULL;
        if (config[31])
            FUN_14257dcb0(config[31]);
        config[31] = thread;
        if ((*(StartFunc**)config[31])[5](config[31], 1))
            (*(SetNameFunc**)config[31])[7](config[31], "Scaleform Video Reader");
    }
    void* memory = (*(AllocFunc*)(*(CriUint8**)config[2] + 0x50))(config[2], 0x50, NULL);
    return memory ? (VideoReader*)FUN_14002ddd0(memory, this) : NULL;
}

// @0x14002e450
void* FUN_14002e450(void* object, void* heap, void* opener)
{
    void** fields = (void**)object;
    CriUint32* words = (CriUint32*)object;
    fields[0] = (void*)DAT_1431b91b0;
    words[2] = 1;
    fields[2] = heap;
    if (opener)
        FUN_14257dc30(opener);
    fields[3] = opener;
    _ReadWriteBarrier();   // the member initializers run in order: Ptr<FileOpenerBase>, then Readers
    CriUint64* readers = (CriUint64*)(fields + 4);   // Array<VideoReader*>
    readers[0] = 0;
    readers[1] = 0;
    readers[2] = 0;
    fields[0] = (void*)DAT_1431b9430;
    _ReadWriteBarrier();   // the vftable is stored before IOEnabled and the pool
    *((CriUint8*)object + 0x38) = 1;
    _ReadWriteBarrier();
    void** pool = fields + 8;   // request node pool
    pool[0] = NULL;
    pool[1] = NULL;
    *(CriUint32*)(pool + 2) = 0x7f;
    pool[3] = NULL;
    pool[4] = pool;
    _ReadWriteBarrier();
    void** sentinel = fields + 13;
    sentinel[0] = sentinel;
    sentinel[1] = sentinel;
    FUN_14258a350(fields + 15, true, false);
    FUN_142582300(fields + 20, 0, 0);
    fields[31] = NULL;
    FUN_14258a620(fields + 32);
    fields[33] = NULL;
    return object;
}

// Release the threaded reader config's sync state, live readers and retained CRI opener.
// @0x14002e2a0
void FUN_14002e2a0(void* object)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_1431b9430;
    if (fields[33])
        FUN_14257dcb0(fields[33]);
    FUN_14258a810(fields + 32);
    if (fields[31])
        FUN_14257dcb0(fields[31]);
    FUN_142582530(fields + 20);
    FUN_14258a720(fields + 15);
    void* reader = fields[8];
    while (reader)
    {
        void* next = *(void**)((CriUint8*)reader + 0x1bc8);
        FUN_14002d3f0(reader);
        reader = next;
    }
    if (fields[4])
        FUN_14002d3f0(fields[4]);
    if (fields[3])
        FUN_14257dcb0(fields[3]);
    FUN_14257db50(object);
}

// VideoReader's primary vftable (no RTTI in this build): the constructor stores it at +0, 0x1431b9360 at +0x10
// MS2-PIN: ??_7VideoReader@Video@GFx@Scaleform@@6B?$RefCountBaseNTS@VVideoReader@Video@GFx@Scaleform@@$01@3@@ 0x1431b93b0
// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002d970
VideoReader::VideoReader(VideoReaderConfig* pconfig)
    : pReaderConfig(pconfig), pFile(NULL), ReadSize(0)
{
    FUN_14001d650(pconfig, this);
    OpenStatus  = ASYNC_STATUS_STOP;
    ReadStatus  = ASYNC_STATUS_STOP;
    CloseStatus = ASYNC_STATUS_STOP;
}

__forceinline VideoReader::VideoReader(VideoReaderConfig* pconfig, InlineCtorTag)
    : pReaderConfig(pconfig), pFile(NULL), ReadSize(0)
{
    FUN_14001d650(pconfig, this);
    OpenStatus  = ASYNC_STATUS_STOP;
    ReadStatus  = ASYNC_STATUS_STOP;
    CloseStatus = ASYNC_STATUS_STOP;
}

// @0x14002d430
VideoReader::~VideoReader()
{
    pReaderConfig->DetachReader(this);
    if (pFile)
        pFile->Release();
}

// Run the VideoReader destructor body and its multiple-inheritance base cleanup.
// @0x14002de60
void FUN_14002de60(VideoReader* reader)
{
    reader->VideoReader::~VideoReader();  // non-virtual: a virtual call re-enters this deleting dtor
}

// Destroy the VideoReader and optionally return its allocation to the global heap.
// @0x14002d9e0
void* FUN_14002d9e0(VideoReader* reader, CriUint32 flags)
{
    reader->VideoReader::~VideoReader();  // non-virtual: a virtual call re-enters this deleting dtor
    if (flags & 1)
        FUN_14002d3f0(reader);
    return reader;
}

// Destroy the alternate VideoReader interface view with the same delete flag semantics.
// @0x14002dec0
void* FUN_14002dec0(VideoReader* reader, CriUint32 flags)
{
    reader->VideoReader::~VideoReader();  // non-virtual: a virtual call re-enters this deleting dtor
    if (flags & 1)
        FUN_14002d3f0(reader);
    return reader;
}

// MS2-FUNCTIONAL: register allocation and block order differ
// @0x14002da70
void VideoReader::Open(CriChar8* fname)
{
    FileSize = -1;
    ReadSize = 0;
    FilePos  = 0;
    Position = 0;
    OpenFile((const char*)fname);
}

// @0x14002da90
void VideoReader::Close(void)
{
    CloseFile();
}

// @0x14002dae0
void VideoReader::Read(CriUint8* buffer, CriSint64 req_size)
{
    while (!pReaderConfig->IOEnabled)
        FUN_14258b240(50);
    ReadFile(buffer, req_size);
}

// ==== VideoReaderConfigSmp ===========================================================================================

// @0x14002df50
VideoReader* VideoReaderConfigSmp::CreateReader()
{
    void* mem = pHeap->Alloc(sizeof(VideoReader));
    return mem ? ::new(mem) VideoReader(this, VideoReader::InlineCtor) : NULL;
}

}}} // namespace Scaleform::GFx::Video

// Append a request node to the reader queue under its lock and wake the worker event. noinline: the exe's
// close request (0x14002e230) calls it.
// @0x14002e140
__declspec(noinline) void FUN_14002e140(void* queue, CriUint32 operation, void* request, void* a, void* b, void* c)
{
    CriMvRequestQueueView* queueView = (CriMvRequestQueueView*)queue;
    FUN_14258aca0(queueView->Lock);
    CriMvRequestNode* node = FUN_14002d890((CriMvRequestPoolView*)&queueView->Reserved0[0x40]);
    node->Operation = operation;
    node->Request = request;
    node->ArgumentA = a;
    node->ArgumentB = b;
    node->ArgumentC = c;
    node->Next = queueView->Head;
    node->Previous = (CriMvRequestNode*)&queueView->Head;
    queueView->Head->Previous = node;
    queueView->Head = node;
    FUN_14258bb70(queueView->Lock);
    FUN_142583d50(queueView->Event);
}

// Initialize the reader request state and enqueue its open operation.
// @0x14002e1e0
void FUN_14002e1e0(void* object, void* input)
{
    CriMvReaderRequestView* state = (CriMvReaderRequestView*)object;
    state->OpenPending = 1;
    state->FileSize = ~(CriUint64)0;
    state->ReadPending = 0;
    state->ClosePending = 0;
    state->ReadBytes = 0;
    state->ReadPosition = 0;
    state->ReadSize = 0;
    FUN_14002e140(state->Queue, 0, (CriUint8*)object - 0x10, input, NULL, NULL);
}

// Mark close pending and append the reader close operation.
// @0x14002e230
void FUN_14002e230(void* object)
{
    CriMvReaderRequestView* state = (CriMvReaderRequestView*)object;
    state->ClosePending = 1;
    FUN_14002e140(state->Queue, 2, (CriUint8*)object - 0x10, NULL, NULL, NULL);
}

// Mark the request as pending and enqueue the selected reader operation.
// @0x14002e260
void FUN_14002e260(void* object, void* first, void* second)
{
    CriMvReaderRequestView* state = (CriMvReaderRequestView*)object;
    state->ReadPending = 1;
    FUN_14002e140(state->Queue, 1, (CriUint8*)object - 0x10, NULL, first, second);
}

// VideoReaderConfigThrd::DetachReader: remove all requests for a detached reader, return their nodes, then stop an idle
// worker.
// @0x14002e370
void FUN_14002e370(CriMvRequestManagerView* manager, void* reader)
{
    FUN_14258aca0(manager->Lock);
    CriMvRequestNode* node = manager->Tail;
    while (node != (CriMvRequestNode*)&manager->Head)
    {
        CriMvRequestNode* previous = node->Previous;
        if (node->Request == reader)
        {
            node->Next->Previous = node->Previous;
            node->Previous->Next = node->Next;
            node->Next = manager->FreeList;
            manager->FreeList = node;
        }
        node = previous;
    }
    FUN_14258bb70(manager->Lock);
    FUN_14001d720(manager, reader);
    if (!manager->ActiveReader && manager->StopEvent)
    {
        FUN_14002e140(manager, 3, NULL, NULL, NULL, NULL);
        FUN_1425845e0(manager->StopEvent, -1);
        if (manager->StopEvent)
            FUN_14257dcb0(manager->StopEvent);
        manager->StopEvent = NULL;
    }
}

// @0x14002a380
void FUN_14002a380(void* array, void* source, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    if (length < fields[1])
    {
        if (length < (fields[2] >> 1))
            FUN_140029bf0(array, source, length);
    }
    else if (length >= fields[2])
        FUN_140029bf0(array, source, length + (length >> 2));
    fields[1] = length;
}

// @0x14002a3e0
void FUN_14002a3e0(void* array, void* source, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    if (length < fields[1])
    {
        if (length < (fields[2] >> 1))
            FUN_140029c90(array, source, length);
    }
    else if (length >= fields[2])
        FUN_140029c90(array, source, length + (length >> 2));
    fields[1] = length;
}

// @0x14002a440
void FUN_14002a440(void* array, void* source, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    if (length < fields[1])
    {
        if (length < (fields[2] >> 1))
            FUN_140029d30(array, source, length);
    }
    else if (length >= fields[2])
        FUN_140029d30(array, source, length + (length >> 2));
    fields[1] = length;
}

// ArrayData::ResizeNoConstruct as the PushBacks inline it: newSize arrives by value, so Size is read again.
typedef void (*CriArrayReserveFn)(void* array, void* source, CriUint64 capacity);
static inline void CriArrayResizeNoConstruct(CriUint64* array, CriArrayReserveFn reserve, CriUint64 newSize)
{
    if (newSize < array[1])
    {
        if (newSize < (array[2] >> 1))
            reserve(array, array, newSize);
    }
    else if (newSize >= array[2])
        reserve(array, array, newSize + (newSize >> 2));
    array[1] = newSize;
}

// @0x14002a780
void FUN_14002a780(CriUint64* array, const CriUint64* value)
{
    CriArrayResizeNoConstruct(array, FUN_140029bf0, array[1] + 1);
    CriUint64* destination = (CriUint64*)array[0] + array[1] - 1;
    if (destination)
        *destination = *value;
}

// @0x14002a800
void FUN_14002a800(CriUint64* array, const CriUint64* value)
{
    CriArrayResizeNoConstruct(array, FUN_140029c90, array[1] + 1);
    CriUint64* destination = (CriUint64*)array[0] + array[1] - 1;
    if (destination)
        *destination = *value;
}

// @0x14002a880
void FUN_14002a880(void* array, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    if (length < fields[1])
    {
        if (length < (fields[2] >> 1))
            FUN_140029d30(array, array, length);
    }
    else if (length >= fields[2])
        FUN_140029d30(array, array, length + (length >> 2));
    fields[1] = length;
}

// @0x14002a9b0
void FUN_14002a9b0(void* array, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    if (length < fields[1])
    {
        if (length < (fields[2] >> 1))
            FUN_140029bf0(array, array, length);
    }
    else if (length >= fields[2])
        FUN_140029bf0(array, array, length + (length >> 2));
    fields[1] = length;
}

// Erase one eight-byte vector entry and shift the remaining entries down.
// @0x14002b9e0
void FUN_14002b9e0(CriUint64* array, CriUint64 index)
{
    if (array[1] == 1)
    {
        FUN_14002afe0(array);
        return;
    }
    CriUint64* destination = (CriUint64*)(array[0] + index * 8);
    memmove(destination, destination + 1, (size_t)((array[1] - index - 1) * 8));
    --array[1];
}

// @0x14002a550
void FUN_14002a550(void* items, CriSint64 count)
{
    CriUint8* current = (CriUint8*)items;
    for (CriUint64 i = (CriUint64)count; i != 0; --i, current += 0x10)
    {
        if (current)
        {
            FUN_142584ce0(current);
            FUN_142584ce0(current + 8);
        }
    }
}

// @0x14002aa30
void FUN_14002aa30(CriUint64* array, CriUint64 length)
{
    CriUint64 oldLength = array[1];
    FUN_140006f50(array, array, length);
    if (length > oldLength)
    {
        CriUint8* item = (CriUint8*)array[0] + oldLength * 0x10;
        for (CriUint64 i = length - oldLength; i != 0; --i, item += 0x10)
        {
            if (item)
            {
                FUN_142584ce0(item);
                FUN_142584ce0(item + 8);
            }
        }
    }
}

// Release the owned opener and heap blocks before destroying the reference-count base.
// @0x14002ab90
void FUN_14002ab90(void* object)
{
    void** fields = (void**)object;
    if (fields[4])
        FUN_14002d3f0(fields[4]);
    if (fields[3])
        FUN_14257dcb0(fields[3]);
    FUN_14257db50(object);
}

// @0x14002aab0
void* FUN_14002aab0(void* object, void* first, void* second)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_142dc9d48;   // RefCountImplCore base vftable
    _ReadWriteBarrier();
    *(CriUint32*)((CriUint8*)object + 8) = 1;
    fields[0] = (void*)DAT_143149940;
    _ReadWriteBarrier();
    fields[2] = first;
    fields[3] = second;
    fields[4] = NULL;
    if (first)
        FUN_14257dc30(first);
    return object;
}

// Tear down the video player reference core and optionally free the object storage.
// @0x14002a0e0
void* FUN_14002a0e0(void* object, CriUint32 flags)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_1431b9028;
    fields[2] = (void*)DAT_1431b8fd0;
    fields[5] = (void*)DAT_1431b8f18;
    if (fields[4])
        FUN_14257dcd0(fields[4]);
    fields[2] = (void*)DAT_1431b8db0;
    FUN_14257db50(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: initialize the extended reference core and its embedded allocator metadata.
// @0x14002abd0
void* FUN_14002abd0(void* object, CriUint32 tag, const CriUint32* sizePair,
                    const void* source, void* owner)
{
    CriUint32* words = (CriUint32*)object;
    void** fields = (void**)object;
    fields[0] = (void*)DAT_143149940;
    words[2] = 1;
    fields[2] = NULL;
    fields[3] = source ? (CriUint8*)source + 0x10 : NULL;
    fields[4] = NULL;
    words[10] = tag;
    fields[0] = (void*)DAT_143183b28;
    words[11] = sizePair[0];
    words[12] = sizePair[1];
    words[13] = 0x10;
    words[14] = FUN_14257bdc0();
    fields[0] = (void*)DAT_1431b9080;
    fields[8] = owner;
    return object;
}

// @0x14002aec0
void FUN_14002aec0(CriUint64* array)
{
    // ResizeNoConstruct(0): shrinking to an empty array frees it, growing from capacity 0 reserves 0
    const CriUint64 newSize = 0;
    if (newSize < array[1])
    {
        if (newSize < (array[2] >> 1))
        {
            if (array[0])
            {
                FUN_14002d3f0((void*)array[0]);
                array[0] = 0;
            }
            array[2] = 0;
        }
    }
    else if (newSize >= array[2])
        FUN_140029d30(array, array, newSize + (newSize >> 2));
    array[1] = newSize;
}

// Destroy the same owned fields and optionally free the containing allocation.
// @0x14002b0f0
void* FUN_14002b0f0(void* object, CriUint32 flags)
{
    void** fields = (void**)object;
    if (fields[4])
        FUN_14002d3f0(fields[4]);
    if (fields[3])
        FUN_14257dcb0(fields[3]);
    FUN_14257db50(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// @0x14002b070
void* FUN_14002b070(void* object, void* heap, void* opener)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_1431b91b0;
    *((CriUint32*)fields + 2) = 1;
    fields[2] = heap;
    if (opener)
        FUN_14257dc30(opener);
    fields[3] = opener;
    _ReadWriteBarrier();   // the member initializers run in order: Ptr<FileOpenerBase>, then Readers
    fields[4] = NULL;
    fields[5] = NULL;
    fields[6] = NULL;
    _ReadWriteBarrier();   // IOEnabled is set after the inlined Array ctor
    *((CriUint8*)object + 0x38) = 1;
    return object;
}

// @0x14002b1b0
void FUN_14002b1b0(void* object)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_1431b91d8;
    _ReadWriteBarrier();   // a dtor's vftable store is not moved past the member reads
    if (fields[4])
        FUN_14002d3f0(fields[4]);
    if (fields[3])
        FUN_14257dcb0(fields[3]);
    FUN_14257db50(object);
}

// @0x14002b150
void* FUN_14002b150(void* object, void* heap, void* opener)
{
    FUN_14002b070(object, heap, opener);
    *(void**)object = (void*)DAT_1431b91d8;
    return object;
}

// @0x14002b200
void* FUN_14002b200(void* object, CriUint32 flags)
{
    FUN_14002b1b0(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// @0x14002ad30
void FUN_14002ad30(void* object)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_1431b9170;
    _ReadWriteBarrier();   // a dtor's vftable store is not moved past the member reads
    if (fields[6])
        FUN_14002d3f0(fields[6]);
    if (fields[3])
        FUN_14002d3f0(fields[3]);
    FUN_14257db50(object);
}

// @0x14002b350
void* FUN_14002b350(void* object, CriUint32 flags)
{
    FUN_14002ad30(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// @0x14002c4b0
void FUN_14002c4b0(CriUint64* array, const CriUint32* value)
{
    FUN_14000bc40(array, array, array[1] + 1);
    CriUint32* destination = (CriUint32*)(array[0] - 0x30 + array[1] * 0x30);
    if (!destination)
        return;
    destination[0] = value[0];
    FUN_142584950(destination + 2, value + 2);
    destination[4] = value[4];
    CriUint64* inner = (CriUint64*)(destination + 6);
    inner[0] = 0;
    inner[1] = 0;
    inner[2] = 0;
    FUN_140007370(inner, *(const CriUint64*)(value + 6), *(const CriUint64*)(value + 8));
}

// @0x14002ba30
__declspec(noinline) CriUint64* FUN_14002ba30(CriUint64* destination, const CriUint64* source)
{
    // Array::operator=: Resize, then assign each string pair; Data is reloaded after every assignment
    FUN_14002aa30(destination, source[1]);
    for (CriUint64 i = 0; i < destination[1]; ++i)
    {
        const CriUint8* in = (const CriUint8*)source[0] + i * 0x10;
        CriUint8* out = (CriUint8*)destination[0] + i * 0x10;
        FUN_142585580(out, in);
        FUN_142585580(out + 8, in + 8);
    }
    return destination;
}

// @0x14002c550
CriUint64* FUN_14002c550(CriUint64* destination, const CriUint64* source)
{
    FUN_14000bd60(destination, source[1]);
    for (CriUint64 i = 0; i < destination[1]; ++i)
    {
        const CriVideoRecordCopyView* sourceRecord = (const CriVideoRecordCopyView*)source[0] + i;
        CriVideoRecordCopyView* record = (CriVideoRecordCopyView*)destination[0] + i;
        record->Type = sourceRecord->Type;
        FUN_142585580(&record->Name, &sourceRecord->Name);
        record->Flags = sourceRecord->Flags;
        FUN_14002ba30(record->NestedStrings, sourceRecord->NestedStrings);
    }
    return destination;
}

// Copy the descriptor fields and nested string vector of a video record.
// @0x14002c260
CriUint32* FUN_14002c260(CriUint32* destination, const CriUint32* source)
{
    destination[0] = source[0];
    FUN_142585580(destination + 2, source + 2);
    destination[4] = source[4];
    FUN_14002ba30((CriUint64*)(destination + 6), (const CriUint64*)(source + 6));
    return destination;
}

// @0x14002a900
void FUN_14002a900(CriUint64* array, const CriUint32* value)
{
    CriArrayResizeNoConstruct(array, FUN_140029d30, array[1] + 1);
    CriUint32* destination = (CriUint32*)(array[0] - 12 + array[1] * 12);
    if (destination)
    {
        destination[0] = value[0];
        destination[1] = value[1];
        destination[2] = value[2];
    }
}

// @0x14002a6f0
void FUN_14002a6f0(CriUint64* array, const CriUint32* value)
{
    CriArrayResizeNoConstruct(array, FUN_1400051c0, array[1] + 1);
    CriUint32* destination = (CriUint32*)(array[0] - 16 + array[1] * 16);
    if (destination)
    {
        destination[0] = value[0];
        destination[1] = value[1];
        destination[2] = value[2];
        destination[3] = value[3];
    }
}

// Append a pair of retained strings to the first fixed-width string vector.
// @0x14002af50
void FUN_14002af50(CriUint64* array, const CriUint64* value)
{
    FUN_140006f50(array, array, array[1] + 1);
    CriUint64* destination = (CriUint64*)(array[0] - 0x10 + array[1] * 0x10);
    if (destination)
    {
        FUN_142584950(destination, value);
        FUN_142584950(destination + 1, value + 1);
    }
}

// Append a pair of retained strings to the second fixed-width string vector.
// @0x14002b950
void FUN_14002b950(CriUint64* array, const CriUint64* value)
{
    FUN_140006f50(array, array, array[1] + 1);
    CriUint64* destination = (CriUint64*)(array[0] - 0x10 + array[1] * 0x10);
    if (destination)
    {
        FUN_142584950(destination, value);
        FUN_142584950(destination + 1, value + 1);
    }
}

// Initialize a lock guard's stored lock pointer and acquire the lock.
// @0x14002d1a0
void* FUN_14002d1a0(void* guard, void* lock)
{
    *(void**)guard = lock;
    FUN_14258aca0(lock);
    return guard;
}

// Restore the abstract reader interface vtable and run its scalar delete path when requested.
// @0x14002d170
void* FUN_14002d170(CriMvFileReaderInterface* reader, CriUint8 flags)
{
    *(const void***)reader = DAT_1431b95e8;
    if (flags & 1)
        ::operator delete(reader);
    return reader;
}

// Replace the held reference, releasing the previous object when non-null.
// @0x14002d280
void* FUN_14002d280(void** slot, void* replacement)
{
    if (*slot)
        FUN_14257dcb0(*slot);
    *slot = replacement;
    return slot;
}

// @0x14002d3c0
void* FUN_14002d3c0(void*, size_t size)
{
    CriUint32 info[4];   // AllocInfo: only the stat id is set
    info[0] = 6;
    void* heap = DAT_143b15f60;
    return (*(void* (__fastcall **)(void*, size_t, CriUint32*))(*(CriUint8**)heap + 0x50))(heap, size, info);
}

// The exe's heap-release helpers below call and return instead of tail-calling: favor-size codegen (/Os). The rest of
// the unit matches the /Ot default; only cl 17.00 sees the pragma.
#if defined(_MSC_VER) && _MSC_VER == 1700
#pragma optimize("s", on)
#endif

// Return a non-null allocation to the global Scaleform heap.
// @0x14002d3f0
void FUN_14002d3f0(void* allocation)
{
    if (allocation)
    {
        void* heap = DAT_143b15f60;
        CriUint8* vtable = (CriUint8*)*(void**)heap;
        void (__fastcall *release)(void*, void*) = *(void (__fastcall **)(void*, void*))(vtable + 0x60);
        release(heap, allocation);
    }
}

// The global heap's Free, inlined without the null test (the deleting dtors and the request pools).
static inline void CriHeapFreeRaw(void* allocation)
{
    void* heap = DAT_143b15f60;
    (*(void (__fastcall **)(void*, void*))(*(CriUint8**)heap + 0x60))(heap, allocation);
}

// Release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a250
void FUN_14002a250(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// Release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a270
void FUN_14002a270(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// Release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a620
void FUN_14002a620(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// Release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a640
void FUN_14002a640(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// Release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a660
void FUN_14002a660(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// Release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002ab70
void FUN_14002ab70(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// Release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002acb0
void FUN_14002acb0(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// Release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002acd0
void FUN_14002acd0(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

#if defined(_MSC_VER) && _MSC_VER == 1700
#pragma optimize("", on)
#endif

// Allocator::ConstructArray(p, count, source) for eight-byte elements, inlined into the Append below.
static inline void CriConstructArray8(void* p, CriUint64 count, const CriUint64* source)
{
    CriUint8* data = (CriUint8*)p;
    for (CriUint64 i = 0; i < count; ++i, ++source, data += sizeof(CriUint64))
        if (data)
            *(CriUint64*)data = *source;
}

// @0x14002a4a0
void FUN_14002a4a0(CriUint64* array, const CriUint64* source, CriUint64 count)
{
    if (!count)
        return;
    CriUint64 oldLength = array[1];
    CriUint64 newLength = oldLength + count;
    if (newLength < oldLength)
    {
        if (newLength < (array[2] >> 1))
            FUN_140029bf0(array, array, newLength);
    }
    else if (newLength >= array[2])
        FUN_140029bf0(array, array, newLength + (newLength >> 2));
    array[1] = newLength;
    CriConstructArray8((CriUint64*)array[0] + oldLength, count, source);
}

// @0x14002afe0
void FUN_14002afe0(CriUint64* array)
{
    // ResizeNoConstruct(0): shrinking to an empty array frees it, growing from capacity 0 reserves 0
    const CriUint64 newSize = 0;
    if (newSize < array[1])
    {
        if (newSize < (array[2] >> 1))
        {
            if (array[0])
            {
                FUN_14002d3f0((void*)array[0]);
                array[0] = 0;
            }
            array[2] = 0;
        }
    }
    else if (newSize >= array[2])
        FUN_140029bf0(array, array, newSize + (newSize >> 2));
    array[1] = newSize;
}

// Clear the destination vector before cloning its two-word source state.
// @0x14002a980
CriUint64* FUN_14002a980(CriUint64* destination, const CriUint64* source)
{
    destination[0] = 0;
    destination[1] = 0;
    destination[2] = 0;
    FUN_14002a4a0(destination, (const CriUint64*)source[0], source[1]);
    return destination;
}

// Clear the destination vector before cloning its two-word source state.
// @0x14002afb0
CriUint64* FUN_14002afb0(CriUint64* destination, const CriUint64* source)
{
    destination[0] = 0;
    destination[1] = 0;
    destination[2] = 0;
    FUN_14002a4a0(destination, (const CriUint64*)source[0], source[1]);
    return destination;
}

// Clear the destination vector before cloning its two-word source state.
// @0x14002b9b0
CriUint64* FUN_14002b9b0(CriUint64* destination, const CriUint64* source)
{
    destination[0] = 0;
    destination[1] = 0;
    destination[2] = 0;
    FUN_14002a4a0(destination, (const CriUint64*)source[0], source[1]);
    return destination;
}

// Run the matching vector helper and preserve the original object pointer.
// @0x14002c0c0
void* FUN_14002c0c0(void* object, void* source)
{
    FUN_14002ba30((CriUint64*)object, (const CriUint64*)source);
    return object;
}

// Run the matching vector helper and preserve the original object pointer.
// @0x14002c780
void* FUN_14002c780(void* object, void* source)
{
    FUN_14002c550((CriUint64*)object, (const CriUint64*)source);
    return object;
}

// @0x14002a2b0
void* FUN_14002a2b0(void* object, CriUint32 flags)
{
    FUN_14257db50(object);
    if (flags & 1)
        CriHeapFreeRaw(object);
    return object;
}

// @0x14002ac70
void* FUN_14002ac70(void* object, CriUint32 flags)
{
    FUN_142579470(object);
    if (flags & 1)
        CriHeapFreeRaw(object);
    return object;
}

// @0x14002bac0
void* FUN_14002bac0(void* object, CriUint32 flags)
{
    static_cast<Scaleform::GFx::Video::VideoDecoderThrd*>(object)->Scaleform::GFx::Video::VideoDecoderThrd::~VideoDecoderThrd();
    if (flags & 1)
        CriHeapFreeRaw(object);
    return object;
}

// @0x14002c8f0
void* FUN_14002c8f0(void* object, CriUint32 flags)
{
    static_cast<Scaleform::GFx::Video::VideoPlayerImpl*>(object)->Scaleform::GFx::Video::VideoPlayerImpl::~VideoPlayerImpl();
    if (flags & 1)
        CriHeapFreeRaw(object);
    return object;
}

// @0x14002e510
void* FUN_14002e510(void* object, CriUint32 flags)
{
    Scaleform::GFx::Video::FUN_14002e2a0(object);
    if (flags & 1)
        CriHeapFreeRaw(object);
    return object;
}

// @0x14002d840
void* FUN_14002d840(void* object, CriUint32 flags)
{
    FUN_14257db50(object);
    if (flags & 1)
        CriHeapFreeRaw(object);
    return object;
}

// MS2-FUNCTIONAL: run reader-thread requests from the intrusive queue until its stop operation arrives.
// @0x14002db40
void* FUN_14002db40(void* thread, void* opaqueConfig)
{
    (void)thread;
    CriMvReaderThreadConfigView* config = (CriMvReaderThreadConfigView*)opaqueConfig;
    struct RequestPoolHead { CriUint8 Reserved[0x58]; CriMvRequestNode* FreeList; };
    struct ReaderMemoryView
    {
        CriUint8 Reserved0[0x20];
        void* Resource;
        CriUint8 Reserved28[4];
        CriUint32 State2c;
        CriUint32 State30;
        CriUint32 State34;
        CriUint8 Reserved38[0x10];
        CriSint64 ResultSize;   // VideoReader::FileSize: the exe sign-extends the length into the whole qword
    };
    bool keepRunning = true;
    do
    {
        FUN_142584540(config->Event, -1);
        FUN_14258aca0(config->Lock);
        if (config->Reader)
        {
            void** vtable = *(void***)config->Reader;
            ((void(__fastcall*)(void*))vtable[1])(config->Reader);
        }
        FUN_14258bb70(config->Lock);

        FUN_14258aca0(config->Lock);
        CriMvRequestNode* sentinel = (CriMvRequestNode*)&config->Head;
        while (config->Tail != sentinel)
        {
            CriMvRequestNode* request = config->Tail;
            request->Next->Previous = request->Previous;
            request->Previous->Next = request->Next;
            // the exe runs the operation outside the lock (0x14002dbdd) and retakes it to free the node
            FUN_14258bb70(config->Lock);
            switch (request->Operation)
            {
            case 0:
            {
                void* reader = request->Request;
                void* memoryOwner = *(void**)((CriUint8*)reader + 0x18);
                void* allocator = *(void**)((CriUint8*)memoryOwner + 0x18);
                void** vtable = *(void***)allocator;
                typedef void* (__fastcall* Allocate)(void*, size_t, CriUint32, CriUint32);
                void* resource = ((Allocate)vtable[1])(allocator, (size_t)request->ArgumentA, 0x21, 0x1b6);
                ReaderMemoryView* state = (ReaderMemoryView*)reader;
                if (state->Resource)
                    FUN_14257dcb0(state->Resource);
                state->Resource = resource;
                void** resourceVtable = resource ? *(void***)resource : NULL;
                typedef CriBool (__fastcall* IsReady)(void*);
                if (!resource || !((IsReady)resourceVtable[2])(resource))
                {
                    state->State2c = 3;
                    state->State30 = 3;
                    state->State34 = 3;
                }
                else
                {
                    typedef CriSint32 (__fastcall* GetSize)(void*);
                    // the exe takes the length first, then marks the open complete, then stores the size
                    CriSint32 length = ((GetSize)resourceVtable[6])(resource);
                    state->State2c = 2;
                    state->ResultSize = length;
                }
                break;
            }
            case 1:
                // FUN_14002e140(queue, 1, reader, NULL, buffer, size): the exe reads node +0x28 / +0x30 (0x14002dc49)
                static_cast<Scaleform::GFx::Video::VideoReader*>(request->Request)->ReadFile(
                    static_cast<Scaleform::UByte*>(request->ArgumentB), reinterpret_cast<Scaleform::SInt64>(request->ArgumentC));
                break;
            case 2:
            {
                ReaderMemoryView* state = (ReaderMemoryView*)request->Request;
                void* resource = state->Resource;
                void** vtable = resource ? *(void***)resource : NULL;
                typedef CriBool (__fastcall* IsFinished)(void*);
                state->State30 = (!resource || ((IsFinished)vtable[0x98 / sizeof(void*)])(resource)) ? 2 : 3;
                if (resource)
                    FUN_14257dcb0(resource);
                state->Resource = NULL;
                break;
            }
            case 3:
                keepRunning = false;
                break;
            default:
                break;
            }
            FUN_14258aca0(config->Lock);
            RequestPoolHead* pool = (RequestPoolHead*)config;
            request->Next = pool->FreeList;
            pool->FreeList = request;
            FUN_14258bb70(config->Lock);
            FUN_14258aca0(config->Lock);
        }
        FUN_14258bb70(config->Lock);

        FUN_14258aca0(config->Lock);
        if (config->Reader)
        {
            void** vtable = *(void***)config->Reader;
            ((void(__fastcall*)(void*))vtable[2])(config->Reader);
        }
        FUN_14258b260(config->Condition);
        FUN_14258bb70(config->Lock);
    } while (keepRunning);
    return NULL;
}

// MS2-FUNCTIONAL: enable or disable reader IO, wake the thread, and wait for its queued work to drain.
// @0x14002d6d0
void FUN_14002d6d0(CriMvReaderThreadConfigView* config, CriUint8 enable)
{
    config->IOEnabled = enable;
    FUN_142583d50(config->Event);
    FUN_14258aca0(config->Lock);
    CriMvRequestNode* sentinel = (CriMvRequestNode*)&config->Head;
    while (sentinel->Previous != sentinel)
        FUN_14258bc20(config->Condition, config->Lock, -1);
    FUN_14258bb70(config->Lock);
}

// MS2-FUNCTIONAL: replace the configured reader with reference balancing while holding its lock.
// @0x14002d750
void FUN_14002d750(CriMvReaderThreadConfigView* config, void* reader)
{
    FUN_14258aca0(config->Lock);
    if (reader)
        FUN_14257dc30(reader);
    if (config->Reader)
        FUN_14257dcb0(config->Reader);
    config->Reader = reader;
    FUN_14258bb70(config->Lock);
}

// @0x14002d7b0
CriUint64 FUN_14002d7b0(void* request, CriSint64 offset, CriSint32 origin)
{
    CriMvReaderRequestView* view = (CriMvReaderRequestView*)request;
    FUN_14258aca0(((CriMvReaderThreadConfigView*)view->Queue)->Lock);
    switch (origin)
    {
    case 1:
        view->ReadSize = view->ReadPosition;
        break;
    case 2:
        view->ReadSize = view->FileSize;
        break;
    default:
        view->ReadSize = 0;
        break;
    }
    view->ReadSize += (CriUint64)offset;
    _ReadWriteBarrier();   // the seek is stored before the Lock::Locker dtor reads the queue
    CriUint64 result = view->ReadSize;
    FUN_14258bb70(((CriMvReaderThreadConfigView*)view->Queue)->Lock);
    return result;
}

// @0x14002d890
CriMvRequestNode* FUN_14002d890(CriMvRequestPoolView* pool)
{
    if (pool->FreeList)
    {
        CriMvRequestNode* result = pool->FreeList;
        pool->FreeList = result->Next;
        return result;
    }
    if (pool->NodesInLastBlock < 0x7f)
        return &pool->LastBlock->Nodes[pool->NodesInLastBlock++];
    CriUint32 info;   // AllocInfo: stat id 6
    info = 6;
    void* heap = DAT_143b15f60;
    CriMvRequestBlock* block = (CriMvRequestBlock*)(*(void* (__fastcall **)(void*, size_t, CriUint32*))(
        *(CriUint8**)heap + 0x50))(heap, sizeof(CriMvRequestBlock), &info);
    block->NextBlock = NULL;
    if (pool->LastBlock)
        pool->LastBlock->NextBlock = block;
    else
        pool->FirstBlock = block;
    pool->LastBlock = block;
    pool->NodesInLastBlock = 1;
    return block->Nodes;
}

static void CriReleaseRequestBlocks(CriMvRequestBlock* block)
{
    while (block)
    {
        CriMvRequestBlock* next = block->NextBlock;
        CriHeapFreeRaw(block);
        block = next;
    }
}

// @0x14002d930
void FUN_14002d930(CriMvRequestPoolView* pool)
{
    CriReleaseRequestBlocks(pool->FirstBlock);
}

// @0x14002dd80
void FUN_14002dd80(CriMvRequestPoolView* pool)
{
    CriReleaseRequestBlocks(pool->FirstBlock);
}

// @0x14002e010
void FUN_14002e010(CriMvRequestPoolView* pool)
{
    CriReleaseRequestBlocks(pool->FirstBlock);
}


// MS2-PIN: ??_7VideoPlayer@Video@GFx@Scaleform@@6B@ 0x1431b8e30
// MS2-PIN: ??_7VideoPlayerImpl@Video@GFx@Scaleform@@6B@ 0x1431b9260
// MS2-PIN: ??_7VideoDecoderSmp@Video@GFx@Scaleform@@6B@ 0x1431b9170
// MS2-PIN: ??_7VideoDecoderThrd@Video@GFx@Scaleform@@6B@ 0x1431b9200
// MS2-PIN: ??_7VideoReader@Video@GFx@Scaleform@@6BRefCountImplCore@Scaleform@@@ 0x1431b93b0
// MS2-PIN: ??_7VideoReader@Video@GFx@Scaleform@@6BCriMvFileReaderInterface@@@ 0x1431b9360
// MS2-PIN: ??_7VideoReaderConfigSmp@Video@GFx@Scaleform@@6B@ 0x1431b91d8
// MS2-PIN: ??0VideoPlayerImpl@Video@GFx@Scaleform@@QEAA@PEAVMemoryHeap@3@@Z 0x14002c810
// ---- full-exe unresolved: leaves without .pdata that data_cri's tables reference as ?FUN_<va>@@YAXXZ ----

// MS2-FUNCTIONAL: empty interface slot.
// @0x14002b0d0
void FUN_14002b0d0(void*) {}

struct cri02_flaghost { void* vtbl; void* _08[6]; CriUint8 flag; };
// MS2-FUNCTIONAL: sets the flag byte +0x38.
// @0x14002b0e0
void FUN_14002b0e0(cri02_flaghost* self, CriUint8 v) { self->flag = v; }

namespace Scaleform { namespace GFx { namespace Video {
// MS2-FUNCTIONAL: deleting-destructor thunk of VideoReader's CriMvFileReaderInterface base (+0x10).
// @0x14002de50
void* FUN_14002de50(char* self, CriUint32 flags)
{
    return FUN_14002dec0(reinterpret_cast<VideoReader*>(self - 0x10), flags);
}
}}}
