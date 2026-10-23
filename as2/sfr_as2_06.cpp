// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 array element storage and
// the script runtime entry points from Init to Reset.
// MS2-UNIT: sfr_as2_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14295d700-0x14295d840 .text$mn
// MS2-RANGE: 0x14295c710-0x14295c930 .text$mn
// MS2-RANGE: 0x14295ca10-0x14295d1c0 .text$mn
// MS2-RANGE: 0x14295d5e0-0x14295d700 .text$mn
// MS2-RANGE: 0x14295d840-0x14295d970 .text$mn
// MS2-RANGE: 0x14295d970-0x14295da40 .text$mn
// MS2-RANGE: 0x14295dbb0-0x14295dbe0 .text$mn
// MS2-RANGE: 0x14295e080-0x14295e1b0 .text$mn
// MS2-RANGE: 0x1429663d0-0x142966480 .text$mn
// MS2-RANGE: 0x1429658d0-0x1429659e0 .text$mn
// MS2-RANGE: 0x142965bb0-0x142965c80 .text$mn
// MS2-RANGE: 0x142965f30-0x1429660c0 .text$mn
// MS2-RANGE: 0x1429660c0-0x142966270 .text$mn
// MS2-RANGE: 0x14295e1b0-0x14295e2b0 .text$mn
// MS2-RANGE: 0x142961720-0x142961830 .text$mn
// MS2-RANGE: 0x142961830-0x142961a40 .text$mn
// MS2-RANGE: 0x142961d40-0x142961d80 .text$mn
// MS2-RANGE: 0x142961ef0-0x142961fe0 .text$mn
// MS2-RANGE: 0x142961fe0-0x142962010 .text$mn
// MS2-RANGE: 0x142962010-0x1429620d0 .text$mn
// MS2-RANGE: 0x1429623a0-0x142962410 .text$mn
// MS2-RANGE: 0x142962bb0-0x142962c90 .text$mn
// MS2-RANGE: 0x142965510-0x142965560 .text$mn
// MS2-RANGE: 0x142965c80-0x142965ce0 .text$mn
// MS2-RANGE: 0x142965d10-0x142965da0 .text$mn
// MS2-RANGE: 0x142965db0-0x142965e50 .text$mn
// MS2-RANGE: 0x142966270-0x142966370 .text$mn
// MS2-RANGE: 0x142967390-0x1429673e0 .text$mn
// MS2-RANGE: 0x1429673e0-0x142967430 .text$mn
// MS2-RANGE: 0x142967430-0x1429674a0 .text$mn
// MS2-RANGE: 0x142967b90-0x142967bf0 .text$mn
// MS2-RANGE: 0x142967d10-0x142967e00 .text$mn
// MS2-RANGE: 0x142967e00-0x142967f60 .text$mn
// MS2-RANGE: 0x142967f60-0x142967fc0 .text$mn
// MS2-RANGE: 0x142967fc0-0x1429680b0 .text$mn
// MS2-RANGE: 0x1429680b0-0x142968210 .text$mn
// MS2-RANGE: 0x142968210-0x142968280 .text$mn
// MS2-RANGE: 0x142968280-0x142968370 .text$mn
// MS2-RANGE: 0x142968370-0x1429684d0 .text$mn
// MS2-RANGE: 0x1429684d0-0x142968560 .text$mn
// MS2-RANGE: 0x142968560-0x142968610 .text$mn
// MS2-RANGE: 0x142968f90-0x142969000 .text$mn
// MS2-RANGE: 0x14296b820-0x14296b850 .text$mn
// MS2-RANGE: 0x14296bba0-0x14296bbb0 .text$mn
// MS2-RANGE: 0x14296ba60-0x14296bbf0 .text$mn
// MS2-RANGE: 0x14296bbf0-0x14296bd60 .text$mn
// MS2-RANGE: 0x14296e790-0x14296e870 .text$mn
// MS2-RANGE: 0x14296e870-0x14296e9f0 .text$mn
// MS2-RANGE: 0x14296efd0-0x14296f070 .text$mn
// MS2-RANGE: 0x14296f070-0x14296f0c0 .text$mn
// MS2-RANGE: 0x14296f1b0-0x14296f260 .text$mn
// MS2-RANGE: 0x14296f2b0-0x14296f390 .text$mn
// MS2-RANGE: 0x14296f390-0x14296f3d0 .text$mn
// MS2-RANGE: 0x14296f640-0x14296f770 .text$mn
// MS2-RANGE: 0x14296f770-0x14296f870 .text$mn
// MS2-RANGE: 0x142971a50-0x142971ac0 .text$mn
// MS2-RANGE: 0x142971ba0-0x142971c50 .text$mn
// MS2-RANGE: 0x142971c50-0x142971cc0 .text$mn
// MS2-RANGE: 0x142972830-0x1429729b0 .text$mn
// MS2-RANGE: 0x142972330-0x142972410 .text$mn
// MS2-RANGE: 0x142972410-0x142972490 .text$mn
// MS2-RANGE: 0x142973040-0x142973080 .text$mn
// MS2-RANGE: 0x14297c970-0x14297ca60 .text$mn
// MS2-RANGE: 0x14297ca70-0x14297cae0 .text$mn
// MS2-RANGE: 0x14297d0d0-0x14297d1e0 .text$mn
// MS2-RANGE: 0x14297d1e0-0x14297d330 .text$mn
// MS2-RANGE: 0x14297d4b0-0x14297d550 .text$mn
// MS2-RANGE: 0x14297d550-0x14297d5f0 .text$mn
// MS2-RANGE: 0x14297d5f0-0x14297d690 .text$mn
// MS2-RANGE: 0x14297d690-0x14297d730 .text$mn
// MS2-RANGE: 0x14297dc30-0x14297dcd0 .text$mn
// MS2-RANGE: 0x14297d730-0x14297d7d0 .text$mn
// MS2-RANGE: 0x14297d7d0-0x14297d870 .text$mn
// MS2-RANGE: 0x14297d870-0x14297d910 .text$mn
// MS2-RANGE: 0x14297d910-0x14297d9b0 .text$mn
// MS2-RANGE: 0x14297d9b0-0x14297da50 .text$mn
// MS2-RANGE: 0x14297da50-0x14297daf0 .text$mn
// MS2-RANGE: 0x14297daf0-0x14297db90 .text$mn
// MS2-RANGE: 0x14297db90-0x14297dc30 .text$mn
// MS2-RANGE: 0x14297dcd0-0x14297dd70 .text$mn
// MS2-RANGE: 0x14297dfb0-0x14297e060 .text$mn
// MS2-RANGE: 0x14297e060-0x14297e0e0 .text$mn
// MS2-RANGE: 0x14297e1b0-0x14297e230 .text$mn
// MS2-RANGE: 0x14297e0e0-0x14297e1b0 .text$mn
// MS2-RANGE: 0x14297e230-0x14297e2b0 .text$mn
// MS2-RANGE: 0x14297e2b0-0x14297e330 .text$mn
// MS2-RANGE: 0x14297e330-0x14297e3f0 .text$mn
// MS2-RANGE: 0x14297e3f0-0x14297e450 .text$mn
// MS2-RANGE: 0x14297e450-0x14297e500 .text$mn
// MS2-RANGE: 0x14297e500-0x14297e5a0 .text$mn
// MS2-RANGE: 0x14297e5a0-0x14297e640 .text$mn
// MS2-RANGE: 0x1429752b0-0x142975740 .text$mn
// MS2-RANGE: 0x142973080-0x142973500 .text$mn
// MS2-RANGE: 0x142973a80-0x142973f20 .text$mn
// MS2-RANGE: 0x142973f20-0x142974460 .text$mn
// MS2-RANGE: 0x142974460-0x142974910 .text$mn
// MS2-RANGE: 0x142974910-0x142974d70 .text$mn
// MS2-RANGE: 0x142974d70-0x1429752b0 .text$mn
// MS2-RANGE: 0x1429763c0-0x142976900 .text$mn
// MS2-RANGE: 0x142976be0-0x142977070 .text$mn
// MS2-RANGE: 0x142977070-0x1429775b0 .text$mn
// MS2-RANGE: 0x142977ad0-0x142977db0 .text$mn
// MS2-RANGE: 0x142978240-0x142978780 .text$mn
// MS2-RANGE: 0x142978dd0-0x142979260 .text$mn
// MS2-RANGE: 0x1429797e0-0x142979d00 .text$mn
// MS2-RANGE: 0x14297a4a0-0x14297a960 .text$mn
// MS2-RANGE: 0x14297aca0-0x14297b190 .text$mn
// MS2-RANGE: 0x14297bf80-0x14297c400 .text$mn
// MS2-RANGE: 0x142976900-0x142976be0 .text$mn
// MS2-RANGE: 0x142979d00-0x142979fe0 .text$mn
// MS2-RANGE: 0x14297c400-0x14297c6e0 .text$mn
// MS2-RANGE: 0x142977db0-0x142978240 .text$mn
// MS2-RANGE: 0x142975f30-0x1429763c0 .text$mn
// MS2-RANGE: 0x142975740-0x142975c20 .text$mn
// MS2-RANGE: 0x14295d1c0-0x14295d320 .text$mn
// MS2-RANGE: 0x142973500-0x142973a80 .text$mn
// MS2-RANGE: 0x1429775b0-0x142977ad0 .text$mn
// MS2-RANGE: 0x142979260-0x1429797e0 .text$mn
// MS2-RANGE: 0x142979fe0-0x14297a4a0 .text$mn
// MS2-RANGE: 0x142978780-0x142978a90 .text$mn
// MS2-RANGE: 0x142978a90-0x142978dd0 .text$mn
// MS2-RANGE: 0x142963400-0x1429635f0 .text$mn
// MS2-RANGE: 0x142969450-0x1429694e0 .text$mn
// MS2-RANGE: 0x142969bd0-0x142969d90 .text$mn
// MS2-RANGE: 0x142969d90-0x142969f50 .text$mn
// MS2-RANGE: 0x142969f50-0x14296a0a0 .text$mn
// MS2-RANGE: 0x14296a300-0x14296a450 .text$mn
// MS2-RANGE: 0x1429696d0-0x1429697f0 .text$mn
// MS2-RANGE: 0x142969aa0-0x142969bd0 .text$mn
// MS2-RANGE: 0x142969850-0x142969980 .text$mn
// MS2-RANGE: 0x142969980-0x142969aa0 .text$mn
// MS2-RANGE: 0x14296c220-0x14296c430 .text$mn
// MS2-RANGE: 0x14296cb80-0x14296cbf0 .text$mn
// MS2-RANGE: 0x14296cbf0-0x14296cd30 .text$mn
// MS2-RANGE: 0x14296cd30-0x14296ce70 .text$mn
// MS2-RANGE: 0x142971d70-0x142972190 .text$mn
// MS2-RANGE: 0x142972490-0x1429726a0 .text$mn
// MS2-RANGE: 0x1429718b0-0x142971a50 .text$mn
// MS2-RANGE: 0x142972190-0x142972330 .text$mn
// MS2-RANGE: 0x142969040-0x142969080 .text$mn
// MS2-RANGE: 0x142965e50-0x142965f00 .text$mn
// MS2-RANGE: 0x14295d450-0x14295d4e0 .text$mn
// MS2-RANGE: 0x142964200-0x142964370 .text$mn
// MS2-RANGE: 0x142964e50-0x142965160 .text$mn
// MS2-RANGE: 0x14297dd70-0x14297df30 .text$mn
// MS2-RANGE: 0x14297df30-0x14297dfb0 .text$mn
// MS2-RANGE: 0x142968f00-0x142968f90 .text$mn
// MS2-RANGE: 0x142966370-0x1429663d0 .text$mn
// MS2-RANGE: 0x1429621f0-0x142962310 .text$mn
// MS2-RANGE: 0x1429620d0-0x1429621f0 .text$mn
// MS2-RANGE: 0x142961b40-0x142961c40 .text$mn
// MS2-RANGE: 0x142961c40-0x142961d40 .text$mn
// MS2-RANGE: 0x14297d030-0x14297d080 .text$mn
// MS2-RANGE: 0x142962310-0x1429623a0 .text$mn
// MS2-RANGE: 0x14296aa90-0x14296ab10 .text$mn
// MS2-RANGE: 0x14297d460-0x14297d4b0 .text$mn
// MS2-RANGE: 0x1429659e0-0x142965a20 .text$mn
// MS2-RANGE: 0x142962b30-0x142962bb0 .text$mn
// MS2-RANGE: 0x142963fc0-0x142964020 .text$mn
// MS2-RANGE: 0x142969000-0x142969040 .text$mn
// MS2-RANGE: 0x14297cf70-0x14297d030 .text$mn
// MS2-RANGE: 0x14296d120-0x14296d140 .text$mn
// MS2-RANGE: 0x14296d310-0x14296d330 .text$mn
// MS2-RANGE: 0x14296a990-0x14296a9f0 .text$mn
// MS2-RANGE: 0x14296a9f0-0x14296aa90 .text$mn
// MS2-RANGE: 0x1429654a0-0x142965510 .text$mn
// MS2-RANGE: 0x142965570-0x1429658d0 .text$mn
// MS2-RANGE: 0x14296f0d0-0x14296f1b0 .text$mn
// MS2-RANGE: 0x14297d080-0x14297d0d0 .text$mn
// MS2-RANGE: 0x142967c30-0x142967c90 .text$mn
// MS2-RANGE: 0x14295db50-0x14295dbb0 .text$mn
// MS2-RANGE: 0x14296a850-0x14296a8f0 .text$mn
// MS2-RANGE: 0x14296a8f0-0x14296a990 .text$mn
// MS2-RANGE: 0x14296f260-0x14296f2b0 .text$mn
// MS2-RANGE: 0x14296a540-0x14296a7c0 .text$mn
// MS2-RANGE: 0x14296a7c0-0x14296a850 .text$mn
// MS2-RANGE: 0x14295d4f0-0x14295d5e0 .text$mn
// MS2-RANGE: 0x1429697f0-0x142969850 .text$mn
// MS2-RANGE: 0x14295d320-0x14295d3a0 .text$mn
// MS2-RANGE: 0x14295d3a0-0x14295d450 .text$mn
// MS2-RANGE: 0x1429635f0-0x142963820 .text$mn
// MS2-RANGE: 0x142963a10-0x142963aa0 .text$mn
// MS2-RANGE: 0x142967c90-0x142967d10 .text$mn
// MS2-RANGE: 0x142967bf0-0x142967c30 .text$mn
// MS2-RANGE: 0x14296a450-0x14296a540 .text$mn
// MS2-RANGE: 0x1429726a0-0x142972730 .text$mn
// MS2-RANGE: 0x142972730-0x142972830 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_timer.h"
#include "../include/gfx/gfx_input.h"
#include "../include/render/render_twips.h"
#include "../include/gfx/gfx_stream.h"

