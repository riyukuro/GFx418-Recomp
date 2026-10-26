// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 scalar deleting destructors of
// classes whose destructor bodies only chain to member/base destructors (gap recovery of sfr_as2_04).
// MS2-UNIT: sfr_as2_04d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14292a170-0x14292a19b .text$mn
// MS2-RANGE: 0x14292a1a0-0x14292a1cb .text$mn
// MS2-RANGE: 0x14292a9b0-0x14292a9db .text$mn
// MS2-RANGE: 0x14292aba0-0x14292abcb .text$mn
// MS2-RANGE: 0x14292afb0-0x14292afdb .text$mn
// MS2-RANGE: 0x14292b6e0-0x14292b70b .text$mn
// MS2-RANGE: 0x14292b770-0x14292b79b .text$mn
// MS2-RANGE: 0x14292bae0-0x14292bb0b .text$mn
// MS2-RANGE: 0x14292be50-0x14292be7b .text$mn
// MS2-RANGE: 0x14292be80-0x14292beab .text$mn
// MS2-RANGE: 0x14292bfc0-0x14292bfeb .text$mn
// MS2-RANGE: 0x14292cae0-0x14292cb29 .text$mn
// MS2-RANGE: 0x14292dc10-0x14292dc3b .text$mn
// MS2-RANGE: 0x14292dc40-0x14292dc6b .text$mn

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


// The 0x18-byte derived class's destructor leaves only the base's vptr store.
// @0x14292a170
void* DeleteAs2_14292a170(ObjectInterface::MemberVisitor* p, unsigned flags)
{
    p->ObjectInterface::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(p, 0x18);
    return p;
}

// The 0x18-byte derived class's destructor leaves only the base's vptr store.
// @0x14292a1a0
void* DeleteAs2_14292a1a0(ObjectInterface::MemberVisitor* p, unsigned flags)
{
    p->ObjectInterface::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(p, 0x18);
    return p;
}

// The 0x18-byte derived class's destructor leaves only the base's vptr store.
// @0x14292a9b0
void* DeleteAs2_14292a9b0(ObjectInterface::MemberVisitor* p, unsigned flags)
{
    p->ObjectInterface::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(p, 0x18);
    return p;
}

// The 0x10-byte derived class's destructor leaves only the base's vptr store.
// @0x14292aba0
void* DeleteAs2_14292aba0(MovieDef::ResourceVisitor* p, unsigned flags)
{
    p->MovieDef::ResourceVisitor::~ResourceVisitor();
    if (flags & 1)
        ::operator delete(p, 0x10);
    return p;
}

// The 0x80-byte derived class's destructor leaves only the base's vptr store.
// @0x14292afb0
void* DeleteAs2_14292afb0(StaticTextSnapshotData::GlyphVisitor* p, unsigned flags)
{
    p->StaticTextSnapshotData::GlyphVisitor::~GlyphVisitor();
    if (flags & 1)
        ::operator delete(p, 0x80);
    return p;
}

// The 0x18-byte derived class's destructor leaves only the base's vptr store.
// @0x14292b6e0
void* DeleteAs2_14292b6e0(ObjectInterface::MemberVisitor* p, unsigned flags)
{
    p->ObjectInterface::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(p, 0x18);
    return p;
}

// The 0x8-byte derived class's destructor leaves only the base's vptr store.
// @0x14292b770
void* DeleteAs2_14292b770(AsBroadcaster::InvokeCallback* p, unsigned flags)
{
    p->AsBroadcaster::InvokeCallback::~InvokeCallback();
    if (flags & 1)
        ::operator delete(p, 0x8);
    return p;
}

// The 0x28-byte derived class's destructor leaves only the base's vptr store.
// @0x14292bae0
void* DeleteAs2_14292bae0(AsBroadcaster::InvokeCallback* p, unsigned flags)
{
    p->AsBroadcaster::InvokeCallback::~InvokeCallback();
    if (flags & 1)
        ::operator delete(p, 0x28);
    return p;
}

// The 0x8-byte derived class's destructor leaves only the base's vptr store.
// @0x14292be50
void* DeleteAs2_14292be50(DisplayList::MemberVisitor* p, unsigned flags)
{
    p->DisplayList::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(p, 0x8);
    return p;
}

// The 0x8-byte derived class's destructor leaves only the base's vptr store.
// @0x14292be80
void* DeleteAs2_14292be80(ObjectInterface::MemberVisitor* p, unsigned flags)
{
    p->ObjectInterface::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(p, 0x8);
    return p;
}

// The 0x8-byte derived class's destructor leaves only the base's vptr store.
// @0x14292bfc0
void* DeleteAs2_14292bfc0(MouseListener* p, unsigned flags)
{
    p->MouseListener::~MouseListener();
    if (flags & 1)
        ::operator delete(p, 0x8);
    return p;
}

// @0x14292cae0
// MS2-FUNCTIONAL: scalar deleting destructor written out; the class is not recovered, so its destructor chain is called by address
void* DeleteAs2_14292cae0(void* p, unsigned flags)
{
    if (flags & 1)
        ::operator delete(p);
    return p;
}

// The 0x18-byte derived class's destructor leaves only the base's vptr store.
// @0x14292dc10
void* DeleteAs2_14292dc10(DisplayList::MemberVisitor* p, unsigned flags)
{
    p->DisplayList::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(p, 0x18);
    return p;
}

// The 0x20-byte derived class's destructor leaves only the base's vptr store.
// @0x14292dc40
void* DeleteAs2_14292dc40(ObjectInterface::MemberVisitor* p, unsigned flags)
{
    p->ObjectInterface::MemberVisitor::~MemberVisitor();
    if (flags & 1)
        ::operator delete(p, 0x20);
    return p;
}

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
// MS2-PIN: ??_7ResourceVisitor@MovieDef@GFx@Scaleform@@6B@ 0x143169d08
// MS2-PIN: ??_7GlyphVisitor@StaticTextSnapshotData@GFx@Scaleform@@6B@ 0x14316a500
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
// MS2-PIN: ??_7MemberVisitor@DisplayList@GFx@Scaleform@@6B@ 0x143215358
// MS2-PIN: ??_7MouseListener@AS2@GFx@Scaleform@@6B@ 0x143217718
