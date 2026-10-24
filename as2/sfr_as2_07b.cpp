// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Sound class (gap recovery of
// sfr_as2_07): the prototype methods, the object, its prototype and constructor function.
// MS2-UNIT: sfr_as2_07b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429967b0-0x142998ee0 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_soundobject.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/sound/sound_renderer.h"
#include "../include/sound/sound_sound.h"

void FUN_14000c280(void* owner, unsigned key, void** value);

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// fn.Arg(n) as a call: the exe does not inline the argument lookup in this file.
#pragma inline_depth(0)
SF_FORCEINLINE Value& SoundArg(const FnCall& fn, int n)
{
    return fn.Arg(n);
}
#pragma inline_depth()

// The movie's sound player; the Audio state is only held for the call.
inline Sound::SoundRenderer* GetSoundRenderer(MovieImpl* pmovie)
{
    Ptr<AudioBase> paudio = *(AudioBase*)pmovie->GetStateBag()->GetStateAddRef(State::State_Audio);
    if (!paudio)
        return 0;
    return paudio->GetRenderer();
}

// The sound resource exported from the target's movie under the given id, 0 if there is none (the binding data
// keeps the reference).
inline SoundResource* FindSoundResource(Environment* penv, MovieDefImpl* pmd, const ASString& id, ResourceBindData* pbd)
{
    if (!penv->GetMovieImpl()->FindExportedResource(pmd, pbd, String(id.ToCStr())))
        return 0;
    if (pbd->pResource->GetResourceType() != Resource::RT_SoundSample)
        return 0;
    return static_cast<SoundResource*>(pbd->pResource.GetPtr());
}

// Runs this.onLoad(success) if the object has a handler.
inline void InvokeOnLoad(const FnCall& fn, SoundObject* pobj, bool success)
{
    Value callback;
    if (pobj->GetMemberRaw(fn.Env->GetSC(), fn.Env->CreateConstString("onLoad"), &callback))
    {
        FunctionRef method = callback.ToFunction(fn.Env);
        Value       result;
        fn.Env->Push(success);
        method.Invoke(FnCall(&result, pobj, fn.Env, 1, fn.Env->GetTopIndex()));
        fn.Env->Drop(1);
    }
}

// Ptr<CharacterHandle> = phandle with the handle's release written out (the exe inlines it; ours does not).
inline void SetTargetHandle(Ptr<CharacterHandle>& ptr, CharacterHandle* phandle)
{
    if (phandle)
        phandle->AddRef();
    CharacterHandle** ppobj = reinterpret_cast<CharacterHandle**>(&ptr);
    CharacterHandle*  pold  = *ppobj;
    if (pold && --pold->RefCount <= 0)
    {
        pold->~CharacterHandle();
        Memory::Free(pold);
    }
    *ppobj = phandle;
}

static SF_FORCEINLINE void SetBuiltinPrototype(GlobalContext* pgc, ASBuiltinType type, Object* proto)
{
    ::FUN_14000c280(pgc, type, reinterpret_cast<void**>(&proto));
}

} // namespace

// MS2-FUNCTIONAL: the resource lookup kept in a helper; same lookup, same sample/resource stored
// @0x1429967b0
void SoundProto::Attach(const FnCall& fn)
{
    Sound::SoundRenderer* pplayer = GetSoundRenderer(fn.Env->GetMovieImpl());
    if (!pplayer)
        return;
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Sound.AttachSound requires one argument (file name)");
        return;
    }
    ASString            id   = SoundArg(fn, 0).ToString(fn.Env);
    SoundObject*        pobj = static_cast<SoundObject*>(fn.ThisPtr);
    Ptr<MovieDefImpl>   pmd  = fn.Env->GetTarget()->GetResourceMovieDef();
    if (pobj && pmd)
    {
        ResourceBindData bd;
        SoundResource*   psound = FindSoundResource(fn.Env, pmd, id, &bd);
        if (psound)
        {
            pobj->pSample   = psound->GetSoundInfo()->GetSoundSample(pplayer);
            pobj->pResource = psound;
        }
    }
}

