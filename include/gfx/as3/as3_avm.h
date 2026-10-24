// Recovered Scaleform GFx 4.1.18 AS3: the AS3 halves of display objects (Avm* classes) as the loader side sees them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// AvmDisplayObj, AvmInteractiveObj, AvmDisplayObjContainer and AvmSprite are spelled out with their vftables in the
// exe's slot order. The other Avm classes are declared OPAQUE for now (size and constructor only).
#ifndef MS2_SF_GFX_AS3_AVM_H
#define MS2_SF_GFX_AS3_AVM_H

#include "ms2/scaleform/include/gfx/gfx_displayobject.h"
#include "ms2/scaleform/include/gfx/gfx_interactiveobject.h"
#include "ms2/scaleform/include/gfx/gfx_displayobjcontainer.h"
#include "ms2/scaleform/include/gfx/gfx_sprite.h"
#include "ms2/scaleform/include/gfx/gfx_eventid.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimplstates.h"
#include "ms2/scaleform/include/gfx/as3/as3_support.h"

namespace Scaleform { namespace GFx {

class Sprite;
class TextField;
class Button;
class StaticTextCharacter;
class CharacterDef;
struct CharacterCreateInfo;

namespace AS3 {

class VMAppDomain;
class ASVM;             // (appended, sfr19)
namespace Instances { namespace fl_display { class DisplayObject; } }

class AvmInteractiveObj;    // (appended, sfr19)
namespace Instances { namespace fl_events { class Event; } }

// AS3 part of every display object. 0x30 bytes; vftable 0x14317c160 (22 slots), ctor inlined into its subclasses'.
class AvmDisplayObj : public AvmDisplayObjBase
{
public:
    enum
    {
        Flag_Unloaded   = 0x01,   // OnUnloading saw the object stage-accessible
        Flag_Loaded     = 0x02    // the load event ran once
    };

    AvmDisplayObj(DisplayObject* pdispObj)
        : pAS3CollectiblePtr(NULL), pDispObj(pdispObj), pClassName(NULL), Flags(0)
    {
        pdispObj->BindAvmObj(this);
        pAS3RawPtr = NULL;
    }
    virtual ~AvmDisplayObj();                                           // 0x1424ddb80, ??_G 0x1424e2760
#ifdef SF_AS3_AVM_INPLACE_DELETE
    // (appended, sfr24) a no-op class delete: the AS3 part lives inside its display object's allocation, so the
    // deleting destructors (0x1424e2760, 0x1424e2a70, 0x1424e26d0, ...) free only for a global delete
    // ((flags & 5) == 5). Opt-in: a class that also derives from a DisplayObject (AvmLoader, ShapeObject,
    // AvmBitmap) then needs a using-declaration of the display object's operator delete.
    void operator delete(void*) {}
#endif

    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase()   { return NULL; }
    virtual AvmSpriteBase*              ToAvmSpriteBase()           { return NULL; }
    virtual AvmButtonBase*              ToAvmButttonBase()          { return NULL; }
    virtual AvmTextFieldBase*           ToAvmTextFieldBase()        { return NULL; }
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase()    { return NULL; }

    virtual const char* GetAbsolutePath(String* ppath) const;           // 0x142506e10
    virtual bool        HasEventHandler(const EventId& id) const;       // 0x142510dc0
    virtual bool        OnEvent(const EventId& id);                     // 0x142518a30
    virtual void        OnEventLoad();                                  // 0x142519020
    virtual void        OnEventUnload();                                // 0x142519200
    virtual bool        OnUnloading(bool mayRemove);                    // 0x14251af40

    virtual void        Bind(DisplayObject* po) { pDispObj = po; }      // 0x1423dc0b0
    virtual void        OnRemoved(bool byTimeline);                     // 0x14251ace0
    // Instantiates the AS3 object unless there is one; returns what the ctor call returned.  0x1424f2400
    virtual unsigned    CreateASInstance(bool execute);
    virtual const char* GetDefaultASClassName() const;                  // "flash.display.DisplayObject" 0x142508910
    // pClassName, or the export name of the character, or the default class name.  0x142505f20
    virtual String&     GetASClassName(String* className) const;
    virtual void        PropagateEvent(const Instances::fl_events::Event& evt, bool inclChildren = true); // 0x14251f3a0
    virtual void        OnAdded(bool byTimeline);                       // 0x1425185d0
    // Appends the display object when pt hits it.  0x14250c2e0
    virtual bool        GetObjectsUnderPoint(ArrayDH<Ptr<DisplayObjectBase> >* destArray, const Render::PointF& pt) const;
    virtual bool        DetachChild(DisplayObjectBase*);                // false 0x1424f7180

