// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 XMLNode (gap recovery of
// sfr_as2_07): the script view of an XML DOM node, its prototype methods, the shadow links between DOM nodes and
// their script objects, and the XMLNode class object.
// MS2-UNIT: sfr_as2_07d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14299b650-0x14299f7f0 .text$mn

// The exe calls Value::~Value out of line throughout this file.
#define MS2_AS2_VALUE_DTOR_CALL
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_xmlnode.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/xml/xml_document.h"
#include "../include/gfx/xml/xml_object.h"

#include <string.h>

void FUN_14000b9e0(Scaleform::UPInt* tableRef, void* owner, void** pair, Scaleform::UPInt hash);
namespace Scaleform { namespace GFx { namespace AS2 { class FnCall; class Value; }}}
Scaleform::GFx::AS2::Value* FUN_1429316c0(const Scaleform::GFx::AS2::FnCall* pfn, int n);
void FUN_142990c40(const Scaleform::GFx::AS2::FnCall* pfn, const char* pclassName, const char*, int);

namespace Scaleform { namespace GFx { namespace AS2 {

bool CheckThisPtrCopy(const FnCall* pfn, unsigned type); // sfr_as2_04e

namespace {

// fn.Arg(n) through the exe's out-of-line FnCall::Arg (sfr_as2_04e).
SF_FORCEINLINE Value& NodeArg(const FnCall& fn, int n)
{
    return *::FUN_1429316c0(&fn, n);
}

// The methods accept an XMLNode or an XML object as this; anything else reports the error and returns false.
SF_FORCEINLINE bool CheckNodeThis(const FnCall& fn)
{
    bool isNode = CheckThisPtrCopy(&fn, ObjectInterface::Object_XMLNode);
    bool isXml  = CheckThisPtrCopy(&fn, ObjectInterface::Object_XML);
    if (!isNode && !isXml)
    {
        ::FUN_142990c40(&fn, "XMLNode", 0, 0);
        return false;
    }
    return true;
}

SF_FORCEINLINE XmlNodeObject* NodeThis(const FnCall& fn)
{
    return static_cast<XmlNodeObject*>(fn.ThisPtr);
}

// The script object of pnode, created (and linked to the tree root) when the node has none yet.
SF_FORCEINLINE void SetNodeObject(Environment* penv, Value* val, XML::Node* pnode, XML::RootNode* proot);

} // namespace

// The member names answered from the DOM node, in StandardMember order.
struct XmlNodeMemberEntry
{
    const char*                   pName;
    XmlNodeObject::StandardMember Id;
};

XmlNodeMemberEntry XmlNodeObject_MemberTable[] = {
    { "attributes", XmlNodeObject::M_attributes },
    { "childNodes", XmlNodeObject::M_childNodes },
    { "firstChild", XmlNodeObject::M_firstChild },
    { "lastChild", XmlNodeObject::M_lastChild },
    { "localName", XmlNodeObject::M_localName },
    { "namespaceURI", XmlNodeObject::M_namespaceURI },
    { "nextSibling", XmlNodeObject::M_nextSibling },
    { "nodeName", XmlNodeObject::M_nodeName },
    { "nodeType", XmlNodeObject::M_nodeType },
    { "nodeValue", XmlNodeObject::M_nodeValue },
    { "parentNode", XmlNodeObject::M_parentNode },
    { "prefix", XmlNodeObject::M_prefix },
    { "previousSibling", XmlNodeObject::M_previousSibling },
    { 0, XmlNodeObject::M_InvalidMember }
};

void                SetupShadow(Environment* penv, XML::Node* preal, XmlNodeObject* asobj);
Ptr<XmlNodeObject>  CreateShadow(Environment* penv, XML::Node* preal, XML::RootNode* proot);
void                ResolveNamespace(Environment* penv, XML::ElementNode* elemNode, XML::RootNode* proot);
void                BuildXMLString(Environment* penv, XML::Node* proot, StringBuffer& dest);

// Answers prefix lookups: remembers the xmlns attribute whose value is the namespace asked for.
struct XMLPrefixQuerier : public ObjectInterface::MemberVisitor
{
    Environment* pEnv;
    ASString&    pKey;
    Value&       pVal;

    XMLPrefixQuerier(Environment* penv, ASString& pkey, Value& pval) : pEnv(penv), pKey(pkey), pVal(pval) {}

    void Visit(const ASString& name, const Value& val, UByte flags);
};

// Appends name="value" for every attribute it visits.
struct XMLAttributeStringBuilder : public ObjectInterface::MemberVisitor
{
    Environment*  pEnv;
    StringBuffer& Dest;

    XMLAttributeStringBuilder(Environment* penv, StringBuffer& dest) : pEnv(penv), Dest(dest) {}

