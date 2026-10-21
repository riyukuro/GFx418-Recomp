// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423ff040-0x1424133c0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x14240c4e0: Instances::fl::Array::AS3pop
template struct ThunkFunc0<Instances::fl::Array, 3, Value>;
// thunk 0x14240c500: Instances::fl::Array::AS3reverse
template struct ThunkFunc0<Instances::fl::Array, 5, SPtr<Instances::fl::Array>>;
// thunk 0x14240c5b0: Instances::fl::Array::AS3shift
template struct ThunkFunc0<Instances::fl::Array, 7, Value>;
// thunk 0x14240c5d0: Instances::fl::Date::AS3toString
template struct ThunkFunc0<Instances::fl::Date, 2, ASString>;
// thunk 0x14240c640: Instances::fl::Date::AS3toDateString
template struct ThunkFunc0<Instances::fl::Date, 3, ASString>;
// thunk 0x14240c6b0: Instances::fl::Date::AS3toTimeString
template struct ThunkFunc0<Instances::fl::Date, 4, ASString>;
// thunk 0x14240c720: Instances::fl::Date::AS3toLocaleString
template struct ThunkFunc0<Instances::fl::Date, 5, ASString>;
// thunk 0x14240c790: Instances::fl::Date::AS3toLocaleDateString
template struct ThunkFunc0<Instances::fl::Date, 6, ASString>;
// thunk 0x14240c800: Instances::fl::Date::AS3toLocaleTimeString
template struct ThunkFunc0<Instances::fl::Date, 7, ASString>;
// thunk 0x14240c870: Instances::fl::Date::AS3toUTCString
template struct ThunkFunc0<Instances::fl::Date, 8, ASString>;
// thunk 0x14240c8e0: Instances::fl::Date::AS3getUTCFullYear
template struct ThunkFunc0<Instances::fl::Date, 9, Value::Number>;
// thunk 0x14240c950: Instances::fl::Date::AS3getUTCMonth
template struct ThunkFunc0<Instances::fl::Date, 10, Value::Number>;
// thunk 0x14240c9c0: Instances::fl::Date::AS3getUTCMilliseconds
template struct ThunkFunc0<Instances::fl::Date, 16, Value::Number>;
// thunk 0x14240ca30: Instances::fl::Date::AS3getFullYear
template struct ThunkFunc0<Instances::fl::Date, 17, Value::Number>;
// thunk 0x14240caa0: Instances::fl::Date::AS3getMonth
template struct ThunkFunc0<Instances::fl::Date, 18, Value::Number>;
// thunk 0x14240cb10: Instances::fl::Date::AS3getDate
template struct ThunkFunc0<Instances::fl::Date, 19, Value::Number>;
// thunk 0x14240cb80: Instances::fl::Date::AS3getDay
template struct ThunkFunc0<Instances::fl::Date, 20, Value::Number>;
// thunk 0x14240cbf0: Instances::fl::Date::AS3getHours
template struct ThunkFunc0<Instances::fl::Date, 21, Value::Number>;
// thunk 0x14240cc60: Instances::fl::Date::AS3getMinutes
template struct ThunkFunc0<Instances::fl::Date, 22, Value::Number>;
// thunk 0x14240ccd0: Instances::fl::Date::AS3getSeconds
template struct ThunkFunc0<Instances::fl::Date, 23, Value::Number>;
// thunk 0x14240cd40: Instances::fl::Date::AS3getMilliseconds
template struct ThunkFunc0<Instances::fl::Date, 24, Value::Number>;
// thunk 0x14240cdb0: Instances::fl::Date::AS3getTimezoneOffset
template struct ThunkFunc0<Instances::fl::Date, 25, Value::Number>;
// thunk 0x14240ce20: Instances::fl::Date::AS3getTime
template struct ThunkFunc0<Instances::fl::Date, 26, Value::Number>;
// thunk 0x14240ce90: Instances::fl::Date::fullYearGet
template struct ThunkFunc0<Instances::fl::Date, 41, Value::Number>;
// thunk 0x14240cf00: Instances::fl::Date::monthGet
template struct ThunkFunc0<Instances::fl::Date, 43, Value::Number>;
// thunk 0x14240cf70: Instances::fl::Date::dateGet
template struct ThunkFunc0<Instances::fl::Date, 45, Value::Number>;
// thunk 0x14240cfe0: Instances::fl::Date::hoursGet
template struct ThunkFunc0<Instances::fl::Date, 47, Value::Number>;
// thunk 0x14240d050: Instances::fl::Date::minutesGet
template struct ThunkFunc0<Instances::fl::Date, 49, Value::Number>;
// thunk 0x14240d0c0: Instances::fl::Date::secondsGet
template struct ThunkFunc0<Instances::fl::Date, 51, Value::Number>;
// thunk 0x14240d130: Instances::fl::Date::millisecondsGet
template struct ThunkFunc0<Instances::fl::Date, 53, Value::Number>;
// thunk 0x14240d1a0: Instances::fl::Date::fullYearUTCGet
template struct ThunkFunc0<Instances::fl::Date, 55, Value::Number>;
// thunk 0x14240d210: Instances::fl::Date::monthUTCGet
template struct ThunkFunc0<Instances::fl::Date, 57, Value::Number>;
// thunk 0x14240d280: Instances::fl::Date::dateUTCGet
template struct ThunkFunc0<Instances::fl::Date, 59, Value::Number>;
// thunk 0x14240d2f0: Instances::fl::Date::hoursUTCGet
template struct ThunkFunc0<Instances::fl::Date, 61, Value::Number>;
// thunk 0x14240d360: Instances::fl::Date::minutesUTCGet
template struct ThunkFunc0<Instances::fl::Date, 63, Value::Number>;
// thunk 0x14240d3d0: Instances::fl::Date::secondsUTCGet
template struct ThunkFunc0<Instances::fl::Date, 65, Value::Number>;
// thunk 0x14240d440: Instances::fl::Date::millisecondsUTCGet
template struct ThunkFunc0<Instances::fl::Date, 67, Value::Number>;
// thunk 0x14240d4b0: Instances::fl::Date::timeGet
template struct ThunkFunc0<Instances::fl::Date, 69, Value::Number>;
// thunk 0x14240d520: Instances::fl::Date::timezoneOffsetGet
template struct ThunkFunc0<Instances::fl::Date, 71, Value::Number>;
// thunk 0x14240d590: Instances::fl::Date::dayGet
template struct ThunkFunc0<Instances::fl::Date, 72, Value::Number>;
// thunk 0x14240d600: Instances::fl::Date::dayUTCGet
template struct ThunkFunc0<Instances::fl::Date, 73, Value::Number>;
// thunk 0x14240d670: Instances::fl::Date::AS3getUTCDate
template struct ThunkFunc0<Instances::fl::Date, 11, Value::Number>;
// thunk 0x14240d6e0: Instances::fl::Date::AS3getUTCDay
template struct ThunkFunc0<Instances::fl::Date, 12, Value::Number>;
// thunk 0x14240d750: Instances::fl::Date::AS3getUTCHours
template struct ThunkFunc0<Instances::fl::Date, 13, Value::Number>;
// thunk 0x14240d7c0: Instances::fl::Date::AS3getUTCMinutes
template struct ThunkFunc0<Instances::fl::Date, 14, Value::Number>;
// thunk 0x14240d830: Instances::fl::Date::AS3getUTCSeconds
template struct ThunkFunc0<Instances::fl::Date, 15, Value::Number>;
// thunk 0x14240d8a0: Instances::FunctionBase::lengthGet
template struct ThunkFunc0<Instances::FunctionBase, 2, UInt32>;
// thunk 0x14240d900: Instances::fl::GlobalObjectCPP::getTimer
template struct ThunkFunc0<Instances::fl::GlobalObjectCPP, 20, SInt32>;
// thunk 0x14240d960: Instances::fl::QName::AS3toString
template struct ThunkFunc0<Instances::fl::QName, 3, ASString>;
// thunk 0x14240d9d0: Classes::fl::XML::settings
template struct ThunkFunc0<Classes::fl::XML, 1, SPtr<Instances::fl::Object>>;
// thunk 0x14240da80: Classes::fl::XML::AS3defaultSettings
template struct ThunkFunc0<Classes::fl::XML, 4, SPtr<Instances::fl::Object>>;
// thunk 0x14240db30: Classes::fl::XML::defaultSettings
template struct ThunkFunc0<Classes::fl::XML, 5, SPtr<Instances::fl::Object>>;
// thunk 0x14240dbe0: Instances::fl::XML::AS3attributes
template struct ThunkFunc0<Instances::fl::XML, 8, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240dc90: Instances::fl::XML::AS3childIndex
template struct ThunkFunc0<Instances::fl::XML, 10, SInt32>;
// thunk 0x14240dcf0: Instances::fl::XML::AS3hasComplexContent
template struct ThunkFunc0<Instances::fl::XML, 17, bool>;
// thunk 0x14240dd50: Instances::fl::XML::AS3hasSimpleContent
template struct ThunkFunc0<Instances::fl::XML, 18, bool>;
// thunk 0x14240ddb0: Instances::fl::XML::AS3inScopeNamespaces
template struct ThunkFunc0<Instances::fl::XML, 19, SPtr<Instances::fl::Array>>;
// thunk 0x14240de60: Instances::fl::XML::AS3length
template struct ThunkFunc0<Instances::fl::XML, 22, SInt32>;
// thunk 0x14240dec0: Instances::fl::XML::AS3localName
template struct ThunkFunc0<Instances::fl::XML, 23, ASString>;
// thunk 0x14240df30: Instances::fl::XML::AS3name
template struct ThunkFunc0<Instances::fl::XML, 24, SPtr<Instances::fl::QName>>;
// thunk 0x14240dfe0: Instances::fl::XML::AS3namespaceDeclarations
template struct ThunkFunc0<Instances::fl::XML, 26, SPtr<Instances::fl::Array>>;
// thunk 0x14240e090: Instances::fl::XML::AS3nodeKind
template struct ThunkFunc0<Instances::fl::XML, 27, ASString>;
// thunk 0x14240e100: Instances::fl::XML::AS3normalize
template struct ThunkFunc0<Instances::fl::XML, 28, SPtr<Instances::fl::XML>>;
// thunk 0x14240e1b0: Instances::fl::XML::AS3parent
template struct ThunkFunc0<Instances::fl::XML, 29, Value>;
// thunk 0x14240e1d0: Instances::fl::XML::AS3text
template struct ThunkFunc0<Instances::fl::XML, 38, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240e280: Instances::fl::XML::AS3toXMLString
template struct ThunkFunc0<Instances::fl::XML, 39, ASString>;
// thunk 0x14240e2f0: Instances::fl::XML::AS3valueOf
template struct ThunkFunc0<Instances::fl::XML, 40, SPtr<Instances::fl::XML>>;
// thunk 0x14240e3a0: Instances::fl::XML::AS3children
template struct ThunkFunc0<Instances::fl::XML, 11, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240e450: Instances::fl::XML::AS3comments
template struct ThunkFunc0<Instances::fl::XML, 12, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240e500: Instances::fl::XML::AS3copy
template struct ThunkFunc0<Instances::fl::XML, 14, SPtr<Instances::fl::XML>>;
// thunk 0x14240e5b0: Instances::fl::XMLList::AS3toString
template struct ThunkFunc0<Instances::fl::XMLList, 3, ASString>;
// thunk 0x14240e620: Instances::fl::XMLList::AS3valueOf
template struct ThunkFunc0<Instances::fl::XMLList, 4, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240e6d0: Instances::fl::XMLList::AS3attributes
template struct ThunkFunc0<Instances::fl::XMLList, 8, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240e780: Instances::fl::XMLList::AS3children
template struct ThunkFunc0<Instances::fl::XMLList, 10, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240e830: Instances::fl::XMLList::AS3hasComplexContent
template struct ThunkFunc0<Instances::fl::XMLList, 16, bool>;
// thunk 0x14240e890: Instances::fl::XMLList::AS3hasSimpleContent
template struct ThunkFunc0<Instances::fl::XMLList, 17, bool>;
// thunk 0x14240e8f0: Instances::fl::XMLList::AS3name
template struct ThunkFunc0<Instances::fl::XMLList, 18, SPtr<Instances::fl::QName>>;
// thunk 0x14240e9a0: Instances::fl::XMLList::AS3normalize
template struct ThunkFunc0<Instances::fl::XMLList, 19, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240ea50: Instances::fl::XMLList::AS3parent
template struct ThunkFunc0<Instances::fl::XMLList, 20, Value>;
// thunk 0x14240ea70: Instances::fl::XMLList::AS3text
template struct ThunkFunc0<Instances::fl::XMLList, 22, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240eb20: Instances::fl::XMLList::AS3toXMLString
template struct ThunkFunc0<Instances::fl::XMLList, 23, ASString>;
// thunk 0x14240eb90: Instances::fl::XMLList::AS3childIndex
template struct ThunkFunc0<Instances::fl::XMLList, 26, SInt32>;
// thunk 0x14240ebf0: Instances::fl::XMLList::AS3inScopeNamespaces
template struct ThunkFunc0<Instances::fl::XMLList, 27, SPtr<Instances::fl::Array>>;
// thunk 0x14240eca0: Instances::fl::XMLList::AS3nodeKind
template struct ThunkFunc0<Instances::fl::XMLList, 30, ASString>;
// thunk 0x14240ed10: Instances::fl::XMLList::AS3localName
template struct ThunkFunc0<Instances::fl::XMLList, 32, ASString>;
// thunk 0x14240ed80: Instances::fl::XMLList::AS3namespaceDeclarations
template struct ThunkFunc0<Instances::fl::XMLList, 33, SPtr<Instances::fl::Array>>;
// thunk 0x14240ee30: Instances::fl::XMLList::AS3comments
template struct ThunkFunc0<Instances::fl::XMLList, 11, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240eee0: Instances::fl::XMLList::AS3copy
template struct ThunkFunc0<Instances::fl::XMLList, 13, SPtr<Instances::fl::XMLList>>;
// thunk 0x14240ef90: Instances::fl::Date::AS3setTime
template struct ThunkFunc1<Instances::fl::Date, 1, Value::Number, Value::Number>;
// thunk 0x14240f070: Instances::fl::Date::fullYearSet
template struct ThunkFunc1<Instances::fl::Date, 42, const Value, Value::Number>;
// thunk 0x14240f100: Instances::fl::Date::monthSet
template struct ThunkFunc1<Instances::fl::Date, 44, const Value, Value::Number>;
// thunk 0x14240f190: Instances::fl::Date::dateSet
template struct ThunkFunc1<Instances::fl::Date, 46, const Value, Value::Number>;
// thunk 0x14240f220: Instances::fl::Date::hoursSet
template struct ThunkFunc1<Instances::fl::Date, 48, const Value, Value::Number>;
// thunk 0x14240f2b0: Instances::fl::Date::minutesSet
template struct ThunkFunc1<Instances::fl::Date, 50, const Value, Value::Number>;
// thunk 0x14240f340: Instances::fl::Date::secondsSet
template struct ThunkFunc1<Instances::fl::Date, 52, const Value, Value::Number>;
// thunk 0x14240f3d0: Instances::fl::Date::millisecondsSet
template struct ThunkFunc1<Instances::fl::Date, 54, const Value, Value::Number>;
// thunk 0x14240f460: Instances::fl::Date::fullYearUTCSet
template struct ThunkFunc1<Instances::fl::Date, 56, const Value, Value::Number>;
// thunk 0x14240f4f0: Instances::fl::Date::monthUTCSet
template struct ThunkFunc1<Instances::fl::Date, 58, const Value, Value::Number>;
// thunk 0x14240f580: Instances::fl::Date::dateUTCSet
template struct ThunkFunc1<Instances::fl::Date, 60, const Value, Value::Number>;
// thunk 0x14240f610: Instances::fl::Date::hoursUTCSet
template struct ThunkFunc1<Instances::fl::Date, 62, const Value, Value::Number>;
// thunk 0x14240f6a0: Instances::fl::Date::minutesUTCSet
template struct ThunkFunc1<Instances::fl::Date, 64, const Value, Value::Number>;
// thunk 0x14240f730: Instances::fl::Date::secondsUTCSet
template struct ThunkFunc1<Instances::fl::Date, 66, const Value, Value::Number>;
// thunk 0x14240f7c0: Instances::fl::Date::millisecondsUTCSet
template struct ThunkFunc1<Instances::fl::Date, 68, const Value, Value::Number>;
// thunk 0x14240f850: Instances::fl::Date::timeSet
template struct ThunkFunc1<Instances::fl::Date, 70, const Value, Value::Number>;
// thunk 0x14240f8e0: Instances::fl::GlobalObjectCPP::decodeURI
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 0, ASString, const ASString&>;
// thunk 0x14240fa20: Instances::fl::GlobalObjectCPP::decodeURIComponent
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 1, ASString, const ASString&>;
// thunk 0x14240fb60: Instances::fl::GlobalObjectCPP::encodeURI
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 2, ASString, const ASString&>;
// thunk 0x14240fca0: Instances::fl::GlobalObjectCPP::encodeURIComponent
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 3, ASString, const ASString&>;
// thunk 0x14240fde0: Instances::fl::GlobalObjectCPP::isNaN
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 4, bool, Value::Number>;
// thunk 0x14240feb0: Instances::fl::GlobalObjectCPP::isFinite
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 5, bool, Value::Number>;
// thunk 0x14240ff80: Instances::fl::GlobalObjectCPP::parseFloat
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 7, Value::Number, const ASString&>;
// thunk 0x1424100c0: Instances::fl::GlobalObjectCPP::isXMLName
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 10, bool, const Value&>;
// thunk 0x142410230: Instances::fl::GlobalObjectCPP::clearInterval
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 13, const Value, UInt32>;
// thunk 0x1424102a0: Instances::fl::GlobalObjectCPP::clearTimeout
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 14, const Value, UInt32>;
// thunk 0x142410310: Instances::fl::GlobalObjectCPP::describeType
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 15, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x1424104d0: Instances::fl::GlobalObjectCPP::escapeMultiByte
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 16, ASString, const ASString&>;
// thunk 0x142410610: Instances::fl::GlobalObjectCPP::getDefinitionByName
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 17, Value, const ASString&>;
// thunk 0x142410710: Instances::fl::GlobalObjectCPP::getQualifiedClassName
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 18, ASString, const Value&>;
// thunk 0x142410890: Instances::fl::GlobalObjectCPP::getQualifiedSuperclassName
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 19, Value, const Value&>;
// thunk 0x1424109e0: Instances::fl::GlobalObjectCPP::unescapeMultiByte
template struct ThunkFunc1<Instances::fl::GlobalObjectCPP, 23, ASString, const ASString&>;
// thunk 0x142410b20: Instances::fl::RegExp::AS3test
template struct ThunkFunc1<Instances::fl::RegExp, 9, bool, const ASString&>;
// thunk 0x142410c60: Classes::fl::XML::AS3setSettings
template struct ThunkFunc1<Classes::fl::XML, 2, const Value, const Value&>;
// thunk 0x142410db0: Classes::fl::XML::setSettings
template struct ThunkFunc1<Classes::fl::XML, 3, const Value, const Value&>;
// thunk 0x142410f00: Instances::fl::XML::AS3hasOwnProperty
template struct ThunkFunc1<Instances::fl::XML, 3, bool, const ASString&>;
// thunk 0x142411040: Instances::fl::XML::AS3addNamespace
template struct ThunkFunc1<Instances::fl::XML, 5, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x142411200: Instances::fl::XML::AS3appendChild
template struct ThunkFunc1<Instances::fl::XML, 6, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x1424113c0: Instances::fl::XML::AS3attribute
template struct ThunkFunc1<Instances::fl::XML, 7, SPtr<Instances::fl::XMLList>, const Value&>;
// thunk 0x142411580: Instances::fl::XML::AS3child
template struct ThunkFunc1<Instances::fl::XML, 9, SPtr<Instances::fl::XMLList>, const Value&>;
// thunk 0x142411740: Instances::fl::XML::AS3prependChild
template struct ThunkFunc1<Instances::fl::XML, 31, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x142411900: Instances::fl::XML::AS3removeNamespace
template struct ThunkFunc1<Instances::fl::XML, 32, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x142411ac0: Instances::fl::XML::AS3setChildren
template struct ThunkFunc1<Instances::fl::XML, 34, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x142411c80: Instances::fl::XML::AS3setLocalName
template struct ThunkFunc1<Instances::fl::XML, 35, const Value, const Value&>;
// thunk 0x142411dd0: Instances::fl::XML::AS3setName
template struct ThunkFunc1<Instances::fl::XML, 36, const Value, const Value&>;
// thunk 0x142411f20: Instances::fl::XML::AS3setNamespace
template struct ThunkFunc1<Instances::fl::XML, 37, const Value, const Value&>;
// thunk 0x142412070: Instances::fl::XML::AS3contains
template struct ThunkFunc1<Instances::fl::XML, 13, bool, const Value&>;
// thunk 0x1424121e0: Instances::fl::XMLList::AS3attribute
template struct ThunkFunc1<Instances::fl::XMLList, 7, SPtr<Instances::fl::XMLList>, const Value&>;
// thunk 0x1424123a0: Instances::fl::XMLList::AS3child
template struct ThunkFunc1<Instances::fl::XMLList, 9, SPtr<Instances::fl::XMLList>, const Value&>;
// thunk 0x142412560: Instances::fl::XMLList::AS3addNamespace
template struct ThunkFunc1<Instances::fl::XMLList, 24, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x142412720: Instances::fl::XMLList::AS3appendChild
template struct ThunkFunc1<Instances::fl::XMLList, 25, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x1424128e0: Instances::fl::XMLList::AS3prependChild
template struct ThunkFunc1<Instances::fl::XMLList, 34, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x142412aa0: Instances::fl::XMLList::AS3removeNamespace
template struct ThunkFunc1<Instances::fl::XMLList, 35, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x142412c60: Instances::fl::XMLList::AS3setChildren
template struct ThunkFunc1<Instances::fl::XMLList, 37, SPtr<Instances::fl::XML>, const Value&>;
// thunk 0x142412e20: Instances::fl::XMLList::AS3setLocalName
template struct ThunkFunc1<Instances::fl::XMLList, 38, const Value, const Value&>;
// thunk 0x142412f70: Instances::fl::XMLList::AS3setName
template struct ThunkFunc1<Instances::fl::XMLList, 39, const Value, const Value&>;
// thunk 0x1424130c0: Instances::fl::XMLList::AS3setNamespace
template struct ThunkFunc1<Instances::fl::XMLList, 40, const Value, const Value&>;
// thunk 0x142413210: Instances::fl::XMLList::AS3contains
template struct ThunkFunc1<Instances::fl::XMLList, 12, bool, const Value&>;
// thunk 0x142413380: Instances::fl::Array::AS3push
template struct ThunkFunc2<Instances::fl::Array, 4, Value, unsigned, const Value*>;
// thunk 0x1424133a0: Instances::fl::Array::AS3concat
template struct ThunkFunc2<Instances::fl::Array, 6, Value, unsigned, const Value*>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc0@VArray@fl@Instances@AS3@GFx@Scaleform@@$02VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c4e0
// MS2-PIN: ?Func@?$ThunkFunc0@VArray@fl@Instances@AS3@GFx@Scaleform@@$04V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c500
// MS2-PIN: ?Func@?$ThunkFunc0@VArray@fl@Instances@AS3@GFx@Scaleform@@$06VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c5b0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$01VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c5d0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c640
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c6b0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c720
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$05VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c790
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$06VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c800
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$07VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c870
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$08N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c8e0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$09N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c950
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BA@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240c9c0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BB@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ca30
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BC@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240caa0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BD@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cb10
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BE@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cb80
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BF@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cbf0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BG@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cc60
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BH@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ccd0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BI@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cd40
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BJ@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cdb0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BK@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ce20
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CJ@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ce90
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CL@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cf00
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CN@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cf70
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CP@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240cfe0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DB@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d050
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DD@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d0c0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DF@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d130
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DH@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d1a0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DJ@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d210
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DL@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d280
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DN@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d2f0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DP@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d360
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EB@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d3d0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0ED@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d440
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EF@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d4b0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EH@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d520
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EI@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d590
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EJ@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d600
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0L@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d670
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0M@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d6e0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0N@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d750
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0O@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d7c0
// MS2-PIN: ?Func@?$ThunkFunc0@VDate@fl@Instances@AS3@GFx@Scaleform@@$0P@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d830
// MS2-PIN: ?Func@?$ThunkFunc0@VFunctionBase@Instances@AS3@GFx@Scaleform@@$01K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d8a0
// MS2-PIN: ?Func@?$ThunkFunc0@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BE@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d900
// MS2-PIN: ?Func@?$ThunkFunc0@VQName@fl@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d960
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Classes@AS3@GFx@Scaleform@@$00V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240d9d0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Classes@AS3@GFx@Scaleform@@$03V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240da80
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Classes@AS3@GFx@Scaleform@@$04V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240db30
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240dbe0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$09J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240dc90
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BB@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240dcf0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BC@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240dd50
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ddb0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BG@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240de60
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BH@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240dec0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BI@V?$SPtr@VQName@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240df30
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BK@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240dfe0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BL@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e090
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BM@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e100
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BN@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e1b0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CG@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e1d0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CH@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e280
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CI@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e2f0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0L@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e3a0
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e450
// MS2-PIN: ?Func@?$ThunkFunc0@VXML@fl@Instances@AS3@GFx@Scaleform@@$0O@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e500
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e5b0
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e620
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e6d0
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$09V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e780
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BA@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e830
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BB@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e890
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BC@V?$SPtr@VQName@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e8f0
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BD@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240e9a0
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ea50
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BG@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ea70
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BH@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240eb20
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BK@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240eb90
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BL@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ebf0
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BO@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240eca0
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CA@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ed10
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CB@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ed80
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0L@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ee30
// MS2-PIN: ?Func@?$ThunkFunc0@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0N@V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240eee0
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$00NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ef90
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CK@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f070
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CM@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f100
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CO@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f190
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DA@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f220
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DC@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f2b0
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DE@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f340
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DG@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f3d0
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DI@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f460
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DK@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f4f0
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DM@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f580
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0DO@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f610
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EA@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f6a0
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EC@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f730
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EE@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f7c0
// MS2-PIN: ?Func@?$ThunkFunc1@VDate@fl@Instances@AS3@GFx@Scaleform@@$0EG@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f850
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240f8e0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$00VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240fa20
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$01VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240fb60
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$02VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240fca0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$03_NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240fde0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$04_NN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240feb0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$06NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14240ff80
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$09_NAEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424100c0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410230
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424102a0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0P@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410310
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BA@VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424104d0
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BB@VValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410610
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BC@VASString@56@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410710
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BD@VValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410890
// MS2-PIN: ?Func@?$ThunkFunc1@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BH@VASString@56@AEBV756@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424109e0
// MS2-PIN: ?Func@?$ThunkFunc1@VRegExp@fl@Instances@AS3@GFx@Scaleform@@$08_NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410b20
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410c60
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Classes@AS3@GFx@Scaleform@@$02$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410db0
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$02_NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142410f00
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$04V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411040
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$05V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411200
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$06V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424113c0
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$08V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411580
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BP@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411740
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CA@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411900
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CC@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411ac0
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CD@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411c80
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CE@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411dd0
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CF@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142411f20
// MS2-PIN: ?Func@?$ThunkFunc1@VXML@fl@Instances@AS3@GFx@Scaleform@@$0N@_NAEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142412070
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$06V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424121e0
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$08V?$SPtr@VXMLList@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424123a0
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BI@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142412560
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BJ@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142412720
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CC@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424128e0
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CD@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142412aa0
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CF@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142412c60
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CG@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142412e20
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CH@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142412f70
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CI@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424130c0
// MS2-PIN: ?Func@?$ThunkFunc1@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0M@_NAEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413210
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$03VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413380
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$05VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424133a0
