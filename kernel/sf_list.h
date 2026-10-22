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

    // splice every node of other in front of / behind ours; other ends up empty
    void PushListToFront(List& other)
    {
        if (other.IsEmpty())
            return;
        ValueType* head = other.GetFirst();
        ValueType* tail = other.GetLast();
        other.Clear();
        tail->pNext       = Root.pNext;
        head->pPrev       = (ValueType*)&Root;
        Root.pNext->pPrev = tail;
        Root.pNext        = head;
    }
    void PushListToBack(List& other)
    {
        if (other.IsEmpty())
            return;
        ValueType* head = other.GetFirst();
        ValueType* tail = other.GetLast();
        other.Clear();
        tail->pNext       = (ValueType*)&Root;
        head->pPrev       = Root.pPrev;
        Root.pPrev->pNext = head;
        Root.pPrev        = tail;
    }

private:
    List(const List&);
    const List& operator=(const List&);
    ListNode<B> Root;
};

// The same list for nodes whose links are reached through an accessor (Acc::GetPrev/GetNext/SetPrev/SetNext), e.g.
// links that share storage with other fields; the root is a whole T.
template<class T, class Acc>
class List2
{
public:
    typedef T ValueType;

    static const ValueType* GetPrev(const ValueType* p) { return Acc::GetPrev(p); }
    static const ValueType* GetNext(const ValueType* p) { return Acc::GetNext(p); }
    static ValueType*       GetPrev(ValueType* p)       { return Acc::GetPrev(p); }
    static ValueType*       GetNext(ValueType* p)       { return Acc::GetNext(p); }
    static void SetPrev(ValueType* p, ValueType* v)     { Acc::SetPrev(p, v); }
    static void SetNext(ValueType* p, ValueType* v)     { Acc::SetNext(p, v); }

    List2()      { SetPrev(&Root, &Root); SetNext(&Root, &Root); }
    void Clear() { SetPrev(&Root, &Root); SetNext(&Root, &Root); }

    const ValueType* GetFirst() const { return GetNext(&Root); }
    const ValueType* GetLast() const  { return GetPrev(&Root); }
    ValueType*       GetFirst()       { return GetNext(&Root); }
    ValueType*       GetLast()        { return GetPrev(&Root); }

    bool IsEmpty() const                   { return GetNext(&Root) == &Root; }
    bool IsFirst(const ValueType* p) const { return p == GetNext(&Root); }
    bool IsLast(const ValueType* p) const  { return p == GetPrev(&Root); }
    bool IsNull(const ValueType* p) const  { return p == &Root; }

    void PushFront(ValueType* p)
    {
        SetNext(p, GetNext(&Root));
        SetPrev(p, &Root);
        SetPrev(GetNext(&Root), p);
        SetNext(&Root, p);
    }
    void PushBack(ValueType* p)
    {
        SetPrev(p, GetPrev(&Root));
        SetNext(p, &Root);
        SetNext(GetPrev(&Root), p);
        SetPrev(&Root, p);
    }
    static void Remove(ValueType* p)
    {
        SetNext(GetPrev(p), GetNext(p));
        SetPrev(GetNext(p), GetPrev(p));
    }
    void BringToFront(ValueType* p) { Remove(p); PushFront(p); }
    void SendToBack(ValueType* p)   { Remove(p); PushBack(p); }

    // link n in right before / right after p
    static void InsertBefore(ValueType* p, ValueType* n)
    {
        ValueType* prev = GetPrev(p);
        SetNext(n, p);
        SetPrev(n, prev);
        SetNext(prev, n);
        SetPrev(p, n);
    }
    static void InsertAfter(ValueType* p, ValueType* n)
    {
        ValueType* next = GetNext(p);
        SetPrev(n, p);
        SetNext(n, next);
        SetPrev(next, n);
        SetNext(p, n);
    }

    void PushListToFront(List2& other)
    {
        if (other.IsEmpty())
            return;
        ValueType* head = other.GetFirst();
        ValueType* tail = other.GetLast();
        other.Clear();
        SetNext(tail, GetNext(&Root));
        SetPrev(head, &Root);
        SetPrev(GetNext(&Root), tail);
        SetNext(&Root, head);
    }

private:
    List2(const List2&);
    const List2& operator=(const List2&);
    ValueType Root;
};

}  // namespace Scaleform

#endif
