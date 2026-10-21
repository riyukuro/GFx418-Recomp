// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, AS3_Obj_All part 1: the class
// traits factories of the core top-level classes and the constructors of their class traits, instance traits, class
// objects and instances (the constructor block is in class-name order). Our own source, written from the exe. Third
// source of queue unit sfr_as3_01.
// MS2-UNIT: sfr_as3_01c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423e0260-0x1423f06a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"
#include "GFx/GFx_ASUtils.h"
#include "Kernel/SF_HeapNew.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace ClassTraits { namespace fl
{
    // @0x1423e0660
    Pickable<Traits> Array::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Array(vm));
    }

    // @0x1423e1590
    Pickable<Traits> RegExp::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) RegExp(vm));
    }

    // @0x1423e16e0
    Pickable<Traits> Catch::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Catch(vm));
    }

    // @0x1423e1940
    Pickable<Traits> XMLList::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XMLList(vm));
    }

    // @0x1423e1ce0
    Pickable<Traits> QName::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) QName(vm));
    }

    // @0x1423e1e60
    Pickable<Traits> Error::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Error(vm));
    }

    // @0x1423e21c0
    Pickable<Traits> DefinitionError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) DefinitionError(vm));
    }

    // @0x1423e2310
    Pickable<Traits> EvalError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) EvalError(vm));
    }

    // @0x1423e2460
    Pickable<Traits> RangeError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) RangeError(vm));
    }

    // @0x1423e25b0
    Pickable<Traits> ReferenceError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ReferenceError(vm));
    }

    // @0x1423e2700
    Pickable<Traits> SecurityError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SecurityError(vm));
    }

    // @0x1423e2bf0
    Pickable<Traits> SyntaxError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SyntaxError(vm));
    }

    // @0x1423e3310
    Pickable<Traits> Number::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Number(vm));
    }

    // @0x1423e34a0
    Pickable<Traits> TypeError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TypeError(vm));
    }

    // @0x1423e35f0
    Pickable<Traits> URIError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) URIError(vm));
    }

    // @0x1423e3740
    Pickable<Traits> VerifyError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) VerifyError(vm));
    }

    // @0x1423e3890
    Pickable<Traits> UninitializedError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) UninitializedError(vm));
    }

    // @0x1423e39e0
    Pickable<Traits> ArgumentError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ArgumentError(vm));
    }

    // @0x1423e3e90
    Pickable<Traits> Date::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Date(vm));
    }

    // @0x1423e4930
    Pickable<Traits> Object::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Object(vm));
    }

    // @0x1423e5f30
    Pickable<Traits> int_::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) int_(vm));
    }

    // @0x1423e6380
    Pickable<Traits> Namespace::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Namespace(vm));
    }

    // @0x1423e6e80
    Pickable<Traits> uint::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) uint(vm));
    }

    // @0x1423e7210
    Pickable<Traits> Boolean::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Boolean(vm));
    }

    // @0x1423e7de0
    Pickable<Traits> String::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) String(vm));
    }

    // @0x1423e7f30
    Pickable<Traits> XML::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) XML(vm));
    }

    // @0x1423eb9f0
    ArgumentError::ArgumentError(VM& vm)
        : Traits(vm, AS3::fl::ArgumentErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::ArgumentErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ebaf0
    Array::Array(VM& vm)
        : Traits(vm, AS3::fl::ArrayCI)
    {
        TraitsType = Traits_Array;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Array(vm, AS3::fl::ArrayCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Array(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ebc20
    Array::Array(ClassTraits::Traits& t)
        : Class(t), CASEINSENSITIVE(1), DESCENDING(2), UNIQUESORT(4), RETURNINDEXEDARRAY(8), NUMERIC(16)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ebc70
    Array::Array(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        TraitsType = Traits_Array;
        SetMemSize(sizeof(Instances::fl::Array));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ebcb0
    Array::Array(InstanceTraits::Traits& t)
        : Instance(t), SA(t.GetVM().GetMemoryHeap())
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ebd20
    Boolean::Boolean(VM& vm)
        : Traits(vm, AS3::fl::BooleanCI)
    {
        TraitsType = Traits_Boolean;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Boolean(vm, AS3::fl::BooleanCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Boolean(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ebe20
    Boolean::Boolean(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ebe50
    Boolean::Boolean(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Boolean;
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ebe80
    Catch::Catch(VM& vm)
        : Traits(vm, AS3::fl::CatchCI)
    {
        TraitsType = Traits_Catch;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Catch(vm, AS3::fl::CatchCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Catch(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ebf90
    Catch::Catch(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ebfc0
    Catch::Catch(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Catch;
        SetMemSize(sizeof(Instances::fl::Catch));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ec100
    Catch::Catch(InstanceTraits::Traits& t)
        : Instance(t)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ec260
    Date::Date(VM& vm)
        : Traits(vm, AS3::fl::DateCI)
    {
        TraitsType = Traits_Date;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Date(vm, AS3::fl::DateCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Date(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ec370
    Date::Date(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ec3a0
    Date::Date(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Date;
        SetMemSize(sizeof(Instances::fl::Date));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ec3d0
    Date::Date(InstanceTraits::Traits& t)
        : Instance(t), TimeValue(0), LocalTZA(0)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ec540
    DefinitionError::DefinitionError(VM& vm)
        : Traits(vm, AS3::fl::DefinitionErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::DefinitionErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ec640
    Error::Error(VM& vm)
        : Traits(vm, AS3::fl::ErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::ErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Error(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ec740
    Error::Error(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ec770
    Error::Error(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl::Error));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ec7a0
    Error::Error(InstanceTraits::Traits& t)
        : Instance(t)
        , message(GetVM().GetStringManager().CreateEmptyString())
        , name(GetVM().GetStringManager().CreateEmptyString())
        , ID(0)
        , StackTrace(GetVM().GetStringManager().CreateEmptyString())
    {
        name = t.GetName();
        GetVM().GetStackTraceASString(StackTrace);
    }

    // @0x1423ec890
    Error::Error(InstanceTraits::Traits& t, int id, const ASString& msg)
        : Instance(t)
        , message(msg)
        , name(GetVM().GetStringManager().CreateConstString("Error"))
        , ID(id)
        , StackTrace(GetVM().GetStringManager().CreateEmptyString())
    {
        GetVM().GetStackTraceASString(StackTrace);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ec940
    EvalError::EvalError(VM& vm)
        : Traits(vm, AS3::fl::EvalErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::EvalErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }
}}

namespace InstanceTraits
{
    // @0x1423ed810
    Interface::Interface(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetIsInterface();
        SetMemSize(sizeof(Instances::fl::Object));
    }
}

namespace ClassTraits { namespace fl
{
    // @0x1423ed840
    Math::Math(VM& vm)
        : Traits(vm, AS3::fl::MathCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl::MathCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Math(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ed9c0
    Math::Math(ClassTraits::Traits& t)
        : Class(t), LN10(2.302585092994046), E(2.718281828459045), LN2(0.6931471805599453), LOG10E(0.4342944819032518),
      LOG2E(1.4426950408889634), PI(3.141592653589793), SQRT1_2(0.7071067811865476), SQRT2(1.4142135623730951)
    {
    }
}}

namespace Instances
{
    // @0x1423edad0
    Namespace::Namespace(VM& vm, Abc::NamespaceKind kind, const char* uri)
        : GASRefCountBase(vm.GetGCPtr())
        , Kind(kind)
        , IsInterface(false)
        , VMRef(vm)
        , Uri(vm.GetStringManager().CreateConstString(uri))
    {
    }

    // @0x1423edb60
    Namespace::Namespace(VM& vm, NamespaceInstanceFactory* pfactory, Abc::NamespaceKind kind, const ASString& uri,
                         const Value& prefix)
        : GASRefCountBase(vm.GetGCPtr())
        , Kind(kind)
        , IsInterface(false)
        , VMRef(vm)
        , Uri(uri)
        , pFactory(pfactory)
        , Prefix(prefix)
    {
    }
}

namespace ClassTraits { namespace fl
{
    // @0x1423edc20
    Namespace::Namespace(VM& vm)
        : Traits(vm, AS3::fl::NamespaceCI)
    {
        TraitsType = Traits_Namespace;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Namespace(vm, AS3::fl::NamespaceCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Namespace(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423edd90
    Namespace::Namespace(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423eddc0
    Namespace::Namespace(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Namespace;
        InstanceFactory = *SF_HEAP_NEW(vm.GetMemoryHeap()) NamespaceInstanceFactory(this);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ede60
    Number::Number(VM& vm)
        : Traits(vm, AS3::fl::NumberCI)
    {
        TraitsType = Traits_Number;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Number(vm, AS3::fl::NumberCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Number(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423edfa0
    Number::Number(ClassTraits::Traits& t)
        : Class(t), NaN(NumberUtil::NaN()), NEGATIVE_INFINITY(NumberUtil::NEGATIVE_INFINITY()),
      POSITIVE_INFINITY(NumberUtil::POSITIVE_INFINITY()), MIN_VALUE(2.2250738585072014e-308),
      MAX_VALUE(1.7976931348623157e+308)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ee000
    Number::Number(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_Number;
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ee030
    Object::Object(VM& vm)
        : Traits(vm, AS3::fl::ObjectCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl::ObjectCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::Object(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ee130
    Object::Object(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ee160
    Object::Object(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl::Object));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ee190
    Object::Object(VM& vm)
        : Instance(vm)
    {
    }

    // @0x1423ee1c0
    Object::Object(InstanceTraits::Traits& t)
        : Instance(t)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ee840
    QName::QName(VM& vm)
        : Traits(vm, AS3::fl::QNameCI)
    {
        TraitsType = Traits_QName;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::QName(vm, AS3::fl::QNameCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::QName(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ee950
    QName::QName(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ee980
    QName::QName(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_QName;
        SetMemSize(sizeof(Instances::fl::QName));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423ee9b0
    QName::QName(InstanceTraits::Traits& t)
        : Instance(t)
        , LocalName(GetVM().GetStringManager().CreateEmptyString())
        , Ns(&t.GetVM().GetPublicNamespace())
    {
    }

    // @0x1423eea20
    QName::QName(InstanceTraits::Traits& t, const ASString& local, Instances::Namespace* ns)
        : Instance(t), LocalName(local), Ns(ns)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423eea80
    RangeError::RangeError(VM& vm)
        : Traits(vm, AS3::fl::RangeErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::RangeErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423eeb80
    ReferenceError::ReferenceError(VM& vm)
        : Traits(vm, AS3::fl::ReferenceErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::ReferenceErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423eec80
    RegExp::RegExp(VM& vm)
        : Traits(vm, AS3::fl::RegExpCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::RegExp(vm, AS3::fl::RegExpCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::RegExp(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423eed80
    RegExp::RegExp(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423eedb0
    RegExp::RegExp(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(Instances::fl::RegExp));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423eede0
    RegExp::RegExp(InstanceTraits::Traits& t)
        : Instance(t)
        , CompRegExp(NULL)
        , MatchOffset(-1)
        , MatchLength(0)
        , IsGlobal(false)
        , LastIndex(0)
        , OptionFlags(0x800)
        , HasNamedGroups(false)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423eee40
    SecurityError::SecurityError(VM& vm)
        : Traits(vm, AS3::fl::SecurityErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::SecurityErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423eef70
    String::String(VM& vm)
        : Traits(vm, AS3::fl::StringCI)
    {
        TraitsType = Traits_String;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::String(vm, AS3::fl::StringCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::String(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423ef070
    String::String(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423ef0a0
    String::String(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_String;
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423ef0d0
    SyntaxError::SyntaxError(VM& vm)
        : Traits(vm, AS3::fl::SyntaxErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::SyntaxErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ef390
    TypeError::TypeError(VM& vm)
        : Traits(vm, AS3::fl::TypeErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::TypeErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ef490
    URIError::URIError(VM& vm)
        : Traits(vm, AS3::fl::URIErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::URIErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423ef590
    UninitializedError::UninitializedError(VM& vm)
        : Traits(vm, AS3::fl::UninitializedErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::UninitializedErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423efa10
    VerifyError::VerifyError(VM& vm)
        : Traits(vm, AS3::fl::VerifyErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl::VerifyErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) ClassCallConstruct(*this)));
    }

    // @0x1423efb10
    XML::XML(VM& vm)
        : Traits(vm, AS3::fl::XMLCI)
    {
        TraitsType = Traits_XML;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::XML(vm, AS3::fl::XMLCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::XML(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423efc30
    XML::XML(ClassTraits::Traits& t)
        : Class(t), ignoreComments(true), ignoreProcessingInstructions(true), ignoreWhitespace(true), prettyPrinting(true),
      prettyIndent(2)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423efc60
    XML::XML(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_XML;
        SetMemSize(0x48);
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423eff70
    XMLList::XMLList(VM& vm)
        : Traits(vm, AS3::fl::XMLListCI)
    {
        TraitsType = Traits_XMLList;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::XMLList(vm, AS3::fl::XMLListCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::XMLList(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423f0080
    XMLList::XMLList(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423f00b0
    XMLList::XMLList(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        Flags |= ArrayLikeMask;
        TraitsType = Traits_XMLList;
        SetMemSize(sizeof(Instances::fl::XMLList));
    }
}}

namespace Instances { namespace fl
{
    // @0x1423f00f0
    XMLList::XMLList(InstanceTraits::Traits& t)
        : Instance(t), TargetProperty(NULL)
    {
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423f0350
    int_::int_(VM& vm)
        : Traits(vm, AS3::fl::int_CI)
    {
        TraitsType = Traits_SInt;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::int_(vm, AS3::fl::int_CI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::int_(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423f0460
    int_::int_(ClassTraits::Traits& t)
        : Class(t), MIN_VALUE(SF_MIN_SINT32), MAX_VALUE(SF_MAX_SINT32)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423f0490
    int_::int_(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_SInt;
    }
}}

namespace ClassTraits { namespace fl
{
    // @0x1423f04c0
    uint::uint(VM& vm)
        : Traits(vm, AS3::fl::uintCI)
    {
        TraitsType = Traits_UInt;
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::uint(vm, AS3::fl::uintCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl::uint(*this)));
    }
}}

namespace Classes { namespace fl
{
    // @0x1423f05d0
    uint::uint(ClassTraits::Traits& t)
        : Class(t), MIN_VALUE(0), MAX_VALUE(SF_MAX_UINT32)
    {
    }
}}

namespace InstanceTraits { namespace fl
{
    // @0x1423f0600
    uint::uint(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        TraitsType = Traits_UInt;
    }
}}

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7GASRefCountBase@AS3@GFx@Scaleform@@6B@ 0x14313f398
// MS2-PIN: ??_7Interface@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313f870
// MS2-PIN: ??_7Object@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313f650
// MS2-PIN: ??_7ClassCallConstruct@AS3@GFx@Scaleform@@6B@ 0x14313f3c8
// MS2-PIN: ??_7Object@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x14313f590
// MS2-PIN: ??_7Namespace@Instances@AS3@GFx@Scaleform@@6B@ 0x143140070
// MS2-PIN: ??_7Array@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431415b0
// MS2-PIN: ??_7Catch@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143140530
// MS2-PIN: ??_7Date@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142508
// MS2-PIN: ??_7Error@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143141b80
// MS2-PIN: ??_7QName@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143140810
// MS2-PIN: ??_7RegExp@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143141880
// MS2-PIN: ??_7XMLList@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431436d0
// MS2-PIN: ??_7NamespaceInstanceFactory@AS3@GFx@Scaleform@@6B@ 0x143140af8
// MS2-PIN: ??_7Array@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141670
// MS2-PIN: ??_7Boolean@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141148
// MS2-PIN: ??_7Catch@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431405f0
// MS2-PIN: ??_7Date@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431425c8
// MS2-PIN: ??_7Error@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141c40
// MS2-PIN: ??_7Namespace@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431400a8
// MS2-PIN: ??_7Number@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143140b00
// MS2-PIN: ??_7QName@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431408d0
// MS2-PIN: ??_7RegExp@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141940
// MS2-PIN: ??_7String@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143141360
// MS2-PIN: ??_7XML@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143142bb0
// MS2-PIN: ??_7XMLList@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143143790
// MS2-PIN: ??_7int_@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143140d28
// MS2-PIN: ??_7uint@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143140f38
// MS2-PIN: ??_7Object@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x14313f788
// MS2-PIN: ??_7Array@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431417a0
// MS2-PIN: ??_7Boolean@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141278
// MS2-PIN: ??_7Catch@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143140728
// MS2-PIN: ??_7Date@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431426f8
// MS2-PIN: ??_7Error@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141d70
// MS2-PIN: ??_7Math@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431428e8
// MS2-PIN: ??_7Namespace@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431401e0
// MS2-PIN: ??_7Number@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143140c30
// MS2-PIN: ??_7QName@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143140a08
// MS2-PIN: ??_7RegExp@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141a78
// MS2-PIN: ??_7String@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141490
// MS2-PIN: ??_7XML@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143142ce0
// MS2-PIN: ??_7XMLList@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x1431438d0
// MS2-PIN: ??_7int_@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143140e58
// MS2-PIN: ??_7uint@fl@Classes@AS3@GFx@Scaleform@@6B@ 0x143141068
// MS2-PIN: ??_7ArgumentError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142470
// MS2-PIN: ??_7Array@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141710
// MS2-PIN: ??_7Boolean@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431411e8
// MS2-PIN: ??_7Catch@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140698
// MS2-PIN: ??_7Date@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142668
// MS2-PIN: ??_7DefinitionError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141ea0
// MS2-PIN: ??_7Error@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141ce0
// MS2-PIN: ??_7EvalError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141f38
// MS2-PIN: ??_7int_@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140dc8
// MS2-PIN: ??_7Math@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142858
// MS2-PIN: ??_7Namespace@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140150
// MS2-PIN: ??_7Number@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140ba0
// MS2-PIN: ??_7Object@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14313f6f8
// MS2-PIN: ??_7QName@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140978
// MS2-PIN: ??_7RangeError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141fc8
// MS2-PIN: ??_7ReferenceError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142058
// MS2-PIN: ??_7RegExp@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431419e8
// MS2-PIN: ??_7SecurityError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431420f0
// MS2-PIN: ??_7String@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143141400
// MS2-PIN: ??_7SyntaxError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142188
// MS2-PIN: ??_7TypeError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142220
// MS2-PIN: ??_7uint@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143140fd8
// MS2-PIN: ??_7UninitializedError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431423d8
// MS2-PIN: ??_7URIError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431422b0
// MS2-PIN: ??_7VerifyError@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142340
// MS2-PIN: ??_7XML@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143142c50
// MS2-PIN: ??_7XMLList@fl@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143143838
