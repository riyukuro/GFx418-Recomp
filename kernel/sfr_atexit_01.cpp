// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): the .text$yd exit-time destructors the compiler emitted
// for Scaleform GFx 4.1.18 statics (two AS3 Values, the resource/sort-key/render-queue interface singletons, static
// Ptr<>s and the AS2 default-parameter Value arrays). Each runs the static's destructor, inline as the exe has it,
// on the exe's own object (bound through DAT_<va>). Our own source, written from the exe.
// MS2-UNIT: sfr_atexit_01
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142cc9300-0x142cc93de .text$yd
// MS2-RANGE: 0x142cc9520-0x142cc9566 .text$yd
// MS2-RANGE: 0x142cc95f0-0x142cc985f .text$yd
// MS2-RANGE: 0x142cc9870-0x142cc9881 .text$yd
// MS2-RANGE: 0x142cc9890-0x142cc98af .text$yd
// MS2-RANGE: 0x142cc98d0-0x142cc990f .text$yd
// MS2-RANGE: 0x142cca370-0x142cca4a4 .text$yd
// MS2-RANGE: 0x142cca4d0-0x142cca4e6 .text$yd

#include "../gfx/sfr_gfx_07raw.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_scale9grid.h"
#include "ms2/scaleform/include/gfx/as2/as2_pointobject.h"
#include "ms2/scaleform/include/gfx/as2/as2_rectangleobject.h"

namespace Scaleform { namespace Render {
// The VertexXY16* formats render headers do not declare (Render_Vertex.cpp statics, 0x143a2fb88..0x143a2fc18).
struct VertexXY16f { static VertexFormat Format; };
struct VertexXY16fAlpha { static VertexFormat Format; };
struct VertexXY16iC32 { static VertexFormat Format; };
struct VertexXY16iInstance { static VertexFormat Format; };
struct VertexXY16iUV { static VertexFormat Format; };
}}

