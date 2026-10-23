// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_07
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142447390-0x142458c10 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x142455e90: Instances::fl_events::KeyboardEvent::keyCodeGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 10, UInt32>;
// thunk 0x142455ef0: Instances::fl_events::KeyboardEvent::keyCodeSet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 11, const Value, UInt32>;
// thunk 0x142455f60: Instances::fl_events::KeyboardEvent::keyLocationGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 12, UInt32>;
// thunk 0x142455fc0: Instances::fl_events::KeyboardEvent::keyLocationSet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 13, const Value, UInt32>;
// thunk 0x142456030: Instances::fl_events::KeyboardEvent::shiftKeyGet
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 14, bool>;
// thunk 0x142456090: Instances::fl_events::KeyboardEvent::shiftKeySet
template struct ThunkFunc1<Instances::fl_events::KeyboardEvent, 15, const Value, bool>;
// thunk 0x142456250: Instances::fl_events::KeyboardEvent::clone
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 16, SPtr<Instances::fl_events::Event>>;
// thunk 0x142456470: Instances::fl_events::KeyboardEvent::toString
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 17, ASString>;
// thunk 0x1424564e0: Instances::fl_events::KeyboardEvent::updateAfterEvent
template struct ThunkFunc0<Instances::fl_events::KeyboardEvent, 18, const Value>;
// thunk 0x142456680: Instances::fl_events::MouseEvent::altKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 0, bool>;
// thunk 0x1424566e0: Instances::fl_events::MouseEvent::altKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 1, const Value, bool>;
// thunk 0x142456740: Instances::fl_events::MouseEvent::buttonDownGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 2, bool>;
// thunk 0x1424567a0: Instances::fl_events::MouseEvent::buttonDownSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 3, const Value, bool>;
// thunk 0x142456800: Instances::fl_events::MouseEvent::clickCountGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 4, SInt32>;
// thunk 0x142456860: Instances::fl_events::MouseEvent::commandKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 5, bool>;
// thunk 0x142456a20: Instances::fl_events::MouseEvent::commandKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 6, const Value, bool>;
// thunk 0x142456a80: Instances::fl_events::MouseEvent::controlKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 7, bool>;
// thunk 0x142456ae0: Instances::fl_events::MouseEvent::controlKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 8, const Value, bool>;
// thunk 0x142456b40: Instances::fl_events::MouseEvent::ctrlKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 9, bool>;
// thunk 0x142456ba0: Instances::fl_events::MouseEvent::ctrlKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 10, const Value, bool>;
// thunk 0x142456c00: Instances::fl_events::MouseEvent::deltaGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 11, SInt32>;
// thunk 0x142456c60: Instances::fl_events::MouseEvent::deltaSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 12, const Value, SInt32>;
// thunk 0x142456cd0: Instances::fl_events::MouseEvent::localXGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 13, Value::Number>;
// thunk 0x142456d40: Instances::fl_events::MouseEvent::localXSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 14, const Value, Value::Number>;
// thunk 0x142456dd0: Instances::fl_events::MouseEvent::localYGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 15, Value::Number>;
// thunk 0x142456e40: Instances::fl_events::MouseEvent::localYSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 16, const Value, Value::Number>;
// thunk 0x142457030: Instances::fl_events::MouseEvent::relatedObjectGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 17, SPtr<Instances::fl_display::InteractiveObject>>;
// thunk 0x1424570e0: Instances::fl_events::MouseEvent::relatedObjectSet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 18, const Value, Instances::fl_display::InteractiveObject*>;
// thunk 0x142457120: Instances::fl_events::MouseEvent::shiftKeyGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 19, bool>;
// thunk 0x142457180: Instances::fl_events::MouseEvent::shiftKeySet
template struct ThunkFunc1<Instances::fl_events::MouseEvent, 20, const Value, bool>;
// thunk 0x1424571e0: Instances::fl_events::MouseEvent::stageXGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 21, Value::Number>;
// thunk 0x142457250: Instances::fl_events::MouseEvent::stageYGet
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 22, Value::Number>;
// thunk 0x1424572c0: Instances::fl_events::MouseEvent::clone
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 23, SPtr<Instances::fl_events::Event>>;
// thunk 0x142457370: Instances::fl_events::MouseEvent::toString
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 24, ASString>;
// thunk 0x142457540: Instances::fl_events::MouseEvent::updateAfterEvent
template struct ThunkFunc0<Instances::fl_events::MouseEvent, 25, const Value>;
// thunk 0x1424576e0: Instances::fl_events::NetStatusEvent::infoGet
template struct ThunkFunc0<Instances::fl_events::NetStatusEvent, 0, SPtr<Instances::fl::Object>>;
// thunk 0x142457790: Instances::fl_events::NetStatusEvent::infoSet
template struct ThunkFunc1<Instances::fl_events::NetStatusEvent, 1, const Value, const Value&>;
// thunk 0x1424578e0: Instances::fl_events::NetStatusEvent::clone
template struct ThunkFunc0<Instances::fl_events::NetStatusEvent, 2, SPtr<Instances::fl_events::Event>>;
// thunk 0x142457c50: Instances::fl_events::NetStatusEvent::toString
template struct ThunkFunc0<Instances::fl_events::NetStatusEvent, 3, ASString>;
// thunk 0x142457f80: Instances::fl_events::ProgressEvent::bytesLoadedGet
template struct ThunkFunc0<Instances::fl_events::ProgressEvent, 0, Value::Number>;
// thunk 0x142457ff0: Instances::fl_events::ProgressEvent::bytesLoadedSet
template struct ThunkFunc1<Instances::fl_events::ProgressEvent, 1, const Value, Value::Number>;
// thunk 0x142458080: Instances::fl_events::ProgressEvent::bytesTotalGet
template struct ThunkFunc0<Instances::fl_events::ProgressEvent, 2, Value::Number>;
// thunk 0x1424580f0: Instances::fl_events::ProgressEvent::bytesTotalSet
template struct ThunkFunc1<Instances::fl_events::ProgressEvent, 3, const Value, Value::Number>;
// thunk 0x142458180: Instances::fl_events::ProgressEvent::clone
template struct ThunkFunc0<Instances::fl_events::ProgressEvent, 4, SPtr<Instances::fl_events::Event>>;
// thunk 0x142458230: Instances::fl_events::ProgressEvent::toString
template struct ThunkFunc0<Instances::fl_events::ProgressEvent, 5, ASString>;
// thunk 0x142458980: Instances::fl_events::TextEvent::textGet
template struct ThunkFunc0<Instances::fl_events::TextEvent, 0, ASString>;
// thunk 0x1424589f0: Instances::fl_events::TextEvent::textSet
template struct ThunkFunc1<Instances::fl_events::TextEvent, 1, const Value, const ASString&>;
// thunk 0x142458af0: Instances::fl_events::TextEvent::clone
template struct ThunkFunc0<Instances::fl_events::TextEvent, 2, SPtr<Instances::fl_events::Event>>;
// thunk 0x142458ba0: Instances::fl_events::TextEvent::toString
template struct ThunkFunc0<Instances::fl_events::TextEvent, 3, ASString>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_errors.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_movieslots.h"
#include "ms2/scaleform/include/gfx/gfx_moviedef.h"
#include "ms2/scaleform/include/gfx/gfx_displayobjcontainer.h"
#include "ms2/scaleform/include/gfx/gfx_sprite.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/gfx/gfx_rendertree.h"
#include "ms2/scaleform/include/render/render_screentoworld.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_display_pixels.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_filters.h"

namespace Scaleform { namespace GFx { namespace AS3 { class AvmDisplayObj; }}}
// VM::IsOfType by class name (exe body).
bool FUN_1425145d0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const char* className);
// VM::GetValueTraits (exe body).
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v);
// AvmButton::GetDownStateObject / GetHitStateObject / GetOverStateObject / GetUpStateObject (exe bodies).
Scaleform::GFx::DisplayObject* FUN_142509970(Scaleform::GFx::AS3::AvmDisplayObj* pavm);
Scaleform::GFx::DisplayObject* FUN_14250a600(Scaleform::GFx::AS3::AvmDisplayObj* pavm);
Scaleform::GFx::DisplayObject* FUN_14250cbe0(Scaleform::GFx::AS3::AvmDisplayObj* pavm);
Scaleform::GFx::DisplayObject* FUN_14250f960(Scaleform::GFx::AS3::AvmDisplayObj* pavm);
// AvmBitmap::SetResourceMovieDef, RecreateRenderNode.
void FUN_142528e70(Scaleform::GFx::DisplayObject* pbitmap, Scaleform::GFx::MovieDefImpl* pdef);
// MovieClip::GetLabeledFrame (exe body): resolves a frame label within a scene, throws if it is not found.
bool FUN_142444050(Scaleform::GFx::AS3::Instances::fl_display::MovieClip* pthis, Scaleform::GFx::Sprite* psprite,
                   const Scaleform::GFx::AS3::Value& frame, const Scaleform::GFx::AS3::Value& scene, unsigned* ptargetFrame);
// AvmDisplayObj heap getter (exe body): the memory heap of the object's movie.
Scaleform::MemoryHeap* FUN_14250a5c0(Scaleform::GFx::AS3::AvmDisplayObj* pavm);
// MovieRoot::RemoveActionQueueEntriesFor, QueueFrameActions, ExecuteActionQueue.
void FUN_142522490(Scaleform::GFx::AS3::MovieRoot* proot, int level, Scaleform::GFx::DisplayObject* pdobj);
void FUN_142520080(Scaleform::GFx::AS3::MovieRoot* proot);
void FUN_1424fa320(Scaleform::GFx::AS3::MovieRoot* proot, unsigned level);
// AvmDisplayObj::GetStage (exe body): the stage display object of this object's movie.
Scaleform::GFx::DisplayObject* FUN_14250edf0(Scaleform::GFx::AS3::AvmDisplayObj* pavm);
// Sprite::GetTextSnapshot (exe body): fills a StaticTextSnapshotData from the sprite's static text fields.
void FUN_1425db410(Scaleform::GFx::DisplayObject* psprite, void* psnapshotData);
// Graphics: reads the gradient arguments of beginGradientFill / lineGradientStyle into the complex fill (exe body).
void FUN_142441010(Scaleform::GFx::AS3::Instances::fl_display::Graphics* pthis, unsigned argc,
                   const Scaleform::GFx::AS3::Value* argv, Scaleform::Render::ComplexFill* pfill);
// Scrolls the pixels of a bitmap image by (x, y) (exe body).
void FUN_1425eed00(Scaleform::Render::ImageBase* pimage, int x, int y);
// Flood fills a bitmap image from a point (exe body).
void FUN_1425ec9e0(Scaleform::Render::ImageBase* pimage, const Scaleform::Render::Point<Scaleform::SInt32>& pt, const Scaleform::Render::Color& color);
// Fills a rect of a bitmap image with one color (exe body).
void FUN_1425ec860(Scaleform::Render::ImageBase* pimage, const Scaleform::Render::Rect<Scaleform::SInt32>& rect, const Scaleform::Render::Color& color);
// Applies a color transform to a rect of a bitmap image (exe body).
void FUN_1425eb200(Scaleform::Render::ImageBase* pimage, const Scaleform::Render::Rect<Scaleform::SInt32>& rect, const Scaleform::Render::Cxform& cxform);
// Fills a bitmap image with random noise (exe body).
void FUN_1425eddc0(Scaleform::Render::ImageBase* pimage, Scaleform::SInt32 randomSeed, Scaleform::UInt32 low, Scaleform::UInt32 high,
                   Scaleform::UInt32 channelOptions, bool grayScale);

// Bitmap's pixel snapping mode of its AS3 name; AvmBitmap::RecreateRenderNode (both in sfr_as3_06).
// The pixel accessors of Render::DrawableImage the BitmapData natives call (exe bodies). render_drawableimage.h is
// built on the other kernel headers, so the AS3 units see the class opaque.
namespace Scaleform { namespace Render {
class DrawableImageContext;
class DrawableImage
{
public:
    // A drawable copy of delegateImage (the BitmapData clone); 200 bytes in the exe.
    DrawableImage(bool transparent, ImageBase* delegateImage, DrawableImageContext* context);   // 0x1425e9a00
    Color GetPixel(SInt32 x, SInt32 y);                 // 0x1425ecdd0
    Color GetPixel32(SInt32 x, SInt32 y);               // 0x1425ecd50
    bool  SetPixel(SInt32 x, SInt32 y, Color c);        // 0x1425eef90
    bool  SetPixel32(SInt32 x, SInt32 y, Color c);      // 0x1425eef20
    // Alpha hit tests of the image at firstPoint: against a rect, or against a second image placed at secondPoint.
    bool  HitTest(const Point<SInt32>& firstPoint, const Rect<SInt32>& secondRect, UInt32 firstAlphaThreshold);   // 0x1425ed5e0
    bool  HitTest(ImageBase* secondImage, const Point<SInt32>& firstPoint, const Point<SInt32>& secondPoint,
                  UInt32 firstAlphaThreshold, UInt32 secondAlphaThreshold);                                     // 0x1425ed800
    // Copies one channel of a rect of the source image into a channel of this image at destPoint.
    void  CopyChannel(ImageBase* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                      UInt32 sourceChannel, UInt32 destChannel);                                                  // 0x1425eb570
    // The bounds of the pixels whose (pixel & mask) equals color (or differs from it without findColor).
    Rect<SInt32> GetColorBoundsRect(UInt32 mask, UInt32 color, bool findColor);                                  // 0x1425ecb50
    // Fills this image with the per-pixel difference of image0 and image1.
    void  Compare(ImageBase* image0, ImageBase* image1);                                                            // 0x1425eb390
    // Copies a rect of the source image to destPoint, optionally through the alpha of alphaSource at alphaPoint.
    void  CopyPixels(ImageBase* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                     ImageBase* alphaSource, const Point<SInt32>* alphaPoint, bool mergeAlpha);                 // 0x1425eb700
    // Reads the pixels of sourceRect into the provider / writes the provider's pixels into destRect.
    bool  GetPixels(DIPixelProvider& provider, const Rect<SInt32>& sourceRect);                                   // 0x1425ecdf0
    bool  SetPixels(const Rect<SInt32>& destRect, DIPixelProvider& provider);                                     // 0x1425ef060
    // The twips area a filter covers when applied to sourceRect (twips).
    static void CalcFilterRect(RectF* result, const Rect<SInt32>& sourceRect, Filter* filter);                     // 0x1425eb180
    // Blends a rect of the source image into this image at destPoint with per-channel multipliers (0..256).
    void  Merge(ImageBase* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                UInt32 redMultiplier, UInt32 greenMultiplier, UInt32 blueMultiplier, UInt32 alphaMultiplier); // 0x1425edc00
    // Maps each channel of a rect of the source image through a 256-entry table (NULL leaves the channel as is);
    // the results of the four channels are added.
    void  PaletteMap(ImageBase* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                     UInt32** channels);                                                                          // 0x1425ee140
    // Copies numPixels pseudo-random pixels of a rect of the source image to destPoint (fillColor when the source
    // is this image); returns the seed to continue the dissolve with.
    SInt32 PixelDissolve(ImageBase* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                         SInt32 randomSeed, SInt32 numPixels, Color fillColor);                                  // 0x1425ee720
    // Fills this image with Perlin noise; offsets holds x / y float pairs, one per octave (offsetCount floats).
    void  PerlinNoise(float frequencyX, float frequencyY, unsigned numOctaves, unsigned randomSeed, bool stitch,
                      bool fractalNoise, unsigned channelOptions, bool grayScale, float* offsets, unsigned offsetCount); // 0x1425ee4d0
    // Threshold compare operations ("<", "<=", ">", ">=", "==", "!=").
    enum ThresholdOperation
    {
        Operation_Less,
        Operation_LessEqual,
        Operation_Greater,
        Operation_GreaterEqual,
        Operation_Equal,
        Operation_NotEqual
    };
    // Tests the pixels of a rect of the source image against threshold (both masked) and writes color where the
    // test passes (the source pixel otherwise, with copySource) to this image at destPoint.
    UInt32 Threshold(ImageBase* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                     ThresholdOperation op, UInt32 threshold, UInt32 color, UInt32 mask, bool copySource);           // 0x1425ef1e0
    // Applies filter to a rect of the source image, writing the result to this image at destPoint.
    void  ApplyFilter(DrawableImage* source, const Rect<SInt32>& sourceRect, const Point<SInt32>& destPoint,
                      Filter* filter);                                                                            // 0x1425eaff0
    bool  IsTransparent() const { return Transparent; }

    UByte Unrecovered_00[0x48];
    bool  Transparent;                                  // +0x48 the image has an alpha channel
};
}} // namespace Scaleform::Render

Scaleform::SInt32 FUN_142446f30(Scaleform::GFx::AS3::Instances::fl_display::Bitmap* pbitmap, const char* pname);
void FUN_142520b20(Scaleform::GFx::DisplayObject* pbitmap);
// MovieImpl::GetDrawableImageContext (made on first use).
void* FUN_14256f220(Scaleform::GFx::MovieImpl* pmovie);

namespace Scaleform { namespace GFx { namespace AS3 {

// ---- flash.errors: class traits (instances are InstanceTraits::fl::Error, class objects plain Class) ----

namespace fl_errors
{
    extern const ClassInfo EOFErrorCI;
    extern const ClassInfo IOErrorCI;
    extern const ClassInfo IllegalOperationErrorCI;
    extern const ClassInfo InvalidSWFErrorCI;
    extern const ClassInfo MemoryErrorCI;
    extern const ClassInfo ScriptTimeoutErrorCI;
    extern const ClassInfo StackOverflowErrorCI;
}

namespace ClassTraits { namespace fl_errors
{
    // @0x142455410
    EOFError::EOFError(VM& vm)
        : Traits(vm, AS3::fl_errors::EOFErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::EOFErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142454e70
    Pickable<Traits> EOFError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) EOFError(vm));
    }

    // @0x1424554f0
    IOError::IOError(VM& vm)
        : Traits(vm, AS3::fl_errors::IOErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::IOErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142454d50
    Pickable<Traits> IOError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IOError(vm));
    }

    // @0x1424555d0
    IllegalOperationError::IllegalOperationError(VM& vm)
        : Traits(vm, AS3::fl_errors::IllegalOperationErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::IllegalOperationErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424552f0
    Pickable<Traits> IllegalOperationError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IllegalOperationError(vm));
    }

    // @0x1424556b0
    InvalidSWFError::InvalidSWFError(VM& vm)
        : Traits(vm, AS3::fl_errors::InvalidSWFErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::InvalidSWFErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142454c30
    Pickable<Traits> InvalidSWFError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) InvalidSWFError(vm));
    }

    // @0x142455790
    MemoryError::MemoryError(VM& vm)
        : Traits(vm, AS3::fl_errors::MemoryErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::MemoryErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x142454f90
    Pickable<Traits> MemoryError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) MemoryError(vm));
    }

    // @0x142455870
    ScriptTimeoutError::ScriptTimeoutError(VM& vm)
        : Traits(vm, AS3::fl_errors::ScriptTimeoutErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::ScriptTimeoutErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424550b0
    Pickable<Traits> ScriptTimeoutError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ScriptTimeoutError(vm));
    }

    // @0x142455950
    StackOverflowError::StackOverflowError(VM& vm)
        : Traits(vm, AS3::fl_errors::StackOverflowErrorCI)
    {
        MemoryHeap* mh = vm.GetMemoryHeap();
        InstanceTraits::Traits* it = new(mh) InstanceTraits::fl::Error(vm, AS3::fl_errors::StackOverflowErrorCI);
        SetInstanceTraits(Pickable<InstanceTraits::Traits>(it));
        it->SetConstructor(Pickable<Class>(new(mh) Class(*this)));
    }

    // @0x1424551d0
    Pickable<Traits> StackOverflowError::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StackOverflowError(vm));
    }
}}

// ---- flash.events: class traits factories (the ClassTraits ctors are in sfr_as3_08) ----

