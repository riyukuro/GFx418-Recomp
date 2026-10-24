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

#include "../gfx/sfr_gfx_07raw.h"
#include "ms2/scaleform/include/gfx/gfx_fontlib.h"

namespace Scaleform { namespace GFx {

extern char DAT_142dc9d48[];
extern char DAT_143109420[];
extern char DAT_143184be8[];
extern char DAT_143184c18[];

char* FUN_1429561c0(void*);          // GlobalContext::GetStringManager
void  FUN_1429260b0(void*);          // Value::~Value
void  FUN_1425c14e0(void*);          // ASStringNode::ReleaseNode
void  FUN_1425925f0(void*);          // RefCountBaseGC<323>::ReleaseInternal
void  FUN_1425921b0(U**, void*);     // HashSetBase::CheckExpand
void  FUN_142592a10(U**, void*, U);  // HashSetBase::setRawCapacity
void  FUN_14257db40(void*);          // RefCountImplCore::~RefCountImplCore
void  FUN_14257dcd0(void*);          // RefCountNTSImpl::Release
void* FUN_142998b50(void*);          // SoundCtorFunction::Register

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
        FUN_1425925f0(p);
    }
}

static inline void StringAddRef(void* node) { RawField<int>(node, 0x18)++; }

static inline void StringRelease(void* node)
{
    if (--RawField<int>(node, 0x18) == 0)
        FUN_1425c14e0(node);
}

// A {key, Register, Ptr} payload copied into a blank slot.
static inline void CopyPayload(char* d, const char* s)
{
    void* key = RawField<void*>(s, 0);
    StringAddRef(key);
    RawField<void*>(d, 0) = key;
    RawField<U>(d, 8) = RawField<U>(s, 8);
    void* p = RawField<void*>(s, 0x10);
    if (p)
        GCAddRef(p);
    RawField<void*>(d, 0x10) = p ? RawField<void*>(s, 0x10) : 0;
}

static inline void AssignNode(void* self, const void* src)
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

static inline void AssignRef(void* self, const void* ref)
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

// The entry at index i of a table {count, mask, entries}; the payload is at +8.
static inline char* ClassEntry(U* table, U i) { return (char*)table + 0x10 + i * 0x20; }

// HashSetBase::add after the table has room: the entry goes to its home slot, a squatter is moved out first.
template<void (*Assign)(void*, const void*)>
static inline void ClassAdd(U** self, void* key, U fn, void* ptr, const void* src, U hash)
{
    U* table = *self;
    U home = hash & table[1];
    table[0]++;
    table = *self;
    char* e = ClassEntry(table, home);
    if (*(SPInt*)e == -2)
    {
        *(SPInt*)e = -1;
        StringAddRef(key);
        RawField<void*>(e, 8) = key;
        RawField<U>(e, 0x10) = fn;
        if (ptr)
            GCAddRef(ptr);
        RawField<void*>(e, 0x18) = ptr ? ptr : 0;
    }
    else
    {
        U blank = home;
        do
            blank = (blank + 1) & table[1];
        while (*(SPInt*)ClassEntry(table, blank) != -2);
        char* b = ClassEntry(table, blank);
        U squatterHome = NodeHash(RawField<void*>(e, 8)) & table[1];
        if (squatterHome == home)
        {
            *(SPInt*)b = *(SPInt*)e;
            CopyPayload(b + 8, e + 8);
            Assign(e + 8, src);
            *(U*)e = blank;
        }
        else
        {
            U* link = (U*)ClassEntry(table, squatterHome);
            U next = *link;
            while (next != home)
            {
                link = (U*)ClassEntry(table, next);
                next = *link;
            }
            *(SPInt*)b = *(SPInt*)e;
            CopyPayload(b + 8, e + 8);
            *link = blank;
            Assign(e + 8, src);
            *(SPInt*)e = -1;
        }
    }
}

