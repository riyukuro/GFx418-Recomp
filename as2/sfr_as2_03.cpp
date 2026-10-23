// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 constructors, destructors and
// assignments of the script values, objects and prototypes (the out-of-line copies the unity build emitted).
// MS2-UNIT: sfr_as2_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142923cb0-0x142923dd0 .text$mn
// MS2-RANGE: 0x1429237f0-0x142923a90 .text$mn
// MS2-RANGE: 0x1429267a0-0x142926a00 .text$mn
// MS2-RANGE: 0x142923e70-0x142923f30 .text$mn
// MS2-RANGE: 0x142923fd0-0x142924040 .text$mn
// MS2-RANGE: 0x1429181f0-0x142918270 .text$mn
// MS2-RANGE: 0x142925350-0x1429253d0 .text$mn
// MS2-RANGE: 0x1429241f0-0x142924490 .text$mn
// MS2-RANGE: 0x142924520-0x142924d20 .text$mn
// MS2-RANGE: 0x142925ae0-0x142925be0 .text$mn
// MS2-RANGE: 0x142926100-0x142926190 .text$mn
// MS2-RANGE: 0x14291f670-0x14291f8d0 .text$mn
// MS2-RANGE: 0x142919d70-0x142919da0 .text$mn
// MS2-RANGE: 0x142919df0-0x142919ee0 .text$mn
// MS2-RANGE: 0x142917bf0-0x142917c90 .text$mn
// MS2-RANGE: 0x142918d10-0x142918d90 .text$mn
// MS2-RANGE: 0x1429197b0-0x142919830 .text$mn
// MS2-RANGE: 0x14291aaf0-0x14291ab70 .text$mn
// MS2-RANGE: 0x14291b750-0x14291b7d0 .text$mn
// MS2-RANGE: 0x14291c010-0x14291c090 .text$mn
// MS2-RANGE: 0x14291cd60-0x14291cde0 .text$mn
// MS2-RANGE: 0x1429184e0-0x142918580 .text$mn
// MS2-RANGE: 0x142919060-0x142919100 .text$mn
// MS2-RANGE: 0x142919980-0x142919a00 .text$mn
// MS2-RANGE: 0x14291b470-0x14291b510 .text$mn
// MS2-RANGE: 0x14291c1c0-0x14291c240 .text$mn
// MS2-RANGE: 0x14291ed40-0x14291edc0 .text$mn
// MS2-RANGE: 0x14291f8e0-0x14291f980 .text$mn
// MS2-RANGE: 0x14291fb70-0x14291fc10 .text$mn
// MS2-RANGE: 0x142920790-0x142920830 .text$mn
// MS2-RANGE: 0x142920d70-0x142920e10 .text$mn
// MS2-RANGE: 0x142921110-0x142921190 .text$mn
// MS2-RANGE: 0x142921480-0x142921520 .text$mn
// MS2-RANGE: 0x142922650-0x1429226d0 .text$mn
// MS2-RANGE: 0x14291c090-0x14291c0b0 .text$mn
// MS2-RANGE: 0x142919a00-0x142919c00 .text$mn
// MS2-RANGE: 0x142918dd0-0x142918ef0 .text$mn
// MS2-RANGE: 0x1429196c0-0x1429197b0 .text$mn
// MS2-RANGE: 0x142919860-0x142919980 .text$mn
// MS2-RANGE: 0x14291ac10-0x14291ad30 .text$mn
// MS2-RANGE: 0x14291b810-0x14291b930 .text$mn
// MS2-RANGE: 0x14291ce20-0x14291cf40 .text$mn
// MS2-RANGE: 0x142917c90-0x142917d80 .text$mn
// MS2-RANGE: 0x142918580-0x142918690 .text$mn
// MS2-RANGE: 0x14291bd50-0x14291be60 .text$mn
// MS2-RANGE: 0x14291dbe0-0x14291dcf0 .text$mn
// MS2-RANGE: 0x14291e6a0-0x14291e790 .text$mn
// MS2-RANGE: 0x14291e830-0x14291e940 .text$mn
// MS2-RANGE: 0x14291eb90-0x14291eca0 .text$mn
// MS2-RANGE: 0x142920600-0x142920710 .text$mn
// MS2-RANGE: 0x142920c50-0x142920d60 .text$mn
// MS2-RANGE: 0x142917ed0-0x1429180c0 .text$mn
// MS2-RANGE: 0x14291f430-0x14291f540 .text$mn
// MS2-RANGE: 0x14291e1a0-0x14291e210 .text$mn
// MS2-RANGE: 0x14291eb20-0x14291eb90 .text$mn
// MS2-RANGE: 0x1429204d0-0x142920540 .text$mn
// MS2-RANGE: 0x142918470-0x1429184e0 .text$mn
// MS2-RANGE: 0x14291bbd0-0x14291bc40 .text$mn
// MS2-RANGE: 0x142920710-0x142920790 .text$mn
// MS2-RANGE: 0x14291aee0-0x14291af50 .text$mn
// MS2-RANGE: 0x14291b510-0x14291b650 .text$mn
// MS2-RANGE: 0x14291e790-0x14291e830 .text$mn
// MS2-RANGE: 0x14291eca0-0x14291ed40 .text$mn
// MS2-RANGE: 0x14291ad30-0x14291adc0 .text$mn
// MS2-RANGE: 0x142920ea0-0x142920fc0 .text$mn
// MS2-RANGE: 0x142920be0-0x142920c50 .text$mn
// MS2-RANGE: 0x1429231e0-0x142923250 .text$mn
// MS2-RANGE: 0x142921520-0x1429215f0 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x14291c090
FunctionObject::FunctionObject(ASStringContext* psc)
    : Object(psc)
{
}

