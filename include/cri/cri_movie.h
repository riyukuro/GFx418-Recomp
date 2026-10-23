// Recovered CRI Movie (Sofdec 2) PC x64 3.07.01 public interface, as far as the exe's code uses it (sfr lane: the
// middleware the Scaleform video player sits on). Written from the exe; names follow the exe's mangled symbols.
// The library itself was built with VS2008 SP1 (Rich header: Utc1500 build 30729), so our VS2017 rebuild of it can
// only be functional. Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_CRI_MOVIE_H
#define MS2_CRI_MOVIE_H

#include <stddef.h>

typedef signed char        CriSint8;
typedef unsigned char      CriUint8;
typedef signed short       CriSint16;
typedef unsigned short     CriUint16;
typedef signed long        CriSint32;
typedef unsigned long      CriUint32;
typedef signed __int64     CriSint64;
typedef unsigned __int64   CriUint64;
typedef float              CriFloat32;
typedef char               CriChar8;
typedef CriSint32          CriBool;

#define CRIAPI __cdecl

// Status of a call; every C++ entry point takes one by reference (default: CriMv::ErrorContainer).
typedef enum {
    CRIERR_OK                        = 0,
    CRIERR_NG                        = -1,
    CRIERR_INVALID_PARAMETER         = -2,
    CRIERR_FAILED_TO_ALLOCATE_MEMORY = -3,
    CRIERR_UNSAFE_FUNCTION_CALL      = -4,
    CRIERR_FUNCTION_NOT_IMPLEMENTED  = -5,
    CRIERR_LIBRARY_NOT_INITIALIZED   = -6,
    CRIERR_ENUM_BE_SINT32            = 0x7FFFFFFF
} CriError;

// Heap module (C interface, CRI Heap/PCx64 1.21.02, 0x140027048-0x140028360). A heap is a header followed by a
// doubly linked list of blocks inside the caller's work buffer; FIX blocks are cut from the front, TEMPORARY ones
// from the back. The library was compiled optimized and its structures are byte packed.
struct _criheap_struct;
typedef struct _criheap_struct* CriHeap;

// Decoder registration records are stored in CRI Movie's process-wide codec table (stride 0x18).
struct CriMvCodecRegistrationEntry
{
    CriSint32 CodecId;                 // 0x00
    CriUint32 Reserved;                // 0x04
    void*     VideoDecoderInterface;   // 0x08
    void*     AlphaDecoderInterface;   // 0x10
};
static_assert(sizeof(CriMvCodecRegistrationEntry) == 0x18, "CRI codec registration stride");

typedef enum {
    CRIHEAP_TYPE_NONE      = 0,
    CRIHEAP_TYPE_FIX       = 1,
    CRIHEAP_TYPE_TEMPORARY = 2,
    CRIHEAP_TYPE_DYNAMIC   = 3,
    CRIHEAP_TYPE_ENUM_BE_SINT32 = 0x7FFFFFFF
} CriHeapType;

#pragma pack(push, 1)
// Block header (0x22 bytes); the data follows after alignspc bytes, preceded by a dword holding its offset back to
// the header (alignspc + 0x26), and gap bytes of slack trail it.
typedef struct CriHeapBlockTag {
    struct CriHeapBlockTag* prevblock;  // 0x00
    struct CriHeapBlockTag* nextblock;  // 0x08
    CriSint32       memsize;            // 0x10
    CriUint8        used;               // 0x14
    CriUint8        type;               // 0x15 CriHeapType
    CriUint16       alignspc;           // 0x16
    CriUint16       gap;                // 0x18
    const CriChar8* nameadr;            // 0x1a
} CriHeapBlock;

typedef struct {
    void*     (*AllocFix)(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align);
    void*     (*AllocTemporary)(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align);
    void*     (*AllocDynamic)(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align);
    CriSint32 (*Free)(CriHeap heap, void* ptr);
} CriHeapVtbl;

struct _criheap_struct {                // 0x24
    const CriHeapVtbl* vtbl;            // 0x00 serialized (0x143a46430) or not (0x143a46450)
    CriSint32     totalsize;            // 0x08
    CriSint32     peaksize;             // 0x0c
    CriSint32     currentsize;          // 0x10
    CriHeapBlock* topblock;             // 0x14
    CriHeapBlock* taleblock;            // 0x1c
};
#pragma pack(pop)

extern "C" {
void      CRIAPI criHeap_Initialize(void);
void      CRIAPI criHeap_Finalize(void);
CriHeap   CRIAPI criHeap_Create(void* ptr, CriSint32 size);
CriHeap   CRIAPI criHeap_CreateNoSerialize(void* ptr, CriSint32 size);
void      CRIAPI criHeap_Destroy(CriHeap heap);
void*     CRIAPI criHeap_AllocFix(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align);
void*     CRIAPI criHeap_AllocTemporary(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align);
void*     CRIAPI criHeap_AllocDynamic(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align);
void*     CRIAPI criHeap_Alloc(CriHeap heap, CriSint32 size, const CriChar8* name, CriSint32 align, CriSint32 type);
CriSint32 CRIAPI criHeap_Free(CriHeap heap, void* ptr);
CriSint32 CRIAPI criHeap_EnterCriticalSection(void);
CriSint32 CRIAPI criHeap_LeaveCriticalSection(void);
CriSint32 CRIAPI criHeap_DebugGetWorstExtraSize(CriSint32 alignment);
void      CRIAPI criHeap_DebugPrintBlockInformationAll(CriHeap heap);
}

namespace CriMv {
    extern CriError ErrorContainer;

    void      CRIAPI Initialize(CriError& err = CriMv::ErrorContainer);
    void      CRIAPI InitializeFrame32bitARGB(void);
    void      CRIAPI Finalize(CriError& err = CriMv::ErrorContainer);
    CriUint32 CRIAPI CalcMovieHandleWork(CriUint32 max_num, CriError& err = CriMv::ErrorContainer);
    void      CRIAPI SetupMovieHandleWork(CriUint32 max_num, void* work, CriUint32 work_size,
                                          CriError& err = CriMv::ErrorContainer);
    void      CRIAPI InitializeMana(CriError& err = CriMv::ErrorContainer);       // 0x14003bea0
    void      CRIAPI AttachSofdecDecoder(CriError& err = CriMv::ErrorContainer);  // 0x140026f40
    CriUint32 CRIAPI GetMaxNumberOfHandles(CriError& err = CriMv::ErrorContainer); // 0x140027020
    void      CRIAPI Initialize_Common(void);                                   // 0x140024f80
    CriBool   CRIAPI IsLibraryInitialized(void);                                // 0x140024ff0
    CriSint32 CRIAPI CalcHandleWorkSize(CriError& err = CriMv::ErrorContainer); // 0x140025010
}

