// Recovered Scaleform 4.1.18 kernel: container allocators (heap choice x construction policy).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//   *LH  allocate in the heap that owns the container ("local heap", AllocAutoHeap on the container address)
//   *GH  allocate in the global heap
//   *DH  allocate in an explicitly given heap
//   _POD raw copies, no ctor/dtor calls; (none) placement-construct and memmove relocation; _CPP element-wise copies
#ifndef MS2_SF_KERNEL_ALLOCATOR_H
#define MS2_SF_KERNEL_ALLOCATOR_H

#include "sf_memory.h"

namespace Scaleform {

template<class T> inline T* Construct(void* p)                    { return ::new(p) T; }
template<class T> inline T* Construct(void* p, const T& source)   { return ::new(p) T(source); }
template<class T, class S>
inline T* ConstructAlt(void* p, const S& source)                  { return ::new(p) T(source); }
template<class T, class S1, class S2>
inline T* ConstructAlt(void* p, const S1& src1, const S2& src2)   { return ::new(p) T(src1, src2); }

template<class T>
inline void ConstructArray(void* p, UPInt count)
{
    UByte* pdata = (UByte*)p;
    for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
        Construct<T>(pdata);
}
template<class T>
inline void ConstructArray(void* p, UPInt count, const T& source)
{
    UByte* pdata = (UByte*)p;
    for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
        Construct<T>(pdata, source);
}
template<class T> inline void Destruct(T* pobj) { SF_UNUSED(pobj); pobj->~T(); }
template<class T>
inline void DestructArray(T* pobj, UPInt count)
{
    for (UPInt i = 0; i < count; ++i, ++pobj)
        pobj->~T();
}

// ---- heap choice
template<int SID = Stat_Default_Mem>
class AllocatorBaseLH
{
public:
    enum { StatId = SID };
    static void* Alloc(const void* pheapAddr, UPInt size, const char*, unsigned)
    {
        return Memory::AllocAutoHeap(pheapAddr, size, AllocInfo(StatId, 0, 0));
    }
    static void* Realloc(void* p, UPInt newSize, const char*, unsigned) { return Memory::Realloc(p, newSize); }
    static void  Free(void* p) { Memory::Free(p); }
};

template<int SID = Stat_Default_Mem>
class AllocatorBaseDH
{
public:
    enum { StatId = SID };
    static void* Alloc(const void* pheap, UPInt size, const char*, unsigned)
    {
        return Memory::AllocInHeap((MemoryHeap*)pheap, size, AllocInfo(StatId, 0, 0));
    }
    static void* Realloc(void* p, UPInt newSize, const char*, unsigned) { return Memory::Realloc(p, newSize); }
    static void  Free(void* p) { Memory::Free(p); }
};

template<int SID = Stat_Default_Mem>
class AllocatorBaseGH
{
public:
    enum { StatId = SID };
    static void* Alloc(const void*, UPInt size, const char*, unsigned)
    {
        return Memory::Alloc(size, AllocInfo(StatId, 0, 0));
    }
    static void* Realloc(void* p, UPInt newSize, const char*, unsigned) { return Memory::Realloc(p, newSize); }
    static void  Free(void* p)
    {
        if (p)
            Memory::Free(p);
    }
};

// ---- construction policy
template<class T>
class ConstructorPOD
{
public:
    static void Construct(void*) {}
    static void Construct(void* p, const T& source) { *(T*)p = source; }
    template<class S>
    static void ConstructAlt(void* p, const S& source) { *(T*)p = source; }
    static void ConstructArray(void*, UPInt) {}
    static void ConstructArray(void* p, UPInt count, const T& source)
    {
        UByte* pdata = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
            *(T*)pdata = source;
    }
    static void ConstructArray(void* p, UPInt count, const T* psource) { memcpy(p, psource, sizeof(T) * count); }
    static void Destruct(T*) {}
    static void DestructArray(T*, UPInt) {}
    static void CopyArrayForward(T* dst, const T* src, UPInt count)  { memmove(dst, src, count * sizeof(T)); }
    static void CopyArrayBackward(T* dst, const T* src, UPInt count) { memmove(dst, src, count * sizeof(T)); }
    static bool IsMovable() { return true; }
};

template<class T>
class ConstructorMov
{
public:
    static void Construct(void* p) { ::new(p) T; }
    static void Construct(void* p, const T& source) { ::new(p) T(source); }
    template<class S>
    static void ConstructAlt(void* p, const S& source) { ::new(p) T(source); }
    static void ConstructArray(void* p, UPInt count)
    {
        UByte* pdata = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
            Construct(pdata);
    }
    static void ConstructArray(void* p, UPInt count, const T& source)
    {
        UByte* pdata = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
            Construct(pdata, source);
    }
    static void ConstructArray(void* p, UPInt count, const T* psource)
    {
        UByte* pdata = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
            Construct(pdata, *psource++);
    }
    static void Destruct(T* p)
    {
        p->~T();
        SF_UNUSED(p);
    }
    // Destroys back to front.
    static void DestructArray(T* p, UPInt count)
    {
        p += count - 1;
        for (UPInt i = 0; i < count; ++i, --p)
            p->~T();
    }
    static void CopyArrayForward(T* dst, const T* src, UPInt count)  { memmove(dst, src, count * sizeof(T)); }
    static void CopyArrayBackward(T* dst, const T* src, UPInt count) { memmove(dst, src, count * sizeof(T)); }
    static bool IsMovable() { return true; }
};

template<class T>
class ConstructorCPP
{
public:
    static void Construct(void* p) { ::new(p) T; }
    static void Construct(void* p, const T& source) { ::new(p) T(source); }
    template<class S>
    static void ConstructAlt(void* p, const S& source) { ::new(p) T(source); }
    static void ConstructArray(void* p, UPInt count)
    {
        UByte* pdata = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
            Construct(pdata);
    }
    static void ConstructArray(void* p, UPInt count, const T& source)
    {
        UByte* pdata = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
            Construct(pdata, source);
    }
    static void ConstructArray(void* p, UPInt count, const T* psource)
    {
        UByte* pdata = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, pdata += sizeof(T))
            Construct(pdata, *psource++);
    }
    static void Destruct(T* p)
    {
        p->~T();
        SF_UNUSED(p);
    }
    static void DestructArray(T* p, UPInt count)
    {
        p += count - 1;
        for (UPInt i = 0; i < count; ++i, --p)
            p->~T();
    }
    static void CopyArrayForward(T* dst, const T* src, UPInt count)
    {
        for (UPInt i = 0; i < count; ++i)
            dst[i] = src[i];
    }
    static void CopyArrayBackward(T* dst, const T* src, UPInt count)
    {
        for (UPInt i = count; i; --i)
            dst[i - 1] = src[i - 1];
    }
    static bool IsMovable() { return false; }
};

