// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_12
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142498890-0x1424abbe0 .text$mn
// MS2-RANGE: 0x1424ad4d0-0x1424ad870 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/gfx_imemanager.h"
#include "ms2/scaleform/include/render/render_font.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_sharedobject.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_net_soloader.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/gfx/gfx_statictextcharacter.h"
#include "ms2/scaleform/include/gfx/gfx_asutils.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x14249c500: Classes::fl_system::Capabilities::avHardwareDisableGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 0, bool>;
// thunk 0x14249c560: Classes::fl_system::Capabilities::hasAccessibilityGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 1, bool>;
// thunk 0x14249c5c0: Classes::fl_system::Capabilities::hasAudioGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 2, bool>;
// thunk 0x14249c620: Classes::fl_system::Capabilities::hasAudioEncoderGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 3, bool>;
// thunk 0x14249c680: Classes::fl_system::Capabilities::hasEmbeddedVideoGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 4, bool>;
// thunk 0x14249c6e0: Classes::fl_system::Capabilities::hasIMEGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 5, bool>;
// thunk 0x14249c740: Classes::fl_system::Capabilities::hasMP3Get
template struct ThunkFunc0<Classes::fl_system::Capabilities, 6, bool>;
// thunk 0x14249c7a0: Classes::fl_system::Capabilities::hasPrintingGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 7, bool>;
// thunk 0x14249c800: Classes::fl_system::Capabilities::hasScreenBroadcastGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 8, bool>;
// thunk 0x14249c860: Classes::fl_system::Capabilities::hasScreenPlaybackGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 9, bool>;
// thunk 0x14249c8c0: Classes::fl_system::Capabilities::hasStreamingAudioGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 10, bool>;
// thunk 0x14249c920: Classes::fl_system::Capabilities::hasStreamingVideoGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 11, bool>;
// thunk 0x14249c980: Instances::fl_system::ApplicationDomain::parentDomainGet
template struct ThunkFunc0<Instances::fl_system::ApplicationDomain, 0, SPtr<Instances::fl_system::ApplicationDomain>>;
// thunk 0x14249ca30: Classes::fl_system::Capabilities::hasTLSGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 12, bool>;
// thunk 0x14249ca90: Classes::fl_system::Capabilities::hasVideoEncoderGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 13, bool>;
// thunk 0x14249caf0: Instances::fl_system::ApplicationDomain::getDefinition
// MS2-FUNCTIONAL: not matched: the Value result with a string argument (the exe releases the default string at the end)
template struct ThunkFunc1<Instances::fl_system::ApplicationDomain, 1, Value, const ASString&>;
// thunk 0x14249cc70: Classes::fl_system::Capabilities::isDebuggerGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 14, bool>;
// thunk 0x14249ccd0: Instances::fl_system::ApplicationDomain::hasDefinition
template struct ThunkFunc1<Instances::fl_system::ApplicationDomain, 2, bool, const ASString&>;
// thunk 0x14249ce10: Classes::fl_system::Capabilities::languageGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 15, ASString>;
// thunk 0x14249ce80: Classes::fl_system::Capabilities::localFileReadDisableGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 16, bool>;
// thunk 0x14249cee0: Classes::fl_system::Capabilities::manufacturerGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 17, ASString>;
// thunk 0x14249cf50: Classes::fl_system::Capabilities::osGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 18, ASString>;
// thunk 0x14249cfc0: Classes::fl_system::Capabilities::pixelAspectRatioGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 19, Value::Number>;
// thunk 0x14249d030: Classes::fl_system::Capabilities::playerTypeGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 20, ASString>;
// thunk 0x14249d1e0: Classes::fl_system::Capabilities::screenColorGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 21, ASString>;
// thunk 0x14249d250: Classes::fl_system::Capabilities::screenDPIGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 22, Value::Number>;
// thunk 0x14249d2c0: Classes::fl_system::Capabilities::screenResolutionXGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 23, Value::Number>;
// thunk 0x14249d330: Classes::fl_system::Capabilities::screenResolutionYGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 24, Value::Number>;
// thunk 0x14249d3a0: Classes::fl_system::Capabilities::serverStringGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 25, ASString>;
// thunk 0x14249d410: Classes::fl_system::Capabilities::versionGet
template struct ThunkFunc0<Classes::fl_system::Capabilities, 26, ASString>;
// thunk 0x14249d5c0: Classes::fl_system::IME::conversionModeSet
template struct ThunkFunc1<Classes::fl_system::IME, 0, const Value, const ASString&>;
// thunk 0x14249d6c0: Classes::fl_system::IME::conversionModeGet
template struct ThunkFunc0<Classes::fl_system::IME, 1, ASString>;
// thunk 0x14249d730: Classes::fl_system::IME::enabledGet
template struct ThunkFunc0<Classes::fl_system::IME, 2, bool>;
// thunk 0x14249d790: Classes::fl_system::IME::enabledSet
template struct ThunkFunc1<Classes::fl_system::IME, 3, const Value, bool>;
// thunk 0x14249d7f0: Classes::fl_system::IME::doConversion
template struct ThunkFunc0<Classes::fl_system::IME, 4, const Value>;
// thunk 0x14249d810: Classes::fl_system::IME::setCompositionString
template struct ThunkFunc1<Classes::fl_system::IME, 5, const Value, const ASString&>;
// thunk 0x14249deb0: Classes::fl_system::SecurityDomain::currentDomainGet
template struct ThunkFunc0<Classes::fl_system::SecurityDomain, 0, SPtr<Instances::fl_system::SecurityDomain>>;
// thunk 0x14249e230: Classes::fl_system::System::imeGet
template struct ThunkFunc0<Classes::fl_system::System, 0, Value>;
// thunk 0x14249e250: Classes::fl_system::System::totalMemoryGet
template struct ThunkFunc0<Classes::fl_system::System, 1, UInt32>;
// thunk 0x14249e2b0: Classes::fl_system::System::exit
template struct ThunkFunc1<Classes::fl_system::System, 2, const Value, UInt32>;
// thunk 0x14249e320: Classes::fl_system::System::gc
template struct ThunkFunc0<Classes::fl_system::System, 3, const Value>;
// thunk 0x14249e340: Classes::fl_system::System::pause
template struct ThunkFunc0<Classes::fl_system::System, 4, const Value>;
// thunk 0x14249e360: Classes::fl_system::System::resume
template struct ThunkFunc0<Classes::fl_system::System, 5, const Value>;
// thunk 0x14249e380: Classes::fl_system::System::setClipboard
template struct ThunkFunc1<Classes::fl_system::System, 6, const Value, const ASString&>;
// thunk 0x1424a0cb0: Instances::fl_text::TextField::caretIndexGet
template struct ThunkFunc0<Instances::fl_text::TextField, 15, SInt32>;
// thunk 0x1424a0d10: Instances::fl_text::TextField::condenseWhiteGet
template struct ThunkFunc0<Instances::fl_text::TextField, 16, bool>;
// thunk 0x1424a0d70: Instances::fl_text::TextField::condenseWhiteSet
template struct ThunkFunc1<Instances::fl_text::TextField, 17, const Value, bool>;
// thunk 0x1424a0f10: Instances::fl_text::TextField::defaultTextFormatGet
template struct ThunkFunc0<Instances::fl_text::TextField, 18, SPtr<Instances::fl_text::TextFormat>>;
// thunk 0x1424a0fc0: Instances::fl_text::TextField::defaultTextFormatSet
template struct ThunkFunc1<Instances::fl_text::TextField, 19, const Value, Instances::fl_text::TextFormat*>;
// thunk 0x1424a1000: Instances::fl_text::TextField::displayAsPasswordGet
template struct ThunkFunc0<Instances::fl_text::TextField, 20, bool>;
// thunk 0x1424a1060: Instances::fl_text::TextField::displayAsPasswordSet
template struct ThunkFunc1<Instances::fl_text::TextField, 21, const Value, bool>;
// thunk 0x1424a10c0: Instances::fl_text::TextField::embedFontsGet
template struct ThunkFunc0<Instances::fl_text::TextField, 22, bool>;
// thunk 0x1424a1120: Instances::fl_text::TextField::embedFontsSet
template struct ThunkFunc1<Instances::fl_text::TextField, 23, const Value, bool>;
// thunk 0x1424a1180: Instances::fl_text::TextField::gridFitTypeGet
template struct ThunkFunc0<Instances::fl_text::TextField, 24, ASString>;
// thunk 0x1424a11f0: Instances::fl_text::StyleSheet::styleNamesGet
template struct ThunkFunc0<Instances::fl_text::StyleSheet, 0, SPtr<Instances::fl::Array>>;
// thunk 0x1424a12a0: Instances::fl_text::TextField::gridFitTypeSet
template struct ThunkFunc1<Instances::fl_text::TextField, 25, const Value, const ASString&>;
// thunk 0x1424a13a0: Instances::fl_text::StyleSheet::clear
template struct ThunkFunc0<Instances::fl_text::StyleSheet, 1, const Value>;
// thunk 0x1424a13c0: Instances::fl_text::TextField::htmlTextGet
template struct ThunkFunc0<Instances::fl_text::TextField, 26, ASString>;
// thunk 0x1424a1430: Instances::fl_text::StyleSheet::getStyle
template struct ThunkFunc1<Instances::fl_text::StyleSheet, 2, SPtr<Instances::fl::Object>, const ASString&>;
// thunk 0x1424a15b0: Instances::fl_text::TextField::htmlTextSet
template struct ThunkFunc1<Instances::fl_text::TextField, 27, const Value, const ASString&>;
// thunk 0x1424a16b0: Instances::fl_text::TextField::lengthGet
template struct ThunkFunc0<Instances::fl_text::TextField, 28, SInt32>;
// thunk 0x1424a1710: Instances::fl_text::StyleSheet::parseCSS
template struct ThunkFunc1<Instances::fl_text::StyleSheet, 3, const Value, const ASString&>;
// thunk 0x1424a1810: Instances::fl_text::TextField::maxCharsGet
template struct ThunkFunc0<Instances::fl_text::TextField, 29, SInt32>;
// thunk 0x1424a1870: Instances::fl_text::StyleSheet::setStyle
template struct ThunkFunc2<Instances::fl_text::StyleSheet, 4, const Value, const ASString&, const Value&>;
// thunk 0x1424a1a50: Instances::fl_text::TextField::maxCharsSet
template struct ThunkFunc1<Instances::fl_text::TextField, 30, const Value, SInt32>;
// thunk 0x1424a1ac0: Instances::fl_text::StyleSheet::transform
template struct ThunkFunc1<Instances::fl_text::StyleSheet, 5, SPtr<Instances::fl_text::TextFormat>, const Value&>;
// thunk 0x1424a1c80: Instances::fl_text::TextField::maxScrollHGet
template struct ThunkFunc0<Instances::fl_text::TextField, 31, SInt32>;
// thunk 0x1424a1ce0: Instances::fl_text::TextField::maxScrollVGet
template struct ThunkFunc0<Instances::fl_text::TextField, 32, SInt32>;
// thunk 0x1424a1d40: Instances::fl_text::TextField::mouseWheelEnabledGet
template struct ThunkFunc0<Instances::fl_text::TextField, 33, bool>;
// thunk 0x1424a1da0: Instances::fl_text::TextField::mouseWheelEnabledSet
template struct ThunkFunc1<Instances::fl_text::TextField, 34, const Value, bool>;
// thunk 0x1424a1e00: Instances::fl_text::TextField::multilineGet
template struct ThunkFunc0<Instances::fl_text::TextField, 35, bool>;
// thunk 0x1424a1e60: Instances::fl_text::TextField::multilineSet
template struct ThunkFunc1<Instances::fl_text::TextField, 36, const Value, bool>;
// thunk 0x1424a1ec0: Instances::fl_text::TextField::numLinesGet
template struct ThunkFunc0<Instances::fl_text::TextField, 37, SInt32>;
// thunk 0x1424a1f20: Instances::fl_text::TextField::restrictGet
template struct ThunkFunc0<Instances::fl_text::TextField, 38, ASString>;
// thunk 0x1424a1f90: Instances::fl_text::TextField::restrictSet
template struct ThunkFunc1<Instances::fl_text::TextField, 39, const Value, const ASString&>;
// thunk 0x1424a2090: Instances::fl_text::TextField::scrollHGet
template struct ThunkFunc0<Instances::fl_text::TextField, 40, SInt32>;
// thunk 0x1424a20f0: Instances::fl_text::TextField::scrollHSet
template struct ThunkFunc1<Instances::fl_text::TextField, 41, const Value, SInt32>;
// thunk 0x1424a2160: Instances::fl_text::TextField::scrollVGet
template struct ThunkFunc0<Instances::fl_text::TextField, 42, SInt32>;
// thunk 0x1424a2310: Instances::fl_text::TextField::scrollVSet
template struct ThunkFunc1<Instances::fl_text::TextField, 43, const Value, SInt32>;
// thunk 0x1424a2380: Instances::fl_text::TextField::selectableGet
template struct ThunkFunc0<Instances::fl_text::TextField, 44, bool>;
// thunk 0x1424a23e0: Instances::fl_text::TextField::selectableSet
template struct ThunkFunc1<Instances::fl_text::TextField, 45, const Value, bool>;
// thunk 0x1424a2440: Instances::fl_text::TextField::selectionBeginIndexGet
template struct ThunkFunc0<Instances::fl_text::TextField, 46, SInt32>;
// thunk 0x1424a2600: Instances::fl_text::TextField::selectionEndIndexGet
template struct ThunkFunc0<Instances::fl_text::TextField, 47, SInt32>;
// thunk 0x1424a2660: Instances::fl_text::TextField::sharpnessGet
template struct ThunkFunc0<Instances::fl_text::TextField, 48, Value::Number>;
// thunk 0x1424a26d0: Instances::fl_text::TextField::sharpnessSet
template struct ThunkFunc1<Instances::fl_text::TextField, 49, const Value, Value::Number>;
// thunk 0x1424a2760: Instances::fl_text::TextField::styleSheetGet
template struct ThunkFunc0<Instances::fl_text::TextField, 50, SPtr<Instances::fl_text::StyleSheet>>;
// thunk 0x1424a2810: Instances::fl_text::TextField::styleSheetSet
template struct ThunkFunc1<Instances::fl_text::TextField, 51, const Value, Instances::fl_text::StyleSheet*>;
// thunk 0x1424a2850: Instances::fl_text::TextField::textGet
template struct ThunkFunc0<Instances::fl_text::TextField, 52, ASString>;
// thunk 0x1424a28c0: Instances::fl_text::TextField::textSet
template struct ThunkFunc1<Instances::fl_text::TextField, 53, const Value, const ASString&>;
// thunk 0x1424a29c0: Instances::fl_text::TextField::textColorGet
template struct ThunkFunc0<Instances::fl_text::TextField, 54, UInt32>;
// thunk 0x1424a2a20: Instances::fl_text::TextField::textColorSet
template struct ThunkFunc1<Instances::fl_text::TextField, 55, const Value, UInt32>;
// thunk 0x1424a2a90: Instances::fl_text::TextField::textHeightGet
template struct ThunkFunc0<Instances::fl_text::TextField, 56, Value::Number>;
// thunk 0x1424a2b00: Instances::fl_text::TextField::textWidthGet
template struct ThunkFunc0<Instances::fl_text::TextField, 57, Value::Number>;
// thunk 0x1424a2b70: Instances::fl_text::TextField::thicknessGet
template struct ThunkFunc0<Instances::fl_text::TextField, 58, Value::Number>;
// thunk 0x1424a2d20: Instances::fl_text::TextField::thicknessSet
template struct ThunkFunc1<Instances::fl_text::TextField, 59, const Value, Value::Number>;
// thunk 0x1424a2db0: Instances::fl_text::TextField::typeGet
template struct ThunkFunc0<Instances::fl_text::TextField, 60, ASString>;
// thunk 0x1424a2e20: Instances::fl_text::TextField::typeSet
template struct ThunkFunc1<Instances::fl_text::TextField, 61, const Value, const ASString&>;
// thunk 0x1424a2f20: Instances::fl_text::TextField::useRichTextClipboardGet
template struct ThunkFunc0<Instances::fl_text::TextField, 62, bool>;
// thunk 0x1424a2f80: Instances::fl_text::TextField::useRichTextClipboardSet
template struct ThunkFunc1<Instances::fl_text::TextField, 63, const Value, bool>;
// thunk 0x1424a2fe0: Instances::fl_text::TextField::wordWrapGet
template struct ThunkFunc0<Instances::fl_text::TextField, 64, bool>;
// thunk 0x1424a3040: Instances::fl_text::TextField::wordWrapSet
template struct ThunkFunc1<Instances::fl_text::TextField, 65, const Value, bool>;
// thunk 0x1424a30a0: Instances::fl_text::TextField::appendText
template struct ThunkFunc1<Instances::fl_text::TextField, 66, const Value, const ASString&>;
// thunk 0x1424a31a0: Instances::fl_text::TextField::getCharBoundaries
template struct ThunkFunc1<Instances::fl_text::TextField, 67, SPtr<Instances::fl_geom::Rectangle>, SInt32>;
// thunk 0x1424a32a0: Instances::fl_text::TextField::getCharIndexAtPoint
template struct ThunkFunc2<Instances::fl_text::TextField, 68, SInt32, Value::Number, Value::Number>;
// thunk 0x1424a33d0: Instances::fl_text::TextField::getFirstCharInParagraph
template struct ThunkFunc1<Instances::fl_text::TextField, 69, SInt32, SInt32>;
// thunk 0x1424a3480: Instances::fl_text::TextField::getImageReference
template struct ThunkFunc1<Instances::fl_text::TextField, 70, SPtr<Instances::fl_display::DisplayObject>, const ASString&>;
// thunk 0x1424a3600: Instances::fl_text::TextField::getLineIndexAtPoint
template struct ThunkFunc2<Instances::fl_text::TextField, 71, SInt32, Value::Number, Value::Number>;
// thunk 0x1424a3730: Instances::fl_text::TextField::getLineIndexOfChar
template struct ThunkFunc1<Instances::fl_text::TextField, 72, SInt32, SInt32>;
// thunk 0x1424a37e0: Instances::fl_text::TextField::getLineLength
template struct ThunkFunc1<Instances::fl_text::TextField, 73, SInt32, SInt32>;
// thunk 0x1424a3890: Instances::fl_text::TextField::getLineMetrics
template struct ThunkFunc1<Instances::fl_text::TextField, 74, SPtr<Instances::fl_text::TextLineMetrics>, SInt32>;
// thunk 0x1424a3990: Instances::fl_text::TextField::getLineOffset
template struct ThunkFunc1<Instances::fl_text::TextField, 75, SInt32, SInt32>;
// thunk 0x1424a3a40: Instances::fl_text::TextField::getLineText
template struct ThunkFunc1<Instances::fl_text::TextField, 76, ASString, SInt32>;
// thunk 0x1424a3af0: Instances::fl_text::TextField::getParagraphLength
template struct ThunkFunc1<Instances::fl_text::TextField, 77, SInt32, SInt32>;
// Instances::fl_text::TextField::getTextFormat argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_text::TextField, 78, 0, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return -1; }
};
// Instances::fl_text::TextField::getTextFormat argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_text::TextField, 78, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return -1; }
};
// thunk 0x1424a3ba0: Instances::fl_text::TextField::getTextFormat
template struct ThunkFunc2<Instances::fl_text::TextField, 78, SPtr<Instances::fl_text::TextFormat>, SInt32, SInt32>;
// thunk 0x1424a3cf0: Instances::fl_text::TextField::replaceSelectedText
template struct ThunkFunc1<Instances::fl_text::TextField, 79, const Value, const ASString&>;
// thunk 0x1424a3df0: Instances::fl_text::TextField::replaceText
// MS2-FUNCTIONAL: lifetime only: the exe releases one default string temporary fewer before the call (4 bytes shorter here)
template struct ThunkFunc3<Instances::fl_text::TextField, 80, const Value, SInt32, SInt32, const ASString&>;
// thunk 0x1424a3f70: Instances::fl_text::TextField::setSelection
template struct ThunkFunc2<Instances::fl_text::TextField, 81, const Value, SInt32, SInt32>;
// Instances::fl_text::TextField::setTextFormat argument 1 default
template <> struct ThunkMethodDefault<Instances::fl_text::TextField, 82, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return -1; }
};
// Instances::fl_text::TextField::setTextFormat argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_text::TextField, 82, 2, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return -1; }
};
// thunk 0x1424a4020: Instances::fl_text::TextField::setTextFormat
template struct ThunkFunc3<Instances::fl_text::TextField, 82, const Value, Instances::fl_text::TextFormat*, SInt32, SInt32>;
// thunk 0x1424a43e0: Instances::fl_text::TextFormat::alignGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 0, ASString>;
// thunk 0x1424a4450: Instances::fl_text::TextFormat::alignSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 1, const Value, const ASString&>;
// thunk 0x1424a4550: Instances::fl_text::TextFormat::blockIndentGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 2, Value>;
// thunk 0x1424a4570: Instances::fl_text::TextFormat::blockIndentSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 3, const Value, const Value&>;
// thunk 0x1424a46c0: Instances::fl_text::TextFormat::boldGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 4, Value>;
// thunk 0x1424a46e0: Instances::fl_text::TextFormat::boldSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 5, const Value, const Value&>;
// thunk 0x1424a4830: Instances::fl_text::TextFormat::bulletGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 6, Value>;
// thunk 0x1424a4850: Instances::fl_text::TextFormat::bulletSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 7, const Value, const Value&>;
// thunk 0x1424a49a0: Instances::fl_text::TextFormat::colorGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 8, Value>;
// thunk 0x1424a49c0: Instances::fl_text::TextFormat::colorSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 9, const Value, const Value&>;
// thunk 0x1424a4b10: Instances::fl_text::TextFormat::fontGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 10, ASString>;
// thunk 0x1424a4b80: Instances::fl_text::TextFormat::fontSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 11, const Value, const ASString&>;
// thunk 0x1424a4c80: Instances::fl_text::TextFormat::indentGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 12, Value>;
// thunk 0x1424a4ca0: Instances::fl_text::TextFormat::indentSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 13, const Value, const Value&>;
// thunk 0x1424a4df0: Instances::fl_text::TextFormat::italicGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 14, Value>;
// thunk 0x1424a4e10: Instances::fl_text::TextFormat::italicSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 15, const Value, const Value&>;
// thunk 0x1424a4f60: Instances::fl_text::TextFormat::kerningGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 16, Value>;
// thunk 0x1424a4f80: Instances::fl_text::TextFormat::kerningSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 17, const Value, const Value&>;
// thunk 0x1424a50d0: Instances::fl_text::TextFormat::leadingGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 18, Value>;
// thunk 0x1424a50f0: Instances::fl_text::TextFormat::leadingSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 19, const Value, const Value&>;
// thunk 0x1424a5240: Instances::fl_text::TextFormat::leftMarginGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 20, Value>;
// thunk 0x1424a5260: Instances::fl_text::TextFormat::leftMarginSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 21, const Value, const Value&>;
// thunk 0x1424a53b0: Instances::fl_text::TextFormat::letterSpacingGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 22, Value>;
// thunk 0x1424a53d0: Instances::fl_text::TextFormat::letterSpacingSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 23, const Value, const Value&>;
// thunk 0x1424a5520: Instances::fl_text::TextFormat::rightMarginGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 24, Value>;
// thunk 0x1424a5540: Instances::fl_text::TextFormat::rightMarginSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 25, const Value, const Value&>;
// thunk 0x1424a5690: Instances::fl_text::TextFormat::sizeGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 26, Value>;
// thunk 0x1424a56b0: Instances::fl_text::TextFormat::sizeSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 27, const Value, const Value&>;
// thunk 0x1424a5800: Instances::fl_text::TextFormat::tabStopsGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 28, SPtr<Instances::fl::Array>>;
// thunk 0x1424a58b0: Instances::fl_text::TextFormat::tabStopsSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 29, const Value, Instances::fl::Array*>;
// thunk 0x1424a58f0: Instances::fl_text::TextFormat::targetGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 30, ASString>;
// thunk 0x1424a5960: Instances::fl_text::TextFormat::targetSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 31, const Value, const ASString&>;
// thunk 0x1424a5a60: Instances::fl_text::TextFormat::underlineGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 32, Value>;
// thunk 0x1424a5a80: Instances::fl_text::TextFormat::underlineSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 33, const Value, const Value&>;
// thunk 0x1424a5bd0: Instances::fl_text::TextFormat::urlGet
template struct ThunkFunc0<Instances::fl_text::TextFormat, 34, ASString>;
// thunk 0x1424a5c40: Instances::fl_text::TextFormat::urlSet
template struct ThunkFunc1<Instances::fl_text::TextFormat, 35, const Value, const ASString&>;
// thunk 0x1424a5e80: Instances::fl_text::StaticText::textGet
template struct ThunkFunc0<Instances::fl_text::StaticText, 0, ASString>;
// thunk 0x1424a6430: Instances::fl_text::TextSnapshot::charCountGet
template struct ThunkFunc0<Instances::fl_text::TextSnapshot, 0, SInt32>;
// thunk 0x1424a6490: Instances::fl_text::TextSnapshot::findText
// MS2-FUNCTIONAL: lifetime only: the exe releases one default string temporary fewer before the call
template struct ThunkFunc3<Instances::fl_text::TextSnapshot, 1, SInt32, SInt32, const ASString&, bool>;
// thunk 0x1424a6650: Instances::fl_text::TextSnapshot::getSelected
template struct ThunkFunc2<Instances::fl_text::TextSnapshot, 2, bool, SInt32, SInt32>;
// thunk 0x1424a6750: Instances::fl_text::TextSnapshot::getSelectedText
template struct ThunkFunc1<Instances::fl_text::TextSnapshot, 3, ASString, bool>;
// thunk 0x1424a6800: Instances::fl_text::TextSnapshot::getText
template struct ThunkFunc3<Instances::fl_text::TextSnapshot, 4, ASString, SInt32, SInt32, bool>;
// thunk 0x1424a6930: Instances::fl_text::TextSnapshot::getTextRunInfo
template struct ThunkFunc2<Instances::fl_text::TextSnapshot, 5, SPtr<Instances::fl::Array>, SInt32, SInt32>;
// Instances::fl_text::TextSnapshot::hitTestTextNearPos argument 2 default
template <> struct ThunkMethodDefault<Instances::fl_text::TextSnapshot, 6, 2, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// thunk 0x1424a6a80: Instances::fl_text::TextSnapshot::hitTestTextNearPos
template struct ThunkFunc3<Instances::fl_text::TextSnapshot, 6, Value::Number, Value::Number, Value::Number, Value::Number>;
// Instances::fl_text::TextSnapshot::setSelectColor argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_text::TextSnapshot, 7, 0, UInt32>
{
    SF_INLINE static UInt32 Get(StringManager&) { return 0xffff00; }
};
// thunk 0x1424a6bf0: Instances::fl_text::TextSnapshot::setSelectColor
template struct ThunkFunc1<Instances::fl_text::TextSnapshot, 7, const Value, UInt32>;
// thunk 0x1424a6c70: Instances::fl_text::TextSnapshot::setSelected
template struct ThunkFunc3<Instances::fl_text::TextSnapshot, 8, const Value, SInt32, SInt32, bool>;
// thunk 0x1424a6d60: Instances::fl_text::Font::fontNameGet
template struct ThunkFunc0<Instances::fl_text::Font, 0, Value>;
// thunk 0x1424a6d80: Instances::fl_text::Font::fontStyleGet
template struct ThunkFunc0<Instances::fl_text::Font, 1, Value>;
// thunk 0x1424a6da0: Instances::fl_text::Font::fontTypeGet
template struct ThunkFunc0<Instances::fl_text::Font, 2, Value>;
// thunk 0x1424a6dc0: Instances::fl_text::Font::hasGlyphs
template struct ThunkFunc1<Instances::fl_text::Font, 3, bool, const ASString&>;
// thunk 0x1424a7180: Classes::fl_text::Font::enumerateFonts
template struct ThunkFunc1<Classes::fl_text::Font, 0, SPtr<Instances::fl::Array>, bool>;
// thunk 0x1424a7270: Classes::fl_text::Font::registerFont
template struct ThunkFunc1<Classes::fl_text::Font, 1, const Value, Class*>;
// thunk 0x1424a7420: Instances::fl_text::TextField::alwaysShowSelectionGet
template struct ThunkFunc0<Instances::fl_text::TextField, 0, bool>;
// thunk 0x1424a7480: Instances::fl_text::TextField::alwaysShowSelectionSet
template struct ThunkFunc1<Instances::fl_text::TextField, 1, const Value, bool>;
// thunk 0x1424a7630: Instances::fl_text::TextField::antiAliasTypeGet
template struct ThunkFunc0<Instances::fl_text::TextField, 2, ASString>;
// thunk 0x1424a76a0: Instances::fl_text::TextField::antiAliasTypeSet
template struct ThunkFunc1<Instances::fl_text::TextField, 3, const Value, const ASString&>;
// thunk 0x1424a78e0: Instances::fl_text::TextField::autoSizeGet
template struct ThunkFunc0<Instances::fl_text::TextField, 4, ASString>;
// thunk 0x1424a7950: Instances::fl_text::TextField::autoSizeSet
template struct ThunkFunc1<Instances::fl_text::TextField, 5, const Value, const ASString&>;
// thunk 0x1424a7a50: Instances::fl_text::TextField::backgroundGet
template struct ThunkFunc0<Instances::fl_text::TextField, 6, bool>;
// thunk 0x1424a7c10: Instances::fl_text::TextField::backgroundSet
template struct ThunkFunc1<Instances::fl_text::TextField, 7, const Value, bool>;
// thunk 0x1424a7c70: Instances::fl_text::TextField::backgroundColorGet
template struct ThunkFunc0<Instances::fl_text::TextField, 8, UInt32>;
// thunk 0x1424a7cd0: Instances::fl_text::TextField::backgroundColorSet
template struct ThunkFunc1<Instances::fl_text::TextField, 9, const Value, UInt32>;
// thunk 0x1424a7d40: Instances::fl_text::TextField::borderGet
template struct ThunkFunc0<Instances::fl_text::TextField, 10, bool>;
// thunk 0x1424a7da0: Instances::fl_text::TextField::borderSet
template struct ThunkFunc1<Instances::fl_text::TextField, 11, const Value, bool>;
// thunk 0x1424a7e00: Instances::fl_text::TextField::borderColorGet
template struct ThunkFunc0<Instances::fl_text::TextField, 12, UInt32>;
// thunk 0x1424a7e60: Instances::fl_text::TextField::borderColorSet
template struct ThunkFunc1<Instances::fl_text::TextField, 13, const Value, UInt32>;
// thunk 0x1424a7ed0: Instances::fl_text::TextField::bottomScrollVGet
template struct ThunkFunc0<Instances::fl_text::TextField, 14, SInt32>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END


const Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142525270(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Multiname& mn);  // VM::Resolve2ClassTraits

// ==== flash.system: natives of the class objects ====================================================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes { namespace fl_system
{
    // The IME of the movie: the host installs it as the movie's IMEManager state; NULL without IME support.

    // @0x1424a00b0
    void IME::conversionModeGet(ASString& result)
    {
        Ptr<IMEManagerBase> pime = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetIMEManager();
        result = "UNKNOWN";
        if (pime)
            result = pime->GetConversionMode();
    }

    // @0x1424a0120
    void IME::conversionModeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        Ptr<IMEManagerBase> pime = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetIMEManager();
        if (pime)
        {
            const char* mode = value.ToCStr();
            UInt32 convMode = !strcmp(mode, "ALPHANUMERIC_HALF");
            if (!strcmp(mode, "JAPANESE_HIRAGANA"))
                convMode = 4;
            if (!strcmp(mode, "JAPANESE_KATAKANA_FULL"))
                convMode = 8;
            if (!strcmp(mode, "JAPANESE_KATAKANA_HALF"))
                convMode = 0x16;
            pime->SetConversionMode(convMode);
        }
    }

    // @0x1424a0230
    void IME::enabledGet(bool& result)
    {
        Ptr<IMEManagerBase> pime = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetIMEManager();
        if (pime)
            result = pime->GetEnabled();
    }

    // @0x1424a0290
    void IME::enabledSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        Ptr<IMEManagerBase> pime = static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetIMEManager();
        if (pime)
            pime->SetEnabled(value);
    }

}}

