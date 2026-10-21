// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 resources and the resource library.
// Queue unit sfr_gfx_02 covers several original sources; this file is the resource library one (sfr_gfx_02b.. hold
// the others).
// MS2-UNIT: sfr_gfx_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a2100-0x1425a4900 .text$mn

#include "../include/gfx/gfx_resource.h"
#include "../include/kernel/sf_msgformat.h"

namespace Scaleform { namespace GFx {

// ---------------------------------------------------------------- Resource

// @0x1425a3850
void Resource::AddRef()
{
    RefCount.Increment_NoSync();
}

// The last release unregisters the resource from its weak library before deleting it.
// @0x1425a4030
void Resource::Release()
{
    if ((RefCount.ExchangeAdd_Acquire(-1) - 1) == 0)
    {
        if (pLib)
        {
            pLib->RemoveResourceOnRelease(this);
            pLib = 0;
        }
        delete this;
    }
}

// Takes a reference unless the count already dropped to zero (the resource is being destroyed).
// @0x1425a3860
bool Resource::AddRef_NotZero()
{
    for (;;)
    {
        SInt32 count = RefCount;
        if (count == 0)
            return false;
        if (RefCount.CompareAndSet_NoSync(count, count + 1))
            break;
    }
    return true;
}

SInt32 Resource::GetRefCount() const
{
    return RefCount;
}

// ---------------------------------------------------------------- ResourceLib

// @0x1425a2b60
ResourceLib::ResourceLib(bool debug)
{
    DebugFlag = debug;
    pWeakLib  = SF_NEW ResourceWeakLib(this);
}

// @0x1425a2ef0
ResourceLib::~ResourceLib()
{
    if (pWeakLib)
    {
        pWeakLib->UnpinAll();
        pWeakLib->Release();
    }
}

// ---------------------------------------------------------------- ResourceLib::ResourceSlot

// @0x1425a2c90
ResourceLib::ResourceSlot::ResourceSlot(ResourceWeakLib* plib, const ResourceKey& key)
{
    pLib      = plib;
    State     = Resolve_InProgress;
    pResource = 0;
    Key       = key;
}

// An unresolved slot still sits in the weak library's table; a resolved one holds a reference to its resource.
// @0x1425a2f30
ResourceLib::ResourceSlot::~ResourceSlot()
{
    Lock::Locker lock(&pLib->ResourceLock);
    if (State == Resolve_InProgress)
        pLib->Resources.Remove(Key);
    else if (pResource)
        pResource->Release();
}

// @0x1425a4600
Resource* ResourceLib::ResourceSlot::WaitForResolve()
{
    ResolveComplete.Wait();
    if (pResource)
        pResource->AddRef();
    return pResource;
}

// @0x1425a3c00
const char* ResourceLib::ResourceSlot::GetError() const
{
    return ErrorMessage.ToCStr();
}

// @0x1425a3f70
bool ResourceLib::ResourceSlot::IsResolved() const
{
    Lock::Locker lock(&pLib->ResourceLock);
    return State != Resolve_InProgress;
}

// The table node switches from this slot to the resource, which now belongs to the weak library.
// @0x1425a41e0
void ResourceLib::ResourceSlot::Resolve(Resource* pres)
{
    Lock::Locker lock(&pLib->ResourceLock);

    pres->AddRef();
    pResource = pres;
    State     = Resolve_Success;

    ResourceWeakLib::ResourceNode* pnode = pLib->Resources.Get(Key);
    pnode->pResource = pres;
    pnode->Type      = ResourceWeakLib::ResourceNode::Node_Resource;
    pres->SetOwnerResourceLib(pLib);

    ResolveComplete.SetEvent();
}

// @0x1425a3a50
void ResourceLib::ResourceSlot::CancelResolve(const char* perrorMessage)
{
    Lock::Locker lock(&pLib->ResourceLock);
    State        = Resolve_Fail;
    ErrorMessage = perrorMessage;
    pLib->Resources.Remove(Key);
    ResolveComplete.SetEvent();
}

// ---------------------------------------------------------------- ResourceLib::BindHandle

// On success the handle switches from the slot to the resource, keeping one reference for itself.
// @0x1425a4540
Resource* ResourceLib::BindHandle::WaitForResolve()
{
    if (State == RS_Available)
    {
        pResource->AddRef();
        return pResource;
    }
    else if (State == RS_Error)
    {
        return 0;
    }

    ResourceSlot* pslot = pSlot;
    Resource*     pres  = pslot->WaitForResolve();
    if (pres)
    {
        State     = RS_Available;
        pResource = pres;
        pResource->AddRef();
        pslot->Release();
        return pres;
    }
    State = RS_Error;
    return 0;
}

// ---------------------------------------------------------------- ResourceWeakLib

// @0x1425a2d60
ResourceWeakLib::ResourceWeakLib(ResourceLib* pstrongLib)
{
    pStrongLib = pstrongLib;

    // Images get a heap of their own.
    HeapDesc desc((pstrongLib && pstrongLib->DebugFlag) ? HeapDesc::Heap_UserDebug : 0);
    desc.Flags      |= HeapDesc::Heap_FastTinyBlocks;
    desc.MinAlign    = 64;
    desc.Granularity = 4 * 1024;
    desc.Reserve     = 0;
    desc.Threshold   = ~UPInt(0);
    desc.Limit       = 0;
    desc.HeapId      = HeapId_Images;
    pImageHeap = *Memory::GetGlobalHeap()->CreateHeap("_ResourceLib_Images", desc);
}

// Resources outliving the library must not call back into it.
// @0x1425a2ff0
ResourceWeakLib::~ResourceWeakLib()
{
    Lock::Locker lock(&ResourceLock);
    HashSet<ResourceNode, ResourceNode::HashOp>::Iterator ires;
    for (ires = Resources.Begin(); ires != Resources.End(); ++ires)
        ires->pResource->SetOwnerResourceLib(0);
}

// @0x1425a3c60
Resource* ResourceWeakLib::GetResource(const ResourceKey& k)
{
    Lock::Locker lock(&ResourceLock);
    ResourceNode* pnode = Resources.Get(k);
    if (pnode && pnode->IsResource())
    {
        if (pnode->pResource->AddRef_NotZero())
            return pnode->pResource;
    }
    return 0;
}

// Finds the resource or the slot of a load in progress; otherwise registers a new slot the caller must resolve.
// @0x1425a3890
ResourceLib::ResolveState ResourceWeakLib::BindResourceKey(ResourceLib::BindHandle* phandle, const ResourceKey& k)
{
    Lock::Locker lock(&ResourceLock);

    ResourceNode* pnode = Resources.Get(k);
    if (pnode)
    {
        if (pnode->IsResource())
        {
            if (pnode->pResource->AddRef_NotZero())
            {
                phandle->pResource = pnode->pResource;
                phandle->State     = ResourceLib::RS_Available;
                return phandle->State;
            }
            // Dying resource: drop its entry and load it again.
            Resources.Remove(k);
        }
        else
        {
            phandle->pSlot = pnode->pResolver;
            phandle->State = ResourceLib::RS_WaitingResolve;
            phandle->pSlot->AddRef();
            return phandle->State;
        }
    }

    ResourceSlot* pslot = SF_NEW ResourceSlot(this, k);
    if (!pslot)
        return ResourceLib::RS_Error;

    ResourceNode n;
    n.Type      = ResourceNode::Node_Resolver;
    n.pResolver = pslot;
    Resources.Add(n);

    phandle->pSlot = pslot;
    phandle->State = ResourceLib::RS_NeedsResolve;
    return phandle->State;
}

// @0x1425a3ce0
void ResourceWeakLib::GetResourceArray(Array<Ptr<Resource> >* presources)
{
    Lock::Locker lock(&ResourceLock);
    HashSet<ResourceNode, ResourceNode::HashOp>::Iterator ires = Resources.Begin();
    while (ires != Resources.End())
    {
        ResourceNode* pnode = &*ires;
        if (pnode->IsResource() && pnode->pResource->AddRef_NotZero())
        {
            Ptr<Resource> presource = *pnode->pResource;
            presources->PushBack(presource);
        }
        ++ires;
    }
}

// @0x1425a3f10
bool ResourceWeakLib::IsPinned(Resource* pres)
{
    Lock::Locker lock(&ResourceLock);
    return pStrongLib && pStrongLib->PinSet.Get(pres) != 0;
}

// @0x1425a3fb0
void ResourceWeakLib::PinResource(Resource* pres)
{
    Lock::Locker lock(&ResourceLock);
    if (pStrongLib)
    {
        if (!pStrongLib->PinSet.Get(pres))
        {
            pStrongLib->PinSet.Add(pres);
            pres->AddRef();
        }
    }
}

// MS2-FUNCTIONAL: same code as the exe with r10 and r11 swapped in the register allocation
// @0x1425a43d0
void ResourceWeakLib::UnpinResource(Resource* pres)
{
    Lock::Locker lock(&ResourceLock);
    if (pStrongLib)
    {
        pStrongLib->PinSet.Remove(pres);
        pres->Release();
    }
}

// @0x1425a4260
void ResourceWeakLib::UnpinAll()
{
    Lock::Locker lock(&ResourceLock);
    if (pStrongLib)
    {
        ResourceLib::PinHashSet::Iterator ihash = pStrongLib->PinSet.Begin();
        while (ihash != pStrongLib->PinSet.End())
        {
            (*ihash)->Release();
            ++ihash;
        }
        pStrongLib->PinSet.Clear();
    }
}

// Called from Resource::Release with the count at zero: forget the entry unless it was already replaced.
// @0x1425a4080
void ResourceWeakLib::RemoveResourceOnRelease(Resource* pres)
{
    Lock::Locker lock(&ResourceLock);
    ResourceNode* pnode = Resources.Get(pres->GetKey());
    if (pnode && pnode->Type == ResourceNode::Node_Resource && pnode->pResource == pres)
        Resources.Remove(pres->GetKey());
}

// ---------------------------------------------------------------- ResourceId

// MS2-FUNCTIONAL: the exe keeps a dead copy of pbuffer in rax after storing the suffix letter (one extra mov)
// @0x1425a3b20
unsigned ResourceId::GenerateIdString(char* pbuffer, UPInt bufferSize, char suffixLetter) const
{
    if (!suffixLetter)
    {
        switch (GetIdType())
        {
        case IdType_GradientImage:
            suffixLetter = 'G';
            break;
        case IdType_DynFontImage:
        case IdType_FontImage:
            suffixLetter = 'F';
            break;
        default:
            suffixLetter = 'I';
            break;
        }
    }
    pbuffer[0] = suffixLetter;

    LongFormatter f(GetIdIndex());
    f.SetBase(16).SetBigLetters().Convert();
    f.InitString(&pbuffer[1], bufferSize);
    return (unsigned)f.GetSize();
}

// ---------------------------------------------------------------- ResourceFileInfo

// @0x1425a2a80
ResourceFileInfo::ResourceFileInfo()
{
    Format        = FileTypeConstants::File_Unknown;
    pExporterInfo = 0;
}

// @0x1425a2a30
ResourceFileInfo::ResourceFileInfo(const ResourceFileInfo& src) : FileName(src.FileName)
{
    Format        = src.Format;
    pExporterInfo = src.pExporterInfo;
}

// @0x1425a3c10
UPInt ResourceFileInfo::GetHashCode() const
{
    UPInt hash = String::BernsteinHashFunction(FileName.ToCStr(), FileName.GetSize());
    return hash ^ Format;
}

// ---------------------------------------------------------------- ResourceKey

// @0x1425a2b50
ResourceKey::ResourceKey()
{
    pKeyInterface = 0;
    hKeyData      = 0;
}

// @0x1425a2b00
ResourceKey::ResourceKey(KeyInterface* pki, KeyHandle hk)
{
    if (pki)
        pki->AddRef(hk);
    pKeyInterface = pki;
    hKeyData      = hk;
}

// @0x1425a2ac0
ResourceKey::ResourceKey(const ResourceKey& src)
{
    if (src.pKeyInterface)
        src.pKeyInterface->AddRef(src.hKeyData);
    pKeyInterface = src.pKeyInterface;
    hKeyData      = src.hKeyData;
}

// @0x1425a3110
ResourceKey& ResourceKey::operator=(const ResourceKey& src)
{
    if (src.pKeyInterface)
        src.pKeyInterface->AddRef(src.hKeyData);
    if (pKeyInterface)
        pKeyInterface->Release(hKeyData);
    pKeyInterface = src.pKeyInterface;
    hKeyData      = src.hKeyData;
    return *this;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
// MS2-PIN: ??_7?$RefCountBaseNTS@UResourceFileInfo@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143185920
// MS2-PIN: ??_7ResourceFileInfo@GFx@Scaleform@@6B@ 0x143185928
// MS2-PIN: ??_7?$RefCountBase@VResourceLibBase@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143185930
// MS2-PIN: ??_7ResourceLibBase@GFx@Scaleform@@6B@ 0x143185938
// MS2-PIN: ??_7?$RefCountBase@VResourceLib@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143185958
// MS2-PIN: ??_7?$RefCountBase@VResourceSlot@ResourceLib@GFx@Scaleform@@$01@Scaleform@@6B@ 0x143185960
// MS2-PIN: ??_7ResourceSlot@ResourceLib@GFx@Scaleform@@6B@ 0x143185968
// MS2-PIN: ??_7ResourceLib@GFx@Scaleform@@6B@ 0x143185970
// MS2-PIN: ??_7ResourceWeakLib@GFx@Scaleform@@6B@ 0x143185978
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
