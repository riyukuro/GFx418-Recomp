// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_TEXT_H
#define MS2_SF_GFX_AS3_OBJ_TEXT_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_display.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Font : public Instances::fl::Object
    {
    public:
        // @0x1424b08d0
        void fontNameGet(Value& result);
        // @0x1424b09c0
        void fontStyleGet(Value& result);
        // @0x1424b0af0
        void fontTypeGet(Value& result);
        // @0x1424b2e80
        void hasGlyphs(bool& result, const ASString&);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class StaticText : public Instances::fl_display::DisplayObject
    {
    public:
        // @0x1424b4d00
        void textGet(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class StyleSheet : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x1424afea0
        void clear(const Value& result);
        // @0x1424b15e0
        void getStyle(SPtr<Instances::fl::Object>& result, const ASString&);
        // @0x1424b32f0
        void parseCSS(const Value& result, const ASString&);
        // @0x1424b43a0
        void setStyle(const Value& result, const ASString&, const Value&);
        // @0x1424b4710
        void styleNamesGet(SPtr<Instances::fl::Array>& result);
        // @0x1424b4f80
        void transform(SPtr<Instances::fl_text::TextFormat>& result, const Value&);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class TextField : public Instances::fl_display::InteractiveObject
    {
    public:
        // @0x1424af880
        void alwaysShowSelectionGet(bool& result);
        // @0x1424af8a0
        void alwaysShowSelectionSet(const Value& result, bool);
        // @0x1424af8d0
        void antiAliasTypeGet(ASString& result);
        // @0x1424af960
        void antiAliasTypeSet(const Value& result, const ASString&);
        // @0x1424af9e0
        void appendText(const Value& result, const ASString&);
        // @0x1424afa40
        void autoSizeGet(ASString& result);
        // @0x1424afb10
        void autoSizeSet(const Value& result, const ASString&);
        // @0x1424afd00
        void backgroundColorGet(UInt32& result);
        // @0x1424afd20
        void backgroundColorSet(const Value& result, UInt32);
        // @0x1424afd30
        void backgroundGet(bool& result);
        // @0x1424afd50
        void backgroundSet(const Value& result, bool);
        // @0x1424afdb0
        void borderColorGet(UInt32& result);
        // @0x1424afdd0
        void borderColorSet(const Value& result, UInt32);
        // @0x1424afde0
        void borderGet(bool& result);
        // @0x1424afe00
        void borderSet(const Value& result, bool);
        // @0x1424afe10
        void bottomScrollVGet(SInt32& result);
        // @0x1424afe60
        void caretIndexGet(SInt32& result);
        // @0x1424afee0
        void condenseWhiteGet(bool& result);
        // @0x1424aff00
        void condenseWhiteSet(const Value& result, bool);
        // @0x1424aff20
        void contextMenuGet(SPtr<Instances::fl_display::NativeMenu>& result);
        // @0x1424affb0
        void defaultTextFormatGet(SPtr<Instances::fl_text::TextFormat>& result);
        // @0x1424b0020
        void defaultTextFormatSet(const Value& result, Instances::fl_text::TextFormat*);
        // @0x1424b0230
        void displayAsPasswordGet(bool& result);
        // @0x1424b0250
        void displayAsPasswordSet(const Value& result, bool);
        // @0x1424b02b0
        void embedFontsGet(bool& result);
        // @0x1424b02d0
        void embedFontsSet(const Value& result, bool);
        // @0x1424b0c00
        void getCharBoundaries(SPtr<Instances::fl_geom::Rectangle>& result, SInt32);
        // @0x1424b0df0
        void getCharIndexAtPoint(SInt32& result, Value::Number, Value::Number);
        // @0x1424b0e40
        void getFirstCharInParagraph(SInt32& result, SInt32);
        // @0x1424b0ed0
        void getImageReference(SPtr<Instances::fl_display::DisplayObject>& result, const ASString&);
        // @0x1424b0ef0
        void getLineIndexAtPoint(SInt32& result, Value::Number, Value::Number);
        // @0x1424b0f40
        void getLineIndexOfChar(SInt32& result, SInt32);
        // @0x1424b0f90
        void getLineLength(SInt32& result, SInt32);
        // @0x1424b1000
        void getLineMetrics(SPtr<Instances::fl_text::TextLineMetrics>& result, SInt32);
        // @0x1424b1330
        void getLineOffset(SInt32& result, SInt32);
        // @0x1424b1380
        void getLineText(ASString& result, SInt32);
        // @0x1424b14d0
        void getParagraphLength(SInt32& result, SInt32);
        // @0x1424b2ad0
        void getTextFormat(SPtr<Instances::fl_text::TextFormat>& result, SInt32, SInt32);
        // @0x1424b2e40
        void gridFitTypeGet(ASString& result);
        // @0x1424b2e60
        void gridFitTypeSet(const Value& result, const ASString&);
        // @0x1424b2f80
        void htmlTextGet(ASString& result);
        // @0x1424b2fd0
        void htmlTextSet(const Value& result, const ASString&);
        // @0x1424b30e0
        void lengthGet(SInt32& result);
        // @0x1424b3140
        void maxCharsGet(SInt32& result);
        // @0x1424b3170
        void maxCharsSet(const Value& result, SInt32);
        // @0x1424b3190
        void maxScrollHGet(SInt32& result);
        // @0x1424b31d0
        void maxScrollVGet(SInt32& result);
        // @0x1424b3200
        void mouseWheelEnabledGet(bool& result);
        // @0x1424b3220
        void mouseWheelEnabledSet(const Value& result, bool);
        // @0x1424b3250
        void multilineGet(bool& result);
        // @0x1424b3270
        void multilineSet(const Value& result, bool);
        // @0x1424b32c0
        void numLinesGet(SInt32& result);
        // @0x1424b3a00
        void replaceSelectedText(const Value& result, const ASString&);
        // @0x1424b3bf0
        void replaceText(const Value& result, SInt32, SInt32, const ASString&);
        // @0x1424b3e70
        void restrictGet(ASString& result);
        // @0x1424b3f20
        void restrictSet(const Value& result, const ASString&);
        // @0x1424b3f70
        void scrollHGet(SInt32& result);
        // @0x1424b3fb0
        void scrollHSet(const Value& result, SInt32);
        // @0x1424b4000
        void scrollVGet(SInt32& result);
        // @0x1424b4030
        void scrollVSet(const Value& result, SInt32);
        // @0x1424b4070
        void selectableGet(bool& result);
        // @0x1424b4090
        void selectableSet(const Value& result, bool);
        // @0x1424b40a0
        void selectionBeginIndexGet(SInt32& result);
        // @0x1424b40c0
        void selectionEndIndexGet(SInt32& result);
        // @0x1424b4390
        void setSelection(const Value& result, SInt32, SInt32);
        // @0x1424b44d0
        void setTextFormat(const Value& result, Instances::fl_text::TextFormat*, SInt32, SInt32);
        // @0x1424b4680
        void sharpnessGet(Value::Number& result);
        // @0x1424b46a0
        void sharpnessSet(const Value& result, Value::Number);
        // @0x1424b49a0
        void styleSheetGet(SPtr<Instances::fl_text::StyleSheet>& result);
        // @0x1424b4a50
        void styleSheetSet(const Value& result, Instances::fl_text::StyleSheet*);
        // @0x1424b4cd0
        void textColorGet(UInt32& result);
        // @0x1424b4cf0
        void textColorSet(const Value& result, UInt32);
        // @0x1424b4e30
        void textGet(ASString& result);
        // @0x1424b4e80
        void textHeightGet(Value::Number& result);
        // @0x1424b4ea0
        void textSet(const Value& result, const ASString&);
        // @0x1424b4f00
        void textWidthGet(Value::Number& result);
        // @0x1424b4f20
        void thicknessGet(Value::Number& result);
        // @0x1424b4f40
        void thicknessSet(const Value& result, Value::Number);
        // @0x1424b51a0
        void typeGet(ASString& result);
        // @0x1424b5230
        void typeSet(const Value& result, const ASString&);
        // @0x1424b53a0
        void useRichTextClipboardGet(bool& result);
        // @0x1424b53c0
        void useRichTextClipboardSet(const Value& result, bool);
        // @0x1424b5420
        void wordWrapGet(bool& result);
        // @0x1424b5440
        void wordWrapSet(const Value& result, bool);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class TextFormat : public Instances::fl::Object
    {
    public:
        // @0x1424af820
        void alignGet(ASString& result);
        // @0x1424af870
        void alignSet(const Value& result, const ASString&);
        // @0x1424afd60
        void blockIndentGet(Value& result);
        // @0x1424afd70
        void blockIndentSet(const Value& result, const Value&);
        // @0x1424afd80
        void boldGet(Value& result);
        // @0x1424afda0
        void boldSet(const Value& result, const Value&);
        // @0x1424afe40
        void bulletGet(Value& result);
        // @0x1424afe50
        void bulletSet(const Value& result, const Value&);
        // @0x1424afeb0
        void colorGet(Value& result);
        // @0x1424afed0
        void colorSet(const Value& result, const Value&);
        // @0x1424b0870
        void fontGet(ASString& result);
        // @0x1424b09b0
        void fontSet(const Value& result, const ASString&);
        // @0x1424b2ff0
        void indentGet(Value& result);
        // @0x1424b3010
        void indentSet(const Value& result, const Value&);
        // @0x1424b3020
        void italicGet(Value& result);
        // @0x1424b3040
        void italicSet(const Value& result, const Value&);
        // @0x1424b3050
        void kerningGet(Value& result);
        // @0x1424b3070
        void kerningSet(const Value& result, const Value&);
        // @0x1424b3080
        void leadingGet(Value& result);
        // @0x1424b30a0
        void leadingSet(const Value& result, const Value&);
        // @0x1424b30b0
        void leftMarginGet(Value& result);
        // @0x1424b30d0
        void leftMarginSet(const Value& result, const Value&);
        // @0x1424b3110
        void letterSpacingGet(Value& result);
        // @0x1424b3130
        void letterSpacingSet(const Value& result, const Value&);
        // @0x1424b3f40
        void rightMarginGet(Value& result);
        // @0x1424b3f60
        void rightMarginSet(const Value& result, const Value&);
        // @0x1424b46c0
        void sizeGet(Value& result);
        // @0x1424b46e0
        void sizeSet(const Value& result, const Value&);
        // @0x1424b4bd0
        void tabStopsGet(SPtr<Instances::fl::Array>& result);
        // @0x1424b4bf0
        void tabStopsSet(const Value& result, Instances::fl::Array*);
        // @0x1424b4c60
        void targetGet(ASString& result);
        // @0x1424b4cc0
        void targetSet(const Value& result, const ASString&);
        // @0x1424b5300
        void underlineGet(Value& result);
        // @0x1424b5320
        void underlineSet(const Value& result, const Value&);
        // @0x1424b5330
        void urlGet(ASString& result);
        // @0x1424b5390
        void urlSet(const Value& result, const ASString&);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class TextSnapshot : public Instances::fl::Object
    {
    public:
        // @0x1424afe80
        void charCountGet(SInt32& result);
        // @0x1424b07e0
        void findText(SInt32& result, SInt32, const ASString&, bool);
        // @0x1424b1500
        void getSelected(bool& result, SInt32, SInt32);
        // @0x1424b1530
        void getSelectedText(ASString& result, bool);
        // @0x1424b29e0
        void getText(ASString& result, SInt32, SInt32, bool);
        // @0x1424b2d00
        void getTextRunInfo(SPtr<Instances::fl::Array>& result, SInt32, SInt32);
        // @0x1424b2f20
        void hitTestTextNearPos(Value::Number& result, Value::Number, Value::Number, Value::Number);
        // @0x1424b4330
        void setSelectColor(const Value& result, UInt32);
        // @0x1424b4360
        void setSelected(const Value& result, SInt32, SInt32, bool);
    };

}}

namespace Classes { namespace fl_text {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Font : public Class
    {
    public:
        // @0x1424b02f0
        void enumerateFonts(SPtr<Instances::fl::Array>& result, bool);
        // @0x1424b3810
        void registerFont(const Value& result, Class*);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
