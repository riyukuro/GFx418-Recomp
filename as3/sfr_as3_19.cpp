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
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/gfx_input.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
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
void FUN_14241a500(Scaleform::UPInt traits, Scaleform::UPInt* ret, Scaleform::UPInt t);   // InstanceTraits::Array::MakeInstance
void FUN_14241d980(Scaleform::UPInt arr, Scaleform::UPInt stack, Scaleform::UInt32 n);   // Array: fill from the operand stack
void FUN_14241b920(Scaleform::UPInt tbl, void* ret, Scaleform::UPInt a, Scaleform::UPInt b);   // class table: find interface traits
const Scaleform::GFx::AS3::Traits* FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& obj);   // Value traits
void* FUN_14250fa80(const Scaleform::GFx::AS3::Traits* tr);   // Traits::GetVT
const char* FUN_142529030(const Scaleform::GFx::AS3::SlotInfo* si, void* res, Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::AS3::Value& obj, void* vt);   // SlotInfo::SetSlotValue
void FUN_1424e6aa0(Scaleform::UPInt tracer, Scaleform::UPInt a, Scaleform::SPInt idx, int b, int c);   // Tracer: trace a block from idx
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
char* FUN_1424f1a30(void* v, void* ok, unsigned long* out);         // Value::Convert2UInt32
char* FUN_1424f0d30(void* v, void* ok, long* out);                  // Value::Convert2SInt32 (CheckResult returned in *ok)
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
bool* FUN_1424f1390(Scaleform::GFx::AS3::Value* v, void* tmpNode, void* strOut);   // Value::ToStringValue style conversion
void FUN_1424e0860(void* out);                                                      // assign from the scratch value
void FUN_1424201a0(void* arr, void* heap, Scaleform::UPInt n);                      // ArrayDH<Value>::Resize growth
void FUN_142521f00(void* value);                                                    // Value::ReleaseInternal
Scaleform::SPInt FUN_1425f9200(void* list, void* obj);                          // DisplayList::FindDisplayIndex(const DisplayObjectBase*)
bool FUN_1425fb480(void* list, void* owner, Scaleform::UPInt i1, Scaleform::UPInt i2);   // DisplayList::SwapEntriesAtIndexes
void FUN_142517ed0(void* avmInteractiveObj);                                     // AvmInteractiveObj::MoveBranchInPlayList
int FUN_142520380(void* ctx, void* multiname);                                    // Tracer: number of run-time operands a multiname takes off the stack
void FUN_142501e80(void* state, void* propRef, void* multiname, void* a, void* b);   // Tracer: resolve a multiname to a property reference
void FUN_1425201f0(void* ctx, void* multiname);                                      // exec: resolve runtime multiname operands from the stack
unsigned char* FUN_142528810(unsigned char* ret, Scaleform::UPInt vm, void* obj, void* multiname, void* value); // VM: set a property on an object
unsigned char* FUN_14250ef80(unsigned char* ret, Scaleform::UPInt vm, Scaleform::UPInt traits, void* result, const void* obj, const void* multiname, int target); // GetSuperProperty
void FUN_142502570(Scaleform::UPInt vm, void* propRef, void* multiname);              // VM: resolve a multiname to a property reference
void FUN_14252c640(Scaleform::UPInt tracer, Scaleform::UPInt* pos);                      // Tracer: advance over padding/labels at pos
void FUN_1425212f0(Scaleform::UPInt tracer);                                              // Tracer: per-opcode bookkeeping
char FUN_14252d100(Scaleform::UPInt tracer, unsigned char op, Scaleform::UPInt* pos, Scaleform::UPInt state);   // Tracer: trace one opcode (common set)
void FUN_14253d520(Scaleform::UPInt state, unsigned char op, Scaleform::UPInt* pos);     // TR::State: trace one opcode (remaining set)
void FUN_1424d7690(void* err, int id, void* vm, const char* a, const char* b);       // VM::Error::Error(id, vm, char*, char*)
Scaleform::UPInt FUN_142524f60(Scaleform::UPInt vm, Scaleform::UPInt file, Scaleform::UPInt entry);   // multiname entry -> traits
Scaleform::UPInt FUN_142507f60(Scaleform::UPInt vm, const void* value);               // class traits of a value
void* FUN_142581a40(void* entry, unsigned changeBits);   // ContextImpl::Entry::getWritableData
void FUN_142581430(void* entry);                         // ContextImpl::Entry::addToPropagateImpl
Scaleform::UPInt FUN_1425f26c0(void* displayObjectBase); // DisplayObjectBase::GetRenderNode
void FUN_1424d7850(void* err, int id, void* vm, const char* s);   // VM::Error::Error(id, vm, char*)
void FUN_1424e42c0(Scaleform::UPInt root, const Scaleform::GFx::AS3::Value* v, void* gfxValue);   // MovieRoot::ASValue2GFxValue
void FUN_142545310(Scaleform::UPInt entry, void* out);    // constant-pool string entry -> (chars, length)

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

// ---- display-object setters and small helpers (sfr31) ----
void FUN_1425f4090(void* obj);
Scaleform::UInt64 FUN_1425e3560(void);
Scaleform::SInt32 FUN_142622510(Scaleform::UPInt obj);
Scaleform::SInt64 FUN_1426224d0(Scaleform::UPInt obj);
void FUN_142623560(Scaleform::UPInt obj, Scaleform::UInt64 delta);
void FUN_1426244e0(Scaleform::UPInt obj, Scaleform::SInt32 v);
void FUN_142624450(Scaleform::UPInt obj, Scaleform::SInt64 v);
char* FUN_142529030(Scaleform::UPInt slot, char* ret, Scaleform::UPInt vm, const Scaleform::GFx::AS3::Value* v, Scaleform::UPInt p5, Scaleform::UPInt vt);
Scaleform::GFx::AS3::Value* FUN_14250a490(Scaleform::UPInt tracer, Scaleform::GFx::AS3::Value* out, Scaleform::UPInt state);

namespace Scaleform { namespace GFx {

// @0x1425265f0
void InteractiveObject::SetBlendMode(Render::BlendMode mode)
{
    DisplayObjectBase::SetBlendMode(mode);
    FUN_1425f4090(this);
}

namespace AS3 {

static inline UPInt Sfr31Rd(UPInt base, UPInt off) { return *reinterpret_cast<const UPInt*>(base + off); }
static inline void Sfr31Wr(UPInt base, UPInt off, UPInt v) { *reinterpret_cast<UPInt*>(base + off) = v; }

// @0x1425262e0
void Sfr31AvmDisplayObjSetAS3Obj(UPInt self, UPInt obj)
{
    if (Sfr31Rd(Sfr31Rd(self, 0x18), 0x38) != 0) { Sfr31SetGcRefClearNext(self, obj); return; }
    *reinterpret_cast<UPInt*>(self + 0x10) = obj;
    UPInt old = Sfr31Rd(self, 8);
    if (old != 0)
    {
        if (((old & 1) == 0) && ((*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0))
        {
            *reinterpret_cast<UInt32*>(old + 0x10) -= 1;
            FUN_1423dfa20(reinterpret_cast<void*>(old));
        }
        *reinterpret_cast<UPInt*>(self + 8) = 0;
    }
}

// @0x1425266c0
bool Sfr31SetCxform(UPInt self, UPInt obj, const Render::Cxform* cx)
{
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) != 0))
    {
        DisplayObjectBase* d = *reinterpret_cast<DisplayObjectBase**>(obj + 0x58);
        d->SetCxform(*cx);
        typedef void (*Fn)(void*, SInt32);
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(d), 0), 0x188))(d, 0);
        return true;
    }
    return false;
}

// MS2-FUNCTIONAL 0x142539420: same logic; Value init/release and register allocation differ
// @0x142539420
void Sfr31StatePushTyped(UPInt st)
{
    Value v;
    const Value* r = FUN_14250a490(Sfr31Rd(st, 0), &v, st);
    reinterpret_cast<TR::State*>(st)->GetOpStack().PushBack(*r);
}

// MS2-FUNCTIONAL 0x142526430: same logic; Value init/release and register allocation differ
// @0x142526430
void Sfr31SyncSetInt(UPInt* self, SInt32 val)
{
    typedef UPInt (*Get)(void*);
    UPInt o = reinterpret_cast<Get>(Sfr31Rd(self[0], 8))(self);
    if (o != 0 && val != FUN_142622510(o))
    {
        UInt64 t = FUN_1425e3560();
        FUN_142623560(o, t - self[0x38]);
        self[0x38] = t;
        FUN_1426244e0(o, val);
    }
}

// MS2-FUNCTIONAL 0x1425263b0: same logic; Value init/release and register allocation differ
// @0x1425263b0
void Sfr31SyncSetInt64(UPInt* self, SInt64 val)
{
    typedef UPInt (*Get)(void*);
    UPInt o = reinterpret_cast<Get>(Sfr31Rd(self[0], 8))(self);
    if (o != 0 && val != FUN_1426224d0(o))
    {
        UInt64 t = FUN_1425e3560();
        FUN_142623560(o, t - self[0x38]);
        self[0x38] = t;
        FUN_142624450(o, val);
    }
}

// MS2-FUNCTIONAL 0x142528fb0: same logic; Value init/release and register allocation differ
// @0x142528fb0
char* Sfr31PropRefSetSlotValue(UPInt self, char* ret, UPInt vm, const Value* v)
{
    UPInt w = Sfr31Rd(self, 0);
    UInt32 k = static_cast<UInt32>(w) & 3;
    char tmp[32];
    if (k == 0) { *ret = *FUN_142529030(w, tmp, vm, v, self + 0x10, 0); return ret; }
    if (k != 1) { *ret = (k == 2) ? 0 : 1; return ret; }
    reinterpret_cast<Value*>(w & ~UPInt(1))->Assign(*v);
    *ret = 1;
    return ret;
}

}}} // namespace Scaleform::GFx::AS3

// ---- tracer pushes, display-list index, VM pop/pushundefined (sfr31) ----
Scaleform::UPInt FUN_142506f00(Scaleform::UPInt link, Scaleform::UPInt traits, Scaleform::GFx::ASString* name);
Scaleform::UPInt FUN_14250ae60(Scaleform::UPInt link, Scaleform::UPInt ind);
Scaleform::GFx::AS3::Value* FUN_1423ef9b0(Scaleform::GFx::AS3::Value* out, Scaleform::UPInt x);
Scaleform::UPInt FUN_14250d760(Scaleform::UPInt root, Scaleform::UPInt pos);
void FUN_142575f10(Scaleform::UPInt obj, Scaleform::UPInt heap, Scaleform::UPInt owner, Scaleform::UPInt flag);
void FUN_14257dcd0(void* obj);
void FUN_1424efe30(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* a, Scaleform::GFx::AS3::Value* b);

