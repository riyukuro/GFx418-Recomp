// Recovered Scaleform GFx 4.1.18: resources, resource keys and the strong/weak resource libraries.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
// Layouts and the out-of-line members are the exe's GFx_Resource unit (sfr_gfx_02.cpp, 0x1425a2100-0x1425a4900).
#ifndef MS2_SF_GFX_RESOURCE_H
#define MS2_SF_GFX_RESOURCE_H

#include "../kernel/sf_refcount.h"
#include "../kernel/sf_array.h"
#include "../kernel/sf_hash.h"
#include "../kernel/sf_string.h"
#include "../kernel/sf_lock.h"

namespace Scaleform { namespace GFx {

class ResourceKey;
class Resource;
class ResourceReport;
class ResourceLib;
class ResourceWeakLib;

// Id of a resource inside one SWF/GFX file: low 16 bits index, bits 16..27 the generated-id type.
class ResourceId
{
    UInt32 Id;

public:
    enum IdTypeConstants
    {
        IdType_Bit_IndexMask = 0x0000FFFFu,
        IdType_Bit_TypeMask  = 0x0FFF0000u,
        IdType_Bit_SWF       = 0x00000,
        IdType_Bit_Static    = 0x10000,
        IdType_Bit_Export    = 0x20000,
        IdType_Bit_GenMask   = 0x30000,
        IdType_Bit_TypeShift = 18,
        InvalidId            = (1 << IdType_Bit_TypeShift) | IdType_Bit_SWF
    };

    enum IdType
    {
        IdType_None             = 0,
        IdType_InternalConstant = (0 << IdType_Bit_TypeShift) | IdType_Bit_Static,
        IdType_GradientImage    = (1 << IdType_Bit_TypeShift) | IdType_Bit_Static,
        IdType_DynFontImage     = (2 << IdType_Bit_TypeShift) | IdType_Bit_Static,
        IdType_FontImage        = (1 << IdType_Bit_TypeShift) | IdType_Bit_Export
    };

    ResourceId() : Id(InvalidId) {}
    explicit ResourceId(UInt32 id) : Id(id) {}
    ResourceId(const ResourceId& src) : Id(src.Id) {}
    ResourceId operator=(const ResourceId& src) { Id = src.Id; return *this; }

    bool operator==(const ResourceId& o) const { return Id == o.Id; }
    bool operator!=(const ResourceId& o) const { return Id != o.Id; }
    bool operator==(UInt32 v) const            { return Id == v; }
    bool operator!=(UInt32 v) const            { return Id != v; }

    UInt32   GetIdValue() const { return Id; }
    unsigned GetIdIndex() const { return Id & IdType_Bit_IndexMask; }
    IdType   GetIdType() const  { return (IdType)(Id & IdType_Bit_TypeMask); }

    // "<letter><index in hex>": the letter defaults to G (gradient), F (font image) or I.
    unsigned GenerateIdString(char* pbuffer, UPInt bufferSize = 9, char suffixLetter = 0) const;

    ResourceId GenerateNextId()
    {
        ResourceId result = *this;
        Id++;
        return result;
    }

    class HashOp
    {
    public:
        UPInt operator()(const ResourceId& r) { return (r.Id ^ (r.Id >> 8)); }
    };
};

class FileTypeConstants
{
public:
    enum FileFormatType
    {
        File_Unopened,
        File_Unknown,
        File_SWF,
        File_GFX,
        File_JPEG        = 10,
        File_PNG         = 11,
        File_GIF         = 12,
        File_TGA         = 13,
        File_DDS         = 14,
        File_HDR         = 15,
        File_BMP         = 16,
        File_DIB         = 17,
        File_PFM         = 18,
        File_TIFF        = 19,
        File_WAVE        = 20,
        File_PVR         = 21,
        File_ETC         = 22,
        File_SIF         = 23,
        File_GXT         = 24,
        File_GTX         = 25,
        File_NextAvail,
        File_MultiFormat = 65534,
        File_Original    = 65535
    };
};

struct ExporterInfo;

// Source file description of a loaded resource (0x28 bytes).
struct ResourceFileInfo : public RefCountBaseNTS<ResourceFileInfo, Stat_Default_Mem>
{
    FileTypeConstants::FileFormatType Format;         // +0x10
    const ExporterInfo*               pExporterInfo;  // +0x18
    String                            FileName;       // +0x20

