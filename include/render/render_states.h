// Recovered Scaleform 4.1.18 Render: the TreeNode state kinds kept in a StateBag (Render_States), plus the
// ref-counted payloads they point at (Scale9GridRect, the 3D matrix holders).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The Interface singletons are .data objects of Render_States (not recovered yet, constructed by its dynamic
// initializers): Scale9 0x143b172a8, MaskNode 0x143b172c8, BlendMode 0x143b172d8, Filter 0x143b172e8,
// ViewMatrix3D 0x143b172f8, Internal_MaskOwner 0x143b17308, ProjectionMatrix3D 0x143b17318 (symbols-manual rows).
// This build has no OrigScale9Parent state.
#ifndef MS2_SF_RENDER_STATES_H
#define MS2_SF_RENDER_STATES_H

#include "ms2/scaleform/include/render/render_statebag.h"
#include "ms2/scaleform/include/render/render_types2d.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"
#include "ms2/scaleform/include/render/render_filters.h"
#include "ms2/scaleform/include/render/render_constants.h"

namespace Scaleform { namespace Render {

class TreeNode;

// a node's scale9 grid rectangle (0x20 bytes)
struct Scale9GridRect : public RefCountBase<Scale9GridRect, Stat_Default_Mem>
{
    RectF Scale9;
};

// ref-counted 3D matrices for the view / projection states (the counter base is laid out first: 0x40 / 0x50 bytes)
template<class T>
class Matrix3x4Ref : public Matrix3x4<T>, public RefCountBase<Matrix3x4<T>, Stat_Default_Mem>
{
public:
    void operator=(const Matrix3x4<T>& m) { memcpy(this->M, m.M, sizeof(this->M)); }
};
typedef Matrix3x4Ref<float> Matrix3FRef;

template<class T>
class Matrix4x4Ref : public Matrix4x4<T>, public RefCountBase<Matrix4x4<T>, Stat_Default_Mem>
{
public:
    void operator=(const Matrix4x4<T>& m) { memcpy(this->M, m.M, sizeof(this->M)); }
};
typedef Matrix4x4Ref<float> Matrix4FRef;

class BlendState : public State
{
public:
    typedef State::Interface_Value Interface;
    static Interface InterfaceImpl;
    static StateType GetType_Static() { return State_BlendMode; }

    BlendState(BlendMode mode) : State(&InterfaceImpl, (void*)mode, NoAddRef) {}
    BlendMode GetBlendMode() const { return (BlendMode)DataValue; }
};

class Scale9State : public State
{
public:
    typedef State::Interface_RefCountImpl Interface;
    static Interface InterfaceImpl;
    static StateType GetType_Static() { return State_Scale9; }

    Scale9State(Scale9GridRect* r) : State(&InterfaceImpl, (void*)r) {}
    RectF GetRect() const { return ((Scale9GridRect*)GetData())->Scale9; }
};

// the mask's tree node: counted only on the advance thread (Ref_NoTreeNode leaves it alone)
class MaskNodeState : public State
{
public:
    class Interface : public State::Interface
    {
    public:
        Interface() : State::Interface(State_MaskNode) {}
        virtual void AddRef(void* data, RefBehaviour b);
        virtual void Release(void* data, RefBehaviour b);
    };
    static Interface InterfaceImpl;
    static StateType GetType_Static() { return State_MaskNode; }

    MaskNodeState(TreeNode* node) : State(&InterfaceImpl, (void*)node) {}
    TreeNode* GetNode() const { return (TreeNode*)pData; }
};

class ViewMatrix3DState : public State
{
public:
    typedef State::Interface_RefCountImpl Interface;
    static Interface InterfaceImpl;
    static StateType GetType_Static() { return State_ViewMatrix3D; }

    ViewMatrix3DState(const Matrix3FRef* m)
        : State(&InterfaceImpl, (RefCountBase<Matrix3F, Stat_Default_Mem>*)m) {}
    const Matrix3FRef* GetViewMatrix3D() const
    {
        return (Matrix3FRef*)(RefCountBase<Matrix3F, Stat_Default_Mem>*)GetData();
    }
};

class ProjectionMatrix3DState : public State
{
public:
    typedef State::Interface_RefCountImpl Interface;
    static Interface InterfaceImpl;
    static StateType GetType_Static() { return State_ProjectionMatrix3D; }

    ProjectionMatrix3DState(const Matrix4FRef* m)
        : State(&InterfaceImpl, (RefCountBase<Matrix4F, Stat_Default_Mem>*)m) {}
    const Matrix4FRef* GetProjectionMatrix3D() const
    {
        return (Matrix4FRef*)(RefCountBase<Matrix4F, Stat_Default_Mem>*)GetData();
    }
};

// on a mask node: the node it masks (not counted)
class Internal_MaskOwnerState : public State
{
public:
    typedef State::Interface_Value Interface;
    static Interface InterfaceImpl;
    static StateType GetType_Static() { return State_Internal_MaskOwner; }

    Internal_MaskOwnerState(TreeNode* owner) : State(&InterfaceImpl, (void*)owner, NoAddRef) {}
    TreeNode* GetMaskOwner() const { return (TreeNode*)DataValue; }
};

class FilterState : public State
{
public:
    typedef State::Interface_RefCountImpl Interface;
    static Interface InterfaceImpl;
    static StateType GetType_Static() { return State_Filter; }

    FilterState(FilterSet* filters) : State(&InterfaceImpl, (void*)filters) {}
    const FilterSet* GetFilters() const { return (const FilterSet*)GetData(); }
    UPInt            GetFilterCount() const { return GetFilters()->GetFilterCount(); }
    const Filter*    GetFilter(UPInt index) const { return GetFilters()->GetFilter(index); }
};

}} // namespace Scaleform::Render

#endif
