// Recovered Scaleform GFx 4.1.18 pieces that no unit owned (own source, written from the exe; SDK material is reference
// only): the Expat based XML parser's ParseFile / ParseString, and the Sound module's sample data objects (SoundData,
// SoundFile, AppendableSoundData and its chunk list, SoundInfo).
// MS2-UNIT: sfr_gfx_12
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423b1920-0x1423b1d3d .text$mn
// MS2-RANGE: 0x142747bc0-0x142747d98 .text$mn
// MS2-RANGE: 0x142747da0-0x142748150 .text$mn
// MS2-RANGE: 0x142748230-0x1427485e6 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/gfx/xml/xml_support.h"
#include "../include/gfx/xml/xml_parser.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/sound/sound_renderer.h"
#include "../include/sound/sound_sound.h"
#include "../include/kernel/sf_memory.h"
#include "../include/kernel/sf_file.h"
#include "hook/ms2hook.h"
#include <string.h>

// the exe calls the CRT strcpy_s import thunk (0x14280f246) directly rather than through the import table, so the
// thunk goes by its own name
extern "C" errno_t __cdecl sfr_strcpy_s_thunk(char* dest, rsize_t size, const char* src);
// the full exe resolves the thunk name to the CRT strcpy_s (the real dllimport decl would call [__imp_] and lose 0x142747cf0)
#ifndef MS2_HOOK_DLL
#pragma comment(linker, "/alternatename:sfr_strcpy_s_thunk=strcpy_s")
#endif

// The exe functions and globals this unit uses but does not define, declared by their FUN_<va> / DAT_<va> names: the
// hook DLL binds them to the exe, the full exe to the recovered definition at that VA (tools/fullexe/alias.py).
template <class T> using ExeDecl = T;

using namespace Scaleform;

// ---- the Expat parser ----

namespace Scaleform { namespace GFx { namespace XML {

// The Expat based parser behind GFx's XML support (RefCountBaseNTS<Parser>, 0x10 bytes; its constructor and
// destructor are the game's, instantiated where the player is created).
class ParserExpat : public Parser
{
public:
    virtual ~ParserExpat() {}
    virtual bool ParseFile(const char* pfilename, FileOpenerBase* pfo, ParserHandler* pphandler);
    virtual bool ParseString(const char* pdata, UPInt len, ParserHandler* pphandler);
};

}}} // namespace Scaleform::GFx::XML

// The Expat library linked into the exe (libgfxexpat, built static).
#define XML_STATIC
#include "../third_party/src/expat-2.0.1/lib/expat.h"
// The parser's callbacks (sfr_gfx_12x; the handler / user data protocol is private to the exe's ParserExpat).
void FUN_1423b1d40(void* userData, const char* name, const char** atts);                         // start element
void FUN_1423b17d0(void* userData, const char* name);                                            // end element
void FUN_1423b1660(void* userData, const char* s, int len);                                      // character data
void FUN_1423b16d0(void* userData, const char* data);                                            // comment
void FUN_1423b23e0(void* userData, const char* version, const char* encoding, int standalone);  // XML declaration
void FUN_1423b1760(void* userData, const char* s, int len);                                      // default
// Formats one message into a small caller supplied buffer descriptor (mode 2, buffer, capacity).
struct Unk_XmlMsgBuffer { int Mode; char* Buffer; UPInt Capacity; };
ExeDecl<UPInt(Unk_XmlMsgBuffer*, const char*, const char**)> FUN_1423b14e0;
static const char Unk_FileIsEmptyFormat[] = "File {0} is empty!";        // exe 0x143135720
static const char Unk_FileMissingFormat[] = "File {0} does not exist!";  // exe 0x143135738

