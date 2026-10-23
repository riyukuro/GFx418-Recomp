// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_19
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142523170-0x14252b580 .text$mn
// MS2-RANGE: 0x14252c7e0-0x142542820 .text$mn
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include <cmath>

namespace Scaleform { namespace GFx { namespace AS3 { namespace ClassTraits {

// MS2-FUNCTIONAL 0x1425274f0: ownership and interface-flag effects match; exact refcount codegen remains to compare.
// @0x1425274f0
void Traits::SetInstanceTraits(Pickable<InstanceTraits::Traits> itr)
{
    const UInt32 incomingFlags = static_cast<UInt32>(itr->Flags);
    const SPInt interfaceMask = -static_cast<SPInt>((incomingFlags >> 2) & 1);
    Flags ^= (Flags ^ interfaceMask) & AS3::Traits::IsInterfaceMask;
    ITraits = itr;
}

}}}} // namespace Scaleform::GFx::AS3::ClassTraits

namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL 0x14252f6d0: delegates conversion to the recovered primitive/complex helper; the exe has an explicit tag switch.
// @0x14252f6d0
CheckResult Value::ToNumberValueInline()
{
    Number result;
    if (!Convert2NumberInline(result))
        return CheckResult(false);
    SetNumber(result);
    return CheckResult(true);
}

// MS2-FUNCTIONAL 0x14252f670: uses the recovered numeric coercion result; locale-sensitive range helpers differ.
// @0x14252f670
CheckResult Value::ToInt32Value()
{
    Number number;
    CheckResult converted = Convert2NumberInline(number);
    if (!converted)
        return converted;

    double wrapped = 0.0;
    if (std::isfinite(number))
    {
        wrapped = std::fmod(std::trunc(number), 4294967296.0);
        if (wrapped >= 2147483648.0)
            wrapped -= 4294967296.0;
        else if (wrapped < -2147483648.0)
            wrapped += 4294967296.0;
    }
    SetSInt32(static_cast<SInt32>(wrapped));
    return converted;
}

// MS2-FUNCTIONAL 0x14252fe80: uses the recovered numeric coercion result and AVM 32-bit modulo; the helper call graph differs.
// @0x14252fe80
CheckResult Value::ToUInt32Value()
{
    Number number;
    CheckResult converted = Convert2NumberInline(number);
    if (!converted)
        return converted;

    double wrapped = 0.0;
    if (std::isfinite(number))
    {
        wrapped = std::fmod(std::trunc(number), 4294967296.0);
        if (wrapped < 0.0)
            wrapped += 4294967296.0;
    }
    SetUInt32(static_cast<UInt32>(wrapped));
    return converted;
}

// MS2-FUNCTIONAL 0x14252fe10: converts into an ASString and assigns it back; the exe routes allocation through the supplied StringManager.
// @0x14252fe10
CheckResult Value::ToStringValue(StringManager& stringManager)
{
    ASString string = stringManager.CreateString("", 0);
    CheckResult converted = Convert2String(string);
    if (converted)
        Assign(string);
    return converted;
}

// MS2-FUNCTIONAL 0x142527560: updates the pair and key-to-latest-slot chain; inlined refcount/hash paths differ.
// @0x142527560
void SlotContainerType::SetKey(AbsoluteIndex ind, const ASString& key)
{
    Pair& pair = VArray[static_cast<UPInt>(ind.Get())];
    ASStringNode* node = key.GetNode();
    if (pair.Key.GetPtr() == node)
        return;

    pair.Key = node;
    SetType::Iterator it = KVHashSet.Find(node);
    if (it.IsEnd())
    {
        pair.Prev = -1;
        KVHashSet.Add(node, static_cast<SPInt>(ind.Get()));
    }
    else
    {
        pair.Prev = it->Second;
        it->Second = static_cast<SPInt>(ind.Get());
    }
}

// MS2-FUNCTIONAL 0x1425276d0: updates the pair name, prior-name chain and name-to-slot map; Ptr/Hash helpers produce different temporary refcount code.
// @0x1425276d0
void Slots::SetKey(AbsoluteIndex ind, const ASString& key)
{
    const UInt32 ownIndex = static_cast<UInt32>(ind.Get()) - static_cast<UInt32>(FirstOwnSlotNum);
    Pair& pair = VArray[ownIndex];
    if (pair.Key.GetPtr() == key.GetNode())
        return;

    pair.Key = key.GetNode();
    const UInt32* previous = Set.Get(pair.Key);
    if (previous)
    {
        pair.Prev = static_cast<SPInt>(*previous);
        Set.Set(pair.Key, static_cast<UInt32>(ind.Get()));
    }
    else
    {
        pair.Prev = -1;
        Set.Set(pair.Key, static_cast<UInt32>(ind.Get()));
    }
}

}}} // namespace Scaleform::GFx::AS3

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
