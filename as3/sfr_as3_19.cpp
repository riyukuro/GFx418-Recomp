// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_19
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142523170-0x14252b580 .text$mn
// MS2-RANGE: 0x14252c7e0-0x142542820 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Reserve@?$ArrayDataBase@UPair@Slots@AS3@GFx@Scaleform@@U?$AllocatorLH@UPair@Slots@AS3@GFx@Scaleform@@$0BEM@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x142523170 ; probe
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@$0BED@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142523530 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@UASStringNode@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@UASStringNode@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425235d0 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142523670 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142523710 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425238f0 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@VASString@GFx@Scaleform@@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BED@@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x142523a30 ; order
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425422c0 ; unique
// MS2-PINS-END tplpin
#include "ms2/scaleform/include/gfx/gfx_input.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include <cmath>

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR { class State; } }}}
void FUN_14251cd30(Scaleform::GFx::AS3::TR::State* state, Scaleform::GFx::AS3::Value* popped);   // State::PopOpValue
void FUN_14252c9f0(Scaleform::UPInt tracer, Scaleform::UInt64 pos, void* state, int off, unsigned int flag);
void FUN_1424e6aa0(Scaleform::UPInt tracer, void* state, Scaleform::UInt64 pos, int a, int b);
void FUN_1424d6cf0(void* err, int id, void* vm, const void* a1, const void* a2);   // VM::Error::Error(id, vm, Value, Value)
void FUN_1424d6f40(void* err, int id, void* vm, const void* a1);   // VM::Error::Error(id, vm, Value)
void FUN_1424d79f0(void* err, int id, void* vm, const char* a1, const void* a2);   // VM::Error::Error(id, vm, char*, Value)
void FUN_142529f70(void* button, int state, void* obj);   // AvmButton::SetStateObject
void FUN_1424ffc10(Scaleform::UPInt a, Scaleform::UPInt b, Scaleform::UPInt c, int d, int e);
void FUN_1424f03f0();
void FUN_14241fe30(void* arr, Scaleform::UInt32 size);   // Array::SetLength
bool FUN_142514000(Scaleform::UPInt tracer, const void* v);   // Tracer::IsBooleanType
bool FUN_142514470(Scaleform::UPInt tracer, const void* v);   // Tracer::IsNumberType
bool FUN_142514c30(Scaleform::UPInt tracer, const void* v);   // Tracer::IsIntType
bool FUN_142514e10(Scaleform::UPInt tracer, const void* v);   // Tracer::IsStringType
bool FUN_1425150c0(Scaleform::UPInt tracer, const void* v);   // Tracer::IsUIntType
bool FUN_142514510(Scaleform::UPInt tracer, void* traits);   // Tracer::IsNumericType
bool FUN_142514a80(Scaleform::UPInt tracer, void* traits);   // Tracer::IsPrimitiveType
void* FUN_14250fe80(void* state, const void* v);             // TR::State::GetValueTraits
void FUN_14252ecb0(void* vm, const void* error, const void* classInfo);   // VM: raise the error as an instance of the class
void FUN_14252f4f0(void* v);                                          // Value: tracer boolean conversion
char* FUN_1424f0d30(void* v, void* ok, long* out);                  // Value::Convert2SInt32 (CheckResult returned in *ok)
char* FUN_1424f1a30(void* v, void* ok, unsigned long* out);         // Value::Convert2UInt32
void FUN_1424d9640(void* ra, Scaleform::GFx::AS3::VM* vm, void* state, Scaleform::UInt32 argc);   // TR::ReadArgs::ReadArgs
void FUN_1424dea90(void* ra);                                                                         // TR::ReadArgs::~ReadArgs
void FUN_1424d9530(void* ra, Scaleform::GFx::AS3::VM* vm, Scaleform::UInt32 argc);                     // ReadArgs::ReadArgs
void FUN_1424de9e0(void* ra);                                          // ReadArgs::~ReadArgs
bool FUN_1425146d0(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* v, const void* traits);
Scaleform::UPInt FUN_14250ffc0(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* v);                 // the traits of a value
Scaleform::UPInt FUN_14250fa80(Scaleform::UPInt traits);                           // Traits::GetVT
void FUN_142500260(Scaleform::GFx::AS3::VM* vm, Scaleform::UInt32 index, Scaleform::UPInt traits, Scaleform::GFx::AS3::Value* obj);
void FUN_142501b00(Scaleform::GFx::AS3::PropRef* prop, Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* obj, const Scaleform::GFx::AS3::Multiname* mn, int mode);   // FindObjProperty
Scaleform::UPInt FUN_142508330(void* frame);
int FUN_142519a00(Scaleform::GFx::AS3::VM* vm, Scaleform::UPInt index, void* frame);
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_1425085b0(const Scaleform::GFx::AS3::SlotInfo* si, Scaleform::GFx::AS3::VM* vm);   // the slot's declared type
void FUN_142508720(const Scaleform::GFx::AS3::SlotInfo* si, Scaleform::GFx::ASString* name, Scaleform::GFx::AS3::VM* vm);       // its name
void FUN_14250e770(const void* si, void* ok, Scaleform::GFx::AS3::Value* result, Scaleform::GFx::AS3::Object* obj);             // SlotInfo: load into result
void FUN_142529720(const void* si, void* ok, Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* v, Scaleform::GFx::AS3::Object* obj);
void FUN_14251f710(Scaleform::UPInt block);   // Tracer: add a state slot
void FUN_1424e0b80(void* dst, const void* src);   // SlotInfo::operator=
void FUN_1426150b0(Scaleform::UPInt doc);   // DocView::SetAutoSizeX
void FUN_1426150d0(Scaleform::UPInt doc);   // DocView::SetAutoSizeY
void FUN_1425bc060(Scaleform::UPInt tf);   // TextField::SetDirtyFlag
void FUN_142511b00(Scaleform::UPInt tracer, Scaleform::UPInt* now, Scaleform::UPInt* old);   // Tracer: merge block states
char* FUN_142516c40(Scaleform::UPInt tracer, void* buf, Scaleform::UPInt* now, Scaleform::UPInt* old);   // Tracer: merge, result flag
void FUN_1425303b0(Scaleform::UPInt entry);   // shutdown of a registered entry
void FUN_1424ef2a0(Scaleform::UPInt array);   // ArrayDH::Clear
Scaleform::UPInt FUN_14250fa80(Scaleform::UPInt traits);   // Traits::GetVT
void FUN_1425282d0(Scaleform::UPInt vt, int index, Scaleform::UPInt arg, int argc, void* name);   // invoke slot
void FUN_14252e9d0(Scaleform::UPInt button, int buttonState);   // AvmButton::SwitchStateIntl
int FUN_1425de200(int mouseState);   // MouseState -> ButtonState
void FUN_1425048d0(Scaleform::UPInt movieRoot, const void* gfxValue, Scaleform::GFx::AS3::Value* out);   // MovieRoot::GFxValue2ASValue
void FUN_1424213b0(Scaleform::UPInt sparseArray, Scaleform::UInt32 ind, const Scaleform::GFx::AS3::Value* v);   // SparseArray::Set
void FUN_1423dfa20(void* obj);                                                                                                  // GC release of an object whose count reached its floor
Scaleform::GFx::AS3::ClassTraits::Traits** FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self, const Scaleform::GFx::ASString& name, const Scaleform::GFx::AS3::Instances::Namespace& ns);   // MultinameHash::Get
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142415520(void* globalObject, const Scaleform::GFx::ASString* name, const Scaleform::GFx::AS3::Instances::Namespace* ns);   // the global object's class of that name
void FUN_14251ccc0(Scaleform::GFx::AS3::TR::State* state, Scaleform::UPInt n);   // State::PopOp
void FUN_14251fcd0(Scaleform::UPInt tracer, Scaleform::UPInt regIndex);                    // Tracer: note register write

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

// An Error built by the exe's constructors (VM::Error::Error is functional in sfr_as3_15, so it is not linkable from here).
struct Sfr31Err
{
    alignas(8) char Buf[sizeof(VM::Error)];
    Sfr31Err(VM::ErrorID id, VM& vm, const Value& a)               { FUN_1424d6f40(Buf, id, &vm, &a); }
    Sfr31Err(VM::ErrorID id, VM& vm, const Value& a, const Value& b) { FUN_1424d6cf0(Buf, id, &vm, &a, &b); }
    Sfr31Err(VM::ErrorID id, VM& vm, const char* a, const Value& b) { FUN_1424d79f0(Buf, id, &vm, a, &b); }
    ~Sfr31Err()                         { Get().~Error(); }
    VM::Error& Get()                    { return *reinterpret_cast<VM::Error*>(Buf); }
    operator const VM::Error&()         { return Get(); }
};


