// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 XML (gap recovery of
// sfr_as2_07): the XML class, its prototype methods, the file loaders behind XML.load and the onData / onLoad /
// onHTTPStatus broadcasts.
// MS2-UNIT: sfr_as2_07e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14299f7f0-0x1429a2820 .text$mn

// The exe calls Value::~Value out of line throughout this file.
#define MS2_AS2_VALUE_DTOR_CALL
// XML and IME come before AS2_Value in the exe's AS2_All order, so their callers do not see its noalias.
#define MS2_AS2_SCU
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_loadqueue.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_xml.h"
#include "../include/gfx/as2/as2_xmlnode.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/xml/xml_document.h"
#include "../include/gfx/xml/xml_dom.h"
#include "../include/gfx/xml/xml_object.h"
#include "../include/gfx/xml/xml_support.h"
#include "../include/kernel/sf_file.h"

void FUN_14000b9e0(Scaleform::UPInt* tableRef, void* owner, void** pair, Scaleform::UPInt hash);
namespace Scaleform { namespace GFx { namespace AS2 { class FnCall; class Value; }}}
// FnCall::ThisPtrError_Call (sfr_as2_07). The exe call sites also zero r8/r9: the member takes the SDK's
// (className, psrcfile, line) shape, so the calls pass (cls, 0, 0).
// (C3) void FUN_142990c40(const FnCall*, const char*, const char*, int) = FnCall::ThisPtrError_Call

namespace Scaleform { namespace GFx { namespace AS2 {

bool   CheckThisPtrCopy(const FnCall* pfn, unsigned type); // sfr_as2_04e
Value* ArgCopy(const FnCall* pfn, int n);                // sfr_as2_04e

namespace {

// fn.Arg(n) through the exe's out-of-line FnCall::Arg (sfr_as2_04e).
SF_FORCEINLINE Value& XmlArg(const FnCall& fn, int n)
{
    return *ArgCopy(&fn, n);
}

// The methods only accept an XML object as this; anything else reports the error and returns false.
SF_FORCEINLINE bool CheckXmlThis(const FnCall& fn)
{
    if (!CheckThisPtrCopy(&fn, ObjectInterface::Object_XML))
    {
        fn.ThisPtrError_Call("XML", 0, 0);
        return false;
    }
    return true;
}

SF_FORCEINLINE XmlObject* XmlThis(const FnCall& fn)
{
    return static_cast<XmlObject*>(fn.ThisPtr);
}

// String constants go through the movie's string manager.
SF_FORCEINLINE ASString XmlConstString(ASStringContext* psc, const char* pstr)
{
    return psc->pContext->GetStringManager()->CreateConstString(pstr);
}

// Environment::GetGC() const (SDK header inline): StringContext.pContext.
SF_FORCEINLINE GlobalContext* XmlEnvGC(const Environment* penv)
{
    return penv->StringContext.pContext;
}

SF_FORCEINLINE ASString XmlConstString(Environment* penv, const char* pstr)
{
    return XmlConstString(penv->GetSC(), pstr);
}

SF_FORCEINLINE bool XmlSetConstMemberRaw(ObjectInterface& obj, ASStringContext* psc, const char* pname,
                                         const Value& val, const PropFlags& flags)
{
    return obj.SetMemberRaw(psc, XmlConstString(psc, pname), val, flags);
}

// The movie shares one DOM object manager between its XML objects.
SF_FORCEINLINE Ptr<XML::ObjectManager> GetXmlObjectManager(Environment* penv, MovieImpl* pmovieroot)
{
    Ptr<XML::ObjectManager> memMgr;
    if (!pmovieroot->pXMLObjectManager)
    {
        memMgr = *SF_HEAP_NEW(penv->GetHeap()) XML::ObjectManager(pmovieroot);
        pmovieroot->pXMLObjectManager = static_cast<ExternalLibPtr*>(memMgr.GetPtr());
    }
    else
        memMgr = static_cast<XML::ObjectManager*>(static_cast<ExternalLibPtr*>(pmovieroot->pXMLObjectManager));
    return memMgr;
}

// The XML parser state of the movie (the state bag keeps it alive).
SF_FORCEINLINE XML::SupportBase* GetXmlSupport(MovieImpl* pmovieroot)
{
    return static_cast<XML::SupportBase*>(
        Ptr<State>(*pmovieroot->GetStateBag()->GetStateAddRef(State::State_XMLSupport)).GetPtr());
}

} // namespace

// Reads the file and parses it into the target's tree on the movie thread; used while onData is the default
// handler. 0x30 bytes.
class XMLFileLoaderAndParserImpl : public XMLFileLoader
{
    Ptr<XML::SupportBase> pParser;           // +0x10
    XML::ObjectManager*   pObjectManager;    // +0x18
    void*                 pFileData;         // +0x20
    int                   FileLength;        // +0x28
    bool                  bIgnoreWhitespace; // +0x2c

public:
    XMLFileLoaderAndParserImpl(XML::SupportBase* pparser, XML::ObjectManager* memMgr, bool ignorews)
        : pParser(pparser), pObjectManager(memMgr), pFileData(0), FileLength(0), bIgnoreWhitespace(ignorews)
    {
    }
    virtual ~XMLFileLoaderAndParserImpl();

