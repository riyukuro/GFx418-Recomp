// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// the action interpreter, ActionBuffer::Execute. The opcode handlers the exe keeps out of line (set target, start
// drag, cast, implements, enumerate, instanceof, extends, wait for frame, the function definitions) are in sfr_as2_04p,
// 05m, 05t, 06s1, 06z2 and 07o; they take the execution context by address.
// MS2-UNIT: sfr_as2_05y
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142939e60-0x14293f98a .text$mn
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7?$LogBase@VActionLogger@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b5018

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieslots.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/kernel/sf_array.h"

namespace Scaleform { namespace GFx { namespace AS2 {

void GAS_GlobalTrace(const FnCall& fn); // sfr_as2_01

// The with stack of the context: a copy of the caller's, made on first use (the WithStackRef of sfr_as2_06s1).
struct WithStackRef
{
    MemoryHeap*     pHeap;  // +0x00
    WithStackArray* pStack; // +0x08
};

// The out-of-line opcode handlers; pctx is the ExecContext below.
void FUN_14298bb90(void* pctx);                                  // set target (tellTarget)
void FUN_14298fea0(void* pctx);                                  // startDrag
void FUN_142932d20(void* pctx);                                  // cast
void FUN_14295dbe0(void* pctx);                                  // implements
void FUN_142939920(void* pctx, int actionId);                    // enumerate / enumerate2
void FUN_142962420(void* pctx);                                  // instanceof
void FUN_142941680(void* pctx);                                  // extends
void FUN_142994a10(void* pctx, ActionBuffer* pbuf, int actionId); // wait for frame / wait for frame 2
void FUN_142946390(void* pctx, ActionBuffer* pactions);          // function2
void FUN_142945da0(void* pctx, ActionBuffer* pactions);          // function
void FUN_142971cc0(WithStackRef* pwith, const WithStackEntry& entry); // with: push a scope

// The action disassembly writer (sfr_as2_06s1).
class Disasm
{
public:
    Log*         pLog;    // +0x00
    LogMessageId MsgType; // +0x08

    Disasm(Log* plog, LogMessageId msgType) : pLog(plog), MsgType(msgType) {}
    void LogDisasm(const unsigned char* pinstructionData);
};

namespace {

// The state of one Execute run the handlers share (on the exe's stack, 0x68 bytes).
struct ExecContext
{
    Environment*       pEnv;            // +0x00
    InteractiveObject* pOriginalTarget; // +0x08
    const UByte*       pBuffer;         // +0x10
    ActionLogger*      pPrevLog;        // +0x18 the environment's logger, put back at the end
    int                StopPC;          // +0x20
    int                NextPC;          // +0x24
    int                PC;              // +0x28
    WithStackRef       WithStack;       // +0x30
    ActionLogger       LogF;            // +0x40
    UInt8              Version;         // +0x60 SWF version of the target
    UInt8              ExecType;        // +0x61
    bool               VerboseActionErrors : 1; // +0x62
    bool               VerboseAction       : 1;
    bool               IsFunction2         : 1;

    ExecContext(Environment* penv, const WithStackArray* pinitialWithStack, int execType, const UByte* pbuffer)
        : pEnv(penv), pOriginalTarget(penv->GetTarget()), pBuffer(pbuffer), LogF(penv->GetTarget(), 0)
    {
        WithStack.pHeap  = penv->GetHeap();
        WithStack.pStack = pinitialWithStack ? SF_HEAP_NEW(WithStack.pHeap) WithStackArray(*pinitialWithStack) : 0;
        pPrevLog            = penv->pASLogger;
        Version             = (UInt8)penv->GetTarget()->GetVersion();
        ExecType            = (UInt8)execType;
        IsFunction2         = execType == ActionBuffer::Exec_Function2;
        VerboseAction       = LogF.IsVerboseAction();
        VerboseActionErrors = LogF.IsVerboseActionErrors();
    }
    ~ExecContext()
    {
        pEnv->pASLogger = pPrevLog;
        if (WithStack.pStack)
            delete WithStack.pStack;
    }

    const WithStackArray* GetWithStack() const { return WithStack.pStack; }

