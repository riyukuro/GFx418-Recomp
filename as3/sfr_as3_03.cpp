// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423ff040-0x1424133c0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_e4x.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include <windows.h>
#include <sys/timeb.h>
#undef GetObject

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

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl
{
    // @0x1423ff040
    void Date::AS3setUTCDate(Value& result, unsigned argc, const Value* argv)
    {
        applyDateArgs(result, argc, argv, Date_Day, 0.0);
    }

    // @0x1423ff060
    void Date::AS3setUTCFullYear(Value& result, unsigned argc, const Value* argv)
    {
        applyDateArgs(result, argc, argv, Date_Year, 0.0);
    }

    // @0x1423ff080
    void Date::AS3setUTCHours(Value& result, unsigned argc, const Value* argv)
    {
        applyTimeArgs(result, argc, argv, Time_Hour, 0.0);
    }

    // @0x1423ff0a0
    void Date::AS3setUTCMilliseconds(Value& result, unsigned argc, const Value* argv)
    {
        applyTimeArgs(result, argc, argv, Time_Ms, 0.0);
    }

    // @0x1423ff0c0
    void Date::AS3setUTCMinutes(Value& result, unsigned argc, const Value* argv)
    {
        applyTimeArgs(result, argc, argv, Time_Minute, 0.0);
    }

    // @0x1423ff0e0
    void Date::AS3setUTCMonth(Value& result, unsigned argc, const Value* argv)
    {
        applyDateArgs(result, argc, argv, Date_Month, 0.0);
    }

    // @0x1423ff100
    void Date::AS3setUTCSeconds(Value& result, unsigned argc, const Value* argv)
    {
        applyTimeArgs(result, argc, argv, Time_Second, 0.0);
    }

    // MS2-FUNCTIONAL: the exe tail-calls RefCountBaseGC::ReleaseInternal from the SPtr release
    // @0x142401860
    void RegExp::AS3test(bool& result, const ASString& str)
    {
        SPtr<Instances::fl::Object> r;
        AS3exec(r, str);
        result = r.GetPtr() != NULL;
    }

    // @0x142401ae0
    void Date::AS3toDateString(ASString& result)
    {
        char buffer[128];
        const UPInt len = formatDateTimeString(buffer, sizeof(buffer), TimeValue, LocalTZA, true, false);
        result = GetVM().GetStringManager().CreateString(buffer, len);
    }

    // @0x142403050
    void Date::AS3toTimeString(ASString& result)
    {
        char buffer[128];
        const UPInt len = formatDateTimeString(buffer, sizeof(buffer), TimeValue, LocalTZA, false, true);
        result = GetVM().GetStringManager().CreateString(buffer, len);
    }

    // @0x142403110
    void Date::AS3toUTCString(ASString& result)
    {
        char buffer[128];
        const UPInt len = formatDateTimeString(buffer, sizeof(buffer), TimeValue, 0, true, true, true);
        result = GetVM().GetStringManager().CreateString(buffer, len);
    }

    // @0x1424036f0
    void Array::AS3unshift(Value& result, unsigned argc, const Value* argv)
    {
        SA.Insert(0, argc, argv);
        result.SetUInt32(static_cast<UInt32>(SA.GetSize()));
    }

    // @0x142403820
    void QName::AS3valueOf(SPtr<Instances::fl::QName>& result)
    {
        result = this;
    }

    // @0x142403960
    void XML::AS3valueOf(SPtr<Instances::fl::XML>& result)
    {
        result = this;
    }

    // @0x1424039c0
    void XMLList::AS3valueOf(SPtr<Instances::fl::XMLList>& result)
    {
        result = this;
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

// VM::GetValueTraits: the traits of a value (0x14250ffc0).
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes { namespace fl
{
    // @0x142407120
    void Boolean::Construct(Value& _this, unsigned argc, const Value* argv, bool /*extCall*/)
    {
        if (argc > 0)
            _this.SetBool(argv[0].Convert2Boolean());
        else
            _this.SetBool(false);
    }

    // @0x1424059b0
    void Math::Call(const Value& /*_this*/, Value& /*result*/, unsigned /*argc*/, const Value* const /*argv*/)
    {
        VM& vm = GetVM();
        vm.ThrowTypeError(VM::Error(VM::eMathNotFunctionError, vm));
    }

    // @0x1424072f0
    void Math::Construct(Value& /*_this*/, unsigned /*argc*/, const Value* /*argv*/, bool /*extCall*/)
    {
        VM& vm = GetVM();
        vm.ThrowTypeError(VM::Error(VM::eMathNotConstructorError, vm));
    }

    // @0x142407480
    void Number::Construct(Value& _this, unsigned argc, const Value* argv, bool /*extCall*/)
    {
        if (argc == 0)
        {
            _this.SetNumber(0.0);
            return;
        }
        if (argc == 1)
        {
            Value::Number v;
            if (argv[0].Convert2Number(v))
                _this.SetNumber(v);
        }
        else
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "Number::Construct", 0, 1, argc));
        }
    }

    // @0x1424076a0
    void QName::Construct(Value& _this, unsigned argc, const Value* argv, bool extCall)
    {
        if (argc == 1)
        {
            const Traits& tr = FUN_14250ffc0(GetVM(), argv[0]);
            if (tr.GetTraitsType() == Traits_QName && tr.IsInstanceTraits())
            {
                _this = argv[0];
                return;
            }
        }
        Class::Construct(_this, argc, argv, extCall);
    }

    // @0x142407730
    void String::Construct(Value& _this, unsigned argc, const Value* argv, bool /*extCall*/)
    {
        ASString r = GetVM().GetStringManager().CreateEmptyString();
        if (argc > 0)
        {
            if (!argv[0].Convert2String(r))
                return;
        }
        _this = r;
    }

    // @0x142407bf0
    void XMLList::Construct(Value& _this, unsigned argc, const Value* argv, bool extCall)
    {
        if (argc == 1)
        {
            const Traits& tr = FUN_14250ffc0(GetVM(), argv[0]);
            if (tr.GetTraitsType() == Traits_XMLList && tr.IsInstanceTraits())
            {
                _this = argv[0];
                return;
            }
        }
        Class::Construct(_this, argc, argv, extCall);
    }

    // @0x142405b00
    void XML::Call(const Value& /*_this*/, Value& result, unsigned argc, const Value* const argv)
    {
        if (argc > 0)
        {
            const Traits& tr = FUN_14250ffc0(GetVM(), argv[0]);
            if (tr.IsInstanceTraits() && tr.GetTraitsType() == Traits_XML)
            {
                result = argv[0];
                return;
            }
        }
        Construct(result, argc, argv);
    }

    // @0x142407c80
    void int_::Construct(Value& _this, unsigned argc, const Value* argv, bool /*extCall*/)
    {
        if (argc > 0)
        {
            SInt32 v;
            if (argv[0].Convert2Int32(v))
                _this.SetSInt32(v);
        }
        else
            _this.SetSInt32(0);
    }

    // @0x142407d30
    void uint::Construct(Value& _this, unsigned argc, const Value* argv, bool /*extCall*/)
    {
        if (argc > 0)
        {
            UInt32 v;
            if (argv[0].Convert2UInt32(v))
                _this.SetUInt32(v);
        }
        else
            _this.SetUInt32(0);
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

// SF_ECMA_dtostr: shortest round-trip ECMA-262 decimal form of val into buffer, returns its length.
Scaleform::UPInt FUN_142525f20(char* buffer, int bufflen, double val);

// Out-of-line Traits::GetConstructor (InitOnDemand when the class is not built yet).
Scaleform::GFx::AS3::Class& FUN_142508460(const Scaleform::GFx::AS3::Traits* t);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace ClassTraits { namespace fl
{
    // @0x1424060c0
    bool Boolean::Coerce(const Value& value, Value& result) const
    {
        result.SetBool(value.Convert2Boolean());
        return true;
    }

    // @0x1424061b0
    bool Namespace::Coerce(const Value& value, Value& result) const
    {
        FUN_142508460(&GetInstanceTraits()).Construct(result, 1, &value);
        return !GetVM().IsException();
    }

    // @0x142406220
    bool String::Coerce(const Value& value, Value& result) const
    {
        if (value.IsNullOrUndefined())
        {
            result.Assign((ASStringNode*)NULL);
        }
        else
        {
            ASString r = GetVM().GetStringManager().CreateEmptyString();
            if (!value.Convert2String(r))
                return false;
            result = r;
        }
        return true;
    }

    // @0x142406360
    bool Number::CoerceValue(const Value& value, Value& result) const
    {
        Value::Number r;
        if (value.Convert2Number(r))
        {
            result.SetNumber(r);
            return true;
        }
        return false;
    }

    // @0x1424063e0
    bool int_::CoerceValue(const Value& value, Value& result) const
    {
        SInt32 r;
        if (value.Convert2Int32(r))
        {
            result.SetSInt32(r);
            return true;
        }
        return false;
    }

    // @0x142406460
    bool uint::CoerceValue(const Value& value, Value& result) const
    {
        UInt32 r;
        if (value.Convert2UInt32(r))
        {
            result.SetUInt32(r);
            return true;
        }
        return false;
    }
}} // namespace ClassTraits::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

namespace InstanceTraits { namespace fl
{
    // @0x142403750
    void Boolean::AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsBool())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result = _this;
    }

    // @0x142402710
    void Number::AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        UInt32 radix = 10;
        if (!_this.IsNumber())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        if (argc > 0 && !argv[0].IsUndefined())
        {
            if (!argv[0].Convert2UInt32(radix))
                return;
            if (radix < 2 || radix > 36)
                return vm.ThrowRangeError(VM::Error(VM::eInvalidRadixError, vm, radix));
        }
        const Value::Number num = _this.AsNumber();
        if (radix != 10 && !_this.IsNaNOrInfinity())
        {
            SInt32 v;
            if (!_this.Convert2Int32(v))
                return;
            LongFormatter f(v);
            f.SetBase(radix).SetBigLetters(false).Convert();
            const StringDataPtr s = f.GetResult();
            result = vm.GetStringManager().CreateString(s.ToCStr(), s.GetSize());
        }
        else
        {
            char buffer[40];
            const UPInt len = FUN_142525f20(buffer, sizeof(buffer), num);
            result = vm.GetStringManager().CreateString(buffer, len);
        }
    }

    // Shared body of int/uint toString: the value in the given radix (2..16).
    #define MS2_AS3_INT_TOSTRING(value) \
        if (!_this.IsInt() && !_this.IsUInt()) \
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm)); \
        UInt32 radix = 10; \
        if (argc > 0 && !argv[0].IsUndefined()) \
        { \
            if (!argv[0].Convert2UInt32(radix)) \
                return; \
            if (radix < 2 || radix > 16) \
                return vm.ThrowRangeError(VM::Error(VM::eInvalidRadixError, vm, radix)); \
        } \
        LongFormatter f(value); \
        f.SetBase(radix).SetBigLetters(false).Convert(); \
        const StringDataPtr s = f.GetResult(); \
        result = vm.GetStringManager().CreateString(s.ToCStr(), s.GetSize())

    // @0x142402d50
    void int_::AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_INT_TOSTRING(static_cast<SInt32>(_this.AsInt()));
    }

    // @0x142402ed0
    void uint::AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        MS2_AS3_INT_TOSTRING(static_cast<UInt32>(_this.AsUInt()));
    }

    #undef MS2_AS3_INT_TOSTRING

    // Shared body of toFixed/toPrecision: format v with the given type and precision into result.
    #define MS2_AS3_FORMAT_DOUBLE(v, type, prec) \
        DoubleFormatter f(v); \
        f.SetType(DoubleFormatter::type).SetPrecision(prec).Convert(); \
        result = vm.GetStringManager().CreateString(f.GetResult().ToCStr(), f.GetSize())

    // @0x142401ba0
    void Number::AS3toFixed(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        UInt32 digits = 0;
        if (argc > 0 && !argv[0].Convert2UInt32(digits))
            return;
        if (digits > 20)
            return vm.ThrowRangeError(VM::Error(VM::eInvalidPrecisionError, vm));
        MS2_AS3_FORMAT_DOUBLE(_this.AsNumber(), FmtDecimal, digits);
    }

    // @0x142402180
    void Number::AS3toPrecision(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        UInt32 precision = 0;
        if (argc > 0 && !argv[0].Convert2UInt32(precision))
            return;
        if (precision == 0 || precision > 21)
            return vm.ThrowRangeError(VM::Error(VM::eInvalidPrecisionError, vm));
        MS2_AS3_FORMAT_DOUBLE(_this.AsNumber(), FmtSignificant, precision);
    }

    // @0x1424037c0
    void Number::AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsNumber())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result = _this;
    }

    // @0x142401d00
    void int_::AS3toFixed(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        UInt32 digits = 0;
        if (argc > 0 && !argv[0].Convert2UInt32(digits))
            return;
        if (digits > 20)
            return vm.ThrowRangeError(VM::Error(VM::eInvalidPrecisionError, vm));
        MS2_AS3_FORMAT_DOUBLE(_this.AsInt(), FmtDecimal, digits);
    }

    // @0x1424022e0
    void int_::AS3toPrecision(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        UInt32 precision = 0;
        if (argc > 0 && !argv[0].Convert2UInt32(precision))
            return;
        if (precision == 0 || precision > 21)
            return vm.ThrowRangeError(VM::Error(VM::eInvalidPrecisionError, vm));
        MS2_AS3_FORMAT_DOUBLE(_this.AsInt(), FmtSignificant, precision);
    }

    // @0x142403a20
    void int_::AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsInt() && !_this.IsUInt())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result.SetSInt32(_this.AsInt());
    }

    // @0x142401e60
    void uint::AS3toFixed(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        UInt32 digits = 0;
        if (argc > 0 && !argv[0].Convert2UInt32(digits))
            return;
        if (digits > 20)
            return vm.ThrowRangeError(VM::Error(VM::eInvalidPrecisionError, vm));
        MS2_AS3_FORMAT_DOUBLE(_this.AsUInt(), FmtDecimal, digits);
    }

    // @0x142402440
    void uint::AS3toPrecision(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        UInt32 precision = 0;
        if (argc > 0 && !argv[0].Convert2UInt32(precision))
            return;
        if (precision == 0 || precision > 21)
            return vm.ThrowRangeError(VM::Error(VM::eInvalidPrecisionError, vm));
        MS2_AS3_FORMAT_DOUBLE(_this.AsUInt(), FmtSignificant, precision);
    }

    // @0x142403ac0
    void uint::AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsInt() && !_this.IsUInt())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result.SetUInt32(_this.AsUInt());
    }

    #undef MS2_AS3_FORMAT_DOUBLE
}} // namespace InstanceTraits::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