// Stores *value under key in the hash at owner+0x10 and releases the passed reference (a folded hash set; the
// prototype table of GlobalContext here). Defined in sfr_video_01.
void FUN_14000c280(void* owner, unsigned key, void** value);
bool FUN_14260b7f0(void* styleManager, const char* text, unsigned __int64 length);
bool FUN_14260b870(void* styleManager, const wchar_t* text, unsigned __int64 length);
bool FUN_142606410(void* allocator, bool noAllocationsAllowed);
bool FUN_142606150(void* allocator, bool noAllocationsAllowed);
void FUN_1425bd9a0(void* textField, const char* text, bool html, bool notifyVariable);
void FUN_14257dcb0(void* file);

namespace Scaleform { namespace GFx {

class FunctionHandler;

namespace AS2 {

// Function object around a host FunctionHandler (GFx::Value::CreateFunction). Only what this unit needs.
class UserDefinedFunctionObject : public FunctionObject
{
protected:
    Ptr<FunctionHandler> pContext;  // +0x68
    void*                pUserData; // +0x70

public:
    // Through super the handler runs on the real this, then the super drops its alternate prototype
    // (exe 0x142963aa0).
    virtual void Invoke(const FnCall& fn, LocalFrame*, const char*);

    // Hands the call to the handler (exe 0x142964390).
    void InvokeImpl(const FnCall& fn);
};

// @0x142961720
void ArrayObject::InitArray(const FnCall& fn)
{
    Value index;
    for (int i = 0; i < fn.NArgs; i++)
    {
        index.SetInt(i);
        SetMember(fn.Env, index.ToString(fn.Env), fn.Arg(i));
    }
}

// MS2-FUNCTIONAL jump offsets of the inlined Object::HasMember
// @0x14295d700
bool ArrayObject::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    int idx;
    if ((idx = ParseIndex(name)) >= 0)
    {
        if (idx >= (int)Elements.GetSize() || Elements[idx] == 0 || Elements[idx]->IsUndefined() ||
            Elements[idx]->IsNull())
            return false;
        return true;
    }
    return Object::HasMember(psc, name, inclPrototypes);
}

// MS2-FUNCTIONAL the exe keeps the copied member's type in a register and skips its destructor on the not found path
// @0x14295d970
bool Object::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    Member member;
    if (MemberHash_Get(&Members, name, &member))
        return true;
    else if (inclPrototypes && pProto)
        return pProto->HasMember(psc, name, true);
    return false;
}

// MS2-FUNCTIONAL the exe inlines the standard-member name hash and ObjectInterface refcount paths; this preserves
// their lookup result through the recovered ASString and object APIs.
// @0x14295d840
bool AvmCharacter::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    ASString lowerName(name);
    if (IsStandardMember(name, &lowerName))
    {
        const StandardMember member = GetStandardMemberConstant(lowerName.IsEmpty() ? name : lowerName);
        if (member != M_InvalidMember && member < M_LastBitMaskMember &&
            (GetStandardMemberBitMask() & (1u << static_cast<unsigned>(member))))
            return true;
    }

    Object* object = GetASObject();
    return object && object->HasMember(psc, name, inclPrototypes);
}

// MS2-FUNCTIONAL the exe inlines the tabEnabled lookup and weak parent traversal; this preserves the flag override,
// script property, parent focus, and explicit tab index behavior with the recovered object interfaces.
// @0x142965f30
bool AvmCharacter::IsTabable() const
{
    InteractiveObject* displayObject = pDispObj;
    if (!displayObject || !displayObject->IsTabable())
        return false;

    const unsigned tabFlags = displayObject->Flags & InteractiveObject::Mask_TabEnabled;
    if (tabFlags)
        return tabFlags == InteractiveObject::Mask_TabEnabled;

    Environment* env = const_cast<AvmCharacter*>(this)->GetASEnvironment();
    Object* object = const_cast<AvmCharacter*>(this)->GetASObject();
    if (env && object)
    {
        ASString tabEnabled = env->StringContext.CreateConstString("tabEnabled");
        Value value;
        if (object->GetMember(env, tabEnabled, &value) && !value.IsUndefined() && !value.IsNull())
            return value.ToBool(env);
    }

    InteractiveObject* parent = displayObject->GetParent();
    if (parent && parent->GetAvmIntObj()->IsTabable())
        return true;
    return displayObject->TabIndex > 0;
}

// MS2-FUNCTIONAL: the exe inlines focusEnabled lookup and the final button-mode virtual call; this preserves script override and fallback semantics.
// @0x1429658d0
bool AvmSprite::IsFocusEnabled(FocusMovedType fmt) const
{
    if (fmt == GFx_FocusMovedByMouse)
        return false;

    Environment* env = const_cast<AvmSprite*>(this)->GetASEnvironment();
    Object* object = const_cast<AvmSprite*>(this)->GetASObject();
    if (env && object)
    {
        ASString focusEnabled = env->StringContext.CreateConstString("focusEnabled");
        Value value;
        if (object->GetMember(env, focusEnabled, &value) && !value.IsUndefined() && !value.IsNull())
            return value.ToBool(env);
    }
    return static_cast<const AvmInteractiveObjBase*>(static_cast<const AvmCharacter*>(this))->ActsAsButton();
}

// MS2-FUNCTIONAL: the exe inlines tabEnabled lookup and Value conversion; this keeps the script override and tab-index fallback.
// @0x1429660c0
bool AvmTextField::IsTabable() const
{
    Environment* env = const_cast<AvmTextField*>(this)->GetASEnvironment();
    Object* object = const_cast<AvmTextField*>(this)->GetASObject();
    if (env && object)
    {
        ASString tabEnabled = env->StringContext.CreateConstString("tabEnabled");
        Value value;
        if (object->GetMember(env, tabEnabled, &value) && !value.IsUndefined() && !value.IsNull())
            return value.ToBool(env);
    }
    return pDispObj && pDispObj->TabIndex > 0;
}

// MS2-FUNCTIONAL: broadcasts the one pushed argument through the recovered broadcaster helper; the exe uses an equivalent local callback.
// @0x1429696d0
void LoadVarsObject::NotifyOnData(Environment* penv, ASString& data)
{
    penv->Push(Value(data));
    ASString eventName = penv->CreateConstString("onData");
    AsBroadcaster::BroadcastMessage(penv, this, eventName, 1, penv->GetTopIndex());
    penv->Drop1();
}

// MS2-FUNCTIONAL: uses the recovered broadcaster helper for the exe's local one-argument callback.
// @0x142969850
void LoadVarsObject::NotifyOnHTTPStatus(Environment* penv, double status)
{
    penv->Push(Value(static_cast<Number>(status)));
    ASString eventName = penv->CreateConstString("onHTTPStatus");
    AsBroadcaster::BroadcastMessage(penv, this, eventName, 1, penv->GetTopIndex());
    penv->Drop1();
}

// MS2-FUNCTIONAL: uses the recovered broadcaster helper for the exe's local one-argument callback.
// @0x142969980
void LoadVarsObject::NotifyOnLoad(Environment* penv, bool success)
{
    penv->Push(Value(success));
    ASString eventName = penv->GetBuiltin(ASBuiltin_onLoad);
    AsBroadcaster::BroadcastMessage(penv, this, eventName, 1, penv->GetTopIndex());
    penv->Drop1();
}

// MS2-FUNCTIONAL: broadcasts the recovered argument list through AsBroadcaster's equivalent local callback.
// @0x142969bd0
void MovieClipLoader::NotifyOnLoadComplete(Environment* penv, InteractiveObject* ptarget, int status)
{
    penv->Push(Value(status));
    penv->Push(Value(ptarget));
    ASString eventName = penv->CreateConstString("onLoadComplete");
    AsBroadcaster::BroadcastMessage(penv, this, eventName, 2, penv->GetTopIndex());
    penv->Drop(2);
}

// MS2-FUNCTIONAL: broadcasts the recovered argument list through AsBroadcaster's equivalent local callback.
// @0x142969d90
void MovieClipLoader::NotifyOnLoadError(Environment* penv, InteractiveObject* ptarget, const char* errorCode, int status)
{
    penv->Push(Value(status));
    penv->Push(Value(penv->CreateConstString(errorCode)));
    penv->Push(Value(ptarget));
    ASString eventName = penv->CreateConstString("onLoadError");
    AsBroadcaster::BroadcastMessage(penv, this, eventName, 3, penv->GetTopIndex());
    penv->Drop(3);
}

// MS2-FUNCTIONAL: broadcasts the recovered argument through AsBroadcaster's equivalent local callback.
// @0x142969f50
void MovieClipLoader::NotifyOnLoadInit(Environment* penv, InteractiveObject* ptarget)
{
    penv->Push(Value(ptarget));
    ASString eventName = penv->CreateConstString("onLoadInit");
    AsBroadcaster::BroadcastMessage(penv, this, eventName, 1, penv->GetTopIndex());
    penv->Drop1();
}

// MS2-FUNCTIONAL: broadcasts the recovered argument through AsBroadcaster's equivalent local callback.
// @0x14296a300
void MovieClipLoader::NotifyOnLoadStart(Environment* penv, InteractiveObject* ptarget)
{
    penv->Push(Value(ptarget));
    ASString eventName = penv->CreateConstString("onLoadStart");
    AsBroadcaster::BroadcastMessage(penv, this, eventName, 1, penv->GetTopIndex());
    penv->Drop1();
}

// MS2-FUNCTIONAL: Ghidra confirms the delimiter split and null-extension path; this uses the recovered ASString helpers.
// @0x14296e870
bool Environment::ParsePath(ASStringContext* psc, const ASString& path, ASString* pbase, ASString* pextension)
{
    const char* text = path.ToCStr();
    const char* split = strchr(text, ':');
    if (!split)
        split = strrchr(text, '.');
    if (!split && !strrchr(text, '/'))
        return false;

    if (split)
    {
        int offset = static_cast<int>(split - text);
        pextension->operator=(psc->CreateString(split + 1));
        if (offset > 0 && text[offset - 1] == '/')
            --offset;
        *pbase = offset < 0 ? path : psc->CreateString(text, static_cast<UPInt>(offset));
    }
    else
    {
        pextension->operator=(psc->CreateConstString(""));
        *pbase = path;
    }
    return true;
}

// MS2-FUNCTIONAL: queues the same CFunction and three argument values using recovered ActionEntry/Array interfaces.
// @0x142972490
void Selection::QueueSetFocus(Environment* penv, InteractiveObject* newFocus, unsigned controllerIdx,
                              FocusMovedType fmt)
{
    MovieRoot* root = ToAS2Root(penv->GetTarget());
    MovieRoot::ActionEntry* entry = root->InsertEmptyAction(ActionPriority::AP_Frame);
    entry->Type = MovieRoot::ActionEntry::Entry_CFunction;
    entry->CFunction = DoTransferFocus;
    entry->FunctionParams.PushBack(Value(newFocus));
    entry->FunctionParams.PushBack(Value(static_cast<int>(fmt)));
    entry->FunctionParams.PushBack(Value(static_cast<Number>(controllerIdx)));
}

// MS2-FUNCTIONAL: follows the exe's this adjustment and TextField style-sheet pointer tests at +0x108/+0x40.
// @0x14295dbb0
bool AvmTextFieldBase_HasStyleSheet(const void* self)
{
    const unsigned char* textField = static_cast<const unsigned char*>(self) - 0x10;
    const void* styleData = *reinterpret_cast<void* const*>(textField + 0x108);
    return styleData && *reinterpret_cast<void* const*>(static_cast<const unsigned char*>(styleData) + 0x40);
}

struct AvmSwfEvent
{
    EventId Id;
    Ptr<ActionBufferData> pActionBuffer;

    void Read(StreamContext* stream, unsigned eventId);
};
static_assert(offsetof(AvmSwfEvent, pActionBuffer) == 0x18, "AvmSwfEvent exe layout");
static_assert(sizeof(AvmSwfEvent) == 0x20, "AvmSwfEvent exe size");

// MS2-FUNCTIONAL: reproduces the executable event header, key byte, action-data read, and stream-length correction.
// @0x142972830
void AvmSwfEvent::Read(StreamContext* stream, unsigned eventId)
{
    Id = EventId(eventId);
    Id.ControllerIndex = -1;
    unsigned actionLength = stream->ReadU32();
    if (eventId & EventId::Event_KeyPress)
    {
        Id.KeyCode = stream->ReadU8();
        if (actionLength)
            --actionLength;
    }

    pActionBuffer = MakePickable(ActionBufferData::CreateNew());
    if (!pActionBuffer)
        return;
    pActionBuffer->Read(stream, actionLength);
    const unsigned actualLength = pActionBuffer->GetLength();
    if (actualLength < actionLength)
        stream->CurByteIndex += actionLength - actualLength;
    else if (actualLength > actionLength)
        stream->CurByteIndex -= actualLength - actionLength;
}

