// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 script function object
// Finalize_GC, gap function of sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142942c00-0x142942c97 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The members of AsFunctionObject past +0x78, as in sfr_as2_03af (the argument specs typed).
struct AsFunctionBodyView
{
    ActionBuffer*                                      pActionBuffer; // +0x78
    WithStackArray                                     WithStack;     // +0x80
    unsigned                                           StartPc;       // +0x98
    unsigned                                           Length;        // +0x9c
    ArrayLH<AsFunctionObject::ArgSpec, StatMV_ActionScript_Mem> ArgSpecs; // +0xa0
    unsigned                                           ArgSpecsFlags; // +0xb8
    ASString                                           Name;          // +0xc0
};

// MS2-FUNCTIONAL: the exe releases the handle with the reference count and destructor inlined
// @0x142942c00
void AsFunctionObject::Finalize_GC()
{
    AsFunctionBodyView* pbody = reinterpret_cast<AsFunctionBodyView*>(reinterpret_cast<UByte*>(this) + 0x78);
    pbody->Name.~ASString();
    pbody->ArgSpecs.~ArrayLH();
    pbody->WithStack.~WithStackArray();
    if (pbody->pActionBuffer)
        pbody->pActionBuffer->Release();
    pbody->pActionBuffer = 0;
    TargetHandle = 0;
    Object::Finalize_GC();
}

}}} // namespace Scaleform::GFx::AS2