namespace Scaleform { namespace GFx { namespace XML {

// Opens the file, reads it whole into a temporary buffer and parses it; reports a missing or empty file
// to the handler's warning / fatal error callbacks.
// @0x1423b1920
bool ParserExpat::ParseFile(const char* pfilename, FileOpenerBase* pfo, ParserHandler* pphandler)
{
    ParserLocator locator;
    char          message[0x100];
    bool          result = false;
    Ptr<File>     pfile  = *pfo->OpenFile(pfilename, 0x21, 0x1b6);
    if (pfile && pfile->IsValid())
    {
        int length = pfile->GetLength();
        if (length != 0)
        {
            char* pbuffer = (char*)Memory::pGlobalHeap->Alloc(length, (const AllocInfo*)0);
            pfile->Read((UByte*)pbuffer, length);
            result = ParseString(pbuffer, length, pphandler);
            Memory::pGlobalHeap->Free(pbuffer);
        }
        else
        {
            pphandler->SetDocumentLocator(&locator);
            Unk_XmlMsgBuffer buffer = {2, message, 0x100};
            FUN_1423b14e0(&buffer, Unk_FileIsEmptyFormat, &pfilename);
            ParserException exception(message, message ? strlen(message) : 0);
            pphandler->Warning(exception);
        }
    }
    else
    {
        pphandler->SetDocumentLocator(&locator);
        Unk_XmlMsgBuffer buffer = {2, message, 0x100};
        FUN_1423b14e0(&buffer, Unk_FileMissingFormat, &pfilename);
        ParserException exception(message, message ? strlen(message) : 0);
        pphandler->FatalError(exception);
    }
    return result;
}

// The callbacks' user data: the parser, the handler and the locator the position is reported through.
struct ExpatUserData
{
    XML_Parser     Parser;
    ParserHandler* Handler;
    ParserLocator* Locator;
};

// Copies the parser's current position into the locator.
static inline void UpdateLocator(ExpatUserData* data)
{
    XML_Parser     parser  = data->Parser;
    ParserLocator* locator = data->Locator;
    locator->Column      = XML_GetCurrentColumnNumber(parser) + 1;
    locator->Line        = XML_GetCurrentLineNumber(parser);
    locator->LoadedBytes = (SPInt)XML_GetCurrentByteIndex(parser);
}

// Parses an in-memory document with Expat and feeds the handler; a parse error is reported with the
// position and Expat's error string.
// @0x1423b1b60
bool ParserExpat::ParseString(const char* pdata, UPInt len, ParserHandler* pphandler)
{
    ParserLocator locator;
    locator.TotalBytesToLoad = len;
    locator.LoadedBytes      = 0;
    pphandler->SetDocumentLocator(&locator);
    XML_Parser parser = XML_ParserCreate(0);
    XML_SetStartElementHandler(parser, &FUN_1423b1d40);
    XML_SetEndElementHandler(parser, &FUN_1423b17d0);
    XML_SetCharacterDataHandler(parser, &FUN_1423b1660);
    XML_SetCommentHandler(parser, &FUN_1423b16d0);
    XML_SetXmlDeclHandler(parser, &FUN_1423b23e0);
    XML_SetDefaultHandler(parser, &FUN_1423b1760);
    ExpatUserData userData = {parser, pphandler, &locator};
    XML_SetUserData(parser, &userData);
    pphandler->StartDocument();
    bool result;
    if (XML_Parse(parser, pdata, (int)len, 1) != 1)
    {
        UpdateLocator(&userData);
        const char*     text = XML_ErrorString(XML_GetErrorCode(parser));
        ParserException exception(text, text ? strlen(text) : 0);
        pphandler->FatalError(exception);
        result = false;
    }
    else
    {
        UpdateLocator(&userData);
        pphandler->EndDocument();
        result = true;
    }
    XML_ParserFree(parser);
    return result;
}

}}} // namespace Scaleform::GFx::XML

// ---- the Sound module ----

// The global statistics object the exe reports sample bytes to (slot 45 on alloc, slot 46 on free; sfr_gfx_07h).
namespace Scaleform { namespace GFx { void* FUN_14261e310(); }}

namespace Scaleform { namespace Sound {

struct AppendableSoundData::DataChunk
{
    DataChunk* pNext;      // +0x00
    UByte*     pData;      // +0x08 the 0x4000 (or larger) sample block
    unsigned   Used;       // +0x10 bytes filled
    unsigned   Reserved14;
    unsigned   Samples;    // +0x18 samples held
    unsigned   Reserved1c;

