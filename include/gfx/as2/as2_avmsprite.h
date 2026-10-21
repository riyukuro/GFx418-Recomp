// Recovered Scaleform 4.1.18 GFx AS2: the script side of a movie clip (AvmSprite) and its MovieClip natives.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_AVMSPRITE_H
#define MS2_SF_GFX_AS2_AVMSPRITE_H

#include "as2_avmcharacter.h"
#include "../gfx_sprite.h"

namespace Scaleform { namespace GFx { namespace AS2 {

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
};

inline Sprite* ObjectInterface::ToSprite()
{
    return GetObjectType() == Object_Sprite ? static_cast<Sprite*>(static_cast<AvmCharacter*>(this)->GetDispObj()) : 0;
}

}}} // namespace Scaleform::GFx::AS2

#endif
