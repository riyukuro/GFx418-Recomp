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
// MS2-RANGE: 0x140031290-0x1400313d0 .text$mn
// MS2-RANGE: 0x140031990-0x140031aa0 .text$mn
// MS2-RANGE: 0x140034330-0x1400344f0 .text$mn
// MS2-RANGE: 0x140034d40-0x140034e70 .text$mn
// MS2-RANGE: 0x1400356a0-0x140035710 .text$mn
// MS2-RANGE: 0x140035800-0x1400359e0 .text$mn
// MS2-RANGE: 0x140036470-0x140036590 .text$mn
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
typedef struct CriUsfChunkHeader            // FUN_14003b3fc fills 0x24 bytes
{
    CriUint32 Reserved0[3];
    CriUint8  Reserved0C, Reserved0D, Reserved0E;
    CriUint8  Type;                         // 0x0f
    CriUint32 Reserved10[5];
} CriUsfChunkHeader;
typedef struct CriMvSubtitleItemInfo        // FUN_140036f40 fills 0x38 bytes
{
    CriUint32 Reserved0[3];
    CriSint32 Channel;                      // 0x0c
    CriUint64 Reserved10[5];
} CriMvSubtitleItemInfo;
typedef struct CriMvSubtitleFrameCounter { CriUint8 Reserved[0xe30]; CriUint32 Value; } CriMvSubtitleFrameCounter;

void FUN_140028074(void* heap);
CriBool FUN_140031aa0(void* player);
void FUN_140034330(void* player, void* source, void* readBuffer, void* dataQueue);
void FUN_1400453c4(void* demux);
void FUN_1400458b8(void* demux);
void FUN_140044f9c(void* demux);
void FUN_140044fa8(void* demux, void* value);
void FUN_140044fb0(void* output, CriUint32 index, void* value, CriUint32 type, CriUint32 flags);
void FUN_140044fd8(void* demux, CriUint8 value);
void FUN_140046798(void* streamJoint);
void* FUN_140037050(void* player, CriUint32* available, CriUint32* bounded);
void FUN_1400467a0(void* queue, CriSint32 operation, CriSint32 timeout, void* item);
void FUN_1400467a8(void* queue, CriSint32 operation, void* chunk);
CriSint32 FUN_1400467b8(void* ringBuffer, CriSint32 query);
void FUN_140046804(void* object, void* value);
void FUN_140046814(void* streamJoint, const void* chunk, CriUint32 size);
void FUN_140037910(void* owner, const char* message, CriSint32 value);
void FUN_1400467b0(void* queue, CriSint32 operation, void* chunk);
CriUint32 FUN_14003b3fc(const CriUint8* data, CriUint32 size, void* output);
CriBool FUN_140036d50(void* player, const CriMovieInputChunk* input);
CriBool FUN_1400314d0(void* player);
void FUN_140031570(void* player);
void FUN_140033810(void* player);
void FUN_1400344f0(void* player);
void FUN_140034690(void* player);
void FUN_140034730(void* player);
void FUN_1400428e0(void* audioManager, void* player);
CriSint32 getInternalStatus(void* player);
CriBool isLockedInputChunk(const void* player);
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
#pragma comment(linker, "/alternatename:?FUN_140031290@@YAXPEAX@Z=FUN_140031290")
#pragma comment(linker, "/alternatename:?FUN_140031990@@YAJPEAX@Z=FUN_140031990")
#pragma comment(linker, "/alternatename:?FUN_140034330@@YAXPEAX000@Z=FUN_140034330")
#pragma comment(linker, "/alternatename:?FUN_140034d40@@YAXPEAXPEAUCriMovieInputChunk@@@Z=FUN_140034d40")
#pragma comment(linker, "/alternatename:getInternalStatus=?getInternalStatus@@YAJPEAX@Z")
#pragma comment(linker, "/alternatename:isLockedInputChunk=?isLockedInputChunk@@YAJPEBX@Z")
#pragma comment(linker, "/alternatename:?criMvPly_GetSubtitle@@YAXPEAX0K0@Z=criMvPly_GetSubtitle")
#pragma comment(linker, "/alternatename:?FUN_1400356a0@@YAXPEAX00PEBUCriMvFrameInfo@@PEBX@Z=FUN_1400356a0")
#pragma comment(linker, "/alternatename:?FUN_140035800@@YAJPEAX00@Z=FUN_140035800")
#pragma comment(linker, "/alternatename:?FUN_1400358d0@@YAKPEAXPEBX@Z=FUN_1400358d0")
#pragma comment(linker, "/alternatename:?FUN_140036b80@@YAJPEAXPEAUCriMvSubtitleChunk@@J@Z=FUN_140036b80")
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