    explicit DataChunk(unsigned size);
    ~DataChunk();
};

// MS2-FUNCTIONAL: the chunk's sample block comes zero filled from the global heap, aligned to 0x20.
// @0x142747c20
AppendableSoundData::DataChunk::DataChunk(unsigned size) : pNext(0), Used(0), Reserved14(0), Samples(0)
{
    pData = (UByte*)Memory::pGlobalHeap->Alloc(size, 0x20, (const AllocInfo*)0);
    memset(pData, 0, size);
}

// MS2-FUNCTIONAL: a streamed sample list: the data description with the stream flag and an empty chunk list.
// @0x142747bc0
AppendableSoundData::AppendableSoundData(unsigned format, unsigned rate)
    : SoundDataBase(format, rate, 0), pFirstChunk(0), pFillChunk(0), pReadChunk(0), DataSize(0), ReadPos(0), ChunkLock()
{
    Format |= Sample_Stream;
}

// Appends room for length samples (dsize bytes) to the chunk list and returns the write position; the chunk lock
// stays held until UnlockData.
// The chunks come from the global heap's Alloc (DataChunk has no heap operator new: SF_HEAP_NEW on it was the
// placement new at the heap object itself).
// @0x142748230
UByte* AppendableSoundData::LockDataForAppend(unsigned length, unsigned dsize)
{
    ChunkLock.DoLock();
    if (!pFirstChunk)
    {
        void* pmem = Memory::pGlobalHeap->Alloc(sizeof(DataChunk));
        pFirstChunk = pmem ? new (pmem) DataChunk(0x4000) : 0;
        pFillChunk  = pFirstChunk;
        pReadChunk  = pFillChunk;
    }
    UByte* pbuffer = 0;
    if (dsize > 0x4000u - pFillChunk->Used)
    {
        void* pmem = Memory::pGlobalHeap->Alloc(sizeof(DataChunk));
        pFillChunk->pNext = pmem ? new (pmem) DataChunk(0x4000) : 0;
        pFillChunk->pNext->Reserved14 = pFillChunk->Samples + pFillChunk->Reserved14;
        pFillChunk = pFillChunk->pNext;
    }
    pbuffer = pFillChunk->pData + pFillChunk->Used;
    pFillChunk->Used += dsize;
    pFillChunk->Samples += length;
    DataSize += dsize;
    Length += length;
    return pbuffer;
}

// MS2-FUNCTIONAL: frees the chunk's sample block (the exe's out of line chunk destructor).
// @0x142747e20
AppendableSoundData::DataChunk::~DataChunk()
{
    Memory::pGlobalHeap->Free(pData);
}

// MS2-FUNCTIONAL: frees the chunk list (sample block, then the chunk) and the chunk lock.
// @0x142747da0
AppendableSoundData::~AppendableSoundData()
{
    DataChunk* pchunk = pFirstChunk;
    while (pchunk)
    {
        DataChunk* pnext = pchunk->pNext;
        pchunk->~DataChunk();
        Memory::pGlobalHeap->Free(pchunk);
        pFirstChunk = pnext;
        pchunk      = pnext;
    }
}

// MS2-FUNCTIONAL: reports the freed byte count to the global statistics object and frees the sample block.
// @0x142747e40
SoundData::~SoundData()
{
    void* pstat = Scaleform::GFx::FUN_14261e310();
    ((void (*)(void*, unsigned))(*(void***)pstat)[46])(pstat, DataSize);
    Memory::pGlobalHeap->Free(pData);
}

// MS2-FUNCTIONAL: frees the file name copy.
// @0x142747e90
SoundFile::~SoundFile()
{
    Memory::pGlobalHeap->Free(pFileName);
}

// Positions the read cursor on the chunk holding the given byte offset.
// @0x1427483a0
bool AppendableSoundData::SetReadPosition(unsigned pos)
{
    Lock::Locker lock(&ChunkLock);
    if (!pReadChunk)
        return false;
    pReadChunk   = pFirstChunk;
    unsigned end = pReadChunk->Used;
    for (;;)
    {
        if (pos < end)
        {
            ReadPos = pReadChunk->Used - end + pos;
            return true;
        }
        if (!pReadChunk->pNext)
            return false;
        pReadChunk = pReadChunk->pNext;
        end += pReadChunk->Used;
    }
}

// MS2-FUNCTIONAL: releases the chunk lock taken by LockDataForAppend.
// @0x142748420
void AppendableSoundData::UnlockData()
{
    ChunkLock.Unlock();
}

// Sample data held in memory: refcount and format, then the zero filled block from the global heap,
// whose size is reported to the global statistics object.
// @0x142747c70
SoundData::SoundData(unsigned format, unsigned rate, unsigned length, unsigned dsize)
    : SoundDataBase(format, rate, length), pData(0), DataSize(dsize)
{
    pData = (UByte*)Memory::pGlobalHeap->Alloc(dsize, 0x20, (const AllocInfo*)0);
    memset(pData, 0, DataSize);
    void* pstat = Scaleform::GFx::FUN_14261e310();
    ((void (*)(void*, unsigned))(*(void***)pstat)[45])(pstat, DataSize);
}

// Sample data in a file: the file name is kept as a heap copy.
// @0x142747cf0
SoundFile::SoundFile(const char* fname, unsigned rate, unsigned length, bool streaming)
    : SoundDataBase(Sample_File, rate, length)
{
    if (streaming)
        Format |= Sample_Stream;
    UPInt size = strlen(fname) + 1;
    pFileName  = (char*)Memory::pGlobalHeap->Alloc(size, (const AllocInfo*)0);
    memset(pFileName, 0, size);
    sfr_strcpy_s_thunk(pFileName, size, fname);
}

// MS2-FUNCTIONAL: drops the renderer's sample and the data description (the exe's out of line destructor body).
// @0x142748430
SoundInfo::~SoundInfo()
{
}

// The data's sample rate, 0 without data.
// @0x142748490
unsigned SoundInfo::GetRate() const
{
    return pSound ? pSound->GetRate() : 0;
}

// MS2-FUNCTIONAL: the renderer's sample for this data, created on first use (or when the old one lost its data).
// @0x1427484a0
SoundSample* SoundInfo::GetSoundSample(SoundRenderer* prenderer)
{
    if (pSoundSample && pSoundSample->IsDataValid())
        return pSoundSample;
    if (pSound)
        pSoundSample = *prenderer->CreateSampleFromData(pSound);
    return pSoundSample;
}

// MS2-FUNCTIONAL: drops the renderer's sample.
// @0x142748540
void SoundInfo::ReleaseResource()
{
    pSoundSample = 0;
}

// MS2-FUNCTIONAL: replaces the sample data and forgets the old renderer sample.
// @0x142748580
bool SoundInfo::SetSoundData(SoundDataBase* psound)
{
    pSound       = psound;
    pSoundSample = 0;
    return true;
}

}} // namespace Scaleform::Sound
// MS2-PIN: ??_7SoundData@Sound@Scaleform@@6B@ 0x1431bef70
// MS2-PIN: ??_7AppendableSoundData@Sound@Scaleform@@6B@ 0x1431bef78
// MS2-PIN: ??_7SoundFile@Sound@Scaleform@@6B@ 0x1431bef80
// MS2-PIN: ??_7SoundInfo@Sound@Scaleform@@6B@ 0x14318ffa8
// MS2-PIN: ??_GSoundData@Sound@Scaleform@@UEAAPEAXI@Z 0x142747ff0
// MS2-PIN: ??_7?$RefCountBaseNTS@VSoundDataBase@Sound@Scaleform@@$03@Scaleform@@6B@ 0x1431bef60
// MS2-PIN: ??_7SoundDataBase@Sound@Scaleform@@6B@ 0x1431bef68
// MS2-PIN: ??_G?$RefCountBaseNTS@VSoundDataBase@Sound@Scaleform@@$03@Scaleform@@UEAAPEAXI@Z 0x142747ed0
// MS2-PIN: ??_GSoundDataBase@Sound@Scaleform@@UEAAPEAXI@Z 0x142748080
