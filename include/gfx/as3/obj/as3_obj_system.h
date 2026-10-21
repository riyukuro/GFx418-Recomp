// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_SYSTEM_H
#define MS2_SF_GFX_AS3_OBJ_SYSTEM_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_system {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ApplicationDomain : public Instances::fl::Object
    {
    public:
        // @0x1424a04a0
        void getDefinition(Value& result, const ASString&);
        // @0x1424a0530
        void hasDefinition(bool& result, const ASString&);
        // @0x1424a07c0
        void parentDomainGet(SPtr<Instances::fl_system::ApplicationDomain>& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class LoaderContext : public Instances::fl::Object
    {
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class SecurityDomain : public Instances::fl::Object
    {
    };

}}

namespace Classes { namespace fl_system {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Capabilities : public Class
    {
    public:
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

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class IME : public Class
    {
    public:
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

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class SecurityDomain : public Class
    {
    public:
        // @0x1424a01f0
        void currentDomainGet(SPtr<Instances::fl_system::SecurityDomain>& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class System : public Class
    {
    public:
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

}}

}}} // namespace Scaleform::GFx::AS3

#endif
