// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_19
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142523170-0x14252b580 .text$mn
// MS2-RANGE: 0x14252c7e0-0x142542820 .text$mn
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include <cmath>

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR { class State; } }}}
void FUN_14251ccc0(Scaleform::GFx::AS3::TR::State* state, Scaleform::UPInt n);   // State::PopOp
void FUN_14251fcd0(void* tracer, Scaleform::UPInt regIndex);                    // Tracer: note register write

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

namespace TR {

// The Tracer reaches the VM and the abc file through a short pointer chain.
static inline UPInt TrRd(UPInt base, UPInt off) { return *reinterpret_cast<const UPInt*>(base + off); }
static inline UPInt TrAbcLink(UPInt tracer) { return TrRd(TrRd(tracer, 0x20), 0x28); }
static inline UPInt TrVM(UPInt tracer) { return TrRd(TrAbcLink(tracer), 0x20); }
static inline UPInt TrFile(UPInt tracer) { return TrRd(TrAbcLink(tracer), 0x28); }
static inline InstanceTraits::Traits& TrITraits(UPInt tracer, UPInt vmOff)
{
    return *reinterpret_cast<InstanceTraits::Traits*>(TrRd(TrRd(TrVM(tracer), vmOff), 0xc0));
}

// The exe pushes tracer values without releasing the temporary (the tag is known to need no release).
struct TrScratch
{
    template <class A> explicit TrScratch(const A& a) { new (&buf0) Value(a); }
    template <class A, class B> TrScratch(A& a, const B& b) { new (&buf0) Value(a, b); }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&buf0); }
    UPInt buf0, buf1, buf2, buf3;
};

// Tracer number value: tag first, then the payload (the exe fills the tag before reading the pool).
struct TrNumScratch
{
    explicit TrNumScratch(Value::KindType k) { w0 = static_cast<UInt32>(k); w1 = 0; }
    void SetInt(SInt32 v) { i = v; }
    void SetUInt(UInt32 v) { i = static_cast<SInt32>(v); }
    void SetNumber(double v) { d = v; }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1;
    union { SInt32 i; double d; };
    UPInt w3;
};

// Tracer value with a traits pointer: the exe zeroes the second word before storing the tag.
struct TrTraitsScratch
{
    TrTraitsScratch()
    {
        w1 = 0;
        w0 = static_cast<UInt32>(Value::kInstanceTraits);
    }
    void SetTraits(InstanceTraits::Traits& tr) { w2 = reinterpret_cast<UPInt>(&tr); }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1, w2, w3;
};

// @0x142528e20
void State::SetRegister(AbsoluteIndex ind, const Value& v)
{
    const UInt32 i = static_cast<UInt32>(ind.Get());
    Registers[i].Assign(v);
    RegChanged[i >> 3] |= static_cast<UInt8>(1 << (i & 7));
}

// @0x14253fde0
void State::SetLocal0()
{
    Registers[0].Assign(OpStack[OpStack.GetSize() - 1]);
    MarkChanged(0);
    FUN_14251ccc0(this, 1);
}

// @0x14253fe30
void State::SetLocal1()
{
    Registers[1].Assign(OpStack[OpStack.GetSize() - 1]);
    MarkChanged(1);
    FUN_14251ccc0(this, 1);
}

// @0x14253fe80
void State::SetLocal2()
{
    Registers[2].Assign(OpStack[OpStack.GetSize() - 1]);
    MarkChanged(2);
    FUN_14251ccc0(this, 1);
}

// @0x14253fed0
void State::SetLocal3()
{
    Registers[3].Assign(OpStack[OpStack.GetSize() - 1]);
    MarkChanged(3);
    FUN_14251ccc0(this, 1);
}

// @0x14253ff20
void State::SetLocalN(UInt32 ind)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(ind));
    Registers[ind].Assign(OpStack[OpStack.GetSize() - 1]);
    RegChanged[ind >> 3] |= static_cast<UInt8>(1 << (ind & 7));
    FUN_14251ccc0(this, 1);
}

// @0x14253f4a0
void State::PushScope()
{
    ScopeStack.PushBack(OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253f2f0
void State::PushByte(UInt32 arg)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(arg));
    { TrScratch t(static_cast<SInt32>(static_cast<char>(arg))); OpStack.PushBack(t.Get()); }
}

// @0x14253f640
void State::PushShort(SInt32 arg)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(arg));
    { TrScratch t(static_cast<SInt32>(arg)); OpStack.PushBack(t.Get()); }
}

// @0x14253f3b0
void State::PushInt(SInt32 ind)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kInt); t.SetInt(pool->ConstInt[ind]); OpStack.PushBack(t.Get()); }
}

// @0x14253f770
void State::PushUInt(SInt32 ind)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kUInt); t.SetUInt(pool->ConstUInt[ind]); OpStack.PushBack(t.Get()); }
}

// @0x14253f340
void State::PushDouble(SInt32 ind)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kNumber); t.SetNumber(pool->GetDouble(ind)); OpStack.PushBack(t.Get()); }
}

// @0x1425395f0
void State::PushObject(UInt32 arg)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x1f8)); OpStack.PushBack(t.Get()); }
}

// @0x14253c1a0
void State::PushObject2(UInt32 arg)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x1f8)); OpStack.PushBack(t.Get()); }
}

// @0x14253c8b0
void State::PushFunction(UInt32 arg)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x208)); OpStack.PushBack(t.Get()); }
}

// @0x14253a630
void State::PushBoolean2(UInt32 a, UInt32 b)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(a));
    FUN_14251fcd0(pTracer, static_cast<UInt32>(b));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x210)); OpStack.PushBack(t.Get()); }
}

// @0x142538f20
void State::PushITraits(InstanceTraits::Traits* tr)
{
    { TrTraitsScratch t; t.SetTraits(*tr); OpStack.PushBack(t.Get()); }
}

// @0x14253bdf0
void State::KillRegister(UInt32 ind)
{
    FUN_14251fcd0(pTracer, static_cast<UInt32>(ind));
    Registers[ind].Assign(Value::GetUndefined());
    const UInt32 sh = ind & 7;
    RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] | (1u << sh));
    RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] & ~(1u << sh));
}

} // namespace TR

}}} // namespace Scaleform::GFx::AS3

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
