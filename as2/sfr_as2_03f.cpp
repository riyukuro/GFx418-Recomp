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

void FUN_14257db40(void* pthis);
void FUN_14257db50(void* pthis);
void FUN_142609070(void* pthis);
void FUN_1429250a0(void* pthis);
void FUN_142925750(void* pthis);
void FUN_142925cf0(void* pthis);

// @0x142928370
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928370(void* p, unsigned flags)
{
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928770
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928770(void* p, unsigned flags)
{
    FUN_142925750((void*)((char*)p+0x98));
    FUN_142609070((void*)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928800
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928800(void* p, unsigned flags)
{
    FUN_1429250a0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928aa0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928aa0(void* p, unsigned flags)
{
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928b00
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928b00(void* p, unsigned flags)
{
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928bb0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928bb0(void* p, unsigned flags)
{
    FUN_14257db50(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928c10
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928c10(void* p, unsigned flags)
{
    FUN_14257db50(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928d00
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928d00(void* p, unsigned flags)
{
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142928d50
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142928d50(void* p, unsigned flags)
{
    FUN_14257db40(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

}}} // namespace Scaleform::GFx::AS2