// The global escapeMultiByte(): the AS3 escaping, or the AS2 byte escaping under System.useCodePage.
// MS2-FUNCTIONAL: Traits::GetConstructor is inlined here (an out-of-line call in the exe); register allocation differs
// @0x1424a02f0
void escapeMultiByteInternal(VM& vm, ASString& result, const ASString& value)
{
    bool useCodePage = false;
    // flash.system.System's class object, looked up as "flash.utils.System" like the exe does
    Multiname mn(vm, StringDataPtr("flash.utils.System"));
    const ClassTraits::Traits* ctr = FUN_142525270(vm, mn);
    if (ctr && ctr->ITraits)
        useCodePage = static_cast<Classes::fl_system::System&>(ctr->GetConstructor()).useCodePage;
    String str;
    if (!useCodePage)
        ASUtils::AS3::Escape(value.ToCStr(), value.GetSize(), str);
    else
        ASUtils::Escape(value.ToCStr(), value.GetSize(), &str);
    result = vm.GetStringManager().CreateString(str);
}

namespace Classes { namespace fl_system
{
    // @0x1424a0570
    void Capabilities::hasIMEGet(bool& result)
    {
        if (static_cast<ASVM&>(GetVM()).GetMovieImpl()->GetIMEManager())
            result = true;
        else
            result = false;
    }

    // @0x1424a0730
    void Capabilities::manufacturerGet(ASString& result)
    {
        result = "Scaleform ";
        ASString os = GetVM().GetStringManager().CreateEmptyString();
        os = "Windows";     // osGet, inlined
        result.Append(os);
    }

    // @0x1424a0820
    void Capabilities::playerTypeGet(ASString& result)
    {
        result = GetVM().GetStringManager().CreateConstString("StandAlone");
    }

    // @0x1424a0990
    void System::totalMemoryGet(UInt32& result)
    {
        result = static_cast<UInt32>(Memory::pGlobalHeap->GetTotalFootprint());
    }
}}

// The global unescapeMultiByte(): result is left as it is when the AS3 decoding fails.
// MS2-FUNCTIONAL: Traits::GetConstructor is inlined here (an out-of-line call in the exe); register allocation differs
// @0x1424a09c0
void unescapeMultiByteInternal(VM& vm, ASString& result, const ASString& value)
{
    bool useCodePage = false;
    // flash.system.System's class object, looked up as "flash.utils.System" like the exe does
    Multiname mn(vm, StringDataPtr("flash.utils.System"));
    const ClassTraits::Traits* ctr = FUN_142525270(vm, mn);
    if (ctr && ctr->ITraits)
        useCodePage = static_cast<Classes::fl_system::System&>(ctr->GetConstructor()).useCodePage;
    String str;
    if (!useCodePage)
    {
        if (!ASUtils::AS3::Unescape(value.ToCStr(), value.GetSize(), str))
            return;
    }
    else
        ASUtils::Unescape(value.ToCStr(), value.GetSize(), &str);
    result = vm.GetStringManager().CreateString(str);
}

}}} // namespace Scaleform::GFx::AS3


// ==== flash.system: class traits, instance traits, classes and instances ===========================================

namespace Scaleform { namespace GFx { namespace AS3 {

// Native class descriptors (data of the exe, with the thunk and member tables).
namespace fl_system
{
    extern const ClassInfo ApplicationDomainCI;
    extern const ClassInfo CapabilitiesCI;
    extern const ClassInfo IMECI;
    extern const ClassInfo IMEConversionModeCI;
    extern const ClassInfo LoaderContextCI;
    extern const ClassInfo SecurityCI;
    extern const ClassInfo SecurityDomainCI;
    extern const ClassInfo SecurityPanelCI;
    extern const ClassInfo SystemCI;
}

namespace ClassTraits { namespace fl_system
{
    // @0x14249d0a0
    Pickable<Traits> Capabilities::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Capabilities(vm));
    }

    // @0x14249d480
    Pickable<Traits> IME::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IME(vm));
    }

