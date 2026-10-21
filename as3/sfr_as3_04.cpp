// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_04
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424133c0-0x14242a640 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// Instances::fl::Array::AS3slice argument 1 default
template <> struct ThunkMethodDefault<Instances::fl::Array, 8, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0xffffff; }
};
// thunk 0x1424133c0: Instances::fl::Array::AS3slice
template struct ThunkFunc2<Instances::fl::Array, 8, SPtr<Instances::fl::Array>, SInt32, SInt32>;
// thunk 0x142413510: Instances::fl::Array::AS3unshift
template struct ThunkFunc2<Instances::fl::Array, 9, Value, unsigned, const Value*>;
// thunk 0x142413530: Instances::fl::Array::AS3splice
template struct ThunkFunc2<Instances::fl::Array, 10, Value, unsigned, const Value*>;
// thunk 0x142413550: Instances::fl::Array::AS3filter
template struct ThunkFunc2<Instances::fl::Array, 16, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x1424136c0: Instances::fl::Array::AS3forEach
template struct ThunkFunc2<Instances::fl::Array, 17, const Value, const Value&, const Value&>;
// thunk 0x1424137a0: Instances::fl::Array::AS3map
template struct ThunkFunc2<Instances::fl::Array, 18, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x142413910: Instances::fl::Array::AS3some
template struct ThunkFunc2<Instances::fl::Array, 19, bool, const Value&, const Value&>;
// thunk 0x142413a30: Instances::fl::Array::AS3sort
template struct ThunkFunc2<Instances::fl::Array, 11, Value, unsigned, const Value*>;
// thunk 0x142413a50: Instances::fl::Array::AS3sortOn
template struct ThunkFunc2<Instances::fl::Array, 12, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x142413bc0: Instances::fl::Array::AS3indexOf
template struct ThunkFunc2<Instances::fl::Array, 13, SInt32, const Value&, SInt32>;
// Instances::fl::Array::AS3lastIndexOf argument 1 default
template <> struct ThunkMethodDefault<Instances::fl::Array, 14, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0x7fffffff; }
};
// thunk 0x142413d70: Instances::fl::Array::AS3lastIndexOf
template struct ThunkFunc2<Instances::fl::Array, 14, SInt32, const Value&, SInt32>;
// thunk 0x142413f20: Instances::fl::Array::AS3every
template struct ThunkFunc2<Instances::fl::Array, 15, bool, const Value&, const Value&>;
// thunk 0x142414040: Instances::fl::Date::AS3setFullYear
template struct ThunkFunc2<Instances::fl::Date, 27, Value, unsigned, const Value*>;
// thunk 0x142414060: Instances::fl::Date::AS3setMonth
template struct ThunkFunc2<Instances::fl::Date, 28, Value, unsigned, const Value*>;
// thunk 0x142414080: Instances::fl::Date::AS3setDate
template struct ThunkFunc2<Instances::fl::Date, 29, Value, unsigned, const Value*>;
// thunk 0x1424140a0: Instances::fl::Date::AS3setHours
template struct ThunkFunc2<Instances::fl::Date, 30, Value, unsigned, const Value*>;
// thunk 0x1424140c0: Instances::fl::Date::AS3setMinutes
template struct ThunkFunc2<Instances::fl::Date, 31, Value, unsigned, const Value*>;
// thunk 0x1424140e0: Instances::fl::Date::AS3setSeconds
template struct ThunkFunc2<Instances::fl::Date, 32, Value, unsigned, const Value*>;
// thunk 0x142414100: Instances::fl::Date::AS3setMilliseconds
template struct ThunkFunc2<Instances::fl::Date, 33, Value, unsigned, const Value*>;
// thunk 0x142414120: Instances::fl::Date::AS3setUTCFullYear
template struct ThunkFunc2<Instances::fl::Date, 34, Value, unsigned, const Value*>;
// thunk 0x142414140: Instances::fl::Date::AS3setUTCMonth
template struct ThunkFunc2<Instances::fl::Date, 35, Value, unsigned, const Value*>;
// thunk 0x142414160: Instances::fl::Date::AS3setUTCDate
template struct ThunkFunc2<Instances::fl::Date, 36, Value, unsigned, const Value*>;
// thunk 0x142414180: Instances::fl::Date::AS3setUTCHours
template struct ThunkFunc2<Instances::fl::Date, 37, Value, unsigned, const Value*>;
// thunk 0x1424141a0: Instances::fl::Date::AS3setUTCMinutes
template struct ThunkFunc2<Instances::fl::Date, 38, Value, unsigned, const Value*>;
// thunk 0x1424141c0: Instances::fl::Date::AS3setUTCSeconds
template struct ThunkFunc2<Instances::fl::Date, 39, Value, unsigned, const Value*>;
// thunk 0x1424141e0: Instances::fl::Date::AS3setUTCMilliseconds
template struct ThunkFunc2<Instances::fl::Date, 40, Value, unsigned, const Value*>;
// thunk 0x142414200: Instances::fl::GlobalObjectCPP::parseInt
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 6, Value, unsigned, const Value*>;
// thunk 0x142414220: Instances::fl::GlobalObjectCPP::escape
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 8, Value, unsigned, const Value*>;
// thunk 0x142414240: Instances::fl::GlobalObjectCPP::unescape
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 9, Value, unsigned, const Value*>;
// thunk 0x142414260: Instances::fl::GlobalObjectCPP::trace
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 11, Value, unsigned, const Value*>;
// thunk 0x142414280: Instances::fl::GlobalObjectCPP::print
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 12, Value, unsigned, const Value*>;
// thunk 0x1424142a0: Instances::fl::GlobalObjectCPP::fscommand
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 30, Value, unsigned, const Value*>;
// thunk 0x1424142c0: Instances::fl::GlobalObjectCPP::setInterval
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 21, Value, unsigned, const Value*>;
// thunk 0x1424142e0: Instances::fl::GlobalObjectCPP::setTimeout
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 22, Value, unsigned, const Value*>;
// thunk 0x142414300: Classes::fl::String::fromCharCode
template struct ThunkFunc2<Classes::fl::String, 1, Value, unsigned, const Value*>;
// thunk 0x142414320: Instances::fl::XML::AS3propertyIsEnumerable
template struct ThunkFunc2<Instances::fl::XML, 4, Value, unsigned, const Value*>;
// thunk 0x142414340: Instances::fl::XML::AS3elements
template struct ThunkFunc2<Instances::fl::XML, 16, Value, unsigned, const Value*>;
// thunk 0x142414360: Instances::fl::XML::AS3insertChildAfter
template struct ThunkFunc2<Instances::fl::XML, 20, Value, const Value&, const Value&>;
// thunk 0x142414440: Instances::fl::XML::AS3insertChildBefore
template struct ThunkFunc2<Instances::fl::XML, 21, Value, const Value&, const Value&>;
// thunk 0x142414520: Instances::fl::XML::AS3namespace_
template struct ThunkFunc2<Instances::fl::XML, 25, Value, unsigned, const Value*>;
// thunk 0x142414540: Instances::fl::XML::AS3processingInstructions
template struct ThunkFunc2<Instances::fl::XML, 30, Value, unsigned, const Value*>;
// thunk 0x142414560: Instances::fl::XML::AS3replace
template struct ThunkFunc2<Instances::fl::XML, 33, SPtr<Instances::fl::XML>, const Value&, const Value&>;
// thunk 0x1424146d0: Instances::fl::XML::AS3descendants
template struct ThunkFunc2<Instances::fl::XML, 15, Value, unsigned, const Value*>;
// thunk 0x1424146f0: Instances::fl::XMLList::AS3propertyIsEnumerable
template struct ThunkFunc2<Instances::fl::XMLList, 6, Value, unsigned, const Value*>;
// thunk 0x142414710: Instances::fl::XMLList::AS3processingInstructions
template struct ThunkFunc2<Instances::fl::XMLList, 21, Value, unsigned, const Value*>;
// thunk 0x142414730: Instances::fl::XMLList::AS3insertChildAfter
template struct ThunkFunc2<Instances::fl::XMLList, 28, Value, const Value&, const Value&>;
// thunk 0x142414810: Instances::fl::XMLList::AS3insertChildBefore
template struct ThunkFunc2<Instances::fl::XMLList, 29, Value, const Value&, const Value&>;
// thunk 0x1424148f0: Instances::fl::XMLList::AS3namespace_
template struct ThunkFunc2<Instances::fl::XMLList, 31, Value, unsigned, const Value*>;
// thunk 0x142414910: Instances::fl::XMLList::AS3replace
template struct ThunkFunc2<Instances::fl::XMLList, 36, SPtr<Instances::fl::XML>, const Value&, const Value&>;
// thunk 0x142414a80: Instances::fl::XMLList::AS3descendants
template struct ThunkFunc2<Instances::fl::XMLList, 14, Value, unsigned, const Value*>;
// thunk 0x142414aa0: Instances::fl::XMLList::AS3elements
template struct ThunkFunc2<Instances::fl::XMLList, 15, Value, unsigned, const Value*>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424133c0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$08VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413510
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$09VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413530
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413550
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424136c0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BC@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424137a0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BD@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413910
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0L@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413a30
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413a50
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0N@JAEBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413bc0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0O@JAEBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413d70
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0P@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413f20
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BL@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414040
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BM@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414060
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BN@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414080
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140a0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BP@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140c0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CA@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140e0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CB@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414100
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CC@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414120
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CD@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414140
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414160
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414180
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CG@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141a0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CH@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141c0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CI@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141e0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$05VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414200
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$07VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414220
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$08VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414240
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0L@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414260
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414280
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142a0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142c0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BG@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142e0
// MS2-PIN: ?Func@?$ThunkFunc2@VString@fl@Classes@AS3@GFx@Scaleform@@$00VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414300
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$03VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414320
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BA@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414340
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414360
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414440
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BJ@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414520
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414540
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CB@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414560
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0P@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424146d0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$05VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424146f0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414710
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BM@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414730
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BN@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414810
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BP@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424148f0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CE@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414910
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0O@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414a80
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0P@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414aa0
