// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 prototype classes, ctors and
// destructors (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142923030-0x1429231a7 .text$mn
// MS2-RANGE: 0x142928860-0x1429288fc .text$mn

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

void FUN_1424aa0f0(void* pthis);  // Render::Text::TextFormat destructor (global, as in sfr_as2_04c)

namespace Scaleform { namespace GFx { namespace AS2 {

inline TextFormatObject::TextFormatObject(ASStringContext* psc, Object* pprototype)
    : Object(psc)
{
    ::new (mTextFormat.Data) Render::Text::TextFormat(psc->GetHeap());
    ::new (mParagraphFormat.Data) Render::Text::ParagraphFormat();
    Set__proto__(psc, pprototype);
}

// @0x142923030
TextFormatProto::TextFormatProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<TextFormatObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// The deleting destructor with the chain inlined, a twin of DeleteAs2_14292d6a0 (sfr_as2_04c): the Prototype
// destructor (its vftables, the prototype base, then the object's implicit destructor: the paragraph and text
// formats, then Object); flag 4 is the sized delete.
// @0x142928860
void* DeleteTextFormatProto(TextFormatProto* pthis, unsigned flags)
{
    void* p = pthis;
    static_cast<Prototype<TextFormatObject, Environment>*>(pthis)->Prototype<TextFormatObject, Environment>::~Prototype();
    if (flags & 1)
    {
        if (!(flags & 4))
            Memory::Free(p);
        else
            ::operator delete(p, 0x110);
    }
    return p;
}

}}}

// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7TextFormatObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d688
// MS2-PIN: ??_7TextFormatObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d6d0
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d778
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d7c0
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321d868
// MS2-PIN: ??_7TextFormatProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d870
// MS2-PIN: ??_7TextFormatProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d8b8
// MS2-PIN: ??_7TextFormatProto@AS2@GFx@Scaleform@@6B@ 0x14321d960