namespace Scaleform { namespace GFx { namespace AS3 {

// A tracer value holding a pointer at +0x10 (the exe stores the kind and clears the second word).
struct TrPtrScratch
{
    TrPtrScratch(UInt32 kind) { w1 = 0; w0 = kind; }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1, w2, w3;
};

// MS2-FUNCTIONAL 0x14253be60: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14253be60
void Sfr31StatePushNs(UPInt st)
{
    const UPInt own = Sfr31Rd(Sfr31Rd(st, 0), 0x20);
    ASString name(reinterpret_cast<ASStringNode*>(Sfr31Rd(own, 0x70)));
    const UPInt link = Sfr31Rd(own, 0x28);
    TrPtrScratch t(8);
    t.w2 = FUN_142506f00(link, *reinterpret_cast<const UPInt*>(Sfr31Rd(Sfr31Rd(link, 0x28), 0x170) + static_cast<SPInt>(*reinterpret_cast<const SInt32*>(own + 0x30)) * 8), &name);
    reinterpret_cast<TR::State*>(st)->GetOpStack().PushBack(t.Get());
}

// MS2-FUNCTIONAL 0x14253f410: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14253f410
void Sfr31StatePushPool(UPInt st, UInt32 ind)
{
    const UPInt tr = Sfr31Rd(st, 0);
    FUN_14251fcd0(tr, ind);
    Value v;
    const Value* r = FUN_1423ef9b0(&v, FUN_14250ae60(Sfr31Rd(Sfr31Rd(tr, 0x20), 0x28), ind));
    reinterpret_cast<TR::State*>(st)->GetOpStack().PushBack(*r);
}

// A recorded state's traits equal to, or derived from, tr (state array at +0xd0, 0x30 bytes each).
// MS2-FUNCTIONAL 0x14252e480: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252e480
bool Sfr31TracerHasTraits(UPInt self, UPInt tr)
{
    const UPInt root = Sfr31Rd(self, 0x78);
    for (UPInt i = 0, off = 0; i < Sfr31Rd(self, 0xd8); ++i, off += 0x30)
    {
        UPInt t = FUN_14250d760(root, Sfr31Rd(self, 0xd0) + off);
        if (t != 0)
        {
            UPInt p = Sfr31Rd(t, 0xc0);
            typedef char (*Fn)(UPInt, UPInt);
            if (p == tr || reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(p, 0), 0x80))(p, tr) != 0)
                return true;
        }
    }
    return false;
}

// Replace the 16-byte holder at self+0x30 by a fresh one {a, b}; b registers itself with a's heap.
// MS2-FUNCTIONAL 0x14252a5a0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252a5a0
void Sfr31SetHolder(UPInt self, UPInt a, UPInt b, UInt8 flag)
{
    if (Sfr31Rd(self, 0x30) != 0)
        Memory::pGlobalHeap->Free(reinterpret_cast<void*>(Sfr31Rd(self, 0x30)));
    AllocInfo ai;
    UPInt* h = static_cast<UPInt*>(Memory::pGlobalHeap->AllocAutoHeap(reinterpret_cast<void*>(self), 0x10, &ai));
    if (h != 0) { h[0] = a; h[1] = b; }
    *reinterpret_cast<UPInt**>(self + 0x30) = h;
    if (b != 0)
        FUN_142575f10(b, Sfr31Rd(a, 0x38), self, flag);
}

// @0x14252a4f0
void Sfr31SetHolderOf(UPInt owner, UPInt self, UPInt b, UInt8 flag)
{
    if (self != 0)
    {
        const UPInt a = Sfr31Rd(owner, 8);
        if (Sfr31Rd(self, 0x30) != 0)
            Memory::pGlobalHeap->Free(reinterpret_cast<void*>(Sfr31Rd(self, 0x30)));
        AllocInfo ai(0x151, 0, 0);
        UPInt* h = static_cast<UPInt*>(Memory::pGlobalHeap->AllocAutoHeap(reinterpret_cast<void*>(self), 0x10, &ai));
        if (h != 0) { h[0] = a; h[1] = b; }
        *reinterpret_cast<UPInt**>(self + 0x30) = h;
        if (b != 0)
            FUN_142575f10(b, Sfr31Rd(a, 0x38), self, flag);
    }
}

// MS2-FUNCTIONAL 0x142526610: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142526610
bool Sfr31ContainerSetChildIndex(UPInt self, DisplayObjectBase* ch, UInt32 index)
{
    const UPInt holder = Sfr31Rd(self, 0x18);
    if (index < *reinterpret_cast<const UInt32*>(holder + 0xe0))
    {
        DisplayList* dl = reinterpret_cast<DisplayList*>(holder + 0xd8);
        SPInt at = dl->FindDisplayIndex(ch);
        if (at >= 0)
        {
            if (ch != 0)
                ++*reinterpret_cast<SInt32*>(reinterpret_cast<UPInt>(ch) + 8);
            dl->RemoveEntryAtIndex(reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(self, 0x18)), static_cast<UPInt>(at));
            dl->AddEntryAtIndex(reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(self, 0x18)), index, ch);
            typedef void (*Fn)(void*, SInt32);
            reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(ch), 0), 0x188))(ch, 0);
            *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(ch) + 0x30) = 0;
            *reinterpret_cast<SInt32*>(reinterpret_cast<UPInt>(ch) + 0x2c) = -1;
            *reinterpret_cast<UInt8*>(holder + 0x100) |= 3;
            FUN_14257dcd0(ch);
            return true;
        }
    }
    return false;
}

// pop: with a running frame flag clear the exe's slow helper pops, otherwise the top is released inline.
// MS2-FUNCTIONAL 0x14253f920: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14253f920
void Sfr31ExecPop(VM* vm)
{
    const UPInt i = VmRd(vm, 0x78) - 1;
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    if (*reinterpret_cast<const char*>((i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8)) == 0)
    {
        FUN_1424efe30(vm, top, top);
        return;
    }
    Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    cur->~Value();
    --cur;
}

// MS2-FUNCTIONAL 0x14253f9e0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14253f9e0
void Sfr31ExecPushUndefined(VM* vm)
{
    const UPInt i = VmRd(vm, 0x78) - 1;
    if (*reinterpret_cast<const char*>((i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8)) == 0)
        ExecPushCopy(vm, Value::GetUndefined());
}

// MS2-FUNCTIONAL 0x14252a640: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252a640
STPtr* Sfr31STPtrSetValue(STPtr* self, const Value& v)
{
    return &self->SetValue(v);
}

}}} // namespace Scaleform::GFx::AS3

// ---- tracer pops with ReadArgs, TextField text, invoke alias, cursor type, action queue (sfr31) ----
namespace Scaleform { namespace GFx { namespace AS3 {
using namespace TR;

// MS2-FUNCTIONAL 0x142537710: behavior-equivalent recovery; codegen differs from exe
// @0x142537710
void Sfr31TraceCallPop(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, argc);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    popped.Get().~Value();
}

// MS2-FUNCTIONAL 0x1425401a0: behavior-equivalent recovery; codegen differs from exe
// @0x1425401a0
void Sfr31TracePop2Note(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), arg);
    TrPopped a, b;
    FUN_14251cd30(st, &a.Get());
    FUN_14251cd30(st, &b.Get());
    b.Get().~Value();
    a.Get().~Value();
}

// MS2-FUNCTIONAL 0x1425264b0: behavior-equivalent recovery; codegen differs from exe
// @0x1425264b0
void Sfr31StatePushValues(State* st, UInt32 n, const Value* vals)
{
    StV s(st);
    for (UInt32 i = 0; i < n; ++i)
        s.OpStack().PushBack(vals[i]);
}

// MS2-FUNCTIONAL 0x142540a90: behavior-equivalent recovery; codegen differs from exe
// @0x142540a90
const MovieRoot::ActionEntry* MovieRoot::ActionQueueIterator::getNext()
{
    ActionQueueType* q = pActionQueue;
    ActionEntry* pe;
    if (q->ModId == ModId)
        pe = pCurEntry;
    else
    {
        ModId = q->ModId;
        ActionEntry** src = pRootEntry ? &pRootEntry->pNextEntry : &q->Entries[Level].pActionRoot;
        pe = *src;
        pCurEntry = pe;
    }
    if (pe != 0)
    {
        if (pe == q->Entries[Level].pInsertEntry)
        {
            ActionEntry* nx = pe->pNextEntry;
            if (nx == 0)
                nx = pRootEntry;
            q->Entries[Level].pInsertEntry = nx;
        }
        ActionEntry** root = &pActionQueue->Entries[Level].pActionRoot;
        ActionEntry* cur = pCurEntry;
        if (cur == *root)
            *root = cur->pNextEntry;
        else if (pRootEntry != 0)
            pRootEntry->pNextEntry = cur->pNextEntry;
        q = pActionQueue;
        pCurEntry = pCurEntry->pNextEntry;
    }
    if (q->Entries[Level].pActionRoot == 0)
    {
        q->Entries[Level].pInsertEntry = 0;
        pActionQueue->Entries[Level].pLastEntry = 0;
    }
    if (pLastEntry != 0)
    {
        pLastEntry->pNextEntry = 0;
        pActionQueue->AddToFreeList(pLastEntry);
        ++pActionQueue->ModId;
        ModId = pActionQueue->ModId;
    }
    pLastEntry = pe;
    return pe;
}

// A text assignment through the host interface: TextFields take it directly, anything else gets text/htmlText.
// MS2-FUNCTIONAL 0x14252a360: behavior-equivalent recovery; codegen differs from exe
// @0x14252a360
bool Sfr31SetTextOnObject(UPInt* self, UPInt obj, const wchar_t* text, bool html)
{
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) != 0))
    {
        TextField* tf = *reinterpret_cast<TextField**>(obj + 0x58);
        typedef SInt32 (*Kind)(void*);
        if (reinterpret_cast<Kind>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(tf), 0), 0x258))(tf) == 4)
        {
            tf->SetText(text, html);
            return true;
        }
        struct RawGfxValue { UPInt iface; UInt32 type; const wchar_t* str; } v = { 0, 7, text };
        typedef char (*Set)(void*, UPInt, const char*, void*, SInt32);
        char r = reinterpret_cast<Set>(Sfr31Rd(self[0], 0x28))(self, obj, html ? "htmlText" : "text", &v, 1);
        if ((v.type >> 6 & 1) != 0)
        {
            typedef void (*Rel)(void*, void*, const wchar_t*);
            reinterpret_cast<Rel>(Sfr31Rd(Sfr31Rd(v.iface, 0), 0x10))(reinterpret_cast<void*>(v.iface), &v, v.str);
        }
        return r != 0;
    }
    return false;
}

// MS2-FUNCTIONAL 0x142525400: behavior-equivalent recovery; codegen differs from exe
// @0x142525400
Value* Sfr31ResolveInvokeAlias(UPInt root, const char* name)
{
    if (Sfr31Rd(root, 0x80) == 0)
        return 0;
    ASStringNode* node = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateStringNode(name);
    Value* res = 0;
    const SInt32 rc = node->RefCount;
    node->RefCount = rc + 1;
    UPInt tbl = *reinterpret_cast<UPInt*>(Sfr31Rd(root, 0x80));
    UPInt ent = 0;
    if (tbl != 0)
    {
        const UPInt mask = Sfr31Rd(tbl, 8);
        UPInt idx = node->HashFlags & mask;
        UPInt* e = reinterpret_cast<UPInt*>(tbl + 0x10 + idx * 0x30);
        if (e[0] != ~UPInt(1) && (reinterpret_cast<ASStringNode*>(e[1])->HashFlags & mask) == idx)
        {
            UPInt at = idx;
            while ((reinterpret_cast<ASStringNode*>(e[1])->HashFlags & mask) != idx || reinterpret_cast<ASStringNode*>(e[1]) != node)
            {
                at = e[0];
                if (at == ~UPInt(0)) { ent = 0; goto done; }
                e = reinterpret_cast<UPInt*>(tbl + 0x10 + at * 0x30);
            }
            if (static_cast<SPInt>(at) >= 0)
                ent = tbl + 0x18 + at * 0x30;
        }
    }
done:
    node->RefCount = rc;
    res = ent != 0 ? reinterpret_cast<Value*>(ent + 8) : 0;
    if (rc == 0)
        node->ReleaseNode();
    return res;
}

// MS2-FUNCTIONAL 0x142528620: behavior-equivalent recovery; codegen differs from exe
// @0x142528620
void Sfr31SetMouseCursorType(UPInt self, const ASString* name, UInt32 mouse)
{
    const char* s = name->ToCStr();
    SInt32 v;
    if (strcmp(s, "arrow") == 0) v = 0;
    else if (strcmp(s, "button") == 0) v = 3;
    else if (strcmp(s, "hand") == 0) v = 1;
    else if (strcmp(s, "ibeam") == 0) v = 2;
    else v = -1;
    SInt32* p0;
    SInt32* p1;
    if (mouse < 4)
    {
        p0 = reinterpret_cast<SInt32*>(Sfr31Rd(self, 0x10) + 0x12a0 + static_cast<UPInt>(mouse) * 0x50);
        p1 = reinterpret_cast<SInt32*>(Sfr31Rd(self, 0x10) + 0x12a4 + static_cast<UPInt>(mouse) * 0x50);
    }
    else
    {
        p0 = reinterpret_cast<SInt32*>(0x40);
        p1 = reinterpret_cast<SInt32*>(0x44);
    }
    typedef void (*Fn)(UPInt, UInt32, SInt32);
    reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(self, 0), 0x18))(self, mouse, v);
    *p1 = v;
    *p0 = v;
}

// Tracer::Recalculate: a position to retrace and the argument it needs (0x10 bytes).
class Tracer { public: struct Recalculate { UPInt Pos; UInt32 Arg; UInt32 Pad; }; };

const SlotInfo* FindFixedSlot(VM& vm, const Traits& tr, const Multiname& mn, UPInt& ind, Object* obj);   // 0x142500f90

