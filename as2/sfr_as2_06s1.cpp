// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 context and action buffer
// helpers of sfr_as2_06 (gap recovery, lane sfr24): the global context's cleanup, the constant pool, the
// implements/instanceof opcodes and the action disassembler; also three one-instruction gap bodies (the TextField
// global constructor, the ObjectInterface instanceof default, FunctionObject::IsCFunction).
// MS2-UNIT: sfr_as2_06s1
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14296f3d0-0x14296f634 .text$mn
// MS2-RANGE: 0x142970210-0x14297044f .text$mn
// MS2-RANGE: 0x142971cc0-0x142971d65 .text$mn
// MS2-RANGE: 0x14295dbe0-0x14295e072 .text$mn
// MS2-RANGE: 0x142962420-0x1429626ca .text$mn
// MS2-RANGE: 0x1429674a0-0x142967b89 .text$mn
// MS2-RANGE: 0x14295ca00-0x14295ca10 .text$mn
// MS2-RANGE: 0x142962410-0x142962420 .text$mn
// MS2-RANGE: 0x142965490-0x1429654a0 .text$mn

#define MS2_SF_HASH_CLEAR_NOINLINE           // HashSet Clear out of line, as the exe's setRawCapacity calls it
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"

// The exe calls the ASString ArrayCC Resize out of line (0x142524390).
template <> void Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString, Scaleform::AllocatorLH<Scaleform::GFx::ASString, 323>, Scaleform::ArrayDefaultPolicy> >::Resize(UPInt);
namespace Scaleform { namespace GFx { namespace AS2 {

// The _global object (sfr_as2_03g, 0x70 bytes); only its constructor is used here.
class GASGlobalObject : public Object
{
public:
    GlobalContext* pContext; // +0x68
    GASGlobalObject(GlobalContext* pcontext); // exe 0x14291c160
};

// @0x14296f3d0
void GlobalContext::PreClean(bool preserveBuiltinProps)
{
    if (preserveBuiltinProps)
    {
        Ptr<Object>     pnewGlobal = *SF_HEAP_NEW(pHeap) GASGlobalObject(this);
        ASStringContext sc(this, 8);
        ASString        playerName   = sc.CreateConstString("gfxPlayer");
        ASString        languageName = sc.CreateConstString("gfxLanguage");
        ASString        argName      = sc.CreateConstString("gfxArg");
        Value           val;
        pGlobal->GetMemberRaw(&sc, playerName, &val);
        pnewGlobal->SetMemberRaw(&sc, playerName, val);
        pGlobal->GetMemberRaw(&sc, languageName, &val);
        pnewGlobal->SetMemberRaw(&sc, languageName, val);
        pGlobal->GetMemberRaw(&sc, argName, &val);
        pnewGlobal->SetMemberRaw(&sc, argName, val);
        pGlobal = pnewGlobal;
    }
    else
        pGlobal = 0;
    RegisteredClasses.Clear();
    BuiltinClassesRegistry.Clear();
    Prototypes.Clear();
    pMovieRoot = 0;
}

// @0x142970210
void ActionBuffer::ProcessDeclDict(ASStringContext* psc, unsigned startPc, unsigned stopPc, ActionLogger& log)
{
    const UByte* pbuffer = pBufferData->GetBufferPtr();
    if (DeclDictProcessedAt == (int)startPc)
        return;
    if (DeclDictProcessedAt != -1)
    {
        if (log.IsVerboseActionErrors())
            log.LogScriptError("ProcessDeclDict(%d, %d) - DeclDict was already processed at %d", startPc, stopPc,
                               DeclDictProcessedAt);
        return;
    }

    DeclDictProcessedAt = startPc;
    // The action header is 3 bytes (code, length); the pool starts with its 16-bit entry count.
    unsigned i      = startPc;
    unsigned length = pbuffer[3 + i] | (pbuffer[3 + i + 1] << 8);
    i += 2;
    Dictionary.Resize(length);

    unsigned ct;
    for (ct = 0; ct < length; ct++)
    {
        Dictionary[ct] = psc->CreateString((const char*)&pbuffer[3 + i]);
        while (pbuffer[3 + i])
        {
            if (i >= stopPc)
            {
                if (log.IsVerboseActionErrors())
                    log.LogScriptError("Action buffer dict length exceeded");
                for (; ct < length; ct++)
                    Dictionary[ct] = psc->CreateString("<invalid>");
                return;
            }
            i++;
        }
        i++;
    }
}

// The with stack of an execution context, made on its first with(): the heap and the array (0x10 bytes).
struct WithStackRef
{
    MemoryHeap*     pHeap;  // +0x00
    WithStackArray* pStack; // +0x08
};

// Pushes a with() scope, creating the array first.
// @0x142971cc0
void FUN_142971cc0(WithStackRef* pwith, const WithStackEntry& entry)
{
    if (!pwith->pStack)
        pwith->pStack = SF_HEAP_NEW(pwith->pHeap) WithStackArray();
    pwith->pStack->PushBack(entry);
}

// The ToFunction copy with SetLocalFrame expanded in place, as the exe inlines it into the instanceof opcode (the
// same expansion as sfr_as2_05j's, under this unit's own tag).
struct SetLocalFrameInlineTag06 {};
static SF_FORCEINLINE void FunctionRefSetLocalFrame06(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
{
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->Release();
    p->pLocalFrame = localFrame;
    if (weakRef)
        p->Flags |= FunctionRefBase::FuncRef_Weak;
    else
        p->Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->AddRef();
}
template<>
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, SetLocalFrameInlineTag06)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        FunctionRefSetLocalFrame06(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}
struct ValueAccess06 : Value
{
    using Value::ResolveFunctionName;
};
static SF_FORCEINLINE FunctionRef ValueToFunction06(const Value& v, const Environment* penv)
{
    switch (v.GetType())
    {
    case Value::FUNCTION:
        return FunctionRef(v.V.FunctionValue, SetLocalFrameInlineTag06());
    case Value::FUNCTIONNAME:
        return static_cast<const ValueAccess06&>(v).ResolveFunctionName(penv);
    }
    return FunctionRef();
}

// RefCountBaseGC::AddRef as one read-modify-write of RefCount (+0x18): the exe loads, increments, clears the state
// bits and stores in the implements opcode.
static SF_FORCEINLINE void AddRefGC06(void* p)
{
    UInt32& rc = *reinterpret_cast<UInt32*>(static_cast<char*>(p) + 0x18);
    rc = (rc + 1) & 0x8fffffffu;
}
static SF_FORCEINLINE void ImplementsSetLocalFrame06(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
{
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->Release();
    p->pLocalFrame = localFrame;
    if (weakRef)
        p->Flags |= FunctionRefBase::FuncRef_Weak;
    else
        p->Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        AddRefGC06(p->pLocalFrame);
}

// Value::ToFunction as the exe inlines it into the implements opcode: the result is built in place.
struct ImplementsFuncRef06 : FunctionRefBase
{
    SF_FORCEINLINE ImplementsFuncRef06(const Value& v, const Environment* penv)
    {
        switch (v.T.Type)
        {
        case Value::FUNCTIONNAME:
            ::new (static_cast<void*>(this)) FunctionRef(static_cast<const ValueAccess06&>(v).ResolveFunctionName(penv));
            return;
        case Value::FUNCTION:
            Flags    = 0;
            Function = v.V.FunctionValue.Function;
            if (Function)
                AddRefGC06(Function);
            pLocalFrame = 0;
            if (v.V.FunctionValue.pLocalFrame)
                ImplementsSetLocalFrame06(this, v.V.FunctionValue.pLocalFrame,
                                          (v.V.FunctionValue.Flags & FuncRef_Weak) != 0);
            return;
        default:;
        }
        Init((FunctionObject*)0);
    }
    SF_FORCEINLINE ~ImplementsFuncRef06() { DropRefs(); }
};

// ExecutionContext (local to the SDK's AS2_Action.cpp) as far as the opcodes use it.
struct ExecutionContextView06
{
    Environment* const       pEnv;            // +0x00
    InteractiveObject* const pOriginalTarget; // +0x08
    const UByte* const       pBuffer;         // +0x10
    ActionLogger*            pPrevLog;        // +0x18
    int                      StopPC;          // +0x20
    int                      NextPC;          // +0x24
    int                      PC;              // +0x28
    WithStackRef             WithStack;       // +0x30
    ActionLogger             LogF;            // +0x40
    UInt8                    Version;         // +0x60
    UInt8                    ExecType;        // +0x61
    bool                     VerboseActionErrors : 1; // +0x62
    bool                     VerboseAction       : 1;
    bool                     IsFunction2         : 1;
};

// PagedStack::Top1 as in the SDK: the element below the top, or the previous page's top.
static SF_FORCEINLINE Value* StackTop1_06s1(PagedStack<Value, 32>& s)
{
    return (s.pCurrent > s.pPageStart) ? (s.pCurrent - 1) : s.pPrevPageTop;
}

// The 'implements' opcode (ExecutionContext::ImplementsOpCode, SDK body over the ExecutionContextView06 layout): the
// constructor on top gets the count interfaces below it added to its prototype.
// MS2-FUNCTIONAL: 1165 vs 1170 bytes; the exe keeps ctorFuncVal's type byte in edi (saved in the prolog) across the
// Drop calls, as if cl knew Value's copy ctor / DropRefs leave the local alone (cross-TU mod-ref). Ours caches it in
// ctorType before the calls, so it lives in esi and is read before ToInt32 instead of after Drop2
// @0x14295dbe0
void FUN_14295dbe0(void* pctx)
{
    ExecutionContextView06* ctx = static_cast<ExecutionContextView06*>(pctx);

    Value ctorFuncVal(*ctx->pEnv->Stack.Top0());
    UByte ctorType = ctorFuncVal.T.Type;
    int   intfNum = StackTop1_06s1(ctx->pEnv->Stack)->ToInt32(ctx->pEnv);
    ctx->pEnv->Drop2();

    if (ctorType == Value::FUNCTION || ctorType == Value::FUNCTIONNAME)
    {
        ImplementsFuncRef06 ctorFunc(ctorFuncVal, ctx->pEnv);
        if (!ctorFunc.IsNull())
        {
            Value protoVal;
            if (ctorFunc->GetMemberRaw(ctx->pEnv->GetSC(), ctx->pEnv->GetBuiltin(ASBuiltin_prototype), &protoVal))
            {
                Object* proto = protoVal.ToObject(ctx->pEnv);
                if (proto != 0)
                {
                    proto->AddInterface(ctx->pEnv->GetSC(), intfNum, NULL);
                    for (int i = 0; i < intfNum; ++i)
                    {
                        const Value& intfVal = ctx->pEnv->Top(i);
                        if (intfVal.IsFunction())
                        {
                            ImplementsFuncRef06 intfFunc(intfVal, ctx->pEnv);
                            if (!intfFunc.IsNull())
                            {
                                proto->AddInterface(ctx->pEnv->GetSC(), i, intfFunc.GetObjectPtr());
                            }
                        }
                    }
                }
            }
            else
            {
                if (ctx->VerboseActionErrors)
                    ctx->LogF.LogScriptError("The constructor function in 'implements' should have 'prototype'.");
            }
        }
    }
    else
    {
        if (ctx->VerboseActionErrors)
            ctx->LogF.LogScriptError("The parameter of 'implements' should be a function.");
    }
    ctx->pEnv->Drop(intfNum);
}

// The SDK's PagedStack::Top1: the element below the top, on the previous page when the top starts a page.
static SF_FORCEINLINE Value& EnvTop1(Environment* e)
{
    return *((e->Stack.pCurrent > e->Stack.pPageStart) ? (e->Stack.pCurrent - 1) : e->Stack.pPrevPageTop);
}

// The 'instanceof' opcode (ExecutionContext::InstanceOfOpCode; the context is read as in FUN_14295dbe0): whether the
// object below the constructor on top is an instance of it, pushed as a boolean. The environment is re-read from
// the context after each call, and the logger is addressed in place.
// @0x142962420
void FUN_142962420(void* pctx)
{
    UByte*        pc   = static_cast<UByte*>(pctx);
    Environment*& penv = *reinterpret_cast<Environment**>(pc);
#define plog reinterpret_cast<ActionLogger*>(pc + 0x40) // a local pointer costs a callee-saved register

    Value& objVal  = EnvTop1(penv);
    Value& ctorVal = *penv->Stack.Top0();
    bool   rv      = false;
    if (ctorVal.IsFunction())
    {
        FunctionRef ctorFunc = ValueToFunction06(ctorVal, penv);
        if (!ctorFunc.IsNull())
        {
            ObjectInterface* pobj = objVal.IsCharacter()
                                        ? static_cast<ObjectInterface*>(objVal.ToAvmCharacter(penv))
                                        : static_cast<ObjectInterface*>(objVal.ToObject(penv));
            if (pobj)
            {
                Value protoVal;
                if (ctorFunc->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_prototype), &protoVal))
                {
                    Object* pproto = protoVal.ToObject(penv);
                    rv = pobj->InstanceOf(penv, pproto);
                }
                else if (pc[0x62] & 1)
                    plog->LogScriptError("The constructor function in InstanceOf should have 'prototype'.");
            }
        }
    }
    else if (pc[0x62] & 1)
        plog->LogScriptError("The parameter of InstanceOf should be a function.");

