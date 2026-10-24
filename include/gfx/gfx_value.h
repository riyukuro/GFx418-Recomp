// Recovered Scaleform 4.1.18 GFx: the host side value (GFx::Value) the external interface hands to the application,
// and the ExternalInterface state that receives ExternalInterface.call. Written from the exe's uses (sfr12); only
// what the recovered units touch: the layout, construction and the release of VM references.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
#ifndef MS2_SF_GFX_VALUE_H
#define MS2_SF_GFX_VALUE_H

#include "gfx_state.h"

namespace Scaleform {
namespace Render { template<class T> class Matrix2x4; template<class T> class Matrix3x4; class Cxform; }
namespace GFx {

class Movie;
class MovieImpl;
class ASUserData;
class MemberValueSet;
namespace AMP { class ViewStats; }
namespace AS2 { class MovieRoot; }

// 0x20 bytes: the VM interface of a managed value (object, array, display object, closure), the type, the value,
// and one more word for AS3 values.
class Value
{
    friend class AS2::MovieRoot;

public:
    class DisplayInfo;

    // How a managed value reaches its VM object.
    class ObjectInterface
    {
    public:
        ObjectInterface(MovieImpl* pmovieRoot) : pMovieRoot(pmovieRoot) {}
        virtual ~ObjectInterface() {}                           // 0

        virtual void ObjectAddRef(Value* val, void* pobj)  = 0; // 1
        virtual void ObjectRelease(Value* val, void* pobj) = 0; // 2

        // (appended for the movie, sfr_gfx_01i) the member, array and display object access of the AVM side
        // (AS2ValueObjectInterface vftable 0x143222128; this build has no ByteArray slots)
        class ObjVisitor;
        class ArrVisitor;
        virtual bool     HasMember(void* pdata, const char* name, bool isdobj) const = 0;                     // 3
        virtual bool     GetMember(void* pdata, const char* name, Value* pval, bool isdobj) const = 0;        // 4
        virtual bool     SetMember(void* pdata, const char* name, const Value& value, bool isdobj) = 0;      // 5
        virtual bool     Invoke(void* pdata, Value* presult, const char* name, const Value* pargs, UPInt nargs,
                                bool isdobj) = 0;                                                             // 6
        virtual bool     InvokeClosure(void* pdata, UPInt dataAux, Value* presult, const Value* pargs,
                                       UPInt nargs) = 0;                                                      // 7
        virtual bool     DeleteMember(void* pdata, const char* name, bool isdobj) = 0;                       // 8
        virtual void     VisitMembers(void* pdata, ObjVisitor* visitor, bool isdobj) const = 0;              // 9
        virtual unsigned GetArraySize(void* pdata) const = 0;                                                // 10
        virtual bool     SetArraySize(void* pdata, unsigned sz) = 0;                                         // 11
        virtual bool     GetElement(void* pdata, unsigned idx, Value* pval) const = 0;                       // 12
        virtual bool     SetElement(void* pdata, unsigned idx, const Value& value) = 0;                      // 13
        virtual void     VisitElements(void* pdata, ArrVisitor* visitor, unsigned idx, int count) const = 0; // 14
        virtual bool     PushBack(void* pdata, const Value& value) = 0;                                      // 15
        virtual bool     PopBack(void* pdata, Value* pval) = 0;                                              // 16
        virtual bool     RemoveElements(void* pdata, unsigned idx, int count) = 0;                           // 17
        virtual bool     IsDisplayObjectActive(void* pdata) const = 0;                                       // 18
        virtual bool     GetDisplayInfo(void* pdata, DisplayInfo* pinfo) const = 0;                          // 19
        virtual bool     SetDisplayInfo(void* pdata, const DisplayInfo& info) = 0;                           // 20
        virtual bool     GetWorldMatrix(void* pdata, Render::Matrix2x4<float>* pmat) const = 0;              // 21

        // (appended, sfr24) slots 22..39, named from AS3ValueObjectInterface's vftable 0x14317eff8 (the abstract
        // ObjectInterface vftable 0x14317bc90 has 40 slots, 1..39 _purecall). MSVC lays the overloads out in reverse.
        virtual bool     GetDisplayMatrix(void* pdata, Render::Matrix2x4<float>* pmat) const = 0;            // 22
        virtual bool     SetDisplayMatrix(void* pdata, const Render::Matrix2x4<float>& mat) = 0;             // 23
        virtual bool     GetMatrix3D(void* pdata, Render::Matrix3x4<float>* pmat) const = 0;                 // 24
        virtual bool     SetMatrix3D(void* pdata, const Render::Matrix3x4<float>& mat) = 0;                  // 25
        virtual bool     GetCxform(void* pdata, Render::Cxform* pcx) const = 0;                              // 26
        virtual bool     SetCxform(void* pdata, const Render::Cxform& cx) = 0;                               // 27
        virtual bool     GetText(void* pdata, Value* pval, bool ishtml) const = 0;                           // 28
        virtual bool     SetText(void* pdata, const char* ptext, bool ishtml) = 0;                           // 30
        virtual bool     SetText(void* pdata, const wchar_t* ptext, bool ishtml) = 0;                        // 29
        virtual bool     CreateEmptyMovieClip(void* pdata, Value* pmc, const char* instanceName,
                                              SInt32 depth) = 0;                                             // 31
        virtual bool     AttachMovie(void* pdata, Value* pmc, const char* symbolName, const char* instanceName,
                                     SInt32 depth, const MemberValueSet* initArgs) = 0;                      // 32
        virtual bool     GotoAndPlay(void* pdata, const char* frame, bool stop) = 0;                         // 34
        virtual bool     GotoAndPlay(void* pdata, unsigned frame, bool stop) = 0;                            // 33
        virtual void     ToString(String* pstr, const Value& thisVal) const = 0;                             // 35
        virtual void     SetUserData(void* pdata, ASUserData* puserdata, bool isdobj) = 0;                   // 36
        virtual ASUserData* GetUserData(void* pdata, bool isdobj) const = 0;                                 // 37
        virtual bool     CreateObjectValue(Value* pval, void* pdata, bool isdobj) = 0;                       // 38
        virtual AMP::ViewStats* GetAdvanceStats() const = 0;                                                 // 39

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
    // ObjectInterface::GetMember/SetMember/Invoke are its vftable slots 4/5/6 (these raw slot calls predate the
    // declarations on ObjectInterface).
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
    // (appended for the movie, sfr_gfx_01i) the world matrix of a display object value, translation in pixels
    bool GetWorldMatrix(Render::Matrix2x4<float>* pmat) const
    {
        return pObjectInterface->GetWorldMatrix(mValue.pData, pmat);
    }
    // (appended, sfr_gfx_01i) the value as text; objects ask their ObjectInterface (vftable slot 35).
    String          ToString() const;                                   // exe 0x142576d50
    const wchar_t*  ToStringW(wchar_t* pdest, UPInt destSz) const;      // exe 0x142576fd0

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
