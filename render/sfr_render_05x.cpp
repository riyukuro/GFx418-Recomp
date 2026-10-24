// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render leftovers: the Perlin
// generator's smoothed lattice noise (Render_Perlin) and the tessellator's stroker edge sort (Render_Tessellator).
// Gap recovery of queue unit sfr_render_05.
// MS2-UNIT: sfr_render_05x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142678210-0x142678490 .text$mn
// MS2-RANGE: 0x1426978d0-0x142697d11 .text$mn

#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_tessdefs.h"
#include "ms2/scaleform/include/render/render_math2d.h"
#include "ms2/scaleform/include/render/render_tessellator.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/include/render/render_perlin.h"

namespace Scaleform { namespace Render {

// MS2-FUNCTIONAL: the exe schedules the nine lattice evaluations differently (same sums and weights)
// @0x142678210
float PerlinGenerator::SmoothNoise(int x, int y)
{
    float corners = noise(x + 1, y - 1) + noise(x - 1, y - 1) + noise(x - 1, y + 1) + noise(x + 1, y + 1);
    float sides   = noise(x + 1, y) + noise(x - 1, y) + noise(x, y - 1) + noise(x, y + 1);
    float center  = noise(x, y);
    return sides * 0.125f + corners * 0.0625f + center * 0.25f;
}

}} // namespace Scaleform::Render

// Tessellator::processStrokerEdges sorts StrokerEdges by (node1, node2). The edge type is private, so the sort is
// instantiated through a holder whose template arguments may name it.
namespace {
template<class ArrayT, class Less>
struct QuickSortSlicedInst
{
    static void (*const Fn)(ArrayT&, Scaleform::UPInt, Scaleform::UPInt, Less);
};
template<class ArrayT, class Less>
void (*const QuickSortSlicedInst<ArrayT, Less>::Fn)(ArrayT&, Scaleform::UPInt, Scaleform::UPInt, Less) =
    &Scaleform::Alg::QuickSortSliced<ArrayT, Less>;
} // namespace

// @0x1426978d0
template struct QuickSortSlicedInst<
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType, 4, 16>,
    bool (*)(const Scaleform::Render::Tessellator::StrokerEdgeType&,
             const Scaleform::Render::Tessellator::StrokerEdgeType&)>;

// MS2-PIN: ?SmoothNoise@PerlinGenerator@Render@Scaleform@@AEAAMHH@Z 0x142678210
// MS2-PIN: ??$QuickSortSliced@V?$ArrayPaged@UStrokerEdgeType@Tessellator@Render@Scaleform@@$03$0BA@@Render@Scaleform@@P6A_NAEBUStrokerEdgeType@Tessellator@23@0@Z@Alg@Scaleform@@YAXAEAV?$ArrayPaged@UStrokerEdgeType@Tessellator@Render@Scaleform@@$03$0BA@@Render@1@_K1P6A_NAEBUStrokerEdgeType@Tessellator@31@2@Z@Z 0x1426978d0
