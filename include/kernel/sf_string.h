// Recovered Scaleform 4.1.18 kernel: strings (only the parts used by recovered units so far).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_STRING_H
#define MS2_SF_KERNEL_STRING_H

#include "sf_memory.h"
#include <intrin.h>
#include <string.h>

namespace Scaleform {

// Shared, reference counted UTF-8 text. pData points at a DataDesc whose two low address bits carry the heap type;
// the top bit of DataDesc::Size flags "length == byte size". The out-of-line members live in the kernel string unit
// (exe: String() 0x142584ce0, String(const char*) 0x142584b70, String(const wchar_t*) 0x142584ca0,
// String(const String&) 0x142584950, operator=(const char*) 0x1425857d0, operator=(const String&) 0x142585580,
// CompareNoCase 0x142586710).
class String
{
protected:
    // Leaves pData unset for derived classes that fill it themselves.
    struct NoConstructor {};
    String(const NoConstructor&) {}

public:
    enum
    {
        HeapTypeMask = 3
    };

    struct DataDesc
    {
        UPInt           Size;      // +0
        volatile SInt32 RefCount;  // +8
        char            Data[1];   // +0xc

        UPInt GetSize() const { return Size & ~((UPInt)1 << (sizeof(UPInt) * 8 - 1)); }
        void  AddRef()        { _InterlockedExchangeAdd((volatile long*)&RefCount, 1); }
        void  Release()
        {
            if ((_InterlockedExchangeAdd((volatile long*)&RefCount, -1) - 1) == 0)
                Memory::Free(this);
        }
    };

    // Writes a value's text into a caller buffer (the MsgFormat formatters implement it).
    struct InitStruct
    {
        virtual ~InitStruct() {}
        virtual void InitString(char* pbuffer, UPInt size) const = 0;
    };

    String();
    String(const char* pdata);
    // Concatenation of the three strings.
    String(const char* pdata1, const char* pdata2, const char* pdata3);
    String(const wchar_t* pdata);
    String(const String& src);
    // First size bytes of pdata (exe 0x142584c10).
    String(const char* pdata, UPInt size);
    ~String() { GetData()->Release(); }

    void operator=(const char* pstr);
    void operator=(const String& src);
    // Empties the string (exe 0x1425866a0); replaces it with size bytes of utf8 (0x142586530) or of a generated
    // text (0x142586430).
    void Clear();
    void AssignString(const char* utf8, UPInt size);
    void AssignString(const InitStruct& src, UPInt size);

    bool operator==(const String& str) const { return strcmp(ToCStr(), str.ToCStr()) == 0; }

    static int SF_STDCALL CompareNoCase(const char* a, const char* b);

    // Key wrapper that makes a hash lookup compare case-insensitively.
    struct NoCaseKey
    {
        const String* pStr;
        NoCaseKey(const String& str) : pStr(&str) {}
    };
    bool operator==(const NoCaseKey& key) const { return CompareNoCase(ToCStr(), key.pStr->ToCStr()) == 0; }

    // Case-insensitive hash of a string or a NoCaseKey.
    struct NoCaseHashFunctor
    {
        UPInt operator()(const String& data) const
        {
            return String::BernsteinHashFunctionCIS(data.ToCStr(), data.GetSize());
        }
        UPInt operator()(const NoCaseKey& data) const
        {
            return String::BernsteinHashFunctionCIS(data.pStr->ToCStr(), data.pStr->GetSize());
        }
    };

    const char* ToCStr() const  { return GetData()->Data; }
    UPInt       GetSize() const { return GetData()->GetSize(); }

    bool operator==(const char* str) const { return strcmp(ToCStr(), str) == 0; }
    bool operator!=(const char* str) const { return !operator==(str); }

    // exe: operator+(const char*) 0x142585c90, AppendString 0x142586130, ToLower 0x142587bf0.
    String operator+(const char* str) const;
    void   AppendString(const char* putf8str, SPInt utf8StrSz = -1);
    void   operator+=(const char* str) { AppendString(str); }
    String ToLower() const;
    // exe: ToUpper 0x142587e00, AppendString(const wchar_t*, SPInt) 0x142586230.
    String ToUpper() const;
    void   AppendString(const wchar_t* pstr, SPInt len = -1);

    // Character (not byte) count and character range [start, end) (exe: GetLength 0x142587010, Substring 0x142587b20).
    UPInt  GetLength() const;
    String Substring(UPInt start, UPInt end) const;
    // Code point at character index (exe 0x142586ef0); appends a string (exe 0x142585ce0).
    UInt32 GetCharAt(UPInt index) const;
    void   operator+=(const String& src);

    // Path helpers (exe: HasExtension 0x1425a4fb0, GetExtension 0x1425a4d00, StripExtension 0x1425a5180).
    static bool SF_STDCALL HasExtension(const char* path);
    bool   HasExtension() const { return HasExtension(ToCStr()); }
    String GetExtension() const;
    void   StripExtension();

    // djb2 run from the last byte to the first: h = h * 33 ^ c.
    static UPInt SF_STDCALL BernsteinHashFunction(const void* pdata, UPInt size, UPInt seed = 5381);
    static UPInt SF_STDCALL BernsteinHashFunctionCIS(const void* pdata, UPInt size, UPInt seed = 5381);

private:
    DataDesc* GetData() const { return (DataDesc*)((UPInt)pData & ~(UPInt)HeapTypeMask); }

    DataDesc* pData; // low bits carry the heap type
};

// String whose buffer lives in the heap that owns the StringLH itself (exe: CopyConstructHelper 0x1425868d0).
class StringLH : public String
{
public:
    StringLH(); // exe 0x142585540
    StringLH(const StringLH& src) : String(NoConstructor()) { CopyConstructHelper(src); }
    explicit StringLH(const String& src) : String(NoConstructor()) { CopyConstructHelper(src); }

    void operator=(const String& src) { String::operator=(src); }
    void operator=(const char* str)   { String::operator=(str); }

    StringLH(const char* data); // exe 0x1425853a0

private:
    void CopyConstructHelper(const String& src);
};

// String with an explicit heap (exe: StringDH(MemoryHeap*) 0x142584fc0).
class StringDH : public String
{
    MemoryHeap* pHeap;

public:
    StringDH(MemoryHeap* heap = Memory::GetGlobalHeap());

    void operator=(const char* str) { String::operator=(str); }

    MemoryHeap* GetHeap() const { return pHeap; }

    StringDH(const StringDH& src) : String(NoConstructor()) { CopyConstructHelper(src, src.GetHeap()); }
    explicit StringDH(MemoryHeap* heap, const String& src) : String(NoConstructor()) { CopyConstructHelper(src, heap); }

private:
    void CopyConstructHelper(const String& src, MemoryHeap* heap); // exe 0x1425867f0
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

    // The very same view, or a text whose first o.Size bytes are o's.
    bool operator==(const StringDataPtr& o) const
    {
        return (o.pStr == pStr && o.Size == Size) || (pStr && o.pStr && strncmp(pStr, o.pStr, o.Size) == 0);
    }

    // The view without leading and trailing white space (exe 0x142587110).
    StringDataPtr GetTruncateWhitespace() const;

protected:
    const char* pStr;
    UPInt       Size;
};

} // namespace Scaleform

#endif
