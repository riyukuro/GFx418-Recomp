// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_FileFILE (stdio backed
// files). Our own source, written from the exe (the leaked SDK copies
// were only used to name things and to compare layouts). Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a5270-0x1425a5f60 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_file.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <windows.h>

namespace Scaleform {

// ==== SF_FileFILE ====================================================================================================

static int SFerror()
{
    if (errno == ENOENT)
        return File::Error_FileNotFound;
    if (errno == EACCES || errno == EPERM)
        return File::Error_Access;
    if (errno == ENOSPC)
        return File::Error_DiskFull;
    return File::Error_IOError;
}

// No "insert a disk" message boxes while a drive letter path is opened.
class SysErrorModeDisabler
{
    BOOL Disabled;
    UINT OldMode;
public:
    SysErrorModeDisabler(const char* fileName)
    {
        if (fileName && fileName[0] != 0 && fileName[1] == ':')
        {
            Disabled = 1;
            OldMode = ::SetErrorMode(SEM_FAILCRITICALERRORS);
        }
        else
            Disabled = 0;
    }
    ~SysErrorModeDisabler()
    {
        if (Disabled)
            ::SetErrorMode(OldMode);
    }
};

enum { FILE_CloseFd = 0x1000 };

// 0x38 bytes: FileName +0x10, Opened +0x18, fs +0x20, OpenFlags +0x28, ErrorCode +0x2c, LastOp +0x30
class FILEFile : public File
{
protected:
    String FileName;
    bool   Opened;
    FILE*  fs;
    int    OpenFlags;
    int    ErrorCode;
    int    LastOp;
public:
    FILEFile(const String& fileName, int flags, int mode);
    FILEFile(const char* fileName, int flags, int mode);
    FILEFile(FILE* file, const char* fileName, int closeFd);
    ~FILEFile()
    {
        if (Opened)
            Close();
    }

