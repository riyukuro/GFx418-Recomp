// Recovered Scaleform GFx 4.1.18: system allocator interfaces (SysAllocBase -> SysAlloc for the MH heap, SysAllocPaged
// for the PT heap), the static-memory allocator, the in-place singleton helper and the page mapper interface.
#ifndef MS2_SF_KERNEL_SYSALLOC_H
#define MS2_SF_KERNEL_SYSALLOC_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform {

namespace Heap { class MemVisitor; class SegVisitor; }
namespace HeapPT { class AllocLite; }

class SysAllocBase
{
    friend class System;
protected:
    virtual ~SysAllocBase() { }
    virtual bool initHeapEngine(const void* heapDesc) { SF_UNUSED(heapDesc); return false; }
    virtual bool shutdownHeapEngine() { return true; }
};

class SysAlloc : public SysAllocBase
{
public:
    SysAlloc() { }
    virtual ~SysAlloc() { }
    virtual void* Alloc(UPInt size, UPInt align) = 0;
    virtual void  Free(void* ptr, UPInt size, UPInt align) = 0;
    virtual void* Realloc(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align) = 0;
protected:
    virtual bool initHeapEngine(const void* heapDesc);
    virtual bool shutdownHeapEngine();
};

class SysAllocPaged : public SysAllocBase
{
public:
    struct Info
    {
        UPInt MinAlign;
        UPInt MaxAlign;
        UPInt Granularity;
        UPInt SysDirectThreshold;
        UPInt MaxHeapGranularity;
        bool  HasRealloc;
    };

    SysAllocPaged() { }
    virtual void  GetInfo(Info* i) const = 0;
    virtual void* Alloc(UPInt size, UPInt align) = 0;
    virtual bool  Free(void* ptr, UPInt size, UPInt align) = 0;
    virtual bool  ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align)
    { SF_UNUSED4(oldPtr, oldSize, newSize, align); return false; }
    virtual void* AllocSysDirect(UPInt, UPInt, UPInt*, UPInt*) { return 0; }
    virtual bool  FreeSysDirect(void*, UPInt, UPInt) { return false; }
    virtual UPInt GetBase() const { return 0; }
    virtual UPInt GetSize() const { return 0; }
    virtual UPInt GetFootprint() const { return 0; }
    virtual UPInt GetUsedSpace() const { return 0; }
    virtual void  VisitMem(Heap::MemVisitor*) const { }
    virtual void  VisitSegments(Heap::SegVisitor*, UPInt, UPInt) const { }
    virtual ~SysAllocPaged() { }
protected:
    virtual bool initHeapEngine(const void* heapDesc);
    virtual bool shutdownHeapEngine();
};

// Up to four caller-supplied memory blocks managed by an AllocLite engine kept in PrivateData.
class SysAllocStatic : public SysAllocPaged
{
public:
    enum { MaxSegments = 4 };
    SF_EXPORT SysAllocStatic(void* mem1 = 0, UPInt size1 = 0, void* mem2 = 0, UPInt size2 = 0,
                             void* mem3 = 0, UPInt size3 = 0, void* mem4 = 0, UPInt size4 = 0);
    SysAllocStatic(UPInt minSize);
    void AddMemSegment(void* mem, UPInt size);

    virtual void  GetInfo(Info* i) const;
    virtual void* Alloc(UPInt size, UPInt align);
    virtual bool  ReallocInPlace(void* oldPtr, UPInt oldSize, UPInt newSize, UPInt align);
    virtual bool  Free(void* ptr, UPInt size, UPInt align);
    virtual void  VisitMem(Heap::MemVisitor* visitor) const;
    virtual UPInt GetFootprint() const;
    virtual UPInt GetUsedSpace() const;
    virtual UPInt GetBase() const;
    virtual UPInt GetSize() const;
private:
    UPInt              MinSize;
    UPInt              NumSegments;
    HeapPT::AllocLite* pAllocator;
    UPInt              PrivateData[8];
    UPInt              Segments[MaxSegments][8];
    UPInt              TotalSpace;
};

// Builds the allocator A (derived from B) in static storage the first time it is asked for, and destroys it in place
// when the heap engine shuts down.
template<class A, class B>
class SysAllocBase_SingletonSupport : public B
{
    struct SysAllocContainer
    {
        UPInt Data[(sizeof(A) + sizeof(UPInt) - 1) / sizeof(UPInt)];
        bool  Initialized;
        SysAllocContainer() : Initialized(0) { }
    };
    SysAllocContainer* pContainer;
public:
    SysAllocBase_SingletonSupport() : pContainer(0) { }
    static B* InitSystemSingleton()
    {
        static SysAllocContainer Container;
        SysAllocBase_SingletonSupport<A, B>* r = ::new((void*)Container.Data) A;
        r->pContainer = &Container;
        Container.Initialized = true;
        return r;
    }
protected:
    virtual bool shutdownHeapEngine()
    {
        bool noLeaks = B::shutdownHeapEngine();
        if (pContainer)
        {
            pContainer->Initialized = false;
            ((B*)this)->~B();
            pContainer = 0;
        }
        return noLeaks;
    }
};

class SysMemMapper
{
public:
    virtual UPInt GetPageSize() const = 0;
    virtual void* ReserveAddrSpace(UPInt size) = 0;
    virtual bool  ReleaseAddrSpace(void* ptr, UPInt size) = 0;
    virtual void* MapPages(void* ptr, UPInt size) = 0;
    virtual bool  UnmapPages(void* ptr, UPInt size) = 0;
    virtual ~SysMemMapper() { }
};

}  // namespace Scaleform

#endif
