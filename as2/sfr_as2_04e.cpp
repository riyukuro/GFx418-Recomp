// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): out-of-line copies of Scaleform GFx 4.1.18 AS2 inline
// methods (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14292dfe0-0x14292e036 .text$mn
// MS2-RANGE: 0x1429316c0-0x142931705 .text$mn
// MS2-RANGE: 0x1429333d0-0x142933413 .text$mn
// MS2-RANGE: 0x142933d50-0x142933d7b .text$mn

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

// @0x14292dfe0
// MS2-FUNCTIONAL: the inline method AvmSprite::AcquirePath out of line
DrawingContext* AcquirePathCopy(AvmSprite* psprite, bool newShapeFlag)
{
    return psprite->AcquirePath(newShapeFlag);
}

// @0x1429316c0
// MS2-FUNCTIONAL: the inline method FnCall::Arg out of line (the exe returns null for an argument beyond the stack)
Value* ArgCopy(const FnCall* pfn, int n)
{
    return &pfn->Arg(n);
}

// @0x1429333d0
// MS2-FUNCTIONAL: the inline method AvmSprite::CharacterGetTarget out of line
InteractiveObject* CharacterGetTargetCopy(const FnCall* pfn)
{
    return AvmSprite::CharacterGetTarget(*pfn);
}

// @0x142933d50
// MS2-FUNCTIONAL: the inline method FnCall::CheckThisPtr out of line
bool CheckThisPtrCopy(const FnCall* pfn, unsigned type)
{
    return pfn->CheckThisPtr(type);
}

}}} // namespace Scaleform::GFx::AS2