    void Visit(const ASString& name, const Value& val, UByte flags);
};

namespace {

SF_FORCEINLINE void SetNodeObject(Environment* penv, Value* val, XML::Node* pnode, XML::RootNode* proot)
{
    XMLShadowRef* pshadow = static_cast<XMLShadowRef*>(pnode->pShadow);
    if (!pshadow || !pshadow->pASNode)
        val->SetAsObject(CreateShadow(penv, pnode, proot));
    else
        val->SetAsObject(pshadow->pASNode);
}

// Takes pchild's node out of its parent (kept alive meanwhile) and appends it to elemNode.
SF_FORCEINLINE void MoveChild(XML::ElementNode* elemNode, XmlNodeObject* pthis, XmlNodeObject* pchild,
                              XML::Node* pinsert)
{
    Ptr<XML::Node> selfptr = pchild->pRealNode;
    if (pchild->pRealNode->Parent)
        pchild->pRealNode->Parent->RemoveChild(pchild->pRealNode);
    if (pinsert)
        elemNode->InsertBefore(pchild->pRealNode, pinsert);
    else
        elemNode->AppendChild(pchild->pRealNode);
    pchild->pRootNode.SetPtr(pthis->pRootNode);
}

} // namespace

// MS2-FUNCTIONAL: the exe inlines the Ptr<RootNode> assignment; ours calls it
// @0x14299b650
void XmlNodeProto::AppendChild(const FnCall& fn)
{
    if (!CheckNodeThis(fn))
        return;
    XmlNodeObject* pthis = NodeThis(fn);
    if (!pthis)
        return;
    Log* log = fn.GetLog();
    if (!pthis->pRealNode)
        return;
    if (pthis->pRealNode->Type == XML::ElementNodeType)
    {
        XML::ElementNode* elemNode = static_cast<XML::ElementNode*>(pthis->pRealNode);
        if (fn.NArgs <= 0)
            return;
        Object* p = NodeArg(fn, 0).ToObject(fn.Env);
        if (p && p->GetObjectType() == Object_XMLNode)
        {
            XmlNodeObject* pchild = static_cast<XmlNodeObject*>(p);
            if (!pchild->pRealNode)
                return;
            // A node cannot take the root of its own tree as a child.
            XML::Node* ptopmost = pthis->pRealNode->Parent;
            while (ptopmost && ptopmost->Parent)
                ptopmost = ptopmost->Parent;
            if (ptopmost == pchild->pRealNode)
            {
                if (log)
                    log->LogMessageById(Log_ScriptWarning,
                                        "XMLNode::appendChild - trying to add a child that is the root of the current tree");
                return;
            }
            Ptr<XML::Node> selfptr = pchild->pRealNode;
            if (pchild->pRealNode->Parent)
                pchild->pRealNode->Parent->RemoveChild(pchild->pRealNode);
            elemNode->AppendChild(pchild->pRealNode);
            pchild->pRootNode.SetPtr(pthis->pRootNode);
            if (pchild->pRealNode->Type == XML::ElementNodeType)
            {
                XML::ElementNode* elemChild = static_cast<XML::ElementNode*>(pchild->pRealNode);
                if (elemChild->Namespace.GetSize() == 0)
                    ResolveNamespace(fn.Env, elemChild, pthis->pRootNode);
            }
        }
        else if (log)
            log->LogMessageById(Log_ScriptWarning,
                                "XMLNode::appendChild - trying to add a child that is not of type XMLNode");
    }
    else if (log)
        log->LogMessageById(Log_ScriptWarning, "XMLNode::appendChild - trying to add a child to a text node");
}

// cloneNode(deep): a copy of the node in a tree of its own.
// @0x14299b880
void XmlNodeProto::CloneNode(const FnCall& fn)
{
    if (!CheckNodeThis(fn))
        return;
    XmlNodeObject* pthis = NodeThis(fn);
    if (!pthis || !pthis->pRealNode)
        return;
    bool deepCopy = false;
    if (fn.NArgs > 0)
        deepCopy = NodeArg(fn, 0).ToBool(fn.Env);
    if (pthis->pRealNode->Type == XML::ElementNodeType)
    {
        Ptr<XML::Node>     realclone = *pthis->pRealNode->Clone(deepCopy);
        Ptr<XmlNodeObject> clone     = CreateShadow(fn.Env, realclone, 0);
        fn.Result->SetAsObject(clone);
    }
    else
    {
        XML::Node*         ptext     = pthis->pRealNode;
        Ptr<XML::Node>     realclone = *pthis->pRealNode->Clone(deepCopy);
        Ptr<XmlNodeObject> clone     = CreateShadow(fn.Env, realclone, 0);
        realclone->Type              = ptext->Type;
        fn.Result->SetAsObject(clone);
    }
}

// getNamespaceForPrefix(prefix): the value of the nearest xmlns[:prefix] attribute up the tree, or null.
// MS2-FUNCTIONAL: register allocation and stack-slot order differ
// @0x14299ba60
void XmlNodeProto::GetNamespaceForPrefix(const FnCall& fn)
{
    if (!CheckNodeThis(fn))
        return;
    XmlNodeObject* pthis = NodeThis(fn);
    if (!pthis)
        return;
    fn.Result->SetNull();
    Log* log = fn.GetLog();
    if (!pthis->pRealNode)
        return;
    if (pthis->pRealNode->Type == XML::ElementNodeType)
    {
    XML::ElementNode* elemNode = static_cast<XML::ElementNode*>(pthis->pRealNode);
    if (fn.NArgs < 1)
        return;
    ASString str      = NodeArg(fn, 0).ToString(fn.Env);
    ASString pfxquery = fn.Env->GetSC()->CreateString("xmlns", 5);
    if (str.GetSize() > 0)
    {
        pfxquery += ":";
        pfxquery += str.ToCStr();
    }
    Value         qval;
    XMLShadowRef* pshadow  = static_cast<XMLShadowRef*>(elemNode->pShadow);
    Object*       pattribs = pshadow->pAttributes;
    pattribs->GetMember(fn.Env, pfxquery, &qval);
    if (!qval.IsUndefined())
    {
        fn.Result->SetString(qval.ToString(fn.Env));
        return;
    }
    for (XML::ElementNode* parent = elemNode->Parent; parent; parent = parent->Parent)
    {
        if (!parent->pShadow)
            CreateShadow(fn.Env, parent, pthis->pRootNode);
        pshadow  = static_cast<XMLShadowRef*>(parent->pShadow);
        pattribs = pshadow->pAttributes;
        pattribs->GetMember(fn.Env, pfxquery, &qval);
        if (!qval.IsUndefined())
        {
            fn.Result->SetString(qval.ToString(fn.Env));
            return;
        }
    }
    }
    else if (log)
        log->LogMessageById(Log_ScriptWarning,
                            "XMLNodeProto::GetNamespaceForPrefix - only element nodes support this method.");
}

// getPrefixForNamespace(uri): the prefix of the nearest xmlns attribute up the tree whose value is uri, or null.
// MS2-FUNCTIONAL: the exe keeps the AddRef/Release pair of the inlined SetString; register allocation differs
// @0x14299bd20
void XmlNodeProto::GetPrefixForNamespace(const FnCall& fn)
{
    if (!CheckNodeThis(fn))
        return;
    XmlNodeObject* pthis = NodeThis(fn);
    if (!pthis)
        return;
    fn.Result->SetNull();
    ASStringContext* psc = fn.Env->GetSC();
    Log*             log = fn.GetLog();
    if (!pthis->pRealNode)
        return;
    if (pthis->pRealNode->Type == XML::ElementNodeType)
    {
    XML::ElementNode* elemNode = static_cast<XML::ElementNode*>(pthis->pRealNode);
    if (fn.NArgs < 1)
        return;
    ASString         str = NodeArg(fn, 0).ToString(fn.Env);
    Value            qval;
    XMLPrefixQuerier pq(fn.Env, str, qval);
    XMLShadowRef*    pshadow  = static_cast<XMLShadowRef*>(elemNode->pShadow);
    Object*          pattribs = pshadow->pAttributes;
    pattribs->VisitMembers(psc, &pq, 0);
    if (!qval.IsUndefined())
        fn.Result->SetString(qval.ToString(fn.Env));
    XML::ElementNode* parent = elemNode->Parent;
    while (fn.Result->IsNull() && parent)
    {
        if (!parent->pShadow)
            CreateShadow(fn.Env, parent, pthis->pRootNode);
        pshadow  = static_cast<XMLShadowRef*>(parent->pShadow);
        pattribs = pshadow->pAttributes;
        pattribs->VisitMembers(psc, &pq, 0);
        if (!qval.IsUndefined())
            fn.Result->SetString(qval.ToString(fn.Env));
        parent = parent->Parent;
    }
    if (!fn.Result->IsNull())
    {
        // The attribute name is "xmlns" or "xmlns:<prefix>"; answer the part after it.
        ASString    pfx   = fn.Result->ToString(fn.Env);
        const char* data  = pfx.ToCStr();
        const char* colon = strchr(data, ':');
        if (colon)
            fn.Result->SetString(psc->CreateString(data + 6, pfx.GetSize() - 6));
        else
            fn.Result->SetString(psc->CreateString(data + 5, pfx.GetSize() - 5));
    }
    }
    else if (log)
        log->LogMessageById(Log_ScriptWarning,
                            "XMLNodeProto::GetNamespaceForPrefix - only element nodes support this method.");
}

// @0x14299c0e0
void XmlNodeProto::HasChildNodes(const FnCall& fn)
{
    if (!CheckNodeThis(fn))
        return;
    XmlNodeObject* pthis = NodeThis(fn);
    if (!pthis)
        return;
    fn.Result->SetBool(false);
    if (pthis->pRealNode && pthis->pRealNode->Type == XML::ElementNodeType)
        fn.Result->SetBool(static_cast<XML::ElementNode*>(pthis->pRealNode)->HasChildren());
}

// insertBefore(child, before): appends child when before is not one of this node's children.
// MS2-FUNCTIONAL: the exe inlines the Ptr<RootNode> assignment; block layout differs
// @0x14299c1a0
void XmlNodeProto::InsertBefore(const FnCall& fn)
{
    if (!CheckNodeThis(fn))
        return;
    XmlNodeObject* pthis = NodeThis(fn);
    if (!pthis || !pthis->pRealNode || pthis->pRealNode->Type != XML::ElementNodeType)
        return;
    XML::ElementNode* elemNode = static_cast<XML::ElementNode*>(pthis->pRealNode);
    if (fn.NArgs <= 1)
        return;
    Object* child  = NodeArg(fn, 0).ToObject(fn.Env);
    Object* insert = NodeArg(fn, 1).ToObject(fn.Env);
    if (!child || child->GetObjectType() != Object_XMLNode)
        return;
    XmlNodeObject* pchild  = static_cast<XmlNodeObject*>(child);
    XmlNodeObject* pinsert = static_cast<XmlNodeObject*>(insert);
    if (pinsert && pinsert->GetObjectType() == Object_XMLNode && pinsert->pRealNode &&
        pinsert->pRealNode->Parent && pinsert->pRealNode->Parent == elemNode)
    {
        if (pchild->pRealNode)
            MoveChild(elemNode, pthis, pchild, pinsert->pRealNode);
    }
    else if (pchild->pRealNode)
        MoveChild(elemNode, pthis, pchild, 0);
}

// removeNode(): detaches the node; it keeps a root of its own.
// @0x14299c370
void XmlNodeProto::RemoveNode(const FnCall& fn)
{
    if (!CheckNodeThis(fn))
        return;
    XmlNodeObject* pthis = NodeThis(fn);
    if (!pthis || !pthis->pRealNode)
        return;
    XML::ElementNode* parent = pthis->pRealNode->Parent;
    if (parent)
    {
        pthis->pRootNode = *parent->MemoryManager->CreateRootNode(pthis->pRealNode);
        parent->RemoveChild(pthis->pRealNode);
    }
}

// toString(): the markup of an element, the value of any other node.
// MS2-FUNCTIONAL: instruction scheduling differs
// @0x14299c450
void XmlNodeProto::ToString(const FnCall& fn)
{
    if (!CheckNodeThis(fn))
        return;
    XmlNodeObject* pthis = NodeThis(fn);
    if (!pthis)
        return;
    StringBuffer str;
    if (pthis->pRealNode)
    {
        if (pthis->pRealNode->Type == XML::ElementNodeType)
            BuildXMLString(fn.Env, pthis->pRealNode, str);
        else
            str.AppendString(pthis->pRealNode->Value.ToCStr());
        fn.Result->SetString(fn.Env->GetSC()->pContext->GetStringManager()->CreateString(str.ToCStr(), str.GetSize()));
    }
    else
        fn.Result->SetUndefined();
}

// The collector traversal of XMLNode.prototype.
template void Prototype<XmlNodeObject>::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector* prcc) const;
template void Prototype<XmlNodeObject>::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector* prcc) const;
template void Prototype<XmlNodeObject>::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector* prcc) const;

