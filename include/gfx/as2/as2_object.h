// Recovered Scaleform 4.1.18 GFx AS2: the object interface shared by script objects and display objects, the
// script object (members hash, resolve handler, watchpoints) and function objects.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals
// (the declaration order reproduces the exe vftables).
#ifndef MS2_SF_GFX_AS2_OBJECT_H
#define MS2_SF_GFX_AS2_OBJECT_H

#include "as2_value.h"

namespace Scaleform { namespace GFx {

// Member hash of a script object, keyed by interned strings and allocated in the action script heap
// (one table pointer). Only the layout and read-only iteration are recovered so far: the table is the kernel
// hash set of (key, value) nodes with uncached slots { NextInChain, node }.
struct ASStringHashFunctor;

template<class T>
class ASStringHash_GC
{
public:
    typedef HashNode<ASString, T, ASStringHashFunctor>                       NodeType;
    typedef HashsetNodeEntry<NodeType, typename NodeType::NodeHashF>         EntryType;
    typedef HashSetBase<NodeType, typename NodeType::NodeHashF, typename NodeType::NodeAltHashF,
                        AllocatorLH<NodeType, StatMV_ASString_Mem>, EntryType> SetType;
    typedef typename SetType::ConstIterator                                  ConstIterator;

    void* pTable;

    const SetType& GetSet() const { return *reinterpret_cast<const SetType*>(this); }
    ConstIterator  Begin() const  { return GetSet().Begin(); }
    ConstIterator  End() const    { return GetSet().End(); }
};

class Movie;

// User data an application attaches to a script object (GFx::Value::SetUserData); told when the object dies.
// vftable { dtor, OnDestroy }.
class ASUserData : public RefCountBase<ASUserData, Stat_Default_Mem>
{
public:
    void* pLastObjectInterface; // +0x10 weak descriptor of the GFx::Value last set
    void* pLastData;            // +0x18
    bool  IsLastDispObj;        // +0x20

    virtual ~ASUserData() {}
    virtual void OnDestroy(Movie* pmovie, void* pobject) = 0;
};

// ASUserData::SetLastObjectValue (exe 0x142575f10; GFx::Value is not recovered, so it is bound as a free function).
void ASUserData_SetLastObjectValue(ASUserData* puserData, void* pobjIfc, void* pdata, bool isdobj);

namespace AS2 {

// Interface of everything a script can address as an object (script objects at +0x20, characters).
// vftable slots: 0x00 dtor .. 0xa0 Unwatch.
class ObjectInterface
{
public:
    enum ObjectType
    {
        Object_Unknown,
        Object_BaseCharacter,
        Object_Sprite,
        Object_Button,
        Object_TextField,
        Object_Video,
        Object_ASObject,
        Object_Array,
        Object_String,
        Object_Number,
        Object_Boolean,
        Object_MovieClipObject,
        Object_ButtonASObject,
        Object_TextFieldASObject,
        Object_VideoASObject,
        Object_Matrix,
        Object_Point,
        Object_Rectangle,
        Object_ColorTransform,
        Object_Capabilities,
        Object_Transform,
        Object_Color,
        Object_Key,
        Object_Function,
        Object_Stage,
        Object_MovieClipLoader,
        Object_BitmapData,
        Object_LoadVars,
        Object_XML,
        Object_XMLNode,
        Object_TextFormat,
        Object_StyleSheet,
        Object_Sound,
        Object_NetConnection,
        Object_NetStream,
        Object_Date,
        Object_AsBroadcaster,
        Object_BitmapFilter,
        Object_DropShadowFilter,
        Object_GlowFilter,
        Object_BlurFilter,
        Object_BevelFilter,
        Object_ColorMatrixFilter,
        Object_TextSnapshot,
        Object_SharedObject
    };

    class UserDataHolder;
    class MemberVisitor;

    UserDataHolder* pUserDataHolder; // +0x08
    Ptr<Object>     pProto;          // +0x10

    ObjectInterface();
    virtual ~ObjectInterface();

    virtual const char* GetTextValue(Environment* penv = 0) const;
    virtual ObjectType  GetObjectType() const;
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);
    virtual bool FindMember(ASStringContext* psc, const ASString& name, Member* pmember);
    virtual bool DeleteMember(ASStringContext* psc, const ASString& name);
    virtual bool SetMemberFlags(ASStringContext* psc, const ASString& name, const UByte flags);
    virtual void VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags = 0,
                              const ObjectInterface* instance = 0) const;
    virtual bool HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes);
    virtual bool SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val,
                              const PropFlags& flags = PropFlags());
    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);
    virtual FunctionRef ToFunction();
    virtual void        Set__proto__(ASStringContext* psc, Object* protoObj);
    virtual FunctionRef Get__constructor__(ASStringContext* psc);
    virtual bool IsSuper() const;
    virtual bool IsBuiltinPrototype() const;
    virtual void AddInterface(ASStringContext* psc, int index, FunctionObject* ctor);
    virtual bool InstanceOf(Environment* penv, const Object* prototype, bool inclInterfaces = true) const;
    virtual bool Watch(ASStringContext* psc, const ASString& prop, const FunctionRef& callback,
                       const Value& userData);
    virtual bool Unwatch(ASStringContext* psc, const ASString& prop);

    // A display object (sprite, button, text field, video) rather than a script object.
    bool IsASCharacter() const
    {
        int type = GetObjectType();
        return type >= Object_Sprite && type <= Object_Video;
    }
    bool IsFunction() const { return GetObjectType() == Object_Function; }
    // The display object of a character, 0 for a script object (as2_avmcharacter.h).
    inline InteractiveObject* ToCharacter();
    // The clip of a movie clip object, 0 for anything else (as2_avmsprite.h).
    inline Sprite* ToSprite();

    // The object on the prototype chain that has the member itself, 0 for none (exe 0x142944a00).
    Object* FindOwner(ASStringContext* psc, const ASString& name);
    // The function of the constructor member, a null reference without one (exe 0x1429583d0).
    FunctionRef Get_constructor(ASStringContext* psc);
};