// @0x14291f670
Object::Object(ASRefCountCollector* pcc)
    : ASRefCountBase<Object>(pcc), pWatchpoints(0), ArePropertiesSet(false),
      IsListenerSet(false)
{
    pProto = 0;
}

// @0x14291f6f0
SF_NOINLINE Object::Object(ASStringContext* psc)
    : ASRefCountBase<Object>(psc->GetGC()), pWatchpoints(0), ArePropertiesSet(false),
      IsListenerSet(false)
{
    pProto = 0;
}

// @0x14291f790
Object::Object(ASStringContext* psc, Object* pprototype)
    : ASRefCountBase<Object>(psc->GetGC()), pWatchpoints(0), ArePropertiesSet(false),
      IsListenerSet(false)
{
    Set__proto__(psc, pprototype);
}

// @0x14291f810
Object::Object(Environment* penv)
    : ASRefCountBase<Object>(penv->GetCollector()), pWatchpoints(0), ArePropertiesSet(false),
      IsListenerSet(false)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Object));
}

// @0x142919d70
CFunctionObject::CFunctionObject(ASStringContext* psc)
    : FunctionObject(psc), pFunction(0)
{
}

// @0x142919df0
CFunctionObject::CFunctionObject(ASStringContext* psc, CFunctionPtr func)
    : FunctionObject(psc), pFunction(func)
{
    Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_Function));
}

// @0x142919e70
CFunctionObject::CFunctionObject(ASStringContext* psc, Object* pprototype, CFunctionPtr func)
    : FunctionObject(psc), pFunction(func)
{
    Set__proto__(psc, pprototype);
}

// @0x1429184e0
AsBroadcasterCtorFunction::AsBroadcasterCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x142919060
BitmapDataCtorFunction::BitmapDataCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x142919980
BooleanCtorFunction::BooleanCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x14291b470
DateCtorFunction::DateCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x14291c1c0
GASLoadVarsLoaderCtorFunction::GASLoadVarsLoaderCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x14291ed40
MovieClipLoaderCtorFunction::MovieClipLoaderCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x14291f8e0
ObjectCtorFunction::ObjectCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, ObjectProto::GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x14291fb70
PointCtorFunction::PointCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x142920790
SharedObjectCtorFunction::SharedObjectCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x142920d70
StringCtorFunction::StringCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x142921110
StyleSheetCtorFunction::StyleSheetCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x142921480
TextFieldCtorFunction::TextFieldCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x142922650
TextFormatCtorFunction::TextFormatCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x142917bf0
AmpMarkerCtorFunction::AmpMarkerCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum);
}

// @0x142918d10
BevelFilterCtorFunction::BevelFilterCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x1429197b0
BlurFilterCtorFunction::BlurFilterCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x14291aaf0
ColorMatrixFilterCtorFunction::ColorMatrixFilterCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x14291b750
DropShadowFilterCtorFunction::DropShadowFilterCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x14291c010
FunctionCtorFunction::FunctionCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, FunctionProto::GlobalCtor)
{
}

// @0x14291cd60
GlowFilterCtorFunction::GlowFilterCtorFunction(ASStringContext* psc)
    : CFunctionObject(psc, GlobalCtor)
{
}

// @0x142919a00
BooleanObject::BooleanObject(Environment* penv)
    : Object(penv), BValue(false)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Boolean));
}

// @0x142919a70
BooleanObject::BooleanObject(Environment* penv, bool v)
    : Object(penv), BValue(v)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Boolean));
}

// @0x142917c90
AmpMarkerProto::AmpMarkerProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<AmpMarker>(psc, pprototype, constructor)
{
}

// @0x142918580
AsBroadcasterProto::AsBroadcasterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<AsBroadcaster>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x14291bd50
ExternalInterfaceProto::ExternalInterfaceProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<ExternalInterface>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x14291dbe0
KeyProto::KeyProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<KeyObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x14291e6a0
MathProto::MathProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<Math>(psc, pprototype, constructor)
{
}

