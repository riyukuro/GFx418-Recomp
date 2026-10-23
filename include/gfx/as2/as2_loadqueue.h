// Recovered Scaleform 4.1.18 GFx AS2: the file loaders behind XML.load and TextField.StyleSheet.load, and the
// loader-thread tasks that run them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// Only what the task Execute functions use is recovered so far; the queue entries and the loaders' other
// virtuals are declared when their functions are recovered.
#ifndef MS2_SF_GFX_AS2_LOADQUEUE_H
#define MS2_SF_GFX_AS2_LOADQUEUE_H

#include "as2_value.h"
#include "../gfx_taskmanager.h"
#include "../gfx_loaderimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Loads and parses a style sheet file for a TextField.StyleSheet object.
class ASCSSFileLoader : public RefCountBase<ASCSSFileLoader, StatMV_ActionScript_Mem>
{
public:
    virtual void Load(const String& filename, FileOpener* pfo) = 0;
};

// Loads and parses an XML file for an XML object.
class XMLFileLoader : public RefCountBase<XMLFileLoader, StatMV_ActionScript_Mem>
{
public:
    virtual void Load(const String& filename, FileOpener* pfo) = 0;
};

// Loads the file of an XML.load / StyleSheet.load on a loader thread; Done tells the movie the loader is ready.
// 0x40 bytes.
template<class FileLoader, URLBuilder::FileUse Use>
class GFxAS2LoadFileTask : public Task
{
protected:
    Ptr<LoadStates>  pLoadStates; // +0x18
    String           Level0Path;  // +0x20
    String           Url;         // +0x28
    Ptr<FileLoader>  pLoader;     // +0x30
    volatile int     Done;        // +0x38

public:
    // The loader was given the file through the file opener of the load states.
    void LoadFile()
    {
        URLBuilder::LocationInfo loc(Use, Url, Level0Path);
        String                   fileName;
        pLoadStates->BuildURL(&fileName, loc);
        pLoader->Load(fileName.ToCStr(), static_cast<FileOpener*>(pLoadStates->GetBindStates()->pFileOpener.GetPtr()));
        Done = 1;
    }
    bool IsDone() const { return Done != 0; }
};

class GFxAS2LoadCSSTask : public GFxAS2LoadFileTask<ASCSSFileLoader, URLBuilder::File_LoadCSS>
{
public:
    virtual void Execute(); // exe 0x14293fcd0
};

class GFxAS2LoadXMLTask : public GFxAS2LoadFileTask<XMLFileLoader, URLBuilder::File_LoadXML>
{
public:
    virtual void Execute(); // exe 0x14293fdf0
};

}}} // namespace Scaleform::GFx::AS2

#endif
