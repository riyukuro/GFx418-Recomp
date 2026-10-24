// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the tree node TU
// (Render_TreeNode): TreeNode state setters, the child array of TreeContainer, bounds propagation, cloning and the
// container's cache node creation.
// MS2-UNIT: sfr_render_03c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14261b310-0x14261b450 .text$mn
// MS2-RANGE: 0x14261b450-0x14261e1c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <math.h>
#include "ms2/scaleform/include/render/render_treenode.h"
#include "ms2/scaleform/include/render/render_treecachenode.h"

namespace Scaleform { namespace Render {

// this build tests bounds emptiness with >= and compares rectangles x1, x2, y1, y2
static inline bool isEmptyBounds(const RectF& r) { return r.x1 >= r.x2 || r.y1 >= r.y2; }
static inline bool boundsDiffer(const RectF& a, const RectF& b)
{
    return a.x1 != b.x1 || a.x2 != b.x2 || a.y1 != b.y1 || a.y2 != b.y2;
}

// the shadow / bevel offset grows the bounds on one side only
static inline float filterOffset(float offset, float scale) { return ceilf((float)fabs(offset) * scale); }

// ***** TreeNode::NodeData

// @0x14261dd30
bool TreeNode::NodeData::expandByFilterBounds(RectF* bounds, bool boundsEmpty) const
{
    if (boundsEmpty)
        return boundsEmpty;
    const FilterState* state = GetState<FilterState>();
    if (state)
    {
        const FilterSet* filters = state->GetFilters();
        if (filters)
        {
            for (unsigned i = 0; i < filters->GetFilterCount(); i++)
                expandByFilterBounds(filters->GetFilter(i), bounds);
        }
    }
    return false;
}

// @0x14261ddb0
// MS2-FUNCTIONAL: stack frame size and register allocation differ
void TreeNode::NodeData::expandByFilterBounds(const Filter* filter, RectF* bounds)
{
    if (!filter)
        return;
    if (filter->GetFilterType() > Filter_Bevel)
        return;

    const BlurFilterParams& params = ((const BlurFilterImpl*)filter)->GetParams();
    float scale  = (params.Mode & BlurFilterParams::Mode_Highlight) ? 1.0f : 0.5f;
    float passes = (float)params.Passes;
    bounds->Expand(ceilf(passes * params.BlurX) * scale, ceilf(passes * params.BlurY) * scale);

    if (filter->GetFilterType() == Filter_Shadow || filter->GetFilterType() == Filter_Bevel)
    {
        float x = params.Offset.x;
        float y = params.Offset.y;
        bounds->HExpand(x > 0 ? 0 : filterOffset(x, scale), x > 0 ? filterOffset(x, scale) : 0);
        bounds->VExpand(y > 0 ? 0 : filterOffset(y, scale), y > 0 ? filterOffset(y, scale) : 0);
    }
}

// @0x14261daf0
// MS2-FUNCTIONAL: stack frame size and register allocation differ
void TreeNode::NodeData::contractByFilterBounds(RectF* bounds) const
{
    const FilterState* state = GetState<FilterState>();
    if (!state)
        return;
    const FilterSet* filters = state->GetFilters();
    if (!filters)
        return;

    for (unsigned i = 0; i < filters->GetFilterCount(); i++)
    {
        const Filter* filter = filters->GetFilter(filters->GetFilterCount() - i - 1);
        if (filter->GetFilterType() > Filter_Bevel)
            continue;

        const BlurFilterParams& params = ((const BlurFilterImpl*)filter)->GetParams();
        float scale  = (params.Mode & BlurFilterParams::Mode_Highlight) ? 2.0f : 1.0f;
        float passes = (float)params.Passes;
        bounds->Contract(ceilf(passes * params.BlurX) * scale, ceilf(passes * params.BlurY) * scale);

        if (filter->GetFilterType() == Filter_Shadow || filter->GetFilterType() == Filter_Bevel)
        {
            // both offsets contract horizontally
            float x = params.Offset.x;
            float y = params.Offset.y;
            bounds->HContract(x > 0 ? 0 : filterOffset(x, scale), x > 0 ? filterOffset(x, scale) : 0);
            bounds->HContract(y > 0 ? 0 : filterOffset(y, scale), y > 0 ? filterOffset(y, scale) : 0);
        }
    }
}

// @0x14261cf20
void TreeNode::NodeData::ReleaseNodes() const
{
    if (HasMask())
        removeThisAsMaskOwner(this);
    States.ReleaseNodes();
}

// @0x14261bfc0
// MS2-FUNCTIONAL: stack frame size and register allocation differ
void TreeNode::NodeData::CopyGeomData(TreeNode* destNode, const TreeNode& srcNode)
{
    if (destNode == &srcNode)
        return;

    const NodeData* srcData = srcNode.GetReadOnlyData();
    if (IsVisible() != srcData->IsVisible())
    {
        destNode->SetVisible(srcData->IsVisible());
        if (destNode->GetParent())
            destNode->GetParent()->AddToPropagate();
    }

    if (srcData->Is3D())
    {
        SetMatrix3D(srcData->M3D());

        Matrix4F projection;
        if (srcNode.GetProjectionMatrix3D(&projection))
            destNode->SetProjectionMatrix3D(projection);
        Matrix3F view;
        if (srcNode.GetViewMatrix3D(&view))
            destNode->SetViewMatrix3D(view);
    }
    else
        SetMatrix(srcData->M2D());

    Cx = srcData->Cx;
    destNode->SetBlendMode(srcNode.GetBlendMode());

    RectF scale9 = srcNode.GetScale9Grid();
    if (!isEmptyBounds(scale9))
        destNode->SetScale9Grid(scale9);
}

// @0x14261bc30
TreeNode* TreeNode::NodeData::CloneCreate(Context*) const
{
    return 0;
}

// @0x14261bdf0
// MS2-FUNCTIONAL: exe splits the body into separate .pdata chunks; same calls and stores
bool TreeNode::NodeData::CloneInit(TreeNode* node, Context* context) const
{
    NodeData* data = node->GetWritableData(Change_State_Mask);

    // the mask is cloned along; the mask owner link is rebuilt by SetMaskNode
    bool  hasMask = false;
    UPInt count   = States.GetSize();
    for (UPInt i = 0; i < count; i++)
    {
        const State& state = States.GetAt(i);
        StateType    type  = state.GetType();
        if (type == State_MaskNode)
            hasMask = true;
        else if (type != State_Internal_MaskOwner)
            data->States.SetState(state);
    }

    if (hasMask)
    {
        TreeNode* mask = GetState<MaskNodeState>()->GetNode()->Clone(context);
        node->SetMaskNode(mask);
        if (mask)
            mask->Release();
    }
    return true;
}

// ***** TreeNode

// @0x14261c5c0
void TreeNode::CopyGeomData(const TreeNode& src)
{
    GetWritableData(Change_Matrix | Change_CxForm)->CopyGeomData(this, src);
}

// @0x14261bb50
TreeNode* TreeNode::Clone(Context* context) const
{
    const NodeData* data = GetReadOnlyData();
    TreeNode*       node = data->CloneCreate(context);
    if (node)
        data->CloneInit(node, context);
    return node;
}

// @0x14261d530
void TreeNode::SetMatrix(const Matrix2F& m)
{
    NodeData* data = GetWritableData(Change_Matrix);
    data->SetMatrix(m);
    AddToPropagate();
}

// @0x14261d490
// MS2-FUNCTIONAL: flag test computed in 16-bit registers
void TreeNode::SetMatrix3D(const Matrix3F& m)
{
    NodeData* data = GetWritableData(Change_Matrix + (Is3D() ? 0 : Change_3D));
    data->SetMatrix3D(m);
    AddToPropagate();
}

// @0x14261d7a0
void TreeNode::SetViewMatrix3D(const Matrix3F& m)
{
    NodeData*    data   = GetWritableData(Change_State_ViewMatrix3D);
    Matrix3FRef* matrix = SF_HEAP_AUTO_NEW(this) Matrix3FRef;
    *matrix = m;
    data->States.SetStateVoid(&ViewMatrix3DState::InterfaceImpl, (RefCountBase<Matrix3F, Stat_Default_Mem>*)matrix);
    data->Flags |= NF_HasViewMatrix3D;
    matrix->Release();
}

// @0x14261d5a0
void TreeNode::SetProjectionMatrix3D(const Matrix4F& m)
{
    NodeData*    data   = GetWritableData(Change_State_ProjectionMatrix3D);
    Matrix4FRef* matrix = SF_HEAP_AUTO_NEW(this) Matrix4FRef;
    *matrix = m;
    data->States.SetStateVoid(&ProjectionMatrix3DState::InterfaceImpl,
                              (RefCountBase<Matrix4F, Stat_Default_Mem>*)matrix);
    data->Flags |= NF_HasProjectionMatrix3D;
    matrix->Release();
}

// @0x14261b9d0
void TreeNode::CalcViewMatrix(Matrix2F* m) const
{
    *m = M2D();
    appendAncestorMatrices(m);
}

// @0x14261da60
void TreeNode::appendAncestorMatrices(Matrix2F* m) const
{
    for (const TreeNode* node = GetParent(); node; node = node->GetParent())
        m->Append(node->M2D());
}

// @0x14261d980
void TreeNode::SetVisible(bool visible)
{
    if (IsVisible() != visible)
    {
        NodeData* data = GetWritableData(Change_Visible);
        data->SetVisible(visible);
        if (GetParent())
            GetParent()->AddToPropagate();
    }
}

// @0x14261d270
void TreeNode::SetEdgeAAMode(EdgeAAMode edgeAA)
{
    if (GetEdgeAAMode() != edgeAA)
    {
        NodeData* data = GetWritableData(Change_EdgeAAMode);
        data->SetEdgeAAMode(edgeAA);
    }
}

// @0x14261c640
const State* TreeNode::GetState(StateType type) const
{
    return GetReadOnlyData()->States.GetState(type);
}

// @0x14261d6a0
void TreeNode::SetScale9Grid(const RectF& rect)
{
    NodeData* data = GetWritableData(Change_State_Scale9);
    if (rect.x2 > rect.x1 && rect.y2 > rect.y1)
    {
        Scale9GridRect* grid = SF_HEAP_AUTO_NEW(this) Scale9GridRect;
        if (grid)
        {
            grid->Scale9 = rect;
            data->States.SetState(&Scale9State::InterfaceImpl, grid);
            grid->Release();
        }
    }
    else
        data->States.RemoveState(State_Scale9);
}

// @0x14261d230
void TreeNode::SetBlendMode(BlendMode mode)
{
    NodeData* data = GetWritableData(Change_State_BlendMode);
    if (mode != Blend_None)
        data->States.SetStateVoid(&BlendState::InterfaceImpl, (void*)(SPInt)mode);
    else
        data->States.RemoveState(State_BlendMode);
}

// @0x14261dfd0
bool TreeNode::setThisAsMaskOwner(NodeData* thisData, TreeNode* node)
{
    NodeData* maskData = node->GetWritableData(Change_IsMask);
    node->SetParent(this);
    maskData->Flags |= NF_MaskNode;
    maskData->States.SetStateVoid(&Internal_MaskOwnerState::InterfaceImpl, this);
    thisData->Flags |= NF_HasMask;
    return true;
}

// @0x14261df70
// MS2-FUNCTIONAL: block layout: exe jumps to a shared epilogue
bool TreeNode::removeThisAsMaskOwner(const NodeData* thisData)
{
    const MaskNodeState* state = thisData->GetState<MaskNodeState>();
    if (!state)
        return false;
    NodeData* maskData = state->GetNode()->GetWritableData(Change_IsMask);
    state->GetNode()->SetParent(0);
    maskData->Flags &= ~NF_MaskNode;
    maskData->States.RemoveState(State_Internal_MaskOwner);
    return true;
}

// @0x14261d3e0
void TreeNode::SetMaskNode(TreeNode* node)
{
    NodeData* data = GetWritableData(Change_State_MaskNode);
    if (node)
    {
        setThisAsMaskOwner(data, node);
        data->States.SetStateVoid(&MaskNodeState::InterfaceImpl, node);
    }
    else if (removeThisAsMaskOwner(data))
    {
        data->States.RemoveState(State_MaskNode);
        data->Flags &= ~NF_HasMask;
    }
    AddToPropagate();
}

// @0x14261d2e0
// MS2-FUNCTIONAL: exe splits the body into separate .pdata chunks; same calls and stores
void TreeNode::SetFilters(const FilterSet* filters)
{
    if (filters && filters->GetFilterCount() > 0)
    {
        FilterSet* copy = filters->Clone(true, 0);
        NodeData*  data = GetWritableData(Change_State_Filter);
        data->States.SetStateVoid(&FilterState::InterfaceImpl, copy);
        data->Flags |= NF_HasFilter;
        if (copy)
            copy->Release();
    }
    else
    {
        if (!HasFilter())
            return;
        NodeData* data = GetWritableData(Change_State_Filter);
        data->States.RemoveState(State_Filter);
        data->Flags &= ~NF_HasFilter;
    }
    AddToPropagate();
}

// @0x14261bac0
// MS2-FUNCTIONAL: last matrix row store scheduled after the flag clear
void TreeNode::Clear3D()
{
    NodeData* data = GetWritableData(Change_Matrix + (Is3D() ? Change_3D : 0));
    data->M3D()    = Matrix3F::Identity;
    data->Clear3D();
}

// ***** TreeNodeArray

// @0x14261b540
TreeNodeArray::TreeNodeArray(const TreeNodeArray& src)
{
    pData[0] = src.pData[0];
    pData[1] = src.pData[1];
    if (src.hasArrayData())
    {
        src.getArrayData()->AddRef();
        setCapacity(0);
    }
}

// @0x14261b6b0
void TreeNodeArray::operator=(const TreeNodeArray& src)
{
    UPInt oldData  = pData[0];
    UPInt capacity = src.pData[1];
    if (src.hasArrayData())
    {
        src.getArrayData()->AddRef();
        capacity = 0;
    }
    if (hasArrayDataBit(oldData))
        toArrayData(oldData)->Release();
    pData[0] = src.pData[0];
    pData[1] = capacity;
}

// @0x14261da20
TreeNodeArray::ArrayData* TreeNodeArray::allocByCapacity(UPInt capacity, UPInt size)
{
    ArrayData* data =
        (ArrayData*)SF_HEAP_AUTO_ALLOC(this, sizeof(ArrayData) + (capacity - FirstNodeSize) * sizeof(TreeNode*));
    if (data)
    {
        data->RefCount = 1;
        data->Size     = size;
    }
    return data;
}

// @0x14261c700
bool TreeNodeArray::Insert(UPInt index, TreeNode* node)
{
    if (!pNodes[0])
    {
        pNodes[0] = node;
        return true;
    }

    if (!hasArrayData())
    {
        if (!pNodes[1])
        {
            if (index == 0)
                pNodes[1] = pNodes[0];
            pNodes[index] = node;
            return true;
        }

        // a third node moves the list out to a shared array
        ArrayData* data = allocByCapacity(FirstNodeSize + RoundMultiple, 3);
        if (!data)
            return false;
        switch (index)
        {
        case 0:
            data->pNodes[1] = pNodes[0];
            data->pNodes[2] = pNodes[1];
            break;
        case 1:
            data->pNodes[0] = pNodes[0];
            data->pNodes[2] = pNodes[1];
            break;
        case 2:
            data->pNodes[0] = pNodes[0];
            data->pNodes[1] = pNodes[1];
            break;
        }
        data->pNodes[index] = node;
        setArrayData(data, FirstNodeSize + RoundMultiple);
        return true;
    }

    ArrayData* data = getArrayData();
    UPInt      size = data->Size;
    if (size + 1 <= getCapacity())
    {
        for (UPInt i = size; i > index; i--)
            data->pNodes[i] = data->pNodes[i - 1];
        data->pNodes[index] = node;
        data->Size++;
        return true;
    }

    // full or shared with a snapshot: copy into a new array
    UPInt      capacity = calcIncreasedCapacity(size);
    ArrayData* newData  = allocByCapacity(capacity, size + 1);
    if (!newData)
        return false;
    if (index)
        memcpy(newData->pNodes, data->pNodes, index * sizeof(TreeNode*));
    newData->pNodes[index] = node;
    if (index < data->Size)
        memcpy(newData->pNodes + index + 1, data->pNodes + index, (data->Size - index) * sizeof(TreeNode*));
    data->Release();
    setArrayData(newData, capacity);
    return true;
}

// @0x14261d020
// MS2-FUNCTIONAL: register allocation and block layout differ
bool TreeNodeArray::Remove(UPInt index, UPInt count)
{
    if (!count)
        return true;

    if (!hasArrayData())
    {
        if (!pNodes[1])
        {
            pNodes[0] = 0;
            return true;
        }
        if (count == 2)
        {
            pNodes[0] = 0;
            pNodes[1] = 0;
            return true;
        }
        TreeNode* last = pNodes[1];
        pNodes[1] = 0;
        if (index == 0)
            pNodes[0] = last;
        return true;
    }

    ArrayData* data    = getArrayData();
    UPInt      newSize = data->Size - count;
    if (newSize <= 1)
    {
        // back to the inline store
        TreeNode* node = 0;
        if (newSize == 1)
            node = index ? data->pNodes[0] : data->pNodes[count];
        pNodes[0] = node;
        pNodes[1] = 0;
        data->Release();
        return true;
    }

    UPInt capacity = getCapacity() ? calcRemoveCapacity(getCapacity(), newSize) : roundUpSize(newSize);
    if (capacity != getCapacity())
    {
        ArrayData* newData = allocByCapacity(capacity, newSize);
        if (!newData)
            return false;
        if (index)
            memcpy(newData->pNodes, data->pNodes, index * sizeof(TreeNode*));
        if (index + count < data->Size)
            memcpy(newData->pNodes + index, data->pNodes + index + count,
                   (data->Size - index - count) * sizeof(TreeNode*));
        data->Release();
        setArrayData(newData, capacity);
        return true;
    }

    for (UPInt i = index; i < newSize; i++)
        data->pNodes[i] = data->pNodes[i + count];
    data->Size = newSize;
    setCapacity(capacity);
    return true;
}

// ***** TreeContainer

// @0x14261c690
bool TreeContainer::Insert(UPInt index, TreeNode* node)
{
    NodeData* data     = GetWritableData(Change_ChildInsert);
    bool      inserted = data->Children.Insert(index, node);
    if (inserted)
    {
        node->AddRef();
        node->SetParent(this);
        AddToPropagate();
    }
    return inserted;
}

// @0x14261cf50
// MS2-FUNCTIONAL: register allocation differs
void TreeContainer::Remove(UPInt index, UPInt count)
{
    if (!count)
        return;
    NodeData*        data  = GetWritableData(Change_ChildRemove);
    TreeNode* const* nodes = data->Children.GetMultipleAt(index);
    for (UPInt i = 0; i < count; i++)
    {
        nodes[i]->SetParent(0);
        nodes[i]->Release();
    }
    AddToPropagate();
    data->Children.Remove(index, count);
}

// @0x14261b570
// MS2-FUNCTIONAL: member copy scheduled differently (statebag test operand order)
TreeContainer::NodeData& TreeContainer::NodeData::operator=(const NodeData& src) = default;

// @0x14261ce60
// MS2-FUNCTIONAL: register allocation differs (loop over the child array)
void TreeContainer::NodeData::ReleaseNodes() const
{
    UPInt count = Children.GetSize();
    if (count)
    {
        TreeNode* const* nodes = Children.GetMultipleAt(0);
        for (UPInt i = 0; i < count; i++)
        {
            nodes[i]->SetParent(0);
            nodes[i]->Release();
        }
    }
    TreeNode::NodeData::ReleaseNodes();
}

// @0x14261c910
// MS2-FUNCTIONAL: exe saves xmm registers and has an EH handler; same logic
bool TreeContainer::NodeData::PropagateUp(Entry* entry) const
{
    RectF            bounds(0), parentBounds(0);
    UPInt            count       = Children.GetSize();
    TreeNode* const* nodes       = Children.GetMultipleAt(0);
    bool             boundsEmpty = true;

    for (UPInt i = 0; i < count; i++)
    {
        const TreeNode::NodeData* data = nodes[i]->GetReadOnlyData();
        if (data->IsVisible() && !isEmptyBounds(data->AproxParentBounds))
        {
            if (boundsEmpty)
            {
                bounds      = data->AproxParentBounds;
                boundsEmpty = false;
            }
            else
                bounds.UnionRect(&bounds, data->AproxParentBounds);
        }
    }

    if (!boundsEmpty)
    {
        expandByFilterBounds(&bounds, false);
        if (!Is3D())
            M2D().EncloseTransform(&parentBounds, bounds);
        else
            M3D().EncloseTransform(&parentBounds, bounds);
    }

    TreeContainer* container = (TreeContainer*)entry;
    if (!boundsDiffer(bounds, AproxLocalBounds) && !boundsDiffer(parentBounds, AproxParentBounds))
    {
        if (entry->GetChange())
            container->GetWritableData(0)->Children.SignalFrameCapture();
        return false;
    }

    NodeData* data          = container->GetWritableData(Change_AproxBounds | Change_Matrix);
    data->AproxLocalBounds  = bounds;
    data->AproxParentBounds = parentBounds;
    if (entry->GetChange())
        data->Children.SignalFrameCapture();
    return IsVisible();
}

// @0x14261e030
// MS2-FUNCTIONAL: register allocation differs (push vs home-slot saves)
TreeCacheNode* TreeContainer::NodeData::updateCache(TreeCacheNode* parent, TreeCacheNode* insert, TreeNode* node,
                                                    UInt16 depth) const
{
    TreeCacheNode* cache = node->GetRenderData();
    if (!cache)
    {
        unsigned flags = (GetFlags() & NF_Visible) | TreeCacheNode::CalcEdgeAAMode(this, parent);
        if (IsMaskNode())
            flags |= NF_PartOfMask | NF_MaskNode;
        cache = SF_HEAP_AUTO_NEW(parent)
            TreeCacheContainer(node, parent->pRenderer2D, Is3D() ? (flags | NF_3D) : flags);
        node->SetRenderData(cache);
        if (!cache)
            return 0;
    }
    cache->UpdateInsertIntoParent(parent, insert, this, depth);
    return cache;
}

// @0x14261bbd0
TreeNode* TreeContainer::NodeData::CloneCreate(Context* context) const
{
    return context->CreateEntry<TreeContainer>(NonlocalCloneArg<NodeData>(*this));
}

// @0x14261bc40
bool TreeContainer::NodeData::CloneInit(TreeNode* node, Context* context) const
{
    if (!TreeNode::NodeData::CloneInit(node, context))
        return false;

    TreeContainer* container = (TreeContainer*)node;
    UPInt          count     = Children.GetSize();
    for (UPInt i = 0; i < count; i++)
    {
        TreeNode* child = Children.GetAt(i)->Clone(context);
        container->Add(child);
        if (child)
            child->Release();
    }
    return true;
}

// ***** TreeRoot

// @0x14261d890
void TreeRoot::SetViewport(const Viewport& vp)
{
    if (GetReadOnlyData()->VP != vp)
    {
        NodeData* data = GetWritableData(Change_Viewport);
        data->VP       = vp;
    }
}

}} // namespace Scaleform::Render

