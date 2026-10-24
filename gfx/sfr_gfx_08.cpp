// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ZLibFile (a File that
// inflates a zlib compressed source file as it is read; seeking backwards restarts the stream unless the target
// is still in the 4 KB backtrack buffer).
// First source of queue unit sfr_gfx_08 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_08
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142645600-0x142645cd0 .text$mn
// MS2-RANGE: 0x142645cf0-0x142646180 .text$mn   (0x142645cd0: AS3 SocketBuffer::LTell, not this TU)

#include "../include/kernel/sf_alg.h"
#include "../include/kernel/sf_file.h"
#include "../include/gfx/gfx_characterdef.h"
#include "../include/kernel/sf_memory.h"
#include <string.h>

// zlib 1.2's stream state (0x58 bytes on x64); the zlib in the exe is linked as C.
typedef void* (*ZLib_AllocFunc)(void* opaque, unsigned items, unsigned size);
typedef void  (*ZLib_FreeFunc)(void* opaque, void* address);

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
    ZLib_AllocFunc       zalloc;    // +0x30
    ZLib_FreeFunc        zfree;     // +0x38
    void*                opaque;    // +0x40
    int                  data_type; // +0x48
    unsigned long        adler;     // +0x4c
    unsigned long        reserved;  // +0x50
};

extern "C" int inflate(z_stream_s* strm, int flush);
extern "C" int inflateEnd(z_stream_s* strm);
extern "C" int inflateReset(z_stream_s* strm);
extern "C" int inflateInit_(z_stream_s* strm, const char* version, int streamSize);

namespace Scaleform { namespace GFx {

enum
{
    ZLib_OK        = 0,
    ZLib_StreamEnd = 1,
    ZLib_SyncFlush = 2
};

// The zlib allocations go to the heap that owns the opaque address.
static void* ZLib_Alloc(void* opaque, unsigned items, unsigned size)
{
    return SF_HEAP_AUTO_ALLOC(opaque, items * size);
}

static void ZLib_Free(void* opaque, void* address)
{
    SF_FREE(address);
}

// 0x207c bytes.
class ZLibFileImpl : public NewOverrideBase<Stat_Default_Mem>
{
public:
    enum { BuffSize = 0x1000 };

    Ptr<File>  pIn;              // +0x00 compressed source
    z_stream_s ZStream;          // +0x08
    int        StartPos;         // +0x60 source position of the compressed data
    int        InflatedPos;      // +0x64 bytes inflated so far
    bool       AtEnd;            // +0x68 zlib reported the end of the stream
    int        ErrorCode;        // +0x6c
    int        UserPos;          // +0x70 read position, <= InflatedPos
    int        BacktrackTail;    // +0x74 end of the newest data in Backtrack (it wraps around)
    int        BacktrackSize;    // +0x78 valid bytes in Backtrack
    UByte      Backtrack[BuffSize]; // +0x7c the last inflated bytes
    UByte      Input[BuffSize];     // +0x107c compressed input

    ZLibFileImpl(File* pin)
    {
        pIn         = pin;
        StartPos    = pin->Tell();
        InflatedPos = 0;
        AtEnd       = false;
        ErrorCode   = 0;
        if (ZLibFile::ZLib_InitStream(&ZStream, this, 0, 0) != ZLib_OK)
        {
            ErrorCode = 1;
            return;
        }
        BacktrackSize = 0;
        BacktrackTail = 0;
        UserPos       = 0;
    }

    // Gives the input zlib has not consumed back to the source.
    void ReturnInput()
    {
        if (ZStream.avail_in > 0)
        {
            int pos = pIn->Tell();
            pIn->Seek(pos - ZStream.avail_in);
        }
    }

    // Rewinds to the start of the compressed data.
    void Restart()
    {
        ErrorCode = 0;
        AtEnd     = false;
        if (inflateReset(&ZStream) != ZLib_OK)
        {
            ErrorCode = 1;
            return;
        }
        ZStream.next_in   = 0;
        ZStream.avail_in  = 0;
        ZStream.next_out  = 0;
        ZStream.avail_out = 0;
        pIn->Seek(StartPos);
        InflatedPos   = 0;
        BacktrackSize = 0;
        BacktrackTail = 0;
        UserPos       = 0;
    }

