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

namespace Scaleform { namespace GFx {

// Text::StyleManager as far as a StyleSheetObject builds one (text_stylesheet.h is on the other kernel tree): the
// style hash and the lookup key are kept as plain words, the destructor and the three lookups are sfr_gfx_06g's
// (vftable 0x14316a738: deleting dtor 0x1424aaf20, then the wchar_t, char and String lookups).
namespace Text {

class StyleManager : public Render::Text::StyleManagerBase
{
public:
    StyleManager() : Styles(0), TempType(CSS_None), State(0) {}
    ~StyleManager();

    virtual const Render::Text::Style* GetStyle(KeyType type, const String& name) const;
    virtual const Render::Text::Style* GetStyle(KeyType type, const char* name, UPInt len = SF_MAX_UPINT) const;
    virtual const Render::Text::Style* GetStyle(KeyType type, const wchar_t* name, UPInt len = SF_MAX_UPINT) const;

private:
    void*    Styles;   // +8 StyleHash
    KeyType  TempType; // +0x10 StyleKey TempKey
    StringLH TempName; // +0x18
    UPInt    TempHash; // +0x20
    int      State;    // +0x28
};

} // namespace Text

namespace AS2 {

inline StyleSheetObject::StyleSheetObject(ASStringContext* psc, Object* pprototype)
    : Object(psc)
{
    ::new (Data68) Text::StyleManager();
    Set__proto__(psc, pprototype);
}

// @0x142921190
// MS2-FUNCTIONAL: the style manager is built from a local declaration of Text::StyleManager
StyleSheetObject::StyleSheetObject(Environment* penv) : Object(penv)
{
    ASStringContext* psc = penv->GetSC();
    ::new (Data68) Text::StyleManager();
    Set__proto__(psc, penv->GetPrototype(ASBuiltin_StyleSheet));
    ObjectInterface* pobj = this;
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    AsBroadcaster::InitializeInstance(psc, pobj);
    AsBroadcaster::AddListener(penv, pobj, pobj);
}

// @0x142921270
// MS2-FUNCTIONAL: the style manager is built from a local declaration of Text::StyleManager
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
// MS2-PIN: ??_7StyleManagerBase@Text@Render@Scaleform@@6B@ 0x14316a718
// MS2-PIN: ??_7StyleManager@Text@GFx@Scaleform@@6B@ 0x14316a738
