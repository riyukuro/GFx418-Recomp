// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_11
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424832e0-0x142497a90 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x1424914e0: Instances::fl_net::URLRequest::authenticateGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 0, bool>;
// thunk 0x142491540: Instances::fl_net::URLRequest::authenticateSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 1, const Value, bool>;
// thunk 0x1424915a0: Instances::fl_net::URLRequest::cacheResponseGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 2, bool>;
// thunk 0x142491600: Instances::fl_net::URLRequest::cacheResponseSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 3, const Value, bool>;
// thunk 0x142491660: Instances::fl_net::URLRequest::contentTypeGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 4, ASString>;
// thunk 0x1424916d0: Instances::fl_net::URLRequest::contentTypeSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 5, const Value, const ASString&>;
// thunk 0x1424917d0: Instances::fl_net::URLRequest::dataGet
// MS2-FUNCTIONAL: not matched: the Value-result getter with no arguments is laid out differently by the exe (same calls)
template struct ThunkFunc0<Instances::fl_net::URLRequest, 6, Value>;
// thunk 0x142491880: Instances::fl_net::URLRequest::dataSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 7, const Value, const Value&>;
// thunk 0x1424919d0: Instances::fl_net::URLRequest::digestGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 8, ASString>;
// thunk 0x142491a40: Instances::fl_net::URLRequest::digestSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 9, const Value, const ASString&>;
// thunk 0x142491b40: Instances::fl_net::URLRequest::followRedirectsGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 10, bool>;
// thunk 0x142491ba0: Instances::fl_net::URLRequest::followRedirectsSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 11, const Value, bool>;
// thunk 0x142491c00: Instances::fl_net::URLRequest::manageCookiesGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 12, bool>;
// thunk 0x142491c60: Instances::fl_net::URLRequest::manageCookiesSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 13, const Value, bool>;
// thunk 0x142491cc0: Instances::fl_net::URLRequest::methodGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 14, ASString>;
// thunk 0x142491d30: Instances::fl_net::URLRequest::methodSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 15, const Value, const ASString&>;
// thunk 0x142491e30: Instances::fl_net::URLRequest::requestHeadersGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 16, SPtr<Instances::fl::Array>>;
// thunk 0x142491ee0: Instances::fl_net::URLRequest::requestHeadersSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 17, const Value, Instances::fl::Array*>;
// thunk 0x142491f20: Instances::fl_net::URLRequest::urlGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 18, ASString>;
// thunk 0x142491f90: Instances::fl_net::URLRequest::urlSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 19, const Value, const ASString&>;
// thunk 0x142492090: Instances::fl_net::URLRequest::useCacheGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 20, bool>;
// thunk 0x1424920f0: Instances::fl_net::URLRequest::useCacheSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 21, const Value, bool>;
// thunk 0x142492150: Instances::fl_net::URLRequest::userAgentGet
template struct ThunkFunc0<Instances::fl_net::URLRequest, 22, ASString>;
// thunk 0x1424921c0: Instances::fl_net::URLRequest::userAgentSet
template struct ThunkFunc1<Instances::fl_net::URLRequest, 23, const Value, const ASString&>;
// thunk 0x1424927f0: Instances::fl_net::URLVariables::decode
template struct ThunkFunc1<Instances::fl_net::URLVariables, 0, const Value, const ASString&>;
// thunk 0x1424928f0: Instances::fl_net::URLVariables::toString
template struct ThunkFunc0<Instances::fl_net::URLVariables, 1, ASString>;
// thunk 0x142492ce0: Instances::fl_net::SharedObject::clientGet
template struct ThunkFunc0<Instances::fl_net::SharedObject, 0, SPtr<Instances::fl::Object>>;
// thunk 0x142492d90: Instances::fl_net::SharedObject::clientSet
template struct ThunkFunc1<Instances::fl_net::SharedObject, 1, const Value, const Value&>;
// thunk 0x142492ee0: Instances::fl_net::SharedObject::dataGet
template struct ThunkFunc0<Instances::fl_net::SharedObject, 2, SPtr<Instances::fl::Object>>;
// thunk 0x142492f90: Instances::fl_net::SharedObject::defaultObjectEncodingSet
template struct ThunkFunc1<Instances::fl_net::SharedObject, 3, const Value, UInt32>;
// thunk 0x142493000: Instances::fl_net::SharedObject::fpsSet
template struct ThunkFunc1<Instances::fl_net::SharedObject, 4, const Value, Value::Number>;
// thunk 0x142493090: Instances::fl_net::SharedObject::objectEncodingGet
template struct ThunkFunc0<Instances::fl_net::SharedObject, 5, UInt32>;
// thunk 0x1424930f0: Instances::fl_net::SharedObject::objectEncodingSet
template struct ThunkFunc1<Instances::fl_net::SharedObject, 6, const Value, UInt32>;
// thunk 0x142493160: Instances::fl_net::SharedObject::sizeGet
template struct ThunkFunc0<Instances::fl_net::SharedObject, 7, UInt32>;
// thunk 0x1424931c0: Instances::fl_net::SharedObject::clear
template struct ThunkFunc0<Instances::fl_net::SharedObject, 8, const Value>;
// thunk 0x1424931e0: Instances::fl_net::SharedObject::close
template struct ThunkFunc0<Instances::fl_net::SharedObject, 9, const Value>;
// Instances::fl_net::SharedObject::connect argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_net::SharedObject, 10, 1, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("null"); }
};
// thunk 0x142493200: Instances::fl_net::SharedObject::connect
template struct ThunkFunc2<Instances::fl_net::SharedObject, 10, const Value, Instances::fl_net::NetConnection*, const ASString&>;
// thunk 0x142493340: Instances::fl_net::SharedObject::flush
template struct ThunkFunc1<Instances::fl_net::SharedObject, 11, ASString, SInt32>;
// thunk 0x1424933f0: Instances::fl_net::SharedObject::send
template struct ThunkFunc2<Instances::fl_net::SharedObject, 12, Value, unsigned, const Value*>;
// thunk 0x142493410: Instances::fl_net::SharedObject::setDirty
template struct ThunkFunc1<Instances::fl_net::SharedObject, 13, const Value, const ASString&>;
// thunk 0x142493510: Instances::fl_net::SharedObject::setProperty
template struct ThunkFunc2<Instances::fl_net::SharedObject, 14, const Value, const ASString&, const Value&>;
// Classes::fl_net::SharedObject::getLocal argument 1 default
template <> struct ThunkMethodDefault<Classes::fl_net::SharedObject, 0, 1, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("null"); }
};
// thunk 0x142493b70: Classes::fl_net::SharedObject::getLocal
// MS2-FUNCTIONAL: register allocation only: r12/r15 swapped for the result and argv (4 bytes longer in the exe)
template struct ThunkFunc3<Classes::fl_net::SharedObject, 0, SPtr<Instances::fl_net::SharedObject>, const ASString&, const ASString&, bool>;
// Classes::fl_net::SharedObject::getRemote argument 1 default
template <> struct ThunkMethodDefault<Classes::fl_net::SharedObject, 1, 1, const ASString&>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateConstString("null"); }
};
// Classes::fl_net::SharedObject::getRemote argument 2 default
template <> struct ThunkMethodDefault<Classes::fl_net::SharedObject, 1, 2, const Value&>
{
    SF_INLINE static Value Get(StringManager&) { return Value(false); }
};
// thunk 0x142493ce0: Classes::fl_net::SharedObject::getRemote
// MS2-FUNCTIONAL: register allocation only: the exe assigns the result and argv to other callee-saved registers
template struct ThunkFunc4<Classes::fl_net::SharedObject, 1, SPtr<Instances::fl_net::SharedObject>, const ASString&, const ASString&, const Value&, bool>;
// thunk 0x142494270: Instances::fl_net::NetConnection::clientGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 0, SPtr<Instances::fl::Object>>;
// thunk 0x142494320: Instances::fl_net::NetConnection::clientSet
template struct ThunkFunc1<Instances::fl_net::NetConnection, 1, const Value, const Value&>;
// thunk 0x142494470: Instances::fl_net::NetConnection::connectedGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 2, bool>;
// thunk 0x1424944d0: Instances::fl_net::NetConnection::connectedProxyTypeGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 3, ASString>;
// thunk 0x142494540: Instances::fl_net::NetConnection::defaultObjectEncodingSet
template struct ThunkFunc1<Instances::fl_net::NetConnection, 4, const Value, UInt32>;
// thunk 0x1424945b0: Instances::fl_net::NetConnection::objectEncodingGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 5, UInt32>;
// thunk 0x142494610: Instances::fl_net::NetConnection::objectEncodingSet
template struct ThunkFunc1<Instances::fl_net::NetConnection, 6, const Value, UInt32>;
// thunk 0x142494680: Instances::fl_net::NetConnection::proxyTypeGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 7, ASString>;
// thunk 0x1424946f0: Instances::fl_net::NetConnection::proxyTypeSet
template struct ThunkFunc1<Instances::fl_net::NetConnection, 8, const Value, const ASString&>;
// thunk 0x1424947f0: Instances::fl_net::NetConnection::uriGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 9, ASString>;
// thunk 0x142494860: Instances::fl_net::NetConnection::usingTLSGet
template struct ThunkFunc0<Instances::fl_net::NetConnection, 10, bool>;
// Instances::fl_net::NetConnection::addHeader argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_net::NetConnection, 11, 2, const Value&>
{
    SF_INLINE static Value Get(StringManager&) { return Value::GetNull(); }
};
// thunk 0x1424948c0: Instances::fl_net::NetConnection::addHeader
// MS2-FUNCTIONAL: register allocation only: the exe keeps the Null default in another register (same calls)
template struct ThunkFunc3<Instances::fl_net::NetConnection, 11, const Value, const ASString&, bool, const Value&>;
// thunk 0x142494ad0: Instances::fl_net::NetConnection::call
template struct ThunkFunc2<Instances::fl_net::NetConnection, 12, Value, unsigned, const Value*>;
// thunk 0x142494af0: Instances::fl_net::NetConnection::close
template struct ThunkFunc0<Instances::fl_net::NetConnection, 13, const Value>;
// thunk 0x142494b10: Instances::fl_net::NetConnection::connect
template struct ThunkFunc2<Instances::fl_net::NetConnection, 14, Value, unsigned, const Value*>;
// thunk 0x142495170: Instances::fl_net::URLLoader::addEventListener
template struct ThunkFunc5<Instances::fl_net::URLLoader, 0, const Value, const ASString&, const Value&, bool, SInt32, bool>;
// thunk 0x142495410: Instances::fl_net::URLLoader::close
template struct ThunkFunc0<Instances::fl_net::URLLoader, 1, const Value>;
// thunk 0x142495430: Instances::fl_net::URLLoader::load
template struct ThunkFunc1<Instances::fl_net::URLLoader, 2, const Value, Instances::fl_net::URLRequest*>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424914e0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491540
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424915a0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491600
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491660
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424916d0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$05VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424917d0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491880
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$07VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424919d0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491a40
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491b40
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491ba0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0M@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491c00
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491c60
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0O@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491cc0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491d30
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491e30
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@PEAVArray@fl@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491ee0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BC@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491f20
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142491f90
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BE@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492090
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424920f0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BG@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492150
// MS2-PIN: ?Func@?$ThunkFunc1@VURLRequest@fl_net@Instances@AS3@GFx@Scaleform@@$0BH@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424921c0
// MS2-PIN: ?Func@?$ThunkFunc1@VURLVariables@fl_net@Instances@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424927f0
// MS2-PIN: ?Func@?$ThunkFunc0@VURLVariables@fl_net@Instances@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424928f0
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492ce0
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492d90
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492ee0
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142492f90
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493000
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$04K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493090
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424930f0
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$06K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493160
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424931c0
// MS2-PIN: ?Func@?$ThunkFunc0@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424931e0
// MS2-PIN: ?Func@?$ThunkFunc2@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$09$$CBVValue@456@PEAVNetConnection@23456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493200
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0L@VASString@56@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493340
// MS2-PIN: ?Func@?$ThunkFunc2@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424933f0
// MS2-PIN: ?Func@?$ThunkFunc1@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493410
// MS2-PIN: ?Func@?$ThunkFunc2@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@AEBVASString@56@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493510
// MS2-PIN: ?Func@?$ThunkFunc3@VSharedObject@fl_net@Classes@AS3@GFx@Scaleform@@$0A@V?$SPtr@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@AEBV856@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493b70
// MS2-PIN: ?Func@?$ThunkFunc4@VSharedObject@fl_net@Classes@AS3@GFx@Scaleform@@$00V?$SPtr@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@AEBV856@AEBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142493ce0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494270
// MS2-PIN: ?Func@?$ThunkFunc1@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494320
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494470
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424944d0
// MS2-PIN: ?Func@?$ThunkFunc1@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494540
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$04K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424945b0
// MS2-PIN: ?Func@?$ThunkFunc1@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494610
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$06VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494680
// MS2-PIN: ?Func@?$ThunkFunc1@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424946f0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$08VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424947f0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494860
// MS2-PIN: ?Func@?$ThunkFunc3@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@AEBVASString@56@_NAEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424948c0
// MS2-PIN: ?Func@?$ThunkFunc2@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494ad0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494af0
// MS2-PIN: ?Func@?$ThunkFunc2@VNetConnection@fl_net@Instances@AS3@GFx@Scaleform@@$0O@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142494b10
// MS2-PIN: ?Func@?$ThunkFunc5@VURLLoader@fl_net@Instances@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@AEBVASString@56@AEBV7456@_NJ_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142495170
// MS2-PIN: ?Func@?$ThunkFunc0@VURLLoader@fl_net@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142495410
// MS2-PIN: ?Func@?$ThunkFunc1@VURLLoader@fl_net@Instances@AS3@GFx@Scaleform@@$01$$CBVValue@456@PEAVURLRequest@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142495430
