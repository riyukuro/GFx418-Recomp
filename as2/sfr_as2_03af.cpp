// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 script function object
// constructor (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03af
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142918690-0x14291882a .text$mn
// MS2-RANGE: 0x142954080-0x142954086 .text$mn
// MS2-RANGE: 0x142964e40-0x142964e42 .text$mn
// MS2-RANGE: 0x142965500-0x142965502 .text$mn
// MS2-RANGE: 0x142965cf0-0x142965cf2 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The members of AsFunctionObject past +0x78 (the body of a script function), as in sfr_as2_06b.
struct AsFunctionBody
{
    ActionBuffer*  pActionBuffer;          // +0x78 Ptr<ActionBuffer>
    WithStackArray WithStack;              // +0x80
    unsigned       StartPc;                // +0x98
    unsigned       Length;                 // +0x9c
    UPInt          ArgSpecs[3];            // +0xa0 the argument specs (empty)
    unsigned       ArgSpecsFlags;          // +0xb8
    ASString       Name;                   // +0xc0 starts as the empty string
    UInt16         Function2Flags;         // +0xc8
    UByte          ExecType;               // +0xca
    UByte          LocalRegisterCount;     // +0xcb
};

// A function made by a script (DefineFunction) is bound to the character it is defined in, except the kinds 3 and 4
// which run without one.
// MS2-FUNCTIONAL: the body members are written through a view, the ASString and the handle counts are the same
// @0x142918690
AsFunctionObject::AsFunctionObject(Environment* penv, ActionBuffer* pactionBuffer, unsigned startPc, unsigned length,
                                   const void* pwithStack, int execType)
    : FunctionObject(penv), pMovieRoot(0), TargetHandle(0)
{
    AsFunctionBody* pbody = reinterpret_cast<AsFunctionBody*>(reinterpret_cast<UByte*>(this) + 0x78);
    if (pactionBuffer)
        pactionBuffer->AddRef();
    pbody->pActionBuffer = pactionBuffer;
    ::new (&pbody->WithStack) WithStackArray();
    pbody->StartPc = startPc;
    pbody->Length  = length;
    pbody->ArgSpecs[0] = pbody->ArgSpecs[1] = pbody->ArgSpecs[2] = 0;
    pbody->ArgSpecsFlags = 0;
    ::new (&pbody->Name) ASString(penv->GetBuiltin(ASBuiltin_empty_));
    pbody->Function2Flags     = 0;
    pbody->ExecType           = static_cast<UByte>(execType);
    pbody->LocalRegisterCount = 0;

    if (pwithStack)
    {
        const WithStackArray* pwith = static_cast<const WithStackArray*>(pwithStack);
        pbody->WithStack.Resize(pwith->GetSize());
        for (UPInt i = 0; i < pbody->WithStack.GetSize(); ++i)
            pbody->WithStack[i] = (*pwith)[i];
    }
    if (static_cast<unsigned>(execType - 3) > 1)
    {
        InteractiveObject* ptarget = penv->GetTarget();
        TargetHandle               = ptarget->GetCharacterHandle();
        pMovieRoot                 = ptarget->GetMovieImpl();
    }
}

// @0x142965cf0
bool AsFunctionObject::IsNull() const { return false; }
// @0x142965500
bool AsFunctionObject::IsEqual(const FunctionObject&) const { return false; }
// @0x142964e40
bool AsFunctionObject::IsAsFunction() const { return true; }
// @0x142954080
int AsFunctionObject::GetNumArgs() const { return *reinterpret_cast<const int*>(reinterpret_cast<const UByte*>(this) + 0xa8); }

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7AsFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218058
// MS2-PIN: ??_7AsFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432180e0
