// Recovered Scaleform 4.1.18 GFx AS2: XMLNode, the script view of an XML DOM node (the node tree itself lives in
// gfx/xml; the script object is attached to its node through an XMLShadowRef).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_XMLNODE_H
#define MS2_SF_GFX_AS2_XMLNODE_H

#include "as2_action.h"
#include "as2_objectproto.h"
#include "../gfx_asstringhash.h"
#include "../xml/xml_document.h"

namespace Scaleform { namespace GFx { namespace AS2 {

class XmlNodeObject;

// What a DOM node keeps of its script object: the object (weak) and the attributes object. 0x18 bytes;
// vftable 0x1432238c8.
struct XMLShadowRef : XML::ShadowRefBase
{
    XmlNodeObject* pASNode;
    Ptr<Object>    pAttributes;

    XMLShadowRef() : pASNode(0) {}
};

// Adds an entry to pobj for every element below elemNode that has an id attribute (exe 0x14299f4e0).
void Xml_CreateIDMap(Environment* penv, XML::ElementNode* elemNode, XML::RootNode* proot, Object* pobj);

// An XMLNode instance. 0x78 bytes; vftables 0x1432238d0 (Object), 0x143223918 (ObjectInterface).
class XmlNodeObject : public Object
{
    friend class XmlNodeProto;
    friend class XmlNodeCtorFunction;

protected:
    // Detaches the node's shadow before the collector frees this.
    void Finalize_GC()
    {
        if (pRealNode && pRealNode->pShadow)
            static_cast<XMLShadowRef*>(pRealNode->pShadow)->pASNode = 0;
        pRootNode = 0;
        Object::Finalize_GC();
    }

    // Only the prototype object is built this way.
    XmlNodeObject(ASStringContext* psc, Object* pprototype) : Object(psc), pRealNode(0)
    {
        Set__proto__(psc, pprototype);
    }
    virtual ~XmlNodeObject(); // exe 0x14299d010

public:
    Ptr<XML::RootNode> pRootNode; // +0x68, keeps the tree alive
    XML::Node*         pRealNode; // +0x70

    XmlNodeObject(Environment* penv); // exe 0x14299c8b0

    virtual ObjectType GetObjectType() const { return Object_XMLNode; }

    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());                       // exe 0x14299ede0
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);       // exe 0x14299daa0

    // The members answered from the DOM node (ids in the order of the member table).
    enum StandardMember
    {
        M_InvalidMember = -1,
        M_attributes    = 0,
        M_childNodes,
        M_firstChild,
        M_lastChild,
        M_localName,
        M_namespaceURI,
        M_nextSibling,
        M_nodeName,
        M_nodeType,
        M_nodeValue,
        M_parentNode,
        M_prefix,
        M_previousSibling,
        M_XMLNodeMemberCount
    };

    StandardMember GetStandardMemberConstant(Environment* penv, const ASString& memberName) const; // exe 0x14299e190
    static void    InitializeStandardMembers(GlobalContext& gc, ASStringHash<char>& hash);      // exe 0x14299e710
};

// XMLNode.prototype. 0xc0 bytes; vftables 0x143223ab8, 0x143223b00 (ObjectInterface), 0x143223ba8
// (GASPrototypeBase).
class XmlNodeProto : public Prototype<XmlNodeObject>
{
protected:
    void Finalize_GC()
    {
        XMLNodeMemberMap.~ASStringHash<char>();
        Prototype<XmlNodeObject>::Finalize_GC();
    }

public:
    ASStringHash<char> XMLNodeMemberMap; // +0xb8, member name -> StandardMember

    XmlNodeProto(ASStringContext* psc, Object* prototype, const FunctionRef& constructor); // exe 0x14299c920

    static const NameFunction FunctionTable[]; // exe 0x143223830

    static void AppendChild(const FnCall& fn);           // exe 0x14299b650
    static void CloneNode(const FnCall& fn);             // exe 0x14299b880
    static void GetNamespaceForPrefix(const FnCall& fn); // exe 0x14299ba60
    static void GetPrefixForNamespace(const FnCall& fn); // exe 0x14299bd20
    static void HasChildNodes(const FnCall& fn);         // exe 0x14299c0e0
    static void InsertBefore(const FnCall& fn);          // exe 0x14299c1a0
    static void RemoveNode(const FnCall& fn);            // exe 0x14299c370
    static void ToString(const FnCall& fn);              // exe 0x14299c450
};

// The XMLNode class object. 0x70 bytes; vftables 0x143223bb0, 0x143223c38 (ObjectInterface).
class XmlNodeCtorFunction : public CFunctionObject
{
public:
    XmlNodeCtorFunction(ASStringContext* psc); // exe 0x14299c870

    static void        GlobalCtor(const FnCall& fn);                 // exe 0x14299e270
    virtual Object*    CreateNewObject(Environment* penv) const;     // exe 0x14299d800
    static FunctionRef Register(GlobalContext* pgc);                 // exe 0x14299e820
};

}}} // namespace Scaleform::GFx::AS2

#endif
