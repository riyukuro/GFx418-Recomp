// Recovered Scaleform 4.1.18 Render: image file format ids (values from LoaderImpl::FileFormat2RenderImageFile).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_IMAGEFILEFORMAT_H
#define MS2_SF_RENDER_IMAGEFILEFORMAT_H

namespace Scaleform { namespace Render {

enum ImageFileFormat
{
    ImageFile_Unopened = 0,
    ImageFile_Unknown  = 1,
    ImageFile_JPEG     = 2,
    ImageFile_DDS      = 3,
    ImageFile_PNG      = 4,
    ImageFile_TGA      = 5,
    ImageFile_PVR      = 6,
    ImageFile_GXT      = 8,
    ImageFile_SIF      = 10
};

}} // namespace Scaleform::Render

#endif
