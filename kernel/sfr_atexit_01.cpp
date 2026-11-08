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

#include <emmintrin.h>
#include "../gfx/sfr_gfx_07raw.h"
#include "ms2/scaleform/include/render/render_primitive.h"
#include "../include/render/render_bundle.h"
#include "ms2/scaleform/include/render/render_scale9grid.h"
#include "ms2/scaleform/include/gfx/as2/as2_pointobject.h"
#include "ms2/scaleform/include/gfx/as2/as2_rectangleobject.h"
#include "ms2/scaleform/include/gfx/as3/as3_value.h"
#include "ms2/scaleform/include/gfx/gfx_resource.h"
#include "ms2/scaleform/include/render/render_imagefile.h"

namespace Scaleform { namespace Render {
// The VertexXY16* formats render headers do not declare (Render_Vertex.cpp statics, 0x143a2fb88..0x143a2fc18).
struct VertexXY16f { static VertexFormat Format; };
struct VertexXY16fAlpha { static VertexFormat Format; };
struct VertexXY16iC32 { static VertexFormat Format; };
struct VertexXY16iInstance { static VertexFormat Format; };
struct VertexXY16iUV { static VertexFormat Format; };
// The glyph vertex formats (Render_GlyphCache statics 0x143a2fe50 / 0x143a30328); only their Format is used here.
struct RasterGlyphVertex { static VertexFormat Format; };
struct ImageGlyphVertex { static VertexFormat Format; };
}}

// The exit-time statics, as far as these destructors name them (defined in sfr_render_06e/06g/06d/07q and
// sfr_gfx_07e/08c/08d/08j).
namespace Scaleform { namespace Render {
struct SortKeyInterface;
extern SortKeyInterface SKI_NullInterface;
class SKI_Primitive { public: static SKI_Primitive Instance; static SKI_Primitive Instance3D; };
class SKI_ComplexPrimitive { public: static SKI_ComplexPrimitive Instance; static SKI_ComplexPrimitive Instance3D; };
class SKI_MaskEnd { public: class RQII_EndMask; static RQII_EndMask EndMaskItem; };
class SKI_BlendMode
{
public:
    class RQII_BlendMode;
    static RQII_BlendMode BlendModeItem;
    static SKI_BlendMode InstanceStart;
    static SKI_BlendMode InstanceEnd;
};
class SKI_Filter { public: static SKI_Filter InstanceStart; static SKI_Filter InstanceEnd; };
class SKI_ViewMatrix3D { public: static SKI_ViewMatrix3D InstanceStart; static SKI_ViewMatrix3D InstanceEnd; };
class SKI_ProjectionMatrix3D
{
public:
    static SKI_ProjectionMatrix3D InstanceStart;
    static SKI_ProjectionMatrix3D InstanceEnd;
};
class SKI_TextPrimitive { public: static SKI_TextPrimitive Instance; static SKI_TextPrimitive Instance3D; };
class HALBeginDisplayItem { public: static HALBeginDisplayItem Instance; };
class HALEndDisplayItem { public: static HALEndDisplayItem Instance; };
class AmpGlyphImageWriter { public: static AmpGlyphImageWriter Instance; };
// The image codecs' handler singletons (Render_TGA/JPEG/PNG/DDS.cpp), as render_tga.h etc. declare them.
namespace TGA { class FileReader { public: static FileReader Instance; }; }
namespace JPEG { class FileReader { public: static FileReader Instance; }; }
namespace PNG { class FileReader { public: static FileReader Instance; }; class FileWriter { public: static FileWriter Instance; }; }
namespace DDS { class FileReader { public: static FileReader Instance; }; }
}}

namespace Scaleform { namespace GFx {
class FontResourceCreator;
class GFxSystemFontResourceKeyInterface;
class ImageFileKeyInterface;
class SoundFileKeyInterface;
extern FontResourceCreator FontResourceCreator_Static;
extern GFxSystemFontResourceKeyInterface GFxSystemFontResourceKeyInterface_Instance;
extern ImageFileKeyInterface ImageFileKeyInterface_Instance;
extern SoundFileKeyInterface SoundFileKeyInterface_Instance;
}}