// batch 18
// LinearHeap::allocFromLastPage: bump-allocates from the last page, or (when that page is untouched) replaces it with one
// big enough for the request.
// MS2-FUNCTIONAL 0x142532060: functional recovery; codegen differs from exe
// @0x142532060
void* Sfr31LinearHeapAllocFromLastPage(UPInt self, UPInt n)
{
    UPInt page = Sfr31Rd(self, 0x18);
    UPInt used = Sfr31Rd(page, 0x10);
    if (static_cast<SPInt>(n) <= static_cast<SPInt>(Sfr31Rd(page, 8) - used))
    {
        Sfr31Wr(page, 0x10, used + n);
        return reinterpret_cast<void*>(Sfr31Rd(Sfr31Rd(self, 0x18), 0x10) - n);
    }
    if (used == Sfr31Rd(page, 0))
    {
        MemoryHeap* heap = reinterpret_cast<MemoryHeap*>(Sfr31Rd(self, 0));
        if (Sfr31Rd(page, 0) != 0)
            heap->Free(reinterpret_cast<void*>(Sfr31Rd(page, 0)));
        UPInt pageSize = Sfr31Rd(self, 8);
        UPInt total = n - 1 + pageSize;
        total -= total % pageSize;
        UPInt p = reinterpret_cast<UPInt>(heap->Alloc(total, static_cast<const AllocInfo*>(0)));
        UPInt cur = Sfr31Rd(self, 0x18);
        Sfr31Wr(cur, 0x10, p);
        Sfr31Wr(Sfr31Rd(self, 0x18), 0, p);
        Sfr31Wr(Sfr31Rd(self, 0x18), 8, Sfr31Rd(Sfr31Rd(self, 0x18), 0) + total);
        Sfr31Wr(Sfr31Rd(self, 0x18), 0x10, Sfr31Rd(Sfr31Rd(self, 0x18), 0x10) + n);
        return reinterpret_cast<void*>(Sfr31Rd(Sfr31Rd(self, 0x18), 0));
    }
    return 0;
}

// SetSuperProperty: stores v through the parent traits' fixed slot for the multiname; false when there is no such slot.
// MS2-FUNCTIONAL 0x14252a150: functional recovery; codegen differs from exe
// @0x14252a150
CheckResult SetSuperProperty(VM& vm, const Traits* tr, const Value& obj, const Multiname& mn, const Value& v)
{
    if (tr == 0)
        tr = FUN_14250ffc0(vm, obj);
    const Traits* parent = tr->GetParent();
    if (parent != 0)
    {
        UPInt ind = 0;
        const SlotInfo* si = FindFixedSlot(vm, *parent, mn, ind, 0);
        if (si != 0)
        {
            UByte res[16];
            void* vt = FUN_14250fa80(parent);
            if (*FUN_142529030(si, res, vm, v, obj, vt) != 0)
                return true;
        }
    }
    return false;
}

// Tracer: records a position to retrace after the target of a jump (backward jumps only note the target's position).
// MS2-FUNCTIONAL 0x14252c9f0: functional recovery; codegen differs from exe
// @0x14252c9f0
void Sfr31TraceNoteJump(UPInt tr, SPInt base, UPInt blk, SInt32 off, SInt32 arg)
{
    SPInt idx = off + base;
    if (off < 0)
    {
        FUN_14251fcd0(tr, Sfr31Rd(Sfr31Rd(tr, 0xd0) + idx * 8, 0) - Sfr31Rd(Sfr31Rd(tr, 0x28), 8) + static_cast<SPInt>(arg));
        return;
    }
    FUN_1424e6aa0(tr, blk, idx, 0, 1);
    FUN_14251fcd0(tr, idx);
    UPInt pos = Sfr31Rd(Sfr31Rd(tr, 0x28), 8);
    ArrayDataBase<Tracer::Recalculate, AllocatorDH_POD<Tracer::Recalculate, 328>, ArrayDefaultPolicy>* arr =
        reinterpret_cast<ArrayDataBase<Tracer::Recalculate, AllocatorDH_POD<Tracer::Recalculate, 328>, ArrayDefaultPolicy>*>(tr + 0xb0);
    UPInt n = arr->Size + 1;
    arr->ResizeNoConstruct(reinterpret_cast<const void*>(Sfr31Rd(tr, 0xc8)), n);
    Tracer::Recalculate& r = arr->Data[n - 1];
    r.Pos = pos - 1;
    r.Arg = static_cast<UInt32>(arg);
}

// batch 19
// nextname/nextvalue share the shape: the index on top is consumed, the object below becomes the name/value.
static __forceinline void Sfr31ExecNextCommon(VM* vm, bool wantValue)
{
    Value*& top = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    UInt64 tmp;
    long idx;
    const bool ok = *FUN_1424f0d30(top, &tmp, &idx) != 0;
    if (ok)
        top->SetSInt32(idx);
    top->~Value();
    --top;
    if (ok)
    {
        Object* obj = *reinterpret_cast<Object**>(reinterpret_cast<UPInt>(top) + 0x10);
        if (wantValue)
            obj->GetNextPropertyValue(*top, GlobalSlotIndex(static_cast<UInt32>(idx)));
        else
            obj->GetNextPropertyName(*top, GlobalSlotIndex(static_cast<UInt32>(idx)));
    }
}

// MS2-FUNCTIONAL 0x14253d2f0: object released through Value::~Value and the namespace case dispatched virtually
// @0x14253d2f0
void Sfr27ExecNextName(VM* vm) { Sfr31ExecNextCommon(vm, false); }

// MS2-FUNCTIONAL 0x14253d440: functional recovery; codegen differs from exe
// @0x14253d440
void Sfr27ExecNextValue(VM* vm) { Sfr31ExecNextCommon(vm, true); }

// As Sfr31SetTextOnObject, for a UTF-8 string; a TextField also has its html flag (+0xfc bit 1) synced to the request.
// MS2-FUNCTIONAL 0x14252a230: behavior-equivalent recovery; codegen differs from exe
// @0x14252a230
bool Sfr31SetTextOnObjectUtf8(UPInt* self, UPInt obj, const char* text, bool html)
{
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U >= 0xc) || ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) == 0))
        return false;
    TextField* tf = *reinterpret_cast<TextField**>(obj + 0x58);
    typedef SInt32 (*Kind)(void*);
    if (reinterpret_cast<Kind>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(tf), 0), 0x258))(tf) != 4)
    {
        struct RawGfxValue { UPInt iface; UInt32 type; const char* str; } v = { 0, 6, text };
        typedef char (*Set)(void*, UPInt, const char*, void*, SInt32);
        char r = reinterpret_cast<Set>(Sfr31Rd(self[0], 0x28))(self, obj, html ? "htmlText" : "text", &v, 1);
        if ((v.type >> 6 & 1) != 0)
        {
            typedef void (*Rel)(void*, void*, const char*);
            reinterpret_cast<Rel>(Sfr31Rd(Sfr31Rd(v.iface, 0), 0x10))(reinterpret_cast<void*>(v.iface), &v, v.str);
        }
        return r != 0;
    }
    UInt32& flags = *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(tf) + 0xfc);
    if (!html)
        flags &= 0xfffffffd;
    else
        flags |= 2;
    tf->SetTextValue(text, html, true);
    return true;
}

// newarray: a new Array filled from the n values on the operand stack, pushed.
// MS2-FUNCTIONAL 0x14253c0f0: behavior-equivalent recovery; codegen differs from exe
// @0x14253c0f0
void Sfr31ExecNewArray(UPInt vm, UInt32 n)
{
    UPInt traits = Sfr31Rd(Sfr31Rd(vm, 0x238), 0xc0);
    UPInt arr;
    FUN_14241a500(traits, &arr, traits);
    FUN_14241d980(arr + 0x38, vm + 0x48, n);
    Value v(Pickable<Object>(reinterpret_cast<Object*>(arr)));
    ExecPushCopy(reinterpret_cast<VM*>(vm), v);
}

// A new instance of the interface traits found by name (a, b), pushed on the operand stack.
// MS2-FUNCTIONAL 0x14253c200: behavior-equivalent recovery; codegen differs from exe
// @0x14253c200
void Sfr31ExecPushInterfaceInstance(UPInt vm, UPInt a, UPInt b)
{
    UPInt owner = Sfr31Rd(Sfr31Rd(vm, 0x240), 0xc0);
    UPInt tbl = Sfr31Rd(owner, 0x80);
    if (tbl == 0)
    {
        typedef void (*Init)(UPInt);
        reinterpret_cast<Init>(Sfr31Rd(Sfr31Rd(owner, 0), 0x68))(owner);
        tbl = Sfr31Rd(owner, 0x80);
    }
    SPtr<InstanceTraits::Interface> iface;
    FUN_14241b920(tbl, &iface, a, b);
    Value v(iface->MakeInstance(*iface));
    ExecPushCopy(reinterpret_cast<VM*>(vm), v);
}


// ---- batch 20: raw models of the ArrayDataBase Reserve / ResizeNoConstruct / Resize instances (Data +0, Size +8, Capacity +0x10)
// Kinds of element teardown run by the shrinking path.
enum { Sfr31ElNone, Sfr31ElStrNode, Sfr31ElStrNodeTag, Sfr31ElRcFree, Sfr31ElObj, Sfr31ElValue, Sfr31ElFree };

static void Sfr31ArrReserve(UPInt* a, const void* addr, UPInt n, UPInt esz, UInt32 id, MemoryHeap* dh)
{
    UPInt cap = 0;
    if (n != 0)
    {
        cap = (n + 3) & ~static_cast<UPInt>(3);
        if (a[0] != 0)
        {
            a[0] = reinterpret_cast<UPInt>(Memory::Realloc(reinterpret_cast<void*>(a[0]), cap * esz));
            a[2] = cap;
            return;
        }
        if (dh != 0)
            a[0] = reinterpret_cast<UPInt>(Memory::AllocInHeap(dh, cap * esz, AllocInfo(id, 0, 0)));
        else
            a[0] = reinterpret_cast<UPInt>(Memory::AllocAutoHeap(addr, cap * esz, AllocInfo(id, 0, 0)));
    }
    else if (a[0] != 0)
    {
        Memory::Free(reinterpret_cast<void*>(a[0]));
        a[0] = 0;
    }
    a[2] = cap;
}

static void Sfr31ArrTearDown(UPInt slot, int kind)
{
    const UPInt el = Sfr31Rd(slot, 0);
    switch (kind)
    {
    case Sfr31ElStrNode:
    {
        int* rc = reinterpret_cast<int*>(el + 0x18);
        if (--*rc == 0)
            reinterpret_cast<ASStringNode*>(el)->ReleaseNode();
        break;
    }
    case Sfr31ElStrNodeTag:
        if (el != 0)
        {
            if ((el & 1) == 0)
            {
                int* rc = reinterpret_cast<int*>(el + 0x18);
                if (--*rc == 0)
                    reinterpret_cast<ASStringNode*>(el)->ReleaseNode();
            }
            else
                Sfr31Wr(slot, 0, el - 1);
        }
        break;
    case Sfr31ElRcFree:
        if (el != 0 && --*reinterpret_cast<int*>(el) == 0)
            Memory::Free(reinterpret_cast<void*>(el));
        break;
    case Sfr31ElObj:
        if (el != 0)
            FUN_14257dcd0(reinterpret_cast<void*>(el));
        break;
    case Sfr31ElFree:
        Memory::Free(reinterpret_cast<void*>(el));
        break;
    default:
        break;
    }
}

// Shrink (destroy the tail, release spare capacity) or grow (reserve n + n/4); Size is set to n.
static void Sfr31ArrResizeNC(UPInt* a, const void* addr, UPInt n, UPInt esz, UInt32 id, MemoryHeap* dh, int kind)
{
    const UPInt old = a[1];
    UPInt want = n;
    bool doReserve;
    if (n < old)
    {
        if (kind == Sfr31ElValue)
        {
            AS3::Value* v = reinterpret_cast<AS3::Value*>(a[0]);
            for (UPInt i = old; i > n; --i)
                v[i - 1].~Value();
        }
        else
        {
            for (UPInt i = old; i > n; --i)
                Sfr31ArrTearDown(a[0] + (i - 1) * esz, kind);
        }
        doReserve = n < (a[2] >> 1);
    }
    else
    {
        doReserve = n >= a[2];
        want = n + (n >> 2);
    }
    if (doReserve)
        Sfr31ArrReserve(a, addr, want, esz, id, dh);
    a[1] = n;
}

// MS2-FUNCTIONAL 0x142523850: raw model of ArrayDataBase<8-byte elem, AllocatorGH>::Reserve
// @0x142523850
void Sfr31ReserveGH8a(UPInt* a, const void* addr, UPInt n) { Sfr31ArrReserve(a, addr, n, 8, 2, 0); }

// MS2-FUNCTIONAL 0x142523990: raw model of ArrayDataBase<8-byte elem, AllocatorGH>::Reserve
// @0x142523990
void Sfr31ReserveGH8b(UPInt* a, const void* addr, UPInt n) { Sfr31ArrReserve(a, addr, n, 8, 2, 0); }

