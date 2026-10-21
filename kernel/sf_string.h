// Recovered Scaleform GFx 4.1.18: UTF-8 strings. String shares an immutable, ref-counted DataDesc {Size, RefCount,
// Data[]} (copy on write); the low two bits of the data pointer say which heap the text lives in (global, the heap
// owning the String object, or an explicit heap for StringDH). The top bit of Size caches "length == size" (ASCII).
// StringBuffer is the mutable, growable variant; StringDataPtr a non-owning {pointer, size} view.
#ifndef MS2_SF_KERNEL_STRING_H
#define MS2_SF_KERNEL_STRING_H

#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_alg.h"

namespace Scaleform {

class String;
class StringLH;
class StringDH;
class StringBuffer;

class String
{
    friend class StringLH;
    friend class StringDH;

protected:
    enum FlagConstants { Flag_LengthIsSizeShift = (sizeof(UPInt) * 8 - 1) };

    struct DataDesc
    {
        UPInt           Size;       // top bit: length is size
        volatile SInt32 RefCount;
        char            Data[1];

        void AddRef() { AtomicOps<SInt32>::ExchangeAdd_NoSync(&RefCount, 1); }
        void Release()
        {
            if ((AtomicOps<SInt32>::ExchangeAdd_NoSync(&RefCount, -1) - 1) == 0)
                SF_FREE(this);
        }
        static UPInt GetLengthFlagBit() { return UPInt(1) << Flag_LengthIsSizeShift; }
        UPInt GetSize() const { return Size & ~GetLengthFlagBit(); }
        UPInt GetLengthFlag() const { return Size & GetLengthFlagBit(); }
        bool  LengthIsSize() const { return GetLengthFlag() != 0; }
    };

    enum HeapType
    {
        HT_Global  = 0,
        HT_Local   = 1,
        HT_Dynamic = 2,
        HT_Mask    = 3
    };

    union {
        DataDesc* pData;
        UPInt     HeapTypeBits;
    };
    typedef union {
        DataDesc* pData;
        UPInt     HeapTypeBits;
    } DataDescUnion;

    inline HeapType GetHeapType() const { return (HeapType)(HeapTypeBits & HT_Mask); }
    inline DataDesc* GetData() const
    {
        DataDescUnion u;
        u.pData = pData;
        u.HeapTypeBits = (u.HeapTypeBits & ~(UPInt)HT_Mask);
        return u.pData;
    }
    inline void SetData(DataDesc* desc)
    {
        HeapType ht = GetHeapType();
        pData = desc;
        HeapTypeBits |= ht;
    }

    DataDesc* AllocData(MemoryHeap* heap, UPInt size, UPInt lengthIsSize);
    DataDesc* AllocDataCopy1(MemoryHeap* heap, UPInt size, UPInt lengthIsSize, const char* data, UPInt copySize);
    DataDesc* AllocDataCopy2(MemoryHeap* heap, UPInt size, UPInt lengthIsSize, const char* data1, UPInt copySize1,
                             const char* data2, UPInt copySize2);

    struct NoConstructor { };
    String(const NoConstructor&) { }

public:
    // fills a freshly allocated buffer of a known size
    struct InitStruct
    {
        virtual ~InitStruct() { }
        virtual void InitString(char* buffer, UPInt size) const = 0;
    };

    String();
    String(const char* data);
    String(const char* data1, const char* data2, const char* data3 = 0);
    String(const char* data, UPInt buflen);
    String(const String& src);
    String(const StringBuffer& src);
    String(const InitStruct& src, UPInt size);
    explicit String(const wchar_t* data);
    ~String() { GetData()->Release(); }

    static DataDesc NullData;

    MemoryHeap* GetHeap() const;
    void Clear();

    operator const char*() const { return GetData()->Data; }
    const char* ToCStr() const { return GetData()->Data; }
    UPInt GetSize() const { return GetData()->GetSize(); }
    bool  IsEmpty() const { return GetSize() == 0; }

    UPInt  GetLength() const;
    UInt32 GetCharAt(UPInt index) const;
    UInt32 GetFirstCharAt(UPInt index, const char** offset) const;
    UInt32 GetNextChar(const char** offset) const;

