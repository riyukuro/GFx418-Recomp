// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// the name resolvers of the AS2 runtime: frame labels, lazily registered builtin classes, ExternalInterface
// aliases, and the SetVariable values waiting for their target clip.
// MS2-UNIT: sfr_as2_07g
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297e870-0x14297f278 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_stickyvarnode.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The exe's out-of-line Hash::Get of the builtin class registry (folded with other tables of 0x10-byte values).
GlobalContext::ClassRegEntry* FUN_140001bd0(ASStringHash<GlobalContext::ClassRegEntry>* phash, const ASString& key);

namespace {

// The ExternalInterface callbacks of a movie (ASStringHash<InvokeAliasInfo>), the pointer at MovieRoot+0x78.
typedef HashNode<ASString, MovieRoot::InvokeAliasInfo, ASStringHashFunctor> InvokeAliasNode;
typedef HashLH<ASString, MovieRoot::InvokeAliasInfo, ASStringHashFunctor, StatMV_ASString_Mem, InvokeAliasNode,
               HashsetNodeEntry<InvokeAliasNode, InvokeAliasNode::NodeHashF> >
    InvokeAliasHash;

// MovieImpl's sticky variables: the path of a clip to the chain of values set on it before it existed.
typedef ASStringHash<GFx::MovieImpl::StickyVarNode*> StickyVarHash;

SF_FORCEINLINE StickyVarHash& StickyVariablesOf(MovieImpl* pmovie)
{
    return *reinterpret_cast<StickyVarHash*>(&pmovie->StickyVariables);
}

// MovieRoot::GetLevelMovie, which ResolveInvokeAlias has inline.
SF_FORCEINLINE InteractiveObject* LevelMovieOf(const MovieImpl* pmovie, int level)
{
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
    {
        if (pmovie->pMovieLevels[i].Level == level)
            return pmovie->pMovieLevels[i].pSprite;
    }
    return 0;
}

// GlobalContext::GetBuiltinClassRegistrar as the exe has it inline (the name copied, the folded Hash::Get).
SF_FORCEINLINE GlobalContext::ClassRegEntry* BuiltinRegistrarOf(GlobalContext* pgc, ASString className)
{
    GlobalContext::ClassRegEntry* pentry = FUN_140001bd0(&pgc->BuiltinClassesRegistry, className);
    if (pentry)
        return pentry;
    return 0;
}

} // namespace

// The frame a goto value names: a number counts from 1, a string is a label, "path:label" looked up in the clip
// the path names; the clip the label belongs to goes to *pchar.
// MS2-FUNCTIONAL: register allocation and string-loop layout differ; same behavior
// @0x14297e870
bool ActionBuffer::ResolveFrameNumber(Environment* env, const Value& frameValue, InteractiveObject** pchar,
                                      unsigned* frameNumber)
{
    InteractiveObject* target = env->GetTarget();
    bool               success;

    if (frameValue.GetType() == Value::STRING)
    {
        ASString str = frameValue.ToString(env);
        int      len = (int)str.GetLength();
        for (int i = 0; i < len; i++)
        {
            if (str.GetCharAt(i) == ':')
            {
                ASString targetStr(str.SubstringNode(0, i));
                target = env->FindTarget(targetStr);
                if (target)
                {
                    if (i < len)
                    {
                        str = ASString(str.SubstringNode(i + 1, len + 1));
                        break;
                    }
                    target = 0;
                }
            }
        }
        success = false;
        if (target && target->GetLabeledFrame(str.ToCStr(), frameNumber))
            success = true;
        if (!success)
            return false;
    }
    else
    {
        if (!frameValue.IsNumber())
            return false;
        success      = true;
        *frameNumber = (int)(frameValue.ToNumber(env) - 1);
    }
    if (pchar)
        *pchar = target;
    return success;
}

// The constructor of a builtin class, created by its registration function the first time the name is used.
// MS2-FUNCTIONAL: FunctionRef copy and key refcount scheduling differ; same behavior
// @0x14297ea30
FunctionObject* GlobalContext::ResolveFunctionName(const ASString& functionName)
{
    ClassRegEntry* pentry = BuiltinRegistrarOf(this, functionName);
    if (!pentry)
        return 0;
    if (!pentry->ResolvedFunc)
    {
        FunctionRef ctor(static_cast<const FunctionRefBase&>(pentry->Register(this)));
        // the registration may have grown the table
        pentry               = BuiltinRegistrarOf(this, functionName);
        pentry->ResolvedFunc = ctor.Function;
    }
    return pentry->ResolvedFunc;
}

// A function-name value: the builtin class constructor it names.
// @0x14297ec30
FunctionRef Value::ResolveFunctionName(const Environment* penv) const
{
    if (penv && GetType() == FUNCTIONNAME)
    {
        ASString functionName = penv->GetBuiltin(ASBuiltin_empty_);
        functionName.AssignNode(V.pStringNode);
        Ptr<FunctionObject> pfunc = penv->StringContext.pContext->ResolveFunctionName(functionName);
        return FunctionRef(pfunc);
    }
    return FunctionRef();
}

// The ExternalInterface callback registered under the name, 0 if none (or no _level0 to make the name in).
// @0x14297ed30
MovieRoot::InvokeAliasInfo* MovieRoot::ResolveInvokeAlias(const char* pstr) const
{
    InvokeAliasHash* const& paliases = *reinterpret_cast<InvokeAliasHash* const*>(Unrecovered_78);
    if (paliases)
    {
        if (!LevelMovieOf(pMovieImpl, 0))
            return 0;
        // AvmCharacter sits at the start of the AVM object.
        Environment* penv = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(
                                LevelMovieOf(pMovieImpl, 0)->GetAvmObjImpl()))->GetASEnvironment();
        return paliases->Get(penv->CreateString(pstr));
    }
    return 0;
}

// Sets the waiting values of the new character's path on it; the permanent ones stay for the next character of
// that path, the rest are dropped.
// MS2-FUNCTIONAL: list relink and hash update codegen differ; same behavior
// @0x14297eec0
void MovieRoot::ResolveStickyVariables(InteractiveObject* pcharacter)
{
    const ASString& path  = pcharacter->GetCharacterHandle()->NamePath;
    AvmCharacter*   pavm  = ToAvmCharacter(pcharacter);
    StickyVarHash&  vars  = StickyVariablesOf(pMovieImpl);
    GFx::MovieImpl::StickyVarNode** ppnode = vars.Get(path);
    if (!ppnode)
        return;

    StickyVarNode* pnode     = static_cast<StickyVarNode*>(*ppnode);
    StickyVarNode* pfirst    = 0;
    StickyVarNode* plast     = 0;
    StickyVarNode* poldfirst = pnode;
    while (pnode)
    {
        pavm->SetMember(pavm->GetASEnvironment(), pnode->Name, pnode->mValue, PropFlags());
        StickyVarNode* pnext = static_cast<StickyVarNode*>(pnode->pNext);
        if (!pnode->Permanent)
            delete pnode;
        else
        {
            // keep it, in order
            if (!pfirst)
            {
                pnode->pNext = 0;
                pfirst = plast = pnode;
            }
            else
            {
                plast->pNext = pnode;
                pnode->pNext = 0;
                plast        = pnode;
            }
        }
        pnode = pnext;
    }

    if (pfirst)
    {
        if (pfirst != poldfirst)
            StickyVariablesOf(pMovieImpl).Set(path, pfirst);
    }
    else
        StickyVariablesOf(pMovieImpl).Remove(path);
}

}}} // namespace Scaleform::GFx::AS2
