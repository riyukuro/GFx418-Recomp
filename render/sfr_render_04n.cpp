// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the jpeglib glue TU shared
// by the JPEG reader and writer (JPEG_ImageCommon): the longjmp error manager.
// MS2-UNIT: sfr_render_04n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14264d350-0x14264d420 .text$mn

#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/include/render/render_jpegcommon.h"

namespace Scaleform { namespace Render { namespace JPEG {

// @0x14264d350
JpegErrorHandler::JpegErrorHandler()
{
    psetjmp_buffer = (jmp_buf*)SF_MEMALIGN(sizeof(jmp_buf), 32, Stat_Default_Mem);
}

// @0x14264d390
JpegErrorHandler::~JpegErrorHandler()
{
    SF_FREE(psetjmp_buffer);
}

// @0x14264d3b0
void JpegErrorExit(j_common_ptr cinfo)
{
    JpegErrorHandler* jerr = (JpegErrorHandler*)cinfo->err;
    char              buffer[JMSG_LENGTH_MAX];

    (*cinfo->err->format_message)(cinfo, buffer);
    SFstrcpy(jerr->errorMessage, sizeof(jerr->errorMessage), buffer);
    longjmp(*jerr->psetjmp_buffer, 1);
}

// @0x14264d400
jpeg_error_mgr* SetupJpegErr(JpegErrorHandler* jerr)
{
    jpeg_error_mgr* err = jpeg_std_error(&jerr->pub);
    jerr->pub.error_exit = JpegErrorExit;
    return err;
}

}}} // namespace Scaleform::Render::JPEG
