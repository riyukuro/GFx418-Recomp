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
// MS2-RANGE: 0x1424f6f50-0x1424f7190 .text$mn
// MS2-RANGE: 0x1424f9570-0x1424f96c0 .text$mn
// MS2-RANGE: 0x1424f9d60-0x1424fa320 .text$mn
// MS2-RANGE: 0x1424fe620-0x1424feab0 .text$mn
// MS2-RANGE: 0x142500770-0x1425008e0 .text$mn
// MS2-RANGE: 0x142501920-0x142501a80 .text$mn
// MS2-RANGE: 0x142502e70-0x142503660 .text$mn
// MS2-RANGE: 0x142507730-0x1425078e0 .text$mn
// MS2-RANGE: 0x142507910-0x142507a40 .text$mn
// MS2-RANGE: 0x1425094e0-0x142509850 .text$mn
#define SF_AS3_SHAPEOBJECT_MODEL
#define SF_AS3_AVMBUTTON_MODEL
#include <math.h>
#include <stdlib.h>
#include "ms2/scaleform/include/kernel/sf_std.h"
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
#undef GetObject   // windows.h

bool FUN_1424f27b0(Scaleform::GFx::AS3::AvmBitmap* self);   // AvmBitmap: the image shape of the render node
void FUN_142524990(void* arr, void* policy, Scaleform::UPInt n);   // ArrayDH<Ptr<InteractiveObject> >::Resize, out of line
namespace Scaleform { namespace GFx { void* FUN_14261e310(); } }   // the AMP server (AmpServer::GetInstance)
// A collector record: a counted object and a second word.
struct Sfr17dCollectorEntry
{
    Sfr17dCollectorEntry() : pExtra(NULL) {}
    Scaleform::Ptr<Scaleform::RefCountImpl> pObject;
    void*                                   pExtra;
};
void FUN_1423de770(void* self, const Sfr17dCollectorEntry& e);   // the collector's queue: adds a record
void FUN_142504630(void* gc, void* stats);   // ASRefCountCollector: queues a collection with the AMP stats
void FUN_1424efab0(void* pages);   // ArrayPagedLH_POD<RefCountBaseGC*>::ClearAndRelease

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

// MS2-FUNCTIONAL 0x142501920: the loop index starts from a copied zero register (mov edi,ebx) where the exe uses xor
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

