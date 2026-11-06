// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 style sheet file loader
// destructor (gap recovery of sfr_as2_03).
// MS2-UNIT: sfr_as2_03ad
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429255c0-0x1429255fb .text$mn

#include "../include/gfx/as2/as2_loadqueue.h"
#include "../include/kernel/sf_std.h"

// The dtor is `inline` under cl, so its copy here is COMDAT-any: sfr_as2_04g inlines the same body into the deleting
// dtor 0x14292a050 and cl (no /Zc:inline) emits its copy too. MS2_Sfr03adEmitDtor keeps it emitted here.
#if defined(__clang__)
#define SFR03AD_INLINE
#else
#define SFR03AD_INLINE inline
#endif

namespace Scaleform { namespace GFx { namespace AS2 {

// The parser's view of the loader: the parsed CSS text buffer sits at +0x18 (the full class is in sfr_as2_06).
class CSSFileLoaderAndParserImpl : public ASCSSFileLoader
{
public:
    UByte    Unrecovered_10[8];
    wchar_t* Buffer;
    int      BufferLen;

    virtual ~CSSFileLoaderAndParserImpl();
    virtual void Load(const String& fileName, FileOpener* opener);
    virtual void Init(Environment* penv, Object* sheet);
};

// @0x1429255c0
SFR03AD_INLINE CSSFileLoaderAndParserImpl::~CSSFileLoaderAndParserImpl()
{
    if (Buffer)
        Memory::pGlobalHeap->Free(Buffer);
}

// Calls the inline dtor out of line (inline_depth 0), so cl emits it (and the vftable and ??_G) here. Nothing calls it.
#pragma inline_depth(0)
void MS2_Sfr03adEmitDtor(CSSFileLoaderAndParserImpl* p)
{
    p->CSSFileLoaderAndParserImpl::~CSSFileLoaderAndParserImpl();
}
#pragma inline_depth()

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7CSSFileLoaderAndParserImpl@AS2@GFx@Scaleform@@6B@ 0x143222848
// MS2-PIN: ??_7ASCSSFileLoader@AS2@GFx@Scaleform@@6B@ 0x1432172f0
