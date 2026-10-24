// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 state bags: the StateBag
// forwarders and the StateBagImpl state hash (set / get / get many under one lock, falling back to the delegate),
// with the hash set code they instantiate. The exe placed them among GFx_DrawText.
// Eighth source of queue unit sfr_gfx_01 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_01h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142569a40-0x142569c00 .text$mn
// MS2-RANGE: 0x142569d70-0x142569dd0 .text$mn
// MS2-RANGE: 0x14256a9d0-0x14256aa60 .text$mn
// MS2-RANGE: 0x14256deb0-0x14256df40 .text$mn
// MS2-RANGE: 0x14256fa70-0x14256fb80 .text$mn
// MS2-RANGE: 0x14256fbb0-0x14256fd60 .text$mn
// MS2-RANGE: 0x142576530-0x142576750 .text$mn
// MS2-RANGE: 0x142578f10-0x142579060 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "../include/gfx/gfx_loaderimpl.h"

namespace Scaleform {
// The state hash's Clear stays out of line (setRawCapacity calls it for a zero capacity).
// @0x14256deb0
template void GFx::StateBagImpl::StateHash::BaseType::Clear();
} // namespace Scaleform

namespace Scaleform { namespace GFx {

// @0x142576530
void StateBag::SetState(State::StateType state, State* pstate)
{
    StateBag* pimpl = GetStateBagImpl();
    if (pimpl)
        pimpl->SetState(state, pstate);
}

// @0x14256fa70
State* StateBag::GetStateAddRef(State::StateType state) const
{
    StateBag* pimpl = GetStateBagImpl();
    return pimpl ? pimpl->GetStateAddRef(state) : 0;
}

// @0x14256fbb0
StateBag* StateBag::GetStateBagImpl() const
{
    return 0;
}

// @0x14256fbc0
void StateBag::GetStatesAddRef(State** pstates, const State::StateType* pstateTypes, unsigned count) const
{
    StateBag* pimpl = GetStateBagImpl();
    if (pimpl)
        pimpl->GetStatesAddRef(pstates, pstateTypes, count);
}

// A null state removes the entry (the delegate's one shows through again).
// @0x142576570
void StateBagImpl::SetState(State::StateType state, State* pstate)
{
    Lock::Locker guard(&StateLock);
    if (pstate)
        States.Set(StatePtr(pstate));
    else
        States.RemoveAlt(state);
}

// @0x14256faa0
State* StateBagImpl::GetStateAddRef(State::StateType state) const
{
    {
        Lock::Locker guard(&StateLock);
        const StatePtr* pstatePtr = States.GetAlt(state);
        if (pstatePtr)
        {
            pstatePtr->pState->AddRef();
            return pstatePtr->pState;
        }
    }
    return pDelegate ? pDelegate->GetStateAddRef(state) : 0;
}

// Fills only the slots still null; whatever this bag lacks is asked of the delegate in one go.
// @0x14256fc10
void StateBagImpl::GetStatesAddRef(State** pstates, const State::StateType* pstateTypes, unsigned count) const
{
    bool needDelegate = false;
    {
        Lock::Locker guard(&StateLock);
        for (unsigned i = 0; i < count; i++)
        {
            if (pstates[i])
                continue;
            const StatePtr* pstatePtr = States.GetAlt(pstateTypes[i]);
            if (pstatePtr)
            {
                pstatePtr->pState->AddRef();
                pstates[i] = pstatePtr->pState;
            }
            else
                needDelegate = true;
        }
    }
    if (needDelegate && pDelegate)
        pDelegate->GetStatesAddRef(pstates, pstateTypes, count);
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??0?$HashsetCachedEntry@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@@Scaleform@@QEAA@AEBV01@@Z 0x142569d70
// MS2-FUNCTIONAL ?setRawCapacity@?$HashSetBase@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@U5234@U?$AllocatorGH@UStatePtr@StateBagImpl@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@@4@@Scaleform@@AEAAXPEAX_K@Z: the exe copy (from another source) calls Clear for a zero capacity, this one inlines it
// MS2-PIN: ?setRawCapacity@?$HashSetBase@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@U5234@U?$AllocatorGH@UStatePtr@StateBagImpl@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@@4@@Scaleform@@AEAAXPEAX_K@Z 0x142578f10
// MS2-PIN: ??1?$HashSetBase@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@U5234@U?$AllocatorGH@UStatePtr@StateBagImpl@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@@4@@Scaleform@@QEAA@XZ 0x14256a9d0
// MS2-PIN: ?Clear@?$HashSetBase@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@U5234@U?$AllocatorGH@UStatePtr@StateBagImpl@GFx@Scaleform@@$01@4@V?$HashsetCachedEntry@UStatePtr@StateBagImpl@GFx@Scaleform@@UStatePtrHashOp@234@@4@@Scaleform@@QEAAXXZ 0x14256deb0
