// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the D3D9 shader TUs
// (D3D9_ShaderDescs, D3D9_Shader): the shader type -> desc index switches of the generated shader set, the vertex
// declaration builder, the VertexShader / FragShader objects of the HAL, and the ShaderInterface uniform upload.
// Queue unit sfr_d3d9_01 is split along its original sources (sfr_d3d9_01d D3D9_ShaderDescs + D3D9_Shader).
// The switch bodies are generated from the exe's compare trees (work/sfr21/genswitch.py over swemu.py dumps).
// MS2-UNIT: sfr_d3d9_01d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14273c230-0x142741af0 .text$mn


#include <d3dx9shader.h>
#include "ms2/scaleform/include/render/d3d9_shader.h"
#include "ms2/scaleform/include/render/d3d9_hal.h"
#include "ms2/scaleform/include/render/d3d9_texture.h"

// @0x142740ff0 is RefCountBaseStatImpl<RefCountImpl, Stat_Default_Mem>'s deleting destructor (pinned below), emitted
// here for SysVertexFormat's base; @0x142741050 is SysVertexFormat's.

namespace Scaleform { namespace Render { namespace D3D9 {

// ==== D3D9_ShaderDescs ===============================================================================================

// @0x14273c230
const FragShaderDesc* FragShaderDesc::GetDesc(ShaderType shader)
{
    return Descs[GetShaderIndex(shader)];
}

// @0x14273c250
const VertexShaderDesc* VertexShaderDesc::GetDesc(ShaderType shader)
{
    return Descs[GetShaderIndex(shader)];
}

// MS2-FUNCTIONAL: generated switch; MSVC lays out the compare tree / jump tables its own way
// @0x14273c270
int FragShaderDesc::GetShaderComboIndex(ShaderType shader)
{
    int key = shader;
    switch (key)
    {
    case 2: return (int)1;
    case 33: return (int)2;
    case 34: return (int)3;
    case 17: return (int)4;
    case 18: return (int)5;
    case 49: return (int)6;
    case 50: return (int)7;
    case 65: return (int)8;
    case 66: return (int)9;
    case 97: return (int)10;
    case 98: return (int)11;
    case 81: return (int)12;
    case 82: return (int)13;
    case 113: return (int)14;
    case 114: return (int)15;
    case 129: return (int)16;
    case 130: return (int)17;
    case 161: return (int)18;
    case 162: return (int)19;
    case 145: return (int)20;
    case 146: return (int)21;
    case 177: return (int)22;
    case 178: return (int)23;
    case 16385: return (int)24;
    case 16386: return (int)25;
    case 16417: return (int)26;
    case 16418: return (int)27;
    case 16401: return (int)28;
    case 16402: return (int)29;
    case 16433: return (int)30;
    case 16434: return (int)31;
    case 9: return (int)32;
    case 10: return (int)33;
    case 41: return (int)34;
    case 42: return (int)35;
    case 25: return (int)36;
    case 26: return (int)37;
    case 57: return (int)38;
    case 58: return (int)39;
    case 73: return (int)40;
    case 74: return (int)41;
    case 105: return (int)42;
    case 106: return (int)43;
    case 89: return (int)44;
    case 90: return (int)45;
    case 121: return (int)46;
    case 122: return (int)47;
    case 137: return (int)48;
    case 138: return (int)49;
    case 169: return (int)50;
    case 170: return (int)51;
    case 153: return (int)52;
    case 154: return (int)53;
    case 185: return (int)54;
    case 186: return (int)55;
    case 16393: return (int)56;
    case 16394: return (int)57;
    case 16425: return (int)58;
    case 16426: return (int)59;
    case 16409: return (int)60;
    case 16410: return (int)61;
    case 16441: return (int)62;
    case 16442: return (int)63;
    case 3: case 5: return (int)64;
    case 4: case 6: return (int)65;
    case 35: return (int)66;
    case 36: return (int)67;
    case 19: case 21: return (int)68;
    case 20: case 22: return (int)69;
    case 51: return (int)70;
    case 52: return (int)71;
    case 67: case 69: return (int)72;
    case 68: case 70: return (int)73;
    case 99: return (int)74;
    case 100: return (int)75;
    case 83: case 85: return (int)76;
    case 84: case 86: return (int)77;
    case 115: return (int)78;
    case 116: return (int)79;
    case 131: return (int)80;
    case 132: return (int)81;
    case 163: return (int)82;
    case 164: return (int)83;
    case 147: return (int)84;
    case 148: return (int)85;
    case 179: return (int)86;
    case 180: return (int)87;
    case 16387: return (int)88;
    case 16388: return (int)89;
    case 16419: return (int)90;
    case 16420: return (int)91;
    case 16403: return (int)92;
    case 16404: return (int)93;
    case 16435: return (int)94;
    case 16436: return (int)95;
    case 11: case 13: return (int)96;
    case 12: case 14: return (int)97;
    case 43: return (int)98;
    case 44: return (int)99;
    case 27: case 29: return (int)100;
    case 28: case 30: return (int)101;
    case 59: return (int)102;
    case 60: return (int)103;
    case 75: case 77: return (int)104;
    case 76: case 78: return (int)105;
    case 107: return (int)106;
    case 108: return (int)107;
    case 91: case 93: return (int)108;
    case 92: case 94: return (int)109;
    case 123: return (int)110;
    case 124: return (int)111;
    case 139: return (int)112;
    case 140: return (int)113;
    case 171: return (int)114;
    case 172: return (int)115;
    case 155: return (int)116;
    case 156: return (int)117;
    case 187: return (int)118;
    case 188: return (int)119;
    case 16395: return (int)120;
    case 16396: return (int)121;
    case 16427: return (int)122;
    case 16428: return (int)123;
    case 16411: return (int)124;
    case 16412: return (int)125;
    case 16443: return (int)126;
    case 16444: return (int)127;
    case 37: return (int)128;
    case 38: return (int)129;
    case 53: return (int)130;
    case 54: return (int)131;
    case 101: return (int)132;
    case 102: return (int)133;
    case 117: return (int)134;
    case 118: return (int)135;
    case 133: return (int)136;
    case 134: return (int)137;
    case 165: return (int)138;
    case 166: return (int)139;
    case 149: return (int)140;
    case 150: return (int)141;
    case 181: return (int)142;
    case 182: return (int)143;
    case 16389: return (int)144;
    case 16390: return (int)145;
    case 16421: return (int)146;
    case 16422: return (int)147;
    case 16405: return (int)148;
    case 16406: return (int)149;
    case 16437: return (int)150;
    case 16438: return (int)151;
    case 45: return (int)152;
    case 46: return (int)153;
    case 61: return (int)154;
    case 62: return (int)155;
    case 109: return (int)156;
    case 110: return (int)157;
    case 125: return (int)158;
    case 126: return (int)159;
    case 141: return (int)160;
    case 142: return (int)161;
    case 173: return (int)162;
    case 174: return (int)163;
    case 157: return (int)164;
    case 158: return (int)165;
    case 189: return (int)166;
    case 190: return (int)167;
    case 16397: return (int)168;
    case 16398: return (int)169;
    case 16429: return (int)170;
    case 16430: return (int)171;
    case 16413: return (int)172;
    case 16414: return (int)173;
    case 16445: return (int)174;
    case 16446: return (int)175;
    case 32771: return (int)176;
    case 36867: return (int)177;
    case 36868: return (int)178;
    case 33795: return (int)179;
    case 33796: return (int)180;
    case 33811: return (int)181;
    case 33812: return (int)182;
    case 32779: return (int)183;
    case 36875: return (int)184;
    case 36876: return (int)185;
    case 33803: return (int)186;
    case 33804: return (int)187;
    case 33819: return (int)188;
    case 33820: return (int)189;
    case 32773: case 32775: return (int)190;
    case 36869: case 36871: return (int)191;
    case 36870: case 36872: return (int)192;
    case 33797: case 33799: return (int)193;
    case 33798: case 33800: return (int)194;
    case 33813: case 33815: return (int)195;
    case 33814: case 33816: return (int)196;
    case 32781: case 32783: return (int)197;
    case 36877: case 36879: return (int)198;
    case 36878: case 36880: return (int)199;
    case 33805: case 33807: return (int)200;
    case 33806: case 33808: return (int)201;
    case 33821: case 33823: return (int)202;
    case 33822: case 33824: return (int)203;
    case 40965: return (int)204;
    case 40966: return (int)205;
    case 40997: return (int)206;
    case 40998: return (int)207;
    case 40981: return (int)208;
    case 40982: return (int)209;
    case 41013: return (int)210;
    case 41014: return (int)211;
    case 41221: return (int)212;
    case 41222: return (int)213;
    case 41253: return (int)214;
    case 41254: return (int)215;
    case 41237: return (int)216;
    case 41238: return (int)217;
    case 41269: return (int)218;
    case 41270: return (int)219;
    case 40973: return (int)220;
    case 40974: return (int)221;
    case 41005: return (int)222;
    case 41006: return (int)223;
    case 40989: return (int)224;
    case 40990: return (int)225;
    case 41021: return (int)226;
    case 41022: return (int)227;
    case 41229: return (int)228;
    case 41230: return (int)229;
    case 41261: return (int)230;
    case 41262: return (int)231;
    case 41245: return (int)232;
    case 41246: return (int)233;
    case 41277: return (int)234;
    case 41278: return (int)235;
    case 40967: case 40969: return (int)236;
    case 40968: case 40970: return (int)237;
    case 40999: return (int)238;
    case 41000: return (int)239;
    case 40983: case 40985: return (int)240;
    case 40984: case 40986: return (int)241;
    case 41015: return (int)242;
    case 41016: return (int)243;
    case 41223: case 41225: return (int)244;
    case 41224: case 41226: return (int)245;
    case 41255: return (int)246;
    case 41256: return (int)247;
    case 41239: case 41241: return (int)248;
    case 41240: case 41242: return (int)249;
    case 41271: return (int)250;
    case 41272: return (int)251;
    case 40975: case 40977: return (int)252;
    case 40976: case 40978: return (int)253;
    case 41007: return (int)254;
    case 41008: return (int)255;
    case 40991: case 40993: return (int)256;
    case 40992: case 40994: return (int)257;
    case 41023: return (int)258;
    case 41024: return (int)259;
    case 41231: case 41233: return (int)260;
    case 41232: case 41234: return (int)261;
    case 41263: return (int)262;
    case 41264: return (int)263;
    case 41247: case 41249: return (int)264;
    case 41248: case 41250: return (int)265;
    case 41279: return (int)266;
    case 41280: return (int)267;
    case 41001: return (int)268;
    case 41002: return (int)269;
    case 41017: return (int)270;
    case 41018: return (int)271;
    case 41257: return (int)272;
    case 41258: return (int)273;
    case 41273: return (int)274;
    case 41274: return (int)275;
    case 41009: return (int)276;
    case 41010: return (int)277;
    case 41025: return (int)278;
    case 41026: return (int)279;
    case 41265: return (int)280;
    case 41266: return (int)281;
    case 41281: return (int)282;
    case 41282: return (int)283;
    case 41479: return (int)284;
    case 41480: return (int)285;
    case 41511: return (int)286;
    case 41512: return (int)287;
    case 41545: return (int)288;
    case 41546: return (int)289;
    case 42057: return (int)290;
    case 42058: return (int)291;
    case 42571: return (int)292;
    case 42572: return (int)293;
    case 42827: return (int)294;
    case 42828: return (int)295;
    case 44619: return (int)296;
    case 44620: return (int)297;
    case 44875: return (int)298;
    case 44876: return (int)299;
    case 46667: return (int)300;
    case 46668: return (int)301;
    case 51787: return (int)302;
    case 51788: return (int)303;
    case 52043: return (int)304;
    case 52044: return (int)305;
    case 59979: return (int)306;
    case 59980: return (int)307;
    case 60235: return (int)308;
    case 60236: return (int)309;
    case 44107: return (int)310;
    case 44108: return (int)311;
    case 75341: return (int)312;
    case 75469: return (int)313;
    case 76365: return (int)320;
    case 76493: return (int)321;
    case 79437: return (int)316;
    case 79565: return (int)317;
    case 80461: return (int)324;
    case 80589: return (int)325;
    case 91725: return (int)314;
    case 91853: return (int)315;
    case 92749: return (int)322;
    case 92877: return (int)323;
    case 95821: return (int)318;
    case 95949: return (int)319;
    case 96845: return (int)326;
    case 96973: return (int)327;
    case 108111: return (int)328;
    case 108113: return (int)329;
    case 108115: return (int)330;
    case 108117: return (int)331;
    case 108119: return (int)336;
    case 108121: return (int)335;
    case 108125: return (int)334;
    case 108133: return (int)333;
    case 108149: return (int)332;
    case 108182: return (int)337;
    case 108184: return (int)342;
    case 108186: return (int)341;
    case 108190: return (int)340;
    case 108198: return (int)339;
    case 108214: return (int)338;
    default: return (int)0;
    }
}

// MS2-FUNCTIONAL: generated switch; MSVC lays out the compare tree / jump tables its own way
// @0x14273d4b0
int VertexShaderDesc::GetShaderComboIndex(ShaderType shader)
{
    int key = shader;
    switch (key)
    {
    case 2: return (int)1;
    case 33: return (int)2;
    case 34: return (int)3;
    case 17: return (int)4;
    case 18: return (int)5;
    case 49: return (int)6;
    case 50: return (int)7;
    case 65: return (int)8;
    case 66: return (int)9;
    case 97: return (int)10;
    case 98: return (int)11;
    case 81: return (int)12;
    case 82: return (int)13;
    case 113: return (int)14;
    case 114: return (int)15;
    case 129: return (int)16;
    case 130: return (int)17;
    case 161: return (int)18;
    case 162: return (int)19;
    case 145: return (int)20;
    case 146: return (int)21;
    case 177: return (int)22;
    case 178: return (int)23;
    case 16385: return (int)24;
    case 16386: return (int)25;
    case 16417: return (int)26;
    case 16418: return (int)27;
    case 16401: return (int)28;
    case 16402: return (int)29;
    case 16433: return (int)30;
    case 16434: return (int)31;
    case 9: return (int)32;
    case 10: return (int)33;
    case 41: return (int)34;
    case 42: return (int)35;
    case 25: return (int)36;
    case 26: return (int)37;
    case 57: return (int)38;
    case 58: return (int)39;
    case 73: return (int)40;
    case 74: return (int)41;
    case 105: return (int)42;
    case 106: return (int)43;
    case 89: return (int)44;
    case 90: return (int)45;
    case 121: return (int)46;
    case 122: return (int)47;
    case 137: return (int)48;
    case 138: return (int)49;
    case 169: return (int)50;
    case 170: return (int)51;
    case 153: return (int)52;
    case 154: return (int)53;
    case 185: return (int)54;
    case 186: return (int)55;
    case 16393: return (int)56;
    case 16394: return (int)57;
    case 16425: return (int)58;
    case 16426: return (int)59;
    case 16409: return (int)60;
    case 16410: return (int)61;
    case 16441: return (int)62;
    case 16442: return (int)63;
    case 3: case 5: return (int)64;
    case 4: case 6: return (int)65;
    case 35: return (int)66;
    case 36: return (int)67;
    case 19: case 21: return (int)68;
    case 20: case 22: return (int)69;
    case 51: return (int)70;
    case 52: return (int)71;
    case 67: case 69: return (int)72;
    case 68: case 70: return (int)73;
    case 99: return (int)74;
    case 100: return (int)75;
    case 83: case 85: return (int)76;
    case 84: case 86: return (int)77;
    case 115: return (int)78;
    case 116: return (int)79;
    case 131: return (int)80;
    case 132: return (int)81;
    case 163: return (int)82;
    case 164: return (int)83;
    case 147: return (int)84;
    case 148: return (int)85;
    case 179: return (int)86;
    case 180: return (int)87;
    case 16387: return (int)88;
    case 16388: return (int)89;
    case 16419: return (int)90;
    case 16420: return (int)91;
    case 16403: return (int)92;
    case 16404: return (int)93;
    case 16435: return (int)94;
    case 16436: return (int)95;
    case 11: case 13: return (int)96;
    case 12: case 14: return (int)97;
    case 43: return (int)98;
    case 44: return (int)99;
    case 27: case 29: return (int)100;
    case 28: case 30: return (int)101;
    case 59: return (int)102;
    case 60: return (int)103;
    case 75: case 77: return (int)104;
    case 76: case 78: return (int)105;
    case 107: return (int)106;
    case 108: return (int)107;
    case 91: case 93: return (int)108;
    case 92: case 94: return (int)109;
    case 123: return (int)110;
    case 124: return (int)111;
    case 139: return (int)112;
    case 140: return (int)113;
    case 171: return (int)114;
    case 172: return (int)115;
    case 155: return (int)116;
    case 156: return (int)117;
    case 187: return (int)118;
    case 188: return (int)119;
    case 16395: return (int)120;
    case 16396: return (int)121;
    case 16427: return (int)122;
    case 16428: return (int)123;
    case 16411: return (int)124;
    case 16412: return (int)125;
    case 16443: return (int)126;
    case 16444: return (int)127;
    case 37: return (int)128;
    case 38: return (int)129;
    case 53: return (int)130;
    case 54: return (int)131;
    case 101: return (int)132;
    case 102: return (int)133;
    case 117: return (int)134;
    case 118: return (int)135;
    case 133: return (int)136;
    case 134: return (int)137;
    case 165: return (int)138;
    case 166: return (int)139;
    case 149: return (int)140;
    case 150: return (int)141;
    case 181: return (int)142;
    case 182: return (int)143;
    case 16389: return (int)144;
    case 16390: return (int)145;
    case 16421: return (int)146;
    case 16422: return (int)147;
    case 16405: return (int)148;
    case 16406: return (int)149;
    case 16437: return (int)150;
    case 16438: return (int)151;
    case 45: return (int)152;
    case 46: return (int)153;
    case 61: return (int)154;
    case 62: return (int)155;
    case 109: return (int)156;
    case 110: return (int)157;
    case 125: return (int)158;
    case 126: return (int)159;
    case 141: return (int)160;
    case 142: return (int)161;
    case 173: return (int)162;
    case 174: return (int)163;
    case 157: return (int)164;
    case 158: return (int)165;
    case 189: return (int)166;
    case 190: return (int)167;
    case 16397: return (int)168;
    case 16398: return (int)169;
    case 16429: return (int)170;
    case 16430: return (int)171;
    case 16413: return (int)172;
    case 16414: return (int)173;
    case 16445: return (int)174;
    case 16446: return (int)175;
    case 32771: return (int)176;
    case 36867: return (int)177;
    case 36868: return (int)178;
    case 33795: return (int)179;
    case 33796: return (int)180;
    case 33811: return (int)181;
    case 33812: return (int)182;
    case 32779: return (int)183;
    case 36875: return (int)184;
    case 36876: return (int)185;
    case 33803: return (int)186;
    case 33804: return (int)187;
    case 33819: return (int)188;
    case 33820: return (int)189;
    case 32773: case 32775: return (int)190;
    case 36869: case 36871: return (int)191;
    case 36870: case 36872: return (int)192;
    case 33797: case 33799: return (int)193;
    case 33798: case 33800: return (int)194;
    case 33813: case 33815: return (int)195;
    case 33814: case 33816: return (int)196;
    case 32781: case 32783: return (int)197;
    case 36877: case 36879: return (int)198;
    case 36878: case 36880: return (int)199;
    case 33805: case 33807: return (int)200;
    case 33806: case 33808: return (int)201;
    case 33821: case 33823: return (int)202;
    case 33822: case 33824: return (int)203;
    case 40965: return (int)204;
    case 40966: return (int)205;
    case 40997: return (int)206;
    case 40998: return (int)207;
    case 40981: return (int)208;
    case 40982: return (int)209;
    case 41013: return (int)210;
    case 41014: return (int)211;
    case 41221: return (int)212;
    case 41222: return (int)213;
    case 41253: return (int)214;
    case 41254: return (int)215;
    case 41237: return (int)216;
    case 41238: return (int)217;
    case 41269: return (int)218;
    case 41270: return (int)219;
    case 40973: return (int)220;
    case 40974: return (int)221;
    case 41005: return (int)222;
    case 41006: return (int)223;
    case 40989: return (int)224;
    case 40990: return (int)225;
    case 41021: return (int)226;
    case 41022: return (int)227;
    case 41229: return (int)228;
    case 41230: return (int)229;
    case 41261: return (int)230;
    case 41262: return (int)231;
    case 41245: return (int)232;
    case 41246: return (int)233;
    case 41277: return (int)234;
    case 41278: return (int)235;
    case 40967: case 40969: return (int)236;
    case 40968: case 40970: return (int)237;
    case 40999: return (int)238;
    case 41000: return (int)239;
    case 40983: case 40985: return (int)240;
    case 40984: case 40986: return (int)241;
    case 41015: return (int)242;
    case 41016: return (int)243;
    case 41223: case 41225: return (int)244;
    case 41224: case 41226: return (int)245;
    case 41255: return (int)246;
    case 41256: return (int)247;
    case 41239: case 41241: return (int)248;
    case 41240: case 41242: return (int)249;
    case 41271: return (int)250;
    case 41272: return (int)251;
    case 40975: case 40977: return (int)252;
    case 40976: case 40978: return (int)253;
    case 41007: return (int)254;
    case 41008: return (int)255;
    case 40991: case 40993: return (int)256;
    case 40992: case 40994: return (int)257;
    case 41023: return (int)258;
    case 41024: return (int)259;
    case 41231: case 41233: return (int)260;
    case 41232: case 41234: return (int)261;
    case 41263: return (int)262;
    case 41264: return (int)263;
    case 41247: case 41249: return (int)264;
    case 41248: case 41250: return (int)265;
    case 41279: return (int)266;
    case 41280: return (int)267;
    case 41001: return (int)268;
    case 41002: return (int)269;
    case 41017: return (int)270;
    case 41018: return (int)271;
    case 41257: return (int)272;
    case 41258: return (int)273;
    case 41273: return (int)274;
    case 41274: return (int)275;
    case 41009: return (int)276;
    case 41010: return (int)277;
    case 41025: return (int)278;
    case 41026: return (int)279;
    case 41265: return (int)280;
    case 41266: return (int)281;
    case 41281: return (int)282;
    case 41282: return (int)283;
    case 41479: return (int)284;
    case 41480: return (int)285;
    case 41511: return (int)286;
    case 41512: return (int)287;
    case 41545: return (int)288;
    case 41546: return (int)289;
    case 42057: return (int)290;
    case 42058: return (int)291;
    case 42571: return (int)292;
    case 42572: return (int)293;
    case 42827: return (int)294;
    case 42828: return (int)295;
    case 44619: return (int)296;
    case 44620: return (int)297;
    case 44875: return (int)298;
    case 44876: return (int)299;
    case 46667: return (int)300;
    case 46668: return (int)301;
    case 51787: return (int)302;
    case 51788: return (int)303;
    case 52043: return (int)304;
    case 52044: return (int)305;
    case 59979: return (int)306;
    case 59980: return (int)307;
    case 60235: return (int)308;
    case 60236: return (int)309;
    case 44107: return (int)310;
    case 44108: return (int)311;
    case 75341: return (int)312;
    case 75469: return (int)313;
    case 76365: return (int)320;
    case 76493: return (int)321;
    case 79437: return (int)316;
    case 79565: return (int)317;
    case 80461: return (int)324;
    case 80589: return (int)325;
    case 91725: return (int)314;
    case 91853: return (int)315;
    case 92749: return (int)322;
    case 92877: return (int)323;
    case 95821: return (int)318;
    case 95949: return (int)319;
    case 96845: return (int)326;
    case 96973: return (int)327;
    case 108111: return (int)328;
    case 108113: return (int)329;
    case 108115: return (int)330;
    case 108117: return (int)331;
    case 108119: return (int)336;
    case 108121: return (int)335;
    case 108125: return (int)334;
    case 108133: return (int)333;
    case 108149: return (int)332;
    case 108182: return (int)337;
    case 108184: return (int)342;
    case 108186: return (int)341;
    case 108190: return (int)340;
    case 108198: return (int)339;
    case 108214: return (int)338;
    default: return (int)0;
    }
}

// MS2-FUNCTIONAL: generated switch; MSVC lays out the compare tree / jump tables its own way
// @0x14273e6f0
FragShaderDesc::ShaderIndex FragShaderDesc::GetShaderIndex(ShaderType shader)
{
    int key = shader;
    switch (key)
    {
    case 1: case 9: case 33795: case 33803: return (ShaderIndex)1;
    case 2: case 10: case 33796: case 33804: return (ShaderIndex)2;
    case 33: case 41: return (ShaderIndex)3;
    case 34: case 42: return (ShaderIndex)4;
    case 17: case 25: case 33811: case 33819: return (ShaderIndex)5;
    case 18: case 26: case 33812: case 33820: return (ShaderIndex)6;
    case 49: case 57: return (ShaderIndex)7;
    case 50: case 58: return (ShaderIndex)8;
    case 65: case 73: return (ShaderIndex)9;
    case 66: case 74: return (ShaderIndex)10;
    case 97: case 105: return (ShaderIndex)11;
    case 98: case 106: return (ShaderIndex)12;
    case 81: case 89: return (ShaderIndex)13;
    case 82: case 90: return (ShaderIndex)14;
    case 113: case 121: return (ShaderIndex)15;
    case 114: case 122: return (ShaderIndex)16;
    case 129: case 137: return (ShaderIndex)17;
    case 130: case 138: return (ShaderIndex)18;
    case 161: case 169: return (ShaderIndex)19;
    case 162: case 170: return (ShaderIndex)20;
    case 145: case 153: return (ShaderIndex)21;
    case 146: case 154: return (ShaderIndex)22;
    case 177: case 185: return (ShaderIndex)23;
    case 178: case 186: return (ShaderIndex)24;
    case 16385: case 16393: return (ShaderIndex)25;
    case 16386: case 16394: return (ShaderIndex)26;
    case 16417: case 16425: return (ShaderIndex)27;
    case 16418: case 16426: return (ShaderIndex)28;
    case 16401: case 16409: return (ShaderIndex)29;
    case 16402: case 16410: return (ShaderIndex)30;
    case 16433: case 16441: return (ShaderIndex)31;
    case 16434: case 16442: return (ShaderIndex)32;
    case 3: case 11: case 33797: case 33805: return (ShaderIndex)33;
    case 4: case 12: case 33798: case 33806: return (ShaderIndex)34;
    case 35: case 43: return (ShaderIndex)35;
    case 36: case 44: return (ShaderIndex)36;
    case 19: case 27: case 33813: case 33821: return (ShaderIndex)37;
    case 20: case 28: case 33814: case 33822: return (ShaderIndex)38;
    case 51: case 59: return (ShaderIndex)39;
    case 52: case 60: return (ShaderIndex)40;
    case 67: case 75: return (ShaderIndex)41;
    case 68: case 76: return (ShaderIndex)42;
    case 99: case 107: return (ShaderIndex)43;
    case 100: case 108: return (ShaderIndex)44;
    case 83: case 91: return (ShaderIndex)45;
    case 84: case 92: return (ShaderIndex)46;
    case 115: case 123: return (ShaderIndex)47;
    case 116: case 124: return (ShaderIndex)48;
    case 131: case 139: return (ShaderIndex)49;
    case 132: case 140: return (ShaderIndex)50;
    case 163: case 171: return (ShaderIndex)51;
    case 164: case 172: return (ShaderIndex)52;
    case 147: case 155: return (ShaderIndex)53;
    case 148: case 156: return (ShaderIndex)54;
    case 179: case 187: return (ShaderIndex)55;
    case 180: case 188: return (ShaderIndex)56;
    case 16387: case 16395: return (ShaderIndex)57;
    case 16388: case 16396: return (ShaderIndex)58;
    case 16419: case 16427: return (ShaderIndex)59;
    case 16420: case 16428: return (ShaderIndex)60;
    case 16403: case 16411: return (ShaderIndex)61;
    case 16404: case 16412: return (ShaderIndex)62;
    case 16435: case 16443: return (ShaderIndex)63;
    case 16436: case 16444: return (ShaderIndex)64;
    case 5: case 13: case 33799: case 33807: return (ShaderIndex)65;
    case 6: case 14: case 33800: case 33808: return (ShaderIndex)66;
    case 37: case 45: return (ShaderIndex)67;
    case 38: case 46: return (ShaderIndex)68;
    case 21: case 29: case 33815: case 33823: return (ShaderIndex)69;
    case 22: case 30: case 33816: case 33824: return (ShaderIndex)70;
    case 53: case 61: return (ShaderIndex)71;
    case 54: case 62: return (ShaderIndex)72;
    case 69: case 77: return (ShaderIndex)73;
    case 70: case 78: return (ShaderIndex)74;
    case 101: case 109: return (ShaderIndex)75;
    case 102: case 110: return (ShaderIndex)76;
    case 85: case 93: return (ShaderIndex)77;
    case 86: case 94: return (ShaderIndex)78;
    case 117: case 125: return (ShaderIndex)79;
    case 118: case 126: return (ShaderIndex)80;
    case 133: case 141: return (ShaderIndex)81;
    case 134: case 142: return (ShaderIndex)82;
    case 165: case 173: return (ShaderIndex)83;
    case 166: case 174: return (ShaderIndex)84;
    case 149: case 157: return (ShaderIndex)85;
    case 150: case 158: return (ShaderIndex)86;
    case 181: case 189: return (ShaderIndex)87;
    case 182: case 190: return (ShaderIndex)88;
    case 16389: case 16397: return (ShaderIndex)89;
    case 16390: case 16398: return (ShaderIndex)90;
    case 16421: case 16429: return (ShaderIndex)91;
    case 16422: case 16430: return (ShaderIndex)92;
    case 16405: case 16413: return (ShaderIndex)93;
    case 16406: case 16414: return (ShaderIndex)94;
    case 16437: case 16445: return (ShaderIndex)95;
    case 16438: case 16446: return (ShaderIndex)96;
    case 32771: case 32779: return (ShaderIndex)97;
    case 36867: case 36875: return (ShaderIndex)98;
    case 36868: case 36876: return (ShaderIndex)99;
    case 32773: case 32781: return (ShaderIndex)100;
    case 36869: case 36877: return (ShaderIndex)101;
    case 36870: case 36878: return (ShaderIndex)102;
    case 32775: case 32783: return (ShaderIndex)103;
    case 36871: case 36879: return (ShaderIndex)104;
    case 36872: case 36880: return (ShaderIndex)105;
    case 40965: case 40973: return (ShaderIndex)106;
    case 40966: case 40974: return (ShaderIndex)107;
    case 40997: case 41005: return (ShaderIndex)108;
    case 40998: case 41006: return (ShaderIndex)109;
    case 40981: case 40989: return (ShaderIndex)110;
    case 40982: case 40990: return (ShaderIndex)111;
    case 41013: case 41021: return (ShaderIndex)112;
    case 41014: case 41022: return (ShaderIndex)113;
    case 41221: case 41229: return (ShaderIndex)114;
    case 41222: case 41230: return (ShaderIndex)115;
    case 41253: case 41261: return (ShaderIndex)116;
    case 41254: case 41262: return (ShaderIndex)117;
    case 41237: case 41245: return (ShaderIndex)118;
    case 41238: case 41246: return (ShaderIndex)119;
    case 41269: case 41277: return (ShaderIndex)120;
    case 41270: case 41278: return (ShaderIndex)121;
    case 40967: case 40975: return (ShaderIndex)122;
    case 40968: case 40976: return (ShaderIndex)123;
    case 40999: case 41007: return (ShaderIndex)124;
    case 41000: case 41008: return (ShaderIndex)125;
    case 40983: case 40991: return (ShaderIndex)126;
    case 40984: case 40992: return (ShaderIndex)127;
    case 41015: case 41023: return (ShaderIndex)128;
    case 41016: case 41024: return (ShaderIndex)129;
    case 41223: case 41231: return (ShaderIndex)130;
    case 41224: case 41232: return (ShaderIndex)131;
    case 41255: case 41263: return (ShaderIndex)132;
    case 41256: case 41264: return (ShaderIndex)133;
    case 41239: case 41247: return (ShaderIndex)134;
    case 41240: case 41248: return (ShaderIndex)135;
    case 41271: case 41279: return (ShaderIndex)136;
    case 41272: case 41280: return (ShaderIndex)137;
    case 40969: case 40977: return (ShaderIndex)138;
    case 40970: case 40978: return (ShaderIndex)139;
    case 41001: case 41009: return (ShaderIndex)140;
    case 41002: case 41010: return (ShaderIndex)141;
    case 40985: case 40993: return (ShaderIndex)142;
    case 40986: case 40994: return (ShaderIndex)143;
    case 41017: case 41025: return (ShaderIndex)144;
    case 41018: case 41026: return (ShaderIndex)145;
    case 41225: case 41233: return (ShaderIndex)146;
    case 41226: case 41234: return (ShaderIndex)147;
    case 41257: case 41265: return (ShaderIndex)148;
    case 41258: case 41266: return (ShaderIndex)149;
    case 41241: case 41249: return (ShaderIndex)150;
    case 41242: case 41250: return (ShaderIndex)151;
    case 41273: case 41281: return (ShaderIndex)152;
    case 41274: case 41282: return (ShaderIndex)153;
    case 41479: return (ShaderIndex)154;
    case 41480: return (ShaderIndex)155;
    case 41511: return (ShaderIndex)156;
    case 41512: return (ShaderIndex)157;
    case 41545: return (ShaderIndex)158;
    case 41546: return (ShaderIndex)159;
    case 42057: return (ShaderIndex)160;
    case 42058: return (ShaderIndex)161;
    case 42571: return (ShaderIndex)162;
    case 42572: return (ShaderIndex)163;
    case 42827: return (ShaderIndex)164;
    case 42828: return (ShaderIndex)165;
    case 44619: return (ShaderIndex)166;
    case 44620: return (ShaderIndex)167;
    case 44875: return (ShaderIndex)168;
    case 44876: return (ShaderIndex)169;
    case 46667: return (ShaderIndex)170;
    case 46668: return (ShaderIndex)171;
    case 51787: return (ShaderIndex)172;
    case 51788: return (ShaderIndex)173;
    case 52043: return (ShaderIndex)174;
    case 52044: return (ShaderIndex)175;
    case 59979: return (ShaderIndex)176;
    case 59980: return (ShaderIndex)177;
    case 60235: return (ShaderIndex)178;
    case 60236: return (ShaderIndex)179;
    case 44107: return (ShaderIndex)180;
    case 44108: return (ShaderIndex)181;
    case 75341: return (ShaderIndex)182;
    case 75469: return (ShaderIndex)183;
    case 76365: return (ShaderIndex)190;
    case 76493: return (ShaderIndex)191;
    case 79437: return (ShaderIndex)186;
    case 79565: return (ShaderIndex)187;
    case 80461: return (ShaderIndex)194;
    case 80589: return (ShaderIndex)195;
    case 91725: return (ShaderIndex)184;
    case 91853: return (ShaderIndex)185;
    case 92749: return (ShaderIndex)192;
    case 92877: return (ShaderIndex)193;
    case 95821: return (ShaderIndex)188;
    case 95949: return (ShaderIndex)189;
    case 96845: return (ShaderIndex)196;
    case 96973: return (ShaderIndex)197;
    case 108111: return (ShaderIndex)198;
    case 108113: return (ShaderIndex)199;
    case 108115: return (ShaderIndex)200;
    case 108117: return (ShaderIndex)201;
    case 108119: return (ShaderIndex)206;
    case 108121: return (ShaderIndex)205;
    case 108125: return (ShaderIndex)204;
    case 108133: return (ShaderIndex)203;
    case 108149: return (ShaderIndex)202;
    case 108182: return (ShaderIndex)207;
    case 108184: return (ShaderIndex)212;
    case 108186: return (ShaderIndex)211;
    case 108190: return (ShaderIndex)210;
    case 108198: return (ShaderIndex)209;
    case 108214: return (ShaderIndex)208;
    default: return (ShaderIndex)0;
    }
}

// MS2-FUNCTIONAL: generated switch; MSVC lays out the compare tree / jump tables its own way
// @0x14273f470
VertexShaderDesc::ShaderIndex VertexShaderDesc::GetShaderIndex(ShaderType shader)
{
    int key = shader;
    switch (key)
    {
    case 1: case 2: case 40965: case 40966: case 41221: case 41222: case 41479: case 41480: return (ShaderIndex)1;
    case 33: case 34: case 40997: case 40998: case 41253: case 41254: case 41511: case 41512: return (ShaderIndex)2;
    case 17: case 18: case 40981: case 40982: case 41237: case 41238: return (ShaderIndex)3;
    case 49: case 50: case 41013: case 41014: case 41269: case 41270: return (ShaderIndex)4;
    case 65: case 66: return (ShaderIndex)5;
    case 97: case 98: return (ShaderIndex)6;
    case 81: case 82: return (ShaderIndex)7;
    case 113: case 114: return (ShaderIndex)8;
    case 129: case 130: case 161: case 162: return (ShaderIndex)9;
    case 145: case 146: case 177: case 178: return (ShaderIndex)10;
    case 16385: case 16386: case 16417: case 16418: return (ShaderIndex)11;
    case 16401: case 16402: case 16433: case 16434: return (ShaderIndex)12;
    case 9: case 10: case 40973: case 40974: case 41229: case 41230: return (ShaderIndex)13;
    case 41: case 42: case 41005: case 41006: case 41261: case 41262: return (ShaderIndex)14;
    case 25: case 26: case 40989: case 40990: case 41245: case 41246: return (ShaderIndex)15;
    case 57: case 58: case 41021: case 41022: case 41277: case 41278: return (ShaderIndex)16;
    case 73: case 74: return (ShaderIndex)17;
    case 105: case 106: return (ShaderIndex)18;
    case 89: case 90: return (ShaderIndex)19;
    case 121: case 122: return (ShaderIndex)20;
    case 137: case 138: case 169: case 170: return (ShaderIndex)21;
    case 153: case 154: case 185: case 186: return (ShaderIndex)22;
    case 16393: case 16394: case 16425: case 16426: return (ShaderIndex)23;
    case 16409: case 16410: case 16441: case 16442: return (ShaderIndex)24;
    case 3: case 4: case 40967: case 40968: case 41223: case 41224: return (ShaderIndex)25;
    case 35: case 36: case 40999: case 41000: case 41255: case 41256: return (ShaderIndex)26;
    case 19: case 20: case 40983: case 40984: case 41239: case 41240: return (ShaderIndex)27;
    case 51: case 52: case 41015: case 41016: case 41271: case 41272: return (ShaderIndex)28;
    case 67: case 68: return (ShaderIndex)29;
    case 99: case 100: return (ShaderIndex)30;
    case 83: case 84: return (ShaderIndex)31;
    case 115: case 116: return (ShaderIndex)32;
    case 131: case 132: case 163: case 164: return (ShaderIndex)33;
    case 147: case 148: case 179: case 180: return (ShaderIndex)34;
    case 16387: case 16388: case 16419: case 16420: return (ShaderIndex)35;
    case 16403: case 16404: case 16435: case 16436: return (ShaderIndex)36;
    case 11: case 12: case 40975: case 40976: case 41231: case 41232: return (ShaderIndex)37;
    case 43: case 44: case 41007: case 41008: case 41263: case 41264: return (ShaderIndex)38;
    case 27: case 28: case 40991: case 40992: case 41247: case 41248: return (ShaderIndex)39;
    case 59: case 60: case 41023: case 41024: case 41279: case 41280: return (ShaderIndex)40;
    case 75: case 76: return (ShaderIndex)41;
    case 107: case 108: return (ShaderIndex)42;
    case 91: case 92: return (ShaderIndex)43;
    case 123: case 124: return (ShaderIndex)44;
    case 139: case 140: case 171: case 172: return (ShaderIndex)45;
    case 155: case 156: case 187: case 188: return (ShaderIndex)46;
    case 16395: case 16396: case 16427: case 16428: return (ShaderIndex)47;
    case 16411: case 16412: case 16443: case 16444: return (ShaderIndex)48;
    case 5: case 6: case 40969: case 40970: case 41225: case 41226: return (ShaderIndex)49;
    case 37: case 38: case 41001: case 41002: case 41257: case 41258: return (ShaderIndex)50;
    case 21: case 22: case 40985: case 40986: case 41241: case 41242: return (ShaderIndex)51;
    case 53: case 54: case 41017: case 41018: case 41273: case 41274: return (ShaderIndex)52;
    case 69: case 70: return (ShaderIndex)53;
    case 101: case 102: return (ShaderIndex)54;
    case 85: case 86: return (ShaderIndex)55;
    case 117: case 118: return (ShaderIndex)56;
    case 133: case 134: case 165: case 166: return (ShaderIndex)57;
    case 149: case 150: case 181: case 182: return (ShaderIndex)58;
    case 16389: case 16390: case 16421: case 16422: return (ShaderIndex)59;
    case 16405: case 16406: case 16437: case 16438: return (ShaderIndex)60;
    case 13: case 14: case 40977: case 40978: case 41233: case 41234: return (ShaderIndex)61;
    case 45: case 46: case 41009: case 41010: case 41265: case 41266: return (ShaderIndex)62;
    case 29: case 30: case 40993: case 40994: case 41249: case 41250: return (ShaderIndex)63;
    case 61: case 62: case 41025: case 41026: case 41281: case 41282: return (ShaderIndex)64;
    case 77: case 78: return (ShaderIndex)65;
    case 109: case 110: return (ShaderIndex)66;
    case 93: case 94: return (ShaderIndex)67;
    case 125: case 126: return (ShaderIndex)68;
    case 141: case 142: case 173: case 174: return (ShaderIndex)69;
    case 157: case 158: case 189: case 190: return (ShaderIndex)70;
    case 16397: case 16398: case 16429: case 16430: return (ShaderIndex)71;
    case 16413: case 16414: case 16445: case 16446: return (ShaderIndex)72;
    case 32771: return (ShaderIndex)73;
    case 36867: case 36868: return (ShaderIndex)74;
    case 33795: case 33796: return (ShaderIndex)75;
    case 33811: case 33812: return (ShaderIndex)76;
    case 32779: return (ShaderIndex)77;
    case 36875: case 36876: return (ShaderIndex)78;
    case 33803: case 33804: return (ShaderIndex)79;
    case 33819: case 33820: return (ShaderIndex)80;
    case 32773: return (ShaderIndex)81;
    case 36869: case 36870: return (ShaderIndex)82;
    case 33797: case 33798: return (ShaderIndex)83;
    case 33813: case 33814: return (ShaderIndex)84;
    case 32781: return (ShaderIndex)85;
    case 36877: case 36878: return (ShaderIndex)86;
    case 33805: case 33806: return (ShaderIndex)87;
    case 33821: case 33822: return (ShaderIndex)88;
    case 32775: return (ShaderIndex)89;
    case 36871: case 36872: return (ShaderIndex)90;
    case 33799: case 33800: return (ShaderIndex)91;
    case 33815: case 33816: return (ShaderIndex)92;
    case 32783: return (ShaderIndex)93;
    case 36879: case 36880: return (ShaderIndex)94;
    case 33807: case 33808: return (ShaderIndex)95;
    case 33823: case 33824: return (ShaderIndex)96;
    case 41545: case 41546: case 42057: case 42058: case 42571: case 42572: case 42827: case 42828:
    case 44107: case 44108: case 44619: case 44620: case 44875: case 44876: case 46667: case 46668:
    case 51787: case 51788: case 52043: case 52044: case 59979: case 59980: case 60235: case 60236: return (ShaderIndex)97;
    case 75341: case 75469: case 79437: case 79565: case 91725: case 91853: case 95821: case 95949:
    case 108111: case 108113: case 108182: case 108184: case 108186: case 108190: case 108198: case 108214: return (ShaderIndex)98;
    case 76365: case 76493: case 80461: case 80589: case 92749: case 92877: case 96845: case 96973: return (ShaderIndex)99;
    case 108115: case 108117: case 108119: case 108121: case 108125: case 108133: case 108149: return (ShaderIndex)1;
    default: return (ShaderIndex)0;
    }
}

// MS2-FUNCTIONAL: generated switch; MSVC lays out the compare tree / jump tables its own way
// @0x14273fe90
FragShaderDesc::ShaderIndex FragShaderDesc::GetShaderIndexForComboIndex(unsigned index)
{
    unsigned key = index;
    switch (key)
    {
    case 0: case 32: case 179: case 186: return (ShaderIndex)1;
    case 1: case 33: case 180: case 187: return (ShaderIndex)2;
    case 2: case 34: return (ShaderIndex)3;
    case 3: case 35: return (ShaderIndex)4;
    case 4: case 36: case 181: case 188: return (ShaderIndex)5;
    case 5: case 37: case 182: case 189: return (ShaderIndex)6;
    case 6: case 38: return (ShaderIndex)7;
    case 7: case 39: return (ShaderIndex)8;
    case 8: case 40: return (ShaderIndex)9;
    case 9: case 41: return (ShaderIndex)10;
    case 10: case 42: return (ShaderIndex)11;
    case 11: case 43: return (ShaderIndex)12;
    case 12: case 44: return (ShaderIndex)13;
    case 13: case 45: return (ShaderIndex)14;
    case 14: case 46: return (ShaderIndex)15;
    case 15: case 47: return (ShaderIndex)16;
    case 16: case 48: return (ShaderIndex)17;
    case 17: case 49: return (ShaderIndex)18;
    case 18: case 50: return (ShaderIndex)19;
    case 19: case 51: return (ShaderIndex)20;
    case 20: case 52: return (ShaderIndex)21;
    case 21: case 53: return (ShaderIndex)22;
    case 22: case 54: return (ShaderIndex)23;
    case 23: case 55: return (ShaderIndex)24;
    case 24: case 56: return (ShaderIndex)25;
    case 25: case 57: return (ShaderIndex)26;
    case 26: case 58: return (ShaderIndex)27;
    case 27: case 59: return (ShaderIndex)28;
    case 28: case 60: return (ShaderIndex)29;
    case 29: case 61: return (ShaderIndex)30;
    case 30: case 62: return (ShaderIndex)31;
    case 31: case 63: return (ShaderIndex)32;
    case 64: case 96: case 193: case 200: return (ShaderIndex)33;
    case 65: case 97: case 194: case 201: return (ShaderIndex)34;
    case 66: case 98: return (ShaderIndex)35;
    case 67: case 99: return (ShaderIndex)36;
    case 68: case 100: case 195: case 202: return (ShaderIndex)37;
    case 69: case 101: case 196: case 203: return (ShaderIndex)38;
    case 70: case 102: return (ShaderIndex)39;
    case 71: case 103: return (ShaderIndex)40;
    case 72: case 104: return (ShaderIndex)41;
    case 73: case 105: return (ShaderIndex)42;
    case 74: case 106: return (ShaderIndex)43;
    case 75: case 107: return (ShaderIndex)44;
    case 76: case 108: return (ShaderIndex)45;
    case 77: case 109: return (ShaderIndex)46;
    case 78: case 110: return (ShaderIndex)47;
    case 79: case 111: return (ShaderIndex)48;
    case 80: case 112: return (ShaderIndex)49;
    case 81: case 113: return (ShaderIndex)50;
    case 82: case 114: return (ShaderIndex)51;
    case 83: case 115: return (ShaderIndex)52;
    case 84: case 116: return (ShaderIndex)53;
    case 85: case 117: return (ShaderIndex)54;
    case 86: case 118: return (ShaderIndex)55;
    case 87: case 119: return (ShaderIndex)56;
    case 88: case 120: return (ShaderIndex)57;
    case 89: case 121: return (ShaderIndex)58;
    case 90: case 122: return (ShaderIndex)59;
    case 91: case 123: return (ShaderIndex)60;
    case 92: case 124: return (ShaderIndex)61;
    case 93: case 125: return (ShaderIndex)62;
    case 94: case 126: return (ShaderIndex)63;
    case 95: case 127: return (ShaderIndex)64;
    case 128: case 152: return (ShaderIndex)67;
    case 129: case 153: return (ShaderIndex)68;
    case 130: case 154: return (ShaderIndex)71;
    case 131: case 155: return (ShaderIndex)72;
    case 132: case 156: return (ShaderIndex)75;
    case 133: case 157: return (ShaderIndex)76;
    case 134: case 158: return (ShaderIndex)79;
    case 135: case 159: return (ShaderIndex)80;
    case 136: case 160: return (ShaderIndex)81;
    case 137: case 161: return (ShaderIndex)82;
    case 138: case 162: return (ShaderIndex)83;
    case 139: case 163: return (ShaderIndex)84;
    case 140: case 164: return (ShaderIndex)85;
    case 141: case 165: return (ShaderIndex)86;
    case 142: case 166: return (ShaderIndex)87;
    case 143: case 167: return (ShaderIndex)88;
    case 144: case 168: return (ShaderIndex)89;
    case 145: case 169: return (ShaderIndex)90;
    case 146: case 170: return (ShaderIndex)91;
    case 147: case 171: return (ShaderIndex)92;
    case 148: case 172: return (ShaderIndex)93;
    case 149: case 173: return (ShaderIndex)94;
    case 150: case 174: return (ShaderIndex)95;
    case 151: case 175: return (ShaderIndex)96;
    case 176: case 183: return (ShaderIndex)97;
    case 177: case 184: return (ShaderIndex)98;
    case 178: case 185: return (ShaderIndex)99;
    case 190: case 197: return (ShaderIndex)100;
    case 191: case 198: return (ShaderIndex)101;
    case 192: case 199: return (ShaderIndex)102;
    case 204: case 220: return (ShaderIndex)106;
    case 205: case 221: return (ShaderIndex)107;
    case 206: case 222: return (ShaderIndex)108;
    case 207: case 223: return (ShaderIndex)109;
    case 208: case 224: return (ShaderIndex)110;
    case 209: case 225: return (ShaderIndex)111;
    case 210: case 226: return (ShaderIndex)112;
    case 211: case 227: return (ShaderIndex)113;
    case 212: case 228: return (ShaderIndex)114;
    case 213: case 229: return (ShaderIndex)115;
    case 214: case 230: return (ShaderIndex)116;
    case 215: case 231: return (ShaderIndex)117;
    case 216: case 232: return (ShaderIndex)118;
    case 217: case 233: return (ShaderIndex)119;
    case 218: case 234: return (ShaderIndex)120;
    case 219: case 235: return (ShaderIndex)121;
    case 236: case 252: return (ShaderIndex)122;
    case 237: case 253: return (ShaderIndex)123;
    case 238: case 254: return (ShaderIndex)124;
    case 239: case 255: return (ShaderIndex)125;
    case 240: case 256: return (ShaderIndex)126;
    case 241: case 257: return (ShaderIndex)127;
    case 242: case 258: return (ShaderIndex)128;
    case 243: case 259: return (ShaderIndex)129;
    case 244: case 260: return (ShaderIndex)130;
    case 245: case 261: return (ShaderIndex)131;
    case 246: case 262: return (ShaderIndex)132;
    case 247: case 263: return (ShaderIndex)133;
    case 248: case 264: return (ShaderIndex)134;
    case 249: case 265: return (ShaderIndex)135;
    case 250: case 266: return (ShaderIndex)136;
    case 251: case 267: return (ShaderIndex)137;
    case 268: case 276: return (ShaderIndex)140;
    case 269: case 277: return (ShaderIndex)141;
    case 270: case 278: return (ShaderIndex)144;
    case 271: case 279: return (ShaderIndex)145;
    case 272: case 280: return (ShaderIndex)148;
    case 273: case 281: return (ShaderIndex)149;
    case 274: case 282: return (ShaderIndex)152;
    case 275: case 283: return (ShaderIndex)153;
    case 284: return (ShaderIndex)154;
    case 285: return (ShaderIndex)155;
    case 286: return (ShaderIndex)156;
    case 287: return (ShaderIndex)157;
    case 288: return (ShaderIndex)158;
    case 289: return (ShaderIndex)159;
    case 290: return (ShaderIndex)160;
    case 291: return (ShaderIndex)161;
    case 292: return (ShaderIndex)162;
    case 293: return (ShaderIndex)163;
    case 294: return (ShaderIndex)164;
    case 295: return (ShaderIndex)165;
    case 296: return (ShaderIndex)166;
    case 297: return (ShaderIndex)167;
    case 298: return (ShaderIndex)168;
    case 299: return (ShaderIndex)169;
    case 300: return (ShaderIndex)170;
    case 301: return (ShaderIndex)171;
    case 302: return (ShaderIndex)172;
    case 303: return (ShaderIndex)173;
    case 304: return (ShaderIndex)174;
    case 305: return (ShaderIndex)175;
    case 306: return (ShaderIndex)176;
    case 307: return (ShaderIndex)177;
    case 308: return (ShaderIndex)178;
    case 309: return (ShaderIndex)179;
    case 310: return (ShaderIndex)180;
    case 311: return (ShaderIndex)181;
    case 312: return (ShaderIndex)182;
    case 313: return (ShaderIndex)183;
    case 314: return (ShaderIndex)184;
    case 315: return (ShaderIndex)185;
    case 316: return (ShaderIndex)186;
    case 317: return (ShaderIndex)187;
    case 318: return (ShaderIndex)188;
    case 319: return (ShaderIndex)189;
    case 320: return (ShaderIndex)190;
    case 321: return (ShaderIndex)191;
    case 322: return (ShaderIndex)192;
    case 323: return (ShaderIndex)193;
    case 324: return (ShaderIndex)194;
    case 325: return (ShaderIndex)195;
    case 326: return (ShaderIndex)196;
    case 327: return (ShaderIndex)197;
    case 328: return (ShaderIndex)198;
    case 329: return (ShaderIndex)199;
    case 330: return (ShaderIndex)200;
    case 331: return (ShaderIndex)201;
    case 332: return (ShaderIndex)202;
    case 333: return (ShaderIndex)203;
    case 334: return (ShaderIndex)204;
    case 335: return (ShaderIndex)205;
    case 336: return (ShaderIndex)206;
    case 337: return (ShaderIndex)207;
    case 338: return (ShaderIndex)208;
    case 339: return (ShaderIndex)209;
    case 340: return (ShaderIndex)210;
    case 341: return (ShaderIndex)211;
    case 342: return (ShaderIndex)212;
    default: return (ShaderIndex)0;
    }
}

// MS2-FUNCTIONAL: generated switch; MSVC lays out the compare tree / jump tables its own way
// @0x1427407a0
VertexShaderDesc::ShaderIndex VertexShaderDesc::GetShaderIndexForComboIndex(unsigned index)
{
    unsigned key = index;
    switch (key)
    {
    case 0: case 1: case 204: case 205: case 212: case 213: case 284: case 285: case 330: case 331:
    case 332: case 333: case 334: case 335: case 336: return (ShaderIndex)1;
    case 2: case 3: case 206: case 207: case 214: case 215: case 286: case 287: return (ShaderIndex)2;
    case 4: case 5: case 208: case 209: case 216: case 217: return (ShaderIndex)3;
    case 6: case 7: case 210: case 211: case 218: case 219: return (ShaderIndex)4;
    case 8: case 9: return (ShaderIndex)5;
    case 10: case 11: return (ShaderIndex)6;
    case 12: case 13: return (ShaderIndex)7;
    case 14: case 15: return (ShaderIndex)8;
    case 16: case 17: case 18: case 19: return (ShaderIndex)9;
    case 20: case 21: case 22: case 23: return (ShaderIndex)10;
    case 24: case 25: case 26: case 27: return (ShaderIndex)11;
    case 28: case 29: case 30: case 31: return (ShaderIndex)12;
    case 32: case 33: case 220: case 221: case 228: case 229: return (ShaderIndex)13;
    case 34: case 35: case 222: case 223: case 230: case 231: return (ShaderIndex)14;
    case 36: case 37: case 224: case 225: case 232: case 233: return (ShaderIndex)15;
    case 38: case 39: case 226: case 227: case 234: case 235: return (ShaderIndex)16;
    case 40: case 41: return (ShaderIndex)17;
    case 42: case 43: return (ShaderIndex)18;
    case 44: case 45: return (ShaderIndex)19;
    case 46: case 47: return (ShaderIndex)20;
    case 48: case 49: case 50: case 51: return (ShaderIndex)21;
    case 52: case 53: case 54: case 55: return (ShaderIndex)22;
    case 56: case 57: case 58: case 59: return (ShaderIndex)23;
    case 60: case 61: case 62: case 63: return (ShaderIndex)24;
    case 64: case 65: case 236: case 237: case 244: case 245: return (ShaderIndex)25;
    case 66: case 67: case 238: case 239: case 246: case 247: return (ShaderIndex)26;
    case 68: case 69: case 240: case 241: case 248: case 249: return (ShaderIndex)27;
    case 70: case 71: case 242: case 243: case 250: case 251: return (ShaderIndex)28;
    case 72: case 73: return (ShaderIndex)29;
    case 74: case 75: return (ShaderIndex)30;
    case 76: case 77: return (ShaderIndex)31;
    case 78: case 79: return (ShaderIndex)32;
    case 80: case 81: case 82: case 83: return (ShaderIndex)33;
    case 84: case 85: case 86: case 87: return (ShaderIndex)34;
    case 88: case 89: case 90: case 91: return (ShaderIndex)35;
    case 92: case 93: case 94: case 95: return (ShaderIndex)36;
    case 96: case 97: case 252: case 253: case 260: case 261: return (ShaderIndex)37;
    case 98: case 99: case 254: case 255: case 262: case 263: return (ShaderIndex)38;
    case 100: case 101: case 256: case 257: case 264: case 265: return (ShaderIndex)39;
    case 102: case 103: case 258: case 259: case 266: case 267: return (ShaderIndex)40;
    case 104: case 105: return (ShaderIndex)41;
    case 106: case 107: return (ShaderIndex)42;
    case 108: case 109: return (ShaderIndex)43;
    case 110: case 111: return (ShaderIndex)44;
    case 112: case 113: case 114: case 115: return (ShaderIndex)45;
    case 116: case 117: case 118: case 119: return (ShaderIndex)46;
    case 120: case 121: case 122: case 123: return (ShaderIndex)47;
    case 124: case 125: case 126: case 127: return (ShaderIndex)48;
    case 128: case 129: case 268: case 269: case 272: case 273: return (ShaderIndex)50;
    case 130: case 131: case 270: case 271: case 274: case 275: return (ShaderIndex)52;
    case 132: case 133: return (ShaderIndex)54;
    case 134: case 135: return (ShaderIndex)56;
    case 136: case 137: case 138: case 139: return (ShaderIndex)57;
    case 140: case 141: case 142: case 143: return (ShaderIndex)58;
    case 144: case 145: case 146: case 147: return (ShaderIndex)59;
    case 148: case 149: case 150: case 151: return (ShaderIndex)60;
    case 152: case 153: case 276: case 277: case 280: case 281: return (ShaderIndex)62;
    case 154: case 155: case 278: case 279: case 282: case 283: return (ShaderIndex)64;
    case 156: case 157: return (ShaderIndex)66;
    case 158: case 159: return (ShaderIndex)68;
    case 160: case 161: case 162: case 163: return (ShaderIndex)69;
    case 164: case 165: case 166: case 167: return (ShaderIndex)70;
    case 168: case 169: case 170: case 171: return (ShaderIndex)71;
    case 172: case 173: case 174: case 175: return (ShaderIndex)72;
    case 176: return (ShaderIndex)73;
    case 177: case 178: return (ShaderIndex)74;
    case 179: case 180: return (ShaderIndex)75;
    case 181: case 182: return (ShaderIndex)76;
    case 183: return (ShaderIndex)77;
    case 184: case 185: return (ShaderIndex)78;
    case 186: case 187: return (ShaderIndex)79;
    case 188: case 189: return (ShaderIndex)80;
    case 190: return (ShaderIndex)81;
    case 191: case 192: return (ShaderIndex)82;
    case 193: case 194: return (ShaderIndex)83;
    case 195: case 196: return (ShaderIndex)84;
    case 197: return (ShaderIndex)85;
    case 198: case 199: return (ShaderIndex)86;
    case 200: case 201: return (ShaderIndex)87;
    case 202: case 203: return (ShaderIndex)88;
    case 288: case 289: case 290: case 291: case 292: case 293: case 294: case 295: case 296: case 297:
    case 298: case 299: case 300: case 301: case 302: case 303: case 304: case 305: case 306: case 307:
    case 308: case 309: case 310: case 311: return (ShaderIndex)97;
    case 312: case 313: case 314: case 315: case 316: case 317: case 318: case 319: case 328: case 329:
    case 337: case 338: case 339: case 340: case 341: case 342: return (ShaderIndex)98;
    case 320: case 321: case 322: case 323: case 324: case 325: case 326: case 327: return (ShaderIndex)99;
    default: return (ShaderIndex)0;
    }
}

// ==== D3D9_Shader ====================================================================================================

void D3DVertexDeclBuilder::Add(int, unsigned attr, int, int)
{
    // the shader's attribute with the same usage and index
    const unsigned key = attr & (VET_Usage_Mask | VET_Index_Mask);
    int slot = 0;
    for (; slot < VertexDesc->NumAttribs; slot++)
        if ((VertexDesc->Attributes[slot].Attr & (VET_Usage_Mask | VET_Index_Mask)) == key)
            break;

    BYTE type   = D3DDECLTYPE_UNUSED;
    WORD bytes  = 0;
    WORD stream = 0;
    switch (attr & (VET_CompType_Mask | VET_Components_Mask))
    {
    case VET_U8N | 1: case VET_U8N | 2: case VET_U8N | 4:
        type = D3DDECLTYPE_UBYTE4N; bytes = 4; break;
    case VET_U8 | 1: case VET_U8 | 2: case VET_U8 | 4:
        type = D3DDECLTYPE_UBYTE4; bytes = 4; break;
    case VET_S16 | 2:
        type = D3DDECLTYPE_SHORT2; bytes = 4; break;
    case VET_U32 | 1:
        type = D3DDECLTYPE_D3DCOLOR; bytes = 4; break;
    case VET_F32 | 2:
        type = D3DDECLTYPE_FLOAT2; bytes = 8; break;
    case VET_I8 | 1:
        // the batch index rides in the instancing stream
        type = D3DDECLTYPE_UBYTE4; bytes = 4; stream = 1; break;
    }

    D3DVERTEXELEMENT9& e = Elements[Count++];
    e.Stream     = stream;
    e.Offset     = Size[stream];
    e.Type       = type;
    e.Method     = D3DDECLMETHOD_DEFAULT;
    e.Usage      = VertexDesc->Attributes[slot].Usage;
    e.UsageIndex = VertexDesc->Attributes[slot].UsageIndex;
    Size[stream] = Size[stream] + bytes;
}

}}} // namespace Scaleform::Render::D3D9

