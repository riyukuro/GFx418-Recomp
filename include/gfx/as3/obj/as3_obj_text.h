// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_TEXT_H
#define MS2_SF_GFX_AS3_OBJ_TEXT_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_display.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"
#include "ms2/scaleform/include/gfx/gfx_textsnapshot.h"

namespace Scaleform { namespace Render { class Font; }}

// The CSS style sheet of a StyleSheet instance. Its bodies (sfr_gfx_06g, text_stylesheet.h) and its base
// (text_styledtext.h) are built on the render text headers, which do not mix with these; only what the instance's
// constructor and destructor touch is modeled.
namespace Scaleform { namespace Render { namespace Text {

struct Style;

// Style lookup for HTML parsing. vftable 0x14316a718.
class StyleManagerBase
{
public:
    enum KeyType { CSS_Tag = 0, CSS_Class = 1, CSS_None = 2 };

    virtual ~StyleManagerBase() {}
    virtual const Style* GetStyle(KeyType type, const String& name) const = 0;
    virtual const Style* GetStyle(KeyType type, const char* name, UPInt len = SF_MAX_UPINT) const = 0;
    virtual const Style* GetStyle(KeyType type, const wchar_t* name, UPInt len = SF_MAX_UPINT) const = 0;
};

}}} // namespace Scaleform::Render::Text

namespace Scaleform { namespace GFx { namespace Text {

// 0x30 bytes, vftable 0x14316a738.
class StyleManager : public Render::Text::StyleManagerBase
{
public:
    StyleManager() : State(0) {}
    ~StyleManager();                                                                        // 0x142609070

    virtual const Render::Text::Style* GetStyle(KeyType type, const String& name) const;                  // 0x142609c70
    virtual const Render::Text::Style* GetStyle(KeyType type, const char* name, UPInt len = SF_MAX_UPINT) const;   // 0x142609d30
    virtual const Render::Text::Style* GetStyle(KeyType type, const wchar_t* name, UPInt len = SF_MAX_UPINT) const; // 0x142609dc0

private:
    // The styles by key (a HashUncachedLH): only its table pointer.
    struct StyleHash
    {
        StyleHash() : pTable(NULL) {}
        void* pTable;
    };
    // A style's key.
    struct StyleKey
    {
        StyleKey() : Type(CSS_None) {}
        KeyType     Type;       // +0x00
        StringLH    Value;      // +0x08
        UPInt       HashValue;  // +0x10
    };

