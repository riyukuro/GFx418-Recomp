// Recovered Scaleform 4.1.18 Render: the advance-thread display tree (Render_TreeNode). A TreeNode is a context
// Entry whose per-snapshot NodeData carries the 2D/3D matrix, color transform, states and approximate bounds;
// TreeContainer adds the child array, TreeRoot the viewport.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// TreeNode::NodeData is 0x90 bytes: M34 +0x10 (a Matrix2F view of its first two rows for 2D nodes), States +0x40,
// Cx +0x50, AproxLocalBounds +0x70, AproxParentBounds +0x80. TreeContainer::NodeData adds Children (+0x90, 0xa0
// bytes), TreeRoot::NodeData the viewport (+0xa0) and background color. vftables: EntryData 0x14317b6d0,
// TreeNode::NodeData 0x14317b700, TreeContainer::NodeData 0x143183280. Bodies in sfr_render_03c.
#ifndef MS2_SF_RENDER_TREENODE_H
#define MS2_SF_RENDER_TREENODE_H

#include "ms2/scaleform/include/render/render_context.h"
#include "ms2/scaleform/include/render/render_cxform.h"
#include "ms2/scaleform/include/render/render_color.h"
#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"
#include "ms2/scaleform/include/render/render_viewport.h"
#include "ms2/scaleform/include/render/render_states.h"

namespace Scaleform { namespace Render {

class TreeContainer;
class TreeCacheNode;
class TreeCacheContainer;

class TreeNode : public ContextImpl::Entry
{
public:
    class NodeData : public ContextImpl::EntryData
    {
        Matrix3F M34;

    public:
        NodeData(ContextImpl::EntryData::EntryType type = ET_Base);   // 0x1424d9310 (sfr_as3_15)
        NodeData(const NodeData& src);                                // 0x1424d9220 (sfr_as3_15)
        // the states stay behind: CloneInit copies the ones that may be shared
        NodeData(NonlocalCloneArg<NodeData> src)
            : ContextImpl::EntryData(NonlocalCloneArg<ContextImpl::EntryData>(*src.pC)), M34(src->M34), Cx(src->Cx),
              AproxLocalBounds(src->AproxLocalBounds), AproxParentBounds(src->AproxParentBounds)
        {
        }

        // (appended for sfr_render_04l) the member-wise copy, out of line in the exe (0x1424e0a70)
        NodeData& operator=(const NodeData& src);

        StateBag States;
        Cxform   Cx;
        RectF    AproxLocalBounds;    // children's bounds in this node's space
        RectF    AproxParentBounds;   // the same through M34

        virtual TreeCacheNode* updateCache(TreeCacheNode* parent, TreeCacheNode* insert,
                                           TreeNode* node, UInt16 depth) const = 0;

        bool        expandByFilterBounds(RectF* bounds, bool boundsEmpty) const;
        static void expandByFilterBounds(const Filter* filter, RectF* bounds);
        void        contractByFilterBounds(RectF* bounds) const;

        virtual void ReleaseNodes() const;

        void SetVisible(bool visible)
        {
            Flags &= ~NF_Visible;
            Flags |= (UInt16)visible;
        }
        bool IsVisible() const             { return (Flags & NF_Visible) != 0; }
        bool IsMaskNode() const            { return (Flags & NF_MaskNode) != 0; }
        bool HasMask() const               { return (Flags & NF_HasMask) != 0; }
        bool HasFilter() const             { return (Flags & NF_HasFilter) != 0; }
        bool HasProjectionMatrix3D() const { return (Flags & NF_HasProjectionMatrix3D) != 0; }
        bool HasViewMatrix3D() const       { return (Flags & NF_HasViewMatrix3D) != 0; }
        bool Is3D() const                  { return (Flags & NF_3D) != 0; }
        void Clear3D()                     { Flags &= ~NF_3D; }
        unsigned GetFlags() const          { return Flags; }

        EdgeAAMode GetEdgeAAMode() const          { return (EdgeAAMode)(GetFlags() & NF_EdgeAA_Mask); }
        void       SetEdgeAAMode(EdgeAAMode mode)
        {
            Flags &= ~NF_EdgeAA_Mask;
            Flags |= (UInt16)mode;
        }

