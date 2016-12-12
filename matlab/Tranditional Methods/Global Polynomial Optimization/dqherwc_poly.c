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

  plhs[0] = mxCreateDoubleMatrix(112, 1,mxREAL);

  cons = mxGetPr(prhs[0]);
  vars = mxGetPr(plhs[0]);

  poly(cons, vars);
}

void poly(double *cons, double *vars)
{
/* Monomials: 112
    qx1^2
    qx2^2
    qx3^2
    qx4^2
    qz1^2
    qz2^2
    qz3^2
    qz4^2
    qx5^2
    qx6^2
    qx7^2
    qx8^2
    qz5^2
    qz6^2
    qz7^2
    qz8^2
    qz2*qx1
    qz1*qx1
    qz4*qx1
    qz3*qx1
    qx5*qx1
    qx6*qx1
    qx7*qx1
    qx8*qx1
    qz5*qx1
    qz6*qx1
    qz7*qx1
    qz8*qx1
    qz1*qx2
    qz2*qx2
    qz3*qx2
    qz4*qx2
    qx5*qx2
    qx6*qx2
    qx7*qx2
    qx8*qx2
    qz4*qx3
    qz1*qx3
    qz3*qx3
    qz2*qx3
    qx5*qx3
    qx8*qx3
    qx6*qx3
    qx7*qx3
    qz3*qx4
    qz1*qx4
    qz4*qx4
    qz2*qx4
    qx5*qx4
    qx7*qx4
    qx6*qx4
    qx8*qx4
    qz6*qx5
    qz5*qx6
    qz8*qx7
    qz7*qx8
    qx5*qz1
    qx6*qz1
    qx7*qz1
    qx8*qz1
    qz5*qx5
    qz6*qx6
    qz7*qx7
    qz8*qx8
    qx5*qz2
    qx6*qz2
    qx7*qz2
    qx8*qz2
    qz8*qx5
    qz7*qx6
    qz6*qx7
    qz5*qx8
    qx5*qz3
    qx6*qz3
    qx7*qz3
    qx8*qz3
    qz7*qx5
    qz8*qx6
    qz5*qx7
    qz6*qx8
    qx5*qz4
    qx6*qz4
    qx7*qz4
    qx8*qz4
    qz6*qx2
    qz5*qx2
    qz8*qx2
    qz7*qx2
    qz7*qx3
    qz8*qx3
    qz5*qx3
    qz6*qx3
    qz8*qx4
    qz7*qx4
    qz6*qx4
    qz5*qx4
    qz5*qz1
    qz6*qz1
    qz7*qz1
    qz8*qz1
    qz5*qz2
    qz6*qz2
    qz7*qz2
    qz8*qz2
    qz5*qz3
    qz7*qz3
    qz6*qz3
    qz8*qz3
    qz5*qz4
    qz8*qz4
    qz6*qz4
    qz7*qz4
*/

/* Variables: 112 */
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
double var112;

/* Temporary Variables: 80 */
double t1,  t2,  t3,  t4,  t5,  t6,  t7,  t8,  t9,  t10,  t11;
double t12,  t13,  t14,  t15,  t16,  t17,  t18,  t19,  t20,  t21;
double t22,  t23,  t24,  t26,  t27,  t28,  t29,  t30,  t31,  t32;
double t33,  t35,  t36,  t37,  t38,  t39,  t40,  t41,  t42,  t44;
double t45,  t46,  t47,  t48,  t49,  t50,  t51,  t73,  t74,  t75;
double t76,  t78,  t79,  t80,  t81,  t83,  t84,  t85,  t86,  t88;
double t89,  t90,  t91,  t109,  t110,  t111,  t112,  t114,  t115,  t116;
double t117,  t119,  t120,  t121,  t122,  t124,  t125,  t126,  t127;


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

t1 = (double) qa2 * (double) qa2;
t2 = (double) qa3 * (double) qa3;
t3 = (double) qa4 * (double) qa4;
t4 = (double) qa5 * (double) qa5;
t5 = (double) qa6 * (double) qa6;
t6 = (double) qa7 * (double) qa7;
t7 = (double) qa8 * (double) qa8;
t8 = (double) qa1 * (double) qa1;
var1 = t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8;
var2 = var1;
var3 = var2;
var4 = var3;
t9 = (double) qb5 * (double) qb5;
t10 = (double) qb1 * (double) qb1;
t11 = (double) qb8 * (double) qb8;
t12 = (double) qb6 * (double) qb6;
t13 = (double) qb4 * (double) qb4;
t14 = (double) qb3 * (double) qb3;
t15 = (double) qb2 * (double) qb2;
t16 = (double) qb7 * (double) qb7;
var5 = t9 + t10 + t11 + t12 + t13 + t14 + t15 + t16;
var6 = var5;
var7 = var6;
var8 = var7;
var9 = t2 + t1 + t3 + t8;
var10 = var9;
var11 = var10;
var12 = var11;
var13 = t13 + t15 + t10 + t14;
var14 = var13;
var15 = var14;
var16 = var15;
t17 =  ((double) qa4 * (double) qb3);
t18 =  ((double) qa7 * (double) qb8);
t19 =  ((double) qa8 * (double) qb7);
t20 =  ((double) qb2 * (double) qa1);
t21 =  ((double) qa6 * (double) qb5);
t22 =  ((double) qa3 * (double) qb4);
t23 =  ((double) qa2 * (double) qb1);
t24 =  ((double) qa5 * (double) qb6);
var17 = -2 * t17 + 2 * t18 - 2 * t19 + 2 * t20 - 2 * t21 + 2 * t22 - 2 * t23 + 2 * t24;
t26 =  ((double) qa3 * (double) qb3);
t27 =  ((double) qa5 * (double) qb5);
t28 =  ((double) qa4 * (double) qb4);
t29 =  ((double) qa8 * (double) qb8);
t30 =  ((double) qa6 * (double) qb6);
t31 =  ((double) qb1 * (double) qa1);
t32 =  ((double) qa2 * (double) qb2);
t33 =  ((double) qa7 * (double) qb7);
var18 = -2 * t26 - 2 * t27 - 2 * t28 - 2 * t29 - 2 * t30 - 2 * t31 - 2 * t32 - 2 * t33;
t35 =  ((double) qa5 * (double) qb8);
t36 =  ((double) qa6 * (double) qb7);
t37 =  ((double) qa7 * (double) qb6);
t38 =  ((double) qb4 * (double) qa1);
t39 =  ((double) qa3 * (double) qb2);
t40 =  ((double) qa2 * (double) qb3);
t41 =  ((double) qa8 * (double) qb5);
t42 =  ((double) qa4 * (double) qb1);
var19 = 2 * t35 + 2 * t36 - 2 * t37 + 2 * t38 - 2 * t39 + 2 * t40 - 2 * t41 - 2 * t42;
t44 =  ((double) qa2 * (double) qb4);
t45 =  ((double) qa3 * (double) qb1);
t46 =  ((double) qa5 * (double) qb7);
t47 =  ((double) qa6 * (double) qb8);
t48 =  ((double) qa8 * (double) qb6);
t49 =  ((double) qb3 * (double) qa1);
t50 =  ((double) qa4 * (double) qb2);
t51 =  ((double) qa7 * (double) qb5);
var20 = -2 * t44 - 2 * t45 + 2 * t46 - 2 * t47 + 2 * t48 + 2 * t49 + 2 * t50 - 2 * t51;
var21 = 2 * qa5 * qa1 + 2 * qa4 * qa8 + 2 * qa2 * qa6 + 2 * qa3 * qa7;
var22 = -2 * qa2 * qa5 - 2 * qa3 * qa8 + 2 * qa4 * qa7 + 2 * qa6 * qa1;
var23 = 2 * qa2 * qa8 - 2 * qa4 * qa6 - 2 * qa3 * qa5 + 2 * qa7 * qa1;
var24 = 2 * qa3 * qa6 - 2 * qa2 * qa7 + 2 * qa8 * qa1 - 2 * qa4 * qa5;
t73 = qb4 * qa8;
t74 = qb3 * qa7;
t75 = qb2 * qa6;
t76 = qb1 * qa5;
var25 = -2 * t73 - 2 * t74 - 2 * t75 - 2 * t76;
t78 = qb4 * qa7;
t79 = qb2 * qa5;
t80 = qb3 * qa8;
t81 = qb1 * qa6;
var26 = 2 * t78 + 2 * t79 - 2 * t80 - 2 * t81;
t83 = qb3 * qa5;
t84 = qb4 * qa6;
t85 = qb1 * qa7;
t86 = qb2 * qa8;
var27 = 2 * t83 - 2 * t84 - 2 * t85 + 2 * t86;
t88 = qb3 * qa6;
t89 = qb1 * qa8;
t90 = qb4 * qa5;
t91 = qb2 * qa7;
var28 = 2 * t88 - 2 * t89 + 2 * t90 - 2 * t91;
var29 = -2 * t20 - 2 * t19 - 2 * t17 + 2 * t23 + 2 * t21 + 2 * t18 - 2 * t24 + 2 * t22;
var30 = -2 * t27 + 2 * t29 - 2 * t31 + 2 * t33 - 2 * t32 + 2 * t28 + 2 * t26 - 2 * t30;
var31 = -2 * t38 - 2 * t36 - 2 * t35 - 2 * t37 - 2 * t40 - 2 * t41 - 2 * t42 - 2 * t39;
var32 = -2 * t48 + 2 * t51 - 2 * t50 - 2 * t47 + 2 * t46 + 2 * t45 + 2 * t49 - 2 * t44;
var33 = -var22;
var34 = var21;
var35 = var24;
var36 = -var23;
var37 = -2 * t20 - 2 * t19 - 2 * t18 - 2 * t17 - 2 * t23 - 2 * t22 - 2 * t21 - 2 * t24;
var38 = -2 * t44 + 2 * t48 - 2 * t46 + 2 * t51 - 2 * t47 + 2 * t45 + 2 * t50 - 2 * t49;
var39 = 2 * t30 - 2 * t27 - 2 * t26 + 2 * t32 + 2 * t28 - 2 * t33 - 2 * t31 + 2 * t29;
var40 = -2 * t36 + 2 * t35 + 2 * t41 + 2 * t42 - 2 * t37 - 2 * t40 - 2 * t39 + 2 * t38;
var41 = var36;
var42 = var22;
var43 = -var35;
var44 = var34;
var45 = 2 * t24 - 2 * t19 + 2 * t23 - 2 * t22 - 2 * t17 + 2 * t20 + 2 * t21 - 2 * t18;
var46 = 2 * t41 + 2 * t40 - 2 * t37 - 2 * t38 - 2 * t35 - 2 * t39 + 2 * t36 + 2 * t42;
var47 = -2 * t29 + 2 * t32 - 2 * t28 - 2 * t27 + 2 * t33 - 2 * t31 + 2 * t26 + 2 * t30;
var48 = -2 * t44 - 2 * t49 - 2 * t46 - 2 * t47 - 2 * t48 - 2 * t50 - 2 * t45 - 2 * t51;
var49 = var43;
var50 = var33;
var51 = var23;
var52 = var44;
var53 = 2 * t22 + 2 * t20 - 2 * t23 - 2 * t17;
var54 = -2 * t17 + 2 * t22 + 2 * t23 - 2 * t20;
var55 = -2 * t17 - 2 * t20 - 2 * t23 - 2 * t22;
var56 = 2 * t23 + 2 * t20 - 2 * t17 - 2 * t22;
t109 = qa2 * qb6;
t110 = qb5 * qa1;
t111 = qa3 * qb7;
t112 = qa4 * qb8;
var57 = -2 * t109 - 2 * t110 - 2 * t111 - 2 * t112;
t114 = qa3 * qb8;
t115 = qa2 * qb5;
t116 = qb6 * qa1;
t117 = qa4 * qb7;
var58 = 2 * t114 + 2 * t115 - 2 * t116 - 2 * t117;
t119 = qa2 * qb8;
t120 = qb7 * qa1;
t121 = qa3 * qb5;
t122 = qa4 * qb6;
var59 = -2 * t119 - 2 * t120 + 2 * t121 + 2 * t122;
t124 = qa4 * qb5;
t125 = qa2 * qb7;
t126 = qa3 * qb6;
t127 = qb8 * qa1;
var60 = 2 * t124 + 2 * t125 - 2 * t126 - 2 * t127;
var61 = -2 * t31 - 2 * t26 - 2 * t32 - 2 * t28;
var62 = 2 * t26 + 2 * t28 - 2 * t31 - 2 * t32;
var63 = -2 * t31 - 2 * t26 + 2 * t28 + 2 * t32;
var64 = 2 * t26 - 2 * t28 + 2 * t32 - 2 * t31;
var65 = -2 * t117 + 2 * t116 - 2 * t115 + 2 * t114;
var66 = 2 * t112 + 2 * t111 - 2 * t110 - 2 * t109;
var67 = -2 * t126 + 2 * t124 - 2 * t125 + 2 * t127;
var68 = -2 * t122 - 2 * t119 - 2 * t120 - 2 * t121;
var69 = -2 * t39 + 2 * t40 + 2 * t38 - 2 * t42;
var70 = -2 * t38 - 2 * t39 - 2 * t40 - 2 * t42;
var71 = -2 * t39 + 2 * t38 + 2 * t42 - 2 * t40;
var72 = 2 * t42 - 2 * t39 + 2 * t40 - 2 * t38;
var73 = 2 * t120 - 2 * t121 - 2 * t119 + 2 * t122;
var74 = -2 * t125 - 2 * t127 - 2 * t124 - 2 * t126;
var75 = 2 * t112 - 2 * t111 + 2 * t109 - 2 * t110;
var76 = 2 * t115 - 2 * t114 + 2 * t116 - 2 * t117;
var77 = 2 * t49 - 2 * t45 + 2 * t50 - 2 * t44;
var78 = -2 * t50 - 2 * t44 + 2 * t45 + 2 * t49;
var79 = 2 * t45 - 2 * t44 - 2 * t49 + 2 * t50;
var80 = -2 * t49 - 2 * t50 - 2 * t45 - 2 * t44;
var81 = 2 * t125 - 2 * t124 - 2 * t126 + 2 * t127;
var82 = -2 * t122 + 2 * t120 - 2 * t119 + 2 * t121;
var83 = -2 * t116 - 2 * t114 - 2 * t117 - 2 * t115;
var84 = -2 * t112 + 2 * t109 + 2 * t111 - 2 * t110;
var85 = -2 * t76 + 2 * t73 - 2 * t75 + 2 * t74;
var86 = 2 * t78 + 2 * t81 - 2 * t80 - 2 * t79;
var87 = 2 * t83 + 2 * t85 - 2 * t84 - 2 * t86;
var88 = -2 * t90 - 2 * t89 - 2 * t91 - 2 * t88;
var89 = 2 * t75 - 2 * t76 + 2 * t73 - 2 * t74;
var90 = -2 * t78 - 2 * t81 - 2 * t79 - 2 * t80;
var91 = -2 * t84 + 2 * t85 + 2 * t86 - 2 * t83;
var92 = 2 * t90 - 2 * t91 + 2 * t89 - 2 * t88;
var93 = -2 * t73 - 2 * t76 + 2 * t75 + 2 * t74;
var94 = 2 * t79 + 2 * t81 - 2 * t78 - 2 * t80;
var95 = -2 * t85 - 2 * t83 - 2 * t86 - 2 * t84;
var96 = 2 * t89 + 2 * t88 - 2 * t90 - 2 * t91;
var97 = 2 * qb2 * qb6 + 2 * qb1 * qb5 + 2 * qb4 * qb8 + 2 * qb3 * qb7;
var98 = -2 * qb4 * qb7 - 2 * qb2 * qb5 + 2 * qb3 * qb8 + 2 * qb1 * qb6;
var99 = 2 * qb1 * qb7 + 2 * qb4 * qb6 - 2 * qb3 * qb5 - 2 * qb2 * qb8;
var100 = -2 * qb4 * qb5 + 2 * qb2 * qb7 + 2 * qb1 * qb8 - 2 * qb3 * qb6;
var101 = -var98;
var102 = var97;
var103 = -var100;
var104 = var99;
var105 = -var104;
var106 = var102;
var107 = var100;
var108 = var101;
var109 = var103;
var110 = var106;
var111 = var105;
var112 = var98;


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

}