namespace ClassTraits { namespace fl_events
{
    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424560f0
    Pickable<Traits> GestureEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) GestureEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142456300
    Pickable<Traits> StageOrientation::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StageOrientation(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142456500
    Pickable<Traits> TransformGestureEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TransformGestureEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424568c0
    Pickable<Traits> PressAndTapGestureEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) PressAndTapGestureEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142456ed0
    Pickable<Traits> KeyboardEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) KeyboardEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142458820
    Pickable<Traits> ContextMenuEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ContextMenuEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424573e0
    Pickable<Traits> ProgressEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ProgressEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457560
    Pickable<Traits> FocusEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) FocusEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457990
    Pickable<Traits> TextEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) TextEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457af0
    Pickable<Traits> IOErrorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) IOErrorEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457cc0
    Pickable<Traits> ErrorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) ErrorEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142457e20
    Pickable<Traits> NetStatusEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) NetStatusEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424582a0
    Pickable<Traits> SecurityErrorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SecurityErrorEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142458400
    Pickable<Traits> AsyncErrorEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) AsyncErrorEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x142458560
    Pickable<Traits> StatusEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) StatusEvent(vm));
    }

    // MS2-FUNCTIONAL: the exe inlines the ClassTraits/InstanceTraits/Classes ctors, which live in sfr_as3_08
    // @0x1424586c0
    Pickable<Traits> SyncEvent::MakeClassTraits(VM& vm)
    {
        return Pickable<Traits>(new(vm.GetMemoryHeap()) SyncEvent(vm));
    }
}}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// ---- flash.display.DisplayObject: simple property getters forwarding to the scripted display object ----
namespace Instances { namespace fl_display
{
    // @0x142447de0
    void DisplayObject::alphaGet(Value::Number& result)
    {
        result = pDispObj->GetAlpha() / 100.0;
    }

    // @0x14244e520
    void DisplayObject::heightGet(Value::Number& result)
    {
        result = pDispObj->GetHeight();
    }

    // @0x142450880
    void DisplayObject::mouseXGet(Value::Number& result)
    {
        result = pDispObj->GetMouseX();
    }

    // @0x1424508a0
    void DisplayObject::mouseYGet(Value::Number& result)
    {
        result = pDispObj->GetMouseY();
    }

    // @0x142452150
    void DisplayObject::rotationGet(Value::Number& result)
    {
        result = pDispObj->GetRotation();
    }

    // @0x142452190
    void DisplayObject::rotationXGet(Value::Number& result)
    {
        result = pDispObj->GetXRotation();
    }

    // @0x1424521d0
    void DisplayObject::rotationYGet(Value::Number& result)
    {
        result = pDispObj->GetYRotation();
    }

    // @0x142452210
    void DisplayObject::rotationZGet(Value::Number& result)
    {
        result = pDispObj->GetRotation();
    }

    // @0x142452660
    void DisplayObject::scaleXGet(Value::Number& result)
    {
        result = pDispObj->GetXScale() / 100.0;
    }

    // @0x1424526b0
    void DisplayObject::scaleYGet(Value::Number& result)
    {
        result = pDispObj->GetYScale() / 100.0;
    }

    // @0x142452700
    void DisplayObject::scaleZGet(Value::Number& result)
    {
        result = pDispObj->GetZScale() / 100.0;
    }

    // @0x142454920
    void DisplayObject::visibleGet(bool& result)
    {
        result = pDispObj->GetVisible();
    }

    // @0x142454a00
    void DisplayObject::widthGet(Value::Number& result)
    {
        result = pDispObj->GetWidth();
    }

    // @0x142454b60
    void DisplayObject::xGet(Value::Number& result)
    {
        result = pDispObj->GetX();
    }

    // @0x142454ba0
    void DisplayObject::yGet(Value::Number& result)
    {
        result = pDispObj->GetY();
    }

    // @0x142454be0
    void DisplayObject::zGet(Value::Number& result)
    {
        result = pDispObj->GetZ() * 0.05;
    }
}}

// ---- flash.display.Graphics: drawing API forwarding to the DrawingContext (coordinates converted to twips) ----

namespace Instances { namespace fl_display
{
    // @0x142448400
    void Graphics::beginFill(const Value& result, UInt32 color, Value::Number alpha)
    {
        SF_UNUSED(result);
        pDispObj->SetDirtyFlag();
        pDispObj->InvalidateHitResult();
        pDrawing->AcquirePath(true);
        pDrawing->BeginSolidFill((UInt32(alpha * 255.0) << 24) | color);
    }

    // @0x1424489d0
    void Graphics::clear(const Value& result)
    {
        SF_UNUSED(result);
        pDrawing->Clear();
        pDispObj->InvalidateHitResult();
        pDispObj->SetDirtyFlag();
    }

    // @0x142449b70
    void Graphics::curveTo(const Value& result, Value::Number controlX, Value::Number controlY,
                           Value::Number anchorX, Value::Number anchorY)
    {
        SF_UNUSED(result);
        pDrawing->CurveTo(float(controlX) * 20.0f, float(controlY) * 20.0f,
                          float(anchorX) * 20.0f, float(anchorY) * 20.0f);
        pDispObj->InvalidateHitResult();
    }

    // @0x14244b9f0
    void Graphics::endFill(const Value& result)
    {
        SF_UNUSED(result);
        pDispObj->SetDirtyFlag();
        pDispObj->InvalidateHitResult();
        pDrawing->AcquirePath(true);
        pDrawing->EndFill();
    }

    // @0x14244fdd0
    void Graphics::lineTo(const Value& result, Value::Number x, Value::Number y)
    {
        SF_UNUSED(result);
        pDrawing->LineTo(float(x * 20.0), float(y * 20.0));
        pDispObj->InvalidateHitResult();
    }

    // @0x1424508c0
    void Graphics::moveTo(const Value& result, Value::Number x, Value::Number y)
    {
        SF_UNUSED(result);
        pDispObj->SetDirtyFlag();
        pDispObj->InvalidateHitResult();
        pDrawing->AcquirePath(false);
        pDrawing->MoveTo(float(x * 20.0), float(y * 20.0));
        pDispObj->InvalidateHitResult();
    }
}}

// ---- flash.display: by-value forms of the SPtr-returning natives (used by the thunk table) ----

namespace Instances { namespace fl_display
{
    // @0x1424474d0
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::addChild(Instances::fl_display::DisplayObject* a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        addChild(result, a0);
        return result;
    }

    // @0x142447640
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::addChildAt(Instances::fl_display::DisplayObject* a0, SInt32 a1)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        addChildAt(result, a0, a1);
        return result;
    }

    // @0x142447e30
    SPtr<Instances::fl_system::ApplicationDomain> LoaderInfo::applicationDomainGet()
    {
        SPtr<Instances::fl_system::ApplicationDomain> result;
        applicationDomainGet(result);
        return result;
    }

    // @0x142449930
    SPtr<Instances::fl_display::Scene> MovieClip::currentSceneGet()
    {
        SPtr<Instances::fl_display::Scene> result;
        currentSceneGet(result);
        return result;
    }

    // The scene holding the current frame; a sprite that is not a movie gets one scene of itself.
    // @0x142449950
    SF_NOINLINE void MovieClip::currentSceneGet(SPtr<Instances::fl_display::Scene>& result)
    {
        result = NULL;
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        if (psprite->pDef->GetType() == CharacterDef::MovieData)
        {
            unsigned frame = psprite->GetCurrentFrame();
            UPInt count = 0;
            const MovieDataDef::SceneInfo* pscenes = psprite->GetResourceMovieDef()->GetDataDef()->GetScenes(&count);
            for (UPInt i = 0; i < count; ++i)
            {
                if (frame >= pscenes[i].Offset && frame < pscenes[i].Offset + pscenes[i].NumFrames)
                {
                    asvm.ConstructInstance(result, GetVM().GetClass(StringDataPtr("flash.display.Scene")));
                    result->SceneInfo = &pscenes[i];
                    return;
                }
            }
        }
        else
        {
            ASVM& vm = static_cast<ASVM&>(GetVM());
            Class* cls = vm.GetClass(StringDataPtr("flash.display.Scene"));
            SPtr<Instances::fl_display::Scene> scene;
            vm.ConstructInstance(scene, cls);
            scene->SpriteObj = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
            result = scene;
        }
    }

    // @0x142449de0
    SPtr<Instances::fl_display::DisplayObject> SimpleButton::downStateGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        downStateGet(result);
        return result;
    }

    // @0x14244b850
    SPtr<Instances::fl_display::DisplayObject> Sprite::dropTargetGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        dropTargetGet(result);
        return result;
    }

    // An Array of flash.filters objects, each holding a copy of one of the display object's filters (null for the
    // filter types AS3 has no class for).
    // MS2-FUNCTIONAL: register allocation / frame (exe keeps the loop state in r13-r15 under an rbp frame)
    // @0x14244bb80
    void DisplayObject::filtersGet(SPtr<Instances::fl::Array>& result)
    {
        Pickable<Instances::fl::Array> arr = GetVM().MakeArray();
        const Render::FilterSet* filters = pDispObj->GetFilters();
        if (filters && filters->GetFilterCount())
        {
            for (unsigned i = 0; i < filters->GetFilterCount(); ++i)
            {
                const Render::Filter* filter = filters->GetFilter(i);
                SPtr<Instances::fl::Object> pobj;
                const char* name;
                switch (filter->GetFilterType())
                {
                case Render::Filter_Blur:        name = "flash.filters.BlurFilter"; break;
                case Render::Filter_Shadow:      name = "flash.filters.DropShadowFilter"; break;
                case Render::Filter_Glow:        name = "flash.filters.GlowFilter"; break;
                case Render::Filter_Bevel:       name = "flash.filters.BevelFilter"; break;
                case Render::Filter_ColorMatrix: name = "flash.filters.ColorMatrixFilter"; break;
                default:
                    arr->SA.PushBack(Value((ASStringNode*)NULL));
                    continue;
                }
                if (GetVM().ConstructBuiltinObject(pobj, name))
                {
                    Ptr<Render::Filter> copy = *filter->Clone();
                    static_cast<Instances::fl_filters::BitmapFilter*>(pobj.GetPtr())->SetFilterData(copy);
                    arr->SA.PushBack(Value(pobj));
                }
            }
        }
        result = arr;
    }

    // A new filter set from copies of the filters held by the flash.filters objects in filters (other entries are
    // ignored).
    // MS2-FUNCTIONAL: register allocation; the exe inlines FilterSet::AddFilter only on the GlowFilter path
    // @0x14244bdd0
    void DisplayObject::filtersSet(const Value& result, Instances::fl::Array* filters)
    {
        SF_UNUSED(result);
        Ptr<Render::FilterSet> set = *SF_NEW Render::FilterSet();
        if (filters)
        {
            for (UPInt i = 0; i < filters->SA.GetSize(); ++i)
            {
                Instances::fl_filters::BitmapFilter* pfilter =
                    static_cast<Instances::fl_filters::BitmapFilter*>(filters->SA.At(i).GetObject());
                ASString name = pfilter->GetTraits().GetName();
                const char* pname = name.ToCStr();
                if (!strcmp(pname, "GlowFilter"))
                {
                    Ptr<Render::Filter> copy = *pfilter->GetFilterData()->Clone(GetVM().GetMemoryHeap());
                    set->AddFilter(copy);
                }
                else if (!strcmp(pname, "BevelFilter") || !strcmp(pname, "DropShadowFilter") ||
                         !strcmp(pname, "BlurFilter") || !strcmp(pname, "ColorMatrixFilter"))
                {
                    Ptr<Render::Filter> copy = *pfilter->GetFilterData()->Clone(GetVM().GetMemoryHeap());
                    set->AddFilter(copy);
                }
            }
        }
        pDispObj->SetFilters(set);
    }

    // @0x14244bb60
    SPtr<Instances::fl::Array> DisplayObject::filtersGet()
    {
        SPtr<Instances::fl::Array> result;
        filtersGet(result);
        return result;
    }

    // @0x14244c060
    SPtr<Instances::fl_display::InteractiveObject> Stage::focusGet()
    {
        SPtr<Instances::fl_display::InteractiveObject> result;
        focusGet(result);
        return result;
    }

    // @0x14244c570
    SPtr<Instances::fl_geom::Rectangle> BitmapData::generateFilterRect(Instances::fl_geom::Rectangle* a0, Instances::fl_filters::BitmapFilter* a1)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        generateFilterRect(result, a0, a1);
        return result;
    }

#pragma strict_gs_check(push, on)
    // The area a filter would cover when applied to sourceRect, as a new Rectangle in whole pixels.
    // MS2-FUNCTIONAL: frame 0x10 smaller (the exe saves rdi inside its own frame instead of the home area); same code otherwise
    // @0x14244c590
    SF_NOINLINE void BitmapData::generateFilterRect(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_geom::Rectangle* sourceRect, Instances::fl_filters::BitmapFilter* filter)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!sourceRect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceRect"));
        }
        else if (!filter)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "filter"));
        }
        else
        {
            RectF bounds(0);
            RectF src((float)(SInt32)sourceRect->x, (float)(SInt32)sourceRect->y,
                      (float)(SInt32)(sourceRect->x + sourceRect->width), (float)(SInt32)(sourceRect->y + sourceRect->height));
            RectF twips(Render::PixelsToTwips(src.x1), Render::PixelsToTwips(src.y1), Render::PixelsToTwips(src.x2), Render::PixelsToTwips(src.y2));
            Render::DrawableImage::CalcFilterRect(&bounds, Render::Rect<SInt32>((SInt32)twips.x1, (SInt32)twips.y1, (SInt32)twips.x2, (SInt32)twips.y2),
                                                  filter->GetFilterData());
            Value args[4];
            args[0].SetNumber(Alg::IRound(Render::TwipsToPixels(bounds.x1)));
            args[1].SetNumber(Alg::IRound(Render::TwipsToPixels(bounds.y1)));
            args[2].SetNumber(Alg::IRound(Render::TwipsToPixels(bounds.Width())));
            args[3].SetNumber(Alg::IRound(Render::TwipsToPixels(bounds.Height())));
            ASVM& asvm = static_cast<ASVM&>(GetVM());
            asvm.ConstructInstance(result, asvm.RectangleClass, 4, args);
        }
    }
#pragma strict_gs_check(pop)

    // @0x14244c8f0
    SPtr<Instances::fl_geom::Rectangle> DisplayObject::getBounds(Instances::fl_display::DisplayObject* a0)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        getBounds(result, a0);
        return result;
    }

#pragma strict_gs_check(push, on)
    // The bounds in the target's space (or our own without one) as a new Rectangle in pixels. Like Flash, the
    // local box is taken first and only then mapped through (our world matrix, then the target's inverse).
    // @0x14244c910
    SF_NOINLINE void DisplayObject::getBounds(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_display::DisplayObject* target)
    {
        RectF b(0);
        Matrix2F m;
        if (target && target != this)
        {
            Matrix2F world;
            target->pDispObj->GetWorldMatrix(&world);
            m.SetInverse(world);
            world = Matrix2F();
            pDispObj->GetWorldMatrix(&world);
            m.Prepend(world);
        }
        m.EncloseTransform(&b, pDispObj->GetBounds(Matrix2F()));
        b.x1 = Render::TwipsToPixels(b.x1);
        b.y1 = Render::TwipsToPixels(b.y1);
        b.x2 = Render::TwipsToPixels(b.x2);
        b.y2 = Render::TwipsToPixels(b.y2);
        Value args[] = { Value(b.x1), Value(b.y1), Value(b.Width()), Value(b.Height()) };
        Value r;
        static_cast<ASVM&>(GetVM()).RectangleClass->Construct(r, 4, args, true);
        result = static_cast<Instances::fl_geom::Rectangle*>(r.GetObject());
    }
#pragma strict_gs_check(pop)

    // @0x14244cc80
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::getChildAt(SInt32 a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        getChildAt(result, a0);
        return result;
    }

    // @0x14244cdc0
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::getChildByName(const ASString& a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        getChildByName(result, a0);
        return result;
    }

    // @0x14244cfb0
    SPtr<Instances::fl_geom::Rectangle> BitmapData::getColorBoundsRect(UInt32 a0, UInt32 a1, bool a2)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        getColorBoundsRect(result, a0, a1, a2);
        return result;
    }

    // @0x14244d1c0
    SPtr<Instances::fl::Array> DisplayObjectContainer::getObjectsUnderPoint(Instances::fl_geom::Point* a0)
    {
        SPtr<Instances::fl::Array> result;
        getObjectsUnderPoint(result, a0);
        return result;
    }

    // @0x14244d540
    SPtr<Instances::fl_utils::ByteArray> BitmapData::getPixels(Instances::fl_geom::Rectangle* a0)
    {
        SPtr<Instances::fl_utils::ByteArray> result;
        getPixels(result, a0);
        return result;
    }

    // @0x14244d740
    SPtr<Instances::fl_geom::Rectangle> DisplayObject::getRect(Instances::fl_display::DisplayObject* a0)
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        getRect(result, a0);
        return result;
    }

#pragma strict_gs_check(push, on)
    // The bounds without strokes in the target's space (or our own without one) as a new Rectangle in pixels. Like Flash, the
    // local box is taken first and only then mapped through (our world matrix, then the target's inverse).
    // @0x14244d760
    SF_NOINLINE void DisplayObject::getRect(SPtr<Instances::fl_geom::Rectangle>& result, Instances::fl_display::DisplayObject* target)
    {
        RectF b(0);
        Matrix2F m;
        if (target && target != this)
        {
            Matrix2F world;
            target->pDispObj->GetWorldMatrix(&world);
            m.SetInverse(world);
            world = Matrix2F();
            pDispObj->GetWorldMatrix(&world);
            m.Prepend(world);
        }
        m.EncloseTransform(&b, pDispObj->GetRectBounds(Matrix2F()));
        b.x1 = Render::TwipsToPixels(b.x1);
        b.y1 = Render::TwipsToPixels(b.y1);
        b.x2 = Render::TwipsToPixels(b.x2);
        b.y2 = Render::TwipsToPixels(b.y2);
        Value args[] = { Value(b.x1), Value(b.y1), Value(b.Width()), Value(b.Height()) };
        Value r;
        static_cast<ASVM&>(GetVM()).RectangleClass->Construct(r, 4, args, true);
        result = static_cast<Instances::fl_geom::Rectangle*>(r.GetObject());
    }
#pragma strict_gs_check(pop)

    // @0x14244dad0
    SPtr<Instances::fl_vec::Vector_uint> BitmapData::getVector(Instances::fl_geom::Rectangle* a0)
    {
        SPtr<Instances::fl_vec::Vector_uint> result;
        getVector(result, a0);
        return result;
    }

    // @0x14244dd00
    SPtr<Instances::fl_geom::Vector3D> DisplayObject::globalToLocal3D(Instances::fl_geom::Point* a0)
    {
        SPtr<Instances::fl_geom::Vector3D> result;
        globalToLocal3D(result, a0);
        return result;
    }

#pragma strict_gs_check(push, on)
    // A new Vector3D (pixels) through the movie VM's Vector3D class.
    // MS2-FUNCTIONAL: stack slot order differs (exe puts the input point and the result Value below the returned
    // Point3F temp); same code otherwise
    // @0x14244dd20
    SF_NOINLINE void DisplayObject::globalToLocal3D(SPtr<Instances::fl_geom::Vector3D>& result, Instances::fl_geom::Point* pt)
    {
        PointF global((float)Render::PixelsToTwips(pt->x), (float)Render::PixelsToTwips(pt->y));
        Render::Point3F local;
        local = pDispObj->GlobalToLocal3D(global);
        Value args[] = { Value(Render::TwipsToPixels(local.x)), Value(Render::TwipsToPixels(local.y)), Value(Render::TwipsToPixels(local.z)) };
        Value r;
        static_cast<ASVM&>(GetVM()).Vector3DClass->Construct(r, 3, args, true);
        result = static_cast<Instances::fl_geom::Vector3D*>(r.GetObject());
    }
