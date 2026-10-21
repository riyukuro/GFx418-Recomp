// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx 4.1.18 GFx_InteractiveObject: the display
// objects that take input and advance (clips, buttons, text fields). An interactive object sits on the movie's
// advance list (pPlayNext / pPlayPrev, last added first) and, when its advance can be skipped otherwise, on the
// optimized advance list (pPlayNextOpt / pPlayPrevOpt) whose members carry the list's current marker bit.
// MS2-UNIT: sfr_gfx_06b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425f7c90-0x1425f8b20 .text$mn
// MS2-PIN: ??_7InteractiveObject@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x14318df70
// MS2-PIN: ??_7InteractiveObject@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x14318e308
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/render/render_twips.h"

namespace Scaleform { namespace GFx {

using Render::TreeNode;
using Render::TreeContainer;

// The AVM root's string manager (ASMovieRootBase vftable +0x190).
static inline ASStringManager* GetRootStringManager(ASMovieRootBase* proot)
{
    typedef ASStringManager* (*GetStringManagerFn)(ASMovieRootBase*);
    return (*(GetStringManagerFn**)proot)[0x190 / 8](proot);
}

static inline DisplayObjContainer* ToDisplayObjContainer(InteractiveObject* p)
{
    return p->IsDisplayObjContainer() ? static_cast<DisplayObjContainer*>(p) : 0;
}

// @0x1425f7c90
InteractiveObject::InteractiveObject(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot,
                                     InteractiveObject* pparent, ResourceId id)
    : DisplayObject(pasRoot, pparent, id),
      pDefImpl(pbindingDefImpl),
      Flags(Mask_Enabled),
      TabIndex(0),
      FocusGroupMask(0),
      RollOverCnt(0),
      pDisplayCallback(0),
      DisplayCallbackUserPtr(0)
{
    DisplayObjectBase::Flags |= DisplayObjectBase::Mask_InteractiveObject;
    pPlayNext = pPlayPrev = 0;
    pPlayNextOpt = pPlayPrevOpt = 0;
}

// @0x1425f7d50
InteractiveObject::~InteractiveObject()
{
    RemoveFromPlayList();
}

// ---------------------------------------------------------------------------------------------------------------------
// Advance lists

// After the first member of the advance list in front of it that is on the optimized list, else at its head.
// @0x1425f7e30
void InteractiveObject::AddToOptimizedPlayList()
{
    MovieImpl* proot = GetMovieImpl();
    if (IsOptAdvListFlagSet() || proot->IsOptAdvListInvalid())
    {
        ClearMarkToRemoveFromOptimizedPlayList();
        return;
    }
    if (IsUnloaded() || IsUnloading())
        return;

    InteractiveObject* cur = pPlayPrev;
    for (; cur; cur = cur->pPlayPrev)
    {
        if (cur->IsValidOptAdvListMember(proot))
            break;
    }
    if (cur)
    {
        pPlayNextOpt = cur->pPlayNextOpt;
        pPlayPrevOpt = cur;
        if (pPlayNextOpt)
            pPlayNextOpt->pPlayPrevOpt = this;
        cur->pPlayNextOpt = this;
    }
    else
    {
        pPlayNextOpt = proot->pPlayListOptHead;
        pPlayPrevOpt = 0;
        if (pPlayNextOpt)
            pPlayNextOpt->pPlayPrevOpt = this;
        proot->pPlayListOptHead = this;
    }
    Flags |= Mask_OptAdvList;
    SetOptAdvListMarker(proot->GetOptAdvListMarker());
    ClearMarkToRemoveFromOptimizedPlayList();
}

// @0x1425f7f70
void InteractiveObject::AddToPlayList()
{
    if (IsUnloaded() || IsUnloading())
        return;
    MovieImpl* proot = GetMovieImpl();
    if (proot->pPlayList)
    {
        proot->pPlayList->pPlayPrev = this;
        pPlayNext = proot->pPlayList;
    }
    proot->pPlayList = this;
}

// ---------------------------------------------------------------------------------------------------------------------
// Replacing a character

// @0x1425f7fc0
void InteractiveObject::CloneInternalData(const InteractiveObject* src)
{
    if (src->pGeomData)
        SetGeomData(*src->pGeomData);
    if (HasAvmObject())
        GetAvmIntObj()->CloneInternalData(src);
}

// @0x1425f8010
void InteractiveObject::CopyPhysicalProperties(const InteractiveObject* poldChar)
{
    Depth = poldChar->Depth;
    SetCxform(poldChar->GetCxform());
    // Is3D() as a bool-returning inline, the way the exe evaluates it
    bool is3D = [this]() -> bool { return pRenNode && pRenNode->Is3D(); }();
    if (is3D)
        SetMatrix3D(poldChar->GetMatrix3D());
    else
        SetMatrix(poldChar->GetMatrix());
    if (poldChar->pGeomData)
        SetGeomData(*poldChar->pGeomData);
    if (const Render::FilterSet* filters = poldChar->GetFilters())
        SetFilters(filters);
    if (HasAvmObject())
        GetAvmIntObj()->CopyPhysicalProperties(poldChar);
}

// @0x1425f8120
Ptr<TreeNode> InteractiveObject::CreateRenderNode(Render::Context& context) const
{
    Ptr<TreeContainer> node = *context.CreateEntry<TreeContainer>();
    return node;
}

// The dragged character puts its origin under the mouse (plus the grab offset), kept inside the drag bounds.
// @0x1425f81b0
// MS2-FUNCTIONAL: the exe keeps the identity parent matrix in registers and spills it only for GetWorldMatrix
void InteractiveObject::DoMouseDrag()
{
    MovieImpl* proot = GetMovieImpl();
    Render::PointF delta(proot->DragCenterDelta());
    bool           bound = proot->DragBound();
    Render::PointF lt(proot->DragBoundLT());
    Render::PointF rb(proot->DragBoundRB());
    if (proot->pKeepAdvancingChar != this)
        return;

    Render::PointF worldMouse(proot->MouseLastPosition);

    Matrix parentWorldMat;
    if (pParent)
        pParent->GetWorldMatrix(&parentWorldMat);
    Matrix inv(Render::NoInit);
    inv.SetInverse(parentWorldMat);
    float x = worldMouse.x;
    float y = worldMouse.y;
    inv.Transform(&x, &y);
    x += delta.x;
    y += delta.y;

    if (bound)
    {
        x = Alg::Min(x, rb.x);
        if (lt.x > x)
            x = lt.x;
        y = Alg::Min(y, rb.y);
        if (lt.y > y)
            y = lt.y;
    }

    SetAcceptAnimMoves(false);
    SetX(Render::TwipsToPixels(double(x)));
    SetY(Render::TwipsToPixels(double(y)));
}

// ---------------------------------------------------------------------------------------------------------------------
// Focus and cursor

// @0x1425f8480
unsigned InteractiveObject::GetCursorType() const
{
    if (HasAvmObject())
        return GetAvmIntObj()->GetCursorType();
    return 0;
}

// @0x1425f84b0
UInt16 InteractiveObject::GetFocusGroupMask()
{
    if (FocusGroupMask == 0 && pParent)
        FocusGroupMask = pParent->GetFocusGroupMask();
    return FocusGroupMask;
}

// @0x1425f84f0
UInt16 InteractiveObject::GetFocusGroupMask() const
{
    if (FocusGroupMask == 0)
        return pParent->GetFocusGroupMask();
    return FocusGroupMask;
}

// @0x1425f8540
TreeContainer* InteractiveObject::GetRenderContainer()
{
    return static_cast<TreeContainer*>(GetRenderNode());
}

// @0x1425f8550
MovieDefImpl* InteractiveObject::GetResourceMovieDef() const
{
    return pDefImpl;
}

// @0x1425f8560
ASStringManager* InteractiveObject::GetStringManager() const
{
    return GetRootStringManager(GetMovieImpl()->pASMovieRoot);
}

// @0x1425f8580
void InteractiveObject::InsertToPlayListAfter(InteractiveObject* pafterCh)
{
    if (IsUnloaded() || IsUnloading())
        return;
    pPlayPrev = pafterCh;
    pPlayNext = pafterCh->pPlayNext;
    pafterCh->pPlayNext = this;
    if (pPlayNext)
        pPlayNext->pPlayPrev = this;
}

// @0x1425f85e0
bool InteractiveObject::IsFocusAllowed(MovieImpl* proot, unsigned controllerIdx)
{
    unsigned focusIdx = proot->FocusGroupIndexes[controllerIdx];
    return (GetFocusGroupMask() & (1u << focusIdx)) != 0;
}

// @0x1425f8630
bool InteractiveObject::IsFocusAllowed(MovieImpl* proot, unsigned controllerIdx) const
{
    unsigned focusIdx = proot->FocusGroupIndexes[controllerIdx];
    return (GetFocusGroupMask() & (1u << focusIdx)) != 0;
}

// @0x1425f8690
bool InteractiveObject::IsFocusEnabled(FocusMovedType fmt) const
{
    if (HasAvmObject())
        return GetAvmIntObj()->IsFocusEnabled(fmt);
    return true;
}

// _focusrect: the object's own setting, else the one of its root clip.
// @0x1425f86d0
bool InteractiveObject::IsFocusRectEnabled() const
{
    if (IsFocusRectFlagDefined())
        return IsFocusRectFlagTrue();
    InteractiveObject* ptop = GetTopParent(true);
    if (ptop && ptop != this)
        return ptop->IsFocusRectEnabled();
    return true;
}

// @0x1425f8730
bool InteractiveObject::IsInPlayList() const
{
    return pPlayNext || pPlayPrev || GetMovieImpl()->pPlayList == this;
}

// @0x1425f8760
bool InteractiveObject::IsTabable() const
{
    if (HasAvmObject())
        return GetAvmIntObj()->IsTabable();
    return false;
}

// @0x1425f87a0
bool InteractiveObject::IsValidOptAdvListMember(MovieImpl* proot) const
{
    return IsOptAdvListFlagSet() && IsOptAdvListMarkerSet() == proot->GetOptAdvListMarker();
}

// @0x1425f87d0
void InteractiveObject::MoveNameHandle(InteractiveObject* poldChar)
{
    pNameHandle = poldChar->pNameHandle;
    poldChar->pNameHandle = 0;
    if (pNameHandle)
        pNameHandle->pCharacter = this;
}

// ---------------------------------------------------------------------------------------------------------------------
// Events

// @0x1425f8870
void InteractiveObject::OnEventLoad()
{
    DisplayObject::OnEventLoad();
}

// @0x1425f8880
void InteractiveObject::OnEventUnload()
{
    SetUnloading();
    MovieImpl* proot = GetMovieImpl();
    RemoveFromPlayList();
    // A dragged character that goes away ends the drag.
    if (proot->pKeepAdvancingChar == this)
        proot->pKeepAdvancingChar = 0;
    proot->ResetFocusForChar(this);
    DisplayObject::OnEventUnload();
}

// @0x1425f88e0
void InteractiveObject::OnFocus(FocusEventType event, InteractiveObject* oldOrNewFocusCh, unsigned controllerIdx,
                                FocusMovedType fmt)
{
    if (HasAvmObject())
        GetAvmIntObj()->OnFocus(event, oldOrNewFocusCh, controllerIdx, fmt);
}

// @0x1425f8940
bool InteractiveObject::OnUnloading()
{
    return DisplayObject::OnUnloading();
}

// @0x1425f8950
void InteractiveObject::RemoveDisplayObject()
{
    if (pParent)
    {
        DisplayObjContainer* pparent = ToDisplayObjContainer(pParent);
        if (pparent)
            pparent->RemoveDisplayObject(Depth, ResourceId(Id));
    }
}

// @0x1425f89a0
void InteractiveObject::RemoveFromOptimizedPlayList()
{
    if (!IsOptAdvListFlagSet())
        return;
    MovieImpl* proot = GetMovieImpl();
    if (!proot->IsOptAdvListInvalid())
    {
        if (pPlayPrevOpt)
            pPlayPrevOpt->pPlayNextOpt = pPlayNextOpt;
        else
            proot->pPlayListOptHead = pPlayNextOpt;
        if (pPlayNextOpt)
            pPlayNextOpt->pPlayPrevOpt = pPlayPrevOpt;
    }
    pPlayNextOpt = pPlayPrevOpt = 0;
    Flags &= ~(Mask_OptAdvList | Mask_MarkedToRemoveFromOptAdvList);
}

// @0x1425f8a20
void InteractiveObject::RemoveFromPlayList()
{
    MovieImpl* proot = GetMovieImpl();
    if (IsOptAdvListFlagSet())
    {
        if (!proot->IsOptAdvListInvalid())
        {
            if (pPlayPrevOpt)
                pPlayPrevOpt->pPlayNextOpt = pPlayNextOpt;
            else
                proot->pPlayListOptHead = pPlayNextOpt;
            if (pPlayNextOpt)
                pPlayNextOpt->pPlayPrevOpt = pPlayPrevOpt;
        }
        Flags &= ~(Mask_OptAdvList | Mask_MarkedToRemoveFromOptAdvList);
        pPlayNextOpt = pPlayPrevOpt = 0;
    }
    if (pPlayNext)
        pPlayNext->pPlayPrev = pPlayPrev;
    if (pPlayPrev)
        pPlayPrev->pPlayNext = pPlayNext;
    else if (proot->pPlayList == this)
        proot->pPlayList = pPlayNext;
    pPlayNext = pPlayPrev = 0;
}

// @0x1425f8b10
void InteractiveObject::SetNextUnloaded(InteractiveObject* punloadQueue)
{
    SetUnloaded();
    pNextUnloaded = punloadQueue;
}

}} // namespace Scaleform::GFx
