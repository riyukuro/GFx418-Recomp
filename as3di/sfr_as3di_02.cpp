// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, the dynamic initializers of
// the native method member pointers ThunkFuncN<T, N, R, A...>::Method (0x14013f0d0-0x140142910): each stores
// {method, 0} (16 bytes, the general member-pointer representation of as3_marshalling.h). The thunks that call
// through them are in the sfr_as3_* units. Our own source, written from the exe (work/sfr5/gen_natives.py).
// MS2-UNIT: sfr_as3di_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14013f0d0-0x140142910 .text$di
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

namespace Scaleform { namespace GFx { namespace AS3 {

typedef ThunkFunc0<Instances::fl_display::InteractiveObject, 8, bool> TFunc_Instances_fl_display_InteractiveObject_tabEnabledGet;
// @0x14013f0d0
template <> const TFunc_Instances_fl_display_InteractiveObject_tabEnabledGet::TMethod TFunc_Instances_fl_display_InteractiveObject_tabEnabledGet::Method = &Instances::fl_display::InteractiveObject::tabEnabledGet;
typedef ThunkFunc0<Instances::fl_display::InteractiveObject, 10, SInt32> TFunc_Instances_fl_display_InteractiveObject_tabIndexGet;
// @0x14013f100
template <> const TFunc_Instances_fl_display_InteractiveObject_tabIndexGet::TMethod TFunc_Instances_fl_display_InteractiveObject_tabIndexGet::Method = &Instances::fl_display::InteractiveObject::tabIndexGet;
typedef ThunkFunc0<Instances::fl_display::InteractiveObject, 0, SPtr<Instances::fl::Object>> TFunc_Instances_fl_display_InteractiveObject_contextMenuGet;
// @0x14013f130
template <> const TFunc_Instances_fl_display_InteractiveObject_contextMenuGet::TMethod TFunc_Instances_fl_display_InteractiveObject_contextMenuGet::Method = &Instances::fl_display::InteractiveObject::contextMenuGet;
typedef ThunkFunc0<Instances::fl_display::Loader, 1, SPtr<Instances::fl_display::LoaderInfo>> TFunc_Instances_fl_display_Loader_contentLoaderInfoGet;
// @0x14013f160
template <> const TFunc_Instances_fl_display_Loader_contentLoaderInfoGet::TMethod TFunc_Instances_fl_display_Loader_contentLoaderInfoGet::Method = &Instances::fl_display::Loader::contentLoaderInfoGet;
typedef ThunkFunc0<Instances::fl_display::Loader, 2, const Value> TFunc_Instances_fl_display_Loader_close;
// @0x14013f190
template <> const TFunc_Instances_fl_display_Loader_close::TMethod TFunc_Instances_fl_display_Loader_close::Method = &Instances::fl_display::Loader::close;
typedef ThunkFunc0<Instances::fl_display::Loader, 5, const Value> TFunc_Instances_fl_display_Loader_unload;
// @0x14013f1c0
template <> const TFunc_Instances_fl_display_Loader_unload::TMethod TFunc_Instances_fl_display_Loader_unload::Method = &Instances::fl_display::Loader::unload;
typedef ThunkFunc0<Instances::fl_display::Loader, 0, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_Loader_contentGet;
// @0x14013f1f0
template <> const TFunc_Instances_fl_display_Loader_contentGet::TMethod TFunc_Instances_fl_display_Loader_contentGet::Method = &Instances::fl_display::Loader::contentGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 1, SPtr<Instances::fl_system::ApplicationDomain>> TFunc_Instances_fl_display_LoaderInfo_applicationDomainGet;
// @0x14013f220
template <> const TFunc_Instances_fl_display_LoaderInfo_applicationDomainGet::TMethod TFunc_Instances_fl_display_LoaderInfo_applicationDomainGet::Method = &Instances::fl_display::LoaderInfo::applicationDomainGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 2, SPtr<Instances::fl_utils::ByteArray>> TFunc_Instances_fl_display_LoaderInfo_bytesGet;
// @0x14013f250
template <> const TFunc_Instances_fl_display_LoaderInfo_bytesGet::TMethod TFunc_Instances_fl_display_LoaderInfo_bytesGet::Method = &Instances::fl_display::LoaderInfo::bytesGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 3, UInt32> TFunc_Instances_fl_display_LoaderInfo_bytesLoadedGet;
// @0x14013f280
template <> const TFunc_Instances_fl_display_LoaderInfo_bytesLoadedGet::TMethod TFunc_Instances_fl_display_LoaderInfo_bytesLoadedGet::Method = &Instances::fl_display::LoaderInfo::bytesLoadedGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 4, UInt32> TFunc_Instances_fl_display_LoaderInfo_bytesTotalGet;
// @0x14013f2b0
template <> const TFunc_Instances_fl_display_LoaderInfo_bytesTotalGet::TMethod TFunc_Instances_fl_display_LoaderInfo_bytesTotalGet::Method = &Instances::fl_display::LoaderInfo::bytesTotalGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 5, bool> TFunc_Instances_fl_display_LoaderInfo_childAllowsParentGet;
// @0x14013f2e0
template <> const TFunc_Instances_fl_display_LoaderInfo_childAllowsParentGet::TMethod TFunc_Instances_fl_display_LoaderInfo_childAllowsParentGet::Method = &Instances::fl_display::LoaderInfo::childAllowsParentGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 6, SPtr<Instances::fl::Object>> TFunc_Instances_fl_display_LoaderInfo_childSandboxBridgeGet;
// @0x14013f310
template <> const TFunc_Instances_fl_display_LoaderInfo_childSandboxBridgeGet::TMethod TFunc_Instances_fl_display_LoaderInfo_childSandboxBridgeGet::Method = &Instances::fl_display::LoaderInfo::childSandboxBridgeGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 8, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_LoaderInfo_contentGet;
// @0x14013f340
template <> const TFunc_Instances_fl_display_LoaderInfo_contentGet::TMethod TFunc_Instances_fl_display_LoaderInfo_contentGet::Method = &Instances::fl_display::LoaderInfo::contentGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 9, ASString> TFunc_Instances_fl_display_LoaderInfo_contentTypeGet;
// @0x14013f370
template <> const TFunc_Instances_fl_display_LoaderInfo_contentTypeGet::TMethod TFunc_Instances_fl_display_LoaderInfo_contentTypeGet::Method = &Instances::fl_display::LoaderInfo::contentTypeGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 10, Value::Number> TFunc_Instances_fl_display_LoaderInfo_frameRateGet;
// @0x14013f3a0
template <> const TFunc_Instances_fl_display_LoaderInfo_frameRateGet::TMethod TFunc_Instances_fl_display_LoaderInfo_frameRateGet::Method = &Instances::fl_display::LoaderInfo::frameRateGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 0, UInt32> TFunc_Instances_fl_display_LoaderInfo_actionScriptVersionGet;
// @0x14013f3d0
template <> const TFunc_Instances_fl_display_LoaderInfo_actionScriptVersionGet::TMethod TFunc_Instances_fl_display_LoaderInfo_actionScriptVersionGet::Method = &Instances::fl_display::LoaderInfo::actionScriptVersionGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 16, SPtr<Instances::fl::Object>> TFunc_Instances_fl_display_LoaderInfo_parentSandboxBridgeGet;
// @0x14013f400
template <> const TFunc_Instances_fl_display_LoaderInfo_parentSandboxBridgeGet::TMethod TFunc_Instances_fl_display_LoaderInfo_parentSandboxBridgeGet::Method = &Instances::fl_display::LoaderInfo::parentSandboxBridgeGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 18, bool> TFunc_Instances_fl_display_LoaderInfo_sameDomainGet;
// @0x14013f430
template <> const TFunc_Instances_fl_display_LoaderInfo_sameDomainGet::TMethod TFunc_Instances_fl_display_LoaderInfo_sameDomainGet::Method = &Instances::fl_display::LoaderInfo::sameDomainGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 19, SPtr<Instances::fl_events::EventDispatcher>> TFunc_Instances_fl_display_LoaderInfo_sharedEventsGet;
// @0x14013f460
template <> const TFunc_Instances_fl_display_LoaderInfo_sharedEventsGet::TMethod TFunc_Instances_fl_display_LoaderInfo_sharedEventsGet::Method = &Instances::fl_display::LoaderInfo::sharedEventsGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 20, UInt32> TFunc_Instances_fl_display_LoaderInfo_swfVersionGet;
// @0x14013f490
template <> const TFunc_Instances_fl_display_LoaderInfo_swfVersionGet::TMethod TFunc_Instances_fl_display_LoaderInfo_swfVersionGet::Method = &Instances::fl_display::LoaderInfo::swfVersionGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 21, ASString> TFunc_Instances_fl_display_LoaderInfo_urlGet;
// @0x14013f4c0
template <> const TFunc_Instances_fl_display_LoaderInfo_urlGet::TMethod TFunc_Instances_fl_display_LoaderInfo_urlGet::Method = &Instances::fl_display::LoaderInfo::urlGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 22, SInt32> TFunc_Instances_fl_display_LoaderInfo_widthGet;
// @0x14013f4f0
template <> const TFunc_Instances_fl_display_LoaderInfo_widthGet::TMethod TFunc_Instances_fl_display_LoaderInfo_widthGet::Method = &Instances::fl_display::LoaderInfo::widthGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 11, SInt32> TFunc_Instances_fl_display_LoaderInfo_heightGet;
// @0x14013f520
template <> const TFunc_Instances_fl_display_LoaderInfo_heightGet::TMethod TFunc_Instances_fl_display_LoaderInfo_heightGet::Method = &Instances::fl_display::LoaderInfo::heightGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 12, SPtr<Instances::fl_display::Loader>> TFunc_Instances_fl_display_LoaderInfo_loaderGet;
// @0x14013f550
template <> const TFunc_Instances_fl_display_LoaderInfo_loaderGet::TMethod TFunc_Instances_fl_display_LoaderInfo_loaderGet::Method = &Instances::fl_display::LoaderInfo::loaderGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 13, ASString> TFunc_Instances_fl_display_LoaderInfo_loaderURLGet;
// @0x14013f580
template <> const TFunc_Instances_fl_display_LoaderInfo_loaderURLGet::TMethod TFunc_Instances_fl_display_LoaderInfo_loaderURLGet::Method = &Instances::fl_display::LoaderInfo::loaderURLGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 14, SPtr<Instances::fl::Object>> TFunc_Instances_fl_display_LoaderInfo_parametersGet;
// @0x14013f5b0
template <> const TFunc_Instances_fl_display_LoaderInfo_parametersGet::TMethod TFunc_Instances_fl_display_LoaderInfo_parametersGet::Method = &Instances::fl_display::LoaderInfo::parametersGet;
typedef ThunkFunc0<Instances::fl_display::LoaderInfo, 15, bool> TFunc_Instances_fl_display_LoaderInfo_parentAllowsChildGet;
// @0x14013f5e0
template <> const TFunc_Instances_fl_display_LoaderInfo_parentAllowsChildGet::TMethod TFunc_Instances_fl_display_LoaderInfo_parentAllowsChildGet::Method = &Instances::fl_display::LoaderInfo::parentAllowsChildGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 1, ASString> TFunc_Instances_fl_display_MovieClip_currentFrameLabelGet;
// @0x14013f610
template <> const TFunc_Instances_fl_display_MovieClip_currentFrameLabelGet::TMethod TFunc_Instances_fl_display_MovieClip_currentFrameLabelGet::Method = &Instances::fl_display::MovieClip::currentFrameLabelGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 2, ASString> TFunc_Instances_fl_display_MovieClip_currentLabelGet;
// @0x14013f640
template <> const TFunc_Instances_fl_display_MovieClip_currentLabelGet::TMethod TFunc_Instances_fl_display_MovieClip_currentLabelGet::Method = &Instances::fl_display::MovieClip::currentLabelGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 3, SPtr<Instances::fl::Array>> TFunc_Instances_fl_display_MovieClip_currentLabelsGet;
// @0x14013f670
template <> const TFunc_Instances_fl_display_MovieClip_currentLabelsGet::TMethod TFunc_Instances_fl_display_MovieClip_currentLabelsGet::Method = &Instances::fl_display::MovieClip::currentLabelsGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 4, SPtr<Instances::fl_display::Scene>> TFunc_Instances_fl_display_MovieClip_currentSceneGet;
// @0x14013f6a0
template <> const TFunc_Instances_fl_display_MovieClip_currentSceneGet::TMethod TFunc_Instances_fl_display_MovieClip_currentSceneGet::Method = &Instances::fl_display::MovieClip::currentSceneGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 5, bool> TFunc_Instances_fl_display_MovieClip_enabledGet;
// @0x14013f6d0
template <> const TFunc_Instances_fl_display_MovieClip_enabledGet::TMethod TFunc_Instances_fl_display_MovieClip_enabledGet::Method = &Instances::fl_display::MovieClip::enabledGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 7, SInt32> TFunc_Instances_fl_display_MovieClip_framesLoadedGet;
// @0x14013f700
template <> const TFunc_Instances_fl_display_MovieClip_framesLoadedGet::TMethod TFunc_Instances_fl_display_MovieClip_framesLoadedGet::Method = &Instances::fl_display::MovieClip::framesLoadedGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 8, SPtr<Instances::fl::Array>> TFunc_Instances_fl_display_MovieClip_scenesGet;
// @0x14013f730
template <> const TFunc_Instances_fl_display_MovieClip_scenesGet::TMethod TFunc_Instances_fl_display_MovieClip_scenesGet::Method = &Instances::fl_display::MovieClip::scenesGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 9, SInt32> TFunc_Instances_fl_display_MovieClip_totalFramesGet;
// @0x14013f760
template <> const TFunc_Instances_fl_display_MovieClip_totalFramesGet::TMethod TFunc_Instances_fl_display_MovieClip_totalFramesGet::Method = &Instances::fl_display::MovieClip::totalFramesGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 10, bool> TFunc_Instances_fl_display_MovieClip_trackAsMenuGet;
// @0x14013f790
template <> const TFunc_Instances_fl_display_MovieClip_trackAsMenuGet::TMethod TFunc_Instances_fl_display_MovieClip_trackAsMenuGet::Method = &Instances::fl_display::MovieClip::trackAsMenuGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 0, SInt32> TFunc_Instances_fl_display_MovieClip_currentFrameGet;
// @0x14013f7c0
template <> const TFunc_Instances_fl_display_MovieClip_currentFrameGet::TMethod TFunc_Instances_fl_display_MovieClip_currentFrameGet::Method = &Instances::fl_display::MovieClip::currentFrameGet;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 16, const Value> TFunc_Instances_fl_display_MovieClip_nextScene;
// @0x14013f7f0
template <> const TFunc_Instances_fl_display_MovieClip_nextScene::TMethod TFunc_Instances_fl_display_MovieClip_nextScene::Method = &Instances::fl_display::MovieClip::nextScene;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 17, const Value> TFunc_Instances_fl_display_MovieClip_play;
// @0x14013f820
template <> const TFunc_Instances_fl_display_MovieClip_play::TMethod TFunc_Instances_fl_display_MovieClip_play::Method = &Instances::fl_display::MovieClip::play;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 18, const Value> TFunc_Instances_fl_display_MovieClip_prevFrame;
// @0x14013f850
template <> const TFunc_Instances_fl_display_MovieClip_prevFrame::TMethod TFunc_Instances_fl_display_MovieClip_prevFrame::Method = &Instances::fl_display::MovieClip::prevFrame;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 19, const Value> TFunc_Instances_fl_display_MovieClip_prevScene;
// @0x14013f880
template <> const TFunc_Instances_fl_display_MovieClip_prevScene::TMethod TFunc_Instances_fl_display_MovieClip_prevScene::Method = &Instances::fl_display::MovieClip::prevScene;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 20, const Value> TFunc_Instances_fl_display_MovieClip_stop;
// @0x14013f8b0
template <> const TFunc_Instances_fl_display_MovieClip_stop::TMethod TFunc_Instances_fl_display_MovieClip_stop::Method = &Instances::fl_display::MovieClip::stop;
typedef ThunkFunc0<Instances::fl_display::MovieClip, 15, const Value> TFunc_Instances_fl_display_MovieClip_nextFrame;
// @0x14013f8e0
template <> const TFunc_Instances_fl_display_MovieClip_nextFrame::TMethod TFunc_Instances_fl_display_MovieClip_nextFrame::Method = &Instances::fl_display::MovieClip::nextFrame;
typedef ThunkFunc0<Instances::fl_display::Scene, 1, ASString> TFunc_Instances_fl_display_Scene_nameGet;
// @0x14013f910
template <> const TFunc_Instances_fl_display_Scene_nameGet::TMethod TFunc_Instances_fl_display_Scene_nameGet::Method = &Instances::fl_display::Scene::nameGet;
typedef ThunkFunc0<Instances::fl_display::Scene, 2, SInt32> TFunc_Instances_fl_display_Scene_numFramesGet;
// @0x14013f940
template <> const TFunc_Instances_fl_display_Scene_numFramesGet::TMethod TFunc_Instances_fl_display_Scene_numFramesGet::Method = &Instances::fl_display::Scene::numFramesGet;
typedef ThunkFunc0<Instances::fl_display::Scene, 0, SPtr<Instances::fl::Array>> TFunc_Instances_fl_display_Scene_labelsGet;
// @0x14013f970
template <> const TFunc_Instances_fl_display_Scene_labelsGet::TMethod TFunc_Instances_fl_display_Scene_labelsGet::Method = &Instances::fl_display::Scene::labelsGet;
typedef ThunkFunc0<Instances::fl_display::Shape, 0, SPtr<Instances::fl_display::Graphics>> TFunc_Instances_fl_display_Shape_graphicsGet;
// @0x14013f9a0
template <> const TFunc_Instances_fl_display_Shape_graphicsGet::TMethod TFunc_Instances_fl_display_Shape_graphicsGet::Method = &Instances::fl_display::Shape::graphicsGet;
typedef ThunkFunc0<Instances::fl_display::SimpleButton, 2, bool> TFunc_Instances_fl_display_SimpleButton_enabledGet;
// @0x14013f9d0
template <> const TFunc_Instances_fl_display_SimpleButton_enabledGet::TMethod TFunc_Instances_fl_display_SimpleButton_enabledGet::Method = &Instances::fl_display::SimpleButton::enabledGet;
typedef ThunkFunc0<Instances::fl_display::SimpleButton, 4, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_SimpleButton_hitTestStateGet;
// @0x14013fa00
template <> const TFunc_Instances_fl_display_SimpleButton_hitTestStateGet::TMethod TFunc_Instances_fl_display_SimpleButton_hitTestStateGet::Method = &Instances::fl_display::SimpleButton::hitTestStateGet;
typedef ThunkFunc0<Instances::fl_display::SimpleButton, 6, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_SimpleButton_overStateGet;
// @0x14013fa30
template <> const TFunc_Instances_fl_display_SimpleButton_overStateGet::TMethod TFunc_Instances_fl_display_SimpleButton_overStateGet::Method = &Instances::fl_display::SimpleButton::overStateGet;
typedef ThunkFunc0<Instances::fl_display::SimpleButton, 8, SPtr<Instances::fl_media::SoundTransform>> TFunc_Instances_fl_display_SimpleButton_soundTransformGet;
// @0x14013fa60
template <> const TFunc_Instances_fl_display_SimpleButton_soundTransformGet::TMethod TFunc_Instances_fl_display_SimpleButton_soundTransformGet::Method = &Instances::fl_display::SimpleButton::soundTransformGet;
typedef ThunkFunc0<Instances::fl_display::SimpleButton, 10, bool> TFunc_Instances_fl_display_SimpleButton_trackAsMenuGet;
// @0x14013fa90
template <> const TFunc_Instances_fl_display_SimpleButton_trackAsMenuGet::TMethod TFunc_Instances_fl_display_SimpleButton_trackAsMenuGet::Method = &Instances::fl_display::SimpleButton::trackAsMenuGet;
typedef ThunkFunc0<Instances::fl_display::SimpleButton, 0, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_SimpleButton_downStateGet;
// @0x14013fac0
template <> const TFunc_Instances_fl_display_SimpleButton_downStateGet::TMethod TFunc_Instances_fl_display_SimpleButton_downStateGet::Method = &Instances::fl_display::SimpleButton::downStateGet;
typedef ThunkFunc0<Instances::fl_display::SimpleButton, 12, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_SimpleButton_upStateGet;
// @0x14013faf0
template <> const TFunc_Instances_fl_display_SimpleButton_upStateGet::TMethod TFunc_Instances_fl_display_SimpleButton_upStateGet::Method = &Instances::fl_display::SimpleButton::upStateGet;
typedef ThunkFunc0<Instances::fl_display::SimpleButton, 14, bool> TFunc_Instances_fl_display_SimpleButton_useHandCursorGet;
// @0x14013fb20
template <> const TFunc_Instances_fl_display_SimpleButton_useHandCursorGet::TMethod TFunc_Instances_fl_display_SimpleButton_useHandCursorGet::Method = &Instances::fl_display::SimpleButton::useHandCursorGet;
typedef ThunkFunc0<Instances::fl_display::Sprite, 2, SPtr<Instances::fl_display::DisplayObject>> TFunc_Instances_fl_display_Sprite_dropTargetGet;
// @0x14013fb50
template <> const TFunc_Instances_fl_display_Sprite_dropTargetGet::TMethod TFunc_Instances_fl_display_Sprite_dropTargetGet::Method = &Instances::fl_display::Sprite::dropTargetGet;
typedef ThunkFunc0<Instances::fl_display::Sprite, 3, SPtr<Instances::fl_display::Graphics>> TFunc_Instances_fl_display_Sprite_graphicsGet;
// @0x14013fb80
template <> const TFunc_Instances_fl_display_Sprite_graphicsGet::TMethod TFunc_Instances_fl_display_Sprite_graphicsGet::Method = &Instances::fl_display::Sprite::graphicsGet;
typedef ThunkFunc0<Instances::fl_display::Sprite, 4, SPtr<Instances::fl_display::Sprite>> TFunc_Instances_fl_display_Sprite_hitAreaGet;
// @0x14013fbb0
template <> const TFunc_Instances_fl_display_Sprite_hitAreaGet::TMethod TFunc_Instances_fl_display_Sprite_hitAreaGet::Method = &Instances::fl_display::Sprite::hitAreaGet;
typedef ThunkFunc0<Instances::fl_display::Sprite, 6, SPtr<Instances::fl_media::SoundTransform>> TFunc_Instances_fl_display_Sprite_soundTransformGet;
// @0x14013fbe0
template <> const TFunc_Instances_fl_display_Sprite_soundTransformGet::TMethod TFunc_Instances_fl_display_Sprite_soundTransformGet::Method = &Instances::fl_display::Sprite::soundTransformGet;
typedef ThunkFunc0<Instances::fl_display::Sprite, 8, bool> TFunc_Instances_fl_display_Sprite_useHandCursorGet;
// @0x14013fc10
template <> const TFunc_Instances_fl_display_Sprite_useHandCursorGet::TMethod TFunc_Instances_fl_display_Sprite_useHandCursorGet::Method = &Instances::fl_display::Sprite::useHandCursorGet;
typedef ThunkFunc0<Instances::fl_display::Sprite, 0, bool> TFunc_Instances_fl_display_Sprite_buttonModeGet;
// @0x14013fc40
template <> const TFunc_Instances_fl_display_Sprite_buttonModeGet::TMethod TFunc_Instances_fl_display_Sprite_buttonModeGet::Method = &Instances::fl_display::Sprite::buttonModeGet;
typedef ThunkFunc0<Instances::fl_display::Sprite, 11, const Value> TFunc_Instances_fl_display_Sprite_stopDrag;
// @0x14013fc70
template <> const TFunc_Instances_fl_display_Sprite_stopDrag::TMethod TFunc_Instances_fl_display_Sprite_stopDrag::Method = &Instances::fl_display::Sprite::stopDrag;
typedef ThunkFunc0<Classes::fl_display::Stage, 0, bool> TFunc_Classes_fl_display_Stage_supportsOrientationChangeGet;
// @0x14013fca0
template <> const TFunc_Classes_fl_display_Stage_supportsOrientationChangeGet::TMethod TFunc_Classes_fl_display_Stage_supportsOrientationChangeGet::Method = &Classes::fl_display::Stage::supportsOrientationChangeGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 2, bool> TFunc_Instances_fl_display_Stage_autoOrientsGet;
// @0x14013fcd0
template <> const TFunc_Instances_fl_display_Stage_autoOrientsGet::TMethod TFunc_Instances_fl_display_Stage_autoOrientsGet::Method = &Instances::fl_display::Stage::autoOrientsGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 3, ASString> TFunc_Instances_fl_display_Stage_deviceOrientationGet;
// @0x14013fd00
template <> const TFunc_Instances_fl_display_Stage_deviceOrientationGet::TMethod TFunc_Instances_fl_display_Stage_deviceOrientationGet::Method = &Instances::fl_display::Stage::deviceOrientationGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 4, ASString> TFunc_Instances_fl_display_Stage_displayStateGet;
// @0x14013fd30
template <> const TFunc_Instances_fl_display_Stage_displayStateGet::TMethod TFunc_Instances_fl_display_Stage_displayStateGet::Method = &Instances::fl_display::Stage::displayStateGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 6, SPtr<Instances::fl_display::InteractiveObject>> TFunc_Instances_fl_display_Stage_focusGet;
// @0x14013fd60
template <> const TFunc_Instances_fl_display_Stage_focusGet::TMethod TFunc_Instances_fl_display_Stage_focusGet::Method = &Instances::fl_display::Stage::focusGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 8, Value::Number> TFunc_Instances_fl_display_Stage_frameRateGet;
// @0x14013fd90
template <> const TFunc_Instances_fl_display_Stage_frameRateGet::TMethod TFunc_Instances_fl_display_Stage_frameRateGet::Method = &Instances::fl_display::Stage::frameRateGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 10, UInt32> TFunc_Instances_fl_display_Stage_fullScreenHeightGet;
// @0x14013fdc0
template <> const TFunc_Instances_fl_display_Stage_fullScreenHeightGet::TMethod TFunc_Instances_fl_display_Stage_fullScreenHeightGet::Method = &Instances::fl_display::Stage::fullScreenHeightGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 0, ASString> TFunc_Instances_fl_display_Stage_alignGet;
// @0x14013fdf0
template <> const TFunc_Instances_fl_display_Stage_alignGet::TMethod TFunc_Instances_fl_display_Stage_alignGet::Method = &Instances::fl_display::Stage::alignGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 16, bool> TFunc_Instances_fl_display_Stage_mouseChildrenGet;
// @0x14013fe20
template <> const TFunc_Instances_fl_display_Stage_mouseChildrenGet::TMethod TFunc_Instances_fl_display_Stage_mouseChildrenGet::Method = &Instances::fl_display::Stage::mouseChildrenGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 900, SPtr<Instances::fl_display::NativeWindow>> TFunc_Instances_fl_display_Stage_nativeWindowGet;
// @0x14013fe50
template <> const TFunc_Instances_fl_display_Stage_nativeWindowGet::TMethod TFunc_Instances_fl_display_Stage_nativeWindowGet::Method = &Instances::fl_display::Stage::nativeWindowGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 18, SInt32> TFunc_Instances_fl_display_Stage_numChildrenGet;
// @0x14013fe80
template <> const TFunc_Instances_fl_display_Stage_numChildrenGet::TMethod TFunc_Instances_fl_display_Stage_numChildrenGet::Method = &Instances::fl_display::Stage::numChildrenGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 19, ASString> TFunc_Instances_fl_display_Stage_orientationGet;
// @0x14013feb0
template <> const TFunc_Instances_fl_display_Stage_orientationGet::TMethod TFunc_Instances_fl_display_Stage_orientationGet::Method = &Instances::fl_display::Stage::orientationGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 20, ASString> TFunc_Instances_fl_display_Stage_qualityGet;
// @0x14013fee0
template <> const TFunc_Instances_fl_display_Stage_qualityGet::TMethod TFunc_Instances_fl_display_Stage_qualityGet::Method = &Instances::fl_display::Stage::qualityGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 22, ASString> TFunc_Instances_fl_display_Stage_scaleModeGet;
// @0x14013ff10
template <> const TFunc_Instances_fl_display_Stage_scaleModeGet::TMethod TFunc_Instances_fl_display_Stage_scaleModeGet::Method = &Instances::fl_display::Stage::scaleModeGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 24, bool> TFunc_Instances_fl_display_Stage_showDefaultContextMenuGet;
// @0x14013ff40
template <> const TFunc_Instances_fl_display_Stage_showDefaultContextMenuGet::TMethod TFunc_Instances_fl_display_Stage_showDefaultContextMenuGet::Method = &Instances::fl_display::Stage::showDefaultContextMenuGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 26, bool> TFunc_Instances_fl_display_Stage_stageFocusRectGet;
// @0x14013ff70
template <> const TFunc_Instances_fl_display_Stage_stageFocusRectGet::TMethod TFunc_Instances_fl_display_Stage_stageFocusRectGet::Method = &Instances::fl_display::Stage::stageFocusRectGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 28, SInt32> TFunc_Instances_fl_display_Stage_stageHeightGet;
// @0x14013ffa0
template <> const TFunc_Instances_fl_display_Stage_stageHeightGet::TMethod TFunc_Instances_fl_display_Stage_stageHeightGet::Method = &Instances::fl_display::Stage::stageHeightGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 30, SInt32> TFunc_Instances_fl_display_Stage_stageWidthGet;
// @0x14013ffd0
template <> const TFunc_Instances_fl_display_Stage_stageWidthGet::TMethod TFunc_Instances_fl_display_Stage_stageWidthGet::Method = &Instances::fl_display::Stage::stageWidthGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 32, bool> TFunc_Instances_fl_display_Stage_tabChildrenGet;
// @0x140140000
template <> const TFunc_Instances_fl_display_Stage_tabChildrenGet::TMethod TFunc_Instances_fl_display_Stage_tabChildrenGet::Method = &Instances::fl_display::Stage::tabChildrenGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 34, SPtr<Instances::fl_text::TextSnapshot>> TFunc_Instances_fl_display_Stage_textSnapshotGet;
// @0x140140030
template <> const TFunc_Instances_fl_display_Stage_textSnapshotGet::TMethod TFunc_Instances_fl_display_Stage_textSnapshotGet::Method = &Instances::fl_display::Stage::textSnapshotGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 35, Value::Number> TFunc_Instances_fl_display_Stage_widthGet;
// @0x140140060
template <> const TFunc_Instances_fl_display_Stage_widthGet::TMethod TFunc_Instances_fl_display_Stage_widthGet::Method = &Instances::fl_display::Stage::widthGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 43, const Value> TFunc_Instances_fl_display_Stage_invalidate;
// @0x140140090
template <> const TFunc_Instances_fl_display_Stage_invalidate::TMethod TFunc_Instances_fl_display_Stage_invalidate::Method = &Instances::fl_display::Stage::invalidate;
typedef ThunkFunc0<Instances::fl_display::Stage, 44, bool> TFunc_Instances_fl_display_Stage_isFocusInaccessible;
// @0x1401400c0
template <> const TFunc_Instances_fl_display_Stage_isFocusInaccessible::TMethod TFunc_Instances_fl_display_Stage_isFocusInaccessible::Method = &Instances::fl_display::Stage::isFocusInaccessible;
typedef ThunkFunc0<Instances::fl_display::Stage, 11, SPtr<Instances::fl_geom::Rectangle>> TFunc_Instances_fl_display_Stage_fullScreenSourceRectGet;
// @0x1401400f0
template <> const TFunc_Instances_fl_display_Stage_fullScreenSourceRectGet::TMethod TFunc_Instances_fl_display_Stage_fullScreenSourceRectGet::Method = &Instances::fl_display::Stage::fullScreenSourceRectGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 13, UInt32> TFunc_Instances_fl_display_Stage_fullScreenWidthGet;
// @0x140140120
template <> const TFunc_Instances_fl_display_Stage_fullScreenWidthGet::TMethod TFunc_Instances_fl_display_Stage_fullScreenWidthGet::Method = &Instances::fl_display::Stage::fullScreenWidthGet;
typedef ThunkFunc0<Instances::fl_display::Stage, 14, Value::Number> TFunc_Instances_fl_display_Stage_heightGet;
// @0x140140150
template <> const TFunc_Instances_fl_display_Stage_heightGet::TMethod TFunc_Instances_fl_display_Stage_heightGet::Method = &Instances::fl_display::Stage::heightGet;
typedef ThunkFunc1<Instances::fl_display::Bitmap, 1, const Value, Instances::fl_display::BitmapData*> TFunc_Instances_fl_display_Bitmap_bitmapDataSet;
// @0x140140180
template <> const TFunc_Instances_fl_display_Bitmap_bitmapDataSet::TMethod TFunc_Instances_fl_display_Bitmap_bitmapDataSet::Method = &Instances::fl_display::Bitmap::bitmapDataSet;
typedef ThunkFunc1<Instances::fl_display::Bitmap, 3, const Value, const ASString&> TFunc_Instances_fl_display_Bitmap_pixelSnappingSet;
// @0x1401401b0
template <> const TFunc_Instances_fl_display_Bitmap_pixelSnappingSet::TMethod TFunc_Instances_fl_display_Bitmap_pixelSnappingSet::Method = &Instances::fl_display::Bitmap::pixelSnappingSet;
typedef ThunkFunc1<Instances::fl_display::Bitmap, 5, const Value, bool> TFunc_Instances_fl_display_Bitmap_smoothingSet;
// @0x1401401e0
template <> const TFunc_Instances_fl_display_Bitmap_smoothingSet::TMethod TFunc_Instances_fl_display_Bitmap_smoothingSet::Method = &Instances::fl_display::Bitmap::smoothingSet;
typedef ThunkFunc1<Instances::fl_display::BitmapData, 7, Value, Instances::fl_display::BitmapData*> TFunc_Instances_fl_display_BitmapData_compare;
// @0x140140210
template <> const TFunc_Instances_fl_display_BitmapData_compare::TMethod TFunc_Instances_fl_display_BitmapData_compare::Method = &Instances::fl_display::BitmapData::compare;
typedef ThunkFunc1<Instances::fl_display::BitmapData, 18, SPtr<Instances::fl_utils::ByteArray>, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_display_BitmapData_getPixels;
// @0x140140240
template <> const TFunc_Instances_fl_display_BitmapData_getPixels::TMethod TFunc_Instances_fl_display_BitmapData_getPixels::Method = &Instances::fl_display::BitmapData::getPixels;
typedef ThunkFunc1<Instances::fl_display::BitmapData, 19, SPtr<Instances::fl_vec::Vector_uint>, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_display_BitmapData_getVector;
// @0x140140270
template <> const TFunc_Instances_fl_display_BitmapData_getVector::TMethod TFunc_Instances_fl_display_BitmapData_getVector::Method = &Instances::fl_display::BitmapData::getVector;
typedef ThunkFunc1<Instances::fl_display::BitmapData, 21, SPtr<Instances::fl::Object>, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_display_BitmapData_histogram;
// @0x1401402a0
template <> const TFunc_Instances_fl_display_BitmapData_histogram::TMethod TFunc_Instances_fl_display_BitmapData_histogram::Method = &Instances::fl_display::BitmapData::histogram;
typedef ThunkFunc1<Instances::fl_display::BitmapData, 34, const Value, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_display_BitmapData_unlock;
// @0x1401402d0
template <> const TFunc_Instances_fl_display_BitmapData_unlock::TMethod TFunc_Instances_fl_display_BitmapData_unlock::Method = &Instances::fl_display::BitmapData::unlock;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 1, const Value, Instances::fl_accessibility::AccessibilityProperties*> TFunc_Instances_fl_display_DisplayObject_accessibilityPropertiesSet;
// @0x140140300
template <> const TFunc_Instances_fl_display_DisplayObject_accessibilityPropertiesSet::TMethod TFunc_Instances_fl_display_DisplayObject_accessibilityPropertiesSet::Method = &Instances::fl_display::DisplayObject::accessibilityPropertiesSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 3, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_alphaSet;
// @0x140140330
template <> const TFunc_Instances_fl_display_DisplayObject_alphaSet::TMethod TFunc_Instances_fl_display_DisplayObject_alphaSet::Method = &Instances::fl_display::DisplayObject::alphaSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 5, const Value, const ASString&> TFunc_Instances_fl_display_DisplayObject_blendModeSet;
// @0x140140360
template <> const TFunc_Instances_fl_display_DisplayObject_blendModeSet::TMethod TFunc_Instances_fl_display_DisplayObject_blendModeSet::Method = &Instances::fl_display::DisplayObject::blendModeSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 7, const Value, bool> TFunc_Instances_fl_display_DisplayObject_cacheAsBitmapSet;
// @0x140140390
template <> const TFunc_Instances_fl_display_DisplayObject_cacheAsBitmapSet::TMethod TFunc_Instances_fl_display_DisplayObject_cacheAsBitmapSet::Method = &Instances::fl_display::DisplayObject::cacheAsBitmapSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 9, const Value, Instances::fl::Array*> TFunc_Instances_fl_display_DisplayObject_filtersSet;
// @0x1401403c0
template <> const TFunc_Instances_fl_display_DisplayObject_filtersSet::TMethod TFunc_Instances_fl_display_DisplayObject_filtersSet::Method = &Instances::fl_display::DisplayObject::filtersSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 18, const Value, const ASString&> TFunc_Instances_fl_display_DisplayObject_nameSet;
// @0x1401403f0
template <> const TFunc_Instances_fl_display_DisplayObject_nameSet::TMethod TFunc_Instances_fl_display_DisplayObject_nameSet::Method = &Instances::fl_display::DisplayObject::nameSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 20, const Value, const Value&> TFunc_Instances_fl_display_DisplayObject_opaqueBackgroundSet;
// @0x140140420
template <> const TFunc_Instances_fl_display_DisplayObject_opaqueBackgroundSet::TMethod TFunc_Instances_fl_display_DisplayObject_opaqueBackgroundSet::Method = &Instances::fl_display::DisplayObject::opaqueBackgroundSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 24, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_rotationSet;
// @0x140140450
template <> const TFunc_Instances_fl_display_DisplayObject_rotationSet::TMethod TFunc_Instances_fl_display_DisplayObject_rotationSet::Method = &Instances::fl_display::DisplayObject::rotationSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 26, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_rotationXSet;
// @0x140140480
template <> const TFunc_Instances_fl_display_DisplayObject_rotationXSet::TMethod TFunc_Instances_fl_display_DisplayObject_rotationXSet::Method = &Instances::fl_display::DisplayObject::rotationXSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 28, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_rotationYSet;
// @0x1401404b0
template <> const TFunc_Instances_fl_display_DisplayObject_rotationYSet::TMethod TFunc_Instances_fl_display_DisplayObject_rotationYSet::Method = &Instances::fl_display::DisplayObject::rotationYSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 30, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_rotationZSet;
// @0x1401404e0
template <> const TFunc_Instances_fl_display_DisplayObject_rotationZSet::TMethod TFunc_Instances_fl_display_DisplayObject_rotationZSet::Method = &Instances::fl_display::DisplayObject::rotationZSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 32, const Value, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_display_DisplayObject_scale9GridSet;
// @0x140140510
template <> const TFunc_Instances_fl_display_DisplayObject_scale9GridSet::TMethod TFunc_Instances_fl_display_DisplayObject_scale9GridSet::Method = &Instances::fl_display::DisplayObject::scale9GridSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 34, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_scaleXSet;
// @0x140140540
template <> const TFunc_Instances_fl_display_DisplayObject_scaleXSet::TMethod TFunc_Instances_fl_display_DisplayObject_scaleXSet::Method = &Instances::fl_display::DisplayObject::scaleXSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 36, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_scaleYSet;
// @0x140140570
template <> const TFunc_Instances_fl_display_DisplayObject_scaleYSet::TMethod TFunc_Instances_fl_display_DisplayObject_scaleYSet::Method = &Instances::fl_display::DisplayObject::scaleYSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 38, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_scaleZSet;
// @0x1401405a0
template <> const TFunc_Instances_fl_display_DisplayObject_scaleZSet::TMethod TFunc_Instances_fl_display_DisplayObject_scaleZSet::Method = &Instances::fl_display::DisplayObject::scaleZSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 40, const Value, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_display_DisplayObject_scrollRectSet;
// @0x1401405d0
template <> const TFunc_Instances_fl_display_DisplayObject_scrollRectSet::TMethod TFunc_Instances_fl_display_DisplayObject_scrollRectSet::Method = &Instances::fl_display::DisplayObject::scrollRectSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 43, const Value, Instances::fl_geom::Transform*> TFunc_Instances_fl_display_DisplayObject_transformSet;
// @0x140140600
template <> const TFunc_Instances_fl_display_DisplayObject_transformSet::TMethod TFunc_Instances_fl_display_DisplayObject_transformSet::Method = &Instances::fl_display::DisplayObject::transformSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 45, const Value, bool> TFunc_Instances_fl_display_DisplayObject_visibleSet;
// @0x140140630
template <> const TFunc_Instances_fl_display_DisplayObject_visibleSet::TMethod TFunc_Instances_fl_display_DisplayObject_visibleSet::Method = &Instances::fl_display::DisplayObject::visibleSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 47, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_widthSet;
// @0x140140660
template <> const TFunc_Instances_fl_display_DisplayObject_widthSet::TMethod TFunc_Instances_fl_display_DisplayObject_widthSet::Method = &Instances::fl_display::DisplayObject::widthSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 49, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_xSet;
// @0x140140690
template <> const TFunc_Instances_fl_display_DisplayObject_xSet::TMethod TFunc_Instances_fl_display_DisplayObject_xSet::Method = &Instances::fl_display::DisplayObject::xSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 51, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_ySet;
// @0x1401406c0
template <> const TFunc_Instances_fl_display_DisplayObject_ySet::TMethod TFunc_Instances_fl_display_DisplayObject_ySet::Method = &Instances::fl_display::DisplayObject::ySet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 53, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_zSet;
// @0x1401406f0
template <> const TFunc_Instances_fl_display_DisplayObject_zSet::TMethod TFunc_Instances_fl_display_DisplayObject_zSet::Method = &Instances::fl_display::DisplayObject::zSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 54, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_DisplayObject_getBounds;
// @0x140140720
template <> const TFunc_Instances_fl_display_DisplayObject_getBounds::TMethod TFunc_Instances_fl_display_DisplayObject_getBounds::Method = &Instances::fl_display::DisplayObject::getBounds;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 55, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_DisplayObject_getRect;
// @0x140140750
template <> const TFunc_Instances_fl_display_DisplayObject_getRect::TMethod TFunc_Instances_fl_display_DisplayObject_getRect::Method = &Instances::fl_display::DisplayObject::getRect;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 56, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*> TFunc_Instances_fl_display_DisplayObject_globalToLocal;
// @0x140140780
template <> const TFunc_Instances_fl_display_DisplayObject_globalToLocal::TMethod TFunc_Instances_fl_display_DisplayObject_globalToLocal::Method = &Instances::fl_display::DisplayObject::globalToLocal;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 57, SPtr<Instances::fl_geom::Vector3D>, Instances::fl_geom::Point*> TFunc_Instances_fl_display_DisplayObject_globalToLocal3D;
// @0x1401407b0
template <> const TFunc_Instances_fl_display_DisplayObject_globalToLocal3D::TMethod TFunc_Instances_fl_display_DisplayObject_globalToLocal3D::Method = &Instances::fl_display::DisplayObject::globalToLocal3D;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 58, bool, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_DisplayObject_hitTestObject;
// @0x1401407e0
template <> const TFunc_Instances_fl_display_DisplayObject_hitTestObject::TMethod TFunc_Instances_fl_display_DisplayObject_hitTestObject::Method = &Instances::fl_display::DisplayObject::hitTestObject;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 60, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*> TFunc_Instances_fl_display_DisplayObject_localToGlobal;
// @0x140140810
template <> const TFunc_Instances_fl_display_DisplayObject_localToGlobal::TMethod TFunc_Instances_fl_display_DisplayObject_localToGlobal::Method = &Instances::fl_display::DisplayObject::localToGlobal;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 61, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_display_DisplayObject_local3DToGlobal;
// @0x140140840
template <> const TFunc_Instances_fl_display_DisplayObject_local3DToGlobal::TMethod TFunc_Instances_fl_display_DisplayObject_local3DToGlobal::Method = &Instances::fl_display::DisplayObject::local3DToGlobal;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 11, const Value, Value::Number> TFunc_Instances_fl_display_DisplayObject_heightSet;
// @0x140140870
template <> const TFunc_Instances_fl_display_DisplayObject_heightSet::TMethod TFunc_Instances_fl_display_DisplayObject_heightSet::Method = &Instances::fl_display::DisplayObject::heightSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObject, 14, const Value, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_DisplayObject_maskSet;
// @0x1401408a0
template <> const TFunc_Instances_fl_display_DisplayObject_maskSet::TMethod TFunc_Instances_fl_display_DisplayObject_maskSet::Method = &Instances::fl_display::DisplayObject::maskSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 1, const Value, bool> TFunc_Instances_fl_display_DisplayObjectContainer_mouseChildrenSet;
// @0x1401408d0
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_mouseChildrenSet::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_mouseChildrenSet::Method = &Instances::fl_display::DisplayObjectContainer::mouseChildrenSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 4, const Value, bool> TFunc_Instances_fl_display_DisplayObjectContainer_tabChildrenSet;
// @0x140140900
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_tabChildrenSet::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_tabChildrenSet::Method = &Instances::fl_display::DisplayObjectContainer::tabChildrenSet;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 6, SPtr<Instances::fl_display::DisplayObject>, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_DisplayObjectContainer_addChild;
// @0x140140930
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_addChild::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_addChild::Method = &Instances::fl_display::DisplayObjectContainer::addChild;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 8, bool, Instances::fl_geom::Point*> TFunc_Instances_fl_display_DisplayObjectContainer_areInaccessibleObjectsUnderPoint;
// @0x140140960
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_areInaccessibleObjectsUnderPoint::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_areInaccessibleObjectsUnderPoint::Method = &Instances::fl_display::DisplayObjectContainer::areInaccessibleObjectsUnderPoint;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 9, bool, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_DisplayObjectContainer_contains;
// @0x140140990
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_contains::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_contains::Method = &Instances::fl_display::DisplayObjectContainer::contains;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 10, SPtr<Instances::fl_display::DisplayObject>, SInt32> TFunc_Instances_fl_display_DisplayObjectContainer_getChildAt;
// @0x1401409c0
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_getChildAt::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_getChildAt::Method = &Instances::fl_display::DisplayObjectContainer::getChildAt;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 11, SPtr<Instances::fl_display::DisplayObject>, const ASString&> TFunc_Instances_fl_display_DisplayObjectContainer_getChildByName;
// @0x1401409f0
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_getChildByName::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_getChildByName::Method = &Instances::fl_display::DisplayObjectContainer::getChildByName;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 12, SInt32, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_DisplayObjectContainer_getChildIndex;
// @0x140140a20
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_getChildIndex::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_getChildIndex::Method = &Instances::fl_display::DisplayObjectContainer::getChildIndex;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 13, SPtr<Instances::fl::Array>, Instances::fl_geom::Point*> TFunc_Instances_fl_display_DisplayObjectContainer_getObjectsUnderPoint;
// @0x140140a50
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_getObjectsUnderPoint::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_getObjectsUnderPoint::Method = &Instances::fl_display::DisplayObjectContainer::getObjectsUnderPoint;
typedef ThunkFunc1<Instances::fl_display::DisplayObjectContainer, 15, SPtr<Instances::fl_display::DisplayObject>, SInt32> TFunc_Instances_fl_display_DisplayObjectContainer_removeChildAt;
// @0x140140a80
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_removeChildAt::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_removeChildAt::Method = &Instances::fl_display::DisplayObjectContainer::removeChildAt;
typedef ThunkFunc1<Instances::fl_display::InteractiveObject, 1, const Value, const Value&> TFunc_Instances_fl_display_InteractiveObject_contextMenuSet;
// @0x140140ab0
template <> const TFunc_Instances_fl_display_InteractiveObject_contextMenuSet::TMethod TFunc_Instances_fl_display_InteractiveObject_contextMenuSet::Method = &Instances::fl_display::InteractiveObject::contextMenuSet;
typedef ThunkFunc1<Instances::fl_display::InteractiveObject, 3, const Value, bool> TFunc_Instances_fl_display_InteractiveObject_doubleClickEnabledSet;
// @0x140140ae0
template <> const TFunc_Instances_fl_display_InteractiveObject_doubleClickEnabledSet::TMethod TFunc_Instances_fl_display_InteractiveObject_doubleClickEnabledSet::Method = &Instances::fl_display::InteractiveObject::doubleClickEnabledSet;
typedef ThunkFunc1<Instances::fl_display::InteractiveObject, 5, const Value, const Value&> TFunc_Instances_fl_display_InteractiveObject_focusRectSet;
// @0x140140b10
template <> const TFunc_Instances_fl_display_InteractiveObject_focusRectSet::TMethod TFunc_Instances_fl_display_InteractiveObject_focusRectSet::Method = &Instances::fl_display::InteractiveObject::focusRectSet;
typedef ThunkFunc1<Instances::fl_display::InteractiveObject, 7, const Value, bool> TFunc_Instances_fl_display_InteractiveObject_mouseEnabledSet;
// @0x140140b40
template <> const TFunc_Instances_fl_display_InteractiveObject_mouseEnabledSet::TMethod TFunc_Instances_fl_display_InteractiveObject_mouseEnabledSet::Method = &Instances::fl_display::InteractiveObject::mouseEnabledSet;
typedef ThunkFunc1<Instances::fl_display::InteractiveObject, 9, const Value, bool> TFunc_Instances_fl_display_InteractiveObject_tabEnabledSet;
// @0x140140b70
template <> const TFunc_Instances_fl_display_InteractiveObject_tabEnabledSet::TMethod TFunc_Instances_fl_display_InteractiveObject_tabEnabledSet::Method = &Instances::fl_display::InteractiveObject::tabEnabledSet;
typedef ThunkFunc1<Instances::fl_display::InteractiveObject, 11, const Value, SInt32> TFunc_Instances_fl_display_InteractiveObject_tabIndexSet;
// @0x140140ba0
template <> const TFunc_Instances_fl_display_InteractiveObject_tabIndexSet::TMethod TFunc_Instances_fl_display_InteractiveObject_tabIndexSet::Method = &Instances::fl_display::InteractiveObject::tabIndexSet;
typedef ThunkFunc1<Instances::fl_display::Loader, 6, const Value, bool> TFunc_Instances_fl_display_Loader_unloadAndStop;
// @0x140140bd0
template <> const TFunc_Instances_fl_display_Loader_unloadAndStop::TMethod TFunc_Instances_fl_display_Loader_unloadAndStop::Method = &Instances::fl_display::Loader::unloadAndStop;
typedef ThunkFunc1<Classes::fl_display::LoaderInfo, 0, SPtr<Instances::fl_display::LoaderInfo>, const Value&> TFunc_Classes_fl_display_LoaderInfo_getLoaderInfoByDefinition;
// @0x140140c00
template <> const TFunc_Classes_fl_display_LoaderInfo_getLoaderInfoByDefinition::TMethod TFunc_Classes_fl_display_LoaderInfo_getLoaderInfoByDefinition::Method = &Classes::fl_display::LoaderInfo::getLoaderInfoByDefinition;
typedef ThunkFunc1<Instances::fl_display::LoaderInfo, 7, const Value, const Value&> TFunc_Instances_fl_display_LoaderInfo_childSandboxBridgeSet;
// @0x140140c30
template <> const TFunc_Instances_fl_display_LoaderInfo_childSandboxBridgeSet::TMethod TFunc_Instances_fl_display_LoaderInfo_childSandboxBridgeSet::Method = &Instances::fl_display::LoaderInfo::childSandboxBridgeSet;
typedef ThunkFunc1<Instances::fl_display::LoaderInfo, 17, const Value, const Value&> TFunc_Instances_fl_display_LoaderInfo_parentSandboxBridgeSet;
// @0x140140c60
template <> const TFunc_Instances_fl_display_LoaderInfo_parentSandboxBridgeSet::TMethod TFunc_Instances_fl_display_LoaderInfo_parentSandboxBridgeSet::Method = &Instances::fl_display::LoaderInfo::parentSandboxBridgeSet;
typedef ThunkFunc1<Instances::fl_display::MovieClip, 6, const Value, bool> TFunc_Instances_fl_display_MovieClip_enabledSet;
// @0x140140c90
template <> const TFunc_Instances_fl_display_MovieClip_enabledSet::TMethod TFunc_Instances_fl_display_MovieClip_enabledSet::Method = &Instances::fl_display::MovieClip::enabledSet;
typedef ThunkFunc1<Instances::fl_display::MovieClip, 11, const Value, bool> TFunc_Instances_fl_display_MovieClip_trackAsMenuSet;
// @0x140140cc0
template <> const TFunc_Instances_fl_display_MovieClip_trackAsMenuSet::TMethod TFunc_Instances_fl_display_MovieClip_trackAsMenuSet::Method = &Instances::fl_display::MovieClip::trackAsMenuSet;
typedef ThunkFunc1<Instances::fl_display::SimpleButton, 1, const Value, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_SimpleButton_downStateSet;
// @0x140140cf0
template <> const TFunc_Instances_fl_display_SimpleButton_downStateSet::TMethod TFunc_Instances_fl_display_SimpleButton_downStateSet::Method = &Instances::fl_display::SimpleButton::downStateSet;
typedef ThunkFunc1<Instances::fl_display::SimpleButton, 3, const Value, bool> TFunc_Instances_fl_display_SimpleButton_enabledSet;
// @0x140140d20
template <> const TFunc_Instances_fl_display_SimpleButton_enabledSet::TMethod TFunc_Instances_fl_display_SimpleButton_enabledSet::Method = &Instances::fl_display::SimpleButton::enabledSet;
typedef ThunkFunc1<Instances::fl_display::SimpleButton, 5, const Value, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_SimpleButton_hitTestStateSet;
// @0x140140d50
template <> const TFunc_Instances_fl_display_SimpleButton_hitTestStateSet::TMethod TFunc_Instances_fl_display_SimpleButton_hitTestStateSet::Method = &Instances::fl_display::SimpleButton::hitTestStateSet;
typedef ThunkFunc1<Instances::fl_display::SimpleButton, 7, const Value, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_SimpleButton_overStateSet;
// @0x140140d80
template <> const TFunc_Instances_fl_display_SimpleButton_overStateSet::TMethod TFunc_Instances_fl_display_SimpleButton_overStateSet::Method = &Instances::fl_display::SimpleButton::overStateSet;
typedef ThunkFunc1<Instances::fl_display::SimpleButton, 9, const Value, Instances::fl_media::SoundTransform*> TFunc_Instances_fl_display_SimpleButton_soundTransformSet;
// @0x140140db0
template <> const TFunc_Instances_fl_display_SimpleButton_soundTransformSet::TMethod TFunc_Instances_fl_display_SimpleButton_soundTransformSet::Method = &Instances::fl_display::SimpleButton::soundTransformSet;
typedef ThunkFunc1<Instances::fl_display::SimpleButton, 11, const Value, bool> TFunc_Instances_fl_display_SimpleButton_trackAsMenuSet;
// @0x140140de0
template <> const TFunc_Instances_fl_display_SimpleButton_trackAsMenuSet::TMethod TFunc_Instances_fl_display_SimpleButton_trackAsMenuSet::Method = &Instances::fl_display::SimpleButton::trackAsMenuSet;
typedef ThunkFunc1<Instances::fl_display::SimpleButton, 13, const Value, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_SimpleButton_upStateSet;
// @0x140140e10
template <> const TFunc_Instances_fl_display_SimpleButton_upStateSet::TMethod TFunc_Instances_fl_display_SimpleButton_upStateSet::Method = &Instances::fl_display::SimpleButton::upStateSet;
typedef ThunkFunc1<Instances::fl_display::SimpleButton, 15, const Value, bool> TFunc_Instances_fl_display_SimpleButton_useHandCursorSet;
// @0x140140e40
template <> const TFunc_Instances_fl_display_SimpleButton_useHandCursorSet::TMethod TFunc_Instances_fl_display_SimpleButton_useHandCursorSet::Method = &Instances::fl_display::SimpleButton::useHandCursorSet;
typedef ThunkFunc1<Instances::fl_display::Sprite, 1, const Value, bool> TFunc_Instances_fl_display_Sprite_buttonModeSet;
// @0x140140e70
template <> const TFunc_Instances_fl_display_Sprite_buttonModeSet::TMethod TFunc_Instances_fl_display_Sprite_buttonModeSet::Method = &Instances::fl_display::Sprite::buttonModeSet;
typedef ThunkFunc1<Instances::fl_display::Sprite, 5, const Value, Instances::fl_display::Sprite*> TFunc_Instances_fl_display_Sprite_hitAreaSet;
// @0x140140ea0
template <> const TFunc_Instances_fl_display_Sprite_hitAreaSet::TMethod TFunc_Instances_fl_display_Sprite_hitAreaSet::Method = &Instances::fl_display::Sprite::hitAreaSet;
typedef ThunkFunc1<Instances::fl_display::Sprite, 7, const Value, Instances::fl_media::SoundTransform*> TFunc_Instances_fl_display_Sprite_soundTransformSet;
// @0x140140ed0
template <> const TFunc_Instances_fl_display_Sprite_soundTransformSet::TMethod TFunc_Instances_fl_display_Sprite_soundTransformSet::Method = &Instances::fl_display::Sprite::soundTransformSet;
typedef ThunkFunc1<Instances::fl_display::Sprite, 9, const Value, bool> TFunc_Instances_fl_display_Sprite_useHandCursorSet;
// @0x140140f00
template <> const TFunc_Instances_fl_display_Sprite_useHandCursorSet::TMethod TFunc_Instances_fl_display_Sprite_useHandCursorSet::Method = &Instances::fl_display::Sprite::useHandCursorSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 1, const Value, const ASString&> TFunc_Instances_fl_display_Stage_alignSet;
// @0x140140f30
template <> const TFunc_Instances_fl_display_Stage_alignSet::TMethod TFunc_Instances_fl_display_Stage_alignSet::Method = &Instances::fl_display::Stage::alignSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 5, const Value, const ASString&> TFunc_Instances_fl_display_Stage_displayStateSet;
// @0x140140f60
template <> const TFunc_Instances_fl_display_Stage_displayStateSet::TMethod TFunc_Instances_fl_display_Stage_displayStateSet::Method = &Instances::fl_display::Stage::displayStateSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 7, const Value, Instances::fl_display::InteractiveObject*> TFunc_Instances_fl_display_Stage_focusSet;
// @0x140140f90
template <> const TFunc_Instances_fl_display_Stage_focusSet::TMethod TFunc_Instances_fl_display_Stage_focusSet::Method = &Instances::fl_display::Stage::focusSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 9, const Value, Value::Number> TFunc_Instances_fl_display_Stage_frameRateSet;
// @0x140140fc0
template <> const TFunc_Instances_fl_display_Stage_frameRateSet::TMethod TFunc_Instances_fl_display_Stage_frameRateSet::Method = &Instances::fl_display::Stage::frameRateSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 17, const Value, bool> TFunc_Instances_fl_display_Stage_mouseChildrenSet;
// @0x140140ff0
template <> const TFunc_Instances_fl_display_Stage_mouseChildrenSet::TMethod TFunc_Instances_fl_display_Stage_mouseChildrenSet::Method = &Instances::fl_display::Stage::mouseChildrenSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 21, const Value, const ASString&> TFunc_Instances_fl_display_Stage_qualitySet;
// @0x140141020
template <> const TFunc_Instances_fl_display_Stage_qualitySet::TMethod TFunc_Instances_fl_display_Stage_qualitySet::Method = &Instances::fl_display::Stage::qualitySet;
typedef ThunkFunc1<Instances::fl_display::Stage, 23, const Value, const ASString&> TFunc_Instances_fl_display_Stage_scaleModeSet;
// @0x140141050
template <> const TFunc_Instances_fl_display_Stage_scaleModeSet::TMethod TFunc_Instances_fl_display_Stage_scaleModeSet::Method = &Instances::fl_display::Stage::scaleModeSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 25, const Value, bool> TFunc_Instances_fl_display_Stage_showDefaultContextMenuSet;
// @0x140141080
template <> const TFunc_Instances_fl_display_Stage_showDefaultContextMenuSet::TMethod TFunc_Instances_fl_display_Stage_showDefaultContextMenuSet::Method = &Instances::fl_display::Stage::showDefaultContextMenuSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 27, const Value, bool> TFunc_Instances_fl_display_Stage_stageFocusRectSet;
// @0x1401410b0
template <> const TFunc_Instances_fl_display_Stage_stageFocusRectSet::TMethod TFunc_Instances_fl_display_Stage_stageFocusRectSet::Method = &Instances::fl_display::Stage::stageFocusRectSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 29, const Value, SInt32> TFunc_Instances_fl_display_Stage_stageHeightSet;
// @0x1401410e0
template <> const TFunc_Instances_fl_display_Stage_stageHeightSet::TMethod TFunc_Instances_fl_display_Stage_stageHeightSet::Method = &Instances::fl_display::Stage::stageHeightSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 31, const Value, SInt32> TFunc_Instances_fl_display_Stage_stageWidthSet;
// @0x140141110
template <> const TFunc_Instances_fl_display_Stage_stageWidthSet::TMethod TFunc_Instances_fl_display_Stage_stageWidthSet::Method = &Instances::fl_display::Stage::stageWidthSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 33, const Value, bool> TFunc_Instances_fl_display_Stage_tabChildrenSet;
// @0x140141140
template <> const TFunc_Instances_fl_display_Stage_tabChildrenSet::TMethod TFunc_Instances_fl_display_Stage_tabChildrenSet::Method = &Instances::fl_display::Stage::tabChildrenSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 36, const Value, Value::Number> TFunc_Instances_fl_display_Stage_widthSet;
// @0x140141170
template <> const TFunc_Instances_fl_display_Stage_widthSet::TMethod TFunc_Instances_fl_display_Stage_widthSet::Method = &Instances::fl_display::Stage::widthSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 37, SPtr<Instances::fl_display::DisplayObject>, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_Stage_addChild;
// @0x1401411a0
template <> const TFunc_Instances_fl_display_Stage_addChild::TMethod TFunc_Instances_fl_display_Stage_addChild::Method = &Instances::fl_display::Stage::addChild;
typedef ThunkFunc1<Instances::fl_display::Stage, 41, bool, Instances::fl_events::Event*> TFunc_Instances_fl_display_Stage_dispatchEvent;
// @0x1401411d0
template <> const TFunc_Instances_fl_display_Stage_dispatchEvent::TMethod TFunc_Instances_fl_display_Stage_dispatchEvent::Method = &Instances::fl_display::Stage::dispatchEvent;
typedef ThunkFunc1<Instances::fl_display::Stage, 42, bool, const ASString&> TFunc_Instances_fl_display_Stage_hasEventListener;
// @0x140141200
template <> const TFunc_Instances_fl_display_Stage_hasEventListener::TMethod TFunc_Instances_fl_display_Stage_hasEventListener::Method = &Instances::fl_display::Stage::hasEventListener;
typedef ThunkFunc1<Instances::fl_display::Stage, 45, SPtr<Instances::fl_display::DisplayObject>, SInt32> TFunc_Instances_fl_display_Stage_removeChildAt;
// @0x140141230
template <> const TFunc_Instances_fl_display_Stage_removeChildAt::TMethod TFunc_Instances_fl_display_Stage_removeChildAt::Method = &Instances::fl_display::Stage::removeChildAt;
typedef ThunkFunc1<Instances::fl_display::Stage, 48, const Value, const ASString&> TFunc_Instances_fl_display_Stage_setOrientation;
// @0x140141260
template <> const TFunc_Instances_fl_display_Stage_setOrientation::TMethod TFunc_Instances_fl_display_Stage_setOrientation::Method = &Instances::fl_display::Stage::setOrientation;
typedef ThunkFunc1<Instances::fl_display::Stage, 50, bool, const ASString&> TFunc_Instances_fl_display_Stage_willTrigger;
// @0x140141290
template <> const TFunc_Instances_fl_display_Stage_willTrigger::TMethod TFunc_Instances_fl_display_Stage_willTrigger::Method = &Instances::fl_display::Stage::willTrigger;
typedef ThunkFunc1<Instances::fl_display::Stage, 12, const Value, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_display_Stage_fullScreenSourceRectSet;
// @0x1401412c0
template <> const TFunc_Instances_fl_display_Stage_fullScreenSourceRectSet::TMethod TFunc_Instances_fl_display_Stage_fullScreenSourceRectSet::Method = &Instances::fl_display::Stage::fullScreenSourceRectSet;
typedef ThunkFunc1<Instances::fl_display::Stage, 15, const Value, Value::Number> TFunc_Instances_fl_display_Stage_heightSet;
// @0x1401412f0
template <> const TFunc_Instances_fl_display_Stage_heightSet::TMethod TFunc_Instances_fl_display_Stage_heightSet::Method = &Instances::fl_display::Stage::heightSet;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 6, const Value, Instances::fl_geom::Rectangle*, Instances::fl_geom::ColorTransform*> TFunc_Instances_fl_display_BitmapData_colorTransform;
// @0x140141320
template <> const TFunc_Instances_fl_display_BitmapData_colorTransform::TMethod TFunc_Instances_fl_display_BitmapData_colorTransform::Method = &Instances::fl_display::BitmapData::colorTransform;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 16, UInt32, SInt32, SInt32> TFunc_Instances_fl_display_BitmapData_getPixel;
// @0x140141350
template <> const TFunc_Instances_fl_display_BitmapData_getPixel::TMethod TFunc_Instances_fl_display_BitmapData_getPixel::Method = &Instances::fl_display::BitmapData::getPixel;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 17, UInt32, SInt32, SInt32> TFunc_Instances_fl_display_BitmapData_getPixel32;
// @0x140141380
template <> const TFunc_Instances_fl_display_BitmapData_getPixel32::TMethod TFunc_Instances_fl_display_BitmapData_getPixel32::Method = &Instances::fl_display::BitmapData::getPixel32;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 23, Value, unsigned, const Value*> TFunc_Instances_fl_display_BitmapData_merge;
// @0x1401413b0
template <> const TFunc_Instances_fl_display_BitmapData_merge::TMethod TFunc_Instances_fl_display_BitmapData_merge::Method = &Instances::fl_display::BitmapData::merge;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 25, Value, unsigned, const Value*> TFunc_Instances_fl_display_BitmapData_paletteMap;
// @0x1401413e0
template <> const TFunc_Instances_fl_display_BitmapData_paletteMap::TMethod TFunc_Instances_fl_display_BitmapData_paletteMap::Method = &Instances::fl_display::BitmapData::paletteMap;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 26, Value, unsigned, const Value*> TFunc_Instances_fl_display_BitmapData_perlinNoise;
// @0x140141410
template <> const TFunc_Instances_fl_display_BitmapData_perlinNoise::TMethod TFunc_Instances_fl_display_BitmapData_perlinNoise::Method = &Instances::fl_display::BitmapData::perlinNoise;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 28, const Value, SInt32, SInt32> TFunc_Instances_fl_display_BitmapData_scroll;
// @0x140141440
template <> const TFunc_Instances_fl_display_BitmapData_scroll::TMethod TFunc_Instances_fl_display_BitmapData_scroll::Method = &Instances::fl_display::BitmapData::scroll;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 31, const Value, Instances::fl_geom::Rectangle*, Instances::fl_utils::ByteArray*> TFunc_Instances_fl_display_BitmapData_setPixels;
// @0x140141470
template <> const TFunc_Instances_fl_display_BitmapData_setPixels::TMethod TFunc_Instances_fl_display_BitmapData_setPixels::Method = &Instances::fl_display::BitmapData::setPixels;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 32, const Value, Instances::fl_geom::Rectangle*, Instances::fl_vec::Vector_uint*> TFunc_Instances_fl_display_BitmapData_setVector;
// @0x1401414a0
template <> const TFunc_Instances_fl_display_BitmapData_setVector::TMethod TFunc_Instances_fl_display_BitmapData_setVector::Method = &Instances::fl_display::BitmapData::setVector;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 33, Value, unsigned, const Value*> TFunc_Instances_fl_display_BitmapData_threshold;
// @0x1401414d0
template <> const TFunc_Instances_fl_display_BitmapData_threshold::TMethod TFunc_Instances_fl_display_BitmapData_threshold::Method = &Instances::fl_display::BitmapData::threshold;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 12, const Value, Instances::fl_geom::Rectangle*, UInt32> TFunc_Instances_fl_display_BitmapData_fillRect;
// @0x140141500
template <> const TFunc_Instances_fl_display_BitmapData_fillRect::TMethod TFunc_Instances_fl_display_BitmapData_fillRect::Method = &Instances::fl_display::BitmapData::fillRect;
typedef ThunkFunc2<Instances::fl_display::BitmapData, 14, SPtr<Instances::fl_geom::Rectangle>, Instances::fl_geom::Rectangle*, Instances::fl_filters::BitmapFilter*> TFunc_Instances_fl_display_BitmapData_generateFilterRect;
// @0x140141530
template <> const TFunc_Instances_fl_display_BitmapData_generateFilterRect::TMethod TFunc_Instances_fl_display_BitmapData_generateFilterRect::Method = &Instances::fl_display::BitmapData::generateFilterRect;
typedef ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 7, SPtr<Instances::fl_display::DisplayObject>, Instances::fl_display::DisplayObject*, SInt32> TFunc_Instances_fl_display_DisplayObjectContainer_addChildAt;
// @0x140141560
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_addChildAt::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_addChildAt::Method = &Instances::fl_display::DisplayObjectContainer::addChildAt;
typedef ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 16, const Value, Instances::fl_display::DisplayObject*, SInt32> TFunc_Instances_fl_display_DisplayObjectContainer_setChildIndex;
// @0x140141590
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_setChildIndex::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_setChildIndex::Method = &Instances::fl_display::DisplayObjectContainer::setChildIndex;
typedef ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 17, const Value, Instances::fl_display::DisplayObject*, Instances::fl_display::DisplayObject*> TFunc_Instances_fl_display_DisplayObjectContainer_swapChildren;
// @0x1401415c0
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_swapChildren::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_swapChildren::Method = &Instances::fl_display::DisplayObjectContainer::swapChildren;
typedef ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 18, const Value, SInt32, SInt32> TFunc_Instances_fl_display_DisplayObjectContainer_swapChildrenAt;
// @0x1401415f0
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_swapChildrenAt::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_swapChildrenAt::Method = &Instances::fl_display::DisplayObjectContainer::swapChildrenAt;
typedef ThunkFunc2<Instances::fl_display::DisplayObjectContainer, 14, Value, unsigned, const Value*> TFunc_Instances_fl_display_DisplayObjectContainer_removeChild;
// @0x140141620
template <> const TFunc_Instances_fl_display_DisplayObjectContainer_removeChild::TMethod TFunc_Instances_fl_display_DisplayObjectContainer_removeChild::Method = &Instances::fl_display::DisplayObjectContainer::removeChild;
typedef ThunkFunc2<Instances::fl_display::Graphics, 1, const Value, UInt32, Value::Number> TFunc_Instances_fl_display_Graphics_beginFill;
// @0x140141650
template <> const TFunc_Instances_fl_display_Graphics_beginFill::TMethod TFunc_Instances_fl_display_Graphics_beginFill::Method = &Instances::fl_display::Graphics::beginFill;
typedef ThunkFunc2<Instances::fl_display::Graphics, 2, Value, unsigned, const Value*> TFunc_Instances_fl_display_Graphics_beginGradientFill;
// @0x140141680
template <> const TFunc_Instances_fl_display_Graphics_beginGradientFill::TMethod TFunc_Instances_fl_display_Graphics_beginGradientFill::Method = &Instances::fl_display::Graphics::beginGradientFill;
typedef ThunkFunc2<Instances::fl_display::Graphics, 9, Value, unsigned, const Value*> TFunc_Instances_fl_display_Graphics_drawRoundRectComplex;
// @0x1401416b0
template <> const TFunc_Instances_fl_display_Graphics_drawRoundRectComplex::TMethod TFunc_Instances_fl_display_Graphics_drawRoundRectComplex::Method = &Instances::fl_display::Graphics::drawRoundRectComplex;
typedef ThunkFunc2<Instances::fl_display::Graphics, 11, Value, unsigned, const Value*> TFunc_Instances_fl_display_Graphics_lineGradientStyle;
// @0x1401416e0
template <> const TFunc_Instances_fl_display_Graphics_lineGradientStyle::TMethod TFunc_Instances_fl_display_Graphics_lineGradientStyle::Method = &Instances::fl_display::Graphics::lineGradientStyle;
typedef ThunkFunc2<Instances::fl_display::Graphics, 12, Value, unsigned, const Value*> TFunc_Instances_fl_display_Graphics_lineStyle;
// @0x140141710
template <> const TFunc_Instances_fl_display_Graphics_lineStyle::TMethod TFunc_Instances_fl_display_Graphics_lineStyle::Method = &Instances::fl_display::Graphics::lineStyle;
typedef ThunkFunc2<Instances::fl_display::Graphics, 13, const Value, Value::Number, Value::Number> TFunc_Instances_fl_display_Graphics_lineTo;
// @0x140141740
template <> const TFunc_Instances_fl_display_Graphics_lineTo::TMethod TFunc_Instances_fl_display_Graphics_lineTo::Method = &Instances::fl_display::Graphics::lineTo;
typedef ThunkFunc2<Instances::fl_display::Graphics, 14, const Value, Value::Number, Value::Number> TFunc_Instances_fl_display_Graphics_moveTo;
// @0x140141770
template <> const TFunc_Instances_fl_display_Graphics_moveTo::TMethod TFunc_Instances_fl_display_Graphics_moveTo::Method = &Instances::fl_display::Graphics::moveTo;
typedef ThunkFunc2<Instances::fl_display::Loader, 3, const Value, Instances::fl_net::URLRequest*, Instances::fl_system::LoaderContext*> TFunc_Instances_fl_display_Loader_load;
// @0x1401417a0
template <> const TFunc_Instances_fl_display_Loader_load::TMethod TFunc_Instances_fl_display_Loader_load::Method = &Instances::fl_display::Loader::load;
typedef ThunkFunc2<Instances::fl_display::Loader, 4, const Value, Instances::fl_utils::ByteArray*, Instances::fl_system::LoaderContext*> TFunc_Instances_fl_display_Loader_loadBytes;
// @0x1401417d0
template <> const TFunc_Instances_fl_display_Loader_loadBytes::TMethod TFunc_Instances_fl_display_Loader_loadBytes::Method = &Instances::fl_display::Loader::loadBytes;
typedef ThunkFunc2<Instances::fl_display::MovieClip, 12, Value, unsigned, const Value*> TFunc_Instances_fl_display_MovieClip_addFrameScript;
// @0x140141800
template <> const TFunc_Instances_fl_display_MovieClip_addFrameScript::TMethod TFunc_Instances_fl_display_MovieClip_addFrameScript::Method = &Instances::fl_display::MovieClip::addFrameScript;
typedef ThunkFunc2<Instances::fl_display::MovieClip, 13, const Value, const Value&, const Value&> TFunc_Instances_fl_display_MovieClip_gotoAndPlay;
// @0x140141830
template <> const TFunc_Instances_fl_display_MovieClip_gotoAndPlay::TMethod TFunc_Instances_fl_display_MovieClip_gotoAndPlay::Method = &Instances::fl_display::MovieClip::gotoAndPlay;
typedef ThunkFunc2<Instances::fl_display::MovieClip, 14, const Value, const Value&, const Value&> TFunc_Instances_fl_display_MovieClip_gotoAndStop;
// @0x140141860
template <> const TFunc_Instances_fl_display_MovieClip_gotoAndStop::TMethod TFunc_Instances_fl_display_MovieClip_gotoAndStop::Method = &Instances::fl_display::MovieClip::gotoAndStop;
typedef ThunkFunc2<Instances::fl_display::Sprite, 10, const Value, bool, Instances::fl_geom::Rectangle*> TFunc_Instances_fl_display_Sprite_startDrag;
// @0x140141890
template <> const TFunc_Instances_fl_display_Sprite_startDrag::TMethod TFunc_Instances_fl_display_Sprite_startDrag::Method = &Instances::fl_display::Sprite::startDrag;
typedef ThunkFunc2<Instances::fl_display::Stage, 38, SPtr<Instances::fl_display::DisplayObject>, Instances::fl_display::DisplayObject*, SInt32> TFunc_Instances_fl_display_Stage_addChildAt;
// @0x1401418c0
template <> const TFunc_Instances_fl_display_Stage_addChildAt::TMethod TFunc_Instances_fl_display_Stage_addChildAt::Method = &Instances::fl_display::Stage::addChildAt;
typedef ThunkFunc2<Instances::fl_display::Stage, 40, const Value, Instances::fl_display::InteractiveObject*, const ASString&> TFunc_Instances_fl_display_Stage_assignFocus;
// @0x1401418f0
template <> const TFunc_Instances_fl_display_Stage_assignFocus::TMethod TFunc_Instances_fl_display_Stage_assignFocus::Method = &Instances::fl_display::Stage::assignFocus;
typedef ThunkFunc2<Instances::fl_display::Stage, 47, const Value, Instances::fl_display::DisplayObject*, SInt32> TFunc_Instances_fl_display_Stage_setChildIndex;
// @0x140141920
template <> const TFunc_Instances_fl_display_Stage_setChildIndex::TMethod TFunc_Instances_fl_display_Stage_setChildIndex::Method = &Instances::fl_display::Stage::setChildIndex;
typedef ThunkFunc2<Instances::fl_display::Stage, 49, const Value, SInt32, SInt32> TFunc_Instances_fl_display_Stage_swapChildrenAt;
// @0x140141950
template <> const TFunc_Instances_fl_display_Stage_swapChildrenAt::TMethod TFunc_Instances_fl_display_Stage_swapChildrenAt::Method = &Instances::fl_display::Stage::swapChildrenAt;
typedef ThunkFunc3<Instances::fl_display::BitmapData, 29, const Value, SInt32, SInt32, UInt32> TFunc_Instances_fl_display_BitmapData_setPixel;
// @0x140141980
template <> const TFunc_Instances_fl_display_BitmapData_setPixel::TMethod TFunc_Instances_fl_display_BitmapData_setPixel::Method = &Instances::fl_display::BitmapData::setPixel;
typedef ThunkFunc3<Instances::fl_display::BitmapData, 30, const Value, SInt32, SInt32, UInt32> TFunc_Instances_fl_display_BitmapData_setPixel32;
// @0x1401419b0
template <> const TFunc_Instances_fl_display_BitmapData_setPixel32::TMethod TFunc_Instances_fl_display_BitmapData_setPixel32::Method = &Instances::fl_display::BitmapData::setPixel32;
typedef ThunkFunc3<Instances::fl_display::BitmapData, 13, const Value, SInt32, SInt32, UInt32> TFunc_Instances_fl_display_BitmapData_floodFill;
// @0x1401419e0
template <> const TFunc_Instances_fl_display_BitmapData_floodFill::TMethod TFunc_Instances_fl_display_BitmapData_floodFill::Method = &Instances::fl_display::BitmapData::floodFill;
typedef ThunkFunc3<Instances::fl_display::BitmapData, 15, SPtr<Instances::fl_geom::Rectangle>, UInt32, UInt32, bool> TFunc_Instances_fl_display_BitmapData_getColorBoundsRect;
// @0x140141a10
template <> const TFunc_Instances_fl_display_BitmapData_getColorBoundsRect::TMethod TFunc_Instances_fl_display_BitmapData_getColorBoundsRect::Method = &Instances::fl_display::BitmapData::getColorBoundsRect;
typedef ThunkFunc3<Instances::fl_display::DisplayObject, 59, bool, Value::Number, Value::Number, bool> TFunc_Instances_fl_display_DisplayObject_hitTestPoint;
// @0x140141a40
template <> const TFunc_Instances_fl_display_DisplayObject_hitTestPoint::TMethod TFunc_Instances_fl_display_DisplayObject_hitTestPoint::Method = &Instances::fl_display::DisplayObject::hitTestPoint;
typedef ThunkFunc3<Instances::fl_display::Graphics, 5, const Value, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_display_Graphics_drawCircle;
// @0x140141a70
template <> const TFunc_Instances_fl_display_Graphics_drawCircle::TMethod TFunc_Instances_fl_display_Graphics_drawCircle::Method = &Instances::fl_display::Graphics::drawCircle;
typedef ThunkFunc3<Instances::fl_display::Stage, 46, const Value, const ASString&, const Value&, bool> TFunc_Instances_fl_display_Stage_removeEventListener;
// @0x140141aa0
template <> const TFunc_Instances_fl_display_Stage_removeEventListener::TMethod TFunc_Instances_fl_display_Stage_removeEventListener::Method = &Instances::fl_display::Stage::removeEventListener;
typedef ThunkFunc4<Instances::fl_display::BitmapData, 4, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, Instances::fl_filters::BitmapFilter*> TFunc_Instances_fl_display_BitmapData_applyFilter;
// @0x140141ad0
template <> const TFunc_Instances_fl_display_BitmapData_applyFilter::TMethod TFunc_Instances_fl_display_BitmapData_applyFilter::Method = &Instances::fl_display::BitmapData::applyFilter;
typedef ThunkFunc4<Instances::fl_display::Graphics, 4, const Value, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_display_Graphics_curveTo;
// @0x140141b00
template <> const TFunc_Instances_fl_display_Graphics_curveTo::TMethod TFunc_Instances_fl_display_Graphics_curveTo::Method = &Instances::fl_display::Graphics::curveTo;
typedef ThunkFunc4<Instances::fl_display::Graphics, 6, const Value, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_display_Graphics_drawEllipse;
// @0x140141b30
template <> const TFunc_Instances_fl_display_Graphics_drawEllipse::TMethod TFunc_Instances_fl_display_Graphics_drawEllipse::Method = &Instances::fl_display::Graphics::drawEllipse;
typedef ThunkFunc4<Instances::fl_display::Graphics, 7, const Value, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_display_Graphics_drawRect;
// @0x140141b60
template <> const TFunc_Instances_fl_display_Graphics_drawRect::TMethod TFunc_Instances_fl_display_Graphics_drawRect::Method = &Instances::fl_display::Graphics::drawRect;
typedef ThunkFunc4<Instances::fl_display::Graphics, 0, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Matrix*, bool, bool> TFunc_Instances_fl_display_Graphics_beginBitmapFill;
// @0x140141b90
template <> const TFunc_Instances_fl_display_Graphics_beginBitmapFill::TMethod TFunc_Instances_fl_display_Graphics_beginBitmapFill::Method = &Instances::fl_display::Graphics::beginBitmapFill;
typedef ThunkFunc5<Instances::fl_display::BitmapData, 8, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, UInt32, UInt32> TFunc_Instances_fl_display_BitmapData_copyChannel;
// @0x140141bc0
template <> const TFunc_Instances_fl_display_BitmapData_copyChannel::TMethod TFunc_Instances_fl_display_BitmapData_copyChannel::Method = &Instances::fl_display::BitmapData::copyChannel;
typedef ThunkFunc5<Instances::fl_display::BitmapData, 20, bool, Instances::fl_geom::Point*, UInt32, const Value&, Instances::fl_geom::Point*, UInt32> TFunc_Instances_fl_display_BitmapData_hitTest;
// @0x140141bf0
template <> const TFunc_Instances_fl_display_BitmapData_hitTest::TMethod TFunc_Instances_fl_display_BitmapData_hitTest::Method = &Instances::fl_display::BitmapData::hitTest;
typedef ThunkFunc5<Instances::fl_display::BitmapData, 24, const Value, SInt32, UInt32, UInt32, UInt32, bool> TFunc_Instances_fl_display_BitmapData_noise;
// @0x140141c20
template <> const TFunc_Instances_fl_display_BitmapData_noise::TMethod TFunc_Instances_fl_display_BitmapData_noise::Method = &Instances::fl_display::BitmapData::noise;
typedef ThunkFunc5<Instances::fl_display::Stage, 39, const Value, const ASString&, const Value&, bool, SInt32, bool> TFunc_Instances_fl_display_Stage_addEventListener;
// @0x140141c50
template <> const TFunc_Instances_fl_display_Stage_addEventListener::TMethod TFunc_Instances_fl_display_Stage_addEventListener::Method = &Instances::fl_display::Stage::addEventListener;
typedef ThunkFunc6<Instances::fl_display::BitmapData, 9, const Value, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, Instances::fl_display::BitmapData*, Instances::fl_geom::Point*, bool> TFunc_Instances_fl_display_BitmapData_copyPixels;
// @0x140141c80
template <> const TFunc_Instances_fl_display_BitmapData_copyPixels::TMethod TFunc_Instances_fl_display_BitmapData_copyPixels::Method = &Instances::fl_display::BitmapData::copyPixels;
typedef ThunkFunc6<Instances::fl_display::BitmapData, 27, SInt32, Instances::fl_display::BitmapData*, Instances::fl_geom::Rectangle*, Instances::fl_geom::Point*, SInt32, SInt32, UInt32> TFunc_Instances_fl_display_BitmapData_pixelDissolve;
// @0x140141cb0
template <> const TFunc_Instances_fl_display_BitmapData_pixelDissolve::TMethod TFunc_Instances_fl_display_BitmapData_pixelDissolve::Method = &Instances::fl_display::BitmapData::pixelDissolve;
typedef ThunkFunc6<Instances::fl_display::BitmapData, 11, const Value, Instances::fl::Object*, Instances::fl_geom::Matrix*, Instances::fl_geom::ColorTransform*, const ASString&, Instances::fl_geom::Rectangle*, bool> TFunc_Instances_fl_display_BitmapData_draw;
// @0x140141ce0
template <> const TFunc_Instances_fl_display_BitmapData_draw::TMethod TFunc_Instances_fl_display_BitmapData_draw::Method = &Instances::fl_display::BitmapData::draw;
typedef ThunkFunc6<Instances::fl_display::Graphics, 8, const Value, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_display_Graphics_drawRoundRect;
// @0x140141d10
template <> const TFunc_Instances_fl_display_Graphics_drawRoundRect::TMethod TFunc_Instances_fl_display_Graphics_drawRoundRect::Method = &Instances::fl_display::Graphics::drawRoundRect;
typedef ThunkFunc0<Instances::fl_events::AppLifecycleEvent, 1, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_AppLifecycleEvent_clone;
// @0x140141d40
template <> const TFunc_Instances_fl_events_AppLifecycleEvent_clone::TMethod TFunc_Instances_fl_events_AppLifecycleEvent_clone::Method = &Instances::fl_events::AppLifecycleEvent::clone;
typedef ThunkFunc0<Instances::fl_events::AppLifecycleEvent, 2, ASString> TFunc_Instances_fl_events_AppLifecycleEvent_toString;
// @0x140141d70
template <> const TFunc_Instances_fl_events_AppLifecycleEvent_toString::TMethod TFunc_Instances_fl_events_AppLifecycleEvent_toString::Method = &Instances::fl_events::AppLifecycleEvent::toString;
typedef ThunkFunc0<Instances::fl_events::AppLifecycleEvent, 0, SPtr<Instances::fl::Object>> TFunc_Instances_fl_events_AppLifecycleEvent_statusGet;
// @0x140141da0
template <> const TFunc_Instances_fl_events_AppLifecycleEvent_statusGet::TMethod TFunc_Instances_fl_events_AppLifecycleEvent_statusGet::Method = &Instances::fl_events::AppLifecycleEvent::statusGet;
typedef ThunkFunc0<Instances::fl_events::ErrorEvent, 1, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_ErrorEvent_clone;
// @0x140141dd0
template <> const TFunc_Instances_fl_events_ErrorEvent_clone::TMethod TFunc_Instances_fl_events_ErrorEvent_clone::Method = &Instances::fl_events::ErrorEvent::clone;
typedef ThunkFunc0<Instances::fl_events::ErrorEvent, 2, ASString> TFunc_Instances_fl_events_ErrorEvent_toString;
// @0x140141e00
template <> const TFunc_Instances_fl_events_ErrorEvent_toString::TMethod TFunc_Instances_fl_events_ErrorEvent_toString::Method = &Instances::fl_events::ErrorEvent::toString;
typedef ThunkFunc0<Instances::fl_events::ErrorEvent, 0, SInt32> TFunc_Instances_fl_events_ErrorEvent_errorIDGet;
// @0x140141e30
template <> const TFunc_Instances_fl_events_ErrorEvent_errorIDGet::TMethod TFunc_Instances_fl_events_ErrorEvent_errorIDGet::Method = &Instances::fl_events::ErrorEvent::errorIDGet;
typedef ThunkFunc0<Instances::fl_events::Event, 1, bool> TFunc_Instances_fl_events_Event_cancelableGet;
// @0x140141e60
template <> const TFunc_Instances_fl_events_Event_cancelableGet::TMethod TFunc_Instances_fl_events_Event_cancelableGet::Method = &Instances::fl_events::Event::cancelableGet;
typedef ThunkFunc0<Instances::fl_events::Event, 2, SPtr<Instances::fl::Object>> TFunc_Instances_fl_events_Event_currentTargetGet;
// @0x140141e90
template <> const TFunc_Instances_fl_events_Event_currentTargetGet::TMethod TFunc_Instances_fl_events_Event_currentTargetGet::Method = &Instances::fl_events::Event::currentTargetGet;
typedef ThunkFunc0<Instances::fl_events::Event, 3, UInt32> TFunc_Instances_fl_events_Event_eventPhaseGet;
// @0x140141ec0
template <> const TFunc_Instances_fl_events_Event_eventPhaseGet::TMethod TFunc_Instances_fl_events_Event_eventPhaseGet::Method = &Instances::fl_events::Event::eventPhaseGet;
typedef ThunkFunc0<Instances::fl_events::Event, 4, SPtr<Instances::fl::Object>> TFunc_Instances_fl_events_Event_targetGet;
// @0x140141ef0
template <> const TFunc_Instances_fl_events_Event_targetGet::TMethod TFunc_Instances_fl_events_Event_targetGet::Method = &Instances::fl_events::Event::targetGet;
typedef ThunkFunc0<Instances::fl_events::Event, 5, ASString> TFunc_Instances_fl_events_Event_typeGet;
// @0x140141f20
template <> const TFunc_Instances_fl_events_Event_typeGet::TMethod TFunc_Instances_fl_events_Event_typeGet::Method = &Instances::fl_events::Event::typeGet;
typedef ThunkFunc0<Instances::fl_events::Event, 6, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_Event_clone;
// @0x140141f50
template <> const TFunc_Instances_fl_events_Event_clone::TMethod TFunc_Instances_fl_events_Event_clone::Method = &Instances::fl_events::Event::clone;
typedef ThunkFunc0<Instances::fl_events::Event, 8, bool> TFunc_Instances_fl_events_Event_isDefaultPrevented;
// @0x140141f80
template <> const TFunc_Instances_fl_events_Event_isDefaultPrevented::TMethod TFunc_Instances_fl_events_Event_isDefaultPrevented::Method = &Instances::fl_events::Event::isDefaultPrevented;
typedef ThunkFunc0<Instances::fl_events::Event, 9, const Value> TFunc_Instances_fl_events_Event_preventDefault;
// @0x140141fb0
template <> const TFunc_Instances_fl_events_Event_preventDefault::TMethod TFunc_Instances_fl_events_Event_preventDefault::Method = &Instances::fl_events::Event::preventDefault;
typedef ThunkFunc0<Instances::fl_events::Event, 10, const Value> TFunc_Instances_fl_events_Event_stopImmediatePropagation;
// @0x140141fe0
template <> const TFunc_Instances_fl_events_Event_stopImmediatePropagation::TMethod TFunc_Instances_fl_events_Event_stopImmediatePropagation::Method = &Instances::fl_events::Event::stopImmediatePropagation;
typedef ThunkFunc0<Instances::fl_events::Event, 0, bool> TFunc_Instances_fl_events_Event_bubblesGet;
// @0x140142010
template <> const TFunc_Instances_fl_events_Event_bubblesGet::TMethod TFunc_Instances_fl_events_Event_bubblesGet::Method = &Instances::fl_events::Event::bubblesGet;
typedef ThunkFunc0<Instances::fl_events::Event, 11, const Value> TFunc_Instances_fl_events_Event_stopPropagation;
// @0x140142040
template <> const TFunc_Instances_fl_events_Event_stopPropagation::TMethod TFunc_Instances_fl_events_Event_stopPropagation::Method = &Instances::fl_events::Event::stopPropagation;
typedef ThunkFunc0<Instances::fl_events::Event, 12, ASString> TFunc_Instances_fl_events_Event_toString;
// @0x140142070
template <> const TFunc_Instances_fl_events_Event_toString::TMethod TFunc_Instances_fl_events_Event_toString::Method = &Instances::fl_events::Event::toString;
typedef ThunkFunc0<Instances::fl_events::FocusEvent, 2, UInt32> TFunc_Instances_fl_events_FocusEvent_keyCodeGet;
// @0x1401420a0
template <> const TFunc_Instances_fl_events_FocusEvent_keyCodeGet::TMethod TFunc_Instances_fl_events_FocusEvent_keyCodeGet::Method = &Instances::fl_events::FocusEvent::keyCodeGet;
typedef ThunkFunc0<Instances::fl_events::FocusEvent, 4, SPtr<Instances::fl_display::InteractiveObject>> TFunc_Instances_fl_events_FocusEvent_relatedObjectGet;
// @0x1401420d0
template <> const TFunc_Instances_fl_events_FocusEvent_relatedObjectGet::TMethod TFunc_Instances_fl_events_FocusEvent_relatedObjectGet::Method = &Instances::fl_events::FocusEvent::relatedObjectGet;
typedef ThunkFunc0<Instances::fl_events::FocusEvent, 6, bool> TFunc_Instances_fl_events_FocusEvent_shiftKeyGet;
// @0x140142100
template <> const TFunc_Instances_fl_events_FocusEvent_shiftKeyGet::TMethod TFunc_Instances_fl_events_FocusEvent_shiftKeyGet::Method = &Instances::fl_events::FocusEvent::shiftKeyGet;
typedef ThunkFunc0<Instances::fl_events::FocusEvent, 8, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_FocusEvent_clone;
// @0x140142130
template <> const TFunc_Instances_fl_events_FocusEvent_clone::TMethod TFunc_Instances_fl_events_FocusEvent_clone::Method = &Instances::fl_events::FocusEvent::clone;
typedef ThunkFunc0<Instances::fl_events::FocusEvent, 9, ASString> TFunc_Instances_fl_events_FocusEvent_toString;
// @0x140142160
template <> const TFunc_Instances_fl_events_FocusEvent_toString::TMethod TFunc_Instances_fl_events_FocusEvent_toString::Method = &Instances::fl_events::FocusEvent::toString;
typedef ThunkFunc0<Instances::fl_events::FocusEvent, 0, ASString> TFunc_Instances_fl_events_FocusEvent_directionGet;
// @0x140142190
template <> const TFunc_Instances_fl_events_FocusEvent_directionGet::TMethod TFunc_Instances_fl_events_FocusEvent_directionGet::Method = &Instances::fl_events::FocusEvent::directionGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 2, bool> TFunc_Instances_fl_events_GestureEvent_commandKeyGet;
// @0x1401421c0
template <> const TFunc_Instances_fl_events_GestureEvent_commandKeyGet::TMethod TFunc_Instances_fl_events_GestureEvent_commandKeyGet::Method = &Instances::fl_events::GestureEvent::commandKeyGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 4, bool> TFunc_Instances_fl_events_GestureEvent_controlKeyGet;
// @0x1401421f0
template <> const TFunc_Instances_fl_events_GestureEvent_controlKeyGet::TMethod TFunc_Instances_fl_events_GestureEvent_controlKeyGet::Method = &Instances::fl_events::GestureEvent::controlKeyGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 6, bool> TFunc_Instances_fl_events_GestureEvent_ctrlKeyGet;
// @0x140142220
template <> const TFunc_Instances_fl_events_GestureEvent_ctrlKeyGet::TMethod TFunc_Instances_fl_events_GestureEvent_ctrlKeyGet::Method = &Instances::fl_events::GestureEvent::ctrlKeyGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 8, Value::Number> TFunc_Instances_fl_events_GestureEvent_localXGet;
// @0x140142250
template <> const TFunc_Instances_fl_events_GestureEvent_localXGet::TMethod TFunc_Instances_fl_events_GestureEvent_localXGet::Method = &Instances::fl_events::GestureEvent::localXGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 10, Value::Number> TFunc_Instances_fl_events_GestureEvent_localYGet;
// @0x140142280
template <> const TFunc_Instances_fl_events_GestureEvent_localYGet::TMethod TFunc_Instances_fl_events_GestureEvent_localYGet::Method = &Instances::fl_events::GestureEvent::localYGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 0, bool> TFunc_Instances_fl_events_GestureEvent_altKeyGet;
// @0x1401422b0
template <> const TFunc_Instances_fl_events_GestureEvent_altKeyGet::TMethod TFunc_Instances_fl_events_GestureEvent_altKeyGet::Method = &Instances::fl_events::GestureEvent::altKeyGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 16, Value::Number> TFunc_Instances_fl_events_GestureEvent_stageXGet;
// @0x1401422e0
template <> const TFunc_Instances_fl_events_GestureEvent_stageXGet::TMethod TFunc_Instances_fl_events_GestureEvent_stageXGet::Method = &Instances::fl_events::GestureEvent::stageXGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 17, Value::Number> TFunc_Instances_fl_events_GestureEvent_stageYGet;
// @0x140142310
template <> const TFunc_Instances_fl_events_GestureEvent_stageYGet::TMethod TFunc_Instances_fl_events_GestureEvent_stageYGet::Method = &Instances::fl_events::GestureEvent::stageYGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 18, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_GestureEvent_clone;
// @0x140142340
template <> const TFunc_Instances_fl_events_GestureEvent_clone::TMethod TFunc_Instances_fl_events_GestureEvent_clone::Method = &Instances::fl_events::GestureEvent::clone;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 19, ASString> TFunc_Instances_fl_events_GestureEvent_toString;
// @0x140142370
template <> const TFunc_Instances_fl_events_GestureEvent_toString::TMethod TFunc_Instances_fl_events_GestureEvent_toString::Method = &Instances::fl_events::GestureEvent::toString;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 20, const Value> TFunc_Instances_fl_events_GestureEvent_updateAfterEvent;
// @0x1401423a0
template <> const TFunc_Instances_fl_events_GestureEvent_updateAfterEvent::TMethod TFunc_Instances_fl_events_GestureEvent_updateAfterEvent::Method = &Instances::fl_events::GestureEvent::updateAfterEvent;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 12, ASString> TFunc_Instances_fl_events_GestureEvent_phaseGet;
// @0x1401423d0
template <> const TFunc_Instances_fl_events_GestureEvent_phaseGet::TMethod TFunc_Instances_fl_events_GestureEvent_phaseGet::Method = &Instances::fl_events::GestureEvent::phaseGet;
typedef ThunkFunc0<Instances::fl_events::GestureEvent, 14, bool> TFunc_Instances_fl_events_GestureEvent_shiftKeyGet;
// @0x140142400
template <> const TFunc_Instances_fl_events_GestureEvent_shiftKeyGet::TMethod TFunc_Instances_fl_events_GestureEvent_shiftKeyGet::Method = &Instances::fl_events::GestureEvent::shiftKeyGet;
typedef ThunkFunc0<Instances::fl_events::IMEEvent, 1, ASString> TFunc_Instances_fl_events_IMEEvent_toString;
// @0x140142430
template <> const TFunc_Instances_fl_events_IMEEvent_toString::TMethod TFunc_Instances_fl_events_IMEEvent_toString::Method = &Instances::fl_events::IMEEvent::toString;
typedef ThunkFunc0<Instances::fl_events::IMEEvent, 0, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_IMEEvent_clone;
// @0x140142460
template <> const TFunc_Instances_fl_events_IMEEvent_clone::TMethod TFunc_Instances_fl_events_IMEEvent_clone::Method = &Instances::fl_events::IMEEvent::clone;
typedef ThunkFunc0<Instances::fl_events::IOErrorEvent, 2, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_IOErrorEvent_clone;
// @0x140142490
template <> const TFunc_Instances_fl_events_IOErrorEvent_clone::TMethod TFunc_Instances_fl_events_IOErrorEvent_clone::Method = &Instances::fl_events::IOErrorEvent::clone;
typedef ThunkFunc0<Instances::fl_events::IOErrorEvent, 3, ASString> TFunc_Instances_fl_events_IOErrorEvent_toString;
// @0x1401424c0
template <> const TFunc_Instances_fl_events_IOErrorEvent_toString::TMethod TFunc_Instances_fl_events_IOErrorEvent_toString::Method = &Instances::fl_events::IOErrorEvent::toString;
typedef ThunkFunc0<Instances::fl_events::IOErrorEvent, 0, ASString> TFunc_Instances_fl_events_IOErrorEvent_textGet;
// @0x1401424f0
template <> const TFunc_Instances_fl_events_IOErrorEvent_textGet::TMethod TFunc_Instances_fl_events_IOErrorEvent_textGet::Method = &Instances::fl_events::IOErrorEvent::textGet;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 2, UInt32> TFunc_Instances_fl_events_KeyboardEvent_charCodeGet;
// @0x140142520
template <> const TFunc_Instances_fl_events_KeyboardEvent_charCodeGet::TMethod TFunc_Instances_fl_events_KeyboardEvent_charCodeGet::Method = &Instances::fl_events::KeyboardEvent::charCodeGet;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 4, bool> TFunc_Instances_fl_events_KeyboardEvent_commandKeyGet;
// @0x140142550
template <> const TFunc_Instances_fl_events_KeyboardEvent_commandKeyGet::TMethod TFunc_Instances_fl_events_KeyboardEvent_commandKeyGet::Method = &Instances::fl_events::KeyboardEvent::commandKeyGet;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 6, bool> TFunc_Instances_fl_events_KeyboardEvent_controlKeyGet;
// @0x140142580
template <> const TFunc_Instances_fl_events_KeyboardEvent_controlKeyGet::TMethod TFunc_Instances_fl_events_KeyboardEvent_controlKeyGet::Method = &Instances::fl_events::KeyboardEvent::controlKeyGet;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 8, bool> TFunc_Instances_fl_events_KeyboardEvent_ctrlKeyGet;
// @0x1401425b0
template <> const TFunc_Instances_fl_events_KeyboardEvent_ctrlKeyGet::TMethod TFunc_Instances_fl_events_KeyboardEvent_ctrlKeyGet::Method = &Instances::fl_events::KeyboardEvent::ctrlKeyGet;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 10, UInt32> TFunc_Instances_fl_events_KeyboardEvent_keyCodeGet;
// @0x1401425e0
template <> const TFunc_Instances_fl_events_KeyboardEvent_keyCodeGet::TMethod TFunc_Instances_fl_events_KeyboardEvent_keyCodeGet::Method = &Instances::fl_events::KeyboardEvent::keyCodeGet;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 0, bool> TFunc_Instances_fl_events_KeyboardEvent_altKeyGet;
// @0x140142610
template <> const TFunc_Instances_fl_events_KeyboardEvent_altKeyGet::TMethod TFunc_Instances_fl_events_KeyboardEvent_altKeyGet::Method = &Instances::fl_events::KeyboardEvent::altKeyGet;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 16, SPtr<Instances::fl_events::Event>> TFunc_Instances_fl_events_KeyboardEvent_clone;
// @0x140142640
template <> const TFunc_Instances_fl_events_KeyboardEvent_clone::TMethod TFunc_Instances_fl_events_KeyboardEvent_clone::Method = &Instances::fl_events::KeyboardEvent::clone;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 17, ASString> TFunc_Instances_fl_events_KeyboardEvent_toString;
// @0x140142670
template <> const TFunc_Instances_fl_events_KeyboardEvent_toString::TMethod TFunc_Instances_fl_events_KeyboardEvent_toString::Method = &Instances::fl_events::KeyboardEvent::toString;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 18, const Value> TFunc_Instances_fl_events_KeyboardEvent_updateAfterEvent;
// @0x1401426a0
template <> const TFunc_Instances_fl_events_KeyboardEvent_updateAfterEvent::TMethod TFunc_Instances_fl_events_KeyboardEvent_updateAfterEvent::Method = &Instances::fl_events::KeyboardEvent::updateAfterEvent;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 12, UInt32> TFunc_Instances_fl_events_KeyboardEvent_keyLocationGet;
// @0x1401426d0
template <> const TFunc_Instances_fl_events_KeyboardEvent_keyLocationGet::TMethod TFunc_Instances_fl_events_KeyboardEvent_keyLocationGet::Method = &Instances::fl_events::KeyboardEvent::keyLocationGet;
typedef ThunkFunc0<Instances::fl_events::KeyboardEvent, 14, bool> TFunc_Instances_fl_events_KeyboardEvent_shiftKeyGet;
// @0x140142700
template <> const TFunc_Instances_fl_events_KeyboardEvent_shiftKeyGet::TMethod TFunc_Instances_fl_events_KeyboardEvent_shiftKeyGet::Method = &Instances::fl_events::KeyboardEvent::shiftKeyGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 2, bool> TFunc_Instances_fl_events_MouseEvent_buttonDownGet;
// @0x140142730
template <> const TFunc_Instances_fl_events_MouseEvent_buttonDownGet::TMethod TFunc_Instances_fl_events_MouseEvent_buttonDownGet::Method = &Instances::fl_events::MouseEvent::buttonDownGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 4, SInt32> TFunc_Instances_fl_events_MouseEvent_clickCountGet;
// @0x140142760
template <> const TFunc_Instances_fl_events_MouseEvent_clickCountGet::TMethod TFunc_Instances_fl_events_MouseEvent_clickCountGet::Method = &Instances::fl_events::MouseEvent::clickCountGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 5, bool> TFunc_Instances_fl_events_MouseEvent_commandKeyGet;
// @0x140142790
template <> const TFunc_Instances_fl_events_MouseEvent_commandKeyGet::TMethod TFunc_Instances_fl_events_MouseEvent_commandKeyGet::Method = &Instances::fl_events::MouseEvent::commandKeyGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 7, bool> TFunc_Instances_fl_events_MouseEvent_controlKeyGet;
// @0x1401427c0
template <> const TFunc_Instances_fl_events_MouseEvent_controlKeyGet::TMethod TFunc_Instances_fl_events_MouseEvent_controlKeyGet::Method = &Instances::fl_events::MouseEvent::controlKeyGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 9, bool> TFunc_Instances_fl_events_MouseEvent_ctrlKeyGet;
// @0x1401427f0
template <> const TFunc_Instances_fl_events_MouseEvent_ctrlKeyGet::TMethod TFunc_Instances_fl_events_MouseEvent_ctrlKeyGet::Method = &Instances::fl_events::MouseEvent::ctrlKeyGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 0, bool> TFunc_Instances_fl_events_MouseEvent_altKeyGet;
// @0x140142820
template <> const TFunc_Instances_fl_events_MouseEvent_altKeyGet::TMethod TFunc_Instances_fl_events_MouseEvent_altKeyGet::Method = &Instances::fl_events::MouseEvent::altKeyGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 17, SPtr<Instances::fl_display::InteractiveObject>> TFunc_Instances_fl_events_MouseEvent_relatedObjectGet;
// @0x140142850
template <> const TFunc_Instances_fl_events_MouseEvent_relatedObjectGet::TMethod TFunc_Instances_fl_events_MouseEvent_relatedObjectGet::Method = &Instances::fl_events::MouseEvent::relatedObjectGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 19, bool> TFunc_Instances_fl_events_MouseEvent_shiftKeyGet;
// @0x140142880
template <> const TFunc_Instances_fl_events_MouseEvent_shiftKeyGet::TMethod TFunc_Instances_fl_events_MouseEvent_shiftKeyGet::Method = &Instances::fl_events::MouseEvent::shiftKeyGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 21, Value::Number> TFunc_Instances_fl_events_MouseEvent_stageXGet;
// @0x1401428b0
template <> const TFunc_Instances_fl_events_MouseEvent_stageXGet::TMethod TFunc_Instances_fl_events_MouseEvent_stageXGet::Method = &Instances::fl_events::MouseEvent::stageXGet;
typedef ThunkFunc0<Instances::fl_events::MouseEvent, 22, Value::Number> TFunc_Instances_fl_events_MouseEvent_stageYGet;
// @0x1401428e0
template <> const TFunc_Instances_fl_events_MouseEvent_stageYGet::TMethod TFunc_Instances_fl_events_MouseEvent_stageYGet::Method = &Instances::fl_events::MouseEvent::stageYGet;

}}} // namespace Scaleform::GFx::AS3

