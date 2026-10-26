// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 NameFunction helpers (gap recovery
// of sfr_as2_04).
// MS2-UNIT: sfr_as2_04f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14292e6e0-0x14292e87f .text$mn
// MS2-RANGE: 0x14292e050-0x14292e11f .text$mn
// MS2-RANGE: 0x1429306a0-0x14293090c .text$mn
// MS2-RANGE: 0x142931870-0x1429318cf .text$mn
// MS2-RANGE: 0x1424ed840-0x1424ed886 .text$mn
// MS2-RANGE: 0x14292cfc0-0x14292d03f .text$mn
// MS2-RANGE: 0x14292f430-0x14292f5a2 .text$mn

namespace Scaleform { class Range; } // gfx_textfield.h (WIP header) names Range before declaring it
#define MS2_AS2_TEXTSNAPSHOT_CTOR_INLINE // MovieClip.getTextSnapshot inlines the TextSnapshotObject ctor
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_actiontypes.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_stickyvarnode.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x14292e6e0
// MS2-FUNCTIONAL: heap new/ctor inlined through the CFunctionObject constructor; register scheduling differs
void NameFunction::AddConstMembers(ObjectInterface* pobj, ASStringContext* psc, const NameFunction* pfunctions,
                                   UByte flags)
{
    Object* pfuncProto = psc->pContext->GetPrototype(ASBuiltin_Function);
    for (; pfunctions->Name; ++pfunctions)
    {
        Ptr<CFunctionObject> pfunc = *SF_HEAP_NEW(psc->GetHeap()) CFunctionObject(psc, pfuncProto, pfunctions->Function);
        pobj->SetMemberRaw(psc, psc->CreateConstString(pfunctions->Name), Value(pfunc.GetPtr()), PropFlags(flags));
    }
}

// @0x14292e050
// MS2-FUNCTIONAL: the prototype walk is recovered from MovieClipObject::ActsAsButton's loop shape
bool AvmSprite::ActsAsButton() const
{
    if (!static_cast<const AvmSpriteBase*>(this)->IsLevelMovie() && (pDispObj->Flags & InteractiveObject::Mask_Enabled))
    {
        Object* pclipObj = pMovieClipObj.GetPtr();
        Object* pobj     = pclipObj ? pclipObj : Get__proto__();
        if (pobj)
        {
            MovieClipObject* pmc = static_cast<MovieClipObject*>(pobj);
            if (pmc->ButtonEventMask != 0 || pmc->HasButtonHandlers)
                return true;
            for (Object* pproto = pobj->Get__proto__(); pproto != 0; pproto = pproto->Get__proto__())
            {
                if (pobj->Get__proto__()->GetObjectType() == ObjectInterface::Object_MovieClipObject)
                    return static_cast<MovieClipObject*>(pproto)->ActsAsButton();
            }
        }
    }
    return false;
}

// @0x142931870
void MovieRoot::StickyVarNode::Assign(const GFx::MovieImpl::StickyVarNode& node)
{
    GFx::MovieImpl::StickyVarNode::Assign(node);
    mValue = static_cast<const StickyVarNode&>(node).mValue;
}

// MS2-FUNCTIONAL: the string handling is recovered from the decompile; the builtins 66 and 67 are "_level0" and "_level0."
// @0x1429306a0
void MovieRoot::AddStickyVariable(const ASString& path, const Value& val, SetVarTypeArg setType)
{
    ASStringContext sc(pGlobalContext, 8);
    ASString        base(sc.GetBuiltin(ASBuiltin_empty_));
    ASString        name(sc.GetBuiltin(ASBuiltin_empty_));
    ASString        key(sc.GetBuiltin(ASBuiltin_empty_));
    if (Environment::ParsePath(&sc, path, &base, &name))
    {
        if (base.GetLength() > 4)
        {
            if (!strncmp(base.ToCStr(), "_root", 5))
                base = sc.GetBuiltin(66) + ASString(base.SubstringNode(5, base.GetLength()));
            if (!strncmp(base.ToCStr(), "_level", 6))
            {
                key = base;
                goto create;
            }
        }
        key = sc.GetBuiltin(67) + base;
    }
    else
    {
        if (name.GetLength() == 0)
            return;
        key = sc.GetBuiltin(66);
    }
create:
    StickyVarNode* pnode = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) StickyVarNode(name, val, (int)setType == 2);
    pMovieImpl->AddStickyVariableNode(key, pnode);
}

// The ExternalInterface callbacks of a movie (ASStringHash<InvokeAliasInfo>), the pointer at +0x78.
typedef HashNode<ASString, MovieRoot::InvokeAliasInfo, ASStringHashFunctor> MS2_AS2InvokeAliasNode;
typedef HashLH<ASString, MovieRoot::InvokeAliasInfo, ASStringHashFunctor, StatMV_ASString_Mem, MS2_AS2InvokeAliasNode,
               HashsetNodeEntry<MS2_AS2InvokeAliasNode, MS2_AS2InvokeAliasNode::NodeHashF> >
    MS2_AS2InvokeAliasHash;

// MS2-FUNCTIONAL: the hash set is inlined through Hash::set; register scheduling differs
// @0x14292f430
void MovieRoot::AddInvokeAlias(const ASString& alias, CharacterHandle* pthisChar, Object* pthisObj, const FunctionRef& func)
{
    MS2_AS2InvokeAliasHash*& paliases = *reinterpret_cast<MS2_AS2InvokeAliasHash**>(Unrecovered_78);
    if (!paliases)
        paliases = SF_NEW MS2_AS2InvokeAliasHash;
    InvokeAliasInfo info;
    info.ThisObject = pthisObj;
    info.ThisChar   = pthisChar;
    info.Function   = func;
    paliases->Set(alias, info);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7StickyVarNode@MovieRoot@AS2@GFx@Scaleform@@6B@ 0x1432177c8
// MS2-PIN: ??_7StickyVarNode@MovieImpl@GFx@Scaleform@@6B@ 0x14317ca50
