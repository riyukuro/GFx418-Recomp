// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 Object and Function
// prototype constructors and their function tables (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14291c0f0-0x14291c15d .text$mn
// MS2-RANGE: 0x14291f9a0-0x14291fa80 .text$mn
// MS2-RANGE: 0x14291fa90-0x14291faf2 .text$mn
// MS2-RANGE: 0x14291fb00-0x14291fb66 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_objectproto.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The valueOf natives of both prototypes (not recovered).
void FUN_1429033a0(const FnCall& fn);
void FUN_142902a00(const FnCall& fn);

const NameFunction ObjectProto::FunctionTable[] = {
    { "addProperty", &ObjectProto::AddProperty },
    { "hasOwnProperty", &ObjectProto::HasOwnProperty },
    { "watch", &ObjectProto::Watch_ },
    { "unwatch", &ObjectProto::Unwatch_ },
    { "isPropertyEnumerable", &ObjectProto::IsPropertyEnumerable },
    { "isPrototypeOf", &ObjectProto::IsPrototypeOf },
    { "toString", &ObjectProto::ToString },
    { "valueOf", &FUN_142902a00 },
    { 0, 0 }
};

const NameFunction FunctionProto::FunctionTable[] = {
    { "apply", &FunctionProto::Apply },
    { "call", &FunctionProto::Call },
    { "toString", &FunctionProto::ToString },
    { "valueOf", &FUN_1429033a0 },
    { 0, 0 }
};

// @0x14291c0f0
FunctionProto::FunctionProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, bool addApply)
    : Prototype<Object>(psc, pprototype, constructor)
{
    if (addApply)
        InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x14291f9a0
ObjectProto::ObjectProto(ASStringContext* psc, const FunctionRef& constructor)
    : Prototype<Object>(psc, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x14291fa90
ObjectProto::ObjectProto(ASStringContext* psc, Object* pprototype)
    : Prototype<Object>(psc, pprototype)
{
}

// @0x14291fb00
ObjectProto::ObjectProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<Object>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143215f60
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215fa8
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143216050
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216058
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432160a0
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6B@ 0x143216148
// MS2-PIN: ??_7FunctionProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216150
// MS2-PIN: ??_7FunctionProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216198
// MS2-PIN: ??_7FunctionProto@AS2@GFx@Scaleform@@6B@ 0x143216240
