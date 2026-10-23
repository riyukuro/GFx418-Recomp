// Scaleform GFx 4.1.18 AS3: objects, traits and classes defined by ABC code (user-defined classes and the global
// object of each script). Our own declarations; layouts from the exe's field accesses (vftables 0x143143bf0..
// 0x143144040, GetFixedMemSize 0x142415ae0 / 0x142415af0, the accessors at 0x142415a60..0x142415bf0).
#ifndef MS2_SF_GFX_AS3_OBJ_USERDEFINED_H
#define MS2_SF_GFX_AS3_OBJ_USERDEFINED_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fl.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace InstanceTraits { namespace fl { class GlobalObjectScript; } }

namespace Instances { namespace fl {
    // The global object of an ABC script; its slots are set up and the script run on first use. 0x40 bytes.
    // vftable 0x143143bf0 (22 slots).
    class GlobalObjectScript : public GlobalObject
    {
    public:
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::GlobalObjectScript"; }
        // The ABC file's source name. 0x142414c00
        virtual String GetAS3ObjectName() const;
        // Runs the script before its first slot is used. 0x142418d00
        virtual const SlotInfo* InitializeOnDemand(const SlotInfo* si, const ASString& name,
                                                   const Instances::Namespace& ns, UPInt& index);
        // Sets up the slots and runs the script body. 0x14240a4b0
        virtual void Execute();

        InstanceTraits::fl::GlobalObjectScript& GetTraits() const;
        VMAbcFile& GetFile() const;
        bool IsInitialized() const { return Initialized; }

        // Runs the script once, before the first use of the global object.
        void InitOnDemand()
        {
            if (!Initialized)
            {
                Execute();
                VM& vm = AS3::Object::GetTraits().GetVM();
                if (!vm.IsException())
                    vm.ExecuteCode(1);
            }
        }

    protected:
        bool Initialized;   // +0x38
    };
}}

namespace InstanceTraits { namespace fl {
    // Traits of global objects. 0xe8 bytes. vftable 0x143143d98.
    class GlobalObject : public CTraits
    {
    public:
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::GlobalObject"; }
        virtual bool IsGlobal() const { return true; }
        virtual void MakeObject(Value& result, Traits& t);     // 0x14241bfc0
    };

    // Traits of a script's global object. 0xf8 bytes. vftable 0x143143e48.
    class GlobalObjectScript : public GlobalObject
    {
    public:
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::GlobalObjectScript"; }
        virtual unsigned GetFixedMemSize() const { return sizeof(Instances::fl::GlobalObjectScript); }
        virtual VMAbcFile* GetFilePtr() const { return File; }

        VMAbcFile& GetFile() const { return *File; }
        const Abc::ScriptInfo& GetScript() const { return Script; }

    protected:
        SPtr<VMAbcFile>         File;       // +0xe8
        const Abc::ScriptInfo&  Script;     // +0xf0
    };
}}

namespace Instances { namespace fl {
    inline InstanceTraits::fl::GlobalObjectScript& GlobalObjectScript::GetTraits() const
    {
        return static_cast<InstanceTraits::fl::GlobalObjectScript&>(AS3::Object::GetTraits());
    }
    inline VMAbcFile& GlobalObjectScript::GetFile() const { return GetTraits().GetFile(); }
}}

namespace InstanceTraits {
    // Traits of instances of a class defined in ABC code. 0xe0 bytes. vftable 0x143143ef8 (18 slots).
    class UserDefined : public RTraits
    {
    public:
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::UserDefined"; }
        virtual VMAbcFile* GetFilePtr() const { return &GetFile(); }
        // The parent's slots first, then the class's own. 0x142423dc0
        virtual CheckResult SetupSlotValues(AS3::Object& for_obj) const;
        virtual Instances::fl::GlobalObjectScript* GetGlobalObjectScript() const { return Script; }
    protected:
        // Runs the defining script. 0x1424177b0
        virtual void InitOnDemand() const;
    public:
        // slots 15..17
        virtual void AS3Constructor(const AS3::Traits& ot, const Value& _this, unsigned argc, const Value* argv) const;
        virtual bool SupportsInterface(const Traits&) const;   // 0x142425370
        // Sets up the slots of a new instance. 0x14241e140
        virtual CheckResult PreInit(const Value& _this) const;

        // 0x142415a60
        VMAbcFile& GetFile() const;
        Instances::fl::GlobalObjectScript& GetScript() const { return *Script; }
        const Abc::ClassInfo& GetClassInfo() const { return class_info; }

    protected:
        SPtr<Instances::fl::GlobalObjectScript> Script;     // +0xd0
        const Abc::ClassInfo&                   class_info; // +0xd8
    };
}

namespace ClassTraits {
    // Traits of a class defined in ABC code. 0xd8 bytes. vftable 0x143143fa8.
    class UserDefined : public Traits
    {
    public:
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::UserDefined"; }
        virtual unsigned GetFixedMemSize() const { return 0x50; }   // sizeof(Classes::UserDefined)
        virtual VMAbcFile* GetFilePtr() const { return File; }
        // The class's static slots. 0x142423d90
        virtual CheckResult SetupSlotValues(AS3::Object& for_obj) const;
        virtual Instances::fl::GlobalObjectScript* GetGlobalObjectScript() const
        {
            return ITraits->GetGlobalObjectScript();
        }

        VMAbcFile& GetFile() const { return *File; }
        const Abc::ClassInfo& GetClassInfo() const { return class_info; }

    protected:
        SPtr<VMAbcFile>         File;       // +0xc8
        const Abc::ClassInfo&   class_info; // +0xd0
    };
}

namespace Classes {
    // Class object of a class defined in ABC code. 0x50 bytes. vftable 0x143144040.
    class UserDefined : public Class
    {
    public:
        virtual const char* GetAS3ObjectType() const { return "Classes::UserDefined"; }
        // 0x142414c60
        virtual String GetAS3ObjectName() const;
        // Runs the static initializer. 0x14241dea0
        virtual void PostInit(const Value& _this, unsigned argc, const Value* argv) const;

        const ClassTraits::UserDefined& GetClassTraits() const
        {
            return static_cast<const ClassTraits::UserDefined&>(GetTraits());
        }
        VMAbcFile& GetFile() const { return GetClassTraits().GetFile(); }
        const Abc::ClassInfo& GetClassInfo() const { return GetClassTraits().GetClassInfo(); }
    };
}

}}} // namespace Scaleform::GFx::AS3

#endif