// MS2-FUNCTIONAL 0x1424f6f50: the exe inlines GetRenderNode differently and re-reads the array data pointer
// @0x1424f6f50
bool AvmButton::DetachChild(DisplayObjectBase* ch)
{
    bool found = false;
    Button* pbtn = GetButton();
    for (unsigned state = 0; state < 3; ++state)
    {
        auto& chars = pbtn->GetCharacters((Button::ButtonState)state);
        Ptr<Render::TreeContainer> prenNode = chars.pRenNode;
        for (UPInt i = 0, n = chars.Characters.GetSize(); i < n; ++i)
        {
            if (chars.Characters[i].Char != ch)
                continue;
            ch->pParent = NULL;
            if (ch->GetRenderNode())
            {
                Render::TreeContainer* pparent = static_cast<Render::TreeContainer*>(ch->GetRenderNode()->GetParent());
                if (pparent)
                {
                    for (UPInt j = 0, cnt = pparent->GetSize(); j < cnt; ++j)
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
// MS2-FUNCTIONAL 0x1424f27b0: the exe calls the shape data's EndPath / EndShape out of line; our header inlines them
// @0x1424f27b0
bool FUN_1424f27b0(Scaleform::GFx::AS3::AvmBitmap* self)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx;
    Render::TreeShape* tshp = static_cast<Render::TreeShape*>(self->pRenNode.GetPtr());
    Ptr<Render::ShapeDataFloat> shapeData = *SF_HEAP_AUTO_NEW(self) Render::ShapeDataFloat();
    Ptr<Render::ComplexFill> complexFill = *SF_HEAP_AUTO_NEW(self) Render::ComplexFill();
    if (!self->pImage)
    {
        shapeData->StartPath(0, 0, 0);
        shapeData->MoveTo(0, 0);
        shapeData->LineTo(1.0f, 1.0f);
        shapeData->ClosePath();
        shapeData->EndPath();
        shapeData->EndShape();
        Ptr<Render::ShapeMeshProvider> prov = *SF_HEAP_AUTO_NEW(self) Render::ShapeMeshProvider(shapeData);
        tshp->SetShape(prov);
        return true;
    }

    Ptr<Render::Image> img;
    if (self->pImage->GetImage()->GetImageType() != Render::ImageBase::Type_ImageBase)
        img = static_cast<Render::Image*>(self->pImage->GetImage());
    else
    {
        MovieImpl* pmovie = static_cast<DisplayObjectBase*>(self)->GetMovieImpl();
        ImageCreator* pcreator = Ptr<ImageCreator>(*(ImageCreator*)pmovie->GetStateBag()->GetStateAddRef(State::State_ImageCreator));
        if (!pcreator)
        {
            LogDebugMessage(Log_Warning, "Image is not created: can't find ImageCreator.");
            return false;
        }
        ImageCreateInfo cinfo(ImageCreateInfo::Create_SourceImage, static_cast<DisplayObjectBase*>(self)->GetMovieImpl()->GetMovieHeap(), 1,
                              Resource::Use_Bitmap);
        img = *pcreator->CreateImage(cinfo, (Render::ImageSource*)self->pImage->GetImage());
    }
    complexFill->pImage = img;
    if (!img)
    {
        LogDebugMessage(Log_Warning, "Image is not created.");
        return false;
    }
    complexFill->ImageMatrix.SetIdentity();
    complexFill->ImageMatrix.AppendScaling(0.05f);
    complexFill->FillMode = Render::ImageFillMode(Render::Wrap_Clamp, Render::Sample_Point);
    AS3::Instances::fl_display::Bitmap* pbmp = static_cast<AS3::Instances::fl_display::Bitmap*>(self->GetAS3Obj());
    if (!pbmp || pbmp->Smoothing)
        complexFill->FillMode = Render::ImageFillMode(Render::Wrap_Clamp, Render::Sample_Linear);

    Render::ImageRect irect = img->GetRect();
    Render::Matrix2F m;
    img->GetMatrix(&m);
    RectF r(0);
    m.EncloseTransform(&r, RectF(float(irect.x1), float(irect.y1), float(irect.x2), float(irect.y2)));

    Render::FillStyleType fill;
    fill.Color = 0;
    fill.pFill = complexFill;
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
        Sfr17dCollectorEntry e;
        FUN_1423de770(gc, e);
        *reinterpret_cast<unsigned*>(gc + 0x88) = 0;
        *reinterpret_cast<unsigned*>(gc + 0x94) = count;
        *reinterpret_cast<unsigned*>(gc + 0x90) = Alg::Max(*reinterpret_cast<unsigned*>(gc + 0x90), count);
        if (gc[0x78] & 0x10)
            gc[0xb0] = 1;
    }
    if (!(gc[0x78] & 2) && *reinterpret_cast<UPInt*>(gc + 0x18) == 0)
        FUN_1424efab0(gc + 0x10);
    *reinterpret_cast<unsigned*>(gc + 0x8c) = *reinterpret_cast<unsigned*>(gc + 0xa8);
    *reinterpret_cast<unsigned*>(gc + 0x90) = 0;
}

// MemoryContextImpl::HeapLimit::Collect: flushes the text format caches, collects (with the AMP stats of the movie
// on this heap, if AMP knows it) and notes the footprint after the collection (+0x20).
// MS2-FUNCTIONAL 0x1424f03f0: HeapLimit's members are private; reached by offset
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
            FUN_142504630(gc, stats);
            if (!(gc[0x78] & 2) && *reinterpret_cast<UPInt*>(gc + 0x18) == 0)
                FUN_1424efab0(gc + 0x10);
            *reinterpret_cast<unsigned*>(gc + 0x90) = 0;
            *reinterpret_cast<unsigned*>(gc + 0x8c) = *reinterpret_cast<unsigned*>(gc + 0xa8);
        }
        pmovie->Release();
    }
    else
        Sfr17dEmergencyCollect(reinterpret_cast<UByte*>((*reinterpret_cast<MemoryContextImpl**>(self + 0x10))->ASGC.GetPtr()));
    *reinterpret_cast<UPInt*>(self + 0x20) = heap->GetFootprint();
}

// MS2-FUNCTIONAL 0x1424f9570: the exe inlines the XMLSupportImpl constructor (its vftable and three class allocations)
// @0x1424f9570
// VM::EnableXMLSupport: the E4X classes of the VM.
void FUN_1424f9570(VM* vm)
{
    vm->XMLSupport_ = Pickable<XMLSupport>(SF_HEAP_NEW(vm->MHeap) XMLSupportImpl(*vm));
}

