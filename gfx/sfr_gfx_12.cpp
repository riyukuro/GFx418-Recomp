// Recovered Scaleform GFx 4.1.18 pieces that no unit owned (own source, written from the exe; SDK material is reference
// only): the Expat based XML parser's ParseFile / ParseString, and the Sound module's sample data objects (SoundData,
// SoundFile, AppendableSoundData and its chunk list, SoundInfo).
// MS2-UNIT: sfr_gfx_12
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1423b1920-0x1423b1d3d .text$mn
// MS2-RANGE: 0x142747bc0-0x142747d98 .text$mn
// MS2-RANGE: 0x142747da0-0x142747ed0 .text$mn
// MS2-RANGE: 0x142747f30-0x142748080 .text$mn
// MS2-RANGE: 0x1427480e0-0x142748150 .text$mn
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

// The Expat library linked into the exe (parser handle, handler setters, error and position queries).
ExeDecl<void*(const char*)> FUN_1423b2eb0;
#define XML_ParserCreate FUN_1423b2eb0
ExeDecl<void(void*, void*)> FUN_1423b3500;
#define XML_SetXmlDeclHandler FUN_1423b3500
ExeDecl<void(void*, void*)> FUN_1423b3400;
#define XML_SetStartElementHandler FUN_1423b3400
ExeDecl<void(void*, void*)> FUN_1423b3310;
#define XML_SetEndElementHandler FUN_1423b3310
ExeDecl<void(void*, void*)> FUN_1423b3320;
#define XML_SetCharacterDataHandler FUN_1423b3320
ExeDecl<void(void*, void*)> FUN_1423b3560;
#define XML_SetStartNamespaceDeclHandler FUN_1423b3560
ExeDecl<void(void*, void*)> FUN_1423b3330;
#define XML_SetCommentHandler FUN_1423b3330
ExeDecl<void(void*, void*)> FUN_1423b3540;
#define XML_SetUserData FUN_1423b3540
ExeDecl<int(void*, const char*, int, int)> FUN_1423b2c20;
#define XML_Parse FUN_1423b2c20
ExeDecl<int(void*)> FUN_1423b2ab0;
#define XML_GetCurrentColumnNumber FUN_1423b2ab0
ExeDecl<int(void*)> FUN_1423b2b10;
#define XML_GetCurrentLineNumber FUN_1423b2b10
ExeDecl<int(void*)> FUN_1423b2a90;
#define XML_GetCurrentByteIndex FUN_1423b2a90
ExeDecl<int(void*)> FUN_1423b2b70;
#define XML_GetErrorCode FUN_1423b2b70
ExeDecl<const char*(int)> FUN_1423b24b0;
#define XML_ErrorString FUN_1423b24b0
ExeDecl<void(void*)> FUN_1423b2f30;
#define XML_ParserFree FUN_1423b2f30
// The parser's own callbacks (the handler / user data protocol is private to the exe's ParserExpat).
ExeDecl<void()> FUN_1423b1d40;
#define ParserExpat_XmlDeclCallback FUN_1423b1d40
ExeDecl<void()> FUN_1423b17d0;
#define ParserExpat_StartElementCallback FUN_1423b17d0
ExeDecl<void()> FUN_1423b1660;
#define ParserExpat_EndElementCallback FUN_1423b1660
ExeDecl<void()> FUN_1423b16d0;
#define ParserExpat_CharacterDataCallback FUN_1423b16d0
ExeDecl<void()> FUN_1423b23e0;
#define ParserExpat_StartNamespaceCallback FUN_1423b23e0
ExeDecl<void()> FUN_1423b1760;
#define ParserExpat_CommentCallback FUN_1423b1760
// Formats one message into a small caller supplied buffer descriptor (mode 2, buffer, capacity).
struct Unk_XmlMsgBuffer { int Mode; char* Buffer; UPInt Capacity; };
ExeDecl<void(Unk_XmlMsgBuffer*, const char*, const char**)> FUN_1423b14e0;
static const char Unk_FileIsEmptyFormat[] = "File {0} is empty!";        // exe 0x143135720
static const char Unk_FileMissingFormat[] = "File {0} does not exist!";  // exe 0x143135738

