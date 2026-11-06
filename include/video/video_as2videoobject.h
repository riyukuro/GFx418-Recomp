// Recovered Scaleform GFx 4.1.18 Video: the AS2 VideoObject (the script object of a Video clip) and its prototype.
// The members are defined in sfr_video_01. sfr_video_02 needs the full class too: its out-of-line
// ~Prototype<VideoObject> (0x14000ebe0) runs the real dtor, so cl emits the ??_7Prototype<VideoObject> stores.
// Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_SF_VIDEO_AS2VIDEOOBJECT_H
#define MS2_SF_VIDEO_AS2VIDEOOBJECT_H

#include "../gfx/as2/as2_objectproto.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The script object of a Video clip.
class VideoObject : public Object
{
public:
    VideoObject(ASStringContext* psc, Object* pprototype);              // exe 0x14000de10
    VideoObject(GlobalContext* gCtxt, InteractiveObject* pcharacter);   // exe 0x14000dee0
    VideoObject(Environment* penv);                                     // exe 0x14000dfb0

    virtual ObjectType GetObjectType() const { return Object_VideoASObject; }
    virtual InteractiveObject* GetASCharacter();
    virtual const InteractiveObject* GetASCharacter() const;

protected:
    virtual void Finalize_GC();   // exe 0x14000db80

    WeakPtr<InteractiveObject> pCharacter;   // +0x68
};

// defined in sfr_video_01 (0x14000d760)
template<>
bool Prototype<VideoObject>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);

}}} // namespace Scaleform::GFx::AS2

#endif // MS2_SF_VIDEO_AS2VIDEOOBJECT_H