// MS2-FUNCTIONAL 0x14252a460: header inline Value::SetUInt32; the exe inlines Release (weak-ref free) where ours calls the out-of-line ReleaseWeakRef.
// Out-of-line copies of header inlines that the exe emits as COMDATs; taking the address forces ours (pinned below).
void (Value::* volatile sfr27KeepSetUInt32)(UInt32) = &Value::SetUInt32;

// @0x14252e560
void Value::Swap(Value& other)
{
    const UInt32 flags = other.Flags;
    const Extra bonus = other.Bonus;
    const VU val = other.value;
    other.Flags = Flags;
    other.Bonus = Bonus;
    other.value = value;
    Flags = flags;
    Bonus = bonus;
    value = val;
}

// @0x142532280
void Object::constructor(Value& result)
{
    result.Assign(&GetTraits().GetConstructor());
}

// @0x142540bb0
void Class::prototypeGet(Value& result)
{
    result.Assign(&GetPrototype());
}

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
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
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
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrScratch t(static_cast<SInt32>(static_cast<char>(arg))); OpStack.PushBack(t.Get()); }
}

// @0x14253f640
void State::PushShort(SInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrScratch t(static_cast<SInt32>(arg)); OpStack.PushBack(t.Get()); }
}

// @0x14253f3b0
void State::PushInt(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kInt); t.SetInt(pool->ConstInt[ind]); OpStack.PushBack(t.Get()); }
}

// @0x14253f770
void State::PushUInt(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kUInt); t.SetUInt(pool->ConstUInt[ind]); OpStack.PushBack(t.Get()); }
}

// @0x14253f340
void State::PushDouble(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kNumber); t.SetNumber(pool->GetDouble(ind)); OpStack.PushBack(t.Get()); }
}

// @0x1425395f0
void State::PushObject(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x1f8)); OpStack.PushBack(t.Get()); }
}

// @0x14253c1a0
void State::PushObject2(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x1f8)); OpStack.PushBack(t.Get()); }
}

// @0x14253c8b0
void State::PushFunction(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x208)); OpStack.PushBack(t.Get()); }
}

// @0x14253a630
void State::PushBoolean2(UInt32 a, UInt32 b)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(a));
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(b));
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
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    Registers[ind].Assign(Value::GetUndefined());
    const UInt32 sh = ind & 7;
    RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] | (1u << sh));
    RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] & ~(1u << sh));
}


// ---- Tracer opcode handlers (free functions: `this` is the TR::State, ABI identical to the exe's member form) ----
struct StV
{
    explicit StV(void* st) : s(reinterpret_cast<UPInt>(st)) { }
    UPInt Tracer() const { return TrRd(s, 0); }
    Value* Ops() const { return reinterpret_cast<Value*>(TrRd(s, 0x38)); }
    UPInt NumOps() const { return TrRd(s, 0x40); }
    Value& Top() const { return Ops()[NumOps() - 1]; }
    Value& Below() const { return Ops()[NumOps() - 2]; }
    ArrayDH<Value>& OpStack() const { return *reinterpret_cast<ArrayDH<Value>*>(s + 0x38); }
    // The tracer's opcode array; its last entry is the opcode being specialized.
    UInt64& LastOp() const
    {
        UPInt* arr = reinterpret_cast<UPInt*>(TrRd(Tracer(), 0x28));
        return reinterpret_cast<UInt64*>(arr[0])[arr[1] - 1];
    }
    const UInt8* Code() const { return reinterpret_cast<const UInt8*>(TrRd(Tracer(), 0x50)); }
    UPInt s;
};

// The popped operand lives in raw storage: PopOpValue fills it in and the exe releases it at the end.
struct TrPopped
{
    Value& Get() { return *reinterpret_cast<Value*>(&w0); }
    UPInt w0, w1, w2, w3;
};

// Raw storage of a TR::ReadArgs (0x140 bytes), built and destroyed by the exe's own functions.
struct TrReadArgsRaw
{
    TrReadArgsRaw(VM* vm, void* st, UInt32 argc) { FUN_1424d9640(buf, vm, st, argc); }
    ~TrReadArgsRaw() { FUN_1424dea90(buf); }
    UInt8 buf[0x140];
};

// @0x14253af70
void Sfr27TraceIfTrueFalse(State* st, UInt64* pos, int op)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    if (FUN_142514000(tracer, &s.Top()))
        s.LastOp() = static_cast<UInt64>(op != 0x11) + 0x33;
    const int off = Abc::ReadS24<UInt8>(s.Code(), *pos);
    FUN_14251ccc0(st, 1);
    FUN_14252c9f0(tracer, *pos, st, off, 0xffffffff);
}

// @0x14253ad00
void Sfr27TraceIfCompare(State* st, UInt64* pos, UInt32 op)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    UInt64 newOp = op;
    if (FUN_142514c30(tracer, &s.Top()) && FUN_142514c30(tracer, &s.Below()))
    {
        switch (op)
        {
        case 0xc: newOp = 0x8a; break;
        case 0xd: newOp = 0x8b; break;
        case 0xe: newOp = 0x8c; break;
        case 0xf: newOp = 0x8d; break;
        case 0x13: case 0x19: newOp = 0x8e; break;
        case 0x14: case 0x1a: newOp = 0x9f; break;
        case 0x15: newOp = 0x9e; break;
        case 0x16: newOp = 0x9d; break;
        case 0x17: newOp = 0x9c; break;
        case 0x18: newOp = 0x8f; break;
        }
        s.LastOp() = newOp;
    }
    else if (FUN_142514470(tracer, &s.Top()) && FUN_142514470(tracer, &s.Below()))
    {
        switch (op)
        {
        case 0xc: newOp = 200; break;
        case 0xd: newOp = 0xc9; break;
        case 0xe: newOp = 0xca; break;
        case 0xf: newOp = 0xcb; break;
        case 0x13: case 0x19: newOp = 0xcc; break;
        case 0x14: case 0x1a: newOp = 0xbf; break;
        case 0x15: newOp = 0xbe; break;
        case 0x16: newOp = 0xbd; break;
        case 0x17: newOp = 0xbc; break;
        case 0x18: newOp = 0xcd; break;
        }
        s.LastOp() = newOp;
    }
    const int off = Abc::ReadS24<UInt8>(s.Code(), *pos);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    FUN_14252c9f0(tracer, *pos, st, off, 0xffffffff);
}

// @0x14253bd80
void Sfr27TraceJump(State* st, UInt64* pos)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    const int off = Abc::ReadS24<UInt8>(s.Code(), *pos);
    FUN_14252c9f0(tracer, *pos, st, off, 0xffffffff);
    FUN_1424e6aa0(tracer, st, *pos, 1, 1);
}

// @0x142540750
void Sfr27TraceLookupSwitch(State* st, UInt64* pos)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    FUN_14251ccc0(st, 1);
    const int base = static_cast<int>(TrRd(tracer, 0x38));
    int off = Abc::ReadS24<UInt8>(s.Code(), *pos);
    FUN_14252c9f0(tracer, *pos, st, (base - static_cast<int>(*pos)) + off, 1);
    const int caseCount = Abc::ReadU30<UInt8>(s.Code(), *pos);
    FUN_14251fcd0(tracer, static_cast<SPInt>(caseCount));
    for (int i = 0; i <= caseCount; ++i)
    {
        off = Abc::ReadS24<UInt8>(s.Code(), *pos);
        FUN_14252c9f0(tracer, *pos, st, (base - static_cast<int>(*pos)) + off, i + 3);
    }
    FUN_1424e6aa0(tracer, st, *pos, 1, 1);
}

// @0x14253bb30
void Sfr27TraceTopBoolean(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), static_cast<UInt32>(arg));
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x210));
    s.Top().Assign(t.Get());
}

// @0x14253f260
void Sfr27TraceCheckNumericOp(State* st)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    void* tr = FUN_14250fe80(st, &s.Top());
    const UPInt vm = TrVM(tracer);
    if (tr != reinterpret_cast<void*>(TrRd(TrRd(vm, 0x210), 0xc0)) &&
        tr != reinterpret_cast<void*>(TrRd(vm, 0x278)) && tr != reinterpret_cast<void*>(TrRd(vm, 0x270)))
    {
        if (!FUN_142514510(tracer, tr))
        {
            FUN_14251ccc0(st, 1);
            return;
        }
    }
    s.LastOp() = 0x6b;
    FUN_14251ccc0(st, 1);
}

// @0x142538280
void Sfr27TraceDup2Check(State* st)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    void* tr = FUN_14250fe80(st, &s.Top());
    const UPInt vm = TrVM(tracer);
    if (tr == reinterpret_cast<void*>(TrRd(TrRd(vm, 0x210), 0xc0)) ||
        tr == reinterpret_cast<void*>(TrRd(vm, 0x278)) || tr == reinterpret_cast<void*>(TrRd(vm, 0x270)) ||
        FUN_142514510(tracer, tr))
        s.LastOp() = 0x69;
    s.OpStack().PushBack(Value::GetUndefined());
    s.Top().Assign(s.Below());
}

