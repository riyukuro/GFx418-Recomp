// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 movie root helpers: the heap
// limit's collection, the movie def root node, the host value interface and the sprite factory (gap recovery of
// sfr_as2_04).
// MS2-UNIT: sfr_as2_04l
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429349a0-0x1429349fd .text$mn
// MS2-RANGE: 0x142936510-0x142936562 .text$mn
// MS2-RANGE: 0x142936570-0x1429365ba .text$mn
// MS2-RANGE: 0x1429365c0-0x14293661b .text$mn
// MS2-RANGE: 0x1429379d0-0x142937a18 .text$mn
// MS2-RANGE: 0x142937a20-0x142937aec .text$mn
// MS2-RANGE: 0x142937af0-0x142937bb6 .text$mn
// MS2-RANGE: 0x142937ca0-0x142937ce5 .text$mn
// MS2-RANGE: 0x142937cf0-0x142937d56 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_shapedef.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/gfx/gfx_value.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The movie's value interface (exe vftable 0x143222128; its members are recovered elsewhere).
extern const void* DAT_143222128[];

// MS2-FUNCTIONAL: the same flush-and-collect as the heap's limit handler, without touching the limits
// @0x1429349a0
void MemoryContextImpl::HeapLimit::Collect(MemoryHeap* pheap)
{
    MemoryContextImpl* context = MemContext;
    if (context->TextAllocator)
    {
        context->TextAllocator->FlushTextFormatCache(true);
        MemContext->TextAllocator->FlushParagraphFormatCache(true);
        context = MemContext;
    }
    context->ASGC->ForceEmergencyCollect();
    CurrentLimit = pheap->GetFootprint();
}

// The field's document view creates its image substitutor on first use (0x18 bytes, empty).
// MS2-FUNCTIONAL: the document view is reached by address
// @0x142936510
void* FUN_142936510(TextField* ptf)
{
    UByte* pdoc = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(ptf) + 0xe0);
    void*  psubst = *reinterpret_cast<void**>(pdoc + 0x30);
    if (!psubst)
    {
        psubst = Memory::pGlobalHeap->Alloc(0x18);
        if (psubst)
        {
            UPInt* w = static_cast<UPInt*>(psubst);
            w[0] = w[1] = w[2] = 0;
        }
        *reinterpret_cast<void**>(pdoc + 0x30) = psubst;
    }
    return psubst;
}

// Stage / render bookkeeping after a character's target changed: the object at +0x20 runs its slot 77 and the four
// callbacks on it and on the result.
void FUN_1425dcaf0(void* pobj);
void FUN_1425f32c0(void* pobj);
void FUN_1425fe1c0(void* pobj, int flag);
void FUN_1425fee30(void* pobj);

// MS2-FUNCTIONAL: raw words
// @0x142936570
void FUN_142936570(void* self)
{
    void* ptarget = *reinterpret_cast<void**>(static_cast<UByte*>(self) + 0x20);
    typedef void* (*Slot77)(void*);
    void* presult = reinterpret_cast<Slot77>((*static_cast<void***>(ptarget))[0x268 / 8])(ptarget);
    FUN_1425dcaf0(ptarget);
    FUN_1425f32c0(ptarget);
    FUN_1425fe1c0(presult, 1);
    FUN_1425fee30(presult);
}

// @0x1429365c0
MovieDefRootNode* MovieRoot::CreateMovieDefRootNode(MemoryHeap* pheap, MovieDefImpl* pdefImpl, bool importFlag)
{
    return new (pheap) MovieDefRootNode(pdefImpl, importFlag);
}

// The host value interface of the movie: 0x10 bytes, vftable and the movie.
// MS2-FUNCTIONAL: the interface class is not modelled, its vftable is raw
// @0x1429379d0
void MovieRoot::CreateObjectInterface(MovieImpl* pmovie)
{
    UPInt* pif = static_cast<UPInt*>(pMovieImpl->pHeap->Alloc(0x10));
    if (pif)
    {
        pif[1] = reinterpret_cast<UPInt>(pmovie);
        pif[0] = reinterpret_cast<UPInt>(DAT_143222128);
        pmovie->pObjectInterface = pif;
        return;
    }
    pmovie->pObjectInterface = 0;
}

