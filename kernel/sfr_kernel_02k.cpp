// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapMH_AllocEngine (the per-heap
// MH engine: small blocks from 4 KB pages through the bit-set allocator, larger ones straight from the SysAlloc with a
// NodeMH trailer in the global tree; the heap limit handler is called with the global lock released).
// Our own source, written from the exe. Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426406e0-0x142641be0 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_allocengine.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_root.h"
#include <string.h>

namespace Scaleform { namespace HeapMH {

AllocEngineMH::AllocEngineMH(SysAlloc* sysAlloc, MemoryHeapMH* heap, UPInt minAlignSize, UPInt limit)
    : pSysAlloc(sysAlloc), pHeap(heap), MinAlignSize((minAlignSize < sizeof(void*)) ? sizeof(void*) : minAlignSize),
      Allocator(), Pages(), Footprint(0), UsedSpace(0), Limit(limit), pLimHandler(0), UseCount(0)
{
}

AllocEngineMH::~AllocEngineMH()
{
    FreeAll();
}

// pages go back to the root with their last block, so there is nothing left to release here
void AllocEngineMH::FreeAll()
{
}

PageMH* AllocEngineMH::allocPageUnlocked(bool* limHandlerOK)
{
    if (Limit && Footprint + PageMH::PageSize > Limit && pLimHandler)
    {
        *limHandlerOK = ((MemoryHeap::LimitHandler*)pLimHandler)->
                        OnExceedLimit(pHeap, Footprint + PageMH::PageSize - Limit);
        return 0;
    }
    *limHandlerOK = false;
    LockSafe::Locker lock(GlobalRootMH->GetLock());
    PageMH* page = GlobalRootMH->AllocPage(pHeap);
    if (page)
    {
        UInt32 index = GlobalRootMH->GetPageIndex(page);
        Allocator.InitPage(page, index);
        Footprint += PageMH::PageSize;
        Pages.PushFront(page);
        *limHandlerOK = true;
    }
    return page;
}

// the caller holds the root lock; the limit handler runs with it released
PageMH* AllocEngineMH::allocPageLocked(bool* limHandlerOK)
{
    if (Limit && Footprint + PageMH::PageSize > Limit && pLimHandler)
    {
        LockSafe::TmpUnlocker unlocker(GlobalRootMH->GetLock());
        *limHandlerOK = ((MemoryHeap::LimitHandler*)pLimHandler)->
                        OnExceedLimit(pHeap, Footprint + PageMH::PageSize - Limit);
        return 0;
    }
    *limHandlerOK = false;
    PageMH* page = GlobalRootMH->AllocPage(pHeap);
    if (page)
    {
        UInt32 index = GlobalRootMH->GetPageIndex(page);
        Allocator.InitPage(page, index);
        Footprint += PageMH::PageSize;
        Pages.PushFront(page);
        *limHandlerOK = true;
    }
    return page;
}

void AllocEngineMH::freePage(PageMH* page, bool globalLocked)
{
    if (globalLocked)
    {
        Allocator.ReleasePage(page->Start);
        PageListType::Remove(page);
        GlobalRootMH->FreePage(page);
    }
    else
    {
        LockSafe::Locker lock(GlobalRootMH->GetLock());
        Allocator.ReleasePage(page->Start);
        PageListType::Remove(page);
        GlobalRootMH->FreePage(page);
    }
    Footprint -= PageMH::PageSize;
}

// retry while a new page could be added (or the limit handler made room)
void* AllocEngineMH::allocFromPage(UPInt size, PageInfoMH* info, bool globalLocked)
{
    void* ptr;
    MagicHeadersInfo headers;
    bool limHandlerOK = false;
    do
    {
        ptr = Allocator.Alloc(size, &headers);
        if (ptr)
        {
            if (headers.Header1)
                headers.Header1->UseCount++;
            if (headers.Header2)
                headers.Header2->UseCount++;
            info->UsableSize = size;
            info->Page       = headers.Page;
            info->Node       = 0;
            ++UseCount;
            UsedSpace += size;
            return ptr;
        }
        if (globalLocked)
            allocPageLocked(&limHandlerOK);
        else
            allocPageUnlocked(&limHandlerOK);
    } while (limHandlerOK);
    return 0;
}

void* AllocEngineMH::allocFromPage(UPInt size, UPInt alignSize, PageInfoMH* info, bool globalLocked)
{
    void* ptr;
    MagicHeadersInfo headers;
    bool limHandlerOK = false;
    do
    {
        ptr = Allocator.Alloc(size, alignSize, &headers);
        if (ptr)
        {
            if (headers.Header1)
                headers.Header1->UseCount++;
            if (headers.Header2)
                headers.Header2->UseCount++;
            info->UsableSize = size;
            info->Page       = headers.Page;
            info->Node       = 0;
            ++UseCount;
            UsedSpace += size;
            return ptr;
        }
        if (globalLocked)
            allocPageLocked(&limHandlerOK);
        else
            allocPageUnlocked(&limHandlerOK);
    } while (limHandlerOK);
    return 0;
}

void AllocEngineMH::Free(PageMH* page, void* ptr, bool globalLocked)
{
    MagicHeadersInfo headers;
    UPInt oldSize;
    Allocator.Free(page, ptr, &headers, &oldSize);
    unsigned useCount = 0;
    UsedSpace -= oldSize;
    if (headers.Header1)
        useCount = --headers.Header1->UseCount;
    if (headers.Header2)
        useCount = --headers.Header2->UseCount;
    if (useCount == 0)
        freePage(page, globalLocked);
    --UseCount;
}

void AllocEngineMH::Free(NodeMH* node, void* ptr, bool)
{
    GlobalRootMH->RemoveFromGlobalTree(node);
    UPInt align    = node->GetAlign();
    UPInt nodeSize = NodeMH::GetNodeSize(align);
    UPInt size     = (UByte*)node - (UByte*)ptr + nodeSize;
    --UseCount;
    Footprint -= size;
    UsedSpace -= size - nodeSize;
    pSysAlloc->Free(ptr, size, align);
}

void AllocEngineMH::Free(void* ptr, bool globalLocked)
{
    PageMH* page = GlobalRootMH->ResolveAddress(UPInt(ptr));
    if (page)
    {
        Free(page, ptr, globalLocked);
    }
    else if (globalLocked)
    {
        LockSafe::Locker lock(GlobalRootMH->GetLock());
        NodeMH* node = GlobalRootMH->FindNodeInGlobalTree((UByte*)ptr);
        Free(node, ptr, true);
    }
    else
    {
        NodeMH* node = GlobalRootMH->FindNodeInGlobalTree((UByte*)ptr);
        Free(node, ptr, false);
    }
}

void AllocEngineMH::GetPageInfo(PageMH* page, PageInfoMH* info) const
{
    memset(info, 0, sizeof(PageInfoMH));
    info->UsableSize = 0;
    info->Page       = page;
}

void AllocEngineMH::GetPageInfo(NodeMH* node, PageInfoMH* info) const
{
    memset(info, 0, sizeof(PageInfoMH));
    info->UsableSize = 0;
    info->Node       = node;
}

void AllocEngineMH::GetPageInfoWithSize(PageMH* page, const void* ptr, PageInfoMH* info) const
{
    memset(info, 0, sizeof(PageInfoMH));
    info->UsableSize = Allocator.GetUsableSize(page, ptr);
    info->Page       = page;
}

void AllocEngineMH::GetPageInfoWithSize(NodeMH* node, const void* ptr, PageInfoMH* info) const
{
    memset(info, 0, sizeof(PageInfoMH));
    info->UsableSize = (UByte*)node - (UByte*)ptr;
    info->Node       = node;
}

void* AllocEngineMH::allocDirect(UPInt size, UPInt alignSize, bool* limHandlerOK, PageInfoMH* info)
{
    size = (size + sizeof(void*) - 1) & ~UPInt(sizeof(void*) - 1);
    UPInt nodeSize = NodeMH::GetNodeSize(alignSize);
    if (Limit && Footprint + size + nodeSize > Limit && pLimHandler)
    {
        LockSafe::TmpUnlocker unlocker(GlobalRootMH->GetLock());
        *limHandlerOK = ((MemoryHeap::LimitHandler*)pLimHandler)->
                        OnExceedLimit(pHeap, Footprint + size + nodeSize - Limit);
        return 0;
    }
    *limHandlerOK = false;
    void* ptr = pSysAlloc->Alloc(size + nodeSize, alignSize);
    if (ptr)
    {
        NodeMH* node = GlobalRootMH->AddToGlobalTree((UByte*)ptr, size, alignSize, pHeap);
        info->UsableSize = size;
        info->Page       = 0;
        info->Node       = node;
        ++UseCount;
        Footprint += size + nodeSize;
        UsedSpace += size;
        *limHandlerOK = true;
    }
    return ptr;
}

void* AllocEngineMH::Alloc(UPInt size, PageInfoMH* info, bool globalLocked)
{
    if (MinAlignSize > PageMH::UnitSize)
        return Alloc(size, MinAlignSize, info, globalLocked);
    if (size <= PageMH::MaxBytes)
    {
        size = (size + PageMH::UnitMask) & ~UPInt(PageMH::UnitMask);
        return allocFromPage(size, info, globalLocked);
    }

    void* ptr = 0;
    if (globalLocked)
    {
        bool limHandlerOK = false;
        do
        {
            ptr = allocDirect(size, MinAlignSize, &limHandlerOK, info);
            if (ptr)
                return ptr;
        } while (limHandlerOK);
    }
    else
    {
        LockSafe::Locker lock(GlobalRootMH->GetLock());
        bool limHandlerOK = false;
        do
        {
            ptr = allocDirect(size, MinAlignSize, &limHandlerOK, info);
            if (ptr)
                return ptr;
        } while (limHandlerOK);
    }
    return ptr;
}

void* AllocEngineMH::Alloc(UPInt size, UPInt alignSize, PageInfoMH* info, bool globalLocked)
{
    if (size <= PageMH::MaxBytes)
    {
        if (alignSize < PageMH::UnitSize)
            alignSize = PageMH::UnitSize;
        size = (size + PageMH::UnitMask) & ~UPInt(PageMH::UnitMask);
        return allocFromPage(size, alignSize, info, globalLocked);
    }

    if (alignSize < sizeof(void*))
        alignSize = sizeof(void*);
    if (size < alignSize)
        size = alignSize;
    size = (size + sizeof(void*) - 1) & ~UPInt(sizeof(void*) - 1);
    void* ptr = 0;
    if (globalLocked)
    {
        bool limHandlerOK = false;
        do
        {
            ptr = allocDirect(size, alignSize, &limHandlerOK, info);
            if (ptr)
                return ptr;
        } while (limHandlerOK);
    }
    else
    {
        LockSafe::Locker lock(GlobalRootMH->GetLock());
        bool limHandlerOK = false;
        do
        {
            ptr = allocDirect(size, alignSize, &limHandlerOK, info);
            if (ptr)
                return ptr;
        } while (limHandlerOK);
    }
    return ptr;
}

// blocks stay in their page (the bit-set allocator grows or shrinks them in place) up to half a page
void* AllocEngineMH::ReallocInPage(PageMH* page, void* oldPtr, UPInt newSize, PageInfoMH* newInfo, bool)
{
    void* newPtr = 0;
    if (newSize < PageMH::PageSize / 2)
    {
        newSize = (newSize + PageMH::UnitMask) & ~UPInt(PageMH::UnitMask);
        MagicHeadersInfo headers;
        UPInt oldSize;
        newPtr = Allocator.ReallocInPlace(page, oldPtr, newSize, &oldSize, &headers);
        if (newPtr)
        {
            newInfo->UsableSize = newSize;
            newInfo->Page       = headers.Page;
            newInfo->Node       = 0;
            UsedSpace -= oldSize;
            UsedSpace += newSize;
        }
    }
    return newPtr;
}

// the caller holds the root lock; the node leaves the global tree while the SysAlloc moves the block
void* AllocEngineMH::reallocInNodeNoLock(NodeMH* node, void* oldPtr, UPInt newSize, PageInfoMH* newInfo)
{
    void* newPtr   = 0;
    UPInt oldAlign = node->GetAlign();
    UPInt nodeSize = NodeMH::GetNodeSize(oldAlign);
    UPInt oldSize  = (UByte*)node - (UByte*)oldPtr + nodeSize;
    newSize  = (newSize + sizeof(void*) - 1) & ~UPInt(sizeof(void*) - 1);
    newSize += nodeSize;
    if (newSize > oldSize)
    {
        while (Limit && Footprint + newSize - oldSize > Limit && pLimHandler)
        {
            LockSafe::TmpUnlocker unlocker(GlobalRootMH->GetLock());
            bool limHandlerOK = ((MemoryHeap::LimitHandler*)pLimHandler)->
                                OnExceedLimit(pHeap, Footprint + newSize - oldSize - Limit);
            if (!limHandlerOK)
                return 0;
        }
    }
    GlobalRootMH->RemoveFromGlobalTree(node);
    newPtr = pSysAlloc->Realloc(oldPtr, oldSize, newSize, oldAlign);
    if (newPtr)
    {
        NodeMH* newNode = GlobalRootMH->AddToGlobalTree((UByte*)newPtr, newSize - nodeSize, oldAlign, pHeap);
        newInfo->UsableSize = newSize - nodeSize;
        newInfo->Page       = 0;
        newInfo->Node       = newNode;
        Footprint -= oldSize;
        Footprint += newSize;
        UsedSpace -= oldSize - nodeSize;
        UsedSpace += newSize - nodeSize;
    }
    else
    {
        GlobalRootMH->AddToGlobalTree((UByte*)oldPtr, oldSize - nodeSize, oldAlign, pHeap);
    }
    return newPtr;
}

void* AllocEngineMH::ReallocInNode(NodeMH* node, void* oldPtr, UPInt newSize, PageInfoMH* newInfo, bool globalLocked)
{
    newSize = (newSize + sizeof(void*) - 1) & ~UPInt(sizeof(void*) - 1);
    if (!globalLocked)
    {
        LockSafe::Locker lock(GlobalRootMH->GetLock());
        return reallocInNodeNoLock(node, oldPtr, newSize, newInfo);
    }
    return reallocInNodeNoLock(node, oldPtr, newSize, newInfo);
}

// move the block to a new allocation of this engine
void* AllocEngineMH::ReallocGeneral(PageMH* page, void* oldPtr, UPInt newSize, PageInfoMH* newInfo, bool globalLocked)
{
    PageInfoMH oldInfo;
    void* newPtr = Alloc(newSize, newInfo, globalLocked);
    if (newPtr)
    {
        GetPageInfoWithSize(page, oldPtr, &oldInfo);
        memcpy(newPtr, oldPtr, (oldInfo.UsableSize < newInfo->UsableSize) ? oldInfo.UsableSize : newInfo->UsableSize);
        Free(page, oldPtr, globalLocked);
    }
    return newPtr;
}

void* AllocEngineMH::Realloc(void* oldPtr, UPInt newSize, bool globalLocked)
{
    PageInfoMH newInfo;
    PageMH* page = GlobalRootMH->ResolveAddress(UPInt(oldPtr));
    if (page)
        return ReallocGeneral(page, oldPtr, newSize, &newInfo, globalLocked);
    LockSafe::Locker lock(GlobalRootMH->GetLock());
    NodeMH* node = GlobalRootMH->FindNodeInGlobalTree((UByte*)oldPtr);
    return ReallocInNode(node, oldPtr, newSize, &newInfo, globalLocked);
}

UPInt AllocEngineMH::GetUsableSize(void* ptr)
{
    PageMH* page = GlobalRootMH->ResolveAddress(UPInt(ptr));
    if (page)
        return Allocator.GetUsableSize(page, ptr);
    LockSafe::Locker lock(GlobalRootMH->GetLock());
    NodeMH* node = GlobalRootMH->FindNodeInGlobalTree((UByte*)ptr);
    return (UByte*)node - (UByte*)ptr;
}

}}  // namespace Scaleform::HeapMH
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0AllocEngineMH@HeapMH@Scaleform@@QEAA@PEAVSysAlloc@2@PEAVMemoryHeapMH@2@_K2@Z 0x1426406e0
// MS2-PIN: ?AddToGlobalTree@RootMH@HeapMH@Scaleform@@QEAAPEAUNodeMH@23@PEAE_K1PEAVMemoryHeapMH@3@@Z 0x142640760
// MS2-PIN: ?Alloc@AllocEngineMH@HeapMH@Scaleform@@QEAAPEAX_K0PEAUPageInfoMH@23@_N@Z 0x142640810
// MS2-PIN: ?Alloc@AllocEngineMH@HeapMH@Scaleform@@QEAAPEAX_KPEAUPageInfoMH@23@_N@Z 0x1426409d0
// MS2-PIN: ?Free@AllocEngineMH@HeapMH@Scaleform@@QEAAXPEAUNodeMH@23@PEAX_N@Z 0x142640ce0
// MS2-PIN: ?Free@AllocEngineMH@HeapMH@Scaleform@@QEAAXPEAUPageMH@23@PEAX_N@Z 0x142640d80
// MS2-PIN: ?Free@AllocEngineMH@HeapMH@Scaleform@@QEAAXPEAX_N@Z 0x142640ea0
// MS2-PIN: ??1AllocEngineMH@HeapMH@Scaleform@@QEAA@XZ 0x142640f70
// MS2-PIN: ?GetPageInfoWithSize@AllocEngineMH@HeapMH@Scaleform@@QEBAXPEAUNodeMH@23@PEBXPEAUPageInfoMH@23@@Z 0x142640fa0
// MS2-PIN: ?GetPageInfoWithSize@AllocEngineMH@HeapMH@Scaleform@@QEBAXPEAUPageMH@23@PEBXPEAUPageInfoMH@23@@Z 0x142640fc0
// MS2-PIN: ?GetUsableSize@AllocEngineMH@HeapMH@Scaleform@@QEAA_KPEAX@Z 0x142641000
// MS2-PIN: ?Realloc@AllocEngineMH@HeapMH@Scaleform@@QEAAPEAXPEAX_K_N@Z 0x142641090
// MS2-PIN: ?ReallocGeneral@AllocEngineMH@HeapMH@Scaleform@@QEAAPEAXPEAUPageMH@23@PEAX_KPEAUPageInfoMH@23@_N@Z 0x1426411e0
// MS2-PIN: ?ReallocInNode@AllocEngineMH@HeapMH@Scaleform@@QEAAPEAXPEAUNodeMH@23@PEAX_KPEAUPageInfoMH@23@_N@Z 0x142641280
// MS2-PIN: ?ReallocInPage@AllocEngineMH@HeapMH@Scaleform@@QEAAPEAXPEAUPageMH@23@PEAX_KPEAUPageInfoMH@23@_N@Z 0x142641320
// MS2-PIN: ?RemoveFromGlobalTree@RootMH@HeapMH@Scaleform@@QEAAXPEAUNodeMH@23@@Z 0x1426413b0
// MS2-PIN: ?allocDirect@AllocEngineMH@HeapMH@Scaleform@@AEAAPEAX_K0PEA_NPEAUPageInfoMH@23@@Z 0x142641470
// MS2-PIN: ?allocFromPage@AllocEngineMH@HeapMH@Scaleform@@AEAAPEAX_K0PEAUPageInfoMH@23@_N@Z 0x1426415a0
// MS2-PIN: ?allocFromPage@AllocEngineMH@HeapMH@Scaleform@@AEAAPEAX_KPEAUPageInfoMH@23@_N@Z 0x142641680
// MS2-PIN: ?allocPageLocked@AllocEngineMH@HeapMH@Scaleform@@AEAAPEAUPageMH@23@PEA_N@Z 0x142641750
// MS2-PIN: ?allocPageUnlocked@AllocEngineMH@HeapMH@Scaleform@@AEAAPEAUPageMH@23@PEA_N@Z 0x142641860
// MS2-PIN: ?freePage@AllocEngineMH@HeapMH@Scaleform@@AEAAXPEAUPageMH@23@_N@Z 0x142641970
// MS2-PIN: ?reallocInNodeNoLock@AllocEngineMH@HeapMH@Scaleform@@AEAAPEAXPEAUNodeMH@23@PEAX_KPEAUPageInfoMH@23@@Z 0x142641a30
// MS2-PIN: ?GetPageInfo@AllocEngineMH@HeapMH@Scaleform@@QEBAXPEAUNodeMH@23@PEAUPageInfoMH@23@@Z 0x142640f80
// MS2-PIN: ?GetPageInfo@AllocEngineMH@HeapMH@Scaleform@@QEBAXPEAUPageMH@23@PEAUPageInfoMH@23@@Z 0x142640f90
