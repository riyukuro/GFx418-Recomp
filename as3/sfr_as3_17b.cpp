// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 VM interpreter loop
// (VM::ExecuteCode). Our own source, written from the exe. The opcode handlers the exe also has out of line are
// called through their sfr_as3_19 recoveries; the rest are written here.
// MS2-UNIT: sfr_as3_17b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424fa5b0-0x1424fe5b0 .text$mn
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7GASRefCountBase@AS3@GFx@Scaleform@@6B@ 0x14313f398
// MS2-PIN: ??_7Object@AS3@GFx@Scaleform@@6B@ 0x14317b098
// MS2-PIN: ??_7Instance@AS3@GFx@Scaleform@@6B@ 0x14313f4d8
#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp/AS3_Value.cpp AddRef bodies inline (as3_value.h)
#define MS2_AS3_ASSIGN_NOALIAS 1
#define SFR_AS3_ESCAPE_NO_INLINE   // exe 0x72 reloads the temp's node after the call: it did not see the body (as3_obj_fl.h)
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_e4x.h"
#undef GetObject

int FUN_142519a00(Scaleform::GFx::AS3::VM* vm, Scaleform::UPInt index, void* frame);   // the frame's handler at index, or < 0
void FUN_1424efe30(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Value* result);
void FUN_14241de40(Scaleform::GFx::AS3::ValueStack* stack, unsigned n);   // ValueStack::PopBack: pops (and releases) the top n values
bool FUN_1425146d0(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* v, const void* traits);
Scaleform::GFx::AS3::Object* FUN_14250a550(Scaleform::GFx::AS3::VM& vm);   // the VM's fallback object (global); defined in sfr_as3_18
void FUN_1424162b0(const Scaleform::GFx::AS3::Instances::Namespace* self, Scaleform::GFx::AS3::Value& name,
                   Scaleform::GFx::AS3::GlobalSlotIndex ind);   // Namespace::GetNextPropertyName (sfr_as3_04)
void FUN_142416600(Scaleform::GFx::AS3::Instances::Namespace* self, Scaleform::GFx::AS3::Value& value,
                   Scaleform::GFx::AS3::GlobalSlotIndex ind);   // Namespace::GetNextPropertyValue (sfr_as3_04)
// Value::operator=(const ASString&), out of line (defined in sfr_as3_19)
__declspec(noalias) Scaleform::GFx::AS3::Value& FUN_1424e0d40(Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::ASString& str);
void FUN_14241d980(Scaleform::GFx::AS3::SparseArray*, Scaleform::GFx::AS3::ValueStack*, unsigned long long);   // SparseArray::Append(stack, n)
namespace Scaleform { namespace GFx { namespace AS3 {
// Value::PickUnsafe(Object*), through the name as3_value.h befriends (sfr_as3_03/19 hold the other members).
struct ValueAssignCopies
{
    static void AssignUnsafeNamespace(Value& v, Instances::Namespace* p);
    static __forceinline void Clean(Value& v) { v.Clean(); }
    // Value::Pick (0x14251c720) inlined into a fresh undefined target: the Release folds away
    static __forceinline void PickFresh(Value& self, Value& other)
    {
        SIMD::PrefetchObj(&other);
        memcpy(&self, &other, sizeof(Value));
        other.SetFlags(0);
    }
    // the exe's inliner ran out of budget for the later cases: AddRefInternal is called there (0x1424e9330)
    static __forceinline void CopyCalled(Value* to, const Value& from)
    {
        new (to) Value(from, Value::NotRefCounted);
        if (from.IsRefCounted())
        {
            if (from.IsWeakRef())
                from.AddRefWeakRefSCU();
            else
                from.AddRefInternal();
        }
    }
    // Value::Pick(ValueStack&) inlined: Release, then PickUnsafe(ValueStack&) field copies (no source clear)
    // Value::AssignUnsafe(const ASString&) inlined into a pushed slot (Assign minus Release, sfr_as3_16)
    static __forceinline void AssignStringUnsafe(Value& self, const ASString& v)
    {
        if (v.GetNode() == v.GetNode()->GetManager()->GetNullStringNode())
        {
            self.value = (ASStringNode*)NULL;
            self.SetKind(Value::kObject);
        }
        else
        {
            self.SetKind(Value::kString);
            self.value = v.GetNode();
            self.AddRefString();
        }
    }
    // PickUnsafe(ValueStack&) member by member, the stack top read again for each
    static __forceinline void CopyFromTop(Value& self, Value*& top)
    {
        self.Flags = top->Flags;
        self.Bonus = top->Bonus;
        self.value = top->value;
    }
    static __forceinline void CopyBits(Value& self, const Value& top)
    {
        self.Flags = top.Flags;
        self.Bonus = top.Bonus;
        self.value = top.value;
    }
    static __forceinline void PickTopLate(Value& self, Value*& top)
    {
        self.Release();
        const Value& t = *top;
        self.Flags = t.Flags;
        self.Bonus = t.Bonus;
        self.value = t.value;
    }
    static __forceinline void PickTop(Value& self, const Value& top)
    {
        self.Release();
        self.Flags = top.Flags;
        self.Bonus = top.Bonus;
        self.value = top.value;
    }
    static __forceinline void PickUnsafeObject19(Value& to, Object* v)
    {
        to.SetKind(Value::kObject);
        to.value = v;
    }
};
}}}

namespace Scaleform { namespace GFx { namespace AS3 {
__declspec(noalias) CheckResult AbstractEqual(bool& result, const Value& l, const Value& r);
__declspec(noalias) CheckResult AbstractLessThan(Boolean3& result, const Value& l, const Value& r);
}}}
void FUN_14252ecb0(void* vm, const void* error, const void* classInfo);  // ThrowErrorInternal
void FUN_1424dd460(void* self);
void FUN_1423f1470(void* self);  // ~Value out of line
#pragma comment(linker, "/alternatename:?FUN_1423f1470@@YAXPEAX@Z=??1Value@AS3@GFx@Scaleform@@QEAA@XZ")
void FUN_142421ed0(void* self);  // Value::SetNull out of line
#pragma comment(linker, "/alternatename:?FUN_142421ed0@@YAXPEAX@Z=?SetNull@Value@AS3@GFx@Scaleform@@QEAAXXZ")
void FUN_14251cb40(void* a, unsigned __int64 n);  // ArrayBase::PopBack out of line
#pragma comment(linker, "/alternatename:?FUN_14251cb40@@YAXPEAX_K@Z=?PopBack@?$ArrayBase@U?$ArrayDataDH@VValue@AS3@GFx@Scaleform@@U?$AllocatorDH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z")
bool FUN_142419cd0(const void* v);  // IsXMLObject(const Value&) out of line
#pragma comment(linker, "/alternatename:?FUN_142419cd0@@YA_NPEBX@Z=?IsXMLObject@AS3@GFx@Scaleform@@YA_NAEBVValue@123@@Z")
bool FUN_142419ca0(const void* v);  // IsXMLListObject(const Value&) out of line
#pragma comment(linker, "/alternatename:?FUN_142419ca0@@YA_NPEBX@Z=?IsXMLListObject@AS3@GFx@Scaleform@@YA_NAEBVValue@123@@Z")

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr_as3_17
const ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>& Sfr33CallFrameGetCode(CallFrame& cf);
InstanceTraits::Traits* Sfr33GetActivationInstanceTraits(VMAbcFile& file, const Abc::MethodBodyInfo* mbi, void* p);
__declspec(noalias) void Sfr33CheckObject(VM* const* self, const Value& v);

