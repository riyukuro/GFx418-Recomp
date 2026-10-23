// Recovered Scaleform 4.1.18 GFx: the host side value (GFx::Value) the external interface hands to the application,
// and the ExternalInterface state that receives ExternalInterface.call. Written from the exe's uses (sfr12); only
// what the recovered units touch: the layout, construction and the release of VM references.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
#ifndef MS2_SF_GFX_VALUE_H
#define MS2_SF_GFX_VALUE_H

#include "gfx_state.h"

namespace Scaleform { namespace GFx {

class Movie;
class MovieImpl;
namespace AS2 { class MovieRoot; }

// 0x20 bytes: the VM interface of a managed value (object, array, display object, closure), the type, the value,
// and one more word for AS3 values.
class Value
{
    friend class AS2::MovieRoot;

public:
    // How a managed value reaches its VM object.
    class ObjectInterface
    {
    public:
        ObjectInterface(MovieImpl* pmovieRoot) : pMovieRoot(pmovieRoot) {}
        virtual ~ObjectInterface() {}                           // 0

        virtual void ObjectAddRef(Value* val, void* pobj)  = 0; // 1
        virtual void ObjectRelease(Value* val, void* pobj) = 0; // 2

    protected:
        MovieImpl* pMovieRoot;                                  // +0x08
    };

    enum ValueTypeControl
    {
        VTC_ConvertBit = 0x80,
        VTC_ManagedBit = 0x40,
        VTC_TypeMask   = VTC_ConvertBit | 0x0F
    };
    enum ValueType
    {
        VT_Undefined     = 0x00,
        VT_Null          = 0x01,
        VT_Boolean       = 0x02,
        VT_Int           = 0x03,
        VT_UInt          = 0x04,
        VT_Number        = 0x05,
        VT_String        = 0x06,
        VT_StringW       = 0x07,
        VT_Object        = 0x08,
        VT_Array         = 0x09,
        VT_DisplayObject = 0x0a,
        VT_Closure       = 0x0b
    };

    Value() : pObjectInterface(NULL), Type(VT_Undefined) {}
    ~Value()
    {
        if (IsManagedValue())
            ReleaseManagedValue();
        Type = VT_Undefined;
    }

    ValueType GetType() const { return ValueType(Type & VTC_TypeMask); }
    // Marks the value as a wide string still to be filled by the VM (the old managed value released).
    void SetConvertStringW()
    {
        if (IsManagedValue())
            ReleaseManagedValue();
        Type = ValueType(VT_StringW | VTC_ConvertBit);
    }

protected:
    union ValueUnion
    {
        SInt32          IValue;
        UInt32          UIValue;
        double          NValue;
        bool            BValue;
        const char*     pString;
        const char**    pStringManaged;
        const wchar_t*  pStringW;
        void*           pData;
    };

    ObjectInterface*    pObjectInterface;   // +0x00
    ValueType           Type;               // +0x08
    ValueUnion          mValue;             // +0x10
    UPInt               DataAux;            // +0x18

    bool IsManagedValue() const { return (Type & VTC_ManagedBit) != 0; }
    void ReleaseManagedValue()
    {
        pObjectInterface->ObjectRelease(this, mValue.pData);
        pObjectInterface = NULL;
    }
};

// The application's handler of ExternalInterface.call (methodName NULL without one; the handler sets the return value
// on the movie).
class ExternalInterface : public State
{
public:
    virtual ~ExternalInterface() {}
    virtual void Callback(Movie* pmovieView, const char* methodName, const Value* args, unsigned argCount) = 0;
};

}} // namespace Scaleform::GFx

#endif