// MS2-FUNCTIONAL 0x142523b70: raw model of ArrayDataBase<24-byte elem, AllocatorLH 340>::Reserve
// @0x142523b70
void Sfr31ReserveLH24(UPInt* a, const void* addr, UPInt n) { Sfr31ArrReserve(a, addr, n, 0x18, 340, 0); }

// MS2-FUNCTIONAL 0x142524d80: ResizeNoConstruct of an ASString array
// @0x142524d80
void Sfr31ResizeNCStr(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 8, 2, 0, Sfr31ElStrNode); }

// MS2-FUNCTIONAL 0x142524cd0: ResizeNoConstruct of an array of reference-counted heap blocks
// @0x142524cd0
void Sfr31ResizeNCRc(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 8, 2, 0, Sfr31ElRcFree); }

// MS2-FUNCTIONAL 0x142524a30: ResizeNoConstruct of an SPtr<ASStringNode> array
// @0x142524a30
void Sfr31ResizeNCSPtrStr(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 8, 2, 0, Sfr31ElStrNodeTag); }

// MS2-FUNCTIONAL 0x142524af0: ResizeNoConstruct of a trivially destructible 8-byte array
// @0x142524af0
void Sfr31ResizeNCPod8a(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 8, 2, 0, Sfr31ElNone); }

// MS2-FUNCTIONAL 0x142524b90: ResizeNoConstruct of a trivially destructible 8-byte array
// @0x142524b90
void Sfr31ResizeNCPod8b(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 8, 2, 0, Sfr31ElNone); }

// MS2-FUNCTIONAL 0x142524c30: ResizeNoConstruct of a trivially destructible 8-byte array
// @0x142524c30
void Sfr31ResizeNCPod8c(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 8, 2, 0, Sfr31ElNone); }

// MS2-FUNCTIONAL 0x142524990: ResizeNoConstruct of a Ptr<InteractiveObject> array (heap passed in)
// @0x142524990
void Sfr31ResizeNCIObj(UPInt* a, void* heap, UPInt n) { Sfr31ArrResizeNC(a, 0, n, 8, 327, static_cast<MemoryHeap*>(heap), Sfr31ElObj); }

// MS2-FUNCTIONAL 0x1425248e0: ResizeNoConstruct of a 16-byte-element array whose first word is a released object
// @0x1425248e0
void Sfr31ResizeNCMaskStack(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 0x10, 2, 0, Sfr31ElObj); }

// MS2-FUNCTIONAL 0x142524e20: ResizeNoConstruct of a Value array
// @0x142524e20
void Sfr31ResizeNCValueA(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 0x20, 331, 0, Sfr31ElValue); }

// MS2-FUNCTIONAL 0x142524ec0: ResizeNoConstruct of a Value array
// @0x142524ec0
void Sfr31ResizeNCValueB(UPInt* a, const void* addr, UPInt n) { Sfr31ArrResizeNC(a, addr, n, 0x20, 331, 0, Sfr31ElValue); }

// MS2-FUNCTIONAL 0x142524870: Resize of a POD array that carries its heap at +0x18 (no destruct)
// @0x142524870
void Sfr31ResizeDH(UPInt* a, UPInt n) { Sfr31ArrResizeNC(a, 0, n, 8, 2, reinterpret_cast<MemoryHeap*>(a[3]), Sfr31ElNone); }

// MS2-FUNCTIONAL 0x1425247f0: Resize of a POD array (no destruct)
// @0x1425247f0
void Sfr31ResizePod(UPInt* a, UPInt n) { Sfr31ArrResizeNC(a, a, n, 8, 2, 0, Sfr31ElNone); }

// MS2-FUNCTIONAL 0x142524470: ArrayDataCC<ASString>::Resize; new slots copy the default string (self+0x18)
// @0x142524470
void Sfr31ResizeCCStr(UPInt* a, UPInt n)
{
    const UPInt old = a[1];
    Sfr31ArrResizeNC(a, a, n, 8, 2, 0, Sfr31ElStrNode);
    for (UPInt i = old; i < n; ++i)
    {
        const UPInt def = a[3];
        Sfr31Wr(a[0], i * 8, def);
        ++*reinterpret_cast<int*>(def + 0x18);
    }
}

// MS2-FUNCTIONAL 0x1425245c0: Resize of a pointer array, new slots zeroed
// @0x1425245c0
void Sfr31ResizeObjZero(UPInt* a, UPInt n)
{
    const UPInt old = a[1];
    Sfr31ArrResizeNC(a, a, n, 8, 2, 0, Sfr31ElObj);
    for (UPInt i = old; i < n; ++i)
        Sfr31Wr(a[0], i * 8, 0);
}

// MS2-FUNCTIONAL 0x142524680: Resize of a trivially destructible 8-byte array, new slots zeroed
// @0x142524680
void Sfr31ResizePodZero(UPInt* a, UPInt n)
{
    const UPInt old = a[1];
    Sfr31ArrResizeNC(a, a, n, 8, 2, 0, Sfr31ElNone);
    for (UPInt i = old; i < n; ++i)
        Sfr31Wr(a[0], i * 8, 0);
}

// MS2-FUNCTIONAL 0x1425244e0: Resize of a 24-byte-element array whose first word is a heap block, new slots zeroed
// @0x1425244e0
void Sfr31ResizeBlk24A(UPInt* a, UPInt n)
{
    const UPInt old = a[1];
    Sfr31ArrResizeNC(a, a, n, 0x18, 340, 0, Sfr31ElFree);
    for (UPInt i = old; i < n; ++i)
    {
        Sfr31Wr(a[0], i * 0x18, 0);
        Sfr31Wr(a[0], i * 0x18 + 8, 0);
        Sfr31Wr(a[0], i * 0x18 + 0x10, 0);
    }
}

// MS2-FUNCTIONAL 0x142524710: Resize of a 24-byte-element array whose first word is a heap block, new slots zeroed
// @0x142524710
void Sfr31ResizeBlk24B(UPInt* a, UPInt n)
{
    const UPInt old = a[1];
    Sfr31ArrResizeNC(a, a, n, 0x18, 340, 0, Sfr31ElFree);
    for (UPInt i = old; i < n; ++i)
    {
        Sfr31Wr(a[0], i * 0x18, 0);
        Sfr31Wr(a[0], i * 0x18 + 8, 0);
        Sfr31Wr(a[0], i * 0x18 + 0x10, 0);
    }
}

// ---- batch 21
static inline void Sfr31ReleaseStr(UPInt node)
{
    int* rc = reinterpret_cast<int*>(node + 0x18);
    if (--*rc == 0)
        reinterpret_cast<ASStringNode*>(node)->ReleaseNode();
}

typedef void (*Sfr31VFn1)(UPInt);
typedef void (*Sfr31VFn3)(UPInt, UPInt, UPInt);

// ShapeMeshProvider holder of a TreeShape (render tree entry): swap the provider, queue the entry for propagation.
// MS2-FUNCTIONAL 0x142528eb0: raw-offset model; codegen differs from the exe
// @0x142528eb0
void Sfr31TreeShapeSetShape(UPInt self, UPInt provider)
{
    UPInt data = reinterpret_cast<UPInt>(FUN_142581a40(reinterpret_cast<void*>(self), 0x400));
    if (provider != 0)
        reinterpret_cast<Sfr31VFn1>(Sfr31Rd(Sfr31Rd(provider + 0x10, 0), 8))(provider + 0x10);
    const UPInt old = Sfr31Rd(data, 0x90);
    if (old != 0)
        reinterpret_cast<Sfr31VFn1>(Sfr31Rd(Sfr31Rd(old + 0x10, 0), 0x10))(old + 0x10);
    Sfr31Wr(data, 0x90, provider);
    if (Sfr31Rd(self, 0x28) == 0)
        FUN_142581430(reinterpret_cast<void*>(self));
}

// ShapeObject::SetRatio: only when its render node is a shape node.
// MS2-FUNCTIONAL 0x142528da0: raw-offset model; codegen differs from the exe
// @0x142528da0
void Sfr31ShapeObjectSetRatio(UPInt self, float ratio)
{
    const UPInt node = FUN_1425f26c0(reinterpret_cast<void*>(self));
    if (node == 0)
        return;
    const UPInt page = node & ~static_cast<UPInt>(0xfff);
    const UInt32 idx = static_cast<UInt32>(static_cast<SPInt>(node - page - 0x38) / 0x38);
    const UPInt info = Sfr31Rd(Sfr31Rd(page, 0x20), 0x28 + static_cast<UPInt>(idx) * 8);
    if (*reinterpret_cast<const SInt16*>(info + 8) == 3)
    {
        UPInt data = reinterpret_cast<UPInt>(FUN_142581a40(reinterpret_cast<void*>(Sfr31Rd(self, 0x48)), 0x10));
        *reinterpret_cast<float*>(data + 0x98) = ratio;
    }
}

// checkfilter: the top of the operand stack must be an XML or XMLList instance, else TypeError 1123.
// MS2-FUNCTIONAL 0x142536ab0: behavior-equivalent recovery; codegen differs from exe
// @0x142536ab0
void Sfr31ExecCheckFilter(UPInt vm)
{
    const UPInt top = Sfr31Rd(vm, 0x50);
    const UInt32 k = (*reinterpret_cast<const UInt32*>(top) & 0x1f) - 0xc;
    if (k <= 3)
    {
        const UPInt o = Sfr31Rd(top, 0x10);
        if (o != 0)
        {
            const UPInt tr = Sfr31Rd(o, 0x20);
            const int ty = *reinterpret_cast<const int*>(tr + 0x70);
            if ((ty == 0xd || ty == 0xe) && (*reinterpret_cast<const UInt8*>(tr + 0x68) & 0x20))
                return;
        }
    }
    const UPInt tr = FUN_14250ffc0(reinterpret_cast<VM*>(vm), reinterpret_cast<const Value*>(top));
    UPInt name = 0;
    typedef UPInt* (*GetName)(UPInt, UPInt*);
    UPInt* p = reinterpret_cast<GetName>(Sfr31Rd(Sfr31Rd(tr, 0), 0x38))(tr, &name);
    UPInt err[2];
    FUN_1424d7850(err, 0x463, reinterpret_cast<void*>(vm), *reinterpret_cast<const char* const*>(*p));
    FUN_14252ecb0(reinterpret_cast<void*>(vm), err, &fl::TypeErrorCI);
    Sfr31ReleaseStr(err[1]);
    Sfr31ReleaseStr(name);
}

// Push the elements [start, start + count) of the array storage (clamped to its length) into an interface object.
// MS2-FUNCTIONAL 0x142531550: behavior-equivalent recovery; codegen differs from exe
// @0x142531550
void Sfr31ArrayToGfxValues(UPInt self, UPInt arr, UPInt out, UInt32 start, int count)
{
    SparseArray* sa = reinterpret_cast<SparseArray*>(arr + 0x38);
    const UInt32 len = static_cast<UInt32>(sa->GetSize());
    const UPInt root = Sfr31Rd(Sfr31Rd(self, 8), 0x18);
    if (start >= len)
        return;
    if (count < 0)
        count = static_cast<int>(len - start);
    UPInt gv[3] = { 0, 0, 0 };
    UInt32 end = start + static_cast<UInt32>(count);
    if (len < end)
        end = len;
    for (UInt32 i = start; i < end; ++i)
    {
        const Value& v = sa->At(i);
        FUN_1424e42c0(root, &v, gv);
        reinterpret_cast<Sfr31VFn3>(Sfr31Rd(Sfr31Rd(out, 0), 8))(out, i, reinterpret_cast<UPInt>(gv));
    }
    if ((reinterpret_cast<UInt32*>(gv)[2] >> 6) & 1)
    {
        typedef void (*Rel)(UPInt, UPInt*, UPInt);
        reinterpret_cast<Rel>(Sfr31Rd(Sfr31Rd(gv[0], 0), 0x10))(gv[0], gv, gv[2]);
    }
}

