// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_FL_H
#define MS2_SF_GFX_AS3_OBJ_FL_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ThunkFunction : public Instances::FunctionBase
    {
    public:
        // @0x1424291d0
        void length(Value& result, unsigned, const Value*);

    protected:
        const ThunkInfo& Function;  // +0x40 (sfr17)
    };

}

namespace Instances { namespace fl {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class GlobalObject : public Instances::fl::Object
    {
    protected:
        // (appended, sfr19) global objects are not constructible (body in sfr_as3_03).
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class GlobalObjectCPP : public Instances::fl::GlobalObject
    {
    public:
        // @0x142427bd0
        void clearInterval(const Value& result, UInt32);
        // @0x142427bf0
        void clearTimeout(const Value& result, UInt32);
        // @0x142427cf0
        void decodeURI(ASString& result, const ASString&);
        // @0x142427e00
        void decodeURIComponent(ASString& result, const ASString&);
        // @0x142428110
        void describeType(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x142428140
        void encodeURI(ASString& result, const ASString&);
        // @0x142428210
        void encodeURIComponent(ASString& result, const ASString&);
        // @0x1424282f0
        void escape(Value& result, unsigned, const Value*);
        // @0x142428460
        void escapeMultiByte(ASString& result, const ASString&);
        // @0x142428890
        void fscommand(Value& result, unsigned, const Value*);
        // @0x142428a80
        void getDefinitionByName(Value& result, const ASString&);
        // @0x142428b70
        void getQualifiedClassName(ASString& result, const Value&);
        // @0x142428be0
        void getQualifiedSuperclassName(Value& result, const Value&);
        // @0x142428d70
        void getTimer(SInt32& result);
        // @0x142428f30
        void isFinite(bool& result, Value::Number);
        // @0x142428f60
        void isNaN(bool& result, Value::Number);
        // @0x142428fa0
        void isXMLName(bool& result, const Value&);
        // @0x142429af0
        void parseFloat(Value::Number& result, const ASString&);
        // @0x142429bd0
        void parseInt(Value& result, unsigned, const Value*);
        // @0x142429dc0
        void print(Value& result, unsigned, const Value*);
        // @0x14242a0c0
        void setInterval(Value& result, unsigned, const Value*);
        // @0x14242ae30
        void setTimeout(Value& result, unsigned, const Value*);
        // @0x14242b410
        void trace(Value& result, unsigned, const Value*);
        // @0x14242b590
        void unescape(Value& result, unsigned, const Value*);
        // @0x14242b700
        void unescapeMultiByte(ASString& result, const ASString&);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class XML : public Instances::fl::Object
    {
    public:
        // @0x1423f6b10
        void AS3addNamespace(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423f6d10
        void AS3appendChild(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423f6de0
        void AS3attribute(SPtr<Instances::fl::XMLList>& result, const Value&);
        // @0x1423f7120
        void AS3attributes(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f7580
        void AS3child(SPtr<Instances::fl::XMLList>& result, const Value&);
        // @0x1423f7920
        void AS3childIndex(SInt32& result);
        // @0x1423f7a10
        void AS3children(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f7cd0
        void AS3comments(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f8170
        void AS3contains(bool& result, const Value&);
        // @0x1423f8270
        void AS3copy(SPtr<Instances::fl::XML>& result);
        // @0x1423f8600
        void AS3descendants(Value& result, unsigned, const Value*);
        // @0x1423f8aa0
        void AS3elements(Value& result, unsigned, const Value*);
        // @0x1423fa9a0
        void AS3hasComplexContent(bool& result);
        // @0x1423fac40
        void AS3hasOwnProperty(bool& result, const ASString&);
        // @0x1423fac60
        void AS3hasSimpleContent(bool& result);
        // @0x1423fad50
        void AS3inScopeNamespaces(SPtr<Instances::fl::Array>& result);
        // @0x1423fb270
        void AS3insertChildAfter(Value& result, const Value&, const Value&);
        // @0x1423fb360
        void AS3insertChildBefore(Value& result, const Value&, const Value&);
        // @0x1423fb870
        void AS3length(SInt32& result);
        // @0x1423fb890
        void AS3localName(ASString& result);
        // @0x1423fc360
        void AS3name(SPtr<Instances::fl::QName>& result);
        // @0x1423fc4b0
        void AS3namespaceDeclarations(SPtr<Instances::fl::Array>& result);
        // @0x1423fc960
        void AS3namespace_(Value& result, unsigned, const Value*);
        // @0x1423fca80
        void AS3nodeKind(ASString& result);
        // @0x1423fcb70
        void AS3normalize(SPtr<Instances::fl::XML>& result);
        // @0x1423fcc70
        void AS3parent(Value& result);
        // @0x1423fcdb0
        void AS3prependChild(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fcec0
        void AS3processingInstructions(Value& result, unsigned, const Value*);
        // @0x1423fd4f0
        void AS3propertyIsEnumerable(Value& result, unsigned, const Value*);
        // @0x1423fd7f0
        void AS3removeNamespace(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fdca0
        void AS3replace(SPtr<Instances::fl::XML>& result, const Value&, const Value&);
        // @0x1423fe250
        void AS3setChildren(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fe3e0
        void AS3setLocalName(const Value& result, const Value&);
        // @0x1423fe620
        void AS3setName(const Value& result, const Value&);
        // @0x1423fe930
        void AS3setNamespace(const Value& result, const Value&);
        // @0x1424018e0
        void AS3text(SPtr<Instances::fl::XMLList>& result);
        // @0x142402b70
        void AS3toString(ASString& result);
        // @0x142403250
        void AS3toXMLString(ASString& result);
        // @0x142403960
        void AS3valueOf(SPtr<Instances::fl::XML>& result);
        // @0x142429df0
        void prototypeGet(SPtr<Instances::fl::XMLList>& result);
        // @0x142429f90
        void prototypeSet(const Value& result, const Value&);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
