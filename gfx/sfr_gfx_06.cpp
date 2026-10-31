// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx 4.1.18 GFx_DisplayObject: the display
// object base classes (DisplayObjectBase, DisplayObject) and the named handles of the AS2 characters. A display
// object keeps its transform, color transform, blend mode, filters and scale9 grid on its render tree node; the AS
// properties (x, y, scales, rotations, perspective) are kept in lazily allocated GeomDataType / PerspectiveDataType
// records and folded back into the node matrices.
// Queue unit sfr_gfx_06 is split along its original sources (06 DisplayObject, 06b InteractiveObject, 06c
// DisplayList, 06d DisplayObjContainer, 06e DrawingContext, 06f Input, 06g Text_StyleSheet).
// MS2-UNIT: sfr_gfx_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425f0690-0x1425f7c90 .text$mn
// MS2-PIN: ??_7RefCountWeakSupportImpl@Scaleform@@6B@ 0x143183cf8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountWeakSupportImpl@Scaleform@@$0BEC@@Scaleform@@6B@ 0x14318da40
// MS2-PIN: ??_7?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@Scaleform@@6B@ 0x14318da48
// MS2-PIN: ??_7?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x14318da50
// MS2-PIN: ??_7DisplayObjectBase@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x14318da60
// MS2-PIN: ??_7DisplayObjectBase@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x14318dcc0
// MS2-PIN: ??_7DisplayObject@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@2@@ 0x14318dcd0
// MS2-PIN: ??_7DisplayObject@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@12@@ 0x14318df48
// MS2-PIN: ??_GDisplayObject@GFx@Scaleform@@UEAAPEAXI@Z 0x1425f0c10
// MS2-FUNCTIONAL 0x1425f0c10: compiler-generated deleting dtor; inlines ~DisplayObject, which differs as noted there
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_types.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_drawingcontext.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/render/render_twips.h"
#include "../include/render/render_viewport.h"
#include "../include/render/render_screentoworld.h"

