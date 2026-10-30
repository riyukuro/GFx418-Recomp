// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx 4.1.18 GFx_DisplayObjContainer: the display
// objects owning a display list (sprites, buttons' states). The root sprite of every loaded movie shares a root node
// (font manager, load progress) with the other roots of the same movie def and import flag; the nodes sit on the
// movie's root node list, counted by the sprites using them. Hit tests walk the children from the top down, clip
// layers (ClipDepth > 0) first deciding which of the children they cover may be hit at all.
// MS2-UNIT: sfr_gfx_06d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425fbbf0-0x1425fd750 .text$mn
// MS2-PIN: ??1DisplayList@GFx@Scaleform@@QEAA@XZ 0x1425fbc60
// MS2-PIN: ??_7DisplayObjContainer@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x14318e318
// MS2-PIN: ??_7DisplayObjContainer@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x14318e6e0
#include <new>
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_fontmanager.h"
#include "../include/render/render_screentoworld.h"

namespace Scaleform { namespace GFx {

// ASMovieRootBase has no recovered virtuals yet; the two slots called here go through its vftable.
typedef MovieDefRootNode* (*CreateMovieDefRootNodeFn)(ASMovieRootBase*, MemoryHeap*, MovieDefImpl*, bool);
typedef void (*ResolveStickyVariablesFn)(ASMovieRootBase*, InteractiveObject*);

// A root node for pdefImpl, allocated on pheap (slot 6).
static inline MovieDefRootNode* CreateMovieDefRootNode(ASMovieRootBase* proot, MemoryHeap* pheap,
                                                       MovieDefImpl* pdefImpl, bool importFlag)
{
    return (*reinterpret_cast<CreateMovieDefRootNodeFn* const*>(proot))[6](proot, pheap, pdefImpl, importFlag);
}

// Assigns the variables set on the character's path before it existed (slot 30).
static inline void ResolveStickyVariables(ASMovieRootBase* proot, InteractiveObject* pch)
{
    (*reinterpret_cast<ResolveStickyVariablesFn* const*>(proot))[30](proot, pch);
}

// The movie's root node list (List<MovieDefRootNode>).
static inline void RemoveRootNode(MovieDefRootNode* p)
{
    p->pPrev->pNext = p->pNext;
    p->pNext->pPrev = p->pPrev;
}

static inline void PushFrontRootNode(MovieDefRootNodeLinks* proot, MovieDefRootNode* p)
{
    p->pNext             = proot->pNext;
    p->pPrev             = static_cast<MovieDefRootNode*>(proot);
    proot->pNext->pPrev  = p;
    proot->pNext         = p;
}

// The hitTestMask bits of PointTestLocal.
enum
{
    HitTest_TestShape       = 1,   // the shapes, not only the bounds
    HitTest_IgnoreInvisible = 2
};

static SF_FORCEINLINE bool ActsAsButton(const InteractiveObject* pch)
{
    return pch->HasAvmObject() && pch->GetAvmIntObj()->ActsAsButton();
}

static inline InteractiveObject* CharToInteractiveObject(DisplayObjectBase* pch)
{
    return pch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pch) : 0;
}

static inline DisplayObjContainer* CharToDisplayObjContainer(DisplayObjectBase* pch)
{
    return pch->IsDisplayObjContainer() ? static_cast<DisplayObjContainer*>(pch) : 0;
}

static inline const DisplayObjContainer* CharToDisplayObjContainer(const DisplayObjectBase* pch)
{
    return pch->IsDisplayObjContainer() ? static_cast<const DisplayObjContainer*>(pch) : 0;
}

// @0x1425fbbf0
DisplayObjContainer::DisplayObjContainer(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot,
                                         InteractiveObject* pparent, ResourceId id)
    : InteractiveObject(pbindingDefImpl, pasRoot, pparent, id),
      pRootNode(0)
{
    DisplayObjectBase::Flags |= Mask_DisplayObjContainer;
}

// @0x1425fbcf0
DisplayObjContainer::~DisplayObjContainer()
{
    if (pRootNode)
    {
        pRootNode->SpriteRefCount--;
        if (pRootNode->SpriteRefCount == 0)
        {
            RemoveRootNode(pRootNode);
            delete pRootNode;
        }
    }
    mDisplayList.Clear(this);
    SetDirtyFlag();
}

// @0x1425fbe90
// MS2-FUNCTIONAL: register allocation only (the exe keeps the movie in r14 across the search loop)
void DisplayObjContainer::AssignRootNode(bool importFlag)
{
    if (!pRootNode)
    {
        // Share the node of another root of the same movie def and import flag.
        MovieImpl*        pmovie = GetMovieImpl();
        MovieDefRootNode* pnode  = pmovie->RootMovieDefNodes.pNext;
        while (pnode != static_cast<MovieDefRootNode*>(&pmovie->RootMovieDefNodes))
        {
            if (pnode->pDefImpl == pDefImpl && pnode->ImportFlag == importFlag)
            {
                pnode->SpriteRefCount++;
                pRootNode = pnode;
                return;
            }
            pnode = pnode->pNext;
        }

        {
            MemoryHeap* pheap = pmovie->GetMovieHeap();

            pRootNode = CreateMovieDefRootNode(pASRoot, pheap, pDefImpl, importFlag);
            // The bytes first: the loading thread keeps advancing both.
            pRootNode->BytesLoaded  = pDefImpl->pBindData->GetBytesLoaded();
            pRootNode->LoadingFrame = importFlag ? 0 : pDefImpl->GetLoadingFrame();

            // The fonts of the movie's sprites resolve against this def's bindings.
            void*        pmem = pheap->Alloc(0x70);
            FontManager* pfontManager =
                pmem ? ::new (pmem) FontManager(GetMovieImpl(), pDefImpl, GetMovieImpl()->pFontManagerStates) : 0;
            MovieDefRootNode* proot = pRootNode;
            if (proot->pFontManager)
                reinterpret_cast<RefCountImpl*>(proot->pFontManager)->Release();
            proot->pFontManager = pfontManager;

            PushFrontRootNode(&GetMovieImpl()->RootMovieDefNodes, pRootNode);
        }
    }
}

// @0x1425fbff0
// MS2-FUNCTIONAL: the inlined matrix inverse schedules its float registers differently
void DisplayObjContainer::CalcDisplayListHitTestMaskArray(Array<UByte>* phitTest, const PointF& pt,
                                                          bool testShape) const
{
    SF_UNUSED(testShape);

    UPInt i, n = mDisplayList.GetCount();
    for (i = 0; i < n; i++)
    {
        DisplayObjectBase* pmaskch = mDisplayList.GetDisplayObject(i);
        if (pmaskch->ClipDepth > 0)
        {
            if (phitTest->GetSize() == 0)
            {
                phitTest->Resize(n);
                memset(&(*phitTest)[0], 1, n);
            }

            PointF p = pmaskch->GetMatrix().TransformByInverse(pt);
            (*phitTest)[i] = pmaskch->PointTestLocal(p, HitTest_TestShape);

            // The clip covers the children up to its clip depth.
            UPInt k = i + 1;
            while (k < n)
            {
                DisplayObjectBase* pch = mDisplayList.GetDisplayObject(k);
                if (pch && pch->Depth > pmaskch->ClipDepth)
                    break;
                (*phitTest)[k] = (*phitTest)[i];
                k++;
            }
            i = k - 1;
        }
    }
}

// @0x1425fc270
bool DisplayObjContainer::Contains(DisplayObjectBase* ch) const
{
    if (this == ch)
        return true;
    for (UPInt i = 0, n = mDisplayList.GetCount(); i < n; ++i)
    {
        DisplayObjectBase* pch = mDisplayList.GetDisplayObject(i);
        if (ch == pch)
            return true;
        DisplayObjContainer* pcont = CharToDisplayObjContainer(pch);
        if (pcont && pcont->Contains(ch))
            return true;
    }
    return false;
}

// @0x1425fc320
void DisplayObjContainer::CreateAndReplaceDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                        DisplayObjectBase** newChar)
{
    CharacterCreateInfo ccinfo = pDefImpl->GetCharacterCreateInfo(pos.CharacterId);
    if (ccinfo.pCharDef == 0)
    {
        LogError("DisplayObjContainer::ReplaceDisplayObject() - unknown cid = %d", pos.CharacterId.GetIdIndex());
        return;
    }

    Ptr<DisplayObjectBase> ch =
        *pASRoot->pASSupport->CreateCharacterInstance(GetMovieImpl(), ccinfo, this, pos.CharacterId);

    ReplaceDisplayObject(pos, ch, name);

    if (newChar)
        *newChar = (ch->GetRefCount() > 1) ? ch.GetPtr() : 0;
}