#pragma strict_gs_check(pop)

    // @0x14244df20
    SPtr<Instances::fl_geom::Point> DisplayObject::globalToLocal(Instances::fl_geom::Point* a0)
    {
        SPtr<Instances::fl_geom::Point> result;
        globalToLocal(result, a0);
        return result;
    }

    // A new Point (pixels) through the movie VM's Point class.
    // @0x14244df40
    SF_NOINLINE void DisplayObject::globalToLocal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* pt)
    {
        PointF global((float)Render::PixelsToTwips(pt->x), (float)Render::PixelsToTwips(pt->y));
        PointF local;
        local = pDispObj->GlobalToLocal(global);
        Value args[] = { Value(Render::TwipsToPixels(local.x)), Value(Render::TwipsToPixels(local.y)) };
        Value r;
        static_cast<ASVM&>(GetVM()).PointClass->Construct(r, 2, args, true);
        result = static_cast<Instances::fl_geom::Point*>(r.GetObject());
    }

    // @0x14244e2c0
    SPtr<Instances::fl_display::Graphics> Shape::graphicsGet()
    {
        SPtr<Instances::fl_display::Graphics> result;
        graphicsGet(result);
        return result;
    }

    // @0x14244e3a0
    SPtr<Instances::fl_display::Graphics> Sprite::graphicsGet()
    {
        SPtr<Instances::fl_display::Graphics> result;
        graphicsGet(result);
        return result;
    }

    // @0x14244f480
    SPtr<Instances::fl_display::DisplayObject> SimpleButton::hitTestStateGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        hitTestStateGet(result);
        return result;
    }

    // @0x14244f590
    SPtr<Instances::fl::Array> Scene::labelsGet()
    {
        SPtr<Instances::fl::Array> result;
        labelsGet(result);
        return result;
    }

    // The scene's frame labels as a new Array of FrameLabel objects (frames counted from 1 within the scene). A
    // sprite scene has no scene info: its labels are gathered frame by frame from the sprite's timeline.
    // MS2-FUNCTIONAL: register allocation (rsi/rdi swapped) and load scheduling of the label pointer; same calls and logic
    // @0x14244f5b0
    SF_NOINLINE void Scene::labelsGet(SPtr<Instances::fl::Array>& result)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        result = GetVM().MakeArray();
        Class* labelClass = GetVM().GetClass(StringDataPtr("flash.display.FrameLabel"));
        if (SceneInfo)
        {
            for (UPInt i = 0, n = SceneInfo->Labels.GetSize(); i < n; ++i)
            {
                SPtr<Instances::fl_display::FrameLabel> label;
                asvm.ConstructInstance(label, labelClass);
                const MovieDataDef::FrameLabelInfo& info = SceneInfo->Labels[i];
                label->FrameNumber = info.Number - SceneInfo->Offset + 1;
                label->FrameName.AssignNode(label->FrameName.GetManager()->CreateStringNode(info.Name.ToCStr(), info.Name.GetSize()));
                result->SA.PushBack(Value(label));
            }
        }
        else
        {
            unsigned frames = SpriteObj->pDef->GetFrameCount();
            Array<String> names;
            for (unsigned i = 0; i < frames; ++i)
            {
                if (SpriteObj->pDef->GetFrameLabels(i, &names))
                {
                    for (UPInt j = 0, n = names.GetSize(); j < n; ++j)
                    {
                        SPtr<Instances::fl_display::FrameLabel> label;
                        asvm.ConstructInstance(label, labelClass);
                        ASString name = asvm.GetStringManager().CreateString(names[j].ToCStr());
                        label->FrameNumber = i + 1;
                        label->FrameName = name;
                        result->SA.PushBack(Value(label));
                    }
                    names.Clear();
                }
            }
        }
    }

    // @0x14244ff90
    SPtr<Instances::fl_display::LoaderInfo> DisplayObject::loaderInfoGet()
    {
        SPtr<Instances::fl_display::LoaderInfo> result;
        loaderInfoGet(result);
        return result;
    }

    // @0x1424500c0
    SPtr<Instances::fl_geom::Point> DisplayObject::local3DToGlobal(Instances::fl_geom::Vector3D* a0)
    {
        SPtr<Instances::fl_geom::Point> result;
        local3DToGlobal(result, a0);
        return result;
    }

    // A new Point (pixels) through the movie VM's Point class.
    // @0x1424500e0
    SF_NOINLINE void DisplayObject::local3DToGlobal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Vector3D* pt)
    {
        PointF global = pDispObj->Local3DToGlobal(Render::Point3F((float)Render::PixelsToTwips(pt->x),
            (float)Render::PixelsToTwips(pt->y), (float)Render::PixelsToTwips(pt->z)));
        Value args[] = { Value(Render::TwipsToPixels(global.x)), Value(Render::TwipsToPixels(global.y)) };
        Value r;
        static_cast<ASVM&>(GetVM()).PointClass->Construct(r, 2, args, true);
        result = static_cast<Instances::fl_geom::Point*>(r.GetObject());
    }

    // @0x1424502a0
    SPtr<Instances::fl_geom::Point> DisplayObject::localToGlobal(Instances::fl_geom::Point* a0)
    {
        SPtr<Instances::fl_geom::Point> result;
        localToGlobal(result, a0);
        return result;
    }

    // A new Point (pixels) through the movie VM's Point class.
    // @0x1424502c0
    SF_NOINLINE void DisplayObject::localToGlobal(SPtr<Instances::fl_geom::Point>& result, Instances::fl_geom::Point* pt)
    {
        PointF global = pDispObj->LocalToGlobal(PointF((float)Render::PixelsToTwips(pt->x), (float)Render::PixelsToTwips(pt->y)));
        Value args[] = { Value(Render::TwipsToPixels(global.x)), Value(Render::TwipsToPixels(global.y)) };
        Value r;
        static_cast<ASVM&>(GetVM()).PointClass->Construct(r, 2, args, true);
        result = static_cast<Instances::fl_geom::Point*>(r.GetObject());
    }

    // @0x142450e30
    SPtr<Instances::fl_display::DisplayObject> SimpleButton::overStateGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        overStateGet(result);
        return result;
    }

    // @0x142451240
    SPtr<Instances::fl_display::DisplayObjectContainer> DisplayObject::parentGet()
    {
        SPtr<Instances::fl_display::DisplayObjectContainer> result;
        parentGet(result);
        return result;
    }

    // @0x142451bf0
    SPtr<Instances::fl_geom::Rectangle> BitmapData::rectGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        rectGet(result);
        return result;
    }

#pragma strict_gs_check(push, on)
    // The bitmap's rect (0, 0, width, height) as a new Rectangle; the size is read unsigned.
    // @0x142451c10
    SF_NOINLINE void BitmapData::rectGet(SPtr<Instances::fl_geom::Rectangle>& result)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        Value args[4];
        args[0].SetNumber(Alg::IRound(0.0));
        args[1].SetNumber(Alg::IRound(0.0));
        args[2].SetNumber(Alg::IRound((double)(UInt32)Width));
        args[3].SetNumber(Alg::IRound((double)(UInt32)Height));
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        asvm.ConstructInstance(result, asvm.RectangleClass, 4, args);
    }
#pragma strict_gs_check(pop)

    // @0x142451ed0
    SPtr<Instances::fl_display::DisplayObject> DisplayObjectContainer::removeChildAt(SInt32 a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        removeChildAt(result, a0);
        return result;
    }

    // @0x142452270
    SPtr<Instances::fl_geom::Rectangle> DisplayObject::scale9GridGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        scale9GridGet(result);
        return result;
    }

#pragma strict_gs_check(push, on)
    // A new Rectangle (pixels) through the movie VM's Rectangle class, or null without a grid.
    // MS2-FUNCTIONAL: the grid temp sits in a different stack slot (exe: above the result Value); same code otherwise
    // @0x142452290
    SF_NOINLINE void DisplayObject::scale9GridGet(SPtr<Instances::fl_geom::Rectangle>& result)
    {
        if (!pDispObj->GetScale9Grid().IsEmpty())
        {
            RectF grid = pDispObj->GetScale9Grid();
            Value args[] = { Value(Render::TwipsToPixels(grid.x1)), Value(Render::TwipsToPixels(grid.y1)),
                             Value(Render::TwipsToPixels(grid.Width())), Value(Render::TwipsToPixels(grid.Height())) };
            Value r;
            static_cast<ASVM&>(GetVM()).RectangleClass->Construct(r, 4, args, true);
            result = static_cast<Instances::fl_geom::Rectangle*>(r.GetObject());
        }
        else
            result = NULL;
    }
#pragma strict_gs_check(pop)

    // @0x142452750
    SPtr<Instances::fl::Array> MovieClip::scenesGet()
    {
        SPtr<Instances::fl::Array> result;
        scenesGet(result);
        return result;
    }

    // One Scene per scene of the movie; a sprite that is not a movie has one scene of itself.
    // @0x142452770
    SF_NOINLINE void MovieClip::scenesGet(SPtr<Instances::fl::Array>& result)
    {
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        result = asvm.MakeArray();
        if (psprite->pDef->GetType() == CharacterDef::MovieData)
        {
            UPInt count = 0;
            const MovieDataDef::SceneInfo* pscenes = psprite->GetResourceMovieDef()->GetDataDef()->GetScenes(&count);
            Class* cls = GetVM().GetClass(StringDataPtr("flash.display.Scene"));
            for (UPInt i = 0; i < count; ++i)
            {
                SPtr<Instances::fl_display::Scene> scene;
                asvm.ConstructInstance(scene, cls);
                scene->SceneInfo = &pscenes[i];
                result->SA.PushBack(Value(scene));
            }
        }
        else
        {
            ASVM& vm = static_cast<ASVM&>(GetVM());
            Class* cls = vm.GetClass(StringDataPtr("flash.display.Scene"));
            SPtr<Instances::fl_display::Scene> scene;
            vm.ConstructInstance(scene, cls);
            scene->SpriteObj = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
            result->SA.PushBack(Value(scene));
        }
    }

    // @0x142452a60
    SPtr<Instances::fl_geom::Rectangle> DisplayObject::scrollRectGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        scrollRectGet(result);
        return result;
    }

#pragma strict_gs_check(push, on)
    // @0x142452a80
    SF_NOINLINE void DisplayObject::scrollRectGet(SPtr<Instances::fl_geom::Rectangle>& result)
    {
        GFx::DisplayObject::ScrollRectInfo* psr = pDispObj->pScrollRect;
        if (psr)
        {
            const Render::RectD& r = psr->Rectangle;
            Value args[4];
            args[0].SetNumber(Alg::IRound(r.x1 * 0.05));
            args[1].SetNumber(Alg::IRound(r.y1 * 0.05));
            args[2].SetNumber(Alg::IRound((r.x2 - r.x1) * 0.05));
            args[3].SetNumber(Alg::IRound((r.y2 - r.y1) * 0.05));
            ASVM& asvm = static_cast<ASVM&>(GetVM());
            asvm.ConstructInstance(result, asvm.RectangleClass, 4, args);
        }
        else
            result = NULL;
    }
#pragma strict_gs_check(pop)

    // @0x142453470
    SPtr<Instances::fl_display::Stage> DisplayObject::stageGet()
    {
        SPtr<Instances::fl_display::Stage> result;
        stageGet(result);
        return result;
    }

    // @0x142453cf0
    SPtr<Instances::fl_text::TextSnapshot> DisplayObjectContainer::textSnapshotGet()
    {
        SPtr<Instances::fl_text::TextSnapshot> result;
        textSnapshotGet(result);
        return result;
    }

    // @0x142454380
    SPtr<Instances::fl_geom::Transform> DisplayObject::transformGet()
    {
        SPtr<Instances::fl_geom::Transform> result;
        transformGet(result);
        return result;
    }

    // @0x1424546e0
    SPtr<Instances::fl_display::DisplayObject> SimpleButton::upStateGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        upStateGet(result);
        return result;
    }
}}

// ---- flash.display: small natives ----

namespace Instances { namespace fl_display
{
    // @0x142449cf0
    void BitmapData::dispose(const Value& result)
    {
        SF_UNUSED(result);
        pImage = NULL;
        Width = 0;
        Height = 0;
    }

    // @0x1424496a0
    void MovieClip::currentFrameGet(SInt32& result)
    {
        if (!pDispObj)
            result = 0;
        else
            result = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr())->GetCurrentFrame() + 1;
    }

    // MS2-FUNCTIONAL: the exe inlines FrameScript::Descr's copy constructor into the PushBack
    // @0x1424478a0
    void MovieClip::addFrameScript(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        if (!pDispObj)
            CreateStageObject();
        GFx::Sprite* psprite = pDispObj->IsSprite() ? static_cast<GFx::Sprite*>(pDispObj.GetPtr()) : NULL;
        if (!psprite)
            return;
        AvmDisplayObj* pavm = reinterpret_cast<AvmDisplayObj*>(psprite->GetAvmObjImpl());

        // (frame, function) pairs; frames that do not convert are skipped.
        ArrayCPP<FrameScript::Descr> descrs;
        const unsigned pairCnt = argc >> 1;
        for (unsigned i = 0, j = 0; i < pairCnt; ++i, j += 2)
        {
            SInt32 frame;
            if (argv[j].Convert2Int32(frame))
                descrs.PushBack(FrameScript::Descr(argv[j + 1], frame));
        }
        frameScript.Set(FUN_14250a5c0(pavm), psprite->pDef->GetFrameCount(), (unsigned)descrs.GetSize(),
                        descrs.GetDataPtr());
        if (frameScript.Get(psprite->GetCurrentFrame()))
        {
            // AvmSprite flags (+0x60) bit 1: a frame script is pending for the current frame.
            reinterpret_cast<UByte*>(pavm)[0x60] |= 2;
            if (psprite->IsInPlayList())
                psprite->AddToOptimizedPlayList();
        }
    }

    // Shared by gotoAndPlay/gotoAndStop: moves to the frame and runs the queued frame actions right away.
    static SF_FORCEINLINE void GotoFrameAndRun(MovieClip* pthis, const Value& frame, const Value& scene, PlayState state)
    {
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pthis->pDispObj.GetPtr());
        unsigned targetFrame;
        if (frame.IsString())
        {
            if (!FUN_142444050(pthis, psprite, frame, scene, &targetFrame))
                return;
        }
        else
        {
            UInt32 r;
            if (!frame.Convert2UInt32(r))
                return;
            targetFrame = r - 1;
        }
        ASVM& vm = static_cast<ASVM&>(pthis->GetVM());
        if (targetFrame != psprite->GetCurrentFrame())
        {
            // gotoAnd... drops the frame actions already queued for this clip
            FUN_142522490(vm.GetMovieRoot(), 3, pthis->pDispObj);
            psprite->GotoFrame(targetFrame);
        }
        psprite->SetPlayState(state);
        FUN_142520080(vm.GetMovieRoot());
        for (unsigned level = 0; level < 4; ++level)
            FUN_1424fa320(vm.GetMovieRoot(), level);
    }

    // @0x14244e0e0
    void MovieClip::gotoAndPlay(const Value& result, const Value& frame, const Value& scene)
    {
        SF_UNUSED(result);
        GotoFrameAndRun(this, frame, scene, State_Playing);
    }

    // @0x14244e1d0
    void MovieClip::gotoAndStop(const Value& result, const Value& frame, const Value& scene)
    {
        SF_UNUSED(result);
        GotoFrameAndRun(this, frame, scene, State_Stopped);
    }

    // @0x142452450
    void DisplayObject::scale9GridSet(const Value& result, Instances::fl_geom::Rectangle* value)
    {
        SF_UNUSED(result);
        if (value)
        {
            Render::RectF grid;
            grid.x1 = Render::PixelsToTwips(float(value->x));
            grid.y1 = Render::PixelsToTwips(float(value->y));
            grid.SetWidth(Render::PixelsToTwips(float(value->width)));
            grid.SetHeight(Render::PixelsToTwips(float(value->height)));
            pDispObj->SetScale9Grid(grid);
        }
        else
            pDispObj->SetScale9Grid(Render::RectF(0));
    }

    // @0x142453d10
    SF_NOINLINE void DisplayObjectContainer::textSnapshotGet(SPtr<Instances::fl_text::TextSnapshot>& result)
    {
        ASVM& vm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_text::TextSnapshot> psnapshot;
        SPtr<Class> cls = vm.GetClass(StringDataPtr("flash.text.TextSnapshot"));
        vm.ConstructInstance(psnapshot, cls);
        // the snapshot data (TextSnapshot +0x38) is filled from the sprite's static text
        FUN_1425db410(pDispObj, reinterpret_cast<UByte*>(psnapshot.GetPtr()) + 0x38);
        result = psnapshot;
    }

    // @0x14244f9a0
    void Graphics::lineGradientStyle(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        FUN_142441010(this, argc, argv, pDrawing->CreateLineComplexFill());
    }

    // lineStyle(thickness, color, alpha, pixelHinting, scaleMode, caps, joints, miterLimit): no arguments leaves the
    // line style alone. The stroke flags: scaling "vertical"/"horizontal"/"none" (else normal), caps "none"/"square"
    // (else round, both ends), joints "miter"/"bevel" (else round).
    // @0x14244f9e0
    void Graphics::lineStyle(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        Value::Number num = 0;
        UInt32 rgb = 0;
        float alpha = 1.0f;
        float miterLimit = 3.0f;
        bool hinting = false;
        unsigned scaling = 0, caps = 0, joints = 0;
        if (argc == 0)
            return;
        if (!argv[0].Convert2Number(num))
            return;
        float thickness = float(num);
        if (argc > 1 && !argv[1].Convert2UInt32(rgb))
            return;
        if (argc > 2)
        {
            if (!argv[2].Convert2Number(num))
                return;
            alpha = float(num);
        }
        if (argc > 3)
            hinting = argv[3].Convert2Boolean();
        if (argc > 4)
        {
            ASString str = GetVM().GetStringManager().CreateEmptyString();
            if (!argv[4].Convert2String(str))
                return;
            if (!strcmp(str.ToCStr(), "vertical"))
                scaling = Render::StrokeScaling_Vertical;
            else if (!strcmp(str.ToCStr(), "horizontal"))
                scaling = Render::StrokeScaling_Horizontal;
            else if (!strcmp(str.ToCStr(), "none"))
                scaling = Render::StrokeScaling_None;
        }
        if (argc > 5)
        {
            ASString str = GetVM().GetStringManager().CreateEmptyString();
            if (!argv[5].Convert2String(str))
                return;
            if (!strcmp(str.ToCStr(), "none"))
                caps = 0x140;   // no start / end cap
            else if (!strcmp(str.ToCStr(), "square"))
                caps = 0x280;   // square start / end cap
        }
        if (argc > 6)
        {
            ASString str = GetVM().GetStringManager().CreateEmptyString();
            if (!argv[6].Convert2String(str))
                return;
            if (!strcmp(str.ToCStr(), "miter"))
                joints = 0x20;
            else if (!strcmp(str.ToCStr(), "bevel"))
                joints = 0x10;
        }
        if (argc > 7)
        {
            if (!argv[7].Convert2Number(num))
                return;
            miterLimit = float(num);
        }
        pDrawing->ChangeLineStyle(thickness * 20.0f, (UInt32(alpha * 255.0f) << 24) | (rgb & 0xFFFFFF), hinting,
                                  scaling, caps, joints, miterLimit);
    }

    // @0x142448460
    void Graphics::beginGradientFill(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        FUN_142441010(this, argc, argv, pDrawing->CreateNewComplexFill());
        pDrawing->BeginFill();
    }

    // MS2-FUNCTIONAL: register allocation (exe computes the fill type into rbx before AcquirePath; ours folds it after)
    // @0x1424482e0
    void Graphics::beginBitmapFill(const Value& result, Instances::fl_display::BitmapData* bitmap,
                                   Instances::fl_geom::Matrix* matrix, bool repeat, bool smooth)
    {
        SF_UNUSED(result);
        if (!bitmap)
            return;
        ImageResource* pimageRes = bitmap->GetImageResource();
        if (pimageRes)
        {
            Render::Matrix2F mtx;
            if (matrix)
                mtx = matrix->GetMatrixF();
            FillType fillType;
            if (smooth)
                fillType = repeat ? Fill_TiledSmoothImage : Fill_ClippedSmoothImage;
            else
                fillType = repeat ? Fill_TiledImage : Fill_ClippedImage;
            pDrawing->AcquirePath(true);
            pDrawing->BeginBitmapFill(fillType, pimageRes, mtx);
        }
    }

    // An ellipse around (cx, cy) as eight quadratic curves (control points on the tangents at
    // 45 degree steps), in twips.
    static const float GraphicsTanPi8 = 0.41421356f;  // tan(pi/8)
    static const float GraphicsSinPi4 = 0.70710677f;  // sin(pi/4)
    static SF_INLINE void GraphicsDrawEllipse(Ptr<DrawingContext>& pdrawing, float cx, float cy, float rx, float ry)
    {
        pdrawing->MoveTo((cx + rx) * 20.0f, cy * 20.0f);
        pdrawing->CurveTo((cx + rx) * 20.0f, (cy + GraphicsTanPi8 * ry) * 20.0f,
                          (cx + GraphicsSinPi4 * rx) * 20.0f, (cy + GraphicsSinPi4 * ry) * 20.0f);
        pdrawing->CurveTo((cx + GraphicsTanPi8 * rx) * 20.0f, (cy + ry) * 20.0f,
                          cx * 20.0f, (cy + ry) * 20.0f);
        pdrawing->CurveTo((cx - GraphicsTanPi8 * rx) * 20.0f, (cy + ry) * 20.0f,
                          (cx - GraphicsSinPi4 * rx) * 20.0f, (cy + GraphicsSinPi4 * ry) * 20.0f);
        pdrawing->CurveTo((cx - rx) * 20.0f, (cy + GraphicsTanPi8 * ry) * 20.0f,
                          (cx - rx) * 20.0f, cy * 20.0f);
        pdrawing->CurveTo((cx - rx) * 20.0f, (cy - GraphicsTanPi8 * ry) * 20.0f,
                          (cx - GraphicsSinPi4 * rx) * 20.0f, (cy - GraphicsSinPi4 * ry) * 20.0f);
        pdrawing->CurveTo((cx - GraphicsTanPi8 * rx) * 20.0f, (cy - ry) * 20.0f,
                          cx * 20.0f, (cy - ry) * 20.0f);
        pdrawing->CurveTo((cx + GraphicsTanPi8 * rx) * 20.0f, (cy - ry) * 20.0f,
                          (cx + GraphicsSinPi4 * rx) * 20.0f, (cy - GraphicsSinPi4 * ry) * 20.0f);
        pdrawing->CurveTo((cx + rx) * 20.0f, (cy - GraphicsTanPi8 * ry) * 20.0f,
                          (cx + rx) * 20.0f, cy * 20.0f);
    }

    // MS2-FUNCTIONAL: xmm register allocation of the inlined ellipse expansion
    // @0x14244a2e0
    void Graphics::drawCircle(const Value& result, Value::Number x, Value::Number y, Value::Number radius)
    {
        SF_UNUSED(result);
        GraphicsDrawEllipse(pDrawing, float(x), float(y), float(radius), float(radius));
        pDispObj->InvalidateHitResult();
    }

    // MS2-FUNCTIONAL: xmm register allocation of the inlined ellipse expansion
    // @0x14244a5c0
    void Graphics::drawEllipse(const Value& result, Value::Number x, Value::Number y,
                               Value::Number width, Value::Number height)
    {
        SF_UNUSED(result);
        float rx = float(width) * 0.5f;
        float ry = float(height) * 0.5f;
        GraphicsDrawEllipse(pDrawing, float(x) + rx, float(y) + ry, rx, ry);
        pDispObj->InvalidateHitResult();
    }

    // @0x14244a900
    void Graphics::drawRect(const Value& result, Value::Number x, Value::Number y,
                            Value::Number width, Value::Number height)
    {
        SF_UNUSED(result);
        if (NumberUtil::IsNaN(width))
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "width"));
            return;
        }
        if (NumberUtil::IsNaN(height))
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "height"));
            return;
        }
        float x1 = float(x * 20.0);
        float x2 = float((x + width) * 20.0);
        float y1 = float(y * 20.0);
        float y2 = float((y + height) * 20.0);
        pDrawing->MoveTo(x1, y1);
        pDrawing->LineTo(x2, y1);
        pDrawing->LineTo(x2, y2);
        pDrawing->LineTo(x1, y2);
        pDrawing->LineTo(x1, y1);
        pDispObj->InvalidateHitResult();
    }

    // A rectangle with elliptic corners (radii clamped to half the size), in twips.
    // MS2-FUNCTIONAL: the exe splits the body into a chained-unwind chunk (shrink-wrapped xmm saves); register allocation
    // @0x14244aae0
    void Graphics::drawRoundRect(const Value& result, Value::Number x, Value::Number y,
                                 Value::Number width, Value::Number height,
                                 Value::Number ellipseWidth, Value::Number ellipseHeight)
    {
        SF_UNUSED(result);
        if (NumberUtil::IsNaN(width))
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "width"));
            return;
        }
        if (NumberUtil::IsNaN(height))
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "height"));
            return;
        }
        if (NumberUtil::IsNaN(ellipseWidth))
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "ellipseWidth"));
            return;
        }
        if (NumberUtil::IsNaN(ellipseHeight))
            ellipseHeight = ellipseWidth;

        float left   = float(x);
        float top    = float(y);
        float right  = left + float(width);
        float bottom = top + float(height);
        float rx = Alg::Min(float(width) * 0.5f, float(ellipseWidth) * 0.5f);
        float ry = Alg::Min(float(height) * 0.5f, float(ellipseHeight) * 0.5f);
        float cx0 = right - rx, cy0 = bottom - ry;
        float cx1 = left + rx,  cy1 = top + ry;

        pDrawing->MoveTo(right * 20.0f, cy0 * 20.0f);
        pDrawing->CurveTo((cx0 + rx) * 20.0f, (cy0 + GraphicsTanPi8 * ry) * 20.0f,
                          (cx0 + GraphicsSinPi4 * rx) * 20.0f, (cy0 + GraphicsSinPi4 * ry) * 20.0f);
        pDrawing->CurveTo((cx0 + GraphicsTanPi8 * rx) * 20.0f, (cy0 + ry) * 20.0f,
                          cx0 * 20.0f, (cy0 + ry) * 20.0f);
        pDrawing->LineTo(cx1 * 20.0f, bottom * 20.0f);
        pDrawing->CurveTo((cx1 - GraphicsTanPi8 * rx) * 20.0f, (cy0 + ry) * 20.0f,
                          (cx1 - GraphicsSinPi4 * rx) * 20.0f, (cy0 + GraphicsSinPi4 * ry) * 20.0f);
        pDrawing->CurveTo((cx1 - rx) * 20.0f, (cy0 + GraphicsTanPi8 * ry) * 20.0f,
                          (cx1 - rx) * 20.0f, cy0 * 20.0f);
        pDrawing->LineTo(left * 20.0f, cy1 * 20.0f);
        pDrawing->CurveTo((cx1 - rx) * 20.0f, (cy1 - GraphicsTanPi8 * ry) * 20.0f,
                          (cx1 - GraphicsSinPi4 * rx) * 20.0f, (cy1 - GraphicsSinPi4 * ry) * 20.0f);
        pDrawing->CurveTo((cx1 - GraphicsTanPi8 * rx) * 20.0f, (cy1 - ry) * 20.0f,
                          cx1 * 20.0f, (cy1 - ry) * 20.0f);
        pDrawing->LineTo(cx0 * 20.0f, top * 20.0f);
        pDrawing->CurveTo((cx0 + GraphicsTanPi8 * rx) * 20.0f, (cy1 - ry) * 20.0f,
                          (cx0 + GraphicsSinPi4 * rx) * 20.0f, (cy1 - GraphicsSinPi4 * ry) * 20.0f);
        pDrawing->CurveTo((cx0 + rx) * 20.0f, (cy1 - GraphicsTanPi8 * ry) * 20.0f,
                          (cx0 + rx) * 20.0f, cy1 * 20.0f);
        pDispObj->InvalidateHitResult();
    }

    // @0x142450de0
    void Stage::orientationGet(ASString& result)
    {
        // GFx::Stage +0x120 (the GFx stage class is not recovered)
        result = *reinterpret_cast<const ASString*>(reinterpret_cast<UByte*>(pDispObj.GetPtr()) + 0x120);
    }