    ResourceFileInfo();
    ResourceFileInfo(const ResourceFileInfo& src);

    UPInt GetHashCode() const;
};

// Library lookup key: an interface pointer plus an opaque handle the interface reference counts.
class ResourceKey
{
public:
    enum KeyType
    {
        Key_None,
        Key_Unique,
        Key_File,
        Key_Gradient,
        Key_SubImage
    };

    typedef void* KeyHandle;

    class KeyInterface
    {
    public:
        virtual ~KeyInterface() {}
        virtual void        AddRef(KeyHandle hdata)                              = 0;
        virtual void        Release(KeyHandle hdata)                             = 0;
        virtual KeyType     GetKeyType(KeyHandle hdata) const                    = 0;
        virtual UPInt       GetHashCode(KeyHandle hdata) const                   = 0;
        virtual bool        KeyEquals(KeyHandle hdata, const ResourceKey& other) = 0;
        virtual const char* GetFileURL(KeyHandle) const { return 0; }
    };

protected:
    KeyInterface* pKeyInterface;
    KeyHandle     hKeyData;

public:
    ResourceKey();
    ResourceKey(KeyInterface* pki, KeyHandle hk);
    ResourceKey(const ResourceKey& src);
    ResourceKey& operator=(const ResourceKey& src);

    ~ResourceKey()
    {
        if (pKeyInterface)
            pKeyInterface->Release(hKeyData);
    }

    KeyType GetKeyType() const     { return pKeyInterface ? pKeyInterface->GetKeyType(hKeyData) : Key_None; }
    const char* GetFileURL() const { return pKeyInterface ? pKeyInterface->GetFileURL(hKeyData) : 0; }

    bool operator==(const ResourceKey& other) const
    {
        if (pKeyInterface && other.pKeyInterface)
            return pKeyInterface->KeyEquals(hKeyData, other);
        return false;
    }

    KeyInterface* GetKeyInterface() const { return pKeyInterface; }
    KeyHandle     GetKeyData() const      { return hKeyData; }

    class HashOp
    {
    public:
        UPInt operator()(const ResourceKey& key)
        {
            return key.pKeyInterface ? key.pKeyInterface->GetHashCode(key.hKeyData) : 0;
        }
    };
};

// What a resource reports back to its library when its last reference goes away.
class ResourceLibBase : public RefCountBase<ResourceLibBase, Stat_Default_Mem>
{
public:
    virtual void RemoveResourceOnRelease(Resource* pres) = 0;
    virtual void PinResource(Resource* pres)             = 0;
    virtual void UnpinResource(Resource* pres)           = 0;
};

// Shared, thread-safe reference counted resource (0x18 bytes): +8 count, +0x10 owning weak library.
class Resource : public NewOverrideBase<Stat_Default_Mem>
{
    friend class ResourceWeakLib;

    AtomicInt<SInt32> RefCount;
    ResourceLibBase*  pLib;

public:
    void   AddRef();
    void   Release();
    bool   AddRef_NotZero();
    SInt32 GetRefCount() const;

    Resource()
    {
        RefCount.Value = 1;
        pLib           = 0;
    }
    virtual ~Resource() {}

    void PinResource()   { if (pLib) pLib->PinResource(this); }
    void UnpinResource() { if (pLib) pLib->UnpinResource(this); }

    void SetOwnerResourceLib(ResourceLibBase* plib) { pLib = plib; }

    enum ResourceType
    {
        RT_CharacterDef_Bit = 0x0080,
        RT_None             = 0,
        RT_Image,
        RT_Font,
        RT_MovieDef,
        RT_SoundSample,
        RT_MovieDataDef     = RT_CharacterDef_Bit | 0,
        RT_ButtonDef,
        RT_TextDef,
        RT_EditTextDef,
        RT_SpriteDef,
        RT_ShapeDef,
        RT_VideoDef,
        RT_TypeCode_Mask    = 0xFF00,
        RT_TypeCode_Shift   = 8
    };

    enum ResourceUse
    {
        Use_None          = 0,
        Use_Bitmap        = 1,
        Use_Gradient      = 2,
        Use_FontTexture   = 3,
        Use_SoundSample   = 4,
        Use_TypeCode_Mask = 0xFF
    };

    virtual ResourceKey     GetKey()                    { return ResourceKey(); }
    virtual unsigned        GetResourceTypeCode() const { return MakeTypeCode(RT_None); }
    virtual ResourceReport* GetResourceReport()         { return 0; }

