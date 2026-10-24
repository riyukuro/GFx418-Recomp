// Recovered Scaleform 4.1.18 GFx: the movie root base and the display object base classes (DisplayObjectBase,
// DisplayObject). Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// Virtual order is the exe's (checked slot by slot against the Sprite vftable 0x14318be38, work/pub1/vtcmp.py):
// DisplayObjectBase owns slots 1..75 (4.1.18 has no IsVerboseActionErrors in the main vftable, only in LogBase),
// DisplayObject adds 76..78. Bodies stay in the exe (GFx_DisplayObject, 0x1425f07e0..) until that unit is recovered.
#ifndef MS2_SF_GFX_DISPLAYOBJECT_H
#define MS2_SF_GFX_DISPLAYOBJECT_H

#include "../kernel/sf_refcount.h"
#include "gfx_log.h"
#include "gfx_characterdef.h"
#include "gfx_asstring.h"
#include "gfx_eventid.h"
#include "../render/render_constants.h"
#include "../render/render_matrix2x4.h"
#include "../render/render_matrix4x4.h"
#include "../render/render_cxform.h"
#include <stdarg.h>

namespace Scaleform {

// The render tree headers come from the other kernel tree; only names are needed here.
namespace Render {
class TreeNode;
class TreeContainer;
class FilterSet;
class DrawingContext;
namespace ContextImpl { class Context; }
class Cxform;
namespace Text { class Allocator; }   // (appended, sfr24)
}

namespace GFx {

class MovieImpl;
class MovieDefImpl;
class ASSupport;
class InteractiveObject;
class DisplayObject;
class EventId;
class FontManager;
// (appended, sfr24) the movie root virtuals
class DisplayObjContainer;
class MovieDefRootNode;
class InputEventsQueueEntry;
class MouseState;
struct ProcessFocusKeyInfo;
class LoadQueueEntry;
class LoadStates;
class MemoryContext;
class FunctionHandler;
class OrientationEvent;
class AppLifecycleEvent;
class Value;
#ifndef SF_GFX_FOCUSMOVEDTYPE
#define SF_GFX_FOCUSMOVEDTYPE
// How the focus got moved.
enum FocusMovedType
{
    GFx_FocusMovedByMouse    = 1,
    GFx_FocusMovedByKeyboard = 2,
    GFx_FocusMovedByAS       = 3
};
#endif
class ASString;
class DrawingContext;

typedef double Double;
using Render::Matrix2F;
using Render::Matrix3F;
using Render::Matrix4F;

// AVM specific half of a movie (AS2::MovieRoot / AS3::MovieRoot). 0x28 bytes.
class ASMovieRootBase : public RefCountBase<ASMovieRootBase, 327>
{
public:
    MovieImpl*     pMovieImpl; // +0x10
    Ptr<ASSupport> pASSupport; // +0x18
    UByte          AVMVersion; // +0x20

    MovieImpl* GetMovieImpl() const { return pMovieImpl; }