namespace Scaleform { namespace GFx { namespace AS3 {

// Creates every record's character in each state it shows in: under the state's container sprite (made once,
// character 0x10001, and put on the play list), with the record's placement; the current state's container goes
// into the button's render tree.
// MS2-FUNCTIONAL 0x1424f2e90: register allocation differs (the exe re-reads the button through this each time)
// @0x1424f2e90
void AvmButton::CreateCharacters()
{
    Button*          pbtn     = GetButton();
    ButtonDef*       pdef     = pbtn->GetButtonDef();
    Button::ButtonState curState = pbtn->GetCurrentState();
    for (UPInt i = 0, n = pdef->GetRecordsCount(); i < n; i++)
    {
        const ButtonRecord& rec = pdef->GetRecordAt(i);
        for (UByte mask = 1; mask & ButtonRecord::Mask_All; mask <<= 1)
        {
            if (!(rec.Flags & mask))
                continue;
            Button::ButtonState state;
            if (mask & ButtonRecord::Mask_Up)
                state = Button::Up;
            else if (mask & ButtonRecord::Mask_Down)
                state = Button::Down;
            else if (mask & ButtonRecord::Mask_Over)
                state = Button::Over;
            else if (mask & ButtonRecord::Mask_HitTest)
                state = Button::Hit;
            else
                state = Button::Up;
            Button::StateCharArray&    chars    = pbtn->GetCharacters(state).Characters;
            Ptr<Render::TreeContainer> prenNode = pbtn->GetStateRenderContainer(state);
            if (!prenNode)
                prenNode = pbtn->CreateStateRenderContainer(state);
            Ptr<InteractiveObject> pobj;
            if (chars.GetSize() == 0)
            {
                CharacterCreateInfo ccinfo = GetButton()->pDefImpl->GetCharacterCreateInfo(ResourceId(0x10001));
                ASMovieRootBase*    proot  = GetButton()->pASRoot;
                Ptr<DisplayObjectBase> ch = *proot->pASSupport->CreateCharacterInstance(
                    proot->GetMovieImpl(), ccinfo, NULL, rec.CharacterId, CharacterDef::Unknown);
                pobj = ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(ch.GetPtr()) : NULL;
                Button::CharToRec cr;
                cr.Char   = pobj.GetPtr();
                cr.Record = &rec;
                chars.PushBack(cr);
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
                pobj = ch->IsInteractiveObject() ? static_cast<InteractiveObject*>(ch) : NULL;
            }
            CharacterCreateInfo ccinfo = GetButton()->pDefImpl->GetCharacterCreateInfo(rec.CharacterId);
            if (ccinfo.pCharDef)
            {
                CharPosInfo pos;
                pos.ColorTransform = rec.ButtonCxform;
                pos.Matrix_1       = rec.ButtonMatrix;
                pos.Depth          = rec.Depth;
                pos.CharacterId    = rec.CharacterId;
                pos.Flags.Flags    = CharPosInfoFlags::Flags_HasDepth | CharPosInfoFlags::Flags_HasCharacterId |
                                     CharPosInfoFlags::Flags_HasMatrix | CharPosInfoFlags::Flags_HasCxform |
                                     CharPosInfoFlags::Flags_HasBlendMode;
                pos.BlendMode      = (UByte)rec.BlendMode;
                ASString name = GetAS3Root()->BuiltinsMgr.CreateEmptyString();
                DisplayObjectBase* pnew = static_cast<DisplayObjContainer*>(pobj.GetPtr())->AddDisplayObject(
                    pos, name, NULL, NULL, 0, 4, NULL, NULL);
                if (pnew && rec.pFilters)
                    pnew->SetFilters(rec.pFilters);
            }
            if (state == curState && !prenNode->GetParent())
            {
                Render::TreeContainer* pcont = pbtn->GetRenderContainer();
                pcont->Insert(pcont->GetSize(), prenNode);
            }
        }
    }
}

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// The stage's AVM part (an AvmDisplayObjContainer with the stage's overrides, 0x48 bytes) has no class model yet:
// it is built in place by the AvmInteractiveObj constructor and its three vftables are stored.
extern void* const AvmStage_vftable[];
extern void* const AvmStage_vftable_30[];
extern void* const AvmStage_vftable_40[];
}}}
bool FUN_142531f40(AS3::VM& vm, AS3::SPtr<AS3::Object>& pobj, AS3::Object* classObj, unsigned argc, const AS3::Value* argv);   // ASVM::_constructInstance