// @0x142962010
void ArrayObject::InsertEmpty(int start, int count)
{
    int i;
    int oldSize = (int)Elements.GetSize();
    Elements.Resize(oldSize + count);
    if (oldSize)
    {
        for (i = (int)Elements.GetSize() - 1; i >= start + count; --i)
            Elements[i] = Elements[i - count];
    }
    for (i = 0; i < count; i++)
        Elements[start + i] = 0;
}

// @0x142966270
void ArrayObject::JoinToString(Environment* penv, StringBuffer* pbuffer, const char* pdelimiter) const
{
    pbuffer->Clear();
    Value undefinedValue;
    for (unsigned i = 0; i < Elements.GetSize(); i++)
    {
        if (i)
            pbuffer->AppendString(pdelimiter);
        if (Elements[i])
        {
            ASString s(Elements[i]->ToString(penv));
            pbuffer->AppendString(s.ToCStr());
        }
        else
        {
            ASString s(undefinedValue.ToString(penv));
            pbuffer->AppendString(s.ToCStr());
        }
    }
}

// @0x142971ba0
void ArrayObject::PushBack(const Value& val)
{
    Elements.PushBack(SF_HEAP_AUTO_NEW(this) Value(val));
}

// @0x142971c50
void ArrayObject::PushBack()
{
    Elements.PushBack(0);
}

// @0x1429684d0
void ArrayObject::MakeDeepCopy(MemoryHeap* pheap)
{
    for (UPInt i = 0, n = Elements.GetSize(); i < n; i++)
    {
        if (Elements[i])
        {
            Value* pval = SF_HEAP_NEW(pheap) Value(*Elements[i]);
            Elements[i] = pval;
        }
    }
}

// @0x142968560
void ArrayObject::MakeDeepCopyFrom(MemoryHeap* pheap, const ArrayObject& ao)
{
    Elements.Resize(ao.Elements.GetSize());
    for (UPInt i = 0, n = Elements.GetSize(); i < n; i++)
    {
        if (ao.Elements[i])
        {
            Value* pval = SF_HEAP_NEW(pheap) Value(*ao.Elements[i]);
            Elements[i] = pval;
        }
    }
}

// noinline: the exe calls it out of line from AsBroadcaster::RemoveListener.
// @0x14297d0d0
__declspec(noinline) void ArrayObject::RemoveElements(int start, int count)
{
    if (Elements.GetSize())
    {
        int i;
        for (i = 0; i < count; i++)
            delete Elements[start + i];
        for (i = start + count; i < (int)Elements.GetSize(); i++)
        {
            Elements[i - count] = Elements[i];
            Elements[i]         = 0;
        }
        Elements.Resize(Elements.GetSize() - count);
    }
}

// @0x14297e330
__declspec(noinline) void ArrayObject::Resize(int size)
{
    if (size < 0)
        size = 0;
    UPInt i;
    UPInt newSize = (UPInt)size;
    UPInt oldSize = Elements.GetSize();
    for (i = newSize; i < oldSize; i++)
        delete Elements[i];
    Elements.Resize(newSize);
    for (i = oldSize; i < newSize; i++)
        Elements[i] = 0;
}

// @0x14296f1b0
void ArrayObject::PopFront_Call()
{
    PopFront();
}

// @0x142961d40
bool AsBroadcaster::Initialize(ASStringContext* psc, ObjectInterface* pobj)
{
    InitializeProto(psc, pobj);
    return InitializeInstance(psc, pobj);
}

// noinline: Initialize tail-calls it.
// @0x142961ef0
__declspec(noinline) bool AsBroadcaster::InitializeInstance(ASStringContext* psc, ObjectInterface* pobj)
{
    if (!pobj)
        return false;
    Ptr<ArrayObject> ao = *SF_HEAP_NEW(psc->GetHeap()) ArrayObject(psc);
    pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin__listeners), Value(ao), PropFlags::PropFlag_DontEnum);
    return true;
}

// The out-of-line copy of Value::ToObjectInterface (exe 0x142991810), which the header inlines.
ObjectInterface* Value_ToObjectInterface(const Value* pval, const Environment* penv);

// @0x14297d1e0
bool AsBroadcaster::RemoveListener(Environment* penv, ObjectInterface* pthis, ObjectInterface* plistener)
{
    if (!pthis || !plistener)
        return false;

    Value listeners;
    if (pthis->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin__listeners), &listeners))
    {
        Object* pobj = listeners.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object_Array)
        {
            Ptr<ArrayObject> parray = static_cast<ArrayObject*>(pobj);
            for (int i = (int)parray->GetSize() - 1; i >= 0; --i)
            {
                Value* pelem = parray->GetElementPtr(i);
                if (pelem && Value_ToObjectInterface(pelem, penv) == plistener)
                {
                    parray->RemoveElements(i, 1);
                    return true;
                }
            }
        }
    }
    return false;
}

// @0x142961fe0
bool AsBroadcaster::InitializeProto(ASStringContext* psc, ObjectInterface* pobj)
{
    if (!pobj)
        return false;
    NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    return true;
}

// @0x14296b820
void AvmCharacter::OnEventLoad()
{
    OnEvent(EventId::Event_Load);
}

// @0x14296bba0
void AvmCharacter::OnEventUnload()
{
}

__forceinline void ActionLogger::LogScriptMessageVarg(LogMessageId messageType, const char* pfmt, va_list argList)
{
    if (!pLog)
        return;
    if (UseSuffix)
    {
        char  fmtBuffer[256];
        UPInt len = strlen(pfmt);
        Format(StringDataPtr(fmtBuffer, sizeof(fmtBuffer)), "{0} : {1}\n",
               StringDataPtr(pfmt, (pfmt[len - 1] == '\n' ? len - 1 : len)), LogSuffix);
        pLog->LogMessageVarg(messageType, fmtBuffer, argList);
    }
    else
        pLog->LogMessageVarg(messageType, pfmt, argList);
}

// @0x142967d10
void ActionLogger::LogScriptError(const char* pfmt, ...)
{
    va_list argList;
    va_start(argList, pfmt);
    LogScriptMessageVarg(LogChannel_Script | LogMessage_Error, pfmt, argList);
    va_end(argList);
}

// @0x142968280
void ActionLogger::LogScriptWarning(const char* pfmt, ...)
{
    va_list argList;
    va_start(argList, pfmt);
    LogScriptMessageVarg(LogChannel_Script | LogMessage_Warning, pfmt, argList);
    va_end(argList);
}

// @0x142967fc0
void ActionLogger::LogScriptMessage(const char* pfmt, ...)
{
    va_list argList;
    va_start(argList, pfmt);
    LogScriptMessageVarg(LogChannel_Script | LogMessage_Text, pfmt, argList);
    va_end(argList);
}

// @0x142967e00
void Environment::LogScriptError(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    if (pASLogger)
        pASLogger->LogScriptMessageVarg(LogChannel_Script | LogMessage_Error, pfmt, argList);
    else if (Target->GetLog())
        Target->GetLog()->LogMessageVarg(LogChannel_Script | LogMessage_Error, pfmt, argList);
    va_end(argList);
}

// @0x142968370
void Environment::LogScriptWarning(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    if (pASLogger)
        pASLogger->LogScriptMessageVarg(LogChannel_Script | LogMessage_Warning, pfmt, argList);
    else if (Target->GetLog())
        Target->GetLog()->LogMessageVarg(LogChannel_Script | LogMessage_Warning, pfmt, argList);
    va_end(argList);
}

// @0x1429680b0
void Environment::LogScriptMessage(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    if (pASLogger)
        pASLogger->LogScriptMessageVarg(LogChannel_Script | LogMessage_Text, pfmt, argList);
    else if (Target->GetLog())
        Target->GetLog()->LogMessageVarg(LogChannel_Script | LogMessage_Text, pfmt, argList);
    va_end(argList);
}

// @0x142973040
bool ArrayObject::RecursionLimitReached_Call() const
{
    return RecursionLimitReached();
}

// Both operands are converted before the store (the inline Mul converts the right one first).
// @0x142968f90
void Value::Mul_Call(Environment* penv, const Value& v)
{
    Number lhs = ToNumber(penv);
    Number rhs = v.ToNumber(penv);
    SetNumber(lhs * rhs);
}

// @0x142965c80
bool IsLeapYear(int y)
{
    return 0 == (y % 4) && ((y % 100) || 0 == (y % 400));
}

// @0x142965db0
bool IsRectValid(const ASRect& r)
{
    return !NumberUtil::IsNaN(r.x1) && !NumberUtil::IsNaN(r.y1) && !NumberUtil::IsNaN(r.x2) &&
           !NumberUtil::IsNaN(r.y2);
}

// @0x1429623a0
bool Object::InstanceOf(Environment* penv, const Object* prototype, bool inclInterfaces) const
{
    for (const Object* proto = this; proto != 0; proto = proto->pProto)
    {
        if (inclInterfaces)
        {
            if (proto->DoesImplement(penv, prototype))
                return true;
        }
        else
        {
            if (proto == prototype)
                return true;
        }
    }
    return false;
}

// @0x142965510
bool CFunctionObject::IsEqual(const FunctionObject& f) const
{
    return f.IsCFunction() && pFunction == static_cast<const CFunctionObject&>(f).pFunction;
}

// @0x142965d10
bool Environment::IsPath(const ASString& varPath)
{
    if (varPath.GetHashFlags() & ASString::Flag_PathCheck)
        return 1;
    const char* pstr = varPath.ToCStr();
    if (strchr(pstr, ':') != 0 || strchr(pstr, '/') != 0 || strchr(pstr, '.') != 0)
    {
        varPath.SetPathFlags(ASString::Flag_PathCheck | 0);
        return 1;
    }
    else
    {
        varPath.SetPathFlags(ASString::Flag_PathCheck | ASString::Flag_IsNotPath);
        return 0;
    }
}

// @0x142967390
Value* Environment::LocalRegisterPtr(unsigned reg)
{
    if (reg >= LocalRegister.GetSize())
    {
        LogError("Invalid local register %d, stack only has %d entries", reg, (int)LocalRegister.GetSize());
        return &GlobalRegister[0];
    }
    return &LocalRegister[LocalRegister.GetSize() - reg - 1];
}

// @0x142972410
void Environment::PushTryBlock(const TryDescr& descr)
{
    TryBlocks.PushBack(descr);
}

// MS2-FUNCTIONAL instruction scheduling (the exe loads the size before the array address)
// @0x14296f390
Environment::TryDescr Environment::PopTryBlock()
{
    return TryBlocks.Pop();
}


// MS2-FUNCTIONAL register choice: the exe keeps the builtin offset in edx and adds the table base to it.
// @0x14296f770
Value Environment::PrimitiveToTempObject(int index)
{
    ASBuiltinType ctorName;

    const Value& top = Top(index);
    switch (top.GetType())
    {
    case Value::BOOLEAN:
        ctorName = ASBuiltin_Boolean;
        break;
    case Value::STRING:
        ctorName = ASBuiltin_String;
        break;
    default:
        if (top.IsNumber())
            ctorName = ASBuiltin_Number;
        else
            return Value();
    }

    Ptr<Object> obj = *OperatorNew(GetBuiltin(ctorName), 1, GetTopIndex() - index);
    return Value(obj);
}

// @0x14296f640
Value Environment::PrimitiveToTempObject(const Value& v)
{
    ASBuiltinType ctorName;

    switch (v.GetType())
    {
    case Value::BOOLEAN:
        ctorName = ASBuiltin_Boolean;
        break;
    case Value::STRING:
        ctorName = ASBuiltin_String;
        break;
    default:
        if (v.IsNumber())
            ctorName = ASBuiltin_Number;
        else
            return Value();
    }

    Push(v);
    Ptr<Object> obj = *OperatorNew(GetBuiltin(ctorName), 1, GetTopIndex());
    Drop1();
    return Value(obj);
}


// @0x14296e790
int MovieRoot::ParseLevelName(const char* pname, const char** ptail, bool caseSensitive)
{
    if (pname[0] >= '0' && pname[0] <= '9')
    {
        char* pend = 0;
        int   level = (int)strtol(pname, &pend, 10);
        *ptail    = pend;
        return level;
    }
    if (!pname || pname[0] != '_')
        return -1;

    if (caseSensitive)
    {
        if (pname[1] != 'l' || pname[2] != 'e' || pname[3] != 'v' || pname[4] != 'e' || pname[5] != 'l')
            return -1;
    }
    else
    {
        if ((pname[1] != 'l' && pname[1] != 'L') || (pname[2] != 'e' && pname[2] != 'E') ||
            (pname[3] != 'v' && pname[3] != 'V') || (pname[4] != 'e' && pname[4] != 'E') ||
            (pname[5] != 'l' && pname[5] != 'L'))
            return -1;
    }
    if (pname[6] < '0' || pname[6] > '9')
        return -1;

    char* pend  = 0;
    int   level = (int)strtol(pname + 6, &pend, 10);
    *ptail    = pend;
    return level;
}


// noinline: CFunctionObject::Invoke calls it out of line.
// @0x14297dfb0
__declspec(noinline) void SuperObject::ResetAltProto()
{
    if (!SavedProto)
        return;
    SuperProto = SavedProto;
    SavedProto = 0;
    pProto     = SuperProto;
}


// MS2-FUNCTIONAL the exe inlines the hash FindAlt (calling findIndexAlt out of line); ours keeps FindAlt out of line.
// @0x14297c970
bool GlobalContext::RegisterClassA(ASStringContext* psc, const ASString& className, const FunctionRef& ctorFunction)
{
    RegisteredClasses.SetCaseCheck(className, ctorFunction, psc->IsCaseSensitive());
    return true;
}