    // (appended, sfr24) The 4.1.18 virtuals, slots 1..51, checked against the AS2 (0x1432177d8) and AS3 (0x14317d8d8)
    // MovieRoot vftables. This build has no SuspendGC / ScheduleGC and no NotifyGamePadAnalogEvent; the touch and
    // gesture slots (12, 13), the device events (23, 24) and ProcessLoadBinaryMT (28, AS2) are the empty defaults
    // both movie roots share. AS2 adds slot 52 (Invoke on an object), AS3 a slot of its own there.
    virtual void SetMovie(MovieImpl* pmovie) = 0;                                                      // 1
    virtual void AdvanceFrame(bool nextFrame) = 0;                                                     // 2
    virtual void ChangeMouseCursorType(unsigned mouseIdx, unsigned newCursorType) = 0;                 // 3
    virtual bool CheckAvm() = 0;                                                                       // 4
    virtual void ClearDisplayList() = 0;                                                               // 5
    virtual MovieDefRootNode* CreateMovieDefRootNode(MemoryHeap* pheap, MovieDefImpl* pdefImpl,
                                                     bool importFlag = false) = 0;                     // 6
    virtual void DoActions() = 0;                                                                      // 7
    virtual InteractiveObject* FindTarget(const ASString& path) const = 0;                             // 8
    // gcFlags is not read by either movie root.
    virtual void ForceCollect(unsigned gcFlags) = 0;                                                   // 9
    virtual void ForceEmergencyCollect() = 0;                                                          // 10
    virtual void GenerateMouseEvents(unsigned mouseIndex) = 0;                                         // 11
    virtual void GenerateTouchEvents(unsigned mouseStateIndex) {}                                      // 12
    virtual void GenerateGestureEvents(InteractiveObject* topmost, unsigned phase, const PointF& pos,
                                       const PointF& offset, const PointF& scale, float rotation,
                                       unsigned gestureMask) {}                                        // 13
    virtual DisplayObjContainer* GetRootMovie(DisplayObject* dobj = NULL) const = 0;                   // 14
    virtual bool Init(MovieDefImpl* pmovieDef) = 0;                                                    // 15
    virtual void NotifyMouseEvent(const InputEventsQueueEntry* qe, const MouseState& ms, int mi) = 0;  // 16
    virtual void NotifyOnResize() = 0;                                                                 // 17
    virtual void NotifyQueueSetFocus(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt) = 0; // 18
    virtual void NotifyTransferFocus(InteractiveObject* curFocused, InteractiveObject* pnewFocus,
                                     unsigned controllerIdx) = 0;                                      // 19
    virtual bool NotifyOnFocusChange(InteractiveObject* curFocused, InteractiveObject* toBeFocused,
                                     unsigned controllerIdx, FocusMovedType fmt,
                                     ProcessFocusKeyInfo* pfocusKeyInfo = NULL) = 0;                   // 20
    virtual void OnMovieFocus(bool set) = 0;                                                           // 21
    virtual void OnNextFrame() = 0;                                                                    // 22
    virtual void OnDeviceOrientationChanged(const OrientationEvent&) {}                                // 23
    virtual void OnAppLifecycleEvent(const AppLifecycleEvent&) {}                                      // 24
    virtual void PrintObjectsReport(UInt32 flags = 0, Log* log = NULL, const char* swfName = NULL) {}  // 25
    virtual void ProcessLoadQueueEntry(LoadQueueEntry* pentry, LoadStates* pls) = 0;                   // 26
    virtual void ProcessLoadVarsMT(LoadQueueEntry* pentry, LoadStates* pls, const String& data, UPInt fileLen,
                                   bool succeeded) = 0;                                                // 27
    virtual void ProcessLoadBinaryMT(LoadQueueEntry* pentry, LoadStates* pls, const ArrayPOD<UByte>& data,
                                     UPInt fileLen, bool succeeded) {}                                 // 28
    virtual void RegisterAuxASClasses() = 0;                                                           // 29
    virtual void ResolveStickyVariables(InteractiveObject* pcharacter) = 0;                            // 30
    virtual void SetExternalInterfaceRetVal(const GFx::Value& retVal) = 0;                             // 31
    virtual void SetMemoryParams(unsigned frameBetweenCollections, unsigned maxRootCount) = 0;         // 32
    virtual void Shutdown() = 0;                                                                       // 33
    virtual void CreateString(GFx::Value* pvalue, const char* pstring) = 0;                            // 34
    virtual void CreateStringW(GFx::Value* pvalue, const wchar_t* pstring) = 0;                        // 35
    virtual void CreateObject(GFx::Value* pvalue, const char* className = NULL, const GFx::Value* pargs = NULL,
                              unsigned nargs = 0) = 0;                                                 // 36
    virtual void CreateArray(GFx::Value* pvalue) = 0;                                                  // 37
    virtual void CreateFunction(GFx::Value* pvalue, FunctionHandler* pfc, void* puserData = NULL) = 0; // 38
    // Slots 39, 41, 42 and 44 take the Movie enums. gfx_player.h is not included here: units that define a local
    // Movie of their own cannot have it. Without it the same slots take a plain int.
#ifdef MS2_SF_GFX_PLAYER_H
    virtual bool SetVariable(const char* ppathToVar, const GFx::Value& value,
                             Movie::SetVarType setType = Movie::SV_Sticky) = 0;                        // 39
#else
    virtual bool SetVariable(const char* ppathToVar, const GFx::Value& value, int setType = 1) = 0;    // 39
#endif
    virtual bool GetVariable(GFx::Value* pval, const char* ppathToVar) const = 0;                      // 40
#ifdef MS2_SF_GFX_PLAYER_H
    virtual bool SetVariableArray(Movie::SetArrayType type, const char* ppathToVar, unsigned index,
                                  const void* pdata, unsigned count,
                                  Movie::SetVarType setType = Movie::SV_Sticky) = 0;                   // 41
    virtual bool SetVariableArraySize(const char* ppathToVar, unsigned count,
                                      Movie::SetVarType setType = Movie::SV_Sticky) = 0;               // 42
#else
    virtual bool SetVariableArray(int type, const char* ppathToVar, unsigned index, const void* pdata,
                                  unsigned count, int setType = 1) = 0;                                // 41
    virtual bool SetVariableArraySize(const char* ppathToVar, unsigned count, int setType = 1) = 0;   // 42
#endif
    virtual unsigned GetVariableArraySize(const char* ppathToVar) = 0;                                 // 43
#ifdef MS2_SF_GFX_PLAYER_H
    virtual bool GetVariableArray(Movie::SetArrayType type, const char* ppathToVar, unsigned index, void* pdata,
                                  unsigned count) = 0;                                                 // 44
#else
    virtual bool GetVariableArray(int type, const char* ppathToVar, unsigned index, void* pdata,
                                  unsigned count) = 0;                                                 // 44
#endif
    // MSVC puts overloads in reverse order: the format overload is slot 46, the array one 47.
    virtual bool IsAvailable(const char* ppathToVar) const = 0;                                        // 45
    virtual bool Invoke(const char* ppathToMethod, GFx::Value* presult, const GFx::Value* pargs,
                        unsigned numArgs) = 0;                                                         // 47
    virtual bool Invoke(const char* ppathToMethod, GFx::Value* presult, const char* pargFmt, ...) = 0; // 46
    virtual bool InvokeArgs(const char* ppathToMethod, GFx::Value* presult, const char* pargFmt,
                            va_list args) = 0;                                                         // 48
    virtual MemoryContext* GetMemoryContext() const = 0;                                               // 49
    virtual ASStringManager* GetStringManager() const = 0;                                             // 50
    virtual Render::Text::Allocator* GetTextAllocator() = 0;                                           // 51
};

class AvmInteractiveObjBase;
class AvmSpriteBase;
class AvmButtonBase;
class AvmTextFieldBase;
class AvmDisplayObjContainerBase;
class AvmVideoCharacterBase;

// The AVM (AS2 or AS3) half of a display object, an interface embedded in the AVM-specific subclass
// (AS2::AvmSprite, AS3::AvmSprite, ...). DisplayObjectBase finds it AvmObjOffset * 4 bytes after its own start.
// Slot order is the exe's: the To* casts (1..5), the event entry points (6..11), the video cast (12).
class AvmDisplayObjBase
{
public:
    virtual ~AvmDisplayObjBase() {}

    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase() = 0;
    virtual AvmSpriteBase*              ToAvmSpriteBase()         = 0;
    virtual AvmButtonBase*              ToAvmButttonBase()        = 0;
    virtual AvmTextFieldBase*           ToAvmTextFieldBase()      = 0;
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase()  = 0;

