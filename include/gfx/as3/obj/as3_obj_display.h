// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_DISPLAY_H
#define MS2_SF_GFX_AS3_OBJ_DISPLAY_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"
#include "ms2/scaleform/include/gfx/gfx_moviedef.h"
#include "ms2/scaleform/include/gfx/gfx_drawingcontext.h"
#include "ms2/scaleform/include/gfx/gfx_imageresource.h"
#include "ms2/scaleform/include/gfx/gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// Hands a display object over to a running collection (DisplayObject::pReleaseProxy). Same layout as
// RefCountCollector<Stat>::PtrReleaseProxy, whose delayed-release chain it joins; Data2 is a counted pointer here.
template <int Stat>
class PtrReleaseProxy : public RefCountBase<PtrReleaseProxy<Stat>, Stat>
{
public:
    Ptr<RefCountNTSImpl>        Data;   // +0x10
    SPtr<ASRefCountBaseType>    Data2;  // +0x18
    Ptr<PtrReleaseProxy>        pNext;  // +0x20
};

namespace Instances { namespace fl_display {
    // 0x68 bytes; implements IBitmapDrawable.
    class DisplayObject : public Instances::fl_events::EventDispatcher
    {
    public:
        typedef AS3::PtrReleaseProxy<StatMV_VM> ReleaseProxy;

        DisplayObject(InstanceTraits::Traits& t);
        virtual ~DisplayObject();
        // @0x142443510
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::DisplayObject"; }
        virtual GFx::DisplayObject* CreateStageObject();
        virtual String GetAS3ObjectName() const;
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    public:
        SPtr<Instances::fl_display::LoaderInfo> pLoaderInfo;    // +0x50
        Ptr<GFx::DisplayObject>                 pDispObj;       // +0x58: the display object this instance scripts
        Ptr<ReleaseProxy>                       pReleaseProxy;  // +0x60: hands pDispObj to the collector when dying in a collection

