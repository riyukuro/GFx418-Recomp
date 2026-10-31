# GFx418-Recomp

Scaleform GFx 4.1.18, the CRI Sofdec movie decoder and the GFx Video add-on, recovered from the MapleStory2 client
(`MapleStory2.exe`, KMS2_DEV x64). See [`NOTICE.md`](NOTICE.md) for what the code is and is not.

This is the `src/ms2/scaleform` submodule of [MS2Recomp](https://github.com/riyukuro/MS2Recomp). It does not build on
its own: MS2Recomp's cmake compiles it into the hook DLL and the full exe. The build setup is in MS2Recomp's
`README.md` and `BUILDING.md`.

## Compilers by section

The exe links these libraries prebuilt, and they were not all built with the game's compiler. A unit only byte-matches
when it is compiled with the compiler and flags of the library it came from, so each section has its own:

| Directory | Contents | Compiler | Flags |
|---|---|---|---|
| `kernel/`, `render/`, `gfx/`, `as2/`, `as3/`, `as3di/`, `d3d9/`, `ime/` | GFx core, renderer, ActionScript 2/3 VMs, D3D9 backend, IME | cl 19.16 (MSVC 14.16, VS2017 15.9), the game's own compiler | `scaleform` profile |
| `cri/` (except `sfr_cri_01`, `sfr_cri_02`) | CRI Movie 3.07 decoder | cl 15.00.30729 (VS2008 SP1), `vc9` | `vc9` toolset |
| `video/`, `cri/sfr_cri_01`, `cri/sfr_cri_02` | GFx Video add-on and its CRI glue | cl 17.00.61030 (VS2012 Update 4), `vc11` | `vc11` toolset |

Two lines in a unit's header comment select its flags and compiler. The flag sets are defined in MS2Recomp's
`cmake/ms2-unit-profiles.cmake`.

- `// MS2-FLAGS: scaleform` appends `/Ox /Ob2 /Ot /GF /Gy /GR- /Zp8 /EHs-c- /fp:precise` and `NDEBUG SF_BUILD_SHIPPING
  GFX_USE_VIDEO` to the game flags. That is the SDK's release configuration: no RTTI, no exceptions.
- `// MS2-TOOLSET: vc9` or `// MS2-TOOLSET: vc11` builds the unit with that old compiler. Its options replace the game
  flags; there is no PCH and none of the game's include directories.
  - vc9 uses `/O2 /Ob1 /Gy /GF /EHsc`, and the source must be C++03 (no `auto`, `decltype`, brace-init or variadic
    templates). `/Ob1` means one function is never inlined into another unless it is marked `inline`, because the
    library's functions came from separate objs.
  - vc9v is the vc9 cl with the vc11 options, for the parts of the Video add-on that the exe links from VS2008 objs
    (sfr_video_01/02 match about 50 more rows each with it). The source must be C++03; tools/msvc9v/compat.h defines
    away the C++11 keywords in the shared headers.
  - vc11 uses `/O2 /Gy /GF /GR- /EHs-c-`, with C++11 only as far as VS2012 goes (no alias `using`, explicit conversion
    operators or variadic templates). Functions that the exe inlines need `inline`.
- A unit with neither line (for example `gfx/sfr_gfx_10`, the game's own GFx logger) is game code and builds with
  the game's `/Od` flags.

clang-cl builds every unit, whatever its toolset. It only checks that the hook DLL links; byte matching needs the
real compilers.

## Getting the old compilers

Both go into MS2Recomp's gitignored `third_party/`, and both run under Wine on Linux. Each install script checks its
ISOs by SHA-256 before extracting anything, and checks the installed result against a manifest
(`tools/msvc9/manifest.tsv`, `tools/msvc11/manifest.tsv`).

- **vc9:** run `tools/fetch-vc9.sh <GRMWDK_EN_7600_1.ISO>` (WDK 7.1.0), or `tools/fetch-vc9.sh --download`.
- **vc11:** run `tools/fetch-vs2012.sh <VS2012.4.iso> <VS2012_WDX_ENU.iso>`, or `tools/fetch-vs2012.sh --download`
  (3.1 GB). It installs the VS2012 Update 4 compiler, the VC headers and the Windows SDK 8.0 headers.
- **Check an existing install:** run either script with `--check`.

Without them, the vc9 and vc11 units still build with clang-cl, but they can't be byte-matched.