    virtual const char* GetAbsolutePath(String* ppath) const = 0;
    virtual bool        HasEventHandler(const EventId& id) const = 0;
    virtual bool        OnEvent(const EventId& id) = 0;
    virtual void        OnEventLoad() = 0;
    // The object left the display list after its load event ran.
    virtual void        OnEventUnload() = 0;
    virtual bool        OnUnloading(bool mayRemove) = 0;

    virtual AvmVideoCharacterBase* ToAvmVideoCharacterBase() { return 0; }
};

// Base of every character on the display list. 0x70 bytes.
class DisplayObjectBase : public RefCountBaseWeakSupport<DisplayObjectBase, 322>,
                          public LogBase<DisplayObjectBase>
{
public:
    struct GeomDataType;
    struct PerspectiveDataType;
    struct IndirectTransformDataType;
    struct TopMostDescr;

    typedef Matrix2F Matrix;

    // Result of the topmost-entity search under the mouse.
    enum TopMostResult
    {
        TopMost_Found       = 1, // the descriptor holds the hit
        TopMost_FoundNothing = 2, // nothing here and the search stops
        TopMost_Continue    = 3  // nothing here yet, keep searching
    };
    // (sfr24) PointTestLocal's hitTestMask bits: 0 tests the bounds only.
    enum HitTestMask
    {
        HitTest_TestShape       = 1, // the shapes, not just their bounds
        HitTest_IgnoreInvisible = 2  // invisible objects are not hit
    };

    virtual Ptr<Render::TreeNode> CreateRenderNode(Render::ContextImpl::Context& context) const = 0;

    virtual const Matrix&   GetMatrix() const;
    virtual void            SetMatrix(const Matrix& m);
    virtual const Matrix3F& GetMatrix3D() const;
    virtual void            SetMatrix3D(const Matrix3F& m);
    virtual bool            GetProjectionMatrix3D(Matrix4F* m, bool inherit = false) const;
    virtual void            SetProjectionMatrix3D(const Matrix4F& m);
    virtual bool            GetViewMatrix3D(Matrix3F* m, bool inherit = false) const;
    virtual void            SetViewMatrix3D(const Matrix3F& m);
    virtual void            UpdateViewAndPerspective();
    virtual void            UpdateTransform3D();
    virtual bool            Has3D();
    virtual Render::BlendMode GetBlendMode() const;
    virtual void            SetBlendMode(Render::BlendMode mode);
    virtual float           GetRatio() const;
    virtual void            SetRatio(float ratio);

    // ActionScript properties (x/y/z in pixels, scales in percent, angles in degrees).
    virtual void            SetX(Double v);
    virtual Double          GetX() const;
    virtual void            SetY(Double v);
    virtual Double          GetY() const;
    virtual void            SetZ(Double v);
    virtual Double          GetZ() const;
    virtual void            SetXScale(Double v);
    virtual Double          GetXScale() const;
    virtual void            SetYScale(Double v);
    virtual Double          GetYScale() const;
    virtual void            SetZScale(Double v);
    virtual Double          GetZScale() const;
    virtual void            SetRotation(Double v);
    virtual Double          GetRotation() const;
    virtual void            SetXRotation(Double v);
    virtual Double          GetXRotation() const;
    virtual void            SetYRotation(Double v);
    virtual Double          GetYRotation() const;
    virtual void            SetFOV(Double v);
    virtual Double          GetFOV() const;
    virtual void            SetFocalLength(Double v);
    virtual Double          GetFocalLength() const;
    virtual void            SetProjectionCenter(PointF center);
    virtual PointF          GetProjectionCenter() const;
    virtual void            SetWidth(Double v);
    virtual Double          GetWidth() const;
    virtual void            SetHeight(Double v);
    virtual Double          GetHeight() const;
    virtual Double          GetMouseX() const;
    virtual Double          GetMouseY() const;
    virtual bool            GetAcceptAnimMoves() const;
    virtual bool            GetContinueAnimationFlag() const;
    virtual void            SetAcceptAnimMoves(bool accept);
    virtual void            SetFilters(const Render::FilterSet* filters);
    virtual const Render::FilterSet* GetFilters() const;
    virtual void            SetVisible(bool visible);
    virtual bool            GetVisible() const;
    virtual void            ForceShutdown();

    // Bounds in the space given by t; the rect variant ignores strokes.
    virtual RectF           GetBounds(const Matrix& t) const;
    virtual RectF           GetRectBounds(const Matrix& t) const;
    virtual bool            PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;
    virtual TopMostResult   GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);
    virtual CharacterDef*   GetCharacterDef() const = 0;
    virtual MovieDefImpl*   GetResourceMovieDef() const;
    virtual FontManager*    GetFontManager() const;
    virtual InteractiveObject* GetTopParent(bool ignoreLockRoot = false) const;
    virtual Render::TreeContainer* GetRenderContainer();
    virtual void            Restart();
    virtual void            AdvanceFrame(bool nextFrame, float framePos = 0.0f);
    virtual bool            OnEvent(const EventId& id);
    virtual void            OnEventLoad();
    virtual bool            OnUnloading();
    virtual void            OnEventUnload();
    virtual Log*            GetLog() const;
    virtual bool            IsVerboseAction() const;
    virtual bool            IsUsedAsMask() const;
    virtual void            SetStateChangeFlags(UByte flags);
    virtual UByte           GetStateChangeFlags() const;
    virtual CharacterDef::CharacterDefType GetType() const;

