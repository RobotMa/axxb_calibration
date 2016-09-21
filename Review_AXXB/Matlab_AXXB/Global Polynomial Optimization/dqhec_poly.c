#include "mex.h"
#include "matrix.h"


void poly(double *cons, double *vars);

void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
  double *cons, *vars;

  if (nrhs != 1)
    {
      mexErrMsgTxt("One input required.");
    }

  plhs[0] = mxCreateDoubleMatrix(177, 1,mxREAL);

  cons = mxGetPr(prhs[0]);
  vars = mxGetPr(plhs[0]);

  poly(cons, vars);
}

void poly(double *cons, double *vars)
{
/* Monomials: 177
    1
    qx2^2*qx1^2
    qx3^2*qx1^2
    qx4^2*qx1^2
    qx5^2*qx1^2
    qx3^2*qx2^2
    qx4^2*qx2^2
    qx6^2*qx2^2
    qx4^2*qx3^2
    qx7^2*qx3^2
    qx8^2*qx4^2
    qx7^2*qx1^2
    qx8^2*qx1^2
    qx7^2*qx2^2
    qx8^2*qx2^2
    qx5^2*qx3^2
    qx6^2*qx3^2
    qx5^2*qx4^2
    qx6^2*qx4^2
    qx6^2*qx1^2
    qx5^2*qx2^2
    qx8^2*qx3^2
    qx7^2*qx4^2
    qx5*qx1^3
    qx6*qx2^3
    qx7*qx3^3
    qx8*qx4^3
    qx8*qx1^3
    qx7*qx2^3
    qx6*qx3^3
    qx5*qx4^3
    qx7*qx1^3
    qx8*qx2^3
    qx5*qx3^3
    qx6*qx4^3
    qx6*qx1^3
    qx5*qx2^3
    qx8*qx3^3
    qx7*qx4^3
    qx4*qx1
    qx3*qx2
    qx3*qx1
    qx4*qx2
    qx2*qx1
    qx4*qx3
    qx5*qx1
    qx6*qx2
    qx7*qx3
    qx8*qx4
    qx8*qx1
    qx7*qx2
    qx6*qx3
    qx5*qx4
    qx7*qx1
    qx8*qx2
    qx5*qx3
    qx6*qx4
    qx6*qx1
    qx5*qx2
    qx8*qx3
    qx7*qx4
    qx6*qx5*qx2*qx1
    qx7*qx5*qx3*qx1
    qx8*qx5*qx4*qx1
    qx7*qx6*qx3*qx2
    qx8*qx6*qx4*qx2
    qx8*qx7*qx4*qx3
    qx6*qx2*qx1^2
    qx7*qx3*qx1^2
    qx8*qx4*qx1^2
    qx5*qx2^2*qx1
    qx5*qx3^2*qx1
    qx5*qx4^2*qx1
    qx7*qx3*qx2^2
    qx8*qx4*qx2^2
    qx6*qx3^2*qx2
    qx6*qx4^2*qx2
    qx8*qx4*qx3^2
    qx7*qx4^2*qx3
    qx8*qx6*qx3*qx1
    qx7*qx6*qx4*qx1
    qx8*qx5*qx3*qx2
    qx7*qx5*qx4*qx2
    qx7*qx6*qx1^2
    qx6^2*qx4*qx1
    qx7^2*qx4*qx1
    qx8*qx5*qx2^2
    qx5^2*qx3*qx2
    qx8^2*qx3*qx2
    qx8*qx5*qx3^2
    qx7*qx6*qx4^2
    qx8*qx6*qx1^2
    qx6^2*qx3*qx1
    qx8^2*qx3*qx1
    qx7*qx5*qx2^2
    qx5^2*qx4*qx2
    qx7^2*qx4*qx2
    qx8*qx6*qx3^2
    qx7*qx5*qx4^2
    qx7*qx2*qx1^2
    qx6*qx3*qx1^2
    qx5*qx4*qx1^2
    qx8*qx2^2*qx1
    qx8*qx3^2*qx1
    qx8*qx4^2*qx1
    qx6*qx3*qx2^2
    qx5*qx4*qx2^2
    qx7*qx3^2*qx2
    qx7*qx4^2*qx2
    qx5*qx4*qx3^2
    qx6*qx4^2*qx3
    qx8*qx2*qx1^2
    qx5*qx3*qx1^2
    qx6*qx4*qx1^2
    qx7*qx2^2*qx1
    qx7*qx3^2*qx1
    qx7*qx4^2*qx1
    qx5*qx3*qx2^2
    qx6*qx4*qx2^2
    qx8*qx3^2*qx2
    qx8*qx4^2*qx2
    qx6*qx4*qx3^2
    qx5*qx4^2*qx3
    qx8*qx7*qx2*qx1
    qx6*qx5*qx4*qx3
    qx8*qx7*qx1^2
    qx7^2*qx2*qx1
    qx8^2*qx2*qx1
    qx8*qx7*qx2^2
    qx6*qx5*qx3^2
    qx5^2*qx4*qx3
    qx6^2*qx4*qx3
    qx6*qx5*qx4^2
    qx5*qx2*qx1^2
    qx8*qx3*qx1^2
    qx7*qx4*qx1^2
    qx6*qx2^2*qx1
    qx6*qx3^2*qx1
    qx6*qx4^2*qx1
    qx8*qx3*qx2^2
    qx7*qx4*qx2^2
    qx5*qx3^2*qx2
    qx5*qx4^2*qx2
    qx7*qx4*qx3^2
    qx8*qx4^2*qx3
    qx7*qx5*qx2*qx1
    qx8*qx6*qx2*qx1
    qx6*qx5*qx3*qx1
    qx8*qx7*qx3*qx1
    qx6*qx5*qx4*qx2
    qx8*qx7*qx4*qx2
    qx7*qx5*qx4*qx3
    qx8*qx6*qx4*qx3
    qx8*qx5*qx2*qx1
    qx7*qx6*qx2*qx1
    qx6*qx5*qx4*qx1
    qx8*qx7*qx4*qx1
    qx6*qx5*qx3*qx2
    qx8*qx7*qx3*qx2
    qx8*qx5*qx4*qx3
    qx7*qx6*qx4*qx3
    qx8*qx5*qx3*qx1
    qx7*qx6*qx3*qx1
    qx7*qx5*qx4*qx1
    qx8*qx6*qx4*qx1
    qx7*qx5*qx3*qx2
    qx8*qx6*qx3*qx2
    qx8*qx5*qx4*qx2
    qx7*qx6*qx4*qx2
    qx4^4
    qx1^4
    qx2^4
    qx3^4
    qx3^2
    qx4^2
    qx2^2
    qx1^2
*/

/* Variables: 177 */
double var1,  var2,  var3,  var4,  var5,  var6,  var7,  var8,  var9,  var10,  var11;
double var12,  var13,  var14,  var15,  var16,  var17,  var18,  var19,  var20,  var21;
double var22,  var23,  var24,  var25,  var26,  var27,  var28,  var29,  var30,  var31;
double var32,  var33,  var34,  var35,  var36,  var37,  var38,  var39,  var40,  var41;
double var42,  var43,  var44,  var45,  var46,  var47,  var48,  var49,  var50,  var51;
double var52,  var53,  var54,  var55,  var56,  var57,  var58,  var59,  var60,  var61;
double var62,  var63,  var64,  var65,  var66,  var67,  var68,  var69,  var70,  var71;
double var72,  var73,  var74,  var75,  var76,  var77,  var78,  var79,  var80,  var81;
double var82,  var83,  var84,  var85,  var86,  var87,  var88,  var89,  var90,  var91;
double var92,  var93,  var94,  var95,  var96,  var97,  var98,  var99,  var100,  var101;
double var102,  var103,  var104,  var105,  var106,  var107,  var108,  var109,  var110,  var111;
double var112,  var113,  var114,  var115,  var116,  var117,  var118,  var119,  var120,  var121;
double var122,  var123,  var124,  var125,  var126,  var127,  var128,  var129,  var130,  var131;
double var132,  var133,  var134,  var135,  var136,  var137,  var138,  var139,  var140,  var141;
double var142,  var143,  var144,  var145,  var146,  var147,  var148,  var149,  var150,  var151;
double var152,  var153,  var154,  var155,  var156,  var157,  var158,  var159,  var160,  var161;
double var162,  var163,  var164,  var165,  var166,  var167,  var168,  var169,  var170,  var171;
double var172,  var173,  var174,  var175,  var176,  var177;

/* Temporary Variables: 50 */
double t1,  t2,  t3,  t4,  t5,  t6,  t7,  t8,  t9,  t10,  t11;
double t12,  t13,  t14,  t15,  t16,  t17,  t36,  t37,  t38,  t39;
double t42,  t43,  t44,  t45,  t48,  t49,  t50,  t51,  t54,  t55;
double t56,  t57,  t62,  t63,  t66,  t67,  t70,  t71,  t80,  t82;
double t85,  t86,  t87,  t88,  t89,  t90,  t91,  t92,  t93;


double qa1 = cons[0];
double qa2 = cons[1];
double qa3 = cons[2];
double qa4 = cons[3];
double qa5 = cons[4];
double qa6 = cons[5];
double qa7 = cons[6];
double qa8 = cons[7];
double qb1 = cons[8];
double qb2 = cons[9];
double qb3 = cons[10];
double qb4 = cons[11];
double qb5 = cons[12];
double qb6 = cons[13];
double qb7 = cons[14];
double qb8 = cons[15];

t1 = (double) qa1 * (double) qa1;
t2 = (double) qa2 * (double) qa2;
t3 = (double) qa3 * (double) qa3;
t4 = (double) qa4 * (double) qa4;
t5 = (double) qa5 * (double) qa5;
t6 = (double) qa6 * (double) qa6;
t7 = (double) qa7 * (double) qa7;
t8 = (double) qa8 * (double) qa8;
var1 = t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;
t9 =  ((double) qb2 * (double) qb2);
t10 =  ((double) qb4 * (double) qb4);
t11 = (double) qb8 * (double) qb8;
t12 = (double) qb6 * (double) qb6;
t13 =  ((double) qb3 * (double) qb3);
t14 =  ((double) qb1 * (double) qb1);
t15 = (double) qb7 * (double) qb7;
t16 = (double) qb5 * (double) qb5;
t17 =  ((double) t9 + (double) t10 + t11 + t12 + (double) t13 + (double) t14 + t15 + t16);
var2 = 2 * t17;
var3 = var2;
var4 = var3;
var5 = 4 * t13 + 4 * t9 + 4 * t10 + 4 * t14;
var6 = var4;
var7 = var6;
var8 = var5;
var9 = var7;
var10 = var8;
var11 = var10;
var12 = 4 * t9 + 4 * t10;
var13 = 4 * t13 + 4 * t9;
var14 = var13;
var15 = var12;
var16 = var15;
var17 = var14;
var18 = var17;
var19 = var16;
var20 = 4 * t10 + 4 * t13;
var21 = var20;
var22 = var21;
var23 = var22;
var24 = 4 * qb1 * qb5 + 4 * qb3 * qb7 + 4 * qb2 * qb6 + 4 * qb4 * qb8;
var25 = var24;
var26 = var25;
var27 = var26;
var28 = -4 * qb3 * qb6 + 4 * qb2 * qb7;
var29 = -var28;
var30 = var28;
var31 = var29;
var32 = 4 * qb4 * qb6 - 4 * qb2 * qb8;
var33 = var32;
var34 = -var33;
var35 = var34;
var36 = 4 * qb3 * qb8 - 4 * qb4 * qb7;
var37 = -var36;
var38 = var37;
var39 = var36;
t36 = qa7 * qb6;
t37 = qa6 * qb7;
t38 = qa2 * qb3;
t39 = qa3 * qb2;
var40 = -4 * t36 + 4 * t37 + 4 * t38 - 4 * t39;
var41 = -4 * t38 - 4 * t39 - 4 * t36 - 4 * t37;
t42 = qa2 * qb4;
t43 = qa6 * qb8;
t44 = qa4 * qb2;
t45 = qa8 * qb6;
var42 = -4 * t42 - 4 * t43 + 4 * t44 + 4 * t45;
var43 = -4 * t44 - 4 * t43 - 4 * t42 - 4 * t45;
t48 = qa4 * qb3;
t49 = qa7 * qb8;
t50 = qa8 * qb7;
t51 = qa3 * qb4;
var44 = -4 * t48 + 4 * t49 - 4 * t50 + 4 * t51;
var45 = -4 * t51 - 4 * t50 - 4 * t48 - 4 * t49;
t54 = qa8 * qb4;
t55 = qa7 * qb3;
t56 = qa6 * qb2;
t57 = qa5 * qb1;
var46 = -4 * t54 - 4 * t55 - 4 * t56 - 4 * t57;
var47 = -4 * t57 + 4 * t55 - 4 * t56 + 4 * t54;
var48 = 4 * t56 + 4 * t54 - 4 * t55 - 4 * t57;
var49 = -4 * t57 + 4 * t55 + 4 * t56 - 4 * t54;
t62 = qa7 * qb2;
t63 = qa6 * qb3;
var50 = -4 * t62 + 4 * t63;
var51 = -4 * t62 - 4 * t63;
var52 = var51;
var53 = var50;
t66 = qa6 * qb4;
t67 = qa8 * qb2;
var54 = -4 * t66 + 4 * t67;
var55 = -4 * t66 - 4 * t67;
var56 = var54;
var57 = var55;
t70 = qa7 * qb4;
t71 = qa8 * qb3;
var58 = 4 * t70 - 4 * t71;
var59 = var58;
var60 = -4 * t71 - 4 * t70;
var61 = var60;
var62 = 8 * t14 + 8 * t9;
var63 = 8 * t13 + 8 * t14;
var64 = 8 * t14 + 8 * t10;
var65 = var64;
var66 = var63;
var67 = var62;
var68 = var27;
var69 = var68;
var70 = var69;
var71 = var70;
var72 = var71;
var73 = var72;
var74 = var73;
var75 = var74;
var76 = var75;
var77 = var76;
var78 = var77;
var79 = var78;
var80 = -8 * t10 + 8 * t9;
var81 = 8 * t13 - 8 * t9;
var82 = var81;
var83 = var80;
t80 = 8 * qb2 * qb3;
var84 = -t80;
var85 = t80;
var86 = var84;
var87 = var85;
var88 = var86;
var89 = var87;
var90 = var88;
var91 = var89;
t82 = 8 * qb2 * qb4;
var92 = -t82;
var93 = var92;
var94 = t82;
var95 = var93;
var96 = var95;
var97 = var94;
var98 = var97;
var99 = var98;
var100 = var31;
var101 = var30;
var102 = var100;
var103 = var101;
var104 = var103;
var105 = var104;
var106 = var105;
var107 = var102;
var108 = var107;
var109 = var108;
var110 = var109;
var111 = var106;
var112 = var33;
var113 = var35;
var114 = var113;
var115 = var112;
var116 = var115;
var117 = var116;
var118 = var114;
var119 = var118;
var120 = var117;
var121 = var120;
var122 = var119;
var123 = var122;
var124 = 8 * t10 - 8 * t13;
var125 = var124;
t85 = 8 * qb3 * qb4;
var126 = -t85;
var127 = t85;
var128 = var126;
var129 = var127;
var130 = var129;
var131 = var128;
var132 = var130;
var133 = var131;
var134 = var38;
var135 = var134;
var136 = var39;
var137 = var136;
var138 = var137;
var139 = var138;
var140 = var135;
var141 = var139;
var142 = var140;
var143 = var142;
var144 = var141;
var145 = var143;
var146 = var91;
var147 = var90;
var148 = var146;
var149 = var148;
var150 = var147;
var151 = var150;
var152 = var149;
var153 = var151;
var154 = var99;
var155 = var154;
var156 = var155;
var157 = var96;
var158 = var156;
var159 = var157;
var160 = var159;
var161 = var160;
var162 = var132;
var163 = var133;
var164 = var162;
var165 = var164;
var166 = var163;
var167 = var166;
var168 = var165;
var169 = var167;
var170 = t17;
var171 = var170;
var172 = var171;
var173 = var172;
t86 = qa8 * qb8;
t87 = qa7 * qb7;
t88 = qa4 * qb4;
t89 = qa3 * qb3;
t90 = qa5 * qb5;
t91 = qa1 * qb1;
t92 = qa2 * qb2;
t93 = qa6 * qb6;
var174 = 2 * t86 - 2 * t87 + 2 * t88 - 2 * t89 - 2 * t90 - 2 * t91 + 2 * t92 + 2 * t93;
var175 = -2 * t86 + 2 * t87 - 2 * t88 - 2 * t90 + 2 * t89 + 2 * t92 - 2 * t91 + 2 * t93;
var176 = -2 * t91 + 2 * t86 - 2 * t92 + 2 * t88 + 2 * t87 - 2 * t93 + 2 * t89 - 2 * t90;
var177 = -2 * t91 - 2 * t86 - 2 * t92 - 2 * t89 - 2 * t87 - 2 * t93 - 2 * t90 - 2 * t88;


vars[0] = var1;
vars[1] = var2;
vars[2] = var3;
vars[3] = var4;
vars[4] = var5;
vars[5] = var6;
vars[6] = var7;
vars[7] = var8;
vars[8] = var9;
vars[9] = var10;
vars[10] = var11;
vars[11] = var12;
vars[12] = var13;
vars[13] = var14;
vars[14] = var15;
vars[15] = var16;
vars[16] = var17;
vars[17] = var18;
vars[18] = var19;
vars[19] = var20;
vars[20] = var21;
vars[21] = var22;
vars[22] = var23;
vars[23] = var24;
vars[24] = var25;
vars[25] = var26;
vars[26] = var27;
vars[27] = var28;
vars[28] = var29;
vars[29] = var30;
vars[30] = var31;
vars[31] = var32;
vars[32] = var33;
vars[33] = var34;
vars[34] = var35;
vars[35] = var36;
vars[36] = var37;
vars[37] = var38;
vars[38] = var39;
vars[39] = var40;
vars[40] = var41;
vars[41] = var42;
vars[42] = var43;
vars[43] = var44;
vars[44] = var45;
vars[45] = var46;
vars[46] = var47;
vars[47] = var48;
vars[48] = var49;
vars[49] = var50;
vars[50] = var51;
vars[51] = var52;
vars[52] = var53;
vars[53] = var54;
vars[54] = var55;
vars[55] = var56;
vars[56] = var57;
vars[57] = var58;
vars[58] = var59;
vars[59] = var60;
vars[60] = var61;
vars[61] = var62;
vars[62] = var63;
vars[63] = var64;
vars[64] = var65;
vars[65] = var66;
vars[66] = var67;
vars[67] = var68;
vars[68] = var69;
vars[69] = var70;
vars[70] = var71;
vars[71] = var72;
vars[72] = var73;
vars[73] = var74;
vars[74] = var75;
vars[75] = var76;
vars[76] = var77;
vars[77] = var78;
vars[78] = var79;
vars[79] = var80;
vars[80] = var81;
vars[81] = var82;
vars[82] = var83;
vars[83] = var84;
vars[84] = var85;
vars[85] = var86;
vars[86] = var87;
vars[87] = var88;
vars[88] = var89;
vars[89] = var90;
vars[90] = var91;
vars[91] = var92;
vars[92] = var93;
vars[93] = var94;
vars[94] = var95;
vars[95] = var96;
vars[96] = var97;
vars[97] = var98;
vars[98] = var99;
vars[99] = var100;
vars[100] = var101;
vars[101] = var102;
vars[102] = var103;
vars[103] = var104;
vars[104] = var105;
vars[105] = var106;
vars[106] = var107;
vars[107] = var108;
vars[108] = var109;
vars[109] = var110;
vars[110] = var111;
vars[111] = var112;
vars[112] = var113;
vars[113] = var114;
vars[114] = var115;
vars[115] = var116;
vars[116] = var117;
vars[117] = var118;
vars[118] = var119;
vars[119] = var120;
vars[120] = var121;
vars[121] = var122;
vars[122] = var123;
vars[123] = var124;
vars[124] = var125;
vars[125] = var126;
vars[126] = var127;
vars[127] = var128;
vars[128] = var129;
vars[129] = var130;
vars[130] = var131;
vars[131] = var132;
vars[132] = var133;
vars[133] = var134;
vars[134] = var135;
vars[135] = var136;
vars[136] = var137;
vars[137] = var138;
vars[138] = var139;
vars[139] = var140;
vars[140] = var141;
vars[141] = var142;
vars[142] = var143;
vars[143] = var144;
vars[144] = var145;
vars[145] = var146;
vars[146] = var147;
vars[147] = var148;
vars[148] = var149;
vars[149] = var150;
vars[150] = var151;
vars[151] = var152;
vars[152] = var153;
vars[153] = var154;
vars[154] = var155;
vars[155] = var156;
vars[156] = var157;
vars[157] = var158;
vars[158] = var159;
vars[159] = var160;
vars[160] = var161;
vars[161] = var162;
vars[162] = var163;
vars[163] = var164;
vars[164] = var165;
vars[165] = var166;
vars[166] = var167;
vars[167] = var168;
vars[168] = var169;
vars[169] = var170;
vars[170] = var171;
vars[171] = var172;
vars[172] = var173;
vars[173] = var174;
vars[174] = var175;
vars[175] = var176;
vars[176] = var177;

}