// ---- easy player layer (CriMvEasyPlayer, 0x14001d7a0-0x140025090). The library objects of this layer were built
// unoptimized (/Od: arguments spilled to their home slots, every member access reloads this).

// Bump allocator over a caller-supplied work buffer (0x14002e6b0 init, 0x14002e6c0 alloc, 0x14002e6bc finish).
struct CriMvWorkAllocator
{
    CriUint8* top;
    CriUint8* cur;
    CriUint32 size;
};

// Allocation base of the CRI C++ objects: they live in a CRI heap (criheap, 0x140027048-0x140028360).
class CriAllocator
{
public:
    static void* operator new(size_t size, CriHeap heap, CriHeapType type, const CriChar8* name, CriUint32 align);
    static void* operator new(size_t size, CriHeap heap);                                   // 0x14002e63c
    static void* operator new(size_t size, CriHeap heap, CriHeapType type);
    static void* operator new(size_t size, CriHeap heap, const CriChar8* name, CriUint32 align); // 0x14002e680
    static void  operator delete(void* ptr, size_t size);                                   // 0x14002e5b0
    static void  operator delete(void* ptr, CriHeap heap);
};

// Stack allocator used while assembling the CRI movie player's persistent work area (0x18 bytes).
struct CriFixedAllocator
{
    CriUint8* Begin;
    CriUint8* Current;
    CriUint32 Size;
};

// YUV plane description passed between the CRI movie and alpha decoders.
struct CriMvPlaneInfo
{
    CriUint64 Buffer;
    CriSint32 Stride;
    CriUint32 Height;
};

struct CriMvFramePlaneSource
{
    CriUint8 Reserved0[0x38];
    CriUint32 PlaneCount;
    CriUint32 Reserved1;
    struct PlaneSource
    {
        CriUint64 Buffer;
        CriUint32 Reserved;
        CriUint32 Width;
        CriUint32 Height;
        CriUint32 Reserved2;
    } Planes[3];
};

struct CriMvAlphaDecoderFrameInfo
{
    CriUint64 Buffer;
    CriSint32 PlaneIndex;
    CriUint32 Reserved;
    CriUint32 Stride;
    CriUint32 Height;
};

struct CriMvYuvBufferState
{
    CriUint8 Reserved[0x30];
    CriMvPlaneInfo Plane;
};

struct CriMvStateFlags
{
    CriUint8 Reserved[0xe58];
    CriUint32 Value0;
    CriUint32 Value1;
    CriUint32 Value2;
};

struct CriMvErrorState
{
    CriUint8 Reserved[0xf14];
    CriUint32 Error;
};

struct CriMvInputLockState
{
    CriUint8 Reserved[0xd98];
    CriSint32 Locked;
};

struct CriMvSupplyState
{
    CriUint8 Reserved0[0x0c];
    CriSint32 SupplyEnded;
    CriSint32 Terminated;
};

struct CriMvSupplyInputBuffer
{
    CriUint8 Reserved[0xd68];
    void* InputBuffer;
};

// CRI UTF runtime table views. Column entries are 0x30 bytes; the table stores big-endian record fields.
struct CriUtfRtvColumn
{
    CriSint32 Type;
    CriUint8 Reserved0[4];
    const CriChar8* Name;
    CriUint8 HasDefault;
    CriUint8 IsRecordField;
    CriUint16 DataOffset;
    CriUint8 Reserved1[4];
    CriUint64 DefaultValue[3];
};

struct CriUtfRtvView
{
    CriUint8 Reserved0[0x38];
    const CriUint8* StringData;
    const CriUint8* BlobData;
    const CriUint8* RecordData;
    CriUint16 FieldCount;
    CriUint16 RecordSize;
    CriUint32 RecordCount;
    CriUtfRtvColumn* Columns;
};

struct CriUtfRtvCell
{
    CriUint8 Type;
    CriUint8 Reserved[7];
    CriUint8 Value[16];
};

struct CriUsfStandardHeader
{
    CriUint8 Data[0x24];
};

struct CriMvSubAudioTrackState
{
    CriUint8 Reserved[0x8cc];
    CriSint32 TrackCount;
    CriUint8 Reserved2[4];
    CriSint32 TrackIds[64];
    CriSint32 TrackValues[64];
};

struct CriMpvDecoderState
{
    CriUint8 Reserved0[0x10];
    CriSint32 MotionVectors[4];
    CriUint8 Reserved1[0x15a0 - 0x20];
    CriSint32 MacroblockWidth;
    CriUint8 Reserved2[0x1794 - 0x15a4];
    CriSint32 MacroblockAddress;
    CriSint32 MacroblockRow;
    CriSint32 MacroblockColumn;
    CriUint8 Reserved3[0x17ac - 0x17a0];
    CriSint32 DcPredictors[3];
};

struct CriMvMetadataAllocatorFields
{
    CriUint8 Reserved[0xee8];
    void* Work;
    void* Allocate;
    void* Free;
};

struct CriMvHeapWorkState
{
    CriUint8 Reserved[0xee0];
    CriHeap Heap;
};

struct CriMvReadBufferState
{
    CriUint8 Reserved0[0xd60];
    CriSint32 Mode;
    CriUint8 Reserved1[0x14];
    void* ReadyBuffer;
    CriUint8 Reserved2[8];
    void* ReadBuffer;
    CriUint8 Reserved3[0x10];
    void* CurrentBuffer;
    CriUint8 Reserved4[8];
    CriSint32 CurrentOffset;
    CriUint8 Reserved5[0x14];
    CriUint32 DataAvailable;
    CriUint8 Reserved6[0x2c];
    CriUint32 ReadBufferSize;
    CriUint8 Reserved7[0x74];
    CriSint32 BufferMode;
    CriUint32 BufferSize;
    void* Buffer;
    CriUint8 Reserved8[0x60];
    CriUint32 AverageReadSize;
    CriUint8 Reserved9[0x3f0];
    CriFloat32 ReadRate;
};

struct CriMvDecoderHandleFields
{
    CriUint8 Reserved0[0xe08];
    void* VideoDecoder;
    CriUint8 Reserved1[0x30];
    void* AlphaDecoder;
};