    // Flags (+0x6a).
    enum FlagMasks
    {
        Mask_Scale9GridExists    = 0x0001,
        Mask_TopmostLevel        = 0x0002,
        Mask_HitTestNegative     = 0x0004,
        Mask_HitTestPositive     = 0x0008,
        Mask_Unloaded            = 0x0010,
        Mask_JustLoaded          = 0x0020,
        Mask_MarkedForRemove     = 0x0040,
        Mask_InteractiveObject   = 0x0080,
        Mask_ScriptableObject    = 0x0100,
        Mask_DisplayObjContainer = 0x0200,
        Mask_Sprite              = 0x0400,
        Mask_MovieClip           = 0x0800,
        Mask_Unloading           = 0x1000,
        Mask_Loaded              = 0x2000,
        Mask_Visible             = 0x4000,
        Mask_IndirectTransform   = 0x8000
    };

    ASMovieRootBase* pASRoot;     // +0x20
    UInt32           Id;          // +0x28 ResourceId
    int              Depth;       // +0x2c
    unsigned         CreateFrame; // +0x30
    union
    {
        InteractiveObject* pParent;     // +0x38
        DisplayObjectBase* pParentChar;
    };
    float                      LastHitTestX;     // +0x40
    float                      LastHitTestY;     // +0x44
    Ptr<Render::TreeNode>      pRenNode;         // +0x48
    GeomDataType*              pGeomData;        // +0x50
    PerspectiveDataType*       pPerspectiveData; // +0x58
    IndirectTransformDataType* pIndXFormData;    // +0x60
    UInt16                     ClipDepth;        // +0x68
    UInt16                     Flags;            // +0x6a
    UByte                      BlendMode;        // +0x6c
    UByte                      AvmObjOffset;     // +0x6d

