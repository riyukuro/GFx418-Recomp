// AS3 leftovers in the sfr_as2_01 map range: the fl_display loader plumbing (DisplayObject loader info, Loader set-up,
// LoaderInfo back pointer, Bitmap pixel-snapping names), FocusEventEx::MakeObject and the Date.parse thunk.
// The header-inline COMDATs in the same gaps (ImageDelegate::GetSize, ImageResource::SetImage, Image::Update,
// NumberUtil::IsNaN) are emitted by sfr_as3_06 / sfr_as2_01 and are left out.
// MS2-UNIT: sfr_as2_01e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423dfef0-0x1423e0090 .text$mn
// MS2-RANGE: 0x1424445d0-0x142444620 .text$mn
// MS2-RANGE: 0x142444620-0x1424447c0 .text$mn
// MS2-RANGE: 0x142446d90-0x142447020 .text$mn
// MS2-RANGE: 0x1424c96a0-0x1424c9700 .text$mn
#include <string.h>
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_display.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_gfx.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avmloader.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"

// ---- Date.parse thunk ----
namespace Scaleform { namespace GFx { namespace AS3 {
typedef ThunkFunc1<Classes::fl::Date, 0, Value::Number, const Value&> TFunc_Classes_fl_Date_parse;
// Method is the explicit specialization defined with the method table (sfr_as3di_01); the instantiation only refers
// to it.
// @0x1423dfef0
template void TFunc_Classes_fl_Date_parse::Func(const ThunkInfo&, VM&, const Value&, Value&, unsigned, const Value*);
typedef ThunkFunc2<Classes::fl::Date, 1, Value, unsigned, const Value*> TFunc_Classes_fl_Date_UTC;
// Date.UTC's thunk (no .pdata: the forwarding jmp); Method is likewise sfr_as3di_01's specialization.
// @0x1423e0070
template void TFunc_Classes_fl_Date_UTC::Func(const ThunkInfo&, VM&, const Value&, Value&, unsigned, const Value*);
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Classes@AS3@GFx@Scaleform@@$00VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1423e0070
}}} // namespace Scaleform::GFx::AS3

// ---- fl_display: loader info ----
// Bodies of the exe called here (not recovered yet), by their addresses.
// ASVM::_constructInstance: makes an instance of classObj into pobj.
bool FUN_142531f40(Scaleform::GFx::AS3::VM& vm, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>& pobj,
                   Scaleform::GFx::AS3::Object* classObj, unsigned argc, const Scaleform::GFx::AS3::Value* argv);
// AvmDisplayObj::AssignAS3Obj: makes pinst the AS3 object of pavm.
void FUN_1424edca0(Scaleform::GFx::AvmDisplayObjBase* pavm, Scaleform::GFx::AS3::Instances::fl_display::DisplayObject* pinst);
// MovieRoot::AddScriptableMovieClip.
void FUN_1424e9380(Scaleform::GFx::AS3::MovieRoot* proot, Scaleform::GFx::DisplayObject* pcont);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl_display
{
    // Defined with the BitmapData bodies (sfr_as3_06).
    bool BindLibraryBitmap(BitmapData* pthis, Resource* pres, MovieDefImpl* pdefImpl);

    // A movie clip has frame scripts once addFrameScript set any.
    // @0x1424445d0
    bool MovieClip::HasFrameScript() const
    {
        return frameScript.DescrCnt != 0;
    }

    // @0x1424445e0
    bool Sprite::HasFrameScript() const
    {
        return false;
    }

    // MS2-PIN
    // @0x1424445f0
    bool DisplayObject::HasLoaderInfo() const
    {
        return pLoaderInfo.GetPtr() != NULL;
    }

    // A timeline bitmap makes its stage object up front.
    // @0x142444600
    void Bitmap::InitInstance(bool extCall)
    {
        if (!extCall)
            Bitmap::CreateStageObject();
    }

    // A timeline bitmap data binds its library image.
    // @0x142444610
    void BitmapData::InitInstance(bool extCall)
    {
        if (!extCall)
            BindLibraryBitmap(this, 0, 0);
    }

    // A script-created loader gets a fresh LoaderInfo and a loader stage object; one made for the timeline hands its
    // content's LoaderInfo the back pointer.
    // @0x142444620
    // MS2-FUNCTIONAL the exe inlines CreateStageObject
    void Loader::InitInstance(bool extCall)
    {
        VM& vm = GetVM();
        if (!extCall)
        {
            SPtr<Class> cls = vm.GetClass(StringDataPtr("flash.display.LoaderInfo", 0x18));
            FUN_142531f40(vm, reinterpret_cast<SPtr<AS3::Object>&>(pContentLoaderInfo), cls.GetPtr(), 0, NULL);
            pContentLoaderInfo->SetLoader(this);
            if (!pDispObj)
            {
                MovieRoot* proot = static_cast<ASVM&>(GetVM()).GetMovieRoot();
                AvmLoader* p = SF_HEAP_NEW(proot->GetMovieImpl()->GetMovieHeap())
                    AvmLoader(proot, proot->GetMovieImpl()->pMainMovieDef, NULL, ResourceId(0x40000));
                if (pDispObj)
                    pDispObj->Release();
                pDispObj.GetRawRef() = p;
                FUN_1424edca0(pDispObj ? pDispObj->GetAvmObjImpl() : NULL, this);
                FUN_1424e9380(proot, pDispObj);
            }
        }
        else if (pDispObj)
        {
            Instances::fl_display::DisplayObject* pas3 = ToAvmDisplayObj(pDispObj)->GetAS3Obj();
            if (pas3 && pas3->pLoaderInfo)
                pas3->pLoaderInfo->SetLoader(this);
        }
    }

    // @0x142446d90
    void LoaderInfo::SetLoader(Loader* p)
    {
        pLoader = p;
    }

    // @0x142446e00
    void DisplayObject::SetLoaderInfo(const Loader& l)
    {
        pLoaderInfo = l.pContentLoaderInfo.GetPtr();
    }

    // @0x142446e70
    void DisplayObject::SetLoaderInfo(LoaderInfo* li)
    {
        SPtr<DisplayObject> self(this);
        self->pLoaderInfo = li;
    }

    // The pixelSnapping names; anything else throws.
    // @0x142446f30
    SInt32 Bitmap::String2PixelSnapping(const char* pname)
    {
        if (strcmp(pname, "never") == 0)
            return 0;
        if (strcmp(pname, "always") == 0)
            return 1;
        if (strcmp(pname, "auto") == 0)
            return 2;
        VM& vm = GetVM();
        vm.ThrowArgumentError(VM::Error(VM::eInvalidEnumParamError, vm, "pixelSnapping"));
        return 0;
    }
}} // namespace Instances::fl_display

namespace InstanceTraits { namespace fl_gfx
{
    // MS2-FUNCTIONAL: the exe inlines the instance ctor (whole-program optimisation); here it is a call
    // @0x1424c96a0
    void FocusEventEx::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) InstanceType(t));
    }
}} // namespace InstanceTraits::fl_gfx

}}} // namespace Scaleform::GFx::AS3
