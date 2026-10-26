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

namespace Scaleform { namespace GFx { namespace AS2 {

void FUN_1424aa050(void* pthis);
void FUN_1424aa0f0(void* pthis);
void FUN_142606690(void* pthis);
void FUN_142609070(void* pthis);
void FUN_1429248c0(void* pthis);
void FUN_142924ab0(void* pthis);
void FUN_142925030(void* pthis);
void FUN_1429250a0(void* pthis);
void FUN_142925750(void* pthis);
void FUN_142925cf0(void* pthis);
void FUN_142925e70(void* pthis);
void FUN_142925fb0(void* pthis);

// The base vftables the inlined destructors store.
extern const void* DAT_1432155c0[];
extern const void* DAT_143215648[];
extern const void* DAT_143215f60[];
extern const void* DAT_143215fa8[];
extern const void* DAT_143216050[];
extern const void* DAT_143216b68[];
extern const void* DAT_143216bd8[];
extern const void* DAT_143216c80[];
extern const void* DAT_143216fc8[];
extern const void* DAT_143217010[];
extern const void* DAT_1432170b8[];
extern const void* DAT_1432173f8[];
extern const void* DAT_143217440[];
extern const void* DAT_1432174e8[];
extern const void* DAT_143218da0[];
extern const void* DAT_143218de8[];
extern const void* DAT_143218e90[];
extern const void* DAT_1432195c0[];
extern const void* DAT_143219608[];
extern const void* DAT_1432196b0[];
extern const void* DAT_1432199d0[];
extern const void* DAT_143219a18[];
extern const void* DAT_143219ac0[];
extern const void* DAT_14321a1f0[];
extern const void* DAT_14321a238[];
extern const void* DAT_14321a2e0[];
extern const void* DAT_14321a600[];
extern const void* DAT_14321a648[];
extern const void* DAT_14321a6f0[];
extern const void* DAT_14321ba50[];
extern const void* DAT_14321ba98[];
extern const void* DAT_14321bb40[];
extern const void* DAT_14321c6d8[];
extern const void* DAT_14321c720[];
extern const void* DAT_14321c7c8[];
extern const void* DAT_14321cb08[];
extern const void* DAT_14321cb50[];
extern const void* DAT_14321cbf8[];
extern const void* DAT_14321d368[];
extern const void* DAT_14321d3b0[];
extern const void* DAT_14321d458[];
extern const void* DAT_14321d778[];
extern const void* DAT_14321d7c0[];
extern const void* DAT_14321d868[];
extern const void* DAT_14321db88[];
extern const void* DAT_14321dbd0[];
extern const void* DAT_14321dc78[];
extern const void* DAT_14321e2c8[];
extern const void* DAT_14321e310[];
extern const void* DAT_14321e3b8[];
extern const void* DAT_14321e400[];
extern const void* DAT_14321e4a8[];

// @0x14292b820
void* DeleteAs2_14292b820(void* p, unsigned flags)
{
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321c6d8;
    *(const void**)((char*)p+0x20) = DAT_14321c720;
    *(const void**)((char*)p+0x68) = DAT_14321c7c8;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_143216fc8;
    *(const void**)((char*)p+0x20) = DAT_143217010;
    *(const void**)((char*)p+0x78) = DAT_1432170b8;
    FUN_142925750((void*)((char*)p+0x78));
    FUN_142925cf0(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321ba50;
    *(const void**)((char*)p+0x20) = DAT_14321ba98;
    *(const void**)((char*)p+0x68) = DAT_14321bb40;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_143218da0;
    *(const void**)((char*)p+0x20) = DAT_143218de8;
    *(const void**)((char*)p+0x68) = DAT_143218e90;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321cb08;
    *(const void**)((char*)p+0x20) = DAT_14321cb50;
    *(const void**)((char*)p+0x68) = DAT_14321cbf8;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_142924ab0((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_143216b68;
    *(const void**)((char*)p+0x20) = DAT_143216bd8;
    *(const void**)((char*)p+0x70) = DAT_143216c80;
    FUN_142925750((void*)((char*)p+0x70));
    FUN_142924ab0((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_142925030(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_143215f60;
    *(const void**)((char*)p+0x20) = DAT_143215fa8;
    *(const void**)((char*)p+0x68) = DAT_143216050;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321a1f0;
    *(const void**)((char*)p+0x20) = DAT_14321a238;
    *(const void**)((char*)p+0x68) = DAT_14321a2e0;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432195c0;
    *(const void**)((char*)p+0x20) = DAT_143219608;
    *(const void**)((char*)p+0x68) = DAT_1432196b0;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321d368;
    *(const void**)((char*)p+0x20) = DAT_14321d3b0;
    *(const void**)((char*)p+0x68) = DAT_14321d458;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    FUN_142925e70(p);
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
    FUN_1429248c0((void*)((char*)p+0x70));
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321db88;
    *(const void**)((char*)p+0x20) = DAT_14321dbd0;
    *(const void**)((char*)p+0x78) = DAT_14321dc78;
    FUN_142925750((void*)((char*)p+0x78));
    FUN_142925e70(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321a600;
    *(const void**)((char*)p+0x20) = DAT_14321a648;
    *(const void**)((char*)p+0x68) = DAT_14321a6f0;
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_142609070((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432173f8;
    *(const void**)((char*)p+0x20) = DAT_143217440;
    *(const void**)((char*)p+0x98) = DAT_1432174e8;
    FUN_142925750((void*)((char*)p+0x98));
    FUN_142609070((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_1429250a0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_142606690((void*)((char*)p+0xb0));
    FUN_1424aa0f0((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321d778;
    *(const void**)((char*)p+0x20) = DAT_14321d7c0;
    *(const void**)((char*)p+0xd0) = DAT_14321d868;
    FUN_142925750((void*)((char*)p+0xd0));
    FUN_142606690((void*)((char*)p+0xb0));
    FUN_1424aa0f0((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321e2c8;
    *(const void**)((char*)p+0x20) = DAT_14321e310;
    FUN_1424aa050((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_14321e3b8;
    *(const void**)((char*)p+0x20) = DAT_14321e400;
    *(const void**)((char*)p+0x90) = DAT_14321e4a8;
    FUN_142925750((void*)((char*)p+0x90));
    *(const void**)p = DAT_14321e2c8;
    *(const void**)((char*)p+0x20) = DAT_14321e310;
    FUN_1424aa050((void*)((char*)p+0x68));
    FUN_142925cf0(p);
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
    *(const void**)p = DAT_1432155c0;
    *(const void**)((char*)p+0x20) = DAT_143215648;
    FUN_142925cf0(p);
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
    FUN_142925fb0(p);
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
    *(const void**)p = DAT_1432199d0;
    *(const void**)((char*)p+0x20) = DAT_143219a18;
    *(const void**)((char*)p+0x90) = DAT_143219ac0;
    FUN_142925750((void*)((char*)p+0x90));
    FUN_142925fb0(p);
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