template<class T, int SID = Stat_Default_Mem> struct AllocatorGH_POD : AllocatorBaseGH<SID>, ConstructorPOD<T> {};
template<class T, int SID = Stat_Default_Mem> struct AllocatorGH     : AllocatorBaseGH<SID>, ConstructorMov<T> {};
template<class T, int SID = Stat_Default_Mem> struct AllocatorGH_CPP : AllocatorBaseGH<SID>, ConstructorCPP<T> {};
template<class T, int SID = Stat_Default_Mem> struct AllocatorLH_POD : AllocatorBaseLH<SID>, ConstructorPOD<T> {};
template<class T, int SID = Stat_Default_Mem> struct AllocatorLH     : AllocatorBaseLH<SID>, ConstructorMov<T> {};
template<class T, int SID = Stat_Default_Mem> struct AllocatorLH_CPP : AllocatorBaseLH<SID>, ConstructorCPP<T> {};
template<class T, int SID = Stat_Default_Mem> struct AllocatorDH_POD : AllocatorBaseDH<SID>, ConstructorPOD<T> {};
template<class T, int SID = Stat_Default_Mem> struct AllocatorDH     : AllocatorBaseDH<SID>, ConstructorMov<T> {};
template<class T, int SID = Stat_Default_Mem> struct AllocatorDH_CPP : AllocatorBaseDH<SID>, ConstructorCPP<T> {};

} // namespace Scaleform

#endif