// @0x1425fc460
void DisplayObjContainer::FillTabableArray(FillTabableParams* params)
{
    if (HasAvmObject())
        GetAvmDispContainer()->FillTabableArray(params);
}

// @0x1425fc4a0
MovieDefRootNode* DisplayObjContainer::FindRootNode() const
{
    // The nearest container up the parent chain that is the root of a loaded movie.
    const InteractiveObject* pchar = this;
    while (pchar)
    {
        const DisplayObjContainer* psprite = CharToDisplayObjContainer(pchar);
        if (psprite && psprite->pRootNode)
            return psprite->pRootNode;
        pchar = pchar->GetParent();
    }
    return 0;
}

// @0x1425fc4e0
void DisplayObjContainer::ForceShutdown()
{
    mDisplayList.Clear(this);
}

// @0x1425fc4f0
DisplayObjectBase* DisplayObjContainer::GetCharacterAtDepth(int depth)
{
    UPInt index = mDisplayList.GetDisplayIndex(depth);
    if (index == SF_MAX_UPINT)
        return 0;
    return mDisplayList.GetDisplayObject(index);
}

// @0x1425fc530
DisplayObjectBase* DisplayObjContainer::GetChildAt(unsigned index) const
{
    if (index >= mDisplayList.GetCount())
        return 0;
    return mDisplayList.GetDisplayObject(index);
}