struct CriMvEasyPlayerFrameFields
{
    CriUint8 Reserved0[8];
    void* PlayerHandle;                                           // 0x08
    CriUint8 Reserved10[0x348];
    CriUint8 AlphaFrameInfo[0x38];                                // 0x358
};
static_assert(offsetof(CriMvEasyPlayerFrameFields, PlayerHandle) == 0x08, "easy player handle offset");
static_assert(offsetof(CriMvEasyPlayerFrameFields, AlphaFrameInfo) == 0x358, "easy player alpha frame offset");

struct CriMvAlphaMovieDimensions
{
    CriUint8 Reserved[0xd44];
    CriUint32 Width;
    CriUint32 Height;
    CriUint8 Reserved2[8];
    CriUint32 DisplayWidth;
};

struct CriMvAlphaFrameSnapshot
{
    CriUint8 Reserved0[0x0c];
    CriUint32 Height;
    CriUint8 Reserved1[4];
    CriUint32 Width;
    CriUint8 Reserved2[0x1c];
    CriUint32 DisplayWidth;
};

struct CriMvSubAudioHandles
{
    CriUint8 Reserved[0xe10];
    void* Manager;
    CriUint8 Reserved2[8];
    void* Decoder;
};

struct CriMvSubtitleFields
{
    CriUint8 Reserved[0xe28];
    void* Queue;
    CriSint32 SubtitleIndex;
    CriSint32 SubtitleChannel;
};

struct CriMvSubtitleChunk
{
    const CriUint8* Data;
    CriUint32 Size;
    CriUint32 Reserved;
};

void      CRIAPI criFixedAllocator_Create(void* begin, CriUint32 size, CriFixedAllocator* allocator);
void*     CRIAPI criFixedAllocator_Allocate(CriFixedAllocator* allocator, CriUint32 size, CriUint32 align);

// Movie data source the player streams from (implemented by the Scaleform video reader).
class CriMvFileReaderInterface
{
public:
    enum AsyncStatus { ASYNC_STATUS_STOP, ASYNC_STATUS_BUSY, ASYNC_STATUS_COMPLETE, ASYNC_STATUS_ERROR,
                       ASYNC_STATUS_ENUM_BE_SINT32 = 0x7FFFFFFF };
    enum SeekOrigin  { SEEK_FROM_BEGIN, SEEK_FROM_CURRENT, SEEK_FROM_END, SEEK_ENUM_BE_SINT32 = 0x7FFFFFFF };

    virtual void        Open(CriChar8* fname) = 0;                                          // 0
    virtual void        Close(void) = 0;                                                    // 1
    virtual void        Read(CriUint8* buffer, CriSint64 req_size) = 0;                     // 2
    virtual AsyncStatus GetOpenStatus(void) = 0;                                            // 3
    virtual AsyncStatus GetCloseStatus(void) = 0;                                           // 4
    virtual AsyncStatus GetReadStatus(void) = 0;                                            // 5
    virtual CriSint64   GetReadSize(void) = 0;                                              // 6
    virtual CriSint64   Seek(CriSint64 size, SeekOrigin offset) = 0;                        // 7
    virtual CriSint64   GetFileSize(void) = 0;                                              // 8
    virtual ~CriMvFileReaderInterface() {}                                                  // 9
};

// PCM output the player feeds (implemented by the Scaleform video sound).
class CriMvSoundInterface
{
public:
    // The easy layer's order: 0 selects the float callback (the player core's own enum has SINT16 = 0).
    enum PcmFormat { PCM_FORMAT_FLOAT32, PCM_FORMAT_SINT16, PCM_FORMAT_ENUM_BE_SINT32 = 0x7FFFFFFF };
    enum Status    { STATUS_STOP, STATUS_EXEC, STATUS_ERROR, STATUS_ENUM_BE_SINT32 = 0x7FFFFFFF };

    typedef CriUint32 (*Float32PcmFunc)(void* obj, CriUint32 nch, CriFloat32* sample[], CriUint32 nsmpl);
    typedef CriUint32 (*Sint16PcmFunc)(void* obj, CriUint32 nch, CriSint16* sample[], CriUint32 nsmpl);

    virtual CriBool   CreateOutput(CriHeap heap, CriUint32 channel, CriUint32 samplerate) = 0;  // 0
    virtual void      DestroyOutput(void) = 0;                                              // 1
    virtual PcmFormat GetPcmFormat(void) = 0;                                               // 2
    virtual void      SetCallbackGetFloat32PcmData(Float32PcmFunc func, void* obj) = 0;     // 3
    virtual void      SetCallbackGetSint16PcmData(Sint16PcmFunc func, void* obj) = 0;       // 4
    virtual void      Start(void) = 0;                                                      // 5
    virtual void      Stop(void) = 0;                                                       // 6
    virtual Status    GetStatus(void) = 0;                                                  // 7
    virtual void      Pause(CriBool sw) = 0;                                                // 8
    virtual void      GetTime(CriUint64& count, CriUint64& unit) = 0;                       // 9
    virtual ~CriMvSoundInterface();                                                         // 10
};

// Clock the player syncs to when there is no audio.
class CriMvSystemTimerInterface
{
public:
    virtual void Start(void) = 0;                                                           // 0
    virtual void Stop(void) = 0;                                                            // 1
    virtual void Pause(CriBool sw) = 0;                                                     // 2
    virtual void GetTime(CriUint64& count, CriUint64& unit) = 0;                            // 3
    virtual ~CriMvSystemTimerInterface();                                                   // 4
};

#define CRIMV_MAX_VIDEO_NUM     1
#define CRIMV_MAX_AUDIO_NUM     32
#define CRIMV_MAX_ALPHA_NUM     1

struct CriMvVideoParameters                 // 0x30
{
    CriUint32 max_width;
    CriUint32 max_height;
    CriUint32 disp_width;
    CriUint32 disp_height;
    CriUint32 num_frame_pools;
    CriUint32 framerate;                    // frames per 1000 s
    CriUint32 total_frames;
    CriUint32 unk1c[5];
};

struct CriMvAudioParameters                 // 0x10
{
    CriUint32 sampling_rate;
    CriUint32 num_channel;
    CriUint32 total_samples;
    CriUint32 output_buffer_samples;
};

struct CriMvAlphaParameters                 // 0x1c
{
    CriUint32 max_width;
    CriUint32 max_height;
    CriUint32 disp_width;
    CriUint32 disp_height;
    CriUint32 framerate;
    CriUint32 total_frames;
    CriUint32 alpha_type;
};

