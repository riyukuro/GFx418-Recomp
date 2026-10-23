// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, first block. Our own source,
// written from the exe (the leaked SDK copies were only used to name things and to compare layouts). Original files of
// this range, in exe order: GFx_AS3Support (the AS3 player factory and the SymbolClass / DoABC tag loaders), the AS3
// garbage collector (AS3_GC; the flash.accessibility classes compiled in between are in sfr_as3_01b.cpp), then
// AS3_Obj_All template instances (thunks, class/traits factories).
// MS2-UNIT: sfr_as3_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423dc110-0x1423dd550 .text$mn
// MS2-RANGE: 0x1423de620-0x1423df430 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?LogError@?$LogBase@VLoadProcess@GFx@Scaleform@@@GFx@Scaleform@@QEBAXPEBDZZ 0x1423dcd80 ; unique
// MS2-PIN: ?LogError@?$LogBase@VStream@GFx@Scaleform@@@GFx@Scaleform@@QEBAXPEBDZZ 0x1423dcdf0 ; unique
// MS2-PIN: ?LogError@Log@Scaleform@@QEAAXPEBDZZ 0x1423dce40 ; unique
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEAVExecuteTag@GFx@Scaleform@@U?$AllocatorGH@PEAVExecuteTag@GFx@Scaleform@@$01@3@U?$ArrayConstPolicy@$0CA@$0BA@$0A@@3@@Scaleform@@QEAAXPEBX_K@Z 0x1423dd080 ; unique
// MS2-PIN: ?SFsprintf@Scaleform@@YA_KPEAD_KPEBDZZ 0x1423dd130 ; unique
// MS2-PINS-END tplpin
#include "ms2/scaleform/include/gfx/gfx_sprite.h"
#include "ms2/scaleform/include/gfx/gfx_spritedef.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
#include "ms2/scaleform/include/gfx/gfx_button.h"
#include "ms2/scaleform/include/gfx/gfx_statictextcharacter.h"
#include "ms2/scaleform/include/video/video_statebag.h"
#include "ms2/scaleform/include/gfx/gfx_loadproc.h"
#include "ms2/scaleform/include/gfx/as3/as3_support.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"

