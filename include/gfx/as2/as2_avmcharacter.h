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
    // The clip event handlers by event (onClipEvent and friends). AvmCharacter is 0x30 bytes.
    HashLH<EventId, ArrayLH<Value, StatMV_ActionScript_Mem>, EventIdHashFunctor, StatMV_ActionScript_Mem>
        EventHandlers; // +0x28

    InteractiveObject* GetDispObj() const { return pDispObj; }
    MovieRoot*         GetAS2Root() const { return ToAS2Root(pDispObj); }

    static void CharacterGetDepth(const FnCall& fn);

    // __proto__ becomes the "prototype" member of psrcObj, if it has one (exe 0x14298a480).
    void SetProtoToPrototypeOf(ObjectInterface* psrcObj);
    // A copy of the character under its parent at depth, initialized from psource (exe 0x142934610).
    InteractiveObject* CloneDisplayObject(const ASString& newname, int depth, const ObjectInterface* psource);

    // ObjectInterface overrides (the AvmCharacter vftable is not modeled yet).
    virtual bool DeleteMember(ASStringContext* psc, const ASString& name); // exe 0x1429386e0
    // The member of the clip's AS object (exe 0x1429448c0).
    virtual bool FindMember(ASStringContext* psc, const ASString& name, Member* pmember);
    // These forward to the clip's AS object.
    virtual bool SetMemberFlags(ASStringContext* psc, const ASString& name, const UByte flags); // exe 0x142988930
    virtual void VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags = 0,
                              const ObjectInterface* instance = 0) const;                    // exe 0x142994660
    virtual void Set__proto__(ASStringContext* psc, Object* protoObj);                        // exe 0x14298dcb0
    virtual bool Watch(ASStringContext* psc, const ASString& prop, const FunctionRef& callback,
                       const Value& userData);                                                // exe 0x142994bb0
    virtual bool Unwatch(ASStringContext* psc, const ASString& prop);                         // exe 0x1429926f0

    // AvmDisplayObjBase overrides.
    virtual void OnEventLoad();   // exe 0x14296b820
    virtual void OnEventUnload(); // exe 0x14296bba0
    // The parent's path plus ".name"; "_level<n>" for a root sprite, empty otherwise (exe 0x1429494d0).
    virtual const char* GetAbsolutePath(String* ppath) const;

    // AvmCharacter's own slots 23..33 (checked against the exe vftable 0x143215b00).
    virtual void               Bind(DisplayObject* po);
    virtual GlobalContext*     GetGC() const;                    // exe 0x14294afb0
    virtual Object*            GetASObject();                    // slot 26
    virtual Object*            GetASObject() const;              // slot 25
    virtual InteractiveObject* GetRelativeTarget(const ASString& name, bool firstCall);
    virtual bool               ReplaceChildCharacterOnLoad(InteractiveObject* poldChar, InteractiveObject* pnewChar);
    virtual bool               ReplaceChildCharacter(InteractiveObject* poldChar, InteractiveObject* pnewChar);
    virtual Environment*       GetASEnvironment();               // slot 31, exe 0x1429493c0 (the parent's)
    virtual const Environment* GetASEnvironment() const;         // slot 30, exe 0x142949400
    virtual InteractiveObject* GetTopParent(bool ignoreLockRoot = false) const;     // exe 0x142956b10
    virtual AvmCharacter*      GetAvmTopParent(bool ignoreLockRoot = false) const;  // exe 0x142949860
    // Slot 34: bit n set when standard member n is a property of this kind of character (exe 0x142956060: none).
    virtual unsigned           GetStandardMemberBitMask() const;

    // The standard (built-in property) members that DeleteMember and friends look up.
    enum StandardMember
    {
        M_InvalidMember      = -1,
        M_x                  = 0,
        M_y                  = 1,
        M_width              = 8,
        M_height             = 9,
        M_useHandCursor      = 31, // clears the clip's useHandCursor setting
        M_LastBitMaskMember  = 32  // the last member the bit mask covers
    };
    // The standard member the name spells, M_InvalidMember otherwise (exe 0x142956090).
    StandardMember GetStandardMemberConstant(const ASString& newname) const;

    // (appended for sfr_as2_04)
    // AvmInteractiveObjBase overrides: both take over the event handlers of the other character (exe 0x142934870,
    // 0x142935cc0).
    virtual void CloneInternalData(const InteractiveObject* src);
    virtual void CopyPhysicalProperties(const InteractiveObject* poldChar);

    // (appended for sfr_as2_05)
    // Slots 35..40. A standard member by index; opcodeFlag rejects the indices the set/getProperty opcodes cannot
    // name (exe 0x14298ab80 / 0x142955080).
    virtual bool SetStandardMember(StandardMember index, const Value& val, bool opcodeFlag);
    virtual bool GetStandardMember(StandardMember index, Value* val, bool opcodeFlag) const;
    // Run script on the character: an action buffer (sprites only), a clip event, a function, a native function
    // (exe 0x142940160 for the event, 0x1429413c0, 0x14293ff70).
    virtual bool ExecuteBuffer(ActionBuffer* pactionbuffer);
    virtual bool ExecuteEvent(const EventId& id);
    virtual bool ExecuteFunction(const FunctionRef& function, const Array<Value>& params);
    virtual bool ExecuteCFunction(CFunctionPtr function, const Array<Value>& params);

    // (appended for sfr_as2_06)
    // The name is a standard member; else a "_" name whose lowercase form is a case-insensitive one, which goes to
    // *plowerCaseName (exe 0x142965e50).
    static bool IsStandardMember(const ASString& memberName, ASString* plowerCaseName = 0);
    // A clip event handler for the event; key down / up handlers are found by the event alone (exe 0x14295d450).
    bool HasClipEventHandler(const EventId& id) const;
    // Calls each clip event handler for the event with this as this; false when there is none (exe 0x142964200).
    bool InvokeClipEventHandlers(Environment* penv, const EventId& id);

    // One standard member name: the member it spells, and whether "_" names match it in any case.
    struct MemberTableType
    {
        const char*    pName;
        StandardMember Id;
        bool           CaseInsensitive;
    };
    // The standard member names, ended by a null name (exe 0x143a512e0).
    static const MemberTableType MemberTable[];
    // Fills the global context's standard member map from the table (exe 0x142961b40).
    static void InitStandardMembers(GlobalContext* pgc);
    // Takes the character off its parent sprite's display list (exe 0x14297d030).
    void RemoveDisplayObject();
    // The clip's AS object is an instance of prototype (exe 0x142962310).
    virtual bool InstanceOf(Environment* penv, const Object* prototype, bool inclInterfaces = true) const;
};

// The script side of a character of an AS2 movie.
inline AvmCharacter* ToAvmCharacter(InteractiveObject* pchar)
{
    return static_cast<AvmCharacter*>(pchar->GetAvmIntObj());
}

inline ASRefCountCollector* Environment::GetCollector()
{
    if (Target)
        return ToAvmCharacter(Target)->GetAS2Root()->GetASGC();
    return 0;
}

inline void Environment::InvalidateOptAdvanceList() const
{
    if (Target)
        Target->GetMovieImpl()->Flags |= MovieImpl::Flag_OptAdvListInvalid;
}

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