namespace Scaleform { namespace GFx {

extern "C" char DAT_143184f20[];
extern "C" char DAT_14318b240[];
extern "C" char DAT_14318f548[];
extern "C" char DAT_143191990[];
extern "C" char DAT_1431927c8[];
extern "C" char DAT_143a2f430[];
extern "C" char DAT_143a2f690[];
extern "C" char DAT_143a2fce8[];
extern "C" char DAT_143a2fcf8[];
extern "C" char DAT_143a2fd08[];
extern "C" char DAT_143a2fd18[];
extern "C" char DAT_143a2fd28[];
extern "C" char DAT_143a2fd38[];
extern "C" char DAT_143a2fd48[];
extern "C" char DAT_143a2fd50[];
extern "C" char DAT_143a2fd80[];
extern "C" char DAT_143a2fd88[];
extern "C" char DAT_143a2fd98[];
extern "C" char DAT_143a2fda8[];
extern "C" char DAT_143a2fdb8[];
extern "C" char DAT_143a2fdc8[];
extern "C" char DAT_143a2fdd8[];
extern "C" char DAT_143a2fde8[];
extern "C" char DAT_143a2fdf8[];
extern "C" char DAT_143a2fe08[];
extern "C" char DAT_143a2fe18[];
extern "C" char DAT_143a2fe20[];
extern "C" char DAT_143a2fe28[];
extern "C" char DAT_143a2fe60[];
extern "C" char DAT_143a2fee8[];
extern "C" char DAT_143a2fef8[];
extern "C" char DAT_143a30338[];
extern "C" char DAT_143a30340[];
extern "C" char DAT_143a30350[];
extern "C" char DAT_143a2dd20[];
extern "C" char DAT_143b15780[];
extern "C" char DAT_143a2f650[];
extern "C" char DAT_143a51b50[];

void FUN_14257db40(void*);                  // RefCountImplCore::~RefCountImplCore
extern "C" void FUN_142521f00(void*);       // AS3::Value::ReleaseInternal
extern "C" void FUN_142939780(void*);       // AS2::Value::DropRefs

// The Ptr<SystemVertexFormat> slot of a VertexFormat static, released as raw storage like the other Ptr<>s.
static inline char* FormatSysSlot(Render::VertexFormat& format)
{
    return reinterpret_cast<char*>(&format) + 0x10;
}

static inline void RawSetVtable(char* object, char* vtable)
{
    RawField<void*>(object, 0) = vtable;
}

// Ptr<T>::~Ptr.
static inline void RawReleasePtr(char* slot)
{
    if (void* p = RawField<void*>(slot, 0))
        FUN_14257dcb0(p);
}

// AS3::Value::~Value (Flags +0, weak proxy +8, value +0x10): kinds above 9 hold a reference; a weak reference drops
// its proxy's count and clears itself, anything else goes through ReleaseInternal.
static inline void RawAs3ValueDtor(char* v)
{
    UInt32 flags = RawField<UInt32>(v, 0);
    if ((flags & 0x1f) > 9)
    {
        if ((flags >> 9) & 1)
        {
            int* proxy = RawField<int*>(v, 8);
            if (--*proxy == 0)
                Memory::Free(proxy);
            RawField<UInt32>(v, 0) &= ~0x21fu;
            RawField<U>(v, 8) = 0;
            RawField<U>(v, 0x10) = 0;
            RawField<U>(v, 0x18) = 0;
        }
        else
            FUN_142521f00(v);
    }
}

// AS2::Value::~Value: STRING and up hold a reference.
static inline void RawAs2ValueDtor(char* v)
{
    if (RawField<UByte>(v, 0) >= 5)
        FUN_142939780(v);
}

// `eh vector destructor iterator' over an AS2::Value array, last element first.
static inline void RawAs2ValueArrayDtor(char* end, U count)
{
    do
    {
        end -= 0x20;
        --count;
        RawAs2ValueDtor(end);
    } while (count);
}

// One past the last element of an AS2 Value array (the destructor walks it back to front).
template <unsigned N>
static inline char* As2ArrayEnd(const AS2::Value (&a)[N])
{
    return reinterpret_cast<char*>(const_cast<AS2::Value*>(a + N));
}

// static AS3::Value at 0x143a2dd20.
// MS2-FUNCTIONAL: the inlined weak-reference release is laid out differently.
// @0x142cc9300
void FUN_142cc9300()
{
    RawAs3ValueDtor(DAT_143a2dd20);
}

// static AS3::Value at 0x143b15780.
// MS2-FUNCTIONAL: the inlined weak-reference release is laid out differently.
// @0x142cc9370
void FUN_142cc9370()
{
    RawAs3ValueDtor(DAT_143b15780);
}

// static ResourceData::DataInterface at 0x143a2f430: back to its interface base vftable.
// @0x142cc9520
void FUN_142cc9520()
{
    RawSetVtable(DAT_143a2f430, DAT_14318f548);
}

// static ResourceKey::KeyInterface at 0x143a2f690: back to its interface base vftable.
// @0x142cc9530
void FUN_142cc9530()
{
    RawSetVtable(DAT_143a2f690, DAT_14318b240);
}

// The member's interface, as far as the destructor uses it (slot 2 lets it go).
struct Sfr21AtexitMember
{
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Drop() = 0;
};

// static RefCountImpl object at 0x143a2f650: lets go of its member at +0x10 (virtual slot 2), then the core dtor.
// @0x142cc9540
void FUN_142cc9540()
{
    if (Sfr21AtexitMember* member = RawField<Sfr21AtexitMember*>(DAT_143a2f650, 0x10))
        member->Drop();
    FUN_14257db40(DAT_143a2f650);
}

// Image9GridVertex::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2f978).
// @0x142cc95f0
void FUN_142cc95f0()
{
    RawReleasePtr(FormatSysSlot(Render::Image9GridVertex::Format));
}

// VertexXY16f::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fb98).
// @0x142cc9610
void FUN_142cc9610()
{
    RawReleasePtr(FormatSysSlot(Render::VertexXY16f::Format));
}

// VertexXY16fAlpha::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fbb0).
// @0x142cc9630
void FUN_142cc9630()
{
    RawReleasePtr(FormatSysSlot(Render::VertexXY16fAlpha::Format));
}

// VertexXY16i::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fb80).
// @0x142cc9650
void FUN_142cc9650()
{
    RawReleasePtr(FormatSysSlot(Render::VertexXY16i::Format));
}

// VertexXY16iAlpha::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fbe0).
// @0x142cc9670
void FUN_142cc9670()
{
    RawReleasePtr(FormatSysSlot(Render::VertexXY16iAlpha::Format));
}

// VertexXY16iC32::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fbc8).
// @0x142cc9690
void FUN_142cc9690()
{
    RawReleasePtr(FormatSysSlot(Render::VertexXY16iC32::Format));
}

// VertexXY16iCF32::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fbf8).
// @0x142cc96b0
void FUN_142cc96b0()
{
    RawReleasePtr(FormatSysSlot(Render::VertexXY16iCF32::Format));
}

// VertexXY16iInstance::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fc10).
// @0x142cc96d0
void FUN_142cc96d0()
{
    RawReleasePtr(FormatSysSlot(Render::VertexXY16iInstance::Format));
}

// VertexXY16iUV::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fc28).
// @0x142cc96f0
void FUN_142cc96f0()
{
    RawReleasePtr(FormatSysSlot(Render::VertexXY16iUV::Format));
}

// static Render::SortKeyInterface at 0x143a2fd38: back to its interface base vftable.
// @0x142cc9710
void FUN_142cc9710()
{
    RawSetVtable(DAT_143a2fd38, DAT_1431927c8);
}

// static Render::SortKeyInterface at 0x143a2fd28: back to its interface base vftable.
// @0x142cc9720
void FUN_142cc9720()
{
    RawSetVtable(DAT_143a2fd28, DAT_1431927c8);
}

// SKI_BlendMode::InstanceEnd (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9730
void FUN_142cc9730()
{
    RawSetVtable(DAT_143a2fd98, DAT_1431927c8);
}

// SKI_Filter::InstanceEnd (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9740
void FUN_142cc9740()
{
    RawSetVtable(DAT_143a2fdb8, DAT_1431927c8);
}

// SKI_ProjectionMatrix3D::InstanceEnd (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9750
void FUN_142cc9750()
{
    RawSetVtable(DAT_143a2fdf8, DAT_1431927c8);
}

// SKI_ViewMatrix3D::InstanceEnd (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9760
void FUN_142cc9760()
{
    RawSetVtable(DAT_143a2fdd8, DAT_1431927c8);
}

// SKI_ComplexPrimitive::Instance3D (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9770
void FUN_142cc9770()
{
    RawSetVtable(DAT_143a2fd18, DAT_1431927c8);
}

// SKI_Primitive::Instance3D (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9780
void FUN_142cc9780()
{
    RawSetVtable(DAT_143a2fcf8, DAT_1431927c8);
}

// SKI_ComplexPrimitive::Instance (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9790
void FUN_142cc9790()
{
    RawSetVtable(DAT_143a2fd08, DAT_1431927c8);
}

// static Render::SortKeyInterface at 0x143a2fd50: back to its interface base vftable.
// @0x142cc97a0
void FUN_142cc97a0()
{
    RawSetVtable(DAT_143a2fd50, DAT_1431927c8);
}

// SKI_Primitive::Instance (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc97b0
void FUN_142cc97b0()
{
    RawSetVtable(DAT_143a2fce8, DAT_1431927c8);
}

// SKI_BlendMode::BlendModeItem (Render::RenderQueueItem::Interface): back to its interface base vftable.
// @0x142cc97c0
void FUN_142cc97c0()
{
    RawSetVtable(DAT_143a2fd80, DAT_143191990);
}

// SKI_MaskEnd::EndMaskItem (Render::RenderQueueItem::Interface): back to its interface base vftable.
// @0x142cc97d0
void FUN_142cc97d0()
{
    RawSetVtable(DAT_143a2fd48, DAT_143191990);
}

// SKI_BlendMode::InstanceStart (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc97e0
void FUN_142cc97e0()
{
    RawSetVtable(DAT_143a2fd88, DAT_1431927c8);
}

// SKI_Filter::InstanceStart (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc97f0
void FUN_142cc97f0()
{
    RawSetVtable(DAT_143a2fda8, DAT_1431927c8);
}

// SKI_ProjectionMatrix3D::InstanceStart (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9800
void FUN_142cc9800()
{
    RawSetVtable(DAT_143a2fde8, DAT_1431927c8);
}

// SKI_ViewMatrix3D::InstanceStart (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9810
void FUN_142cc9810()
{
    RawSetVtable(DAT_143a2fdc8, DAT_1431927c8);
}

// static Render::SortKeyInterface at 0x143a2fe08: back to its interface base vftable.
// @0x142cc9820
void FUN_142cc9820()
{
    RawSetVtable(DAT_143a2fe08, DAT_1431927c8);
}

// static ResourceKey::KeyInterface at 0x143a2fe18: back to its interface base vftable.
// @0x142cc9830
void FUN_142cc9830()
{
    RawSetVtable(DAT_143a2fe18, DAT_14318b240);
}

// HALBeginDisplayItem::Instance (Render::RenderQueueItem::Interface): back to its interface base vftable.
// @0x142cc9840
void FUN_142cc9840()
{
    RawSetVtable(DAT_143a2fe20, DAT_143191990);
}

// HALEndDisplayItem::Instance (Render::RenderQueueItem::Interface): back to its interface base vftable.
// @0x142cc9850
void FUN_142cc9850()
{
    RawSetVtable(DAT_143a2fe28, DAT_143191990);
}

// static Ptr<> at 0x143a2fe60.
// @0x142cc9870
void FUN_142cc9870()
{
    RawReleasePtr(DAT_143a2fe60);
}

// AmpGlyphImageWriter::Instance (Render::ImageFileHandler): back to its interface base vftable.
// @0x142cc9890
void FUN_142cc9890()
{
    RawSetVtable(DAT_143a2fee8, DAT_143184f20);
}

// static ResourceKey::KeyInterface at 0x143a2fef8: back to its interface base vftable.
// @0x142cc98a0
void FUN_142cc98a0()
{
    RawSetVtable(DAT_143a2fef8, DAT_14318b240);
}

// static Ptr<> at 0x143a30338.
// @0x142cc98d0
void FUN_142cc98d0()
{
    RawReleasePtr(DAT_143a30338);
}

// SKI_TextPrimitive::Instance3D (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc98f0
void FUN_142cc98f0()
{
    RawSetVtable(DAT_143a30350, DAT_1431927c8);
}

// SKI_TextPrimitive::Instance (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9900
void FUN_142cc9900()
{
    RawSetVtable(DAT_143a30340, DAT_1431927c8);
}

// AS2 Point_DefaultParams, Value[2] at 0x143a51b70.
// @0x142cca370
void FUN_142cca370()
{
    RawAs2ValueArrayDtor(As2ArrayEnd(AS2::Point_DefaultParams), 2);
}

// AS2 Point_NanParams, Value[2] at 0x143d747b0.
// @0x142cca3c0
void FUN_142cca3c0()
{
    RawAs2ValueArrayDtor(As2ArrayEnd(AS2::Point_NanParams), 2);
}

// AS2 Rectangle_DefaultParams, Value[4] at 0x143a51bb0.
// @0x142cca410
void FUN_142cca410()
{
    RawAs2ValueArrayDtor(As2ArrayEnd(AS2::Rectangle_DefaultParams), 4);
}

// AS2 Rectangle_NaNParams, Value[4] at 0x143d74730.
// @0x142cca460
void FUN_142cca460()
{
    RawAs2ValueArrayDtor(As2ArrayEnd(AS2::Rectangle_NaNParams), 4);
}

// AS2 Object_NotsetVal (0x143a51b50).
// @0x142cca4d0
void FUN_142cca4d0()
{
    RawAs2ValueDtor(DAT_143a51b50);
}

}} // namespace Scaleform::GFx
