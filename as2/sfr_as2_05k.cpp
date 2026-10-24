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

// Looks the method up by name: the variable itself, the object or character it was found on (the receiver of the
// call), and the character the path ended in. The messages are the exe's.
struct FoundMethod
{
    Value              Method;
    Value              Owner;
    InteractiveObject* pNewTarget;
    FoundMethod() : pNewTarget(0) {}
};

bool FindMethod(FoundMethod* pfound, const char* pmethodName, ObjectInterface* pthis, Environment* penv)
{
    if (!penv->GetVariable(penv->CreateString(pmethodName), &pfound->Method, 0, &pfound->pNewTarget, &pfound->Owner, 0))
    {
        if (pthis && pthis->IsASCharacter())
            penv->LogScriptError("Can't find method '%s.%s' to invoke.",
                                 pthis->ToCharacter_Call()->GetCharacterHandle()->NamePath.ToCStr(), pmethodName);
        else
            penv->LogScriptError("Can't find method '%s' to invoke.", pmethodName);
        return false;
    }
    return true;
}

// The object the method is called on: the owner found with it, else the character the path ended in, else pthis.
ObjectInterface* ReceiverOf(FoundMethod& found, ObjectInterface* pthis, Environment* penv)
{
    if (found.Owner.IsCharacter())
        return found.Owner.ToAvmCharacter(penv);
    if (found.Owner.IsObject())
        return found.Owner.ToObject(penv);
    if (found.pNewTarget)
        return static_cast<AvmCharacter*>(found.pNewTarget->GetAvmIntObj());
    return pthis;
}

void LogNotFunction(const char* pmethodName, ObjectInterface* pthis, Environment* penv)
{
    if (pthis && pthis->IsASCharacter())
        penv->LogScriptError("Invoked method '%s.%s' is not a function",
                             pthis->ToCharacter_Call()->GetCharacterHandle()->NamePath.ToCStr(), pmethodName);
    else
        penv->LogScriptError("Invoked method '%s' is not a function", pmethodName);
}

} // namespace

// The method by name, called with nargs values from the environment stack.
// MS2-FUNCTIONAL: ref-counted function holders and the owner switch are scheduled differently
// @0x142946fc0
bool GAS_Invoke(const char* pmethodName, Value* presult, ObjectInterface* pthis, Environment* penv, int nargs,
                int firstArgBottomIndex)
{
    if (!pmethodName || !*pmethodName)
        return true;
    FoundMethod found;
    if (!FindMethod(&found, pmethodName, pthis, penv))
        return false;
    FunctionRef func = found.Method.ToFunction(penv);
    if (func.IsNull())
    {
        LogNotFunction(pmethodName, pthis, penv);
        return false;
    }
    return GAS_Invoke(found.Method, presult, ReceiverOf(found, pthis, penv), penv, nargs, firstArgBottomIndex,
                      pmethodName);
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
// MS2-FUNCTIONAL: ref-counted function holders and the owner switch are scheduled differently
// @0x142947800
bool GAS_InvokeParsed(const char* pmethodName, Value* presult, ObjectInterface* pthis, Environment* penv,
                      const char* pmethodArgFmt, va_list args)
{
    if (!pmethodName || !*pmethodName)
        return true;
    FoundMethod found;
    if (!FindMethod(&found, pmethodName, pthis, penv))
        return false;
    FunctionRef func = found.Method.ToFunction(penv);
    if (func.IsNull())
    {
        LogNotFunction(pmethodName, pthis, penv);
        return false;
    }
    return GAS_InvokeParsed(found.Method, presult, ReceiverOf(found, pthis, penv), penv, pmethodArgFmt, args,
                            pmethodName);
}

} } }
