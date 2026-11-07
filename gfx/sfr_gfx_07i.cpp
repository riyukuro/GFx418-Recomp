// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AMP server support (second part):
// memory file / socket buffer deleting destructors, the hash set CheckExpand instances, set clears and the
// per-frame statistics snapshot functions of the AMP server state. Raw-layout free functions under the exe's own
// FUN_<va> names. Sub-unit of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14261fc40-0x14261fd80 .text$mn
// MS2-RANGE: 0x1426202f0-0x142623c60 .text$mn
// MS2-PIN: ?FUN_14261fc40@GFx@Scaleform@@YA_KPEAXPEBE@Z 0x14261fc40
// MS2-FUNCTIONAL: raw-layout transcriptions of the exe's template instances; the algorithms and effects match.

#include "sfr_gfx_07raw.h"
#include "ms2/scaleform/kernel/sf_threads.h"
#include "ms2/scaleform/kernel/sf_random.h"

#include <new>
#include <string.h>
#include <windows.h>
#include "../include/kernel/sf_timer.h"
#include "../include/gfx/amp/amp_profileframe.h"
#include "../include/kernel/sf_hash.h"

unsigned long long FUN_1425e3560();             // performance counter
namespace Scaleform { namespace Render { struct FillStyleType; } typedef ArrayDataBase<Render::FillStyleType, AllocatorLH<Render::FillStyleType, 2>, ArrayDefaultPolicy> Sfr07iFillArr; template<> void Sfr07iFillArr::Reserve(const void*, UPInt); } // (C3) FUN_142623c60 = its Reserve (definer out of line)
namespace Scaleform { namespace GFx {

using ::FUN_1425e3560;

namespace {
// Lock::Locker over the state's critical section: entered here, left when the scope ends.
struct RawLocker
{
    LPCRITICAL_SECTION pLock;
    explicit RawLocker(char* lock) : pLock((LPCRITICAL_SECTION)lock) { EnterCriticalSection(pLock); }
    ~RawLocker() { LeaveCriticalSection(pLock); }
};

}

extern char DAT_14318f020[];
extern char DAT_14318f048[];
extern char DAT_14318f060[];
extern char DAT_14318f040[];
extern char DAT_14318f030[];

void FUN_14015b310(void*, UPInt);
void FUN_14261fa90(char*);
void FUN_142624840(U**, void*, U);
void FUN_142624af0(U**, void*, U);
void FUN_142624d70(U**, void*, U);
void FUN_142624f80(U**, void*, U);
void FUN_1426251d0(U**, void*, U);
void FUN_1426255e0(U**, void*, U);
U* FUN_1426223c0(U**, U*, const String*);   // NoCase String set Find(iterator out, key)
void FUN_1426240f0(U*, void*, U);             // Array<Ptr>::Resize
static __forceinline void FUN_142623bc0(U* a, void* o, U n) { reinterpret_cast<ArrayDataBase<AMP::MovieFunctionStats::FuncStats, AllocatorLH<AMP::MovieFunctionStats::FuncStats, 2>, ArrayDefaultPolicy>*>(a)->Reserve(o, n); }   // (C3) = Array<FuncStats>::Reserve (0x142623bc0)
//void FUN_142623c60(U*, void*, U);           // (C3) = Sfr07iFillArr::Reserve
void FUN_142623e40(U*, void*, U);             // Array<Ptr>::Reserve
void FUN_142623d00(U*, void*, U);             // Array<0x18-byte record>::Reserve
void FUN_142623da0(U*, void*, U);             // Array<Ptr>::Reserve
void FUN_142624190(U**, const U*, void* const*);   // Hash<key, Ptr>::Set
void FUN_142624300(U**, const U*, const String*);   // Hash<key, Ptr>::Set (second value type)
void FUN_142624700(U, U, int, int, U);
void FUN_14261e730(char*, U*);
void FUN_14261f220(U**, void*, StringKeyOps::Ref*, U);
void FUN_14261ec70(U**, void*, NodeRef*, U);
void FUN_14261eae0(U**, void*, WordsRefOps::Ref*, U);
// @0x14261fc40: FixedSizeHash<UByte[16]> (sdbm). Inline so cl sees it writes no memory, as the exe's TU did.
inline __declspec(noinline) U FUN_14261fc40(void*, const unsigned char* key) { return FixedSizeHash<UByte[16]>::SDBM_Hash(key, 16); }
void FUN_142624020(U*, void*, U);               // Array<0x18-byte record>::Resize
void FUN_142623f80(U*, void*, U);               // Array<8-byte>::Reserve
void FUN_14261ee70(U**, void*, NodeRef*, U);
__declspec(noinline) void FUN_142623820(char*, unsigned, UInt32, const char*, int, int, char);
void FUN_142623050(char*, int, int, U);
__declspec(noinline) void FUN_1426237c0(char*);

static inline void RawDelete(void* self, unsigned long long flags, UPInt size)
{
    if (flags & 1)
        ::operator delete(self, size);
}

// @0x1426202f0
void* FUN_1426202f0(char* self, unsigned flags)
{
    (RawFieldPtr<String>(self, 0x10))->~String();
    RawRefCountCoreDtor(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x30);
    }
    return self;
}

// @0x142620370
void* FUN_142620370(char* self, unsigned flags)
{
    (RawFieldPtr<String>(self, 0x10))->~String();
    RawRefCountCoreDtor(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x20);
    }
    return self;
}

// @0x1426203f0
void* FUN_1426203f0(char* self, unsigned flags)
{
    Memory::Free(RawField<void*>(self, 0x20));
    RawRefCountCoreDtor(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x38);
    }
    return self;
}

// @0x142620460
void* FUN_142620460(char* self, unsigned flags)
{
    FUN_14261fa90(self);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(self);
        else
            FUN_14015b310(self, 0x1d0);
    }
    return self;
}

// Counter adjusters of the AMP stats (vftable slots in the exe's .rdata).
// @0x1426204c0
void FUN_1426204c0(char* self, int delta) { RawField<int>(self, 0x174) += delta; }
// @0x1426204d0
void FUN_1426204d0(char* self, int delta) { RawField<int>(self, 0x170) += delta; }

namespace AMP {
class ViewStats
{
public:
    void AddMarker(const char* name);
    void GetStats(StatBag* bag, bool clear);
};
}

// Counts a named marker: bumps an existing entry or adds {name, 1}.
// MS2-FUNCTIONAL: one-instruction scheduling (the exe masks name2.pData before the Ref.Key store); same blocks
// @0x1426204e0
void AMP::ViewStats::AddMarker(const char* name)
{
    char* self = reinterpret_cast<char*>(this);
    struct Iterator
    {
        U**   pHash;
        SPInt Index;
        bool  IsEnd() const { return !pHash || !*pHash || Index > (SPInt)(*pHash)[1]; }
        char* Entry() const { return (char*)(*pHash + 2) + Index * 0x20; }
    } it;
    {
        String key(name);
        FUN_1426223c0(RawFieldPtr<U*>(self, 0x168), (U*)&it, &key);
    }
    if (!it.IsEnd())
    {
        (*(int*)(it.Entry() + 0x18))++;
        return;
    }
    UInt32 one = 1;
    String name2(name);
    StringKeyOps::Ref ref = { &name2, &one };
    FUN_14261f220(RawFieldPtr<U*>(self, 0x168), self + 0x168, &ref,
                  String::BernsteinHashFunctionCIS(name2.ToCStr(), name2.GetSize(), 0x1505));
}