// Two operands popped, one value of a builtin type pushed.
// @0x14253ab60
void Sfr27TracePop2PushInt(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x220));
    s.OpStack().PushBack(t.Get());
}

// @0x14253d3d0
void Sfr27TracePop2PushObject(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
}

// @0x14253c030
void Sfr27TraceNewArray(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, argc);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x238));
    s.OpStack().PushBack(t.Get());
}

// @0x14253cd00
void Sfr27TraceNewObject(State* st, int propCount)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), static_cast<SPInt>(propCount));
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, static_cast<UInt32>(propCount * 2));
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
}

// The first operand popped and dropped after noting a register/operand read.
// @0x142532f20
void Sfr27TracePopNote(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), arg);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    popped.Get().~Value();
}

// @0x1425379f0
void Sfr27TraceConvertTopBoolean(State* st)
{
    StV s(st);
    Value& top = s.Top();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        FUN_14252f4f0(&top);
        return;
    }
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x210));
    top.Assign(t.Get());
}

// @0x142537ab0
void Sfr27TraceConvertTopNumber(State* st)
{
    StV s(st);
    Value& top = s.Top();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        top.ToNumberValueInline();
        return;
    }
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x218));
    top.Assign(t.Get());
}

// @0x142537b70
void Sfr27TraceConvertTopInt(State* st)
{
    StV s(st);
    Value& top = s.Top();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        SInt32 result;
        CheckResult ok(false);
        if (*FUN_1424f0d30(&top, &ok, &result))
            top.SetSInt32(result);
        return;
    }
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x220));
    top.Assign(t.Get());
}

// @0x142537e00
void Sfr27TraceConvertTopUInt(State* st)
{
    StV s(st);
    Value& top = s.Top();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        UInt32 result;
        CheckResult ok(false);
        if (*FUN_1424f1a30(&top, &ok, &result))
            top.SetUInt32(result);
        return;
    }
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x228));
    top.Assign(t.Get());
}


#define SFR27_TOP_OP(Name, Off) \
    void State::Name() \
    { \
        Value tv(TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Value::NotNull); \
        OpStack[OpStack.GetSize() - 1].Assign(tv); \
    }
#define SFR27_POP2_OP(Name, Off) \
    void State::Name() \
    { \
        TrPopped popped; \
        FUN_14251cd30(this, &popped.Get()); \
        Value tv(TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Value::NotNull); \
        OpStack[OpStack.GetSize() - 1].Assign(tv); \
        popped.Get().~Value(); \
    }
#define SFR27_REG_OP(Name, Off) \
    void State::Name(UInt32 ind) \
    { \
        Value tv(TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Value::NotNull); \
        Registers[ind].Assign(tv); \
    }

// @0x142532670
SFR27_TOP_OP(TopNumber, 0x218)
// @0x142532710
SFR27_TOP_OP(TopInt, 0x220)
// @0x1425327b0
SFR27_TOP_OP(TopString, 0x230)
// @0x142532850
SFR27_POP2_OP(Pop2Boolean, 0x210)
// @0x142532930
SFR27_POP2_OP(Pop2Number, 0x218)
// @0x142532a10
SFR27_POP2_OP(Pop2Int, 0x220)
// @0x142532af0
SFR27_POP2_OP(Pop2UInt, 0x228)
// @0x142537c50
SFR27_REG_OP(RegNumber, 0x218)
// @0x142537ce0
SFR27_REG_OP(RegInt, 0x220)
// @0x142537d70
SFR27_REG_OP(RegUInt, 0x228)

// dxns / dxnslate: the method must set the SETS_DXNS flag (and XML support must be enabled).
static inline void TraceCheckSetsDxns(State* st, const char* disabledName, UInt32 arg, bool pop)
{
    const UPInt tracer = TrRd(reinterpret_cast<UPInt>(st), 0);
    UPInt link = TrAbcLink(tracer);
    const char* what;
    if (*reinterpret_cast<const char*>(TrRd(TrRd(link, 0x20), 0x40) + 0x20) == 0)
        what = disabledName;
    else
    {
        if (pop)
            FUN_14251ccc0(st, 1);
        else
            FUN_14251fcd0(tracer, arg);
        link = TrAbcLink(tracer);
        const UPInt file = TrRd(link, 0x28);
        const int methodIndex = *reinterpret_cast<const int*>(TrRd(tracer, 0x20) + 0x30);
        const UPInt method = TrRd(TrRd(file, 0x170), static_cast<SPInt>(methodIndex) * 8);
        const int bodyIndex = *reinterpret_cast<const int*>(method + 0x18);
        const UPInt body = TrRd(TrRd(file, 0xf8), static_cast<SPInt>(bodyIndex) * 8);
        if (*reinterpret_cast<const UInt8*>(body) & 0x40)
            return;
        what = "does not have the SETS_DXNS flag set";
    }
    VM& vm = *reinterpret_cast<VM*>(TrRd(link, 0x20));
    vm.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), vm, what));
}

// @0x1425383d0
void Sfr27TraceDxns(State* st, UInt32 arg) { TraceCheckSetsDxns(st, "dxns", arg, false); }
// @0x142538490
void Sfr27TraceDxnsLate(State* st) { TraceCheckSetsDxns(st, "dxnslate", 0, true); }

} // namespace TR

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace AS3 {

// @0x14252ec90
void VM::ThrowArgumentError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ArgumentErrorCI); }
// @0x14252eca0
void VM::ThrowError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ErrorCI); }
// @0x14252efc0
void VM::ThrowEvalError(const Error& e) { FUN_14252ecb0(this, &e, &fl::EvalErrorCI); }
// @0x14252f1a0
void VM::ThrowRangeError(const Error& e) { FUN_14252ecb0(this, &e, &fl::RangeErrorCI); }
// @0x14252f1b0
void VM::ThrowReferenceError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ReferenceErrorCI); }
// @0x14252f1e0
void VM::ThrowTypeError(const Error& e) { FUN_14252ecb0(this, &e, &fl::TypeErrorCI); }
// @0x14252f1f0
void VM::ThrowURIError(const Error& e) { FUN_14252ecb0(this, &e, &fl::URIErrorCI); }
// @0x14252f210
void VM::ThrowVerifyError(const Error& e) { FUN_14252ecb0(this, &e, &fl::VerifyErrorCI); }

// ---- Interpreter opcode handlers (free functions; the VM is the first argument as in the exe) ----

// Raw storage of a (TR::)ReadArgs: constructed and destroyed by the exe's own out-of-line functions.
struct RA
{
    RA(VM* vm, UInt32 argc) { FUN_1424d9530(buf, vm, argc); }
    ~RA() { FUN_1424de9e0(buf); }
    ValueStack& Stk() { return **reinterpret_cast<ValueStack**>(buf + 8); }
    UInt32 ArgNum() const { return *reinterpret_cast<const UInt32*>(buf + 0x10); }
    const Value* Argv() { return ArgNum() > 8 ? *reinterpret_cast<const Value**>(buf + 0x118) : reinterpret_cast<const Value*>(buf + 0x18); }
    UInt8 buf[0x140];
};

// null or undefined where an object is needed: TypeError 1009 / 1010
static inline void ExecRequireObject(VM& vm, const Value& v)
{
    const UInt32 k = static_cast<UInt32>(v.GetKind());
    if (k == 0 || (k - 0xc < 4 && v.GetGASRefCountBase() == NULL))
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(k - 0xc < 4 ? 0x3f1 : 0x3f2), vm));
}

// VM::Convert check used by astype/coerce handlers (returns whether value can be converted to the traits).

// The class operand popped: a value not convertible to its type becomes null.
// @0x142533300
void Sfr27ExecAsType(VM* vm)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value* below = stk.GetTopPtr() - 1;
    Value y;
    y.Pick(stk);
    if (y.GetKind() == Value::kClass)
    {
        if (!FUN_1425146d0(vm, below, &y.AsClass().GetTraits()))
            below->SetNull();
    }
    else
    {
        const UInt32 k = static_cast<UInt32>(y.GetKind());
        if (k != 0 && (k - 0xc >= 4 || y.GetGASRefCountBase() != NULL))
            vm->ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x411), *vm));
        else
            ExecRequireObject(*vm, y);
    }
}

// call: function, receiver and argc arguments popped; the result is dropped.
// @0x142533680
void Sfr27ExecCallVoid(VM* vm, UInt32 argc)
{
    RA args(vm, argc);
    Value receiver;
    receiver.Pick(args.Stk());
    ExecRequireObject(*vm, receiver);
    Value func;
    func.Pick(args.Stk());
    if (vm->IsException())
        return;
    Value result(Value::GetUndefined());
    vm->ExecuteInternalUnsafe(func, receiver, result, argc, args.Argv(), true);
}