namespace Scaleform { namespace GFx { namespace XML {

// MS2-FUNCTIONAL: opens the file, reads it whole into a temporary buffer and parses it; reports a missing or empty file
// to the handler's warning / fatal error callbacks.
// @0x1423b1920
bool ParserExpat::ParseFile(const char* pfilename, FileOpenerBase* pfo, ParserHandler* pphandler)
{
    ParserLocator locator;
    char          message[0x100];
    bool          result = false;
    File*         pfile  = pfo->OpenFile(pfilename, 0x21, 0x1b6);
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
            UPInt size = 0;
            while (message[size] != 0)
                ++size;
            ParserException exception(StringRef(message, size));
            pphandler->Warning(exception);
        }
    }
    else
    {
        pphandler->SetDocumentLocator(&locator);
        Unk_XmlMsgBuffer buffer = {2, message, 0x100};
        FUN_1423b14e0(&buffer, Unk_FileMissingFormat, &pfilename);
        UPInt size = 0;
        while (message[size] != 0)
            ++size;
        ParserException exception(StringRef(message, size));
        pphandler->FatalError(exception);
    }
    if (pfile)
        pfile->Release();
    return result;
}

// MS2-FUNCTIONAL: parses an in-memory document with Expat and feeds the handler; a parse error is reported with the
// position and Expat's error string.
// @0x1423b1b60
bool ParserExpat::ParseString(const char* pdata, UPInt len, ParserHandler* pphandler)
{
    ParserLocator locator;
    pphandler->SetDocumentLocator(&locator);
    void* parser = XML_ParserCreate(0);
    XML_SetXmlDeclHandler(parser, &ParserExpat_XmlDeclCallback);
    XML_SetStartElementHandler(parser, &ParserExpat_StartElementCallback);
    XML_SetEndElementHandler(parser, &ParserExpat_EndElementCallback);
    XML_SetCharacterDataHandler(parser, &ParserExpat_CharacterDataCallback);
    XML_SetStartNamespaceDeclHandler(parser, &ParserExpat_StartNamespaceCallback);
    XML_SetCommentHandler(parser, &ParserExpat_CommentCallback);
    struct { void* Parser; ParserHandler* Handler; ParserLocator* Locator; } userData = {parser, pphandler, &locator};
    XML_SetUserData(parser, &userData);
    pphandler->StartDocument();
    bool result;
    if (XML_Parse(parser, pdata, (int)len, 1) == 1)
    {
        locator.Column      = XML_GetCurrentColumnNumber(parser) + 1;
        locator.Line        = XML_GetCurrentLineNumber(parser);
        locator.LoadedBytes = (SPInt)XML_GetCurrentByteIndex(parser);
        pphandler->EndDocument();
        result = true;
    }
    else
    {
        locator.Column      = XML_GetCurrentColumnNumber(parser) + 1;
        locator.Line        = XML_GetCurrentLineNumber(parser);
        locator.LoadedBytes = (SPInt)XML_GetCurrentByteIndex(parser);
        const char* text = XML_ErrorString(XML_GetErrorCode(parser));
        UPInt size = 0;
        if (text)
        {
            while (text[size] != 0)
                ++size;
        }
        ParserException exception(StringRef(text, size));
        pphandler->FatalError(exception);
        result = false;
    }
    XML_ParserFree(parser);
    return result;
}

}}} // namespace Scaleform::GFx::XML

// ---- the Sound module ----

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