// @0x1425fc590
ResourceId DisplayObjContainer::GetIdAtDepth(int depth)
{
    DisplayObjectBase* pch = GetCharacterAtDepth(depth);
    return pch ? ResourceId(pch->Id) : ResourceId();
}

// @0x1425fc5f0
// MS2-FUNCTIONAL: register allocation and block layout around the shared epilogue that frees the hit-test array
DisplayObjectBase::TopMostResult DisplayObjContainer::GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr)
{
    Sprite* phitAreaHolder = GetHitAreaHolder();

    // Hidden containers take no mouse events unless they are a hit area; masks never do.
    if ((Flags & Mask_HitTestDisable) || (!GetVisible() && !phitAreaHolder) || IsUsedAsMask())
    {
        pdescr->pResult = 0;
        return TopMost_FoundNothing;
    }
    if (pdescr->pIgnoreMC == this || !IsFocusAllowed(GetMovieImpl(), pdescr->ControllerIdx))
    {
        pdescr->pResult = 0;
        return TopMost_FoundNothing;
    }

    PointF localPt;
    if (!TransformPointToLocalAndCheckBounds(&localPt, pt))
        return TopMost_FoundNothing;

    DisplayObject* pmask = GetMask();
    if (pmask && pmask->IsUsedAsMask() && !pmask->IsUnloaded())
    {
        PointF pp;
        if (!pmask->Is3D())
        {
            Matrix2F matrix;
            Matrix2F maskWorld;
            pmask->GetWorldMatrix(&maskWorld);
            matrix.SetInverse(maskWorld);
            Matrix2F world;
            GetWorldMatrix(&world);
            matrix.Prepend(world);
            pp.x = matrix.M[0][0] * localPt.x + matrix.M[0][1] * localPt.y + matrix.M[0][3];
            pp.y = matrix.M[1][0] * localPt.x + matrix.M[1][1] * localPt.y + matrix.M[1][3];
        }
        else
        {
            Matrix3F view;
            Matrix4F proj;
            Matrix3F world;
            pmask->GetWorldMatrix3D(&world);
            Render::ScreenToWorld& stw = GetMovieImpl()->GetScreenToWorld();

            if (pmask->GetProjectionMatrix3D(&proj))
                stw.SetProjection(proj);
            if (pmask->GetViewMatrix3D(&view))
                stw.SetView(view);
            stw.SetWorld(world);
            stw.GetWorldPoint(&pp);
        }

        if (!pmask->PointTestLocal(pp, HitTest_TestShape))
        {
            pdescr->pResult = 0;
            return TopMost_FoundNothing;
        }
    }

    Array<UByte> hitTest;
    CalcDisplayListHitTestMaskArray(&hitTest, localPt, true);
    TopMostDescr  savedDescr;
    TopMostResult savedTe              = TopMost_FoundNothing;
    bool          foundButMouseDisabled = false;

    // Backwards: the higher objects first.
    for (SPInt i = (SPInt)mDisplayList.GetCount() - 1; i >= 0; i--)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);

        if (hitTest.GetSize() && (!hitTest[i] || ch->ClipDepth > 0))
            continue;
        if (ch->IsTopmostLevelFlagSet())
            continue;

        TopMostResult te = ch->GetTopMostMouseEntity(localPt, pdescr);
        if (te == TopMost_Found)
        {
            if (Flags & Mask_MouseChildrenDisabled)
                pdescr->pResult = this;
            if (pdescr->pResult && (pdescr->pResult->Flags & Mask_MouseDisabled))
            {
                pdescr->pResult       = this;
                foundButMouseDisabled = true;
                continue;
            }
            if (pdescr->TestAll)
                te = TopMost_Found;
        }
        else if (te == TopMost_Continue && pdescr->pResult)
        {
            savedTe    = TopMost_Found;
            savedDescr = *pdescr;
        }

        // A hit in button mode is ours (or the hit area holder's).
        if (ActsAsButton(this) || (phitAreaHolder && ActsAsButton(phitAreaHolder)))
        {
            if (te == TopMost_Found || savedTe == TopMost_Found)
            {
                if (phitAreaHolder && ActsAsButton(phitAreaHolder))
                {
                    pdescr->pResult = phitAreaHolder;
                    return TopMost_Found;
                }

                Sprite* phitArea = GetHitArea();
                if (GetAVMVersion() == 1)
                {
                    if (phitArea)
                    {
                        // A hit area that is not our descendant takes our mouse events away.
                        InteractiveObject* parent = phitArea;
                        do {
                            parent = parent->GetParent();
                        } while (parent && parent != this);
                        if (!parent)
                        {
                            pdescr->pResult = 0;
                            return TopMost_FoundNothing;
                        }
                        return phitArea->GetTopMostMouseEntity(localPt, pdescr);
                    }
                    pdescr->pResult = this;
                    return TopMost_Found;
                }
                // AS3: the hit area does not count when a child interactive object was hit.
                if (phitArea && (!pdescr->pResult || pdescr->pResult == this ||
                                 !pdescr->pResult->IsInteractiveObject()))
                    return phitArea->GetTopMostMouseEntity(localPt, pdescr);
            }
            if (te == TopMost_Found && pdescr->TestAll)
                return te;
        }
        else
        {
            if (te == TopMost_Found && pdescr->TestAll)
                return te;
            if (te == TopMost_Found && pdescr->pResult != this)
            {
                // _root has no parent.
                if (pdescr->pResult->GetParent() && pdescr->pResult->GetParent()->GetVisible())
                    return te;
                pdescr->pResult = 0;
                return TopMost_FoundNothing;
            }
        }
    }

    if (savedTe == TopMost_Found)
    {
        *pdescr = savedDescr;
        return TopMost_Found;
    }
    pdescr->LocalPt = localPt;
    if (foundButMouseDisabled)
    {
        pdescr->pResult = this;
        return TopMost_Found;
    }
    pdescr->pResult = 0;
    return TopMost_Continue;
}