    // The action at pc in the action log ("EX: pc" and its disassembly).
    void LogOp(int pc)
    {
        LogF.LogAction("EX: %4.4X\t", pc);
        if (LogF.GetLog() && LogF.IsVerboseAction())
        {
            Disasm da(LogF.GetLog(), (LogMessageId)Log_Action);
            da.LogDisasm(&pBuffer[pc]);
        }
    }
};
static_assert(offsetof(ExecContext, StopPC) == 0x20, "ExecContext::StopPC");
static_assert(offsetof(ExecContext, WithStack) == 0x30, "ExecContext::WithStack");
static_assert(offsetof(ExecContext, LogF) == 0x40, "ExecContext::LogF");
static_assert(offsetof(ExecContext, Version) == 0x60, "ExecContext::Version");
static_assert(sizeof(ExecContext) == 0x68, "ExecContext size");

// Builtin string indexes of the exe's table (the header enum lacks them).
enum
{
    B_undefined     = 51,
    B_null          = 52,
    B_string        = 55,
    B_number        = 56,
    B_boolean       = 57,
    B_movieclip     = 58,
    B_object        = 59,
    B_function      = 60,
    B_NaN           = 74,
    B_Infinity      = 75,
    B_MinusInfinity = 76
};

// The value below the top.
inline Value& Top1(Environment* env) { return env->Top(1); }

// Pops three values.
inline void Drop3(Environment* env)
{
    env->Drop2();
    env->Drop1();
}

// The 16-bit little-endian operand at p.
inline int ReadU16(const UByte* p) { return p[0] | (p[1] << 8); }
inline int ReadS16(const UByte* p) { return (SInt16)(UInt16)(p[0] | (p[1] << 8)); }

// The movie stops dragging (MovieImpl::StopDrag: the dragged character is cleared).
inline void StopDragOf(MovieImpl* pmovie)
{
#ifdef SF_GFX_PLAYERIMPL
    pmovie->CurrentDragState.pCharacter = 0;
#else
    pmovie->pKeepAdvancingChar = 0;
#endif
}

// The name path of a character object for the error log, or null for other objects.
inline const char* CharNamePath(ObjectInterface* piobj)
{
    if (!piobj || !piobj->IsASCharacter())
        return 0;
    return piobj->ToCharacter()->GetCharacterHandle()->NamePath.ToCStr();
}

// Logs "fmtChar" with the character's path and the name, or "fmtPlain" with the name alone.
inline void LogMemberError(ActionLogger& log, ObjectInterface* piobj, const char* fmtChar, const char* fmtPlain,
                           const ASString& name)
{
    if (const char* path = CharNamePath(piobj))
        log.LogScriptError(fmtChar, path, name.ToCStr());
    else
        log.LogScriptError(fmtPlain, name.ToCStr());
}

// FSCommandHandler as the movie holds it: the host callback is the first virtual after the destructor.
class FsCommandView : public RefCountBase<FsCommandView, Stat_Default_Mem>
{
public:
    virtual void Callback(MovieImpl* pmovie, const char* pcommand, const char* parg) = 0;
};

inline FsCommandView* FsCommandHandlerOf(MovieImpl* pmovie)
{
    return static_cast<FsCommandView*>(pmovie->pFSCommandHandler);
}

// The register store / push trace: "fmt" with the register and the value on top, the object address if any.
inline void LogRegister(ActionLogger& log, Environment* env, const char* fmt, int reg)
{
    const Value& top = env->Top(0);
    ASString     str = top.ToDebugString(env);
    log.LogAction(fmt, reg, str.ToCStr());
    if (ObjectInterface* piobj = top.ToObjectInterface(env))
        log.LogAction(" at %p", piobj);
    log.LogAction("\n");
}

} // namespace

// Runs the actions from startPc for execBytes bytes (at most to the end of the buffer). Simple actions (below 0x80)
// are one byte; the others carry a 16-bit length and their data. "finally" blocks of the try blocks still open at the
// end run before returning; retval gets the value of a return action.
// MS2-FUNCTIONAL: the stack, value and string helpers are the inlined ones of the exe; the with stack copy is made
// inline (the exe calls its out-of-line copy, 0x142924090); the context is a layout view the handlers read;
// the target restores call SetTarget / SetInvalidTarget (the exe inlines the target, flag and version stores); the
// FSCommand handler is reached through a slot view of the movie's handler pointer
// @0x142939e60
void ActionBuffer::Execute(Environment* env, int startPc, int execBytes, Value* retval,
                           const WithStackArray* pinitialWithStack, ExecuteType execType)
{
    if (env->NeedTermination(execType))
        return;
    int tryCount = 0;
    ++env->ExecutionNestingLevel;

    ExecContext ctx(env, pinitialWithStack, execType, pBufferData->GetBufferPtr());
    const bool  isOriginalTargetValid = !env->IsInvalidTarget;

    if (ctx.VerboseAction)
        ctx.LogF.LogAction("\n");

    const int bufferLen = (int)pBufferData->GetLength();
    ctx.StopPC = startPc + (execBytes < bufferLen ? execBytes : bufferLen);
    ctx.NextPC = startPc;
    ctx.PC     = startPc;

    Ptr<Object> pobj;

    while (ctx.PC < ctx.StopPC)
    {
        // with blocks the pc has left end here
        if (WithStackArray* pwith = ctx.WithStack.pStack)
        {
            UPInt n = pwith->GetSize(), expired = 0;
            while (expired < n && ctx.PC >= (int)(*pwith)[n - 1 - expired].BlockEndPc)
                ++expired;
            if (expired > 0)
                pwith->Resize(n - expired);
        }

        const int actionId = ctx.pBuffer[ctx.PC];

        if ((actionId & 0x80) == 0)
        {
            ctx.NextPC = ctx.PC + 1;
            if (ctx.VerboseAction)
                ctx.LogOp(ctx.PC);

            switch (actionId)
            {
            default:
                break;

            case 0x00: // end: a normal end, the finally blocks have run
                ctx.NextPC = ctx.StopPC;
                tryCount   = 0;
                break;

            case 0x04: // nextFrame
                if (!env->IsInvalidTarget)
                    env->GetTarget()->GotoFrame(env->GetTarget()->GetCurrentFrame() + 1);
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;

            case 0x05: // prevFrame
                if (!env->IsInvalidTarget)
                    env->GetTarget()->GotoFrame(env->GetTarget()->GetCurrentFrame() - 1);
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;

            case 0x06: // play
                if (!env->IsInvalidTarget)
                    env->GetTarget()->SetPlayState(State_Playing);
                break;

            case 0x07: // stop
                if (!env->IsInvalidTarget)
                    env->GetTarget()->SetPlayState(State_Stopped);
                break;

            case 0x08: // toggleQuality: nothing
                break;

            case 0x09: // stopAllSounds
                if (MovieRoot* proot = env->GetAS2Root())
                {
                    if (Sprite* plevel0 = proot->GetLevelMovie(0))
                        plevel0->StopActiveSounds();
                }
                break;

            case 0x0A: // add (numeric)
                Top1(env).Add(env, env->Top(0));
                env->Drop1();
                break;

            case 0x0B: // subtract
                Top1(env).Sub(env, env->Top(0));
                env->Drop1();
                break;

            case 0x0C: // multiply
                Top1(env).Mul(env, env->Top(0));
                env->Drop1();
                break;

            case 0x0D: // divide
                Top1(env).Div(env, env->Top(0));
                env->Drop1();
                break;

            case 0x0E: // equals (SWF 4)
                Top1(env).SetBool(Top1(env).IsEqual(env, env->Top(0)));
                env->Drop1();
                break;

            case 0x0F: // less
            case 0x48: // less2
            {
                Value cmp = Top1(env).Compare(env, env->Top(0), -1);
                Top1(env) = cmp;
                env->Drop1();
                break;
            }

            case 0x10: // and
                Top1(env).SetBool(Top1(env).ToBool(env) && env->Top(0).ToBool(env));
                env->Drop1();
                break;

            case 0x11: // or
                Top1(env).SetBool(Top1(env).ToBool(env) || env->Top(0).ToBool(env));
                env->Drop1();
                break;

            case 0x12: // not; booleans and undefined directly
            {
                Value& v = env->Top(0);
                if (v.GetType() == Value::BOOLEAN)
                    v.V.BooleanValue = !v.V.BooleanValue;
                else if (v.IsUndefined())
                {
                    v.T.Type         = Value::BOOLEAN;
                    v.V.BooleanValue = true;
                }
                else
                    v.SetBool(!v.ToBool(env));
                break;
            }

            case 0x13: // string equals
            {
                ASString a = Top1(env).ToStringVersioned(env, ctx.Version);
                ASString b = env->Top(0).ToStringVersioned(env, ctx.Version);
                Top1(env).SetBool(a == b);
                env->Drop1();
                break;
            }

            case 0x14: // string length
            case 0x31: // mb string length
            {
                ASString s = env->Top(0).ToStringVersioned(env, ctx.Version);
                env->Top(0).SetInt((int)s.GetLength());
                break;
            }

            case 0x15: // substring(s, index (1-based), count)
            {
                ASString s   = env->Top(2).ToStringVersioned(env, ctx.Version);
                ASString sub = StringProto::StringSubstring(s, Top1(env).ToInt32(env) - 1, env->Top(0).ToInt32(env));
                env->Drop2();
                env->Top(0).SetString(sub);
                break;
            }

            case 0x17: // pop
                env->Drop1();
                break;

            case 0x18: // int
                env->Top(0).SetInt(env->Top(0).ToInt32(env));
                break;

            case 0x1C: // get variable; NaN, Infinity and -Infinity are names here (case-insensitive before SWF 7)
            {
                Value&   var  = env->Top(0);
                ASString name = var.ToString(env);
                int      special = -1;
                if (!env->IsCaseSensitive())
                {
                    if (env->GetBuiltin(B_NaN).CompareBuiltIn_CaseInsensitive(name))
                        special = 0;
                    else if (env->GetBuiltin(B_Infinity).CompareBuiltIn_CaseInsensitive(name))
                        special = 1;
                    else if (env->GetBuiltin(B_MinusInfinity).CompareBuiltIn_CaseInsensitive(name))
                        special = 2;
                }
                else if (name == env->GetBuiltin(B_NaN))
                    special = 0;
                else if (name == env->GetBuiltin(B_Infinity))
                    special = 1;
                else if (name == env->GetBuiltin(B_MinusInfinity))
                    special = 2;

                if (special == 0)
                    var.SetNumber(NumberUtil::NaN());
                else if (special == 1)
                    var.SetNumber(NumberUtil::POSITIVE_INFINITY());
                else if (special == 2)
                    var.SetNumber(NumberUtil::NEGATIVE_INFINITY());
                else
                {
                    var.SetUndefined();
                    env->GetVariable(name, &var, ctx.GetWithStack());
                }

                if (ctx.VerboseAction)
                {
                    ASString dbg = var.ToDebugString(env);
                    if (!var.ToObjectInterface(env))
                        ctx.LogF.LogAction("-- get var: %s=%s\n", name.ToCStr(), dbg.ToCStr());
                    else
                        ctx.LogF.LogAction("-- get var: %s=%s at %p\n", name.ToCStr(), dbg.ToCStr(),
                                           var.ToObjectInterface(env));
                }
                break;
            }

            case 0x1D: // set variable
            {
                ASString name = Top1(env).ToString(env, -1);
                env->SetVariable(name, env->Top(0), ctx.GetWithStack(), true);
                if (ctx.VerboseAction)
                {
                    ASString dbg = Top1(env).ToDebugString(env);
                    ctx.LogF.LogAction("-- set var: %s \n", dbg.ToCStr());
                }
                env->Drop2();
                break;
            }

            case 0x20: // set target expression (tellTarget)
                FUN_14298bb90(&ctx);
                break;

            case 0x21: // string concat
            {
                Top1(env).ConvertToStringVersioned(env, ctx.Version);
                ASString s = env->Top(0).ToStringVersioned(env, ctx.Version);
                Top1(env).StringConcat(env, s);
                env->Drop1();
                break;
            }

            case 0x22: // get property
            {
                InteractiveObject* ptarget = env->FindTargetByValue(Top1(env));
                if (!ptarget)
                    Top1(env).SetUndefined();
                else
                    ToAvmCharacter(ptarget)->GetStandardMember(
                        (AvmCharacter::StandardMember)env->Top(0).ToInt32(env), &Top1(env), true);
                env->Drop1();
                break;
            }

            case 0x23: // set property
            {
                InteractiveObject* ptarget = env->FindTargetByValue(env->Top(2));
                if (ptarget)
                    ToAvmCharacter(ptarget)->SetStandardMember(
                        (AvmCharacter::StandardMember)Top1(env).ToInt32(env), env->Top(0), true);
                Drop3(env);
                break;
            }

            case 0x24: // duplicate clip: target, new name, depth
            {
                InteractiveObject* ptarget = env->FindTargetByValue(env->Top(2));
                if (ptarget)
                {
                    ASString newname = Top1(env).ToString(env);
                    ToAvmCharacter(ptarget)->CloneDisplayObject(newname, env->Top(0).ToInt32(env), 0); // the depth has its 16384 already
                }
                Drop3(env);
                break;
            }

            case 0x25: // remove clip; clips at negative depths stay
            {
                InteractiveObject* ptarget = env->FindTargetByValue(env->Top(0));
                if (ptarget)
                {
                    if (ptarget->Depth < 16384)
                        ctx.LogF.LogScriptMessage("removeMovieClip(\"%s\") failed - depth must be >= 0",
                                                  ptarget->GetName().ToCStr());
                    else
                        ptarget->RemoveDisplayObject();
                }
                env->Drop1();
                break;
            }

            case 0x26: // trace
            {
                FnCall fn(&env->Top(0), (ObjectInterface*)0, env, 1, env->GetTopIndex());
                GAS_GlobalTrace(fn);
                env->Drop1();
                break;
            }

            case 0x27: // start drag
                FUN_14298fea0(&ctx);
                break;

            case 0x28: // stop drag
                StopDragOf(env->GetTarget()->GetMovieImpl());
                break;

            case 0x29: // string less than
            {
                ASString a = Top1(env).ToStringVersioned(env, ctx.Version);
                ASString b = env->Top(0).ToStringVersioned(env, ctx.Version);
                Top1(env).SetBool(a < b);
                env->Drop1();
                break;
            }

            case 0x2A: // throw
                env->CheckTryBlocks(ctx.PC, &tryCount);
                env->ThrowingValue = env->Top(0);
                env->Drop1();
                ctx.NextPC = env->CheckExceptions(this, ctx.NextPC, &tryCount, retval, ctx.GetWithStack(), execType);
                break;

            case 0x2B: // cast
                FUN_142932d20(&ctx);
                break;

            case 0x2C: // implements
                FUN_14295dbe0(&ctx);
                break;

            case 0x30: // random(max)
            {
                int max = env->Top(0).ToInt32(env);
                if (max < 1)
                    max = 1;
                env->Top(0).SetInt((int)(Math::GetNextRandom(env->GetTarget()->GetMovieImpl()) % (unsigned)max));
                break;
            }

            case 0x32: // ord
            {
                ASString s = env->Top(0).ToString(env);
                env->Top(0).SetInt(s[0]);
                break;
            }

            case 0x33: // chr
            {
                char buf[2];
                buf[0] = (char)(UByte)env->Top(0).ToInt32(env);
                buf[1] = 0;
                env->Top(0).SetString(env->CreateString(buf));
                break;
            }

            case 0x34: // get timer
                env->Push(Value((Number)AsMovieSlots(env->GetTarget()->GetMovieImpl())->GetASTimerMs()));
                break;

            case 0x35: // mb substring(s, index (1-based), count)
            {
                ASString s   = env->Top(2).ToStringVersioned(env, ctx.Version);
                ASString sub = StringProto::StringSubstring(s, Top1(env).ToInt32(env) - 1, env->Top(0).ToInt32(env));
                env->Drop2();
                env->Top(0).SetString(sub);
                break;
            }

            case 0x36: // mb ord
            {
                ASString s = env->Top(0).ToStringVersioned(env, ctx.Version);
                env->Top(0).SetInt(s.GetSize() == 0 ? 0 : (int)s.GetCharAt(0));
                break;
            }

            case 0x37: // mb chr
            {
                wchar_t wbuf[2];
                wbuf[0] = (wchar_t)env->Top(0).ToUInt32(env);
                wbuf[1] = 0;
                env->Top(0).SetString(env->GetSC()->CreateString(wbuf));
                break;
            }

            case 0x3A: // delete object.member; before SWF 7 a missing object deletes through the scope chain
            {
                bool     deleted = false;
                Value&   objv    = Top1(env);
                ASString name    = env->Top(0).ToString(env);
                if (ctx.Version < 7 && (objv.IsUndefined() || objv.IsNull() || !objv.IsSet()))
                {
                    Value owner;
                    if (env->FindOwnerOfMember(name, &owner, ctx.GetWithStack()))
                        if (ObjectInterface* pobjif = owner.ToObjectInterface(env))
                            deleted = pobjif->DeleteMember(env->GetSC(), name);
                }
                else if (ObjectInterface* pobjif = objv.ToObjectInterface(env))
                    deleted = pobjif->DeleteMember(env->GetSC(), name);
                env->Drop1();
                env->Top(0).SetBool(deleted);
                break;
            }

            case 0x3B: // delete a variable (or path)
            {
                ASString name = env->Top(0).ToString(env, -1);
                Value    owner;
                bool     found;
                if ((name.GetHashFlags() & ASConstString::Flag_IsNotPath) == 0 && Environment::IsPath(name))
                {
                    Value                     tmp;
                    Environment::GetVarParams params(name, &tmp, ctx.GetWithStack(), 0, &owner);
                    found = env->FindVariable(params, false, &name) && !owner.IsUndefined() && owner.IsSet();
                }
                else
                    found = env->FindOwnerOfMember(name, &owner, ctx.GetWithStack());

                ObjectInterface* pobjif = found ? owner.ToObjectInterface(env) : 0;
                env->Top(0).SetBool(pobjif ? pobjif->DeleteMember(env->GetSC(), name) : false);
                break;
            }

            case 0x3C: // set local (a variable outside functions)
            {
                ASString name = Top1(env).ToString(env);
                if (ctx.IsFunction2 || execType == ActionBuffer::Exec_Function)
                    env->SetLocal(name, env->Top(0));
                else
                    env->SetVariable(name, env->Top(0), ctx.GetWithStack(), true);
                env->Drop2();
                break;
            }

            case 0x3D: // call function: name or function, arg count, args
            {
                Value function, owner;
                bool  invoke = true;
                if (env->Top(0).GetType() == Value::STRING)
                {
                    ASString fname = env->Top(0).ToString(env, -1);
                    env->GetVariable(fname, &function, ctx.GetWithStack(), 0, &owner);
                    if (!function.IsFunction())
                    {
                        // "super(...)": the super object's __constructor__ with the super object as this
                        if (function.IsObject() && (pobj = function.ToObject(env)) && pobj->IsSuper())
                        {
                            function = Value(pobj->Get__constructor__(env->GetSC()));
                            owner.SetAsObject(pobj);
                        }
                        else
                        {
                            if (ctx.VerboseActionErrors)
                                ctx.LogF.LogScriptError("CallFunction - '%s' is not a function", fname.ToCStr());
                            invoke = false;
                        }
                        pobj = NULL;
                    }
                }
                else
                    function = env->Top(0);

                const Number nargsf = Top1(env).ToNumber(env);
                const int    nargs  = NumberUtil::IsNaNOrInfinity(nargsf) ? 0 : (int)nargsf;
                Value        result;
                if (invoke)
                {
                    // a method called as a plain function gets its owner (the target, a with object) as this
                    ObjectInterface* pthis = owner.ToObjectInterface(env);
                    FunctionRef      func  = function.ToFunction(env);
                    if (func.Function)
                    {
                        FnCall fn(&result, pthis, env, nargs, env->GetTopIndex() - 2);
                        func.Function->Invoke(fn, func.pLocalFrame, NULL);
                    }
                    else if (env->IsVerboseActionErrors())
                        env->LogScriptError("CallFunction - attempt to call invalid function");
                }
                env->Drop(nargs + 1);
                env->Top(0) = result;

                if (env->ThrowingValue.IsSet())
                {
                    env->CheckTryBlocks(ctx.PC, &tryCount);
                    ctx.NextPC =
                        env->CheckExceptions(this, ctx.NextPC, &tryCount, retval, ctx.GetWithStack(), execType);
                }
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;
            }

            case 0x3E: // return
                if (retval)
                    *retval = env->Top(0);
                env->Drop1();
                ctx.NextPC = ctx.StopPC;
                break;

            case 0x3F: // modulo
            {
                const Number y = env->Top(0).ToNumber(env);
                const Number x = Top1(env).ToNumber(env);
                const Number r = (y != 0) ? (Number)fmod(x, y) : NumberUtil::NaN();
                env->Drop2();
                env->Push(Value(r));
                break;
            }

            case 0x40: // new: class name, arg count, args
            {
                ASString     classname = env->Top(0).ToString(env, -1);
                const Number nargsf    = Top1(env).ToNumber(env);
                const int    nargs     = NumberUtil::IsNaNOrInfinity(nargsf) ? 0 : (int)nargsf;
                env->Drop2();
                if (ctx.VerboseAction)
                    ctx.LogF.LogAction("---new object: %s\n", classname.ToCStr());

                pobj = NULL;
                Value ctor;
                if (env->GetVariable(classname, &ctor, ctx.GetWithStack()) && ctor.IsFunction())
                {
                    FunctionRef func = ctor.ToFunction(env);
                    pobj = *env->OperatorNew(func, nargs, -1);
                    if (!pobj && ctx.VerboseActionErrors)
                        ctx.LogF.LogScriptError("Can't create object with unknown class '%s'", classname.ToCStr());
                }
                else if (ctx.VerboseActionErrors)
                    ctx.LogF.LogScriptError("Can't create object with unknown class '%s'", classname.ToCStr());

                env->Drop(nargs);
                if (pobj)
                    env->Push(Value(pobj.GetPtr()));
                else
                    env->Push(Value());
                if (ctx.VerboseAction)
                    ctx.LogF.LogAction("New object %s at %p\n", classname.ToCStr(), pobj.GetPtr());
                pobj = NULL;

                if (env->ThrowingValue.IsSet())
                {
                    env->CheckTryBlocks(ctx.PC, &tryCount);
                    ctx.NextPC =
                        env->CheckExceptions(this, ctx.NextPC, &tryCount, retval, ctx.GetWithStack(), execType);
                }
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;
            }

            case 0x41: // declare local (var); local in functions only
            {
                ASString name = env->Top(0).ToString(env);
                if (ctx.IsFunction2 || execType == ActionBuffer::Exec_Function)
                    env->DeclareLocal(name);
                env->Drop1();
                break;
            }

            case 0x42: // init array: count, elements
            {
                const int n = (int)env->Top(0).ToNumber(env);
                env->Drop1();
                Value result;
                {
                    FnCall fn(&result, (ObjectInterface*)0, env, n, env->GetTopIndex());
                    ArrayCtorFunction::DeclareArray(fn);
                }
                if (n > 0)
                    env->Drop(n);
                env->Push(result);
                break;
            }

            case 0x43: // init object: count, {value, name} pairs
            {
                const int n = (int)env->Top(0).ToNumber(env);
                pobj = *env->OperatorNew(env->GetBuiltin(ASBuiltin_Object));
                env->Drop1();
                if (pobj)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (env->GetTopIndex() > 0)
                        {
                            if (Top1(env).GetType() == Value::STRING)
                            {
                                ASString name = Top1(env).ToString(env, -1);
                                pobj->SetMember(env, name, env->Top(0));
                            }
                            env->Drop2();
                        }
                    }
                }
                env->Push(Value(pobj.GetPtr()));
                pobj = NULL;

                if (env->ThrowingValue.IsSet())
                {
                    env->CheckTryBlocks(ctx.PC, &tryCount);
                    ctx.NextPC =
                        env->CheckExceptions(this, ctx.NextPC, &tryCount, retval, ctx.GetWithStack(), execType);
                }
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;
            }

            case 0x44: // typeof
            {
                int   typeName = B_undefined;
                Value& top     = env->Top(0);
                switch (top.GetType())
                {
                case Value::UNDEFINED:
                case Value::UNSET:
                    break;
                case Value::NULLTYPE:
                    typeName = B_null;
                    break;
                case Value::BOOLEAN:
                    typeName = B_boolean;
                    break;
                case Value::STRING:
                    typeName = B_string;
                    break;
                case Value::OBJECT:
                    typeName = B_object;
                    break;
                case Value::CHARACTER:
                {
                    // "movieclip" for sprites and null clips only
                    InteractiveObject* pch = top.ToCharacter(env);
                    typeName = (pch && !pch->IsSprite()) ? B_object : B_movieclip;
                    break;
                }
                case Value::FUNCTION:
                    typeName = B_function;
                    break;
                default:
                    if (top.IsNumber())
                        typeName = B_number;
                    else if (ctx.VerboseActionErrors)
                        ctx.LogF.LogScriptError("typeof unknown - %02X", top.GetType());
                    break;
                }
                top.SetString(env->GetBuiltin(typeName));
                break;
            }

            case 0x45: // target path
            {
                InteractiveObject* ptarget = env->Top(0).ToCharacter(env);
                if (ptarget)
                    env->Top(0).SetString(ptarget->GetCharacterHandle()->NamePath);
                else
                    env->Top(0).SetUndefined();
                break;
            }

            case 0x46: // enumerate
            case 0x55: // enumerate object
                FUN_142939920(&ctx, actionId);
                break;

            case 0x47: // add (typed)
                Top1(env).Add(env, env->Top(0));
                env->Drop1();
                break;

            case 0x49: // equals (typed)
                Top1(env).SetBool(Top1(env).IsEqual(env, env->Top(0)));
                env->Drop1();
                break;

            case 0x4A: // to number
                env->Top(0).SetNumber(env->Top(0).ToNumber(env));
                break;

            case 0x4B: // to string
                env->Top(0).ConvertToStringVersioned(env, ctx.Version);
                break;

            case 0x4C: // dup
                env->Push(env->Top(0));
                break;

            case 0x4D: // swap
            {
                Value t   = Top1(env);
                Top1(env) = env->Top(0);
                env->Top(0) = t;
                break;
            }

            case 0x4E: // get member: object, name
            {
                Value&           objv   = Top1(env);
                Value&           namev  = env->Top(0);
                ObjectInterface* pobjif = objv.ToObjectInterface(env);
                if (!pobjif)
                {
                    // a primitive: the member of its wrapper object
                    Value tmp = env->PrimitiveToTempObject(1);
                    Object* ptmp = tmp.ToObject(env);
                    if (ptmp)
                    {
                        ASString name = namev.ToString(env, -1);
                        if (!env->GetMember(ptmp, name, &objv))
                            objv.SetUndefined();
                    }
                    else
                        objv.SetUndefined();
                }
                else if (namev.IsNumber() && pobjif->GetObjectType() == ObjectInterface::Object_Array)
                {
                    // array element by index
                    ArrayObject* parr = static_cast<ArrayObject*>(static_cast<Object*>(pobjif));
                    pobj              = parr; // keeps the array while objv is overwritten
                    const int index   = (int)namev.ToNumber(env);
                    if (index < 0)
                    {
                        ASString name = namev.ToString(env, -1);
                        if (!pobjif->GetMemberRaw(env->GetSC(), name, &objv))
                            objv.SetUndefined();
                    }
                    else if (index < parr->GetSize() && parr->GetElementPtr(index))
                        objv = *parr->GetElementPtr(index);
                    else
                        objv.SetUndefined();
                    if (ctx.VerboseAction)
                    {
                        ASString dbg = objv.ToDebugString(env);
                        ctx.LogF.LogAction("-- GetMember %p[%d]=%s\n", parr, index, dbg.ToCStr());
                    }
                    pobj = NULL;
                }
                else
                {
                    ASString name = namev.ToString(env, -1);
                    if (objv.IsObject() || objv.IsFunction())
                        pobj = objv.ToObject(env); // keeps the object while objv is overwritten
                    objv.SetUndefined();
                    env->GetMember(pobjif, name, &objv);
                    if (ctx.VerboseAction)
                    {
                        ASString dbg = objv.ToDebugString(env);
                        if (!objv.ToObjectInterface(env))
                            ctx.LogF.LogAction("-- GetMember %s=%s\n", name.ToCStr(), dbg.ToCStr());
                        else
                            ctx.LogF.LogAction("-- GetMember %s=%s at %p\n", name.ToCStr(), dbg.ToCStr(),
                                               objv.ToObjectInterface(env));
                    }
                    pobj = NULL;
                }
                env->Drop1();
                // (no termination check here)
                if (env->ThrowingValue.IsSet())
                {
                    env->CheckTryBlocks(ctx.PC, &tryCount);
                    ctx.NextPC =
                        env->CheckExceptions(this, ctx.NextPC, &tryCount, retval, ctx.GetWithStack(), execType);
                }
                break;
            }

            case 0x4F: // set member: object, name, value
            {
                ObjectInterface* pobjif = env->Top(2).ToObjectInterface(env);
                if (!pobjif)
                {
                    if (ctx.VerboseAction)
                    {
                        ASString s2 = env->Top(2).ToDebugString(env);
                        ASString s1 = Top1(env).ToDebugString(env);
                        ASString s0 = env->Top(0).ToDebugString(env);
                        ctx.LogF.LogAction("- SetMember %s.%s=%s on invalid object\n", s2.ToCStr(), s1.ToCStr(),
                                           s0.ToCStr());
                    }
                }
                else
                {
                    Value& namev = Top1(env);
                    if (namev.IsNumber() && pobjif->GetObjectType() == ObjectInterface::Object_Array)
                    {
                        ArrayObject* parr  = static_cast<ArrayObject*>(static_cast<Object*>(pobjif));
                        const int    index = (int)namev.ToNumber(env);
                        if (index < 0)
                        {
                            ASString name = namev.ToString(env, -1);
                            parr->Object::SetMember(env, name, env->Top(0));
                        }
                        else
                            parr->SetElementSafe(index, env->Top(0));
                        if (ctx.VerboseAction)
                        {
                            ASString s0 = env->Top(0).ToDebugString(env);
                            ctx.LogF.LogAction("-- SetMember %p[%d]=%s\n", parr, index, s0.ToCStr());
                        }
                    }
                    else
                    {
                        ASString name = namev.ToString(env, -1);
                        pobjif->SetMember(env, name, env->Top(0));
                        if (ctx.VerboseAction)
                        {
                            ASString s2 = env->Top(2).ToDebugString(env);
                            ASString s0 = env->Top(0).ToDebugString(env);
                            ctx.LogF.LogAction("-- SetMember %s.%s=%s\n", s2.ToCStr(), name.ToCStr(), s0.ToCStr());
                        }
                    }
                }
                Drop3(env);
                // (no termination check here)
                if (env->ThrowingValue.IsSet())
                {
                    env->CheckTryBlocks(ctx.PC, &tryCount);
                    ctx.NextPC =
                        env->CheckExceptions(this, ctx.NextPC, &tryCount, retval, ctx.GetWithStack(), execType);
                }
                break;
            }

            case 0x50: // increment
                env->Top(0).Add(env, 1);
                break;

            case 0x51: // decrement
                env->Top(0).SetNumber(env->Top(0).ToNumber(env) - 1);
                break;

            case 0x52: // call method: name, object, arg count, args
            {
                const Number     nargsf     = env->Top(2).ToNumber(env);
                const int        nargs      = NumberUtil::IsNaNOrInfinity(nargsf) ? 0 : (int)nargsf;
                Value            result;
                ASString         methodName = env->Top(0).ToString(env, -1);
                ObjectInterface* piobj      = 0;
                // the object stays alive during the call (a character by a reference of its own)
                Value                  objectGuard = Top1(env);
                Ptr<InteractiveObject> charGuard   = objectGuard.IsCharacter() ? objectGuard.ToCharacter(env) : 0;

                if (env->Top(0).IsUndefined() || methodName.IsEmpty())
                {
                    // no name: the object itself is the function
                    Value function = Top1(env);
                    Value thisVal;
                    if (function.IsObject() && (pobj = function.ToObject(env)) && pobj->IsSuper())
                    {
                        function = Value(pobj->Get__constructor__(env->GetSC()));
                        thisVal.SetAsObject(pobj);
                    }
                    else
                        env->GetVariable(env->GetBuiltin(ASBuiltin_this), &thisVal, ctx.GetWithStack());

                    if (function.IsFunction())
                    {
                        FunctionRef func = function.ToFunction(env);
                        if (func.Function)
                        {
                            FnCall fn(&result, thisVal, env, nargs, env->GetTopIndex() - 3);
                            func.Invoke(fn, NULL);
                        }
                    }
                    else if (ctx.VerboseActionErrors)
                        ctx.LogF.LogScriptError("CallMethod \"as a function\" - pushed object is not a function object");
                }
                else if (!Top1(env).IsFunction() && (piobj = Top1(env).ToObjectInterface(env)) != 0)
                {
                    Value method;
                    if (piobj->IsSuper())
                    {
                        // super.method(): the nearest base class that has the method answers for the call
                        Ptr<SuperObject> psuper = static_cast<SuperObject*>(piobj);
                        pobj = psuper->SuperProto->FindOwner(env->GetSC(), methodName);
                        if (pobj)
                        {
                            psuper->SetAltProto(pobj);
                            pobj = NULL;
                        }
                        else
                            piobj = 0;
                    }
                    if (piobj)
                    {
                        if (env->GetMember(piobj, methodName, &method))
                        {
                            if (!method.IsFunction())
                            {
                                if (ctx.VerboseActionErrors)
                                    LogMemberError(ctx.LogF, piobj, "CallMethod - '%s.%s' is not a method",
                                                   "CallMethod - '%s' is not a method", methodName);
                            }
                            else
                            {
                                FunctionRef func = method.ToFunction(env);
                                if (func.Function)
                                {
                                    FnCall fn(&result, piobj, env, nargs, env->GetTopIndex() - 3);
                                    func.Function->Invoke(fn, func.pLocalFrame, methodName.ToCStr());
                                }
                                else if (ctx.VerboseActionErrors)
                                    LogMemberError(ctx.LogF, piobj, "Invoked method (%s.%s) is null",
                                                   "Invoked method (%s) is null", methodName);
                            }
                        }
                        else if (ctx.VerboseActionErrors)
                            LogMemberError(ctx.LogF, piobj, "CallMethod - can't find method %s.%s",
                                           "CallMethod - can't find method %s", methodName);
                    }
                }
                else if (Top1(env).IsFunction())
                {
                    // a static method: a member of the function object
                    Object* pfnobj = Top1(env).ToObject(env);
                    piobj          = pfnobj;
                    if (piobj)
                    {
                        Value method;
                        if (env->GetMember(piobj, methodName, &method))
                        {
                            FunctionRef func = method.ToFunction(env);
                            if (func.Function)
                            {
                                FnCall fn(&result, Top1(env), env, nargs, env->GetTopIndex() - 3);
                                func.Function->Invoke(fn, func.pLocalFrame, methodName.ToCStr());
                            }
                            else if (ctx.VerboseActionErrors)
                                LogMemberError(ctx.LogF, piobj, "Invoked method (%s.%s) is not a function",
                                               "Invoked method (%s) is not a function", methodName);
                        }
                        else if (ctx.VerboseActionErrors)
                            LogMemberError(ctx.LogF, piobj, "Static method '%s.%s' is not found.",
                                           "Static method '%s' is not found.", methodName);
                    }
                    else if (ctx.VerboseActionErrors)
                        ctx.LogF.LogScriptError("Function is not an object for static method '%s'.",
                                                methodName.ToCStr());
                }
                else
                {
                    // a primitive (string, number, boolean): its method on a temporary wrapper object
                    Value objVal = env->PrimitiveToTempObject(1);
                    if (objVal.IsObject())
                    {
                        ObjectInterface* ptemp = objVal.ToObject(env);
                        Value            method;
                        if (env->GetMember(ptemp, methodName, &method))
                        {
                            if (method.GetType() != Value::FUNCTION)
                            {
                                if (ctx.VerboseActionErrors)
                                    LogMemberError(ctx.LogF, ptemp, "CallMethod - '%s.%s' is not a method",
                                                   "CallMethod - '%s' is not a method", methodName);
                            }
                            else
                            {
                                FunctionRef func = method.ToFunction(env);
                                if (func.Function)
                                {
                                    FnCall fn(&result, ptemp, env, nargs, env->GetTopIndex() - 3);
                                    func.Function->Invoke(fn, func.pLocalFrame, methodName.ToCStr());
                                }
                                else if (ctx.VerboseActionErrors)
                                    LogMemberError(ctx.LogF, ptemp, "Error: Invoked method (%s.%s) is not a function\n",
                                                   "Error: Invoked method (%s) is not a function\n", methodName);
                            }
                        }
                        else if (ctx.VerboseActionErrors)
                            LogMemberError(ctx.LogF, ptemp, "CallMethod - can't find method %s.%s",
                                           "CallMethod - can't find method %s", methodName);
                    }
                    else if (ctx.VerboseActionErrors)
                        ctx.LogF.LogScriptError("CallMethod - '%s' on invalid object.", methodName.ToCStr());
                }

                env->Drop(nargs + 2);
                env->Top(0) = result;
                if (env->ThrowingValue.IsSet())
                {
                    env->CheckTryBlocks(ctx.PC, &tryCount);
                    ctx.NextPC =
                        env->CheckExceptions(this, ctx.NextPC, &tryCount, retval, ctx.GetWithStack(), execType);
                }
                // only a resolved this that is not an unloaded character can end the run
                if (piobj)
                {
                    InteractiveObject* pch = piobj->ToCharacter();
                    if ((!pch || !pch->IsUnloaded()) && env->NeedTermination(execType))
                        ctx.NextPC = ctx.StopPC;
                }
                break;
            }

            case 0x53: // new method: name, object, arg count, args
            {
                Value        ctorName = env->Top(0);
                Value        object   = Top1(env);
                const Number nargsf   = env->Top(2).ToNumber(env);
                const int    nargs    = NumberUtil::IsNaNOrInfinity(nargsf) ? 0 : (int)nargsf;
                Drop3(env);
                ASString ctorNameStr = ctorName.ToString(env, -1);
                if (ctx.VerboseAction)
                    ctx.LogF.LogAction("---new method: %s\n", ctorNameStr.ToCStr());

                Value ctor;
                if (ctorName.IsUndefined() || (ctorName.GetType() == Value::STRING && ctorNameStr.IsEmpty()))
                    ctor = Value(object.ToFunction(env));
                else
                {
                    ObjectInterface* pobjif = object.ToObjectInterface(env);
                    if ((!pobjif || !env->GetMember(pobjif, ctorNameStr, &ctor)) && ctx.VerboseActionErrors)
                        LogMemberError(ctx.LogF, pobjif, "Method '%s.%s' is not found.", "Method '%s' is not found.",
                                       ctorNameStr);
                }
                if (ctor.IsFunction())
                {
                    FunctionRef func = ctor.ToFunction(env);
                    pobj = *env->OperatorNew(func, nargs, -1);
                }
                else
                {
                    pobj = NULL;
                    if (ctx.VerboseActionErrors)
                        ctx.LogF.LogScriptError("Can't create object with unknown ctor");
                }
                env->Drop(nargs);
                env->Push(Value(pobj.GetPtr()));
                if (ctx.VerboseAction)
                    ctx.LogF.LogAction("New object created at %p\n", pobj.GetPtr());
                pobj = NULL;

                if (env->ThrowingValue.IsSet())
                {
                    env->CheckTryBlocks(ctx.PC, &tryCount);
                    ctx.NextPC =
                        env->CheckExceptions(this, ctx.NextPC, &tryCount, retval, ctx.GetWithStack(), execType);
                }
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;
            }

            case 0x54: // instanceof
                FUN_142962420(&ctx);
                break;

            case 0x60: // bitwise and
                Top1(env).SetInt(Top1(env).ToInt32(env) & env->Top(0).ToInt32(env));
                env->Drop1();
                break;

            case 0x61: // bitwise or
                Top1(env).SetInt(Top1(env).ToInt32(env) | env->Top(0).ToInt32(env));
                env->Drop1();
                break;

            case 0x62: // bitwise xor
                Top1(env).SetInt(Top1(env).ToInt32(env) ^ env->Top(0).ToInt32(env));
                env->Drop1();
                break;

            case 0x63: // shift left
                Top1(env).SetInt(Top1(env).ToInt32(env) << (env->Top(0).ToInt32(env) & 0x1f));
                env->Drop1();
                break;

            case 0x64: // shift right (signed)
                Top1(env).SetInt(Top1(env).ToInt32(env) >> (env->Top(0).ToInt32(env) & 0x1f));
                env->Drop1();
                break;

            case 0x65: // shift right (unsigned)
                Top1(env).SetUInt(Top1(env).ToUInt32(env) >> (env->Top(0).ToInt32(env) & 0x1f));
                env->Drop1();
                break;

            case 0x66: // strict equals: the same type (any two numbers) and equal
            {
                Value&     a       = Top1(env);
                const unsigned ta  = a.GetType(), tb = env->Top(0).GetType();
                const bool numbers = (ta == Value::INTEGER || ta == Value::NUMBER) &&
                                     (tb == Value::INTEGER || tb == Value::NUMBER);
                a.SetBool((ta == tb || numbers) && a.IsEqual(env, env->Top(0)));
                env->Drop1();
                break;
            }

            case 0x67: // greater (typed)
            {
                Value cmp = Top1(env).Compare(env, env->Top(0), 1);
                Top1(env) = cmp;
                env->Drop1();
                break;
            }

            case 0x68: // string greater
            {
                ASString a = Top1(env).ToStringVersioned(env, ctx.Version);
                ASString b = env->Top(0).ToStringVersioned(env, ctx.Version);
                Top1(env).SetBool(a > b);
                env->Drop1();
                break;
            }

            case 0x69: // extends
                FUN_142941680(&ctx);
                break;
            }
        }
        else
        {
            const int length = ReadU16(&ctx.pBuffer[ctx.PC + 1]);
            ctx.NextPC       = ctx.PC + length + 3;
            if (ctx.VerboseAction)
                ctx.LogOp(ctx.PC);

            switch (actionId)
            {
            default:
                break;

            case 0x81: // goto frame (0-based operand)
                if (!env->IsInvalidTarget && env->GetTarget())
                    env->GetTarget()->GotoFrame(ReadU16(&ctx.pBuffer[ctx.PC + 3]));
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;

            case 0x83: // get url: url, target path; "FSCommand:" urls go to the host
            {
                const char* purl        = reinterpret_cast<const char*>(&ctx.pBuffer[ctx.PC + 3]);
                const char* ptargetPath = purl + strlen(purl) + 1;
                if (ctx.VerboseAction)
                    ctx.LogF.LogAction("GetURL - path: %s  URL: %s", ptargetPath, purl);
                if (strncmp(purl, "FSCommand:", 10) == 0)
                {
                    if (FsCommandView* phandler = FsCommandHandlerOf(ctx.pOriginalTarget->GetMovieImpl()))
                        phandler->Callback(env->GetTarget()->GetMovieImpl(), purl + 10, ptargetPath);
                }
                else
                    env->GetAS2Root()->AddLoadQueueEntry(ptargetPath, purl, env);
                break;
            }

            case 0x87: // store register: the top stays on the stack
            {
                const int reg = ctx.pBuffer[ctx.PC + 3];
                if (ctx.IsFunction2)
                {
                    *env->LocalRegisterPtr(reg) = env->Top(0);
                    if (ctx.VerboseAction)
                        LogRegister(ctx.LogF, env, "-------------- local register[%d] = '%s'", reg);
                }
                else if (reg < 4)
                {
                    env->GlobalRegister[reg] = env->Top(0);
                    if (ctx.VerboseAction)
                        LogRegister(ctx.LogF, env, "-------------- global register[%d] = '%s'", reg);
                }
                else if (ctx.VerboseActionErrors)
                    ctx.LogF.LogScriptError("StoreRegister[%d] - register out of bounds!", reg);
                break;
            }

            case 0x88: // constant pool (the dictionary)
                ProcessDeclDict(env->GetSC(), ctx.PC, ctx.NextPC, ctx.LogF);
                break;

            case 0x8A: // wait for frame
            case 0x8D: // wait for frame 2 (stack based)
                FUN_142994a10(&ctx, this, actionId);
                break;

            case 0x8B: // set target (tellTarget by name); an empty name goes back to the original target
            {
                const char* ptargetName = reinterpret_cast<const char*>(&ctx.pBuffer[ctx.PC + 3]);
                if (ptargetName[0] == 0)
                    env->SetTarget(ctx.pOriginalTarget);
                else
                {
                    ASString           targetName = env->CreateString(ptargetName);
                    InteractiveObject* ptarget    = env->FindTarget(targetName, 0);
                    if (!ptarget)
                    {
                        if (ctx.VerboseActionErrors)
                            ctx.LogF.LogScriptError("SetTarget(tellTarget) with invalid target '%s'.", ptargetName);
                        env->SetInvalidTarget(ctx.pOriginalTarget);
                    }
                    else
                        env->SetTarget(ptarget);
                }
                break;
            }

            case 0x8C: // go to labeled frame
                if (!env->IsInvalidTarget)
                {
                    InteractiveObject* ptarget = env->GetTarget();
                    if (ptarget->IsSprite())
                        static_cast<Sprite*>(ptarget)->GotoLabeledFrame(
                            reinterpret_cast<const char*>(&ctx.pBuffer[ctx.PC + 3]), 0);
                }
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;

            case 0x8E: // define function 2
                FUN_142946390(&ctx, this);
                break;

            case 0x8F: // try: the block record, where it starts and the stack depth to go back to
            {
                env->CheckTryBlocks(ctx.PC, &tryCount);
                ++tryCount;
                Environment::TryDescr descr;
                descr.pTryBlock     = &ctx.pBuffer[ctx.PC + 3];
                descr.TryBeginPC    = ctx.NextPC;
                descr.TopStackIndex = env->GetTopIndex();
                env->PushTryBlock(descr);
                break;
            }

            case 0x94: // with: the object on top scopes the block (8 levels at most)
            {
                if (ctx.VerboseAction)
                    ctx.LogF.LogAction("-------------- with block start: stack size is %d\n",
                                       ctx.WithStack.pStack ? (int)ctx.WithStack.pStack->GetSize() : 0);
                if (!ctx.WithStack.pStack || ctx.WithStack.pStack->GetSize() < 8)
                {
                    WithStackEntry entry;
                    entry.BlockEndPc = ctx.NextPC + ReadU16(&ctx.pBuffer[ctx.PC + 3]);
                    if (env->Top(0).IsCharacter())
                    {
                        entry.pCharacter = env->Top(0).ToCharacter(env);
                        entry.IsObject   = 0;
                    }
                    else
                    {
                        entry.pObject  = env->Top(0).ToObject(env);
                        entry.IsObject = 1;
                    }
                    FUN_142971cc0(&ctx.WithStack, entry);
                }
                env->Drop1();
                break;
            }

            case 0x96: // push: typed values up to the end of the record
            {
                int i = ctx.PC;
                do
                {
                    const int type = ctx.pBuffer[3 + i];
                    ++i;
                    if (type == 4) // register
                    {
                        const int reg = ctx.pBuffer[3 + i];
                        ++i;
                        if (ctx.IsFunction2)
                        {
                            env->Push(*env->LocalRegisterPtr(reg));
                            if (ctx.VerboseAction)
                                LogRegister(ctx.LogF, env, "-------------- pushed local register[%d] = '%s'", reg);
                        }
                        else if (reg >= 4)
                        {
                            env->Push(Value());
                            if (ctx.VerboseActionErrors)
                                ctx.LogF.LogScriptError("Push register[%d] - register out of bounds", reg);
                        }
                        else
                        {
                            env->Push(env->GlobalRegister[reg]);
                            if (ctx.VerboseAction)
                                LogRegister(ctx.LogF, env, "-------------- pushed global register[%d] = '%s'", reg);
                        }
                    }
                    else if (type == 8 || type == 9) // dictionary entry, 8- or 16-bit index
                    {
                        unsigned id = ctx.pBuffer[3 + i];
                        if (type == 9)
                        {
                            id |= ctx.pBuffer[4 + i] << 8;
                            i += 2;
                        }
                        else
                            ++i;
                        if (id < Dictionary.GetSize())
                        {
                            env->Push(Value(Dictionary[id]));
                            if (ctx.VerboseAction)
                                ctx.LogF.LogAction("-------------- pushed '%s'\n", Dictionary[id].ToCStr());
                        }
                        else
                        {
                            if (ctx.VerboseActionErrors)
                                ctx.LogF.LogScriptError("DictLookup(%d) is out of bounds", id);
                            env->Push(Value());
                            if (ctx.VerboseAction)
                                ctx.LogF.LogAction(type == 8 ? "-------------- pushed 0\n" : "-------------- pushed 0");
                        }
                    }
                    else if (type == 0) // string
                    {
                        ASString str = env->CreateString(reinterpret_cast<const char*>(&ctx.pBuffer[3 + i]));
                        i += (int)str.GetSize() + 1;
                        env->Push(Value(str));
                        if (ctx.VerboseAction)
                            ctx.LogF.LogAction("-------------- pushed '%s'\n", str.ToCStr());
                    }
                    else if (type == 1) // float
                    {
                        float f;
                        memcpy(&f, &ctx.pBuffer[3 + i], 4);
                        i += 4;
                        env->Push(Value((Number)f));
                        if (ctx.VerboseAction)
                            ctx.LogF.LogAction("-------------- pushed '%f'\n", (double)f);
                    }
                    else if (type == 2) // null
                    {
                        Value nullValue;
                        nullValue.SetNull();
                        env->Push(nullValue);
                        if (ctx.VerboseAction)
                            ctx.LogF.LogAction("-------------- pushed NULL\n");
                    }
                    else if (type == 3) // undefined
                    {
                        env->Push(Value());
                        if (ctx.VerboseAction)
                            ctx.LogF.LogAction("-------------- pushed UNDEFINED\n");
                    }
                    else if (type == 5) // boolean
                    {
                        const bool b = ctx.pBuffer[3 + i] != 0;
                        ++i;
                        env->Push(Value(b));
                        if (ctx.VerboseAction)
                            ctx.LogF.LogAction("-------------- pushed %s\n", b ? "true" : "false");
                    }
                    else if (type == 6) // double: the high word first
                    {
                        UInt32 hi, lo;
                        memcpy(&hi, &ctx.pBuffer[3 + i], 4);
                        memcpy(&lo, &ctx.pBuffer[3 + i + 4], 4);
                        const UInt64 bits = ((UInt64)hi << 32) | lo;
                        Number       d;
                        memcpy(&d, &bits, 8);
                        i += 8;
                        env->Push(Value(d));
                        if (ctx.VerboseAction)
                            ctx.LogF.LogAction("-------------- pushed double %f\n", d);
                    }
                    else if (type == 7) // int32
                    {
                        SInt32 v;
                        memcpy(&v, &ctx.pBuffer[3 + i], 4);
                        i += 4;
                        env->Push(Value((int)v));
                        if (ctx.VerboseAction)
                            ctx.LogF.LogAction("-------------- pushed int32 %d\n", (int)v);
                    }
                } while (i - ctx.PC < length);
                break;
            }

            case 0x99: // branch always; out of the buffer ends the run at once (the nesting level stays)
                ctx.NextPC += ReadS16(&ctx.pBuffer[ctx.PC + 3]);
                if ((unsigned)ctx.NextPC >= pBufferData->GetLength())
                {
                    env->SetTarget(ctx.pOriginalTarget);
                    if (ctx.VerboseActionErrors)
                        ctx.LogF.LogScriptError("Branch destination %d is out of action buffer bounds!", ctx.NextPC);
                    return;
                }
                break;

            case 0x9A: // get url 2: url, target path; the method flags pick a variables or movie load
            {
                const UByte method     = ctx.pBuffer[ctx.PC + 3];
                ASString    targetPath = env->Top(0).ToString(env, -1);
                ASString    url        = Top1(env).ToString(env, -1);
                if (ctx.VerboseAction)
                    ctx.LogF.LogAction("GetURL2 - path: %s  URL: %s", targetPath.ToCStr(), url.ToCStr());
                if (strncmp(url.ToCStr(), "FSCommand:", 10) == 0)
                {
                    if (FsCommandView* phandler = FsCommandHandlerOf(ctx.pOriginalTarget->GetMovieImpl()))
                        phandler->Callback(env->GetTarget()->GetMovieImpl(), url.ToCStr() + 10, targetPath.ToCStr());
                }
                else
                {
                    LoadQueueEntry::LoadMethod loadMethod = LoadQueueEntry::LM_None;
                    if ((method & 3) == 1)
                        loadMethod = LoadQueueEntry::LM_Get;
                    else if ((method & 3) == 2)
                        loadMethod = LoadQueueEntry::LM_Post;
                    const char* ptail = "";
                    const int   level = MovieRoot::ParseLevelName(targetPath.ToCStr(), &ptail,
                                                                  env->GetTarget()->GetVersion() > 6);
                    if (method & 0x80)
                        env->GetAS2Root()->AddVarLoadQueueEntry(targetPath.ToCStr(), url.ToCStr(), loadMethod);
                    else if ((method & 0x40) || (level != -1 && *ptail == 0))
                        env->GetAS2Root()->AddLoadQueueEntry(targetPath.ToCStr(), url.ToCStr(), env, loadMethod);
                    // (a load into a clip by path is not done)
                }
                env->Drop2();
                break;
            }

            case 0x9B: // define function
                FUN_142945da0(&ctx, this);
                break;

            case 0x9D: // branch if true
            {
                const int  offset = ReadS16(&ctx.pBuffer[ctx.PC + 3]);
                const bool test   = env->Top(0).ToBool(env);
                env->Drop1();
                if (test)
                {
                    ctx.NextPC += offset;
                    if (ctx.NextPC > ctx.StopPC && ctx.VerboseActionErrors)
                        ctx.LogF.LogScriptError("branch to offset %d - this section only runs to %d", ctx.NextPC,
                                                ctx.StopPC);
                }
                break;
            }

            case 0x9E: // call frame: the actions of a frame of the target run now
            {
                InteractiveObject* ptarget = env->GetTarget();
                if (env->IsInvalidTarget)
                    break;
                unsigned frameNumber = 0;
                if (ResolveFrameNumber(env, env->Top(0), &ptarget, &frameNumber))
                {
                    if (ptarget->IsSprite())
                        AvmSprite::FromSprite(static_cast<Sprite*>(ptarget))->CallFrameActions(frameNumber);
                }
                else if (ctx.VerboseActionErrors)
                {
                    ASString frame = env->Top(0).ToString(env, -1);
                    ctx.LogF.LogScriptError("%s, CallFrame('%s') - unknown frame",
                                            ptarget->GetCharacterHandle()->NamePath.ToCStr(), frame.ToCStr());
                }
                env->Drop1();
                break;
            }

            case 0x9F: // goto frame expression: frame on the stack, play flag, scene offset
            {
                const UByte     optionFlag  = ctx.pBuffer[ctx.PC + 3];
                const PlayState state       = (optionFlag & 1) ? State_Playing : State_Stopped;
                const int       sceneOffset = (optionFlag & 2) ? ReadU16(&ctx.pBuffer[ctx.PC + 4]) : 0;
                InteractiveObject* ptarget     = env->GetTarget();
                unsigned           frameNumber = 0;
                if (ResolveFrameNumber(env, env->Top(0), &ptarget, &frameNumber))
                {
                    ptarget->GotoFrame(frameNumber + sceneOffset);
                    ptarget->SetPlayState(state);
                }
                env->Drop1();
                if (env->NeedTermination(execType))
                    ctx.NextPC = ctx.StopPC;
                break;
            }
            }
        }

