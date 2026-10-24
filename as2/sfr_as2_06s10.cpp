// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 MovieRoot::RegisterAuxASClasses
// of sfr_as2_06 (gap recovery, lane sfr24): XML and XMLNode are registered for first use, then the Sound and Video
// states add their classes.
// MS2-UNIT: sfr_as2_06s10
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297c6e0-0x14297c965 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_xml.h"
#include "../include/gfx/as2/as2_xmlnode.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/video/video_video.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The folded ASStringHash<ClassRegEntry>::Get (exe 0x140001bd0).
GlobalContext::ClassRegEntry* FUN_140001bd0(ASStringHash<GlobalContext::ClassRegEntry>* phash, const ASString& key);

namespace {

// A builtin class created on first use: its registration function under the type's name, and the name published
// in pdest as a function name value until then.
SF_FORCEINLINE void AddBuiltinClassRegistry(GlobalContext* pgc, ASStringContext* psc, Object* pdest,
                                            ASBuiltinType type, GlobalContext::ClassRegEntry::RegisterFunc func)
{
    const ASString& name = psc->GetBuiltin(type);
    if (FUN_140001bd0(&pgc->BuiltinClassesRegistry, name))
        return;
    {
        GlobalContext::ClassRegEntry entry;
        entry.Register = func;
        pgc->BuiltinClassesRegistry.Add(name, entry);
    }

    Value fname;
    fname.T.Type        = Value::FUNCTIONNAME;
    fname.V.pStringNode = psc->GetBuiltin(type).GetNode();
    fname.V.pStringNode->AddRef();
    pdest->SetMemberRaw(psc, name, fname);
}

} // namespace

// MS2-FUNCTIONAL: the movie's states are read through its own state bag; the video glue takes the string context
// under the GFx-level name its header declares.
// @0x14297c6e0
void MovieRoot::RegisterAuxASClasses()
{
    ASStringContext sc(pGlobalContext, 8);
    AddBuiltinClassRegistry(pGlobalContext, &sc, pGlobalContext->pGlobal, ASBuiltin_XML, XmlCtorFunction::Register);
    AddBuiltinClassRegistry(pGlobalContext, &sc, pGlobalContext->pGlobal, ASBuiltin_XMLNode,
                            XmlNodeCtorFunction::Register);

    Ptr<AudioBase> paudio = *(AudioBase*)pMovieImpl->pStateBag->GetStateAddRef(State::State_Audio);
    if (paudio)
        paudio->RegisterASClasses(*pGlobalContext, sc);
    Ptr<Video::VideoBase> pvideo = *(Video::VideoBase*)pMovieImpl->pStateBag->GetStateAddRef(State::State_Video);
    if (pvideo && pvideo->GetAS2Support())
        pvideo->GetAS2Support()->RegisterASClasses(*pGlobalContext, reinterpret_cast<GFx::ASStringContext&>(sc));
}

}}} // namespace Scaleform::GFx::AS2