// @0x14291e830
MatrixProto::MatrixProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<MatrixObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x14291eb90
MouseProto::MouseProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<MouseObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x142920600
SelectionProto::SelectionProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<Selection>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x142920c50
StageProto::StageProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<StageObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x142918dd0
BevelFilterProto::BevelFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<BevelFilterObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags());
}

// @0x1429196c0
BitmapFilterProto::BitmapFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<BitmapFilterObject>(psc, pprototype, constructor)
{
}

// @0x142919860
BlurFilterProto::BlurFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<BlurFilterObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags());
}

// @0x14291ac10
ColorMatrixFilterProto::ColorMatrixFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<ColorMatrixFilterObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags());
}

// @0x14291b810
DropShadowFilterProto::DropShadowFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<DropShadowFilterObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags());
}

// @0x14291ce20
GlowFilterProto::GlowFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<GlowFilterObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags());
}

// @0x142919af0
BooleanProto::BooleanProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<BooleanObject>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x142917ed0
ArrayObject::ArrayObject(ASStringContext* psc, Object* pprototype)
    : Object(psc), LogPtr(0), RecursionCount(0), LengthValueOverriden(false)
{
    Set__proto__(psc, pprototype);
}

// @0x142917f70
ArrayObject::ArrayObject(ASStringContext* psc)
    : Object(psc), LogPtr(0), RecursionCount(0), LengthValueOverriden(false)
{
    Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_Array));
}

// @0x142918010
ArrayObject::ArrayObject(Environment* penv)
    : Object(penv), LogPtr(penv->GetTarget()->GetLog()), RecursionCount(0), LengthValueOverriden(false)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Array));
}

// @0x14291f430
NumberObject::NumberObject(Environment* penv)
    : Object(penv), NumberValue(0)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Number));
}

// @0x14291f4b0
NumberObject::NumberObject(Environment* penv, Number v)
    : Object(penv), NumberValue(v)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Number));
}

// @0x14291e1a0
Math::Math(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Math));
}

// @0x14291eb20
MouseObject::MouseObject(Environment* penv)
    : Object(penv)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Mouse));
}

// @0x1429204d0
Selection::Selection(Environment* penv)
    : Object(penv)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Selection));
}

// @0x142918470
AsBroadcaster::AsBroadcaster(Environment* penv)
    : Object(penv)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_AsBroadcaster));
}

// @0x14291bbd0
ExternalInterface::ExternalInterface(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_ExternalInterface));
}

// @0x142920710
SharedObject::SharedObject(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_SharedObject));
}

// @0x14291aee0
ColorTransformObject::ColorTransformObject(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_ColorTransform));
}

// @0x14291b510
DateObject::DateObject(Environment* penv)
    : Object(penv)
{
    Date        = 0;
    Time        = 0;
    Year        = 0;
    JDate       = 0;
    LDate       = 0;
    LTime       = 0;
    LYear       = 0;
    LJDate      = 0;
    LocalOffset = 0;
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Date));
}

// @0x14291b5a0
DateObject::DateObject(Environment* penv, SInt64 val)
    : Object(penv)
{
    Date        = 0;
    Time        = 0;
    Year        = 0;
    JDate       = 0;
    LDate       = 0;
    LTime       = 0;
    LYear       = 0;
    LJDate      = 0;
    LocalOffset = 0;
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Date));
    SetDate(val);
}

// @0x14291e790
__declspec(safebuffers) MatrixObject::MatrixObject(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Matrix));
    SetMatrix(penv, Render::Matrix2F());
}

// @0x14291eca0
MovieClipLoader::MovieClipLoader(Environment* penv)
    : Object(penv)
{
    ASStringContext* psc = penv->GetSC();
    static_cast<ObjectInterface*>(this)->Set__proto__(psc, penv->GetPrototype(ASBuiltin_MovieClipLoader));
    ObjectInterface* pobj = this;
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    AsBroadcaster::InitializeInstance(psc, pobj);
}

// @0x14291ad30
ColorObject::ColorObject(Environment* penv, InteractiveObject* ptarget)
    : Object(penv), pCharacter(ptarget)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Color));
}

// @0x142920ea0
StringObject::StringObject(Environment* penv)
    : Object(penv), sValue(penv->GetBuiltin(ASBuiltin_empty_))
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_String));
}

// @0x142920f30
StringObject::StringObject(Environment* penv, const ASString& val)
    : Object(penv), sValue(val)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_String));
}

// @0x142920be0
StageObject::StageObject(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Stage));
}

// @0x1429231e0
TextSnapshotObject::TextSnapshotObject(Environment* penv)
    : Object(penv)
{
    ::new (Data68) StaticTextSnapshotData();
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_TextSnapshot));
}

// @0x142921520
TextFieldObject::TextFieldObject(ASStringContext* psc, Object* pprototype)
    : Object(psc), pIMECompositionStringStyles(0)
{
    Set__proto__(psc, pprototype);
}