// AS2 Object_NotsetVal (0x143a51b50; Value(NOTSET), defined in data_data_game).
namespace Scaleform { namespace GFx { namespace AS2 { extern const Value Object_NotsetVal; } } }
namespace Scaleform { namespace Render { class RenderQueueProcessor; class RenderQueueItem { public: enum QIPrepareResult { QIP_Done, QIP_NeedCache }; class Interface { public: virtual ~Interface() {} virtual QIPrepareResult Prepare(RenderQueueItem&, RenderQueueProcessor&, bool waitForCache) { (void)waitForCache; return QIP_Done; } virtual void EmitToHAL(RenderQueueItem&, RenderQueueProcessor&) {} }; }; }}   // RenderQueueItem::Interface as render_primitivequeue.h has it (that header clashes with this TU kernel headers)
namespace Scaleform { namespace GFx {

// 0x143191990 = RenderQueueItem::Interface vftable (stored by its real inline dtor)
extern "C" char DAT_143a2dd20[];
extern "C" char DAT_143b15780[];
extern "C" char DAT_143a2f650[];
// SKI_MaskStart::Instance / InstanceClipped and SKI_MaskEnd::Instance (sfr_render_06e) stay DAT_ names: 06e takes
// their addresses in static data (the mask key table), so a real-name row would make the hook DLL rebind the
// definitions to the exe (ADDR64 against an exe global). sfr_render_06e binds these names to the definitions
// (definer-form /alternatename, full exe only).
extern "C" char DAT_143a2fd28[];
extern "C" char DAT_143a2fd38[];
extern "C" char DAT_143a2fd50[];

}}

namespace Scaleform { namespace GFx { namespace AS3 {
// Value's friend, as in sfr_as3_19: the out-of-line Value::ReleaseInternal (0x142521f00) is private.
struct ValueAssignCopies
{
    static void ReleaseInternal(Value& v) { v.ReleaseInternal(); }
};
}}}