    void AppendChar(UInt32 ch);
    void AppendString(const wchar_t* str, SPInt len = -1);
    void AppendString(const char* utf8, SPInt utf8StrSz = -1);
    void AssignString(const InitStruct& src, UPInt size);
    void AssignString(const char* utf8, UPInt size);

    void    Remove(UPInt posAt, SPInt len = 1);
    String  Substring(UPInt start, UPInt end) const;
    String  ToUpper() const;
    String  ToLower() const;
    String& Insert(const char* substr, UPInt posAt, SPInt len = -1);
    UPInt   InsertCharAt(UInt32 c, UPInt posAt);
    UPInt   GetByteIndex(UPInt index) const { return (UPInt)UTF8Util::GetByteIndex(index, GetData()->Data); }

    static int SF_STDCALL   CompareNoCase(const char* a, const char* b);
    static int SF_STDCALL   CompareNoCase(const char* a, const char* b, SPInt len);
    static UPInt SF_STDCALL BernsteinHashFunctionCIS(const void* dataIn, UPInt size, UPInt seed = 5381);
    static UPInt SF_STDCALL BernsteinHashFunction(const void* dataIn, UPInt size, UPInt seed = 5381);
    static void SF_STDCALL  EscapeSpecialHTML(const char* src, UPInt length, String* escapedStr);
    static void SF_STDCALL  UnescapeSpecialHTML(const char* src, UPInt length, String* unescapedStr);

    // path helpers (SF_String_PathUtil)
    static bool HasAbsolutePath(const char* path);
    static bool HasExtension(const char* path);
    static bool HasProtocol(const char* path);
    bool   HasAbsolutePath() const { return HasAbsolutePath(ToCStr()); }
    bool   HasExtension() const { return HasExtension(ToCStr()); }
    bool   HasProtocol() const { return HasProtocol(ToCStr()); }
    String GetProtocol() const;
    String GetPath() const;
    String GetFilename() const;
    String GetExtension() const;
    void   StripProtocol();
    void   StripExtension();

    void operator=(const char* str);
    void operator=(const wchar_t* str);
    void operator=(const String& src);
    void operator=(const StringBuffer& src);
    void operator+=(const String& src);
    void operator+=(const char* src) { AppendString(src); }
    void operator+=(const wchar_t* src) { AppendString(src); }
    void operator+=(char ch) { AppendChar(ch); }
    String operator+(const char* str) const;
    String operator+(const String& src) const;

    bool operator==(const String& str) const { return (SFstrcmp(GetData()->Data, str.GetData()->Data) == 0); }
    bool operator!=(const String& str) const { return !operator==(str); }
    bool operator==(const char* str) const { return SFstrcmp(GetData()->Data, str) == 0; }
    bool operator!=(const char* str) const { return !operator==(str); }
    bool operator<(const char* str) const { return SFstrcmp(GetData()->Data, str) < 0; }
    bool operator<(const String& str) const { return *this < str.GetData()->Data; }
    bool operator>(const char* str) const { return SFstrcmp(GetData()->Data, str) > 0; }
    bool operator>(const String& str) const { return *this > str.GetData()->Data; }

    int CompareNoCase(const char* str) const { return CompareNoCase(GetData()->Data, str); }
    int CompareNoCase(const String& str) const { return CompareNoCase(GetData()->Data, str.ToCStr()); }

    const char& operator[](int index) const { return GetData()->Data[index]; }
    const char& operator[](UPInt index) const { return GetData()->Data[index]; }

    // case-insensitive hash key
    struct NoCaseKey
    {
        const String* pStr;
        NoCaseKey(const String& str) : pStr(&str) { };
    };
    bool operator==(const NoCaseKey& strKey) const { return (CompareNoCase(ToCStr(), strKey.pStr->ToCStr()) == 0); }
    bool operator!=(const NoCaseKey& strKey) const { return !(CompareNoCase(ToCStr(), strKey.pStr->ToCStr()) == 0); }

