// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 local frame creation and Array
// literals (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142936680-0x14293678d .text$mn
// MS2-RANGE: 0x142938020-0x14293817c .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The vftable of LocalFrame (its members are recovered elsewhere).
extern const void* DAT_143215a98[];

// A fresh activation frame, pushed on the environment's frame stack. The frame is built by raw words (the class has
// no constructor in this recovery).
// MS2-FUNCTIONAL: raw words
// @0x142936680
LocalFrame* Environment::CreateNewLocalFrame()
{
    UPInt* pw = static_cast<UPInt*>(StringContext.pContext->pHeap->Alloc(0x88, static_cast<const AllocInfo*>(0)));
    LocalFrame*     pf = 0;
    if (pw)
    {
        void* pheapOwner = 0;
        if (Target)
            pheapOwner = ToAvmCharacter(Target)->GetAS2Root()->GetASGC();
        pw[1]                                    = reinterpret_cast<UPInt>(pheapOwner);
        pw[0]                                    = reinterpret_cast<UPInt>(DAT_143215a98);
        reinterpret_cast<unsigned*>(pw)[6]       = 1;
        pw[4] = pw[5] = pw[6] = pw[7] = pw[8] = 0;
        reinterpret_cast<UByte*>(pw)[0x48]       = 0;
        reinterpret_cast<UByte*>(pw)[0x68]       = 0;
        pf                                       = reinterpret_cast<LocalFrame*>(pw);
    }
    LocalFrames.Resize(LocalFrames.GetSize() + 1);
    LocalFrames[LocalFrames.GetSize() - 1] = pf;
    pf->Release();
    return pf;
}

// The Array literal: a new empty array with its length and constructor, filled from the arguments.
// MS2-FUNCTIONAL: GlobalCtor's twin
// @0x142938020
void ArrayCtorFunction::DeclareArray(const FnCall& fn)
{
    Ptr<ArrayObject> parray = *SF_HEAP_NEW(fn.Env->GetHeap()) ArrayObject(fn.Env);
    parray->SetMember(fn.Env, fn.Env->GetBuiltin(ASBuiltin_length), Value(0), PropFlags::PropFlag_DontEnum);
    parray->Set_constructor(fn.Env->GetSC(), fn.Env->GetConstructor(ASBuiltin_Array));
    if (fn.NArgs != 0)
        parray->InitArray(fn);
    fn.Result->SetAsObject(parray.GetPtr());
}

}}} // namespace Scaleform::GFx::AS2
