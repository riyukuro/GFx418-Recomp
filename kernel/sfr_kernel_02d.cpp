// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_SysFile (SysFile over the
// stdio files, the unopened placeholder). Our own source, written from the exe (the leaked SDK copies were only used to
// name things and to compare layouts). Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a5f60-0x1425a66b0 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_file.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_memory.h"

namespace Scaleform {

// ==== SF_SysFile =====================================================================================================

// Stands in for a file that failed to open: every operation fails.
class UnopenedFile : public File
{
public:
    UnopenedFile() { }
    ~UnopenedFile() { }

    virtual const char* GetFilePath()                     { return 0; }
    virtual bool        IsValid()                         { return 0; }
    virtual bool        IsWritable()                      { return 0; }
    virtual int         Tell()                            { return 0; }
    virtual SInt64      LTell()                           { return 0; }
    virtual int         GetLength()                       { return 0; }
    virtual SInt64      LGetLength()                      { return 0; }
    virtual int         GetErrorCode()                    { return Error_FileNotFound; }
    virtual int         Write(const UByte*, int)          { return -1; }
    virtual int         Read(UByte*, int)                 { return -1; }
    virtual int         SkipBytes(int)                    { return 0; }
    virtual int         BytesAvailable()                  { return 0; }
    virtual bool        Flush()                           { return 0; }
    virtual int         Seek(int, int)                    { return -1; }
    virtual SInt64      LSeek(SInt64, int)                { return -1; }
    virtual bool        ChangeSize(int)                   { return 0; }
    virtual int         CopyFromStream(File*, int)        { return -1; }
    virtual bool        Close()                           { return 0; }
    virtual bool        CloseCancel()                     { return 0; }
};

SysFile::SysFile() : DelegatedFile(0)
{
    pFile = *new UnopenedFile;
}

SysFile::SysFile(const String& path, int flags, int mode) : DelegatedFile(0)
{
    Open(path, flags, mode);
}

bool SysFile::Open(const String& path, int flags, int mode)
{
    pFile = *FileFILEOpen(path, flags, mode);
    if (!pFile || !pFile->IsValid())
    {
        pFile = *SF_NEW UnopenedFile;
        return 0;
    }
    if (flags & Open_Buffered)
        pFile = *SF_NEW BufferedFile(pFile);
    return 1;
}

int SysFile::GetErrorCode()
{
    return pFile ? pFile->GetErrorCode() : Error_FileNotFound;
}

bool SysFile::IsValid()
{
    return pFile && pFile->IsValid();
}

bool SysFile::Close()
{
    if (IsValid())
    {
        DelegatedFile::Close();
        pFile = *SF_NEW UnopenedFile;
        return 1;
    }
    return 0;
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0SysFile@Scaleform@@QEAA@AEBVString@1@HH@Z 0x1425a5f60
// MS2-PIN: ??0SysFile@Scaleform@@QEAA@XZ 0x1425a6090
// MS2-PIN: ??_GDelegatedFile@Scaleform@@UEAAPEAXI@Z 0x1425a6120
// MS2-PIN: ??_GSysFile@Scaleform@@UEAAPEAXI@Z 0x1425a6190
// MS2-PIN: ??_GUnopenedFile@Scaleform@@UEAAPEAXI@Z 0x1425a6200
// MS2-PIN: ?Close@SysFile@Scaleform@@UEAA_NXZ 0x1425a62c0
// MS2-PIN: ?IsValid@DelegatedFile@Scaleform@@UEAA_NXZ 0x1425a6420
// MS2-PIN: ?IsValid@SysFile@Scaleform@@UEAA_NXZ 0x1425a6450
// MS2-PIN: ?Open@SysFile@Scaleform@@QEAA_NAEBVString@2@HH@Z 0x1425a6510
// MS2-PIN: ??_7SysFile@Scaleform@@6B@ 0x143188c48
// MS2-PIN: ??_7UnopenedFile@Scaleform@@6B@ 0x143188ce8
// MS2-PIN: ??_7DelegatedFile@Scaleform@@6B@ 0x143188ba8