namespace Scaleform { namespace GFx {

// The Ptr<SystemVertexFormat> slot of a VertexFormat static, released as raw storage like the other Ptr<>s.
static inline char* FormatSysSlot(Render::VertexFormat& format)
{
    return reinterpret_cast<char*>(&format) + 0x10;
}

// A named static's storage.
template <class T>
static inline char* RawObj(T& object)
{
    return reinterpret_cast<char*>(&object);
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
        if ((UByte)(flags >> 9) & 1)
        {
            int* proxy = RawField<int*>(v, 8);
            if (--*proxy == 0)
                Memory::Free(proxy);
            RawField<UInt32>(v, 0) &= ~0x21fu;
            _mm_storeu_si128(reinterpret_cast<__m128i*>(v + 8), _mm_setzero_si128());
            RawField<U>(v, 0x18) = 0;
        }
        else
            AS3::ValueAssignCopies::ReleaseInternal(*reinterpret_cast<AS3::Value*>(v));
    }
}

// AS2::Value::~Value: STRING and up hold a reference.
static inline void RawAs2ValueDtor(char* v)
{
    if (RawField<UByte>(v, 0) >= 5)
        reinterpret_cast<AS2::Value*>(v)->DropRefs();
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
// @0x142cc9300
void FUN_142cc9300()
{
    RawAs3ValueDtor(DAT_143a2dd20);
}

// static AS3::Value at 0x143b15780.
// @0x142cc9370
void FUN_142cc9370()
{
    RawAs3ValueDtor(DAT_143b15780);
}

// Render::TGA::FileReader::Instance (Render::ImageFileHandler): back to its interface base vftable.
// @0x142cc9440
void FUN_142cc9440()
{
    reinterpret_cast<Render::ImageFileHandler*>(RawObj(Render::TGA::FileReader::Instance))->Render::ImageFileHandler::~ImageFileHandler();
}

// Render::JPEG::FileReader::Instance (Render::ImageFileHandler): back to its interface base vftable.
// @0x142cc9450
void FUN_142cc9450()
{
    reinterpret_cast<Render::ImageFileHandler*>(RawObj(Render::JPEG::FileReader::Instance))->Render::ImageFileHandler::~ImageFileHandler();
}

// Render::PNG::FileReader::Instance (Render::ImageFileHandler): back to its interface base vftable.
// @0x142cc9460
void FUN_142cc9460()
{
    reinterpret_cast<Render::ImageFileHandler*>(RawObj(Render::PNG::FileReader::Instance))->Render::ImageFileHandler::~ImageFileHandler();
}

// Render::PNG::FileWriter::Instance (Render::ImageFileHandler): back to its interface base vftable.
// @0x142cc9470
void FUN_142cc9470()
{
    reinterpret_cast<Render::ImageFileHandler*>(RawObj(Render::PNG::FileWriter::Instance))->Render::ImageFileHandler::~ImageFileHandler();
}

// Render::DDS::FileReader::Instance (Render::ImageFileHandler): back to its interface base vftable.
// @0x142cc9480
void FUN_142cc9480()
{
    reinterpret_cast<Render::ImageFileHandler*>(RawObj(Render::DDS::FileReader::Instance))->Render::ImageFileHandler::~ImageFileHandler();
}

// static ResourceData::DataInterface at 0x143a2f430: back to its interface base vftable.
// @0x142cc9520
void FUN_142cc9520()
{
    reinterpret_cast<ResourceData::DataInterface*>(RawObj(GFx::FontResourceCreator_Static))->ResourceData::DataInterface::~DataInterface();
}

// static ResourceKey::KeyInterface at 0x143a2f690: back to its interface base vftable.
// @0x142cc9530
void FUN_142cc9530()
{
    reinterpret_cast<ResourceKey::KeyInterface*>(RawObj(GFx::GFxSystemFontResourceKeyInterface_Instance))->ResourceKey::KeyInterface::~KeyInterface();
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
    RawRefCountCoreDtor(DAT_143a2f650);
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
    reinterpret_cast<Render::SortKeyInterface*>(DAT_143a2fd38)->Render::SortKeyInterface::~SortKeyInterface();
}

// static Render::SortKeyInterface at 0x143a2fd28: back to its interface base vftable.
// @0x142cc9720
void FUN_142cc9720()
{
    reinterpret_cast<Render::SortKeyInterface*>(DAT_143a2fd28)->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_BlendMode::InstanceEnd (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9730
void FUN_142cc9730()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_BlendMode::InstanceEnd))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_Filter::InstanceEnd (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9740
void FUN_142cc9740()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_Filter::InstanceEnd))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_ProjectionMatrix3D::InstanceEnd (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9750
void FUN_142cc9750()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_ProjectionMatrix3D::InstanceEnd))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_ViewMatrix3D::InstanceEnd (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9760
void FUN_142cc9760()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_ViewMatrix3D::InstanceEnd))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_ComplexPrimitive::Instance3D (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9770
void FUN_142cc9770()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_ComplexPrimitive::Instance3D))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_Primitive::Instance3D (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9780
void FUN_142cc9780()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_Primitive::Instance3D))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_ComplexPrimitive::Instance (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9790
void FUN_142cc9790()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_ComplexPrimitive::Instance))->Render::SortKeyInterface::~SortKeyInterface();
}

// static Render::SortKeyInterface at 0x143a2fd50: back to its interface base vftable.
// @0x142cc97a0
void FUN_142cc97a0()
{
    reinterpret_cast<Render::SortKeyInterface*>(DAT_143a2fd50)->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_Primitive::Instance (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc97b0
void FUN_142cc97b0()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_Primitive::Instance))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_BlendMode::BlendModeItem (Render::RenderQueueItem::Interface): back to its interface base vftable.
// @0x142cc97c0
void FUN_142cc97c0()
{
    reinterpret_cast<Render::RenderQueueItem::Interface*>(RawObj(Render::SKI_BlendMode::BlendModeItem))->Render::RenderQueueItem::Interface::~Interface();
}

// SKI_MaskEnd::EndMaskItem (Render::RenderQueueItem::Interface): back to its interface base vftable.
// @0x142cc97d0
void FUN_142cc97d0()
{
    reinterpret_cast<Render::RenderQueueItem::Interface*>(RawObj(Render::SKI_MaskEnd::EndMaskItem))->Render::RenderQueueItem::Interface::~Interface();
}

