// Recovered Scaleform GFx 4.1.18 AS3 native classes, flash.filters package. First generated from the exe's ClassInfo
// tables and thunk member pointers (work/sfr5/gen_natives.py), then completed by hand from the exe (sfr_as3_10): the
// instance layouts, the instance traits, class objects and class traits. Do not regenerate. Our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_FILTERS_H
#define MS2_SF_GFX_AS3_OBJ_FILTERS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/render/render_filters.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace InstanceTraits { namespace fl_filters
{
    class BitmapFilter;
    class BevelFilter;
    class BlurFilter;
    class ColorMatrixFilter;
    class DropShadowFilter;
    class GlowFilter;
}}

// ==== instances ======================================================================================================

namespace Instances { namespace fl_filters {
    // 0x40 bytes. Holds the render filter the display list uses.
    class BitmapFilter : public Instances::fl::Object
    {
        friend class InstanceTraits::fl_filters::BitmapFilter;
    public:
        BitmapFilter(InstanceTraits::Traits& t);
        // @0x14247a060
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_filters::BitmapFilter"; }

        Render::Filter* GetFilterData() const { return FilterData; }

        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        SPtr<Instances::fl_filters::BitmapFilter> clone()
        {
            SPtr<Instances::fl_filters::BitmapFilter> result;
            clone(result);
            return result;
        }

    protected:
        Ptr<Render::Filter> FilterData;     // +0x38
    };

    // Render::BevelFilter; the accessors go through the virtual GetBevelFilterData (slot 21).
    class BevelFilter : public Instances::fl_filters::BitmapFilter
    {
        friend class InstanceTraits::fl_filters::BevelFilter;
    public:
        BevelFilter(InstanceTraits::Traits& t);
        // @0x14247a030
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_filters::BevelFilter"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        // @0x14247a1d0
        virtual Render::BevelFilter* GetBevelFilterData() const { return (Render::BevelFilter*)GetFilterData(); }

        void angleGet(Value::Number& result);
        void angleSet(const Value& result, Value::Number value);
        void blurXGet(Value::Number& result);
        void blurXSet(const Value& result, Value::Number value);
        void blurYGet(Value::Number& result);
        void blurYSet(const Value& result, Value::Number value);
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        void distanceGet(Value::Number& result);
        void distanceSet(const Value& result, Value::Number value);
        void highlightAlphaGet(Value::Number& result);
        void highlightAlphaSet(const Value& result, Value::Number value);
        void highlightColorGet(UInt32& result);
        void highlightColorSet(const Value& result, UInt32 value);
        void knockoutGet(bool& result);
        void knockoutSet(const Value& result, bool value);
        void qualityGet(SInt32& result);
        void qualitySet(const Value& result, SInt32 value);
        void shadowAlphaGet(Value::Number& result);
        void shadowAlphaSet(const Value& result, Value::Number value);
        void shadowColorGet(UInt32& result);
        void shadowColorSet(const Value& result, UInt32 value);
        void strengthGet(Value::Number& result);
        void strengthSet(const Value& result, Value::Number value);
        void typeGet(ASString& result);
        void typeSet(const Value& result, const ASString& value);

        SPtr<Instances::fl_filters::BitmapFilter> clone();
    };

    // Render::BlurFilter.
    class BlurFilter : public Instances::fl_filters::BitmapFilter
    {
        friend class InstanceTraits::fl_filters::BlurFilter;
    public:
        BlurFilter(InstanceTraits::Traits& t);
        // @0x14247a0d0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_filters::BlurFilter"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        Render::BlurFilter* GetBlurFilterData() const { return (Render::BlurFilter*)GetFilterData(); }

        void blurXGet(Value::Number& result);
        void blurXSet(const Value& result, Value::Number value);
        void blurYGet(Value::Number& result);
        void blurYSet(const Value& result, Value::Number value);
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        void qualityGet(SInt32& result);
        void qualitySet(const Value& result, SInt32 value);

        SPtr<Instances::fl_filters::BitmapFilter> clone();
    };

