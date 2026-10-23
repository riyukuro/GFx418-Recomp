// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_18
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142509d40-0x142523170 .text$mn
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL 0x14250c230: returns the executable's null-tagged singleton; C++ local-static initialization differs.
// @0x14250c230
const Value& Value::GetNull()
{
    static const Value nullValue = []() {
        Value value;
        value.SetNullUnsafe();
        return value;
    }();
    return nullValue;
}

// MS2-FUNCTIONAL 0x14250f8f0: default-constructed Value has the undefined tag; local-static initialization differs.
// @0x14250f8f0
const Value& Value::GetUndefined()
{
    static const Value undefinedValue;
    return undefinedValue;
}

// MS2-FUNCTIONAL 0x14250a900: tracer-only and class-traits tags still need exact edge-case matching.
// @0x14250a900
// The executable selects the boxed primitive traits from the value kind and takes the
// instance traits directly from reference values. The remaining tracer-only tags are
// deliberately mapped through their public Value accessors; their uncommon edge cases
// still need byte-level comparison.
const InstanceTraits::Traits& VM::GetInstanceTraits(const Value& v) const
{
    switch (v.GetKind())
    {
    case Value::kBoolean: return GetClassTraitsBoolean().GetInstanceTraits();
    case Value::kInt:     return GetClassTraitsSInt().GetInstanceTraits();
    case Value::kUInt:    return GetClassTraitsUInt().GetInstanceTraits();
    case Value::kNumber:  return GetClassTraitsNumber().GetInstanceTraits();
    case Value::kString:  return GetClassTraitsString().GetInstanceTraits();
    case Value::kNamespace: return GetClassTraitsNamespace().GetInstanceTraits();
    case Value::kClass:   return v.AsClass().GetInstanceTraits();
    case Value::kFunction:
    case Value::kThunk:
    case Value::kThunkFunction:
        return GetClassTraitsFunction().GetInstanceTraits();
    case Value::kUndefined:
    case Value::kMethodInd:
    case Value::kVTableInd:
    case Value::kVTableIndClosure:
        return GetClassTraitsVoid().GetInstanceTraits();
    default:
        if (v.IsNull())
            return GetClassTraitsNull().GetInstanceTraits();
        return v.GetInstanceTraits();
    }
}

// MS2-FUNCTIONAL 0x14250be40: iterator preserves bucket order; exact tombstone boundary comparison remains to verify.
// @0x14250be40
GlobalSlotIndex Object::GetNextDynPropIndex(GlobalSlotIndex ind) const
{
    const DynAttrsType& attrs = DynAttrs;
    DynAttrsType::ConstIterator it = attrs.Begin();
    const UPInt start = ind.IsValid() ? static_cast<UPInt>(ind.Get() - 1) : 0;
    for (; !it.IsEnd(); ++it)
    {
        if (static_cast<UPInt>(it.GetIndex()) < start)
            continue;
        if ((it->First.Flags & 1) == 0)
            return GlobalSlotIndex(static_cast<UInt32>(it.GetIndex() + 1));
    }
    return GlobalSlotIndex(0);
}

// MS2-FUNCTIONAL 0x14250c010: name lookup follows the recovered bucket index; invalid-index behavior remains to verify.
// @0x14250c010
void Object::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
{
    const UPInt target = ind.IsValid() ? static_cast<UPInt>(ind.Get() - 1) : 0;
    for (DynAttrsType::ConstIterator it = DynAttrs.Begin(); !it.IsEnd(); ++it)
    {
        if (static_cast<UPInt>(it.GetIndex()) == target)
        {
            name.Assign(it->First.Name);
            return;
        }
    }
    name.SetUndefined();
}

}}} // namespace Scaleform::GFx::AS3

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