// @0x1429969d0
void SoundProto::GetBytesLoaded(const FnCall& fn)
{
    fn.Result->SetUndefined();
    SoundObject* pobj = static_cast<SoundObject*>(fn.ThisPtr);
    if (pobj && !pobj->pResource && pobj->pSample)
        fn.Result->SetInt(pobj->pSample->GetBytesLoaded());
}

// @0x142996a50
void SoundProto::GetBytesTotal(const FnCall& fn)
{
    fn.Result->SetUndefined();
    SoundObject* pobj = static_cast<SoundObject*>(fn.ThisPtr);
    if (pobj && !pobj->pResource && pobj->pSample)
        fn.Result->SetInt(pobj->pSample->GetBytesTotal());
}

// @0x142996ad0
void SoundProto::GetPan(const FnCall& fn)
{
    SoundObject* pobj = static_cast<SoundObject*>(fn.ThisPtr);
    if (!pobj)
        return;
    Sprite* psprite = pobj->GetSprite();
    if (psprite)
        fn.Result->SetInt(psprite->GetSoundPan());
}

// @0x142996b60
void SoundProto::GetTransform(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// @0x142996b80
void SoundProto::GetVolume(const FnCall& fn)
{
    SoundObject* pobj = static_cast<SoundObject*>(fn.ThisPtr);
    fn.Result->SetUndefined();
    if (!pobj)
        return;
    Sprite* psprite = pobj->GetSprite();
    if (psprite)
        fn.Result->SetInt(psprite->GetSoundVolume());
}

// MS2-FUNCTIONAL: other register allocation and frame layout; same URL resolution, sample creation and onLoad calls
// @0x142996c30
void SoundProto::LoadSound(const FnCall& fn)
{
    MovieImpl* proot = fn.Env->GetMovieImpl();
    if (!proot)
        return;
    Sound::SoundRenderer* pplayer = GetSoundRenderer(proot);
    if (!pplayer)
        return;
    SoundObject* pobj    = static_cast<SoundObject*>(fn.ThisPtr);
    Sprite*      psprite = pobj->GetSprite();
    if (!psprite)
        return;
    if (fn.NArgs < 1)
    {
        fn.Env->LogScriptError("Sound.AttachSound requires one argument (file name)");
        return;
    }
    ASString url       = SoundArg(fn, 0).ToString(fn.Env);
    bool     streaming = fn.NArgs > 1 ? SoundArg(fn, 1).ToBool(fn.Env) : false;

    Ptr<LoadStates> pls = *SF_NEW LoadStates(proot->pMainMovieDef->pLoaderImpl, proot->pStateBag);
    String level0Path;
    proot->GetMainMoviePath(&level0Path);
    URLBuilder::LocationInfo loc(URLBuilder::File_Regular, String(url.ToCStr()), level0Path);
    String fileName;
    pls->BuildURL(&fileName, loc);

    Ptr<Sound::SoundSample> psample = *pplayer->CreateSampleFromFile(fileName.ToCStr(), streaming);
    if (!psample)
    {
        InvokeOnLoad(fn, pobj, false);
        return;
    }
    pobj->pResource = NULL;
    pobj->pSample   = psample;
    if (streaming)
    {
        Ptr<Sound::SoundChannel> pchan = *pplayer->PlaySample(psample, true);
        if (pchan)
        {
            pchan->SetVolume(psprite->GetRealSoundVolume());
            pchan->SetPan(psprite->GetRealSoundPan());
            pchan->Pause(false);
            psprite->AddActiveSound(pchan, pobj, pobj->pResource);
        }
    }
    InvokeOnLoad(fn, pobj, true);
    fn.Env->Drop(1);
}

// SetPan and SetVolume are built without inlining (the argument setup order follows from it).
#pragma inline_depth(0)
// @0x1429973c0
void SoundProto::SetPan(const FnCall& fn)
{
    Environment* penv = fn.Env;
    if (fn.NArgs < 1)
    {
        penv->LogScriptError("Sound.SetPan requires one argument (pan)");
        return;
    }
    int          pan  = fn.Arg(0).ToInt32(penv);
    SoundObject* pobj = static_cast<SoundObject*>(fn.ThisPtr);
    if (pobj)
    {
        Sprite* psprite = pobj->GetSprite();
        if (psprite)
            psprite->SetSoundPan(pan);
    }
}

#pragma inline_depth()

// No pdata in the exe (0x142997440, a bare ret).
void SoundProto::SetTransform(const FnCall&)
{
}

#pragma inline_depth(0)
// @0x142997450
void SoundProto::SetVolume(const FnCall& fn)
{
    Environment* penv = fn.Env;
    if (fn.NArgs < 1)
    {
        penv->LogScriptError("Sound.SetVolume requires at least one argument (volume)");
        return;
    }
    int volume    = fn.Arg(0).ToInt32(penv);
    int subVolume = 100;
    if (fn.NArgs > 1)
        subVolume = fn.Arg(1).ToInt32(fn.Env);
    SoundObject* pobj = static_cast<SoundObject*>(fn.ThisPtr);
    if (pobj)
    {
        Sprite* psprite = pobj->GetSprite();
        if (psprite)
            psprite->SetSoundVolume(volume, subVolume);
    }
}

#pragma inline_depth()

// MS2-FUNCTIONAL: other register allocation (the exe keeps zero in r12); same start call
// @0x142997500
void SoundProto::Start(const FnCall& fn)
{
    MovieImpl* proot = fn.Env->GetMovieImpl();
    if (!proot)
        return;
    Sound::SoundRenderer* pplayer = GetSoundRenderer(proot);
    if (!pplayer)
        return;
    if (!fn.ThisPtr || fn.ThisPtr->GetObjectType() != Object::Object_Sound)
        return;
    SoundObject* pobj = static_cast<SoundObject*>(fn.ThisPtr);
    if (!pobj)
        return;
    Sprite* psprite = pobj->GetSprite();
    if (!psprite)
        return;

    int offset = 0;
    int loops  = 0;
    if (fn.NArgs > 0)
        offset = SoundArg(fn, 0).ToInt32(fn.Env);
    if (fn.NArgs > 1)
        loops = SoundArg(fn, 1).ToInt32(fn.Env);
    if (loops == 0)
        loops = 1;
    if (!pobj->pResource && psprite->IsSoundPlaying(pobj))
        return;

    Ptr<Sound::SoundChannel> pchan = *pplayer->PlaySample(pobj->pSample, true);
    if (pchan)
    {
        if (offset > 0 || loops > 0)
            pchan->Loop(loops, float(offset));
        pchan->SetVolume(psprite->GetRealSoundVolume());
        pchan->SetPan(psprite->GetRealSoundPan());
        pchan->Pause(false);
        psprite->AddActiveSound(pchan, pobj, pobj->pResource);
    }
}

// MS2-FUNCTIONAL: the resource lookup kept in a helper; same stop calls
// @0x1429976e0
void SoundProto::Stop(const FnCall& fn)
{
    SoundObject* pobj = static_cast<SoundObject*>(fn.ThisPtr);
    if (!pobj)
        return;
    Sprite* psprite = pobj->GetSprite();
    if (!psprite)
        return;
    if (fn.NArgs < 1)
    {
        psprite->StopActiveSounds();
        return;
    }
    ASString          id  = SoundArg(fn, 0).ToString(fn.Env);
    Ptr<MovieDefImpl> pmd = fn.Env->GetTarget()->GetResourceMovieDef();
    if (pobj && pmd)
    {
        ResourceBindData bd;
        SoundResource*   psound = FindSoundResource(fn.Env, pmd, id, &bd);
        if (psound)
            psprite->StopActiveSounds(psound);
    }
}

// The collector traversal of Sound.prototype (the instances fold with the other Object-only prototypes).
template void Prototype<SoundObject>::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector* prcc) const;
template void Prototype<SoundObject>::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector* prcc) const;
template void Prototype<SoundObject>::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector* prcc) const;

