// Recovered Scaleform 4.1.18 GFx: keyboard state of a controller and its listener interface.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// Only the listener interface and the key queries are recovered so far (0x688 bytes, MovieImpl keeps four).
#ifndef MS2_SF_GFX_KEYBOARDSTATE_H
#define MS2_SF_GFX_KEYBOARDSTATE_H

namespace Scaleform { namespace GFx {

class InteractiveObject;
class EventId;

class KeyboardState
{
public:
    // Told about every key press and release (the AS2 Key object).
    class IListener
    {
    public:
        virtual ~IListener() {}
        virtual void OnKeyDown(InteractiveObject* pmovie, const EventId& evt, int keyMask) = 0;
        virtual void OnKeyUp(InteractiveObject* pmovie, const EventId& evt, int keyMask)   = 0;
        virtual void Update(const EventId& evt)                                             = 0;
    };

    bool IsKeyDown(int code) const;    // exe 0x14261af60
    bool IsKeyToggled(int code) const; // exe 0x14261afa0
};

}} // namespace Scaleform::GFx

#endif
