// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 VM interpreter loop
// (VM::ExecuteCode). Our own source, written from the exe. The opcode handlers the exe also has out of line are
// called through their sfr_as3_19 recoveries; the rest are written here.
// MS2-UNIT: sfr_as3_17b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424fa5b0-0x1424fe5b0 .text$mn
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_e4x.h"
#undef GetObject

int FUN_142519a00(Scaleform::GFx::AS3::VM* vm, Scaleform::UPInt index, void* frame);   // the frame's handler at index, or < 0
void FUN_1424efe30(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* value, Scaleform::GFx::AS3::Value* result);
void FUN_14241de40(void* stack, unsigned n);   // ValueStack::PopBack: pops (and releases) the top n values
bool FUN_1425146d0(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* v, const void* traits);
Scaleform::UPInt FUN_14250a550(Scaleform::UPInt vm);   // the VM's fallback object (global)
void FUN_1424d9530(void* ra, Scaleform::GFx::AS3::VM* vm, Scaleform::UInt32 argc);   // ReadArgs::ReadArgs
void FUN_1424de9e0(void* ra);                                                        // ReadArgs::~ReadArgs

namespace Scaleform { namespace GFx { namespace AS3 {

// sfr_as3_17
const ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>& Sfr33CallFrameGetCode(CallFrame& cf);
InstanceTraits::Traits* Sfr33GetActivationInstanceTraits(VMAbcFile& file, const Abc::MethodBodyInfo* mbi, void* p);
void Sfr33CheckObject(VM* const* self, const Value& v);

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
bool Sfr31StrictEquals(const UInt32* a, const UInt32* b);
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

// The raw storage of a ReadArgs, built and torn down by the exe's own out-of-line functions.
struct Sfr33Args
{
    Sfr33Args(VM* vm, UInt32 argc) { FUN_1424d9530(buf, vm, argc); }
    ~Sfr33Args() { FUN_1424de9e0(buf); }
    UInt32 ArgNum() const { return *reinterpret_cast<const UInt32*>(buf + 0x10); }
    const Value* Argv() const
    {
        return ArgNum() > 8 ? *reinterpret_cast<const Value* const*>(buf + 0x118) : reinterpret_cast<const Value*>(buf + 0x18);
    }
    UInt8 buf[0x140];
};

inline CallFrameStack& Sfr33CallStack(VM& vm) { return *reinterpret_cast<CallFrameStack*>(vm.Unk070); }

inline CallFrame& Sfr33FrameAt(VM& vm, UPInt i)
{
    return Sfr33CallStack(vm).Pages[i >> 6][i & 0x3f];
}

// pushwith / pushscope: the top of the operand stack moves onto the scope stack (TypeError 1010 for undefined, 1009
// for a null object).
inline void Sfr33PushScope(VM& vm, Value*& sp, bool with)
{
    if (sp->IsUndefined())
    {
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(1010), vm));
        return;
    }
    if (sp->IsObject() && sp->GetObject() == NULL)
    {
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(1009), vm));
        return;
    }
    vm.ScopeStack.PushBack(Value::GetUndefined());
    Value& back = vm.ScopeStack[vm.ScopeStack.GetSize() - 1];
    back.Pick(*sp);
    if (with)
        back.SetWith(true);
    sp->~Value();
    --sp;
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

