// Recovered Scaleform GFx 4.1.18 Kernel: ArrayStaticBuff<T, N>, an array that keeps its first N elements in the
// object and moves to the heap past them (the AS3 event dispatch keeps the display parent chain in an
// ArrayStaticBuff<SPtr<DisplayObject>, 32>; destructor 0x1424621c0). In-object elements live as long as the array;
// heap slots are constructed when the heap block grows and destroyed when it goes. (The POD variant of the render
// units lives in ms2/scaleform/kernel/sf_arraystaticbuff.h.)
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_INCLUDE_KERNEL_ARRAYSTATICBUFF_H
#define MS2_SF_INCLUDE_KERNEL_ARRAYSTATICBUFF_H

#include <string.h>
#include "sf_memory.h"
#include "sf_allocator.h"

namespace Scaleform {

template<class T, unsigned N, int SID = Stat_Default_Mem>
class ArrayStaticBuff
{
public:
    ArrayStaticBuff(MemoryHeap* heap = 0) : pHeap(heap), Size(0), Reserved(N), Data(Static) {}
    ~ArrayStaticBuff() { Clear(); }

    // Back to the in-object storage. The heap block's elements are destroyed with it (the in-object ones are not).
    void Clear()
    {
        if (Data != Static)
        {
            DestructArray(Data, Size);
            Memory::Free(Data);
        }
        Data = Static;
        Size = 0;
    }

    UPInt GetSize() const { return Size; }

    T&       operator[](UPInt i)       { return Data[i]; }
    const T& operator[](UPInt i) const { return Data[i]; }

    void PushBack(const T& v)
    {
        T* p;
        if (Size < N)
            p = &Static[Size];
        else
        {
            if (Size == N)
            {
                // the in-object elements are copied bitwise to the new heap block
                Reserved *= 2;
                Data = (T*)(pHeap ? Memory::AllocInHeap(pHeap, Reserved * sizeof(T))
                                  : Memory::AllocAutoHeap(this, Reserved * sizeof(T)));
                memcpy(Data, Static, sizeof(Static));
                ConstructArray<T>(Data + Size, Reserved - Size);
            }
            else if (Size >= Reserved)
            {
                Reserved *= 2;
                Data = (T*)Memory::Realloc(Data, Reserved * sizeof(T));
                ConstructArray<T>(Data + Size, Reserved - Size);
            }
            p = &Data[Size];
        }
        ++Size;
        *p = v;
    }

private:
    MemoryHeap* pHeap;
    UPInt       Size;
    UPInt       Reserved;
    T           Static[N];
    T*          Data;
};

} // namespace Scaleform

#endif