    ASMovieRootBase* GetASMovieRoot() const { return pASRoot; }
    MovieImpl*       GetMovieImpl() const   { return pASRoot->GetMovieImpl(); }

    bool IsInteractiveObject() const   { return (Flags & Mask_InteractiveObject) != 0; }
    bool IsDisplayObjContainer() const { return (Flags & Mask_DisplayObjContainer) != 0; }
    bool IsSprite() const              { return (Flags & Mask_Sprite) != 0; }
    bool IsUnloaded() const            { return (Flags & Mask_Unloaded) != 0; }
    bool IsVisibleFlagSet() const      { return (Flags & Mask_Visible) != 0; }
    bool IsUnloading() const           { return (Flags & Mask_Unloading) != 0 || Depth < -1; }

    bool               HasAvmObject() const  { return AvmObjOffset != 0; }
    AvmDisplayObjBase* GetAvmObjImpl() const
    {
        return reinterpret_cast<AvmDisplayObjBase*>(reinterpret_cast<UPInt>(this) + AvmObjOffset * 4);
    }

    // Non-virtual members called from the recovered units (bodies in the exe).
    void SetScale9Grid(const RectF& grid);   // 0x1425f5a50
    void SetDirtyFlag();                     // 0x1425f4090, empty in this build (folded with other empty bodies)

protected:
    // Sets Mask_Visible and updates the render node (0x1425f60e0).
    void SetVisibleFlag(bool v = true);

    // (appended for the GFx_DisplayObject unit, sfr_gfx_06)
public:
    typedef Render::Cxform Cxform;

    DisplayObjectBase(ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id);
    virtual ~DisplayObjectBase();

