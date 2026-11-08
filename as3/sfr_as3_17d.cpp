// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 display list (the MovieRoot,
// AvmDisplayObjContainer, AvmButton, AvmBitmap and ShapeObject functions between the as3_17 natives). Our own
// source, written from the exe.
// MS2-UNIT: sfr_as3_17d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424e20e0-0x1424e2150 .text$mn
// MS2-RANGE: 0x1424e2390-0x1424e2420 .text$mn
// MS2-RANGE: 0x1424e2c10-0x1424e2c90 .text$mn
// MS2-RANGE: 0x1424e2d20-0x1424e2d80 .text$mn
// MS2-RANGE: 0x1424e37a0-0x1424e3830 .text$mn
// MS2-RANGE: 0x1424ede80-0x1424ee490 .text$mn
// MS2-RANGE: 0x1424efb40-0x1424efc30 .text$mn
// MS2-RANGE: 0x1424f03f0-0x1424f05a0 .text$mn
// MS2-RANGE: 0x1424f2010-0x1424f2400 .text$mn
// MS2-RANGE: 0x1424f2450-0x1424f2700 .text$mn
// MS2-RANGE: 0x1424f27b0-0x1424f3320 .text$mn
// MS2-RANGE: 0x1424f33d0-0x1424f3710 .text$mn
// MS2-RANGE: 0x1424f3e60-0x1424f3f40 .text$mn
// MS2-RANGE: 0x1424f4000-0x1424f41f0 .text$mn
// MS2-RANGE: 0x1424f6f50-0x1424f7180 .text$mn
// MS2-RANGE: 0x1424f9570-0x1424f96c0 .text$mn
// MS2-RANGE: 0x1424f9d60-0x1424fa320 .text$mn
// MS2-RANGE: 0x1424fe620-0x1424feab0 .text$mn
// MS2-RANGE: 0x142500770-0x1425008e0 .text$mn
// MS2-RANGE: 0x142501920-0x142501a60 .text$mn
// MS2-RANGE: 0x142502e70-0x142503660 .text$mn
// MS2-RANGE: 0x142507730-0x1425078e0 .text$mn
// MS2-RANGE: 0x142507910-0x142507a40 .text$mn
// MS2-RANGE: 0x1425094e0-0x142509850 .text$mn
#define MS2_AS3_SCU
#define SF_AS3_SHAPEOBJECT_MODEL
#define SF_AS3_AVMBUTTON_MODEL
#include <math.h>
#include <stdlib.h>
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/as3_vec_base.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/gfx_button.h"
#include "ms2/scaleform/include/gfx/gfx_shapedef.h"
#include "ms2/scaleform/include/gfx/gfx_drawingcontext.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_display.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/as3_udbase.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/as2/as2_object.h"
#include "ms2/scaleform/include/kernel/sf_msgformat.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
#include "ms2/scaleform/include/gfx/gfx_valueinfo.h"
#include "ms2/scaleform/include/video/video_statebag.h"
#include "ms2/scaleform/include/gfx/as3/as3_loadqueue.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_net.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_utils.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/gfx_imageresource.h"
#include "ms2/scaleform/include/gfx/gfx_imagecreator.h"
#include "ms2/scaleform/include/render/render_shapedatafloatmp.h"
// render_gradients.h uses Alg::Lerp from kernel/sf_alg.h, which shares its include guard with the
// include/kernel/sf_alg.h this unit already pulled in.
namespace Scaleform { namespace Alg {
template<class T> SF_INLINE T Lerp(T a, T b, T f) { return (b - a) * f + a; }
}}
#include "ms2/scaleform/include/render/render_gradients.h"
#include "ms2/scaleform/include/gfx/gfx_displayobjcontainer.h"
#include "ms2/scaleform/include/gfx/as3/as3_support.h"
#include "ms2/scaleform/include/gfx/as3/as3_gc.h"
#include "ms2/scaleform/include/gfx/as3/as3_stage.h"
#include "ms2/scaleform/include/gfx/gfx_player.h"
#include "ms2/scaleform/include/gfx/gfx_placeobject.h"
#include "ms2/scaleform/include/gfx/as3/as3_abcfilewithmoviedef.h"
#include "ms2/scaleform/include/gfx/as3/as3_moviedefrootnode.h"
#include "ms2/scaleform/include/gfx/as3/as3_valueobjectinterface.h"
// Button::StateCharArray's ResizeNoConstruct is out of line in the exe (0x1425248e0, instantiated in sfr_as3_19).
namespace Scaleform {
template <> void ArrayDataBase<GFx::Button::CharToRec, AllocatorLH<GFx::Button::CharToRec, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);
// MovieDefRootNode::AbcFiles' ResizeNoConstruct is out of line too (0x142524b90, instantiated in sfr_as3_19).
template <> void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);
}
#undef GetObject   // windows.h

bool FUN_1424f27b0(Scaleform::GFx::AS3::AvmBitmap* self);   // AvmBitmap: the image shape of the render node
void FUN_142524990(void* arr, void* policy, Scaleform::UPInt n);   // ArrayDH<Ptr<InteractiveObject> >::Resize, out of line
namespace Scaleform { namespace GFx { void* FUN_14261e310(); } }   // the AMP server (AmpServer::GetInstance)
// ASRefCountCollector::Stats as Collect() gets it here: the AMP stats and the two root counters (Stats(ampStats)).
struct Sfr17dCollectorEntry
{
    Sfr17dCollectorEntry(Scaleform::RefCountImpl* advanceStats) : pObject(advanceStats) { RootsNumber = RootsFreedTotal = 0; }
    Scaleform::Ptr<Scaleform::RefCountImpl> pObject;
    unsigned                                RootsNumber;
    unsigned                                RootsFreedTotal;
};
// ASRefCountCollector: queues a collection with the AMP stats (0x142504630, sfr_as3_17)
namespace Scaleform { class RefCountImpl; namespace GFx { namespace AS3 { void Sfr33CollectorQueue(Scaleform::UByte* gc, Scaleform::RefCountImpl* stats); } } }