// @0x142921580
TextFieldObject::TextFieldObject(Environment* penv)
    : Object(penv), pIMECompositionStringStyles(0)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_TextField));
}

// @0x1429237f0
Value::Value(const Value& v)
{
    T.Type = v.T.Type;
    switch (v.T.Type)
    {
    case BOOLEAN:
        V.BooleanValue = v.V.BooleanValue;
        break;
    case STRING:
    case FUNCTIONNAME:
        V.pStringNode = v.V.pStringNode;
        V.pStringNode->AddRef();
        break;
    case NUMBER:
        NV.NumberValue = v.NV.NumberValue;
        break;
    case INTEGER:
        NV.Int32Value = v.NV.Int32Value;
        break;
    case OBJECT:
        if (v.V.pObjectValue)
        {
            if (v.V.pObjectValue->IsFunction())
            {
                T.Type = FUNCTION;
                V.FunctionValue.Init(v.V.pObjectValue->ToFunction());
            }
            else
            {
                V.pObjectValue = v.V.pObjectValue;
                V.pObjectValue->AddRef();
            }
        }
        else
            V.pObjectValue = 0;
        break;
    case CHARACTER:
        V.pCharHandle = v.V.pCharHandle;
        if (V.pCharHandle)
            V.pCharHandle->AddRef();
        break;
    case FUNCTION:
    case RESOLVEHANDLER:
        V.FunctionValue.Init(v.V.FunctionValue);
        break;
    case PROPERTY:
        V.pProperty = v.V.pProperty;
        V.pProperty->AddRef();
        break;
    default:
        break;
    }
}

// @0x142923cb0
Value::Value(Object* pobj)
{
    if (pobj && pobj->IsFunction())
    {
        T.Type = FUNCTION;
        V.FunctionValue.Init(pobj->ToFunction());
    }
    else
    {
        T.Type         = OBJECT;
        V.pObjectValue = pobj;
        if (pobj)
            pobj->AddRef();
    }
}

// @0x1429267a0
void Value::operator=(const Value& v)
{
    if (T.Type >= STRING)
        DropRefs();

    // The same copy as the copy constructor.
    T.Type = v.T.Type;
    switch (v.T.Type)
    {
    case BOOLEAN:
        V.BooleanValue = v.V.BooleanValue;
        break;
    case STRING:
    case FUNCTIONNAME:
        V.pStringNode = v.V.pStringNode;
        V.pStringNode->AddRef();
        break;
    case NUMBER:
        NV.NumberValue = v.NV.NumberValue;
        break;
    case INTEGER:
        NV.Int32Value = v.NV.Int32Value;
        break;
    case OBJECT:
        if (v.V.pObjectValue)
        {
            if (v.V.pObjectValue->IsFunction())
            {
                T.Type = FUNCTION;
                V.FunctionValue.Init(v.V.pObjectValue->ToFunction());
            }
            else
            {
                V.pObjectValue = v.V.pObjectValue;
                V.pObjectValue->AddRef();
            }
        }
        else
            V.pObjectValue = 0;
        break;
    case CHARACTER:
        V.pCharHandle = v.V.pCharHandle;
        if (V.pCharHandle)
            V.pCharHandle->AddRef();
        break;
    case FUNCTION:
    case RESOLVEHANDLER:
        V.FunctionValue.Init(v.V.FunctionValue);
        break;
    case PROPERTY:
        V.pProperty = v.V.pProperty;
        V.pProperty->AddRef();
        break;
    default:
        break;
    }
}

// @0x142923e70
ValueProperty::ValueProperty(ASRefCountCollector* pcc, const FunctionRef& getterMethod,
                             const FunctionRef& setterMethod)
    : ASRefCountBase<ValueProperty>(pcc), GetterMethod(getterMethod), SetterMethod(setterMethod)
{
}

// @0x142923fd0
Object::Watchpoint::Watchpoint(const Watchpoint& o) : Callback(o.Callback), UserData(o.UserData)
{
}

// @0x1429181f0
ArraySortFunctor::ArraySortFunctor(const ArraySortFunctor& src)
    : This(src.This), Flags(src.Flags), Func(src.Func), Env(src.Env), LogPtr(src.LogPtr)
{
}

// @0x142925350
ArraySortFunctor::~ArraySortFunctor()
{
}

// @0x142926100
void Object::Watchpoint::Destruct_Call()
{
    this->~Watchpoint();
}

