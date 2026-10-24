// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_SYSTEM_H
#define MS2_SF_GFX_AS3_OBJ_SYSTEM_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_system {
    // 0x38 bytes.
    class ApplicationDomain : public Instances::fl::Object
    {
    public:
        ApplicationDomain(InstanceTraits::Traits& t);
        // @0x14249fcc0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_system::ApplicationDomain"; }

        // @0x1424a04a0
        void getDefinition(Value& result, const ASString&);
        // @0x1424a0530
        void hasDefinition(bool& result, const ASString&);
        // @0x1424a07c0
        void parentDomainGet(SPtr<Instances::fl_system::ApplicationDomain>& result);
    };

    // 0x38 bytes.
    class SecurityDomain : public Instances::fl::Object
    {
    public:
        SecurityDomain(InstanceTraits::Traits& t);
        // @0x14249fdb0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_system::SecurityDomain"; }
    };

    // 0x58 bytes.
    class LoaderContext : public Instances::fl::Object
    {
    public:
        LoaderContext(InstanceTraits::Traits& t);
        // @0x14249fd50
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_system::LoaderContext"; }

        bool                                        allowLoadBytesCodeExecution;    // +0x38
        SPtr<Instances::fl_system::ApplicationDomain> applicationDomain;            // +0x40
        bool                                        checkPolicyFile;                // +0x48
        SPtr<Instances::fl_system::SecurityDomain>  securityDomain;                 // +0x50
    };

}}

namespace Classes { namespace fl_system {
    class Capabilities : public Class
    {
    public:
        Capabilities(ClassTraits::Traits& t);
        // @0x14249fce0
        virtual const char* GetAS3ObjectType() const { return "Classes::Capabilities"; }

        // @0x1424a0090
        void avHardwareDisableGet(bool& result);
        // @0x1424a04d0
        void hasAccessibilityGet(bool& result);
        // @0x1424a04f0
        void hasAudioEncoderGet(bool& result);
        // @0x1424a0510
        void hasAudioGet(bool& result);
        // @0x1424a0550
        void hasEmbeddedVideoGet(bool& result);
        // @0x1424a0570
        void hasIMEGet(bool& result);
        // @0x1424a05c0
        void hasMP3Get(bool& result);
        // @0x1424a05e0
        void hasPrintingGet(bool& result);
        // @0x1424a0600
        void hasScreenBroadcastGet(bool& result);
        // @0x1424a0620
        void hasScreenPlaybackGet(bool& result);
        // @0x1424a0640
        void hasStreamingAudioGet(bool& result);
        // @0x1424a0660
        void hasStreamingVideoGet(bool& result);
        // @0x1424a0680
        void hasTLSGet(bool& result);
        // @0x1424a06a0
        void hasVideoEncoderGet(bool& result);
        // @0x1424a06e0
        void isDebuggerGet(bool& result);
        // @0x1424a06f0
        void languageGet(ASString& result);
        // @0x1424a0710
        void localFileReadDisableGet(bool& result);
        // @0x1424a0730
        void manufacturerGet(ASString& result);
        // @0x1424a07b0
        void osGet(ASString& result);
        // @0x1424a0800
        void pixelAspectRatioGet(Value::Number& result);
        // @0x1424a0820
        void playerTypeGet(ASString& result);
        // @0x1424a08b0
        void screenColorGet(ASString& result);
        // @0x1424a08d0
        void screenDPIGet(Value::Number& result);
        // @0x1424a08f0
        void screenResolutionXGet(Value::Number& result);
        // @0x1424a0910
        void screenResolutionYGet(Value::Number& result);
        // @0x1424a0930
        void serverStringGet(ASString& result);
        // @0x1424a0b50
        void versionGet(ASString& result);
    };

    class IME : public Class
    {
    public:
        IME(ClassTraits::Traits& t);
        // @0x14249fd00
        virtual const char* GetAS3ObjectType() const { return "Classes::IME"; }

        // @0x1424a00b0
        void conversionModeGet(ASString& result);
        // @0x1424a0120
        void conversionModeSet(const Value& result, const ASString&);
        // @0x1424a0210
        void doConversion(const Value& result);
        // @0x1424a0230
        void enabledGet(bool& result);
        // @0x1424a0290
        void enabledSet(const Value& result, bool);
        // @0x1424a0970
        void setCompositionString(const Value& result, const ASString&);
    };

    class SecurityDomain : public Class
    {
    public:
        SecurityDomain(ClassTraits::Traits& t);
        // @0x14249fd90
        virtual const char* GetAS3ObjectType() const { return "Classes::SecurityDomain"; }

        // @0x1424a01f0
        void currentDomainGet(SPtr<Instances::fl_system::SecurityDomain>& result);
    };

    // 0x58 bytes.
    class System : public Class
    {
    public:
        System(ClassTraits::Traits& t);
        // @0x14249fdf0
        virtual const char* GetAS3ObjectType() const { return "Classes::fl_system::System"; }
        bool useCodePage;   // +0x50

        // @0x1424a0460
        void exit(const Value& result, UInt32);
        // @0x1424a0480
        void gc(const Value& result);
        // @0x1424a06c0
        void imeGet(Value& result);
        // @0x1424a07e0
        void pause(const Value& result);
        // @0x1424a0890
        void resume(const Value& result);
        // @0x1424a0950
        void setClipboard(const Value& result, const ASString&);
        // @0x1424a0990
        void totalMemoryGet(UInt32& result);
    };

