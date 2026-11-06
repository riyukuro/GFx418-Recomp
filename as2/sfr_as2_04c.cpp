// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 scalar deleting destructors of
// classes whose destructor bodies only chain to member/base destructors (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14292b820-0x14292b879 .text$mn
// MS2-RANGE: 0x14292b880-0x14292b904 .text$mn
// MS2-RANGE: 0x14292b910-0x14292b969 .text$mn
// MS2-RANGE: 0x14292b970-0x14292b9f4 .text$mn
// MS2-RANGE: 0x14292bb10-0x14292bb69 .text$mn
// MS2-RANGE: 0x14292bb70-0x14292bbde .text$mn
// MS2-RANGE: 0x14292bbe0-0x14292bc64 .text$mn
// MS2-RANGE: 0x14292bc70-0x14292bcc9 .text$mn
// MS2-RANGE: 0x14292bcd0-0x14292bd54 .text$mn
// MS2-RANGE: 0x14292bff0-0x14292c049 .text$mn
// MS2-RANGE: 0x14292c050-0x14292c0d4 .text$mn
// MS2-RANGE: 0x14292c0e0-0x14292c14e .text$mn
// MS2-RANGE: 0x14292c150-0x14292c1b5 .text$mn
// MS2-RANGE: 0x14292c1c0-0x14292c22e .text$mn
// MS2-RANGE: 0x14292c230-0x14292c2bd .text$mn
// MS2-RANGE: 0x14292c530-0x14292c59e .text$mn
// MS2-RANGE: 0x14292c620-0x14292c679 .text$mn
// MS2-RANGE: 0x14292c680-0x14292c6d9 .text$mn
// MS2-RANGE: 0x14292c6e0-0x14292c74e .text$mn
// MS2-RANGE: 0x14292c790-0x14292c814 .text$mn
// MS2-RANGE: 0x14292c820-0x14292c88e .text$mn
// MS2-RANGE: 0x14292c890-0x14292c8e9 .text$mn
// MS2-RANGE: 0x14292c8f0-0x14292c974 .text$mn
// MS2-RANGE: 0x14292c980-0x14292c9ee .text$mn
// MS2-RANGE: 0x14292c9f0-0x14292ca49 .text$mn
// MS2-RANGE: 0x14292ca50-0x14292cad4 .text$mn
// MS2-RANGE: 0x14292cb30-0x14292cb89 .text$mn
// MS2-RANGE: 0x14292cb90-0x14292cbfe .text$mn
// MS2-RANGE: 0x14292cc00-0x14292cc84 .text$mn
// MS2-RANGE: 0x14292cc90-0x14292cce9 .text$mn
// MS2-RANGE: 0x14292ccf0-0x14292cd6a .text$mn
// MS2-RANGE: 0x14292cd70-0x14292cdf4 .text$mn
// MS2-RANGE: 0x14292ce60-0x14292cece .text$mn
// MS2-RANGE: 0x14292ced0-0x14292cf29 .text$mn
// MS2-RANGE: 0x14292cf30-0x14292cfb4 .text$mn
// MS2-RANGE: 0x14292d040-0x14292d0ae .text$mn
// MS2-RANGE: 0x14292d1c0-0x14292d22e .text$mn
// MS2-RANGE: 0x14292d230-0x14292d295 .text$mn
// MS2-RANGE: 0x14292d2a0-0x14292d330 .text$mn
// MS2-RANGE: 0x14292d440-0x14292d4ae .text$mn
// MS2-RANGE: 0x14292d550-0x14292d5a9 .text$mn
// MS2-RANGE: 0x14292d5b0-0x14292d61e .text$mn
// MS2-RANGE: 0x14292d620-0x14292d691 .text$mn
// MS2-RANGE: 0x14292d6a0-0x14292d73c .text$mn
// MS2-RANGE: 0x14292d740-0x14292d7ae .text$mn
// MS2-RANGE: 0x14292d7b0-0x14292d82a .text$mn
// MS2-RANGE: 0x14292d830-0x14292d8d5 .text$mn
// MS2-RANGE: 0x14292d8e0-0x14292d94e .text$mn
// MS2-RANGE: 0x14292d950-0x14292d9a9 .text$mn
// MS2-RANGE: 0x14292d9b0-0x14292da37 .text$mn