// @0x142620600
void FUN_142620600(U** self, void* ctx) { RawCheckExpand<FUN_142624840>(self, ctx); }
// @0x142620650
void FUN_142620650(U** self, void* ctx) { RawCheckExpand<FUN_142624af0>(self, ctx); }
// @0x1426206a0
void FUN_1426206a0(U** self, void* ctx) { RawCheckExpand<FUN_142624d70>(self, ctx); }
// @0x1426206f0
void FUN_1426206f0(U** self, void* ctx) { RawCheckExpand<FUN_142624f80>(self, ctx); }
// @0x142620740
void FUN_142620740(U** self, void* ctx) { RawCheckExpand<FUN_1426251d0>(self, ctx); }
// @0x142620790
void FUN_142620790(U** self, void* ctx) { RawCheckExpand<FUN_1426255e0>(self, ctx); }

// @0x1426207e0
void FUN_1426207e0(U* self) { RawClearPlainSet(self, 0x30); }
// MS2-FUNCTIONAL: the exe shrink-wraps the callee-saved spill into the non-empty path (split .pdata chunk); same clear logic.
// @0x142620840
__declspec(noinline) void FUN_142620840(U* self) { RawClearPtrSet(self); }
// @0x1426208d0
__declspec(noinline) void FUN_1426208d0(U* self) { RawClearStringSet(self, 0x10); }

// @0x142620970
void FUN_142620970(char* self)
{
    RawLocker lock(self + 0xe0);
    RawClearPlainSet(RawFieldPtr<U>(self, 0x10), 0x30);
    FUN_1426240f0(RawFieldPtr<U>(self, 0x48), self + 0x48, 0);
    RawField<int>(self, 0x60) = 0;
}

// @0x142620a10
void FUN_142620a10(char* self)
{
    if (reinterpret_cast<Mutex*>(self + 0xa8)->TryLock())
    {
        FUN_142620840(RawFieldPtr<U>(self, 0xa0));
        reinterpret_cast<Mutex*>(self + 0xa8)->Unlock();
    }
}

// The set's ConstIterator (Begin() / IsEnd() / ++), over raw entries of the given stride.
namespace {
template<U Stride>
struct RawSetIterator
{
    U**   pHash;
    SPInt Index;
    RawSetIterator(U** hash, SPInt index) : pHash(hash), Index(index) {}
    static RawSetIterator Begin(U** hash)
    {
        if (!*hash)
            return RawSetIterator(nullptr, 0);
        U i = 0;
        while (i <= (*hash)[1] && *(SPInt*)RawEntry(*hash, i, Stride) == -2)
            ++i;
        return RawSetIterator(hash, i);
    }
    bool  IsEnd() const { return !pHash || !*pHash || Index > (SPInt)(*pHash)[1]; }
    char* Entry() const { return RawEntry(*pHash, Index, Stride); }
    void  operator++()
    {
        if (Index <= (SPInt)(*pHash)[1])
        {
            ++Index;
            while ((U)Index <= (*pHash)[1] && *(SPInt*)RawEntry(*pHash, Index, Stride) == -2)
                ++Index;
        }
    }
};
}

// Zeroes the running value of every entry of the per-name statistics set.
// @0x142620a50
void FUN_142620a50(char* self)
{
    RawLocker lock(self + 0xe0);
    for (RawSetIterator<0x28> it = RawSetIterator<0x28>::Begin(RawFieldPtr<U*>(self, 0xd0)); !it.IsEnd(); ++it)
        RawField<U>(it.Entry(), 0x20) = 0;
}

// @0x142620b10
void FUN_142620b10(char* self)
{
    RawLocker lock(self + 0xe0);
    FUN_1426208d0(RawFieldPtr<U>(self, 0x168));
}

// ViewStats::CollectAmpFunctionStats (SDK body; no IsFunctionAggregation test in the exe).
// MS2-FUNCTIONAL: 2356 vs 2397 bytes; same blocks, calls and inlined Find/Set. The exe saves rsi/rdi/r12/r14/r15 with movs
// after the prolog and restores them before the HashSet dtor and unlock tail (split .pdata chunk); ours pushes them. The
// rest is regalloc (movieProfile in rsi vs r14). Tried: functionIds declared first, the real Set in the first loop
// (same code; the exe calls it out of line there and inlines it in the second).
// @0x142620b50
void FUN_142620b50(char* self, AMP::MovieProfile* movieProfile)
{
    // ViewStats::AmpFunctionStats, ParentChildFunctionPair and FunctionStatMap (HashLH<ParentChildFunctionPair, AmpFunctionStats>).
    struct AmpFunctionStats
    {
        UInt32 TimesCalled;
        UInt64 TotalTime;    // Microseconds
    };
    struct ParentChildFunctionPair
    {
        UInt64 CallerId;    // SWF handle and byte offset
        UInt64 FunctionId;  // SWF handle and byte offset
        bool operator==(const ParentChildFunctionPair& kRhs) const { return (CallerId == kRhs.CallerId && FunctionId == kRhs.FunctionId); }
    };
    typedef HashLH<ParentChildFunctionPair, AmpFunctionStats> FunctionStatMap;
    typedef AMP::MovieFunctionStats MovieFunctionStats;
    typedef AMP::FunctionDescMap FunctionDescMap;
    // The ViewStats members are reached through macros so that self+N is recomputed at each use, as in the exe.
#define FunctionTimingMap (*reinterpret_cast<FunctionStatMap*>(self + 0x10))
#define FunctionInfoMap (*reinterpret_cast<FunctionDescMap*>(self + 0x18))
#define viewFunctionRoots (*reinterpret_cast<ArrayLH<Ptr<AMP::FuncTreeItem> >*>(self + 0x48))
    RawLocker locker(self + 0xe0);

    // Copy over all the non-zero function timings
    FunctionStatMap::Iterator funcTimeIter;
    for (funcTimeIter = FunctionTimingMap.Begin(); funcTimeIter != FunctionTimingMap.End(); ++funcTimeIter)
    {
        AmpFunctionStats& funcTime = funcTimeIter->Second;
        if (funcTime.TimesCalled > 0 || funcTime.TotalTime > 0)
        {
            MovieFunctionStats::FuncStats funcStats;
            funcStats.FunctionId = funcTimeIter->First.FunctionId;
            funcStats.CallerId = funcTimeIter->First.CallerId;
            funcStats.TimesCalled = funcTime.TimesCalled;
            funcStats.TotalTime = funcTime.TotalTime; // microseconds
            U* array = reinterpret_cast<U*>(&movieProfile->FunctionStats->FunctionTimings);
            UPInt oldSize = array[1];
            UPInt newSize = oldSize + 1;
            if (newSize < oldSize)
            {
                if (newSize < (array[2] >> 1))
                    FUN_142623bc0(array, array, newSize);
            }
            else if (newSize >= array[2])
                FUN_142623bc0(array, array, newSize + (newSize >> 2));
            array[1] = newSize;
            new ((MovieFunctionStats::FuncStats*)array[0] + newSize - 1) MovieFunctionStats::FuncStats(funcStats);

            // Send the friendly name along with the function Id
            UInt64 swfHandleAndOffset = funcTimeIter->First.FunctionId;
            FunctionDescMap::Iterator funcNameIter = FunctionInfoMap.Find(swfHandleAndOffset);
            if (funcNameIter != FunctionInfoMap.End())
            {
                FunctionDescMap& descMap = movieProfile->FunctionStats->FunctionInfo;
                if (descMap.Find(swfHandleAndOffset) == descMap.End())
                {
                    FUN_142624190(reinterpret_cast<U**>(&descMap), &swfHandleAndOffset, (void* const*)&funcNameIter->Second);
                }
            }
        }
    }

    HashSet<UInt64> functionIds;
    for (UPInt i = 0; i < viewFunctionRoots.GetSize(); ++i)
    {
        U* roots = reinterpret_cast<U*>(&movieProfile->FunctionTreeStats->FunctionRoots);
        FUN_1426240f0(roots, roots, roots[1] + 1);
        new ((Ptr<AMP::FuncTreeItem>*)roots[0] + roots[1] - 1) Ptr<AMP::FuncTreeItem>(viewFunctionRoots[i]);
        viewFunctionRoots[i]->GetAllFunctions(&functionIds);
    }

    for (HashSet<UInt64>::Iterator it = functionIds.Begin(); it != functionIds.End(); ++it)
    {
        FunctionDescMap::Iterator funcNameIter = FunctionInfoMap.Find(*it);
        if (funcNameIter != FunctionInfoMap.End())
        {
            FunctionDescMap& descMap = movieProfile->FunctionTreeStats->FunctionInfo;
            if (descMap.Find(*it) == descMap.End())
            {
                descMap.Set(*it, funcNameIter->Second);
            }
        }
    }
#undef FunctionTimingMap
#undef FunctionInfoMap
#undef viewFunctionRoots
}