// callmethod: receiver and argc arguments popped; the method comes from the receiver's method table.
// @0x142533980
void Sfr27ExecCallMethod(VM* vm, UInt32 methodIndex, UInt32 argc)
{
    RA args(vm, argc);
    Value receiver;
    receiver.Pick(args.Stk());
    ExecRequireObject(*vm, receiver);
    if (vm->IsException())
        return;
    const UPInt traits = FUN_14250ffc0(vm, &receiver);
    const UPInt vt = FUN_14250fa80(traits);
    Value func;
    vm->ExecuteInternalUnsafe(*reinterpret_cast<Value*>(*reinterpret_cast<UPInt*>(vt + 8) + methodIndex * 0x20ULL),
                              receiver, func, 0, NULL, false);
    if (!vm->IsException())
    {
        Value result(Value::GetUndefined());
        vm->ExecuteInternalUnsafe(func, receiver, result, argc, args.Argv(), true);
    }
}


static inline UPInt VmRd(VM* vm, UPInt off) { return *reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(vm) + off); }

// Push a copy of v on the VM's operand stack (VM +0x50 is the top-of-stack pointer).
static inline Value* ExecPushCopy(VM* vm, const Value& v)
{
    Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    ++cur;
    return new (cur) Value(v);
}

// getscopeobject: the scope entry of the frame at index.
// @0x142539af0
void Sfr27ExecGetScopeObject(VM* vm, void* frame, UInt32 index)
{
    UPInt* scopes = *reinterpret_cast<UPInt**>(reinterpret_cast<UPInt>(frame) + 0x38);
    if (scopes == NULL || scopes[1] <= index)
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x7d6), *vm));
        return;
    }
    ExecPushCopy(vm, reinterpret_cast<Value*>(scopes[0])[index]);
}

// getouterscope-style read of the VM scope stack at the frame's scope base plus index.
// @0x142539e20
void Sfr27ExecGetScopeStack(VM* vm, void* frame, UInt32 index)
{
    const UPInt pos = static_cast<UPInt>(index) + *reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(frame) + 8);
    if (VmRd(vm, 0x168) <= pos)
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x7d6), *vm));
        return;
    }
    Value* pushed = ExecPushCopy(vm, reinterpret_cast<Value*>(VmRd(vm, 0x160))[pos]);
    *reinterpret_cast<UInt32*>(pushed) &= 0xfffffeff;
}


// The innermost call frame of the VM (the paged call stack: VM +0x78 frames, 64 per page of 0xa8-byte frames), or 0.
static inline UPInt ExecTopFrame(VM* vm)
{
    const UPInt count = VmRd(vm, 0x78);
    if (count == 0)
        return 0;
    const UPInt i = count - 1;
    return (i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8);
}

// The object the frame runs in: the first scope object, else the frame's this when that is an object.
static inline Object* ExecFrameObject(VM* vm)
{
    const UPInt frame = ExecTopFrame(vm);
    if (frame == 0)
        return NULL;
    const UPInt* scopes = *reinterpret_cast<const UPInt* const*>(frame + 0x38);
    if (scopes != NULL && scopes[1] != 0)
        return *reinterpret_cast<Object* const*>(scopes[0] + 0x10);
    const Value* self = *reinterpret_cast<Value* const*>(*reinterpret_cast<const UPInt*>(frame + 0x18) + 8);
    if (static_cast<UInt32>(self->GetKind()) - 0xc < 4)
        return reinterpret_cast<Object*>(self->GetGASRefCountBase());
    return NULL;
}

static inline const SlotInfo& ExecSlotOf(Object* obj, SPInt slot, bool relativeToOwn)
{
    Traits& tr = obj->GetTraits();
    SPInt ind = slot - 1;
    if (relativeToOwn)
        ind += tr.FirstOwnSlotInd.Get();
    return tr.GetSlotInfo(AbsoluteIndex(ind));
}

// getglobalslot: pushes undefined, then loads the global object's slot into it.
// @0x142539490
void Sfr27ExecGetGlobalSlot(VM* vm, UInt32 slot)
{
    Value* top = ExecPushCopy(vm, Value::GetUndefined());
    Object* obj = ExecFrameObject(vm);
    CheckResult ok(false);
    FUN_14250e770(&ExecSlotOf(obj, slot, true), &ok, top, obj);
}

// getslot: the object on top of the stack is replaced by the value of its slot.
// @0x142538f50
void Sfr27ExecGetSlot(VM* vm, SPInt slot)
{
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    ExecRequireObject(*vm, *top);
    if (vm->IsException())
        return;
    Value saved(*top, PickValue);
    Object* obj = reinterpret_cast<Object*>(saved.GetGASRefCountBase());
    CheckResult ok(false);
    FUN_14250e770(&ExecSlotOf(obj, slot, false), &ok, top, obj);
}

// setglobalslot: the value on top of the stack is stored into the global object's slot and popped.
// @0x14253fc90
void Sfr27ExecSetGlobalSlot(VM* vm, UInt32 slot)
{
    Object* obj = ExecFrameObject(vm);
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    CheckResult ok(false);
    FUN_142529720(&ExecSlotOf(obj, slot, true), &ok, vm, top, obj);
    Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    cur->~Value();
    --cur;
}

// getslot for objects whose slots follow the traits' first own slot.
// @0x14253a2d0
void Sfr27ExecGetOwnSlot(VM* vm, UInt32 slot)
{
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    ExecRequireObject(*vm, *top);
    if (vm->IsException())
        return;
    Value saved(*top, PickValue);
    Object* obj = reinterpret_cast<Object*>(saved.GetGASRefCountBase());
    CheckResult ok(false);
    FUN_14250e770(&ExecSlotOf(obj, slot, true), &ok, top, obj);
}

// setslot: value and object popped, the object's slot receives the value.
// @0x14253faa0
void Sfr27ExecSetSlot(VM* vm, SPInt slot)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value value;
    value.Pick(stk);
    Value self;
    self.Pick(stk);
    ExecRequireObject(*vm, self);
    if (vm->IsException())
        return;
    Object* obj = reinterpret_cast<Object*>(self.GetGASRefCountBase());
    CheckResult ok(false);
    FUN_142529720(&ExecSlotOf(obj, slot, false), &ok, &obj->GetVM(), &value, obj);
}


// ---- SlotInfo::SetSlotValue (two entry points: with the receiver's Value and VTable, or with the Object) ----

// The out-of-line helpers write an ASString into raw storage they initialize themselves.
struct RawASString
{
    ASString& Get() { return *reinterpret_cast<ASString*>(&node); }
    ~RawASString() { Get().~ASString(); }
    UPInt node;
};

// The value stored through a bound slot: one case per binding kind (the data lives at obj + ValueInd, or in the
// global object's value array for BT_ValueArray). Returns false for unbound or read-only kinds.
static bool SlotStoreBound(const SlotInfo& si, Object* obj, const Value& v)
{
    const UPInt base = reinterpret_cast<UPInt>(obj);
    const SInt32 ind = si.ValueInd;
    // the payload words of the (already coerced) value
    const UPInt* raw = reinterpret_cast<const UPInt*>(&v);
    switch (si.BindType)
    {
    case SlotInfo::BT_ValueArray:
        reinterpret_cast<Value*>(*reinterpret_cast<UPInt*>(base + 0xa8))[ind].Assign(v);
        return true;
    case SlotInfo::BT_Value:
        reinterpret_cast<Value*>(base + ind)->Assign(v);
        return true;
    case SlotInfo::BT_ObjectAS:
        reinterpret_cast<STPtr*>(base + ind)->SetValue(v);
        return true;
    case SlotInfo::BT_ObjectCpp:
    {
        UPInt* slot = reinterpret_cast<UPInt*>(base + ind);
        const UPInt np = raw[2];
        if (np != *slot)
        {
            const UPInt old = *slot;
            if (old != 0)
            {
                if ((old & 1) == 0)
                {
                    UInt32* rc = reinterpret_cast<UInt32*>(old + 0x10);
                    if ((*rc & 0x3fffff) != 0)
                    {
                        --*rc;
                        FUN_1423dfa20(reinterpret_cast<void*>(old));
                    }
                }
                else
                    *slot = old - 1;
            }
            if (np != 0)
            {
                UInt32* rc = reinterpret_cast<UInt32*>(np + 0x10);
                *rc = (*rc + 1) & 0x8fbfffff;
            }
            *slot = np;
        }
        return true;
    }
    case SlotInfo::BT_Boolean:
        *reinterpret_cast<UInt8*>(base + ind) = static_cast<UInt8>(raw[2]);
        return true;
    case SlotInfo::BT_Int:
    case SlotInfo::BT_UInt:
        *reinterpret_cast<UInt32*>(base + ind) = static_cast<UInt32>(raw[2]);
        return true;
    case SlotInfo::BT_Number:
        *reinterpret_cast<UPInt*>(base + ind) = raw[2];
        return true;
    case SlotInfo::BT_String:
    {
        ASStringNode** slot = reinterpret_cast<ASStringNode**>(base + ind);
        ASStringNode* old = *slot;
        ASStringNode* ns = reinterpret_cast<ASStringNode*>(raw[2]);
        if (old != NULL)
            old->Release();
        *slot = ns;
        if (ns != NULL)
            ns->AddRef();
        return true;
    }
    }
    return false;
}

