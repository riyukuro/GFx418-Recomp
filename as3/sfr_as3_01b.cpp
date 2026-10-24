// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, flash.accessibility package
// (Accessibility, AccessibilityImplementation, AccessibilityProperties, ISearchableText, ISimpleTextSelection). Our own
// source, written from the exe. Second source of queue unit sfr_as3_01 (between GFx_AS3Support and the AS3 collector).
// None of the package's methods does anything in this build: every thunk of the descriptors points to one empty stub.
// MS2-UNIT: sfr_as3_01b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423dd550-0x1423de620 .text$mn
// MS2-RANGE: 0x1423df430-0x1423df850 .text$mn
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// Native class descriptors (data of the exe, with the thunk and member tables).
namespace fl_accessibility
{
    extern const ClassInfo ISearchableTextCI;
    extern const ClassInfo ISimpleTextSelectionCI;
    extern const ClassInfo AccessibilityCI;
    extern const ClassInfo AccessibilityImplementationCI;
    extern const ClassInfo AccessibilityPropertiesCI;
}

// ==== instances ======================================================================================================

namespace InstanceTraits { namespace fl_accessibility
{
    class AccessibilityImplementation;
    class AccessibilityProperties;
}}

namespace Instances { namespace fl_accessibility
{
    // 0x40 bytes.
    class AccessibilityImplementation : public Instances::fl::Object
    {
        friend class InstanceTraits::fl_accessibility::AccessibilityImplementation;
    public:
        AccessibilityImplementation(InstanceTraits::Traits& t);
        // @0x1423df520
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_accessibility::AccessibilityImplementation"; }

        UInt32  errno_;     // +0x38 "errno"
        bool    stub;       // +0x3c
    };

    // 0x68 bytes.
    class AccessibilityProperties : public Instances::fl::Object
    {
        friend class InstanceTraits::fl_accessibility::AccessibilityProperties;
    public:
        AccessibilityProperties(InstanceTraits::Traits& t);
        // @0x1423df550
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_accessibility::AccessibilityProperties"; }

        ASString    description;    // +0x38
        bool        forceSimple;    // +0x40
        ASString    name;           // +0x48
        bool        noAutoLabeling; // +0x50
        ASString    shortcut;       // +0x58
        bool        silent;         // +0x60
    };
}}

namespace InstanceTraits { namespace fl_accessibility
{
    class AccessibilityImplementation : public CTraits
    {
    public:
        typedef Instances::fl_accessibility::AccessibilityImplementation InstanceType;

        AccessibilityImplementation(VM& vm, const ClassInfo& ci);
        // @0x1423df510
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::AccessibilityImplementation"; }
        // @0x1423df720
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(MakeInstance(static_cast<AccessibilityImplementation&>(t)));
        }

        Pickable<InstanceType> MakeInstance(AccessibilityImplementation& t);
    };

    class AccessibilityProperties : public CTraits
    {
    public:
        typedef Instances::fl_accessibility::AccessibilityProperties InstanceType;

        AccessibilityProperties(VM& vm, const ClassInfo& ci);
        // @0x1423df540
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::AccessibilityProperties"; }
        // @0x1423df790
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(MakeInstance(static_cast<AccessibilityProperties&>(t)));
        }

        Pickable<InstanceType> MakeInstance(AccessibilityProperties& t);
    };
}}

// ==== classes ========================================================================================================

namespace Classes { namespace fl_accessibility
{
    class Accessibility : public Class
    {
    public:
        Accessibility(ClassTraits::Traits& t);
        // @0x1423df4f0
        virtual const char* GetAS3ObjectType() const { return "Classes::Accessibility"; }
    };
}}

// ==== class traits ===================================================================================================

namespace ClassTraits { namespace fl_accessibility
{
    class Accessibility : public Traits
    {
    public:
        Accessibility(VM& vm);
        // @0x1423df4e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Accessibility"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class AccessibilityImplementation : public Traits
    {
    public:
        AccessibilityImplementation(VM& vm);
        // @0x1423df500
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::AccessibilityImplementation"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class AccessibilityProperties : public Traits
    {
    public:
        AccessibilityProperties(VM& vm);
        // @0x1423df530
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::AccessibilityProperties"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ISearchableText : public Traits
    {
    public:
        ISearchableText(VM& vm);
        // @0x1423df560
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ISearchableText"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ISimpleTextSelection : public Traits
    {
    public:
        ISimpleTextSelection(VM& vm);
        // @0x1423df570
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ISimpleTextSelection"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };
}}

// ---- factories ------------------------------------------------------------------------------------------------------

namespace ClassTraits { namespace fl_accessibility
{
    // @0x1423dd550
    Pickable<Traits> ISimpleTextSelection::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ISimpleTextSelection(vm));
    }

    // @0x1423dd670
    Pickable<Traits> Accessibility::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Accessibility(vm));
    }

