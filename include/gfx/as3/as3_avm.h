// Recovered Scaleform GFx 4.1.18 AS3: the AS3 halves of display objects (Avm* classes) as the loader side sees them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// AvmDisplayObj is spelled out up to its data members. The other Avm classes are declared OPAQUE for now (size and
// constructor only): their full declarations (bases, vftables) come with the units that recover their code.
#ifndef MS2_SF_GFX_AS3_AVM_H
#define MS2_SF_GFX_AS3_AVM_H

#include "ms2/scaleform/include/gfx/gfx_displayobject.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimplstates.h"
#include "ms2/scaleform/include/gfx/as3/as3_support.h"

namespace Scaleform { namespace GFx {

class Sprite;
class TextField;
class Button;
class StaticTextCharacter;
class CharacterDef;
struct CharacterCreateInfo;

namespace AS3 {

class VMAppDomain;
namespace Instances { namespace fl_display { class DisplayObject; } }

// AS3 part of every display object. 0x38 bytes.
class AvmDisplayObj : public AvmDisplayObjBase
{
public:
    Instances::fl_display::DisplayObject*   pAS3CollectiblePtr; // +0x08 SPtr<>
    Instances::fl_display::DisplayObject*   pAS3RawPtr;         // +0x10
    DisplayObject*                          pDispObj;           // +0x18
    const char*                             pClassName;         // +0x20
    VMAppDomain*                            AppDomain;          // +0x28
    UByte                                   Flags;              // +0x30

    MovieRoot*  GetAS3Root() const;
    MovieImpl*  GetMovieImpl() const    { return pDispObj->GetMovieImpl(); }
    Ptr<Log>    GetLog() const          { return GetMovieImpl()->GetLog(); }
};

inline AvmDisplayObj* ToAvmDisplayObj(DisplayObjectBase* p)
{
    return static_cast<AvmDisplayObj*>(p->GetAvmObjImpl());
}

// Opaque until recovered: size and constructor. The display objects among them are used through their
// DisplayObjectBase part (offset 0) via AsDisplayObject().
template <class T> inline DisplayObjectBase* AsDisplayObject(T* p) { return reinterpret_cast<DisplayObjectBase*>(p); }
class ShapeObject
{
public:
    ShapeObject(CharacterDef* pdef, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id);
    UByte Data[0xd0];
};

class AvmBitmap
{
public:
    AvmBitmap(ASMovieRootBase* pasRoot, const CharacterCreateInfo& ccinfo, InteractiveObject* pparent, ResourceId id);
    UByte Data[0xd0];
};

class AvmSprite
{
public:
    AvmSprite(Sprite* pspr);
    UByte Data[0x68];
};

// AvmSprite of a timeline sprite. Its constructor is inlined into its users: AvmSprite's, then its own vftables.
class AvmMovieClip : public AvmSprite
{
public:
    static void Construct(AvmMovieClip* p, Sprite* pspr);
};

class AvmTextField
{
public:
    AvmTextField(TextField* ptxt);
    UByte Data[0x48];
};

class AvmStaticText
{
public:
    AvmStaticText(StaticTextCharacter* ptxt);
    UByte Data[0x30];
};

class AvmButton
{
public:
    AvmButton(Button* pbtn);
    UByte Data[0x48];
};

// The exe's AvmMovieClip vftables (main, AvmInteractiveObj, AvmDisplayObjContainer, AvmSpriteBase parts).
extern void* const AvmMovieClip_vftable[];
extern void* const AvmMovieClip_vftable_30[];
extern void* const AvmMovieClip_vftable_40[];
extern void* const AvmMovieClip_vftable_48[];

inline void AvmMovieClip::Construct(AvmMovieClip* p, Sprite* pspr)
{
    new (p) AvmSprite(pspr);
    UByte* pb = (UByte*)p;
    *(void* const**)(pb + 0x00) = AvmMovieClip_vftable;
    *(void* const**)(pb + 0x30) = AvmMovieClip_vftable_30;
    *(void* const**)(pb + 0x40) = AvmMovieClip_vftable_40;
    *(void* const**)(pb + 0x48) = AvmMovieClip_vftable_48;
}

}}} // namespace Scaleform::GFx::AS3

#endif