// ViewStats::BufferInstructionTimes: one counted array of per-offset times.
struct AmpBufferInstructionTimes : public RefCountBase<AmpBufferInstructionTimes, 0x246>
{
    AmpBufferInstructionTimes(UInt32 size) : Times(size)
    {
        memset(&Times[0], 0, size * sizeof(Times[0]));
    }
    ArrayLH<UInt64, 0x246> Times;
};

// ViewStats::CollectAmpInstructionStats: copies each buffer's non-zero instruction times (in microseconds) into a new ScriptBufferStats and appends it to the movie profile.
// @0x1426214b0
// MS2-FUNCTIONAL: same size and instruction sequence as the exe (871 B). Only the registers in the inlined BufferStatsArray PushBack resize differ: exe rsi/r15/rdi/rbp = array/newSize/p/count, ours r15/rbp/rsi/rdi (regalloc). Tried a Ptr local + copy-construct, an SDK DestructArray helper and a ResizeNoConstruct helper.
void FUN_1426214b0(char* self, AMP::MovieProfile* movieProfile)
{
    typedef HashLH<UInt64, Ptr<AmpBufferInstructionTimes> > InstructionTimingMap;
    typedef AMP::MovieInstructionStats::ScriptBufferStats ScriptBufferStats;
    // SDK ConstructorMov<T>::DestructArray: destroys count elements from the last one down.
    struct DestructArray { static void Run(Ptr<ScriptBufferStats>* first, UPInt count) { first += count - 1; for (; count; --count, --first) first->~Ptr<ScriptBufferStats>(); } };
    Mutex& instructionTimingMutex = *reinterpret_cast<Mutex*>(self + 0xa8);
    if (instructionTimingMutex.TryLock())
    {
        InstructionTimingMap& instructionTimingsMap = *reinterpret_cast<InstructionTimingMap*>(self + 0xa0);
        InstructionTimingMap::Iterator it;
        for (it = instructionTimingsMap.Begin(); it != instructionTimingsMap.End(); ++it)
        {
            Ptr<AmpBufferInstructionTimes>& buffer = it->Second;

            unsigned nonZeroTimes = 0;
            for (UPInt i = 0; i < buffer->Times.GetSize(); i++)
            {
                if (buffer->Times[i] != 0)
                    ++nonZeroTimes;
            }

            if (nonZeroTimes > 0)
            {
                Ptr<ScriptBufferStats> nonZeroValues = *SF_HEAP_AUTO_NEW(movieProfile) ScriptBufferStats();

                nonZeroValues->SwdHandle = static_cast<UInt32>(it->First >> 32);
                nonZeroValues->BufferOffset = static_cast<UInt32>(it->First);
                nonZeroValues->BufferLength = static_cast<UInt32>(buffer->Times.GetSize());
                U* recs = reinterpret_cast<U*>(&nonZeroValues->InstructionTimesArray);
                UPInt newSize = nonZeroTimes;
                if (newSize < recs[1])
                {
                    if (newSize < (recs[2] >> 1))
                        reinterpret_cast<Sfr07iFillArr*>(recs)->Reserve(recs, newSize);
                }
                else if (newSize >= recs[2])
                    reinterpret_cast<Sfr07iFillArr*>(recs)->Reserve(recs, newSize + (newSize >> 2));
                recs[1] = newSize;

                unsigned nonZeroCount = 0;
                for (UPInt i = 0; i < buffer->Times.GetSize(); i++)
                {
                    if (buffer->Times[i] != 0)
                    {
                        AMP::MovieInstructionStats::InstructionTimePair& pair = nonZeroValues->InstructionTimesArray[nonZeroCount];
                        pair.Offset = static_cast<UInt32>(i);
                        pair.Time = buffer->Times[i] * 1000000 / Timer::GetRawFrequency();
                        ++nonZeroCount;
                    }
                }

                U* array = reinterpret_cast<U*>(&movieProfile->InstructionStats->BufferStatsArray);
                UPInt oldSize = array[1];
                UPInt newSize2 = oldSize + 1;
                if (newSize2 < oldSize)
                {
                    DestructArray::Run((Ptr<ScriptBufferStats>*)array[0] + newSize2, oldSize - newSize2);
                    if (newSize2 < (array[2] >> 1))
                        FUN_142623e40(array, array, newSize2);
                }
                else if (newSize2 >= array[2])
                    FUN_142623e40(array, array, newSize2 + (newSize2 >> 2));
                array[1] = newSize2;
                new ((Ptr<ScriptBufferStats>*)array[0] + newSize2 - 1) Ptr<ScriptBufferStats>(nonZeroValues);
            }
        }
        instructionTimingMutex.Unlock();
    }
}

