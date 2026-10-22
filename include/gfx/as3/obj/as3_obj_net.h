// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_NET_H
#define MS2_SF_GFX_AS3_OBJ_NET_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"
#include "ms2/scaleform/include/gfx/gfx_asstringhash.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_net {
    // 0x50 bytes.
    class NetConnection : public Instances::fl_events::EventDispatcher
    {
    public:
        NetConnection(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_net::NetConnection"; }

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

    // 0x68 bytes.
    class SharedObject : public Instances::fl_events::EventDispatcher
    {
    public:
        SharedObject(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_net::SharedObject"; }

        SPtr<Instances::fl::Object> Data;   // +0x50
        String                      Name;   // +0x58
        String                      LocalPath; // +0x60

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

    // 0x80 bytes.
    class URLLoader : public Instances::fl_events::EventDispatcher
    {
    public:
        URLLoader(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_net::URLLoader"; }

        void*       pLoadQueue;     // +0x50, not owned
        Value       Data;           // +0x58
        ASString    DataFormat;     // +0x78

        // @0x14249ad90
        void addEventListener(const Value& result, const ASString&, const Value&, bool, SInt32, bool);
        // @0x14249af50
        void close(const Value& result);
        // @0x14249bcb0
        void load(const Value& result, Instances::fl_net::URLRequest*);
    };

    // 0x48 bytes.
    class URLRequest : public Instances::fl::Object
    {
    public:
        URLRequest(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_net::URLRequest"; }
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;    // 0x1424991f0
        virtual void AS3Constructor(unsigned argc, const Value* argv);   // 0x142498890

        ASString                    Url;            // +0x38
        SPtr<Instances::fl::Array>  RequestHeaders; // +0x40

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

    // 0x40 bytes.
    class URLVariables : public Instances::fl::Object
    {
    public:
        URLVariables(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_net::URLVariables"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);   // 0x1424988c0

        ASString    Source;     // +0x38

        // @0x14249b0a0
        void decode(const Value& result, const ASString&);
        // @0x14249c380
        void toString(ASString& result);
    };

    // 0x48 bytes.
    class URLRequestHeader : public Instances::fl::Object
    {
    public:
        URLRequestHeader(InstanceTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_net::URLRequestHeader"; }

        ASString    HeaderName;     // +0x38
        ASString    HeaderValue;    // +0x40
    };

}}

namespace Classes { namespace fl_net {
    // 0x60 bytes.
    class ObjectEncoding : public Class
    {
    public:
        ObjectEncoding(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::ObjectEncoding"; }

        UInt32 AMF0;        // +0x50
        UInt32 AMF3;        // +0x54
        UInt32 Default;     // +0x58
    };

    // 0x58 bytes.
    class SharedObject : public Class
    {
    public:
        SharedObject(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::SharedObject"; }
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;    // 0x1424990f0

        // the shared objects already handed out, by name (allocator stat id 324)
        HashLH<ASString, SPtr<Instances::fl_net::SharedObject>, ASStringHashFunctor, 324> SharedObjects;  // +0x50

        // @0x14249b710
        void getLocal(SPtr<Instances::fl_net::SharedObject>& result, const ASString&, const ASString&, bool);
        // @0x14249bc90
        void getRemote(SPtr<Instances::fl_net::SharedObject>& result, const ASString&, const ASString&, const Value&, bool);
    };

    // 0x60 bytes.
    class SharedObjectFlushStatus : public Class
    {
    public:
        SharedObjectFlushStatus(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::SharedObjectFlushStatus"; }

        const char* Flushed;    // +0x50
        const char* Pending;    // +0x58
    };

    // 0x68 bytes.
    class URLLoaderDataFormat : public Class
    {
    public:
        URLLoaderDataFormat(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::URLLoaderDataFormat"; }

        const char* Binary;     // +0x50
        const char* Text;       // +0x58
        const char* Variables;  // +0x60
    };

    // 0x80 bytes.
    class URLRequestMethod : public Class
    {
    public:
        URLRequestMethod(ClassTraits::Traits& t);
        virtual const char* GetAS3ObjectType() const { return "Classes::URLRequestMethod"; }

        const char* Delete;     // +0x50
        const char* Get;        // +0x58
        const char* Head;       // +0x60
        const char* Options;    // +0x68
        const char* Post;       // +0x70
        const char* Put;        // +0x78
    };

}}

namespace InstanceTraits { namespace fl_net {
    class NetConnection : public CTraits
    {
    public:
        typedef Instances::fl_net::NetConnection InstanceType;

        NetConnection(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::NetConnection"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142499890
    };

    class SharedObject : public CTraits
    {
    public:
        typedef Instances::fl_net::SharedObject InstanceType;

        SharedObject(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::SharedObject"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424998f0
    };

    class URLLoader : public CTraits
    {
    public:
        typedef Instances::fl_net::URLLoader InstanceType;

        URLLoader(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::URLLoader"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142499970
    };

    class URLRequest : public CTraits
    {
    public:
        typedef Instances::fl_net::URLRequest InstanceType;

        URLRequest(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::URLRequest"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142499a10
    };

    class URLRequestHeader : public CTraits
    {
    public:
        typedef Instances::fl_net::URLRequestHeader InstanceType;

        URLRequestHeader(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::URLRequestHeader"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142499a90
    };

    class URLVariables : public CTraits
    {
    public:
        typedef Instances::fl_net::URLVariables InstanceType;

        URLVariables(VM& vm, const ClassInfo& ci);
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::URLVariables"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142499b30
    };

}}

namespace ClassTraits { namespace fl_net {
    class FileFilter : public Traits
    {
    public:
        FileFilter(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FileFilter"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class FileReference : public Traits
    {
    public:
        FileReference(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FileReference"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class FileReferenceList : public Traits
    {
    public:
        FileReferenceList(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FileReferenceList"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IDynamicPropertyOutput : public Traits
    {
    public:
        IDynamicPropertyOutput(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IDynamicPropertyOutput"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IDynamicPropertyWriter : public Traits
    {
    public:
        IDynamicPropertyWriter(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IDynamicPropertyWriter"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class LocalConnection : public Traits
    {
    public:
        LocalConnection(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::LocalConnection"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class NetConnection : public Traits
    {
    public:
        NetConnection(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::NetConnection"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ObjectEncoding : public Traits
    {
    public:
        ObjectEncoding(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ObjectEncoding"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Responder : public Traits
    {
    public:
        Responder(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Responder"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SharedObject : public Traits
    {
    public:
        SharedObject(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SharedObject"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SharedObjectFlushStatus : public Traits
    {
    public:
        SharedObjectFlushStatus(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SharedObjectFlushStatus"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Socket : public Traits
    {
    public:
        Socket(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Socket"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URLLoader : public Traits
    {
    public:
        URLLoader(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URLLoader"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URLLoaderDataFormat : public Traits
    {
    public:
        URLLoaderDataFormat(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URLLoaderDataFormat"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URLRequest : public Traits
    {
    public:
        URLRequest(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URLRequest"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URLRequestHeader : public Traits
    {
    public:
        URLRequestHeader(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URLRequestHeader"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URLRequestMethod : public Traits
    {
    public:
        URLRequestMethod(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URLRequestMethod"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URLStream : public Traits
    {
    public:
        URLStream(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URLStream"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URLVariables : public Traits
    {
    public:
        URLVariables(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URLVariables"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class XMLSocket : public Traits
    {
    public:
        XMLSocket(VM& vm);
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::XMLSocket"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