// What the movie header says (GetMovieInfo) / what the player is configured with (SetStreamingParameters).
struct CriMvStreamingParameters             // 0x288
{
    CriBool              is_playable;                           // 0x000
    CriFloat32           buffering_time;                        // 0x004
    CriUint32            max_bitrate;                           // 0x008
    CriUint32            max_chunk_size;                        // 0x00c
    CriUint32            min_buffer_size;                       // 0x010
    CriUint32            read_buffer_size;                      // 0x014
    CriUint32            num_video;                             // 0x018
    CriMvVideoParameters video_prm[CRIMV_MAX_VIDEO_NUM];        // 0x01c
    CriUint32            num_audio;                             // 0x04c
    CriSint32            track_play_audio;                      // 0x050
    CriMvAudioParameters audio_prm[CRIMV_MAX_AUDIO_NUM];        // 0x054
    CriUint32            num_subtitle;                          // 0x254
    CriSint32            channel_play_subtitle;                 // 0x258
    CriUint32            max_subtitle_size;                     // 0x25c
    CriUint32            num_alpha;                             // 0x260
    CriMvAlphaParameters alpha_prm[CRIMV_MAX_ALPHA_NUM];        // 0x264
    CriBool              seekinfo_flag;                         // 0x280
    CriUint32            format_ver;                            // 0x284
};

struct CriMvInputBufferInfo
{
    CriUint32 buffer_size;
    CriUint32 data_size;
    CriUint32 reload_threshold;
};

// One cue point of the movie.
struct CriMvEventPoint                      // 0x38
{
    CriChar8*            cue_name;          // 0x00
    CriUint32            size_name;         // 0x08
    CriUint64            time;              // 0x10
    CriUint64            tunit;             // 0x18
    CriSint32            type;              // 0x20
    CriChar8*            param_string;      // 0x28
    CriUint32            size_param;        // 0x30
    CriUint32            cnt_callback;      // 0x34 times the cue callback fired for it
};

// One plane of a decoded frame.
struct CriMvImageBufferInfo                 // 0x18
{
    CriUint8* imageptr;
    CriUint32 bufsize;
    CriUint32 line_pitch;
    CriUint32 line_size;
    CriUint32 num_lines;
};

// A decoded frame as the player core describes it.
struct CriMvFrameInfo                       // 0xc8
{
    CriUint8*            imageptr;          // 0x00
    CriSint32            frame_id;          // 0x08
    CriUint32            width;             // 0x0c
    CriUint32            height;            // 0x10
    CriUint32            pitch;             // 0x14
    CriUint32            disp_width;        // 0x18
    CriUint32            disp_height;       // 0x1c
    CriUint32            framerate;         // 0x20 frames per 1000 s
    CriUint32            framerate_n;       // 0x24
    CriUint32            framerate_d;       // 0x28
    CriUint64            time;              // 0x30
    CriUint64            tunit;             // 0x38
    CriUint32            cnt_concatenated_movie; // 0x40
    CriSint32            frame_id_per_data; // 0x44
    CriBool              csc_flag;          // 0x48
    CriSint32            alpha_type;        // 0x4c
    CriSint32            num_images;        // 0x50
    CriMvImageBufferInfo image_info[4];     // 0x58
    CriUint32            color_conversion_type; // 0xb8
    CriUint32            total_frames_per_data; // 0xbc
    CriUint32            cnt_skipped_frames;    // 0xc0
};

// A piece of the player core's input buffer (GetInputChunk / PutInputChunk).
struct CriChunk
{
    CriUint8*            data;
    CriUint32            size;
};

// One subtitle as the player core hands it out (times in time_unit ticks).
struct CriMvSubtitleInfo                    // 0x38
{
    CriUint8*            dataptr;           // 0x00
    CriUint32            data_size;         // 0x08
    CriSint32            channel_no;        // 0x0c
    CriUint64            time_unit;         // 0x10
    CriUint64            in_time;           // 0x18
    CriUint64            duration_time;     // 0x20
    CriUint32            cnt_concatenated_movie; // 0x28
    CriUint64            in_time_per_data;  // 0x30
};

enum CriMvMetaFlag { CRIMV_META_FLAG_NONE = 0, CRIMV_META_FLAG_CUE = 1, CRIMV_META_FLAG_SEEK = 2,
                     CRIMV_META_FLAG_ALL = 3, CRIMV_META_FLAG_ENUM_BE_SINT32 = 0x7FFFFFFF };

// Cue points of the movie (the player handle's copy, +0xeb8).
struct CriMvCuePointInfo
{
    CriUint32        num_eventpoint;
    CriMvEventPoint* eventtable;
};

// The memory "file" reader the easy player uses for SetData (sfr_cri_02).
class CriMvEasyFileReaderMem : public CriMvFileReaderInterface
{
public:
    static CriMvEasyFileReaderMem* Create(CriHeap heap);                                    // 0x1400385d0
    void Open(CriChar8* fname) override;                                                    // 0x140038720
    void Close(void) override;                                                              // 0x1400387b0
    void Read(CriUint8* buffer, CriSint64 req_size) override;                               // 0x140038810
    AsyncStatus GetOpenStatus(void) override;                                               // 0x1400388d0
    AsyncStatus GetCloseStatus(void) override;                                              // 0x140038910
    AsyncStatus GetReadStatus(void) override;                                               // 0x1400388f0
    CriSint64 GetReadSize(void) override;                                                   // 0x140038930
    CriSint64 Seek(CriSint64 size, SeekOrigin offset) override;                             // 0x140038950
    CriSint64 GetFileSize(void) override;                                                   // 0x1400389d0
    ~CriMvEasyFileReaderMem() override;                                                     // 0x140038c80
    virtual void Destroy(void);                                                             // 10, 0x1400386c0
private:
    CriUint8* Data;                                                                         // 0x08
    CriSint64 FileSize;                                                                     // 0x10
    CriHeap Heap;                                                                           // 0x18
    CriSint64 Position;                                                                     // 0x20
    CriUint64 ReadSize;                                                                     // 0x28
    AsyncStatus OpenState;                                                                  // 0x30
    AsyncStatus CloseState;                                                                 // 0x34
    AsyncStatus ReadState;                                                                  // 0x38
};