// SKI_BlendMode::InstanceStart (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc97e0
void FUN_142cc97e0()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_BlendMode::InstanceStart))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_Filter::InstanceStart (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc97f0
void FUN_142cc97f0()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_Filter::InstanceStart))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_ProjectionMatrix3D::InstanceStart (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9800
void FUN_142cc9800()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_ProjectionMatrix3D::InstanceStart))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_ViewMatrix3D::InstanceStart (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9810
void FUN_142cc9810()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_ViewMatrix3D::InstanceStart))->Render::SortKeyInterface::~SortKeyInterface();
}

// static Render::SortKeyInterface at 0x143a2fe08: back to its interface base vftable.
// @0x142cc9820
void FUN_142cc9820()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_NullInterface))->Render::SortKeyInterface::~SortKeyInterface();
}

// static ResourceKey::KeyInterface at 0x143a2fe18: back to its interface base vftable.
// @0x142cc9830
void FUN_142cc9830()
{
    reinterpret_cast<ResourceKey::KeyInterface*>(RawObj(GFx::ImageFileKeyInterface_Instance))->ResourceKey::KeyInterface::~KeyInterface();
}

// HALBeginDisplayItem::Instance (Render::RenderQueueItem::Interface): back to its interface base vftable.
// @0x142cc9840
void FUN_142cc9840()
{
    reinterpret_cast<Render::RenderQueueItem::Interface*>(RawObj(Render::HALBeginDisplayItem::Instance))->Render::RenderQueueItem::Interface::~Interface();
}

// HALEndDisplayItem::Instance (Render::RenderQueueItem::Interface): back to its interface base vftable.
// @0x142cc9850
void FUN_142cc9850()
{
    reinterpret_cast<Render::RenderQueueItem::Interface*>(RawObj(Render::HALEndDisplayItem::Instance))->Render::RenderQueueItem::Interface::~Interface();
}

// RasterGlyphVertex::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a2fe60).
// @0x142cc9870
void FUN_142cc9870()
{
    RawReleasePtr(FormatSysSlot(Render::RasterGlyphVertex::Format));
}

// MS2-PIN: ??_7ImageFileHandler@Render@Scaleform@@6B@ 0x143184f20
// MS2-PIN: ??_7KeyInterface@ResourceKey@GFx@Scaleform@@6B@ 0x14318b240
// MS2-PIN: ??_7DataInterface@ResourceData@GFx@Scaleform@@6B@ 0x14318f548
// AmpGlyphImageWriter::Instance (Render::ImageFileHandler): back to its interface base vftable.
// @0x142cc9890
void FUN_142cc9890()
{
    reinterpret_cast<Render::ImageFileHandler*>(RawObj(Render::AmpGlyphImageWriter::Instance))->Render::ImageFileHandler::~ImageFileHandler();
}

// static ResourceKey::KeyInterface at 0x143a2fef8: back to its interface base vftable.
// @0x142cc98a0
void FUN_142cc98a0()
{
    reinterpret_cast<ResourceKey::KeyInterface*>(RawObj(GFx::SoundFileKeyInterface_Instance))->ResourceKey::KeyInterface::~KeyInterface();
}

// ImageGlyphVertex::Format.pSysFormat (Ptr<SystemVertexFormat>, 0x143a30338).
// @0x142cc98d0
void FUN_142cc98d0()
{
    RawReleasePtr(FormatSysSlot(Render::ImageGlyphVertex::Format));
}

// SKI_TextPrimitive::Instance3D (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc98f0
void FUN_142cc98f0()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_TextPrimitive::Instance3D))->Render::SortKeyInterface::~SortKeyInterface();
}

// SKI_TextPrimitive::Instance (Render::SortKeyInterface): back to its interface base vftable.
// @0x142cc9900
void FUN_142cc9900()
{
    reinterpret_cast<Render::SortKeyInterface*>(RawObj(Render::SKI_TextPrimitive::Instance))->Render::SortKeyInterface::~SortKeyInterface();
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
    RawAs2ValueDtor(reinterpret_cast<char*>(const_cast<AS2::Value*>(&AS2::Object_NotsetVal)));
}

}} // namespace Scaleform::GFx
// MS2-PIN: ??_7SortKeyInterface@Render@Scaleform@@6B@ 0x1431927c8
// MS2-PIN: ??_7Interface@RenderQueueItem@Render@Scaleform@@6B@ 0x143191990
// MS2-RANGE: 0x142cc9440-0x142cc948f .text$yd
