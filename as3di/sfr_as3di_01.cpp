// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, the dynamic initializers of
// the native method member pointers ThunkFuncN<T, N, R, A...>::Method (0x14013b210-0x14013f0d0): each stores
// {method, 0} (16 bytes, the general member-pointer representation of as3_marshalling.h). The thunks that call
// through them are in the sfr_as3_* units. Our own source, written from the exe (work/sfr5/gen_natives.py).
// MS2-UNIT: sfr_as3di_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14013b210-0x14013f0d0 .text$di
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

namespace Scaleform { namespace GFx { namespace AS3 {

typedef ThunkFunc0<Instances::fl::Array, 3, Value> TFunc_Instances_fl_Array_AS3pop;
// @0x14013b210
template <> const TFunc_Instances_fl_Array_AS3pop::TMethod TFunc_Instances_fl_Array_AS3pop::Method = &Instances::fl::Array::AS3pop;
typedef ThunkFunc0<Instances::fl::Array, 5, SPtr<Instances::fl::Array>> TFunc_Instances_fl_Array_AS3reverse;
// @0x14013b240
template <> const TFunc_Instances_fl_Array_AS3reverse::TMethod TFunc_Instances_fl_Array_AS3reverse::Method = &Instances::fl::Array::AS3reverse;
typedef ThunkFunc0<Instances::fl::Array, 7, Value> TFunc_Instances_fl_Array_AS3shift;
// @0x14013b270
template <> const TFunc_Instances_fl_Array_AS3shift::TMethod TFunc_Instances_fl_Array_AS3shift::Method = &Instances::fl::Array::AS3shift;
typedef ThunkFunc0<Instances::fl::Array, 0, UInt32> TFunc_Instances_fl_Array_lengthGet;
// @0x14013b2a0
template <> const TFunc_Instances_fl_Array_lengthGet::TMethod TFunc_Instances_fl_Array_lengthGet::Method = &Instances::fl::Array::lengthGet;
typedef ThunkFunc0<Instances::fl::Date, 2, ASString> TFunc_Instances_fl_Date_AS3toString;
// @0x14013b2d0
template <> const TFunc_Instances_fl_Date_AS3toString::TMethod TFunc_Instances_fl_Date_AS3toString::Method = &Instances::fl::Date::AS3toString;
typedef ThunkFunc0<Instances::fl::Date, 3, ASString> TFunc_Instances_fl_Date_AS3toDateString;
// @0x14013b300
template <> const TFunc_Instances_fl_Date_AS3toDateString::TMethod TFunc_Instances_fl_Date_AS3toDateString::Method = &Instances::fl::Date::AS3toDateString;
typedef ThunkFunc0<Instances::fl::Date, 4, ASString> TFunc_Instances_fl_Date_AS3toTimeString;
// @0x14013b330
template <> const TFunc_Instances_fl_Date_AS3toTimeString::TMethod TFunc_Instances_fl_Date_AS3toTimeString::Method = &Instances::fl::Date::AS3toTimeString;
typedef ThunkFunc0<Instances::fl::Date, 5, ASString> TFunc_Instances_fl_Date_AS3toLocaleString;
// @0x14013b360
template <> const TFunc_Instances_fl_Date_AS3toLocaleString::TMethod TFunc_Instances_fl_Date_AS3toLocaleString::Method = &Instances::fl::Date::AS3toLocaleString;
typedef ThunkFunc0<Instances::fl::Date, 6, ASString> TFunc_Instances_fl_Date_AS3toLocaleDateString;
// @0x14013b390
template <> const TFunc_Instances_fl_Date_AS3toLocaleDateString::TMethod TFunc_Instances_fl_Date_AS3toLocaleDateString::Method = &Instances::fl::Date::AS3toLocaleDateString;
typedef ThunkFunc0<Instances::fl::Date, 7, ASString> TFunc_Instances_fl_Date_AS3toLocaleTimeString;
// @0x14013b3c0
template <> const TFunc_Instances_fl_Date_AS3toLocaleTimeString::TMethod TFunc_Instances_fl_Date_AS3toLocaleTimeString::Method = &Instances::fl::Date::AS3toLocaleTimeString;
typedef ThunkFunc0<Instances::fl::Date, 8, ASString> TFunc_Instances_fl_Date_AS3toUTCString;
// @0x14013b3f0
template <> const TFunc_Instances_fl_Date_AS3toUTCString::TMethod TFunc_Instances_fl_Date_AS3toUTCString::Method = &Instances::fl::Date::AS3toUTCString;
typedef ThunkFunc0<Instances::fl::Date, 9, Value::Number> TFunc_Instances_fl_Date_AS3getUTCFullYear;
// @0x14013b420
template <> const TFunc_Instances_fl_Date_AS3getUTCFullYear::TMethod TFunc_Instances_fl_Date_AS3getUTCFullYear::Method = &Instances::fl::Date::AS3getUTCFullYear;
typedef ThunkFunc0<Instances::fl::Date, 10, Value::Number> TFunc_Instances_fl_Date_AS3getUTCMonth;
// @0x14013b450
template <> const TFunc_Instances_fl_Date_AS3getUTCMonth::TMethod TFunc_Instances_fl_Date_AS3getUTCMonth::Method = &Instances::fl::Date::AS3getUTCMonth;
typedef ThunkFunc0<Instances::fl::Date, 0, Value::Number> TFunc_Instances_fl_Date_AS3valueOf;
// @0x14013b480
template <> const TFunc_Instances_fl_Date_AS3valueOf::TMethod TFunc_Instances_fl_Date_AS3valueOf::Method = &Instances::fl::Date::AS3valueOf;
typedef ThunkFunc0<Instances::fl::Date, 16, Value::Number> TFunc_Instances_fl_Date_AS3getUTCMilliseconds;
// @0x14013b4b0
template <> const TFunc_Instances_fl_Date_AS3getUTCMilliseconds::TMethod TFunc_Instances_fl_Date_AS3getUTCMilliseconds::Method = &Instances::fl::Date::AS3getUTCMilliseconds;
typedef ThunkFunc0<Instances::fl::Date, 17, Value::Number> TFunc_Instances_fl_Date_AS3getFullYear;
// @0x14013b4e0
template <> const TFunc_Instances_fl_Date_AS3getFullYear::TMethod TFunc_Instances_fl_Date_AS3getFullYear::Method = &Instances::fl::Date::AS3getFullYear;
typedef ThunkFunc0<Instances::fl::Date, 18, Value::Number> TFunc_Instances_fl_Date_AS3getMonth;
// @0x14013b510
template <> const TFunc_Instances_fl_Date_AS3getMonth::TMethod TFunc_Instances_fl_Date_AS3getMonth::Method = &Instances::fl::Date::AS3getMonth;
typedef ThunkFunc0<Instances::fl::Date, 19, Value::Number> TFunc_Instances_fl_Date_AS3getDate;
// @0x14013b540
template <> const TFunc_Instances_fl_Date_AS3getDate::TMethod TFunc_Instances_fl_Date_AS3getDate::Method = &Instances::fl::Date::AS3getDate;
typedef ThunkFunc0<Instances::fl::Date, 20, Value::Number> TFunc_Instances_fl_Date_AS3getDay;
// @0x14013b570
template <> const TFunc_Instances_fl_Date_AS3getDay::TMethod TFunc_Instances_fl_Date_AS3getDay::Method = &Instances::fl::Date::AS3getDay;
typedef ThunkFunc0<Instances::fl::Date, 21, Value::Number> TFunc_Instances_fl_Date_AS3getHours;
// @0x14013b5a0
template <> const TFunc_Instances_fl_Date_AS3getHours::TMethod TFunc_Instances_fl_Date_AS3getHours::Method = &Instances::fl::Date::AS3getHours;
typedef ThunkFunc0<Instances::fl::Date, 22, Value::Number> TFunc_Instances_fl_Date_AS3getMinutes;
// @0x14013b5d0
template <> const TFunc_Instances_fl_Date_AS3getMinutes::TMethod TFunc_Instances_fl_Date_AS3getMinutes::Method = &Instances::fl::Date::AS3getMinutes;
typedef ThunkFunc0<Instances::fl::Date, 23, Value::Number> TFunc_Instances_fl_Date_AS3getSeconds;
// @0x14013b600
template <> const TFunc_Instances_fl_Date_AS3getSeconds::TMethod TFunc_Instances_fl_Date_AS3getSeconds::Method = &Instances::fl::Date::AS3getSeconds;
typedef ThunkFunc0<Instances::fl::Date, 24, Value::Number> TFunc_Instances_fl_Date_AS3getMilliseconds;
// @0x14013b630
template <> const TFunc_Instances_fl_Date_AS3getMilliseconds::TMethod TFunc_Instances_fl_Date_AS3getMilliseconds::Method = &Instances::fl::Date::AS3getMilliseconds;
typedef ThunkFunc0<Instances::fl::Date, 25, Value::Number> TFunc_Instances_fl_Date_AS3getTimezoneOffset;
// @0x14013b660
template <> const TFunc_Instances_fl_Date_AS3getTimezoneOffset::TMethod TFunc_Instances_fl_Date_AS3getTimezoneOffset::Method = &Instances::fl::Date::AS3getTimezoneOffset;
typedef ThunkFunc0<Instances::fl::Date, 26, Value::Number> TFunc_Instances_fl_Date_AS3getTime;
// @0x14013b690
template <> const TFunc_Instances_fl_Date_AS3getTime::TMethod TFunc_Instances_fl_Date_AS3getTime::Method = &Instances::fl::Date::AS3getTime;
typedef ThunkFunc0<Instances::fl::Date, 41, Value::Number> TFunc_Instances_fl_Date_fullYearGet;
// @0x14013b6c0
template <> const TFunc_Instances_fl_Date_fullYearGet::TMethod TFunc_Instances_fl_Date_fullYearGet::Method = &Instances::fl::Date::fullYearGet;
typedef ThunkFunc0<Instances::fl::Date, 43, Value::Number> TFunc_Instances_fl_Date_monthGet;
// @0x14013b6f0
template <> const TFunc_Instances_fl_Date_monthGet::TMethod TFunc_Instances_fl_Date_monthGet::Method = &Instances::fl::Date::monthGet;
typedef ThunkFunc0<Instances::fl::Date, 45, Value::Number> TFunc_Instances_fl_Date_dateGet;
// @0x14013b720
template <> const TFunc_Instances_fl_Date_dateGet::TMethod TFunc_Instances_fl_Date_dateGet::Method = &Instances::fl::Date::dateGet;
typedef ThunkFunc0<Instances::fl::Date, 47, Value::Number> TFunc_Instances_fl_Date_hoursGet;
// @0x14013b750
template <> const TFunc_Instances_fl_Date_hoursGet::TMethod TFunc_Instances_fl_Date_hoursGet::Method = &Instances::fl::Date::hoursGet;
typedef ThunkFunc0<Instances::fl::Date, 49, Value::Number> TFunc_Instances_fl_Date_minutesGet;
// @0x14013b780
template <> const TFunc_Instances_fl_Date_minutesGet::TMethod TFunc_Instances_fl_Date_minutesGet::Method = &Instances::fl::Date::minutesGet;
typedef ThunkFunc0<Instances::fl::Date, 51, Value::Number> TFunc_Instances_fl_Date_secondsGet;
// @0x14013b7b0
template <> const TFunc_Instances_fl_Date_secondsGet::TMethod TFunc_Instances_fl_Date_secondsGet::Method = &Instances::fl::Date::secondsGet;
typedef ThunkFunc0<Instances::fl::Date, 53, Value::Number> TFunc_Instances_fl_Date_millisecondsGet;
// @0x14013b7e0
template <> const TFunc_Instances_fl_Date_millisecondsGet::TMethod TFunc_Instances_fl_Date_millisecondsGet::Method = &Instances::fl::Date::millisecondsGet;
typedef ThunkFunc0<Instances::fl::Date, 55, Value::Number> TFunc_Instances_fl_Date_fullYearUTCGet;
// @0x14013b810
template <> const TFunc_Instances_fl_Date_fullYearUTCGet::TMethod TFunc_Instances_fl_Date_fullYearUTCGet::Method = &Instances::fl::Date::fullYearUTCGet;
typedef ThunkFunc0<Instances::fl::Date, 57, Value::Number> TFunc_Instances_fl_Date_monthUTCGet;
// @0x14013b840
template <> const TFunc_Instances_fl_Date_monthUTCGet::TMethod TFunc_Instances_fl_Date_monthUTCGet::Method = &Instances::fl::Date::monthUTCGet;
typedef ThunkFunc0<Instances::fl::Date, 59, Value::Number> TFunc_Instances_fl_Date_dateUTCGet;
// @0x14013b870
template <> const TFunc_Instances_fl_Date_dateUTCGet::TMethod TFunc_Instances_fl_Date_dateUTCGet::Method = &Instances::fl::Date::dateUTCGet;
typedef ThunkFunc0<Instances::fl::Date, 61, Value::Number> TFunc_Instances_fl_Date_hoursUTCGet;
// @0x14013b8a0
template <> const TFunc_Instances_fl_Date_hoursUTCGet::TMethod TFunc_Instances_fl_Date_hoursUTCGet::Method = &Instances::fl::Date::hoursUTCGet;
typedef ThunkFunc0<Instances::fl::Date, 63, Value::Number> TFunc_Instances_fl_Date_minutesUTCGet;
// @0x14013b8d0
template <> const TFunc_Instances_fl_Date_minutesUTCGet::TMethod TFunc_Instances_fl_Date_minutesUTCGet::Method = &Instances::fl::Date::minutesUTCGet;
typedef ThunkFunc0<Instances::fl::Date, 65, Value::Number> TFunc_Instances_fl_Date_secondsUTCGet;
// @0x14013b900
template <> const TFunc_Instances_fl_Date_secondsUTCGet::TMethod TFunc_Instances_fl_Date_secondsUTCGet::Method = &Instances::fl::Date::secondsUTCGet;
typedef ThunkFunc0<Instances::fl::Date, 67, Value::Number> TFunc_Instances_fl_Date_millisecondsUTCGet;
// @0x14013b930
template <> const TFunc_Instances_fl_Date_millisecondsUTCGet::TMethod TFunc_Instances_fl_Date_millisecondsUTCGet::Method = &Instances::fl::Date::millisecondsUTCGet;
typedef ThunkFunc0<Instances::fl::Date, 69, Value::Number> TFunc_Instances_fl_Date_timeGet;
// @0x14013b960
template <> const TFunc_Instances_fl_Date_timeGet::TMethod TFunc_Instances_fl_Date_timeGet::Method = &Instances::fl::Date::timeGet;
typedef ThunkFunc0<Instances::fl::Date, 71, Value::Number> TFunc_Instances_fl_Date_timezoneOffsetGet;
// @0x14013b990
template <> const TFunc_Instances_fl_Date_timezoneOffsetGet::TMethod TFunc_Instances_fl_Date_timezoneOffsetGet::Method = &Instances::fl::Date::timezoneOffsetGet;
typedef ThunkFunc0<Instances::fl::Date, 72, Value::Number> TFunc_Instances_fl_Date_dayGet;
// @0x14013b9c0
template <> const TFunc_Instances_fl_Date_dayGet::TMethod TFunc_Instances_fl_Date_dayGet::Method = &Instances::fl::Date::dayGet;
typedef ThunkFunc0<Instances::fl::Date, 73, Value::Number> TFunc_Instances_fl_Date_dayUTCGet;
// @0x14013b9f0
template <> const TFunc_Instances_fl_Date_dayUTCGet::TMethod TFunc_Instances_fl_Date_dayUTCGet::Method = &Instances::fl::Date::dayUTCGet;
typedef ThunkFunc0<Instances::fl::Date, 11, Value::Number> TFunc_Instances_fl_Date_AS3getUTCDate;
// @0x14013ba20
template <> const TFunc_Instances_fl_Date_AS3getUTCDate::TMethod TFunc_Instances_fl_Date_AS3getUTCDate::Method = &Instances::fl::Date::AS3getUTCDate;
typedef ThunkFunc0<Instances::fl::Date, 12, Value::Number> TFunc_Instances_fl_Date_AS3getUTCDay;
// @0x14013ba50
template <> const TFunc_Instances_fl_Date_AS3getUTCDay::TMethod TFunc_Instances_fl_Date_AS3getUTCDay::Method = &Instances::fl::Date::AS3getUTCDay;
typedef ThunkFunc0<Instances::fl::Date, 13, Value::Number> TFunc_Instances_fl_Date_AS3getUTCHours;
// @0x14013ba80
template <> const TFunc_Instances_fl_Date_AS3getUTCHours::TMethod TFunc_Instances_fl_Date_AS3getUTCHours::Method = &Instances::fl::Date::AS3getUTCHours;
typedef ThunkFunc0<Instances::fl::Date, 14, Value::Number> TFunc_Instances_fl_Date_AS3getUTCMinutes;
// @0x14013bab0
template <> const TFunc_Instances_fl_Date_AS3getUTCMinutes::TMethod TFunc_Instances_fl_Date_AS3getUTCMinutes::Method = &Instances::fl::Date::AS3getUTCMinutes;
typedef ThunkFunc0<Instances::fl::Date, 15, Value::Number> TFunc_Instances_fl_Date_AS3getUTCSeconds;
// @0x14013bae0
template <> const TFunc_Instances_fl_Date_AS3getUTCSeconds::TMethod TFunc_Instances_fl_Date_AS3getUTCSeconds::Method = &Instances::fl::Date::AS3getUTCSeconds;
typedef ThunkFunc0<Instances::fl::Error, 1, ASString> TFunc_Instances_fl_Error_getStackTrace;
// @0x14013bb10
template <> const TFunc_Instances_fl_Error_getStackTrace::TMethod TFunc_Instances_fl_Error_getStackTrace::Method = &Instances::fl::Error::getStackTrace;
typedef ThunkFunc0<Instances::fl::Error, 2, ASString> TFunc_Instances_fl_Error_toStringProto;
// @0x14013bb40
template <> const TFunc_Instances_fl_Error_toStringProto::TMethod TFunc_Instances_fl_Error_toStringProto::Method = &Instances::fl::Error::toStringProto;
typedef ThunkFunc0<Instances::fl::Error, 0, SInt32> TFunc_Instances_fl_Error_errorIDGet;
// @0x14013bb70
template <> const TFunc_Instances_fl_Error_errorIDGet::TMethod TFunc_Instances_fl_Error_errorIDGet::Method = &Instances::fl::Error::errorIDGet;
typedef ThunkFunc0<Instances::FunctionBase, 2, UInt32> TFunc_Instances_FunctionBase_lengthGet;
// @0x14013bba0
template <> const TFunc_Instances_FunctionBase_lengthGet::TMethod TFunc_Instances_FunctionBase_lengthGet::Method = &Instances::FunctionBase::lengthGet;
typedef ThunkFunc0<Instances::fl::GlobalObjectCPP, 20, SInt32> TFunc_Instances_fl_GlobalObjectCPP_getTimer;
// @0x14013bbd0
template <> const TFunc_Instances_fl_GlobalObjectCPP_getTimer::TMethod TFunc_Instances_fl_GlobalObjectCPP_getTimer::Method = &Instances::fl::GlobalObjectCPP::getTimer;
typedef ThunkFunc0<Classes::fl::Math, 17, Value::Number> TFunc_Classes_fl_Math_random;
// @0x14013bc00
template <> const TFunc_Classes_fl_Math_random::TMethod TFunc_Classes_fl_Math_random::Method = &Classes::fl::Math::random;
typedef ThunkFunc0<Instances::fl::QName, 1, Value> TFunc_Instances_fl_QName_uriGet;
// @0x14013bc30
template <> const TFunc_Instances_fl_QName_uriGet::TMethod TFunc_Instances_fl_QName_uriGet::Method = &Instances::fl::QName::uriGet;
typedef ThunkFunc0<Instances::fl::QName, 2, SPtr<Instances::fl::QName>> TFunc_Instances_fl_QName_AS3valueOf;
// @0x14013bc60
template <> const TFunc_Instances_fl_QName_AS3valueOf::TMethod TFunc_Instances_fl_QName_AS3valueOf::Method = &Instances::fl::QName::AS3valueOf;
typedef ThunkFunc0<Instances::fl::QName, 3, ASString> TFunc_Instances_fl_QName_AS3toString;
// @0x14013bc90
template <> const TFunc_Instances_fl_QName_AS3toString::TMethod TFunc_Instances_fl_QName_AS3toString::Method = &Instances::fl::QName::AS3toString;
typedef ThunkFunc0<Instances::fl::QName, 0, ASString> TFunc_Instances_fl_QName_localNameGet;
// @0x14013bcc0
template <> const TFunc_Instances_fl_QName_localNameGet::TMethod TFunc_Instances_fl_QName_localNameGet::Method = &Instances::fl::QName::localNameGet;
typedef ThunkFunc0<Instances::fl::RegExp, 1, bool> TFunc_Instances_fl_RegExp_globalGet;
// @0x14013bcf0
template <> const TFunc_Instances_fl_RegExp_globalGet::TMethod TFunc_Instances_fl_RegExp_globalGet::Method = &Instances::fl::RegExp::globalGet;
typedef ThunkFunc0<Instances::fl::RegExp, 2, bool> TFunc_Instances_fl_RegExp_ignoreCaseGet;
// @0x14013bd20
template <> const TFunc_Instances_fl_RegExp_ignoreCaseGet::TMethod TFunc_Instances_fl_RegExp_ignoreCaseGet::Method = &Instances::fl::RegExp::ignoreCaseGet;
typedef ThunkFunc0<Instances::fl::RegExp, 3, bool> TFunc_Instances_fl_RegExp_multilineGet;
// @0x14013bd50
template <> const TFunc_Instances_fl_RegExp_multilineGet::TMethod TFunc_Instances_fl_RegExp_multilineGet::Method = &Instances::fl::RegExp::multilineGet;
typedef ThunkFunc0<Instances::fl::RegExp, 4, SInt32> TFunc_Instances_fl_RegExp_lastIndexGet;
// @0x14013bd80
template <> const TFunc_Instances_fl_RegExp_lastIndexGet::TMethod TFunc_Instances_fl_RegExp_lastIndexGet::Method = &Instances::fl::RegExp::lastIndexGet;
typedef ThunkFunc0<Instances::fl::RegExp, 6, bool> TFunc_Instances_fl_RegExp_dotallGet;
// @0x14013bdb0
template <> const TFunc_Instances_fl_RegExp_dotallGet::TMethod TFunc_Instances_fl_RegExp_dotallGet::Method = &Instances::fl::RegExp::dotallGet;
typedef ThunkFunc0<Instances::fl::RegExp, 7, bool> TFunc_Instances_fl_RegExp_extendedGet;
// @0x14013bde0
template <> const TFunc_Instances_fl_RegExp_extendedGet::TMethod TFunc_Instances_fl_RegExp_extendedGet::Method = &Instances::fl::RegExp::extendedGet;
typedef ThunkFunc0<Instances::fl::RegExp, 0, ASString> TFunc_Instances_fl_RegExp_sourceGet;
// @0x14013be10
template <> const TFunc_Instances_fl_RegExp_sourceGet::TMethod TFunc_Instances_fl_RegExp_sourceGet::Method = &Instances::fl::RegExp::sourceGet;
typedef ThunkFunc0<Classes::fl::XML, 1, SPtr<Instances::fl::Object>> TFunc_Classes_fl_XML_settings;
// @0x14013be40
template <> const TFunc_Classes_fl_XML_settings::TMethod TFunc_Classes_fl_XML_settings::Method = &Classes::fl::XML::settings;
typedef ThunkFunc0<Classes::fl::XML, 4, SPtr<Instances::fl::Object>> TFunc_Classes_fl_XML_AS3defaultSettings;
// @0x14013be70
template <> const TFunc_Classes_fl_XML_AS3defaultSettings::TMethod TFunc_Classes_fl_XML_AS3defaultSettings::Method = &Classes::fl::XML::AS3defaultSettings;
typedef ThunkFunc0<Classes::fl::XML, 5, SPtr<Instances::fl::Object>> TFunc_Classes_fl_XML_defaultSettings;
// @0x14013bea0
template <> const TFunc_Classes_fl_XML_defaultSettings::TMethod TFunc_Classes_fl_XML_defaultSettings::Method = &Classes::fl::XML::defaultSettings;
typedef ThunkFunc0<Classes::fl::XML, 0, SPtr<Instances::fl::Object>> TFunc_Classes_fl_XML_AS3settings;
// @0x14013bed0
template <> const TFunc_Classes_fl_XML_AS3settings::TMethod TFunc_Classes_fl_XML_AS3settings::Method = &Classes::fl::XML::AS3settings;
typedef ThunkFunc0<Instances::fl::XML, 2, ASString> TFunc_Instances_fl_XML_AS3toString;
// @0x14013bf00
template <> const TFunc_Instances_fl_XML_AS3toString::TMethod TFunc_Instances_fl_XML_AS3toString::Method = &Instances::fl::XML::AS3toString;
typedef ThunkFunc0<Instances::fl::XML, 8, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XML_AS3attributes;
// @0x14013bf30
template <> const TFunc_Instances_fl_XML_AS3attributes::TMethod TFunc_Instances_fl_XML_AS3attributes::Method = &Instances::fl::XML::AS3attributes;
typedef ThunkFunc0<Instances::fl::XML, 10, SInt32> TFunc_Instances_fl_XML_AS3childIndex;
// @0x14013bf60
template <> const TFunc_Instances_fl_XML_AS3childIndex::TMethod TFunc_Instances_fl_XML_AS3childIndex::Method = &Instances::fl::XML::AS3childIndex;
typedef ThunkFunc0<Instances::fl::XML, 0, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XML_prototypeGet;
// @0x14013bf90
template <> const TFunc_Instances_fl_XML_prototypeGet::TMethod TFunc_Instances_fl_XML_prototypeGet::Method = &Instances::fl::XML::prototypeGet;
typedef ThunkFunc0<Instances::fl::XML, 17, bool> TFunc_Instances_fl_XML_AS3hasComplexContent;
// @0x14013bfc0
template <> const TFunc_Instances_fl_XML_AS3hasComplexContent::TMethod TFunc_Instances_fl_XML_AS3hasComplexContent::Method = &Instances::fl::XML::AS3hasComplexContent;
typedef ThunkFunc0<Instances::fl::XML, 18, bool> TFunc_Instances_fl_XML_AS3hasSimpleContent;
// @0x14013bff0
template <> const TFunc_Instances_fl_XML_AS3hasSimpleContent::TMethod TFunc_Instances_fl_XML_AS3hasSimpleContent::Method = &Instances::fl::XML::AS3hasSimpleContent;
typedef ThunkFunc0<Instances::fl::XML, 19, SPtr<Instances::fl::Array>> TFunc_Instances_fl_XML_AS3inScopeNamespaces;
// @0x14013c020
template <> const TFunc_Instances_fl_XML_AS3inScopeNamespaces::TMethod TFunc_Instances_fl_XML_AS3inScopeNamespaces::Method = &Instances::fl::XML::AS3inScopeNamespaces;
typedef ThunkFunc0<Instances::fl::XML, 22, SInt32> TFunc_Instances_fl_XML_AS3length;
// @0x14013c050
template <> const TFunc_Instances_fl_XML_AS3length::TMethod TFunc_Instances_fl_XML_AS3length::Method = &Instances::fl::XML::AS3length;
typedef ThunkFunc0<Instances::fl::XML, 23, ASString> TFunc_Instances_fl_XML_AS3localName;
// @0x14013c080
template <> const TFunc_Instances_fl_XML_AS3localName::TMethod TFunc_Instances_fl_XML_AS3localName::Method = &Instances::fl::XML::AS3localName;
typedef ThunkFunc0<Instances::fl::XML, 24, SPtr<Instances::fl::QName>> TFunc_Instances_fl_XML_AS3name;
// @0x14013c0b0
template <> const TFunc_Instances_fl_XML_AS3name::TMethod TFunc_Instances_fl_XML_AS3name::Method = &Instances::fl::XML::AS3name;
typedef ThunkFunc0<Instances::fl::XML, 26, SPtr<Instances::fl::Array>> TFunc_Instances_fl_XML_AS3namespaceDeclarations;
// @0x14013c0e0
template <> const TFunc_Instances_fl_XML_AS3namespaceDeclarations::TMethod TFunc_Instances_fl_XML_AS3namespaceDeclarations::Method = &Instances::fl::XML::AS3namespaceDeclarations;
typedef ThunkFunc0<Instances::fl::XML, 27, ASString> TFunc_Instances_fl_XML_AS3nodeKind;
// @0x14013c110
template <> const TFunc_Instances_fl_XML_AS3nodeKind::TMethod TFunc_Instances_fl_XML_AS3nodeKind::Method = &Instances::fl::XML::AS3nodeKind;
typedef ThunkFunc0<Instances::fl::XML, 28, SPtr<Instances::fl::XML>> TFunc_Instances_fl_XML_AS3normalize;
// @0x14013c140
template <> const TFunc_Instances_fl_XML_AS3normalize::TMethod TFunc_Instances_fl_XML_AS3normalize::Method = &Instances::fl::XML::AS3normalize;
typedef ThunkFunc0<Instances::fl::XML, 29, Value> TFunc_Instances_fl_XML_AS3parent;
// @0x14013c170
template <> const TFunc_Instances_fl_XML_AS3parent::TMethod TFunc_Instances_fl_XML_AS3parent::Method = &Instances::fl::XML::AS3parent;
typedef ThunkFunc0<Instances::fl::XML, 38, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XML_AS3text;
// @0x14013c1a0
template <> const TFunc_Instances_fl_XML_AS3text::TMethod TFunc_Instances_fl_XML_AS3text::Method = &Instances::fl::XML::AS3text;
typedef ThunkFunc0<Instances::fl::XML, 39, ASString> TFunc_Instances_fl_XML_AS3toXMLString;
// @0x14013c1d0
template <> const TFunc_Instances_fl_XML_AS3toXMLString::TMethod TFunc_Instances_fl_XML_AS3toXMLString::Method = &Instances::fl::XML::AS3toXMLString;
typedef ThunkFunc0<Instances::fl::XML, 40, SPtr<Instances::fl::XML>> TFunc_Instances_fl_XML_AS3valueOf;
// @0x14013c200
template <> const TFunc_Instances_fl_XML_AS3valueOf::TMethod TFunc_Instances_fl_XML_AS3valueOf::Method = &Instances::fl::XML::AS3valueOf;
typedef ThunkFunc0<Instances::fl::XML, 11, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XML_AS3children;
// @0x14013c230
template <> const TFunc_Instances_fl_XML_AS3children::TMethod TFunc_Instances_fl_XML_AS3children::Method = &Instances::fl::XML::AS3children;
typedef ThunkFunc0<Instances::fl::XML, 12, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XML_AS3comments;
// @0x14013c260
template <> const TFunc_Instances_fl_XML_AS3comments::TMethod TFunc_Instances_fl_XML_AS3comments::Method = &Instances::fl::XML::AS3comments;
typedef ThunkFunc0<Instances::fl::XML, 14, SPtr<Instances::fl::XML>> TFunc_Instances_fl_XML_AS3copy;
// @0x14013c290
template <> const TFunc_Instances_fl_XML_AS3copy::TMethod TFunc_Instances_fl_XML_AS3copy::Method = &Instances::fl::XML::AS3copy;
typedef ThunkFunc0<Instances::fl::XMLList, 2, SInt32> TFunc_Instances_fl_XMLList_AS3length;
// @0x14013c2c0
template <> const TFunc_Instances_fl_XMLList_AS3length::TMethod TFunc_Instances_fl_XMLList_AS3length::Method = &Instances::fl::XMLList::AS3length;
typedef ThunkFunc0<Instances::fl::XMLList, 3, ASString> TFunc_Instances_fl_XMLList_AS3toString;
// @0x14013c2f0
template <> const TFunc_Instances_fl_XMLList_AS3toString::TMethod TFunc_Instances_fl_XMLList_AS3toString::Method = &Instances::fl::XMLList::AS3toString;
typedef ThunkFunc0<Instances::fl::XMLList, 4, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XMLList_AS3valueOf;
// @0x14013c320
template <> const TFunc_Instances_fl_XMLList_AS3valueOf::TMethod TFunc_Instances_fl_XMLList_AS3valueOf::Method = &Instances::fl::XMLList::AS3valueOf;
typedef ThunkFunc0<Instances::fl::XMLList, 8, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XMLList_AS3attributes;
// @0x14013c350
template <> const TFunc_Instances_fl_XMLList_AS3attributes::TMethod TFunc_Instances_fl_XMLList_AS3attributes::Method = &Instances::fl::XMLList::AS3attributes;
typedef ThunkFunc0<Instances::fl::XMLList, 10, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XMLList_AS3children;
// @0x14013c380
template <> const TFunc_Instances_fl_XMLList_AS3children::TMethod TFunc_Instances_fl_XMLList_AS3children::Method = &Instances::fl::XMLList::AS3children;
typedef ThunkFunc0<Instances::fl::XMLList, 0, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XMLList_prototypeGet;
// @0x14013c3b0
template <> const TFunc_Instances_fl_XMLList_prototypeGet::TMethod TFunc_Instances_fl_XMLList_prototypeGet::Method = &Instances::fl::XMLList::prototypeGet;
typedef ThunkFunc0<Instances::fl::XMLList, 16, bool> TFunc_Instances_fl_XMLList_AS3hasComplexContent;
// @0x14013c3e0
template <> const TFunc_Instances_fl_XMLList_AS3hasComplexContent::TMethod TFunc_Instances_fl_XMLList_AS3hasComplexContent::Method = &Instances::fl::XMLList::AS3hasComplexContent;
typedef ThunkFunc0<Instances::fl::XMLList, 17, bool> TFunc_Instances_fl_XMLList_AS3hasSimpleContent;
// @0x14013c410
template <> const TFunc_Instances_fl_XMLList_AS3hasSimpleContent::TMethod TFunc_Instances_fl_XMLList_AS3hasSimpleContent::Method = &Instances::fl::XMLList::AS3hasSimpleContent;
typedef ThunkFunc0<Instances::fl::XMLList, 18, SPtr<Instances::fl::QName>> TFunc_Instances_fl_XMLList_AS3name;
// @0x14013c440
template <> const TFunc_Instances_fl_XMLList_AS3name::TMethod TFunc_Instances_fl_XMLList_AS3name::Method = &Instances::fl::XMLList::AS3name;
typedef ThunkFunc0<Instances::fl::XMLList, 19, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XMLList_AS3normalize;
// @0x14013c470
template <> const TFunc_Instances_fl_XMLList_AS3normalize::TMethod TFunc_Instances_fl_XMLList_AS3normalize::Method = &Instances::fl::XMLList::AS3normalize;
typedef ThunkFunc0<Instances::fl::XMLList, 20, Value> TFunc_Instances_fl_XMLList_AS3parent;
// @0x14013c4a0
template <> const TFunc_Instances_fl_XMLList_AS3parent::TMethod TFunc_Instances_fl_XMLList_AS3parent::Method = &Instances::fl::XMLList::AS3parent;
typedef ThunkFunc0<Instances::fl::XMLList, 22, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XMLList_AS3text;
// @0x14013c4d0
template <> const TFunc_Instances_fl_XMLList_AS3text::TMethod TFunc_Instances_fl_XMLList_AS3text::Method = &Instances::fl::XMLList::AS3text;
typedef ThunkFunc0<Instances::fl::XMLList, 23, ASString> TFunc_Instances_fl_XMLList_AS3toXMLString;
// @0x14013c500
template <> const TFunc_Instances_fl_XMLList_AS3toXMLString::TMethod TFunc_Instances_fl_XMLList_AS3toXMLString::Method = &Instances::fl::XMLList::AS3toXMLString;
typedef ThunkFunc0<Instances::fl::XMLList, 26, SInt32> TFunc_Instances_fl_XMLList_AS3childIndex;
// @0x14013c530
template <> const TFunc_Instances_fl_XMLList_AS3childIndex::TMethod TFunc_Instances_fl_XMLList_AS3childIndex::Method = &Instances::fl::XMLList::AS3childIndex;
typedef ThunkFunc0<Instances::fl::XMLList, 27, SPtr<Instances::fl::Array>> TFunc_Instances_fl_XMLList_AS3inScopeNamespaces;
// @0x14013c560
template <> const TFunc_Instances_fl_XMLList_AS3inScopeNamespaces::TMethod TFunc_Instances_fl_XMLList_AS3inScopeNamespaces::Method = &Instances::fl::XMLList::AS3inScopeNamespaces;
typedef ThunkFunc0<Instances::fl::XMLList, 30, ASString> TFunc_Instances_fl_XMLList_AS3nodeKind;
// @0x14013c590
template <> const TFunc_Instances_fl_XMLList_AS3nodeKind::TMethod TFunc_Instances_fl_XMLList_AS3nodeKind::Method = &Instances::fl::XMLList::AS3nodeKind;
typedef ThunkFunc0<Instances::fl::XMLList, 32, ASString> TFunc_Instances_fl_XMLList_AS3localName;
// @0x14013c5c0
template <> const TFunc_Instances_fl_XMLList_AS3localName::TMethod TFunc_Instances_fl_XMLList_AS3localName::Method = &Instances::fl::XMLList::AS3localName;
typedef ThunkFunc0<Instances::fl::XMLList, 33, SPtr<Instances::fl::Array>> TFunc_Instances_fl_XMLList_AS3namespaceDeclarations;
// @0x14013c5f0
template <> const TFunc_Instances_fl_XMLList_AS3namespaceDeclarations::TMethod TFunc_Instances_fl_XMLList_AS3namespaceDeclarations::Method = &Instances::fl::XMLList::AS3namespaceDeclarations;
typedef ThunkFunc0<Instances::fl::XMLList, 11, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XMLList_AS3comments;
// @0x14013c620
template <> const TFunc_Instances_fl_XMLList_AS3comments::TMethod TFunc_Instances_fl_XMLList_AS3comments::Method = &Instances::fl::XMLList::AS3comments;
typedef ThunkFunc0<Instances::fl::XMLList, 13, SPtr<Instances::fl::XMLList>> TFunc_Instances_fl_XMLList_AS3copy;
// @0x14013c650
template <> const TFunc_Instances_fl_XMLList_AS3copy::TMethod TFunc_Instances_fl_XMLList_AS3copy::Method = &Instances::fl::XMLList::AS3copy;
typedef ThunkFunc1<Instances::fl::Array, 1, const Value, UInt32> TFunc_Instances_fl_Array_lengthSet;
// @0x14013c680
template <> const TFunc_Instances_fl_Array_lengthSet::TMethod TFunc_Instances_fl_Array_lengthSet::Method = &Instances::fl::Array::lengthSet;
typedef ThunkFunc1<Classes::fl::Date, 0, Value::Number, const Value&> TFunc_Classes_fl_Date_parse;
// @0x14013c6b0
template <> const TFunc_Classes_fl_Date_parse::TMethod TFunc_Classes_fl_Date_parse::Method = &Classes::fl::Date::parse;
typedef ThunkFunc1<Instances::fl::Date, 1, Value::Number, Value::Number> TFunc_Instances_fl_Date_AS3setTime;
// @0x14013c6e0
template <> const TFunc_Instances_fl_Date_AS3setTime::TMethod TFunc_Instances_fl_Date_AS3setTime::Method = &Instances::fl::Date::AS3setTime;
typedef ThunkFunc1<Instances::fl::Date, 42, const Value, Value::Number> TFunc_Instances_fl_Date_fullYearSet;
// @0x14013c710
template <> const TFunc_Instances_fl_Date_fullYearSet::TMethod TFunc_Instances_fl_Date_fullYearSet::Method = &Instances::fl::Date::fullYearSet;
typedef ThunkFunc1<Instances::fl::Date, 44, const Value, Value::Number> TFunc_Instances_fl_Date_monthSet;
// @0x14013c740
template <> const TFunc_Instances_fl_Date_monthSet::TMethod TFunc_Instances_fl_Date_monthSet::Method = &Instances::fl::Date::monthSet;
typedef ThunkFunc1<Instances::fl::Date, 46, const Value, Value::Number> TFunc_Instances_fl_Date_dateSet;
// @0x14013c770
template <> const TFunc_Instances_fl_Date_dateSet::TMethod TFunc_Instances_fl_Date_dateSet::Method = &Instances::fl::Date::dateSet;
typedef ThunkFunc1<Instances::fl::Date, 48, const Value, Value::Number> TFunc_Instances_fl_Date_hoursSet;
// @0x14013c7a0
template <> const TFunc_Instances_fl_Date_hoursSet::TMethod TFunc_Instances_fl_Date_hoursSet::Method = &Instances::fl::Date::hoursSet;
typedef ThunkFunc1<Instances::fl::Date, 50, const Value, Value::Number> TFunc_Instances_fl_Date_minutesSet;
// @0x14013c7d0
template <> const TFunc_Instances_fl_Date_minutesSet::TMethod TFunc_Instances_fl_Date_minutesSet::Method = &Instances::fl::Date::minutesSet;
typedef ThunkFunc1<Instances::fl::Date, 52, const Value, Value::Number> TFunc_Instances_fl_Date_secondsSet;
// @0x14013c800
template <> const TFunc_Instances_fl_Date_secondsSet::TMethod TFunc_Instances_fl_Date_secondsSet::Method = &Instances::fl::Date::secondsSet;
typedef ThunkFunc1<Instances::fl::Date, 54, const Value, Value::Number> TFunc_Instances_fl_Date_millisecondsSet;
// @0x14013c830
template <> const TFunc_Instances_fl_Date_millisecondsSet::TMethod TFunc_Instances_fl_Date_millisecondsSet::Method = &Instances::fl::Date::millisecondsSet;
typedef ThunkFunc1<Instances::fl::Date, 56, const Value, Value::Number> TFunc_Instances_fl_Date_fullYearUTCSet;
// @0x14013c860
template <> const TFunc_Instances_fl_Date_fullYearUTCSet::TMethod TFunc_Instances_fl_Date_fullYearUTCSet::Method = &Instances::fl::Date::fullYearUTCSet;
typedef ThunkFunc1<Instances::fl::Date, 58, const Value, Value::Number> TFunc_Instances_fl_Date_monthUTCSet;
// @0x14013c890
template <> const TFunc_Instances_fl_Date_monthUTCSet::TMethod TFunc_Instances_fl_Date_monthUTCSet::Method = &Instances::fl::Date::monthUTCSet;
typedef ThunkFunc1<Instances::fl::Date, 60, const Value, Value::Number> TFunc_Instances_fl_Date_dateUTCSet;
// @0x14013c8c0
template <> const TFunc_Instances_fl_Date_dateUTCSet::TMethod TFunc_Instances_fl_Date_dateUTCSet::Method = &Instances::fl::Date::dateUTCSet;
typedef ThunkFunc1<Instances::fl::Date, 62, const Value, Value::Number> TFunc_Instances_fl_Date_hoursUTCSet;
// @0x14013c8f0
template <> const TFunc_Instances_fl_Date_hoursUTCSet::TMethod TFunc_Instances_fl_Date_hoursUTCSet::Method = &Instances::fl::Date::hoursUTCSet;
typedef ThunkFunc1<Instances::fl::Date, 64, const Value, Value::Number> TFunc_Instances_fl_Date_minutesUTCSet;
// @0x14013c920
template <> const TFunc_Instances_fl_Date_minutesUTCSet::TMethod TFunc_Instances_fl_Date_minutesUTCSet::Method = &Instances::fl::Date::minutesUTCSet;
typedef ThunkFunc1<Instances::fl::Date, 66, const Value, Value::Number> TFunc_Instances_fl_Date_secondsUTCSet;
// @0x14013c950
template <> const TFunc_Instances_fl_Date_secondsUTCSet::TMethod TFunc_Instances_fl_Date_secondsUTCSet::Method = &Instances::fl::Date::secondsUTCSet;
typedef ThunkFunc1<Instances::fl::Date, 68, const Value, Value::Number> TFunc_Instances_fl_Date_millisecondsUTCSet;
// @0x14013c980
template <> const TFunc_Instances_fl_Date_millisecondsUTCSet::TMethod TFunc_Instances_fl_Date_millisecondsUTCSet::Method = &Instances::fl::Date::millisecondsUTCSet;
typedef ThunkFunc1<Instances::fl::Date, 70, const Value, Value::Number> TFunc_Instances_fl_Date_timeSet;
// @0x14013c9b0
template <> const TFunc_Instances_fl_Date_timeSet::TMethod TFunc_Instances_fl_Date_timeSet::Method = &Instances::fl::Date::timeSet;
typedef ThunkFunc1<Classes::fl::Error, 0, ASString, SInt32> TFunc_Classes_fl_Error_getErrorMessage;
// @0x14013c9e0
template <> const TFunc_Classes_fl_Error_getErrorMessage::TMethod TFunc_Classes_fl_Error_getErrorMessage::Method = &Classes::fl::Error::getErrorMessage;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 0, ASString, const ASString&> TFunc_Instances_fl_GlobalObjectCPP_decodeURI;
// @0x14013ca10
template <> const TFunc_Instances_fl_GlobalObjectCPP_decodeURI::TMethod TFunc_Instances_fl_GlobalObjectCPP_decodeURI::Method = &Instances::fl::GlobalObjectCPP::decodeURI;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 1, ASString, const ASString&> TFunc_Instances_fl_GlobalObjectCPP_decodeURIComponent;
// @0x14013ca40
template <> const TFunc_Instances_fl_GlobalObjectCPP_decodeURIComponent::TMethod TFunc_Instances_fl_GlobalObjectCPP_decodeURIComponent::Method = &Instances::fl::GlobalObjectCPP::decodeURIComponent;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 2, ASString, const ASString&> TFunc_Instances_fl_GlobalObjectCPP_encodeURI;
// @0x14013ca70
template <> const TFunc_Instances_fl_GlobalObjectCPP_encodeURI::TMethod TFunc_Instances_fl_GlobalObjectCPP_encodeURI::Method = &Instances::fl::GlobalObjectCPP::encodeURI;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 3, ASString, const ASString&> TFunc_Instances_fl_GlobalObjectCPP_encodeURIComponent;
// @0x14013caa0
template <> const TFunc_Instances_fl_GlobalObjectCPP_encodeURIComponent::TMethod TFunc_Instances_fl_GlobalObjectCPP_encodeURIComponent::Method = &Instances::fl::GlobalObjectCPP::encodeURIComponent;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 4, bool, Value::Number> TFunc_Instances_fl_GlobalObjectCPP_isNaN;
// @0x14013cad0
template <> const TFunc_Instances_fl_GlobalObjectCPP_isNaN::TMethod TFunc_Instances_fl_GlobalObjectCPP_isNaN::Method = &Instances::fl::GlobalObjectCPP::isNaN;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 5, bool, Value::Number> TFunc_Instances_fl_GlobalObjectCPP_isFinite;
// @0x14013cb00
template <> const TFunc_Instances_fl_GlobalObjectCPP_isFinite::TMethod TFunc_Instances_fl_GlobalObjectCPP_isFinite::Method = &Instances::fl::GlobalObjectCPP::isFinite;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 7, Value::Number, const ASString&> TFunc_Instances_fl_GlobalObjectCPP_parseFloat;
// @0x14013cb30
template <> const TFunc_Instances_fl_GlobalObjectCPP_parseFloat::TMethod TFunc_Instances_fl_GlobalObjectCPP_parseFloat::Method = &Instances::fl::GlobalObjectCPP::parseFloat;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 10, bool, const Value&> TFunc_Instances_fl_GlobalObjectCPP_isXMLName;
// @0x14013cb60
template <> const TFunc_Instances_fl_GlobalObjectCPP_isXMLName::TMethod TFunc_Instances_fl_GlobalObjectCPP_isXMLName::Method = &Instances::fl::GlobalObjectCPP::isXMLName;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 13, const Value, UInt32> TFunc_Instances_fl_GlobalObjectCPP_clearInterval;
// @0x14013cb90
template <> const TFunc_Instances_fl_GlobalObjectCPP_clearInterval::TMethod TFunc_Instances_fl_GlobalObjectCPP_clearInterval::Method = &Instances::fl::GlobalObjectCPP::clearInterval;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 14, const Value, UInt32> TFunc_Instances_fl_GlobalObjectCPP_clearTimeout;
// @0x14013cbc0
template <> const TFunc_Instances_fl_GlobalObjectCPP_clearTimeout::TMethod TFunc_Instances_fl_GlobalObjectCPP_clearTimeout::Method = &Instances::fl::GlobalObjectCPP::clearTimeout;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 15, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_GlobalObjectCPP_describeType;
// @0x14013cbf0
template <> const TFunc_Instances_fl_GlobalObjectCPP_describeType::TMethod TFunc_Instances_fl_GlobalObjectCPP_describeType::Method = &Instances::fl::GlobalObjectCPP::describeType;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 16, ASString, const ASString&> TFunc_Instances_fl_GlobalObjectCPP_escapeMultiByte;
// @0x14013cc20
template <> const TFunc_Instances_fl_GlobalObjectCPP_escapeMultiByte::TMethod TFunc_Instances_fl_GlobalObjectCPP_escapeMultiByte::Method = &Instances::fl::GlobalObjectCPP::escapeMultiByte;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 17, Value, const ASString&> TFunc_Instances_fl_GlobalObjectCPP_getDefinitionByName;
// @0x14013cc50
template <> const TFunc_Instances_fl_GlobalObjectCPP_getDefinitionByName::TMethod TFunc_Instances_fl_GlobalObjectCPP_getDefinitionByName::Method = &Instances::fl::GlobalObjectCPP::getDefinitionByName;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 18, ASString, const Value&> TFunc_Instances_fl_GlobalObjectCPP_getQualifiedClassName;
// @0x14013cc80
template <> const TFunc_Instances_fl_GlobalObjectCPP_getQualifiedClassName::TMethod TFunc_Instances_fl_GlobalObjectCPP_getQualifiedClassName::Method = &Instances::fl::GlobalObjectCPP::getQualifiedClassName;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 19, Value, const Value&> TFunc_Instances_fl_GlobalObjectCPP_getQualifiedSuperclassName;
// @0x14013ccb0
template <> const TFunc_Instances_fl_GlobalObjectCPP_getQualifiedSuperclassName::TMethod TFunc_Instances_fl_GlobalObjectCPP_getQualifiedSuperclassName::Method = &Instances::fl::GlobalObjectCPP::getQualifiedSuperclassName;
typedef ThunkFunc1<Instances::fl::GlobalObjectCPP, 23, ASString, const ASString&> TFunc_Instances_fl_GlobalObjectCPP_unescapeMultiByte;
// @0x14013cce0
template <> const TFunc_Instances_fl_GlobalObjectCPP_unescapeMultiByte::TMethod TFunc_Instances_fl_GlobalObjectCPP_unescapeMultiByte::Method = &Instances::fl::GlobalObjectCPP::unescapeMultiByte;
typedef ThunkFunc1<Classes::fl::Math, 1, Value::Number, Value::Number> TFunc_Classes_fl_Math_acos;
// @0x14013cd10
template <> const TFunc_Classes_fl_Math_acos::TMethod TFunc_Classes_fl_Math_acos::Method = &Classes::fl::Math::acos;
typedef ThunkFunc1<Classes::fl::Math, 2, Value::Number, Value::Number> TFunc_Classes_fl_Math_asin;
// @0x14013cd40
template <> const TFunc_Classes_fl_Math_asin::TMethod TFunc_Classes_fl_Math_asin::Method = &Classes::fl::Math::asin;
typedef ThunkFunc1<Classes::fl::Math, 3, Value::Number, Value::Number> TFunc_Classes_fl_Math_atan;
// @0x14013cd70
template <> const TFunc_Classes_fl_Math_atan::TMethod TFunc_Classes_fl_Math_atan::Method = &Classes::fl::Math::atan;
typedef ThunkFunc1<Classes::fl::Math, 5, Value::Number, Value::Number> TFunc_Classes_fl_Math_ceil;
// @0x14013cda0
template <> const TFunc_Classes_fl_Math_ceil::TMethod TFunc_Classes_fl_Math_ceil::Method = &Classes::fl::Math::ceil;
typedef ThunkFunc1<Classes::fl::Math, 6, Value::Number, Value::Number> TFunc_Classes_fl_Math_cos;
// @0x14013cdd0
template <> const TFunc_Classes_fl_Math_cos::TMethod TFunc_Classes_fl_Math_cos::Method = &Classes::fl::Math::cos;
typedef ThunkFunc1<Classes::fl::Math, 7, Value::Number, Value::Number> TFunc_Classes_fl_Math_exp;
// @0x14013ce00
template <> const TFunc_Classes_fl_Math_exp::TMethod TFunc_Classes_fl_Math_exp::Method = &Classes::fl::Math::exp;
typedef ThunkFunc1<Classes::fl::Math, 8, Value::Number, Value::Number> TFunc_Classes_fl_Math_floor;
// @0x14013ce30
template <> const TFunc_Classes_fl_Math_floor::TMethod TFunc_Classes_fl_Math_floor::Method = &Classes::fl::Math::floor;
typedef ThunkFunc1<Classes::fl::Math, 9, Value::Number, Value::Number> TFunc_Classes_fl_Math_log;
// @0x14013ce60
template <> const TFunc_Classes_fl_Math_log::TMethod TFunc_Classes_fl_Math_log::Method = &Classes::fl::Math::log;
typedef ThunkFunc1<Classes::fl::Math, 10, Value::Number, Value::Number> TFunc_Classes_fl_Math_round;
// @0x14013ce90
template <> const TFunc_Classes_fl_Math_round::TMethod TFunc_Classes_fl_Math_round::Method = &Classes::fl::Math::round;
typedef ThunkFunc1<Classes::fl::Math, 0, Value::Number, Value::Number> TFunc_Classes_fl_Math_abs;
// @0x14013cec0
template <> const TFunc_Classes_fl_Math_abs::TMethod TFunc_Classes_fl_Math_abs::Method = &Classes::fl::Math::abs;
typedef ThunkFunc1<Classes::fl::Math, 11, Value::Number, Value::Number> TFunc_Classes_fl_Math_sin;
// @0x14013cef0
template <> const TFunc_Classes_fl_Math_sin::TMethod TFunc_Classes_fl_Math_sin::Method = &Classes::fl::Math::sin;
typedef ThunkFunc1<Classes::fl::Math, 12, Value::Number, Value::Number> TFunc_Classes_fl_Math_sqrt;
// @0x14013cf20
template <> const TFunc_Classes_fl_Math_sqrt::TMethod TFunc_Classes_fl_Math_sqrt::Method = &Classes::fl::Math::sqrt;
typedef ThunkFunc1<Classes::fl::Math, 13, Value::Number, Value::Number> TFunc_Classes_fl_Math_tan;
// @0x14013cf50
template <> const TFunc_Classes_fl_Math_tan::TMethod TFunc_Classes_fl_Math_tan::Method = &Classes::fl::Math::tan;
typedef ThunkFunc1<Instances::fl::RegExp, 5, const Value, SInt32> TFunc_Instances_fl_RegExp_lastIndexSet;
// @0x14013cf80
template <> const TFunc_Instances_fl_RegExp_lastIndexSet::TMethod TFunc_Instances_fl_RegExp_lastIndexSet::Method = &Instances::fl::RegExp::lastIndexSet;
typedef ThunkFunc1<Instances::fl::RegExp, 8, SPtr<Instances::fl::Object>, const ASString&> TFunc_Instances_fl_RegExp_AS3exec;
// @0x14013cfb0
template <> const TFunc_Instances_fl_RegExp_AS3exec::TMethod TFunc_Instances_fl_RegExp_AS3exec::Method = &Instances::fl::RegExp::AS3exec;
typedef ThunkFunc1<Instances::fl::RegExp, 9, bool, const ASString&> TFunc_Instances_fl_RegExp_AS3test;
// @0x14013cfe0
template <> const TFunc_Instances_fl_RegExp_AS3test::TMethod TFunc_Instances_fl_RegExp_AS3test::Method = &Instances::fl::RegExp::AS3test;
typedef ThunkFunc1<Classes::fl::XML, 2, const Value, const Value&> TFunc_Classes_fl_XML_AS3setSettings;
// @0x14013d010
template <> const TFunc_Classes_fl_XML_AS3setSettings::TMethod TFunc_Classes_fl_XML_AS3setSettings::Method = &Classes::fl::XML::AS3setSettings;
typedef ThunkFunc1<Classes::fl::XML, 3, const Value, const Value&> TFunc_Classes_fl_XML_setSettings;
// @0x14013d040
template <> const TFunc_Classes_fl_XML_setSettings::TMethod TFunc_Classes_fl_XML_setSettings::Method = &Classes::fl::XML::setSettings;
typedef ThunkFunc1<Instances::fl::XML, 1, const Value, const Value&> TFunc_Instances_fl_XML_prototypeSet;
// @0x14013d070
template <> const TFunc_Instances_fl_XML_prototypeSet::TMethod TFunc_Instances_fl_XML_prototypeSet::Method = &Instances::fl::XML::prototypeSet;
typedef ThunkFunc1<Instances::fl::XML, 3, bool, const ASString&> TFunc_Instances_fl_XML_AS3hasOwnProperty;
// @0x14013d0a0
template <> const TFunc_Instances_fl_XML_AS3hasOwnProperty::TMethod TFunc_Instances_fl_XML_AS3hasOwnProperty::Method = &Instances::fl::XML::AS3hasOwnProperty;
typedef ThunkFunc1<Instances::fl::XML, 5, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XML_AS3addNamespace;
// @0x14013d0d0
template <> const TFunc_Instances_fl_XML_AS3addNamespace::TMethod TFunc_Instances_fl_XML_AS3addNamespace::Method = &Instances::fl::XML::AS3addNamespace;
typedef ThunkFunc1<Instances::fl::XML, 6, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XML_AS3appendChild;
// @0x14013d100
template <> const TFunc_Instances_fl_XML_AS3appendChild::TMethod TFunc_Instances_fl_XML_AS3appendChild::Method = &Instances::fl::XML::AS3appendChild;
typedef ThunkFunc1<Instances::fl::XML, 7, SPtr<Instances::fl::XMLList>, const Value&> TFunc_Instances_fl_XML_AS3attribute;
// @0x14013d130
template <> const TFunc_Instances_fl_XML_AS3attribute::TMethod TFunc_Instances_fl_XML_AS3attribute::Method = &Instances::fl::XML::AS3attribute;
typedef ThunkFunc1<Instances::fl::XML, 9, SPtr<Instances::fl::XMLList>, const Value&> TFunc_Instances_fl_XML_AS3child;
// @0x14013d160
template <> const TFunc_Instances_fl_XML_AS3child::TMethod TFunc_Instances_fl_XML_AS3child::Method = &Instances::fl::XML::AS3child;
typedef ThunkFunc1<Instances::fl::XML, 31, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XML_AS3prependChild;
// @0x14013d190
template <> const TFunc_Instances_fl_XML_AS3prependChild::TMethod TFunc_Instances_fl_XML_AS3prependChild::Method = &Instances::fl::XML::AS3prependChild;
typedef ThunkFunc1<Instances::fl::XML, 32, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XML_AS3removeNamespace;
// @0x14013d1c0
template <> const TFunc_Instances_fl_XML_AS3removeNamespace::TMethod TFunc_Instances_fl_XML_AS3removeNamespace::Method = &Instances::fl::XML::AS3removeNamespace;
typedef ThunkFunc1<Instances::fl::XML, 34, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XML_AS3setChildren;
// @0x14013d1f0
template <> const TFunc_Instances_fl_XML_AS3setChildren::TMethod TFunc_Instances_fl_XML_AS3setChildren::Method = &Instances::fl::XML::AS3setChildren;
typedef ThunkFunc1<Instances::fl::XML, 35, const Value, const Value&> TFunc_Instances_fl_XML_AS3setLocalName;
// @0x14013d220
template <> const TFunc_Instances_fl_XML_AS3setLocalName::TMethod TFunc_Instances_fl_XML_AS3setLocalName::Method = &Instances::fl::XML::AS3setLocalName;
typedef ThunkFunc1<Instances::fl::XML, 36, const Value, const Value&> TFunc_Instances_fl_XML_AS3setName;
// @0x14013d250
template <> const TFunc_Instances_fl_XML_AS3setName::TMethod TFunc_Instances_fl_XML_AS3setName::Method = &Instances::fl::XML::AS3setName;
typedef ThunkFunc1<Instances::fl::XML, 37, const Value, const Value&> TFunc_Instances_fl_XML_AS3setNamespace;
// @0x14013d280
template <> const TFunc_Instances_fl_XML_AS3setNamespace::TMethod TFunc_Instances_fl_XML_AS3setNamespace::Method = &Instances::fl::XML::AS3setNamespace;
typedef ThunkFunc1<Instances::fl::XML, 13, bool, const Value&> TFunc_Instances_fl_XML_AS3contains;
// @0x14013d2b0
template <> const TFunc_Instances_fl_XML_AS3contains::TMethod TFunc_Instances_fl_XML_AS3contains::Method = &Instances::fl::XML::AS3contains;
typedef ThunkFunc1<Instances::fl::XMLList, 1, const Value, const Value&> TFunc_Instances_fl_XMLList_prototypeSet;
// @0x14013d2e0
template <> const TFunc_Instances_fl_XMLList_prototypeSet::TMethod TFunc_Instances_fl_XMLList_prototypeSet::Method = &Instances::fl::XMLList::prototypeSet;
typedef ThunkFunc1<Instances::fl::XMLList, 7, SPtr<Instances::fl::XMLList>, const Value&> TFunc_Instances_fl_XMLList_AS3attribute;
// @0x14013d310
template <> const TFunc_Instances_fl_XMLList_AS3attribute::TMethod TFunc_Instances_fl_XMLList_AS3attribute::Method = &Instances::fl::XMLList::AS3attribute;
typedef ThunkFunc1<Instances::fl::XMLList, 9, SPtr<Instances::fl::XMLList>, const Value&> TFunc_Instances_fl_XMLList_AS3child;
// @0x14013d340
template <> const TFunc_Instances_fl_XMLList_AS3child::TMethod TFunc_Instances_fl_XMLList_AS3child::Method = &Instances::fl::XMLList::AS3child;
typedef ThunkFunc1<Instances::fl::XMLList, 24, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XMLList_AS3addNamespace;
// @0x14013d370
template <> const TFunc_Instances_fl_XMLList_AS3addNamespace::TMethod TFunc_Instances_fl_XMLList_AS3addNamespace::Method = &Instances::fl::XMLList::AS3addNamespace;
typedef ThunkFunc1<Instances::fl::XMLList, 25, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XMLList_AS3appendChild;
// @0x14013d3a0
template <> const TFunc_Instances_fl_XMLList_AS3appendChild::TMethod TFunc_Instances_fl_XMLList_AS3appendChild::Method = &Instances::fl::XMLList::AS3appendChild;
typedef ThunkFunc1<Instances::fl::XMLList, 34, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XMLList_AS3prependChild;
// @0x14013d3d0
template <> const TFunc_Instances_fl_XMLList_AS3prependChild::TMethod TFunc_Instances_fl_XMLList_AS3prependChild::Method = &Instances::fl::XMLList::AS3prependChild;
typedef ThunkFunc1<Instances::fl::XMLList, 35, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XMLList_AS3removeNamespace;
// @0x14013d400
template <> const TFunc_Instances_fl_XMLList_AS3removeNamespace::TMethod TFunc_Instances_fl_XMLList_AS3removeNamespace::Method = &Instances::fl::XMLList::AS3removeNamespace;
typedef ThunkFunc1<Instances::fl::XMLList, 37, SPtr<Instances::fl::XML>, const Value&> TFunc_Instances_fl_XMLList_AS3setChildren;
// @0x14013d430
template <> const TFunc_Instances_fl_XMLList_AS3setChildren::TMethod TFunc_Instances_fl_XMLList_AS3setChildren::Method = &Instances::fl::XMLList::AS3setChildren;
typedef ThunkFunc1<Instances::fl::XMLList, 38, const Value, const Value&> TFunc_Instances_fl_XMLList_AS3setLocalName;
// @0x14013d460
template <> const TFunc_Instances_fl_XMLList_AS3setLocalName::TMethod TFunc_Instances_fl_XMLList_AS3setLocalName::Method = &Instances::fl::XMLList::AS3setLocalName;
typedef ThunkFunc1<Instances::fl::XMLList, 39, const Value, const Value&> TFunc_Instances_fl_XMLList_AS3setName;
// @0x14013d490
template <> const TFunc_Instances_fl_XMLList_AS3setName::TMethod TFunc_Instances_fl_XMLList_AS3setName::Method = &Instances::fl::XMLList::AS3setName;
typedef ThunkFunc1<Instances::fl::XMLList, 40, const Value, const Value&> TFunc_Instances_fl_XMLList_AS3setNamespace;
// @0x14013d4c0
template <> const TFunc_Instances_fl_XMLList_AS3setNamespace::TMethod TFunc_Instances_fl_XMLList_AS3setNamespace::Method = &Instances::fl::XMLList::AS3setNamespace;
typedef ThunkFunc1<Instances::fl::XMLList, 12, bool, const Value&> TFunc_Instances_fl_XMLList_AS3contains;
// @0x14013d4f0
template <> const TFunc_Instances_fl_XMLList_AS3contains::TMethod TFunc_Instances_fl_XMLList_AS3contains::Method = &Instances::fl::XMLList::AS3contains;
typedef ThunkFunc2<Instances::fl::Array, 2, Value, unsigned, const Value*> TFunc_Instances_fl_Array_AS3join;
// @0x14013d520
template <> const TFunc_Instances_fl_Array_AS3join::TMethod TFunc_Instances_fl_Array_AS3join::Method = &Instances::fl::Array::AS3join;
typedef ThunkFunc2<Instances::fl::Array, 4, Value, unsigned, const Value*> TFunc_Instances_fl_Array_AS3push;
// @0x14013d550
template <> const TFunc_Instances_fl_Array_AS3push::TMethod TFunc_Instances_fl_Array_AS3push::Method = &Instances::fl::Array::AS3push;
typedef ThunkFunc2<Instances::fl::Array, 6, Value, unsigned, const Value*> TFunc_Instances_fl_Array_AS3concat;
// @0x14013d580
template <> const TFunc_Instances_fl_Array_AS3concat::TMethod TFunc_Instances_fl_Array_AS3concat::Method = &Instances::fl::Array::AS3concat;
typedef ThunkFunc2<Instances::fl::Array, 8, SPtr<Instances::fl::Array>, SInt32, SInt32> TFunc_Instances_fl_Array_AS3slice;
// @0x14013d5b0
template <> const TFunc_Instances_fl_Array_AS3slice::TMethod TFunc_Instances_fl_Array_AS3slice::Method = &Instances::fl::Array::AS3slice;
typedef ThunkFunc2<Instances::fl::Array, 9, Value, unsigned, const Value*> TFunc_Instances_fl_Array_AS3unshift;
// @0x14013d5e0
template <> const TFunc_Instances_fl_Array_AS3unshift::TMethod TFunc_Instances_fl_Array_AS3unshift::Method = &Instances::fl::Array::AS3unshift;
typedef ThunkFunc2<Instances::fl::Array, 10, Value, unsigned, const Value*> TFunc_Instances_fl_Array_AS3splice;
// @0x14013d610
template <> const TFunc_Instances_fl_Array_AS3splice::TMethod TFunc_Instances_fl_Array_AS3splice::Method = &Instances::fl::Array::AS3splice;
typedef ThunkFunc2<Instances::fl::Array, 16, SPtr<Instances::fl::Array>, const Value&, const Value&> TFunc_Instances_fl_Array_AS3filter;
// @0x14013d640
template <> const TFunc_Instances_fl_Array_AS3filter::TMethod TFunc_Instances_fl_Array_AS3filter::Method = &Instances::fl::Array::AS3filter;
typedef ThunkFunc2<Instances::fl::Array, 17, const Value, const Value&, const Value&> TFunc_Instances_fl_Array_AS3forEach;
// @0x14013d670
template <> const TFunc_Instances_fl_Array_AS3forEach::TMethod TFunc_Instances_fl_Array_AS3forEach::Method = &Instances::fl::Array::AS3forEach;
typedef ThunkFunc2<Instances::fl::Array, 18, SPtr<Instances::fl::Array>, const Value&, const Value&> TFunc_Instances_fl_Array_AS3map;
// @0x14013d6a0
template <> const TFunc_Instances_fl_Array_AS3map::TMethod TFunc_Instances_fl_Array_AS3map::Method = &Instances::fl::Array::AS3map;
typedef ThunkFunc2<Instances::fl::Array, 19, bool, const Value&, const Value&> TFunc_Instances_fl_Array_AS3some;
// @0x14013d6d0
template <> const TFunc_Instances_fl_Array_AS3some::TMethod TFunc_Instances_fl_Array_AS3some::Method = &Instances::fl::Array::AS3some;
typedef ThunkFunc2<Instances::fl::Array, 11, Value, unsigned, const Value*> TFunc_Instances_fl_Array_AS3sort;
// @0x14013d700
template <> const TFunc_Instances_fl_Array_AS3sort::TMethod TFunc_Instances_fl_Array_AS3sort::Method = &Instances::fl::Array::AS3sort;
typedef ThunkFunc2<Instances::fl::Array, 12, SPtr<Instances::fl::Array>, const Value&, const Value&> TFunc_Instances_fl_Array_AS3sortOn;
// @0x14013d730
template <> const TFunc_Instances_fl_Array_AS3sortOn::TMethod TFunc_Instances_fl_Array_AS3sortOn::Method = &Instances::fl::Array::AS3sortOn;
typedef ThunkFunc2<Instances::fl::Array, 13, SInt32, const Value&, SInt32> TFunc_Instances_fl_Array_AS3indexOf;
// @0x14013d760
template <> const TFunc_Instances_fl_Array_AS3indexOf::TMethod TFunc_Instances_fl_Array_AS3indexOf::Method = &Instances::fl::Array::AS3indexOf;
typedef ThunkFunc2<Instances::fl::Array, 14, SInt32, const Value&, SInt32> TFunc_Instances_fl_Array_AS3lastIndexOf;
// @0x14013d790
template <> const TFunc_Instances_fl_Array_AS3lastIndexOf::TMethod TFunc_Instances_fl_Array_AS3lastIndexOf::Method = &Instances::fl::Array::AS3lastIndexOf;
typedef ThunkFunc2<Instances::fl::Array, 15, bool, const Value&, const Value&> TFunc_Instances_fl_Array_AS3every;
// @0x14013d7c0
template <> const TFunc_Instances_fl_Array_AS3every::TMethod TFunc_Instances_fl_Array_AS3every::Method = &Instances::fl::Array::AS3every;
typedef ThunkFunc2<Classes::fl::Date, 1, Value, unsigned, const Value*> TFunc_Classes_fl_Date_UTC;
// @0x14013d7f0
template <> const TFunc_Classes_fl_Date_UTC::TMethod TFunc_Classes_fl_Date_UTC::Method = &Classes::fl::Date::UTC;
typedef ThunkFunc2<Instances::fl::Date, 27, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setFullYear;
// @0x14013d820
template <> const TFunc_Instances_fl_Date_AS3setFullYear::TMethod TFunc_Instances_fl_Date_AS3setFullYear::Method = &Instances::fl::Date::AS3setFullYear;
typedef ThunkFunc2<Instances::fl::Date, 28, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setMonth;
// @0x14013d850
template <> const TFunc_Instances_fl_Date_AS3setMonth::TMethod TFunc_Instances_fl_Date_AS3setMonth::Method = &Instances::fl::Date::AS3setMonth;
typedef ThunkFunc2<Instances::fl::Date, 29, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setDate;
// @0x14013d880
template <> const TFunc_Instances_fl_Date_AS3setDate::TMethod TFunc_Instances_fl_Date_AS3setDate::Method = &Instances::fl::Date::AS3setDate;
typedef ThunkFunc2<Instances::fl::Date, 30, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setHours;
// @0x14013d8b0
template <> const TFunc_Instances_fl_Date_AS3setHours::TMethod TFunc_Instances_fl_Date_AS3setHours::Method = &Instances::fl::Date::AS3setHours;
typedef ThunkFunc2<Instances::fl::Date, 31, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setMinutes;
// @0x14013d8e0
template <> const TFunc_Instances_fl_Date_AS3setMinutes::TMethod TFunc_Instances_fl_Date_AS3setMinutes::Method = &Instances::fl::Date::AS3setMinutes;
typedef ThunkFunc2<Instances::fl::Date, 32, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setSeconds;
// @0x14013d910
template <> const TFunc_Instances_fl_Date_AS3setSeconds::TMethod TFunc_Instances_fl_Date_AS3setSeconds::Method = &Instances::fl::Date::AS3setSeconds;
typedef ThunkFunc2<Instances::fl::Date, 33, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setMilliseconds;
// @0x14013d940
template <> const TFunc_Instances_fl_Date_AS3setMilliseconds::TMethod TFunc_Instances_fl_Date_AS3setMilliseconds::Method = &Instances::fl::Date::AS3setMilliseconds;
typedef ThunkFunc2<Instances::fl::Date, 34, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setUTCFullYear;
// @0x14013d970
template <> const TFunc_Instances_fl_Date_AS3setUTCFullYear::TMethod TFunc_Instances_fl_Date_AS3setUTCFullYear::Method = &Instances::fl::Date::AS3setUTCFullYear;
typedef ThunkFunc2<Instances::fl::Date, 35, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setUTCMonth;
// @0x14013d9a0
template <> const TFunc_Instances_fl_Date_AS3setUTCMonth::TMethod TFunc_Instances_fl_Date_AS3setUTCMonth::Method = &Instances::fl::Date::AS3setUTCMonth;
typedef ThunkFunc2<Instances::fl::Date, 36, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setUTCDate;
// @0x14013d9d0
template <> const TFunc_Instances_fl_Date_AS3setUTCDate::TMethod TFunc_Instances_fl_Date_AS3setUTCDate::Method = &Instances::fl::Date::AS3setUTCDate;
typedef ThunkFunc2<Instances::fl::Date, 37, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setUTCHours;
// @0x14013da00
template <> const TFunc_Instances_fl_Date_AS3setUTCHours::TMethod TFunc_Instances_fl_Date_AS3setUTCHours::Method = &Instances::fl::Date::AS3setUTCHours;
typedef ThunkFunc2<Instances::fl::Date, 38, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setUTCMinutes;
// @0x14013da30
template <> const TFunc_Instances_fl_Date_AS3setUTCMinutes::TMethod TFunc_Instances_fl_Date_AS3setUTCMinutes::Method = &Instances::fl::Date::AS3setUTCMinutes;
typedef ThunkFunc2<Instances::fl::Date, 39, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setUTCSeconds;
// @0x14013da60
template <> const TFunc_Instances_fl_Date_AS3setUTCSeconds::TMethod TFunc_Instances_fl_Date_AS3setUTCSeconds::Method = &Instances::fl::Date::AS3setUTCSeconds;
typedef ThunkFunc2<Instances::fl::Date, 40, Value, unsigned, const Value*> TFunc_Instances_fl_Date_AS3setUTCMilliseconds;
// @0x14013da90
template <> const TFunc_Instances_fl_Date_AS3setUTCMilliseconds::TMethod TFunc_Instances_fl_Date_AS3setUTCMilliseconds::Method = &Instances::fl::Date::AS3setUTCMilliseconds;
typedef ThunkFunc2<Classes::fl::Error, 1, Value, unsigned, const Value*> TFunc_Classes_fl_Error_throwError;
// @0x14013dac0
template <> const TFunc_Classes_fl_Error_throwError::TMethod TFunc_Classes_fl_Error_throwError::Method = &Classes::fl::Error::throwError;
typedef ThunkFunc2<Instances::fl::GlobalObjectCPP, 6, Value, unsigned, const Value*> TFunc_Instances_fl_GlobalObjectCPP_parseInt;
// @0x14013daf0
template <> const TFunc_Instances_fl_GlobalObjectCPP_parseInt::TMethod TFunc_Instances_fl_GlobalObjectCPP_parseInt::Method = &Instances::fl::GlobalObjectCPP::parseInt;
typedef ThunkFunc2<Instances::fl::GlobalObjectCPP, 8, Value, unsigned, const Value*> TFunc_Instances_fl_GlobalObjectCPP_escape;
// @0x14013db20
template <> const TFunc_Instances_fl_GlobalObjectCPP_escape::TMethod TFunc_Instances_fl_GlobalObjectCPP_escape::Method = &Instances::fl::GlobalObjectCPP::escape;
typedef ThunkFunc2<Instances::fl::GlobalObjectCPP, 9, Value, unsigned, const Value*> TFunc_Instances_fl_GlobalObjectCPP_unescape;
// @0x14013db50
template <> const TFunc_Instances_fl_GlobalObjectCPP_unescape::TMethod TFunc_Instances_fl_GlobalObjectCPP_unescape::Method = &Instances::fl::GlobalObjectCPP::unescape;
typedef ThunkFunc2<Instances::fl::GlobalObjectCPP, 11, Value, unsigned, const Value*> TFunc_Instances_fl_GlobalObjectCPP_trace;
// @0x14013db80
template <> const TFunc_Instances_fl_GlobalObjectCPP_trace::TMethod TFunc_Instances_fl_GlobalObjectCPP_trace::Method = &Instances::fl::GlobalObjectCPP::trace;
typedef ThunkFunc2<Instances::fl::GlobalObjectCPP, 12, Value, unsigned, const Value*> TFunc_Instances_fl_GlobalObjectCPP_print;
// @0x14013dbb0
template <> const TFunc_Instances_fl_GlobalObjectCPP_print::TMethod TFunc_Instances_fl_GlobalObjectCPP_print::Method = &Instances::fl::GlobalObjectCPP::print;
typedef ThunkFunc2<Instances::fl::GlobalObjectCPP, 30, Value, unsigned, const Value*> TFunc_Instances_fl_GlobalObjectCPP_fscommand;
// @0x14013dbe0
template <> const TFunc_Instances_fl_GlobalObjectCPP_fscommand::TMethod TFunc_Instances_fl_GlobalObjectCPP_fscommand::Method = &Instances::fl::GlobalObjectCPP::fscommand;
typedef ThunkFunc2<Instances::fl::GlobalObjectCPP, 21, Value, unsigned, const Value*> TFunc_Instances_fl_GlobalObjectCPP_setInterval;
// @0x14013dc10
template <> const TFunc_Instances_fl_GlobalObjectCPP_setInterval::TMethod TFunc_Instances_fl_GlobalObjectCPP_setInterval::Method = &Instances::fl::GlobalObjectCPP::setInterval;
typedef ThunkFunc2<Instances::fl::GlobalObjectCPP, 22, Value, unsigned, const Value*> TFunc_Instances_fl_GlobalObjectCPP_setTimeout;
// @0x14013dc40
template <> const TFunc_Instances_fl_GlobalObjectCPP_setTimeout::TMethod TFunc_Instances_fl_GlobalObjectCPP_setTimeout::Method = &Instances::fl::GlobalObjectCPP::setTimeout;
typedef ThunkFunc2<Classes::fl::Math, 4, Value::Number, Value::Number, Value::Number> TFunc_Classes_fl_Math_atan2;
// @0x14013dc70
template <> const TFunc_Classes_fl_Math_atan2::TMethod TFunc_Classes_fl_Math_atan2::Method = &Classes::fl::Math::atan2;
typedef ThunkFunc2<Classes::fl::Math, 16, Value, unsigned, const Value*> TFunc_Classes_fl_Math_min;
// @0x14013dca0
template <> const TFunc_Classes_fl_Math_min::TMethod TFunc_Classes_fl_Math_min::Method = &Classes::fl::Math::min;
typedef ThunkFunc2<Classes::fl::Math, 14, Value::Number, Value::Number, Value::Number> TFunc_Classes_fl_Math_pow;
// @0x14013dcd0
template <> const TFunc_Classes_fl_Math_pow::TMethod TFunc_Classes_fl_Math_pow::Method = &Classes::fl::Math::pow;
typedef ThunkFunc2<Classes::fl::Math, 15, Value, unsigned, const Value*> TFunc_Classes_fl_Math_max;
// @0x14013dd00
template <> const TFunc_Classes_fl_Math_max::TMethod TFunc_Classes_fl_Math_max::Method = &Classes::fl::Math::max;
typedef ThunkFunc2<Classes::fl::String, 1, Value, unsigned, const Value*> TFunc_Classes_fl_String_fromCharCode;
// @0x14013dd30
template <> const TFunc_Classes_fl_String_fromCharCode::TMethod TFunc_Classes_fl_String_fromCharCode::Method = &Classes::fl::String::fromCharCode;
typedef ThunkFunc2<Classes::fl::String, 0, Value, unsigned, const Value*> TFunc_Classes_fl_String_AS3fromCharCode;
// @0x14013dd60
template <> const TFunc_Classes_fl_String_AS3fromCharCode::TMethod TFunc_Classes_fl_String_AS3fromCharCode::Method = &Classes::fl::String::AS3fromCharCode;
typedef ThunkFunc2<Instances::ThunkFunction, 0, Value, unsigned, const Value*> TFunc_Instances_ThunkFunction_length;
// @0x14013dd90
template <> const TFunc_Instances_ThunkFunction_length::TMethod TFunc_Instances_ThunkFunction_length::Method = &Instances::ThunkFunction::length;
typedef ThunkFunc2<Instances::fl::XML, 4, Value, unsigned, const Value*> TFunc_Instances_fl_XML_AS3propertyIsEnumerable;
// @0x14013ddc0
template <> const TFunc_Instances_fl_XML_AS3propertyIsEnumerable::TMethod TFunc_Instances_fl_XML_AS3propertyIsEnumerable::Method = &Instances::fl::XML::AS3propertyIsEnumerable;
typedef ThunkFunc2<Instances::fl::XML, 16, Value, unsigned, const Value*> TFunc_Instances_fl_XML_AS3elements;
// @0x14013ddf0
template <> const TFunc_Instances_fl_XML_AS3elements::TMethod TFunc_Instances_fl_XML_AS3elements::Method = &Instances::fl::XML::AS3elements;
typedef ThunkFunc2<Instances::fl::XML, 20, Value, const Value&, const Value&> TFunc_Instances_fl_XML_AS3insertChildAfter;
// @0x14013de20
template <> const TFunc_Instances_fl_XML_AS3insertChildAfter::TMethod TFunc_Instances_fl_XML_AS3insertChildAfter::Method = &Instances::fl::XML::AS3insertChildAfter;
typedef ThunkFunc2<Instances::fl::XML, 21, Value, const Value&, const Value&> TFunc_Instances_fl_XML_AS3insertChildBefore;
// @0x14013de50
template <> const TFunc_Instances_fl_XML_AS3insertChildBefore::TMethod TFunc_Instances_fl_XML_AS3insertChildBefore::Method = &Instances::fl::XML::AS3insertChildBefore;
typedef ThunkFunc2<Instances::fl::XML, 25, Value, unsigned, const Value*> TFunc_Instances_fl_XML_AS3namespace_;
// @0x14013de80
template <> const TFunc_Instances_fl_XML_AS3namespace_::TMethod TFunc_Instances_fl_XML_AS3namespace_::Method = &Instances::fl::XML::AS3namespace_;
typedef ThunkFunc2<Instances::fl::XML, 30, Value, unsigned, const Value*> TFunc_Instances_fl_XML_AS3processingInstructions;
// @0x14013deb0
template <> const TFunc_Instances_fl_XML_AS3processingInstructions::TMethod TFunc_Instances_fl_XML_AS3processingInstructions::Method = &Instances::fl::XML::AS3processingInstructions;
typedef ThunkFunc2<Instances::fl::XML, 33, SPtr<Instances::fl::XML>, const Value&, const Value&> TFunc_Instances_fl_XML_AS3replace;
// @0x14013dee0
template <> const TFunc_Instances_fl_XML_AS3replace::TMethod TFunc_Instances_fl_XML_AS3replace::Method = &Instances::fl::XML::AS3replace;
typedef ThunkFunc2<Instances::fl::XML, 15, Value, unsigned, const Value*> TFunc_Instances_fl_XML_AS3descendants;
// @0x14013df10
template <> const TFunc_Instances_fl_XML_AS3descendants::TMethod TFunc_Instances_fl_XML_AS3descendants::Method = &Instances::fl::XML::AS3descendants;
typedef ThunkFunc2<Instances::fl::XMLList, 6, Value, unsigned, const Value*> TFunc_Instances_fl_XMLList_AS3propertyIsEnumerable;
// @0x14013df40
template <> const TFunc_Instances_fl_XMLList_AS3propertyIsEnumerable::TMethod TFunc_Instances_fl_XMLList_AS3propertyIsEnumerable::Method = &Instances::fl::XMLList::AS3propertyIsEnumerable;
typedef ThunkFunc2<Instances::fl::XMLList, 21, Value, unsigned, const Value*> TFunc_Instances_fl_XMLList_AS3processingInstructions;
// @0x14013df70
template <> const TFunc_Instances_fl_XMLList_AS3processingInstructions::TMethod TFunc_Instances_fl_XMLList_AS3processingInstructions::Method = &Instances::fl::XMLList::AS3processingInstructions;
typedef ThunkFunc2<Instances::fl::XMLList, 28, Value, const Value&, const Value&> TFunc_Instances_fl_XMLList_AS3insertChildAfter;
// @0x14013dfa0
template <> const TFunc_Instances_fl_XMLList_AS3insertChildAfter::TMethod TFunc_Instances_fl_XMLList_AS3insertChildAfter::Method = &Instances::fl::XMLList::AS3insertChildAfter;
typedef ThunkFunc2<Instances::fl::XMLList, 29, Value, const Value&, const Value&> TFunc_Instances_fl_XMLList_AS3insertChildBefore;
// @0x14013dfd0
template <> const TFunc_Instances_fl_XMLList_AS3insertChildBefore::TMethod TFunc_Instances_fl_XMLList_AS3insertChildBefore::Method = &Instances::fl::XMLList::AS3insertChildBefore;
typedef ThunkFunc2<Instances::fl::XMLList, 31, Value, unsigned, const Value*> TFunc_Instances_fl_XMLList_AS3namespace_;
// @0x14013e000
template <> const TFunc_Instances_fl_XMLList_AS3namespace_::TMethod TFunc_Instances_fl_XMLList_AS3namespace_::Method = &Instances::fl::XMLList::AS3namespace_;
typedef ThunkFunc2<Instances::fl::XMLList, 36, SPtr<Instances::fl::XML>, const Value&, const Value&> TFunc_Instances_fl_XMLList_AS3replace;
// @0x14013e030
template <> const TFunc_Instances_fl_XMLList_AS3replace::TMethod TFunc_Instances_fl_XMLList_AS3replace::Method = &Instances::fl::XMLList::AS3replace;
typedef ThunkFunc2<Instances::fl::XMLList, 14, Value, unsigned, const Value*> TFunc_Instances_fl_XMLList_AS3descendants;
// @0x14013e060
template <> const TFunc_Instances_fl_XMLList_AS3descendants::TMethod TFunc_Instances_fl_XMLList_AS3descendants::Method = &Instances::fl::XMLList::AS3descendants;
typedef ThunkFunc2<Instances::fl::XMLList, 15, Value, unsigned, const Value*> TFunc_Instances_fl_XMLList_AS3elements;
// @0x14013e090
template <> const TFunc_Instances_fl_XMLList_AS3elements::TMethod TFunc_Instances_fl_XMLList_AS3elements::Method = &Instances::fl::XMLList::AS3elements;
typedef ThunkFunc0<Instances::fl_display::Bitmap, 2, ASString> TFunc_Instances_fl_display_Bitmap_pixelSnappingGet;
// @0x14013e740
template <> const TFunc_Instances_fl_display_Bitmap_pixelSnappingGet::TMethod TFunc_Instances_fl_display_Bitmap_pixelSnappingGet::Method = &Instances::fl_display::Bitmap::pixelSnappingGet;
typedef ThunkFunc0<Instances::fl_display::Bitmap, 4, bool> TFunc_Instances_fl_display_Bitmap_smoothingGet;
// @0x14013e770
template <> const TFunc_Instances_fl_display_Bitmap_smoothingGet::TMethod TFunc_Instances_fl_display_Bitmap_smoothingGet::Method = &Instances::fl_display::Bitmap::smoothingGet;
typedef ThunkFunc0<Instances::fl_display::Bitmap, 0, SPtr<Instances::fl_display::BitmapData>> TFunc_Instances_fl_display_Bitmap_bitmapDataGet;
// @0x14013e7a0
template <> const TFunc_Instances_fl_display_Bitmap_bitmapDataGet::TMethod TFunc_Instances_fl_display_Bitmap_bitmapDataGet::Method = &Instances::fl_display::Bitmap::bitmapDataGet;
typedef ThunkFunc0<Instances::fl_display::BitmapData, 1, SPtr<Instances::fl_geom::Rectangle>> TFunc_Instances_fl_display_BitmapData_rectGet;
// @0x14013e7d0
template <> const TFunc_Instances_fl_display_BitmapData_rectGet::TMethod TFunc_Instances_fl_display_BitmapData_rectGet::Method = &Instances::fl_display::BitmapData::rectGet;
typedef ThunkFunc0<Instances::fl_display::BitmapData, 2, bool> TFunc_Instances_fl_display_BitmapData_transparentGet;
// @0x14013e800
template <> const TFunc_Instances_fl_display_BitmapData_transparentGet::TMethod TFunc_Instances_fl_display_BitmapData_transparentGet::Method = &Instances::fl_display::BitmapData::transparentGet;
typedef ThunkFunc0<Instances::fl_display::BitmapData, 3, SInt32> TFunc_Instances_fl_display_BitmapData_widthGet;
// @0x14013e830
template <> const TFunc_Instances_fl_display_BitmapData_widthGet::TMethod TFunc_Instances_fl_display_BitmapData_widthGet::Method = &Instances::fl_display::BitmapData::widthGet;
typedef ThunkFunc0<Instances::fl_display::BitmapData, 5, SPtr<Instances::fl_display::BitmapData>> TFunc_Instances_fl_display_BitmapData_clone;
// @0x14013e860
template <> const TFunc_Instances_fl_display_BitmapData_clone::TMethod TFunc_Instances_fl_display_BitmapData_clone::Method = &Instances::fl_display::BitmapData::clone;
typedef ThunkFunc0<Instances::fl_display::BitmapData, 10, const Value> TFunc_Instances_fl_display_BitmapData_dispose;
// @0x14013e890
template <> const TFunc_Instances_fl_display_BitmapData_dispose::TMethod TFunc_Instances_fl_display_BitmapData_dispose::Method = &Instances::fl_display::BitmapData::dispose;
typedef ThunkFunc0<Instances::fl_display::BitmapData, 0, SInt32> TFunc_Instances_fl_display_BitmapData_heightGet;
// @0x14013e8c0
template <> const TFunc_Instances_fl_display_BitmapData_heightGet::TMethod TFunc_Instances_fl_display_BitmapData_heightGet::Method = &Instances::fl_display::BitmapData::heightGet;
typedef ThunkFunc0<Instances::fl_display::BitmapData, 22, const Value> TFunc_Instances_fl_display_BitmapData_lock;
// @0x14013e8f0
template <> const TFunc_Instances_fl_display_BitmapData_lock::TMethod TFunc_Instances_fl_display_BitmapData_lock::Method = &Instances::fl_display::BitmapData::lock;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 2, Value::Number> TFunc_Instances_fl_display_DisplayObject_alphaGet;
// @0x14013e920
template <> const TFunc_Instances_fl_display_DisplayObject_alphaGet::TMethod TFunc_Instances_fl_display_DisplayObject_alphaGet::Method = &Instances::fl_display::DisplayObject::alphaGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 4, ASString> TFunc_Instances_fl_display_DisplayObject_blendModeGet;
// @0x14013e950
template <> const TFunc_Instances_fl_display_DisplayObject_blendModeGet::TMethod TFunc_Instances_fl_display_DisplayObject_blendModeGet::Method = &Instances::fl_display::DisplayObject::blendModeGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 6, bool> TFunc_Instances_fl_display_DisplayObject_cacheAsBitmapGet;
// @0x14013e980
template <> const TFunc_Instances_fl_display_DisplayObject_cacheAsBitmapGet::TMethod TFunc_Instances_fl_display_DisplayObject_cacheAsBitmapGet::Method = &Instances::fl_display::DisplayObject::cacheAsBitmapGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 8, SPtr<Instances::fl::Array>> TFunc_Instances_fl_display_DisplayObject_filtersGet;
// @0x14013e9b0
template <> const TFunc_Instances_fl_display_DisplayObject_filtersGet::TMethod TFunc_Instances_fl_display_DisplayObject_filtersGet::Method = &Instances::fl_display::DisplayObject::filtersGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 10, Value::Number> TFunc_Instances_fl_display_DisplayObject_heightGet;
// @0x14013e9e0
template <> const TFunc_Instances_fl_display_DisplayObject_heightGet::TMethod TFunc_Instances_fl_display_DisplayObject_heightGet::Method = &Instances::fl_display::DisplayObject::heightGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 0, SPtr<Instances::fl_accessibility::AccessibilityProperties>> TFunc_Instances_fl_display_DisplayObject_accessibilityPropertiesGet;
// @0x14013ea10
template <> const TFunc_Instances_fl_display_DisplayObject_accessibilityPropertiesGet::TMethod TFunc_Instances_fl_display_DisplayObject_accessibilityPropertiesGet::Method = &Instances::fl_display::DisplayObject::accessibilityPropertiesGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 16, Value::Number> TFunc_Instances_fl_display_DisplayObject_mouseYGet;
// @0x14013ea40
template <> const TFunc_Instances_fl_display_DisplayObject_mouseYGet::TMethod TFunc_Instances_fl_display_DisplayObject_mouseYGet::Method = &Instances::fl_display::DisplayObject::mouseYGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 17, ASString> TFunc_Instances_fl_display_DisplayObject_nameGet;
// @0x14013ea70
template <> const TFunc_Instances_fl_display_DisplayObject_nameGet::TMethod TFunc_Instances_fl_display_DisplayObject_nameGet::Method = &Instances::fl_display::DisplayObject::nameGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 19, SPtr<Instances::fl::Object>> TFunc_Instances_fl_display_DisplayObject_opaqueBackgroundGet;
// @0x14013eaa0
template <> const TFunc_Instances_fl_display_DisplayObject_opaqueBackgroundGet::TMethod TFunc_Instances_fl_display_DisplayObject_opaqueBackgroundGet::Method = &Instances::fl_display::DisplayObject::opaqueBackgroundGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 21, SPtr<Instances::fl_display::DisplayObjectContainer>> TFunc_Instances_fl_display_DisplayObject_parentGet;
// @0x14013ead0
template <> const TFunc_Instances_fl_display_DisplayObject_parentGet::TMethod TFunc_Instances_fl_display_DisplayObject_parentGet::Method = &Instances::fl_display::DisplayObject::parentGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 22, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_DisplayObject_rootGet;
// @0x14013eb00
template <> const TFunc_Instances_fl_display_DisplayObject_rootGet::TMethod TFunc_Instances_fl_display_DisplayObject_rootGet::Method = &Instances::fl_display::DisplayObject::rootGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 23, Value::Number> TFunc_Instances_fl_display_DisplayObject_rotationGet;
// @0x14013eb30
template <> const TFunc_Instances_fl_display_DisplayObject_rotationGet::TMethod TFunc_Instances_fl_display_DisplayObject_rotationGet::Method = &Instances::fl_display::DisplayObject::rotationGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 25, Value::Number> TFunc_Instances_fl_display_DisplayObject_rotationXGet;
// @0x14013eb60
template <> const TFunc_Instances_fl_display_DisplayObject_rotationXGet::TMethod TFunc_Instances_fl_display_DisplayObject_rotationXGet::Method = &Instances::fl_display::DisplayObject::rotationXGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 27, Value::Number> TFunc_Instances_fl_display_DisplayObject_rotationYGet;
// @0x14013eb90
template <> const TFunc_Instances_fl_display_DisplayObject_rotationYGet::TMethod TFunc_Instances_fl_display_DisplayObject_rotationYGet::Method = &Instances::fl_display::DisplayObject::rotationYGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 29, Value::Number> TFunc_Instances_fl_display_DisplayObject_rotationZGet;
// @0x14013ebc0
template <> const TFunc_Instances_fl_display_DisplayObject_rotationZGet::TMethod TFunc_Instances_fl_display_DisplayObject_rotationZGet::Method = &Instances::fl_display::DisplayObject::rotationZGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 31, SPtr<Instances::fl_geom::Rectangle>> TFunc_Instances_fl_display_DisplayObject_scale9GridGet;
// @0x14013ebf0
template <> const TFunc_Instances_fl_display_DisplayObject_scale9GridGet::TMethod TFunc_Instances_fl_display_DisplayObject_scale9GridGet::Method = &Instances::fl_display::DisplayObject::scale9GridGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 33, Value::Number> TFunc_Instances_fl_display_DisplayObject_scaleXGet;
// @0x14013ec20
template <> const TFunc_Instances_fl_display_DisplayObject_scaleXGet::TMethod TFunc_Instances_fl_display_DisplayObject_scaleXGet::Method = &Instances::fl_display::DisplayObject::scaleXGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 35, Value::Number> TFunc_Instances_fl_display_DisplayObject_scaleYGet;
// @0x14013ec50
template <> const TFunc_Instances_fl_display_DisplayObject_scaleYGet::TMethod TFunc_Instances_fl_display_DisplayObject_scaleYGet::Method = &Instances::fl_display::DisplayObject::scaleYGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 37, Value::Number> TFunc_Instances_fl_display_DisplayObject_scaleZGet;
// @0x14013ec80
template <> const TFunc_Instances_fl_display_DisplayObject_scaleZGet::TMethod TFunc_Instances_fl_display_DisplayObject_scaleZGet::Method = &Instances::fl_display::DisplayObject::scaleZGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 39, SPtr<Instances::fl_geom::Rectangle>> TFunc_Instances_fl_display_DisplayObject_scrollRectGet;
// @0x14013ecb0
template <> const TFunc_Instances_fl_display_DisplayObject_scrollRectGet::TMethod TFunc_Instances_fl_display_DisplayObject_scrollRectGet::Method = &Instances::fl_display::DisplayObject::scrollRectGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 41, SPtr<Instances::fl_display::Stage>> TFunc_Instances_fl_display_DisplayObject_stageGet;
// @0x14013ece0
template <> const TFunc_Instances_fl_display_DisplayObject_stageGet::TMethod TFunc_Instances_fl_display_DisplayObject_stageGet::Method = &Instances::fl_display::DisplayObject::stageGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 42, SPtr<Instances::fl_geom::Transform>> TFunc_Instances_fl_display_DisplayObject_transformGet;
// @0x14013ed10
template <> const TFunc_Instances_fl_display_DisplayObject_transformGet::TMethod TFunc_Instances_fl_display_DisplayObject_transformGet::Method = &Instances::fl_display::DisplayObject::transformGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 44, bool> TFunc_Instances_fl_display_DisplayObject_visibleGet;
// @0x14013ed40
template <> const TFunc_Instances_fl_display_DisplayObject_visibleGet::TMethod TFunc_Instances_fl_display_DisplayObject_visibleGet::Method = &Instances::fl_display::DisplayObject::visibleGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 46, Value::Number> TFunc_Instances_fl_display_DisplayObject_widthGet;
// @0x14013ed70
template <> const TFunc_Instances_fl_display_DisplayObject_widthGet::TMethod TFunc_Instances_fl_display_DisplayObject_widthGet::Method = &Instances::fl_display::DisplayObject::widthGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 48, Value::Number> TFunc_Instances_fl_display_DisplayObject_xGet;
// @0x14013eda0
template <> const TFunc_Instances_fl_display_DisplayObject_xGet::TMethod TFunc_Instances_fl_display_DisplayObject_xGet::Method = &Instances::fl_display::DisplayObject::xGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 50, Value::Number> TFunc_Instances_fl_display_DisplayObject_yGet;
// @0x14013edd0
template <> const TFunc_Instances_fl_display_DisplayObject_yGet::TMethod TFunc_Instances_fl_display_DisplayObject_yGet::Method = &Instances::fl_display::DisplayObject::yGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 52, Value::Number> TFunc_Instances_fl_display_DisplayObject_zGet;
// @0x14013ee00
template <> const TFunc_Instances_fl_display_DisplayObject_zGet::TMethod TFunc_Instances_fl_display_DisplayObject_zGet::Method = &Instances::fl_display::DisplayObject::zGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 12, SPtr<Instances::fl_display::LoaderInfo>> TFunc_Instances_fl_display_DisplayObject_loaderInfoGet;
// @0x14013ee30
template <> const TFunc_Instances_fl_display_DisplayObject_loaderInfoGet::TMethod TFunc_Instances_fl_display_DisplayObject_loaderInfoGet::Method = &Instances::fl_display::DisplayObject::loaderInfoGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 13, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_DisplayObject_maskGet;
// @0x14013ee60
template <> const TFunc_Instances_fl_display_DisplayObject_maskGet::TMethod TFunc_Instances_fl_display_DisplayObject_maskGet::Method = &Instances::fl_display::DisplayObject::maskGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObject, 15, Value::Number> TFunc_Instances_fl_display_DisplayObject_mouseXGet;
// @0x14013ee90
template <> const TFunc_Instances_fl_display_DisplayObject_mouseXGet::TMethod TFunc_Instances_fl_display_DisplayObject_mouseXGet::Method = &Instances::fl_display::DisplayObject::mouseXGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObjectContainer, 2, SInt32> TFunc_Instances_fl_display_DisplayObjectContainer_numChildrenGet;
// @0x14013eec0
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_numChildrenGet::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_numChildrenGet::Method = &Instances::fl_display::DisplayObjectContainer::numChildrenGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObjectContainer, 3, bool> TFunc_Instances_fl_display_DisplayObjectContainer_tabChildrenGet;
// @0x14013eef0
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_tabChildrenGet::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_tabChildrenGet::Method = &Instances::fl_display::DisplayObjectContainer::tabChildrenGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObjectContainer, 5, SPtr<Instances::fl_text::TextSnapshot>> TFunc_Instances_fl_display_DisplayObjectContainer_textSnapshotGet;
// @0x14013ef20
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_textSnapshotGet::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_textSnapshotGet::Method = &Instances::fl_display::DisplayObjectContainer::textSnapshotGet;
typedef ThunkFunc0<Instances::fl_display::DisplayObjectContainer, 0, bool> TFunc_Instances_fl_display_DisplayObjectContainer_mouseChildrenGet;
// @0x14013ef50
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_mouseChildrenGet::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_mouseChildrenGet::Method = &Instances::fl_display::DisplayObjectContainer::mouseChildrenGet;
typedef ThunkFunc0<Instances::fl_display::FrameLabel, 1, ASString> TFunc_Instances_fl_display_FrameLabel_nameGet;
// @0x14013ef80
template <> const TFunc_Instances_fl_display_FrameLabel_nameGet::TMethod TFunc_Instances_fl_display_FrameLabel_nameGet::Method = &Instances::fl_display::FrameLabel::nameGet;
typedef ThunkFunc0<Instances::fl_display::FrameLabel, 0, SInt32> TFunc_Instances_fl_display_FrameLabel_frameGet;
// @0x14013efb0
template <> const TFunc_Instances_fl_display_FrameLabel_frameGet::TMethod TFunc_Instances_fl_display_FrameLabel_frameGet::Method = &Instances::fl_display::FrameLabel::frameGet;
typedef ThunkFunc0<Instances::fl_display::Graphics, 3, const Value> TFunc_Instances_fl_display_Graphics_clear;
// @0x14013efe0
template <> const TFunc_Instances_fl_display_Graphics_clear::TMethod TFunc_Instances_fl_display_Graphics_clear::Method = &Instances::fl_display::Graphics::clear;
typedef ThunkFunc0<Instances::fl_display::Graphics, 10, const Value> TFunc_Instances_fl_display_Graphics_endFill;
// @0x14013f010
template <> const TFunc_Instances_fl_display_Graphics_endFill::TMethod TFunc_Instances_fl_display_Graphics_endFill::Method = &Instances::fl_display::Graphics::endFill;
typedef ThunkFunc0<Instances::fl_display::InteractiveObject, 2, bool> TFunc_Instances_fl_display_InteractiveObject_doubleClickEnabledGet;
// @0x14013f040
template <> const TFunc_Instances_fl_display_InteractiveObject_doubleClickEnabledGet::TMethod TFunc_Instances_fl_display_InteractiveObject_doubleClickEnabledGet::Method = &Instances::fl_display::InteractiveObject::doubleClickEnabledGet;
typedef ThunkFunc0<Instances::fl_display::InteractiveObject, 4, Value> TFunc_Instances_fl_display_InteractiveObject_focusRectGet;
// @0x14013f070
template <> const TFunc_Instances_fl_display_InteractiveObject_focusRectGet::TMethod TFunc_Instances_fl_display_InteractiveObject_focusRectGet::Method = &Instances::fl_display::InteractiveObject::focusRectGet;
typedef ThunkFunc0<Instances::fl_display::InteractiveObject, 6, bool> TFunc_Instances_fl_display_InteractiveObject_mouseEnabledGet;
// @0x14013f0a0
template <> const TFunc_Instances_fl_display_InteractiveObject_mouseEnabledGet::TMethod TFunc_Instances_fl_display_InteractiveObject_mouseEnabledGet::Method = &Instances::fl_display::InteractiveObject::mouseEnabledGet;

}}} // namespace Scaleform::GFx::AS3

