// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_GFX_H
#define MS2_SF_GFX_AS3_OBJ_GFX_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_gfx {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class GamePadAnalogEvent : public Instances::fl_events::Event
    {
    public:
        // @0x1424c9d30
        void clone(SPtr<Instances::fl_events::Event>& result);
        // @0x1424c9dc0
        void codeGet(UInt32& result);
        // @0x1424c9dd0
        void codeSet(const Value& result, UInt32);
        // @0x1424c9de0
        void controllerIdxGet(UInt32& result);
        // @0x1424c9df0
        void controllerIdxSet(const Value& result, UInt32);
        // @0x1424cc0f0
        void toString(ASString& result);
        // @0x1424cca00
        void xvalueGet(Value::Number& result);
        // @0x1424cca10
        void xvalueSet(const Value& result, Value::Number);
        // @0x1424cca20
        void yvalueGet(Value::Number& result);
        // @0x1424cca30
        void yvalueSet(const Value& result, Value::Number);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class IMECandidateListStyle : public Instances::fl::Object
    {
    };

}}

namespace Classes { namespace fl_gfx {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Extensions : public Class
    {
    public:
        // @0x1424c9ef0
        void enabledGet(bool& result);
        // @0x1424c9f10
        void enabledSet(const Value& result, bool);
        // @0x1424ca900
        void getEdgeAAMode(UInt32& result, Instances::fl_display::DisplayObject*);
        // @0x1424cadf0
        void getMouseCursorType(ASString& result, UInt32);
        // @0x1424cae10
        void getMouseTopMostEntity(SPtr<Instances::fl_display::DisplayObject>& result, bool, UInt32);
        // @0x1424cb000
        void getTopMostEntity(SPtr<Instances::fl_display::DisplayObject>& result, Value::Number, Value::Number, bool);
        // @0x1424cb2b0
        void isScaleformGet(bool& result);
        // @0x1424cb610
        void noInvisibleAdvanceGet(bool& result);
        // @0x1424cb640
        void noInvisibleAdvanceSet(const Value& result, bool);
        // @0x1424cb680
        void numControllersGet(UInt32& result);
        // @0x1424cb7c0
        void setEdgeAAMode(const Value& result, Instances::fl_display::DisplayObject*, UInt32);
        // @0x1424cbd90
        void setMouseCursorType(const Value& result, const ASString&, UInt32);
        // @0x1424cc860
        void visibleRectGet(SPtr<Instances::fl_geom::Rectangle>& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class FocusManager : public Class
    {
    public:
        // @0x1424c9b20
        void alwaysEnableArrowKeysGet(bool& result);
        // @0x1424c9b70
        void alwaysEnableArrowKeysSet(const Value& result, bool);
        // @0x1424c9e60
        void disableFocusKeysGet(bool& result);
        // @0x1424c9eb0
        void disableFocusKeysSet(const Value& result, bool);
        // @0x1424c9f20
        void findFocus(SPtr<Instances::fl_display::InteractiveObject>& result, const ASString&, Instances::fl_display::DisplayObjectContainer*, bool, Instances::fl_display::InteractiveObject*, bool, UInt32);
        // @0x1424ca860
        void getControllerFocusGroup(UInt32& result, UInt32);
        // @0x1424ca8b0
        void getControllerMaskByFocusGroup(UInt32& result, UInt32);
        // @0x1424ca9b0
        void getFocus(SPtr<Instances::fl_display::InteractiveObject>& result, UInt32);
        // @0x1424cab30
        void getFocusGroupMask(UInt32& result, Instances::fl_display::InteractiveObject*);
        // @0x1424cad40
        void getModalClip(SPtr<Instances::fl_display::Sprite>& result, UInt32);
        // @0x1424cb2c0
        void moveFocus(SPtr<Instances::fl_display::InteractiveObject>& result, const ASString&, Instances::fl_display::InteractiveObject*, bool, UInt32);
        // @0x1424cb6c0
        void numFocusGroupsGet(UInt32& result);
        // @0x1424cb770
        void setControllerFocusGroup(bool& result, UInt32, UInt32);
        // @0x1424cb810
        void setFocus(const Value& result, Instances::fl_display::InteractiveObject*, UInt32);
        // @0x1424cb910
        void setFocusGroupMask(const Value& result, Instances::fl_display::InteractiveObject*, UInt32);
        // @0x1424cbd50
        void setModalClip(const Value& result, Instances::fl_display::Sprite*, UInt32);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class GamePad : public Class
    {
    public:
        // @0x1424cc0e0
        void supportsAnalogEvents(bool& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class IMEEx : public Class
    {
    public:
        // @0x1424c8fb0
        void GetCompositionString(ASString& result);
        // @0x1424c9120
        void GetOSVersion(ASString& result);
        // @0x1424c9a20
        void SendLangBarMessage(const Value& result, Instances::fl_display::Sprite*, const ASString&, const ASString&);
        // @0x1424cab90
        void getIMECandidateListStyle(SPtr<Instances::fl_gfx::IMECandidateListStyle>& result);
        // @0x1424cb980
        void setIMECandidateListStyle(const Value& result, Instances::fl_gfx::IMECandidateListStyle*);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class InteractiveObjectEx : public Class
    {
    public:
        // @0x1424cab60
        void getHitTestDisable(bool& result, Instances::fl_display::InteractiveObject*);
        // @0x1424cb1a0
        void getTopmostLevel(bool& result, Instances::fl_display::InteractiveObject*);
        // @0x1424cb940
        void setHitTestDisable(const Value& result, Instances::fl_display::InteractiveObject*, bool);
        // @0x1424cbef0
        void setTopmostLevel(const Value& result, Instances::fl_display::InteractiveObject*, bool);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class SystemEx : public Class
    {
    public:
        // @0x1424c9aa0
        void actionVerboseGet(bool& result);
        // @0x1424c9ad0
        void actionVerboseSet(const Value& result, bool);
        // @0x1424c9e00
        void describeType(ASString& result, const Value&);
        // @0x1424ca6a0
        void getCodeFileName(ASString& result);
        // @0x1424ca6b0
        void getCodeFileNames(SPtr<Instances::fl::Array>& result);
        // @0x1424caf20
        void getStackTrace(ASString& result);
        // @0x1424cb6e0
        void printObjectsReport(const Value& result, bool, UInt32, const ASString&);
        // @0x1424cb740
        void setBackgroundAlpha(const Value& result, Value::Number);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class TextFieldEx : public Class
    {
    public:
        // @0x1424c9bb0
        void appendHtml(const Value& result, Instances::fl_text::TextField*, const ASString&);
        // @0x1424caf40
        void getTextAutoSize(ASString& result, Instances::fl_text::TextField*);
        // @0x1424cb1d0
        void getVerticalAlign(ASString& result, Instances::fl_text::TextField*);
        // @0x1424cbab0
        void setIMEEnabled(const Value& result, Instances::fl_text::TextField*, bool);
        // @0x1424cbb40
        void setImageSubstitutions(const Value& result, Instances::fl_text::TextField*, const Value&);
        // @0x1424cbdb0
        void setTextAutoSize(const Value& result, Instances::fl_text::TextField*, const ASString&);
        // @0x1424cbf60
        void setVerticalAlign(const Value& result, Instances::fl_text::TextField*, const ASString&);
        // @0x1424cc450
        void updateImageSubstitution(const Value& result, Instances::fl_text::TextField*, const ASString&, Instances::fl_display::BitmapData*);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
