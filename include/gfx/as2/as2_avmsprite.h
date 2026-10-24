// Recovered Scaleform 4.1.18 GFx AS2: the script side of a movie clip (AvmSprite) and its MovieClip natives.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_AVMSPRITE_H
#define MS2_SF_GFX_AS2_AVMSPRITE_H

#include "as2_avmcharacter.h"
#include "../gfx_sprite.h"
#include "as2_action.h"

namespace Scaleform { namespace GFx { namespace AS2 {

class MovieClipObject;

class AvmSprite : public AvmCharacter, public AvmSpriteBase
{
public:
    // The clip a MovieClip method works on: this, or the target of the environment for a plain function call.
    static Sprite* SpriteGetTarget(const FnCall& fn)
    {
        if (!fn.ThisPtr)
            return static_cast<Sprite*>(fn.Env->GetTarget());
        return fn.ThisPtr->ToSprite();
    }
    static InteractiveObject* CharacterGetTarget(const FnCall& fn)
    {
        if (!fn.ThisPtr)
            return fn.Env->GetTarget();
        return fn.ThisPtr->ToCharacter();
    }

    static void SpritePlay(const FnCall& fn);
    static void SpriteStop(const FnCall& fn);
    static void SpriteNextFrame(const FnCall& fn);
    static void SpritePrevFrame(const FnCall& fn);
    static void SpriteUnloadMovie(const FnCall& fn);
    static void SpriteGetBytesLoaded(const FnCall& fn);
    static void SpriteGetBytesTotal(const FnCall& fn);

    // ObjectInterface overrides (the AvmSprite vftables are not modeled yet).
    virtual bool DeleteMember(ASStringContext* psc, const ASString& name); // exe 0x142938830
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);          // exe 0x14294c700
    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);    // exe 0x1429531f0

    AvmSprite(Sprite* psprite); // exe 0x142918980

    // (sfr32) exe 0x142925420: releases the clip's script data, its object and its environment.
    virtual ~AvmSprite();

    Sprite*         GetSprite() const { return static_cast<Sprite*>(pDispObj); }
    DrawingContext* GetDrawingContext() { return GetSprite()->GetDrawingContext(); }
    // Ends the open path before a style change (the exe's out-of-line copy is 0x14292dfe0).
    DrawingContext* AcquirePath(bool newShapeFlag)
    {
        DrawingContext* pdc = GetDrawingContext();
        GetSprite()->SetDirtyFlag();
        GetSprite()->InvalidateHitResult();
        pdc->AcquirePath(newShapeFlag);
        return pdc;
    }
    // The drawing API of the clip (coordinates in pixels); each ends the open path first, as AcquirePath(true).
    void                 BeginFill(unsigned rgba);                                   // exe 0x142932120
    Render::ComplexFill* BeginFill();                                                // exe 0x1429320c0
    void                 BeginBitmapFill(FillType fillType, ImageResource* pimageRes,
                                         const Render::Matrix2F& mtx);              // exe 0x142932040
    void                 CurveTo(float cx, float cy, float ax, float ay);            // exe 0x142937f90
    void                 MoveTo(float x, float y);                                   // exe 0x142968f00
    void                 LineTo(float x, float y);                                   // exe 0x142966370
    void SetNoFill(); // exe 0x142989390
    void SetNoLine(); // exe 0x142989400
    // lineWidth in pixels (exe 0x142981da0).
    void SetLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps, unsigned joins,
                      float miterLimit);

    // The exe's out-of-line copy of SpriteGetTarget (exe 0x14298fe50).
    static Sprite* SpriteGetTarget_Call(const FnCall& fn);
    // Mirrors the clip's button handler state into its MovieClipObject (exe 0x142981650).
    void SetHasButtonHandlers(bool has);

    // (appended for sfr_as2_02: the drawing API natives)
    static void SpriteClear(const FnCall& fn);
    static void SpriteBeginFill(const FnCall& fn);
    static void SpriteEndFill(const FnCall& fn);
    static void SpriteMoveTo(const FnCall& fn);
    static void SpriteLineTo(const FnCall& fn);
    static void SpriteCurveTo(const FnCall& fn);
    static void SpriteGotoAndStop(const FnCall& fn);
    static void SpriteGotoAndPlay(const FnCall& fn);
    static void SpriteRemoveMovieClip(const FnCall& fn);
    static void SpriteGetNextHighestDepth(const FnCall& fn);
    static void SpriteGetInstanceAtDepth(const FnCall& fn);
    static void SpriteSetMask(const FnCall& fn);
    static void SpriteSwapDepths(const FnCall& fn);
    static void SpriteLoadMovie(const FnCall& fn);
    static void SpriteLoadVariables(const FnCall& fn);
    static void SpriteGetBounds(const FnCall& fn);
    static void SpriteGetRect(const FnCall& fn);
    static void SpriteLocalToGlobal(const FnCall& fn);
    static void SpriteGlobalToLocal(const FnCall& fn);
    static void SpriteGetSWFVersion(const FnCall& fn);
    static void SpriteStopDrag(const FnCall& fn);
    static void SpriteDuplicateMovieClip(const FnCall& fn);
    static void SpriteGetTextSnapshot(const FnCall& fn);
    static void SpriteCreateEmptyMovieClip(const FnCall& fn);
    static void SpriteAttachAudio(const FnCall& fn);
    static void SpriteAttachMovie(const FnCall& fn);
    static void SpriteStartDrag(const FnCall& fn);
    static void SpriteBeginGradientFill(const FnCall& fn);
    static void SpriteBeginBitmapFill(const FnCall& fn);
    static void SpriteLineGradientStyle(const FnCall& fn);
    static void SpriteLineStyle(const FnCall& fn);
    // The script side of a clip; AvmCharacter sits at the start of its AVM object.
    static AvmSprite* FromSprite(Sprite* psprite)
    {
        return static_cast<AvmSprite*>(
            static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(psprite->GetAvmObjImpl())));
    }

