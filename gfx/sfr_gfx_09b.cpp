// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 XML, DOM node tree (nodes, attributes, cloning).
// Queue unit sfr_gfx_09 is split along its three original sources (sfr_gfx_09 / 09b / 09c): inlining of the
// DOMString members differs between them.
// MS2-UNIT: sfr_gfx_09b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429a6520-0x1429a7310 .text$mn

#include "../include/gfx/xml/xml_document.h"

namespace Scaleform { namespace GFx { namespace XML {

// ---------------------------------------------------------------- node tree

// @0x1429a6520
Document::Document(ObjectManager* memMgr)
    : ElementNode(memMgr), XMLVersion(MemoryManager->EmptyString()), Encoding(MemoryManager->EmptyString()),
      Standalone(-1)
{
}

// @0x1429a65f0
ElementNode::ElementNode(ObjectManager* memMgr)
    : Node(memMgr, ElementNodeType), Prefix(memMgr->EmptyString()), Namespace(memMgr->EmptyString()),
      FirstAttribute(0), LastAttribute(0), LastChild(0)
{
}

// @0x1429a6690
ElementNode::ElementNode(ObjectManager* memMgr, DOMString value)
    : Node(memMgr, ElementNodeType, value), Prefix(memMgr->EmptyString()), Namespace(memMgr->EmptyString()),
      FirstAttribute(0), LastAttribute(0), LastChild(0)
{
}

// @0x1429a6760
Node::Node(ObjectManager* memMgr, UByte type)
    : MemoryManager(memMgr), Value(MemoryManager->EmptyString()), Parent(0), PrevSibling(0), pShadow(0), Type(type)
{
}

// @0x1429a67c0
Node::Node(ObjectManager* memMgr, UByte type, DOMString value)
    : MemoryManager(memMgr), Value(value), Parent(0), PrevSibling(0), pShadow(0), Type(type)
{
}

// @0x1429a6840
TextNode::TextNode(ObjectManager* memMgr, DOMString value) : Node(memMgr, TextNodeType, value)
{
}

// @0x1429a68e0
Document::~Document()
{
}

// @0x1429a6920
ElementNode::~ElementNode()
{
    // Detach the children back to front and cut the NextSibling chain so each child is released on its own.
    Node* cur  = LastChild;
    Node* prev = 0;
    while (cur)
    {
        cur->Parent = 0;
        prev        = cur->PrevSibling;
        if (prev)
            prev->NextSibling = 0;
        cur = prev;
    }
    if (FirstChild)
        FirstChild = 0;

    for (Attribute* a = FirstAttribute; a != 0;)
    {
        Attribute* next = a->Next;
        delete a;
        a = next;
    }
}

// @0x1429a6a40
Node::~Node()
{
    if (pShadow)
        delete pShadow;
}

// @0x1429a6aa0
TextNode::~TextNode()
{
}

// @0x1429a6d80
void ElementNode::AddAttribute(Attribute* xmlAttrib)
{
    if (FirstAttribute == 0)
    {
        FirstAttribute = xmlAttrib;
        LastAttribute  = xmlAttrib;
    }
    else
    {
        LastAttribute->Next = xmlAttrib;
        LastAttribute       = xmlAttrib;
    }
}

// @0x1429a6da0
void ElementNode::AppendChild(Node* xmlNode)
{
    if (LastChild == 0)
    {
        FirstChild      = xmlNode;
        LastChild       = xmlNode;
        xmlNode->Parent = this;
    }
    else
    {
        xmlNode->PrevSibling   = LastChild;
        LastChild->NextSibling = xmlNode;
        LastChild              = xmlNode;
        xmlNode->Parent        = this;
    }
}

// @0x1429a6e20
void ElementNode::ClearAttributes()
{
    Attribute* next = FirstAttribute;
    for (Attribute* a = FirstAttribute; a != 0;)
    {
        next = a->Next;
        delete a;
        a = next;
    }
    FirstAttribute = 0;
    LastAttribute  = 0;
}

// @0x1429a6ea0
Node* Document::Clone(bool deep)
{
    Document* doc = MemoryManager->CreateDocument();
    ElementNode::CloneHelper(doc, deep);
    doc->Encoding   = Encoding;
    doc->Standalone = Standalone;
    doc->XMLVersion = XMLVersion;
    doc->Type       = Type;
    return doc;
}

// @0x1429a6f20
Node* ElementNode::Clone(bool deep)
{
    ElementNode* node = MemoryManager->CreateElementNode(Value);
    CloneHelper(node, deep);
    node->Type = Type;
    return node;
}

// @0x1429a6f80
Node* TextNode::Clone(bool)
{
    TextNode* node = MemoryManager->CreateTextNode(Value);
    node->Type     = Type;
    return node;
}

// @0x1429a6fc0
void ElementNode::CloneHelper(ElementNode* clone, bool deep)
{
    clone->Prefix = Prefix;
    for (Attribute* a = FirstAttribute; a != 0; a = a->Next)
    {
        Attribute* copy = MemoryManager->CreateAttribute(a->Name, a->Value);
        clone->AddAttribute(copy);
    }
    if (deep)
    {
        for (Node* child = FirstChild; child != 0; child = child->NextSibling)
        {
            Ptr<Node> childCopy = *child->Clone(deep);
            clone->AppendChild(childCopy);
        }
    }
}

// @0x1429a70e0
bool ElementNode::HasAttributes()
{
    return 0 != FirstAttribute;
}

// @0x1429a70f0
bool ElementNode::HasChildren()
{
    return 0 != FirstChild.GetPtr();
}

// @0x1429a7100
void ElementNode::InsertBefore(Node* child, Node* insert)
{
    Node* before         = insert->PrevSibling;
    insert->PrevSibling  = child;
    child->PrevSibling   = before;
    child->NextSibling   = insert;
    if (before)
        before->NextSibling = child;
    if (insert == FirstChild)
        FirstChild = child;
    child->Parent = this;
}

// @0x1429a7190
bool ElementNode::RemoveAttribute(const char* str, unsigned len)
{
    Attribute* found = 0;
    Attribute* prev  = 0;
    for (Attribute* a = FirstAttribute; a != 0; a = a->Next)
    {
        if (strncmp(str, a->Name.ToCStr(), len) == 0)
        {
            found = a;
            break;
        }
        prev = a;
    }
    if (found)
    {
        if (FirstAttribute == found)
            FirstAttribute = found->Next;
        if (LastAttribute == found)
            LastAttribute = prev;
        if (prev)
            prev->Next = found->Next;
        delete found;
        return true;
    }
    return false;
}

// @0x1429a7250
void ElementNode::RemoveChild(Node* xmlNode)
{
    // Hold the node: unlinking it from FirstChild/NextSibling may drop its last owner.
    Ptr<Node> keep = xmlNode;
    if (xmlNode == FirstChild)
        FirstChild = xmlNode->NextSibling;
    if (xmlNode == LastChild)
        LastChild = xmlNode->PrevSibling;
    if (xmlNode->NextSibling)
        xmlNode->NextSibling->PrevSibling = xmlNode->PrevSibling;
    if (xmlNode->PrevSibling)
        xmlNode->PrevSibling->NextSibling = xmlNode->NextSibling;
    xmlNode->Parent      = 0;
    xmlNode->NextSibling = 0;
    xmlNode->PrevSibling = 0;
}

} // namespace XML
}} // namespace Scaleform::GFx

// Scaleform is built without RTTI: the vftables are pinned by hand (RefCountBaseStatImpl<RefCountNTSImpl> is the
// XML_Object TU's copy, the linker kept the first one).
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BEG@@Scaleform@@6B@ 0x1432247d8
// MS2-PIN: ??_7?$RefCountBaseNTS@UNode@XML@GFx@Scaleform@@$0BEG@@Scaleform@@6B@ 0x1432247f8
// MS2-PIN: ??_7Node@XML@GFx@Scaleform@@6B@ 0x143224800
// MS2-PIN: ??_G?$RefCountBaseNTS@UNode@XML@GFx@Scaleform@@$0BEG@@Scaleform@@UEAAPEAXI@Z 0x1429a6b00
// MS2-PIN: ??_7ElementNode@XML@GFx@Scaleform@@6B@ 0x143224810
// MS2-PIN: ??_7TextNode@XML@GFx@Scaleform@@6B@ 0x143224820
// MS2-PIN: ??_7Document@XML@GFx@Scaleform@@6B@ 0x143224830
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