    ResourceType GetResourceType() const
    {
        return (ResourceType)((GetResourceTypeCode() & RT_TypeCode_Mask) >> RT_TypeCode_Shift);
    }
    ResourceUse GetResourceUse() const { return (ResourceUse)(GetResourceTypeCode() & Use_TypeCode_Mask); }

    static unsigned MakeTypeCode(ResourceType rt, ResourceUse ru = Use_None)
    {
        return (rt << RT_TypeCode_Shift) | ru;
    }
};

class ResourceReport
{
public:
    virtual ~ResourceReport() {}
    virtual String      GetResourceName() const { return String(); }
    virtual MemoryHeap* GetResourceHeap() const { return 0; }
    virtual void        GetStats(StatBag* pbag, bool reset = true) { SF_UNUSED2(pbag, reset); }
};

// Strong library (0x28 bytes): owns the weak library and the pinned resources.
class ResourceLib : public RefCountBase<ResourceLib, Stat_Default_Mem>
{
    friend class ResourceWeakLib;

    struct ResourcePtrHashFunc
    {
        UPInt operator()(Resource* const& p) const { return (((UPInt)p) >> 6) ^ (UPInt)p; }
    };

    typedef HashSetUncached<Resource*, ResourcePtrHashFunc> PinHashSet;

    ResourceWeakLib* pWeakLib;   // +0x10
    PinHashSet       PinSet;     // +0x18
    bool             DebugFlag;  // +0x20

public:
    ResourceLib(bool debug = false);
    ~ResourceLib();

    enum ResolveState
    {
        RS_Unbound,
        RS_Available,
        RS_WaitingResolve,
        RS_NeedsResolve,
        RS_Error
    };

    // Placeholder for a resource being loaded by one thread while others wait on it (0x98 bytes).
    class ResourceSlot : public RefCountBase<ResourceSlot, Stat_Default_Mem>
    {
    public:
        enum ResolveState
        {
            Resolve_InProgress,
            Resolve_Success,
            Resolve_Fail
        };

    private:
        Ptr<ResourceWeakLib>  pLib;             // +0x10
        volatile ResolveState State;            // +0x18
        Resource* volatile    pResource;        // +0x20
        ResourceKey           Key;              // +0x28
        String                ErrorMessage;     // +0x38
        Event                 ResolveComplete;  // +0x40

    public:
        ResourceSlot(ResourceWeakLib* plib, const ResourceKey& key);
        ~ResourceSlot();

        const ResourceKey& GetKey() const { return Key; }

        Resource*   WaitForResolve();
        bool        IsResolved() const;
        const char* GetError() const;
        void        Resolve(Resource* pres);
        void        CancelResolve(const char* perrorMessage);
    };

    // Result of BindResourceKey: either the resource or the slot to resolve / wait on.
    class BindHandle
    {
    public:
        ResolveState State;
        union
        {
            Resource*     pResource;
            ResourceSlot* pSlot;
        };

        BindHandle() : State(RS_Unbound), pResource(0) {}
        ~BindHandle()
        {
            if (State == RS_Available)
                pResource->Release();
            else if (State >= RS_WaitingResolve)
                pSlot->Release();
        }

        void Clear()
        {
            if (State == RS_Available)
                pResource->Release();
            else if (State >= RS_WaitingResolve)
                pSlot->Release();
            State     = RS_Unbound;
            pResource = 0;
        }

        ResolveState GetState() const     { return State; }
        bool         IsAvailable() const  { return State == RS_Available; }
        bool         NeedsResolve() const { return State == RS_NeedsResolve; }

        Resource* WaitForResolve();

        Resource*   GetResource() const     { return pResource; }
        const char* GetResolveError() const { return (State >= RS_WaitingResolve) ? pSlot->GetError() : ""; }

        void ResolveResource(Resource* pres)          { pSlot->Resolve(pres); }
        void CancelResolve(const char* perrorMessage) { pSlot->CancelResolve(perrorMessage); }
    };

    ResourceWeakLib* GetWeakLib() const { return pWeakLib; }