#pragma strict_gs_check(push, on)
    // MS2-FUNCTIONAL: exe uses an rbp frame and other registers (and keeps the source image in a cmov); same checks, filter-type switch and calls
    // @0x142447f10
    void BitmapData::applyFilter(const Value& result, Instances::fl_display::BitmapData* sourceBitmapData,
                                 Instances::fl_geom::Rectangle* sourceRect, Instances::fl_geom::Point* destPoint,
                                 Instances::fl_filters::BitmapFilter* filter)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        if (!sourceBitmapData)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceBitmapData"));
            return;
        }
        if (!sourceRect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceRect"));
            return;
        }
        if (!destPoint)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "destPoint"));
            return;
        }
        if (!filter)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "filter"));
            return;
        }

        Render::Filter* pfilter = filter->GetFilterData();
        Render::DrawableImage* psource = reinterpret_cast<Render::DrawableImage*>(sourceBitmapData->pImage.GetPtr());
        Render::DrawableImage* pdest = reinterpret_cast<Render::DrawableImage*>(this ? pImage.GetPtr() : NULL);
        Render::Rect<SInt32> r((SInt32)sourceRect->x, (SInt32)sourceRect->y,
                               (SInt32)(sourceRect->x + sourceRect->width), (SInt32)(sourceRect->y + sourceRect->height));
        Render::Point<SInt32> dp((SInt32)destPoint->x, (SInt32)destPoint->y);
        if (!pfilter)
        {
            GetVM().GetUI().Output(FlashUI::Output_Warning, "The method BitmapData::applyFilter (unsupported filter type) is not implemented\n");
            return;
        }

        // Filters that need an alpha channel can only write to a transparent image; a displacement map also needs
        // the source image to match it.
        bool transparent = pdest->IsTransparent();
        switch (pfilter->GetFilterType())
        {
        case Render::Filter_Blur:
        case Render::Filter_ColorMatrix:
            break;
        case Render::Filter_Shadow:
        case Render::Filter_Glow:
        case Render::Filter_Bevel:
            if (!transparent)
                goto failed;
            break;
        case Render::Filter_DisplacementMap:
        {
            bool sourceTransparent;
            sourceBitmapData->transparentGet(sourceTransparent);
            if (sourceTransparent != transparent)
                goto failed;
            break;
        }
        default:
            GetVM().GetUI().Output(FlashUI::Output_Warning, "The method BitmapData::applyFilter (unsupported filter type) is not implemented\n");
            return;
        }
        pdest->ApplyFilter(psource, r, dp, pfilter);
        return;

    failed:
        VM& vm = GetVM();
        vm.ThrowArgumentError(VM::Error(VM::eIllegalOperationError, vm,
                                        "This filter operation cannot be performed with the specified input parameters."));
    }
#pragma strict_gs_check(pop)

    // @0x1424529e0
    void BitmapData::scroll(const Value& result, SInt32 x, SInt32 y)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        FUN_1425eed00(pImage, x, y);
    }

#pragma strict_gs_check(push, on)
    // MS2-FUNCTIONAL: exe keeps pImage and this in registers across the cxform call (push rsi frame); ours reloads pImage after it; same checks and calls
    // @0x142448ba0
    void BitmapData::colorTransform(const Value& result, Instances::fl_geom::Rectangle* rect, Instances::fl_geom::ColorTransform* cTransform)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!rect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eIllegalOperationError, vm, "rect"));
        }
        else if (!cTransform)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eIllegalOperationError, vm, "colorTransform"));
        }
        else
        {
            Render::Cxform cxform = ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(cTransform);
            Render::ImageBase* pimage = this ? pImage.GetPtr() : NULL;
            Render::Rect<SInt32> r((SInt32)rect->x, (SInt32)rect->y, (SInt32)(rect->x + rect->width), (SInt32)(rect->y + rect->height));
            FUN_1425eb200(pimage, r, cxform);
        }
    }
#pragma strict_gs_check(pop)

#pragma strict_gs_check(push, on)
    // MS2-FUNCTIONAL: exe keeps this in rdx from the entry and picks the image (this-null cmov) before the rect; same loads and calls
    // @0x14244ba30
    void BitmapData::fillRect(const Value& result, Instances::fl_geom::Rectangle* rect, UInt32 color)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!rect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "rect"));
        }
        else
        {
            Render::ImageBase* pimage = this ? pImage.GetPtr() : NULL;
            Render::Rect<SInt32> r((SInt32)rect->x, (SInt32)rect->y, (SInt32)(rect->x + rect->width), (SInt32)(rect->y + rect->height));
            FUN_1425ec860(pimage, r, Render::Color(color));
        }
    }
#pragma strict_gs_check(pop)

    // @0x14244bfd0
    void BitmapData::floodFill(const Value& result, SInt32 x, SInt32 y, UInt32 color)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        // Color is the packed 32-bit value itself
        FUN_1425ec9e0(pImage, Render::Point<SInt32>(x, y), reinterpret_cast<const Render::Color&>(color));
    }

    // @0x142450cb0
    void BitmapData::noise(const Value& result, SInt32 randomSeed, UInt32 low, UInt32 high, UInt32 channelOptions, bool grayScale)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        FUN_1425eddc0(pImage, randomSeed, low, high, channelOptions, grayScale);
    }

    // threshold(sourceBitmapData, sourceRect, destPoint, operation, threshold[, color, mask, copySource]).
#pragma strict_gs_check(push, on)
    // MS2-FUNCTIONAL: stack slots of the converted arguments and the error temporaries; same code otherwise
    // @0x142453eb0
    void BitmapData::threshold(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        if (argc < 5)
            return;
        Instances::fl_display::BitmapData* sourceBitmapData = static_cast<Instances::fl_display::BitmapData*>(argv[0].GetObject());
        Instances::fl_geom::Point* destPoint = static_cast<Instances::fl_geom::Point*>(argv[2].GetObject());
        Instances::fl_geom::Rectangle* sourceRect = static_cast<Instances::fl_geom::Rectangle*>(argv[1].GetObject());
        if (!sourceBitmapData)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceBitmapData"));
            return;
        }
        if (!sourceRect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceRect"));
            return;
        }
        if (!destPoint)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "destPoint"));
            return;
        }

        ASString opstr = argv[3].AsString();
        const char* pop = opstr.ToCStr();
        Render::DrawableImage::ThresholdOperation op;
        if (!strcmp(pop, "<="))
            op = Render::DrawableImage::Operation_LessEqual;
        else if (!strcmp(pop, "<"))
            op = Render::DrawableImage::Operation_Less;
        else if (!strcmp(pop, ">"))
            op = Render::DrawableImage::Operation_Greater;
        else if (!strcmp(pop, ">="))
            op = Render::DrawableImage::Operation_GreaterEqual;
        else if (!strcmp(pop, "!="))
            op = Render::DrawableImage::Operation_NotEqual;
        else if (!strcmp(pop, "=="))
            op = Render::DrawableImage::Operation_Equal;
        else
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "The operation string is not a valid operation."));
            return;
        }

        UInt32 thresholdValue;
        UInt32 color = 0;
        UInt32 mask = 0xFFFFFFFF;
        bool copySource = true;
        if (!argv[4].Convert2UInt32(thresholdValue))
            return;
        if (argc >= 6 && !argv[5].Convert2UInt32(color))
            return;
        if (argc >= 7 && !argv[6].Convert2UInt32(mask))
            return;
        if (argc >= 8)
            copySource = argv[7].Convert2Boolean();
        reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr())->Threshold(sourceBitmapData->pImage,
            Render::Rect<SInt32>((SInt32)sourceRect->x, (SInt32)sourceRect->y,
                                 (SInt32)(sourceRect->x + sourceRect->width), (SInt32)(sourceRect->y + sourceRect->height)),
            Render::Point<SInt32>((SInt32)destPoint->x, (SInt32)destPoint->y), op, thresholdValue, color, mask, copySource);
    }
#pragma strict_gs_check(pop)

    // perlinNoise(baseX, baseY, numOctaves, randomSeed, stitch, fractalNoise[, channelOptions, grayScale, offsets]):
    // offsets is an array of flash.geom.Point, read as x / y float pairs (at most 128 floats).
    // @0x142451340
    void BitmapData::perlinNoise(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (argc < 6)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, vm, "BitmapData::perlinNoise"));
        }
        else
        {
            Value::Number baseX = 1.0, baseY = 1.0;
            UInt32 numOctaves = 1, randomSeed = 0;
            if (!argv[0].Convert2Number(baseX) || !argv[1].Convert2Number(baseY) ||
                !argv[2].Convert2UInt32(numOctaves) || !argv[3].Convert2UInt32(randomSeed))
                return;
            bool stitch = argv[4].Convert2Boolean();
            bool fractalNoise = argv[5].Convert2Boolean();
            UInt32 channelOptions = 7;
            if (argc >= 7 && !argv[6].Convert2UInt32(channelOptions))
                return;
            bool grayScale = (argc >= 8) ? argv[7].Convert2Boolean() : false;

            float* poffsets = NULL;
            unsigned offsetCount = 0;
            float offsets[128];
            if (argc >= 9 && argv[8].GetObject())
            {
                memset(offsets, 0, sizeof(offsets));
                poffsets = offsets;
                if (!FUN_1425145d0(GetVM(), Value(argv[8]), "Array"))
                    return;
                Instances::fl::Array* arr = static_cast<Instances::fl::Array*>(argv[8].GetObject());
                {
                    UInt32 len;
                    arr->lengthGet(len);
                    offsetCount = len * 2;
                }
                if (offsetCount > 128)
                    offsetCount = 128;
                for (unsigned i = 0; i < offsetCount; ++i)
                {
                    offsets[i * 2] = 0;
                    offsets[i * 2 + 1] = 0;
                    AS3::Object* pobj = arr->SA.At(i).GetObject();
                    if (FUN_1425145d0(GetVM(), Value(pobj), "flash.geom.Point"))
                    {
                        Instances::fl_geom::Point* pt = static_cast<Instances::fl_geom::Point*>(pobj);
                        offsets[i * 2] = (float)pt->x;
                        offsets[i * 2 + 1] = (float)pt->y;
                    }
                }
            }
            reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr())->PerlinNoise((float)baseX, (float)baseY, numOctaves, randomSeed,
                stitch, fractalNoise, channelOptions, grayScale, poffsets, offsetCount);
        }
    }

    // pixelDissolve(sourceBitmapData, sourceRect, destPoint, randomSeed, numPixels, fillColor).
#pragma strict_gs_check(push, on)
    // MS2-FUNCTIONAL: stack slots of the point / color / rect locals and the error temporaries; same code otherwise
    // @0x142451770
    void BitmapData::pixelDissolve(SInt32& result, Instances::fl_display::BitmapData* sourceBitmapData, Instances::fl_geom::Rectangle* sourceRect,
                                   Instances::fl_geom::Point* destPoint, SInt32 randomSeed, SInt32 numPixels, UInt32 fillColor)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!sourceBitmapData)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceBitmapData"));
        }
        else if (!sourceRect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceRect"));
        }
        else if (!destPoint)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "destPoint"));
        }
        else if (numPixels < 0)
        {
            // 2027: the parameter must be a non-negative number
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::ErrorID(2027), vm, "numPixels"));
        }
        else
        {
            Render::Point<SInt32> dp((SInt32)destPoint->x, (SInt32)destPoint->y);
            Render::Color color(fillColor);
            Render::Rect<SInt32> rect((SInt32)sourceRect->x, (SInt32)sourceRect->y,
                                      (SInt32)(sourceRect->x + sourceRect->width), (SInt32)(sourceRect->y + sourceRect->height));
            Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
            result = pimage->PixelDissolve(sourceBitmapData->pImage, rect, dp, randomSeed, numPixels, color);
        }
    }
#pragma strict_gs_check(pop)

    // The Graphics object of a sprite or shape, made on first use and bound to the display object's drawing.
    static SF_FORCEINLINE void MakeGraphics(VM& vm, SPtr<Instances::fl_display::Graphics>& pgraphics, GFx::DisplayObject* pdobj)
    {
        ASVM& asvm = static_cast<ASVM&>(vm);
        if (asvm.ConstructInstance(pgraphics, asvm.GraphicsClass))
        {
            Instances::fl_display::Graphics* pg = pgraphics;
            pg->pDrawing = pdobj->GetDrawingContext();
            pgraphics->pDispObj = pdobj;
        }
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<Graphics>::operator= instance (0x14243d720); ours inlines it
    // @0x14244e3c0
    SF_NOINLINE void Sprite::graphicsGet(SPtr<Instances::fl_display::Graphics>& result)
    {
        if (!pGraphics)
            MakeGraphics(GetVM(), pGraphics, pDispObj);
        result = pGraphics;
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<Graphics>::operator= instance (0x14243d720); ours inlines it
    // @0x14244e2e0
    SF_NOINLINE void Shape::graphicsGet(SPtr<Instances::fl_display::Graphics>& result)
    {
        if (!pDispObj)
            CreateStageObject();
        if (!pGraphics)
            MakeGraphics(GetVM(), pGraphics, pDispObj);
        result = pGraphics;
    }

#pragma strict_gs_check(push, on)
    // MS2-FUNCTIONAL: exe loads pDispObj before the null test and keeps the twips constant in xmm2 (ours xmm3); same rect
    // @0x142452c90
    void DisplayObject::scrollRectSet(const Value& result, Instances::fl_geom::Rectangle* value)
    {
        SF_UNUSED(result);
        Render::RectD r(Render::RectD::NoInit);
        Render::RectD* pr;
        if (value)
        {
            r.x1 = value->x * 20.0;
            r.y1 = value->y * 20.0;
            r.x2 = value->width * 20.0 + r.x1;
            r.y2 = value->height * 20.0 + r.y1;
            pr = &r;
        }
        else
            pr = NULL;
        pDispObj->SetScrollRect(pr);
    }
#pragma strict_gs_check(pop)

    // @0x142449030
    void LoaderInfo::contentTypeGet(ASString& result)
    {
        if (Content)
        {
            GFx::DisplayObject* pdisp;
            {
                Ptr<GFx::DisplayObject> p;
                p = Content->pDispObj;
                pdisp = p.GetPtr();
            }
            MovieDataDef::MovieDataType type = pdisp->GetResourceMovieDef()->pBindData->GetDataDef()->MovieType;
            if (type == MovieDataDef::MT_Flash)
                result = "application/x-shockwave-flash";
            else
                result = (type == MovieDataDef::MT_Image) ? "image" : "unknown";
        }
        else
            result = "unknown";
    }

    // The movie's log as a raw pointer (the Ptr temporary is released before the caller uses it).
    static SF_FORCEINLINE Log* MovieLogPtr(ASVM& asvm)
    {
        Log* plog = asvm.GetMovieImpl()->GetStateBag()->GetLog().GetPtr();
        return plog;
    }

    // @0x142447e50
    SF_NOINLINE void LoaderInfo::applicationDomainGet(SPtr<Instances::fl_system::ApplicationDomain>& result)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        if (MovieLogPtr(asvm))
            MovieLogPtr(asvm)->LogWarning("LoaderInfo::applicationDomainGet() is not supported.");
        result = NULL;
    }

    // @0x1424543a0
    SF_NOINLINE void DisplayObject::transformGet(SPtr<Instances::fl_geom::Transform>& result)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        SPtr<Instances::fl_geom::Transform> ptransform;
        if (asvm.ConstructInstance(ptransform, asvm.TransformClass))
            ptransform->pDispObj = pDispObj;
        result = ptransform;
    }

