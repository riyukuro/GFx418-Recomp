// Recovered Scaleform GFx 4.1.18 Video: the AS2 video character (the AvmCharacter of a Video clip).
// sfr_video_02 defines its overriders and emits the vftables (Video02EmitAvmVideoVftables). sfr_video_01 defines
// GetStandardMemberBitMask (0x14000d320) and the ctor (0x14000e2b0).
// Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_SF_VIDEO_AS2AVMVIDEOCHARACTER_H
#define MS2_SF_VIDEO_AS2AVMVIDEOCHARACTER_H

#include "../gfx/as2/as2_avmcharacter.h"
#include "video_as2videoobject.h"

namespace Scaleform { namespace GFx {
class __declspec(novtable) AvmVideoCharacterBase : public AvmInteractiveObjBase
{
};
namespace AS2 {
// the video character's own fields at +0x38: a base, since the exe sets them before the vftable stores
struct AvmVideoCharacterFields
{
    UInt32 FieldA, FieldB, Deblocking;   // +0x38
    bool   Smoothing;                    // +0x44
    AvmVideoCharacterFields() { Deblocking = 0; FieldB = 0; FieldA = 0; Smoothing = true; }
};
class AvmVideoCharacter : public AvmCharacter, public AvmVideoCharacterBase, public AvmVideoCharacterFields
{
public:
    // (implicit destructor, inlined into the deleting destructor 0x14000e8a0; 0x14000e840 is its out-of-line copy)
    // the AS2 part lives inside its display object's allocation: the deleting destructor frees nothing
    void operator delete(void*) {}
    AvmVideoCharacter(InteractiveObject* pdispObj);   // 0x14000e2b0 (sfr_video_01)

    virtual AvmInteractiveObjBase*      ToAvmInteractiveObjBase();      // 0x14000e520
    virtual AvmSpriteBase*              ToAvmSpriteBase();              // 0x14000e530
    virtual AvmButtonBase*              ToAvmButttonBase();             // 0x14000e540
    virtual AvmTextFieldBase*           ToAvmTextFieldBase();           // 0x14000e550
    virtual AvmDisplayObjContainerBase* ToAvmDispContainerBase();       // 0x14000e560
    virtual const char* GetAbsolutePath(String* ppath) const;           // 0x14000e570
    virtual bool        HasEventHandler(const EventId& id) const;       // 0x14000e600
    virtual bool        OnEvent(const EventId& id);                     // 0x14000e580
    virtual void        OnEventLoad();                                  // 0x14000e590
    virtual void        OnEventUnload();                                // 0x14000e5d0
    virtual bool        OnUnloading(bool mayRemove);                    // 0x14000e5e0
    virtual AvmVideoCharacterBase* ToAvmVideoCharacterBase();           // 0x14000e510

    virtual bool     ActsAsButton() const;                              // 0x14000e620
    virtual unsigned GetCursorType() const;                             // 0x14000e610
    virtual void     CloneInternalData(const InteractiveObject* src);   // 0x14000e630
    virtual void     CopyPhysicalProperties(const InteractiveObject* poldChar);    // 0x14000e640
    virtual void     OnFocus(InteractiveObject::FocusEventType event, InteractiveObject* oldOrNewFocusCh,
                             unsigned controllerIdx, FocusMovedType fmt);          // 0x14000e650
    virtual void     OnGettingKeyboardFocus(unsigned controllerIdx, FocusMovedType fmt);   // 0x14000e670
    virtual bool     OnKeyEvent(const EventId& id, int* pkeyMask);      // 0x14000e680
    virtual bool     OnLosingKeyboardFocus(InteractiveObject* newFocusCh, unsigned controllerIdx,
                                           FocusMovedType fmt = GFx_FocusMovedByKeyboard);  // 0x14000e690
    virtual bool     IsFocusEnabled(FocusMovedType fmt = GFx_FocusMovedByKeyboard) const;   // 0x14000e6a0
    virtual bool     IsTabable() const;                                 // 0x14000e6b0

    virtual Object*  GetASObject();                                     // 0x14000e880
    virtual Object*  GetASObject() const;                               // 0x14000e890
    virtual unsigned GetStandardMemberBitMask() const;                  // 0x14000d320

    virtual ObjectType GetObjectType() const;                           // 0x14000e500
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());       // 0x14000e8f0
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);   // 0x14000e9f0

    // (FieldA, FieldB, Deblocking, Smoothing at +0x38: the AvmVideoCharacterFields base)
    Ptr<VideoObject> pVideoObject;                  // +0x48, created by FUN_14000e020
};
}}} // namespace Scaleform::GFx::AS2

#endif
