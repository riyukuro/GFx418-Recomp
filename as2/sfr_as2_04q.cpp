// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 host value interface: attachMovie
// (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04q
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429318d0-0x142931db8 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_value.h"

namespace Scaleform { namespace GFx {

// The initial members of attachMovie: a name and a value each (0x28 bytes), counted by the second word.
class MemberValueSet
{
public:
    struct Member
    {
        String Name;
        Value  Val;
    };
    Member* pMembers;
    UPInt   Count;
};
static_assert(sizeof(MemberValueSet::Member) == 0x28, "attachMovie member size");

// The host side of AS2 values; only the members recovered in this unit.
class AS2ValueObjectInterface : public Value::ObjectInterface
{
private:
    virtual bool AttachMovie(void* pdata, Value* pmc, const char* symbolName, const char* instanceName, SInt32 depth,
                             const MemberValueSet* initArgs);
};

// Attaches the exported movie clip symbol to the clip in pdata at depth (a free one above the used ones when negative),
// with the initial members in an object, and hands the new clip back in *pmc (for AS2 movies above version 5).
// MS2-FUNCTIONAL: same code; the exe puts the bind data and the instance name spill in other stack slots and allocates registers differently
// @0x1429318d0
bool AS2ValueObjectInterface::AttachMovie(void* pdata, Value* pmc, const char* symbolName, const char* instanceName,
                                          SInt32 depth, const MemberValueSet* initArgs)
{
    DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pdobj || !((UByte)(*reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pdobj) + 0x6a) >> 10) & 1))
        return false;
    AS2::MovieRoot*    proot = static_cast<AS2::MovieRoot*>(pMovieRoot->pASMovieRoot);
    AvmDisplayObjBase* pmain = proot->pMovieImpl->pMainMovie->GetAvmObjImpl();
    AS2::Environment*  penv  =
        static_cast<AS2::AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmain))->GetASEnvironment();

    ResourceBindData bind;
    bool             missing;
    {
        String symbol(symbolName);
        missing = !pdobj->GetMovieImpl()->FindExportedResource(pdobj->GetResourceMovieDef(), &bind, symbol);
    }
    if (missing)
    {
        pdobj->LogScriptWarning("%s.attachMovie() failed - export name \"%s\" is not found.",
                                pdobj->GetCharacterHandle()->NamePath.ToCStr(), symbolName);
        return false;
    }
    if (!(bind.pResource->GetResourceTypeCode() & (Resource::RT_CharacterDef_Bit << Resource::RT_TypeCode_Shift)))
    {
        pdobj->LogScriptWarning("%s.attachMovie() failed - \"%s\" is not a movieclip.",
                                pdobj->GetCharacterHandle()->NamePath.ToCStr(), symbolName);
        return false;
    }

    CharacterCreateInfo ccinfo;
    ccinfo.pResource    = 0;
    ccinfo.pCharDef     = reinterpret_cast<CharacterDef*>(bind.pResource.GetPtr());
    ccinfo.pBindDefImpl = *reinterpret_cast<MovieDefImpl**>(reinterpret_cast<UByte*>(bind.pBinding) + 0x48);
    if (depth < 0)
    {
        depth = static_cast<Sprite*>(pdobj)->mDisplayList.GetLargestDepthInUse() - 16383;
        if (depth < 0)
            depth = 0;
    }
    ResourceId rid(*reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(bind.pResource.GetPtr()) + 0x18));
    CharPosInfo pos(rid, depth + 16384, 1, Render::Cxform::Identity, 1, Render::Matrix2F::Identity);
    if (pos.Depth < 0 || pos.Depth > 0x7efffffd)
    {
        pdobj->LogScriptWarning("%s.attachMovie(\"%s\") failed - depth (%d) must be >= 0",
                                pdobj->GetCharacterHandle()->NamePath.ToCStr(), symbolName, pos.Depth);
        return false;
    }

    Ptr<AS2::Object> pinit;
    if (initArgs)
    {
        pinit = *penv->OperatorNew(penv->GetBuiltin(AS2::ASBuiltin_Object));
        for (unsigned i = 0; i < initArgs->Count; ++i)
        {
            const MemberValueSet::Member& member = initArgs->pMembers[i];
            ASString     name = penv->CreateString(member.Name);
            AS2::Value    val;
            proot->Value2ASValue(member.Val, &val);
            pinit->SetMember(penv, name, val);
        }
    }
    Ptr<DisplayObjectBase> newch = static_cast<Sprite*>(pdobj)->AddDisplayObject(
        pos, penv->CreateString(instanceName), 0, static_cast<AS2::ObjectInterface*>(pinit.GetPtr()), ~0u,
        1, &ccinfo, 0);
    if (newch)
    {
        newch->SetAcceptAnimMoves(false);
        if (pdobj->GetVersion() > 5)
        {
            AS2::Value val(static_cast<InteractiveObject*>(newch.GetPtr()));
            proot->ASValue2GFxValue(penv, val, pmc);
        }
    }
    return true;
}

}} // namespace Scaleform::GFx
