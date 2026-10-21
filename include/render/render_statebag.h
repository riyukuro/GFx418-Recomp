// Recovered Scaleform 4.1.18 Render: the per-node state list (Render_StateBag). A TreeNode's optional attributes
// (blend mode, scale9 grid, filters, mask, 3D matrices) are {interface, data} pairs. A bag holding one state keeps
// it inline with bit 0 of the interface word set; more states live in a shared ref-counted array whose size sits in
// the interface word shifted left by one.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The array block is the 4-byte reference count directly followed by the states (at +4, not 8-aligned: GetAt and
// GetState index from +4). Each state type has one Interface singleton, registered by its constructor in the
// StateType_Interfaces table (0x143b160a0). Bodies in sfr_render_03 (Render_StateBag).
#ifndef MS2_SF_RENDER_STATEBAG_H
#define MS2_SF_RENDER_STATEBAG_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_atomic.h"
#include "ms2/scaleform/kernel/sf_refcount.h"

namespace Scaleform { namespace Render {

class State;
class StateBag;

enum StateType
{
    State_None,
    State_BlendMode,
    State_Scale9,
    State_Filter,
    State_MaskNode,
    State_ViewMatrix3D,
    State_ProjectionMatrix3D,
    State_Internal_MaskOwner,   // set on the masked node's mask, points back at the owner (7: no user data state yet)
    State_Type_Count
};

class StateData
{
    friend class State;
    friend class StateBag;

    ~StateData() {}

public:
    // lifetime manager of one state type (one static instance per type), 0x10 bytes
    class Interface
    {
        StateType Type;
        Interface* getThis() { return this; }

    public:
        Interface(StateType type);
        virtual ~Interface() {}

        StateType GetType() const { return Type; }
        static Interface* FromStateType(StateType type);   // inlined in Render_StateBag

        // which references AddRef/Release really touch: tree nodes are counted by the advance thread only
        enum RefBehaviour
        {
            Ref_All,
            Ref_NoTreeNode,
            Ref_ReleaseTreeNodeOnly
        };
        virtual void AddRef(void* data, RefBehaviour b) = 0;
        virtual void Release(void* data, RefBehaviour b) = 0;
    };

    // a plain value, nothing to count
    class Interface_Value : public Interface
    {
    public:
        Interface_Value(StateType type) : Interface(type) {}
        virtual void AddRef(void*, RefBehaviour) {}
        virtual void Release(void*, RefBehaviour) {}
    };

    // a RefCountImpl object
    class Interface_RefCountImpl : public Interface
    {
    public:
        Interface_RefCountImpl(StateType type) : Interface(type) {}
        virtual void AddRef(void* data, RefBehaviour) { ((RefCountImpl*)data)->AddRef(); }
        virtual void Release(void* data, RefBehaviour b)
        {
            if (b != Ref_ReleaseTreeNodeOnly)
                ((RefCountImpl*)data)->Release();
        }
    };

protected:
    // no AddRef: the callers count
    StateData(Interface* i = 0, void* data = 0)
    {
        pInterface = i;
        pData      = data;
    }
    StateData(const StateData& src)
    {
        pInterface = src.pInterface;
        pData      = src.pData;
    }

    struct ArrayData
    {
        volatile int RefCount;

        void   AddRef() { AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, 1); }
        void   Release(UPInt count);
        State* GetStates() { return (State*)(void*)((char*)this + sizeof(int)); }
    };

    union {
        Interface* pInterface;
        UPInt      ArraySize;      // bit 0 set: single inline state; otherwise array size << 1
    };
    union {
        void*      pData;
        UPInt      DataValue;
        ArrayData* pArray;
    };

    Interface* getInterface() const        { return (Interface*)(ArraySize & ~(UPInt)1); }
    Interface* getInterface_Unsafe() const { return pInterface; }
    void       initSingleItem(Interface* i, void* data) { ArraySize = ((UPInt)i) | 1; pData = data; }
    void       initArrayItem(Interface* i, void* data)  { pInterface = i; pData = data; }
    void       initArray(ArrayData* arr, UPInt size)    { ArraySize = size << 1; pArray = arr; }
    bool       isEmpty() const      { return ArraySize == 0; }
    bool       isSingleItem() const { return (ArraySize & 1) != 0; }
    UPInt      getArraySize() const { return ArraySize >> 1; }

    void addRefBag_NotEmpty() const;
    void destroyBag_NotEmpty();
    void assignBag(const StateData& src);
};

class State : public StateData
{
public:
    Interface* GetInterface() const { return getInterface(); }
    void*      GetData() const      { return pData; }
    StateType  GetType() const
    {
        Interface* i = getInterface();
        return i ? i->GetType() : State_None;
    }

    enum NoAddRefType { NoAddRef };
    State(Interface* i, void* data, NoAddRefType) : StateData(i, data) {}
    State(Interface* i, void* data) : StateData(i, data)
    {
        if (i)
            i->AddRef(data, Interface::Ref_All);
    }
    State(const State& other) : StateData(other)
    {
        if (getInterface_Unsafe())
            getInterface_Unsafe()->AddRef(pData, Interface::Ref_All);
    }
    ~State()
    {
        if (getInterface_Unsafe())
            getInterface_Unsafe()->Release(pData, Interface::Ref_All);
    }
};

class StateBag : private StateData
{
public:
    StateBag() : StateData() {}
    StateBag(const StateBag& src) : StateData(src)
    {
        if (!src.isEmpty())
            addRefBag_NotEmpty();
    }
    ~StateBag()
    {
        if (!isEmpty())
            destroyBag_NotEmpty();
    }
    void operator=(const StateBag& src)
    {
        if ((ArraySize | src.ArraySize) != 0)
            assignBag(src);
    }

    const State* GetState(StateType type) const;
    void         SetStateVoid(Interface* i, void* data);
    void         SetState(Interface* i, RefCountImpl* data) { SetStateVoid(i, data); }
    void         SetState(const State& s) { SetStateVoid(s.GetInterface(), s.GetData()); }
    bool         RemoveState(StateType type);

    bool         IsEmpty() const { return isEmpty(); }
    UPInt        GetSize() const { return isSingleItem() ? 1 : getArraySize(); }
    const State& GetAt(UPInt index) const;
    const State& operator[](UPInt index) const { return GetAt(index); }

    template<class S>
    const S* GetState() const { return static_cast<const S*>(GetState(S::GetType_Static())); }

    // drops only the tree-node references (TreeNode::NodeData lifetime protocol)
    void ReleaseNodes() const;

protected:
    ArrayData*  allocData(State* source, UPInt count, UPInt extra = 0);
    ArrayData*  allocData2(State* source1, UPInt count1, State* source2, UPInt count2);
    static void copyArrayAddRef(State* d, State* s, UPInt count);

    State*       toState()       { return (State*)(StateData*)this; }
    const State* toState() const { return (const State*)(const StateData*)this; }
};

}} // namespace Scaleform::Render

#endif
