// Recovered Scaleform GFx 4.1.18: intrusive doubly linked list (the root node is a ListNode inside the List object).
#ifndef MS2_SF_KERNEL_LIST_H
#define MS2_SF_KERNEL_LIST_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform {

template<class T>
struct ListNode
{
    union { T* pPrev; void* pVoidPrev; };
    union { T* pNext; void* pVoidNext; };

    void RemoveNode()
    {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
    }
    void ReplaceNodeWith(T* n)
    {
        pPrev->pNext = n;
        pNext->pPrev = n;
        n->pPrev = pPrev;
        n->pNext = pNext;
    }
    void InsertNodeAfter(T* n)
    {
        n->pPrev = pNext->pPrev;
        n->pNext = pNext;
        pNext->pPrev = n;
        pNext = n;
    }
    void InsertNodeBefore(T* n)
    {
        n->pNext = pNext->pPrev;
        n->pPrev = pPrev;
        pPrev->pNext = n;
        pPrev = n;
    }
};

template<class T, class B = T>
class List
{
public:
    typedef T ValueType;

    List()       { Root.pNext = Root.pPrev = (ValueType*)&Root; }
    void Clear() { Root.pNext = Root.pPrev = (ValueType*)&Root; }

    const ValueType* GetFirst() const { return (const ValueType*)Root.pNext; }
    const ValueType* GetLast() const  { return (const ValueType*)Root.pPrev; }
    ValueType*       GetFirst()       { return (ValueType*)Root.pNext; }
    ValueType*       GetLast()        { return (ValueType*)Root.pPrev; }

    bool IsEmpty() const                  { return Root.pVoidNext == (const T*)(const B*)&Root; }
    bool IsFirst(const ValueType* p) const { return p == Root.pNext; }
    bool IsLast(const ValueType* p) const  { return p == Root.pPrev; }
    bool IsNull(const ValueType* p) const  { return p == (const T*)(const B*)&Root; }

    static const ValueType* GetPrev(const ValueType* p) { return (const ValueType*)p->pPrev; }
    static const ValueType* GetNext(const ValueType* p) { return (const ValueType*)p->pNext; }
    static ValueType*       GetPrev(ValueType* p)       { return (ValueType*)p->pPrev; }
    static ValueType*       GetNext(ValueType* p)       { return (ValueType*)p->pNext; }

    void PushFront(ValueType* p)
    {
        p->pNext = Root.pNext;
        p->pPrev = (ValueType*)&Root;
        Root.pNext->pPrev = p;
        Root.pNext = p;
    }
    void PushBack(ValueType* p)
    {
        p->pPrev = Root.pPrev;
        p->pNext = (ValueType*)&Root;
        Root.pPrev->pNext = p;
        Root.pPrev = p;
    }
    static void Remove(ValueType* p)
    {
        p->pPrev->pNext = p->pNext;
        p->pNext->pPrev = p->pPrev;
    }
    void BringToFront(ValueType* p) { Remove(p); PushFront(p); }
    void SendToBack(ValueType* p)   { Remove(p); PushBack(p); }

private:
    List(const List&);
    const List& operator=(const List&);
    ListNode<B> Root;
};

}  // namespace Scaleform

#endif
