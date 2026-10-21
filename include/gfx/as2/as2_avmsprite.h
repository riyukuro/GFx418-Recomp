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
    void SetNoFill(); // exe 0x142989390
    void SetNoLine(); // exe 0x142989400
    // lineWidth in pixels (exe 0x142981da0).
    void SetLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps, unsigned joins,
                      float miterLimit);

    // The exe's out-of-line copy of SpriteGetTarget (exe 0x14298fe50).
    static Sprite* SpriteGetTarget_Call(const FnCall& fn);
    // Mirrors the clip's button handler state into its MovieClipObject (exe 0x142981650).
    void SetHasButtonHandlers(bool has);

private:
    // Both lookups: penv is 0 for GetMemberRaw, psc 0 for GetMember (exe 0x14294bff0).
    bool GetMember(Environment* penv, ASStringContext* psc, const ASString& name, Value* val);
    MovieClipObject* GetMovieClipObject(); // exe 0x142953da0
};

inline Sprite* ObjectInterface::ToSprite()
{
    return GetObjectType() == Object_Sprite ? static_cast<Sprite*>(static_cast<AvmCharacter*>(this)->GetDispObj()) : 0;
}

}}} // namespace Scaleform::GFx::AS2

#endif
