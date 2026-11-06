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
}}} // namespace Scaleform::GFx::AS2
// ASStringHash<GlobalContext::ClassRegEntry>::Get, defined with plain pointer parameters in sfr_video_04.
void* FUN_140001bd0(void* phash, void* pkey);
namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// A builtin class created on first use: its registration function under the type's name, and the name published
// in pdest as a function name value until then.
// GlobalContext::GetBuiltin: the builtin name from the string manager of the movie's AS2 root.
SF_FORCEINLINE const ASString& GcBuiltin(GlobalContext* pgc, ASBuiltinType type)
{
    return ((MovieRoot*)pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(type);
}

SF_FORCEINLINE void AddBuiltinClassRegistry(GlobalContext* pgc, ASStringContext* psc, Object* pdest,
                                            ASBuiltinType type, GlobalContext::ClassRegEntry::RegisterFunc func)
{
    const ASString& name = GcBuiltin(pgc, type);
    if (::FUN_140001bd0(&pgc->BuiltinClassesRegistry, (void*)&name) == NULL)
    {
        {
            GlobalContext::ClassRegEntry entry;
            entry.Register = func;
            pgc->BuiltinClassesRegistry.Add(name, entry);
        }
        {
            Value fname;
            fname.T.Type        = Value::FUNCTIONNAME;
            fname.V.pStringNode = GcBuiltin(pgc, type).GetNode();
            fname.V.pStringNode->AddRef();
            pdest->SetMemberRaw(psc, GcBuiltin(pgc, type), fname);
        }
    }
}

} // namespace

// MS2-FUNCTIONAL: register allocation only: the exe keeps the global context in rbx and the builtin name in rdi
// (ours swaps them), and stores the class entry's null ResolvedFunc as an immediate where ours reuses the zero
// Get result.
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