    Instances::fl_display::DisplayObject*   pAS3CollectiblePtr; // +0x08 SPtr<>; bit 0 set while the GC tears it down
    Instances::fl_display::DisplayObject*   pAS3RawPtr;         // +0x10
    DisplayObject*                          pDispObj;           // +0x18
    const char*                             pClassName;         // +0x20 copy owned by the global heap
    UByte                                   Flags;              // +0x28

    MovieRoot*  GetAS3Root() const;
    MovieImpl*  GetMovieImpl() const    { return pDispObj->GetMovieImpl(); }
    // Drops the AS3 object (0x142521eb0).
    void        ReleaseAS3Obj();
    Ptr<Log>    GetLog() const          { return GetMovieImpl()->GetLog(); }
    // (appended, sfr19) the VM of the movie (0x142506d30)
    ASVM*       GetAVM();
    // (appended, sfr19) the AS3 object, kept raw or as a tagged collectible pointer
    Instances::fl_display::DisplayObject* GetAS3Obj() const
    {
        Instances::fl_display::DisplayObject* p = pAS3RawPtr;
        if (!p)
            p = pAS3CollectiblePtr;
        if (reinterpret_cast<UPInt>(p) & 1)
            p = reinterpret_cast<Instances::fl_display::DisplayObject*>(reinterpret_cast<UByte*>(p) - 1);
        return p;
    }
    // (appended, sfr19)
    AvmInteractiveObj*                      GetAvmParent() const;   // 0x142507550
    Instances::fl_display::DisplayObject*   GetAS3Parent() const;   // 0x142505e50
    void        InitClassName(const char* name);                    // 0x142511760
    bool        IsStageAccessible() const;                          // 0x142514d20
    // The object now lives on the timeline: the AS3 object is kept raw, the counted reference dropped. 0x1425189a0
    void        OnDetachFromTimeline();
    // (appended, sfr19) the AS3 object of the class GetASClassName names, made without running its constructor;
    // false when there is no such class. 0x1424f2450
    bool        CreateASInstanceNoCtor(bool execute);
    // (appended, sfr19) runs the constructor of the object CreateASInstanceNoCtor made (now when execute, else
    // queued). 0x1424ee800
    unsigned    CallCtor(bool execute);
};

// AS3 part of an interactive object, with its AvmInteractiveObjBase part at +0x30. 0x40 bytes;
// vftables 0x14317ca60 (26 slots) and 0x14317cb30. Ctor 0x1424d6480.
class AvmInteractiveObj : public AvmDisplayObj, public AvmInteractiveObjBase
{
public:
    AvmInteractiveObj(InteractiveObject* pdispObj);
    // Inline: the containers' destructors (AvmLoader 0x1424ddc40) inline it and reset the AvmInteractiveObjBase part.
    virtual ~AvmInteractiveObj() {}                                     // 0x1424ddc20, ??_G 0x1424e2860

    virtual AvmInteractiveObjBase* ToAvmInteractiveObjBase() { return this; }

    virtual const char* GetAbsolutePath(String* ppath) const;           // 0x1423dcc50
    virtual bool        HasEventHandler(const EventId& id) const;
    virtual bool        OnEvent(const EventId& id);                     // 0x142518c70
    virtual void        OnEventLoad();                                  // 0x142519080
    virtual void        OnEventUnload();                                // 0x142519860
    virtual bool        OnUnloading(bool mayRemove);                    // 0x14251b0c0
    virtual const char* GetDefaultASClassName() const;                  // "flash.display.InteractiveObject" 0x142508930

    virtual bool     ActsAsButton() const;                              // 0x1424e5480
    virtual unsigned GetCursorType() const;                             // 0x142508530
    virtual void     CloneInternalData(const InteractiveObject* src);   // 0x1424efe00
    virtual void     CopyPhysicalProperties(const InteractiveObject* poldChar);    // 0x1424f1f70
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt);          // 0x142519d50
    virtual void     OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt);
    virtual bool     OnKeyEvent(const EventId& id, int* pkeyMask);
    virtual bool     OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                           FocusMovedType fmt = GFx_FocusMovedByKeyboard);
    virtual bool     IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;
    virtual bool     IsTabable() const;                                 // 0x142514f70

