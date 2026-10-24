// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// System.capabilities, the members computed on the fly (screen size, IME, sound) and the server string.
// MS2-UNIT: sfr_as2_05r
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142947ba0-0x142948211 .text$mn
// MS2-RANGE: 0x14294de70-0x14294e51a .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_player.h"
#include "../include/gfx/gfx_movieimplstates.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/kernel/sf_string.h"
#include "../include/render/render_viewport.h"
#include "../include/sound/sound_renderer.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The class of sfr_as2_03h, repeated for its GetMember.
class CapabilitiesCtorFunction : public CFunctionObject
{
public:
    CapabilitiesCtorFunction(ASStringContext* psc);
    virtual ~CapabilitiesCtorFunction() {}
    virtual Object* CreateNewObject(Environment*) const { return 0; }
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);
    virtual bool SetMemberRaw(ASStringContext*, const ASString&, const Value&, const PropFlags&) { return false; }
};

namespace {

// The sound renderer of the movie, if it has one.
inline Sound::SoundRenderer* GetSoundRenderer(MovieImpl* pmovie)
{
    Ptr<AudioBase> paudio = *(AudioBase*)pmovie->GetStateBag()->GetStateAddRef(State::State_Audio);
    return paudio ? paudio->GetRenderer() : 0;
}

// The Movie interface of the movie: MovieImpl is the layout mirror here (as2_movieroot.h needs it), the movie
// virtuals sit at the start of the object.
inline Movie* AsMovie(MovieImpl* pmovie)
{
    return reinterpret_cast<Movie*>(pmovie);
}

} // namespace

// "A=t&MP3=t&SA=t&...": the capabilities as the query string of System.capabilities.serverString.
// MS2-FUNCTIONAL: the movie is found through the target (inlined GetMovieImpl in the exe)
// @0x142947ba0
ASString GFxCapabilities_ServerString(Environment* penv)
{
    ASStringContext* psc = penv->GetSC();
    StringBuffer     temp;
    Sound::SoundRenderer* psoundrenderer = GetSoundRenderer(penv->GetMovieImpl());
    UInt32 capBits = 0;
    if (psoundrenderer)
        psoundrenderer->GetRenderCaps(&capBits);
    temp.AppendString("A=t");
    temp.AppendString((psoundrenderer && !(capBits & Sound::SoundRenderer::Cap_NoMP3)) ? "&MP3=t" : "&MP3=f");
    temp.AppendString((psoundrenderer && !(capBits & Sound::SoundRenderer::Cap_NoStreaming)) ? "&SA=t" : "&SA=f");
    temp.AppendString("&SV=f");
    temp.AppendString("&EV=f");
    temp.AppendString("&IME=");
    {
        Ptr<IMEManagerBase> pimeManager = penv->GetMovieImpl()->GetIMEManager();
        temp.AppendString(pimeManager ? "t" : "f");
    }
    temp.AppendString("&AE=f");
    temp.AppendString("&VE=f");
    temp.AppendString("&ACC=f");
    temp.AppendString("&PR=f");
    temp.AppendString("&SP=f");
    temp.AppendString("&SB=f");
    temp.AppendString("&DEB=f");

    temp.AppendString("&V=");
    String etemp;
    String vtemp(psc->CreateConstString("WIN 8,0,0,0").ToCStr());
    ASUtils::Escape(vtemp.ToCStr(), vtemp.GetSize(), &etemp);
    temp.AppendString(etemp.ToCStr(), etemp.GetSize());

    temp.AppendString("&M=");
    etemp.Clear();
    String mtemp(psc->CreateConstString("Scaleform Windows").ToCStr());
    ASUtils::Escape(mtemp.ToCStr(), mtemp.GetSize(), &etemp);
    temp.AppendString(etemp.ToCStr(), etemp.GetSize());

    Viewport vp;
    AsMovie(penv->GetMovieImpl())->GetViewport(&vp);
    temp.AppendString("&R=");
    temp.AppendString(Value(vp.BufferWidth).ToString(penv).ToCStr());
    temp.AppendString("x");
    temp.AppendString(Value(vp.BufferHeight).ToString(penv).ToCStr());

    temp.AppendString("&DP=72");
    temp.AppendString("&COL=color");
    temp.AppendString("&AR=1.0");

    temp.AppendString("&OS=");
    etemp.Clear();
    String ostemp(psc->CreateConstString("Windows").ToCStr());
    ASUtils::Escape(ostemp.ToCStr(), ostemp.GetSize(), &etemp);
    temp.AppendString(etemp.ToCStr(), etemp.GetSize());

    temp.AppendString("&L=en");
    temp.AppendString("&PT=External");
    temp.AppendString("&AVD=f");
    temp.AppendString("&LFD=f");
    temp.AppendString("&WD=f");
    return penv->CreateString(temp.ToCStr(), temp.GetSize());
}

namespace {

// name against a constant in the case mode of the movie.
inline bool NameIs(Environment* penv, const ASString& name, const char* pconst)
{
    if (penv->IsCaseSensitive())
        return strcmp(name.ToCStr(), pconst) == 0;
    ASString c = penv->CreateConstString(pconst);
    c.ResolveLowercase();
    return c.CompareBuiltIn_CaseCheck(name, false);
}

} // namespace

// screenResolutionX/Y, hasIME and the sound members are looked up each time; numControllers is a GFx extension.
// MS2-FUNCTIONAL: the exe keeps the two case modes as separate chains (strcmp / lowercase nodes) and inlines
// GetMovieImpl and Object::GetMember
// @0x14294de70
bool CapabilitiesCtorFunction::GetMember(Environment* penv, const ASString& name, Value* val)
{
    Sound::SoundRenderer* psoundrenderer = GetSoundRenderer(penv->GetMovieImpl());
    UInt32 capBits = 0;
    if (psoundrenderer)
        psoundrenderer->GetRenderCaps(&capBits);

    if (NameIs(penv, name, "screenResolutionX"))
    {
        Viewport vp;
        AsMovie(penv->GetMovieImpl())->GetViewport(&vp);
        *val = Value(vp.BufferWidth);
        return true;
    }
    if (NameIs(penv, name, "screenResolutionY"))
    {
        Viewport vp;
        AsMovie(penv->GetMovieImpl())->GetViewport(&vp);
        *val = Value(vp.BufferHeight);
        return true;
    }
    if (NameIs(penv, name, "hasIME"))
    {
        Ptr<IMEManagerBase> pimeManager = penv->GetMovieImpl()->GetIMEManager();
        *val = Value(pimeManager != 0);
        return true;
    }
    if (NameIs(penv, name, "hasAudio"))
    {
        *val = Value(psoundrenderer != 0);
        return true;
    }
    if (NameIs(penv, name, "hasMP3"))
    {
        *val = Value(psoundrenderer && !(capBits & Sound::SoundRenderer::Cap_NoMP3));
        return true;
    }
    if (NameIs(penv, name, "hasStreamingAudio"))
    {
        *val = Value(psoundrenderer && !(capBits & Sound::SoundRenderer::Cap_NoStreaming));
        return true;
    }
    if (NameIs(penv, name, "serverString"))
    {
        *val = Value(GFxCapabilities_ServerString(penv));
        return true;
    }
    if (penv->CheckExtensions() && strcmp(name.ToCStr(), "numControllers") == 0)
    {
        *val = Value(int(AsMovie(penv->GetMovieImpl())->GetControllerCount()));
        return true;
    }
    return GetMemberRaw(penv->GetSC(), name, val);
}

}}} // namespace Scaleform::GFx::AS2