// @0x14299c870
XmlNodeCtorFunction::XmlNodeCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor)
{
}

// @0x14299c8b0
XmlNodeObject::XmlNodeObject(Environment* penv) : Object(penv), pRealNode(0)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_XMLNode));
}

// The prototype holds the methods and an undefined placeholder for every node member (only attributes, nodeName
// and nodeValue are writable).
// MS2-FUNCTIONAL: register allocation of the inlined member-table setup differs
// @0x14299c920
XmlNodeProto::XmlNodeProto(ASStringContext* psc, Object* prototype, const FunctionRef& constructor)
    : Prototype<XmlNodeObject>(psc, prototype, constructor)
{
    const PropFlags readOnly(PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete);
    const PropFlags writable(PropFlags::PropFlag_DontDelete);
    InitFunctionMembers(this, psc, FunctionTable, readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("attributes"), Value(), writable);
    Object::SetMemberRaw(psc, psc->CreateConstString("childNodes"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("firstChild"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("lastChild"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("localName"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("namespaceURI"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("nextSibling"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("nodeName"), Value(), writable);
    Object::SetMemberRaw(psc, psc->CreateConstString("nodeType"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("nodeValue"), Value(), writable);
    Object::SetMemberRaw(psc, psc->CreateConstString("parentNode"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("prefix"), Value(), readOnly);
    Object::SetMemberRaw(psc, psc->CreateConstString("previousSibling"), Value(), readOnly);
}

// @0x14299d010
XmlNodeObject::~XmlNodeObject()
{
    if (pRealNode && pRealNode->pShadow)
        static_cast<XMLShadowRef*>(pRealNode->pShadow)->pASNode = 0;
}

// Writes the markup of preal (and its subtree) to dest; an XML document contributes its declaration and children.
// MS2-FUNCTIONAL: register allocation and block layout differ
// @0x14299d3c0
void BuildXMLString(Environment* penv, XML::Node* proot, StringBuffer& dest)
{
    if (proot->Type != XML::ElementNodeType)
    {
        dest.AppendString(proot->Value.ToCStr());
        return;
    }
    XML::ElementNode* pnode   = static_cast<XML::ElementNode*>(proot);
    XMLShadowRef*     pshadow = static_cast<XMLShadowRef*>(proot->pShadow);
    if (pshadow && pshadow->pASNode && pshadow->pASNode->GetObjectType() == ObjectInterface::Object_XML)
    {
        XmlNodeObject* pobj = pshadow->pASNode;
        Value          xmldecl;
        pobj->GetMember(penv, penv->GetSC()->CreateConstString("xmlDecl"), &xmldecl);
        if (!xmldecl.IsUndefined())
        {
            dest.AppendString(xmldecl.ToString(penv).ToCStr());
            Value ignorews;
            pobj->GetMember(penv, penv->GetSC()->CreateConstString("ignoreWhite"), &ignorews);
            if (!ignorews.ToBool(penv))
                dest.AppendString("\n");
        }
        for (XML::Node* child = pnode->FirstChild; child; child = child->NextSibling)
            BuildXMLString(penv, child, dest);
        return;
    }
    dest.AppendString("<");
    if (pnode->Prefix.GetSize() > 0)
    {
        dest.AppendString(pnode->Prefix.ToCStr());
        dest.AppendString(":");
    }
    dest.AppendString(proot->Value.ToCStr());
    if (pshadow && pshadow->pAttributes)
    {
        XMLAttributeStringBuilder attrvis(penv, dest);
        Object*                   attrs = pshadow->pAttributes;
        if (attrs)
            attrs->VisitMembers(penv->GetSC(), &attrvis, 0);
    }
    else
    {
        for (XML::Attribute* attr = pnode->FirstAttribute; attr; attr = attr->Next)
        {
            dest.AppendString(" ");
            dest.AppendString(attr->Name.ToCStr());
            dest.AppendString("=\"");
            dest.AppendString(attr->Value.ToCStr());
            dest.AppendString("\"");
        }
    }
    if (pnode->HasChildren())
        dest.AppendString(">");
    else
        dest.AppendString(" />");
    for (XML::Node* child = pnode->FirstChild; child; child = child->NextSibling)
        BuildXMLString(penv, child, dest);
    if (pnode->HasChildren())
    {
        dest.AppendString("</");
        if (pnode->Prefix.GetSize() > 0)
        {
            dest.AppendString(pnode->Prefix.ToCStr());
            dest.AppendString(":");
        }
        dest.AppendString(proot->Value.ToCStr());
        dest.AppendString(">");
    }
}

// @0x14299d800
Object* XmlNodeCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) XmlNodeObject(penv);
}

// A new script object for preal, holding proot (or a new root for preal) so the tree stays alive.
// @0x14299d840
Ptr<XmlNodeObject> CreateShadow(Environment* penv, XML::Node* preal, XML::RootNode* proot)
{
    Ptr<XmlNodeObject> asobj = *SF_HEAP_NEW(penv->GetHeap()) XmlNodeObject(penv);
    SetupShadow(penv, preal, asobj);
    if (proot)
        asobj->pRootNode = proot;
    else
        asobj->pRootNode = *preal->MemoryManager->CreateRootNode(preal);
    return asobj;
}

// @0x14299d930
template void Prototype<XmlNodeObject>::Finalize_GC();

// The members the DOM node answers.
// MS2-FUNCTIONAL: the member switch is laid out and inlined differently
// @0x14299daa0
bool XmlNodeObject::GetMember(Environment* penv, const ASString& name, Value* val)
{
    ASStringContext* psc = penv->GetSC();
    if (pRealNode)
    {
        switch (GetStandardMemberConstant(penv, name))
        {
        case M_firstChild:
            if (!pRealNode)
                val->SetUndefined();
            else if (pRealNode->Type == XML::ElementNodeType &&
                     static_cast<XML::ElementNode*>(pRealNode)->HasChildren())
                SetNodeObject(penv, val, static_cast<XML::ElementNode*>(pRealNode)->FirstChild, pRootNode);
            else
                val->SetNull();
            return true;
        case M_nextSibling:
            if (!pRealNode)
                val->SetUndefined();
            else if (pRealNode->NextSibling)
                SetNodeObject(penv, val, pRealNode->NextSibling, pRootNode);
            else
                val->SetNull();
            return true;
        case M_childNodes:
            if (pRealNode && pRealNode->Type == XML::ElementNodeType)
            {
                Ptr<ArrayObject>  parr  = *SF_HEAP_NEW(penv->GetHeap()) ArrayObject(penv);
                XML::ElementNode* pnode = static_cast<XML::ElementNode*>(pRealNode);
                for (XML::Node* child = pnode->FirstChild; child; child = child->NextSibling)
                {
                    XMLShadowRef* pshadow = static_cast<XMLShadowRef*>(child->pShadow);
                    if (!pshadow || !pshadow->pASNode)
                        parr->PushBack(Value(CreateShadow(penv, child, pRootNode)));
                    else
                        parr->PushBack(Value(pshadow->pASNode));
                }
                val->SetAsObject(parr);
            }
            else
                val->SetUndefined();
            return true;
        case M_nodeName:
            if (!pRealNode)
                val->SetUndefined();
            else if (pRealNode->Type == XML::ElementNodeType)
            {
                XML::ElementNode* pelem = static_cast<XML::ElementNode*>(pRealNode);
                if (pelem->Prefix.GetSize() > 0)
                {
                    ASString str = psc->CreateString(pelem->Prefix.ToCStr());
                    str += ":";
                    str += pelem->Value.ToCStr();
                    val->SetString(str);
                }
                else
                    val->SetString(psc->CreateString(pelem->Value.ToCStr()));
            }
            else
                val->SetNull();
            return true;
        case M_nodeValue:
            if (!pRealNode)
                val->SetUndefined();
            else if (pRealNode->Type == XML::ElementNodeType)
                val->SetNull();
            else
                val->SetString(psc->CreateString(pRealNode->Value.ToCStr()));
            return true;
        case M_attributes:
            if (pRealNode)
            {
                XMLShadowRef* pshadow = static_cast<XMLShadowRef*>(pRealNode->pShadow);
                if (!pshadow->pAttributes)
                    pshadow->pAttributes = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
                val->SetAsObject(pshadow->pAttributes);
            }
            else
                val->SetUndefined();
            return true;
        case M_lastChild:
            if (!pRealNode)
                val->SetUndefined();
            else if (pRealNode->Type == XML::ElementNodeType &&
                     static_cast<XML::ElementNode*>(pRealNode)->HasChildren())
                SetNodeObject(penv, val, static_cast<XML::ElementNode*>(pRealNode)->LastChild, pRootNode);
            else
                val->SetNull();
            return true;
        case M_previousSibling:
            if (!pRealNode)
                val->SetUndefined();
            else if (pRealNode->PrevSibling)
                SetNodeObject(penv, val, pRealNode->PrevSibling, pRootNode);
            else
                val->SetNull();
            return true;
        case M_parentNode:
            if (!pRealNode)
                val->SetUndefined();
            else if (pRealNode->Parent)
                SetNodeObject(penv, val, pRealNode->Parent, pRootNode);
            else
                val->SetNull();
            return true;
        case M_localName:
            if (pRealNode && pRealNode->Type == XML::ElementNodeType)
                val->SetString(psc->CreateString(pRealNode->Value.ToCStr()));
            else
                val->SetUndefined();
            return true;
        case M_namespaceURI:
            if (pRealNode && pRealNode->Type == XML::ElementNodeType)
                val->SetString(psc->CreateString(static_cast<XML::ElementNode*>(pRealNode)->Namespace.ToCStr()));
            else
                val->SetUndefined();
            return true;
        case M_prefix:
            if (pRealNode && pRealNode->Type == XML::ElementNodeType)
                val->SetString(psc->CreateString(static_cast<XML::ElementNode*>(pRealNode)->Prefix.ToCStr()));
            else
                val->SetUndefined();
            return true;
        case M_nodeType:
            if (pRealNode)
                val->SetNumber(pRealNode->Type);
            else
                val->SetUndefined();
            return true;
        default:
            break;
        }
    }
    return Object::GetMember(penv, name, val);
}

// "constructor" and "__constructor__" are answered by the prototype part.
// @0x14299e060
template<>
bool Prototype<XmlNodeObject>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    bool isConstructor2 = psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin___constructor__)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive());
    if (isConstructor2 || psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin_constructor)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        return GetMemberRawConstructor(this, psc, name, val, isConstructor2);
    }
    return XmlNodeObject::GetMemberRaw(psc, name, val);
}

// The member id of a standard-member name (M_InvalidMember for anything else).
// MS2-FUNCTIONAL: the exe tests the standard-member flag with shr+test
// @0x14299e190
XmlNodeObject::StandardMember XmlNodeObject::GetStandardMemberConstant(Environment* penv,
                                                                       const ASString& memberName) const
{
    char memberConstant = (char)M_InvalidMember;
    if ((memberName.GetHashFlags() >> 29) & 1) // Flag_StandardMember
    {
        XmlNodeProto* proto = static_cast<XmlNodeProto*>(penv->GetPrototype(ASBuiltin_XMLNode));
        proto->XMLNodeMemberMap.GetCaseCheck(memberName, &memberConstant, true);
    }
    return (StandardMember)memberConstant;
}

// new XMLNode(type, value): an element (value "prefix:name" or "name"), a text node, or a node of another type
// with an empty value.
// MS2-FUNCTIONAL: register allocation and block layout differ
// @0x14299e270
void XmlNodeCtorFunction::GlobalCtor(const FnCall& fn)
{
    Ptr<XmlNodeObject> pnode;
    if (fn.ThisPtr && (fn.ThisPtr->GetObjectType() == Object_XMLNode || fn.ThisPtr->GetObjectType() == Object_XML))
        pnode = static_cast<XmlNodeObject*>(fn.ThisPtr);
    else
        pnode = *SF_HEAP_NEW(fn.Env->GetHeap()) XmlNodeObject(fn.Env);
    Log*  log = fn.GetLog();
    Value nodeType;
    Value nodeValue;
    if (fn.NArgs > 0)
    {
        nodeType = NodeArg(fn, 0);
        if (fn.NArgs > 1)
            nodeValue = NodeArg(fn, 1);
    }
    if (nodeType.IsUndefined())
    {
        if (log)
            log->LogMessageById(Log_ScriptWarning, "XMLNodeCtorFunction::GlobalCtor - node type not specified");
    }
    else
    {
        Number nt = nodeType.ToNumber(fn.Env);
        if (nodeValue.IsUndefined())
        {
            if (log)
                log->LogMessageById(Log_ScriptWarning, "XMLNodeCtorFunction::GlobalCtor - malformed XMLNode object");
        }
        else
        {
            // The movie shares one DOM object manager between its XML objects.
            MovieImpl*              pmovieroot = fn.Env->GetMovieImpl();
            Ptr<XML::ObjectManager> memMgr;
            if (!pmovieroot->pXMLObjectManager)
            {
                memMgr = *SF_HEAP_NEW(fn.Env->GetHeap()) XML::ObjectManager(pmovieroot);
                pmovieroot->pXMLObjectManager = static_cast<ExternalLibPtr*>(memMgr.GetPtr());
            }
            else
                memMgr = static_cast<XML::ObjectManager*>(static_cast<ExternalLibPtr*>(pmovieroot->pXMLObjectManager));
            XML::DOMString localname(memMgr->EmptyString());
            XML::DOMString prefix(memMgr->EmptyString());
            ASString       s = nodeValue.ToString(fn.Env);
            if (nt == XML::ElementNodeType)
            {
                const char* pfx = strchr(s.ToCStr(), ':');
                if (pfx)
                {
                    prefix    = memMgr->CreateString(s.ToCStr(), pfx - s.ToCStr());
                    localname = memMgr->CreateString(pfx + 1, strlen(pfx));
                }
                else
                    localname = memMgr->CreateString(s.ToCStr(), s.GetSize());
                Ptr<XML::ElementNode> en = *memMgr->CreateElementNode(localname);
                pnode->pRealNode         = en;
                pnode->pRootNode         = *memMgr->CreateRootNode(pnode->pRealNode);
                static_cast<XML::ElementNode*>(pnode->pRealNode)->Prefix = prefix;
            }
            else if (nt == XML::TextNodeType)
            {
                localname                = memMgr->CreateString(s.ToCStr(), s.GetSize());
                Ptr<XML::TextNode> tn    = *memMgr->CreateTextNode(localname);
                pnode->pRealNode         = tn;
                pnode->pRootNode         = *memMgr->CreateRootNode(pnode->pRealNode);
            }
            else
            {
                Ptr<XML::TextNode> tn    = *memMgr->CreateTextNode(localname);
                pnode->pRealNode         = tn;
                pnode->pRootNode         = *memMgr->CreateRootNode(pnode->pRealNode);
                pnode->pRealNode->Type   = (UByte)(int)nt;
            }
            SetupShadow(fn.Env, pnode->pRealNode, pnode);
        }
    }
    fn.Result->SetAsObject(pnode.GetPtr());
}

// @0x14299e710
void XmlNodeObject::InitializeStandardMembers(GlobalContext& gc, ASStringHash<char>& hash)
{
    ASStringManager* pstrManager = gc.GetStringManager()->pStringManager;
    hash.SetCapacity(M_XMLNodeMemberCount);
    for (XmlNodeMemberEntry* pentry = XmlNodeObject_MemberTable; pentry->pName; pentry++)
    {
        ASString name(pstrManager->CreateConstString(pentry->pName, strlen(pentry->pName),
                                                     ASString::Flag_StandardMember));
        hash.Add(name, (char)pentry->Id);
    }
}

// MS2-FUNCTIONAL: the exe inlines the XmlNodeCtorFunction ctor, the prototype store and InitializeStandardMembers
// @0x14299e820
FunctionRef XmlNodeCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext    sc(pgc, 8);
    FunctionRef        ctor(*SF_HEAP_NEW(pgc->pHeap) XmlNodeCtorFunction(&sc));
    Ptr<XmlNodeProto>  proto = *SF_HEAP_NEW(pgc->pHeap) XmlNodeProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    {
        Ptr<Object>   pproto = proto.GetPtr();
        ASBuiltinType key    = ASBuiltin_XMLNode;
        void*         pair[2] = { &key, &pproto };
        ::FUN_14000b9e0(reinterpret_cast<UPInt*>(&pgc->Prototypes), &pgc->Prototypes, pair,
                        FixedSizeHash<ASBuiltinType>()(key));
    }
    pgc->pGlobal->SetMemberRaw(&sc, pgc->GetStringManager()->GetBuiltin(ASBuiltin_XMLNode), Value(ctor));
    XmlNodeObject::InitializeStandardMembers(*pgc, proto->XMLNodeMemberMap);
    return ctor;
}

// Finds the namespace of elemNode's prefix in the xmlns attributes of the node and its ancestors (empty when none
// declares it).
// MS2-FUNCTIONAL: register allocation differs
// @0x14299ead0
void ResolveNamespace(Environment* penv, XML::ElementNode* elemNode, XML::RootNode* proot)
{
    ASStringContext* psc      = penv->GetSC();
    ASString         pfxquery = psc->CreateString("xmlns", 5);
    if (elemNode->Prefix.GetSize() > 0)
    {
        pfxquery += ":";
        pfxquery += elemNode->Prefix.ToCStr();
    }
    Value qval;
    elemNode->Namespace     = elemNode->MemoryManager->EmptyString();
    XMLShadowRef* pshadow   = static_cast<XMLShadowRef*>(elemNode->pShadow);
    Object*       pattribs  = pshadow->pAttributes;
    pattribs->GetMember(penv, pfxquery, &qval);
    if (!qval.IsUndefined())
    {
        ASString ns         = qval.ToString(penv);
        elemNode->Namespace = elemNode->MemoryManager->CreateString(ns.ToCStr(), ns.GetSize());
        return;
    }
    for (XML::ElementNode* parent = elemNode->Parent; parent; parent = parent->Parent)
    {
        if (!parent->pShadow)
            CreateShadow(penv, parent, proot);
        pshadow  = static_cast<XMLShadowRef*>(parent->pShadow);
        pattribs = pshadow->pAttributes;
        pattribs->GetMember(penv, pfxquery, &qval);
        if (!qval.IsUndefined())
        {
            ASString ns         = qval.ToString(penv);
            elemNode->Namespace = elemNode->MemoryManager->CreateString(ns.ToCStr(), ns.GetSize());
            break;
        }
    }
}

// Element node members: nodeName (re-resolving the namespace), nodeValue of the other nodes, and the attributes
// object.
// MS2-FUNCTIONAL: the member switch is laid out and inlined differently
// @0x14299ede0
bool XmlNodeObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    Log* log = penv->GetLog();
    if (pRealNode)
    {
        switch (GetStandardMemberConstant(penv, name))
        {
        case M_nodeName:
            if (!pRealNode)
            {
                if (log)
                    log->LogMessageById(Log_ScriptWarning,
                                        "XMLNodeObject::SetMember - cannot set nodeName of a malformed node");
            }
            else if (pRealNode->Type == XML::ElementNodeType)
            {
                XML::ElementNode* elemNode = static_cast<XML::ElementNode*>(pRealNode);
                XML::DOMString    prefix(pRealNode->MemoryManager->EmptyString());
                ASString          str   = val.ToString(penv);
                const char*       data  = str.ToCStr();
                const char*       colon = strchr(data, ':');
                if (colon)
                {
                    prefix           = pRealNode->MemoryManager->CreateString(data, colon - data);
                    pRealNode->Value = pRealNode->MemoryManager->CreateString(colon + 1, strlen(colon + 1));
                }
                else
                    pRealNode->Value = pRealNode->MemoryManager->CreateString(str.ToCStr(), str.GetSize());
                elemNode->Prefix = prefix;
                ResolveNamespace(penv, elemNode, pRootNode);
            }
            else if (log)
                log->LogMessageById(Log_ScriptWarning,
                                    "XMLNodeObject::SetMember - cannot set nodeName of node type %d. Only type 1 allowed",
                                    pRealNode->Type);
            return true;
        case M_nodeValue:
            if (pRealNode && pRealNode->Type != XML::ElementNodeType)
            {
                ASString str     = val.ToString(penv);
                pRealNode->Value = pRealNode->MemoryManager->CreateString(str.ToCStr(), str.GetSize());
            }
            else if (log)
                log->LogMessageById(Log_ScriptWarning,
                                    "XMLNodeObject::SetMember - cannot set nodeValue of a malformed node");
            return true;
        case M_attributes:
            if (!pRealNode)
            {
                if (log)
                    log->LogMessageById(Log_ScriptWarning,
                                        "XMLNodeObject::SetMember - cannot set attributes of a malformed node");
            }
            else if (pRealNode->Type == XML::ElementNodeType)
                static_cast<XMLShadowRef*>(pRealNode->pShadow)->pAttributes = val.ToObject(penv);
            else if (log)
                log->LogMessageById(Log_ScriptWarning,
                                    "XMLNodeObject::SetMember - cannot set attributes of node type %d. Only type 1 allowed",
                                    pRealNode->Type);
            return true;
        default:
            break;
        }
    }
    return Object::SetMember(penv, name, val, flags);
}