    // Render::ColorMatrixFilter.
    class ColorMatrixFilter : public Instances::fl_filters::BitmapFilter
    {
        friend class InstanceTraits::fl_filters::ColorMatrixFilter;
    public:
        ColorMatrixFilter(InstanceTraits::Traits& t);
        // @0x14247a100
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_filters::ColorMatrixFilter"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        Render::ColorMatrixFilter* GetColorMatrixFilterData() const { return (Render::ColorMatrixFilter*)GetFilterData(); }

        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        void matrixGet(SPtr<Instances::fl::Array>& result);
        void matrixSet(const Value& result, Instances::fl::Array* value);

        SPtr<Instances::fl_filters::BitmapFilter> clone();
        SPtr<Instances::fl::Array> matrixGet();
    };

    // Render::ShadowFilter.
    class DropShadowFilter : public Instances::fl_filters::BitmapFilter
    {
        friend class InstanceTraits::fl_filters::DropShadowFilter;
    public:
        DropShadowFilter(InstanceTraits::Traits& t);
        // @0x14247a170
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_filters::DropShadowFilter"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        Render::ShadowFilter* GetShadowFilterData() const { return (Render::ShadowFilter*)GetFilterData(); }

        void alphaGet(Value::Number& result);
        void alphaSet(const Value& result, Value::Number value);
        void angleGet(Value::Number& result);
        void angleSet(const Value& result, Value::Number value);
        void blurXGet(Value::Number& result);
        void blurXSet(const Value& result, Value::Number value);
        void blurYGet(Value::Number& result);
        void blurYSet(const Value& result, Value::Number value);
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        void colorGet(UInt32& result);
        void colorSet(const Value& result, UInt32 value);
        void distanceGet(Value::Number& result);
        void distanceSet(const Value& result, Value::Number value);
        void hideObjectGet(bool& result);
        void hideObjectSet(const Value& result, bool value);
        void innerGet(bool& result);
        void innerSet(const Value& result, bool value);
        void knockoutGet(bool& result);
        void knockoutSet(const Value& result, bool value);
        void qualityGet(SInt32& result);
        void qualitySet(const Value& result, SInt32 value);
        void strengthGet(Value::Number& result);
        void strengthSet(const Value& result, Value::Number value);

        SPtr<Instances::fl_filters::BitmapFilter> clone();
    };

    // Render::GlowFilter.
    class GlowFilter : public Instances::fl_filters::BitmapFilter
    {
        friend class InstanceTraits::fl_filters::GlowFilter;
    public:
        GlowFilter(InstanceTraits::Traits& t);
        // @0x14247a1a0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_filters::GlowFilter"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        Render::GlowFilter* GetGlowFilterData() const { return (Render::GlowFilter*)GetFilterData(); }

        void alphaGet(Value::Number& result);
        void alphaSet(const Value& result, Value::Number value);
        void blurXGet(Value::Number& result);
        void blurXSet(const Value& result, Value::Number value);
        void blurYGet(Value::Number& result);
        void blurYSet(const Value& result, Value::Number value);
        void clone(SPtr<Instances::fl_filters::BitmapFilter>& result);
        void colorGet(UInt32& result);
        void colorSet(const Value& result, UInt32 value);
        void innerGet(bool& result);
        void innerSet(const Value& result, bool value);
        void knockoutGet(bool& result);
        void knockoutSet(const Value& result, bool value);
        void qualityGet(SInt32& result);
        void qualitySet(const Value& result, SInt32 value);
        void strengthGet(Value::Number& result);
        void strengthSet(const Value& result, Value::Number value);

        SPtr<Instances::fl_filters::BitmapFilter> clone();
    };
}}

// ==== instance traits ================================================================================================

