// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_UI_H
#define MS2_SF_GFX_AS3_OBJ_UI_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_ui {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ContextMenu : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x1424b9120
        void builtInItemsGet(SPtr<Instances::fl_ui::ContextMenuBuiltInItems>& result);
        // @0x1424b9190
        void builtInItemsSet(const Value& result, Instances::fl_ui::ContextMenuBuiltInItems*);
        // @0x1424b91f0
        void clone(SPtr<Instances::fl_display::NativeMenu>& result);
        // @0x1424b9270
        void customItemsGet(SPtr<Instances::fl::Array>& result);
        // @0x1424b9300
        void customItemsSet(const Value& result, Instances::fl::Array*);
        // @0x1424b93e0
        void hideBuiltInItems(const Value& result);
    };

}}

namespace Classes { namespace fl_ui {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Keyboard : public Class
    {
    public:
        // @0x1424b91b0
        void capsLockGet(bool& result);
        // @0x1424b9570
        void isAccessible(bool& result);
        // @0x1424b95b0
        void numLockGet(bool& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Mouse : public Class
    {
    public:
        // @0x1424b9210
        void cursorGet(ASString& result);
        // @0x1424b9230
        void cursorSet(const Value& result, const ASString&);
        // @0x1424b9320
        void hide(const Value& result);
        // @0x1424b95f0
        void show(const Value& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Multitouch : public Class
    {
    public:
        // @0x1424b9400
        void inputModeGet(ASString& result);
        // @0x1424b94c0
        void inputModeSet(const Value& result, const ASString&);
        // @0x1424b9580
        void maxTouchPointsGet(SInt32& result);
        // @0x1424b96b0
        void supportedGesturesGet(SPtr<Instances::fl_vec::Vector_String>& result);
        // @0x1424b97d0
        void supportsGestureEventsGet(bool& result);
        // @0x1424b9800
        void supportsTouchEventsGet(bool& result);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
