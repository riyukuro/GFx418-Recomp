// Recovered Scaleform 4.1.18 GFx XML: DOM node tree (element/text/document nodes, attributes, prefixes).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_XML_DOCUMENT_H
#define MS2_SF_GFX_XML_DOCUMENT_H

#include "xml_object.h"

namespace Scaleform { namespace GFx { namespace XML {

class DOMBuilder;

// Script-side wrapper attached to a node (AS2/AS3 XMLNode); deleted with the node.
struct ShadowRefBase : NewOverrideBase<StatMV_XML_Mem>
{
public:
    virtual ~ShadowRefBase() {}
};

// name="value" pair, singly linked per element: 0x18 bytes.
struct Attribute : public NewOverrideBase<StatMV_XML_Mem>
{
    DOMString  Name;
    DOMString  Value;
    Attribute* Next;

    Attribute(DOMString name, DOMString value) : Name(name), Value(value), Next(0) {}
};

// xmlns prefix binding.
struct Prefix : public RefCountBaseNTS<Prefix, StatMV_XML_Mem>
{
    DOMString Name;
    DOMString Value;

    Prefix(DOMString name, DOMString value) : Name(name), Value(value) {}
};

// Common node part: 0x48 bytes. Children are owned through NextSibling (Ptr), PrevSibling/Parent are weak.
struct Node : public RefCountBaseNTS<Node, StatMV_XML_Mem>
{
    Ptr<ObjectManager> MemoryManager;
    DOMString          Value;
    ElementNode*       Parent;
    Node*              PrevSibling;
    Ptr<Node>          NextSibling;
    ShadowRefBase*     pShadow;
    UByte              Type;

    virtual Node* Clone(bool deep) = 0;

protected:
    Node(ObjectManager* memMgr, UByte type);
    Node(ObjectManager* memMgr, UByte type, DOMString value);
    virtual ~Node();
};

const UByte ElementNodeType = 1;
const UByte TextNodeType    = 3;

// 0x78 bytes.
struct ElementNode : public Node
{
    DOMString  Prefix;
    DOMString  Namespace;
    Attribute* FirstAttribute;
    Attribute* LastAttribute;
    Ptr<Node>  FirstChild;
    Node*      LastChild;

    ElementNode(ObjectManager* memMgr);
    ElementNode(ObjectManager* memMgr, DOMString value);
    ~ElementNode();

    Node* Clone(bool deep);

    void AppendChild(Node* xmlNode);
    void InsertBefore(Node* child, Node* insert);
    void RemoveChild(Node* xmlNode);
    bool HasChildren();

    void AddAttribute(Attribute* xmlAttrib);
    bool RemoveAttribute(const char* str, unsigned len);
    void ClearAttributes();
    bool HasAttributes();

protected:
    void CloneHelper(ElementNode* clone, bool deep);
};

struct TextNode : public Node
{
    TextNode(ObjectManager* memMgr, DOMString value);
    ~TextNode();

    Node* Clone(bool deep);
};

// Root element of a parsed document: 0x90 bytes.
struct Document : public ElementNode
{
    DOMString XMLVersion;
    DOMString Encoding;
    SByte     Standalone;

    Document(ObjectManager* memMgr);
    ~Document();

    Node* Clone(bool deep);
};

// Keeps a DOM tree alive for script objects.
struct RootNode : public RefCountBaseNTS<RootNode, StatMV_XML_Mem>
{
    Ptr<Node> pDOMTree;

    RootNode(Node* pdom) : pDOMTree(pdom) {}
};

}}} // namespace Scaleform::GFx::XML

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::XML::ElementNode) == 0x78, "ElementNode size");
static_assert(sizeof(Scaleform::GFx::XML::TextNode) == 0x48, "TextNode size");

#endif