    virtual bool                IsStage() const { return false; }       // 0x1423dcd60
    virtual InteractiveObject*  GetTopParent(bool ignoreLockRoot = false) const;       // 0x14250f820
    virtual AvmInteractiveObj*  GetAvmTopParent(bool ignoreLockRoot = false) const;    // 0x142507590
    virtual InteractiveObject*  FindInsertToPlayList(InteractiveObject* ch);           // 0x142501a60

    InteractiveObject*  GetIntObj() const { return static_cast<InteractiveObject*>(pDispObj); }
    void        InsertChildToPlayList(InteractiveObject* ch);           // 0x142512750
    void        MoveBranchInPlayList();                                 // 0x142517ed0
    void        OnFocusChange(InteractiveObject* ptoBeFocused, unsigned controllerIdx, FocusMovedType fmt); // 0x142519ee0

    static AvmInteractiveObj* FromBase(AvmInteractiveObjBase* p)
    {
        return p ? static_cast<AvmInteractiveObj*>(p) : NULL;
    }

    UByte   MouseOverCnt;   // +0x38
    UByte   IntFlags;       // +0x39
};

// The AVM part of p (an AS3 interactive object), or NULL.
inline AvmInteractiveObj* ToAvmInteractiveObj(InteractiveObject* p)
{
    return p ? AvmInteractiveObj::FromBase(p->GetAvmIntObj()) : NULL;
}

// AS3 part of a display object container, with its AvmDisplayObjContainerBase part at +0x40. 0x48 bytes;
// vftables 0x14317cbe8 (31 slots), 0x14317cce0, 0x14317cd98.
class AvmDisplayObjContainer : public AvmInteractiveObj, public AvmDisplayObjContainerBase
{
public:
    AvmDisplayObjContainer(DisplayObjContainer* pdispObj)
        : AvmInteractiveObj(reinterpret_cast<InteractiveObject*>(pdispObj)) {}

    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase()   { return static_cast<AvmInteractiveObj*>(this); }
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase()    { return this; }

    virtual const char* GetAbsolutePath(String* ppath) const;           // 0x142506ea0
    virtual bool        HasEventHandler(const EventId& id) const;       // 0x142510dd0
    virtual bool        OnEvent(const EventId& id);                     // 0x142518c50
    virtual void        OnEventLoad();                                  // 0x142519040
    virtual void        OnEventUnload();                                // 0x142519840
    virtual bool        OnUnloading(bool mayRemove);                    // 0x14251b0a0
    virtual const char* GetDefaultASClassName() const;                  // "flash.display.DisplayObjectContainer"
    virtual void        PropagateEvent(const Instances::fl_events::Event& evt, bool inclChildren = true); // 0x14251f430
    virtual bool        GetObjectsUnderPoint(ArrayDH<Ptr<DisplayObjectBase> >* destArray, const Render::PointF& pt) const; // 0x14250c360
    virtual bool        DetachChild(DisplayObjectBase* ch);             // 0x1424f7190
    virtual InteractiveObject*  FindInsertToPlayList(InteractiveObject* ch);           // 0x142501920

    virtual bool     ActsAsButton() const;
    virtual unsigned GetCursorType() const;
    virtual void     CloneInternalData(const InteractiveObject* src);
    virtual void     CopyPhysicalProperties(const InteractiveObject* poldChar);
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt);
    virtual void     OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt);
    virtual bool     OnKeyEvent(const EventId& id, int* pkeyMask);
    virtual bool     OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                           FocusMovedType fmt = GFx_FocusMovedByKeyboard);
    virtual bool     IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;
    virtual bool     IsTabable() const;                                 // 0x142514f10

    virtual bool        IsLevelMovie() const;                           // 0x142514330
    virtual void        ForceShutdown();                                // 0x142504800
    virtual void        ExecuteInitActionFrameTags(unsigned frame);     // 0x1424fee00
    virtual void        ExecuteFrame0Events();                          // 0x1424fe5f0
    virtual void        ExecuteFrameTags(unsigned frame);               // 0x1424feaa0

    virtual void        FillTabableArray(InteractiveObject::FillTabableParams* params);  // 0x142500770

    static AvmDisplayObjContainer* FromBase(AvmDisplayObjContainerBase* p)
    {
        return p ? static_cast<AvmDisplayObjContainer*>(p) : NULL;
    }
    DisplayObjContainer* GetDisplayObjContainer() const
    {
        return reinterpret_cast<DisplayObjContainer*>(pDispObj);
    }

    void SetChildIndex(DisplayObjectBase* ch, unsigned index);          // 0x142526610
    void SwapChildrenAt(unsigned i1, unsigned i2);                      // 0x14252e6d0
    void SwapChildren(DisplayObjectBase* ch1, DisplayObjectBase* ch2);  // 0x14252e590
    DisplayObjectBase* RemoveChild(DisplayObjectBase* ch);              // the child removed, or NULL. 0x142522570
    void RemoveChildAt(unsigned index);                                 // 0x1425226a0
    void AddChild(DisplayObjectBase* ch);                               // 0x1424e6d90
    void AddChildAt(DisplayObjectBase* ch, unsigned index);             // 0x1424e6e90
    SPtr<Instances::fl_display::DisplayObject> GetAS3ChildAt(unsigned index);                // 0x142505cc0
    SPtr<Instances::fl_display::DisplayObject> GetAS3ChildByName(const ASString& name);      // 0x142505d40
};

