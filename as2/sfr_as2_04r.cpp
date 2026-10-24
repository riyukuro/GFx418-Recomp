// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 host object construction
// (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04r
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429374f0-0x1429379c7 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_value.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Builds an object of the (dotted) class name with the host arguments, or a plain Object when no class is named.
// The class path is resolved member by member from the global object; the result is handed back as a host value.
// MS2-FUNCTIONAL: smart pointers hold the walk's objects
// @0x1429374f0
void MovieRoot::CreateObject(GFx::Value* pvalue, const char* className, const GFx::Value* pargs, unsigned nargs)
{
    AvmDisplayObjBase* pmain = pMovieImpl->pMainMovie->GetAvmObjImpl();
    Environment* penv =
        static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmain))->GetASEnvironment();

    Ptr<Object> pobj;
    if (!className)
    {
        pobj = *penv->OperatorNew(penv->StringContext.pContext->pGlobal, penv->GetBuiltin(ASBuiltin_Object), 0, -1);
        ASValue2GFxValue(penv, Value(pobj.GetPtr()), pvalue);
        return;
    }

    for (int i = (int)nargs - 1; i >= 0; --i)
    {
        Value arg;
        Value2ASValue(pargs[i], &arg);
        penv->Push(arg);
    }

    if (!strchr(className, '.'))
    {
        pobj = *penv->OperatorNew(penv->StringContext.pContext->pGlobal, penv->CreateString(className), nargs, -1);
    }
    else
    {
        Ptr<Object> pcur = penv->StringContext.pContext->pGlobal;
        const char* rest = className;
        for (;;)
        {
            const char* dot = strchr(rest, '.');
            if (!dot)
                break;
            char   buf[0x100];
            UPInt  len = (UPInt)(dot + 1 - rest);
            if (len > 0x100)
                len = 0x100;
            memcpy(buf, rest, len - 1);
            buf[len - 1] = '\0';
            rest         = dot + 1;
            Value member;
            if (!pcur->GetMemberRaw(&penv->StringContext, penv->CreateString(buf), &member))
            {
                pvalue->SetUndefined();
                return;
            }
            pcur = member.ToObject(0);
        }
        pobj = *penv->OperatorNew(pcur, penv->CreateString(rest), nargs, -1);
    }

    if (!pobj)
        pvalue->SetUndefined();
    else
        ASValue2GFxValue(penv, Value(pobj.GetPtr()), pvalue);
    for (unsigned n = nargs; n; --n)
        penv->Drop(1);
}

}}} // namespace Scaleform::GFx::AS2