// @0x142997bc0
SoundObject::SoundObject(Environment* penv) : Object(penv), pMovieRoot(0)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Sound));
    pMovieRoot = penv->GetMovieImpl();
}

// @0x142997c70
SoundProto::SoundProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<SoundObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x142997db0
SoundObject::~SoundObject()
{
    DetachFromTarget();
}

// @0x142998130
void SoundObject::AttachToTarget(Sprite* psprite)
{
    SetTargetHandle(pTargetHandle, psprite->GetCharacterHandle());
    psprite->AttachSoundObject(this);
}

// @0x1429981c0
Object* SoundCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) SoundObject(penv);
}

// @0x142998950
Sprite* SoundObject::GetSprite()
{
    if (!pTargetHandle || !pMovieRoot)
        return 0;
    DisplayObject* ptarget = pTargetHandle->ResolveCharacter(pMovieRoot);
    if (!ptarget)
        return 0;
    return ptarget->IsSprite() ? static_cast<Sprite*>(ptarget) : 0;
}

// @0x142998200
void SoundObject::DetachFromTarget()
{
    Sprite* psprite = GetSprite();
    if (psprite)
        psprite->DetachSoundObject(this);
}

// MS2-FUNCTIONAL: the exe calls Value::~Value out of line and inlines the FnCall dtor; same handler lookup and call
// @0x1429982b0
void SoundObject::ExecuteOnSoundComplete()
{
    Sprite* psprite = GetSprite();
    if (!psprite)
        return;
    Environment* penv = AS2::ToAvmCharacter(psprite)->GetASEnvironment();
    Value        callback;
    if (GetMemberRaw(penv->GetSC(), penv->GetSC()->pContext->GetStringManager()->CreateConstString("onSoundComplete"),
                     &callback))
    {
        FunctionRef method = callback.ToFunction_Call(penv);
        Value       result;
        method.Invoke(FnCall(&result, this, penv, 0, penv->GetTopIndex()));
    }
}

