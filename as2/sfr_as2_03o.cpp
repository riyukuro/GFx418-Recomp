// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 super object constructor (gap
// recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429213a0-0x14292147f .text$mn
// MS2-RANGE: 0x142941250-0x142941270 .text$mn
// MS2-RANGE: 0x142987700-0x14298770e .text$mn
// MS2-RANGE: 0x1429505c0-0x1429505cd .text$mn
// MS2-RANGE: 0x1429449f0-0x1429449fd .text$mn
// MS2-RANGE: 0x142938ac0-0x142938acd .text$mn
// MS2-RANGE: 0x142988a30-0x142988a3d .text$mn
// MS2-RANGE: 0x142994a00-0x142994a0e .text$mn
// MS2-RANGE: 0x14295da40-0x14295da4d .text$mn
// MS2-RANGE: 0x142989020-0x14298902e .text$mn
// MS2-RANGE: 0x142953970-0x14295397d .text$mn
// MS2-RANGE: 0x142965f00-0x142965f02 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_refcountcollector.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x1429213a0
SuperObject::SuperObject(Object* pproto, ObjectInterface* prealThis, const FunctionRef& ctor)
    : Object(static_cast<ASRefCountCollector*>(pproto->GetCollector())), SuperProto(pproto), SavedProto(0), RealThis(prealThis), Constructor(ctor)
{
    pProto = pproto;
}

// The collector's walk, per operation (the exe tail-calls the three instantiations).
// MS2-FUNCTIONAL: the exe tail-calls out-of-line ForEachChild_GC instantiations (0x1429141f0/0x14290e280/0x142911340);
// here they are inlined
// @0x142941250
void SuperObject::ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const
{
    switch (operation)
    {
    case ASRefCountBaseType::Operation_Release:
        ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(prcc);
        break;
    case ASRefCountBaseType::Operation_MarkInCycle:
        ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(prcc);
        break;
    case ASRefCountBaseType::Operation_ScanInUse:
        ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(prcc);
        break;
    default:;
    }
}

// The member accessors forward to the prototype above the caller's (the exe tail-calls through its ObjectInterface).
// @0x142987700
bool SuperObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    return SuperProto->SetMember(penv, name, val, flags);
}

// @0x1429505c0
bool SuperObject::GetMember(Environment* penv, const ASString& name, Value* val)
{
    return SuperProto->GetMember(penv, name, val);
}

// @0x1429449f0
bool SuperObject::FindMember(ASStringContext* psc, const ASString& name, Member* pmember)
{
    return SuperProto->FindMember(psc, name, pmember);
}

// @0x142938ac0
bool SuperObject::DeleteMember(ASStringContext* psc, const ASString& name)
{
    return SuperProto->DeleteMember(psc, name);
}

// @0x142988a30
bool SuperObject::SetMemberFlags(ASStringContext* psc, const ASString& name, const UByte flags)
{
    return SuperProto->SetMemberFlags(psc, name, flags);
}

// @0x142994a00
void SuperObject::VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags,
                               const ObjectInterface* instance) const
{
    SuperProto->VisitMembers(psc, pvisitor, visitFlags, instance);
}

// @0x14295da40
bool SuperObject::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    return SuperProto->HasMember(psc, name, inclPrototypes);
}

// @0x142989020
bool SuperObject::SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val, const PropFlags& flags)
{
    return SuperProto->SetMemberRaw(psc, name, val, flags);
}

// @0x142953970
bool SuperObject::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    return SuperProto->GetMemberRaw(psc, name, val);
}

// @0x142965f00
bool SuperObject::IsSuper() const
{
    return true;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7SuperObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216248
// MS2-PIN: ??_7SuperObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216290
