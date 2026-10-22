// Recovered Scaleform 4.1.18 GFx: the IME manager state as the AS3 flash.system.IME class reaches it (sfr12).
// The exe's vftable slots 6..9 are the conversion mode and enable switches; the others are kept as placeholders.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder virtuals.
#ifndef MS2_SF_GFX_IMEMANAGER_H
#define MS2_SF_GFX_IMEMANAGER_H

#include "gfx_state.h"

namespace Scaleform { namespace GFx {

class IMEManagerBase : public State
{
public:
    virtual ~IMEManagerBase() {}                                        // 0
private:
    virtual void Slot01();                                              // Init
    virtual void Slot02();                                              // IMECommand
    virtual void Slot03();                                              // ProcessIMEMessage
    virtual void Slot04();                                              // HandleIMEEvent
    virtual void Slot05();                                              // ClearCandidateListPath
public:
    virtual bool        SetConversionMode(const UInt32 convMode);       // 6
    virtual const char* GetConversionMode();                            // 7
    virtual bool        SetEnabled(bool enable);                        // 8
    virtual bool        GetEnabled();                                   // 9
};

}} // namespace Scaleform::GFx

#endif