// MS2-FUNCTIONAL: appends room for length samples (dsize bytes) to the chunk list and returns the write position; the
// chunk lock stays held until UnlockData.
// The chunks come from the global heap's Alloc (DataChunk has no heap operator new: SF_HEAP_NEW on it was the
// placement new at the heap object itself).
// @0x142748230
UByte* AppendableSoundData::LockDataForAppend(unsigned length, unsigned dsize)
{
    ChunkLock.DoLock();
    if (!pFirstChunk)
        pFirstChunk = pFillChunk = pReadChunk = new (Memory::pGlobalHeap->Alloc(sizeof(DataChunk))) DataChunk(0x4000);
    if (dsize > 0x4000u - pFillChunk->Used)
    {
        DataChunk* pnew = new (Memory::pGlobalHeap->Alloc(sizeof(DataChunk))) DataChunk(0x4000);
        pFillChunk->pNext = pnew;
        pFillChunk->pNext->Reserved14 = pFillChunk->Samples + pFillChunk->Reserved14;
        pFillChunk = pFillChunk->pNext;
    }
    DataChunk* pcur = pFillChunk;
    unsigned   used = pcur->Used;
    pcur->Used      = used + dsize;
    pFillChunk->Samples += length;
    DataSize += dsize;
    Length += length;
    return pcur->pData + used;
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

// The global statistics object the exe reports sample bytes to (slot 45 on alloc, slot 46 on free).
extern "C" void* FUN_14261e310();

// MS2-FUNCTIONAL: reports the freed byte count to the global statistics object and frees the sample block.
// @0x142747e40
SoundData::~SoundData()
{
    void* pstat = FUN_14261e310();
    ((void (*)(void*, unsigned))(*(void***)pstat)[46])(pstat, DataSize);
    Memory::pGlobalHeap->Free(pData);
}

// MS2-FUNCTIONAL: frees the file name copy.
// @0x142747e90
SoundFile::~SoundFile()
{
    Memory::pGlobalHeap->Free(pFileName);
}

// MS2-FUNCTIONAL: positions the read cursor on the chunk holding the given byte offset.
// @0x1427483a0
bool AppendableSoundData::SetReadPosition(unsigned pos)
{
    ChunkLock.DoLock();
    bool found = false;
    if (pReadChunk)
    {
        pReadChunk = pFirstChunk;
        unsigned end = pReadChunk->Used;
        while (pos >= end)
        {
            DataChunk* pnext = pReadChunk->pNext;
            if (!pnext)
                goto done;
            pReadChunk = pnext;
            end += pnext->Used;
        }
        ReadPos = pReadChunk->Used - end + pos;
        found   = true;
    }
done:
    ChunkLock.Unlock();
    return found;
}

// MS2-FUNCTIONAL: releases the chunk lock taken by LockDataForAppend.
// @0x142748420
void AppendableSoundData::UnlockData()
{
    ChunkLock.Unlock();
}

// MS2-FUNCTIONAL: sample data held in memory: refcount and format, then the zero filled block from the global heap,
// whose size is reported to the global statistics object.
// @0x142747c70
SoundData::SoundData(unsigned format, unsigned rate, unsigned length, unsigned dsize)
    : SoundDataBase(format, rate, length)
{
    DataSize = dsize;
    pData    = (UByte*)Memory::pGlobalHeap->Alloc(dsize, 0x20, (const AllocInfo*)0);
    memset(pData, 0, DataSize);
    void* pstat = FUN_14261e310();
    ((void (*)(void*, unsigned))(*(void***)pstat)[45])(pstat, DataSize);
}

// MS2-FUNCTIONAL: sample data in a file: the file name is kept as a heap copy.
// @0x142747cf0
SoundFile::SoundFile(const char* fname, unsigned rate, unsigned length, bool streaming)
    : SoundDataBase(streaming ? (Sample_File | Sample_Stream) : Sample_File, rate, length)
{
    UPInt size = strlen(fname) + 1;
    pFileName  = (char*)Memory::pGlobalHeap->Alloc(size, (const AllocInfo*)0);
    memset(pFileName, 0, size);
    memcpy(pFileName, fname, size);
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
