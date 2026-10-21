// Recovered Scaleform 4.1.18 GFx AS2: the script side of a display object (AvmCharacter). Only the layout prefix
// up to the display object is recovered so far.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_AVMCHARACTER_H
#define MS2_SF_GFX_AS2_AVMCHARACTER_H

#include "as2_movieroot.h"
#include "../gfx_interactiveobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// AvmInteractiveObjBase vftable at +0x00, ObjectInterface at +0x08.
class AvmCharacter : public NewOverrideBase<StatMV_ActionScript_Mem>, public AvmInteractiveObjBase,
                     public ObjectInterface
{
public:
    InteractiveObject* pDispObj; // +0x20

    InteractiveObject* GetDispObj() const { return pDispObj; }
};

inline InteractiveObject* ObjectInterface::ToCharacter()
{
    return IsASCharacter() ? static_cast<AvmCharacter*>(this)->GetDispObj() : 0;
}

inline Value::Value(InteractiveObject* pcharacter)
{
    T.Type        = CHARACTER;
    V.pCharHandle = pcharacter ? pcharacter->GetCharacterHandle() : 0;
    if (V.pCharHandle)
        V.pCharHandle->AddRef();
}

inline ObjectInterface* Value::ToObjectInterface(const Environment* penv) const
{
    if (T.Type == CHARACTER)
        return ToAvmCharacter(penv);
    return ToObject(penv);
}

// The target path of a character value, "" once the character is gone.
inline const ASString& Value::GetCharacterNamePath(Environment* penv) const
{
    if (V.pCharHandle && V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl()))
        return V.pCharHandle->NamePath;
    return penv->GetBuiltin(ASBuiltin_empty_);
}

}}} // namespace Scaleform::GFx::AS2

#endif