    StyleHash   Styles;         // +0x08
    StyleKey    TempKey;        // +0x10 the key of the last lookup
    UInt32      State;          // +0x28
};

}}} // namespace Scaleform::GFx::Text

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_text {
    // 0x50 bytes: the font settings of TextRenderer.setAdvancedAntiAliasingTable.
    class CSMSettings : public Instances::fl::Object
    {
    public:
        CSMSettings(InstanceTraits::Traits& t);
        // @0x1424ac470
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_text::CSMSettings"; }

        Value::Number   fontSize;       // +0x38
        Value::Number   insideCutoff;   // +0x40
        Value::Number   outsideCutoff;  // +0x48
    };

    // 0x58 bytes.
    class Font : public Instances::fl::Object
    {
    public:
        Font(InstanceTraits::Traits& t);
        // @0x1424ac4b0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_text::Font"; }

        Ptr<Render::Font>   pFont;      // +0x38: the font the instance stands for; NULL for a font class not bound yet
        ASString            fontName;   // +0x40
        ASString            fontStyle;  // +0x48
        ASString            fontType;   // +0x50

        // @0x1424aced0
        virtual void InitInstance(bool extCall = false);
        // Binds the instance to the library font exported under its class name; returns false on every path.
        // @0x1424abe80
        bool AttachLibraryFont();

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
        StaticText(InstanceTraits::Traits& t) : Instances::fl_display::DisplayObject(t) {}   // 0x1424a8d20
        // @0x1424b4d00
        void textGet(ASString& result);
    };

    // 0x80 bytes.
    class StyleSheet : public Instances::fl_events::EventDispatcher
    {
    public:
        StyleSheet(InstanceTraits::Traits& t);   // 0x1424a8e80

        Text::StyleManager  CSS;        // +0x50

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
        SPtr<Instances::fl::Array> styleNamesGet();
        // @0x1424b4f80
        void transform(SPtr<Instances::fl_text::TextFormat>& result, const Value&);
        SPtr<Instances::fl_text::TextFormat> transform(const Value& value);
    };

    // 0x70 bytes: no members of its own; the display text field it scripts is pDispObj.
    class TextField : public Instances::fl_display::InteractiveObject
    {
    public:
        TextField(InstanceTraits::Traits& t);   // 0x1424a9290
        // @0x1424ac5e0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_text::TextField"; }
        virtual void InitInstance(bool extCall = false);        // 0x1424acee0
        virtual GFx::DisplayObject* CreateStageObject();        // 0x1424ac040

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
        SPtr<Instances::fl_geom::Rectangle> getCharBoundaries(SInt32 charIndex);
        // @0x1424b0df0
        void getCharIndexAtPoint(SInt32& result, Value::Number, Value::Number);
        // @0x1424b0e40
        void getFirstCharInParagraph(SInt32& result, SInt32);
        // @0x1424b0ed0
        void getImageReference(SPtr<Instances::fl_display::DisplayObject>& result, const ASString&);
        SPtr<Instances::fl_display::DisplayObject> getImageReference(const ASString& id);
        // @0x1424b0ef0
        void getLineIndexAtPoint(SInt32& result, Value::Number, Value::Number);
        // @0x1424b0f40
        void getLineIndexOfChar(SInt32& result, SInt32);
        // @0x1424b0f90
        void getLineLength(SInt32& result, SInt32);
        // @0x1424b1000
        void getLineMetrics(SPtr<Instances::fl_text::TextLineMetrics>& result, SInt32);
        SPtr<Instances::fl_text::TextLineMetrics> getLineMetrics(SInt32 lineIndex);
        // @0x1424b1330
        void getLineOffset(SInt32& result, SInt32);
        // @0x1424b1380
        void getLineText(ASString& result, SInt32);
        // @0x1424b14d0
        void getParagraphLength(SInt32& result, SInt32);
        // @0x1424b2ad0
        void getTextFormat(SPtr<Instances::fl_text::TextFormat>& result, SInt32, SInt32);
        SPtr<Instances::fl_text::TextFormat> getTextFormat(SInt32 beginIndex, SInt32 endIndex);
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
        SPtr<Instances::fl_text::StyleSheet> styleSheetGet();
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

    // 0x260 bytes: the properties, null while unset.
    class TextFormat : public Instances::fl::Object
    {
    public:
        TextFormat(InstanceTraits::Traits& t);   // 0x1424a9690

        Value                       align;          // +0x038
        Value                       blockIndent;    // +0x058
        Value                       bullet;         // +0x078
        Value                       bold;           // +0x098
        Value                       color;          // +0x0b8
        Value                       font;           // +0x0d8
        Value                       italic;         // +0x0f8
        Value                       indent;         // +0x118
        Value                       kerning;        // +0x138
        Value                       leading;        // +0x158
        Value                       leftMargin;     // +0x178
        Value                       rightMargin;    // +0x198
        Value                       letterSpacing;  // +0x1b8
        Value                       size;           // +0x1d8
        SPtr<Instances::fl::Array>  tabStops;       // +0x1f8
        Value                       target;         // +0x200
        Value                       underline;      // +0x220
        Value                       url;            // +0x240

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
        SPtr<Instances::fl::Array> tabStopsGet();
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

    // 0x68 bytes.
    class TextLineMetrics : public Instances::fl::Object
    {
    public:
        TextLineMetrics(InstanceTraits::Traits& t);
        // @0x1424ac6a0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_text::TextLineMetrics"; }

        Value::Number   ascent;     // +0x38
        Value::Number   descent;    // +0x40
        Value::Number   height;     // +0x48
        Value::Number   leading;    // +0x50
        Value::Number   width;      // +0x58
        Value::Number   x;          // +0x60

        // @0x1424abd70
        virtual void AS3Constructor(unsigned argc, const Value* argv);
    };

    // 0x60 bytes.
    class TextSnapshot : public Instances::fl::Object
    {
    public:
        TextSnapshot(InstanceTraits::Traits& t);   // 0x1424a9ea0

        StaticTextSnapshotData  SnapshotData;   // +0x38

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
        SPtr<Instances::fl::Array> getTextRunInfo(SInt32 beginIndex, SInt32 endIndex);
        // @0x1424b2f20
        void hitTestTextNearPos(Value::Number& result, Value::Number, Value::Number, Value::Number);
        // @0x1424b4330
        void setSelectColor(const Value& result, UInt32);
        // @0x1424b4360
        void setSelected(const Value& result, SInt32, SInt32, bool);
    };
}}

namespace Classes { namespace fl_text {
    class Font : public Class
    {
    public:
        Font(ClassTraits::Traits& t);
        // @0x1424ac490
        virtual const char* GetAS3ObjectType() const { return "Classes::fl_text::Font"; }

        // @0x1424b02f0
        void enumerateFonts(SPtr<Instances::fl::Array>& result, bool);
        // @0x1424b3810
        void registerFont(const Value& result, Class*);
    };

    // 0x60 bytes.
    class AntiAliasType : public Class
    {
    public:
        AntiAliasType(ClassTraits::Traits& t);
        // @0x1424ac440
        virtual const char* GetAS3ObjectType() const { return "Classes::AntiAliasType"; }

        const char* ADVANCED;    // +0x50
        const char* NORMAL;      // +0x58
    };

    // 0x70 bytes.
    class FontStyle : public Class
    {
    public:
        FontStyle(ClassTraits::Traits& t);
        // @0x1424ac4d0
        virtual const char* GetAS3ObjectType() const { return "Classes::FontStyle"; }

        const char* BOLD;        // +0x50
        const char* BOLD_ITALIC; // +0x58
        const char* ITALIC;      // +0x60
        const char* REGULAR;     // +0x68
    };

    // 0x60 bytes.
    class FontType : public Class
    {
    public:
        FontType(ClassTraits::Traits& t);
        // @0x1424ac4f0
        virtual const char* GetAS3ObjectType() const { return "Classes::FontType"; }

        const char* DEVICE;      // +0x50
        const char* EMBEDDED;    // +0x58
    };

    // 0x68 bytes.
    class GridFitType : public Class
    {
    public:
        GridFitType(ClassTraits::Traits& t);
        // @0x1424ac510
        virtual const char* GetAS3ObjectType() const { return "Classes::GridFitType"; }

        const char* NONE;        // +0x50
        const char* PIXEL;       // +0x58
        const char* SUBPIXEL;    // +0x60
    };

    // 0x60 bytes.
    class TextColorType : public Class
    {
    public:
        TextColorType(ClassTraits::Traits& t);
        // @0x1424ac590
        virtual const char* GetAS3ObjectType() const { return "Classes::TextColorType"; }

        const char* DARK_COLOR;  // +0x50
        const char* LIGHT_COLOR; // +0x58
    };

    // 0x68 bytes.
    class TextDisplayMode : public Class
    {
    public:
        TextDisplayMode(ClassTraits::Traits& t);
        // @0x1424ac5b0
        virtual const char* GetAS3ObjectType() const { return "Classes::TextDisplayMode"; }

        const char* CRT;         // +0x50
        const char* DEFAULT;     // +0x58
        const char* LCD;         // +0x60
    };

    // 0x70 bytes.
    class TextFieldAutoSize : public Class
    {
    public:
        TextFieldAutoSize(ClassTraits::Traits& t);
        // @0x1424ac600
        virtual const char* GetAS3ObjectType() const { return "Classes::TextFieldAutoSize"; }

        const char* CENTER;      // +0x50
        const char* LEFT;        // +0x58
        const char* NONE;        // +0x60
        const char* RIGHT;       // +0x68
    };

    // 0x60 bytes.
    class TextFieldType : public Class
    {
    public:
        TextFieldType(ClassTraits::Traits& t);
        // @0x1424ac620
        virtual const char* GetAS3ObjectType() const { return "Classes::TextFieldType"; }

        const char* DYNAMIC;     // +0x50
        const char* INPUT;       // +0x58
    };

    // 0x70 bytes.
    class TextFormatAlign : public Class
    {
    public:
        TextFormatAlign(ClassTraits::Traits& t);
        // @0x1424ac670
        virtual const char* GetAS3ObjectType() const { return "Classes::TextFormatAlign"; }

        const char* CENTER;      // +0x50
        const char* JUSTIFY;     // +0x58
        const char* LEFT;        // +0x60
        const char* RIGHT;       // +0x68
    };


    class TextRenderer : public Class
    {
    public:
        TextRenderer(ClassTraits::Traits& t);
        // @0x1424ac6c0
        virtual const char* GetAS3ObjectType() const { return "Classes::TextRenderer"; }
    };
}}

namespace InstanceTraits { namespace fl_text {
    class CSMSettings : public CTraits
    {
    public:
        typedef Instances::fl_text::CSMSettings InstanceType;

        CSMSettings(VM& vm, const ClassInfo& ci);
        // @0x1424ac460
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::CSMSettings"; }
        // @0x1424ad4d0
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(new(t.Alloc()) InstanceType(t));
        }
    };

    class Font : public CTraits
    {
    public:
        typedef Instances::fl_text::Font InstanceType;

        Font(VM& vm, const ClassInfo& ci);
        // @0x1424ac4a0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Font"; }
        // @0x1424ad540
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(new(t.Alloc()) InstanceType(t));
        }
    };

    class TextLineMetrics : public CTraits
    {
    public:
        typedef Instances::fl_text::TextLineMetrics InstanceType;

        TextLineMetrics(VM& vm, const ClassInfo& ci);
        // @0x1424ac690
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TextLineMetrics"; }
        // @0x1424ad780
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(new(t.Alloc()) InstanceType(t));
        }
    };

    class StaticText : public CTraits
    {
    public:
        typedef Instances::fl_text::StaticText InstanceType;

        StaticText(VM& vm, const ClassInfo& ci);
        // @0x1424ac530
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::StaticText"; }
        // @0x1424ad5f0
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(new(t.Alloc()) InstanceType(t));
        }
    };

    class StyleSheet : public CTraits
    {
    public:
        typedef Instances::fl_text::StyleSheet InstanceType;

        StyleSheet(VM& vm, const ClassInfo& ci);
        // @0x1424ac560
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::StyleSheet"; }
        // @0x1424ad650
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(new(t.Alloc()) InstanceType(t));
        }
    };

    class TextField : public CTraits
    {
    public:
        typedef Instances::fl_text::TextField InstanceType;

        TextField(VM& vm, const ClassInfo& ci);
        // @0x1424ac5d0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TextField"; }
        // @0x1424ad6e0
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(new(t.Alloc()) InstanceType(t));
        }
    };

    class TextFormat : public CTraits
    {
    public:
        typedef Instances::fl_text::TextFormat InstanceType;

        TextFormat(VM& vm, const ClassInfo& ci);
        // @0x1424ac640
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TextFormat"; }
        // @0x1424ad740
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(new(t.Alloc()) InstanceType(t));
        }
    };

    class TextSnapshot : public CTraits
    {
    public:
        typedef Instances::fl_text::TextSnapshot InstanceType;

        TextSnapshot(VM& vm, const ClassInfo& ci);
        // @0x1424ac6e0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::TextSnapshot"; }
        // @0x1424ad800
        virtual void MakeObject(Value& result, Traits& t)
        {
            result.Pick(new(t.Alloc()) InstanceType(t));
        }
    };
}}