// Tracer: push the constant-pool string index as a String value (the empty string becomes a null object).
// MS2-FUNCTIONAL 0x14253f690: behavior-equivalent recovery; codegen differs from exe
// @0x14253f690
void Sfr31TracePushString(State* st, UInt32 index)
{
    const UPInt tracer = Sfr31Rd(reinterpret_cast<UPInt>(st), 0);
    FUN_14251fcd0(tracer, index);
    UPInt lit[2];
    FUN_142545310(Sfr31Rd(TrFile(tracer), 0x70) + static_cast<UPInt>(index) * 8, lit);
    ASStringManager* mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(Sfr31Rd(TrVM(tracer), 0x10), 0x1e8));
    ASStringNode* node = mgr->CreateStringNode(reinterpret_cast<const char*>(lit[0]), lit[1]);
    UPInt raw[4] = { 10, 0, 0, 0 };
    UInt32* kind = reinterpret_cast<UInt32*>(raw);
    int* rc = reinterpret_cast<int*>(reinterpret_cast<UPInt>(node) + 0x18);
    const int base = *rc;
    *rc = base + 1;
    if (reinterpret_cast<UPInt>(node) == Sfr31Rd(reinterpret_cast<UPInt>(node), 8) + 0x68)
    {
        *kind = 0xc;
        raw[2] = 0;
        raw[3] = lit[1];
    }
    else
    {
        *rc = base + 2;
        raw[2] = reinterpret_cast<UPInt>(node);
    }
    StV(st).OpStack().PushBack(*reinterpret_cast<const Value*>(raw));
    reinterpret_cast<Value*>(raw)->~Value();
    Sfr31ReleaseStr(reinterpret_cast<UPInt>(node));
}

// Set the owned object of a holder {obj, ownsFlag}: destroy the previous owned object (a value array plus its names).
// MS2-FUNCTIONAL 0x142524290: behavior-equivalent recovery; codegen differs from exe
// @0x142524290
void Sfr31SetOwnedObject(UPInt* holder, UPInt np, char own)
{
    const UPInt old = holder[0];
    if (old != np)
    {
        if (old != 0 && static_cast<char>(holder[1]) != 0)
        {
            *reinterpret_cast<char*>(&holder[1]) = 0;
            Sfr31ReleaseStr(Sfr31Rd(old, 0x38));
            UPInt* names = reinterpret_cast<UPInt*>(old + 0x20);
            for (UPInt i = names[1]; i > 0; --i)
                Sfr31ReleaseStr(Sfr31Rd(names[0], (i - 1) * 8));
            if (names[0] != 0)
                Memory::Free(reinterpret_cast<void*>(names[0]));
            Value* vals = reinterpret_cast<Value*>(Sfr31Rd(old, 8));
            for (UPInt i = Sfr31Rd(old, 0x10); i > 0; --i)
                vals[i - 1].~Value();
            Memory::Free(reinterpret_cast<void*>(Sfr31Rd(old, 8)));
            Memory::Free(reinterpret_cast<void*>(old));
        }
        holder[0] = np;
    }
    *reinterpret_cast<char*>(&holder[1]) = (np != 0 && own != 0) ? 1 : 0;
}
// ---- batch 22
static void Sfr31PushByte(UPInt* a, UInt8 b)
{
    const UPInt n = a[1] + 1;
    if (n < a[1])
    {
        if (n >= (a[2] >> 1))
            goto store;
    }
    else if (n < a[2])
        goto store;
    Sfr31ArrReserve(a, a, n < a[1] ? n : n + (n >> 2), 1, 2, 0);
store:
    a[1] = n;
    *reinterpret_cast<UInt8*>(a[0] + n - 1) = b;
}

// Variable-length integer writer: the low two bits of the first byte give the byte count - 1.
// MS2-FUNCTIONAL 0x142531bf0: raw-offset model; codegen differs from the exe
// @0x142531bf0
UPInt Sfr31WriteVarint(UPInt** arr, UInt32 v)
{
    UPInt* a = *arr;
    const UInt8 b0 = static_cast<UInt8>(v << 2);
    if (v < 0x40)
    {
        Sfr31PushByte(a, b0);
        return 1;
    }
    if (v < 0x4000)
    {
        Sfr31PushByte(a, b0 | 1);
        Sfr31PushByte(*arr, static_cast<UInt8>(v >> 6));
        return 2;
    }
    if (v < 0x400000)
    {
        Sfr31PushByte(a, b0 | 2);
        Sfr31PushByte(*arr, static_cast<UInt8>(v >> 6));
        Sfr31PushByte(*arr, static_cast<UInt8>(v >> 14));
        return 3;
    }
    Sfr31PushByte(a, b0 | 3);
    Sfr31PushByte(*arr, static_cast<UInt8>(v >> 6));
    Sfr31PushByte(*arr, static_cast<UInt8>(v >> 14));
    Sfr31PushByte(*arr, static_cast<UInt8>(v >> 22));
    return 4;
}

// Record writer: emits a leading 0 byte on the first record, then a 1 tag and three varints.
// MS2-FUNCTIONAL 0x14252c8b0: raw-offset model; codegen differs from the exe
// @0x14252c8b0
void Sfr31WriteRecord3(UPInt self, UInt32 a, UInt32 b, UInt32 c)
{
    UPInt* arr = reinterpret_cast<UPInt*>(Sfr31Rd(self, 0x48));
    UPInt* cur = arr;
    if (*reinterpret_cast<int*>(self + 0x10) == 0)
    {
        Sfr31PushByte(arr, 0);
        *reinterpret_cast<int*>(self + 0x10) = 1;
    }
    Sfr31PushByte(arr, 1);
    Sfr31WriteVarint(&cur, a);
    Sfr31WriteVarint(&cur, b);
    Sfr31WriteVarint(&cur, c);
    *reinterpret_cast<int*>(self + 0x10) = 2;
}

// Evaluates a virtual getter into a scratch Value; a non-null result is handed to FUN_1424e0860, else the out slot is cleared.
// MS2-FUNCTIONAL 0x142531f40: raw-offset model; codegen differs from the exe
// @0x142531f40
UPInt Sfr31FetchOrClear(UPInt self, UPInt* out, UPInt src, UInt32 arg, UPInt arg2)
{
    UInt32 tmp[6] = {0, 0, 0, 0, 0, 0};
    typedef void (*Fn)(UPInt, void*, UInt32, UPInt, int);
    reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(src, 0), 0x60))(src, tmp, arg, arg2, 1);
    UPInt result;
    const UInt32 kind = tmp[0] & 0x1f;
    if (*reinterpret_cast<UInt8*>(self + 0x180) == 0 && kind != 0 && (kind - 0xc > 3 || *reinterpret_cast<UPInt*>(&tmp[4]) != 0))
    {
        FUN_1424e0860(out);
        result = 1;
    }
    else
    {
        UPInt old = *out;
        if (old != 0)
        {
            if ((old & 1) == 0 && (*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0)
            {
                *reinterpret_cast<UInt32*>(old + 0x10) -= 1;
                FUN_1423dfa20(reinterpret_cast<void*>(old));
            }
            *out = 0;
        }
        *reinterpret_cast<UInt8*>(self + 0x180) = 0;
        result = 0;
    }
    if (kind > 9)
    {
        if (((tmp[0] >> 9) & 1) == 0)
            FUN_142521f00(tmp);
        else
        {
            int* rc = *reinterpret_cast<int**>(&tmp[4]);
            if (--*rc == 0)
                Memory::pGlobalHeap->Free(rc);
        }
    }
    return result;
}

// Traits::StoreScopeStack: appends copies of scope entries [start, n) onto the stored scope array.
// MS2-FUNCTIONAL 0x14252cad0: raw-offset model; codegen differs from the exe
// @0x14252cad0
void Sfr31StoreScopeStack(UPInt self, UPInt start, UPInt* src)
{
    const UPInt n = src[1];
    UPInt* dst = reinterpret_cast<UPInt*>(self + 0xa0);
    if (dst[2] < dst[1] + n)
        Sfr31ArrReserve(dst, reinterpret_cast<void*>(dst[3]), dst[1] + n, 0x20, 2, reinterpret_cast<MemoryHeap*>(dst[3]));
    for (UPInt i = start; i < n; ++i)
    {
        const AS3::Value* s = reinterpret_cast<const AS3::Value*>(src[0]) + i;
        FUN_1424201a0(dst, reinterpret_cast<void*>(dst[3]), dst[1] + 1);
        new (reinterpret_cast<AS3::Value*>(dst[0]) + dst[1] - 1) AS3::Value(*s);
    }
}

// exec_esc_xattr: converts the top of stack to a string and replaces it with its XML-escaped form.
// MS2-FUNCTIONAL 0x142538700: behavior-equivalent recovery; codegen differs from exe
// @0x142538700
void Sfr31ExecEscXAttr(UPInt vm)
{
    const UPInt mgr = Sfr31Rd(Sfr31Rd(vm, 0x10), 0x1e8);
    AS3::Value* top = reinterpret_cast<AS3::Value*>(Sfr31Rd(vm, 0x50));
    UPInt tmpNode = 0;
    ASString str(reinterpret_cast<ASStringNode*>(mgr + 0x40));
    const bool ok = *FUN_1424f1390(top, &tmpNode, &str);
    if (ok)
        *top = str;
    if (ok)
    {
        StringBuffer buf(Memory::pGlobalHeap);
        ASString cur(reinterpret_cast<ASStringNode*>(Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10)));
        Instances::fl::XML::EscapeElementValue(buf, cur);
        const char* c = buf.ToCStr();
        ASString res(reinterpret_cast<ASStringManager*>(mgr)->CreateStringNode(c ? c : "", buf.GetSize()));
        *top = res;
    }
}
// ---- batch 23
// Native call whose first argument must be a non-null object: reports TypeError 1009/1010 otherwise, then dispatches through the object.
// MS2-FUNCTIONAL 0x142533fd0: raw-offset model; codegen differs from the exe
// @0x142533fd0
void Sfr31CallOnObjectArg(UPInt vmAddr, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, argc);
    const UInt32* a0 = reinterpret_cast<const UInt32*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8), 8));
    const UInt32 k = (a0[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(a0), 0x10);
    if ((a0[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        const UInt32 id = (k < 4 ? (obj != 0) : 1u) + 0x3f1;
        VM::Error e(static_cast<VM::ErrorID>(id), vm);
        vm.ThrowTypeError(e);
    }
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt o = Sfr31Rd(reinterpret_cast<UPInt>(a0), 0x10);
        typedef void (*Fn)(UPInt, const Value*, const void*, UInt32, void*);
        const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
        void* args = cnt > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(o, 0), 0x50))(o, &Value::GetUndefined(), a0, argc, args);
    }
    FUN_1424de9e0(raBuf);
}

// The top of the operand stack is converted to an int index and popped; the new top's object is queried at that index and
// the top replaced by the resulting int.
// MS2-FUNCTIONAL 0x14253abd0: behavior-equivalent recovery; codegen differs from exe
// @0x14253abd0
void Sfr31ExecIndexedQuery(UPInt vm)
{
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(vm, 0x50));
    UInt8 okBuf[8];
    long out;
    const bool ok = *FUN_1424f0d30(top, okBuf, &out) != 0;
    UInt32 idx = 0;
    if (ok)
    {
        top->SetSInt32(static_cast<SInt32>(out));
        idx = *reinterpret_cast<const UInt32*>(reinterpret_cast<UPInt>(top) + 0x10);
    }
    top->~Value();
    Sfr31Wr(vm, 0x50, Sfr31Rd(vm, 0x50) - 0x20);
    if (ok)
    {
        const UPInt cur = reinterpret_cast<UPInt>(top) - 0x20;
        const UPInt o = Sfr31Rd(cur, 0x10);
        typedef const UInt32* (*Fn)(UPInt, void*, UInt32);
        const UInt32* r = reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(o, 0), 0x88))(o, okBuf, idx);
        Value res(static_cast<SInt32>(*r));
        reinterpret_cast<Value*>(cur)->Assign(res);
    }
}
// ---- batch 24
// Value -> Boolean conversion used by the tracer, in place.
// MS2-FUNCTIONAL 0x14252f4f0: behavior-equivalent recovery; codegen differs from exe
// @0x14252f4f0
void Sfr31ValueToBool(Value* v)
{
    const UInt32 kind = *reinterpret_cast<const UInt32*>(v) & 0x1f;
    const UPInt p = reinterpret_cast<UPInt>(v);
    bool r = false;
    switch (kind)
    {
    case 1:
        r = *reinterpret_cast<const UInt8*>(p + 0x10) != 0;
        break;
    case 2:
    case 3:
        r = *reinterpret_cast<const int*>(p + 0x10) != 0;
        break;
    case 4:
    {
        const UInt64 bits = *reinterpret_cast<const UInt64*>(p + 0x10);
        const bool nan = (bits & 0x7ff0000000000000ull) == 0x7ff0000000000000ull && (bits & 0xfffffffffffffull) != 0;
        r = !nan && (bits & 0x7fffffffffffffffull) != 0;
        break;
    }
    case 5:
    case 7:
    case 0x10:
    case 0x11:
        r = true;
        break;
    case 10:
    {
        const UPInt node = Sfr31Rd(p, 0x10);
        r = node != 0 && *reinterpret_cast<const int*>(node + 0x20) != 0;
        break;
    }
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
        r = Sfr31Rd(p, 0x10) != 0;
        break;
    default:
        break;
    }
    v->SetBool(r);
}

