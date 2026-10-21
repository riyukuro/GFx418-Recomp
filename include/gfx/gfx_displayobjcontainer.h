// Recovered Scaleform 4.1.18 GFx: DisplayList (the depth-sorted children of a container) and DisplayObjContainer.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// DisplayObjContainer is 0x110 bytes (ctor 0x1425fbbf0, vftable 0x14318e318, LogBase vftable 0x14318e6e0); its new
// virtuals are slots 115..120 of the Sprite vftable. DisplayList is 0x30 bytes (ctor 0x1425f8d80).
#ifndef MS2_SF_GFX_DISPLAYOBJCONTAINER_H
#define MS2_SF_GFX_DISPLAYOBJCONTAINER_H

#include "gfx_interactiveobject.h"
#include "../kernel/sf_array.h"

namespace Scaleform { namespace GFx {

class CharPosInfo;
class SwfEvent;
struct CharacterCreateInfo;
class MovieDef;
class MovieDefRootNode;
class Sprite;

// Tag memory of the movie data (the SwfEvent handler arrays are allocated with it).
enum { StatMD_Tags_Mem = 0x104 };

class DisplayList
{
public:
    // One child: the object and its index in the render container (mask objects keep their own index).
    class DisplayEntry
    {
    public:
        DisplayObjectBase* pCharacter;
        unsigned           TreeIndex;
        unsigned           MaskTreeIndex;

        // (appended for the display list, sfr_gfx_06c) the entry holds a reference to its object
        DisplayEntry() : pCharacter(0), TreeIndex(~0u), MaskTreeIndex(~0u) {}
        DisplayEntry(const DisplayEntry& e) : pCharacter(0) { *this = e; }
        ~DisplayEntry()
        {
            if (pCharacter)
                pCharacter->Release();
        }
        // Out of line in the exe (0x1425f8da0).
        void operator=(const DisplayEntry& e);

        void SetDisplayObject(DisplayObjectBase* pch)
        {
            if (pCharacter)
                pCharacter->Release();
            pCharacter = pch;
            if (pch)
                pch->AddRef();
        }
        DisplayObjectBase* GetDisplayObject() const { return pCharacter; }

        int  GetDepth() const          { return pCharacter->Depth; }
        int  GetClipDepth() const      { return pCharacter->ClipDepth; }
        bool IsMarkedForRemove() const { return (pCharacter->Flags & DisplayObjectBase::Mask_MarkedForRemove) != 0; }
        void MarkForRemove(bool remove)
        {
            if (remove)
                pCharacter->Flags |= DisplayObjectBase::Mask_MarkedForRemove;
            else
                pCharacter->Flags &= ~DisplayObjectBase::Mask_MarkedForRemove;
        }
        void ClearMarkForRemove()      { MarkForRemove(false); }
        bool IsInRenderTree() const    { return TreeIndex != ~0u; }
        bool IsMaskedTreeNode() const  { return MaskTreeIndex != ~0u; }
    };
    struct DepthToIndexContainer;

    DisplayList();   // 0x1425f8d80

    ArrayLH<DisplayEntry>          DisplayObjectArray; // +0x00
    mutable DepthToIndexContainer* DepthToIndexMap;    // +0x18
    mutable DisplayObject*         pCachedChar;        // +0x20 last name lookup hit
    mutable UByte                  Flags;              // +0x28

    UPInt GetCount() const { return DisplayObjectArray.GetSize(); }
    DisplayObjectBase* GetDisplayObject(UPInt index) const { return DisplayObjectArray[index].pCharacter; }

    // Removes every entry, unloading and releasing the objects (0x1425f9100).
    void Clear(DisplayObjectBase* powner);
    // Starts unloading every entry; false while some of them still run their onUnload (0x1425fb780).
    bool UnloadAll(DisplayObjectBase* powner);
    // Marks the timeline entries for removal (those created on ignoreFrame excepted, 0 for none) before a frame
    // jump re-places them (0x1425fa360); then unloads the ones still marked (0x1425fba90).
    void MarkAllEntriesForRemoval(DisplayObjectBase* powner, unsigned ignoreFrame);
    void UnloadMarkedObjects(DisplayObjectBase* powner);
    // Union of the entries' bounds in the space of t (0x1425f9580), the rect-only variant (0x1425f9ba0).
    RectF GetBounds(const Render::Matrix2F& t) const;
    RectF GetRectBounds(const Render::Matrix2F& t) const;

    // (appended for the display objects, sfr_gfx_06)
    // Index of the entry holding pch, -1 when it is not on this list (0x1425f9200).
    SPInt FindDisplayIndex(const DisplayObjectBase* pch) const;

private:
    friend class DisplayObjectBase;
    friend class DisplayObject;
    // Puts the render node of entry index into / takes it out of the owner's render container (0x1425f9e70,
    // 0x1425fa860).
    void InsertIntoRenderTree(DisplayObjectBase* powner, UPInt index);
    void RemoveFromRenderTree(DisplayObjectBase* powner, UPInt index);

