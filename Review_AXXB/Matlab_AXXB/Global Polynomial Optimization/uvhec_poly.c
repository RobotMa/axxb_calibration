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

  plhs[0] = mxCreateDoubleMatrix(124, 1,mxREAL);

  cons = mxGetPr(prhs[0]);
  vars = mxGetPr(plhs[0]);

  poly(cons, vars);
}

void poly(double *cons, double *vars)
{
/* Monomials: 124
    1
    rx4*rx8
    rx5*rx7
    rx1*rx8
    rx2*rx7
    rx1*rx5
    rx2*rx4
    rx8^2*rx4^2
    rx7^2*rx5^2
    rx8^2*rx1^2
    rx7^2*rx2^2
    rx5^2*rx1^2
    rx4^2*rx2^2
    rx8*rx1^2
    rx7*rx2^2
    rx8*rx4^2
    rx7*rx5^2
    rx5*rx1^2
    rx4*rx2^2
    rx7^2*rx5
    rx8^2*rx4
    rx4^2*rx2
    rx5^2*rx1
    rx7^2*rx2
    rx8^2*rx1
    rx4*rx1
    rx5*rx2
    tx2*tx1
    rx7*rx1
    rx8*rx2
    tx3*tx1
    rx2*rx1
    tx1*rx1
    tx1*rx2
    rx7*rx4
    rx8*rx5
    tx3*tx2
    tx2*rx1
    tx2*rx2
    tx3*rx1
    tx3*rx2
    tx1*rx4
    tx1*rx5
    rx5*rx4
    tx2*rx4
    tx2*rx5
    tx3*rx4
    tx3*rx5
    tx1*rx7
    tx1*rx8
    tx2*rx7
    tx2*rx8
    rx8*rx7
    tx3*rx7
    tx3*rx8
    rx8*rx7*rx5*rx4
    rx8^2*rx4*rx1
    rx7^2*rx5*rx2
    rx7*rx5^2*rx1
    rx8*rx4^2*rx2
    rx8*rx7*rx2*rx1
    rx8*rx5*rx1^2
    rx7*rx4*rx2^2
    rx5*rx4*rx2*rx1
    rx8*rx4*rx1
    rx7*rx5*rx1
    rx8*rx4*rx2
    rx7*rx5*rx2
    tx1*rx8*rx4
    tx1*rx7*rx5
    rx7*rx2*rx1
    rx8*rx2*rx1
    rx7*rx5*rx4
    rx8*rx5*rx4
    tx2*rx8*rx4
    tx2*rx7*rx5
    rx4*rx2*rx1
    rx5*rx2*rx1
    rx8*rx7*rx4
    rx8*rx7*rx5
    tx3*rx8*rx4
    tx3*rx7*rx5
    tx1*rx8*rx1
    tx1*rx7*rx2
    rx7*rx4*rx2
    rx8*rx5*rx1
    tx2*rx8*rx1
    tx2*rx7*rx2
    rx5*rx4*rx1
    rx5*rx4*rx2
    rx8*rx7*rx1
    rx8*rx7*rx2
    tx3*rx8*rx1
    tx3*rx7*rx2
    tx1*rx5*rx1
    tx1*rx4*rx2
    tx2*rx5*rx1
    tx2*rx4*rx2
    tx3*rx5*rx1
    tx3*rx4*rx2
    rx8*rx7*rx5*rx1
    rx8*rx7*rx4*rx2
    rx8*rx5*rx4*rx1
    rx7*rx5*rx4*rx2
    rx8*rx4*rx2*rx1
    rx7*rx5*rx2*rx1
    tx1^2
    tx2^2
    tx3^2
    rx1^2
    rx2^2
    rx4^2
    rx5^2
    rx7^2
    rx8^2
    rx1
    rx4
    rx7
    rx2
    rx8
    rx5
    tx1
    tx2
    tx3
*/

/* Variables: 124 */
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
double var122,  var123,  var124;

/* Temporary Variables: 63 */
double t1,  t2,  t3,  t5,  t12,  t20,  t25,  t26,  t27,  t28,  t29;
double t30,  t31,  t33,  t34,  t35,  t36,  t38,  t39,  t40,  t41;
double t43,  t80,  t82,  t83,  t90,  t91,  t92,  t100,  t103,  t104;
double t105,  t111,  t113,  t114,  t159,  t160,  t162,  t163,  t184,  t185;
double t186,  t187,  t189,  t190,  t192,  t193,  t194,  t195,  t197,  t198;
double t203,  t205,  t213,  t215,  t221,  t222,  t225,  t226,  t229,  t230;
double t231,  t232;


double a11 = cons[0];
double a12 = cons[1];
double a13 = cons[2];
double a14 = cons[3];
double a21 = cons[4];
double a22 = cons[5];
double a23 = cons[6];
double a24 = cons[7];
double a31 = cons[8];
double a32 = cons[9];
double a33 = cons[10];
double a34 = cons[11];
double b11 = cons[12];
double b12 = cons[13];
double b13 = cons[14];
double b14 = cons[15];
double b21 = cons[16];
double b22 = cons[17];
double b23 = cons[18];
double b24 = cons[19];
double b31 = cons[20];
double b32 = cons[21];
double b33 = cons[22];
double b34 = cons[23];

t1 = (double) a14 * (double) a14;
t2 = (double) a24 * (double) a24;
t3 = (double) a34 * (double) a34;
var1 = t1 + t2 + t3;
t5 =  ((double) a14 * (double) b34);
var2 = -2 * a23 * b12 - 2 * t5 - 2 * a32 * b21;
var3 = 2 * t5 - 2 * a23 * b21 - 2 * a32 * b12;
t12 =  ((double) a24 * (double) b34);
var4 = -2 * a31 * b21 + 2 * t12 - 2 * a13 * b12;
var5 = -2 * a31 * b12 - 2 * t12 - 2 * a13 * b21;
t20 =  ((double) a34 * (double) b34);
var6 = -2 * a21 * b21 - 2 * a12 * b12 - 2 * t20;
var7 = -2 * a21 * b12 - 2 * a12 * b21 + 2 * t20;
t25 = a21 * a21;
t26 =  ((double) a11 * (double) a11);
t27 =  ((double) b34 * (double) b34);
t28 = a31 * a31;
t29 =  ((double) b33 * (double) b33);
t30 =  ((double) b32 * (double) b32);
t31 =  ((double) a11 * (double) b33);
t33 =  ((double) b31 * (double) b31);
var8 = t25 + t26 + t27 + t28 + t29 + t30 - 2 * t31 + t33;
var9 = var8;
t34 =  ((double) a22 * (double) a22);
t35 = a32 * a32;
t36 =  ((double) a22 * (double) b33);
t38 = a12 * a12;
var10 = t34 + t29 + t33 + t35 - 2 * t36 + t27 + t30 + t38;
var11 = var10;
t39 = a23 * a23;
t40 = a13 * a13;
t41 =  ((double) a33 * (double) b33);
t43 =  ((double) a33 * (double) a33);
var12 = t39 + t27 + t33 + t40 + t29 + t30 - 2 * t41 + t43;
var13 = var12;
var14 = 2 * a21 * b31 + 2 * a12 * b13;
var15 = -2 * a21 * b32 - 2 * a12 * b23;
var16 = -2 * a21 * b13 - 2 * a12 * b31;
var17 = 2 * a21 * b23 + 2 * a12 * b32;
var18 = -2 * a31 * b31 - 2 * a13 * b13;
var19 = 2 * a13 * b23 + 2 * a31 * b32;
var20 = 2 * a31 * b13 + 2 * a13 * b31;
var21 = -2 * a31 * b23 - 2 * a13 * b32;
var22 = 2 * a32 * b31 + 2 * a23 * b13;
var23 = -2 * a23 * b23 - 2 * a32 * b32;
var24 = -2 * a23 * b31 - 2 * a32 * b13;
var25 = 2 * a32 * b23 + 2 * a23 * b32;
t80 = a21 * a22;
t82 = a11 * a12;
t83 = a31 * a32;
var26 = 2 * t80 - 2 * a12 * b11 + 2 * t82 + 2 * t83 - 2 * a21 * b11;
var27 = -2 * a12 * b22 + 2 * t80 + 2 * t83 + 2 * t82 - 2 * a21 * b22;
var28 = -2 * a21 + 2 * t80 + 2 * t82 - 2 * a12 + 2 * t83;
t90 = a11 * a13;
t91 = a21 * a23;
t92 = a31 * a33;
var29 = 2 * t90 + 2 * t91 + 2 * t92 - 2 * a13 * b11 - 2 * a31 * b11;
var30 = 2 * t91 + 2 * t90 - 2 * a31 * b22 + 2 * t92 - 2 * a13 * b22;
var31 = -2 * a13 + 2 * t90 - 2 * a31 + 2 * t91 + 2 * t92;
t100 =  ((double) b14 * (double) b24);
t103 = b13 * b23;
t104 = b11 * b21;
t105 = b12 * b22;
var32 = 2 * t100 - 2 * a11 * b12 - 2 * a11 * b21 + 2 * t103 + 2 * t104 + 2 * t105;
var33 = -2 * a11 * b14 + 2 * b14;
var34 = -2 * a11 * b24 + 2 * b24;
t111 = a32 * a33;
t113 = a22 * a23;
t114 = a12 * a13;
var35 = 2 * t111 - 2 * a32 * b11 + 2 * t113 + 2 * t114 - 2 * a23 * b11;
var36 = -2 * a23 * b22 + 2 * t111 - 2 * a32 * b22 + 2 * t113 + 2 * t114;
var37 = -2 * a23 - 2 * a32 + 2 * t111 + 2 * t114 + 2 * t113;
var38 = -2 * a12 * b14;
var39 = -2 * a12 * b24;
var40 = -2 * a13 * b14;
var41 = -2 * a13 * b24;
var42 = -2 * a21 * b14;
var43 = -2 * a21 * b24;
var44 = 2 * t100 + 2 * t104 + 2 * t103 - 2 * a22 * b12 - 2 * a22 * b21 + 2 * t105;
var45 = -2 * a22 * b14 + 2 * b14;
var46 = 2 * b24 - 2 * a22 * b24;
var47 = -2 * a23 * b14;
var48 = -2 * a23 * b24;
var49 = -2 * a31 * b14;
var50 = -2 * a31 * b24;
var51 = -2 * a32 * b14;
var52 = -2 * a32 * b24;
var53 = -2 * a33 * b21 - 2 * a33 * b12 + 2 * t103 + 2 * t105 + 2 * t104 + 2 * t100;
var54 = 2 * b14 - 2 * a33 * b14;
var55 = -2 * a33 * b24 + 2 * b24;
t159 = 2 * t30;
t160 = 2 * t33;
t162 = 2 * t27;
t163 = 2 * t29;
var56 = -t159 - t160 - 2 * t26 - t162 - t163 - 2 * t25 - 2 * t28 + 4 * t31;
var57 = 2 * a21 * b33 - 2 * t82 - 2 * t83 - 2 * t80 + 2 * a12 * b33;
var58 = var57;
var59 = 2 * a13 * b33 - 2 * t91 - 2 * t90 - 2 * t92 + 2 * a31 * b33;
var60 = var59;
var61 = -t160 - t162 - 2 * t38 - t163 + 4 * t36 - 2 * t35 - t159 - 2 * t34;
var62 = 2 * a23 * b33 - 2 * t114 - 2 * t111 - 2 * t113 + 2 * a32 * b33;
var63 = var62;
var64 = -2 * t39 - t162 - t160 - t163 - t159 - 2 * t40 + 4 * t41 - 2 * t43;
t184 = a11 * b13;
t185 = a22 * b31;
t186 = a22 * b13;
t187 = a11 * b31;
var65 = -2 * t184 + 2 * t185 + 2 * t186 - 2 * t187;
t189 = a33 * b31;
t190 = a33 * b13;
var66 = 2 * t187 - 2 * t189 - 2 * t190 + 2 * t184;
t192 = a33 * b32;
t193 = a33 * b23;
t194 = a11 * b32;
t195 = a11 * b23;
var67 = 2 * t192 + 2 * t193 - 2 * t194 - 2 * t195;
t197 = a22 * b32;
t198 = a22 * b23;
var68 = 2 * t195 + 2 * t194 - 2 * t197 - 2 * t198;
var69 = -2 * a11 * b34 + 2 * b34;
var70 = -var69;
var71 = -var14;
var72 = -var15;
var73 = -var16;
var74 = -var17;
t203 = 2 * a12 * b34;
var75 = -t203;
var76 = t203;
var77 = -var18;
var78 = -var19;
var79 = -var20;
var80 = -var21;
t205 = 2 * a13 * b34;
var81 = -t205;
var82 = t205;
var83 = 2 * a21 * b34;
var84 = -var83;
var85 = 2 * t189 - 2 * t185 - 2 * t186 + 2 * t190;
var86 = 2 * t197 - 2 * t192 - 2 * t193 + 2 * t198;
var87 = 2 * a22 * b34 - 2 * b34;
var88 = -var87;
var89 = -var22;
var90 = -var23;
var91 = -var24;
var92 = -var25;
var93 = 2 * a23 * b34;
var94 = -var93;
t213 = 2 * a31 * b34;
var95 = -t213;
var96 = t213;
t215 = 2 * a32 * b34;
var97 = -t215;
var98 = t215;
var99 = -2 * a33 * b34 + 2 * b34;
var100 = -var99;
var101 = -var58;
var102 = var101;
var103 = -var60;
var104 = var103;
var105 = -var63;
var106 = var105;
var107 = 1 + t25 - 2 * a11 + t26 + t28;
var108 = t35 + 1 - 2 * a22 + t34 + t38;
var109 = t43 - 2 * a33 + t40 + t39 + 1;
t221 = b12 * b12;
t222 = b13 * b13;
t225 = b14 * b14;
t226 = b11 * b11;
var110 = t221 + t25 + t222 + t26 - 2 * a11 * b11 + t225 + t226 + t28;
t229 = b23 * b23;
t230 = b24 * b24;
t231 = b21 * b21;
t232 = b22 * b22;
var111 = -2 * a11 * b22 + t229 + t230 + t231 + t26 + t232 + t25 + t28;
var112 = t38 + t226 + t35 + t225 + t221 + t34 + t222 - 2 * a22 * b11;
var113 = t35 + t34 - 2 * a22 * b22 + t231 + t232 + t230 + t38 + t229;
var114 = t39 - 2 * a33 * b11 + t221 + t40 + t225 + t43 + t222 + t226;
var115 = t43 + t230 + t40 + t232 + t39 + t229 - 2 * a33 * b22 + t231;
var116 = -2 * a14 * b14;
var117 = -2 * a24 * b14;
var118 = -2 * a34 * b14;
var119 = -2 * a14 * b24;
var120 = -2 * a34 * b24;
var121 = -2 * a24 * b24;
var122 = -2 * a14 + 2 * a11 * a14 + 2 * a21 * a24 + 2 * a31 * a34;
var123 = -2 * a24 + 2 * a32 * a34 + 2 * a12 * a14 + 2 * a22 * a24;
var124 = 2 * a13 * a14 - 2 * a34 + 2 * a33 * a34 + 2 * a23 * a24;


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

}
