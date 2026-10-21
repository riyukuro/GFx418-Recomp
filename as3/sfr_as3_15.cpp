// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_15
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424c9700-0x1424dc870 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {

// thunk 0x1424cdc40: Instances::fl_media::SoundTransform::leftToLeftGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 0, Value::Number>;
// thunk 0x1424cdcb0: Instances::fl_media::SoundTransform::leftToLeftSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 1, const Value, Value::Number>;
// thunk 0x1424cdd40: Instances::fl_media::SoundTransform::leftToRightGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 2, Value::Number>;
// thunk 0x1424cddb0: Instances::fl_media::SoundTransform::leftToRightSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 3, const Value, Value::Number>;
// thunk 0x1424cde40: Instances::fl_media::SoundTransform::panGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 4, Value::Number>;
// thunk 0x1424cdeb0: Instances::fl_media::SoundTransform::panSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 5, const Value, Value::Number>;
// thunk 0x1424cdf40: Instances::fl_media::SoundTransform::rightToLeftGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 6, Value::Number>;
// thunk 0x1424cdfb0: Instances::fl_media::SoundTransform::rightToLeftSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 7, const Value, Value::Number>;
// thunk 0x1424ce040: Instances::fl_media::SoundTransform::rightToRightGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 8, Value::Number>;
// thunk 0x1424ce0b0: Instances::fl_media::SoundTransform::rightToRightSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 9, const Value, Value::Number>;
// thunk 0x1424ce140: Instances::fl_media::SoundTransform::volumeGet
template struct ThunkFunc0<Instances::fl_media::SoundTransform, 10, Value::Number>;
// thunk 0x1424ce1b0: Instances::fl_media::SoundTransform::volumeSet
template struct ThunkFunc1<Instances::fl_media::SoundTransform, 11, const Value, Value::Number>;
// thunk 0x1424ceb00: Instances::fl_media::Sound::bytesLoadedGet
template struct ThunkFunc0<Instances::fl_media::Sound, 0, UInt32>;
// thunk 0x1424ceb60: Instances::fl_media::Sound::bytesTotalGet
template struct ThunkFunc0<Instances::fl_media::Sound, 1, SInt32>;
// thunk 0x1424cebc0: Instances::fl_media::Sound::id3Get
template struct ThunkFunc0<Instances::fl_media::Sound, 2, SPtr<Instances::fl_media::ID3Info>>;
// thunk 0x1424cec70: Instances::fl_media::Sound::isBufferingGet
template struct ThunkFunc0<Instances::fl_media::Sound, 3, bool>;
// thunk 0x1424cecd0: Instances::fl_media::Sound::lengthGet
template struct ThunkFunc0<Instances::fl_media::Sound, 4, Value::Number>;
// thunk 0x1424ced40: Instances::fl_media::Sound::urlGet
template struct ThunkFunc0<Instances::fl_media::Sound, 5, ASString>;
// thunk 0x1424cedb0: Instances::fl_media::Sound::close
template struct ThunkFunc0<Instances::fl_media::Sound, 6, const Value>;
// thunk 0x1424cedd0: Instances::fl_media::Sound::load
template struct ThunkFunc2<Instances::fl_media::Sound, 7, const Value, Instances::fl_net::URLRequest*, Instances::fl_media::SoundLoaderContext*>;
// Instances::fl_media::Sound::play argument 0 default
template <> struct ThunkMethodDefault<Instances::fl_media::Sound, 8, 0, Value::Number>
{
    SF_INLINE static Value::Number Get(StringManager&) { return 0.0; }
};
// thunk 0x1424cee20: Instances::fl_media::Sound::play
template struct ThunkFunc3<Instances::fl_media::Sound, 8, Value, Value::Number, SInt32, Instances::fl_media::SoundTransform*>;
// thunk 0x1424cef10: Instances::fl_media::SoundChannel::leftPeakGet
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 0, Value::Number>;
// thunk 0x1424cef80: Instances::fl_media::SoundChannel::positionGet
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 1, Value::Number>;
// thunk 0x1424ceff0: Instances::fl_media::SoundChannel::rightPeakGet
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 2, Value::Number>;
// thunk 0x1424cf060: Instances::fl_media::SoundChannel::soundTransformGet
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 3, SPtr<Instances::fl_media::SoundTransform>>;
// thunk 0x1424cf110: Instances::fl_media::SoundChannel::soundTransformSet
template struct ThunkFunc1<Instances::fl_media::SoundChannel, 4, const Value, Instances::fl_media::SoundTransform*>;
// thunk 0x1424cf150: Instances::fl_media::SoundChannel::stop
template struct ThunkFunc0<Instances::fl_media::SoundChannel, 5, const Value>;
// thunk 0x1424d2160: Class::prototypeGet
template struct ThunkFunc0<Class, 0, Value>;
// thunk 0x1424d2180: Class::lengthGet
template struct ThunkFunc0<Class, 1, SInt32>;
// thunk 0x1424d21e0: Class::toString
// MS2-FUNCTIONAL: inlining only: the exe inlines the string result store (Value::AssignUnsafe(const ASString&))
template struct ThunkFunc0<Class, 2, ASString>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdc40
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$00$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdcb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdd40
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$02$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cddb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cde40
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdeb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$05N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdf40
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cdfb0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$07N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ce040
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$08$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ce0b0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$09N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ce140
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@$0L@$$CBVValue@456@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ce1b0
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$0A@K@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ceb00
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$00J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ceb60
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$01V?$SPtr@VID3Info@fl_media@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cebc0
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$02_N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cec70
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$03N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cecd0
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$04VASString@56@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ced40
// MS2-PIN: ?Func@?$ThunkFunc0@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$05$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cedb0
// MS2-PIN: ?Func@?$ThunkFunc2@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$06$$CBVValue@456@PEAVURLRequest@fl_net@3456@PEAVSoundLoaderContext@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cedd0
// MS2-PIN: ?Func@?$ThunkFunc3@VSound@fl_media@Instances@AS3@GFx@Scaleform@@$07VValue@456@NJPEAVSoundTransform@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cee20
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$0A@N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cef10
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$00N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cef80
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$01N@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424ceff0
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$02V?$SPtr@VSoundTransform@fl_media@Instances@AS3@GFx@Scaleform@@@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cf060
// MS2-PIN: ?Func@?$ThunkFunc1@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$03$$CBVValue@456@PEAVSoundTransform@23456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cf110
// MS2-PIN: ?Func@?$ThunkFunc0@VSoundChannel@fl_media@Instances@AS3@GFx@Scaleform@@$04$$CBVValue@456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424cf150
// MS2-PIN: ?Func@?$ThunkFunc0@VClass@AS3@GFx@Scaleform@@$0A@VValue@234@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424d2160
// MS2-PIN: ?Func@?$ThunkFunc0@VClass@AS3@GFx@Scaleform@@$00J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424d2180
// MS2-PIN: ?Func@?$ThunkFunc0@VClass@AS3@GFx@Scaleform@@$01VASString@34@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424d21e0