    // (appended for the display list, sfr_gfx_06c)
public:
    enum AddFlags
    {
        Flags_ReplaceIfDepthIsOccupied = 0x1,
        Flags_DeadOnArrival            = 0x2,
        Flags_PlaceObject              = 0x4
    };
    enum
    {
        INVALID_DEPTH = -1,
        THRESHOLD_CNT = 10   // above this many entries a depth map backs the depth lookups
    };
    enum
    {
        Flags_DepthToIndexInvalid    = 0x1,
        Flags_MayContainForeignElems = 0x2   // depths may be out of order (AS3), so no plain binary search
    };
    struct DepthToIndexMapElem;

    // Named children, visited in order.
    struct MemberVisitor
    {
        virtual ~MemberVisitor() {}
        virtual void Visit(const ASString& name, InteractiveObject* pch) = 0;
    };

    ~DisplayList();

    DisplayEntry& GetDisplayEntry(UPInt index) { return DisplayObjectArray[index]; }

    void AddDisplayObject(DisplayObjectBase* powner, const CharPosInfo& pos, DisplayObjectBase* ch,
                          UInt32 addFlags);                                                    // 0x1425f8df0
    void AddDisplayObject(DisplayObjectBase* powner, UPInt index, DisplayObjectBase* ch);       // 0x1425f8f70
    void AddEntryAtIndex(DisplayObjectBase* powner, UPInt index, DisplayObjectBase* ch);        // 0x1425f9040
    void MoveDisplayObject(DisplayObjectBase* powner, const CharPosInfo& pos);                  // 0x1425fa410
    void ReplaceDisplayObject(DisplayObjectBase* powner, const CharPosInfo& pos,
                              DisplayObjectBase* ch);                                           // 0x1425fab10
    void ReplaceDisplayObjectAtIndex(DisplayObjectBase* powner, UPInt index, DisplayObjectBase* ch); // 0x1425facd0
    void RemoveDisplayObject(DisplayObjectBase* powner, int depth, ResourceId id);              // 0x1425fa6f0
    bool RemoveDisplayObject(DisplayObjectBase* powner, const DisplayObjectBase* ch);           // 0x1425fa7c0
    void RemoveEntryAtIndex(DisplayObjectBase* powner, UPInt index);                            // 0x1425fa820
    // Starts unloading entry index; true when it was removed right away (0x1425fb940).
    bool UnloadDisplayObjectAtIndex(DisplayObjectBase* powner, UPInt index);

    void PropagateMouseEvent(const EventId& id);                  // 0x1425fa5e0
    void PropagateKeyEvent(const EventId& id, int* pkeyMask);     // 0x1425fa540

    // Index of the first entry at depth or deeper (0x1425f9230); the exact match or ~0 (0x1425f97c0).
    UPInt FindDisplayIndex(int depth) const;
    UPInt GetDisplayIndex(int depth);
    bool  SwapDepths(DisplayObjectBase* powner, int depth1, int depth2, unsigned frame);           // 0x1425fb1e0
    bool  SwapEntriesAtIndexes(DisplayObjectBase* powner, UPInt index1, UPInt index2);            // 0x1425fb480
    int   GetLargestDepthInUse() const;                                                           // 0x1425f9b70

    DisplayObjectBase* GetDisplayObjectAtDepth(int depth, bool* pisMarkedForRemove = 0);          // 0x1425f9800
    DisplayObjectBase* GetDisplayObjectAtDepthAndUnmark(DisplayObjectBase* powner, int depth);    // 0x1425f9880
    DisplayObject*     GetDisplayObjectByName(const ASString& name, bool caseSensitive = true) const; // 0x1425f9920
    void               VisitMembers(MemberVisitor* pvisitor) const;                                // 0x1425fbb50

private:
    static int DepthLess(const DisplayEntry& e, int depth)         { return e.GetDepth() < depth; }
    static int DepthLess1(const DepthToIndexMapElem& e, int depth);

    void CheckAndInvalidateDepthMappings()
    {
        if ((Flags & Flags_MayContainForeignElems) != 0)
            Flags |= Flags_DepthToIndexInvalid;
    }

    void ReplaceRenderTreeNode(DisplayObjectBase* powner, UPInt index);               // 0x1425fad70
    bool SwapRenderTreeNodes(DisplayObjectBase* powner, UPInt index1, UPInt index2);  // 0x1425fb590
};

// (appended for the display list, sfr_gfx_06c) the depth -> index map of a display list with foreign entries
struct DisplayList::DepthToIndexMapElem
{
    int      Depth;
    unsigned Index;

