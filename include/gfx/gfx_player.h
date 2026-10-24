// Recovered Scaleform 4.1.18 GFx: the Movie interface (the player API a host drives a movie instance through) and
// the movie viewport. Movie is RefCountBase<Movie, StatMV_Other_Mem> + StateBag, 0x20 bytes; its vftable (exe
// 0x143183378, 65 slots, all pure) is what MovieImpl (gfx_movieimpl.h) overrides. Slot order from the exe's
// MovieImpl vftable 0x143183640: this build has no sound player slots and no SuspendGC / ScheduleGC.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder the virtuals.
//
// Units that define a local class Movie of their own (sfr_gfx_04, sfr_as3_20) must not include this header.
#ifndef MS2_SF_GFX_PLAYER_H
#define MS2_SF_GFX_PLAYER_H

#include "gfx_moviedef.h"
#include "../render/render_viewport.h"
#include "../render/render_constants.h"

namespace Scaleform {
class StatBag;
namespace Render {
template<class T> class Matrix2x4;
template<class T> class Matrix3x4;
template<class T> class Matrix4x4;
class Color;
class TreeRoot;
namespace ContextImpl { template<class C> class DisplayHandle; }
}
namespace GFx {

class ASMovieRootBase;
class Event;
class Value;
class FunctionHandler;

// (also in gfx_interactiveobject.h) whether a timeline plays.
#ifndef SF_GFX_PLAYSTATE
#define SF_GFX_PLAYSTATE
enum PlayState
{
    State_Playing,
    State_Stopped
};
#endif

// The movie's view: a Render::Viewport plus the pixel scale and aspect ratio (0x34 bytes).
class Viewport : public Render::Viewport
{
public:
    float Scale;          // +0x2c
    float AspectRatio;    // +0x30

    Viewport() { AspectRatio = 1.f; Scale = 1.f; }
    // (appended, sfr_gfx_01i) a view rectangle inside a buffer, no scissor (MovieImpl::SetLevelMovie)
    Viewport(int bufw, int bufh, int left, int top, int w, int h, unsigned flags = 0)
    {
        BufferWidth = bufw; BufferHeight = bufh;
        Left = left; Top = top; Width = w; Height = h;
        Flags = flags;
        ScissorLeft = ScissorTop = ScissorWidth = ScissorHeight = 0;
        AspectRatio = 1.f; Scale = 1.f;
    }
};

class Movie : public RefCountBase<Movie, 0x147>, public StateBag   // StatMV_Other_Mem
{
public:
    Ptr<ASMovieRootBase> pASMovieRoot;   // +0x18 the AVM specific root (AS2 or AS3)

    // The stage's view scale mode and alignment (Stage.scaleMode / Stage.align).
    enum ScaleModeType
    {
        SM_NoScale,
        SM_ShowAll,
        SM_ExactFit,
        SM_NoBorder
    };
    enum AlignType
    {
        Align_Center,
        Align_TopCenter,
        Align_BottomCenter,
        Align_CenterLeft,
        Align_CenterRight,
        Align_TopLeft,
        Align_TopRight,
        Align_BottomLeft,
        Align_BottomRight
    };
    // What HandleEvent reports.
    enum HE_ReturnValueType
    {
        HE_NotHandled           = 0,
        HE_Handled              = 1,
        HE_NoDefaultAction      = 2,
        HE_Completed            = (HE_Handled | HE_NoDefaultAction)
    };
    enum HitTestType
    {
        HitTest_Bounds            = 0,
        HitTest_Shapes            = 1,
        HitTest_ButtonEvents      = 2,
        HitTest_ShapesNoInvisible = 3
    };
    // MakeAreaVisible flags.
    enum
    {
        MAVF_DontScaleDown = 0x1,   // a box larger than the screen rect is not scaled down
        MAVF_ScaleUp50     = 0x2,   // a box under half the screen rect area is scaled up
        MAVF_LeftTopToZero = 0x4    // the box's top left goes to the screen rect's (0,0) instead of its center
    };

    Movie();            // inline in MovieImpl's ctor (define it inline where ASMovieRootBase is complete)
    ~Movie();           // exe 0x14256ac90

