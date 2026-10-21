// Recovered Scaleform 4.1.18 GFx: the movie implementation (MovieImpl), as far as the recovered units call into it.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder. The bases (Movie :
// RefCountBase, StateBag) are not recovered yet; their words are kept as placeholders up to the members read.
#ifndef MS2_SF_GFX_MOVIEIMPL_H
#define MS2_SF_GFX_MOVIEIMPL_H

namespace Scaleform { namespace GFx {

class ASMovieRootBase;
class DisplayObjectBase;
class InteractiveObject;
class MovieDefImpl;

class MovieImpl
{
public:
    void*            MovieBase_Unrecovered[3]; // +0x00 RefCountBase vftable + count, StateBag vftable
    ASMovieRootBase* pASMovieRoot;             // +0x18 Ptr<ASMovieRootBase>: the AVM specific root
    void*            Unrecovered_20[6];        // +0x20
    InteractiveObject* pMainMovie;             // +0x50 _level0
    void*            Unrecovered_58[0x5b1];    // +0x58
    // A character the timeline keeps advancing even when stopped (MS2 build; Sprite::CheckAdvanceStatus).
    DisplayObjectBase* pKeepAdvancingChar;     // +0x2de0

    // Removes the setInterval/setTimeout timer with the given id (exe 0x14256e0d0).
    void ClearIntervalTimer(int id);
};

// The root of one loaded movie's sprite tree; leading members only (the font manager, bytes loaded and so on).
class MovieDefRootNode
{
public:
    MovieDefRootNode* pPrev;          // +0x00 ListNode
    MovieDefRootNode* pNext;          // +0x08
    unsigned          SpriteRefCount; // +0x10
    MovieDefImpl*     pDefImpl;       // +0x18
    void*             pFontManager;   // +0x20 Ptr<FontManager>
    unsigned          LoadingFrame;   // +0x28
    unsigned          BytesLoaded;    // +0x2c
    bool              ImportFlag;     // +0x30 the root of an import: its loading state is the parent's
};

}} // namespace Scaleform::GFx

#endif