// AS3 part of a sprite, with its AvmSpriteBase part at +0x48. 0x68 bytes; vftables 0x14317ce80, 0x14317cf78,
// 0x14317d030, 0x14317d0f0. Ctor 0x1424d6590.
class AvmSprite : public AvmDisplayObjContainer, public AvmSpriteBase
{
public:
    enum
    {
        Flag_ButtonMode         = 0x01,
        Flag_NeedExecuteFrame   = 0x02,
        Flag_ChildrenCreated    = 0x04
    };

    AvmSprite(Sprite* pspr);
    virtual ~AvmSprite();                                               // 0x1424ddce0, ??_G 0x1424e29a0

    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase()   { return static_cast<AvmInteractiveObj*>(this); }
    virtual AvmSpriteBase*              ToAvmSpriteBase()           { return this; }
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase()    { return static_cast<AvmDisplayObjContainer*>(this); }

    virtual AvmButtonBase*              ToAvmButttonBase()          { return NULL; }
    virtual AvmTextFieldBase*           ToAvmTextFieldBase()        { return NULL; }

    // The AvmSpriteBase part needs its own overriders of these: forwarders to the container's.
    virtual const char* GetAbsolutePath(String* ppath) const            { return AvmDisplayObjContainer::GetAbsolutePath(ppath); }
    virtual bool        HasEventHandler(const EventId& id) const        { return AvmDisplayObjContainer::HasEventHandler(id); }
    virtual bool        OnEvent(const EventId& id);                     // 0x142518df0
    virtual void        OnEventLoad();                                  // 0x1425190b0
    virtual void        OnEventUnload();                                // 0x142519880
    virtual bool        OnUnloading(bool mayRemove);                    // 0x14251b0e0
    virtual const char* GetDefaultASClassName() const;                  // "flash.display.Sprite" 0x142508950
    virtual bool        GetObjectsUnderPoint(ArrayDH<Ptr<DisplayObjectBase> >* destArray, const Render::PointF& pt) const; // 0x14250c7c0

