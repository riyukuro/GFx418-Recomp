// Recovered Scaleform 4.1.18 GFx AS2: flash.filters objects (the render filter is held natively).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_BITMAPFILTER_H
#define MS2_SF_GFX_AS2_BITMAPFILTER_H

#include "as2_movieroot.h"
#include "as2_objectproto.h"
#include "../../render/render_filters.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Common base of the filter objects.
class BitmapFilterObject : public Object
{
public:
    BitmapFilterObject(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }
    // A new filter object holding a default render filter of the type (none for other types).
    BitmapFilterObject(Environment* penv, Render::FilterType ft); // exe 0x142919250
    // The filter is set by the subclass.
    BitmapFilterObject(Environment* penv) : Object(penv) {}

    Render::Filter* GetFilter() const { return pFilter; }
    void            SetFilter(Render::Filter* pfilter) { pFilter = pfilter; }

    Ptr<Render::Filter> pFilter; // +0x68

    // Alpha of the first filter color, 0..1 (exe 0x1429497f0).
    float GetAlpha() const;

    // The filter itself, cloned first when it is shared (frozen).
    Render::Filter* writableFilter()
    {
        if (pFilter && pFilter->IsFrozen())
            pFilter = *pFilter->Clone(Memory::GetHeapByAddress(this));
        return pFilter;
    }
    // Shadow angle in radians; the offset follows (exe 0x14297fac0).
    void SetAngle(float a);
    // Shadow distance in twips (exe 0x142981320).
    void SetDistance(float d);

protected:
    // The blur parameters of the filter (exe 0x142995370).
    const Render::BlurFilterParams& readonlyFilterParams() const;
    // The same after writableFilter; a shared dummy for a non-blur filter (exe 0x142996690).
    Render::BlurFilterParams& writableFilterParams();

    virtual void Finalize_GC(); // exe 0x142942cf0
    virtual ~BitmapFilterObject(); // exe 0x142925560
public:
    virtual ObjectType GetObjectType() const; // exe 0x1429541b0
};

// The instance classes of the filters (0x70 bytes, all state in the render filter).
class BevelFilterObject : public BitmapFilterObject
{
public:
    BevelFilterObject(ASStringContext* psc, Object* pprototype) : BitmapFilterObject(psc, pprototype) {}
    BevelFilterObject(Environment* penv); // exe 0x142918d90

    virtual ObjectType GetObjectType() const; // exe 0x142954190
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x142985100
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x14294d800

protected:
    virtual ~BevelFilterObject(); // exe 0x142925640
};
class BlurFilterObject : public BitmapFilterObject
{
public:
    BlurFilterObject(ASStringContext* psc, Object* pprototype) : BitmapFilterObject(psc, pprototype) {}
    BlurFilterObject(Environment* penv); // exe 0x142919830

    virtual ObjectType GetObjectType() const; // exe 0x1429541c0
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x142985570
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x14294dd10

protected:
    virtual ~BlurFilterObject(); // exe 0x142925520
};
class ColorMatrixFilterObject : public BitmapFilterObject
{
public:
    ColorMatrixFilterObject(ASStringContext* psc, Object* pprototype) : BitmapFilterObject(psc, pprototype) {}
    ColorMatrixFilterObject(Environment* penv); // exe 0x14291ab70

    virtual ObjectType GetObjectType() const; // exe 0x1429541f0
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x1429856c0
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x14294e520

protected:
    virtual ~ColorMatrixFilterObject(); // exe 0x1429254e0
};
class DropShadowFilterObject : public BitmapFilterObject
{
public:
    DropShadowFilterObject(ASStringContext* psc, Object* pprototype) : BitmapFilterObject(psc, pprototype) {}
    DropShadowFilterObject(Environment* penv); // exe 0x14291b7d0

    virtual ObjectType GetObjectType() const; // exe 0x142954230
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x142985b50
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x14294ec10

protected:
    virtual ~DropShadowFilterObject(); // exe 0x142925600
};
class GlowFilterObject : public BitmapFilterObject
{
public:
    GlowFilterObject(ASStringContext* psc, Object* pprototype) : BitmapFilterObject(psc, pprototype) {}
    GlowFilterObject(Environment* penv); // exe 0x14291cde0

    virtual ObjectType GetObjectType() const; // exe 0x142954250
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x142986170
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x14294f260

protected:
    virtual ~GlowFilterObject(); // exe 0x142925990
};

// The filter prototypes: BitmapFilter has no methods, the others only add clone() (the table holds it, flags 0).
class BitmapFilterProto : public Prototype<BitmapFilterObject>
{
public:
    BitmapFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x1429196c0
};

class BevelFilterProto : public Prototype<BevelFilterObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213750

    BevelFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142918dd0

    static void Clone(const FnCall& fn);
};

class BlurFilterProto : public Prototype<BlurFilterObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213730

    BlurFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142919860

    static void Clone(const FnCall& fn);
};

class ColorMatrixFilterProto : public Prototype<ColorMatrixFilterObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213860

    ColorMatrixFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291ac10

    static void Clone(const FnCall& fn);
};

class DropShadowFilterProto : public Prototype<DropShadowFilterObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432136a0

    DropShadowFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291b810

    static void Clone(const FnCall& fn);
};

class GlowFilterProto : public Prototype<GlowFilterObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213710

    GlowFilterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291ce20

    static void Clone(const FnCall& fn);
};

// The ColorMatrixFilter class.
class ColorMatrixFilterCtorFunction : public CFunctionObject
{
public:
    ColorMatrixFilterCtorFunction(ASStringContext* psc); // exe 0x14291aaf0

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936bc0

    static void GlobalCtor(const FnCall& fn); // exe 0x1429598b0
};

// The classes of the other filters.
class BevelFilterCtorFunction : public CFunctionObject
{
public:
    BevelFilterCtorFunction(ASStringContext* psc); // exe 0x142918d10

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429368c0

    static void GlobalCtor(const FnCall& fn); // exe 0x142958720
};

class BlurFilterCtorFunction : public CFunctionObject
{
public:
    BlurFilterCtorFunction(ASStringContext* psc); // exe 0x1429197b0

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936940

    static void GlobalCtor(const FnCall& fn); // exe 0x1429591e0
};

class DropShadowFilterCtorFunction : public CFunctionObject
{
public:
    DropShadowFilterCtorFunction(ASStringContext* psc); // exe 0x14291b750

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936c80

    static void GlobalCtor(const FnCall& fn); // exe 0x14295a4b0
};

class GlowFilterCtorFunction : public CFunctionObject
{
public:
    GlowFilterCtorFunction(ASStringContext* psc); // exe 0x14291cd60

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936e90

    static void GlobalCtor(const FnCall& fn); // exe 0x14295b480
};

}}} // namespace Scaleform::GFx::AS2

#endif
