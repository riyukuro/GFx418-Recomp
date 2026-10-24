// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 TextSnapshot glyph visitor of
// sfr_as2_06 (gap recovery, lane sfr24): TextSnapshot.getTextRunInfo turns each visited glyph into an info object.
// MS2-UNIT: sfr_as2_06s6
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14296d330-0x14296ddd6 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_textsnapshot.h"
#include "../include/render/render_twips.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The glyph's run index, selection, font, color, size, matrix and corners (in pixels) as an object pushed onto the
// result array.
// MS2-FUNCTIONAL: register allocation and stack layout differ.
// @0x14296d330
void GASTextSnapshotGlyphVisitor::OnVisit()
{
    Ptr<Object> pobj = *SF_HEAP_NEW(pEnv->GetHeap()) Object(pEnv);

    Value val((int)GetRunIndex());
    pobj->SetMember(pEnv, pEnv->CreateConstString("indexInRun"), val);

    ASString fontName = pEnv->CreateString(GetFont()->GetName());
    pobj->SetMember(pEnv, pEnv->CreateConstString("font"), Value(fontName));

    val.SetNumber((float)GetColor().ToColor32());
    pobj->SetMember(pEnv, pEnv->CreateConstString("color"), val);

    val.SetNumber(GetHeight());
    pobj->SetMember(pEnv, pEnv->GetBuiltin(ASBuiltin_height), val);

    val.SetBool(IsSelected());
    pobj->SetMember(pEnv, pEnv->CreateConstString("selected"), val);

    const Render::Matrix2F& mat = GetMatrix();
    val.SetNumber(Render::TwipsToPixels(mat.Sx()));
    pobj->SetMember(pEnv, pEnv->CreateString("matrix_a"), val);
    val.SetNumber(Render::TwipsToPixels(mat.Shy()));
    pobj->SetMember(pEnv, pEnv->CreateString("matrix_b"), val);
    val.SetNumber(Render::TwipsToPixels(mat.Shx()));
    pobj->SetMember(pEnv, pEnv->CreateString("matrix_c"), val);
    val.SetNumber(Render::TwipsToPixels(mat.Sy()));
    pobj->SetMember(pEnv, pEnv->CreateString("matrix_d"), val);
    val.SetNumber(Render::TwipsToPixels(mat.Tx()));
    pobj->SetMember(pEnv, pEnv->CreateString("matrix_tx"), val);
    val.SetNumber(Render::TwipsToPixels(mat.Ty()));
    pobj->SetMember(pEnv, pEnv->CreateString("matrix_ty"), val);

    const Render::PointF& bl = GetCorners().BottomLeft();
    const Render::PointF& br = GetCorners().BottomRight();
    const Render::PointF& tl = GetCorners().TopLeft();
    const Render::PointF& tr = GetCorners().TopRight();
    val.SetNumber(Render::TwipsToPixels(bl.x));
    pobj->SetMember(pEnv, pEnv->CreateString("corner0x"), val);
    val.SetNumber(Render::TwipsToPixels(bl.y));
    pobj->SetMember(pEnv, pEnv->CreateString("corner0y"), val);
    val.SetNumber(Render::TwipsToPixels(br.x));
    pobj->SetMember(pEnv, pEnv->CreateString("corner1x"), val);
    val.SetNumber(Render::TwipsToPixels(br.y));
    pobj->SetMember(pEnv, pEnv->CreateString("corner1y"), val);
    val.SetNumber(Render::TwipsToPixels(tr.x));
    pobj->SetMember(pEnv, pEnv->CreateString("corner2x"), val);
    val.SetNumber(Render::TwipsToPixels(tr.y));
    pobj->SetMember(pEnv, pEnv->CreateString("corner2y"), val);
    val.SetNumber(Render::TwipsToPixels(tl.x));
    pobj->SetMember(pEnv, pEnv->CreateString("corner3x"), val);
    val.SetNumber(Render::TwipsToPixels(tl.y));
    pobj->SetMember(pEnv, pEnv->CreateString("corner3y"), val);

    pArray->PushBack(Value(pobj));
}

}}} // namespace Scaleform::GFx::AS2