// The user data of an object and the movie it was set from. 0x10 bytes.
class ObjectInterface::UserDataHolder : public NewOverrideBase<StatMV_ActionScript_Mem>
{
public:
    Movie*      pMovieView; // +0x00
    ASUserData* pUserData;  // +0x08

    // Drops the weak reference of the user data and tells it that the object is gone.
    void NotifyDestroy(ObjectInterface* pthis) const
    {
        if (pUserData)
        {
            ASUserData_SetLastObjectValue(pUserData, 0, 0, false);
            pUserData->OnDestroy(pMovieView, pthis);
        }
    }
};

// Script object: GC base at +0, ObjectInterface at +0x20. 0x68 bytes.
class Object : public ASRefCountBase<Object>, public ObjectInterface
{
public:
    struct Watchpoint;

    ASStringHash_GC<Member>      Members;          // +0x38
    FunctionRef                  ResolveHandler;   // +0x40
    ASStringHash_GC<Watchpoint>* pWatchpoints;     // +0x58
    bool                         ArePropertiesSet; // +0x60
    bool                         IsListenerSet;    // +0x61

    // Primary vftable: 0x00 ExecuteForEachChild_GC, 0x08 Finalize_GC, 0x10 dtor, then these.
    Object(Environment* penv); // exe 0x14291f810
    virtual ~Object();
    virtual void  SetValue(Environment* penv, const Value&);
    virtual Value GetValue() const;
    virtual bool  DoesImplement(Environment*, const Object* prototype) const;
    virtual InteractiveObject*       GetASCharacter();
    virtual const InteractiveObject* GetASCharacter() const;
    virtual void  CheckAndResetCtorRef(FunctionObject* pfunc);

    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val); // exe 0x142953280
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);       // exe 0x14294f7d0
    virtual bool DeleteMember(ASStringContext* psc, const ASString& name);             // exe 0x1429388e0

protected:
    Object(ASRefCountCollector* pcc);

    virtual void ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const;
    virtual void Finalize_GC();

    // Members, the resolve handler, the watchpoints and __proto__ (defined in sfr_as2_02).
    template<class Functor> void ForEachChild_GC(Collector* prcc) const;
};

// Watch() callback of one member. 0x38 bytes.
struct Object::Watchpoint
{
    FunctionRef Callback; // +0x00
    Value       UserData; // +0x18

    Watchpoint(const Watchpoint& o); // exe 0x142923fd0
    ~Watchpoint();                   // exe 0x142926100

    // Release before collection: only the user data holds counted references.
    void Finalize_GC()
    {
        Callback.Finalize_GC();
        UserData.Finalize_GC();
    }

    template<class Functor> void ForEachChild_GC(Collector* prcc) const
    {
        Callback.template ForEachChild_GC<Functor>(prcc);
        UserData.template ForEachChild_GC<Functor>(prcc);
    }
};

// Script-callable function. 0x68 bytes.
class FunctionObject : public Object
{
public:
    virtual ~FunctionObject();
    virtual Environment* GetEnvironment(const FnCall& fn, Ptr<InteractiveObject>* ptargetCh);
    virtual void    Invoke(const FnCall& fn, LocalFrame*, const char* pmethodName);
    virtual bool    IsNull() const;
    virtual bool    IsEqual(const FunctionObject& f) const;
    virtual bool    IsCFunction() const;
    virtual bool    IsAsFunction() const;
    virtual Object* CreateNewObject(Environment*) const;
    virtual int     GetNumArgs() const;

    // The object of the prototype member, 0 without one (exe 0x142954b40).
    Object* GetPrototype(ASStringContext* psc);

protected:
    FunctionObject(ASRefCountCollector* pcc);
};

// Native function. 0x70 bytes.
class CFunctionObject : public FunctionObject
{
public:
    CFunctionPtr pFunction; // +0x68

    virtual ~CFunctionObject();

protected:
    CFunctionObject(ASRefCountCollector* pcc);
};

// Function defined in script (the action buffer of a DefineFunction). Its instances are plain objects.
class AsFunctionObject : public FunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936880

    MovieImpl*           pMovieRoot;   // +0x68 0 for a function without a target
    Ptr<CharacterHandle> TargetHandle; // +0x70

    // The character the function was defined in, 0 once it is gone (exe 0x142956230).
    InteractiveObject* GetTargetCharacter();
};

SF_FORCEINLINE void FunctionRefBase::Init(FunctionObject* poriginal, UByte flags)
{
    Flags    = flags;
    Function = poriginal;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
}

// Counted copy of the function; the frame keeps the weak flag of the original.
SF_FORCEINLINE void FunctionRefBase::Init(const FunctionRefBase& orig, UByte flags)
{
    Flags    = flags;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        SetLocalFrame(orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

SF_FORCEINLINE void FunctionRef::Invoke(const FnCall& fn, const char* pmethodName) const
{
    Function->Invoke(fn, pLocalFrame, pmethodName);
}

inline FunctionRef Value::ToFunction(const Environment* penv) const
{
    if (T.Type == FUNCTION)
        return V.FunctionValue;
    else if (T.Type == FUNCTIONNAME)
        return ResolveFunctionName(penv);
    return FunctionRef();
}

}}} // namespace Scaleform::GFx::AS2

#endif
