// Recovered Scaleform GFx 4.1.18 AMP: per-frame profile data (GFx/AMP/Amp_ProfileFrame.h).
// The members live in sfr_as3_22 (0x142685f00-0x142690c70). Layouts are checked against the exe offsets below.
#ifndef MS2_SF_GFX_AMP_PROFILEFRAME_H
#define MS2_SF_GFX_AMP_PROFILEFRAME_H

#include "ms2/scaleform/include/kernel/sf_refcount.h"
#include "ms2/scaleform/include/kernel/sf_array.h"
#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/include/kernel/sf_hash.h"
#include "ms2/scaleform/include/kernel/sf_file.h"
#include "ms2/scaleform/kernel/sf_memitem.h"

namespace Scaleform {
class Log;
namespace GFx {
namespace AMP {

enum StatAmp
{
    StatAmp_Default = StatGroup_GFxAmp,
    StatAmp_Mem,
    StatAmp_ProfileFrame,
    StatAmp_Server
};

// ActionScript per-instruction timings of each script buffer.
struct MovieInstructionStats : public RefCountBase<MovieInstructionStats, StatAmp_ProfileFrame>
{
    struct InstructionTimePair
    {
        UInt32 Offset;
        UInt64 Time;
    };

    struct ScriptBufferStats : RefCountBase<ScriptBufferStats, StatAmp_ProfileFrame>
    {
        UInt32                       SwdHandle;
        UInt32                       BufferOffset;
        UInt32                       BufferLength;
        ArrayLH<InstructionTimePair> InstructionTimesArray;

        void Read(File& str, UInt32 version);
        void Write(File& str, UInt32 version) const;
    };

    ArrayLH<Ptr<ScriptBufferStats> > BufferStatsArray;

    MovieInstructionStats& operator/=(unsigned numFrames);
    MovieInstructionStats& operator*=(unsigned num);
    void Merge(const MovieInstructionStats& other);

    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
};
static_assert(sizeof(MovieInstructionStats::InstructionTimePair) == 0x10, "InstructionTimePair");
static_assert(offsetof(MovieInstructionStats::ScriptBufferStats, InstructionTimesArray) == 0x20, "ScriptBufferStats");
static_assert(offsetof(MovieInstructionStats, BufferStatsArray) == 0x10, "MovieInstructionStats");

// Function descriptions of the profiled movies, keyed by SWF handle and offset.
struct FunctionDesc : public RefCountBase<FunctionDesc, StatAmp_ProfileFrame>
{
    StringLH Name;
    unsigned Length;
    UInt64   FileId;
    UInt32   FileLine;
    UInt32   ASVersion;
};
typedef HashLH<UInt64, Ptr<FunctionDesc> > FunctionDescMap;
typedef HashLH<UInt64, String>              SourceFileDescMap;

// Call tree of the profiled functions.
class FuncTreeItem : public RefCountBase<FuncTreeItem, Stat_Default_Mem>
{
public:
    UInt64                      FunctionId;
    UInt64                      BeginTime;
    UInt64                      EndTime;
    UInt32                      TreeItemId;
    ArrayLH<Ptr<FuncTreeItem> > Children;

    void                GetAllFunctions(HashSet<UInt64>* functionIds) const;
    const FuncTreeItem* GetTreeItem(UInt32 treeItemId) const;
    void                ResetTreeIds(FuncTreeItem* other);
    int                 GetNumItems();

    template<typename T>
    void Visit(T& visitor)
    {
        visitor(this);
        for (UPInt i = 0; i < Children.GetSize(); ++i)
        {
            Children[i]->Visit(visitor);
        }
    }

    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
};

struct MovieFunctionStats;

struct MovieFunctionTreeStats : public RefCountBase<MovieFunctionTreeStats, Stat_Default_Mem>
{
    StringLH                    ViewName;
    ArrayLH<Ptr<FuncTreeItem> > FunctionRoots;
    FunctionDescMap             FunctionInfo;

    bool IsEmpty() const;
    void Merge(const MovieFunctionTreeStats& other);
    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
    MovieFunctionStats* Accumulate(bool includeActionscipt) const;
    void Print(Log* log) const;
};

// Per-function call counts and times.
struct MovieFunctionStats : public RefCountBase<MovieFunctionStats, StatAmp_ProfileFrame>
{
    struct FuncStats
    {
        UInt64 FunctionId;
        UInt64 CallerId;
        UInt32 TimesCalled;
        UInt64 TotalTime;
    };

    ArrayLH<FuncStats> FunctionTimings;
    FunctionDescMap    FunctionInfo;

    MovieFunctionStats& operator/=(unsigned numFrames);
    MovieFunctionStats& operator*=(unsigned numFrames);
    void Merge(const MovieFunctionStats& other);
    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
    void DebugPrint() const;
    void Print(Log* log) const;
};

// Per-source-line times.
struct MovieSourceLineStats : public RefCountBase<MovieSourceLineStats, StatAmp_ProfileFrame>
{
    struct SourceStats
    {
        UInt64 FileId;
        UInt32 LineNumber;
        UInt64 TotalTime;
    };

