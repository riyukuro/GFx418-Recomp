// Recovered Scaleform GFx 4.1.18 AS2: the movie's GFx::Value object interface, which reaches AS2 objects, arrays
// and display objects for the host. 0x10 bytes (MovieRoot::CreateObjectInterface 0x1429379d0 allocates 0x10 and
// stores the vftable and the movie); vftable 0x143222128, 40 slots (??_G 0x142928d00).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// (sfr24) sfr_as2_04, 04p, 04q, 05 and 06 still declare partial local copies of this class for the bodies they
// define. A unit has to drop its local copy before it includes this header.
#ifndef MS2_SF_GFX_AS2_VALUEOBJECTINTERFACE_H
#define MS2_SF_GFX_AS2_VALUEOBJECTINTERFACE_H

#include "../gfx_value.h"

namespace Scaleform { namespace GFx {

class AS2ValueObjectInterface : public Value::ObjectInterface
{
public:
    AS2ValueObjectInterface(MovieImpl* pmovieRoot) : ObjectInterface(pmovieRoot) {}
    virtual ~AS2ValueObjectInterface() {}                                                                     // 0

    // The overrides are all private in the exe (manglings @@EE / @@EB). Slot numbers as in Value::ObjectInterface.
private:
    virtual void     ObjectAddRef(Value* val, void* pobj);                                    // 1  0x14296a990
    virtual void     ObjectRelease(Value* val, void* pobj);                                   // 2  0x14296a9f0
    virtual bool     HasMember(void* pdata, const char* name, bool isdobj) const;             // 3  0x14295d5e0
    virtual bool     GetMember(void* pdata, const char* name, Value* pval, bool isdobj) const;// 4  0x14294bbb0
    virtual bool     SetMember(void* pdata, const char* name, const Value& value, bool isdobj);// 5 0x1429829c0
    virtual bool     Invoke(void* pdata, Value* presult, const char* name, const Value* pargs, UPInt nargs,
                            bool isdobj);                                                     // 6  0x142962710
    virtual bool     InvokeClosure(void* pdata, UPInt dataAux, Value* presult, const Value* pargs,
                                   UPInt nargs);                                              // 7  0x142964380
    virtual bool     DeleteMember(void* pdata, const char* name, bool isdobj);                // 8  0x1429384f0
    virtual void     VisitMembers(void* pdata, ObjVisitor* visitor, bool isdobj) const;       // 9  0x1429943f0
    virtual unsigned GetArraySize(void* pdata) const;                                         // 10 0x142949820
    virtual bool     SetArraySize(void* pdata, unsigned sz);                                  // 11 0x14297fb80
    virtual bool     GetElement(void* pdata, unsigned idx, Value* pval) const;                // 12 0x14294a9b0
    virtual bool     SetElement(void* pdata, unsigned idx, const Value& value);               // 13 0x1429813e0
    virtual void     VisitElements(void* pdata, ArrVisitor* visitor, unsigned idx, int count) const; // 14 0x142994280
    virtual bool     PushBack(void* pdata, const Value& value);                               // 15 0x142971ac0
    virtual bool     PopBack(void* pdata, Value* pval);                                       // 16 0x14296f0d0
    virtual bool     RemoveElements(void* pdata, unsigned idx, int count);                    // 17 0x14297d080
    virtual bool     IsDisplayObjectActive(void* pdata) const;                                // 18 0x1429654a0
    virtual bool     GetDisplayInfo(void* pdata, Value::DisplayInfo* pinfo) const;            // 19 0x14294a5b0
    virtual bool     SetDisplayInfo(void* pdata, const Value::DisplayInfo& info);             // 20 0x142980790
    virtual bool     GetWorldMatrix(void* pdata, Render::Matrix2x4<float>* pmat) const;       // 21 0x142958290
    virtual bool     GetDisplayMatrix(void* pdata, Render::Matrix2x4<float>* pmat) const;     // 22 0x14294a8f0
    virtual bool     SetDisplayMatrix(void* pdata, const Render::Matrix2x4<float>& mat);      // 23 0x142981130
    virtual bool     GetMatrix3D(void* pdata, Render::Matrix3x4<float>* pmat) const;          // 24 0x14294b250
    virtual bool     SetMatrix3D(void* pdata, const Render::Matrix3x4<float>& mat);           // 25 0x142981f00
    virtual bool     GetCxform(void* pdata, Render::Cxform* pcx) const;                       // 26 0x14294a500
    virtual bool     SetCxform(void* pdata, const Render::Cxform& cx);                        // 27 0x1429803d0
    virtual bool     GetText(void* pdata, Value* pval, bool ishtml) const;                    // 28 0x142956270
    virtual bool     SetText(void* pdata, const char* ptext, bool ishtml);                    // 30 0x14298be80
    virtual bool     SetText(void* pdata, const wchar_t* ptext, bool ishtml);                 // 29 0x14298bfa0
    virtual bool     CreateEmptyMovieClip(void* pdata, Value* pmc, const char* instanceName,
                                          SInt32 depth);                                      // 31 0x142935ea0
    virtual bool     AttachMovie(void* pdata, Value* pmc, const char* symbolName, const char* instanceName,
                                 SInt32 depth, const MemberValueSet* initArgs);               // 32 0x1429318d0
    virtual bool     GotoAndPlay(void* pdata, const char* frame, bool stop);                  // 34 0x14295d3a0
    virtual bool     GotoAndPlay(void* pdata, unsigned frame, bool stop);                     // 33 0x14295d320
    virtual void     ToString(String* pstr, const Value& thisVal) const;                      // 35 0x142991d30
    virtual void     SetUserData(void* pdata, ASUserData* puserdata, bool isdobj);            // 36 0x14298ca20
    virtual ASUserData* GetUserData(void* pdata, bool isdobj) const;                          // 37 0x142956be0
    virtual bool     CreateObjectValue(Value* pval, void* pdata, bool isdobj);                // 38 0x142937a20
    virtual AMP::ViewStats* GetAdvanceStats() const;                                          // 39 0x1429497d0
};
static_assert(sizeof(AS2ValueObjectInterface) == 0x10, "AS2ValueObjectInterface size");

}} // namespace Scaleform::GFx

#endif