    inline Resource*    GetResource(const ResourceKey& k);
    inline ResolveState BindResourceKey(BindHandle* phandle, const ResourceKey& k);
    inline void         GetResourceArray(Array<Ptr<Resource> >* presources);
    inline void         UnpinAll();
    inline MemoryHeap*  GetImageHeap() const;
};

// Weak library (0x50 bytes): the key -> resource/slot table shared by every movie, guarded by ResourceLock.
class ResourceWeakLib : public ResourceLibBase
{
    friend class ResourceLib;
    friend class ResourceLib::ResourceSlot;

    typedef ResourceLib::ResourceSlot ResourceSlot;

    struct ResourceNode
    {
        enum NodeType
        {
            Node_Resource,
            Node_Resolver
        };

        NodeType Type;
        union
        {
            ResourceSlot* pResolver;
            Resource*     pResource;
        };

        bool IsResource() const { return Type == Node_Resource; }

        bool operator==(const ResourceKey& k) const
        {
            if (Type == Node_Resource)
                return pResource->GetKey() == k;
            return pResolver->GetKey() == k;
        }

        struct HashOp
        {
            UPInt operator()(const ResourceNode& node) const
            {
                ResourceKey k = (node.Type == Node_Resource) ? node.pResource->GetKey() : node.pResolver->GetKey();
                return ResourceKey::HashOp()(k);
            }
            UPInt operator()(const ResourceKey& k) const { return ResourceKey::HashOp()(k); }
        };
    };

    ResourceLib*                                pStrongLib;    // +0x10
    Lock                                        ResourceLock;  // +0x18
    HashSet<ResourceNode, ResourceNode::HashOp> Resources;     // +0x40
    Ptr<MemoryHeap>                             pImageHeap;    // +0x48

public:
    ResourceWeakLib(ResourceLib* pstrongLib);
    ~ResourceWeakLib();

    typedef ResourceLib::BindHandle   BindHandle;
    typedef ResourceLib::ResolveState ResolveState;

    Resource*    GetResource(const ResourceKey& k);
    ResolveState BindResourceKey(BindHandle* phandle, const ResourceKey& k);

    bool IsPinned(Resource* pres);
    void PinResource(Resource* pres);
    void UnpinResource(Resource* pres);
    void UnpinAll();

    void GetResourceArray(Array<Ptr<Resource> >* presources);

    MemoryHeap* GetImageHeap() const { return pImageHeap.GetPtr(); }

    virtual void RemoveResourceOnRelease(Resource* pres);

    ResourceLib* GetResourceLib() const { return pStrongLib; }
};

inline Resource* ResourceLib::GetResource(const ResourceKey& k) { return pWeakLib->GetResource(k); }
inline ResourceLib::ResolveState ResourceLib::BindResourceKey(BindHandle* phandle, const ResourceKey& k)
{
    return pWeakLib->BindResourceKey(phandle, k);
}
inline void        ResourceLib::GetResourceArray(Array<Ptr<Resource> >* presources) { pWeakLib->GetResourceArray(presources); }
inline void        ResourceLib::UnpinAll()           { pWeakLib->UnpinAll(); }
inline MemoryHeap* ResourceLib::GetImageHeap() const { return pWeakLib->GetImageHeap(); }

struct ResourceBindData;
class ResourceBinding;
class LoadStates;

// Load-time data of a resource that is created per binding (an interface plus an opaque handle it reference
// counts). The exe's out-of-line ctor 0x1425a2b00 and operator= 0x1425a3110 are folded with ResourceKey's.
class ResourceData
{
public:
    typedef void* DataHandle;

    class DataInterface
    {
    public:
        typedef ResourceData::DataHandle DataHandle;

        virtual ~DataInterface() {}
        // The handle is a RefCountBase object unless overridden.
        virtual void AddRef(DataHandle hdata) { ((RefCountImpl*)hdata)->AddRef(); }
        virtual void Release(DataHandle hdata) { ((RefCountImpl*)hdata)->Release(); }
        // Creates the resource into pbindData->pResource; false on failure.
        virtual bool CreateResource(DataHandle hdata, ResourceBindData* pbindData, LoadStates* pls,
                                    MemoryHeap* pheap) const = 0;
    };

protected:
    DataInterface* pInterface;
    DataHandle     hData;

public:
    ResourceData() : pInterface(0), hData(0) {}
    ResourceData(DataInterface* pdi, DataHandle hdata)
    {
        if (pdi)
            pdi->AddRef(hdata);
        pInterface = pdi;
        hData      = hdata;
    }
    ResourceData(const ResourceData& src)
    {
        if (src.pInterface)
            src.pInterface->AddRef(src.hData);
        pInterface = src.pInterface;
        hData      = src.hData;
    }
    ~ResourceData()
    {
        if (pInterface)
            pInterface->Release(hData);
    }
    ResourceData& operator=(const ResourceData& src)
    {
        if (src.pInterface)
            src.pInterface->AddRef(src.hData);
        if (pInterface)
            pInterface->Release(hData);
        pInterface = src.pInterface;
        hData      = src.hData;
        return *this;
    }

