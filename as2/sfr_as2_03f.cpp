// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 scalar deleting destructors of
// classes whose destructor bodies only chain to member/base destructors (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_03f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142928370-0x1429283f4 .text$mn
// MS2-RANGE: 0x142928770-0x142928800 .text$mn
// MS2-RANGE: 0x142928800-0x142928859 .text$mn
// MS2-RANGE: 0x142928aa0-0x142928af9 .text$mn
// MS2-RANGE: 0x142928b00-0x142928b59 .text$mn
// MS2-RANGE: 0x142928bb0-0x142928c09 .text$mn
// MS2-RANGE: 0x142928c10-0x142928c69 .text$mn
// MS2-RANGE: 0x142928d00-0x142928d49 .text$mn
// MS2-RANGE: 0x142928d50-0x142928db3 .text$mn

namespace Scaleform { class Range; } // gfx_textfield.h (WIP header) names Range before declaring it
#define MS2_AS2_TEXTSNAPSHOT_CTOR_INLINE // MovieClip.getTextSnapshot inlines the TextSnapshotObject ctor
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_loadqueue.h"
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
#include "../include/gfx/text_stylesheet.h"
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

namespace Scaleform { namespace GFx { namespace AS2 {

// The Prototype<TextFieldObject> dtor, called out of line (the real dtor inlines here: 9 -> 8 matched).
template<> SF_NOINLINE Prototype<TextFieldObject, Environment>::~Prototype();  // 0x1429250a0

// The Prototype<X> destructors called by name emit these vftables here as well.
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143216050
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143215f60
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215fa8
// MS2-PIN: ??_7ObjectInterface@Value@GFx@Scaleform@@6B@ 0x14317bc90
// MS2-PIN: ??_7ASCSSFileLoader@AS2@GFx@Scaleform@@6B@ 0x1432172f0

// @0x142928370
void* DeleteAs2_142928370(void* p, unsigned flags)
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

// @0x142928770
void* DeleteAs2_142928770(void* p, unsigned flags)
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

// @0x142928800
void* DeleteAs2_142928800(void* p, unsigned flags)
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

// @0x142928aa0
void* DeleteAs2_142928aa0(void* p, unsigned flags)
{
    static_cast<RefCountImplCore*>(p)->RefCountImplCore::~RefCountImplCore();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x10);
    }
    return p;
}

// @0x142928b00
void* DeleteAs2_142928b00(void* p, unsigned flags)
{
    static_cast<RefCountImplCore*>(p)->RefCountImplCore::~RefCountImplCore();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x10);
    }
    return p;
}

// @0x142928bb0
void* DeleteAs2_142928bb0(void* p, unsigned flags)
{
    static_cast<RefCountNTSImplCore*>(p)->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x10);
    }
    return p;
}

// @0x142928c10
void* DeleteAs2_142928c10(void* p, unsigned flags)
{
    static_cast<RefCountNTSImplCore*>(p)->RefCountNTSImplCore::~RefCountNTSImplCore();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x10);
    }
    return p;
}

// @0x142928d00
void* DeleteAs2_142928d00(void* p, unsigned flags)
{
    static_cast<Scaleform::GFx::Value::ObjectInterface*>(p)->Scaleform::GFx::Value::ObjectInterface::~ObjectInterface();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x10);
    }
    return p;
}

// @0x142928d50
void* DeleteAs2_142928d50(void* p, unsigned flags)
{
    static_cast<ASCSSFileLoader*>(p)->ASCSSFileLoader::~ASCSSFileLoader();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x10);
    }
    return p;
}

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432173f8
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217440
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1432174e8
