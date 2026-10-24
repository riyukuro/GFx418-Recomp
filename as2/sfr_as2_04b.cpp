// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 scalar deleting destructors of
// classes whose destructor bodies only chain to member/base destructors (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429297a0-0x14292980e .text$mn
// MS2-RANGE: 0x142929810-0x14292988f .text$mn
// MS2-RANGE: 0x142929890-0x1429298e9 .text$mn
// MS2-RANGE: 0x1429298f0-0x14292997d .text$mn
// MS2-RANGE: 0x142929980-0x1429299ee .text$mn
// MS2-RANGE: 0x1429299f0-0x142929a49 .text$mn
// MS2-RANGE: 0x142929a50-0x142929abe .text$mn
// MS2-RANGE: 0x142929ac0-0x142929b3f .text$mn
// MS2-RANGE: 0x142929b40-0x142929b99 .text$mn
// MS2-RANGE: 0x142929ba0-0x142929c0e .text$mn
// MS2-RANGE: 0x142929c10-0x142929c8f .text$mn
// MS2-RANGE: 0x142929c90-0x142929ce9 .text$mn
// MS2-RANGE: 0x142929cf0-0x142929d5e .text$mn
// MS2-RANGE: 0x142929d60-0x142929db9 .text$mn
// MS2-RANGE: 0x142929dc0-0x142929e44 .text$mn
// MS2-RANGE: 0x142929e50-0x142929ebe .text$mn
// MS2-RANGE: 0x142929fe0-0x14292a04e .text$mn
// MS2-RANGE: 0x14292a1d0-0x14292a23e .text$mn
// MS2-RANGE: 0x14292a240-0x14292a2ae .text$mn
// MS2-RANGE: 0x14292a2b0-0x14292a31e .text$mn
// MS2-RANGE: 0x14292a320-0x14292a39f .text$mn
// MS2-RANGE: 0x14292a3a0-0x14292a3f9 .text$mn
// MS2-RANGE: 0x14292a520-0x14292a58e .text$mn
// MS2-RANGE: 0x14292a590-0x14292a5e9 .text$mn
// MS2-RANGE: 0x14292a5f0-0x14292a677 .text$mn
// MS2-RANGE: 0x14292a700-0x14292a76e .text$mn
// MS2-RANGE: 0x14292a770-0x14292a7c9 .text$mn
// MS2-RANGE: 0x14292a7d0-0x14292a857 .text$mn
// MS2-RANGE: 0x14292a860-0x14292a8ce .text$mn
// MS2-RANGE: 0x14292a8d0-0x14292a94f .text$mn
// MS2-RANGE: 0x14292a950-0x14292a9a9 .text$mn
// MS2-RANGE: 0x14292a9e0-0x14292aa39 .text$mn
// MS2-RANGE: 0x14292aa40-0x14292aa99 .text$mn
// MS2-RANGE: 0x14292aaa0-0x14292ab0e .text$mn
// MS2-RANGE: 0x14292ab10-0x14292ab94 .text$mn
// MS2-RANGE: 0x14292abd0-0x14292ac3e .text$mn
// MS2-RANGE: 0x14292ac40-0x14292acae .text$mn
// MS2-RANGE: 0x14292acb0-0x14292ad34 .text$mn
// MS2-RANGE: 0x14292ade0-0x14292ae4e .text$mn
// MS2-RANGE: 0x14292ae50-0x14292aebe .text$mn
// MS2-RANGE: 0x14292aec0-0x14292af2e .text$mn
// MS2-RANGE: 0x14292b1e0-0x14292b262 .text$mn
// MS2-RANGE: 0x14292b270-0x14292b300 .text$mn
// MS2-RANGE: 0x14292b300-0x14292b382 .text$mn
// MS2-RANGE: 0x14292b470-0x14292b4da .text$mn
// MS2-RANGE: 0x14292b590-0x14292b5fe .text$mn
// MS2-RANGE: 0x14292b600-0x14292b67f .text$mn
// MS2-RANGE: 0x14292b680-0x14292b6d9 .text$mn
// MS2-RANGE: 0x14292b710-0x14292b769 .text$mn
// MS2-RANGE: 0x14292b7a0-0x14292b819 .text$mn

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

