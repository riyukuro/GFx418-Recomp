// Recovered Scaleform GFx 4.1.18: ArrayStaticBuffPOD<T, N>, a POD array that keeps its first N elements in the
// object and moves to the heap past them (ShapeMeshProvider::acquireShapeData keeps its path list in one).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_ARRAYSTATICBUFF_H
#define MS2_SF_KERNEL_ARRAYSTATICBUFF_H

#include <string.h>
#include "ms2/scaleform/kernel/sf_memory.h"

namespace Scaleform {

template<class T, unsigned N, int SID = Stat_Default_Mem>
class ArrayStaticBuffPOD
{
public:
    ArrayStaticBuffPOD(MemoryHeap* heap = 0) : pHeap(heap), Size(0), Reserved(N), Data(Static) {}
    ~ArrayStaticBuffPOD()
    {
        if (Data != Static)
            Memory::Free(Data);
    }

    UPInt GetSize() const { return Size; }

    T&       operator[](UPInt i)       { return Data[i]; }
    const T& operator[](UPInt i) const { return Data[i]; }

    // the first overflow copies the in-object elements out; later ones double the heap block
    void PushBack(const T& v)
    {
        if (Size < N)
            Static[Size] = v;
        else
        {
            if (Size == N)
            {
                Reserved *= 2;
                Data = (T*)(pHeap ? Memory::AllocInHeap(pHeap, Reserved * sizeof(T))
                                  : Memory::AllocAutoHeap(this, Reserved * sizeof(T)));
                memcpy(Data, Static, sizeof(Static));
            }
            else if (Size >= Reserved)
            {
                Reserved *= 2;
                Data = (T*)Memory::Realloc(Data, Reserved * sizeof(T));
            }
            Data[Size] = v;
        }
        ++Size;
    }

    void CutAt(UPInt newSize)
    {
        if (newSize < Size)
            Size = newSize;
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