// The player handle the easy player drives (criMvPly, sfr_cri_02); only the members this layer touches.
struct CriMvPlyObj
{
    CriUint8          unk000[0x5f0];
    CriUint32         num_audio_out;                            // 0x5f0
    CriUint8          unk5f4[0x61c - 0x5f4];
    CriUint32         framerate;                                // 0x61c
    CriSint32         total_frames;                             // 0x620
    CriUint8          unk624[0x630 - 0x624];
    CriSint32         seek_mode;                                // 0x630
    CriUint32         unk634;
    CriSint32         seekinfo_flag;                            // 0x638
    CriUint8          unk63c[0xda0 - 0x63c];
    void*             unkda0;                                   // 0xda0 memory input support
    CriUint8          unkda8[0xdd0 - 0xda8];
    void*             utf_heap;                                 // 0xdd0
    CriUint8          unkdd8[0xe88 - 0xdd8];
    void*             seektbl;                                  // 0xe88
    CriUint32         num_seektbl;                              // 0xe90
    void*             seektbl_alpha;                            // 0xe98
    CriUint32         num_seektbl_alpha;                        // 0xea0
    CriUint8          unkea4[0xeb8 - 0xea4];
    CriMvCuePointInfo cuepoint;                                 // 0xeb8
    CriMvInputBufferInfo ibuf_info;                             // 0xec8
    CriFloat32        reload_threshold;                         // 0xed4
    CriSint32         unked8;                                   // 0xed8
    CriUint8          unkedc[0xf14 - 0xedc];
    CriBool           decoder_error;                            // 0xf14
};
typedef CriMvPlyObj* CriMvPly;

// CRI Movie's state machine reads these fields directly from the start of CriMvPly.
struct CriMvPlyStateTransitionFields
{
    CriUint8  Reserved0[4];
    CriSint32 Status;                                             // 0x04
    CriUint32 InternalFlags;                                      // 0x08
    CriUint8  Reserved0C[0xad4 - 0x0c];
    CriSint32 StartReady;                                          // 0xad4
    CriUint8  ReservedAD8[0xd68 - 0xad8];
    void*     Demux;                                               // 0xd68
    CriUint8  ReservedD70[0xe30 - 0xd70];
    CriSint32 LastFrame;                                           // 0xe30
    CriUint8  ReservedE34[0xf10 - 0xe34];
    CriUint8  StopState;                                           // 0xf10
};
static_assert(offsetof(CriMvPlyStateTransitionFields, StartReady) == 0xad4, "CriMvPly start-ready offset");
static_assert(offsetof(CriMvPlyStateTransitionFields, Demux) == 0xd68, "CriMvPly demux offset");
static_assert(offsetof(CriMvPlyStateTransitionFields, LastFrame) == 0xe30, "CriMvPly frame offset");
static_assert(offsetof(CriMvPlyStateTransitionFields, StopState) == 0xf10, "CriMvPly stop-state offset");

struct CriMvPlyHeaderAnalysisFields
{
    CriUint8  Reserved0[0x28];
    CriUint8  CurrentHeader[0x2c0];                               // 0x28
    CriUint8  Reserved2E8[0x18];
    CriUint64 HeaderParameter;                                    // 0x300
    CriUint8  Reserved308[0x2f0];
    CriUint8  AnalyzedHeader[0x2c0];                              // 0x5f8
};
static_assert(offsetof(CriMvPlyHeaderAnalysisFields, HeaderParameter) == 0x300, "movie header parameter offset");
static_assert(offsetof(CriMvPlyHeaderAnalysisFields, AnalyzedHeader) == 0x5f8, "analyzed header offset");

// The "easy player": file/memory input, decoding, sync and sound on top of one player handle. 0x728 bytes.
struct CriMvYuvBuffers;
struct CriMvAlphaFrameInfo;

class CriMvEasyPlayer : public CriAllocator
{
public:
    enum Status { MVEASY_STATUS_STOP, MVEASY_STATUS_DECHDR, MVEASY_STATUS_WAIT_PREP, MVEASY_STATUS_PREP,
                  MVEASY_STATUS_READY, MVEASY_STATUS_PLAYING, MVEASY_STATUS_PLAYEND, MVEASY_STATUS_ERROR,
                  MVEASY_STATUS_ENUM_BE_SINT32 = 0x7FFFFFFF };
    enum TimerType { MVEASY_TIMER_NONE, MVEASY_TIMER_SYSTEM, MVEASY_TIMER_AUDIO, MVEASY_TIMER_USER,
                     MVEASY_TIMER_ENUM_BE_SINT32 = 0x7FFFFFFF };