// ViewStats::CollectAmpSourceLineStats: copies each non-zero per-line time (in microseconds) into movieProfile->SourceLineStats, plus the file's name the first time its id is seen.
// The ViewStats maps are reached through macros so that self+0xd0/0xd8 are recomputed at each use, as in the exe.
// @0x142621820
void FUN_142621820(char* self, AMP::MovieProfile* movieProfile)
{
    // ViewStats::FileLinePair and SourceLineStatMap (HashLH<FileLinePair, UInt64>).
    struct FileLinePair
    {
        UInt64 FileId;
        UInt32 LineNumber;
        bool operator==(const FileLinePair& rhs) const { return (FileId == rhs.FileId && LineNumber == rhs.LineNumber); }
    };
    typedef HashLH<FileLinePair, UInt64> SourceLineStatMap;
    typedef AMP::MovieSourceLineStats MovieSourceLineStats;
    RawLocker locker(self + 0xe0);
#define sourceLineTimingsMap (*reinterpret_cast<SourceLineStatMap*>(self + 0xd0))
#define sourceLineInfoMap (*reinterpret_cast<AMP::SourceFileDescMap*>(self + 0xd8))

    // Copy over all the non-zero timings
    SourceLineStatMap::Iterator sourceTimeIter;
    for (sourceTimeIter = sourceLineTimingsMap.Begin(); sourceTimeIter != sourceLineTimingsMap.End(); ++sourceTimeIter)
    {
        if (sourceTimeIter->Second > 0)
        {
            MovieSourceLineStats::SourceStats sourceStats;
            sourceStats.FileId = sourceTimeIter->First.FileId;
            sourceStats.LineNumber = sourceTimeIter->First.LineNumber;
            sourceStats.TotalTime = sourceTimeIter->Second * 1000000 / Timer::GetRawFrequency(); // microseconds
            U* array = reinterpret_cast<U*>(&movieProfile->SourceLineStats->SourceLineTimings);
            UPInt oldSize = array[1];
            UPInt newSize = oldSize + 1;
            if (newSize < oldSize)
            {
                if (newSize < (array[2] >> 1))
                    FUN_142623d00(array, array, newSize);
            }
            else if (newSize >= array[2])
                FUN_142623d00(array, array, newSize + (newSize >> 2));
            array[1] = newSize;
            new ((MovieSourceLineStats::SourceStats*)array[0] + newSize - 1) MovieSourceLineStats::SourceStats(sourceStats);

            // Send the file name along with the file Id
            AMP::SourceFileDescMap::Iterator fileNameIter = sourceLineInfoMap.Find(sourceStats.FileId);
            if (fileNameIter != sourceLineInfoMap.End())
            {
                AMP::SourceFileDescMap& descMap = movieProfile->SourceLineStats->SourceFileInfo;
                if (descMap.Find(sourceStats.FileId) == descMap.End())
                {
                    FUN_142624300(reinterpret_cast<U**>(&descMap), &sourceStats.FileId, &fileNameIter->Second);
                }
            }
        }
    }
}
#undef sourceLineTimingsMap
#undef sourceLineInfoMap

// ViewStats::CollectMarkers(snap): each marker becomes a value-initialised MarkerInfo {name, count} pushed onto
// snap->Markers (the PushBack and its ResizeNoConstruct inlined). Its vftable (folded with the RefCountBase<MarkerInfo,
// 0x242> one) is DAT_14318f048.
// MS2-FUNCTIONAL: one-instruction operand order in the Number load (exe [rax+rsi+0x28], ours [rsi+rax+0x28]); same size, same blocks.
// MS2-PIN: ??_7MarkerInfo@MovieProfile@AMP@GFx@Scaleform@@6B@ 0x14318f048
// MS2-PIN: ??_7?$RefCountBase@UMarkerInfo@MovieProfile@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x14318f048
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0CEC@@Scaleform@@6B@ 0x14318f020
// ArrayLH<Ptr<MarkerInfo>>::PushBack(val), the array as its own `this`.
static __forceinline void RawPushMarker(U* array, const Ptr<AMP::MovieProfile::MarkerInfo>& val)
{
    U oldSize = array[1];
    U newSize = oldSize + 1;
    if (newSize < oldSize)
    {
        void** p = (void**)array[0] + newSize;
        U count = oldSize - newSize;
        p += count - 1;
        for (U i = 0; i < count; ++i, --p)
            if (*p)
                FUN_14257dcb0(*p);
        if (newSize < (array[2] >> 1))
            FUN_142623da0(array, array, newSize);
    }
    else if (newSize >= array[2])
        FUN_142623da0(array, array, newSize + (newSize >> 2));
    array[1] = newSize;
    new ((Ptr<AMP::MovieProfile::MarkerInfo>*)array[0] + newSize - 1) Ptr<AMP::MovieProfile::MarkerInfo>(val);
}
// @0x142621c80
void FUN_142621c80(char* self, char* snap)
{
    RawLocker lock(self + 0xe0);
    for (RawSetIterator<0x20> it = RawSetIterator<0x20>::Begin(RawFieldPtr<U*>(self, 0x168)); !it.IsEnd(); ++it)
    {
        Ptr<AMP::MovieProfile::MarkerInfo> info = *SF_HEAP_AUTO_NEW(snap) AMP::MovieProfile::MarkerInfo();
        info->Name = RawField<String>(it.Entry(), 0x10);
        info->Number = RawField<UInt32>(it.Entry(), 0x18);
        RawPushMarker(RawFieldPtr<U>(snap, 0x40), info);
    }
}

// FuncTreeItem: RefCountBase header, FunctionId, BeginTime, EndTime, TreeItemId, ArrayLH<Ptr<FuncTreeItem>> Children.
struct AmpFuncTreeItem
{
    void* VTable;
    U RefCount;
    U FunctionId;
    U BeginTime;
    U EndTime;
    U TreeItemId;
    AmpFuncTreeItem** ChildData;
    U ChildSize;
    U ChildPolicy;
};

// FuncStatsVisitor: FrameInfo, CallingView (FUN_14261e730 is FuncTreeItem::Visit over it).
class AmpFuncStatsVisitor
{
public:
    AmpFuncStatsVisitor(U frameInfo, char* callingView) : FrameInfo(frameInfo), CallingView(callingView) {}
    void operator()(const AmpFuncTreeItem* treeItem)
    {
        FUN_142624700((U)CallingView, treeItem->FunctionId, (UInt32)(treeItem->EndTime - treeItem->BeginTime), 1, FrameInfo);
    }

private:
    U FrameInfo;
    char* CallingView;
};

// ViewStats::CollectTimingStats: visits every function root, the root's Visit inlined.
// @0x142621ed0
void FUN_142621ed0(char* self, U frameInfo)
{
    RawLocker locker(self + 0xe0);
    {
        AmpFuncStatsVisitor visitor(frameInfo, self);
        for (UPInt i = 0; i < RawField<U>(self, 0x50); ++i)
        {
            AmpFuncTreeItem* rootItem = RawField<AmpFuncTreeItem**>(self, 0x48)[i];
            visitor(rootItem);
            for (UPInt j = 0; j < rootItem->ChildSize; ++j)
                FUN_14261e730((char*)rootItem->ChildData[j], (U*)&visitor);
        }
    }
}


// ===== accessors, finds and the scope stack of the AMP server state =====

static inline bool RawFound(const U* it) { return it[0] && *(U*)it[0] && (SPInt)it[1] <= *(SPInt*)(*(U*)it[0] + 8); }

// The find instances inline the whole lookup and hash the key through its address.
static __forceinline SPInt RawFindKey8At(U* table, const U* key)
{
    if (!table)
        return -1;
    U hash = FixedSizeHash<U>()(*key);
    U home = table[1] & hash;
    U index = home;
    char* e = RawEntry(table, index, 0x20);
    if (*(SPInt*)e == -2 || *(U*)(e + 8) != home)
        return -1;
    for (;;)
    {
        if (*(U*)(e + 8) == home && RawField<U>(e, 0x10) == *key)
            return (SPInt)index;
        SPInt next = *(SPInt*)e;
        if (next == -1)
            return -1;
        index = (U)next;
        e = RawEntry(table, index, 0x20);
    }
}