    virtual MovieDef*      GetMovieDef() const = 0;                                         // 1
    virtual unsigned       GetCurrentFrame() const = 0;                                     // 2
    virtual bool           HasLooped() const = 0;                                           // 3
    virtual void           GotoFrame(unsigned frameNumber) = 0;                             // 4
    virtual bool           GotoLabeledFrame(const char* plabel, int offset = 0) = 0;        // 5
    virtual void           SetPlayState(PlayState s) = 0;                                   // 6
    virtual PlayState      GetPlayState() const = 0;                                        // 7
    virtual void           SetVisible(bool visible) = 0;                                    // 8
    virtual bool           GetVisible() const = 0;                                          // 9
    virtual UInt64         GetASTimerMs() const = 0;                                        // 10
    virtual void           SetViewport(const Viewport& viewDesc) = 0;                       // 11
    virtual void           GetViewport(Viewport* pviewDesc) const = 0;                      // 12
    virtual void           SetViewScaleMode(ScaleModeType) = 0;                             // 13
    virtual ScaleModeType  GetViewScaleMode() const = 0;                                    // 14
    virtual void           SetViewAlignment(AlignType) = 0;                                 // 15
    virtual AlignType      GetViewAlignment() const = 0;                                    // 16
    virtual Render::RectF  GetVisibleFrameRect() const = 0;                                 // 17
    virtual Render::RectF  GetSafeRect() const = 0;                                         // 18
    virtual void           SetSafeRect(const Render::RectF& rect) = 0;                      // 19
    virtual void           SetEdgeAAMode(Render::EdgeAAMode edgeAA) = 0;                    // 20
    virtual Render::EdgeAAMode GetEdgeAAMode() const = 0;                                   // 21
    virtual void           Restart(bool advance0 = true) = 0;                               // 22
    virtual float          Advance(float deltaT, unsigned frameCatchUpCount = 2, bool capture = true) = 0; // 23
    virtual void           Capture(bool onChangeOnly = true) = 0;                           // 24
    virtual const Render::ContextImpl::DisplayHandle<Render::TreeRoot>& GetDisplayHandle() const = 0; // 25
    virtual void           SetCaptureThread(void* captureThreadId) = 0;                     // 26 (ThreadId)
    virtual void           ShutdownRendering(bool wait) = 0;                                // 27
    virtual bool           IsShutdownRenderingComplete() const = 0;                         // 28
    virtual void           SetPause(bool pause) = 0;                                        // 29
    virtual bool           IsPaused() const = 0;                                            // 30
    virtual void           SetBackgroundColor(const Render::Color bgColor) = 0;             // 31
    virtual void           SetBackgroundAlpha(float alpha) = 0;                             // 32
    virtual float          GetBackgroundAlpha() const = 0;                                  // 33
    virtual unsigned       HandleEvent(const Event& event) = 0;                             // 34 HE_ReturnValueType bits
    virtual void           GetMouseState(unsigned mouseIndex, float* x, float* y, unsigned* buttons) = 0; // 35
    virtual void           NotifyMouseState(float x, float y, unsigned buttons, unsigned mouseIndex = 0) = 0; // 36
    virtual bool           HitTest(float x, float y, HitTestType testCond = HitTest_Shapes,
                                   unsigned controllerIdx = 0) = 0;                         // 37
    virtual void*          GetUserData() const = 0;                                         // 38
    virtual void           SetUserData(void*) = 0;                                          // 39
    virtual bool           IsMovieFocused() const = 0;                                      // 40
    virtual bool           GetDirtyFlag(bool doReset = true) = 0;                           // 41
    virtual void           SetMouseCursorCount(unsigned n) = 0;                             // 42
    virtual unsigned       GetMouseCursorCount() const = 0;                                 // 43
    virtual void           SetControllerCount(unsigned n) = 0;                              // 44
    virtual unsigned       GetControllerCount() const = 0;                                  // 45
    virtual void           GetStats(::Scaleform::StatBag* pbag, bool reset = true) = 0;     // 46
    virtual MemoryHeap*    GetHeap() const = 0;                                             // 47
    virtual void           ForceCollectGarbage() = 0;                                       // 48
    virtual void           PrintObjectsReport(UInt32 flags = 0, Log* log = 0, const char* swfName = 0) = 0; // 49
    // MSVC lays overloaded virtuals out in reverse: the rect one is slot 50, the point one 51.
    virtual Render::PointF TranslateToScreen(const Render::PointF& p, Render::Matrix2x4<float>* puserMatrix = 0) = 0;
    virtual Render::RectF  TranslateToScreen(const Render::RectF& p, Render::Matrix2x4<float>* puserMatrix = 0) = 0;
    virtual bool           TranslateLocalToScreen(const char* pathToCharacter, const Render::PointF& pt,
                                                  Render::PointF* presPt,
                                                  Render::Matrix2x4<float>* userMatrix = 0) = 0; // 52
    virtual bool           SetControllerFocusGroup(unsigned controllerIdx, unsigned focusGroupIndex) = 0; // 53
    virtual unsigned       GetControllerFocusGroup(unsigned controllerIdx) const = 0;       // 54
    virtual void           ResetInputFocus(unsigned controllerIdx) = 0;                     // 55
    virtual bool           IsExitRequested() const = 0;                                     // 56
    virtual void           GetViewMatrix3D(Render::Matrix3x4<float>*) = 0;                  // 57
    virtual void           SetViewMatrix3D(const Render::Matrix3x4<float>& m) = 0;          // 58
    virtual void           GetProjectionMatrix3D(Render::Matrix4x4<float>*) = 0;            // 59
    virtual void           SetProjectionMatrix3D(const Render::Matrix4x4<float>& m) = 0;    // 60
    virtual void           SetStageAutoOrients(bool v = true) = 0;                          // 61
    virtual void           ForceUpdateImages() = 0;                                         // 62
    virtual void           MakeAreaVisible(const Render::RectF& screenRect, const Render::RectF& box,
                                           UInt32 flags = 0) = 0;                           // 63
    virtual void           RestoreViewport() = 0;                                           // 64