    ArrayLH<SourceStats> SourceLineTimings;
    SourceFileDescMap    SourceFileInfo;

    MovieSourceLineStats& operator/=(unsigned numFrames);
    MovieSourceLineStats& operator*=(unsigned numFrames);
    void Merge(const MovieSourceLineStats& other);
    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
};

// Profile of one movie view.
struct MovieProfile : public RefCountBase<MovieProfile, StatAmp_ProfileFrame>
{
    struct MarkerInfo : public RefCountBase<MarkerInfo, StatAmp_ProfileFrame>
    {
        StringLH Name;
        UInt32   Number;
    };

    UInt32                      ViewHandle;
    UInt32                      MinFrame;
    UInt32                      MaxFrame;
    StringLH                    ViewName;
    UInt32                      Version;
    float                       Width;
    float                       Height;
    float                       FrameRate;
    UInt32                      FrameCount;
    ArrayLH<Ptr<MarkerInfo> >   Markers;
    Ptr<MovieInstructionStats>  InstructionStats;
    Ptr<MovieFunctionStats>     FunctionStats;
    Ptr<MovieSourceLineStats>   SourceLineStats;
    Ptr<MovieFunctionTreeStats> FunctionTreeStats;

    MovieProfile();
    void          Merge(const MovieProfile& rhs);
    MovieProfile& operator=(const MovieProfile& rhs);
    MovieProfile& operator/=(unsigned numFrames);
    MovieProfile& operator*=(unsigned num);
    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
    void Print(Log* log) const;
};

// One image of the frame's image list.
struct ImageInfo : public RefCountBase<ImageInfo, StatAmp_ProfileFrame>
{
    UInt32   Id;
    StringLH Name;
    UInt32   Bytes;
    bool     External;
    UInt32   AtlasId;
    UInt32   AtlasTop;
    UInt32   AtlasBottom;
    UInt32   AtlasLeft;
    UInt32   AtlasRight;

    ImageInfo() : Id(0), Bytes(0), External(false), AtlasId(0), AtlasTop(0), AtlasBottom(0), AtlasLeft(0),
        AtlasRight(0) { }

    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
};

// The AMP server state (Amp_ProfileFrame.h). exe vftable 0x1431921e0.
class ServerState : public RefCountBase<ServerState, StatAmp_ProfileFrame>
{
public:
    UInt32                  StateFlags;
    SInt32                  ProfileLevel;
    StringLH                ConnectedApp;
    StringLH                ConnectedFile;
    StringLH                AaMode;
    StringLH                StrokeType;
    StringLH                CurrentLocale;
    ArrayLH<String>         Locales;
    float                   CurveTolerance;
    float                   CurveToleranceMin;
    float                   CurveToleranceMax;
    float                   CurveToleranceStep;
    UInt64                  CurrentFileId;
    UInt32                  CurrentLineNumber;

    ServerState();
    ServerState& operator=(const ServerState& rhs);
    bool operator!=(const ServerState& rhs) const;

    void        Read(File& str, UInt32 version);
    void        Write(File& str, UInt32 version) const;
};

// One frame of profile data. 4.1.18 (AMP stream version 31) has no Gc* timings or root counts.
class ProfileFrame : public RefCountBase<ProfileFrame, StatAmp_ProfileFrame>
{
public:
    UInt64 TimeStamp;
    UInt32 FramesPerSecond;
    UInt32 AdvanceTime;
    UInt32 ActionTime;
    UInt32 TimelineTime;
    UInt32 InputTime;
    UInt32 MouseTime;
    UInt32 GetVariableTime;
    UInt32 SetVariableTime;
    UInt32 InvokeTime;
    UInt32 DisplayTime;
    UInt32 PresentTime;
    UInt32 TesselationTime;
    UInt32 GradientGenTime;
    UInt32 UserTime;
    UInt32 LineCount;
    UInt32 MaskCount;
    UInt32 FilterCount;
    UInt32 MeshCount;
    UInt32 TriangleCount;
    UInt32 DrawPrimitiveCount;
    UInt32 StrokeCount;
    UInt32 GradientFillCount;
    UInt32 MeshThrashing;
    UInt32 RasterizedGlyphCount;
    UInt32 FontTextureCount;
    UInt32 NumFontCacheTextureUpdates;
    UInt32 FontThrashing;
    UInt32 FontFill;
    UInt32 FontFail;
    UInt32 FontMisses;
    UInt32 FontTotalArea;
    UInt32 FontUsedArea;
    UInt32 TotalMemory;
    UInt32 ImageMemory;
    UInt32 ImageGraphicsMemory;
    UInt32 MovieDataMemory;
    UInt32 MovieViewMemory;
    UInt32 MeshCacheMemory;
    UInt32 MeshCacheGraphicsMemory;
    UInt32 MeshCacheUnusedMemory;
    UInt32 MeshCacheGraphicsUnusedMemory;
    UInt32 FontCacheMemory;
    UInt32 VideoMemory;
    UInt32 SoundMemory;
    UInt32 OtherMemory;