#pragma strict_gs_check(push, on)
    // Copies the color transform, the 2D or 3D matrix, and any view / projection matrix from the transform's object.
    // @0x142454470
    void DisplayObject::transformSet(const Value& result, Instances::fl_geom::Transform* value)
    {
        SF_UNUSED(result);
        pDispObj->SetCxform(value->pDispObj->GetCxform());
        if (pDispObj->Is3D())
            pDispObj->SetMatrix3D(value->pDispObj->GetMatrix3D());
        else
            pDispObj->SetMatrix(value->pDispObj->GetMatrix());

        Matrix3F view;
        if (value->pDispObj->GetViewMatrix3D(&view))
            pDispObj->SetViewMatrix3D(view);
        Matrix4F proj;
        if (value->pDispObj->GetProjectionMatrix3D(&proj))
            pDispObj->SetProjectionMatrix3D(proj);
    }
#pragma strict_gs_check(pop)

    // MS2-FUNCTIONAL: string manager load uses a different temp register (rcx vs rax); logic identical
    // @0x1424496d0
    void MovieClip::currentFrameLabelGet(ASString& result)
    {
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        VM& vm = GetVM();
        unsigned frame = psprite->GetCurrentFrame(), labelFrame;
        const String* plabel = psprite->pDef->GetFrameLabel(frame, &labelFrame);
        if (plabel && frame == labelFrame)
            result = vm.GetStringManager().CreateString(plabel->ToCStr());
        else
            result.SetNull();
    }

    // MS2-FUNCTIONAL: string manager load uses a different temp register (rcx vs rax); logic identical
    // @0x1424497a0
    void MovieClip::currentLabelGet(ASString& result)
    {
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        VM& vm = GetVM();
        unsigned frame = psprite->GetCurrentFrame();
        const String* plabel = psprite->pDef->GetFrameLabel(frame, &frame);
        if (plabel)
            result = vm.GetStringManager().CreateString(plabel->ToCStr());
        else
            result.SetNull();
    }

    // @0x1424509c0
    void FrameLabel::nameGet(ASString& result)
    {
        result = FrameName;
    }

    // @0x142451a50
    void Bitmap::pixelSnappingSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        PixelSnapping = FUN_142446f30(this, value.ToCStr());
        if (pDispObj)
            FUN_142520b20(pDispObj);
    }
}}

// ---- flash.display: getters this build does not implement (warn and return null) ----

namespace Instances { namespace fl_display
{
    void DisplayObject::accessibilityPropertiesGet(SPtr<Instances::fl_accessibility::AccessibilityProperties>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method instance::DisplayObject::accessibilityPropertiesGet() is not implemented\n");
    }

    // @0x142447440
    SPtr<Instances::fl_accessibility::AccessibilityProperties> DisplayObject::accessibilityPropertiesGet()
    {
        SPtr<Instances::fl_accessibility::AccessibilityProperties> result;
        accessibilityPropertiesGet(result);
        return result;
    }

    void LoaderInfo::bytesGet(SPtr<Instances::fl_utils::ByteArray>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method LoaderInfo::bytesGet() is not implemented\n");
    }

    // @0x142448810
    SPtr<Instances::fl_utils::ByteArray> LoaderInfo::bytesGet()
    {
        SPtr<Instances::fl_utils::ByteArray> result;
        bytesGet(result);
        return result;
    }

    void Stage::fullScreenSourceRectGet(SPtr<Instances::fl_geom::Rectangle>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method Stage::fullScreenSourceRectGet() is not implemented\n");
    }

    // @0x14244c4d0
    SPtr<Instances::fl_geom::Rectangle> Stage::fullScreenSourceRectGet()
    {
        SPtr<Instances::fl_geom::Rectangle> result;
        fullScreenSourceRectGet(result);
        return result;
    }

    void LoaderInfo::sharedEventsGet(SPtr<Instances::fl_events::EventDispatcher>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method LoaderInfo::sharedEventsGet() is not implemented\n");
    }

    // @0x142453250
    SPtr<Instances::fl_events::EventDispatcher> LoaderInfo::sharedEventsGet()
    {
        SPtr<Instances::fl_events::EventDispatcher> result;
        sharedEventsGet(result);
        return result;
    }

    void SimpleButton::soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method SimpleButton::soundTransformGet() is not implemented\n");
    }

    // @0x142453320
    SPtr<Instances::fl_media::SoundTransform> SimpleButton::soundTransformGet()
    {
        SPtr<Instances::fl_media::SoundTransform> result;
        soundTransformGet(result);
        return result;
    }

    void Sprite::soundTransformGet(SPtr<Instances::fl_media::SoundTransform>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method Sprite::soundTransformGet() is not implemented\n");
    }

    // @0x142453380
    SPtr<Instances::fl_media::SoundTransform> Sprite::soundTransformGet()
    {
        SPtr<Instances::fl_media::SoundTransform> result;
        soundTransformGet(result);
        return result;
    }

    void Stage::textSnapshotGet(SPtr<Instances::fl_text::TextSnapshot>& result)
    {
        SF_UNUSED(result);
        GetVM().GetUI().Output(FlashUI::Output_Warning, "The method Stage::textSnapshotGet() is not implemented\n");
    }

    // @0x142453e50
    SPtr<Instances::fl_text::TextSnapshot> Stage::textSnapshotGet()
    {
        SPtr<Instances::fl_text::TextSnapshot> result;
        textSnapshotGet(result);
        return result;
    }
}}

namespace Instances { namespace fl_display
{
    // @0x142448790
    void DisplayObject::blendModeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        Render::BlendMode mode = Classes::fl_display::BlendMode::GetBlendMode(value);
        pDispObj->SetBlendMode(mode);
    }

    // @0x1424485e0
    void DisplayObject::blendModeGet(ASString& result)
    {
        switch (pDispObj->GetBlendMode())
        {
        case Render::Blend_None:
        case Render::Blend_Normal:     result = GetVM().GetStringManager().CreateConstString("normal"); break;
        case Render::Blend_Layer:      result = GetVM().GetStringManager().CreateConstString("layer"); break;
        case Render::Blend_Multiply:   result = GetVM().GetStringManager().CreateConstString("multiply"); break;
        case Render::Blend_Screen:     result = GetVM().GetStringManager().CreateConstString("screen"); break;
        case Render::Blend_Lighten:    result = GetVM().GetStringManager().CreateConstString("lighten"); break;
        case Render::Blend_Darken:     result = GetVM().GetStringManager().CreateConstString("darken"); break;
        case Render::Blend_Difference: result = GetVM().GetStringManager().CreateConstString("difference"); break;
        case Render::Blend_Add:        result = GetVM().GetStringManager().CreateConstString("add"); break;
        case Render::Blend_Subtract:   result = GetVM().GetStringManager().CreateConstString("subtract"); break;
        case Render::Blend_Invert:     result = GetVM().GetStringManager().CreateConstString("invert"); break;
        case Render::Blend_Alpha:      result = GetVM().GetStringManager().CreateConstString("alpha"); break;
        case Render::Blend_Erase:      result = GetVM().GetStringManager().CreateConstString("erase"); break;
        case Render::Blend_Overlay:    result = GetVM().GetStringManager().CreateConstString("overlay"); break;
        case Render::Blend_HardLight:  result = GetVM().GetStringManager().CreateConstString("hardlight"); break;
        default: break;
        }
    }

#pragma strict_gs_check(push, on)
    // paletteMap(sourceBitmapData, sourceRect, destPoint, redArray, greenArray, blueArray, alphaArray): the channel
    // arrays are read into 256-entry tables; a missing or null array leaves its channel unmapped.
    // MS2-FUNCTIONAL: stack layout (the exe frame is 0x10 larger and shares the argument and error slots); same code otherwise
    // @0x142450f00
    void BitmapData::paletteMap(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (argc >= 3)
        {
            Instances::fl_display::BitmapData* sourceBitmapData = static_cast<Instances::fl_display::BitmapData*>(argv[0].GetObject());
            Instances::fl_geom::Rectangle* sourceRect = static_cast<Instances::fl_geom::Rectangle*>(argv[1].GetObject());
            Instances::fl_geom::Point* destPoint = static_cast<Instances::fl_geom::Point*>(argv[2].GetObject());
            if (!sourceBitmapData)
            {
                VM& vm = GetVM();
                vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceBitmapData"));
            }
            else if (!sourceRect)
            {
                VM& vm = GetVM();
                vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceRect"));
            }
            else if (!destPoint)
            {
                VM& vm = GetVM();
                vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "destPoint"));
            }
            else
            {
                UInt32* channels[4];
                UInt32 tables[4][256];
                for (unsigned i = 0; i < 4; ++i)
                {
                    Instances::fl::Array* arr = (i < argc - 3) ? static_cast<Instances::fl::Array*>(argv[3 + i].GetObject()) : NULL;
                    if (arr)
                    {
                        channels[i] = tables[i];
                        for (UPInt j = 0; j < 256; ++j)
                            arr->SA.At(j).Convert2UInt32(channels[i][j]);
                    }
                    else
                        channels[i] = NULL;
                }
                Render::Point<SInt32> dp((SInt32)destPoint->x, (SInt32)destPoint->y);
                Render::Rect<SInt32> rect((SInt32)sourceRect->x, (SInt32)sourceRect->y,
                                          (SInt32)(sourceRect->x + sourceRect->width), (SInt32)(sourceRect->y + sourceRect->height));
                reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr())->PaletteMap(sourceBitmapData->pImage, rect, dp, channels);
            }
        }
    }
#pragma strict_gs_check(pop)

#pragma strict_gs_check(push, on)
    // merge(sourceBitmapData, sourceRect, destPoint, redMultiplier, greenMultiplier, blueMultiplier, alphaMultiplier):
    // only the full seven-argument form does anything.
    // MS2-FUNCTIONAL: the exe keeps pImage in a volatile register until the cast (no rbp push in the prolog); stack slots
    // @0x142450590
    void BitmapData::merge(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (argc == 7)
        {
            Instances::fl_display::BitmapData* sourceBitmapData = static_cast<Instances::fl_display::BitmapData*>(argv[0].GetObject());
            Instances::fl_geom::Point* destPoint = static_cast<Instances::fl_geom::Point*>(argv[2].GetObject());
            Instances::fl_geom::Rectangle* sourceRect = static_cast<Instances::fl_geom::Rectangle*>(argv[1].GetObject());
            if (!sourceBitmapData)
                return;
            Render::ImageBase* psource = sourceBitmapData->pImage;
            Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
            if (!psource || !pimage)
                return;
            UInt32 mult[4];
            for (unsigned i = 0; i < argc - 3; ++i)
                argv[3 + i].Convert2UInt32(mult[i]);
            Render::Point<SInt32> dp((SInt32)destPoint->x, (SInt32)destPoint->y);
            Render::Rect<SInt32> rect((SInt32)sourceRect->x, (SInt32)sourceRect->y,
                                      (SInt32)(sourceRect->x + sourceRect->width), (SInt32)(sourceRect->y + sourceRect->height));
            pimage->Merge(psource, rect, dp, mult[0], mult[1], mult[2], mult[3]);
        }
    }
#pragma strict_gs_check(pop)

    // @0x142450540
    void DisplayObject::maskSet(const Value& result, Instances::fl_display::DisplayObject* value)
    {
        SF_UNUSED(result);
        GFx::DisplayObject* pmask;
        if (!value)
            pmask = NULL;
        else
        {
            pmask = value->pDispObj;
            if (!pmask)
            {
                value->CreateStageObject();
                pmask = value->pDispObj;
            }
        }
        pDispObj->SetMask(pmask);
    }

    // InteractiveObject::ModifyOptimizedPlayList as these natives inline it: the play list bits tested one at a time.
    static inline bool InOptAdvList(const GFx::InteractiveObject* ch) { return ((ch->Flags >> 21) & 1) != 0; }
    static inline bool MarkedToLeaveAdvList(const GFx::InteractiveObject* ch) { return ((ch->Flags >> 22) & 1) != 0; }
    static inline void ModifyOptPlayList(GFx::InteractiveObject* pio)
    {
        switch (pio->CheckAdvanceStatus(InOptAdvList(pio) && !MarkedToLeaveAdvList(pio)))
        {
        case 1:  pio->AddToOptimizedPlayList(); break;
        case -1: pio->MarkToRemoveFromOptimizedPlayList(); break;
        }
    }

    // MS2-FUNCTIONAL: exe sets up an rbp frame and zeroes the drag state points one qword at a time; same stores and calls
    // @0x142453670
    void Sprite::startDrag(const Value& result, bool lockCenter, Instances::fl_geom::Rectangle* bounds)
    {
        SF_UNUSED(result);
        // no IsDragging check in this build: a new drag replaces the current one
        MovieImpl::DragState st;
        if (bounds)
        {
            st.Bound = true;
            st.BoundLT.x = (float)bounds->x * 20.0f;
            st.BoundLT.y = (float)bounds->y * 20.0f;
            st.BoundRB.x = (float)((float)bounds->x + bounds->width) * 20.0f;
            st.BoundRB.y = (float)((float)bounds->y + bounds->height) * 20.0f;
        }
        st.pCharacter = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr());
        st.InitCenterDelta(lockCenter);
        pDispObj->GetMovieImpl()->SetDragState(st);
        ModifyOptPlayList(static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr()));
    }

    // @0x142453800
    void Sprite::stopDrag(const Value& result)
    {
        SF_UNUSED(result);
        pDispObj->GetMovieImpl()->pKeepAdvancingChar = NULL;    // StopDrag: the drag state lets go of its character
        ModifyOptPlayList(static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr()));
    }

    // @0x14244ecc0
    void Sprite::hitAreaSet(const Value& result, Instances::fl_display::Sprite* value)
    {
        SF_UNUSED(result);
        GFx::DisplayObject* phit;
        if (value)
        {
            phit = value->pDispObj;
            if (!phit)
            {
                value->CreateStageObject();
                phit = value->pDispObj;
            }
        }
        else
            phit = NULL;
        static_cast<GFx::Sprite*>(pDispObj.GetPtr())->SetHitArea(static_cast<GFx::Sprite*>(phit));
    }

    // @0x14244c480
    void MovieClip::framesLoadedGet(SInt32& result)
    {
        if (!pDispObj)
        {
            result = 1;
            return;
        }
        result = static_cast<GFx::Sprite*>(pDispObj.GetPtr())->GetLoadingFrame();
    }

    // @0x142451a90
    void MovieClip::prevFrame(const Value& result)
    {
        SF_UNUSED(result);
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        int frame = psprite->GetCurrentFrame();
        if (frame > 0)
            psprite->GotoFrame(frame - 1);
        psprite->SetPlayState(State_Stopped);
    }

    // @0x142450bc0
    void MovieClip::nextScene(const Value& result)
    {
        SF_UNUSED(result);
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        if (psprite->pDef->GetType() == CharacterDef::MovieData)
        {
            UPInt count = 0;
            const MovieDataDef::SceneInfo* pscenes = psprite->GetResourceMovieDef()->GetDataDef()->GetScenes(&count);
            unsigned frame = psprite->GetCurrentFrame();
            for (UPInt i = 0; i < count; ++i)
            {
                if (frame >= pscenes[i].Offset && frame < pscenes[i].Offset + pscenes[i].NumFrames)
                {
                    // The next scene, once its first frame is loaded.
                    if (i + 1 < count)
                    {
                        unsigned loaded = psprite->GetLoadingFrame();
                        if (pscenes[i + 1].Offset < loaded)
                        {
                            psprite->GotoFrame(pscenes[i + 1].Offset);
                            psprite->SetPlayState(State_Playing);
                        }
                    }
                }
            }
        }
    }

    // @0x142451ae0
    void MovieClip::prevScene(const Value& result)
    {
        SF_UNUSED(result);
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        if (psprite->pDef->GetType() == CharacterDef::MovieData)
        {
            UPInt count = 0;
            const MovieDataDef::SceneInfo* pscenes = psprite->GetResourceMovieDef()->GetDataDef()->GetScenes(&count);
            unsigned frame = psprite->GetCurrentFrame();
            for (UPInt i = 0; i < count; ++i)
            {
                if (frame >= pscenes[i].Offset && frame < pscenes[i].Offset + pscenes[i].NumFrames)
                {
                    // The previous scene.
                    if (i > 0)
                    {
                        psprite->GotoFrame(pscenes[i - 1].Offset);
                        psprite->SetPlayState(State_Playing);
                    }
                }
            }
        }
    }

    // @0x1424542b0
    void MovieClip::totalFramesGet(SInt32& result)
    {
        result = static_cast<GFx::Sprite*>(pDispObj.GetPtr())->pDef->GetFrameCount();
    }

    // @0x142450a00
    void Scene::nameGet(ASString& result)
    {
        VM& vm = GetVM();
        if (SceneInfo)
        {
            result.AssignNode(result.GetManager()->CreateStringNode(SceneInfo->Name.ToCStr(), SceneInfo->Name.GetSize()));
            return;
        }
        result = vm.GetStringManager().CreateEmptyString();
    }

    // @0x142450d60
    void Scene::numFramesGet(SInt32& result)
    {
        if (SceneInfo)
        {
            result = SceneInfo->NumFrames;
            return;
        }
        result = SpriteObj->pDef->GetFrameCount();
    }

    // @0x142453420
    void Stage::stageFocusRectGet(bool& result)
    {
        result = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr())->IsFocusRectEnabled();
    }
}}

namespace Instances { namespace fl_display
{
    // @0x14244c260
    void InteractiveObject::focusRectSet(const Value& result, const Value& value)
    {
        SF_UNUSED(result);
        GFx::InteractiveObject* pobj = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr());
        if (!value.IsUndefined())
            pobj->SetFocusRectFlag(value.Convert2Boolean());
        else
            pobj->Flags &= ~GFx::InteractiveObject::Mask_TabEnabled;   // the exe clears these bits, not Mask_FocusRect
    }

    // @0x142450b60
    void MovieClip::nextFrame(const Value& result)
    {
        SF_UNUSED(result);
        GFx::Sprite* psprite = static_cast<GFx::Sprite*>(pDispObj.GetPtr());
        int loaded = psprite->GetLoadingFrame();
        int frame = psprite->GetCurrentFrame();
        if (frame < loaded)
            psprite->GotoFrame(frame + 1);
        psprite->SetPlayState(State_Stopped);
    }
}}

namespace Instances { namespace fl_display
{
    // @0x1424484e0
    void Bitmap::bitmapDataGet(SPtr<Instances::fl_display::BitmapData>& result)
    {
        result = pBitmapData;
    }

    // Cast-only view of the AS3 part of an interactive display object (AS3::AvmInteractiveObj): its
    // AvmInteractiveObjBase interface sits at +0x30, the AS3 flags at +0x39 (bit 1: doubleClickEnabled).
    struct AvmIntObjHead
    {
        virtual ~AvmIntObjHead();
        UByte   Unrecovered_08[0x28];
    };
    struct AvmIntObjView : AvmIntObjHead, AvmInteractiveObjBase
    {
        UByte   Unrecovered_38;
        UByte   AS3Flags;   // +0x39

        bool IsDoubleClickEnabled() const { return (AS3Flags & 2) != 0; }
        void SetDoubleClickEnabled(bool v) { v ? AS3Flags |= 2 : AS3Flags &= ~2; }
    };
    static AvmIntObjView* ToAvmIntObjView(GFx::DisplayObject* pdobj)
    {
        GFx::InteractiveObject* pio = pdobj->IsInteractiveObject() ? static_cast<GFx::InteractiveObject*>(pdobj) : NULL;
        if (!pio)
            return NULL;
        return static_cast<AvmIntObjView*>(pio->GetAvmObjImpl()->ToAvmInteractiveObjBase());
    }

    // @0x142449d20
    void InteractiveObject::doubleClickEnabledGet(bool& result)
    {
        result = ToAvmIntObjView(pDispObj)->IsDoubleClickEnabled();
    }

    // @0x142449d80
    void InteractiveObject::doubleClickEnabledSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        ToAvmIntObjView(pDispObj)->SetDoubleClickEnabled(value);
    }