// @0x14295e1b0
void GASPrototypeBase::Init(Object* pthis, ASStringContext* psc, const FunctionRef& constructor)
{
    SetConstructor(pthis, psc, constructor);
    Constructor->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_prototype), Value(pthis),
                              PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete);
}


// MS2-FUNCTIONAL the exe inlines the CFunctionObject ctor (sfr_as2_03)
// @0x142961830
void GASPrototypeBase::InitFunctionMembers(Object* pthis, ASStringContext* psc, const NameFunction* table,
                                           const PropFlags& flags)
{
    Ptr<Object> pfuncProto = psc->pContext->GetPrototype(ASBuiltin_Function);
    for (UPInt i = 0; table[i].Name; i++)
    {
        FunctionRef func(*SF_HEAP_NEW(psc->GetHeap()) CFunctionObject(psc, pfuncProto, table[i].Function));
        pthis->SetMemberRaw(psc, psc->CreateConstString(table[i].Name), Value(func), flags);
    }
}


// @0x142962bb0
void CFunctionObject::Invoke(const FnCall& fn, LocalFrame*, const char*)
{
    if (!pFunction)
        return;
    ObjectInterface* pthis = fn.ThisPtr;
    if (pthis && pthis->IsSuper())
    {
        ObjectInterface* prealThis = static_cast<SuperObject*>(pthis)->RealThis;
        FnCall           fn2(fn.Result, prealThis, fn.Env, fn.NArgs, fn.FirstArgBottomIndex);
        pFunction(fn2);
        static_cast<SuperObject*>(pthis)->ResetAltProto();
    }
    else
        pFunction(fn);
}


// @0x142963aa0
void UserDefinedFunctionObject::Invoke(const FnCall& fn, LocalFrame*, const char*)
{
    if (!pContext)
        return;
    ObjectInterface* pthis = fn.ThisPtr;
    if (pthis && pthis->IsSuper())
    {
        ObjectInterface* prealThis = static_cast<SuperObject*>(pthis)->RealThis;
        FnCall           fn2(fn.Result, prealThis, fn.Env, fn.NArgs, fn.FirstArgBottomIndex);
        InvokeImpl(fn2);
        static_cast<SuperObject*>(pthis)->ResetAltProto();
    }
    else
        InvokeImpl(fn);
}

// Built-in class registration: the constructor function, its prototype stored in the context's prototype table
// (the table takes over the passed reference) and the constructor published as a member of the global object or
// of a package object.

static SF_FORCEINLINE void SetBuiltinPrototype(GlobalContext* pgc, ASBuiltinType type, Object* proto)
{
    ::FUN_14000c280(pgc, type, reinterpret_cast<void**>(&proto));
}

// The common registration: a CtorFunctionType constructor, a ProtoType prototype on the parent type's prototype,
// the constructor published under the type's name in ptarget.
template<class CtorFunctionType, class ProtoType>
static SF_FORCEINLINE FunctionRef RegisterBuiltinClass(GlobalContext* pgc, ASBuiltinType type, ASBuiltinType parentType,
                                               Object* ptarget)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) CtorFunctionType(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) ProtoType(&sc, pgc->GetPrototype(parentType), ctor);
    SetBuiltinPrototype(pgc, type, proto);
    ptarget->SetMemberRaw(&sc, sc.GetBuiltin(type), Value(ctor));
    return ctor;
}

// The filter classes derive from BitmapFilter: it is registered first unless the registry knows the name.
static SF_FORCEINLINE void RegisterBitmapFilterBase(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    if (!pgc->GetBuiltinClassRegistrar(sc.GetBuiltin(ASBuiltin_BitmapFilter)))
        BitmapFilterCtorFunction::Register(pgc);
}

