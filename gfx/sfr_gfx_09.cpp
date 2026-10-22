// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 XML, string pool and the per-movie object manager.
// Queue unit sfr_gfx_09 is split along its three original sources (sfr_gfx_09 / 09b / 09c): inlining of the
// DOMString members differs between them.
// MS2-UNIT: sfr_gfx_09
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429a4d50-0x1429a6520 .text$mn

#include "../include/gfx/xml/xml_document.h"

namespace Scaleform { namespace GFx {

// MovieImpl is not recovered yet: the only field used here is its XML manager back pointer.
struct MovieImplXMLView
{
    UByte               Unrecovered[0x260];
    XML::ObjectManager* pXMLObjectManager;
};

namespace XML {

// ---------------------------------------------------------------- string pool / object manager

// @0x1429a4d50
DOMStringManager::DOMStringManager()
{
    pHeap            = Memory::GetHeapByAddress(this);
    pStringNodePages = 0;
    pFreeStringNodes = 0;
    pFreeTextBuffers = 0;
    pTextBufferPages = 0;

    // The shared empty string is never freed: it starts with one reference of its own.
    EmptyStringNode.RefCount  = 1;
    EmptyStringNode.Size      = 0;
    EmptyStringNode.HashFlags = DOMString::HashFunction("", 0);
    EmptyStringNode.pData     = "";
    EmptyStringNode.pManager  = this;
    StringSet.Add(&EmptyStringNode);
}

// @0x1429a4de0
ObjectManager::ObjectManager(MemoryHeap* pheap, MovieImpl* powner) : ExternalLibPtr(powner), pHeap(pheap)
{
}

// @0x1429a4e30
ObjectManager::ObjectManager(MovieImpl* powner) : ExternalLibPtr(powner)
{
    pHeap = Memory::GetHeapByAddress(this);
}

// @0x1429a4e80
DOMString::~DOMString()
{
    pNode->Release();
}

// @0x1429a4e90
DOMStringManager::~DOMStringManager()
{
    // Node pages: give back the text of every node still holding some, then the page.
    while (pStringNodePages)
    {
        StringNodePage* page = pStringNodePages;
        pStringNodePages     = page->pNext;
        for (unsigned i = 0; i < page->StringNodeCount; i++)
        {
            if (page->Nodes[i].pData)
                FreeTextBuffer(const_cast<char*>(page->Nodes[i].pData), page->Nodes[i].Size);
        }
        SF_FREE(page);
    }
    // Text pages were over-allocated for alignment; pMem is the real block.
    while (pTextBufferPages)
    {
        void* mem        = pTextBufferPages->pMem;
        pTextBufferPages = pTextBufferPages->pNext;
        SF_FREE(mem);
    }
}

// @0x1429a4fb0
ObjectManager::~ObjectManager()
{
    if (pOwner)
        reinterpret_cast<MovieImplXMLView*>(pOwner)->pXMLObjectManager = 0;
}

// @0x1429a5010
bool operator==(DOMStringNode* pnode, const DOMStringKey& key)
{
    if (pnode->Size != key.Length)
        return 0;
    return strncmp(pnode->pData, key.pStr, key.Length) == 0;
}

// @0x1429a5400
char* DOMStringManager::AllocTextBuffer(const char* pbuffer, UPInt length)
{
    char* p = AllocTextBuffer(length);
    if (p)
    {
        memcpy(p, pbuffer, length);
        p[length] = 0;
    }
    return p;
}

// @0x1429a5490
char* DOMStringManager::AllocTextBuffer(UPInt length)
{
    // Short strings (with their terminator) fit a pooled 16-byte slot.
    if (length < TextPage::BuffSize)
    {
        if (!pFreeTextBuffers)
            AllocateTextBuffers();
        char* p = 0;
        if (pFreeTextBuffers)
        {
            p                = pFreeTextBuffers->Buff;
            pFreeTextBuffers = pFreeTextBuffers->pNextAlloc;
        }
        return p;
    }
    return (char*)SF_HEAP_ALLOC(pHeap, length + 1, StatMV_XML_Mem);
}

// @0x1429a54f0
void DOMStringManager::AllocateStringNodes()
{
    StringNodePage* page = (StringNodePage*)SF_HEAP_ALLOC(pHeap, sizeof(StringNodePage), StatMV_XML_Mem);
    if (page)
    {
        page->pNext      = pStringNodePages;
        pStringNodePages = page;
        for (unsigned i = 0; i < StringNodePage::StringNodeCount; i++)
        {
            DOMStringNode* n = &page->Nodes[i];
            n->pData         = 0;
            n->pNextAlloc    = pFreeStringNodes;
            pFreeStringNodes = n;
        }
    }
}

// @0x1429a5550
void DOMStringManager::AllocateTextBuffers()
{
    // Allocate 8 extra bytes and round the page up to 8-byte alignment.
    void*     mem  = SF_HEAP_ALLOC(pHeap, sizeof(TextPage) + 8, StatMV_XML_Mem);
    TextPage* page = (TextPage*)((((UPInt)mem) + 7) & ~7);
    if (page)
    {
        page->pMem       = mem;
        page->pNext      = pTextBufferPages;
        pTextBufferPages = page;
        for (unsigned i = 0; i < TextPage::BuffCount; i++)
        {
            TextPage::Entry* e = page->Entries + i;
            e->pNextAlloc      = pFreeTextBuffers;
            pFreeTextBuffers   = e;
        }
    }
}

// @0x1429a5a20
void DOMString::AssignNode(DOMStringNode* pnode)
{
    pnode->AddRef();
    pNode->Release();
    pNode = pnode;
}

// @0x1429a5a50
Attribute* ObjectManager::CreateAttribute(DOMString name, DOMString value)
{
    return SF_HEAP_NEW(pHeap) Attribute(name, value);
}

// @0x1429a5ae0
Document* ObjectManager::CreateDocument()
{
    return SF_HEAP_NEW(pHeap) Document(this);
}

// @0x1429a5b20
ElementNode* ObjectManager::CreateElementNode(DOMString value)
{
    return SF_HEAP_NEW(pHeap) ElementNode(this, value);
}

// @0x1429a5b80
Prefix* ObjectManager::CreatePrefix(DOMString name, DOMString value)
{
    return SF_HEAP_NEW(pHeap) Prefix(name, value);
}

// @0x1429a5c20
RootNode* ObjectManager::CreateRootNode(Node* pdom)
{
    return SF_HEAP_NEW(pHeap) RootNode(pdom);
}

// @0x1429a5c70
DOMStringNode* DOMStringManager::CreateStringNode(const char* pstr1, UPInt l1, const char* pstr2, UPInt l2)
{
    DOMStringNode* node   = 0;
    UPInt          length = l1 + l2;
    char*          buf    = AllocTextBuffer(length);

    if (buf)
    {
        if (l1 > 0)
            memcpy(buf, pstr1, l1);
        if (l2 > 0)
            memcpy(buf + l1, pstr2, l2);
        buf[length] = 0;

        DOMStringKey key(buf, DOMString::HashFunction(buf, length), length);
        if (StringSet.GetAlt(key, &node))
        {
            // Already interned: drop the scratch copy.
            FreeTextBuffer(buf, length);
            return node;
        }

        if ((node = AllocStringNode()) != 0)
        {
            node->RefCount  = 0;
            node->Size      = (unsigned)length;
            node->pData     = buf;
            node->HashFlags = (UInt32)key.HashValue;
            StringSet.Add(node);
            return node;
        }
        FreeTextBuffer(buf, length);
    }
    return &EmptyStringNode;
}

// @0x1429a5e90
DOMStringNode* DOMStringManager::CreateStringNode(const char* pstr, UPInt length)
{
    DOMStringNode* node = 0;
    DOMStringKey   key(pstr, DOMString::HashFunction(pstr, length), length);

    if (StringSet.GetAlt(key, &node))
        return node;
    if (length == 0)
        return &EmptyStringNode;

    if ((node = AllocStringNode()) != 0)
    {
        node->pData = AllocTextBuffer(pstr, length);
        if (node->pData)
        {
            node->RefCount  = 0;
            node->Size      = (unsigned)length;
            node->HashFlags = (UInt32)key.HashValue;
            StringSet.Add(node);
            return node;
        }
        FreeStringNode(node);
    }
    return &EmptyStringNode;
}

// @0x1429a6040
TextNode* ObjectManager::CreateTextNode(DOMString value)
{
    return SF_HEAP_NEW(pHeap) TextNode(this, value);
}

// @0x1429a6120
UInt32 DOMString::HashFunction(const char* pchar, UPInt length)
{
    return (UInt32)String::BernsteinHashFunction(pchar, length) & DOMStringNode::Flag_HashMask;
}

// @0x1429a6280
void DOMStringNode::ReleaseNode()
{
    pManager->StringSet.Remove(this);
    pManager->FreeStringNode(this);
}

// Inlined at every call site (the linker dropped the out-of-line copy).
void DOMStringManager::FreeTextBuffer(char* pbuffer, UPInt length)
{
    if (length < TextPage::BuffSize)
    {
        // The slot's free-list link overlays the start of its text.
        TextPage::Entry* e = reinterpret_cast<TextPage::Entry*>(pbuffer);
        e->pNextAlloc      = pFreeTextBuffers;
        pFreeTextBuffers   = e;
        return;
    }
    SF_FREE(pbuffer);
}

// Folded with ASString::ASString(ASStringNode*) at 0x1429a4d40 (another unit's range).
DOMString::DOMString(DOMStringNode* pnode)
{
    pNode = pnode;
    pNode->AddRef();
}

DOMString::DOMString(const DOMString& src)
{
    pNode = src.pNode;
    pNode->AddRef();
}

} // namespace XML
}} // namespace Scaleform::GFx