namespace InstanceTraits { namespace fl
{
    // The [start, start + length) part of str, clamped to the string; a negative length means "to the end".
    static SF_INLINE ASString StringSubstring(StringManager& sm, const ASString& str, SInt32 start, SInt32 length)
    {
        if (length == 0)
            return sm.CreateEmptyString();
        if (start < 0)
            start = 0;
        const SInt32 len = (SInt32)str.GetLength();
        if (start >= len)
            return sm.CreateEmptyString();
        if (length < 0 || start + length > len)
            length = len - start;
        return ASString(str.SubstringNode(start, start + length));
    }

    // @0x1423ff660
    void String::AS3slice(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str))
            return;
        if (argc == 0)
        {
            result = str;
            return;
        }

        const SInt32 len = (SInt32)str.GetLength();
        SInt32 start = 0;
        SInt32 end = 0x7fffffff;
        Value::Number startNum, endNum;
        if (argc >= 1)
        {
            if (!argv[0].Convert2Number(startNum))
                return;
            start = (startNum > len) ? len : (SInt32)startNum;
            if (start < 0)
                start += len;
        }
        if (argc >= 2)
        {
            if (!argv[1].Convert2Number(endNum))
                return;
            end = (endNum > len) ? len : (SInt32)endNum;
            if (end < 0)
                end += len;
            if (end < start)
            {
                result = sm.CreateEmptyString();
                return;
            }
        }
        result = ASString(str.SubstringNode(start, end));
    }

    // @0x1424013f0
    void String::AS3substr(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str))
            return;

        Value::Number startNum, lengthNum;
        SInt32 start = 0;
        SInt32 length = -1;
        const unsigned len = str.GetLength();
        if (argc >= 1)
        {
            if (!argv[0].Convert2Number(startNum))
                return;
            start = (startNum > len) ? (SInt32)len : (SInt32)startNum;
            if (start < 0)
                start += len;
        }
        if (argc >= 2)
        {
            if (!argv[1].Convert2Number(lengthNum))
                return;
            length = (lengthNum > len) ? (SInt32)len : (SInt32)lengthNum;
            // Unlike substring, a negative length gives the empty string.
            if (length < 0)
                length = 0;
        }
        result = StringSubstring(sm, str, start, length);
    }

    // @0x1424015b0
    void String::AS3substring(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        StringManager& sm = vm.GetStringManager();
        ASString str = sm.CreateEmptyString();
        if (!_this.Convert2String(str))
            return;

        const unsigned len = str.GetLength();
        Value::Number startNum = 0;
        Value::Number endNum = 0x7fffffff;
        if (argc >= 1 && !argv[0].Convert2Number(startNum))
            return;
        if (argc >= 2 && !argv[1].Convert2Number(endNum))
            return;

        const Value vs(startNum);
        if (vs.IsNaN())
            startNum = NumberUtil::NEGATIVE_INFINITY();
        const Value ve(endNum);
        if (ve.IsNaN())
            endNum = NumberUtil::NEGATIVE_INFINITY();

        if (endNum == startNum)
        {
            result = sm.CreateEmptyString();
            return;
        }

        SInt32 start = (startNum > len) ? (SInt32)len : (SInt32)startNum;
        SInt32 end = (endNum > len) ? (SInt32)len : (SInt32)endNum;
        if (end < start)
            Alg::Swap(start, end);
        if (start < 0)
            start = 0;
        result = StringSubstring(sm, str, start, end - start);
    }
}} // namespace InstanceTraits::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes { namespace fl
{
    // @0x142405670
    void Date::Call(const Value& _this, Value& result, unsigned argc, const Value* const argv)
    {
        Value::Number timeValue;
        SInt32 localTZA;
        char buffer[128];
        {
            // Instances::fl::Date::GetCurrentTimeValue, inlined.
            __timeb64 tb;
            TIME_ZONE_INFORMATION tzi;
            _ftime64(&tb);
            GetTimeZoneInformation(&tzi);
            localTZA = tzi.Bias * -60000;
            timeValue = static_cast<Value::Number>(tb.time) * 1000.0 + tb.millitm;
        }
        const UPInt len = Instances::fl::Date::formatDateTimeString(buffer, sizeof(buffer), timeValue, localTZA, true, true, false);
        result = GetVM().GetStringManager().CreateString(buffer, len);
    }

    // @0x142405a80
    void RegExp::Call(const Value& _this, Value& result, unsigned argc, const Value* const argv)
    {
        Construct(result, argc, argv);
        Instances::fl::RegExp* re = static_cast<Instances::fl::RegExp*>(result.GetObject());
        result = re->ToString();
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl
{
    // @0x142408710
    Value::Number Date::DayFromYear(Value::Number year)
    {
        return ::floor((year - 1969.0) * 0.25) + (year - 1970.0) * 365.0 - ::floor((year - 1901.0) / 100.0) +
               ::floor((year - 1601.0) / 400.0);
    }

    // @0x1424085c0
    SInt32 Date::DateFromTime(Value::Number t)
    {
        const Value::Number year = YearFromTime(t);
        SInt32 day = static_cast<SInt32>(::floor(t / 86400000.0) - DayFromYear(year));
        const SInt32 y = static_cast<SInt32>(year);
        const bool leap = (y % 4) == 0 && ((y % 100) != 0 || (y % 400) == 0);
        const SInt32 month = MonthFromYearDay(y, day);
        ++day;
        if (month > 0)
            day -= Months[leap ? 1 : 0][month - 1];
        return day;
    }
}}}}}

