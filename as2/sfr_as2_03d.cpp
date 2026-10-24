// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 prototype classes, ctors and
// destructors (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142921190-0x1429212ed .text$mn
// MS2-RANGE: 0x142954330-0x142954340 .text$mn

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

// The empty style manager a StyleSheetObject starts with (Text::StyleManager: vftable, style hash, lookup key, state).
struct EmptyStyleManager
{
    virtual ~EmptyStyleManager() {}
    void* Styles;
    int   KeyType;
    StringLH KeyName;
    UPInt KeyHash;
    int   State;
    EmptyStyleManager() : Styles(0), KeyType(2), State(0) {}
};

inline StyleSheetObject::StyleSheetObject(ASStringContext* psc, Object* pprototype)
    : Object(psc)
{
    ::new (Data68) EmptyStyleManager();
    Set__proto__(psc, pprototype);
}

// @0x142921190
// MS2-FUNCTIONAL: the style manager is built from a local stand-in for Text::StyleManager
StyleSheetObject::StyleSheetObject(Environment* penv) : Object(penv)
{
    ASStringContext* psc = penv->GetSC();
    ::new (Data68) EmptyStyleManager();
    Set__proto__(psc, penv->GetPrototype(ASBuiltin_StyleSheet));
    ObjectInterface* pobj = this;
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    AsBroadcaster::InitializeInstance(psc, pobj);
    AsBroadcaster::AddListener(penv, pobj, pobj);
}

// @0x142921270
// MS2-FUNCTIONAL: the style manager is built from a local stand-in for Text::StyleManager
StyleSheetProto::StyleSheetProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<StyleSheetObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x142954330
Object::ObjectType StyleSheetObject::GetObjectType() const { return Object_StyleSheet; }

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7StyleSheetObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143217308
// MS2-PIN: ??_7StyleSheetObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217350
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432173f8
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217440
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1432174e8
// MS2-PIN: ??_7StyleSheetProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432174f0
// MS2-PIN: ??_7StyleSheetProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217538
// MS2-PIN: ??_7StyleSheetProto@AS2@GFx@Scaleform@@6B@ 0x1432175e0
// MS2-PIN: ??_7EmptyStyleManager@AS2@GFx@Scaleform@@6B@ 0x14316a738
