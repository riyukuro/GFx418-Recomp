// Recovered Scaleform GFx 4.1.18 AS3 E4X: the node classes behind XML (element, attribute, text, comment,
// processing instruction), the in-scope namespace list and the expat-driven parser. Our own declarations from
// the exe's field accesses and vftables 0x1431429d0-0x1431436c0; the base Instances::fl::XML is in as3_obj_fl.h,
// XMLList and QName in as3_obj_core.h. Ctors in sfr_as3_01c, the node methods in sfr_as3_02..04.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_OBJ_E4X_H
#define MS2_SF_GFX_AS3_OBJ_E4X_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fl.h"

struct XML_ParserStruct;    // expat's parser (third_party/src/expat-2.0.1, the exe's libgfxexpat)

namespace Scaleform { namespace GFx { namespace AS3 {

// The namespaces declared on an element (its in-scope list). 0x18 bytes.
class NamespaceArray
{
public:
    ArrayLH<SPtr<Instances::Namespace> >    Namespaces;     // +0x00

    // (appended, sfr19) pushes ns; with checkUnique, not if an equal namespace (uri + kind) is already in. 0x142403b60
    void Add(Instances::Namespace& ns, bool checkUnique = true);
    // (appended, sfr19) Add(ns, true) for every namespace of other. 0x142404230
    void AddUnique(const NamespaceArray& other);
    // (appended, sfr19) an equal namespace (uri + prefix) is in. 0x14240ada0
    bool Find(const Instances::Namespace& ns) const;
    // (appended, sfr19) a namespace with prefix is in. 0x14240aed0
    bool FindByPrefix(const ASString& prefix) const;
    // (appended, sfr19) a namespace with uri is in. 0x14240af70
    bool FindByUri(const ASString& uri) const;
};

namespace Instances { namespace fl {

    // An attribute: Text is the local name. 0x58 bytes; vftable 0x143142dc8.
    class XMLAttr : public XML
    {
    public:
        // 0x1423efd40
        XMLAttr(InstanceTraits::Traits& t, const Instances::Namespace& ns, const ASString& name,
                const ASString& value, XML* parent = NULL);
        // ??_G 0x1423f4c80
        virtual ~XMLAttr() {}

        // @0x14240c280
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142425a40
        virtual void ToString(StringBuffer& buf, SInt32 ident);
        // @0x142425d20
        virtual void ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                 const NamespaceArray* usedNotDeclared);
        // @0x142415d90
        virtual Kind GetKind() const { return kAttr; }
        // @0x142409ae0
        virtual Boolean3 EqualsInternal(const XML& other);
        // @0x1424176a0
        virtual bool HasSimpleContent() const { return true; }
        // @0x142415fe0
        virtual const Instances::Namespace& GetNamespace() const { return *Ns; }
        // @0x142421c40
        virtual void SetNamespace(Instances::Namespace& ns);
        // @0x142421b50
        virtual void SetNamespace2(Instances::Namespace& ns);
        // @0x142415710
        virtual Instances::Namespace& GetCurrNamespace() const { return *Ns; }
        // @0x142408860
        virtual Pickable<XML> DeepCopy(XML* parent);
        // @0x142416c50
        virtual SPtr<Instances::fl::QName> GetQName();
        // @0x142420270
        virtual void ResolveNamespaces(HashSetDH<ASString>& nr, XML* lp) const;

    public:
        SPtr<Instances::Namespace>  Ns;     // +0x48
        ASString                    Data;   // +0x50 the value
    };

    // An element: Text is the local name. 0x98 bytes; vftable 0x143142fa0.
    class XMLElement : public XML
    {
    public:
        // 0x1423efe80
        XMLElement(InstanceTraits::Traits& t, const Instances::Namespace& ns, const ASString& name,
                   XML* parent = NULL);
        // ??_G 0x1423f4e20
        virtual ~XMLElement() {}

        // @0x14240c340
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x1424220e0
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);
        // @0x142416910
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);
        // @0x142409120
        virtual CheckResult DeleteProperty(const Multiname& prop_name);
        // @0x14240b080
        virtual PropRef FindDynamicSlot(const Multiname& mn);