// HashSetBase<HashNode<ASString, ClassRegEntry>>::add<HashNode>
// @0x142591860
void FUN_142591860(U** self, void* ctx, const void* node, U hash)
{
    FUN_1425921b0(self, ctx);
    ClassAdd<AssignNode>(self, RawField<void*>(node, 0), RawField<U>(node, 8), RawField<void*>(node, 0x10), node, hash);
}

// The same for a NodeRef {&key, &{Register, Ptr}}, with the table growth inline.
// @0x142591a00
void FUN_142591a00(U** self, void* ctx, const void* ref, U hash)
{
    U* table = *self;
    if (!table)
        FUN_142592a10(self, ctx, 8);
    else if (table[0] * 5 > table[1] * 4 + 4)
        FUN_142592a10(self, ctx, table[1] * 2 + 2);
    U* value = RawField<U*>(ref, 8);
    ClassAdd<AssignRef>(self, *RawField<void**>(ref, 0), value[0], (void*)value[1], ref, hash);
}

// The builtin class registry entry of "Sound": registered on first use, then the class is published as a member.
// @0x1425916c0
void FUN_1425916c0(void* self, void* psc, void* object)
{
    char* sm = FUN_1429561c0(self);
    U* table = RawField<U*>(self, 0x20);
    void* key = RawField<void*>(sm, 0x40);
    char* found = 0;
    if (table)
    {
        U hash = NodeHash(key);
        U mask = table[1];
        U idx = hash & mask;
        char* e = ClassEntry(table, idx);
        if (*(SPInt*)e != -2 && (NodeHash(RawField<void*>(e, 8)) & mask) == idx)
        {
            U at = idx;
            while ((NodeHash(RawField<void*>(e, 8)) & mask) != idx || RawField<void*>(e, 8) != key)
            {
                at = *(U*)e;
                if (at == (U)-1)
                    goto notFound;
                e = ClassEntry(table, at);
            }
            if ((SPInt)at >= 0)
                found = (char*)table + 0x18 + at * 0x20;
        }
    }
notFound:
    if ((found ? found + 8 : 0) == 0)
    {
        struct { void* Key; U* Value; } ref;
        U entry[2];
        entry[0] = (U)&FUN_142998b50;
        entry[1] = 0;
        ref.Key = &RawField<void*>(FUN_1429561c0(self), 0x40);
        ref.Value = entry;
        FUN_142591a00(RawFieldPtr<U*>(self, 0x20), RawFieldPtr<void>(self, 0x20), &ref, NodeHash(*(void**)ref.Key));
        GCRelease((void*)entry[1]);

        char flags = 0;
        sm = FUN_1429561c0(self);
        U value[2];
        value[0] = 0xb;
        value[1] = RawField<U>(sm, 0x40);
        StringAddRef((void*)value[1]);
        RawFieldPtr<RawObjectInterface>(object, 0x20)->SetMember(psc, sm + 0x40, value, &flags);
        FUN_1429260b0(value);
    }
}

// Audio state: sync settings, the sound renderer (counted) and a default tag reader object.
// @0x142591be0
void* FUN_142591be0(void* self, void* renderer, float maxTimeDifference, unsigned checkFrameInterval, unsigned syncType)
{
    RawField<float>(self, 0x18) = maxTimeDifference;
    RawField<void*>(self, 0) = DAT_142dc9d48;
    RawField<unsigned>(self, 0x20) = syncType;
    RawField<void*>(self, 0) = DAT_143184be8;
    RawField<int>(self, 8) = 1;
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

// @0x142591c90
void FUN_142591c90(void* self)
{
    RawField<void*>(self, 0) = DAT_143184be8;
    if (RawField<void*>(self, 0x30))
        FUN_14257dcd0(RawField<void*>(self, 0x30));
    if (RawField<void*>(self, 0x28))
        FUN_14257dcb0(RawField<void*>(self, 0x28));
    RawField<void*>(self, 0) = DAT_143109420;
    FUN_14257db40(self);
}

// @0x14259d950
const char* FUN_14259d950(FontResource* resource)
{
    return RawField<RawFontIntf*>(resource, 0x18)->GetName();
}

}} // namespace Scaleform::GFx