// Binds the host value to the VM object: display objects must still be on the stage, others are Arrays or
// plain Objects.
static inline bool FillObjectValue(MovieImpl* pmovie, GFx::Value::ObjectInterface* pif, GFx::Value* pval, void* pdata,
                                   bool isdobj)
{
    GFx::Value::ValueType vt;
    if (isdobj)
    {
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pmovie);
        if (!pdobj || !(*reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pdobj) + 0x6a) & 0x400))
            return false;
        vt = GFx::Value::VT_DisplayObject;
    }
    else
    {
        Object* pobj = static_cast<Object*>(pdata);
        vt           = pobj->GetObjectType() == Object::Object_Array ? GFx::Value::VT_Array : GFx::Value::VT_Object;
    }
    UPInt* w = reinterpret_cast<UPInt*>(pval);
    if (reinterpret_cast<unsigned*>(w)[2] & GFx::Value::VTC_ManagedBit)
        reinterpret_cast<GFx::Value::ObjectInterface*>(w[0])->ObjectRelease(pval, reinterpret_cast<void*>(w[2]));
    w[2]                                  = reinterpret_cast<UPInt>(pdata);
    reinterpret_cast<unsigned*>(w)[2]     = vt | GFx::Value::VTC_ManagedBit;
    w[0]                                  = reinterpret_cast<UPInt>(pif);
    pif->ObjectAddRef(pval, pdata);
    return true;
}

// The interface's own entry: the movie is reached through its movie root.
// MS2-FUNCTIONAL: the interface class is not modelled, the movie is read by address
// @0x142937a20
bool FUN_142937a20(GFx::Value::ObjectInterface* pif, GFx::Value* pval, void* pdata, bool isdobj)
{
    UByte* pasRoot = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(pif) + 8);
    UByte* pbase   = *reinterpret_cast<UByte**>(pasRoot + 0x18);
    return FillObjectValue(*reinterpret_cast<MovieImpl**>(pbase + 0x10), pif, pval, pdata, isdobj);
}

// MS2-FUNCTIONAL: the host value is filled by raw words
// @0x142937af0
bool MovieRoot::CreateObjectValue(GFx::Value* pval, GFx::Value::ObjectInterface* pif, void* pdata, bool isdobj)
{
    return FillObjectValue(this->pMovieImpl, pif, pval, pdata, isdobj);
}

// The render node of a shape object: its shape definition's tree shape in the object's movie definition.
// MS2-FUNCTIONAL: GenericDisplayObj is not modelled, the shape definition is read by address
// @0x142937ca0
Ptr<Render::TreeNode>* FUN_142937ca0(DisplayObject* pself, Ptr<Render::TreeNode>* pret,
                                     Render::ContextImpl::Context& context)
{
    ShapeBaseCharacterDef* pdef = *reinterpret_cast<ShapeBaseCharacterDef**>(reinterpret_cast<UByte*>(pself) + 0x70);
    MovieDefImpl*          pmd  = pself->GetResourceMovieDef();
    new (pret) Ptr<Render::TreeNode>(pdef->CreateTreeShape(context, pmd));
    return pret;
}

// @0x142937cf0
Sprite* MovieRoot::CreateSprite(TimelineDef* ptimelineDef, MovieDefImpl* pdefImpl, InteractiveObject* parent,
                                ResourceId id, bool loadedSeparately)
{
    CharacterCreateInfo ccinfo;
    ccinfo.pCharDef     = reinterpret_cast<CharacterDef*>(ptimelineDef);
    ccinfo.pBindDefImpl = pdefImpl;
    ccinfo.pResource    = 0;
    Sprite* psprite     = reinterpret_cast<Sprite*>(
        pASSupport->CreateCharacterInstance(pMovieImpl, ccinfo, parent, id, CharacterDef::Sprite));
    psprite->SetLoadedSeparately(loadedSeparately);
    return psprite;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7MovieDefRootNode@GFx@Scaleform@@6B@ 0x14317c9e0
