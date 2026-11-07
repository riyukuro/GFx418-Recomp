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
#include "../include/gfx/as2/as2_genericdisplayobj.h"
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
#include "../include/gfx/as2/as2_valueobjectinterface.h"
namespace Scaleform { namespace GFx { namespace AS2 {

// CreateObjectInterface inlines the AS2ValueObjectInterface constructor, so its vftable is emitted here:
// MS2-PIN: ??_7AS2ValueObjectInterface@GFx@Scaleform@@6B@ 0x143222128
// MS2-PIN: ??_7ObjectInterface@Value@GFx@Scaleform@@6B@ 0x14317bc90

// the same flush-and-collect as the heap's limit handler, without touching the limits
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
// The empty image substitutor (three zeroed words).
struct Sfr04lImageSubstitutor
{
    UPInt Words[3];
    Sfr04lImageSubstitutor() { Words[0] = 0; Words[1] = 0; Words[2] = 0; }
};

// @0x142936510
void* FUN_142936510(TextField* ptf)
{
    UByte* pdoc = *reinterpret_cast<UByte**>(reinterpret_cast<UByte*>(ptf) + 0xe0);
    void*  psubst = *reinterpret_cast<void**>(pdoc + 0x30);
    if (!psubst)
    {
        void* mem = Memory::pGlobalHeap->Alloc(0x18);
        psubst = mem ? new (mem) Sfr04lImageSubstitutor : 0;
        *reinterpret_cast<void**>(pdoc + 0x30) = psubst;
    }
    return psubst;
}

// Stage / render bookkeeping after a character's target changed: the object at +0x20 runs its slot 77 and the four
// callbacks on it and on the result.
void FUN_1425dcaf0(void* pobj);

// The target (+0x20) is re-read after every call, as the exe does.
// @0x142936570
void FUN_142936570(void* self)
{
    void* const& ptarget = *reinterpret_cast<void**>(static_cast<UByte*>(self) + 0x20);
    typedef void* (*Slot77)(void*);
    void* presult = reinterpret_cast<Slot77>((*static_cast<void* const* const*>(ptarget))[0x268 / 8])(ptarget);
    FUN_1425dcaf0(ptarget);
    static_cast<DisplayObjectBase*>(ptarget)->InvalidateHitResult();
    static_cast<DrawingContext*>(presult)->AcquirePath(true);
    static_cast<DrawingContext*>(presult)->CreateLineComplexFill();
}

// @0x1429365c0
MovieDefRootNode* MovieRoot::CreateMovieDefRootNode(MemoryHeap* pheap, MovieDefImpl* pdefImpl, bool importFlag)
{
    return new (pheap) MovieDefRootNode(pdefImpl, importFlag);
}

// The host value interface of the movie: 0x10 bytes, vftable and the movie.
// @0x1429379d0
void MovieRoot::CreateObjectInterface(MovieImpl* pmovie)
{
    pmovie->pObjectInterface = SF_HEAP_NEW(pMovieImpl->pHeap) AS2ValueObjectInterface(pmovie);
}
//
//
//
//
//
//
//

// Binds the host value to the VM object: display objects must still be on the stage, others are Arrays or
// plain Objects.
static SF_FORCEINLINE bool FillObjectValue(MovieImpl* pmovie, GFx::Value::ObjectInterface* pif, GFx::Value* pval,
                                          void* pdata, bool isdobj)
{
    GFx::Value::ValueType vt = GFx::Value::VT_Object;
    if (isdobj)
    {
        vt                   = GFx::Value::VT_DisplayObject;
        DisplayObject* pdobj = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pmovie);
        if (!pdobj || !((UByte)(*reinterpret_cast<UInt16*>(reinterpret_cast<UByte*>(pdobj) + 0x6a) >> 10) & 1))
            return false;
    }
    else
    {
        // the host data of an object is its ObjectInterface, as AS2ValueObjectInterface::ObjectAddRef reads it
        ObjectInterface* pobjif = static_cast<ObjectInterface*>(pdata);
        Object*          pobj   = pobjif->IsASObject() ? static_cast<Object*>(pobjif) : 0; // ToASObject, inlined
        if (pobj->GetObjectType() == Object::Object_Array)
            vt = GFx::Value::VT_Array;
    }
    UPInt* w = reinterpret_cast<UPInt*>(pval);
    if ((UByte)(reinterpret_cast<unsigned*>(w)[2] >> 6) & 1) // VTC_ManagedBit
        reinterpret_cast<GFx::Value::ObjectInterface*>(w[0])->ObjectRelease(pval, reinterpret_cast<void*>(w[2]));
    w[2]                                  = reinterpret_cast<UPInt>(pdata);
    reinterpret_cast<unsigned*>(w)[2]     = vt | GFx::Value::VTC_ManagedBit;
    w[0]                                  = reinterpret_cast<UPInt>(pif);
    pif->ObjectAddRef(pval, pdata);
    return true;
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// The interface's own entry: the movie is reached through its AS2 movie root.
// @0x142937a20
bool AS2ValueObjectInterface::CreateObjectValue(Value* pval, void* pdata, bool isdobj)
{
    AS2::MovieRoot* proot = static_cast<AS2::MovieRoot*>(pMovieRoot->pASMovieRoot);
    return AS2::FillObjectValue(proot->pMovieImpl, this, pval, pdata, isdobj);
}

}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS2 {

// The host value is filled by raw words.
// @0x142937af0
bool MovieRoot::CreateObjectValue(GFx::Value* pval, GFx::Value::ObjectInterface* pif, void* pdata, bool isdobj)
{
    return FillObjectValue(this->pMovieImpl, pif, pval, pdata, isdobj);
}

// The render node of a shape object: its shape definition's tree shape in the object's movie definition.
// @0x142937ca0
Ptr<Render::TreeNode> GenericDisplayObj::CreateRenderNode(Render::ContextImpl::Context& context) const
{
    return static_cast<ShapeBaseCharacterDef*>(pDef.GetPtr())->CreateTreeShape(context, GetResourceMovieDef());
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
        pASSupport->CreateCharacterInstance(GetMovieImpl(), ccinfo, parent, id, CharacterDef::Sprite));
    psprite->SetLoadedSeparately(loadedSeparately);
    return psprite;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7MovieDefRootNode@GFx@Scaleform@@6B@ 0x14317c9e0

// AS2::FUN_1425dcaf0 is the exe's folded empty body (named ConstructorMov<ASSoundIntf*>::Construct); bound by
// alternatename so the call stays out of line, as in the exe (see sfr_as3_16z).
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:?FUN_1425dcaf0@AS2@GFx@Scaleform@@YAXPEAX@Z=?Construct@?$ConstructorMov@PEAVASSoundIntf@GFx@Scaleform@@@Scaleform@@SAXPEAX@Z")
#endif
