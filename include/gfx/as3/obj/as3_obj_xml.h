// Recovered Scaleform GFx 4.1.18 AS3 flash.xml (XMLNode, XMLDocument, XMLNodeType) and flash.security
// (XMLSignatureValidator) traits and instances; our own declarations, layouts read from the exe ctors.
#ifndef MS2_SF_GFX_AS3_OBJ_XML_H
#define MS2_SF_GFX_AS3_OBJ_XML_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_xml {
    // Instance of flash.xml.XMLNode. 0x78 bytes, vftable 0x143176a80.
    class XMLNode : public Instances::fl::Object
    {
    public:
        XMLNode(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_xml::XMLNode"; }

        SPtr<XMLNode>   firstChild;         // +0x38
        SPtr<XMLNode>   lastChild;          // +0x40
        SPtr<XMLNode>   nextSibling;        // +0x48
        ASString        nodeName;           // +0x50
        UInt32          nodeType;           // +0x58
        ASString        nodeValue;          // +0x60
        SPtr<XMLNode>   parentNode;         // +0x68
        SPtr<XMLNode>   previousSibling;    // +0x70
    };

    // Instance of flash.xml.XMLDocument. 0x98 bytes, vftable 0x143176c78.
    class XMLDocument : public XMLNode
    {
    public:
        XMLDocument(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_xml::XMLDocument"; }

        SPtr<Instances::fl::Object> docTypeDecl;    // +0x78
        SPtr<Instances::fl::Object> idMap;          // +0x80
        bool                        ignoreWhite;    // +0x88
        SPtr<Instances::fl::Object> xmlDecl;        // +0x90
    };
}}

namespace InstanceTraits { namespace fl_xml {
    class XMLNode : public CTraits
    {
    public:
        typedef Instances::fl_xml::XMLNode InstanceType;

        XMLNode(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::XMLNode"; }
        virtual void MakeObject(Value& result, Traits& t);  // 0x1424cdc00
    };

    class XMLDocument : public CTraits
    {
    public:
        typedef Instances::fl_xml::XMLDocument InstanceType;

        XMLDocument(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::XMLDocument"; }
        virtual void MakeObject(Value& result, Traits& t);  // 0x1424cdb80
    };
}}

namespace Classes { namespace fl_xml {
    // 0x58 bytes, vftable 0x143176f18.
    class XMLNodeType : public Class
    {
    public:
        XMLNodeType(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::XMLNodeType"; }

        const UInt32 ELEMENT_NODE;  // +0x50
        const UInt32 TEXT_NODE;     // +0x54
    };
}}

namespace ClassTraits { namespace fl_xml {
    class XMLDocument : public Traits
    {
    public:
        XMLDocument(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::XMLDocument"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class XMLNode : public Traits
    {
    public:
        XMLNode(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::XMLNode"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class XMLNodeType : public Traits
    {
    public:
        XMLNodeType(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::XMLNodeType"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };
}}

namespace ClassTraits { namespace fl_security {
    class XMLSignatureValidator : public Traits
    {
    public:
        XMLSignatureValidator(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::XMLSignatureValidator"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };
}}

}}} // namespace Scaleform::GFx::AS3

#endif