private:
    // Fills a gradient from beginGradientFill / lineGradientStyle arguments (exe 0x14298efe0).
    static void SpriteCreateGradient(const FnCall& fn, Render::ComplexFill* pfill);
    // Both lookups: penv is 0 for GetMemberRaw, psc 0 for GetMember (exe 0x14294bff0).
    bool GetMember(Environment* penv, ASStringContext* psc, const ASString& name, Value* val);
    MovieClipObject* GetMovieClipObject(); // exe 0x142953da0

public:
    // (appended for sfr_as2_04)
    // Queues the frame actions of pbuffer on this clip (exe 0x14292e650).
    void AddActionBuffer(ActionBuffer* pbuffer, ActionPriority::Priority prio = ActionPriority::AP_Frame);
    // Copies the event handlers of src; button handlers carry over to the clip object (exe 0x1429348c0).
    virtual void AdvanceFrame(bool nextFrame, float framePos); // exe 0x142931430
    virtual void CloneInternalData(const InteractiveObject* src);
    virtual void CopyPhysicalProperties(const InteractiveObject* poldChar); // exe 0x142935d10
    void SetLevel(int level); // exe 0x142981bf0
    void CallFrameActions(unsigned frame); // exe 0x1429329a0 (sfr32)

    // (appended for sfr_as2_05)
    // Runs the whole buffer in the clip's environment; false once the clip is unloaded (exe 0x14293ff10).
    virtual bool ExecuteBuffer(ActionBuffer* pactionbuffer);
    // AvmSpriteBase overrides: queues the load event of frame 0 (exe 0x142941330); runs the frame's InitActions
    // tags once (exe 0x1429415c0).
    virtual void ExecuteFrame0Events();
    virtual void ExecuteInitActionFrameTags(unsigned frame);
    // AvmInteractiveObjBase override: hand or arrow (exe 0x14294a430).
    virtual unsigned GetCursorType() const;
    // AvmCharacter override: a path element relative to the clip (exe 0x142954d10).
    virtual InteractiveObject* GetRelativeTarget(const ASString& name, bool firstCall);

    // The data members (only those used so far). AvmSpriteBase's vftable is at +0x30.
    Environment                             Env;             // +0x38 (0x198 bytes)
    int                                     Level;           // +0x1d0 -1 until the clip is made a level movie
    Ptr<MovieClipObject>                    pMovieClipObj;   // +0x1d8 created on first use
    ArrayLH<bool, StatMV_ActionScript_Mem>  InitActionsExecuted; // +0x1e0 per frame
    bool                                    Unrecovered_1f8;  // +0x1f8 cleared by the constructor (FillTabableArray reads it as the clip's tabChildren: 0 unset, 2 off)

    // (appended for sfr_as2_02)
    static void SpriteCreateTextField(const FnCall& fn); // exe 0x142906040
    static void SpriteHitTest(const FnCall& fn); // exe 0x1429049b0
    static void SpriteAttachBitmap(const FnCall& fn); // exe 0x142905190

    // (appended for sfr_as2_06)
    // MS2-FUNCTIONAL: property lookup and button fallback are recovered from the executable.
    virtual bool IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;
    // A child was put on the display list: its queued actions run unless it came from a place-object tag; a sprite
    // child with an onLoad handler (or any placed sprite) then needs its load event (exe 0x14296aa90).
    void OnAddedDisplayObject(InteractiveObject* ch, unsigned sessionId, bool placeObject);
    // The AS2 side of putting a child on the display list (exe 0x14296ab10): binds its events and init source and
    // returns the session of the queued actions.
    unsigned OnAddingDisplayObject(const CharacterCreateInfo& ccinfo, InteractiveObject* pch,
                                   const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                   const void* pinitSource, bool placeObject);
    // AvmSpriteBase slot (exe 0x14292ea50): a place-object tag creates, or moves, the child at pos.Depth.
    virtual DisplayObjectBase* AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                                const void* pinitSource, unsigned createFrame,
                                                unsigned long addFlags, CharacterCreateInfo* pcharCreateOverride,
                                                InteractiveObject* origChar);
    // The replacement gets its load event and the queued actions run at once (exe 0x14297d460).
    virtual bool ReplaceChildCharacterOnLoad(InteractiveObject* poldChar, InteractiveObject* pnewChar);
    // Calls the clip's method with numArgs arguments already on its environment's stack (exe 0x142962b30), or
    // with the arguments in methodArgFmt and args (exe 0x142963fc0).
    bool Invoke(const char* methodName, Value* presult, unsigned numArgs);
    bool InvokeArgs(const char* methodName, Value* presult, const char* methodArgFmt, va_list args);
    // AvmSpriteBase override: an onEnterFrame handler keeps the clip in the playlist (exe 0x142969000).
    virtual bool MustBeInPlaylist() const;
    // ch (a child at its depth) leaves the display list; false when it is not there (exe 0x14297cf70).
    bool RemoveCharacter(DisplayObjectBase* ch);
    // A clip event handler, or a method of the event's name on the clip object or the prototype (exe 0x14295d4f0).
    virtual bool HasEventHandler(const EventId& id) const;
    // (appended for sfr_as2_04) An enabled clip that is not a level movie, whose clip object or first movie clip prototype
    // has button handlers (exe 0x14292e050).
    virtual bool ActsAsButton() const;

    // (sfr32) The vftable overrides of the clip, in the exe's slot order. The AvmSpriteBase half is at +0x30; the
    // exe's functions that sit in its vftable alone take that subobject as this.
    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase();   // exe 0x142990e20
    virtual AvmSpriteBase*              ToAvmSpriteBase();           // exe 0x142990eb0
    virtual AvmButtonBase*              ToAvmButttonBase();          // exe 0x142990ce0
    virtual AvmTextFieldBase*           ToAvmTextFieldBase();        // exe 0x142990ef0
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase();    // exe 0x142990de0
    virtual const char*                 GetAbsolutePath(String* ppath) const; // exe 0x142949620
    virtual bool                        OnEvent(const EventId& id);  // exe 0x14296b490
    virtual void                        OnEventLoad();               // exe 0x14296b860
    virtual void                        OnEventUnload();             // exe 0x14296bbb0
    virtual bool                        OnUnloading(bool mayRemove); // exe 0x14296d140
    virtual void                        OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                                                unsigned controllerIdx, FocusMovedType fmt); // exe 0x14296c0d0
    virtual void                        OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt); // exe 0x14296c160
    virtual bool                        OnKeyEvent(const EventId& id, int* pkeyMask);                       // exe 0x14296c1b0
    virtual bool                        OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                                              FocusMovedType fmt);                          // exe 0x14296c200
    virtual bool                        IsTabable() const;           // exe 0x1429660a0
    virtual Object*                     GetASObject();               // exe 0x142949470
    virtual Object*                     GetASObject() const;         // exe 0x142949480
    virtual Environment*                GetASEnvironment();          // exe 0x142949410
    virtual const Environment*          GetASEnvironment() const;    // exe 0x142949420
    virtual unsigned                    GetStandardMemberBitMask() const; // exe 0x142956070
    virtual bool SetStandardMember(StandardMember index, const Value& val, bool opcodeFlag); // exe 0x14298b410
    virtual bool GetStandardMember(StandardMember index, Value* val, bool opcodeFlag) const; // exe 0x142955c50
    virtual bool ExecuteEvent(const EventId& id);                    // exe 0x1429409a0
    virtual ObjectType                  GetObjectType() const;       // exe 0x142954170
    virtual bool SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val,
                              const PropFlags& flags = PropFlags()); // exe 0x142988a40
    virtual void VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags = 0,
                              const ObjectInterface* instance = 0) const; // exe 0x142994710
    virtual void FillTabableArray(InteractiveObject::FillTabableParams* params); // exe 0x142941b40
    virtual void ExecuteFrameTags(unsigned frame);                   // exe 0x1429413b0
    virtual void ForceShutdown();                                    // exe 0x142945d80
    virtual int  GetLevel() const;                                   // exe 0x14294b110
    virtual bool IsLevelMovie() const;                               // exe 0x142965ce0
    virtual bool CheckCandidateListLevel(int level) const;           // exe 0x142933430
    virtual void SetHitAreaNotify(Sprite* phitArea);                 // exe 0x142981670

    // (appended for sfr_as2_06e)
    // pnewChar takes the place, properties and name of poldChar, which gets its unload event (exe 0x14297d330).
    virtual bool ReplaceChildCharacter(InteractiveObject* poldChar, InteractiveObject* pnewChar);

private:
    // Natives run on a clip of a registered class: it takes the prototype of the constructor in Arg(0)
    // (exe 0x142961d80); the members of the init object in Arg(0) are set on it (exe 0x142961a40).
    static void InitializeClassInstance(const FnCall& fn);
    static void InitObjectMembers(const FnCall& fn);
};

inline Sprite* ObjectInterface::ToSprite()
{
    return GetObjectType() == Object_Sprite ? static_cast<Sprite*>(static_cast<AvmCharacter*>(this)->GetDispObj()) : 0;
}

}}} // namespace Scaleform::GFx::AS2

#endif