    virtual bool     ActsAsButton() const;                              // 0x1424e54b0
    virtual unsigned GetCursorType() const;                             // 0x142508540
    virtual void     CloneInternalData(const InteractiveObject* src);   // 0x1424efe10
    virtual void     CopyPhysicalProperties(const InteractiveObject* poldChar)
    {
        AvmDisplayObjContainer::CopyPhysicalProperties(poldChar);
    }
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt)
    {
        AvmDisplayObjContainer::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
    }
    virtual void     OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt)
    {
        AvmDisplayObjContainer::OnGettingKeyboardFocus(controllerIdx, fmt);
    }
    virtual bool     OnKeyEvent(const EventId& id, int* pkeyMask)
    {
        return AvmDisplayObjContainer::OnKeyEvent(id, pkeyMask);
    }
    virtual bool     OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                           FocusMovedType fmt = GFx_FocusMovedByKeyboard)
    {
        return AvmDisplayObjContainer::OnLosingKeyboardFocus(newFocusCh, controllerIdx, fmt);
    }
    virtual bool     IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;   // 0x1425142a0
    virtual bool     IsTabable() const;                                 // 0x142514fc0

    virtual bool        IsLevelMovie() const;                           // 0x142514340
    virtual void        ForceShutdown();                                // 0x142504810
    virtual void        ExecuteInitActionFrameTags(unsigned frame);     // 0x1424fee10
    virtual void        ExecuteFrame0Events();                          // 0x1424fe600
    virtual void        ExecuteFrameTags(unsigned frame);               // 0x1424feab0

    virtual DisplayObjectBase* AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                                const void* pinitSource, unsigned createFrame,
                                                unsigned long addFlags, CharacterCreateInfo* pcharCreateOverride,
                                                InteractiveObject* origChar);              // 0x1424e7140
    virtual void        AdvanceFrame(bool nextFrame, float framePos);   // 0x1424eb130
    virtual int         GetLevel() const;
    virtual bool        MustBeInPlaylist() const;                       // 0x142518160
    virtual void        FillTabableArray(InteractiveObject::FillTabableParams* params)
    {
        AvmDisplayObjContainer::FillTabableArray(params);
    }

    Sprite*     GetSprite() const { return reinterpret_cast<Sprite*>(pDispObj); }
    // Creates the timeline children of frame 0 once.  0x1424f3320
    void        CreateChildren();
    // Queues the frame script of frame for the frame action level.  0x1425200b0
    void        QueueFrameScript(unsigned frame);

    UByte*      InitActionsExecuted;        // +0x50 one bit per frame (FixedBitSetLH)
    unsigned    InitActionsExecutedSize;    // +0x58 bits (the ctor stores 4 bytes)
    UInt32      InitActionsExecutedPad;     // +0x5c end of the 0x10-byte bit set
    UByte       SprFlags;                   // +0x60 Flag_*
};

inline AvmDisplayObj* ToAvmDisplayObj(DisplayObjectBase* p)
{
    return static_cast<AvmDisplayObj*>(p->GetAvmObjImpl());
}

// Opaque until recovered: size and constructor. The display objects among them are used through their
// DisplayObjectBase part (offset 0) via AsDisplayObject().
template <class T> inline DisplayObjectBase* AsDisplayObject(T* p) { return reinterpret_cast<DisplayObjectBase*>(p); }
#ifndef SF_AS3_SHAPEOBJECT_MODEL
class ShapeObject
{
public:
    ShapeObject(CharacterDef* pdef, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id);
    UByte Data[0xd0];
};

class AvmBitmap
{
public:
    AvmBitmap(ASMovieRootBase* pasRoot, const CharacterCreateInfo& ccinfo, InteractiveObject* pparent, ResourceId id);
    UByte Data[0xd0];
};
#else
// (appended, sfr24) The class model of ShapeObject / AvmBitmap, opt-in (SF_AS3_SHAPEOBJECT_MODEL) while their
// constructors (sfr_as3_15) are still written over the opaque Data[0xd0] versions above. Both are 0xd0 bytes: the
// DisplayObject (0x90), the AvmDisplayObj part at +0x90, then two pointers of their own. Over DisplayObject's
// vftables 0x14318dcd0 (79 slots) / 0x14318df48 and AvmDisplayObj's 0x14317c160 they override only the slots listed.
// A unit that defines the destructor or a constructor makes the compiler emit the vftables, which needs every
// out-of-line virtual below defined or pinned.
} } } // namespace Scaleform::GFx::AS3
#include "ms2/scaleform/include/gfx/gfx_drawingcontext.h"
#include "ms2/scaleform/include/gfx/gfx_imageresource.h"
#include "ms2/scaleform/include/gfx/gfx_shapedef.h"
namespace Scaleform { namespace GFx { namespace AS3 {

// A shape on the display list. Vftables 0x14317c210, 0x14317c488 (+0x18), 0x14317c498 (+0x90); ctor 0x1424d98a0.
class ShapeObject : public DisplayObject, public AvmDisplayObj
{
public:
    ShapeObject(CharacterDef* pdef, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id);
    // Body: AvmObjOffset = 0 (the AS3 part is a base here, not one DisplayObjectBase destroys). ??_G 0x1424e3890
    virtual ~ShapeObject();

    virtual Ptr<Render::TreeNode> CreateRenderNode(Render::ContextImpl::Context& context) const;   // 1  0x1424f3f40
    // The morph ratio of the render node when it is a shape node, else 0.
    virtual float           GetRatio() const;                                                   // 15 0x14250d630
    virtual void            SetRatio(float ratio);                                              // 16 0x142528da0
    virtual RectF           GetBounds(const Matrix& t) const;                                   // 55 0x142507910
    virtual RectF           GetRectBounds(const Matrix& t) const;                               // 56 0x14250d700
    // The drawn graphics first, then the shape of the definition.
    virtual bool            PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;      // 57 0x14251cac0
    virtual TopMostResult   GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);      // 58 0x14250f770
    virtual CharacterDef*   GetCharacterDef() const;                                            // 59 0x142507b70 pDef
    // The drawing context of the AS3 Graphics API, made on first use.
    virtual DrawingContext* GetDrawingContext();                                                // 77 0x1425099a0

