// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, the dynamic initializers of
// the native method member pointers ThunkFuncN<T, N, R, A...>::Method (0x140149990-0x14014c8e0): each stores
// {method, 0} (16 bytes, the general member-pointer representation of as3_marshalling.h). The thunks that call
// through them are in the sfr_as3_* units. Our own source, written from the exe (work/sfr5/gen_natives.py).
// MS2-UNIT: sfr_as3di_05
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140149990-0x14014c8e0 .text$di
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

namespace Scaleform { namespace GFx { namespace AS3 {

typedef ThunkFunc0<Instances::fl_utils::ByteArray, 19, UInt32> TFunc_Instances_fl_utils_ByteArray_readUnsignedByte;
// @0x140149990
template <> const TFunc_Instances_fl_utils_ByteArray_readUnsignedByte::TMethod TFunc_Instances_fl_utils_ByteArray_readUnsignedByte::Method = &Instances::fl_utils::ByteArray::readUnsignedByte;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 20, UInt32> TFunc_Instances_fl_utils_ByteArray_readUnsignedInt;
// @0x1401499c0
template <> const TFunc_Instances_fl_utils_ByteArray_readUnsignedInt::TMethod TFunc_Instances_fl_utils_ByteArray_readUnsignedInt::Method = &Instances::fl_utils::ByteArray::readUnsignedInt;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 21, UInt32> TFunc_Instances_fl_utils_ByteArray_readUnsignedShort;
// @0x1401499f0
template <> const TFunc_Instances_fl_utils_ByteArray_readUnsignedShort::TMethod TFunc_Instances_fl_utils_ByteArray_readUnsignedShort::Method = &Instances::fl_utils::ByteArray::readUnsignedShort;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 22, ASString> TFunc_Instances_fl_utils_ByteArray_readUTF;
// @0x140149a20
template <> const TFunc_Instances_fl_utils_ByteArray_readUTF::TMethod TFunc_Instances_fl_utils_ByteArray_readUTF::Method = &Instances::fl_utils::ByteArray::readUTF;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 24, ASString> TFunc_Instances_fl_utils_ByteArray_toString;
// @0x140149a50
template <> const TFunc_Instances_fl_utils_ByteArray_toString::TMethod TFunc_Instances_fl_utils_ByteArray_toString::Method = &Instances::fl_utils::ByteArray::toString;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 11, SInt32> TFunc_Instances_fl_utils_ByteArray_readByte;
// @0x140149a80
template <> const TFunc_Instances_fl_utils_ByteArray_readByte::TMethod TFunc_Instances_fl_utils_ByteArray_readByte::Method = &Instances::fl_utils::ByteArray::readByte;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 13, Value::Number> TFunc_Instances_fl_utils_ByteArray_readDouble;
// @0x140149ab0
template <> const TFunc_Instances_fl_utils_ByteArray_readDouble::TMethod TFunc_Instances_fl_utils_ByteArray_readDouble::Method = &Instances::fl_utils::ByteArray::readDouble;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 14, Value::Number> TFunc_Instances_fl_utils_ByteArray_readFloat;
// @0x140149ae0
template <> const TFunc_Instances_fl_utils_ByteArray_readFloat::TMethod TFunc_Instances_fl_utils_ByteArray_readFloat::Method = &Instances::fl_utils::ByteArray::readFloat;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 15, SInt32> TFunc_Instances_fl_utils_ByteArray_readInt;
// @0x140149b10
template <> const TFunc_Instances_fl_utils_ByteArray_readInt::TMethod TFunc_Instances_fl_utils_ByteArray_readInt::Method = &Instances::fl_utils::ByteArray::readInt;
typedef ThunkFunc0<Instances::fl_utils::Timer, 1, Value::Number> TFunc_Instances_fl_utils_Timer_delayGet;
// @0x140149b40
template <> const TFunc_Instances_fl_utils_Timer_delayGet::TMethod TFunc_Instances_fl_utils_Timer_delayGet::Method = &Instances::fl_utils::Timer::delayGet;
typedef ThunkFunc0<Instances::fl_utils::Timer, 3, SInt32> TFunc_Instances_fl_utils_Timer_repeatCountGet;
// @0x140149b70
template <> const TFunc_Instances_fl_utils_Timer_repeatCountGet::TMethod TFunc_Instances_fl_utils_Timer_repeatCountGet::Method = &Instances::fl_utils::Timer::repeatCountGet;
typedef ThunkFunc0<Instances::fl_utils::Timer, 5, bool> TFunc_Instances_fl_utils_Timer_runningGet;
// @0x140149ba0
template <> const TFunc_Instances_fl_utils_Timer_runningGet::TMethod TFunc_Instances_fl_utils_Timer_runningGet::Method = &Instances::fl_utils::Timer::runningGet;
typedef ThunkFunc0<Instances::fl_utils::Timer, 6, const Value> TFunc_Instances_fl_utils_Timer_reset;
// @0x140149bd0
template <> const TFunc_Instances_fl_utils_Timer_reset::TMethod TFunc_Instances_fl_utils_Timer_reset::Method = &Instances::fl_utils::Timer::reset;
typedef ThunkFunc0<Instances::fl_utils::Timer, 7, const Value> TFunc_Instances_fl_utils_Timer_start;
// @0x140149c00
template <> const TFunc_Instances_fl_utils_Timer_start::TMethod TFunc_Instances_fl_utils_Timer_start::Method = &Instances::fl_utils::Timer::start;
typedef ThunkFunc0<Instances::fl_utils::Timer, 8, const Value> TFunc_Instances_fl_utils_Timer_stop;
// @0x140149c30
template <> const TFunc_Instances_fl_utils_Timer_stop::TMethod TFunc_Instances_fl_utils_Timer_stop::Method = &Instances::fl_utils::Timer::stop;
typedef ThunkFunc0<Instances::fl_utils::Timer, 0, SInt32> TFunc_Instances_fl_utils_Timer_currentCountGet;
// @0x140149c60
template <> const TFunc_Instances_fl_utils_Timer_currentCountGet::TMethod TFunc_Instances_fl_utils_Timer_currentCountGet::Method = &Instances::fl_utils::Timer::currentCountGet;
typedef ThunkFunc1<Classes::fl_utils::ByteArray, 0, const Value, UInt32> TFunc_Classes_fl_utils_ByteArray_defaultObjectEncodingSet;
// @0x140149c90
template <> const TFunc_Classes_fl_utils_ByteArray_defaultObjectEncodingSet::TMethod TFunc_Classes_fl_utils_ByteArray_defaultObjectEncodingSet::Method = &Classes::fl_utils::ByteArray::defaultObjectEncodingSet;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 2, const Value, const ASString&> TFunc_Instances_fl_utils_ByteArray_endianSet;
// @0x140149cc0
template <> const TFunc_Instances_fl_utils_ByteArray_endianSet::TMethod TFunc_Instances_fl_utils_ByteArray_endianSet::Method = &Instances::fl_utils::ByteArray::endianSet;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 4, const Value, UInt32> TFunc_Instances_fl_utils_ByteArray_lengthSet;
// @0x140149cf0
template <> const TFunc_Instances_fl_utils_ByteArray_lengthSet::TMethod TFunc_Instances_fl_utils_ByteArray_lengthSet::Method = &Instances::fl_utils::ByteArray::lengthSet;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 6, const Value, UInt32> TFunc_Instances_fl_utils_ByteArray_objectEncodingSet;
// @0x140149d20
template <> const TFunc_Instances_fl_utils_ByteArray_objectEncodingSet::TMethod TFunc_Instances_fl_utils_ByteArray_objectEncodingSet::Method = &Instances::fl_utils::ByteArray::objectEncodingSet;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 8, const Value, UInt32> TFunc_Instances_fl_utils_ByteArray_positionSet;
// @0x140149d50
template <> const TFunc_Instances_fl_utils_ByteArray_positionSet::TMethod TFunc_Instances_fl_utils_ByteArray_positionSet::Method = &Instances::fl_utils::ByteArray::positionSet;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 23, ASString, UInt32> TFunc_Instances_fl_utils_ByteArray_readUTFBytes;
// @0x140149d80
template <> const TFunc_Instances_fl_utils_ByteArray_readUTFBytes::TMethod TFunc_Instances_fl_utils_ByteArray_readUTFBytes::Method = &Instances::fl_utils::ByteArray::readUTFBytes;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 26, const Value, bool> TFunc_Instances_fl_utils_ByteArray_writeBoolean;
// @0x140149db0
template <> const TFunc_Instances_fl_utils_ByteArray_writeBoolean::TMethod TFunc_Instances_fl_utils_ByteArray_writeBoolean::Method = &Instances::fl_utils::ByteArray::writeBoolean;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 27, const Value, SInt32> TFunc_Instances_fl_utils_ByteArray_writeByte;
// @0x140149de0
template <> const TFunc_Instances_fl_utils_ByteArray_writeByte::TMethod TFunc_Instances_fl_utils_ByteArray_writeByte::Method = &Instances::fl_utils::ByteArray::writeByte;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 29, const Value, Value::Number> TFunc_Instances_fl_utils_ByteArray_writeDouble;
// @0x140149e10
template <> const TFunc_Instances_fl_utils_ByteArray_writeDouble::TMethod TFunc_Instances_fl_utils_ByteArray_writeDouble::Method = &Instances::fl_utils::ByteArray::writeDouble;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 30, const Value, Value::Number> TFunc_Instances_fl_utils_ByteArray_writeFloat;
// @0x140149e40
template <> const TFunc_Instances_fl_utils_ByteArray_writeFloat::TMethod TFunc_Instances_fl_utils_ByteArray_writeFloat::Method = &Instances::fl_utils::ByteArray::writeFloat;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 31, const Value, SInt32> TFunc_Instances_fl_utils_ByteArray_writeInt;
// @0x140149e70
template <> const TFunc_Instances_fl_utils_ByteArray_writeInt::TMethod TFunc_Instances_fl_utils_ByteArray_writeInt::Method = &Instances::fl_utils::ByteArray::writeInt;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 33, const Value, const Value&> TFunc_Instances_fl_utils_ByteArray_writeObject;
// @0x140149ea0
template <> const TFunc_Instances_fl_utils_ByteArray_writeObject::TMethod TFunc_Instances_fl_utils_ByteArray_writeObject::Method = &Instances::fl_utils::ByteArray::writeObject;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 34, const Value, SInt32> TFunc_Instances_fl_utils_ByteArray_writeShort;
// @0x140149ed0
template <> const TFunc_Instances_fl_utils_ByteArray_writeShort::TMethod TFunc_Instances_fl_utils_ByteArray_writeShort::Method = &Instances::fl_utils::ByteArray::writeShort;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 35, const Value, UInt32> TFunc_Instances_fl_utils_ByteArray_writeUnsignedInt;
// @0x140149f00
template <> const TFunc_Instances_fl_utils_ByteArray_writeUnsignedInt::TMethod TFunc_Instances_fl_utils_ByteArray_writeUnsignedInt::Method = &Instances::fl_utils::ByteArray::writeUnsignedInt;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 36, const Value, const ASString&> TFunc_Instances_fl_utils_ByteArray_writeUTF;
// @0x140149f30
template <> const TFunc_Instances_fl_utils_ByteArray_writeUTF::TMethod TFunc_Instances_fl_utils_ByteArray_writeUTF::Method = &Instances::fl_utils::ByteArray::writeUTF;
typedef ThunkFunc1<Instances::fl_utils::ByteArray, 37, const Value, const Value&> TFunc_Instances_fl_utils_ByteArray_writeUTFBytes;
// @0x140149f60
template <> const TFunc_Instances_fl_utils_ByteArray_writeUTFBytes::TMethod TFunc_Instances_fl_utils_ByteArray_writeUTFBytes::Method = &Instances::fl_utils::ByteArray::writeUTFBytes;
typedef ThunkFunc1<Instances::fl_utils::Timer, 2, const Value, Value::Number> TFunc_Instances_fl_utils_Timer_delaySet;
// @0x140149f90
template <> const TFunc_Instances_fl_utils_Timer_delaySet::TMethod TFunc_Instances_fl_utils_Timer_delaySet::Method = &Instances::fl_utils::Timer::delaySet;
typedef ThunkFunc1<Instances::fl_utils::Timer, 4, const Value, SInt32> TFunc_Instances_fl_utils_Timer_repeatCountSet;
// @0x140149fc0
template <> const TFunc_Instances_fl_utils_Timer_repeatCountSet::TMethod TFunc_Instances_fl_utils_Timer_repeatCountSet::Method = &Instances::fl_utils::Timer::repeatCountSet;
typedef ThunkFunc2<Instances::fl_utils::ByteArray, 9, Value, unsigned, const Value*> TFunc_Instances_fl_utils_ByteArray_compress;
// @0x140149ff0
template <> const TFunc_Instances_fl_utils_ByteArray_compress::TMethod TFunc_Instances_fl_utils_ByteArray_compress::Method = &Instances::fl_utils::ByteArray::compress;
typedef ThunkFunc2<Instances::fl_utils::ByteArray, 16, ASString, UInt32, const ASString&> TFunc_Instances_fl_utils_ByteArray_readMultiByte;
// @0x14014a020
template <> const TFunc_Instances_fl_utils_ByteArray_readMultiByte::TMethod TFunc_Instances_fl_utils_ByteArray_readMultiByte::Method = &Instances::fl_utils::ByteArray::readMultiByte;
typedef ThunkFunc2<Instances::fl_utils::ByteArray, 25, Value, unsigned, const Value*> TFunc_Instances_fl_utils_ByteArray_uncompress;
// @0x14014a050
template <> const TFunc_Instances_fl_utils_ByteArray_uncompress::TMethod TFunc_Instances_fl_utils_ByteArray_uncompress::Method = &Instances::fl_utils::ByteArray::uncompress;
typedef ThunkFunc2<Instances::fl_utils::ByteArray, 32, const Value, const ASString&, const ASString&> TFunc_Instances_fl_utils_ByteArray_writeMultiByte;
// @0x14014a080
template <> const TFunc_Instances_fl_utils_ByteArray_writeMultiByte::TMethod TFunc_Instances_fl_utils_ByteArray_writeMultiByte::Method = &Instances::fl_utils::ByteArray::writeMultiByte;
typedef ThunkFunc3<Instances::fl_utils::ByteArray, 28, const Value, Instances::fl_utils::ByteArray*, UInt32, UInt32> TFunc_Instances_fl_utils_ByteArray_writeBytes;
// @0x14014a0b0
template <> const TFunc_Instances_fl_utils_ByteArray_writeBytes::TMethod TFunc_Instances_fl_utils_ByteArray_writeBytes::Method = &Instances::fl_utils::ByteArray::writeBytes;
typedef ThunkFunc3<Instances::fl_utils::ByteArray, 12, const Value, Instances::fl_utils::ByteArray*, UInt32, UInt32> TFunc_Instances_fl_utils_ByteArray_readBytes;
// @0x14014a0e0
template <> const TFunc_Instances_fl_utils_ByteArray_readBytes::TMethod TFunc_Instances_fl_utils_ByteArray_readBytes::Method = &Instances::fl_utils::ByteArray::readBytes;
typedef ThunkFunc0<Classes::fl_gfx::Extensions, 1, bool> TFunc_Classes_fl_gfx_Extensions_enabledGet;
// @0x14014a160
template <> const TFunc_Classes_fl_gfx_Extensions_enabledGet::TMethod TFunc_Classes_fl_gfx_Extensions_enabledGet::Method = &Classes::fl_gfx::Extensions::enabledGet;
typedef ThunkFunc0<Classes::fl_gfx::Extensions, 3, bool> TFunc_Classes_fl_gfx_Extensions_noInvisibleAdvanceGet;
// @0x14014a190
template <> const TFunc_Classes_fl_gfx_Extensions_noInvisibleAdvanceGet::TMethod TFunc_Classes_fl_gfx_Extensions_noInvisibleAdvanceGet::Method = &Classes::fl_gfx::Extensions::noInvisibleAdvanceGet;
typedef ThunkFunc0<Classes::fl_gfx::Extensions, 10, UInt32> TFunc_Classes_fl_gfx_Extensions_numControllersGet;
// @0x14014a1c0
template <> const TFunc_Classes_fl_gfx_Extensions_numControllersGet::TMethod TFunc_Classes_fl_gfx_Extensions_numControllersGet::Method = &Classes::fl_gfx::Extensions::numControllersGet;
typedef ThunkFunc0<Classes::fl_gfx::Extensions, 11, SPtr<Instances::fl_geom::Rectangle>> TFunc_Classes_fl_gfx_Extensions_visibleRectGet;
// @0x14014a1f0
template <> const TFunc_Classes_fl_gfx_Extensions_visibleRectGet::TMethod TFunc_Classes_fl_gfx_Extensions_visibleRectGet::Method = &Classes::fl_gfx::Extensions::visibleRectGet;
typedef ThunkFunc0<Classes::fl_gfx::Extensions, 12, bool> TFunc_Classes_fl_gfx_Extensions_isScaleformGet;
// @0x14014a220
template <> const TFunc_Classes_fl_gfx_Extensions_isScaleformGet::TMethod TFunc_Classes_fl_gfx_Extensions_isScaleformGet::Method = &Classes::fl_gfx::Extensions::isScaleformGet;
typedef ThunkFunc0<Classes::fl_gfx::FocusManager, 1, bool> TFunc_Classes_fl_gfx_FocusManager_alwaysEnableArrowKeysGet;
// @0x14014a250
template <> const TFunc_Classes_fl_gfx_FocusManager_alwaysEnableArrowKeysGet::TMethod TFunc_Classes_fl_gfx_FocusManager_alwaysEnableArrowKeysGet::Method = &Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysGet;
typedef ThunkFunc0<Classes::fl_gfx::FocusManager, 3, bool> TFunc_Classes_fl_gfx_FocusManager_disableFocusKeysGet;
// @0x14014a280
template <> const TFunc_Classes_fl_gfx_FocusManager_disableFocusKeysGet::TMethod TFunc_Classes_fl_gfx_FocusManager_disableFocusKeysGet::Method = &Classes::fl_gfx::FocusManager::disableFocusKeysGet;
typedef ThunkFunc0<Classes::fl_gfx::FocusManager, 8, UInt32> TFunc_Classes_fl_gfx_FocusManager_numFocusGroupsGet;
// @0x14014a2b0
template <> const TFunc_Classes_fl_gfx_FocusManager_numFocusGroupsGet::TMethod TFunc_Classes_fl_gfx_FocusManager_numFocusGroupsGet::Method = &Classes::fl_gfx::FocusManager::numFocusGroupsGet;
typedef ThunkFunc0<Classes::fl_gfx::GamePad, 0, bool> TFunc_Classes_fl_gfx_GamePad_supportsAnalogEvents;
// @0x14014a2e0
template <> const TFunc_Classes_fl_gfx_GamePad_supportsAnalogEvents::TMethod TFunc_Classes_fl_gfx_GamePad_supportsAnalogEvents::Method = &Classes::fl_gfx::GamePad::supportsAnalogEvents;
typedef ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 2, UInt32> TFunc_Instances_fl_gfx_GamePadAnalogEvent_controllerIdxGet;
// @0x14014a310
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_controllerIdxGet::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_controllerIdxGet::Method = &Instances::fl_gfx::GamePadAnalogEvent::controllerIdxGet;
typedef ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 4, Value::Number> TFunc_Instances_fl_gfx_GamePadAnalogEvent_xvalueGet;
// @0x14014a340
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_xvalueGet::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_xvalueGet::Method = &Instances::fl_gfx::GamePadAnalogEvent::xvalueGet;
typedef ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 6, Value::Number> TFunc_Instances_fl_gfx_GamePadAnalogEvent_yvalueGet;
// @0x14014a370
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_yvalueGet::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_yvalueGet::Method = &Instances::fl_gfx::GamePadAnalogEvent::yvalueGet;
typedef ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 8, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_gfx_GamePadAnalogEvent_clone;
// @0x14014a3a0
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_clone::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_clone::Method = &Instances::fl_gfx::GamePadAnalogEvent::clone;
typedef ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 9, ASString> TFunc_Instances_fl_gfx_GamePadAnalogEvent_toString;
// @0x14014a3d0
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_toString::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_toString::Method = &Instances::fl_gfx::GamePadAnalogEvent::toString;
typedef ThunkFunc0<Instances::fl_gfx::GamePadAnalogEvent, 0, UInt32> TFunc_Instances_fl_gfx_GamePadAnalogEvent_codeGet;
// @0x14014a400
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_codeGet::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_codeGet::Method = &Instances::fl_gfx::GamePadAnalogEvent::codeGet;
typedef ThunkFunc0<Classes::fl_gfx::IMEEx, 3, ASString> TFunc_Classes_fl_gfx_IMEEx_GetOSVersion;
// @0x14014a430
template <> const TFunc_Classes_fl_gfx_IMEEx_GetOSVersion::TMethod TFunc_Classes_fl_gfx_IMEEx_GetOSVersion::Method = &Classes::fl_gfx::IMEEx::GetOSVersion;
typedef ThunkFunc0<Classes::fl_gfx::IMEEx, 4, ASString> TFunc_Classes_fl_gfx_IMEEx_GetCompositionString;
// @0x14014a460
template <> const TFunc_Classes_fl_gfx_IMEEx_GetCompositionString::TMethod TFunc_Classes_fl_gfx_IMEEx_GetCompositionString::Method = &Classes::fl_gfx::IMEEx::GetCompositionString;
typedef ThunkFunc0<Classes::fl_gfx::IMEEx, 0, SPtr<Instances::fl_gfx::IMECandidateListStyle>> TFunc_Classes_fl_gfx_IMEEx_getIMECandidateListStyle;
// @0x14014a490
template <> const TFunc_Classes_fl_gfx_IMEEx_getIMECandidateListStyle::TMethod TFunc_Classes_fl_gfx_IMEEx_getIMECandidateListStyle::Method = &Classes::fl_gfx::IMEEx::getIMECandidateListStyle;
typedef ThunkFunc0<Classes::fl_gfx::SystemEx, 1, bool> TFunc_Classes_fl_gfx_SystemEx_actionVerboseGet;
// @0x14014a4c0
template <> const TFunc_Classes_fl_gfx_SystemEx_actionVerboseGet::TMethod TFunc_Classes_fl_gfx_SystemEx_actionVerboseGet::Method = &Classes::fl_gfx::SystemEx::actionVerboseGet;
typedef ThunkFunc0<Classes::fl_gfx::SystemEx, 3, ASString> TFunc_Classes_fl_gfx_SystemEx_getStackTrace;
// @0x14014a4f0
template <> const TFunc_Classes_fl_gfx_SystemEx_getStackTrace::TMethod TFunc_Classes_fl_gfx_SystemEx_getStackTrace::Method = &Classes::fl_gfx::SystemEx::getStackTrace;
typedef ThunkFunc0<Classes::fl_gfx::SystemEx, 4, ASString> TFunc_Classes_fl_gfx_SystemEx_getCodeFileName;
// @0x14014a520
template <> const TFunc_Classes_fl_gfx_SystemEx_getCodeFileName::TMethod TFunc_Classes_fl_gfx_SystemEx_getCodeFileName::Method = &Classes::fl_gfx::SystemEx::getCodeFileName;
typedef ThunkFunc0<Classes::fl_gfx::SystemEx, 5, SPtr<Instances::fl::Array>> TFunc_Classes_fl_gfx_SystemEx_getCodeFileNames;
// @0x14014a550
template <> const TFunc_Classes_fl_gfx_SystemEx_getCodeFileNames::TMethod TFunc_Classes_fl_gfx_SystemEx_getCodeFileNames::Method = &Classes::fl_gfx::SystemEx::getCodeFileNames;
typedef ThunkFunc1<Classes::fl_gfx::Extensions, 2, const Value, bool> TFunc_Classes_fl_gfx_Extensions_noInvisibleAdvanceSet;
// @0x14014a580
template <> const TFunc_Classes_fl_gfx_Extensions_noInvisibleAdvanceSet::TMethod TFunc_Classes_fl_gfx_Extensions_noInvisibleAdvanceSet::Method = &Classes::fl_gfx::Extensions::noInvisibleAdvanceSet;
typedef ThunkFunc1<Classes::fl_gfx::Extensions, 7, ASString, UInt32> TFunc_Classes_fl_gfx_Extensions_getMouseCursorType;
// @0x14014a5b0
template <> const TFunc_Classes_fl_gfx_Extensions_getMouseCursorType::TMethod TFunc_Classes_fl_gfx_Extensions_getMouseCursorType::Method = &Classes::fl_gfx::Extensions::getMouseCursorType;
typedef ThunkFunc1<Classes::fl_gfx::Extensions, 8, UInt32, Instances::fl_display::DisplayObject*> TFunc_Classes_fl_gfx_Extensions_getEdgeAAMode;
// @0x14014a5e0
template <> const TFunc_Classes_fl_gfx_Extensions_getEdgeAAMode::TMethod TFunc_Classes_fl_gfx_Extensions_getEdgeAAMode::Method = &Classes::fl_gfx::Extensions::getEdgeAAMode;
typedef ThunkFunc1<Classes::fl_gfx::Extensions, 0, const Value, bool> TFunc_Classes_fl_gfx_Extensions_enabledSet;
// @0x14014a610
template <> const TFunc_Classes_fl_gfx_Extensions_enabledSet::TMethod TFunc_Classes_fl_gfx_Extensions_enabledSet::Method = &Classes::fl_gfx::Extensions::enabledSet;
typedef ThunkFunc1<Classes::fl_gfx::FocusManager, 2, const Value, bool> TFunc_Classes_fl_gfx_FocusManager_disableFocusKeysSet;
// @0x14014a640
template <> const TFunc_Classes_fl_gfx_FocusManager_disableFocusKeysSet::TMethod TFunc_Classes_fl_gfx_FocusManager_disableFocusKeysSet::Method = &Classes::fl_gfx::FocusManager::disableFocusKeysSet;
typedef ThunkFunc1<Classes::fl_gfx::FocusManager, 7, SPtr<Instances::fl_display::InteractiveObject>, UInt32> TFunc_Classes_fl_gfx_FocusManager_getFocus;
// @0x14014a670
template <> const TFunc_Classes_fl_gfx_FocusManager_getFocus::TMethod TFunc_Classes_fl_gfx_FocusManager_getFocus::Method = &Classes::fl_gfx::FocusManager::getFocus;
typedef ThunkFunc1<Classes::fl_gfx::FocusManager, 10, UInt32, Instances::fl_display::InteractiveObject*> TFunc_Classes_fl_gfx_FocusManager_getFocusGroupMask;
// @0x14014a6a0
template <> const TFunc_Classes_fl_gfx_FocusManager_getFocusGroupMask::TMethod TFunc_Classes_fl_gfx_FocusManager_getFocusGroupMask::Method = &Classes::fl_gfx::FocusManager::getFocusGroupMask;
typedef ThunkFunc1<Classes::fl_gfx::FocusManager, 0, const Value, bool> TFunc_Classes_fl_gfx_FocusManager_alwaysEnableArrowKeysSet;
// @0x14014a6d0
template <> const TFunc_Classes_fl_gfx_FocusManager_alwaysEnableArrowKeysSet::TMethod TFunc_Classes_fl_gfx_FocusManager_alwaysEnableArrowKeysSet::Method = &Classes::fl_gfx::FocusManager::alwaysEnableArrowKeysSet;
typedef ThunkFunc1<Classes::fl_gfx::FocusManager, 12, UInt32, UInt32> TFunc_Classes_fl_gfx_FocusManager_getControllerFocusGroup;
// @0x14014a700
template <> const TFunc_Classes_fl_gfx_FocusManager_getControllerFocusGroup::TMethod TFunc_Classes_fl_gfx_FocusManager_getControllerFocusGroup::Method = &Classes::fl_gfx::FocusManager::getControllerFocusGroup;
typedef ThunkFunc1<Classes::fl_gfx::FocusManager, 13, UInt32, UInt32> TFunc_Classes_fl_gfx_FocusManager_getControllerMaskByFocusGroup;
// @0x14014a730
template <> const TFunc_Classes_fl_gfx_FocusManager_getControllerMaskByFocusGroup::TMethod TFunc_Classes_fl_gfx_FocusManager_getControllerMaskByFocusGroup::Method = &Classes::fl_gfx::FocusManager::getControllerMaskByFocusGroup;
typedef ThunkFunc1<Classes::fl_gfx::FocusManager, 14, SPtr<Instances::fl_display::Sprite>, UInt32> TFunc_Classes_fl_gfx_FocusManager_getModalClip;
// @0x14014a760
template <> const TFunc_Classes_fl_gfx_FocusManager_getModalClip::TMethod TFunc_Classes_fl_gfx_FocusManager_getModalClip::Method = &Classes::fl_gfx::FocusManager::getModalClip;
typedef ThunkFunc1<Instances::fl_gfx::GamePadAnalogEvent, 1, const Value, UInt32> TFunc_Instances_fl_gfx_GamePadAnalogEvent_codeSet;
// @0x14014a790
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_codeSet::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_codeSet::Method = &Instances::fl_gfx::GamePadAnalogEvent::codeSet;
typedef ThunkFunc1<Instances::fl_gfx::GamePadAnalogEvent, 3, const Value, UInt32> TFunc_Instances_fl_gfx_GamePadAnalogEvent_controllerIdxSet;
// @0x14014a7c0
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_controllerIdxSet::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_controllerIdxSet::Method = &Instances::fl_gfx::GamePadAnalogEvent::controllerIdxSet;
typedef ThunkFunc1<Instances::fl_gfx::GamePadAnalogEvent, 5, const Value, Value::Number> TFunc_Instances_fl_gfx_GamePadAnalogEvent_xvalueSet;
// @0x14014a7f0
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_xvalueSet::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_xvalueSet::Method = &Instances::fl_gfx::GamePadAnalogEvent::xvalueSet;
typedef ThunkFunc1<Instances::fl_gfx::GamePadAnalogEvent, 7, const Value, Value::Number> TFunc_Instances_fl_gfx_GamePadAnalogEvent_yvalueSet;
// @0x14014a820
template <> const TFunc_Instances_fl_gfx_GamePadAnalogEvent_yvalueSet::TMethod TFunc_Instances_fl_gfx_GamePadAnalogEvent_yvalueSet::Method = &Instances::fl_gfx::GamePadAnalogEvent::yvalueSet;
typedef ThunkFunc1<Classes::fl_gfx::IMEEx, 1, const Value, Instances::fl_gfx::IMECandidateListStyle*> TFunc_Classes_fl_gfx_IMEEx_setIMECandidateListStyle;
// @0x14014a850
template <> const TFunc_Classes_fl_gfx_IMEEx_setIMECandidateListStyle::TMethod TFunc_Classes_fl_gfx_IMEEx_setIMECandidateListStyle::Method = &Classes::fl_gfx::IMEEx::setIMECandidateListStyle;
typedef ThunkFunc1<Classes::fl_gfx::InteractiveObjectEx, 1, bool, Instances::fl_display::InteractiveObject*> TFunc_Classes_fl_gfx_InteractiveObjectEx_getHitTestDisable;
// @0x14014a880
template <> const TFunc_Classes_fl_gfx_InteractiveObjectEx_getHitTestDisable::TMethod TFunc_Classes_fl_gfx_InteractiveObjectEx_getHitTestDisable::Method = &Classes::fl_gfx::InteractiveObjectEx::getHitTestDisable;
typedef ThunkFunc1<Classes::fl_gfx::InteractiveObjectEx, 3, bool, Instances::fl_display::InteractiveObject*> TFunc_Classes_fl_gfx_InteractiveObjectEx_getTopmostLevel;
// @0x14014a8b0
template <> const TFunc_Classes_fl_gfx_InteractiveObjectEx_getTopmostLevel::TMethod TFunc_Classes_fl_gfx_InteractiveObjectEx_getTopmostLevel::Method = &Classes::fl_gfx::InteractiveObjectEx::getTopmostLevel;
typedef ThunkFunc1<Classes::fl_gfx::SystemEx, 2, const Value, Value::Number> TFunc_Classes_fl_gfx_SystemEx_setBackgroundAlpha;
// @0x14014a8e0
template <> const TFunc_Classes_fl_gfx_SystemEx_setBackgroundAlpha::TMethod TFunc_Classes_fl_gfx_SystemEx_setBackgroundAlpha::Method = &Classes::fl_gfx::SystemEx::setBackgroundAlpha;
typedef ThunkFunc1<Classes::fl_gfx::SystemEx, 6, ASString, const Value&> TFunc_Classes_fl_gfx_SystemEx_describeType;
// @0x14014a910
template <> const TFunc_Classes_fl_gfx_SystemEx_describeType::TMethod TFunc_Classes_fl_gfx_SystemEx_describeType::Method = &Classes::fl_gfx::SystemEx::describeType;
typedef ThunkFunc1<Classes::fl_gfx::SystemEx, 0, const Value, bool> TFunc_Classes_fl_gfx_SystemEx_actionVerboseSet;
// @0x14014a940
template <> const TFunc_Classes_fl_gfx_SystemEx_actionVerboseSet::TMethod TFunc_Classes_fl_gfx_SystemEx_actionVerboseSet::Method = &Classes::fl_gfx::SystemEx::actionVerboseSet;
typedef ThunkFunc1<Classes::fl_gfx::TextFieldEx, 2, ASString, Instances::fl_text::TextField*> TFunc_Classes_fl_gfx_TextFieldEx_getVerticalAlign;
// @0x14014a970
template <> const TFunc_Classes_fl_gfx_TextFieldEx_getVerticalAlign::TMethod TFunc_Classes_fl_gfx_TextFieldEx_getVerticalAlign::Method = &Classes::fl_gfx::TextFieldEx::getVerticalAlign;
typedef ThunkFunc1<Classes::fl_gfx::TextFieldEx, 4, ASString, Instances::fl_text::TextField*> TFunc_Classes_fl_gfx_TextFieldEx_getTextAutoSize;
// @0x14014a9a0
template <> const TFunc_Classes_fl_gfx_TextFieldEx_getTextAutoSize::TMethod TFunc_Classes_fl_gfx_TextFieldEx_getTextAutoSize::Method = &Classes::fl_gfx::TextFieldEx::getTextAutoSize;
typedef ThunkFunc2<Classes::fl_gfx::Extensions, 5, SPtr<Instances::fl_display::DisplayObject>, bool, UInt32> TFunc_Classes_fl_gfx_Extensions_getMouseTopMostEntity;
// @0x14014a9d0
template <> const TFunc_Classes_fl_gfx_Extensions_getMouseTopMostEntity::TMethod TFunc_Classes_fl_gfx_Extensions_getMouseTopMostEntity::Method = &Classes::fl_gfx::Extensions::getMouseTopMostEntity;
typedef ThunkFunc2<Classes::fl_gfx::Extensions, 6, const Value, const ASString&, UInt32> TFunc_Classes_fl_gfx_Extensions_setMouseCursorType;
// @0x14014aa00
template <> const TFunc_Classes_fl_gfx_Extensions_setMouseCursorType::TMethod TFunc_Classes_fl_gfx_Extensions_setMouseCursorType::Method = &Classes::fl_gfx::Extensions::setMouseCursorType;
typedef ThunkFunc2<Classes::fl_gfx::Extensions, 9, const Value, Instances::fl_display::DisplayObject*, UInt32> TFunc_Classes_fl_gfx_Extensions_setEdgeAAMode;
// @0x14014aa30
template <> const TFunc_Classes_fl_gfx_Extensions_setEdgeAAMode::TMethod TFunc_Classes_fl_gfx_Extensions_setEdgeAAMode::Method = &Classes::fl_gfx::Extensions::setEdgeAAMode;
typedef ThunkFunc2<Classes::fl_gfx::FocusManager, 6, const Value, Instances::fl_display::InteractiveObject*, UInt32> TFunc_Classes_fl_gfx_FocusManager_setFocus;
// @0x14014aa60
template <> const TFunc_Classes_fl_gfx_FocusManager_setFocus::TMethod TFunc_Classes_fl_gfx_FocusManager_setFocus::Method = &Classes::fl_gfx::FocusManager::setFocus;
typedef ThunkFunc2<Classes::fl_gfx::FocusManager, 9, const Value, Instances::fl_display::InteractiveObject*, UInt32> TFunc_Classes_fl_gfx_FocusManager_setFocusGroupMask;
// @0x14014aa90
template <> const TFunc_Classes_fl_gfx_FocusManager_setFocusGroupMask::TMethod TFunc_Classes_fl_gfx_FocusManager_setFocusGroupMask::Method = &Classes::fl_gfx::FocusManager::setFocusGroupMask;
typedef ThunkFunc2<Classes::fl_gfx::FocusManager, 11, bool, UInt32, UInt32> TFunc_Classes_fl_gfx_FocusManager_setControllerFocusGroup;
// @0x14014aac0
template <> const TFunc_Classes_fl_gfx_FocusManager_setControllerFocusGroup::TMethod TFunc_Classes_fl_gfx_FocusManager_setControllerFocusGroup::Method = &Classes::fl_gfx::FocusManager::setControllerFocusGroup;
typedef ThunkFunc2<Classes::fl_gfx::FocusManager, 15, const Value, Instances::fl_display::Sprite*, UInt32> TFunc_Classes_fl_gfx_FocusManager_setModalClip;
// @0x14014aaf0
template <> const TFunc_Classes_fl_gfx_FocusManager_setModalClip::TMethod TFunc_Classes_fl_gfx_FocusManager_setModalClip::Method = &Classes::fl_gfx::FocusManager::setModalClip;
typedef ThunkFunc2<Classes::fl_gfx::InteractiveObjectEx, 2, const Value, Instances::fl_display::InteractiveObject*, bool> TFunc_Classes_fl_gfx_InteractiveObjectEx_setTopmostLevel;
// @0x14014ab20
template <> const TFunc_Classes_fl_gfx_InteractiveObjectEx_setTopmostLevel::TMethod TFunc_Classes_fl_gfx_InteractiveObjectEx_setTopmostLevel::Method = &Classes::fl_gfx::InteractiveObjectEx::setTopmostLevel;
typedef ThunkFunc2<Classes::fl_gfx::InteractiveObjectEx, 0, const Value, Instances::fl_display::InteractiveObject*, bool> TFunc_Classes_fl_gfx_InteractiveObjectEx_setHitTestDisable;
// @0x14014ab50
template <> const TFunc_Classes_fl_gfx_InteractiveObjectEx_setHitTestDisable::TMethod TFunc_Classes_fl_gfx_InteractiveObjectEx_setHitTestDisable::Method = &Classes::fl_gfx::InteractiveObjectEx::setHitTestDisable;
typedef ThunkFunc2<Classes::fl_gfx::TextFieldEx, 1, const Value, Instances::fl_text::TextField*, const ASString&> TFunc_Classes_fl_gfx_TextFieldEx_setVerticalAlign;
// @0x14014ab80
template <> const TFunc_Classes_fl_gfx_TextFieldEx_setVerticalAlign::TMethod TFunc_Classes_fl_gfx_TextFieldEx_setVerticalAlign::Method = &Classes::fl_gfx::TextFieldEx::setVerticalAlign;
typedef ThunkFunc2<Classes::fl_gfx::TextFieldEx, 3, const Value, Instances::fl_text::TextField*, const ASString&> TFunc_Classes_fl_gfx_TextFieldEx_setTextAutoSize;
// @0x14014abb0
template <> const TFunc_Classes_fl_gfx_TextFieldEx_setTextAutoSize::TMethod TFunc_Classes_fl_gfx_TextFieldEx_setTextAutoSize::Method = &Classes::fl_gfx::TextFieldEx::setTextAutoSize;
typedef ThunkFunc2<Classes::fl_gfx::TextFieldEx, 5, const Value, Instances::fl_text::TextField*, bool> TFunc_Classes_fl_gfx_TextFieldEx_setIMEEnabled;
// @0x14014abe0
template <> const TFunc_Classes_fl_gfx_TextFieldEx_setIMEEnabled::TMethod TFunc_Classes_fl_gfx_TextFieldEx_setIMEEnabled::Method = &Classes::fl_gfx::TextFieldEx::setIMEEnabled;
typedef ThunkFunc2<Classes::fl_gfx::TextFieldEx, 6, const Value, Instances::fl_text::TextField*, const Value&> TFunc_Classes_fl_gfx_TextFieldEx_setImageSubstitutions;
// @0x14014ac10
template <> const TFunc_Classes_fl_gfx_TextFieldEx_setImageSubstitutions::TMethod TFunc_Classes_fl_gfx_TextFieldEx_setImageSubstitutions::Method = &Classes::fl_gfx::TextFieldEx::setImageSubstitutions;
typedef ThunkFunc2<Classes::fl_gfx::TextFieldEx, 0, const Value, Instances::fl_text::TextField*, const ASString&> TFunc_Classes_fl_gfx_TextFieldEx_appendHtml;
// @0x14014ac40
template <> const TFunc_Classes_fl_gfx_TextFieldEx_appendHtml::TMethod TFunc_Classes_fl_gfx_TextFieldEx_appendHtml::Method = &Classes::fl_gfx::TextFieldEx::appendHtml;
typedef ThunkFunc3<Classes::fl_gfx::Extensions, 4, SPtr<Instances::fl_display::DisplayObject>, Value::Number, Value::Number, bool> TFunc_Classes_fl_gfx_Extensions_getTopMostEntity;
// @0x14014ac70
template <> const TFunc_Classes_fl_gfx_Extensions_getTopMostEntity::TMethod TFunc_Classes_fl_gfx_Extensions_getTopMostEntity::Method = &Classes::fl_gfx::Extensions::getTopMostEntity;
typedef ThunkFunc3<Classes::fl_gfx::IMEEx, 2, const Value, Instances::fl_display::Sprite*, const ASString&, const ASString&> TFunc_Classes_fl_gfx_IMEEx_SendLangBarMessage;
// @0x14014aca0
template <> const TFunc_Classes_fl_gfx_IMEEx_SendLangBarMessage::TMethod TFunc_Classes_fl_gfx_IMEEx_SendLangBarMessage::Method = &Classes::fl_gfx::IMEEx::SendLangBarMessage;
typedef ThunkFunc3<Classes::fl_gfx::SystemEx, 7, const Value, bool, UInt32, const ASString&> TFunc_Classes_fl_gfx_SystemEx_printObjectsReport;
// @0x14014acd0
template <> const TFunc_Classes_fl_gfx_SystemEx_printObjectsReport::TMethod TFunc_Classes_fl_gfx_SystemEx_printObjectsReport::Method = &Classes::fl_gfx::SystemEx::printObjectsReport;
typedef ThunkFunc3<Classes::fl_gfx::TextFieldEx, 7, const Value, Instances::fl_text::TextField*, const ASString&, Instances::fl_display::BitmapData*> TFunc_Classes_fl_gfx_TextFieldEx_updateImageSubstitution;
// @0x14014ad00
template <> const TFunc_Classes_fl_gfx_TextFieldEx_updateImageSubstitution::TMethod TFunc_Classes_fl_gfx_TextFieldEx_updateImageSubstitution::Method = &Classes::fl_gfx::TextFieldEx::updateImageSubstitution;
typedef ThunkFunc4<Classes::fl_gfx::FocusManager, 4, SPtr<Instances::fl_display::InteractiveObject>, const ASString&, Instances::fl_display::InteractiveObject*, bool, UInt32> TFunc_Classes_fl_gfx_FocusManager_moveFocus;
// @0x14014ad30
template <> const TFunc_Classes_fl_gfx_FocusManager_moveFocus::TMethod TFunc_Classes_fl_gfx_FocusManager_moveFocus::Method = &Classes::fl_gfx::FocusManager::moveFocus;
typedef ThunkFunc6<Classes::fl_gfx::FocusManager, 5, SPtr<Instances::fl_display::InteractiveObject>, const ASString&, Instances::fl_display::DisplayObjectContainer*, bool, Instances::fl_display::InteractiveObject*, bool, UInt32> TFunc_Classes_fl_gfx_FocusManager_findFocus;
// @0x14014ad60
template <> const TFunc_Classes_fl_gfx_FocusManager_findFocus::TMethod TFunc_Classes_fl_gfx_FocusManager_findFocus::Method = &Classes::fl_gfx::FocusManager::findFocus;
typedef ThunkFunc0<Instances::fl_media::Sound, 1, SInt32> TFunc_Instances_fl_media_Sound_bytesTotalGet;
// @0x14014ad90
template <> const TFunc_Instances_fl_media_Sound_bytesTotalGet::TMethod TFunc_Instances_fl_media_Sound_bytesTotalGet::Method = &Instances::fl_media::Sound::bytesTotalGet;
typedef ThunkFunc0<Instances::fl_media::Sound, 2, SPtr<Instances::fl_media::ID3Info>> TFunc_Instances_fl_media_Sound_id3Get;
// @0x14014adc0
template <> const TFunc_Instances_fl_media_Sound_id3Get::TMethod TFunc_Instances_fl_media_Sound_id3Get::Method = &Instances::fl_media::Sound::id3Get;
typedef ThunkFunc0<Instances::fl_media::Sound, 3, bool> TFunc_Instances_fl_media_Sound_isBufferingGet;
// @0x14014adf0
template <> const TFunc_Instances_fl_media_Sound_isBufferingGet::TMethod TFunc_Instances_fl_media_Sound_isBufferingGet::Method = &Instances::fl_media::Sound::isBufferingGet;
typedef ThunkFunc0<Instances::fl_media::Sound, 4, Value::Number> TFunc_Instances_fl_media_Sound_lengthGet;
// @0x14014ae20
template <> const TFunc_Instances_fl_media_Sound_lengthGet::TMethod TFunc_Instances_fl_media_Sound_lengthGet::Method = &Instances::fl_media::Sound::lengthGet;
typedef ThunkFunc0<Instances::fl_media::Sound, 5, ASString> TFunc_Instances_fl_media_Sound_urlGet;
// @0x14014ae50
template <> const TFunc_Instances_fl_media_Sound_urlGet::TMethod TFunc_Instances_fl_media_Sound_urlGet::Method = &Instances::fl_media::Sound::urlGet;
typedef ThunkFunc0<Instances::fl_media::Sound, 6, const Value> TFunc_Instances_fl_media_Sound_close;
// @0x14014ae80
template <> const TFunc_Instances_fl_media_Sound_close::TMethod TFunc_Instances_fl_media_Sound_close::Method = &Instances::fl_media::Sound::close;
typedef ThunkFunc0<Instances::fl_media::Sound, 0, UInt32> TFunc_Instances_fl_media_Sound_bytesLoadedGet;
// @0x14014aeb0
template <> const TFunc_Instances_fl_media_Sound_bytesLoadedGet::TMethod TFunc_Instances_fl_media_Sound_bytesLoadedGet::Method = &Instances::fl_media::Sound::bytesLoadedGet;
typedef ThunkFunc0<Instances::fl_media::SoundChannel, 1, Value::Number> TFunc_Instances_fl_media_SoundChannel_positionGet;
// @0x14014aee0
template <> const TFunc_Instances_fl_media_SoundChannel_positionGet::TMethod TFunc_Instances_fl_media_SoundChannel_positionGet::Method = &Instances::fl_media::SoundChannel::positionGet;
typedef ThunkFunc0<Instances::fl_media::SoundChannel, 2, Value::Number> TFunc_Instances_fl_media_SoundChannel_rightPeakGet;
// @0x14014af10
template <> const TFunc_Instances_fl_media_SoundChannel_rightPeakGet::TMethod TFunc_Instances_fl_media_SoundChannel_rightPeakGet::Method = &Instances::fl_media::SoundChannel::rightPeakGet;
typedef ThunkFunc0<Instances::fl_media::SoundChannel, 3, SPtr<Instances::fl_media::SoundTransform>> TFunc_Instances_fl_media_SoundChannel_soundTransformGet;
// @0x14014af40
template <> const TFunc_Instances_fl_media_SoundChannel_soundTransformGet::TMethod TFunc_Instances_fl_media_SoundChannel_soundTransformGet::Method = &Instances::fl_media::SoundChannel::soundTransformGet;
typedef ThunkFunc0<Instances::fl_media::SoundChannel, 5, const Value> TFunc_Instances_fl_media_SoundChannel_stop;
// @0x14014af70
template <> const TFunc_Instances_fl_media_SoundChannel_stop::TMethod TFunc_Instances_fl_media_SoundChannel_stop::Method = &Instances::fl_media::SoundChannel::stop;
typedef ThunkFunc0<Instances::fl_media::SoundChannel, 0, Value::Number> TFunc_Instances_fl_media_SoundChannel_leftPeakGet;
// @0x14014afa0
template <> const TFunc_Instances_fl_media_SoundChannel_leftPeakGet::TMethod TFunc_Instances_fl_media_SoundChannel_leftPeakGet::Method = &Instances::fl_media::SoundChannel::leftPeakGet;
typedef ThunkFunc0<Instances::fl_media::SoundTransform, 2, Value::Number> TFunc_Instances_fl_media_SoundTransform_leftToRightGet;
// @0x14014afd0
template <> const TFunc_Instances_fl_media_SoundTransform_leftToRightGet::TMethod TFunc_Instances_fl_media_SoundTransform_leftToRightGet::Method = &Instances::fl_media::SoundTransform::leftToRightGet;
typedef ThunkFunc0<Instances::fl_media::SoundTransform, 4, Value::Number> TFunc_Instances_fl_media_SoundTransform_panGet;
// @0x14014b000
template <> const TFunc_Instances_fl_media_SoundTransform_panGet::TMethod TFunc_Instances_fl_media_SoundTransform_panGet::Method = &Instances::fl_media::SoundTransform::panGet;
typedef ThunkFunc0<Instances::fl_media::SoundTransform, 6, Value::Number> TFunc_Instances_fl_media_SoundTransform_rightToLeftGet;
// @0x14014b030
template <> const TFunc_Instances_fl_media_SoundTransform_rightToLeftGet::TMethod TFunc_Instances_fl_media_SoundTransform_rightToLeftGet::Method = &Instances::fl_media::SoundTransform::rightToLeftGet;
typedef ThunkFunc0<Instances::fl_media::SoundTransform, 8, Value::Number> TFunc_Instances_fl_media_SoundTransform_rightToRightGet;
// @0x14014b060
template <> const TFunc_Instances_fl_media_SoundTransform_rightToRightGet::TMethod TFunc_Instances_fl_media_SoundTransform_rightToRightGet::Method = &Instances::fl_media::SoundTransform::rightToRightGet;
typedef ThunkFunc0<Instances::fl_media::SoundTransform, 10, Value::Number> TFunc_Instances_fl_media_SoundTransform_volumeGet;
// @0x14014b090
template <> const TFunc_Instances_fl_media_SoundTransform_volumeGet::TMethod TFunc_Instances_fl_media_SoundTransform_volumeGet::Method = &Instances::fl_media::SoundTransform::volumeGet;
typedef ThunkFunc0<Instances::fl_media::SoundTransform, 0, Value::Number> TFunc_Instances_fl_media_SoundTransform_leftToLeftGet;
// @0x14014b0c0
template <> const TFunc_Instances_fl_media_SoundTransform_leftToLeftGet::TMethod TFunc_Instances_fl_media_SoundTransform_leftToLeftGet::Method = &Instances::fl_media::SoundTransform::leftToLeftGet;
typedef ThunkFunc1<Instances::fl_media::SoundChannel, 4, const Value, Instances::fl_media::SoundTransform*> TFunc_Instances_fl_media_SoundChannel_soundTransformSet;
// @0x14014b0f0
template <> const TFunc_Instances_fl_media_SoundChannel_soundTransformSet::TMethod TFunc_Instances_fl_media_SoundChannel_soundTransformSet::Method = &Instances::fl_media::SoundChannel::soundTransformSet;
typedef ThunkFunc1<Instances::fl_media::SoundTransform, 1, const Value, Value::Number> TFunc_Instances_fl_media_SoundTransform_leftToLeftSet;
// @0x14014b120
template <> const TFunc_Instances_fl_media_SoundTransform_leftToLeftSet::TMethod TFunc_Instances_fl_media_SoundTransform_leftToLeftSet::Method = &Instances::fl_media::SoundTransform::leftToLeftSet;
typedef ThunkFunc1<Instances::fl_media::SoundTransform, 3, const Value, Value::Number> TFunc_Instances_fl_media_SoundTransform_leftToRightSet;
// @0x14014b150
template <> const TFunc_Instances_fl_media_SoundTransform_leftToRightSet::TMethod TFunc_Instances_fl_media_SoundTransform_leftToRightSet::Method = &Instances::fl_media::SoundTransform::leftToRightSet;
typedef ThunkFunc1<Instances::fl_media::SoundTransform, 5, const Value, Value::Number> TFunc_Instances_fl_media_SoundTransform_panSet;
// @0x14014b180
template <> const TFunc_Instances_fl_media_SoundTransform_panSet::TMethod TFunc_Instances_fl_media_SoundTransform_panSet::Method = &Instances::fl_media::SoundTransform::panSet;
typedef ThunkFunc1<Instances::fl_media::SoundTransform, 7, const Value, Value::Number> TFunc_Instances_fl_media_SoundTransform_rightToLeftSet;
// @0x14014b1b0
template <> const TFunc_Instances_fl_media_SoundTransform_rightToLeftSet::TMethod TFunc_Instances_fl_media_SoundTransform_rightToLeftSet::Method = &Instances::fl_media::SoundTransform::rightToLeftSet;
typedef ThunkFunc1<Instances::fl_media::SoundTransform, 9, const Value, Value::Number> TFunc_Instances_fl_media_SoundTransform_rightToRightSet;
// @0x14014b1e0
template <> const TFunc_Instances_fl_media_SoundTransform_rightToRightSet::TMethod TFunc_Instances_fl_media_SoundTransform_rightToRightSet::Method = &Instances::fl_media::SoundTransform::rightToRightSet;
typedef ThunkFunc1<Instances::fl_media::SoundTransform, 11, const Value, Value::Number> TFunc_Instances_fl_media_SoundTransform_volumeSet;
// @0x14014b210
template <> const TFunc_Instances_fl_media_SoundTransform_volumeSet::TMethod TFunc_Instances_fl_media_SoundTransform_volumeSet::Method = &Instances::fl_media::SoundTransform::volumeSet;
typedef ThunkFunc2<Instances::fl_media::Sound, 7, const Value, Instances::fl_net::URLRequest*, Instances::fl_media::SoundLoaderContext*> TFunc_Instances_fl_media_Sound_load;
// @0x14014b240
template <> const TFunc_Instances_fl_media_Sound_load::TMethod TFunc_Instances_fl_media_Sound_load::Method = &Instances::fl_media::Sound::load;
typedef ThunkFunc3<Instances::fl_media::Sound, 8, Value, Value::Number, SInt32, Instances::fl_media::SoundTransform*> TFunc_Instances_fl_media_Sound_play;
// @0x14014b270
template <> const TFunc_Instances_fl_media_Sound_play::TMethod TFunc_Instances_fl_media_Sound_play::Method = &Instances::fl_media::Sound::play;
typedef ThunkFunc0<Class, 0, Value> TFunc_Class_prototypeGet;
// @0x14014b2a0
template <> const TFunc_Class_prototypeGet::TMethod TFunc_Class_prototypeGet::Method = &Class::prototypeGet;
typedef ThunkFunc0<Class, 1, SInt32> TFunc_Class_lengthGet;
// @0x14014b2d0
template <> const TFunc_Class_lengthGet::TMethod TFunc_Class_lengthGet::Method = &Class::lengthGet;
typedef ThunkFunc0<Class, 2, ASString> TFunc_Class_toString;
// @0x14014b300
template <> const TFunc_Class_toString::TMethod TFunc_Class_toString::Method = &Class::toString;
typedef ThunkFunc0<Instances::fl_vec::Vector_String, 3, bool> TFunc_Instances_fl_vec_Vector_String_fixedGet;
// @0x14014b350
template <> const TFunc_Instances_fl_vec_Vector_String_fixedGet::TMethod TFunc_Instances_fl_vec_Vector_String_fixedGet::Method = &Instances::fl_vec::Vector_String::fixedGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_String, 4, ASString> TFunc_Instances_fl_vec_Vector_String_AS3toString;
// @0x14014b380
template <> const TFunc_Instances_fl_vec_Vector_String_AS3toString::TMethod TFunc_Instances_fl_vec_Vector_String_AS3toString::Method = &Instances::fl_vec::Vector_String::AS3toString;
typedef ThunkFunc0<Instances::fl_vec::Vector_String, 5, ASString> TFunc_Instances_fl_vec_Vector_String_AS3toLocaleString;
// @0x14014b3b0
template <> const TFunc_Instances_fl_vec_Vector_String_AS3toLocaleString::TMethod TFunc_Instances_fl_vec_Vector_String_AS3toLocaleString::Method = &Instances::fl_vec::Vector_String::AS3toLocaleString;
typedef ThunkFunc0<Instances::fl_vec::Vector_String, 0, UInt32> TFunc_Instances_fl_vec_Vector_String_lengthGet;
// @0x14014b3e0
template <> const TFunc_Instances_fl_vec_Vector_String_lengthGet::TMethod TFunc_Instances_fl_vec_Vector_String_lengthGet::Method = &Instances::fl_vec::Vector_String::lengthGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_String, 16, SPtr<Instances::fl_vec::Vector_String>> TFunc_Instances_fl_vec_Vector_String_AS3reverse;
// @0x14014b410
template <> const TFunc_Instances_fl_vec_Vector_String_AS3reverse::TMethod TFunc_Instances_fl_vec_Vector_String_AS3reverse::Method = &Instances::fl_vec::Vector_String::AS3reverse;
typedef ThunkFunc0<Instances::fl_vec::Vector_String, 17, ASString> TFunc_Instances_fl_vec_Vector_String_AS3shift;
// @0x14014b440
template <> const TFunc_Instances_fl_vec_Vector_String_AS3shift::TMethod TFunc_Instances_fl_vec_Vector_String_AS3shift::Method = &Instances::fl_vec::Vector_String::AS3shift;
typedef ThunkFunc0<Instances::fl_vec::Vector_String, 15, ASString> TFunc_Instances_fl_vec_Vector_String_AS3pop;
// @0x14014b470
template <> const TFunc_Instances_fl_vec_Vector_String_AS3pop::TMethod TFunc_Instances_fl_vec_Vector_String_AS3pop::Method = &Instances::fl_vec::Vector_String::AS3pop;
typedef ThunkFunc0<Instances::fl_vec::Vector_double, 3, bool> TFunc_Instances_fl_vec_Vector_double_fixedGet;
// @0x14014b4a0
template <> const TFunc_Instances_fl_vec_Vector_double_fixedGet::TMethod TFunc_Instances_fl_vec_Vector_double_fixedGet::Method = &Instances::fl_vec::Vector_double::fixedGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_double, 4, ASString> TFunc_Instances_fl_vec_Vector_double_AS3toString;
// @0x14014b4d0
template <> const TFunc_Instances_fl_vec_Vector_double_AS3toString::TMethod TFunc_Instances_fl_vec_Vector_double_AS3toString::Method = &Instances::fl_vec::Vector_double::AS3toString;
typedef ThunkFunc0<Instances::fl_vec::Vector_double, 5, ASString> TFunc_Instances_fl_vec_Vector_double_AS3toLocaleString;
// @0x14014b500
template <> const TFunc_Instances_fl_vec_Vector_double_AS3toLocaleString::TMethod TFunc_Instances_fl_vec_Vector_double_AS3toLocaleString::Method = &Instances::fl_vec::Vector_double::AS3toLocaleString;
typedef ThunkFunc0<Instances::fl_vec::Vector_double, 0, UInt32> TFunc_Instances_fl_vec_Vector_double_lengthGet;
// @0x14014b530
template <> const TFunc_Instances_fl_vec_Vector_double_lengthGet::TMethod TFunc_Instances_fl_vec_Vector_double_lengthGet::Method = &Instances::fl_vec::Vector_double::lengthGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_double, 16, SPtr<Instances::fl_vec::Vector_double>> TFunc_Instances_fl_vec_Vector_double_AS3reverse;
// @0x14014b560
template <> const TFunc_Instances_fl_vec_Vector_double_AS3reverse::TMethod TFunc_Instances_fl_vec_Vector_double_AS3reverse::Method = &Instances::fl_vec::Vector_double::AS3reverse;
typedef ThunkFunc0<Instances::fl_vec::Vector_double, 17, Value::Number> TFunc_Instances_fl_vec_Vector_double_AS3shift;
// @0x14014b590
template <> const TFunc_Instances_fl_vec_Vector_double_AS3shift::TMethod TFunc_Instances_fl_vec_Vector_double_AS3shift::Method = &Instances::fl_vec::Vector_double::AS3shift;
typedef ThunkFunc0<Instances::fl_vec::Vector_double, 15, Value::Number> TFunc_Instances_fl_vec_Vector_double_AS3pop;
// @0x14014b5c0
template <> const TFunc_Instances_fl_vec_Vector_double_AS3pop::TMethod TFunc_Instances_fl_vec_Vector_double_AS3pop::Method = &Instances::fl_vec::Vector_double::AS3pop;
typedef ThunkFunc0<Instances::fl_vec::Vector_int, 3, bool> TFunc_Instances_fl_vec_Vector_int_fixedGet;
// @0x14014b5f0
template <> const TFunc_Instances_fl_vec_Vector_int_fixedGet::TMethod TFunc_Instances_fl_vec_Vector_int_fixedGet::Method = &Instances::fl_vec::Vector_int::fixedGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_int, 4, ASString> TFunc_Instances_fl_vec_Vector_int_AS3toString;
// @0x14014b620
template <> const TFunc_Instances_fl_vec_Vector_int_AS3toString::TMethod TFunc_Instances_fl_vec_Vector_int_AS3toString::Method = &Instances::fl_vec::Vector_int::AS3toString;
typedef ThunkFunc0<Instances::fl_vec::Vector_int, 5, ASString> TFunc_Instances_fl_vec_Vector_int_AS3toLocaleString;
// @0x14014b650
template <> const TFunc_Instances_fl_vec_Vector_int_AS3toLocaleString::TMethod TFunc_Instances_fl_vec_Vector_int_AS3toLocaleString::Method = &Instances::fl_vec::Vector_int::AS3toLocaleString;
typedef ThunkFunc0<Instances::fl_vec::Vector_int, 0, UInt32> TFunc_Instances_fl_vec_Vector_int_lengthGet;
// @0x14014b680
template <> const TFunc_Instances_fl_vec_Vector_int_lengthGet::TMethod TFunc_Instances_fl_vec_Vector_int_lengthGet::Method = &Instances::fl_vec::Vector_int::lengthGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_int, 16, SPtr<Instances::fl_vec::Vector_int>> TFunc_Instances_fl_vec_Vector_int_AS3reverse;
// @0x14014b6b0
template <> const TFunc_Instances_fl_vec_Vector_int_AS3reverse::TMethod TFunc_Instances_fl_vec_Vector_int_AS3reverse::Method = &Instances::fl_vec::Vector_int::AS3reverse;
typedef ThunkFunc0<Instances::fl_vec::Vector_int, 17, SInt32> TFunc_Instances_fl_vec_Vector_int_AS3shift;
// @0x14014b6e0
template <> const TFunc_Instances_fl_vec_Vector_int_AS3shift::TMethod TFunc_Instances_fl_vec_Vector_int_AS3shift::Method = &Instances::fl_vec::Vector_int::AS3shift;
typedef ThunkFunc0<Instances::fl_vec::Vector_int, 15, SInt32> TFunc_Instances_fl_vec_Vector_int_AS3pop;
// @0x14014b710
template <> const TFunc_Instances_fl_vec_Vector_int_AS3pop::TMethod TFunc_Instances_fl_vec_Vector_int_AS3pop::Method = &Instances::fl_vec::Vector_int::AS3pop;
typedef ThunkFunc0<Instances::fl_vec::Vector_object, 3, bool> TFunc_Instances_fl_vec_Vector_object_fixedGet;
// @0x14014b740
template <> const TFunc_Instances_fl_vec_Vector_object_fixedGet::TMethod TFunc_Instances_fl_vec_Vector_object_fixedGet::Method = &Instances::fl_vec::Vector_object::fixedGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_object, 4, ASString> TFunc_Instances_fl_vec_Vector_object_AS3toString;
// @0x14014b770
template <> const TFunc_Instances_fl_vec_Vector_object_AS3toString::TMethod TFunc_Instances_fl_vec_Vector_object_AS3toString::Method = &Instances::fl_vec::Vector_object::AS3toString;
typedef ThunkFunc0<Instances::fl_vec::Vector_object, 5, ASString> TFunc_Instances_fl_vec_Vector_object_AS3toLocaleString;
// @0x14014b7a0
template <> const TFunc_Instances_fl_vec_Vector_object_AS3toLocaleString::TMethod TFunc_Instances_fl_vec_Vector_object_AS3toLocaleString::Method = &Instances::fl_vec::Vector_object::AS3toLocaleString;
typedef ThunkFunc0<Instances::fl_vec::Vector_object, 0, UInt32> TFunc_Instances_fl_vec_Vector_object_lengthGet;
// @0x14014b7d0
template <> const TFunc_Instances_fl_vec_Vector_object_lengthGet::TMethod TFunc_Instances_fl_vec_Vector_object_lengthGet::Method = &Instances::fl_vec::Vector_object::lengthGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_object, 16, SPtr<Instances::fl_vec::Vector_object>> TFunc_Instances_fl_vec_Vector_object_AS3reverse;
// @0x14014b800
template <> const TFunc_Instances_fl_vec_Vector_object_AS3reverse::TMethod TFunc_Instances_fl_vec_Vector_object_AS3reverse::Method = &Instances::fl_vec::Vector_object::AS3reverse;
typedef ThunkFunc0<Instances::fl_vec::Vector_object, 17, Value> TFunc_Instances_fl_vec_Vector_object_AS3shift;
// @0x14014b830
template <> const TFunc_Instances_fl_vec_Vector_object_AS3shift::TMethod TFunc_Instances_fl_vec_Vector_object_AS3shift::Method = &Instances::fl_vec::Vector_object::AS3shift;
typedef ThunkFunc0<Instances::fl_vec::Vector_object, 15, Value> TFunc_Instances_fl_vec_Vector_object_AS3pop;
// @0x14014b860
template <> const TFunc_Instances_fl_vec_Vector_object_AS3pop::TMethod TFunc_Instances_fl_vec_Vector_object_AS3pop::Method = &Instances::fl_vec::Vector_object::AS3pop;
typedef ThunkFunc0<Instances::fl_vec::Vector_uint, 3, bool> TFunc_Instances_fl_vec_Vector_uint_fixedGet;
// @0x14014b890
template <> const TFunc_Instances_fl_vec_Vector_uint_fixedGet::TMethod TFunc_Instances_fl_vec_Vector_uint_fixedGet::Method = &Instances::fl_vec::Vector_uint::fixedGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_uint, 4, ASString> TFunc_Instances_fl_vec_Vector_uint_AS3toString;
// @0x14014b8c0
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3toString::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3toString::Method = &Instances::fl_vec::Vector_uint::AS3toString;
typedef ThunkFunc0<Instances::fl_vec::Vector_uint, 5, ASString> TFunc_Instances_fl_vec_Vector_uint_AS3toLocaleString;
// @0x14014b8f0
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3toLocaleString::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3toLocaleString::Method = &Instances::fl_vec::Vector_uint::AS3toLocaleString;
typedef ThunkFunc0<Instances::fl_vec::Vector_uint, 0, UInt32> TFunc_Instances_fl_vec_Vector_uint_lengthGet;
// @0x14014b920
template <> const TFunc_Instances_fl_vec_Vector_uint_lengthGet::TMethod TFunc_Instances_fl_vec_Vector_uint_lengthGet::Method = &Instances::fl_vec::Vector_uint::lengthGet;
typedef ThunkFunc0<Instances::fl_vec::Vector_uint, 16, SPtr<Instances::fl_vec::Vector_uint>> TFunc_Instances_fl_vec_Vector_uint_AS3reverse;
// @0x14014b950
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3reverse::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3reverse::Method = &Instances::fl_vec::Vector_uint::AS3reverse;
typedef ThunkFunc0<Instances::fl_vec::Vector_uint, 17, UInt32> TFunc_Instances_fl_vec_Vector_uint_AS3shift;
// @0x14014b980
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3shift::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3shift::Method = &Instances::fl_vec::Vector_uint::AS3shift;
typedef ThunkFunc0<Instances::fl_vec::Vector_uint, 15, UInt32> TFunc_Instances_fl_vec_Vector_uint_AS3pop;
// @0x14014b9b0
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3pop::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3pop::Method = &Instances::fl_vec::Vector_uint::AS3pop;
typedef ThunkFunc1<Instances::fl_vec::Vector_String, 1, const Value, UInt32> TFunc_Instances_fl_vec_Vector_String_lengthSet;
// @0x14014b9e0
template <> const TFunc_Instances_fl_vec_Vector_String_lengthSet::TMethod TFunc_Instances_fl_vec_Vector_String_lengthSet::Method = &Instances::fl_vec::Vector_String::lengthSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_String, 2, const Value, bool> TFunc_Instances_fl_vec_Vector_String_fixedSet;
// @0x14014ba10
template <> const TFunc_Instances_fl_vec_Vector_String_fixedSet::TMethod TFunc_Instances_fl_vec_Vector_String_fixedSet::Method = &Instances::fl_vec::Vector_String::fixedSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_String, 6, ASString, const ASString&> TFunc_Instances_fl_vec_Vector_String_AS3join;
// @0x14014ba40
template <> const TFunc_Instances_fl_vec_Vector_String_AS3join::TMethod TFunc_Instances_fl_vec_Vector_String_AS3join::Method = &Instances::fl_vec::Vector_String::AS3join;
typedef ThunkFunc1<Instances::fl_vec::Vector_double, 1, const Value, UInt32> TFunc_Instances_fl_vec_Vector_double_lengthSet;
// @0x14014ba70
template <> const TFunc_Instances_fl_vec_Vector_double_lengthSet::TMethod TFunc_Instances_fl_vec_Vector_double_lengthSet::Method = &Instances::fl_vec::Vector_double::lengthSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_double, 2, const Value, bool> TFunc_Instances_fl_vec_Vector_double_fixedSet;
// @0x14014baa0
template <> const TFunc_Instances_fl_vec_Vector_double_fixedSet::TMethod TFunc_Instances_fl_vec_Vector_double_fixedSet::Method = &Instances::fl_vec::Vector_double::fixedSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_double, 6, ASString, const ASString&> TFunc_Instances_fl_vec_Vector_double_AS3join;
// @0x14014bad0
template <> const TFunc_Instances_fl_vec_Vector_double_AS3join::TMethod TFunc_Instances_fl_vec_Vector_double_AS3join::Method = &Instances::fl_vec::Vector_double::AS3join;
typedef ThunkFunc1<Instances::fl_vec::Vector_int, 1, const Value, UInt32> TFunc_Instances_fl_vec_Vector_int_lengthSet;
// @0x14014bb00
template <> const TFunc_Instances_fl_vec_Vector_int_lengthSet::TMethod TFunc_Instances_fl_vec_Vector_int_lengthSet::Method = &Instances::fl_vec::Vector_int::lengthSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_int, 2, const Value, bool> TFunc_Instances_fl_vec_Vector_int_fixedSet;
// @0x14014bb30
template <> const TFunc_Instances_fl_vec_Vector_int_fixedSet::TMethod TFunc_Instances_fl_vec_Vector_int_fixedSet::Method = &Instances::fl_vec::Vector_int::fixedSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_int, 6, ASString, const ASString&> TFunc_Instances_fl_vec_Vector_int_AS3join;
// @0x14014bb60
template <> const TFunc_Instances_fl_vec_Vector_int_AS3join::TMethod TFunc_Instances_fl_vec_Vector_int_AS3join::Method = &Instances::fl_vec::Vector_int::AS3join;
typedef ThunkFunc1<Instances::fl_vec::Vector_object, 1, const Value, UInt32> TFunc_Instances_fl_vec_Vector_object_lengthSet;
// @0x14014bb90
template <> const TFunc_Instances_fl_vec_Vector_object_lengthSet::TMethod TFunc_Instances_fl_vec_Vector_object_lengthSet::Method = &Instances::fl_vec::Vector_object::lengthSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_object, 2, const Value, bool> TFunc_Instances_fl_vec_Vector_object_fixedSet;
// @0x14014bbc0
template <> const TFunc_Instances_fl_vec_Vector_object_fixedSet::TMethod TFunc_Instances_fl_vec_Vector_object_fixedSet::Method = &Instances::fl_vec::Vector_object::fixedSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_object, 6, ASString, const ASString&> TFunc_Instances_fl_vec_Vector_object_AS3join;
// @0x14014bbf0
template <> const TFunc_Instances_fl_vec_Vector_object_AS3join::TMethod TFunc_Instances_fl_vec_Vector_object_AS3join::Method = &Instances::fl_vec::Vector_object::AS3join;
typedef ThunkFunc1<Instances::fl_vec::Vector_uint, 1, const Value, UInt32> TFunc_Instances_fl_vec_Vector_uint_lengthSet;
// @0x14014bc20
template <> const TFunc_Instances_fl_vec_Vector_uint_lengthSet::TMethod TFunc_Instances_fl_vec_Vector_uint_lengthSet::Method = &Instances::fl_vec::Vector_uint::lengthSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_uint, 2, const Value, bool> TFunc_Instances_fl_vec_Vector_uint_fixedSet;
// @0x14014bc50
template <> const TFunc_Instances_fl_vec_Vector_uint_fixedSet::TMethod TFunc_Instances_fl_vec_Vector_uint_fixedSet::Method = &Instances::fl_vec::Vector_uint::fixedSet;
typedef ThunkFunc1<Instances::fl_vec::Vector_uint, 6, ASString, const ASString&> TFunc_Instances_fl_vec_Vector_uint_AS3join;
// @0x14014bc80
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3join::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3join::Method = &Instances::fl_vec::Vector_uint::AS3join;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 7, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_String_AS3every;
// @0x14014bcb0
template <> const TFunc_Instances_fl_vec_Vector_String_AS3every::TMethod TFunc_Instances_fl_vec_Vector_String_AS3every::Method = &Instances::fl_vec::Vector_String::AS3every;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 8, const Value, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_String_AS3forEach;
// @0x14014bce0
template <> const TFunc_Instances_fl_vec_Vector_String_AS3forEach::TMethod TFunc_Instances_fl_vec_Vector_String_AS3forEach::Method = &Instances::fl_vec::Vector_String::AS3forEach;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 9, SPtr<Instances::fl_vec::Vector_String>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_String_AS3map;
// @0x14014bd10
template <> const TFunc_Instances_fl_vec_Vector_String_AS3map::TMethod TFunc_Instances_fl_vec_Vector_String_AS3map::Method = &Instances::fl_vec::Vector_String::AS3map;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 10, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_String_AS3push;
// @0x14014bd40
template <> const TFunc_Instances_fl_vec_Vector_String_AS3push::TMethod TFunc_Instances_fl_vec_Vector_String_AS3push::Method = &Instances::fl_vec::Vector_String::AS3push;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 18, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_String_AS3slice;
// @0x14014bd70
template <> const TFunc_Instances_fl_vec_Vector_String_AS3slice::TMethod TFunc_Instances_fl_vec_Vector_String_AS3slice::Method = &Instances::fl_vec::Vector_String::AS3slice;
typedef ThunkFunc1<Instances::fl_vec::Vector_String, 19, SPtr<Instances::fl_vec::Vector_String>, const Value&> TFunc_Instances_fl_vec_Vector_String_AS3sort;
// @0x14014bda0
template <> const TFunc_Instances_fl_vec_Vector_String_AS3sort::TMethod TFunc_Instances_fl_vec_Vector_String_AS3sort::Method = &Instances::fl_vec::Vector_String::AS3sort;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 20, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_String_AS3splice;
// @0x14014bdd0
template <> const TFunc_Instances_fl_vec_Vector_String_AS3splice::TMethod TFunc_Instances_fl_vec_Vector_String_AS3splice::Method = &Instances::fl_vec::Vector_String::AS3splice;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 21, SInt32, const ASString&, SInt32> TFunc_Instances_fl_vec_Vector_String_AS3indexOf;
// @0x14014be00
template <> const TFunc_Instances_fl_vec_Vector_String_AS3indexOf::TMethod TFunc_Instances_fl_vec_Vector_String_AS3indexOf::Method = &Instances::fl_vec::Vector_String::AS3indexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 22, SInt32, const ASString&, SInt32> TFunc_Instances_fl_vec_Vector_String_AS3lastIndexOf;
// @0x14014be30
template <> const TFunc_Instances_fl_vec_Vector_String_AS3lastIndexOf::TMethod TFunc_Instances_fl_vec_Vector_String_AS3lastIndexOf::Method = &Instances::fl_vec::Vector_String::AS3lastIndexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 11, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_String_AS3some;
// @0x14014be60
template <> const TFunc_Instances_fl_vec_Vector_String_AS3some::TMethod TFunc_Instances_fl_vec_Vector_String_AS3some::Method = &Instances::fl_vec::Vector_String::AS3some;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 12, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_String_AS3unshift;
// @0x14014be90
template <> const TFunc_Instances_fl_vec_Vector_String_AS3unshift::TMethod TFunc_Instances_fl_vec_Vector_String_AS3unshift::Method = &Instances::fl_vec::Vector_String::AS3unshift;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 13, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_String_AS3concat;
// @0x14014bec0
template <> const TFunc_Instances_fl_vec_Vector_String_AS3concat::TMethod TFunc_Instances_fl_vec_Vector_String_AS3concat::Method = &Instances::fl_vec::Vector_String::AS3concat;
typedef ThunkFunc2<Instances::fl_vec::Vector_String, 14, SPtr<Instances::fl_vec::Vector_String>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_String_AS3filter;
// @0x14014bef0
template <> const TFunc_Instances_fl_vec_Vector_String_AS3filter::TMethod TFunc_Instances_fl_vec_Vector_String_AS3filter::Method = &Instances::fl_vec::Vector_String::AS3filter;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 7, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_double_AS3every;
// @0x14014bf20
template <> const TFunc_Instances_fl_vec_Vector_double_AS3every::TMethod TFunc_Instances_fl_vec_Vector_double_AS3every::Method = &Instances::fl_vec::Vector_double::AS3every;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 8, const Value, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_double_AS3forEach;
// @0x14014bf50
template <> const TFunc_Instances_fl_vec_Vector_double_AS3forEach::TMethod TFunc_Instances_fl_vec_Vector_double_AS3forEach::Method = &Instances::fl_vec::Vector_double::AS3forEach;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 9, SPtr<Instances::fl_vec::Vector_double>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_double_AS3map;
// @0x14014bf80
template <> const TFunc_Instances_fl_vec_Vector_double_AS3map::TMethod TFunc_Instances_fl_vec_Vector_double_AS3map::Method = &Instances::fl_vec::Vector_double::AS3map;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 10, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_double_AS3push;
// @0x14014bfb0
template <> const TFunc_Instances_fl_vec_Vector_double_AS3push::TMethod TFunc_Instances_fl_vec_Vector_double_AS3push::Method = &Instances::fl_vec::Vector_double::AS3push;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 18, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_double_AS3slice;
// @0x14014bfe0
template <> const TFunc_Instances_fl_vec_Vector_double_AS3slice::TMethod TFunc_Instances_fl_vec_Vector_double_AS3slice::Method = &Instances::fl_vec::Vector_double::AS3slice;
typedef ThunkFunc1<Instances::fl_vec::Vector_double, 19, SPtr<Instances::fl_vec::Vector_double>, const Value&> TFunc_Instances_fl_vec_Vector_double_AS3sort;
// @0x14014c010
template <> const TFunc_Instances_fl_vec_Vector_double_AS3sort::TMethod TFunc_Instances_fl_vec_Vector_double_AS3sort::Method = &Instances::fl_vec::Vector_double::AS3sort;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 20, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_double_AS3splice;
// @0x14014c040
template <> const TFunc_Instances_fl_vec_Vector_double_AS3splice::TMethod TFunc_Instances_fl_vec_Vector_double_AS3splice::Method = &Instances::fl_vec::Vector_double::AS3splice;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 21, SInt32, Value::Number, SInt32> TFunc_Instances_fl_vec_Vector_double_AS3indexOf;
// @0x14014c070
template <> const TFunc_Instances_fl_vec_Vector_double_AS3indexOf::TMethod TFunc_Instances_fl_vec_Vector_double_AS3indexOf::Method = &Instances::fl_vec::Vector_double::AS3indexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 22, SInt32, Value::Number, SInt32> TFunc_Instances_fl_vec_Vector_double_AS3lastIndexOf;
// @0x14014c0a0
template <> const TFunc_Instances_fl_vec_Vector_double_AS3lastIndexOf::TMethod TFunc_Instances_fl_vec_Vector_double_AS3lastIndexOf::Method = &Instances::fl_vec::Vector_double::AS3lastIndexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 11, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_double_AS3some;
// @0x14014c0d0
template <> const TFunc_Instances_fl_vec_Vector_double_AS3some::TMethod TFunc_Instances_fl_vec_Vector_double_AS3some::Method = &Instances::fl_vec::Vector_double::AS3some;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 12, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_double_AS3unshift;
// @0x14014c100
template <> const TFunc_Instances_fl_vec_Vector_double_AS3unshift::TMethod TFunc_Instances_fl_vec_Vector_double_AS3unshift::Method = &Instances::fl_vec::Vector_double::AS3unshift;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 13, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_double_AS3concat;
// @0x14014c130
template <> const TFunc_Instances_fl_vec_Vector_double_AS3concat::TMethod TFunc_Instances_fl_vec_Vector_double_AS3concat::Method = &Instances::fl_vec::Vector_double::AS3concat;
typedef ThunkFunc2<Instances::fl_vec::Vector_double, 14, SPtr<Instances::fl_vec::Vector_double>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_double_AS3filter;
// @0x14014c160
template <> const TFunc_Instances_fl_vec_Vector_double_AS3filter::TMethod TFunc_Instances_fl_vec_Vector_double_AS3filter::Method = &Instances::fl_vec::Vector_double::AS3filter;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 7, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_int_AS3every;
// @0x14014c190
template <> const TFunc_Instances_fl_vec_Vector_int_AS3every::TMethod TFunc_Instances_fl_vec_Vector_int_AS3every::Method = &Instances::fl_vec::Vector_int::AS3every;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 8, const Value, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_int_AS3forEach;
// @0x14014c1c0
template <> const TFunc_Instances_fl_vec_Vector_int_AS3forEach::TMethod TFunc_Instances_fl_vec_Vector_int_AS3forEach::Method = &Instances::fl_vec::Vector_int::AS3forEach;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 9, SPtr<Instances::fl_vec::Vector_int>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_int_AS3map;
// @0x14014c1f0
template <> const TFunc_Instances_fl_vec_Vector_int_AS3map::TMethod TFunc_Instances_fl_vec_Vector_int_AS3map::Method = &Instances::fl_vec::Vector_int::AS3map;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 10, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_int_AS3push;
// @0x14014c220
template <> const TFunc_Instances_fl_vec_Vector_int_AS3push::TMethod TFunc_Instances_fl_vec_Vector_int_AS3push::Method = &Instances::fl_vec::Vector_int::AS3push;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 18, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_int_AS3slice;
// @0x14014c250
template <> const TFunc_Instances_fl_vec_Vector_int_AS3slice::TMethod TFunc_Instances_fl_vec_Vector_int_AS3slice::Method = &Instances::fl_vec::Vector_int::AS3slice;
typedef ThunkFunc1<Instances::fl_vec::Vector_int, 19, SPtr<Instances::fl_vec::Vector_int>, const Value&> TFunc_Instances_fl_vec_Vector_int_AS3sort;
// @0x14014c280
template <> const TFunc_Instances_fl_vec_Vector_int_AS3sort::TMethod TFunc_Instances_fl_vec_Vector_int_AS3sort::Method = &Instances::fl_vec::Vector_int::AS3sort;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 20, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_int_AS3splice;
// @0x14014c2b0
template <> const TFunc_Instances_fl_vec_Vector_int_AS3splice::TMethod TFunc_Instances_fl_vec_Vector_int_AS3splice::Method = &Instances::fl_vec::Vector_int::AS3splice;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 21, SInt32, SInt32, SInt32> TFunc_Instances_fl_vec_Vector_int_AS3indexOf;
// @0x14014c2e0
template <> const TFunc_Instances_fl_vec_Vector_int_AS3indexOf::TMethod TFunc_Instances_fl_vec_Vector_int_AS3indexOf::Method = &Instances::fl_vec::Vector_int::AS3indexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 22, SInt32, SInt32, SInt32> TFunc_Instances_fl_vec_Vector_int_AS3lastIndexOf;
// @0x14014c310
template <> const TFunc_Instances_fl_vec_Vector_int_AS3lastIndexOf::TMethod TFunc_Instances_fl_vec_Vector_int_AS3lastIndexOf::Method = &Instances::fl_vec::Vector_int::AS3lastIndexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 11, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_int_AS3some;
// @0x14014c340
template <> const TFunc_Instances_fl_vec_Vector_int_AS3some::TMethod TFunc_Instances_fl_vec_Vector_int_AS3some::Method = &Instances::fl_vec::Vector_int::AS3some;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 12, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_int_AS3unshift;
// @0x14014c370
template <> const TFunc_Instances_fl_vec_Vector_int_AS3unshift::TMethod TFunc_Instances_fl_vec_Vector_int_AS3unshift::Method = &Instances::fl_vec::Vector_int::AS3unshift;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 13, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_int_AS3concat;
// @0x14014c3a0
template <> const TFunc_Instances_fl_vec_Vector_int_AS3concat::TMethod TFunc_Instances_fl_vec_Vector_int_AS3concat::Method = &Instances::fl_vec::Vector_int::AS3concat;
typedef ThunkFunc2<Instances::fl_vec::Vector_int, 14, SPtr<Instances::fl_vec::Vector_int>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_int_AS3filter;
// @0x14014c3d0
template <> const TFunc_Instances_fl_vec_Vector_int_AS3filter::TMethod TFunc_Instances_fl_vec_Vector_int_AS3filter::Method = &Instances::fl_vec::Vector_int::AS3filter;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 7, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_object_AS3every;
// @0x14014c400
template <> const TFunc_Instances_fl_vec_Vector_object_AS3every::TMethod TFunc_Instances_fl_vec_Vector_object_AS3every::Method = &Instances::fl_vec::Vector_object::AS3every;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 8, const Value, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_object_AS3forEach;
// @0x14014c430
template <> const TFunc_Instances_fl_vec_Vector_object_AS3forEach::TMethod TFunc_Instances_fl_vec_Vector_object_AS3forEach::Method = &Instances::fl_vec::Vector_object::AS3forEach;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 9, SPtr<Instances::fl_vec::Vector_object>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_object_AS3map;
// @0x14014c460
template <> const TFunc_Instances_fl_vec_Vector_object_AS3map::TMethod TFunc_Instances_fl_vec_Vector_object_AS3map::Method = &Instances::fl_vec::Vector_object::AS3map;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 10, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_object_AS3push;
// @0x14014c490
template <> const TFunc_Instances_fl_vec_Vector_object_AS3push::TMethod TFunc_Instances_fl_vec_Vector_object_AS3push::Method = &Instances::fl_vec::Vector_object::AS3push;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 18, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_object_AS3slice;
// @0x14014c4c0
template <> const TFunc_Instances_fl_vec_Vector_object_AS3slice::TMethod TFunc_Instances_fl_vec_Vector_object_AS3slice::Method = &Instances::fl_vec::Vector_object::AS3slice;
typedef ThunkFunc1<Instances::fl_vec::Vector_object, 19, SPtr<Instances::fl_vec::Vector_object>, const Value&> TFunc_Instances_fl_vec_Vector_object_AS3sort;
// @0x14014c4f0
template <> const TFunc_Instances_fl_vec_Vector_object_AS3sort::TMethod TFunc_Instances_fl_vec_Vector_object_AS3sort::Method = &Instances::fl_vec::Vector_object::AS3sort;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 20, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_object_AS3splice;
// @0x14014c520
template <> const TFunc_Instances_fl_vec_Vector_object_AS3splice::TMethod TFunc_Instances_fl_vec_Vector_object_AS3splice::Method = &Instances::fl_vec::Vector_object::AS3splice;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 21, SInt32, const Value&, SInt32> TFunc_Instances_fl_vec_Vector_object_AS3indexOf;
// @0x14014c550
template <> const TFunc_Instances_fl_vec_Vector_object_AS3indexOf::TMethod TFunc_Instances_fl_vec_Vector_object_AS3indexOf::Method = &Instances::fl_vec::Vector_object::AS3indexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 22, SInt32, const Value&, SInt32> TFunc_Instances_fl_vec_Vector_object_AS3lastIndexOf;
// @0x14014c580
template <> const TFunc_Instances_fl_vec_Vector_object_AS3lastIndexOf::TMethod TFunc_Instances_fl_vec_Vector_object_AS3lastIndexOf::Method = &Instances::fl_vec::Vector_object::AS3lastIndexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 11, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_object_AS3some;
// @0x14014c5b0
template <> const TFunc_Instances_fl_vec_Vector_object_AS3some::TMethod TFunc_Instances_fl_vec_Vector_object_AS3some::Method = &Instances::fl_vec::Vector_object::AS3some;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 12, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_object_AS3unshift;
// @0x14014c5e0
template <> const TFunc_Instances_fl_vec_Vector_object_AS3unshift::TMethod TFunc_Instances_fl_vec_Vector_object_AS3unshift::Method = &Instances::fl_vec::Vector_object::AS3unshift;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 13, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_object_AS3concat;
// @0x14014c610
template <> const TFunc_Instances_fl_vec_Vector_object_AS3concat::TMethod TFunc_Instances_fl_vec_Vector_object_AS3concat::Method = &Instances::fl_vec::Vector_object::AS3concat;
typedef ThunkFunc2<Instances::fl_vec::Vector_object, 14, SPtr<Instances::fl_vec::Vector_object>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_object_AS3filter;
// @0x14014c640
template <> const TFunc_Instances_fl_vec_Vector_object_AS3filter::TMethod TFunc_Instances_fl_vec_Vector_object_AS3filter::Method = &Instances::fl_vec::Vector_object::AS3filter;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 7, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_uint_AS3every;
// @0x14014c670
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3every::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3every::Method = &Instances::fl_vec::Vector_uint::AS3every;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 8, const Value, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_uint_AS3forEach;
// @0x14014c6a0
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3forEach::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3forEach::Method = &Instances::fl_vec::Vector_uint::AS3forEach;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 9, SPtr<Instances::fl_vec::Vector_uint>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_uint_AS3map;
// @0x14014c6d0
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3map::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3map::Method = &Instances::fl_vec::Vector_uint::AS3map;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 10, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_uint_AS3push;
// @0x14014c700
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3push::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3push::Method = &Instances::fl_vec::Vector_uint::AS3push;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 18, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_uint_AS3slice;
// @0x14014c730
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3slice::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3slice::Method = &Instances::fl_vec::Vector_uint::AS3slice;
typedef ThunkFunc1<Instances::fl_vec::Vector_uint, 19, SPtr<Instances::fl_vec::Vector_uint>, const Value&> TFunc_Instances_fl_vec_Vector_uint_AS3sort;
// @0x14014c760
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3sort::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3sort::Method = &Instances::fl_vec::Vector_uint::AS3sort;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 20, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_uint_AS3splice;
// @0x14014c790
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3splice::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3splice::Method = &Instances::fl_vec::Vector_uint::AS3splice;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 21, SInt32, UInt32, SInt32> TFunc_Instances_fl_vec_Vector_uint_AS3indexOf;
// @0x14014c7c0
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3indexOf::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3indexOf::Method = &Instances::fl_vec::Vector_uint::AS3indexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 22, SInt32, UInt32, SInt32> TFunc_Instances_fl_vec_Vector_uint_AS3lastIndexOf;
// @0x14014c7f0
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3lastIndexOf::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3lastIndexOf::Method = &Instances::fl_vec::Vector_uint::AS3lastIndexOf;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 11, bool, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_uint_AS3some;
// @0x14014c820
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3some::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3some::Method = &Instances::fl_vec::Vector_uint::AS3some;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 12, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_uint_AS3unshift;
// @0x14014c850
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3unshift::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3unshift::Method = &Instances::fl_vec::Vector_uint::AS3unshift;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 13, Value, unsigned, const Value*> TFunc_Instances_fl_vec_Vector_uint_AS3concat;
// @0x14014c880
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3concat::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3concat::Method = &Instances::fl_vec::Vector_uint::AS3concat;
typedef ThunkFunc2<Instances::fl_vec::Vector_uint, 14, SPtr<Instances::fl_vec::Vector_uint>, const Value&, const Value&> TFunc_Instances_fl_vec_Vector_uint_AS3filter;
// @0x14014c8b0
template <> const TFunc_Instances_fl_vec_Vector_uint_AS3filter::TMethod TFunc_Instances_fl_vec_Vector_uint_AS3filter::Method = &Instances::fl_vec::Vector_uint::AS3filter;

}}} // namespace Scaleform::GFx::AS3

