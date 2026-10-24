// Recovered Scaleform 4.1.18 GFx AS2: the script side of a movie clip (AvmSprite) and its MovieClip natives.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_AVMSPRITE_H
#define MS2_SF_GFX_AS2_AVMSPRITE_H

#include "as2_avmcharacter.h"
#include "../gfx_sprite.h"

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
    virtual void CloneInternalData(const InteractiveObject* src);
    virtual void CopyPhysicalProperties(const InteractiveObject* poldChar); // exe 0x142935d10
    void SetLevel(int level); // exe 0x142981bf0

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
    UByte                                   Unrecovered_38[0x1e0 - 0x38];
    ArrayLH<bool, StatMV_ActionScript_Mem>  InitActionsExecuted; // +0x1e0 per frame

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
};

inline Sprite* ObjectInterface::ToSprite()
{
    return GetObjectType() == Object_Sprite ? static_cast<Sprite*>(static_cast<AvmCharacter*>(this)->GetDispObj()) : 0;
}

}}} // namespace Scaleform::GFx::AS2

#endif
