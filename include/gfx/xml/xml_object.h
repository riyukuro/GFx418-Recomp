// Recovered Scaleform 4.1.18 GFx XML: pooled DOM strings and the per-movie XML object manager.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_XML_OBJECT_H
#define MS2_SF_GFX_XML_OBJECT_H

#include "../../kernel/sf_hash.h"
#include "../../kernel/sf_array.h"
#include "../../kernel/sf_string.h"
#include "../gfx_state.h"

namespace Scaleform { namespace GFx { namespace XML {

class DOMString;
class DOMStringManager;
struct DOMStringNode;
struct Node;
struct Prefix;
struct Attribute;
struct ElementNode;
struct TextNode;
struct Document;
struct RootNode;
class ObjectManager;

// (pointer, length) probe compared by strncmp against a DOMString.
struct DOMStringCompareWrapper
{
    const char* pData;
    UPInt       Length;

    DOMStringCompareWrapper(const char* p, UPInt n) : pData(p), Length(n) {}
};

// Interned string: 0x20 bytes, allocated from 127-node pages. While free, the manager slot links the free list.
struct DOMStringNode
{
    enum FlagConstants
    {
        Flag_HashMask = 0x00FFFFFF,
    };

    const char* pData;
    union
    {
        DOMStringManager* pManager;
        DOMStringNode*    pNextAlloc;
    };
    UInt32   HashFlags;
    unsigned Size;
    SInt32   RefCount;

    DOMStringManager* GetManager() const { return pManager; }
    inline UInt32     GetHashCode()      { return HashFlags & Flag_HashMask; }

    void AddRef() { RefCount++; }
    void Release()
    {
        if (--RefCount == 0)
            ReleaseNode();
    }
    void ReleaseNode();
};

struct DOMStringNodeHolder
{
    DOMStringNode* pNode;
};

// Counted reference to an interned node; equality is node identity.
class DOMString : public DOMStringNodeHolder
{
    friend class DOMStringManager;

public:
    explicit DOMString(DOMStringNode* pnode);
    DOMString(const DOMString& src);
    ~DOMString();

    const char* ToCStr() const       { return pNode->pData; }
    const char* GetBuffer() const    { return pNode->pData; }
    unsigned    GetSize() const      { return pNode->Size; }
    bool        IsEmpty() const      { return pNode->Size == 0; }
    unsigned    GetHashFlags() const { return pNode->HashFlags; }
    unsigned    GetHash() const      { return GetHashFlags() & DOMStringNode::Flag_HashMask; }
    DOMStringNode* GetNode() const   { return pNode; }

    static UInt32 HashFunction(const char* pchar, UPInt length);

    void operator=(const DOMString& src) { AssignNode(src.pNode); }
    bool operator==(const DOMString& o) const { return pNode == o.pNode; }
    bool operator!=(const DOMString& o) const { return pNode != o.pNode; }
    bool operator==(const DOMStringCompareWrapper& o) { return strncmp(pNode->pData, o.pData, o.Length) == 0; }

    void AssignNode(DOMStringNode* pnode);
};

// Lookup key carrying a precomputed hash.
struct DOMStringKey
{
    const char* pStr;
    UPInt       HashValue;
    UPInt       Length;

    DOMStringKey(const DOMStringKey& o) : pStr(o.pStr), HashValue(o.HashValue), Length(o.Length) {}
    DOMStringKey(const char* p, UPInt h, UPInt n) : pStr(p), HashValue(h), Length(n) {}
};

template<class C>
class DOMStringNodeHashFunc
{
public:
    typedef C ValueType;

    UPInt operator()(const C& node) const          { return node->HashFlags; }
    UPInt operator()(const DOMStringKey& k) const  { return k.HashValue; }

    static UPInt    GetCachedHash(const C& node)  { return node->HashFlags; }
    static void     SetCachedHash(C&, UPInt)      {}
    static C&       GetValue(C& v)                { return v; }
    static const C& GetValue(const C& v)          { return v; }
};

bool operator==(DOMStringNode* pnode, const DOMStringKey& key);

typedef HashSetUncachedLH<DOMStringNode*, DOMStringNodeHashFunc<DOMStringNode*>,
                          DOMStringNodeHashFunc<DOMStringNode*>, StatMV_XML_Mem> XMLDOMStringNodeHash;

// String pool: 0x48 bytes (StringSet +0, free/page lists +8..+0x20, pHeap +0x28, EmptyStringNode +0x30).
class DOMStringManager
{
    friend class DOMString;
    friend struct DOMStringNode;

