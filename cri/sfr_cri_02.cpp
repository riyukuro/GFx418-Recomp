// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the rest of the Scaleform GFx 4.1.18 Video player glue
// (VideoPlayerImpl, the decoders and readers over CRI, from 0x14002a0e0), then the CRI Movie 3.07.01 internals.
// Our own source, written from the exe; the leaked SDK copies were only used to name things.
// The CRI part was built by CRI with VS2008 SP1 and the Video add-on lib with VS2012; both can only be functional
// with our toolset.
// MS2-UNIT: sfr_cri_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14002a0e0-0x140039ea8 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/video/video_video.h"
#include "../include/cri/cri_movie.h"
#include "../include/video/video_videoplayerimpl.h"
#include "../include/kernel/sf_file.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include <new>
#include <cstring>

extern "C" {
extern void* DAT_143b15f60;
extern const CriUint8 DAT_143b27a88[];
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
extern CriSint32 DAT_1431b97a0[];
extern const char* DAT_1431b97a8[];
extern const char* DAT_1431b9820;
extern const void* DAT_143b27a40;
extern CriUint16 DAT_143b2794c;
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

const CriUint8* FUN_14003b674(const CriUint8* data, CriUint32 size, CriSint32* contentSize);

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
void*    FUN_14002a000(void* mem, void* pheap, void* psound);           // CriMvSound::CriMvSound(MemoryHeap*, VideoSound*)
void*    FUN_14002d970(void* mem, void* pconfig);                       // VideoReader::VideoReader(VideoReaderConfig*)
void*    FUN_140029e40(void* mem, void* psync);                     // CriMvSystemTimer::CriMvSystemTimer(SyncObject*)
void     FUN_142586530(void* pstr, const char* p, Scaleform::UPInt size); // String::AssignString
void*    FUN_14002abd0(void* mem, int format, const void* psize, void* ptexman, void* pplayer); // VideoImage ctor
void     FUN_140037950(void* player, const char* message, int severity);
void     FUN_140044fdc(void* inputBuffer);
CriSint32 FUN_140045ed0(const void* config);
CriSint32 FUN_140044eb0(CriSint32 workCount);
CriSint32 FUN_140045910(const void* config);
CriSint32 FUN_140042150(void* player, void* source, void* work, CriUint32 size, CriSint32 flags);
void     FUN_140037850(void* player);
void     FUN_140037880(void* player);
CriUint32 FUN_140030280(void* player, void* heap, void* work);
CriHeap  FUN_140027fec(void* memory, CriSint32 size);
void*    FUN_140030b50(CriSint32 codecId);
void*    FUN_140044e40(void* decoderInterface);
CriSint32 FUN_1400467b8(void* ringBuffer, CriSint32 query);
void FUN_140046804(void* object, void* value);
void FUN_140046814(void* streamJoint, const void* chunk, CriUint32 size);
void     FUN_140039f50(void* section);
void     FUN_140039f8c(void* section);
void     FUN_1400411f8(void);
void     FUN_140046944(char* buffer, CriUint32 capacity, const char* text);
void     FUN_14004698c(char* buffer, CriUint32 capacity, const char* text);
void     FUN_140038190(const void* key);
void     FUN_140038ce4(CriSint32 category, const char* message, CriSint32 value, CriSint32 flags, void* owner);
void     FUN_140038e24(CriSint32 category, const char* message, CriSint32 value);
void     FUN_140031140(void* player);
void     FUN_140031290(void* player);
CriBool  FUN_140031aa0(void* player);
CriBool  FUN_1400314d0(void* player);
CriSint32 FUN_140042d70(void* decoder, void* player);
void     FUN_1400428e0(void* audioManager, void* player);
void     FUN_140031570(void* player);
void     FUN_140034730(void* player);
void     FUN_140033810(void* player);
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
void     FUN_14003a108(void* object);
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
CriSint32 FUN_140043cb0(void* decoder);
void     FUN_140044750(void* decoder);
void     FUN_140043dd0(void* decoder);
CriSint32 FUN_1400355b0(void* playerHandle);
void     FUN_1400393f0(void* easyPlayer, CriSint32 a, CriSint32 b, CriSint32 c,
                       CriUint64 d, CriUint64 e);
CriSint32 FUN_140039330(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo);
CriBool  FUN_140035710(void* player, void* movieYuvState, void* outputInfo);
CriBool  FUN_140035800(void* player, void* movieYuvState, void* outputInfo);
CriSint32 FUN_1400397a0(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo,
                        CriUint64 count, CriUint64 unit, void* userData);
void     FUN_1400467b0(void* queue, CriSint32 operation, void* chunk);
void     FUN_1400467a8(void* queue, CriSint32 operation, void* chunk);
void     FUN_140036650(void* player);
void     FUN_140036710(void* player);
void     FUN_1400369e0(void* player);
void     FUN_140034c20(void* player);
void     FUN_140042e40(void* manager, CriSint32 stream, void* player, CriUint32 format,
                       void* output, CriUint32 sampleCount, void* result);
void     FUN_140042ea0(void* manager, CriSint32 stream, void* player, CriUint32 format,
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
void*    FUN_1400385c8(void* storage, CriSint32 size);
void*    FUN_1400449c0(void* decoder, void* frameInfo);
void     FUN_140044050(void* decoder, void* frameInfo);
void     FUN_140044a30(void* decoder, void* frameInfo);
void     FUN_140044b90(void* decoder, void* a, void* b, void* c, void* d, void* e);
void     FUN_140044fb0(void* output, CriUint32 index, void* value, CriUint32 type, CriUint32 flags);
void     FUN_140044680(void* decoder);
void     FUN_140043d00(void* decoder);
void     FUN_1400379b0(void* owner, const char* message);
CriBool  FUN_1400467b8(void* queue, CriSint32 operation);
void     FUN_1400467a0(void* queue, CriSint32 operation, CriSint32 timeout, void* item);
void     FUN_140044d20(void* decoder, CriUint32 count);
void     FUN_140044270(void* decoder, CriUint32 count);
void     FUN_140044d70(void* decoder, CriUint32 count, void* streamInfo, void* outputInfo);
void     FUN_1400442c0(void* decoder, CriUint32 count, void* streamInfo, void* outputInfo);
void     FUN_140032650(void* player, void* streamSlot, void* output, const void* parsed);
void     FUN_140032db0(void* player, void* streamSlot, void* output, const void* parsed);
void     FUN_140032b70(void* player, void* streamSlot, void* output, const void* parsed);
void     FUN_140033e60(void* player, void* streamSlot);
void*    FUN_14002db40(void* thread, void* config);
CriBool  FUN_140042270(void* manager, void* player, void* source, void* streamInfo,
                       CriUint32 stream, CriBool enable);
void     FUN_140041e30(void* manager, void (*callback)(void**, void*), void* player, CriBool enable);
CriBool  FUN_140037a10(void);
void     FUN_140037910(void* owner, const char* message, CriSint32 value);
CriUint32 FUN_140042f00(void* manager, CriSint32 stream, void* player, void* output);
void     FUN_140042df0(void* manager, void* player, CriSint32 stream);
void     FUN_140042600(void* manager, void* decoder, CriSint32 stream);
CriSint32 FUN_140036b80(void* player, CriMvSubtitleChunk* chunk, CriSint32 channel);
void     FUN_140036e30(void* player, CriMvSubtitleChunk* chunk);
void     FUN_140036e80(void* player, CriMvSubtitleChunk* chunk);
void     FUN_140036f40(void* player, CriMvSubtitleChunk* chunk, void* outputInfo);
void     FUN_140046784(void* streamJoint);
void     FUN_140027fb4(void* heap, void* memory);
void     FUN_140044fa8(void* demux, void* value);
void     FUN_140044fd8(void* demux, CriUint8 value);
void     FUN_140044f9c(void* demux);
void     FUN_140046798(void* streamJoint);
void     FUN_1400420b0(void* manager, void* heap);
void     FUN_140043be0(void* decoder);
void     FUN_140028074(void* heap);
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
void     FUN_14002afe0(void* array);
void     FUN_14002d3f0(void* allocation);
void     FUN_14002a4a0(CriUint64* array, const CriUint64* source, CriUint64 count);
void     FUN_140006f50(void* array, void* source, CriUint64 capacity);
void     FUN_1400051c0(void* array, void* source, CriUint64 capacity);
void     FUN_142584950(void* destination, const void* source);
CriUint64* FUN_14002ba30(CriUint64* destination, const CriUint64* source);
CriUint64* FUN_14002c550(CriUint64* destination, const CriUint64* source);
void     FUN_14002aa30(CriUint64* array, CriUint64 length);
void     FUN_14000bd60(void* array, void* source, CriUint64 length);
void     FUN_14001d720(void* manager, void* reader);
void     FUN_1425845e0(void* event, CriSint32 timeout);
void     FUN_14002b2e0(void* object);
void     FUN_14002c5f0(void* object);
void     FUN_14002e2a0(void* object);
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
    CriUint8 Tail[0x2E0 - 0x2D8];
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

// @0x140038000
void FUN_140038000(void** record, void*)
{
    CriSint32 contentsSize = 0;
    CriUint8* contents = (CriUint8*)FUN_14003b674((const CriUint8*)record[0],
        *(CriUint32*)((CriUint8*)record + 8), &contentsSize);
    if (!contents || contentsSize <= 0x13f)
        return;
    for (CriUint32 i = 0x140; i < (CriUint32)contentsSize; ++i)
        contents[i] ^= DAT_143b27a88[i % 0x20];
}

// @0x1400380d0
void FUN_1400380d0(void** record, void*)
{
    CriSint32 contentsSize = 0;
    CriUint8* contents = (CriUint8*)FUN_14003b674((const CriUint8*)record[0],
        *(CriUint32*)((CriUint8*)record + 8), &contentsSize);
    for (CriUint32 i = 0; contents && i + 0x10 < (CriUint32)contentsSize; ++i)
        contents[i + 0x10] ^= 0xff;
}

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

// MS2-FUNCTIONAL: the CRI VS2008 build has different code generation for this wrapper.
// @0x14002e628
int FUN_14002e628(CriSint32 alignment)
{
    return criHeap_DebugGetWorstExtraSize(alignment) + (int)sizeof(CriHeap);
}

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

// MS2-FUNCTIONAL: CRI emits the empty helper as a short c2 return in its VS2008 build.
// @0x14002e6bc
void FUN_14002e6bc(CriFixedAllocator*)
{
}

// MS2-FUNCTIONAL: the CRI VS2008 build uses a different register allocation for this allocator.
// @0x14002e6c0
void* CRIAPI criFixedAllocator_Allocate(CriFixedAllocator* allocator, CriUint32 size, CriUint32 align)
{
    size_t current = (size_t)allocator->Current;
    size_t aligned = (current + align - 1) / align * align;
    allocator->Current = (CriUint8*)(aligned + size);
    return (void*)aligned;
}

namespace Scaleform { namespace GFx { namespace Video {

#define SF_VIDEO_ERR CriMv::ErrorContainer

// The VideoPlayer methods below are the Video add-on lib (prebuilt with VS2012), so none of them can be exact.

// ==== VideoDecoderThrd ===============================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002a160
void VideoDecoderThrd::StopDecoding(VideoPlayer* pplayer)
{
    DecodeLock.DoLock();
    int idx = -1;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        if (Players[i] == pplayer)
        {
            idx = (int)i;
            break;
        }
    }
    if (idx != -1)
        static_cast<VideoPlayerImpl*>(pplayer)->pPlayer->Stop();
    DecodeLock.Unlock();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002a1e0
bool VideoDecoderThrd::IsDecodingStopped(VideoPlayer* pplayer)
{
    DecodeLock.DoLock();
    int idx = -1;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        if (Players[i] == pplayer)
        {
            idx = (int)i;
            break;
        }
    }
    DecodeLock.Unlock();
    return idx == -1;
}

// ==== VideoPlayerImpl: texture ======================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); the VideoImage constructor is inlined there
// @0x14002ad80
VideoImage* VideoPlayerImpl::CreateTexture(Render::TextureManager* ptexman)
{
    if ((Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking) && ptexman)
    {
        unsigned size[2] = { Width, Height };
        PauseLocked = true;
        void* mem = pHeap->Alloc(0x48);
        if (mem)
            return (VideoImage*)FUN_14002abd0(mem, 0xc9 /* Image_Y8_U2_V2 */, size, ptexman, this);
    }
    return NULL;
}

// ==== VideoDecoderSmp ================================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002b3d0
void VideoDecoderSmp::StartDecoding(VideoPlayer* pplayer)
{
    Players.PushBack(static_cast<VideoPlayerImpl*>(pplayer));
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002beb0
bool VideoDecoderSmp::ExecuteDecode(VideoPlayer* pplayer)
{
    int idx = -1;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        if (Players[i] == pplayer)
        {
            idx = (int)i;
            break;
        }
    }
    if (idx == -1)
        return false;
    if (static_cast<VideoPlayerImpl*>(pplayer)->pPlayer->ExecuteDecode(SF_VIDEO_ERR))
        return true;
    Players.RemoveAt(idx);
    return false;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002bf70
void VideoDecoderSmp::PauseDecoding(bool pause)
{
    if (Paused && pause)
        return;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        VideoPlayerImpl* pplayer = Players[i];
        if (pause)
        {
            // Players the application paused itself stay paused when decoding resumes.
            if (pplayer->PauseFlag)
            {
                PausedPlayers.PushBack(pplayer);
                continue;
            }
        }
        else
        {
            int idx = -1;
            for (UPInt j = 0; j < PausedPlayers.GetSize(); j++)
            {
                if (PausedPlayers[j] == pplayer)
                {
                    idx = (int)j;
                    break;
                }
            }
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002b270
VideoDecoderThrd::VideoDecoderThrd(MemoryHeap* pheap, Thread::ThreadPriority priority)
    : pHeap(pheap), pDecodeThread(NULL), ThreadPriority(priority), DecodeLock(0)
{
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002b2e0
VideoDecoderThrd::~VideoDecoderThrd()
{
    if (pDecodeThread)
        FUN_14257dcb0(pDecodeThread);
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002bb00
int VideoDecoderThrd::DecodeFunc(Thread*, void* obj)
{
    VideoDecoderThrd* pdecoder = (VideoDecoderThrd*)obj;
    for (;;)
    {
        pdecoder->DecodeLock.DoLock();
        if (pdecoder->Players.GetSize() == 1)
        {
            VideoPlayerImpl* pplayer = pdecoder->Players[0];
            pdecoder->DecodeLock.Unlock();
            if (!pplayer->pPlayer->ExecuteDecode(SF_VIDEO_ERR))
            {
                pdecoder->DecodeLock.DoLock();
                pdecoder->Players.RemoveAt(0);
                if (pdecoder->Players.GetSize() == 0)
                {
                    if (pdecoder->pDecodeThread)
                        FUN_14257dcb0(pdecoder->pDecodeThread);
                    pdecoder->pDecodeThread = NULL;
                    pdecoder->DecodeLock.Unlock();
                    return 0;
                }
                pdecoder->DecodeLock.Unlock();
            }
        }
        else
        {
            Array<VideoPlayerImpl*> players(pdecoder->Players);
            pdecoder->DecodeLock.Unlock();

            Array<UPInt> finished;
            for (UPInt i = 0; i < players.GetSize(); i++)
            {
                if (!players[i]->pPlayer->ExecuteDecode(SF_VIDEO_ERR))
                    finished.PushBack(i);
            }
            if (finished.GetSize())
            {
                pdecoder->DecodeLock.DoLock();
                for (UPInt j = 0; j < finished.GetSize(); j++)
                    pdecoder->Players.RemoveAt(finished[j] - j);
                if (pdecoder->Players.GetSize() == 0)
                {
                    if (pdecoder->pDecodeThread)
                        FUN_14257dcb0(pdecoder->pDecodeThread);
                    pdecoder->pDecodeThread = NULL;
                    pdecoder->DecodeLock.Unlock();
                    return 0;
                }
                pdecoder->DecodeLock.Unlock();
            }
        }
        FUN_14258b240(1);
    }
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c0e0
void VideoDecoderThrd::StartDecoding(VideoPlayer* pplayer)
{
    DecodeLock.DoLock();
    int idx = -1;
    for (UPInt i = 0; i < Players.GetSize(); i++)
    {
        if (Players[i] == pplayer)
        {
            idx = (int)i;
            break;
        }
    }
    if (idx != -1)
    {
        DecodeLock.Unlock();
        return;
    }
    Players.PushBack(static_cast<VideoPlayerImpl*>(pplayer));
    DecodeLock.Unlock();

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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); the owned objects' constructors are inlined there
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
            VideoPlayerSound* psound = mem ? (VideoPlayerSound*)FUN_14002a000(mem, pHeap, pinterface) : NULL;
            if (pSound)
                pSound->Release();
            pSound = psound;

            mem = pHeap->Alloc(0x50);
            psound = mem ? (VideoPlayerSound*)FUN_14002a000(mem, pHeap, psubinterface) : NULL;
            if (pSubSound)
                pSubSound->Release();
            pSubSound = psound;
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
        if (pReader)
            pReader->Release();
        pReader = preader;
    }
    else
    {
        void* mem = pHeap->Alloc(0x40);
        VideoReaderConfig* pconfig = mem ? ::new(mem) VideoReaderConfigSmp(pHeap, pfileOpener) : NULL;
        mem = pHeap->Alloc(0x50);
        VideoReader* preader = mem ? (VideoReader*)FUN_14002d970(mem, pconfig) : NULL;
        if (pReader)
            pReader->Release();
        pReader = preader;
        if (pconfig)
            pconfig->Release();
    }

    void* mem = pHeap->Alloc(0x48);
    VideoPlayer::SyncObject* psyncObj = mem ? (VideoPlayer::SyncObject*)FUN_140041c00(mem) : NULL;
    mem = pHeap->Alloc(0x20);
    CriMvSystemTimer* ptimer = mem ? (CriMvSystemTimer*)FUN_140029e40(mem, psyncObj) : NULL;
    if (pTimer)
        pTimer->Release();
    pTimer = ptimer;

    pPlayer = CriMvEasyPlayer::Create((CriHeap)pCriHeap,
                                      pReader ? (CriMvFileReaderInterface*)((UByte*)pReader + 0x10) : NULL,
                                      pTimer ? static_cast<CriMvSystemTimerInterface*>(pTimer) : NULL,
                                      pSound ? (CriMvSoundInterface*)((UByte*)pSound + 0x10) : NULL,
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
// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); a constructor of CuePoint there
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
            p = pcomma + 1;
        }
    }
    return pcue;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c5f0
VideoPlayerImpl::~VideoPlayerImpl()
{
    StopAndWait();
    if (pSubSound)
        pPlayer->DetachSubAudioInterface(SF_VIDEO_ERR);
    if (pPlayer)
        pPlayer->Destroy(SF_VIDEO_ERR);
    pPlayer = NULL;
    if (pTimer)
        pTimer->Release();
    pTimer = NULL;
    if (pSound)
        pSound->Release();
    pSound = NULL;
    if (pSubSound)
        pSubSound->Release();
    pSubSound = NULL;
    if (pReader)
        pReader->Release();
    pReader = NULL;
    FUN_140041dd0(pCriHeap);
    if (pLog)
        FUN_14257dcb0(pLog);
    if (pDecoder)
        pDecoder->Release();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c730
VideoPlayer::Status VideoPlayerImpl::GetStatus()
{
    return Stat;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c740
bool VideoPlayerImpl::IsTextureReady()
{
    return UpdateTextureCalled && FrameOnTime;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c7a0
void VideoPlayerImpl::CuePointCallback(CriMvEasyPlayer*, CriMvEventPoint* eventinfo, void* usrobj)
{
    if (!usrobj)
        return;
    VideoPlayerImpl* pplayer = (VideoPlayerImpl*)usrobj;
    VideoPlayer::CuePoint cue;
    pplayer->CurrentCuePoints.PushBack(*ConstructCuePoint(&cue, eventinfo));
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c810
VideoPlayerImpl::VideoPlayerImpl(MemoryHeap* pheap)
    : pPlayer(NULL), Stat(NotInitialized), pTimer(NULL), pReader(NULL), pSound(NULL), pSubSound(NULL),
      Width(~0u), Height(~0u), HasAlpha(false), CurrentFrame(0), StartFrame(0), StatusAfterStop(Finished),
      PauseFlag(0), LoopFlag(0), UpdateTextureCalled(false), FrameOnTime(false), PauseLocked(false),
      PausePending(false), SubtitleChannel(-1), DecodeHeaderTimeout(0), UseAudioTimer(true), pDecoder(NULL),
      pHeap(pheap), pLog(NULL)
{
    pCriHeap = FUN_140041d40(pheap);
}

// Puts the player back to the state of a newly opened file (Open and the SetSyncObject restart).
static inline void ResetForOpen(VideoPlayerImpl* p)
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002c930
void VideoPlayerImpl::Open(const char* url)
{
    ResetForOpen(this);
    pPlayer->SetFile((CriChar8*)url, SF_VIDEO_ERR);
    pPlayer->DecodeHeader(SF_VIDEO_ERR);
    pDecoder->StartDecoding(this);
    if (pSubSound)
        pPlayer->AttachSubAudioInterface((CriMvSoundInterface*)((UByte*)pSubSound + 0x10), SF_VIDEO_ERR);
    OpenTicks = FUN_1425e3590();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002ca30
void VideoPlayerImpl::GetVideoInfo(VideoInfo* info)
{
    if (!(Stat == Ready || Stat == Starting || Stat == Playing || Stat == Seeking))
        return;

    info->Width         = StmPrm.video_prm[0].disp_width;
    info->Height        = StmPrm.video_prm[0].disp_height;
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002cfe0
void VideoPlayerImpl::GetCurrentCuePoints(Array<CuePoint>* cuePoints)
{
    if (CurrentCuePoints.GetSize() > 0)
    {
        *cuePoints = CurrentCuePoints;
        CurrentCuePoints.Clear();
    }
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
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

// MS2-FUNCTIONAL: lazily start the threaded reader service and allocate a reader on its configured heap.
// @0x14002e050
VideoReader* VideoReaderConfigThrd::CreateReader()
{
    void** config = (void**)this;
    void* heap = config[2];
    if (!config[31])
    {
        struct ThreadParams
        {
            void* (*Entry)(void*, void*);
            void* UserData;
            CriUint64 StackSize;
            CriSint32 Processor;
            CriSint32 Priority;
            CriSint32 Flags;
            CriSint32 Reserved;
        } params = { FUN_14002db40, this, 0x10000, -1, 0, 1, 0 };
        void* heapVtable = *(void**)heap;
        void* (__fastcall *allocateThread)(void*, size_t) =
            (void* (__fastcall *)(void*, size_t))(*(void**)((CriUint8*)heapVtable + 0x50));
        void* memory = allocateThread(heap, 0x60);
        void* thread = memory ? FUN_14258a490(memory, &params) : NULL;
        if (config[31])
            FUN_14257dcb0(config[31]);
        config[31] = thread;
        if (thread)
        {
            void** vtable = *(void***)thread;
            CriBool (__fastcall *start)(void*, CriBool) = (CriBool (__fastcall *)(void*, CriBool))vtable[5];
            if (start(thread, 1))
            {
                void (__fastcall *setName)(void*, const char*) = (void (__fastcall *)(void*, const char*))vtable[7];
                setName(thread, "Scaleform Video Reader");
            }
        }
    }
    void* heapVtable = *(void**)heap;
    void* (__fastcall *allocateReader)(void*, size_t) =
        (void* (__fastcall *)(void*, size_t))(*(void**)((CriUint8*)heapVtable + 0x50));
    void* memory = allocateReader(heap, 0x50);
    return memory ? (VideoReader*)FUN_14002ddd0(memory, this) : NULL;
}

// MS2-FUNCTIONAL: initialize the threaded reader configuration, intrusive reader list and synchronization objects.
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
    fields[4] = fields[5] = fields[6] = NULL;
    fields[0] = (void*)DAT_1431b9430;
    *((CriUint8*)object + 0x38) = 1;
    fields[8] = fields[9] = NULL;
    words[20] = 0x7f;
    fields[11] = NULL;
    fields[12] = fields + 8;
    void** sentinel = fields + 13;
    sentinel[0] = sentinel;
    sentinel[1] = sentinel;
    FUN_14258a350(fields + 15, 1, 0);
    FUN_142582300(fields + 20, 0, 0);
    FUN_14258a620(fields + 32);
    fields[31] = NULL;
    fields[33] = NULL;
    return object;
}

// MS2-FUNCTIONAL: release the threaded reader config's sync state, live readers and retained CRI opener.
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

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d970
VideoReader::VideoReader(VideoReaderConfig* pconfig)
    : pReaderConfig(pconfig), pFile(NULL), ReadSize(0)
{
    FUN_14001d650(pconfig, this);
    OpenStatus  = ASYNC_STATUS_STOP;
    ReadStatus  = ASYNC_STATUS_STOP;
    CloseStatus = ASYNC_STATUS_STOP;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002d430
VideoReader::~VideoReader()
{
    pReaderConfig->DetachReader(this);
    if (pFile)
        pFile->Release();
}

// MS2-FUNCTIONAL: run the VideoReader destructor body and its multiple-inheritance base cleanup.
// @0x14002de60
void FUN_14002de60(VideoReader* reader)
{
    reader->~VideoReader();
}

// MS2-FUNCTIONAL: destroy the VideoReader and optionally return its allocation to the global heap.
// @0x14002d9e0
void* FUN_14002d9e0(VideoReader* reader, CriUint32 flags)
{
    reader->~VideoReader();
    if (flags & 1)
        FUN_14002d3f0(reader);
    return reader;
}

// MS2-FUNCTIONAL: destroy the alternate VideoReader interface view with the same delete flag semantics.
// @0x14002dec0
void* FUN_14002dec0(VideoReader* reader, CriUint32 flags)
{
    reader->~VideoReader();
    if (flags & 1)
        FUN_14002d3f0(reader);
    return reader;
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002da70
void VideoReader::Open(CriChar8* fname)
{
    FileSize = -1;
    ReadSize = 0;
    FilePos  = 0;
    Position = 0;
    OpenFile((const char*)fname);
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002da90
void VideoReader::Close(void)
{
    CloseFile();
}

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002dae0
void VideoReader::Read(CriUint8* buffer, CriSint64 req_size)
{
    while (!pReaderConfig->IOEnabled)
        FUN_14258b240(50);
    ReadFile(buffer, req_size);
}

// ==== VideoReaderConfigSmp ===========================================================================================

// MS2-FUNCTIONAL: Video add-on lib, prebuilt with VS2012 (Rich 0xce build 65501); register allocation and block order differ
// @0x14002df50
VideoReader* VideoReaderConfigSmp::CreateReader()
{
    void* mem = pHeap->Alloc(sizeof(VideoReader));
    return mem ? ::new(mem) VideoReader(this) : NULL;
}

}}} // namespace Scaleform::GFx::Video

// ==== CRI Movie player state and frame-buffer helpers ===============================================================

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

// MS2-FUNCTIONAL: preserves the executable's invalid-value store after its diagnostic call.
// @0x140031060
void FUN_140031060(void* player, CriSint32 value)
{
    if (value < 1)
        FUN_140037950(player, "E10120701M: the parameter nframe must be greater than 0", 0);
    *(CriSint32*)((CriUint8*)player + 0xed8) = value;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this accessor is rebuilt with our VS2017 toolset.
// @0x1400310b0
CriSint32 criMvPly_GetStatus(void* player)
{
    return *(CriSint32*)((CriUint8*)player + 4);
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this wrapper preserves its status gate and frame-time update.
// @0x140039c10
CriSint32 FUN_140039c10(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo, CriError& error)
{
    error = CRIERR_OK;
    CriSint32 status = criMvPly_GetStatus(easyPlayer->mvply);
    if (status < 0 || status > 4)
    {
        CriSint32 onTime = FUN_140039330(easyPlayer, frameInfo);
        FUN_1400393f0(easyPlayer, onTime, onTime, 0,
                      *(const CriUint64*)((const CriUint8*)frameInfo + 0x28),
                      *(const CriUint64*)((const CriUint8*)frameInfo + 0x30));
        return onTime;
    }
    return 0;
}

// MS2-FUNCTIONAL: forwards both frame queries and copies the returned YUV metadata into the player's saved frame.
// @0x140039cb0
CriBool FUN_140039cb0(CriMvEasyPlayer* easyPlayer, void* yuvBuffers,
                      CriMvFrameInfo* frameInfo, CriMvAlphaFrameInfo* alphaInfo, CriError& error)
{
    error = CRIERR_OK;
    CriBool result = FUN_140035710(easyPlayer->mvply, yuvBuffers, frameInfo);
    if (result == 1)
    {
        FUN_140035800(easyPlayer->mvply, yuvBuffers, alphaInfo);
        memcpy(&easyPlayer->frame_info, frameInfo, 0xb0);
    }
    return result;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this accessor is rebuilt with our VS2017 toolset.
// @0x1400310e0
CriSint32 getInternalStatus(void* player)
{
    return *(CriSint32*)((CriUint8*)player + 4);
}

// MS2-FUNCTIONAL: compares the frame and system time as the CRI player does, including unsigned-to-float wrap correction.
// @0x1400397a0
__declspec(noinline) CriSint32 FUN_1400397a0(CriMvEasyPlayer*, const CriMvFrameInfo* frameInfo,
                                              CriUint64 count, CriUint64 unit, void*)
{
    CriUint64 frameCountValue = *(const CriUint64*)((const CriUint8*)frameInfo + 0x28);
    CriUint64 frameUnitValue = *(const CriUint64*)((const CriUint8*)frameInfo + 0x30);
    CriFloat32 frameCount = (CriFloat32)(CriSint64)frameCountValue;
    CriFloat32 frameUnit = (CriFloat32)(CriSint64)frameUnitValue;
    CriFloat32 systemCount = (CriFloat32)(CriSint64)count;
    CriFloat32 systemUnit = (CriFloat32)(CriSint64)unit;
    if ((CriSint64)frameCountValue < 0) frameCount += 18446744073709551616.0f;
    if ((CriSint64)frameUnitValue < 0) frameUnit += 18446744073709551616.0f;
    if ((CriSint64)count < 0) systemCount += 18446744073709551616.0f;
    if ((CriSint64)unit < 0) systemUnit += 18446744073709551616.0f;
    return (frameCount * 1000.0f) / frameUnit <= (systemCount * 1000.0f) / systemUnit;
}

// MS2-FUNCTIONAL: selects CRI's configured comparison callback or the built-in frame-time comparison.
// @0x140039330
CriSint32 FUN_140039330(CriMvEasyPlayer* easyPlayer, const CriMvFrameInfo* frameInfo)
{
    CriUint64 count = 0;
    CriUint64 unit = 0;
    CriError error = CRIERR_OK;
    easyPlayer->GetTime(count, unit, error);
    auto callback = *(CriSint32(__fastcall**)(CriMvEasyPlayer*, const CriMvFrameInfo*, CriUint64,
                                                CriUint64, void*))((CriUint8*)easyPlayer + 0x620);
    void* userData = *(void**)((CriUint8*)easyPlayer + 0x628);
    if (callback)
        return callback(easyPlayer, frameInfo, count, unit, userData);
    return FUN_1400397a0(easyPlayer, frameInfo, count, unit, userData);
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
        if (corrected >= 0.0f && corrected < period)
        {
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

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this helper is rebuilt with our VS2017 toolset.
// @0x1400351c0
void crimvply_clearAlphaFrameInfoMembers(void* info)
{
    memset(info, 0, 0x40);
    *(CriSint32*)((CriUint8*)info + 0x08) = -1;
    *(CriUint32*)((CriUint8*)info + 0x28) = 1;
    *(CriSint32*)((CriUint8*)info + 0x30) = -1;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this predicate is rebuilt with our VS2017 toolset.
// @0x140035560
CriBool crimvply_isUnderGetFrameCondition(void* player)
{
    if (*(CriSint32*)((CriUint8*)player + 8) == 1)
        return 0;
    CriSint32 status = *(CriSint32*)((CriUint8*)player + 4);
    return status == 4 || status == 5;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this frame-info copier is rebuilt with our VS2017 toolset.
// @0x1400358d0
CriUint32 FUN_1400358d0(void* output, const void* info)
{
    CriMvPlaneInfo* out = (CriMvPlaneInfo*)output;
    const CriMvFramePlaneSource* in = (const CriMvFramePlaneSource*)info;
    memset(out, 0, 0x40);
    CriUint32 planes = in->PlaneCount;
    if (planes != 0)
    {
        out[0].Buffer = in->Planes[0].Buffer;
        out[0].Stride = (CriSint32)in->Planes[0].Height * (CriSint32)in->Planes[0].Width;
        out[0].Height = in->Planes[0].Height;
    }
    if (planes > 1)
    {
        out[1].Buffer = in->Planes[1].Buffer;
        out[1].Stride = (CriSint32)in->Planes[1].Height * (CriSint32)in->Planes[1].Width;
        out[1].Height = in->Planes[1].Height;
    }
    if (planes > 2)
    {
        out[2].Buffer = in->Planes[2].Buffer;
        out[2].Stride = (CriSint32)in->Planes[2].Height * (CriSint32)in->Planes[2].Width;
        out[2].Height = in->Planes[2].Height;
    }
    return planes;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this plane updater is rebuilt with our VS2017 toolset.
// @0x1400359e0
void crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(void* player, const CriMvAlphaDecoderFrameInfo* info)
{
    if (info->PlaneIndex != -1)
    {
        CriMvPlaneInfo* dst = &((CriMvYuvBufferState*)player)->Plane;
        dst->Buffer = info->Buffer;
        dst->Stride = (CriSint32)info->Height * (CriSint32)info->Stride;
        dst->Height = info->Height;
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
    *(CriUint32*)((CriUint8*)player + 0xe1c) = format == 0 ? 2 : 4;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this setter is rebuilt with our VS2017 toolset.
// @0x140037740
void FUN_140037740(void* player, CriUint32 value0, CriUint32 value1)
{
    CriMvStateFlags* state = (CriMvStateFlags*)player;
    state->Value0 = value0;
    state->Value1 = value1;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this setter is rebuilt with our VS2017 toolset.
// @0x140037780
void FUN_140037780(void* player, CriUint32 value)
{
    ((CriMvStateFlags*)player)->Value2 = value;
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this state transition is rebuilt with our VS2017 toolset.
// @0x1400379b0
void* crimvply_transitErrorState(void* player, void* fallback)
{
    if (player)
    {
        ((CriMvErrorState*)player)->Error = 1;
        return player;
    }
    return fallback;
}

// MS2-FUNCTIONAL: CRI Movie was built with VS2008; preserve the input-chunk state check from the executable.
// @0x140035000
CriBool isLockedInputChunk(const void* player)
{
    return ((const CriMvInputLockState*)player)->Locked != 0;
}

// MS2-FUNCTIONAL: CRI Movie was built with VS2008; this transition helper is rebuilt with our VS2017 toolset.
// @0x140035050
void criMvPly_TerminateSupply(void* player)
{
    CriMvSupplyState* state = (CriMvSupplyState*)player;
    state->SupplyEnded = 1;
    state->Terminated = 1;
    FUN_140044fdc(((CriMvSupplyInputBuffer*)player)->InputBuffer);
}

// MS2-FUNCTIONAL: initializes the observed 0x90-byte next-frame record and its two sentinel fields.
// @0x140035090
void FUN_140035090(void* record)
{
    memset(record, 0, 0x90);
    *(CriSint32*)((CriUint8*)record + 8) = -1;
    *(CriUint32*)((CriUint8*)record + 0x30) = 1;
    *(CriSint32*)((CriUint8*)record + 0x3c) = -1;
}

// MS2-FUNCTIONAL: return the next decoded video frame and release its decoder-owned record afterward.
// @0x1400355b0
CriBool FUN_1400355b0(void* player, void* output)
{
    FUN_140035090(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return 0;

    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    CriMvFrameInfo frame = {};
    void* frameToken = FUN_1400449c0(decoders->VideoDecoder, &frame);
    if (!frameToken)
        return 0;

    FUN_140035260(player, output, &frame, (CriUint64)(uintptr_t)frameToken, frame.width);
    FUN_140044a30(decoders->VideoDecoder, &frame);
    ((CriMvPlyObj*)player)->num_audio_out = ((CriMvFrameInfo*)output)->frame_id;
    return 1;
}

// MS2-FUNCTIONAL: return decoded video metadata and copy the frame's plane descriptors into YUV buffers.
// @0x140035710
CriBool FUN_140035710(void* player, void* yuvBuffers, void* output)
{
    FUN_140035090(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return 0;

    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    CriMvFrameInfo frame = {};
    void* frameToken = FUN_1400449c0(decoders->VideoDecoder, &frame);
    if (!frameToken)
        return 0;

    FUN_140035260(player, output, &frame, (CriUint64)(uintptr_t)frameToken, frame.width);
    ((CriMvPlyObj*)player)->num_audio_out = ((CriMvFrameInfo*)output)->frame_id;
    FUN_1400358d0(yuvBuffers, &frame);
    return 1;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; preserve its null-safe Windows critical-section wrapper.
// @0x140039dd4
CriBool criCsWin_InitializeCriticalSection(LPCRITICAL_SECTION section)
{
    if (section)
        InitializeCriticalSection(section);
    return section != NULL;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; preserve its null-safe Windows critical-section wrapper.
// @0x140039dfc
CriBool criCsWin_DeleteCriticalSection(LPCRITICAL_SECTION section)
{
    if (section)
        DeleteCriticalSection(section);
    return section != NULL;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; preserve its null-safe Windows critical-section wrapper.
// @0x140039e24
CriBool FUN_140039e24(LPCRITICAL_SECTION section)
{
    if (section)
        EnterCriticalSection(section);
    return section != NULL;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; preserve its null-safe Windows critical-section wrapper.
// @0x140039e4c
CriBool FUN_140039e4c(LPCRITICAL_SECTION section)
{
    if (section)
        LeaveCriticalSection(section);
    return section != NULL;
}

// MS2-FUNCTIONAL: CRI Base was built with VS2008; this ownership check is rebuilt with our VS2017 toolset.
// @0x140039e74
CriBool criCs_IsInCriticalSection(const void* state)
{
    const CriUint8* bytes = (const CriUint8*)state;
    CriSint32 depth = *(const CriSint32*)(bytes + 0x2c);
    if (depth < 1)
        return 0;
    return GetCurrentThreadId() == *(const DWORD*)(bytes + 0x28);
}

// MS2-FUNCTIONAL: the CRI Movie library was built with VS2008; this stores its caller-supplied metadata allocator.
// @0x1400301d0
void criMvPly_SetMetaDataWorkAllocator(void* player, void* work, void* allocate, void* freeFn)
{
    CriMvMetadataAllocatorFields* fields = (CriMvMetadataAllocatorFields*)player;
    fields->Work = work;
    fields->Allocate = allocate;
    fields->Free = freeFn;
}

// MS2-FUNCTIONAL: the work-size helper combines the CRI RBF, demux, and two universal-jump-buffer requirements.
// @0x14002e9e0
CriSint32 FUN_14002e9e0(void)
{
    CriUint32 rbfConfig[6] = { 1, 0x2800, 0, 0x40, 0, 0 };
    CriSint32 total = 0x376c + 4 + FUN_140045ed0(rbfConfig);
    total += 4 + FUN_140044eb0(8);
    CriUint32 uniConfig[3] = { 1, 0, 0x40 };
    total += FUN_140045910(uniConfig);
    uniConfig[2] = 4;
    return total + FUN_140045910(uniConfig);
}

// MS2-FUNCTIONAL: the CRI Movie sub-audio helper forwards the caller's sizing inputs with flags set to zero.
// @0x1400345e0
void FUN_1400345e0(void* player, void* value, CriUint32 type, CriUint32 flags)
{
    CriMovieOutputLogView* state = (CriMovieOutputLogView*)player;
    if (state->Count >= state->Capacity)
        FUN_140037910(player, "E05063025M: Can't entry output stream info.", state->Count);
    FUN_140044fb0(state->Output, state->Count, value, type, flags);
    ++state->Count;
}

// MS2-FUNCTIONAL: detect terminal decoder errors and report them through the player error logger.
// @0x140034690
void FUN_140034690(void* player)
{
    void** fields = (void**)player;
    if (fields[0x1c1])
    {
        FUN_140044680(fields[0x1c1]);
        if (FUN_140044630(fields[0x1c1]) == 4)
        {
            FUN_1400379b0(player, "The internal status of Vdec is ERROR.");
            return;
        }
    }
    if (fields[0x1c8])
    {
        FUN_140043d00(fields[0x1c8]);
        if (FUN_140043cb0(fields[0x1c8]) == 4)
            FUN_1400379b0(player, "The internal status of AlphaDec is ERROR.");
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
        CriMovieParsedChunk parsed = { FUN_14003b674(input->Data, input->Size, &size), size, 0 };
        FUN_140032650(player, slot, slot->PrimaryOutput, &parsed);
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
        CriMovieParsedChunk parsed = { FUN_14003b674(input->Data, input->Size, &size), size, 0 };
        FUN_140032db0(player, slot, slot->SubtitleOutput, &parsed);
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
        CriMovieParsedChunk parsed = { FUN_14003b674(input->Data, input->Size, &size), size, 0 };
        FUN_140032b70(player, slot, slot->AlphaOutput, &parsed);
        --slot->PendingSubtitle;
        FUN_140033e60(player, slot);
    }
    return 1;
}

// MS2-FUNCTIONAL: replace the pending movie chunk and save the most recently enqueued record.
// @0x1400363b0
void FUN_1400363b0(void* player, void* chunk, CriUint32 type)
{
    CriMovieQueueView* state = (CriMovieQueueView*)player;
    CriMovieChunkQueueRecord item = {};
    if (FUN_1400467b8(state->Queue, 0))
        FUN_1400467a0(state->Queue, 0, -1, &item);
    item.Chunk = chunk;
    item.Type = type;
    FUN_1400467b0(state->Queue, 1, &item);
    memcpy(state->LastChunk, &item, sizeof(item));
}

// MS2-FUNCTIONAL: forward video sizing and stream metadata to the video and alpha decoder interfaces.
// @0x1400377a0
void FUN_1400377a0(void* player, void* videoDecoder, void* alphaDecoder)
{
    CriUint32* words = (CriUint32*)player;
    FUN_140044d20(videoDecoder, words[0x8d0 / 4]);
    FUN_140044270(alphaDecoder, words[0x8d0 / 4]);
    FUN_140044d70(videoDecoder, words[0x8cc / 4], words + 0x8d4 / 4, words + 0x9d4 / 4);
    FUN_1400442c0(alphaDecoder, words[0x8cc / 4], words + 0x8d4 / 4, words + 0x9d4 / 4);
}

// MS2-FUNCTIONAL: the CRI Movie sub-audio helper forwards the caller's sizing inputs with flags set to zero.
// @0x140030f10
CriBool FUN_140030f10(void* player, void* source, CriUint32 stream)
{
    CriMovieAttachView* state = (CriMovieAttachView*)player;
    state->AttachedSource = source;
    CriBool attached = FUN_140042270(state->Manager, player, source,
                                     &state->StreamInfo[stream * 0x10], stream, 1);
    if (!attached)
        return 0;
    if (FUN_140037a10() == 1)
        FUN_140041e30(state->Manager, FUN_140038000, player, 1);
    return 1;
}

// MS2-FUNCTIONAL: the CRI Movie sub-audio helper forwards the caller's sizing inputs with flags set to zero.
// @0x140030ed0
CriSint32 criMvPly_CalcSubAudioWorkSize(void* player, void* source, void* work, CriUint32 size)
{
    return FUN_140042150(player, source, work, size, 0);
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

// MS2-FUNCTIONAL: create the supplied-memory heap, store it in the player, then prepare its work buffers under lock.
// @0x140030e50
CriUint32 criMvPly_AllocateWorkBufferWithWork(void* player, void* memory, CriSint32 size, void* work)
{
    FUN_140037850(player);
    CriHeap heap = FUN_140027fec(memory, size);
    ((CriMvHeapWorkState*)player)->Heap = heap;
    CriUint32 result = FUN_140030280(player, heap, work);
    FUN_140037880(player);
    return result;
}

// MS2-FUNCTIONAL: absent decoder interfaces and missing core functions use the executable's divided-input fallback.
// @0x140037360
CriBool isAvailableDividedInputChunk(void* player)
{
    CriSint32 codec = *(CriSint32*)((CriUint8*)player + 0x44);
    void* decoder = FUN_140030b50(codec);
    if (!decoder)
        return 1;
    void* core = FUN_140044e40(decoder);
    if (!core)
        return 1;
    void* callback = *(void**)((CriUint8*)core + 0x10);
    if (!callback)
        return 1;
    return ((CriBool(__fastcall*)(void))callback)();
}

// MS2-FUNCTIONAL: a divided decoder input uses the fixed extension; otherwise retain the configured minimum size.
// @0x140037310
CriUint32 decideReadBufferExtSize(void* player)
{
    if (isAvailableDividedInputChunk(player))
        return 0x2800;
    CriUint32 size = *(CriUint32*)((CriUint8*)player + 0x0c);
    return size < 0x2800 ? 0x2800 : size;
}

// MS2-FUNCTIONAL: selects the active CRI read buffer and returns its available and bounded sizes.
// @0x140037050
void* FUN_140037050(void* player, CriUint32* available, CriUint32* bounded)
{
    CriMvReadBufferState* state = (CriMvReadBufferState*)player;
    void* buffer;
    CriUint32 first, second;
    if (state->Mode == 0)
    {
        if (getInternalStatus(player) == 1)
        {
            if (state->BufferMode == 0)
            {
                buffer = state->ReadyBuffer;
                first = second = state->DataAvailable;
            }
            else
            {
                buffer = state->Buffer;
                first = second = state->BufferSize;
            }
        }
        else
        {
            buffer = state->ReadBuffer;
            first = state->ReadBufferSize;
            second = (CriUint32)((float)(state->AverageReadSize / 8) * state->ReadRate);
            if (first < second)
                second = first;
        }
    }
    else
    {
        buffer = state->CurrentBuffer;
        first = second = 0;
    }
    if (available)
        *available = first;
    if (bounded)
        *bounded = second;
    return buffer;
}

// MS2-FUNCTIONAL: report bytes in the current or selected CRI input buffer, including partially consumed chunks.
// @0x1400371d0
CriSint32 criMvPly_PeekInputBufferData(void* player)
{
    CriMvReadBufferState* state = (CriMvReadBufferState*)player;
    void* buffer;
    if (state->Mode == 0)
    {
        if (getInternalStatus(player) == 1)
            buffer = state->BufferMode == 0 ? state->ReadyBuffer : state->Buffer;
        else
            buffer = state->ReadBuffer;
    }
    else
    {
        buffer = state->CurrentBuffer;
    }
    if (!buffer)
        return 0;
    if (state->Mode == 1)
        return state->CurrentOffset - FUN_1400467b8(state->CurrentBuffer, 0);
    return FUN_1400467b8(buffer, 1);
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

// MS2-FUNCTIONAL: copy the decoder's 0x38-byte alpha-frame metadata and overlay current movie dimensions.
// @0x140035480
void FUN_140035480(void* player, void* destination, const void* source)
{
    memcpy(destination, source, 0x38);
    CriMvAlphaFrameSnapshot* out = (CriMvAlphaFrameSnapshot*)destination;
    const CriMvAlphaMovieDimensions* movie = (const CriMvAlphaMovieDimensions*)player;
    out->Height = movie->Height;
    out->Width = movie->Width;
    out->DisplayWidth = movie->DisplayWidth;
}

// MS2-FUNCTIONAL: release the alpha decoder frame using its copied frame descriptor when an alpha decoder exists.
// @0x140035a90
CriBool FUN_140035a90(void* player, const CriUint64* frameInfo)
{
    void* decoder = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
    if (!decoder)
        return 0;
    CriUint64 local[11] = {};
    local[0] = *frameInfo;
    FUN_140044050(decoder, local);
    return 1;
}

// MS2-FUNCTIONAL: release the main decoder's current frame using the descriptor's first pointer.
// @0x140035a40
CriBool FUN_140035a40(void* player, const CriMvFrameInfo* frameInfo)
{
    void* localFrame[23] = {};
    localFrame[0] = (void*)*(const CriUint64*)frameInfo;
    FUN_140044050(*(void**)((CriUint8*)player + 0xe08), localFrame);
    return 1;
}

// MS2-FUNCTIONAL: drain and release every queued alpha frame from the player decoder.
// @0x140035bf0
void FUN_140035bf0(void* player)
{
    void* decoder = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
    CriUint64 frameInfo[10];
    while (FUN_1400449c0(decoder, frameInfo))
        FUN_140044050(decoder, frameInfo);
}

// MS2-FUNCTIONAL: get the current alpha frame only while the movie is in a frame-producing state.
// @0x140035800
CriBool FUN_140035800(void* player, void* movieYuvState, void* outputInfo)
{
    crimvply_clearAlphaFrameInfoMembers(outputInfo);
    CriMvDecoderHandleFields* handles = (CriMvDecoderHandleFields*)player;
    if (!handles->AlphaDecoder || !crimvply_isUnderGetFrameCondition(player))
        return 0;
    CriUint64 frameInfo[10] = {};
    if (!FUN_1400449c0(handles->AlphaDecoder, frameInfo))
        return 0;
    FUN_140035480(player, outputInfo, frameInfo);
    crimvply_updateMvPlyYuvBuffersFromAlphadecInfo(movieYuvState,
        (const CriMvAlphaDecoderFrameInfo*)frameInfo);
    return 1;
}

// MS2-FUNCTIONAL: forward the player's video decoder and all five caller outputs to its frame-pool query.
// @0x140036ed0
void criMvPly_GetFramePoolInfo(void* player, void* a, void* b, void* c, void* d, void* e)
{
    if (player)
        FUN_140044b90(((CriMvDecoderHandleFields*)player)->VideoDecoder, a, b, c, d, e);
}

// MS2-FUNCTIONAL: request the main audio stream's current data size from the movie audio manager.
// @0x1400360c0
CriUint32 criMvPly_GetDataSizeMainAudio(void* player, void* output)
{
    return FUN_140042f00(((CriMvSubAudioHandles*)player)->Manager, 0, player, output);
}

// MS2-FUNCTIONAL: request the secondary audio stream's current data size from the movie audio manager.
// @0x140036100
CriUint32 criMvPly_GetDataSizeSubAudio(void* player, void* output)
{
    return FUN_140042f00(((CriMvSubAudioHandles*)player)->Manager, 1, player, output);
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
    CriMvSubAudioHandles* audio = (CriMvSubAudioHandles*)player;
    FUN_140042600(audio->Manager, audio->Decoder, 1);
    audio->Decoder = NULL;
}

// MS2-FUNCTIONAL: read the selected USF subtitle chunk, decode its metadata, and copy its text into caller storage.
// @0x140036470
void criMvPly_GetSubtitle(void* player, void* destination, CriUint32 capacity, void* outputInfo)
{
    memset(outputInfo, 0, 0x38);
    ((CriUint64*)outputInfo)[2] = 1;
    if (!player || !((CriMvSubtitleFields*)player)->Queue)
        return;
    CriMvSubtitleChunk chunk = {};
    FUN_140036b80(player, &chunk, ((CriMvSubtitleFields*)player)->SubtitleChannel);
    if (!chunk.Data || chunk.Size < 0x20)
    {
        FUN_140036e80(player, &chunk);
        return;
    }
    FUN_140036f40(player, &chunk, outputInfo);
    memset(destination, 0, capacity);
    CriUint32 bytes = *(CriUint32*)((CriUint8*)outputInfo + 8);
    if (bytes > capacity)
        bytes = capacity;
    memcpy(destination, *(void**)outputInfo, bytes);
    FUN_140036e30(player, &chunk);
}

// MS2-FUNCTIONAL: obtain the next valid subtitle's decoded metadata and return its chunk to the queue afterward.
// @0x140036590
void criMvPly_GetNextSubtitleInfo(void* player, void* outputInfo)
{
    memset(outputInfo, 0, 0x38);
    *(CriUint64*)((CriUint8*)outputInfo + 0x10) = 1;
    if (!player || !((CriMvSubtitleFields*)player)->Queue)
        return;
    CriMvSubtitleChunk chunk = {};
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
CriUint64 FUN_140038bd0(const CriChar8* text, CriChar8** end, CriSint32 radix)
{
    return _strtoui64(text, end, radix);
}

// MS2-FUNCTIONAL: forward CRI Base's two-argument notification to its shared error dispatch routine.
// @0x140038ddc
void criErr_Notify(CriSint32 category, const CriChar8* message)
{
    FUN_140038ce4(category, message, 0, 0, NULL);
}

// MS2-FUNCTIONAL: preserve the executable's default empty error-dispatch call.
// @0x140038df8
void FUN_140038df8(void)
{
    FUN_140038ce4(0, NULL, 0, 0, NULL);
}

// MS2-FUNCTIONAL: preserve the executable's second default empty error-dispatch call.
// @0x140038e10
void FUN_140038e10(void)
{
    FUN_140038ce4(0, NULL, 0, 0, NULL);
}

// MS2-FUNCTIONAL: enter the movie player's shared handle critical section.
// @0x1400378b0
void FUN_1400378b0(void)
{
    FUN_140039f50(DAT_143ffd550);
}

// MS2-FUNCTIONAL: leave the movie player's shared handle critical section.
// @0x1400378e0
void FUN_1400378e0(void)
{
    FUN_140039f8c(DAT_143ffd550);
}

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
    }
    DAT_143b27bb8 = (void*)notify;
    DAT_143b27bc0 = (void*)secondary;
    if (DAT_143b27bc8 == 1 && category == 1)
        ++DAT_143b27bd0;
    else
    {
        ++DAT_143b27bcc;
        if (notify)
            notify(message, value, flags, owner);
    }
}

// MS2-FUNCTIONAL: find the CRI error text by code, format its message, and send it through the shared dispatcher.
// @0x140038e24
void FUN_140038e24(CriSint32 category, const char* code, CriSint32 error)
{
    const char* description = "Unknown Error.";
    if (DAT_1431b97a8[0])
    {
        for (CriUint32 i = 0; DAT_1431b97a8[i * 2]; ++i)
        {
            if (DAT_1431b97a0[i * 4] == error)
            {
                description = DAT_1431b97a8[i * 2];
                break;
            }
        }
    }
    FUN_140046944(DAT_143b27ab0, 0x100, code);
    FUN_14004698c(DAT_143b27ab0, 0x100, DAT_1431b9820);
    FUN_14004698c(DAT_143b27ab0, 0x100, description);
    FUN_140038ce4(category, DAT_143b27ab0, 0, 0, NULL);
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
    CriMvCodecRegistrationEntry* entries = (CriMvCodecRegistrationEntry*)DAT_143b27950;
    CriUint16 count = DAT_143b2794c;
    CriUint16 index = count;
    for (CriUint16 i = 0; i < count; ++i)
    {
        if (entries[i].CodecId == registration->CodecId)
        {
            index = i;
            break;
        }
    }
    entries[index].CodecId = registration->CodecId;
    entries[index].VideoDecoderInterface = registration->VideoDecoderInterface;
    entries[index].AlphaDecoderInterface = registration->AlphaDecoderInterface;
    if (index == count)
        DAT_143b2794c = count + 1;
}

// MS2-FUNCTIONAL: append a request node to the reader queue under its lock and wake the worker event.
// @0x14002e140
void FUN_14002e140(void* queue, CriUint32 operation, void* request, void* a, void* b, void* c)
{
    CriMvRequestQueueView* queueView = (CriMvRequestQueueView*)queue;
    FUN_14258aca0(queueView->Lock);
    CriMvRequestNode* node = FUN_14002d890((CriMvRequestPoolView*)&queueView->Reserved0[0x40]);
    node->ArgumentB = b;
    node->Operation = operation;
    node->Request = request;
    node->ArgumentA = a;
    node->ArgumentC = c;
    node->Previous = (CriMvRequestNode*)&queueView->Head;
    node->Next = queueView->Head;
    node->Next->Previous = node;
    queueView->Head = node;
    FUN_14258bb70(queueView->Lock);
    FUN_142583d50(queueView->Event);
}

// MS2-FUNCTIONAL: initialize the reader request state and enqueue its open operation.
// @0x14002e1e0
void FUN_14002e1e0(void* object, void* input)
{
    CriMvReaderRequestView* state = (CriMvReaderRequestView*)object;
    state->OpenPending = 1;
    state->FileSize = ~(CriUint64)0;
    state->ReadPending = 0;
    state->ClosePending = 0;
    state->ReadSize = 0;
    state->ReadPosition = 0;
    FUN_14002e140(state->Queue, 0, (CriUint8*)object - 0x10, input, NULL, NULL);
}

// MS2-FUNCTIONAL: mark close pending and append the reader close operation.
// @0x14002e230
void FUN_14002e230(void* object)
{
    CriMvReaderRequestView* state = (CriMvReaderRequestView*)object;
    state->ClosePending = 1;
    FUN_14002e140(state->Queue, 2, (CriUint8*)object - 0x10, NULL, NULL, NULL);
}

// MS2-FUNCTIONAL: mark the request as pending and enqueue the selected reader operation.
// @0x14002e260
void FUN_14002e260(void* object, void* first, void* second)
{
    CriMvReaderRequestView* state = (CriMvReaderRequestView*)object;
    state->ReadPending = 1;
    FUN_14002e140(state->Queue, 1, (CriUint8*)object - 0x10, NULL, first, second);
}

// MS2-FUNCTIONAL: remove all requests for a detached reader, return their nodes, then stop an idle worker.
// @0x14002e370
void FUN_14002e370(CriMvRequestManagerView* manager, void* reader)
{
    FUN_14258aca0(manager->Lock);
    CriMvRequestNode* sentinel = (CriMvRequestNode*)&manager->Head;
    CriMvRequestNode* node = manager->Tail;
    while (node != sentinel)
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
        FUN_14257dcb0(manager->StopEvent);
        manager->StopEvent = NULL;
    }
}

// MS2-FUNCTIONAL: resize the first eight-byte vector flavor, using its three-quarter growth policy.
// @0x14002a380
void FUN_14002a380(void* array, void* source, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    CriUint64 capacity = fields[2];
    if (length < fields[1])
    {
        if (length < (capacity >> 1))
            FUN_140029bf0(array, source, length);
    }
    else if (capacity <= length)
        FUN_140029bf0(array, source, (length >> 2) + length);
    fields[1] = length;
}

// MS2-FUNCTIONAL: resize the second eight-byte vector flavor with its matching allocator helper.
// @0x14002a3e0
void FUN_14002a3e0(void* array, void* source, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    CriUint64 capacity = fields[2];
    if ((length < fields[1] && length < (capacity >> 1)) ||
        (length >= fields[1] && capacity <= length))
        FUN_140029c90(array, source, length < fields[1] ? length : (length >> 2) + length);
    fields[1] = length;
}

// MS2-FUNCTIONAL: resize the third eight-byte vector flavor with its matching allocator helper.
// @0x14002a440
void FUN_14002a440(void* array, void* source, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    CriUint64 capacity = fields[2];
    if ((length < fields[1] && length < (capacity >> 1)) ||
        (length >= fields[1] && capacity <= length))
        FUN_140029d30(array, source, length < fields[1] ? length : (length >> 2) + length);
    fields[1] = length;
}

// MS2-FUNCTIONAL: grow and append one entry to the first eight-byte vector flavor.
// @0x14002a780
void FUN_14002a780(CriUint64* array, const CriUint64* value)
{
    CriUint64 length = array[1] + 1;
    CriUint64 capacity = array[2];
    if (length < array[1])
    {
        if ((capacity >> 1) <= length)
            FUN_140029bf0(array, array, length);
    }
    else if (length >= capacity)
        FUN_140029bf0(array, array, (length >> 2) + length);
    array[1] = length;
    *(CriUint64*)(array[0] - 8 + length * 8) = *value;
}

// MS2-FUNCTIONAL: grow and append one entry to the second eight-byte vector flavor.
// @0x14002a800
void FUN_14002a800(CriUint64* array, const CriUint64* value)
{
    CriUint64 length = array[1] + 1;
    CriUint64 capacity = array[2];
    if (length < array[1])
    {
        if ((capacity >> 1) <= length)
            FUN_140029c90(array, array, length);
    }
    else if (length >= capacity)
        FUN_140029c90(array, array, (length >> 2) + length);
    array[1] = length;
    *(CriUint64*)(array[0] - 8 + length * 8) = *value;
}

// MS2-FUNCTIONAL: set the first vector's logical length and resize its backing store as needed.
// @0x14002a880
void FUN_14002a880(void* array, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    if (length < fields[1] && length < (fields[2] >> 1))
        FUN_140029d30(array, array, length);
    else if (length >= fields[1] && fields[2] <= length)
        FUN_140029d30(array, array, (length >> 2) + length);
    fields[1] = length;
}

// MS2-FUNCTIONAL: set the second vector's logical length and resize through its allocator flavor.
// @0x14002a9b0
void FUN_14002a9b0(void* array, CriUint64 length)
{
    CriUint64* fields = (CriUint64*)array;
    if (length < fields[1] && length < (fields[2] >> 1))
        FUN_140029bf0(array, array, length);
    else if (length >= fields[1] && fields[2] <= length)
        FUN_140029bf0(array, array, (length >> 2) + length);
    fields[1] = length;
}

// MS2-FUNCTIONAL: erase one eight-byte vector entry and shift the remaining entries down.
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

// MS2-FUNCTIONAL: destroy the two string members in each fixed-size vector element.
// @0x14002a550
void FUN_14002a550(void* items, CriSint64 count)
{
    CriUint8* current = (CriUint8*)items;
    while (count-- > 0)
    {
        if (current)
        {
            FUN_142584ce0(current);
            FUN_142584ce0(current + 8);
        }
        current += 0x10;
    }
}

// MS2-FUNCTIONAL: resize a vector of two-string records and initialize each newly added pair.
// @0x14002aa30
void FUN_14002aa30(CriUint64* array, CriUint64 length)
{
    CriUint64 oldLength = array[1];
    FUN_140006f50(array, array, length);
    if (oldLength < length)
    {
        CriUint8* item = (CriUint8*)array[0] + oldLength * 0x10;
        for (CriUint64 i = oldLength; i < length; ++i, item += 0x10)
        {
            if (item)
            {
                FUN_142584ce0(item);
                FUN_142584ce0(item + 8);
            }
        }
    }
}

// MS2-FUNCTIONAL: release the owned opener and heap blocks before destroying the reference-count base.
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

// MS2-FUNCTIONAL: initialize the shared reference-count core and retain its first owned object.
// @0x14002aab0
void* FUN_14002aab0(void* object, void* first, void* second)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_143149940;
    *(CriUint32*)((CriUint8*)object + 8) = 1;
    fields[0] = (void*)DAT_143149940;
    fields[2] = first;
    fields[3] = second;
    fields[4] = NULL;
    if (first)
        FUN_14257dc30(first);
    return object;
}

// MS2-FUNCTIONAL: tear down the video player reference core and optionally free the object storage.
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

// MS2-FUNCTIONAL: release a non-null heap-owned member through the process Scaleform heap.
// @0x14002ab70
void FUN_14002ab70(void** value)
{
    if (*value)
        FUN_14002d3f0(*value);
}

// MS2-FUNCTIONAL: release a non-null heap-owned member through the process Scaleform heap.
// @0x14002acb0
void FUN_14002acb0(void** value)
{
    if (*value)
        FUN_14002d3f0(*value);
}

// MS2-FUNCTIONAL: release a non-null heap-owned member through the process Scaleform heap.
// @0x14002acd0
void FUN_14002acd0(void** value)
{
    if (*value)
        FUN_14002d3f0(*value);
}

// MS2-FUNCTIONAL: clear the request vector while retaining a single-entry allocation when possible.
// @0x14002aec0
void FUN_14002aec0(CriUint64* array)
{
    if (array[1] == 0)
    {
        if (array[2] == 0)
        {
            FUN_140029d30(array, array, 0);
            array[1] = 0;
            return;
        }
    }
    else if ((array[2] & ~CriUint64(1)) != 0)
    {
        if (array[0])
        {
            FUN_14002d3f0((void*)array[0]);
            array[0] = 0;
        }
        array[2] = 0;
        array[1] = 0;
        return;
    }
    array[1] = 0;
}

// MS2-FUNCTIONAL: destroy the same owned fields and optionally free the containing allocation.
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

// MS2-FUNCTIONAL: construct the reader configuration base and retain its file opener.
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
    fields[4] = fields[5] = fields[6] = NULL;
    *((CriUint8*)object + 0x38) = 1;
    return object;
}

// MS2-FUNCTIONAL: finalize the sampled reader configuration and release its two owned members.
// @0x14002b1b0
void FUN_14002b1b0(void* object)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_1431b91d8;
    if (fields[4])
        FUN_14002d3f0(fields[4]);
    if (fields[3])
        FUN_14257dcb0(fields[3]);
    FUN_14257db50(object);
}

// MS2-FUNCTIONAL: construct the sampled reader configuration from its base state and opener.
// @0x14002b150
void* FUN_14002b150(void* object, void* heap, void* opener)
{
    FUN_14002b070(object, heap, opener);
    *(void**)object = (void*)DAT_1431b91d8;
    return object;
}

// MS2-FUNCTIONAL: destroy the sampled reader configuration and conditionally release its allocation.
// @0x14002b200
void* FUN_14002b200(void* object, CriUint32 flags)
{
    FUN_14002b1b0(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: release both player arrays and restore the synchronous decoder's base state.
// @0x14002ad30
void FUN_14002ad30(void* object)
{
    void** fields = (void**)object;
    fields[0] = (void*)DAT_1431b9170;
    if (fields[6])
        FUN_14002d3f0(fields[6]);
    if (fields[3])
        FUN_14002d3f0(fields[3]);
    FUN_14257db50(object);
}

// MS2-FUNCTIONAL: destroy the synchronous decoder and optionally return its storage to the global heap.
// @0x14002b350
void* FUN_14002b350(void* object, CriUint32 flags)
{
    FUN_14002ad30(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: append one 0x30-byte video record and retain its two string fields.
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
    *(CriUint64*)(destination + 6) = 0;
    *(CriUint64*)(destination + 8) = 0;
    *(CriUint64*)(destination + 10) = 0;
    FUN_140007370(destination + 6, *(const CriUint64*)(value + 6), *(const CriUint64*)(value + 8));
}

// MS2-FUNCTIONAL: copy a vector of paired strings after resizing its destination.
// @0x14002ba30
CriUint64* FUN_14002ba30(CriUint64* destination, const CriUint64* source)
{
    FUN_14002aa30(destination, source[1]);
    CriUint8* out = (CriUint8*)destination[0];
    const CriUint8* in = (const CriUint8*)source[0];
    for (CriUint64 i = 0; i < destination[1]; ++i)
    {
        FUN_142585580(out, in);
        FUN_142585580(out + 8, in + 8);
        out += 0x10;
        in += 0x10;
    }
    return destination;
}

// MS2-FUNCTIONAL: copy the 0x30-byte video records and their nested paired-string vectors.
// @0x14002c550
CriUint64* FUN_14002c550(CriUint64* destination, const CriUint64* source)
{
    FUN_14000bd60(destination, destination, source[1]);
    CriUint8* out = (CriUint8*)destination[0];
    const CriUint8* in = (const CriUint8*)source[0];
    for (CriUint64 i = 0; i < destination[1]; ++i)
    {
        CriVideoRecordCopyView* record = (CriVideoRecordCopyView*)(out + i * sizeof(CriVideoRecordCopyView));
        const CriVideoRecordCopyView* sourceRecord =
            (const CriVideoRecordCopyView*)(in + i * sizeof(CriVideoRecordCopyView));
        record->Type = sourceRecord->Type;
        FUN_142585580(&record->Name, &sourceRecord->Name);
        record->Flags = sourceRecord->Flags;
        FUN_14002ba30(record->NestedStrings, sourceRecord->NestedStrings);
    }
    return destination;
}

// MS2-FUNCTIONAL: copy the descriptor fields and nested string vector of a video record.
// @0x14002c260
CriUint32* FUN_14002c260(CriUint32* destination, const CriUint32* source)
{
    destination[0] = source[0];
    FUN_142585580(destination + 2, source + 2);
    destination[4] = source[4];
    FUN_14002ba30((CriUint64*)(destination + 6), (const CriUint64*)(source + 6));
    return destination;
}

// MS2-FUNCTIONAL: append a three-word record using the vector's twelve-byte element stride.
// @0x14002a900
void FUN_14002a900(CriUint64* array, const CriUint32* value)
{
    CriUint64 length = array[1] + 1;
    CriUint64 capacity = array[2];
    if (length < array[1])
    {
        if ((capacity >> 1) <= length)
            FUN_140029d30(array, array, length);
    }
    else if (length >= capacity)
        FUN_140029d30(array, array, (length >> 2) + length);
    array[1] = length;
    CriUint32* destination = (CriUint32*)(array[0] - 12 + length * 12);
    if (destination)
    {
        destination[0] = value[0];
        destination[1] = value[1];
        destination[2] = value[2];
    }
}

// MS2-FUNCTIONAL: append a four-word record using the vector's sixteen-byte element stride.
// @0x14002a6f0
void FUN_14002a6f0(CriUint64* array, const CriUint32* value)
{
    CriUint64 length = array[1] + 1;
    CriUint64 capacity = array[2];
    if (length < array[1])
    {
        if ((capacity >> 1) <= length)
            FUN_1400051c0(array, array, length);
    }
    else if (length >= capacity)
        FUN_1400051c0(array, array, (length >> 2) + length);
    array[1] = length;
    CriUint32* destination = (CriUint32*)(array[0] - 16 + length * 16);
    if (destination)
    {
        destination[0] = value[0];
        destination[1] = value[1];
        destination[2] = value[2];
        destination[3] = value[3];
    }
}

// MS2-FUNCTIONAL: append a pair of retained strings to the first fixed-width string vector.
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

// MS2-FUNCTIONAL: append a pair of retained strings to the second fixed-width string vector.
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

// MS2-FUNCTIONAL: initialize a lock guard's stored lock pointer and acquire the lock.
// @0x14002d1a0
void* FUN_14002d1a0(void* guard, void* lock)
{
    *(void**)guard = lock;
    FUN_14258aca0(lock);
    return guard;
}

// MS2-FUNCTIONAL: restore the abstract reader interface vtable and run its scalar delete path when requested.
// @0x14002d170
void* FUN_14002d170(CriMvFileReaderInterface* reader, CriUint8 flags)
{
    *(const void***)reader = DAT_1431b95e8;
    if (flags & 1)
        ::operator delete(reader);
    return reader;
}

// MS2-FUNCTIONAL: replace the held reference, releasing the previous object when non-null.
// @0x14002d280
void* FUN_14002d280(void** slot, void* replacement)
{
    if (*slot)
        FUN_14257dcb0(*slot);
    *slot = replacement;
    return slot;
}

// MS2-FUNCTIONAL: allocate a six-byte aligned tag block from the global Scaleform heap.
// @0x14002d3c0
void FUN_14002d3c0(void*, size_t size)
{
    CriUint32 flags[6] = { 6, 0, 0, 0, 0, 0 };
    void* heap = DAT_143b15f60;
    CriUint8* vtable = (CriUint8*)*(void**)heap;
    void* (__fastcall *allocate)(void*, size_t, CriUint32*) =
        (void* (__fastcall *)(void*, size_t, CriUint32*))(vtable + 0x50);
    allocate(heap, size, flags);
}

// MS2-FUNCTIONAL: return a non-null allocation to the global Scaleform heap.
// @0x14002d3f0
void FUN_14002d3f0(void* allocation)
{
    if (allocation)
    {
        void* heap = DAT_143b15f60;
        CriUint8* vtable = (CriUint8*)*(void**)heap;
        void (__fastcall *release)(void*, void*) = (void (__fastcall *)(void*, void*))(vtable + 0x60);
        release(heap, allocation);
    }
}

// MS2-FUNCTIONAL: release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a250
void FUN_14002a250(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// MS2-FUNCTIONAL: release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a270
void FUN_14002a270(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// MS2-FUNCTIONAL: release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a620
void FUN_14002a620(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// MS2-FUNCTIONAL: release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a640
void FUN_14002a640(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// MS2-FUNCTIONAL: release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002a660
void FUN_14002a660(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// MS2-FUNCTIONAL: release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002ab70
void FUN_14002ab70(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// MS2-FUNCTIONAL: release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002acb0
void FUN_14002acb0(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// MS2-FUNCTIONAL: release the pointed-to block through the global Scaleform heap when non-null.
// @0x14002acd0
void FUN_14002acd0(const void* slot)
{
    if (*(void* const*)slot)
        FUN_14002d3f0(*(void* const*)slot);
}

// MS2-FUNCTIONAL: append a run of pointer values, growing backing storage by the observed quarter margin.
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
    else if (array[2] <= newLength)
        FUN_140029bf0(array, array, (newLength >> 2) + newLength);
    array[1] = newLength;
    CriUint64* destination = (CriUint64*)array[0] + oldLength;
    for (CriUint64 i = 0; i < count; ++i)
        if (destination)
            destination[i] = source[i];
}

// MS2-FUNCTIONAL: clear a vector while preserving its one-element inline-capacity sentinel.
// @0x14002afe0
void FUN_14002afe0(CriUint64* array)
{
    if (array[1] == 0)
    {
        if (array[2] == 0)
        {
            FUN_140029bf0(array, array, 0);
            array[1] = 0;
            return;
        }
    }
    else if ((array[2] & ~((CriUint64)1)) != 0)
    {
        if (array[0])
        {
            FUN_14002d3f0((void*)array[0]);
            array[0] = 0;
        }
        array[2] = 0;
        array[1] = 0;
        return;
    }
    array[1] = 0;
}

// MS2-FUNCTIONAL: clear the destination vector before cloning its two-word source state.
// @0x14002a980
CriUint64* FUN_14002a980(CriUint64* destination, const CriUint64* source)
{
    destination[0] = destination[1] = destination[2] = 0;
    FUN_14002a4a0(destination, (const CriUint64*)source[0], source[1]);
    return destination;
}

// MS2-FUNCTIONAL: clear the destination vector before cloning its two-word source state.
// @0x14002afb0
CriUint64* FUN_14002afb0(CriUint64* destination, const CriUint64* source)
{
    destination[0] = destination[1] = destination[2] = 0;
    FUN_14002a4a0(destination, (const CriUint64*)source[0], source[1]);
    return destination;
}

// MS2-FUNCTIONAL: clear the destination vector before cloning its two-word source state.
// @0x14002b9b0
CriUint64* FUN_14002b9b0(CriUint64* destination, const CriUint64* source)
{
    destination[0] = destination[1] = destination[2] = 0;
    FUN_14002a4a0(destination, (const CriUint64*)source[0], source[1]);
    return destination;
}

// MS2-FUNCTIONAL: run the matching vector helper and preserve the original object pointer.
// @0x14002c0c0
void* FUN_14002c0c0(void* object, void* source)
{
    FUN_14002ba30((CriUint64*)object, (const CriUint64*)source);
    return object;
}

// MS2-FUNCTIONAL: run the matching vector helper and preserve the original object pointer.
// @0x14002c780
void* FUN_14002c780(void* object, void* source)
{
    FUN_14002c550((CriUint64*)object, (const CriUint64*)source);
    return object;
}

// MS2-FUNCTIONAL: destroy the base reference-count state and conditionally free its storage.
// @0x14002a2b0
void* FUN_14002a2b0(void* object, CriUint64 flags)
{
    FUN_14257db50(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: destroy the alternate reference-count state and conditionally free its storage.
// @0x14002ac70
void* FUN_14002ac70(void* object, CriUint64 flags)
{
    FUN_142579470(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: destroy the container's base object and optionally return its allocation to the heap.
// @0x14002bac0
void* FUN_14002bac0(void* object, CriUint64 flags)
{
    FUN_14002b2e0(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: destroy the second container base and optionally free its allocation.
// @0x14002c8f0
void* FUN_14002c8f0(void* object, CriUint64 flags)
{
    FUN_14002c5f0(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: destroy the reader configuration and optionally release the containing block.
// @0x14002e510
void* FUN_14002e510(void* object, CriUint64 flags)
{
    FUN_14002e2a0(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: run the shared refcount base cleanup and optionally release its allocation.
// @0x14002d840
void* FUN_14002d840(void* object, CriUint64 flags)
{
    FUN_14257db50(object);
    if (flags & 1)
        FUN_14002d3f0(object);
    return object;
}

// MS2-FUNCTIONAL: enable or disable reader IO, wake the thread, and wait for its queued work to drain.
// @0x14002d6d0
void FUN_14002d6d0(CriMvReaderThreadConfigView* config, CriUint8 enable)
{
    config->IOEnabled = enable;
    FUN_142583d50(config->Event);
    FUN_14258aca0(config->Lock);
    CriMvRequestNode* sentinel = (CriMvRequestNode*)&config->Head;
    while (config->Tail != sentinel)
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

// MS2-FUNCTIONAL: apply an origin-relative seek to the reader's active input or output cursor.
// @0x14002d7b0
CriUint64 FUN_14002d7b0(void* request, CriSint64 offset, CriSint32 origin)
{
    CriMvReaderRequestView* view = (CriMvReaderRequestView*)request;
    CriMvReaderThreadConfigView* config = (CriMvReaderThreadConfigView*)view->Queue;
    FUN_14258aca0(config->Lock);
    CriUint64* cursor = &view->ReadSize;
    if (origin == 1)
        *cursor = view->ReadPosition;
    else if (origin == 2)
        *cursor = view->FileSize;
    else
        *cursor = 0;
    *cursor += (CriUint64)offset;
    CriUint64 result = *cursor;
    FUN_14258bb70(config->Lock);
    return result;
}

// MS2-FUNCTIONAL: acquire a request node from the free list or the current 127-entry block.
// @0x14002d890
CriMvRequestNode* FUN_14002d890(CriMvRequestPoolView* pool)
{
    if (pool->FreeList)
    {
        CriMvRequestNode* result = pool->FreeList;
        pool->FreeList = result->Next;
        return result;
    }
    CriUint32 index = pool->NodesInLastBlock;
    if (index < 0x7f)
    {
        pool->NodesInLastBlock = index + 1;
        return &pool->LastBlock->Nodes[index];
    }
    CriUint32 flags[8] = { 6, 0, 0, 0, 0, 0, 0, 0 };
    void* heap = DAT_143b15f60;
    CriUint8* vtable = (CriUint8*)*(void**)heap;
    void* (__fastcall *allocate)(void*, size_t, CriUint32*) =
        (void* (__fastcall *)(void*, size_t, CriUint32*))(vtable + 0x50);
    CriMvRequestBlock* block = (CriMvRequestBlock*)allocate(heap, sizeof(CriMvRequestBlock), flags);
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
    void* heap = DAT_143b15f60;
    CriUint8* vtable = (CriUint8*)*(void**)heap;
    void (__fastcall *release)(void*, void*) = (void (__fastcall *)(void*, void*))(vtable + 0x60);
    while (block)
    {
        CriMvRequestBlock* next = block->NextBlock;
        release(heap, block);
        block = next;
    }
}

// MS2-FUNCTIONAL: release every request block from the first queue-pool instantiation.
// @0x14002d930
void FUN_14002d930(CriMvRequestPoolView* pool)
{
    CriReleaseRequestBlocks(pool->FirstBlock);
}

// MS2-FUNCTIONAL: release every request block from the second queue-pool instantiation.
// @0x14002dd80
void FUN_14002dd80(CriMvRequestPoolView* pool)
{
    CriReleaseRequestBlocks(pool->FirstBlock);
}

// MS2-FUNCTIONAL: release every request block from the third queue-pool instantiation.
// @0x14002e010
void FUN_14002e010(CriMvRequestPoolView* pool)
{
    CriReleaseRequestBlocks(pool->FirstBlock);
}

// MS2-FUNCTIONAL: initialize CRI Movie on the first reference and maintain its process reference count.
// @0x14002e7d0
void FUN_14002e7d0(void)
{
    if (DAT_143ffd500 == 0)
    {
        memset(&DAT_143ffd500, 0, 0x58);
        FUN_140044e84();
        FUN_140039fc8();
        CriMvCodecRegistrationEntry* entries = (CriMvCodecRegistrationEntry*)DAT_143b27950;
        for (CriUint16 i = 0; i < DAT_143b2794c; ++i)
        {
            FUN_140044390(entries[i].VideoDecoderInterface);
            FUN_140043a20(entries[i].AlphaDecoderInterface);
        }
        FUN_140041ea0();
        DAT_143ffd550 = FUN_1400385c8(DAT_143ffd504, 0x48);
        if (!DAT_143ffd550)
            FUN_140037910(NULL, "E07020200M: Can't create critical section.", 0);
    }
    ++DAT_143ffd500;
}

// MS2-FUNCTIONAL: release CRI Movie subsystems and decoder registrations on the final reference.
// @0x14002e8c0
void FUN_14002e8c0(void)
{
    if (--DAT_143ffd500 == 0)
    {
        FUN_140041ec0();
        CriMvCodecRegistrationEntry* entries = (CriMvCodecRegistrationEntry*)DAT_143b27950;
        for (CriUint16 i = 0; i < DAT_143b2794c; ++i)
        {
            FUN_140043a50(entries[i].AlphaDecoderInterface);
            FUN_1400443d0(entries[i].VideoDecoderInterface);
            entries[i] = CriMvCodecRegistrationEntry();
        }
        DAT_143b2794c = 0;
        FUN_14003a010();
        FUN_140044ea8();
        if (DAT_143ffd550)
        {
            FUN_140039f00(DAT_143ffd550);
            DAT_143ffd550 = NULL;
        }
    }
}

// MS2-FUNCTIONAL: find the registered video decoder interface, mapping codec zero to codec one.
// @0x140030b50
void* FUN_140030b50(CriSint32 codecId)
{
    if (codecId == 0)
        codecId = 1;
    CriMvCodecRegistrationEntry* entries = (CriMvCodecRegistrationEntry*)DAT_143b27950;
    for (CriUint16 i = 0; i < DAT_143b2794c; ++i)
        if (entries[i].CodecId == codecId)
            return entries[i].VideoDecoderInterface;
    return NULL;
}

// MS2-FUNCTIONAL: find the registered alpha decoder interface, mapping codec zero to codec one.
// @0x140030be0
void* FUN_140030be0(CriSint32 codecId)
{
    if (codecId == 0)
        codecId = 1;
    CriMvCodecRegistrationEntry* entries = (CriMvCodecRegistrationEntry*)DAT_143b27950;
    for (CriUint16 i = 0; i < DAT_143b2794c; ++i)
        if (entries[i].CodecId == codecId)
            return entries[i].AlphaDecoderInterface;
    return NULL;
}

// MS2-FUNCTIONAL: service subtitles, header preparation, frame queues and audio for active players.
// @0x14002fb70
void FUN_14002fb70(void* player)
{
    CriSint32 status = ((CriMvPlyStateTransitionFields*)player)->Status;
    if (status != 0 && status != 9 && status != 7 && status != 6)
    {
        FUN_140036650(player);
        FUN_140036710(player);
        FUN_1400369e0(player);
        FUN_140034c20(player);
    }
}

// MS2-FUNCTIONAL: report whether a default USM decryption key has been configured.
// @0x140037a10
CriBool FUN_140037a10(void)
{
    return DAT_143b27a40 != NULL;
}

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
            FUN_140037910(player, "E08120301M: Illigal data size of input stream.", buffer.Capacity);
        memcpy(buffer.Data, chunk.Data, chunk.Size);
        copied += chunk.Size;
        FUN_140046814(dataQueue, &buffer, chunk.Size);
    }

    while (FUN_1400467b8(source, 1) != 0)
    {
        FUN_140046804(dataQueue, &buffer);
        FUN_1400467a0(source, 1, -1, &chunk);
        if (buffer.Capacity < chunk.Size)
            FUN_140037910(player, "E08120302M: Illigal data size in input buffer.", buffer.Capacity);
        memcpy(buffer.Data, chunk.Data, chunk.Size);
        copied += chunk.Size;
        FUN_140046814(dataQueue, &buffer, chunk.Size);
        FUN_1400467b0(source, 0, &chunk);
    }
    (void)copied;
}

// MS2-FUNCTIONAL: parse sample rate, channel count, sample count, and buffer size from an audio header.
// @0x140032a70
void FUN_140032a70(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    output[0] = FUN_14003a85c(document, 0, "sampling_rate");
    output[1] = FUN_14003a85c(document, 0, "num_channels");
    output[2] = FUN_14003a85c(document, 0, "total_samples");
    output[3] = FUN_14003a85c(document, 0, "ixsize");
    CriUint32 suggestedSize = FUN_14003a85c(document, 0, "ixsize");
    WorkSizeView* work = (WorkSizeView*)workInfo;
    if (work->Size < suggestedSize)
        work->Size = suggestedSize;
    FUN_14003a108(document);
}

// MS2-FUNCTIONAL: parse channel and time-base metadata for a CRI Movie stream record.
// @0x140032b70
void FUN_140032b70(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    output[1] = FUN_14003a85c(document, 0, "num_channels");
    CriUint32 timeUnit = FUN_14003a85c(document, 0, "time_unit");
    ((CriUint64*)output)[1] = timeUnit;
    output[4] = 0x400;
    CriUint32 suggestedSize = FUN_14003a85c(document, 0, "ixsize");
    WorkSizeView* work = (WorkSizeView*)workInfo;
    if (work->Size < suggestedSize)
        work->Size = suggestedSize;
    if (output[1] != 0 && ((CriUint64*)output)[1] != 0 && output[4] != 0)
        output[0] = 1;
    FUN_14003a108(document);
}

// MS2-FUNCTIONAL: parse the cue metadata header and raise the required working-buffer size.
// @0x140032c70
void FUN_140032c70(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    output[1] = FUN_14003a85c(document, 0, "metadata_count");
    output[2] = FUN_14003a85c(document, 0, "metadata_size");
    output[3] = FUN_14003a85c(document, 0, "total_points");
    CriUint32 timeUnit = FUN_14003a85c(document, 0, "time_unit");
    ((CriUint64*)output)[2] = timeUnit;
    CriUint32 suggestedSize = FUN_14003a85c(document, 0, "ixsize");
    WorkSizeView* work = (WorkSizeView*)workInfo;
    if (work->Size < suggestedSize)
        work->Size = suggestedSize;
    if (output[1] == 1 && output[2] != 0 && output[3] != 0 && ((CriUint64*)output)[2] != 0)
        output[0] = 1;
    FUN_14003a108(document);
}

// MS2-FUNCTIONAL: parse video dimensions, timing, codec, alpha, and metadata information.
// @0x140032db0
void FUN_140032db0(void* player, void* workInfo, CriUint32* output, const CriMovieParsedChunk* parsed)
{
    struct WorkSizeView { CriUint32 Reserved; CriUint32 Size; };
    void* document = FUN_14003b348(((CriMvPlyObj*)player)->utf_heap, parsed->Data, parsed->Size);
    CriUint32 rateNumerator = FUN_14003a85c(document, 0, "framerate_n");
    CriUint32 rateDenominator = FUN_14003a85c(document, 0, "framerate_d");
    output[4] = (CriUint32)(((float)rateNumerator * 1000.0f) / (float)rateDenominator);
    output[5] = FUN_14003a85c(document, 0, "total_frames");
    output[0] = FUN_14003a85c(document, 0, "width");
    output[1] = FUN_14003a85c(document, 0, "height");
    CriUint32 suggestedSize = FUN_14003a85c(document, 0, "ixsize");
    WorkSizeView* work = (WorkSizeView*)workInfo;
    if (work->Size < suggestedSize)
        work->Size = suggestedSize;
    output[10] = FUN_14003a3e0(document, "pre_padding") < 1
        ? 0x40 : FUN_14003a85c(document, 0, "pre_padding");
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
    FUN_14003a108(document);
}

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
        CriUint8 Reserved20[4];
        CriSint32 Field24;
        CriUint8 Reserved28[0x24];
        CriUint32 PlaneCount;
        PlaneInfo Planes[8];
    };
    struct CompareModeView { CriUint8 Reserved[0xb28]; CriSint32 Mode; };
    const StreamInfo* left = (const StreamInfo*)leftValue;
    const StreamInfo* right = (const StreamInfo*)rightValue;
    if (left->Field18 != right->Field18 || left->Field14 != right->Field14 ||
        left->Field24 != right->Field24)
        return 0;
    if (((CompareModeView*)player)->Mode >= 0)
    {
        if (left->PlaneCount != right->PlaneCount)
            return 0;
        for (CriUint32 i = 0; i < left->PlaneCount; ++i)
        {
            if (left->Planes[i].First != right->Planes[i].First ||
                left->Planes[i].Second != right->Planes[i].Second)
                return 0;
        }
    }
    return 1;
}

// MS2-FUNCTIONAL: discard handled command chunks while returning ordinary input records to the stream.
// @0x140033610
void FUN_140033610(void* player)
{
    void* queue = ((CriMvPlyInputQueueFields*)player)->ReadBuffer;
    struct ChunkView { void* Data; CriUint32 Size; } chunk = {};
    CriUint8 parsedHeader[0x20];
    CriSint32 contentSize = 0;
    for (;;)
    {
        if (FUN_1400467b8(queue, 1) == 0)
            return;
        FUN_1400467a0(queue, 1, -1, &chunk);
        if (chunk.Size < 0x20)
        {
            FUN_1400467a8(queue, 1, &chunk);
            return;
        }
        memset(parsedHeader, 0, sizeof(parsedHeader));
        FUN_14003b3fc((const CriUint8*)chunk.Data, chunk.Size, parsedHeader);
        FUN_14003b674((const CriUint8*)chunk.Data, chunk.Size, &contentSize);
        if (parsedHeader[0xf] != 2 && parsedHeader[0xf] != 3)
        {
            FUN_1400467a8(queue, 1, &chunk);
            return;
        }
        FUN_1400467b0(queue, 2, &chunk);
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
    CleanupView* state = (CleanupView*)player;
    if (state->StreamJoint)
    {
        FUN_140046784(state->StreamJoint);
        state->StreamJoint = NULL;
        if (state->CallbackBuffer)
            state->Release(state->ReleaseContext, state->CallbackBuffer);
    }
    if (state->Work)
    {
        if (!state->WorkReleaseBuffer)
        {
            if (state->Heap)
                FUN_140027fb4(state->Heap, state->Work);
        }
        else
            state->Release(state->ReleaseContext, state->WorkReleaseBuffer);
        state->Work = NULL;
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
        CriUint8 Reserved0C[4];
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
        CriUint8 ReservedD70[0x10];
        void* OutputStream;
        CriUint8 ReservedD88[0x140];
        CriUint32 InputCount0;
        CriUint32 InputCount1;
        CriUint32 InputCount2;
    };
    if (!player)
    {
        FUN_140037950(NULL, "E05121601M: CriMvPly handle is NULL.", 0);
        return 0;
    }

    PlayerResetView* state = (PlayerResetView*)player;
    if (state->Status != 0 && state->Status != 7)
    {
        FUN_140037950(player, "E05121602M: Can't execute start in the current state.", state->Status);
        return 0;
    }

    state->ResetTimer = 0;
    state->HeaderSize = 0;
    memset(state->AnalyzedHeader, 0, sizeof(state->AnalyzedHeader));
    state->ReadMode = 0;
    FUN_140044fa8(state->Demux, NULL);
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
    state->InternalFlags = 0;
    state->Status = 1;
    return 1;
}

// MS2-FUNCTIONAL: reset the demux and its output stream after the player update completes.
// @0x140031990
CriBool FUN_140031990(void* player)
{
    if (FUN_140031aa0(player) != 1)
        return 0;
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)player;
    CriMvPlyInputQueueFields* queues = (CriMvPlyInputQueueFields*)player;
    struct ReadModeView { CriUint8 Reserved[0xd60]; CriSint32 Mode; };
    struct MemoryInputView { CriUint8 Reserved[0xda0]; void* Input; };
    FUN_140034330(player, queues->InputBuffer, queues->ReadBuffer, queues->HeaderBuffer);
    FUN_1400453c4(state->Demux);
    FUN_140046798(queues->ReadBuffer);
    void* nextInput = ((ReadModeView*)player)->Mode == 0
        ? queues->HeaderBuffer : ((MemoryInputView*)player)->Input;
    FUN_140044fa8(state->Demux, nextInput);
    FUN_140044fb0(state->Demux, 0, queues->ReadBuffer, 0, (CriUint32)-1);
    FUN_140044fd8(state->Demux, 0);
    FUN_140044f9c(state->Demux);
    FUN_1400458b8(state->Demux);
    return 1;
}

// MS2-FUNCTIONAL: advance a completed video or alpha decoder through the metadata and stop phases.
// @0x1400344f0
void FUN_1400344f0(void* player)
{
    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)player;
    if (decoders->VideoDecoder && FUN_140044630(decoders->VideoDecoder) != 3)
        return;

    if (decoders->AlphaDecoder)
    {
        FUN_140035bf0(player);
        if (FUN_140043cb0(decoders->AlphaDecoder) != 3)
        {
            state->StopState = 2;
            return;
        }
    }

    CriSint32 result = FUN_140042d70(decoders->AudioManager, player);
    if (result == 1)
    {
        if (isLockedInputChunk(player) == 1)
            state->StopState = 3;
        else
        {
            FUN_140031570(player);
            state->Status = 6;
            state->StopState = 5;
        }
    }
    else
        state->StopState = 4;
}

// MS2-FUNCTIONAL: copy the selected analyzed-header or input-buffer remainder into the read queue.
// @0x1400342b0
void FUN_1400342b0(void* player)
{
    CriMvPlyObj* movie = (CriMvPlyObj*)player;
    CriMvPlyInputQueueFields* input = (CriMvPlyInputQueueFields*)player;
    if (input->PendingData < 1)
    {
        void* source = movie->seekinfo_flag == 0 ? input->InputBuffer : input->HeaderBuffer;
        FUN_140034330(player, source, input->ReadBuffer, input->DataQueue);
    }
}

// MS2-FUNCTIONAL: perform the executable's pending start/stop state transition on the player.
// @0x140031140
void FUN_140031140(void* player)
{
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)player;
    CriSint32 status = state->Status;
    if (status == 2)
    {
        if (state->StartReady == 1)
        {
            FUN_1400342b0(player);
            FUN_1400453c4(state->Demux);
            state->InternalFlags = 0;
            state->Status = 3;
        }
        else
            FUN_140037950(player, "E05063019M: Can't start movie while not ready.", 0);
    }
    else if (status == 4)
        state->Status = 5;
    else if (status == 6)
    {
        state->LastFrame = -1;
        state->Status = 7;
        state->StopState = 0;
    }
    else if (status == 9)
    {
        state->LastFrame = -1;
        state->Status = 0;
        state->StopState = 0;
    }
}

// MS2-FUNCTIONAL: advance decoder and audio processing according to the CRI Movie state machine.
// @0x140031290
void FUN_140031290(void* player)
{
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)player;
    CriSint32 status = getInternalStatus(player);
    if (status == 0 || status == 9 || status == 7 || status == 6)
        return;

    if (status != 1)
        FUN_140034730(player);
    FUN_140034690(player);

    if (getInternalStatus(player) == 8)
    {
        if (FUN_1400314d0(player) == 1)
        {
            if (isLockedInputChunk(player) == 1)
                state->StopState = 3;
            else
            {
                FUN_140031570(player);
                state->Status = 9;
                state->StopState = 5;
                state->InternalFlags = 0;
            }
        }
        return;
    }

    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    if (decoders->AudioManager)
        FUN_1400428e0(decoders->AudioManager, player);
    status = getInternalStatus(player);
    if (status == 3)
        FUN_140033810(player);
    else if (status == 5)
        FUN_1400344f0(player);
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
    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    CriBool result = FUN_140043d40(decoders->VideoDecoder);
    if (decoders->AlphaDecoder)
        FUN_1400446c0(decoders->AlphaDecoder);
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
    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)player;
    if (decoders->VideoDecoder && FUN_140044630(decoders->VideoDecoder) != 0)
    {
        state->StopState = 1;
        return 0;
    }
    if (decoders->AlphaDecoder && FUN_140043cb0(decoders->AlphaDecoder) != 0)
    {
        state->StopState = 2;
        return 0;
    }
    return 1;
}

// MS2-FUNCTIONAL: decode a video frame while holding the global CRI movie-player lock.
// @0x1400313d0
CriBool FUN_1400313d0(void* player)
{
    FUN_1400378b0();
    CriBool result = FUN_140031410(player);
    FUN_1400378e0();
    return result;
}

// MS2-FUNCTIONAL: process a pending video-server frame and update decoder progress.
// @0x140031470
void FUN_140031470(void* player)
{
    FUN_140034730(player);
    FUN_1400317b0(player);
}

// MS2-FUNCTIONAL: discard the player's pending subtitle chunk.
// @0x140036e30
void FUN_140036e30(void* player, CriMvSubtitleChunk* chunk)
{
    void* queue = player ? ((CriMvSubtitleFields*)player)->Queue : NULL;
    if (queue)
        FUN_1400467b0(queue, 0, chunk);
}

// MS2-FUNCTIONAL: return a subtitle chunk to the head of the player's subtitle queue.
// @0x140036e80
void FUN_140036e80(void* player, CriMvSubtitleChunk* chunk)
{
    void* queue = player ? ((CriMvSubtitleFields*)player)->Queue : NULL;
    if (queue)
        FUN_1400467a8(queue, 1, chunk);
}

// MS2-FUNCTIONAL: release the main and current alpha frame held by the easy player.
// @0x140038fa0
CriSint32 FUN_140038fa0(void* easyPlayer, const CriMvFrameInfo* frameInfo, CriError* error)
{
    CriMvEasyPlayerFrameFields* fields = (CriMvEasyPlayerFrameFields*)easyPlayer;
    *error = CRIERR_OK;
    FUN_140035a40(fields->PlayerHandle, frameInfo);
    if (*(CriUint64*)fields->AlphaFrameInfo)
        FUN_140035a90(fields->PlayerHandle, (const CriUint64*)fields->AlphaFrameInfo);
    return 1;
}

// MS2-FUNCTIONAL: discard the next decoded frame and clear the current-frame bookkeeping.
// @0x140039110
CriSint32 FUN_140039110(void* easyPlayer, CriMvFrameInfo* frameInfo, CriError* error)
{
    CriMvEasyPlayerFrameFields* fields = (CriMvEasyPlayerFrameFields*)easyPlayer;
    *error = CRIERR_OK;
    CriSint32 result = FUN_1400355b0(fields->PlayerHandle);
    FUN_1400393f0(easyPlayer, 0, 0, 1, 0, 0);
    (void)frameInfo;
    return result;
}

// MS2-FUNCTIONAL: apply the analyzed movie header after a successful decoder analysis pass.
// @0x1400318f0
CriBool FUN_1400318f0(void* player)
{
    if (((CriMvPlyObj*)player)->decoder_error)
        return 0;
    if (FUN_140032090(player) != 1)
        return 0;
    CriMvPlyHeaderAnalysisFields* fields = (CriMvPlyHeaderAnalysisFields*)player;
    memcpy(fields->CurrentHeader, fields->AnalyzedHeader, sizeof(fields->CurrentHeader));
    fields->HeaderParameter = 0;
    return 1;
}

// MS2-FUNCTIONAL: complete the metadata stage only when parsing succeeds without a decoder error.
// @0x140032040
CriBool FUN_140032040(void* player)
{
    return ((CriMvPlyObj*)player)->decoder_error == 0 && FUN_140033030(player) == 1;
}

// MS2-FUNCTIONAL: run the metadata-work cleanup under the player's handle critical section.
// @0x140031f00
CriBool FUN_140031f00(void* player)
{
    FUN_140037850(player);
    CriBool result = FUN_140031f40(player);
    FUN_140037880(player);
    return result;
}

// MS2-FUNCTIONAL: enter the player's handle lock around the requested CRI Movie transition.
// @0x140034920
CriBool FUN_140034920(void* player)
{
    FUN_140037850(player);
    CriBool result = FUN_140034960(player);
    FUN_140037880(player);
    return result;
}

// MS2-FUNCTIONAL: copy the decoded frame metadata and add the alpha frame metadata when available.
// @0x1400356a0
void FUN_1400356a0(void* player, void* output, void* alphaOutput,
                   const CriMvFrameInfo* frameInfo, const void* alphaInfo)
{
    FUN_140035260(player, output, frameInfo, *(const CriUint64*)frameInfo,
                  *(const CriUint32*)((const CriUint8*)frameInfo + 0x0c));
    if (((CriMvDecoderHandleFields*)player)->AlphaDecoder)
        FUN_140035480(player, alphaOutput, alphaInfo);
}

// MS2-FUNCTIONAL: destroy player-owned decoders and queues under the player's handle lock.
// @0x140030c70
void FUN_140030c70(void* player)
{
    FUN_140037850(player);
    FUN_140030cb0(player);
    FUN_140037880(player);
}

// MS2-FUNCTIONAL: release every CRI Movie player subsystem and clear its owned state.
// @0x140030cb0
void FUN_140030cb0(void* player)
{
    CriUint8* bytes = (CriUint8*)player;
    void** fields = (void**)player;
    if (fields[0xe28 / sizeof(void*)])
    {
        FUN_140046784(fields[0xe28 / sizeof(void*)]);
        fields[0xe28 / sizeof(void*)] = 0;
    }
    if (fields[0xe10 / sizeof(void*)])
    {
        FUN_1400420b0(fields[0xe10 / sizeof(void*)], fields[0xee0 / sizeof(void*)]);
        fields[0xe10 / sizeof(void*)] = 0;
    }
    if (fields[0xe40 / sizeof(void*)])
    {
        FUN_140043be0(fields[0xe40 / sizeof(void*)]);
        fields[0xe40 / sizeof(void*)] = 0;
    }
    if (fields[0xe08 / sizeof(void*)])
    {
        FUN_140043be0(fields[0xe08 / sizeof(void*)]);
        fields[0xe08 / sizeof(void*)] = 0;
    }
    if (fields[0xd88 / sizeof(void*)])
    {
        FUN_140046784(fields[0xd88 / sizeof(void*)]);
        memset(bytes + 0xdf8, 0, 8);
        fields[0xd88 / sizeof(void*)] = 0;
    }
    memset(bytes + 0xad8, 0, 0x288);
    if (fields[0xee0 / sizeof(void*)])
    {
        FUN_140028074(fields[0xee0 / sizeof(void*)]);
        fields[0xee0 / sizeof(void*)] = 0;
    }
    memset(bytes + 0xad4, 0, 4);
}

// MS2-FUNCTIONAL: perform the player update under its handle critical section.
// @0x140031aa0
CriBool FUN_140031aa0(void* player)
{
    FUN_140037850(player);
    CriBool result = FUN_140031ae0(player);
    FUN_140037880(player);
    return result;
}

// MS2-FUNCTIONAL: request both video decoders to stop and move the player into stop-pending state.
// @0x140034b60
void FUN_140034b60(void* player)
{
    CriMvPlyStateTransitionFields* state = (CriMvPlyStateTransitionFields*)player;
    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    if (state->Status == 0 || state->Status == 7)
        state->Status = 0;
    else if (state->Status != 9 && state->Status != 6)
    {
        state->InternalFlags = 1;
        state->Status = 8;
        if (decoders->VideoDecoder)
            FUN_140044750(decoders->VideoDecoder);
        if (decoders->AlphaDecoder)
            FUN_140043dd0(decoders->AlphaDecoder);
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
void FUN_140035f00(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    FUN_140042e40(((CriMvDecoderHandleFields*)player)->AudioManager, 0, player,
                  format, output, sampleCount, result);
}

// MS2-FUNCTIONAL: fetch a 32-bit waveform block from the main audio stream.
// @0x140035f70
void FUN_140035f70(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    FUN_140042ea0(((CriMvDecoderHandleFields*)player)->AudioManager, 0, player,
                  format, output, sampleCount, result);
}

// MS2-FUNCTIONAL: fetch a 16-bit waveform block from the secondary audio stream.
// @0x140035fe0
void FUN_140035fe0(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    FUN_140042e40(((CriMvDecoderHandleFields*)player)->AudioManager, 1, player,
                  format, output, sampleCount, result);
}

// MS2-FUNCTIONAL: fetch a 32-bit waveform block from the secondary audio stream.
// @0x140036050
void FUN_140036050(void* player, CriUint32 format, void* output, CriUint32 sampleCount, void* result)
{
    FUN_140042ea0(((CriMvDecoderHandleFields*)player)->AudioManager, 1, player,
                  format, output, sampleCount, result);
}

// MS2-FUNCTIONAL: request the next alpha-frame metadata record when the alpha decoder is present.
// @0x140035e90
CriBool FUN_140035e90(void* player, void* frameInfo, void* reserved1, void* reserved2)
{
    void* decoder = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
    if (!decoder)
        return 0;
    return FUN_140043f10(decoder, frameInfo) != NULL;
}

// MS2-FUNCTIONAL: advance the alpha decoder to the requested frame, releasing frames skipped en route.
// @0x140035db0
CriBool FUN_140035db0(void* player, CriSint32 targetFrame, void* frameInfo, void* reserved)
{
    if (!FUN_140035e90(player, frameInfo, frameInfo, reserved))
        return 0;
    void* decoder = ((CriMvDecoderHandleFields*)player)->AlphaDecoder;
    for (;;)
    {
        CriSint32 currentFrame = *(CriSint32*)((CriUint8*)frameInfo + 8);
        if (targetFrame <= currentFrame)
            return 1;
        if (!FUN_140043fe0(decoder, frameInfo))
            return 0;
        FUN_140044050(decoder, frameInfo);
        if (currentFrame + 1 == targetFrame)
            return FUN_140043f10(decoder, frameInfo) != NULL;
    }
}

// MS2-FUNCTIONAL: pair the next video frame with its matching alpha frame when the alpha decoder is ready.
// @0x140035c80
void* FUN_140035c80(void* player, void* output)
{
    FUN_140035090(output);
    if (!crimvply_isUnderGetFrameCondition(player))
        return NULL;

    CriMvDecoderHandleFields* decoders = (CriMvDecoderHandleFields*)player;
    CriMvFrameInfo frame = {};
    void* frameToken = FUN_140044870(decoders->VideoDecoder, &frame);
    if (!frameToken)
        return NULL;

    if (decoders->AlphaDecoder)
    {
        if (FUN_140043cb0(decoders->AlphaDecoder) == 3)
        {
            FUN_140037950(player, "E08092600M: Alpha channel is lost.", 0);
            return NULL;
        }
        CriUint8 alphaFrame[0x50] = {};
        if (!FUN_140035db0(player, frame.frame_id, alphaFrame, NULL))
            return NULL;
    }

    FUN_140035260(player, output, &frame, (CriUint64)(uintptr_t)frameToken, 0);
    return frameToken;
}

// MS2-FUNCTIONAL: return the ordinary or suppressed CRI error count selected by the API flag.
// @0x140038eec
CriUint32 criErr_GetErrorCount(CriSint32 type)
{
    CriUint32 count = type == 0 ? DAT_143b27bcc : DAT_143b27bd0;
    if (type == 0 || type == 1)
        return count;
    FUN_140038e24(0, "E09012703B", -2);
    return 0;
}

// MS2-FUNCTIONAL: reset one of CRI Error's two counters or report the invalid selector.
// @0x140038f24
void criErr_ResetErrorCount(CriSint32 type)
{
    if (type == 0)
        DAT_143b27bcc = 0;
    else if (type == 1)
        DAT_143b27bd0 = 0;
    else
        FUN_140038e24(0, "E09012704B", -2);
}

// MS2-FUNCTIONAL: publish the callback and user object used to compare decoded frame times.
// @0x140039750
void CriMvEasyPlayer::SetCompareFrameTimeCallback(
    CriSint32 (*callback)(CriMvEasyPlayer*, CriMvFrameInfo*, CriUint64, CriUint64, void*),
    void* userObject, CriError& error)
{
    error = CRIERR_OK;
    *(decltype(callback)*)((CriUint8*)this + 0x620) = callback;
    *(void**)((CriUint8*)this + 0x628) = userObject;
}

// MS2-FUNCTIONAL: query the easy player's next frame using the standard one-frame offset.
// @0x140038f60
CriSint32 CriMvEasyPlayer::IsNextFrameOnTime(CriError& error)
{
    return isNextFrameOnTime(1, error);
}

// MS2-FUNCTIONAL: release the optional alpha frame and the associated main video frame.
// @0x140039d80
CriSint32 CriMvEasyPlayer::UnlockFrameBufferWithAlpha(const CriMvFrameInfo* frameInfo,
                                                       const CriMvAlphaFrameInfo* alphaInfo,
                                                       CriError& error)
{
    error = CRIERR_OK;
    FUN_140035a90(*(void**)this, (const CriUint64*)alphaInfo);
    FUN_140035a40(*(void**)this, frameInfo);
    return 1;
}

// MS2-FUNCTIONAL: allocate the 0x40-byte memory reader from its CRI heap and initialize its state.
// @0x1400385d0
CriMvEasyFileReaderMem* CriMvEasyFileReaderMem::Create(CriHeap heap)
{
    void* memory = CriAllocator::operator new(0x40, heap, CRIHEAP_TYPE_FIX, "CriMvEasyFileReaderMem", 4);
    if (!memory)
        return NULL;
    CriMvEasyFileReaderMem* reader = ::new(memory) CriMvEasyFileReaderMem();
    reader->Data = NULL;
    reader->FileSize = -1;
    reader->Heap = heap;
    reader->Position = 0;
    reader->ReadSize = 0;
    reader->OpenState = ASYNC_STATUS_STOP;
    reader->CloseState = ASYNC_STATUS_STOP;
    reader->ReadState = ASYNC_STATUS_STOP;
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
    OpenState = ASYNC_STATUS_BUSY;
    if (!fname || strncmp(fname, "MFS:", 4) != 0)
    {
        OpenState = ASYNC_STATUS_ERROR;
        return;
    }
    const CriChar8* dot = strchr(fname + 4, '.');
    if (!dot || dot == fname + 4 || !dot[1])
    {
        OpenState = ASYNC_STATUS_ERROR;
        return;
    }
    char addressText[32] = {};
    char sizeText[32] = {};
    size_t addressLen = (size_t)(dot - (fname + 4));
    if (addressLen >= sizeof(addressText) || strlen(dot + 1) >= sizeof(sizeText))
    {
        OpenState = ASYNC_STATUS_ERROR;
        return;
    }
    memcpy(addressText, fname + 4, addressLen);
    strcpy_s(sizeText, dot + 1);
    char* endAddress = NULL;
    char* endSize = NULL;
    unsigned __int64 address = _strtoui64(addressText, &endAddress, 16);
    unsigned __int64 size = _strtoui64(sizeText, &endSize, 16);
    if (!endAddress || *endAddress || !endSize || *endSize)
    {
        OpenState = ASYNC_STATUS_ERROR;
        return;
    }
    Data = (CriUint8*)(uintptr_t)address;
    FileSize = (CriSint64)size;
    Position = 0;
    ReadSize = 0;
    OpenState = ASYNC_STATUS_COMPLETE;
}

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

// MS2-FUNCTIONAL: adjust the memory-file position according to the CRI seek origin.
// @0x140038950
CriSint64 CriMvEasyFileReaderMem::Seek(CriSint64 size, CriMvFileReaderInterface::SeekOrigin origin)
{
    if (origin == SEEK_FROM_BEGIN)
        Position = size;
    else if (origin == SEEK_FROM_CURRENT)
        Position += size;
    else
        Position = FileSize + size;
    return (CriSint64)origin;
}

// MS2-FUNCTIONAL: return the configured memory-file size.
// @0x1400389d0
CriSint64 CriMvEasyFileReaderMem::GetFileSize(void)
{
    return FileSize;
}

// MS2-FUNCTIONAL: the derived memory reader has no resources beyond its base reader state.
// @0x140038c80
CriMvEasyFileReaderMem::~CriMvEasyFileReaderMem()
{
}

// MS2-FUNCTIONAL: destroy the reader and release its CRI heap allocation when requested.
// @0x140038c40
void* FUN_140038c40(CriMvEasyFileReaderMem* reader, CriUint32 flags)
{
    reader->~CriMvEasyFileReaderMem();
    if ((flags & 1) != 0)
        CriAllocator::operator delete(reader, (size_t)0x40);
    return reader;
}

// MS2-FUNCTIONAL: destroy the reader through its virtual deleting destructor.
// @0x1400386c0
void CriMvEasyFileReaderMem::Destroy(void)
{
    FUN_140038c40(this, 1);
}

// MS2-PIN: ??_7VideoPlayer@Video@GFx@Scaleform@@6B@ 0x1431b8e30
// MS2-PIN: ??_7VideoPlayerImpl@Video@GFx@Scaleform@@6B@ 0x1431b9260
// MS2-PIN: ??_7VideoDecoderSmp@Video@GFx@Scaleform@@6B@ 0x1431b9170
// MS2-PIN: ??_7VideoDecoderThrd@Video@GFx@Scaleform@@6B@ 0x1431b9200
// MS2-PIN: ??_7VideoReader@Video@GFx@Scaleform@@6BRefCountImplCore@Scaleform@@@ 0x1431b93b0
// MS2-PIN: ??_7VideoReader@Video@GFx@Scaleform@@6BCriMvFileReaderInterface@@@ 0x1431b9360
// MS2-PIN: ??_7VideoReaderConfigSmp@Video@GFx@Scaleform@@6B@ 0x1431b91d8