namespace Scaleform { namespace GFx {

template <> void LogBase<LoadProcess>::LogParse(const char* pfmt, ...) const;

// ==== GFx_AS3Support =================================================================================================

// @0x1423dc110
Ptr<ASIMEManager> AS3Support::CreateASIMEManager()
{
    Ptr<ASIMEManager> pimeMgr = *new AS3::IMEManager();
    return pimeMgr;
}

// The display object types an AS3 movie can place. Display objects carry their AS3 part (Avm*) right behind the
// object in the same allocation, at a 4-byte aligned offset.
template <class D, class A>
static UByte* AllocWithAvm(MemoryHeap* pheap)
{
    return (UByte*)pheap->Alloc(((sizeof(D) + 3) & ~3) + sizeof(A), (const AllocInfo*)0);
}

// MS2-FUNCTIONAL: AvmMovieClip's constructor is inlined in the exe (AvmSprite constructor + 4 vftables); its vftables
// are the exe's, stored through AS3::AvmMovieClip::InitVTables.
// @0x1423dc160
DisplayObjectBase* AS3Support::CreateCharacterInstance(MovieImpl* proot, const CharacterCreateInfo& ccinfo,
                                                       InteractiveObject* pparent, ResourceId rid,
                                                       CharacterDef::CharacterDefType type)
{
    MemoryHeap* pheap = proot->GetMovieHeap();
    switch (type != CharacterDef::Unknown ? type : ccinfo.pCharDef->GetType())
    {
    case CharacterDef::Shape:
    {
        void* pm = pheap->Alloc(sizeof(AS3::ShapeObject), (const AllocInfo*)0);
        return pm ? AS3::AsDisplayObject(new (pm) AS3::ShapeObject(ccinfo.pCharDef, proot->pASMovieRoot, pparent, rid))
                  : 0;
    }

    case CharacterDef::Sprite:
    {
        UByte* pm = AllocWithAvm<Sprite, AS3::AvmMovieClip>(pheap);
        Sprite* pspr = pm ? new (pm) Sprite(static_cast<SpriteDef*>(ccinfo.pCharDef), ccinfo.pBindDefImpl,
                                            proot->pASMovieRoot, pparent, rid) : 0;
        AS3::AvmMovieClip* pavm = (AS3::AvmMovieClip*)(pm + ((sizeof(Sprite) + 3) & ~3));
        if (pavm)
            AS3::AvmMovieClip::Construct(pavm, pspr);
        return pspr;
    }
    case CharacterDef::TextField:
    {
        UByte* pm = AllocWithAvm<TextField, AS3::AvmTextField>(pheap);
        TextField* ptxt = pm ? new (pm) TextField(static_cast<TextFieldDef*>(ccinfo.pCharDef), ccinfo.pBindDefImpl,
                                                  proot->pASMovieRoot, pparent, rid) : 0;
        if (AS3::AvmTextField* pavm = (AS3::AvmTextField*)(pm + ((sizeof(TextField) + 3) & ~3)))
            new (pavm) AS3::AvmTextField(ptxt);
        return AS3::AsDisplayObject(ptxt);
    }
    case CharacterDef::StaticText:
    {
        UByte* pm = AllocWithAvm<StaticTextCharacter, AS3::AvmStaticText>(pheap);
        StaticTextCharacter* ptxt = pm ? new (pm) StaticTextCharacter(static_cast<StaticTextDef*>(ccinfo.pCharDef),
                                                                      ccinfo.pBindDefImpl, proot->pASMovieRoot,
                                                                      pparent, rid) : 0;
        if (AS3::AvmStaticText* pavm = (AS3::AvmStaticText*)(pm + ((sizeof(StaticTextCharacter) + 3) & ~3)))
            new (pavm) AS3::AvmStaticText(ptxt);
        return AS3::AsDisplayObject(ptxt);
    }
    case CharacterDef::Button:
    {
        UByte* pm = AllocWithAvm<Button, AS3::AvmButton>(pheap);
        Button* pbtn = pm ? new (pm) Button(static_cast<ButtonDef*>(ccinfo.pCharDef), ccinfo.pBindDefImpl,
                                            proot->pASMovieRoot, pparent, rid) : 0;
        if (AS3::AvmButton* pavm = (AS3::AvmButton*)(pm + ((sizeof(Button) + 3) & ~3)))
            new (pavm) AS3::AvmButton(pbtn);
        return pbtn;
    }
    case CharacterDef::Video:
    {
        Ptr<Video::VideoBase> pvideo = proot->pStateBag->GetVideo();
        if (pvideo && pvideo->GetAS3Support())
            return pvideo->GetAS3Support()->CreateASCharacter(proot, ccinfo.pCharDef, pparent, rid,
                                                              ccinfo.pBindDefImpl);
        return 0;
    }
    case CharacterDef::Bitmap:
    {
        void* pm = pheap->Alloc(sizeof(AS3::AvmBitmap), (const AllocInfo*)0);
        return pm ? AS3::AsDisplayObject(new (pm) AS3::AvmBitmap(proot->pASMovieRoot, ccinfo, pparent, rid)) : 0;
    }

    case CharacterDef::EmptySprite:
    {
        UByte* pm = AllocWithAvm<Sprite, AS3::AvmSprite>(pheap);
        Sprite* pspr = pm ? new (pm) Sprite(static_cast<SpriteDef*>(ccinfo.pCharDef), ccinfo.pBindDefImpl,
                                            proot->pASMovieRoot, pparent, rid) : 0;
        if (AS3::AvmSprite* pavm = (AS3::AvmSprite*)(pm + ((sizeof(Sprite) + 3) & ~3)))
            new (pavm) AS3::AvmSprite(pspr);
        return pspr;
    }
    default:
        return 0;
    }
}

// @0x1423dc560
MemoryContext* AS3Support::CreateMemoryContext(const char* heapName, const MemoryParams& memParams, bool debugHeap)
{
    HeapDesc desc = memParams.Desc;
    desc.Flags |= ((unsigned)debugHeap << 12) | HeapDesc::Heap_FastTinyBlocks | HeapDesc::Heap_ThreadUnsafe;
    desc.HeapId = HeapId_MovieView;
    desc.Limit = 0;
    MemoryHeap* pheap = Memory::GetGlobalHeap()->CreateHeap(heapName, desc);

    AS3::MemoryContextImpl* pmemContext = SF_HEAP_NEW(pheap) AS3::MemoryContextImpl();
    pmemContext->Heap = pheap;
    pmemContext->ASGC = *SF_HEAP_NEW(pheap) AS3::ASRefCountCollector();
    pmemContext->ASGC->SetParams(memParams.FramesBetweenCollections, memParams.MaxCollectionRoots);
    pmemContext->StringMgr = *SF_HEAP_NEW(pheap) ASStringManager(pheap);
    pmemContext->LimHandler.SetUserLevelLimit(memParams.Desc.Limit);
    pmemContext->LimHandler.SetHeapLimitMultiplier(memParams.HeapLimitMultiplier);
    pheap->SetLimitHandler(&pmemContext->LimHandler);
    pheap->ReleaseOnFree(pmemContext);
    return pmemContext;
}

// @0x1423dc710
MovieImpl* AS3Support::CreateMovie(MemoryContext* memContext)
{
    AS3::MemoryContextImpl* pmemContext = static_cast<AS3::MemoryContextImpl*>(memContext);
    MemoryHeap* pheap = pmemContext->Heap;
    MovieImpl* pmovie = SF_HEAP_NEW(pheap) MovieImpl(pheap);
    void* pm = pheap->Alloc(sizeof(AS3::MovieRoot), (const AllocInfo*)0);
    Ptr<ASMovieRootBase> pasRoot = *(pm ? (new (pm) AS3::MovieRoot(pmemContext, pmovie, this))->GetBase() : 0);
    return pmovie;
}

namespace AS3 {

// Stream::LogBytes: verbose-parse hex dump, compiled out of the shipping SDK headers.
void Stream_LogBytes(Stream* pin, unsigned numOfBytes);

// DoABC tag: UI32 flags, null-terminated name, then the ABC bytes up to the end of the tag.
// MS2-FUNCTIONAL: same calls and flow; the exe's StringDH / Ptr temporaries are laid out differently (4 bytes off).
// @0x1423dc7b0
void SF_STDCALL DoAbcLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    Stream* pin = p->GetStream();
    UInt32 flags = pin->ReadU32();
    StringDH name(p->GetLoadHeap());
    pin->ReadString(&name);
    unsigned dataSize = tagInfo.TagDataOffset + tagInfo.TagLength - pin->Tell();

