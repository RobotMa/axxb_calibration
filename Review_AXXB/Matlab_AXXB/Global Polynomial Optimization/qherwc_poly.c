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

  plhs[0] = mxCreateDoubleMatrix(209, 1,mxREAL);

  cons = mxGetPr(prhs[0]);
  vars = mxGetPr(plhs[0]);

  poly(cons, vars);
}

void poly(double *cons, double *vars)
{
/* Monomials: 209
    1
    tx1*qz4*qz1
    tx1*qz3*qz2
    tx1*qz3*qz1
    tx1*qz4*qz2
    tx2*qz4*qz1
    tx2*qz3*qz2
    tx2*qz3*qz1
    tx2*qz4*qz2
    tx3*qz4*qz1
    tx3*qz3*qz2
    tx3*qz3*qz1
    tx3*qz4*qz2
    tx1*qz2*qz1
    tx1*qz4*qz3
    tz1
    tx1
    tx2
    tx3
    tz2
    tz3
    qz1*qz4
    qz2*qz3
    qz1*qz3
    qz2*qz4
    qz1*qz2
    qz3*qz4
    qz1^2*qx1^2
    qz2^2*qx1^2
    qz3^2*qx1^2
    qz4^2*qx1^2
    qz1^2*qx2^2
    qz2^2*qx2^2
    qz3^2*qx2^2
    qz4^2*qx2^2
    qz1^2*qx3^2
    qz2^2*qx3^2
    qz3^2*qx3^2
    qz4^2*qx3^2
    qz1^2*qx4^2
    qz2^2*qx4^2
    qz3^2*qx4^2
    qz4^2*qx4^2
    tx1*qz1^2
    tx1*qz2^2
    tx1*qz3^2
    tx1*qz4^2
    tx2*qz1^2
    tx2*qz2^2
    tx2*qz3^2
    tx2*qz4^2
    tx3*qz1^2
    tx3*qz2^2
    tx3*qz3^2
    tx3*qz4^2
    tx2*tx1
    tx3*tx1
    tx3*tx2
    qz1^2*qx4*qx1
    qz2^2*qx4*qx1
    qz3^2*qx4*qx1
    qz4^2*qx4*qx1
    qz1^2*qx3*qx2
    qz2^2*qx3*qx2
    qz3^2*qx3*qx2
    qz4^2*qx3*qx2
    qz1^2*qx3*qx1
    qz2^2*qx3*qx1
    qz3^2*qx3*qx1
    qz4^2*qx3*qx1
    qz1^2*qx4*qx2
    qz2^2*qx4*qx2
    qz3^2*qx4*qx2
    qz4^2*qx4*qx2
    qz4*qz1*qx1^2
    qz3*qz2*qx1^2
    qz4*qz1*qx2^2
    qz3*qz2*qx2^2
    qz4*qz1*qx3^2
    qz3*qz2*qx3^2
    qz4*qz1*qx4^2
    qz3*qz2*qx4^2
    qz3*qz1*qx1^2
    qz4*qz2*qx1^2
    qz3*qz1*qx2^2
    qz4*qz2*qx2^2
    qz3*qz1*qx3^2
    qz4*qz2*qx3^2
    qz3*qz1*qx4^2
    qz4*qz2*qx4^2
    qz1^2*qx2*qx1
    qz2^2*qx2*qx1
    qz3^2*qx2*qx1
    qz4^2*qx2*qx1
    qz1^2*qx4*qx3
    qz2^2*qx4*qx3
    qz3^2*qx4*qx3
    qz4^2*qx4*qx3
    qz2*qz1*qx1^2
    qz4*qz3*qx1^2
    qz2*qz1*qx2^2
    qz4*qz3*qx2^2
    qz2*qz1*qx3^2
    qz4*qz3*qx3^2
    qz2*qz1*qx4^2
    qz4*qz3*qx4^2
    qz4*qz1*qx4*qx1
    qz3*qz2*qx4*qx1
    qz4*qz1*qx3*qx2
    qz3*qz2*qx3*qx2
    qz4*qz1*qx3*qx1
    qz3*qz2*qx3*qx1
    qz4*qz1*qx4*qx2
    qz3*qz2*qx4*qx2
    qz3*qz1*qx4*qx1
    qz4*qz2*qx4*qx1
    qz3*qz1*qx3*qx2
    qz4*qz2*qx3*qx2
    qz3*qz1*qx3*qx1
    qz4*qz2*qx3*qx1
    qz3*qz1*qx4*qx2
    qz4*qz2*qx4*qx2
    qz4*qz1*qx2*qx1
    qz3*qz2*qx2*qx1
    qz4*qz1*qx4*qx3
    qz3*qz2*qx4*qx3
    qz3*qz1*qx2*qx1
    qz4*qz2*qx2*qx1
    qz3*qz1*qx4*qx3
    qz4*qz2*qx4*qx3
    qz2*qz1*qx4*qx1
    qz4*qz3*qx4*qx1
    qz2*qz1*qx3*qx2
    qz4*qz3*qx3*qx2
    qz2*qz1*qx3*qx1
    qz4*qz3*qx3*qx1
    qz2*qz1*qx4*qx2
    qz4*qz3*qx4*qx2
    qz2*qz1*qx2*qx1
    qz4*qz3*qx2*qx1
    qz2*qz1*qx4*qx3
    qz4*qz3*qx4*qx3
    tz1^2
    tz2^2
    tz3^2
    qx1^4
    qx2^4
    qx3^4
    qx4^4
    tx1^2
    tx2^2
    tx3^2
    qz1^4
    qz2^4
    qz3^4
    qz4^4
    qx2^2*qx1^2
    qx3^2*qx1^2
    qx4^2*qx1^2
    qx3^2*qx2^2
    qx4^2*qx2^2
    qx4^2*qx3^2
    qz2^2*qz1^2
    qz3^2*qz1^2
    qz4^2*qz1^2
    qz3^2*qz2^2
    qz4^2*qz2^2
    qz4^2*qz3^2
    tz1*qz1^2
    tz1*qz2^2
    tz1*qz3^2
    tz1*qz4^2
    tz2*qz1^2
    tz2*qz2^2
    tz2*qz3^2
    tz2*qz4^2
    tz3*qz1^2
    tz3*qz2^2
    tz3*qz3^2
    tz3*qz4^2
    tz1*tx1
    tz1*tx2
    tz1*tx3
    tz2*tx1
    tz2*tx2
    tz2*tx3
    tz3*tx1
    tz3*tx2
    tz3*tx3
    tx2*qz2*qz1
    tx2*qz4*qz3
    tx3*qz2*qz1
    tx3*qz4*qz3
    tz3*qz3*qz1
    tz2*qz4*qz1
    tz2*qz3*qz2
    tz3*qz4*qz2
    tz3*qz2*qz1
    tz1*qz4*qz1
    tz1*qz3*qz2
    tz3*qz4*qz3
    tz2*qz2*qz1
    tz1*qz3*qz1
    tz1*qz4*qz2
    tz2*qz4*qz3
    qz1^2
    qz2^2
    qz3^2
    qz4^2
*/

/* Variables: 209 */
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
double var172,  var173,  var174,  var175,  var176,  var177,  var178,  var179,  var180,  var181;
double var182,  var183,  var184,  var185,  var186,  var187,  var188,  var189,  var190,  var191;
double var192,  var193,  var194,  var195,  var196,  var197,  var198,  var199,  var200,  var201;
double var202,  var203,  var204,  var205,  var206,  var207,  var208,  var209;

/* Temporary Variables: 143 */
double t1,  t2,  t3,  t4,  t5,  t8,  t9,  t12,  t13,  t16,  t17;
double t20,  t21,  t24,  t25,  t28,  t29,  t47,  t48,  t51,  t52;
double t55,  t56,  t59,  t60,  t61,  t62,  t63,  t64,  t65,  t66;
double t67,  t84,  t85,  t86,  t91,  t92,  t93,  t98,  t99,  t100;
double t117,  t118,  t119,  t120,  t121,  t122,  t131,  t132,  t133,  t134;
double t135,  t136,  t145,  t146,  t147,  t148,  t149,  t150,  t159,  t160;
double t161,  t162,  t163,  t164,  t173,  t174,  t175,  t176,  t177,  t178;
double t187,  t188,  t189,  t190,  t191,  t192,  t201,  t202,  t203,  t204;
double t209,  t210,  t211,  t212,  t217,  t218,  t219,  t220,  t225,  t226;
double t227,  t228,  t233,  t234,  t235,  t236,  t241,  t242,  t243,  t244;
double t249,  t250,  t251,  t252,  t257,  t258,  t259,  t260,  t265,  t266;
double t267,  t268,  t273,  t274,  t275,  t276,  t277,  t278,  t279,  t280;
double t281,  t282,  t283,  t284,  t285,  t286,  t287,  t288,  t289,  t290;
double t291,  t292,  t293,  t303,  t304,  t307,  t308,  t311,  t312,  t313;
double t314,  t315;


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
t4 =  ((double) a11 * (double) b24);
t5 =  ((double) a21 * (double) b14);
var2 = 4 * t4 - 4 * t5;
var3 = -4 * t4 - 4 * t5;
t8 =  ((double) a31 * (double) b14);
t9 =  ((double) a11 * (double) b34);
var4 = 4 * t8 - 4 * t9;
var5 = -4 * t9 - 4 * t8;
t12 =  ((double) a12 * (double) b24);
t13 =  ((double) a22 * (double) b14);
var6 = 4 * t12 - 4 * t13;
var7 = -4 * t13 - 4 * t12;
t16 =  ((double) a12 * (double) b34);
t17 =  ((double) a32 * (double) b14);
var8 = -4 * t16 + 4 * t17;
var9 = -4 * t17 - 4 * t16;
t20 =  ((double) a23 * (double) b14);
t21 =  ((double) a13 * (double) b24);
var10 = -4 * t20 + 4 * t21;
var11 = -4 * t21 - 4 * t20;
t24 =  ((double) a33 * (double) b14);
t25 =  ((double) a13 * (double) b34);
var12 = 4 * t24 - 4 * t25;
var13 = -4 * t24 - 4 * t25;
t28 =  ((double) a21 * (double) b34);
t29 =  ((double) a31 * (double) b24);
var14 = 4 * t28 - 4 * t29;
var15 = -4 * t28 - 4 * t29;
var16 = -2 * a14;
var17 = 2 * a31 * a34 + 2 * a21 * a24 + 2 * a11 * a14;
var18 = 2 * a32 * a34 + 2 * a12 * a14 + 2 * a22 * a24;
var19 = 2 * a13 * a14 + 2 * a33 * a34 + 2 * a23 * a24;
var20 = -2 * a24;
var21 = -2 * a34;
t47 = a24 * b14;
t48 = a14 * b24;
var22 = -4 * t47 + 4 * t48;
var23 = -4 * t47 - 4 * t48;
t51 = a34 * b14;
t52 = a14 * b34;
var24 = 4 * t51 - 4 * t52;
var25 = -4 * t52 - 4 * t51;
t55 = a34 * b24;
t56 = a24 * b34;
var26 = -4 * t55 + 4 * t56;
var27 = -4 * t56 - 4 * t55;
t59 = a23 * b23;
t60 = a11 * b11;
t61 = a12 * b12;
t62 = a32 * b32;
t63 = a21 * b21;
t64 = a33 * b33;
t65 = a13 * b13;
t66 = a31 * b31;
t67 = a22 * b22;
var28 = -2 * t59 - 2 * t60 - 2 * t61 - 2 * t62 - 2 * t63 - 2 * t64 - 2 * t65 - 2 * t66 - 2 * t67;
var29 = 2 * t63 + 2 * t67 - 2 * t65 - 2 * t61 - 2 * t60 + 2 * t64 + 2 * t62 + 2 * t66 + 2 * t59;
var30 = 2 * t64 + 2 * t60 - 2 * t67 + 2 * t65 + 2 * t66 + 2 * t62 - 2 * t63 - 2 * t59 + 2 * t61;
var31 = 2 * t60 + 2 * t63 + 2 * t61 + 2 * t59 + 2 * t67 + 2 * t65 - 2 * t62 - 2 * t66 - 2 * t64;
var32 = 2 * t61 - 2 * t63 + 2 * t62 - 2 * t66 + 2 * t65 + 2 * t59 + 2 * t64 - 2 * t60 + 2 * t67;
var33 = 2 * t66 + 2 * t61 - 2 * t64 + 2 * t63 + 2 * t65 - 2 * t67 - 2 * t60 - 2 * t59 - 2 * t62;
var34 = -2 * t65 + 2 * t67 - 2 * t61 + 2 * t60 + 2 * t59 - 2 * t63 - 2 * t64 + 2 * t66 - 2 * t62;
var35 = -2 * t66 - 2 * t65 + 2 * t63 - 2 * t67 - 2 * t61 + 2 * t60 - 2 * t59 + 2 * t62 + 2 * t64;
var36 = -2 * t61 + 2 * t66 - 2 * t67 + 2 * t59 + 2 * t65 + 2 * t60 + 2 * t63 - 2 * t62 + 2 * t64;
var37 = -2 * t61 + 2 * t60 - 2 * t66 + 2 * t65 + 2 * t67 - 2 * t59 + 2 * t62 - 2 * t63 - 2 * t64;
var38 = -2 * t65 - 2 * t60 + 2 * t59 + 2 * t62 - 2 * t67 + 2 * t61 + 2 * t63 - 2 * t64 - 2 * t66;
var39 = -2 * t59 - 2 * t60 - 2 * t65 + 2 * t67 + 2 * t61 - 2 * t62 + 2 * t64 + 2 * t66 - 2 * t63;
var40 = -2 * t59 + 2 * t61 + 2 * t60 - 2 * t65 - 2 * t64 + 2 * t67 + 2 * t62 + 2 * t63 + 2 * t66;
var41 = -2 * t67 - 2 * t65 + 2 * t61 - 2 * t63 - 2 * t62 + 2 * t64 + 2 * t60 - 2 * t66 + 2 * t59;
var42 = 2 * t67 - 2 * t61 - 2 * t62 - 2 * t66 + 2 * t64 + 2 * t63 - 2 * t59 - 2 * t60 + 2 * t65;
var43 = 2 * t65 + 2 * t59 + 2 * t62 - 2 * t61 - 2 * t60 - 2 * t64 - 2 * t63 - 2 * t67 + 2 * t66;
t84 = a31 * b34;
t85 = a11 * b14;
t86 = a21 * b24;
var44 = -2 * t84 - 2 * t85 - 2 * t86;
var45 = 2 * t84 + 2 * t86 - 2 * t85;
var46 = 2 * t85 - 2 * t86 + 2 * t84;
var47 = -2 * t84 + 2 * t86 + 2 * t85;
t91 = a22 * b24;
t92 = a12 * b14;
t93 = a32 * b34;
var48 = -2 * t91 - 2 * t92 - 2 * t93;
var49 = 2 * t91 - 2 * t92 + 2 * t93;
var50 = -2 * t91 + 2 * t92 + 2 * t93;
var51 = 2 * t92 - 2 * t93 + 2 * t91;
t98 = a13 * b14;
t99 = a33 * b34;
t100 = a23 * b24;
var52 = -2 * t98 - 2 * t99 - 2 * t100;
var53 = 2 * t99 + 2 * t100 - 2 * t98;
var54 = 2 * t99 - 2 * t100 + 2 * t98;
var55 = -2 * t99 + 2 * t100 + 2 * t98;
var56 = 2 * a31 * a32 + 2 * a11 * a12 + 2 * a21 * a22;
var57 = 2 * a21 * a23 + 2 * a11 * a13 + 2 * a31 * a33;
var58 = 2 * a32 * a33 + 2 * a12 * a13 + 2 * a22 * a23;
t117 = a11 * b12;
t118 = a22 * b21;
t119 = a12 * b11;
t120 = a21 * b22;
t121 = a32 * b31;
t122 = a31 * b32;
var59 = 4 * t117 - 4 * t118 - 4 * t119 + 4 * t120 - 4 * t121 + 4 * t122;
var60 = 4 * t118 + 4 * t117 - 4 * t120 + 4 * t121 - 4 * t122 - 4 * t119;
var61 = -4 * t117 - 4 * t118 + 4 * t120 - 4 * t122 + 4 * t119 + 4 * t121;
var62 = 4 * t119 - 4 * t120 + 4 * t118 - 4 * t117 + 4 * t122 - 4 * t121;
var63 = -4 * t119 - 4 * t120 - 4 * t121 - 4 * t117 - 4 * t122 - 4 * t118;
var64 = 4 * t121 - 4 * t117 + 4 * t122 + 4 * t118 - 4 * t119 + 4 * t120;
var65 = 4 * t121 + 4 * t117 + 4 * t119 + 4 * t122 - 4 * t120 - 4 * t118;
var66 = 4 * t117 + 4 * t119 - 4 * t122 + 4 * t120 + 4 * t118 - 4 * t121;
t131 = a11 * b13;
t132 = a23 * b21;
t133 = a33 * b31;
t134 = a21 * b23;
t135 = a13 * b11;
t136 = a31 * b33;
var67 = -4 * t131 + 4 * t132 + 4 * t133 - 4 * t134 + 4 * t135 - 4 * t136;
var68 = -4 * t132 - 4 * t133 + 4 * t135 + 4 * t134 - 4 * t131 + 4 * t136;
var69 = 4 * t131 - 4 * t133 - 4 * t134 + 4 * t136 + 4 * t132 - 4 * t135;
var70 = -4 * t136 - 4 * t135 + 4 * t131 + 4 * t133 + 4 * t134 - 4 * t132;
var71 = -4 * t136 - 4 * t135 - 4 * t134 - 4 * t133 - 4 * t131 - 4 * t132;
var72 = 4 * t133 - 4 * t135 - 4 * t131 + 4 * t132 + 4 * t136 + 4 * t134;
var73 = -4 * t132 + 4 * t135 + 4 * t133 + 4 * t131 + 4 * t136 - 4 * t134;
var74 = -4 * t133 + 4 * t131 + 4 * t134 - 4 * t136 + 4 * t135 + 4 * t132;
t145 = a11 * b21;
t146 = a21 * b11;
t147 = a12 * b22;
t148 = a22 * b12;
t149 = a23 * b13;
t150 = a13 * b23;
var75 = 4 * t145 - 4 * t146 + 4 * t147 - 4 * t148 - 4 * t149 + 4 * t150;
var76 = -4 * t146 - 4 * t148 - 4 * t147 - 4 * t145 - 4 * t149 - 4 * t150;
var77 = 4 * t148 - 4 * t147 - 4 * t150 + 4 * t149 + 4 * t145 - 4 * t146;
var78 = 4 * t149 + 4 * t147 + 4 * t150 + 4 * t148 - 4 * t145 - 4 * t146;
var79 = 4 * t147 + 4 * t146 - 4 * t145 - 4 * t148 + 4 * t149 - 4 * t150;
var80 = 4 * t149 + 4 * t145 - 4 * t148 + 4 * t146 + 4 * t150 - 4 * t147;
var81 = -4 * t149 - 4 * t145 - 4 * t147 + 4 * t150 + 4 * t148 + 4 * t146;
var82 = -4 * t150 + 4 * t147 - 4 * t149 + 4 * t148 + 4 * t145 + 4 * t146;
t159 = a31 * b11;
t160 = a32 * b12;
t161 = a13 * b33;
t162 = a33 * b13;
t163 = a11 * b31;
t164 = a12 * b32;
var83 = 4 * t159 + 4 * t160 - 4 * t161 + 4 * t162 - 4 * t163 - 4 * t164;
var84 = -4 * t163 - 4 * t159 - 4 * t162 - 4 * t164 - 4 * t160 - 4 * t161;
var85 = -4 * t160 - 4 * t163 + 4 * t161 - 4 * t162 + 4 * t164 + 4 * t159;
var86 = 4 * t162 + 4 * t164 + 4 * t160 - 4 * t159 - 4 * t163 + 4 * t161;
var87 = 4 * t160 + 4 * t161 - 4 * t164 - 4 * t162 + 4 * t163 - 4 * t159;
var88 = -4 * t160 - 4 * t164 + 4 * t162 + 4 * t161 + 4 * t163 + 4 * t159;
var89 = 4 * t162 + 4 * t163 - 4 * t159 + 4 * t164 - 4 * t161 - 4 * t160;
var90 = 4 * t160 - 4 * t162 + 4 * t163 + 4 * t159 + 4 * t164 - 4 * t161;
t173 = a12 * b13;
t174 = a32 * b33;
t175 = a23 * b22;
t176 = a22 * b23;
t177 = a33 * b32;
t178 = a13 * b12;
var91 = 4 * t173 + 4 * t174 - 4 * t175 + 4 * t176 - 4 * t177 - 4 * t178;
var92 = 4 * t175 - 4 * t176 + 4 * t173 + 4 * t177 - 4 * t174 - 4 * t178;
var93 = -4 * t174 + 4 * t177 - 4 * t175 - 4 * t173 + 4 * t176 + 4 * t178;
var94 = -4 * t173 + 4 * t175 - 4 * t176 - 4 * t177 + 4 * t178 + 4 * t174;
var95 = -4 * t176 - 4 * t178 - 4 * t177 - 4 * t173 - 4 * t175 - 4 * t174;
var96 = -4 * t178 - 4 * t173 + 4 * t177 + 4 * t176 + 4 * t174 + 4 * t175;
var97 = 4 * t177 - 4 * t176 - 4 * t175 + 4 * t173 + 4 * t178 + 4 * t174;
var98 = 4 * t176 + 4 * t173 - 4 * t177 + 4 * t175 - 4 * t174 + 4 * t178;
t187 = a22 * b32;
t188 = a21 * b31;
t189 = a32 * b22;
t190 = a33 * b23;
t191 = a23 * b33;
t192 = a31 * b21;
var99 = 4 * t187 + 4 * t188 - 4 * t189 - 4 * t190 + 4 * t191 - 4 * t192;
var100 = -4 * t190 - 4 * t192 - 4 * t188 - 4 * t187 - 4 * t191 - 4 * t189;
var101 = 4 * t189 - 4 * t192 + 4 * t188 + 4 * t190 - 4 * t187 - 4 * t191;
var102 = 4 * t190 + 4 * t191 - 4 * t188 + 4 * t189 - 4 * t192 + 4 * t187;
var103 = -4 * t189 + 4 * t192 + 4 * t190 - 4 * t191 - 4 * t188 + 4 * t187;
var104 = 4 * t192 + 4 * t190 + 4 * t191 - 4 * t187 + 4 * t188 - 4 * t189;
var105 = -4 * t190 - 4 * t187 + 4 * t191 + 4 * t189 - 4 * t188 + 4 * t192;
var106 = 4 * t187 + 4 * t192 - 4 * t190 - 4 * t191 + 4 * t189 + 4 * t188;
t201 = a21 * b12;
t202 = a22 * b11;
t203 = a11 * b22;
t204 = a12 * b21;
var107 = 8 * t201 - 8 * t202 - 8 * t203 + 8 * t204;
var108 = -8 * t202 + 8 * t201 - 8 * t204 + 8 * t203;
var109 = -8 * t201 + 8 * t204 + 8 * t203 - 8 * t202;
var110 = -8 * t201 - 8 * t204 - 8 * t202 - 8 * t203;
t209 = a23 * b11;
t210 = a13 * b21;
t211 = a21 * b13;
t212 = a11 * b23;
var111 = 8 * t209 - 8 * t210 - 8 * t211 + 8 * t212;
var112 = -8 * t212 + 8 * t210 - 8 * t211 + 8 * t209;
var113 = -8 * t211 + 8 * t210 - 8 * t209 + 8 * t212;
var114 = -8 * t211 - 8 * t209 - 8 * t210 - 8 * t212;
t217 = a31 * b12;
t218 = a11 * b32;
t219 = a32 * b11;
t220 = a12 * b31;
var115 = -8 * t217 + 8 * t218 + 8 * t219 - 8 * t220;
var116 = -8 * t220 + 8 * t217 - 8 * t219 + 8 * t218;
var117 = -8 * t218 + 8 * t217 + 8 * t219 - 8 * t220;
var118 = -8 * t218 - 8 * t217 - 8 * t219 - 8 * t220;
t225 = a33 * b11;
t226 = a31 * b13;
t227 = a11 * b33;
t228 = a13 * b31;
var119 = -8 * t225 + 8 * t226 - 8 * t227 + 8 * t228;
var120 = -8 * t226 - 8 * t227 + 8 * t228 + 8 * t225;
var121 = -8 * t227 + 8 * t225 + 8 * t226 - 8 * t228;
var122 = -8 * t227 - 8 * t228 - 8 * t226 - 8 * t225;
t233 = a22 * b13;
t234 = a23 * b12;
t235 = a12 * b23;
t236 = a13 * b22;
var123 = 8 * t233 - 8 * t234 - 8 * t235 + 8 * t236;
var124 = 8 * t233 - 8 * t236 - 8 * t234 + 8 * t235;
var125 = -8 * t234 + 8 * t236 - 8 * t233 + 8 * t235;
var126 = -8 * t233 - 8 * t234 - 8 * t236 - 8 * t235;
t241 = a32 * b13;
t242 = a12 * b33;
t243 = a33 * b12;
t244 = a13 * b32;
var127 = -8 * t241 + 8 * t242 + 8 * t243 - 8 * t244;
var128 = -8 * t243 + 8 * t241 - 8 * t244 + 8 * t242;
var129 = -8 * t242 + 8 * t243 + 8 * t241 - 8 * t244;
var130 = -8 * t244 - 8 * t243 - 8 * t241 - 8 * t242;
t249 = a31 * b22;
t250 = a32 * b21;
t251 = a21 * b32;
t252 = a22 * b31;
var131 = 8 * t249 - 8 * t250 - 8 * t251 + 8 * t252;
var132 = 8 * t249 - 8 * t252 - 8 * t250 + 8 * t251;
var133 = 8 * t252 - 8 * t250 + 8 * t251 - 8 * t249;
var134 = -8 * t249 - 8 * t251 - 8 * t250 - 8 * t252;
t257 = a31 * b23;
t258 = a33 * b21;
t259 = a23 * b31;
t260 = a21 * b33;
var135 = -8 * t257 + 8 * t258 - 8 * t259 + 8 * t260;
var136 = -8 * t257 + 8 * t259 + 8 * t258 - 8 * t260;
var137 = 8 * t259 - 8 * t258 + 8 * t260 - 8 * t257;
var138 = -8 * t259 - 8 * t257 - 8 * t260 - 8 * t258;
t265 = a33 * b22;
t266 = a32 * b23;
t267 = a23 * b32;
t268 = a22 * b33;
var139 = -8 * t265 + 8 * t266 + 8 * t267 - 8 * t268;
var140 = 8 * t266 + 8 * t268 - 8 * t267 - 8 * t265;
var141 = 8 * t268 + 8 * t267 - 8 * t266 - 8 * t265;
var142 = -8 * t265 - 8 * t267 - 8 * t268 - 8 * t266;
var143 = 1;
var144 = 1;
var145 = 1;
t273 = a11 * a11;
t274 = a32 * a32;
t275 = a13 * a13;
t276 = a22 * a22;
t277 = a33 * a33;
t278 = a12 * a12;
t279 = a23 * a23;
t280 = a31 * a31;
t281 = a21 * a21;
var146 = t273 + t274 + t275 + t276 + t277 + t278 + t279 + t280 + t281;
var147 = var146;
var148 = var147;
var149 = var148;
var150 = t281 + t280 + t273;
var151 = t274 + t278 + t276;
var152 = t275 + t277 + t279;
t282 = b11 * b11;
t283 = b21 * b21;
t284 = b34 * b34;
t285 = b12 * b12;
t286 = b23 * b23;
t287 = b13 * b13;
t288 = b22 * b22;
t289 = b24 * b24;
t290 = b33 * b33;
t291 = b32 * b32;
t292 = b31 * b31;
t293 = b14 * b14;
var153 = t282 + t283 + t284 + t285 + t286 + t287 + t288 + t289 + t290 + t291 + t292 + t293;
var154 = var153;
var155 = var154;
var156 = var155;
var157 = 2 * var149;
var158 = var157;
var159 = var158;
var160 = var159;
var161 = var160;
var162 = var161;
var163 = 2 * var156;
var164 = var163;
var165 = var164;
var166 = var165;
var167 = var166;
var168 = var167;
var169 = 2 * b14;
var170 = var169;
var171 = -var170;
var172 = var171;
var173 = 2 * b24;
var174 = -var173;
var175 = var173;
var176 = var174;
var177 = 2 * b34;
var178 = -var177;
var179 = var178;
var180 = var177;
var181 = -2 * a11;
var182 = -2 * a12;
var183 = -2 * a13;
var184 = -2 * a21;
var185 = -2 * a22;
var186 = -2 * a23;
var187 = -2 * a31;
var188 = -2 * a32;
var189 = -2 * a33;
t303 = a22 * b34;
t304 = a32 * b24;
var190 = 4 * t303 - 4 * t304;
var191 = -4 * t303 - 4 * t304;
t307 = a23 * b34;
t308 = a33 * b24;
var192 = 4 * t307 - 4 * t308;
var193 = -4 * t307 - 4 * t308;
t311 = 4 * b14;
var194 = -t311;
var195 = t311;
var196 = var195;
var197 = var196;
var198 = 4 * b24;
var199 = -var198;
var200 = var198;
var201 = var200;
t312 = 4 * b34;
var202 = -t312;
var203 = t312;
var204 = var203;
var205 = var204;
t313 = a34 * b34;
t314 = a24 * b24;
t315 = a14 * b14;
var206 = -2 * t313 - 2 * t314 - 2 * t315;
var207 = 2 * t314 + 2 * t313 - 2 * t315;
var208 = 2 * t313 - 2 * t314 + 2 * t315;
var209 = -2 * t313 + 2 * t315 + 2 * t314;


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
vars[177] = var178;
vars[178] = var179;
vars[179] = var180;
vars[180] = var181;
vars[181] = var182;
vars[182] = var183;
vars[183] = var184;
vars[184] = var185;
vars[185] = var186;
vars[186] = var187;
vars[187] = var188;
vars[188] = var189;
vars[189] = var190;
vars[190] = var191;
vars[191] = var192;
vars[192] = var193;
vars[193] = var194;
vars[194] = var195;
vars[195] = var196;
vars[196] = var197;
vars[197] = var198;
vars[198] = var199;
vars[199] = var200;
vars[200] = var201;
vars[201] = var202;
vars[202] = var203;
vars[203] = var204;
vars[204] = var205;
vars[205] = var206;
vars[206] = var207;
vars[207] = var208;
vars[208] = var209;

}