static bool Sfr31SwapChildrenTail(UPInt owner, UPInt i1, UPInt i2)
{
    if (i1 >= Sfr31Rd(owner, 0xe0) || i2 >= Sfr31Rd(owner, 0xe0))
        return false;
    if (!FUN_1425fb480(reinterpret_cast<void*>(owner + 0xd8), reinterpret_cast<void*>(owner), i1, i2))
        return false;
    const UPInt list = Sfr31Rd(owner, 0xd8);
    const UPInt c1 = Sfr31Rd(list, i1 * 0x10);
    const UPInt c2 = Sfr31Rd(list, i2 * 0x10);
    typedef void (*Fn)(UPInt, UInt32);
    if (c1 != 0)
    {
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(c1, 0), 0x188))(c1, 0);
        *reinterpret_cast<UInt32*>(c1 + 0x30) = 0;
        *reinterpret_cast<UInt32*>(c1 + 0x2c) = 0xffffffffu;
    }
    if (c2 != 0)
    {
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(c2, 0), 0x188))(c2, 0);
        *reinterpret_cast<UInt32*>(c2 + 0x30) = 0;
        *reinterpret_cast<UInt32*>(c2 + 0x2c) = 0xffffffffu;
    }
    *reinterpret_cast<UInt8*>(owner + 0x100) |= 3;
    typedef UPInt (*Fn2)(UPInt);
    UPInt avm = 0;
    if (*reinterpret_cast<const SInt8*>(c1 + 0x6a) < 0)
    {
        const UPInt sub = c1 + static_cast<UPInt>(*reinterpret_cast<const UInt8*>(c1 + 0x6d)) * 4;
        const UPInt r = reinterpret_cast<Fn2>(Sfr31Rd(Sfr31Rd(sub, 0), 8))(sub);
        avm = r != 0 ? r - 0x30 : 0;
        FUN_142517ed0(reinterpret_cast<void*>(avm));
    }
    if (*reinterpret_cast<const SInt8*>(c2 + 0x6a) < 0)
    {
        const UPInt sub = c2 + static_cast<UPInt>(*reinterpret_cast<const UInt8*>(c2 + 0x6d)) * 4;
        const UPInt r = reinterpret_cast<Fn2>(Sfr31Rd(Sfr31Rd(sub, 0), 8))(sub);
        FUN_142517ed0(reinterpret_cast<void*>(r != 0 ? r - 0x30 : 0));
    }
    return true;
}

// AvmDisplayObjContainer::SwapChildren: swaps two children of the display list.
// MS2-FUNCTIONAL 0x14252e590: raw-offset model; codegen differs from the exe
// @0x14252e590
bool Sfr31SwapChildren(UPInt self, UPInt ch1, UPInt ch2)
{
    const UPInt owner = Sfr31Rd(self, 0x18);
    const UPInt list = owner + 0xd8;
    const UInt32 i1 = static_cast<UInt32>(FUN_1425f9200(reinterpret_cast<void*>(Sfr31Rd(self, 0x18) + 0xd8), reinterpret_cast<void*>(ch1)));
    const UInt32 i2 = static_cast<UInt32>(FUN_1425f9200(reinterpret_cast<void*>(list), reinterpret_cast<void*>(ch2)));
    return Sfr31SwapChildrenTail(owner, i1, i2);
}

// AvmDisplayObjContainer::SwapChildrenAt
// MS2-FUNCTIONAL 0x14252e6d0: raw-offset model; codegen differs from the exe
// @0x14252e6d0
bool Sfr31SwapChildrenAt(UPInt self, UInt32 i1, UInt32 i2)
{
    return Sfr31SwapChildrenTail(Sfr31Rd(self, 0x18), i1, i2);
}
// ---- batch 25
// Strict equality of two values (same kind: payload compare; mixed Int/UInt/Number: numeric compare).
// MS2-FUNCTIONAL 0x14252cbf0: behavior-equivalent recovery; codegen differs from exe
// @0x14252cbf0
bool Sfr31StrictEquals(const UInt32* a, const UInt32* b)
{
    const UInt32 ka = a[0] & 0x1f;
    const UInt32 kb = b[0] & 0x1f;
    const UPInt pa = reinterpret_cast<UPInt>(a);
    const UPInt pb = reinterpret_cast<UPInt>(b);
    if (ka != kb)
    {
        if (ka - 2 > 2 || kb - 2 > 2)
            return false;
        if (ka - 2 < 2)
        {
            if (kb == 2)
                return static_cast<int>(b[4]) >= 0 && a[4] == b[4];
            if (kb == 4)
            {
                const double d = static_cast<double>(static_cast<UInt64>(a[4]));
                const double e = *reinterpret_cast<const double*>(pb + 0x10);
                return d == e;
            }
        }
        else
        {
            const double d = kb == 2 ? static_cast<double>(static_cast<int>(b[4])) : static_cast<double>(static_cast<UInt64>(b[4]));
            return *reinterpret_cast<const double*>(pa + 0x10) == d;
        }
    }
    switch (ka)
    {
    case 0:
        return true;
    case 1:
        return static_cast<char>(a[4]) == static_cast<char>(b[4]);
    case 2:
    case 3:
        return a[4] == b[4];
    case 4:
        return *reinterpret_cast<const double*>(pa + 0x10) == *reinterpret_cast<const double*>(pb + 0x10);
    case 5:
    case 10:
    case 11:
        return Sfr31Rd(pa, 0x10) == Sfr31Rd(pb, 0x10);
    case 7:
        return a[4] == b[4] && Sfr31Rd(pa, 0x18) == Sfr31Rd(pb, 0x18);
    case 0x10:
        return Sfr31Rd(pa, 0x18) == Sfr31Rd(pb, 0x18) && Sfr31Rd(pa, 0x10) == Sfr31Rd(pb, 0x10);
    case 0x11:
        return Sfr31Rd(pa, 0x18) == Sfr31Rd(pb, 0x18) && a[4] == b[4];
    case 6:
    case 8:
    case 9:
        return false;
    default:
        return ka <= 0x11 && Sfr31Rd(pa, 0x10) == Sfr31Rd(pb, 0x10);
    }
}

// Tracer ops taking the two counts of a call and pushing an object value.
// MS2-FUNCTIONAL 0x142533cb0: behavior-equivalent recovery; codegen differs from exe
// @0x142533cb0
void Sfr31TraceCallPushObject(State* st, UInt32 a, UInt32 b)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), a);
    FUN_14251fcd0(s.Tracer(), b);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, b);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
    popped.Get().~Value();
}

// MS2-FUNCTIONAL 0x142535540: behavior-equivalent recovery; codegen differs from exe
// @0x142535540
void Sfr31TraceCallPushObjectB(State* st, UInt32 a, UInt32 b)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), a);
    FUN_14251fcd0(s.Tracer(), b);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, b);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
    popped.Get().~Value();
}

struct Sfr31MnCtx
{
    UPInt vm;
    State* st;
    int pops;
};

static inline const Abc::Multiname& Sfr31MnEntry(UPInt abcLink, UInt32 idx)
{
    const UPInt file = TrRd(abcLink, 0x28);
    return *reinterpret_cast<const Abc::Multiname*>(idx == 0 ? file + 0xe8 : static_cast<UPInt>(idx) * 0x10 + TrRd(file, 0xb8));
}

// Tracer op with a multiname: notes the name operand(s), pops the object and pushes an object value.
// MS2-FUNCTIONAL 0x142537f00: behavior-equivalent recovery; codegen differs from exe
// @0x142537f00
void Sfr31TraceMnPopPush(State* st, UInt32 idx)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    const UPInt link = TrAbcLink(s.Tracer());
    Sfr31MnCtx ctx = {TrRd(link, 0x20), st, 0};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntry(link, idx));
    ctx.pops += FUN_142520380(&ctx, &mn);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++ctx.pops;
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x210));
    s.OpStack().PushBack(t.Get());
    popped.Get().~Value();
}

// Tracer op with a multiname that pops the object and the value without pushing.
// MS2-FUNCTIONAL 0x14253b640: behavior-equivalent recovery; codegen differs from exe
// @0x14253b640
void Sfr31TraceMnPop2(State* st, UInt32 idx)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    const UPInt link = TrAbcLink(s.Tracer());
    Sfr31MnCtx ctx = {TrRd(link, 0x20), st, 0};
    TrPopped first;
    FUN_14251cd30(st, &first.Get());
    ++ctx.pops;
    Multiname mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntry(link, idx));
    ctx.pops += FUN_142520380(&ctx, &mn);
    TrPopped second;
    FUN_14251cd30(st, &second.Get());
    ++ctx.pops;
    second.Get().~Value();
    first.Get().~Value();
}
// ---- batch 26
static void Sfr31ThrowIfNotObject(VM& vm, const UInt32* v)
{
    const UInt32 k = (v[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    if ((v[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        VM::Error e(static_cast<VM::ErrorID>((k < 4 ? (obj != 0) : 1u) + 0x3f1), vm);
        vm.ThrowTypeError(e);
    }
}

// Constructs the named class into a scratch value; a non-null object result is moved into *out, else *out is cleared.
// MS2-FUNCTIONAL 0x142532130: raw-offset model; codegen differs from the exe
// @0x142532130
UInt8* Sfr31ConstructOrClear(UPInt self, UInt8* ret, UPInt* out, const char* gname, UInt32 argc, const Value* argv)
{
    Value tmp;
    reinterpret_cast<VM*>(self)->Construct(gname, tmp, argc, argv, true);
    const UInt32 kind = *reinterpret_cast<const UInt32*>(&tmp) & 0x1f;
    if (*reinterpret_cast<UInt8*>(self + 0x180) == 0 && kind != 0 &&
        (kind - 0xc > 3 || Sfr31Rd(reinterpret_cast<UPInt>(&tmp), 0x10) != 0))
    {
        FUN_1424e0860(out);
        *ret = 1;
    }
    else
    {
        UPInt old = *out;
        if (old != 0)
        {
            if ((old & 1) == 0 && (*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0)
            {
                *reinterpret_cast<UInt32*>(old + 0x10) -= 1;
                FUN_1423dfa20(reinterpret_cast<void*>(old));
            }
            *out = 0;
        }
        *reinterpret_cast<UInt8*>(self + 0x180) = 0;
        *ret = 0;
    }
    return ret;
}

// pushwith: the (non-null) object on top of the operand stack moves onto the scope stack.
// MS2-FUNCTIONAL 0x14253f4e0: behavior-equivalent recovery; codegen differs from exe
// @0x14253f4e0
void Sfr31ExecPushWith(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(vmAddr, 0x50));
    Sfr31ThrowIfNotObject(vm, reinterpret_cast<const UInt32*>(top));
    if ((*reinterpret_cast<const UInt32*>(top) & 0x1f) == 0)
        return;
    vm.ScopeStack.PushBack(Value::GetUndefined());
    UInt32* dst = reinterpret_cast<UInt32*>(vm.ScopeStack.GetDataPtr() + vm.ScopeStack.GetSize() - 1);
    UInt32* src = reinterpret_cast<UInt32*>(top);
    for (int i = 0; i < 8; ++i)
        dst[i] = src[i];
    src[0] = 0;
    top->~Value();
    Sfr31Wr(vmAddr, 0x50, Sfr31Rd(vmAddr, 0x50) - 0x20);
}

// Native with a required object argument, which must be an Object-kind value; replaces it with the result of its virtual call.
// MS2-FUNCTIONAL 0x142532dc0: raw-offset model; codegen differs from the exe
// @0x142532dc0
void Sfr31CallClassArg(UPInt vmAddr, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, argc);
    Value* a0 = reinterpret_cast<Value*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8), 8));
    Sfr31ThrowIfNotObject(vm, reinterpret_cast<const UInt32*>(a0));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        if ((*reinterpret_cast<const UInt32*>(a0) & 0x1f) == 0xd)
        {
            const UPInt o = Sfr31Rd(reinterpret_cast<UPInt>(a0), 0x10);
            const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
            void* args = cnt > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
            typedef const Value* (*Fn)(UPInt, UInt32, void*);
            a0->Assign(*reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(o, 0), 0xb8))(o, cnt, args));
        }
        else
        {
            VM::Error e(static_cast<VM::ErrorID>(0x467), vm);
            vm.ThrowTypeError(e);
        }
    }
    FUN_1424de9e0(raBuf);
}