        template<class S>
        const S* GetState() const { return States.GetState<S>(); }

        TreeNode* GetMaskOwner() const
        {
            const Internal_MaskOwnerState* owner = GetState<Internal_MaskOwnerState>();
            return owner ? owner->GetMaskOwner() : 0;
        }

        const Matrix2F& M2D() const { return *(const Matrix2F*)(const void*)&M34; }
        Matrix2F&       M2D()       { return *(Matrix2F*)(void*)&M34; }
        const Matrix3F& M3D() const { return M34; }
        Matrix3F&       M3D()       { return M34; }

        void SetMatrix(const Matrix2F& m)   { *(Matrix2F*)(void*)&M34 = m; }
        void SetMatrix3D(const Matrix3F& m) { M34 = m; Flags |= NF_3D; }

        virtual void      CopyGeomData(TreeNode* destNode, const TreeNode& srcNode);
        virtual TreeNode* CloneCreate(Context* context) const;
        virtual bool      CloneInit(TreeNode* node, Context* context) const;
    };

    SF_RENDER_CONTEXT_ENTRY_INLINES(NodeData)

    void      CopyGeomData(const TreeNode& src);
    TreeNode* Clone(Context* context) const;

    bool HasChanges(unsigned cb) const { return GetChange() ? (GetChange()->ChangeBits & cb) != 0 : false; }

    void            SetMatrix(const Matrix2F& m);
    const Matrix2F& M2D() const { return GetReadOnlyData()->M2D(); }
    void            SetMatrix3D(const Matrix3F& m);
    const Matrix3F& M3D() const { return GetReadOnlyData()->M3D(); }

    void SetViewMatrix3D(const Matrix3F& m);
    bool GetViewMatrix3D(Matrix3F* m) const
    {
        const ViewMatrix3DState* state = GetState<ViewMatrix3DState>();
        if (!state)
            return false;
        *m = Matrix3F(state->GetViewMatrix3D()->M);
        return true;
    }
    void SetProjectionMatrix3D(const Matrix4F& m);
    bool GetProjectionMatrix3D(Matrix4F* m) const
    {
        const ProjectionMatrix3DState* state = GetState<ProjectionMatrix3DState>();
        if (!state)
            return false;
        *m = Matrix4F(state->GetProjectionMatrix3D()->M);
        return true;
    }

    void CalcViewMatrix(Matrix2F* m) const;

    void SetCxform(const Cxform& cx)
    {
        NodeData* data = GetWritableData(Change_CxForm);
        data->Cx = cx;
    }
    const Cxform& GetCxform() const { return GetReadOnlyData()->Cx; }

    void       SetVisible(bool visible);
    bool       IsVisible() const { return GetReadOnlyData()->IsVisible(); }
    unsigned   GetFlags() const  { return GetReadOnlyData()->GetFlags(); }
    void       SetEdgeAAMode(EdgeAAMode edgeAA);
    EdgeAAMode GetEdgeAAMode() const { return (EdgeAAMode)(GetFlags() & NF_EdgeAA_Mask); }

    const State* GetState(StateType type) const;
    template<class S>
    const S* GetState() const { return static_cast<const S*>(GetState(S::GetType_Static())); }

    void  SetScale9Grid(const RectF& rect);
    RectF GetScale9Grid() const
    {
        const Scale9State* state = GetState<Scale9State>();
        return state ? state->GetRect() : RectF(0);
    }
    bool HasScale9Grid() const { return GetState<Scale9State>() != 0; }

    void      SetBlendMode(BlendMode mode);
    BlendMode GetBlendMode() const
    {
        const BlendState* state = GetState<BlendState>();
        return state ? state->GetBlendMode() : Blend_None;
    }

    void      SetMaskNode(TreeNode* node);
    TreeNode* GetMaskNode() const
    {
        const MaskNodeState* state = GetState<MaskNodeState>();
        return state ? state->GetNode() : 0;
    }

    void             SetFilters(const FilterSet* filters);
    const FilterSet* GetFilters() const
    {
        const FilterState* state = GetState<FilterState>();
        return state ? state->GetFilters() : 0;
    }

