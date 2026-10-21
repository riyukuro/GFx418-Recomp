// Recovered Scaleform GFx 4.1.18: a bump allocator over an in-object buffer that falls back to the heap once the
// buffer is used up (MsgFormat keeps its formatters in one). Freeing only returns heap blocks.
#ifndef MS2_SF_KERNEL_STACKMEMPOOL_H
#define MS2_SF_KERNEL_STACKMEMPOOL_H

#include "ms2/scaleform/kernel/sf_memory.h"

namespace Scaleform {

// heap blocks are freed one by one as the pool frees them
struct MemPoolImmediateFree
{
    MemPoolImmediateFree(MemoryHeap* pheap) : pHeap(pheap) { }
    void* Alloc(UPInt nbytes, UPInt align)
    {
        return pHeap ? Memory::AllocInHeap(pHeap, nbytes, align) : Memory::Alloc(nbytes, align);
    }
    void Free(void* p) { Memory::Free(p); }

private:
    MemoryHeap* pHeap;
};

template<UPInt N = 512, UPInt A = sizeof(void*), class AFP = MemPoolImmediateFree>
class StackMemPool : AFP
{
public:
    StackMemPool(MemoryHeap* pheap = 0)
        : AFP(pheap), BuffPtr(AlignMem(Buff)), BuffSize(BuffMaxSize - (BuffPtr - Buff))
    {
    }

    void* Alloc(UPInt nbytes)
    {
        void* p = 0;
        if (nbytes <= BuffSize)
        {
            p = BuffPtr;
            BuffPtr = AlignMem(BuffPtr + nbytes);
            const UPInt used = BuffPtr - Buff;
            BuffSize = BuffMaxSize > used ? BuffMaxSize - used : 0;
        }
        else
        {
            p = AFP::Alloc(nbytes, Align);
        }
        return p;
    }
    void Free(void* p)
    {
        if (!(p >= Buff && p < Buff + BuffMaxSize))
            AFP::Free(p);
    }

private:
    // next A-aligned address at or after offset
    static char* AlignMem(char* offset) { return reinterpret_cast<char*>(A + ((reinterpret_cast<UPInt>(offset) - 1) & ~(A - 1))); }

    enum { BuffMaxSize = N, Align = A };
    char  Buff[BuffMaxSize];
    char* BuffPtr;
    UPInt BuffSize;
};

}  // namespace Scaleform

template<Scaleform::UPInt N, Scaleform::UPInt A>
inline void* operator new(Scaleform::UPInt nbytes, Scaleform::StackMemPool<N, A>& pool)
{
    return pool.Alloc(nbytes);
}
template<Scaleform::UPInt N, Scaleform::UPInt A>
inline void operator delete(void* p, Scaleform::StackMemPool<N, A>& pool)
{
    pool.Free(p);
}

#endif
