// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_FILTERS_H
#define MS2_SF_GFX_AS3_OBJ_FILTERS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_filters {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class BitmapFilter : public Instances::fl::Object
    {
    public:
        // @0x14247b400
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class BevelFilter : public Instances::fl_filters::BitmapFilter
    {
    public:
        // @0x14247ab00
        void angleGet(Value::Number& result);
        // @0x14247ab70
        void angleSet(const Value& result, Value::Number);
        // @0x14247aca0
        void blurXGet(Value::Number& result);
        // @0x14247ad30
        void blurXSet(const Value& result, Value::Number);
        // @0x14247adc0
        void blurYGet(Value::Number& result);
        // @0x14247ae50
        void blurYSet(const Value& result, Value::Number);
        // @0x14247af00
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        // @0x14247bb30
        void distanceGet(Value::Number& result);
        // @0x14247bb80
        void distanceSet(const Value& result, Value::Number);
        // @0x14247bcc0
        void highlightAlphaGet(Value::Number& result);
        // @0x14247bcf0
        void highlightAlphaSet(const Value& result, Value::Number);
        // @0x14247bd20
        void highlightColorGet(UInt32& result);
        // @0x14247bd50
        void highlightColorSet(const Value& result, UInt32);
        // @0x14247bdc0
        void knockoutGet(bool& result);
        // @0x14247be10
        void knockoutSet(const Value& result, bool);
        // @0x14247c0e0
        void qualityGet(SInt32& result);
        // @0x14247c130
        void qualitySet(const Value& result, SInt32);
        // @0x14247c180
        void shadowAlphaGet(Value::Number& result);
        // @0x14247c1b0
        void shadowAlphaSet(const Value& result, Value::Number);
        // @0x14247c1e0
        void shadowColorGet(UInt32& result);
        // @0x14247c210
        void shadowColorSet(const Value& result, UInt32);
        // @0x14247c240
        void strengthGet(Value::Number& result);
        // @0x14247c2b0
        void strengthSet(const Value& result, Value::Number);
        // @0x14247c320
        void typeGet(ASString& result);
        // @0x14247c360
        void typeSet(const Value& result, const ASString&);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class BlurFilter : public Instances::fl_filters::BitmapFilter
    {
    public:
        // @0x14247acd0
        void blurXGet(Value::Number& result);
        // @0x14247ad60
        void blurXSet(const Value& result, Value::Number);
        // @0x14247adf0
        void blurYGet(Value::Number& result);
        // @0x14247ae80
        void blurYSet(const Value& result, Value::Number);
        // @0x14247b440
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        // @0x14247c100
        void qualityGet(SInt32& result);
        // @0x14247c150
        void qualitySet(const Value& result, SInt32);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class ColorMatrixFilter : public Instances::fl_filters::BitmapFilter
    {
    public:
        // @0x14247b550
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        // @0x14247be80
        void matrixGet(SPtr<Instances::fl::Array>& result);
        // @0x14247c020
        void matrixSet(const Value& result, Instances::fl::Array*);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class DropShadowFilter : public Instances::fl_filters::BitmapFilter
    {
    public:
        // @0x14247aa80
        void alphaGet(Value::Number& result);
        // @0x14247aac0
        void alphaSet(const Value& result, Value::Number);
        // @0x14247ab40
        void angleGet(Value::Number& result);
        // @0x14247ac10
        void angleSet(const Value& result, Value::Number);
        // @0x14247acf0
        void blurXGet(Value::Number& result);
        // @0x14247ad80
        void blurXSet(const Value& result, Value::Number);
        // @0x14247ae10
        void blurYGet(Value::Number& result);
        // @0x14247aea0
        void blurYSet(const Value& result, Value::Number);
        // @0x14247b6c0
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        // @0x14247baf0
        void colorGet(UInt32& result);
        // @0x14247bb10
        void colorSet(const Value& result, UInt32);
        // @0x14247bb60
        void distanceGet(Value::Number& result);
        // @0x14247bc20
        void distanceSet(const Value& result, Value::Number);
        // @0x14247bca0
        void hideObjectGet(bool& result);
        // @0x14247bcb0
        void hideObjectSet(const Value& result, bool);
        // @0x14247bd80
        void innerGet(bool& result);
        // @0x14247bda0
        void innerSet(const Value& result, bool);
        // @0x14247bdf0
        void knockoutGet(bool& result);
        // @0x14247be40
        void knockoutSet(const Value& result, bool);
        // @0x14247c110
        void qualityGet(SInt32& result);
        // @0x14247c160
        void qualitySet(const Value& result, SInt32);
        // @0x14247c270
        void strengthGet(Value::Number& result);
        // @0x14247c2e0
        void strengthSet(const Value& result, Value::Number);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class GlowFilter : public Instances::fl_filters::BitmapFilter
    {
    public:
        // @0x14247aaa0
        void alphaGet(Value::Number& result);
        // @0x14247aae0
        void alphaSet(const Value& result, Value::Number);
        // @0x14247ad10
        void blurXGet(Value::Number& result);
        // @0x14247ada0
        void blurXSet(const Value& result, Value::Number);
        // @0x14247ae30
        void blurYGet(Value::Number& result);
        // @0x14247aec0
        void blurYSet(const Value& result, Value::Number);
        // @0x14247b980
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        // @0x14247bb00
        void colorGet(UInt32& result);
        // @0x14247bb20
        void colorSet(const Value& result, UInt32);
        // @0x14247bd90
        void innerGet(bool& result);
        // @0x14247bdb0
        void innerSet(const Value& result, bool);
        // @0x14247be00
        void knockoutGet(bool& result);
        // @0x14247be50
        void knockoutSet(const Value& result, bool);
        // @0x14247c120
        void qualityGet(SInt32& result);
        // @0x14247c170
        void qualitySet(const Value& result, SInt32);
        // @0x14247c290
        void strengthGet(Value::Number& result);
        // @0x14247c300
        void strengthSet(const Value& result, Value::Number);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