    // @0x142453b70
    void InteractiveObject::tabEnabledSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        GFx::InteractiveObject* pio = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr());
        UInt32 flags = pio->Flags;
        UInt32 on = flags | GFx::InteractiveObject::Mask_TabEnabled;   // true
        UInt32 off = (flags & ~0x20u) | 0x40u;                         // false (defined)
        pio->Flags = value ? on : off;
        SPtr<fl_events::Event> e = CreateEventObject(GetVM().GetStringManager().CreateConstString("tabEnabledChange"), true, false);
        DispatchEventObject(e, pDispObj);
    }

    // @0x142453a70
    void DisplayObjectContainer::tabChildrenSet(const Value& result, bool value)
    {
        SF_UNUSED(result);
        GFx::InteractiveObject* pio = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr());
        UInt32 flags = pio->Flags;
        UInt32 on = flags & ~GFx::InteractiveObject::Mask_TabChildrenDisabled;
        UInt32 off = flags | GFx::InteractiveObject::Mask_TabChildrenDisabled;
        pio->Flags = value ? on : off;
        SPtr<fl_events::Event> e = CreateEventObject(GetVM().GetStringManager().CreateConstString("tabChildrenChange"), true, false);
        DispatchEventObject(e, pDispObj);
    }

    // @0x142453c40
    void InteractiveObject::tabIndexSet(const Value& result, SInt32 value)
    {
        SF_UNUSED(result);
        static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr())->TabIndex = (SInt16)value;
        SPtr<fl_events::Event> e = CreateEventObject(GetVM().GetStringManager().CreateConstString("tabIndexChange"), true, false);
        DispatchEventObject(e, pDispObj);
    }

    // @0x1424490d0
    void InteractiveObject::contextMenuGet(SPtr<Instances::fl::Object>& result)
    {
        result = pContextMenu;
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<Object>::operator= instance (0x14243d870); ours inlines it
    // @0x142449140
    void InteractiveObject::contextMenuSet(const Value& result, const Value& value)
    {
        SF_UNUSED(result);
        if (value.IsObject() && FUN_14250ffc0(GetVM(), value).IsInstanceTraits())
        {
            pContextMenu = static_cast<Instances::fl::Object*>(value.GetObject());
            return;
        }
        GetVM().ThrowTypeError(VM::Error(VM::eCheckTypeFailedError, GetVM(), FUN_14250ffc0(GetVM(), value).GetName().ToCStr(),
            "flash.ui.ContextMenu"));
    }

    // @0x14244ff20
    void LoaderInfo::loaderGet(SPtr<Instances::fl_display::Loader>& result)
    {
        result = pLoader;
    }

    // @0x142448eb0
    void DisplayObjectContainer::contains(bool& result, Instances::fl_display::DisplayObject* child)
    {
        if (!child)
        {
            VM& vm = GetVM();
            vm.ThrowTypeError(VM::Error(VM::eNullPointerError, vm, "child"));
            return;
        }
        result = static_cast<GFx::DisplayObjContainer*>(pDispObj.GetPtr())->Contains(child->pDispObj);
    }
}}

namespace Instances { namespace fl_display
{
    // MS2-FUNCTIONAL: exe frame carries a /GS cookie around the GetRect temp; logic identical
    // @0x142454960
    SF_NOINLINE void BitmapData::widthGet(SInt32& result)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        result = pImage->GetRect().Width();
    }

    // MS2-FUNCTIONAL: exe frame carries a /GS cookie around the GetRect temp; logic identical
    // @0x14244e480
    SF_NOINLINE void BitmapData::heightGet(SInt32& result)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        result = pImage->GetRect().Height();
    }

    // @0x142450940
    void DisplayObject::nameGet(ASString& result)
    {
        ASString name = pDispObj->GetName();
        if (name.IsEmpty() && pDispObj->IsInstanceBasedNameFlagSet())
            result.SetNull();
        else
            result = name;
    }

    // @0x142450ab0
    void DisplayObject::nameSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        if (pDispObj->Flags & GFx::DisplayObject::Mask_TimelineObject)
        {
            VM& vm = GetVM();
            vm.ThrowTypeError(VM::Error(VM::eIllegalWriteError, vm, "name", "Timeline"));
            return;
        }
        pDispObj->SetName(value);
        pDispObj->Flags &= ~GFx::DisplayObject::Mask_InstanceBasedName;
    }

    // MS2-FUNCTIONAL: inline Value::Release kind test scheduled differently (byte compare in exe); logic identical
    // @0x14244c1b0
    void InteractiveObject::focusRectGet(Value& result)
    {
        // The exe reads the bits focusRectSet clears for undefined.
        UInt32 bits = static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr())->Flags & GFx::InteractiveObject::Mask_TabEnabled;
        if (bits)
        {
            const bool enabled = bits == GFx::InteractiveObject::Mask_TabEnabled;
            result.SetBool(enabled);
        }
        else
            result.SetNull();
    }
}}

// The AS3 part of every display object (as3_avm.h, which this unit cannot include). Only what the natives use:
// the AS3 object instantiation (slot 15) and the AS3 object pointers.
class AvmDisplayObj : public AvmDisplayObjBase
{
public:
    virtual void        OnRemoved(bool byTimeline);
    virtual void        Unrecovered_14();
    virtual unsigned    CreateASInstance(bool execute);

    // The AS3 object, kept raw or as a tagged collectible pointer.
    Instances::fl_display::DisplayObject* GetAS3Obj() const
    {
        UPInt p = pAS3RawPtr ? reinterpret_cast<UPInt>(pAS3RawPtr) : reinterpret_cast<UPInt>(pAS3CollectiblePtr);
        if (p & 1)
            --p;
        return reinterpret_cast<Instances::fl_display::DisplayObject*>(p);
    }
    // The root of the movie this object is in (0x14250d990).
    DisplayObject* GetRoot();
    // False while the stage is off limits to this object's code (0x142514d20).
    bool IsStageAccessible() const;

    Instances::fl_display::DisplayObject*   pAS3CollectiblePtr; // +0x08 SPtr<>
    Instances::fl_display::DisplayObject*   pAS3RawPtr;         // +0x10
};

static inline AvmDisplayObj* ToAvmDisplayObj(DisplayObject* p)
{
    if (!p)
        return NULL;
    return static_cast<AvmDisplayObj*>(p->GetAvmObjImpl());
}

// AS3::AvmInteractiveObj as the natives see it: the AvmInteractiveObjBase interface at +0x30.
class AvmInteractiveObjHead : public AvmDisplayObj
{
    UByte   Unrecovered_18[0x18];
};
class AvmInteractiveObj : public AvmInteractiveObjHead, public AvmInteractiveObjBase
{
};

static inline AvmInteractiveObj* ToAvmInteractiveObj(GFx::InteractiveObject* p)
{
    return static_cast<AvmInteractiveObj*>(p->GetAvmIntObj());
}

namespace Instances { namespace fl_display
{
    // MS2-FUNCTIONAL: exe strips the collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x14244b870
    SF_NOINLINE void Sprite::dropTargetGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        MovieImpl* proot = pDispObj->GetMovieImpl();
        Render::PointF mousePos = proot->MouseLastPosition;
        GFx::InteractiveObject* ptop = proot->GetTopMostEntity(mousePos, 0, true,
                                                               static_cast<GFx::InteractiveObject*>(pDispObj.GetPtr()));
        if (ptop)
        {
            ToAvmInteractiveObj(ptop)->CreateASInstance(true);
            result = ToAvmInteractiveObj(ptop)->GetAS3Obj();
        }
        else
            result = NULL;
    }
}}

namespace Instances { namespace fl_display
{
    // MS2-FUNCTIONAL: exe strips the collectible tag with a branch (test/je/dec), ours with cmov; register
    // assignment follows. Same loads and calls.
    // @0x142452090
    SF_NOINLINE void DisplayObject::rootGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        AvmDisplayObj* pavm = ToAvmDisplayObj(ToAvmDisplayObj(pDispObj)->GetRoot());
        pavm->CreateASInstance(true);
        result = pavm->GetAS3Obj();
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<Sprite>::operator= instance (0x14243d950) and strips the collectible tag with a branch; ours inlines both
    // @0x14244ec30
    void Sprite::hitAreaGet(SPtr<Instances::fl_display::Sprite>& result)
    {
        if (pDispObj)
        {
            GFx::Sprite* phit = static_cast<GFx::Sprite*>(pDispObj.GetPtr())->GetHitArea();
            if (phit)
            {
                // the AS3 sprite already exists here: no CreateASInstance
                Instances::fl_display::DisplayObject* ido = ToAvmDisplayObj(phit)->GetAS3Obj();
                BuiltinTraitsType tt = ido->GetTraits().GetTraitsType();
                if (tt == Traits_Sprite || tt == Traits_MovieClip)
                {
                    result = static_cast<Instances::fl_display::Sprite*>(ido);
                    return;
                }
            }
        }
        result = NULL;
    }
}}


namespace Instances { namespace fl_display
{
    // A button state character's AS3 object, null when the state has none.
    static SF_FORCEINLINE void SetButtonStateResult(SPtr<Instances::fl_display::DisplayObject>& result, GFx::DisplayObject* pch)
    {
        if (pch)
        {
            result = ToAvmDisplayObj(pch)->GetAS3Obj();
            return;
        }
        result = NULL;
    }

    // MS2-FUNCTIONAL: exe strips the collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x142449e00
    SF_NOINLINE void SimpleButton::downStateGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        SetButtonStateResult(result, FUN_142509970(ToAvmDisplayObj(pDispObj)));
    }

    // MS2-FUNCTIONAL: exe strips the collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x14244f4a0
    SF_NOINLINE void SimpleButton::hitTestStateGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        SetButtonStateResult(result, FUN_14250a600(ToAvmDisplayObj(pDispObj)));
    }

    // MS2-FUNCTIONAL: exe strips the collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x142450e50
    SF_NOINLINE void SimpleButton::overStateGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        SetButtonStateResult(result, FUN_14250cbe0(ToAvmDisplayObj(pDispObj)));
    }

    // MS2-FUNCTIONAL: exe strips the collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x142454700
    SF_NOINLINE void SimpleButton::upStateGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        SetButtonStateResult(result, FUN_14250f960(ToAvmDisplayObj(pDispObj)));
    }

    // MS2-FUNCTIONAL: exe strips the collectible tag with a branch (test/je/dec), ours with cmov, and shrink-wraps differently; same loads and calls
    // @0x14244ffb0
    SF_NOINLINE void DisplayObject::loaderInfoGet(SPtr<Instances::fl_display::LoaderInfo>& result)
    {
        // A timeline-placed object shares the loader info of its movie's root.
        DisplayObject* pobj = this;
        if (pDispObj->Flags & GFx::DisplayObject::Mask_TimelineObject)
            pobj = ToAvmDisplayObj(ToAvmDisplayObj(pDispObj)->GetRoot())->GetAS3Obj();
        result = pobj->pLoaderInfo;
    }

    // MS2-FUNCTIONAL: exe strips the collectible tag with a branch (test/je/dec), ours with cmov; same loads and calls
    // @0x1424504a0
    SF_NOINLINE void DisplayObject::maskGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        result = NULL;
        if (pDispObj && pDispObj->GetMask())
            result = ToAvmDisplayObj(pDispObj->GetMask())->GetAS3Obj();
    }

    // MS2-FUNCTIONAL: collectible tag strip compiles to cmov; container assignment goes through the out-of-line SPtr operator= in the exe
    // @0x142451260
    SF_NOINLINE void DisplayObject::parentGet(SPtr<Instances::fl_display::DisplayObjectContainer>& result)
    {
        GFx::InteractiveObject* pparent = pDispObj->GetParent();
        if (pparent)
        {
            // through the interactive part; the AS3 instance is not created here
            AvmIntObjView* pview = static_cast<AvmIntObjView*>(pparent->GetAvmObjImpl()->ToAvmInteractiveObjBase());
            Instances::fl_display::DisplayObject* ido =
                reinterpret_cast<AvmDisplayObj*>(static_cast<AvmIntObjHead*>(pview))->GetAS3Obj();
            if (ido && ido->GetTraits().GetTraitsType() >= Traits_DisplayObjectContainer)
            {
                result = static_cast<Instances::fl_display::DisplayObjectContainer*>(ido);
                return;
            }
        }
        result = NULL;
    }

    // MS2-FUNCTIONAL: register allocation of the inlined SPtr<BitmapData> assignment (exe keeps the old pointer in rdx); same loads, stores and calls
    // @0x142448550
    void Bitmap::bitmapDataSet(const Value& result, Instances::fl_display::BitmapData* value)
    {
        SF_UNUSED(result);
        pBitmapData = value;
        if (pDispObj)
            FUN_142528e70(pDispObj, value ? value->pDefImpl.GetPtr() : NULL);
        if (pDispObj)
            FUN_142520b20(pDispObj);
    }
}}

// AS3 part of a display object container: AvmInteractiveObj, with its
// AvmDisplayObjContainerBase part at +0x40. Opaque; only the members the natives call.
class AvmDisplayObjContainer : public AvmInteractiveObj
{
public:
    virtual void        Unrecovered_16();
    virtual void        Unrecovered_17();
    virtual void        Unrecovered_18();
    virtual void        Unrecovered_19();
    // Appends the display objects under pt (container space, twips), topmost last.
    virtual void        GetObjectsUnderPoint(ArrayDH<Ptr<DisplayObjectBase> >* destArray, const Render::PointF& pt) const;

    static AvmDisplayObjContainer* FromBase(AvmDisplayObjContainerBase* p)
    {
        return p ? reinterpret_cast<AvmDisplayObjContainer*>(reinterpret_cast<UByte*>(p) - 0x40) : NULL;
    }
    void SetChildIndex(DisplayObjectBase* ch, unsigned index);  // 0x142526610
    void SwapChildrenAt(unsigned i1, unsigned i2);              // 0x14252e6d0
    void SwapChildren(DisplayObjectBase* ch1, DisplayObjectBase* ch2);   // 0x14252e590
    void RemoveChild(DisplayObjectBase* ch);                    // 0x142522570
    void RemoveChildAt(unsigned index);                         // 0x1425226a0
    void AddChild(DisplayObjectBase* ch);                       // 0x1424e6d90
    void AddChildAt(DisplayObjectBase* ch, unsigned index);     // 0x1424e6e90
    SPtr<Instances::fl_display::DisplayObject> GetAS3ChildAt(unsigned index);
    SPtr<Instances::fl_display::DisplayObject> GetAS3ChildByName(const ASString& name);
};

namespace Instances { namespace fl_display
{
    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<Stage>::operator= instance (0x14243d9c0) and strips the collectible tag with a branch; ours inlines both
    // @0x142453490
    SF_NOINLINE void DisplayObject::stageGet(SPtr<Instances::fl_display::Stage>& result)
    {
        if (!ToAvmDisplayObj(pDispObj)->IsStageAccessible())
        {
            result = NULL;
            return;
        }
        GFx::DisplayObject* pstage = FUN_14250edf0(ToAvmDisplayObj(pDispObj));
        AvmDisplayObj* pavm = reinterpret_cast<AvmDisplayObj*>(
            pstage ? AvmDisplayObjContainer::FromBase(pstage->GetAvmObjImpl()->ToAvmDispContainerBase()) : NULL);
        pavm->CreateASInstance(true);
        result = static_cast<Instances::fl_display::Stage*>(pavm->GetAS3Obj());
    }

    // Uninitialized room for a RectF that a callee fills in
    struct __declspec(align(16)) RectFStorage
    {
        float Edges[4];
        RectF& Get() { return *reinterpret_cast<RectF*>(Edges); }
    };

#pragma strict_gs_check(push, on)
    // The point (stage pixels) against the bounds or, with shapeFlag, the shapes; 3D objects map it through the
    // movie's screen-to-world state first.
    // MS2-FUNCTIONAL: the exe calls Matrix2F::TransformByInverse out of line (COMDAT 0x142447090); ours inlines it
    // @0x14244f0f0
    void DisplayObject::hitTestPoint(bool& result, Value::Number x, Value::Number y, bool shapeFlag)
    {
        result = false;
        RectF bounds = pDispObj->GetBounds(Matrix2F());
        if (bounds.IsNull())
            return;
        Render::PointF pt((float)x * 20.0f, (float)y * 20.0f);
        MovieImpl* proot = pDispObj->GetMovieImpl();
        if (proot && pDispObj->Is3D(true))
        {
            proot->SetNormalizedScreenCoords(pt);
            Matrix3F view;
            Matrix4F proj;
            Render::ScreenToWorld& stw = proot->GetScreenToWorld();
            if (pDispObj->GetProjectionMatrix3D(&proj))
                stw.SetProjection(proj);
            if (pDispObj->GetViewMatrix3D(&view))
                stw.SetView(view);
            Matrix3F world;
            pDispObj->GetWorldMatrix3D(&world);
            stw.SetWorld(world);
            stw.GetWorldPoint(&pt);
            result = pDispObj->PointTestLocal(pt, shapeFlag);
        }
        else
        {
            Matrix2F level;
            pDispObj->GetLevelMatrix(&level);
            Render::PointF local = level.TransformByInverse(pt);
            if (!(pDispObj->Flags & GFx::DisplayObjectBase::Mask_Scale9GridExists))
            {
                if (!bounds.Contains(local))
                    return;
                if (!shapeFlag)
                {
                    result = true;
                    return;
                }
            }
            result = pDispObj->PointTestLocal(local, shapeFlag);
        }
    }
#pragma strict_gs_check(pop)

#pragma strict_gs_check(push, on)
    // @0x14244ef60
    void DisplayObject::hitTestObject(bool& result, Instances::fl_display::DisplayObject* obj)
    {
        result = false;
        RectF bounds1 = pDispObj->GetBounds(Matrix2F());
        if (bounds1.IsNull() || !obj)
            return;
        RectF bounds2 = obj->pDispObj->GetBounds(Matrix2F());
        if (bounds2.IsNull())
            return;
        // EncloseTransform fills both rects; they are not zeroed first
        RectFStorage w1, w2;
        RectF& world1 = w1.Get();
        RectF& world2 = w2.Get();
        {
            Matrix2F m;
            pDispObj->GetWorldMatrix(&m);
            m.EncloseTransform(&world1, bounds1);
        }
        {
            Matrix2F m;
            obj->pDispObj->GetWorldMatrix(&m);
            m.EncloseTransform(&world2, bounds2);
        }
        result = world1.Intersects(world2);
    }
#pragma strict_gs_check(pop)
}}

namespace Instances { namespace fl_display
{
    // AS3 builtin string 45 (4.1.18 numbering)
    static const BuiltinType BI_mouseCursorChange = static_cast<BuiltinType>(45);

    // The stage's mouseCursorChange listener count (GFx::Stage +0x128; the GFx stage class is not recovered).
    static inline int& StageCursorListenerCount(GFx::DisplayObject* pstage)
    {
        return *reinterpret_cast<int*>(reinterpret_cast<UByte*>(pstage) + 0x128);
    }

    // @0x142447610
    SPtr<Instances::fl_display::DisplayObject> Stage::addChild(Instances::fl_display::DisplayObject* a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        DisplayObjectContainer::addChild(result, a0);
        return result;
    }

    // @0x142447800
    SPtr<Instances::fl_display::DisplayObject> Stage::addChildAt(Instances::fl_display::DisplayObject* a0, SInt32 a1)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        DisplayObjectContainer::addChildAt(result, a0, a1);
        return result;
    }