    DepthToIndexMapElem(int d = DisplayList::INVALID_DEPTH, unsigned i = ~0u) : Depth(d), Index(i) {}
};

struct DisplayList::DepthToIndexContainer : public NewOverrideBase<322>
{
    ArrayLH<DepthToIndexMapElem> Array;

    void SetElement(UPInt index, int depth, unsigned mappedIndex)
    {
        if (index < Array.GetSize())
            Array[index] = DepthToIndexMapElem(depth, mappedIndex);
        else
            Array.PushBack(DepthToIndexMapElem(depth, mappedIndex));
    }
    void  SetSize(UPInt size) { Array.Resize(size); }
    UPInt GetSize() const     { return Array.GetSize(); }

    DepthToIndexMapElem&       operator[](UPInt i)       { return Array[i]; }
    const DepthToIndexMapElem& operator[](UPInt i) const { return Array[i]; }
};

inline int DisplayList::DepthLess1(const DepthToIndexMapElem& e, int depth) { return e.Depth < depth; }

inline DisplayList::~DisplayList()
{
    delete DepthToIndexMap;
}

class DisplayObjContainer : public InteractiveObject
{
public:
    DisplayObjContainer(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent,
                        ResourceId id);   // 0x1425fbbf0
    virtual ~DisplayObjContainer();

    virtual RectF           GetBounds(const Matrix& t) const;
    virtual CharacterDef*   GetCharacterDef() const;
    virtual RectF           GetRectBounds(const Matrix& t) const;
    virtual FontManager*    GetFontManager() const;
    virtual void            SetStateChangeFlags(UByte flags);
    virtual void            ForceShutdown();
    virtual TopMostResult   GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);
    virtual bool            PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;
    virtual void            PropagateMouseEvent(const EventId& id);
    virtual void            PropagateKeyEvent(const EventId& id, int* pkeyMask);
    virtual void            PropagateFocusGroupMask(unsigned mask);
    virtual void            RemoveDisplayObject(DisplayObjectBase* ch);
    virtual bool            Has3D();
    virtual void            UpdateViewAndPerspective();

    // addFlags is an unsigned long in the exe's signature.
    virtual DisplayObjectBase* AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                                const void* pinitSource, unsigned initSourceLen,
                                                unsigned long addFlags, CharacterCreateInfo* pcharCreateOverride,
                                                InteractiveObject* origChar);
    virtual void            ExecuteImportedInitActions(MovieDef* psourceMovie);
    virtual Sprite*         GetHitArea() const;
    virtual Sprite*         GetHitAreaHolder() const;
    virtual void            OnInsertionAsLevel(int level);
    virtual void            CreateAndReplaceDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                          DisplayObjectBase** newChar);

    MovieDefRootNode* FindRootNode() const;      // 0x1425fc4a0

protected:
    void              AssignRootNode(bool importFlag = false);   // 0x1425fbe90

public:

    DisplayList       mDisplayList;  // +0xd8
    MovieDefRootNode* pRootNode;     // +0x108 set on the root of a loaded movie

    // (appended for the interactive objects, sfr_gfx_06b) removes the child at depth with the given id (0x1425fd560)
    void RemoveDisplayObject(int depth, ResourceId id);

    // (appended for the containers, sfr_gfx_06d)
    AvmDisplayObjContainerBase* GetAvmDispContainer() const { return GetAvmObjImpl()->ToAvmDispContainerBase(); }

    // Per child: 0 where a clip layer (mask) hides pt; left empty when no child is a clip layer (0x1425fbff0).
    void CalcDisplayListHitTestMaskArray(Array<UByte>* phitTest, const PointF& pt, bool testShape) const;

    void MoveDisplayObject(const CharPosInfo& pos);                                           // 0x1425fcea0
    void ReplaceDisplayObject(const CharPosInfo& pos, DisplayObjectBase* ch, const ASString& name);   // 0x1425fd5e0
    DisplayObjectBase* GetChildAt(unsigned index) const;                                      // 0x1425fc530
    DisplayObjectBase* GetCharacterAtDepth(int depth);                                        // 0x1425fc4f0
    ResourceId         GetIdAtDepth(int depth);                                               // 0x1425fc590
    // ch is this container or one of its descendants (0x1425fc270).
    bool Contains(DisplayObjectBase* ch) const;
    void FillTabableArray(FillTabableParams* params);                                         // 0x1425fc460
};

// The AVM half of a container: slot 23.
class AvmDisplayObjContainerBase : public AvmInteractiveObjBase
{
public:
    virtual void FillTabableArray(InteractiveObject::FillTabableParams* params) = 0;
};

}} // namespace Scaleform::GFx

#endif