    static CriMvEasyPlayer* Create(void* work, CriUint32 work_size, CriMvFileReaderInterface* freader,
                                   CriMvSystemTimerInterface* stimer, CriMvSoundInterface* sound,
                                   CriError& err = CriMv::ErrorContainer);                      // 0x14001d7a0
    CriSint32 CalcPlaybackWorkSize(const CriMvStreamingParameters* stmprm,
                                   CriError& err = CriMv::ErrorContainer);                      // 0x14001dba0
    void      SetPlaybackWork(void* work, CriUint32 work_size, CriError& err = CriMv::ErrorContainer); // 0x14001dd80
    static CriMvEasyPlayer* Create(CriHeap heap, CriMvFileReaderInterface* freader,
                                   CriMvSystemTimerInterface* stimer, CriMvSoundInterface* sound,
                                   CriError& err = CriMv::ErrorContainer);                      // 0x14001de20
    void      Destroy(CriError& err = CriMv::ErrorContainer);                                   // 0x14001e720
    Status    GetStatus(CriError& err = CriMv::ErrorContainer);                                 // 0x14001e940
    void      ResetAllParameters(CriError& err = CriMv::ErrorContainer);                        // 0x14001e160
    void      Update(CriError& err = CriMv::ErrorContainer);                                    // 0x14001f8b0
    void      SetFile(CriChar8* fname, CriError& err = CriMv::ErrorContainer);                  // 0x140021530
    void      SetData(CriUint8* dataptr, CriUint32 datasize, CriError& err = CriMv::ErrorContainer); // 0x140021580
    void      SetFileRange(CriChar8* fname, CriUint64 offset, CriSint64 range,
                           CriError& err = CriMv::ErrorContainer);                              // 0x140021720
    void      SetPreviousDataAgain(CriError& err = CriMv::ErrorContainer);                      // 0x140021850
    void      DecodeHeader(CriError& err = CriMv::ErrorContainer);                              // 0x1400218d0
    void      Prepare(CriError& err = CriMv::ErrorContainer);                                   // 0x140021930
    void      Start(CriError& err = CriMv::ErrorContainer);                                     // 0x1400219b0
    void      Stop(CriError& err = CriMv::ErrorContainer);                                      // 0x140021bf0
    void      Pause(CriBool sw, CriError& err = CriMv::ErrorContainer);                         // 0x140021c90
    CriBool   IsPaused(CriError& err = CriMv::ErrorContainer);                                  // 0x140021d70
    void      SetMasterTimer(TimerType type, CriError& err = CriMv::ErrorContainer);            // 0x140021da0
    TimerType GetMasterTimer(CriError& err = CriMv::ErrorContainer);                            // 0x140021dd0
    void      SetNumberOfFramePools(CriUint32 npools, CriError& err = CriMv::ErrorContainer);   // 0x140021ef0
    void      SetBufferingTime(CriFloat32 sec, CriError& err = CriMv::ErrorContainer);          // 0x140021f20
    void      SetReloadThresholdTime(CriFloat32 sec, CriError& err = CriMv::ErrorContainer);    // 0x140021f60
    void      GetTime(CriUint64& count, CriUint64& unit, CriError& err = CriMv::ErrorContainer); // 0x140022190
    void      GetInputBufferInfo(CriMvInputBufferInfo& ibuf_info,
                                 CriError& err = CriMv::ErrorContainer);                        // 0x140021fa0
    void      SetMaxBitrate(CriUint32 max_bitrate, CriError& err = CriMv::ErrorContainer);     // 0x140022010
    void      SetMaxChunkSize(CriUint32 max_chunk_size, CriError& err = CriMv::ErrorContainer); // 0x140022040
    void      SetMinBufferSize(CriUint32 min_buffer_size, CriError& err = CriMv::ErrorContainer); // 0x140022070
    void      SetReadBufferSize(CriSint32 size, CriError& err = CriMv::ErrorContainer);        // 0x1400220a0
    void      SetAudioTrack(CriSint32 track, CriError& err = CriMv::ErrorContainer);            // 0x1400220d0
    void      SetLoopFlag(CriBool flag, CriError& err = CriMv::ErrorContainer);                 // 0x140022130
    CriBool   GetLoopFlag(CriError& err = CriMv::ErrorContainer);                               // 0x140022160
    CriBool   GetHeaderInfo(CriMvStreamingParameters* stmprm, CriError& err = CriMv::ErrorContainer); // 0x140022310
    CriBool   GetMovieInfo(CriMvStreamingParameters& stmprm, CriError& err = CriMv::ErrorContainer); // 0x140022420
    CriUint32 GetSubtitleOnTime(CriUint8* bufptr, CriUint32 bufsize, CriError& err = CriMv::ErrorContainer); // 0x140022610
    void      SetStreamingParameters(CriMvStreamingParameters* stmprm,
                                     CriError& err = CriMv::ErrorContainer);                    // 0x140022540
    void      SetSubtitleChannel(CriSint32 channel, CriError& err = CriMv::ErrorContainer);     // 0x1400225b0
    void      ReplaceCenterVoice(CriSint32 track, CriError& err = CriMv::ErrorContainer);       // 0x1400238f0
    void      AttachSubAudioInterface(CriMvSoundInterface* sound, CriError& err = CriMv::ErrorContainer); // 0x140023b10
    void      DetachSubAudioInterface(CriError& err = CriMv::ErrorContainer);                   // 0x140023bf0
    void      SetSubAudioTrack(CriSint32 track, CriError& err = CriMv::ErrorContainer);         // 0x140023c20
    CriSint32 GetSubAudioTrack(CriError& err = CriMv::ErrorContainer);                          // 0x140023c50
    void      SetFileRequestCallback(void (*func)(CriMvEasyPlayer* mveasy, void* usrobj),
                                     void* usrobj, CriError& err = CriMv::ErrorContainer);      // 0x140023dc0
    void      SetSeekPosition(CriSint32 frame_id, CriError& err = CriMv::ErrorContainer);       // 0x140023e10
    void      SetSeekFrameAndOffset(CriSint32 frame_id, CriUint64 offset,
                                    CriError& err = CriMv::ErrorContainer);                     // 0x140023e50
    void      GetPlaybackInfo(void* info, CriError& err = CriMv::ErrorContainer);               // 0x140023ea0
    CriSint32 GetLastFrameResult(CriError& err = CriMv::ErrorContainer);                        // 0x140023ef0
    void      SetNumberOfFramesForPrep(CriUint32 nframes, CriError& err = CriMv::ErrorContainer); // 0x140023f20
    CriSint32 CalcFrameIdFromTime(CriUint64 count, CriUint64 unit, CriError& err = CriMv::ErrorContainer); // 0x140023f70
    CriUint64 CalcTimeFromFrameId(CriSint32 frame_id, CriUint64 unit,
                                  CriError& err = CriMv::ErrorContainer);                       // 0x140024040
    CriSint32 SearchNextEventPointByTime(CriUint64 count, CriUint64 unit, CriSint32 type, CriMvEventPoint* eventinfo,
                                         CriError& err = CriMv::ErrorContainer);                // 0x140024120
    CriSint32 SearchPrevEventPointByTime(CriUint64 count, CriUint64 unit, CriSint32 type, CriMvEventPoint* eventinfo,
                                         CriError& err = CriMv::ErrorContainer);                // 0x140024360
    CriMvCuePointInfo* GetCuePointInfo(CriError& err = CriMv::ErrorContainer);                  // 0x1400245b0
    void      SetCuePointCallback(void (*func)(CriMvEasyPlayer* mveasy, CriMvEventPoint* eventinfo, void* usrobj), void* usrobj,
                                  CriError& err = CriMv::ErrorContainer);                       // 0x140024610
    void      SetStopCompleteCallback(void (*func)(CriMvEasyPlayer* mveasy, void* usrobj), void* usrobj,
                                      CriError& err = CriMv::ErrorContainer);                   // 0x140024bf0
    void      SetUsableProcessors_PC(int num_threads, const unsigned long* affinity_masks, int priority,
                                     CriError& err = CriMv::ErrorContainer);                    // 0x140024c40
    void      SetMemoryPlaybackType(CriSint32 type, CriError& err = CriMv::ErrorContainer);     // 0x140024ee0
    void      DeferFileRequest(CriError& err = CriMv::ErrorContainer);                          // 0x140024f10
    void      SetMetaDataWorkAllocator(void* (*allocfunc)(void* obj, CriUint32 size),
                                       void (*freefunc)(void* obj, void* mem), void* obj,
                                       CriMvMetaFlag meta_flag);                                // 0x14001ddd0
    void      SetCompareFrameTimeCallback(CriSint32 (*func)(CriMvEasyPlayer* mveasy, CriMvFrameInfo* frameinfo,
                                                            CriUint64 count, CriUint64 unit, void* usrobj),
                                          void* usrobj, CriError& err = CriMv::ErrorContainer); // 0x140039750
    CriSint32 IsNextFrameOnTime(CriError& err = CriMv::ErrorContainer);                           // 0x140038f60
    CriSint32 UnlockFrameBufferWithAlpha(const CriMvFrameInfo* frameinfo,
                                         const CriMvAlphaFrameInfo* alphainfo,
                                         CriError& err = CriMv::ErrorContainer);                  // 0x140039d80