    if (p->IsVerboseParse())
    {
        p->LogParse("  DoAbcLoader: flags = 0x%X, name = '%s', dataSize = %d\n", flags, name.ToCStr(), dataSize);
        Stream_LogBytes(pin, dataSize);
        pin->SetPosition(pin->Tell() - dataSize);
    }
    if (name.IsEmpty() && p->GetASInitActionTagsNum())
    {
        char num[20];
        SFsprintf(num, sizeof(num), "%d", p->GetASInitActionTagsNum());
        name = num;
    }

    void* pmem = Memory::GetGlobalHeap()->Alloc(sizeof(AbcDataBuffer) - 1 + dataSize, (const AllocInfo*)0);
    Ptr<AbcDataBuffer> pabc = *(pmem ? ::new (pmem) AbcDataBuffer(name, dataSize, (UByte)flags) : 0);
    pabc->FileName = p->GetFileURL();
    if (pin->ReadToBuffer(pabc->Data, pabc->DataSize) != (int)pabc->DataSize)
    {
        pin->LogError("Can't read completely ABCData at offset %d", tagInfo.TagOffset);
        return;
    }
    DoAbc* ptag = new (p->AllocTagMemory(sizeof(DoAbc))) DoAbc(0);
    ptag->pAbc = pabc;
    p->AddInitAction(ptag);
}

// MS2-FUNCTIONAL: the exe takes the Log pointer out of the GetLog() temporary before releasing it; register choice.
// @0x1423dcae0
void DoAbc::Execute(DisplayObjContainer* m)
{
    AvmDisplayObj* pavm = ToAvmDisplayObj(m);
    if (!pavm->GetAS3Root()->ExecuteAbc(pAbc, m))
    {
        if (pavm->GetLog())
            pavm->GetLog()->LogError("Can't execute ABC from %s", m->GetResourceMovieDef()->GetFileURL());
    }
}

// SymbolClass tag: UI16 count, then (UI16 character id, null-terminated class name) pairs; id 0 is the main timeline.
// MS2-FUNCTIONAL: identical code except that the stream and the count swap registers (rbx/rdi).
// @0x1423dd1c0
void SF_STDCALL SymbolClassLoader(LoadProcess* p, const TagInfo& tagInfo)
{
    SF_UNUSED(tagInfo);
    Stream* pin = p->GetStream();
    unsigned count = pin->ReadU16();
    p->LogParse("  SymbolClassLoader: num = %d\n", count);
    for (unsigned i = 0; i < count; ++i)
    {
        UInt16 id = pin->ReadU16();
        StringDH className(p->GetLoadHeap());
        pin->ReadString(&className);
        p->LogParse("       id = %d, symbol = '%s'\n", id, className.ToCStr());

        ResourceHandle hres;
        if (id == 0 || p->GetResourceHandle(&hres, ResourceId(id)))
            p->ExportResource(className, ResourceId(id), hres);
        else
            p->LogError("SymbolClassLoader can't find Resource with id = %d, name = '%s'", id, className.ToCStr());
    }
}

// ==== AS3_GC: the movie's garbage collector ==========================================================================
// Synchronous cycle collection over the root buffer: the roots and everything they reach are marked "in cycle" with
// their internal references subtracted (MarkInCycle); whatever still has references is put back in use together with
// what it reaches (ScanInUse); the rest is garbage. Objects with finalizers and their children survive one more round
// (ScanTempInUse) to be finalized first.

typedef RefCountCollector<StatMV_ActionScript_Mem> ASCollector;

// MS2-FUNCTIONAL: the exe keeps the reused slot's address in a register (lea) instead of re-indexing; 3 bytes off.
// @0x1423de620
template <int Stat>
void RefCountCollector<Stat>::AddRoot(const BaseType* root)
{
    if (Flags & Flags_MarkInCycle)
        return;
    UPInt freeIndex = FirstFreeRootIndex;
    if (freeIndex != SF_MAX_UPINT)
    {
        // reuse a free slot: free slots chain the next free index as (index << 1) | 1
        root->RefCount |= BaseType::Flag_InRootList;
        root->RootIndex = (UInt32)freeIndex;
        SPInt next = (SPInt)Roots[FirstFreeRootIndex] >> 1;
        Roots[FirstFreeRootIndex] = root;
        FirstFreeRootIndex = (UPInt)next;
        return;
    }
    UPInt size = Roots.GetSize();
    root->RefCount |= BaseType::Flag_InRootList;
    root->RootIndex = (UInt32)size;
    Flags |= Flags_AddingRoot;
    bool added = Roots.PushBackSafe(root);
    Flags &= ~Flags_AddingRoot;
    if (!added)
    {
        // out of memory: collect and retry; when that fails too the object is just not a root
        bool collected = Collect();
        Flags |= Flags_AddingRoot;
        if (!collected || !Roots.PushBackSafe(root))
        {
            UInt32 rc = root->RefCount;
            root->RefCount = rc & ~BaseType::Flag_InRootList;
            if (!root->IsInList())
                root->RootIndex = ~0u;
            root->RefCount = rc & ~(BaseType::Flag_InRootList | (BaseType::Mask_State << BaseType::Shift_State));
        }
        Flags &= ~Flags_AddingRoot;
    }
}

// MS2-FUNCTIONAL: written from the exe's control flow; register allocation and block order not checked yet.
// @0x1423de770
template <int Stat>
bool RefCountCollector<Stat>::Collect(Stats* pstat)
{
    Flags &= ~Flags_RequireMoreCollect;
    if ((Flags & (Flags_AddingRoot | Flags_InCollect)) || Roots.GetSize() == 0)
    {
        if (pstat)
        {
            pstat->RootsNumber = 0;
            pstat->RootsFreedTotal = 0;
        }
        return false;
    }
    StatsObserver* pobserver = (pstat ? pstat->pObserver : Ptr<StatsObserver>()).GetPtr();
    Flags |= Flags_InCollect;

    unsigned rootsNumber = 0;
    unsigned freed = 0;
    for (;;)
    {
        Flags |= Flags_Collecting;
        UPInt n = Roots.GetSize();
        rootsNumber += (unsigned)n;
        pLastPtr = &ListRoot;
        ListRoot.pPrev = &ListRoot;
        ListRoot.pNext = &ListRoot;
        ListRoot.RefCount |= BaseType::Flag_InList;

        // 1. mark the roots and what they reach
        Flags |= Flags_MarkInCycle;
        for (UPInt i = 0; i < n; ++i)
        {
            const BaseType* proot = Roots[i];
            if ((UPInt)proot & 1)
                continue;
            if (proot->IsInState(BaseType::State_Root))
            {
                if (!proot->IsInList())
                    AddToList(proot);
                for (const BaseType* p = proot; p != &ListRoot; p = p->pNext)
                {
                    if (!p->IsInState(BaseType::State_InCycle))
                    {
                        p->SetState(BaseType::State_InCycle);
                        p->ForEachChild_GC(this, MarkInCycleCall);
                    }
                }
            }
            else
            {
                proot->RefCount &= ~BaseType::Flag_InRootList;
                if (!proot->IsInList())
                    proot->RootIndex = ~0u;
            }
        }
        FirstFreeRootIndex = SF_MAX_UPINT;
        Flags &= ~Flags_MarkInCycle;
        Roots.Resize(0);

        // 2. whatever is still referenced from outside is in use, with everything it reaches
        bool hasFinalizers = false;
        for (const BaseType* p = ListRoot.pNext; p != &ListRoot; p = p->pNext)
        {
            if (p->IsRefCntZero())
            {
                if (p->HasFinalize())
                    hasFinalizers = true;
                p->SetState(BaseType::State_Garbage);
            }
            else
            {
                p->SetState(BaseType::State_InUse);
                pLastPtr = p;
                p->ForEachChild_GC(this, ScanInUseCall);
            }
        }

        // 3. garbage with finalizers keeps itself and its children until finalized
        if (hasFinalizers)
        {
            pLastPtr = &ListRoot;
            for (const BaseType* p = ListRoot.pNext; p != &ListRoot; p = p->pNext)
            {
                if (p->IsInState(BaseType::State_Garbage))
                {
                    if (p->HasFinalize())
                    {
                        p->SetState(BaseType::State_InUse);
                        pLastPtr = p;
                        p->ForEachChild_GC(this, ScanTempInUseCall);
                        p->RefCount |= BaseType::Flag_ToBeFinalized;
                    }
                }
                else if (p->IsInState(BaseType::State_TempInUse))
                {
                    p->SetState(BaseType::State_InUse);
                    pLastPtr = p;
                    p->ForEachChild_GC(this, ScanTempInUseCall);
                }
            }
        }

        // 4. free the garbage, hand the survivors back (delayed releases, roots)
        pLastPtr = &ListRoot;
        const BaseType* pnext;
        for (const BaseType* p = ListRoot.pNext; p != &ListRoot; p = pnext)
        {
            pnext = p->pNext;
            if (p->IsInState(BaseType::State_Garbage))
            {
                if (!p->IsDeleteLast())
                {
                    p->RemoveFromList();
                    if (p->HasWeakRef())
                    {
                        p->RefCount &= ~BaseType::Flag_HasWeakRef;
                        RemoveWeakProxy(p);
                    }
                    p->ForEachChild_GC(this, KillChildCall);
                    delete p;
                    ++freed;
                }
                continue;
            }
            UInt32 rc = p->RefCount;
            p->RemoveFromList();
            p->pRCC = this;
            if (p->IsDelayedRelease())
            {
                p->RefCount &= ~BaseType::Flag_DelayedRelease;
                if ((rc & BaseType::Mask_RefCount) == 0)
                {
                    if (p->HasFinalize())
                        const_cast<BaseType*>(p)->Finalize_GC();
                    if (!p->IsInList())
                    {
                        p->SetState(BaseType::State_InUse);
                        if (p->IsInRootList())
                        {
                            if (!p->IsInList())
                            {
                                p->pRCC->RemoveFromRoots(p);
                                p->RefCount &= ~BaseType::Flag_InRootList;
                                if (!p->IsInList())
                                    p->RootIndex = ~0u;
                            }
                            else
                                p->RemoveFromList();
                        }
                        else if (p->IsInList())
                            p->RemoveFromList();
                        delete p;
                    }
                    else
                        p->RefCount |= BaseType::Flag_DelayedRelease;
                }
                else if (((rc >> BaseType::Shift_State) & BaseType::Mask_State) != BaseType::State_Root)
                {
                    p->SetState(BaseType::State_Root);
                    AddRoot(p);
                }
            }
            else if (p->IsToBeFinalized() ||
                     ((rc >> BaseType::Shift_State) & BaseType::Mask_State) == BaseType::State_Root)
                AddRoot(p);
        }
        // objects that must die last
        for (const BaseType* p = ListRoot.pNext; p != &ListRoot; p = pnext)
        {
            pnext = p->pNext;
            if (p->HasWeakRef())
            {
                p->RefCount &= ~BaseType::Flag_HasWeakRef;
                RemoveWeakProxy(p);
            }
            p->ForEachChild_GC(this, KillChildCall);
            delete p;
            ++freed;
        }
        pLastPtr = &ListRoot;
        ListRoot.RefCount &= ~(BaseType::Flag_InList | BaseType::Flag_InRootList);
        ListRoot.pRCC = 0;
        ListRoot.RootIndex = ~0u;
        Flags &= ~Flags_Collecting;
        FirstFreeRootIndex = SF_MAX_UPINT;

        // 5. run the finalizers of the objects kept in step 3 (they are roots again)
        if (hasFinalizers)
        {
            UPInt nroots = Roots.GetSize();
            for (UPInt i = 0; i < nroots; ++i)
            {
                const BaseType* proot = Roots[i];
                if (((UPInt)proot & 1) == 0 && proot->IsToBeFinalized())
                {
                    proot->RefCount = (proot->RefCount & ~(BaseType::Flag_ToBeFinalized | BaseType::Flag_HasFinalize)) + 1;
                    const_cast<BaseType*>(proot)->Finalize_GC();
                    --proot->RefCount;
                    proot->SetState(BaseType::State_Root);
                }
            }
        }
        if (Roots.GetSize() == 0)
            break;
    }

    if (pstat)
    {
        pstat->RootsNumber = rootsNumber;
        if (rootsNumber < freed)
            freed = rootsNumber;
        pstat->RootsFreedTotal = freed;
        if (pobserver)
        {
            pobserver->SetRootsNumber(rootsNumber);
            pobserver->SetRootsFreedTotal(pstat->RootsFreedTotal);
        }
    }
    Flags &= ~Flags_InCollect;

    // release the Ptrs whose release was delayed during the collection
    Ptr<PtrReleaseProxy> pproxy = HeadDelayedPtrRelease;
    HeadDelayedPtrRelease = 0;
    if (pproxy)
    {
        Flags |= Flags_RequireMoreCollect;
        for (;;)
        {
            Ptr<PtrReleaseProxy> pnextProxy = pproxy->pNext;
            pproxy->pNext = 0;
            pproxy = pnextProxy;
            if (!pproxy)
                break;
        }
    }
    return true;
}

// Children of freed garbage: tag the pointer so the dying owner does not release it.
// @0x1423df410
template <int Stat>
void RefCountCollector<Stat>::KillChildCall(RefCountCollector*, const BaseType** pchild)
{
    *pchild = (const BaseType*)((UPInt)*pchild + 1);
}

template <int Stat>
void RefCountCollector<Stat>::MarkInCycleCall(RefCountCollector* prcc, const BaseType** pchild)
{
    --(*pchild)->RefCount;
    if (!(*pchild)->IsInList())
        prcc->AddToList(*pchild);
}

template <int Stat>
void RefCountCollector<Stat>::ScanInUseCall(RefCountCollector* prcc, const BaseType** pchild)
{
    ++(*pchild)->RefCount;
    if (!(*pchild)->IsInState(BaseType::State_InUse))
    {
        (*pchild)->SetState(BaseType::State_InUse);
        if ((*pchild)->IsInList())
            prcc->ReinsertToList(*pchild);
    }
}

template <int Stat>
void RefCountCollector<Stat>::ScanTempInUseCall(RefCountCollector* prcc, const BaseType** pchild)
{
    ++(*pchild)->RefCount;
    unsigned state = (*pchild)->GetState();
    if (state != BaseType::State_TempInUse && state != BaseType::State_InUse)
    {
        (*pchild)->SetState(BaseType::State_TempInUse);
        if ((*pchild)->IsInList())
            prcc->ReinsertToList(*pchild);
    }
}

template void ASCollector::AddRoot(const BaseType* root);
template bool ASCollector::Collect(Stats* pstat);
template void ASCollector::KillChildCall(ASCollector*, const BaseType** pchild);

} // namespace AS3

// @0x1423dce80
template <> void LogBase<LoadProcess>::LogParse(const char* pfmt, ...) const
{
    va_list args;
    va_start(args, pfmt);
    LoadProcess* process = (LoadProcess*)this;
    if (process->IsVerboseParse())
    {
        Log* log = process->GetLog();
        if (process->IsLogNotNull() || log)
            log->LogMessageVarg(LogChannel_Parse | LogMessage_Text, pfmt, args);
    }
    va_end(args);
}

namespace AS3 {

// @0x1423dcc50
// MS2-FUNCTIONAL: the executable uses a five-byte forwarding thunk to AvmDisplayObj::GetAbsolutePath.
const char* AvmInteractiveObj::GetAbsolutePath(String* ppath) const
{
    return AvmDisplayObj::GetAbsolutePath(ppath);
}

} // namespace AS3

}} // namespace Scaleform::GFx