    // LogBase: overridden in the LogBase part of the vftable only.
    virtual bool IsVerboseActionErrors() const;

    void BindAvmObj(AvmDisplayObjBase* p);

    Render::ContextImpl::Context& GetRenderContext() const;
    Render::TreeNode*             GetRenderNode() const;

    const Cxform& GetCxform() const;
    void          SetCxform(const Cxform& cx);
    void          ConcatenateCxform(const Cxform& cx);
    void          ConcatenateMatrix(const Matrix& m);

    void GetWorldMatrix(Matrix* pmat) const;
    void GetWorldMatrix3D(Matrix3F* pmat) const;
    void GetLevelMatrix(Matrix* pmat) const;
    void GetWorldCxform(Cxform* pcxform) const;

    void Clear3D(bool inherit = false);
    bool Is3D(bool inherit) const;
    bool Is3D() const;

    PointF  Local3DToGlobal(const Render::Point3F& pt) const;
    PointF  GlobalToLocal(const PointF& pt) const;
    Render::Point3F GlobalToLocal3D(const PointF& pt) const;
    void    TransformPointToLocal(PointF* p, const PointF& pt, bool ptInParentSpace = true,
                                  const Matrix2F* mat = 0) const;

    Render::BlendMode GetActiveBlendMode() const;
    unsigned          GetVersion() const;

    bool CheckLastHitResult(float x, float y) const;
    void SetLastHitResult(float x, float y, bool result) const;
    void InvalidateHitResult() const;

    GeomDataType& GetGeomData(GeomDataType& geomData) const;
    void          SetGeomData(const GeomDataType& gd);

    void   SetAlpha(Double alpha);
    Double GetAlpha() const;

    MovieImpl* FindMovieImpl() const;
    bool       IsAncestor(DisplayObjectBase* ch) const;
    RectF      GetScale9Grid() const;
    bool       HasScale9Grid() const; // (appended for sfr_as2_06) exe 0x14295db50

    InteractiveObject* GetTopMostMouseEntityDef(CharacterDef* pdef, const PointF& pt, bool testAll = false,
                                                const InteractiveObject* ignoreMC = 0);

    Ptr<Render::TreeNode> SetIndirectTransform(Render::TreeNode* newParent);   // 0x1425f4800
    void                  RemoveIndirectTransform();                           // 0x1425f3b80

    bool IsTopmostLevelFlagSet() const    { return (Flags & Mask_TopmostLevel) != 0; }
    bool HasIndirectTransform() const     { return (Flags & Mask_IndirectTransform) != 0; }
    bool IsScriptableObject() const       { return (Flags & Mask_ScriptableObject) != 0; }
    void SetUnloaded(bool v = true)       { v ? Flags |= Mask_Unloaded : Flags &= ~Mask_Unloaded; }
    void SetUnloading(bool v = true)      { v ? Flags |= Mask_Unloading : Flags &= ~Mask_Unloading; }
    void SetLoaded(bool v = true)         { v ? Flags |= Mask_Loaded : Flags &= ~Mask_Loaded; }
    int  GetAVMVersion() const            { return pASRoot->AVMVersion; }

    // (appended for flash.geom, sfr_as3_11)
    InteractiveObject*         GetParent() const             { return pParent; }
    const PerspectiveDataType* GetPerspectiveDataPtr() const { return pPerspectiveData; }
    PointF LocalToGlobal(const PointF& pt) const { return Local3DToGlobal(Render::Point3F(pt.x, pt.y, 0)); }

    // (appended for the AS3 character factory, sfr12) built in place in memory shared with the AVM part; the class
    // operator new set is redeclared next to the placement one, which would hide it otherwise.
    SF_MEMORY_DEFINE_PLACEMENT_NEW
    SF_MEMORY_REDEFINE_NEW(DisplayObjectBase, 322)

protected:
    Render::TreeContainer* ConvertToTreeContainer();
    void                   EnsureGeomDataCreated();
};

// Named reference to a display object that survives the object (it is resolved again by path when the object
// was recreated). Own non-atomic count; 0x28 bytes, freed to the global heap.
class CharacterHandle : public NewOverrideBase<322>
{
public:
    int            RefCount;     // +0x00
    DisplayObject* pCharacter;   // +0x08 null once the object is gone
    ASString       Name;         // +0x10
    ASString       NamePath;     // +0x18
    ASString       OriginalName; // +0x20

