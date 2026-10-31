// Recovered Scaleform 4.1.18 Render: D3D9 shaders (D3D9_ShaderDescs and D3D9_Shader sections of sfr_d3d9_01, unit
// sfr_d3d9_01d). Written from the exe; names from the SDK headers.
// The precompiled shader set of this build: 100 vertex shaders and 213 fragment shaders, each described by a static
// desc (binary, the register / shadow slot of each of the 18 uniforms, batch slots, vertex attributes). A shader
// type (the fill / blend / cxform bits a HAL asks for) maps to a desc index through generated switches. The HAL keeps
// one VertexShader / FragShader per index; ShaderInterface gathers the uniforms of a draw and uploads the dirty
// register ranges in Finish.
//
// Layouts (exe): VertexShaderDesc 0x140, FragShaderDesc 0x100, VertexShader 0x58, FragShader 0x80, SysVertexFormat
// 0x58 (vftable 0x14319e020), ShaderInterface 0x1180, ShaderManager 0x40. Desc tables: VertexShaderDesc::Descs
// 0x143a30930, FragShaderDesc::Descs 0x143a30c50, uniform names 0x143a308a0.
#ifndef MS2_SF_RENDER_D3D9_SHADER_H
#define MS2_SF_RENDER_D3D9_SHADER_H

#include <d3d9.h>
#include "ms2/scaleform/include/render/render_shader.h"
#include "ms2/scaleform/include/render/render_fillmode.h"
#include "ms2/scaleform/include/render/render_staticshader.h"

namespace Scaleform { namespace Render {

class Texture;

namespace D3D9 {

class HAL;
class Texture;

// The uniforms a shader may read; the order is that of the name table.
struct Uniform
{
    enum UniformType
    {
        SU_color,
        SU_cxadd,
        SU_cxmul,
        SU_fsize,
        SU_mask,
        SU_mvp,
        SU_offset,
        SU_paletteMap,
        SU_scolor,
        SU_scolor2,
        SU_srctex,
        SU_srctexscale,
        SU_tex,
        SU_texgen,
        SU_texscale,
        SU_threshold,
        SU_vfmuniforms,
        SU_vfuniforms,

        SU_Count,
        SU_TotalSize = 1088   // floats in the shadow store
    };

    // per-uniform flags: builtin uniforms are set by the HAL, the rest come from a user shader's matrix user data;
    // TexScale ones are given in pixels of the first texture
    enum UniformFlag
    {
        Uniform_Builtin  = 1,
        Uniform_TexScale = 2,
    };
    static const UByte UniformFlags[SU_Count];   // 0x14319df68, all zero in this build
};

// the uniform names as the D3DX constant tables know them (0x143a308a0)
extern const char* ShaderUniformNames[Uniform::SU_Count];

// one uniform of a desc (10 bytes); Location < 0 when the shader does not use it
struct UniformVar
{
    short Location;       // first constant register
    short ShadowOffset;   // first float in ShaderInterface::UniformData
    UByte ElementSize;
    short Size;           // floats
    UByte ElementCount;
    UByte BatchSize;
};

// a batched uniform: its slot in the per-instance arrays
struct BatchVar
{
    SByte Array;
    SByte Offset;
    UByte Size;
};

struct VertexAttrDesc
{
    const char* Name;
    unsigned    Attr;         // the VertexElementType usage / index it binds
    UByte       Usage;        // D3DDECLUSAGE
    UByte       UsageIndex;
};

struct FragShaderDesc
{
    // the numbering of this build (no enumerators are spelled out: the switches below take the raw values)
    enum ShaderType  { FS_None = 0 };
    enum ShaderIndex { FSI_None = 0, FSI_Count = 213 };

    int          Type;
    unsigned     Flags;
    const DWORD* pBinary;
    UniformVar   Uniforms[Uniform::SU_Count];        // +0x10
    BatchVar     BatchUniforms[Uniform::SU_Count];   // +0xc4

    static const FragShaderDesc* Descs[FSI_Count];                     // 0x143a30c50

    static const FragShaderDesc* GetDesc(ShaderType shader);           // 0x14273c230
    static ShaderIndex           GetShaderIndex(ShaderType shader);    // 0x14273e6f0
    static int                   GetShaderComboIndex(ShaderType shader);       // 0x14273c270
    static ShaderIndex           GetShaderIndexForComboIndex(unsigned index);  // 0x14273fe90
};

struct VertexShaderDesc
{
    enum ShaderType  { VS_None = 0 };
    enum ShaderIndex { VSI_None = 0, VSI_Count = 100 };

    int            Type;
    unsigned       Flags;
    const DWORD*   pBinary;
    UniformVar     Uniforms[Uniform::SU_Count];        // +0x10
    BatchVar       BatchUniforms[Uniform::SU_Count];   // +0xc4
    char           NumAttribs;                         // +0xfa
    VertexAttrDesc Attributes[4];                      // +0x100

    static const VertexShaderDesc* Descs[VSI_Count];                   // 0x143a30930

    static const VertexShaderDesc* GetDesc(ShaderType shader);         // 0x14273c250
    static ShaderIndex             GetShaderIndex(ShaderType shader);  // 0x14273f470
    static int                     GetShaderComboIndex(ShaderType shader);       // 0x14273d4b0
    static ShaderIndex             GetShaderIndexForComboIndex(unsigned index);  // 0x1427407a0
};

struct VertexShader
{
    VertexShader() : pDesc(0) { }
    ~VertexShader() { Shutdown(); }   // 0x14272e9d0