namespace ClassTraits { namespace fl_text {
    class CSMSettings : public Traits
    {
    public:
        CSMSettings(VM& vm);
        // @0x1424ac450
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::CSMSettings"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Font : public Traits
    {
    public:
        Font(VM& vm);
        // @0x1424ac480
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Font"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextLineMetrics : public Traits
    {
    public:
        TextLineMetrics(VM& vm);
        // @0x1424ac680
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextLineMetrics"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class AntiAliasType : public Traits
    {
    public:
        AntiAliasType(VM& vm);
        // @0x1424ac430
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::AntiAliasType"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class FontStyle : public Traits
    {
    public:
        FontStyle(VM& vm);
        // @0x1424ac4c0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FontStyle"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class FontType : public Traits
    {
    public:
        FontType(VM& vm);
        // @0x1424ac4e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FontType"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class GridFitType : public Traits
    {
    public:
        GridFitType(VM& vm);
        // @0x1424ac500
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::GridFitType"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextColorType : public Traits
    {
    public:
        TextColorType(VM& vm);
        // @0x1424ac580
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextColorType"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextDisplayMode : public Traits
    {
    public:
        TextDisplayMode(VM& vm);
        // @0x1424ac5a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextDisplayMode"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextFieldAutoSize : public Traits
    {
    public:
        TextFieldAutoSize(VM& vm);
        // @0x1424ac5f0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextFieldAutoSize"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextFieldType : public Traits
    {
    public:
        TextFieldType(VM& vm);
        // @0x1424ac610
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextFieldType"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextFormatAlign : public Traits
    {
    public:
        TextFormatAlign(VM& vm);
        // @0x1424ac660
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextFormatAlign"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextRenderer : public Traits
    {
    public:
        TextRenderer(VM& vm);
        // @0x1424ac6b0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextRenderer"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StaticText : public Traits
    {
    public:
        StaticText(VM& vm);
        // @0x1424ac520
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StaticText"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StyleSheet : public Traits
    {
    public:
        StyleSheet(VM& vm);
        // @0x1424ac550
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StyleSheet"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextField : public Traits
    {
    public:
        TextField(VM& vm);
        // @0x1424ac5c0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextField"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextFormat : public Traits
    {
    public:
        TextFormat(VM& vm);
        // @0x1424ac630
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextFormat"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TextSnapshot : public Traits
    {
    public:
        TextSnapshot(VM& vm);
        // @0x1424ac6d0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TextSnapshot"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };
}}

}}} // namespace Scaleform::GFx::AS3

#endif