        // @0x142447480
        void accessibilityPropertiesGet(SPtr<Instances::fl_accessibility::AccessibilityProperties>& result);
        SPtr<Instances::fl_accessibility::AccessibilityProperties> accessibilityPropertiesGet();
        // @0x1424474a0
        void accessibilityPropertiesSet(const Value& result, Instances::fl_accessibility::AccessibilityProperties*);
        // @0x142447de0
        void alphaGet(Value::Number& result);
        // @0x142447e10
        void alphaSet(const Value& result, Value::Number);
        // @0x1424485e0
        void blendModeGet(ASString& result);
        // @0x142448790
        void blendModeSet(const Value& result, const ASString&);
        // @0x142448930
        void cacheAsBitmapGet(bool& result);
        // @0x142448950
        void cacheAsBitmapSet(const Value& result, bool);
        // @0x14244bb80
        void filtersGet(SPtr<Instances::fl::Array>& result);
        SPtr<Instances::fl::Array> filtersGet();
        // @0x14244bdd0
        void filtersSet(const Value& result, Instances::fl::Array*);
        // @0x14244c910
        void getBounds(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_display::DisplayObject*);
        SPtr<Instances::fl_geom::Rectangle> getBounds(Instances::fl_display::DisplayObject* a0);
        // @0x14244d760
        void getRect(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_display::DisplayObject*);
        SPtr<Instances::fl_geom::Rectangle> getRect(Instances::fl_display::DisplayObject* a0);
        // @0x14244df40
        void globalToLocal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*);
        SPtr<Instances::fl_geom::Point> globalToLocal(Instances::fl_geom::Point* a0);
        // @0x14244dd20
        void globalToLocal3D(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Point*);
        SPtr<Instances::fl_geom::Vector3D> globalToLocal3D(Instances::fl_geom::Point* a0);
        // @0x14244e520
        void heightGet(Value::Number& result);
        // @0x14244e630
        void heightSet(const Value& result, Value::Number);
        // @0x14244ef60
        void hitTestObject(bool& result, Instances::fl_display::DisplayObject*);
        // @0x14244f0f0
        void hitTestPoint(bool& result, Value::Number, Value::Number, bool);
        // @0x14244ffb0
        void loaderInfoGet(SPtr<Instances::fl_display::LoaderInfo>& result);
        SPtr<Instances::fl_display::LoaderInfo> loaderInfoGet();
        // @0x1424500e0
        void local3DToGlobal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Vector3D*);
        SPtr<Instances::fl_geom::Point> local3DToGlobal(Instances::fl_geom::Vector3D* a0);
        // @0x1424502c0
        void localToGlobal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*);
        SPtr<Instances::fl_geom::Point> localToGlobal(Instances::fl_geom::Point* a0);
        // @0x1424504a0
        void maskGet(SPtr<Instances::fl_display::DisplayObject>& result);
        // @0x142450540
        void maskSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x142450880
        void mouseXGet(Value::Number& result);
        // @0x1424508a0
        void mouseYGet(Value::Number& result);
        // @0x142450940
        void nameGet(ASString& result);
        // @0x142450ab0
        void nameSet(const Value& result, const ASString&);
        // @0x142450da0
        void opaqueBackgroundGet(SPtr<Instances::fl::Object>& result);
        // @0x142450dc0
        void opaqueBackgroundSet(const Value& result, const Value&);
        // @0x142451260
        void parentGet(SPtr<Instances::fl_display::DisplayObjectContainer>& result);
        SPtr<Instances::fl_display::DisplayObjectContainer> parentGet();
        // @0x142452090
        void rootGet(SPtr<Instances::fl_display::DisplayObject>& result);
        // @0x142452150
        void rotationGet(Value::Number& result);
        // @0x142452170
        void rotationSet(const Value& result, Value::Number);
        // @0x142452190
        void rotationXGet(Value::Number& result);
        // @0x1424521b0
        void rotationXSet(const Value& result, Value::Number);
        // @0x1424521d0
        void rotationYGet(Value::Number& result);
        // @0x1424521f0
        void rotationYSet(const Value& result, Value::Number);
        // @0x142452210
        void rotationZGet(Value::Number& result);
        // @0x142452230
        void rotationZSet(const Value& result, Value::Number);
        // @0x142452290
        void scale9GridGet(SPtr<Instances::fl_geom::Rectangle>& result);
        SPtr<Instances::fl_geom::Rectangle> scale9GridGet();
        // @0x142452450
        void scale9GridSet(const Value& result, Instances::fl_geom::Rectangle*);
        // @0x142452660
        void scaleXGet(Value::Number& result);
        // @0x142452690
        void scaleXSet(const Value& result, Value::Number);
        // @0x1424526b0
        void scaleYGet(Value::Number& result);
        // @0x1424526e0
        void scaleYSet(const Value& result, Value::Number);
        // @0x142452700
        void scaleZGet(Value::Number& result);
        // @0x142452730
        void scaleZSet(const Value& result, Value::Number);
        // @0x142452a80
        void scrollRectGet(SPtr<Instances::fl_geom::Rectangle>& result);
        SPtr<Instances::fl_geom::Rectangle> scrollRectGet();
        // @0x142452c90
        void scrollRectSet(const Value& result, Instances::fl_geom::Rectangle*);
        // @0x142453490
        void stageGet(SPtr<Instances::fl_display::Stage>& result);
        SPtr<Instances::fl_display::Stage> stageGet();
        // @0x1424543a0
        void transformGet(SPtr<Instances::fl_geom::Transform>& result);
        SPtr<Instances::fl_geom::Transform> transformGet();
        // @0x142454470
        void transformSet(const Value& result, Instances::fl_geom::Transform*);
        // @0x142454920
        void visibleGet(bool& result);
        // @0x142454940
        void visibleSet(const Value& result, bool);
        // @0x142454a00
        void widthGet(Value::Number& result);
        // @0x142454b10
        void widthSet(const Value& result, Value::Number);
        // @0x142454b60
        void xGet(Value::Number& result);
        // @0x142454b80
        void xSet(const Value& result, Value::Number);
        // @0x142454ba0
        void yGet(Value::Number& result);
        // @0x142454bc0
        void ySet(const Value& result, Value::Number);
        // @0x142454be0
        void zGet(Value::Number& result);
        // @0x142454c10
        void zSet(const Value& result, Value::Number);

        // (appended, sfr24) whether pLoaderInfo is set.
        bool HasLoaderInfo() const;   // 0x1424445f0
        // (sfr_as2_01e) pLoaderInfo from the loader's content LoaderInfo, or set directly.
        void SetLoaderInfo(const Instances::fl_display::Loader& l);   // 0x142446e00
        void SetLoaderInfo(Instances::fl_display::LoaderInfo* li);    // 0x142446e70
    };

    // 0x68 bytes: no members of its own.
    class AVM1Movie : public Instances::fl_display::DisplayObject
    {
    public:
        AVM1Movie(InstanceTraits::Traits& t);
        AVM1Movie(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x142443400
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::AVM1Movie"; }
    };

    // 0x78 bytes.
    class Bitmap : public Instances::fl_display::DisplayObject
    {
    public:
        Bitmap(InstanceTraits::Traits& t);
        Bitmap(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x142443450
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::Bitmap"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        virtual void InitInstance(bool extCall);         // 0x142444600
        virtual GFx::DisplayObject* CreateStageObject();
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    public:
        SPtr<Instances::fl_display::BitmapData> pBitmapData;    // +0x68
        SInt32                                  PixelSnapping;  // +0x70
        bool                                    Smoothing;      // +0x74

        // The bitmap data's image resource, NULL without bitmap data (0x142443e40).
        ImageResource* GetImageResource() const;
        // (sfr_as2_01e) "never" / "always" / "auto" as 0 / 1 / 2; throws on anything else (0x142446f30).
        SInt32 String2PixelSnapping(const char* pname);

        // @0x1424484e0
        void bitmapDataGet(SPtr<Instances::fl_display::BitmapData>& result);
        // @0x142448550
        void bitmapDataSet(const Value& result, Instances::fl_display::BitmapData*);
        // @0x142451a00
        void pixelSnappingGet(ASString& result);
        // @0x142451a50
        void pixelSnappingSet(const Value& result, const ASString&);
        // @0x1424532f0
        void smoothingGet(bool& result);
        // @0x142453300
        void smoothingSet(const Value& result, bool);
    };

    // 0x60 bytes; implements IBitmapDrawable.
    class BitmapData : public Instances::fl::Object
    {
    public:
        BitmapData(InstanceTraits::Traits& t);
        BitmapData(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        virtual ~BitmapData();
        // @0x142443480
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::BitmapData"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        virtual void InitInstance(bool extCall);         // 0x142444610
        Ptr<ImageResource>      pImageResource; // +0x38
        Ptr<Render::ImageBase>  pImage;         // +0x40
        Ptr<MovieDefImpl>       pDefImpl;       // +0x48
        SInt32                  Width;          // +0x50
        SInt32                  Height;         // +0x54
        bool                    Transparent;    // +0x58
        bool                    Unk59;          // +0x59
        UInt32                  FillColor;      // +0x5c: not set by the constructor

        // The image resource of pImage, created on first use (0x142443e50).
        ImageResource* GetImageResource();

        // @0x142447f10
        void applyFilter(const Value& result, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, Instances::fl_filters::BitmapFilter*);
        // @0x142448a00
        void clone(SPtr<Instances::fl_display::BitmapData>& result);
        // @0x142448ba0
        void colorTransform(const Value& result, Instances::fl_geom::Rectangle*, Instances::fl_geom::ColorTransform*);
        // @0x142448d10
        void compare(Value& result, Instances::fl_display::BitmapData*);
        // @0x142449220
        void copyChannel(const Value& result, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, UInt32, UInt32);
        // @0x142449440
        void copyPixels(const Value& result, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, Instances::fl_display::BitmapData*, Instances::fl_geom::Point*, bool);
        // @0x142449cf0
        void dispose(const Value& result);
        // @0x142449eb0
        void draw(const Value& result, Instances::fl::Object*, Instances::fl_geom::Matrix*, Instances::fl_geom::ColorTransform*, const ASString&, Instances::fl_geom::Rectangle*, bool);
        // @0x14244ba30
        void fillRect(const Value& result, Instances::fl_geom::Rectangle*, UInt32);
        // @0x14244bfd0
        void floodFill(const Value& result, SInt32, SInt32, UInt32);
        // @0x14244c590
        void generateFilterRect(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_geom::Rectangle*, Instances::fl_filters::BitmapFilter*);
        SPtr<Instances::fl_geom::Rectangle> generateFilterRect(Instances::fl_geom::Rectangle* a0, Instances::fl_filters::BitmapFilter* a1);
        // @0x14244cfe0
        void getColorBoundsRect(SPtr<Instances::fl_geom::Rectangle>& result, UInt32, UInt32, bool);
        SPtr<Instances::fl_geom::Rectangle> getColorBoundsRect(UInt32 a0, UInt32 a1, bool a2);
        // @0x14244d4d0
        void getPixel(UInt32& result, SInt32, SInt32);
        // @0x14244d460
        void getPixel32(UInt32& result, SInt32, SInt32);
        // @0x14244d560
        void getPixels(SPtr<Instances::fl_utils::ByteArray>& result, Instances::fl_geom::Rectangle*);
        SPtr<Instances::fl_utils::ByteArray> getPixels(Instances::fl_geom::Rectangle* a0);
        // @0x14244daf0
        void getVector(SPtr<Instances::fl_vec::Vector_uint>& result, Instances::fl_geom::Rectangle*);
        SPtr<Instances::fl_vec::Vector_uint> getVector(Instances::fl_geom::Rectangle* a0);
        // @0x14244e480
        void heightGet(SInt32& result);
        // @0x14244e670
        void histogram(SPtr<Instances::fl::Object>& result, Instances::fl_geom::Rectangle*);
        // @0x14244ed10
        void hitTest(bool& result, Instances::fl_geom::Point*, UInt32, const Value&, Instances::fl_geom::Point*, UInt32);
        // @0x142450480
        void lock(const Value& result);
        // @0x142450590
        void merge(Value& result, unsigned, const Value*);
        // @0x142450cb0
        void noise(const Value& result, SInt32, UInt32, UInt32, UInt32, bool);
        // @0x142450f00
        void paletteMap(Value& result, unsigned, const Value*);
        // @0x142451340
        void perlinNoise(Value& result, unsigned, const Value*);
        // @0x142451770
        void pixelDissolve(SInt32& result, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, SInt32, SInt32, UInt32);
        // @0x142451c10
        void rectGet(SPtr<Instances::fl_geom::Rectangle>& result);
        SPtr<Instances::fl_geom::Rectangle> rectGet();
        // @0x1424529e0
        void scroll(const Value& result, SInt32, SInt32);
        // @0x142452e90
        void setPixel(const Value& result, SInt32, SInt32, UInt32);
        // @0x142452e10
        void setPixel32(const Value& result, SInt32, SInt32, UInt32);
        // @0x142452f10
        void setPixels(const Value& result, Instances::fl_geom::Rectangle*, Instances::fl_utils::ByteArray*);
        // @0x1424530a0
        void setVector(const Value& result, Instances::fl_geom::Rectangle*, Instances::fl_vec::Vector_uint*);
        // @0x142453eb0
        void threshold(Value& result, unsigned, const Value*);
        // @0x142454610
        void transparentGet(bool& result);
        // @0x1424546c0
        void unlock(const Value& result, Instances::fl_geom::Rectangle*);
        // @0x142454960
        void widthGet(SInt32& result);
    };

    // 0x70 bytes.
    class InteractiveObject : public Instances::fl_display::DisplayObject
    {
    public:
        InteractiveObject(InstanceTraits::Traits& t);
        InteractiveObject(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        virtual ~InteractiveObject();
        // @0x142443600
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::InteractiveObject"; }
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    public:
        SPtr<Instances::fl::Object> pContextMenu;   // +0x68

        // @0x1424490d0
        void contextMenuGet(SPtr<Instances::fl::Object>& result);
        // @0x142449140
        void contextMenuSet(const Value& result, const Value&);
        // @0x142449d20
        void doubleClickEnabledGet(bool& result);
        // @0x142449d80
        void doubleClickEnabledSet(const Value& result, bool);
        // @0x14244c1b0
        void focusRectGet(Value& result);
        // @0x14244c260
        void focusRectSet(const Value& result, const Value&);
        // @0x142450810
        void mouseEnabledGet(bool& result);
        // @0x142450840
        void mouseEnabledSet(const Value& result, bool);
        // @0x142453b50
        void tabEnabledGet(bool& result);
        // @0x142453b70
        void tabEnabledSet(const Value& result, bool);
        // @0x142453c30
        void tabIndexGet(SInt32& result);
        // @0x142453c40
        void tabIndexSet(const Value& result, SInt32);
    };

    // 0x70 bytes: no members of its own; the GC visitor also visits the AS3 objects of the children.
    class DisplayObjectContainer : public Instances::fl_display::InteractiveObject
    {
    public:
        DisplayObjectContainer(InstanceTraits::Traits& t);
        DisplayObjectContainer(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x142443540
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::DisplayObjectContainer"; }
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    public:
        // @0x1424474f0
        void addChild(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject*);
        SPtr<Instances::fl_display::DisplayObject> addChild(Instances::fl_display::DisplayObject* a0);
        // @0x142447660
        void addChildAt(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject*, SInt32);
        SPtr<Instances::fl_display::DisplayObject> addChildAt(Instances::fl_display::DisplayObject* a0, SInt32 a1);
        // @0x142448270
        void areInaccessibleObjectsUnderPoint(bool& result, Instances::fl_geom::Point*);
        // @0x142448eb0
        void contains(bool& result, Instances::fl_display::DisplayObject*);
        // @0x14244cca0
        void getChildAt(SPtr<Instances::fl_display::DisplayObject>& result, SInt32);
        SPtr<Instances::fl_display::DisplayObject> getChildAt(SInt32 a0);
        // @0x14244cde0
        void getChildByName(SPtr<Instances::fl_display::DisplayObject>& result, const ASString&);
        SPtr<Instances::fl_display::DisplayObject> getChildByName(const ASString& a0);
        // @0x14244cee0
        void getChildIndex(SInt32& result, Instances::fl_display::DisplayObject*);
        // @0x14244d1e0
        void getObjectsUnderPoint(SPtr<Instances::fl::Array>& result, Instances::fl_geom::Point*);
        SPtr<Instances::fl::Array> getObjectsUnderPoint(Instances::fl_geom::Point* a0);
        // @0x142450770
        void mouseChildrenGet(bool& result);
        // @0x1424507b0
        void mouseChildrenSet(const Value& result, bool);
        // @0x142450d40
        void numChildrenGet(SInt32& result);
        // @0x142451dc0
        void removeChild(Value& result, unsigned, const Value*);
        // @0x142451ef0
        void removeChildAt(SPtr<Instances::fl_display::DisplayObject>& result, SInt32);
        SPtr<Instances::fl_display::DisplayObject> removeChildAt(SInt32 a0);
        // @0x142452d20
        void setChildIndex(const Value& result, Instances::fl_display::DisplayObject*, SInt32);
        // @0x142453890
        void swapChildren(const Value& result, Instances::fl_display::DisplayObject*, Instances::fl_display::DisplayObject*);
        // @0x142453900
        void swapChildrenAt(const Value& result, SInt32, SInt32);
        // @0x142453a30
        void tabChildrenGet(bool& result);
        // @0x142453a70
        void tabChildrenSet(const Value& result, bool);
        // @0x142453d10
        void textSnapshotGet(SPtr<Instances::fl_text::TextSnapshot>& result);
        SPtr<Instances::fl_text::TextSnapshot> textSnapshotGet();
    };

    // 0x48 bytes.
    class FrameLabel : public Instances::fl::Object
    {
    public:
        FrameLabel(InstanceTraits::Traits& t);
        FrameLabel(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x142443570
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::FrameLabel"; }
        UInt32      FrameNumber;    // +0x38
        ASString    FrameName;      // +0x40

        // @0x14244c3a0
        void frameGet(SInt32& result);
        // @0x1424509c0
        void nameGet(ASString& result);
    };

    // 0x48 bytes.
    class Graphics : public Instances::fl::Object
    {
    public:
        Graphics(InstanceTraits::Traits& t);
        Graphics(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x1424435c0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::Graphics"; }
        Ptr<DrawingContext>     pDrawing;   // +0x38
        GFx::DisplayObject*     pDispObj;   // +0x40

        // @0x1424482e0
        void beginBitmapFill(const Value& result, Instances::fl_display::BitmapData*, Instances::fl_geom::Matrix*, bool, bool);
        // @0x142448400
        void beginFill(const Value& result, UInt32, Value::Number);
        // @0x142448460
        void beginGradientFill(Value& result, unsigned, const Value*);
        // @0x1424489d0
        void clear(const Value& result);
        // @0x142449b70
        void curveTo(const Value& result, Value::Number, Value::Number, Value::Number, Value::Number);
        // @0x14244a2e0
        void drawCircle(const Value& result, Value::Number, Value::Number, Value::Number);
        // @0x14244a5c0
        void drawEllipse(const Value& result, Value::Number, Value::Number, Value::Number, Value::Number);
        // @0x14244a900
        void drawRect(const Value& result, Value::Number, Value::Number, Value::Number, Value::Number);
        // @0x14244aae0
        void drawRoundRect(const Value& result, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number);
        // @0x14244b070
        void drawRoundRectComplex(Value& result, unsigned, const Value*);
        // @0x14244b9f0
        void endFill(const Value& result);
        // @0x14244f9a0
        void lineGradientStyle(Value& result, unsigned, const Value*);
        // @0x14244f9e0
        void lineStyle(Value& result, unsigned, const Value*);
        // @0x14244fdd0
        void lineTo(const Value& result, Value::Number, Value::Number);
        // @0x1424508c0
        void moveTo(const Value& result, Value::Number, Value::Number);
    };

    // 0x78 bytes.
    class Loader : public Instances::fl_display::DisplayObjectContainer
    {
    public:
        Loader(InstanceTraits::Traits& t);
        Loader(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x142443690
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::Loader"; }
        virtual void InitInstance(bool extCall);         // 0x142444620
        virtual GFx::DisplayObject* CreateStageObject();
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    public:
        SPtr<Instances::fl_display::LoaderInfo> pContentLoaderInfo; // +0x70

        // @0x142448b80
        void close(const Value& result);
        // @0x142448f50
        void contentGet(SPtr<Instances::fl_display::DisplayObject>& result);
        SPtr<Instances::fl_display::DisplayObject> contentGet();   // 0x142448f20 (sfr17)
        // @0x142449020
        void contentLoaderInfoGet(SPtr<Instances::fl_display::LoaderInfo>& result);
        SPtr<Instances::fl_display::LoaderInfo> contentLoaderInfoGet();   // 0x142448ff0 (sfr17)
        // @0x14244fe10
        void load(const Value& result, Instances::fl_net::URLRequest*, Instances::fl_system::LoaderContext*);
        // @0x14244fe80
        void loadBytes(const Value& result, Instances::fl_utils::ByteArray*, Instances::fl_system::LoaderContext*);
        // @0x142454680
        void unload(const Value& result);
        // @0x1424546a0
        void unloadAndStop(const Value& result, bool);

        // Load notifications: dispatch complete / ioError / init / open / progress to the LoaderInfo's listeners.
        void ExecuteCompleteEvent();                                    // 0x1424421e0
        void ExecuteErrorEvent(const char* purl);                       // 0x142442410
        void ExecuteInitEvent(GFx::DisplayObject* pcontent);            // 0x1424425d0
        void ExecuteOpenEvent();                                        // 0x1424428f0
        void ExecuteProgressEvent(UPInt bytesLoaded, UPInt bytesTotal); // 0x142442a60

        Instances::fl_display::LoaderInfo* GetContentLoaderInfo() const { return pContentLoaderInfo; } // 0x142443d90
        // Drops the LoaderInfo's content object (0x1424463f0).
        void ResetContent();
        // Queue the complete / init notification as an action of the movie root (0x142445ca0 / 0x142445db0); the
        // init action holds pcontent and pref until it runs.
        void QueueCompleteEvent();
        void QueueInitEvent(GFx::DisplayObject* pcontent, Ptr<RefCountImpl> pref);
    };

    // 0x68 bytes.
    class LoaderInfo : public Instances::fl_events::EventDispatcher
    {
    public:
        LoaderInfo(InstanceTraits::Traits& t);
        LoaderInfo(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x1424436d0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::LoaderInfo"; }
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    public:
        UInt32                                      BytesLoaded;    // +0x50
        UInt32                                      BytesTotal;     // +0x54
        SPtr<Instances::fl_display::DisplayObject>  Content;        // +0x58
        SPtr<Instances::fl_display::Loader>         pLoader;        // +0x60

        // Load notifications: dispatch complete / ioError / init / open / progress to the LoaderInfo's listeners.
        void ExecuteCompleteEvent();                                    // 0x1424422a0
        void ExecuteErrorEvent(const char* ptext);                      // 0x142442520
        void ExecuteInitEvent(GFx::DisplayObject* pcontent);            // 0x1424426d0
        void ExecuteOpenEvent();                                        // 0x1424429b0
        void ExecuteProgressEvent(UPInt bytesLoaded, UPInt bytesTotal); // 0x142442b50

        // The display object of the content (0x142443d00).
        GFx::DisplayObject* GetContentDispObj() const;
        // (sfr_as2_01e) sets the pLoader back pointer (0x142446d90).
        void SetLoader(Instances::fl_display::Loader* p);

        // @0x1424474c0
        void actionScriptVersionGet(UInt32& result);
        // @0x142447e50
        void applicationDomainGet(SPtr<Instances::fl_system::ApplicationDomain>& result);
        SPtr<Instances::fl_system::ApplicationDomain> applicationDomainGet();
        // @0x142448850
        void bytesGet(SPtr<Instances::fl_utils::ByteArray>& result);
        SPtr<Instances::fl_utils::ByteArray> bytesGet();
        // @0x142448870
        void bytesLoadedGet(UInt32& result);
        // @0x1424488d0
        void bytesTotalGet(UInt32& result);
        // @0x142448970
        void childAllowsParentGet(bool& result);
        // @0x142448990
        void childSandboxBridgeGet(SPtr<Instances::fl::Object>& result);
        // @0x1424489b0
        void childSandboxBridgeSet(const Value& result, const Value&);
        // @0x142448fe0
        void contentGet(SPtr<Instances::fl_display::DisplayObject>& result);
        SPtr<Instances::fl_display::DisplayObject> contentGet();   // 0x142448fb0 (sfr17)
        // @0x142449030
        void contentTypeGet(ASString& result);
        // @0x14244c3b0
        void frameRateGet(Value::Number& result);
        // @0x14244e540
        void heightGet(SInt32& result);
        // @0x14244ff20
        void loaderGet(SPtr<Instances::fl_display::Loader>& result);
        // @0x142450020
        void loaderURLGet(ASString& result);
        // @0x142451200
        void parametersGet(SPtr<Instances::fl::Object>& result);
        // @0x142451220
        void parentAllowsChildGet(bool& result);
        // @0x142451300
        void parentSandboxBridgeGet(SPtr<Instances::fl::Object>& result);
        // @0x142451320
        void parentSandboxBridgeSet(const Value& result, const Value&);
        // @0x142452250
        void sameDomainGet(bool& result);
        // @0x142453290
        void sharedEventsGet(SPtr<Instances::fl_events::EventDispatcher>& result);
        SPtr<Instances::fl_events::EventDispatcher> sharedEventsGet();
        // @0x1424539c0
        void swfVersionGet(UInt32& result);
        // @0x1424547b0
        void urlGet(ASString& result);
        // @0x142454a20
        void widthGet(SInt32& result);
    };

    // 0x78 bytes.
    class Sprite : public Instances::fl_display::DisplayObjectContainer
    {
    public:
        Sprite(InstanceTraits::Traits& t);
        Sprite(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        virtual ~Sprite();
        // @0x142443870
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::Sprite"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        virtual void InitInstance(bool extCall);         // 0x142444a00
        virtual GFx::DisplayObject* CreateStageObject();
        virtual bool HasFrameScript() const;                 // 0x1424445e0
        virtual bool GetFrameScript(unsigned frame, Value* pv); // 0x142443e10
        virtual bool IsMovieClip() const;                    // 0x142444bf0
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    public:
        SPtr<Instances::fl_display::Graphics>   pGraphics;  // +0x70

        // @0x1424487c0
        void buttonModeGet(bool& result);
        // @0x1424487e0
        void buttonModeSet(const Value& result, bool);
        // @0x14244b870
        void dropTargetGet(SPtr<Instances::fl_display::DisplayObject>& result);
        SPtr<Instances::fl_display::DisplayObject> dropTargetGet();
        // @0x14244e3c0
        void graphicsGet(SPtr<Instances::fl_display::Graphics>& result);
        SPtr<Instances::fl_display::Graphics> graphicsGet();
        // @0x14244ec30
        void hitAreaGet(SPtr<Instances::fl_display::Sprite>& result);
        // @0x14244ecc0
        void hitAreaSet(const Value& result, Instances::fl_display::Sprite*);
        // @0x1424533c0
        void soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result);
        SPtr<Instances::fl_media::SoundTransform> soundTransformGet();
        // @0x142453400
        void soundTransformSet(const Value& result, Instances::fl_media::SoundTransform*);
        // @0x142453670
        void startDrag(const Value& result, bool, Instances::fl_geom::Rectangle*);
        // @0x142453800
        void stopDrag(const Value& result);
        // @0x1424548a0
        void useHandCursorGet(bool& result);
        // @0x1424548f0
        void useHandCursorSet(const Value& result, bool);
    };

    // 0x88 bytes.
    class MovieClip : public Instances::fl_display::Sprite
    {
    public:
        // (appended, sfr33) member ABI: the exe passes the result slot in rdx. 0x142440f80
        SPtr<Instances::fl_display::Scene> FUN_142440f80();   // a Scene standing for the whole clip
        // Frame scripts set by addFrameScript: a bit array of the set frames followed by the descriptors, sorted by
        // frame.
        struct FrameScript
        {
            // 0x28 bytes.
            struct Descr
            {
                Descr(const Value& method, UInt32 frame) : Method(method), Frame(frame) {}
                Descr(const Descr& other);

                static bool Less(const Descr& a, const Descr& b) { return a.Frame < b.Frame; }

                Value   Method; // +0x00
                UInt32  Frame;  // +0x20
            };

            FrameScript() : pData(0), DescrCnt(0), FrameCnt(0) {}
            ~FrameScript();                                  // 0x14243d290

            const Descr* Get(unsigned frame);
            // Adds the descriptors (a later one wins for the same frame; an already set frame gets its method
            // replaced), keeping the descriptors sorted by frame (0x1424466b0).
            void Set(MemoryHeap* pheap, unsigned frameCnt, unsigned descrCnt, const Descr* pdescrs);
            void ForEachChild_GC(Collector* prcc, GcOp op, const Instances::fl::Object& owner) const;

            bool    IsSet(unsigned frame) const { return (reinterpret_cast<const UByte*>(pData)[frame >> 3] & (1 << (frame & 7))) != 0; }
            Descr*  GetDescrs() const   { return reinterpret_cast<Descr*>(reinterpret_cast<UByte*>(pData) + (UInt32)(((FrameCnt + 31) >> 5) * sizeof(UInt32))); }

            void*   pData;      // +0x00: (FrameCnt + 31) / 32 words of bits, then the values
            UInt16  DescrCnt;   // +0x08: number of values
            UInt16  FrameCnt;   // +0x0a
        };

        MovieClip(InstanceTraits::Traits& t);
        MovieClip(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x142443730
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::MovieClip"; }
        virtual bool HasFrameScript() const;                 // 0x1424445d0
        virtual bool GetFrameScript(unsigned frame, Value* pv);
        virtual bool IsMovieClip() const;                    // 0x142444be0
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // The scene holding frame / named name, NULL unless the sprite is a movie (0x1424443f0 / 0x142444490).
        const MovieDataDef::SceneInfo* GetSceneInfo(unsigned frame) const;
        const MovieDataDef::SceneInfo* GetSceneInfoByName(const ASString& name) const;
    public:
        // Resolves frame (a label) to *targetFrame and checks that it lies in scene (or the current scene when
        // scene is null/undefined); throws and returns false otherwise (0x142444050).
        bool GetLabeledFrame(GFx::Sprite* spr, const Value& frame, const Value& scene, unsigned* targetFrame);

        FrameScript frameScript;    // +0x78

        // @0x1424478a0
        void addFrameScript(Value& result, unsigned, const Value*);
        // @0x1424496a0
        void currentFrameGet(SInt32& result);
        // @0x1424496d0
        void currentFrameLabelGet(ASString& result);
        // @0x1424497a0
        void currentLabelGet(ASString& result);
        // @0x1424498d0
        void currentLabelsGet(SPtr<Instances::fl::Array>& result);
        SPtr<Instances::fl::Array> currentLabelsGet();   // 0x142449870 (sfr17)
        // @0x142449950
        void currentSceneGet(SPtr<Instances::fl_display::Scene>& result);
        SPtr<Instances::fl_display::Scene> currentSceneGet();
        // @0x14244b970
        void enabledGet(bool& result);
        // @0x14244b9b0
        void enabledSet(const Value& result, bool);
        // @0x14244c480
        void framesLoadedGet(SInt32& result);
        // @0x14244e0e0
        void gotoAndPlay(const Value& result, const Value&, const Value&);
        // @0x14244e1d0
        void gotoAndStop(const Value& result, const Value&, const Value&);
        // @0x142450b60
        void nextFrame(const Value& result);
        // @0x142450bc0
        void nextScene(const Value& result);
        // @0x142451a80
        void play(const Value& result);
        // @0x142451a90
        void prevFrame(const Value& result);
        // @0x142451ae0
        void prevScene(const Value& result);
        // @0x142452770
        void scenesGet(SPtr<Instances::fl::Array>& result);
        SPtr<Instances::fl::Array> scenesGet();
        // @0x1424537e0
        void stop(const Value& result);
        // @0x1424542b0
        void totalFramesGet(SInt32& result);
        // @0x1424542e0
        void trackAsMenuGet(bool& result);
        // @0x142454320
        void trackAsMenuSet(const Value& result, bool);
    };

    // 0x68 bytes: no members of its own.
    class MorphShape : public Instances::fl_display::DisplayObject
    {
    public:
        MorphShape(InstanceTraits::Traits& t);
        MorphShape(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x142443700
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::MorphShape"; }
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class NativeMenu : public Instances::fl::Object
    {
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class NativeWindow : public Instances::fl::Object
    {
    };

    // 0x48 bytes.
    class Scene : public Instances::fl::Object
    {
    public:
        Scene(InstanceTraits::Traits& t);
        Scene(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x1424437a0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::Scene"; }
        const MovieDataDef::SceneInfo*  SceneInfo;  // +0x38
        Ptr<GFx::Sprite>                SpriteObj;  // +0x40

        void Set(GFx::Sprite* psprite);  // 0x142446bd0

        // @0x14244f5b0
        void labelsGet(SPtr<Instances::fl::Array>& result);
        SPtr<Instances::fl::Array> labelsGet();
        // @0x142450a00
        void nameGet(ASString& result);
        // @0x142450d60
        void numFramesGet(SInt32& result);
    };

    // 0x70 bytes.
    class Shape : public Instances::fl_display::DisplayObject
    {
    public:
        Shape(InstanceTraits::Traits& t);
        Shape(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by Shape::MakeInstance (sfr_as2_01)
        virtual ~Shape();
        // @0x1424437f0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::Shape"; }
        virtual void InitInstance(bool extCall);         // 0x1424447c0
        virtual GFx::DisplayObject* CreateStageObject();
    protected:
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
    public:
        SPtr<Instances::fl_display::Graphics>   pGraphics;  // +0x68

        // @0x14244e2e0
        void graphicsGet(SPtr<Instances::fl_display::Graphics>& result);
        SPtr<Instances::fl_display::Graphics> graphicsGet();
    };

    // 0x70 bytes: no members of its own yet.
    class SimpleButton : public Instances::fl_display::InteractiveObject
    {
    public:
        SimpleButton(InstanceTraits::Traits& t);
        SimpleButton(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x142443820
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::SimpleButton"; }
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        virtual void InitInstance(bool extCall);         // 0x142444890
        virtual GFx::DisplayObject* CreateStageObject();

        // @0x142449e00
        void downStateGet(SPtr<Instances::fl_display::DisplayObject>& result);
        SPtr<Instances::fl_display::DisplayObject> downStateGet();
        // @0x142449e80
        void downStateSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x14244b990
        void enabledGet(bool& result);
        // @0x14244b9d0
        void enabledSet(const Value& result, bool);
        // @0x14244f4a0
        void hitTestStateGet(SPtr<Instances::fl_display::DisplayObject>& result);
        SPtr<Instances::fl_display::DisplayObject> hitTestStateGet();
        // @0x14244f520
        void hitTestStateSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x142450e50
        void overStateGet(SPtr<Instances::fl_display::DisplayObject>& result);
        SPtr<Instances::fl_display::DisplayObject> overStateGet();
        // @0x142450ed0
        void overStateSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x142453360
        void soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result);
        SPtr<Instances::fl_media::SoundTransform> soundTransformGet();
        // @0x1424533e0
        void soundTransformSet(const Value& result, Instances::fl_media::SoundTransform*);
        // @0x142454300
        void trackAsMenuGet(bool& result);
        // @0x142454350
        void trackAsMenuSet(const Value& result, bool);
        // @0x142454700
        void upStateGet(SPtr<Instances::fl_display::DisplayObject>& result);
        SPtr<Instances::fl_display::DisplayObject> upStateGet();
        // @0x142454780
        void upStateSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x142454880
        void useHandCursorGet(bool& result);
        // @0x1424548c0
        void useHandCursorSet(const Value& result, bool);
    };

    // 0x70 bytes: no members of its own.
    class Stage : public Instances::fl_display::DisplayObjectContainer
    {
    public:
        Stage(InstanceTraits::Traits& t);
        Stage(InstanceTraits::Traits& t, Instances::fl::InlineCtor);   // inlined by MakeInstance (sfr_as2_01)
        // @0x1424438b0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl_display::Stage"; }

        // @0x142447630
        void addChild(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject*);
        SPtr<Instances::fl_display::DisplayObject> addChild(Instances::fl_display::DisplayObject* a0);   // 0x142447610 (sfr17)
        // @0x142447820
        void addChildAt(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject*, SInt32);
        SPtr<Instances::fl_display::DisplayObject> addChildAt(Instances::fl_display::DisplayObject* a0, SInt32 a1);   // 0x142447800 (sfr17)
        // @0x142447830
        void addEventListener(const Value& result, const ASString&, const Value&, bool, SInt32, bool);
        // @0x142447b90
        void alignGet(ASString& result);
        // @0x142447cb0
        void alignSet(const Value& result, const ASString&);
        // @0x142448290
        void assignFocus(const Value& result, Instances::fl_display::InteractiveObject*, const ASString&);
        // @0x1424482b0
        void autoOrientsGet(bool& result);
        // @0x142449be0
        void deviceOrientationGet(ASString& result);
        // @0x142449ca0
        void dispatchEvent(bool& result, Instances::fl_events::Event*);
        // @0x142449cb0
        void displayStateGet(ASString& result);
        // @0x142449cd0
        void displayStateSet(const Value& result, const ASString&);
        // @0x14244c080
        void focusGet(SPtr<Instances::fl_display::InteractiveObject>& result);
        SPtr<Instances::fl_display::InteractiveObject> focusGet();
        // @0x14244c2b0
        void focusSet(const Value& result, Instances::fl_display::InteractiveObject*);
        // @0x14244c420
        void frameRateGet(Value::Number& result);
        // @0x14244c460
        void frameRateSet(const Value& result, Value::Number);
        // @0x14244c4b0
        void fullScreenHeightGet(UInt32& result);
        // @0x14244c510
        void fullScreenSourceRectGet(SPtr<Instances::fl_geom::Rectangle>& result);
        SPtr<Instances::fl_geom::Rectangle> fullScreenSourceRectGet();
        // @0x14244c530
        void fullScreenSourceRectSet(const Value& result, Instances::fl_geom::Rectangle*);
        // @0x14244c550
        void fullScreenWidthGet(UInt32& result);
        // @0x14244e470
        void hasEventListener(bool& result, const ASString&);
        // @0x14244e5b0
        void heightGet(Value::Number& result);
        // @0x14244e650
        void heightSet(const Value& result, Value::Number);
        // @0x14244f550
        void invalidate(const Value& result);
        // @0x14244f570
        void isFocusInaccessible(bool& result);
        // @0x142450790
        void mouseChildrenGet(bool& result);
        // @0x1424507e0
        void mouseChildrenSet(const Value& result, bool);
        // @0x142450b40
        void nativeWindowGet(SPtr<Instances::fl_display::NativeWindow>& result);
        // @0x142450d50
        void numChildrenGet(SInt32& result);
        // @0x142450de0
        void orientationGet(ASString& result);
        // @0x142451bb0
        void qualityGet(ASString& result);
        // @0x142451bd0
        void qualitySet(const Value& result, const ASString&);
        // @0x142452030
        void removeChildAt(SPtr<Instances::fl_display::DisplayObject>& result, SInt32);
        SPtr<Instances::fl_display::DisplayObject> removeChildAt(SInt32 a0);   // 0x142452010 (sfr17)
        // @0x142452040
        void removeEventListener(const Value& result, const ASString&, const Value&, bool);
        // @0x142452500
        void scaleModeGet(ASString& result);
        // @0x1424525c0
        void scaleModeSet(const Value& result, const ASString&);
        // @0x142452d90
        void setChildIndex(const Value& result, Instances::fl_display::DisplayObject*, SInt32);
        // @0x142452e00
        void setOrientation(const Value& result, const ASString&);
        // @0x1424532b0
        void showDefaultContextMenuGet(bool& result);
        // @0x1424532d0
        void showDefaultContextMenuSet(const Value& result, bool);
        // @0x142453420
        void stageFocusRectGet(bool& result);
        // @0x142453440
        void stageFocusRectSet(const Value& result, bool);
        // @0x142453570
        void stageHeightGet(SInt32& result);
        // @0x1424535d0
        void stageHeightSet(const Value& result, SInt32);
        // @0x1424535f0
        void stageWidthGet(SInt32& result);
        // @0x142453650
        void stageWidthSet(const Value& result, SInt32);
        // @0x142453960
        void swapChildrenAt(const Value& result, SInt32, SInt32);
        // @0x142453a50
        void tabChildrenGet(bool& result);
        // @0x142453b30
        void tabChildrenSet(const Value& result, bool);
        // @0x142453e90
        void textSnapshotGet(SPtr<Instances::fl_text::TextSnapshot>& result);
        SPtr<Instances::fl_text::TextSnapshot> textSnapshotGet();
        // @0x142454a90
        void widthGet(Value::Number& result);
        // @0x142454b30
        void widthSet(const Value& result, Value::Number);
        // @0x142454b50
        void willTrigger(bool& result, const ASString&);
    };

}}

namespace Classes { namespace fl_display {
    class LoaderInfo : public Class
    {
    public:
        LoaderInfo(ClassTraits::Traits& t);
        LoaderInfo(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x1424436b0
        virtual const char* GetAS3ObjectType() const { return "Classes::LoaderInfo"; }

        // @0x14244d1a0
        void getLoaderInfoByDefinition(SPtr<Instances::fl_display::LoaderInfo>& result, const Value&);
    };

    class Stage : public Class
    {
    public:
        Stage(ClassTraits::Traits& t);
        Stage(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443890
        virtual const char* GetAS3ObjectType() const { return "Classes::Stage"; }

        // @0x142453880
        void supportsOrientationChangeGet(bool& result);
    };

    // 0x58 bytes.
    class ActionScriptVersion : public Class
    {
    public:
        ActionScriptVersion(ClassTraits::Traits& t);
        ActionScriptVersion(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443420
        virtual const char* GetAS3ObjectType() const { return "Classes::ActionScriptVersion"; }

        UInt32 Actionscript2; // +0x50
        UInt32 Actionscript3; // +0x54
    };

    // 0x60 bytes.
    class BitmapDataChannel : public Class
    {
    public:
        BitmapDataChannel(ClassTraits::Traits& t);
        BitmapDataChannel(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x1424434a0
        virtual const char* GetAS3ObjectType() const { return "Classes::BitmapDataChannel"; }

        UInt32 Alpha; // +0x50
        UInt32 Blue;  // +0x54
        UInt32 Green; // +0x58
        UInt32 Red;   // +0x5c
    };

    // 0xc0 bytes.
    class BlendMode : public Class
    {
    public:
        BlendMode(ClassTraits::Traits& t);
        BlendMode(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x1424434c0
        virtual const char* GetAS3ObjectType() const { return "Classes::fl_display::BlendMode"; }

        const char* Add;        // +0x50
        const char* Alpha;      // +0x58
        const char* Darken;     // +0x60
        const char* Difference; // +0x68
        const char* Erase;      // +0x70
        const char* Hardlight;  // +0x78
        const char* Invert;     // +0x80
        const char* Layer;      // +0x88
        const char* Lighten;    // +0x90
        const char* Multiply;   // +0x98
        const char* Normal;     // +0xa0
        const char* Overlay;    // +0xa8
        const char* Screen;     // +0xb0
        const char* Subtract;   // +0xb8

        // The render blend mode of an AS3 blend mode name; Blend_None for an unknown name (0x1424439d0).
        static Render::BlendMode GetBlendMode(const ASString& name);
    };

    // 0x68 bytes.
    class CapsStyle : public Class
    {
    public:
        CapsStyle(ClassTraits::Traits& t);
        CapsStyle(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x1424434e0
        virtual const char* GetAS3ObjectType() const { return "Classes::CapsStyle"; }

        const char* None;   // +0x50
        const char* Round;  // +0x58
        const char* Square; // +0x60
    };

    // 0x60 bytes.
    class GradientType : public Class
    {
    public:
        GradientType(ClassTraits::Traits& t);
        GradientType(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443590
        virtual const char* GetAS3ObjectType() const { return "Classes::GradientType"; }

        const char* Linear; // +0x50
        const char* Radial; // +0x58
    };

    // 0x60 bytes.
    class InterpolationMethod : public Class
    {
    public:
        InterpolationMethod(ClassTraits::Traits& t);
        InterpolationMethod(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443620
        virtual const char* GetAS3ObjectType() const { return "Classes::InterpolationMethod"; }

        const char* LinearRgb;  // +0x50
        const char* Rgb;        // +0x58
    };

    // 0x68 bytes.
    class JointStyle : public Class
    {
    public:
        JointStyle(ClassTraits::Traits& t);
        JointStyle(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443640
        virtual const char* GetAS3ObjectType() const { return "Classes::JointStyle"; }

        const char* Bevel; // +0x50
        const char* Miter; // +0x58
        const char* Round; // +0x60
    };

    // 0x70 bytes.
    class LineScaleMode : public Class
    {
    public:
        LineScaleMode(ClassTraits::Traits& t);
        LineScaleMode(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443660
        virtual const char* GetAS3ObjectType() const { return "Classes::LineScaleMode"; }

        const char* Horizontal; // +0x50
        const char* None;       // +0x58
        const char* Normal;     // +0x60
        const char* Vertical;   // +0x68
    };

    // 0x68 bytes.
    class PixelSnapping : public Class
    {
    public:
        PixelSnapping(ClassTraits::Traits& t);
        PixelSnapping(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443750
        virtual const char* GetAS3ObjectType() const { return "Classes::PixelSnapping"; }

        const char* Always; // +0x50
        const char* Auto;   // +0x58
        const char* Never;  // +0x60
    };

    // 0x78 bytes.
    class SWFVersion : public Class
    {
    public:
        SWFVersion(ClassTraits::Traits& t);
        SWFVersion(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443770
        virtual const char* GetAS3ObjectType() const { return "Classes::SWFVersion"; }

        UInt32 Flash1;  // +0x50
        UInt32 Flash2;  // +0x54
        UInt32 Flash3;  // +0x58
        UInt32 Flash4;  // +0x5c
        UInt32 Flash5;  // +0x60
        UInt32 Flash6;  // +0x64
        UInt32 Flash7;  // +0x68
        UInt32 Flash8;  // +0x6c
        UInt32 Flash9;  // +0x70
        UInt32 Flash10; // +0x74: not set by the constructor
    };

    // 0x68 bytes.
    class SpreadMethod : public Class
    {
    public:
        SpreadMethod(ClassTraits::Traits& t);
        SpreadMethod(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443840
        virtual const char* GetAS3ObjectType() const { return "Classes::SpreadMethod"; }

        const char* Pad;     // +0x50
        const char* Reflect; // +0x58
        const char* Repeat;  // +0x60
    };

    // 0x90 bytes.
    class StageAlign : public Class
    {
    public:
        StageAlign(ClassTraits::Traits& t);
        StageAlign(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x1424438d0
        virtual const char* GetAS3ObjectType() const { return "Classes::StageAlign"; }

        const char* Bottom;       // +0x50
        const char* BottomLeft;   // +0x58
        const char* BottomRight;  // +0x60
        const char* Left;         // +0x68
        const char* Right;        // +0x70
        const char* Top;          // +0x78
        const char* TopLeft;      // +0x80
        const char* TopRight;     // +0x88
    };

    // 0x68 bytes.
    class StageDisplayState : public Class
    {
    public:
        StageDisplayState(ClassTraits::Traits& t);
        StageDisplayState(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x1424438f0
        virtual const char* GetAS3ObjectType() const { return "Classes::StageDisplayState"; }

        const char* FullScreen;              // +0x50
        const char* FullScreenInteractive;   // +0x58
        const char* Normal;                  // +0x60
    };

    // 0x70 bytes.
    class StageQuality : public Class
    {
    public:
        StageQuality(ClassTraits::Traits& t);
        StageQuality(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443910
        virtual const char* GetAS3ObjectType() const { return "Classes::StageQuality"; }

        const char* Best;   // +0x50
        const char* High;   // +0x58
        const char* Low;    // +0x60
        const char* Medium; // +0x68
    };

    // 0x70 bytes.
    class StageScaleMode : public Class
    {
    public:
        StageScaleMode(ClassTraits::Traits& t);
        StageScaleMode(ClassTraits::Traits& t, Instances::fl::InlineCtor);
        // @0x142443930
        virtual const char* GetAS3ObjectType() const { return "Classes::StageScaleMode"; }

        const char* ExactFit;  // +0x50
        const char* NoBorder;  // +0x58
        const char* NoScale;   // +0x60
        const char* ShowAll;   // +0x68
    };

}}

namespace InstanceTraits { namespace fl_display {
    class AVM1Movie : public CTraits
    {
    public:
        typedef Instances::fl_display::AVM1Movie InstanceType;

        AVM1Movie(VM& vm, const ClassInfo& ci);
        AVM1Movie(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x1424433f0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::AVM1Movie"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445480
        Pickable<InstanceType> MakeInstance(AVM1Movie& t);   // 0x142444c40
    };

    class Bitmap : public CTraits
    {
    public:
        typedef Instances::fl_display::Bitmap InstanceType;

        Bitmap(VM& vm, const ClassInfo& ci);
        Bitmap(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x142443440
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Bitmap"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424454e0
        Pickable<InstanceType> MakeInstance(Bitmap& t);   // 0x142444cb0
    };

    class BitmapData : public CTraits
    {
    public:
        typedef Instances::fl_display::BitmapData InstanceType;

        BitmapData(VM& vm, const ClassInfo& ci);
        // @0x142443470
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl_display::BitmapData"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445550
        Pickable<InstanceType> MakeInstance(BitmapData& t);   // 0x142444d30
    };

    class DisplayObject : public CTraits
    {
    public:
        typedef Instances::fl_display::DisplayObject InstanceType;

        DisplayObject(VM& vm, const ClassInfo& ci);
        // @0x142443500
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::DisplayObject"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424455d0
        Pickable<InstanceType> MakeInstance(DisplayObject& t);   // 0x142444db0
    };

    class DisplayObjectContainer : public CTraits
    {
    public:
        typedef Instances::fl_display::DisplayObjectContainer InstanceType;

        DisplayObjectContainer(VM& vm, const ClassInfo& ci);
        DisplayObjectContainer(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x142443530
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::DisplayObjectContainer"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445610
        Pickable<InstanceType> MakeInstance(DisplayObjectContainer& t);   // 0x142444e00
    };

    class FrameLabel : public CTraits
    {
    public:
        typedef Instances::fl_display::FrameLabel InstanceType;

        FrameLabel(VM& vm, const ClassInfo& ci);
        FrameLabel(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x142443560
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::FrameLabel"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445670
        Pickable<InstanceType> MakeInstance(FrameLabel& t);   // 0x142444e80
    };

    class Graphics : public CTraits
    {
    public:
        typedef Instances::fl_display::Graphics InstanceType;

        Graphics(VM& vm, const ClassInfo& ci);
        Graphics(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x1424435b0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Graphics"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424456f0
        Pickable<InstanceType> MakeInstance(Graphics& t);   // 0x142444f10
    };

    class InteractiveObject : public CTraits
    {
    public:
        typedef Instances::fl_display::InteractiveObject InstanceType;

        InteractiveObject(VM& vm, const ClassInfo& ci);
        InteractiveObject(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x1424435f0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::InteractiveObject"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445760
        Pickable<InstanceType> MakeInstance(InteractiveObject& t);   // 0x142444f90
    };

    class Loader : public CTraits
    {
    public:
        typedef Instances::fl_display::Loader InstanceType;

        Loader(VM& vm, const ClassInfo& ci);
        Loader(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x142443680
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Loader"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424457c0
        Pickable<InstanceType> MakeInstance(Loader& t);   // 0x142445010
    };

    class LoaderInfo : public CTraits
    {
    public:
        typedef Instances::fl_display::LoaderInfo InstanceType;

        LoaderInfo(VM& vm, const ClassInfo& ci);
        LoaderInfo(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x1424436c0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::LoaderInfo"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445830
        Pickable<InstanceType> MakeInstance(LoaderInfo& t);   // 0x142445090
    };

    class MorphShape : public CTraits
    {
    public:
        typedef Instances::fl_display::MorphShape InstanceType;

        MorphShape(VM& vm, const ClassInfo& ci);
        MorphShape(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x1424436f0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::MorphShape"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424458a0
        Pickable<InstanceType> MakeInstance(MorphShape& t);   // 0x142445110
    };

    class MovieClip : public CTraits
    {
    public:
        typedef Instances::fl_display::MovieClip InstanceType;

        MovieClip(VM& vm, const ClassInfo& ci);
        MovieClip(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x142443720
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::MovieClip"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445900
        Pickable<InstanceType> MakeInstance(MovieClip& t);   // 0x142445180
    };

    class Scene : public CTraits
    {
    public:
        typedef Instances::fl_display::Scene InstanceType;

        Scene(VM& vm, const ClassInfo& ci);
        Scene(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x142443790
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Scene"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445970
        Pickable<InstanceType> MakeInstance(Scene& t);   // 0x142445200
    };

    class Shape : public CTraits
    {
    public:
        typedef Instances::fl_display::Shape InstanceType;

        Shape(VM& vm, const ClassInfo& ci);
        Shape(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x1424437e0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Shape"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x1424459e0
        Pickable<InstanceType> MakeInstance(Shape& t);   // 0x142445280
    };

    class SimpleButton : public CTraits
    {
    public:
        typedef Instances::fl_display::SimpleButton InstanceType;

        SimpleButton(VM& vm, const ClassInfo& ci);
        SimpleButton(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x142443810
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::SimpleButton"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445a40
        Pickable<InstanceType> MakeInstance(SimpleButton& t);   // 0x142445300
    };

    class Sprite : public CTraits
    {
    public:
        typedef Instances::fl_display::Sprite InstanceType;

        Sprite(VM& vm, const ClassInfo& ci);
        Sprite(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x142443860
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Sprite"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445aa0
        Pickable<InstanceType> MakeInstance(Sprite& t);   // 0x142445380
    };

    class Stage : public CTraits
    {
    public:
        typedef Instances::fl_display::Stage InstanceType;

        Stage(VM& vm, const ClassInfo& ci);
        Stage(VM& vm, const ClassInfo& ci, Instances::fl::InlineCtor);
        // @0x1424438a0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Stage"; }
        virtual void MakeObject(Value& result, Traits& t);      // 0x142445b10
        Pickable<InstanceType> MakeInstance(Stage& t);   // 0x142445400
    };

}}

namespace ClassTraits { namespace fl_display {
    class AVM1Movie : public Traits
    {
    public:
        AVM1Movie(VM& vm);
        AVM1Movie(VM& vm, Instances::fl::InlineCtor);
        // @0x1424433e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::AVM1Movie"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ActionScriptVersion : public Traits
    {
    public:
        ActionScriptVersion(VM& vm);
        ActionScriptVersion(VM& vm, Instances::fl::InlineCtor);
        // @0x142443410
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ActionScriptVersion"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Bitmap : public Traits
    {
    public:
        Bitmap(VM& vm);
        Bitmap(VM& vm, Instances::fl::InlineCtor);
        // @0x142443430
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Bitmap"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class BitmapData : public Traits
    {
    public:
        BitmapData(VM& vm);
        // @0x142443460
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::BitmapData"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class BitmapDataChannel : public Traits
    {
    public:
        BitmapDataChannel(VM& vm);
        BitmapDataChannel(VM& vm, Instances::fl::InlineCtor);
        // @0x142443490
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::BitmapDataChannel"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class BlendMode : public Traits
    {
    public:
        BlendMode(VM& vm);
        BlendMode(VM& vm, Instances::fl::InlineCtor);
        // @0x1424434b0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::BlendMode"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class CapsStyle : public Traits
    {
    public:
        CapsStyle(VM& vm);
        CapsStyle(VM& vm, Instances::fl::InlineCtor);
        // @0x1424434d0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::CapsStyle"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class DisplayObject : public Traits
    {
    public:
        DisplayObject(VM& vm);
        // @0x1424434f0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::DisplayObject"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class DisplayObjectContainer : public Traits
    {
    public:
        DisplayObjectContainer(VM& vm);
        DisplayObjectContainer(VM& vm, Instances::fl::InlineCtor);
        // @0x142443520
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::DisplayObjectContainer"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class FrameLabel : public Traits
    {
    public:
        FrameLabel(VM& vm);
        FrameLabel(VM& vm, Instances::fl::InlineCtor);
        // @0x142443550
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::FrameLabel"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class GradientType : public Traits
    {
    public:
        GradientType(VM& vm);
        GradientType(VM& vm, Instances::fl::InlineCtor);
        // @0x142443580
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::GradientType"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Graphics : public Traits
    {
    public:
        Graphics(VM& vm);
        Graphics(VM& vm, Instances::fl::InlineCtor);
        // @0x1424435a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Graphics"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IBitmapDrawable : public Traits
    {
    public:
        IBitmapDrawable(VM& vm);
        IBitmapDrawable(VM& vm, Instances::fl::InlineCtor);
        // @0x1424435d0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IBitmapDrawable"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class InteractiveObject : public Traits
    {
    public:
        InteractiveObject(VM& vm);
        InteractiveObject(VM& vm, Instances::fl::InlineCtor);
        // @0x1424435e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::InteractiveObject"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class InterpolationMethod : public Traits
    {
    public:
        InterpolationMethod(VM& vm);
        InterpolationMethod(VM& vm, Instances::fl::InlineCtor);
        // @0x142443610
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::InterpolationMethod"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class JointStyle : public Traits
    {
    public:
        JointStyle(VM& vm);
        JointStyle(VM& vm, Instances::fl::InlineCtor);
        // @0x142443630
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::JointStyle"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class LineScaleMode : public Traits
    {
    public:
        LineScaleMode(VM& vm);
        LineScaleMode(VM& vm, Instances::fl::InlineCtor);
        // @0x142443650
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::LineScaleMode"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Loader : public Traits
    {
    public:
        Loader(VM& vm);
        Loader(VM& vm, Instances::fl::InlineCtor);
        // @0x142443670
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Loader"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class LoaderInfo : public Traits
    {
    public:
        LoaderInfo(VM& vm);
        LoaderInfo(VM& vm, Instances::fl::InlineCtor);
        // @0x1424436a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::LoaderInfo"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class MorphShape : public Traits
    {
    public:
        MorphShape(VM& vm);
        MorphShape(VM& vm, Instances::fl::InlineCtor);
        // @0x1424436e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::MorphShape"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class MovieClip : public Traits
    {
    public:
        MovieClip(VM& vm);
        MovieClip(VM& vm, Instances::fl::InlineCtor);
        // @0x142443710
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::MovieClip"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class PixelSnapping : public Traits
    {
    public:
        PixelSnapping(VM& vm);
        PixelSnapping(VM& vm, Instances::fl::InlineCtor);
        // @0x142443740
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::PixelSnapping"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SWFVersion : public Traits
    {
    public:
        SWFVersion(VM& vm);
        SWFVersion(VM& vm, Instances::fl::InlineCtor);
        // @0x142443760
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SWFVersion"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Scene : public Traits
    {
    public:
        Scene(VM& vm);
        Scene(VM& vm, Instances::fl::InlineCtor);
        // @0x142443780
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Scene"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Shader : public Traits
    {
    public:
        Shader(VM& vm);
        Shader(VM& vm, Instances::fl::InlineCtor);
        // @0x1424437b0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Shader"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ShaderData : public Traits
    {
    public:
        ShaderData(VM& vm);
        ShaderData(VM& vm, Instances::fl::InlineCtor);
        // @0x1424437c0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ShaderData"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Shape : public Traits
    {
    public:
        Shape(VM& vm);
        Shape(VM& vm, Instances::fl::InlineCtor);
        // @0x1424437d0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Shape"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SimpleButton : public Traits
    {
    public:
        SimpleButton(VM& vm);
        SimpleButton(VM& vm, Instances::fl::InlineCtor);
        // @0x142443800
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SimpleButton"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SpreadMethod : public Traits
    {
    public:
        SpreadMethod(VM& vm);
        SpreadMethod(VM& vm, Instances::fl::InlineCtor);
        // @0x142443830
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SpreadMethod"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Sprite : public Traits
    {
    public:
        Sprite(VM& vm);
        Sprite(VM& vm, Instances::fl::InlineCtor);
        // @0x142443850
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Sprite"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Stage : public Traits
    {
    public:
        Stage(VM& vm);
        Stage(VM& vm, Instances::fl::InlineCtor);
        // @0x142443880
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Stage"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StageAlign : public Traits
    {
    public:
        StageAlign(VM& vm);
        StageAlign(VM& vm, Instances::fl::InlineCtor);
        // @0x1424438c0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StageAlign"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StageDisplayState : public Traits
    {
    public:
        StageDisplayState(VM& vm);
        StageDisplayState(VM& vm, Instances::fl::InlineCtor);
        // @0x1424438e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StageDisplayState"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StageQuality : public Traits
    {
    public:
        StageQuality(VM& vm);
        StageQuality(VM& vm, Instances::fl::InlineCtor);
        // @0x142443900
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StageQuality"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StageScaleMode : public Traits
    {
    public:
        StageScaleMode(VM& vm);
        StageScaleMode(VM& vm, Instances::fl::InlineCtor);
        // @0x142443920
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StageScaleMode"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

}}

}}} // namespace Scaleform::GFx::AS3

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::AVM1Movie) == 0xc8, "AVM1Movie size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::ActionScriptVersion) == 0xc8, "ActionScriptVersion size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::Bitmap) == 0xc8, "Bitmap size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::BitmapData) == 0xc8, "BitmapData size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::BitmapDataChannel) == 0xc8, "BitmapDataChannel size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::BlendMode) == 0xc8, "BlendMode size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::CapsStyle) == 0xc8, "CapsStyle size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject) == 0xc8, "DisplayObject size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObjectContainer) == 0xc8, "DisplayObjectContainer size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::FrameLabel) == 0xc8, "FrameLabel size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::GradientType) == 0xc8, "GradientType size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::Graphics) == 0xc8, "Graphics size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::IBitmapDrawable) == 0xc8, "IBitmapDrawable size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::InteractiveObject) == 0xc8, "InteractiveObject size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::InterpolationMethod) == 0xc8, "InterpolationMethod size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::JointStyle) == 0xc8, "JointStyle size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::LineScaleMode) == 0xc8, "LineScaleMode size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::Loader) == 0xc8, "Loader size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::LoaderInfo) == 0xc8, "LoaderInfo size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::MorphShape) == 0xc8, "MorphShape size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::MovieClip) == 0xc8, "MovieClip size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::PixelSnapping) == 0xc8, "PixelSnapping size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::SWFVersion) == 0xc8, "SWFVersion size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::Scene) == 0xc8, "Scene size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::Shader) == 0xc8, "Shader size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::ShaderData) == 0xc8, "ShaderData size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::Shape) == 0xc8, "Shape size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::SimpleButton) == 0xc8, "SimpleButton size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::SpreadMethod) == 0xc8, "SpreadMethod size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::Sprite) == 0xc8, "Sprite size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::Stage) == 0xc8, "Stage size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::StageAlign) == 0xc8, "StageAlign size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::StageDisplayState) == 0xc8, "StageDisplayState size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::StageQuality) == 0xc8, "StageQuality size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_display::StageScaleMode) == 0xc8, "StageScaleMode size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::ActionScriptVersion) == 0x58, "ActionScriptVersion size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::BitmapDataChannel) == 0x60, "BitmapDataChannel size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::BlendMode) == 0xc0, "BlendMode size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::CapsStyle) == 0x68, "CapsStyle size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::GradientType) == 0x60, "GradientType size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::InterpolationMethod) == 0x60, "InterpolationMethod size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::JointStyle) == 0x68, "JointStyle size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::LineScaleMode) == 0x70, "LineScaleMode size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::LoaderInfo) == 0x50, "LoaderInfo size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::PixelSnapping) == 0x68, "PixelSnapping size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::SWFVersion) == 0x78, "SWFVersion size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::SpreadMethod) == 0x68, "SpreadMethod size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::Stage) == 0x50, "Stage size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::StageAlign) == 0x90, "StageAlign size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::StageDisplayState) == 0x68, "StageDisplayState size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::StageQuality) == 0x70, "StageQuality size");
static_assert(sizeof(Scaleform::GFx::AS3::Classes::fl_display::StageScaleMode) == 0x70, "StageScaleMode size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::AVM1Movie) == 0xe8, "AVM1Movie size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap) == 0xe8, "Bitmap size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData) == 0xe8, "BitmapData size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject) == 0xe8, "DisplayObject size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObjectContainer) == 0xe8, "DisplayObjectContainer size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::FrameLabel) == 0xe8, "FrameLabel size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::Graphics) == 0xe8, "Graphics size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::InteractiveObject) == 0xe8, "InteractiveObject size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::Loader) == 0xe8, "Loader size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo) == 0xe8, "LoaderInfo size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::MorphShape) == 0xe8, "MorphShape size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip) == 0xe8, "MovieClip size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::Scene) == 0xe8, "Scene size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape) == 0xe8, "Shape size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::SimpleButton) == 0xe8, "SimpleButton size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::Sprite) == 0xe8, "Sprite size");
static_assert(sizeof(Scaleform::GFx::AS3::InstanceTraits::fl_display::Stage) == 0xe8, "Stage size");

#endif