    // @0x142452010
    SPtr<Instances::fl_display::DisplayObject> Stage::removeChildAt(SInt32 a0)
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        DisplayObjectContainer::removeChildAt(result, a0);
        return result;
    }

    // @0x142447830
    void Stage::addEventListener(const Value& result, const ASString& type, const Value& listener, bool useCapture, SInt32 priority, bool useWeakReference)
    {
        EventDispatcher::addEventListener(result, type, listener, useCapture, priority, useWeakReference);
        if (type == static_cast<ASVM&>(GetVM()).GetBuiltin(BI_mouseCursorChange))
            ++StageCursorListenerCount(pDispObj);
    }

    // @0x142452040
    void Stage::removeEventListener(const Value& result, const ASString& type, const Value& listener, bool useCapture)
    {
        EventDispatcher::removeEventListener(result, type, listener, useCapture);
        if (type == static_cast<ASVM&>(GetVM()).GetBuiltin(BI_mouseCursorChange))
            --StageCursorListenerCount(pDispObj);
    }

    // @0x14244c420
    void Stage::frameRateGet(Value::Number& result)
    {
        MovieImpl* pmovie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        result = AsMovieSlots(pmovie)->GetMovieDef()->GetFrameRate();
    }

    // The focused character of controller 0's focus group.
    static Ptr<GFx::InteractiveObject> FocusedCharacter0(MovieImpl* pmovie)
    {
        return pmovie->FocusGroups[pmovie->FocusGroupIndexes[0]].LastFocused;
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<InteractiveObject>::operator= instance (0x14243d790); ours inlines it
    // @0x14244c080
    SF_NOINLINE void Stage::focusGet(SPtr<Instances::fl_display::InteractiveObject>& result)
    {
        Ptr<GFx::InteractiveObject> focused = FocusedCharacter0(static_cast<ASVM&>(GetVM()).GetMovieImpl());
        if (focused)
        {
            // the AS3 part (AS3::AvmDisplayObj, as3_avm.h) sits 0x30 before its AvmInteractiveObjBase interface and
            // keeps the object raw at +0x10 or as a tagged SPtr at +0x08
            AvmInteractiveObjBase* pavm = focused->GetAvmIntObj();
            const UPInt* pas3 = pavm ? reinterpret_cast<const UPInt*>(reinterpret_cast<UByte*>(pavm) - 0x30) : NULL;
            UPInt raw = pas3[2];
            if (!raw)
                raw = pas3[1];
            if (raw & 1)
                raw -= 1;
            Instances::fl_display::DisplayObject* ido = reinterpret_cast<Instances::fl_display::DisplayObject*>(raw);
            BuiltinTraitsType tt = ido->GetTraits().GetTraitsType();
            if (tt == Traits_InteractiveObject || tt >= Traits_DisplayObjectContainer)
            {
                result = static_cast<Instances::fl_display::InteractiveObject*>(ido);
                return;
            }
        }
        result = NULL;
    }

    // @0x14244c2b0
    void Stage::focusSet(const Value& result, Instances::fl_display::InteractiveObject* value)
    {
        SF_UNUSED(result);
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        Ptr<GFx::InteractiveObject> newfocus;
        if (value)
            newfocus = static_cast<GFx::InteractiveObject*>(value->pDispObj.GetPtr());
        Ptr<GFx::InteractiveObject> focused = FocusedCharacter0(asvm.GetMovieImpl());
        if (focused != newfocus)
            asvm.GetMovieImpl()->SetKeyboardFocusTo(newfocus, 0, GFx_FocusMovedByAS);
    }

    // @0x142449be0
    void Stage::deviceOrientationGet(ASString& result)
    {
        const char* porient;
        switch (static_cast<ASVM&>(GetVM()).GetMovieImpl()->DeviceOrientation)
        {
        case 0:  porient = "default"; break;
        case 1:  porient = "rotatedLeft"; break;
        case 2:  porient = "rotatedRight"; break;
        case 3:  porient = "upsideDown"; break;
        default: porient = "unknown"; break;
        }
        result = GetVM().GetStringManager().CreateConstString(porient);
    }

    // @0x142447b90
    void Stage::alignGet(ASString& result)
    {
        MovieImpl* pmovie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        const char* palign;
        switch (AsMovieSlots(pmovie)->GetViewAlignment())
        {
        case MovieSlots418::Align_TopCenter:    palign = "T"; break;
        case MovieSlots418::Align_BottomCenter: palign = "B"; break;
        case MovieSlots418::Align_CenterLeft:   palign = "L"; break;
        case MovieSlots418::Align_CenterRight:  palign = "R"; break;
        case MovieSlots418::Align_TopLeft:      palign = "LT"; break;
        case MovieSlots418::Align_TopRight:     palign = "TR"; break;
        case MovieSlots418::Align_BottomLeft:   palign = "LB"; break;
        case MovieSlots418::Align_BottomRight:  palign = "RB"; break;
        default:                                palign = ""; break;
        }
        result += GetVM().GetStringManager().CreateConstString(palign);
    }

    // @0x142447cb0
    void Stage::alignSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        ASString upper(value.ToUpperNode());
        UInt32 c0 = 0, c1 = 0;
        const int len = (int)upper.GetLength();
        if (len > 0)
        {
            c0 = upper.GetCharAt(0);
            if (len > 1)
                c1 = upper.GetCharAt(1);
        }
        // Two-letter codes in either order pick a corner, one letter an edge.
        MovieSlots418::AlignType a;
        if ((c0 == 'T' && c1 == 'L') || (c0 == 'L' && c1 == 'T'))
            a = MovieSlots418::Align_TopLeft;
        else if ((c0 == 'T' && c1 == 'R') || (c0 == 'R' && c1 == 'T'))
            a = MovieSlots418::Align_TopRight;
        else if ((c0 == 'B' && c1 == 'L') || (c0 == 'L' && c1 == 'B'))
            a = MovieSlots418::Align_BottomLeft;
        else if ((c0 == 'B' && c1 == 'R') || (c0 == 'R' && c1 == 'B'))
            a = MovieSlots418::Align_BottomRight;
        else if (c0 == 'T')
            a = MovieSlots418::Align_TopCenter;
        else if (c0 == 'B')
            a = MovieSlots418::Align_BottomCenter;
        else if (c0 == 'L')
            a = MovieSlots418::Align_CenterLeft;
        else if (c0 == 'R')
            a = MovieSlots418::Align_CenterRight;
        else
            a = MovieSlots418::Align_Center;
        AsMovieSlots(static_cast<ASVM&>(GetVM()).GetMovieImpl())->SetViewAlignment(a);
    }

    // @0x142452500
    void Stage::scaleModeGet(ASString& result)
    {
        MovieImpl* pmovie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        const char* pmode;
        switch (AsMovieSlots(pmovie)->GetViewScaleMode())
        {
        case MovieSlots418::SM_NoScale:  pmode = "noScale"; break;
        case MovieSlots418::SM_ExactFit: pmode = "exactFit"; break;
        case MovieSlots418::SM_NoBorder: pmode = "noBorder"; break;
        default:                         pmode = "showAll"; break;
        }
        result += GetVM().GetStringManager().CreateConstString(pmode);
    }

    // @0x1424525c0
    void Stage::scaleModeSet(const Value& result, const ASString& value)
    {
        SF_UNUSED(result);
        ASString mode(value);
        MovieImpl* pmovie = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        MovieSlots418::ScaleModeType sm;
        if (!String::CompareNoCase(mode.ToCStr(), "noScale"))
            sm = MovieSlots418::SM_NoScale;
        else if (!String::CompareNoCase(mode.ToCStr(), "exactFit"))
            sm = MovieSlots418::SM_ExactFit;
        else if (!String::CompareNoCase(mode.ToCStr(), "noBorder"))
            sm = MovieSlots418::SM_NoBorder;
        else
            sm = MovieSlots418::SM_ShowAll;
        if (pmovie)
            AsMovieSlots(pmovie)->SetViewScaleMode(sm);
    }

    // @0x14244e5b0
    void Stage::heightGet(Value::Number& result)
    {
        Render::RectF r = pDispObj->GetBounds(pDispObj->GetMatrix());
        result = TwipsToPixels((Value::Number)r.Height());
    }

    // @0x142454a90
    void Stage::widthGet(Value::Number& result)
    {
        Render::RectF r = pDispObj->GetBounds(pDispObj->GetMatrix());
        result = TwipsToPixels((Value::Number)r.Width());
    }

    // @0x142448f50
    void Loader::contentGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        if ((unsigned)static_cast<GFx::DisplayObjContainer*>(pDispObj.GetPtr())->mDisplayList.GetCount() > 0)
            getChildAt(result, 0);
        else
            result = NULL;
    }

    // @0x142448f20
    SPtr<Instances::fl_display::DisplayObject> Loader::contentGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        contentGet(result);
        return result;
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<LoaderInfo>::operator= instance (0x14243d800); ours inlines it
    // @0x142449020
    void Loader::contentLoaderInfoGet(SPtr<Instances::fl_display::LoaderInfo>& result)
    {
        result = pContentLoaderInfo;
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<LoaderInfo>::operator= instance (0x14243d800); ours inlines it
    // @0x142448ff0
    SPtr<Instances::fl_display::LoaderInfo> Loader::contentLoaderInfoGet()
    {
        SPtr<Instances::fl_display::LoaderInfo> result;
        contentLoaderInfoGet(result);
        return result;
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<DisplayObject>::operator= instance (0x14243d5d0); ours inlines it
    // @0x142448fe0
    void LoaderInfo::contentGet(SPtr<Instances::fl_display::DisplayObject>& result)
    {
        result = Content;
    }

    // MS2-FUNCTIONAL: exe calls the out-of-line SPtr<DisplayObject>::operator= instance (0x14243d5d0); ours inlines it
    // @0x142448fb0
    SPtr<Instances::fl_display::DisplayObject> LoaderInfo::contentGet()
    {
        SPtr<Instances::fl_display::DisplayObject> result;
        contentGet(result);
        return result;
    }

    // @0x1424498d0
    void MovieClip::currentLabelsGet(SPtr<Instances::fl::Array>& result)
    {
        SPtr<Instances::fl_display::Scene> scene;
        currentSceneGet(scene);
        scene->labelsGet(result);
    }

    // @0x142449870
    SPtr<Instances::fl::Array> MovieClip::currentLabelsGet()
    {
        SPtr<Instances::fl::Array> result;
        currentLabelsGet(result);
        return result;
    }
    // The AS3 container half of a display object container.
    static SF_FORCEINLINE AvmDisplayObjContainer* ToAvmDispContainer(GFx::DisplayObject* p)
    {
        return p ? AvmDisplayObjContainer::FromBase(p->GetAvmObjImpl()->ToAvmDispContainerBase()) : NULL;
    }

#pragma strict_gs_check(push, on)
    // The scriptable display objects under a stage point (pixels) as a new Array of their AS3 objects, each made
    // on first use.
    // MS2-FUNCTIONAL: register allocation (exe keeps this in rsi) and stack slots; the exe re-tests the inlined container / AvmDisplayObj casts for null
    // @0x14244d1e0
    SF_NOINLINE void DisplayObjectContainer::getObjectsUnderPoint(SPtr<Instances::fl::Array>& result, Instances::fl_geom::Point* point)
    {
        GFx::DisplayObject* pcont = pDispObj;
        Render::Matrix2F world;
        pcont->GetWorldMatrix(&world);
        Render::PointF global((float)Render::PixelsToTwips(point->x), (float)Render::PixelsToTwips(point->y));
        Render::PointF local = world.TransformByInverse(global);
        ArrayDH<Ptr<DisplayObjectBase> > objects(GetVM().GetMemoryHeap());
        ToAvmDispContainer(pcont)->GetObjectsUnderPoint(&objects, local);
        SPtr<Instances::fl::Array> arr = GetVM().MakeArray();
        for (UPInt i = 0, n = objects.GetSize(); i < n; ++i)
        {
            DisplayObjectBase* pch = objects[i];
            if (pch->IsScriptableObject())
            {
                AvmDisplayObj* pavm = ToAvmDisplayObj(static_cast<GFx::DisplayObject*>(pch));
                if (!pavm->GetAS3Obj())
                    pavm->CreateASInstance(true);
                arr->SA.PushBack(Value(pavm->GetAS3Obj()));
            }
        }
        result = arr;
    }
#pragma strict_gs_check(pop)

    // MS2-FUNCTIONAL: exe tail-calls SwapChildren for a null container and merges the AS3-part paths; ours
    // duplicates the call tail per path. Same loads and calls.
    // @0x142453890
    SF_NOINLINE void DisplayObjectContainer::swapChildren(const Value& result, Instances::fl_display::DisplayObject* child1,
                                              Instances::fl_display::DisplayObject* child2)
    {
        SF_UNUSED(result);
        if (child1->pDispObj && child2->pDispObj)
        {
            AvmDisplayObjContainer* avmObj = ToAvmDispContainer(pDispObj);
            avmObj->SwapChildren(child1->pDispObj, child2->pDispObj);
        }
    }

    // MS2-FUNCTIONAL: exe tail-calls the out-of-line Value::SetUndefined (0x142423b90) and Assign(Object*); ours inlines
    // SetUndefined and shrink-wraps the rdi save. Same checks and calls.
    // @0x142451dc0
    SF_NOINLINE void DisplayObjectContainer::removeChild(Value& result, unsigned argc, const Value* argv)
    {
        if (argc < 1 || argv[0].IsNullOrUndefined() || !argv[0].IsObject())
        {
            VM& vm = GetVM();
            vm.ThrowTypeError(VM::Error(VM::eNullPointerError, vm, "child"));
            return;
        }
        AS3::Object* object = argv[0].GetObject();
        if (object)
        {
            const Traits& tr = object->GetTraits();
            if (tr.GetTraitsType() >= Traits_DisplayObject_Begin && tr.GetTraitsType() < Traits_DisplayObject_End &&
                tr.IsInstanceTraits())
            {
                Instances::fl_display::DisplayObject* child = static_cast<Instances::fl_display::DisplayObject*>(object);
                if (child->pDispObj)
                {
                    AvmDisplayObjContainer* avmObj = ToAvmDispContainer(pDispObj);
                    avmObj->RemoveChild(child->pDispObj);
                }
                result = child;
                return;
            }
        }
        result.SetUndefined();
    }

    // @0x14244cde0
    SF_NOINLINE void DisplayObjectContainer::getChildByName(SPtr<Instances::fl_display::DisplayObject>& result, const ASString& name)
    {
        SPtr<Instances::fl_display::DisplayObject> pchild = ToAvmDispContainer(pDispObj)->GetAS3ChildByName(name);
        if (!pchild)
            result = NULL;
        else
            result = pchild;
    }

    // @0x14244cca0
    SF_NOINLINE void DisplayObjectContainer::getChildAt(SPtr<Instances::fl_display::DisplayObject>& result, SInt32 index)
    {
        SPtr<Instances::fl_display::DisplayObject> pchild = ToAvmDispContainer(pDispObj)->GetAS3ChildAt(index);
        if (!pchild)
        {
            VM& vm = GetVM();
            vm.ThrowRangeError(VM::Error(VM::eParamRangeError, vm));
        }
        else
            result = pchild;
    }

    // @0x1424474f0
    SF_NOINLINE void DisplayObjectContainer::addChild(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject* child)
    {
        if (!child)
        {
            VM& vm = GetVM();
            vm.ThrowTypeError(VM::Error(VM::eNullPointerError, vm, "child"));
            return;
        }
        if (child == this)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eAddObjectItselfError, vm));
            return;
        }
        GFx::DisplayObject* pcont = pDispObj;
        if (!child->pDispObj)
            child->CreateStageObject();
        ToAvmDispContainer(pcont)->AddChild(child->pDispObj);
        result = child;
    }

    // @0x142447660
    SF_NOINLINE void DisplayObjectContainer::addChildAt(SPtr<Instances::fl_display::DisplayObject>& result, Instances::fl_display::DisplayObject* child,
                                                        SInt32 index)
    {
        if (!child)
        {
            VM& vm = GetVM();
            vm.ThrowTypeError(VM::Error(VM::eNullPointerError, vm, "child"));
            return;
        }
        if (child == this)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eAddObjectItselfError, vm));
            return;
        }
        GFx::DisplayObjContainer* pcont = static_cast<GFx::DisplayObjContainer*>(pDispObj.GetPtr());
        if (!child->pDispObj)
            child->CreateStageObject();
        result = NULL;
        if (index < 0 || index > (SInt32)pcont->mDisplayList.GetCount())
        {
            VM& vm = GetVM();
            vm.ThrowRangeError(VM::Error(VM::eParamRangeError, vm));
        }
        else
        {
            ToAvmDispContainer(pcont)->AddChildAt(child->pDispObj, index);
            result = child;
        }
    }

    // MS2-FUNCTIONAL: exe strips the collectible tag of the child's AS3 object with branches; ours with cmov
    // @0x142451ef0
    SF_NOINLINE void DisplayObjectContainer::removeChildAt(SPtr<Instances::fl_display::DisplayObject>& result, SInt32 index)
    {
        GFx::DisplayObjContainer* pcont = static_cast<GFx::DisplayObjContainer*>(pDispObj.GetPtr());
        result = NULL;
        AvmDisplayObjContainer* pavm = ToAvmDispContainer(pcont);
        GFx::DisplayObjectBase* pchild = pcont->GetChildAt(index);
        if (pchild)
        {
            GFx::DisplayObject* pdisp = static_cast<GFx::DisplayObject*>(pchild);
            if (ToAvmDisplayObj(pdisp)->GetAS3Obj())
                result = ToAvmDisplayObj(pdisp)->GetAS3Obj();
        }
        else
        {
            VM& vm = GetVM();
            vm.ThrowRangeError(VM::Error(VM::eParamRangeError, vm));
            return;
        }
        pavm->RemoveChildAt(index);
    }

    // @0x14244cee0
    void DisplayObjectContainer::getChildIndex(SInt32& result, Instances::fl_display::DisplayObject* child)
    {
        if (!child)
        {
            VM& vm = GetVM();
            vm.ThrowTypeError(VM::Error(VM::eNullPointerError, vm, "child"));
            return;
        }
        SPInt index = static_cast<GFx::DisplayObjContainer*>(pDispObj.GetPtr())->mDisplayList.FindDisplayIndex(child->pDispObj);
        if (index < 0)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eMustBeChildError, vm, "DisplayObject"));
            return;
        }
        result = (SInt32)index;
    }

    // @0x142453900
    void DisplayObjectContainer::swapChildrenAt(const Value& result, SInt32 index1, SInt32 index2)
    {
        SF_UNUSED(result);
        const unsigned i1 = index1 >= 0 ? index1 : 0;
        const unsigned i2 = index2 >= 0 ? index2 : 0;
        ToAvmDispContainer(pDispObj)->SwapChildrenAt(i1, i2);
    }

    // @0x142453960
    void Stage::swapChildrenAt(const Value& result, SInt32 index1, SInt32 index2)
    {
        SF_UNUSED(result);
        const unsigned i1 = index1 >= 0 ? index1 : 0;
        const unsigned i2 = index2 >= 0 ? index2 : 0;
        ToAvmDispContainer(pDispObj)->SwapChildrenAt(i1, i2);
    }

    // MS2-FUNCTIONAL: exe loads this->pDispObj before the child test; ours after it
    // @0x142452d20
    void DisplayObjectContainer::setChildIndex(const Value& result, Instances::fl_display::DisplayObject* child, SInt32 index)
    {
        SF_UNUSED(result);
        if (child->pDispObj)
        {
            const unsigned idx = index >= 0 ? index : 0;
            AvmDisplayObjContainer* pcont = ToAvmDispContainer(pDispObj);
            pcont->SetChildIndex(child->pDispObj, idx);
        }
    }

    // MS2-FUNCTIONAL: exe loads this->pDispObj before the child test; ours after it
    // @0x142452d90
    void Stage::setChildIndex(const Value& result, Instances::fl_display::DisplayObject* child, SInt32 index)
    {
        SF_UNUSED(result);
        if (child->pDispObj)
        {
            const unsigned idx = index >= 0 ? index : 0;
            AvmDisplayObjContainer* pcont = ToAvmDispContainer(pDispObj);
            pcont->SetChildIndex(child->pDispObj, idx);
        }
    }

    // @0x142453570
    void Stage::stageHeightGet(SInt32& result)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        result = (SInt32)asvm.GetMovieImpl()->AsMovieInterface()->GetVisibleFrameRect().Height();
    }

    // @0x1424535f0
    void Stage::stageWidthGet(SInt32& result)
    {
        ASVM& asvm = static_cast<ASVM&>(GetVM());
        result = (SInt32)asvm.GetMovieImpl()->AsMovieInterface()->GetVisibleFrameRect().Width();
    }

    // @0x14244e540
    void LoaderInfo::heightGet(SInt32& result)
    {
        if (Content)
        {
            GFx::DisplayObject* pdisp = Ptr<GFx::DisplayObject>(Content->pDispObj);
            result = (SInt32)pdisp->GetResourceMovieDef()->GetHeight();
            return;
        }
        result = 0;
    }

    // @0x142454a20
    void LoaderInfo::widthGet(SInt32& result)
    {
        if (Content)
        {
            GFx::DisplayObject* pdisp = Ptr<GFx::DisplayObject>(Content->pDispObj);
            result = (SInt32)pdisp->GetResourceMovieDef()->GetWidth();
            return;
        }
        result = 0;
    }

    // MovieDefImpl's GetBytesLoaded / GetFileBytes.
    static inline UInt32 MovieBytesLoaded(MovieDefImpl* pdef) { return pdef->pBindData->GetBytesLoaded(); }
    static inline UInt32 MovieFileBytes(MovieDefImpl* pdef)   { return pdef->pBindData->GetDataDef()->GetFileBytes(); }

    // @0x142448870
    void LoaderInfo::bytesLoadedGet(UInt32& result)
    {
        if (GetContentDispObj())
            result = MovieBytesLoaded(GetContentDispObj()->GetResourceMovieDef());
        else
            result = BytesLoaded;
    }

    // @0x1424488d0
    void LoaderInfo::bytesTotalGet(UInt32& result)
    {
        if (GetContentDispObj())
            result = MovieFileBytes(GetContentDispObj()->GetResourceMovieDef());
        else
            result = BytesTotal;
    }

    // @0x14244c3b0
    void LoaderInfo::frameRateGet(Value::Number& result)
    {
        if (Content)
        {
            GFx::DisplayObject* pdisp = Ptr<GFx::DisplayObject>(Content->pDispObj);
            result = pdisp->GetResourceMovieDef()->GetFrameRate();
            return;
        }
        result = 0;
    }

    // @0x1424539c0
    void LoaderInfo::swfVersionGet(UInt32& result)
    {
        if (Content)
        {
            GFx::DisplayObject* pdisp = Ptr<GFx::DisplayObject>(Content->pDispObj);
            result = pdisp->GetResourceMovieDef()->GetVersion();
            return;
        }
        result = 0;
    }

    // @0x142450020
    void LoaderInfo::loaderURLGet(ASString& result)
    {
        if (pLoader)
        {
            MovieDefImpl* pdef = pLoader->pDispObj->GetResourceMovieDef();
            result = GetVM().GetStringManager().CreateString(pdef->GetFileURL());
        }
        else
            result = GetVM().GetStringManager().CreateEmptyString();
    }

    // @0x1424547b0
    void LoaderInfo::urlGet(ASString& result)
    {
        if (Content)
        {
            GFx::DisplayObject* pdisp = Ptr<GFx::DisplayObject>(Content->pDispObj);
            MovieDefImpl* pdef = pdisp->GetResourceMovieDef();
            result = GetVM().GetStringManager().CreateString(pdef->GetFileURL());
        }
        else
            result = GetVM().GetStringManager().CreateEmptyString();
    }
    // @0x142454610
    void BitmapData::transparentGet(bool& result)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        result = reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr())->IsTransparent();
    }

    // MS2-FUNCTIONAL: the exe inlines the BitmapData constructor (0x14243a220, defined with the class in as3_06)
    // @0x142448a00
    void BitmapData::clone(SPtr<Instances::fl_display::BitmapData>& result)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        InstanceTraits::Traits& itr = GetInstanceTraits();
        result = Pickable<BitmapData>(new(itr.Alloc()) BitmapData(itr));
        result->Width = Width;
        result->Height = Height;
        result->Transparent = Transparent;
        result->Unk59 = Unk59;
        Render::DrawableImageContext* pcontext =
            (Render::DrawableImageContext*)FUN_14256f220(static_cast<ASVM&>(GetVM()).GetMovieImpl());
        Render::DrawableImage* pcopy = new(Memory::Alloc(200)) Render::DrawableImage(Transparent, pImage, pcontext);
        result->pImage = *reinterpret_cast<Render::ImageBase*>(pcopy);
    }

    // @0x142447390
    void ByteArrayPixelProvider::WriteNextPixel(UInt32 v)
    {
        Instances::fl_utils::ByteArray* pbytes = pBytes;
        pbytes->writeUnsignedInt(Value::GetUndefined(), v);
    }

    // @0x1424473c0
    void VectorPixelProvider::WriteNextPixel(UInt32 v)
    {
        pVector->V.Set(Index++, Value(v), pVector->GetVM().GetClassTraitsUInt());
    }