    virtual void Load(const String& filename, FileOpener* pfo);
    virtual void InitASXml(Environment* penv, Object* ptarget);
};

// Reads the file and hands its text to the target's onData. 0x20 bytes.
class XMLFileLoaderImpl : public XMLFileLoader
{
    void* pFileData;  // +0x10
    int   FileLength; // +0x18

public:
    XMLFileLoaderImpl() : pFileData(0), FileLength(0) {}
    virtual ~XMLFileLoaderImpl();

    virtual void Load(const String& filename, FileOpener* pfo);
    virtual void InitASXml(Environment* penv, Object* ptarget);
};

// @0x14299f7f0
void XmlProto::AddRequestHeader(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    Log* plog = fn.GetLog();
    if (plog)
        plog->LogMessageById(LogChannel_Script | LogMessage_Error, "XML.addRequestHeader is not implemented.");
}

// createElement(name): new XMLNode(1, name).
// @0x14299f870
void XmlProto::CreateElement(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    fn.Env->Push(XmlArg(fn, 0));
    fn.Env->Push(1);
    GlobalContext* pgc       = fn.Env->GetSC()->pContext;
    ASString       className = pgc->GetStringManager()->CreateConstString("XMLNode");
    Ptr<Object>    pnode     = *fn.Env->OperatorNew(className, 2);
    fn.Result->SetAsObject(pnode);
    fn.Env->Drop2();
}

// createTextNode(text): new XMLNode(3, text).
// @0x14299fa20
void XmlProto::CreateTextNode(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    fn.Env->Push(XmlArg(fn, 0));
    fn.Env->Push(3);
    GlobalContext* pgc       = fn.Env->GetSC()->pContext;
    ASString       className = pgc->GetStringManager()->CreateConstString("XMLNode");
    Ptr<Object>    pnode     = *fn.Env->OperatorNew(className, 2);
    fn.Result->SetAsObject(pnode);
    fn.Env->Drop2();
}

// @0x14299fbd0
void XmlProto::GetBytesLoaded(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    if (pthis->BytesLoadedCurrent < 0)
        fn.Result->SetUndefined();
    else
        fn.Result->SetNumber(pthis->BytesLoadedCurrent);
}

// @0x14299fc50
void XmlProto::GetBytesTotal(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    if (pthis->BytesLoadedTotal < 0)
        fn.Result->SetUndefined();
    else
        fn.Result->SetNumber(pthis->BytesLoadedTotal);
}

// load(url): queues the load; with the default onData the file is parsed into this, otherwise onData gets the
// text.
// @0x14299fcd0
void XmlProto::Load(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    if (fn.NArgs == 0)
    {
        fn.Result->SetBool(false);
        return;
    }
    ASString url = ArgCopy(&fn, 0)->ToString(fn.Env);
    Value    ondata;
    pthis->GetMember(fn.Env, XmlEnvGC(fn.Env)->GetStringManager()->CreateConstString("onData"), &ondata);
    FunctionRef handler = ondata.ToFunction_Call(fn.Env);
    if (handler->IsCFunction() && handler->IsCFunction() &&
        static_cast<CFunctionObject*>(handler.GetObjectPtr())->pFunction == XmlProto::DefaultOnData)
    {
        MovieImpl*              pmovieroot = fn.Env->GetMovieImpl();
        Ptr<XML::ObjectManager> memMgr;
        if (!pmovieroot->pXMLObjectManager)
        {
            memMgr = *SF_HEAP_NEW(fn.Env->GetHeap()) XML::ObjectManager(pmovieroot);
            pmovieroot->pXMLObjectManager = static_cast<ExternalLibPtr*>(memMgr.GetPtr());
        }
        else
            memMgr = static_cast<XML::ObjectManager*>(static_cast<ExternalLibPtr*>(pmovieroot->pXMLObjectManager));
        XML::SupportBase* psupport = GetXmlSupport(pmovieroot);
        pthis->BytesLoadedCurrent = 0;
        Value ignoreWhite;
        pthis->GetMember(fn.Env, XmlEnvGC(fn.Env)->GetStringManager()->CreateConstString("ignoreWhite"), &ignoreWhite);
        bool                  ignorews = ignoreWhite.ToBool(fn.Env);
        Ptr<XMLFileLoader>    ploader  = *SF_HEAP_NEW(Memory::pGlobalHeap)
            XMLFileLoaderAndParserImpl(psupport, memMgr, ignorews);
        fn.Env->GetAS2Root()->AddXmlLoadQueueEntry(pthis, ploader, url.ToCStr());
        fn.Result->SetBool(true);
    }
    else
    {
        Ptr<XMLFileLoader> ploader = *SF_HEAP_NEW(Memory::pGlobalHeap) XMLFileLoaderImpl();
        fn.Env->GetAS2Root()->AddXmlLoadQueueEntry(pthis, ploader, url.ToCStr());
        fn.Result->SetBool(true);
    }
    pthis->SetMemberRaw(fn.Env->GetSC(), XmlConstString(fn.Env, "loaded"), Value(false),
                        PropFlags(PropFlags::PropFlag_DontDelete));
}

// parseXML(text): replaces the tree of this with the parsed text and rebuilds idMap.
// @0x1429a01c0
void XmlProto::ParseXML(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    XML_LoadString(fn, pthis);
    Environment* penv  = fn.Env;
    Ptr<Object>  idMap = *SF_HEAP_NEW(penv->GetHeap()) Object(penv);
    for (XML::Node* child = static_cast<XML::ElementNode*>(pthis->pRealNode)->FirstChild; child;
         child = child->NextSibling)
    {
        if (child->Type == XML::ElementNodeType)
            Xml_CreateIDMap(penv, static_cast<XML::ElementNode*>(child), pthis->pRootNode, idMap);
    }
    pthis->SetMember(penv, XmlConstString(penv, "idMap"), Value(idMap), PropFlags(PropFlags::PropFlag_DontDelete));
}

// @0x1429a0380
void XmlProto::Send(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    Log* plog = fn.GetLog();
    if (plog)
        plog->LogMessageById(LogChannel_Script | LogMessage_Error, "XML.send is not implemented.");
}

// @0x1429a0400
void XmlProto::SendAndLoad(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
    XmlObject* pthis = XmlThis(fn);
    if (!pthis)
        return;
    Log* plog = fn.GetLog();
    if (plog)
        plog->LogMessageById(LogChannel_Script | LogMessage_Error, "XML.sendAndLoad is not implemented.");
}

// @0x1429a0480
template void Prototype<XmlObject>::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector* prcc) const;
// @0x1429a0540
template void Prototype<XmlObject>::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector* prcc) const;
// @0x1429a0650
template void Prototype<XmlObject>::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector* prcc) const;

