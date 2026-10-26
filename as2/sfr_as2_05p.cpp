// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmButton::GetMember of
// sfr_as2_05 (gap recovery, lane sfr36).
// Also the vftable slots without pdata that only the recovered vftable images (data_rdata_sf_b) reach, defined at
// their exe addresses so the full-exe link resolves them: LocalFrame's two collector overrides, AS2ValueObjectInterface's
// GetArraySize and GetAdvanceStats, AvmCharacter::GetMember and the AS2 IntervalTimer's two getters (sfr22).
// MS2-UNIT: sfr_as2_05p
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14294bea0-0x14294bfdd .text$mn
// MS2-RANGE: 0x142941190-0x1429411c0 .text$mn
// MS2-RANGE: 0x142942db0-0x142942db9 .text$mn
// MS2-RANGE: 0x1429497d0-0x1429497e1 .text$mn
// MS2-RANGE: 0x142949820-0x142949833 .text$mn
// MS2-RANGE: 0x14294b080-0x14294b084 .text$mn
// MS2-RANGE: 0x14294bfe0-0x14294bfe3 .text$mn
// MS2-RANGE: 0x142953f40-0x142953f45 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/gfx_button.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_value.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The script side of a button (partial local copy; the other units carry their own).
class AvmButton : public AvmCharacter, public AvmButtonBase
{
public:
    Ptr<ButtonObject> ASButtonObj; // +0x38

    virtual bool GetMember(Environment* penv, const ASString& name, Value* pval);
};

// Standard members (_x, _alpha, ...) first, then the button's AS object; until that exists the prototype stands
// in (__proto__ itself is answered here). _global is visible from every character.
// @0x14294bea0
bool AvmButton::GetMember(Environment* penv, const ASString& name, Value* pval)
{
    if (name.GetHashFlags() & ASConstString::Flag_StandardMember)
        if (GetStandardMember(GetStandardMemberConstant(name), pval, 0))
            return true;

    if (ASButtonObj)
        return ASButtonObj->GetMember(penv, name, pval);

    if (penv && name == penv->GetBuiltin(ASBuiltin___proto__))
    {
        pval->SetAsObject(pProto);
        return true;
    }
    if (pProto && pProto->GetMember(penv, name, pval))
        return true;
    if (penv && name == penv->GetBuiltin(63)) // _global
    {
        pval->SetAsObject(penv->GetSC()->pContext->pGlobal);
        return true;
    }
    return false;
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx { namespace AS2 {

// LocalFrame's ExecuteForEachChild_GC and Finalize_GC overrides. as2_action.h does not declare them (adding them would
// rebuild every AS2 unit), so they stand in here as free functions.
// LocalFrame's out-of-line ForEachChild_GC<Functor> instantiations (sfr_as2_02; this in rcx).
void FUN_142910cf0(const LocalFrame* pframe, ASRefCountBaseType::Collector* prcc); // ReleaseFunctor
void FUN_14290dbd0(const LocalFrame* pframe, ASRefCountBaseType::Collector* prcc); // MarkInCycleFunctor
void FUN_142913b00(const LocalFrame* pframe, ASRefCountBaseType::Collector* prcc); // ScanInUseFunctor

// @0x142941190
void FUN_142941190(const LocalFrame* pframe, ASRefCountBaseType::Collector* prcc,
                   ASRefCountBaseType::OperationGC operation)
{
    switch (operation)
    {
    case ASRefCountBaseType::Operation_Release:
        FUN_142910cf0(pframe, prcc);
        break;
    case ASRefCountBaseType::Operation_MarkInCycle:
        FUN_14290dbd0(pframe, prcc);
        break;
    case ASRefCountBaseType::Operation_ScanInUse:
        FUN_142913b00(pframe, prcc);
        break;
    default:;
    }
}

// The variables' hash destructor (0x142924960, shared by ICF).
void FUN_142924960(ASStringHash_GC<Value>* phash);

// Finalize_GC: the variables go before collection (the exe jumps to the hash's destructor).
// @0x142942db0
void FUN_142942db0(LocalFrame* pframe)
{
    FUN_142924960(&pframe->Variables);
}

// The base character finds no member; the sprite, button and text field characters override it.
// @0x14294bfe0
bool AvmCharacter::GetMember(Environment*, const ASString&, Value*)
{
    return false;
}

// @0x14294b080
int IntervalTimer::GetId() const
{
    return Id;
}

// @0x142953f40
UInt64 IntervalTimer::GetNextInvokeTime() const
{
    return InvokeTime;
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// The host side of AS2 values; only the members recovered in this unit.
class AS2ValueObjectInterface : public Value::ObjectInterface
{
private:
    virtual unsigned        GetArraySize(void* pdata) const;
    virtual AMP::ViewStats* GetAdvanceStats() const;
};

// The element count of the array pdata.
// @0x142949820
unsigned AS2ValueObjectInterface::GetArraySize(void* pdata) const
{
    AS2::ArrayObject* parr = static_cast<AS2::ArrayObject*>(static_cast<AS2::ObjectInterface*>(pdata));
    return parr->GetSize();
}

// The movie's advance statistics.
// @0x1429497d0
AMP::ViewStats* AS2ValueObjectInterface::GetAdvanceStats() const
{
    return (AMP::ViewStats*)pMovieRoot->pASMovieRoot->GetMovieImpl()->pAdvanceStats;
}

}} // namespace Scaleform::GFx