// HashSetBase::findIndexCore over an eight-byte key at its home slot: the entry index, or -1.
static __forceinline SPInt RawFindKey8Core(U* table, U key, U home)
{
    U index = home;
    char* e = RawEntry(table, index, 0x20);
    if (*(SPInt*)e == -2 || *(U*)(e + 8) != home)
        return -1;
    for (;;)
    {
        if (*(U*)(e + 8) == home && RawField<U>(e, 0x10) == key)
            return (SPInt)index;
        SPInt next = *(SPInt*)e;
        if (next == -1)
            return -1;
        index = (U)next;
        e = RawEntry(table, index, 0x20);
    }
}

// The case-insensitive findIndexCore of a StringHash keyed by String (0x20-byte entries): the entry index, or -1.
static inline SPInt FindStringKeyIndex(U** self, const String* key)
{
    if (!*self)
        return -1;
    U     hash  = String::BernsteinHashFunctionCIS(key->ToCStr(), key->GetSize(), 0x1505);
    U*    table = *self;
    U     home  = hash & table[1];
    SPInt index = (SPInt)home;
    char* e     = RawEntry(table, index, 0x20);
    if (*(SPInt*)e == -2 || *(U*)(e + 8) != home)
        return -1;
    for (;;)
    {
        if (*(U*)(e + 8) == home && strcmp((RawFieldPtr<const String>(e, 0x10))->ToCStr(), key->ToCStr()) == 0)
            return index;
        index = *(SPInt*)e;
        if (index == -1)
            break;
        e = RawEntry(table, index, 0x20);
    }
    return -1;
}

static __forceinline U* RawFindMovieKey(U** self, U* out, const U* key)
{
    struct Iterator
    {
        U**   pHash;
        SPInt Index;
    };
    Iterator* it  = reinterpret_cast<Iterator*>(out);
    SPInt     idx = RawFindKey8At(*self, key);
    if (idx >= 0)
    {
        it->pHash = self;
        it->Index = idx;
    }
    else
    {
        it->pHash = 0;
        it->Index = 0;
    }
    return out;
}

// @0x142622030
__declspec(noinline) U* FUN_142622030(U** self, U* out, const U* key) { return RawFindMovieKey(self, out, key); }
// @0x142622160
__declspec(noinline) U* FUN_142622160(U** self, U* out, const U* key) { return RawFindMovieKey(self, out, key); }
// @0x142622290
__declspec(noinline) U* FUN_142622290(U** self, U* out, const U* key) { return RawFindMovieKey(self, out, key); }

// @0x1426223c0
U* FUN_1426223c0(U** self, U* out, const String* key)
{
    struct Iterator
    {
        U**   pHash;
        SPInt Index;
    };
    Iterator* it    = reinterpret_cast<Iterator*>(out);
    SPInt     found = FindStringKeyIndex(self, key);
    if (found >= 0)
    {
        it->pHash = self;
        it->Index = found;
    }
    else
    {
        it->pHash = 0;
        it->Index = 0;
    }
    return out;
}

template<class T, unsigned Lock, unsigned Off>
static inline T RawLocked(char* self)
{
    RawLocker lock(self + Lock);
    return *(T*)(self + Off);
}

// @0x1426224d0
U FUN_1426224d0(char* self) { return RawLocked<U, 0x78, 0x68>(self); }
// @0x142622510
unsigned FUN_142622510(char* self) { return RawLocked<unsigned, 0x78, 0x70>(self); }
// @0x142622550
unsigned FUN_142622550(char* self) { return RawLocked<unsigned, 0xe0, 0x118>(self); }
// @0x142622590
unsigned FUN_142622590(char* self) { return RawLocked<unsigned, 0xe0, 0x12c>(self); }
// @0x1426225d0
float FUN_1426225d0(char* self) { return RawLocked<float, 0xe0, 0x128>(self); }
// @0x142622620
float FUN_142622620(char* self) { return RawLocked<float, 0xe0, 0x124>(self); }
// @0x142622900
unsigned FUN_142622900(char* self) { return RawLocked<unsigned, 0xe0, 0x11c>(self); }
// @0x142622940
unsigned FUN_142622940(char* self) { return RawLocked<unsigned, 0xe0, 0x108>(self); }
// @0x142622980
float FUN_142622980(char* self) { return RawLocked<float, 0xe0, 0x120>(self); }

// Timer sampling: with 0 returns the counter delta, otherwise scales the elapsed time and re-arms a random skip count.
// @0x142622670
SPInt FUN_142622670(char* self, unsigned period)
{
    U timeDiff = 0;

    if (period == 0)
    {
        U nextTimer = FUN_1425e3560();
        timeDiff = nextTimer - RawField<U>(self, 0x160);
        RawField<U>(self, 0x160) = nextTimer;
    }
    else
    {
        if (RawField<U>(self, 0x160) != 0)
        {
            timeDiff = (FUN_1425e3560() - RawField<U>(self, 0x160)) * period;
        }

        if (RawField<unsigned>(self, 0x158) == 0)
        {
            RawField<U>(self, 0x160) = FUN_1425e3560();
            U random = (unsigned)reinterpret_cast<Alg::Random::Generator*>(self + 0x130)->NextRandom();
            random *= 2 * period;
            random /= 0xFFFFFFFF;
            RawField<unsigned>(self, 0x158) = static_cast<unsigned>(random);
        }
        else
        {
            RawField<U>(self, 0x160) = 0;
            --RawField<unsigned>(self, 0x158);
        }
    }

    return (SPInt)timeDiff;
}

// Snapshots the open scopes into a new stats record, optionally clearing the recorded scopes.
// @0x142622740
void AMP::ViewStats::GetStats(StatBag* bag, bool clear)
{
    char* self = reinterpret_cast<char*>(this);
    if (bag != NULL)
    {
        Ptr<AMP::ProfileFrame> stats = *SF_HEAP_AUTO_NEW(this) AMP::ProfileFrame();
        RawLocker locker(self + 0xe0);
        AmpFuncStatsVisitor visitor((U)stats.GetPtr(), self);
        for (UPInt i = 0; i < RawField<U>(self, 0x50); ++i)
        {
            AmpFuncTreeItem* rootItem = RawField<AmpFuncTreeItem**>(self, 0x48)[i];
            visitor(rootItem);
            for (UPInt j = 0; j < rootItem->ChildSize; ++j)
                FUN_14261e730((char*)rootItem->ChildData[j], (U*)&visitor);
        }
    }
    if (clear)
    {
        EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
        RawClearPlainSet(RawFieldPtr<U>(self, 0x10), 0x30);
        FUN_1426240f0(RawFieldPtr<U>(self, 0x48), self + 0x48, 0);
        RawField<int>(self, 0x60) = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    }
}

// @0x1426229d0
bool FUN_1426229d0(char* self)
{
    typedef char (*Fn)(void*);
    return ((Fn*)RawField<void**>(self, 0x178))[1](self + 0x178) == 0;
}

