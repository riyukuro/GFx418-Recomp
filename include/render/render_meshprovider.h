// Recovered Scaleform 4.1.18 Render: the mesh providers the tree nodes get their meshes from, only as far as the
// recovered units use them so far (a provider's reference count, through the MeshProvider subobject at +0x10).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_MESHPROVIDER_H
#define MS2_SF_RENDER_MESHPROVIDER_H

#include "../kernel/sf_refcount.h"

namespace Scaleform { namespace Render {

// Source of the meshes of one shape. Only the reference counting slots are declared.
class MeshProvider
{
public:
    virtual ~MeshProvider() {}
    virtual void AddRef() {}
    virtual void Release() {}
};

// A reference counted provider: RefCountBase at +0, MeshProvider at +0x10.
class MeshProvider_RCImpl : public RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>, public MeshProvider
{
public:
    virtual void AddRef() { RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>::AddRef(); }
    virtual void Release() { RefCountBase<MeshProvider_RCImpl, Stat_Default_Mem>::Release(); }
};

// A provider whose meshes are keyed by scale (shapes and their bound copies).
class MeshProvider_KeySupport : public MeshProvider_RCImpl
{
};

class ShapeMeshProvider : public MeshProvider_KeySupport
{
};

}} // namespace Scaleform::Render

#endif