namespace Scaleform { class Range; } // gfx_textfield.h (WIP header) names Range before declaring it
#define MS2_AS2_TEXTSNAPSHOT_CTOR_INLINE // MovieClip.getTextSnapshot inlines the TextSnapshotObject ctor
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/gfx/gfx_event.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_imageresource.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/video/video_statebag.h"
#include "../include/kernel/sf_alg.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/render/render_twips.h"
#include "../include/render/render_screentoworld.h"
#include "../include/kernel/sf_std.h"
#include "../include/render/text_core.h"
#include "../include/render/text_fontmanager.h"
#include "../include/render/render_font.h"
#include "../include/gfx/gfx_textsnapshot.h"
#include "../include/gfx/text_stylesheet.h"

void FUN_1424aa0f0(void* pthis);  // Render::Text::TextFormat destructor (global, as in sfr_as3_13/16z)

namespace Scaleform { namespace GFx { namespace AS2 {

// The NumberObject prototype destructor stays out of line (0x142925030).
template<> SF_NOINLINE Prototype<NumberObject, Environment>::~Prototype();
template<> SF_NOINLINE Prototype<TextFieldObject, Environment>::~Prototype();  // 0x1429250a0
}}}

namespace Scaleform {
// Out of line in the exe as well; the explicit-specialization declarations keep the dtors uninlined.
typedef HashNode<GFx::ASString, GFx::AS2::SharedObjectPtr, GFx::ASStringHashFunctor> Sfr04cHN1;
typedef HashSetBase<Sfr04cHN1, Sfr04cHN1::NodeHashF, Sfr04cHN1::NodeAltHashF, AllocatorLH<GFx::ASString, 324>,
    GFx::HashsetNodeEntry_GC<Sfr04cHN1, Sfr04cHN1::NodeHashF> > Sfr04cHashShared;
typedef StringLH_HashNode<GFx::AS2::MovieClipLoader::ProgressDesc, String::NoCaseHashFunctor> Sfr04cHN2;
typedef HashSetBase<Sfr04cHN2, Sfr04cHN2::NodeHashF, Sfr04cHN2::NodeAltHashF,
    AllocatorLH<GFx::AS2::MovieClipLoader::ProgressDesc, 2>, HashsetCachedNodeEntry<Sfr04cHN2, Sfr04cHN2::NodeHashF> >
    Sfr04cHashProgress;
template<> SF_NOINLINE Sfr04cHashShared::~HashSetBase();    // 0x1429248c0
template<> SF_NOINLINE Sfr04cHashProgress::~HashSetBase();  // 0x142924ab0
}

