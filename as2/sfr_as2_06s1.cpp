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

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The _global object (sfr_as2_03g, 0x70 bytes); only its constructor is used here.
class GASGlobalObject : public Object
{
public:
    GlobalContext* pContext; // +0x68
    GASGlobalObject(GlobalContext* pcontext); // exe 0x14291c160
};

// MS2-FUNCTIONAL: register allocation differs.
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

// MS2-FUNCTIONAL: register allocation differs.
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

// The 'implements' opcode (ExecutionContext::ImplementsOpCode; the context is not modelled: +0 the environment,
// +0x40 the logger, +0x62 the verbose flag): the constructor on top gets the count interfaces below it added to its
// prototype.
// MS2-FUNCTIONAL: the context is read by address
// @0x14295dbe0
void FUN_14295dbe0(void* pctx)
{
    UByte*        pc      = static_cast<UByte*>(pctx);
    Environment*  penv    = *reinterpret_cast<Environment**>(pc);
    ActionLogger* plog    = reinterpret_cast<ActionLogger*>(pc + 0x40);

    Value ctorVal = penv->Top(0);
    int   count   = penv->Top(1).ToInt32(penv);
    penv->Drop2();
    if (ctorVal.IsFunction())
    {
        FunctionRef ctorFunc = ctorVal.ToFunction(penv);
        if (!ctorFunc.IsNull())
        {
            Value protoVal;
            if (ctorFunc->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_prototype), &protoVal))
            {
                Object* pproto = protoVal.ToObject(penv);
                if (pproto)
                {
                    pproto->AddInterface(penv->GetSC(), count, 0);
                    for (int i = 0; i < count; i++)
                    {
                        Value& intfVal = penv->Top(i);
                        if (intfVal.IsFunction())
                        {
                            FunctionRef intf = intfVal.ToFunction(penv);
                            if (!intf.IsNull())
                                pproto->AddInterface(penv->GetSC(), i, intf.GetObjectPtr());
                        }
                    }
                }
            }
            else if (pc[0x62] & 1)
                plog->LogScriptError("The constructor function in 'implements' should have 'prototype'.");
        }
    }
    else if (pc[0x62] & 1)
        plog->LogScriptError("The parameter of 'implements' should be a function.");

    penv->Drop(count);
}

// The 'instanceof' opcode (ExecutionContext::InstanceOfOpCode; the context is read as in FUN_14295dbe0): whether the
// object below the constructor on top is an instance of it, pushed as a boolean.
// MS2-FUNCTIONAL: the context is read by address
// @0x142962420
void FUN_142962420(void* pctx)
{
    UByte*        pc   = static_cast<UByte*>(pctx);
    Environment*  penv = *reinterpret_cast<Environment**>(pc);
    ActionLogger* plog = reinterpret_cast<ActionLogger*>(pc + 0x40);

    bool   rv      = false;
    Value& objVal  = penv->Top(1);
    Value& ctorVal = penv->Top(0);
    if (ctorVal.IsFunction())
    {
        FunctionRef ctorFunc = ctorVal.ToFunction(penv);
        if (!ctorFunc.IsNull())
        {
            ObjectInterface* pobj = objVal.IsCharacter()
                                        ? static_cast<ObjectInterface*>(objVal.ToAvmCharacter(penv))
                                        : static_cast<ObjectInterface*>(objVal.ToObject(penv));
            if (pobj)
            {
                Value protoVal;
                if (ctorFunc->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_prototype), &protoVal))
                    rv = pobj->InstanceOf(penv, protoVal.ToObject(penv));
                else if (pc[0x62] & 1)
                    plog->LogScriptError("The constructor function in InstanceOf should have 'prototype'.");
            }
        }
    }
    else if (pc[0x62] & 1)
        plog->LogScriptError("The parameter of InstanceOf should be a function.");

    penv->Drop2();
    penv->Push(Value(rv));
}

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

