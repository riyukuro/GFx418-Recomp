// Recovered Scaleform GFx 4.1.18 Video: VideoPC, the Windows PC video state (Video_VideoPC). Written from the exe: the
// constructor 0x140002780, ApplySystemSettings 0x140002820 / 0x140002830 / 0x140002850 and ??_G 0x1400028d0 are
// src/ms2/unnamed/unit_140002780_videopc.cpp; vftable 0x1431b4b10 (Video's 13 slots, the three ApplySystemSettings
// overridden). The game's GFxVideo (?\gfxvideo.cpp) creates it. Shared header of the src/ms2/scaleform units: append,
// do not reorder.
#ifndef MS2_SF_VIDEO_VIDEOPC_H
#define MS2_SF_VIDEO_VIDEOPC_H

#include "video_video.h"

namespace Scaleform { namespace GFx { namespace Video {

// Video with the CRI decoding threads set up per player: up to three threads, each with an affinity mask.
class VideoPC : public Video
{
public:
    VideoPC(const VideoVMSupport& vmSupport, Thread::ThreadPriority decodingThreadsPriority = Thread::NormalPriority,
            int decodingThreadsNumber = 3, UInt32* affinityMask = NULL);

    virtual void ApplySystemSettings(VideoPlayer* pvideoPlayer);    // 12
    virtual void ApplySystemSettings(VideoDecoder*) {}              // 11
    virtual void ApplySystemSettings(VideoReaderConfig*) {}         // 10

private:
    int    DecodingThreadNumber;    // +0x60
    UInt32 AffinityMask[3];         // +0x64
};

}}} // namespace Scaleform::GFx::Video

#endif