    void Clear3D();
    bool Is3D() const                  { return GetReadOnlyData()->Is3D(); }
    bool IsMaskNode() const            { return GetReadOnlyData()->IsMaskNode(); }
    bool HasMask() const               { return GetReadOnlyData()->HasMask(); }
    bool HasFilter() const             { return GetReadOnlyData()->HasFilter(); }
    bool HasProjectionMatrix3D() const { return GetReadOnlyData()->HasProjectionMatrix3D(); }
    bool HasViewMatrix3D() const       { return GetReadOnlyData()->HasViewMatrix3D(); }

    inline TreeNode* GetParent() const;

    const RectF& GetAproxLocalBounds() const  { return GetReadOnlyData()->AproxLocalBounds; }
    const RectF& GetAproxParentBounds() const { return GetReadOnlyData()->AproxParentBounds; }

    void appendAncestorMatrices(Matrix2F* m) const;

protected:
    friend class NodeData;
    bool        setThisAsMaskOwner(NodeData* thisData, TreeNode* node);
    static bool removeThisAsMaskOwner(const NodeData* thisData);
};

// Child list of a container. Up to two children are stored inline; more go to a shared ref-counted array (bit 0 of
// the first word set, the second word its capacity, or 0 while it may be shared with another snapshot).
class TreeNodeArray
{
public:
    enum
    {
        FixedStoreSize = 2,
        FirstNodeSize  = 2,
        RoundMultiple  = 4,
        RoundMask      = RoundMultiple - 1
    };

    struct ArrayData
    {
        volatile int RefCount;
        UPInt        Size;
        TreeNode*    pNodes[FirstNodeSize];

        void AddRef() { AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, 1); }
        void Release()
        {
            if (AtomicOps<int>::ExchangeAdd_NoSync(&RefCount, -1) - 1 == 0)
                SF_FREE(this);
        }
    };

    union {
        TreeNode* pNodes[FixedStoreSize];
        UPInt     pData[FixedStoreSize];
    };

    static bool       hasArrayDataBit(UPInt data) { return (data & 1) != 0; }
    static ArrayData* toArrayData(UPInt data)     { return (ArrayData*)(data & ~(UPInt)1); }

    bool       hasArrayData() const { return hasArrayDataBit(pData[0]); }
    ArrayData* getArrayData() const { return toArrayData(pData[0]); }
    UPInt      getCapacity() const  { return pData[1]; }
    void       setArrayData(ArrayData* data, UPInt capacity = 0)
    {
        pData[0] = ((UPInt)data) | 1;
        pData[1] = capacity;
    }
    void setCapacity(UPInt capacity) { pData[1] = capacity; }

    UPInt roundUpSize(UPInt size) { return FirstNodeSize + ((size - FirstNodeSize + RoundMask) & ~(UPInt)RoundMask); }
    UPInt calcIncreasedCapacity(UPInt oldSize) { return roundUpSize(oldSize + (oldSize >> 1)); }
    UPInt calcRemoveCapacity(UPInt oldCapacity, UPInt newSize)
    {
        if (oldCapacity / 2 < newSize || oldCapacity <= FirstNodeSize + RoundMultiple * 2)
            return oldCapacity;
        return roundUpSize(newSize);
    }

    ArrayData* allocByCapacity(UPInt capacity, UPInt size);

    TreeNodeArray() { pNodes[0] = pNodes[1] = 0; }
    TreeNodeArray(const TreeNodeArray& src);
    ~TreeNodeArray()
    {
        if (hasArrayData())
            getArrayData()->Release();
    }
    void operator=(const TreeNodeArray& src);

    UPInt GetSize() const
    {
        if (!pNodes[0])
            return 0;
        if (hasArrayData())
            return getArrayData()->Size;
        return pNodes[1] ? 2 : 1;
    }
    TreeNode* GetAt(UPInt index) const
    {
        TreeNode* const* nodes = hasArrayData() ? getArrayData()->pNodes : pNodes;
        return nodes[index];
    }
    TreeNode* operator[](UPInt index) const { return GetAt(index); }

