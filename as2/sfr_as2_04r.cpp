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
// MS2-FUNCTIONAL: SDK body; exe keeps penv in r13 / this in r14 during the push loop and places the bail-out SetUndefined block earlier (regalloc + block layout, 1 byte)
// @0x1429374f0
void MovieRoot::CreateObject(GFx::Value* pvalue, const char* className, const GFx::Value* pargs, unsigned nargs)
{
    AvmDisplayObjBase* pmain = pMovieImpl->pMainMovie->GetAvmObjImpl();
    Environment* penv =
        static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmain))->GetASEnvironment();
    Ptr<Object> pobj;

    if (className)
    {
        // Push params to stack
        if (nargs > 0)
        {
            for (int i = (nargs - 1); i > -1; --i)
            {
                Value asval;
                Value2ASValue(pargs[i], &asval);
                penv->Push(asval);
            }
        }

        // Check if the className is part of a package (has '.')
        const char* p = strchr(className, '.');
        if (p)
        {
            ASStringContext* psc = penv->GetSC();
            char             buf[256];
            const char*      pname  = className;
            Ptr<Object>      parent = penv->StringContext.pContext->pGlobal;

            while (pname)
            {
                const char* p = strchr(pname, '.');
                UPInt       sz;
                if (p)
                    sz = p++ - pname + 1;
                else
                    break; // class name found

                if (sz > sizeof(buf))
                    sz = sizeof(buf);

                memcpy(buf, pname, sz - 1);
                buf[sz - 1] = '\0';

                pname = p;

                Value       pkgObjVal;
                Ptr<Object> pkgObj;
                ASString    memberName(psc->CreateString(buf));

                if (parent->GetMemberRaw(psc, memberName, &pkgObjVal))
                    pkgObj = pkgObjVal.ToObject(NULL);
                else
                {
                    pvalue->SetUndefined();
                    return; // Package in path not found; bail
                }

                parent = pkgObj;
            }

            pobj = *penv->OperatorNew(parent, penv->CreateString(pname), nargs);
        }
        else
            pobj = *penv->OperatorNew(penv->CreateString(className), nargs);

        if (pobj)
            ASValue2GFxValue(penv, Value(pobj), pvalue);
        else
            pvalue->SetUndefined();

        // Cleanup; pop params from stack
        if (nargs > 0)
            penv->Drop(nargs);
    }
    else
    {
        pobj = *penv->OperatorNew(penv->GetBuiltin(ASBuiltin_Object));
        ASValue2GFxValue(penv, Value(pobj), pvalue);
    }
}

}}} // namespace Scaleform::GFx::AS2