// MS2-FUNCTIONAL: register allocation and block order differ.
// @0x1429674a0
void Disasm::LogDisasm(const unsigned char* pinstructionData)
{
    const int       actionId = pinstructionData[0];
    DisasmInstInfo* pinfo    = 0;
    for (int i = 0;; i++)
    {
        if (DisasmInstTable[i].ActionId == actionId)
            pinfo = &DisasmInstTable[i];
        if (DisasmInstTable[i].ActionId == 0)
            break;
    }

    DisasmArgFormat fmt = ArgHex;
    if (!pinfo)
        LogF("<unknown>[0x%02X]", actionId);
    else
    {
        LogF("%-15s", pinfo->pName);
        fmt = pinfo->ArgFormat;
    }

    if (actionId & 0x80)
    {
        const unsigned char* pdata  = pinstructionData + 3;
        int                  length = pinstructionData[1] | (pinstructionData[2] << 8);

        if (fmt == ArgHex)
        {
            for (int i = 0; i < length; i++)
                LogF(" 0x%02X", pdata[i]);
        }
        else if (fmt == ArgString)
        {
            LogF(" \"");
            for (int i = 0; i < length; i++)
                LogF("%c", pdata[i]);
            LogF("\"\n");
            return;
        }
        else if (fmt == ArgU8)
        {
            LogF(" %d\n", pdata[0]);
            return;
        }
        else if (fmt == ArgU16)
        {
            LogF(" %d\n", pdata[0] | (pdata[1] << 8));
            return;
        }
        else if (fmt == ArgS16)
        {
            int val = pdata[0] | (pdata[1] << 8);
            if (val & 0x8000)
                val |= 0xFFFF8000;
            LogF(" %d\n", val);
            return;
        }
        else if (fmt == ArgPushData)
        {
            LogF("\n");
            int i = 0;
            while (i < length)
            {
                int type = pdata[i];
                i++;
                LogF("\t\t");
                if (type == 0)
                {
                    LogF("\"");
                    while (pdata[i] != 0)
                    {
                        LogF("%c", pdata[i]);
                        i++;
                    }
                    i++;
                    LogF("\"\n");
                }
                else if (type == 1)
                {
                    float f;
                    memcpy(&f, pdata + i, sizeof(f));
                    i += 4;
                    LogF("(float) %f\n", f);
                }
                else if (type == 2)
                    LogF("NULL\n");
                else if (type == 3)
                    LogF("undef\n");
                else if (type == 4)
                {
                    int reg = pdata[i];
                    i++;
                    LogF("reg[%d]\n", reg);
                }
                else if (type == 5)
                {
                    int b = pdata[i];
                    i++;
                    LogF("bool(%d)\n", b);
                }
                else if (type == 6)
                {
                    // The two 32-bit halves are stored high word first.
                    union { double D; UInt32 I[2]; } u;
                    memcpy(&u.I[1], pdata + i, 4);
                    memcpy(&u.I[0], pdata + i + 4, 4);
                    i += 8;
                    LogF("(double) %f\n", u.D);
                }
                else if (type == 7)
                {
                    int val = pdata[i] | (pdata[i + 1] << 8) | (pdata[i + 2] << 16) | (pdata[i + 3] << 24);
                    i += 4;
                    LogF("(int) %d\n", val);
                }
                else if (type == 8)
                {
                    int id = pdata[i];
                    i++;
                    LogF("DictLookup[%d]\n", id);
                }
                else if (type == 9)
                {
                    int id = pdata[i] | (pdata[i + 1] << 8);
                    i += 2;
                    LogF("DictLookupLg[%d]\n", id);
                }
            }
            return;
        }
        else if (fmt == ArgDeclDict)
        {
            int count = pdata[0] | (pdata[1] << 8);
            LogF(" [%d]\n", count);
            int i = 2;
            for (int ct = 0; ct < count; ct++)
            {
                LogF("\t\t");
                LogF("\"");
                while (pdata[i] != 0)
                {
                    if (i >= length)
                    {
                        LogF("<disasm error -- length exceeded>\n");
                        break;
                    }
                    LogF("%c", pdata[i]);
                    i++;
                }
                LogF("\"\n");
                i++;
            }
            return;
        }
        else if (fmt == ArgFunction2)
        {
            const char* pname   = (const char*)pdata;
            int         i       = (int)strlen(pname);
            int         nargs   = pdata[i + 1] | (pdata[i + 2] << 8);
            int         nregs   = pdata[i + 3];
            UInt16      flags   = (UInt16)(pdata[i + 4] | (pdata[i + 5] << 8));
            LogF("\n\t\tname = '%s', ArgCount = %d, RegCount = %d\n", pname, nargs, nregs);
            LogF("\t\t        pg = %d\n\t\t        pp = %d\n\t\t        pr = %d\n"
                 "\t\tss = %d, ps = %d\n\t\tsa = %d, pa = %d\n\t\tst = %d, pt = %d\n",
                 (flags >> 8) & 1, (flags >> 7) & 1, (flags >> 6) & 1, (flags >> 5) & 1, (flags >> 4) & 1,
                 (flags >> 3) & 1, (flags >> 2) & 1, (flags >> 1) & 1, flags & 1);
            i += 6;
            for (int argi = 0; argi < nargs; argi++)
            {
                int         reg      = pdata[i];
                const char* pargName = (const char*)pdata + i + 1;
                i += 1 + (int)strlen(pargName) + 1;
                LogF("\t\targ[%d] - reg[%d] - '%s'\n", argi, reg, pargName);
            }
            LogF("\t\tfunction length = %d\n", pdata[i] | (pdata[i + 1] << 8));
            return;
        }
        else if (fmt == ArgFunction)
        {
            const char* pname = (const char*)pdata;
            int         i     = (int)strlen(pname);
            int         nargs = pdata[i + 1] | (pdata[i + 2] << 8);
            i += 3;
            LogF("\n\t\tname = '%s', ArgCount = %d\n", pname, nargs);
            for (int argi = 0; argi < nargs; argi++)
            {
                const char* pargName = (const char*)pdata + i;
                i += (int)strlen(pargName) + 1;
                LogF("\t\targ[%d] - '%s'\n", argi, pargName);
            }
            LogF("\t\tfunction length = %d\n", pdata[i] | (pdata[i + 1] << 8));
            return;
        }
    }
    LogF("\n");
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
