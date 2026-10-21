// Recovered Scaleform GFx 4.1.18: intrusive binary radix tree keyed on UPInt (bit by bit from the top), used by the
// heaps to find blocks by address/size. Accessor maps a node to its key and links; the root's parent link points back
// at the Root slot, which Remove relies on.
#ifndef MS2_SF_KERNEL_RADIXTREE_H
#define MS2_SF_KERNEL_RADIXTREE_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform {

template<class T, class Accessor>
class RadixTree
{
    enum { KeyBits = 8 * sizeof(UPInt) };

public:
    RadixTree() : Root(0) { }
    void Clear() { Root = 0; }

    // returns the existing node with the same key (node not inserted), else 0
    T* Insert(T* node)
    {
        T** root = &Root;
        Accessor::ClearLinks(node);
        if (Root == 0)
        {
            *root = node;
            Accessor::SetParent(node, (T*)root);
        }
        else
        {
            UPInt key = Accessor::GetKey(node);
            UPInt bits = key;
            T*    head = *root;
            for (;;)
            {
                if (Accessor::GetKey(head) == key)
                    return head;
                T** link = Accessor::GetChildPtr(head, (bits >> (KeyBits - 1)) & 1);
                bits <<= 1;
                if (*link != 0)
                {
                    head = *link;
                }
                else
                {
                    *link = node;
                    Accessor::SetParent(node, head);
                    break;
                }
            }
        }
        return 0;
    }

    // replace node by rotor (a leaf already detached, or 0)
    void Remove(T* node, T* rotor)
    {
        T* parent = Accessor::GetParent(node);
        if (parent != 0)
        {
            T** root = &Root;
            if (node == *root)
            {
                *root = rotor;
            }
            else
            {
                UPInt ic = Accessor::GetChild(parent, 0) != node;
                Accessor::SetChild(parent, ic, rotor);
            }
            if (rotor != 0)
            {
                T* child;
                Accessor::SetParent(rotor, parent);
                if ((child = Accessor::GetChild(node, 0)) != 0)
                {
                    Accessor::SetChild(rotor, 0, child);
                    Accessor::SetParent(child, rotor);
                }
                if ((child = Accessor::GetChild(node, 1)) != 0)
                {
                    Accessor::SetChild(rotor, 1, child);
                    Accessor::SetParent(child, rotor);
                }
            }
        }
        Accessor::ClearLinks(node);
    }

    // the replacement is any leaf below the node (rightmost path first)
    void Remove(T* node)
    {
        T*  rotor;
        T** rp;
        if (((rotor = *(rp = Accessor::GetChildPtr(node, 1))) != 0) ||
            ((rotor = *(rp = Accessor::GetChildPtr(node, 0))) != 0))
        {
            T** cp;
            while ((*(cp = Accessor::GetChildPtr(rotor, 1)) != 0) || (*(cp = Accessor::GetChildPtr(rotor, 0)) != 0))
                rotor = *(rp = cp);
            *rp = 0;
        }
        Remove(node, rotor);
    }

    const T* FindEqual(UPInt key) const
    {
        const T* node = Root;
        UPInt    bits = key;
        while (node && Accessor::GetKey(node) != key)
        {
            node = Accessor::GetChild(node, (bits >> (KeyBits - 1)) & 1);
            bits <<= 1;
        }
        return node;
    }

    static const T* GetLeftmost(const T* node) { return Accessor::GetChild(node, Accessor::GetChild(node, 0) == 0); }
    static const T* GetRightmost(const T* node) { return Accessor::GetChild(node, Accessor::GetChild(node, 1) != 0); }

    // smallest key >= key
    const T* FindGrEq(UPInt key) const
    {
        const T* best = 0;
        UPInt    rkey = ~UPInt(0);
        UPInt    nkey;
        UPInt    diff;
        const T* node = Root;
        if (node != 0)
        {
            const T* rst = 0;   // deepest right subtree not taken: every key there is greater
            UPInt    bits = key;
            for (;;)
            {
                const T* rt;
                nkey = Accessor::GetKey(node);
                diff = nkey - key;
                if (nkey >= key && diff < rkey)
                {
                    best = node;
                    if ((rkey = diff) == 0)
                        return best;
                }
                rt = Accessor::GetChild(node, 1);
                node = Accessor::GetChild(node, (bits >> (KeyBits - 1)) & 1);
                if (rt != 0 && rt != node)
                    rst = rt;
                if (node == 0)
                {
                    node = rst;
                    break;
                }
                bits <<= 1;
            }
        }
        while (node)
        {
            nkey = Accessor::GetKey(node);
            diff = nkey - key;
            if (nkey >= key && diff < rkey)
            {
                rkey = diff;
                best = node;
            }
            node = GetLeftmost(node);
        }
        return best;
    }

    // largest key <= key
    const T* FindLeEq(UPInt key) const
    {
        const T* best = 0;
        UPInt    rkey = ~UPInt(0);
        UPInt    nkey;
        UPInt    diff;
        const T* node = Root;
        if (node != 0)
        {
            const T* lst = 0;
            UPInt    bits = key;
            for (;;)
            {
                const T* lt;
                nkey = Accessor::GetKey(node);
                diff = key - nkey;
                if (nkey <= key && diff < rkey)
                {
                    best = node;
                    if ((rkey = diff) == 0)
                        return best;
                }
                lt = Accessor::GetChild(node, 0);
                node = Accessor::GetChild(node, (bits >> (KeyBits - 1)) & 1);
                if (lt != 0 && lt != node)
                    lst = lt;
                if (node == 0)
                {
                    node = lst;
                    break;
                }
                bits <<= 1;
            }
        }
        while (node)
        {
            nkey = Accessor::GetKey(node);
            diff = key - nkey;
            if (nkey <= key && diff < rkey)
            {
                rkey = diff;
                best = node;
            }
            node = GetRightmost(node);
        }
        return best;
    }

    T* Root;
};

// Radix tree allowing equal keys: nodes with the same key hang off the tree node in a ring (pPrev/pNext).
template<class T, class Accessor>
class RadixTreeMulti
{
public:
    void Insert(T* node)
    {
        node->pPrev = node;
        node->pNext = node;
        T* head = Tree.Insert(node);
        if (head)
        {
            node->pNext = head->pNext;
            node->pPrev = head;
            head->pNext = node;
            node->pNext->pPrev = node;
        }
    }

    void Remove(T* node)
    {
        if (node->pPrev != node)
        {
            T* rotor;
            T* f = node->pNext;
            rotor = node->pPrev;
            f->pPrev = rotor;
            rotor->pNext = f;
            Tree.Remove(node, rotor);
        }
        else
        {
            Tree.Remove(node);
        }
    }

    const T* FindBestGrEq(UPInt key) { return Tree.FindGrEq(key); }
    const T* FindBestLeEq(UPInt key) { return Tree.FindLeEq(key); }

    T* PullBestGrEq(UPInt key)
    {
        T* node = (T*)Tree.FindGrEq(key);
        if (node)
        {
            node = (T*)node->pNext;
            Remove(node);
        }
        return node;
    }
    T* PullBestLeEq(UPInt key)
    {
        T* node = (T*)Tree.FindLeEq(key);
        if (node)
        {
            node = (T*)node->pNext;
            Remove(node);
        }
        return node;
    }

    RadixTree<T, Accessor> Tree;
};

}  // namespace Scaleform

#endif