// @0x1425fcdd0
bool DisplayObjContainer::Has3D()
{
    if (pRenNode && pRenNode->Is3D())
        return true;

    for (UPInt i = 0, n = mDisplayList.GetCount(); i < n; ++i)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);
        if (ch && ch->Has3D())
            return true;
    }
    return false;
}

// @0x1425fcea0
void DisplayObjContainer::MoveDisplayObject(const CharPosInfo& pos)
{
    mDisplayList.MoveDisplayObject(this, pos);
    SetDirtyFlag();
}

// @0x1425fced0
void DisplayObjContainer::OnInsertionAsLevel(int level)
{
    if (level == 0)
        SetFocusRectFlag();   // _focusrect of _root is on by default
    else if (level > 0)
    {
        // The other levels inherit it from _level0.
        InteractiveObject* plevel0 = GetMovieImpl()->pMainMovie;
        if (plevel0)
            SetFocusRectFlag(plevel0->IsFocusRectEnabled());
    }
    AddToPlayList();
    ModifyOptimizedPlayList();
    FocusGroupMask = 0xFFFF;
}

// @0x1425fcfa0
bool DisplayObjContainer::PointTestLocal(const PointF& pt, UByte hitTestMask) const
{
    if ((UByte)(Flags >> 11) & 1)
        return false;

    if (!(DisplayObjectBase::Flags & Mask_Scale9GridExists) && !GetBounds(Matrix2F()).Contains(pt))
        return false;

    if ((hitTestMask & HitTest_IgnoreInvisible) && !GetVisible())
        return false;

    SPInt i, n = (SPInt)mDisplayList.GetCount();

    DisplayObject* pmask = GetMask();
    if (pmask && pmask->IsUsedAsMask() && !pmask->IsUnloaded())
    {
        Matrix2F matrix;
        {
            Matrix2F maskWorld;
            pmask->GetWorldMatrix(&maskWorld);
            matrix.SetInverse(maskWorld);
        }
        {
            Matrix2F world;
            GetWorldMatrix(&world);
            matrix.Prepend(world);
        }
        PointF p(matrix.M[0][0] * pt.x + matrix.M[0][1] * pt.y + matrix.M[0][3],
                 matrix.M[1][0] * pt.x + matrix.M[1][1] * pt.y + matrix.M[1][3]);

        if (!pmask->PointTestLocal(p, hitTestMask))
            return false;
    }

    Array<UByte> hitTest;
    CalcDisplayListHitTestMaskArray(&hitTest, pt, (hitTestMask & HitTest_TestShape) != 0);

    Matrix2F m;
    PointF   p = pt;

    // Backwards: the higher objects first.
    for (i = n - 1; i >= 0; i--)
    {
        DisplayObjectBase* pch = mDisplayList.GetDisplayObject(i);

        if ((hitTestMask & HitTest_IgnoreInvisible) && !pch->GetVisible())
            continue;
        if (hitTest.GetSize() && (!hitTest[i] || pch->ClipDepth > 0))
            continue;

        m = pch->GetMatrix();
        p = m.TransformByInverse(pt);
        if (pch->PointTestLocal(p, hitTestMask))
            return true;
    }
    return false;
}