namespace Scaleform {

void LogDebugMessage(LogMessageId id, const char* fmt, ...);

namespace Render {

inline ComplexFill::ComplexFill() : BindIndex(~0u) {}

inline void TreeShape::SetShape(ShapeMeshProvider* pshape)
{
    NodeData* data = GetWritableData(Change_Shape);
    if (pshape)
        pshape->AddRef();
    if (data->pMeshProvider)
        data->pMeshProvider->Release();
    data->pMeshProvider = pshape;
    AddToPropagate();
}

} // namespace Render

namespace GFx { namespace AS3 {

// The level clips, as the movie holds them (MovieImpl::LevelInfo with its counted sprite reference).
struct Sfr17dLevelInfo
{
    int                     Level;
    Ptr<InteractiveObject>  pSprite;
};

// @0x1424efb40
void MovieRoot::ClearDisplayList()
{
    DisplayObjContainer* pmain = reinterpret_cast<DisplayObjContainer*>(pMovieImpl->pMainMovie);
    pmain->mDisplayList.Clear(pmain);
    pmain->SetDirtyFlag();
    pMovieImpl->pMainMovie->OnEventUnload();
    pMovieImpl->pMainMovie->ForceShutdown();
    reinterpret_cast<ArrayLH<Sfr17dLevelInfo, 0x147>*>(&pMovieImpl->pMovieLevels)->Clear();
}

// tabChildren = false (the flag as the exe tests it, a shifted bit)
static inline bool Sfr17dTabChildrenDisabled(const InteractiveObject* p)
{
    return (bool)((p->Flags >> 15) & 1);
}

// @0x142500770
void AvmDisplayObjContainer::FillTabableArray(InteractiveObject::FillTabableParams* params)
{
    UPInt n = GetDisplayObjContainer()->mDisplayList.GetCount();
    if (n == 0 || Sfr17dTabChildrenDisabled(GetDisplayObjContainer()))
        return;
    for (UPInt i = 0; i < n; ++i)
    {
        DisplayObjectBase* ch = GetDisplayObjContainer()->mDisplayList.GetDisplayObject(i);
        if (ch && ch->IsInteractiveObject() && ch->GetVisible())
        {
            InteractiveObject* pio = static_cast<InteractiveObject*>(ch);
            if (pio->TabIndex > 0 && !params->TabIndexed)
            {
                params->Array->Resize(0);
                params->TabIndexed = true;
            }
            if ((pio->IsTabable() || (params->InclFocusEnabled && pio->IsFocusEnabled(GFx_FocusMovedByKeyboard))) &&
                (!params->TabIndexed || pio->TabIndex > 0))
            {
                params->Array->PushBack(Ptr<InteractiveObject>(pio));
            }
            if (ch->IsDisplayObjContainer())
                static_cast<DisplayObjContainer*>(ch)->FillTabableArray(params);
        }
    }
}

// @0x142501920
InteractiveObject* AvmDisplayObjContainer::FindInsertToPlayList(InteractiveObject* ch)
{
    InteractiveObject* afterCh = NULL;
    DisplayObjContainer* dobjParent = GetDisplayObjContainer();
    unsigned n = (unsigned)dobjParent->mDisplayList.GetCount();
    if (n == 0)
        afterCh = dobjParent->pPlayPrev;
    else
    {
        // the last child before ch that is in the play list
        InteractiveObject* dobPrevSpr = NULL;
        unsigned i = 0;
        for (; i < n; ++i)
        {
            DisplayObjectBase* pcur = dobjParent->mDisplayList.GetDisplayObject(i);
            if (pcur == ch)
                break;
            if (pcur->IsInteractiveObject() && static_cast<InteractiveObject*>(pcur)->IsInPlayList())
                dobPrevSpr = static_cast<InteractiveObject*>(pcur);
        }
        if (!dobPrevSpr)
            afterCh = dobjParent->pPlayPrev;
        else
        {
            // the next child after ch that is in the play list
            InteractiveObject* dobNextSpr = NULL;
            for (++i; i < n; ++i)
            {
                DisplayObjectBase* pcur = dobjParent->mDisplayList.GetDisplayObject(i);
                if (pcur->IsInteractiveObject() && static_cast<InteractiveObject*>(pcur)->IsInPlayList())
                {
                    dobNextSpr = static_cast<InteractiveObject*>(pcur);
                    break;
                }
            }
            if (dobNextSpr)
                afterCh = dobNextSpr;
            else
            {
                // walk back from the previous one to the first object whose parent chain leaves this one
                InteractiveObject* pcur = dobPrevSpr;
                InteractiveObject* parpar = GetIntObj()->GetParent();
                for (; pcur; pcur = pcur->pPlayPrev)
                {
                    InteractiveObject* c = pcur;
                    for (; c; c = c->GetParent())
                    {
                        if (c == GetIntObj())
                            break;
                        else if (c == parpar)
                        {
                            c = NULL;
                            break;
                        }
                    }
                    if (!c)
                    {
                        afterCh = pcur;
                        break;
                    }
                }
            }
        }
    }
    return afterCh;
}

// MS2-FUNCTIONAL 0x1424f6f50: the exe recomputes the parent NodeData page index for GetAt instead of sharing it with the child count
// @0x1424f6f50
bool AvmButton::DetachChild(DisplayObjectBase* ch)
{
    bool found = false;
    Button* pbtn = GetButton();
    for (unsigned state = 0; state < 3; ++state)
    {
        Ptr<Render::TreeContainer> prenNode = pbtn->GetStateRenderContainer((Button::ButtonState)state);
        auto& chars = pbtn->GetCharacters((Button::ButtonState)state).Characters;
        for (UPInt i = 0, n = chars.GetSize(); i < n; ++i)
        {
            if (chars[i].Char != ch)
                continue;
            ch->pParent = NULL;
            if (ch->GetRenderNode())
            {
                Render::TreeContainer* pparent = static_cast<Render::TreeContainer*>(ch->GetRenderNode()->GetParent());
                if (pparent)
                {
                    for (UPInt j = 0, cnt = pparent->GetReadOnlyData()->Children.GetSize(); j < cnt; ++j)
                    {
                        if (pparent->GetAt(j) == ch->GetRenderNode())
                        {
                            pparent->Remove(j, 1);
                            break;
                        }
                    }
                }
            }
            found = true;
        }
    }
    return found;
}

// @0x142507730
RectF AvmBitmap::GetBounds(const Matrix& t) const
{
    RectF r(0);
    if (pImage)
    {
        Render::ImageRect irect = pImage->GetImage()->GetRect();
        Render::Matrix2F m;
        if (Render::Image* pimg = pImage->GetImage()->GetAsImage())
        {
            pimg->GetMatrix(&m);
            m.EncloseTransform(&r, RectF(float(UInt32(irect.x1 * 20)), float(UInt32(irect.y1 * 20)),
                                         float(UInt32(irect.x2 * 20)), float(UInt32(irect.y2 * 20))));
        }
        else
            r = RectF(float(UInt32(irect.x1 * 20)), float(UInt32(irect.y1 * 20)), float(UInt32(irect.x2 * 20)),
                      float(UInt32(irect.y2 * 20)));
    }
    RectF result(RectF::NoInit);
    t.EncloseTransform(&result, RectF(0, 0, r.GetSize()));
    return result;
}

// The exe calls the definition's GetBoundsLocal (slot 7) without loading a morph ratio into xmm2.
struct Sfr17dBoundsLocalView
{
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void Slot6() = 0;
    virtual RectF GetBoundsLocal() const = 0;
};

// @0x142507910
RectF ShapeObject::GetBounds(const Matrix& t) const
{
    RectF r(0);
    if (pDrawing)
    {
        RectF b(0);
        pDrawing->ComputeBound(&b);
        if (!b.IsEmpty())
        {
            RectF tb = t.EncloseTransform(b);
            if (!r.IsEmpty())
                r.Union(tb);
            else
                r = tb;
        }
    }
    else
    {
        r = t.EncloseTransform(reinterpret_cast<const Sfr17dBoundsLocalView*>(pDef.GetPtr())->GetBoundsLocal());
    }
    return r;
}

}} // namespace GFx::AS3
} // namespace Scaleform

// AvmBitmap::CreateBitmapShape: the shape of the bitmap's tree shape node, a rectangle of the image's size (in
// twips) filled with the image, smoothed unless the Bitmap object turned smoothing off. Without an image, a unit
// rectangle with no fill. An image resource that is only an image source gets its image from the image creator.
// MS2-FUNCTIONAL 0x1424f27b0: frame layout only: the exe puts the ImageCreateInfo below the ImageRect (cinfo rbp-0x71, irect rbp-0x39)
// @0x1424f27b0
bool FUN_1424f27b0(Scaleform::GFx::AS3::AvmBitmap* self)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    Render::TreeShape* tshp = static_cast<Render::TreeShape*>(self->pRenNode.GetPtr());
    Ptr<Render::ShapeDataFloat> shapeData = *SF_HEAP_AUTO_NEW(self) Render::ShapeDataFloat();
    Render::FillStyleType fill;
    fill.Color = 0;
    fill.pFill = *SF_HEAP_AUTO_NEW(self) Render::ComplexFill();
    if (self->pImage)
    {
        Ptr<Render::Image> img;
        if (self->pImage->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
            img = static_cast<Render::Image*>(self->pImage->GetImage());
        else
        {
            MovieImpl* pmovie = static_cast<DisplayObjectBase*>(self)->GetMovieImpl();
            ImageCreator* pcreator = Ptr<ImageCreator>(*(ImageCreator*)pmovie->GetStateBag()->GetStateAddRef(State::State_ImageCreator));
            if (pcreator)
            {
                ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, static_cast<DisplayObjectBase*>(self)->GetMovieImpl()->GetMovieHeap(), 1,
                                      Resource::Use_Bitmap);
                img = *pcreator->CreateImage(cinfo, (Render::ImageSource*)self->pImage->GetImage());
            }
            else
            {   LogDebugMessage(Log_Warning, "Image is not created: can't find ImageCreator."); return false; }
        }
        fill.pFill->pImage = img;
        if (!img)
        {
            LogDebugMessage(Log_Warning, "Image is not created.");
            return false;
        }
        fill.pFill->ImageMatrix.SetIdentity();
        fill.pFill->ImageMatrix.AppendScaling(0.05f);
        fill.pFill->FillMode = Render::ImageFillMode(Render::Wrap_Clamp, Render::Sample_Point);
        // SDK: GetAS3Obj() is tested, then re-read as GetAS3Bitmap(); smoothing is on by default without an AS3 object
        if (!self->GetAS3Obj() || static_cast<AS3::Instances::fl_display::Bitmap*>(self->GetAS3Obj())->Smoothing)
            fill.pFill->FillMode = Render::ImageFillMode(Render::Wrap_Clamp, Render::Sample_Linear);
        Render::ImageRect irect = img->GetRect();
        Render::Matrix2F m;
        img->GetMatrix(&m);
        RectF r(0);
        m.EncloseTransform(&r, RectF(float(irect.x1), float(irect.y1), float(irect.x2), float(irect.y2)));


        shapeData->AddFillStyle(fill);
        shapeData->StartPath(1, 0, 0);
        shapeData->MoveTo(0, 0);
        shapeData->LineTo(r.Width() * 20.0f, 0);
        shapeData->LineTo(r.Width() * 20.0f, r.Height() * 20.0f);
        shapeData->LineTo(0, r.Height() * 20.0f);
        shapeData->ClosePath();
        shapeData->EndPath();
        shapeData->EndShape();
        Ptr<Render::ShapeMeshProvider> prov = *SF_HEAP_AUTO_NEW(self) Render::ShapeMeshProvider(shapeData);
        tshp->SetShape(prov);
    }
    else
    {
        shapeData->StartPath(0, 0, 0);
        shapeData->MoveTo(0, 0);
        shapeData->LineTo(1.0f, 1.0f);
        shapeData->ClosePath();
        shapeData->EndPath();
        shapeData->EndShape();
        Ptr<Render::ShapeMeshProvider> prov = *SF_HEAP_AUTO_NEW(self) Render::ShapeMeshProvider(shapeData);
        tshp->SetShape(prov);
    }
    return true;
}