#define MS2_SF_FILTER_ITRAITS(Name)                                                                                     \
    class Name : public CTraits                                                                                         \
    {                                                                                                                   \
    public:                                                                                                             \
        typedef Instances::fl_filters::Name InstanceType;                                                               \
                                                                                                                        \
        Name(VM& vm, const ClassInfo& ci);                                                                              \
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::" #Name; }                              \
        virtual void MakeObject(Value& result, Traits& t);                                                              \
                                                                                                                        \
        Pickable<InstanceType> MakeInstance(Name& t);                                                                   \
    };

namespace InstanceTraits { namespace fl_filters
{
    // One line per class: the tag is the GetAS3ObjectType of the macro.
    // @0x14247a050
    MS2_SF_FILTER_ITRAITS(BitmapFilter)
    // @0x14247a020
    MS2_SF_FILTER_ITRAITS(BevelFilter)
    // @0x14247a0c0
    MS2_SF_FILTER_ITRAITS(BlurFilter)
    // @0x14247a0f0
    MS2_SF_FILTER_ITRAITS(ColorMatrixFilter)
    // @0x14247a160
    MS2_SF_FILTER_ITRAITS(DropShadowFilter)
    // @0x14247a190
    MS2_SF_FILTER_ITRAITS(GlowFilter)
}}

#undef MS2_SF_FILTER_ITRAITS

// ==== classes ========================================================================================================

namespace Classes { namespace fl_filters
{
    // 0x60 bytes.
    class BitmapFilterQuality : public Class
    {
    public:
        BitmapFilterQuality(ClassTraits::Traits& t);
        // @0x14247a080
        virtual const char* GetAS3ObjectType() const { return "Classes::BitmapFilterQuality"; }

        const SInt32 HIGH;      // +0x50
        const SInt32 LOW;       // +0x54
        const SInt32 MEDIUM;    // +0x58
    };

    // 0x68 bytes.
    class BitmapFilterType : public Class
    {
    public:
        BitmapFilterType(ClassTraits::Traits& t);
        // @0x14247a0a0
        virtual const char* GetAS3ObjectType() const { return "Classes::BitmapFilterType"; }

        const char* FULL;       // +0x50
        const char* INNER;      // +0x58
        const char* OUTER;      // +0x60
    };

    // 0x70 bytes.
    class DisplacementMapFilterMode : public Class
    {
    public:
        DisplacementMapFilterMode(ClassTraits::Traits& t);
        // @0x14247a140
        virtual const char* GetAS3ObjectType() const { return "Classes::DisplacementMapFilterMode"; }

        const char* CLAMP;      // +0x50
        const char* COLOR;      // +0x58
        const char* IGNORE_;    // +0x60 (IGNORE is a Windows macro)
        const char* WRAP;       // +0x68
    };
}}

// ==== class traits ===================================================================================================

#define MS2_SF_FILTER_CTRAITS(Name)                                                                                     \
    class Name : public Traits                                                                                          \
    {                                                                                                                   \
    public:                                                                                                             \
        Name(VM& vm);                                                                                                   \
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::" #Name; }                                 \
        static Pickable<Traits> MakeClassTraits(VM& vm);                                                                \
    };

namespace ClassTraits { namespace fl_filters
{
    // One line per class: the tag is the GetAS3ObjectType of the macro.
    // @0x14247a010
    MS2_SF_FILTER_CTRAITS(BevelFilter)
    // @0x14247a040
    MS2_SF_FILTER_CTRAITS(BitmapFilter)
    // @0x14247a070
    MS2_SF_FILTER_CTRAITS(BitmapFilterQuality)
    // @0x14247a090
    MS2_SF_FILTER_CTRAITS(BitmapFilterType)
    // @0x14247a0b0
    MS2_SF_FILTER_CTRAITS(BlurFilter)
    // @0x14247a0e0
    MS2_SF_FILTER_CTRAITS(ColorMatrixFilter)
    // @0x14247a110
    MS2_SF_FILTER_CTRAITS(ConvolutionFilter)
    // @0x14247a120
    MS2_SF_FILTER_CTRAITS(DisplacementMapFilter)
    // @0x14247a130
    MS2_SF_FILTER_CTRAITS(DisplacementMapFilterMode)
    // @0x14247a150
    MS2_SF_FILTER_CTRAITS(DropShadowFilter)
    // @0x14247a180
    MS2_SF_FILTER_CTRAITS(GlowFilter)
    // @0x14247a1b0
    MS2_SF_FILTER_CTRAITS(GradientBevelFilter)
    // @0x14247a1c0
    MS2_SF_FILTER_CTRAITS(GradientGlowFilter)
}}

#undef MS2_SF_FILTER_CTRAITS

}}} // namespace Scaleform::GFx::AS3

#endif
