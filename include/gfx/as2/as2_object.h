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

    bool IsASCharacter() const;
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
    virtual ~Object();
    virtual void  SetValue(Environment* penv, const Value&);
    virtual Value GetValue() const;
    virtual bool  DoesImplement(Environment*, const Object* prototype) const;
    virtual InteractiveObject*       GetASCharacter();
    virtual const InteractiveObject* GetASCharacter() const;
    virtual void  CheckAndResetCtorRef(FunctionObject* pfunc);

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
    virtual Object* CreateNewObject(Environment*);
    virtual int     GetNumArgs() const;

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

}}} // namespace Scaleform::GFx::AS2

#endif
