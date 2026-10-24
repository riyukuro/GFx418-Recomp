// Recovered Scaleform 4.1.18 GFx AS2: the Sound class (a sample from the library or a file, played on a clip).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_SOUNDOBJECT_H
#define MS2_SF_GFX_AS2_SOUNDOBJECT_H

#include "as2_movieroot.h"
#include "as2_objectproto.h"
#include "../gfx_sound.h"

namespace Scaleform { namespace GFx {

class Sprite;
class CharacterHandle;
class MovieImpl;

namespace AS2 {

// Sound instance. 0x90 bytes; vftables 0x143222bf0 (Object), 0x143222c38 (ObjectInterface), 0x143222ce0
// (ASSoundIntf).
class SoundObject : public Object, public ASSoundIntf
{
protected:
    SoundObject(ASStringContext* psc, Object* pprototype) : Object(psc), pMovieRoot(0)
    {
        Set__proto__(psc, pprototype);
    }

    virtual void Finalize_GC(); // exe 0x142998610

public:
    SoundObject(Environment* penv); // exe 0x142997bc0
    virtual ~SoundObject();         // exe 0x142997db0

    virtual ObjectType GetObjectType() const { return Object_Sound; }

    // position and duration (milliseconds) are computed, the rest are plain members (exe 0x1429986f0).
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);

    void    AttachToTarget(Sprite* psprite); // exe 0x142998130
    void    DetachFromTarget();              // exe 0x142998200
    // The clip the sound plays on, 0 once it is gone (exe 0x142998950).
    Sprite* GetSprite();

    // ASSoundIntf
    virtual void ExecuteOnSoundComplete(); // exe 0x1429982b0: the onSoundComplete handler
    virtual void ReleaseTarget();          // exe 0x142998e80

    Ptr<Sound::SoundSample> pSample;       // +0x70
    Ptr<SoundResource>      pResource;     // +0x78 set when the sample came from the movie's library
    Ptr<CharacterHandle>    pTargetHandle; // +0x80
    MovieImpl*              pMovieRoot;    // +0x88
};

// Sound.prototype.
class SoundProto : public Prototype<SoundObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143222ad0

    SoundProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142997c70

    static void Attach(const FnCall& fn);         // exe 0x1429967b0
    static void GetBytesLoaded(const FnCall& fn); // exe 0x1429969d0
    static void GetBytesTotal(const FnCall& fn);  // exe 0x142996a50
    static void GetPan(const FnCall& fn);         // exe 0x142996ad0
    static void GetTransform(const FnCall& fn);   // exe 0x142996b60
    static void GetVolume(const FnCall& fn);      // exe 0x142996b80
    static void LoadSound(const FnCall& fn);      // exe 0x142996c30
    static void SetPan(const FnCall& fn);         // exe 0x1429973c0
    static void SetTransform(const FnCall& fn);
    static void SetVolume(const FnCall& fn);      // exe 0x142997450
    static void Start(const FnCall& fn);          // exe 0x142997500
    static void Stop(const FnCall& fn);           // exe 0x1429976e0
};

// The Sound constructor function.
class SoundCtorFunction : public CFunctionObject
{
public:
    SoundCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor) {}

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429981c0

    // new Sound(target): attached to the target clip, _level0 without one (exe 0x1429989a0).
    static void GlobalCtor(const FnCall& fn);

    // Creates the class and its prototype and publishes "Sound" (exe 0x142998b50).
    static FunctionRef Register(GlobalContext* pgc);
};

}}} // namespace Scaleform::GFx::AS2

#endif