namespace Scaleform { namespace GFx { namespace AS2 {


// The Prototype<X> destructors called by name emit these vftables here as well.
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143215f60
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215fa8
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143216050
// MS2-PIN: ??_7?$Prototype@VMovieClipLoader@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216b68
// MS2-PIN: ??_7?$Prototype@VMovieClipLoader@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216bd8
// MS2-PIN: ??_7?$Prototype@VMovieClipLoader@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143216c80
// MS2-PIN: ??_7?$Prototype@VLoadVarsObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216fc8
// MS2-PIN: ??_7?$Prototype@VLoadVarsObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217010
// MS2-PIN: ??_7?$Prototype@VLoadVarsObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1432170b8
// MS2-PIN: ??_7?$Prototype@VMatrixObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218da0
// MS2-PIN: ??_7?$Prototype@VMatrixObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143218de8
// MS2-PIN: ??_7?$Prototype@VMatrixObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143218e90
// MS2-PIN: ??_7?$Prototype@VRectangleObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432195c0
// MS2-PIN: ??_7?$Prototype@VRectangleObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219608
// MS2-PIN: ??_7?$Prototype@VRectangleObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1432196b0
// MS2-PIN: ??_7?$Prototype@VTransformObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432199d0
// MS2-PIN: ??_7?$Prototype@VTransformObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219a18
// MS2-PIN: ??_7?$Prototype@VTransformObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143219ac0
// MS2-PIN: ??_7?$Prototype@VPointObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a1f0
// MS2-PIN: ??_7?$Prototype@VPointObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a238
// MS2-PIN: ??_7?$Prototype@VPointObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321a2e0
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a600
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a648
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321a6f0
// MS2-PIN: ??_7?$Prototype@VMath@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ba50
// MS2-PIN: ??_7?$Prototype@VMath@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ba98
// MS2-PIN: ??_7?$Prototype@VMath@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321bb40
// MS2-PIN: ??_7?$Prototype@VKeyObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c6d8
// MS2-PIN: ??_7?$Prototype@VKeyObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c720
// MS2-PIN: ??_7?$Prototype@VKeyObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321c7c8
// MS2-PIN: ??_7?$Prototype@VMouseObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321cb08
// MS2-PIN: ??_7?$Prototype@VMouseObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321cb50
// MS2-PIN: ??_7?$Prototype@VMouseObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321cbf8
// MS2-PIN: ??_7?$Prototype@VSelection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d368
// MS2-PIN: ??_7?$Prototype@VSelection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d3b0
// MS2-PIN: ??_7?$Prototype@VSelection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321d458
// MS2-PIN: ??_7?$Prototype@VSharedObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321db88
// MS2-PIN: ??_7?$Prototype@VSharedObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321dbd0
// MS2-PIN: ??_7?$Prototype@VSharedObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321dc78

// The base vftables the inlined destructors store.

// ~TextSnapshotObject (out of line at 0x142925f70, sfr_as2_03; `inline` there under cl) inlines into the deleting dtors.
// It is protected: a derived view runs it.
inline TextSnapshotObject::~TextSnapshotObject() { GetData().~StaticTextSnapshotData(); }
// Out of line at 0x1429255a0 in sfr_as2_03 (`inline` there under cl, so both copies are COMDAT-any). The deleting
// dtors below inline it (the two FunctionObject vftable stores).
inline FunctionObject::~FunctionObject()
{
}
struct Sfr_TextSnapshotObjectDtor : TextSnapshotObject
{
    static void Destroy(void* p) { static_cast<Sfr_TextSnapshotObjectDtor*>(p)->TextSnapshotObject::~TextSnapshotObject(); }
};

// @0x14292b820
void* DeleteAs2_14292b820(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292b880
void* DeleteAs2_14292b880(void* p, unsigned flags)
{
    static_cast<Prototype<KeyObject, Environment>*>(p)->Prototype<KeyObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292b910
void* DeleteAs2_14292b910(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x78);
    }
    return p;
}

// @0x14292b970
void* DeleteAs2_14292b970(void* p, unsigned flags)
{
    static_cast<Prototype<LoadVarsObject, Environment>*>(p)->Prototype<LoadVarsObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb8);
    }
    return p;
}

// @0x14292bb10
void* DeleteAs2_14292bb10(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292bb70
void* DeleteAs2_14292bb70(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292bbe0
void* DeleteAs2_14292bbe0(void* p, unsigned flags)
{
    static_cast<Prototype<Math, Environment>*>(p)->Prototype<Math, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292bc70
void* DeleteAs2_14292bc70(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292bcd0
void* DeleteAs2_14292bcd0(void* p, unsigned flags)
{
    static_cast<Prototype<MatrixObject, Environment>*>(p)->Prototype<MatrixObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292bff0
void* DeleteAs2_14292bff0(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292c050
void* DeleteAs2_14292c050(void* p, unsigned flags)
{
    static_cast<Prototype<MouseObject, Environment>*>(p)->Prototype<MouseObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292c0e0
void* DeleteAs2_14292c0e0(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292c150
void* DeleteAs2_14292c150(void* p, unsigned flags)
{
    reinterpret_cast<Sfr04cHashProgress*>((char*)p+0x68)->~Sfr04cHashProgress();
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292c1c0
void* DeleteAs2_14292c1c0(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292c230
void* DeleteAs2_14292c230(void* p, unsigned flags)
{
    static_cast<Prototype<MovieClipLoader, Environment>*>(p)->Prototype<MovieClipLoader, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb0);
    }
    return p;
}

// @0x14292c530
void* DeleteAs2_14292c530(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292c620
void* DeleteAs2_14292c620(void* p, unsigned flags)
{
    static_cast<Prototype<NumberObject, Environment>*>(p)->Prototype<NumberObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb8);
    }
    return p;
}

// @0x14292c680
void* DeleteAs2_14292c680(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292c6e0
void* DeleteAs2_14292c6e0(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292c790
void* DeleteAs2_14292c790(void* p, unsigned flags)
{
    static_cast<Prototype<Object, Environment>*>(p)->Prototype<Object, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292c820
void* DeleteAs2_14292c820(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292c890
void* DeleteAs2_14292c890(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292c8f0
void* DeleteAs2_14292c8f0(void* p, unsigned flags)
{
    static_cast<Prototype<PointObject, Environment>*>(p)->Prototype<PointObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292c980
void* DeleteAs2_14292c980(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292c9f0
void* DeleteAs2_14292c9f0(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292ca50
void* DeleteAs2_14292ca50(void* p, unsigned flags)
{
    static_cast<Prototype<RectangleObject, Environment>*>(p)->Prototype<RectangleObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292cb30
void* DeleteAs2_14292cb30(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292cb90
void* DeleteAs2_14292cb90(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292cc00
void* DeleteAs2_14292cc00(void* p, unsigned flags)
{
    static_cast<Prototype<Selection, Environment>*>(p)->Prototype<Selection, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292cc90
void* DeleteAs2_14292cc90(void* p, unsigned flags)
{
    static_cast<SharedObject*>(p)->SharedObject::~SharedObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x78);
    }
    return p;
}

// @0x14292ccf0
void* DeleteAs2_14292ccf0(void* p, unsigned flags)
{
    reinterpret_cast<Sfr04cHashShared*>((char*)p+0x70)->~Sfr04cHashShared();
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x78);
    }
    return p;
}

// @0x14292cd70
void* DeleteAs2_14292cd70(void* p, unsigned flags)
{
    static_cast<Prototype<SharedObject, Environment>*>(p)->Prototype<SharedObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb8);
    }
    return p;
}

// @0x14292ce60
void* DeleteAs2_14292ce60(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x78);
    }
    return p;
}

// @0x14292ced0
void* DeleteAs2_14292ced0(void* p, unsigned flags)
{
    static_cast<Object*>(p)->Object::~Object();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x68);
    }
    return p;
}

// @0x14292cf30
void* DeleteAs2_14292cf30(void* p, unsigned flags)
{
    static_cast<Prototype<StageObject, Environment>*>(p)->Prototype<StageObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xa8);
    }
    return p;
}

// @0x14292d040
void* DeleteAs2_14292d040(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292d1c0
void* DeleteAs2_14292d1c0(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292d230
void* DeleteAs2_14292d230(void* p, unsigned flags)
{
    static_cast<StyleSheetObject*>(p)->StyleSheetObject::~StyleSheetObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x98);
    }
    return p;
}

// @0x14292d2a0
void* DeleteAs2_14292d2a0(void* p, unsigned flags)
{
    static_cast<Prototype<StyleSheetObject, Environment>*>(p)->Prototype<StyleSheetObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xd8);
    }
    return p;
}

// @0x14292d440
void* DeleteAs2_14292d440(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292d550
void* DeleteAs2_14292d550(void* p, unsigned flags)
{
    static_cast<Prototype<TextFieldObject, Environment>*>(p)->Prototype<TextFieldObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xb8);
    }
    return p;
}

// @0x14292d5b0
void* DeleteAs2_14292d5b0(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292d620
void* DeleteAs2_14292d620(void* p, unsigned flags)
{
    static_cast<TextFormatObject*>(p)->TextFormatObject::~TextFormatObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xd0);
    }
    return p;
}

// @0x14292d6a0
void* DeleteAs2_14292d6a0(void* p, unsigned flags)
{
    static_cast<Prototype<TextFormatObject, Environment>*>(p)->Prototype<TextFormatObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x110);
    }
    return p;
}

// @0x14292d740
void* DeleteAs2_14292d740(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292d7b0
void* DeleteAs2_14292d7b0(void* p, unsigned flags)
{
    Sfr_TextSnapshotObjectDtor::Destroy(p);
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x90);
    }
    return p;
}

// @0x14292d830
void* DeleteAs2_14292d830(void* p, unsigned flags)
{
    static_cast<Prototype<TextSnapshotObject, Environment>*>(p)->Prototype<TextSnapshotObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xd0);
    }
    return p;
}

// @0x14292d8e0
void* DeleteAs2_14292d8e0(void* p, unsigned flags)
{
    static_cast<FunctionObject*>(p)->FunctionObject::~FunctionObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x70);
    }
    return p;
}

// @0x14292d950
void* DeleteAs2_14292d950(void* p, unsigned flags)
{
    static_cast<TransformObject*>(p)->TransformObject::~TransformObject();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x90);
    }
    return p;
}

// @0x14292d9b0
void* DeleteAs2_14292d9b0(void* p, unsigned flags)
{
    static_cast<Prototype<TransformObject, Environment>*>(p)->Prototype<TransformObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0xd0);
    }
    return p;
}

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ??_7TextSnapshotObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e2c8
// MS2-PIN: ??_7TextSnapshotObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e310
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
// MS2-PIN: ??_7?$Prototype@VTextSnapshotObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e3b8
// MS2-PIN: ??_7?$Prototype@VTextSnapshotObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321e4a8
// MS2-PIN: ??_7?$Prototype@VTextSnapshotObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e400
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d778
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d7c0
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321d868
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432173f8
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217440
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1432174e8
