// Recovered Scaleform 4.1.18 Render: the GPU debug events a HAL brackets its work with (frame capture tools hook
// them); the default event does nothing.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_EVENTS_H
#define MS2_SF_RENDER_EVENTS_H

#include "ms2/scaleform/kernel/sf_string.h"

namespace Scaleform { namespace Render {

enum EventType
{
    Event_InitHAL,
    Event_Frame,
    Event_Scene,
    Event_BeginScene,
    Event_Display,
    Event_Clear,
    Event_Mask,
    Event_PopMask,
    Event_MaskClear,
    Event_DrawPrimitive,
    Event_DrawComplex,
    Event_RenderTarget,
    Event_Filter,
    Event_ApplyBlend,
    Event_DrawableImage,   // one drawable image's commands
    Event_DICxform,
    Event_DICompare,
    Event_DICopyPixels,
    Event_DIMerge,
    Event_DIPaletteMap,
    Event_DIThreshold,
    Event_DICopyback,
    Event_Count
};

// vftable: dtor 0, GetListenerStatus 1, Begin 2, End 3.
class RenderEvent
{
public:
    virtual ~RenderEvent() {}
    virtual bool GetListenerStatus() const { return false; }
    virtual void Begin(String eventName) { SF_UNUSED(eventName); }   // the name travels by value
    virtual void End() {}
};

}} // namespace Scaleform::Render

#endif