// Moves the DOM attributes of preal into a script object held by its shadow.
// MS2-FUNCTIONAL: block layout differs
// @0x14299f130
void SetupAttributes(Environment* penv, XML::ElementNode* preal)
{
    XMLShadowRef*    pshadow = static_cast<XMLShadowRef*>(preal->pShadow);
    ASStringContext* psc     = penv->GetSC();
    pshadow->pAttributes     = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    if (preal->HasAttributes())
    {
        for (XML::Attribute* attr = preal->FirstAttribute; attr; attr = attr->Next)
            pshadow->pAttributes->SetMember(penv, psc->CreateString(attr->Name.ToCStr()),
                                            Value(psc->CreateString(attr->Value.ToCStr())));
        preal->ClearAttributes();
    }
}

// Links preal and asobj (giving preal a shadow, and an element its attributes object, the first time).
// @0x14299f2d0
void SetupShadow(Environment* penv, XML::Node* preal, XmlNodeObject* asobj)
{
    if (!preal->pShadow)
    {
        preal->pShadow = SF_HEAP_NEW(preal->MemoryManager->GetHeap()) XMLShadowRef();
        if (preal->Type == XML::ElementNodeType)
            SetupAttributes(penv, static_cast<XML::ElementNode*>(preal));
    }
    static_cast<XMLShadowRef*>(preal->pShadow)->pASNode = asobj;
    asobj->pRealNode                                    = preal;
}