// HashSetBase<HashNode<UPInt, Value>>::GetAlt<UPInt>, out of line in the exe; returns the node (key, then value).
const Scaleform::HashNode<Scaleform::UPInt, Scaleform::GFx::AS3::Value, Scaleform::FixedSizeHash<Scaleform::UPInt> >*
FUN_1423e87e0(const void* hash, const Scaleform::UPInt* key);

namespace Scaleform { namespace GFx { namespace AS3
{
    // HashDH<UPInt, Value>::Get with the exe's out-of-line GetAlt.
    static SF_INLINE const Value* SparseHashGet(const HashDH<UPInt, Value>& h, const UPInt& key)
    {
        const HashNode<UPInt, Value, FixedSizeHash<UPInt> >* p = FUN_1423e87e0(&h, &key);
        return p ? &p->Second : 0;
    }

    // MS2-FUNCTIONAL: exe keeps the node->value null select as a cmove before the test; ours folds it into the branch
    // @0x142405480
    const Value& SparseArray::At(UPInt ind) const
    {
        if (ind < ValueA.GetSize())
            return ValueA[ind];
        if (ind >= ValueHLowInd && ind <= ValueHHighInd)
        {
            const Value* v = SparseHashGet(ValueH, ind);
            if (v)
                return *v;
        }
        return DefaultValue;
    }

    // @0x1424051b0
    void SparseArray::Assign(const SparseArray& other)
    {
        if (this != &other)
        {
            Length = other.Length;
            ValueHLowInd = other.ValueHLowInd;
            ValueHHighInd = other.ValueHHighInd;
            ValueH = other.ValueH;
            ValueA = other.ValueA;
        }
    }

    // MS2-FUNCTIONAL: the exe calls ArrayDataDH::Append (0x142404330) out of line; ours inlines it
    // @0x1424046c0
    void SparseArray::Append(const ValueArrayDH& x)
    {
        const UPInt size = x.GetSize();
        if (Length == ValueA.GetSize())
        {
            ValueA.Append(x);
            Length = ValueA.GetSize();
        }
        else
        {
            for (UPInt i = 0; i < size; ++i)
            {
                ValueHHighInd = Length;
                ValueH.Set(ValueHHighInd, x[i]);
                ++Length;
            }
        }
    }

    // @0x1424048a0
    void SparseArray::Append(const ValueArray& x, UPInt ind, UPInt num)
    {
        const UPInt sizeX = x.GetSize();
        if (Length == ValueA.GetSize())
        {
            for (UPInt i = 0; i < num && (ind + i) < sizeX; ++i)
                ValueA.PushBack(x[ind + i]);
            Length = ValueA.GetSize();
        }
        else
        {
            for (UPInt i = 0; i < num && (ind + i) < sizeX; ++i)
            {
                ValueHHighInd = Length;
                ValueH.Set(ValueHHighInd, x[ind + i]);
                ++Length;
            }
        }
    }

    // MS2-FUNCTIONAL: the inlined SparseArray::At keeps the hash-node null select as a cmove in the exe; ours branches
    // @0x1424043e0
    void SparseArray::Append(const SparseArray& other, UPInt ind, UPInt num)
    {
        const UPInt sizeO = other.GetSize();
        if (Length == ValueA.GetSize())
        {
            for (UPInt i = 0; i < num && (ind + i) < sizeO; ++i)
                ValueA.PushBack(other.At(ind + i));
            Length = ValueA.GetSize();
        }
        else
        {
            for (UPInt i = 0; i < num && (ind + i) < sizeO; ++i)
            {
                ValueHHighInd = Length;
                ValueH.Set(ValueHHighInd, other.At(ind + i));
                ++Length;
            }
        }
    }

    // @0x142404b20
    void SparseArray::Append(unsigned argc, const Value* argv)
    {
        if (Length == ValueA.GetSize())
        {
            for (unsigned i = 0; i < argc; ++i)
                ValueA.PushBack(argv[i]);
            Length = ValueA.GetSize();
        }
        else
        {
            for (unsigned i = 0; i < argc; ++i)
            {
                ValueHHighInd = Length;
                ValueH.Set(ValueHHighInd, argv[i]);
                ++Length;
            }
        }
    }

    // @0x14240b510
    void SparseArray::ForEach(ArrayFunc& f) const
    {
        const UPInt sizeA = ValueA.GetSize();
        for (UInt32 i = 0; i < sizeA; ++i)
            f(i, ValueA[i]);

        HashDH<UPInt, Value>::ConstIterator it = ValueH.Begin();
        while (!it.IsEnd())
        {
            f(static_cast<UInt32>(it->First), it->Second);
            ++it;
        }
    }
}}}

namespace Scaleform { namespace GFx { namespace AS3
{
    // MS2-FUNCTIONAL: exe reads CaseInsensitive before the Desc branch (register/scheduling only)
    // @0x1424066d0
    int CompareAsString::Compare(const ASString& a, const ASString& b) const
    {
        if (UseLocale)
        {
            const bool ci = CaseInsensitive;
            if (Desc)
                return b.LocaleCompare_CaseCheck(a.ToCStr(), a.GetLength(), !ci);
            return a.LocaleCompare_CaseCheck(b.ToCStr(), b.GetLength(), !ci);
        }

        int r;
        if (CaseInsensitive)
            r = String::CompareNoCase(a.ToCStr(), b.ToCStr());
        else
            r = strcmp(a.ToCStr(), b.ToCStr());
        return Desc ? -r : r;
    }

    namespace InstanceTraits { namespace fl
    {
        // MS2-FUNCTIONAL: loop register allocation and shrink-wrapping differ
        // @0x142407090
        SInt32 String::Compare(ASString& l, ASString& r)
        {
            SInt32 diff = 0;
            if (l == r)
                return 0;

            const char* lp = l.ToCStr();
            const char* rp = r.ToCStr();
            UInt32 lc = UTF8Util::DecodeNextChar(&lp);
            UInt32 rc = UTF8Util::DecodeNextChar(&rp);
            while (lc != 0 && rc != 0)
            {
                diff = rc - lc;
                if (diff != 0)
                    return diff;
                lc = UTF8Util::DecodeNextChar(&lp);
                rc = UTF8Util::DecodeNextChar(&rp);
            }
            if (lc != rc)
                diff = rc == 0 ? -1 : 1;
            return diff;
        }
    }}
}}}

// ---- Array.sort: the elements are collected (as numbers, strings or element pointers), sorted, then copied back
namespace Scaleform {
// A sort key and the index of the element it came from (same as sfr_as3_20).
template <typename F, typename S>
struct Pair
{
    Pair(const F& f, const S& s) : First(f), Second(s) {}

    F First;
    S Second;
};
}

namespace Scaleform { namespace GFx { namespace AS3
{
    // A sort key, the element and its index.
    template <typename T1, typename T2, typename T3>
    struct Triple : public Pair<T1, T2>
    {
        Triple(const T1& f, const T2& s, const T3& t) : Pair<T1, T2>(f, s), Third(t) {}

        T3 Third;
    };

    typedef Triple<ASString, const Value*, UInt32>      StringValueTriple;
    typedef Triple<Value::Number, const Value*, UInt32> NumberValueTriple;
    typedef Pair<const Value*, UInt32>                  ValuePtrPair;

    // Array.sort option bits.
    enum
    {
        SortFlags_CaseInsensitive    = 0x1,
        SortFlags_Descending         = 0x2,
        SortFlags_UniqueSort         = 0x4,
        SortFlags_ReturnIndexedArray = 0x8,
        SortFlags_Numeric            = 0x10,
        SortFlags_Locale             = 0x400
    };

    // numeric ordering of the keys. 1 byte, passed by value.
    class CompareAsNumber
    {
    public:
        CompareAsNumber(bool desc) : Desc(desc) {}

        bool operator()(const NumberValueTriple& a, const NumberValueTriple& b) const
        {
            if (Desc)
                return b.First < a.First;
            return a.First < b.First;
        }
        bool Equal(const NumberValueTriple& a, const NumberValueTriple& b) const { return a.First == b.First; }

    private:
        CompareAsNumber& operator=(const CompareAsNumber&);

        const bool Desc;
    };

    // string ordering of the keys, by CompareAsString::Compare.
    class CompareAsStringTriple
    {
    public:
        CompareAsStringTriple(const CompareAsString& c) : Cmp(c) {}

        bool operator()(const StringValueTriple& a, const StringValueTriple& b) const { return Cmp.Compare(a.First, b.First) < 0; }
        bool Equal(const StringValueTriple& a, const StringValueTriple& b) const { return Cmp.Compare(a.First, b.First) == 0; }

    private:
        CompareAsStringTriple& operator=(const CompareAsStringTriple&);

        CompareAsString Cmp;
    };

    // ordering by a script compare function. 0x10 bytes: the VM and the function (no descending flag in 4.1).
    class CompareValuePtr
    {
    public:
        CompareValuePtr(VM& vm, const Value& f) : Vm(vm), Func(f) {}

        bool operator()(const ValuePtrPair& a, const ValuePtrPair& b) const { return Compare(*a.First, *b.First) < 0; }
        bool Equal(const ValuePtrPair& a, const ValuePtrPair& b) const { return Compare(*a.First, *b.First) == 0; }

