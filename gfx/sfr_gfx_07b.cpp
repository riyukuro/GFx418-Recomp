// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Event: the keyboard state of
// one controller (pressed keys, lock toggles, the queue of pending key events and the AS2 Key listener).
// Second source of queue unit sfr_gfx_07 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_07b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14261a950-0x14261b310 .text$mn
// MS2-RANGE: 0x14261ff80-0x14261ffe0 .text$mn

// MS2-PIN: ??_7KeyboardState@GFx@Scaleform@@6B@ 0x14318eb90
// MS2-PIN: ??_7?$RefCountBase@VKeyboardState@GFx@Scaleform@@$01@Scaleform@@6B@ 0x14318f018
// MS2-PIN: ??_G?$RefCountBase@VKeyboardState@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14261ff80
// MS2-PIN: ??_GKeyboardState@GFx@Scaleform@@UEAAPEAXI@Z 0x14261ad20

#include "../include/gfx/gfx_keyboardstate.h"
#include "../include/gfx/gfx_eventid.h"
#include "../include/gfx/gfx_log.h"

#include <string.h>

namespace Scaleform { namespace GFx {

// ---------------------------------------------------------------------------------------------------------------------
// KeyboardState::KeyQueue

// @0x14261a950
KeyboardState::KeyQueue::KeyQueue()
{
    ResetState();
}

// @0x14261b080
void KeyboardState::KeyQueue::ResetState()
{
    PutIdx = 0;
    GetIdx = 0;
    Count  = 0;
    memset(&Buffer, 0, sizeof(Buffer));
}

// Appends one event; a full queue drops it.
// @0x14261b000
void KeyboardState::KeyQueue::Put(short code, UByte ascii, UInt32 wcharCode, Event::EventType event, KeyModifiers mods)
{
    if (Count >= KeyQueueSize)
        return;
    Buffer[PutIdx].code      = code;
    Buffer[PutIdx].ascii     = ascii;
    Buffer[PutIdx].wcharCode = wcharCode;
    Buffer[PutIdx].event     = event;
    Buffer[PutIdx].keyMods   = mods;
    if (++PutIdx >= KeyQueueSize)
        PutIdx = 0;
    ++Count;
}

// Takes the oldest event; false when the queue is empty. mods is optional.
bool KeyboardState::KeyQueue::Get(short* code, UByte* ascii, UInt32* wcharCode, Event::EventType* event,
                                  KeyModifiers* mods)
{
    if (Count > 0)
    {
        *code      = Buffer[GetIdx].code;
        *ascii     = Buffer[GetIdx].ascii;
        *wcharCode = Buffer[GetIdx].wcharCode;
        *event     = Buffer[GetIdx].event;
        if (mods)
            *mods = Buffer[GetIdx].keyMods;
        if (++GetIdx >= KeyQueueSize)
            GetIdx = 0;
        --Count;
        return true;
    }
    return false;
}

// ---------------------------------------------------------------------------------------------------------------------
// KeyboardState

// @0x14261a990
KeyboardState::KeyboardState()
{
    pListener     = 0;
    KeyboardIndex = 0;
    memset(Keymap, 0, sizeof(Keymap));
    memset(Toggled, 0, sizeof(Toggled));
}

// @0x14261b0a0
void KeyboardState::ResetState()
{
    KeyQueue.ResetState();
    memset(Keymap, 0, sizeof(Keymap));
    memset(Toggled, 0, sizeof(Toggled));
}

// @0x14261af60
bool KeyboardState::IsKeyDown(int code) const
{
    if (code < 0 || code >= Key::KeyCount)
        return false;
    int byteIndex = code >> 3;
    int mask      = 1 << (code - (byteIndex << 3));
    if (Keymap[byteIndex] & mask)
        return true;
    else
        return false;
}

// @0x14261afa0
bool KeyboardState::IsKeyToggled(int code) const
{
    switch (code)
    {
    case Key::NumLock:    return Toggled[0];
    case Key::CapsLock:   return Toggled[1];
    case Key::ScrollLock: return Toggled[2];
    }
    return false;
}

// @0x14261ae30
KeyModifiers KeyboardState::GetKeyModifiers() const
{
    KeyModifiers mods;
    mods.SetAltPressed(IsKeyDown(Key::Alt));
    mods.SetCtrlPressed(IsKeyDown(Key::Control));
    mods.SetShiftPressed(IsKeyDown(Key::Shift));
    mods.SetNumToggled(Toggled[0]);
    mods.SetCapsToggled(Toggled[1]);
    mods.SetScrollToggled(Toggled[2]);
    return mods;
}

// @0x14261b1e0
void KeyboardState::SetKeyToggled(int code, bool toggle)
{
    switch (code)
    {
    case Key::NumLock:    Toggled[0] = toggle; break;
    case Key::CapsLock:   Toggled[1] = toggle; break;
    case Key::ScrollLock: Toggled[2] = toggle; break;
    }
}

// @0x14261b170
void KeyboardState::SetKeyDown(int code, UByte ascii, KeyModifiers mods, bool putInQueue)
{
    if (code < 0 || code >= Key::KeyCount)
        return;
    int byteIndex = code >> 3;
    Keymap[byteIndex] |= 1 << (code - (byteIndex << 3));
    if (putInQueue)
        KeyQueue.Put(short(code), ascii, 0, Event::KeyDown, mods);
}

// @0x14261b210
void KeyboardState::SetKeyUp(int code, UByte ascii, KeyModifiers mods, bool putInQueue)
{
    if (code < 0 || code >= Key::KeyCount)
        return;
    int byteIndex = code >> 3;
    Keymap[byteIndex] &= ~(1 << (code - (byteIndex << 3)));
    if (putInQueue)
        KeyQueue.Put(short(code), ascii, 0, Event::KeyUp, mods);
}

// @0x14261b0f0
void KeyboardState::SetChar(UInt32 wcharCode)
{
    KeyQueue.Put(0, 0, wcharCode, Event::Char, 0);
}

// @0x14261aeb0
bool KeyboardState::GetQueueEntry(short* code, UByte* ascii, UInt32* wcharCode, Event::EventType* event,
                                  KeyModifiers* mods)
{
    return KeyQueue.Get(code, ascii, wcharCode, event, mods);
}

// Only key down / key up events reach the listener here.
// @0x14261afd0
void KeyboardState::NotifyListeners(InteractiveObject* pmovie, const EventId& evt, int keyMask) const
{
    if (!pListener)
        return;
    if (evt.Id == EventId::Event_KeyDown)
        pListener->OnKeyDown(pmovie, evt, keyMask);
    else if (evt.Id == EventId::Event_KeyUp)
        pListener->OnKeyUp(pmovie, evt, keyMask);
}

// @0x14261b290
void KeyboardState::UpdateListeners(const EventId& evt)
{
    if (pListener)
        pListener->Update(evt);
}

// @0x14261b280
void KeyboardState::SetListener(IListener* listener)
{
    CleanupListener();
    pListener = listener;
}

}} // namespace Scaleform::GFx

namespace Scaleform {

// A message to the global log, or the default output when there is none.
// @0x14261b2b0
void LogDebugMessage(LogMessageId id, const char* fmt, ...)
{
    Log*    plog = Log::GetGlobalLog();
    va_list argList;
    va_start(argList, fmt);
    if (plog)
        plog->LogMessageVarg(id, fmt, argList);
    else
        Log::DefaultLogMessageVarg(id, fmt, argList);
    va_end(argList);
}

} // namespace Scaleform

// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