    // Releases the movie; the last reference also lets go of the AVM root (exe 0x142573e70).
    void     Release();
    int      GetAVMVersion() const;
    float    GetFrameRate() const;
    void     SetViewport(int bufw, int bufh, int left, int top, int w, int h, unsigned flags = 0);

    void     CreateString(Value* pvalue, const char* pstring);
    void     CreateStringW(Value* pvalue, const wchar_t* pstring);
    void     CreateObject(Value* pvalue, const char* className = 0, const Value* pargs = 0, unsigned nargs = 0);
    void     CreateArray(Value* pvalue);
    void     CreateFunction(Value* pvalue, FunctionHandler* pfc, void* puserData = 0);
    bool     GetVariable(Value* pval, const char* ppathToVar) const;
    bool     Invoke(const char* ppathToMethod, Value* presult, const Value* pargs, unsigned numArgs);

    // How SetVariable keeps a value whose target does not exist yet.
    enum SetVarType
    {
        SV_Normal,      // not kept
        SV_Sticky,      // kept until the target appears
        SV_Permanent    // kept, reapplied whenever the target is created again
    };
    // (appended, sfr24) The element type of SetVariableArray / GetVariableArray (0..5: the AS3 SetVariableArray
    // jump table).
    enum SetArrayType
    {
        SA_Int,
        SA_Double,
        SA_Float,
        SA_String,
        SA_StringW,
        SA_Value
    };
    bool     SetVariable(const char* ppathToVar, const Value& value, SetVarType setType = SV_Sticky);
    // The value an ExternalInterface.call made by the movie returns.
    void     SetExternalInterfaceRetVal(const Value& retVal);
    // pargFmt: one character per argument (%d %u %s %ls %f %hf %b %r ...).
    bool     Invoke(const char* ppathToMethod, Value* presult, const char* pargFmt, ...);
    bool     InvokeArgs(const char* ppathToMethod, Value* presult, const char* pargFmt, va_list args);
};

}} // namespace Scaleform::GFx

#endif