        // @0x142415c10
        virtual const NamespaceArray* GetInScopeNamespaces() const { return &Namespaces; }
        // @0x142403ff0
        virtual void AddInScopeNamespace(const Instances::Namespace& ns);
        // @0x142404db0
        virtual void AppendChild(const SPtr<XML>& child);
        // @0x142404d80
        virtual CheckResult AppendChild(const Value& child);
        // @0x142425a80
        virtual void ToString(StringBuffer& buf, SInt32 ident);
        // @0x142425f30
        virtual void ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                 const NamespaceArray* usedNotDeclared);
        // @0x142415db0
        virtual Kind GetKind() const { return kElement; }
        // @0x142409b40
        virtual Boolean3 EqualsInternal(const XML& other);
        // no element children. 0x1424176b0
        virtual bool HasSimpleContent() const;
        // @0x142417330
        virtual bool HasOwnProperty(const ASString& p);
        // @0x142415ff0
        virtual const Instances::Namespace& GetNamespace() const { return *Ns; }
        // @0x142421cb0
        virtual void SetNamespace(Instances::Namespace& ns);
        // @0x142421bc0
        virtual void SetNamespace2(Instances::Namespace& ns);
        // @0x142415720
        virtual Instances::Namespace& GetCurrNamespace() const { return *Ns; }
        // @0x142408960
        virtual Pickable<XML> DeepCopy(XML* parent);
        // (appended, sfr19) the first attribute matching mn (a string name), its index in ind. 0x14240ae20
        bool FindAttr(const Multiname& mn, UPInt& ind) const;
        // (appended, sfr19) the first element child matching mn (a string name), its index in ind. 0x14240afb0
        bool FindChild(const Multiname& mn, UPInt& ind) const;
        // @0x1424153c0
        virtual void GetChildren(Instances::fl::XMLList& list, Kind k, const ASString* name = NULL);
        // @0x142415320
        virtual void GetChildren(Instances::fl::XMLList& list, const Multiname& prop_name);
        // @0x1424152b0
        virtual CheckResult GetChildIndex(UPInt& ind) const;
        // @0x1424157d0
        virtual void GetDescendants(Instances::fl::XMLList& list, const Multiname& prop_name);
        // @0x142419270
        virtual CheckResult InsertChildAt(UPInt pos, const Value& child);
        // @0x1424191a0
        virtual CheckResult InsertChildAfter(const Value& child1, const Value& child2);
        // @0x1424197f0
        virtual CheckResult InsertChildBefore(const Value& child1, const Value& child2);
        // @0x142408f50
        virtual void DeleteChildren(XML* child);
        // @0x142408ed0
        virtual void DeleteByIndex(UPInt ind);
        // @0x1424151e0
        virtual void GetAttributes(Instances::fl::XMLList& list);
        // @0x142416d00
        virtual SPtr<Instances::fl::QName> GetQName();
        // @0x14241d580
        virtual void Normalize();
        // @0x14240b260
        virtual Instances::Namespace* FindNamespaceByPrefix(const ASString& prefix, XML* lp) const;
        // @0x14240b3e0
        virtual Instances::Namespace* FindNamespaceByURI(const ASString& uri, XML* lp) const;
        // @0x1424203b0
        virtual void ResolveNamespaces(HashSetDH<ASString>& nr, XML* lp) const;
        // @0x14241efd0
        virtual XML* RemoveNamespace(const Value& ns);
        // @0x14241f4b0
        virtual CheckResult Replace(const Multiname& prop_name, const Value& value);
        // @0x1423f6870
        virtual CheckResult AS3Replace(const Multiname& prop_name, const Value& value);
        // @0x142421780
        virtual void SetChildren(const Value& value);
        // @0x1424169f0
        virtual CheckResult GetProperty(const Multiname& prop_name, Instances::fl::XMLList& list);

        // v itself if it is an XML, the single item if it is a one-item XMLList, else NULL. 0x142425c90
        XML* ToXML(const Value& v) const;

        // (appended, sfr19) a visitor of the attributes or children ForEachAttr/ForEachChild select.
        // vftable 0x143142f90 (slot 1 pure).
        class CallBack
        {
        public:
            CallBack(XMLElement& el) : Element(el) {}
            // ??_G 0x1423f2540
            virtual ~CallBack() {}
            // ind indexes Attrs or Children; false stops the walk.
            virtual bool Call(UPInt ind) = 0;

        protected:
            XMLElement&     Element;        // +0x08

        private:
            CallBack& operator=(const CallBack&);
        };