    ~CharacterHandle();   // 0x1425f0900

    void AddRef() { ++RefCount; }
    void Release()
    {
        if (--RefCount <= 0)
            delete this;
    }

    DisplayObject* ResolveCharacter(MovieImpl* proot) const;   // 0x1425f3dc0

    // (appended for the GFx_DisplayObject unit, sfr_gfx_06)
    CharacterHandle(const ASString& name, DisplayObject* pparent, DisplayObject* pcharacter = 0);

    DisplayObject* ForceResolveCharacter(MovieImpl* proot) const;
    void           ReleaseCharacter() { pCharacter = 0; }
    void           ChangeName(const ASString& name, DisplayObject* pparent);
    void           ResetName(ASStringManager* psm);
};

// A display object placed on a timeline. 0x88 bytes.
class DisplayObject : public DisplayObjectBase
{
public:
    struct ScrollRectInfo;

    virtual ~DisplayObject();

protected:
    virtual ASString        CreateNewInstanceName() const;
public:
    virtual DrawingContext* GetDrawingContext();
    virtual void            DoDisplayCallback();

    virtual const Matrix&   GetMatrix() const;
    virtual void            SetMatrix(const Matrix& m);
    virtual const Matrix3F& GetMatrix3D() const;
    virtual void            SetMatrix3D(const Matrix3F& m);
    virtual bool            GetContinueAnimationFlag() const;
    virtual void            OnEventLoad();
    virtual void            OnEventUnload();
    virtual bool            OnEvent(const EventId& id);
    virtual Double          GetMouseX() const;
    virtual Double          GetMouseY() const;
    virtual bool            GetAcceptAnimMoves() const;
    virtual void            SetAcceptAnimMoves(bool accept);
    virtual bool            IsUsedAsMask() const;

    // Flags (+0x88).
    enum FlagMasks
    {
        Mask_TimelineObject    = 0x01,
        Mask_InstanceBasedName = 0x02,
        Mask_UsedAsMask        = 0x04,
        Mask_AcceptAnimMoves   = 0x08,
        Mask_ContinueAnimation = 0x10,
        Mask_ExecutionAborted  = 0x20
    };

    void SetName(const ASString& name);   // 0x1425f52f0

    // The handle naming this object, created on first use.
    CharacterHandle* GetCharacterHandle() const { return pNameHandle ? pNameHandle.GetPtr() : CreateCharacterHandle(); }

protected:
    CharacterHandle* CreateCharacterHandle() const;   // 0x1425f1910

public:
    mutable Ptr<CharacterHandle> pNameHandle;    // +0x70
    DisplayObject*               pMaskCharacter; // +0x78 the mask, or the masked object when IsUsedAsMask
    ScrollRectInfo*              pScrollRect;    // +0x80
    UInt16                       Flags;          // +0x88

    // (appended for the GFx_DisplayObject unit, sfr_gfx_06)
    DisplayObject(ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id);

    const char* GetAbsolutePath(String* ppath) const;
    bool        HasEventHandler(const EventId& id) const;

    ASString GetName() const;
    ASString GetOriginalName() const;
    void     SetOriginalName(const ASString& name);

    void           SetMask(DisplayObject* pmaskSprite);
    DisplayObject* GetMask() const;
    void           SetMaskOwner(DisplayObject* pmaskOwner);
    DisplayObject* GetMaskOwner() const;

    void SetScrollRect(const Render::RectD* r);

    bool TransformPointToLocalAndCheckBounds(PointF* p, const PointF& pt, bool ptInParentSpace = true,
                                             const Matrix2F* mat = 0) const;