// The bound class's traits, coerce the value to the slot's declared type (unless it is a class).
// Returns false (after throwing) when the type is unknown or the value does not fit.
static bool SlotCoerceForStore(const SlotInfo* si, VM* vm, const Value& v, Value& coerced)
{
    if (v.GetKind() != Value::kClass && si->BindType <= 10)
    {
        ClassTraits::Traits* ct = FUN_1425085b0(si, vm);
        if (ct == NULL)
        {
            RawASString typeName;
            FUN_142508720(si, &typeName.Get(), vm);
            Value tv(typeName.Get());
            vm->ThrowVerifyError(Sfr31Err(static_cast<VM::ErrorID>(0x3f6), *vm, tv));
            return false;
        }
        if (!ct->Coerce(v, coerced))
        {
            RawASString typeName;
            FUN_142508720(si, &typeName.Get(), vm);
            Value tv(typeName.Get());
            vm->ThrowTypeError(Sfr31Err(static_cast<VM::ErrorID>(0x40a), *vm, v, tv));
            return false;
        }
        return true;
    }
    coerced.Assign(v);
    return true;
}

// Store v into slot si of the object held by thisV (setters run with thisV as receiver).
// @0x142529030
char* Sfr27SlotSetValueThis(const SlotInfo* si, char* ret, VM* vm, const Value* v, const Value* thisV, VTable* vt)
{
    if (si->ReadOnly && static_cast<int>(VmRd(vm, 0x30)) < 1)
    {
        vm->ThrowReferenceError(Sfr31Err(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData, *thisV));
        *ret = 0;
        return ret;
    }
    Value coerced;
    if (!SlotCoerceForStore(si, vm, *v, coerced))
    {
        *ret = 0;
        return ret;
    }
    Object* obj = reinterpret_cast<Object*>(thisV->GetGASRefCountBase());
    switch (si->BindType)
    {
    case SlotInfo::BT_ValueArray: case SlotInfo::BT_Value: case SlotInfo::BT_ObjectAS: case SlotInfo::BT_ObjectCpp:
    case SlotInfo::BT_Boolean: case SlotInfo::BT_Int: case SlotInfo::BT_UInt: case SlotInfo::BT_Number:
    case SlotInfo::BT_String:
        *ret = SlotStoreBound(*si, obj, coerced);
        break;
    case 10: case SlotInfo::BT_Get:
        vm->ThrowReferenceError(Sfr31Err(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData, *thisV));
        *ret = 0;
        break;
    case SlotInfo::BT_Code:
    {
        const UInt32 k = static_cast<UInt32>(thisV->GetKind());
        const bool primitive = k < 5 || k == 10;
        vm->ThrowReferenceError(Sfr31Err(static_cast<VM::ErrorID>(primitive ? 0x420 : 0x40d), *vm, si->Name->pData, *thisV));
        *ret = 0;
        break;
    }
    case SlotInfo::BT_Set: case SlotInfo::BT_GetSet:
    {
        if (vt == NULL)
            vt = reinterpret_cast<VTable*>(FUN_14250fa80(FUN_14250ffc0(vm, thisV)));
        Value setter = vt->GetValue(AbsoluteIndex(si->ValueInd + 1));
        const UInt32 sk = static_cast<UInt32>(setter.GetKind());
        if (sk < 0xc && sk - 5 > 2)
        {
            vm->ThrowTypeError(Sfr31Err(static_cast<VM::ErrorID>(0x3ee), *vm, setter));
            *ret = 0;
        }
        else
        {
            Value result(Value::GetUndefined());
            vm->ExecuteInternalUnsafe(setter, *thisV, result, 1, &coerced, false);
            *ret = vm->IsException() ? 0 : 1;
        }
        break;
    }
    default:
        *ret = 0;
        break;
    }
    return ret;
}

// The same for an Object receiver; the error texts name the object's traits.
// @0x142529720
char* Sfr27SlotSetValueObj(const SlotInfo* si, char* ret, VM* vm, const Value* v, Object* obj)
{
    if (si->ReadOnly && static_cast<int>(VmRd(vm, 0x30)) < 1)
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData,
                                          obj->GetTraits().GetName().ToCStr()));
        *ret = 0;
        return ret;
    }
    Value coerced;
    if (!SlotCoerceForStore(si, vm, *v, coerced))
    {
        *ret = 0;
        return ret;
    }
    switch (si->BindType)
    {
    case SlotInfo::BT_ValueArray: case SlotInfo::BT_Value: case SlotInfo::BT_ObjectAS: case SlotInfo::BT_ObjectCpp:
    case SlotInfo::BT_Boolean: case SlotInfo::BT_Int: case SlotInfo::BT_UInt: case SlotInfo::BT_Number:
    case SlotInfo::BT_String:
        *ret = SlotStoreBound(*si, obj, coerced);
        break;
    case 10: case SlotInfo::BT_Get:
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData,
                                          obj->GetTraits().GetName().ToCStr()));
        *ret = 1;
        break;
    case SlotInfo::BT_Code:
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x40d), *vm, si->Name->pData,
                                          obj->GetTraits().GetName().ToCStr()));
        *ret = 0;
        break;
    case SlotInfo::BT_Set: case SlotInfo::BT_GetSet:
    {
        VTable* vt = reinterpret_cast<VTable*>(FUN_14250fa80(reinterpret_cast<UPInt>(&obj->GetTraits())));
        Value setter = vt->GetValue(AbsoluteIndex(si->ValueInd + 1));
        const UInt32 sk = static_cast<UInt32>(setter.GetKind());
        if (sk < 0xc && sk - 5 > 2)
        {
            vm->ThrowTypeError(Sfr31Err(static_cast<VM::ErrorID>(0x3ee), *vm, setter));
            *ret = 0;
        }
        else
        {
            Value result(Value::GetUndefined());
            Value self(obj);
            vm->ExecuteInternalUnsafe(setter, self, result, 1, &coerced, false);
            *ret = vm->IsException() ? 0 : 1;
        }
        break;
    }
    default:
        *ret = 0;
        break;
    }
    return ret;
}


// throw: the exception object is taken off the stack, then the frame's handler table is searched.
// @0x142540850
int Sfr27ExecThrow(VM* vm, UInt64* pc, CallFrame* frame)
{
    vm->ExceptionObj.Pick(*reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48));
    const UPInt* code = reinterpret_cast<const UPInt*>(FUN_142508330(frame));
    return FUN_142519a00(vm, (reinterpret_cast<UPInt>(pc) - *code) >> 3, frame);
}

// typeof: the value on top of the stack is replaced by the name of its type.
// @0x142540910
void Sfr27ExecTypeOf(VM* vm)
{
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    SPInt idx;
    switch (static_cast<UInt32>(top->GetKind()))
    {
    case 0: idx = 1; break;
    case 1: idx = 6; break;
    case 2: case 3: case 4: idx = 7; break;
    case 5: case 7: case 0xe: case 0xf: case 0x10: case 0x11: idx = 9; break;
    case 10:
        idx = top->GetGASRefCountBase() == NULL ? 10 : 8;
        break;
    case 0xb: case 0xc:
    {
        const UPInt traits = FUN_14250ffc0(vm, top);
        idx = static_cast<UInt32>(*reinterpret_cast<const int*>(traits + 0x70) - 0xd) < 2 ? 11 : 10;
        break;
    }
    default: idx = 0xc; break;
    }
    top->Assign(reinterpret_cast<ASStringNode**>(&vm->GetStringManager())[idx]);
}


// A PropRef that found nothing: no this value, or an empty dynamic/closure tag.
static inline bool PropRefNotFound(const PropRef& p)
{
    const UPInt w = reinterpret_cast<UPInt>(p.pValue);
    return p.This.GetKind() == Value::kUndefined || w == 1 || w == 2;
}

