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

// The exe inlines the CFunctionObject ctor, and its FunctionObject base ctor, here.
inline FunctionObject::FunctionObject(ASStringContext* psc, ObjectInlineCtorTag)
    : Object(psc)
{
}

inline CFunctionObject::CFunctionObject(ASStringContext* psc, Object* pprototype, CFunctionPtr func, ObjectInlineCtorTag)
    : FunctionObject(psc, ObjectInlineCtorTag()), pFunction(func)
{
    Set__proto__(psc, pprototype);
}

// @0x14292e6e0
void NameFunction::AddConstMembers(ObjectInterface* pobj, ASStringContext* psc, const NameFunction* pfunctions,
                                   UByte flags)
{
    MemoryHeap* pheap      = psc->GetHeap();
    Object*     pfuncProto = psc->pContext->GetPrototype(ASBuiltin_Function);
    while (pfunctions->Name)
    {
        PropFlags pf(flags);
        pobj->SetMemberRaw(psc, psc->CreateConstString(pfunctions->Name),
                           FunctionRef(*SF_HEAP_NEW(pheap)
                                           CFunctionObject(psc, pfuncProto, pfunctions->Function, ObjectInlineCtorTag())),
                           pf);
        pfunctions++;
    }
}

// @0x14292e050
// The prototype walk is recovered from MovieClipObject::ActsAsButton's loop shape.
bool AvmSprite::ActsAsButton() const
{
    if (!static_cast<const AvmSpriteBase&>(*this).IsLevelMovie() && pDispObj->IsEnabledFlagSet())
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

// The exe keeps the global context in a register across ParsePath and reads the builtins through it.
static inline const ASString& MS2_GcBuiltin(GlobalContext* pgc, int btype)
{
    return ((MovieRoot*)pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(btype);
}

// The builtins 66 and 67 are "_level0" and "_level0."
// MS2-FUNCTIONAL: the exe saves rsi only around the _root rewrite and puts the string context below the path;
// register choice and frame slots differ
// @0x1429306a0
void MovieRoot::AddStickyVariable(const ASString& fullPath, const Value& val, SetVarTypeArg setType)
{
    GlobalContext*  pgc = pGlobalContext;
    ASString        path(MS2_GcBuiltin(pgc, ASBuiltin_empty_));
    ASString        name(MS2_GcBuiltin(pgc, ASBuiltin_empty_));
    ASStringContext sc(pgc, 8);
    if (!Environment::ParsePath(&sc, fullPath, &path, &name))
    {
        if (name.IsEmpty())
            return;
        // a sticky variable without a path is taken as _level0
        path = MS2_GcBuiltin(pgc, ASBuiltin__level0);
    }
    else
    {
        bool needLevelPrefix = 0;
        if (path.GetSize() >= 5)
        {
            if (!memcmp(path.ToCStr(), "_root", 5))
                path = MS2_GcBuiltin(pgc, ASBuiltin__level0) + ASString(path.SubstringNode(5, path.GetLength()));
            if (memcmp(path.ToCStr(), "_level", 6) != 0)
                needLevelPrefix = 1;
        }
        else
            needLevelPrefix = 1;
        if (needLevelPrefix)
            path = MS2_GcBuiltin(pgc, ASBuiltin__level0dot_) + path;
    }
    StickyVarNode* pnode;
    if ((pnode = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) StickyVarNode(name, val, (int)setType == 2)) != 0)
        pMovieImpl->AddStickyVariableNode(path, pnode);
}

// The ExternalInterface callbacks of a movie (ASStringHash<InvokeAliasInfo>), the pointer at +0x78.
typedef HashNode<ASString, MovieRoot::InvokeAliasInfo, ASStringHashFunctor> MS2_AS2InvokeAliasNode;
typedef HashLH<ASString, MovieRoot::InvokeAliasInfo, ASStringHashFunctor, StatMV_ASString_Mem, MS2_AS2InvokeAliasNode,
               HashsetNodeEntry<MS2_AS2InvokeAliasNode, MS2_AS2InvokeAliasNode::NodeHashF> >
    MS2_AS2InvokeAliasHash;

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
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