    bool           IsValid() const          { return pInterface != 0; }
    DataInterface* GetDataInterface() const { return pInterface; }
    DataHandle     GetData() const          { return hData; }

    bool CreateResource(ResourceBindData* pbindData, LoadStates* pls, MemoryHeap* pheap) const
    {
        return pInterface ? pInterface->CreateResource(hData, pbindData, pls, pheap) : false;
    }
};

// A resource of a definition as the loader sees it: the resource itself, or its index in the binding of the movie
// (16 bytes). Pointer handles hold a reference.
class ResourceHandle
{
public:
    enum HandleType
    {
        RH_Pointer,
        RH_Index
    };

protected:
    HandleType HType; // +0
    union
    {
        Resource* pResource; // +8
        unsigned  BindIndex;
    };

    template<class C> friend class ResourcePtr;

public:
    ResourceHandle() : HType(RH_Pointer), pResource(0) {}
    ResourceHandle(Resource* pres) : HType(RH_Pointer), pResource(pres)
    {
        if (pres)
            pres->AddRef();
    }
    ResourceHandle(HandleType type, unsigned bindIndex) : HType(type) { BindIndex = bindIndex; }
    ResourceHandle(const ResourceHandle& src)
    {
        HType     = src.HType;
        pResource = src.pResource;
        if (HType == RH_Pointer && pResource)
            pResource->AddRef();
    }
    ~ResourceHandle()
    {
        if (HType == RH_Pointer && pResource)
            pResource->Release();
    }

    ResourceHandle& operator=(const ResourceHandle& src)
    {
        if (src.HType == RH_Pointer && src.pResource)
            src.pResource->AddRef();
        if (HType == RH_Pointer && pResource)
            pResource->Release();
        HType     = src.HType;
        pResource = src.pResource;
        return *this;
    }

    bool      IsIndex() const        { return HType == RH_Index; }
    Resource* GetResourcePtr() const { return HType == RH_Pointer ? pResource : 0; }

    unsigned GetBindIndex() const { return BindIndex; }
    bool     Equals(const ResourceHandle& other) const
    {
        return HType == other.HType && pResource == other.pResource;
    }
    // The resource, looked up in pbinding for index handles (defined in gfx_moviedef.h after ResourceBinding;
    // the exe also has an out-of-line copy, 0x14250d840).
    inline Resource* GetResource(ResourceBinding* pbinding) const;
    // Same, also returning the binding the resource came from (an imported movie's for imports).
    inline Resource* GetResourceAndBinding(ResourceBinding* pbinding, ResourceBinding** presBinding) const;
};

// A resource reference held by a definition, set from a handle (16 bytes).
template<class C>
class ResourcePtr
{
public:
    enum PtrType
    {
        RP_Resource,
        RP_Index
    };

    ResourcePtr() : PType(RP_Resource), pResource(0) {}
    ~ResourcePtr()
    {
        if (PType == RP_Resource && pResource)
            GetResource()->Release();
    }

    // C may be incomplete here; the resources derive from Resource first.
    Resource* GetResource() const { return (Resource*)pResource; }

    void SetFromHandle(const ResourceHandle& h)
    {
        if (h.HType == ResourceHandle::RH_Pointer && h.pResource)
            h.pResource->AddRef();
        if (PType == RP_Resource && pResource)
            GetResource()->Release();
        PType     = (PtrType)h.HType;
        pResource = (C*)h.pResource;
    }

protected:
    PtrType PType; // +0
    union
    {
        C*       pResource; // +8
        unsigned BindIndex;
    };

public:
    // (appended for the static text, sfr_gfx_05d)
    bool      IsIndex() const        { return PType == RP_Index; }
    unsigned  GetBindIndex() const   { return BindIndex; }
    Resource* GetResourcePtr() const { return (PType == RP_Resource) ? GetResource() : 0; }
};

}} // namespace Scaleform::GFx

#endif
