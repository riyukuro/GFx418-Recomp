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
    void SetUndefined()
    {
        if (IsManagedValue())
            ReleaseManagedValue();
        Type = VT_Undefined;
    }
    // Marks the value as a wide string still to be filled by the VM (the old managed value released).
    void SetConvertStringW()
    {
        if (IsManagedValue())
            ReleaseManagedValue();
        Type = ValueType(VT_StringW | VTC_ConvertBit);
    }

    // (appended, sfr19) copies, type tests and setters, and the managed value's member access (the IME units).
    Value(const Value& src) : pObjectInterface(NULL), Type(src.Type)
    {
        mValue = src.mValue;
        DataAux = src.DataAux;
        if (src.IsManagedValue())
            AcquireManagedValue(src);
    }
    Value& operator=(const Value& src)
    {
        if (this != &src)
        {
            if (IsManagedValue())
                ReleaseManagedValue();
            Type = src.Type;
            mValue = src.mValue;
            DataAux = src.DataAux;
            if (src.IsManagedValue())
                AcquireManagedValue(src);
        }
        return *this;
    }
    bool IsUndefined() const     { return GetType() == VT_Undefined; }
    bool IsNull() const          { return GetType() == VT_Null; }
    bool IsDisplayObject() const { return GetType() == VT_DisplayObject; }
    void SetNull()
    {
        if (IsManagedValue())
            ReleaseManagedValue();
        Type = VT_Null;
    }
    void SetNumber(double v)
    {
        if (IsManagedValue())
            ReleaseManagedValue();
        Type = VT_Number;
        mValue.NValue = v;
    }
    // ObjectInterface::GetMember/SetMember/Invoke are its vftable slots 4/5/6 (not declared on ObjectInterface:
    // the AS2 interface overrides only part of it so far).
    bool GetMember(const char* name, Value* pval) const
    {
        typedef bool (*Fn)(ObjectInterface*, void*, const char*, Value*, bool);
        return (*reinterpret_cast<Fn const* const*>(pObjectInterface))[4](pObjectInterface, mValue.pData, name, pval,
                                                                           IsDisplayObject());
    }
    bool SetMember(const char* name, const Value& val)
    {
        typedef bool (*Fn)(ObjectInterface*, void*, const char*, const Value&, bool);
        return (*reinterpret_cast<Fn const* const*>(pObjectInterface))[5](pObjectInterface, mValue.pData, name, val,
                                                                           IsDisplayObject());
    }
    bool Invoke(const char* name, Value* presult, const Value* args, UPInt nargs)
    {
        typedef bool (*Fn)(ObjectInterface*, void*, Value*, const char*, const Value*, UPInt, bool);
        return (*reinterpret_cast<Fn const* const*>(pObjectInterface))[6](pObjectInterface, mValue.pData, presult,
                                                                           name, args, nargs, IsDisplayObject());
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
    // (appended, sfr19)
    void AcquireManagedValue(const Value& src)
    {
        pObjectInterface = src.pObjectInterface;
        pObjectInterface->ObjectAddRef(this, mValue.pData);
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