    bool IsUsedAsMaskFlagSet() const        { return (Flags & Mask_UsedAsMask) != 0; }
    bool IsInstanceBasedNameFlagSet() const { return (Flags & Mask_InstanceBasedName) != 0; }
    bool IsAcceptAnimMovesFlagSet() const   { return (Flags & Mask_AcceptAnimMoves) != 0; }

protected:
    void ResetClipDepth();
};

// (appended for Sprite::GetTopMostMouseEntity, sfr_gfx_05b) the mouse hit search state.
struct DisplayObjectBase::TopMostDescr
{
    InteractiveObject*       pResult;       // +0x00 out: the hit
    PointF                   LocalPt;       // +0x08 out: the point in the tested object's space (TopMost_Continue)
    const InteractiveObject* pIgnoreMC;     // +0x10 in: skipped (the clip being dragged)
    bool                     TestAll;       // +0x18 in: also hit objects without button handlers
    unsigned                 ControllerIdx; // +0x1c in

    // LocalPt is left unset (the exe stores nothing there)
    TopMostDescr() : LocalPt(PointF::NoInit), pIgnoreMC(0), TestAll(false), ControllerIdx(0) {}
};

// (appended for the GFx_DisplayObject unit, sfr_gfx_06) the lazily allocated transform state of a display object.
// The 3D matrices are 16-aligned in these structs.

// Position, scale and rotation as the AS properties hold them (twips, percent, degrees). 0x60 bytes.
struct DisplayObjectBase::GeomDataType : public NewOverrideBase<322>
{
    int      X, Y;               // +0x00
    Double   XScale, YScale;     // +0x08
    Double   Rotation;           // +0x18
    Matrix   OrigMatrix;         // +0x20
    Double   Z;                  // +0x40
    Double   ZScale;             // +0x48
    Double   XRotation;          // +0x50
    Double   YRotation;          // +0x58

    GeomDataType()
    {
        X = Y = 0;
        Rotation = 0;
        XScale = YScale = 100;
        Z = XRotation = YRotation = 0;
        ZScale = 100;
    }
};

// The perspective of a 3D object that does not inherit its parent's. 0x50 bytes.
struct DisplayObjectBase::PerspectiveDataType : public NewOverrideBase<322>
{
    Double   FieldOfView;                            // +0x00 degrees
    Double   FocalLength;                            // +0x08 twips
    PointF   ProjectionCenter;                       // +0x10 stage twips
    __declspec(align(16)) Matrix3F ViewMatrix3D;     // +0x20 without the viewport adjustment

    PerspectiveDataType() : FieldOfView(0), FocalLength(0), ProjectionCenter(0, 0) {}
};

// The transform the tree node would have without the indirect transform. 0x40 bytes.
struct DisplayObjectBase::IndirectTransformDataType : public NewOverrideBase<322>
{
    __declspec(align(16)) Matrix3F OrigTransformMatrix;  // +0x00
    bool     IsOrig3D;                                   // +0x30
};

// scrollRect: the clip rectangle, its mask shape and the transform without the scroll. 0x70 bytes.
struct DisplayObject::ScrollRectInfo : public NewOverrideBase<322>
{
    Render::RectD        Rectangle;                         // +0x00
    Ptr<DrawingContext>  Mask;                              // +0x20
    __declspec(align(16)) Matrix3F OrigTransformMatrix;     // +0x30
    bool                 IsOrig3D;                          // +0x60
};

// The AS3 display objects construct their AvmDisplayObj right after the DisplayObject part, at +0x90.
static_assert(sizeof(DisplayObject) == 0x90, "DisplayObject size");

}} // namespace Scaleform::GFx

// (appended, sfr12) DisplayObjectBase::Is3D() is inline over the render node's flags; it needs both gfx_displayobject.h
// and gfx_rendertree.h, so whichever of the two comes second defines it.
#if defined(MS2_SF_GFX_DISPLAYOBJECT_H) && defined(MS2_SF_GFX_RENDERTREE_H) && !defined(MS2_SF_GFX_DISPLAYOBJECT_IS3D)
#define MS2_SF_GFX_DISPLAYOBJECT_IS3D
namespace Scaleform { namespace GFx {
inline bool DisplayObjectBase::Is3D() const
{
    return pRenNode && pRenNode->Is3D();
}
}} // namespace Scaleform::GFx
#endif

#endif
