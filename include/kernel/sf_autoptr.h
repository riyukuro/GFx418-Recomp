// Recovered Scaleform 4.1.18 Kernel: Scaleform::AutoPtr, a single-owner pointer whose ownership can be waived.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// (gfx/gfx_moviedef.h keeps an older GFx::AutoPtr of its own; the exe's mangled names use this one.)
#ifndef MS2_SF_KERNEL_AUTOPTR_H
#define MS2_SF_KERNEL_AUTOPTR_H

#include "sf_types.h"

namespace Scaleform {

template<class T>
class AutoPtr
{
    T*   pObject;
    bool Owner;

public:
    AutoPtr(T* p = 0, bool owner = true) : pObject(p), Owner(owner) {}
    ~AutoPtr() { Reset(); }

    // Deletes the held object when owned (ownership is dropped before the delete) and takes p.
    void Reset(T* p = 0, bool owner = true)
    {
        if (pObject != p)
        {
            if (pObject && Owner)
            {
                Owner = false;
                delete pObject;
            }
            pObject = p;
        }
        Owner = (p && owner);
    }

    AutoPtr& operator=(T* p)
    {
        Reset(p);
        return *this;
    }

    T*   operator->() const { return pObject; }
    T&   operator*() const  { return *pObject; }
    T*   GetPtr() const     { return pObject; }
    operator T*() const     { return pObject; }
    bool operator!() const  { return pObject == 0; }
    bool operator==(const T* p) const { return pObject == p; }
    bool operator!=(const T* p) const { return pObject != p; }
};

} // namespace Scaleform

#endif