// ViewStats::LockBufferInstructionTimes: returns the per-key record array for (a, b), creating it with `count` zeroed words on first use.
// MS2-FUNCTIONAL: the unrolled SDBM key hash sums its bytes in another order (exe 6,7,4,5, ours 4,5,7,6 after 3,2,1); same size and blocks
// @0x1426229f0
char* FUN_1426229f0(char* self, unsigned a, UInt32 b, unsigned count)
{
    reinterpret_cast<Mutex*>(self + 0xa8)->DoLock();
    U** set = RawFieldPtr<U*>(self, 0xa0);
    U key = ((U)a << 32) + b;
    U it[2];
    FUN_142622030(set, it, &key);
    if (!RawFound(it))
    {
        AmpBufferInstructionTimes* pBuffer = SF_HEAP_AUTO_NEW(self) AmpBufferInstructionTimes(count);
        void* value = pBuffer;
        NodeRef ref = { &key, &value };
        U hash = FixedSizeHash<U>()(key);
        SPInt idx = -1;
        if (*set)
            idx = RawFindKey8Core(*set, key, hash & (*set)[1]);
        if (idx >= 0)
        {
            char* payload = (char*)*set + (idx + 1) * 0x20;
            RawField<U>(payload, 0) = key;
            if (value)
                FUN_14257dc30(value);
            if (RawField<void*>(payload, 8))
                FUN_14257dcb0(RawField<void*>(payload, 8));
            RawField<void*>(payload, 8) = value;
        }
        else
            FUN_14261ec70(set, set, &ref, hash);
        if (value)
            FUN_14257dcb0(value);
        U tmp[2];
        U* r = FUN_142622030(set, tmp, &key);
        memcpy(it, r, sizeof(it));
    }
    return *(char**)(*(U*)it[0] + 0x10 + it[1] * 0x20 + 0x18) + 0x10;
}

// ViewStats::CallInfo, one 0x18 entry of the call stack at +0x30.
struct AmpCallInfo
{
    void* FunctionInfo;
    U FileId;
    UInt32 LineNumber;
};

// ArrayLH<CallInfo>: Data, Size, Policy.
struct AmpCallstack
{
    AmpCallInfo* Data;
    U Size;
    U Policy;
    bool IsEmpty() const { return Size == 0; }
    AmpCallInfo& Back() { return Data[Size - 1]; }
};

// The ViewStats fields the call-stack code touches.
struct AmpViewStatsView
{
    char Pad0[0x30];
    AmpCallstack Callstack;            // +0x30
    char Pad48[0x20];
    U ActiveFileId;                    // +0x68
    UInt32 ActiveLineNumber;           // +0x70
    CRITICAL_SECTION ActiveLock;       // +0x78

    // ViewStats::RefreshActiveLine: copies the top call's file and line under ActiveLock.
    void RefreshActiveLine()
    {
        if (!Callstack.IsEmpty())
        {
            AmpCallInfo& back = Callstack.Back();
            RawLocker lock((char*)&ActiveLock);
            ActiveFileId = back.FileId;
            ActiveLineNumber = back.LineNumber;
        }
    }
};

static inline void RawPublishTopScope(char* self) { ((AmpViewStatsView*)self)->RefreshActiveLine(); }

// @0x142622c90
void FUN_142622c90(char* self, U arg)
{
    RawLocker locker(self + 0xe0);
    AmpViewStatsView* vs = (AmpViewStatsView*)self;
    if (!vs->Callstack.IsEmpty())
    {
        U functionId = RawField<U>(vs->Callstack.Back().FunctionInfo, 0x10);
        FUN_142623050(self, (int)(functionId >> 32), (int)functionId, arg);
    }
}

// ViewStats::PushCallstack body, also inlined into NativePushCallstack (0x142622d00).
static __forceinline void RawPushCallstack(char* self, UInt32 swdHandle, UInt32 swfOffset, U funcTime)
{
    RawLocker locker(self + 0xe0);
    Ptr<AMP::FuncTreeItem> newCall = *SF_HEAP_AUTO_NEW(self) AMP::FuncTreeItem();
    newCall->BeginTime = funcTime;
    newCall->FunctionId = ((UInt64)swdHandle << 32) + swfOffset;
    RawField<int>(self, 0x60) += 1;
    newCall->TreeItemId = RawField<int>(self, 0x60);
    {
        struct CallInfo
        {
            Ptr<AMP::FuncTreeItem> FunctionInfo; U FileId; UInt32 LineNumber;
            CallInfo(AMP::FuncTreeItem* f, U file, UInt32 line) : FunctionInfo(f), FileId(file), LineNumber(line) {}
        } call(newCall, 0, 0);
        FUN_142624020(RawFieldPtr<U>(self, 0x30), self + 0x30, RawField<U>(self, 0x38) + 1);
        CallInfo* slot = (CallInfo*)RawField<U>(self, 0x30) + RawField<U>(self, 0x38) - 1;
        new (slot) CallInfo(call);
    }
    RawPublishTopScope(self);
}

// Opens a named scope: interns the name (assigning the next id) and pushes it.
// MS2-FUNCTIONAL 0x142622d00: same length (844); scheduling only (the exe loads the hash mask movabs before the Ref value store).
// @0x142622d00
void FUN_142622d00(char* self, const char* name, unsigned id, U arg)
{
    EnterCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
    UInt32 handle = id;
    if ((int)id == -1)
    {
        U** names = RawFieldPtr<U*>(self, 0x20);
        U it[2];
        {
            String key(name);
            FUN_1426223c0(names, it, &key);
        }
        if (!RawFound(it))
        {
            FUN_142623820(self, 1, RawField<unsigned>(self, 0x28), name, 0, 0, 0);
            {
                String key(name);
                StringKeyOps::Ref ref = { &key, RawFieldPtr<UInt32>(self, 0x28) };
                FUN_14261f220(names, names, &ref,
                              String::BernsteinHashFunctionCIS(key.ToCStr(), key.GetSize(), 0x1505));
            }
            {
                String key(name);
                U found[2];
                memcpy(it, FUN_1426223c0(names, found, &key), sizeof(it));
            }
            RawField<int>(self, 0x28) += 1;
        }
        handle = *(UInt32*)(*(U*)it[0] + 0x10 + it[1] * 0x20 + 0x18);
    }
    else
        FUN_142623820(self, 1, handle, name, 0, 0, 0);
    RawPushCallstack(self, 1, handle, arg);
    LeaveCriticalSection((LPCRITICAL_SECTION)(self + 0xe0));
}

// ViewStats::IsFunctionAggregation: always false without SF_AMP_SERVER.
static inline UInt64 RawSwdOffsetKey(UInt32 swdHandle, UInt32 swfOffset) { return ((UInt64)swdHandle << 32) + swfOffset; }
static inline bool RawIsFunctionAggregation() { return false; }
void RawAggregateFunctionTime(char*, void*, U);

// ArrayLH<Ptr<FuncTreeItem>>::PushBack(val): grow by one (0x1426240f0), then copy-construct the last slot.
static __forceinline void RawPushItem(U* arr, const Ptr<AMP::FuncTreeItem>& val)
{
    FUN_1426240f0(arr, arr, arr[1] + 1);
    new ((Ptr<AMP::FuncTreeItem>*)arr[0] + arr[1] - 1) Ptr<AMP::FuncTreeItem>(val);
}