// Scaleform is built without RTTI: the vftables are pinned by hand (exe .rdata order of the XML_Object TU).
// MS2-PIN: ??_7ExternalLibPtr@GFx@Scaleform@@6B@ 0x1432247b0
// MS2-PIN: ??_7?$RefCountBaseNTS@URootNode@XML@GFx@Scaleform@@$0BEG@@Scaleform@@6B@ 0x1432247b8
// MS2-PIN: ??_7?$RefCountBaseNTS@UPrefix@XML@GFx@Scaleform@@$0BEG@@Scaleform@@6B@ 0x1432247c0
// MS2-PIN: ??_7ObjectManager@XML@GFx@Scaleform@@6B?$RefCountBaseNTS@VObjectManager@XML@GFx@Scaleform@@$0BEG@@3@@ 0x1432247c8
// MS2-PIN: ??_7ObjectManager@XML@GFx@Scaleform@@6BExternalLibPtr@23@@ 0x1432247d0
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BEG@@Scaleform@@6B@ 0x1432247d8
// MS2-PIN: ??_7Prefix@XML@GFx@Scaleform@@6B@ 0x1432247e0
// MS2-PIN: ??_7?$RefCountBaseNTS@VObjectManager@XML@GFx@Scaleform@@$0BEG@@Scaleform@@6B@ 0x1432247e8
// MS2-PIN: ??_7RootNode@XML@GFx@Scaleform@@6B@ 0x1432247f0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@PEAUDOMStringNode@XML@GFx@Scaleform@@V?$DOMStringNodeHashFunc@PEAUDOMStringNode@XML@GFx@Scaleform@@@234@V5234@U?$AllocatorLH@PEAUDOMStringNode@XML@GFx@Scaleform@@$0BEG@@4@V?$HashsetEntry@PEAUDOMStringNode@XML@GFx@Scaleform@@V?$DOMStringNodeHashFunc@PEAUDOMStringNode@XML@GFx@Scaleform@@@234@@4@@Scaleform@@AEAAXPEAX_K@Z 0x1429a63b0
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
