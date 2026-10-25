// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 small dtors: the argument
// descriptor array of script functions (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142924180-0x1429241e7 .text$mn
// MS2-RANGE: 0x142925250-0x1429252d1 .text$mn
// MS2-RANGE: 0x1429253d0-0x14292541e .text$mn
// MS2-RANGE: 0x142925420-0x1429254d3 .text$mn
// MS2-RANGE: 0x142925680-0x14292572b .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"

namespace Scaleform {

// The exe calls the container teardowns instead of inlining them.
extern template GFx::AS2::PagedStack<GFx::AS2::Value, 32>::~PagedStack();
extern template GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::~PagedStack();
extern template ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
extern template decltype(HashLH<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>,
                                GFx::EventIdHashFunctor, GFx::AS2::StatMV_ActionScript_Mem>::mHash)::BaseType::~HashSetBase();
extern template ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                              ArrayDefaultPolicy>::~ArrayDataBase();

// @0x142924180
template ArrayDataBase<GFx::AS2::AsFunctionObject::ArgSpec,
                       AllocatorLH<GFx::AS2::AsFunctionObject::ArgSpec, GFx::AS2::StatMV_ActionScript_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();

} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS2 {

// The queue's iterator hands every entry back to the free list; the recycled entries are then deleted.
// @0x142925250
MovieRoot::ActionQueueType::~ActionQueueType()
{
    {
        ActionQueueIterator iter(this);
        while (iter.getNext())
            ;
    }
    ActionEntry* pentry = pFreeEntry;
    while (pentry)
    {
        ActionEntry* pnext = pentry->pNextEntry;
        pentry->~ActionEntry();
        SF_FREE(pentry);
        pentry = pnext;
    }
}

// @0x1429253d0
AvmCharacter::~AvmCharacter()
{
}

// @0x142925420
AvmSprite::~AvmSprite()
{
}

// The members release in reverse order: the frames, the throw value, the try blocks, the call stack, the registers
// and the stack.
// @0x142925680
Environment::~Environment()
{
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7?$LogBase@VEnvironment@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x143215ad0
// MS2-PIN: ??_7Environment@AS2@GFx@Scaleform@@6B@ 0x143215ae0
// MS2-PIN: ??_7AvmSprite@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x143216338
// MS2-PIN: ??_7AvmSprite@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216480
// MS2-PIN: ??_7AvmSprite@AS2@GFx@Scaleform@@6B@ 0x143216528
// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x143215b00
// MS2-PIN: ??_7AvmCharacter@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215c48
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