        ctx.PC = ctx.NextPC;
        if (ctx.VerboseAction)
            ctx.LogF.LogAction("==== stack top index %d ====\n", env->GetTopIndex());
    }

    // the finally blocks of the try blocks still open
    for (; tryCount > 0; --tryCount)
    {
        Environment::TryDescr tryDescr = env->PopTryBlock();
        const unsigned        topIndex = (unsigned)env->GetTopIndex();
        if (topIndex > tryDescr.TopStackIndex)
            env->Drop(topIndex - tryDescr.TopStackIndex);
        if (tryDescr.pTryBlock[0] & 2)
        {
            ctx.PC = tryDescr.TryBeginPC + tryDescr.GetTrySize() + ReadU16(&tryDescr.pTryBlock[3]);
            env->Unrolling = true;
            Execute(env, ctx.PC, ReadU16(&tryDescr.pTryBlock[5]), retval, ctx.GetWithStack(), execType);
            env->Unrolling = false;
        }
    }

    if (--env->ExecutionNestingLevel == 0 && env->ThrowingValue.IsSet())
        env->ClearThrowing();
    if (isOriginalTargetValid)
        env->SetTarget(ctx.pOriginalTarget);
    else
        env->SetInvalidTarget(ctx.pOriginalTarget);
    if (ctx.VerboseAction)
        ctx.LogF.LogAction("\n");
}

}}} // namespace Scaleform::GFx::AS2