// advance decoder and audio processing according to the CRI Movie state machine
// @0x140031290
void FUN_140031290(void* player)
{
    CriSint32 status;
    status = getInternalStatus(player);
    if (status == 0 || status == 9 || status == 7 || status == 6)
        return;

    if (((CriMvPlyStateView*)player)->Status != 1)
        FUN_140034730(player);
    FUN_140034690(player);

    if (((CriMvPlyStateView*)player)->Status == 8)
    {
        if (FUN_1400314d0(player) == 1)
        {
            if (isLockedInputChunk(player) == 1)
            {
                ((CriMvPlyStateView*)player)->StopState = 3;
                return;
            }
            FUN_140031570(player);
            ((CriMvPlyStateView*)player)->Status = 9;
            ((CriMvPlyStateView*)player)->StopState = 5;
            ((CriMvPlyStateView*)player)->InternalFlags = 0;
        }
        return;
    }

    if (((CriMvPlyStateView*)player)->AudioManager)
        FUN_1400428e0(((CriMvPlyStateView*)player)->AudioManager, player);
    status = getInternalStatus(player);
    switch (status)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        FUN_140033810(player);
        break;
    case 5:
        FUN_1400344f0(player);
        break;
    }
}

// reset the demux and its output stream after the player update completes
// @0x140031990
CriBool FUN_140031990(void* player)
{
    void* demux;
    demux = ((CriMvPlyDemuxFields*)player)->Demux;
    if (FUN_140031aa0(player) != 1)
        return 0;
    FUN_140034330(player, ((CriMvPlyDemuxFields*)player)->InputBuffer, ((CriMvPlyDemuxFields*)player)->ReadBuffer,
                  ((CriMvPlyDemuxFields*)player)->HeaderBuffer);
    FUN_1400453c4(demux);
    FUN_140046798(((CriMvPlyDemuxFields*)player)->ReadBuffer);
    if (((CriMvPlyDemuxFields*)player)->ReadMode == 0)
        FUN_140044fa8(demux, ((CriMvPlyDemuxFields*)player)->HeaderBuffer);
    else
        FUN_140044fa8(demux, ((CriMvPlyDemuxFields*)player)->MemoryInput);
    FUN_140044fb0(demux, 0, ((CriMvPlyDemuxFields*)player)->ReadBuffer, 0, (CriUint32)-1);
    FUN_140044fd8(demux, 0);
    FUN_140044f9c(demux);
    FUN_1400458b8(demux);
    return 1;
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
        FUN_140046804(dataQueue, &dst);
        FUN_1400467a0(readBuffer, 1, -1, &chunk);
        if (chunk.Type > dst.Capacity)
            FUN_140037910(player, "E08120301M : Illigal data size of analize header against demux data line.", dst.Capacity);
        memcpy(dst.Data, chunk.Chunk, chunk.Type);
        written += chunk.Type;
        FUN_140046814(dataQueue, &dst, chunk.Type);
    }
    while ((CriUint32)FUN_1400467b8(source, 1) > 0)
    {
        FUN_140046804(dataQueue, &dst);
        FUN_1400467a0(source, 1, -1, &chunk);
        if (chunk.Type > dst.Capacity)
            FUN_140037910(player, "E08120302M : Illigal data size in read buffer data line of analize header.", dst.Capacity);
        memcpy(dst.Data, chunk.Chunk, chunk.Type);
        written += chunk.Type;
        FUN_140046814(dataQueue, &dst, chunk.Type);
        FUN_1400467b0(source, 0, &chunk);
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
    source = FUN_140037050(player, 0, 0);
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
                accepted = FUN_140036d50(player, (const CriMovieInputChunk*)&record);
                if (accepted == 0)
                {
                    FUN_1400467a8(sj, 1, &record);
                    return 0;
                }
                ++((CriMvSubtitleFrameCounter*)player)->Value;
            }
            FUN_1400467b0(sj, 0, &record);
            ++count;
        }
        else
        {
            FUN_140036f40(player, (CriMvSubtitleChunk*)&record, &item);
            if (channel != item.Channel)
            {
                FUN_1400467b0(sj, 0, &record);
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