    CriBool   GetFrameOnTimeAs32bitARGB(CriUint8* imagebuf, CriUint32 pitch, CriUint32 bufsize,
                                        CriMvFrameInfo& frameinfo,
                                        CriError& err = CriMv::ErrorContainer);                 // 0x140026dd0
    CriSint32 CopyFrameToBufferARGB32(CriUint8* dstbuf, CriUint32 dstpitch, CriUint32 dstbufsize,
                                      const CriMvYuvBuffers* srcbufs, const CriMvFrameInfo* src_vinf,
                                      const CriMvAlphaFrameInfo* src_ainf,
                                      CriError& err = CriMv::ErrorContainer);                   // 0x140026e60
    void      SyncMasterTimer(CriError& err = CriMv::ErrorContainer);                             // 0x140021000
    CriBool   ExecuteDecode(CriError& err = CriMv::ErrorContainer);                               // 0x140021450
protected:
    CriMvEasyPlayer();                                                                          // 0x140024e80
    virtual ~CriMvEasyPlayer();                                                                 // 0x140024ea0

private:
    void      resetHandleParameters(void);                                                      // 0x14001e500
    void      initializeCompareFrameParameters(void);                                           // 0x14001e680
    void      resetPlayback(void);                                                              // 0x14001e1c0
    void      executeUpdate(CriError& err);                                                     // 0x14001f920
    CriUint32 adjustNumTrackAudioOut(void);                                                     // 0x140020790
    void      startModules(void);                                                               // 0x1400207f0
    void      requestStopModules(void);                                                         // 0x1400208c0
    void      updateStatus(CriError& err);                                                      // 0x14001fb00
    void      setupSeekPosition(void);                                                          // 0x14001fdc0
    CriBool   setupPlayback(void);                                                              // 0x140020140
    CriBool   isFileReaderIdle(void);                                                           // 0x1400209a0
    CriBool   detachOutputs(void);                                                              // 0x140020ae0
    void      completeStop(CriSint32 ply_status);                                               // 0x140020db0
    void      releasePlaybackResources(void);                                                   // 0x140020eb0
    void      calcAudioTime(CriUint64* count, CriUint64* unit, CriUint64 sys_count, CriUint64 sys_unit); // 0x1400211d0
    CriBool   startInputAndDecoding(void);                                                      // 0x140021a30
    void      supplyDataFromStreamer(void);                                                       // 0x140022d00
    void      executeFileReadServer(void);                                                      // 0x140022f20
    void      reinputDataForLooping(void);                                                          // 0x1400230a0
    void      surveilTerminationInput(void);                                                   // 0x1400231d0
    CriBool   isEndReadFile(void);                                                              // 0x140023330
    void      executeFileCloseServer(void);                                                     // 0x1400233c0
    void      executeFileOpenServer(void);                                                      // 0x1400235a0
    void      executeCuePointServer(void);                                                      // 0x140024660
    CriBool   isAvailableCenterVoice(const CriMvStreamingParameters* stmprm);                   // 0x140023940
    CriBool   isAvailableSubAudio(const CriMvStreamingParameters* stmprm);                      // 0x1400239e0
    CriBool   attachCenterVoice(void);                                                          // 0x140023a70
    void      detachCenterVoice(void);                                                          // 0x140023ad0
    CriBool   attachSubAudioHandle(CriHeap heap);                                               // 0x140023d20
    void      detachSubAudioHandle(void);                                                       // 0x140023d80
    void      setNormalErrorStatus(const CriChar8* msg);                                        // 0x140024d00
    void      setErrorMessage(const CriChar8* msg, const CriChar8* detail);                     // 0x140024de0
    void      notifyErrorA(void* obj, const CriChar8* msg, CriSint32 p1);                       // 0x140024d40
    void      notifyErrorB(void* obj, const CriChar8* msg, CriSint32 p1);                       // 0x140024d90
    static CriUint32 crimveasy_SupplyPcmDataByFloat32(void* obj, CriUint32 nch, CriFloat32* sample[],
                                                      CriUint32 nsmpl);                         // 0x14001ea50
    static CriUint32 crimveasy_SupplyPcmDataBySint16(void* obj, CriUint32 nch, CriSint16* sample[],
                                                     CriUint32 nsmpl);                          // 0x14001eb20
    static CriUint32 crimveasy_CalcAvailableNumSmpls(CriMvEasyPlayer* mveasy);                  // 0x14001ebe0
    static CriUint32 crimveasy_GetWave16(CriMvEasyPlayer* mveasy, CriUint32 nch, CriSint16* sample[],
                                         CriUint32 nsmpl);                                      // 0x14001ecc0
    static CriUint32 crimveasy_GetWave32(CriMvEasyPlayer* mveasy, CriUint32 nch, CriFloat32* sample[],
                                         CriUint32 nsmpl);                                      // 0x14001f060
    static CriUint32 crimveasy_SupplySubAudioDataByFloat32(void* obj, CriUint32 nch, CriFloat32* sample[],
                                                           CriUint32 nsmpl);                    // 0x14001f400
    static CriUint32 crimveasy_GetSubAudioWave32(CriMvEasyPlayer* mveasy, CriUint32 nch, CriFloat32* sample[],
                                                 CriUint32 nsmpl);                              // 0x14001f4b0
    static CriUint32 crimveasy_SupplySubAudioDataBySint16(void* obj, CriUint32 nch, CriSint16* sample[],
                                                          CriUint32 nsmpl);                     // 0x14001f660
    static CriUint32 crimveasy_GetSubAudioWave16(CriMvEasyPlayer* mveasy, CriUint32 nch, CriSint16* sample[],
                                                 CriUint32 nsmpl);                              // 0x14001f700
    CriSint32 isNextFrameOnTime(CriSint32 frame_id, CriError& err);                            // 0x140039180
    static CriSint32 compareFrameTimeFluctuation(CriMvEasyPlayer* mveasy, CriMvFrameInfo* frameinfo,
                                                 CriUint64 count, CriUint64 unit, void* usrobj); // 0x1400398a0

public:
    CriMvPly                   mvply;                           // 0x008
    CriHeap                    heap;                            // 0x010 (the caller's heap; NULL when created on a work buffer)
    CriBool                    stmprm_flag;                     // 0x018
    CriMvStreamingParameters   stmprm;                          // 0x01c
    CriUint32                  unk2a4;
    CriMvFrameInfo             frame_info;                      // 0x2a8 last frame handed out
    CriUint8                   unk370[0x390 - 0x370];
    CriMvFileReaderInterface*  freader;                         // 0x390
    CriMvSoundInterface*       sound;                           // 0x398
    CriMvSystemTimerInterface* stimer;                          // 0x3a0
    TimerType                  timer_type;                      // 0x3a8
    Status                     status_after_stop;               // 0x3ac
    CriBool                    req_decode_header;               // 0x3b0
    CriBool                    req_prepare;                     // 0x3b4
    CriBool                    pause_flag;                      // 0x3b8
    CriUint32                  num_frame_pools;                 // 0x3bc
    CriSint32                  audio_track;                     // 0x3c0
    CriUint32                  num_audio_channel;               // 0x3c4
    CriUint32                  unk3c8;                          // 0x3c8
    CriBool                    loop_flag;                       // 0x3cc
    CriUint64                  user_time_count;                 // 0x3d0
    CriUint64                  user_time_unit;                  // 0x3d8
    CriSint64                  file_read_pos;                   // 0x3e0
    CriSint64                  file_read_end;                   // 0x3e8
    CriChunk                   readck;                          // 0x3f0 input chunk the file reader fills
    CriBool                    file_opened;                     // 0x400
    CriBool                    file_closing;                    // 0x404
    CriBool                    file_reading;                    // 0x408
    CriUint32                  unk40c;
    CriUint64                  time0_count;                     // 0x410
    CriUint64                  time0_unit;                      // 0x418
    CriUint64                  time1_count;                     // 0x420
    CriUint64                  time1_unit;                      // 0x428
    CriUint64                  time2_count;                     // 0x430
    CriUint64                  time2_unit;                      // 0x438
    CriFloat32                 buffering_time;                  // 0x440
    CriUint32                  max_bitrate;                     // 0x444
    CriUint32                  max_chunk_size;                  // 0x448
    CriUint32                  min_buffer_size;                 // 0x44c
    CriSint32                  read_buffer_size;                // 0x450 (-1: as the header says)
    CriSint32                  subtitle_channel;                // 0x454
    CriMvSubtitleInfo          subtitle_info;                   // 0x458 subtitle currently shown
    CriFloat32                 subtitle_start_ms;               // 0x490
    CriFloat32                 subtitle_end_ms;                 // 0x494
    CriUint8*                  subtitle_buf;                    // 0x498
    CriBool                    unk4a0;                          // 0x4a0
    CriUint8                   unk4a4[4];
    CriMvFileReaderInterface*  freader_file;                    // 0x4a8
    class CriMvEasyFileReaderMem* freader_mem;                  // 0x4b0
    CriSint32                  memory_playback_type;            // 0x4b8
    CriSint32                  data_type;                       // 0x4bc (0 none, 1 file, 2 memory)
    CriUint32                  unk4c0;                          // 0x4c0
    CriUint32                  unk4c4;                          // 0x4c4
    CriChar8                   fname[0x100];                    // 0x4c8
    CriUint64                  file_offset;                     // 0x5c8
    CriSint64                  file_range;                      // 0x5d0
    CriUint8*                  data_ptr;                        // 0x5d8
    CriUint32                  data_size;                       // 0x5e0
    CriUint32                  unk5e4;                          // 0x5e4
    CriUint32                  unk5e8;                          // 0x5e8
    CriSint32                  file_request_state;              // 0x5ec
    CriUint32                  center_channel;                  // 0x5f0
    CriSint32                  center_voice_track;              // 0x5f4
    CriSint32                  attached_center_voice_track;     // 0x5f8
    CriUint8                   unk5fc[4];
    CriMvSoundInterface*       subaudio;                        // 0x600
    CriSint32                  subaudio_track;                  // 0x608
    CriSint32                  attached_subaudio_track;         // 0x60c
    void                     (*filereq_func)(CriMvEasyPlayer* mveasy, void* usrobj);     // 0x610
    void*                      filereq_usrobj;                  // 0x618
    CriUint8                   unk620[0x630 - 0x620];
    CriSint32                  seek_frame_id;                   // 0x630
    CriUint64                  seek_offset;                     // 0x638
    void                     (*cuepoint_func)(CriMvEasyPlayer* mveasy, CriMvEventPoint* eventinfo, void* usrobj); // 0x640
    void*                      cuepoint_usrobj;                 // 0x648
    CriUint32                  unk650;                          // 0x650
    CriUint64                  unk658;                          // 0x658
    CriFloat32                 unk660;                          // 0x660
    CriUint8                   unk664[4];
    CriUint8                   playback_info[0x40];             // 0x668
    CriSint32                  last_frame_result;               // 0x6a8
    CriSint32                  destroy_lock;                    // 0x6ac
    CriSint32                  update_lock;                     // 0x6b0
    CriUint8                   unk6b4[4];
    void                     (*stopcmpl_func)(CriMvEasyPlayer* mveasy, void* usrobj); // 0x6b8
    void*                      stopcmpl_usrobj;                 // 0x6c0
    void*                      playback_work;                   // 0x6c8
    CriUint32                  playback_work_size;              // 0x6d0
    CriUint8                   unk6d4[4];
    void*                      mvply_work;                      // 0x6d8
    CriHeap                    work_heap;                       // 0x6e0 (the heap built on the caller's work buffer)
    CriHeap                    sound_heap;                      // 0x6e8
    CriUint8                   unk6f0;                          // 0x6f0
    CriUint8                   unk6f1[7];
    void*                      cs;                              // 0x6f8
    void*                      cs_work;                         // 0x700
    CriUint32                  compare_frame_count;             // 0x708
    CriFloat32                 compare_frame_prm0;              // 0x70c
    CriFloat32                 compare_frame_prm1;              // 0x710
    CriFloat32                 compare_frame_prm2;              // 0x714
    CriFloat32                 compare_frame_prm3;              // 0x718
    CriBool                    modules_stopped;                 // 0x71c
    CriBool                    error_flag;                      // 0x720
    CriUint32                  unk724;                          // 0x724
};

#endif
