// Recovered Scaleform 4.1.18 GFx: the ActionScript string table. Strings are interned nodes owned by an
// ASStringManager; equal text always shares one node, so string equality is a pointer compare.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The exe spells UInt32 as unsigned long in these signatures (mangling K), hence the explicit type below.
#ifndef MS2_SF_GFX_ASSTRING_H
#define MS2_SF_GFX_ASSTRING_H

#include "../kernel/sf_hash.h"
#include "../kernel/sf_refcount.h"
#include "../kernel/sf_string.h"
#include "../kernel/sf_utf8util.h"
#include <string.h>

namespace Scaleform { namespace GFx {

class ASString;
class ASStringManager;
class LogState;

// One interned string: 0x28 bytes.
struct ASStringNode
{
    const char*      pData;    // +0x00
    ASStringManager* pManager; // +0x08
    union
    {
        ASStringNode* pLower;     // +0x10 lowercase twin (resolved lazily; builtins and the empty string point at self)
        ASStringNode* pNextAlloc; //       free list link while unused
    };
    unsigned RefCount;  // +0x18
    unsigned HashFlags; // +0x1c low 24 bits hash, high 8 bits ASConstString::Flag_*
    unsigned Size;      // +0x20 bytes, without the terminating 0

    ASStringManager* GetManager() const { return pManager; }

    void AddRef() { RefCount++; }
    // exe 0x1425c1200 (out-of-line copy)
    void Release()
    {
        if (--RefCount == 0)
            ReleaseNode();
    }
    void ReleaseNode();           // exe 0x1425c14e0
    void ResolveLowercase_Impl(); // exe 0x1425c1630
};

struct ASStringNodeHolder
{
    ASStringNode* pNode;

    ASStringNodeHolder(ASStringNode* pnode = 0) : pNode(pnode) {}
    ASStringNodeHolder(const ASStringNodeHolder& src) : pNode(src.pNode) {}
};

// Non-owning string handle; ASString adds the reference.
class ASConstString : protected ASStringNodeHolder
{
public:
    explicit ASConstString(ASStringNode* pnode) : ASStringNodeHolder(pnode) {}
    ASConstString(const ASConstString& src) : ASStringNodeHolder(src) {}

    enum FlagConstants
    {
        Flag_HashMask        = 0x00FFFFFF,
        Flag_Builtin         = 0x80000000,
        Flag_ConstData       = 0x40000000, // pData is not owned by the manager
        Flag_StandardMember  = 0x20000000,
        Flag_CaseInsensitive = 0x10000000,
        Flag_LengthIsSize    = 0x08000000, // plain ASCII: character count == byte count
        Flag_PathCheck       = 0x04000000,
        Flag_IsNotPath       = 0x02000000
    };

    const char*      ToCStr() const       { return pNode->pData; }
    const char*      GetBuffer() const    { return pNode->pData; }
    unsigned         GetSize() const      { return pNode->Size; }
    unsigned         GetHashFlags() const { return pNode->HashFlags; }
    ASStringNode*    GetNode() const      { return pNode; }
    ASStringManager* GetManager() const   { return pNode->GetManager(); }

    char operator[](unsigned index) const { return pNode->pData[index]; }

    static unsigned long SF_STDCALL HashFunction(const char* pchar, UPInt length); // exe 0x1425c0ea0

    unsigned      GetLength() const;                                       // exe 0x1425c0e10
    unsigned long GetCharAt(unsigned index) const;                         // exe 0x1425c0d60
    unsigned long GetFirstCharAt(UPInt index, const char** offset) const;  // exe 0x1425c0da0
    unsigned long GetNextChar(const char** offset) const;                  // exe 0x1425c0e60

    ASStringNode* AppendCharNode(unsigned long ch) const;              // exe 0x1425c0370
    ASStringNode* AppendStringNode(const ASConstString& str) const;    // exe 0x1425c0400
    ASStringNode* SubstringNode(int start, int end) const;             // exe 0x1425c1760
    ASStringNode* TruncateWhitespaceNode() const;                      // exe 0x1425c1910
    ASStringNode* ToUpperNode() const;                                 // exe 0x1425c1860
    ASStringNode* ToLowerNode() const;                                 // exe 0x1425c1820