// @0x1425fd3d0
void DisplayObjContainer::PropagateFocusGroupMask(unsigned mask)
{
    FocusGroupMask = (UInt16)mask;
    for (UPInt i = 0, n = mDisplayList.GetCount(); i < n; ++i)
    {
        InteractiveObject* ch = CharToInteractiveObject(mDisplayList.GetDisplayObject(i));
        if (ch)
        {
            ch->FocusGroupMask = (UInt16)mask;
            ch->PropagateFocusGroupMask(mask);
        }
    }
}

// @0x1425fd460
void DisplayObjContainer::PropagateKeyEvent(const EventId& id, int* pkeyMask)
{
    Ptr<DisplayObjContainer> thisHolder(this);   // the handlers may release this

    // Hidden clips take no key events.
    if (!GetVisible())
        return;

    mDisplayList.PropagateKeyEvent(id, pkeyMask);
    // Then this one, after its children.
    OnKeyEvent(id, pkeyMask);
}

// @0x1425fd4d0
void DisplayObjContainer::PropagateMouseEvent(const EventId& id)
{
    Ptr<DisplayObjContainer> thisHolder(this);   // the handlers may release this

    // A dragged clip follows the mouse.
    if (id.Id == EventId::Event_MouseMove && GetMovieImpl()->IsMouseSupportEnabled())
        DoMouseDrag();

    // Hidden clips take no mouse events.
    if (!GetVisible())
        return;

    mDisplayList.PropagateMouseEvent(id);
    // Then this one, after its children.
    if (HasAvmObject())
        GetAvmDispContainer()->OnEvent(id);
}