        int Compare(const Value& a, const Value& b) const;

    private:
        CompareValuePtr& operator=(const CompareValuePtr&);

        VM&          Vm;
        const Value& Func;
    };

    // The collectors' operator() bodies lie in sfr_as3_02's range (0x1423f1ec0/0x1423f1d70/0x1423f1cb0); they are
    // defined here until that unit is written. vftables 0x143141580/0x143141590/0x1431415a0.
    class ValuePtrCollector : public ArrayFunc
    {
    public:
        ValuePtrCollector(ArrayDH<ValuePtrPair>& p) : Pairs(p) {}

        virtual void operator()(UInt32 ind, const Value& v) { Pairs.PushBack(ValuePtrPair(&v, ind)); }

    private:
        ValuePtrCollector& operator=(const ValuePtrCollector&);

        ArrayDH<ValuePtrPair>& Pairs;
    };

    class Value2StrCollector : public ArrayFunc
    {
    public:
        Value2StrCollector(VM& vm, ArrayDH<StringValueTriple>& p) : Vm(vm), Pairs(p) {}

        virtual void operator()(UInt32 ind, const Value& v)
        {
            ASString str = Vm.GetStringManager().CreateEmptyString();
            if (!v.Convert2String(str))
                return;
            Pairs.PushBack(StringValueTriple(str, &v, ind));
        }

    private:
        Value2StrCollector& operator=(const Value2StrCollector&);

        VM&                         Vm;
        ArrayDH<StringValueTriple>& Pairs;
    };

    class Value2NumberCollector : public ArrayFunc
    {
    public:
        Value2NumberCollector(ArrayDH<NumberValueTriple>& p) : Pairs(p) {}

        virtual void operator()(UInt32 ind, const Value& v)
        {
            Value::Number num;
            if (!v.Convert2Number(num))
                return;
            Pairs.PushBack(NumberValueTriple(num, &v, ind));
        }

    private:
        Value2NumberCollector& operator=(const Value2NumberCollector&);

        ArrayDH<NumberValueTriple>& Pairs;
    };

    // SparseArray::PushBack (0x14241e4b0, sfr_as3_04), which the exe inlines into Array.sort.
    static SF_INLINE void PushBackInline(SparseArray& sa, const Value& v)
    {
        if (sa.Length == sa.ValueA.GetSize())
            sa.ValueA.PushBack(v);
        else
        {
            sa.ValueHHighInd = sa.Length;
            sa.ValueH.Set(sa.ValueHHighInd, v);
        }
        ++sa.Length;
    }

    // MS2-FUNCTIONAL: argument setup scheduling around ExecuteInternalUnsafe differs (same instructions, reordered)
    // @0x142406e70
    int CompareValuePtr::Compare(const Value& a, const Value& b) const
    {
        Value result;
        Value argv[2] = {a, b};
        VM& vm = Vm;

        vm.ExecuteInternalUnsafe(Func, Value::GetUndefined(), result, 2, argv, false);
        if (Vm.IsException())
            return 0;

        Value::Number n;
        if (!result.Convert2Number(n))
            return 0;
        if (NumberUtil::IsNEGATIVE_INFINITY(n))
            return -1;
        if (NumberUtil::IsPOSITIVE_INFINITY(n))
            return 1;
        if (NumberUtil::IsNEGATIVE_ZERO(n))
            return -1;
        if (NumberUtil::IsPOSITIVE_ZERO(n))
            return 1;
        return n == 0.0 ? 0 : (n < 0.0 ? -1 : 1);
    }

    namespace Instances { namespace fl
    {
        // MS2-FUNCTIONAL: frame 0x10 smaller and newSA/compareFunction stack slots differ; code otherwise identical
        // @0x1423ffba0
        void Array::AS3sort(Value& result, unsigned argc, const Value* argv)
        {
            Value compareFunction;
            SInt32 flags = 0;

            if (argc > 0)
            {
                if (argv[0].IsCallable())
                    compareFunction = argv[0];
                else if (!argv[0].Convert2Int32(flags))
                    return;
            }
            if (argc > 1)
                if (!argv[1].Convert2Int32(flags))
                    return;

            SparseArray newSA(GetVM().GetMemoryHeap());

            if (!compareFunction.IsNullOrUndefined())
            {
                ArrayDH<ValuePtrPair> pairs(GetVM().GetMemoryHeap());
                ValuePtrCollector vc(pairs);
                SA.ForEach(vc);

                CompareValuePtr functor(GetVM(), compareFunction);
                Alg::QuickSortSafe(pairs, functor);
                const UPInt size = pairs.GetSize();

                if (flags & SortFlags_UniqueSort)
                {
                    for (UInt32 i = 1; i < size; ++i)
                    {
                        if (functor.Equal(pairs[i - 1], pairs[i]))
                        {
                            result.SetNull();
                            return;
                        }
                    }
                }

                if (flags & SortFlags_ReturnIndexedArray)
                    for (UPInt i = 0; i < size; ++i)
                        PushBackInline(newSA, Value(pairs[i].Second));
                else
                    for (UPInt i = 0; i < size; ++i)
                        PushBackInline(newSA, *pairs[i].First);

                if (size < GetSize())
                    newSA.Resize(GetSize());
            }
            else if (flags & SortFlags_Numeric)
            {
                ArrayDH<NumberValueTriple> pairs(GetVM().GetMemoryHeap());
                Value2NumberCollector vc(pairs);
                SA.ForEach(vc);

                CompareAsNumber functor((flags & SortFlags_Descending) != 0);
                Alg::QuickSortSafe(pairs, functor);
                const UPInt size = pairs.GetSize();

                if (flags & SortFlags_UniqueSort)
                {
                    for (UInt32 i = 1; i < size; ++i)
                    {
                        if (functor.Equal(pairs[i - 1], pairs[i]))
                        {
                            result.SetNull();
                            return;
                        }
                    }
                }

                if (flags & SortFlags_ReturnIndexedArray)
                    for (UPInt i = 0; i < size; ++i)
                        PushBackInline(newSA, Value(pairs[i].Third));
                else
                    for (UPInt i = 0; i < size; ++i)
                        PushBackInline(newSA, *pairs[i].Second);

                if (size < GetSize())
                    newSA.Resize(GetSize());
            }
            else
            {
                ArrayDH<StringValueTriple> pairs(GetVM().GetMemoryHeap());
                Value2StrCollector vc(GetVM(), pairs);
                SA.ForEach(vc);

                CompareAsStringTriple functor(CompareAsString((flags & SortFlags_Descending) != 0,
                                                              (flags & SortFlags_CaseInsensitive) != 0,
                                                              (flags & SortFlags_Locale) != 0));
                Alg::QuickSortSafe(pairs, functor);
                const UPInt size = pairs.GetSize();

                if (flags & SortFlags_UniqueSort)
                {
                    for (UInt32 i = 1; i < size; ++i)
                    {
                        if (functor.Equal(pairs[i - 1], pairs[i]))
                        {
                            result.SetNull();
                            return;
                        }
                    }
                }

                if (flags & SortFlags_ReturnIndexedArray)
                    for (UPInt i = 0; i < size; ++i)
                        PushBackInline(newSA, Value(pairs[i].Third));
                else
                    for (UPInt i = 0; i < size; ++i)
                        PushBackInline(newSA, *pairs[i].Second);

                if (size < GetSize())
                    newSA.Resize(GetSize());
            }

            if (flags & SortFlags_ReturnIndexedArray)
            {
                Pickable<Instances::fl::Array> newArr = GetVM().MakeArray();
                result.Pick(newArr);
                newArr->SA.Assign(newSA);
            }
            else
            {
                SA.Assign(newSA);
                result.Assign(this);
            }
        }
    }}
}}}

namespace Scaleform { namespace GFx { namespace AS3
{
    // @0x142406120
    bool ClassTraits::ClassClass::Coerce(const Value& value, Value& result) const
    {
        result.Assign(value);
        return true;
    }

    // @0x1424057c0
    void Instances::FunctionBase::Call(const Value& _this, Value& result, unsigned argc, const Value* const argv)
    {
        Value r = Value::GetUndefined();
        ExecuteUnsafe(_this, r, argc, argv);
        r.Swap(result);
    }

    // @0x1424072a0
    void Instances::fl::GlobalObject::Construct(Value& _this, unsigned argc, const Value* argv, bool extCall)
    {
        GetVM().ThrowTypeError(VM::Error(VM::eConstructOfNonFunctionError, GetVM()));
    }
}}}

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl
{
    // @0x142402910
    void QName::AS3toString(ASString& result)
    {
        if (Ns.GetPtr() == NULL)
        {
            const String s = String("*::") + String(LocalName.ToCStr(), LocalName.GetSize());
            result.AssignNode(result.GetManager()->CreateStringNode(s.ToCStr(), s.GetSize()));
        }
        else if (Ns->GetUri().IsEmpty())
            result = LocalName;
        else
        {
            result = Ns->GetUri();
            result += "::";
            result += LocalName;
        }
    }
}}}}}

// SparseArray::PopFront and CutMultipleAt, out of line in the exe.
void FUN_142423ef0(Scaleform::GFx::AS3::SparseArray* sa);
void FUN_142408230(Scaleform::GFx::AS3::SparseArray* sa, Scaleform::UPInt pos, Scaleform::UPInt count, Scaleform::GFx::AS3::SparseArray* cut);

