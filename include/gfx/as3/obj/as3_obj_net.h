// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_NET_H
#define MS2_SF_GFX_AS3_OBJ_NET_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_net {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class NetConnection : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x14249adb0
        void addHeader(const Value& result, const ASString&, bool, const Value&);
        // @0x14249ae50
        void call(Value& result, unsigned, const Value*);
        // @0x14249ae90
        void clientGet(SPtr<Instances::fl::Object>& result);
        // @0x14249aed0
        void clientSet(const Value& result, const Value&);
        // @0x14249af10
        void close(const Value& result);
        // @0x14249af70
        void connect(Value& result, unsigned, const Value*);
        // @0x14249afa0
        void connectedGet(bool& result);
        // @0x14249afc0
        void connectedProxyTypeGet(ASString& result);
        // @0x14249b470
        void defaultObjectEncodingSet(const Value& result, UInt32);
        // @0x14249bd50
        void objectEncodingGet(UInt32& result);
        // @0x14249bd90
        void objectEncodingSet(const Value& result, UInt32);
        // @0x14249bdd0
        void proxyTypeGet(ASString& result);
        // @0x14249bdf0
        void proxyTypeSet(const Value& result, const ASString&);
        // @0x14249c3c0
        void uriGet(ASString& result);
        // @0x14249c4e0
        void usingTLSGet(bool& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class SharedObject : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x14249ae70
        void clear(const Value& result);
        // @0x14249aeb0
        void clientGet(SPtr<Instances::fl::Object>& result);
        // @0x14249aef0
        void clientSet(const Value& result, const Value&);
        // @0x14249af30
        void close(const Value& result);
        // @0x14249af80
        void connect(const Value& result, Instances::fl_net::NetConnection*, const ASString&);
        // @0x14249b020
        void dataGet(SPtr<Instances::fl::Object>& result);
        // @0x14249b490
        void defaultObjectEncodingSet(const Value& result, UInt32);
        // @0x14249b4f0
        void flush(ASString& result, SInt32);
        // @0x14249b6f0
        void fpsSet(const Value& result, Value::Number);
        // @0x14249bd70
        void objectEncodingGet(UInt32& result);
        // @0x14249bdb0
        void objectEncodingSet(const Value& result, UInt32);
        // @0x14249be90
        void send(Value& result, unsigned, const Value*);
        // @0x14249beb0
        void setDirty(const Value& result, const ASString&);
        // @0x14249bed0
        void setProperty(const Value& result, const ASString&, const Value&);
        // @0x14249c360
        void sizeGet(UInt32& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class URLLoader : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x14249ad90
        void addEventListener(const Value& result, const ASString&, const Value&, bool, SInt32, bool);
        // @0x14249af50
        void close(const Value& result);
        // @0x14249bcb0
        void load(const Value& result, Instances::fl_net::URLRequest*);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class URLRequest : public Instances::fl::Object
    {
    public:
        // @0x14249add0
        void authenticateGet(bool& result);
        // @0x14249adf0
        void authenticateSet(const Value& result, bool);
        // @0x14249ae10
        void cacheResponseGet(bool& result);
        // @0x14249ae30
        void cacheResponseSet(const Value& result, bool);
        // @0x14249afe0
        void contentTypeGet(ASString& result);
        // @0x14249b000
        void contentTypeSet(const Value& result, const ASString&);
        // @0x14249b030
        void dataGet(Value& result);
        // @0x14249b040
        void dataSet(const Value& result, const Value&);
        // @0x14249b4b0
        void digestGet(ASString& result);
        // @0x14249b4d0
        void digestSet(const Value& result, const ASString&);
        // @0x14249b6b0
        void followRedirectsGet(bool& result);
        // @0x14249b6d0
        void followRedirectsSet(const Value& result, bool);
        // @0x14249bcd0
        void manageCookiesGet(bool& result);
        // @0x14249bcf0
        void manageCookiesSet(const Value& result, bool);
        // @0x14249bd10
        void methodGet(ASString& result);
        // @0x14249bd30
        void methodSet(const Value& result, const ASString&);
        // @0x14249be50
        void requestHeadersGet(SPtr<Instances::fl::Array>& result);
        // @0x14249be70
        void requestHeadersSet(const Value& result, Instances::fl::Array*);
        // @0x14249c3e0
        void urlGet(ASString& result);
        // @0x14249c420
        void urlSet(const Value& result, const ASString&);
        // @0x14249c460
        void useCacheGet(bool& result);
        // @0x14249c480
        void useCacheSet(const Value& result, bool);
        // @0x14249c4a0
        void userAgentGet(ASString& result);
        // @0x14249c4c0
        void userAgentSet(const Value& result, const ASString&);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class URLVariables : public Instances::fl::Object
    {
    public:
        // @0x14249b0a0
        void decode(const Value& result, const ASString&);
        // @0x14249c380
        void toString(ASString& result);
    };

}}

namespace Classes { namespace fl_net {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class SharedObject : public Class
    {
    public:
        // @0x14249b710
        void getLocal(SPtr<Instances::fl_net::SharedObject>& result, const ASString&, const ASString&, bool);
        // @0x14249bc90
        void getRemote(SPtr<Instances::fl_net::SharedObject>& result, const ASString&, const ASString&, const Value&, bool);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
