// Recovered Scaleform GFx 4.1.18 AS3: the shared object loader SharedObject.getLocal hands the shared object
// manager. Our own declaration. Methods in sfr_as3_12; its deleting dtor (0x1424974d0) and its bases' are COMDATs the
// exe keeps in sfr_as3_11's range.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_OBJ_NET_SOLOADER_H
#define MS2_SF_GFX_AS3_OBJ_NET_SOLOADER_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/gfx_sharedobject.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// Rebuilds the data object of a shared object from the visits of the shared object manager (SharedObject.getLocal).
// 0x40 bytes.
class ASSharedObjectLoader : public SharedObjectVisitor
{
public:
    ASSharedObjectLoader(VM* pvm, Instances::fl::Object* psobj)
        : pVM(pvm), pData(psobj), bArrayIsTop(false) {}

    virtual void Begin();
    virtual void PushObject(const String& name);
    virtual void PushArray(const String& name);
    virtual void AddProperty(const String& name, const String& value, GFx::Value::ValueType type);
    virtual void PopObject();
    virtual void PopArray();
    virtual void End();

private:
    VM*                                 pVM;            // +0x10
    Instances::fl::Object*              pData;          // +0x18
    ArrayLH<AS3::Object*>               ObjectStack;    // +0x20
    bool                                bArrayIsTop;    // +0x38
};

}}} // namespace Scaleform::GFx::AS3

#endif
