// Recovered Scaleform GFx 4.1.18: container allocators. An allocator = heap policy (GH: global heap, LH: the heap that
// owns a given address, DH: an explicit heap) + construction policy (POD: raw copies, Mov: constructed in place and
// moved with memmove, CPP: constructed in place and moved with operator=).
#ifndef MS2_SF_KERNEL_ALLOCATOR_H
#define MS2_SF_KERNEL_ALLOCATOR_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include <string.h>

namespace Scaleform {

template<class T> SF_INLINE T* Construct(void* p) { return ::new(p) T; }
template<class T> SF_INLINE T* Construct(void* p, const T& src) { return ::new(p) T(src); }
template<class T, class S> SF_INLINE T* ConstructAlt(void* p, const S& src) { return ::new(p) T(src); }
template<class T, class S1, class S2>
SF_INLINE T* ConstructAlt(void* p, const S1& a, const S2& b) { return ::new(p) T(a, b); }
template<class T> SF_INLINE void ConstructArray(void* p, UPInt count)
{
    UByte* d = (UByte*)p;
    for (UPInt i = 0; i < count; ++i, d += sizeof(T))
        Construct<T>(d);
}
template<class T> SF_INLINE void ConstructArray(void* p, UPInt count, const T& src)
{
    UByte* d = (UByte*)p;
    for (UPInt i = 0; i < count; ++i, d += sizeof(T))
        Construct<T>(d, src);
}
template<class T> SF_INLINE void Destruct(T* p) { SF_UNUSED(p); p->~T(); }
template<class T> SF_INLINE void DestructArray(T* p, UPInt count)
{
    for (UPInt i = 0; i < count; ++i, ++p)
        p->~T();
}

// ---- heap policies ----
template<int SID = Stat_Default_Mem>
class AllocatorBaseLH
{
public:
    enum { StatId = SID };
    static void* Alloc(const void* heapAddr, UPInt size, const char*, unsigned)
    { return Memory::AllocAutoHeap(heapAddr, size, AllocInfo(StatId, 0, 0)); }
    static void* Realloc(void* p, UPInt newSize, const char*, unsigned) { return Memory::Realloc(p, newSize); }
    static void Free(void* p) { Memory::Free(p); }
};

template<int SID = Stat_Default_Mem>
class AllocatorBaseDH
{
public:
    enum { StatId = SID };
    static void* Alloc(const void* heap, UPInt size, const char*, unsigned)
    { return Memory::AllocInHeap((MemoryHeap*)heap, size, AllocInfo(StatId, 0, 0)); }
    static void* Realloc(void* p, UPInt newSize, const char*, unsigned) { return Memory::Realloc(p, newSize); }
    static void Free(void* p) { Memory::Free(p); }
};

template<int SID = Stat_Default_Mem>
class AllocatorBaseGH
{
public:
    enum { StatId = SID };
    static void* Alloc(const void*, UPInt size, const char*, unsigned)
    { return Memory::Alloc(size, AllocInfo(StatId, 0, 0)); }
    static void* Realloc(void* p, UPInt newSize, const char*, unsigned) { return Memory::Realloc(p, newSize); }
    static void Free(void* p)
    {
        if (p)
            Memory::Free(p);
    }
};

// ---- construction policies ----
template<class T>
class ConstructorPOD
{
public:
    static void Construct(void*) { }
    static void Construct(void* p, const T& src) { *(T*)p = src; }
    template<class S> static void ConstructAlt(void* p, const S& src) { *(T*)p = src; }
    static void ConstructArray(void*, UPInt) { }
    static void ConstructArray(void* p, UPInt count, const T& src)
    {
        UByte* d = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, d += sizeof(T))
            *(T*)d = src;
    }
    static void ConstructArray(void* p, UPInt count, const T* src) { memcpy(p, src, sizeof(T) * count); }
    static void Destruct(T*) { }
    static void DestructArray(T*, UPInt) { }
    static void CopyArrayForward(T* dst, const T* src, UPInt count) { memmove(dst, src, count * sizeof(T)); }
    static void CopyArrayBackward(T* dst, const T* src, UPInt count) { memmove(dst, src, count * sizeof(T)); }
    static bool IsMovable() { return true; }
};