namespace Scaleform { namespace Render {

// MS2-FUNCTIONAL: own builder walk; register allocation / jump table differ (pinned at the end)
template void BuildVertexArray<D3D9::D3DVertexDeclBuilder>(const VertexFormat*, D3D9::D3DVertexDeclBuilder&);

}} // namespace Scaleform::Render

namespace Scaleform { namespace Render { namespace D3D9 {

// @0x142740f10
SysVertexFormat::SysVertexFormat(IDirect3DDevice9* device, const VertexFormat* format, const VertexShaderDesc* vdesc)
    : pVDecl(0)
{
    D3DVertexDeclBuilder builder(vdesc);
    BuildVertexArray(format, builder);
    if (FAILED(device->CreateVertexDeclaration(builder.Elements, &pVDecl.GetRawRef())))
        pVDecl = 0;
    memcpy(VertexElements, builder.Elements, sizeof(VertexElements));
}

// MS2-FUNCTIONAL: the uniform walk is scheduled differently
// @0x1427410e0
void ShaderInterface::Finish(unsigned)
{
    // Dirty uniforms are uploaded as one register range per stage: a uniform whose shadow slot does not continue the
    // running range flushes it first.
    struct Range
    {
        int Lo, Hi, Shadow;
        Range() : Lo(SF_MAX_SINT), Hi(-1), Shadow(0) { }
        // false: the range was flushed and this uniform dropped
        bool Add(const UniformVar& u, int& flushLo, int& flushCount, int& flushShadow)
        {
            int first = u.Location * 4;
            int shadow = u.ShadowOffset - first;
            if (shadow != Shadow && Hi >= 0)
            {
                flushLo = Lo; flushCount = Hi - Lo; flushShadow = Shadow;
                Shadow = shadow;
                Lo = SF_MAX_SINT;
                Hi = -1;
                return false;
            }
            Shadow = shadow;
            Lo = Alg::Min(Lo, first / 4);
            Hi = Alg::Max(Hi, (first + u.Size + 3) / 4);
            return true;
        }
    };

    IDirect3DDevice9* device = pHal->pDevice;
    Range fs, vs;
    for (int i = 0; i < Uniform::SU_Count; i++)
    {
        if (!UniformSet[i])
            continue;
        int lo, count, shadow;
        if (CurShaders.pFS->Uniforms[i] >= 0)
        {
            if (!fs.Add(CurShaders.pFDesc->Uniforms[i], lo, count, shadow))
                device->SetPixelShaderConstantF(lo, UniformData + shadow, count);
        }
        else if (CurShaders.pVS->Uniforms[i] >= 0)
        {
            if (!vs.Add(CurShaders.pVDesc->Uniforms[i], lo, count, shadow))
                device->SetVertexShaderConstantF(lo, UniformData + shadow, count);
        }
    }
    if (vs.Hi >= 0)
        device->SetVertexShaderConstantF(vs.Lo, UniformData + vs.Shadow, vs.Hi - vs.Lo);
    if (fs.Hi >= 0)
        device->SetPixelShaderConstantF(fs.Lo, UniformData + fs.Shadow, fs.Hi - fs.Lo);
    memset(UniformSet, 0, sizeof(UniformSet));

    if (pLastVS != CurShaders.pVS->pProg)
    {
        device->SetVertexShader(CurShaders.pVS->pProg);
        pLastVS = CurShaders.pVS->pProg;
    }
    IDirect3DVertexDeclaration9* decl = ((SysVertexFormat*)CurShaders.pVFormat->pSysFormat.GetPtr())->pVDecl;
    if (pLastDecl != decl)
    {
        device->SetVertexDeclaration(decl);
        pLastDecl = decl;
    }
    if (pLastFS != CurShaders.pFS->pProg)
    {
        device->SetPixelShader(CurShaders.pFS->pProg);
        pLastFS = CurShaders.pFS->pProg;
    }
}

// @0x1427410c0
void ShaderManager::BeginScene()
{
}

// @0x1427410d0
void ShaderManager::EndScene()
{
}

// @0x142741410
bool ShaderManager::HasDynamicLoopingSupport() const
{
    return DynamicLoopingSupport;
}

// @0x142741420
bool ShaderManager::HasInstancingSupport() const
{
    return InstancingSupport;
}

// MS2-FUNCTIONAL: frame / save order differs
// @0x142741620
bool VertexShader::Init(HAL* phal, const VertexShaderDesc* pd)
{
    if (!phal || !pd)
        return false;
    pDesc = pd;
    if (FAILED(phal->pDevice->CreateVertexShader(pd->pBinary, &pProg.GetRawRef())))
        return false;

    bool ok = false;
    ID3DXConstantTable* table = 0;
    if (SUCCEEDED(D3DXGetShaderConstantTableEx(pDesc->pBinary, D3DXCONSTTABLE_LARGEADDRESSAWARE, &table)))
    {
        ok = true;
        for (unsigned i = 0; i < Uniform::SU_Count; i++)
        {
            if (pDesc->Uniforms[i].Location < 0)
            {
                Uniforms[i] = -1;
                continue;
            }
            D3DXHANDLE h = table->GetConstantByName(0, ShaderUniformNames[i]);
            D3DXCONSTANT_DESC cdesc[8];
            UINT count = 8;
            if (!h || FAILED(table->GetConstantDesc(h, cdesc, &count)))
            {
                ok = false;
                break;
            }
            Uniforms[i] = cdesc[0].RegisterIndex;
        }
    }
    if (table)
        table->Release();
    return ok;
}

// MS2-FUNCTIONAL: frame / save order differs
// @0x142741430
bool FragShader::Init(HAL* phal, const FragShaderDesc* pd)
{
    if (!phal || !pd)
        return false;
    pDesc = pd;
    if (FAILED(phal->pDevice->CreatePixelShader(pd->pBinary, &pProg.GetRawRef())))
        return false;

    bool ok = false;
    ID3DXConstantTable* table = 0;
    if (SUCCEEDED(D3DXGetShaderConstantTableEx(pDesc->pBinary, D3DXCONSTTABLE_LARGEADDRESSAWARE, &table)))
    {
        ok = true;
        for (unsigned i = 0; i < Uniform::SU_Count; i++)
        {
            if (pDesc->Uniforms[i].Location < 0)
            {
                Uniforms[i] = -1;
                continue;
            }
            D3DXHANDLE h = table->GetConstantByName(0, ShaderUniformNames[i]);
            D3DXCONSTANT_DESC cdesc[8];
            UINT count = 8;
            if (!h || FAILED(table->GetConstantDesc(h, cdesc, &count)))
            {
                // walk the table's constants (the debug build prints them here)
                D3DXCONSTANTTABLE_DESC tdesc;
                if (SUCCEEDED(table->GetDesc(&tdesc)))
                {
                    for (unsigned c = 0; c < tdesc.Constants; c++)
                    {
                        D3DXCONSTANT_DESC one;
                        UINT n = 1;
                        table->GetConstantDesc(table->GetConstant(0, c), &one, &n);
                    }
                }
                table->GetConstant(0, 0);
                ok = false;
                break;
            }
            Uniforms[i] = cdesc[0].RegisterIndex;
        }
    }
    if (table)
        table->Release();
    return ok;
}

// MS2-FUNCTIONAL: the caps test is laid out differently
// @0x142741790
bool ShaderManager::Initialize(HAL* phal)
{
    pDevice = phal->pDevice;
    D3DCAPS9 caps;
    pDevice->GetDeviceCaps(&caps);
    if (caps.PixelShaderVersion >= D3DPS_VERSION(3, 0))
    {
        InstancingSupport     = true;
        DynamicLoopingSupport = true;
    }
    return true;
}

// @0x142741820
void ShaderManager::Reset()
{
    pDevice = 0;
}

// MS2-FUNCTIONAL: the declaration is built inline and stored through the Ptr; scheduling differs
// @0x142741850
bool ShaderInterface::SetStaticShader(VertexShaderDesc::ShaderType vshader, FragShaderDesc::ShaderType fshader,
                                      const VertexFormat* format)
{
    int vi = VertexShaderDesc::GetShaderIndex(vshader);
    int fi = FragShaderDesc::GetShaderIndex(fshader);

    CurShaders.pVFormat = format;
    CurShaders.pVS      = &pHal->StaticVShaders[vi];
    CurShaders.pVDesc   = CurShaders.pVS->pDesc;
    CurShaders.pFS      = &pHal->StaticFShaders[fi];
    CurShaders.pFDesc   = CurShaders.pFS->pDesc;

    if (format && !format->pSysFormat)
    {
        SysVertexFormat* sys = SF_HEAP_NEW(Memory::pGlobalHeap)
            SysVertexFormat(pHal->pDevice, format, CurShaders.pVS->pDesc);
        const_cast<VertexFormat*>(format)->pSysFormat = Pickable<Render::SystemVertexFormat>(sys);
    }
    return CurShaders.pVS && CurShaders.pFS && CurShaders.pVS->pProg && CurShaders.pFS->pProg &&
           CurShaders.pVFormat;
}

// MS2-FUNCTIONAL: the fill mode is forwarded by reference
// @0x142741a50
void ShaderInterface::SetTexture(Shader, unsigned var, Render::Texture* ptexture, ImageFillMode fm, unsigned index)
{
    ((Texture*)ptexture)->ApplyTexture(CurShaders.pFDesc->Uniforms[var].Location + index, fm);
}

// @0x142741a90
void FragShader::Shutdown()
{
    pProg = 0;
}

// @0x142741ac0
void VertexShader::Shutdown()
{
    pProg = 0;
}

}}} // namespace Scaleform::Render::D3D9

// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142740ff0
// MS2-PIN: ??_GSysVertexFormat@D3D9@Render@Scaleform@@UEAAPEAXI@Z 0x142741050
// MS2-PIN: ??_7SysVertexFormat@D3D9@Render@Scaleform@@6B@ 0x14319e020
// MS2-PIN: ??_7SystemVertexFormat@Render@Scaleform@@6B@ 0x1431925f8
// MS2-PIN: ??_7?$RefCountBase@VSystemVertexFormat@Render@Scaleform@@$01@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??$BuildVertexArray@UD3DVertexDeclBuilder@D3D9@Render@Scaleform@@@Render@Scaleform@@YAXPEBUVertexFormat@01@AEAUD3DVertexDeclBuilder@D3D9@01@@Z 0x142740c70
