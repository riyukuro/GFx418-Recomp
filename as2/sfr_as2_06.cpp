// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 array element storage and
// the script runtime entry points from Init to Reset.
// MS2-UNIT: sfr_as2_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14295d700-0x14295d840 .text$mn
// MS2-RANGE: 0x14295c710-0x14295c930 .text$mn
// MS2-RANGE: 0x14295c930-0x14295ca00 .text$mn
// MS2-RANGE: 0x14295ca10-0x14295d1c0 .text$mn
// MS2-RANGE: 0x14295d5e0-0x14295d700 .text$mn
// MS2-RANGE: 0x14295d840-0x14295d970 .text$mn
// MS2-RANGE: 0x14295d970-0x14295da40 .text$mn
// MS2-RANGE: 0x14295dbb0-0x14295dbe0 .text$mn
// MS2-RANGE: 0x14295e080-0x14295e1b0 .text$mn
// MS2-RANGE: 0x1429663d0-0x142966480 .text$mn
// MS2-RANGE: 0x1429658d0-0x1429659e0 .text$mn
// MS2-RANGE: 0x142965bb0-0x142965c80 .text$mn
// MS2-RANGE: 0x142965160-0x142965250 .text$mn
// MS2-RANGE: 0x142965f30-0x1429660a0 .text$mn
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
// MS2-RANGE: 0x14296ba60-0x14296bbb0 .text$mn
// MS2-RANGE: 0x14296bbf0-0x14296bd60 .text$mn
// MS2-RANGE: 0x14296e790-0x14296e870 .text$mn
// MS2-RANGE: 0x14296e870-0x14296e9f0 .text$mn
// MS2-RANGE: 0x14296dde0-0x14296e6c0 .text$mn
// MS2-RANGE: 0x14296efd0-0x14296f070 .text$mn
// MS2-RANGE: 0x14296f070-0x14296f0d0 .text$mn
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
// MS2-RANGE: 0x14297cae0-0x14297cf70 .text$mn
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
// MS2-RANGE: 0x142964b90-0x142964e50 .text$mn
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
// MS2-RANGE: 0x142963aa0-0x142963b90 .text$mn
// MS2-RANGE: 0x142967c90-0x142967d10 .text$mn
// MS2-RANGE: 0x142967bf0-0x142967c30 .text$mn
// MS2-RANGE: 0x14296a450-0x14296a540 .text$mn
// MS2-RANGE: 0x1429726a0-0x142972730 .text$mn
// MS2-RANGE: 0x142972730-0x142972830 .text$mn

// The exe's out-of-line copy of the file-static helper IsLeapYear is defined here as an external function; as2_date.h
// gives every other TU its own static copy.
#define MS2_AS2_OUTOFLINE_HELPERS
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_broadcastlocal.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/gfx_imageresource.h" // BitmapData tag ctor: Ptr<ImageResource> member
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_timer.h"
#include "../include/gfx/gfx_input.h"
#include "../include/render/render_twips.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/gfx/text_stylesheet.h"
#include "../include/render/text_core.h"
#include "../include/gfx/as2/as2_hashaccess.h"

// Stores *value under key in the hash at owner+0x10 and releases the passed reference (a folded hash set; the
// prototype table of GlobalContext here). Defined in sfr_video_01.
void FUN_14000c280(void* owner, unsigned key, void** value);

// The text field's style data (exe 0x1425b7e60).
Scaleform::UPInt FUN_1425b7e60(Scaleform::UPInt textField);

namespace Scaleform { namespace GFx {

class FunctionHandler;

template <> inline void LogBase<AS2::Environment>::LogError(const char* pfmt, ...) const;

namespace AS2 {

// The member table's findIndexAlt (exact / ignoring case), COMDATs the exe calls out of line.
MS2_AS2_HASH_FINDINDEX(Member)

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

// MS2-FUNCTIONAL scheduling only: the exe stores the PropFlags default temp first and sinks SetInt's int store past the inlined Arg(i) page lookup (body is the SDK's; named arg, explicit PropFlags(), const Bottom tried)
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

// IsStandardMember below as the exe inlines it, without the lowercase name out.
static inline bool IsStandardMemberInline(const ASString& memberName)
{
    if ((UByte)(memberName.GetHashFlags() >> 29) & 1)
        return true;
    if (memberName.GetLength() > 0 && memberName.GetCharAt(0) == '_')
    {
        ASString lower(memberName.ToLowerNode());
        if ((UByte)(lower.GetHashFlags() >> 28) & 1)
            return true;
    }
    return false;
}

// A standard member answers from the clip's member bit mask, anything else from its AS object.
// @0x14295d840
bool AvmCharacter::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    if (IsStandardMemberInline(name))
    {
        const StandardMember member = GetStandardMemberConstant(name);
        if (member != M_InvalidMember && member <= M_LastBitMaskMember &&
            (GetStandardMemberBitMask() & (1u << static_cast<unsigned>(member))))
            return true;
    }