    ArrayLH<Ptr<MovieProfile> > MovieStats;
    Ptr<MovieFunctionStats>     DisplayStats;
    Ptr<MovieFunctionTreeStats> DisplayFunctionStats;
    ArrayLH<UInt32>             SwdHandles;
    ArrayLH<UInt64>             FileHandles;
    Ptr<MemItem>                MemoryByStatId;
    Ptr<MemItem>                Images;
    Ptr<MemItem>                Fonts;
    ArrayLH<Ptr<ImageInfo> >    ImageList;

    ProfileFrame();
    ProfileFrame& operator+=(const ProfileFrame& rhs);
    ProfileFrame& operator/=(unsigned numFrames);
    ProfileFrame& operator*=(unsigned num);
    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
    void Print(Log* log) const;
    int  GetNumFunctionTreeStats() const;
    void AccumulateTreeFunctionStats(bool includeActionScript);
};

static_assert(offsetof(FuncTreeItem, Children) == 0x30, "FuncTreeItem");
static_assert(offsetof(MovieFunctionTreeStats, FunctionInfo) == 0x30, "MovieFunctionTreeStats");
static_assert(sizeof(MovieFunctionStats::FuncStats) == 0x20, "FuncStats");
static_assert(offsetof(MovieFunctionStats, FunctionInfo) == 0x28, "MovieFunctionStats");
static_assert(sizeof(MovieSourceLineStats::SourceStats) == 0x18, "SourceStats");
static_assert(offsetof(MovieProfile, InstructionStats) == 0x58, "MovieProfile");
static_assert(sizeof(MovieProfile) == 0x78, "MovieProfile size");
static_assert(sizeof(ImageInfo) == 0x40, "ImageInfo size");
static_assert(offsetof(ProfileFrame, OtherMemory) == 0xc8, "ProfileFrame stats");
static_assert(offsetof(ProfileFrame, MovieStats) == 0xd0, "ProfileFrame MovieStats");
static_assert(offsetof(ProfileFrame, DisplayStats) == 0xe8, "ProfileFrame DisplayStats");
static_assert(offsetof(ProfileFrame, SwdHandles) == 0xf8, "ProfileFrame SwdHandles");
static_assert(offsetof(ProfileFrame, FileHandles) == 0x110, "ProfileFrame FileHandles");
static_assert(offsetof(ProfileFrame, MemoryByStatId) == 0x128, "ProfileFrame MemoryByStatId");
static_assert(offsetof(ProfileFrame, ImageList) == 0x140, "ProfileFrame ImageList");

// Little endian File helpers of the AMP serialization (SF_File.h inline readers/writers over PRead/PWrite).
inline UInt8  PRead8(File& str)  { UInt8 v = 0; str.Read(&v, 1); return v; }
inline UInt64 PRead64(File& str) { UInt64 v = 0; str.Read(reinterpret_cast<UByte*>(&v), 8); return v; }
inline bool   PWrite8(File& str, UInt8 v)   { return str.Write(&v, 1) == 1; }
inline bool   PWrite32(File& str, UInt32 v) { return str.Write(reinterpret_cast<UByte*>(&v), 4) == 4; }
inline bool   PWrite64(File& str, UInt64 v) { return str.Write(reinterpret_cast<UByte*>(&v), 8) == 8; }

inline UByte  ReadUByte(File& str)  { return static_cast<UByte>(PRead8(str)); }
inline SByte  ReadSByte(File& str)  { return static_cast<SByte>(PRead8(str)); }
inline UInt64 ReadUInt64(File& str) { return PRead64(str); }
inline float  ReadFloat(File& str)  { float v = 0.0f; str.Read(reinterpret_cast<UByte*>(&v), 4); return v; }
inline void   WriteUByte(File& str, UByte v)   { PWrite8(str, static_cast<UInt8>(v)); }
inline void   WriteSByte(File& str, SByte v)   { PWrite8(str, static_cast<UInt8>(v)); }
inline void   WriteUInt32(File& str, UInt32 v) { PWrite32(str, v); }
inline void   WriteUInt64(File& str, UInt64 v) { PWrite64(str, v); }
inline void   WriteFloat(File& str, float v)   { str.Write(reinterpret_cast<UByte*>(&v), 4); }

void readString(File& file, String* str);
void writeString(File& file, const String& str);

} // namespace AMP
} // namespace GFx
} // namespace Scaleform

#endif