// Object.SetProperty: a fixed slot, an existing dynamic value, or a new dynamic property.
// MS2-FUNCTIONAL 0x142528a50: same lookup and branches; the exe inlines the Value temporaries differently (frame differs).
// @0x142528a50
CheckResult Object::SetProperty(const Multiname& prop_name, const Value& value)
{
    VM& vm = GetVM();
    PropRef prop;
    {
        Value self(this);
        FUN_142501b00(&prop, &vm, &self, &prop_name, 1);
    }
    if (PropRefNotFound(prop))
    {
        if (!pTraits->IsDynamic() || !prop_name.ContainsNamespace(vm.GetPublicNamespace()))
        {
            vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x420), vm, prop_name.Name,
                                             GetTraits().GetName().ToCStr()));
            return CheckResult(false);
        }
        AddDynamicSlotValuePair(prop_name.Name, value);
        return CheckResult(true);
    }
    switch (reinterpret_cast<UPInt>(prop.pValue) & 3)
    {
    case 0:
    {
        CheckResult ok(false);
        Sfr27SlotSetValueThis(prop.pSI, reinterpret_cast<char*>(&ok), &vm, &value, &prop.This, NULL);
        return ok;
    }
    case 1:
        reinterpret_cast<Value*>(reinterpret_cast<UPInt>(prop.pValue) & ~static_cast<UPInt>(1))->Assign(value);
        return CheckResult(true);
    case 2:
        return CheckResult(false);
    }
    return CheckResult(true);
}

// setproperty on any value: objects with special property handling take it themselves, the rest go through
// the property lookup.
// @0x142528810
char* Sfr27SetPropertyOfValue(char* ret, VM* vm, const Value* obj, const Multiname* mn, const Value* v)
{
    if (static_cast<UInt32>(obj->GetKind()) - 0xc < 4)
    {
        Object* o = reinterpret_cast<Object*>(obj->GetGASRefCountBase());
        Traits& tr = o->GetTraits();
        const UPInt flags = static_cast<UPInt>(tr.Flags);
        const int type = static_cast<int>(tr.TraitsType);
        if ((flags & 1) != 0 || (static_cast<UInt32>(type - 0xd) < 2 && ((~(flags >> 5)) & 1) != 0))
        {
            *ret = o->SetProperty(*mn, *v) ? 1 : 0;
            return ret;
        }
    }
    PropRef prop;
    FUN_142501b00(&prop, vm, obj, mn, 1);
    if (PropRefNotFound(prop))
    {
        if (static_cast<UInt32>(obj->GetKind()) - 0xc < 4 &&
            (reinterpret_cast<Object*>(obj->GetGASRefCountBase())->GetTraits().Flags >> 1 & 1) != 0 &&
            mn->ContainsNamespace(vm->GetPublicNamespace()))
        {
            reinterpret_cast<Object*>(obj->GetGASRefCountBase())->AddDynamicSlotValuePair(mn->Name, *v);
            *ret = 1;
        }
        else
        {
            Traits* tr = reinterpret_cast<Traits*>(FUN_14250ffc0(vm, obj));
            vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x420), *vm, mn->Name, tr->GetName().ToCStr()));
            *ret = 0;
        }
        return ret;
    }
    char r = 1;
    switch (reinterpret_cast<UPInt>(prop.pValue) & 3)
    {
    case 0:
        Sfr27SlotSetValueThis(prop.pSI, &r, vm, v, &prop.This, NULL);
        break;
    case 1:
        reinterpret_cast<Value*>(reinterpret_cast<UPInt>(prop.pValue) & ~static_cast<UPInt>(1))->Assign(*v);
        break;
    case 2:
        r = 0;
        break;
    }
    *ret = r;
    return ret;
}

// A run-time multiname taken from a QName object: its name and namespace.
// @0x1425273b0
void Sfr27MultinameFromQName(Multiname* mn, const Value* v)
{
    const UPInt q = reinterpret_cast<UPInt>(v->GetGASRefCountBase());
    mn->Name.Assign(*reinterpret_cast<const ASString*>(q + 0x38));
    if (mn->Name.GetKind() == Value::kString)
    {
        ASStringNode* node = reinterpret_cast<ASStringNode*>(mn->Name.GetGASRefCountBase());
        node->AddRef();
        if (node->Size != 0 && node->pData[0] == '*')
            mn->Name.Assign(reinterpret_cast<ASStringNode*>(reinterpret_cast<UPInt>(node->pManager) + 0x40));
        node->Release();
    }
    mn->Obj = reinterpret_cast<GASRefCountBase*>(*reinterpret_cast<UPInt*>(q + 0x40));
    *reinterpret_cast<UInt32*>(mn) &= 0xfffffff9;
}

// @0x142528cc0
void Multiname::SetRTNameUnsafe(const Value& v)
{
    const UInt32 k = static_cast<UInt32>(v.GetKind());
    if (k - 0xc < 4 && v.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(v.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && ((~(static_cast<UPInt>(tr.Flags) >> 5)) & 1) != 0)
        {
            Sfr27MultinameFromQName(this, &v);
            return;
        }
    }
    Name.AssignUnsafe(v);
    PostProcessName(false);
}


// setslot for objects whose slots follow the traits' first own slot.
// @0x1425402a0
void Sfr27ExecSetOwnSlot(VM* vm, UInt32 slot)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value value;
    value.Pick(stk);
    Value self;
    self.Pick(stk);
    ExecRequireObject(*vm, self);
    if (vm->IsException())
        return;
    Object* obj = reinterpret_cast<Object*>(self.GetGASRefCountBase());
    CheckResult ok(false);
    FUN_142529720(&ExecSlotOf(obj, slot, true), &ok, &obj->GetVM(), &value, obj);
}

// initslot: setslot with read-only checks off (the VM is counted as inside an initializer).
// @0x14253b420
void Sfr27ExecInitSlot(VM* vm, SPInt slot)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value value;
    value.Pick(stk);
    Value self;
    self.Pick(stk);
    ExecRequireObject(*vm, self);
    if (vm->IsException())
        return;
    int& inInitializer = *reinterpret_cast<int*>(reinterpret_cast<UPInt>(vm) + 0x30);
    ++inInitializer;
    Object* obj = reinterpret_cast<Object*>(self.GetGASRefCountBase());
    CheckResult ok(false);
    FUN_142529720(&ExecSlotOf(obj, slot, false), &ok, &obj->GetVM(), &value, obj);
    --inInitializer;
}


// Makes room for n more values, moving to a new page when the current one is full.
// @0x1425241f0
void ValueStack::Reserve(UInt16 n)
{
    Page* page = pCurrentPage;
    Value* stack;
    if (pCurrent + n < page->Values + page->PageSize)
        stack = pCurrent + 1;
    else
    {
        Page* np = NewPage(n);
        np->pNext = NULL;
        np->pPrev = pCurrentPage;
        pCurrentPage->pNext = np;
        pCurrentPage->pCurrent = pCurrent;
        pCurrentPage->pFirst = pStack;
        stack = np->Values;
        pCurrentPage = np;
        pCurrent = np->Values - 1;
    }
    pStack = stack;
    ReservedNum = n;
    ++pCurrentPage->ReservationNum;
}

// Reserves the num registers of a new call frame.
// @0x1425240e0
void ValueRegisterFile::Reserve(UInt16 num)
{
    const UInt16 used = Unk00;
    Page* page = pCurrentPage;
    UInt16 previousSize = 0;
    Value* regs;
    if (page->PageSize < static_cast<UInt32>(used) + num)
    {
        Page* np = NewPage(num);
        np->pNext = NULL;
        np->pPrev = pCurrentPage;
        pCurrentPage->pNext = np;
        pCurrentPage->ReservedNum = Unk00;
        pCurrentPage->pCurrent = pRF;
        pCurrentPage = np;
        regs = np->Values;
        Unk00 = num;
    }
    else
    {
        previousSize = static_cast<UInt16>(used - (pRF - page->Values));
        regs = page->Values + used;
        Unk00 = static_cast<UInt16>(used + num);
    }
    pRF = regs;
    GetReservations(pCurrentPage)[pCurrentPage->CurrPos] = previousSize;
    ++pCurrentPage->CurrPos;
    for (UInt32 i = 0; i < num; ++i)
    {
        *reinterpret_cast<UInt32*>(&regs[i]) = 0;
        reinterpret_cast<UPInt*>(&regs[i])[1] = 0;
    }
}


// The class traits registered under name and namespace; looked up in the global object's classes on a miss
// (and then cached).
// @0x1425251e0
ClassTraits::Traits* Sfr27GetClassTraitsByName(VM* vm, const ASString* name, const Instances::Namespace* ns)
{
    ClassTraits::Traits** found = FUN_142414ac0(&vm->ClassTraitsSet, *name, *ns);
    ClassTraits::Traits* ct = found != NULL ? *found : NULL;
    if (ct == NULL)
    {
        ct = FUN_142415520(reinterpret_cast<void*>(VmRd(vm, 0x298)), name, ns);
        if (ct != NULL)
            vm->ClassTraitsSet.Add(*name, *ns, ct);
    }
    return ct;
}