namespace Scaleform { namespace GFx { namespace AS3 {

// The exe inlines SparseArray::At and PushBack into the Array natives (same as sfr_as3_02).
static SF_INLINE const Value& saAt03(const SparseArray& sa, UPInt ind)
{
    if (ind < sa.ValueA.GetSize())
        return sa.ValueA[ind];
    if (ind >= sa.ValueHLowInd && ind <= sa.ValueHHighInd)
    {
        const HashNode<UPInt, Value, FixedSizeHash<UPInt> >* p = FUN_1423e87e0(&sa.ValueH, &ind);
        const Value* v = p ? &p->Second : 0;
        if (v)
            return *v;
    }
    return sa.DefaultValue;
}

static SF_INLINE void saPushBack03(SparseArray& sa, const Value& v)
{
    if (sa.Length == sa.ValueA.GetSize())
        sa.ValueA.PushBack(v);
    else
    {
        sa.ValueHHighInd = sa.Length;
        sa.ValueH.Set(sa.ValueHHighInd, v);
    }
    ++sa.Length;
}

namespace Instances { namespace fl
{
    // MS2-FUNCTIONAL: the exe keeps the inlined At's node-to-value null select as a cmove
    // @0x1423ff400
    void Array::AS3shift(Value& result)
    {
        if (SA.GetSize() == 0)
        {
            result.SetUndefined();
            return;
        }
        result = saAt03(SA, 0);
        FUN_142423ef0(&SA);
    }

    // MS2-FUNCTIONAL: the exe inlines the Array constructor and keeps the inlined At's null select as a cmove
    // @0x1423ff4d0
    void Array::AS3slice(SPtr<Instances::fl::Array>& result, SInt32 startIndex, SInt32 endIndex)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        Array* arr = new(itr.Alloc()) Array(itr);
        result = arr;
        const SInt32 len = static_cast<SInt32>(SA.GetSize());
        if (startIndex < 0)
            startIndex += len;
        if (endIndex < 0)
            endIndex += len;
        if (endIndex > len)
            endIndex = len;
        if (startIndex < 0)
            startIndex = 0;
        for (SInt32 i = startIndex; i < endIndex; ++i)
            saPushBack03(arr->SA, saAt03(SA, i));
    }

    // MS2-FUNCTIONAL: the exe keeps the inlined At's node-to-value null select as a cmove
    // @0x1423ff800
    void Array::AS3some(bool& result, const Value& callback, const Value& thisObject)
    {
        if (!callback.IsNullOrUndefined())
        {
            Value _this(thisObject.IsNullOrUndefined() ? callback : thisObject);
            for (UPInt i = 0; i < SA.GetSize(); ++i)
            {
                Value argv[3] = {saAt03(SA, i), Value(static_cast<UInt32>(i)), Value(this)};
                if (!callback.IsCallable())
                    break;
                Value r;
                GetVM().ExecuteInternalUnsafe(callback, _this, r, 3, argv, false);
                if (GetVM().IsException())
                    break;
                if (!r.IsBool() || r.AsBool())
                {
                    result = true;
                    return;
                }
            }
        }
        result = false;
    }

    // MS2-FUNCTIONAL: register allocation and the deleteCount spill differ from the exe
    // @0x142400d30
    void Array::AS3splice(Value& result, unsigned argc, const Value* argv)
    {
        SInt32 startIndex = 0;
        UInt32 deleteCount;
        if (argc > 0)
        {
            if (!argv[0].Convert2Int32(startIndex))
                return;
            if (startIndex < 0)
                startIndex += static_cast<SInt32>(SA.GetSize());
        }
        if (startIndex < 0)
            startIndex = 0;
        if (argc < 2)
            deleteCount = static_cast<UInt32>(SA.GetSize()) - startIndex;
        else if (!argv[1].Convert2UInt32(deleteCount))
            return;

        InstanceTraits::fl::Array& itr = static_cast<InstanceTraits::fl::Array&>(GetInstanceTraits());
        Pickable<Array> arr = itr.MakeInstance(itr);
        result.Pick(arr);
        FUN_142408230(&SA, startIndex, deleteCount, arr.GetPtr() ? &arr.GetPtr()->SA : NULL);

        if (argc > 2)
        {
            if (static_cast<SInt32>(SA.GetSize()) < startIndex)
                startIndex = static_cast<SInt32>(SA.GetSize());
            SA.Insert(startIndex, argc - 2, argv + 2);
        }
    }
}}
}}}

// FindObjProperty: the slot or dynamic value named mn of the object a value stands for. 0x142501b00
void FUN_142501b00(Scaleform::GFx::AS3::PropRef& result, Scaleform::GFx::AS3::VM& vm,
                   const Scaleform::GFx::AS3::Value& value, const Scaleform::GFx::AS3::Multiname& mn, int attr);

namespace Scaleform { namespace GFx { namespace AS3 {

// ---- Array.sortOn: elements ordered by one or more named properties, each with its own option bits
namespace
{
    // A property lookup that found something (same test as sfr_as3_09).
    SF_INLINE bool PropRefFound03(const PropRef& prop)
    {
        const UPInt bits = reinterpret_cast<UPInt>(prop.pValue);
        if (prop.This.GetKind() == Value::kUndefined || bits == 1)
            return false;
        return !((bits & 2) != 0 && (bits & ~UPInt(2)) == 0);
    }
}

    // The field names and their option bits. 0x18 bytes, passed by value.
    class CompareOn
    {
    public:
        CompareOn(VM& vm, const ArrayDH<Value>& names, const ArrayDH<UInt32>& flags)
            : Vm(vm), Names(names), Flags(flags) {}

        bool operator()(const ValuePtrPair& a, const ValuePtrPair& b) const { return Compare(*a.First, *b.First) < 0; }
        bool Equal(const ValuePtrPair& a, const ValuePtrPair& b) const { return Compare(*a.First, *b.First) == 0; }

        int Compare(const Value& a, const Value& b) const;

    private:
        CompareOn& operator=(const CompareOn&);

        VM&                     Vm;
        const ArrayDH<Value>&   Names;
        const ArrayDH<UInt32>&  Flags;
    };

    // The first field both elements have and that differs decides; a failed read compares equal.
    // MS2-FUNCTIONAL: the exe keeps the conversion results in flag registers and duplicates the cleanup paths
    // @0x1424067e0
    int CompareOn::Compare(const Value& a, const Value& b) const
    {
        int result = 0;
        const UPInt size = Names.GetSize();
        for (UPInt i = 0; result == 0 && i < size; ++i)
        {
            Multiname mn(Vm.GetPublicNamespace(), Names[i]);
            PropRef propA;
            PropRef propB;
            FUN_142501b00(propA, Vm, a, mn, 0);
            FUN_142501b00(propB, Vm, b, mn, 0);
            if (!PropRefFound03(propA) || !PropRefFound03(propB))
                continue;

            Value va;
            Value vb;
            if (!propA.GetSlotValueUnsafe(Vm, va) || !propB.GetSlotValueUnsafe(Vm, vb))
                return 0;

            const UInt32 flags = Flags[i];
            int r;
            if (flags & SortFlags_Numeric)
            {
                Value::Number na = 0.0;
                Value::Number nb = 0.0;
                if (!va.Convert2NumberInline(na) || !vb.Convert2NumberInline(nb))
                    return 0;
                r = static_cast<int>(na - nb);
            }
            else
            {
                ASString sb = Vm.GetStringManager().CreateEmptyString();
                ASString sa = sb;
                if (!va.Convert2String(sa) || !vb.Convert2String(sb))
                    return 0;
                const bool caseSensitive = (flags & SortFlags_CaseInsensitive) == 0;
                if (flags & SortFlags_Locale)
                    r = sa.LocaleCompare_CaseCheck(sb.ToCStr(), sb.GetLength(), caseSensitive);
                else if (caseSensitive)
                    r = strcmp(sa.ToCStr(), sb.ToCStr());
                else
                    r = String::CompareNoCase(sa.ToCStr(), sb.ToCStr());
            }
            result = (flags & SortFlags_Descending) ? -r : r;
        }
        return result;
    }

namespace Instances { namespace fl
{
    // fieldName is a name or an array of names; options is one set of option bits for all of them or an array with
    // one per name (ignored unless the lengths agree). The first name's bits decide unique / indexed-array result.
    // MS2-FUNCTIONAL: the exe inlines the collector, SparseArray::At and PushBack; stack layout differs
    // @0x142400500
    void Array::AS3sortOn(SPtr<Instances::fl::Array>& result, const Value& fieldName, const Value& options)
    {
        VM& vm = GetVM();
        ASString str = vm.GetStringManager().CreateEmptyString();
        ArrayDH<Value> names(vm.GetMemoryHeap());
        ArrayDH<UInt32> flags(vm.GetMemoryHeap());

        const Traits& ntr = FUN_14250ffc0(vm, fieldName);
        if (ntr.GetTraitsType() == Traits_Array && ntr.IsInstanceTraits())
        {
            const SparseArray& sa = static_cast<Array*>(fieldName.GetObject())->SA;
            for (UPInt i = 0; i < sa.GetSize(); ++i)
            {
                if (!saAt03(sa, i).Convert2String(str))
                    return;
                names.PushBack(Value(str));
            }
        }
        else
        {
            if (!fieldName.Convert2String(str))
                return;
            names.PushBack(Value(str));
        }

        flags.Resize(names.GetSize());
        for (UPInt i = 0; i < flags.GetSize(); ++i)
            flags[i] = 0;

        if (!options.IsNullOrUndefined())
        {
            const Traits& otr = FUN_14250ffc0(vm, options);
            if (otr.GetTraitsType() == Traits_Array && otr.IsInstanceTraits())
            {
                const SparseArray& sa = static_cast<Array*>(options.GetObject())->SA;
                if (sa.GetSize() == names.GetSize())
                {
                    for (UPInt i = 0; i < sa.GetSize() && i < flags.GetSize(); ++i)
                    {
                        UInt32 f;
                        if (!saAt03(sa, i).Convert2UInt32(f))
                            return;
                        flags[i] = f;
                    }
                }
            }
            else
            {
                UInt32 f;
                if (!options.Convert2UInt32(f))
                    return;
                for (UPInt i = 0; i < flags.GetSize(); ++i)
                    flags[i] = f;
            }
        }

        SparseArray newSA(vm.GetMemoryHeap());
        ArrayDH<ValuePtrPair> pairs(vm.GetMemoryHeap());
        ValuePtrCollector vc(pairs);
        SA.ForEach(vc);

        CompareOn functor(vm, names, flags);
        Alg::QuickSortSafe(pairs, functor);
        const UPInt size = pairs.GetSize();
        const UInt32 first = flags[0];

        if (first & SortFlags_UniqueSort)
        {
            for (UInt32 i = 1; i < size; ++i)
            {
                if (functor.Equal(pairs[i - 1], pairs[i]))
                {
                    result = NULL;
                    return;
                }
            }
        }

        if (first & SortFlags_ReturnIndexedArray)
            for (UPInt i = 0; i < size; ++i)
                saPushBack03(newSA, Value(pairs[i].Second));
        else
            for (UPInt i = 0; i < size; ++i)
                saPushBack03(newSA, *pairs[i].First);

        if (size < GetSize())
            newSA.Resize(GetSize());

        if (first & SortFlags_ReturnIndexedArray)
        {
            result = vm.MakeArray();
            result->SA.Assign(newSA);
        }
        else
        {
            SA.Assign(newSA);
            result = this;
        }
    }
}}
}}}