    virtual const char* GetFilePath();
    virtual bool        IsValid();
    virtual bool        IsWritable();
    virtual int         Tell();
    virtual SInt64      LTell();
    virtual int         GetLength();
    virtual SInt64      LGetLength();
    virtual int         GetErrorCode();
    virtual int         Write(const UByte* buffer, int numBytes);
    virtual int         Read(UByte* buffer, int numBytes);
    virtual int         SkipBytes(int numBytes);
    virtual int         BytesAvailable();
    virtual bool        Flush();
    virtual int         Seek(int offset, int origin);
    virtual SInt64      LSeek(SInt64 offset, int origin);
    virtual bool        ChangeSize(int newSize);
    virtual int         CopyFromStream(File* stream, int byteSize);
    virtual bool        Close();
private:
    void init();
};

FILEFile::FILEFile(const String& fileName, int flags, int mode)
    : FileName(fileName), OpenFlags(flags)
{
    SF_UNUSED(mode);
    init();
}

FILEFile::FILEFile(const char* fileName, int flags, int mode)
    : FileName(fileName), OpenFlags(flags)
{
    SF_UNUSED(mode);
    init();
}

FILEFile::FILEFile(FILE* file, const char* fileName, int closeFd)
{
    FileName = fileName;
    Opened = 1;
    OpenFlags = Open_Read | Open_Write;
    if (closeFd)
        OpenFlags |= FILE_CloseFd;
    ErrorCode = 0;
    LastOp = 0;
    fs = file;
}

// fopen mode from the flags; the UTF-8 name is widened for _wfopen_s
void FILEFile::init()
{
    const char* mode = "rb";
    if (OpenFlags & Open_Truncate)
        mode = !(OpenFlags & Open_Read) ? "wb" : "w+b";
    else if (OpenFlags & Open_Create)
        mode = !(OpenFlags & Open_Read) ? "ab" : "a+b";
    else if (OpenFlags & Open_Write)
        mode = "r+b";

    SysErrorModeDisabler disabler(FileName.ToCStr());

    wchar_t  wideMode[16];
    wchar_t* wideName = (wchar_t*)SF_ALLOC((UTF8Util::GetLength(FileName.ToCStr()) + 1) * sizeof(wchar_t),
                                           Stat_Default_Mem);
    UTF8Util::DecodeString(wideName, FileName.ToCStr());
    UTF8Util::DecodeString(wideMode, mode);
    _wfopen_s(&fs, wideName, wideMode);
    SF_FREE(wideName);
    if (fs)
        rewind(fs);
    Opened = (fs != NULL);
    ErrorCode = !Opened ? SFerror() : 0;
    LastOp = 0;
}

const char* FILEFile::GetFilePath() { return FileName.ToCStr(); }
bool        FILEFile::IsValid()     { return Opened; }
bool        FILEFile::IsWritable()  { return IsValid() && (OpenFlags & Open_Write); }

int FILEFile::Tell()
{
    int pos = ftell(fs);
    if (pos < 0)
        ErrorCode = SFerror();
    return pos;
}

SInt64 FILEFile::LTell()
{
    int pos = ftell(fs);
    if (pos < 0)
        ErrorCode = SFerror();
    return pos;
}

int FILEFile::GetLength()
{
    int pos = Tell();
    if (pos >= 0)
    {
        Seek(0, Seek_End);
        int size = Tell();
        Seek(pos, Seek_Set);
        return size;
    }
    return -1;
}

SInt64 FILEFile::LGetLength() { return GetLength(); }
int    FILEFile::GetErrorCode() { return ErrorCode; }

// switching between reading and writing needs a flush in between
int FILEFile::Write(const UByte* buffer, int numBytes)
{
    if (LastOp && LastOp != Open_Write)
        fflush(fs);
    LastOp = Open_Write;
    int written = (int)fwrite(buffer, 1, numBytes, fs);
    if (written < numBytes)
        ErrorCode = SFerror();
    return written;
}

int FILEFile::Read(UByte* buffer, int numBytes)
{
    if (LastOp && LastOp != Open_Read)
        fflush(fs);
    LastOp = Open_Read;
    int read = (int)fread(buffer, 1, numBytes, fs);
    if (read < numBytes)
        ErrorCode = SFerror();
    return read;
}

int FILEFile::SkipBytes(int numBytes)
{
    SInt64 pos = LTell();
    SInt64 newPos = LSeek(numBytes, Seek_Cur);
    if (pos == -1 || newPos == -1)
        return -1;
    return int(newPos - (int)pos);
}

int FILEFile::BytesAvailable()
{
    SInt64 pos = LTell();
    SInt64 end = LGetLength();
    if (pos == -1 || end == -1)
    {
        ErrorCode = SFerror();
        return 0;
    }
    ErrorCode = 0;
    return int(end - (int)pos);
}

bool FILEFile::Flush() { return !fflush(fs); }

int FILEFile::Seek(int offset, int origin)
{
    int whence = 0;
    switch (origin)
    {
    case Seek_Set: whence = SEEK_SET; break;
    case Seek_Cur: whence = SEEK_CUR; break;
    case Seek_End: whence = SEEK_END; break;
    }
    if (whence == SEEK_SET && offset == Tell())
        return Tell();
    if (fseek(fs, offset, whence))
        return -1;
    return (int)Tell();
}

SInt64 FILEFile::LSeek(SInt64 offset, int origin) { return Seek((int)offset, origin); }

bool FILEFile::ChangeSize(int newSize)
{
    SF_UNUSED(newSize);
    ErrorCode = Error_IOError;
    return 0;
}

int FILEFile::CopyFromStream(File* stream, int byteSize)
{
    UByte buff[0x4000];
    int   count = 0;
    while (byteSize)
    {
        int request = (byteSize > int(sizeof(buff))) ? int(sizeof(buff)) : byteSize;
        int read = stream->Read(buff, request);
        int written = 0;
        if (read > 0)
            written = Write(buff, read);
        count += written;
        byteSize -= written;
        if (written < request)
            break;
    }
    return count;
}

bool FILEFile::Close()
{
    if (fclose(fs))
    {
        ErrorCode = SFerror();
        return 0;
    }
    Opened = 0;
    fs = 0;
    ErrorCode = 0;
    return 1;
}

File* FileFILEOpen(const String& path, int flags, int mode)
{
    return SF_NEW FILEFile(path, flags, mode);
}

File* FileFILEOpen(FILE* file, const char* path, int closeFd)
{
    return SF_NEW FILEFile(file, path, closeFd);
}

bool SysFile::GetFileStat(FileStat* fileStat, const String& path)
{
    struct __stat64 st;
    wchar_t* widePath = (wchar_t*)SF_ALLOC((UTF8Util::GetLength(path.ToCStr()) + 1) * sizeof(wchar_t), Stat_Default_Mem);
    UTF8Util::DecodeString(widePath, path.ToCStr());
    int ret = _wstat64(widePath, &st);
    SF_FREE(widePath);
    if (ret)
        return false;
    fileStat->AccessTime = st.st_atime;
    fileStat->ModifyTime = st.st_mtime;
    fileStat->FileSize = st.st_size;
    return true;
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0FILEFile@Scaleform@@QEAA@AEBVString@1@HH@Z 0x1425a5270
// MS2-PIN: ??0FILEFile@Scaleform@@QEAA@PEAU_iobuf@@PEBDH@Z 0x1425a52c0
// MS2-PIN: ??0FILEFile@Scaleform@@QEAA@PEBDHH@Z 0x1425a5360
// MS2-PIN: ??_GFILEFile@Scaleform@@UEAAPEAXI@Z 0x1425a53b0
// MS2-PIN: ?BytesAvailable@FILEFile@Scaleform@@UEAAHXZ 0x1425a54a0
// MS2-PIN: ?Close@FILEFile@Scaleform@@UEAA_NXZ 0x1425a5560
// MS2-PIN: ?CopyFromStream@FILEFile@Scaleform@@UEAAHPEAVFile@2@H@Z 0x1425a55f0
// MS2-PIN: ?FileFILEOpen@Scaleform@@YAPEAVFile@1@AEBVString@1@HH@Z 0x1425a56c0
// MS2-PIN: ?FileFILEOpen@Scaleform@@YAPEAVFile@1@PEAU_iobuf@@PEBDH@Z 0x1425a5750
// MS2-PIN: ?Flush@FILEFile@Scaleform@@UEAA_NXZ 0x1425a5800
// MS2-PIN: ?GetFileStat@SysFile@Scaleform@@SA_NPEAUFileStat@2@AEBVString@2@@Z 0x1425a5840
// MS2-PIN: ?GetLength@FILEFile@Scaleform@@UEAAHXZ 0x1425a5920
// MS2-PIN: ?IsWritable@FILEFile@Scaleform@@UEAA_NXZ 0x1425a59a0
// MS2-PIN: ?LGetLength@FILEFile@Scaleform@@UEAA_JXZ 0x1425a59d0
// MS2-PIN: ?LSeek@FILEFile@Scaleform@@UEAA_J_JH@Z 0x1425a59f0
// MS2-PIN: ?LTell@FILEFile@Scaleform@@UEAA_JXZ 0x1425a5a10
// MS2-PIN: ?Read@FILEFile@Scaleform@@UEAAHPEAEH@Z 0x1425a5aa0
// MS2-PIN: ?Seek@FILEFile@Scaleform@@UEAAHHH@Z 0x1425a5b50
// MS2-PIN: ?SkipBytes@FILEFile@Scaleform@@UEAAHH@Z 0x1425a5bd0
// MS2-PIN: ?Tell@FILEFile@Scaleform@@UEAAHXZ 0x1425a5c40
// MS2-PIN: ?Write@FILEFile@Scaleform@@UEAAHPEBEH@Z 0x1425a5cd0
// MS2-PIN: ?init@FILEFile@Scaleform@@AEAAXXZ 0x1425a5d80
// MS2-PIN: ??_7FILEFile@Scaleform@@6B@ 0x143188af8