// ViewStats::PopCallstack: closes the top call (when it matches {swdHandle, swfOffset}) and files it under its
// parent, the object-interface root (1:0xe, for 1:0xf..0x36) or the function roots.
// MS2-FUNCTIONAL 0x142623050: 916 vs 907 bytes; same blocks and calls, register allocation only (the exe keeps the
// swd handle/offset in r12/r13 and a zero in r15 across RefreshActiveLine, ours keeps the key in r14).
#pragma strict_gs_check(push, on)
// @0x142623050
void FUN_142623050(char* self, int swdHandle, int swfOffset, U funcTime)
{
    if (swdHandle == 0)
        return;

    RawLocker locker(self + 0xe0);
    AmpCallstack& callstack = ((AmpViewStatsView*)self)->Callstack;
    if (callstack.IsEmpty())
        return;

    typedef Ptr<AMP::FuncTreeItem> ItemPtr;
    if (RawSwdOffsetKey(swdHandle, swfOffset) != reinterpret_cast<ItemPtr&>(callstack.Back().FunctionInfo)->FunctionId)
        return;

    ItemPtr poppedCall = reinterpret_cast<ItemPtr&>(callstack.Back().FunctionInfo);
    poppedCall->EndTime = poppedCall->BeginTime + funcTime;
    {
        U oldSize = callstack.Size;
        U newSize = oldSize - 1;
        FUN_142624020(RawFieldPtr<U>(self, 0x30), self + 0x30, newSize);
        if (newSize > oldSize)
        {
            struct CallInfo
            {
                ItemPtr FunctionInfo; U FileId; UInt32 LineNumber;
                CallInfo() : FileId(0), LineNumber(0) {}
            };
            CallInfo* p = (CallInfo*)callstack.Data + oldSize;
            for (U n = newSize - oldSize; n; --n, ++p)
                new (p) CallInfo();
        }
    }
    FUN_1426237c0(self);

    struct ParentChildFunctionPair { UInt64 CallerId; UInt64 FunctionId; } keyParentChild;
    keyParentChild.FunctionId = RawSwdOffsetKey(swdHandle, swfOffset);
    if (callstack.Size == 0)
        keyParentChild.CallerId = 0;
    else
        keyParentChild.CallerId = reinterpret_cast<ItemPtr&>(callstack.Back().FunctionInfo)->FunctionId;

    U* roots = RawFieldPtr<U>(self, 0x48);
    if (RawIsFunctionAggregation())
    {
        // FunctionTimingMap aggregation; compiled out without SF_AMP_SERVER, but keyParentChild stays on the stack.
        RawAggregateFunctionTime(self, &keyParentChild, funcTime);
    }
    else if (callstack.Size > 0)
    {
        RawPushItem(reinterpret_cast<U*>(&reinterpret_cast<ItemPtr&>(callstack.Back().FunctionInfo)->Children), poppedCall);
    }
    else if (swdHandle == 1 && (UInt32)swfOffset > 0xe && (UInt32)swfOffset < 0x37)
    {
        UInt64 objectInterfaceRootId = RawSwdOffsetKey(1, 0xe);
        bool foundObjectInterfaceRoot = false;
        for (UPInt i = 0; i < roots[1]; ++i)
        {
            if (((AMP::FuncTreeItem**)roots[0])[i]->FunctionId == objectInterfaceRootId)
            {
                foundObjectInterfaceRoot = true;
                ((AMP::FuncTreeItem**)roots[0])[i]->EndTime += funcTime;
                RawPushItem(reinterpret_cast<U*>(&((AMP::FuncTreeItem**)roots[0])[i]->Children), poppedCall);
                break;
            }
        }
        if (!foundObjectInterfaceRoot)
        {
            ItemPtr newCall = *SF_HEAP_AUTO_NEW(self) AMP::FuncTreeItem();
            newCall->BeginTime = 0;
            newCall->EndTime = funcTime;
            newCall->FunctionId = objectInterfaceRootId;
            RawField<int>(self, 0x60) += 1;
            newCall->TreeItemId = RawField<int>(self, 0x60);
            RawPushItem(reinterpret_cast<U*>(&newCall->Children), poppedCall);
            RawPushItem(roots, newCall);
        }
    }
    else
    {
        RawPushItem(roots, poppedCall);
    }

    int& callstackDepthPause = RawField<int>(self, 0x64);
    if (callstackDepthPause >= 0 && static_cast<int>(callstack.Size) >= callstackDepthPause)
    {
        reinterpret_cast<Event*>(self + 0x178)->ResetEvent();
        callstackDepthPause = -1;
    }
}
#pragma strict_gs_check(pop)

// ViewStats::PushCallstack(swdHandle, swfOffset, funcTime): the new FuncTreeItem is value-initialised and pushed as a
// CallInfo {item, 0, 0}. Its vftable (folded with the RefCountBase<FuncTreeItem, 2> one) is DAT_14318f040.
// MS2-PIN: ??_7FuncTreeItem@AMP@GFx@Scaleform@@6B@ 0x14318f040
// MS2-PIN: ??_7?$RefCountBase@VFuncTreeItem@AMP@GFx@Scaleform@@$01@Scaleform@@6B@ 0x14318f040
// @0x1426233e0
void FUN_1426233e0(char* self, UInt32 swdHandle, UInt32 swfOffset, U funcTime)
{
    RawPushCallstack(self, swdHandle, swfOffset, funcTime);
}

// RecordSourceLineTime: SourceLineTimingsMap is a HashLH<FileLinePair, UInt64> at +0xd0
// (0x28-byte entries: NextInChain, HashValue, FileId, LineNumber, Second).
struct Sfr07iFileLine { U FileId; unsigned LineNumber; };
struct Sfr07iLineRef { const Sfr07iFileLine* pFirst; const U* pSecond; };
struct Sfr07iLineEntry { SPInt NextInChain; U HashValue; Sfr07iFileLine First; U Second; };
struct Sfr07iLineTable { U EntryCount; U SizeMask; };
struct Sfr07iLineMap;
struct Sfr07iLineIt { Sfr07iLineMap* pHash; SPInt Index; };
struct Sfr07iLineHashF { };

struct Sfr07iLineMap
{
    Sfr07iLineTable* pTable;

    __forceinline Sfr07iLineEntry& E(UPInt index) { return *(((Sfr07iLineEntry*)(pTable + 1)) + index); }

    __forceinline SPInt FindIndexCore(const Sfr07iFileLine& key, UPInt hashValue)
    {
        UPInt index = hashValue;
        Sfr07iLineEntry* e = &E(index);
        if (e->NextInChain == -2 || e->HashValue != index)
            return -1;
        for (;;)
        {
            if (e->HashValue == hashValue && e->First.FileId == key.FileId && e->First.LineNumber == key.LineNumber)
                return (SPInt)index;
            index = (UPInt)e->NextInChain;
            if (index == (UPInt)-1)
                break;
            e = &E(index);
        }
        return -1;
    }

    __forceinline Sfr07iLineIt Find(const Sfr07iFileLine& key)
    {
        SPInt index = -1;
        if (pTable)
        {
            Sfr07iLineHashF hf;
            UPInt hashValue = FUN_14261fc40(&hf, (const unsigned char*)&key) & pTable->SizeMask;
            index = FindIndexCore(key, hashValue);
        }
        Sfr07iLineIt it;
        if (index >= 0)
        {
            it.pHash = this;
            it.Index = index;
        }
        else
        {
            it.pHash = 0;
            it.Index = 0;
        }
        return it;
    }