    struct HashFunctor
    {
        UPInt operator()(const String& data) const
        {
            UPInt size = data.GetSize();
            return String::BernsteinHashFunction((const char*)data, size);
        }
    };
    struct NoCaseHashFunctor
    {
        UPInt operator()(const String& data) const
        {
            UPInt size = data.GetSize();
            return String::BernsteinHashFunctionCIS((const char*)data, size);
        }
        UPInt operator()(const NoCaseKey& data) const
        {
            UPInt size = data.pStr->GetSize();
            return String::BernsteinHashFunctionCIS((const char*)data.pStr->ToCStr(), size);
        }
    };
};

// String whose text lives in the heap that owns the String object.
class StringLH : public String
{
    void SetDataLcl(DataDesc* desc)
    {
        pData = desc;
        HeapTypeBits |= HT_Local;
    }
    void CopyConstructHelper(const String& src);

public:
    StringLH();
    StringLH(const char* data);
    StringLH(const char* data, UPInt buflen);
    StringLH(const StringLH& src) : String(NoConstructor()) { CopyConstructHelper(src); }
    explicit StringLH(const String& src) : String(NoConstructor()) { CopyConstructHelper(src); }
    explicit StringLH(const InitStruct& src, UPInt size);
    explicit StringLH(const wchar_t* data);

    void operator=(const char* str) { String::operator=(str); }
    void operator=(const wchar_t* str) { String::operator=(str); }
    void operator=(const String& src) { String::operator=(src); }
    void operator=(const StringBuffer& src) { String::operator=(src); }
};

// String with an explicit heap.
class StringDH : public String
{
    MemoryHeap* pHeap;

    void SetDataLcl(DataDesc* desc)
    {
        pData = desc;
        HeapTypeBits |= HT_Dynamic;
    }
    void CopyConstructHelper(const String& src, MemoryHeap* heap);

public:
    StringDH(MemoryHeap* heap = Memory::GetGlobalHeap());
    StringDH(MemoryHeap* heap, const char* data);
    StringDH(MemoryHeap* heap, const char* data1, const char* data2, const char* data3 = 0);
    StringDH(MemoryHeap* heap, const char* data, UPInt buflen);
    StringDH(const StringDH& src) : String(NoConstructor()) { CopyConstructHelper(src, src.GetHeap()); }
    explicit StringDH(const String& src) : String(NoConstructor()) { CopyConstructHelper(src, 0); }
    explicit StringDH(MemoryHeap* heap, const String& src) : String(NoConstructor()) { CopyConstructHelper(src, heap); }
    explicit StringDH(MemoryHeap* heap, const InitStruct& src, UPInt size);
    explicit StringDH(MemoryHeap* heap, const wchar_t* data);

    void operator=(const char* str) { String::operator=(str); }
    void operator=(const wchar_t* str) { String::operator=(str); }
    void operator=(const String& src) { String::operator=(src); }
    void operator=(const StringBuffer& src) { String::operator=(src); }

    MemoryHeap* GetHeap() const { return pHeap; }
};

class StringBuffer
{
    char*        pData;
    UPInt        Size;
    UPInt        BufferSize;
    UPInt        GrowSize;      // power of two
    mutable bool LengthIsSize;
    MemoryHeap*  pHeap;

public:
    StringBuffer(MemoryHeap* heap = Memory::GetGlobalHeap());
    explicit StringBuffer(UPInt growSize, MemoryHeap* heap = Memory::GetGlobalHeap());
    StringBuffer(const char* data, MemoryHeap* heap = Memory::GetGlobalHeap());
    StringBuffer(const char* data, UPInt buflen, MemoryHeap* heap = Memory::GetGlobalHeap());
    StringBuffer(const String& src, MemoryHeap* heap = Memory::GetGlobalHeap());
    StringBuffer(const StringBuffer& src, MemoryHeap* heap = Memory::GetGlobalHeap());
    explicit StringBuffer(const wchar_t* data, MemoryHeap* heap = Memory::GetGlobalHeap());
    ~StringBuffer();

    MemoryHeap* GetHeap() const { return pHeap; }
    UPInt GetGrowSize() const { return GrowSize; }
    void  SetGrowSize(UPInt growSize);
    void  Clear();

    operator const char*() const { return (pData) ? pData : ""; }
    const char* ToCStr() const { return (pData) ? pData : ""; }
    UPInt GetSize() const { return Size; }
    bool  IsEmpty() const { return GetSize() == 0; }

    UPInt  GetLength() const;
    UInt32 GetCharAt(UPInt index) const;
    UInt32 GetFirstCharAt(UPInt index, const char** offset) const;
    UInt32 GetNextChar(const char** offset) const;