namespace Scaleform {
namespace GFx { namespace AS3 {

// The bitmap's node is a tree shape holding its image shape; without an image shape, no node.
// MS2-FUNCTIONAL 0x1424f3e60: instruction scheduling inside the inlined TreeShape NodeData constructor differs
// @0x1424f3e60
Ptr<Render::TreeNode> AvmBitmap::CreateRenderNode(Render::ContextImpl::Context& context) const
{
    AvmBitmap* self = const_cast<AvmBitmap*>(this);
    self->pRenNode = *context.CreateEntry<Render::TreeShape>();
    if (!FUN_1424f27b0(self))
    {
        self->pRenNode = NULL;
        return NULL;
    }
    return pRenNode;
}

}} // namespace GFx::AS3
} // namespace Scaleform

using namespace Scaleform;
using namespace Scaleform::GFx;
using namespace Scaleform::GFx::AS3;

// The AMP server's slot 37: the movie whose heap is heap (a counted reference in *ppmovie).
typedef bool (*Sfr17dAmpFindMovieByHeap)(void* amp, MemoryHeap* heap, Movie** ppmovie);

// The collector's emergency collection (inlined): queues one (unless a collection runs, +0xb1: then only asks for
// one, +0xb0), frees an empty queue's pages unless the flags keep them (bit 1) and restarts the counters.
static SF_INLINE void Sfr17dEmergencyCollect(UByte* gc)
{
    if (gc[0xb1] > 0)
    {
        gc[0xb0] = 1;
        return;
    }
    const unsigned count = *reinterpret_cast<unsigned*>(gc + 0x18);
    {
        Sfr17dCollectorEntry e(NULL);
        reinterpret_cast<AS3::ASRefCountCollector*>(gc)->Collect(reinterpret_cast<AS3::ASRefCountCollector::Stats*>(&e));
        *reinterpret_cast<unsigned*>(gc + 0x88) = 0;
        *reinterpret_cast<unsigned*>(gc + 0x90) = Alg::Max(*reinterpret_cast<unsigned*>(gc + 0x90), count);
        *reinterpret_cast<unsigned*>(gc + 0x94) = count;
        if (gc[0x78] & 0x10)
            gc[0xb0] = 1;
    }
    if (!(gc[0x78] & 2) && *reinterpret_cast<UPInt*>(gc + 0x18) == 0)
        reinterpret_cast<AS3::ASRefCountCollector*>(gc)->Roots.ClearAndRelease();
    *reinterpret_cast<unsigned*>(gc + 0x8c) = *reinterpret_cast<unsigned*>(gc + 0xa8);
    *reinterpret_cast<unsigned*>(gc + 0x90) = 0;
}

// MemoryContextImpl::HeapLimit::Collect: flushes the text format caches, collects (with the AMP stats of the movie
// on this heap, if AMP knows it) and notes the footprint after the collection (+0x20).
// HeapLimit's members are private, so they are reached by offset.
// @0x1424f03f0
void FUN_1424f03f0(UByte* self, MemoryHeap* heap)
{
    MemoryContextImpl* ctx = *reinterpret_cast<MemoryContextImpl**>(self + 0x10);
    if (ctx->TextAllocator)
    {
        ctx->TextAllocator->FlushTextFormatCache(true);
        (*reinterpret_cast<MemoryContextImpl**>(self + 0x10))->TextAllocator->FlushParagraphFormatCache(true);
    }
    void* amp = FUN_14261e310();
    Movie* pmovie;
    if (reinterpret_cast<Sfr17dAmpFindMovieByHeap>((*static_cast<void***>(amp))[37])(amp, heap, &pmovie))
    {
        void* stats = *reinterpret_cast<void**>(reinterpret_cast<UByte*>(pmovie) + 0x30);
        UByte* gc = reinterpret_cast<UByte*>((*reinterpret_cast<MemoryContextImpl**>(self + 0x10))->ASGC.GetPtr());
        if (gc[0xb1] > 0)
            gc[0xb0] = 1;
        else
        {
            AS3::Sfr33CollectorQueue(gc, static_cast<RefCountImpl*>(stats));
            if (!(gc[0x78] & 2) && *reinterpret_cast<UPInt*>(gc + 0x18) == 0)
                reinterpret_cast<AS3::ASRefCountCollector*>(gc)->Roots.ClearAndRelease();
            *reinterpret_cast<unsigned*>(gc + 0x90) = 0;
            *reinterpret_cast<unsigned*>(gc + 0x8c) = *reinterpret_cast<unsigned*>(gc + 0xa8);
        }
        pmovie->Release();
    }
    else
        Sfr17dEmergencyCollect(reinterpret_cast<UByte*>((*reinterpret_cast<MemoryContextImpl**>(self + 0x10))->ASGC.GetPtr()));
    *reinterpret_cast<UPInt*>(self + 0x20) = heap->GetFootprint();
}

// VM::PrepareClassTraits: registers tr and hands it on
static inline Pickable<ClassTraits::Traits> Sfr17dPrepareClassTraits(VM& vm, ClassTraits::Traits* tr)
{
    vm.RegisterClassTraits(*tr);
    return Pickable<ClassTraits::Traits>(tr);
}

// The XMLSupportImpl constructor (0x1424dc160, sfr_as3_15) as the exe inlines it here.
__forceinline XMLSupportImpl::XMLSupportImpl(VM& vm, InlineCtorTag)
    : XMLSupport(vm, true), pVM(&vm),
      TraitsQName(Sfr17dPrepareClassTraits(vm, SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::fl::QName(vm))),
      TraitsXML(Sfr17dPrepareClassTraits(vm, SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::fl::XML(vm))),
      TraitsXMLList(Sfr17dPrepareClassTraits(vm, SF_HEAP_NEW(vm.GetMemoryHeap()) ClassTraits::fl::XMLList(vm)))
{
}

// @0x1424f9570
// VM::EnableXMLSupport: the E4X classes of the VM.
void FUN_1424f9570(VM* vm)
{
    vm->XMLSupport_ = Pickable<XMLSupport>(SF_HEAP_NEW(vm->MHeap) XMLSupportImpl(*vm, XMLSupportImpl::InlineCtorTag()));
}