// The traits' slot ind receives v for obj.
// @0x142529eb0
char* Sfr27TraitsSetSlotValue(Traits* tr, char* ret, SPInt ind, Value* v, Object* obj)
{
    Sfr27SlotSetValueObj(&tr->GetSlotInfo(AbsoluteIndex(ind)), ret, &tr->GetVM(), v, obj);
    return ret;
}

// Object slot number slot (1-based, counted from the traits' first own slot) receives v.
// @0x142528f80
char* Sfr27ObjectSetSlotValue(Object* obj, char* ret, UInt32 slot, Value* v)
{
    Traits& tr = obj->GetTraits();
    return Sfr27TraitsSetSlotValue(&tr, ret, static_cast<SPInt>(slot) - 1 + tr.FirstOwnSlotInd.Get(), v, obj);
}

// AS3 Array object: sets its length (GFx::Value::ObjectInterface::SetArraySize).
// @0x1425265d0
bool Sfr27ObjectInterfaceSetArraySize(void* self, UPInt obj, UInt32 size)
{
    FUN_14241fe30(reinterpret_cast<void*>(obj + 0x38), size);
    return true;
}

// The tag bits an object address carries for this value (no exe address of its own: inlined everywhere).
Value::ObjectTag Value::GetObjectTag() const
{
    switch (GetKind())
    {
    case kFunction:  return otFunction;
    case kObject:    return otObject;
    case kClass:     return otClass;
    case kNamespace: return otNamespace;
    default:         break;
    }
    return otInvalid;
}

void STPtr::AddRef() const
{
    if (pObject)
        GetRawAddr()->AddRef();
}

void STPtr::Release() const
{
    if (pObject)
        GetRawAddr()->Release();
}


// The button's up state receives obj.
// @0x14252a4e0
void Sfr31ButtonSetUpState(void* button, void* obj) { FUN_142529f70(button, 0, obj); }

// The same for the over state.
// @0x1425287b0
void Sfr31ButtonSetOverState(void* button, void* obj) { FUN_142529f70(button, 1, obj); }

// The same for the down state.
// @0x1425272f0
void Sfr31ButtonSetDownState(void* button, void* obj) { FUN_142529f70(button, 2, obj); }

// The same for the hit-test state.
// @0x142527490
void Sfr31ButtonSetHitTestState(void* button, void* obj) { FUN_142529f70(button, 3, obj); }

// Two bounds with -1 meaning the default (0 and 1000); the second is stored twice.
// @0x1425287c0
void Sfr31SetDefaultedBounds(char* self, int lo, int hi)
{
    if (lo == -1)
        lo = 0;
    *reinterpret_cast<int*>(self + 0xac) = lo;
    if (hi == -1)
        hi = 1000;
    *reinterpret_cast<int*>(self + 0x8c) = hi;
    *reinterpret_cast<int*>(self + 0xa8) = hi;
}

// Hands arg to the helper with the table 200 bytes into the file's constant block.
// @0x142531510
void Sfr31HandOffToFileBlock(UPInt self, UPInt arg)
{
    FUN_1424ffc10(self, *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x20) + 0x78) + 0x10) + 200,
                  arg, 0, 0);
}

// Calls the helper object's virtual 0x58 with the owner and its +0x50 field (result discarded).
// @0x142538810
void Sfr31CallHelperVirtual(UPInt self)
{
    typedef void (*Fn)(UPInt helper, void* ret, UPInt owner, UPInt arg);
    UPInt helper = *reinterpret_cast<UPInt*>(self + 0x40);
    char ret[32];
    (*reinterpret_cast<Fn*>(*reinterpret_cast<UPInt*>(helper) + 0x58))(helper, ret, self, *reinterpret_cast<UPInt*>(self + 0x50));
}

// Flags the object (virtual 0x30 with 0x20000) after the global init helper, and caches its field 0x60.
// @0x142524350
void Sfr31FlagAndCacheField(UPInt self, UPInt* obj)
{
    typedef void (*Fn)(UPInt* obj, int flags);
    FUN_1424f03f0();
    (*reinterpret_cast<Fn*>(*obj + 0x30))(obj, 0x20000);
    *reinterpret_cast<UPInt*>(self + 0x28) = obj[0xc];
}


// Stage::SetOrientation: the orientation string (+0x120) is replaced.
// @0x142528770
void Sfr31StageSetOrientation(char* self, const ASString& orientation)
{
    *reinterpret_cast<ASString*>(self + 0x120) = orientation;
}

// ShapeDataInterface::SkipPathData: reads (virtual 0x48) until it reports the end.
// @0x14252c850
void Sfr31SkipPathData(UPInt self, void* pos)
{
    typedef int (*Fn)(UPInt self, void* pos, void* out);
    char out[24];
    while ((*reinterpret_cast<Fn*>(*reinterpret_cast<UPInt*>(self) + 0x48))(self, pos, out) != 0)
    {
    }
}


// Stores np into a tagged GC reference slot (odd values are weak marks); the old target is released.
static void Sfr31AssignGcRef(UPInt* slot, UPInt np)
{
    if (np != *slot)
    {
        const UPInt old = *slot;
        if (old != 0)
        {
            if ((old & 1) == 0)
            {
                UInt32* rc = reinterpret_cast<UInt32*>(old + 0x10);
                if ((*rc & 0x3fffff) != 0)
                {
                    --*rc;
                    FUN_1423dfa20(reinterpret_cast<void*>(old));
                }
            }
            else
                *slot = old - 1;
        }
        if (np != 0)
        {
            UInt32* rc = reinterpret_cast<UInt32*>(np + 0x10);
            *rc = (*rc + 1) & 0x8fbfffff;
        }
        *slot = np;
    }
}

// Stores the new GC reference at +8 and clears the word after it.
// MS2-FUNCTIONAL 0x142526340: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142526340
void Sfr31SetGcRefClearNext(UPInt self, UPInt np)
{
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 8), np);
    *reinterpret_cast<UPInt*>(self + 0x10) = 0;
}

// Stores the new GC reference at +8 and clears the two low flag bits of the first word.
// MS2-FUNCTIONAL 0x142528d20: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142528d20
void Sfr31SetGcRefClearFlags(UInt32* self, UPInt np)
{
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 2), np);
    *self &= 0xfffffffc;
}

// Stores the new GC reference at +8.
// MS2-FUNCTIONAL 0x142540bd0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142540bd0
void Sfr31SetGcRef(UPInt self, UPInt np)
{
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 8), np);
}

// Replaces the resource at +0xc0 (the new one is referenced first).
// @0x1425274b0
void Sfr31SetResource(UPInt self, Resource* res)
{
    if (res)
        res->AddRef();
    Resource*& cur = *reinterpret_cast<Resource**>(self + 0xc0);
    if (cur)
        cur->Release();
    cur = res;
}

// AvmBitmap::SetResourceMovieDef: the movie def (a resource) at +0xc8 is replaced.
// @0x142528e70
void Sfr31BitmapSetMovieDef(UPInt self, Resource* def)
{
    if (def)
        def->AddRef();
    Resource*& cur = *reinterpret_cast<Resource**>(self + 0xc8);
    if (cur)
        cur->Release();
    cur = def;
}

// MS2-FUNCTIONAL 0x142528f20: the copy/rename helpers are shared out-of-line code.
// @0x142528f20
void Slots::SetSlotInfo(AbsoluteIndex ind, const ASString& k, const SlotInfo& v)
{
    FUN_1424e0b80(&VArray[static_cast<UInt32>(ind.Get()) - static_cast<UInt32>(FirstOwnSlotNum)].Value, &v);
    SetKey(ind, k);
}

// Tracer::SkipOrigOpCode: a position inside the code gets its register state noted before moving on.
// @0x14252c7e0
void Sfr31TracerSkipOrigOpCode(UPInt tracer, UPInt* pos, UPInt next)
{
    if (*pos < *reinterpret_cast<UPInt*>(tracer + 0x58))
    {
        FUN_14251f710(tracer + 0x70);
        *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(tracer + 0xd0) + *pos * 8) =
            *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(tracer + 0x28) + 8);
    }
    *pos = next;
}


// Re-reads the autosize flags of the text field (+0x18) into its document view and marks it dirty.
// MS2-FUNCTIONAL 0x142530fc0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142530fc0
void Sfr31UpdateAutosizeSettings(UPInt self)
{
    const UPInt tf = *reinterpret_cast<UPInt*>(self + 0x18);
    const UInt8 flags = *reinterpret_cast<UInt8*>(tf + 0xfc);
    UPInt doc = *reinterpret_cast<UPInt*>(tf + 0xe0);
    if ((flags & 1) && !(*reinterpret_cast<UInt8*>(doc + 0x149) & 8))
        FUN_1426150b0(doc);
    else
        *reinterpret_cast<UInt8*>(doc + 0x149) &= 0xfe;
    if (!(flags & 1))
        *reinterpret_cast<UInt8*>(*reinterpret_cast<UPInt*>(tf + 0xe0) + 0x149) &= 0xfd;
    else
        FUN_1426150d0(*reinterpret_cast<UPInt*>(tf + 0xe0));
    *reinterpret_cast<UInt32*>(tf + 0xfc) |= 0x2000;
    FUN_1425bc060(tf);
}