    void Resize(UPInt size);
    void Reserve(UPInt size);
    void AppendChar(UInt32 ch);
    void AppendString(const wchar_t* str, SPInt len = -1);
    void AppendString(const char* utf8, SPInt utf8StrSz = -1);
    void Insert(const char* substr, UPInt posAt, SPInt len = -1);
    UPInt InsertCharAt(UInt32 c, UPInt posAt);

    void operator=(const char* str);
    void operator=(const wchar_t* str);
    void operator=(const String& src);
    void operator=(const StringBuffer& src);
    void operator+=(const StringBuffer& buff) { AppendString(buff.ToCStr(), buff.GetSize()); }
    void operator+=(const String& src) { AppendString(src.ToCStr(), src.GetSize()); }
    void operator+=(const char* src) { AppendString(src); }
    void operator+=(const wchar_t* src) { AppendString(src); }
    void operator+=(char ch) { AppendChar(ch); }

    char&       operator[](int index) { return pData[index]; }
    char&       operator[](UPInt index) { return pData[index]; }
    const char& operator[](int index) const { return pData[index]; }
    const char& operator[](UPInt index) const { return pData[index]; }
};

class StringDataPtr
{
public:
    StringDataPtr() : pStr(NULL), Size(0) { }
    StringDataPtr(const StringDataPtr& p) : pStr(p.pStr), Size(p.Size) { }
    StringDataPtr(const char* str, UPInt sz) : pStr(str), Size(sz) { }
    StringDataPtr(const char* str) : pStr(str), Size((str != NULL) ? SFstrlen(str) : 0) { }
    explicit StringDataPtr(const String& str) : pStr(str.ToCStr()), Size(str.GetSize()) { }
    template<typename T, int N>
    StringDataPtr(const T (&v)[N]) : pStr(v), Size(N) { }

public:
    char operator[](UPInt index) const { return pStr[index]; }
    const char* ToCStr() const { return pStr; }
    UPInt GetSize() const { return Size; }
    bool  IsEmpty() const { return GetSize() == 0; }

    bool IsPrefix(const StringDataPtr& value) const { return ToCStr() == value.ToCStr() && GetSize() >= value.GetSize(); }
    bool IsSuffix(const StringDataPtr& value) const { return ToCStr() <= value.ToCStr() && (End()) == (value.End()); }

    SPInt FindChar(char c, UPInt initInd = 0) const
    {
        for (UPInt i = initInd; i < GetSize(); ++i)
            if (pStr[i] == c)
                return static_cast<SPInt>(i);
        return -1;
    }
    SPInt FindLastChar(char c, UPInt initInd = ~0) const;
    SPInt FindSubstring(const StringDataPtr& s, UPInt initInd = 0) const;

    StringDataPtr GetTrimLeft(UPInt size) const
    {
        size = Alg::PMin(GetSize(), size);
        return StringDataPtr(ToCStr() + size, GetSize() - size);
    }
    StringDataPtr GetTrimRight(UPInt size) const
    {
        size = Alg::PMin(GetSize(), size);
        return StringDataPtr(ToCStr(), GetSize() - size);
    }
    StringDataPtr GetNextToken(char separator = ':') const;
    StringDataPtr& TrimLeft(UPInt size)
    {
        size = Alg::PMin(GetSize(), size);
        pStr += size;
        Size -= size;
        return *this;
    }
    StringDataPtr& TrimRight(UPInt size)
    {
        size = Alg::PMin(GetSize(), size);
        Size -= size;
        return *this;
    }

    static bool IsWhiteSpace(UInt32 c);
    StringDataPtr GetTruncateWhitespace() const;
    StringDataPtr& TruncateWhitespace()
    {
        *this = GetTruncateWhitespace();
        return *this;
    }

    const char* Begin() const { return ToCStr(); }
    const char* End() const { return ToCStr() + GetSize(); }

    struct HashFunctor
    {
        UPInt operator()(const StringDataPtr& data) const
        {
            return String::BernsteinHashFunction(data.ToCStr(), data.GetSize());
        }
    };

    bool operator==(const StringDataPtr& other) const
    {
        return ((other.pStr == pStr && other.Size == Size) ||
                (pStr && other.pStr && SFstrncmp(pStr, other.pStr, other.Size) == 0));
    }

public:
    static StringDataPtr Null;

protected:
    const char* pStr;
    UPInt       Size;
};

}  // namespace Scaleform

#endif