// Non-RTTI interface and shared-base tables emitted by this SCU; addresses are from the exe's constructor stores.
// MS2-PIN: ??_7?$RefCountBase@VMemoryContext@GFx@Scaleform@@$01@Scaleform@@6B@ 0x14313c0a8
// MS2-PIN: ??_7MemoryContext@GFx@Scaleform@@6B@ 0x14313c0a8
// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68
// MS2-PIN: ??_7HeapLimit@MemoryContextImpl@AS3@GFx@Scaleform@@6B@ 0x14313c090
// MS2-PIN: ??_7MemoryContextImpl@AS3@GFx@Scaleform@@6B@ 0x14313c0a8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BAI@@Scaleform@@6B@ 0x14313c088
// MS2-PIN: ??_7?$RefCountBase@VAbcDataBuffer@AS3@GFx@Scaleform@@$0BAI@@Scaleform@@6B@ 0x14313c088
// MS2-PIN: ??_7AbcDataBuffer@AS3@GFx@Scaleform@@6B@ 0x14313c088
// MS2-PIN: ??_7DoAbc@AS3@GFx@Scaleform@@6B@ 0x14313c0b0
// MS2-PIN: ?ExecuteWithPriority@ExecuteTag@GFx@Scaleform@@UEAAXPEAVDisplayObjContainer@23@W4Priority@ActionPriority@23@@Z 0x1423dcc10
// MS2-PIN: ?Trace@ExecuteTag@GFx@Scaleform@@UEAAXPEBD@Z 0x1423dd510