// @0x142998610
void SoundObject::Finalize_GC()
{
    DetachFromTarget();
    pSample.~Ptr<Sound::SoundSample>();
    pTargetHandle.~Ptr<CharacterHandle>();
    pResource.~Ptr<SoundResource>();
    Object::Finalize_GC();
}

// @0x142998510
template void Prototype<SoundObject>::Finalize_GC();

// position and duration in milliseconds; everything else is an ordinary member.
// MS2-FUNCTIONAL: the exe calls Value::operator= and Value::~Value out of line; same values
// @0x1429986f0
bool SoundObject::GetMember(Environment* penv, const ASString& name, Value* val)
{
    const char* pname = name.ToCStr();
    if (strcmp(pname, "position") == 0)
    {
        Sprite* psprite = GetSprite();
        if (psprite)
            *val = Value(psprite->GetActiveSoundPosition(this) * 1000.f);
        else
            *val = Value(0.0);
        return true;
    }
    if (strcmp(pname, "duration") == 0)
    {
        if (pSample)
            *val = Value(pSample->GetDuration() * 1000.f);
        else
            *val = Value(0.0);
        return true;
    }
    return Object::GetMember(penv, name, val);
}

// "constructor" and "__constructor__" are answered by the prototype part.
// @0x142998820
template<>
bool Prototype<SoundObject>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    // The builtins come through GlobalContext::GetStringManager here (not inlined into this file).
    bool isConstructor2 = psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin___constructor__)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive());
    if (isConstructor2 || psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin_constructor)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        return GetMemberRawConstructor(this, psc, name, val, isConstructor2);
    }
    return SoundObject::GetMemberRaw(psc, name, val);
}