    XMLDOMStringNodeHash StringSet;

    struct StringNodePage
    {
        enum { StringNodeCount = 127 };
        DOMStringNode   Nodes[StringNodeCount];
        StringNodePage* pNext;
    };

    // 126 sixteen-byte text slots per 2 KB page; strings shorter than 16 bytes live here.
    struct TextPage
    {
        enum
        {
            BuffSize  = sizeof(void*) * 2,
            BuffCount = (2048 / BuffSize) - 2
        };
        struct Entry
        {
            union
            {
                Entry* pNextAlloc;
                char   Buff[BuffSize];
            };
        };
        Entry     Entries[BuffCount];
        TextPage* pNext;
        void*     pMem;
    };

    DOMStringNode*   pFreeStringNodes;
    StringNodePage*  pStringNodePages;
    TextPage::Entry* pFreeTextBuffers;
    TextPage*        pTextBufferPages;
    MemoryHeap*      pHeap;
    DOMStringNode    EmptyStringNode;

    void AllocateStringNodes();
    void AllocateTextBuffers();

    // Pops a node off the free list (refilling it first); the node's manager slot is set to this pool.
    DOMStringNode* AllocStringNode()
    {
        if (!pFreeStringNodes)
            AllocateStringNodes();
        DOMStringNode* n = pFreeStringNodes;
        if (pFreeStringNodes)
            pFreeStringNodes = n->pNextAlloc;
        n->pManager = this;
        return n;
    }
    void FreeStringNode(DOMStringNode* pnode)
    {
        if (pnode->pData)
        {
            FreeTextBuffer(const_cast<char*>(pnode->pData), pnode->Size);
            pnode->pData = 0;
        }
        pnode->pNextAlloc = pFreeStringNodes;
        pFreeStringNodes  = pnode;
    }

    char* AllocTextBuffer(UPInt length);
    char* AllocTextBuffer(const char* pbuffer, UPInt length);
    void  FreeTextBuffer(char* pbuffer, UPInt length);

    DOMStringNode* CreateStringNode(const char* pstr, UPInt length);
    DOMStringNode* CreateStringNode(const char* pstr1, UPInt l1, const char* pstr2, UPInt l2);
    DOMStringNode* GetEmptyStringNode() { return &EmptyStringNode; }

public:
    DOMStringManager();
    ~DOMStringManager();

    DOMString CreateEmptyString()                         { return DOMString(GetEmptyStringNode()); }
    DOMString CreateString(const char* pstr, UPInt length) { return DOMString(CreateStringNode(pstr, length)); }
    void AppendString(DOMString& str1, const char* str2, UPInt length)
    {
        str1.AssignNode(CreateStringNode(str1.pNode->pData, str1.pNode->Size, str2, length));
    }
};

// Per-movie factory for XML objects (MovieImpl::pXMLObjectManager): 0x78 bytes, vtables 0x1432247c8/0x1432247d0.
class ObjectManager : public RefCountBaseNTS<ObjectManager, StatMV_XML_Mem>, public ExternalLibPtr
{
    DOMStringManager StringPool;
    MemoryHeap*      pHeap;

public:
    ObjectManager(MemoryHeap* pheap, MovieImpl* powner = 0);
    ObjectManager(MovieImpl* powner = 0);
    virtual ~ObjectManager();

    MemoryHeap* GetHeap() { return pHeap; }

    DOMString CreateString(const char* str, UPInt len) { return StringPool.CreateString(str, len); }
    template<size_t N>
    DOMString CreateString(const char (&str)[N]) { return StringPool.CreateString(str, N - 1); }
    DOMString EmptyString() { return StringPool.CreateEmptyString(); }
    void AppendString(DOMString& str1, const char* str2, UPInt len) { StringPool.AppendString(str1, str2, len); }

    Document*    CreateDocument();
    ElementNode* CreateElementNode(DOMString value);
    TextNode*    CreateTextNode(DOMString value);
    Attribute*   CreateAttribute(DOMString name, DOMString value);
    Prefix*      CreatePrefix(DOMString name, DOMString value);
    RootNode*    CreateRootNode(Node* pdom);
};

}}} // namespace Scaleform::GFx::XML

#endif