// Tracer op: replaces the popped value with the instance traits it denotes (primitives collapse to the Object traits).
// MS2-FUNCTIONAL 0x1425331a0: behavior-equivalent recovery; codegen differs from exe
// @0x1425331a0
void Sfr31TraceTopInstanceTraits(State* st)
{
    StV s(st);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    const UPInt p = reinterpret_cast<UPInt>(&popped.Get());
    const UInt32 k = *reinterpret_cast<const UInt32*>(p) & 0x1f;
    UPInt tr = Sfr31Rd(p, 0x10);
    if (k == 9)
        tr = Sfr31Rd(tr, 0xc0);
    else if (k == 0xd)
        tr = Sfr31Rd(Sfr31Rd(tr, 0x20), 0xc0);
    else if (k != 8)
    {
        popped.Get().~Value();
        return;
    }
    if (tr != 0)
    {
        if (FUN_142514a80(s.Tracer(), reinterpret_cast<void*>(tr)))
            tr = Sfr31Rd(Sfr31Rd(TrVM(s.Tracer()), 0x1f8), 0xc0);
        TrTraitsScratch t;
        t.SetTraits(*reinterpret_cast<InstanceTraits::Traits*>(tr));
        s.Top().Assign(t.Get());
    }
    popped.Get().~Value();
}
// ---- batch 27
struct Sfr31RawTraitsVal
{
    UInt32 w0;
    UPInt w1, w2, w3;
};

// Tracer find-property core: resolves the multiname and pushes the property value, or the Object traits when unresolved.
static void Sfr31TraceFindProp(State* st, UInt32 idx, UInt32 fallbackTag)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    const UPInt link = TrAbcLink(s.Tracer());
    Sfr31MnCtx ctx = {TrRd(link, 0x20), st, 0};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntry(link, idx));
    ctx.pops += FUN_142520380(&ctx, &mn);
    UPInt pr[6] = {0, 0, 0, 0, 0, 0};
    UInt8 t1[8], t2[8];
    FUN_142501e80(st, pr, &mn, t1, t2);
    Value& res = *reinterpret_cast<Value*>(&pr[2]);
    const UPInt f = pr[0];
    Sfr31RawTraitsVal fb;
    const Value* push = &res;
    if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
    {
        fb.w0 = fallbackTag;
        fb.w1 = 0;
        fb.w2 = Sfr31Rd(Sfr31Rd(TrVM(s.Tracer()), 0x1f8), 0xc0);
        fb.w3 = 0;
        push = reinterpret_cast<const Value*>(&fb);
    }
    s.OpStack().PushBack(*push);
    res.~Value();
}

// MS2-FUNCTIONAL 0x142538840: behavior-equivalent recovery; codegen differs from exe
// @0x142538840
void Sfr31TraceFindPropA(State* st, UInt32 idx) { Sfr31TraceFindProp(st, idx, 0x48); }

// MS2-FUNCTIONAL 0x142538bc0: behavior-equivalent recovery; codegen differs from exe
// @0x142538bc0
void Sfr31TraceFindPropB(State* st, UInt32 idx) { Sfr31TraceFindProp(st, idx, 8); }

// Tracer op: an operand of a type-describing kind becomes its instance traits, anything else is pushed back as it was.
// MS2-FUNCTIONAL 0x142536dd0: behavior-equivalent recovery; codegen differs from exe
// @0x142536dd0
void Sfr31TraceTypeOperand(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, argc);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    const UPInt p = reinterpret_cast<UPInt>(&popped.Get());
    const UInt32 k = *reinterpret_cast<const UInt32*>(p) & 0x1f;
    UPInt tr = Sfr31Rd(p, 0x10);
    bool conv = true;
    if (k == 9)
        tr = Sfr31Rd(tr, 0xc0);
    else if (k == 0xd)
        tr = Sfr31Rd(Sfr31Rd(tr, 0x20), 0xc0);
    else if (k != 8)
        conv = false;
    if (conv)
    {
        Sfr31RawTraitsVal v = {8, 0, tr, 0};
        s.OpStack().PushBack(*reinterpret_cast<const Value*>(&v));
    }
    else
        s.OpStack().PushBack(popped.Get());
    popped.Get().~Value();
}
// ---- batch 28
struct Sfr31ExecMnCtx
{
    UPInt vm;
    UPInt stack;
    UPInt file;
};

static inline void Sfr31ThrowIfNullOperand(UPInt vmAddr, const UInt32* v)
{
    const UInt32 k = (v[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    if ((v[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        VM::Error e(static_cast<VM::ErrorID>((k < 4 ? (obj != 0) : 1u) + 0x3f1), *reinterpret_cast<VM*>(vmAddr));
        reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(e);
    }
}

// Takes the Value on top of the operand stack bitwise, without touching refcounts.
static inline void Sfr31TakeTop(UPInt vmAddr, Sfr31RawTraitsVal& out)
{
    const UPInt top = Sfr31Rd(vmAddr, 0x50);
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&out)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(vmAddr, 0x50, top - 0x20);
}

// setproperty: pops the value and the object, resolves the multiname and stores the value.
// MS2-FUNCTIONAL 0x14253b790: raw-offset model; codegen differs from the exe
// @0x14253b790
void Sfr31ExecSetProperty(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Sfr31RawTraitsVal val;
    Sfr31TakeTop(cvm, val);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    const UPInt st = Sfr31Rd(ctx.stack, 8);
    Sfr31RawTraitsVal obj;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(st)[i];
    Sfr31Wr(ctx.stack, 8, st - 0x20);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(&obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        UInt8 ret[16];
        *reinterpret_cast<UInt32*>(vmAddr + 0x30) += 1;
        FUN_142528810(ret, vmAddr, &obj, &mn, &val);
        *reinterpret_cast<UInt32*>(vmAddr + 0x30) -= 1;
    }
    reinterpret_cast<Value*>(&obj)->~Value();
    mn.~Multiname();
    reinterpret_cast<Value*>(&val)->~Value();
}

// getsuper: reads the named property of the object on top of the stack through the current frame's super traits.
// MS2-FUNCTIONAL 0x14253a430: raw-offset model; codegen differs from the exe
// @0x14253a430
void Sfr31ExecGetSuper(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    UPInt top = Sfr31Rd(ctx.stack, 8);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(top));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        Sfr31RawTraitsVal obj;
        for (int i = 0; i < 8; ++i)
            reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(top)[i];
        *reinterpret_cast<UInt32*>(top) = 0;
        const UPInt n = Sfr31Rd(vmAddr, 0x78) - 1;
        const UPInt frame = Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (n >> 6) * 8) + 0x40 + (n & 0x3f) * 0xa8;
        UInt8 ret[16];
        UInt8* r = FUN_14250ef80(ret, vmAddr, Sfr31Rd(frame, 0), reinterpret_cast<void*>(top), &obj, &mn, 0);
        if (*r == 0)
        {
            VM::Error e(static_cast<VM::ErrorID>(0x40b), *reinterpret_cast<VM*>(vmAddr));
            reinterpret_cast<VM*>(vmAddr)->ThrowReferenceError(e);
        }
        reinterpret_cast<Value*>(&obj)->~Value();
    }
    mn.~Multiname();
}
// ---- batch 29
// getlex-style resolve: pushes the value the multiname resolves to, or raises a ReferenceError.
// MS2-FUNCTIONAL 0x142538d30: raw-offset model; codegen differs from the exe
// @0x142538d30
void Sfr31ExecGetLex(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) != 0)
    {
        mn.~Multiname();
        return;
    }
    UPInt pr[4] = {0, 0, 0, 0};
    FUN_142502570(vmAddr, pr, &mn);
    Value& res = *reinterpret_cast<Value*>(&pr[1]);
    const UPInt f = pr[0];
    if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
    {
        VM::Error e(static_cast<VM::ErrorID>(0x429), *reinterpret_cast<VM*>(vmAddr));
        reinterpret_cast<VM*>(vmAddr)->ThrowReferenceError(e);
    }
    else
        ExecPushCopy(reinterpret_cast<VM*>(vmAddr), res);
    res.~Value();
    mn.~Multiname();
}

typedef UInt8* (*Sfr31VFnDel)(UPInt self, UInt8* ret, const void* obj, const void* mn);
typedef UPInt* (*Sfr31VFnName)(UPInt self, UPInt* out);

// deleteproperty-style op: asks the VM helper object to handle the name; when it declines, pops the operand and raises a TypeError naming the traits.
// MS2-FUNCTIONAL 0x142539230: raw-offset model; codegen differs from the exe
// @0x142539230
void Sfr31ExecDeleteProp(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    const UPInt obj = Sfr31Rd(ctx.stack, 8);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt helper = Sfr31Rd(vmAddr, 0x40);
        UInt8 ret[16];
        Sfr31VFnDel fn = *reinterpret_cast<Sfr31VFnDel*>(Sfr31Rd(helper, 0) + 0x68);
        if (*fn(helper, ret, reinterpret_cast<const void*>(obj), &mn) == 0)
        {
            Value* top = reinterpret_cast<Value*>(Sfr31Rd(vmAddr, 0x50));
            top->~Value();
            Sfr31Wr(vmAddr, 0x50, Sfr31Rd(vmAddr, 0x50) - 0x20);
            const UPInt tr = FUN_14250ffc0(reinterpret_cast<VM*>(vmAddr), reinterpret_cast<const Value*>(obj));
            UPInt nameNode = 0;
            Sfr31VFnName nf = *reinterpret_cast<Sfr31VFnName*>(Sfr31Rd(tr, 0) + 0x38);
            UPInt* p = nf(tr, &nameNode);
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d7850(eb, 0x3f8, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(Sfr31Rd(*p, 0)));
            reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
            Sfr31ReleaseStr(nameNode);
        }
    }
    mn.~Multiname();
}

// initproperty: pops the value and the object, resolves the multiname and initializes the property.
// MS2-FUNCTIONAL 0x14253ffa0: raw-offset model; codegen differs from the exe
// @0x14253ffa0
void Sfr31ExecInitProperty(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Sfr31RawTraitsVal val;
    Sfr31TakeTop(cvm, val);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    const UPInt st = Sfr31Rd(ctx.stack, 8);
    Sfr31RawTraitsVal obj;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(st)[i];
    Sfr31Wr(ctx.stack, 8, st - 0x20);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(&obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        UInt8 ret[16];
        FUN_142528810(ret, vmAddr, &obj, &mn, &val);
    }
    reinterpret_cast<Value*>(&obj)->~Value();
    mn.~Multiname();
    reinterpret_cast<Value*>(&val)->~Value();
}
// ---- batch 30
// Tracer op: the popped operand becomes the traits describing its class: the Object traits for a null value, otherwise the
// traits of its dynamic class (or its instance traits when it is a class/function traits holder).
// MS2-FUNCTIONAL 0x14253d160: raw-offset model; codegen differs from the exe
// @0x14253d160
void Sfr31TraceOperandClassTraits(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    const UPInt vm = TrVM(s.Tracer());
    const UPInt pv = reinterpret_cast<UPInt>(&popped.Get());
    const UInt32 kind = *reinterpret_cast<const UInt32*>(pv) & 0x1f;
    UPInt tr = 0;
    if (kind == 0)
        tr = Sfr31Rd(vm, 0x278);
    else if (kind == 8 || kind == 9)
        tr = Sfr31Rd(pv, 0x10);
    else
        tr = FUN_14250ffc0(reinterpret_cast<VM*>(vm), &popped.Get());
    if (tr != 0 && tr == Sfr31Rd(vm, 0x1f0))
        tr = Sfr31Rd(vm, 0x1f8);
    Sfr31RawTraitsVal v = {0x48, 0, 0, 0};
    if (*reinterpret_cast<const UInt32*>(tr + 0x70) == 10 && ((*reinterpret_cast<const UInt8*>(tr + 0x68) >> 5) & 1) == 0)
        v.w2 = Sfr31Rd(Sfr31Rd(vm, 0x1f8), 0xc0);
    else if ((*reinterpret_cast<const UInt8*>(tr + 0x68) & 1) != 0)
    {
        v.w0 = 8;
        v.w2 = Sfr31Rd(Sfr31Rd(vm, 0x228), 0xc0);
    }
    else
        v.w2 = Sfr31Rd(Sfr31Rd(vm, 0x230), 0xc0);
    s.OpStack().PushBack(*reinterpret_cast<const Value*>(&v));
    popped.Get().~Value();
}

