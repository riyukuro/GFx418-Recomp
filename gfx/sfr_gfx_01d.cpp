// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ZlibSupport (the zlib state:
// compressed SWF files and DefineBitsLossless data).
// Fourth source of queue unit sfr_gfx_01 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_01d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14258f1a0-0x14258f330 .text$mn

#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/gfx/gfx_stream.h"

// The part of zlib 1.2's stream state used here (0x58 bytes on x64); the zlib in the exe is linked as C.
struct z_stream_s
{
    const unsigned char* next_in;   // +0
    unsigned             avail_in;  // +8
    unsigned long        total_in;  // +0xc
    unsigned char*       next_out;  // +0x10
    unsigned             avail_out; // +0x18
    unsigned long        total_out; // +0x1c
    char*                msg;       // +0x20
    void*                state;     // +0x28
    void*                zalloc;    // +0x30
    void*                zfree;     // +0x38
    void*                opaque;    // +0x40
    int                  data_type; // +0x48
    unsigned long        adler;     // +0x4c
    unsigned long        reserved;  // +0x50
};

extern "C" int inflate(z_stream_s* strm, int flush);
extern "C" int inflateEnd(z_stream_s* strm);

namespace Scaleform { namespace GFx {

enum
{
    ZLib_OK         = 0,
    ZLib_StreamEnd  = 1,
    ZLib_SyncFlush  = 2
};

// @0x14258f1a0
File* ZlibSupport::CreateZlibFile(File* in)
{
    return SF_HEAP_AUTO_NEW(this) ZLibFile(in);
}

// Inflates zlib data from pin into buffer (bufferBytes long); input read past the end of the data is pushed back.
// @0x14258f1f0
void ZlibSupport::InflateWrapper(Stream* pin, void* buffer, int bufferBytes)
{
    z_stream_s zstream;
    int        err = ZLibFile::ZLib_InitStream(&zstream, this, buffer, bufferBytes);
    if (err != ZLib_OK)
    {
        pin->LogError("GFx_InflateWrapper() inflateInit() returned %d", err);
        return;
    }

    UByte buf[32];
    for (;;)
    {
        zstream.next_in  = buf;
        zstream.avail_in = pin->ReadToBuffer(buf, sizeof(buf));

        err = inflate(&zstream, ZLib_SyncFlush);
        if (err == ZLib_StreamEnd)
            break;
        if (err != ZLib_OK)
        {
            pin->LogError("GFx_InflateWrapper() Inflate() returned %d", err);
            // Pushed back here and again below: the error path moves back twice.
            if (zstream.avail_in)
                pin->SetPosition(pin->Tell() - zstream.avail_in);
            break;
        }
    }

    if (zstream.avail_in)
        pin->SetPosition(pin->Tell() - zstream.avail_in);

    err = inflateEnd(&zstream);
    if (err != ZLib_OK)
        pin->LogError("GFx_InflateWrapper() InflateEnd() return %d", err);
}

}} // namespace Scaleform::GFx

// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