    // @0x14249d910
    Pickable<Traits> IMEConversionMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IMEConversionMode(vm));
    }

    // @0x14249dab0
    Pickable<Traits> SecurityDomain::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SecurityDomain(vm));
    }

    // @0x14249dc00
    Pickable<Traits> LoaderContext::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) LoaderContext(vm));
    }

    // @0x14249dd40
    Pickable<Traits> Security::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Security(vm));
    }

    // @0x14249df60
    Pickable<Traits> SecurityPanel::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SecurityPanel(vm));
    }

    // @0x14249e0f0
    Pickable<Traits> System::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) System(vm));
    }

    // @0x14249e480
    Pickable<Traits> ApplicationDomain::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ApplicationDomain(vm));
    }

}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249e5c0
    ApplicationDomain::ApplicationDomain(VM& vm)
        : Traits(vm, AS3::fl_system::ApplicationDomainCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_system::ApplicationDomain(
            vm, AS3::fl_system::ApplicationDomainCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_system
{
    // @0x14249e6c0
    ApplicationDomain::ApplicationDomain(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_system
{
    // @0x14249e6f0
    ApplicationDomain::ApplicationDomain(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
    {
    }
}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249e720
    Capabilities::Capabilities(VM& vm)
        : Traits(vm, AS3::fl_system::CapabilitiesCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_system::CapabilitiesCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_system::Capabilities(*this)));
    }
}}

namespace Classes { namespace fl_system
{
    // @0x14249e800
    Capabilities::Capabilities(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249e830
    IME::IME(VM& vm)
        : Traits(vm, AS3::fl_system::IMECI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_events::EventDispatcher(vm, AS3::fl_system::IMECI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_system::IME(*this)));
    }
}}

namespace Classes { namespace fl_system
{
    // @0x14249e910
    IME::IME(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249e940
    IMEConversionMode::IMEConversionMode(VM& vm)
        : Traits(vm, AS3::fl_system::IMEConversionModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_system::IMEConversionModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_system::IMEConversionMode(*this)));
    }
}}

namespace Classes { namespace fl_system
{
    // @0x14249ea80
    IMEConversionMode::IMEConversionMode(ClassTraits::Traits& t)
        : Class(t),
          ALPHANUMERIC_FULL("ALPHANUMERIC_FULL"), ALPHANUMERIC_HALF("ALPHANUMERIC_HALF"), CHINESE("CHINESE"),
          JAPANESE_HIRAGANA("JAPANESE_HIRAGANA"), JAPANESE_KATAKANA_FULL("JAPANESE_KATAKANA_FULL"),
          JAPANESE_KATAKANA_HALF("JAPANESE_KATAKANA_HALF"), KOREAN("KOREAN"), UNKNOWN("UNKNOWN")
    {
    }
}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249eb00
    LoaderContext::LoaderContext(VM& vm)
        : Traits(vm, AS3::fl_system::LoaderContextCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_system::LoaderContext(
            vm, AS3::fl_system::LoaderContextCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_system
{
    // @0x14249ec00
    LoaderContext::LoaderContext(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_system
{
    // @0x14249ec30
    LoaderContext::LoaderContext(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , allowLoadBytesCodeExecution(false), checkPolicyFile(false)
    {
    }
}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249ec70
    Security::Security(VM& vm)
        : Traits(vm, AS3::fl_system::SecurityCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_system::SecurityCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_system::Security(*this)));
    }
}}

namespace Classes { namespace fl_system
{
    // @0x14249ed90
    Security::Security(ClassTraits::Traits& t)
        : Class(t),
          APPLICATION("application"), LOCAL_TRUSTED("localTrusted"), LOCAL_WITH_FILE("localWithFile"),
          LOCAL_WITH_NETWORK("localWithNetwork"), REMOTE("remote")
    {
    }
}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249edf0
    SecurityDomain::SecurityDomain(VM& vm)
        : Traits(vm, AS3::fl_system::SecurityDomainCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_system::SecurityDomain(
            vm, AS3::fl_system::SecurityDomainCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_system::SecurityDomain(*this)));
    }
}}

namespace InstanceTraits { namespace fl_system
{
    // @0x14249ef20
    SecurityDomain::SecurityDomain(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_system
{
    // @0x14249ef50
    SecurityDomain::SecurityDomain(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
    {
    }
}}

namespace Classes { namespace fl_system
{
    // @0x14249eef0
    SecurityDomain::SecurityDomain(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249ef80
    SecurityPanel::SecurityPanel(VM& vm)
        : Traits(vm, AS3::fl_system::SecurityPanelCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_system::SecurityPanelCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_system::SecurityPanel(*this)));
    }
}}

namespace Classes { namespace fl_system
{
    // @0x14249f0b0
    SecurityPanel::SecurityPanel(ClassTraits::Traits& t)
        : Class(t),
          CAMERA("camera"), DEFAULT("default"), DISPLAY("display"), LOCAL_STORAGE("localStorage"),
          MICROPHONE("microphone"), PRIVACY("privacy"), SETTINGS_MANAGER("settingsManager")
    {
    }
}}

namespace ClassTraits { namespace fl_system
{
    // @0x14249f130
    System::System(VM& vm)
        : Traits(vm, AS3::fl_system::SystemCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_system::SystemCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_system::System(*this)));
    }
}}

namespace Classes { namespace fl_system
{
    // @0x14249f220
    System::System(ClassTraits::Traits& t)
        : Class(t), useCodePage(false)
    {
    }
}}

namespace InstanceTraits { namespace fl_system
{
    // @0x14249fe00
    Pickable<ApplicationDomain::InstanceType> ApplicationDomain::MakeInstance(ApplicationDomain& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x14249fe70
    Pickable<LoaderContext::InstanceType> LoaderContext::MakeInstance(LoaderContext& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // @0x14249fef0
    Pickable<SecurityDomain::InstanceType> SecurityDomain::MakeInstance(SecurityDomain& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

}}

}}} // namespace Scaleform::GFx::AS3