    // Collation compare through wide strings (exe 0x1425c1090); len -1 = up to the terminating 0.
    int LocaleCompare_CaseCheck(const char* pstr, UPInt len, bool caseSensitive) const;

    void ResolveLowercase() const
    {
        if (pNode->pLower == 0)
            pNode->ResolveLowercase_Impl();
    }

    // Case-insensitive compare with this a builtin (its lowercase twin always resolved); exe 0x142935540.
    bool CompareBuiltIn_CaseInsensitive(const ASConstString& str) const;
    // The same compare in the case mode of the movie (inlined: pointer compare when case sensitive).
    SF_FORCEINLINE bool CompareBuiltIn_CaseCheck(const ASConstString& str, bool caseSensitive) const
    {
        if (caseSensitive)
            return pNode == str.pNode;
        str.ResolveLowercase();
        return pNode->pLower == str.pNode->pLower;
    }
};

// Counted string handle.
class ASString : public ASConstString
{
    friend class ASStringManager;

public:
    explicit ASString(ASStringNode* pnode) : ASConstString(pnode) { pNode->AddRef(); }
    ASString(const ASString& src) : ASConstString(src) { pNode->AddRef(); }
    ~ASString() { pNode->Release(); }

    void Clear();                              // exe 0x1425c0460
    void Append(const char* str, UPInt len);   // exe 0x1425c0320
    void Append(const ASString& str);          // exe 0x1425c02d0

    void operator=(const char* str);           // exe 0x1425bf980
    void operator=(const ASString& src) { AssignNode(src.pNode); }

    ASString operator+(const char* str) const;     // exe 0x1425bfa40
    ASString operator+(const ASString& str) const; // exe 0x1425bfa00
    bool     operator<(const ASString& str) const; // exe 0x1425bfa90
    // Not equal and not less.
    bool     operator>(const ASString& str) const
    {
        if (pNode == str.pNode)
            return false;
        return !(*this < str);
    }

    void AssignNode(ASStringNode* pnode)
    {
        pnode->AddRef();
        pNode->Release();
        pNode = pnode;
    }
};

// Lookup key of the string set: text, its hash and its byte count.
struct ASStringKey
{
    const char* pStr;
    UPInt       HashValue;
    UPInt       Length;

    ASStringKey(const char* pstr, UPInt hashValue, UPInt length) : pStr(pstr), HashValue(hashValue), Length(length) {}
};

// exe 0x1425bf9d0
bool operator==(ASStringNode* pnode, const ASStringKey& key);

// The nodes hash by their stored HashFlags (flag bits included, the table masks them away).
template<class C>
class ASStringNodeHashFunc
{
public:
    UPInt operator()(const C& node) const          { return node->HashFlags; }
    UPInt operator()(const ASStringKey& key) const { return key.HashValue; }
};

enum { StatMV_ASString_Mem = 0x144 };

typedef HashSetUncachedLH<ASStringNode*, ASStringNodeHashFunc<ASStringNode*>, ASStringNodeHashFunc<ASStringNode*>,
                          StatMV_ASString_Mem>
    ASStringNodeHash;

// 0xa0 bytes. Nodes come from 127-node pages; texts shorter than 16 bytes come from 2 KB pages of 16-byte cells,
// longer ones from the heap.
class ASStringManager : public RefCountBase<ASStringManager, StatMV_ASString_Mem>
{
    friend class ASString;
    friend struct ASStringNode;

    struct StringNodePage
    {
        enum { StringNodeCount = 127 };
        ASStringNode    Nodes[StringNodeCount];
        StringNodePage* pNext; // +0x13d8
    };

    struct TextPage
    {
        enum
        {
            BuffSize  = 16,
            BuffCount = 2048 / BuffSize - 2
        };
        union Entry
        {
            Entry* pNextAlloc;
            char   Buff[BuffSize];
        };
        Entry     Entries[BuffCount];
        TextPage* pNext; // +0x7e0
        void*     pMem;  // +0x7e8 unaligned allocation
    };

