// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_FileOpener (the default file
// opener state: plain system files).
// Second source of queue unit sfr_gfx_01 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_01b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14258d0c0-0x14258d2a0 .text$mn

#include "../include/gfx/gfx_loaderimpl.h"

namespace Scaleform { namespace GFx {

// The modification time of purl, -1 if it cannot be read.
// @0x14258d0c0
SInt64 FileOpener::GetFileModifyTime(const char* purl)
{
    FileStat fileStat;
    if (SysFile::GetFileStat(&fileStat, purl))
        return fileStat.ModifyTime;
    return -1;
}

// @0x14258d150
File* FileOpener::OpenFile(const char* purl, int flags, int modes)
{
    return new SysFile(purl, flags, modes);
}

// Opens purl and checks it; logs and returns 0 when it cannot be opened.
// @0x14258d210
File* FileOpener::OpenFileEx(const char* pfilename, Log* plog, int flags, int modes)
{
    File* pin     = OpenFile(pfilename, flags, modes);
    int   errCode = 0;
    if (pin)
        errCode = pin->GetErrorCode();

    if (!pin || errCode)
    {
        if (plog)
            plog->LogError("Loader failed to open '%s'", pfilename);
        if (pin)
            pin->Release();
        return 0;
    }
    return pin;
}

}} // namespace Scaleform::GFx

// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
