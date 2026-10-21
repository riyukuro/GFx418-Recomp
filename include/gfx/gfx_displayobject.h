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

namespace Scaleform {

// The render tree headers come from the other kernel tree; only names are needed here.
namespace Render {
class TreeNode;
class TreeContainer;
class FilterSet;
class DrawingContext;
namespace ContextImpl { class Context; }
}

namespace GFx {

class MovieImpl;
class MovieDefImpl;
class ASSupport;
class InteractiveObject;
class DisplayObject;
class EventId;
class FontManager;
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
};

}} // namespace Scaleform::GFx

#endif
