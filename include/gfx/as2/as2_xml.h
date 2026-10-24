// Recovered Scaleform 4.1.18 GFx AS2: the XML class, an XMLNode that is the document of its tree, with the
// load/parse methods and the onData/onLoad broadcasts.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_XML_H
#define MS2_SF_GFX_AS2_XML_H

#include "as2_xmlnode.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// An XML instance. 0x88 bytes; vftables 0x1432241b8 (Object), 0x143224200 (ObjectInterface).
class XmlObject : public XmlNodeObject
{
    friend class XmlProto;
    friend class XmlCtorFunction;

public:
    Number BytesLoadedCurrent; // +0x78, -1 while unknown
    Number BytesLoadedTotal;   // +0x80, -1 while unknown

protected:
    // Only the prototype object is built this way.
    XmlObject(ASStringContext* psc, Object* pprototype) : XmlNodeObject(psc, pprototype) {}

public:
    XmlObject(Environment* penv); // exe 0x1429a0840

    virtual ObjectType GetObjectType() const { return Object_XML; }

    void NotifyOnData(Environment* penv, Value val);                 // exe 0x1429a1f30
    void NotifyOnHTTPStatus(Environment* penv, Number httpStatus);   // exe 0x1429a2030
    void NotifyOnLoad(Environment* penv, bool success);              // exe 0x1429a2130
    void SetLoadedBytes(Number total, Number loaded)
    {
        BytesLoadedCurrent = loaded;
        BytesLoadedTotal   = total;
    }
    // Sets xmlDecl from the declaration of pdoc, when it has one.
    void AssignXMLDecl(Environment* penv, XML::Document* pdoc);      // exe 0x1429a14a0
};

// Parses the first argument of fn (when there is one) into pnode's tree; an empty document otherwise
// (exe 0x1429a2510).
void XML_LoadString(const FnCall& fn, XmlObject* pnode);

// XML.prototype. 0xb8 bytes; vftables 0x1432243a0, 0x1432243e8 (ObjectInterface), 0x143224490
// (GASPrototypeBase).
class XmlProto : public Prototype<XmlObject>
{
public:
    XmlProto(ASStringContext* psc, Object* prototype, const FunctionRef& constructor); // exe 0x1429a08f0

    static const NameFunction FunctionTable[];

    static void AddRequestHeader(const FnCall& fn); // exe 0x14299f7f0
    static void CreateElement(const FnCall& fn);    // exe 0x14299f870
    static void CreateTextNode(const FnCall& fn);   // exe 0x14299fa20
    static void GetBytesLoaded(const FnCall& fn);   // exe 0x14299fbd0
    static void GetBytesTotal(const FnCall& fn);    // exe 0x14299fc50
    static void Load(const FnCall& fn);             // exe 0x14299fcd0
    static void ParseXML(const FnCall& fn);         // exe 0x1429a01c0
    static void Send(const FnCall& fn);             // exe 0x1429a0380
    static void SendAndLoad(const FnCall& fn);      // exe 0x1429a0400
    static void DefaultOnData(const FnCall& fn);    // exe 0x1429a1780
};

// The XML class object. 0x70 bytes; vftables 0x143224498, 0x143224520 (ObjectInterface).
class XmlCtorFunction : public CFunctionObject
{
public:
    XmlCtorFunction(ASStringContext* psc); // exe 0x1429a0800

    static void        GlobalCtor(const FnCall& fn);             // exe 0x1429a19d0
    virtual Object*    CreateNewObject(Environment* penv) const; // exe 0x1429a1740
    static FunctionRef Register(GlobalContext* pgc);             // exe 0x1429a22b0
};

}}} // namespace Scaleform::GFx::AS2

#endif