// Traces the code of the block containing pos, merging block states, and keeps tracing opcodes until the code ends or a halt is raised.
// MS2-FUNCTIONAL 0x142530220: raw-offset model; codegen differs from the exe
// @0x142530220
void Sfr31TraceBlock(UPInt tr, UPInt pos, UPInt block)
{
    UPInt b = Sfr31Rd(tr, 0x110);
    while (b != 0 && pos < Sfr31Rd(b, 0x20))
        b = Sfr31Rd(b, 0);
    Sfr31Wr(tr, 0x68, b);
    UInt8 buf[8];
    if ((*reinterpret_cast<const UInt8*>(b + 0x10) & 1) == 0)
        FUN_142511b00(tr, reinterpret_cast<UPInt*>(b), reinterpret_cast<UPInt*>(block));
    else if (b != block && *FUN_142516c40(tr, buf, reinterpret_cast<UPInt*>(b), reinterpret_cast<UPInt*>(block)) == 0)
        return;
    if (pos >= Sfr31Rd(tr, 0x58))
        return;
    while (*reinterpret_cast<const UInt8*>(TrVM(tr) + 0x180) == 0)
    {
        const UPInt prev = Sfr31Rd(tr, 0x68);
        for (UPInt p = Sfr31Rd(tr, 0x110); p != 0; p = Sfr31Rd(p, 0))
        {
            if (Sfr31Rd(p, 0x20) <= pos)
            {
                if (Sfr31Rd(p, 0x20) == pos)
                {
                    Sfr31Wr(tr, 0x68, p);
                    if ((*reinterpret_cast<const UInt8*>(p + 0x10) & 1) == 0)
                        FUN_142511b00(tr, reinterpret_cast<UPInt*>(p), reinterpret_cast<UPInt*>(prev));
                    else if (p != prev && *FUN_142516c40(tr, buf, reinterpret_cast<UPInt*>(p), reinterpret_cast<UPInt*>(prev)) == 0)
                        return;
                }
                break;
            }
        }
        FUN_14252c640(tr, &pos);
        if (Sfr31Rd(tr, 0x58) <= pos)
            return;
        FUN_1425212f0(tr);
        const UInt8 op = *reinterpret_cast<const UInt8*>(pos + Sfr31Rd(tr, 0x50));
        ++pos;
        const UPInt state = Sfr31Rd(Sfr31Rd(tr, 0x68), 0x18);
        if (FUN_14252d100(tr, op, &pos, state) == 0)
        {
            if (*reinterpret_cast<const UInt8*>(TrVM(tr) + 0x180) != 0)
                return;
            FUN_14253d520(state, op, &pos);
        }
        if (Sfr31Rd(tr, 0x58) <= pos)
            return;
    }
}
// ---- batch 31
typedef UPInt (*Sfr31VFnGet)(UPInt self);

// Tracer getdescendants: raises a verify error when XML support is absent, else the object operand becomes an XMLList-typed value.
// MS2-FUNCTIONAL 0x1425390a0: raw-offset model; codegen differs from the exe
// @0x1425390a0
void Sfr31TraceGetDescendants(State* st, UInt32 idx)
{
    StV s(st);
    const UPInt vm = TrVM(s.Tracer());
    const UPInt helper = Sfr31Rd(vm, 0x40);
    if (*reinterpret_cast<const UInt8*>(helper + 0x20) == 0)
    {
        VM& v = *reinterpret_cast<VM*>(vm);
        v.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), v, "getdescendants"));
        return;
    }
    FUN_14251fcd0(s.Tracer(), idx);
    const UPInt link = TrAbcLink(s.Tracer());
    Sfr31MnCtx ctx = {TrRd(link, 0x20), st, 0};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntry(link, idx));
    ctx.pops += FUN_142520380(&ctx, &mn);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++ctx.pops;
    Sfr31VFnGet fn = *reinterpret_cast<Sfr31VFnGet*>(Sfr31Rd(helper, 0) + 0x98);
    Sfr31RawTraitsVal v = {8, 0, fn(helper), 0};
    s.OpStack().PushBack(*reinterpret_cast<const Value*>(&v));
    popped.Get().~Value();
}
// ---- batch 32
// istype-style op: replaces the top value with whether it is an instance of the named class; names resolved at compile time are rejected.
// MS2-FUNCTIONAL 0x14253bbe0: raw-offset model; codegen differs from the exe
// @0x14253bbe0
void Sfr31ExecIsTypeNamed(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    const UPInt cfile = Sfr31Rd(file, 0x28);
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntry(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    const UPInt nameSlot = Sfr31Rd(cfile, 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8;
    if ((flags & 3) == 1 || ((flags >> 2) & 1) != 0)
    {
        UPInt sv[2];
        FUN_142545310(nameSlot, sv);
        String name(reinterpret_cast<const char*>(sv[0]), sv[1]);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x436, reinterpret_cast<void*>(cvm), name.ToCStr(), "compile time");
        reinterpret_cast<VM*>(cvm)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(cvm, 0x50));
    const UPInt tr = FUN_142524f60(vmAddr, file, entry);
    if (tr == 0)
    {
        UPInt sv[2];
        FUN_142545310(Sfr31Rd(Sfr31Rd(file, 0x28), 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8, sv);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7850(eb, 0x3f6, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(sv[0]));
        reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    else
        top->SetBool(FUN_1425146d0(reinterpret_cast<VM*>(vmAddr), top, reinterpret_cast<const void*>(tr)));
}
// ---- batch 33
// instanceof: pops the class operand and replaces the top value with whether the class (or its prototype) is on the value's traits chain.
// MS2-FUNCTIONAL 0x14253b990: raw-offset model; codegen differs from the exe
// @0x14253b990
void Sfr31ExecInstanceOf(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Value* below;
    Sfr31RawTraitsVal cls;
    {
        const UPInt top = Sfr31Rd(vmAddr, 0x50);
        for (int i = 0; i < 8; ++i)
            reinterpret_cast<UInt32*>(&cls)[i] = reinterpret_cast<const UInt32*>(top)[i];
        below = reinterpret_cast<Value*>(top - 0x20);
        Sfr31Wr(vmAddr, 0x50, top - 0x20);
    }
    const UInt32 ck = cls.w0 & 0x1f;
    if (ck - 0xd > 1)
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x410), vm));
    else
    {
        const UInt32 bk = *reinterpret_cast<const UInt32*>(below) & 0x1f;
        bool r = false;
        if (bk != 0 && (bk - 0xc > 3 || Sfr31Rd(reinterpret_cast<UPInt>(below), 0x10) != 0))
        {
            UPInt chain = FUN_142507f60(vmAddr, below);
            const UPInt target = FUN_14250ffc0(&vm, reinterpret_cast<const Value*>(&cls));
            if (ck == 0xd)
            {
                for (; chain != 0; chain = Sfr31Rd(chain, 0x88))
                    if (chain == target)
                    {
                        r = true;
                        break;
                    }
            }
            else
            {
                typedef void (*Fn)(UPInt);
                UPInt proto = Sfr31Rd(target, 0x80);
                if (proto == 0)
                {
                    (*reinterpret_cast<Fn*>(Sfr31Rd(target, 0) + 0x68))(target);
                    proto = Sfr31Rd(target, 0x80);
                }
                for (; chain != 0; chain = Sfr31Rd(chain, 0x88))
                {
                    UPInt c = Sfr31Rd(chain, 0x80);
                    if (c == 0)
                    {
                        (*reinterpret_cast<Fn*>(Sfr31Rd(chain, 0) + 0x68))(chain);
                        c = Sfr31Rd(chain, 0x80);
                    }
                    if (reinterpret_cast<UPInt>(&reinterpret_cast<Class*>(c)->GetPrototype()) == proto)
                    {
                        r = true;
                        break;
                    }
                }
            }
        }
        below->SetBool(r);
    }
    reinterpret_cast<Value*>(&cls)->~Value();
}
// ---- batch 34
// astype-style op: replaces the top value with null when it is an instance of the named class; names resolved at compile time are rejected.
// MS2-FUNCTIONAL 0x142532ff0: raw-offset model; codegen differs from the exe
// @0x142532ff0
void Sfr31ExecAsTypeNamed(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    const UPInt cfile = Sfr31Rd(file, 0x28);
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntry(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    const UPInt nameSlot = Sfr31Rd(cfile, 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8;
    if ((flags & 3) == 1 || ((flags >> 2) & 1) != 0)
    {
        UPInt sv[2];
        FUN_142545310(nameSlot, sv);
        String name(reinterpret_cast<const char*>(sv[0]), sv[1]);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x436, reinterpret_cast<void*>(cvm), name.ToCStr(), "compile time");
        reinterpret_cast<VM*>(cvm)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(cvm, 0x50));
    if (*reinterpret_cast<const UInt8*>(vmAddr + 0x180) != 0)
        return;
    const UPInt tr = FUN_142524f60(vmAddr, file, entry);
    if (tr == 0 || tr == FUN_142507f60(vmAddr, top))
    {
        UPInt sv[2];
        FUN_142545310(nameSlot, sv);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7850(eb, 0x3f6, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(sv[0]));
        reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    else
        top->SetNull();
}

// Raises verify error 0x42c naming two conflicting objects; an object whose name is the empty string is reported as null.
// MS2-FUNCTIONAL 0x14252efe0: raw-offset model; codegen differs from the exe
// @0x14252efe0
void Sfr31RaiseNameConflict(UPInt tr, UPInt a, UPInt b)
{
    const UPInt vm = TrVM(tr);
    UPInt nodeB = 0, nodeA = 0;
    Sfr31VFnName fb = *reinterpret_cast<Sfr31VFnName*>(Sfr31Rd(b, 0) + 0x38);
    UPInt* pb = fb(b, &nodeB);
    Sfr31RawTraitsVal vb = {10, 0, *pb, 0};
    if (*pb == Sfr31Rd(*pb, 8) + 0x68)
    {
        vb.w0 = 0xc;
        vb.w2 = 0;
    }
    else
        ++*reinterpret_cast<int*>(vb.w2 + 0x18);
    Sfr31VFnName fa = *reinterpret_cast<Sfr31VFnName*>(Sfr31Rd(a, 0) + 0x38);
    UPInt* pa = fa(a, &nodeA);
    Sfr31RawTraitsVal va = {10, 0, *pa, 0};
    if (*pa == Sfr31Rd(*pa, 8) + 0x68)
    {
        va.w0 = 0xc;
        va.w2 = 0;
    }
    else
        ++*reinterpret_cast<int*>(va.w2 + 0x18);
    {
        VM& v = *reinterpret_cast<VM*>(vm);
        Sfr31Err e(static_cast<VM::ErrorID>(0x42c), v, *reinterpret_cast<const Value*>(&va), *reinterpret_cast<const Value*>(&vb));
        v.ThrowVerifyError(e);
    }
    reinterpret_cast<Value*>(&va)->~Value();
    Sfr31ReleaseStr(nodeA);
    reinterpret_cast<Value*>(&vb)->~Value();
    Sfr31ReleaseStr(nodeB);
}
// ---- batch 35
// Native with a required object argument: the popped value is handed to the owner's helper through its virtual call along with the remaining arguments.
// MS2-FUNCTIONAL 0x142537810: raw-offset model; codegen differs from the exe
// @0x142537810
void Sfr31ExecOwnerCall(UPInt vmAddr, UPInt owner, UInt32 n)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, n);
    const UPInt frame = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8);
    const UPInt top = Sfr31Rd(frame, 8);
    Sfr31RawTraitsVal val;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&val)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(frame, 8, top - 0x20);
    Sfr31ThrowIfNotObject(vm, reinterpret_cast<const UInt32*>(&val));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt helper = Sfr31Rd(Sfr31Rd(owner, 0x40), 0x88);
        if (helper != 0)
        {
            const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
            void* args = cnt > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
            typedef void (*Fn)(UPInt, UPInt, void*, UInt32, void*);
            (*reinterpret_cast<Fn*>(Sfr31Rd(helper, 0) + 0x78))(helper, Sfr31Rd(owner, 0x40), &val, n, args);
        }
    }
    reinterpret_cast<Value*>(&val)->~Value();
    FUN_1424de9e0(raBuf);
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
template void Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
struct Sfr31Rec24 { Scaleform::UInt64 a, b, c; };
struct Sfr31Rec64 { Scaleform::UInt64 a[8]; };
template void Scaleform::ArrayDataBase<const Scaleform::UInt8*,Scaleform::AllocatorDH<const Scaleform::UInt8*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::ASStringNode*,Scaleform::AllocatorGH<Scaleform::GFx::ASStringNode*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::DisplayObject*,Scaleform::AllocatorGH<Scaleform::GFx::DisplayObject*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value*,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value*,331>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Sfr31Rec24,Scaleform::AllocatorLH<Sfr31Rec24,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Sfr31Rec64,Scaleform::AllocatorLH<Sfr31Rec64,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
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