void FUN_142516600(Scaleform::GFx::AS3::VM& vm, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>& result);

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances { namespace fl
{
    // A new list of the text children.
    // MS2-FUNCTIONAL: the exe inlines the XMLList constructor
    // @0x1424018e0
    void XML::AS3text(SPtr<XMLList>& result)
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(
            GetVM().GetXMLSupport().GetClassTraitsXMLList()->GetInstanceTraits());
        result = itr.MakeInstance(itr);
        GetChildren(*result, kText);
    }

    // A new list (with this list's target, when it has one) of the text children of every item.
    // MS2-FUNCTIONAL: the exe inlines the XMLList constructor
    // @0x1424019b0
    void XMLList::AS3text(SPtr<XMLList>& result)
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(GetInstanceTraits());
        if (TargetNamespace && TargetObject && TargetProperty)
            result = itr.MakeInstance(itr, *TargetObject, ASString(TargetProperty), *TargetNamespace);
        else
            result = itr.MakeInstance(itr);
        for (UPInt i = 0; i < List.GetSize(); ++i)
            List[i]->GetChildren(*result, XML::kText);
    }
}}

namespace Classes { namespace fl
{
    // A new Object with the current settings.
    // MS2-FUNCTIONAL: written from behaviour
    // @0x1423ff120
    void XML::AS3settings(SPtr<Instances::fl::Object>& result)
    {
        VM& vm = GetVM();
        StringManager& sm = vm.GetStringManager();
        FUN_142516600(vm, result);
        result->AddDynamicSlotValuePair(sm.CreateConstString("ignoreComments"), Value(ignoreComments));
        result->AddDynamicSlotValuePair(sm.CreateConstString("ignoreProcessingInstructions"), Value(ignoreProcessingInstructions));
        result->AddDynamicSlotValuePair(sm.CreateConstString("ignoreWhitespace"), Value(ignoreWhitespace));
        result->AddDynamicSlotValuePair(sm.CreateConstString("prettyPrinting"), Value(prettyPrinting));
        result->AddDynamicSlotValuePair(sm.CreateConstString("prettyIndent"), Value(prettyIndent));
    }
}}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace InstanceTraits { namespace fl
{
    // @0x142401fd0
    void String::AS3toLocaleLowerCase(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        ASString str = vm.GetStringManager().CreateEmptyString();
        if (_this.Convert2String(str))
            result = ASString(str.ToLowerNode());
    }

    // @0x142402080
    void String::AS3toLocaleUpperCase(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        ASString str = vm.GetStringManager().CreateEmptyString();
        if (_this.Convert2String(str))
            result = ASString(str.ToUpperNode());
    }

    // @0x142402100
    void String::AS3toLowerCase(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        ASString str = vm.GetStringManager().CreateEmptyString();
        if (_this.Convert2String(str))
            result = ASString(str.ToLowerNode());
    }

    // @0x1424031d0
    void String::AS3toUpperCase(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        ASString str = vm.GetStringManager().CreateEmptyString();
        if (_this.Convert2String(str))
            result = ASString(str.ToUpperNode());
    }

    // MS2-FUNCTIONAL: written from behaviour
    // @0x142402a90
    void String::AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsString())
            result.Assign(_this);
        else if (_this.IsNullOrUndefined())
            vm.ThrowTypeError(VM::Error(VM::eInvalidEnumError, vm, "null", "String"));
        else
            vm.ThrowTypeError(VM::Error(VM::eInvalidEnumError, vm, FUN_14250ffc0(vm, _this).GetName().ToCStr(), "String"));
    }

    // MS2-FUNCTIONAL: written from behaviour
    // @0x142403880
    void String::AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (_this.IsString())
            result.Assign(_this);
        else if (_this.IsNullOrUndefined())
            vm.ThrowTypeError(VM::Error(VM::eInvalidEnumError, vm, "null", "String"));
        else
            vm.ThrowTypeError(VM::Error(VM::eInvalidEnumError, vm, FUN_14250ffc0(vm, _this).GetName().ToCStr(), "String"));
    }

    // @0x1424026a0
    void Namespace::AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv)
    {
        if (!_this.IsNamespace())
            return vm.ThrowTypeError(VM::Error(VM::eInvokeOnIncompatibleObjectError, vm));
        result = _this.AsNamespace().GetUri();
    }
}}

namespace Instances { namespace fl
{
    // "Invalid Date" for the prototype.
    // MS2-FUNCTIONAL: stack frame differs (exe keeps the buffer cookie layout differently)
    // @0x1424025b0
    void Date::AS3toString(ASString& result)
    {
        StringManager& sm = GetVM().GetStringManager();
        if (this == &GetTraits().GetConstructor().GetPrototype())
        {
            result = sm.CreateConstString("Invalid Date");
            return;
        }
        char buffer[128];
        const UPInt len = formatDateTimeString(buffer, sizeof(buffer), TimeValue, LocalTZA, true, true, false);
        result = sm.CreateString(buffer, len);
    }

    // @0x142402b70
    void XML::AS3toString(ASString& result)
    {
        VM& vm = GetVM();
        StringBuffer buf(vm.GetMemoryHeap());
        ToString(buf, 0);
        result = vm.GetStringManager().CreateString(buf.ToCStr(), buf.GetSize());
    }

    // Simple content: the text of every item but comments and processing instructions; else toXMLString.
    // MS2-FUNCTIONAL: stack frame differs (the exe keeps the bool result in a home slot)
    // @0x142402c20
    void XMLList::AS3toString(ASString& result)
    {
        bool simple;
        AS3hasSimpleContent(simple);
        if (!simple)
        {
            AS3toXMLString(result);
            return;
        }

        VM& vm = GetVM();
        StringBuffer buf(vm.GetMemoryHeap());
        const UPInt size = List.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            XML* x = List[i];
            const XML::Kind k = x->GetKind();
            if (k != XML::kComment && k != XML::kInstruction)
                x->ToString(buf, 0);
        }
        result = vm.GetStringManager().CreateString(buf.ToCStr(), buf.GetSize());
    }

    // @0x142403250
    void XML::AS3toXMLString(ASString& result)
    {
        VM& vm = GetVM();
        StringBuffer buf(vm.GetMemoryHeap());
        ToXMLString(buf, 0, NULL, NULL);
        result = vm.GetStringManager().CreateString(buf.ToCStr(), buf.GetSize());
    }
}}
}}}

namespace
{
    using namespace Scaleform::GFx::AS3;