void FUN_14257dcb0(void* pthis);
void FUN_14257dcd0(void* pthis);
void FUN_1425a4030(void* pthis);
void FUN_1425f0a60(void* pthis);
void FUN_142639d10(void* pthis);
void FUN_142924d20(void* pthis);
void FUN_142924d90(void* pthis);
void FUN_142924e00(void* pthis);
void FUN_142924e70(void* pthis);
void FUN_142924ee0(void* pthis);
void FUN_142924f50(void* pthis);
void FUN_142924fc0(void* pthis);
void FUN_142925680(void* pthis);
void FUN_142925750(void* pthis);
void FUN_1429259d0(void* pthis);
void FUN_142925cf0(void* pthis);

// @0x1429297a0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_1429297a0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929810
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929810(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x68)) FUN_14257dcb0(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929890
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929890(void* p, unsigned flags)
{
    FUN_142924d20(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x1429298f0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_1429298f0(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x70)) FUN_1425a4030(*(void**)((char*)p+0x70));
    if (*(void**)((char*)p+0x68)) FUN_1425a4030(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929980
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929980(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x1429299f0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_1429299f0(void* p, unsigned flags)
{
    FUN_142924d90(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929a50
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929a50(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929ac0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929ac0(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x68)) FUN_14257dcb0(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929b40
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929b40(void* p, unsigned flags)
{
    FUN_142924e00(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929ba0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929ba0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929c10
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929c10(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x68)) FUN_14257dcb0(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929c90
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929c90(void* p, unsigned flags)
{
    FUN_142924e70(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929cf0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929cf0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929d60
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929d60(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929dc0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929dc0(void* p, unsigned flags)
{
    FUN_142925750((void*)((char*)p+0x70));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929e50
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929e50(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x142929fe0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_142929fe0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a1d0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a1d0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a240
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a240(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a2b0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a2b0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a320
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a320(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x68)) FUN_14257dcb0(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a3a0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a3a0(void* p, unsigned flags)
{
    FUN_142924ee0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a520
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a520(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a590
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a590(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a5f0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a5f0(void* p, unsigned flags)
{
    FUN_142925750((void*)((char*)p+0x90));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a700
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a700(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a770
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a770(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a7d0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a7d0(void* p, unsigned flags)
{
    FUN_142925750((void*)((char*)p+0x98));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a860
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a860(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a8d0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a8d0(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x68)) FUN_14257dcb0(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a950
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a950(void* p, unsigned flags)
{
    FUN_142924f50(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292a9e0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292a9e0(void* p, unsigned flags)
{
    FUN_142925680(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292aa40
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292aa40(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292aaa0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292aaa0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292ab10
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292ab10(void* p, unsigned flags)
{
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292abd0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292abd0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292ac40
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292ac40(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292acb0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292acb0(void* p, unsigned flags)
{
    FUN_142925750((void*)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292ade0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292ade0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292ae50
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292ae50(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292aec0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292aec0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b1e0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b1e0(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    if (*(void**)((char*)p+0x28)) FUN_14257dcb0(*(void**)((char*)p+0x28));
    FUN_142639d10(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b270
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b270(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x40)) FUN_14257dcd0(*(void**)((char*)p+0x40));
    if (*(void**)((char*)p+0x30)) FUN_14257dcd0(*(void**)((char*)p+0x30));
    if (*(void**)((char*)p+0x28)) FUN_14257dcb0(*(void**)((char*)p+0x28));
    FUN_142639d10(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b300
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b300(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x30)) FUN_14257dcb0(*(void**)((char*)p+0x30));
    if (*(void**)((char*)p+0x28)) FUN_14257dcb0(*(void**)((char*)p+0x28));
    FUN_142639d10(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b470
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b470(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x70)) FUN_1425a4030(*(void**)((char*)p+0x70));
    FUN_1425f0a60(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b590
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b590(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b600
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b600(void* p, unsigned flags)
{
    if (*(void**)((char*)p+0x68)) FUN_14257dcb0(*(void**)((char*)p+0x68));
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b680
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b680(void* p, unsigned flags)
{
    FUN_142924fc0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b710
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b710(void* p, unsigned flags)
{
    FUN_1429259d0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

// @0x14292b7a0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292b7a0(void* p, unsigned flags)
{
    FUN_142925cf0(p);
    if (flags & 1)
        Memory::Free(p);
    return p;
}

}}} // namespace Scaleform::GFx::AS2
