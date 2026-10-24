// Recovered Scaleform GFx 4.1.18 AS3: the ObjectInterface of the AS3 movie root, through which a GFx::Value that
// holds an AS3 object, array, display object or closure reaches the VM. 0x10 bytes (only the base's pMovieRoot),
// vftable 0x14317eff8 (40 slots, the order of Value::ObjectInterface in gfx_value.h); the deleting destructor
// 0x1424e2150 puts back the base vftable 0x14317bc90 and frees 0x10 bytes. The movie root builds it inline
// (sfr_as3_15, sfr_as3_17). The exe mangles the overrides as private virtuals (EEAA / EEBA).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder the virtuals.
//
// Units that define a local class AS3ValueObjectInterface of their own (sfr_as3_17) must not include this header.
// A unit that constructs one makes the compiler emit the vftable, which needs every slot below defined or pinned.
#ifndef MS2_SF_GFX_AS3_VALUEOBJECTINTERFACE_H
#define MS2_SF_GFX_AS3_VALUEOBJECTINTERFACE_H

#include "ms2/scaleform/include/gfx/gfx_value.h"

namespace Scaleform { namespace GFx {

class AS3ValueObjectInterface : public Value::ObjectInterface
{
public:
    AS3ValueObjectInterface(MovieImpl* pmovieRoot) : Value::ObjectInterface(pmovieRoot) {}
    virtual ~AS3ValueObjectInterface() {}                                                            // 0x1424e2150 (??_G)

private:
    virtual void     ObjectAddRef(Value* val, void* pobj);                                          // 1  0x142518530
    virtual void     ObjectRelease(Value* val, void* pobj);                                         // 2  0x142518570
    virtual bool     HasMember(void* pdata, const char* name, bool isdobj) const;                   // 3  0x142510e70
    virtual bool     GetMember(void* pdata, const char* name, Value* pval, bool isdobj) const;      // 4  0x14250b4a0
    virtual bool     SetMember(void* pdata, const char* name, const Value& value, bool isdobj);    // 5  0x142527d60
    virtual bool     Invoke(void* pdata, Value* presult, const char* name, const Value* pargs, UPInt nargs,
                            bool isdobj);                                                           // 6  0x142512870
    virtual bool     InvokeClosure(void* pdata, UPInt dataAux, Value* presult, const Value* pargs,
                                   UPInt nargs);                                                    // 7  0x142513920
    virtual bool     DeleteMember(void* pdata, const char* name, bool isdobj);                     // 8  0x1424f4780
    virtual void     VisitMembers(void* pdata, ObjVisitor* visitor, bool isdobj) const;            // 9  0x142531630
    virtual unsigned GetArraySize(void* pdata) const;                                              // 10 0x142507540
    virtual bool     SetArraySize(void* pdata, unsigned sz);                                       // 11 0x1425265d0
    virtual bool     GetElement(void* pdata, unsigned idx, Value* pval) const;                     // 12 0x142509ad0
    virtual bool     SetElement(void* pdata, unsigned idx, const Value& value);                    // 13 0x142527300
    virtual void     VisitElements(void* pdata, ArrVisitor* visitor, unsigned idx, int count) const; // 14 0x142531550
    virtual bool     PushBack(void* pdata, const Value& value);                                    // 15 0x14251f780
    virtual bool     PopBack(void* pdata, Value* pval);                                            // 16 0x14251cbe0
    virtual bool     RemoveElements(void* pdata, unsigned idx, int count);                         // 17 0x1425227e0
    virtual bool     IsDisplayObjectActive(void* pdata) const;                                     // 18 0x142514240
    virtual bool     GetDisplayInfo(void* pdata, Value::DisplayInfo* pinfo) const;                 // 19 0x1425094e0
    virtual bool     SetDisplayInfo(void* pdata, const Value::DisplayInfo& info);                  // 20 0x142526730
    virtual bool     GetWorldMatrix(void* pdata, Render::Matrix2x4<float>* pmat) const;            // 21 0x142510a70
    virtual bool     GetDisplayMatrix(void* pdata, Render::Matrix2x4<float>* pmat) const;          // 22 0x142509850
    virtual bool     SetDisplayMatrix(void* pdata, const Render::Matrix2x4<float>& mat);           // 23 0x1425270e0
    virtual bool     GetMatrix3D(void* pdata, Render::Matrix3x4<float>* pmat) const;               // 24 0x14250b3c0
    virtual bool     SetMatrix3D(void* pdata, const Render::Matrix3x4<float>& mat);                // 25 0x1425278d0
    virtual bool     GetCxform(void* pdata, Render::Cxform* pcx) const;                            // 26 0x142508560
    virtual bool     SetCxform(void* pdata, const Render::Cxform& cx);                             // 27 0x1425266c0
    virtual bool     GetText(void* pdata, Value* pval, bool ishtml) const;                         // 28 0x14250f110
    virtual bool     SetText(void* pdata, const char* ptext, bool ishtml);                         // 30 0x14252a230
    virtual bool     SetText(void* pdata, const wchar_t* ptext, bool ishtml);                      // 29 0x14252a360
    virtual bool     CreateEmptyMovieClip(void* pdata, Value* pmc, const char* instanceName,
                                          SInt32 depth);                                            // 31 0x1424f33d0
    virtual bool     AttachMovie(void* pdata, Value* pmc, const char* symbolName, const char* instanceName,
                                 SInt32 depth, const MemberValueSet* initArgs);                     // 32 0x1424ede80
    virtual bool     GotoAndPlay(void* pdata, const char* frame, bool stop);                       // 34 0x142510c30
    virtual bool     GotoAndPlay(void* pdata, unsigned frame, bool stop);                          // 33 0x142510b70
    virtual void     ToString(String* pstr, const Value& thisVal) const;                           // 35 0x14252fd40
    virtual void     SetUserData(void* pdata, ASUserData* puserdata, bool isdobj);                 // 36 0x14252a4f0
    virtual ASUserData* GetUserData(void* pdata, bool isdobj) const;                               // 37 0x14250f980
    virtual bool     CreateObjectValue(Value* pval, void* pdata, bool isdobj);                     // 38 0x1424f3d20
    virtual AMP::ViewStats* GetAdvanceStats() const;                                               // 39 0x1425071d0
};
// The deleting destructor 0x1424e2150 frees 0x10 bytes.
static_assert(sizeof(AS3ValueObjectInterface) == 0x10, "AS3ValueObjectInterface size");

}} // namespace Scaleform::GFx

#endif