    // Add the non-public namespaces of nss to na that it doesn't hold yet.
    void AddNamespaces03(NamespaceArray& na, const NamespaceArray* nss, const Instances::Namespace& pub)
    {
        if (!nss)
            return;
        const Scaleform::UPInt n = nss->Namespaces.GetSize();
        for (Scaleform::UPInt i = 0; i < n; ++i)
        {
            Instances::Namespace* ns = nss->Namespaces[i];
            if (*ns == pub)
                continue;
            Scaleform::UPInt j = 0;
            for (; j < na.Namespaces.GetSize(); ++j)
                if (*na.Namespaces[j] == *ns)
                    break;
            if (j == na.Namespaces.GetSize())
                na.Namespaces.PushBack(ns);
        }
    }
}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances { namespace fl
{
    // The items, a line each, with the namespaces in scope at the target passed down.
    // MS2-FUNCTIONAL: the exe keeps the collected namespaces in an ArrayDH; a plain-object target ends the walk
    // @0x142403310
    void XMLList::AS3toXMLString(ASString& result)
    {
        VM& vm = GetVM();
        const UPInt size = List.GetSize();
        NamespaceArray na;
        if (size)
        {
            const Instances::Namespace& pub = vm.GetPublicNamespace();
            AS3::Object* o = TargetObject;
            while (o)
            {
                if (IsXMLObject(o))
                {
                    for (XML* x = static_cast<XML*>(o); x; x = x->Parent)
                        AddNamespaces03(na, x->GetInScopeNamespaces(), pub);
                    break;
                }
                if (!IsXMLListObject(o))
                    break;
                XMLList* l = static_cast<XMLList*>(o);
                for (UPInt i = 0; i < l->List.GetSize(); ++i)
                    AddNamespaces03(na, l->List[i]->GetInScopeNamespaces(), pub);
                o = l->TargetObject;
            }
        }

        StringBuffer buf(vm.GetMemoryHeap());
        for (UPInt i = 0; i < size; ++i)
        {
            if (i)
                buf.AppendChar('\n');
            List[i]->ToXMLString(buf, 0, NULL, &na);
        }
        result = vm.GetStringManager().CreateString(buf.ToCStr(), buf.GetSize());
    }
}}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances { namespace fl
{
    // @0x142403c10
    void XMLElement::AddAttr(const Instances::Namespace& ns, const ASString& name, const ASString& value)
    {
        InstanceTraits::fl::XML& itr = static_cast<InstanceTraits::fl::XML&>(GetInstanceTraits());
        Attrs.PushBack(SPtr<XMLAttr>(itr.MakeInstanceAttr(itr, ns, name, value, this)));
    }

    // @0x142404d80
    CheckResult XMLElement::AppendChild(const Value& child)
    {
        return InsertChildAt(Children.GetSize(), child);
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line ArrayLH PushBack 0x142420060; ours inlines it
    // @0x142404db0
    void XMLElement::AppendChild(const SPtr<XML>& child)
    {
        Children.PushBack(child);
    }

    // @0x142404e90
    void XMLList::Append(const XMLList& l)
    {
        const UPInt size = l.List.GetSize();
        for (UPInt i = 0; i < size; ++i)
            List.PushBack(l.List[i]);
    }

    // @0x142404f20
    void XMLList::Append(XML* x)
    {
        List.PushBack(x);
    }
}}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
    // MS2-FUNCTIONAL: exe stores the raw pointer after an out-of-line resize 0x14241ff20; ours pushes an SPtr
    // @0x142403b60
    void NamespaceArray::Add(Instances::Namespace& ns, bool checkUnique)
    {
        if (checkUnique)
        {
            for (UPInt i = 0; i < Namespaces.GetSize(); ++i)
                if (*Namespaces[i] == ns)
                    return;
        }
        Namespaces.PushBack(SPtr<Instances::Namespace>(&ns));
    }

    // MS2-FUNCTIONAL: same push as Add, inlined into the loop
    // @0x142404230
    void NamespaceArray::AddUnique(const NamespaceArray& other)
    {
        const UPInt size = other.Namespaces.GetSize();
        for (UPInt i = 0; i < size; ++i)
            Add(*other.Namespaces[i], true);
    }
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances { namespace fl
{
    // MS2-FUNCTIONAL: exe stores the new namespace raw after an out-of-line resize 0x14241ffc0; ours pushes an SPtr
    // @0x142403ff0
    void XMLElement::AddInScopeNamespace(const Instances::Namespace& ns)
    {
        const Value& prefix = ns.GetPrefix();
        if (prefix.IsUndefined())
            return;

        const ASString p = prefix.IsString() ? prefix.AsString() : GetVM().GetStringManager().CreateEmptyString();
        if (p.IsEmpty() && Ns->GetUri().IsEmpty())
            return;

        ArrayLH<SPtr<Instances::Namespace> >& nss = Namespaces.Namespaces;
        UPInt match = SF_MAX_UPINT;
        for (UPInt i = 0; i < nss.GetSize(); ++i)
        {
            if (StrictEqual(prefix, nss[i]->GetPrefix()))
            {
                match = i;
                break;
            }
        }

        SPtr<Instances::Namespace> nns = GetVM().MakeNamespace(Abc::NS_Public, ns.GetUri(), prefix);
        if (match != SF_MAX_UPINT && nss[match]->GetUri().GetNode() != ns.GetUri().GetNode())
            nss.RemoveAt(match);
        nss.PushBack(nns);

        // the element's own and its attributes' prefixes are shadowed by the new declaration
        if (StrictEqual(Ns->GetPrefix(), prefix))
            Ns->SetPrefix(Value::GetUndefined());
        const UPInt size = Attrs.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            Instances::Namespace& ans = Attrs[i]->GetCurrNamespace();
            if (StrictEqual(ans.GetPrefix(), prefix))
                ans.SetPrefix(Value::GetUndefined());
        }
    }
}}
}}}

// ---- collector visits ----

namespace Scaleform { namespace GFx { namespace AS3 {

// Visits the collectable a value holds (0x142504530).
void ForEachChild_GC_Internal(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                              ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner);

SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const Value& v,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (v.IsGarbageCollectable() && !v.IsWeakRef())
        ForEachChild_GC_Internal(prcc, v, op, owner);
}

// The exe passes the owner as a third argument to every GcOp (r8); the shared GcOp typedef has two.
typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const ASRefCountBaseType** pchild,
                              const ASRefCountBaseType& owner);
SF_INLINE void CallGcOp(ASRefCountBaseType::GcOp op, RefCountCollector<StatMV_ActionScript_Mem>* prcc,
                        const ASRefCountBaseType** pchild, const ASRefCountBaseType& owner)
{
    reinterpret_cast<GcOpWithOwner>(op)(prcc, pchild, owner);
}

// Visits a counted pointer member.
template <class T>
SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const SPtr<T>& p,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (p.GetPtr())
        CallGcOp(op, prcc, const_cast<const ASRefCountBaseType**>((ASRefCountBaseType**)(p.GetRawPtr())), owner);
}

// Visits every item of a counted pointer array.
template <class T>
SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const ArrayLH<SPtr<T> >& a,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    const UPInt size = a.GetSize();
    for (UPInt i = 0; i < size; ++i)
        ForEachChild_GC(prcc, a[i], op, owner);
}

namespace Instances { namespace fl
{
    // @0x14240c010
    void QName::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Instance::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, Ns, op, *this);
    }

    // @0x14240c240
    void XML::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Instances::fl::Object::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, Parent, op, *this);
    }

    // @0x14240c280
    void XMLAttr::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        XML::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, Ns, op, *this);
        AS3::ForEachChild_GC(prcc, Value(Data), op, *this);
    }

    // @0x14240c340
    void XMLElement::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        XML::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, Ns, op, *this);
        AS3::ForEachChild_GC(prcc, Namespaces.Namespaces, op, *this);
        AS3::ForEachChild_GC(prcc, Attrs, op, *this);
        AS3::ForEachChild_GC(prcc, Children, op, *this);
    }

    // @0x14240c440
    void XMLList::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Instance::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, TargetObject, op, *this);
        AS3::ForEachChild_GC(prcc, TargetNamespace, op, *this);
        AS3::ForEachChild_GC(prcc, List, op, *this);
    }
}}
}}}

// Visits every value of a value array for owner (0x142503660).
void FUN_142503660(Scaleform::GFx::AS3::RefCountCollector<Scaleform::GFx::AS3::StatMV_ActionScript_Mem>* prcc,
                   const Scaleform::GFx::AS3::ValueArrayDH& a, Scaleform::GFx::AS3::ASRefCountBaseType::GcOp op,
                   const Scaleform::GFx::AS3::ASRefCountBaseType& owner);

namespace Scaleform { namespace GFx { namespace AS3 {
    // @0x14240c050
    void SparseArray::ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, ASRefCountBaseType::GcOp op,
                                      const ASRefCountBaseType& owner) const
    {
        FUN_142503660(prcc, ValueA, op, owner);
        for (HashDH<UPInt, Value>::ConstIterator it = ValueH.Begin(); !it.IsEnd(); ++it)
            AS3::ForEachChild_GC(prcc, it->Second, op, owner);
    }

namespace Instances { namespace fl
{
    // @0x14240bc90
    void Array::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Instance::ForEachChild_GC(prcc, op);
        SA.ForEachChild_GC(prcc, op, *this);
    }
}}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances
{
    // @0x14240c160
    void ThunkFunction::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        FunctionBase::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, OriginationTraits, op, *this);
    }
}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace fl { extern const char* NS_XML; }
namespace Instances { namespace fl
{
    // @0x14240b200
    Instances::Namespace* XML::FindNamespaceByPrefix(const ASString& prefix, XML* lp) const
    {
        if (Parent.GetPtr() != lp)
            return Parent->FindNamespaceByPrefix(prefix, lp);
        if (strcmp(prefix.ToCStr(), "xml") == 0)
            return GetVM().XMLNamespace.GetPtr();
        return NULL;
    }

    // @0x14240b380
    Instances::Namespace* XML::FindNamespaceByURI(const ASString& uri, XML* lp) const
    {
        if (Parent.GetPtr() != lp)
            return Parent->FindNamespaceByURI(uri, lp);
        if (strcmp(uri.ToCStr(), AS3::fl::NS_XML) == 0)
            return GetVM().XMLNamespace.GetPtr();
        return NULL;
    }

    // @0x14240b260
    Instances::Namespace* XMLElement::FindNamespaceByPrefix(const ASString& prefix, XML* lp) const
    {
        const ArrayLH<SPtr<Instances::Namespace> >& nss = Namespaces.Namespaces;
        for (UPInt i = 0; i < nss.GetSize(); ++i)
        {
            const Value& p = nss[i]->GetPrefix();
            if (p.IsString() && p.AsString() == prefix)
                return nss[i].GetPtr();
        }
        return XML::FindNamespaceByPrefix(prefix, lp);
    }

    // MS2-FUNCTIONAL: exe tail-jumps through the parent vslot; ours keeps a frame for the string compare
    // @0x14240b3e0
    Instances::Namespace* XMLElement::FindNamespaceByURI(const ASString& uri, XML* lp) const
    {
        const ArrayLH<SPtr<Instances::Namespace> >& nss = Namespaces.Namespaces;
        for (UPInt i = 0; i < nss.GetSize(); ++i)
        {
            if (nss[i]->GetUri() == uri)
                return nss[i].GetPtr();
        }
        // the exe tests the uri against the "xml" prefix here, not against NS_XML
        if (Parent.GetPtr() != lp)
            return Parent->FindNamespaceByURI(uri, lp);
        if (strcmp(uri.ToCStr(), "xml") == 0)
            return GetVM().XMLNamespace.GetPtr();
        return NULL;
    }

