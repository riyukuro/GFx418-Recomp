// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, the dynamic initializers of
// the native method member pointers ThunkFuncN<T, N, R, A...>::Method (0x140146150-0x140149990): each stores
// {method, 0} (16 bytes, the general member-pointer representation of as3_marshalling.h). The thunks that call
// through them are in the sfr_as3_* units. Our own source, written from the exe (work/sfr5/gen_natives.py).
// MS2-UNIT: sfr_as3di_04
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140146150-0x140149990 .text$di
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"

namespace Scaleform { namespace GFx { namespace AS3 {

typedef ThunkFunc2<Instances::fl_geom::Matrix3D, 23, const Value, Instances::fl_vec::Vector_double*, Instances::fl_vec::Vector_double*> TFunc_Instances_fl_geom_Matrix3D_transformVectors;
// @0x140146150
template <> const TFunc_Instances_fl_geom_Matrix3D_transformVectors::TMethod TFunc_Instances_fl_geom_Matrix3D_transformVectors::Method = &Instances::fl_geom::Matrix3D::transformVectors;
typedef ThunkFunc2<Instances::fl_geom::Matrix3D, 14, const Value, Instances::fl_geom::Matrix3D*, Value::Number> TFunc_Instances_fl_geom_Matrix3D_interpolateTo;
// @0x140146180
template <> const TFunc_Instances_fl_geom_Matrix3D_interpolateTo::TMethod TFunc_Instances_fl_geom_Matrix3D_interpolateTo::Method = &Instances::fl_geom::Matrix3D::interpolateTo;
typedef ThunkFunc2<Instances::fl_geom::Matrix, 8, const Value, Value::Number, Value::Number> TFunc_Instances_fl_geom_Matrix_scale;
// @0x1401461b0
template <> const TFunc_Instances_fl_geom_Matrix_scale::TMethod TFunc_Instances_fl_geom_Matrix_scale::Method = &Instances::fl_geom::Matrix::scale;
typedef ThunkFunc2<Instances::fl_geom::Matrix, 11, const Value, Value::Number, Value::Number> TFunc_Instances_fl_geom_Matrix_translate;
// @0x1401461e0
template <> const TFunc_Instances_fl_geom_Matrix_translate::TMethod TFunc_Instances_fl_geom_Matrix_translate::Method = &Instances::fl_geom::Matrix::translate;
typedef ThunkFunc2<Classes::fl_geom::Point, 2, SPtr<Instances::fl_geom::Point>, Value::Number, Value::Number> TFunc_Classes_fl_geom_Point_polar;
// @0x140146210
template <> const TFunc_Classes_fl_geom_Point_polar::TMethod TFunc_Classes_fl_geom_Point_polar::Method = &Classes::fl_geom::Point::polar;
typedef ThunkFunc2<Classes::fl_geom::Point, 0, Value::Number, Instances::fl_geom::Point*, Instances::fl_geom::Point*> TFunc_Classes_fl_geom_Point_distance;
// @0x140146240
template <> const TFunc_Classes_fl_geom_Point_distance::TMethod TFunc_Classes_fl_geom_Point_distance::Method = &Classes::fl_geom::Point::distance;
typedef ThunkFunc2<Instances::fl_geom::Point, 5, const Value, Value::Number, Value::Number> TFunc_Instances_fl_geom_Point_offset;
// @0x140146270
template <> const TFunc_Instances_fl_geom_Point_offset::TMethod TFunc_Instances_fl_geom_Point_offset::Method = &Instances::fl_geom::Point::offset;
typedef ThunkFunc2<Instances::fl_geom::Rectangle, 19, const Value, Value::Number, Value::Number> TFunc_Instances_fl_geom_Rectangle_inflate;
// @0x1401462a0
template <> const TFunc_Instances_fl_geom_Rectangle_inflate::TMethod TFunc_Instances_fl_geom_Rectangle_inflate::Method = &Instances::fl_geom::Rectangle::inflate;
typedef ThunkFunc2<Instances::fl_geom::Rectangle, 24, const Value, Value::Number, Value::Number> TFunc_Instances_fl_geom_Rectangle_offset;
// @0x1401462d0
template <> const TFunc_Instances_fl_geom_Rectangle_offset::TMethod TFunc_Instances_fl_geom_Rectangle_offset::Method = &Instances::fl_geom::Rectangle::offset;
typedef ThunkFunc2<Instances::fl_geom::Rectangle, 15, bool, Value::Number, Value::Number> TFunc_Instances_fl_geom_Rectangle_contains;
// @0x140146300
template <> const TFunc_Instances_fl_geom_Rectangle_contains::TMethod TFunc_Instances_fl_geom_Rectangle_contains::Method = &Instances::fl_geom::Rectangle::contains;
typedef ThunkFunc2<Classes::fl_geom::Vector3D, 1, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*> TFunc_Classes_fl_geom_Vector3D_distance;
// @0x140146330
template <> const TFunc_Classes_fl_geom_Vector3D_distance::TMethod TFunc_Classes_fl_geom_Vector3D_distance::Method = &Classes::fl_geom::Vector3D::distance;
typedef ThunkFunc2<Classes::fl_geom::Vector3D, 0, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*> TFunc_Classes_fl_geom_Vector3D_angleBetween;
// @0x140146360
template <> const TFunc_Classes_fl_geom_Vector3D_angleBetween::TMethod TFunc_Classes_fl_geom_Vector3D_angleBetween::Method = &Classes::fl_geom::Vector3D::angleBetween;
typedef ThunkFunc2<Instances::fl_geom::Vector3D, 15, bool, Instances::fl_geom::Vector3D*, bool> TFunc_Instances_fl_geom_Vector3D_equals;
// @0x140146390
template <> const TFunc_Instances_fl_geom_Vector3D_equals::TMethod TFunc_Instances_fl_geom_Vector3D_equals::Method = &Instances::fl_geom::Vector3D::equals;
typedef ThunkFunc3<Instances::fl_geom::Matrix3D, 6, const Value, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Matrix3D_appendRotation;
// @0x1401463c0
template <> const TFunc_Instances_fl_geom_Matrix3D_appendRotation::TMethod TFunc_Instances_fl_geom_Matrix3D_appendRotation::Method = &Instances::fl_geom::Matrix3D::appendRotation;
typedef ThunkFunc3<Instances::fl_geom::Matrix3D, 7, const Value, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_geom_Matrix3D_appendScale;
// @0x1401463f0
template <> const TFunc_Instances_fl_geom_Matrix3D_appendScale::TMethod TFunc_Instances_fl_geom_Matrix3D_appendScale::Method = &Instances::fl_geom::Matrix3D::appendScale;
typedef ThunkFunc3<Instances::fl_geom::Matrix3D, 8, const Value, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_geom_Matrix3D_appendTranslation;
// @0x140146420
template <> const TFunc_Instances_fl_geom_Matrix3D_appendTranslation::TMethod TFunc_Instances_fl_geom_Matrix3D_appendTranslation::Method = &Instances::fl_geom::Matrix3D::appendTranslation;
typedef ThunkFunc3<Instances::fl_geom::Matrix3D, 16, const Value, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Matrix3D_pointAt;
// @0x140146450
template <> const TFunc_Instances_fl_geom_Matrix3D_pointAt::TMethod TFunc_Instances_fl_geom_Matrix3D_pointAt::Method = &Instances::fl_geom::Matrix3D::pointAt;
typedef ThunkFunc3<Instances::fl_geom::Matrix3D, 18, const Value, Value::Number, Instances::fl_geom::Vector3D*, Instances::fl_geom::Vector3D*> TFunc_Instances_fl_geom_Matrix3D_prependRotation;
// @0x140146480
template <> const TFunc_Instances_fl_geom_Matrix3D_prependRotation::TMethod TFunc_Instances_fl_geom_Matrix3D_prependRotation::Method = &Instances::fl_geom::Matrix3D::prependRotation;
typedef ThunkFunc3<Instances::fl_geom::Matrix3D, 19, const Value, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_geom_Matrix3D_prependScale;
// @0x1401464b0
template <> const TFunc_Instances_fl_geom_Matrix3D_prependScale::TMethod TFunc_Instances_fl_geom_Matrix3D_prependScale::Method = &Instances::fl_geom::Matrix3D::prependScale;
typedef ThunkFunc3<Instances::fl_geom::Matrix3D, 20, const Value, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_geom_Matrix3D_prependTranslation;
// @0x1401464e0
template <> const TFunc_Instances_fl_geom_Matrix3D_prependTranslation::TMethod TFunc_Instances_fl_geom_Matrix3D_prependTranslation::Method = &Instances::fl_geom::Matrix3D::prependTranslation;
typedef ThunkFunc3<Instances::fl_geom::Matrix3D, 13, SPtr<Instances::fl_geom::Matrix3D>, Instances::fl_geom::Matrix3D*, Instances::fl_geom::Matrix3D*, Value::Number> TFunc_Instances_fl_geom_Matrix3D_interpolate;
// @0x140146510
template <> const TFunc_Instances_fl_geom_Matrix3D_interpolate::TMethod TFunc_Instances_fl_geom_Matrix3D_interpolate::Method = &Instances::fl_geom::Matrix3D::interpolate;
typedef ThunkFunc3<Classes::fl_geom::Point, 1, SPtr<Instances::fl_geom::Point>, Instances::fl_geom::Point*, Instances::fl_geom::Point*, Value::Number> TFunc_Classes_fl_geom_Point_interpolate;
// @0x140146540
template <> const TFunc_Classes_fl_geom_Point_interpolate::TMethod TFunc_Classes_fl_geom_Point_interpolate::Method = &Classes::fl_geom::Point::interpolate;
typedef ThunkFunc3<Instances::fl_geom::Vector3D, 17, bool, Instances::fl_geom::Vector3D*, Value::Number, bool> TFunc_Instances_fl_geom_Vector3D_nearEquals;
// @0x140146570
template <> const TFunc_Instances_fl_geom_Vector3D_nearEquals::TMethod TFunc_Instances_fl_geom_Vector3D_nearEquals::Method = &Instances::fl_geom::Vector3D::nearEquals;
typedef ThunkFunc5<Instances::fl_geom::Matrix, 2, const Value, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_geom_Matrix_createBox;
// @0x1401465a0
template <> const TFunc_Instances_fl_geom_Matrix_createBox::TMethod TFunc_Instances_fl_geom_Matrix_createBox::Method = &Instances::fl_geom::Matrix::createBox;
typedef ThunkFunc5<Instances::fl_geom::Matrix, 3, const Value, Value::Number, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_geom_Matrix_createGradientBox;
// @0x1401465d0
template <> const TFunc_Instances_fl_geom_Matrix_createGradientBox::TMethod TFunc_Instances_fl_geom_Matrix_createGradientBox::Method = &Instances::fl_geom::Matrix::createGradientBox;
typedef ThunkFunc0<Instances::fl_net::NetConnection, 2, bool> TFunc_Instances_fl_net_NetConnection_connectedGet;
// @0x140146600
template <> const TFunc_Instances_fl_net_NetConnection_connectedGet::TMethod TFunc_Instances_fl_net_NetConnection_connectedGet::Method = &Instances::fl_net::NetConnection::connectedGet;
typedef ThunkFunc0<Instances::fl_net::NetConnection, 3, ASString> TFunc_Instances_fl_net_NetConnection_connectedProxyTypeGet;
// @0x140146630
template <> const TFunc_Instances_fl_net_NetConnection_connectedProxyTypeGet::TMethod TFunc_Instances_fl_net_NetConnection_connectedProxyTypeGet::Method = &Instances::fl_net::NetConnection::connectedProxyTypeGet;
typedef ThunkFunc0<Instances::fl_net::NetConnection, 5, UInt32> TFunc_Instances_fl_net_NetConnection_objectEncodingGet;
// @0x140146660
template <> const TFunc_Instances_fl_net_NetConnection_objectEncodingGet::TMethod TFunc_Instances_fl_net_NetConnection_objectEncodingGet::Method = &Instances::fl_net::NetConnection::objectEncodingGet;
typedef ThunkFunc0<Instances::fl_net::NetConnection, 7, ASString> TFunc_Instances_fl_net_NetConnection_proxyTypeGet;
// @0x140146690
template <> const TFunc_Instances_fl_net_NetConnection_proxyTypeGet::TMethod TFunc_Instances_fl_net_NetConnection_proxyTypeGet::Method = &Instances::fl_net::NetConnection::proxyTypeGet;
typedef ThunkFunc0<Instances::fl_net::NetConnection, 9, ASString> TFunc_Instances_fl_net_NetConnection_uriGet;
// @0x1401466c0
template <> const TFunc_Instances_fl_net_NetConnection_uriGet::TMethod TFunc_Instances_fl_net_NetConnection_uriGet::Method = &Instances::fl_net::NetConnection::uriGet;
typedef ThunkFunc0<Instances::fl_net::NetConnection, 10, bool> TFunc_Instances_fl_net_NetConnection_usingTLSGet;
// @0x1401466f0
template <> const TFunc_Instances_fl_net_NetConnection_usingTLSGet::TMethod TFunc_Instances_fl_net_NetConnection_usingTLSGet::Method = &Instances::fl_net::NetConnection::usingTLSGet;
typedef ThunkFunc0<Instances::fl_net::NetConnection, 0, SPtr<Instances::fl::Object>> TFunc_Instances_fl_net_NetConnection_clientGet;
// @0x140146720
template <> const TFunc_Instances_fl_net_NetConnection_clientGet::TMethod TFunc_Instances_fl_net_NetConnection_clientGet::Method = &Instances::fl_net::NetConnection::clientGet;
typedef ThunkFunc0<Instances::fl_net::NetConnection, 13, const Value> TFunc_Instances_fl_net_NetConnection_close;
// @0x140146750
template <> const TFunc_Instances_fl_net_NetConnection_close::TMethod TFunc_Instances_fl_net_NetConnection_close::Method = &Instances::fl_net::NetConnection::close;
typedef ThunkFunc0<Instances::fl_net::SharedObject, 2, SPtr<Instances::fl::Object>> TFunc_Instances_fl_net_SharedObject_dataGet;
// @0x140146780
template <> const TFunc_Instances_fl_net_SharedObject_dataGet::TMethod TFunc_Instances_fl_net_SharedObject_dataGet::Method = &Instances::fl_net::SharedObject::dataGet;
typedef ThunkFunc0<Instances::fl_net::SharedObject, 5, UInt32> TFunc_Instances_fl_net_SharedObject_objectEncodingGet;
// @0x1401467b0
template <> const TFunc_Instances_fl_net_SharedObject_objectEncodingGet::TMethod TFunc_Instances_fl_net_SharedObject_objectEncodingGet::Method = &Instances::fl_net::SharedObject::objectEncodingGet;
typedef ThunkFunc0<Instances::fl_net::SharedObject, 7, UInt32> TFunc_Instances_fl_net_SharedObject_sizeGet;
// @0x1401467e0
template <> const TFunc_Instances_fl_net_SharedObject_sizeGet::TMethod TFunc_Instances_fl_net_SharedObject_sizeGet::Method = &Instances::fl_net::SharedObject::sizeGet;
typedef ThunkFunc0<Instances::fl_net::SharedObject, 8, const Value> TFunc_Instances_fl_net_SharedObject_clear;
// @0x140146810
template <> const TFunc_Instances_fl_net_SharedObject_clear::TMethod TFunc_Instances_fl_net_SharedObject_clear::Method = &Instances::fl_net::SharedObject::clear;
typedef ThunkFunc0<Instances::fl_net::SharedObject, 9, const Value> TFunc_Instances_fl_net_SharedObject_close;
// @0x140146840
template <> const TFunc_Instances_fl_net_SharedObject_close::TMethod TFunc_Instances_fl_net_SharedObject_close::Method = &Instances::fl_net::SharedObject::close;
typedef ThunkFunc0<Instances::fl_net::SharedObject, 0, SPtr<Instances::fl::Object>> TFunc_Instances_fl_net_SharedObject_clientGet;
// @0x140146870
template <> const TFunc_Instances_fl_net_SharedObject_clientGet::TMethod TFunc_Instances_fl_net_SharedObject_clientGet::Method = &Instances::fl_net::SharedObject::clientGet;
typedef ThunkFunc0<Instances::fl_net::URLLoader, 1, const Value> TFunc_Instances_fl_net_URLLoader_close;
// @0x1401468a0
template <> const TFunc_Instances_fl_net_URLLoader_close::TMethod TFunc_Instances_fl_net_URLLoader_close::Method = &Instances::fl_net::URLLoader::close;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 2, bool> TFunc_Instances_fl_net_URLRequest_cacheResponseGet;
// @0x1401468d0
template <> const TFunc_Instances_fl_net_URLRequest_cacheResponseGet::TMethod TFunc_Instances_fl_net_URLRequest_cacheResponseGet::Method = &Instances::fl_net::URLRequest::cacheResponseGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 4, ASString> TFunc_Instances_fl_net_URLRequest_contentTypeGet;
// @0x140146900
template <> const TFunc_Instances_fl_net_URLRequest_contentTypeGet::TMethod TFunc_Instances_fl_net_URLRequest_contentTypeGet::Method = &Instances::fl_net::URLRequest::contentTypeGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 6, SPtr<Instances::fl::Object>> TFunc_Instances_fl_net_URLRequest_dataGet;
// @0x140146930
template <> const TFunc_Instances_fl_net_URLRequest_dataGet::TMethod TFunc_Instances_fl_net_URLRequest_dataGet::Method = &Instances::fl_net::URLRequest::dataGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 8, ASString> TFunc_Instances_fl_net_URLRequest_digestGet;
// @0x140146960
template <> const TFunc_Instances_fl_net_URLRequest_digestGet::TMethod TFunc_Instances_fl_net_URLRequest_digestGet::Method = &Instances::fl_net::URLRequest::digestGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 10, bool> TFunc_Instances_fl_net_URLRequest_followRedirectsGet;
// @0x140146990
template <> const TFunc_Instances_fl_net_URLRequest_followRedirectsGet::TMethod TFunc_Instances_fl_net_URLRequest_followRedirectsGet::Method = &Instances::fl_net::URLRequest::followRedirectsGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 0, bool> TFunc_Instances_fl_net_URLRequest_authenticateGet;
// @0x1401469c0
template <> const TFunc_Instances_fl_net_URLRequest_authenticateGet::TMethod TFunc_Instances_fl_net_URLRequest_authenticateGet::Method = &Instances::fl_net::URLRequest::authenticateGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 16, SPtr<Instances::fl::Array>> TFunc_Instances_fl_net_URLRequest_requestHeadersGet;
// @0x1401469f0
template <> const TFunc_Instances_fl_net_URLRequest_requestHeadersGet::TMethod TFunc_Instances_fl_net_URLRequest_requestHeadersGet::Method = &Instances::fl_net::URLRequest::requestHeadersGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 18, ASString> TFunc_Instances_fl_net_URLRequest_urlGet;
// @0x140146a20
template <> const TFunc_Instances_fl_net_URLRequest_urlGet::TMethod TFunc_Instances_fl_net_URLRequest_urlGet::Method = &Instances::fl_net::URLRequest::urlGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 20, bool> TFunc_Instances_fl_net_URLRequest_useCacheGet;
// @0x140146a50
template <> const TFunc_Instances_fl_net_URLRequest_useCacheGet::TMethod TFunc_Instances_fl_net_URLRequest_useCacheGet::Method = &Instances::fl_net::URLRequest::useCacheGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 22, ASString> TFunc_Instances_fl_net_URLRequest_userAgentGet;
// @0x140146a80
template <> const TFunc_Instances_fl_net_URLRequest_userAgentGet::TMethod TFunc_Instances_fl_net_URLRequest_userAgentGet::Method = &Instances::fl_net::URLRequest::userAgentGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 12, bool> TFunc_Instances_fl_net_URLRequest_manageCookiesGet;
// @0x140146ab0
template <> const TFunc_Instances_fl_net_URLRequest_manageCookiesGet::TMethod TFunc_Instances_fl_net_URLRequest_manageCookiesGet::Method = &Instances::fl_net::URLRequest::manageCookiesGet;
typedef ThunkFunc0<Instances::fl_net::URLRequest, 14, ASString> TFunc_Instances_fl_net_URLRequest_methodGet;
// @0x140146ae0
template <> const TFunc_Instances_fl_net_URLRequest_methodGet::TMethod TFunc_Instances_fl_net_URLRequest_methodGet::Method = &Instances::fl_net::URLRequest::methodGet;
typedef ThunkFunc0<Instances::fl_net::URLVariables, 1, ASString> TFunc_Instances_fl_net_URLVariables_toString;
// @0x140146b10
template <> const TFunc_Instances_fl_net_URLVariables_toString::TMethod TFunc_Instances_fl_net_URLVariables_toString::Method = &Instances::fl_net::URLVariables::toString;
typedef ThunkFunc1<Instances::fl_net::NetConnection, 1, const Value, const Value&> TFunc_Instances_fl_net_NetConnection_clientSet;
// @0x140146b40
template <> const TFunc_Instances_fl_net_NetConnection_clientSet::TMethod TFunc_Instances_fl_net_NetConnection_clientSet::Method = &Instances::fl_net::NetConnection::clientSet;
typedef ThunkFunc1<Instances::fl_net::NetConnection, 4, const Value, UInt32> TFunc_Instances_fl_net_NetConnection_defaultObjectEncodingSet;
// @0x140146b70
template <> const TFunc_Instances_fl_net_NetConnection_defaultObjectEncodingSet::TMethod TFunc_Instances_fl_net_NetConnection_defaultObjectEncodingSet::Method = &Instances::fl_net::NetConnection::defaultObjectEncodingSet;
typedef ThunkFunc1<Instances::fl_net::NetConnection, 6, const Value, UInt32> TFunc_Instances_fl_net_NetConnection_objectEncodingSet;
// @0x140146ba0
template <> const TFunc_Instances_fl_net_NetConnection_objectEncodingSet::TMethod TFunc_Instances_fl_net_NetConnection_objectEncodingSet::Method = &Instances::fl_net::NetConnection::objectEncodingSet;
typedef ThunkFunc1<Instances::fl_net::NetConnection, 8, const Value, const ASString&> TFunc_Instances_fl_net_NetConnection_proxyTypeSet;
// @0x140146bd0
template <> const TFunc_Instances_fl_net_NetConnection_proxyTypeSet::TMethod TFunc_Instances_fl_net_NetConnection_proxyTypeSet::Method = &Instances::fl_net::NetConnection::proxyTypeSet;
typedef ThunkFunc1<Instances::fl_net::SharedObject, 1, const Value, const Value&> TFunc_Instances_fl_net_SharedObject_clientSet;
// @0x140146c00
template <> const TFunc_Instances_fl_net_SharedObject_clientSet::TMethod TFunc_Instances_fl_net_SharedObject_clientSet::Method = &Instances::fl_net::SharedObject::clientSet;
typedef ThunkFunc1<Instances::fl_net::SharedObject, 3, const Value, UInt32> TFunc_Instances_fl_net_SharedObject_defaultObjectEncodingSet;
// @0x140146c30
template <> const TFunc_Instances_fl_net_SharedObject_defaultObjectEncodingSet::TMethod TFunc_Instances_fl_net_SharedObject_defaultObjectEncodingSet::Method = &Instances::fl_net::SharedObject::defaultObjectEncodingSet;
typedef ThunkFunc1<Instances::fl_net::SharedObject, 4, const Value, Value::Number> TFunc_Instances_fl_net_SharedObject_fpsSet;
// @0x140146c60
template <> const TFunc_Instances_fl_net_SharedObject_fpsSet::TMethod TFunc_Instances_fl_net_SharedObject_fpsSet::Method = &Instances::fl_net::SharedObject::fpsSet;
typedef ThunkFunc1<Instances::fl_net::SharedObject, 6, const Value, UInt32> TFunc_Instances_fl_net_SharedObject_objectEncodingSet;
// @0x140146c90
template <> const TFunc_Instances_fl_net_SharedObject_objectEncodingSet::TMethod TFunc_Instances_fl_net_SharedObject_objectEncodingSet::Method = &Instances::fl_net::SharedObject::objectEncodingSet;
typedef ThunkFunc1<Instances::fl_net::SharedObject, 11, ASString, SInt32> TFunc_Instances_fl_net_SharedObject_flush;
// @0x140146cc0
template <> const TFunc_Instances_fl_net_SharedObject_flush::TMethod TFunc_Instances_fl_net_SharedObject_flush::Method = &Instances::fl_net::SharedObject::flush;
typedef ThunkFunc1<Instances::fl_net::SharedObject, 13, const Value, const ASString&> TFunc_Instances_fl_net_SharedObject_setDirty;
// @0x140146cf0
template <> const TFunc_Instances_fl_net_SharedObject_setDirty::TMethod TFunc_Instances_fl_net_SharedObject_setDirty::Method = &Instances::fl_net::SharedObject::setDirty;
typedef ThunkFunc1<Instances::fl_net::URLLoader, 2, const Value, Instances::fl_net::URLRequest*> TFunc_Instances_fl_net_URLLoader_load;
// @0x140146d20
template <> const TFunc_Instances_fl_net_URLLoader_load::TMethod TFunc_Instances_fl_net_URLLoader_load::Method = &Instances::fl_net::URLLoader::load;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 1, const Value, bool> TFunc_Instances_fl_net_URLRequest_authenticateSet;
// @0x140146d50
template <> const TFunc_Instances_fl_net_URLRequest_authenticateSet::TMethod TFunc_Instances_fl_net_URLRequest_authenticateSet::Method = &Instances::fl_net::URLRequest::authenticateSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 3, const Value, bool> TFunc_Instances_fl_net_URLRequest_cacheResponseSet;
// @0x140146d80
template <> const TFunc_Instances_fl_net_URLRequest_cacheResponseSet::TMethod TFunc_Instances_fl_net_URLRequest_cacheResponseSet::Method = &Instances::fl_net::URLRequest::cacheResponseSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 5, const Value, const ASString&> TFunc_Instances_fl_net_URLRequest_contentTypeSet;
// @0x140146db0
template <> const TFunc_Instances_fl_net_URLRequest_contentTypeSet::TMethod TFunc_Instances_fl_net_URLRequest_contentTypeSet::Method = &Instances::fl_net::URLRequest::contentTypeSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 7, const Value, const Value&> TFunc_Instances_fl_net_URLRequest_dataSet;
// @0x140146de0
template <> const TFunc_Instances_fl_net_URLRequest_dataSet::TMethod TFunc_Instances_fl_net_URLRequest_dataSet::Method = &Instances::fl_net::URLRequest::dataSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 9, const Value, const ASString&> TFunc_Instances_fl_net_URLRequest_digestSet;
// @0x140146e10
template <> const TFunc_Instances_fl_net_URLRequest_digestSet::TMethod TFunc_Instances_fl_net_URLRequest_digestSet::Method = &Instances::fl_net::URLRequest::digestSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 17, const Value, Instances::fl::Array*> TFunc_Instances_fl_net_URLRequest_requestHeadersSet;
// @0x140146e40
template <> const TFunc_Instances_fl_net_URLRequest_requestHeadersSet::TMethod TFunc_Instances_fl_net_URLRequest_requestHeadersSet::Method = &Instances::fl_net::URLRequest::requestHeadersSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 19, const Value, const ASString&> TFunc_Instances_fl_net_URLRequest_urlSet;
// @0x140146e70
template <> const TFunc_Instances_fl_net_URLRequest_urlSet::TMethod TFunc_Instances_fl_net_URLRequest_urlSet::Method = &Instances::fl_net::URLRequest::urlSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 21, const Value, bool> TFunc_Instances_fl_net_URLRequest_useCacheSet;
// @0x140146ea0
template <> const TFunc_Instances_fl_net_URLRequest_useCacheSet::TMethod TFunc_Instances_fl_net_URLRequest_useCacheSet::Method = &Instances::fl_net::URLRequest::useCacheSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 23, const Value, const ASString&> TFunc_Instances_fl_net_URLRequest_userAgentSet;
// @0x140146ed0
template <> const TFunc_Instances_fl_net_URLRequest_userAgentSet::TMethod TFunc_Instances_fl_net_URLRequest_userAgentSet::Method = &Instances::fl_net::URLRequest::userAgentSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 11, const Value, bool> TFunc_Instances_fl_net_URLRequest_followRedirectsSet;
// @0x140146f00
template <> const TFunc_Instances_fl_net_URLRequest_followRedirectsSet::TMethod TFunc_Instances_fl_net_URLRequest_followRedirectsSet::Method = &Instances::fl_net::URLRequest::followRedirectsSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 13, const Value, bool> TFunc_Instances_fl_net_URLRequest_manageCookiesSet;
// @0x140146f30
template <> const TFunc_Instances_fl_net_URLRequest_manageCookiesSet::TMethod TFunc_Instances_fl_net_URLRequest_manageCookiesSet::Method = &Instances::fl_net::URLRequest::manageCookiesSet;
typedef ThunkFunc1<Instances::fl_net::URLRequest, 15, const Value, const ASString&> TFunc_Instances_fl_net_URLRequest_methodSet;
// @0x140146f60
template <> const TFunc_Instances_fl_net_URLRequest_methodSet::TMethod TFunc_Instances_fl_net_URLRequest_methodSet::Method = &Instances::fl_net::URLRequest::methodSet;
typedef ThunkFunc1<Instances::fl_net::URLVariables, 0, const Value, const ASString&> TFunc_Instances_fl_net_URLVariables_decode;
// @0x140146f90
template <> const TFunc_Instances_fl_net_URLVariables_decode::TMethod TFunc_Instances_fl_net_URLVariables_decode::Method = &Instances::fl_net::URLVariables::decode;
typedef ThunkFunc2<Instances::fl_net::NetConnection, 12, Value, unsigned, const Value*> TFunc_Instances_fl_net_NetConnection_call;
// @0x140146fc0
template <> const TFunc_Instances_fl_net_NetConnection_call::TMethod TFunc_Instances_fl_net_NetConnection_call::Method = &Instances::fl_net::NetConnection::call;
typedef ThunkFunc2<Instances::fl_net::NetConnection, 14, Value, unsigned, const Value*> TFunc_Instances_fl_net_NetConnection_connect;
// @0x140146ff0
template <> const TFunc_Instances_fl_net_NetConnection_connect::TMethod TFunc_Instances_fl_net_NetConnection_connect::Method = &Instances::fl_net::NetConnection::connect;
typedef ThunkFunc2<Instances::fl_net::SharedObject, 10, const Value, Instances::fl_net::NetConnection*, const ASString&> TFunc_Instances_fl_net_SharedObject_connect;
// @0x140147020
template <> const TFunc_Instances_fl_net_SharedObject_connect::TMethod TFunc_Instances_fl_net_SharedObject_connect::Method = &Instances::fl_net::SharedObject::connect;
typedef ThunkFunc2<Instances::fl_net::SharedObject, 12, Value, unsigned, const Value*> TFunc_Instances_fl_net_SharedObject_send;
// @0x140147050
template <> const TFunc_Instances_fl_net_SharedObject_send::TMethod TFunc_Instances_fl_net_SharedObject_send::Method = &Instances::fl_net::SharedObject::send;
typedef ThunkFunc2<Instances::fl_net::SharedObject, 14, const Value, const ASString&, const Value&> TFunc_Instances_fl_net_SharedObject_setProperty;
// @0x140147080
template <> const TFunc_Instances_fl_net_SharedObject_setProperty::TMethod TFunc_Instances_fl_net_SharedObject_setProperty::Method = &Instances::fl_net::SharedObject::setProperty;
typedef ThunkFunc3<Instances::fl_net::NetConnection, 11, const Value, const ASString&, bool, const Value&> TFunc_Instances_fl_net_NetConnection_addHeader;
// @0x1401470b0
template <> const TFunc_Instances_fl_net_NetConnection_addHeader::TMethod TFunc_Instances_fl_net_NetConnection_addHeader::Method = &Instances::fl_net::NetConnection::addHeader;
typedef ThunkFunc3<Classes::fl_net::SharedObject, 0, SPtr<Instances::fl_net::SharedObject>, const ASString&, const ASString&, bool> TFunc_Classes_fl_net_SharedObject_getLocal;
// @0x1401470e0
template <> const TFunc_Classes_fl_net_SharedObject_getLocal::TMethod TFunc_Classes_fl_net_SharedObject_getLocal::Method = &Classes::fl_net::SharedObject::getLocal;
typedef ThunkFunc4<Classes::fl_net::SharedObject, 1, SPtr<Instances::fl_net::SharedObject>, const ASString&, const ASString&, const Value&, bool> TFunc_Classes_fl_net_SharedObject_getRemote;
// @0x140147110
template <> const TFunc_Classes_fl_net_SharedObject_getRemote::TMethod TFunc_Classes_fl_net_SharedObject_getRemote::Method = &Classes::fl_net::SharedObject::getRemote;
typedef ThunkFunc5<Instances::fl_net::URLLoader, 0, const Value, const ASString&, const Value&, bool, SInt32, bool> TFunc_Instances_fl_net_URLLoader_addEventListener;
// @0x140147140
template <> const TFunc_Instances_fl_net_URLLoader_addEventListener::TMethod TFunc_Instances_fl_net_URLLoader_addEventListener::Method = &Instances::fl_net::URLLoader::addEventListener;
typedef ThunkFunc0<Instances::fl_system::ApplicationDomain, 0, SPtr<Instances::fl_system::ApplicationDomain>> TFunc_Instances_fl_system_ApplicationDomain_parentDomainGet;
// @0x140147170
template <> const TFunc_Instances_fl_system_ApplicationDomain_parentDomainGet::TMethod TFunc_Instances_fl_system_ApplicationDomain_parentDomainGet::Method = &Instances::fl_system::ApplicationDomain::parentDomainGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 1, bool> TFunc_Classes_fl_system_Capabilities_hasAccessibilityGet;
// @0x1401471a0
template <> const TFunc_Classes_fl_system_Capabilities_hasAccessibilityGet::TMethod TFunc_Classes_fl_system_Capabilities_hasAccessibilityGet::Method = &Classes::fl_system::Capabilities::hasAccessibilityGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 2, bool> TFunc_Classes_fl_system_Capabilities_hasAudioGet;
// @0x1401471d0
template <> const TFunc_Classes_fl_system_Capabilities_hasAudioGet::TMethod TFunc_Classes_fl_system_Capabilities_hasAudioGet::Method = &Classes::fl_system::Capabilities::hasAudioGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 3, bool> TFunc_Classes_fl_system_Capabilities_hasAudioEncoderGet;
// @0x140147200
template <> const TFunc_Classes_fl_system_Capabilities_hasAudioEncoderGet::TMethod TFunc_Classes_fl_system_Capabilities_hasAudioEncoderGet::Method = &Classes::fl_system::Capabilities::hasAudioEncoderGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 4, bool> TFunc_Classes_fl_system_Capabilities_hasEmbeddedVideoGet;
// @0x140147230
template <> const TFunc_Classes_fl_system_Capabilities_hasEmbeddedVideoGet::TMethod TFunc_Classes_fl_system_Capabilities_hasEmbeddedVideoGet::Method = &Classes::fl_system::Capabilities::hasEmbeddedVideoGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 5, bool> TFunc_Classes_fl_system_Capabilities_hasIMEGet;
// @0x140147260
template <> const TFunc_Classes_fl_system_Capabilities_hasIMEGet::TMethod TFunc_Classes_fl_system_Capabilities_hasIMEGet::Method = &Classes::fl_system::Capabilities::hasIMEGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 6, bool> TFunc_Classes_fl_system_Capabilities_hasMP3Get;
// @0x140147290
template <> const TFunc_Classes_fl_system_Capabilities_hasMP3Get::TMethod TFunc_Classes_fl_system_Capabilities_hasMP3Get::Method = &Classes::fl_system::Capabilities::hasMP3Get;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 7, bool> TFunc_Classes_fl_system_Capabilities_hasPrintingGet;
// @0x1401472c0
template <> const TFunc_Classes_fl_system_Capabilities_hasPrintingGet::TMethod TFunc_Classes_fl_system_Capabilities_hasPrintingGet::Method = &Classes::fl_system::Capabilities::hasPrintingGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 8, bool> TFunc_Classes_fl_system_Capabilities_hasScreenBroadcastGet;
// @0x1401472f0
template <> const TFunc_Classes_fl_system_Capabilities_hasScreenBroadcastGet::TMethod TFunc_Classes_fl_system_Capabilities_hasScreenBroadcastGet::Method = &Classes::fl_system::Capabilities::hasScreenBroadcastGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 9, bool> TFunc_Classes_fl_system_Capabilities_hasScreenPlaybackGet;
// @0x140147320
template <> const TFunc_Classes_fl_system_Capabilities_hasScreenPlaybackGet::TMethod TFunc_Classes_fl_system_Capabilities_hasScreenPlaybackGet::Method = &Classes::fl_system::Capabilities::hasScreenPlaybackGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 10, bool> TFunc_Classes_fl_system_Capabilities_hasStreamingAudioGet;
// @0x140147350
template <> const TFunc_Classes_fl_system_Capabilities_hasStreamingAudioGet::TMethod TFunc_Classes_fl_system_Capabilities_hasStreamingAudioGet::Method = &Classes::fl_system::Capabilities::hasStreamingAudioGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 0, bool> TFunc_Classes_fl_system_Capabilities_avHardwareDisableGet;
// @0x140147380
template <> const TFunc_Classes_fl_system_Capabilities_avHardwareDisableGet::TMethod TFunc_Classes_fl_system_Capabilities_avHardwareDisableGet::Method = &Classes::fl_system::Capabilities::avHardwareDisableGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 16, bool> TFunc_Classes_fl_system_Capabilities_localFileReadDisableGet;
// @0x1401473b0
template <> const TFunc_Classes_fl_system_Capabilities_localFileReadDisableGet::TMethod TFunc_Classes_fl_system_Capabilities_localFileReadDisableGet::Method = &Classes::fl_system::Capabilities::localFileReadDisableGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 17, ASString> TFunc_Classes_fl_system_Capabilities_manufacturerGet;
// @0x1401473e0
template <> const TFunc_Classes_fl_system_Capabilities_manufacturerGet::TMethod TFunc_Classes_fl_system_Capabilities_manufacturerGet::Method = &Classes::fl_system::Capabilities::manufacturerGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 18, ASString> TFunc_Classes_fl_system_Capabilities_osGet;
// @0x140147410
template <> const TFunc_Classes_fl_system_Capabilities_osGet::TMethod TFunc_Classes_fl_system_Capabilities_osGet::Method = &Classes::fl_system::Capabilities::osGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 19, Value::Number> TFunc_Classes_fl_system_Capabilities_pixelAspectRatioGet;
// @0x140147440
template <> const TFunc_Classes_fl_system_Capabilities_pixelAspectRatioGet::TMethod TFunc_Classes_fl_system_Capabilities_pixelAspectRatioGet::Method = &Classes::fl_system::Capabilities::pixelAspectRatioGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 20, ASString> TFunc_Classes_fl_system_Capabilities_playerTypeGet;
// @0x140147470
template <> const TFunc_Classes_fl_system_Capabilities_playerTypeGet::TMethod TFunc_Classes_fl_system_Capabilities_playerTypeGet::Method = &Classes::fl_system::Capabilities::playerTypeGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 21, ASString> TFunc_Classes_fl_system_Capabilities_screenColorGet;
// @0x1401474a0
template <> const TFunc_Classes_fl_system_Capabilities_screenColorGet::TMethod TFunc_Classes_fl_system_Capabilities_screenColorGet::Method = &Classes::fl_system::Capabilities::screenColorGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 22, Value::Number> TFunc_Classes_fl_system_Capabilities_screenDPIGet;
// @0x1401474d0
template <> const TFunc_Classes_fl_system_Capabilities_screenDPIGet::TMethod TFunc_Classes_fl_system_Capabilities_screenDPIGet::Method = &Classes::fl_system::Capabilities::screenDPIGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 23, Value::Number> TFunc_Classes_fl_system_Capabilities_screenResolutionXGet;
// @0x140147500
template <> const TFunc_Classes_fl_system_Capabilities_screenResolutionXGet::TMethod TFunc_Classes_fl_system_Capabilities_screenResolutionXGet::Method = &Classes::fl_system::Capabilities::screenResolutionXGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 24, Value::Number> TFunc_Classes_fl_system_Capabilities_screenResolutionYGet;
// @0x140147530
template <> const TFunc_Classes_fl_system_Capabilities_screenResolutionYGet::TMethod TFunc_Classes_fl_system_Capabilities_screenResolutionYGet::Method = &Classes::fl_system::Capabilities::screenResolutionYGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 25, ASString> TFunc_Classes_fl_system_Capabilities_serverStringGet;
// @0x140147560
template <> const TFunc_Classes_fl_system_Capabilities_serverStringGet::TMethod TFunc_Classes_fl_system_Capabilities_serverStringGet::Method = &Classes::fl_system::Capabilities::serverStringGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 26, ASString> TFunc_Classes_fl_system_Capabilities_versionGet;
// @0x140147590
template <> const TFunc_Classes_fl_system_Capabilities_versionGet::TMethod TFunc_Classes_fl_system_Capabilities_versionGet::Method = &Classes::fl_system::Capabilities::versionGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 11, bool> TFunc_Classes_fl_system_Capabilities_hasStreamingVideoGet;
// @0x1401475c0
template <> const TFunc_Classes_fl_system_Capabilities_hasStreamingVideoGet::TMethod TFunc_Classes_fl_system_Capabilities_hasStreamingVideoGet::Method = &Classes::fl_system::Capabilities::hasStreamingVideoGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 12, bool> TFunc_Classes_fl_system_Capabilities_hasTLSGet;
// @0x1401475f0
template <> const TFunc_Classes_fl_system_Capabilities_hasTLSGet::TMethod TFunc_Classes_fl_system_Capabilities_hasTLSGet::Method = &Classes::fl_system::Capabilities::hasTLSGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 13, bool> TFunc_Classes_fl_system_Capabilities_hasVideoEncoderGet;
// @0x140147620
template <> const TFunc_Classes_fl_system_Capabilities_hasVideoEncoderGet::TMethod TFunc_Classes_fl_system_Capabilities_hasVideoEncoderGet::Method = &Classes::fl_system::Capabilities::hasVideoEncoderGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 14, bool> TFunc_Classes_fl_system_Capabilities_isDebuggerGet;
// @0x140147650
template <> const TFunc_Classes_fl_system_Capabilities_isDebuggerGet::TMethod TFunc_Classes_fl_system_Capabilities_isDebuggerGet::Method = &Classes::fl_system::Capabilities::isDebuggerGet;
typedef ThunkFunc0<Classes::fl_system::Capabilities, 15, ASString> TFunc_Classes_fl_system_Capabilities_languageGet;
// @0x140147680
template <> const TFunc_Classes_fl_system_Capabilities_languageGet::TMethod TFunc_Classes_fl_system_Capabilities_languageGet::Method = &Classes::fl_system::Capabilities::languageGet;
typedef ThunkFunc0<Classes::fl_system::IME, 1, ASString> TFunc_Classes_fl_system_IME_conversionModeGet;
// @0x1401476b0
template <> const TFunc_Classes_fl_system_IME_conversionModeGet::TMethod TFunc_Classes_fl_system_IME_conversionModeGet::Method = &Classes::fl_system::IME::conversionModeGet;
typedef ThunkFunc0<Classes::fl_system::IME, 2, bool> TFunc_Classes_fl_system_IME_enabledGet;
// @0x1401476e0
template <> const TFunc_Classes_fl_system_IME_enabledGet::TMethod TFunc_Classes_fl_system_IME_enabledGet::Method = &Classes::fl_system::IME::enabledGet;
typedef ThunkFunc0<Classes::fl_system::IME, 4, const Value> TFunc_Classes_fl_system_IME_doConversion;
// @0x140147710
template <> const TFunc_Classes_fl_system_IME_doConversion::TMethod TFunc_Classes_fl_system_IME_doConversion::Method = &Classes::fl_system::IME::doConversion;
typedef ThunkFunc0<Classes::fl_system::SecurityDomain, 0, SPtr<Instances::fl_system::SecurityDomain>> TFunc_Classes_fl_system_SecurityDomain_currentDomainGet;
// @0x140147740
template <> const TFunc_Classes_fl_system_SecurityDomain_currentDomainGet::TMethod TFunc_Classes_fl_system_SecurityDomain_currentDomainGet::Method = &Classes::fl_system::SecurityDomain::currentDomainGet;
typedef ThunkFunc0<Classes::fl_system::System, 1, UInt32> TFunc_Classes_fl_system_System_totalMemoryGet;
// @0x140147770
template <> const TFunc_Classes_fl_system_System_totalMemoryGet::TMethod TFunc_Classes_fl_system_System_totalMemoryGet::Method = &Classes::fl_system::System::totalMemoryGet;
typedef ThunkFunc0<Classes::fl_system::System, 3, const Value> TFunc_Classes_fl_system_System_gc;
// @0x1401477a0
template <> const TFunc_Classes_fl_system_System_gc::TMethod TFunc_Classes_fl_system_System_gc::Method = &Classes::fl_system::System::gc;
typedef ThunkFunc0<Classes::fl_system::System, 4, const Value> TFunc_Classes_fl_system_System_pause;
// @0x1401477d0
template <> const TFunc_Classes_fl_system_System_pause::TMethod TFunc_Classes_fl_system_System_pause::Method = &Classes::fl_system::System::pause;
typedef ThunkFunc0<Classes::fl_system::System, 5, const Value> TFunc_Classes_fl_system_System_resume;
// @0x140147800
template <> const TFunc_Classes_fl_system_System_resume::TMethod TFunc_Classes_fl_system_System_resume::Method = &Classes::fl_system::System::resume;
typedef ThunkFunc0<Classes::fl_system::System, 0, Value> TFunc_Classes_fl_system_System_imeGet;
// @0x140147830
template <> const TFunc_Classes_fl_system_System_imeGet::TMethod TFunc_Classes_fl_system_System_imeGet::Method = &Classes::fl_system::System::imeGet;
typedef ThunkFunc1<Instances::fl_system::ApplicationDomain, 1, Value, const ASString&> TFunc_Instances_fl_system_ApplicationDomain_getDefinition;
// @0x140147860
template <> const TFunc_Instances_fl_system_ApplicationDomain_getDefinition::TMethod TFunc_Instances_fl_system_ApplicationDomain_getDefinition::Method = &Instances::fl_system::ApplicationDomain::getDefinition;
typedef ThunkFunc1<Instances::fl_system::ApplicationDomain, 2, bool, const ASString&> TFunc_Instances_fl_system_ApplicationDomain_hasDefinition;
// @0x140147890
template <> const TFunc_Instances_fl_system_ApplicationDomain_hasDefinition::TMethod TFunc_Instances_fl_system_ApplicationDomain_hasDefinition::Method = &Instances::fl_system::ApplicationDomain::hasDefinition;
typedef ThunkFunc1<Classes::fl_system::IME, 3, const Value, bool> TFunc_Classes_fl_system_IME_enabledSet;
// @0x1401478c0
template <> const TFunc_Classes_fl_system_IME_enabledSet::TMethod TFunc_Classes_fl_system_IME_enabledSet::Method = &Classes::fl_system::IME::enabledSet;
typedef ThunkFunc1<Classes::fl_system::IME, 5, const Value, const ASString&> TFunc_Classes_fl_system_IME_setCompositionString;
// @0x1401478f0
template <> const TFunc_Classes_fl_system_IME_setCompositionString::TMethod TFunc_Classes_fl_system_IME_setCompositionString::Method = &Classes::fl_system::IME::setCompositionString;
typedef ThunkFunc1<Classes::fl_system::IME, 0, const Value, const ASString&> TFunc_Classes_fl_system_IME_conversionModeSet;
// @0x140147920
template <> const TFunc_Classes_fl_system_IME_conversionModeSet::TMethod TFunc_Classes_fl_system_IME_conversionModeSet::Method = &Classes::fl_system::IME::conversionModeSet;
typedef ThunkFunc1<Classes::fl_system::System, 2, const Value, UInt32> TFunc_Classes_fl_system_System_exit;
// @0x140147950
template <> const TFunc_Classes_fl_system_System_exit::TMethod TFunc_Classes_fl_system_System_exit::Method = &Classes::fl_system::System::exit;
typedef ThunkFunc1<Classes::fl_system::System, 6, const Value, const ASString&> TFunc_Classes_fl_system_System_setClipboard;
// @0x140147980
template <> const TFunc_Classes_fl_system_System_setClipboard::TMethod TFunc_Classes_fl_system_System_setClipboard::Method = &Classes::fl_system::System::setClipboard;
typedef ThunkFunc0<Instances::fl_text::Font, 1, Value> TFunc_Instances_fl_text_Font_fontStyleGet;
// @0x1401479b0
template <> const TFunc_Instances_fl_text_Font_fontStyleGet::TMethod TFunc_Instances_fl_text_Font_fontStyleGet::Method = &Instances::fl_text::Font::fontStyleGet;
typedef ThunkFunc0<Instances::fl_text::Font, 2, Value> TFunc_Instances_fl_text_Font_fontTypeGet;
// @0x1401479e0
template <> const TFunc_Instances_fl_text_Font_fontTypeGet::TMethod TFunc_Instances_fl_text_Font_fontTypeGet::Method = &Instances::fl_text::Font::fontTypeGet;
typedef ThunkFunc0<Instances::fl_text::Font, 0, Value> TFunc_Instances_fl_text_Font_fontNameGet;
// @0x140147a10
template <> const TFunc_Instances_fl_text_Font_fontNameGet::TMethod TFunc_Instances_fl_text_Font_fontNameGet::Method = &Instances::fl_text::Font::fontNameGet;
typedef ThunkFunc0<Instances::fl_text::StaticText, 0, ASString> TFunc_Instances_fl_text_StaticText_textGet;
// @0x140147a40
template <> const TFunc_Instances_fl_text_StaticText_textGet::TMethod TFunc_Instances_fl_text_StaticText_textGet::Method = &Instances::fl_text::StaticText::textGet;
typedef ThunkFunc0<Instances::fl_text::StyleSheet, 1, const Value> TFunc_Instances_fl_text_StyleSheet_clear;
// @0x140147a70
template <> const TFunc_Instances_fl_text_StyleSheet_clear::TMethod TFunc_Instances_fl_text_StyleSheet_clear::Method = &Instances::fl_text::StyleSheet::clear;
typedef ThunkFunc0<Instances::fl_text::StyleSheet, 0, SPtr<Instances::fl::Array>> TFunc_Instances_fl_text_StyleSheet_styleNamesGet;
// @0x140147aa0
template <> const TFunc_Instances_fl_text_StyleSheet_styleNamesGet::TMethod TFunc_Instances_fl_text_StyleSheet_styleNamesGet::Method = &Instances::fl_text::StyleSheet::styleNamesGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 2, ASString> TFunc_Instances_fl_text_TextField_antiAliasTypeGet;
// @0x140147ad0
template <> const TFunc_Instances_fl_text_TextField_antiAliasTypeGet::TMethod TFunc_Instances_fl_text_TextField_antiAliasTypeGet::Method = &Instances::fl_text::TextField::antiAliasTypeGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 4, ASString> TFunc_Instances_fl_text_TextField_autoSizeGet;
// @0x140147b00
template <> const TFunc_Instances_fl_text_TextField_autoSizeGet::TMethod TFunc_Instances_fl_text_TextField_autoSizeGet::Method = &Instances::fl_text::TextField::autoSizeGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 6, bool> TFunc_Instances_fl_text_TextField_backgroundGet;
// @0x140147b30
template <> const TFunc_Instances_fl_text_TextField_backgroundGet::TMethod TFunc_Instances_fl_text_TextField_backgroundGet::Method = &Instances::fl_text::TextField::backgroundGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 8, UInt32> TFunc_Instances_fl_text_TextField_backgroundColorGet;
// @0x140147b60
template <> const TFunc_Instances_fl_text_TextField_backgroundColorGet::TMethod TFunc_Instances_fl_text_TextField_backgroundColorGet::Method = &Instances::fl_text::TextField::backgroundColorGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 10, bool> TFunc_Instances_fl_text_TextField_borderGet;
// @0x140147b90
template <> const TFunc_Instances_fl_text_TextField_borderGet::TMethod TFunc_Instances_fl_text_TextField_borderGet::Method = &Instances::fl_text::TextField::borderGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 0, bool> TFunc_Instances_fl_text_TextField_alwaysShowSelectionGet;
// @0x140147bc0
template <> const TFunc_Instances_fl_text_TextField_alwaysShowSelectionGet::TMethod TFunc_Instances_fl_text_TextField_alwaysShowSelectionGet::Method = &Instances::fl_text::TextField::alwaysShowSelectionGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 16, bool> TFunc_Instances_fl_text_TextField_condenseWhiteGet;
// @0x140147bf0
template <> const TFunc_Instances_fl_text_TextField_condenseWhiteGet::TMethod TFunc_Instances_fl_text_TextField_condenseWhiteGet::Method = &Instances::fl_text::TextField::condenseWhiteGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 900, SPtr<Instances::fl_display::NativeMenu>> TFunc_Instances_fl_text_TextField_contextMenuGet;
// @0x140147c20
template <> const TFunc_Instances_fl_text_TextField_contextMenuGet::TMethod TFunc_Instances_fl_text_TextField_contextMenuGet::Method = &Instances::fl_text::TextField::contextMenuGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 18, SPtr<Instances::fl_text::TextFormat>> TFunc_Instances_fl_text_TextField_defaultTextFormatGet;
// @0x140147c50
template <> const TFunc_Instances_fl_text_TextField_defaultTextFormatGet::TMethod TFunc_Instances_fl_text_TextField_defaultTextFormatGet::Method = &Instances::fl_text::TextField::defaultTextFormatGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 20, bool> TFunc_Instances_fl_text_TextField_displayAsPasswordGet;
// @0x140147c80
template <> const TFunc_Instances_fl_text_TextField_displayAsPasswordGet::TMethod TFunc_Instances_fl_text_TextField_displayAsPasswordGet::Method = &Instances::fl_text::TextField::displayAsPasswordGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 22, bool> TFunc_Instances_fl_text_TextField_embedFontsGet;
// @0x140147cb0
template <> const TFunc_Instances_fl_text_TextField_embedFontsGet::TMethod TFunc_Instances_fl_text_TextField_embedFontsGet::Method = &Instances::fl_text::TextField::embedFontsGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 24, ASString> TFunc_Instances_fl_text_TextField_gridFitTypeGet;
// @0x140147ce0
template <> const TFunc_Instances_fl_text_TextField_gridFitTypeGet::TMethod TFunc_Instances_fl_text_TextField_gridFitTypeGet::Method = &Instances::fl_text::TextField::gridFitTypeGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 26, ASString> TFunc_Instances_fl_text_TextField_htmlTextGet;
// @0x140147d10
template <> const TFunc_Instances_fl_text_TextField_htmlTextGet::TMethod TFunc_Instances_fl_text_TextField_htmlTextGet::Method = &Instances::fl_text::TextField::htmlTextGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 28, SInt32> TFunc_Instances_fl_text_TextField_lengthGet;
// @0x140147d40
template <> const TFunc_Instances_fl_text_TextField_lengthGet::TMethod TFunc_Instances_fl_text_TextField_lengthGet::Method = &Instances::fl_text::TextField::lengthGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 29, SInt32> TFunc_Instances_fl_text_TextField_maxCharsGet;
// @0x140147d70
template <> const TFunc_Instances_fl_text_TextField_maxCharsGet::TMethod TFunc_Instances_fl_text_TextField_maxCharsGet::Method = &Instances::fl_text::TextField::maxCharsGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 31, SInt32> TFunc_Instances_fl_text_TextField_maxScrollHGet;
// @0x140147da0
template <> const TFunc_Instances_fl_text_TextField_maxScrollHGet::TMethod TFunc_Instances_fl_text_TextField_maxScrollHGet::Method = &Instances::fl_text::TextField::maxScrollHGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 32, SInt32> TFunc_Instances_fl_text_TextField_maxScrollVGet;
// @0x140147dd0
template <> const TFunc_Instances_fl_text_TextField_maxScrollVGet::TMethod TFunc_Instances_fl_text_TextField_maxScrollVGet::Method = &Instances::fl_text::TextField::maxScrollVGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 33, bool> TFunc_Instances_fl_text_TextField_mouseWheelEnabledGet;
// @0x140147e00
template <> const TFunc_Instances_fl_text_TextField_mouseWheelEnabledGet::TMethod TFunc_Instances_fl_text_TextField_mouseWheelEnabledGet::Method = &Instances::fl_text::TextField::mouseWheelEnabledGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 35, bool> TFunc_Instances_fl_text_TextField_multilineGet;
// @0x140147e30
template <> const TFunc_Instances_fl_text_TextField_multilineGet::TMethod TFunc_Instances_fl_text_TextField_multilineGet::Method = &Instances::fl_text::TextField::multilineGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 37, SInt32> TFunc_Instances_fl_text_TextField_numLinesGet;
// @0x140147e60
template <> const TFunc_Instances_fl_text_TextField_numLinesGet::TMethod TFunc_Instances_fl_text_TextField_numLinesGet::Method = &Instances::fl_text::TextField::numLinesGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 38, ASString> TFunc_Instances_fl_text_TextField_restrictGet;
// @0x140147e90
template <> const TFunc_Instances_fl_text_TextField_restrictGet::TMethod TFunc_Instances_fl_text_TextField_restrictGet::Method = &Instances::fl_text::TextField::restrictGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 40, SInt32> TFunc_Instances_fl_text_TextField_scrollHGet;
// @0x140147ec0
template <> const TFunc_Instances_fl_text_TextField_scrollHGet::TMethod TFunc_Instances_fl_text_TextField_scrollHGet::Method = &Instances::fl_text::TextField::scrollHGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 42, SInt32> TFunc_Instances_fl_text_TextField_scrollVGet;
// @0x140147ef0
template <> const TFunc_Instances_fl_text_TextField_scrollVGet::TMethod TFunc_Instances_fl_text_TextField_scrollVGet::Method = &Instances::fl_text::TextField::scrollVGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 44, bool> TFunc_Instances_fl_text_TextField_selectableGet;
// @0x140147f20
template <> const TFunc_Instances_fl_text_TextField_selectableGet::TMethod TFunc_Instances_fl_text_TextField_selectableGet::Method = &Instances::fl_text::TextField::selectableGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 46, SInt32> TFunc_Instances_fl_text_TextField_selectionBeginIndexGet;
// @0x140147f50
template <> const TFunc_Instances_fl_text_TextField_selectionBeginIndexGet::TMethod TFunc_Instances_fl_text_TextField_selectionBeginIndexGet::Method = &Instances::fl_text::TextField::selectionBeginIndexGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 47, SInt32> TFunc_Instances_fl_text_TextField_selectionEndIndexGet;
// @0x140147f80
template <> const TFunc_Instances_fl_text_TextField_selectionEndIndexGet::TMethod TFunc_Instances_fl_text_TextField_selectionEndIndexGet::Method = &Instances::fl_text::TextField::selectionEndIndexGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 48, Value::Number> TFunc_Instances_fl_text_TextField_sharpnessGet;
// @0x140147fb0
template <> const TFunc_Instances_fl_text_TextField_sharpnessGet::TMethod TFunc_Instances_fl_text_TextField_sharpnessGet::Method = &Instances::fl_text::TextField::sharpnessGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 50, SPtr<Instances::fl_text::StyleSheet>> TFunc_Instances_fl_text_TextField_styleSheetGet;
// @0x140147fe0
template <> const TFunc_Instances_fl_text_TextField_styleSheetGet::TMethod TFunc_Instances_fl_text_TextField_styleSheetGet::Method = &Instances::fl_text::TextField::styleSheetGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 52, ASString> TFunc_Instances_fl_text_TextField_textGet;
// @0x140148010
template <> const TFunc_Instances_fl_text_TextField_textGet::TMethod TFunc_Instances_fl_text_TextField_textGet::Method = &Instances::fl_text::TextField::textGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 54, UInt32> TFunc_Instances_fl_text_TextField_textColorGet;
// @0x140148040
template <> const TFunc_Instances_fl_text_TextField_textColorGet::TMethod TFunc_Instances_fl_text_TextField_textColorGet::Method = &Instances::fl_text::TextField::textColorGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 56, Value::Number> TFunc_Instances_fl_text_TextField_textHeightGet;
// @0x140148070
template <> const TFunc_Instances_fl_text_TextField_textHeightGet::TMethod TFunc_Instances_fl_text_TextField_textHeightGet::Method = &Instances::fl_text::TextField::textHeightGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 57, Value::Number> TFunc_Instances_fl_text_TextField_textWidthGet;
// @0x1401480a0
template <> const TFunc_Instances_fl_text_TextField_textWidthGet::TMethod TFunc_Instances_fl_text_TextField_textWidthGet::Method = &Instances::fl_text::TextField::textWidthGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 58, Value::Number> TFunc_Instances_fl_text_TextField_thicknessGet;
// @0x1401480d0
template <> const TFunc_Instances_fl_text_TextField_thicknessGet::TMethod TFunc_Instances_fl_text_TextField_thicknessGet::Method = &Instances::fl_text::TextField::thicknessGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 60, ASString> TFunc_Instances_fl_text_TextField_typeGet;
// @0x140148100
template <> const TFunc_Instances_fl_text_TextField_typeGet::TMethod TFunc_Instances_fl_text_TextField_typeGet::Method = &Instances::fl_text::TextField::typeGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 62, bool> TFunc_Instances_fl_text_TextField_useRichTextClipboardGet;
// @0x140148130
template <> const TFunc_Instances_fl_text_TextField_useRichTextClipboardGet::TMethod TFunc_Instances_fl_text_TextField_useRichTextClipboardGet::Method = &Instances::fl_text::TextField::useRichTextClipboardGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 64, bool> TFunc_Instances_fl_text_TextField_wordWrapGet;
// @0x140148160
template <> const TFunc_Instances_fl_text_TextField_wordWrapGet::TMethod TFunc_Instances_fl_text_TextField_wordWrapGet::Method = &Instances::fl_text::TextField::wordWrapGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 12, UInt32> TFunc_Instances_fl_text_TextField_borderColorGet;
// @0x140148190
template <> const TFunc_Instances_fl_text_TextField_borderColorGet::TMethod TFunc_Instances_fl_text_TextField_borderColorGet::Method = &Instances::fl_text::TextField::borderColorGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 14, SInt32> TFunc_Instances_fl_text_TextField_bottomScrollVGet;
// @0x1401481c0
template <> const TFunc_Instances_fl_text_TextField_bottomScrollVGet::TMethod TFunc_Instances_fl_text_TextField_bottomScrollVGet::Method = &Instances::fl_text::TextField::bottomScrollVGet;
typedef ThunkFunc0<Instances::fl_text::TextField, 15, SInt32> TFunc_Instances_fl_text_TextField_caretIndexGet;
// @0x1401481f0
template <> const TFunc_Instances_fl_text_TextField_caretIndexGet::TMethod TFunc_Instances_fl_text_TextField_caretIndexGet::Method = &Instances::fl_text::TextField::caretIndexGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 2, Value> TFunc_Instances_fl_text_TextFormat_blockIndentGet;
// @0x140148220
template <> const TFunc_Instances_fl_text_TextFormat_blockIndentGet::TMethod TFunc_Instances_fl_text_TextFormat_blockIndentGet::Method = &Instances::fl_text::TextFormat::blockIndentGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 4, Value> TFunc_Instances_fl_text_TextFormat_boldGet;
// @0x140148250
template <> const TFunc_Instances_fl_text_TextFormat_boldGet::TMethod TFunc_Instances_fl_text_TextFormat_boldGet::Method = &Instances::fl_text::TextFormat::boldGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 6, Value> TFunc_Instances_fl_text_TextFormat_bulletGet;
// @0x140148280
template <> const TFunc_Instances_fl_text_TextFormat_bulletGet::TMethod TFunc_Instances_fl_text_TextFormat_bulletGet::Method = &Instances::fl_text::TextFormat::bulletGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 8, Value> TFunc_Instances_fl_text_TextFormat_colorGet;
// @0x1401482b0
template <> const TFunc_Instances_fl_text_TextFormat_colorGet::TMethod TFunc_Instances_fl_text_TextFormat_colorGet::Method = &Instances::fl_text::TextFormat::colorGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 10, ASString> TFunc_Instances_fl_text_TextFormat_fontGet;
// @0x1401482e0
template <> const TFunc_Instances_fl_text_TextFormat_fontGet::TMethod TFunc_Instances_fl_text_TextFormat_fontGet::Method = &Instances::fl_text::TextFormat::fontGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 0, ASString> TFunc_Instances_fl_text_TextFormat_alignGet;
// @0x140148310
template <> const TFunc_Instances_fl_text_TextFormat_alignGet::TMethod TFunc_Instances_fl_text_TextFormat_alignGet::Method = &Instances::fl_text::TextFormat::alignGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 16, Value> TFunc_Instances_fl_text_TextFormat_kerningGet;
// @0x140148340
template <> const TFunc_Instances_fl_text_TextFormat_kerningGet::TMethod TFunc_Instances_fl_text_TextFormat_kerningGet::Method = &Instances::fl_text::TextFormat::kerningGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 18, Value> TFunc_Instances_fl_text_TextFormat_leadingGet;
// @0x140148370
template <> const TFunc_Instances_fl_text_TextFormat_leadingGet::TMethod TFunc_Instances_fl_text_TextFormat_leadingGet::Method = &Instances::fl_text::TextFormat::leadingGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 20, Value> TFunc_Instances_fl_text_TextFormat_leftMarginGet;
// @0x1401483a0
template <> const TFunc_Instances_fl_text_TextFormat_leftMarginGet::TMethod TFunc_Instances_fl_text_TextFormat_leftMarginGet::Method = &Instances::fl_text::TextFormat::leftMarginGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 22, Value> TFunc_Instances_fl_text_TextFormat_letterSpacingGet;
// @0x1401483d0
template <> const TFunc_Instances_fl_text_TextFormat_letterSpacingGet::TMethod TFunc_Instances_fl_text_TextFormat_letterSpacingGet::Method = &Instances::fl_text::TextFormat::letterSpacingGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 24, Value> TFunc_Instances_fl_text_TextFormat_rightMarginGet;
// @0x140148400
template <> const TFunc_Instances_fl_text_TextFormat_rightMarginGet::TMethod TFunc_Instances_fl_text_TextFormat_rightMarginGet::Method = &Instances::fl_text::TextFormat::rightMarginGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 26, Value> TFunc_Instances_fl_text_TextFormat_sizeGet;
// @0x140148430
template <> const TFunc_Instances_fl_text_TextFormat_sizeGet::TMethod TFunc_Instances_fl_text_TextFormat_sizeGet::Method = &Instances::fl_text::TextFormat::sizeGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 28, SPtr<Instances::fl::Array>> TFunc_Instances_fl_text_TextFormat_tabStopsGet;
// @0x140148460
template <> const TFunc_Instances_fl_text_TextFormat_tabStopsGet::TMethod TFunc_Instances_fl_text_TextFormat_tabStopsGet::Method = &Instances::fl_text::TextFormat::tabStopsGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 30, ASString> TFunc_Instances_fl_text_TextFormat_targetGet;
// @0x140148490
template <> const TFunc_Instances_fl_text_TextFormat_targetGet::TMethod TFunc_Instances_fl_text_TextFormat_targetGet::Method = &Instances::fl_text::TextFormat::targetGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 32, Value> TFunc_Instances_fl_text_TextFormat_underlineGet;
// @0x1401484c0
template <> const TFunc_Instances_fl_text_TextFormat_underlineGet::TMethod TFunc_Instances_fl_text_TextFormat_underlineGet::Method = &Instances::fl_text::TextFormat::underlineGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 34, ASString> TFunc_Instances_fl_text_TextFormat_urlGet;
// @0x1401484f0
template <> const TFunc_Instances_fl_text_TextFormat_urlGet::TMethod TFunc_Instances_fl_text_TextFormat_urlGet::Method = &Instances::fl_text::TextFormat::urlGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 12, Value> TFunc_Instances_fl_text_TextFormat_indentGet;
// @0x140148520
template <> const TFunc_Instances_fl_text_TextFormat_indentGet::TMethod TFunc_Instances_fl_text_TextFormat_indentGet::Method = &Instances::fl_text::TextFormat::indentGet;
typedef ThunkFunc0<Instances::fl_text::TextFormat, 14, Value> TFunc_Instances_fl_text_TextFormat_italicGet;
// @0x140148550
template <> const TFunc_Instances_fl_text_TextFormat_italicGet::TMethod TFunc_Instances_fl_text_TextFormat_italicGet::Method = &Instances::fl_text::TextFormat::italicGet;
typedef ThunkFunc0<Instances::fl_text::TextSnapshot, 0, SInt32> TFunc_Instances_fl_text_TextSnapshot_charCountGet;
// @0x140148580
template <> const TFunc_Instances_fl_text_TextSnapshot_charCountGet::TMethod TFunc_Instances_fl_text_TextSnapshot_charCountGet::Method = &Instances::fl_text::TextSnapshot::charCountGet;
typedef ThunkFunc1<Classes::fl_text::Font, 1, const Value, Class*> TFunc_Classes_fl_text_Font_registerFont;
// @0x1401485b0
template <> const TFunc_Classes_fl_text_Font_registerFont::TMethod TFunc_Classes_fl_text_Font_registerFont::Method = &Classes::fl_text::Font::registerFont;
typedef ThunkFunc1<Classes::fl_text::Font, 0, SPtr<Instances::fl::Array>, bool> TFunc_Classes_fl_text_Font_enumerateFonts;
// @0x1401485e0
template <> const TFunc_Classes_fl_text_Font_enumerateFonts::TMethod TFunc_Classes_fl_text_Font_enumerateFonts::Method = &Classes::fl_text::Font::enumerateFonts;
typedef ThunkFunc1<Instances::fl_text::Font, 3, bool, const ASString&> TFunc_Instances_fl_text_Font_hasGlyphs;
// @0x140148610
template <> const TFunc_Instances_fl_text_Font_hasGlyphs::TMethod TFunc_Instances_fl_text_Font_hasGlyphs::Method = &Instances::fl_text::Font::hasGlyphs;
typedef ThunkFunc1<Instances::fl_text::StyleSheet, 2, SPtr<Instances::fl::Object>, const ASString&> TFunc_Instances_fl_text_StyleSheet_getStyle;
// @0x140148640
template <> const TFunc_Instances_fl_text_StyleSheet_getStyle::TMethod TFunc_Instances_fl_text_StyleSheet_getStyle::Method = &Instances::fl_text::StyleSheet::getStyle;
typedef ThunkFunc1<Instances::fl_text::StyleSheet, 3, const Value, const ASString&> TFunc_Instances_fl_text_StyleSheet_parseCSS;
// @0x140148670
template <> const TFunc_Instances_fl_text_StyleSheet_parseCSS::TMethod TFunc_Instances_fl_text_StyleSheet_parseCSS::Method = &Instances::fl_text::StyleSheet::parseCSS;
typedef ThunkFunc1<Instances::fl_text::StyleSheet, 5, SPtr<Instances::fl_text::TextFormat>, const Value&> TFunc_Instances_fl_text_StyleSheet_transform;
// @0x1401486a0
template <> const TFunc_Instances_fl_text_StyleSheet_transform::TMethod TFunc_Instances_fl_text_StyleSheet_transform::Method = &Instances::fl_text::StyleSheet::transform;
typedef ThunkFunc1<Instances::fl_text::TextField, 1, const Value, bool> TFunc_Instances_fl_text_TextField_alwaysShowSelectionSet;
// @0x1401486d0
template <> const TFunc_Instances_fl_text_TextField_alwaysShowSelectionSet::TMethod TFunc_Instances_fl_text_TextField_alwaysShowSelectionSet::Method = &Instances::fl_text::TextField::alwaysShowSelectionSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 3, const Value, const ASString&> TFunc_Instances_fl_text_TextField_antiAliasTypeSet;
// @0x140148700
template <> const TFunc_Instances_fl_text_TextField_antiAliasTypeSet::TMethod TFunc_Instances_fl_text_TextField_antiAliasTypeSet::Method = &Instances::fl_text::TextField::antiAliasTypeSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 5, const Value, const ASString&> TFunc_Instances_fl_text_TextField_autoSizeSet;
// @0x140148730
template <> const TFunc_Instances_fl_text_TextField_autoSizeSet::TMethod TFunc_Instances_fl_text_TextField_autoSizeSet::Method = &Instances::fl_text::TextField::autoSizeSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 7, const Value, bool> TFunc_Instances_fl_text_TextField_backgroundSet;
// @0x140148760
template <> const TFunc_Instances_fl_text_TextField_backgroundSet::TMethod TFunc_Instances_fl_text_TextField_backgroundSet::Method = &Instances::fl_text::TextField::backgroundSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 9, const Value, UInt32> TFunc_Instances_fl_text_TextField_backgroundColorSet;
// @0x140148790
template <> const TFunc_Instances_fl_text_TextField_backgroundColorSet::TMethod TFunc_Instances_fl_text_TextField_backgroundColorSet::Method = &Instances::fl_text::TextField::backgroundColorSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 17, const Value, bool> TFunc_Instances_fl_text_TextField_condenseWhiteSet;
// @0x1401487c0
template <> const TFunc_Instances_fl_text_TextField_condenseWhiteSet::TMethod TFunc_Instances_fl_text_TextField_condenseWhiteSet::Method = &Instances::fl_text::TextField::condenseWhiteSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 19, const Value, Instances::fl_text::TextFormat*> TFunc_Instances_fl_text_TextField_defaultTextFormatSet;
// @0x1401487f0
template <> const TFunc_Instances_fl_text_TextField_defaultTextFormatSet::TMethod TFunc_Instances_fl_text_TextField_defaultTextFormatSet::Method = &Instances::fl_text::TextField::defaultTextFormatSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 21, const Value, bool> TFunc_Instances_fl_text_TextField_displayAsPasswordSet;
// @0x140148820
template <> const TFunc_Instances_fl_text_TextField_displayAsPasswordSet::TMethod TFunc_Instances_fl_text_TextField_displayAsPasswordSet::Method = &Instances::fl_text::TextField::displayAsPasswordSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 23, const Value, bool> TFunc_Instances_fl_text_TextField_embedFontsSet;
// @0x140148850
template <> const TFunc_Instances_fl_text_TextField_embedFontsSet::TMethod TFunc_Instances_fl_text_TextField_embedFontsSet::Method = &Instances::fl_text::TextField::embedFontsSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 25, const Value, const ASString&> TFunc_Instances_fl_text_TextField_gridFitTypeSet;
// @0x140148880
template <> const TFunc_Instances_fl_text_TextField_gridFitTypeSet::TMethod TFunc_Instances_fl_text_TextField_gridFitTypeSet::Method = &Instances::fl_text::TextField::gridFitTypeSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 27, const Value, const ASString&> TFunc_Instances_fl_text_TextField_htmlTextSet;
// @0x1401488b0
template <> const TFunc_Instances_fl_text_TextField_htmlTextSet::TMethod TFunc_Instances_fl_text_TextField_htmlTextSet::Method = &Instances::fl_text::TextField::htmlTextSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 30, const Value, SInt32> TFunc_Instances_fl_text_TextField_maxCharsSet;
// @0x1401488e0
template <> const TFunc_Instances_fl_text_TextField_maxCharsSet::TMethod TFunc_Instances_fl_text_TextField_maxCharsSet::Method = &Instances::fl_text::TextField::maxCharsSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 34, const Value, bool> TFunc_Instances_fl_text_TextField_mouseWheelEnabledSet;
// @0x140148910
template <> const TFunc_Instances_fl_text_TextField_mouseWheelEnabledSet::TMethod TFunc_Instances_fl_text_TextField_mouseWheelEnabledSet::Method = &Instances::fl_text::TextField::mouseWheelEnabledSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 36, const Value, bool> TFunc_Instances_fl_text_TextField_multilineSet;
// @0x140148940
template <> const TFunc_Instances_fl_text_TextField_multilineSet::TMethod TFunc_Instances_fl_text_TextField_multilineSet::Method = &Instances::fl_text::TextField::multilineSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 39, const Value, const ASString&> TFunc_Instances_fl_text_TextField_restrictSet;
// @0x140148970
template <> const TFunc_Instances_fl_text_TextField_restrictSet::TMethod TFunc_Instances_fl_text_TextField_restrictSet::Method = &Instances::fl_text::TextField::restrictSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 41, const Value, SInt32> TFunc_Instances_fl_text_TextField_scrollHSet;
// @0x1401489a0
template <> const TFunc_Instances_fl_text_TextField_scrollHSet::TMethod TFunc_Instances_fl_text_TextField_scrollHSet::Method = &Instances::fl_text::TextField::scrollHSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 43, const Value, SInt32> TFunc_Instances_fl_text_TextField_scrollVSet;
// @0x1401489d0
template <> const TFunc_Instances_fl_text_TextField_scrollVSet::TMethod TFunc_Instances_fl_text_TextField_scrollVSet::Method = &Instances::fl_text::TextField::scrollVSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 45, const Value, bool> TFunc_Instances_fl_text_TextField_selectableSet;
// @0x140148a00
template <> const TFunc_Instances_fl_text_TextField_selectableSet::TMethod TFunc_Instances_fl_text_TextField_selectableSet::Method = &Instances::fl_text::TextField::selectableSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 49, const Value, Value::Number> TFunc_Instances_fl_text_TextField_sharpnessSet;
// @0x140148a30
template <> const TFunc_Instances_fl_text_TextField_sharpnessSet::TMethod TFunc_Instances_fl_text_TextField_sharpnessSet::Method = &Instances::fl_text::TextField::sharpnessSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 51, const Value, Instances::fl_text::StyleSheet*> TFunc_Instances_fl_text_TextField_styleSheetSet;
// @0x140148a60
template <> const TFunc_Instances_fl_text_TextField_styleSheetSet::TMethod TFunc_Instances_fl_text_TextField_styleSheetSet::Method = &Instances::fl_text::TextField::styleSheetSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 53, const Value, const ASString&> TFunc_Instances_fl_text_TextField_textSet;
// @0x140148a90
template <> const TFunc_Instances_fl_text_TextField_textSet::TMethod TFunc_Instances_fl_text_TextField_textSet::Method = &Instances::fl_text::TextField::textSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 55, const Value, UInt32> TFunc_Instances_fl_text_TextField_textColorSet;
// @0x140148ac0
template <> const TFunc_Instances_fl_text_TextField_textColorSet::TMethod TFunc_Instances_fl_text_TextField_textColorSet::Method = &Instances::fl_text::TextField::textColorSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 59, const Value, Value::Number> TFunc_Instances_fl_text_TextField_thicknessSet;
// @0x140148af0
template <> const TFunc_Instances_fl_text_TextField_thicknessSet::TMethod TFunc_Instances_fl_text_TextField_thicknessSet::Method = &Instances::fl_text::TextField::thicknessSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 61, const Value, const ASString&> TFunc_Instances_fl_text_TextField_typeSet;
// @0x140148b20
template <> const TFunc_Instances_fl_text_TextField_typeSet::TMethod TFunc_Instances_fl_text_TextField_typeSet::Method = &Instances::fl_text::TextField::typeSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 63, const Value, bool> TFunc_Instances_fl_text_TextField_useRichTextClipboardSet;
// @0x140148b50
template <> const TFunc_Instances_fl_text_TextField_useRichTextClipboardSet::TMethod TFunc_Instances_fl_text_TextField_useRichTextClipboardSet::Method = &Instances::fl_text::TextField::useRichTextClipboardSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 65, const Value, bool> TFunc_Instances_fl_text_TextField_wordWrapSet;
// @0x140148b80
template <> const TFunc_Instances_fl_text_TextField_wordWrapSet::TMethod TFunc_Instances_fl_text_TextField_wordWrapSet::Method = &Instances::fl_text::TextField::wordWrapSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 66, const Value, const ASString&> TFunc_Instances_fl_text_TextField_appendText;
// @0x140148bb0
template <> const TFunc_Instances_fl_text_TextField_appendText::TMethod TFunc_Instances_fl_text_TextField_appendText::Method = &Instances::fl_text::TextField::appendText;
typedef ThunkFunc1<Instances::fl_text::TextField, 67, SPtr<Instances::fl_geom::Rectangle>, SInt32> TFunc_Instances_fl_text_TextField_getCharBoundaries;
// @0x140148be0
template <> const TFunc_Instances_fl_text_TextField_getCharBoundaries::TMethod TFunc_Instances_fl_text_TextField_getCharBoundaries::Method = &Instances::fl_text::TextField::getCharBoundaries;
typedef ThunkFunc1<Instances::fl_text::TextField, 69, SInt32, SInt32> TFunc_Instances_fl_text_TextField_getFirstCharInParagraph;
// @0x140148c10
template <> const TFunc_Instances_fl_text_TextField_getFirstCharInParagraph::TMethod TFunc_Instances_fl_text_TextField_getFirstCharInParagraph::Method = &Instances::fl_text::TextField::getFirstCharInParagraph;
typedef ThunkFunc1<Instances::fl_text::TextField, 70, SPtr<Instances::fl_display::DisplayObject>, const ASString&> TFunc_Instances_fl_text_TextField_getImageReference;
// @0x140148c40
template <> const TFunc_Instances_fl_text_TextField_getImageReference::TMethod TFunc_Instances_fl_text_TextField_getImageReference::Method = &Instances::fl_text::TextField::getImageReference;
typedef ThunkFunc1<Instances::fl_text::TextField, 72, SInt32, SInt32> TFunc_Instances_fl_text_TextField_getLineIndexOfChar;
// @0x140148c70
template <> const TFunc_Instances_fl_text_TextField_getLineIndexOfChar::TMethod TFunc_Instances_fl_text_TextField_getLineIndexOfChar::Method = &Instances::fl_text::TextField::getLineIndexOfChar;
typedef ThunkFunc1<Instances::fl_text::TextField, 73, SInt32, SInt32> TFunc_Instances_fl_text_TextField_getLineLength;
// @0x140148ca0
template <> const TFunc_Instances_fl_text_TextField_getLineLength::TMethod TFunc_Instances_fl_text_TextField_getLineLength::Method = &Instances::fl_text::TextField::getLineLength;
typedef ThunkFunc1<Instances::fl_text::TextField, 74, SPtr<Instances::fl_text::TextLineMetrics>, SInt32> TFunc_Instances_fl_text_TextField_getLineMetrics;
// @0x140148cd0
template <> const TFunc_Instances_fl_text_TextField_getLineMetrics::TMethod TFunc_Instances_fl_text_TextField_getLineMetrics::Method = &Instances::fl_text::TextField::getLineMetrics;
typedef ThunkFunc1<Instances::fl_text::TextField, 75, SInt32, SInt32> TFunc_Instances_fl_text_TextField_getLineOffset;
// @0x140148d00
template <> const TFunc_Instances_fl_text_TextField_getLineOffset::TMethod TFunc_Instances_fl_text_TextField_getLineOffset::Method = &Instances::fl_text::TextField::getLineOffset;
typedef ThunkFunc1<Instances::fl_text::TextField, 76, ASString, SInt32> TFunc_Instances_fl_text_TextField_getLineText;
// @0x140148d30
template <> const TFunc_Instances_fl_text_TextField_getLineText::TMethod TFunc_Instances_fl_text_TextField_getLineText::Method = &Instances::fl_text::TextField::getLineText;
typedef ThunkFunc1<Instances::fl_text::TextField, 77, SInt32, SInt32> TFunc_Instances_fl_text_TextField_getParagraphLength;
// @0x140148d60
template <> const TFunc_Instances_fl_text_TextField_getParagraphLength::TMethod TFunc_Instances_fl_text_TextField_getParagraphLength::Method = &Instances::fl_text::TextField::getParagraphLength;
typedef ThunkFunc1<Instances::fl_text::TextField, 79, const Value, const ASString&> TFunc_Instances_fl_text_TextField_replaceSelectedText;
// @0x140148d90
template <> const TFunc_Instances_fl_text_TextField_replaceSelectedText::TMethod TFunc_Instances_fl_text_TextField_replaceSelectedText::Method = &Instances::fl_text::TextField::replaceSelectedText;
typedef ThunkFunc1<Instances::fl_text::TextField, 11, const Value, bool> TFunc_Instances_fl_text_TextField_borderSet;
// @0x140148dc0
template <> const TFunc_Instances_fl_text_TextField_borderSet::TMethod TFunc_Instances_fl_text_TextField_borderSet::Method = &Instances::fl_text::TextField::borderSet;
typedef ThunkFunc1<Instances::fl_text::TextField, 13, const Value, UInt32> TFunc_Instances_fl_text_TextField_borderColorSet;
// @0x140148df0
template <> const TFunc_Instances_fl_text_TextField_borderColorSet::TMethod TFunc_Instances_fl_text_TextField_borderColorSet::Method = &Instances::fl_text::TextField::borderColorSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 1, const Value, const ASString&> TFunc_Instances_fl_text_TextFormat_alignSet;
// @0x140148e20
template <> const TFunc_Instances_fl_text_TextFormat_alignSet::TMethod TFunc_Instances_fl_text_TextFormat_alignSet::Method = &Instances::fl_text::TextFormat::alignSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 3, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_blockIndentSet;
// @0x140148e50
template <> const TFunc_Instances_fl_text_TextFormat_blockIndentSet::TMethod TFunc_Instances_fl_text_TextFormat_blockIndentSet::Method = &Instances::fl_text::TextFormat::blockIndentSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 5, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_boldSet;
// @0x140148e80
template <> const TFunc_Instances_fl_text_TextFormat_boldSet::TMethod TFunc_Instances_fl_text_TextFormat_boldSet::Method = &Instances::fl_text::TextFormat::boldSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 7, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_bulletSet;
// @0x140148eb0
template <> const TFunc_Instances_fl_text_TextFormat_bulletSet::TMethod TFunc_Instances_fl_text_TextFormat_bulletSet::Method = &Instances::fl_text::TextFormat::bulletSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 9, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_colorSet;
// @0x140148ee0
template <> const TFunc_Instances_fl_text_TextFormat_colorSet::TMethod TFunc_Instances_fl_text_TextFormat_colorSet::Method = &Instances::fl_text::TextFormat::colorSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 17, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_kerningSet;
// @0x140148f10
template <> const TFunc_Instances_fl_text_TextFormat_kerningSet::TMethod TFunc_Instances_fl_text_TextFormat_kerningSet::Method = &Instances::fl_text::TextFormat::kerningSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 19, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_leadingSet;
// @0x140148f40
template <> const TFunc_Instances_fl_text_TextFormat_leadingSet::TMethod TFunc_Instances_fl_text_TextFormat_leadingSet::Method = &Instances::fl_text::TextFormat::leadingSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 21, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_leftMarginSet;
// @0x140148f70
template <> const TFunc_Instances_fl_text_TextFormat_leftMarginSet::TMethod TFunc_Instances_fl_text_TextFormat_leftMarginSet::Method = &Instances::fl_text::TextFormat::leftMarginSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 23, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_letterSpacingSet;
// @0x140148fa0
template <> const TFunc_Instances_fl_text_TextFormat_letterSpacingSet::TMethod TFunc_Instances_fl_text_TextFormat_letterSpacingSet::Method = &Instances::fl_text::TextFormat::letterSpacingSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 25, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_rightMarginSet;
// @0x140148fd0
template <> const TFunc_Instances_fl_text_TextFormat_rightMarginSet::TMethod TFunc_Instances_fl_text_TextFormat_rightMarginSet::Method = &Instances::fl_text::TextFormat::rightMarginSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 27, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_sizeSet;
// @0x140149000
template <> const TFunc_Instances_fl_text_TextFormat_sizeSet::TMethod TFunc_Instances_fl_text_TextFormat_sizeSet::Method = &Instances::fl_text::TextFormat::sizeSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 29, const Value, Instances::fl::Array*> TFunc_Instances_fl_text_TextFormat_tabStopsSet;
// @0x140149030
template <> const TFunc_Instances_fl_text_TextFormat_tabStopsSet::TMethod TFunc_Instances_fl_text_TextFormat_tabStopsSet::Method = &Instances::fl_text::TextFormat::tabStopsSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 31, const Value, const ASString&> TFunc_Instances_fl_text_TextFormat_targetSet;
// @0x140149060
template <> const TFunc_Instances_fl_text_TextFormat_targetSet::TMethod TFunc_Instances_fl_text_TextFormat_targetSet::Method = &Instances::fl_text::TextFormat::targetSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 33, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_underlineSet;
// @0x140149090
template <> const TFunc_Instances_fl_text_TextFormat_underlineSet::TMethod TFunc_Instances_fl_text_TextFormat_underlineSet::Method = &Instances::fl_text::TextFormat::underlineSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 35, const Value, const ASString&> TFunc_Instances_fl_text_TextFormat_urlSet;
// @0x1401490c0
template <> const TFunc_Instances_fl_text_TextFormat_urlSet::TMethod TFunc_Instances_fl_text_TextFormat_urlSet::Method = &Instances::fl_text::TextFormat::urlSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 11, const Value, const ASString&> TFunc_Instances_fl_text_TextFormat_fontSet;
// @0x1401490f0
template <> const TFunc_Instances_fl_text_TextFormat_fontSet::TMethod TFunc_Instances_fl_text_TextFormat_fontSet::Method = &Instances::fl_text::TextFormat::fontSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 13, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_indentSet;
// @0x140149120
template <> const TFunc_Instances_fl_text_TextFormat_indentSet::TMethod TFunc_Instances_fl_text_TextFormat_indentSet::Method = &Instances::fl_text::TextFormat::indentSet;
typedef ThunkFunc1<Instances::fl_text::TextFormat, 15, const Value, const Value&> TFunc_Instances_fl_text_TextFormat_italicSet;
// @0x140149150
template <> const TFunc_Instances_fl_text_TextFormat_italicSet::TMethod TFunc_Instances_fl_text_TextFormat_italicSet::Method = &Instances::fl_text::TextFormat::italicSet;
typedef ThunkFunc1<Instances::fl_text::TextSnapshot, 3, ASString, bool> TFunc_Instances_fl_text_TextSnapshot_getSelectedText;
// @0x140149180
template <> const TFunc_Instances_fl_text_TextSnapshot_getSelectedText::TMethod TFunc_Instances_fl_text_TextSnapshot_getSelectedText::Method = &Instances::fl_text::TextSnapshot::getSelectedText;
typedef ThunkFunc1<Instances::fl_text::TextSnapshot, 7, const Value, UInt32> TFunc_Instances_fl_text_TextSnapshot_setSelectColor;
// @0x1401491b0
template <> const TFunc_Instances_fl_text_TextSnapshot_setSelectColor::TMethod TFunc_Instances_fl_text_TextSnapshot_setSelectColor::Method = &Instances::fl_text::TextSnapshot::setSelectColor;
typedef ThunkFunc2<Instances::fl_text::StyleSheet, 4, const Value, const ASString&, const Value&> TFunc_Instances_fl_text_StyleSheet_setStyle;
// @0x1401491e0
template <> const TFunc_Instances_fl_text_StyleSheet_setStyle::TMethod TFunc_Instances_fl_text_StyleSheet_setStyle::Method = &Instances::fl_text::StyleSheet::setStyle;
typedef ThunkFunc2<Instances::fl_text::TextField, 68, SInt32, Value::Number, Value::Number> TFunc_Instances_fl_text_TextField_getCharIndexAtPoint;
// @0x140149210
template <> const TFunc_Instances_fl_text_TextField_getCharIndexAtPoint::TMethod TFunc_Instances_fl_text_TextField_getCharIndexAtPoint::Method = &Instances::fl_text::TextField::getCharIndexAtPoint;
typedef ThunkFunc2<Instances::fl_text::TextField, 71, SInt32, Value::Number, Value::Number> TFunc_Instances_fl_text_TextField_getLineIndexAtPoint;
// @0x140149240
template <> const TFunc_Instances_fl_text_TextField_getLineIndexAtPoint::TMethod TFunc_Instances_fl_text_TextField_getLineIndexAtPoint::Method = &Instances::fl_text::TextField::getLineIndexAtPoint;
typedef ThunkFunc2<Instances::fl_text::TextField, 78, SPtr<Instances::fl_text::TextFormat>, SInt32, SInt32> TFunc_Instances_fl_text_TextField_getTextFormat;
// @0x140149270
template <> const TFunc_Instances_fl_text_TextField_getTextFormat::TMethod TFunc_Instances_fl_text_TextField_getTextFormat::Method = &Instances::fl_text::TextField::getTextFormat;
typedef ThunkFunc2<Instances::fl_text::TextField, 81, const Value, SInt32, SInt32> TFunc_Instances_fl_text_TextField_setSelection;
// @0x1401492a0
template <> const TFunc_Instances_fl_text_TextField_setSelection::TMethod TFunc_Instances_fl_text_TextField_setSelection::Method = &Instances::fl_text::TextField::setSelection;
typedef ThunkFunc2<Instances::fl_text::TextSnapshot, 2, bool, SInt32, SInt32> TFunc_Instances_fl_text_TextSnapshot_getSelected;
// @0x1401492d0
template <> const TFunc_Instances_fl_text_TextSnapshot_getSelected::TMethod TFunc_Instances_fl_text_TextSnapshot_getSelected::Method = &Instances::fl_text::TextSnapshot::getSelected;
typedef ThunkFunc2<Instances::fl_text::TextSnapshot, 5, SPtr<Instances::fl::Array>, SInt32, SInt32> TFunc_Instances_fl_text_TextSnapshot_getTextRunInfo;
// @0x140149300
template <> const TFunc_Instances_fl_text_TextSnapshot_getTextRunInfo::TMethod TFunc_Instances_fl_text_TextSnapshot_getTextRunInfo::Method = &Instances::fl_text::TextSnapshot::getTextRunInfo;
typedef ThunkFunc3<Instances::fl_text::TextField, 80, const Value, SInt32, SInt32, const ASString&> TFunc_Instances_fl_text_TextField_replaceText;
// @0x140149330
template <> const TFunc_Instances_fl_text_TextField_replaceText::TMethod TFunc_Instances_fl_text_TextField_replaceText::Method = &Instances::fl_text::TextField::replaceText;
typedef ThunkFunc3<Instances::fl_text::TextField, 82, const Value, Instances::fl_text::TextFormat*, SInt32, SInt32> TFunc_Instances_fl_text_TextField_setTextFormat;
// @0x140149360
template <> const TFunc_Instances_fl_text_TextField_setTextFormat::TMethod TFunc_Instances_fl_text_TextField_setTextFormat::Method = &Instances::fl_text::TextField::setTextFormat;
typedef ThunkFunc3<Instances::fl_text::TextSnapshot, 1, SInt32, SInt32, const ASString&, bool> TFunc_Instances_fl_text_TextSnapshot_findText;
// @0x140149390
template <> const TFunc_Instances_fl_text_TextSnapshot_findText::TMethod TFunc_Instances_fl_text_TextSnapshot_findText::Method = &Instances::fl_text::TextSnapshot::findText;
typedef ThunkFunc3<Instances::fl_text::TextSnapshot, 4, ASString, SInt32, SInt32, bool> TFunc_Instances_fl_text_TextSnapshot_getText;
// @0x1401493c0
template <> const TFunc_Instances_fl_text_TextSnapshot_getText::TMethod TFunc_Instances_fl_text_TextSnapshot_getText::Method = &Instances::fl_text::TextSnapshot::getText;
typedef ThunkFunc3<Instances::fl_text::TextSnapshot, 6, Value::Number, Value::Number, Value::Number, Value::Number> TFunc_Instances_fl_text_TextSnapshot_hitTestTextNearPos;
// @0x1401493f0
template <> const TFunc_Instances_fl_text_TextSnapshot_hitTestTextNearPos::TMethod TFunc_Instances_fl_text_TextSnapshot_hitTestTextNearPos::Method = &Instances::fl_text::TextSnapshot::hitTestTextNearPos;
typedef ThunkFunc3<Instances::fl_text::TextSnapshot, 8, const Value, SInt32, SInt32, bool> TFunc_Instances_fl_text_TextSnapshot_setSelected;
// @0x140149420
template <> const TFunc_Instances_fl_text_TextSnapshot_setSelected::TMethod TFunc_Instances_fl_text_TextSnapshot_setSelected::Method = &Instances::fl_text::TextSnapshot::setSelected;
typedef ThunkFunc0<Instances::fl_ui::ContextMenu, 2, SPtr<Instances::fl::Array>> TFunc_Instances_fl_ui_ContextMenu_customItemsGet;
// @0x140149450
template <> const TFunc_Instances_fl_ui_ContextMenu_customItemsGet::TMethod TFunc_Instances_fl_ui_ContextMenu_customItemsGet::Method = &Instances::fl_ui::ContextMenu::customItemsGet;
typedef ThunkFunc0<Instances::fl_ui::ContextMenu, 900, SPtr<Instances::fl_display::NativeMenu>> TFunc_Instances_fl_ui_ContextMenu_clone;
// @0x140149480
template <> const TFunc_Instances_fl_ui_ContextMenu_clone::TMethod TFunc_Instances_fl_ui_ContextMenu_clone::Method = &Instances::fl_ui::ContextMenu::clone;
typedef ThunkFunc0<Instances::fl_ui::ContextMenu, 4, const Value> TFunc_Instances_fl_ui_ContextMenu_hideBuiltInItems;
// @0x1401494b0
template <> const TFunc_Instances_fl_ui_ContextMenu_hideBuiltInItems::TMethod TFunc_Instances_fl_ui_ContextMenu_hideBuiltInItems::Method = &Instances::fl_ui::ContextMenu::hideBuiltInItems;
typedef ThunkFunc0<Instances::fl_ui::ContextMenu, 0, SPtr<Instances::fl_ui::ContextMenuBuiltInItems>> TFunc_Instances_fl_ui_ContextMenu_builtInItemsGet;
// @0x1401494e0
template <> const TFunc_Instances_fl_ui_ContextMenu_builtInItemsGet::TMethod TFunc_Instances_fl_ui_ContextMenu_builtInItemsGet::Method = &Instances::fl_ui::ContextMenu::builtInItemsGet;
typedef ThunkFunc0<Classes::fl_ui::Keyboard, 1, bool> TFunc_Classes_fl_ui_Keyboard_numLockGet;
// @0x140149510
template <> const TFunc_Classes_fl_ui_Keyboard_numLockGet::TMethod TFunc_Classes_fl_ui_Keyboard_numLockGet::Method = &Classes::fl_ui::Keyboard::numLockGet;
typedef ThunkFunc0<Classes::fl_ui::Keyboard, 2, bool> TFunc_Classes_fl_ui_Keyboard_isAccessible;
// @0x140149540
template <> const TFunc_Classes_fl_ui_Keyboard_isAccessible::TMethod TFunc_Classes_fl_ui_Keyboard_isAccessible::Method = &Classes::fl_ui::Keyboard::isAccessible;
typedef ThunkFunc0<Classes::fl_ui::Keyboard, 0, bool> TFunc_Classes_fl_ui_Keyboard_capsLockGet;
// @0x140149570
template <> const TFunc_Classes_fl_ui_Keyboard_capsLockGet::TMethod TFunc_Classes_fl_ui_Keyboard_capsLockGet::Method = &Classes::fl_ui::Keyboard::capsLockGet;
typedef ThunkFunc0<Classes::fl_ui::Mouse, 1, ASString> TFunc_Classes_fl_ui_Mouse_cursorGet;
// @0x1401495a0
template <> const TFunc_Classes_fl_ui_Mouse_cursorGet::TMethod TFunc_Classes_fl_ui_Mouse_cursorGet::Method = &Classes::fl_ui::Mouse::cursorGet;
typedef ThunkFunc0<Classes::fl_ui::Mouse, 2, const Value> TFunc_Classes_fl_ui_Mouse_hide;
// @0x1401495d0
template <> const TFunc_Classes_fl_ui_Mouse_hide::TMethod TFunc_Classes_fl_ui_Mouse_hide::Method = &Classes::fl_ui::Mouse::hide;
typedef ThunkFunc0<Classes::fl_ui::Mouse, 3, const Value> TFunc_Classes_fl_ui_Mouse_show;
// @0x140149600
template <> const TFunc_Classes_fl_ui_Mouse_show::TMethod TFunc_Classes_fl_ui_Mouse_show::Method = &Classes::fl_ui::Mouse::show;
typedef ThunkFunc0<Classes::fl_ui::Multitouch, 2, SInt32> TFunc_Classes_fl_ui_Multitouch_maxTouchPointsGet;
// @0x140149630
template <> const TFunc_Classes_fl_ui_Multitouch_maxTouchPointsGet::TMethod TFunc_Classes_fl_ui_Multitouch_maxTouchPointsGet::Method = &Classes::fl_ui::Multitouch::maxTouchPointsGet;
typedef ThunkFunc0<Classes::fl_ui::Multitouch, 3, SPtr<Instances::fl_vec::Vector_String>> TFunc_Classes_fl_ui_Multitouch_supportedGesturesGet;
// @0x140149660
template <> const TFunc_Classes_fl_ui_Multitouch_supportedGesturesGet::TMethod TFunc_Classes_fl_ui_Multitouch_supportedGesturesGet::Method = &Classes::fl_ui::Multitouch::supportedGesturesGet;
typedef ThunkFunc0<Classes::fl_ui::Multitouch, 4, bool> TFunc_Classes_fl_ui_Multitouch_supportsGestureEventsGet;
// @0x140149690
template <> const TFunc_Classes_fl_ui_Multitouch_supportsGestureEventsGet::TMethod TFunc_Classes_fl_ui_Multitouch_supportsGestureEventsGet::Method = &Classes::fl_ui::Multitouch::supportsGestureEventsGet;
typedef ThunkFunc0<Classes::fl_ui::Multitouch, 5, bool> TFunc_Classes_fl_ui_Multitouch_supportsTouchEventsGet;
// @0x1401496c0
template <> const TFunc_Classes_fl_ui_Multitouch_supportsTouchEventsGet::TMethod TFunc_Classes_fl_ui_Multitouch_supportsTouchEventsGet::Method = &Classes::fl_ui::Multitouch::supportsTouchEventsGet;
typedef ThunkFunc0<Classes::fl_ui::Multitouch, 0, ASString> TFunc_Classes_fl_ui_Multitouch_inputModeGet;
// @0x1401496f0
template <> const TFunc_Classes_fl_ui_Multitouch_inputModeGet::TMethod TFunc_Classes_fl_ui_Multitouch_inputModeGet::Method = &Classes::fl_ui::Multitouch::inputModeGet;
typedef ThunkFunc1<Instances::fl_ui::ContextMenu, 1, const Value, Instances::fl_ui::ContextMenuBuiltInItems*> TFunc_Instances_fl_ui_ContextMenu_builtInItemsSet;
// @0x140149720
template <> const TFunc_Instances_fl_ui_ContextMenu_builtInItemsSet::TMethod TFunc_Instances_fl_ui_ContextMenu_builtInItemsSet::Method = &Instances::fl_ui::ContextMenu::builtInItemsSet;
typedef ThunkFunc1<Instances::fl_ui::ContextMenu, 3, const Value, Instances::fl::Array*> TFunc_Instances_fl_ui_ContextMenu_customItemsSet;
// @0x140149750
template <> const TFunc_Instances_fl_ui_ContextMenu_customItemsSet::TMethod TFunc_Instances_fl_ui_ContextMenu_customItemsSet::Method = &Instances::fl_ui::ContextMenu::customItemsSet;
typedef ThunkFunc1<Classes::fl_ui::Mouse, 0, const Value, const ASString&> TFunc_Classes_fl_ui_Mouse_cursorSet;
// @0x140149780
template <> const TFunc_Classes_fl_ui_Mouse_cursorSet::TMethod TFunc_Classes_fl_ui_Mouse_cursorSet::Method = &Classes::fl_ui::Mouse::cursorSet;
typedef ThunkFunc1<Classes::fl_ui::Multitouch, 1, const Value, const ASString&> TFunc_Classes_fl_ui_Multitouch_inputModeSet;
// @0x1401497b0
template <> const TFunc_Classes_fl_ui_Multitouch_inputModeSet::TMethod TFunc_Classes_fl_ui_Multitouch_inputModeSet::Method = &Classes::fl_ui::Multitouch::inputModeSet;
typedef ThunkFunc0<Classes::fl_utils::ByteArray, 1, UInt32> TFunc_Classes_fl_utils_ByteArray_defaultObjectEncodingGet;
// @0x1401497e0
template <> const TFunc_Classes_fl_utils_ByteArray_defaultObjectEncodingGet::TMethod TFunc_Classes_fl_utils_ByteArray_defaultObjectEncodingGet::Method = &Classes::fl_utils::ByteArray::defaultObjectEncodingGet;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 1, ASString> TFunc_Instances_fl_utils_ByteArray_endianGet;
// @0x140149810
template <> const TFunc_Instances_fl_utils_ByteArray_endianGet::TMethod TFunc_Instances_fl_utils_ByteArray_endianGet::Method = &Instances::fl_utils::ByteArray::endianGet;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 3, UInt32> TFunc_Instances_fl_utils_ByteArray_lengthGet;
// @0x140149840
template <> const TFunc_Instances_fl_utils_ByteArray_lengthGet::TMethod TFunc_Instances_fl_utils_ByteArray_lengthGet::Method = &Instances::fl_utils::ByteArray::lengthGet;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 5, UInt32> TFunc_Instances_fl_utils_ByteArray_objectEncodingGet;
// @0x140149870
template <> const TFunc_Instances_fl_utils_ByteArray_objectEncodingGet::TMethod TFunc_Instances_fl_utils_ByteArray_objectEncodingGet::Method = &Instances::fl_utils::ByteArray::objectEncodingGet;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 7, UInt32> TFunc_Instances_fl_utils_ByteArray_positionGet;
// @0x1401498a0
template <> const TFunc_Instances_fl_utils_ByteArray_positionGet::TMethod TFunc_Instances_fl_utils_ByteArray_positionGet::Method = &Instances::fl_utils::ByteArray::positionGet;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 10, bool> TFunc_Instances_fl_utils_ByteArray_readBoolean;
// @0x1401498d0
template <> const TFunc_Instances_fl_utils_ByteArray_readBoolean::TMethod TFunc_Instances_fl_utils_ByteArray_readBoolean::Method = &Instances::fl_utils::ByteArray::readBoolean;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 0, UInt32> TFunc_Instances_fl_utils_ByteArray_bytesAvailableGet;
// @0x140149900
template <> const TFunc_Instances_fl_utils_ByteArray_bytesAvailableGet::TMethod TFunc_Instances_fl_utils_ByteArray_bytesAvailableGet::Method = &Instances::fl_utils::ByteArray::bytesAvailableGet;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 17, Value> TFunc_Instances_fl_utils_ByteArray_readObject;
// @0x140149930
template <> const TFunc_Instances_fl_utils_ByteArray_readObject::TMethod TFunc_Instances_fl_utils_ByteArray_readObject::Method = &Instances::fl_utils::ByteArray::readObject;
typedef ThunkFunc0<Instances::fl_utils::ByteArray, 18, SInt32> TFunc_Instances_fl_utils_ByteArray_readShort;
// @0x140149960
template <> const TFunc_Instances_fl_utils_ByteArray_readShort::TMethod TFunc_Instances_fl_utils_ByteArray_readShort::Method = &Instances::fl_utils::ByteArray::readShort;

}}} // namespace Scaleform::GFx::AS3