template<class T>
class ConstructorMov
{
public:
    static void Construct(void* p) { ::new(p) T; }
    static void Construct(void* p, const T& src) { ::new(p) T(src); }
    template<class S> static void ConstructAlt(void* p, const S& src) { ::new(p) T(src); }
    static void ConstructArray(void* p, UPInt count)
    {
        UByte* d = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, d += sizeof(T))
            Construct(d);
    }
    static void ConstructArray(void* p, UPInt count, const T& src)
    {
        UByte* d = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, d += sizeof(T))
            Construct(d, src);
    }
    static void ConstructArray(void* p, UPInt count, const T* src)
    {
        UByte* d = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, d += sizeof(T))
            Construct(d, *src++);
    }
    static void Destruct(T* p) { p->~T(); SF_UNUSED(p); }
    static void DestructArray(T* p, UPInt count)
    {
        p += count - 1;
        for (UPInt i = 0; i < count; ++i, --p)
            p->~T();
    }
    static void CopyArrayForward(T* dst, const T* src, UPInt count) { memmove(dst, src, count * sizeof(T)); }
    static void CopyArrayBackward(T* dst, const T* src, UPInt count) { memmove(dst, src, count * sizeof(T)); }
    static bool IsMovable() { return true; }
};

template<class T>
class ConstructorCPP
{
public:
    static void Construct(void* p) { ::new(p) T; }
    static void Construct(void* p, const T& src) { ::new(p) T(src); }
    template<class S> static void ConstructAlt(void* p, const S& src) { ::new(p) T(src); }
    static void ConstructArray(void* p, UPInt count)
    {
        UByte* d = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, d += sizeof(T))
            Construct(d);
    }
    static void ConstructArray(void* p, UPInt count, const T& src)
    {
        UByte* d = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, d += sizeof(T))
            Construct(d, src);
    }
    static void ConstructArray(void* p, UPInt count, const T* src)
    {
        UByte* d = (UByte*)p;
        for (UPInt i = 0; i < count; ++i, d += sizeof(T))
            Construct(d, *src++);
    }
    static void Destruct(T* p) { p->~T(); SF_UNUSED(p); }
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

template<class T, int SID = Stat_Default_Mem> struct AllocatorGH_POD : AllocatorBaseGH<SID>, ConstructorPOD<T> { };
template<class T, int SID = Stat_Default_Mem> struct AllocatorGH     : AllocatorBaseGH<SID>, ConstructorMov<T> { };
template<class T, int SID = Stat_Default_Mem> struct AllocatorGH_CPP : AllocatorBaseGH<SID>, ConstructorCPP<T> { };
template<class T, int SID = Stat_Default_Mem> struct AllocatorLH_POD : AllocatorBaseLH<SID>, ConstructorPOD<T> { };
template<class T, int SID = Stat_Default_Mem> struct AllocatorLH     : AllocatorBaseLH<SID>, ConstructorMov<T> { };
template<class T, int SID = Stat_Default_Mem> struct AllocatorLH_CPP : AllocatorBaseLH<SID>, ConstructorCPP<T> { };
template<class T, int SID = Stat_Default_Mem> struct AllocatorDH_POD : AllocatorBaseDH<SID>, ConstructorPOD<T> { };
template<class T, int SID = Stat_Default_Mem> struct AllocatorDH     : AllocatorBaseDH<SID>, ConstructorMov<T> { };
template<class T, int SID = Stat_Default_Mem> struct AllocatorDH_CPP : AllocatorBaseDH<SID>, ConstructorCPP<T> { };

}  // namespace Scaleform

#endif
