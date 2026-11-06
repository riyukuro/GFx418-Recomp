// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 AvmButton gap functions of
// sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142943360-0x14294347d .text$mn
// MS2-RANGE: 0x142949960-0x142949b12 .text$mn
// MS2-RANGE: 0x14294a370-0x14294a41f .text$mn
// MS2-PIN: ??_7ButtonObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143217c48
// MS2-PIN: ??_7ButtonObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217c90

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_button.h"
#include "../include/gfx/gfx_interactiveobject.h"
template <> void Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec, Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt); // out of line in the exe (0x1425248e0)
namespace Scaleform { namespace GFx { namespace AS2 {

// The script side of a button (partial local copy; the other units carry their own).
class AvmButton : public AvmCharacter, public AvmButtonBase
{
public:
    Ptr<ButtonObject> ASButtonObj; // +0x38

    virtual unsigned GetCursorType() const;

private:
    ButtonObject*     GetButtonASObject();
    Button::CharToRec FindCharacterAndRemove(const ButtonRecord& rec);
};

// GlobalContext::GetGC (exe 0x14294afc0) and Object::Set__proto__ (exe 0x140007ba0) as the exe inlines them.
static inline ASRefCountCollector* Sfr05dGetGC(GlobalContext* pgc)
{
    return pgc->pMovieRoot ? static_cast<MovieRoot*>(pgc->pMovieRoot->pASMovieRoot)->GetASGC() : 0;
}

static inline void Sfr05dSetProto(ObjectInterface* pobj, ASStringContext* psc, Object* protoObj)
{
    if (!pobj->pProto)
        pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin___proto__), Value(Value::UNSET),
                           PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pobj->pProto = protoObj;
}

inline ButtonObject::ButtonObject(GlobalContext* pgc, InteractiveObject* pbutton)
    : Object(Sfr05dGetGC(pgc)), pButton(pbutton)
{
    AvmCharacter* pavm = 0;
    if (pbutton) pavm = AS2::ToAvmCharacter(pbutton); // the SDK ToAvmCharacter null check
    ASStringContext* psc = pavm->GetASEnvironment()->GetSC();
    Sfr05dSetProto(this, psc, pavm->Get__proto__());
}

// The hand while the button is enabled and its useHandCursor (looked up through the prototype chain) is true.
// @0x14294a370
unsigned AvmButton::GetCursorType() const
{
    const Environment* penv = GetASEnvironment();
    Value              val;
    if (penv && ((UByte)(pDispObj->Flags >> 4) & 1))
    {
        if (ASButtonObj)
            const_cast<AvmButton*>(this)->GetMemberRaw(const_cast<Environment*>(penv)->GetSC(),
                                                       penv->GetBuiltin(ASBuiltin_useHandCursor), &val);
        else if (pProto)
            pProto->GetMemberRaw(const_cast<Environment*>(penv)->GetSC(), penv->GetBuiltin(ASBuiltin_useHandCursor), &val);
        if (val.ToBool(penv))
            return 1;
    }
    return 0;
}

// @0x142949960
ButtonObject* AvmButton::GetButtonASObject()
{
    if (!ASButtonObj)
        ASButtonObj = *SF_HEAP_AUTO_NEW(this) ButtonObject(GetGC(), pDispObj);
    return ASButtonObj;
}

// The state character made from rec leaves its state (the Hit state holds none): found by record.
// @0x142943360
Button::CharToRec AvmButton::FindCharacterAndRemove(const ButtonRecord& rec)
{
    // Button::States (+0xe0, 0x20 bytes each) is protected.
    struct StateView
    {
        void*                  pRenNode;
        Button::StateCharArray Characters;
    };
    StateView* pstates = reinterpret_cast<StateView*>(reinterpret_cast<UByte*>(pDispObj) + 0xe0);
    for (unsigned i = 0; i < Button::StatesCount; ++i)
    {
        if (i != Button::Hit)
        {
            Button::ButtonState curState = (Button::ButtonState)i;
            Button::StateCharArray&
                chars = pstates[curState].Characters;
            for (UPInt j = 0, n = chars.GetSize(); j < n; ++j)
            {
                if (chars[j].Record == &rec)
                {
                    Button::CharToRec chr = chars[j];
                    chars.RemoveAt(j);
                    return chr;
                }
            }
        }
    }
    return Button::CharToRec();
}

}}} // namespace Scaleform::GFx::AS2