// @0x142925ae0
MovieRoot::InvokeAliasInfo::~InvokeAliasInfo()
{
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// The out-of-line destructors of the AS2 arrays, hashes and stacks.
template ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<Ptr<GFx::AS2::Object>, AllocatorLH<Ptr<GFx::AS2::Object>, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
// MS2-FUNCTIONAL cl inlines ~ArraySortFunctor (defined above), the exe calls it
// @0x1429242d0
template ArrayDataBase<GFx::AS2::ArraySortFunctor, AllocatorGH<GFx::AS2::ArraySortFunctor, 2>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<GFx::AS2::Value, AllocatorGH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();

typedef HashNode<GFx::AS2::Object*, GFx::AS2::Object*, IdentityHash<GFx::AS2::Object*> > MS2_AS2ObjectIdentityNode;
template HashSetBase<MS2_AS2ObjectIdentityNode, MS2_AS2ObjectIdentityNode::NodeHashF,
                     MS2_AS2ObjectIdentityNode::NodeAltHashF, AllocatorGH<GFx::AS2::Object*>,
                     HashsetNodeEntry<MS2_AS2ObjectIdentityNode, MS2_AS2ObjectIdentityNode::NodeHashF> >::~HashSetBase();
typedef HashNode<GFx::ASString, char, GFx::ASStringHashFunctor> MS2_AS2StandardMemberNode;
template decltype(HashLH<GFx::ASString, char, GFx::ASStringHashFunctor, GFx::StatMV_ASString_Mem, MS2_AS2StandardMemberNode,
                         HashsetNodeEntry<MS2_AS2StandardMemberNode, MS2_AS2StandardMemberNode::NodeHashF> >::mHash)::
    BaseType::~HashSetBase();
typedef HashNode<GFx::ASString, GFx::AS2::MovieRoot::InvokeAliasInfo, GFx::ASStringHashFunctor> MS2_AS2InvokeAliasNode;
// MS2-FUNCTIONAL cl inlines ~InvokeAliasInfo (defined above), the exe calls it
// @0x142924610
template decltype(HashLH<GFx::ASString, GFx::AS2::MovieRoot::InvokeAliasInfo, GFx::ASStringHashFunctor,
                         GFx::StatMV_ASString_Mem, MS2_AS2InvokeAliasNode,
                         HashsetNodeEntry<MS2_AS2InvokeAliasNode, MS2_AS2InvokeAliasNode::NodeHashF> >::mHash)::
    BaseType::~HashSetBase();
typedef HashNode<GFx::ASString, GFx::AS2::FunctionRef, GFx::ASStringHashFunctor> MS2_AS2FunctionRefNode;
// MS2-FUNCTIONAL the exe calls the node dtor out of line (0x142924490)
// @0x142924770
template decltype(HashLH<GFx::ASString, GFx::AS2::FunctionRef, GFx::ASStringHashFunctor, GFx::StatMV_ASString_Mem,
                         MS2_AS2FunctionRefNode,
                         HashsetNodeEntry<MS2_AS2FunctionRefNode, MS2_AS2FunctionRefNode::NodeHashF> >::mHash)::
    BaseType::~HashSetBase();

// The collected string hashes (ASStringHash_GC<U>).
#define MS2_AS2_STRING_HASH_GC_DTOR(U)                                                                           \
    template decltype(HashLH<GFx::ASString, U, GFx::ASStringHashFunctor, GFx::StatMV_ASString_Mem,                 \
                             HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>,                                 \
                             GFx::HashsetNodeEntry_GC<HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>,        \
                                                      HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>::NodeHashF> >::mHash)::BaseType::~HashSetBase();

MS2_AS2_STRING_HASH_GC_DTOR(GFx::AS2::Object::Watchpoint)
MS2_AS2_STRING_HASH_GC_DTOR(GFx::AS2::Member)
MS2_AS2_STRING_HASH_GC_DTOR(GFx::AS2::SharedObjectPtr)
MS2_AS2_STRING_HASH_GC_DTOR(GFx::AS2::Value)
// MS2-FUNCTIONAL cl inlines the handler array dtor (instantiated above), the exe calls it
// @0x142924a20
template decltype(HashLH<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, GFx::EventIdHashFunctor,
                         GFx::AS2::StatMV_ActionScript_Mem>::mHash)::BaseType::~HashSetBase();
template decltype(StringHashLH<GFx::AS2::MovieClipLoader::ProgressDesc>::mHash)::BaseType::~HashSetBase();

// MS2-FUNCTIONAL the Ptr release is inlined differently (the exe calls ReleaseInternal from two sites)
// @0x142924b70
template GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::~PagedStack();
// MS2-FUNCTIONAL register allocation of the pop loop (the exe reloads the top pointer each iteration)
// @0x142924c60
template GFx::AS2::PagedStack<GFx::AS2::Value, 32>::~PagedStack();

} // namespace Scaleform
// MS2-PIN: ??1?$ArrayDataBase@VArraySortFunctor@AS2@GFx@Scaleform@@U?$AllocatorGH@VArraySortFunctor@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1429242d0
// MS2-PIN: ??1?$ArrayDataBase@VValue@AS2@GFx@Scaleform@@U?$AllocatorLH@VValue@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1429243b0
// MS2-PIN: ??1?$ArrayDataBase@VValue@AS2@GFx@Scaleform@@U?$AllocatorLH@VValue@AS2@GFx@Scaleform@@$0BED@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x142924420
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UInvokeAliasInfo@MovieRoot@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UInvokeAliasInfo@MovieRoot@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x142924610
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x142924770
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VEventId@GFx@Scaleform@@$0BED@@2@V?$HashsetCachedNodeEntry@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x142924a20
// MS2-PIN: ??1?$PagedStack@V?$Ptr@VFunctionObject@AS2@GFx@Scaleform@@@Scaleform@@$0CA@@AS2@GFx@Scaleform@@QEAA@XZ 0x142924b70
// MS2-PIN: ??1?$PagedStack@VValue@AS2@GFx@Scaleform@@$0CA@@AS2@GFx@Scaleform@@QEAA@XZ 0x142924c60
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@6B@ 0x143215370
// MS2-PIN: ??_7?$ASRefCountBase@UValueProperty@AS2@GFx@Scaleform@@@AS2@GFx@Scaleform@@6B@ 0x1432153d0
// MS2-PIN: ??_7ValueProperty@AS2@GFx@Scaleform@@6B@ 0x1432153e8
// MS2-PIN: ??_7ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215410
// MS2-PIN: ??_7?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@AS2@GFx@Scaleform@@6B@ 0x1432154b8
// MS2-PIN: ??_7Object@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432154d0
// MS2-PIN: ??_7Object@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215518
// MS2-PIN: ??_7BooleanObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b550
// MS2-PIN: ??_7BooleanObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b598
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
// MS2-PIN: ??_7ArrayObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ad30
// MS2-PIN: ??_7ArrayObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ad78
// MS2-PIN: ??_7NumberObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b140
// MS2-PIN: ??_7NumberObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b188
// MS2-PIN: ??_7Math@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b960
// MS2-PIN: ??_7Math@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b9a8
// MS2-PIN: ??_7MouseObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ca18
// MS2-PIN: ??_7MouseObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ca60
// MS2-PIN: ??_7Selection@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d278
// MS2-PIN: ??_7Selection@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d2c0
// MS2-PIN: ??_7AsBroadcaster@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321bdc8
// MS2-PIN: ??_7AsBroadcaster@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321be10
// MS2-PIN: ??_7ExternalInterface@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ce68
// MS2-PIN: ??_7ExternalInterface@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ceb0
// MS2-PIN: ??_7SharedObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321da98
// MS2-PIN: ??_7SharedObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321dae0
// MS2-PIN: ??_7ColorTransformObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432190c0
// MS2-PIN: ??_7ColorTransformObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219108
// MS2-PIN: ??_7DateObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c1d8
// MS2-PIN: ??_7DateObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c220
// MS2-PIN: ??_7MatrixObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218cb0
// MS2-PIN: ??_7MatrixObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143218cf8
// MS2-PIN: ??_7MovieClipLoader@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216a50
// MS2-PIN: ??_7MovieClipLoader@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216ac0
// MS2-PIN: ??_7ColorObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432188a0
// MS2-PIN: ??_7ColorObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432188e8
// MS2-PIN: ??_7StringObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a920
// MS2-PIN: ??_7StringObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a968
// MS2-PIN: ??_7StageObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a510
// MS2-PIN: ??_7StageObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a558
// MS2-PIN: ??_7TextSnapshotObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e2c8
// MS2-PIN: ??_7TextSnapshotObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e310
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218490
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432184d8
// MS2-PIN: ??_7AsBroadcasterCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c0a8
// MS2-PIN: ??_7AsBroadcasterCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c130
// MS2-PIN: ??_7BitmapDataCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143219fd0
// MS2-PIN: ??_7BitmapDataCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a058
// MS2-PIN: ??_7BooleanCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b830
// MS2-PIN: ??_7BooleanCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b8b8
// MS2-PIN: ??_7DateCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c4b8
// MS2-PIN: ??_7DateCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c540
// MS2-PIN: ??_7GASLoadVarsLoaderCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432171b8
// MS2-PIN: ??_7GASLoadVarsLoaderCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217240
// MS2-PIN: ??_7MovieClipLoaderCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216da8
// MS2-PIN: ??_7MovieClipLoaderCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216e30
// MS2-PIN: ??_7ObjectCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143215820
// MS2-PIN: ??_7ObjectCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432158a8
// MS2-PIN: ??_7PointCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a3e0
// MS2-PIN: ??_7PointCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a468
// MS2-PIN: ??_7SharedObjectCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321dd88
// MS2-PIN: ??_7SharedObjectCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321de10
// MS2-PIN: ??_7StringCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ac00
// MS2-PIN: ??_7StringCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ac88
// MS2-PIN: ??_7StyleSheetCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432175e8
// MS2-PIN: ??_7StyleSheetCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217670
// MS2-PIN: ??_7TextFieldCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218770
// MS2-PIN: ??_7TextFieldCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432187f8
// MS2-PIN: ??_7TextFormatCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d968
// MS2-PIN: ??_7TextFormatCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d9f0
// MS2-PIN: ??_7AmpMarkerCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e198
// MS2-PIN: ??_7AmpMarkerCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e220
// MS2-PIN: ??_7BevelFilterCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321fb28
// MS2-PIN: ??_7BevelFilterCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321fbb0
// MS2-PIN: ??_7BlurFilterCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f718
// MS2-PIN: ??_7BlurFilterCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f7a0
// MS2-PIN: ??_7ColorMatrixFilterCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ff38
// MS2-PIN: ??_7ColorMatrixFilterCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ffc0
// MS2-PIN: ??_7DropShadowFilterCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321eef8
// MS2-PIN: ??_7DropShadowFilterCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ef80
// MS2-PIN: ??_7FunctionCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143215950
// MS2-PIN: ??_7FunctionCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432159d8
// MS2-PIN: ??_7GlowFilterCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f308
// MS2-PIN: ??_7GlowFilterCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f390
// MS2-PIN: ??_7?$Prototype@VBooleanObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b640
// MS2-PIN: ??_7?$Prototype@VBooleanObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b688
// MS2-PIN: ??_7?$Prototype@VBooleanObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321b730
// MS2-PIN: ??_7BooleanProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b738
// MS2-PIN: ??_7BooleanProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b780
// MS2-PIN: ??_7BooleanProto@AS2@GFx@Scaleform@@6B@ 0x14321b828
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7?$Prototype@VAmpMarker@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321dfa8
// MS2-PIN: ??_7?$Prototype@VAmpMarker@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321dff0
// MS2-PIN: ??_7?$Prototype@VAmpMarker@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321e098
// MS2-PIN: ??_7AmpMarkerProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e0a0
// MS2-PIN: ??_7AmpMarkerProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e0e8
// MS2-PIN: ??_7AmpMarkerProto@AS2@GFx@Scaleform@@6B@ 0x14321e190
// MS2-PIN: ??_7?$Prototype@VAsBroadcaster@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321beb8
// MS2-PIN: ??_7?$Prototype@VAsBroadcaster@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321bf00
// MS2-PIN: ??_7?$Prototype@VAsBroadcaster@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321bfa8
// MS2-PIN: ??_7AsBroadcasterProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321bfb0
// MS2-PIN: ??_7AsBroadcasterProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321bff8
// MS2-PIN: ??_7AsBroadcasterProto@AS2@GFx@Scaleform@@6B@ 0x14321c0a0
// MS2-PIN: ??_7?$Prototype@VExternalInterface@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321cf58
// MS2-PIN: ??_7?$Prototype@VExternalInterface@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321cfa0
// MS2-PIN: ??_7?$Prototype@VExternalInterface@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321d048
// MS2-PIN: ??_7ExternalInterfaceProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d050
// MS2-PIN: ??_7ExternalInterfaceProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d098
// MS2-PIN: ??_7ExternalInterfaceProto@AS2@GFx@Scaleform@@6B@ 0x14321d140
// MS2-PIN: ??_7KeyObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c5e8
// MS2-PIN: ??_7KeyObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c630
// MS2-PIN: ??_7?$Prototype@VKeyObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c6d8
// MS2-PIN: ??_7?$Prototype@VKeyObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c720
// MS2-PIN: ??_7?$Prototype@VKeyObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321c7c8
// MS2-PIN: ??_7KeyProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321c7d0
// MS2-PIN: ??_7KeyProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321c818
// MS2-PIN: ??_7KeyProto@AS2@GFx@Scaleform@@6B@ 0x14321c8c0
// MS2-PIN: ??_7?$Prototype@VMath@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ba50
// MS2-PIN: ??_7?$Prototype@VMath@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ba98
// MS2-PIN: ??_7?$Prototype@VMath@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321bb40
// MS2-PIN: ??_7MathProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321bb48
// MS2-PIN: ??_7MathProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321bb90
// MS2-PIN: ??_7MathProto@AS2@GFx@Scaleform@@6B@ 0x14321bc38
// MS2-PIN: ??_7?$Prototype@VMatrixObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218da0
// MS2-PIN: ??_7?$Prototype@VMatrixObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143218de8
// MS2-PIN: ??_7?$Prototype@VMatrixObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143218e90
// MS2-PIN: ??_7MatrixProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218e98
// MS2-PIN: ??_7MatrixProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143218ee0
// MS2-PIN: ??_7MatrixProto@AS2@GFx@Scaleform@@6B@ 0x143218f88
// MS2-PIN: ??_7?$Prototype@VMouseObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321cb08
// MS2-PIN: ??_7?$Prototype@VMouseObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321cb50
// MS2-PIN: ??_7?$Prototype@VMouseObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321cbf8
// MS2-PIN: ??_7MouseProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321cc00
// MS2-PIN: ??_7MouseProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321cc48
// MS2-PIN: ??_7MouseProto@AS2@GFx@Scaleform@@6B@ 0x14321ccf0
// MS2-PIN: ??_7?$Prototype@VSelection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d368
// MS2-PIN: ??_7?$Prototype@VSelection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d3b0
// MS2-PIN: ??_7?$Prototype@VSelection@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321d458
// MS2-PIN: ??_7SelectionProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d460
// MS2-PIN: ??_7SelectionProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d4a8
// MS2-PIN: ??_7SelectionProto@AS2@GFx@Scaleform@@6B@ 0x14321d550
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a600
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a648
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321a6f0
// MS2-PIN: ??_7StageProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a6f8
// MS2-PIN: ??_7StageProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a740
// MS2-PIN: ??_7StageProto@AS2@GFx@Scaleform@@6B@ 0x14321a7e8
// MS2-PIN: ??_7AmpMarker@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321deb8
// MS2-PIN: ??_7AmpMarker@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321df00
// MS2-PIN: ??_7?$Prototype@VBevelFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f938
// MS2-PIN: ??_7?$Prototype@VBevelFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f980
// MS2-PIN: ??_7?$Prototype@VBevelFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321fa28
// MS2-PIN: ??_7BevelFilterProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321fa30
// MS2-PIN: ??_7BevelFilterProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321fa78
// MS2-PIN: ??_7BevelFilterProto@AS2@GFx@Scaleform@@6B@ 0x14321fb20
// MS2-PIN: ??_7?$Prototype@VBitmapFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e8f8
// MS2-PIN: ??_7?$Prototype@VBitmapFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e940
// MS2-PIN: ??_7?$Prototype@VBitmapFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321e9e8
// MS2-PIN: ??_7BitmapFilterProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e9f0
// MS2-PIN: ??_7BitmapFilterProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ea38
// MS2-PIN: ??_7BitmapFilterProto@AS2@GFx@Scaleform@@6B@ 0x14321eae0
// MS2-PIN: ??_7?$Prototype@VBlurFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f528
// MS2-PIN: ??_7?$Prototype@VBlurFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f570
// MS2-PIN: ??_7?$Prototype@VBlurFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321f618
// MS2-PIN: ??_7BlurFilterProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f620
// MS2-PIN: ??_7BlurFilterProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f668
// MS2-PIN: ??_7BlurFilterProto@AS2@GFx@Scaleform@@6B@ 0x14321f710
// MS2-PIN: ??_7?$Prototype@VColorMatrixFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321fd48
// MS2-PIN: ??_7?$Prototype@VColorMatrixFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321fd90
// MS2-PIN: ??_7?$Prototype@VColorMatrixFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321fe38
// MS2-PIN: ??_7ColorMatrixFilterProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321fe40
// MS2-PIN: ??_7ColorMatrixFilterProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321fe88
// MS2-PIN: ??_7ColorMatrixFilterProto@AS2@GFx@Scaleform@@6B@ 0x14321ff30
// MS2-PIN: ??_7?$Prototype@VDropShadowFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ed08
// MS2-PIN: ??_7?$Prototype@VDropShadowFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ed50
// MS2-PIN: ??_7?$Prototype@VDropShadowFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321edf8
// MS2-PIN: ??_7DropShadowFilterProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ee00
// MS2-PIN: ??_7DropShadowFilterProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ee48
// MS2-PIN: ??_7DropShadowFilterProto@AS2@GFx@Scaleform@@6B@ 0x14321eef0
// MS2-PIN: ??_7?$Prototype@VGlowFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f118
// MS2-PIN: ??_7?$Prototype@VGlowFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f160
// MS2-PIN: ??_7?$Prototype@VGlowFilterObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321f208
// MS2-PIN: ??_7GlowFilterProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f210
// MS2-PIN: ??_7GlowFilterProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f258
// MS2-PIN: ??_7GlowFilterProto@AS2@GFx@Scaleform@@6B@ 0x14321f300
// MS2-PIN: ??_7BitmapFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321e808
// MS2-PIN: ??_7BitmapFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321e850
// MS2-PIN: ??_7BevelFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f848
// MS2-PIN: ??_7BevelFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f890
// MS2-PIN: ??_7BlurFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f438
// MS2-PIN: ??_7BlurFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f480
// MS2-PIN: ??_7ColorMatrixFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321fc58
// MS2-PIN: ??_7ColorMatrixFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321fca0
// MS2-PIN: ??_7DropShadowFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ec18
// MS2-PIN: ??_7DropShadowFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ec60
// MS2-PIN: ??_7GlowFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f028
// MS2-PIN: ??_7GlowFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f070
