// Recovered Scaleform 4.1.18 Render: the jpeglib (IJG jpeg-6b) glue shared by the JPEG reader units - the jpeglib
// headers in the exe's Windows configuration and the error manager that longjmps back instead of exiting.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// JpegErrorHandler is 0x178 bytes. Its ctor / dtor, JpegErrorExit and SetupJpegErr live with JPEG_ImageCommon
// (sfr_render_04n, 0x14264d350..).
#ifndef MS2_SF_RENDER_JPEGCOMMON_H
#define MS2_SF_RENDER_JPEGCOMMON_H

#include <setjmp.h>
#include "ms2/scaleform/kernel/sf_types.h"

// IJG jpeg-6b, linked as C in the exe (lib_jpeg), Windows configuration.
#include "../third_party/src/jpeg-6b/jconfig.vc"
#define JCONFIG_INCLUDED
#if defined(_BASETSD_H_)
#define XMD_H   // INT16/INT32 come from the Windows headers
#endif
extern "C" {
#include "../third_party/src/jpeg-6b/jpeglib.h"
}

namespace Scaleform { namespace Render { namespace JPEG {

// jpeglib error manager that longjmps back to the caller instead of exiting (0x178 bytes).
struct JpegErrorHandler
{
    struct jpeg_error_mgr pub;                      // +0x000
    char                  errorMessage[JMSG_LENGTH_MAX];  // +0x0a8
    jmp_buf*              psetjmp_buffer;           // +0x170, heap allocated by the ctor

    JpegErrorHandler();
    ~JpegErrorHandler();
};

// keeps jpeglib's message in errorMessage, then jumps to psetjmp_buffer
void JpegErrorExit(j_common_ptr cinfo);

// the standard error manager with JpegErrorExit as its exit routine
jpeg_error_mgr* SetupJpegErr(JpegErrorHandler* jerr);

}}} // namespace Scaleform::Render::JPEG

#endif
