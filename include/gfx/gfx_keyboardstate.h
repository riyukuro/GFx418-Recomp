// Recovered Scaleform 4.1.18 GFx: keyboard state of a controller and its listener interface.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// 0x688 bytes, MovieImpl keeps four (bodies in sfr_gfx_07b, GFx_Event).
#ifndef MS2_SF_GFX_KEYBOARDSTATE_H
#define MS2_SF_GFX_KEYBOARDSTATE_H

#include "gfx_event.h"
#include "../kernel/sf_keycodes.h"

namespace Scaleform { namespace GFx {

class InteractiveObject;
class EventId;

class KeyboardState : public RefCountBase<KeyboardState, Stat_Default_Mem>
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

protected:
    IListener* pListener; // +0x10

    // Ring buffer of the key and char events not yet handed to the movie. 0x64c bytes.
    class KeyQueue
    {
        enum { KeyQueueSize = 100 };
        struct KeyRecord // 0x10 bytes
        {
            UInt32           wcharCode; // +0x00
            short            code;      // +0x04
            Event::EventType event;     // +0x08
            UByte            ascii;     // +0x0c
            KeyModifiers     keyMods;   // +0x0d
        };
        KeyRecord Buffer[KeyQueueSize]; // +0x000
        unsigned  PutIdx;               // +0x640
        unsigned  GetIdx;               // +0x644
        unsigned  Count;                // +0x648

    public:
        KeyQueue();

        void Put(short code, UByte ascii, UInt32 wcharCode, Event::EventType event, KeyModifiers mods = 0);
        bool Get(short* code, UByte* ascii, UInt32* wcharCode, Event::EventType* event, KeyModifiers* mods = 0);
        bool IsEmpty() const { return Count == 0; }
        void ResetState();
    } KeyQueue; // +0x18

    UInt8 KeyboardIndex;              // +0x664
    UByte Keymap[Key::KeyCount / 8 + 1]; // +0x665 one bit per key code
    bool  Toggled[3];                 // +0x682 num, caps, scroll lock

public:
    KeyboardState();

    void  SetKeyboardIndex(UInt8 ki) { KeyboardIndex = ki; }
    UInt8 GetKeyboardIndex() const   { return KeyboardIndex; }

    bool IsKeyDown(int code) const;    // exe 0x14261af60
    bool IsKeyToggled(int code) const; // exe 0x14261afa0
    void SetKeyToggled(int code, bool toggle);
    void SetKeyDown(int code, UByte ascii, KeyModifiers mods = 0, bool putInQueue = true);
    void SetKeyUp(int code, UByte ascii, KeyModifiers mods = 0, bool putInQueue = true);
    void SetChar(UInt32 wcharCode);

    bool IsQueueEmpty() const { return KeyQueue.IsEmpty(); }
    bool GetQueueEntry(short* code, UByte* ascii, UInt32* wcharCode, Event::EventType* event, KeyModifiers* mods = 0);

    void CleanupListener() { pListener = 0; }
    void SetListener(IListener* listener);
    void NotifyListeners(InteractiveObject* pmovie, const EventId& evt, int keyMask) const;
    void UpdateListeners(const EventId& evt);

    void ResetState();

    KeyModifiers GetKeyModifiers() const;
};

}} // namespace Scaleform::GFx

#endif