// MS2-FUNCTIONAL the exe inlines the BooleanCtorFunction and BooleanProto ctors (sfr_as2_03)
// @0x1429752b0
FunctionRef BooleanCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) BooleanCtorFunction(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) BooleanProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_Boolean, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Boolean), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL the exe inlines the AmpMarkerCtorFunction and AmpMarkerProto ctors (sfr_as2_03)
// @0x142973080
FunctionRef AmpMarkerCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<AmpMarkerCtorFunction, AmpMarkerProto>(pgc, ASBuiltin_Amp, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the AsBroadcasterCtorFunction and AsBroadcasterProto ctors (sfr_as2_03)
// @0x142973a80
FunctionRef AsBroadcasterCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<AsBroadcasterCtorFunction, AsBroadcasterProto>(pgc, ASBuiltin_AsBroadcaster, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the BevelFilterCtorFunction and BevelFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142973f20
FunctionRef BevelFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<BevelFilterCtorFunction, BevelFilterProto>(pgc, ASBuiltin_BevelFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the BitmapDataCtorFunction and BitmapDataProto ctors (sfr_as2_03)
// @0x142974460
FunctionRef BitmapDataCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<BitmapDataCtorFunction, BitmapDataProto>(pgc, ASBuiltin_BitmapData, ASBuiltin_Object, pgc->FlashDisplayPackage);
}

// MS2-FUNCTIONAL the exe inlines the BitmapFilterCtorFunction and BitmapFilterProto ctors (sfr_as2_03)
// @0x142974910
FunctionRef BitmapFilterCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<BitmapFilterCtorFunction, BitmapFilterProto>(pgc, ASBuiltin_BitmapFilter, ASBuiltin_Object, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the BlurFilterCtorFunction and BlurFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142974d70
FunctionRef BlurFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<BlurFilterCtorFunction, BlurFilterProto>(pgc, ASBuiltin_BlurFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the ColorMatrixFilterCtorFunction and ColorMatrixFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x1429763c0
FunctionRef ColorMatrixFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<ColorMatrixFilterCtorFunction, ColorMatrixFilterProto>(pgc, ASBuiltin_ColorMatrixFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the DateCtorFunction and DateProto ctors (sfr_as2_03)
// @0x142976be0
FunctionRef DateCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<DateCtorFunction, DateProto>(pgc, ASBuiltin_Date, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the DropShadowFilterCtorFunction and DropShadowFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142977070
FunctionRef DropShadowFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<DropShadowFilterCtorFunction, DropShadowFilterProto>(pgc, ASBuiltin_DropShadowFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the GASLoadVarsLoaderCtorFunction ctor (sfr_as2_03)
// @0x142977ad0
FunctionRef GASLoadVarsLoaderCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<GASLoadVarsLoaderCtorFunction, LoadVarsProto>(pgc, ASBuiltin_LoadVars, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the GlowFilterCtorFunction and GlowFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142978240
FunctionRef GlowFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<GlowFilterCtorFunction, GlowFilterProto>(pgc, ASBuiltin_GlowFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the MovieClipLoaderCtorFunction and MovieClipLoaderProto ctors (sfr_as2_03)
// @0x142978dd0
FunctionRef MovieClipLoaderCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<MovieClipLoaderCtorFunction, MovieClipLoaderProto>(pgc, ASBuiltin_MovieClipLoader, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the PointCtorFunction and PointProto ctors (sfr_as2_03)
// @0x1429797e0
FunctionRef PointCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<PointCtorFunction, PointProto>(pgc, ASBuiltin_Point, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the SharedObjectCtorFunction and SharedObjectProto ctors (sfr_as2_03)
// @0x14297a4a0
FunctionRef SharedObjectCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<SharedObjectCtorFunction, SharedObjectProto>(pgc, ASBuiltin_SharedObject, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the StringCtorFunction and StringProto ctors (sfr_as2_03)
// @0x14297aca0
FunctionRef StringCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<StringCtorFunction, StringProto>(pgc, ASBuiltin_String, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the TextSnapshotCtorFunction and TextSnapshotProto ctors (sfr_as2_03)
// @0x14297bf80
FunctionRef TextSnapshotCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<TextSnapshotCtorFunction, TextSnapshotProto>(pgc, ASBuiltin_TextSnapshot, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the ColorTransformCtorFunction ctor
// @0x142976900
FunctionRef ColorTransformCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ColorTransformCtorFunction, ColorTransformProto>(pgc, ASBuiltin_ColorTransform, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the RectangleCtorFunction ctor
// @0x142979d00
FunctionRef RectangleCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<RectangleCtorFunction, RectangleProto>(pgc, ASBuiltin_Rectangle, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the TransformCtorFunction ctor
// @0x14297c400
FunctionRef TransformCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<TransformCtorFunction, TransformProto>(pgc, ASBuiltin_Transform, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the GASMatrixCtorFunction and MatrixProto ctors (sfr_as2_03)
// @0x142977db0
FunctionRef GASMatrixCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<GASMatrixCtorFunction, MatrixProto>(pgc, ASBuiltin_Matrix, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the ColorCtorFunction and ColorProto ctors (sfr_as2_03)
// @0x142975f30
FunctionRef ColorCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ColorCtorFunction, ColorProto>(pgc, ASBuiltin_Color, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the ButtonCtorFunction and ButtonProto ctors (sfr_as2_03)
// @0x142975740
FunctionRef ButtonCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ButtonCtorFunction, ButtonProto>(pgc, ASBuiltin_Button, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the ArrayCtorFunction and ArrayProto ctors (sfr_as2_03)
// @0x142973500
FunctionRef ArrayCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ArrayCtorFunction, ArrayProto>(pgc, ASBuiltin_Array, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the ExternalInterfaceCtorFunction and ExternalInterfaceProto ctors (sfr_as2_03)
// @0x1429775b0
FunctionRef ExternalInterfaceCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ExternalInterfaceCtorFunction, ExternalInterfaceProto>(pgc, ASBuiltin_ExternalInterface, ASBuiltin_Object,
                                                                                      pgc->FlashExternalPackage);
}

// MS2-FUNCTIONAL the exe inlines the NumberCtorFunction and NumberProto ctors (sfr_as2_03)
// @0x142979260
FunctionRef NumberCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<NumberCtorFunction, NumberProto>(pgc, ASBuiltin_Number, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the SelectionCtorFunction ctor (sfr_as2_03)
// @0x142979fe0
FunctionRef SelectionCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<SelectionCtorFunction, SelectionProto>(pgc, ASBuiltin_Selection, ASBuiltin_Object, pgc->pGlobal);
}

// MovieImpl keeps one MouseState per mouse (4, 0x50 bytes each) at +0x1260, not recovered in gfx_movieimpl.h
// yet; null past the last one (the exe still reads through it).
static inline const MouseState* GetMovieMouseState(MovieImpl* proot, unsigned mouseIndex)
{
    if (mouseIndex >= 4)
        return 0;
    return reinterpret_cast<const MouseState*>(reinterpret_cast<const UByte*>(proot) + 0x1260) + mouseIndex;
}

// @0x14296cb80
void MouseCtorFunction::OnMouseMove(Environment* penv, unsigned mouseIndex) const
{
    NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseMove);
}

// @0x14296c220
void MouseCtorFunction::OnMouseDown(Environment* penv, unsigned mouseIndex, unsigned button,
                                    InteractiveObject* ptarget) const
{
    bool dblClick = false;
    if (penv->CheckExtensions())
    {
        UInt32 ticks = (UInt32)(Timer::GetTicks() / 1000);
        Render::PointF pos = GetMovieMouseState(penv->GetTarget()->GetMovieImpl(), mouseIndex)->GetLastPosition();
        SInt32 x = (SInt32)Render::TwipsToPixels(pos.x);
        SInt32 y = (SInt32)Render::TwipsToPixels(pos.y);
        // A second click within 300 ms at the same pixel.
        if (ticks <= LastClickTime + 300 && LastMousePos[0] == x && LastMousePos[1] == y)
            dblClick = true;
        LastMousePos[0] = x;
        LastMousePos[1] = y;
        LastClickTime   = ticks;
    }
    if (ptarget)
    {
        ASString path = ptarget->GetCharacterHandle()->NamePath;
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseDown, &path, button, 0, dblClick);
    }
    else
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseDown, 0, button, 0, dblClick);
}

// @0x14296cbf0
void MouseCtorFunction::OnMouseUp(Environment* penv, unsigned mouseIndex, unsigned button,
                                  InteractiveObject* ptarget) const
{
    if (ptarget)
    {
        ASString path = ptarget->GetCharacterHandle()->NamePath;
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseUp, &path, button);
    }
    else
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseUp, 0, button);
}

// @0x14296cd30
void MouseCtorFunction::OnMouseWheel(Environment* penv, unsigned mouseIndex, int sdelta,
                                     InteractiveObject* ptarget) const
{
    if (ptarget)
    {
        ASString path = ptarget->GetCharacterHandle()->NamePath;
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseWheel, &path, 0, sdelta);
    }
    else
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseWheel, 0, 0, sdelta);
}

bool MouseCtorFunction::IsEmpty() const
{
    return pListenersArray && pListenersArray->GetSize() == 0;
}

// @0x142969450
void MouseCtorFunction::NotifyListeners(Environment* penv, unsigned mouseIndex, ASBuiltinType eventName,
                                        const ASString* ptargetName, unsigned button, int delta,
                                        bool dblClick) const
{
    LocalInvokeCallback callback(mouseIndex, eventName, ptargetName, button, delta, dblClick);
    AsBroadcaster::BroadcastMessageWithCallback(penv, const_cast<MouseCtorFunction*>(this),
                                                penv->GetBuiltin(eventName), &callback);
}

// MS2-FUNCTIONAL frame layout (exe keeps an rbp frame) and register allocation
// @0x142963400
void MouseCtorFunction::LocalInvokeCallback::Invoke(Environment* penv, ObjectInterface* pthis,
                                                    const FunctionRef& method)
{
    int nargs = PushListenersParams(penv, MouseIndex, EventName, Value(method), pTargetName, Button, Delta,
                                    DblClick);
    if (nargs < 0)
        return;
    Value result;
    method.Invoke(FnCall(&result, pthis, penv, nargs, penv->GetTopIndex()));
    penv->Drop(nargs);
}

// MS2-FUNCTIONAL event compare folding and FunctionRef temporary scheduling
// @0x142971d70
int MouseCtorFunction::PushListenersParams(Environment* penv, unsigned mouseIndex, ASBuiltinType eventName,
                                           const Value& method, const ASString* ptargetName, unsigned button,
                                           int delta, bool dblClick)
{
    int  nargs     = 0;
    // Without extensions (or for a method taking no arguments) only the standard arguments.
    bool noExtArgs = !penv->CheckExtensions();
    if (penv->CheckExtensions() && button != 0 &&
        (eventName == ASBuiltin_onMouseDown || eventName == ASBuiltin_onMouseUp))
    {
        // An extended button other than the left one only reaches methods that declare arguments.
        FunctionRef func = method.ToFunction(penv);
        if (func.IsNull())
            return -1;
        if (func->GetNumArgs() <= 0)
        {
            if (button > 1)
                return -1;
            noExtArgs = true;
        }
    }
    if (penv->CheckExtensions() && !noExtArgs)
    {
        if (eventName == ASBuiltin_onMouseDown && dblClick)
        {
            penv->Push(dblClick);
            nargs = 1;
        }
        Render::PointF pos = GetMovieMouseState(penv->GetTarget()->GetMovieImpl(), mouseIndex)->GetLastPosition();
        penv->Push(Number(Render::TwipsToPixels(floor(pos.y + 0.5))));
        penv->Push(Number(Render::TwipsToPixels(floor(pos.x + 0.5))));
        penv->Push(Value((int)mouseIndex));
        nargs += 3;
    }
    if (eventName != ASBuiltin_onMouseMove)
    {
        if (ptargetName && (eventName == ASBuiltin_onMouseWheel || !noExtArgs))
        {
            penv->Push(*ptargetName);
            ++nargs;
        }
        else if (nargs)
        {
            penv->Push(Value(Value::NULLTYPE));
            ++nargs;
        }
    }
    if (eventName == ASBuiltin_onMouseDown || eventName == ASBuiltin_onMouseUp)
    {
        if (button && !noExtArgs)
        {
            penv->Push(Number(button));
            ++nargs;
        }
        else if (nargs)
        {
            penv->Push(Value(Value::NULLTYPE));
            ++nargs;
        }
    }
    else if (eventName == ASBuiltin_onMouseWheel)
    {
        penv->Push(Value(delta));
        ++nargs;
    }
    return nargs;
}

// MS2-FUNCTIONAL the exe inlines the MathProto ctor (sfr_as2_03)
// @0x142978780
FunctionRef MathCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<MathCtorFunction, MathProto>(pgc, ASBuiltin_Math, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the MouseProto ctor (sfr_as2_03)
// @0x142978a90
FunctionRef MouseCtorFunction::Register(GlobalContext* pgc)
{
    // As RegisterBuiltinClass, but the class also becomes the movie's mouse listener.
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap)
                             MouseCtorFunction(&sc, static_cast<MovieRoot*>(pgc->pMovieRoot->pASMovieRoot)));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) MouseProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_Mouse, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Mouse), Value(ctor));
    return ctor;
}

// @0x14295d1c0
void TransformCtorFunction::GlobalCtor(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    InteractiveObject* ptarget = fn.Env->FindTargetByValue(fn.Arg(0));
    if (!ptarget)
    {
        fn.Result->SetUndefined();
        return;
    }
    Ptr<TransformObject> ptransform;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_Transform && !fn.ThisPtr->IsBuiltinPrototype())
        ptransform = static_cast<TransformObject*>(fn.ThisPtr);
    else
        ptransform = *SF_HEAP_NEW(fn.Env->GetHeap()) TransformObject(fn.Env);
    ptransform->SetTarget(ptarget);
    fn.Result->SetAsObject(ptransform.GetPtr());
}

// @0x142969040
bool Environment::NeedTermination(int execType) const
{
    if ((execType == ActionBuffer::Exec_Unknown || execType == ActionBuffer::Exec_Function) && Target->IsUnloading())
        return true;
    if (Target->IsUnloaded())
        return true;
    return false;
}

// MS2-FUNCTIONAL the exe reads the string node flags as bit-fields (shift and test)
// @0x142965e50
bool AvmCharacter::IsStandardMember(const ASString& memberName, ASString* plowerCaseName)
{
    if (memberName.GetHashFlags() & ASConstString::Flag_StandardMember)
        return true;
    if (memberName.GetLength() == 0 || memberName.GetCharAt(0) != '_')
        return false;
    ASString lower(memberName.ToLowerNode());
    if (!(lower.GetHashFlags() & ASConstString::Flag_CaseInsensitive))
        return false;
    if (plowerCaseName)
        *plowerCaseName = lower;
    return true;
}

// MS2-FUNCTIONAL the exe calls the event handler hash lookup out of line
// @0x14295d450
__declspec(noinline) bool AvmCharacter::HasClipEventHandler(const EventId& id) const
{
    EventId key = (id.Id == EventId::Event_KeyDown || id.Id == EventId::Event_KeyUp) ? EventId(id.Id) : id;
    return EventHandlers.Get(key) != 0;
}

// MS2-FUNCTIONAL the exe calls the event handler hash lookup out of line
// @0x142964200
bool AvmCharacter::InvokeClipEventHandlers(Environment* penv, const EventId& id)
{
    EventId key = (id.Id == EventId::Event_KeyDown || id.Id == EventId::Event_KeyUp) ? EventId(id.Id) : id;
    const ArrayLH<Value, StatMV_ActionScript_Mem>* phandlers = EventHandlers.Get(key);
    if (!phandlers)
        return false;
    for (UPInt i = 0, n = phandlers->GetSize(); i < n; i++)
        GAS_Invoke((*phandlers)[i], 0, this, penv, 0, penv->GetTopIndex() + 1, 0);
    return true;
}

// The out-of-line resizes Reset calls (COMDATs where cl inlines them): the register array (exe 0x14297e0e0) and
// the frame array's shrink (exe 0x14297e450).
void LocalRegister_Resize(ArrayLH<Value, Stat_Default_Mem>* pregs, UPInt newSize);
void LocalFrames_ResizeNoConstruct(ArrayLH<Ptr<LocalFrame>, Stat_Default_Mem>* pframes, const void* pheapAddr,
                                   UPInt newSize);

// @0x14297dd70
void Environment::Reset()
{
    Stack.Reset();
    for (unsigned i = 0; i < 4; i++)
        GlobalRegister[i].SetUndefined();
    LocalRegister_Resize(&LocalRegister, 0);
    Unrolling       = false;
    IsInvalidTarget = false;
    CallStack.Reset();
    LocalFrames_ResizeNoConstruct(&LocalFrames, &LocalFrames, 0);
    FuncCallNestingLevel = 0;
    TryBlocks_Resize(&TryBlocks, 0);
    ThrowingValue.SetUndefined();
}

inline MovieRoot::ActionEntry::ActionEntry()
{
    pNextEntry    = 0;
    Type          = Entry_None;
    pActionBuffer = 0;
    SessionId     = 0;
}

inline MovieRoot::ActionEntry* MovieRoot::ActionQueueType::GetNewEntry()
{
    ActionEntry* pentry;
    if (pFreeEntry)
    {
        pentry             = pFreeEntry;
        pFreeEntry         = pentry->pNextEntry;
        pentry->pNextEntry = 0;
        --FreeEntriesCount;
    }
    else
    {
        pentry = (ActionEntry*)SF_HEAP_ALLOC(pHeap, sizeof(ActionEntry), 0);
        if (!pentry)
            return 0;
        ::new (pentry) ActionEntry;
    }
    return pentry;
}

// MS2-FUNCTIONAL the exe keeps the level's address in a register (cl indexes it; the inlined copy matches)
// @0x1429621f0
MovieRoot::ActionEntry* MovieRoot::ActionQueueType::InsertEntry(ActionPriority::Priority prio)
{
    ActionEntry* pentry = GetNewEntry();
    if (!pentry)
        return 0;
    Level& level = Levels[prio];
    if (!level.pInsertEntry)
    {
        pentry->pNextEntry = level.pActionRoot;
        level.pActionRoot  = pentry;
    }
    else
    {
        pentry->pNextEntry              = level.pInsertEntry->pNextEntry;
        level.pInsertEntry->pNextEntry = pentry;
    }
    level.pInsertEntry = pentry;
    if (!pentry->pNextEntry)
        level.pLastEntry = pentry;
    pentry->SessionId = Field_a0;
    ++ModId;
    return pentry;
}

// @0x1429620d0
MovieRoot::ActionEntry* MovieRoot::InsertEmptyAction(ActionPriority::Priority prio)
{
    return GetActionQueue().InsertEntry(prio);
}

// MoveTo starts a new path at the point (the open one ends without a new shape); LineTo adds a line to it.
// @0x142968f00
void AvmSprite::MoveTo(float x, float y)
{
    DrawingContext* pdc = AcquirePath(false);
    pdc->MoveTo(Render::PixelsToTwips(x), Render::PixelsToTwips(y));
    GetSprite()->InvalidateHitResult();
}

// @0x142966370
void AvmSprite::LineTo(float x, float y)
{
    DrawingContext* pdc = GetDrawingContext();
    pdc->LineTo(Render::PixelsToTwips(x), Render::PixelsToTwips(y));
    GetSprite()->InvalidateHitResult();
}


// @0x142961b40
void AvmCharacter::InitStandardMembers(GlobalContext* pgc)
{
    ASStringManager* psm = static_cast<MovieRoot*>(pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->pStringManager;
    pgc->StandardMemberMap.SetCapacity(117);
    for (const MemberTableType* pentry = MemberTable; pentry->pName; pentry++)
    {
        ASString name(psm->CreateConstString(pentry->pName, strlen(pentry->pName),
            pentry->CaseInsensitive ? (ASString::Flag_StandardMember | ASString::Flag_CaseInsensitive)
                                    : ASString::Flag_StandardMember));
        pgc->StandardMemberMap.Add(name, (char)pentry->Id);
    }
}

// @0x142961c40
void GlobalContext::InitStandardMembers()
{
    StandardMemberMap.Clear();
    AvmCharacter::InitStandardMembers(this);
}

// @0x14297d030
void AvmCharacter::RemoveDisplayObject()
{
    InteractiveObject* pparent = pDispObj->GetParent();
    if (!pparent)
        return;
    Sprite* psprite = pparent->IsSprite() ? static_cast<Sprite*>(pparent) : 0;
    if (psprite)
        psprite->RemoveDisplayObject(pDispObj->Depth, ResourceId(pDispObj->Id));
}

// @0x142962310
bool AvmCharacter::InstanceOf(Environment* penv, const Object* prototype, bool inclInterfaces) const
{
    Ptr<Object> obj = GetASObject();
    if (!obj)
        return false;
    return obj->InstanceOf(penv, prototype, inclInterfaces);
}

// @0x14296aa90
void AvmSprite::OnAddedDisplayObject(InteractiveObject* ch, unsigned sessionId, bool placeObject)
{
    Sprite* psprite = ch->IsSprite() ? static_cast<Sprite*>(ch) : 0;
    if (!placeObject)
    {
        GetAS2Root()->DoActionsForSession(sessionId);
        if (psprite && psprite->HasEventHandler(EventId(EventId::Event_Load)))
            psprite->Flags |= Sprite::Flags_OnLoadReqd;
    }
    else if (psprite)
        psprite->Flags |= Sprite::Flags_OnLoadReqd;
}

// MS2-FUNCTIONAL the MovieRoot vftable is not modeled: DoActions is called directly (the exe goes through slot 7)
// @0x14297d460
bool AvmSprite::ReplaceChildCharacterOnLoad(InteractiveObject* poldChar, InteractiveObject* pnewChar)
{
    if (!ReplaceChildCharacter(poldChar, pnewChar))
        return false;
    pnewChar->OnEventLoad();
    GetAS2Root()->MovieRoot::DoActions();
    return true;
}

// @0x1429659e0
bool AvmTextField::IsFocusEnabled(FocusMovedType fmt) const
{
    if (fmt == GFx_FocusMovedByMouse)
    {
        if (reinterpret_cast<TextField*>(pDispObj)->IsReadOnly() &&
            !reinterpret_cast<TextField*>(pDispObj)->IsSelectable())
            return false;
    }
    return true;
}

// @0x142962b30
bool AvmSprite::Invoke(const char* methodName, Value* presult, unsigned numArgs)
{
    Ptr<Sprite> psprite = GetSprite(); // kept alive across the call
    return GAS_Invoke(methodName, presult, this, reinterpret_cast<Environment*>(Unrecovered_38), numArgs,
                      reinterpret_cast<Environment*>(Unrecovered_38)->GetTopIndex());
}

// @0x142963fc0
bool AvmSprite::InvokeArgs(const char* methodName, Value* presult, const char* methodArgFmt, va_list args)
{
    Ptr<Sprite> psprite = GetSprite();
    return GAS_InvokeParsed(methodName, presult, this, reinterpret_cast<Environment*>(Unrecovered_38), methodArgFmt,
                            args);
}

// A sprite with an onEnterFrame handler has to stay in the playlist.
// @0x14295d4f0
bool AvmSprite::HasEventHandler(const EventId& id) const
{
    if (HasClipEventHandler(id))
        return true;
    ASBuiltinType btype = EventId_GetFunctionNameBuiltinType(id);
    ASString      method(GetAS2Root()->GetStringManager()->GetBuiltin(btype));
    if (!method.IsEmpty())
    {
        Object* pclipObj = *reinterpret_cast<Object* const*>(&Unrecovered_38[0x1d8 - 0x38]);
        Value   v;
        Object* pobj = pclipObj ? pclipObj : Get__proto__();
        if (pobj)
        {
            Environment* penv = reinterpret_cast<Environment*>(const_cast<UByte*>(Unrecovered_38));
            if (pobj->GetMemberRaw(penv->GetSC(), method, &v))
                return true;
        }
    }
    return false;
}

// @0x142969000
bool AvmSprite::MustBeInPlaylist() const
{
    return static_cast<const AvmCharacter*>(this)->HasEventHandler(EventId(EventId::Event_EnterFrame));
}

// The sprite child at ch's depth that is ch itself leaves the display list; false when it is not there.
// @0x14297cf70
bool AvmSprite::RemoveCharacter(DisplayObjectBase* ch)
{
    Sprite* psprite = GetSprite();
    int     depth   = ch->Depth;
    UPInt   size    = psprite->mDisplayList.GetCount();
    UPInt   index   = psprite->mDisplayList.FindDisplayIndex(depth);
    if (index >= size)
        return false;
    // Several entries can share the depth: look for ch among them.
    DisplayObjectBase* pch = psprite->mDisplayList.GetDisplayObject(index);
    while (pch && pch != ch && depth == pch->Depth && index + 1 < size)
        pch = psprite->mDisplayList.GetDisplayObject(++index);
    if (index >= size || pch != ch)
        return false;
    psprite->mDisplayList.RemoveEntryAtIndex(psprite, index);
    return true;
}

// The script side of a button (only the unload hook here; sfr_as2_04 has the clone hooks).
class AvmButton : public AvmCharacter
{
public:
    virtual bool OnUnloading(bool mayRemove);
};

// Buttons and text fields unload at once, leaving the playlist.
// @0x14296d120
bool AvmButton::OnUnloading(bool)
{
    GetDispObj()->RemoveFromPlayList();
    return true;
}

// @0x14296d310
bool AvmTextField::OnUnloading(bool)
{
    GetDispObj()->RemoveFromPlayList();
    return true;
}

// MS2-FUNCTIONAL BroadcastMessage and the Rectangle creation are calls here; the exe inlines both
// @0x14296a540
void StageCtorFunction::NotifyOnResize(Environment* penv)
{
    if (penv->GetSC()->pContext->CheckExtensions())
    {
        Render::RectF rect = penv->GetTarget()->GetMovieImpl()->AsMovieInterface()->GetVisibleFrameRect();
        Value         v    = CreateRectangleObject(penv, rect);
        penv->Push(v);
        AsBroadcaster::BroadcastMessage(penv, this, penv->CreateConstString("onResize"), 1, penv->GetTopIndex());
        penv->Drop1();
    }
    else
        AsBroadcaster::BroadcastMessage(penv, this, penv->CreateConstString("onResize"), 0, 0);
}

// @0x14296a7c0
void StageCtorFunction::NotifyOnResize(const FnCall& fn)
{
    Value stageCtorVal;
    if (fn.Env->GetSC()->pContext->pGlobal->GetMemberRaw(fn.Env->GetSC(), fn.Env->GetBuiltin(ASBuiltin_Stage),
                                                          &stageCtorVal) &&
        stageCtorVal.GetType() != Value::FUNCTIONNAME)
    {
        ObjectInterface* pobj = stageCtorVal.ToObject(fn.Env);
        if (pobj)
            static_cast<StageCtorFunction*>(pobj)->NotifyOnResize(fn.Env);
    }
}

// The environment of _level0 (MovieRoot::GetLevelMovie(0) inline).
// @0x1429635f0
bool MovieRoot::Invoke(InteractiveObject* pmovie, const char* pmethodName, GFx::Value* presult,
                       const GFx::Value* pargs, unsigned numArgs)
{
    if (!pmovie || pmovie->GetType() != CharacterDef::Sprite)
        return false;
    Value resultVal;
    AvmCharacter* pavmChar = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmovie->GetAvmObjImpl()));
    Environment*  penv     = pavmChar->GetASEnvironment();
    for (int i = (int)numArgs - 1; i >= 0; --i)
    {
        Value v;
        Value2ASValue(pargs[i], &v);
        penv->Push(v);
    }
    bool             retVal;
    InvokeAliasInfo* palias;
    if (*reinterpret_cast<void* const*>(Unrecovered_78) && (palias = ResolveInvokeAlias(pmethodName)) != 0)
        retVal = InvokeAlias(pmethodName, *palias, &resultVal, numArgs);
    else
    {
        AvmSprite*             pavmSprite = static_cast<AvmSprite*>(pavmChar);
        Ptr<InteractiveObject> holder     = pavmSprite->GetDispObj();
        Environment*           pspriteEnv = reinterpret_cast<Environment*>(pavmSprite->Unrecovered_38);
        retVal = GAS_Invoke(pmethodName, &resultVal, pavmSprite, pspriteEnv, numArgs, pspriteEnv->GetTopIndex());
    }
    for (unsigned n = numArgs; n; n--)
        penv->Drop1();
    if (retVal && presult)
        ASValue2GFxValue(penv, resultVal, presult);
    return retVal;
}

// The movie loaded as _level<level>, 0 if none.
static SF_FORCEINLINE InteractiveObject* GetMovieAtLevel(const MovieImpl* pmovieImpl, int level)
{
    for (unsigned i = 0; i < pmovieImpl->MovieLevelsSize; i++)
    {
        if (pmovieImpl->pMovieLevels[i].Level == level)
            return pmovieImpl->pMovieLevels[i].pSprite;
    }
    return 0;
}

// MS2-FUNCTIONAL the MovieRoot vftable is not modeled: the Invoke(InteractiveObject*, ...) slot differs (exe 0x1a0)
// @0x142963a10
bool MovieRoot::Invoke(const char* pmethodName, GFx::Value* presult, const GFx::Value* pargs, unsigned numArgs)
{
    return Invoke(GetMovieAtLevel(pMovieImpl, 0), pmethodName, presult, pargs, numArgs);
}

// @0x1429726a0
void ActionBufferData::Read(StreamContext* psc, unsigned eventLength)
{
    psc->Align();
    pBuffer = (UByte*)SF_HEAP_AUTO_ALLOC(this, eventLength);
    memcpy(pBuffer, psc->pData + psc->CurByteIndex, eventLength);
    BufferLen = eventLength;
    psc->Align();
    psc->CurByteIndex += eventLength;
}

// Queues Stage.onResize for the next action pass when there is a _level0.
// MS2-FUNCTIONAL register allocation of the two _level0 lookups differs
// @0x14296a450
void MovieRoot::NotifyOnResize()
{
    if (GetMovieAtLevel(pMovieImpl, 0))
    {
        ActionEntry* pe = InsertEmptyAction(ActionPriority::AP_Frame);
        if (pe)
        {
            InteractiveObject* plevel0 = GetMovieAtLevel(pMovieImpl, 0);
            pe->Type          = ActionEntry::Entry_CFunction;
            pe->pCharacter    = plevel0;
            pe->pActionBuffer = 0;
            pe->CFunction     = StageCtorFunction::NotifyOnResize;
        }
    }
}

static inline Environment* GetLevel0MovieEnvironment(MovieImpl* pmovieImpl)
{
    InteractiveObject* pmovie = 0;
    for (unsigned i = 0; i < pmovieImpl->MovieLevelsSize; i++)
    {
        if (pmovieImpl->pMovieLevels[i].Level == 0)
        {
            pmovie = pmovieImpl->pMovieLevels[i].pSprite;
            break;
        }
    }
    return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pmovie->GetAvmObjImpl()))->GetASEnvironment();
}

// MS2-FUNCTIONAL: queues the Selection CFunction with the recovered focus arguments through the environment helper.
// @0x14296a850
void MovieRoot::NotifyQueueSetFocus(InteractiveObject* ch, unsigned controllerIdx, FocusMovedType fmt)
{
    Selection::QueueSetFocus(GetLevel0MovieEnvironment(pMovieImpl), ch, controllerIdx, fmt);
}

// @0x14296a8f0
void MovieRoot::NotifyTransferFocus(InteractiveObject* curFocused, InteractiveObject* pnewFocus, unsigned controllerIdx)
{
    Selection::BroadcastOnSetFocus(GetLevel0MovieEnvironment(pMovieImpl), curFocused, pnewFocus, controllerIdx);
}

// @0x1429697f0
bool MovieRoot::NotifyOnFocusChange(InteractiveObject* curFocused, InteractiveObject* toBeFocused, unsigned,
                                    FocusMovedType fmt, ProcessFocusKeyInfo*)
{
    if (fmt == GFx_FocusMovedByMouse)
    {
        if ((!curFocused || !curFocused->IsFocusEnabled(fmt)) && (!toBeFocused || !toBeFocused->IsFocusEnabled(fmt)))
            return false;
    }
    return true;
}

// MS2-FUNCTIONAL the exe manually manages Value and refcounts around visitor callbacks; this retains the same
// parent assignment, stack ownership, and array/object state transitions through the recovered AS2 APIs.
// @0x1429718b0
void GASSharedObjectLoader::PushArray(const String& name)
{
    Object* object = pEnv->OperatorNew(pEnv->StringContext.pContext->pGlobal,
                                       pEnv->StringContext.GetBuiltin(ASBuiltin_Array), 0, -1);
    Object* parent = ObjectStack.Back();
    Value value(object);
    if (bArrayIsTop)
        static_cast<ArrayObject*>(parent)->PushBack(value);
    else
    {
        ASString memberName = pEnv->StringContext.CreateString(name.ToCStr(), name.GetSize());
        parent->SetMember(pEnv, memberName, value);
    }
    ObjectStack.PushBack(object);
    bArrayIsTop = true;
}

// MS2-FUNCTIONAL the exe manually handles Value and object refcounts around its visitor calls; this uses the
// recovered OperatorNew, SetMember, ArrayObject::PushBack, and Array storage APIs with the same state changes.
// @0x142972190
void GASSharedObjectLoader::PushObject(const String& name)
{
    Object* object = pEnv->OperatorNew(pEnv->StringContext.pContext->pGlobal,
                                       pEnv->StringContext.GetBuiltin(ASBuiltin_Object), 0, -1);
    Object* parent = ObjectStack.Back();
    Value value(object);
    if (bArrayIsTop)
        static_cast<ArrayObject*>(parent)->PushBack(value);
    else
    {
        ASString memberName = pEnv->StringContext.CreateString(name.ToCStr(), name.GetSize());
        parent->SetMember(pEnv, memberName, value);
    }
    ObjectStack.PushBack(object);
    bArrayIsTop = false;
}

// Back to the enclosing object; an array is on top again when it is one.
// @0x14296f260
void GASSharedObjectLoader::PopObject()
{
    ObjectPtrArray_Resize(&ObjectStack, ObjectStack.GetSize() - 1);
    bArrayIsTop = ObjectStack[ObjectStack.GetSize() - 1]->GetObjectType() == ObjectInterface::Object_Array;
}

// @0x14296f0c0
void GASSharedObjectLoader::PopArray()
{
    PopObject();
}

// The parser owns a temporary CSS buffer and writes parsed rules into the sheet's StyleManager.
class CSSFileLoaderAndParserImpl
{
public:
    UByte Unrecovered_08[0x10];
    wchar_t* Buffer;
    int BufferLen;

    virtual void Load(const String& fileName, FileOpener* opener);
    virtual void Init(Environment* penv, Object* sheet);
};

// MS2-FUNCTIONAL: opens the CSS file, reads its complete byte stream into an owned, terminated buffer, and closes it.
// @0x1429663d0
void CSSFileLoaderAndParserImpl::Load(const String& fileName, FileOpener* opener)
{
    Buffer = 0;
    BufferLen = 0;
    if (!opener)
        return;

    using OpenFileFn = void* (*)(FileOpener*, const char*, int, int);
    void** openerVtable = *reinterpret_cast<void***>(opener);
    void* file = reinterpret_cast<OpenFileFn>(openerVtable[1])(opener, fileName.ToCStr(), 0x21, 0x1b6);
    if (!file)
        return;

    void** fileVtable = *reinterpret_cast<void***>(file);
    using IsValidFn = bool (*)(void*);
    using GetLengthFn = int (*)(void*);
    using ReadFn = void (*)(void*, void*, unsigned);
    if (reinterpret_cast<IsValidFn>(fileVtable[2])(file))
    {
        BufferLen = reinterpret_cast<GetLengthFn>(fileVtable[6])(file);
        if (BufferLen)
        {
            Buffer = reinterpret_cast<wchar_t*>(Memory::GetGlobalHeap()->Alloc(UPInt(BufferLen) + 2));
            if (Buffer)
            {
                reinterpret_cast<ReadFn>(fileVtable[10])(file, Buffer, unsigned(BufferLen));
                reinterpret_cast<UByte*>(Buffer)[BufferLen] = 0;
                reinterpret_cast<UByte*>(Buffer)[BufferLen + 1] = 0;
            }
            else
                BufferLen = 0;
        }
    }
    FUN_14257dcb0(file);
}

// MS2-FUNCTIONAL: records the completion status, pushes the result, and broadcasts onLoad to listeners.
// @0x142969aa0
void StyleSheetObject::NotifyOnLoad(Environment* penv, bool success)
{
    *reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(this) + 0x90) = success ? 2u : 3u;
    penv->Push(success);
    AsBroadcaster::BroadcastMessage(penv, this, penv->CreateConstString("onLoad"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// MS2-FUNCTIONAL: converts the optional argument, returns the string primitive, and updates a constructed String object.
// @0x14295c710
void StringCtorFunction::GlobalCtor(const FnCall& fn)
{
    const ASString value = fn.NArgs > 0 ? fn.Arg(0).ToString(fn.Env) : fn.Env->GetBuiltin(ASBuiltin_empty_);
    Value result(value);
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_String && !fn.ThisPtr->IsBuiltinPrototype())
        static_cast<StringObject*>(fn.ThisPtr)->SetValue(fn.Env, result);
    *fn.Result = result;
}

// MS2-FUNCTIONAL: creates or reuses the TextFormat receiver and applies the constructor arguments via AS2 members.
// @0x14295ca10
void TextFormatCtorFunction::GlobalCtor(const FnCall& fn)
{
    Ptr<TextFormatObject> format;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_TextFormat && !fn.ThisPtr->IsBuiltinPrototype())
        format = static_cast<TextFormatObject*>(fn.ThisPtr);
    else
        format = *SF_HEAP_NEW(fn.Env->GetHeap()) TextFormatObject(fn.Env);

    static const char* names[] = {"font", "size", "color", "bold", "italic", "underline", "url", "target", "align", "leftMargin", "rightMargin", "indent", "leading"};
    for (unsigned i = 0; i < 13 && i < fn.NArgs; ++i)
        format->SetMember(fn.Env, fn.Env->CreateConstString(names[i]), fn.Arg(i));

    fn.Result->SetAsObject(format.GetPtr());
}

// MS2-FUNCTIONAL: handles UTF-8/UTF-16 BOMs, parses the owned buffer, releases it, and reports completion.
// @0x14295e080
void CSSFileLoaderAndParserImpl::Init(Environment* penv, Object* sheet)
{
    bool success = false;
    if (Buffer)
    {
        wchar_t* data = Buffer;
        int length = BufferLen;
        if (data[0] == 0xfeff)
        {
            *reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(this) + 0x10) = 1;
            data++;
            length = length / 2 - 1;
        }
        else if (data[0] == 0xfffe)
        {
            *reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(this) + 0x10) = 1;
            data++;
            length = length / 2 - 1;
            for (int i = 0; i < length; ++i)
                data[i] = wchar_t((unsigned(data[i]) << 8) | (unsigned(data[i]) >> 8));
        }
        else if (length > 2 && UByte(data[0]) == 0xef && UByte(data[0] >> 8) == 0xbb &&
                 UByte(data[1]) == 0xbf)
        {
            data = reinterpret_cast<wchar_t*>(reinterpret_cast<UByte*>(data) + 3);
            length -= 3;
        }

        void* styles = reinterpret_cast<UByte*>(sheet) + 0x68;
        success = *reinterpret_cast<unsigned*>(reinterpret_cast<UByte*>(this) + 0x10) == 1
                      ? FUN_14260b870(styles, data, UPInt(length))
                      : FUN_14260b7f0(styles, reinterpret_cast<const char*>(data), UPInt(length));
        Memory::GetGlobalHeap()->Free(Buffer);
        Buffer = 0;
    }
    static_cast<StyleSheetObject*>(sheet)->NotifyOnLoad(penv, success);
}

// MS2-FUNCTIONAL: flushes text caches, forces an emergency AS2 collection, then resets the heap's budget counters.
// @0x14297df30
void MemoryContextImpl::HeapLimit::Reset(MemoryHeap* heap)
{
    MemoryContextImpl* context = MemContext;
    if (context->TextAllocator)
    {
        FUN_142606410(context->TextAllocator.GetPtr(), true);
        FUN_142606150(context->TextAllocator.GetPtr(), true);
    }
    context->ASGC->ForceEmergencyCollect();
    CurrentLimit = heap->GetFootprint();
    heap->SetLimit(0x20000);
    LastCollectionFootprint = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
}

// MS2-FUNCTIONAL: applies the emergency collection threshold, honors the optional user limit, and updates heap limits.
// @0x14296bbf0
bool MemoryContextImpl::HeapLimit::OnExceedLimit(MemoryHeap* heap, UPInt overLimit)
{
    const UPInt footprint = heap->GetFootprint();
    const UPInt heapLimit = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
    const UPInt projected = UPInt(float(footprint) * HeapLimitMultiplier) + heapLimit + overLimit;
    if (UPInt(float(footprint) * HeapLimitMultiplier) <= footprint - CurrentLimit ||
        (UserLevelLimit && UserLevelLimit < projected))
    {
        MemoryContextImpl* context = MemContext;
        if (context->TextAllocator)
        {
            FUN_142606410(context->TextAllocator.GetPtr(), true);
            FUN_142606150(context->TextAllocator.GetPtr(), true);
        }
        context->ASGC->ForceEmergencyCollect();
        const UPInt collectedFootprint = heap->GetFootprint();
        CurrentLimit = collectedFootprint;
        if (!UserLevelLimit || projected <= UserLevelLimit)
            return true;
        if (footprint - collectedFootprint < overLimit)
            LastCollectionFootprint = heapLimit + (collectedFootprint - footprint) + overLimit;
    }
    heap->SetLimit(UserLevelLimit && UserLevelLimit < projected ? LastCollectionFootprint : projected);
    LastCollectionFootprint = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
    return true;
}

// MS2-FUNCTIONAL: implements AS2 nullish, primitive, object identity, character-path, and coercive equality cases.
// @0x142965570
bool Value::IsEqual(Environment* penv, const Value& other) const
{
    const type left = GetType();
    const type right = other.GetType();
    const bool leftNullish = left == UNDEFINED || left == NULLTYPE || left == UNSET;
    const bool rightNullish = right == UNDEFINED || right == NULLTYPE || right == UNSET;
    if (leftNullish || rightNullish)
        return leftNullish && rightNullish;

    if (left == right)
    {
        switch (left)
        {
        case BOOLEAN:
            return V.BooleanValue == other.V.BooleanValue;
        case INTEGER:
            return NV.Int32Value == other.NV.Int32Value;
        case NUMBER:
            return NV.NumberValue == other.NV.NumberValue ||
                   (NumberUtil_IsNaN(NV.NumberValue) && NumberUtil_IsNaN(other.NV.NumberValue));
        case STRING:
            return V.pStringNode == other.V.pStringNode;
        case OBJECT:
            return V.pObjectValue == other.V.pObjectValue;
        case CHARACTER:
            if (V.pCharHandle == other.V.pCharHandle)
                return true;
            if (!V.pCharHandle || !other.V.pCharHandle)
                return false;
            return GetCharacterNamePath(penv).GetNode() == other.GetCharacterNamePath(penv).GetNode();
        case FUNCTION:
        case FUNCTIONNAME:
            return reinterpret_cast<const UPInt*>(this)[1] == reinterpret_cast<const UPInt*>(&other)[1];
        default:
            return false;
        }
    }

    if (left == BOOLEAN)
    {
        Value number(ToNumber(penv));
        return number.IsEqual(penv, other);
    }
    if (right == BOOLEAN)
    {
        Value number(other.ToNumber(penv));
        return IsEqual(penv, number);
    }

    if (left == OBJECT && right == OBJECT)
        return V.pObjectValue == other.V.pObjectValue;
    if (left == CHARACTER && right == CHARACTER)
        return GetCharacterNamePath(penv).GetNode() == other.GetCharacterNamePath(penv).GetNode();
    if ((left == STRING && right == STRING))
        return V.pStringNode == other.V.pStringNode;

    const Number lhs = ToNumber(penv);
    const Number rhs = other.ToNumber(penv);
    return lhs == rhs || (NumberUtil_IsNaN(lhs) && NumberUtil_IsNaN(rhs));
}

// MS2-FUNCTIONAL: restores empty/default text, resolves the optional bound variable, and dispatches the load event.
// @0x14296ba60
void AvmTextField::OnEventLoad()
{
    if (!pDispObj)
    {
        AvmCharacter::OnEventLoad();
        return;
    }
    TextField* textField = reinterpret_cast<TextField*>(pDispObj);
    void* document = textField ? textField->GetDocument() : 0;
    String* documentText = document ? reinterpret_cast<String*>(reinterpret_cast<UByte*>(document) + 0x70) : 0;
    const bool html = textField && (textField->GetFlags418() & 0x2) != 0;
    if (!documentText || documentText->GetSize() == 0)
    {
        FUN_1425bd9a0(textField, "", html, false);
    }
    else
    {
        bool variableFound = false;
        Environment* environment = GetASEnvironment();
        if (VariableName.GetLength() != 0 && environment)
        {
            *reinterpret_cast<UInt32*>(reinterpret_cast<UByte*>(textField) + 0xfc) |= 0x8000;
            Value value;
            variableFound = environment->GetVariable(VariableName, &value);
        }
        if (!variableFound)
        {
            FUN_1425bd9a0(textField, documentText->ToCStr(), html, true);
        }
    }
    AvmCharacter::OnEventLoad();
}

// MS2-FUNCTIONAL: checks raw/path lookup, with scopes, local variables, the target object, and the global object.
// @0x142964e50
bool Environment::IsAvailable(const ASString& name, const WithStackArray* withStack) const
{
    if (name.GetLength() == 0)
        return false;

    Value value;
    GetVarParams params(name, &value, withStack);
    if (FindAndGetVariableRaw(params))
        return true;

    if (withStack)
    {
        for (SPInt i = SPInt(withStack->GetSize()) - 1; i >= 0; --i)
        {
            ObjectInterface* iface = (*withStack)[UPInt(i)].GetObjectInterface();
            if (iface && iface->HasMember(const_cast<ASStringContext*>(&StringContext), name, false))
                return true;
        }
    }
    if (FindLocal(name))
        return true;
    if (Target && ToAvmCharacter(Target)->HasMember(const_cast<ASStringContext*>(&StringContext), name, false))
        return true;
    Object* global = StringContext.pContext ? StringContext.pContext->pGlobal : 0;
    return global && global->HasMember(const_cast<ASStringContext*>(&StringContext), name, false);
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// The function call's script channels read the target's log directly.
// @0x142967f60
template<>
void LogBase<AS2::FnCall>::LogScriptMessage(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    Log* plog = static_cast<const AS2::FnCall*>(this)->Env->Target->GetLog();
    if (plog)
        plog->LogMessageVarg(LogChannel_Script | LogMessage_Text, pfmt, argList);
    va_end(argList);
}

// The environment's action trace: the movie's verbose-action flag (MovieImpl::Flags bit 2), then the target's log.
// @0x142967430
template<>
void LogBase<AS2::Environment>::LogAction(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    InteractiveObject* ptarget = static_cast<const AS2::Environment*>(this)->Target;
    if ((UByte)(ptarget->GetMovieImpl()->Flags >> 2) & 1)
    {
        Log* plog = ptarget->GetLog();
        if (plog)
            plog->LogMessageVarg(Log_Action, pfmt, argList);
    }
    va_end(argList);
}

// @0x142968210
template<>
void LogBase<AS2::FnCall>::LogScriptWarning(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    if (P_IsVerboseActionErrors())
    {
        Log* plog = static_cast<const AS2::FnCall*>(this)->Env->Target->GetLog();
        if (plog)
            plog->LogMessageVarg(Log_ScriptWarning, pfmt, argList);
    }
    va_end(argList);
}

// The script error channel of a display object, only with verbose action errors.
// @0x142967c90
template<>
void LogBase<DisplayObjectBase>::LogScriptError(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    const DisplayObjectBase* p = static_cast<const DisplayObjectBase*>(this);
    if (p->P_IsVerboseActionErrors())
    {
        Log* plog = p->GetLog();
        if (plog)
            plog->LogMessageVarg(LogChannel_Script | LogMessage_Error, pfmt, argList);
    }
    va_end(argList);
}

namespace AS2 {

// The action disassembly writer: the log and the message type of its lines.
class Disasm
{
public:
    Log*         pLog;    // +0x00
    LogMessageId MsgType; // +0x08

    Disasm(Log* plog, LogMessageId msgType) : pLog(plog), MsgType(msgType) {}

    void LogF(const char* pfmt, ...);
    // Logs one action, its opcode and arguments (exe 0x1429674a0).
    void LogDisasm(const unsigned char* pinstructionData);
};

// @0x142967bf0
void Disasm::LogF(const char* pfmt, ...)
{
    if (pLog)
    {
        va_list argList;
        va_start(argList, pfmt);
        pLog->LogMessageVarg(MsgType, pfmt, argList);
        va_end(argList);
    }
}

// @0x142972730
void ActionBufferData::Read(Stream* pin, unsigned length)
{
    BufferLen = length;
    pBuffer   = (UByte*)SF_HEAP_AUTO_ALLOC(this, length);
    pin->ReadToBuffer(pBuffer, BufferLen);

    if (pin->IsVerboseParseAction())
    {
        const UByte* pbuf = pBuffer;
        UPInt pc = 0;
        UByte actionId;
        do
        {
            actionId = pbuf[pc];
            UPInt next = pc + 1;
            if (actionId & 0x80)
            {
                UPInt len = pbuf[next] | (UPInt(pbuf[next + 1]) << 8);
                next += 2 + len;
            }
            pin->LogParseAction("%4d\t", (int)pc);
            Disasm da(pin->GetLog(), Log_ParseAction);
            da.LogDisasm(pBuffer + pc);
            pc = next;
        } while (actionId);
    }
}

} // namespace AS2

// @0x142965bb0
bool MovieImpl::IsKeyboardFocused(const InteractiveObject* ch, unsigned controllerIdx) const
{
    const unsigned group = FocusGroupIndexes[controllerIdx];
    Ptr<InteractiveObject> focused = FocusGroups[group].LastFocused;
    return focused.GetPtr() == ch && FocusGroups[group].FocusRectShown;
}

// The host side of AS2 values; only the members recovered in this unit.
class AS2ValueObjectInterface : public Value::ObjectInterface
{
private:
    virtual void ObjectAddRef(Value* val, void* pobj);
    virtual void ObjectRelease(Value* val, void* pobj);
    virtual bool IsDisplayObjectActive(void* pdata) const;
    virtual bool PopBack(void* pdata, Value* pval);
    virtual bool RemoveElements(void* pdata, unsigned idx, int count);
    virtual bool GotoAndPlay(void* pdata, const char* frame, bool stop);
    virtual bool GotoAndPlay(void* pdata, unsigned frame, bool stop);
    virtual bool HasMember(void* pdata, const char* name, bool isCharacter) const;
};

// The wide string storage of a VT_StringW value, from its characters.
static inline MovieImpl::WideStringStorage* GetWideStringStorage(void* pdata)
{
    return reinterpret_cast<MovieImpl::WideStringStorage*>(
        static_cast<UByte*>(pdata) - offsetof(MovieImpl::WideStringStorage, pData));
}

// The environment of _level0, through its AS2 character.
static inline AS2::Environment* GetLevel0Environment(MovieImpl* pmovieImpl)
{
    AvmDisplayObjBase* pavm = pmovieImpl->pMainMovie->GetAvmObjImpl();
    return static_cast<AS2::AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
}

// Moves the clip pdata to frame (1-based) and plays or stops it; false for other characters.
// @0x14295d320
bool AS2ValueObjectInterface::GotoAndPlay(void* pdata, unsigned frame, bool stop)
{
    DisplayObject* pchar = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (pchar && pchar->IsSprite())
    {
        InteractiveObject* psprite = static_cast<InteractiveObject*>(pchar);
        psprite->GotoFrame(frame - 1);
        psprite->SetPlayState(stop ? State_Stopped : State_Playing);
        return true;
    }
    return false;
}

// The same for a frame label (or a number in a string).
// @0x14295d3a0
bool AS2ValueObjectInterface::GotoAndPlay(void* pdata, const char* frame, bool stop)
{
    DisplayObject* pchar = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (pchar && pchar->IsSprite())
    {
        InteractiveObject* psprite = static_cast<InteractiveObject*>(pchar);
        unsigned           frameNum;
        if (psprite->GetLabeledFrame(frame, &frameNum, true))
        {
            psprite->GotoFrame(frameNum);
            psprite->SetPlayState(stop ? State_Stopped : State_Playing);
            return true;
        }
    }
    return false;
}

// MS2-FUNCTIONAL the exe builds the key node and calls the AS2 ObjectInterface slot directly; this resolves the
// same character handle and uses the recovered string context and member lookup.
// @0x14295d5e0
bool AS2ValueObjectInterface::HasMember(void* pdata, const char* name, bool isCharacter) const
{
    AS2::MovieRoot* root = static_cast<AS2::MovieRoot*>(pMovieRoot->pASMovieRoot);
    AS2::Environment* env = GetLevel0Environment(root->pMovieImpl);
    AS2::ObjectInterface* object = static_cast<AS2::ObjectInterface*>(pdata);
    if (isCharacter)
    {
        DisplayObject* displayObject = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
        if (!displayObject)
            return false;
        InteractiveObject* interactive = static_cast<InteractiveObject*>(displayObject);
        AS2::AvmCharacter* avm = static_cast<AS2::AvmCharacter*>(interactive->GetAvmIntObj());
        object = avm->GetASObject();
    }
    if (!object)
        return false;
    ASString key = env->StringContext.CreateConstString(name);
    return object->HasMember(&env->StringContext, key, false);
}

// The host's reference to a string node, a wide string, an AS object or a character handle.
// @0x14296a990
void AS2ValueObjectInterface::ObjectAddRef(Value* val, void* pobj)
{
    switch (val->GetType())
    {
    case Value::VT_String:
        static_cast<ASStringNode*>(pobj)->AddRef();
        break;
    case Value::VT_StringW:
        GetWideStringStorage(pobj)->AddRef();
        break;
    case Value::VT_Object:
    case Value::VT_Array:
        static_cast<AS2::ObjectInterface*>(pobj)->ToASObject()->AddRef();
        break;
    case Value::VT_DisplayObject:
        static_cast<CharacterHandle*>(pobj)->AddRef();
        break;
    default:;
    }
}

// @0x14296a9f0
void AS2ValueObjectInterface::ObjectRelease(Value* val, void* pobj)
{
    switch (val->GetType())
    {
    case Value::VT_String:
        static_cast<ASStringNode*>(pobj)->Release();
        break;
    case Value::VT_StringW:
        GetWideStringStorage(pobj)->Release();
        break;
    case Value::VT_Object:
    case Value::VT_Array:
        static_cast<AS2::ObjectInterface*>(pobj)->ToASObject()->Release();
        break;
    case Value::VT_DisplayObject:
    {
        CharacterHandle* phandle = static_cast<CharacterHandle*>(pobj);
        if (--phandle->RefCount <= 0)
            delete phandle;
        break;
    }
    default:;
    }
}

// @0x1429654a0
bool AS2ValueObjectInterface::IsDisplayObjectActive(void* pdata) const
{
    return static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot) != 0;
}

// The last element of the array pdata goes to pval (when given) and off the array; false (pval undefined) when
// the array is empty.
// @0x14296f0d0
bool AS2ValueObjectInterface::PopBack(void* pdata, Value* pval)
{
    AS2::MovieRoot*   proot = static_cast<AS2::MovieRoot*>(pMovieRoot->pASMovieRoot);
    AS2::ArrayObject* parr  = static_cast<AS2::ArrayObject*>(static_cast<AS2::ObjectInterface*>(pdata));
    AS2::Environment* penv  = GetLevel0Environment(proot->pMovieImpl);
    int               size  = parr->GetSize();
    if (size <= 0)
    {
        if (pval)
            pval->SetUndefined();
        return false;
    }
    if (pval)
        proot->ASValue2GFxValue(penv, *parr->Elements[size - 1], pval);
    parr->PopBack();
    return true;
}

// count elements of the array pdata from idx on (to the end when negative) are removed; false past the end.
// @0x14297d080
bool AS2ValueObjectInterface::RemoveElements(void* pdata, unsigned idx, int count)
{
    AS2::ArrayObject* parr = static_cast<AS2::ArrayObject*>(static_cast<AS2::ObjectInterface*>(pdata));
    unsigned          size = parr->GetSize();
    if (idx >= size)
        return false;
    if (count < 0)
        count = size - idx;
    parr->RemoveElements(idx, Alg::Min(size - idx, (unsigned)count));
    return true;
}

// Set when the 9-slice grid is a non-empty rectangle.
// @0x14295db50
bool DisplayObjectBase::HasScale9Grid() const
{
    return !GetScale9Grid().IsEmpty();
}

}} // namespace Scaleform::GFx

namespace Scaleform {

// @0x14296f070
template void GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Pop(unsigned);
// @0x14296efd0
template void GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Pop3();
// @0x142967c30
template void GFx::LogBase<GFx::Stream>::LogParseAction(const char*, ...) const;

// The page switches of the call stack (those of the value stack are elsewhere in the exe, 0x140006a40 /
// 0x140006cf0).
// @0x142972330
template<>
void GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::PushPage()
{
    Page* pnewPage;
    if (pReserved)
    {
        pnewPage  = pReserved;
        pReserved = pReserved->pNext;
    }
    else
        pnewPage = (Page*)SF_HEAP_AUTO_ALLOC(this, sizeof(Page));
    if (pnewPage)
    {
        Pages.PushBack(pnewPage);
        pPrevPageTop = pPageEnd - 1;
        pPageEnd     = pnewPage->Values + 32;
        pPageStart   = pnewPage->Values;
        pCurrent     = pnewPage->Values;
    }
    else
        pCurrent--;
}

// noinline: Environment::Reset calls it out of line.
// @0x14296f2b0
template<>
__declspec(noinline) void GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::PopPage()
{
    if (Pages.GetSize() > 1)
    {
        Page* plast  = Pages.Back();
        plast->pNext = pReserved;
        pReserved    = plast;
        Pages.PopBack();
        Page* ptop   = Pages.Back();
        pPageStart   = ptop->Values;
        pPageEnd     = ptop->Values + 32;
        pCurrent     = pPageEnd - 1;
        pPrevPageTop = Pages.GetSize() > 1 ? &Pages[Pages.GetSize() - 2]->Values[32 - 1] : pPageStart;
    }
    else
    {
        pCurrent++;
        Construct<Ptr<GFx::AS2::FunctionObject> >(pCurrent);
    }
}

// @0x1429673e0
template void GFx::LogBase<GFx::AS2::ActionLogger>::LogAction(const char*, ...) const;

// MS2-FUNCTIONAL the exe inlines Target->GetLog(), while this explicit instantiation calls the recovered
// Environment::GetLog helper; the log routing and format are unchanged.
// LogError functional (pinned at the end): Environment::GetLog (exe 0x14294b210) is out of line here, the exe
// inlines Target->GetLog()
// @0x142967b90
template void GFx::LogBase<GFx::AS2::Environment>::LogError(const char*, ...) const;

// The out-of-line array growth of the AS2 containers.
// @0x14297d690
template void ArrayDataBase<GFx::AS2::AsFunctionObject::ArgSpec,
                            AllocatorLH<GFx::AS2::AsFunctionObject::ArgSpec, GFx::AS2::StatMV_ActionScript_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d4b0
template void ArrayDataBase<GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Page*,
                            AllocatorLH<GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Page*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d5f0
template void ArrayDataBase<GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::Page*,
                            AllocatorLH<GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::Page*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d7d0
template void ArrayDataBase<Ptr<GFx::AS2::Object>, AllocatorLH<Ptr<GFx::AS2::Object>, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d870
template void ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d9b0
template void ArrayDataBase<GFx::AS2::ArraySortFunctor, AllocatorGH<GFx::AS2::ArraySortFunctor, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297da50
template void ArrayDataBase<GFx::AS2::Value, AllocatorGH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::Reserve(const void*,
                                                                                                        UPInt);
// @0x14297daf0
template void ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::Reserve(const void*,
                                                                                                        UPInt);
// @0x14297db90
template void ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297dc30
template void ArrayDataBase<GFx::AS2::WithStackEntry,
                            AllocatorLH_POD<GFx::AS2::WithStackEntry, GFx::AS2::StatMV_ActionScript_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297e1b0
template void ArrayData<GFx::AS2::WithStackEntry,
                        AllocatorLH_POD<GFx::AS2::WithStackEntry, GFx::AS2::StatMV_ActionScript_Mem>,
                        ArrayDefaultPolicy>::Resize(UPInt);
// @0x14297dcd0
template void ArrayDataBase<bool, AllocatorLH<bool, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// TryBlocks_Resize
// @0x14297e060
template void ArrayBase<ArrayData<GFx::AS2::Environment::TryDescr, AllocatorLH<GFx::AS2::Environment::TryDescr, 2>,
                                  ArrayDefaultPolicy> >::Resize(UPInt);
// ArrayObjectElements_Resize (pinned at the end)
template void ArrayData<GFx::AS2::Value*, AllocatorLH<GFx::AS2::Value*, GFx::AS2::StatMV_ActionScript_Mem>,
                        ArrayDefaultPolicy>::Resize(UPInt);
// (pinned at the end)
template void ArrayData<GFx::AS2::Object*, AllocatorGH<GFx::AS2::Object*, 2>, ArrayDefaultPolicy>::Resize(UPInt);
// @0x14297d910
template void ArrayDataBase<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297e450
template void ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// @0x14297e500
template void ArrayDataBase<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// RemoveAt functional (pinned at the end): cl inlines the ResizeNoConstruct of Clear, the exe tail-calls it
template void ArrayBase<ArrayData<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                                  ArrayDefaultPolicy> >::RemoveAt(UPInt);
// @0x14297d730
template void ArrayDataBase<GFx::AS2::Environment::TryDescr, AllocatorLH<GFx::AS2::Environment::TryDescr, Stat_Default_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297e3f0
template void ArrayDataBase<GFx::AS2::Environment::TryDescr, AllocatorLH<GFx::AS2::Environment::TryDescr, Stat_Default_Mem>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// @0x14297d550
template void ArrayDataBase<GFx::AS2::Object*, AllocatorGH<GFx::AS2::Object*, 2>, ArrayDefaultPolicy>::Reserve(const void*,
                                                                                                             UPInt);
// @0x142971a50
template void ArrayData<GFx::AS2::Object*, AllocatorGH<GFx::AS2::Object*, 2>, ArrayDefaultPolicy>::PushBack(
    GFx::AS2::Object* const&);
// @0x14297e0e0
template void ArrayBase<ArrayData<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, Stat_Default_Mem>, ArrayDefaultPolicy> >::Resize(
    UPInt);
// @0x14297e5a0
template void ArrayDataBase<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS2::StatMV_ActionScript_Mem>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);

} // namespace Scaleform
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$Ptr@VSprite@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VSprite@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14297ca70
// MS2-PIN: ?Resize@?$ArrayData@PEAVValue@AS2@GFx@Scaleform@@U?$AllocatorLH@PEAVValue@AS2@GFx@Scaleform@@$0BED@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14297e2b0
// MS2-PIN: ?Resize@?$ArrayData@PEAVObject@AS2@GFx@Scaleform@@U?$AllocatorGH@PEAVObject@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14297e230
// MS2-PIN: ?LogError@?$LogBase@VEnvironment@AS2@GFx@Scaleform@@@GFx@Scaleform@@QEBAXPEBDZZ 0x142967b90
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7ColorTransformCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432193a0
// MS2-PIN: ??_7ColorTransformCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219428
// MS2-PIN: ??_7RectangleCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432197b0
// MS2-PIN: ??_7RectangleCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219838
// MS2-PIN: ??_7TransformCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143219bc0
// MS2-PIN: ??_7TransformCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219c48
// MS2-PIN: ??_7GASMatrixCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218f90
// MS2-PIN: ??_7GASMatrixCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219018
// MS2-PIN: ??_7ColorCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218b80
// MS2-PIN: ??_7ColorCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143218c08
// MS2-PIN: ??_7ButtonCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143217f28
// MS2-PIN: ??_7ButtonCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217fb0
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
// MS2-PIN: ??_7LocalInvokeCallback@MouseCtorFunction@AS2@GFx@Scaleform@@6B@ 0x14321ccf8