    TreeNode* const* GetMultipleAt(UPInt index) const
    {
        if (!pNodes[0] && index == 0)
            return 0;
        TreeNode* const* nodes = hasArrayData() ? getArrayData()->pNodes : pNodes;
        return nodes + index;
    }

    bool Insert(UPInt index, TreeNode* node);
    bool Remove(UPInt index, UPInt count = 1);

    // a captured array is shared with the snapshot: the next change must copy it
    void SignalFrameCapture()
    {
        if (hasArrayData())
            setCapacity(0);
    }
};

class TreeContainer : public TreeNode
{
public:
    class NodeData : public ContextData_ImplMixin<NodeData, TreeNode::NodeData>
    {
        typedef ContextData_ImplMixin<NodeData, TreeNode::NodeData> BaseClass;

    protected:
        NodeData(ContextImpl::EntryData::EntryType type) : BaseClass(type) {}

    public:
        NodeData() : BaseClass(ET_Container) {}
        NodeData(NonlocalCloneArg<NodeData> src) : BaseClass(NonlocalCloneArg<BaseClass>(*src.pC)) {}

        TreeNodeArray Children;

        NodeData& operator=(const NodeData& src);   // the member-wise copy, out of line in sfr_render_03c

        virtual void ReleaseNodes() const;
        virtual bool PropagateUp(Entry* entry) const;

        virtual TreeCacheNode* updateCache(TreeCacheNode* parent, TreeCacheNode* insert,
                                           TreeNode* node, UInt16 depth) const;

        virtual TreeNode* CloneCreate(Context* context) const;
        virtual bool      CloneInit(TreeNode* node, Context* context) const;
    };

    SF_RENDER_CONTEXT_ENTRY_INLINES(NodeData)

    bool Insert(UPInt index, TreeNode* node);
    void Remove(UPInt index, UPInt count);
    bool Add(TreeNode* node) { return Insert(GetSize(), node); }

    TreeNode* GetAt(UPInt index) const { return GetReadOnlyData()->Children.GetAt(index); }
    UPInt     GetSize() const          { return GetReadOnlyData()->Children.GetSize(); }
};

inline TreeNode* TreeNode::GetParent() const { return static_cast<TreeNode*>(ContextImpl::Entry::GetParent()); }

class TreeRoot : public TreeContainer
{
public:
    class NodeData : public ContextData_ImplMixin<NodeData, TreeContainer::NodeData>
    {
    public:
        NodeData();   // 0x14256a710 (sfr_gfx_01i)

        Viewport VP;        // +0xa0
        Color    BGColor;

        Color GetBackgroundColor() const { return BGColor; }
        bool  HasViewport() const        { return VP.IsValid(); }
    };

    SF_RENDER_CONTEXT_ENTRY_INLINES(NodeData)

    bool            HasViewport() const        { return GetReadOnlyData()->HasViewport(); }
    const Viewport& GetViewport() const        { return GetReadOnlyData()->VP; }
    Color           GetBackgroundColor() const { return GetReadOnlyData()->GetBackgroundColor(); }

    void SetViewport(const Viewport& vp);
    void SetBackgroundColor(const Color& color)
    {
        if (GetReadOnlyData()->BGColor != color)
        {
            NodeData* data = GetWritableData(Change_Viewport);
            data->BGColor = color;
        }
    }
};

typedef DisplayHandle<TreeRoot> TreeRootDisplayHandle;

// Proven by the exe: entry pages hand out 0x38-byte entries; CreateEntry<TreeContainer> allocates 0xa0 bytes of node
// data (TreeNodeArray at +0x90 after the TreeNode part), the MovieImpl constructor 0xd0 for the TreeRoot.
static_assert(sizeof(TreeNode) == 0x38, "TreeNode size");
static_assert(sizeof(TreeNode::NodeData) == 0x90, "TreeNode::NodeData size");
static_assert(sizeof(TreeContainer::NodeData) == 0xa0, "TreeContainer::NodeData size");
static_assert(sizeof(TreeRoot::NodeData) == 0xd0, "TreeRoot::NodeData size");

}} // namespace Scaleform::Render

#endif