    virtual const char*     GetDefaultASClassName() const { return "flash.display.Shape"; }     // AvmDisplayObj 16 0x142508990

    Ptr<ShapeBaseCharacterDef>  pDef;       // +0xc0
    Ptr<DrawingContext>         pDrawing;   // +0xc8
};
static_assert(sizeof(ShapeObject) == 0xd0, "ShapeObject size");

// A bitmap on the display list. Vftables 0x14317c560, 0x14317c7d8 (+0x18), 0x14317c7e8 (+0x90); ctor 0x1424d6270.
class AvmBitmap : public DisplayObject, public AvmDisplayObj
{
public:
    AvmBitmap(ASMovieRootBase* pasRoot, const CharacterCreateInfo& ccinfo, InteractiveObject* pparent, ResourceId id);
    // Body: AvmObjOffset = 0. ??_G 0x1424e2610
    virtual ~AvmBitmap();

protected:
    virtual Ptr<Render::TreeNode> CreateRenderNode(Render::ContextImpl::Context& context) const;   // 1  0x1424f3e60
public:
    // Drops the bitmap data of the AS3 object.
    virtual void            ForceShutdown();                                                    // 54 0x1425047c0
    virtual RectF           GetBounds(const Matrix& t) const;                                   // 55 0x142507730
    virtual RectF           GetRectBounds(const Matrix& t) const { return GetBounds(t); }       // 56 0x14250d6b0
    virtual bool            PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;      // 57 0x14251c9f0
    virtual TopMostResult   GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);      // 58 0x14250f660
    virtual CharacterDef*   GetCharacterDef() const { return NULL; }                            // 59 0x142507b30
    virtual MovieDefImpl*   GetResourceMovieDef() const { return pDefImpl; }                    // 60 0x14250d960

    virtual unsigned        CreateASInstance(bool execute);                                     // AvmDisplayObj 15 0x1424f2010
    virtual const char*     GetDefaultASClassName() const { return "flash.display.Bitmap"; }    // AvmDisplayObj 16 0x1425088f0
    virtual String&         GetASClassName(String* className) const                             // AvmDisplayObj 17 0x142505ef0
    {
        *className = "flash.display.Bitmap";
        return *className;
    }

    void SetImage(Resource* pimage);                // 0x1425274b0
    void SetResourceMovieDef(MovieDefImpl* pdefImpl); // 0x142528e70
    // Makes the render node again from the current image, in the old one's place among the parent's children.
    Render::TreeNode* RecreateRenderNode() const;   // 0x142520b20

    Ptr<ImageResource>  pImage;     // +0xc0
    Ptr<MovieDefImpl>   pDefImpl;   // +0xc8 the movie that binds the image
};
static_assert(sizeof(AvmBitmap) == 0xd0, "AvmBitmap size");
#endif // SF_AS3_SHAPEOBJECT_MODEL

// AvmSprite of a timeline sprite. Its constructor is inlined into its users: AvmSprite's, then its own vftables.
class AvmMovieClip : public AvmSprite
{
public:
    static void Construct(AvmMovieClip* p, Sprite* pspr);
};

#ifndef SF_AS3_AVMBUTTON_MODEL
class AvmTextField
{
public:
    AvmTextField(TextField* ptxt);
    UByte Data[0x48];
};
#endif

#ifndef SF_AS3_AVMBUTTON_MODEL
class AvmStaticText
{
public:
    AvmStaticText(StaticTextCharacter* ptxt);
    UByte Data[0x30];
};
#endif

#ifndef SF_AS3_AVMBUTTON_MODEL
class AvmButton
{
public:
    AvmButton(Button* pbtn);
    UByte Data[0x48];
};
#endif

// (appended, sfr24) The class model of AvmButton / AvmTextField (and AvmStaticText), opt-in (SF_AS3_AVMBUTTON_MODEL) while their
// constructors are still written over the opaque Data[0x48] versions above. Both are AvmInteractiveObj with the
// AvmButtonBase / AvmTextFieldBase part at +0x40 and no fields of their own; their main vftables keep the 26
// AvmInteractiveObj slots. The +0x40 part brings a third AvmDisplayObjBase, so every base virtual gets an overrider
// here (forwarders where the exe's slot jumps to the base).
#ifdef SF_AS3_AVMBUTTON_MODEL
} } } // namespace Scaleform::GFx::AS3
#include "ms2/scaleform/include/gfx/gfx_button.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
namespace Scaleform { namespace GFx { namespace AS3 {

// AS3 part of a SimpleButton. 0x48 bytes; vftables 0x14317dbe0, 0x14317dcb0, 0x14317dd68. Ctor 0x1424d63e0 (sets
// Mask_TabEnabled in the button's flags), ??_G 0x1424e26d0 with the implicit destructor.
class AvmButton : public AvmInteractiveObj, public AvmButtonBase
{
public:
    AvmButton(Button* pbtn);

    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase()   { return static_cast<AvmInteractiveObj*>(this); }
    virtual AvmSpriteBase*              ToAvmSpriteBase()           { return NULL; }
    virtual AvmButtonBase*              ToAvmButttonBase()          { return this; }
    virtual AvmTextFieldBase*           ToAvmTextFieldBase()        { return NULL; }
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase()    { return NULL; }