// MS2-FUNCTIONAL 0x1424f4000: the stage's AVM part is built in place (no class model); the exe inlines the Stage constructor and InsertEntry
// @0x1424f4000
// MovieRoot::CreateStage: the stage and its AVM part in one allocation; its load event goes first in the queue.
void FUN_1424f4000(MovieRoot* proot, MovieDefImpl* pmovieDef)
{
    void*  pmem   = proot->GetMovieImpl()->pHeap->Alloc(sizeof(Stage) + 0x48);
    Stage* pstage = pmem ? new (pmem) Stage(pmovieDef, proot, NULL, ResourceId(0x40000)) : NULL;
    if (proot->pStage)
        proot->pStage->Release();
    proot->pStage = pstage;
    if (UByte* pavm = static_cast<UByte*>(pmem) + sizeof(Stage))
    {
        new (pavm) AvmInteractiveObj(pstage);
        *reinterpret_cast<void* const**>(pavm + 0x00) = AvmStage_vftable;
        *reinterpret_cast<void* const**>(pavm + 0x30) = AvmStage_vftable_30;
        *reinterpret_cast<void* const**>(pavm + 0x40) = AvmStage_vftable_40;
    }
    proot->ActionQueue.InsertEntry(MovieRoot::AL_Highest)->SetAction(proot->pStage, EventId(EventId::Event_Load));
}

namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL 0x1424fe620: written from the exe's control flow (register allocation and the inlined LoaderInfo content assignment differ)
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
    root->SetName(ASString(GetStringManager()->CreateConstString("root1")));

    pRoot = root;
    SetFOV(55.0);
    root->SetFOV(55.0);
    Ptr<Render::TreeContainer> node = GetRenderContainer();
    mDisplayList.AddEntryAtIndex(this, mDisplayList.GetCount(), root);
    static_cast<Render::TreeContainer*>(pmovie->pRenderRoot)->Insert(0, node);
    root->pParent = this;
    root->AddToPlayList();

    as3root->ASFramesToExecute += ToAvmDisplayObj(this)->CreateASInstance(false);
    as3root->ASFramesToExecute += ToAvmDisplayObj(root)->CreateASInstance(false);

    VM&        vm  = *as3root->pAVM;
    SPtr<Class> cls = vm.GetClass(StringDataPtr("flash.display.LoaderInfo"));
    if (cls)
    {
        SPtr<Instances::fl_display::LoaderInfo> li;
        if (FUN_142531f40(vm, reinterpret_cast<SPtr<Object>&>(li), cls, 0, NULL))
        {
            if (Instances::fl_display::DisplayObject* pas3obj = ToAvmDisplayObj(root)->GetAS3Obj())
            {
                pas3obj->SetLoaderInfo(li);
                li->Content = ToAvmDisplayObj(root)->GetAS3Obj();
            }
        }
    }

    root->ExecuteFrame0Events();
    as3root->ExecuteActionQueue(MovieRoot::AL_Highest);
    as3root->ExecuteActionQueue(MovieRoot::AL_High);
    while (unsigned n = as3root->ASFramesToExecute)
    {
        as3root->ASFramesToExecute = 0;
        VM& avm = *as3root->pAVM;
        avm.ExecuteCode(n);
        if (avm.HandleException)
        {
            avm.HandleException = false;
            avm.OutputError(avm.ExceptionObj);
            avm.ExceptionObj.SetUndefined();
            FrameCounterObj->DisplayObject::Flags |= DisplayObject::Mask_ExecutionAborted;
        }
    }
    ToAvmDisplayObj(root)->OnAdded(true);
    pmovie->Flags |= MovieImpl::Flag_OptAdvListInvalid;
    FrameCounterObj->AdvanceFrame(true, 0.0f);
    as3root->ExecuteActionQueue(MovieRoot::AL_Frame);
}

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace AS3 {

// MS2-FUNCTIONAL 0x1424f9d60: written from the exe's control flow (the exe inlines CheckAvm and the loaded-file lookup's SPtr copies)
// @0x1424f9d60
// A file already loaded under the same name ("file[name]") is reused; otherwise the block is parsed and its classes
// and scripts registered. Either way the movie's root node keeps the file alive.
bool MovieRoot::ExecuteAbc(const AbcDataBuffer* pabc, DisplayObjContainer* pspr)
{
    MovieDefImpl* pdefImpl = pspr->GetResourceMovieDef();
    String fileName(pabc->FileName);
    if (pabc->Name.GetSize() != 0)
    {
        fileName.AppendString("[");
        fileName += pabc->Name;
        fileName.AppendString("]");
    }

    bool            result = false;
    SPtr<VMAbcFile> vmabc;
    const UPInt nfiles = pAVM ? pAVM->VMAbcFilesWeak.GetSize() : 0;
    for (UPInt i = 0; i < nfiles; ++i)
    {
        if (strcmp(pAVM->VMAbcFilesWeak[i]->GetAbcFile().Source.ToCStr(), fileName.ToCStr()) == 0)
        {
            vmabc  = pAVM->VMAbcFilesWeak[i];
            result = true;
            break;
        }
    }
    if (!vmabc)
    {
        MemoryHeap*  pheap   = GetMovieImpl()->GetMovieHeap();
        Abc::Reader* preader = SF_HEAP_NEW(pheap) Abc::Reader(pabc->Data, pabc->DataSize);
        Ptr<Abc::File> file  = *SF_HEAP_NEW(pheap) ASVM::AbcFileWithMovieDef(pdefImpl, const_cast<AbcDataBuffer*>(pabc));
        file->Source   = fileName;
        file->DataSize = pabc->DataSize;
        result = preader->Read(*file);
        if (result)
        {
            CheckAvm();
            VM& vm = *pAVM;
            SPtr<VMAbcFile> pfile = Pickable<VMAbcFile>(SF_HEAP_NEW(vm.GetMemoryHeap()) VMAbcFile(vm, file));
            if (pfile->RegisterUserDefinedClassTraits() && pfile->RegisterScrips(false))
                vmabc = pfile;
            if (vm.HandleException)
            {
                vm.HandleException = false;
                vm.OutputError(vm.ExceptionObj);
                vm.ExceptionObj.SetUndefined();
                result = false;
            }
        }
        delete preader;
    }
    if (vmabc)
        static_cast<MovieDefRootNode*>(pspr->FindRootNode())->AbcFiles.PushBack(vmabc);
    return result;
}

}}} // namespace Scaleform::GFx::AS3