namespace Scaleform { namespace GFx {

using Render::TreeNode;
using Render::TreeContainer;
using Render::Cxform;
using Render::Point3F;

// The AVM root's string manager (ASMovieRootBase vftable +0x190).
static inline ASStringManager* GetRootStringManager(ASMovieRootBase* proot)
{
    typedef ASStringManager* (*GetStringManagerFn)(ASMovieRootBase*);
    return (*(GetStringManagerFn**)proot)[0x190 / 8](proot);
}

// ---------------------------------------------------------------------------------------------------------------------
// CharacterHandle

// @0x1425f0690
CharacterHandle::CharacterHandle(const ASString& name, DisplayObject* pparent, DisplayObject* pcharacter)
    : RefCount(1), pCharacter(pcharacter), Name(name), NamePath(name.GetManager()->GetEmptyStringNode()),
      OriginalName(name)
{
    // AS2 names resolve by path.
    if (pcharacter && pcharacter->GetAVMVersion() == 1)
    {
        String path;
        if (pparent)
            pparent->GetAbsolutePath(&path);
        path += ".";
        path += Name.ToCStr();
        NamePath = name.GetManager()->CreateString(path.ToCStr(), path.GetSize());
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// Construction

// @0x1425f07e0
// MS2-FUNCTIONAL: the exe ctor is a leaf (base ctor inlined differently), same stores
DisplayObject::DisplayObject(ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id)
    : DisplayObjectBase(pasRoot, pparent, id), pScrollRect(0), Flags(0)
{
    pMaskCharacter = 0;
    DisplayObjectBase::Flags |= Mask_ScriptableObject;
    Flags |= Mask_InstanceBasedName;
    Flags |= Mask_AcceptAnimMoves;
}

// @0x1425f0880
DisplayObjectBase::DisplayObjectBase(ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id)
    : pASRoot(pasRoot), Id(id.GetIdValue()), Depth(-1), CreateFrame(0), pParent(pparent), pGeomData(0),
      pPerspectiveData(0), pIndXFormData(0), ClipDepth(0), Flags(0), BlendMode(Render::Blend_None), AvmObjOffset(0)
{
    SetVisibleFlag();
}

// @0x1425f0900
CharacterHandle::~CharacterHandle()
{
}

// @0x1425f0950
// MS2-FUNCTIONAL: the exe inlines the pNameHandle release with ~CharacterHandle and the heap free, ours calls it
DisplayObject::~DisplayObject()
{
    delete pScrollRect;
    if (GetMask())
        SetMask(0);
    DisplayObject* pmaskOwner = GetMaskOwner();
    if (pmaskOwner)
        pmaskOwner->SetMask(0);
    if (pNameHandle)
        pNameHandle->ReleaseCharacter();
}

// @0x1425f0a60
DisplayObjectBase::~DisplayObjectBase()
{
    if (pGeomData)
        delete pGeomData;
    if (pPerspectiveData)
        delete pPerspectiveData;
    if (pIndXFormData)
        delete pIndXFormData;
    if (HasAvmObject())
        GetAvmObjImpl()->~AvmDisplayObjBase();
}

// Rotates the 2x2 part of m by radians and scales its columns.
// @0x1425f0dd0
void ASCharacter_MatrixScaleAndRotate2x2(Render::Matrix2F& m, float sx, float sy, float radians)
{
    float cosAngle = cosf(radians);
    float sinAngle = sinf(radians);
    float x00      = m.Sx();
    float x01      = m.Shx();
    float x10      = m.Shy();
    float x11      = m.Sy();

    m.Sx()  = (x00 * cosAngle - x10 * sinAngle) * sx;
    m.Shx() = (x01 * cosAngle - x11 * sinAngle) * sy;
    m.Shy() = (x00 * sinAngle + x10 * cosAngle) * sx;
    m.Sy()  = (x01 * sinAngle + x11 * cosAngle) * sy;
}

// @0x1425f0f60
void DisplayObjectBase::BindAvmObj(AvmDisplayObjBase* p)
{
    AvmObjOffset = UByte(((UPInt)((UByte*)p - (UByte*)this) + 3) / 4);
}

// @0x1425f0f70
void CharacterHandle::ChangeName(const ASString& name, DisplayObject* pparent)
{
    Name = name;
    if (pparent && pparent->GetAVMVersion() == 1)
    {
        String path;
        pparent->GetAbsolutePath(&path);
        path += ".";
        path += Name.ToCStr();
        NamePath = name.GetManager()->CreateString(path.ToCStr(), path.GetSize());
    }
}

// The last hit test result is kept for one point.
// @0x1425f10a0
bool DisplayObjectBase::CheckLastHitResult(float x, float y) const
{
    return (Flags & (Mask_HitTestNegative | Mask_HitTestPositive)) && x == LastHitTestX && y == LastHitTestY;
}

// @0x1425f10c0
void DisplayObjectBase::Clear3D(bool inherit)
{
    if (inherit)
        if (pParent)
            pParent->Clear3D(inherit);

    GeomDataType geomData;
    SetGeomData(geomData);

    if (pRenNode)
        pRenNode->Clear3D();
}

// ---------------------------------------------------------------------------------------------------------------------
// Render node access

// @0x1425f26b0
// MS2-FUNCTIONAL: the context is reached through the placeholder words of MovieImpl
Render::ContextImpl::Context& DisplayObjectBase::GetRenderContext() const
{
    return *reinterpret_cast<Render::ContextImpl::Context*>(GetMovieImpl()->RenderContext);
}

// @0x1425f26c0
Render::TreeNode* DisplayObjectBase::GetRenderNode() const
{
    if (!pRenNode)
    {
        const_cast<Ptr<TreeNode>&>(pRenNode) = CreateRenderNode(GetRenderContext());
        pRenNode->SetVisible(IsVisibleFlagSet());
    }
    return pRenNode.GetPtr();
}

// @0x1425f1d00
const Cxform& DisplayObjectBase::GetCxform() const
{
    if (pRenNode)
        return pRenNode->GetCxform();
    return Cxform::Identity;
}

// @0x1425f4060
void DisplayObjectBase::SetCxform(const Cxform& cx)
{
    GetRenderNode()->SetCxform(cx);
}

// @0x1425f1150
void DisplayObjectBase::ConcatenateCxform(const Cxform& cx)
{
    Cxform cx1(GetCxform());
    cx1.Prepend(cx);
    SetCxform(cx1);
}

// @0x1425f1210
void DisplayObjectBase::ConcatenateMatrix(const Matrix& m)
{
    if (Is3D())
    {
        Matrix3F m1(GetMatrix3D());
        m1.Prepend(m);
        SetMatrix3D(m1);
    }
    else
    {
        Matrix m1(GetMatrix());
        m1.Prepend(m);
        SetMatrix(m1);
    }
}

// Puts a container between this object's node and its parent: the container takes over the transform, color
// transform, visibility, blend mode and scale9 grid, the old node keeps the content.
// @0x1425f1450
Render::TreeContainer* DisplayObjectBase::ConvertToTreeContainer()
{
    if (!pRenNode)
        GetRenderNode();

    TreeContainer* cont = static_cast<TreeContainer*>(pRenNode->GetParent());

    Ptr<TreeContainer> newnode = *GetRenderContext().CreateEntry<TreeContainer>();
    if (cont)
    {
        if (!pRenNode->IsMaskNode())
        {
            UPInt i = 0;
            for (UPInt n = cont->GetSize(); i < n; ++i)
            {
                TreeNode* nd = cont->GetAt(i);
                if (nd == pRenNode)
                    break;
            }
            cont->Remove(i, 1);
            cont->Insert(i, newnode.GetPtr());
        }
        else
        {
            cont->SetMaskNode(0);
            cont->SetMaskNode(newnode.GetPtr());
        }
    }
    if (Is3D())
    {
        newnode->SetMatrix3D(GetMatrix3D());
        Matrix4F m4;
        if (GetProjectionMatrix3D(&m4))
            newnode->SetProjectionMatrix3D(m4);
        Matrix3F m3;
        if (GetViewMatrix3D(&m3))
            newnode->SetViewMatrix3D(m3);
    }
    else
        newnode->SetMatrix(GetMatrix());
    pRenNode->SetMatrix(Matrix2F::Identity);

    newnode->SetCxform(GetCxform());
    pRenNode->SetCxform(Cxform::Identity);

    newnode->SetVisible(GetVisible());
    pRenNode->SetVisible(true);

    newnode->SetBlendMode(pRenNode->GetBlendMode());
    pRenNode->SetBlendMode(Render::Blend_None);

    RectF s9g = pRenNode->GetScale9Grid();
    if (s9g.x1 < s9g.x2 && s9g.y1 < s9g.y2)
    {
        newnode->SetScale9Grid(s9g);
        pRenNode->SetScale9Grid(RectF(0));
    }

    newnode->Add(pRenNode);
    pRenNode = newnode;
    return newnode;
}

// @0x1425f1910
CharacterHandle* DisplayObject::CreateCharacterHandle() const
{
    if (!pNameHandle)
    {
        MovieImpl* proot = GetMovieImpl();

        // An unloaded object only gets a temporary handle.
        if (IsUnloaded())
        {
            pNameHandle = *SF_HEAP_NEW(proot->GetMovieHeap())
                CharacterHandle(ASString(GetRootStringManager(proot->pASMovieRoot)->GetEmptyStringNode()), 0, 0);
            return pNameHandle;
        }

        ASString name(CreateNewInstanceName());
        pNameHandle = *SF_HEAP_NEW(proot->GetMovieHeap())
            CharacterHandle(name, pParent, const_cast<DisplayObject*>(this));
    }
    return pNameHandle;
}

// @0x1425f1ae0
ASString DisplayObject::CreateNewInstanceName() const
{
    return GetMovieImpl()->CreateNewInstanceName();
}

// @0x1425f1b00
void DisplayObjectBase::EnsureGeomDataCreated()
{
    if (!pGeomData)
    {
        GeomDataType geomData;
        SetGeomData(GetGeomData(geomData));
    }
}

// The movie of the nearest interactive object up the parent chain.
// @0x1425f1b80
MovieImpl* DisplayObjectBase::FindMovieImpl() const
{
    const DisplayObjectBase* dobj = this;
    while (dobj && !dobj->IsInteractiveObject())
        dobj = dobj->pParentChar;
    if (dobj)
        return dobj->GetMovieImpl();
    return 0;
}

// @0x1425f1bb0
DisplayObject* CharacterHandle::ForceResolveCharacter(MovieImpl* proot) const
{
    typedef DisplayObject* (*FindTargetFn)(ASMovieRootBase*, const ASString&);
    return (*(FindTargetFn**)proot->pASMovieRoot)[0x40 / 8](proot->pASMovieRoot, NamePath);
}

// @0x1425f1bd0
const char* DisplayObject::GetAbsolutePath(String* ppath) const
{
    if (HasAvmObject())
        return GetAvmObjImpl()->GetAbsolutePath(ppath);
    return "";
}

// The first blend mode up the parent chain that is more than a layer.
// @0x1425f1c00
Render::BlendMode DisplayObjectBase::GetActiveBlendMode() const
{
    Render::BlendMode blend = Render::Blend_None;
    const DisplayObjectBase* pchar = this;

    while (pchar)
    {
        blend = pchar->GetBlendMode();
        if (blend > Render::Blend_Layer)
            return blend;
        pchar = pchar->pParentChar;
    }
    // Return last blend mode.
    return blend;
}

// @0x1425f1c30
Double DisplayObjectBase::GetAlpha() const
{
    return GetCxform().M[0][3] * 100.f;
}

// @0x1425f1ca0
Render::BlendMode DisplayObjectBase::GetBlendMode() const
{
    if (GetRenderNode())
        return GetRenderNode()->GetBlendMode();
    return (Render::BlendMode)BlendMode;
}

// @0x1425f1d70
const Render::FilterSet* DisplayObjectBase::GetFilters() const
{
    if (GetRenderNode())
        return GetRenderNode()->GetFilters();
    return 0;
}

// @0x1425f1dd0
DisplayObjectBase::GeomDataType& DisplayObjectBase::GetGeomData(GeomDataType& geomData) const
{
    if (!pGeomData)
    {
        // The AS properties derived from the matrix.
        const Matrix& m     = GetMatrix();
        geomData.X          = int(m.Tx());
        geomData.Y          = int(m.Ty());
        geomData.XScale     = sqrt(Double(m.Sx()) * Double(m.Sx()) + Double(m.Shy()) * Double(m.Shy())) * 100;
        geomData.YScale     = sqrt(Double(m.Shx()) * Double(m.Shx()) + Double(m.Sy()) * Double(m.Sy())) * 100;
        geomData.Rotation   = atan2(Double(m.Shy()), Double(m.Sx())) * 180 / 3.1415926535897932384626433832795;
        geomData.OrigMatrix = GetMatrix();
    }
    else
        geomData = *pGeomData;
    return geomData;
}

// @0x1425f1f60
// MS2-FUNCTIONAL: frame layout (the exe keeps the bounds rect in a /GS-checked slot)
Double DisplayObjectBase::GetHeight() const
{
    RectF r = GetBounds(GetMatrix());
    return Render::TwipsToPixels(floor(Double(r.y2 - r.y1)));
}

// @0x1425f1fd0
void DisplayObjectBase::GetLevelMatrix(Matrix* pmat) const
{
    if (pParent)
    {
        pParent->GetLevelMatrix(pmat);
        pmat->Prepend(GetMatrix());
    }
    else
        *pmat = Matrix();
}

// @0x1425f2040
Log* DisplayObjectBase::GetLog() const
{
    MovieImpl* proot = FindMovieImpl();
    if (!G_IsFlagSet<MovieImpl::Flag_CachedLogFlag>(proot->Flags))
        proot->pCachedLog = proot->GetStateBag()->GetLog();
    return proot->pCachedLog;
}

// @0x1425f20e0
DisplayObject* DisplayObject::GetMask() const
{
    if (pMaskCharacter && !IsUsedAsMask())
        return pMaskCharacter;
    return 0;
}

// @0x1425f2110
DisplayObject* DisplayObject::GetMaskOwner() const
{
    if (pMaskCharacter && IsUsedAsMask())
        return pMaskCharacter;
    return 0;
}


// The mouse position in local coordinates, in pixels.
// MS2-FUNCTIONAL 0x1425f22e0: scheduling of the inlined SetNormalizedScreenCoords (as in sfr_gfx_01i HitTest)
// @0x1425f22e0
Double DisplayObject::GetMouseX() const
{
    PointF a = GetMovieImpl()->MouseLastPosition;
    PointF b(PointF::NoInit);
    GetMovieImpl()->SetNormalizedScreenCoords(a);
    TransformPointToLocal(&b, a, false);
    return Render::TwipsToPixels(floor(b.x + 0.5));
}

// MS2-FUNCTIONAL 0x1425f23e0: scheduling of the inlined SetNormalizedScreenCoords (as in sfr_gfx_01i HitTest)
// @0x1425f23e0
Double DisplayObject::GetMouseY() const
{
    PointF a = GetMovieImpl()->MouseLastPosition;
    PointF b(PointF::NoInit);
    GetMovieImpl()->SetNormalizedScreenCoords(a);
    TransformPointToLocal(&b, a, false);
    return Render::TwipsToPixels(floor(b.y + 0.5));
}

// @0x1425f24e0
ASString DisplayObject::GetName() const
{
    CharacterHandle* pnameHandle = GetCharacterHandle();
    if (pnameHandle)
        return pnameHandle->Name;
    return ASString(GetRootStringManager(GetMovieImpl()->pASMovieRoot)->GetEmptyStringNode());
}

// @0x1425f2540
ASString DisplayObject::GetOriginalName() const
{
    CharacterHandle* pnameHandle = GetCharacterHandle();
    if (pnameHandle)
        return pnameHandle->OriginalName;
    return GetName();
}

// @0x1425f2600
bool DisplayObjectBase::GetProjectionMatrix3D(Matrix4F* m, bool inherit) const
{
    if (pRenNode)
    {
        const Render::ProjectionMatrix3DState* state = pRenNode->GetState<Render::ProjectionMatrix3DState>();
        if (state)
        {
            *m = *state->GetProjectionMatrix3D();
            return true;
        }
    }
    if (!inherit || !pParent)
        return false;
    return pParentChar->GetProjectionMatrix3D(m, inherit);
}

// @0x1425f2760
Double DisplayObjectBase::GetRotation() const
{
    GeomDataType gd;
    return GetGeomData(gd).Rotation;
}

// @0x1425f27d0
RectF DisplayObjectBase::GetScale9Grid() const
{
    return GetRenderNode()->GetScale9Grid();
}

// Whether a clip button mode applies: the clip's AVM object takes button events.
static inline bool ActsAsButton(const InteractiveObject* pch)
{
    return pch->HasAvmObject() && pch->GetAvmIntObj()->ActsAsButton();
}

// The innermost button-mode sprite (or any sprite when testAll) containing pt, for a character whose shape
// is defined by pdef.
// @0x1425f2840
InteractiveObject* DisplayObjectBase::GetTopMostMouseEntityDef(CharacterDef* pdef, const PointF& pt, bool testAll,
                                                               const InteractiveObject* ignoreMC)
{
    if (!GetVisible())
        return 0;

    PointF p(PointF::NoInit);
    TransformPointToLocal(&p, pt);

    if (ClipDepth == 0 && pdef->DefPointTestLocal(p, 1, this))
    {
        // The mouse is inside the shape: the parent sprites in button mode get it.
        InteractiveObject* pparent = pParent;
        while (pparent && pparent->IsSprite())
        {
            Sprite* spr = static_cast<Sprite*>(pparent);
            if (testAll || ActsAsButton(pparent) ||
                (spr->GetHitAreaHolder() && ActsAsButton(spr->GetHitAreaHolder())))
            {
                if (!ignoreMC || ignoreMC != pparent)
                    return pparent;
            }
            pparent = pparent->pParent;
        }
    }
    return 0;
}

// @0x1425f2980
unsigned DisplayObjectBase::GetVersion() const
{
    return GetResourceMovieDef()->GetVersion();
}

// @0x1425f2a40
// MS2-FUNCTIONAL: frame layout (the exe keeps the bounds rect in a /GS-checked slot)
Double DisplayObjectBase::GetWidth() const
{
    RectF r = GetBounds(GetMatrix());
    return Render::TwipsToPixels(floor(Double(r.x2 - r.x1)));
}

// @0x1425f2ab0
void DisplayObjectBase::GetWorldCxform(Cxform* pcxform) const
{
    if (pParent)
    {
        pParentChar->GetWorldCxform(pcxform);
        pcxform->Prepend(GetCxform());
    }
    else
        *pcxform = GetCxform();
}

// @0x1425f2bb0
void DisplayObjectBase::GetWorldMatrix3D(Matrix3F* pmat) const
{
    if (pParent)
    {
        pParentChar->GetWorldMatrix3D(pmat);
        pmat->Prepend(GetMatrix3D());
    }
    else
        *pmat = GetMatrix3D();
}

// @0x1425f2c50
void DisplayObjectBase::GetWorldMatrix(Matrix* pmat) const
{
    if (pParent)
    {
        pParentChar->GetWorldMatrix(pmat);
        pmat->Prepend(GetMatrix());
    }
    else
        *pmat = GetMatrix();
}

// @0x1425f2cd0
Double DisplayObjectBase::GetX() const
{
    GeomDataType gd;
    return Render::TwipsToPixels(Double(GetGeomData(gd).X));
}

// @0x1425f2d40
Double DisplayObjectBase::GetXRotation() const
{
    GeomDataType gd;
    return GetGeomData(gd).XRotation;
}

// @0x1425f2db0
Double DisplayObjectBase::GetXScale() const
{
    GeomDataType gd;
    return GetGeomData(gd).XScale;
}

// @0x1425f2e20
Double DisplayObjectBase::GetY() const
{
    GeomDataType gd;
    return Render::TwipsToPixels(Double(GetGeomData(gd).Y));
}

// @0x1425f2e90
Double DisplayObjectBase::GetYRotation() const
{
    GeomDataType gd;
    return GetGeomData(gd).YRotation;
}

// @0x1425f2f00
Double DisplayObjectBase::GetYScale() const
{
    GeomDataType gd;
    return GetGeomData(gd).YScale;
}

// @0x1425f2f70
Double DisplayObjectBase::GetZ() const
{
    GeomDataType gd;
    return GetGeomData(gd).Z;
}

// @0x1425f2fe0
Double DisplayObjectBase::GetZScale() const
{
    GeomDataType gd;
    return GetGeomData(gd).ZScale;
}


// @0x1425f3050
Point3F DisplayObjectBase::GlobalToLocal3D(const PointF& ptIn) const
{
    PointF ptOut = GlobalToLocal(ptIn);
    return Point3F(ptOut.x, ptOut.y, 0);
}

// A stage point (twips) in local coordinates; the window position feeds the 3D screen-to-world mapping.
// MS2-FUNCTIONAL 0x1425f3150: scheduling of the inlined SetNormalizedScreenCoords loads (same operations)
// @0x1425f3150
PointF DisplayObjectBase::GlobalToLocal(const PointF& ptIn) const
{
    PointF     ptOut(PointF::NoInit);
    MovieImpl* proot = GetMovieImpl();
    if (proot)
    {
        float wx = (ptIn.x - proot->ViewOffsetX) / proot->ViewScaleX;
        float wy = (ptIn.y - proot->ViewOffsetY) / proot->ViewScaleY;
        proot->SetNormalizedScreenCoords(PointF(wx, wy));
        TransformPointToLocal(&ptOut, ptIn, false);
    }
    return ptOut;
}

// @0x1425f3230
bool DisplayObject::HasEventHandler(const EventId& id) const
{
    if (HasAvmObject())
        return GetAvmObjImpl()->HasEventHandler(id);
    return false;
}

// The Flash player ignores the perspective of an object whose 3D parent has none of its own.
// @0x1425f3250
bool IgnoreProjection(DisplayObjectBase* pdispObj)
{
    return pdispObj->pParent && pdispObj->pParentChar->Is3D() && !pdispObj->pParentChar->pPerspectiveData;
}

// @0x1425f32c0
void DisplayObjectBase::InvalidateHitResult() const
{
    const_cast<DisplayObjectBase*>(this)->Flags &= ~(Mask_HitTestNegative | Mask_HitTestPositive);
}

// @0x1425f32d0
bool DisplayObjectBase::Is3D(bool inherit) const
{
    bool b3D = Is3D();
    if (inherit)
    {
        if (b3D)
            return true;
        if (pParent)
            return pParentChar->Is3D(inherit);
    }
    return b3D;
}

// @0x1425f3350
bool DisplayObjectBase::IsAncestor(DisplayObjectBase* ch) const
{
    for (DisplayObjectBase* p = ch->pParentChar; p; p = p->pParentChar)
    {
        if (p == this)
            return true;
    }
    return false;
}


// The movie viewport as Movie::GetViewport fills it (GFx::Viewport: the render viewport plus scale and aspect).
struct MovieViewport : public Render::Viewport
{
    float Scale;
    float AspectRatio;

    MovieViewport() : Scale(1.0f), AspectRatio(1.0f) {}
};

// Movie::GetViewport (MovieImpl vftable +0x60).
static inline void GetMovieViewport(MovieImpl* pmovie, MovieViewport* pviewport)
{
    typedef void (*GetViewportFn)(MovieImpl*, MovieViewport*);
    (*(GetViewportFn**)pmovie)[0x60 / 8](pmovie, pviewport);
}

// A local 3D point (twips) on the stage (twips), projected through the inherited view and perspective.
// @0x1425f3430
PointF DisplayObjectBase::Local3DToGlobal(const Point3F& ptIn) const
{
    if (Is3D(true))
    {
        Matrix3F view;
        GetViewMatrix3D(&view, true);

        Matrix4F proj;
        GetProjectionMatrix3D(&proj, true);

        Matrix3F world;
        GetWorldMatrix3D(&world);

        Matrix4F mvp(Matrix4F(proj, view), world);
        Point3F  p1 = mvp.TransformHomogeneous(ptIn);

        MovieViewport vp;
        GetMovieViewport(pASRoot->GetMovieImpl(), &vp);

        // To window pixels.
        p1.x = (p1.x + 1.0f) * float(vp.Width) * 0.5f;
        p1.y = (1.0f - p1.y) * float(vp.Height) * 0.5f;

        // To stage twips.
        const MovieImpl* pmovie = pASRoot ? pASRoot->GetMovieImpl() : 0;
        if (pmovie)
        {
            p1.x = Render::PixelsToTwips(pmovie->ViewOffsetX + p1.x * pmovie->ViewScaleX);
            p1.y = Render::PixelsToTwips(pmovie->ViewOffsetY + p1.y * pmovie->ViewScaleY);
        }
        return PointF(p1.x, p1.y);
    }

    Matrix world;
    GetWorldMatrix(&world);
    PointF p(ptIn.x, ptIn.y);
    world.Transform(&p.x, &p.y);
    return p;
}


// @0x1425f39b0
// MS2-FUNCTIONAL: the exe inlines the base OnEventLoad as a leaf, ours calls it
void DisplayObject::OnEventLoad()
{
    DisplayObjectBase::OnEventLoad();
    if (HasAvmObject())
        GetAvmObjImpl()->OnEventLoad();
}

// @0x1425f39e0
void DisplayObject::OnEventUnload()
{
    DisplayObjectBase::OnEventUnload();
    // A released handle no longer finds this object.
    if (pNameHandle)
        pNameHandle->ReleaseCharacter();
    if (HasAvmObject())
        GetAvmObjImpl()->OnEventUnload();
}

// @0x1425f3ac0
void DisplayObjectBase::OnEventUnload()
{
    SetUnloading();
    if (IsTopmostLevelFlagSet())
        FindMovieImpl()->RemoveTopmostLevelCharacter(this);
    if (!IsUnloaded())
    {
        OnEvent(EventId(EventId::Event_Unload));
        SetUnloaded();
    }
}

// Puts the node back under its display list parent with the transform it had before SetIndirectTransform.
// @0x1425f3b80
void DisplayObjectBase::RemoveIndirectTransform()
{
    if (HasIndirectTransform())
    {
        Ptr<TreeNode> renderNode = GetRenderNode();

        if (!pIndXFormData->IsOrig3D)
        {
            renderNode->Clear3D();
            renderNode->SetMatrix(*(Matrix2F*)(void*)&pIndXFormData->OrigTransformMatrix);
        }
        else
            renderNode->SetMatrix3D(pIndXFormData->OrigTransformMatrix);
        delete pIndXFormData;
        pIndXFormData = 0;
        Flags &= ~Mask_IndirectTransform;

        MovieImpl::IndirectTransPair p = GetMovieImpl()->RemoveIndirectTransformPair(this);
        if (p.OriginalParent)
        {
            DisplayList& dl  = p.OriginalParent->mDisplayList;
            SPInt        idx = dl.FindDisplayIndex(this);
            if (idx != -1)
                dl.InsertIntoRenderTree(p.OriginalParent, idx);
        }
    }
}

// A timeline mask that becomes a regular object: its node goes back into the parent's render tree unmasked.
// @0x1425f3ca0
void DisplayObject::ResetClipDepth()
{
    if (ClipDepth != 0)
    {
        DisplayObjContainer* parent = 0;
        if (pParent && pParent->IsDisplayObjContainer())
            parent = static_cast<DisplayObjContainer*>(pParent);
        if (parent)
        {
            DisplayList& dl  = parent->mDisplayList;
            UPInt        idx = dl.FindDisplayIndex(this);
            dl.RemoveFromRenderTree(parent, idx);
            ClipDepth = 0;
            dl.InsertIntoRenderTree(parent, idx);
        }
        else
            ClipDepth = 0;
    }
}

// @0x1425f3d60
void CharacterHandle::ResetName(ASStringManager* psm)
{
    Name     = ASString(psm->GetEmptyStringNode());
    NamePath = Name;
}

// @0x1425f3dc0
DisplayObject* CharacterHandle::ResolveCharacter(MovieImpl* proot) const
{
    if (pCharacter)
        return pCharacter;
    return ForceResolveCharacter(proot);
}

// Timeline moves apply again (accept) or stop for good; the AS view of the transform is frozen first.
// @0x1425f3de0
void DisplayObject::SetAcceptAnimMoves(bool accept)
{
    if (!pGeomData)
    {
        GeomDataType geomData;
        SetGeomData(GetGeomData(geomData));
    }
    if (accept)
        Flags |= Mask_AcceptAnimMoves;
    else
        Flags &= ~Mask_AcceptAnimMoves;

    // The movie's continueAnimation flag, cached here.
    if (GetMovieImpl()->Flags & MovieImpl::Flag_ContinueAnimation)
        Flags |= Mask_ContinueAnimation;
    else
        Flags &= ~Mask_ContinueAnimation;

    if ((GetMovieImpl()->Flags & MovieImpl::Flag_ContinueAnimation) && accept)
    {
        // The timeline owns the transform again: the AS properties are read back from the matrix.
        delete pGeomData;
        pGeomData = 0;
    }
    SetDirtyFlag();
}


// Movie::AcceptAnimMovesWith3D (MovieImpl vftable +0x218): 3D properties keep the timeline transform.
static inline bool AcceptAnimMovesWith3D(MovieImpl* pmovie)
{
    typedef bool (*AcceptAnimMovesWith3DFn)(MovieImpl*);
    return (*(AcceptAnimMovesWith3DFn**)pmovie)[0x218 / 8](pmovie);
}

static const Double MATH_PI = 3.1415926535897932384626433832795;

// _alpha, in percent.
// @0x1425f3f00
void DisplayObjectBase::SetAlpha(Double alpha)
{
    if (NumberUtil::IsNaN(alpha))
        return;

    Cxform cx  = GetCxform();
    cx.M[0][3] = float(alpha / 100.);
    SetCxform(cx);
    SetAcceptAnimMoves(0);
}

// @0x1425f4010
void DisplayObjectBase::SetBlendMode(Render::BlendMode blend)
{
    GetRenderNode()->SetBlendMode(blend == Render::Blend_Normal ? Render::Blend_None : blend);
    BlendMode = (UByte)blend;
}

// @0x1425f4090
void DisplayObjectBase::SetDirtyFlag()
{
}

// The field of view of the object's own perspective, in degrees.
// @0x1425f40a0
void DisplayObjectBase::SetFOV(Double fovdeg)
{
    if (NumberUtil::IsNaN(fovdeg))
        return;
    if (NumberUtil::IsNEGATIVE_INFINITY(fovdeg) || NumberUtil::IsPOSITIVE_INFINITY(fovdeg))
        fovdeg = 0;

    if (!pPerspectiveData)
        pPerspectiveData = SF_HEAP_AUTO_NEW(this) PerspectiveDataType;

    if (pPerspectiveData->FieldOfView != fovdeg)
    {
        pPerspectiveData->FieldOfView = fovdeg;
        DisplayObjectBase::UpdateViewAndPerspective();
    }
}

// @0x1425f41b0
void DisplayObjectBase::SetFilters(const Render::FilterSet* filters)
{
    if (GetRenderNode())
        GetRenderNode()->SetFilters(filters);
}

// The focal length of the object's own perspective, in twips.
// @0x1425f41f0
void DisplayObjectBase::SetFocalLength(Double focalLength)
{
    if (NumberUtil::IsNaN(focalLength))
        return;
    if (NumberUtil::IsNEGATIVE_INFINITY(focalLength) || NumberUtil::IsPOSITIVE_INFINITY(focalLength))
        focalLength = 0;

    if (!pPerspectiveData)
        pPerspectiveData = SF_HEAP_AUTO_NEW(this) PerspectiveDataType;

    if (pPerspectiveData->FocalLength != focalLength)
    {
        pPerspectiveData->FocalLength = focalLength;
        DisplayObjectBase::UpdateViewAndPerspective();
    }
}

// @0x1425f4300
void DisplayObjectBase::SetGeomData(const GeomDataType& gd)
{
    if (pGeomData)
        *pGeomData = gd;
    else
        pGeomData = SF_HEAP_AUTO_NEW(this) GeomDataType(gd);
}

// _height: scales along the local y axis (with the rotation taken out) so that the bounds get the new height.
// @0x1425f4460
void DisplayObjectBase::SetHeight(Double height)
{
    if (NumberUtil::IsNaN(height) || NumberUtil::IsNEGATIVE_INFINITY(height))
        return;
    if (NumberUtil::IsPOSITIVE_INFINITY(height))
        height = 0;

    SetAcceptAnimMoves(0);

    Matrix        m   = pGeomData->OrigMatrix;
    const Matrix& chm = GetMatrix();
    m.Tx()            = chm.Tx();
    m.Ty()            = chm.Ty();

    Matrix im = m;
    im.AppendRotation(float(-m.GetRotationDouble() + pGeomData->Rotation * MATH_PI / 180.));

    float oldHeight  = GetBounds(im).Height();
    float newHeight  = float(Render::PixelsToTwips(height));
    float multiplier = (fabsf(oldHeight) > 1e-6f) ? (newHeight / oldHeight) : 0.0f;

    Double origYScale = m.GetYScaleDouble();
    Double newYScale  = origYScale * multiplier * 100;
    pGeomData->YScale = newYScale;
    if (origYScale == 0)
    {
        newYScale  = 0;
        origYScale = 1;
    }

    ASCharacter_MatrixScaleAndRotate2x2(m, float(fabs(pGeomData->XScale / (m.GetXScaleDouble() * 100.))),
                                        float(fabs(newYScale / (origYScale * 100.))),
                                        float(-m.GetRotationDouble() + pGeomData->Rotation * MATH_PI / 180.));

    pGeomData->XScale = fabs(pGeomData->XScale);
    pGeomData->YScale = fabs(pGeomData->YScale);

    if (m.IsValid())
        SetMatrix(m);
}

// _width: the x axis counterpart of SetHeight.
// @0x1425f6130
void DisplayObjectBase::SetWidth(Double width)
{
    if (NumberUtil::IsNaN(width) || NumberUtil::IsNEGATIVE_INFINITY(width))
        return;
    if (NumberUtil::IsPOSITIVE_INFINITY(width))
        width = 0;

    SetAcceptAnimMoves(0);

    Matrix        m   = pGeomData->OrigMatrix;
    const Matrix& chm = GetMatrix();
    m.Tx()            = chm.Tx();
    m.Ty()            = chm.Ty();

    Matrix im = m;
    im.AppendRotation(float(-m.GetRotationDouble() + pGeomData->Rotation * MATH_PI / 180.));

    float oldWidth   = GetBounds(im).Width();
    float newWidth   = float(Render::PixelsToTwips(width));
    float multiplier = (fabsf(oldWidth) > 1e-6f) ? (newWidth / oldWidth) : 0.0f;

    Double origXScale = m.GetXScaleDouble();
    Double newXScale  = origXScale * multiplier * 100;
    pGeomData->XScale = newXScale;
    if (origXScale == 0)
    {
        newXScale  = 0;
        origXScale = 1;
    }

    ASCharacter_MatrixScaleAndRotate2x2(m, float(fabs(newXScale / (origXScale * 100.))),
                                        float(fabs(pGeomData->YScale / (m.GetYScaleDouble() * 100.))),
                                        float(-m.GetRotationDouble() + pGeomData->Rotation * MATH_PI / 180.));

    pGeomData->XScale = fabs(pGeomData->XScale);
    pGeomData->YScale = fabs(pGeomData->YScale);

    if (m.IsValid())
        SetMatrix(m);
}

// _x, in pixels.
// @0x1425f64c0
// MS2-FUNCTIONAL: the exe inlines the matrix validity check ours calls
void DisplayObjectBase::SetX(Double x)
{
    if (NumberUtil::IsNaN(x))
        return;
    if (NumberUtil::IsNEGATIVE_INFINITY(x) || NumberUtil::IsPOSITIVE_INFINITY(x))
        x = 0;
    SetAcceptAnimMoves(0);

    Matrix m      = GetMatrix();
    pGeomData->X  = int(floor(Render::PixelsToTwips(x)));
    m.Tx()        = (float)pGeomData->X;
    if (m.IsValid())
        SetMatrix(m);
}

// _y, in pixels.
// @0x1425f69f0
// MS2-FUNCTIONAL: the exe inlines the matrix validity check ours calls
void DisplayObjectBase::SetY(Double y)
{
    if (NumberUtil::IsNaN(y))
        return;
    if (NumberUtil::IsNEGATIVE_INFINITY(y) || NumberUtil::IsPOSITIVE_INFINITY(y))
        y = 0;
    SetAcceptAnimMoves(0);

    Matrix m      = GetMatrix();
    pGeomData->Y  = int(floor(Render::PixelsToTwips(y)));
    m.Ty()        = (float)pGeomData->Y;
    if (m.IsValid())
        SetMatrix(m);
}

// z, in twips.
// @0x1425f6f20
void DisplayObjectBase::SetZ(Double z)
{
    if (NumberUtil::IsNaN(z))
        return;
    if (NumberUtil::IsNEGATIVE_INFINITY(z) || NumberUtil::IsPOSITIVE_INFINITY(z))
        z = 0;

    if (pASRoot && AcceptAnimMovesWith3D(pASRoot->GetMovieImpl()))
        EnsureGeomDataCreated();
    else
        SetAcceptAnimMoves(0);

    pGeomData->Z = z;
    UpdateTransform3D();
}

// _xscale, in percent.
// @0x1425f6760
void DisplayObjectBase::SetXScale(Double xscale)
{
    if (NumberUtil::IsNaN(xscale) || NumberUtil::IsNEGATIVE_INFINITY(xscale) ||
        NumberUtil::IsPOSITIVE_INFINITY(xscale))
        return;
    SetAcceptAnimMoves(0);

    pGeomData->XScale = xscale;
    if (Is3D())
        UpdateTransform3D();
    else
    {
        const Matrix& chm = GetMatrix();
        Matrix        m   = pGeomData->OrigMatrix;
        m.Tx()            = chm.Tx();
        m.Ty()            = chm.Ty();

        Double origXScale = m.GetXScaleDouble();
        if (origXScale == 0 || xscale > 1E+16)
        {
            xscale     = 0;
            origXScale = 1;
        }

        ASCharacter_MatrixScaleAndRotate2x2(m, float(xscale / (origXScale * 100.)),
                                            float(pGeomData->YScale / (m.GetYScaleDouble() * 100.)),
                                            float(-m.GetRotationDouble() + pGeomData->Rotation * MATH_PI / 180.));
        if (m.IsValid())
            SetMatrix(m);
    }
}

// _yscale, in percent.
// @0x1425f6c90
void DisplayObjectBase::SetYScale(Double yscale)
{
    if (NumberUtil::IsNaN(yscale) || NumberUtil::IsNEGATIVE_INFINITY(yscale) ||
        NumberUtil::IsPOSITIVE_INFINITY(yscale))
        return;
    SetAcceptAnimMoves(0);

    pGeomData->YScale = yscale;
    if (Is3D())
        UpdateTransform3D();
    else
    {
        const Matrix& chm = GetMatrix();
        Matrix        m   = pGeomData->OrigMatrix;
        m.Tx()            = chm.Tx();
        m.Ty()            = chm.Ty();

        Double origYScale = m.GetYScaleDouble();
        if (origYScale == 0 || yscale > 1E+16)
        {
            yscale     = 0;
            origYScale = 1;
        }

        ASCharacter_MatrixScaleAndRotate2x2(m, float(pGeomData->XScale / (m.GetXScaleDouble() * 100.)),
                                            float(yscale / (origYScale * 100.)),
                                            float(-m.GetRotationDouble() + pGeomData->Rotation * MATH_PI / 180.));
        if (m.IsValid())
            SetMatrix(m);
    }
}

// z scale, in percent.
// @0x1425f6fe0
void DisplayObjectBase::SetZScale(Double zscale)
{
    if (NumberUtil::IsNaN(zscale) || NumberUtil::IsNEGATIVE_INFINITY(zscale) ||
        NumberUtil::IsPOSITIVE_INFINITY(zscale))
        return;

    if (pASRoot && AcceptAnimMovesWith3D(pASRoot->GetMovieImpl()))
        EnsureGeomDataCreated();
    else
        SetAcceptAnimMoves(0);

    pGeomData->ZScale = zscale;
    UpdateTransform3D();
}

// The angle wrapped into -180..180 degrees.
static inline Double WrapDegrees(Double rotation)
{
    Double r = fmod(rotation, 360.);
    if (r > 180)
        r -= 360;
    else if (r < -180)
        r += 360;
    return r;
}

// _rotation, in degrees.
// @0x1425f57a0
void DisplayObjectBase::SetRotation(Double rotation)
{
    if (NumberUtil::IsNaN(rotation))
        return;
    SetAcceptAnimMoves(0);

    Double r            = WrapDegrees(rotation);
    pGeomData->Rotation = r;

    if (Is3D())
        UpdateTransform3D();
    else
    {
        const Matrix& chm = GetMatrix();
        Matrix        m   = pGeomData->OrigMatrix;
        m.Tx()            = chm.Tx();
        m.Ty()            = chm.Ty();

        Double origRotation = m.GetRotationDouble();

        // Rotate the old angle out and the new one in.
        ASCharacter_MatrixScaleAndRotate2x2(m, float(pGeomData->XScale / (m.GetXScaleDouble() * 100.)),
                                            float(pGeomData->YScale / (m.GetYScaleDouble() * 100.)),
                                            float(-origRotation + r * MATH_PI / 180.));
        if (m.IsValid())
            SetMatrix(m);
    }
}

// rotationX, in degrees.
// @0x1425f6690
void DisplayObjectBase::SetXRotation(Double rotation)
{
    if (NumberUtil::IsNaN(rotation))
        return;

    if (pASRoot && AcceptAnimMovesWith3D(pASRoot->GetMovieImpl()))
        EnsureGeomDataCreated();
    else
        SetAcceptAnimMoves(0);

    pGeomData->XRotation = WrapDegrees(rotation);
    UpdateTransform3D();
}

// rotationY, in degrees.
// @0x1425f6bc0
void DisplayObjectBase::SetYRotation(Double rotation)
{
    if (NumberUtil::IsNaN(rotation))
        return;

    if (pASRoot && AcceptAnimMovesWith3D(pASRoot->GetMovieImpl()))
        EnsureGeomDataCreated();
    else
        SetAcceptAnimMoves(0);

    pGeomData->YRotation = WrapDegrees(rotation);
    UpdateTransform3D();
}


// Detaches the render node from the display list parent's container so another node can hold it (a mask); the
// display list keeps the object. Returns the detached node, null when newParent lies under it.
// @0x1425f4800
Ptr<TreeNode> DisplayObjectBase::SetIndirectTransform(TreeNode* newParent)
{
    Ptr<TreeNode>  renderNode    = GetRenderNode();
    TreeContainer* oldParentNode = static_cast<TreeContainer*>(renderNode->GetParent());

    // A node cannot hold one of its ancestors.
    for (TreeNode* c = newParent; c; c = c->GetParent())
    {
        if (c == renderNode)
            return 0;
    }

    DisplayObjContainer* parent = 0;
    if (pParent && pParent->IsDisplayObjContainer())
        parent = static_cast<DisplayObjContainer*>(pParent);
    if (parent)
    {
        DisplayList& dl  = parent->mDisplayList;
        UPInt        idx = dl.FindDisplayIndex(this);
        dl.RemoveFromRenderTree(parent, idx);
    }

    GetMovieImpl()->AddIndirectTransformPair(parent, oldParentNode, this);

    if (!pIndXFormData)
        pIndXFormData = SF_HEAP_AUTO_NEW(this) IndirectTransformDataType;
    pIndXFormData->OrigTransformMatrix = renderNode->M3D();
    pIndXFormData->IsOrig3D            = renderNode->Is3D();
    Flags |= Mask_IndirectTransform;
    return renderNode;
}

// setMask: pmaskSprite's node becomes the mask node of this object's node (null removes the mask).
// @0x1425f4a10
void DisplayObject::SetMask(DisplayObject* pmaskSprite)
{
    Ptr<TreeNode> renNode = GetRenderNode();

    // setMask overrides the timeline masking.
    ResetClipDepth();
    if (pmaskSprite)
    {
        // A mask and a scrollRect do not go together.
        if (pScrollRect)
            SetScrollRect(0);
        pmaskSprite->ResetClipDepth();
    }

    DisplayObject* poldMask = GetMask();
    if (poldMask)
    {
        poldMask->SetMaskOwner(0);
        renNode->SetMaskNode(0);
        // The old mask goes back to its place in the render tree.
        poldMask->RemoveIndirectTransform();
    }

    // The masked object cannot be a mask itself.
    DisplayObject* poldOwner = GetMaskOwner();
    if (poldOwner)
        poldOwner->SetMask(0);
    if (pmaskSprite && pmaskSprite->GetMaskOwner())
        pmaskSprite->GetMaskOwner()->SetMask(0);

    if (pMaskCharacter && !IsUsedAsMask())
        pMaskCharacter->Release();

    Ptr<TreeNode> maskNode;
    if (pmaskSprite)
        maskNode = pmaskSprite->SetIndirectTransform(renNode);

    renNode->SetMaskNode(maskNode);
    Flags &= ~Mask_UsedAsMask;

    if (maskNode)
    {
        pMaskCharacter = pmaskSprite;
        if (pmaskSprite)
            pmaskSprite->AddRef();
        if (pmaskSprite)
            pmaskSprite->SetMaskOwner(this);
    }
    else
        pMaskCharacter = 0;

    SetDirtyFlag();
}

// @0x1425f4d00
void DisplayObject::SetMaskOwner(DisplayObject* pmaskOwner)
{
    if (GetMask())
        SetMask(0);

    if (pmaskOwner != 0)
        Flags |= Mask_UsedAsMask;
    else
        Flags &= ~Mask_UsedAsMask;
    pMaskCharacter = pmaskOwner;
}


// ---------------------------------------------------------------------------------------------------------------------
// The node transform. While an indirect transform (mask, topmost level) or a scrollRect holds the node, the matrix set
// is the one to restore later; the scrollRect shifts the node by the scroll and moves its mask shape back.

// @0x1425f4fb0
void DisplayObjectBase::SetMatrix3D(const Matrix3F& m)
{
    if (!pIndXFormData)
        GetRenderNode()->SetMatrix3D(m);
    else
    {
        pIndXFormData->OrigTransformMatrix = m;
        pIndXFormData->IsOrig3D            = true;
        GetRenderNode()->GetWritableData(Render::Change_Matrix);
    }
}

// @0x1425f4d70
// MS2-FUNCTIONAL: the exe keeps the matrix temporaries 16-byte aligned (movaps), frame layout differs
void DisplayObject::SetMatrix3D(const Matrix3F& m)
{
    if (!pScrollRect)
    {
        DisplayObjectBase::SetMatrix3D(m);
        return;
    }

    pScrollRect->OrigTransformMatrix = m;
    pScrollRect->IsOrig3D            = true;

    Matrix3F m1(pScrollRect->OrigTransformMatrix);
    m1.Prepend(Matrix3F::Translation(float(-pScrollRect->Rectangle.x1), float(-pScrollRect->Rectangle.y1), 0));
    GetRenderNode()->SetMatrix3D(m1);

    Matrix3F mm;
    mm.Prepend(Matrix3F::Translation(float(pScrollRect->Rectangle.x1), float(pScrollRect->Rectangle.y1), 0));
    pScrollRect->Mask->GetTreeNode()->SetMatrix3D(mm);
}

// 4.1.18 leaves IsOrig3D as it was.
// @0x1425f5280
void DisplayObjectBase::SetMatrix(const Matrix& m)
{
    if (!pIndXFormData)
        GetRenderNode()->SetMatrix(m);
    else
    {
        pIndXFormData->OrigTransformMatrix = Matrix3F(m);
        GetRenderNode()->GetWritableData(Render::Change_Matrix);
    }
}

// @0x1425f5010
// MS2-FUNCTIONAL: the exe keeps the matrix temporaries 16-byte aligned (movaps), frame layout differs
void DisplayObject::SetMatrix(const Matrix& m)
{
    if (!pScrollRect)
    {
        DisplayObjectBase::SetMatrix(m);
        return;
    }

    pScrollRect->OrigTransformMatrix = Matrix3F(m);

    Matrix m1(pScrollRect->OrigTransformMatrix);
    m1.PrependTranslation(float(-pScrollRect->Rectangle.x1), float(-pScrollRect->Rectangle.y1));
    GetRenderNode()->SetMatrix(m1);

    Matrix mm;
    mm.PrependTranslation(float(pScrollRect->Rectangle.x1), float(pScrollRect->Rectangle.y1));
    pScrollRect->Mask->GetTreeNode()->SetMatrix(mm);
}

// ---------------------------------------------------------------------------------------------------------------------
// Names

// @0x1425f52f0
void DisplayObject::SetName(const ASString& name)
{
    if (name.GetSize() != 0)
        Flags &= ~Mask_InstanceBasedName;

    if (pNameHandle)
        pNameHandle->ChangeName(name, pParent);
    else
        pNameHandle = *SF_HEAP_AUTO_NEW(this) CharacterHandle(name, pParent, this);
}

// @0x1425f54d0
void DisplayObject::SetOriginalName(const ASString& name)
{
    SetName(name);
    CharacterHandle* phandle = GetCharacterHandle();
    if (phandle)
        phandle->OriginalName = name;
}

// ---------------------------------------------------------------------------------------------------------------------
// Perspective

// The center of projection of the object's own perspective, in stage twips.
// @0x1425f5530
void DisplayObjectBase::SetProjectionCenter(PointF projCenter)
{
    if (NumberUtil::IsNaN(projCenter.x) || NumberUtil::IsNaN(projCenter.y))
        return;
    if (NumberUtil::IsNEGATIVE_INFINITY(projCenter.x) || NumberUtil::IsPOSITIVE_INFINITY(projCenter.x))
        projCenter.x = 0;
    if (NumberUtil::IsNEGATIVE_INFINITY(projCenter.y) || NumberUtil::IsPOSITIVE_INFINITY(projCenter.y))
        projCenter.y = 0;

    if (!pPerspectiveData)
        pPerspectiveData = SF_HEAP_AUTO_NEW(this) PerspectiveDataType;

    if (pPerspectiveData->ProjectionCenter != projCenter)
    {
        pPerspectiveData->ProjectionCenter = PointF(projCenter.x, projCenter.y);
        DisplayObjectBase::UpdateViewAndPerspective();
    }
}

// The stage (_level0) also carries its projection on the render root and the topmost root.
// @0x1425f56c0
void DisplayObjectBase::SetProjectionMatrix3D(const Matrix4F& m)
{
    // A child of a 3D parent without a perspective of its own keeps the parent's, unless it already had one.
    bool hasProjMat = pRenNode && pRenNode->HasProjectionMatrix3D();
    if (IgnoreProjection(this) && !hasProjMat)
        return;

    GetRenderNode()->SetProjectionMatrix3D(m);

    MovieImpl* pmovie = GetMovieImpl();
    if (pmovie && pmovie->pMovieLevels[0].pSprite == this)
    {
        pmovie->pRenderRoot->SetProjectionMatrix3D(m);
        pmovie->pTopMostRoot->SetProjectionMatrix3D(m);
    }
}

// The view matrix is kept as set (for the hit tests); the node gets it with the viewport scale and offset undone.
// @0x1425f5e70
// MS2-FUNCTIONAL: the exe keeps the matrix temporaries 16-byte aligned (movaps), frame layout differs
void DisplayObjectBase::SetViewMatrix3D(const Matrix3F& m)
{
    bool hasViewMat = pRenNode && pRenNode->HasViewMatrix3D();
    if (IgnoreProjection(this) && !hasViewMat)
        return;

    if (!pPerspectiveData)
        pPerspectiveData = SF_HEAP_AUTO_NEW(this) PerspectiveDataType;
    pPerspectiveData->ViewMatrix3D = m;

    MovieImpl* pmovie = GetMovieImpl();
    Matrix3F viewportInv(Matrix3F::Translation(pmovie->VisibleFrameRect.x1, pmovie->VisibleFrameRect.y1, 0),
                         Matrix3F::Scaling(1.0f / (pmovie->ViewportWidth / pmovie->VisibleFrameRect.Width()),
                                           1.0f / (pmovie->ViewportHeight / pmovie->VisibleFrameRect.Height()), 1.0f));
    Matrix3F view(m, viewportInv);

    GetRenderNode()->SetViewMatrix3D(view);

    if (pmovie && pmovie->pMovieLevels[0].pSprite == this)
    {
        pmovie->pRenderRoot->SetViewMatrix3D(view);
        pmovie->pTopMostRoot->SetViewMatrix3D(view);
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// Node state

// @0x1425f5a50
void DisplayObjectBase::SetScale9Grid(const RectF& grid)
{
    GetRenderNode()->SetScale9Grid(grid);
}

// @0x1425f60e0
void DisplayObjectBase::SetVisibleFlag(bool v)
{
    if (v)
    {
        Flags |= Mask_Visible;
        if (pRenNode)
            pRenNode->SetVisible(v);
    }
    else
    {
        Flags &= ~Mask_Visible;
        GetRenderNode()->SetVisible(false);
    }
}

// scrollRect: the node is clipped by a rectangle mask shape (drawn at the origin) and shifted by the scroll; a null
// rectangle removes it. Masks (setMask) and indirect transforms do not combine with it.
// @0x1425f5a70
void DisplayObject::SetScrollRect(const Render::RectD* r)
{
    if (GetMask())
        SetMask(0);
    if (HasIndirectTransform())
        return;

    TreeNode* renNode = GetRenderNode();
    if (pScrollRect)
    {
        // The previous scrollRect's mask goes, the node gets its own matrix back.
        renNode->SetMaskNode(0);
        if (!pScrollRect->IsOrig3D)
        {
            Matrix m = *(Matrix*)(void*)&pScrollRect->OrigTransformMatrix;
            renNode->SetMatrix(m);
        }
        else
            renNode->SetMatrix3D(pScrollRect->OrigTransformMatrix);
    }

    if (!r)
    {
        delete pScrollRect;
        pScrollRect = 0;
        return;
    }

    if (renNode->HasMask())
        renNode->SetMaskNode(0);
    if (!pScrollRect)
        pScrollRect = SF_HEAP_AUTO_NEW(this) ScrollRectInfo;
    pScrollRect->Rectangle           = *r;
    pScrollRect->OrigTransformMatrix = renNode->M3D();
    pScrollRect->IsOrig3D            = renNode->Is3D();

    // The mask: a white rectangle the size of the scroll window.
    pScrollRect->Mask = *GetMovieImpl()->CreateDrawingContext();
    pScrollRect->Mask->BeginSolidFill(0xFFFFFFFF);
    float w = (float)r->Width(), h = (float)r->Height();
    pScrollRect->Mask->MoveTo(0, 0);
    pScrollRect->Mask->LineTo(w, 0);
    pScrollRect->Mask->LineTo(w, h);
    pScrollRect->Mask->LineTo(0, h);
    pScrollRect->Mask->EndFill();
    pScrollRect->Mask->UpdateRenderNode();

    if (!pScrollRect->IsOrig3D)
        SetMatrix(renNode->M2D());
    else
        SetMatrix3D(renNode->M3D());

    renNode->SetMaskNode(pScrollRect->Mask->GetTreeNode());
}

// ---------------------------------------------------------------------------------------------------------------------
// Points and transforms

// The movie's ScreenToWorld (+0x130), which un-projects the normalized mouse position for the 3D hit tests.
static inline Render::ScreenToWorld& GetScreenToWorld(MovieImpl* pmovie)
{
    return *(Render::ScreenToWorld*)(void*)&pmovie->ScreenToWorldSx;
}

// A stage point (twips) in the object's space: through the inverse of the 2D transforms, or for 3D objects by
// un-projecting the mouse position onto the object's plane. ptInParentSpace: pt is in the parent's space (the
// recursive hit tests), mat replacing the object's own matrix.
// @0x1425f70a0
void DisplayObjectBase::TransformPointToLocal(PointF* p, const PointF& pt, bool ptInParentSpace,
                                              const Matrix2F* mat) const
{
    bool b3D = ptInParentSpace ? Is3D() : Is3D(true);
    if (!b3D)
    {
        if (ptInParentSpace)
        {
            if (mat)
                mat->TransformByInverse(p, pt);
            else
                GetMatrix().TransformByInverse(p, pt);
        }
        else
        {
            Matrix2F worldMat;
            GetWorldMatrix(&worldMat);
            worldMat.TransformByInverse(p, pt);
        }
    }
    else
    {
        Matrix3F view;
        Matrix4F proj;
        Matrix3F world;
        GetWorldMatrix3D(&world);
        Render::ScreenToWorld& stw = GetScreenToWorld(GetMovieImpl());

        if (GetProjectionMatrix3D(&proj, true))
            stw.SetProjection(proj);
        if (GetViewMatrix3D(&view, true))
            stw.SetView(view);
        stw.SetWorld(world);
        stw.GetWorldPoint(p);
    }
}

// The same for a clip with a scrollRect: the point shifted by the scroll, false outside the scroll window.
// @0x1425f74f0
bool DisplayObject::TransformPointToLocalAndCheckBounds(PointF* p, const PointF& pt, bool ptInParentSpace,
                                                        const Matrix2F* mat) const
{
    if (pScrollRect)
    {
        PointF localPt2(PointF::NoInit);
        TransformPointToLocal(&localPt2, pt, ptInParentSpace, mat);

        p->SetPoint(localPt2.x, localPt2.y);
        PointF scroll((float)pScrollRect->Rectangle.x1, (float)pScrollRect->Rectangle.y1);
        p->x += scroll.x;
        p->y += scroll.y;

        if (localPt2.x < 0 || localPt2.y < 0 ||
            localPt2.x > pScrollRect->Rectangle.Width() ||
            localPt2.y > pScrollRect->Rectangle.Height())
            return false;
    }
    else
        TransformPointToLocal(p, pt, ptInParentSpace, mat);
    return true;
}

static inline float DegToRad(Double deg)
{
    return float(deg * MATH_PI / 180.0);
}

// The node matrix from the AS 3D properties: scale, then the x, y and z rotations, then the translation.
// @0x1425f75c0
// MS2-FUNCTIONAL: SIMD matrix construction, the exe keeps the temporaries aligned
void DisplayObjectBase::UpdateTransform3D()
{
    Matrix3F rotXMat(Matrix3F::NoInit), transMat(Matrix3F::NoInit), scaleMat(Matrix3F::NoInit),
             rotYMat(Matrix3F::NoInit), rotZMat(Matrix3F::NoInit);

    transMat = Matrix3F::Translation((float)pGeomData->X, (float)pGeomData->Y, (float)pGeomData->Z);
    scaleMat = Matrix3F::Scaling((float)pGeomData->XScale / 100.f, (float)pGeomData->YScale / 100.f,
                                 (float)pGeomData->ZScale / 100.f);

    rotXMat = pGeomData->XRotation != 0.0 ? Matrix3F::RotationX(DegToRad(pGeomData->XRotation)) : Matrix3F::Identity;
    rotYMat = pGeomData->YRotation != 0.0 ? Matrix3F::RotationY(DegToRad(pGeomData->YRotation)) : Matrix3F::Identity;
    rotZMat = pGeomData->Rotation != 0.0 ? Matrix3F::RotationZ(DegToRad(pGeomData->Rotation)) : Matrix3F::Identity;

    Matrix3F m(transMat, Matrix3F(Matrix3F(rotZMat, rotYMat), Matrix3F(rotXMat, scaleMat)));

    if (m.IsValid())
        SetMatrix3D(m);
}

// The view and projection of the object's own perspective (field of view 55 degrees unless set), centered on the
// projection center or else on the visible frame.
// @0x1425f7af0
void DisplayObjectBase::UpdateViewAndPerspective()
{
    MovieImpl* pmovie = GetMovieImpl();
    if (pmovie && pPerspectiveData)
    {
        const RectF& vfr = pmovie->VisibleFrameRect;
        if (vfr.x2 != vfr.x1 || vfr.y2 != vfr.y1)
        {
            Matrix3F view;
            Matrix4F proj;

            PointF center;
            if (pPerspectiveData->ProjectionCenter.x != 0 || pPerspectiveData->ProjectionCenter.y != 0)
                center = pPerspectiveData->ProjectionCenter;
            else
            {
                center.x = (vfr.x1 + vfr.x2) * 0.5f;
                center.y = (vfr.y1 + vfr.y2) * 0.5f;
            }

            float fieldOfView = pPerspectiveData->FieldOfView ? (float)pPerspectiveData->FieldOfView : 55.0f;
            float focalLength = pPerspectiveData->FocalLength ? (float)pPerspectiveData->FocalLength : 0;

            MovieImpl::MakeViewAndPersp3D(&view, &proj, vfr, center, fieldOfView, focalLength);
            SetViewMatrix3D(view);
            SetProjectionMatrix3D(proj);
        }
    }
}

// ---- (sfr24) virtuals the full exe links by name (work/sfr35/outside-units.tsv) ----

// A plain display object follows the timeline and keeps no animation state.
// @0x1425f1bf0
bool DisplayObjectBase::GetAcceptAnimMoves() const
{
    return true;
}

// @0x1425f1cf0
bool DisplayObjectBase::GetContinueAnimationFlag() const
{
    return false;
}

// @0x1425f3ef0
void DisplayObjectBase::SetAcceptAnimMoves(bool)
{
}

// The perspective values are 0 until a perspective block exists.
// @0x1425f1d50
Double DisplayObjectBase::GetFOV() const
{
    return pPerspectiveData ? pPerspectiveData->FieldOfView : 0;
}

// @0x1425f1db0
Double DisplayObjectBase::GetFocalLength() const
{
    return pPerspectiveData ? pPerspectiveData->FocalLength : 0;
}

// @0x1425f25c0
PointF DisplayObjectBase::GetProjectionCenter() const
{
    return pPerspectiveData ? pPerspectiveData->ProjectionCenter : PointF(0, 0);
}

// The matrices as the scripts see them: the original one while a transform is applied indirectly, else the
// render node's.
// @0x1425f2280
const DisplayObjectBase::Matrix& DisplayObjectBase::GetMatrix() const
{
    if (pIndXFormData)
        return *(const Matrix*)(const void*)&pIndXFormData->OrigTransformMatrix;
    if (pRenNode)
        return pRenNode->M2D();
    return Matrix::Identity;
}

// @0x1425f21b0
const Matrix3F& DisplayObjectBase::GetMatrix3D() const
{
    if (pIndXFormData)
        return pIndXFormData->OrigTransformMatrix;
    if (pRenNode)
        return pRenNode->M3D();
    return Matrix3F::Identity;
}

// A scroll rectangle moves the node, so its saved matrix comes first.
// @0x1425f2210
const DisplayObjectBase::Matrix& DisplayObject::GetMatrix() const
{
    if (!pScrollRect)
        return DisplayObjectBase::GetMatrix();
    return *(const Matrix*)(const void*)&pScrollRect->OrigTransformMatrix;
}

// @0x1425f2140
const Matrix3F& DisplayObject::GetMatrix3D() const
{
    if (!pScrollRect)
        return DisplayObjectBase::GetMatrix3D();
    return pScrollRect->OrigTransformMatrix;
}

// The view matrix set on this object, or with inherit the nearest parent's.
// @0x1425f29a0
bool DisplayObjectBase::GetViewMatrix3D(Matrix3F* m, bool inherit) const
{
    if (pRenNode && pRenNode->HasViewMatrix3D())
    {
        *m = pPerspectiveData->ViewMatrix3D;
        return true;
    }
    if (!inherit || !pParent)
        return false;
    return pParentChar->GetViewMatrix3D(m, inherit);
}

// Only interactive objects track the mouse.
// @0x1425f23d0
Double DisplayObjectBase::GetMouseX() const
{
    return NumberUtil::NaN();
}

// @0x1425f24d0
Double DisplayObjectBase::GetMouseY() const
{
    return NumberUtil::NaN();
}

// @0x1425f3380
bool DisplayObjectBase::IsUsedAsMask() const
{
    return false;
}

// The movie's verbose-action and suppress-errors options.
// @0x1425f3390
bool DisplayObjectBase::IsVerboseAction() const
{
    return (FindMovieImpl()->Flags & MovieImpl::Flag_VerboseAction) != 0;
}

// @0x1425f33e0
bool DisplayObjectBase::IsVerboseActionErrors() const
{
    return (FindMovieImpl()->Flags & MovieImpl::Flag_SuppressActionErrors) == 0;
}

// Events go to the script object, if there is one.
// @0x1425f3980
bool DisplayObject::OnEvent(const EventId& id)
{
    if (HasAvmObject())
        return GetAvmObjImpl()->OnEvent(id);
    return false;
}

// @0x1425f39a0
bool DisplayObjectBase::OnEvent(const EventId&)
{
    return false;
}

// @0x1425f39d0
void DisplayObjectBase::OnEventLoad()
{
    Flags |= Mask_Loaded;
}

// @0x1425f3b60
bool DisplayObjectBase::OnUnloading()
{
    return true;
}

}} // namespace Scaleform::GFx