// MS2-FUNCTIONAL: the exe tail-calls AppendString differently
// @0x14299f370
void XMLAttributeStringBuilder::Visit(const ASString& name, const Value& val, UByte)
{
    Dest.AppendString(" ");
    Dest.AppendString(name.ToCStr());
    Dest.AppendString("=\"");
    Dest.AppendString(val.ToString(pEnv).ToCStr());
    Dest.AppendString("\"");
}

// MS2-FUNCTIONAL: register allocation differs
// @0x14299f440
void XMLPrefixQuerier::Visit(const ASString& name, const Value& val, UByte)
{
    ASString valstr = val.ToString(pEnv);
    if (valstr.GetNode() == pKey.GetNode() && !strncmp(name.ToCStr(), "xmlns", 5))
        pVal.SetString(name);
}

// Adds a member named after the id attribute of every element below elemNode, holding its script object.
// MS2-FUNCTIONAL: register allocation and block layout differ
// @0x14299f4e0
void Xml_CreateIDMap(Environment* penv, XML::ElementNode* elemNode, XML::RootNode* proot, Object* pobj)
{
    XML::DOMStringCompareWrapper idstr("id", 2);
    for (XML::Node* child = elemNode->FirstChild; child; child = child->NextSibling)
    {
        if (child->Type != XML::ElementNodeType)
            continue;
        XML::ElementNode* pnode = static_cast<XML::ElementNode*>(child);
        Xml_CreateIDMap(penv, pnode, proot, pobj);
        for (XML::Attribute* attr = pnode->FirstAttribute; attr; attr = attr->Next)
        {
            if (attr->Name == idstr)
            {
                String             v(attr->Value.ToCStr(), attr->Value.GetSize());
                Ptr<XmlNodeObject> pchildobj;
                if (!pnode->pShadow)
                    pchildobj = CreateShadow(penv, pnode, proot);
                else
                {
                    pchildobj = static_cast<XMLShadowRef*>(pnode->pShadow)->pASNode;
                    if (!pchildobj)
                    {
                        pchildobj = *SF_HEAP_NEW(penv->GetHeap()) XmlNodeObject(penv);
                        SetupShadow(penv, pnode, pchildobj);
                    }
                }
                pobj->SetMember(penv, penv->CreateString(v), Value(pchildobj.GetPtr()));
                break;
            }
        }
    }
}