// @0x14261b450 TreeContainer::NodeData(NonlocalCloneArg) comes from the header; @0x14261b730..0x14261b970 are the deleting destructors of the ref-counted state payloads
// and of TreeCacheContainer.
// MS2-PIN: ??_7NodeData@TreeContainer@Render@Scaleform@@6B@ 0x143183280
// MS2-PIN: ??_7NodeData@TreeNode@Render@Scaleform@@6B@ 0x14317b700
// MS2-PIN: ??_7EntryData@ContextImpl@Render@Scaleform@@6B@ 0x14317b6d0
// MS2-PIN: ??_7TreeCacheContainer@Render@Scaleform@@6B@ 0x14318ebc8
// MS2-PIN: ??_7Scale9GridRect@Render@Scaleform@@6B@ 0x14318eba0
// MS2-PIN: ??_7?$Matrix3x4Ref@M@Render@Scaleform@@6B@ 0x14318ebb0
// MS2-PIN: ??_7?$Matrix4x4Ref@M@Render@Scaleform@@6B@ 0x14318ebc0
// MS2-PIN: ??_7?$RefCountBase@UScale9GridRect@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318eb98
// MS2-PIN: ??_7?$RefCountBase@V?$Matrix3x4@M@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318eba8
// MS2-PIN: ??_7?$RefCountBase@V?$Matrix4x4@M@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f058
// MS2-PIN: ??_7?$ContextData_ImplMixin@VNodeData@TreeContainer@Render@Scaleform@@V1TreeNode@34@@ContextImpl@Render@Scaleform@@6B@ 0x143183230
// MS2-PIN: ??_G?$RefCountBase@UScale9GridRect@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14261b7f0
// MS2-PIN: ??_G?$RefCountBase@V?$Matrix3x4@M@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14261b850
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14261b8b0
// MS2-PIN: ??_GTreeCacheContainer@Render@Scaleform@@UEAAPEAXI@Z 0x14261b970