// @0x1429a0800
XmlCtorFunction::XmlCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor)
{
}

// @0x1429a0840
XmlObject::XmlObject(Environment* penv) : XmlNodeObject(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_XML));
    BytesLoadedTotal = BytesLoadedCurrent = -1;
    AsBroadcaster::Initialize(penv->GetSC(), this);
    AsBroadcaster::AddListener(penv, this, this);
}

// The prototype holds the methods, the writable defaults of the XML properties and the default onData handler.
// @0x1429a08f0
XmlProto::XmlProto(ASStringContext* psc, Object* prototype, const FunctionRef& constructor)
    : Prototype<XmlObject>(psc, prototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete));
    Object::SetMemberRaw(psc, XmlConstString(psc, "contentType"),
                         Value(XmlConstString(psc, "application/x-www-form-urlencoded")),
                         PropFlags(PropFlags::PropFlag_DontDelete));
    Object::SetMemberRaw(psc, XmlConstString(psc, "docTypeDecl"), Value(), PropFlags(PropFlags::PropFlag_DontDelete));
    Object::SetMemberRaw(psc, XmlConstString(psc, "idMap"), Value(), PropFlags(PropFlags::PropFlag_DontDelete));
    Object::SetMemberRaw(psc, XmlConstString(psc, "ignoreWhite"), Value(false), PropFlags(PropFlags::PropFlag_DontDelete));
    Object::SetMemberRaw(psc, XmlConstString(psc, "loaded"), Value(), PropFlags(PropFlags::PropFlag_DontDelete));
    Object::SetMemberRaw(psc, XmlConstString(psc, "status"), Value(0), PropFlags(PropFlags::PropFlag_DontDelete));
    Object::SetMemberRaw(psc, XmlConstString(psc, "xmlDecl"), Value(), PropFlags(PropFlags::PropFlag_DontDelete));
    // The SDK's ObjectInterface::SetConstMemberRaw (header inline, through the interface): the Value is built
    // before the name.
    XmlSetConstMemberRaw(*this, psc, "onData", Value(psc, XmlProto::DefaultOnData),
                         PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x1429a0f00
XMLFileLoaderAndParserImpl::~XMLFileLoaderAndParserImpl()
{
    if (pFileData)
        Memory::pGlobalHeap->Free(pFileData);
}

// @0x1429a0f50
XMLFileLoaderImpl::~XMLFileLoaderImpl()
{
    if (pFileData)
        Memory::pGlobalHeap->Free(pFileData);
}

// Builds the <?xml ...?> declaration of pdoc into xmlDecl; nothing is set when the document declares none.
// @0x1429a14a0
void XmlObject::AssignXMLDecl(Environment* penv, XML::Document* pdoc)
{
    StringBuffer decl("", Memory::pGlobalHeap);
    if (pdoc)
    {
        decl.AppendString("<?");
        if (pdoc->XMLVersion.GetSize() > 0)
        {
            decl.AppendString("xml version=\"");
            decl.AppendString(pdoc->XMLVersion.ToCStr());
            decl.AppendString("\"");
        }
        if (pdoc->Encoding.GetSize() > 0)
        {
            if (pdoc->XMLVersion.GetSize() > 0)
                decl.AppendString(" ");
            decl.AppendString("encoding=\"");
            decl.AppendString(pdoc->Encoding.ToCStr());
            decl.AppendString("\"");
        }
        if (pdoc->Standalone != -1)
        {
            if (pdoc->XMLVersion.GetSize() > 0 || pdoc->Encoding.GetSize() > 0)
                decl.AppendString(" ");
            if (pdoc->Standalone)
                decl.AppendString("standalone=\"yes\"");
            else
                decl.AppendString("standalone=\"no\"");
        }
        decl.AppendString("?>");
    }
    if (pdoc->XMLVersion.GetSize() > 0 || pdoc->Encoding.GetSize() > 0 || pdoc->Standalone != -1)
    {
        ASString declstr = penv->GetSC()->pContext->GetStringManager()->CreateString(decl.ToCStr(), decl.GetSize());
        Value     v(declstr);
        PropFlags flags;
        SetMember(penv, XmlConstString(penv, "xmlDecl"), v, flags);
    }
}

// @0x1429a1740
Object* XmlCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) XmlObject(penv);
}