#pragma strict_gs_check(push, on)
    // The pixels of rect into a new ByteArray (4 bytes each); null for an empty rect.
    // MS2-FUNCTIONAL: frame size / register allocation (exe shrink-wraps the callee saves)
// @0x14244d560
    void BitmapData::getPixels(SPtr<Instances::fl_utils::ByteArray>& result, Instances::fl_geom::Rectangle* rect)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!rect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "rect"));
        }
        else
        {
            Render::Rect<SInt32> r((SInt32)rect->x, (SInt32)rect->y, (SInt32)(rect->x + rect->width), (SInt32)(rect->y + rect->height));
            Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
            if (r.Width() == 0 || r.Height() == 0)
                return;
            if (!GetVM().ConstructBuiltinObject(result, "flash.utils.ByteArray"))
            {
                result = NULL;
                return;
            }
            result->lengthSet(Value::GetUndefined(), r.Width() * r.Height() * 4);
            ByteArrayPixelProvider provider(result);
            pimage->GetPixels(provider, r);
        }
    }

    // The pixels of rect into a new Vector.<uint>; null for an empty rect.
    // MS2-FUNCTIONAL: frame size / register allocation (exe shrink-wraps the callee saves)
// @0x14244daf0
    void BitmapData::getVector(SPtr<Instances::fl_vec::Vector_uint>& result, Instances::fl_geom::Rectangle* rect)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!rect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "rect"));
        }
        else
        {
            Render::Rect<SInt32> r((SInt32)rect->x, (SInt32)rect->y, (SInt32)(rect->x + rect->width), (SInt32)(rect->y + rect->height));
            Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
            if (r.Width() == 0 || r.Height() == 0)
                return;
            if (!GetVM().ConstructBuiltinObject(result, "Vector.<uint>"))
            {
                result = NULL;
                return;
            }
            // The length is set to four entries a pixel, as for the ByteArray.
            result->lengthSet(Value::GetUndefined(), r.Width() * r.Height() * 4);
            VectorPixelProvider provider(result);
            pimage->GetPixels(provider, r);
        }
    }

    // The pixels of inputByteArray (from its position) into rect; EOFError when it runs out first.
    // MS2-FUNCTIONAL: stack slot order / register allocation
// @0x142452f10
    void BitmapData::setPixels(const Value& result, Instances::fl_geom::Rectangle* rect, Instances::fl_utils::ByteArray* inputByteArray)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!rect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "rect"));
        }
        else if (!inputByteArray)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "inputByteArray"));
        }
        else
        {
            ByteArrayPixelProvider provider(inputByteArray);
            {
                Render::Rect<SInt32> r((SInt32)rect->x, (SInt32)rect->y, (SInt32)(rect->x + rect->width), (SInt32)(rect->y + rect->height));
                Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
                if (pimage->SetPixels(r, provider))
                    return;
            }
            if (provider.pBytes->GetLength() <= inputByteArray->GetLength())
                return;
            VM& vm = GetVM();
            vm.ThrowError(VM::Error(VM::eEOFError, vm, "EOF"));
        }
    }

    // The pixels of inputVector into rect; RangeError when it is too short.
    // MS2-FUNCTIONAL: stack slot order / register allocation (this/inputVector in rdi/rbx swapped)
// @0x1424530a0
    void BitmapData::setVector(const Value& result, Instances::fl_geom::Rectangle* rect, Instances::fl_vec::Vector_uint* inputVector)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!rect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "rect"));
        }
        else if (!inputVector)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "inputVector"));
        }
        else
        {
            UInt32 have, need;
            VectorPixelProvider provider(inputVector);
            {
                Render::Rect<SInt32> r((SInt32)rect->x, (SInt32)rect->y, (SInt32)(rect->x + rect->width), (SInt32)(rect->y + rect->height));
                Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
                if (pimage->SetPixels(r, provider))
                    return;
            }
            inputVector->lengthGet(have);
            provider.pVector->lengthGet(need);
            if (have >= need)
                return;
            VM& vm = GetVM();
            vm.ThrowError(VM::Error(VM::eOutOfRangeError, vm, "inputVector not large enough to read all the pixel data."));
        }
    }
#pragma strict_gs_check(pop)

#pragma strict_gs_check(push, on)
    // The bounds of the pixels matching color under mask, as a new flash.geom.Rectangle.
    // MS2-FUNCTIONAL: register use (the exe keeps the pImage load in rax for the this-cmov)
    // @0x14244cfe0
    SF_NOINLINE void BitmapData::getColorBoundsRect(SPtr<Instances::fl_geom::Rectangle>& result, UInt32 mask, UInt32 color, bool findColor)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
        Render::Rect<SInt32> bounds = pimage->GetColorBoundsRect(mask, color, findColor);
        Value args[4] = { Value(bounds.x1), Value(bounds.y1), Value(bounds.Width()), Value(bounds.Height()) };
        GetVM().ConstructBuiltinObject(result, "flash.geom.Rectangle", 4, args);
    }
#pragma strict_gs_check(pop)

    // The difference of two equally sized bitmaps as a new BitmapData; -3 / -4 when the widths / heights differ.
    // MS2-FUNCTIONAL: register assignment (exe keeps this in rdi and result in rsi; ours rsi / rbp)
    // @0x142448d10
    void BitmapData::compare(Value& result, Instances::fl_display::BitmapData* otherBitmapData)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!otherBitmapData)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "otherBitmapData"));
        }
        else
        {
        SInt32 w, h;
        otherBitmapData->widthGet(w);
        otherBitmapData->heightGet(h);
        if ((SInt32)pImage->GetSize().Width != w)
        {
            result.SetSInt32(-3);
            return;
        }
        if ((SInt32)pImage->GetSize().Height != h)
        {
            result.SetSInt32(-4);
            return;
        }
        Render::ImageBase* pother = otherBitmapData->pImage;
        SPtr<BitmapData> pdiff;
        clone(pdiff);
        Render::DrawableImage* pdst = pdiff ? reinterpret_cast<Render::DrawableImage*>(pdiff->pImage.GetPtr()) : NULL;
        pdst->Compare(pImage, pother);
        result = pdiff;
        }
    }

#pragma strict_gs_check(push, on)
    // MS2-FUNCTIONAL: the exe tests the arguments one by one (pImage kept in r8); ours loads them up front and
    // lays the error blocks out after the copy
    // @0x142449220
    void BitmapData::copyChannel(const Value& result, Instances::fl_display::BitmapData* sourceBitmapData,
                                 Instances::fl_geom::Rectangle* sourceRect, Instances::fl_geom::Point* destPoint,
                                 UInt32 sourceChannel, UInt32 destChannel)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!sourceBitmapData)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceBitmapData"));
        }
        else if (!sourceRect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceRect"));
        }
        else if (!destPoint)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "destPoint"));
        }
        else
        {
            Render::Point<SInt32> dp((SInt32)destPoint->x, (SInt32)destPoint->y);
            Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
            Render::Rect<SInt32> rect((SInt32)sourceRect->x, (SInt32)sourceRect->y,
                                      (SInt32)(sourceRect->x + sourceRect->width), (SInt32)(sourceRect->y + sourceRect->height));
            pimage->CopyChannel(sourceBitmapData->pImage, rect, dp, sourceChannel, destChannel);
        }
    }
#pragma strict_gs_check(pop)

#pragma strict_gs_check(push, on)
    // MS2-FUNCTIONAL: stack slot order of the rect/points and the error temporaries differs (register allocation)
    // @0x142449440
    void BitmapData::copyPixels(const Value& result, Instances::fl_display::BitmapData* sourceBitmapData,
                                Instances::fl_geom::Rectangle* sourceRect, Instances::fl_geom::Point* destPoint,
                                Instances::fl_display::BitmapData* alphaBitmapData, Instances::fl_geom::Point* alphaPoint,
                                bool mergeAlpha)
    {
        SF_UNUSED(result);
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
        }
        else if (!sourceBitmapData)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceBitmapData"));
        }
        else if (!sourceRect)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "sourceRect"));
        }
        else if (!destPoint)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eNullPointerError, vm, "destPoint"));
        }
        else
        {
            Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
            Render::ImageBase* palpha = alphaBitmapData ? alphaBitmapData->pImage.GetPtr() : NULL;
            if (!sourceBitmapData->pImage || !pimage)
                return;
            // The alpha point is left unset without an alphaPoint; the image only reads it with an alpha source.
            Render::Point<SInt32> ap(Render::Point<SInt32>::NoInit);
            if (alphaPoint)
            {
                ap.x = (SInt32)alphaPoint->x;
                ap.y = (SInt32)alphaPoint->y;
            }
            Render::Point<SInt32> dp((SInt32)destPoint->x, (SInt32)destPoint->y);
            Render::Rect<SInt32> rect((SInt32)sourceRect->x, (SInt32)sourceRect->y,
                                      (SInt32)(sourceRect->x + sourceRect->width), (SInt32)(sourceRect->y + sourceRect->height));
            pimage->CopyPixels(sourceBitmapData->pImage, rect, dp, palpha, &ap, mergeAlpha);
        }
    }
#pragma strict_gs_check(pop)

#pragma strict_gs_check(push, on)
    // The alpha hit test of this bitmap at firstPoint against a Rectangle, a Point (a 1x1 rect), the image of a
    // Bitmap or a second BitmapData at secondBitmapDataPoint.
    // MS2-FUNCTIONAL: register allocation and frame size differ (the exe re-reads pImage after the check)
    // @0x14244ed10
    void BitmapData::hitTest(bool& result, Instances::fl_geom::Point* firstPoint, UInt32 firstAlphaThreshold,
                             const Value& secondObject, Instances::fl_geom::Point* secondBitmapDataPoint,
                             UInt32 secondAlphaThreshold)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        Render::DrawableImage* pimage = this ? reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr()) : NULL;
        Render::Point<SInt32> fp((SInt32)firstPoint->x, (SInt32)firstPoint->y);
        Render::Rect<SInt32> rect;
        if (FUN_1425145d0(GetVM(), secondObject, "flash.geom.Rectangle"))
        {
            Instances::fl_geom::Rectangle* r = static_cast<Instances::fl_geom::Rectangle*>(secondObject.GetObject());
            rect = Render::Rect<SInt32>((SInt32)r->x, (SInt32)r->y, (SInt32)(r->x + r->width), (SInt32)(r->y + r->height));
        }
        else if (FUN_1425145d0(GetVM(), secondObject, "flash.geom.Point"))
        {
            Instances::fl_geom::Point* pt = static_cast<Instances::fl_geom::Point*>(secondObject.GetObject());
            SInt32 x = (SInt32)pt->x, y = (SInt32)pt->y;
            rect = Render::Rect<SInt32>(x, y, x + 1, y + 1);
        }
        else
        {
            Render::ImageBase* psecond = NULL;
            Render::Point<SInt32> sp(0, 0);
            if (FUN_1425145d0(GetVM(), secondObject, "flash.display.Bitmap"))
            {
                Instances::fl_display::Bitmap* pbitmap = static_cast<Instances::fl_display::Bitmap*>(secondObject.GetObject());
                if (!pbitmap->pBitmapData)
                    return;
                ImageResource* pres = pbitmap->pBitmapData->GetImageResource();
                if (!pres)
                    return;
                psecond = pres->GetImage();
                if (!psecond)
                    return;
            }
            else if (FUN_1425145d0(GetVM(), secondObject, "flash.display.BitmapData"))
            {
                if (secondBitmapDataPoint)
                    sp = Render::Point<SInt32>((SInt32)secondBitmapDataPoint->x, (SInt32)secondBitmapDataPoint->y);
                Instances::fl_display::BitmapData* pdata = static_cast<Instances::fl_display::BitmapData*>(secondObject.GetObject());
                psecond = pdata ? pdata->pImage.GetPtr() : NULL;
            }
            else
            {
                VM& vm = GetVM();
                vm.ThrowArgumentError(VM::Error(VM::eInvalidArgumentError, vm, "secondObject"));
                return;
            }
            result = pimage->HitTest(psecond, fp, sp, firstAlphaThreshold, secondAlphaThreshold);
            return;
        }
        result = pimage->HitTest(fp, rect, firstAlphaThreshold);
    }
#pragma strict_gs_check(pop)

    // @0x14244d460
    void BitmapData::getPixel32(UInt32& result, SInt32 x, SInt32 y)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        result = reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr())->GetPixel32(x, y).ToColor32();
    }

    // @0x14244d4d0
    void BitmapData::getPixel(UInt32& result, SInt32 x, SInt32 y)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        result = reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr())->GetPixel(x, y).ToColor32();
    }

    // @0x142452e10
    void BitmapData::setPixel32(const Value& result, SInt32 x, SInt32 y, UInt32 color)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        SF_UNUSED(result);
        reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr())->SetPixel32(x, y, Render::Color(color));
    }

    // @0x142452e90
    void BitmapData::setPixel(const Value& result, SInt32 x, SInt32 y, UInt32 color)
    {
        if (!pImage)
        {
            VM& vm = GetVM();
            vm.ThrowArgumentError(VM::Error(VM::eInvalidBitmapData, vm, "Invalid BitmapData"));
            return;
        }
        SF_UNUSED(result);
        reinterpret_cast<Render::DrawableImage*>(pImage.GetPtr())->SetPixel(x, y, Render::Color(color));
    }
    // @0x14244fe10
    void Loader::load(const Value& result, Instances::fl_net::URLRequest* request, Instances::fl_system::LoaderContext* context)
    {
        SF_UNUSED2(result, context);
        MovieRoot* root = static_cast<ASVM&>(GetVM()).GetMovieRoot();
        // unload the previous content first
        if (pContentLoaderInfo && pContentLoaderInfo->GetContentDispObj())
            root->UnloadMovie(this);
        root->AddNewLoadQueueEntry(request, this);
    }

    // @0x14244fe80
    void Loader::loadBytes(const Value& result, Instances::fl_utils::ByteArray* bytes, Instances::fl_system::LoaderContext* context)
    {
        SF_UNUSED2(result, context);
        MovieRoot* root = static_cast<ASVM&>(GetVM()).GetMovieRoot();
        if (pContentLoaderInfo && pContentLoaderInfo->GetContentDispObj())
            root->UnloadMovie(this);
        root->AddNewLoadQueueEntry(bytes, this);
    }
}}

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$09K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142455e90
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142455ef0
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0M@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142455f60
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0N@$$CBVValue@456@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142455fc0
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0O@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456030
// MS2-PIN: ?Func@?$ThunkFunc1@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0P@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456090
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456250
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BB@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456470
// MS2-PIN: ?Func@?$ThunkFunc0@VKeyboardEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424564e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456680
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424566e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456740
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424567a0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456800
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456860
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456a20
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$06_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456a80
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$07$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456ae0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$08_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456b40
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$09$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456ba0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0L@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456c00
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0M@$$CBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456c60
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0N@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456cd0
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0O@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456d40
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0P@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456dd0
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BA@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142456e40
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BB@V?$SPtr@VInteractiveObject@fl_display@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457030
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BC@$$CBVValue@456@PEAVInteractiveObject@fl_display@3456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424570e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BD@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457120
// MS2-PIN: ?Func@?$ThunkFunc1@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BE@$$CBVValue@456@_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457180
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BF@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424571e0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BG@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457250
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BH@V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424572c0
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BI@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457370
// MS2-PIN: ?Func@?$ThunkFunc0@VMouseEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0BJ@$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457540
// MS2-PIN: ?Func@?$ThunkFunc0@VNetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@V?$SPtr@VObject@fl@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424576e0
// MS2-PIN: ?Func@?$ThunkFunc1@VNetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457790
// MS2-PIN: ?Func@?$ThunkFunc0@VNetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424578e0
// MS2-PIN: ?Func@?$ThunkFunc0@VNetStatusEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457c50
// MS2-PIN: ?Func@?$ThunkFunc0@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457f80
// MS2-PIN: ?Func@?$ThunkFunc1@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142457ff0
// MS2-PIN: ?Func@?$ThunkFunc0@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458080
// MS2-PIN: ?Func@?$ThunkFunc1@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424580f0
// MS2-PIN: ?Func@?$ThunkFunc0@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$03V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458180
// MS2-PIN: ?Func@?$ThunkFunc0@VProgressEvent@fl_events@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458230
// MS2-PIN: ?Func@?$ThunkFunc0@VTextEvent@fl_events@Instances@AS3@GFx@Scaleform@@$0A@VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458980
// MS2-PIN: ?Func@?$ThunkFunc1@VTextEvent@fl_events@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@AEBVASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424589f0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextEvent@fl_events@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VEvent@fl_events@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458af0
// MS2-PIN: ?Func@?$ThunkFunc0@VTextEvent@fl_events@Instances@AS3@GFx@Scaleform@@$02VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142458ba0
// MS2-PIN: ??_7EOFError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f138
// MS2-PIN: ??_7IOError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f0a8
// MS2-PIN: ??_7IllegalOperationError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314ef70
// MS2-PIN: ??_7InvalidSWFError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f010
// MS2-PIN: ??_7MemoryError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f1c8
// MS2-PIN: ??_7ScriptTimeoutError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f260
// MS2-PIN: ??_7StackOverflowError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@6B@ 0x14314f2f8
// MS2-PIN: ??_GEOFError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455a30
// MS2-PIN: ??_GIOError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455ac0
// MS2-PIN: ??_GIllegalOperationError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455b50
// MS2-PIN: ??_GInvalidSWFError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455be0
// MS2-PIN: ??_GMemoryError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455c70
// MS2-PIN: ??_GScriptTimeoutError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455d00
// MS2-PIN: ??_GStackOverflowError@fl_errors@ClassTraits@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x142455d90
// MS2-PIN: ??_7DIPixelProvider@Render@Scaleform@@6B@ 0x143149c28
// MS2-PIN: ??_7ByteArrayPixelProvider@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314a930
// MS2-PIN: ??_7VectorPixelProvider@fl_display@Instances@AS3@GFx@Scaleform@@6B@ 0x14314a950