    // @0x1423dd7b0
    Pickable<Traits> AccessibilityImplementation::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) AccessibilityImplementation(vm));
    }

    // @0x1423dd8f0
    Pickable<Traits> AccessibilityProperties::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) AccessibilityProperties(vm));
    }

    // @0x1423dda30
    Pickable<Traits> ISearchableText::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ISearchableText(vm));
    }

    // ---- constructors -----------------------------------------------------------------------------------------------

    // Accessibility has no instances of its own: plain Object instance traits.
    // @0x1423ddb50
    Accessibility::Accessibility(VM& vm)
        : Traits(vm, AS3::fl_accessibility::AccessibilityCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_accessibility::AccessibilityCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_accessibility::Accessibility(*this)));
    }
}}

namespace Classes { namespace fl_accessibility
{
    // @0x1423ddc30
    Accessibility::Accessibility(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_accessibility
{
    // @0x1423ddc60
    AccessibilityImplementation::AccessibilityImplementation(VM& vm)
        : Traits(vm, AS3::fl_accessibility::AccessibilityImplementationCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_accessibility::AccessibilityImplementation(
            vm, AS3::fl_accessibility::AccessibilityImplementationCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_accessibility
{
    // @0x1423ddd60
    AccessibilityImplementation::AccessibilityImplementation(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_accessibility
{
    // @0x1423ddd90
    AccessibilityImplementation::AccessibilityImplementation(InstanceTraits::Traits& t)
        : Instances::fl::Object(t), errno_(0), stub(false)
    {
    }
}}

namespace ClassTraits { namespace fl_accessibility
{
    // @0x1423dddc0
    AccessibilityProperties::AccessibilityProperties(VM& vm)
        : Traits(vm, AS3::fl_accessibility::AccessibilityPropertiesCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_accessibility::AccessibilityProperties(
            vm, AS3::fl_accessibility::AccessibilityPropertiesCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_accessibility
{
    // @0x1423ddec0
    AccessibilityProperties::AccessibilityProperties(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_accessibility
{
    // @0x1423ddef0
    AccessibilityProperties::AccessibilityProperties(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , description(GetVM().GetStringManager().CreateEmptyString())
        , forceSimple(false)
        , name(GetVM().GetStringManager().CreateEmptyString())
        , noAutoLabeling(false)
        , shortcut(GetVM().GetStringManager().CreateEmptyString())
        , silent(false)
    {
    }
}}

namespace ClassTraits { namespace fl_accessibility
{
    // Interfaces: interface instance traits, plain class object.
    // @0x1423ddf80
    ISearchableText::ISearchableText(VM& vm)
        : Traits(vm, AS3::fl_accessibility::ISearchableTextCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_accessibility::ISearchableTextCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1423de060
    ISimpleTextSelection::ISimpleTextSelection(VM& vm)
        : Traits(vm, AS3::fl_accessibility::ISimpleTextSelectionCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::Interface(vm, AS3::fl_accessibility::ISimpleTextSelectionCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

// ---- instance factories ---------------------------------------------------------------------------------------------

namespace InstanceTraits { namespace fl_accessibility
{
    // @0x1423df5c0
    Pickable<AccessibilityImplementation::InstanceType> AccessibilityImplementation::MakeInstance(AccessibilityImplementation& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x1423df640
    Pickable<AccessibilityProperties::InstanceType> AccessibilityProperties::MakeInstance(AccessibilityProperties& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }
}}

// ---- Object / collector-base virtual defaults ---------------------------------------------------------------------

// @0x1423df580
void* Object::Unk15()
{
    return 0;
}

// @0x1423df590
void Object::InitInstance(bool)
{
}

// Only AS3 objects say so; the collector base is not one.
template <int Stat>
bool RefCountBaseGC<Stat>::IsAS3Object() const
{
    return false;
}
// @0x1423df5a0
template bool RefCountBaseGC<323>::IsAS3Object() const;

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ??_7AccessibilityImplementation@fl_accessibility@Instances@AS3@GFx@Scaleform@@6B@ 0x14313cbe0
// MS2-PIN: ??_7AccessibilityProperties@fl_accessibility@Instances@AS3@GFx@Scaleform@@6B@ 0x14313ce28
// MS2-PIN: ??_7AccessibilityImplementation@fl_accessibility@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313ccc8
// MS2-PIN: ??_7AccessibilityProperties@fl_accessibility@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14313cf08
// MS2-PIN: ??_7Accessibility@fl_accessibility@Classes@AS3@GFx@Scaleform@@6B@ 0x14313caf8
// MS2-PIN: ??_7Accessibility@fl_accessibility@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14313ca60
// MS2-PIN: ??_7AccessibilityImplementation@fl_accessibility@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14313cd80
// MS2-PIN: ??_7AccessibilityProperties@fl_accessibility@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14313cfb8
// MS2-PIN: ??_7ISearchableText@fl_accessibility@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14313c928
// MS2-PIN: ??_7ISimpleTextSelection@fl_accessibility@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14313c9c0
