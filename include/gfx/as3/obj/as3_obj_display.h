// Recovered Scaleform GFx 4.1.18 AS3 native classes. Generated from the exe's ClassInfo tables and thunk
// member pointers (work/sfr5/gen_natives.py); our own declarations.
#ifndef MS2_SF_GFX_AS3_OBJ_DISPLAY_H
#define MS2_SF_GFX_AS3_OBJ_DISPLAY_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_events.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_display {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class DisplayObject : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x142447480
        void accessibilityPropertiesGet(SPtr<Instances::fl_accessibility::AccessibilityProperties>& result);
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
        // @0x14244bdd0
        void filtersSet(const Value& result, Instances::fl::Array*);
        // @0x14244c910
        void getBounds(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_display::DisplayObject*);
        // @0x14244d760
        void getRect(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_display::DisplayObject*);
        // @0x14244df40
        void globalToLocal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*);
        // @0x14244dd20
        void globalToLocal3D(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Point*);
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
        // @0x1424500e0
        void local3DToGlobal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Vector3D*);
        // @0x1424502c0
        void localToGlobal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point*);
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
        // @0x142452c90
        void scrollRectSet(const Value& result, Instances::fl_geom::Rectangle*);
        // @0x142453490
        void stageGet(SPtr<Instances::fl_display::Stage>& result);
        // @0x1424543a0
        void transformGet(SPtr<Instances::fl_geom::Transform>& result);
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
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Bitmap : public Instances::fl_display::DisplayObject
    {
    public:
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

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class BitmapData : public Instances::fl::Object
    {
    public:
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
        // @0x14244cfe0
        void getColorBoundsRect(SPtr<Instances::fl_geom::Rectangle>& result, UInt32, UInt32, bool);
        // @0x14244d4d0
        void getPixel(UInt32& result, SInt32, SInt32);
        // @0x14244d460
        void getPixel32(UInt32& result, SInt32, SInt32);
        // @0x14244d560
        void getPixels(SPtr<Instances::fl_utils::ByteArray>& result, Instances::fl_geom::Rectangle*);
        // @0x14244daf0
        void getVector(SPtr<Instances::fl_vec::Vector_uint>& result, Instances::fl_geom::Rectangle*);
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

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class InteractiveObject : public Instances::fl_display::DisplayObject
    {
    public:
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

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class DisplayObjectContainer : public Instances::fl_display::InteractiveObject
    {
    public:
        // @0x1424474f0
        void addChild(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject*);
        // @0x142447660
        void addChildAt(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject*, SInt32);
        // @0x142448270
        void areInaccessibleObjectsUnderPoint(bool& result, Instances::fl_geom::Point*);
        // @0x142448eb0
        void contains(bool& result, Instances::fl_display::DisplayObject*);
        // @0x14244cca0
        void getChildAt(SPtr<Instances::fl_display::DisplayObject>& result, SInt32);
        // @0x14244cde0
        void getChildByName(SPtr<Instances::fl_display::DisplayObject>& result, const ASString&);
        // @0x14244cee0
        void getChildIndex(SInt32& result, Instances::fl_display::DisplayObject*);
        // @0x14244d1e0
        void getObjectsUnderPoint(SPtr<Instances::fl::Array>& result, Instances::fl_geom::Point*);
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
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class FrameLabel : public Instances::fl::Object
    {
    public:
        // @0x14244c3a0
        void frameGet(SInt32& result);
        // @0x1424509c0
        void nameGet(ASString& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Graphics : public Instances::fl::Object
    {
    public:
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

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Loader : public Instances::fl_display::DisplayObjectContainer
    {
    public:
        // @0x142448b80
        void close(const Value& result);
        // @0x142448f50
        void contentGet(SPtr<Instances::fl_display::DisplayObject>& result);
        // @0x142449020
        void contentLoaderInfoGet(SPtr<Instances::fl_display::LoaderInfo>& result);
        // @0x14244fe10
        void load(const Value& result, Instances::fl_net::URLRequest*, Instances::fl_system::LoaderContext*);
        // @0x14244fe80
        void loadBytes(const Value& result, Instances::fl_utils::ByteArray*, Instances::fl_system::LoaderContext*);
        // @0x142454680
        void unload(const Value& result);
        // @0x1424546a0
        void unloadAndStop(const Value& result, bool);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class LoaderInfo : public Instances::fl_events::EventDispatcher
    {
    public:
        // @0x1424474c0
        void actionScriptVersionGet(UInt32& result);
        // @0x142447e50
        void applicationDomainGet(SPtr<Instances::fl_system::ApplicationDomain>& result);
        // @0x142448850
        void bytesGet(SPtr<Instances::fl_utils::ByteArray>& result);
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
        // @0x1424539c0
        void swfVersionGet(UInt32& result);
        // @0x1424547b0
        void urlGet(ASString& result);
        // @0x142454a20
        void widthGet(SInt32& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Sprite : public Instances::fl_display::DisplayObjectContainer
    {
    public:
        // @0x1424487c0
        void buttonModeGet(bool& result);
        // @0x1424487e0
        void buttonModeSet(const Value& result, bool);
        // @0x14244b870
        void dropTargetGet(SPtr<Instances::fl_display::DisplayObject>& result);
        // @0x14244e3c0
        void graphicsGet(SPtr<Instances::fl_display::Graphics>& result);
        // @0x14244ec30
        void hitAreaGet(SPtr<Instances::fl_display::Sprite>& result);
        // @0x14244ecc0
        void hitAreaSet(const Value& result, Instances::fl_display::Sprite*);
        // @0x1424533c0
        void soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result);
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

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class MovieClip : public Instances::fl_display::Sprite
    {
    public:
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
        // @0x142449950
        void currentSceneGet(SPtr<Instances::fl_display::Scene>& result);
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
        // @0x1424537e0
        void stop(const Value& result);
        // @0x1424542b0
        void totalFramesGet(SInt32& result);
        // @0x1424542e0
        void trackAsMenuGet(bool& result);
        // @0x142454320
        void trackAsMenuSet(const Value& result, bool);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class NativeMenu : public Instances::fl::Object
    {
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class NativeWindow : public Instances::fl::Object
    {
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Scene : public Instances::fl::Object
    {
    public:
        // @0x14244f5b0
        void labelsGet(SPtr<Instances::fl::Array>& result);
        // @0x142450a00
        void nameGet(ASString& result);
        // @0x142450d60
        void numFramesGet(SInt32& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Shape : public Instances::fl_display::DisplayObject
    {
    public:
        // @0x14244e2e0
        void graphicsGet(SPtr<Instances::fl_display::Graphics>& result);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class SimpleButton : public Instances::fl_display::InteractiveObject
    {
    public:
        // @0x142449e00
        void downStateGet(SPtr<Instances::fl_display::DisplayObject>& result);
        // @0x142449e80
        void downStateSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x14244b990
        void enabledGet(bool& result);
        // @0x14244b9d0
        void enabledSet(const Value& result, bool);
        // @0x14244f4a0
        void hitTestStateGet(SPtr<Instances::fl_display::DisplayObject>& result);
        // @0x14244f520
        void hitTestStateSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x142450e50
        void overStateGet(SPtr<Instances::fl_display::DisplayObject>& result);
        // @0x142450ed0
        void overStateSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x142453360
        void soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result);
        // @0x1424533e0
        void soundTransformSet(const Value& result, Instances::fl_media::SoundTransform*);
        // @0x142454300
        void trackAsMenuGet(bool& result);
        // @0x142454350
        void trackAsMenuSet(const Value& result, bool);
        // @0x142454700
        void upStateGet(SPtr<Instances::fl_display::DisplayObject>& result);
        // @0x142454780
        void upStateSet(const Value& result, Instances::fl_display::DisplayObject*);
        // @0x142454880
        void useHandCursorGet(bool& result);
        // @0x1424548c0
        void useHandCursorSet(const Value& result, bool);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Stage : public Instances::fl_display::DisplayObjectContainer
    {
    public:
        // @0x142447630
        void addChild(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject*);
        // @0x142447820
        void addChildAt(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject*, SInt32);
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
        // @0x142454a90
        void widthGet(Value::Number& result);
        // @0x142454b30
        void widthSet(const Value& result, Value::Number);
        // @0x142454b50
        void willTrigger(bool& result, const ASString&);
    };

}}

namespace Classes { namespace fl_display {
    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class LoaderInfo : public Class
    {
    public:
        // @0x14244d1a0
        void getLoaderInfoByDefinition(SPtr<Instances::fl_display::LoaderInfo>& result, const Value&);
    };

    // MS2-FUNCTIONAL: native method declarations only; the data members are not recovered yet
    class Stage : public Class
    {
    public:
        // @0x142453880
        void supportsOrientationChangeGet(bool& result);
    };

}}

}}} // namespace Scaleform::GFx::AS3

#endif
