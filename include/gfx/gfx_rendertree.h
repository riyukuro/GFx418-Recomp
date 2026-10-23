// Recovered Scaleform 4.1.18: the render tree as the GFx units see it. The display objects keep a TreeNode per
// object and edit it through the Render_TreeNode API (bodies in sfr_render_01b / sfr_render_03c), but the render
// headers (render_context.h, render_treenode.h) sit on the other kernel tree (ms2/scaleform/kernel) and cannot be
// included next to the gfx headers. This header declares the same classes with the same names and layout, limited
// to what the GFx units use: never include it together with render_context.h / render_treenode.h.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Entry 0x38 bytes (RefCount +8, pParent +0x20); EntryData: Type +8, Flags +0xa; TreeNode::NodeData: M34 +0x10,
// States +0x40, Cx +0x50, AproxLocalBounds +0x70, AproxParentBounds +0x80; TreeContainer::NodeData: Children +0x90
// (0xa0 bytes, vftable 0x143183280).
#ifndef MS2_SF_GFX_RENDERTREE_H
#define MS2_SF_GFX_RENDERTREE_H

#ifdef MS2_SF_RENDER_CONTEXT_H
#error gfx_rendertree.h mirrors render_context.h; include only one of them
#endif

#include "../kernel/sf_memory.h"
#include "../render/render_stats.h"
#include "../render/render_constants.h"
#include "../render/render_cxform.h"
#include "../render/render_matrix2x4.h"
#include "../render/render_matrix4x4.h"
#include "../render/render_states.h"

namespace Scaleform { namespace Render {

class TreeCacheNode;
class TreeNode;
class TreeContainer;

namespace ContextImpl {

class Entry;
class EntryData;
class EntryChange;
class Context;
struct SnapshotPage;

// The page header in front of the entries of one 4 KB entry page.
struct EntryPageBase
{
    void*         Links[2];
    unsigned      UseCount;
    void*         pSnapshot;
    SnapshotPage* pSnapshotPage;
    SnapshotPage* pDisplaySnapshotPage;
    SnapshotPage* pTempPage;
};

// The data pointers of one entry page as the active snapshot sees them.
struct SnapshotPage
{
    void*         Links[2];
    void*         pEntryPage;
    SnapshotPage* pOlderSnapshotPage;
    SnapshotPage* pNewerSnapshotPage;
    EntryData*    pData[1];
};

class Entry
{
protected:
    union {
        Entry*       pPrev;
        EntryChange* pChange;
    };
    union {
        Entry*       pNext;
        UPInt        RefCount;
    };
    EntryData*     pNative;
    TreeCacheNode* pRenderer;
    Entry*         pParent;
    void*          PNode[2];

    void       destroyHelper();
    EntryData* getWritableData(unsigned changeBits);
    // (appended for the drawing API, sfr_gfx_06e) queue the entry for the next snapshot unless it is already queued
    void       addToPropagateImpl();
    void       AddToPropagate() { if (!PNode[0]) addToPropagateImpl(); }

public:
    inline const EntryData* GetReadOnlyDataBase() const;

    Entry* GetParent() const { return pParent; }
    void   AddRef()          { RefCount++; }
    void   Release()         { if (--RefCount == 0) destroyHelper(); }
};

struct EntryPage : public EntryPageBase
{
    Entry Entries[1];
};

// Per-snapshot node data; pVTable is the EntryData vftable of the concrete node data class.
class EntryData
{
public:
    enum EntryType
    {
        ET_Base,
        ET_Root,
        ET_Container,
        ET_Shape,
        ET_Mesh,
        ET_Text
    };

    const void* pVTable;
    UInt16      Type;
    UInt16      Flags;
};

const EntryData* Entry::GetReadOnlyDataBase() const
{
    EntryPage* page  = (EntryPage*)((UPInt)this & ~(UPInt)0xFFF);
    unsigned   index = unsigned(this - &page->Entries[0]);
    return page->pSnapshotPage->pData[index];
}

// The advance-thread side of a render context: the heap the node data comes from and the entry factory.
class Context
{
public:
    template<class T>
    T* CreateEntry()
    {
        EntryData* data = (EntryData*)SF_HEAP_ALLOC(pHeap, sizeof(typename T::NodeData), StatRender_NodeData_Mem);
        new (data) typename T::NodeData;
        return (T*)createEntryHelper(data);
    }

