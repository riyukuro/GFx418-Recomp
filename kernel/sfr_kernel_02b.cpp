// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_String_PathUtil (URL / file
// path splitting on String). Our own source, written from the exe (the leaked SDK copies were only used to name things
// and to compare layouts). Queue unit sfr_kernel_02 is split along its original sources (sfr_kernel_02 / 02b ...).
// MS2-UNIT: sfr_kernel_02b
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a4d00-0x1425a5270 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"

namespace Scaleform {

// Finds the file name (after the last '/' or '\\') and the extension (the last '.' of the file name, 0 if none).
void ScanFilePath(const char* url, const char** pfilename, const char** pext)
{
    const char* name = url;
    const char* dot = 0;
    for (UInt32 c = UTF8Util::DecodeNextChar(&url); c != 0; c = UTF8Util::DecodeNextChar(&url))
    {
        if (c == '/' || c == '\\')
        {
            name = url;
            dot = 0;
        }
        else if (c == '.')
            dot = url - 1;
    }
    if (pfilename)
        *pfilename = name;
    if (pext)
        *pext = dot;
}

// Returns the text after the first "://", or 0.
const char* ScanPathProtocol(const char* url)
{
    UInt32 c = UTF8Util::DecodeNextChar(&url);
    while (c != 0)
    {
        if (c == ':')
        {
            UInt32 c1 = UTF8Util::DecodeNextChar(&url);
            c = UTF8Util::DecodeNextChar(&url);
            if (c == '/' && c1 == '/')
                return url;
        }
        c = UTF8Util::DecodeNextChar(&url);
    }
    return 0;
}

// Empty paths count as absolute, as do a leading slash and a slash right after the first ':' ("c:/", "http://").
bool String::HasAbsolutePath(const char* url)
{
    if (!url || !*url)
        return true;
    UInt32 c = UTF8Util::DecodeNextChar(&url);
    if (c == '/' || c == '\\')
        return true;
    while (c != 0)
    {
        if (c == ':')
        {
            c = UTF8Util::DecodeNextChar(&url);
            if (c == '/' || c == '\\')
                return true;
        }
        else if (c == '/' || c == '\\')
            break;
        c = UTF8Util::DecodeNextChar(&url);
    }
    return false;
}

bool String::HasExtension(const char* path)
{
    const char* ext = 0;
    ScanFilePath(path, 0, &ext);
    return ext != 0;
}

bool String::HasProtocol(const char* path)
{
    return ScanPathProtocol(path) != 0;
}

String String::GetPath() const
{
    const char* name = 0;
    ScanFilePath(ToCStr(), &name, 0);
    return String(ToCStr(), name ? (UPInt)(name - ToCStr()) : GetSize());
}

String String::GetProtocol() const
{
    const char* end = ScanPathProtocol(ToCStr());
    return String(ToCStr(), end ? end - ToCStr() : 0);
}

String String::GetFilename() const
{
    const char* name = 0;
    ScanFilePath(ToCStr(), &name, 0);
    return String(name);
}

String String::GetExtension() const
{
    const char* ext = 0;
    ScanFilePath(ToCStr(), 0, &ext);
    return String(ext);
}

// As in the exe: the string is replaced by its extension (from the dot on), not cut before it.
void String::StripExtension()
{
    const char* ext = 0;
    ScanFilePath(ToCStr(), 0, &ext);
    if (ext)
        AssignString(ext, SFstrlen(ext));
}

void String::StripProtocol()
{
    const char* rest = ScanPathProtocol(ToCStr());
    if (rest)
        AssignString(rest, SFstrlen(rest));
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ?GetExtension@String@Scaleform@@QEBA?AV12@XZ 0x1425a4d00
// MS2-PIN: ?GetFilename@String@Scaleform@@QEBA?AV12@XZ 0x1425a4d90
// MS2-PIN: ?GetPath@String@Scaleform@@QEBA?AV12@XZ 0x1425a4e10
// MS2-PIN: ?GetProtocol@String@Scaleform@@QEBA?AV12@XZ 0x1425a4ed0
// MS2-PIN: ?HasAbsolutePath@String@Scaleform@@SA_NPEBD@Z 0x1425a4f20
// MS2-PIN: ?HasExtension@String@Scaleform@@SA_NPEBD@Z 0x1425a4fb0
// MS2-PIN: ?HasProtocol@String@Scaleform@@SA_NPEBD@Z 0x1425a5020
// MS2-PIN: ?ScanFilePath@Scaleform@@YAXPEBDPEAPEBD1@Z 0x1425a5040
// MS2-PIN: ?ScanPathProtocol@Scaleform@@YAPEBDPEBD@Z 0x1425a50f0
// MS2-PIN: ?StripExtension@String@Scaleform@@QEAAXXZ 0x1425a5180
// MS2-PIN: ?StripProtocol@String@Scaleform@@QEAAXXZ 0x1425a5220