    const VertexShaderDesc*       pDesc;
    Ptr<IDirect3DVertexShader9>   pProg;                      // +0x08
    int                           Uniforms[Uniform::SU_Count];  // +0x10, constant registers from the D3DX table

    bool Init(HAL* phal, const VertexShaderDesc* pd);   // 0x142741620
    void Shutdown();                                    // 0x142741ac0
};

struct FragShader
{
    FragShader() { pDesc = 0; pProg = 0; Offset = 0; }   // 0x14272dbd0
    ~FragShader() { Shutdown(); }   // 0x14272e620

    const FragShaderDesc*         pDesc;
    Ptr<IDirect3DPixelShader9>    pProg;                      // +0x08
    UPInt                         Offset;                     // +0x10
    int                           Uniforms[Uniform::SU_Count];  // +0x18
    int                           TexParams[8];               // +0x60

    bool Init(HAL* phal, const FragShaderDesc* pd);     // 0x142741430
    void Shutdown();                                    // 0x142741a90
};

// The D3D declaration a VertexFormat gets the first time it is drawn with a vertex shader.
class SysVertexFormat : public Render::SystemVertexFormat
{
public:
    SysVertexFormat(IDirect3DDevice9* device, const VertexFormat* format, const VertexShaderDesc* vdesc);   // 0x142740f10
    virtual ~SysVertexFormat()
    {
        if (pVDecl)
            pVDecl->Release();
    }

    IDirect3DVertexDeclaration9* pVDecl;              // +0x10
    D3DVERTEXELEMENT9            VertexElements[8];   // +0x18
};

// BuildVertexArray's D3D9 builder: one D3DVERTEXELEMENT9 per attribute, laid out per stream (stream 1 carries the
// instance index).
struct D3DVertexDeclBuilder
{
    D3DVERTEXELEMENT9       Elements[8];
    WORD                    Size[2];   // +0x40, next offset in each stream
    WORD                    Count;     // +0x44
    const VertexShaderDesc* VertexDesc;  // +0x48

    D3DVertexDeclBuilder(const VertexShaderDesc* vdesc) : Count(0), VertexDesc(vdesc) { Size[0] = Size[1] = 0; }

    void Add(int, unsigned attr, int, int);
    void Finish(int)
    {
        static const D3DVERTEXELEMENT9 end = D3DDECL_END();
        Elements[Count++] = end;
    }
};

struct ShaderPair
{
    const VertexShader*     pVS;
    const VertexShaderDesc* pVDesc;
    const FragShader*       pFS;
    const FragShaderDesc*   pFDesc;
    const VertexFormat*     pVFormat;

    ShaderPair() : pVS(0), pVDesc(0), pFS(0), pFDesc(0), pVFormat(0) { }
    const ShaderPair* operator->() const { return this; }
};

class ShaderInterface : public ShaderInterfaceBase<Uniform, ShaderPair>
{
    friend class ShaderManager;

public:
    typedef const ShaderPair Shader;

    ShaderInterface(HAL* phal) : pHal(phal), pLastVS(0), pLastFS(0), pLastDecl(0) { }

    void BeginScene()
    {
        pLastVS   = 0;
        pLastDecl = 0;
        pLastFS   = 0;
    }

    const Shader& GetCurrentShaders() const { return CurShaders; }
    bool SetStaticShader(VertexShaderDesc::ShaderType vshader, FragShaderDesc::ShaderType fshader,
                         const VertexFormat* format);                                               // 0x142741850
    void SetTexture(Shader, unsigned var, Render::Texture* ptexture, ImageFillMode fm, unsigned index = 0);   // 0x142741a50
    void Finish(unsigned meshCount);                                                                // 0x1427410e0

    HAL*                          pHal;         // +0x1138
    ShaderPair                    CurShaders;   // +0x1140
    IDirect3DVertexShader9*       pLastVS;      // +0x1168
    IDirect3DPixelShader9*        pLastFS;      // +0x1170
    IDirect3DVertexDeclaration9*  pLastDecl;    // +0x1178
};

// The static shader manager of the D3D9 HAL: the StaticShaderManager part plus the device and its caps.
class ShaderManager : public StaticShaderManager<FragShaderDesc, VertexShaderDesc, Uniform, ShaderInterface, Texture>
{
public:
    typedef StaticShaderManager<FragShaderDesc, VertexShaderDesc, Uniform, ShaderInterface, Texture> Base;

    ShaderManager(Render::HAL::ProfileViews* profiler)
        : Base(profiler), InstancingSupport(false), DynamicLoopingSupport(false) {}

    bool Initialize(HAL* phal);   // 0x142741790
    void Reset();                 // 0x142741820

    void BeginScene();            // 0x1427410c0
    void EndScene();              // 0x1427410d0

    bool HasInstancingSupport() const;       // 0x142741420
    bool HasDynamicLoopingSupport() const;   // 0x142741410

    Ptr<IDirect3DDevice9>  pDevice;                 // +0x30
    bool                   InstancingSupport;       // +0x38
    bool                   DynamicLoopingSupport;   // +0x39
};

}}} // namespace Scaleform::Render::D3D9

#endif