    penv->Drop2();
    penv->Push(rv);
}
#undef plog

// The action disassembly writer (declared in sfr_as2_06, same layout): the log and the message type of its lines.
class Disasm
{
public:
    Log*         pLog;    // +0x00
    LogMessageId MsgType; // +0x08

    Disasm(Log* plog, LogMessageId msgType) : pLog(plog), MsgType(msgType) {}

    void LogF(const char* pfmt, ...); // exe 0x142967bf0
    void LogDisasm(const unsigned char* pinstructionData);
};

// How an action's argument block is printed.
enum DisasmArgFormat
{
    ArgNone      = 0,
    ArgString    = 1,
    ArgHex       = 2,
    ArgU8        = 3,
    ArgU16       = 4,
    ArgS16       = 5,
    ArgPushData  = 6,
    ArgDeclDict  = 7,
    ArgFunction  = 8,
    ArgFunction2 = 9
};

struct DisasmInstInfo
{
    int             ActionId;
    const char*     pName;
    DisasmArgFormat ArgFormat;
};

// The opcode table (exe 0x143a52120), ended by action 0.
static DisasmInstInfo DisasmInstTable[] =
{
    { 0x04, "next_frame",       ArgNone },
    { 0x05, "prev_frame",       ArgNone },
    { 0x06, "play",             ArgNone },
    { 0x07, "stop",             ArgNone },
    { 0x08, "toggle_qlty",      ArgNone },
    { 0x09, "stop_sounds",      ArgNone },
    { 0x0A, "add",              ArgNone },
    { 0x0B, "sub",              ArgNone },
    { 0x0C, "mul",              ArgNone },
    { 0x0D, "div",              ArgNone },
    { 0x0E, "equ",              ArgNone },
    { 0x0F, "lt",               ArgNone },
    { 0x10, "and",              ArgNone },
    { 0x11, "or",               ArgNone },
    { 0x12, "not",              ArgNone },
    { 0x13, "str_eq",           ArgNone },
    { 0x14, "str_len",          ArgNone },
    { 0x15, "substr",           ArgNone },
    { 0x17, "pop",              ArgNone },
    { 0x18, "floor",            ArgNone },
    { 0x1C, "get_var",          ArgNone },
    { 0x1D, "set_var",          ArgNone },
    { 0x20, "set_target2",      ArgNone },
    { 0x21, "str_cat",          ArgNone },
    { 0x22, "get_prop",         ArgNone },
    { 0x23, "set_prop",         ArgNone },
    { 0x24, "dup_sprite",       ArgNone },
    { 0x25, "rem_sprite",       ArgNone },
    { 0x26, "trace",            ArgNone },
    { 0x27, "start_drag",       ArgNone },
    { 0x28, "stop_drag",        ArgNone },
    { 0x29, "str_lt",           ArgNone },
    { 0x2A, "throw",            ArgNone },
    { 0x2B, "cast_object",      ArgNone },
    { 0x2C, "implements",       ArgNone },
    { 0x30, "random",           ArgNone },
    { 0x31, "mb_length",        ArgNone },
    { 0x32, "ord",              ArgNone },
    { 0x33, "chr",              ArgNone },
    { 0x34, "get_timer",        ArgNone },
    { 0x35, "substr_mb",        ArgNone },
    { 0x36, "ord_mb",           ArgNone },
    { 0x37, "chr_mb",           ArgNone },
    { 0x3A, "delete",           ArgNone },
    { 0x3B, "delete2",          ArgString },
    { 0x3C, "set_local",        ArgNone },
    { 0x3D, "call_func",        ArgNone },
    { 0x3E, "return",           ArgNone },
    { 0x3F, "mod",              ArgNone },
    { 0x40, "new",              ArgNone },
    { 0x41, "decl_local",       ArgNone },
    { 0x42, "decl_array",       ArgNone },
    { 0x43, "decl_obj",         ArgNone },
    { 0x44, "type_of",          ArgNone },
    { 0x45, "get_target",       ArgNone },
    { 0x46, "enumerate",        ArgNone },
    { 0x47, "add_t",            ArgNone },
    { 0x48, "lt_t",             ArgNone },
    { 0x49, "eq_t",             ArgNone },
    { 0x4A, "number",           ArgNone },
    { 0x4B, "string",           ArgNone },
    { 0x4C, "dup",              ArgNone },
    { 0x4D, "swap",             ArgNone },
    { 0x4E, "get_member",       ArgNone },
    { 0x4F, "set_member",       ArgNone },
    { 0x50, "inc",              ArgNone },
    { 0x51, "dec",              ArgNone },
    { 0x52, "call_method",      ArgNone },
    { 0x53, "new_method",       ArgNone },
    { 0x54, "is_inst_of",       ArgNone },
    { 0x55, "enum_object",      ArgNone },
    { 0x60, "bit_and",          ArgNone },
    { 0x61, "bit_or",           ArgNone },
    { 0x62, "bit_xor",          ArgNone },
    { 0x63, "shl",              ArgNone },
    { 0x64, "asr",              ArgNone },
    { 0x65, "lsr",              ArgNone },
    { 0x66, "eq_strict",        ArgNone },
    { 0x67, "gt_t",             ArgNone },
    { 0x68, "gt_str",           ArgNone },
    { 0x69, "extends",          ArgNone },
    { 0x81, "goto_frame",       ArgU16 },
    { 0x83, "get_url",          ArgString },
    { 0x87, "store_register",   ArgU8 },
    { 0x88, "decl_dict",        ArgDeclDict },
    { 0x8A, "wait_for_frame",   ArgHex },
    { 0x8B, "set_target",       ArgString },
    { 0x8C, "goto_frame_lbl",   ArgString },
    { 0x8D, "wait_for_fr_exp",  ArgHex },
    { 0x8E, "function2",        ArgFunction2 },
    { 0x8F, "try",              ArgHex },
    { 0x94, "with",             ArgU16 },
    { 0x96, "push_data",        ArgPushData },
    { 0x99, "goto",             ArgS16 },
    { 0x9A, "get_url2",         ArgHex },
    { 0x9B, "function",         ArgFunction },
    { 0x9D, "branch_if_true",   ArgS16 },
    { 0x9E, "call_frame",       ArgHex },
    { 0x9F, "goto_frame_exp",   ArgHex },
    { 0x00, "<end>",            ArgNone },
};

// @0x1429674a0
void Disasm::LogDisasm(const unsigned char* InstructionData)
{
    int             actionId = InstructionData[0];
    DisasmInstInfo* info     = 0;

    for (int i = 0;; i++)
    {
        if (DisasmInstTable[i].ActionId == actionId)
        {
            info = &DisasmInstTable[i];
        }
        if (DisasmInstTable[i].ActionId == 0)
        {
            break;
        }
    }

    DisasmArgFormat fmt = ArgHex;
    if (info == 0)
    {
        LogF("<unknown>[0x%02X]", actionId);
    }
    else
    {
        LogF("%-15s", info->pName);
        fmt = info->ArgFormat;
    }

    if (actionId & 0x80)
    {
        int length = InstructionData[1] | (InstructionData[2] << 8);

        if (fmt == ArgHex)
        {
            for (int i = 0; i < length; i++)
            {
                LogF(" 0x%02X", InstructionData[3 + i]);
            }
            LogF("\n");
        }
        else if (fmt == ArgString)
        {
            LogF(" \"");
            for (int i = 0; i < length; i++)
            {
                LogF("%c", InstructionData[3 + i]);
            }
            LogF("\"\n");
        }
        else if (fmt == ArgU8)
        {
            int val = InstructionData[3];
            LogF(" %d\n", val);
        }
        else if (fmt == ArgU16)
        {
            int val = InstructionData[3] | (InstructionData[4] << 8);
            LogF(" %d\n", val);
        }
        else if (fmt == ArgS16)
        {
            int val = InstructionData[3] | (InstructionData[4] << 8);
            if (val & 0x8000) val |= ~0x7FFF;
            LogF(" %d\n", val);
        }
        else if (fmt == ArgPushData)
        {
            LogF("\n");
            int i = 0;
            while (i < length)
            {
                int type = InstructionData[3 + i];
                i++;
                LogF("\t\t");
                if (type == 0)
                {
                    LogF("\"");
                    while (InstructionData[3 + i])
                    {
                        LogF("%c", InstructionData[3 + i]);
                        i++;
                    }
                    i++;
                    LogF("\"\n");
                }
                else if (type == 1)
                {
                    union
                    {
                        float  F;
                        UInt32 I;
                    } u;
                    memcpy(&u.I, InstructionData + 3 + i, 4);
                    i += 4;
                    LogF("(float) %f\n", u.F);
                }
                else if (type == 2)
                {
                    LogF("NULL\n");
                }
                else if (type == 3)
                {
                    LogF("undef\n");
                }
                else if (type == 4)
                {
                    int reg = InstructionData[3 + i];
                    i++;
                    LogF("reg[%d]\n", reg);
                }
                else if (type == 5)
                {
                    int boolVal = InstructionData[3 + i];
                    i++;
                    LogF("bool(%d)\n", boolVal);
                }
                else if (type == 6)
                {
                    // The two 32-bit halves are stored high word first.
                    union
                    {
                        double D;
                        UInt64 I;
                        struct
                        {
                            UInt32 Lo;
                            UInt32 Hi;
                        } Sub;
                    } u;
                    memcpy(&u.Sub.Hi, InstructionData + 3 + i, 4);
                    memcpy(&u.Sub.Lo, InstructionData + 3 + i + 4, 4);
                    i += 8;
                    LogF("(double) %f\n", u.D);
                }
                else if (type == 7)
                {
                    SInt32 val = InstructionData[3 + i] | (InstructionData[3 + i + 1] << 8) |
                                 (InstructionData[3 + i + 2] << 16) | (InstructionData[3 + i + 3] << 24);
                    i += 4;
                    LogF("(int) %d\n", val);
                }
                else if (type == 8)
                {
                    int id = InstructionData[3 + i];
                    i++;
                    LogF("DictLookup[%d]\n", id);
                }
                else if (type == 9)
                {
                    int id = InstructionData[3 + i] | (InstructionData[3 + i + 1] << 8);
                    i += 2;
                    LogF("DictLookupLg[%d]\n", id);
                }
            }
        }
        else if (fmt == ArgDeclDict)
        {
            int i     = 0;
            int count = InstructionData[3 + i] | (InstructionData[3 + i + 1] << 8);
            i += 2;

            LogF(" [%d]\n", count);

            for (int ct = 0; ct < count; ct++)
            {
                LogF("\t\t");
                LogF("\"");
                while (InstructionData[3 + i])
                {
                    if (i >= length)
                    {
                        LogF("<disasm error -- length exceeded>\n");
                        break;
                    }
                    LogF("%c", InstructionData[3 + i]);
                    i++;
                }
                LogF("\"\n");
                i++;
            }
        }
        else if (fmt == ArgFunction2)
        {
            int         i            = 0;
            const char* functionName = (const char*)&InstructionData[3 + i];
            i += (int)strlen(functionName) + 1;

            int argCount = InstructionData[3 + i] | (InstructionData[3 + i + 1] << 8);
            i += 2;

            int regCount = InstructionData[3 + i];
            i++;

            LogF("\n\t\tname = '%s', ArgCount = %d, RegCount = %d\n", functionName, argCount, regCount);

            UInt16 flags = (InstructionData[3 + i]) | (InstructionData[3 + i + 1] << 8);
            i += 2;

            bool preloadGlobal = (flags & 0x100) != 0;
            bool preloadParent = (flags & 0x80) != 0;
            bool preloadRoot   = (flags & 0x40) != 0;
            bool suppressSuper = (flags & 0x20) != 0;
            bool preloadSuper  = (flags & 0x10) != 0;
            bool suppressArgs  = (flags & 0x08) != 0;
            bool preloadArgs   = (flags & 0x04) != 0;
            bool suppressThis  = (flags & 0x02) != 0;
            bool preloadThis   = (flags & 0x01) != 0;

            LogF("\t\t        pg = %d\n"
                 "\t\t        pp = %d\n"
                 "\t\t        pr = %d\n"
                 "\t\tss = %d, ps = %d\n"
                 "\t\tsa = %d, pa = %d\n"
                 "\t\tst = %d, pt = %d\n",
                 int(preloadGlobal), int(preloadParent), int(preloadRoot), int(suppressSuper), int(preloadSuper),
                 int(suppressArgs), int(preloadArgs), int(suppressThis), int(preloadThis));

            for (int argi = 0; argi < argCount; argi++)
            {
                int argRegister = InstructionData[3 + i];
                i++;
                const char* argName = (const char*)&InstructionData[3 + i];
                i += (int)strlen(argName) + 1;

                LogF("\t\targ[%d] - reg[%d] - '%s'\n", argi, argRegister, argName);
            }

            int functionLength = InstructionData[3 + i] | (InstructionData[3 + i + 1] << 8);
            i += 2;

            LogF("\t\tfunction length = %d\n", functionLength);
        }
        else if (fmt == ArgFunction)
        {
            int         i            = 0;
            const char* functionName = (const char*)&InstructionData[3 + i];
            i += (int)strlen(functionName) + 1;

            int argCount = InstructionData[3 + i] | (InstructionData[3 + i + 1] << 8);
            i += 2;

            LogF("\n\t\tname = '%s', ArgCount = %d\n", functionName, argCount);

            for (int argi = 0; argi < argCount; argi++)
            {
                const char* argName = (const char*)&InstructionData[3 + i];
                i += (int)strlen(argName) + 1;

                LogF("\t\targ[%d] - '%s'\n", argi, argName);
            }

            int functionLength = InstructionData[3 + i] | (InstructionData[3 + i + 1] << 8);
            i += 2;

            LogF("\t\tfunction length = %d\n", functionLength);
        }
    }
    else
    {
        LogF("\n");
    }
}

// `new TextField()` makes nothing (text fields come from createTextField only).
// @0x14295ca00
void TextFieldCtorFunction::GlobalCtor(const FnCall&)
{
}

// A plain object interface has no prototype chain to search.
// @0x142962410
bool ObjectInterface::InstanceOf(Environment*, const Object*, bool) const
{
    return false;
}

// @0x142965490
bool FunctionObject::IsCFunction() const
{
    return false;
}

}}} // namespace Scaleform::GFx::AS2