// Tracer::UpdateBlock: moves to the block that starts at pos; false when the merge of the old state fails.
// MS2-FUNCTIONAL 0x142531040: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142531040
void Sfr31TracerUpdateBlock(UPInt tracer, char* ok, UPInt pos)
{
    UPInt* old = *reinterpret_cast<UPInt**>(tracer + 0x68);
    UPInt* blk = *reinterpret_cast<UPInt**>(tracer + 0x110);
    if (blk != NULL)
    {
        while (pos < blk[4])
        {
            blk = reinterpret_cast<UPInt*>(*blk);
            if (blk == NULL)
            {
                *ok = 1;
                return;
            }
        }
        if (blk[4] == pos)
        {
            *reinterpret_cast<UPInt**>(tracer + 0x68) = blk;
            if ((*reinterpret_cast<UInt8*>(blk + 2) & 1) == 0)
                FUN_142511b00(tracer, blk, old);
            else if (blk != old)
            {
                char buf[32];
                if (*FUN_142516c40(tracer, buf, blk, old) == 0)
                {
                    *ok = 0;
                    return;
                }
            }
        }
    }
    *ok = 1;
}

// Runs the shutdown of every registered entry (+0x2c0 array of +0x2c8 items), then empties the array.
// @0x142530d50
void Sfr31ShutdownRegistered(UPInt self)
{
    const UPInt n = *reinterpret_cast<UPInt*>(self + 0x2c8);
    const UInt8 saved = *reinterpret_cast<UInt8*>(self + 9);
    *reinterpret_cast<UInt8*>(self + 9) = 1;
    for (UPInt i = 0; i < n; ++i)
        FUN_1425303b0(reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x2c0))[i]);
    FUN_1424ef2a0(self + 0x2c0);
    *reinterpret_cast<UInt8*>(self + 9) = saved;
}

// Runs the slot (kind bits 5..9 are not a getter unless the caller asked for one) through the invoke helper.
// MS2-FUNCTIONAL 0x1425311c0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x1425311c0
void Sfr31InvokeSlot(UPInt self, const SlotInfo* si, UPInt arg, int argc)
{
    const UPInt traits = FUN_14250fa80(self);
    const int kind = *reinterpret_cast<const int*>(si);
    if (((kind << 22) >> 27) != 0xb || argc == 0xb)
    {
        ASStringNode* node = *reinterpret_cast<ASStringNode* const*>(reinterpret_cast<const char*>(si) + 0x28);
        ASString name(node);
        FUN_1425282d0(traits, (kind << 5) >> 15, arg, argc, &name);
    }
}

// Looks the name up in the own slots and invokes the newest one whose namespace has the flag (bit 4).
// MS2-FUNCTIONAL 0x1425310e0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x1425310e0
void Sfr31InvokeNamedSlot(UPInt self, const ASString& name, UPInt target, UPInt arg, int argc)
{
    if (target != *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x78) + 0x1d0))
        return;
    const Slots& slots = *reinterpret_cast<const Slots*>(self + 0x20);
    SPInt i = *slots.FindSlotValues(name);
    do
    {
        const SlotInfo* si;
        if (static_cast<UPInt>(i) < slots.FirstOwnSlotNum)
            si = &slots.Parent->GetSlotInfo(AbsoluteIndex(i));
        else
            si = &slots.VArray[static_cast<UInt32>(i) - static_cast<UInt32>(slots.FirstOwnSlotNum)].Value;
        if ((*reinterpret_cast<const UInt8*>(*reinterpret_cast<const UPInt*>(reinterpret_cast<const char*>(si) + 8) + 0x20) >> 4) & 1)
        {
            Sfr31InvokeSlot(self, si, arg, argc);
            return;
        }
        if (static_cast<UPInt>(i) < slots.FirstOwnSlotNum)
            i = slots.Parent->GetPrevSlotIndex(i);
        else
            i = slots.VArray[static_cast<UInt32>(i) - static_cast<UInt32>(slots.FirstOwnSlotNum)].Prev;
    } while (i >= 0);
}


// TR::State::SwapOp: the two topmost operand stack values trade places.
// MS2-FUNCTIONAL 0x14252e800: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252e800
void Sfr31StateSwapOp(UPInt state)
{
    Value* data = *reinterpret_cast<Value**>(state + 0x38);
    const UPInt n = *reinterpret_cast<UPInt*>(state + 0x40);
    Value top(data[n - 1]);
    data[n - 1] = data[n - 2];
    data[n - 2] = top;
}

// AvmDisplayObj::SwitchAS3ObjPtrType: type 1 makes the object reference strong, anything else weak.
// MS2-FUNCTIONAL 0x14252e900: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252e900
void Sfr31SwitchAS3ObjPtrType(UPInt self, int type)
{
    UPInt* strong = reinterpret_cast<UPInt*>(self + 8);
    UPInt* weak = reinterpret_cast<UPInt*>(self + 0x10);
    UPInt v = *weak;
    if (type == 1)
    {
        if (v == 0)
            v = *strong;
        if (v & 1)
            --v;
        Sfr31SetGcRefClearNext(self, v);
        return;
    }
    if (v == 0)
        v = *strong;
    if (v & 1)
        --v;
    *weak = v;
    const UPInt s = *strong;
    if (s != 0)
    {
        if (((s & 1) == 0) && (*reinterpret_cast<UInt32*>(s + 0x10) & 0x3fffff) != 0)
        {
            --*reinterpret_cast<UInt32*>(s + 0x10);
            FUN_1423dfa20(reinterpret_cast<void*>(s));
        }
        *strong = 0;
    }
}

// AvmButton::SwitchState: unless the owner is being destroyed or already removed, the mouse state is
// translated and handed to SwitchStateIntl.
// MS2-FUNCTIONAL 0x14252e980: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252e980
void Sfr31ButtonSwitchState(UPInt self, int mouseState)
{
    const UPInt owner = *reinterpret_cast<UPInt*>(self - 0x28);
    const UInt16 flags = *reinterpret_cast<UInt16*>(owner + 0x6a);
    if (!((flags >> 4) & 1) && !(flags & 0x1000) && *reinterpret_cast<int*>(owner + 0x2c) > -2)
        FUN_14252e9d0(self - 0x40, FUN_1425de200(mouseState));
}

// AS3ValueObjectInterface::SetElement: stores the converted value at the array index.
// MS2-FUNCTIONAL 0x142527300: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142527300
bool Sfr31SetElement(UPInt self, UPInt array, UInt32 ind, const void* gfxValue)
{
    Value v;
    FUN_1425048d0(*reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 8) + 0x18), gfxValue, &v);
    FUN_1424213b0(array + 0x38, ind, &v);
    return true;
}

// AS3ValueObjectInterface::ToString: the value's string form is copied into out.
// MS2-FUNCTIONAL 0x14252fd40: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252fd40
void Sfr31ToString(UPInt self, String* out, const void* gfxValue)
{
    const UPInt root = *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 8) + 0x18);
    Value v;
    FUN_1425048d0(root, gfxValue, &v);
    ASString s(reinterpret_cast<ASStringNode*>(*reinterpret_cast<UPInt*>(root + 0x348) + 0x40));
    v.Convert2String(s);
    out->AssignString(s.ToCStr(), s.GetSize());
}

}}} // namespace Scaleform::GFx::AS3

// INST-Reserve-BEGIN
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SlotContainerType::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SlotContainerType::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long const*,Scaleform::AllocatorDH<long const*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<double const*,Scaleform::AllocatorDH<double const*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object*,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH_POD<unsigned int,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State*,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State*,328>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::ClassInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::ClassInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MetadataInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// INST-Reserve-END

// INST-HashRaw-BEGIN
template void Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeHashF,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::UInt32,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode*,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase*,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::setRawCapacity(void*, Scaleform::UPInt);
// INST-HashRaw-END

// INST-Resize-BEGIN
template void Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> >::Resize(Scaleform::UPInt);
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::UInt8,Scaleform::AllocatorLH<Scaleform::UInt8,2>,Scaleform::ArrayDefaultPolicy> >::Resize(Scaleform::UPInt);
// INST-Resize-END

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
// MS2-PIN: ?SetUInt32@Value@AS3@GFx@Scaleform@@QEAAXK@Z 0x14252a460