    int InflateStream(void* buffer, int bytes);
    int Inflate(void* buffer, int bytes);
    int SetPosition(int pos);
};

// Inflates up to bytes bytes into buffer; returns the count.
inline int ZLibFileImpl::InflateStream(void* buffer, int bytes)
{
    if (ErrorCode)
        return 0;

    ZStream.next_out  = (unsigned char*)buffer;
    ZStream.avail_out = bytes;
    for (;;)
    {
        if (ZStream.avail_in == 0)
        {
            int n = pIn->Read(Input, BuffSize);
            if (n == 0)
                break;
            ZStream.next_in  = Input;
            ZStream.avail_in = n;
        }
        int err = inflate(&ZStream, ZLib_SyncFlush);
        if (err == ZLib_StreamEnd)
        {
            AtEnd = true;
            break;
        }
        if (err != ZLib_OK)
        {
            ErrorCode = 1;
            break;
        }
        if (ZStream.avail_out == 0)
            break;
    }

    int inflated = bytes - ZStream.avail_out;
    InflatedPos += inflated;
    return inflated;
}

// Reads up to bytes bytes at UserPos: first from the backtrack buffer, then by inflating more input.
// @0x142645a80
inline int ZLibFileImpl::Inflate(void* buffer, int bytes)
{
    int total = 0;

    if (UserPos < InflatedPos)
    {
        int back    = InflatedPos - UserPos;
        int toCopy  = (back > bytes) ? bytes : back;
        int fromBuf = toCopy;

        if (back > BacktrackTail)
        {
            // The older part sits at the end of the buffer.
            int start = BacktrackSize - (back - BacktrackTail);
            int n     = BacktrackSize - start;
            if (n > toCopy)
                n = toCopy;
            memcpy(buffer, Backtrack + start, n);
            toCopy -= n;
            back -= n;
            buffer = (UByte*)buffer + n;
        }
        if (toCopy > 0)
        {
            memcpy(buffer, Backtrack + (BacktrackTail - back), toCopy);
            buffer = (UByte*)buffer + toCopy;
        }
        bytes -= fromBuf;
        total += fromBuf;
        UserPos += fromBuf;
    }

    if (bytes > 0)
    {
        int inflated = InflateStream(buffer, bytes);

        // Keep the newest bytes for backward seeks.
        if (inflated >= BuffSize)
        {
            BacktrackTail = BuffSize;
            BacktrackSize = BuffSize;
            memcpy(Backtrack, (UByte*)buffer + (inflated - BuffSize), BuffSize);
        }
        else if (inflated > 0)
        {
            UByte* psrc = (UByte*)buffer;
            int    room = BuffSize - BacktrackTail;
            int    n    = (room < inflated) ? room : inflated;
            if (n > 0)
            {
                memcpy(Backtrack + BacktrackTail, psrc, n);
                psrc += n;
                BacktrackTail += n;
            }
            if (inflated > n)
            {
                BacktrackTail = inflated - n;
                memcpy(Backtrack, psrc, BacktrackTail);
            }
            if (BacktrackSize < BuffSize)
            {
                BacktrackSize += inflated;
                if (BacktrackSize > BuffSize)
                    BacktrackSize = BuffSize;
            }
        }
        UserPos = InflatedPos;
        total += inflated;
    }
    return total;
}

// Moves UserPos to pos: inside the backtrack buffer directly, before it by restarting the stream, after it by
// inflating up to pos.
// @0x142645d90
int ZLibFileImpl::SetPosition(int pos)
{
    if (pos < InflatedPos)
    {
        if (pos >= InflatedPos - BacktrackSize)
        {
            UserPos = pos;
            return UserPos;
        }
        Restart();
    }
    else if (pos > InflatedPos)
    {
        UserPos = InflatedPos;
    }

    UByte temp[BuffSize];
    while (UserPos < pos)
    {
        int toRead = pos - UserPos;
        if (Inflate(temp, Alg::Min<int>(toRead, BuffSize)) == 0)
            break;
    }
    return UserPos;
}

// @0x142645610
ZLibFile::ZLibFile(File* psourceFile)
{
    pImpl = 0;
    if (psourceFile && psourceFile->IsValid())
        pImpl = SF_HEAP_AUTO_NEW(this) ZLibFileImpl(psourceFile);
}

// @0x142645740
ZLibFile::~ZLibFile()
{
    if (pImpl)
    {
        pImpl->ReturnInput();
        inflateEnd(&pImpl->ZStream);
        delete pImpl;
    }
}

// @0x1426458b0
int ZLibFile::BytesAvailable()
{
    if (!pImpl || pImpl->ErrorCode)
        return 0;
    int pos = pImpl->UserPos;
    int end = Seek(0, Seek_End);
    Seek(pos, Seek_Set);
    return end - pos;
}

// @0x142645920
bool ZLibFile::Close()
{
    if (!pImpl)
        return false;
    pImpl->ReturnInput();
    int err = inflateEnd(&pImpl->ZStream);
    pImpl->pIn->Close();
    delete pImpl;
    pImpl = 0;
    return err == ZLib_OK;
}

// @0x142645a20
int ZLibFile::GetLength()
{
    if (!pImpl || pImpl->ErrorCode)
        return 0;
    int pos = pImpl->UserPos;
    int end = Seek(0, Seek_End);
    Seek(pos, Seek_Set);
    return end;
}

// @0x142645c90
SInt64 ZLibFile::LGetLength()
{
    return GetLength();
}

// @0x142645cb0
SInt64 ZLibFile::LSeek(SInt64 offset, int origin)
{
    return Seek((int)offset, origin);
}

// @0x142645d10
// MS2-FUNCTIONAL: same code, the Seek_Cur case branches to the pImpl reload of Seek_End instead of past it
int ZLibFile::Seek(int offset, int origin)
{
    if (!pImpl)
        return -1;
    if (pImpl->ErrorCode)
        return pImpl->UserPos;

    switch (origin)
    {
    case Seek_End:
        pImpl->SetPosition(0x7fffffff);
        if (!offset)
            break;
        // relative to the end: fall through
    case Seek_Cur:
        offset += pImpl->UserPos;
        // fall through
    case Seek_Set:
        pImpl->SetPosition(offset);
        break;
    }
    return pImpl->UserPos;
}

// @0x142646120
int SF_STDCALL ZLibFile::ZLib_InitStream(z_stream_s* pstream, void* pheapAddr, void* pbuffer, unsigned bufSize)
{
    pstream->zalloc    = ZLib_Alloc;
    pstream->zfree     = ZLib_Free;
    pstream->opaque    = pheapAddr;
    pstream->next_in   = 0;
    pstream->avail_in  = 0;
    pstream->next_out  = (unsigned char*)pbuffer;
    pstream->avail_out = bufSize;
    pstream->data_type = 0;
    pstream->adler     = 0;
    pstream->reserved  = 0;
    return inflateInit_(pstream, "1.2.5", sizeof(z_stream_s));
}

// ---- (sfr24) virtuals the full exe links by name (work/sfr35/outside-units.tsv) ----

// A plain character definition draws nothing.
// @0x142645600
void CharacterDef::Display(DisplayContext&, DisplayObjectBase*)
{
}

// The inflated stream cannot be resized, written or flushed to.
// @0x142645910
bool ZLibFile::ChangeSize(int)
{
    return false;
}

// @0x1426459d0
int ZLibFile::CopyFromStream(File*, int)
{
    return 0;
}

// @0x1426459e0
bool ZLibFile::Flush()
{
    return true;
}

// @0x1426459f0
int ZLibFile::GetErrorCode()
{
    return pImpl ? pImpl->ErrorCode : 0;
}

// The path of the compressed source.
// @0x142645a00
const char* ZLibFile::GetFilePath()
{
    return pImpl ? pImpl->pIn->GetFilePath() : 0;
}

// @0x142645c70
bool ZLibFile::IsValid()
{
    return pImpl != 0;
}

// @0x142645c80
bool ZLibFile::IsWritable()
{
    return false;
}

// @0x142645cf0
int ZLibFile::Read(UByte* pbuffer, int numBytes)
{
    if (!pImpl)
        return -1;
    return pImpl->Inflate(pbuffer, numBytes);
}

// @0x1426460b0
int ZLibFile::SkipBytes(int numBytes)
{
    return Seek(numBytes, Seek_Cur);
}

// @0x1426460c0
int ZLibFile::Tell()
{
    if (!pImpl)
        return -1;
    return pImpl->UserPos;
}

// @0x1426460e0
int ZLibFile::Write(const UByte*, int)
{
    return 0;
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7ZLibFile@GFx@Scaleform@@6B@ 0x14318fec0
