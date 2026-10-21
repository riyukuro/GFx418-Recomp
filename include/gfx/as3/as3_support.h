// Recovered Scaleform GFx 4.1.18 AS3: the pieces of the AS3 player the loader side needs (GFx_AS3Support): the per-movie
// memory context, ABC data blocks and the DoAbc execute tag, plus the AS3 MovieRoot constructor.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS3_SUPPORT_H
#define MS2_SF_GFX_AS3_SUPPORT_H

#include "GFx/GFx_Player.h"
#include "GFx/GFx_PlayerImpl.h"
#include "GFx/GFx_ASMovieRootBase.h"
#include "GFx/GFx_ASString.h"
#include "GFx/GFx_AS3Support.h"
#include "Render/Text/Text_Core.h"
#include "ms2/scaleform/include/gfx/as3/as3_gc.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// Per-movie memory: the movie heap with its string manager and garbage collector. 0x68 bytes; the heap limit
// handler sits at +0x30.
class MemoryContextImpl : public MemoryContext
{
public:
    // Heap limit handler: collects garbage before letting the movie heap grow.
    // The 4.1.18 limit handler base carries one more word than the SDK's MemoryHeap::LimitHandler (it is initialized
    // before the derived vftable is stored): nonzero while collections must not run from inside the allocator, then
    // OnExceedLimit only schedules one.
    struct LimitHandlerBase : public MemoryHeap::LimitHandler
    {
        unsigned            DeferCollect;               // +0x08 (+0x38 in the context)
        LimitHandlerBase() : DeferCollect(0) { }
    };

    class HeapLimit : public LimitHandlerBase
    {
        friend class MemoryContextImpl;

        MemoryContextImpl*  MemContext;                 // +0x10
        UPInt               UserLevelLimit;             // +0x18
        UPInt               LastCollectionFootprint;    // +0x20
        UPInt               CurrentLimit;               // +0x28
        float               HeapLimitMultiplier;        // +0x30
    public:
        HeapLimit() : MemContext(0), UserLevelLimit(0), LastCollectionFootprint(0), CurrentLimit(0),
                      HeapLimitMultiplier(0.25f) { }
        virtual ~HeapLimit() { }
        virtual bool OnExceedLimit(MemoryHeap* heap, UPInt overLimit);
        virtual void OnFreeSegment(MemoryHeap* heap, UPInt freeingSize);

        void SetMemoryContext(MemoryContextImpl* memContext) { MemContext = memContext; }
        void SetUserLevelLimit(UPInt lim)   { UserLevelLimit = lim; }
        void SetHeapLimitMultiplier(float m){ HeapLimitMultiplier = m; }
    };

    MemoryHeap*                         Heap;           // +0x10
    Ptr<ASStringManager>                StringMgr;      // +0x18
    Ptr<ASRefCountCollector>            ASGC;           // +0x20
    Ptr<Render::Text::Allocator>        TextAllocator;  // +0x28
    HeapLimit                           LimHandler;     // +0x30

    MemoryContextImpl() { LimHandler.SetMemoryContext(this); }
    virtual ~MemoryContextImpl() { Heap->SetLimitHandler(0); }
};

// One DoABC tag's byte code. Allocated with the data inline (sizeof - 1 + DataSize).
class AbcDataBuffer : public RefCountBase<AbcDataBuffer, StatMD_ASBinaryData_Mem>
{
public:
    String      Name;           // +0x10
    unsigned    DataSize;       // +0x18
    UByte       Flags;          // +0x1c
    void*       pReserved;      // +0x20
    StringLH    FileName;       // +0x28
    UByte       Data[1];        // +0x30

    AbcDataBuffer(const String& name, unsigned dataSize, UByte flags)
        : Name(name), DataSize(dataSize), Flags(flags), pReserved(0) { }
};

// Execute tag created by DoAbcLoader: runs the ABC block when its frame is reached.
class DoAbc : public ExecuteTag
{
public:
    Ptr<AbcDataBuffer> pAbc;    // +0x08

    DoAbc(AbcDataBuffer* pabc) : pAbc(pabc) { }

    virtual void Execute(DisplayObjContainer* m);
    virtual bool IsActionTag() const { return true; }
};

// The AS3 side of a movie (0x6f8 bytes). Opaque until recovered: the loader side only constructs it and runs ABC
// blocks; it is used through its ASMovieRootBase part (at offset 0).
class MovieRoot
{
public:
    MovieRoot(MemoryContextImpl* memContext, MovieImpl* pmovie, ASSupport* pas);

    // Executes one ABC block for the given sprite; false when the VM refused it.
    bool ExecuteAbc(const AbcDataBuffer* pabc, DisplayObjContainer* pspr);

    ASMovieRootBase* GetBase() { return reinterpret_cast<ASMovieRootBase*>(this); }

    void* operator new(UPInt, void* p) { return p; }
    void  operator delete(void*, void*) { }

private:
    UByte Data[0x6f8];
};

void SF_STDCALL SymbolClassLoader(LoadProcess* p, const TagInfo& tagInfo);
void SF_STDCALL DoAbcLoader(LoadProcess* p, const TagInfo& tagInfo);

}}} // namespace Scaleform::GFx::AS3

#endif
