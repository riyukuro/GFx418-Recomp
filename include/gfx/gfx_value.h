// Recovered Scaleform 4.1.18 GFx: the host side value (GFx::Value) the external interface hands to the application,
// and the ExternalInterface state that receives ExternalInterface.call. Written from the exe's uses (sfr12); only
// what the recovered units touch: the layout, construction and the release of VM references.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
#ifndef MS2_SF_GFX_VALUE_H
#define MS2_SF_GFX_VALUE_H

#include "gfx_state.h"
#include "../kernel/sf_std.h"

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

        // (appended, fq1)
        bool       IsSameContext(ObjectInterface* pother) { return pMovieRoot == pother->pMovieRoot; }
        MovieImpl* GetMovieImpl() const { return pMovieRoot; }

    protected:
        MovieImpl* pMovieRoot;                                  // +0x08
    };

    enum ValueTypeControl
    {
        VTC_ConvertBit = 0x80,
        VTC_ManagedBit = 0x40,
        VTC_TypeMask   = VTC_ConvertBit | 0x0F,
        VTC_OrphanedBit = 0x20                                  // (appended, fq1)
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
        VT_Closure       = 0x0b,

        // (appended, fq1) a value the VM converts to the given type on the way out
        VT_ConvertBoolean = VTC_ConvertBit | VT_Boolean,
        VT_ConvertInt     = VTC_ConvertBit | VT_Int,
        VT_ConvertUInt    = VTC_ConvertBit | VT_UInt,
        VT_ConvertNumber  = VTC_ConvertBit | VT_Number,
        VT_ConvertString  = VTC_ConvertBit | VT_String,
        VT_ConvertStringW = VTC_ConvertBit | VT_StringW
    };

    Value() : pObjectInterface(NULL), Type(VT_Undefined) {}
    ~Value()
    {
        if (IsManagedValue())
            ReleaseManagedValue();
        Type = VT_Undefined;
    }

    ValueType GetType() const { return ValueType(Type & VTC_TypeMask); }
    void SetUndefined() { ChangeType(VT_Undefined); }
    // Marks the value as a wide string still to be filled by the VM (the old managed value released).
    void SetConvertStringW() { ChangeType(VT_ConvertStringW); }

    // (appended, sfr19) copies, type tests and setters, and the managed value's member access (the IME units).
    Value(const Value& src) : pObjectInterface(NULL), Type(src.Type)
    {
        mValue = src.mValue;
        DataAux = src.DataAux;
        if (src.IsManagedValue())
            AcquireManagedValue(src);
    }
    const Value& operator=(const Value& src)
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
    void SetNull()           { ChangeType(VT_Null); }
    void SetNumber(double v) { ChangeType(VT_Number); mValue.NValue = v; }
    // (appended, sfr24) an unmanaged string value: pstr is not copied.
    void SetString(const char* pstr) { ChangeType(VT_String); mValue.pString = pstr; }
    // ObjectInterface slots 4/5/6 (fq1: virtual calls, as the game's /Od copies make them)
    bool GetMember(const char* name, Value* pval) const
    {
        return pObjectInterface->GetMember(mValue.pData, name, pval, IsDisplayObject());
    }
    bool SetMember(const char* name, const Value& val)
    {
        return pObjectInterface->SetMember(mValue.pData, name, val, IsDisplayObject());
    }
    bool Invoke(const char* name, Value* presult, const Value* args, UPInt nargs)
    {
        return pObjectInterface->Invoke(mValue.pData, presult, name, args, nargs, IsDisplayObject());
    }
    // (appended for the movie, sfr_gfx_01i) the world matrix of a display object value, translation in pixels
    bool GetWorldMatrix(Render::Matrix2x4<float>* pmat) const
    {
        return pObjectInterface->GetWorldMatrix(mValue.pData, pmat);
    }
    // (appended, sfr_gfx_01i) the value as text; objects ask their ObjectInterface (vftable slot 35).
    String          ToString() const;                                   // exe 0x142576d50
    const wchar_t*  ToStringW(wchar_t* pdest, UPInt destSz) const;      // exe 0x142576fd0

    // (appended, fq1) the rest of the host API the game uses. These are inline: the game's /Od units keep
    // out-of-line copies of them (Value(bool) and the Is*/Get*/Set* family), so each body keeps the same calls as those
    // copies. A setter goes through ChangeType, and a getter of a string asks IsManagedValue.
    Value(ValueType type) : pObjectInterface(NULL), Type(type) { mValue.pString = 0; }
    Value(SInt32 v)          : pObjectInterface(NULL), Type(VT_Int)     { mValue.IValue = v; }
    Value(UInt32 v)          : pObjectInterface(NULL), Type(VT_UInt)    { mValue.UIValue = v; }
    Value(double v)          : pObjectInterface(NULL), Type(VT_Number)  { mValue.NValue = v; }
    Value(bool v)            : pObjectInterface(NULL), Type(VT_Boolean) { mValue.BValue = v; }
    Value(const char* ps)    : pObjectInterface(NULL), Type(VT_String)  { mValue.pString = ps; }
    Value(const wchar_t* ps) : pObjectInterface(NULL), Type(VT_StringW) { mValue.pStringW = ps; }

    bool operator==(const Value& other) const
    {
        if (GetType() != other.GetType())
            return false;
        switch (GetType())
        {
        case VT_Undefined:
        case VT_Null:      return true;
        case VT_Boolean:   return mValue.BValue == other.mValue.BValue;
        case VT_Int:       return mValue.IValue == other.mValue.IValue;
        case VT_UInt:      return mValue.UIValue == other.mValue.UIValue;
        case VT_Number:    return mValue.NValue == other.mValue.NValue;
        case VT_String:    return !SFstrcmp(GetString(), other.GetString());
        case VT_StringW:   return !SFwcscmp(GetStringW(), other.GetStringW());
        case VT_Closure:   return mValue.pData == other.mValue.pData && DataAux == other.DataAux;
        default:           return mValue.pData == other.mValue.pData;
        }
    }

    bool IsBool() const     { return GetType() == VT_Boolean; }
    bool IsInt() const      { return GetType() == VT_Int; }
    bool IsUInt() const     { return GetType() == VT_UInt; }
    bool IsNumber() const   { return GetType() == VT_Number; }
    bool IsNumeric() const  { return IsInt() || IsUInt() || IsNumber(); }
    bool IsString() const   { return GetType() == VT_String; }
    bool IsStringW() const  { return GetType() == VT_StringW; }
    bool IsObject() const   { return GetType() == VT_Object || GetType() == VT_Array || GetType() == VT_DisplayObject; }
    bool IsArray() const    { return GetType() == VT_Array; }
    bool IsClosure() const  { return GetType() == VT_Closure; }
    bool IsOrphaned() const { return (Type & VTC_OrphanedBit) != 0; }

    bool           GetBool() const    { return mValue.BValue; }
    SInt32         GetInt() const     { return mValue.IValue; }
    UInt32         GetUInt() const    { return mValue.UIValue; }
    double         GetNumber() const  { return mValue.NValue; }
    const char*    GetString() const  { return IsManagedValue() ? *mValue.pStringManaged : mValue.pString; }
    const wchar_t* GetStringW() const { return mValue.pStringW; }

    void SetBoolean(bool v)           { ChangeType(VT_Boolean); mValue.BValue = v; }
    void SetInt(SInt32 v)             { ChangeType(VT_Int);     mValue.IValue = v; }
    void SetUInt(UInt32 v)            { ChangeType(VT_UInt);    mValue.UIValue = v; }
    void SetStringW(const wchar_t* p) { ChangeType(VT_StringW); mValue.pStringW = p; }
    void SetConvertBoolean()          { ChangeType(VT_ConvertBoolean); }
    void SetConvertNumber()           { ChangeType(VT_ConvertNumber); }
    void SetConvertString()           { ChangeType(VT_ConvertString); }

    typedef ObjectInterface::ObjVisitor ObjectVisitor;
    typedef ObjectInterface::ArrVisitor ArrayVisitor;

    // objects
    bool HasMember(const char* name) const
    {
        return pObjectInterface->HasMember(mValue.pData, name, IsDisplayObject());
    }
    bool InvokeSelf(Value* presult, const Value* pargs, UPInt nargs)
    {
        return pObjectInterface->InvokeClosure(mValue.pData, DataAux, presult, pargs, nargs);
    }
    bool InvokeSelf(Value* presult = NULL) { return InvokeSelf(presult, NULL, 0); }
    bool Invoke(const char* name, Value* presult = NULL) { return Invoke(name, presult, NULL, 0); }
    void VisitMembers(ObjectVisitor* visitor) const
    {
        return pObjectInterface->VisitMembers(mValue.pData, visitor, IsDisplayObject());
    }
    bool DeleteMember(const char* name)
    {
        return pObjectInterface->DeleteMember(mValue.pData, name, IsDisplayObject());
    }
    void SetUserData(ASUserData* pdata)
    {
        pObjectInterface->SetUserData(mValue.pData, pdata, IsDisplayObject());
    }
    ASUserData* GetUserData() const
    {
        return pObjectInterface->GetUserData(mValue.pData, IsDisplayObject());
    }

    // arrays
    unsigned GetArraySize() const          { return pObjectInterface->GetArraySize(mValue.pData); }
    bool     SetArraySize(unsigned sz)     { return pObjectInterface->SetArraySize(mValue.pData, sz); }
    bool     GetElement(unsigned idx, Value* pval) const
    {
        return pObjectInterface->GetElement(mValue.pData, idx, pval);
    }
    bool     SetElement(unsigned idx, const Value& val)
    {
        return pObjectInterface->SetElement(mValue.pData, idx, val);
    }
    void     VisitElements(ArrayVisitor* visitor, unsigned idx, int count = -1) const
    {
        return pObjectInterface->VisitElements(mValue.pData, visitor, idx, count);
    }
    void     VisitElements(ArrayVisitor* visitor) const { VisitElements(visitor, 0); }
    bool     PushBack(const Value& val)    { return pObjectInterface->PushBack(mValue.pData, val); }
    bool     PopBack(Value* pval = NULL)   { return pObjectInterface->PopBack(mValue.pData, pval); }
    bool     RemoveElements(unsigned idx, int count = -1)
    {
        return pObjectInterface->RemoveElements(mValue.pData, idx, count);
    }
    bool     RemoveElement(unsigned idx)   { return RemoveElements(idx, 1); }
    bool     ClearElements()               { return RemoveElements(0); }

    // display objects
    bool IsDisplayObjectActive() const { return pObjectInterface->IsDisplayObjectActive(mValue.pData); }
    bool GetDisplayInfo(DisplayInfo* pinfo) const { return pObjectInterface->GetDisplayInfo(mValue.pData, pinfo); }
    bool SetDisplayInfo(const DisplayInfo& info)  { return pObjectInterface->SetDisplayInfo(mValue.pData, info); }
    bool GetDisplayMatrix(Render::Matrix2x4<float>* pmat) const
    {
        return pObjectInterface->GetDisplayMatrix(mValue.pData, pmat);
    }
    bool SetDisplayMatrix(const Render::Matrix2x4<float>& mat)
    {
        return pObjectInterface->SetDisplayMatrix(mValue.pData, mat);
    }
    bool GetMatrix3D(Render::Matrix3x4<float>* pmat) const { return pObjectInterface->GetMatrix3D(mValue.pData, pmat); }
    bool SetMatrix3D(const Render::Matrix3x4<float>& mat)  { return pObjectInterface->SetMatrix3D(mValue.pData, mat); }
    bool GetColorTransform(Render::Cxform* pcx) const      { return pObjectInterface->GetCxform(mValue.pData, pcx); }
    bool SetColorTransform(Render::Cxform& cx)             { return pObjectInterface->SetCxform(mValue.pData, cx); }
    bool SetText(const char* ptext)        { return pObjectInterface->SetText(mValue.pData, ptext, false); }
    bool SetText(const wchar_t* ptext)     { return pObjectInterface->SetText(mValue.pData, ptext, false); }
    bool SetTextHTML(const char* phtml)    { return pObjectInterface->SetText(mValue.pData, phtml, true); }
    bool SetTextHTML(const wchar_t* phtml) { return pObjectInterface->SetText(mValue.pData, phtml, true); }
    bool GetText(Value* pval) const        { return pObjectInterface->GetText(mValue.pData, pval, false); }
    bool GetTextHTML(Value* pval) const    { return pObjectInterface->GetText(mValue.pData, pval, true); }
    bool CreateEmptyMovieClip(Value* pmc, const char* instanceName, SInt32 depth = -1)
    {
        return pObjectInterface->CreateEmptyMovieClip(mValue.pData, pmc, instanceName, depth);
    }
    bool AttachMovie(Value* pmc, const char* symbolName, const char* instanceName, SInt32 depth = -1,
                     const MemberValueSet* initArgs = NULL)
    {
        return pObjectInterface->AttachMovie(mValue.pData, pmc, symbolName, instanceName, depth, initArgs);
    }
    bool GotoAndPlay(const char* frame) { return pObjectInterface->GotoAndPlay(mValue.pData, frame, false); }
    bool GotoAndStop(const char* frame) { return pObjectInterface->GotoAndPlay(mValue.pData, frame, true); }
    bool GotoAndPlay(unsigned frame)    { return pObjectInterface->GotoAndPlay(mValue.pData, frame, false); }
    bool GotoAndStop(unsigned frame)    { return pObjectInterface->GotoAndPlay(mValue.pData, frame, true); }
    Movie* GetMovie() const { return (Movie*)pObjectInterface->GetMovieImpl(); }

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
    // (appended, fq1) drops a managed value before the type changes
    void ChangeType(ValueType type)
    {
        if (IsManagedValue())
            ReleaseManagedValue();
        Type = type;
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