// The placeholder onData: XML.load bypasses it and parses the file itself.
// @0x1429a1780
void XmlProto::DefaultOnData(const FnCall& fn)
{
    if (!CheckXmlThis(fn))
        return;
}

// @0x1429a1810
template void Prototype<XmlObject>::Finalize_GC();

// "constructor" and "__constructor__" are answered by the prototype part.
// @0x1429a18a0
template<>
bool Prototype<XmlObject>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    bool isConstructor2 = psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin___constructor__)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive());
    if (isConstructor2 || psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin_constructor)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        return GetMemberRawConstructor(this, psc, name, val, isConstructor2);
    }
    return XmlObject::GetMemberRaw(psc, name, val);
}

// new XML([text]): parses text (when given) into this.
// @0x1429a19d0
void XmlCtorFunction::GlobalCtor(const FnCall& fn)
{
    Ptr<XmlObject> pnode;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object_XML)
        pnode = static_cast<XmlObject*>(fn.ThisPtr);
    else
        pnode = *SF_HEAP_NEW(fn.Env->GetHeap()) XmlObject(fn.Env);
    XML_LoadString(fn, pnode);
}

// The parsed file becomes the tree of ptarget; onLoad reports whether it parsed.
// @0x1429a1a80
void XMLFileLoaderAndParserImpl::InitASXml(Environment* penv, Object* ptarget)
{
    XmlObject* pnode = static_cast<XmlObject*>(ptarget);
    if (!pFileData)
    {
        pnode->SetLoadedBytes(-1, 0);
        pnode->NotifyOnLoad(penv, false);
    }
    else
    {
        XML::DOMBuilder    builder(pParser, bIgnoreWhitespace);
        Ptr<XML::Document> pdoc = builder.ParseString((const char*)pFileData, FileLength, pObjectManager);
        Memory::pGlobalHeap->Free(pFileData);
        pFileData = 0;
        pnode->pRealNode = pdoc;
        pnode->pRootNode = *pObjectManager->CreateRootNode(pdoc);
        XMLShadowRef* pshadow = SF_HEAP_NEW(pObjectManager->GetHeap()) XMLShadowRef();
        pshadow->pAttributes  = NULL;
        pshadow->pASNode      = pnode;
        pdoc->pShadow         = pshadow;
        pnode->AssignXMLDecl(penv, pdoc);
        if (builder.IsError() && builder.GetTotalBytesToLoad() == 0)
        {
            pnode->SetLoadedBytes(-1, (Number)builder.GetLoadedBytes());
            pnode->NotifyOnLoad(penv, false);
        }
        else
        {
            pnode->SetMemberRaw(penv->GetSC(), XmlConstString(penv, "loaded"), Value(true),
                                PropFlags(PropFlags::PropFlag_DontDelete));
            pnode->SetLoadedBytes((Number)builder.GetTotalBytesToLoad(), (Number)builder.GetLoadedBytes());
            pnode->NotifyOnLoad(penv, true);
        }
    }
}