// The run of the frame cf from pc until it returns, throws out or calls into a new frame.
Sfr33ExecExit Sfr33ExecFrame(VM& vm, CallFrame& cf, const UPInt* pc, UPInt sizeAtEntry)
{
    VMAbcFile& file = *cf.pFile;
    const Abc::File& abc = file.GetAbcFile();
    const UPInt* const code = Sfr33CallFrameGetCode(cf).GetDataPtr();
    const UPInt vmAddr = reinterpret_cast<UPInt>(&vm);
    const UPInt fileAddr = reinterpret_cast<UPInt>(&file);
    Value*& sp = *reinterpret_cast<Value**>(&vm.OpStack[1]);
    StringManager& sm = vm.GetStringManager();

    // A pending exception moves pc to the frame's handler, or leaves the frame.
#define SFR33_CHECK(next)                                                                  \
    do                                                                                     \
    {                                                                                      \
        pc = (next);                                                                       \
        if (vm.HandleException)                                                            \
        {                                                                                  \
            const int h = FUN_142519a00(&vm, static_cast<UPInt>(pc - code), &cf);          \
            if (h < 0)                                                                     \
                return Sfr33ExitLeaveExc;                                                  \
            pc = code + h;                                                                 \
        }                                                                                  \
    } while (0)
    // After a call: a pushed frame runs next, this one resumes at pc.
#define SFR33_CALL_TAIL(next)                                                              \
    do                                                                                     \
    {                                                                                      \
        SFR33_CHECK(next);                                                                 \
        if (Sfr33CallStack(vm).Size != sizeAtEntry)                                        \
        {                                                                                  \
            Sfr33FrameAt(vm, sizeAtEntry - 1).CP = pc;                                     \
            return Sfr33ExitCalled;                                                        \
        }                                                                                  \
    } while (0)
#define SFR33_REG(i) (reinterpret_cast<Value*>(vm.RegisterFile[1])[i])

    for (;;)
    {
        const UPInt* const ip = pc;
        const UInt32 op1 = static_cast<UInt32>(ip[1]);
        const UInt32 op2 = static_cast<UInt32>(ip[2]);
        const SInt32 off = static_cast<SInt32>(ip[1]);
        switch (ip[0])
        {
        case 0x03:  // throw
            vm.ExceptionObj.Pick(*sp);
            sp->~Value();
            --sp;
            vm.HandleException = true;
            {
                const int h = FUN_142519a00(&vm, static_cast<UPInt>(ip + 1 - code), &cf);
                if (h < 0)
                    return Sfr33ExitLeaveExc;
                pc = code + h;
            }
            break;
        case 0x04: Sfr31ExecGetSuper(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x05: Sfr31ExecSetSuper(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x06:  // dxns
            cf.DefXMLNamespace = &file.GetInternedNamespace(op1);
            SFR33_CHECK(ip + 2);
            break;
        case 0x07: Sfr31ExecPushNamespace(vmAddr, reinterpret_cast<UPInt>(&cf)); SFR33_CHECK(ip + 1); break;
        case 0x08:  // kill
            SFR33_REG(op1).Assign(Value::GetUndefined());
            pc = ip + 2;
            break;
        case 0x0a:
        case 0x37:
            ++SFR33_REG(op1).AsInt();
            pc = ip + 2;
            break;
        case 0x0b:
        case 0x38:
            --SFR33_REG(op1).AsInt();
            pc = ip + 2;
            break;

        // generic compare-and-branch: the two operands are popped either way
        case 0x0c: case 0x0d: case 0x0e: case 0x0f: case 0x15: case 0x16: case 0x17: case 0x18:
        {
            const Value& a = sp[-1];
            const Value& b = *sp;
            Boolean3 r = undefined3;
            bool jump = false;
            switch (ip[0])
            {
            case 0x0c: jump = AbstractLessThan(r, a, b) && r != true3; break;   // ifnlt
            case 0x0d: jump = AbstractLessThan(r, b, a) && r != false3; break;  // ifnle
            case 0x0e: jump = AbstractLessThan(r, b, a) && r != true3; break;   // ifngt
            case 0x0f: jump = AbstractLessThan(r, a, b) && r != false3; break;  // ifnge
            case 0x15: jump = AbstractLessThan(r, a, b) && r == true3; break;   // iflt
            case 0x16: jump = AbstractLessThan(r, b, a) && r == false3; break;  // ifle
            case 0x17: jump = AbstractLessThan(r, b, a) && r == true3; break;   // ifgt
            case 0x18: jump = AbstractLessThan(r, a, b) && r == false3; break;  // ifge
            }
            FUN_14241de40(vm.OpStack, 2);
            SFR33_CHECK(ip + 2);
            if (pc == ip + 2 && jump)
                pc = ip + 2 + off;
            break;
        }
        case 0x13:
        case 0x14:
        {
            bool eq = false;
            const bool ok = AbstractEqual(eq, sp[-1], *sp);
            const bool jump = ok && (ip[0] == 0x13 ? eq : !eq);
            FUN_14241de40(vm.OpStack, 2);
            SFR33_CHECK(ip + 2);
            if (pc == ip + 2 && jump)
                pc = ip + 2 + off;
            break;
        }
        case 0x10:  // jump
            pc = ip + 2 + off;
            break;
        case 0xf0: case 0xf1: case 0xf2:
            pc = ip + 2;
            break;
        case 0x11:
        case 0x12:
        {
            Sfr31ValueToBool(sp);
            const bool b = sp->AsBool();
            --sp;
            pc = ip + 2 + ((ip[0] == 0x11 ? b : !b) ? off : 0);
            break;
        }
        case 0x19:
        case 0x1a:
        {
            const bool eq = Sfr31StrictEquals(reinterpret_cast<const UInt32*>(sp - 1), reinterpret_cast<const UInt32*>(sp));
            sp->~Value();
            --sp;
            sp->~Value();
            --sp;
            pc = ip + 2 + ((ip[0] == 0x19 ? eq : !eq) ? off : 0);
            break;
        }
        case 0x1b:  // lookupswitch
        {
            SInt32 target = off;
            const UPInt cnt = ip[2];
            const SInt32 i = sp->AsInt();
            sp->~Value();
            --sp;
            if (i >= 0 && static_cast<UPInt>(i) <= cnt)
                target = static_cast<SInt32>(ip[3 + i]);
            pc = ip + target;
            break;
        }
        case 0x1c: Sfr33PushScope(vm, sp, true); SFR33_CHECK(ip + 1); break;
        case 0x30: Sfr33PushScope(vm, sp, false); SFR33_CHECK(ip + 1); break;
        case 0x1d:  // popscope
            vm.ScopeStack.PopBack();
            pc = ip + 1;
            break;
        case 0x1e: Sfr27ExecNextName(&vm); SFR33_CHECK(ip + 1); break;
        case 0x23: Sfr27ExecNextValue(&vm); SFR33_CHECK(ip + 1); break;
        case 0x1f: Sfr31ExecIndexedQuery(vmAddr); SFR33_CHECK(ip + 1); break;
        case 0x20: ++sp; new (sp) Value(static_cast<Object*>(NULL)); pc = ip + 1; break;
        case 0x21: ++sp; new (sp) Value(); pc = ip + 1; break;
        case 0x22: sp->AsBool() = !sp->AsBool(); pc = ip + 1; break;
        case 0x24: ++sp; new (sp) Value(static_cast<SInt32>(static_cast<signed char>(op1))); pc = ip + 2; break;
        case 0x25: ++sp; new (sp) Value(static_cast<SInt32>(op1)); pc = ip + 2; break;
        case 0x26: ++sp; new (sp) Value(true); pc = ip + 1; break;
        case 0x27: ++sp; new (sp) Value(false); pc = ip + 1; break;
        case 0x28: ++sp; new (sp) Value(NumberUtil::NaN()); pc = ip + 1; break;
        case 0x29: sp->~Value(); --sp; pc = ip + 1; break;
        case 0x2a: ++sp; new (sp) Value(sp[-1]); pc = ip + 1; break;
        case 0x2b: sp[-1].Swap(*sp); pc = ip + 1; break;
        case 0x2c:  // pushstring
        {
            const StringDataPtr s = abc.Const_Pool.GetString(op1);
            ASString str(sm.GetStringManager()->CreateStringNode(s.ToCStr(), s.GetSize()));
            ++sp;
            new (sp) Value(str);
            pc = ip + 2;
            break;
        }
        case 0x2d: ++sp; new (sp) Value(abc.Const_Pool.ConstInt[op1]); pc = ip + 2; break;
        case 0x2e: ++sp; new (sp) Value(abc.Const_Pool.ConstUInt[op1]); pc = ip + 2; break;
        case 0x2f: ++sp; new (sp) Value(abc.Const_Pool.GetDouble(op1)); pc = ip + 2; break;
        case 0x31: ++sp; new (sp) Value(&file.GetInternedNamespace(op1)); pc = ip + 2; break;
        case 0x32: Sfr31ExecHasNext2(vmAddr, op1, op2); SFR33_CHECK(ip + 3); break;
        case 0x33:
        case 0x34:
        {
            const bool b = sp->AsBool();
            --sp;
            pc = ip + 2 + ((ip[0] == 0x33 ? b : !b) ? off : 0);
            break;
        }
        case 0x35: case 0x98: ++sp->AsInt(); pc = ip + 1; break;
        case 0x36: case 0x99: --sp->AsInt(); pc = ip + 1; break;
        case 0x3f: sp->AsInt() = -sp->AsInt(); pc = ip + 1; break;
        case 0x54: sp->AsNumber() = -sp->AsNumber(); pc = ip + 1; break;
        case 0x40: Sfr31ExecNewFunction(vmAddr, reinterpret_cast<UPInt>(&cf), op1); pc = ip + 2; break;
        case 0x41: Sfr27ExecCallVoid(&vm, op1); SFR33_CALL_TAIL(ip + 2); break;
        case 0x42: Sfr31ExecCallValue(vmAddr, op1); SFR33_CALL_TAIL(ip + 2); break;
        case 0x43: Sfr31ExecCallWithTraits(vmAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0x44: Sfr31ExecCallStatic(vmAddr, fileAddr, static_cast<SInt32>(op1), op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0x45: Sfr31ExecCallSuperArgsA(vmAddr, fileAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0x46: Sfr31ExecCallProperty(vmAddr, fileAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0x47:  // returnvoid
            if (!cf.DiscardResult)
            {
                ++sp;
                new (sp) Value();
            }
            return Sfr33ExitLeaveExc;
        case 0x48:  // returnvalue
            if (!cf.DiscardResult)
                FUN_1424efe30(&vm, sp, sp);
            else
            {
                sp->~Value();
                --sp;
            }
            if (!vm.HandleException)
                return Sfr33ExitLeave;
            FUN_142519a00(&vm, static_cast<UPInt>(ip + 1 - code), &cf);
            return Sfr33ExitLeaveExc;
        case 0x49: Sfr31ExecOwnerCall(vmAddr, reinterpret_cast<UPInt>(&cf), op1); SFR33_CALL_TAIL(ip + 2); break;
        case 0x4a: Sfr31ExecConstructProp(vmAddr, fileAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0x4c: Sfr31ExecCallPropLex(vmAddr, fileAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0x4e: Sfr31ExecCallSuperArgsB(vmAddr, fileAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0x4f: Sfr31ExecCallPropVoid(vmAddr, fileAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0x53:  // applytype
        {
            Sfr33Args args(&vm, op1);
            Value& fv = *sp;
            VM* self = &vm;
            Sfr33CheckObject(&self, fv);
            if (!vm.HandleException)
            {
                if (fv.IsClass())
                    fv.Assign(&fv.AsClass().ApplyTypeArgs(args.ArgNum(), args.Argv()));
                else
                    vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(1127), vm));
            }
        }
            SFR33_CHECK(ip + 2);
            break;
        case 0x55: Sfr31ExecNewObject(vmAddr, op1); pc = ip + 2; break;
        case 0x56: Sfr31ExecNewArray(vmAddr, op1); pc = ip + 2; break;
        case 0x57:  // newactivation
        {
            ASString name(cf.Name.GetPtr());
            InstanceTraits::Traits* itr =
                Sfr33GetActivationInstanceTraits(file, abc.MethodBodies.Info[cf.MBIIndex], &name);
            Instance* obj = new (itr->Alloc()) Instance(*itr);
            ++sp;
            new (sp) Value(Pickable<Object>(obj));
            pc = ip + 1;
            break;
        }
        case 0x58: Sfr31ExecClassEntry(vmAddr, fileAddr, op1); SFR33_CALL_TAIL(ip + 2); break;
        case 0x59: Sfr31ExecDeleteProp(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x5a:  // newcatch
            Sfr31ExecPushInterfaceInstance(vmAddr, fileAddr,
                                           reinterpret_cast<UPInt>(&file.GetException(cf.MBIIndex).info[op1]));
            pc = ip + 2;
            break;
        case 0x5d: Sfr31ExecGetLex(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x5e: Sfr31ExecFindPropOrGlobal(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x60: Sfr31ExecGetLexStatic(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x61: Sfr31ExecInitProperty(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x62: ++sp; new (sp) Value(SFR33_REG(op1)); pc = ip + 2; break;
        case 0xd0: case 0xd1: case 0xd2: case 0xd3:
            ++sp;
            new (sp) Value(SFR33_REG(ip[0] - 0xd0));
            pc = ip + 1;
            break;
        case 0x63: SFR33_REG(op1).Pick(*sp); --sp; pc = ip + 2; break;
        case 0xd4: case 0xd5: case 0xd6: case 0xd7:
            SFR33_REG(ip[0] - 0xd4).Pick(*sp);
            --sp;
            pc = ip + 1;
            break;
        case 0x64:  // getglobalscope
            ++sp;
            new (sp) Value(reinterpret_cast<Object*>(FUN_14250a550(vmAddr)));
            pc = ip + 1;
            break;
        case 0x65:  // getscopeobject
        {
            const UPInt i = op1 + cf.ScopeStackBaseInd;
            if (i >= vm.ScopeStack.GetSize())
                vm.ThrowRangeError(VM::Error(static_cast<VM::ErrorID>(2006), vm));
            else
            {
                ++sp;
                new (sp) Value(vm.ScopeStack[i]);
                sp->SetWith(false);
            }
            pc = ip + 2;
            break;
        }
        case 0x66: Sfr31ExecGetProp(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x67:  // getouterscope
        {
            const ScopeStackType* saved = cf.pSavedScope;
            if (saved == NULL || op1 >= saved->GetSize())
                vm.ThrowRangeError(VM::Error(static_cast<VM::ErrorID>(2006), vm));
            else
            {
                ++sp;
                new (sp) Value((*saved)[op1]);
            }
            pc = ip + 2;
            break;
        }
        case 0x68: Sfr31ExecSetProperty(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x69: ++sp; memcpy(static_cast<void*>(sp), sp - 1, sizeof(Value)); pc = ip + 1; break;
        case 0x6a: Sfr31ExecIn(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x6b: --sp; pc = ip + 1; break;
        case 0x6c: Sfr27ExecGetOwnSlot(&vm, op1); SFR33_CHECK(ip + 2); break;
        case 0x6d: Sfr27ExecSetOwnSlot(&vm, op1); SFR33_CHECK(ip + 2); break;
        case 0x6e: Sfr27ExecGetGlobalSlot(&vm, op1); SFR33_CHECK(ip + 2); break;
        case 0x6f: Sfr27ExecSetGlobalSlot(&vm, op1); SFR33_CHECK(ip + 2); break;
        case 0x70: sp->ToStringValue(sm); SFR33_CHECK(ip + 1); break;
        case 0x71: vm.XMLSupport_->ToXMLString(vm, *sp); SFR33_CHECK(ip + 1); break;
        case 0x72: Sfr31ExecEscXAttr(vmAddr); SFR33_CHECK(ip + 1); break;
        case 0x73: sp->ToInt32Value(); SFR33_CHECK(ip + 1); break;
        case 0x74: sp->ToUInt32Value(); SFR33_CHECK(ip + 1); break;
        case 0x75: sp->ToNumberValueInline(); SFR33_CHECK(ip + 1); break;
        case 0x76: Sfr31ValueToBool(sp); pc = ip + 1; break;
        case 0x77:  // coerce_o / checknotnull
            if (sp->IsUndefined() || (sp->IsObject() && sp->GetObject() == NULL))
                vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(1009), vm));
            SFR33_CHECK(ip + 1);
            break;
        case 0x78: Sfr31ExecCheckFilter(vmAddr); pc = ip + 1; break;
        case 0x79: sp[-1].AsInt() += sp->AsInt(); --sp; pc = ip + 1; break;
        case 0x7a: sp[-1].AsInt() -= sp->AsInt(); --sp; pc = ip + 1; break;
        case 0x7b: sp[-1].AsInt() *= sp->AsInt(); --sp; pc = ip + 1; break;
        case 0x7c: sp[-1].AsNumber() += sp->AsNumber(); --sp; pc = ip + 1; break;
        case 0x7d: sp[-1].AsNumber() -= sp->AsNumber(); --sp; pc = ip + 1; break;
        case 0x7e: sp[-1].AsNumber() *= sp->AsNumber(); --sp; pc = ip + 1; break;
        case 0x7f: sp[-1].AsNumber() /= sp->AsNumber(); --sp; pc = ip + 1; break;
        case 0x80: Sfr31ExecCheckScopeObject(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x85:  // coerce_s
            if (sp->IsNullOrUndefined())
                sp->SetNull();
            else
                sp->ToStringValue(sm);
            SFR33_CHECK(ip + 1);
            break;
        case 0x86: Sfr31ExecAsTypeNamed(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0x87: Sfr27ExecAsType(&vm); SFR33_CHECK(ip + 1); break;

        // int compare-and-branch on raw operands
        case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f:
        case 0x9c: case 0x9d: case 0x9e: case 0x9f:
        {
            const SInt32 a = sp[-1].AsInt();
            const SInt32 b = sp->AsInt();
            sp -= 2;
            bool stay = false;
            switch (ip[0])
            {
            case 0x8a: case 0x8f: stay = a < b; break;
            case 0x8b: case 0x9c: stay = a <= b; break;
            case 0x8c: case 0x9d: stay = b < a; break;
            case 0x8d: case 0x9e: stay = b <= a; break;
            case 0x8e: stay = a != b; break;
            case 0x9f: stay = a == b; break;
            }
            pc = ip + 2 + (stay ? 0 : off);
            break;
        }

        case 0x90:  // negate
            if (sp->ToNumberValueInline())
                sp->AsNumber() = -sp->AsNumber();
            SFR33_CHECK(ip + 1);
            break;
        case 0x91:
        case 0x93:
            if (sp->ToNumberValueInline())
                sp->AsNumber() += ip[0] == 0x91 ? 1.0 : -1.0;
            SFR33_CHECK(ip + 1);
            break;
        case 0x92:
        case 0x94:
        {
            Value::Number d;
            Value& r = SFR33_REG(op1);
            if (r.Convert2NumberInline(d))
                r.SetNumber(ip[0] == 0x92 ? d + 1.0 : d - 1.0);
            SFR33_CHECK(ip + 2);
            break;
        }
        case 0x95: Sfr27ExecTypeOf(&vm); SFR33_CHECK(ip + 1); break;
        case 0x96: Sfr31ValueToBool(sp); sp->AsBool() = !sp->AsBool(); SFR33_CHECK(ip + 1); break;
        case 0x97:
        {
            SInt32 i;
            if (sp->Convert2Int32(i))
                sp->SetSInt32(~i);
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0x9b: case 0xa3: case 0xa4:   // add_d / divide / modulo
        {
            const bool rok = sp->ToNumberValueInline();
            const Value::Number r = rok ? sp->AsNumber() : 0.0;
            const bool lok = rok && sp[-1].ToNumberValueInline();
            sp->~Value();
            --sp;
            if (lok)
            {
                Value::Number& l = sp->AsNumber();
                if (ip[0] == 0x9b)
                    l += r;
                else if (ip[0] == 0xa3)
                    l = l / r;
                else
                    l = fmod(l, r);
            }
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0xa0:  // add
        {
            Value r(*sp, PickValue);
            --sp;
            Add(sm, *sp, *sp, r);
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0xa1:
        case 0xa2:
        {
            Value r(*sp, PickValue);
            --sp;
            Value::Number l, rn;
            if (sp->Convert2NumberInline(l) && r.Convert2NumberInline(rn))
                sp->SetNumber(ip[0] == 0xa1 ? l - rn : l * rn);
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa:
        {
            const bool uns = ip[0] == 0xa7;
            const bool rok = ip[0] <= 0xa7 ? sp->ToUInt32Value() : sp->ToInt32Value();
            const UInt32 r = rok ? sp->AsUInt() : 0;
            const bool lok = rok && (uns ? sp[-1].ToUInt32Value() : sp[-1].ToInt32Value());
            sp->~Value();
            --sp;
            if (lok)
            {
                switch (ip[0])
                {
                case 0xa5: sp->AsInt() <<= (r & 31); break;
                case 0xa6: sp->AsInt() >>= (r & 31); break;
                case 0xa7: sp->AsUInt() >>= (r & 31); break;
                case 0xa8: sp->AsInt() &= static_cast<SInt32>(r); break;
                case 0xa9: sp->AsInt() |= static_cast<SInt32>(r); break;
                case 0xaa: sp->AsInt() ^= static_cast<SInt32>(r); break;
                }
            }
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0xab:  // equals
        {
            Value r(*sp, PickValue);
            --sp;
            bool eq = false;
            if (AbstractEqual(eq, *sp, r))
                sp->SetBool(eq);
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0xac:  // strictequals
        {
            Value r(*sp, PickValue);
            --sp;
            const bool eq = StrictEqual(*sp, r);
            sp->Assign(Value(eq));
            pc = ip + 1;
            break;
        }
        case 0xad: case 0xae: case 0xaf: case 0xb0:
        {
            Value r(*sp, PickValue);
            --sp;
            Boolean3 b3 = undefined3;
            bool ok;
            bool res;
            switch (ip[0])
            {
            case 0xad: ok = AbstractLessThan(b3, *sp, r); res = b3 == true3; break;   // lessthan
            case 0xae: ok = AbstractLessThan(b3, r, *sp); res = b3 == false3; break;  // lessequals
            case 0xaf: ok = AbstractLessThan(b3, r, *sp); res = b3 == true3; break;   // greaterthan
            default:   ok = AbstractLessThan(b3, *sp, r); res = b3 == false3; break;  // greaterequals
            }
            if (ok)
                sp->SetBool(res);
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0xb1: Sfr31ExecInstanceOf(vmAddr); SFR33_CHECK(ip + 1); break;
        case 0xb2: Sfr31ExecIsTypeNamed(vmAddr, fileAddr, op1); SFR33_CHECK(ip + 2); break;
        case 0xb3:  // istypelate
        {
            Value r(*sp, PickValue);
            --sp;
            if (r.IsClass())
                sp->Assign(Value(FUN_1425146d0(&vm, sp, &r.AsClass().GetTraits())));
            else
                vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(1041), vm));
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0xb4: Sfr31ExecIn(vmAddr); SFR33_CHECK(ip + 1); break;
        case 0xb5: ++sp; new (sp) Value(GetAbsObject(ip[1])); pc = ip + 2; break;
        case 0xb6: Sfr27ExecGetSlot(&vm, static_cast<SPInt>(static_cast<SInt32>(op1))); SFR33_CHECK(ip + 2); break;
        case 0xb7: Sfr27ExecSetSlot(&vm, static_cast<SPInt>(static_cast<SInt32>(op1))); SFR33_CHECK(ip + 2); break;
        case 0xb8: Sfr27ExecInitSlot(&vm, static_cast<SPInt>(static_cast<SInt32>(op1))); SFR33_CHECK(ip + 2); break;
        case 0xb9: Sfr31ExecCallSuper(vmAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0xba: Sfr27ExecCallMethod(&vm, op1, op2); SFR33_CALL_TAIL(ip + 3); break;
        case 0xbb: Sfr31ExecCallParentSlot(vmAddr, op1, op2); SFR33_CALL_TAIL(ip + 3); break;

        // Number compare-and-branch on raw operands
        case 0xbc: case 0xbd: case 0xbe: case 0xbf: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd:
        {
            const Value::Number l = sp[-1].AsNumber();
            const Value::Number r = sp->AsNumber();
            sp -= 2;
            bool jump = false;
            switch (ip[0])
            {
            case 0xbc: case 0xc9: jump = r < l; break;
            case 0xbd: case 0xca: jump = l <= r; break;
            case 0xbe: case 0xcb: jump = l < r; break;
            case 0xbf: jump = !(l == r); break;
            case 0xc8: case 0xcd: jump = r <= l; break;
            case 0xcc: jump = l == r; break;
            }
            pc = ip + 2 + (jump ? off : 0);
            break;
        }

        case 0xc0: if (sp->ToInt32Value()) ++sp->AsInt(); SFR33_CHECK(ip + 1); break;   // increment_i
        case 0xc1: if (sp->ToInt32Value()) --sp->AsInt(); SFR33_CHECK(ip + 1); break;   // decrement_i
        case 0xc2:
        case 0xc3:
        {
            Value& r = SFR33_REG(op1);
            if (r.ToInt32Value())
                r.AsInt() += ip[0] == 0xc2 ? 1 : -1;
            SFR33_CHECK(ip + 2);
            break;
        }
        case 0xc4: if (sp->ToInt32Value()) sp->AsInt() = -sp->AsInt(); SFR33_CHECK(ip + 1); break;   // negate_i
        case 0xc5: case 0xc6: case 0xc7:   // add_i / subtract_i / multiply_i
        {
            const bool rok = sp->ToInt32Value();
            const SInt32 r = rok ? sp->AsInt() : 0;
            const bool lok = rok && sp[-1].ToInt32Value();
            sp->~Value();
            --sp;
            if (lok)
            {
                if (ip[0] == 0xc5)
                    sp->AsInt() += r;
                else if (ip[0] == 0xc6)
                    sp->AsInt() -= r;
                else
                    sp->AsInt() *= r;
            }
            SFR33_CHECK(ip + 1);
            break;
        }
        case 0xce: Sfr31CallOnObjectArg(vmAddr, op1); SFR33_CALL_TAIL(ip + 2); break;
        case 0xef: pc = ip + 5; break;   // debug
        default: pc = ip + 1; break;
        }
    }
#undef SFR33_REG
#undef SFR33_CALL_TAIL
#undef SFR33_CHECK
}

} // namespace

// The interpreter: runs the top call frame from its CP (the method's traced code from the start when unset), and the
// frames its calls push, until max_stack_depth frames have returned or the call stack is empty. An exception pending
// on entry (or left by a returning frame) goes to the frame's handler; with none the frame is popped and the next
// one down looks for its own. Returns the frames still to run (0 when max_stack_depth returned).
// MS2-FUNCTIONAL 0x1424fa5b0: the opcode switch is a run-frame helper; the opcodes the exe also has out of line call the sfr_as3_19 recoveries instead of their inlined copies
// @0x1424fa5b0
int VM::ExecuteCode(unsigned max_stack_depth)
{
    unsigned depth = max_stack_depth;
    // nothing to run: MovieRoot::Init runs the VM before any frame is pushed
    if (Sfr33CallStack(*this).Size == 0)
        return static_cast<int>(depth);
    for (;;)
    {
        CallFrameStack& cs = Sfr33CallStack(*this);
        CallFrame& cf = Sfr33FrameAt(*this, cs.Size - 1);
        Value saved(ExceptionObj);
        const bool hadEx = HandleException;
        HandleException = false;
        ExceptionObj.SetUndefined();

        const UPInt* const code = Sfr33CallFrameGetCode(cf).GetDataPtr();
        const UPInt* pc = static_cast<const UPInt*>(cf.CP);
        if (pc == NULL)
        {
            pc = code;
            cf.CP = pc;
        }

        Sfr33ExecExit how;
        if (HandleException)
            how = Sfr33ExitLeaveExc;    // tracing the method threw
        else
        {
            how = Sfr33ExitCalled;
            if (hadEx)
            {
                HandleException = true;
                ExceptionObj.Assign(saved);
                if (HandleException)
                {
                    const int h = FUN_142519a00(this, static_cast<UPInt>(pc - code), &cf);
                    if (h < 0)
                        how = Sfr33ExitLeaveExc;
                    else
                        pc = code + h;
                }
            }
            if (how != Sfr33ExitLeaveExc)
                how = Sfr33ExecFrame(*this, cf, pc, cs.Size);
        }

        if (how == Sfr33ExitCalled)
            ++depth;
        else
        {
            if (how == Sfr33ExitLeaveExc && HandleException)
                cf.ClearOpStack();
            cf.~CallFrame();
            --cs.Size;
            if (--depth == 0)
                return 0;
        }
        if (cs.Size == 0)
            return static_cast<int>(depth);
    }
}

}}} // namespace Scaleform::GFx::AS3
