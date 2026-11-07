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

namespace Scaleform {
// The frame push grows the array out of line (0x14297e450, sfr_as2_06).
template<> void ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                              ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);
}

namespace Scaleform { namespace GFx { namespace AS2 {

// The vftable of LocalFrame (its members are recovered elsewhere).
extern const void* DAT_143215a98[];

// The inlined LocalFrame constructor, written as raw words (the class has no constructor in this recovery).
static inline LocalFrame* MS2_InitLocalFrame(UPInt* pw, void* pheapOwner)
{
    pw[1]                              = reinterpret_cast<UPInt>(pheapOwner);
    pw[0]                              = reinterpret_cast<UPInt>(DAT_143215a98);
    reinterpret_cast<unsigned*>(pw)[6] = 1;
    pw[4]                              = 0;
    pw[5]                              = 0;
    pw[6]                              = 0;
    pw[7]                              = 0;
    pw[8]                              = 0;
    reinterpret_cast<UByte*>(pw)[0x48] = 0;
    reinterpret_cast<UByte*>(pw)[0x68] = 0;
    return reinterpret_cast<LocalFrame*>(pw);
}

// A fresh activation frame, pushed on the environment's frame stack.
// @0x142936680
LocalFrame* Environment::CreateNewLocalFrame()
{
    UPInt*      pw = static_cast<UPInt*>(StringContext.pContext->pHeap->Alloc(0x88, static_cast<const AllocInfo*>(0)));
    LocalFrame* pf = pw ? MS2_InitLocalFrame(pw, Target ? ToAvmCharacter(Target)->GetAS2Root()->GetASGC() : 0) : 0;
    Ptr<LocalFrame> frame = *pf;
    LocalFrames.PushBack(frame);
    return frame;
}

// DeclareArray's length Value and constructor ref, which share one slot. The exe (LTCG) releases the ref with its
// flags read once and no field clears, so the code below does it by hand.
union DeclareArrayHolder
{
    Value       z;
    FunctionRef v;
    SF_FORCEINLINE DeclareArrayHolder() {}
    SF_FORCEINLINE ~DeclareArrayHolder() {}
};

// The Array literal: a new empty array with its length and constructor, filled from the arguments.
// MS2-FUNCTIONAL: one instruction off: the exe loads the Object vptr (mov r10,[rbx+0x20]) before the length Value's
// stores, ours after them; the holder/flags forms tried (fe36 a-g) do not move it
// @0x142938020
void ArrayCtorFunction::DeclareArray(const FnCall& fn)
{
    Ptr<ArrayObject> parray = *SF_HEAP_NEW(fn.Env->GetHeap()) ArrayObject(fn.Env);
    DeclareArrayHolder ctor;
    PropFlags flags(PropFlags::PropFlag_DontEnum);
    parray->SetMember(fn.Env, fn.Env->GetBuiltin(ASBuiltin_length), *::new (&ctor.z) Value(0), flags);
    ctor.z.~Value();
    ::new (&ctor.v) FunctionRef(fn.Env->GetConstructor(ASBuiltin_Array));
    parray->Set_constructor(fn.Env->GetSC(), ctor.v);
    if (fn.NArgs != 0)
        parray->InitArray(fn);
    fn.Result->SetAsObject(parray.GetPtr());
    UByte rflags = ctor.v.Flags;
    if (!(rflags & FunctionRefBase::FuncRef_Internal) && ctor.v.Function)
        ctor.v.Function->Release();
    if (!(rflags & FunctionRefBase::FuncRef_Weak) && ctor.v.pLocalFrame)
        ctor.v.pLocalFrame->Release();
}

}}} // namespace Scaleform::GFx::AS2