// onData gets the file text, or undefined when the file could not be read.
// @0x1429a1d10
void XMLFileLoaderImpl::InitASXml(Environment* penv, Object* ptarget)
{
    XmlObject* pnode = static_cast<XmlObject*>(ptarget);
    if (pFileData)
    {
        pnode->NotifyOnData(penv, Value(penv->GetSC()->pContext->GetStringManager()->CreateString(
                                      (const char*)pFileData, FileLength)));
        Memory::pGlobalHeap->Free(pFileData);
        pFileData = 0;
    }
    else
        pnode->NotifyOnData(penv, Value());
}

// Reads the whole file (nothing when it cannot be opened or is empty).
// @0x1429a1df0
void XMLFileLoaderAndParserImpl::Load(const String& filename, FileOpener* pfo)
{
    Ptr<File> pfile = *pfo->OpenFile(filename.ToCStr(), 0x21, 0x1b6);
    if (pfile && pfile->IsValid() && (FileLength = pfile->GetLength()) != 0)
    {
        pFileData = Memory::pGlobalHeap->Alloc(FileLength, (const AllocInfo*)0);
        pfile->Read((UByte*)pFileData, FileLength);
    }
}

// @0x1429a1e90
void XMLFileLoaderImpl::Load(const String& filename, FileOpener* pfo)
{
    Ptr<File> pfile = *pfo->OpenFile(filename.ToCStr(), 0x21, 0x1b6);
    if (pfile && pfile->IsValid() && (FileLength = pfile->GetLength()) != 0)
    {
        pFileData = Memory::pGlobalHeap->Alloc(FileLength, (const AllocInfo*)0);
        pfile->Read((UByte*)pFileData, FileLength);
    }
}