    ASStringNodeHash StringSet;        // +0x10
    MemoryHeap*      pHeap;            // +0x18
    ASStringNode*    pFreeStringNodes; // +0x20
    StringNodePage*  pStringNodePages; // +0x28
    TextPage::Entry* pFreeTextBuffers; // +0x30
    TextPage*        pTextBufferPages; // +0x38
    ASStringNode     EmptyStringNode;  // +0x40
    ASStringNode     NullStringNode;   // +0x68
    Ptr<LogState>    pLog;             // +0x90 leak report target
    StringLH         FileName;         // +0x98

    void AllocateStringNodes(); // exe 0x1425bfd90
    void AllocateTextBuffers(); // exe 0x1425bfe00

    // exe 0x1425bfc20 (out-of-line copy)
    ASStringNode* AllocStringNode()
    {
        if (!pFreeStringNodes)
            AllocateStringNodes();
        ASStringNode* pnode = pFreeStringNodes;
        if (pnode)
            pFreeStringNodes = pnode->pNextAlloc;
        return pnode;
    }
    // exe 0x1425c0ce0 (out-of-line copy)
    void FreeStringNode(ASStringNode* pnode)
    {
        if (pnode->pData)
        {
            if (!(pnode->HashFlags & ASConstString::Flag_ConstData))
                FreeTextBuffer(const_cast<char*>(pnode->pData), pnode->Size);
            pnode->pData = 0;
        }
        pnode->pNextAlloc = pFreeStringNodes;
        pFreeStringNodes  = pnode;
    }

    char* AllocTextBuffer(UPInt length);                      // exe 0x1425bfd30 (length + 1 bytes)
    char* AllocTextBuffer(const char* pbuffer, UPInt length); // exe 0x1425bfca0 (copy, 0 terminated)
    void  FreeTextBuffer(char* pbuffer, UPInt length)
    {
        if (length < TextPage::BuffSize)
        {
            TextPage::Entry* pentry = (TextPage::Entry*)pbuffer;
            pentry->pNextAlloc      = pFreeTextBuffers;
            pFreeTextBuffers        = pentry;
            return;
        }
        SF_HEAP_FREE(pHeap, pbuffer);
    }

public:
    ASStringManager(MemoryHeap* pheap); // exe 0x1425bf620
    ~ASStringManager();                 // exe 0x1425bf710

    MemoryHeap* GetHeap() const { return pHeap; }

    void SetLeakReportLog(LogState* plog, const char* pfilename); // exe 0x1425c16f0

    ASStringNode* CreateConstStringNode(const char* pstr, UPInt length, unsigned long stringFlags); // exe 0x1425c04a0
    ASStringNode* CreateStringNode(const char* pstr);                                              // exe 0x1425c05f0
    ASStringNode* CreateStringNode(const char* pstr, UPInt length);                                // exe 0x1425c0a80
    ASStringNode* CreateStringNode(const char* pstr1, UPInt l1, const char* pstr2, UPInt l2);      // exe 0x1425c0860
    ASStringNode* CreateStringNode(const char* pstr1, UPInt l1, const char* pstr2, UPInt l2, const char* pstr3,
                                   UPInt l3);                                                      // exe 0x1425c0610
    ASStringNode* CreateStringNode(const wchar_t* pwstr, SPInt len = -1);                          // exe 0x1425c0c40

    ASString CreateConstString(const char* pstr, UPInt length, unsigned long stringFlags = 0)
    {
        return ASString(CreateConstStringNode(pstr, length, stringFlags));
    }
    ASString CreateString(const char* pstr, UPInt length) { return ASString(CreateStringNode(pstr, length)); }

    ASStringNode* GetEmptyStringNode() { return &EmptyStringNode; }
    ASStringNode* GetNullStringNode()  { return &NullStringNode; }

    // Builtin name tables (exe: Init 0x1425c0ec0, Release 0x1425c1350).
    void InitBuiltinArray(ASStringNodeHolder* nodes, const char** strings, unsigned count);
    void ReleaseBuiltinArray(ASStringNodeHolder* nodes, unsigned count);
};

}} // namespace Scaleform::GFx

#endif
