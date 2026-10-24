// Recovered Scaleform 4.1.18 GFx AS2: System.IME, the script side of the input method editor (its state and the
// events the IME manager broadcasts to the listeners).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_IME_H
#define MS2_SF_GFX_AS2_IME_H

#include "as2_movieroot.h"
#include "as2_objectproto.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// System.IME instance. 0x68 bytes; vftables 0x143223340 (Object), 0x143223388 (ObjectInterface).
class GASIme : public Object
{
protected:
    GASIme(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

    void commonInit(Environment* penv); // exe 0x14299b610

public:
    GASIme(Environment* penv); // exe 0x142999670

    // Calls System.IME.<event>(...) on the listeners; the string ones pass null for an empty string.
    static void BroadcastOnDisplayStatusWindow(Environment* penv);                          // exe 0x142999be0
    static void BroadcastOnIMEComposition(Environment* penv, const ASString& pString);      // exe 0x142999d80
    static void BroadcastOnRemoveStatusWindow(Environment* penv);                           // exe 0x142999fd0
    static void BroadcastOnSetConversionMode(Environment* penv, const ASString& pString);   // exe 0x14299a170
    static void BroadcastOnSetCurrentInputLang(Environment* penv, const ASString& pString); // exe 0x14299a3c0
    static void BroadcastOnSetIMEName(Environment* penv, const ASString& pString);          // exe 0x14299a610
    static void BroadcastOnSetSupportedIMEs(Environment* penv, const ASString& pString);    // exe 0x14299a860
    static void BroadcastOnSetSupportedLanguages(Environment* penv, const ASString& pString); // exe 0x14299aab0
    static void BroadcastOnSwitchLanguage(Environment* penv, const ASString& pString);      // exe 0x14299ad00
};

// System.IME.prototype: its methods are no-ops (the class is used through the static functions).
class GASImeProto : public Prototype<GASIme>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143223150

    GASImeProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142999830

    // new System.IME() (exe 0x14299b120).
    static void GlobalCtor(const FnCall& fn);
};

// The System.IME class object: the IME state functions, the conversion mode names, and a broadcaster.
class GASImeCtorFunction : public CFunctionObject
{
public:
    static const NameFunction StaticFunctionTable[]; // exe 0x1432231e0
    static const NameNumber   GASNumberConstTable[]; // exe 0x143223260

    GASImeCtorFunction(ASStringContext* psc); // exe 0x1429996e0

    static void DoConversion(const FnCall& fn);         // exe 0x142998f00 (nothing to do)
    static void GetConversionMode(const FnCall& fn);    // exe 0x142998f10
    static void GetEnabled(const FnCall& fn);           // exe 0x142998fe0
    static void SetCompositionString(const FnCall& fn); // exe 0x142999050
    static void SetConversionMode(const FnCall& fn);    // exe 0x142999120
    static void SetEnabled(const FnCall& fn);           // exe 0x1429991d0
    static void SendLangBarMessage(const FnCall& fn);   // exe 0x142999270

    // Creates the class and its prototype and publishes System.IME (exe 0x14299b200).
    static FunctionRef Register(GlobalContext* pgc);
};

}}} // namespace Scaleform::GFx::AS2

#endif