    // @0x14240b490
    Instances::Namespace* XMLList::FindNamespaceByURI(const ASString& uri) const
    {
        AS3::Object* obj = TargetObject.GetPtr();
        while (obj)
        {
            if (IsXMLObject(obj))
                return static_cast<XML*>(obj)->FindNamespaceByURI(uri, NULL);
            if (IsXMLListObject(obj))
            {
                XMLList* l = static_cast<XMLList*>(obj);
                Instances::Namespace* ns = l->TargetNamespace.GetPtr();
                if (ns && ns->GetUri() == uri)
                    return ns;
                obj = l->TargetObject.GetPtr();
            }
        }
        return NULL;
    }
}}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances { namespace fl
{
    // @0x14240b630
    UInt32 XMLElement::ForEachAttr(const Multiname& prop_name, CallBack& cb)
    {
        UInt32 num = 0;
        if (!prop_name.Name.IsString())
            return num;
        const UPInt size = Attrs.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            if (Attrs[i]->Matches(prop_name))
            {
                ++num;
                if (!cb.Call(i))
                    return num;
            }
        }
        return num;
    }

    // MS2-FUNCTIONAL: exe inlines XML::Matches into the loop; ours calls it
    // @0x14240b6d0
    UInt32 XMLElement::ForEachChild(const Multiname& prop_name, CallBack& cb)
    {
        UInt32 num = 0;
        const UPInt size = Children.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            if (Children[i]->Matches(prop_name))
            {
                ++num;
                if (!cb.Call(i))
                    return num;
            }
        }
        return num;
    }
}}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances { namespace fl
{
    // A found E4X node: the pointer tagged with bit 1, This the element that owns it.
    static PropRef MakeXMLPropRef(XML* node, XMLElement* owner)
    {
        PropRef r;
        r.pObject = reinterpret_cast<AS3::Object*>(reinterpret_cast<UPInt>(node) | 2);
        r.This = Value(owner);
        return r;
    }

    // MS2-FUNCTIONAL: exe inlines ForEachAttr and builds the result in place
    // @0x14240b080
    PropRef XMLElement::FindDynamicSlot(const Multiname& mn)
    {
        if (mn.IsAttr())
        {
            AttrGetFirst f(*this);
            if (ForEachAttr(mn, f) != 0)
                return MakeXMLPropRef(f.Result.GetPtr(), this);
        }
        else
        {
            ChildGetFirst f(*this);
            if (ForEachChild(mn, f) != 0)
                return MakeXMLPropRef(f.Result.GetPtr(), this);
        }
        return PropRef();
    }
}}
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances { namespace fl
{
    // MS2-FUNCTIONAL: exe pushes through the out-of-line ArrayLH resize 0x142420060 and stores raw
    // @0x142405500
    bool AttrGet::Call(UPInt ind)
    {
        List.List.PushBack(SPtr<XML>(Element.Attrs[ind].GetPtr()));
        return true;
    }

    // @0x142405590
    bool AttrGetFirst::Call(UPInt ind)
    {
        if (Result.GetPtr() == NULL)
            Result = Element.Attrs[ind].GetPtr();
        return true;
    }

    // MS2-FUNCTIONAL: exe pushes through the out-of-line ArrayLH resize 0x142420060 and stores raw
    // @0x1424055e0
    bool ChildGet::Call(UPInt ind)
    {
        List.List.PushBack(Element.Children[ind]);
        return true;
    }

    // MS2-FUNCTIONAL: exe assigns through the out-of-line SPtr<XML> operator= 0x1423f1970
    // @0x142405640
    bool ChildGetFirst::Call(UPInt ind)
    {
        if (Result.GetPtr() == NULL)
            Result = Element.Children[ind];
        return true;
    }
}}
}}}
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl {

    // @0x142409100
    CheckResult XML::DeleteProperty(const Multiname& prop_name)
    {
        return Object::DeleteProperty(prop_name);
    }

    // @0x142409a60
    Boolean3 XML::EqualsInternal(const XML& other)
    {
        if (this == &other)
            return true3;
        if (GetKind() == other.GetKind() && Text == other.Text)
            return undefined3;
        return false3;
    }

    // @0x142409ae0
    Boolean3 XMLAttr::EqualsInternal(const XML& other)
    {
        Boolean3 r = XML::EqualsInternal(other);
        if (r == undefined3)
            r = (Data == static_cast<const XMLAttr&>(other).Data) ? true3 : false3;
        return r;
    }

    // @0x142409b20
    Boolean3 XMLComment::EqualsInternal(const XML& other)
    {
        Boolean3 r = XML::EqualsInternal(other);
        if (r == undefined3)
            r = true3;
        return r;
    }

    // @0x142409d40
    Boolean3 XMLProcInstr::EqualsInternal(const XML& other)
    {
        Boolean3 r = XML::EqualsInternal(other);
        if (r == undefined3)
            r = (Data == static_cast<const XMLProcInstr&>(other).Data) ? true3 : false3;
        return r;
    }
}}}}}
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl {

    // MS2-FUNCTIONAL: exe inlines the XML ctor 0x1423efce0
    // @0x1424087b0
    Pickable<XML> XML::DeepCopy(XML* parent)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        return Pickable<XML>(SF_HEAP_NEW(itr.GetVM().GetMemoryHeap()) XML(itr, Text, parent));
    }

    // @0x142408860
    Pickable<XML> XMLAttr::DeepCopy(XML* parent)
    {
        InstanceTraits::fl::XML& itr = static_cast<InstanceTraits::fl::XML&>(GetInstanceTraits());
        return Pickable<XML>(itr.MakeInstanceAttr(itr, *Ns, Text, Data, parent).GetPtr());
    }

    // MS2-FUNCTIONAL: exe inlines the XMLComment ctor
    // @0x1424088b0
    Pickable<XML> XMLComment::DeepCopy(XML* parent)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        return Pickable<XML>(SF_HEAP_NEW(itr.GetVM().GetMemoryHeap()) XMLComment(itr, Text, parent));
    }

    // MS2-FUNCTIONAL: exe inlines the XMLProcInstr ctor 0x1423f0260
    // @0x142408d40
    Pickable<XML> XMLProcInstr::DeepCopy(XML* parent)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        return Pickable<XML>(SF_HEAP_NEW(itr.GetVM().GetMemoryHeap()) XMLProcInstr(itr, Text, Data, parent));
    }
}}}}}
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl {

    // MS2-FUNCTIONAL: exe inlines the XMLText ctor 0x1423f02e0
    // @0x142408e00
    Pickable<XML> XMLText::DeepCopy(XML* parent)
    {
        InstanceTraits::Traits& itr = GetInstanceTraits();
        return Pickable<XML>(SF_HEAP_NEW(itr.GetVM().GetMemoryHeap()) XMLText(itr, Text, parent));
    }

    // @0x142408ed0
    void XMLElement::DeleteByIndex(UPInt ind)
    {
        if (ind < Children.GetSize())
        {
            Children[ind]->Parent = NULL;
            Children.RemoveAt(ind);
        }
    }

    // MS2-FUNCTIONAL: exe clears through the out-of-line ArrayLH ResizeNoConstruct 0x142420060
    // @0x142408f50
    void XMLElement::DeleteChildren(XML* child)
    {
        const UPInt size = Children.GetSize();
        if (child == NULL)
        {
            for (UPInt i = 0; i < size; ++i)
                Children[i]->Parent = NULL;
            Children.Clear();
        }
        else
        {
            for (UPInt i = 0; i < size; ++i)
            {
                if (Children[i] == child)
                {
                    Children[i]->Parent = NULL;
                    Children.RemoveAt(i);
                    return;
                }
            }
        }
    }

    // @0x142409060
    CheckResult Array::DeleteProperty(const Multiname& prop_name)
    {
        UInt32 ind;
        if (!GetArrayInd(prop_name, ind))
            return Object::DeleteProperty(prop_name);
        if (ind >= SA.GetSize())
            return false;
        SA.RemoveMultipleAt(ind, 1);
        return true;
    }
}}}}}
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl {

    // @0x142409120
    CheckResult XMLElement::DeleteProperty(const Multiname& prop_name)
    {
        UPInt i = 0;
        if (prop_name.IsAttr())
        {
            while (i < Attrs.GetSize())
            {
                XMLAttr* attr = Attrs[i];
                if (attr->Matches(prop_name))
                {
                    attr->Parent = NULL;
                    Attrs.RemoveAt(i);
                }
                else
                    ++i;
            }
        }
        else
        {
            while (i < Children.GetSize())
            {
                XML* child = Children[i];
                if (child->Matches(prop_name))
                {
                    child->Parent = NULL;
                    Children.RemoveAt(i);
                }
                else
                    ++i;
            }
        }
        return true;
    }
}}}}}
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl {

    // MS2-FUNCTIONAL: frame differs (exe keeps the Value/Multiname temps in a different layout)
    // @0x142409340
    CheckResult XMLList::DeleteProperty(const Multiname& prop_name)
    {
        UInt32 ind;
        const UPInt size = List.GetSize();
        if (GetVectorInd(prop_name, ind))
        {
            if (ind < size)
            {
                XML* x = List[ind];
                XML* parent = x->Parent;
                if (parent)
                {
                    if (x->GetKind() == XML::kAttr)
                    {
                        Value name(x->GetName());
                        Multiname mn(x->GetCurrNamespace(), name);
                        parent->DeleteProperty(mn);
                    }
                    else
                    {
                        UPInt pos;
                        if (x->GetChildIndex(pos))
                            parent->DeleteByIndex(pos);
                    }
                }
                List.RemoveAt(ind);
            }
        }
        else
        {
            for (UPInt i = 0; i < size; ++i)
            {
                XML* x = List[i];
                if (x->GetKind() == XML::kElement && !x->DeleteProperty(prop_name))
                    return false;
            }
        }
        return true;
    }
}}}}}

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
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