// MS2-FUNCTIONAL: the exe inlines AttachToTarget; same target choice
// @0x1429989a0
void SoundCtorFunction::GlobalCtor(const FnCall& fn)
{
    Ptr<SoundObject> psound;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_Sound && !fn.ThisPtr->IsBuiltinPrototype())
        psound = static_cast<SoundObject*>(fn.ThisPtr);
    else
        psound = *SF_HEAP_NEW(fn.Env->GetHeap()) SoundObject(fn.Env);

    InteractiveObject* ptarget = fn.NArgs > 0 ? SoundArg(fn, 0).ToCharacter(fn.Env) : 0;
    if (!ptarget || !ptarget->IsSprite())
        ptarget = fn.Env->GetAS2Root()->GetLevelMovie(0);
    psound->AttachToTarget(ptarget->IsSprite() ? static_cast<Sprite*>(ptarget) : 0);
    fn.Result->SetAsObject(psound.GetPtr());
}

// MS2-FUNCTIONAL: the exe inlines the SoundCtorFunction and SoundProto ctors
// @0x142998b50
FunctionRef SoundCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) SoundCtorFunction(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) SoundProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_Sound, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Sound), Value(ctor));
    return ctor;
}

// @0x142998e80
void SoundObject::ReleaseTarget()
{
    pTargetHandle = NULL;
}

const NameFunction SoundProto::FunctionTable[] = {
    { "attachSound", &SoundProto::Attach },
    { "getBytesLoaded", &SoundProto::GetBytesLoaded },
    { "getBytesTotal", &SoundProto::GetBytesTotal },
    { "getPan", &SoundProto::GetPan },
    { "getTransform", &SoundProto::GetTransform },
    { "getVolume", &SoundProto::GetVolume },
    { "loadSound", &SoundProto::LoadSound },
    { "setPan", &SoundProto::SetPan },
    { "setTransform", &SoundProto::SetTransform },
    { "setVolume", &SoundProto::SetVolume },
    { "start", &SoundProto::Start },
    { "stop", &SoundProto::Stop },
    { 0, 0 }
};

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??$ForEachChild_GC@UMarkInCycleFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VSoundObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x1429978f0
// MS2-PIN: ??$ForEachChild_GC@UReleaseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VSoundObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x1429979b0
// MS2-PIN: ??$ForEachChild_GC@UScanInUseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VSoundObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x142997ac0
// MS2-PIN: ??_G?$Prototype@VSoundObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x142997f20
// MS2-PIN: ??_GSoundCtorFunction@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x142997fc0
// MS2-PIN: ??_GSoundObject@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x142998020
// MS2-PIN: ??_GSoundProto@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x142998080
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7ASSoundIntf@GFx@Scaleform@@6B@ 0x143182f18
// MS2-PIN: ??_7SoundObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143222bf0
// MS2-PIN: ??_7SoundObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143222c38
// MS2-PIN: ??_7SoundObject@AS2@GFx@Scaleform@@6B@ 0x143222ce0
// MS2-PIN: ??_7?$Prototype@VSoundObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143222d10
// MS2-PIN: ??_7?$Prototype@VSoundObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143222d58
// MS2-PIN: ??_7?$Prototype@VSoundObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BSoundObject@123@@ 0x143222e00
// MS2-PIN: ??_7?$Prototype@VSoundObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BGASPrototypeBase@123@@ 0x143222e30
// MS2-PIN: ??_7SoundProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143222e38
// MS2-PIN: ??_7SoundProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143222e80
// MS2-PIN: ??_7SoundProto@AS2@GFx@Scaleform@@6BSoundObject@123@@ 0x143222f28
// MS2-PIN: ??_7SoundProto@AS2@GFx@Scaleform@@6BGASPrototypeBase@123@@ 0x143222f58
// MS2-PIN: ??_7SoundCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143222f60
// MS2-PIN: ??_7SoundCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143222fe8