// @0x1429a1f30
void XmlObject::NotifyOnData(Environment* penv, Value val)
{
    penv->Push(val);
    AsBroadcaster::BroadcastMessage(penv, this, XmlConstString(penv, "onData"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// @0x1429a2030
void XmlObject::NotifyOnHTTPStatus(Environment* penv, Number httpStatus)
{
    penv->Push(httpStatus);
    AsBroadcaster::BroadcastMessage(penv, this, XmlConstString(penv, "onHTTPStatus"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// MS2-FUNCTIONAL: instruction scheduling
// @0x1429a2130
void XmlObject::NotifyOnLoad(Environment* penv, bool success)
{
    SetMemberRaw(penv->GetSC(), XmlConstString(penv, "loaded"), Value(success),
                 PropFlags(PropFlags::PropFlag_DontDelete));
    penv->Push(success);
    AsBroadcaster::BroadcastMessage(penv, this, XmlConstString(penv, "onLoad"), 1, penv->GetTopIndex());
    penv->Drop1();
}

Value* FUN_142923b90(Value* pthis, const FunctionRef& func); // sfr_as2_03, Value(const FunctionRef&) out of line
// Raw room for a Value the exe builds through FUN_142923b90.
struct XmlValueStorage
{
    XmlValueStorage() {}
    UInt64 Raw0, Raw1, Raw2, Raw3;
};
// @0x1429a22b0
FunctionRef XmlCtorFunction::Register(GlobalContext* pgc)
{
    if (!pgc->GetBuiltinClassRegistrar(pgc->GetStringManager()->GetBuiltin(ASBuiltin_XMLNode)))
        XmlNodeCtorFunction::Register(pgc);
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) XmlCtorFunction(&sc));
    Ptr<XmlProto>   proto = *SF_HEAP_NEW(pgc->pHeap) XmlProto(&sc, pgc->GetPrototype(ASBuiltin_XMLNode), ctor);
    {
        Ptr<Object>   pproto  = proto.GetPtr();
        ASBuiltinType key     = ASBuiltin_XML;
        void*         pair[2] = { &key, &pproto };
        UPInt*        ptable  = reinterpret_cast<UPInt*>(&pgc->Prototypes);
        ::FUN_14000b9e0(ptable, ptable, pair, FixedSizeHash<ASBuiltinType>()(key));
    }
    {
        XmlValueStorage storage;
        Value& fval = *reinterpret_cast<Value*>(&storage);
        pgc->pGlobal->SetMemberRaw(&sc, pgc->GetStringManager()->GetBuiltin(ASBuiltin_XML),
                                   *FUN_142923b90(&fval, ctor));
        fval.~Value();
    }
    return ctor;
}

// Parses the first argument (when there is one) into pnode's tree, otherwise gives it an empty document; the
// document gets its shadow and an attributes object.
// @0x1429a2510
void XML_LoadString(const FnCall& fn, XmlObject* pnode)
{
    Log*                    plog       = fn.GetLog();
    MovieImpl*              pmovieroot = fn.Env->GetMovieImpl();
    Ptr<XML::ObjectManager> memMgr     = GetXmlObjectManager(fn.Env, pmovieroot);
    Ptr<XML::Document>      pdoc;
    Value                   str;
    if (fn.NArgs > 0)
    {
        str                        = XmlArg(fn, 0);
        XML::SupportBase* pxml = GetXmlSupport(fn.Env->GetMovieImpl());
        if (pxml)
        {
            XML::DOMBuilder builder(pxml, true);
            ASString        text = str.ToString(fn.Env);
            pdoc = builder.ParseString(text.ToCStr(), text.GetSize(), memMgr);
            pnode->AssignXMLDecl(fn.Env, pdoc);
        }
        else if (plog)
            plog->LogMessageById(LogChannel_Script | LogMessage_Error, "No XML parser state set for movie!");
    }
    if (!pdoc)
        pdoc = *memMgr->CreateDocument();
    pdoc->Value      = memMgr->CreateString("null", 4);
    pnode->pRealNode = pdoc;
    pnode->pRootNode = *memMgr->CreateRootNode(pdoc);
    XMLShadowRef* pshadow = SF_HEAP_NEW(memMgr->GetHeap()) XMLShadowRef();
    pdoc->pShadow         = pshadow;
    pshadow->pAttributes  = *SF_HEAP_NEW(fn.Env->GetHeap()) XmlNodeObject(fn.Env);
    pshadow->pASNode      = pnode;
}

const NameFunction XmlProto::FunctionTable[] = {
    { "addRequestHeader", &XmlProto::AddRequestHeader },
    { "createElement", &XmlProto::CreateElement },
    { "createTextNode", &XmlProto::CreateTextNode },
    { "getBytesLoaded", &XmlProto::GetBytesLoaded },
    { "getBytesTotal", &XmlProto::GetBytesTotal },
    { "load", &XmlProto::Load },
    { "parseXML", &XmlProto::ParseXML },
    { "send", &XmlProto::Send },
    { "sendAndLoad", &XmlProto::SendAndLoad },
    { 0, 0 }
};

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??0XMLFileLoaderAndParserImpl@AS2@GFx@Scaleform@@QEAA@PEAVSupportBase@XML@23@PEAVObjectManager@523@_N@Z 0x1429a0750
// MS2-PIN: ??1?$Array@UPrefixOwnership@DOMBuilder@XML@GFx@Scaleform@@$01UArrayDefaultPolicy@5@@Scaleform@@QEAA@XZ 0x1429a0d90
// MS2-PIN: ??1DOMBuilder@XML@GFx@Scaleform@@UEAA@XZ 0x1429a0e10
// MS2-PIN: ??_G?$Prototype@VXmlObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1429a0fe0
// MS2-PIN: ??_G?$RefCountBase@VXMLFileLoader@AS2@GFx@Scaleform@@$0BED@@Scaleform@@UEAAPEAXI@Z 0x1429a1070
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@UEAAPEAXI@Z 0x1429a10d0
// MS2-PIN: ??_GParserHandler@XML@GFx@Scaleform@@UEAAPEAXI@Z 0x1429a1130
// MS2-PIN: ??_GXMLFileLoader@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1429a11a0
// MS2-PIN: ??_GXMLFileLoaderAndParserImpl@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1429a1210
// MS2-PIN: ??_GXMLFileLoaderImpl@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1429a12b0
// MS2-PIN: ??_GXmlCtorFunction@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1429a1340
// MS2-PIN: ??_GXmlObject@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1429a13a0
// MS2-PIN: ??_GXmlProto@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1429a1400
// MS2-PIN: ??_7XMLFileLoader@AS2@GFx@Scaleform@@6B@ 0x143224130
// MS2-PIN: ??_7XmlObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432241b8
// MS2-PIN: ??_7XmlObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143224200
// MS2-PIN: ??_7?$Prototype@VXmlObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432242a8
// MS2-PIN: ??_7?$Prototype@VXmlObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432242f0
// MS2-PIN: ??_7?$Prototype@VXmlObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143224398
// MS2-PIN: ??_7XmlProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432243a0
// MS2-PIN: ??_7XmlProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432243e8
// MS2-PIN: ??_7XmlProto@AS2@GFx@Scaleform@@6B@ 0x143224490
// MS2-PIN: ??_7XmlCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143224498
// MS2-PIN: ??_7XmlCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143224520
// MS2-PIN: ??_7XMLFileLoaderAndParserImpl@AS2@GFx@Scaleform@@6B@ 0x1432245c8
// MS2-PIN: ??_7XMLFileLoaderImpl@AS2@GFx@Scaleform@@6B@ 0x1432245e0
// MS2-PIN: ??_7?$RefCountBase@VXMLFileLoader@AS2@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x143224128
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7ShadowRefBase@XML@GFx@Scaleform@@6B@ 0x1432238c0
// MS2-PIN: ??_7XMLShadowRef@AS2@GFx@Scaleform@@6B@ 0x1432238c8
// MS2-PIN: ??_7XmlNodeObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432238d0
// MS2-PIN: ??_7XmlNodeObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143223918
// MS2-PIN: ??_7ParserHandler@XML@GFx@Scaleform@@6B@ 0x143224148
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
