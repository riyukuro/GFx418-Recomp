// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 head of the GFx_Audio TU, which the
// exe places inside the queue range of sfr_render_01: the Audio state ctor/dtor, the AS2 builtin class registration of
// "Sound" and the ClassRegEntry hash set helpers it instantiates. Raw-layout free functions under the exe's own
// FUN_<va> names (the entries are {next, ASStringNode*, Register, Ptr<FunctionObject>} 0x20 bytes, table = {count,
// mask, entries}). FontResource::GetName (0x14259d950) is the out-of-line copy of the inline accessor.
// Sub-unit of queue unit sfr_render_01 (Render_Image 01, Render_Context/Renderer2D 01b, Text_StyledText 01c,
// Render_ImageFile 01d).
// MS2-UNIT: sfr_render_01e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425916c0-0x142591e10 .text$mn
// MS2-RANGE: 0x14259d950-0x14259d960 .text$mn
// MS2-FUNCTIONAL: raw-layout transcriptions of the exe's template instances; the algorithms and effects match.

#define MS2_AS2_VALUE_DTOR_CALL // the exe calls Value::~Value (0x1429260b0) out of line in this TU
#include "../gfx/sfr_gfx_07raw.h"
#include "ms2/scaleform/include/gfx/gfx_fontlib.h"
#include "ms2/scaleform/include/gfx/as2/as2_action.h"
#include "ms2/scaleform/include/gfx/as2/as2_soundobject.h"
#include "ms2/scaleform/include/gfx/xml/xml_support.h"   // XML::Support::ParseFile, folded with FUN_14259d950

