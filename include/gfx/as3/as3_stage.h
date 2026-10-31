// Recovered Scaleform GFx 4.1.18 AS3: the stage display object, the top container that holds the root movie clip
// and the frame counter. 0x130 bytes; ctor 0x1424d9b50, destructor 0x1424defe0, deleting destructor 0x1424e3950
// (frees 0x130). Over DisplayObjContainer's vftable 0x14318e318 its primary vftable 0x14317d220 (122 slots)
// overrides 0, 54, 62, 76, 83, 93, 101..106, 119 and adds ExecuteFrameTags at 121; LogBase vftable 0x14317d5f0.
// The frame queries forward to the root movie clip.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder the virtuals.
//
// Units that define a local class Stage of their own (sfr_as3_15, sfr_as3_18) must not include this header.
#ifndef MS2_SF_GFX_AS3_STAGE_H
#define MS2_SF_GFX_AS3_STAGE_H

#include "ms2/scaleform/include/gfx/gfx_displayobjcontainer.h"
#include "ms2/scaleform/include/gfx/gfx_asstring.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class Stage : public DisplayObjContainer
{
public:
    Ptr<DisplayObjContainer> pRoot;                   // +0x110
    Ptr<InteractiveObject>   FrameCounterObj;         // +0x118
    ASString                 CurrentStageOrientation; // +0x120
    unsigned                 MouseCursorEventCnt;     // +0x128

    Stage(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent, ResourceId id); // 0x1424d9b50
    virtual ~Stage();                                                       // 0x1424defe0, ??_G 0x1424e3950

    virtual void        ForceShutdown();                                    // 54 0x142504860
    // (sfb) GetTopParent, IsFocusEnabled, GetLabeledFrame, GetFrameLabel, GotoFrame and GetLoadingFrame are defined
    // out of line in sfr_as3_18, which owns their VAs; in-class bodies here clash with them (LNK2005) in any unit
    // that emits the vftable (sfr_as3_16 defines ~Stage).
    virtual InteractiveObject* GetTopParent(bool ignoreLockRoot = false) const; // 62 0x14250f870
protected:
    virtual ASString    CreateNewInstanceName() const;                      // 76 0x1424f3980
public:
    virtual bool        IsFocusEnabled(FocusMovedType = GFx_FocusMovedByKeyboard) const; // 83 0x142514310
    virtual void        PropagateMouseEvent(const EventId& id);             // 93 0x14251f570
    virtual unsigned    GetCurrentFrame() const                             // 101 0x1425084e0
    {
        return pRoot ? pRoot->GetCurrentFrame() : 0;
    }
    virtual bool        GetLabeledFrame(const char* plabel, unsigned* frameNumber, bool translateNumbers = true); // 102 0x14250b370
    virtual const String* GetFrameLabel(unsigned frame, unsigned* exactFrame = NULL); // 103 0x142509dd0
    virtual void        GotoFrame(unsigned targetFrameNumber);              // 104 0x142510d20
    virtual unsigned    GetLoadingFrame() const;                            // 105 0x14250b3b0
    virtual void        ExecuteFrame0Events();                              // 106 0x1424fe620
    virtual void        OnInsertionAsLevel(int level);                      // 119 0x14251a110
    // (new in Stage) the stage has no frame tags of its own.
    virtual void        ExecuteFrameTags(unsigned frame) { SF_UNUSED(frame); } // 121 0x1424feaf0

    void SetOrientation(const ASString& orientation);                       // 0x142528770
};
// The deleting destructor 0x1424e3950 frees 0x130 bytes.
static_assert(sizeof(Stage) == 0x130, "Stage size");

}}} // namespace Scaleform::GFx::AS3

#endif