        // (appended, sfr19) cb for each attribute prop_name matches (none unless the name is a string); the
        // number visited. 0x14240b630
        UInt32 ForEachAttr(const Multiname& prop_name, CallBack& cb);
        // (appended, sfr19) the same over the children. 0x14240b6d0
        UInt32 ForEachChild(const Multiname& prop_name, CallBack& cb);
        // (appended, sfr19) prop_name names a child (an attribute for an attribute name); a list index only
        // "0". check_prototype is unused. Not virtual in this build. 0x1424174c0
        bool HasProperty(const Multiname& prop_name, bool check_prototype);
        // (appended, sfr19) replace child ind (appended when past the end) with value: an XML node, a list's
        // items, or a text node of value's string. 0x14241f1a0
        CheckResult Replace(UPInt ind, const Value& value);

    public:
        SPtr<Instances::Namespace>      Ns;             // +0x48
        NamespaceArray                  Namespaces;     // +0x50 declared on this element
        ArrayLH<SPtr<XMLAttr> >         Attrs;          // +0x68
        ArrayLH<SPtr<XML> >             Children;       // +0x80

    public:
        // (appended, sfr19) a new attribute name=value in ns, parented to this. 0x142403c10
        void AddAttr(const Instances::Namespace& ns, const ASString& name, const ASString& value);
    };

    // A text node: Text is the content. 0x48 bytes; vftable 0x143143168.
    class XMLText : public XML
    {
    public:
        // 0x1423f02e0
        XMLText(InstanceTraits::Traits& t, const ASString& text, XML* parent = NULL);
        // ??_G 0x1423f5200
        virtual ~XMLText() {}

        // @0x1424270d0
        virtual void ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                 const NamespaceArray* usedNotDeclared);
        // @0x142415dd0
        virtual Kind GetKind() const { return kText; }
        // @0x142417720
        virtual bool HasSimpleContent() const { return true; }
        // @0x142408e00
        virtual Pickable<XML> DeepCopy(XML* parent);
    };

    // A processing instruction: Text is the target. 0x50 bytes; vftable 0x143143330.
    class XMLProcInstr : public XML
    {
    public:
        // 0x1423f0260
        XMLProcInstr(InstanceTraits::Traits& t, const ASString& name, const ASString& data, XML* parent = NULL);
        // ??_G 0x1423f5150 (implicit dtor)

        // @0x142427020
        virtual void ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                 const NamespaceArray* usedNotDeclared);
        // @0x142415dc0
        virtual Kind GetKind() const { return kInstruction; }
        // @0x142409d40
        virtual Boolean3 EqualsInternal(const XML& other);
        // @0x142408d40
        virtual Pickable<XML> DeepCopy(XML* parent);
        // @0x142416db0
        virtual SPtr<Instances::fl::QName> GetQName();

    public:
        ASString    Data;   // +0x48
    };

    // A comment: Text is the content. 0x48 bytes; vftable 0x1431434f8.
    class XMLComment : public XML
    {
    public:
        // 0x1423efe10
        XMLComment(InstanceTraits::Traits& t, const ASString& text, XML* parent = NULL);
        // ??_G 0x1423f4d70
        virtual ~XMLComment() {}

        // @0x142425a60
        virtual void ToString(StringBuffer& buf, SInt32 ident);
        // @0x142425ea0
        virtual void ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                 const NamespaceArray* usedNotDeclared);
        // @0x142415da0
        virtual Kind GetKind() const { return kComment; }
        // @0x142409b20
        virtual Boolean3 EqualsInternal(const XML& other);
        // @0x1424088b0
        virtual Pickable<XML> DeepCopy(XML* parent);
    };

    // (appended, sfr19) the XMLElement::CallBack visitors (vftables 0x1431439b8-0x1431439f8; the ??_G bodies
    // sit with the ctors in sfr_as3_01c, the Call bodies in sfr_as3_03).

    // Counts only. vftable 0x1431439b8, ??_G 0x1423f2c50
    class EmptyCallBack : public XMLElement::CallBack
    {
    public:
        EmptyCallBack(XMLElement& el) : XMLElement::CallBack(el) {}
        // 0x142405770 (one body with ThunkDefault<bool>::Get)
        virtual bool Call(UPInt ind) { SF_UNUSED(ind); return true; }
    };

    // The first matching attribute. vftable 0x1431439c8, ??_G 0x1423f2380
    class AttrGetFirst : public XMLElement::CallBack
    {
    public:
        AttrGetFirst(XMLElement& el) : XMLElement::CallBack(el) {}
        // @0x142405590
        virtual bool Call(UPInt ind);

    public:
        SPtr<XML>   Result;     // +0x10
    };

    // The first matching child. vftable 0x1431439d8, ??_G 0x1423f27e0
    class ChildGetFirst : public XMLElement::CallBack
    {
    public:
        ChildGetFirst(XMLElement& el) : XMLElement::CallBack(el) {}
        // @0x142405640
        virtual bool Call(UPInt ind);

    public:
        SPtr<XML>   Result;     // +0x10
    };

    // Appends the matching children to List. vftable 0x1431439e8, ??_G 0x1423f27b0
    class ChildGet : public XMLElement::CallBack
    {
    public:
        ChildGet(XMLElement& el, XMLList& list) : XMLElement::CallBack(el), List(list) {}
        // @0x1424055e0
        virtual bool Call(UPInt ind);

    private:
        XMLList&    List;       // +0x10
        ChildGet& operator=(const ChildGet&);
    };

    // Appends the matching attributes to List. vftable 0x1431439f8, ??_G 0x1423f2350
    class AttrGet : public XMLElement::CallBack
    {
    public:
        AttrGet(XMLElement& el, XMLList& list) : XMLElement::CallBack(el), List(list) {}
        // @0x142405500
        virtual bool Call(UPInt ind);

    private:
        XMLList&    List;       // +0x10
        AttrGet& operator=(const AttrGet&);
    };

    // Appends the matching children to Result. vftable 0x143143ae0, ??_G 0x1423f35d0
    class ListGet : public XMLList::CallBack
    {
    public:
        ListGet(XMLList& list, XMLList& result) : XMLList::CallBack(list), Result(result) {}
        // @0x142405920
        virtual void Call(UPInt ind1, UPInt ind2);

    private:
        XMLList&    Result;     // +0x10
        ListGet& operator=(const ListGet&);
    };

}} // namespace Instances::fl