    virtual const char* GetAbsolutePath(String* ppath) const        { return AvmInteractiveObj::GetAbsolutePath(ppath); }
    virtual bool        HasEventHandler(const EventId&) const       { return false; }
    virtual bool        OnEvent(const EventId& id)                  { return AvmInteractiveObj::OnEvent(id); }
    // Keeps the AS3 object by a counted reference from now on.     0x142518fe0
    virtual void        OnEventLoad();
    virtual void        OnEventUnload()                             { AvmDisplayObj::OnEventUnload(); }
    virtual bool        OnUnloading(bool)                           { return true; }
    virtual const char* GetDefaultASClassName() const               { return "flash.display.SimpleButton"; }
    virtual bool        DetachChild(DisplayObjectBase* ch);         // 0x1424f6f50

    virtual bool     ActsAsButton() const                           { return true; }
    virtual unsigned GetCursorType() const                          { return GetButton()->IsEnabledFlagSet(); }
    virtual void     CloneInternalData(const InteractiveObject*)    {}
    virtual void     CopyPhysicalProperties(const InteractiveObject*) {}
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt)
    {
        AvmInteractiveObj::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
    }
    virtual void     OnGettingKeyboardFocus(unsigned, FocusMovedType) {}
    virtual bool     OnKeyEvent(const EventId&, int*)               { return false; }
    virtual bool     OnLosingKeyboardFocus(InteractiveObject*, unsigned,
                                           FocusMovedType = GFx_FocusMovedByKeyboard) { return true; }
    virtual bool     IsFocusEnabled(FocusMovedType = GFx_FocusMovedByKeyboard) const  { return true; }
    virtual bool     IsTabable() const;                             // 0x142514eb0

    virtual void CreateCharacters();                                // 0x1424f2e90
    virtual bool OnMouseEvent(const EventId& event);                // 0x14251a830
    virtual bool OnButtonKeyEvent(const EventId&, int*)             { return true; }
    virtual void SwitchState(ButtonRecord::MouseState);             // 0x14252e980

    Button*     GetButton() const { return reinterpret_cast<Button*>(pDispObj); }
    // Puts the character of a state (up / over / down / hit) in place.  0x142529f70
    void        SetStateObject(Button::ButtonState state, Instances::fl_display::DisplayObject* pobj);

private:
    void        SwitchStateIntl(Button::ButtonState);               // 0x14252e9d0
};
static_assert(sizeof(AvmButton) == 0x48, "AvmButton size");

// AS3 part of a TextField. 0x48 bytes; vftables 0x14317ea80, 0x14317eb50, 0x14317ec08. Ctor 0x1424d66b0 (marks the
// field AS3 and clears its selection), ??_G 0x1424e2ac0 with the implicit destructor.
class AvmTextField : public AvmInteractiveObj, public AvmTextFieldBase
{
public:
    AvmTextField(TextField* ptxt);

    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase()   { return static_cast<AvmInteractiveObj*>(this); }
    virtual AvmSpriteBase*              ToAvmSpriteBase()           { return NULL; }
    virtual AvmButtonBase*              ToAvmButttonBase()          { return NULL; }
    virtual AvmTextFieldBase*           ToAvmTextFieldBase()        { return this; }
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase()    { return NULL; }

