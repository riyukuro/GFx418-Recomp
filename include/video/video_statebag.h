// Recovered Scaleform 4.1.18 GFx: StateBag::GetVideo / SetVideo, apart from video_video.h so the video units do not need the
// movie def declarations. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_VIDEO_STATEBAG_H
#define MS2_SF_VIDEO_STATEBAG_H

#include "../gfx/gfx_moviedef.h"
#include "video_video.h"

namespace Scaleform { namespace GFx {

// The video state of a state bag (State_Video).
inline Ptr<Video::VideoBase> StateBag::GetVideo() const
{
    return *(Video::VideoBase*)GetStateAddRef(State::State_Video);
}

// (appended) Sets the video state (the game's /Od copy is a COMDAT of ?\gfxvideo.cpp).
inline void StateBag::SetVideo(Video::VideoBase* ptr)
{
    SetState(State::State_Video, ptr);
}

}} // namespace Scaleform::GFx

#endif
