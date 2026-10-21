// Recovered Scaleform 4.1.18 kernel: strings (only the parts used by recovered units so far).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_STRING_H
#define MS2_SF_KERNEL_STRING_H

#include "sf_memory.h"

namespace Scaleform {

class String
{
public:
    struct DataDesc;

    // djb2 run from the last byte to the first: h = h * 33 ^ c.
    static UPInt SF_STDCALL BernsteinHashFunction(const void* pdata, UPInt size, UPInt seed = 5381);
    static UPInt SF_STDCALL BernsteinHashFunctionCIS(const void* pdata, UPInt size, UPInt seed = 5381);

private:
    DataDesc* pData; // low bits carry the heap type
};

// Growable UTF-8 buffer: 0x30 bytes.
class StringBuffer
{
    char*        pData;
    UPInt        Size;
    UPInt        BufferSize;
    UPInt        GrowSize;
    mutable bool LengthIsSize;
    MemoryHeap*  pHeap;

public:
    StringBuffer(MemoryHeap* pheap = Memory::GetGlobalHeap());
    ~StringBuffer();

    MemoryHeap* GetHeap() const     { return pHeap; }
    UPInt       GetGrowSize() const { return GrowSize; }

    void Clear();

    operator const char*() const { return pData ? pData : ""; }
    const char* ToCStr() const   { return pData ? pData : ""; }
    UPInt       GetSize() const  { return Size; }
    bool        IsEmpty() const  { return GetSize() == 0; }

    void Resize(UPInt size);
    void Reserve(UPInt size);

    void AppendChar(UInt32 ch);
    void AppendString(const char* putf8str, SPInt utf8StrSz = -1);
};

// Non-owning (pointer, byte count) view.
class StringDataPtr
{
public:
    StringDataPtr() : pStr(0), Size(0) {}
    StringDataPtr(const char* p, UPInt n) : pStr(p), Size(n) {}

    const char* ToCStr() const  { return pStr; }
    UPInt       GetSize() const { return Size; }
    bool        IsEmpty() const { return Size == 0; }

protected:
    const char* pStr;
    UPInt       Size;
};

} // namespace Scaleform

#endif