namespace Scaleform { namespace GFx { namespace AS3 {

// DisplayObjectBase::CharToSprite as the exe inlines it: the sprite part, or NULL.
static SF_FORCEINLINE InteractiveObject* Sfr17dCharToSprite(DisplayObjectBase* p)
{
    return p->IsSprite() ? static_cast<InteractiveObject*>(p) : NULL;
}

// Creates every record's character in each state it shows in: under the state's container sprite (made once,
// character 0x10001, and put on the play list), with the record's placement; the current state's container goes
// into the button's render tree.
// @0x1424f2e90
void AvmButton::CreateCharacters()
{
    Button*          pbtn     = GetButton();
    ButtonDef*       pdef     = pbtn->GetButtonDef();
    Button::ButtonState curState = pbtn->GetCurrentState();
    for (UPInt i = 0, n = pdef->GetRecordsCount(); i < n; i++)
    {
        const ButtonRecord& rec = pdef->GetRecordAt(i);
        UByte flags = rec.Flags;
        for (UByte mask = 1; mask & ButtonRecord::Mask_All; mask <<= 1)
        {
            if (!(flags & mask))
                continue;
            Button::ButtonState state = Button::Up;
            if (mask & ButtonRecord::Mask_Up)
                state = Button::Up;
            else if (mask & ButtonRecord::Mask_Down)
                state = Button::Down;
            else if (mask & ButtonRecord::Mask_Over)
                state = Button::Over;
            else if (mask & ButtonRecord::Mask_HitTest)
                state = Button::Hit;
            Button::StateCharArray&    chars    = pbtn->GetCharacters(state).Characters;
            Ptr<Render::TreeContainer> prenNode = pbtn->GetStateRenderContainer(state);
            if (!prenNode)
                prenNode = pbtn->CreateStateRenderContainer(state);
            Ptr<InteractiveObject> pobj;
            if (chars.GetSize() == 0)
            {
                CharacterCreateInfo ccinfo = GetButton()->pDefImpl->GetCharacterCreateInfo(ResourceId(0x10001));
                Ptr<DisplayObjectBase> ch = *GetButton()->pASRoot->pASSupport->CreateCharacterInstance(
                    GetButton()->pASRoot->GetMovieImpl(), ccinfo, NULL, rec.CharacterId, CharacterDef::Unknown);
                pobj = Sfr17dCharToSprite(ch);
                {
                    Button::CharToRec cr;
                    cr.Char   = pobj.GetPtr();
                    cr.Record = &rec;
                    chars.PushBack(cr);
                }
                if (!pobj->GetParent())
                {
                    pobj->AddToPlayList();
                    pobj->ModifyOptimizedPlayList();
                }
                prenNode->Insert(prenNode->GetSize(), ch->GetRenderNode());
            }
            else
            {
                DisplayObjectBase* ch = chars[0].Char;
                pobj = Sfr17dCharToSprite(ch);
            }
            CharacterCreateInfo ccinfo = GetButton()->pDefImpl->GetCharacterCreateInfo(rec.CharacterId);
            if (ccinfo.pCharDef)
            {
                const Matrix2F&  mat = rec.ButtonMatrix;
                const Cxform&    cx  = rec.ButtonCxform;
                CharPosInfo pos;
                pos.ColorTransform = cx;
                pos.Matrix_1       = mat;
                pos.CharacterId    = rec.CharacterId;
                pos.BlendMode      = (UByte)rec.BlendMode;
                pos.Depth          = rec.Depth;
                pos.Flags.Flags    = CharPosInfoFlags::Flags_HasDepth | CharPosInfoFlags::Flags_HasCharacterId |
                                     CharPosInfoFlags::Flags_HasMatrix | CharPosInfoFlags::Flags_HasCxform |
                                     CharPosInfoFlags::Flags_HasBlendMode;
                DisplayObjectBase* pnew = static_cast<DisplayObjContainer*>(pobj.GetPtr())->AddDisplayObject(
                    pos, static_cast<MovieRoot*>(GetButton()->pASRoot)->BuiltinsMgr.CreateEmptyString(), NULL, NULL, 0, 4,
                    NULL, NULL);
                if (pnew && rec.pFilters)
                    pnew->SetFilters(rec.pFilters);
            }
            if (curState == state && !prenNode->GetParent())
            {
                Render::TreeContainer* pcont = pbtn->GetRenderContainer();
                pcont->Insert(pcont->GetSize(), prenNode);
            }
        }
    }
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// AvmStage (as3_avm.h): CreateStage inlines its constructor, so its vftables and its bases' are emitted here:
// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmStage@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317d600
// MS2-PIN: ??_7AvmStage@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317d6f8
// MS2-PIN: ??_7AvmStage@AS3@GFx@Scaleform@@6B@ 0x14317d7b0
// MS2-PIN: ??_7AvmInteractiveObjBase@GFx@Scaleform@@6B@ 0x14317bfe8
// MS2-PIN: ??_7AvmDisplayObjContainerBase@GFx@Scaleform@@6B@ 0x14317c0a0
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317cbe8
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6BAvmInteractiveObjBase@23@@ 0x14317cce0
// MS2-PIN: ??_7AvmDisplayObjContainer@AS3@GFx@Scaleform@@6B@ 0x14317cd98
}}}

// The Stage constructor (0x1424d9b50, sfr_as3_15) as the exe inlines it in CreateStage.
__forceinline Stage::Stage(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id, InlineCtorTag)
    : DisplayObjContainer(pbindingDefImpl, pasRoot, pparent, id),
      CurrentStageOrientation(GetStringManager()->GetEmptyStringNode())
{
    DisplayObjectBase::Flags |= DisplayObjectBase::Mask_Loaded;
    DisplayObject::Flags |= DisplayObject::Mask_TimelineObject;
    MouseCursorEventCnt = 0;
}

// ActionQueueType::InsertEntry (0x142512800, sfr_as3_18) as the exe inlines it in CreateStage.
static SF_FORCEINLINE MovieRoot::ActionEntry* Sfr17dInsertEntry(MovieRoot::ActionQueueType& aq, MovieRoot::ActionLevel lvl)
{
    MovieRoot::ActionEntry* pentry = aq.GetNewEntry();
    MovieRoot::ActionQueueEntry& q = aq.Entries[lvl];
    if (!q.pInsertEntry)
    {
        pentry->pNextEntry = q.pActionRoot;
        q.pActionRoot = pentry;
    }
    else
    {
        pentry->pNextEntry = q.pInsertEntry->pNextEntry;
        q.pInsertEntry->pNextEntry = pentry;
    }
    q.pInsertEntry = pentry;
    if (!pentry->pNextEntry)
        q.pLastEntry = pentry;
    ++aq.ModId;
    return pentry;
}

// @0x1424f4000
// MovieRoot::CreateStage: the stage and its AVM part in one allocation; its load event goes first in the queue.
// Returns the AVM part.
AvmInteractiveObj* FUN_1424f4000(MovieRoot* proot, MovieDefImpl* pmovieDef)
{
    void*  pmem   = proot->GetMovieImpl()->pHeap->Alloc(sizeof(Stage) + 0x48);
    Stage* pstage = pmem ? new (pmem) Stage(pmovieDef, proot, NULL, ResourceId(0x40000), Stage::InlineCtorTag()) : NULL;
    if (proot->pStage)
        proot->pStage->Release();
    proot->pStage = pstage;
    AvmInteractiveObj* pavmObj = reinterpret_cast<AvmStage*>(static_cast<UByte*>(pmem) + sizeof(Stage));
    if (pavmObj)
        new (pavmObj) AvmStage(pstage);
    else
        pavmObj = NULL;
    DisplayObject* pch = proot->pStage;
    // ActionEntry::SetAction, with Value::SetUndefined (0x142423b90) called out of line as in the exe
    MovieRoot::ActionEntry* pe = Sfr17dInsertEntry(proot->ActionQueue, MovieRoot::AL_Highest);
    void (AS3::Value::*setUndefined)() = &AS3::Value::SetUndefined;
    pe->Type = MovieRoot::ActionEntry::Entry_Event;
    pe->pCharacter = pch;
    new (&pe->mEventId) EventId(EventId::Event_Load);
    pe->CFunction = NULL;
    pe->pAS3Obj = NULL;
    (pe->Function.*setUndefined)();
    pe->pNLoadInitCL = NULL;
    return pavmObj;
}

namespace Scaleform { namespace GFx { namespace AS3 {

// SPtr<T>::SetPtr written out: the exe inlines LoaderInfo::Content's assignment in ExecuteFrame0Events.
template <class T>
static SF_FORCEINLINE void Sfr17dSetSPtr(SPtr<T>& sp, T* p)
{
    T*& raw = sp.GetRawRef();
    if (p != raw)
    {
        if (raw)
        {
            if ((UPInt)raw & 1)
                raw = (T*)((UPInt)raw - 1);
            else
                raw->Release();
        }
        if (p)
            p->AddRef();
        raw = p;
    }
}

// MS2-FUNCTIONAL 0x1424fe620: written from the exe's control flow (register allocation differs: the exe keeps root in r14, the stage in r15)
// @0x1424fe620
// Builds the root movie ("root1") on the stage, gives it its LoaderInfo, runs frame 0 and the constructors it queued.
void Stage::ExecuteFrame0Events()
{
    MovieDefImpl* pdefImpl = pDefImpl;
    MovieImpl*    pmovie   = GetMovieImpl();
    MovieRoot*    as3root  = static_cast<MovieRoot*>(pmovie->pASMovieRoot);
    CharacterCreateInfo ccinfo = { pdefImpl->GetDataDef(), pdefImpl, NULL };
    Ptr<Sprite> root = *static_cast<Sprite*>(GetASMovieRoot()->pASSupport->CreateCharacterInstance(
        pmovie, ccinfo, this, ResourceId(0), CharacterDef::Sprite));
    root->SetLoadedSeparately(true);
    root->DisplayObjectBase::Flags |= DisplayObjectBase::Mask_MovieClip | DisplayObjectBase::Mask_Loaded;
    root->InteractiveObject::Flags |= InteractiveObject::Mask_MouseDisabled;
    if (root->HasAvmObject())
        root->GetAvmSprite()->ExecuteInitActionFrameTags(0);
    root->SetName(ASString(GetMovieImpl()->pASMovieRoot->GetStringManager()->CreateConstString("root1")));

    pRoot = root;
    SetFOV(55.0);
    root->SetFOV(55.0);
    Ptr<Render::TreeContainer> node = GetRenderContainer();
    mDisplayList.AddEntryAtIndex(this, (unsigned)mDisplayList.GetCount(), root);
    static_cast<Render::TreeContainer*>(GetMovieImpl()->pRenderRoot)->Insert(0, node);
    root->pParent = this;
    root->AddToPlayList();

    as3root->ASFramesToExecute += ToAvmDisplayObj(this)->CreateASInstance(false);
    as3root->ASFramesToExecute += ToAvmDisplayObj(root)->CreateASInstance(false);

    VM&        vm  = *as3root->pAVM;
    SPtr<Class> cls = vm.GetClass(StringDataPtr("flash.display.LoaderInfo"));
    if (cls)
    {
        SPtr<Instances::fl_display::LoaderInfo> li;
        if (static_cast<ASVM&>(vm)._constructInstance(reinterpret_cast<SPtr<Object>&>(li), cls, 0, NULL))
        {
            if (ToAvmDisplayObj(root)->pAS3RawPtr || ToAvmDisplayObj(root)->pAS3CollectiblePtr)
            {
                ToAvmDisplayObj(root)->GetAS3Obj()->SetLoaderInfo(li);
                Sfr17dSetSPtr(li->Content, ToAvmDisplayObj(root)->GetAS3Obj());
            }
        }
    }

    root->ExecuteFrame0Events();
    static_cast<MovieRoot*>(GetMovieImpl()->pASMovieRoot)->ExecuteActionQueue(MovieRoot::AL_Highest);
    static_cast<MovieRoot*>(GetMovieImpl()->pASMovieRoot)->ExecuteActionQueue(MovieRoot::AL_High);
    void (Value::*setUndefined)() = &Value::SetUndefined;
    while (unsigned n = as3root->ASFramesToExecute)
    {
        as3root->ASFramesToExecute = 0;
        VM& avm = *as3root->pAVM;
        avm.ExecuteCode(n);
        if (avm.HandleException)
        {
            avm.HandleException = false;
            avm.OutputError(avm.ExceptionObj);
            (avm.ExceptionObj.*setUndefined)();
            FrameCounterObj->DisplayObject::Flags |= DisplayObject::Mask_ExecutionAborted;
        }
    }
    ToAvmDisplayObj(root)->OnAdded(true);
    GetMovieImpl()->Flags |= MovieImpl::Flag_OptAdvListInvalid;
    FrameCounterObj->AdvanceFrame(true, 0.0f);
    static_cast<MovieRoot*>(GetMovieImpl()->pASMovieRoot)->ExecuteActionQueue(MovieRoot::AL_Frame);
}

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace AS3 {

// The file loader MovieRoot::CheckAvm hands the new VM (sfr_as3_17 defines its out-of-line slots and vftable
// 0x14317f470; the same class here, so the inlined CheckAvm below stores that vftable).
class Sfr33NullFileLoader : public FileLoader
{
public:
    virtual UPInt GetSize() const;
    virtual const Ptr<Abc::File>& GetFile(UPInt n);
    virtual const Abc::File* GetFile(const ASString& name);
};

// (sfr_as3_17's inline copy at 0x142509c20)
inline const Ptr<Abc::File>& Sfr33NullFileLoader::GetFile(UPInt)
{
    static Ptr<Abc::File> f;
    return f;
}

struct Sfr17dFlashUIAccess : FlashUI
{
    static void SetCurrState(FlashUI& ui, StateType s) { static_cast<Sfr17dFlashUIAccess&>(ui).FlashUI::SetCurrState(s); }
};

// MovieRoot::CheckAvm (0x1424eecb0, sfr_as3_17) as ExecuteAbc inlines it: the VM is created on first use.
static __forceinline void Sfr17dCheckAvm(MovieRoot* self)
{
    Scaleform::AutoPtr<ASVM>& avm = *reinterpret_cast<Scaleform::AutoPtr<ASVM>*>(&self->pAVM);
    if (!avm)
    {
        const ActionControl* pac = Ptr<ActionControl>(*static_cast<ActionControl*>(
            self->GetMovieImpl()->GetStateBag()->GetStateAddRef(State::State_ActionControl)));
        if (pac != NULL)
        {
            self->SetNeedToCheckOpCode((pac->GetActionFlags() & ActionControl::Action_Verbose) != 0);
        }
        else
        {
            self->SetNeedToCheckOpCode(false);
        }
        Sfr17dFlashUIAccess::SetCurrState(*self, FlashUI::sStep);
        Sfr33NullFileLoader loader;
        avm = SF_HEAP_NEW(self->GetMovieImpl()->GetMovieHeap())
            ASVM(self, *self, loader, self->BuiltinsMgr, *self->MemContext->ASGC);
        self->pAVM->ExecuteCode(1);
    }
}

// VM::FindVMAbcFileWeak, inlined: the loaded file whose source is name.
static __forceinline SPtr<VMAbcFile> Sfr17dFindVMAbcFileWeak(const VM& vm, const char* name)
{
    for (UPInt i = 0, n = vm.VMAbcFilesWeak.GetSize(); i < n; ++i)
    {
        VMAbcFile* abcFile = vm.VMAbcFilesWeak[i];
        if (strcmp(abcFile->GetAbcFile().Source.ToCStr(), name) == 0)
            return SPtr<VMAbcFile>(vm.VMAbcFilesWeak[i]);
    }
    return SPtr<VMAbcFile>(NULL);
}

// VM::LoadFile, inlined: the file's classes and scripts are registered, or no file.
struct Sfr17dAbcLoad
{
    static __forceinline SPtr<VMAbcFile> LoadFile(VM& vm, const Ptr<Abc::File>& file)
    {
        SPtr<VMAbcFile> pfile = Pickable<VMAbcFile>(SF_HEAP_NEW(vm.GetMemoryHeap()) VMAbcFile(vm, file));
        if (pfile->RegisterUserDefinedClassTraits() && pfile->RegisterScrips(false))
            return pfile;
        return SPtr<VMAbcFile>();
    }
};

// MS2-FUNCTIONAL 0x1424f9d60: SDK form with CheckAvm, FindVMAbcFileWeak and LoadFile inlined as the exe does; the
// this/pabc/pspr register permutation (exe r14/rbp/r15) is left
// @0x1424f9d60
// A file already loaded under the same name ("file[name]") is reused; otherwise the block is parsed and its classes
// and scripts registered. Either way the movie's root node keeps the file alive.
bool MovieRoot::ExecuteAbc(const AbcDataBuffer* pabc, DisplayObjContainer* pspr)
{
    bool          result   = false;
    MovieDefImpl* pdefImpl = pspr->GetResourceMovieDef();
    String fileName(pabc->FileName);
    if (pabc->Name.GetSize() != 0)
    {
        fileName.AppendString("[");
        fileName += pabc->Name;
        fileName.AppendString("]");
    }

    SPtr<VMAbcFile> vmabc = Sfr17dFindVMAbcFileWeak(*pAVM, fileName.ToCStr());
    if (!vmabc)
    {
        Scaleform::AutoPtr<Abc::Reader> preader = SF_HEAP_NEW(GetMovieImpl()->GetMovieHeap()) Abc::Reader(pabc->Data, pabc->DataSize);
        Ptr<Abc::File> file = *SF_HEAP_NEW(GetMovieImpl()->GetMovieHeap())
            ASVM::AbcFileWithMovieDef(pdefImpl, const_cast<AbcDataBuffer*>(pabc));
        file->Source   = fileName;
        file->DataSize = pabc->DataSize;
        result = preader->Read(*file);
        if (result)
        {
            Sfr17dCheckAvm(this);
            vmabc = Sfr17dAbcLoad::LoadFile(*pAVM, file);
            VM* vm = pAVM;   // OutputAndIgnoreException, inlined
            if (vm->IsException())
            {
                vm->HandleException = false;
                vm->OutputError(vm->ExceptionObj);
                vm->ExceptionObj.SetUndefined();
                result = false;
            }
        }
    }
    else
        result = true;
    if (vmabc)
        static_cast<MovieDefRootNode*>(pspr->FindRootNode())->AbcFiles.PushBack(vmabc);
    return result;
}

// Value(const ASString&) (0x1424dbf70), Value(Object*) (0x1424dc050) and Multiname(Namespace&, const Value&)
// (0x1424d8a90) with SetRTNameUnsafe and PostProcessName, as the exe inlines them into FUN_142502e70 (the same
// bodies as the sfr_as3_17 / sfr_as3_19 copies).
SF_FORCEINLINE Value::Value(const ASString& v, InlineStrType)
    : Flags(kString)
    , value(v.GetNode())
{
    if (v.GetNode() == v.GetManager()->GetNullStringNode())
    {
        SetKind(kObject);
        value = (Object*)NULL;
    }
    else
        value.VS._1.VStr->AddRef();
}

SF_FORCEINLINE Value::Value(Object* v, InlineObjType)
    : Flags(kObject)
    , value(v)
{
    if (v)
        v->AddRef();
}

void Sfr27MultinameFromQName(Multiname* mn, const Value* qname);   // sfr_as3_19

// Value(Class*) (0x1424dc0e0) as the exe inlines it into CreateEmptyMovieClip: Value(Object*) with the class kind.
struct Sfr17dValueInline
{
    static SF_FORCEINLINE void SetClassKind(Value& v) { v.SetKind(Value::kClass); }
    static SF_FORCEINLINE void InitClass(Value& v, Class* cl)
    { Value::VU tmp(cl); cl->AddRef(); v.Flags = Value::kClass; v.value = tmp; }
    // Value::ReleaseInternal (0x142521f00) out of line, for a Value whose kind is known to be ref-counted.
    static SF_FORCEINLINE void Release(Value& v) { v.ReleaseInternal(); }
    // Value()'s Bonus init: the exe keeps the store, its kUndefined Flags store dies under InitClass.
    static SF_FORCEINLINE void ClearBonus(Value& v) { v.Bonus.pWeakProxy = NULL; }
};
// A Value slot with no destructor: released through Sfr17dValueInline::Release, as in the exe.
struct Sfr17dRawValue
{
    union { Value v; };
    Sfr17dRawValue() { Sfr17dValueInline::ClearBonus(v); }
    ~Sfr17dRawValue() {}
};
}}} // namespace Scaleform::GFx::AS3

// Value::operator=(const ASString&), out of line in the exe (defined in sfr_as3_19).
Scaleform::GFx::AS3::Value& FUN_1424e0d40(Scaleform::GFx::AS3::Value& v, const Scaleform::GFx::ASString& str);

namespace Scaleform { namespace GFx { namespace AS3 {
static __forceinline void Sfr17dPostProcessName(Multiname& mn)
{
    // SDK Multiname::PostProcessName(false) (AS3_Object.cpp): the manager is read before the switch on name[0]
    if (mn.Name.IsString())
    {
        const ASString n = mn.Name.AsString();
        if (!n.IsEmpty())
        {
            ASStringManager* sm = n.GetManager();
            switch (n[0])
            {
            case '@':
                mn.Kind = static_cast<Abc::MultinameKind>(mn.Kind | 8);
                if (n.GetSize() == 2 && n[1] == '*')
                    FUN_1424e0d40(mn.Name, ASString(sm->GetEmptyStringNode()));
                else
                    FUN_1424e0d40(mn.Name, ASString(n.SubstringNode(1, n.GetSize())));
                break;
            case '*':
                FUN_1424e0d40(mn.Name, ASString(sm->GetEmptyStringNode()));
                break;
            default:
                break;
            }
        }
    }
}

// Value::AssignUnsafe(const Value&) (0x1424edce0, defined in sfr_as3_17), which the exe inlines into the Multiname
// ctor: the same definition as sfr_as3_17's Sfr17ValueInline (a Value friend). Name is a fresh kUndefined Value
// there, so the Release folds away and only the prefetch, the copy and the AddRef remain.
struct Sfr17ValueInline
{
    static __forceinline void Assign(Value& self, const Value& other)
    {
        self.Release();
        SIMD::PrefetchObj(&other);
        memcpy(&self, &other, sizeof(Value));
        self.AddRef();
    }
};

__forceinline Multiname::Multiname(Instances::Namespace& ns, const Value& name, InlineCtorTag)
    : Kind(static_cast<Abc::MultinameKind>(0))
    , Obj(&ns)
{
    const UInt32 k = static_cast<UInt32>(name.GetKind());
    if (k - 0xc <= 3 && name.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(name.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
        {
            Sfr27MultinameFromQName(this, &name);
            return;
        }
    }
    Name.AssignUnsafe(name);
    Sfr17dPostProcessName(*this);
}

// The same, with AssignUnsafe inlined as FireEvent 0x142502e70 has it (AttachMovie 0x1424ede80 calls it).
__forceinline Multiname::Multiname(Instances::Namespace& ns, const Value& name, InlineAssignTag)
    : Kind(static_cast<Abc::MultinameKind>(0))
    , Obj(&ns)
{
    const UInt32 k = static_cast<UInt32>(name.GetKind());
    if (k - 0xc <= 3 && name.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(name.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
        {
            Sfr27MultinameFromQName(this, &name);
            return;
        }
    }
    Sfr17ValueInline::Assign(Name, name);
    Sfr17dPostProcessName(*this);
}
}}} // namespace Scaleform::GFx::AS3

// AvmDisplayObj: fires the display-list event id at the AS3 object (load, enter frame, the timeline instance's
// creation and parent property, its constructor, added / removed and the frame and activation broadcasts).
// MS2-FUNCTIONAL 0x142502e70: SDK case order and per-case as3obj; 1984 of 2001 bytes. Regalloc and slots differ (the exe keeps the name's kind in r12, shrink-wraps r12/r13/r15/xmm6, reads InstanceBasedName as a bit field and calls CreateASInstanceNoCtor without the false arg)
// The plain event ids past the sockets (gfx_eventid.h stops at Event_SockXML).
enum Sfr17dEventIds
{
    Sfr17dEvent_Added = 0x100000f, Sfr17dEvent_Removed, Sfr17dEvent_Activate, Sfr17dEvent_Deactivate, Sfr17dEvent_Render,
    Sfr17dEvent_Resize, Sfr17dEvent_FrameConstructed, Sfr17dEvent_ExitFrame
};

// @0x142502e70
void FUN_142502e70(void* pavm, const Scaleform::GFx::EventId& id)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    using namespace Scaleform::GFx::AS3;
    AvmDisplayObj* self = static_cast<AvmDisplayObj*>(pavm);
    SPtr<Instances::fl_display::DisplayObject> as3obj = self->GetAS3Obj();
    Instances::fl_events::EventDispatcher* pdisp = as3obj;
    MovieRoot* root;
    switch (id.Id)
    {
    case EventId::Event_Load:
        self->pDispObj->OnEventLoad();
        break;
    case Sfr17dEvent_Added:
        {
            root = static_cast<MovieRoot*>(self->pDispObj->pASRoot);
            // the SDK's per-case as3obj: GetAS3Obj() read again here
            Instances::fl_events::EventDispatcher* const as3o = self->GetAS3Obj();
            if (as3o && as3o->HasEventHandler(root->BuiltinsMgr.GetBuiltin(AS3Builtin_added), false) &&
                !self->GetAVM()->HandleException)
            {
                SPtr<Instances::fl_events::Event> evt = as3o->CreateEventObject(root->BuiltinsMgr.GetBuiltin(AS3Builtin_added), true, false);
                evt->Target = as3o;
                as3o->DispatchEventObject(evt, self->pDispObj);
            }
        }
        if (self->IsStageAccessible())
        {
            root = static_cast<MovieRoot*>(self->pDispObj->pASRoot);
            root->CheckAvm();
            if (!root->pAVM->HandleException)
            {
                root->CheckAvm();
                SPtr<Instances::fl_events::Event> evt = static_cast<Classes::fl_events::EventDispatcher*>(
                    root->pAVM->EventDispatcherClass.GetPtr())->CreateEventObject(root->BuiltinsMgr.GetBuiltin(AS3Builtin_addedToStage), false, false);
                self->PropagateEvent(*evt, false);
            }
        }
        break;
    case Sfr17dEvent_Removed:
        self->pDispObj->Depth = 0;
        {
            root = static_cast<MovieRoot*>(self->pDispObj->pASRoot);
            // the SDK's per-case as3obj: GetAS3Obj() read again here
            Instances::fl_events::EventDispatcher* const as3o = self->GetAS3Obj();
            if (as3o && as3o->HasEventHandler(root->BuiltinsMgr.GetBuiltin(AS3Builtin_removed), false) &&
                !self->GetAVM()->HandleException)
            {
                SPtr<Instances::fl_events::Event> evt = as3o->CreateEventObject(root->BuiltinsMgr.GetBuiltin(AS3Builtin_removed), true, false);
                evt->Target = as3o;
                as3o->DispatchEventObject(evt, self->pDispObj);
            }
        }
        if ((self->Flags & AvmDisplayObj::Flag_Unloaded) && !self->GetAVM()->HandleException)
        {
            root = static_cast<MovieRoot*>(self->pDispObj->pASRoot);
            root->CheckAvm();
            SPtr<Instances::fl_events::Event> evt = static_cast<Classes::fl_events::EventDispatcher*>(
                root->pAVM->EventDispatcherClass.GetPtr())->CreateEventObject(root->BuiltinsMgr.GetBuiltin(AS3Builtin_removedFromStage), false, false);
            self->PropagateEvent(*evt, false);
        }
        self->pDispObj->OnEventUnload();
        break;
    case EventId::Event_Construct:
        self->CallCtor(true);
        break;
    case EventId::Event_Initialize:
        if (self->pDispObj->Flags & DisplayObject::Mask_TimelineObject)
        {
            self->CreateASInstanceNoCtor(false);
            if (!(self->pDispObj->Flags & DisplayObject::Mask_InstanceBasedName) && self->GetAS3Parent())
            {
                const ASString& name = self->pDispObj->GetName();
                // the name's Value is built before GetAS3Parent() is called again, as in the exe
                const AS3::Value namev(name, AS3::Value::InlineStr);
                // SetProperty() can throw; the result is not checked (DoNotCheck).
                self->GetAS3Parent()->SetProperty(Multiname(static_cast<MovieRoot*>(self->pDispObj->pASRoot)->pAVM->GetPublicNamespace(),
                                                            namev, Multiname::InlineAssignTag()),
                                                  AS3::Value(self->GetAS3Obj(), AS3::Value::InlineObj));
                if (static_cast<MovieRoot*>(self->pDispObj->pASRoot)->pAVM->HandleException)
                {
                    static_cast<MovieRoot*>(self->pDispObj->pASRoot)->pAVM->OutputAndIgnoreException();
                    self->pDispObj->pParent->DisplayObject::Flags |= DisplayObject::Mask_ExecutionAborted;   // DisplayObject::Flags (+0x88), not InteractiveObject::Flags, as in the exe
                }
            }
        }
        break;
    case EventId::Event_EnterFrame:
        if (as3obj && pdisp->MayHaveEnterFrameHandler())
            pdisp->DispatchTypeToTarget(static_cast<MovieRoot*>(self->pDispObj->pASRoot)->BuiltinsMgr.GetBuiltin(AS3Builtin_enterFrame),
                                        as3obj, false, self->pDispObj);
        break;
    case Sfr17dEvent_FrameConstructed:
        if (as3obj && pdisp->MayHaveFrameConstructedHandler())
            pdisp->DispatchTypeToTarget(static_cast<MovieRoot*>(self->pDispObj->pASRoot)->BuiltinsMgr.GetBuiltin(AS3Builtin_frameConstructed),
                                        as3obj, false, self->pDispObj);
        break;
    case Sfr17dEvent_ExitFrame:
        if (as3obj && pdisp->MayHaveExitFrameHandler())
            pdisp->DispatchTypeToTarget(static_cast<MovieRoot*>(self->pDispObj->pASRoot)->BuiltinsMgr.GetBuiltin(AS3Builtin_exitFrame),
                                        as3obj, false, self->pDispObj);
        break;    case Sfr17dEvent_Activate:
        if (as3obj && pdisp->MayHaveActivateHandler())
            pdisp->Dispatch(id, self->pDispObj);
        break;
    case Sfr17dEvent_Deactivate:
        if (as3obj && pdisp->MayHaveDeactivateHandler())
            pdisp->Dispatch(id, self->pDispObj);
        break;
    case Sfr17dEvent_Render:
        if (as3obj && pdisp->MayHaveRenderHandler())
            pdisp->Dispatch(id, self->pDispObj);
        break;
    case Sfr17dEvent_Resize:
        if (as3obj)
            pdisp->Dispatch(id, self->pDispObj);
        break;
    }
}

void FUN_14252ecb0(void* vm, const void* error, const void* classInfo);   // VM: raise the error as an instance of the class

namespace Scaleform { namespace GFx { namespace AS3 {
namespace Instances { namespace fl_display { bool BindLibraryBitmap(BitmapData* pthis, Resource* pres, MovieDefImpl* pdefImpl); } }   // 0x142441730

// MS2-FUNCTIONAL 0x1424f2450: written from the exe's control flow (the exe inlines the Value and StringDataPtr temporaries)
// @0x1424f2450
bool AvmDisplayObj::CreateASInstanceNoCtor(bool)
{
    if (pAS3RawPtr || pAS3CollectiblePtr)
        return false;
    VM* pvm = static_cast<MovieRoot*>(pDispObj->pASRoot)->pAVM;
    if (!pvm)
        return false;
    bool result = false;
    String className;
    GetASClassName(&className);
    Value _this;
    Class* cls = pvm->GetClass(StringDataPtr(className.ToCStr(), className.GetSize()));
    if (!cls)
    {
        if (!pvm->HandleException)
        {
            const VM::Error e(VM::ErrorID(1065) /* eUndefinedVarError */, *pvm, className.ToCStr());
            FUN_14252ecb0(pvm, &e, &fl::ReferenceErrorCI);
        }
    }
    else
    {
        Value _class(cls);
        InstanceTraits::Traits& itr = cls->GetInstanceTraits();
        itr.MakeObject(_this, itr);
        Instances::fl_display::DisplayObject* pobj = static_cast<Instances::fl_display::DisplayObject*>(_this.GetObject());
        pobj->pDispObj = pDispObj;
        SetAS3ObjCollectible(pobj);
        if (cls->PreInit(_this))
        {
            pobj->InitInstance(true);
            return true;
        }
    }
    if (pvm->HandleException)
    {
        pvm->OutputAndIgnoreException();
        pDispObj->Flags |= DisplayObject::Mask_ExecutionAborted;
    }
    return result;
}

// CreateASInstanceNoCtor ignores its bool, and the exe's LTCG calls it without one: called through the shorter
// signature (the same symbol).
static SF_FORCEINLINE bool Sfr17dCreateNoCtor(AvmDisplayObj& avm)
{
    bool (AvmDisplayObj::*const pf)() = reinterpret_cast<bool (AvmDisplayObj::*)()>(&AvmDisplayObj::CreateASInstanceNoCtor);
    return (avm.*pf)();
}

// MS2-FUNCTIONAL 0x1424f2010: SDK nested ifs, written from the exe's control flow (the exe inlines AvmDisplayObj::CreateASInstance).
// Regalloc differs, the exe keeps the String in the high slot and the SPtr in the low one, and its SPtr dtor skips a marked
// pointer (no store back)
// @0x1424f2010
unsigned AvmBitmap::CreateASInstance(bool execute)
{
    // AvmDisplayObj::CreateASInstance (0x1424f2400), which the exe inlines here
    unsigned rv = 1;
    if (!AvmDisplayObj::GetAS3Obj())
        rv = (!pAS3RawPtr && !pAS3CollectiblePtr && Sfr17dCreateNoCtor(*this)) ? CallCtor(execute) : 0;
    if (AvmDisplayObj::GetAS3Obj())
    {
        Instances::fl_display::Bitmap* as3bmp = static_cast<Instances::fl_display::Bitmap*>(AvmDisplayObj::GetAS3Obj());
        if (!as3bmp->pBitmapData && pDispObj->GetResourceMovieDef())
        {
            // the bitmap data is the image's size
            Value params[2] = { Value(Value::Number(0)), Value(Value::Number(0)) };
            if (pImage && pImage->GetImage())
            {
                const Render::ImageSize sz = pImage->GetImage()->GetSize();
                params[0].Assign(Value(UInt32(sz.Width)));
                params[1].Assign(Value(UInt32(sz.Height)));
            }
            String name;
            const String* pname = pDispObj->GetResourceMovieDef()->GetNameOfExportedResource(ResourceId(pDispObj->Id));
            if (!pname)
                return rv;
            SPtr<Instances::fl_display::BitmapData> pbmpData;
            name = *pname;
            VM& vm = *static_cast<MovieRoot*>(pDispObj->pASRoot)->pAVM;
            if (vm.ConstructBuiltinObject(pbmpData, name.ToCStr(), 2, params))
            {
                Instances::fl_display::BindLibraryBitmap(pbmpData.GetPtr(), pImage.GetPtr(), pDispObj->GetResourceMovieDef());
                Value r;
                as3bmp->bitmapDataSet(r, pbmpData);
            }
        }
    }
    return rv;
}

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace AS3 {

// The host side's display object access to AS3 values, members of AS3ValueObjectInterface.
static inline MovieRoot* Sfr34_RootOf(MovieImpl* proot) { return static_cast<MovieRoot*>(proot->pASMovieRoot); }

// A MemberValueSet element: the member name and its value.
struct Sfr17dMemberValue
{
    String     Key;    // +0x00
    GFx::Value mValue; // +0x08
};
// The MemberValueSet array as AttachMovie reads it.
struct Sfr17dMemberValueSet
{
    const Sfr17dMemberValue* Data;
    UPInt                    Size;
};

// Whether the AS3 object is a display object (container, when containersOnly) instance.
static inline bool Sfr17d_IsDisplayObject(void* pdata, bool containersOnly)
{
    const Traits&  tr    = static_cast<Object*>(pdata)->GetTraits();
    const unsigned begin = containersOnly ? Traits_DisplayObjectContainer : Traits_DisplayObject_Begin;
    return (unsigned)(tr.GetTraitsType() - begin) < (unsigned)(Traits_DisplayObject_End - begin) &&
           tr.IsInstanceTraits();
}
static inline bool Sfr17d_IsDisplayObject(const Value& v)
{
    return Sfr17d_IsDisplayObject(v.GetObject(), false);
}
static inline AvmDisplayObjContainer* Sfr17d_ToAvmContainer(DisplayObject* p)
{
    return p ? AvmDisplayObjContainer::FromBase(p->GetAvmObjImpl()->ToAvmDispContainerBase()) : NULL;
}

} // namespace AS3

// Position, scales, rotations (pixels / percent / degrees), alpha, visibility, the field of view, the 3D matrices
// and the edge AA mode of a display object; a text field gives its own position fields.
// @0x1425094e0
bool AS3ValueObjectInterface::GetDisplayInfo(void* pdata, GFx::Value::DisplayInfo* pinfo) const
{
    using namespace AS3;
    using AS3::Value;
    if (!Sfr17d_IsDisplayObject(pdata, false))
        return false;
    DisplayObject* pdisp = static_cast<Instances::fl_display::DisplayObject*>(static_cast<Object*>(pdata))->pDispObj;
    if (!pdisp)
        return false;
    DisplayObjectBase::GeomDataType geomData;
    pdisp->GetGeomData(geomData);
    if (pdisp->GetType() == CharacterDef::TextField)
    {
        static_cast<TextField*>(pdisp)->GetPosition(pinfo);
    }
    else
    {
        Double x = Double(geomData.X) * 0.05;
        Double y = Double(geomData.Y) * 0.05;
        Double rotation = geomData.Rotation;
        Double xscale = geomData.XScale;
        Double yscale = geomData.YScale;
        Double alpha = reinterpret_cast<const float*>(&pdisp->GetCxform())[3] * 100.0f;
        bool visible = pdisp->GetVisible();
        Double xrotation = geomData.XRotation;
        Double yrotation = geomData.YRotation;
        Double zscale = geomData.ZScale;
        Double z = geomData.Z * 0.05;
        pinfo->Set(x, y, rotation, xscale, yscale, alpha, visible, z, xrotation, yrotation, zscale);
    }

    pinfo->SetFOV(pdisp->GetFOV());
    Matrix4F matProj;
    if (pdisp->GetProjectionMatrix3D(&matProj))
        pinfo->SetProjectionMatrix3D(&matProj);
    Matrix3F matView;
    if (pdisp->GetViewMatrix3D(&matView))
        pinfo->SetViewMatrix3D(&matView);

    Render::EdgeAAMode edgeaaMode = pdisp->GetRenderNode()->GetEdgeAAMode();
    pinfo->SetEdgeAAMode(edgeaaMode);

    return true;
}

namespace AS3 {

} // namespace AS3

// FUN_14252ecb0 on an Error temporary, as the exe passes the Error ctor's result.
static SF_FORCEINLINE void Sfr17dThrow(AS3::VM* vm, const AS3::VM::Error& e, const AS3::ClassInfo& ci)
{
    ::FUN_14252ecb0(vm, &e, &ci);
}

// VM::Construct(gname, result) (SDK AS3_VM.cpp), inline here as in the exe: true when code has to run.
static SF_FORCEINLINE bool Sfr17dConstruct(AS3::VM* vm, const char* gname, AS3::Value& result)
{
    using namespace AS3;
    using AS3::Value;
    const UPInt callStackSize = vm->Unk070[1];
    Sfr17dRawValue cb;
    Value& _class = cb.v;
    const StringDataPtr className(gname);
    Class* cls = vm->GetClass(className);
    if (cls)
    {
        Sfr17dValueInline::InitClass(_class, cls);
        if (_class.IsNullOrUndefined())
        {
            Sfr17dThrow(vm, VM::Error(VM::ErrorID(1009) /* eConvertNullToObjectError */, *vm), fl::TypeErrorCI);
            Sfr17dValueInline::Release(_class);
            return false;
        }
        _class.GetObject()->Construct(result, 0, NULL, false);
        if (vm->HandleException)
        {
            Sfr17dValueInline::Release(_class);
            return false;
        }
        const bool need = vm->Unk070[1] > callStackSize;
        Sfr17dValueInline::Release(_class);
        return need;
    }
    if (!vm->HandleException)
        Sfr17dThrow(vm, VM::Error(VM::ErrorID(1065) /* eUndefinedVarError */, *vm, className.ToCStr()),
                    fl::ReferenceErrorCI);
    return false;
}

// VM::CreateObject's tail (SDK AS3_VM.h): run the constructor code when needed; false on an exception.
static SF_FORCEINLINE bool Sfr17dCreateObject(AS3::VM* vm, bool needExecute)
{
    if (vm->HandleException)
        return false;
    if (needExecute)
        vm->ExecuteCode(1);
    return !vm->HandleException;
}

// VM::CreateObject(gname, result) (SDK AS3_VM.h), inline here as in the exe.
static SF_FORCEINLINE bool Sfr17dCreateObjectFull(AS3::VM* vm, const char* gname, AS3::Value& result)
{
    const bool needExecute = Sfr17dConstruct(vm, gname, result);
    return Sfr17dCreateObject(vm, needExecute);
}

// A new empty Sprite named instanceName at depth (the top when negative) of the container; its constructor runs
// right away.
// VM::Construct and CreateObject are inline here as in the exe. The class Value is a dtor-less slot set up in place
// (Value(Class*) inlined) and released out of line on each exit. The nameSet result lives to the end.
// MS2-FUNCTIONAL: one store scheduled apart: the exe sets the class Value's Flags (0xd) between the AddRef's inc and
// its store; written in that order here, cl re-reads Flags for IsNullOrUndefined (2 diffs)
// @0x1424f33d0
bool AS3ValueObjectInterface::CreateEmptyMovieClip(void* pdata, GFx::Value* pmc, const char* instanceName, SInt32 depth)
{
    using namespace AS3;
    using AS3::Value;
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
    if (!Sfr17d_IsDisplayObject(pdata, true))
        return false;
    DisplayObject* pcont = static_cast<Instances::fl_display::DisplayObject*>(static_cast<Object*>(pdata))->pDispObj;
    Value result;
    VM*   vm = root->pAVM;
    if (!Sfr17dCreateObjectFull(vm, "flash.display.Sprite", result))
        return false;
    if (!Sfr17d_IsDisplayObject(result))
        return false;
    Instances::fl_display::DisplayObject* pnew = static_cast<Instances::fl_display::DisplayObject*>(result.GetObject());
    Value r;
    pnew->nameSet(r, ASString(root->BuiltinsMgr.GetStringManager()->CreateStringNode(instanceName)));
    AvmDisplayObjContainer* cont = Sfr17d_ToAvmContainer(pcont);
    if (depth < 0)
        depth = SInt32(cont->GetDisplayObjContainer()->mDisplayList.GetCount());
    cont->AddChildAt(pnew->pDispObj, unsigned(depth));
    root->ASValue2GFxValue(result, pmc);
    return true;
}

namespace AS3 {

} // namespace AS3

// A new instance of the exported class symbolName named instanceName at depth (the top when negative or past it)
// of the container, with the initArgs members set; its constructor runs right away.
// MS2-FUNCTIONAL: 3 bytes short of the exe (1549 vs 1552); register allocation and slot layout differ (exe keeps pmc in r12, symbolName in r14)
// @0x1424ede80
bool AS3ValueObjectInterface::AttachMovie(void* pdata, GFx::Value* pmc, const char* symbolName, const char* instanceName,
                                     SInt32 depth, const MemberValueSet* initArgs)
{
    using namespace AS3;
    using AS3::Value;
    MovieRoot* root = Sfr34_RootOf(pMovieRoot);
    if (!Sfr17d_IsDisplayObject(pdata, true))
        return false;
    DisplayObject* pcont = static_cast<Instances::fl_display::DisplayObject*>(static_cast<Object*>(pdata))->pDispObj;
    Value result;
    VM*   vm = root->pAVM;
    const bool needExecute = vm->Construct(symbolName, result, 0, NULL, false);   // VM::CreateObject, inlined
    bool ok = false;
    if (!vm->HandleException)
    {
        if (needExecute) vm->ExecuteCode(1);
        ok = !vm->HandleException;
    }
    if (ok)
    {
        {
            if (!Sfr17d_IsDisplayObject(result))
                return false;
            Instances::fl_display::DisplayObject* pnew =
                static_cast<Instances::fl_display::DisplayObject*>(result.GetObject());
            Value r;
            pnew->nameSet(r, ASString(root->BuiltinsMgr.GetStringManager()->CreateStringNode(instanceName)));
            const Sfr17dMemberValueSet* args = reinterpret_cast<const Sfr17dMemberValueSet*>(initArgs);
            if (args)
            {
                for (unsigned i = 0; i < args->Size; ++i)
                {
                    const Sfr17dMemberValue& mv = args->Data[i];
                    const Multiname mn(root->pAVM->GetPublicNamespace(),
                                       Value(ASString(root->BuiltinsMgr.GetStringManager()->CreateStringNode(mv.Key.ToCStr(),
                                                                                                    mv.Key.GetSize())),
                                             Value::InlineStr),
                                       Multiname::InlineAssignTag());
                    Value v;
                    root->GFxValue2ASValue(mv.mValue, &v);
                    pnew->SetProperty(mn, v);
                }
            }
            AvmDisplayObjContainer* cont  = Sfr17d_ToAvmContainer(pcont);
            const SInt32            count = SInt32(cont->GetDisplayObjContainer()->mDisplayList.GetCount());
            if (depth > count)
            {
                if (Ptr<LogState> plog = root->GetMovieImpl()->GetLogState())
                    plog->LogScriptWarning("DAPI AttachMovie() depth requested (%d) for symbol \"%s\" is too large. "
                                           "Using next highest index (%d) instead.",
                                           depth, symbolName, count);
            }
            if (depth < 0 || depth > count)
                depth = count;
            cont->AddChildAt(pnew->pDispObj, unsigned(depth));
            root->ASValue2GFxValue(result, pmc);
            return true;
        }
    }
    if (Ptr<LogState> plog = root->GetMovieImpl()->GetLogState())
        plog->LogScriptWarning("attachMovie() failed - export name \"%s\" is not found.", symbolName);
    vm->HandleException = false;
    return false;
}

namespace AS3 {

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ??_7File@Abc@AS3@GFx@Scaleform@@6B@ 0x14317b050
// MS2-PIN: ??_7AbcFileWithMovieDef@ASVM@AS3@GFx@Scaleform@@6B@ 0x14317d8a8
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7GASRefCountBase@AS3@GFx@Scaleform@@6B@ 0x14313f398
// MS2-PIN: ??_7FileLoader@AS3@GFx@Scaleform@@6B@ 0x14317b798
// MS2-PIN: ??_7Sfr33NullFileLoader@AS3@GFx@Scaleform@@6B@ 0x14317f470
// MS2-PIN: ??_7XMLSupport@AS3@GFx@Scaleform@@6B@ 0x14317b7b8
// MS2-PIN: ??_7XMLSupportImpl@AS3@GFx@Scaleform@@6B@ 0x14317f9e0
// MS2-PIN: ??_7Stage@AS3@GFx@Scaleform@@6B?$RefCountBaseWeakSupport@VDisplayObjectBase@GFx@Scaleform@@$0BEC@@3@@ 0x14317d220
// MS2-PIN: ??_7Stage@AS3@GFx@Scaleform@@6B?$LogBase@VDisplayObjectBase@GFx@Scaleform@@@23@@ 0x14317d5f0
// MS2-PIN: ??_7ShapeDataInterface@Render@Scaleform@@6B@ 0x14317b678
// MS2-PIN: ??_7?$RefCountBase@VComplexFill@Render@Scaleform@@$01@Scaleform@@6B@ 0x14317b660
// MS2-PIN: ??_7ComplexFill@Render@Scaleform@@6B@ 0x14317b668
// MS2-PIN: ??_7?$ShapeDataFloatTempl@V?$Array@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@6B@ 0x14317bb40
// MS2-PIN: ??_7ShapeDataFloat@Render@Scaleform@@6B@ 0x14317bb98
// MS2-PIN: ??_G?$ShapeDataFloatTempl@V?$Array@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@UEAAPEAXI@Z 0x1424e20e0
// MS2-PIN: ??_GAbcFileWithMovieDef@ASVM@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2390
// MS2-PIN: ??_GComplexFill@Render@Scaleform@@UEAAPEAXI@Z 0x1424e2c10
// MS2-PIN: ??_GFile@Abc@AS3@GFx@Scaleform@@UEAAPEAXI@Z 0x1424e2d20
// MS2-PIN: ??_GShapeDataFloat@Render@Scaleform@@UEAAPEAXI@Z 0x1424e37a0