    Ptr<Object> object = GetASObject();
    if (!object)
        return false;
    return object->HasMember(psc, name, inclPrototypes);
}

// MS2-FUNCTIONAL: the exe inlines the tabEnabled lookup; same flow and calls.
// The first test is the display object's GetVisible (vtable +0x1a8), not InteractiveObject::IsTabable (+0x288), which
// calls back into this function through GetAvmIntObj. tabEnabled is read raw from the prototype (+0x18); an undefined value
// falls through to the clip's own ActsAsButton and then to the tab index.
// @0x142965f30
bool AvmCharacter::IsTabable() const
{
    if (!pDispObj->GetVisible())
        return false;

    const unsigned tabFlags = pDispObj->Flags & InteractiveObject::Mask_TabEnabled;
    if (!tabFlags)
    {
        if (Object* proto = Get__proto__())
        {
            Value value;
            Environment* env = const_cast<Environment*>(GetASEnvironment());
            bool found = proto->GetMemberRaw(&env->StringContext, env->StringContext.CreateConstString("tabEnabled"), &value);
            if (found && !value.IsUndefined())
                return value.ToBool(env);
        }

        return (pDispObj->HasAvmObject() && pDispObj->GetAvmObjImpl()->ToAvmInteractiveObjBase()->ActsAsButton()) ||
               pDispObj->TabIndex > 0;
    }
    return tabFlags == InteractiveObject::Mask_TabEnabled;
}

// MS2-FUNCTIONAL: the exe tail-calls ActsAsButton and saves only rbx/rsi; ours calls it and also saves rbp.
// focusEnabled is read raw from the prototype (+0x18) with the sprite's own environment (+0x38); an undefined value
// falls through to ActsAsButton (tail call through vtable +0x68).
// @0x1429658d0
bool AvmSprite::IsFocusEnabled(FocusMovedType fmt) const
{
    if (fmt == GFx_FocusMovedByMouse)
        return false;

    if (Object* proto = Get__proto__())
    {
        Value value;
        Environment* env = const_cast<Environment*>(&Env);
        bool found = proto->GetMemberRaw(&env->StringContext, env->StringContext.CreateConstString("focusEnabled"), &value);
        if (found && !value.IsUndefined())
            return value.ToBool(env);
    }
    return static_cast<const AvmInteractiveObjBase*>(static_cast<const AvmCharacter*>(this))->ActsAsButton();
}

// MS2-PIN: ?IsVerboseActionErrors@Environment@AS2@GFx@Scaleform@@UEBA_NXZ 0x142966240
// @0x142966240
bool Environment::IsVerboseActionErrors() const
{
    return !(GetTarget()->GetMovieImpl()->Flags & MovieImpl::Flag_SuppressActionErrors);
}

// tabEnabled is read raw from the prototype (+0x18); without a defined value a text field is tabable unless it is read-only.
// @0x1429660c0
bool AvmTextField::IsTabable() const
{
    if (Object* proto = Get__proto__())
    {
        Value value;
        Environment* env = const_cast<Environment*>(GetASEnvironment());
        bool found = proto->GetMemberRaw(&env->StringContext, env->StringContext.CreateConstString("tabEnabled"), &value);
        if (found && !value.IsUndefined())
            return value.ToBool(env);
    }
    return !reinterpret_cast<TextField*>(pDispObj)->IsReadOnly();
}

// @0x1429696d0
void LoadVarsObject::NotifyOnData(Environment* penv, ASString& data)
{
    penv->Push(data);
    BroadcastMessageLocal(penv, this, penv->CreateConstString("onData"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// @0x142969850
void LoadVarsObject::NotifyOnHTTPStatus(Environment* penv, double status)
{
    penv->Push(static_cast<Number>(status));
    BroadcastMessageLocal(penv, this, penv->CreateConstString("onHTTPStatus"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// @0x142969980
void LoadVarsObject::NotifyOnLoad(Environment* penv, bool success)
{
    penv->Push(success);
    BroadcastMessageLocal(penv, this, penv->CreateConstString("onLoad"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// @0x142969bd0
void MovieClipLoader::NotifyOnLoadComplete(Environment* penv, InteractiveObject* ptarget, int status)
{
    penv->Push(status);
    penv->Push(ptarget);
    BroadcastMessageLocal(penv, this, penv->CreateConstString("onLoadComplete"), 2, penv->GetTopIndex());
    penv->Drop2();
}

// @0x142969d90
void MovieClipLoader::NotifyOnLoadError(Environment* penv, InteractiveObject* ptarget, const char* errorCode, int status)
{
    penv->Push(status);
    penv->Push(penv->CreateConstString(errorCode));
    penv->Push(ptarget);
    BroadcastMessageLocal(penv, this, penv->CreateConstString("onLoadError"), 3, penv->GetTopIndex());
    penv->Stack.Pop3();
}

// @0x142969f50
void MovieClipLoader::NotifyOnLoadInit(Environment* penv, InteractiveObject* ptarget)
{
    penv->Push(ptarget);
    BroadcastMessageLocal(penv, this, penv->CreateConstString("onLoadInit"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// @0x14296a300
void MovieClipLoader::NotifyOnLoadStart(Environment* penv, InteractiveObject* ptarget)
{
    penv->Push(ptarget);
    BroadcastMessageLocal(penv, this, penv->CreateConstString("onLoadStart"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// @0x14296e870
bool Environment::ParsePath(ASStringContext* psc, const ASString& path, ASString* pbase, ASString* pextension)
{
    // Search for colon.
    int colonIndex = -1;
    const char* text = path.ToCStr();
    const char* p;
    if ((p = strchr(text, ':')) != 0)
        colonIndex = int(p - text);
    else
    {
        if ((p = strrchr(text, '.')) != 0)
            colonIndex = int(p - text);
        else
        {
            if ((p = strrchr(text, '/')) == 0)
                return false;
        }
    }

    // The extension.
    if (colonIndex >= 0)
        *pextension = psc->CreateString(path.ToCStr() + colonIndex + 1);
    else
        *pextension = psc->GetBuiltin(ASBuiltin_empty_);

    // The base: trim off a trailing slash.
    if (colonIndex > 0)
    {
        if (path[colonIndex - 1] == '/')
            colonIndex--;
    }
    if (colonIndex >= 0)
        *pbase = psc->CreateString(path.ToCStr(), colonIndex);
    else
        *pbase = path;
    return true;
}

static SF_FORCEINLINE InteractiveObject* GetMovieAtLevel(const MovieImpl* pmovieImpl, int level);

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {
// The Value array grows out of line (0x14297e710, explicit instantiation in sfr_as2_07).
template<> void ArrayDataBase<GFx::AS2::Value, AllocatorGH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::ResizeNoConstruct(
    const void* pheapAddr, UPInt newSize);
// The event handler table's lookup (exe 0x142917460, explicit instantiation in sfr_as2_02): the exe calls it out of
// line from the inlined Get.
template<> template<> SPInt decltype(HashLH<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>,
                                            GFx::EventIdHashFunctor, GFx::AS2::StatMV_ActionScript_Mem>::mHash)::BaseType::
    findIndexAlt<GFx::EventId>(const GFx::EventId& key) const;
// The registered-classes table's two lookups (exe 0x1429172b0, 0x142916f50, as in sfr_as2_05): the exe calls them out
// of line from the FindAlt it inlines into RegisterClassA.
typedef decltype(HashUncachedLH<GFx::ASString, GFx::AS2::FunctionRef, GFx::ASStringHashFunctor, 324>::mHash)::BaseType
    Sfr06ClassSet;
template<> template<> SPInt Sfr06ClassSet::findIndexAlt<GFx::ASString>(const GFx::ASString& key) const;
template<> template<> SPInt Sfr06ClassSet::findIndexAlt<GFx::ASStringNoCaseKey>(const GFx::ASStringNoCaseKey& key) const;
}

namespace Scaleform { namespace GFx { namespace AS2 {

// Array<Value>::operator=, out of line in sfr_as2_03.
const Array<Value>& FUN_142926200(Array<Value>* pthis, const Array<Value>& src);

// Queues DoTransferFocus(newFocus, fmt, controllerIdx) on _level0: an action entry without a character never runs.
// MS2-FUNCTIONAL: LTCG mod-ref: the exe knows the out-of-line Value copy-ctor, DropRefs and CreateCharacterHandle leave
// params.Size alone (keeps it in rbx, ResizeNoConstruct(.., 1) on both branches); here Size is reloaded after each call
// @0x142972490
void Selection::QueueSetFocus(Environment* penv, InteractiveObject* newFocus, unsigned controllerIdx,
                              FocusMovedType fmt)
{
    Array<Value> params;
    if (newFocus)
        params.PushBack(Value(newFocus));
    else
        params.PushBack(Value(Value::NULLTYPE));
    params.PushBack(Value(static_cast<int>(fmt)));
    params.PushBack(Value(static_cast<Number>(controllerIdx)));
    MovieRoot* root = static_cast<MovieRoot*>(penv->GetTarget()->GetMovieImpl()->pASMovieRoot);
    InteractiveObject* plevel0 = GetMovieAtLevel(root->pMovieImpl, 0);
    MovieRoot::ActionEntry* entry = root->InsertEmptyAction(ActionPriority::AP_Frame);
    entry->Type          = MovieRoot::ActionEntry::Entry_CFunction;
    entry->pCharacter    = plevel0;
    entry->pActionBuffer = 0;
    entry->CFunction     = DoTransferFocus;
    FUN_142926200(&entry->FunctionParams, params);
}

// Whether the text field (0x10 bytes before self) has a style data with a style sheet (+0x40).
// @0x14295dbb0
bool AvmTextField::HasStyleSheet() const
{
    const UByte* self = reinterpret_cast<const UByte*>(this) + 0x30;
    UPInt styleData = ::FUN_1425b7e60(*reinterpret_cast<const UPInt*>(self - 0x10));
    if (styleData && *reinterpret_cast<void* const*>(styleData + 0x40))
        return true;
    return false;
}

struct AvmSwfEvent
{
    EventId Id;
    Ptr<ActionBufferData> pActionBuffer;

    void Read(StreamContext* stream, unsigned eventId);
};
static_assert(offsetof(AvmSwfEvent, pActionBuffer) == 0x18, "AvmSwfEvent exe layout");
static_assert(sizeof(AvmSwfEvent) == 0x20, "AvmSwfEvent exe size");

// The exe inlines ActionBufferData::CreateNew here (LTCG); the ctor is protected, so a vtable-less derived
// shell runs it. novtable: no vptr store of its own, the object keeps ActionBufferData's vftable.
struct __declspec(novtable) AvmSwfActionBufferNew : ActionBufferData
{
    SF_FORCEINLINE AvmSwfActionBufferNew() {}
};

// The SDK's EventId (GFx_Input.h): KeysState is a KeyModifiers object, and operator= is member-wise. Our shared
// EventId has a UByte KeysState and no operator=, so the SDK temporary and its assignment are spelled out here.
struct SdkEventId
{
    UInt32 Id;
    UInt32 WcharCode;
    UInt32 KeyCode;
    union
    {
        UByte    AsciiCode;
        unsigned TouchID;
    };
    UInt8 RollOverCnt;
    SInt8 ControllerIndex;
    KeyModifiers KeysState;
    SInt8 MouseWheelDelta;

    SF_FORCEINLINE SdkEventId(UInt32 id) : Id(id), WcharCode(0), KeyCode(0), AsciiCode(0), RollOverCnt(0),
                                           MouseWheelDelta(0)
    {
        ControllerIndex = -1;
    }
};
static_assert(sizeof(SdkEventId) == sizeof(EventId), "SdkEventId layout");

static SF_FORCEINLINE void AssignEventId(EventId& d, const SdkEventId& o)
{
    d.Id              = o.Id;
    d.WcharCode       = o.WcharCode;
    d.KeyCode         = o.KeyCode;
    d.AsciiCode       = o.AsciiCode;
    d.RollOverCnt     = o.RollOverCnt;
    d.ControllerIndex = o.ControllerIndex;
    reinterpret_cast<KeyModifiers&>(d.KeysState) = o.KeysState;
    d.MouseWheelDelta = o.MouseWheelDelta;
}

// @0x142972830
void AvmSwfEvent::Read(StreamContext* psc, unsigned flags)
{
    const SdkEventId e(flags);
    AssignEventId(Id, e);
    UInt32 eventLength = psc->ReadU32();
    if (Id.Id & EventId::Event_KeyPress)
    {
        Id.KeyCode = psc->ReadU8();
        --eventLength;
    }

    pActionBuffer = *static_cast<ActionBufferData*>(SF_NEW AvmSwfActionBufferNew());
    pActionBuffer->Read(psc, eventLength);
    if (pActionBuffer->GetLength() != eventLength)
    {
        if (eventLength > pActionBuffer->GetLength())
        {
            unsigned remainder = eventLength - pActionBuffer->GetLength();
            for (unsigned i = 0; i < remainder; i++)
                psc->ReadU8(); // the SDK skips with ReadS8; StreamContext here has only ReadU8
        }
        else
        {
            UPInt pos = psc->CurByteIndex;
            psc->CurByteIndex = pos - (pActionBuffer->GetLength() - eventLength);
        }
    }
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

// LocalFrame's vftable slot 4 (0x143215a98, the raw-word vftable of sfr_as2_04n): always true.
// @0x142966210
bool LocalFrame_VSlot4(const void*)
{
    return true;
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
                if (pelem && (pelem->*&Value::ToObjectInterface)(penv) == plistener)
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

// The out-of-line copy the qualified calls use; the vftable holds the copy 0x14000e390 (sfr_as2_03m).
// @0x14296b820
void AvmCharacter::OnEventLoadBase()
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

// @0x14296f390
Environment::TryDescr Environment::PopTryBlock()
{
    UPInt    n = TryBlocks.GetSize();
    TryDescr t = TryBlocks[n - 1];
    TryBlocks.Resize(n - 1);
    return t;
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


// The exe calls this from Environment::IsAvailable rather than inlining it.
// @0x14296e790
__declspec(noinline) int MovieRoot::ParseLevelName(const char* pname, const char** ptail, bool caseSensitive)
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


// The exe inlines the CFunctionObject ctor, and its FunctionObject base ctor, here (as in sfr_as2_04f).
inline FunctionObject::FunctionObject(ASStringContext* psc, ObjectInlineCtorTag)
    : Object(psc)
{
}

inline CFunctionObject::CFunctionObject(ASStringContext* psc, Object* pprototype, CFunctionPtr func, ObjectInlineCtorTag)
    : FunctionObject(psc, ObjectInlineCtorTag()), pFunction(func)
{
    Set__proto__(psc, pprototype);
}

// @0x142961830
void GASPrototypeBase::InitFunctionMembers(Object* pthis, ASStringContext* psc, const NameFunction* table,
                                           const PropFlags& flags)
{
    Ptr<Object> pfuncProto = psc->pContext->GetPrototype(ASBuiltin_Function);
    for (int i = 0; table[i].Name; i++)
    {
        FunctionRef func(*SF_HEAP_NEW(psc->GetHeap()) CFunctionObject(psc, pfuncProto, table[i].Function, ObjectInlineCtorTag()));
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


// dispatches to InvokeImpl and restores the alternate prototype when called through super.
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

// ASStringContext::GetGC through GlobalContext::GetGC, both inlined (as in sfr_as2_06s9).
static __forceinline ASRefCountCollector* Sfr06GcG(GlobalContext* p)
{
    return p->pMovieRoot ? ((MovieRoot*)p->pMovieRoot->pASMovieRoot)->GetASGC() : 0;
}
static __forceinline ASRefCountCollector* Sfr06GcN(ASStringContext* psc)
{
    return psc->pContext ? Sfr06GcG(psc->pContext) : 0;
}
// Object::Object(ASStringContext*) (0x14291f6f0), inlined (the same body as sfr_as2_06s9's).
__forceinline Object::Object(ASStringContext* psc, ObjectInlineCtorTag)
    : ASRefCountBase<Object>(Sfr06GcN(psc)), pWatchpoints(0), ArePropertiesSet(false), IsListenerSet(false)
{
    pProto = 0;
}
__forceinline FunctionObject::FunctionObject(ASStringContext* psc, ObjectDeepInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
}
// CFunctionObject(psc, func) (0x142919df0) inlined down to Object(psc), with its Set__proto__ (a virtual
// __proto__ store).
__forceinline CFunctionObject::CFunctionObject(ASStringContext* psc, CFunctionPtr func, ObjectInlineCtorTag)
    : FunctionObject(psc, ObjectDeepInlineCtorTag()), pFunction(func)
{
    Object* pprototype = psc->pContext->GetPrototype(ASBuiltin_Function);
    if (!pProto)
        static_cast<ObjectInterface*>(this)->SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
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

// Object(psc) + Set__proto__ inlined (prototype instances); the exe calls Object::SetMemberRaw directly.
#define SFR06_INLINE_PROTO_OBJECT(T)                                                                                     \
    __forceinline T::T(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag) : Object(psc, ObjectInlineCtorTag()) \
    {                                                                                                                    \
        if (!pProto)                                                                                                     \
            Object::SetMemberRaw(                                                                                        \
                psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__), \
                Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));         \
        pProto = pprototype;                                                                                             \
    }

SFR06_INLINE_PROTO_OBJECT(DateObject)
__forceinline DateProto::DateProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<DateObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}
__forceinline DateCtorFunction::DateCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// BooleanObject(psc, pprototype), BooleanProto and BooleanCtorFunction (sfr_as2_03), inlined like the exe.
__forceinline BooleanObject::BooleanObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag()), BValue(false)
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}
__forceinline BooleanProto::BooleanProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<BooleanObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}
__forceinline BooleanCtorFunction::BooleanCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
}

// RegisterBuiltinClass with the CtorFunction and Proto ctors inlined down to Object(psc), as in the exe.
template<class CtorFunctionType, class ProtoType>
static SF_FORCEINLINE FunctionRef RegisterBuiltinClassInline(GlobalContext* pgc, ASBuiltinType type, ASBuiltinType parentType,
                                                     Object* ptarget)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) CtorFunctionType(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) ProtoType(&sc, pgc->GetPrototype(parentType), ctor, ObjectInlineCtorTag());
    SetBuiltinPrototype(pgc, type, proto);
    ptarget->SetMemberRaw(&sc, sc.GetBuiltin(type), Value(ctor));
    return ctor;
}


__forceinline AmpMarker::AmpMarker(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline AmpMarkerProto::AmpMarkerProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<AmpMarker>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
}

__forceinline AmpMarkerCtorFunction::AmpMarkerCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

__forceinline TextSnapshotObject::TextSnapshotObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    ::new (Data68) StaticTextSnapshotData();
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline TextSnapshotProto::TextSnapshotProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<TextSnapshotObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete));
}

__forceinline TextSnapshotCtorFunction::TextSnapshotCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, 0, t)
{
}

__forceinline Selection::Selection(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline SelectionProto::SelectionProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<Selection>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline SelectionCtorFunction::SelectionCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    // AsBroadcaster::Initialize, its InitializeProto inlined.
    ObjectInterface* pobj = this;
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    AsBroadcaster::InitializeInstance(psc, pobj);
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

__forceinline PointObject::PointObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline PointProto::PointProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<PointObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete));
    SetMemberRaw(psc, psc->CreateConstString("length"), Value(0), PropFlags(PropFlags::PropFlag_DontDelete));
}

__forceinline PointCtorFunction::PointCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

__forceinline StringObject::StringObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag()), sValue(psc->GetBuiltin(ASBuiltin_empty_))
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline StringProto::StringProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<StringObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    sValue = psc->GetBuiltin(ASBuiltin_typeObject_);
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline StringCtorFunction::StringCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

__forceinline NumberObject::NumberObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag()), NumberValue(0)
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline NumberProto::NumberProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<NumberObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline NumberCtorFunction::NumberCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    for (int i = 0; ConstTable[i].Name; i++)
        static_cast<ObjectInterface*>(this)->SetMemberRaw(psc, psc->CreateConstString(ConstTable[i].Name), Value(ConstTable[i].Function()),
                                                          PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

__forceinline AsBroadcaster::AsBroadcaster(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline AsBroadcasterProto::AsBroadcasterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<AsBroadcaster>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline AsBroadcasterCtorFunction::AsBroadcasterCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

__forceinline ExternalInterface::ExternalInterface(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline ExternalInterfaceProto::ExternalInterfaceProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<ExternalInterface>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline ExternalInterfaceCtorFunction::ExternalInterfaceCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    {
        Value unset(Value::UNSET);
        static_cast<ObjectInterface*>(this)->SetMemberRaw(psc, psc->CreateConstString("available"), unset);
    }
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

__forceinline Math::Math(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline MathProto::MathProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<Math>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
}

__forceinline MovieClipLoader::MovieClipLoader(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline MovieClipLoaderProto::MovieClipLoaderProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<MovieClipLoader>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline MovieClipLoaderCtorFunction::MovieClipLoaderCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
}

__forceinline SharedObject::SharedObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline SharedObjectProto::SharedObjectProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<SharedObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline SharedObjectCtorFunction::SharedObjectCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// Inlined in the exe (no out-of-line copy), as in sfr_as2_03, 03s and 04b; BitmapDataProto's vftable built here needs it.
inline BitmapData::~BitmapData()
{
}

// BitmapData(psc, pprototype), BitmapDataProto and BitmapDataCtorFunction (sfr_as2_03), inlined like the exe.
__forceinline BitmapData::BitmapData(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline BitmapDataProto::BitmapDataProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<BitmapData>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline BitmapDataCtorFunction::BitmapDataCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// ArrayObject(psc, pprototype), ArrayProto and ArrayCtorFunction (sfr_as2_03), inlined like the exe.
__forceinline ArrayObject::ArrayObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag()), LogPtr(0), RecursionCount(0), LengthValueOverriden(false)
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline ArrayProto::ArrayProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<ArrayObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline ArrayCtorFunction::ArrayCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
    for (int i = 0; SortFlagTable[i].Name; i++)
        static_cast<ObjectInterface*>(this)->SetMemberRaw(psc, psc->CreateConstString(SortFlagTable[i].Name), Value(SortFlagTable[i].Number),
                                                          PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete);
}

__forceinline MatrixObject::MatrixObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline MatrixProto::MatrixProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<MatrixObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline ButtonObject::ButtonObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline ButtonProto::ButtonProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<ButtonObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
    SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_useHandCursor), Value(true),
                 PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
}

__forceinline ColorObject::ColorObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline ColorProto::ColorProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<ColorObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

__forceinline GASLoadVarsLoaderCtorFunction::GASLoadVarsLoaderCtorFunction(ASStringContext* psc, ObjectInlineCtorTag t)
    : CFunctionObject(psc, GlobalCtor, t)
{
}

// The filter classes derive from BitmapFilter: it is registered first unless the registry knows the name.
static SF_FORCEINLINE void RegisterBitmapFilterBase(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    if (!pgc->GetBuiltinClassRegistrar(sc.GetBuiltin(ASBuiltin_BitmapFilter)))
        BitmapFilterCtorFunction::Register(pgc);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x1429752b0
FunctionRef BooleanCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) BooleanCtorFunction(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) BooleanProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor, ObjectInlineCtorTag());
    SetBuiltinPrototype(pgc, ASBuiltin_Boolean, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Boolean), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142973080
FunctionRef AmpMarkerCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<AmpMarkerCtorFunction, AmpMarkerProto>(pgc, ASBuiltin_Amp, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142973a80
FunctionRef AsBroadcasterCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<AsBroadcasterCtorFunction, AsBroadcasterProto>(pgc, ASBuiltin_AsBroadcaster, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the BevelFilterCtorFunction and BevelFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142973f20
FunctionRef BevelFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<BevelFilterCtorFunction, BevelFilterProto>(pgc, ASBuiltin_BevelFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142974460
FunctionRef BitmapDataCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<BitmapDataCtorFunction, BitmapDataProto>(pgc, ASBuiltin_BitmapData, ASBuiltin_Object, pgc->FlashDisplayPackage);
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

// The exe inlines the DateCtorFunction and DateProto ctors down to Object(psc).
// MS2-FUNCTIONAL: register allocation floor (1175 vs 1165 bytes), the same as StyleSheetCtorFunction::Register
// (sfr_as2_06s9): the exe keeps zero in rdi and the ObjectInterface vptr in rdx across the inlined CtorFunction
// Object(psc), so its byte/word zero stores use dil/di; it also stores the DateObject vptrs before the pProto test.
// @0x142976be0
FunctionRef DateCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) DateCtorFunction(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) DateProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor, ObjectInlineCtorTag());
    SetBuiltinPrototype(pgc, ASBuiltin_Date, proto);
    pgc->pGlobal->SetMemberRaw(&sc, ((MovieRoot*)pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin_Date), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL the exe inlines the DropShadowFilterCtorFunction and DropShadowFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142977070
FunctionRef DropShadowFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<DropShadowFilterCtorFunction, DropShadowFilterProto>(pgc, ASBuiltin_DropShadowFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL regalloc floor: the CtorFunction ctor is inlined via its ObjectInlineCtorTag ctor, like the exe;
// the remaining diff is register allocation and a 2-byte longer prolog (mov rax,rsp frame).
// @0x142977ad0
FunctionRef GASLoadVarsLoaderCtorFunction::Register(GlobalContext* pgc)
{
    // The exe inlines the CtorFunction ctor here but calls the LoadVarsProto ctor.
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) GASLoadVarsLoaderCtorFunction(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) LoadVarsProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_LoadVars, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_LoadVars), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL the exe inlines the GlowFilterCtorFunction and GlowFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142978240
FunctionRef GlowFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<GlowFilterCtorFunction, GlowFilterProto>(pgc, ASBuiltin_GlowFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142978dd0
FunctionRef MovieClipLoaderCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<MovieClipLoaderCtorFunction, MovieClipLoaderProto>(pgc, ASBuiltin_MovieClipLoader, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x1429797e0
FunctionRef PointCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<PointCtorFunction, PointProto>(pgc, ASBuiltin_Point, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x14297a4a0
FunctionRef SharedObjectCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<SharedObjectCtorFunction, SharedObjectProto>(pgc, ASBuiltin_SharedObject, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x14297aca0
FunctionRef StringCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<StringCtorFunction, StringProto>(pgc, ASBuiltin_String, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x14297bf80
FunctionRef TextSnapshotCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<TextSnapshotCtorFunction, TextSnapshotProto>(pgc, ASBuiltin_TextSnapshot, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor: ctor inlined down to Object(psc) like the exe (731 vs 730 B); pgc lives in r13
// where the exe uses r15, and the Object zero stores are immediates where the exe stores dil/di.
// @0x142976900
FunctionRef ColorTransformCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) ColorTransformCtorFunction(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) ColorTransformProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_ColorTransform, proto);
    pgc->FlashGeomPackage->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_ColorTransform), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL regalloc floor, as ColorTransformCtorFunction::Register above (731 vs 730 B).
// @0x142979d00
FunctionRef RectangleCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) RectangleCtorFunction(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) RectangleProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_Rectangle, proto);
    pgc->FlashGeomPackage->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Rectangle), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL regalloc floor, as ColorTransformCtorFunction::Register above (731 vs 730 B).
// @0x14297c400
FunctionRef TransformCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) TransformCtorFunction(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) TransformProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_Transform, proto);
    pgc->FlashGeomPackage->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Transform), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142977db0
FunctionRef GASMatrixCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<GASMatrixCtorFunction, MatrixProto>(pgc, ASBuiltin_Matrix, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142975f30
FunctionRef ColorCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<ColorCtorFunction, ColorProto>(pgc, ASBuiltin_Color, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142975740
FunctionRef ButtonCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<ButtonCtorFunction, ButtonProto>(pgc, ASBuiltin_Button, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142973500
FunctionRef ArrayCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<ArrayCtorFunction, ArrayProto>(pgc, ASBuiltin_Array, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x1429775b0
FunctionRef ExternalInterfaceCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<ExternalInterfaceCtorFunction, ExternalInterfaceProto>(pgc, ASBuiltin_ExternalInterface, ASBuiltin_Object,
                                                                                      pgc->FlashExternalPackage);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142979260
FunctionRef NumberCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<NumberCtorFunction, NumberProto>(pgc, ASBuiltin_Number, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL regalloc floor, as DateCtorFunction::Register: the ctors are inlined down to Object(psc) via the
// ObjectInlineCtorTag ctors above, like the exe; it keeps zero in rdi and stores dil/di.
// @0x142979fe0
FunctionRef SelectionCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClassInline<SelectionCtorFunction, SelectionProto>(pgc, ASBuiltin_Selection, ASBuiltin_Object, pgc->pGlobal);
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

// Runs one mouse listener with the event arguments; a negative count means the listener is skipped.
// @0x142963400
void MouseCtorFunction::LocalInvokeCallback::Invoke(Environment* penv, ObjectInterface* pthis,
                                                    const FunctionRef& method)
{
    int nargs = PushListenersParams(penv, MouseIndex, EventName, Value(method), pTargetName, Button, Delta,
                                    DblClick);
    if (nargs >= 0) {
        Value result;
        method.Invoke(FnCall(&result, pthis, penv, nargs, penv->GetTopIndex()));
        penv->Drop(nargs);
    }
}

struct MouseLocalFrameInlineTag {};

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it in PushListenersParams.
static SF_FORCEINLINE void MouseFunctionRefSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
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
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, MouseLocalFrameInlineTag)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        MouseFunctionRefSetLocalFrame(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

// Value::ToFunction as the SDK writes it (a switch), with the copy above.
struct MouseValueAccess : Value
{
    using Value::ResolveFunctionName;
};
static SF_FORCEINLINE FunctionRef MouseValueToFunction(const Value& v, const Environment* penv)
{
    switch (v.GetType())
    {
    case Value::FUNCTIONNAME:
        return static_cast<const MouseValueAccess&>(v).ResolveFunctionName(penv);
    case Value::FUNCTION:
        return FunctionRef(v.V.FunctionValue, MouseLocalFrameInlineTag());
    default:;
    }
    return FunctionRef();
}

// The SDK body: the switch on the event, ToFunction with SetLocalFrame expanded, in-place pushes.
// @0x142971d70
int MouseCtorFunction::PushListenersParams(Environment* penv, unsigned mouseIndex, ASBuiltinType eventName,
                                           const Value& method, const ASString* ptargetName, unsigned button,
                                           int delta, bool dblClick)
{
    // Without extensions (or for a method taking no arguments) only the standard arguments.
    bool noExtArgs = !penv->CheckExtensions();
    if (penv->CheckExtensions() && button > 0 &&
        (eventName == ASBuiltin_onMouseDown || eventName == ASBuiltin_onMouseUp))
    {
        // An extended button other than the left one only reaches methods that declare arguments.
        FunctionRef func = MouseValueToFunction(method, penv);
        if (!func.IsNull())
        {
            if (func->GetNumArgs() <= 0)
            {
                if (button > 1)
                    return -1;
                noExtArgs = true;
            }
        }
        else
            return -1;
    }
    int nargs = 0;
    if (penv->CheckExtensions() && !noExtArgs)
    {
        if (eventName == ASBuiltin_onMouseDown && dblClick)
        {
            penv->Push(dblClick);
            ++nargs;
        }
        Render::PointF pos = GetMovieMouseState(penv->GetTarget()->GetMovieImpl(), mouseIndex)->GetLastPosition();
        penv->Push(Number(Render::TwipsToPixels(floor(pos.y + 0.5))));
        penv->Push(Number(Render::TwipsToPixels(floor(pos.x + 0.5))));
        penv->Push((int)mouseIndex);
        nargs += 3;
    }
    if (eventName != ASBuiltin_onMouseMove)
    {
        if (ptargetName && (eventName == ASBuiltin_onMouseWheel || !noExtArgs))
        {
            penv->Push(*ptargetName);
            ++nargs;
        }
        else if (nargs > 0)
        {
            penv->Push(Value::NULLTYPE);
            ++nargs;
        }
    }
    switch (eventName)
    {
    case ASBuiltin_onMouseWheel:
        penv->Push(delta);
        ++nargs;
        break;
    case ASBuiltin_onMouseDown:
    case ASBuiltin_onMouseUp:
        if (button && !noExtArgs)
        {
            penv->Push(Number(button));
            ++nargs;
        }
        else if (nargs > 0)
        {
            penv->Push(Value::NULLTYPE);
            ++nargs;
        }
        break;
    case ASBuiltin_onMouseMove:
        break;
    default:
        break;
    }
    return nargs;
}

// MS2-FUNCTIONAL regalloc floor: MathProto is inlined down to Object(psc) via the ObjectInlineCtorTag ctors, like
// the exe; 787 vs 783 B, the remaining diff is register allocation.
// @0x142978780
FunctionRef MathCtorFunction::Register(GlobalContext* pgc)
{
    // The exe inlines the MathProto ctor here but calls the MathCtorFunction ctor.
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) MathCtorFunction(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) MathProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor, ObjectInlineCtorTag());
    SetBuiltinPrototype(pgc, ASBuiltin_Math, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Math), Value(ctor));
    return ctor;
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
    if ((execType == ActionBuffer::Exec_Unknown || execType == ActionBuffer::Exec_Event) && Target->IsUnloading())
        return true;
    if (Target->IsUnloaded())
        return true;
    return false;
}

// @0x142965e50
bool AvmCharacter::IsStandardMember(const ASString& memberName, ASString* plowerCaseName)
{
    if ((UByte)(memberName.GetHashFlags() >> 29) & 1)
        return true;
    if (memberName.GetLength() > 0 && memberName.GetCharAt(0) == '_')
    {
        ASString lower(memberName.ToLowerNode());
        if ((UByte)(lower.GetHashFlags() >> 28) & 1)
        {
            if (plowerCaseName)
                *plowerCaseName = lower;
            return true;
        }
    }
    return false;
}

// The key a clip event handler is kept under: key events without their key code.
static inline EventId ClipEventHandlerKey(const EventId& id)
{
    if (id.Id == EventId::Event_KeyDown || id.Id == EventId::Event_KeyUp)
        return EventId(id.Id);
    return id;
}

// @0x14295d450
__declspec(noinline) bool AvmCharacter::HasClipEventHandler(const EventId& id) const
{
    return EventHandlers.Get(ClipEventHandlerKey(id)) != 0;
}

// @0x142964200
bool AvmCharacter::InvokeClipEventHandlers(Environment* penv, const EventId& id)
{
    const ArrayLH<Value, StatMV_ActionScript_Mem>* phandlers = EventHandlers.Get(ClipEventHandlerKey(id));
    if (phandlers)
    {
        for (UPInt i = 0, n = phandlers->GetSize(); i < n; i++)
            GAS_Invoke((*phandlers)[i], 0, this, penv, 0, penv->GetTopIndex() + 1, 0);
        return true;
    }
    return false;
}

// The out-of-line resizes Reset calls (COMDATs where cl inlines them): the register array (exe 0x14297e0e0) and
// the frame array's shrink (exe 0x14297e450).
typedef ArrayData<Value, AllocatorLH<Value, Stat_Default_Mem>, ArrayDefaultPolicy> LocalRegisterData;
typedef ArrayBase<LocalRegisterData> LocalRegisterBase;
typedef ArrayDataBase<Ptr<LocalFrame>, AllocatorLH<Ptr<LocalFrame>, Stat_Default_Mem>, ArrayDefaultPolicy> LocalFramesData;

// @0x14297dd70
void Environment::Reset()
{
    Stack.Reset();
    for (unsigned i = 0; i < 4; i++)
        GlobalRegister[i].SetUndefined();
    (LocalRegister.*&LocalRegisterBase::Resize)(0);
    Unrolling       = false;
    IsInvalidTarget = false;
    CallStack.Reset();
    (reinterpret_cast<LocalFramesData*>(&LocalFrames)->*&LocalFramesData::ResizeNoConstruct)(&LocalFrames, 0);
    FuncCallNestingLevel = 0;
    (reinterpret_cast<TryBlocksData*>(&TryBlocks)->*&TryBlocksData::Resize)(0);
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

// @0x14297d460
bool AvmSprite::ReplaceChildCharacterOnLoad(InteractiveObject* poldChar, InteractiveObject* pnewChar)
{
    if (!ReplaceChildCharacter(poldChar, pnewChar))
        return false;
    pnewChar->OnEventLoad();
    GetAS2Root()->DoActions();
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
    return GAS_Invoke(methodName, presult, this, &Env, numArgs,
                      Env.GetTopIndex());
}

// @0x142963fc0
bool AvmSprite::InvokeArgs(const char* methodName, Value* presult, const char* methodArgFmt, va_list args)
{
    Ptr<Sprite> psprite = GetSprite();
    return GAS_InvokeParsed(methodName, presult, this, &Env, methodArgFmt,
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
        Object* pclipObj = pMovieClipObj.GetPtr();
        Value   v;
        Object* pobj = pclipObj ? pclipObj : Get__proto__();
        if (pobj)
        {
            Environment* penv = const_cast<Environment*>(&Env);
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

// MS2-FUNCTIONAL: one instruction is scheduled differently: the exe moves penv into rcx for OperatorNew before
// it zeroes v's type byte; ours after.
// @0x14296a540
void StageCtorFunction::NotifyOnResize(Environment* penv)
{
    if (penv->GetSC()->pContext->CheckExtensions())
    {
        Render::RectF rect = penv->GetTarget()->GetMovieImpl()->AsMovieInterface()->GetVisibleFrameRect();
        // CreateRectangleObject (0x142937bc0) inlined
        Value         v;
        {
            Ptr<Object> obj =
                *penv->OperatorNew(penv->GetSC()->pContext->FlashGeomPackage, penv->GetBuiltin(ASBuiltin_Rectangle));
            ASRect r(rect.x1, rect.y1, rect.x2, rect.y2);
            static_cast<RectangleObject*>(obj.GetPtr())->SetProperties(penv, r);
            v.SetAsObject(obj);
        }
        penv->Push(v);
        BroadcastMessageLocal(penv, this, penv->CreateConstString("onResize"), 1, penv->GetTopIndex());
        penv->Drop1();
    }
    else
        BroadcastMessageLocal(penv, this, penv->CreateConstString("onResize"), 0, 0);
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
        retVal = GAS_Invoke(pmethodName, &resultVal, pavmSprite, &pavmSprite->Env, numArgs, pavmSprite->Env.GetTopIndex());
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
    memcpy(pBuffer, &psc->pData[psc->CurByteIndex], eventLength);
    BufferLen = eventLength;
    psc->Align();
    psc->CurByteIndex += eventLength;
}

// Queues Stage.onResize for the next action pass when there is a _level0.
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

// GlobalContext::GetStringManager (ToAS2Root of the movie), which is out of line in the SDK and inlined in the exe. The
// root is read through the SDK's Ptr<ASMovieRootBase>, which gives the exe's load order.
static SF_FORCEINLINE StringManager* SoGcStringManager(const GlobalContext* pgc)
{
    return static_cast<MovieRoot*>(
        reinterpret_cast<Ptr<ASMovieRootBase>&>(pgc->pMovieRoot->pASMovieRoot).GetPtr())->GetStringManager();
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

// queues the Selection CFunction with the recovered focus arguments through the environment helper.
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

// A nested array of a SharedObject being read: added to the object (or array) on top, then pushed.
// @0x1429718b0
void GASSharedObjectLoader::PushArray(const String& name)
{
    Object* ptop = ObjectStack.Back();
    Ptr<Object> parr =
        *pEnv->OperatorNew(SoGcStringManager(pEnv->StringContext.pContext)->GetBuiltin(ASBuiltin_Array));
    if (bArrayIsTop)
    {
        ArrayObject* ptoparr = static_cast<ArrayObject*>(ptop);
        ptoparr->PushBack(Value(parr));
    }
    else
        ptop->SetMember(pEnv, pEnv->CreateString(name), Value(parr));
    bArrayIsTop = true;
    ObjectStack.PushBack(parr);
}

// A nested object of a SharedObject being read: added to the object (or array) on top, then pushed.
// @0x142972190
void GASSharedObjectLoader::PushObject(const String& name)
{
    Object* ptop = ObjectStack.Back();
    Ptr<Object> pobj =
        *pEnv->OperatorNew(SoGcStringManager(pEnv->StringContext.pContext)->GetBuiltin(ASBuiltin_Object));
    if (bArrayIsTop)
    {
        ArrayObject* ptoparr = static_cast<ArrayObject*>(ptop);
        ptoparr->PushBack(Value(pobj));
    }
    else
        ptop->SetMember(pEnv, pEnv->CreateString(name), Value(pobj));
    bArrayIsTop = false;
    ObjectStack.PushBack(pobj);
}

// Back to the enclosing object; an array is on top again when it is one.
// @0x14296f260
void GASSharedObjectLoader::PopObject()
{
    (reinterpret_cast<ArrayData<Object*, AllocatorGH<Object*, 2>, ArrayDefaultPolicy>*>(&ObjectStack)->*&ArrayData<Object*, AllocatorGH<Object*, 2>, ArrayDefaultPolicy>::Resize)(ObjectStack.GetSize() - 1);
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
    UByte Unrecovered_08[8];
    int Type;
    wchar_t* Buffer;
    int BufferLen;

    virtual void Load(const String& fileName, FileOpener* opener);
    virtual void Init(Environment* penv, Object* sheet);
};

// opens the CSS file, reads its complete byte stream into an owned, terminated buffer, and closes it.
// @0x1429663d0
void CSSFileLoaderAndParserImpl::Load(const String& fileName, FileOpener* opener)
{
    Ptr<File> pfile = *opener->OpenFile(fileName.ToCStr(), FileConstants::Open_Read | FileConstants::Open_Buffered,
                                        FileConstants::Mode_ReadWrite);
    if (pfile && pfile->IsValid())
    {
        BufferLen = pfile->GetLength();
        if (BufferLen)
        {
            Buffer = reinterpret_cast<wchar_t*>(Memory::GetGlobalHeap()->Alloc(BufferLen + 2));
            pfile->Read(reinterpret_cast<UByte*>(Buffer), BufferLen);
            reinterpret_cast<UByte*>(Buffer)[BufferLen + 1] = 0;
            reinterpret_cast<UByte*>(Buffer)[BufferLen] = 0;
        }
    }
}

// Records the completion status, pushes the result, and broadcasts onLoad to listeners.
// noinline: CSSFileLoaderAndParserImpl::Init tail-calls it.
// @0x142969aa0
__declspec(noinline) void StyleSheetObject::NotifyOnLoad(Environment* penv, bool success)
{
    Text::StyleManager& CSS = *reinterpret_cast<Text::StyleManager*>(this->CSS.Data);
    if (success)
        CSS.SetState(Text::StyleManager::LoadingFinished);
    else
        CSS.SetState(Text::StyleManager::Error);
    penv->Push(success);
    BroadcastMessageLocal(penv, this,
        penv->CreateConstString("onLoad"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// MS2-FUNCTIONAL 0x14295c710: register allocation and branch layout differ (/O2 codegen); same calls as the exe.
// @0x14295c710
void StringCtorFunction::GlobalCtor(const FnCall& fn)
{
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_String && !fn.ThisPtr->IsBuiltinPrototype())
    {
        // A constructed String object takes the raw argument (SetValue converts it) and the result is
        // that raw argument, not its string form.
        StringObject* pobj = static_cast<StringObject*>(fn.ThisPtr);
        Value retVal = fn.NArgs > 0 ? Value(fn.Arg(0)) : Value(fn.Env->GetBuiltin(ASBuiltin_empty_));
        pobj->SetValue(fn.Env, retVal);
        *fn.Result = retVal;
    }
    else if (fn.NArgs == 0)
        fn.Result->SetString(fn.Env->GetBuiltin(ASBuiltin_empty_));
    else
        fn.Result->SetString(fn.Arg(0).ToString(fn.Env));
}

// returns the active StyleSheet receiver or constructs a new sheet for a global call.
// @0x14295c930
void StyleSheetCtorFunction::GlobalCtor(const FnCall& fn)
{
    Ptr<StyleSheetObject> sheet;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_StyleSheet && !fn.ThisPtr->IsBuiltinPrototype())
        sheet = static_cast<StyleSheetObject*>(fn.ThisPtr);
    else
        sheet = *SF_HEAP_NEW(fn.Env->GetHeap()) StyleSheetObject(fn.Env);
    fn.Result->SetAsObject(sheet.GetPtr());
}

// @0x14295ca10
void TextFormatCtorFunction::GlobalCtor(const FnCall& fn)
{
    Ptr<TextFormatObject> format;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_TextFormat && !fn.ThisPtr->IsBuiltinPrototype())
        format = static_cast<TextFormatObject*>(fn.ThisPtr);
    else
        format = *SF_HEAP_NEW(fn.Env->GetHeap()) TextFormatObject(fn.Env);

    if (fn.NArgs >= 1)
    {
        ASStringContext* psc = fn.Env->GetSC();
        format->SetMember(fn.Env, psc->CreateConstString("font"), fn.Arg(0));
        if (fn.NArgs >= 2)
        {
            format->SetMember(fn.Env, psc->CreateConstString("size"), fn.Arg(1));
            if (fn.NArgs >= 3)
            {
                format->SetMember(fn.Env, psc->CreateConstString("color"), fn.Arg(2));
                if (fn.NArgs >= 4)
                {
                    format->SetMember(fn.Env, psc->CreateConstString("bold"), fn.Arg(3));
                    if (fn.NArgs >= 5)
                    {
                        format->SetMember(fn.Env, psc->CreateConstString("italic"), fn.Arg(4));
                        if (fn.NArgs >= 6)
                        {
                            format->SetMember(fn.Env, psc->CreateConstString("underline"), fn.Arg(5));
                            if (fn.NArgs >= 7)
                            {
                                format->SetMember(fn.Env, psc->CreateConstString("url"), fn.Arg(6));
                                if (fn.NArgs >= 8)
                                {
                                    format->SetMember(fn.Env, psc->CreateConstString("target"), fn.Arg(7));
                                    if (fn.NArgs >= 9)
                                    {
                                        format->SetMember(fn.Env, psc->CreateConstString("align"), fn.Arg(8));
                                        if (fn.NArgs >= 10)
                                        {
                                            format->SetMember(fn.Env, psc->CreateConstString("leftMargin"), fn.Arg(9));
                                            if (fn.NArgs >= 11)
                                            {
                                                format->SetMember(fn.Env, psc->CreateConstString("rightMargin"), fn.Arg(10));
                                                if (fn.NArgs >= 12)
                                                {
                                                    format->SetMember(fn.Env, psc->CreateConstString("indent"), fn.Arg(11));
                                                    if (fn.NArgs >= 13)
                                                    {
                                                        format->SetMember(fn.Env, psc->CreateConstString("leading"), fn.Arg(12));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    fn.Result->SetAsObject(format.GetPtr());
}

// @0x14295e080
void CSSFileLoaderAndParserImpl::Init(Environment* penv, Object* pTarget)
{
    StyleSheetObject* pASObj = static_cast<StyleSheetObject*>(pTarget);

    if (!Buffer)
    {
        pASObj->NotifyOnLoad(penv, false);
    }
    else
    {
        wchar_t* wcsptr     = NULL;
        UByte*   ptextData  = reinterpret_cast<UByte*>(Buffer);
        int      textLength = BufferLen;

        UInt16* prefix16 = reinterpret_cast<UInt16*>(Buffer);
        if (prefix16[0] == Alg::ByteUtil::BEToSystem((UInt16)0xFFFE))
        {
            prefix16++;
            ptextData  = (UByte*)prefix16;
            textLength = (BufferLen / 2) - 1;
            Type       = 1;
            for (int i = 0; i < textLength; i++)
                prefix16[i] = (wchar_t)Alg::ByteUtil::LEToSystem(prefix16[i]);
        }
        else if (prefix16[0] == Alg::ByteUtil::BEToSystem((UInt16)0xFEFF))
        {
            prefix16++;
            ptextData  = (UByte*)prefix16;
            textLength = (BufferLen / 2) - 1;
            Type       = 1;
            for (int i = 0; i < textLength; i++)
                prefix16[i] = Alg::ByteUtil::BEToSystem(prefix16[i]);
        }
        else if (BufferLen > 2 && reinterpret_cast<UByte*>(Buffer)[0] == 0xEF &&
                 reinterpret_cast<UByte*>(Buffer)[1] == 0xBB && reinterpret_cast<UByte*>(Buffer)[2] == 0xBF)
        {
            ptextData += 3;
            textLength -= 3;
        }

        Text::StyleManager& CSS = *reinterpret_cast<Text::StyleManager*>(pASObj->CSS.Data);
        bool ret = false;
        switch (Type)
        {
        case 1:
            ret = CSS.ParseCSS((wchar_t*)ptextData, textLength);
            break;
        default:
            ret = CSS.ParseCSS((char*)ptextData, textLength);
        }

        if (wcsptr)
            SF_FREE(wcsptr);
        SF_FREE(Buffer);
        Buffer = NULL;

        pASObj->NotifyOnLoad(penv, ret);
    }
}

// Flushes text caches, forces an emergency AS2 collection, then resets the heap's budget counters.
// @0x14297df30
void MemoryContextImpl::HeapLimit::Reset(MemoryHeap* heap)
{
    if (MemContext->TextAllocator)
    {
        MemContext->TextAllocator->FlushTextFormatCache(true);
        MemContext->TextAllocator->FlushParagraphFormatCache(true);
    }
    MemContext->ASGC->ForceEmergencyCollect();
    CurrentLimit = heap->GetFootprint();
    heap->SetLimit(0x20000);
    LastCollectionFootprint = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
}

// The SDK body with the inlined Collect. Our CurrentLimit (+0x20) is the SDK's LastCollectionFootprint and our
// LastCollectionFootprint (+0x28) is the SDK's CurrentLimit; [heap+0x60] is GetLimit().
// @0x14296bbf0
bool MemoryContextImpl::HeapLimit::OnExceedLimit(MemoryHeap* heap, UPInt overLimit)
{
    UPInt footprint = heap->GetFootprint();
    UPInt heapLimit = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);

    SPInt allocsSinceLastCollect = (SPInt)footprint - CurrentLimit;
    UPInt newLimit = (heapLimit + overLimit) + (UPInt)(footprint * HeapLimitMultiplier);

    if (allocsSinceLastCollect >= (SPInt)(footprint * HeapLimitMultiplier) ||
        (UserLevelLimit != 0 && newLimit > UserLevelLimit))
    {
        if (MemContext->TextAllocator)
        {
            MemContext->TextAllocator->FlushTextFormatCache(true);
            MemContext->TextAllocator->FlushParagraphFormatCache(true);
        }
        MemContext->ASGC->ForceEmergencyCollect();
        CurrentLimit = heap->GetFootprint();

        if (UserLevelLimit != 0 && newLimit > UserLevelLimit)
        {
            if (overLimit > (footprint - CurrentLimit))
            {
                LastCollectionFootprint = heapLimit + (overLimit - (footprint - CurrentLimit));
                heap->SetLimit(LastCollectionFootprint);
                LastCollectionFootprint = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
            }
            else
            {
                heap->SetLimit(LastCollectionFootprint);
                LastCollectionFootprint = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
            }
        }
    }
    else
    {
        heap->SetLimit(newLimit);
        LastCollectionFootprint = *reinterpret_cast<UPInt*>(reinterpret_cast<UByte*>(heap) + 0x60);
    }

    return true;
}

// MS2-FUNCTIONAL: SDK AS2_Value.cpp flow (ECMA-262 11.9.3). 12 bytes off, all in the NUMBER NaN test. The exe keeps the first
// IsNaN(NV) in bl (the LTCG pure-call CSE of the SDK double test) and tests bl before its second IsNaN(pv) call. With the
// SDK form cl calls IsNaN 4 times; with `thisNaN || IsNaN(pv)` it merges the two IsNaN(pv) calls into one. The form here
// keeps both call sites but makes the second call before the bl test. The result is the same, since IsNaN is pure.
// @0x142965570
bool Value::IsEqual(Environment* penv, const Value& other) const
{
    const bool thisNullType = IsUndefined() || T.Type == NULLTYPE;
    const bool otherNullType = other.IsUndefined() || other.T.Type == NULLTYPE;
    if (thisNullType || otherNullType)
        return thisNullType == otherNullType;

    switch (T.Type)
    {
    case STRING:
        if (other.IsNumber())
            return Value(ToNumber(penv)).IsEqual(penv, other);
        else if (other.T.Type == BOOLEAN)
            return IsEqual(penv, Value(other.ToNumber(penv)));
        else if (other.IsFunction() || other.IsObject())
        {
            Value primVal = other.ToPrimitive(penv);
            if (primVal.T.Type >= NULLTYPE && primVal.T.Type <= STRING)
                return IsEqual(penv, primVal);
            else
                return false;
        }
        return ASString(V.pStringNode) == other.ToString(penv);

    case NUMBER:
    {
        Number pv;
        if (other.T.Type == BOOLEAN)
            pv = other.ToNumber(penv);
        else if (other.IsFunction() || other.IsObject())
        {
            Value primVal = other.ToPrimitive(penv);
            if (primVal.T.Type >= NULLTYPE && primVal.T.Type <= STRING)
                return IsEqual(penv, primVal);
            else
                return false;
        }
        else
            pv = other.ToNumber(penv);
        const bool thisNaN = NumberUtil_IsNaN(NV.NumberValue);
        if (thisNaN && NumberUtil_IsNaN(pv))
            return true;
        const bool pvNaN = NumberUtil_IsNaN(pv);
        if (thisNaN || pvNaN)
            return false;
        return NV.NumberValue == pv;
    }
    case INTEGER:
    {
        if (other.T.Type == NUMBER)
        {
            Value dv;
            dv.SetNumber((Number)NV.Int32Value);
            return dv.IsEqual(penv, other);
        }
        SInt32 pv;
        if (other.T.Type == BOOLEAN)
            pv = other.ToInt32(penv);
        else if (other.IsFunction() || other.IsObject())
        {
            Value primVal = other.ToPrimitive(penv);
            if (primVal.T.Type >= NULLTYPE && primVal.T.Type <= STRING)
                return IsEqual(penv, primVal);
            else
                return false;
        }
        else
            pv = other.ToInt32(penv);
        return NV.Int32Value == pv;
    }
    case BOOLEAN:
        return Value(ToNumber(penv)).IsEqual(penv, other);

    case OBJECT:
    case FUNCTION:
        if (other.IsNumber() || other.T.Type == STRING || other.T.Type == BOOLEAN)
        {
            Value primVal = ToPrimitive(penv);
            if (primVal.T.Type >= NULLTYPE && primVal.T.Type <= STRING)
                return primVal.IsEqual(penv, other);
            else
                return false;
        }
        if (T.Type == OBJECT && other.T.Type == OBJECT)
            return V.pObjectValue == other.V.pObjectValue;
        else if (T.Type == FUNCTION && other.T.Type == FUNCTION)
            return reinterpret_cast<const UPInt*>(this)[1] == reinterpret_cast<const UPInt*>(&other)[1];
        return false;

    case CHARACTER:
        if (other.T.Type != CHARACTER)
            return false;
        if (!V.pCharHandle || !other.V.pCharHandle)
            return V.pCharHandle == other.V.pCharHandle;
        return GetCharacterNamePath(penv) == other.GetCharacterNamePath(penv);

    default:
        break;
    }
    return T.Type == other.T.Type;
}

// The text comes from the definition's DefaultText (pDef +0xd8, +0x70), not from the document. A bound variable
// that already exists keeps its value: then only UpdateTextFromVariable runs.
// @0x14296ba60
void AvmTextField::OnEventLoad()
{
    TextField* textField = reinterpret_cast<TextField*>(pDispObj);
    if (textField->pDef->DefaultText.GetLength() != 0)
    {
        bool found = false;
        if (VariableName.GetSize() != 0)
        {
            textField->Flags |= 0x8000;
            if (Environment* environment = GetASEnvironment())
            {
                Value value;
                found = environment->GetVariable(VariableName, &value);
            }
        }
        if (!found)
        {
            textField->SetTextValue(reinterpret_cast<TextField*>(pDispObj)->pDef->DefaultText.ToCStr(),
                                    (textField->GetFlags418() & 0x2) != 0, true);
            UpdateVariable();
        }
    }
    else
        textField->SetTextValue("", (textField->GetFlags418() & 0x2) != 0, false);
    UpdateTextFromVariable();
}

// Invokes the registered watch callback with user data, new value, old value, and property name.
// @0x142964b90
const Object::Watchpoint* WatchpointHash_GetCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash,
                                                      const ASString& key, bool caseSensitive);

bool Object::InvokeWatchpoint(Environment* penv, const ASString& prop, const Value& newVal, Value* resultVal)
{
    // The old value is read even when no watchpoint matches (a getter property runs).
    Value oldVal;
    GetMember(penv, prop, &oldVal);

    Value result;
    const Watchpoint* watch = WatchpointHash_GetCaseCheck(pWatchpoints, prop, penv->GetVersion() > 6);
    if (watch && pWatchpoints)
    {
        penv->Push(watch->UserData);
        penv->Push(newVal);
        penv->Push(oldVal);
        penv->Push(Value(prop));

        // A clip's AS object calls back with the clip itself as this.
        Ptr<InteractiveObject> paschar = GetASCharacter();
        if (paschar)
            watch->Callback.Invoke(
                FnCall(&result, AS2::ToAvmCharacter(paschar.GetPtr()), penv, 4, penv->GetTopIndex()));
        else
            watch->Callback.Invoke(FnCall(&result, this, penv, 4, penv->GetTopIndex()));
        penv->Drop(4);
        *resultVal = result;
        return true;
    }
    return false;
}

// Whether the timer still runs (Clear() stops it).
// @0x142964e30
bool IntervalTimer::IsActive() const
{
    return Active;
}

// A raw lookup, then a path ("a.b", "/a:b") through FindTarget, the with-stack, the locals, the target, the names
// this/_root/_global, _levelN and the global object; nothing is logged.
// @0x142964e50
bool Environment::IsAvailable(const ASString& name, const WithStackArray* withStack) const
{
    if (name.GetSize() == 0)
        return false;

    ASStringContext* psc = const_cast<ASStringContext*>(&StringContext);
    ASString         path(GetBuiltin(ASBuiltin_empty_));
    ASString         var(GetBuiltin(ASBuiltin_empty_));
    Value            value;

    if (FindAndGetVariableRaw(GetVarParams(name, &value, withStack, 0, 0, 4)))
        return true;

    if (ParsePath(psc, name, &path, &var))
    {
        InteractiveObject* target = FindTarget(path, 4);
        if (!target)
            return false;
        return ToAvmCharacter(target)->GetMemberRaw(psc, var, &value);
    }

    if (withStack)
    {
        for (int i = (int)withStack->GetSize() - 1; i >= 0; i--)
        {
            ObjectInterface* iface = (*withStack)[UPInt(i)].GetObjectInterface();
            if (iface && iface->GetMemberRaw(psc, name, &value))
                return true;
        }
    }
    if (FindLocal(name))
        return true;
    if (Target && ToAvmCharacter(Target)->GetMemberRaw(psc, name, &value))
        return true;

    if (IsCaseSensitive())
    {
        if (GetBuiltin(ASBuiltin_this) == name || GetBuiltin(ASBuiltin__root) == name ||
            GetBuiltin(ASBuiltin__global) == name)
            return true;
    }
    else
    {
        name.ResolveLowercase();
        if (GetBuiltin(ASBuiltin_this).GetNode()->pLower == name.GetNode()->pLower ||
            GetBuiltin(ASBuiltin__root).GetNode()->pLower == name.GetNode()->pLower ||
            GetBuiltin(ASBuiltin__global).GetNode()->pLower == name.GetNode()->pLower)
            return true;
    }

    if (name.ToCStr()[0] == '_')
    {
        const char* ptail = 0;
        int         level = MovieRoot::ParseLevelName(name.ToCStr(), &ptail, IsCaseSensitive());
        if (level != -1 && !*ptail)
        {
            if (static_cast<MovieRoot*>(Target->GetMovieImpl()->pASMovieRoot)->GetLevelMovie(level))
                return true;
        }
    }

    Object* global = StringContext.pContext->pGlobal;
    return global && global->GetMemberRaw(psc, name, &value);
}

// The member className of the package, when it is a function, constructs the object (SDK form: no null package
// test, a non-function member gives 0).
// MS2-FUNCTIONAL: LTCG codegen: the exe inlines Value::ToFunction (AS2_Value.cpp) and keeps the FunctionRef fields in
// registers across the OperatorNew call
// @0x14296e520
Object* Environment::OperatorNew(Object* package, const ASString& className, int nargs, int argsTopOff)
{
    Value ctor;
    if (package->GetMember(this, className, &ctor))
    {
        if (ctor.IsFunction())
        {
            return OperatorNew(ctor.ToFunction(this), nargs, argsTopOff);
        }
    }
    return 0;
}

// MS2-FUNCTIONAL: new Object(x) wraps x; otherwise creates the instance through the prototype's __constructor__,
// always runs the constructor (its return value is ignored) and returns the new object with an added reference.
// @0x14296dde0
Object* Environment::OperatorNew(const FunctionRef& constructor, int nargs, int argsTopOff)
{
    if (argsTopOff < 0)
        argsTopOff = GetTopIndex();

    if (nargs == 1 && constructor.GetObjectPtr() == GetConstructor(ASBuiltin_Object).GetObjectPtr())
    {
        // new Object(x): a primitive becomes its wrapper object, an object is returned as is.
        Value objVal;
        const Value& arg = Top(0);
        if (arg.GetType() >= Value::BOOLEAN && arg.GetType() <= Value::STRING)
            objVal = PrimitiveToTempObject(0);
        else if (arg.IsObject() || arg.IsCharacter())
            objVal = arg;
        if (!objVal.IsUndefined())
        {
            Object* pobj = objVal.ToObject(this);
            if (pobj)
                pobj->AddRef();
            return pobj;
        }
    }

    Value prototypeVal;
    if (!constructor->GetMemberRaw(GetSC(), GetBuiltin(ASBuiltin_prototype), &prototypeVal))
        prototypeVal.SetAsObject(GetPrototype(ASBuiltin_Object));

    // The prototype's __constructor__ (set by extends) creates the instance.
    Object* proto = prototypeVal.ToObject(this);
    FunctionRef ctor = constructor;
    Value ctorVal;
    if (proto && proto->GetMemberRaw(GetSC(), GetBuiltin(ASBuiltin___constructor__), &ctorVal) && ctorVal.IsFunction()
        && !ctorVal.ToFunction(this).IsNull())
        ctor = ctorVal.ToFunction(this);

    Ptr<Object> pnew = *ctor->CreateNewObject(this);
    if (!pnew)
    {
        LogScriptError("%s::CreateNewObject returned NULL during creation of %s class instance.",
                       StringContext.pContext->FindClassName(this, ctor.GetObjectPtr()).ToCStr(),
                       StringContext.pContext->FindClassName(this, constructor.GetObjectPtr()).ToCStr());
        return 0;
    }
    pnew->Set__proto__(GetSC(), prototypeVal.ToObject(this));
    pnew->Set__constructor__(GetSC(), constructor);

    Value result;
    ctor.Invoke(FnCall(&result, pnew, this, nargs, argsTopOff));
    pnew->AddRef();
    return pnew;
}

// MovieRoot::GetLevelMovie (sfr_as2_05), which the exe inlines here.
static SF_INLINE Sprite* IsAvailable_GetLevelMovie(const MovieImpl* pmovie, int level)
{
    for (unsigned i = 0; i < pmovie->MovieLevelsSize; i++)
    {
        if (pmovie->pMovieLevels[i].Level == level)
            return static_cast<Sprite*>(pmovie->pMovieLevels[i].pSprite);
    }
    return 0;
}

// Queries the level-zero AS2 environment for the supplied variable or target path.
// @0x142965160
bool MovieRoot::IsAvailable(const char* name) const
{
    if (!IsAvailable_GetLevelMovie(pMovieImpl, 0))
        return false;
    Environment* environment =
        static_cast<AvmCharacter*>(IsAvailable_GetLevelMovie(pMovieImpl, 0)->GetAvmObjImpl())->GetASEnvironment();
    return environment->IsAvailable(environment->CreateString(name));
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
        UPInt i = 0;
        UPInt pc = i;
        UByte actionId;
        do
        {
            actionId = pbuf[i];
            i = pc + 1;
            if (actionId & 0x80)
            {
                UPInt len = pbuf[i] | (UPInt(pbuf[i + 1]) << 8);
                i += 2 + len;
            }
            pin->LogParseAction("%4d\t", (int)pc);
            Disasm da(pin->GetLog(), Log_ParseAction);
            da.LogDisasm(pBuffer + pc);
            pc = i;
        } while (actionId);
    }
}

} // namespace AS2

inline bool MovieImpl::IsFocused(const InteractiveObject* ch, unsigned controllerIdx) const
{
    Ptr<InteractiveObject> focused = FocusGroups[FocusGroupIndexes[controllerIdx]].LastFocused;
    return focused.GetPtr() == ch;
}

// @0x142965bb0
bool MovieImpl::IsKeyboardFocused(const InteractiveObject* ch, unsigned controllerIdx) const
{
    return IsFocused(ch, controllerIdx) && IsFocusRectShown(controllerIdx);
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

// AvmTextField::CSSHolder::HasStyleSheet (vftable 0x143218188 slot 1): whether a StyleSheet object (+0x40) is set.
// @0x14295d440
bool CSSHolder_HasStyleSheet(const void* pholder)
{
    return *reinterpret_cast<void* const*>(static_cast<const UByte*>(pholder) + 0x40) != 0;
}

// The SDK's Value_AS2ObjectData (sfr_as2_03g 0x142923f30), which the exe inlines here.
struct InlineAS2ObjectData
{
    AS2::ObjectInterface* pObject;
    AS2::Environment*     pEnv;
    AS2::MovieRoot*       pRoot;

    SF_FORCEINLINE InlineAS2ObjectData(MovieImpl* pmovie, void* pdata, bool isdobj)
    {
        pRoot   = static_cast<AS2::MovieRoot*>(pmovie->pASMovieRoot);
        pEnv    = GetLevel0Environment(pRoot->pMovieImpl);
        pObject = static_cast<AS2::ObjectInterface*>(pdata);
        if (isdobj)
        {
            DisplayObject* d = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pmovie);
            if (!d)
            {
                pObject = 0;
                return;
            }
            pObject = AS2::ToAvmCharacter(static_cast<InteractiveObject*>(d));
        }
    }
};

// Whether the AS object (or the character) in pdata has the member name.
// @0x14295d5e0
bool AS2ValueObjectInterface::HasMember(void* pdata, const char* name, bool isCharacter) const
{
    InlineAS2ObjectData o(pMovieRoot, pdata, isCharacter);
    if (!o.pObject)
        return false;
    // GetMember, not HasMember: the character's members (child clips, properties) only resolve through it
    AS2::Value member;
    if (!o.pObject->GetMember(o.pEnv, o.pEnv->StringContext.CreateConstString(name), &member))
        return false;
    return true;
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
        if (Pages.GetSize() > 1)
            pPrevPageTop = Pages[Pages.GetSize() - 2]->Values + 32 - 1;
        else
            pPrevPageTop = pPageStart;
    }
    else
    {
        pCurrent++;
        Construct<Ptr<GFx::AS2::FunctionObject> >(pCurrent);
    }
}

// @0x1429673e0
template void GFx::LogBase<GFx::AS2::ActionLogger>::LogAction(const char*, ...) const;

// GFXLOG_MESSAGE_FUNC(LogError) for Environment with Environment::GetLog (Target->GetLog()) inlined, as in the exe.
// @0x142967b90
template <>
inline void GFx::LogBase<GFx::AS2::Environment>::LogError(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    GFx::AS2::Environment* p = (GFx::AS2::Environment*)this;
    Log* plog = p->Target->GetLog();
    if (p->IsLogNotNull() || plog)
        plog->LogMessageVarg(Log_Error, pfmt, argList);
    va_end(argList);
}

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
template void ArrayData<GFx::AS2::Value*, AllocatorLH<GFx::AS2::Value*, 2>,
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
// Clear goes through a member pointer: the exe tail-calls the ResizeNoConstruct above, which cl otherwise inlines.
template <>
__declspec(dllexport) void ArrayBase<ArrayData<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                         ArrayDefaultPolicy> >::RemoveAt(UPInt index)
{
    if (Data.Size == 1)
    {
        typedef ArrayDataBase<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>, ArrayDefaultPolicy> Base;
        (Data.*&Base::ResizeNoConstruct)(&Data, 0);
    }
    else
    {
        AllocatorType::Destruct(Data.Data + index);
        AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + 1, Data.Size - 1 - index);
        --Data.Size;
    }
}
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

// removes the exact or case-folded watchpoint key according to the AS2 version's name rules.
// @0x14297cae0
namespace GFx { namespace AS2 {
void WatchpointHash_RemoveCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key,
                                    bool caseSensitive)
{
    typedef ASStringHash_GC<Object::Watchpoint>::SetType Set;
    Set* set = reinterpret_cast<Set*>(phash);
    if (caseSensitive)
        set->Remove(key);
    else
        set->RemoveAlt(ASStringNoCaseKey(key));
}

// removes the exact or case-folded registered class name according to the AS2 version's rules.
// @0x14297cd20
void ClassHash_RemoveCaseCheck(ASStringHash<FunctionRef>* phash, const ASString& key, bool caseSensitive)
{
    if (caseSensitive)
        phash->Remove(key);
    else
        phash->RemoveAlt(ASStringNoCaseKey(key));
}
}} // namespace GFx::AS2

} // namespace Scaleform
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$Ptr@VSprite@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VSprite@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14297ca70
// MS2-PIN: ?Resize@?$ArrayData@PEAVValue@AS2@GFx@Scaleform@@U?$AllocatorLH@PEAVValue@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14297e2b0
// MS2-PIN: ?Resize@?$ArrayData@PEAVObject@AS2@GFx@Scaleform@@U?$AllocatorGH@PEAVObject@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14297e230
// MS2-PIN: ?LogError@?$LogBase@VEnvironment@AS2@GFx@Scaleform@@@GFx@Scaleform@@QEBAXPEBDZZ 0x142967b90
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
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
// MS2-PIN: ??_7SetFocusInvokeCallback@AS2@GFx@Scaleform@@6B@ 0x143221850
// MS2-PIN: ??_7LocalInvokeCallback@MouseCtorFunction@AS2@GFx@Scaleform@@6B@ 0x14321ccf8
// MS2-PIN: ??_7ActionBufferData@AS2@GFx@Scaleform@@6B@ 0x1432153b8
// MS2-PIN: ??_7?$RefCountBase@VActionBufferData@AS2@GFx@Scaleform@@$0BAI@@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BAI@@Scaleform@@6B@ 0x14318ccd8

// data_rdata_sf_b names these vftable slots by their address
#pragma comment(linker, "/alternatename:?FUN_14295d440@@YAXXZ=?CSSHolder_HasStyleSheet@GFx@Scaleform@@YA_NPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_142966210@@YAXXZ=?LocalFrame_VSlot4@AS2@GFx@Scaleform@@YA_NPEBX@Z")

// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@6B@ 0x143215370
// MS2-PIN: ??_7ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215410
// MS2-PIN: ??_7?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@AS2@GFx@Scaleform@@6B@ 0x1432154b8
// MS2-PIN: ??_7Object@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432154d0
// MS2-PIN: ??_7Object@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215518
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7DateObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c1d8
// MS2-PIN: ??_7DateObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c220
// MS2-PIN: ??_7?$Prototype@VDateObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c2c8
// MS2-PIN: ??_7?$Prototype@VDateObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c310
// MS2-PIN: ??_7?$Prototype@VDateObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321c3b8
// MS2-PIN: ??_7DateProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c3c0
// MS2-PIN: ??_7DateProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c408
// MS2-PIN: ??_7DateProto@AS2@GFx@Scaleform@@6B@ 0x14321c4b0
// MS2-PIN: ??_7DateCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c4b8
// MS2-PIN: ??_7DateCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c540