    MemoryHeap* pHeap;

    // (appended for the player, sfr_gfx_01i)
    bool HasChanges() const;                        // 0x142580270
    void Shutdown(bool waitFlag);                   // 0x142581230
    bool IsShutdownComplete() const;                // 0x1425802a0
    void ForceUpdateImages();                       // 0x14257ff60
    void SetCaptureThreadId(void* captureThreadId); // 0x142581220 (ThreadId)

    UByte  Unrecovered_08[0xe0];
    UInt64 FinalizedFrameId;   // +0xe8 the last frame the render thread is done with
    UInt64 GetFinalizedFrameId() const { return FinalizedFrameId; }

private:
    Entry* createEntryHelper(EntryData* data);
};

} // namespace ContextImpl

using ContextImpl::Context;

class TreeNode : public ContextImpl::Entry
{
public:
    class NodeData : public ContextImpl::EntryData
    {
    public:
        NodeData(ContextImpl::EntryData::EntryType type = ET_Base);   // 0x1424d9310

        Matrix3F M34;                 // +0x10
        StateBag States;              // +0x40
        Cxform   Cx;                  // +0x50
        RectF    AproxLocalBounds;    // +0x70
        RectF    AproxParentBounds;   // +0x80

        bool IsVisible() const             { return (Flags & NF_Visible) != 0; }
        bool IsMaskNode() const            { return (Flags & NF_MaskNode) != 0; }
        bool HasMask() const               { return (Flags & NF_HasMask) != 0; }
        bool HasProjectionMatrix3D() const { return (Flags & NF_HasProjectionMatrix3D) != 0; }
        bool HasViewMatrix3D() const       { return (Flags & NF_HasViewMatrix3D) != 0; }
        bool Is3D() const                  { return (Flags & NF_3D) != 0; }

        const Matrix2F& M2D() const { return *(const Matrix2F*)(const void*)&M34; }
        const Matrix3F& M3D() const { return M34; }
    };

    NodeData*       GetWritableData(unsigned cb) { return (NodeData*)Entry::getWritableData(cb); }
    const NodeData* GetReadOnlyData() const      { return (const NodeData*)Entry::GetReadOnlyDataBase(); }

    void            SetMatrix(const Matrix2F& m);
    const Matrix2F& M2D() const { return GetReadOnlyData()->M2D(); }
    void            SetMatrix3D(const Matrix3F& m);
    const Matrix3F& M3D() const { return GetReadOnlyData()->M3D(); }

    void SetViewMatrix3D(const Matrix3F& m);
    void SetProjectionMatrix3D(const Matrix4F& m);

    void SetCxform(const Cxform& cx)
    {
        NodeData* data = GetWritableData(Change_CxForm);
        data->Cx = cx;
    }
    const Cxform& GetCxform() const { return GetReadOnlyData()->Cx; }

    void SetVisible(bool visible);
    bool IsVisible() const { return GetReadOnlyData()->IsVisible(); }

    void       SetEdgeAAMode(EdgeAAMode edgeAA);   // 0x14261d270
    EdgeAAMode GetEdgeAAMode() const { return (EdgeAAMode)(GetReadOnlyData()->Flags & NF_EdgeAA_Mask); }

    const State* GetState(StateType type) const;
    template<class S>
    const S* GetState() const { return static_cast<const S*>(GetState(S::GetType_Static())); }

    void  SetScale9Grid(const RectF& rect);
    RectF GetScale9Grid() const
    {
        const Scale9State* state = GetState<Scale9State>();
        return state ? state->GetRect() : RectF(0);
    }

    void      SetBlendMode(BlendMode mode);
    BlendMode GetBlendMode() const
    {
        const BlendState* state = GetState<BlendState>();
        return state ? state->GetBlendMode() : Blend_None;
    }

    void SetMaskNode(TreeNode* node);

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
    bool HasProjectionMatrix3D() const { return GetReadOnlyData()->HasProjectionMatrix3D(); }
    bool HasViewMatrix3D() const       { return GetReadOnlyData()->HasViewMatrix3D(); }

    TreeNode* GetParent() const { return static_cast<TreeNode*>(ContextImpl::Entry::GetParent()); }
};

// The child list of a container: up to two children inline, more in a shared array (bit 0 of the first word).
class TreeNodeArray
{
public:
    struct ArrayData
    {
        volatile int RefCount;
        UPInt        Size;
        TreeNode*    pNodes[2];
    };