// ==== flash.text: constant classes =================================================================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_text
{
    extern const ClassInfo AntiAliasTypeCI;
    extern const ClassInfo FontStyleCI;
    extern const ClassInfo FontTypeCI;
    extern const ClassInfo GridFitTypeCI;
    extern const ClassInfo TextColorTypeCI;
    extern const ClassInfo TextDisplayModeCI;
    extern const ClassInfo TextFieldAutoSizeCI;
    extern const ClassInfo TextFieldTypeCI;
    extern const ClassInfo TextFormatAlignCI;
    extern const ClassInfo TextRendererCI;
}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a21c0
    Pickable<Traits> TextColorType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextColorType(vm));
    }

    // @0x1424a24a0
    Pickable<Traits> TextDisplayMode::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextDisplayMode(vm));
    }

    // @0x1424a4120
    Pickable<Traits> TextFieldAutoSize::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextFieldAutoSize(vm));
    }

    // @0x1424a4290
    Pickable<Traits> TextFieldType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextFieldType(vm));
    }

    // @0x1424a5ef0
    Pickable<Traits> TextFormatAlign::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextFormatAlign(vm));
    }

    // @0x1424a6060
    Pickable<Traits> TextRenderer::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextRenderer(vm));
    }

    // @0x1424a61a0
    Pickable<Traits> AntiAliasType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) AntiAliasType(vm));
    }

    // @0x1424a72b0
    Pickable<Traits> FontStyle::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FontStyle(vm));
    }

    // @0x1424a74e0
    Pickable<Traits> FontType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FontType(vm));
    }

    // @0x1424a7ab0
    Pickable<Traits> GridFitType::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GridFitType(vm));
    }

}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a8360
    AntiAliasType::AntiAliasType(VM& vm)
        : Traits(vm, AS3::fl_text::AntiAliasTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::AntiAliasTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::AntiAliasType(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a8460
    AntiAliasType::AntiAliasType(ClassTraits::Traits& t)
        : Class(t),
          ADVANCED("advanced"), NORMAL("normal")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a87f0
    FontStyle::FontStyle(VM& vm)
        : Traits(vm, AS3::fl_text::FontStyleCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::FontStyleCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::FontStyle(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a8900
    FontStyle::FontStyle(ClassTraits::Traits& t)
        : Class(t),
          BOLD("bold"), BOLD_ITALIC("boldItalic"), ITALIC("italic"), REGULAR("regular")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a8950
    FontType::FontType(VM& vm)
        : Traits(vm, AS3::fl_text::FontTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::FontTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::FontType(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a8a50
    FontType::FontType(ClassTraits::Traits& t)
        : Class(t),
          DEVICE("device"), EMBEDDED("embedded")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a8a90
    GridFitType::GridFitType(VM& vm)
        : Traits(vm, AS3::fl_text::GridFitTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::GridFitTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::GridFitType(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a8b90
    GridFitType::GridFitType(ClassTraits::Traits& t)
        : Class(t),
          NONE("none"), PIXEL("pixel"), SUBPIXEL("subpixel")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a8ed0
    TextColorType::TextColorType(VM& vm)
        : Traits(vm, AS3::fl_text::TextColorTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::TextColorTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::TextColorType(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a8fd0
    TextColorType::TextColorType(ClassTraits::Traits& t)
        : Class(t),
          DARK_COLOR("dark"), LIGHT_COLOR("light")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a9010
    TextDisplayMode::TextDisplayMode(VM& vm)
        : Traits(vm, AS3::fl_text::TextDisplayModeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::TextDisplayModeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::TextDisplayMode(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a9110
    TextDisplayMode::TextDisplayMode(ClassTraits::Traits& t)
        : Class(t),
          CRT("crt"), DEFAULT("default"), LCD("lcd")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a92c0
    TextFieldAutoSize::TextFieldAutoSize(VM& vm)
        : Traits(vm, AS3::fl_text::TextFieldAutoSizeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::TextFieldAutoSizeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::TextFieldAutoSize(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a93d0
    TextFieldAutoSize::TextFieldAutoSize(ClassTraits::Traits& t)
        : Class(t),
          CENTER("center"), LEFT("left"), NONE("none"), RIGHT("right")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a9420
    TextFieldType::TextFieldType(VM& vm)
        : Traits(vm, AS3::fl_text::TextFieldTypeCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::TextFieldTypeCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::TextFieldType(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a9520
    TextFieldType::TextFieldType(ClassTraits::Traits& t)
        : Class(t),
          DYNAMIC("dynamic"), INPUT("input")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a9990
    TextFormatAlign::TextFormatAlign(VM& vm)
        : Traits(vm, AS3::fl_text::TextFormatAlignCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::TextFormatAlignCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::TextFormatAlign(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a9aa0
    TextFormatAlign::TextFormatAlign(ClassTraits::Traits& t)
        : Class(t),
          CENTER("center"), JUSTIFY("justify"), LEFT("left"), RIGHT("right")
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a9c60
    TextRenderer::TextRenderer(VM& vm)
        : Traits(vm, AS3::fl_text::TextRendererCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Object(vm, AS3::fl_text::TextRendererCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::TextRenderer(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a9d40
    TextRenderer::TextRenderer(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ==== flash.text: CSMSettings, Font, TextLineMetrics =================================================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_text
{
    extern const ClassInfo CSMSettingsCI;
    extern const ClassInfo FontCI;
    extern const ClassInfo TextLineMetricsCI;
}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a0b60
    Pickable<Traits> Font::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) Font(vm));
    }

    // @0x1424a2be0
    Pickable<Traits> CSMSettings::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) CSMSettings(vm));
    }

    // @0x1424a7040
    Pickable<Traits> TextLineMetrics::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextLineMetrics(vm));
    }

    // @0x1424a84a0
    CSMSettings::CSMSettings(VM& vm)
        : Traits(vm, AS3::fl_text::CSMSettingsCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_text::CSMSettings(vm, AS3::fl_text::CSMSettingsCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_text
{
    // @0x1424a85a0
    CSMSettings::CSMSettings(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_text
{
    // @0x1424a85d0
    CSMSettings::CSMSettings(InstanceTraits::Traits& t)
        : Instances::fl::Object(t), fontSize(0), insideCutoff(0), outsideCutoff(0)
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a8600
    Font::Font(VM& vm)
        : Traits(vm, AS3::fl_text::FontCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_text::Font(vm, AS3::fl_text::FontCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Classes::fl_text::Font(*this)));
    }
}}

namespace Classes { namespace fl_text
{
    // @0x1424a8700
    Font::Font(ClassTraits::Traits& t)
        : Class(t)
    {
    }
}}

namespace InstanceTraits { namespace fl_text
{
    // @0x1424a8730
    Font::Font(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_text
{
    // @0x1424a8760
    Font::Font(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
        , fontName(t.GetVM().GetStringManager().CreateEmptyString())
        , fontStyle(t.GetVM().GetStringManager().CreateEmptyString())
        , fontType(t.GetVM().GetStringManager().CreateEmptyString())
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a9af0
    TextLineMetrics::TextLineMetrics(VM& vm)
        : Traits(vm, AS3::fl_text::TextLineMetricsCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_text::TextLineMetrics(
            vm, AS3::fl_text::TextLineMetricsCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_text
{
    // @0x1424a9bf0
    TextLineMetrics::TextLineMetrics(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_text
{
    // @0x1424a9c20
    TextLineMetrics::TextLineMetrics(InstanceTraits::Traits& t)
        : Instances::fl::Object(t), ascent(0), descent(0), height(0), leading(0), width(0), x(0)
    {
    }
}}

}}} // namespace Scaleform::GFx::AS3


// ==== flash.text: StaticText, StyleSheet, TextField, TextFormat, TextSnapshot traits =========================================

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl_text
{
    extern const ClassInfo StaticTextCI;
    extern const ClassInfo StyleSheetCI;
    extern const ClassInfo TextFieldCI;
    extern const ClassInfo TextFormatCI;
    extern const ClassInfo TextSnapshotCI;
}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a0dd0
    Pickable<Traits> TextFormat::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextFormat(vm));
    }

    // @0x1424a5d40
    Pickable<Traits> StaticText::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StaticText(vm));
    }

    // @0x1424a62f0
    Pickable<Traits> TextSnapshot::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextSnapshot(vm));
    }

    // @0x1424a6f00
    Pickable<Traits> TextField::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextField(vm));
    }

    // @0x1424a77a0
    Pickable<Traits> StyleSheet::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StyleSheet(vm));
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a8bf0
    StaticText::StaticText(VM& vm)
        : Traits(vm, AS3::fl_text::StaticTextCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_text::StaticText(vm, AS3::fl_text::StaticTextCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_text
{
    // The instance layout is not recovered yet, so the size is the exe's constant.
    // @0x1424a8cf0
    StaticText::StaticText(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(0x68);
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a8d50
    StyleSheet::StyleSheet(VM& vm)
        : Traits(vm, AS3::fl_text::StyleSheetCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_text::StyleSheet(vm, AS3::fl_text::StyleSheetCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_text
{
    // @0x1424a8e50
    StyleSheet::StyleSheet(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_text
{
    // @0x1424a8e80
    StyleSheet::StyleSheet(InstanceTraits::Traits& t)
        : Instances::fl_events::EventDispatcher(t)
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a9160
    TextField::TextField(VM& vm)
        : Traits(vm, AS3::fl_text::TextFieldCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_text::TextField(vm, AS3::fl_text::TextFieldCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_text
{
    // @0x1424a9260
    TextField::TextField(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_text
{
    // @0x1424a9290
    TextField::TextField(InstanceTraits::Traits& t)
        : Instances::fl_display::InteractiveObject(t)
    {
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a9560
    TextFormat::TextFormat(VM& vm)
        : Traits(vm, AS3::fl_text::TextFormatCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_text::TextFormat(vm, AS3::fl_text::TextFormatCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_text
{
    // @0x1424a9660
    TextFormat::TextFormat(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_text
{
    // Every property starts out null.
    // @0x1424a9690
    TextFormat::TextFormat(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
    {
        const ASString nullStr = GetVM().GetStringManager().CreateNullString();
        Value r, n;
        n.SetNull();

        align = nullStr;
        blockIndent = n;
        bold = n;
        bullet = n;
        color = n;
        font = nullStr;
        indent = n;
        italic = n;
        kerning = n;
        leading = n;
        leftMargin = n;
        letterSpacing = n;
        rightMargin = n;
        size = n;
        tabStops = NULL;
        target = nullStr;
        underline = n;
        url = nullStr;
    }
}}

namespace ClassTraits { namespace fl_text
{
    // @0x1424a9d70
    TextSnapshot::TextSnapshot(VM& vm)
        : Traits(vm, AS3::fl_text::TextSnapshotCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl_text::TextSnapshot(vm, AS3::fl_text::TextSnapshotCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }
}}

namespace InstanceTraits { namespace fl_text
{
    // @0x1424a9e70
    TextSnapshot::TextSnapshot(VM& vm, const ClassInfo& ci)
        : CTraits(vm, ci)
    {
        SetMemSize(sizeof(InstanceType));
    }
}}

namespace Instances { namespace fl_text
{
    // @0x1424a9ea0
    TextSnapshot::TextSnapshot(InstanceTraits::Traits& t)
        : Instances::fl::Object(t)
    {
    }
}}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx {

// @0x1424aa050
StaticTextSnapshotData::~StaticTextSnapshotData()
{
}

}} // namespace Scaleform::GFx


// ==== flash.net: instance helpers, constructors and object factories ===============================================

// VM::GetValueTraits: the traits of a value (0x14250ffc0).
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);

namespace Scaleform { namespace GFx { namespace AS3 {

// ---- collector visits ---------------------------------------------------------------------------------------------

// The exe passes the owner as a third argument to every GcOp (r8); the shared GcOp typedef has two.
typedef void (*GcOpWithOwner)(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const ASRefCountBaseType** pchild,
                              const ASRefCountBaseType& owner);

// Visits a counted pointer member.
template <class T>
SF_INLINE void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, const SPtr<T>& p,
                               ASRefCountBaseType::GcOp op, const ASRefCountBaseType& owner)
{
    if (p.GetPtr())
        reinterpret_cast<GcOpWithOwner>(op)(prcc,
            const_cast<const ASRefCountBaseType**>(reinterpret_cast<ASRefCountBaseType**>(p.GetRawPtr())), owner);
}

namespace Instances { namespace fl_net
{
    // @0x142498890
    void URLRequest::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc >= 1)
            argv[0].Convert2String(Url);
    }

    // @0x1424988c0
    void URLVariables::AS3Constructor(unsigned argc, const Value* argv)
    {
        if (argc >= 1 && argv[0].Convert2String(Source))
        {
            Value result;
            decode(result, Source);
        }
    }

    // @0x14249b040
    void URLRequest::dataSet(const Value& /*result*/, const Value& value)
    {
        if (value.IsObject() && FUN_14250ffc0(GetVM(), value).IsInstanceTraits())
            Data = static_cast<Instances::fl::Object*>(value.GetObject());
    }

    // @0x14249be50
    void URLRequest::requestHeadersGet(SPtr<Instances::fl::Array>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method URLRequest::requestHeadersGet() is not implemented\n");
    }

    // @0x14249be10
    SPtr<Instances::fl::Array> URLRequest::requestHeadersGet()
    {
        SPtr<Instances::fl::Array> result;
        requestHeadersGet(result);
        return result;
    }

    // @0x14249c3e0
    void URLRequest::urlGet(ASString& result)
    {
        result = Url;
    }

    // @0x14249c420
    void URLRequest::urlSet(const Value& /*result*/, const ASString& value)
    {
        Url = value;
    }

    // Stores one decoded name=value pair as a dynamic property.
    static SF_INLINE void SetDecodedVariable(URLVariables* pthis, const StringBuffer& name, const StringBuffer& value)
    {
        StringManager& sm = pthis->GetVM().GetStringManager();
        ASString n = sm.CreateString(name.ToCStr());
        Value nv(n);
        ASString v = sm.CreateString(value.ToCStr());
        Value vv(v);
        Multiname mn(pthis->GetVM().GetPublicNamespace(), nv);
        pthis->SetProperty(mn, vv).DoNotCheck();
    }

    // MS2-FUNCTIONAL: same parse and calls; the exe allocates the loop registers differently (r12/r15 vs r14/rsi)
    // @0x14249b0a0
    void URLVariables::decode(const Value& /*result*/, const ASString& source)
    {
        StringBuffer name;
        StringBuffer value;
        bool inName = true;
        const char* p;
        for (UInt32 c = source.GetFirstCharAt(0, &p); c; c = source.GetNextChar(&p))
        {
            if (c == '\r')
                c = '\n';
            else if (c == '&')
            {
                SetDecodedVariable(this, name, value);
                name.Clear();
                value.Clear();
                inName = true;
                continue;
            }
            if (inName)
            {
                if (c == '=')
                    inName = false;
                else
                    name.AppendChar(c);
            }
            else
                value.AppendChar(c);
        }
        if (name.GetLength() != 0)
            SetDecodedVariable(this, name, value);
    }

    // @0x14249c380
    void URLVariables::toString(ASString& result)
    {
        result = Source;
    }

    // @0x1424991f0
    void URLRequest::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Object::ForEachChild_GC(prcc, op);
        AS3::ForEachChild_GC(prcc, Data, op, *this);
    }

    // @0x142499480
    const ASString& URLRequest::GetUrl() const
    {
        return Url;
    }

    // @0x142499490
    bool URLLoader::IsLoadingBinary() const
    {
        return strcmp(DataFormat.ToCStr(), "binary") == 0;
    }

    // @0x1424994c0
    bool URLLoader::IsLoadingText() const
    {
        return strcmp(DataFormat.ToCStr(), "text") == 0;
    }

    // @0x1424994f0
    bool URLLoader::IsLoadingVariables() const
    {
        return strcmp(DataFormat.ToCStr(), "variables") == 0;
    }

    // The AS3 movie root's builtin event names (ASVM::pMovieRoot +0x298 ...).
    enum URLLoaderEventName
    {
        URLLoaderEvent_complete = 0x298,
        URLLoaderEvent_progress = 0x2a0,
        URLLoaderEvent_open     = 0x2a8
    };

    static ASString GetURLLoaderEventName(VM& vm, URLLoaderEventName name)
    {
        UByte* proot = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(&vm) + 0x2d8);
        return ASString(*reinterpret_cast<ASStringNode**>(proot + name));
    }

    // Dispatches a plain event of the given name to pthis' listeners, if it has any.
    static SF_INLINE void DispatchURLLoaderEvent(URLLoader* pthis, URLLoaderEventName name)
    {
        ASString type = GetURLLoaderEventName(pthis->GetVM(), name);
        if (pthis->HasEventHandler(type, false))
        {
            SPtr<fl_events::Event> evt = pthis->CreateEventObject(type, false, false);
            evt->Target = pthis;
            pthis->DispatchSingleEvent(evt, false);
        }
    }

    // @0x142498d90
    void URLLoader::ExecuteCompleteEvent()
    {
        DispatchURLLoaderEvent(this, URLLoaderEvent_complete);
    }

    // @0x142498e40
    void URLLoader::ExecuteErrorEvent(const char* errorStr)
    {
        SPtr<fl_events::Event> evt = CreateIOErrorEventObject(errorStr);
        evt->Target = this;
        DispatchSingleEvent(evt, false);
    }

    // @0x142498ef0
    void URLLoader::ExecuteOpenEvent()
    {
        DispatchURLLoaderEvent(this, URLLoaderEvent_open);
    }

    // @0x142498fa0
    void URLLoader::ExecuteProgressEvent(UInt32 bytesLoaded, UInt32 bytesTotal)
    {
        ASString type = GetURLLoaderEventName(GetVM(), URLLoaderEvent_progress);
        if (HasEventHandler(type, false))
        {
            BytesLoaded = bytesLoaded;
            BytesTotal = bytesTotal;
            SPtr<fl_events::Event> evt = CreateProgressEventObject(type);
            evt->Target = this;
            // ProgressEvent's bytesLoaded / bytesTotal (+0x58 / +0x60, 64-bit counts).
            *reinterpret_cast<UInt64*>(reinterpret_cast<UByte*>(evt.GetPtr()) + 0x58) = bytesLoaded;
            *reinterpret_cast<UInt64*>(reinterpret_cast<UByte*>(evt.GetPtr()) + 0x60) = bytesTotal;
            DispatchSingleEvent(evt, false);
        }
    }

    // @0x14249a190
    void URLLoader::SetBinaryData(const ArrayPOD<UByte>& binaryData)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SPtr<Class> cls = asvm.GetClass(StringDataPtr("flash.utils.ByteArray"));
        SPtr<fl_utils::ByteArray> ba;
        if (asvm.ConstructInstance(ba, cls))
        {
            ba->Set(binaryData.GetDataPtr(), binaryData.GetSize());
            Data = ba;
        }
    }

    // MS2-FUNCTIONAL: register choice for the VM load and argument order differ
    // @0x14249a3d0
    void URLLoader::SetTextString(const char* pdata)
    {
        Data.Assign(Value(GetVM().GetStringManager().CreateString(pdata)));
    }

    // MS2-FUNCTIONAL: register allocation of this/vm differs
    // @0x14249a450
    void URLLoader::SetVariablesDataString(const char* pdata)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SPtr<Class> cls = asvm.GetClass(StringDataPtr("flash.net.URLVariables"));
        ASString str = GetVM().GetStringManager().CreateString(pdata);
        Value arg(str);
        SPtr<URLVariables> vars;
        if (asvm.ConstructInstance(vars, cls, 1, &arg))
            Data = vars;
    }


    // Walks a shared object's data tree into a SharedObjectVisitor (SharedObject.flush). Each object is written
    // once: VisitedObjects stops the walk at objects already seen.
    struct SharedObjectDataWriter
    {
        typedef HashUncached<AS3::Object*, AS3::Object*,
                             IdentityHash<AS3::Object*> > ObjectSet;

        ObjectSet            VisitedObjects;    // +0x00
        VM&                  VMRef;             // +0x08
        SharedObjectVisitor* pWriter;           // +0x10

        SharedObjectDataWriter(VM& vm, SharedObjectVisitor* pwriter) : VMRef(vm), pWriter(pwriter) {}

        static bool IsArray(const AS3::Object* pobj)
        {
            const Traits& tr = pobj->GetTraits();
            return tr.GetTraitsType() == Traits_Array && tr.IsInstanceTraits();
        }

        void VisitMembers(AS3::Object* pobj);
        void Visit(const String& name, const Value& val);
    };

    // @0x14249aa50
    void SharedObjectDataWriter::VisitMembers(AS3::Object* pobj)
    {
        if (IsArray(pobj))
        {
            const Instances::fl::Array* parr = static_cast<const Instances::fl::Array*>(pobj);
            const UInt32 size = static_cast<UInt32>(parr->GetSize());
            for (unsigned i = 0; i < size; ++i)
            {
                const Value& v = parr->At(i);
                String name;
                Format(name, "{0}", i);
                Visit(name, v);
            }
        }
        else
        {
            const AS3::Object::DynAttrsType* pmembers = pobj->GetDynamicAttrs();
            if (pmembers)
            {
                for (AS3::Object::DynAttrsType::ConstIterator it = pmembers->Begin(); !it.IsEnd(); ++it)
                {
                    const ASString& name = it->First.Name;
                    Visit(String(name.ToCStr(), name.GetLength()), it->Second);
                }
            }
        }
    }

    // @0x14249a5c0
    void SharedObjectDataWriter::Visit(const String& name, const Value& val)
    {
        switch (val.GetKind())
        {
        case Value::kNumber:
            {
                DoubleFormatter f(val.AsNumber());
                f.Convert();
                const String value(f, f.GetSize());
                pWriter->AddProperty(name, value, GFx::Value::VT_Number);
            }
            break;
        case Value::kInt:
            {
                LongFormatter f(static_cast<long>(val.AsInt()));
                f.Convert();
                const String value(f, f.GetSize());
                pWriter->AddProperty(name, value, GFx::Value::VT_Int);
            }
            break;
        case Value::kUInt:
            {
                LongFormatter f(static_cast<long>(val.AsInt()));
                f.Convert();
                const String value(f, f.GetSize());
                pWriter->AddProperty(name, value, GFx::Value::VT_Int);
            }
            break;
        case Value::kString:
            {
                const String value(val.AsString().ToCStr());
                pWriter->AddProperty(name, value, GFx::Value::VT_String);
            }
            break;
        case Value::kUndefined:
            {
                const String value("");
                pWriter->AddProperty(name, value, GFx::Value::VT_Undefined);
            }
            break;
        case Value::kBoolean:
            {
                const String value(val.AsBool() ? "true" : "false");
                pWriter->AddProperty(name, value, GFx::Value::VT_Boolean);
            }
            break;
        case Value::kObject:
            if (val.IsNull())
            {
                const String value("");
                pWriter->AddProperty(name, value, GFx::Value::VT_Null);
            }
            else
            {
                AS3::Object* pobj = val.GetObject();
                if (VisitedObjects.Get(pobj) == NULL)
                {
                    VisitedObjects.Add(pobj, pobj);
                    const Traits& tr = pobj->GetTraits();
                    if (tr.GetTraitsType() == Traits_Array && tr.IsInstanceTraits())
                    {
                        pWriter->PushArray(name);
                        VisitMembers(pobj);
                        pWriter->PopArray();
                    }
                    else
                    {
                        pWriter->PushObject(name);
                        VisitMembers(pobj);
                        pWriter->PopObject();
                    }
                }
            }
            break;
        default:
            break;
        }
    }

    // @0x142499080
    bool SharedObject::FlushImpl(SharedObjectVisitor* pwriter)
    {
        if (!pwriter)
            return false;
        AS3::Object* pdata = Data;
        SharedObjectDataWriter writer(GetVM(), pwriter);
        pwriter->Begin();
        writer.VisitMembers(pdata);
        pwriter->End();
        return true;
    }

    // SharedObject errors (VM error 1501).
    static const VM::ErrorID SharedObjectError = static_cast<VM::ErrorID>(1501);

    // @0x14249b4f0
    void SharedObject::flush(ASString& result, SInt32 /*minDiskSpace*/)
    {
        VM& vm = GetVM();
        MovieImpl* proot = static_cast<ASVM&>(vm).GetMovieImpl();
        Ptr<SharedObjectManagerBase> psomgr =
            *static_cast<SharedObjectManagerBase*>(proot->GetStateBag()->GetStateAddRef(State::State_SharedObject));
        if (psomgr)
        {
            Ptr<SharedObjectVisitor> pwriter = *psomgr->CreateWriter(Name, LocalPath, proot->GetStateBag()->GetFileOpener());
            if (FlushImpl(pwriter))
                result = vm.GetStringManager().CreateConstString("flushed");
            else
                vm.ThrowError(VM::Error(SharedObjectError, vm, "Unable to flush shared object data!"));
        }
        else
            vm.ThrowError(VM::Error(SharedObjectError, vm, "SharedObjectManager state is not installed!"));
    }

    // (sfr19) false when name has a character a shared object name cannot have; otherwise both are kept.
    // @0x14249a290
    bool SharedObject::SetNameAndLocalPath(const ASString& name, const ASString& localPath)
    {
        const char* pstr;
        for (unsigned long ch = name.GetFirstCharAt(0, &pstr); ch != 0; ch = name.GetNextChar(&pstr))
        {
            switch (ch)
            {
            case '"': case '#': case '%': case '&': case '\'': case ',': case ':': case ';':
            case '<': case '>': case '?': case '\\': case '~':
                return false;
            }
            if (SFiswspace((wchar_t)ch))
                return false;
        }
        Name = name.ToCStr();
        LocalPath = localPath.ToCStr();
        return true;
    }
}}

namespace Classes { namespace fl_net
{
    // The shared object localPath:name, made once per movie and filled from the shared object manager's store; null
    // for an invalid name or when nothing could be loaded.
    // MS2-FUNCTIONAL: the exe inlines the SharedObject constructor (out of line in sfr_as3_11) and the name check
    // @0x14249b710
    void SharedObject::getLocal(SPtr<Instances::fl_net::SharedObject>& result, const ASString& name,
                                const ASString& localPath, bool secure)
    {
        SF_UNUSED(secure);
        ASString key = GetVM().GetStringManager().CreateString(localPath.ToCStr());
        key.Append(":", 1);
        key.Append(name);
        if (SPtr<Instances::fl_net::SharedObject>* pfound = SharedObjects.Get(key))
        {
            result = *pfound;
            return;
        }

        InstanceTraits::Traits& itr = GetInstanceTraits();
        SPtr<Instances::fl_net::SharedObject> pso =
            Pickable<Instances::fl_net::SharedObject>(new(itr.Alloc()) Instances::fl_net::SharedObject(itr));
        if (!pso->SetNameAndLocalPath(name, localPath))
        {
            result = NULL;
            return;
        }

        VM& vm = GetVM();
        MovieImpl* proot = static_cast<ASVM&>(vm).GetMovieImpl();
        SPtr<Instances::fl::Object> pdata = vm.MakeObject();
        ASSharedObjectLoader loader(&vm, pdata);
        Ptr<SharedObjectManagerBase> psomgr =
            *static_cast<SharedObjectManagerBase*>(proot->GetStateBag()->GetStateAddRef(State::State_SharedObject));
        Ptr<FileOpenerBase> pfileOpener = proot->GetStateBag()->GetFileOpener();
        String sname(name.ToCStr());
        String spath(localPath.ToCStr());
        if (psomgr && psomgr->LoadSharedObject(sname, spath, &loader, pfileOpener))
        {
            pso->Data = pdata;
            result = pso;
            SharedObjects.Add(key, pso);
        }
        else
            result = NULL;
    }
}}

// ---- the shared object loader -------------------------------------------------------------------------------------

// ASSharedObjectLoader: as3_obj_net_soloader.h (sfr_as3_11 emits its deleting dtor).

// MS2-FUNCTIONAL: cl inlines the object stack PushBack the exe tail-calls
// @0x142498cb0
void ASSharedObjectLoader::Begin()
{
    ObjectStack.Resize(0);
    ObjectStack.PushBack(pData);
}

// MS2-FUNCTIONAL: register allocation of the name length/data around String::GetLength differs
// @0x142499e80
void ASSharedObjectLoader::PushObject(const String& name)
{
    AS3::Object* ptop = ObjectStack.Back();
    SPtr<Instances::fl::Object> pobj = pVM->MakeObject();

    if (bArrayIsTop)
        static_cast<Instances::fl::Array*>(ptop)->SA.PushBack(Value(pobj));
    else
        ptop->SetProperty(Multiname(*pVM, StringDataPtr(name.ToCStr(), name.GetLength())), Value(pobj)).DoNotCheck();

    bArrayIsTop = false;
    ObjectStack.PushBack(pobj);
}

// MS2-FUNCTIONAL: register allocation of the name length/data around String::GetLength differs
// @0x142499c20
void ASSharedObjectLoader::PushArray(const String& name)
{
    AS3::Object* ptop = ObjectStack.Back();
    SPtr<Instances::fl::Array> parr = pVM->MakeArray();

    if (bArrayIsTop)
        static_cast<Instances::fl::Array*>(ptop)->SA.PushBack(Value(parr));
    else
        ptop->SetProperty(Multiname(*pVM, StringDataPtr(name.ToCStr(), name.GetLength())), Value(parr)).DoNotCheck();

    bArrayIsTop = true;
    ObjectStack.PushBack(parr);
}

// @0x142498950
void ASSharedObjectLoader::AddProperty(const String& name, const String& value, GFx::Value::ValueType type)
{
    AS3::Object* ptop = ObjectStack.Back();

    Value v;
    switch (type)
    {
    case GFx::Value::VT_Int:
        v.SetSInt32(atoi(value.ToCStr()));
        break;
    case GFx::Value::VT_UInt:
        v.SetUInt32(atoi(value.ToCStr()));
        break;
    case GFx::Value::VT_Number:
        v.SetNumber(atof(value.ToCStr()));
        break;
    case GFx::Value::VT_String:
        v.Assign(pVM->GetStringManager().CreateString(value.ToCStr(), value.GetSize()));
        break;
    case GFx::Value::VT_Boolean:
        v.SetBool(!strncmp(value.ToCStr(), "true", 4));
        break;
    case GFx::Value::VT_Undefined:
        v.SetUndefined();
        break;
    case GFx::Value::VT_Null:
        v.SetNull();
        break;
    default:
        break;
    }

    if (bArrayIsTop)
        static_cast<Instances::fl::Array*>(ptop)->SA.PushBack(v);
    else
        ptop->SetProperty(Multiname(*pVM, StringDataPtr(name.ToCStr(), name.GetLength())), v).DoNotCheck();
}

// @0x142499bc0
void ASSharedObjectLoader::PopObject()
{
    ObjectStack.PopBack();
    AS3::Object* ptop = ObjectStack.Back();
    bArrayIsTop = ptop->GetTraits().GetTraitsType() == Traits_Array && ptop->GetTraits().IsInstanceTraits();
}

// @0x142499bb0
void ASSharedObjectLoader::PopArray()
{
    PopObject();
}

// @0x142498d80
void ASSharedObjectLoader::End()
{
}

namespace Classes { namespace fl_net
{
    // @0x1424990f0
    void SharedObject::ForEachChild_GC(Collector* prcc, GcOp op) const
    {
        Class::ForEachChild_GC(prcc, op);
        typedef HashUncachedLH<ASString, SPtr<Instances::fl_net::SharedObject>, ASStringHashFunctor, 324> ContainerType;
        for (ContainerType::ConstIterator it = SharedObjects.Begin(); !it.IsEnd(); ++it)
            AS3::ForEachChild_GC(prcc, it->Second, op, *this);
    }
}}

namespace InstanceTraits { namespace fl_net
{
    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499520
    Pickable<NetConnection::InstanceType> NetConnection::MakeInstance(NetConnection& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499590
    Pickable<SharedObject::InstanceType> SharedObject::MakeInstance(SharedObject& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499620
    Pickable<URLLoader::InstanceType> URLLoader::MakeInstance(URLLoader& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x1424996c0
    Pickable<URLRequest::InstanceType> URLRequest::MakeInstance(URLRequest& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499750
    Pickable<URLRequestHeader::InstanceType> URLRequestHeader::MakeInstance(URLRequestHeader& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499800
    Pickable<URLVariables::InstanceType> URLVariables::MakeInstance(URLVariables& t)
    {
        return Pickable<InstanceType>(new(t.Alloc()) InstanceType(t));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499890
    void NetConnection::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<NetConnection&>(t)));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x1424998f0
    void SharedObject::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<SharedObject&>(t)));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499970
    void URLLoader::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<URLLoader&>(t)));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499a10
    void URLRequest::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<URLRequest&>(t)));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499a90
    void URLRequestHeader::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<URLRequestHeader&>(t)));
    }

    // MS2-FUNCTIONAL: the exe inlines the instance constructor (defined out of line in sfr_as3_11); ours calls it
    // @0x142499b30
    void URLVariables::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<URLVariables&>(t)));
    }
}}

}}} // namespace Scaleform::GFx::AS3

// The font set of TextField.getTextRuns/Font.enumerateFonts (sfr_as3_13): the AS3 library is one compilation unit,
// so its adds sit in this part of the exe; instantiated here to place them the same way.
// MS2-FUNCTIONAL 0x1424a8170: byte-identical; its CheckExpand call goes to the copy paired in sfr_as3_13 (0x1424abe30)
namespace Scaleform {
template void HashSetBase<Ptr<Render::Font>, FixedSizeHash<Ptr<Render::Font> >, FixedSizeHash<Ptr<Render::Font> >,
    AllocatorGH<Ptr<Render::Font> >, HashsetCachedEntry<Ptr<Render::Font>, FixedSizeHash<Ptr<Render::Font> > > >
    ::add<Render::Font*>(void*, Render::Font* const&, UPInt);
template void HashSetBase<Ptr<Render::Font>, FixedSizeHash<Ptr<Render::Font> >, FixedSizeHash<Ptr<Render::Font> >,
    AllocatorGH<Ptr<Render::Font> >, HashsetCachedEntry<Ptr<Render::Font>, FixedSizeHash<Ptr<Render::Font> > > >
    ::add<Ptr<Render::Font> >(void*, const Ptr<Render::Font>&, UPInt);
}

using SOSharedObjectNode = Scaleform::HashNode<Scaleform::GFx::ASString,
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,
    Scaleform::GFx::ASStringHashFunctor>;
// @0x14249c160
template void Scaleform::HashSetBase<SOSharedObjectNode,
    SOSharedObjectNode::NodeHashF, SOSharedObjectNode::NodeAltHashF,
    Scaleform::AllocatorLH<Scaleform::GFx::ASString, 324>,
    Scaleform::HashsetNodeEntry<SOSharedObjectNode, SOSharedObjectNode::NodeHashF>>::setRawCapacity(
        void*, Scaleform::UPInt);

// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c500
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$00_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c560
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c5c0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c620
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$03_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c680
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$04_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c6e0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c740
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$06_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c7a0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$07_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c800
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$08_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c860
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c8c0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0L@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c920
// MS2-PIN: ?Func@?$ThunkFunc0@VApplicationDomain@fl_system@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VApplicationDomain@fl_system@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249c980
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0M@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249ca30
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0N@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249ca90
// MS2-PIN: ?Func@?$ThunkFunc1@VApplicationDomain@fl_system@Instances@AS3@GFx@Scaleform@@$00VValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249caf0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0O@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249cc70
// MS2-PIN: ?Func@?$ThunkFunc1@VApplicationDomain@fl_system@Instances@AS3@GFx@Scaleform@@$01_NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249ccd0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0P@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249ce10
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BA@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249ce80
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BB@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249cee0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BC@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249cf50
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BD@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249cfc0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BE@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d030
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BF@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d1e0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BG@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d250
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BH@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d2c0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BI@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d330
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BJ@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d3a0
// MS2-PIN: ?Func@?$ThunkFunc0@VCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@$0BK@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d410
// MS2-PIN: ?Func@?$ThunkFunc1@VIME@fl_system@Classes@AS3@GFx@Scaleform@@$0A@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d5c0
// MS2-PIN: ?Func@?$ThunkFunc0@VIME@fl_system@Classes@AS3@GFx@Scaleform@@$00VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d6c0
// MS2-PIN: ?Func@?$ThunkFunc0@VIME@fl_system@Classes@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d730
// MS2-PIN: ?Func@?$ThunkFunc1@VIME@fl_system@Classes@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d790
// MS2-PIN: ?Func@?$ThunkFunc0@VIME@fl_system@Classes@AS3@GFx@Scaleform@@$03$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d7f0
// MS2-PIN: ?Func@?$ThunkFunc1@VIME@fl_system@Classes@AS3@GFx@Scaleform@@$04$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249d810
// MS2-PIN: ?Func@?$ThunkFunc0@VSecurityDomain@fl_system@Classes@AS3@GFx@Scaleform@@$0A@V?$SPtr@VSecurityDomain@fl_system@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249deb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSystem@fl_system@Classes@AS3@GFx@Scaleform@@$0A@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249e230
// MS2-PIN: ?Func@?$ThunkFunc0@VSystem@fl_system@Classes@AS3@GFx@Scaleform@@$00K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249e250
// MS2-PIN: ?Func@?$ThunkFunc1@VSystem@fl_system@Classes@AS3@GFx@Scaleform@@$01$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249e2b0
// MS2-PIN: ?Func@?$ThunkFunc0@VSystem@fl_system@Classes@AS3@GFx@Scaleform@@$02$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249e320
// MS2-PIN: ?Func@?$ThunkFunc0@VSystem@fl_system@Classes@AS3@GFx@Scaleform@@$03$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249e340
// MS2-PIN: ?Func@?$ThunkFunc0@VSystem@fl_system@Classes@AS3@GFx@Scaleform@@$04$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249e360
// MS2-PIN: ?Func@?$ThunkFunc1@VSystem@fl_system@Classes@AS3@GFx@Scaleform@@$05$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x14249e380
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0P@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a0cb0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BA@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a0d10
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a0d70
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BC@V?$SPtr@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a0f10
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@PEAVTextFormat@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a0fc0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BE@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1000
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1060
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BG@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a10c0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BH@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1120
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BI@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1180
// MS2-PIN: ?Func@?$ThunkFunc0@VStyleSheet@fl_text@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a11f0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BJ@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a12a0
// MS2-PIN: ?Func@?$ThunkFunc0@VStyleSheet@fl_text@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a13a0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BK@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a13c0
// MS2-PIN: ?Func@?$ThunkFunc1@VStyleSheet@fl_text@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1430
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BL@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a15b0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BM@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a16b0
// MS2-PIN: ?Func@?$ThunkFunc1@VStyleSheet@fl_text@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1710
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BN@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1810
// MS2-PIN: ?Func@?$ThunkFunc2@VStyleSheet@fl_text@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@AEBVASString@56@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1870
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BO@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1a50
// MS2-PIN: ?Func@?$ThunkFunc1@VStyleSheet@fl_text@Instances@AS3@GFx@Scaleform@@$04V?$SPtr@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1ac0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0BP@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1c80
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CA@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1ce0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CB@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1d40
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CC@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1da0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CD@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1e00
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CE@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1e60
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CF@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1ec0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CG@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1f20
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CH@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a1f90
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CI@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2090
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CJ@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a20f0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CK@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2160
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CL@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2310
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CM@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2380
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CN@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a23e0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CO@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2440
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0CP@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2600
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DA@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2660
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DB@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a26d0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DC@V?$SPtr@VStyleSheet@fl_text@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2760
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DD@$$CBVValue@456@PEAVStyleSheet@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2810
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DE@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2850
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DF@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a28c0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DG@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a29c0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DH@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2a20
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DI@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2a90
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DJ@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2b00
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DK@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2b70
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DL@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2d20
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DM@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2db0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DN@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2e20
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DO@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2f20
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0DP@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2f80
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EA@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a2fe0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EB@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3040
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EC@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a30a0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0ED@V?$SPtr@VRectangle@fl_geom@Instances@AS3@GFx@Scaleform@@@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a31a0
// MS2-PIN: ?Func@?$ThunkFunc2@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EE@JNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a32a0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EF@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a33d0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EG@V?$SPtr@VDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3480
// MS2-PIN: ?Func@?$ThunkFunc2@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EH@JNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3600
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EI@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3730
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EJ@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a37e0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EK@V?$SPtr@VTextLineMetrics@fl_text@Instances@AS3@GFx@Scaleform@@@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3890
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EL@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3990
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EM@VASString@56@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3a40
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EN@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3af0
// MS2-PIN: ?Func@?$ThunkFunc2@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EO@V?$SPtr@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3ba0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0EP@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3cf0
// MS2-PIN: ?Func@?$ThunkFunc3@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0FA@$$CBVValue@456@JJAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3df0
// MS2-PIN: ?Func@?$ThunkFunc2@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0FB@$$CBVValue@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a3f70
// MS2-PIN: ?Func@?$ThunkFunc3@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0FC@$$CBVValue@456@PEAVTextFormat@23456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4020
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a43e0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4450
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$01VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4550
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4570
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$03VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a46c0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a46e0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$05VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4830
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4850
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$07VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a49a0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a49c0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$09VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4b10
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4b80
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4c80
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4ca0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0O@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4df0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4e10
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BA@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4f60
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a4f80
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BC@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a50d0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BD@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a50f0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5240
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BF@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5260
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BG@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a53b0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BH@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a53d0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BI@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5520
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BJ@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5540
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BK@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5690
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BL@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a56b0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BM@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5800
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BN@$$CBVValue@456@PEAVArray@fl@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a58b0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BO@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a58f0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0BP@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5960
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0CA@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5a60
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0CB@$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5a80
// MS2-PIN: ?Func@?$ThunkFunc0@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0CC@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5bd0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextFormat@fl_text@Instances@AS3@GFx@Scaleform@@$0CD@$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5c40
// MS2-PIN: ?Func@?$ThunkFunc0@VStaticText@fl_text@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a5e80
// MS2-PIN: ?Func@?$ThunkFunc0@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$0A@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6430
// MS2-PIN: ?Func@?$ThunkFunc3@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$00JJAEBVASString@56@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6490
// MS2-PIN: ?Func@?$ThunkFunc2@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$01_NJJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6650
// MS2-PIN: ?Func@?$ThunkFunc1@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$02VASString@56@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6750
// MS2-PIN: ?Func@?$ThunkFunc3@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$03VASString@56@JJ_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6800
// MS2-PIN: ?Func@?$ThunkFunc2@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$04V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6930
// MS2-PIN: ?Func@?$ThunkFunc3@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$05NNNN@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6a80
// MS2-PIN: ?Func@?$ThunkFunc1@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6bf0
// MS2-PIN: ?Func@?$ThunkFunc3@VTextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@JJ_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6c70
// MS2-PIN: ?Func@?$ThunkFunc0@VFont@fl_text@Instances@AS3@GFx@Scaleform@@$0A@VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6d60
// MS2-PIN: ?Func@?$ThunkFunc0@VFont@fl_text@Instances@AS3@GFx@Scaleform@@$00VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6d80
// MS2-PIN: ?Func@?$ThunkFunc0@VFont@fl_text@Instances@AS3@GFx@Scaleform@@$01VValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6da0
// MS2-PIN: ?Func@?$ThunkFunc1@VFont@fl_text@Instances@AS3@GFx@Scaleform@@$02_NAEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a6dc0
// MS2-PIN: ?Func@?$ThunkFunc1@VFont@fl_text@Classes@AS3@GFx@Scaleform@@$0A@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7180
// MS2-PIN: ?Func@?$ThunkFunc1@VFont@fl_text@Classes@AS3@GFx@Scaleform@@$00$$CBVValue@456@PEAVClass@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7270
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7420
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7480
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$01VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7630
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a76a0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$03VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a78e0
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7950
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$05_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7a50
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7c10
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$07K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7c70
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7cd0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$09_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7d40
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7da0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0M@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7e00
// MS2-PIN: ?Func@?$ThunkFunc1@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7e60
// MS2-PIN: ?Func@?$ThunkFunc0@VTextField@fl_text@Instances@AS3@GFx@Scaleform@@$0O@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424a7ed0
// MS2-PIN: ??_7ApplicationDomain@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143165aa0
// MS2-PIN: ??_7Capabilities@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143165c28
// MS2-PIN: ??_7IME@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143166470
// MS2-PIN: ??_7IMEConversionMode@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143166668
// MS2-PIN: ??_7SecurityDomain@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143166968
// MS2-PIN: ??_7LoaderContext@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143166c60
// MS2-PIN: ??_7Security@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143166cf8
// MS2-PIN: ??_7SecurityPanel@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143166f10
// MS2-PIN: ??_7System@fl_system@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x1431670d8
// MS2-PIN: ??_7Capabilities@fl_system@Classes@AS3@GFx@Scaleform@@6B@ 0x143165cc0
// MS2-PIN: ??_7IME@fl_system@Classes@AS3@GFx@Scaleform@@6B@ 0x143166500
// MS2-PIN: ??_7IMEConversionMode@fl_system@Classes@AS3@GFx@Scaleform@@6B@ 0x143166700
// MS2-PIN: ??_7SecurityDomain@fl_system@Classes@AS3@GFx@Scaleform@@6B@ 0x143166a00
// MS2-PIN: ??_7Security@fl_system@Classes@AS3@GFx@Scaleform@@6B@ 0x143166d88
// MS2-PIN: ??_7SecurityPanel@fl_system@Classes@AS3@GFx@Scaleform@@6B@ 0x143166fa8
// MS2-PIN: ??_7System@fl_system@Classes@AS3@GFx@Scaleform@@6B@ 0x143167168
// MS2-PIN: ??_7ApplicationDomain@fl_system@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431659f0
// MS2-PIN: ??_7LoaderContext@fl_system@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143166bb8
// MS2-PIN: ??_7SecurityDomain@fl_system@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431668c0
// MS2-PIN: ??_7ApplicationDomain@fl_system@Instances@AS3@GFx@Scaleform@@6B@ 0x143165920
// MS2-PIN: ??_7LoaderContext@fl_system@Instances@AS3@GFx@Scaleform@@6B@ 0x143166ae8
// MS2-PIN: ??_7SecurityDomain@fl_system@Instances@AS3@GFx@Scaleform@@6B@ 0x1431667f0
// MS2-PIN: ??_GApplicationDomain@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f250
// MS2-PIN: ??_GCapabilities@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f3a0
// MS2-PIN: ??_GIME@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f490
// MS2-PIN: ??_GIMEConversionMode@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f580
// MS2-PIN: ??_GSecurityDomain@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f910
// MS2-PIN: ??_GLoaderContext@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f670
// MS2-PIN: ??_GSecurity@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f820
// MS2-PIN: ??_GSecurityPanel@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249fac0
// MS2-PIN: ??_GSystem@fl_system@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249fbb0
// MS2-PIN: ??_GCapabilities@fl_system@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f430
// MS2-PIN: ??_GIME@fl_system@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f520
// MS2-PIN: ??_GIMEConversionMode@fl_system@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f610
// MS2-PIN: ??_GSecurityDomain@fl_system@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f9a0
// MS2-PIN: ??_GSecurity@fl_system@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f8b0
// MS2-PIN: ??_GSecurityPanel@fl_system@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249fb50
// MS2-PIN: ??_GSystem@fl_system@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249fc40
// MS2-PIN: ??_GApplicationDomain@fl_system@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f2e0
// MS2-PIN: ??_GLoaderContext@fl_system@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f700
// MS2-PIN: ??_GSecurityDomain@fl_system@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249fa00
// MS2-PIN: ??_GApplicationDomain@fl_system@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f340
// MS2-PIN: ??_GLoaderContext@fl_system@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249f760
// MS2-PIN: ??_GSecurityDomain@fl_system@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x14249fa60
// MS2-PIN: ??_7AntiAliasType@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143169970
// MS2-PIN: ??_7AntiAliasType@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x143169a08
// MS2-PIN: ??_7FontStyle@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316a078
// MS2-PIN: ??_7FontStyle@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316a108
// MS2-PIN: ??_7FontType@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316a1f0
// MS2-PIN: ??_7FontType@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316a280
// MS2-PIN: ??_7GridFitType@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316a368
// MS2-PIN: ??_7GridFitType@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316a400
// MS2-PIN: ??_7TextColorType@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316aca8
// MS2-PIN: ??_7TextColorType@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316ad40
// MS2-PIN: ??_7TextDisplayMode@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316ae30
// MS2-PIN: ??_7TextDisplayMode@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316aec8
// MS2-PIN: ??_7TextFieldAutoSize@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316b640
// MS2-PIN: ??_7TextFieldAutoSize@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316b6d8
// MS2-PIN: ??_7TextFieldType@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316b7c8
// MS2-PIN: ??_7TextFieldType@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316b860
// MS2-PIN: ??_7TextFormatAlign@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316b948
// MS2-PIN: ??_7TextFormatAlign@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316b9e0
// MS2-PIN: ??_7TextRenderer@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316bad0
// MS2-PIN: ??_7TextRenderer@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x14316bb68
// MS2-PIN: ??_GAntiAliasType@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa530
// MS2-PIN: ??_GAntiAliasType@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa5c0
// MS2-PIN: ??_GFontStyle@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aaa70
// MS2-PIN: ??_GFontStyle@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aab00
// MS2-PIN: ??_GFontType@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aab60
// MS2-PIN: ??_GFontType@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aabf0
// MS2-PIN: ??_GGridFitType@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aacb0
// MS2-PIN: ??_GGridFitType@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aad40
// MS2-PIN: ??_GTextColorType@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab0f0
// MS2-PIN: ??_GTextColorType@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab180
// MS2-PIN: ??_GTextDisplayMode@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab1e0
// MS2-PIN: ??_GTextDisplayMode@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab270
// MS2-PIN: ??_GTextFieldAutoSize@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab420
// MS2-PIN: ??_GTextFieldAutoSize@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab4b0
// MS2-PIN: ??_GTextFieldType@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab510
// MS2-PIN: ??_GTextFieldType@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab5a0
// MS2-PIN: ??_GTextFormatAlign@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab750
// MS2-PIN: ??_GTextFormatAlign@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab7e0
// MS2-PIN: ??_GTextRenderer@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab990
// MS2-PIN: ??_GTextRenderer@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aba20
// MS2-PIN: ??_7CSMSettings@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143169c70
// MS2-PIN: ??_7CSMSettings@fl_text@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143169bc8
// MS2-PIN: ??_7CSMSettings@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x143169b00
// MS2-PIN: ??_7Font@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x143169e88
// MS2-PIN: ??_7Font@fl_text@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x143169de8
// MS2-PIN: ??_7Font@fl_text@Classes@AS3@GFx@Scaleform@@6B@ 0x143169f18
// MS2-PIN: ??_7Font@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x143169d18
// MS2-PIN: ??_7TextLineMetrics@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316b358
// MS2-PIN: ??_7TextLineMetrics@fl_text@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316b2b0
// MS2-PIN: ??_7TextLineMetrics@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x14316b1e0
// MS2-PIN: ??_GCSMSettings@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa620
// MS2-PIN: ??_GCSMSettings@fl_text@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa6b0
// MS2-PIN: ??_GCSMSettings@fl_text@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa710
// MS2-PIN: ??_GFont@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa880
// MS2-PIN: ??_GFont@fl_text@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa970
// MS2-PIN: ??_GFont@fl_text@Classes@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa910
// MS2-PIN: ??_GFont@fl_text@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aa9d0
// MS2-PIN: ??_GTextLineMetrics@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab840
// MS2-PIN: ??_GTextLineMetrics@fl_text@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab8d0
// MS2-PIN: ??_GTextLineMetrics@fl_text@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab930
// MS2-PIN: ??_7StaticText@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316a688
// MS2-PIN: ??_7StaticText@fl_text@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316a5e0
// MS2-PIN: ??_7StyleSheet@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316a8c8
// MS2-PIN: ??_7StyleSheet@fl_text@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316a820
// MS2-PIN: ??_7TextField@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316b150
// MS2-PIN: ??_7TextField@fl_text@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316b0a8
// MS2-PIN: ??_7TextFormat@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316aac8
// MS2-PIN: ??_7TextFormat@fl_text@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316aa20
// MS2-PIN: ??_7TextSnapshot@fl_text@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14316bdc8
// MS2-PIN: ??_7TextSnapshot@fl_text@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x14316bd20
// MS2-PIN: ??_GStaticText@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aadd0
// MS2-PIN: ??_GStaticText@fl_text@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aae60
// MS2-PIN: ??_GStyleSheet@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aaf90
// MS2-PIN: ??_GStyleSheet@fl_text@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab020
// MS2-PIN: ??_GTextField@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab2d0
// MS2-PIN: ??_GTextField@fl_text@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab360
// MS2-PIN: ??_GTextFormat@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab600
// MS2-PIN: ??_GTextFormat@fl_text@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424ab690
// MS2-PIN: ??_GTextSnapshot@fl_text@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424aba80
// MS2-PIN: ??_GTextSnapshot@fl_text@InstanceTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424abb10
// MS2-PIN: ??_7StaticText@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x14316a510
// MS2-PIN: ??_GStaticText@fl_text@Instances@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142442e10
// MS2-PIN: ?Reserve@?$ArrayDataBase@PEAVObject@AS3@GFx@Scaleform@@U?$AllocatorLH@PEAVObject@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14249a070
// MS2-PIN: ??0StaticText@fl_text@Instances@AS3@GFx@Scaleform@@QEAA@AEAVTraits@InstanceTraits@345@@Z 0x1424a8d20 ; unique
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
// MS2-PIN: ??_7StyleManagerBase@Text@Render@Scaleform@@6B@ 0x14316a718
// MS2-PIN: ??_7StyleManager@Text@GFx@Scaleform@@6B@ 0x14316a738
// MS2-PIN: ??_7StyleSheet@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x14316a758
// MS2-PIN: ??_7TextField@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x14316afd8
// MS2-PIN: ??_7TextFormat@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x14316a958
// MS2-PIN: ??_7TextSnapshot@fl_text@Instances@AS3@GFx@Scaleform@@6B@ 0x14316bc50
// MS2-PIN: ??$add@PEAVFont@Render@Scaleform@@@?$HashSetBase@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@AEAAXPEAXAEBQEAVFont@Render@1@_K@Z 0x1424a7f90 ; unique
// MS2-PIN: ??$add@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@@?$HashSetBase@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@@2@V32@U?$AllocatorGH@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@$01@2@V?$HashsetCachedEntry@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@@2@@2@@Scaleform@@AEAAXPEAXAEBV?$Ptr@VFont@Render@Scaleform@@@1@_K@Z 0x1424a8170 ; unique
// MS2-PIN: ??0?$HashsetCachedEntry@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@V?$FixedSizeHash@V?$Ptr@VFont@Render@Scaleform@@@Scaleform@@@2@@Scaleform@@QEAA@AEBV01@@Z 0x1424a8300 ; unique
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@V?$SPtr@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@V?$SPtr@VSharedObject@fl_net@Instances@AS3@GFx@Scaleform@@@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x14249c160