// AvmDisplayObj: fires the display-list event id at the AS3 object (load, enter frame, the timeline instance's
// creation and parent property, its constructor, added / removed and the frame and activation broadcasts).
// MS2-FUNCTIONAL 0x142502e70: written from the exe's control flow (the exe inlines the Multiname and Value constructors)
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
    case EventId::Event_EnterFrame:
        if (!as3obj)
            return;
        if (pdisp->MayHaveEnterFrameHandler())
            pdisp->DispatchTypeToTarget(static_cast<MovieRoot*>(self->pDispObj->pASRoot)->BuiltinsMgr.GetBuiltin(AS3Builtin_enterFrame),
                                        as3obj, false, self->pDispObj);
        break;
    case EventId::Event_Initialize:
    {
        DisplayObject* pdispObj = self->pDispObj;
        if (!(pdispObj->Flags & DisplayObject::Mask_TimelineObject))
            break;
        self->CreateASInstanceNoCtor(false);
        if ((pdispObj->Flags & DisplayObject::Mask_InstanceBasedName) || !self->GetAS3Parent())
            break;
        // the timeline object is the parent's property of its name
        ASString name = pdispObj->GetName();
        {
            AS3::Value vname(name);
            Instances::fl::Object* parent = self->GetAS3Parent();
            AS3::Value vobj(as3obj.GetPtr());
            VM& vm = *static_cast<MovieRoot*>(pdispObj->pASRoot)->pAVM;
            Multiname mn(vm.GetPublicNamespace(), vname);
            parent->SetProperty(mn, vobj);
        }
        VM& vm = *static_cast<MovieRoot*>(self->pDispObj->pASRoot)->pAVM;
        if (vm.HandleException)
        {
            vm.OutputAndIgnoreException();
            self->pDispObj->pParent->Flags |= DisplayObject::Mask_ExecutionAborted;
        }
        break;
    }
    case EventId::Event_Construct:
        self->CallCtor(true);
        break;
    case Sfr17dEvent_Added:
        root = static_cast<MovieRoot*>(self->pDispObj->pASRoot);
        if (pdisp && pdisp->HasEventHandler(root->BuiltinsMgr.GetBuiltin(AS3Builtin_added), false) &&
            !self->GetAVM()->HandleException)
        {
            SPtr<Instances::fl_events::Event> evt = pdisp->CreateEventObject(root->BuiltinsMgr.GetBuiltin(AS3Builtin_added), true, false);
            evt->Target = pdisp;
            pdisp->DispatchEventObject(evt, self->pDispObj);
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
        root = static_cast<MovieRoot*>(self->pDispObj->pASRoot);
        if (pdisp && pdisp->HasEventHandler(root->BuiltinsMgr.GetBuiltin(AS3Builtin_removed), false) &&
            !self->GetAVM()->HandleException)
        {
            SPtr<Instances::fl_events::Event> evt = pdisp->CreateEventObject(root->BuiltinsMgr.GetBuiltin(AS3Builtin_removed), true, false);
            evt->Target = pdisp;
            pdisp->DispatchEventObject(evt, self->pDispObj);
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
    case Sfr17dEvent_Activate:
        if (!as3obj)
            return;
        if (pdisp->MayHaveActivateHandler())
            pdisp->Dispatch(id, self->pDispObj);
        break;
    case Sfr17dEvent_Deactivate:
        if (!as3obj)
            return;
        if (pdisp->MayHaveDeactivateHandler())
            pdisp->Dispatch(id, self->pDispObj);
        break;
    case Sfr17dEvent_Render:
        if (!as3obj)
            return;
        if (pdisp->MayHaveRenderHandler())
            pdisp->Dispatch(id, self->pDispObj);
        break;
    case Sfr17dEvent_Resize:
        if (!as3obj)
            return;
        pdisp->Dispatch(id, self->pDispObj);
        break;
    case Sfr17dEvent_FrameConstructed:
        if (!as3obj)
            return;
        if (pdisp->MayHaveFrameConstructedHandler())
            pdisp->DispatchTypeToTarget(static_cast<MovieRoot*>(self->pDispObj->pASRoot)->BuiltinsMgr.GetBuiltin(AS3Builtin_frameConstructed),
                                        as3obj, false, self->pDispObj);
        break;
    case Sfr17dEvent_ExitFrame:
        if (!as3obj)
            return;
        if (pdisp->MayHaveExitFrameHandler())
            pdisp->DispatchTypeToTarget(static_cast<MovieRoot*>(self->pDispObj->pASRoot)->BuiltinsMgr.GetBuiltin(AS3Builtin_exitFrame),
                                        as3obj, false, self->pDispObj);
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

// MS2-FUNCTIONAL 0x1424f2010: written from the exe's control flow (the exe inlines AvmDisplayObj::CreateASInstance)
// @0x1424f2010
unsigned AvmBitmap::CreateASInstance(bool execute)
{
    unsigned rv = AvmDisplayObj::GetAS3Obj() ? 1 : AvmDisplayObj::CreateASInstance(execute);
    Instances::fl_display::Bitmap* as3bmp = static_cast<Instances::fl_display::Bitmap*>(AvmDisplayObj::GetAS3Obj());
    if (!as3bmp || as3bmp->pBitmapData || !GetResourceMovieDef())
        return rv;
    // the bitmap data is the image's size
    Value params[2] = { Value(Value::Number(0)), Value(Value::Number(0)) };
    if (pImage && pImage->GetImage())
    {
        const Render::ImageSize sz = pImage->GetImage()->GetSize();
        params[0].Assign(Value(UInt32(sz.Width)));
        params[1].Assign(Value(UInt32(sz.Height)));
    }
    SPtr<Instances::fl_display::BitmapData> pbmpData;
    String name;
    const String* pname = GetResourceMovieDef()->GetNameOfExportedResource(ResourceId(Id));
    if (!pname)
        return rv;
    name = *pname;
    VM& vm = *static_cast<MovieRoot*>(pASRoot)->pAVM;
    if (vm.ConstructBuiltinObject(pbmpData, name.ToCStr(), 2, params))
    {
        Instances::fl_display::BindLibraryBitmap(pbmpData.GetPtr(), pImage.GetPtr(), GetResourceMovieDef());
        Value r;
        as3bmp->bitmapDataSet(r, pbmpData);
    }
    return rv;
}

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace AS3 {

// The host side's display object access to AS3 values. The ObjectInterface subclass (AS3ValueObjectInterface,
// vftable 0x14317eff8) is sfr_as3_17's; the slots recovered here are members of a view over it.
class Sfr34d_ValueObjIfc : public GFx::Value::ObjectInterface
{
public:
    MovieRoot* GetAS3Root() const { return static_cast<MovieRoot*>(pMovieRoot->pASMovieRoot); }

    bool GetDisplayInfo(void* pdata, GFx::Value::DisplayInfo* pinfo) const;
    bool CreateEmptyMovieClip(void* pdata, GFx::Value* pmc, const char* instanceName, SInt32 depth);
    bool AttachMovie(void* pdata, GFx::Value* pmc, const char* symbolName, const char* instanceName, SInt32 depth,
                     const MemberValueSet* initArgs);
};

// GFx::Value::DisplayInfo as this build lays it out (the class is opaque in gfx_value.h).
struct Sfr17dDisplayInfo
{
    Double   X, Y;            // +0x00 pixels
    Double   Rotation;        // +0x10
    Double   XScale, YScale;  // +0x18
    Double   Alpha;           // +0x28 percent
    bool     Visible;         // +0x30
    Double   Z;               // +0x38 pixels
    Double   XRotation;       // +0x40
    Double   YRotation;       // +0x48
    Double   ZScale;          // +0x50
    Double   FOV;             // +0x58
    Matrix3F ViewMatrix3D;    // +0x60
    Matrix4F ProjectionMatrix3D; // +0x90
    UInt32   EdgeAAMode;      // +0xd0
    UInt16   VarsSet;         // +0xd4 V_* bits of the fields set
};
static_assert(offsetof(Sfr17dDisplayInfo, ViewMatrix3D) == 0x60, "DisplayInfo::ViewMatrix3D");
static_assert(offsetof(Sfr17dDisplayInfo, ProjectionMatrix3D) == 0x90, "DisplayInfo::ProjectionMatrix3D");
static_assert(offsetof(Sfr17dDisplayInfo, VarsSet) == 0xd4, "DisplayInfo::VarsSet");

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

// Position, scales, rotations (pixels / percent / degrees), alpha, visibility, the field of view, the 3D matrices
// and the edge AA mode of a display object; a text field gives its own position fields.
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's); DisplayInfo written through a layout view
// @0x1425094e0
bool Sfr34d_ValueObjIfc::GetDisplayInfo(void* pdata, GFx::Value::DisplayInfo* pinfo) const
{
    if (!Sfr17d_IsDisplayObject(pdata, false))
        return false;
    DisplayObject* pdisp = static_cast<Instances::fl_display::DisplayObject*>(static_cast<Object*>(pdata))->pDispObj;
    if (!pdisp)
        return false;
    Sfr17dDisplayInfo* info = reinterpret_cast<Sfr17dDisplayInfo*>(pinfo);
    DisplayObjectBase::GeomDataType geom;
    pdisp->GetGeomData(geom);
    if (pdisp->GetType() == CharacterDef::TextField)
        static_cast<TextField*>(pdisp)->GetPosition(pinfo);
    else
    {
        const Double x = Double(geom.X) * 0.05;
        const Double y = Double(geom.Y) * 0.05;
        const float  alpha = reinterpret_cast<const float*>(&pdisp->GetCxform())[3] * 100.0f;
        info->Visible   = pdisp->GetVisible();
        info->VarsSet  |= 0x7ff;
        info->X         = x;
        info->Z         = geom.Z * 0.05;
        info->XRotation = geom.XRotation;
        info->YRotation = geom.YRotation;
        info->Y         = y;
        info->Rotation  = geom.Rotation;
        info->Alpha     = Double(alpha);
        info->XScale    = geom.XScale;
        info->YScale    = geom.YScale;
        info->ZScale    = geom.ZScale;
    }
    const Double fov = pdisp->GetFOV();
    info->VarsSet |= 0x800;
    info->FOV = fov;
    Matrix4F proj;
    if (pdisp->GetProjectionMatrix3D(&proj, false))
    {
        info->VarsSet |= 0x1000;
        info->ProjectionMatrix3D = proj;
    }
    Matrix3F view;
    if (pdisp->GetViewMatrix3D(&view, false))
    {
        info->VarsSet |= 0x2000;
        info->ViewMatrix3D = view;
    }
    const unsigned edgeAA = pdisp->GetRenderNode()->GetEdgeAAMode();
    info->VarsSet |= 0x4000;
    info->EdgeAAMode = edgeAA;
    return true;
}

// A new empty Sprite named instanceName at depth (the top when negative) of the container; its constructor runs
// right away.
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's); the exe inlines the Value and Error temporaries
// @0x1424f33d0
bool Sfr34d_ValueObjIfc::CreateEmptyMovieClip(void* pdata, GFx::Value* pmc, const char* instanceName, SInt32 depth)
{
    MovieRoot* root = GetAS3Root();
    if (!Sfr17d_IsDisplayObject(pdata, true))
        return false;
    DisplayObject* pcont = static_cast<Instances::fl_display::DisplayObject*>(static_cast<Object*>(pdata))->pDispObj;
    Value result;
    VM*   vm = root->pAVM;
    const StringDataPtr className("flash.display.Sprite", 0x14);
    const UPInt callStackSize = vm->Unk070[1];
    bool needExecute;
    Class* cls = vm->GetClass(className);
    if (!cls)
    {
        if (!vm->HandleException)
        {
            const VM::Error e(VM::ErrorID(1065) /* eUndefinedVarError */, *vm, className.ToCStr());
            FUN_14252ecb0(vm, &e, &fl::ReferenceErrorCI);
        }
        needExecute = false;
    }
    else
    {
        Value _class(cls);
        cls->Construct(result, 0, NULL, false);
        needExecute = callStackSize < vm->Unk070[1];
    }
    if (vm->HandleException)
        return false;
    if (needExecute)
    {
        vm->ExecuteCode(1);
        if (vm->HandleException)
            return false;
    }
    if (!Sfr17d_IsDisplayObject(result))
        return false;
    Instances::fl_display::DisplayObject* pnew = static_cast<Instances::fl_display::DisplayObject*>(result.GetObject());
    {
        Value r;
        pnew->nameSet(r, ASString(root->GetStringManager418()->CreateStringNode(instanceName)));
    }
    AvmDisplayObjContainer* cont = Sfr17d_ToAvmContainer(pcont);
    if (depth < 0)
        depth = SInt32(cont->GetDisplayObjContainer()->mDisplayList.GetCount());
    cont->AddChildAt(pnew->pDispObj, unsigned(depth));
    root->ASValue2GFxValue(result, pmc);
    return true;
}

// A new instance of the exported class symbolName named instanceName at depth (the top when negative or past it)
// of the container, with the initArgs members set; its constructor runs right away.
// MS2-FUNCTIONAL member of a view over the AS3 value object interface (the class is sfr_as3_17's); the exe inlines the Multiname and Value constructors
// @0x1424ede80
bool Sfr34d_ValueObjIfc::AttachMovie(void* pdata, GFx::Value* pmc, const char* symbolName, const char* instanceName,
                                     SInt32 depth, const MemberValueSet* initArgs)
{
    MovieRoot* root = GetAS3Root();
    if (!Sfr17d_IsDisplayObject(pdata, true))
        return false;
    DisplayObject* pcont = static_cast<Instances::fl_display::DisplayObject*>(static_cast<Object*>(pdata))->pDispObj;
    Value result;
    VM*   vm = root->pAVM;
    // VM::Construct 0x1424f0750 as the exe has it returns whether a constructor frame was queued (+0x78 grew)
    const UPInt frames = vm->Unk070[1];
    vm->Construct(symbolName, result, 0, NULL, false);
    const bool needExecute = !vm->HandleException && vm->Unk070[1] > frames;
    if (!vm->HandleException)
    {
        if (needExecute)
            vm->ExecuteCode(1);
        if (!vm->HandleException)
        {
            if (!Sfr17d_IsDisplayObject(result))
                return false;
            Instances::fl_display::DisplayObject* pnew =
                static_cast<Instances::fl_display::DisplayObject*>(result.GetObject());
            Value r;
            pnew->nameSet(r, ASString(root->GetStringManager418()->CreateStringNode(instanceName)));
            const Sfr17dMemberValueSet* args = reinterpret_cast<const Sfr17dMemberValueSet*>(initArgs);
            if (args)
            {
                for (unsigned i = 0; i < args->Size; ++i)
                {
                    const Sfr17dMemberValue& mv = args->Data[i];
                    const Multiname mn(vm->GetPublicNamespace(),
                                       Value(ASString(root->GetStringManager418()->CreateStringNode(mv.Key.ToCStr(),
                                                                                                    mv.Key.GetSize()))));
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

}}} // namespace Scaleform::GFx::AS3

// MS2-PIN: ??_7File@Abc@AS3@GFx@Scaleform@@6B@ 0x14317b050
// MS2-PIN: ??_7AbcFileWithMovieDef@ASVM@AS3@GFx@Scaleform@@6B@ 0x14317d8a8
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
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
