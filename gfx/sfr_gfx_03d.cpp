// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_IMEManager (IMEManagerBase:
// the platform independent half of the IME manager state: the active movie and the field being composed into,
// one VM side IME manager per movie, the composition calls a platform manager makes).
// Queue unit sfr_gfx_03 is split along its original sources: this file is GFx_IMEManager. The base Broadcast*
// forwarders were folded by the linker into the AS2 range (0x1423c9020..), they are in this TU's source.
// MS2-UNIT: sfr_gfx_03d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425b3a90-0x1425b5290 .text$mn
// MS2-RANGE: 0x1423c9020-0x1423c9140 .text$mn
// MS2-PIN: ??_7IMEManagerBase@GFx@Scaleform@@6B@ 0x1431898c8
// MS2-PIN: ??_7IMEFuncHandler@ASIMEManager@GFx@Scaleform@@6B@ 0x1431898b8

#include "../include/gfx/gfx_imemanager.h"
#include "../include/gfx/gfx_textfield.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_imecandidateliststyle.h"
#include "../include/render/render_twips.h"

namespace Scaleform { namespace GFx {

// The text field that has the focus of the movie's first controller, when it is one (NULL otherwise).
static inline Ptr<InteractiveObject> FocusedCharacter(Movie* pmovie)
{
    MovieImpl* proot = reinterpret_cast<MovieImpl*>(pmovie);
    return proot->FocusGroups[proot->FocusGroupIndexes[0]].LastFocused;
}

// A rectangle in twips, in pixels.
static inline Render::RectF RectTwipsToPixels(const Render::RectF& r)
{
    return Render::RectF(Render::TwipsToPixels(r.x1), Render::TwipsToPixels(r.y1), Render::TwipsToPixels(r.x2), Render::TwipsToPixels(r.y2));
}

// @0x1425b3e90
IMEManagerBase::IMEManagerBase() : State(State_IMEManager)
{
    pASIMEManager  = NULL;
    IMEDisabled    = false;
    pMovie         = NULL;
    pTextField     = NULL;
    CursorPosition = 0;
}

// @0x1425b3fb0
IMEManagerBase::~IMEManagerBase()
{
    pASIMEManager = NULL;
}

// @0x1425b4890
UInt32 IMEManagerBase::Init(Log*, FileOpener*, const char*, bool bcheckIMEExists)
{
    bCheckIMEExists = bcheckIMEExists;
    return 1;
}

// @0x1425b4880
void IMEManagerBase::IMECommand(Movie*, const char*, const char*) {}

// @0x1425b4980
void IMEManagerBase::ProcessIMEMessage(const FunctionHandler::Params&) {}

// @0x1425b4810
unsigned IMEManagerBase::HandleIMEEvent(Movie*, const IMEEvent&)
{
    return 0;
}

// @0x1425b43b0
void IMEManagerBase::ClearCandidateListPath() {}

// @0x1425b4e90
bool IMEManagerBase::SetConversionMode(const UInt32)
{
    return false;
}

// @0x1425b4660
const char* IMEManagerBase::GetConversionMode()
{
    return "UNKNOWN";
}

// @0x1425b4eb0
bool IMEManagerBase::SetEnabled(bool)
{
    return false;
}

// @0x1425b4670
bool IMEManagerBase::GetEnabled()
{
    return false;
}

// @0x1425b4680
const String IMEManagerBase::GetInputLanguage()
{
    return String("UNKNOWN");
}

// @0x1423c9040
void IMEManagerBase::BroadcastIMEConversion(const wchar_t* pstr)
{
    if (pASIMEManager)
        pASIMEManager->BroadcastIMEConversion(pstr);
}

// @0x1423c9120
void IMEManagerBase::BroadcastSwitchLanguage(const char* pstr)
{
    if (pASIMEManager)
        pASIMEManager->BroadcastSwitchLanguage(pstr);
}

// @0x1423c9100
void IMEManagerBase::BroadcastSetSupportedLanguages(const char* pstr)
{
    if (pASIMEManager)
        pASIMEManager->BroadcastSetSupportedLanguages(pstr);
}

// @0x1423c90e0
void IMEManagerBase::BroadcastSetSupportedIMEs(const char* pstr)
{
    if (pASIMEManager)
        pASIMEManager->BroadcastSetSupportedIMEs(pstr);
}

// @0x1423c90a0
void IMEManagerBase::BroadcastSetCurrentInputLanguage(const char* pstr)
{
    if (pASIMEManager)
        pASIMEManager->BroadcastSetCurrentInputLanguage(pstr);
}

// @0x1423c90c0
void IMEManagerBase::BroadcastSetIMEName(const char* pstr)
{
    if (pASIMEManager)
        pASIMEManager->BroadcastSetIMEName(pstr);
}

// @0x1423c9080
void IMEManagerBase::BroadcastSetConversionStatus(const char* pstr)
{
    if (pASIMEManager)
        pASIMEManager->BroadcastSetConversionStatus(pstr);
}

// @0x1423c9060
void IMEManagerBase::BroadcastRemoveStatusWindow()
{
    if (pASIMEManager)
        pASIMEManager->BroadcastRemoveStatusWindow("");
}

// @0x1423c9020
void IMEManagerBase::BroadcastDisplayStatusWindow()
{
    if (pASIMEManager)
        pASIMEManager->BroadcastDisplayStatusWindow("");
}

// @0x1425b49a0
void IMEManagerBase::SendLangBarMessage(DisplayObject*, const ASString&, const ASString&) {}

// @0x1425b4e70
bool IMEManagerBase::SetCompositionString(const char*)
{
    return false;
}

// @0x1425b4590
const wchar_t* IMEManagerBase::GetCompositionString()
{
    if (pMovie)
    {
        Ptr<InteractiveObject> pfocused = FocusedCharacter(pMovie);
        if (pfocused && pfocused->GetType() == CharacterDef::TextField)
        {
            Ptr<TextField> ptextField = reinterpret_cast<TextField*>(pfocused.GetPtr());
            return ptextField->GetCompositionString();
        }
    }
    return NULL;
}

// @0x1425b4970
void IMEManagerBase::OnShutdown() {}

// @0x1425b48f0
void IMEManagerBase::OnFinalize() {}

// @0x1425b48c0
void IMEManagerBase::OnCandidateListStyleChanged(const IMECandidateListStyle&) {}

// @0x1425b48b0
void IMEManagerBase::OnCandidateListLoaded(const char*) {}

// @0x1425b48d0
void IMEManagerBase::OnCandidateListStyleRequest(IMECandidateListStyle* pstyle) const
{
    if (pMovie)
        reinterpret_cast<MovieImpl*>(pMovie)->GetIMECandidateListStyle(pstyle);
}

// @0x1425b48e0
void IMEManagerBase::OnEnableIME(bool) {}

// MS2-FUNCTIONAL 0x1425b49b0: hash lookup through Find and the Ptr temporaries differ in codegen; same steps in the same order
// @0x1425b49b0
void IMEManagerBase::SetActiveMovie(Movie* pmovie)
{
    if (pmovie == pMovie)
        return;
    if (pmovie)
    {
        ClearActiveMovie();
        OnFinalize();
        pTextField = NULL;
        Hash<Movie*, Ptr<ASIMEManager>, FixedSizeHash<Movie*> >::Iterator it = MovieASIMEManagerHash.Find(pmovie);
        if (it == MovieASIMEManagerHash.End())
        {
            ClearCandidateListPath();
            ASSupport* psupport = reinterpret_cast<MovieImpl*>(pmovie)->pASMovieRoot->pASSupport;
            if (psupport)
            {
                pASIMEManager = psupport->CreateASIMEManager();
                if (pASIMEManager)
                {
                    pASIMEManager->SetIMEManager(this);
                    pASIMEManager->SetIMEMoviePath(CandidateSwfPath.ToCStr());
                    pASIMEManager->CustomFuncCandList    = *SF_NEW ASIMEManager::IMEFuncHandler(this);
                    pASIMEManager->CustomFuncLanguageBar = *SF_NEW ASIMEManager::IMEFuncHandler(this);
                    pASIMEManager->SetActiveMovie(pmovie);
                    MovieASIMEManagerHash.Add(pmovie, pASIMEManager);
                }
            }
        }
        else
            pASIMEManager = it->Second;
    }
    pTextField = NULL;
    pMovie     = pmovie;
}

// @0x1425b48a0
bool IMEManagerBase::IsMovieActive(Movie* pmovie) const
{
    return pMovie == pmovie;
}

// @0x1425b4520
Movie* IMEManagerBase::GetActiveMovie() const
{
    return pMovie;
}

// @0x1425b41e0
void IMEManagerBase::ClearActiveMovie()
{
    if (!pMovie)
        return;
    MovieASIMEManagerHash.Remove(pMovie);
    if (pASIMEManager)
        pASIMEManager->ShutDown();
    pTextField = NULL;
    pMovie     = NULL;
    OnShutdown();
}

// @0x1425b47e0
String IMEManagerBase::GetWindowsVersion()
{
    return String("Unknown");
}

// @0x1425b43d0
void IMEManagerBase::DoFinalize()
{
    OnFinalize();
    pTextField = NULL;
}

// @0x1425b4400
void IMEManagerBase::EnableIME(bool enable)
{
    if (IMEDisabled == enable)
    {
        IMEDisabled = !IMEDisabled;
        OnEnableIME(enable);
    }
}

// @0x1425b4420
void IMEManagerBase::FinalizeComposition(const wchar_t* pstr, UPInt len)
{
    if (pTextField)
    {
        pTextField->CommitCompositionString(pstr, len);
        return;
    }
    if (pMovie)
    {
        Ptr<InteractiveObject> pfocused = FocusedCharacter(pMovie);
        if (pfocused && pfocused->GetType() == CharacterDef::TextField)
        {
            TextField* ptextField = reinterpret_cast<TextField*>(pfocused.GetPtr());
            UPInt endIndex = ptextField->GetEndIndex();
            ptextField->ReplaceTextA(pstr, ptextField->GetBeginIndex(), endIndex, len);
        }
    }
}

// @0x1425b4ec0
void IMEManagerBase::SetWideCursor(bool ow)
{
    if (pTextField)
        pTextField->SetWideCursor(ow);
}

// @0x1425b4900
void IMEManagerBase::OnMouseDown(Movie* pmovie, int, InteractiveObject* ptopMostChar)
{
    if (IsMovieActive(pmovie) && pTextField && ptopMostChar == reinterpret_cast<InteractiveObject*>(pTextField.GetPtr()))
    {
        OnFinalize();
        pTextField = NULL;
    }
}

// @0x1425b4960
void IMEManagerBase::OnMouseUp(Movie*, int, InteractiveObject*) {}

// @0x1425b4570
bool IMEManagerBase::GetCandidateListStyle(IMECandidateListStyle* pstyle) const
{
    if (pMovie)
    {
        reinterpret_cast<MovieImpl*>(pMovie)->GetIMECandidateListStyle(pstyle);
        return true;
    }
    return false;
}

// @0x1425b4de0
bool IMEManagerBase::SetCandidateListStyle(const IMECandidateListStyle& st)
{
    if (pMovie)
        reinterpret_cast<MovieImpl*>(pMovie)->SetIMECandidateListStyle(st);
    if (pASIMEManager && pASIMEManager->IsCandidateListLoaded())
    {
        OnCandidateListStyleChanged(st);
        return true;
    }
    return false;
}

// @0x1425b4ed0
void IMEManagerBase::StartComposition()
{
    if (!pMovie)
        return;
    Ptr<InteractiveObject> pfocused = FocusedCharacter(pMovie);
    if (pfocused && pfocused->GetType() == CharacterDef::TextField)
    {
        Ptr<TextField> ptextField = reinterpret_cast<TextField*>(pfocused.GetPtr());
        if (!ptextField->IsIMEDisabledFlag() && !ptextField->IsReadOnly() && !ptextField->IsPassword())
        {
            pTextField = ptextField;
            pASIMEManager->pTextField = ptextField;
            UPInt beginIndex = pTextField->GetBeginIndex();
            UPInt endIndex   = pTextField->GetEndIndex();
            pTextField->ReplaceTextA(L"", beginIndex, endIndex, endIndex - beginIndex);
            CursorPosition = beginIndex;
            pTextField->SetSelection(beginIndex, beginIndex);
            pTextField->CreateCompositionString();
        }
    }
}

// @0x1425b43c0
void IMEManagerBase::ClearComposition()
{
    if (pTextField)
        pTextField->ClearCompositionString();
}

// @0x1425b4e80
void IMEManagerBase::SetCompositionText(const wchar_t* pstr, UPInt len)
{
    if (pTextField)
        pTextField->SetCompositionStringText(pstr, len);
}

// MS2-FUNCTIONAL 0x1425b4e40: register allocation differs; same calls
// @0x1425b4e40
void IMEManagerBase::SetCompositionPosition()
{
    if (pTextField)
        pTextField->SetCompositionStringPosition(pTextField->GetCaretIndex());
}

// @0x1425b4ea0
void IMEManagerBase::SetCursorInComposition(UPInt pos)
{
    if (pTextField)
        pTextField->SetCursorInCompositionString(pos);
}

// MS2-FUNCTIONAL 0x1425b4820: the switch compiles to a different branch order; same category per style
// @0x1425b4820
void IMEManagerBase::HighlightText(UPInt pos, UPInt len, TextHighlightStyle style, bool)
{
    if (!pTextField)
        return;
    // The Text::IMEStyle::Category of each style (the text_editorkit.h world does not mix with this TU's headers).
    unsigned cat;
    switch (style)
    {
    case THS_ClauseSegment:    cat = 1; break;   // SC_ClauseSegment
    case THS_ConvertedSegment: cat = 2; break;   // SC_ConvertedSegment
    case THS_PhraseLengthAdj:  cat = 3; break;   // SC_PhraseLengthAdj
    case THS_LowConfSegment:   cat = 4; break;   // SC_LowConfSegment
    default:                   cat = 0; break;   // SC_CompositionSegment
    }
    pTextField->HighlightCompositionStringText(pos, len, cat);
}

// MS2-FUNCTIONAL 0x1425b46b0: codegen differs (matrix / rect copies and the clamp); same calls and results
// @0x1425b46b0
void IMEManagerBase::GetMetrics(Render::RectF* pviewRect, Render::RectF* pcursorRect, int cursorOffset)
{
    if (!pTextField)
        return;
    DisplayObjectBase* pobj = pTextField;
    Render::Matrix2F wm;
    pobj->GetWorldMatrix(&wm);
    Render::RectF bounds = pobj->GetBounds(wm);
    if (pviewRect)
        *pviewRect = RectTwipsToPixels(bounds);
    SPInt cursorPos;
    UPInt compPos = pTextField->GetCompositionStringPosition();
    if (compPos == SF_MAX_UPINT)
        cursorPos = pTextField->GetCaretIndex();
    else
        cursorPos = SPInt(compPos + pTextField->GetCompositionStringLength());
    cursorPos += cursorOffset;
    Render::RectF cursorRect = pTextField->GetCursorBounds(cursorPos < 0 ? 0 : UPInt(cursorPos), NULL, NULL);
    Render::RectF r;
    wm.EncloseTransform(&r, cursorRect);
    if (pcursorRect)
        *pcursorRect = RectTwipsToPixels(r);
}

// @0x1425b4530
bool IMEManagerBase::GetCandidateListErrorMsg(String* pdest)
{
    if (pdest)
        *pdest = pASIMEManager->CandidateSwfErrorMsg;
    return pASIMEManager->CandidateSwfErrorMsg.GetLength() != 0;
}

// @0x1425b4180
void ASIMEManager::IMEFuncHandler::Call(const Params& params)
{
    pimeManager->ProcessIMEMessage(params);
}

}} // namespace Scaleform::GFx