// @0x1425fd560
void DisplayObjContainer::RemoveDisplayObject(int depth, ResourceId id)
{
    mDisplayList.RemoveDisplayObject(this, depth, id);
    SetDirtyFlag();
}

// @0x1425fd5a0
void DisplayObjContainer::RemoveDisplayObject(DisplayObjectBase* ch)
{
    SPInt i = mDisplayList.FindDisplayIndex(ch);
    if (i >= 0)
        mDisplayList.RemoveEntryAtIndex(this, UPInt(i));
}

// @0x1425fd5e0
void DisplayObjContainer::ReplaceDisplayObject(const CharPosInfo& pos, DisplayObjectBase* ch, const ASString& name)
{
    if (name.GetSize() != 0 && IsScriptableObject())
        static_cast<DisplayObject*>(ch)->SetName(name);

    mDisplayList.ReplaceDisplayObject(this, pos, ch);

    if (name.GetSize() != 0 && ch->IsInteractiveObject())
        ResolveStickyVariables(pASRoot, static_cast<InteractiveObject*>(ch));
    SetDirtyFlag();
}

// @0x1425fd670
void DisplayObjContainer::SetStateChangeFlags(UByte flags)
{
    Flags &= ~Mask_ChangedFlags;
    Flags |= (flags & 0xF) << 16;
    UPInt size = mDisplayList.GetCount();
    for (UPInt i = 0; i < size; ++i)
        mDisplayList.GetDisplayObject(i)->SetStateChangeFlags(flags);
}

// @0x1425fd6f0
void DisplayObjContainer::UpdateViewAndPerspective()
{
    InteractiveObject::UpdateViewAndPerspective();

    for (UPInt i = 0, n = mDisplayList.GetCount(); i < n; ++i)
    {
        DisplayObjectBase* ch = mDisplayList.GetDisplayObject(i);
        if (ch)
            ch->UpdateViewAndPerspective();
    }
}

// (sfr24) a virtual the full exe links by name (work/sfr35/outside-units.tsv).
// The font manager of the loaded movie this container roots, else the parent's, else that of the main movie.
// @0x1425fc550
FontManager* DisplayObjContainer::GetFontManager() const
{
    if (pRootNode)
        return pRootNode->pFontManager;
    if (!pParent)
        return GetMovieImpl()->RootMovieDefNodes.pNext->pFontManager;
    return pParent->GetFontManager();
}

}} // namespace Scaleform::GFx