    // 0x90 bytes: the constants of flash.system.IMEConversionMode.
    class IMEConversionMode : public Class
    {
    public:
        IMEConversionMode(ClassTraits::Traits& t);
        // @0x14249fd20
        virtual const char* GetAS3ObjectType() const { return "Classes::IMEConversionMode"; }

        const char* ALPHANUMERIC_FULL;      // +0x50
        const char* ALPHANUMERIC_HALF;      // +0x58
        const char* CHINESE;                // +0x60
        const char* JAPANESE_HIRAGANA;      // +0x68
        const char* JAPANESE_KATAKANA_FULL; // +0x70
        const char* JAPANESE_KATAKANA_HALF; // +0x78
        const char* KOREAN;                 // +0x80
        const char* UNKNOWN;                // +0x88
    };

    // 0x78 bytes.
    class Security : public Class
    {
    public:
        Security(ClassTraits::Traits& t);
        // @0x14249fd70
        virtual const char* GetAS3ObjectType() const { return "Classes::Security"; }

        const char* APPLICATION;            // +0x50
        const char* LOCAL_TRUSTED;          // +0x58
        const char* LOCAL_WITH_FILE;        // +0x60
        const char* LOCAL_WITH_NETWORK;     // +0x68
        const char* REMOTE;                 // +0x70
    };

    // 0x88 bytes.
    class SecurityPanel : public Class
    {
    public:
        SecurityPanel(ClassTraits::Traits& t);
        // @0x14249fdd0
        virtual const char* GetAS3ObjectType() const { return "Classes::SecurityPanel"; }

        const char* CAMERA;                 // +0x50
        const char* DEFAULT;                // +0x58
        const char* DISPLAY;                // +0x60
        const char* LOCAL_STORAGE;          // +0x68
        const char* MICROPHONE;             // +0x70
        const char* PRIVACY;                // +0x78
        const char* SETTINGS_MANAGER;       // +0x80
    };

}}

namespace InstanceTraits { namespace fl_system {
    class ApplicationDomain : public CTraits
    {
    public:
        typedef Instances::fl_system::ApplicationDomain InstanceType;

        ApplicationDomain(VM& vm, const ClassInfo& ci);
        // @0x14249fcb0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::ApplicationDomain"; }
        // @0x14249ff60
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(MakeInstance(static_cast<ApplicationDomain&>(t)));
        }

        Pickable<InstanceType> MakeInstance(ApplicationDomain& t);
    };

    class LoaderContext : public CTraits
    {
    public:
        typedef Instances::fl_system::LoaderContext InstanceType;

        LoaderContext(VM& vm, const ClassInfo& ci);
        // @0x14249fd40
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::LoaderContext"; }
        // @0x14249ffc0
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(MakeInstance(static_cast<LoaderContext&>(t)));
        }

        Pickable<InstanceType> MakeInstance(LoaderContext& t);
    };

    class SecurityDomain : public CTraits
    {
    public:
        typedef Instances::fl_system::SecurityDomain InstanceType;

        SecurityDomain(VM& vm, const ClassInfo& ci);
        // @0x14249fda0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::SecurityDomain"; }
        // @0x1424a0030
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(MakeInstance(static_cast<SecurityDomain&>(t)));
        }

        Pickable<InstanceType> MakeInstance(SecurityDomain& t);
    };
}}

namespace ClassTraits { namespace fl_system {
    class ApplicationDomain : public Traits
    {
    public:
        ApplicationDomain(VM& vm);
        // @0x14249fca0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ApplicationDomain"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Capabilities : public Traits
    {
    public:
        Capabilities(VM& vm);
        // @0x14249fcd0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Capabilities"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IME : public Traits
    {
    public:
        IME(VM& vm);
        // @0x14249fcf0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IME"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IMEConversionMode : public Traits
    {
    public:
        IMEConversionMode(VM& vm);
        // @0x14249fd10
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IMEConversionMode"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class LoaderContext : public Traits
    {
    public:
        LoaderContext(VM& vm);
        // @0x14249fd30
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::LoaderContext"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Security : public Traits
    {
    public:
        Security(VM& vm);
        // @0x14249fd60
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Security"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SecurityDomain : public Traits
    {
    public:
        SecurityDomain(VM& vm);
        // @0x14249fd80
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SecurityDomain"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SecurityPanel : public Traits
    {
    public:
        SecurityPanel(VM& vm);
        // @0x14249fdc0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SecurityPanel"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class System : public Traits
    {
    public:
        System(VM& vm);
        // @0x14249fde0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::System"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

}}

}}} // namespace Scaleform::GFx::AS3

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain) == 0xc8, "ApplicationDomain size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::Capabilities) == 0xc8, "Capabilities size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::IME) == 0xc8, "IME size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::IMEConversionMode) == 0xc8, "IMEConversionMode size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::LoaderContext) == 0xc8, "LoaderContext size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::Security) == 0xc8, "Security size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain) == 0xc8, "SecurityDomain size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityPanel) == 0xc8, "SecurityPanel size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_system::System) == 0xc8, "System size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_system::Capabilities) == 0x50, "Capabilities size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_system::IME) == 0x50, "IME size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode) == 0x90, "IMEConversionMode size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_system::Security) == 0x78, "Security size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_system::SecurityDomain) == 0x50, "SecurityDomain size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_system::SecurityPanel) == 0x88, "SecurityPanel size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_system::System) == 0x58, "System size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain) == 0xe8, "ApplicationDomain size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext) == 0xe8, "LoaderContext size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_system::SecurityDomain) == 0xe8, "SecurityDomain size");

#endif