// Builds XML nodes from source text with expat. The Classes::fl::XML ignoreComments and
// ignoreProcessingInstructions settings decide whether the comment and PI handlers are registered.
// 0x68 bytes.
class XMLParser
{
public:
    // The parse state: which kind of node the pending character data belongs to.
    enum Kind { kNone, kElement, kText, kComment, kDecl, kCData, kDocType, kProcInstr };

    // 0x1423f0130
    XMLParser(InstanceTraits::fl::XML& itr);

    // The expat handlers; userData is the XMLParser.
    // @0x142424100
    static void StartElementExpatCallback(void* userData, const char* name, const char** atts);
    // @0x142409730
    static void EndElementExpatCallback(void* userData, const char* name);
    // @0x142405ef0
    static void CharacterDataExpatCallback(void* userData, const char* s, int len);
    // @0x1424087a0
    static void XmlDeclExpatCallback(void* userData, const char* version, const char* encoding, int standalone);
    // @0x142424090
    static void StartDoctypeDeclExpatCallback(void* userData, const char* doctypeName, const char* sysid,
                                              const char* pubid, int has_internal_subset);
    // @0x1424096d0
    static void EndDoctypeDeclExpatCallback(void* userData);
    // @0x142408eb0
    static void DefaultExpatCallback(void* userData, const char* s, int len);
    // @0x1424064e0
    static void CommentExpatCallback(void* userData, const char* data);
    // @0x14241e160
    static void ProcessingInstructionExpatCallback(void* userData, const char* target, const char* data);

    // appends the top-level nodes (AddRef) to nodes. 0x142416f20
    void GetRootNodes(ArrayLH<SPtr<Instances::fl::XML> >& nodes) const;

public:
    char                                        NsSeparator;    // +0x00 ':'
    Instances::fl::XML::Kind                    CurrKind;       // +0x04
    InstanceTraits::fl::XML&                    ITr;            // +0x08
    XML_ParserStruct*                           Parser;         // +0x10
    SPtr<Instances::fl::XMLElement>             CurrElement;    // +0x18
    ArrayDH<SPtr<Instances::fl::XML> >          RootElements;   // +0x20
    ASString                                    Text;           // +0x40 the pending character data
    ArrayDH_POD<Kind>                           KindStack;      // +0x48
};

}}} // namespace Scaleform::GFx::AS3

#endif