    union {
        TreeNode* pNodes[2];
        UPInt     pData[2];
    };

    bool       hasArrayData() const { return (pData[0] & 1) != 0; }
    ArrayData* getArrayData() const { return (ArrayData*)(pData[0] & ~(UPInt)1); }

    TreeNode* GetAt(UPInt index) const
    {
        TreeNode* const* nodes = hasArrayData() ? getArrayData()->pNodes : pNodes;
        return nodes[index];
    }

    // (appended for the buttons, sfr_gfx_05c) the child count as TreeContainer::GetSize inlines it
    UPInt GetSize() const
    {
        if (!pData[0])
            return 0;
        if (hasArrayData())
            return getArrayData()->Size;
        return pNodes[1] ? 2 : 1;
    }
};

// The TreeContainer::NodeData vftable (0x143183280): the constructor below stores it the way the inlined
// constructor of the render tree does.
extern const void* const TreeContainerNodeDataVTable[];

class TreeContainer : public TreeNode
{
public:
    class NodeData : public TreeNode::NodeData
    {
    public:
        NodeData() : TreeNode::NodeData(ET_Container)
        {
            pVTable = TreeContainerNodeDataVTable;
            Children.pNodes[0] = Children.pNodes[1] = 0;
        }

        TreeNodeArray Children;   // +0x90
    };

    const NodeData* GetReadOnlyData() const { return (const NodeData*)Entry::GetReadOnlyDataBase(); }

    bool      Insert(UPInt index, TreeNode* node);
    void      Remove(UPInt index, UPInt count);
    bool      Add(TreeNode* node) { return Insert(GetSize(), node); }
    TreeNode* GetAt(UPInt index) const { return GetReadOnlyData()->Children.GetAt(index); }
    UPInt     GetSize() const;   // the AS2 units' out-of-line copy, 0x14250dbc0
};

// (appended for the drawing API, sfr_gfx_06e) a leaf node drawing one shape
class ShapeMeshProvider;

// The TreeShape::NodeData vftable (0x14317bc40), stored the way the inlined constructor does.
extern const void* const TreeShapeNodeDataVTable[];

class TreeShape : public TreeNode
{
public:
    class NodeData : public TreeNode::NodeData
    {
    public:
        NodeData() : TreeNode::NodeData(ET_Shape)
        {
            pVTable       = TreeShapeNodeDataVTable;
            pMeshProvider = 0;
            MorphRatio    = 0;
        }

        ShapeMeshProvider* pMeshProvider;   // +0x90 (a Ptr in the exe)
        float              MorphRatio;      // +0x98
    };

    NodeData*          GetWritableData(unsigned cb) { return (NodeData*)Entry::getWritableData(cb); }
    const NodeData*    GetReadOnlyData() const { return (const NodeData*)Entry::GetReadOnlyDataBase(); }
    ShapeMeshProvider* GetShape() const        { return GetReadOnlyData()->pMeshProvider; }
    // takes a reference on the provider (defined where ShapeMeshProvider is complete, sfr_gfx_06e)
    inline void        SetShape(ShapeMeshProvider* pshape);
};

// (appended for the player, sfr_gfx_01i) the root of a movie's render tree: viewport and background color.
class Color;
class TreeRoot : public TreeContainer
{
public:
    void SetBackgroundColor(const Color& color);   // 0x142575a20 (inline in render_treenode.h)
};

}} // namespace Scaleform::Render

// (appended, sfr12) DisplayObjectBase::Is3D() is inline over the render node's flags; it needs both gfx_displayobject.h
// and gfx_rendertree.h, so whichever of the two comes second defines it.
#if defined(MS2_SF_GFX_DISPLAYOBJECT_H) && defined(MS2_SF_GFX_RENDERTREE_H) && !defined(MS2_SF_GFX_DISPLAYOBJECT_IS3D)
#define MS2_SF_GFX_DISPLAYOBJECT_IS3D
namespace Scaleform { namespace GFx {
inline bool DisplayObjectBase::Is3D() const
{
    return pRenNode && pRenNode->Is3D();
}
}} // namespace Scaleform::GFx
#endif

#endif