namespace Scaleform { namespace GFx {

extern char DAT_143184be8[];
extern char DAT_143184c18[];


// ReleaseInternal is protected in RefCountBaseGC.
struct RefCountBaseGCAccess : AS2::RefCountBaseGC<323>
{
    using AS2::RefCountBaseGC<323>::ReleaseInternal;
};

typedef HashNode<ASString, AS2::GlobalContext::ClassRegEntry, ASStringHashFunctor> ClassRegNode;
typedef HashSetBase<ClassRegNode, ClassRegNode::NodeHashF, ClassRegNode::NodeAltHashF, AllocatorLH<ASString, 324>,
                    HashsetNodeEntry<ClassRegNode, ClassRegNode::NodeHashF> > ClassRegSet;

// The script object interface at +0x20 of an AS2 Object; slot 10 (+0x50) is SetMember.
struct RawObjectInterface
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual bool SetMember(void* psc, void* name, void* value, void* flags);
};

struct RawFontIntf
{
    virtual void s0();
    virtual const char* GetName();
};

// Counted GC reference: the count is the low 26 bits, flags above.
static inline void GCAddRef(void* p)
{
    unsigned& rc = RawField<unsigned>(p, 0x18);
    rc = (rc + 1) & 0x8fffffff;
}

static inline void GCRelease(void* p)
{
    if (p && (RawField<unsigned>(p, 0x18) & 0x3ffffff) != 0)
    {
        RawField<unsigned>(p, 0x18)--;
        reinterpret_cast<RefCountBaseGCAccess*>(p)->ReleaseInternal();
    }
}

static inline void StringAddRef(void* node) { RawField<int>(node, 0x18)++; }

static inline void StringRelease(void* node)
{
    if (--RawField<unsigned>(node, 0x18) == 0)
        reinterpret_cast<ASStringNode*>(node)->ReleaseNode();
}

// A {key, Register, Ptr} payload copied into a blank slot.
static inline void CopyPayload(char* d, const char* s)
{
    RawField<void*>(d, 0) = RawField<void*>(s, 0);
    StringAddRef(RawField<void*>(d, 0));
    RawField<U>(d, 8) = RawField<U>(s, 8);
    if (RawField<void*>(s, 0x10))
        GCAddRef(RawField<void*>(s, 0x10));
    RawField<void*>(d, 0x10) = RawField<void*>(s, 0x10);
}

static __forceinline void AssignNode(void* self, const void* src)
{
    void* key = RawField<void*>(src, 0);
    StringAddRef(key);
    StringRelease(RawField<void*>(self, 0));
    RawField<void*>(self, 0) = key;
    RawField<U>(self, 8) = RawField<U>(src, 8);
    void* p = RawField<void*>(src, 0x10);
    if (p)
        GCAddRef(p);
    GCRelease(RawField<void*>(self, 0x10));
    RawField<void*>(self, 0x10) = RawField<void*>(src, 0x10);
}

static __forceinline void AssignRef(void* self, const void* ref)
{
    void* key = *RawField<void**>(ref, 0);
    StringAddRef(key);
    StringRelease(RawField<void*>(self, 0));
    RawField<void*>(self, 0) = key;
    U* value = RawField<U*>(ref, 8);
    RawField<U>(self, 8) = value[0];
    void* p = (void*)value[1];
    if (p)
        GCAddRef(p);
    GCRelease(RawField<void*>(self, 0x10));
    RawField<void*>(self, 0x10) = (void*)value[1];
}

// HashNode::operator=(const HashNode&): the key and the registered function are replaced.
// @0x142591cf0
void* FUN_142591cf0(void* self, const void* src)
{
    AssignNode(self, src);
    return self;
}

static inline U NodeHash(const void* key) { return RawField<unsigned>(key, 0x1c); }

// HashNode::operator=(const NodeRef&)
// @0x142591d80
void FUN_142591d80(void* self, const void* ref)
{
    AssignRef(self, ref);
}

// the two key forms of the hash add: a HashNode {key, Register, Ptr} and a NodeRef {&key, &{Register, Ptr}}; the add
// reads the source when it builds the entry and calls the node assignments out of line
struct NodeSrc
{
    static __forceinline void* Key(const void* s) { return RawField<void*>(s, 0); }
    static __forceinline const U* Val(const void* s) { return &RawField<U>(s, 8); }
    static __forceinline void Assign(void* self, const void* s) { FUN_142591cf0(self, s); }
};
struct RefSrc
{
    static __forceinline void* Key(const void* s) { return *RawField<void**>(s, 0); }
    static __forceinline const U* Val(const void* s) { return RawField<U*>(s, 8); }
    static __forceinline void Assign(void* self, const void* s) { FUN_142591d80(self, s); }
};

// The entry at index i of a table {count, mask, entries}; the payload is at +8.
static inline char* ClassEntry(U* table, U i) { return (char*)table + 0x10 + i * 0x20; }

// HashSetBase::add after the table has room: the entry goes to its home slot, a squatter is moved out first.
template<class Src>
static __forceinline void ClassAdd(U** self, const void* src, U hash)
{
    hash &= (*self)[1];
    (*self)[0]++;
    SPInt index = hash;
    char* e = ClassEntry(*self, index);
    if (*(SPInt*)e == -2)
    {
        *(SPInt*)e = -1;
        RawField<void*>(e, 8) = Src::Key(src);
        StringAddRef(RawField<void*>(e, 8));
        const U* v = Src::Val(src);
        RawField<U>(e, 0x10) = v[0];
        if (v[1])
            GCAddRef((void*)v[1]);
        RawField<void*>(e, 0x18) = (void*)v[1];
    }
    else
    {
        SPInt blank = index;
        do
            blank = (blank + 1) & (*self)[1];
        while (*(SPInt*)ClassEntry(*self, blank) != -2);
        char* b = ClassEntry(*self, blank);
        if ((SPInt)(NodeHash(RawField<void*>(e, 8)) & (*self)[1]) == index)
        {
            *(SPInt*)b = *(SPInt*)e;
            CopyPayload(b + 8, e + 8);
            Src::Assign(e + 8, src);
            *(SPInt*)e = blank;
        }
        else
        {
            SPInt collided = NodeHash(RawField<void*>(e, 8)) & (*self)[1];
            for (;;)
            {
                SPInt* link = (SPInt*)ClassEntry(*self, collided);
                if (*link == index)
                {
                    *(SPInt*)b = *(SPInt*)e;
                    CopyPayload(b + 8, e + 8);
                    *link = blank;
                    break;
                }
                collided = *link;
            }
            Src::Assign(e + 8, src);
            *(SPInt*)e = -1;
        }
    }
}

// HashSetBase<HashNode<ASString, ClassRegEntry>>::add<HashNode>
// MS2-FUNCTIONAL 0x142591860: register allocation only (the exe keeps the hash in rdi and the source in r14); the
// same loads, stores and calls in the same order.
// @0x142591860
#pragma inline_depth(0)
void FUN_142591860(U** self, void* ctx, const void* node, U hash)
{
    reinterpret_cast<ClassRegSet*>(self)->CheckExpand(ctx);
    ClassAdd<NodeSrc>(self, node, hash);
}
#pragma inline_depth()

// The same for a NodeRef {&key, &{Register, Ptr}}, with the table growth inline.
// MS2-FUNCTIONAL 0x142591a00: register allocation only, as 0x142591860.
// @0x142591a00
void FUN_142591a00(U** self, void* ctx, const void* ref, U hash)
{
    reinterpret_cast<ClassRegSet*>(self)->CheckExpand(ctx);
    ClassAdd<RefSrc>(self, ref, hash);
}

// The builtin class registry entry of "Sound": registered on first use, then the class is published as a member.
// MS2-FUNCTIONAL: SDK registry lookup and SetMemberRaw; left: Value type store order around GetStringManager and
// the early vtable load (r10) for the SetMemberRaw call.
// @0x1425916c0
void FUN_1425916c0(void* self, void* psc, void* object)
{
    AS2::GlobalContext* pgc = reinterpret_cast<AS2::GlobalContext*>(self);
    const ASString& name = *reinterpret_cast<const ASString*>((char*)pgc->GetStringManager() + 0x40);
    if (!pgc->BuiltinClassesRegistry.Get(name))
    {
        {
            struct { void* Key; U* Value; } ref;
            U entry[2];
            entry[0] = (U)&AS2::SoundCtorFunction::Register;
            entry[1] = 0;
            ref.Key = &RawField<void*>(reinterpret_cast<AS2::GlobalContext*>(self)->GetStringManager(), 0x40);
            ref.Value = entry;
            FUN_142591a00(RawFieldPtr<U*>(self, 0x20), RawFieldPtr<void>(self, 0x20), &ref, NodeHash(*(void**)ref.Key));
            GCRelease((void*)entry[1]);
        }

        char flags = 0;
        {
            AS2::Value value;
            value.T.Type = AS2::Value::FUNCTIONNAME;
            value.V.pStringNode = RawField<ASStringNode*>(pgc->GetStringManager(), 0x40);
            value.V.pStringNode->AddRef();
            const ASString& key = *reinterpret_cast<const ASString*>((char*)pgc->GetStringManager() + 0x40);
            reinterpret_cast<AS2::Object*>(object)->SetMemberRaw(reinterpret_cast<AS2::ASStringContext*>(psc), key,
                                                                 value, reinterpret_cast<AS2::PropFlags&>(flags));
        }
    }
}

// Audio state: sync settings, the sound renderer (counted) and a default tag reader object.
// @0x142591be0
void* FUN_142591be0(void* self, void* renderer, float maxTimeDifference, unsigned checkFrameInterval, unsigned syncType)
{
    RawField<float>(self, 0x18) = maxTimeDifference;
    ::new (self) RefCountImplCore;
    RawField<unsigned>(self, 0x20) = syncType;
    RawField<void*>(self, 0) = DAT_143184be8;
    RawField<int>(self, 0x10) = 0x1d;
    RawField<unsigned>(self, 0x1c) = checkFrameInterval;
    if (renderer)
        FUN_14257dc30(renderer);
    RawField<void*>(self, 0x28) = renderer;
    RawField<void*>(self, 0x30) = 0;
    void* reader = Memory::pGlobalHeap->Alloc(0x10);
    if (reader)
    {
        RawField<int>(reader, 8) = 1;
        RawField<void*>(reader, 0) = DAT_143184c18;
        RawField<void*>(self, 0x30) = reader;
        return self;
    }
    RawField<void*>(self, 0x30) = 0;
    return self;
}
#ifndef MS2_HOOK_DLL
// the Audio ctor (0x142591be0): callers that construct GFx::Audio by name bind here
#pragma comment(linker, "/alternatename:??0Audio@GFx@Scaleform@@QEAA@PEAVSoundRenderer@Sound@2@MIW4SyncTypeFlags@AudioBase@12@@Z=?FUN_142591be0@GFx@Scaleform@@YAPEAXPEAX0MII@Z")
#endif

// @0x142591c90
void FUN_142591c90(void* self)
{
    RawField<void*>(self, 0) = DAT_143184be8;
    if (RawField<void*>(self, 0x30))
        FUN_14257dcd0(RawField<void*>(self, 0x30));
    if (RawField<void*>(self, 0x28))
        FUN_14257dcb0(RawField<void*>(self, 0x28));
    static_cast<State*>(self)->State::~State();
}

// @0x14259d950
const char* FUN_14259d950(FontResource* resource) { return RawField<RawFontIntf*>(resource, 0x18)->GetName(); }
// The XML support state forwards to its parser; the exe folds it with the one above (same three instructions).
bool XML::Support::ParseFile(const char* pfilename, FileOpenerBase* pfo, XML::ParserHandler* pdb) { return pParser->ParseFile(pfilename, pfo, pdb); }

}} // namespace Scaleform::GFx