const NameFunction XmlNodeProto::FunctionTable[] = {
    { "appendChild", &XmlNodeProto::AppendChild },
    { "cloneNode", &XmlNodeProto::CloneNode },
    { "getNamespaceForPrefix", &XmlNodeProto::GetNamespaceForPrefix },
    { "getPrefixForNamespace", &XmlNodeProto::GetPrefixForNamespace },
    { "hasChildNodes", &XmlNodeProto::HasChildNodes },
    { "insertBefore", &XmlNodeProto::InsertBefore },
    { "removeNode", &XmlNodeProto::RemoveNode },
    { "toString", &XmlNodeProto::ToString },
    { 0, 0 }
};

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??$ForEachChild_GC@UMarkInCycleFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VXmlNodeObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x14299c5a0
// MS2-PIN: ??$ForEachChild_GC@UReleaseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VXmlNodeObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x14299c660
// MS2-PIN: ??$ForEachChild_GC@UScanInUseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VXmlNodeObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x14299c770
// MS2-PIN: ??_G?$Prototype@VXmlNodeObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14299d0b0
// MS2-PIN: ??_GShadowRefBase@XML@GFx@Scaleform@@UEAAPEAXI@Z 0x14299d110
// MS2-PIN: ??_GXMLAttributeStringBuilder@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14299d160
// MS2-PIN: ??_GXMLPrefixQuerier@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14299d190
// MS2-PIN: ??_GXMLShadowRef@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14299d1c0
// MS2-PIN: ??_GXmlNodeCtorFunction@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14299d240
// MS2-PIN: ??_GXmlNodeObject@AS2@GFx@Scaleform@@MEAAPEAXI@Z 0x14299d2a0
// MS2-PIN: ??_GXmlNodeProto@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14299d340
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7ShadowRefBase@XML@GFx@Scaleform@@6B@ 0x1432238c0
// MS2-PIN: ??_7XMLShadowRef@AS2@GFx@Scaleform@@6B@ 0x1432238c8
// MS2-PIN: ??_7XmlNodeObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432238d0
// MS2-PIN: ??_7XmlNodeObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143223918
// MS2-PIN: ??_7?$Prototype@VXmlNodeObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432239c0
// MS2-PIN: ??_7?$Prototype@VXmlNodeObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143223a08
// MS2-PIN: ??_7?$Prototype@VXmlNodeObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143223ab0
// MS2-PIN: ??_7XmlNodeProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143223ab8
// MS2-PIN: ??_7XmlNodeProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143223b00
// MS2-PIN: ??_7XmlNodeProto@AS2@GFx@Scaleform@@6B@ 0x143223ba8
// MS2-PIN: ??_7XmlNodeCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143223bb0
// MS2-PIN: ??_7XmlNodeCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143223c38
// MS2-PIN: ??_7XMLPrefixQuerier@AS2@GFx@Scaleform@@6B@ 0x143223fe0
// MS2-PIN: ??_7XMLAttributeStringBuilder@AS2@GFx@Scaleform@@6B@ 0x143223ff0
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
