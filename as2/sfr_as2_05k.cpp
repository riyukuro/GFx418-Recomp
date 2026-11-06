// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 GAS_Invoke by method name and
// GAS_InvokeParsed (argument format strings), gap functions of sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142946fc0-0x142947350 .text$mn
// MS2-RANGE: 0x142947360-0x1429477ff .text$mn
// MS2-RANGE: 0x142947800-0x142947b97 .text$mn

#include <stdarg.h>

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_interactiveobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {
struct InvokeInlineTag {};
}

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it here.
static SF_FORCEINLINE void InvokeSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
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

// FunctionRefBase::Init(orig) with the SetLocalFrame call expanded.
template<>
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, InvokeInlineTag)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        InvokeSetLocalFrame(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

namespace {

// Value::ToFunction (exe 0x142991190), inlined.
struct InvokeValueAccess : Value
{
    static SF_FORCEINLINE FunctionRef ToFunction(const Value& v, const Environment* penv)
    {
        switch (v.T.Type)
        {
        case FUNCTIONNAME:
            return static_cast<const InvokeValueAccess&>(v).ResolveFunctionName(penv);
        case FUNCTION:
            return FunctionRef(v.V.FunctionValue, InvokeInlineTag());
        default:;
        }
        return FunctionRef();
    }
};

// Value::ToObjectInterface with ToCharacter and ToAvmCharacter inlined.
static SF_FORCEINLINE ObjectInterface* InvokeToObjectInterface(const Value& v, const Environment* penv)
{
    if (v.T.Type == Value::CHARACTER)
    {
        InteractiveObject* pchar = 0;
        if (penv && v.V.pCharHandle)
        {
            DisplayObject* pdisp = v.V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
            if (pdisp)
                pchar = pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
        }
        return pchar ? GFx::AS2::ToAvmCharacter(pchar) : 0;
    }
    return v.ToObject(penv);
}

} // namespace

// The method by name, called with nargs values from the environment stack.
// @0x142946fc0
bool GAS_Invoke(const char* pmethodName, Value* presult, ObjectInterface* pthis, Environment* penv, int nargs,
                int firstArgBottomIndex)
{
    if (!pmethodName || *pmethodName == '\0')
        return false;

    InteractiveObject* pnewTarget = 0;
    Value              method, owner;
    if (!penv->GetVariable(penv->CreateString(pmethodName), &method, NULL, &pnewTarget, &owner, 0))
    {
        if (pthis && pthis->IsASCharacter())
            penv->LogScriptError("Can't find method '%s.%s' to invoke.",
                                 pthis->ToCharacter_Call()->GetCharacterHandle()->NamePath.ToCStr(), pmethodName);
        else
            penv->LogScriptError("Can't find method '%s' to invoke.", pmethodName);
        return false;
    }

    FunctionRef func = InvokeValueAccess::ToFunction(method, penv);
    if (func.IsNull())
    {
        if (pthis && pthis->IsASCharacter())
            penv->LogScriptError("Invoked method '%s.%s' is not a function",
                                 pthis->ToCharacter_Call()->GetCharacterHandle()->NamePath.ToCStr(), pmethodName);
        else
            penv->LogScriptError("Invoked method '%s' is not a function", pmethodName);
        return false;
    }

    if (owner.IsCharacter() || owner.IsObject())
        pthis = InvokeToObjectInterface(owner, penv);
    else if (pnewTarget)
        pthis = ToAvmCharacter(pnewTarget);
    return GAS_Invoke(method, presult, pthis, penv, nargs, firstArgBottomIndex, pmethodName);
}

// The method value, its arguments pushed as the format string describes (%d %u %n %b %f %hf %s %ls), in reverse.
// MS2-FUNCTIONAL: the stack pushes and the argument reversal are scheduled differently
// @0x142947360
bool GAS_InvokeParsed(const Value& method, Value* presult, ObjectInterface* pthis, Environment* penv,
                      const char* pmethodArgFmt, va_list args, const char* pmethodName)
{
    int nargs = 0;
    if (pmethodArgFmt)
    {
        int         start = penv->GetTopIndex();
        const char* p     = pmethodArgFmt;
        char        c     = *p;
        while (c != 0)
        {
            ++p;
            if (c != '%')
                penv->LogScriptError("InvokeParsed('%s','%s') - invalid char '%c'", pmethodName, pmethodArgFmt, c);
            else
            {
                c = *p++;
                switch (c)
                {
                case 'd':
                    penv->Push(Value(va_arg(args, int)));
                    break;
                case 'u':
                    penv->Push(Value());
                    break;
                case 'n':
                    penv->Push(Value(Value::NULLTYPE));
                    break;
                case 'b':
                    penv->Push(Value(va_arg(args, int) != 0));
                    break;
                case 'f':
                    penv->Push(Value(Number(va_arg(args, double))));
                    break;
                case 'h':
                    c = *p++;
                    if (c != 'f')
                        penv->LogScriptError("InvokeParsed('%s','%s') - invalid format '%%h%c'", pmethodName,
                                             pmethodArgFmt, c);
                    else
                        penv->Push(Value(Number(va_arg(args, double))));
                    break;
                case 's':
                    penv->Push(Value(penv->CreateString(va_arg(args, const char*))));
                    break;
                case 'l':
                    c = *p++;
                    if (c != 's')
                        penv->LogScriptError("InvokeParsed('%s','%s') - invalid format '%%l%c'", pmethodName,
                                             pmethodArgFmt, c);
                    else
                        penv->Push(Value(penv->GetSC()->CreateString(va_arg(args, const wchar_t*))));
                    break;
                default:
                    penv->LogScriptError("InvokeParsed('%s','%s') - invalid format '%%%c'", pmethodName,
                                         pmethodArgFmt, c);
                    break;
                }
            }
            // blanks, tabs and commas between the specifiers
            c = *p;
            while (c == ' ' || c == '\t' || c == ',')
                c = *++p;
        }
        nargs = penv->GetTopIndex() - start;
        // the callee reads its arguments last-pushed first
        for (int i = 0; i < nargs / 2; ++i)
        {
            Value* phigh = penv->Bottom(start + nargs - i);
            Value* plow  = penv->Bottom(start + 1 + i);
            Value  tmp(*plow);
            *plow  = *phigh;
            *phigh = tmp;
        }
    }
    bool ok = GAS_Invoke(method, presult, pthis, penv, nargs, penv->GetTopIndex(), pmethodName);
    penv->Drop(nargs);
    return ok;
}

// The method by name, with the arguments of a format string.
// @0x142947800
bool GAS_InvokeParsed(const char* pmethodName, Value* presult, ObjectInterface* pthis, Environment* penv,
                      const char* pmethodArgFmt, va_list args)
{
    if (!pmethodName || *pmethodName == '\0')
        return false;

    InteractiveObject* pnewTarget = 0;
    Value              method, owner;
    if (!penv->GetVariable(penv->CreateString(pmethodName), &method, NULL, &pnewTarget, &owner, 0))
    {
        if (pthis && pthis->IsASCharacter())
            penv->LogScriptError("Can't find method '%s.%s' to invoke.",
                                 pthis->ToCharacter_Call()->GetCharacterHandle()->NamePath.ToCStr(), pmethodName);
        else
            penv->LogScriptError("Can't find method '%s' to invoke.", pmethodName);
        return false;
    }

    FunctionRef func = InvokeValueAccess::ToFunction(method, penv);
    if (func.IsNull())
    {
        if (pthis && pthis->IsASCharacter())
            penv->LogScriptError("Invoked method '%s.%s' is not a function",
                                 pthis->ToCharacter_Call()->GetCharacterHandle()->NamePath.ToCStr(), pmethodName);
        else
            penv->LogScriptError("Invoked method '%s' is not a function", pmethodName);
        return false;
    }

    if (owner.IsCharacter() || owner.IsObject())
        pthis = InvokeToObjectInterface(owner, penv);
    else if (pnewTarget)
        pthis = ToAvmCharacter(pnewTarget);
    return GAS_InvokeParsed(method, presult, pthis, penv, pmethodArgFmt, args, pmethodName);
}

} } }