    virtual const char* GetAbsolutePath(String* ppath) const        { return AvmInteractiveObj::GetAbsolutePath(ppath); }
    virtual bool        HasEventHandler(const EventId&) const       { return false; }
    virtual bool        OnEvent(const EventId& id)                  { return AvmDisplayObj::OnEvent(id); }
    virtual void        OnEventLoad();                              // 0x1425190f0
    virtual void        OnEventUnload()                             { AvmDisplayObj::OnEventUnload(); }
    virtual bool        OnUnloading(bool)                           { return true; }
    virtual const char* GetDefaultASClassName() const               { return "flash.text.TextField"; }

    virtual bool     ActsAsButton() const                           { return false; }
    virtual unsigned GetCursorType() const                          { return 0; }
    virtual void     CloneInternalData(const InteractiveObject*)    {}
    virtual void     CopyPhysicalProperties(const InteractiveObject*) {}
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt)
    {
        AvmInteractiveObj::OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
    }
    virtual void     OnGettingKeyboardFocus(unsigned, FocusMovedType) {}
    virtual bool     OnKeyEvent(const EventId& id, int* pkeyMask);  // 0x14251a350
    virtual bool     OnLosingKeyboardFocus(InteractiveObject*, unsigned,
                                           FocusMovedType = GFx_FocusMovedByKeyboard) { return true; }
    // A read-only field takes no focus from the keyboard.
    virtual bool     IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const
    {
        return fmt == GFx_FocusMovedByKeyboard ? !GetTextField()->IsReadOnly() : true;
    }
    virtual bool     IsTabable() const;                             // 0x142515050

    virtual const Text::StyleManager* GetStyleSheet() const;        // 0x14250ef30
    virtual bool HasStyleSheet() const;                             // 0x1425113d0
    virtual void NotifyChanged();                                   // 0x142518360
    virtual void OnLinkEventEx(TextField::LinkEvent event, unsigned pos, unsigned controllerIndex);  // 0x14251a500
    virtual bool OnMouseEvent(const EventId& event);                // 0x14251a8a0
    virtual bool OnCharEvent(wchar_t wcharCode, unsigned controllerIdx);   // 0x142518750
    virtual void OnScroll();                                        // 0x14251ae60
    virtual bool UpdateTextFromVariable()                           { return false; }
    virtual void UpdateVariable()                                   {}

    TextField*  GetTextField() const { return reinterpret_cast<TextField*>(pDispObj); }
};
static_assert(sizeof(AvmTextField) == 0x48, "AvmTextField size");

// (appended, sfr24) AS3 part of a static text: an AvmDisplayObj with no fields of its own. 0x30 bytes; vftable
// 0x14317e9b8 (AvmDisplayObj's but for 0, 16, 17). Ctor 0x1424d6650; ??_G 0x1424e2a70 stores the vftable before
// ~AvmDisplayObj, so the destructor is the explicit empty one.
class AvmStaticText : public AvmDisplayObj
{
public:
    AvmStaticText(StaticTextCharacter* ptxt);
    virtual ~AvmStaticText() {}

    virtual const char* GetDefaultASClassName() const   { return "flash.text.StaticText"; }    // 16 0x142508970
    virtual String&     GetASClassName(String* className) const                                // 17 0x142505fd0
    {
        *className = "flash.text.StaticText";
        return *className;
    }
};
static_assert(sizeof(AvmStaticText) == 0x30, "AvmStaticText size");
#endif // SF_AS3_AVMBUTTON_MODEL

// The exe's AvmMovieClip vftables (main, AvmInteractiveObj, AvmDisplayObjContainer, AvmSpriteBase parts).
extern void* const AvmMovieClip_vftable[];
extern void* const AvmMovieClip_vftable_30[];
extern void* const AvmMovieClip_vftable_40[];
extern void* const AvmMovieClip_vftable_48[];

inline void AvmMovieClip::Construct(AvmMovieClip* p, Sprite* pspr)
{
    new (p) AvmSprite(pspr);
    UByte* pb = (UByte*)p;
    *(void* const**)(pb + 0x00) = AvmMovieClip_vftable;
    *(void* const**)(pb + 0x30) = AvmMovieClip_vftable_30;
    *(void* const**)(pb + 0x40) = AvmMovieClip_vftable_40;
    *(void* const**)(pb + 0x48) = AvmMovieClip_vftable_48;
}

}}} // namespace Scaleform::GFx::AS3

#endif