    __forceinline void Set(const Sfr07iFileLine& key, const U& value)
    {
        Sfr07iLineRef ref = { &key, &value };
        Sfr07iLineHashF hf;
        UPInt hashValue = FUN_14261fc40(&hf, (const unsigned char*)ref.pFirst);
        SPInt index = -1;
        if (pTable != 0)
            index = FindIndexCore(*ref.pFirst, hashValue & pTable->SizeMask);
        if (index >= 0)
        {
            Sfr07iLineEntry& e = E(index);
            e.First = *ref.pFirst;
            e.Second = value;
        }
        else
            FUN_14261eae0((U**)&pTable, this, (WordsRefOps::Ref*)&ref, hashValue);
    }
};

static __forceinline bool RawLineItIsEnd(const Sfr07iLineIt& it)
{
    return it.pHash == 0 || it.pHash->pTable == 0 || it.Index > (SPInt)it.pHash->pTable->SizeMask;
}

// MS2-FUNCTIONAL 0x142623560: SDK ViewStats::RecordSourceLineTime shape (Find, Set(0), re-Find, += lineTime).
// 600 bytes vs 603: register choice (exe keeps lineTime in r14, the map in rsi) and the Set loop's idx*0x28 entry addressing.
// @0x142623560
void FUN_142623560(char* self, U lineTime)
{
    Sfr07iFileLine fileLine;
    fileLine.LineNumber = RawLocked<unsigned, 0x78, 0x70>(self);
    if (fileLine.LineNumber != 0)
    {
        fileLine.FileId = RawLocked<U, 0x78, 0x68>(self);
        Sfr07iLineMap* map = RawFieldPtr<Sfr07iLineMap>(self, 0xd0);
        Sfr07iLineIt it = map->Find(fileLine);
        if (RawLineItIsEnd(it))
        {
            map->Set(fileLine, 0);
            it = map->Find(fileLine);
        }
        it.pHash->E((UPInt)it.Index).Second += lineTime;
    }
}

// @0x1426237c0
void FUN_1426237c0(char* self) { RawPublishTopScope(self); }

// ViewStats::RegisterScriptFunction: registers a FunctionDesc for (swdHandle, swfOffset), or refreshes its file and line.
// @0x142623820
void FUN_142623820(char* self, unsigned hi, UInt32 lo, const char* text, int a, int b, char useCurrent)
{
    U key = ((U)hi << 32) + lo;
    struct Iterator
    {
        U**   pHash;
        SPInt Index;
        bool  IsEnd() const { return !pHash || !*pHash || Index > (SPInt)(*pHash)[1]; }
        char* Entry() const { return (char*)(*pHash + 2) + Index * 0x20; }
    } it;
    FUN_142622160(RawFieldPtr<U*>(self, 0x18), (U*)&it, &key);
    if (it.IsEnd())
    {
        AMP::FunctionDesc* pDesc = SF_HEAP_AUTO_NEW(self) AMP::FunctionDesc();
        pDesc->Name = text;
        pDesc->Length = a;
        pDesc->ASVersion = b;
        pDesc->FileId = useCurrent ? RawLocked<U, 0x78, 0x68>(self) : 0;
        pDesc->FileLine = useCurrent ? RawLocked<unsigned, 0x78, 0x70>(self) : 0;
        {
            Ptr<AMP::FunctionDesc> value(*pDesc);
            FUN_142624190(RawFieldPtr<U*>(self, 0x18), &key, (void* const*)&value);
        }
    }
    else
    {
        AMP::FunctionDesc* pDesc = RawField<AMP::FunctionDesc*>(it.Entry(), 0x18);
        UInt32 newLine = RawLocked<unsigned, 0x78, 0x70>(self);
        if (useCurrent && newLine != 0)
        {
            pDesc->FileId = RawLocked<U, 0x78, 0x68>(self);
            if (pDesc->FileLine != 0)
                pDesc->FileLine = Alg::Min(pDesc->FileLine, newLine);
            else
                pDesc->FileLine = newLine;
        }
    }
}

// Interns a string with ';' replaced by '\\' under the key (a, b).
// @0x142623a00
void FUN_142623a00(char* self, unsigned hi, UInt32 lo, const char* text)
{
    U key = ((U)hi << 32) + (lo & 0xffffffffULL);
    U it[2];
    FUN_142622290(RawFieldPtr<U*>(self, 0xd8), it, &key);
    if (!RawFound(it))
    {
        U len = strlen(text);
        String s;
        for (U i = 0; i < len; i++)
            s.AppendChar(text[i] == ';' ? 0x5c : (int)text[i]);
        FUN_142624300(RawFieldPtr<U*>(self, 0xd8), &key, &s);
    }
}

struct AmpCallInfoSlot { U a, b, c; };   // ViewStats::CallInfo stand-in (0x18 bytes; the real type is not in our SDK headers)
// @0x142623b10: ArrayDataBase<CallInfo, AllocatorLH<, 0x245>, ArrayConstPolicy<0, 4, true>>::Reserve (caller: sfr_gfx_07j's 0x142624020)
}} // namespace Scaleform::GFx
template void Scaleform::ArrayDataBase<Scaleform::GFx::AmpCallInfoSlot, Scaleform::AllocatorLH<Scaleform::GFx::AmpCallInfoSlot, 0x245>, Scaleform::ArrayConstPolicy<0, 4, true> >::Reserve(const void*, Scaleform::UPInt);
// MS2-PIN: ?Reserve@?$ArrayDataBase@UAmpCallInfoSlot@GFx@Scaleform@@U?$AllocatorLH@UAmpCallInfoSlot@GFx@Scaleform@@$0CEF@@3@U?$ArrayConstPolicy@$0A@$03$00@3@@Scaleform@@QEAAXPEBX_K@Z 0x142623b10 ; unique

// @0x142623bc0: ArrayDataBase<MovieFunctionStats::FuncStats, AllocatorLH<, 2>, ArrayDefaultPolicy>::Reserve (FUN_142623bc0 above)
// MS2-PIN: ?Reserve@?$ArrayDataBase@UFuncStats@MovieFunctionStats@AMP@GFx@Scaleform@@U?$AllocatorLH@UFuncStats@MovieFunctionStats@AMP@GFx@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x142623bc0 ; unique
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// (namespace Scaleform::GFx closed above the 0x142623b10 instantiation)
// MS2-PIN: ??_7AmpBufferInstructionTimes@GFx@Scaleform@@6B@ 0x14318f060
// MS2-PIN: ??_7?$RefCountBase@UAmpBufferInstructionTimes@GFx@Scaleform@@$0CEG@@Scaleform@@6B@ 0x14318f060
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0CEG@@Scaleform@@6B@ 0x14318f060
// MS2-PIN: ??_7FunctionDesc@AMP@GFx@Scaleform@@6B@ 0x14318f030
// MS2-PIN: ??_7?$RefCountBase@UFunctionDesc@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x14318f030
// MS2-PIN: ??_7ScriptBufferStats@MovieInstructionStats@AMP@GFx@Scaleform@@6B@ 0x14318f020
// MS2-PIN: ??_7?$RefCountBase@UScriptBufferStats@MovieInstructionStats@AMP@GFx@Scaleform@@$0CEC@@Scaleform@@6B@ 0x14318f020
