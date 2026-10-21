// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the state bag TU
// (Render_StateBag): the per-type Interface registry and the StateBag single-item / shared-array storage.
// Queue unit sfr_render_03 is split along its original sources (sfr_render_03 Matrix3x4 + Text_Core, 03b
// Text_DocView, 03c TreeNode, 03d ShapeMeshProvider, 03e StateBag, 03f TreeMesh + TreeShape).
// MS2-UNIT: sfr_render_03e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142625920-0x142626190 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_statebag.h"

namespace Scaleform { namespace Render {

// indexed by StateType (0x143b160a0)
static StateData::Interface* StateType_Interfaces[State_Type_Count] = { 0 };

inline StateData::Interface* StateData::Interface::FromStateType(StateType type)
{
    return StateType_Interfaces[type];
}

// @0x142625920
StateData::Interface::Interface(StateType type) : Type(type)
{
    StateType_Interfaces[type] = getThis();
}

// @0x142625a10
void StateData::ArrayData::Release(UPInt count)
{
    if (AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, -1) - 1 == 0)
    {
        State* states = GetStates();
        for (; count; count--, states++)
            states->getInterface_Unsafe()->Release(states->pData, Interface::Ref_NoTreeNode);
        SF_FREE(this);
    }
}

// @0x142625ee0
void StateData::addRefBag_NotEmpty() const
{
    if (isSingleItem())
        getInterface()->AddRef(pData, Interface::Ref_NoTreeNode);
    else
        pArray->AddRef();
}

// The bag is left pointing at the released data (the caller is the destructor or overwrites it).
// @0x142626160
void StateData::destroyBag_NotEmpty()
{
    if (isSingleItem())
        getInterface()->Release(pData, Interface::Ref_NoTreeNode);
    else
        pArray->Release(getArraySize());
}

// @0x142626070
void StateData::assignBag(const StateData& src)
{
    if (!src.isEmpty())
        src.addRefBag_NotEmpty();
    if (!isEmpty())
        destroyBag_NotEmpty();
    pInterface = src.pInterface;
    pData      = src.pData;
}

// @0x1426259b0
const State* StateBag::GetState(StateType type) const
{
    if (isEmpty())
        return 0;
    Interface* pi = Interface::FromStateType(type);
    if (isSingleItem())
        return getInterface() == pi ? toState() : 0;

    UPInt  count  = getArraySize();
    State* states = pArray->GetStates();
    for (UPInt i = 0; i < count; i++)
        if (states[i].pInterface == pi)
            return &states[i];
    return 0;
}

// @0x142625cb0
void StateBag::SetStateVoid(Interface* pi, void* data)
{
    if (isEmpty())
    {
        initSingleItem(pi, data);
        pi->AddRef(data, Interface::Ref_All);
        return;
    }

    if (isSingleItem())
    {
        if (getInterface() == pi)
        {
            pi->AddRef(data, Interface::Ref_All);
            pi->Release(pData, Interface::Ref_All);
            pData = data;
            return;
        }
        // grow to a two-entry array; the inline state's reference moves into it
        ArrayData* arr = allocData(0, 0, 2);
        if (!arr)
            return;
        arr->GetStates()[0].initArrayItem(getInterface(), pData);
        arr->GetStates()[1].initArrayItem(pi, data);
        pi->AddRef(data, Interface::Ref_All);
        initArray(arr, 2);
        return;
    }

    UPInt  count  = getArraySize();
    State* states = pArray->GetStates();
    for (UPInt i = 0; i < count; i++)
    {
        if (states[i].pInterface == pi)
        {
            pi->AddRef(data, Interface::Ref_All);
            pi->Release(states[i].pData, Interface::Ref_All);
            states[i].pData = data;
            return;
        }
    }

    // the array may be shared with another snapshot: copy it with one more slot
    ArrayData* arr = allocData(states, count, 1);
    if (!arr)
        return;
    arr->GetStates()[count].initArrayItem(pi, data);
    pi->AddRef(data, Interface::Ref_All);
    pArray->Release(count);
    initArray(arr, count + 1);
}

// @0x142625b00
bool StateBag::RemoveState(StateType type)
{
    if (isEmpty())
        return false;
    Interface* pi = Interface::FromStateType(type);

    if (isSingleItem())
    {
        if (getInterface() != pi)
            return false;
        pi->Release(pData, Interface::Ref_All);
        pInterface = 0;
        pData      = 0;
        return true;
    }

    UPInt  count  = getArraySize();
    State* states = pArray->GetStates();
    UPInt  i;
    for (i = 0; i < count; i++)
        if (states[i].pInterface == pi)
            break;
    if (i == count)
        return false;

    ArrayData* old     = pArray;
    State*     removed = old->GetStates() + i;
    if (count == 2)
    {
        State* other = old->GetStates() + (i ^ 1);
        initSingleItem(other->getInterface_Unsafe(), other->GetData());
        other->getInterface_Unsafe()->AddRef(other->GetData(), Interface::Ref_NoTreeNode);
    }
    else
    {
        ArrayData* arr = allocData2(old->GetStates(), i, old->GetStates() + i + 1, count - i - 1);
        if (!arr)
            return false;
        initArray(arr, count - 1);
    }
    // releasing the old array drops everything but tree nodes; the removed one's node goes here
    removed->getInterface_Unsafe()->Release(removed->GetData(), Interface::Ref_ReleaseTreeNodeOnly);
    old->Release(count);
    return true;
}

// @0x142625990
const State& StateBag::GetAt(UPInt index) const
{
    if (isSingleItem())
        return *toState();
    return pArray->GetStates()[index];
}

// @0x142625a80
void StateBag::ReleaseNodes() const
{
    if (isEmpty())
        return;
    if (isSingleItem())
    {
        getInterface()->Release(pData, Interface::Ref_ReleaseTreeNodeOnly);
    }
    else
    {
        UPInt  count = getArraySize();
        State* state = pArray->GetStates();
        for (; count; count--, state++)
            state->getInterface_Unsafe()->Release(state->pData, Interface::Ref_ReleaseTreeNodeOnly);
    }
}

// @0x142625fb0
StateBag::ArrayData* StateBag::allocData(State* source, UPInt count, UPInt extra)
{
    UPInt      size = sizeof(int) + sizeof(State) * (count + extra);
    ArrayData* data = (ArrayData*)SF_HEAP_AUTO_ALLOC(this, size);
    if (!data)
        return 0;
    data->RefCount = 1;
    copyArrayAddRef(data->GetStates(), source, count);
    return data;
}

// @0x142625f10
StateBag::ArrayData* StateBag::allocData2(State* source1, UPInt count1, State* source2, UPInt count2)
{
    ArrayData* data = allocData(source1, count1, count2);
    if (!data)
        return 0;
    copyArrayAddRef(data->GetStates() + count1, source2, count2);
    return data;
}

// @0x142626100
void StateBag::copyArrayAddRef(State* d, State* s, UPInt count)
{
    for (; count; count--, s++, d++)
    {
        Interface* pi = s->getInterface_Unsafe();
        d->initArrayItem(pi, s->pData);
        pi->AddRef(s->pData, Interface::Ref_NoTreeNode);
    }
}

}} // namespace Scaleform::Render

// @0x142625950 is the Interface deleting destructor (emitted from the header).
// MS2-PIN: ??_7Interface@StateData@Render@Scaleform@@6B@ 0x14318f0a8