// sfr_as3_19: the out-of-line opcode handlers
void Sfr27ExecAsType(VM* vm);
void Sfr27ExecCallVoid(VM* vm, UInt32 argc);
void Sfr27ExecCallMethod(VM* vm, UInt32 methodIndex, UInt32 argc);
void Sfr27ExecGetGlobalSlot(VM* vm, UInt32 slot);
void Sfr27ExecSetGlobalSlot(VM* vm, UInt32 slot);
void Sfr27ExecGetOwnSlot(VM* vm, UInt32 slot);
void Sfr27ExecSetOwnSlot(VM* vm, UInt32 slot);
void Sfr27ExecGetSlot(VM* vm, SPInt slot);
void Sfr27ExecSetSlot(VM* vm, SPInt slot);
void Sfr27ExecInitSlot(VM* vm, SPInt slot);
void Sfr27ExecTypeOf(VM* vm);
void Sfr27ExecNextName(VM* vm);
void Sfr27ExecNextValue(VM* vm);
void Sfr31ExecNewArray(UPInt vm, UInt32 n);
void Sfr31ExecPushInterfaceInstance(UPInt vm, UPInt a, UPInt b);
void Sfr31ExecCheckFilter(UPInt vm);
void Sfr31ExecEscXAttr(UPInt vm);
void Sfr31CallOnObjectArg(UPInt vmAddr, UInt32 argc);
void Sfr31ExecIndexedQuery(UPInt vm);
void Sfr31ValueToBool(Value* v);
void Sfr31ExecSetProperty(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecGetSuper(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecGetLex(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecDeleteProp(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecInitProperty(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecIsTypeNamed(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecInstanceOf(UPInt vmAddr);
void Sfr31ExecAsTypeNamed(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecOwnerCall(UPInt vmAddr, UPInt owner, UInt32 n);
void Sfr31ExecCallWithTraits(UPInt vmAddr, UInt32 a, UInt32 n);
void Sfr31ExecPushNamespace(UPInt vm, UPInt target);
void Sfr31ExecFindPropOrGlobal(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecCheckScopeObject(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecIn(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecGetProp(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecSetSuper(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecCallSuper(UPInt vmAddr, UInt32 a, UInt32 n);
void Sfr31ExecNewObject(UPInt vmAddr, UInt32 n);
void Sfr31ExecCallSuperArgsA(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc);
void Sfr31ExecCallSuperArgsB(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc);
void Sfr31ExecCallValue(UPInt vmAddr, UInt32 argc);
void Sfr31ExecIn(UPInt vmAddr);
void Sfr31ExecClassEntry(UPInt vmAddr, UPInt link, UInt32 idx);
void Sfr31ExecCallParentSlot(UPInt vmAddr, UInt32 slotIdx, UInt32 argc);
void Sfr31ExecCallStatic(UPInt vmAddr, UPInt file, SInt32 idx, UInt32 argc);
void Sfr31ExecGetLexStatic(UPInt vmAddr, UPInt file, UInt32 idx);
void Sfr31ExecHasNext2(UPInt vmAddr, UInt32 objReg, UInt32 idxReg);
void Sfr31ExecConstructProp(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc);
void Sfr31ExecNewFunction(UPInt vmAddr, UPInt frame, UInt32 methodInd);
void Sfr31ExecCallPropVoid(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc);
void Sfr31ExecCallPropLex(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc);
void Sfr31ExecCallProperty(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc);

namespace {

// How the run of one frame ended.
enum Sfr33ExecExit
{
    Sfr33ExitLeave,     // the frame returned
    Sfr33ExitLeaveExc,  // an exception left the frame (no handler in it)
    Sfr33ExitCalled     // a call pushed a new frame; this one resumes at its CP
};

// The raw storage of a ReadArgs, built and torn down by its out-of-line ctor/dtor.
struct Sfr33Args
{
    Sfr33Args(VM* vm, UInt32 argc) { reinterpret_cast<ReadArgs*>(buf)->ReadArgs::ReadArgs(*vm, argc); }
    ~Sfr33Args() { reinterpret_cast<ReadArgs*>(buf)->ReadArgs::~ReadArgs(); }
    UInt32 ArgNum() const { return *reinterpret_cast<const UInt32*>(buf + 0x10); }
    const Value* Argv() const
    {
        return ArgNum() > 8 ? *reinterpret_cast<const Value* const*>(buf + 0x118) : reinterpret_cast<const Value*>(buf + 0x18);
    }
    UInt8 buf[0x140];
};

// ReadArgsObject: the object under the args is read through args.GetVM's stack pointer (+8) and checked.
struct Sfr33ArgsObject : Sfr33Args
{
    __forceinline Sfr33ArgsObject(VM* vm, UInt32 argc) : Sfr33Args(vm, argc)
    {
        *reinterpret_cast<Value**>(buf + 0x138) = *reinterpret_cast<Value**>(*reinterpret_cast<UPInt*>(buf + 8) + 8);
        Sfr33CheckObject(reinterpret_cast<VM* const*>(buf), ArgObject());
    }
    __forceinline Value& ArgObject() { return **reinterpret_cast<Value**>(buf + 0x138); }
};

// VM::ThrowTypeError / ThrowRangeError inlined: ThrowErrorInternal(e, fl::XxxErrorCI).
__forceinline void Sfr33ThrowType(VM& vm, const VM::Error& e) { ::FUN_14252ecb0(&vm, &e, &fl::TypeErrorCI); }
__forceinline void Sfr33ThrowRange(VM& vm, const VM::Error& e) { ::FUN_14252ecb0(&vm, &e, &fl::RangeErrorCI); }

inline CallFrameStack& Sfr33CallStack(VM& vm) { return *reinterpret_cast<CallFrameStack*>(&vm.Unk070); }

__forceinline CallFrame& Sfr33FrameAt(VM& vm, UPInt i)
{
    return Sfr33CallStack(vm).Pages[i >> 6][i & 0x3f];
}

// pushwith / pushscope: the top of the operand stack moves onto the scope stack (TypeError 1010 for undefined, 1009
// for a null object).
__forceinline void Sfr33PushScope(VM& vm, Value*& sp, bool with)
{
    Value& top = *sp;
    if (top.IsNullOrUndefined())
    {
        Sfr33ThrowType(vm, VM::Error(static_cast<VM::ErrorID>(top.IsNull() ? 1009 : 1010), vm));
        return;
    }
    vm.ScopeStack.PushBack(Value::GetUndefined());
    Value& back = vm.ScopeStack[vm.ScopeStack.GetSize() - 1];
    ValueAssignCopies::PickFresh(back, top);
    sp->~Value();
    --sp;
    if (with)
        back.SetWith(true);
}

// nextname / nextvalue / hasnext convert the index on top in place (0 when the conversion threw).
inline SInt32 Sfr33TopIndex(Value& top, bool& ok)
{
    SInt32 i = 0;
    ok = top.Convert2Int32(i);
    if (ok)
        top.SetSInt32(i);
    return ok ? top.AsInt() : 0;
}

// The two operands of a compare-and-branch come off the stack (OpStack.PopBack(2), inlined).
__forceinline void Sfr33PopBack2(Value*& sp)
{
    UInt32 n = 2;
    do
    {
        --n;
        sp->Value::~Value();
        --sp;
    } while (n != 0);
}

// the popped right operand of add/subtract/multiply: the exe copies it without clearing the stack slot and
// destroys it through the out-of-line SCU ~Value (FUN_1424dd460, sfr_as3_16)
// A named Value whose destructor is the exe's out-of-line ~Value (0x1423f1470): the exe inliner
// ran out of budget late in ExecuteCode and calls it at every tail of these cases.
union Sfr33OolTmp
{
    Value v;
    __forceinline Sfr33OolTmp() : v() {}
    template <class T> __forceinline explicit Sfr33OolTmp(T* p) : v(p, Value::InlineObj) {}
    __forceinline Sfr33OolTmp(Value& s, PickType) : v(s, PickValue) {}
    struct FromVal {};
    template <class T> __forceinline Sfr33OolTmp(T x, FromVal) : v(x) {}
    struct FromCall {};
    template <class F> __forceinline Sfr33OolTmp(F f, FromCall) : v(f()) {}
    __forceinline ~Sfr33OolTmp() { FUN_1423f1470(&v); }
};

// SDK SH2<1>: the right operand picked off the stack (destroyed out of line by the case), _1 the new top
struct Sfr33Tag {};
__forceinline void* Sfr33TraitsAlloc(Traits& t)
{
    const UPInt sz = t.GetMemSize();
    AllocInfo info(StatMV_VM_Instance_Mem, NULL, 0);
    return t.GetVM().GetMemoryHeap()->Alloc(sz, &info);
}
__forceinline void Sfr33Nop() {}
__forceinline UInt32 Sfr33ReadOp(const UPInt*& cp) { return static_cast<UInt32>(*cp++); }
struct Sfr33Stack
{
    void* First;
    Value* pCurrent;
    __forceinline void PushBack(const Value& v) { ++pCurrent; new (pCurrent) Value(v); }
};
struct Sfr33Pop2
{
    union { Value v; };
    Value* _1;
    static __forceinline Value* Pop(Value*& top) { --top; return top; }
    __forceinline Sfr33Pop2(Value*& top) : _1((ValueAssignCopies::CopyFromTop(v, top), Pop(top))) {}
    struct Reg {};
    static __forceinline Value* PopReg(Value*& top) { Value* p = top; --p; top = p; return p; }
    __forceinline Sfr33Pop2(Value*& top, Reg) : _1((ValueAssignCopies::CopyFromTop(v, top), PopReg(top))) {}
    __forceinline ~Sfr33Pop2() {}
};
template <typename T> __forceinline T& Sfr33ToType(Value& v, bool& success);
template <> __forceinline SInt32& Sfr33ToType<SInt32>(Value& v, bool& success)
{
    static SInt32 tmp;
    success = success && v.ToInt32Value();
    return success ? v.AsInt() : tmp;
}
template <> __forceinline UInt32& Sfr33ToType<UInt32>(Value& v, bool& success)
{
    static UInt32 tmp;
    success = success && v.ToUInt32Value();
    return success ? v.AsUInt() : tmp;
}
template <> __forceinline Value::Number& Sfr33ToType<Value::Number>(Value& v, bool& success)
{
    static Value::Number tmp;
    success = success && v.ToNumberValueInline();
    return success ? v.AsNumber() : tmp;
}
// r._1 is read at each use (rcx, then back from its slot after the conversions), not bound to a reference.
__forceinline void Sfr33ArithSub(Sfr33Pop2& r, Value::Number& rn)
{
    Value::Number l;
    if (r._1->Convert2NumberInline(l) && r.v.Convert2NumberInline(rn))
        r._1->SetNumber(l - rn);
}
__forceinline void Sfr33ArithMul(Sfr33Pop2& r, Value::Number& rn)
{
    Value::Number l;
    if (r._1->Convert2NumberInline(l) && r.v.Convert2NumberInline(rn))
        r._1->SetNumber(l * rn);
}
template <typename T1, typename T2> struct Sfr33SH2
{
    __forceinline Sfr33SH2(Value*& top)
    : Success(true)
    , _2(Sfr33ToType<T2>(top[0], Success))
    , _1(Sfr33ToType<T1>(top[-1], Success))
    {
        top->~Value();
        --top;
    }
    bool Success;
    T2 _2;
    T1& _1;
};

// nextname/nextvalue (SDK exec_nextname/exec_nextvalue, SH2<1, Value, SInt32>), as the exe inlines them.
__forceinline bool Sfr33ConvSInt32B(Value& v)
{
    SInt32 result;
    if (v.Convert2Int32(result))
    {
        v.SetSInt32(result);
        return true;
    }
    return false;
}
__forceinline CheckResult Sfr33ConvSInt32(Value& v)
{
    return Sfr33ConvSInt32B(v);
}
__forceinline SInt32& Sfr33ToTypeSInt32(Value& v, bool& success)
{
    static SInt32 tmp;
    success = success && Sfr33ConvSInt32(v);
    return success ? *reinterpret_cast<SInt32*>(reinterpret_cast<UPInt>(&v) + 0x10) : tmp;
}

struct Sfr33SH2ValueSInt32
{
    __forceinline Sfr33SH2ValueSInt32(Value*& top)
    : Success(true)
    , _2(Sfr33ToTypeSInt32(top[0], Success))
    , _1(top[-1])
    {
        top->~Value();
        --top;
    }
    bool Success;
    SInt32 _2;
    Value& _1;
};

__forceinline void Sfr33ExecNext(Value*& sp, bool wantValue)
{
    Sfr33SH2ValueSInt32 stack(sp);
    if (stack.Success)
    {
        if (stack._1.IsNamespace())
        {
            if (wantValue)
                ::FUN_142416600(stack._1.GetNamespace(), stack._1, GlobalSlotIndex(static_cast<UInt32>(stack._2)));
            else
                ::FUN_1424162b0(stack._1.GetNamespace(), stack._1, GlobalSlotIndex(static_cast<UInt32>(stack._2)));
        }
        else
        {
            Object* obj = *reinterpret_cast<Object**>(reinterpret_cast<UPInt>(&stack._1) + 0x10);
            if (wantValue)
                obj->GetNextPropertyValue(stack._1, GlobalSlotIndex(static_cast<UInt32>(stack._2)));
            else
                obj->GetNextPropertyName(stack._1, GlobalSlotIndex(static_cast<UInt32>(stack._2)));
        }
    }
}

// hasnext (SDK exec_hasnext): the index is popped, the object below replaced by its next dynamic property index.
__forceinline void Sfr33ExecHasNext(Value*& sp)
{
    Sfr33SH2ValueSInt32 stack(sp);
    if (!stack.Success)
        return;
    Sfr33OolTmp t(stack._1.GetObject()->GetNextDynPropIndex(GlobalSlotIndex(static_cast<UInt32>(stack._2))).Get(), Sfr33OolTmp::FromVal());
    stack._1 = t.v;
}

// checkfilter: the top must be an XML or XMLList instance, else TypeError 1123.
__forceinline void Sfr33ExecCheckFilter(VM& v, const Value& tv)
{
    if (::FUN_142419cd0(&tv) || ::FUN_142419ca0(&tv))
        return;
    Sfr33ThrowType(v, VM::Error(static_cast<VM::ErrorID>(0x463), v, v.GetValueTraits(tv).GetName().ToCStr()));
}

// esc_xattr: the top converted to a string and replaced by its XML-escaped form.
__forceinline void Sfr33ExecEscXAttr(StringManager& sm, Value* top)
{
    if (top->ToStringValue(sm))
    {
        StringBuffer buf(Memory::pGlobalHeap);
        Instances::fl::XML::EscapeElementValue(buf, top->AsString());
        FUN_1424e0d40(*top, (*reinterpret_cast<ASStringManager**>(reinterpret_cast<UPInt>(&sm) + 0x1e8))->CreateString(buf.ToCStr(), buf.GetSize()));
    }
}

// newarray: a new Array of the n values on top of the stack, pushed.
__forceinline void Sfr33ExecNewArray(VM& vm, Value*& sp, ValueStack& stack, UInt32 n)
{
    InstanceTraits::fl::Array& itr = *reinterpret_cast<InstanceTraits::fl::Array*>(
        *reinterpret_cast<const UPInt*>(*reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(&vm) + 0x238) + 0xc0));
    Pickable<Instances::fl::Array> arr = itr.MakeInstance(itr);
    ::FUN_14241d980(reinterpret_cast<SparseArray*>(reinterpret_cast<UPInt>(arr.GetPtr()) + 0x38), &stack, n);
    Sfr33OolTmp v;
    ValueAssignCopies::PickUnsafeObject19(v.v, arr.GetPtr());
    ++sp; _ReadWriteBarrier();
    new (sp) Value(v.v);
}

// newcatch: a Catch scope object for the handler (exception info), pushed.
__forceinline void Sfr33ExecNewCatch(VM& vm, Value*& sp, VMAbcFile& file, const Abc::MethodBodyInfo::ExceptionInfo& info)
{
    UPInt owner = *reinterpret_cast<const UPInt*>(*reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(&vm) + 0x240) + 0xc0);
    UPInt tbl = *reinterpret_cast<const UPInt*>(owner + 0x80);
    if (tbl == 0)
    {
        typedef void (*Init)(UPInt);
        reinterpret_cast<Init>(*reinterpret_cast<const UPInt*>(*reinterpret_cast<const UPInt*>(owner) + 0x68))(owner);
        tbl = *reinterpret_cast<const UPInt*>(owner + 0x80);
    }
    struct M { static __forceinline Pickable<Instances::fl::Catch> Make(UPInt cls, VMAbcFile& f, const Abc::MethodBodyInfo::ExceptionInfo& e)
    {
        SPtr<InstanceTraits::fl::Catch> tr = reinterpret_cast<Classes::fl::Catch*>(cls)->MakeInstanceTraits(f, e);
        return tr->MakeInstance(*tr);
    } };
    Pickable<Instances::fl::Catch> inst = M::Make(tbl, file, info);
    Sfr33OolTmp v;
    ValueAssignCopies::PickUnsafeObject19(v.v, inst.GetPtr());
    ++sp; _ReadWriteBarrier();
    new (sp) Value(v.v);
}

} // namespace

}}} // namespace Scaleform::GFx::AS3

// sfr_as3_18: CallStack.PopBack()
namespace Scaleform {
struct Sfr34_CallFramePagedArray;
void Sfr34_CallFramePagedArray_PopBack(Sfr34_CallFramePagedArray* a);
}

namespace Scaleform { namespace GFx { namespace AS3 {

// Object(Traits&) / Instance(Traits&): the exe inlines both into newactivation (see sfr_as3_19).
inline Object::Object(Traits& t)
    : GASRefCountBase(&t.GetVM().GetGC())
    , pTraits(&t)
    , pUserDataHolder(NULL)
{
}
template <class Tag> __forceinline Instance::Instance(InstanceTraits::Traits& t, Tag)
    : Object(t)
{
    t.ConstructTail(*this);
}
SF_FORCEINLINE Value::Value(Object* v, InlineObjType)
    : Flags(kObject)
    , value(v)
{
    if (v)
        v->AddRef();
}

// The interpreter: runs the top call frame from its CP (the method's traced code from the start when unset), and the
// frames its calls push, until max_stack_depth frames have returned or the call stack is empty. An exception pending
// on entry (or left by a returning frame) goes to the frame's handler; with none the frame is popped and the next
// one down looks for its own. Returns the frames still to run (0 when max_stack_depth returned).
// MS2-FUNCTIONAL 0x1424fa5b0: the opcodes the exe inlines from their out-of-line handlers call the sfr_as3_19 recoveries
// @0x1424fa5b0
int VM::ExecuteCode(unsigned max_stack_depth)
{
    UPInt call_stack_size = Sfr33CallStack(*this).Size;
    while (call_stack_size != 0)
    {
        {
        CallFrame& cf = Sfr33FrameAt(*this, Sfr33CallStack(*this).Size - 1);
        VMAbcFile& file = *cf.pFile;
        const UPInt vmAddr = reinterpret_cast<UPInt>(this);
        const UPInt fileAddr = reinterpret_cast<UPInt>(&file);
        const bool hadEx = HandleException;
        Value saved(ExceptionObj);
        HandleException = false;
        ValueAssignCopies::Clean(ExceptionObj);
#define sp (*reinterpret_cast<Value**>(&OpStack[1]))

        Boolean3 r3;
        const UPInt* cp = static_cast<const UPInt*>(cf.CP);
        if (cp == NULL)
        {
            cp = Sfr33CallFrameGetCode(cf).GetDataPtr();
            cf.CP = cp;
        }
        _mm_prefetch(reinterpret_cast<const char*>(cp), _MM_HINT_T1);

    // A pending exception moves cp to the frame's handler, or leaves the frame.
#define SFR33_CHECK()                                                                      \
    if (HandleException)                                                                   \
    {                                                                                      \
        const UPInt* const code = Sfr33CallFrameGetCode(cf).GetDataPtr();                  \
        const int h = FUN_142519a00(this, static_cast<UPInt>(cp - code), &cf);             \
        if (h < 0)                                                                         \
            goto exit_frame;                                                               \
        cp = code + h;                                                                     \
    }
// after a call: a pushed frame runs next, this one resumes at cp
#define SFR33_CALL_TAIL()                                                                  \
    SFR33_CHECK();                                                                         \
    if (call_stack_size != Sfr33CallStack(*this).Size)                                     \
    {                                                                                      \
        Sfr33FrameAt(*this, call_stack_size - 1).CP = cp;                                  \
        ++max_stack_depth;                                                                 \
        goto next_frame;                                                                   \
    }                                                                                      \
    break
#define SFR33_REG(i) (reinterpret_cast<Value*>(RegisterFile[1])[i])
#define SFR33_OP() Sfr33ReadOp(cp)

        if (HandleException)
            goto exit_frame;    // tracing the method threw
        if (hadEx)
        {
            HandleException = hadEx;
            ExceptionObj.Assign(saved);
            SFR33_CHECK();
        }

        for (;;)
        {
            const UPInt* const ip = cp;
            const int op = static_cast<int>(*cp++);
            switch (op)
            {
            case 0x02: Sfr33Nop(); break;  // nop
            case 0x03:  // throw
            {
                ValueAssignCopies::PickTopLate(ExceptionObj, sp);
                --sp;
                const int h = FUN_142519a00(this, static_cast<UPInt>(cp - Sfr33CallFrameGetCode(cf).GetDataPtr()), &cf);
                if (h < 0)
                    goto exit_frame;
                cp = Sfr33CallFrameGetCode(cf).GetDataPtr() + h;
                break;
            }
            case 0x04: Sfr31ExecGetSuper(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x05: Sfr31ExecSetSuper(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x06:  // dxns
                cf.DefXMLNamespace = &cf.pFile->GetInternedNamespace(SFR33_OP());
                SFR33_CHECK();
                break;
            case 0x07: Sfr31ExecPushNamespace(vmAddr, reinterpret_cast<UPInt>(&cf)); SFR33_CHECK(); break;
            case 0x08:  // kill
                SFR33_REG(SFR33_OP()).Assign(Value::GetUndefined());
                break;
            case 0x0c:  // ifnlt
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                Boolean3 r;
                SInt32 jmp = 0;
                if (AbstractLessThan(r, sp[-1], *sp))
                    if (r != true3)
                        jmp = offset;
                Sfr33PopBack2(sp);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x8a: case 0x8f:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const SInt32 b = (sp--)->AsInt();
                const SInt32 a = (sp--)->AsInt();
                cp += a < b ? 0 : offset;
                ++cp;
                break;
            }
            case 0xc8: case 0xcd:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const Value::Number b = (sp--)->AsNumber();
                const Value::Number a = (sp--)->AsNumber();
                cp += a >= b ? offset : 0;
                ++cp;
                break;
            }
            case 0x0d:  // ifnle
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                Boolean3 r;
                SInt32 jmp = 0;
                if (AbstractLessThan(r, *sp, sp[-1]))
                    if (r != false3)
                        jmp = offset;
                Sfr33PopBack2(sp);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x8b: case 0x9c:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const SInt32 b = (sp--)->AsInt();
                const SInt32 a = (sp--)->AsInt();
                cp += a <= b ? 0 : offset;
                ++cp;
                break;
            }
            case 0xbc: case 0xc9:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const Value::Number b = (sp--)->AsNumber();
                const Value::Number a = (sp--)->AsNumber();
                cp += b < a ? offset : 0;
                ++cp;
                break;
            }
            case 0x0e:  // ifngt
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                Boolean3 r;
                SInt32 jmp = 0;
                if (AbstractLessThan(r, *sp, sp[-1]))
                    if (r != true3)
                        jmp = offset;
                Sfr33PopBack2(sp);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x8c: case 0x9d:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const SInt32 b = (sp--)->AsInt();
                const SInt32 a = (sp--)->AsInt();
                cp += b < a ? 0 : offset;
                ++cp;
                break;
            }
            case 0xbd: case 0xca:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const Value::Number b = (sp--)->AsNumber();
                const Value::Number a = (sp--)->AsNumber();
                cp += a <= b ? offset : 0;
                ++cp;
                break;
            }
            case 0x0f:  // ifnge
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                Boolean3 r;
                SInt32 jmp = 0;
                if (AbstractLessThan(r, sp[-1], *sp))
                    if (r != false3)
                        jmp = offset;
                Sfr33PopBack2(sp);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x8d: case 0x9e:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const SInt32 b = (sp--)->AsInt();
                const SInt32 a = (sp--)->AsInt();
                cp += b <= a ? 0 : offset;
                ++cp;
                break;
            }
            case 0xbe: case 0xcb:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const Value::Number b = (sp--)->AsNumber();
                const Value::Number a = (sp--)->AsNumber();
                cp += a < b ? offset : 0;
                ++cp;
                break;
            }
            case 0x10:  // jump
                cp += static_cast<SInt32>(*cp);
                // fall through: the offset is relative to the next op
            case 0xf0: case 0xf1: case 0xf2:
                ++cp;
                break;
            case 0x11:  // iftrue
            {
                Value* const t = sp;
                const SInt32 offset = static_cast<SInt32>(*cp);
                Sfr31ValueToBool(t);
                const bool b = t->AsBool();
                --sp;
                cp += b == true ? offset : 0;
                ++cp;
                break;
            }
            case 0x33:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const bool b = sp->AsBool();
                --sp;
                cp += b == true ? offset : 0;
                ++cp;
                break;
            }
            case 0x12:  // iffalse
            {
                Value* const t = sp;
                const SInt32 offset = static_cast<SInt32>(*cp);
                Sfr31ValueToBool(t);
                const bool b = t->AsBool();
                --sp;
                cp += b ? 0 : offset;
                ++cp;
                break;
            }
            case 0x34:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const bool b = sp->AsBool();
                --sp;
                cp += b ? 0 : offset;
                ++cp;
                break;
            }
            case 0x13:  // ifeq
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                bool eq;
                SInt32 jmp = 0;
                if (AbstractEqual(eq, sp[-1], *sp))
                    if (eq)
                        jmp = offset;
                Sfr33PopBack2(sp);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x8e:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const SInt32 b = (sp--)->AsInt();
                const SInt32 a = (sp--)->AsInt();
                cp += a != b ? 0 : offset;
                ++cp;
                break;
            }
            case 0xcc:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const Value::Number b = (sp--)->AsNumber();
                const Value::Number a = (sp--)->AsNumber();
                cp += a == b ? offset : 0;
                ++cp;
                break;
            }
            case 0x14:  // ifne
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                bool eq;
                SInt32 jmp = 0;
                if (AbstractEqual(eq, sp[-1], *sp))
                    if (!eq)
                        jmp = offset;
                FUN_14241de40(reinterpret_cast<ValueStack*>(&OpStack), 2);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x9f:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const SInt32 b = (sp--)->AsInt();
                const SInt32 a = (sp--)->AsInt();
                cp += a == b ? 0 : offset;
                ++cp;
                break;
            }
            case 0xbf:
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const Value::Number b = (sp--)->AsNumber();
                const Value::Number a = (sp--)->AsNumber();
                cp += a == b ? 0 : offset;
                ++cp;
                break;
            }
            case 0x15:  // iflt
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                r3 = undefined3;
                SInt32 jmp = 0;
                if (AbstractLessThan(r3, sp[-1], *sp))
                    if (r3 == true3)
                        jmp = offset;
                FUN_14241de40(reinterpret_cast<ValueStack*>(&OpStack), 2);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x16:  // ifle
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                r3 = undefined3;
                SInt32 jmp = 0;
                if (AbstractLessThan(r3, *sp, sp[-1]))
                    if (r3 == false3)
                        jmp = offset;
                FUN_14241de40(reinterpret_cast<ValueStack*>(&OpStack), 2);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x17:  // ifgt
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                r3 = undefined3;
                SInt32 jmp = 0;
                if (AbstractLessThan(r3, *sp, sp[-1]))
                    if (r3 == true3)
                        jmp = offset;
                FUN_14241de40(reinterpret_cast<ValueStack*>(&OpStack), 2);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0x18:  // ifge
            {
                const SInt32 offset = static_cast<SInt32>(*cp++);
                r3 = undefined3;
                SInt32 jmp = 0;
                if (AbstractLessThan(r3, sp[-1], *sp))
                    if (r3 == false3)
                        jmp = offset;
                FUN_14241de40(reinterpret_cast<ValueStack*>(&OpStack), 2);
                SFR33_CHECK();
                cp += jmp;
                break;
            }
            case 0xce:  // call
            {
                const UInt32 argc = SFR33_OP();
                Sfr33Args args(this, argc);
                Value& fv = *sp;
                VM* self = this;
                Sfr33CheckObject(&self, fv);
                if (!HandleException)
                    fv.GetObject()->Call(Value::GetUndefined(), fv, argc, args.Argv());
            }
                SFR33_CALL_TAIL();
            case 0x19:  // ifstricteq
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const bool eq = StrictEqual(*sp, sp[-1]);
                sp->~Value();
                --sp;
                sp->~Value();
                --sp;
                cp += (eq ? offset : 0);
                ++cp;
                break;
            }
            case 0x1a:  // ifstrictne
            {
                const SInt32 offset = static_cast<SInt32>(*cp);
                const bool eq = StrictEqual(*sp, sp[-1]);
                sp->~Value();
                --sp;
                sp->~Value();
                --sp;
                cp += (eq ? 0 : offset);
                ++cp;
                break;
            }
            case 0x1b:  // lookupswitch
            {
                SInt32 target = static_cast<SInt32>(cp[0]);
                const UInt32 cnt = static_cast<UInt32>(cp[1]);
                const SInt32 i = sp->AsInt();
                sp->~Value();
                --sp;
                if (i >= 0 && static_cast<UInt32>(i) <= cnt)
                    target = static_cast<SInt32>(cp[2 + i]);
                cp = ip + target;
                break;
            }
            case 0x1c: Sfr33PushScope(*this, sp, true); SFR33_CHECK(); break;
            case 0x1d:  // popscope
                ::FUN_14251cb40(&ScopeStack, 1);
                break;
            case 0x1e: Sfr33ExecNext(sp, false); SFR33_CHECK(); break;
            case 0x1f: Sfr33ExecHasNext(sp); SFR33_CHECK(); break;
            case 0x20: ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->SetNullUnsafe(); break;
            case 0x21: ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->SetUndefinedUnsafe(); break;
            case 0x22: sp->AsBool() = !sp->AsBool(); break;
            case 0x23: Sfr33ExecNext(sp, true); SFR33_CHECK(); break;
            case 0x24: { const UInt32 b = SFR33_OP(); ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->AssignUnsafe(static_cast<SInt32>(static_cast<signed char>(b))); break; }
            case 0x25: { const SInt32 i = static_cast<SInt32>(SFR33_OP()); ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->AssignUnsafe(i); break; }
            case 0x26: ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->AssignUnsafe(true); break;
            case 0x27: ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->AssignUnsafe(false); break;
            case 0x28: ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->AssignUnsafe(NumberUtil::NaN()); break;
            case 0x29: sp->~Value(); --sp; break;
            case 0x2a: ++sp; ValueAssignCopies::CopyCalled(sp, sp[-1]); break;
            case 0x2b:  // swap
            {
                Sfr33OolTmp t(*sp, PickValue);
                ValueAssignCopies::PickFresh(sp[0], sp[-1]);
                ValueAssignCopies::PickFresh(sp[-1], t.v);
                break;
            }
            case 0x2c:  // pushstring
            {
                const UInt32 idx = SFR33_OP();
                ++sp;
                *reinterpret_cast<UPInt*>(sp) = 0;
                const StringDataPtr s = file.GetAbcFile().Const_Pool.GetString(idx);
                ASString str(GetStringManager().GetStringManager()->CreateStringNode(s.ToCStr(), s.GetSize()));
                ValueAssignCopies::AssignStringUnsafe(*sp, str);
                break;
            }
            case 0x2d: { const UInt32 idx = SFR33_OP(); ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->AssignUnsafe(file.GetAbcFile().Const_Pool.ConstInt[idx]); break; }
            case 0x2e: { const UInt32 idx = SFR33_OP(); ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->AssignUnsafe(file.GetAbcFile().Const_Pool.ConstUInt[idx]); break; }
            case 0x2f: { const UInt32 idx = SFR33_OP(); ++sp; *reinterpret_cast<UPInt*>(sp) = 0; sp->AssignUnsafe(file.GetAbcFile().Const_Pool.GetDouble(idx)); break; }
            case 0x30: Sfr33PushScope(*this, sp, false); SFR33_CHECK(); break;
            case 0x31: { const UInt32 idx = SFR33_OP(); ++sp; *reinterpret_cast<UPInt*>(sp) = 0; Value* top = sp; ValueAssignCopies::AssignUnsafeNamespace(*top, &file.GetInternedNamespace(idx)); break; }
            case 0x32:
            {
                const UInt32 objReg = SFR33_OP();
                const UInt32 idxReg = SFR33_OP();
                Sfr31ExecHasNext2(vmAddr, objReg, idxReg);
                SFR33_CHECK();
                break;
            }
            case 0x35: case 0x98: ++sp->AsInt(); break;
            case 0x36: case 0x99: --sp->AsInt(); break;
            case 0x0a: case 0x37: ++SFR33_REG(SFR33_OP()).AsInt(); break;
            case 0x0b: case 0x38: --SFR33_REG(SFR33_OP()).AsInt(); break;
            case 0x40: Sfr31ExecNewFunction(vmAddr, reinterpret_cast<UPInt>(&cf), SFR33_OP()); break;
            case 0x41: Sfr27ExecCallVoid(this, SFR33_OP()); SFR33_CALL_TAIL();
            case 0x42: Sfr31ExecCallValue(vmAddr, SFR33_OP()); SFR33_CALL_TAIL();
            case 0x43:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallWithTraits(vmAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0xb9:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallSuper(vmAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0xba:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr27ExecCallMethod(this, a, n);
                SFR33_CALL_TAIL();
            }
            case 0xbb:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallParentSlot(vmAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0x44:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallStatic(vmAddr, fileAddr, static_cast<SInt32>(a), n);
                SFR33_CALL_TAIL();
            }
            case 0x45:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallSuperArgsA(vmAddr, fileAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0x46:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallProperty(vmAddr, fileAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0x49: Sfr31ExecOwnerCall(vmAddr, reinterpret_cast<UPInt>(&cf), SFR33_OP()); SFR33_CALL_TAIL();
            case 0x4a:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecConstructProp(vmAddr, fileAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0x4c:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallPropLex(vmAddr, fileAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0x4e:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallSuperArgsB(vmAddr, fileAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0x4f:
            {
                const UInt32 a = SFR33_OP();
                const UInt32 n = SFR33_OP();
                Sfr31ExecCallPropVoid(vmAddr, fileAddr, a, n);
                SFR33_CALL_TAIL();
            }
            case 0x53:  // applytype
            {
                Sfr33ArgsObject args(this, SFR33_OP());
                if (!HandleException)
                {
                    Value& fv = args.ArgObject();
                    if (!fv.IsClass())
                        Sfr33ThrowType(*this, VM::Error(static_cast<VM::ErrorID>(1127), *this));
                    else
                        fv.Assign(&fv.AsClass().ApplyTypeArgs(args.ArgNum(), args.Argv()));
                }
            }
                SFR33_CHECK();
                break;
            case 0x55: Sfr31ExecNewObject(vmAddr, SFR33_OP()); break;
            case 0x56: Sfr33ExecNewArray(*this, sp, *reinterpret_cast<ValueStack*>(&OpStack), SFR33_OP()); break;
            case 0x57:  // newactivation
            {
                InstanceTraits::Traits* itr;
                {
                    ASString name(cf.Name.GetPtr());
                    VMAbcFile& f = *cf.pFile;
                    itr = Sfr33GetActivationInstanceTraits(f, f.GetAbcFile().MethodBodies.Info[cf.MBIIndex], &name);
                }
                Instance* obj = new (Sfr33TraitsAlloc(*itr)) Instance(*itr, Sfr33Tag());
                Sfr33OolTmp v;
                ValueAssignCopies::PickUnsafeObject19(v.v, obj);
                ++sp; _ReadWriteBarrier(); new (reinterpret_cast<Sfr33Stack*>(&OpStack)->pCurrent) Value(v.v);
                break;
            }
            case 0x58: Sfr31ExecClassEntry(vmAddr, fileAddr, SFR33_OP()); SFR33_CALL_TAIL();
            case 0x59: Sfr31ExecDeleteProp(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x5a:  // newcatch
                Sfr33ExecNewCatch(*this, sp, file, cf.pFile->GetException(cf.MBIIndex).info[static_cast<SInt32>(SFR33_OP())]);
                break;
            case 0x5d: Sfr31ExecGetLex(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x5e: Sfr31ExecFindPropOrGlobal(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x60: Sfr31ExecGetLexStatic(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x61: Sfr31ExecInitProperty(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x62: { const UInt32 idx = SFR33_OP(); const Value& r = SFR33_REG(idx); ++sp; _ReadWriteBarrier(); ValueAssignCopies::CopyCalled(sp, r); break; }
            case 0x63: SFR33_REG(SFR33_OP()).Pick(*sp); --sp; break;
            case 0x64:  // getglobalscope
            {
                Sfr33OolTmp scope(::FUN_14250a550(*this));
                ++sp; _ReadWriteBarrier();
                new (sp) Value(scope.v);
                break;
            }
            case 0x65:  // getscopeobject
            {
                const UPInt i = SFR33_OP() + cf.ScopeStackBaseInd;
                if (i >= ScopeStack.GetSize())
                    Sfr33ThrowRange(*this, VM::Error(static_cast<VM::ErrorID>(2006), *this));
                else
                {
                    ++sp; _ReadWriteBarrier();
                    ValueAssignCopies::CopyCalled(sp, ScopeStack[i]);
                    sp->SetWith(false);
                }
                break;
            }
            case 0x66: Sfr31ExecGetProp(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x67:  // getouterscope
            {
                const UInt32 i = SFR33_OP();
                const ScopeStackType* saved_scope = cf.pSavedScope;
                if (saved_scope == NULL || i >= saved_scope->GetSize())
                    Sfr33ThrowRange(*this, VM::Error(static_cast<VM::ErrorID>(2006), *this));
                else
                {
                    const Value& r = (*saved_scope)[i];
                    ++sp; _ReadWriteBarrier();
                    ValueAssignCopies::CopyCalled(sp, r);
                }
                break;
            }
            case 0x68: Sfr31ExecSetProperty(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x6b: --sp; break;
            case 0x6a: Sfr31ExecIn(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x69: { Value* const from = sp; sp = from + 1; ValueAssignCopies::CopyBits(*sp, *from); break; }
            case 0x6c: Sfr27ExecGetOwnSlot(this, SFR33_OP()); SFR33_CHECK(); break;
            case 0x6d: Sfr27ExecSetOwnSlot(this, SFR33_OP()); SFR33_CHECK(); break;
            case 0x6e: Sfr27ExecGetGlobalSlot(this, SFR33_OP()); SFR33_CHECK(); break;
            case 0x6f: Sfr27ExecSetGlobalSlot(this, SFR33_OP()); SFR33_CHECK(); break;
            case 0x70: sp->ToStringValue(GetStringManager()); SFR33_CHECK(); break;
            case 0x71: XMLSupport_->ToXMLString(*this, *sp); SFR33_CHECK(); break;
            case 0x72: Sfr33ExecEscXAttr(GetStringManager(), sp); SFR33_CHECK(); break;
            case 0x73: sp->ToInt32Value(); SFR33_CHECK(); break;
            case 0x74: sp->ToUInt32Value(); SFR33_CHECK(); break;
            case 0x75: sp->ToNumberValueInline(); SFR33_CHECK(); break;
            case 0x76: Sfr31ValueToBool(sp); break;
            case 0x77:  // coerce_o / checknotnull
                if (sp->IsUndefined() || (sp->IsObject() && sp->GetObject() == NULL))
                    Sfr33ThrowType(*this, VM::Error(static_cast<VM::ErrorID>(1009), *this));
                SFR33_CHECK();
                break;
            case 0x78: Sfr33ExecCheckFilter(*this, *sp); break;
            case 0x80: Sfr31ExecCheckScopeObject(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x85:  // coerce_s
                if (sp->IsNullOrUndefined())
                    FUN_142421ed0(sp);
                else
                    sp->ToStringValue(GetStringManager());
                SFR33_CHECK();
                break;
            case 0x86: Sfr31ExecAsTypeNamed(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0x87: Sfr27ExecAsType(this); SFR33_CHECK(); break;
            case 0x90:  // negate
                if (sp->ToNumberValueInline())
                    sp->AsNumber() = -sp->AsNumber();
                SFR33_CHECK();
                break;
            case 0x91:  // increment
                if (sp->ToNumberValueInline())
                    sp->AsNumber() += 1.0;
                SFR33_CHECK();
                break;
            case 0x92:  // inclocal
            {
                Value::Number d;
                Value& r = SFR33_REG(SFR33_OP());
                if (r.Convert2NumberInline(d))
                    r.SetNumber(d + 1.0);
                SFR33_CHECK();
                break;
            }
            case 0x93:  // decrement
                if (sp->ToNumberValueInline())
                    sp->AsNumber() += -1.0;
                SFR33_CHECK();
                break;
            case 0x94:  // declocal
            {
                Value::Number d;
                Value& r = SFR33_REG(SFR33_OP());
                if (r.Convert2NumberInline(d))
                    r.SetNumber(d - 1.0);
                SFR33_CHECK();
                break;
            }
            case 0x95: Sfr27ExecTypeOf(this); SFR33_CHECK(); break;
            case 0x96: Sfr31ValueToBool(sp); sp->AsBool() = !sp->AsBool(); SFR33_CHECK(); break;
            case 0x97:  // bitnot
            {
                SInt32 i;
                if (sp->Convert2Int32(i))
                    sp->SetSInt32(~i);
                SFR33_CHECK();
                break;
            }
            case 0x9b:  // add_d
            {
                Sfr33SH2<Value::Number, Value::Number> stack(sp);
                if (stack.Success)
                    stack._1 += stack._2;
                SFR33_CHECK();
                break;
            }
            case 0xa0:  // add
            {
                Sfr33Pop2 r(sp);
                Add(GetStringManager(), (*r._1), (*r._1), r.v);
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xa1:  // subtract
            {
                Value::Number rn = 0.0;
                Sfr33Pop2 r(sp);
                Sfr33ArithSub(r, rn);
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xa2:  // multiply
            {
                Value::Number rn = 0.0;
                Sfr33Pop2 r(sp);
                Sfr33ArithMul(r, rn);
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xa3:  // divide
            {
                Sfr33SH2<Value::Number, Value::Number> stack(sp);
                if (stack.Success)
                    stack._1 /= stack._2;
                SFR33_CHECK();
                break;
            }
            case 0x7f: sp[-1].AsNumber() /= sp->AsNumber(); --sp; break;
            case 0xa4:  // modulo
            {
                Sfr33SH2<Value::Number, Value::Number> stack(sp);
                if (stack.Success)
                    stack._1 = fmod(stack._1, stack._2);
                SFR33_CHECK();
                break;
            }
            case 0xa5:  // lshift
            {
                Sfr33SH2<SInt32, UInt32> stack(sp);
                if (stack.Success)
                    stack._1 <<= (stack._2 & 0x1F);
                SFR33_CHECK();
                break;
            }
            case 0xa6:  // rshift
            {
                Sfr33SH2<SInt32, UInt32> stack(sp);
                if (stack.Success)
                    stack._1 >>= (stack._2 & 0x1F);
                SFR33_CHECK();
                break;
            }
            case 0xa7:  // urshift
            {
                Sfr33SH2<UInt32, UInt32> stack(sp);
                if (stack.Success)
                    stack._1 >>= (stack._2 & 0x1F);
                SFR33_CHECK();
                break;
            }
            case 0xa8:  // bitand
            {
                Sfr33SH2<SInt32, SInt32> stack(sp);
                if (stack.Success)
                    stack._1 &= stack._2;
                SFR33_CHECK();
                break;
            }
            case 0xa9:  // bitor
            {
                Sfr33SH2<SInt32, SInt32> stack(sp);
                if (stack.Success)
                    stack._1 |= stack._2;
                SFR33_CHECK();
                break;
            }
            case 0xaa:  // bitxor
            {
                Sfr33SH2<SInt32, SInt32> stack(sp);
                if (stack.Success)
                    stack._1 ^= stack._2;
                SFR33_CHECK();
                break;
            }
            case 0xab:  // equals
            {
                bool eq = false;
                Sfr33Pop2 r(sp);
                if (AbstractEqual(eq, (*r._1), r.v))
                    (*r._1).SetBool(eq);
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xac:  // strictequals
            {
                Sfr33Pop2 r(sp);
                const bool eq = StrictEqual((*r._1), r.v);
                (*r._1).Assign(Value(eq));
                FUN_1424dd460(&r);
                break;
            }
            case 0xad:  // lessthan
            {
                r3 = undefined3;
                Sfr33Pop2 r(sp, Sfr33Pop2::Reg());
                if (AbstractLessThan(r3, (*r._1), r.v))
                    (*r._1).SetBool(r3 == true3);
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xae:  // lessequals
            {
                r3 = undefined3;
                Sfr33Pop2 r(sp, Sfr33Pop2::Reg());
                if (AbstractLessThan(r3, r.v, (*r._1)))
                    (*r._1).SetBool(r3 == false3);
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xaf:  // greaterthan
            {
                r3 = undefined3;
                Sfr33Pop2 r(sp, Sfr33Pop2::Reg());
                if (AbstractLessThan(r3, r.v, (*r._1)))
                    (*r._1).SetBool(r3 == true3);
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xb0:  // greaterequals
            {
                r3 = undefined3;
                Sfr33Pop2 r(sp, Sfr33Pop2::Reg());
                if (AbstractLessThan(r3, (*r._1), r.v))
                    (*r._1).SetBool(r3 == false3);
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xb1: Sfr31ExecInstanceOf(vmAddr); SFR33_CHECK(); break;
            case 0xb2: Sfr31ExecIsTypeNamed(vmAddr, fileAddr, SFR33_OP()); SFR33_CHECK(); break;
            case 0xb3:  // istypelate
            {
                Sfr33Pop2 r(sp);
                if (r.v.IsClass())
                    (*r._1).Assign(Value(FUN_1425146d0(this, sp, &r.v.AsClass().GetTraits())));
                else
                    Sfr33ThrowType(*this, VM::Error(static_cast<VM::ErrorID>(1041), *this));
                FUN_1424dd460(&r);
                SFR33_CHECK();
                break;
            }
            case 0xb4: Sfr31ExecIn(vmAddr); SFR33_CHECK(); break;
            case 0xb5: { Value v(GetAbsObject(*cp++)); ++sp; _ReadWriteBarrier(); ValueAssignCopies::CopyCalled(sp, v); break; }
            case 0xb6: Sfr27ExecGetSlot(this, static_cast<SPInt>(static_cast<SInt32>(SFR33_OP()))); SFR33_CHECK(); break;
            case 0xb7: Sfr27ExecSetSlot(this, static_cast<SPInt>(static_cast<SInt32>(SFR33_OP()))); SFR33_CHECK(); break;
            case 0xb8: Sfr27ExecInitSlot(this, static_cast<SPInt>(static_cast<SInt32>(SFR33_OP()))); SFR33_CHECK(); break;
            case 0xc0: if (sp->ToInt32Value()) ++sp->AsInt(); SFR33_CHECK(); break;   // increment_i
            case 0xc1: if (sp->ToInt32Value()) --sp->AsInt(); SFR33_CHECK(); break;   // decrement_i
            case 0xc2:
            {
                Value& r = SFR33_REG(SFR33_OP());
                if (r.ToInt32Value())
                    ++r.AsInt();
                SFR33_CHECK();
                break;
            }
            case 0xc3:
            {
                Value& r = SFR33_REG(SFR33_OP());
                if (r.ToInt32Value())
                    --r.AsInt();
                SFR33_CHECK();
                break;
            }
            case 0xc4: if (sp->ToInt32Value()) sp->AsInt() = -sp->AsInt(); SFR33_CHECK(); break;   // negate_i
            case 0x3f: sp->AsInt() = -sp->AsInt(); break;
            case 0x54: sp->AsNumber() = -sp->AsNumber(); break;
            case 0xc5:  // add_i
            {
                Sfr33SH2<SInt32, SInt32> stack(sp);
                if (stack.Success)
                    stack._1 += stack._2;
                SFR33_CHECK();
                break;
            }
            case 0x79: sp[-1].AsInt() += sp->AsInt(); --sp; break;
            case 0x7c: sp[-1].AsNumber() += sp->AsNumber(); --sp; break;
            case 0xc6:  // subtract_i
            {
                Sfr33SH2<SInt32, SInt32> stack(sp);
                if (stack.Success)
                    stack._1 -= stack._2;
                SFR33_CHECK();
                break;
            }
            case 0x7a: sp[-1].AsInt() -= sp->AsInt(); --sp; break;
            case 0x7d: sp[-1].AsNumber() -= sp->AsNumber(); --sp; break;
            case 0xc7:  // multiply_i
            {
                Sfr33SH2<SInt32, SInt32> stack(sp);
                if (stack.Success)
                    stack._1 *= stack._2;
                SFR33_CHECK();
                break;
            }
            case 0x7b: sp[-1].AsInt() *= sp->AsInt(); --sp; break;
            case 0x7e: sp[-1].AsNumber() *= sp->AsNumber(); --sp; break;
            case 0xd0:
                { const Value& r = SFR33_REG(0); ++sp; _ReadWriteBarrier(); ValueAssignCopies::CopyCalled(sp, r); }
                break;
            case 0xd1:
                { const Value& r = SFR33_REG(1); ++sp; _ReadWriteBarrier(); ValueAssignCopies::CopyCalled(sp, r); }
                break;
            case 0xd2:
                { const Value& r = SFR33_REG(2); ++sp; _ReadWriteBarrier(); ValueAssignCopies::CopyCalled(sp, r); }
                break;
            case 0xd3:
                { const Value& r = SFR33_REG(3); ++sp; _ReadWriteBarrier(); ValueAssignCopies::CopyCalled(sp, r); }
                break;
            case 0xd4:
                SFR33_REG(0).Pick(*sp);
                --sp;
                break;
            case 0xd5:
                SFR33_REG(1).Pick(*sp);
                --sp;
                break;
            case 0xd6:
                SFR33_REG(2).Pick(*sp);
                --sp;
                break;
            case 0xd7:
                SFR33_REG(3).Pick(*sp);
                --sp;
                break;
            case 0xef: cp += 4; break;   // debug
            case 0x47:  // returnvoid
                if (!Sfr33FrameAt(*this, Sfr33CallStack(*this).Size - 1).DiscardResult)
                {
                    ++sp; _ReadWriteBarrier();
                    ValueAssignCopies::CopyCalled(sp, Value::GetUndefined());
                }
                goto exit_frame;
            case 0x48:  // returnvalue
                if (Sfr33FrameAt(*this, Sfr33CallStack(*this).Size - 1).DiscardResult)
                {
                    sp->~Value();
                    --sp;
                }
                else
                    FUN_1424efe30(this, sp, sp);
                if (HandleException)
                    FUN_142519a00(this, static_cast<UPInt>(cp - Sfr33CallFrameGetCode(cf).GetDataPtr()), &cf);
                goto exit_frame;
            default:
                break;
            }
            continue;

        }
#undef SFR33_OP
#undef SFR33_REG
#undef SFR33_CHECK
#undef SFR33_CALL_TAIL
#undef sp

    exit_frame:
        if (HandleException)
            Sfr33FrameAt(*this, Sfr33CallStack(*this).Size - 1).ClearOpStack();
        Sfr34_CallFramePagedArray_PopBack(reinterpret_cast<Sfr34_CallFramePagedArray*>(&Unk070));
        if (--max_stack_depth == 0)
            break;
    next_frame:;
        }
        call_stack_size = Sfr33CallStack(*this).Size;
    }
    return static_cast<int>(max_stack_depth);
}

}}} // namespace Scaleform::GFx::AS3
