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

  plhs[0] = mxCreateDoubleMatrix(85, 1,mxREAL);

  cons = mxGetPr(prhs[0]);
  vars = mxGetPr(plhs[0]);

  poly(cons, vars);
}

void poly(double *cons, double *vars)
{
/* Monomials: 85
    1
    qx3*qx2*qx1^2
    qx4*qx2^2*qx1
    qx4*qx3^2*qx1
    qx4^2*qx3*qx2
    qx4*qx2*qx1^2
    qx3*qx2^2*qx1
    qx4^2*qx3*qx1
    qx4*qx3^2*qx2
    qx4*qx3*qx1^2
    qx3^2*qx2*qx1
    qx4^2*qx2*qx1
    qx4*qx3*qx2^2
    tx1
    tx2
    tx3
    qx1*qx4
    qx2*qx3
    qx1*qx3
    qx2*qx4
    qx1*qx2
    qx3*qx4
    tx1*qx4*qx1
    tx1*qx3*qx2
    tx1*qx3*qx1
    tx1*qx4*qx2
    tx2*qx4*qx1
    tx2*qx3*qx2
    tx2*qx3*qx1
    tx2*qx4*qx2
    tx3*qx4*qx1
    tx3*qx3*qx2
    tx3*qx3*qx1
    tx3*qx4*qx2
    tx1*qx2*qx1
    tx1*qx4*qx3
    tx2*qx2*qx1
    tx2*qx4*qx3
    tx3*qx2*qx1
    tx3*qx4*qx3
    qx2^2*qx1^2
    qx3^2*qx1^2
    qx4^2*qx1^2
    qx3^2*qx2^2
    qx4^2*qx2^2
    qx4^2*qx3^2
    qx4*qx1^3
    qx4^3*qx1
    qx3*qx2^3
    qx3^3*qx2
    qx3*qx1^3
    qx3^3*qx1
    qx4*qx2^3
    qx4^3*qx2
    qx2*qx1^3
    qx2^3*qx1
    qx4*qx3^3
    qx4^3*qx3
    qx4*qx3*qx2*qx1
    tx1^2
    tx2^2
    tx3^2
    qx1^4
    qx2^4
    qx3^4
    qx4^4
    tx1*qx1^2
    tx1*qx2^2
    tx1*qx3^2
    tx1*qx4^2
    tx2*qx1^2
    tx2*qx2^2
    tx2*qx3^2
    tx2*qx4^2
    tx3*qx1^2
    tx3*qx2^2
    tx3*qx3^2
    tx3*qx4^2
    tx2*tx1
    tx3*tx1
    tx3*tx2
    qx1^2
    qx2^2
    qx3^2
    qx4^2
*/

/* Variables: 85 */
double var1,  var2,  var3,  var4,  var5,  var6,  var7,  var8,  var9,  var10,  var11;
double var12,  var13,  var14,  var15,  var16,  var17,  var18,  var19,  var20,  var21;
double var22,  var23,  var24,  var25,  var26,  var27,  var28,  var29,  var30,  var31;
double var32,  var33,  var34,  var35,  var36,  var37,  var38,  var39,  var40,  var41;
double var42,  var43,  var44,  var45,  var46,  var47,  var48,  var49,  var50,  var51;
double var52,  var53,  var54,  var55,  var56,  var57,  var58,  var59,  var60,  var61;
double var62,  var63,  var64,  var65,  var66,  var67,  var68,  var69,  var70,  var71;
double var72,  var73,  var74,  var75,  var76,  var77,  var78,  var79,  var80,  var81;
double var82,  var83,  var84,  var85;

/* Temporary Variables: 231 */
double t1,  t2,  t3,  t5,  t7,  t8,  t9,  t11,  t13,  t15,  t16;
double t17,  t18,  t19,  t20,  t21,  t22,  t23,  t25,  t26,  t27;
double t28,  t29,  t30,  t31,  t32,  t33,  t34,  t35,  t37,  t38;
double t39,  t41,  t42,  t43,  t45,  t46,  t47,  t49,  t51,  t52;
double t53,  t54,  t55,  t57,  t59,  t60,  t61,  t62,  t63,  t65;
double t66,  t67,  t68,  t69,  t70,  t71,  t73,  t74,  t75,  t76;
double t77,  t78,  t79,  t80,  t81,  t83,  t84,  t85,  t87,  t89;
double t90,  t91,  t93,  t94,  t95,  t96,  t97,  t99,  t101,  t103;
double t104,  t105,  t107,  t108,  t109,  t110,  t111,  t112,  t113,  t114;
double t115,  t116,  t117,  t119,  t120,  t121,  t122,  t123,  t136,  t137;
double t140,  t141,  t144,  t145,  t148,  t149,  t152,  t153,  t156,  t157;
double t160,  t161,  t164,  t165,  t168,  t169,  t172,  t173,  t176,  t177;
double t180,  t181,  t184,  t185,  t186,  t187,  t188,  t189,  t190,  t191;
double t192,  t193,  t195,  t196,  t197,  t199,  t200,  t201,  t202,  t203;
double t204,  t205,  t206,  t207,  t208,  t209,  t210,  t211,  t212,  t213;
double t214,  t215,  t216,  t217,  t218,  t219,  t220,  t221,  t222,  t223;
double t224,  t225,  t226,  t227,  t228,  t229,  t230,  t231,  t232,  t233;
double t234,  t235,  t236,  t237,  t239,  t240,  t241,  t243,  t244,  t245;
double t246,  t247,  t248,  t249,  t250,  t251,  t252,  t254,  t256,  t257;
double t258,  t259,  t260,  t261,  t262,  t263,  t264,  t265,  t266,  t267;
double t268,  t269,  t270,  t271,  t272,  t277,  t278,  t279,  t280,  t281;
double t282,  t283,  t284,  t285,  t286,  t287,  t288,  t289,  t290,  t291;
double t292,  t297,  t298,  t299,  t304,  t305,  t306,  t323,  t324,  t325;


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

t1 = (double) a24 * (double) a24;
t2 = (double) a34 * (double) a34;
t3 = (double) a14 * (double) a14;
var1 = t1 + t2 + t3;
t5 = 8 * a23 * b31;
t7 = 8 * a12 * b33;
t8 = a12 * b22;
t9 = 4 * t8;
t11 = 8 * a21 * b33;
t13 = 8 * a32 * b13;
t15 = 8 * a33 * b21;
t16 = a32 * b31;
t17 = 4 * t16;
t18 =  ((double) a31 * (double) b32);
t19 = 4 * t18;
t20 =  ((double) a22 * (double) b12);
t21 = 4 * t20;
t22 =  ((double) a13 * (double) b23);
t23 = 4 * t22;
t25 = 8 * a13 * b32;
t26 = a21 * b11;
t27 = 4 * t26;
t28 = a23 * b13;
t29 = 4 * t28;
t30 = a11 * b21;
t31 = 4 * t30;
t32 = a11 * b12;
t33 = 4 * t32;
t34 = a12 * b11;
t35 = 4 * t34;
t37 = 8 * a33 * b12;
t38 = a21 * b22;
t39 = 4 * t38;
t41 = 8 * a31 * b23;
t42 = a22 * b21;
t43 = 4 * t42;
var2 = -t5 + t7 - t9 + t11 - t13 + t15 - t17 - t19 - t21 - t23 - t25 - t27 - t29 - t31 - t33 - t35 + t37 - t39 - t41 - t43;
var3 = -t25 + t29 - t15 - t23 - t35 + t11 - t37 - t41 + t7 - t27 + t13 - t39 + t33 + t5 + t17 + t43 + t31 - t19 - t9 + t21;
var4 = t37 - t41 + t27 + t17 - t43 + t29 - t25 + t15 + t5 - t11 - t31 - t7 + t35 - t21 - t19 - t23 + t9 - t33 + t39 + t13;
var5 = t43 + t31 - t25 + t35 - t15 - t19 - t37 + t21 - t11 + t9 - t23 - t7 + t33 - t17 + t27 - t5 + t39 - t41 - t13 - t29;
t45 = 8 * a22 * b13;
t46 = a11 * b13;
t47 = 4 * t46;
t49 = 8 * a23 * b12;
t51 = 8 * a13 * b22;
t52 = a13 * b33;
t53 = 4 * t52;
t54 = a13 * b11;
t55 = 4 * t54;
t57 = 8 * a31 * b22;
t59 = 8 * a12 * b23;
t60 = a21 * b23;
t61 = 4 * t60;
t62 = a31 * b33;
t63 = 4 * t62;
t65 = 8 * a22 * b31;
t66 = a31 * b11;
t67 = 4 * t66;
t68 = a33 * b13;
t69 = 4 * t68;
t70 = a12 * b32;
t71 = 4 * t70;
t73 = 8 * a21 * b32;
t74 = a32 * b12;
t75 = 4 * t74;
t76 = a11 * b31;
t77 = 4 * t76;
t78 = a23 * b21;
t79 = 4 * t78;
t80 = a33 * b31;
t81 = 4 * t80;
t83 = 8 * a32 * b21;
var6 = t45 - t47 - t49 + t51 - t53 - t55 + t57 - t59 - t61 - t63 + t65 - t67 - t69 - t71 - t73 - t75 - t77 - t79 - t81 - t83;
var7 = t45 + t61 + t55 + t63 + t73 - t77 - t51 - t49 - t57 + t71 - t69 + t59 - t75 + t67 - t83 + t53 - t47 - t79 + t65 - t81;
var8 = -t63 - t67 + t77 - t45 + t47 + t57 + t61 + t71 - t75 + t51 + t73 - t49 + t69 + t59 - t53 - t79 + t81 - t55 - t65 - t83;
var9 = -t61 - t59 + t47 - t45 + t77 - t83 - t75 - t79 - t57 - t51 - t65 + t63 - t71 - t49 + t53 + t81 + t69 - t73 + t67 + t55;
t84 = a22 * b32;
t85 = 4 * t84;
t87 = 8 * a21 * b13;
t89 = 8 * a11 * b32;
t90 = a23 * b22;
t91 = 4 * t90;
t93 = 8 * a13 * b21;
t94 = a23 * b33;
t95 = 4 * t94;
t96 = a32 * b33;
t97 = 4 * t96;
t99 = 8 * a12 * b31;
t101 = 8 * a32 * b11;
t103 = 8 * a23 * b11;
t104 = a21 * b31;
t105 = 4 * t104;
t107 = 8 * a31 * b12;
t108 = a33 * b23;
t109 = 4 * t108;
t110 = a22 * b23;
t111 = 4 * t110;
t112 = a33 * b32;
t113 = 4 * t112;
t114 = a32 * b22;
t115 = 4 * t114;
t116 = a12 * b13;
t117 = 4 * t116;
t119 = 8 * a11 * b23;
t120 = a13 * b12;
t121 = 4 * t120;
t122 = a31 * b21;
t123 = 4 * t122;
var10 = -t85 - t87 + t89 - t91 - t93 - t95 - t97 - t99 + t101 + t103 - t105 - t107 - t109 - t111 - t113 - t115 - t117 + t119 - t121 - t123;
var11 = t123 + t113 - t91 + t121 + t109 + t111 - t115 + t85 - t95 + t93 - t87 - t89 + t103 + t107 + t101 - t119 - t99 - t117 - t97 - t105;
var12 = -t109 + t121 - t117 - t113 - t111 + t91 + t97 + t107 + t95 + t93 - t99 - t103 - t85 + t123 - t87 - t101 + t115 + t119 - t105 + t89;
var13 = -t93 - t107 + t109 - t105 - t101 + t111 + t97 - t117 - t99 + t85 + t113 - t121 - t103 - t87 + t91 - t119 - t123 - t89 + t115 + t95;
var14 = -2 * a14 + 2 * a31 * a34 + 2 * a21 * a24 + 2 * a11 * a14;
var15 = 2 * a22 * a24 + 2 * a12 * a14 - 2 * a24 + 2 * a32 * a34;
var16 = 2 * a13 * a14 + 2 * a33 * a34 - 2 * a34 + 2 * a23 * a24;
t136 = a14 * b24;
t137 = a24 * b14;
var17 = 4 * t136 - 4 * t137;
var18 = -4 * t137 - 4 * t136;
t140 = a14 * b34;
t141 = a34 * b14;
var19 = -4 * t140 + 4 * t141;
var20 = -4 * t141 - 4 * t140;
t144 = a34 * b24;
t145 = a24 * b34;
var21 = -4 * t144 + 4 * t145;
var22 = -4 * t145 - 4 * t144;
t148 = a21 * b14;
t149 = a11 * b24;
var23 = -4 * b24 - 4 * t148 + 4 * t149;
var24 = 4 * b24 - 4 * t149 - 4 * t148;
t152 = a31 * b14;
t153 = a11 * b34;
var25 = 4 * b34 + 4 * t152 - 4 * t153;
var26 = 4 * b34 - 4 * t153 - 4 * t152;
t156 = a22 * b14;
t157 = a12 * b24;
var27 = 4 * b14 - 4 * t156 + 4 * t157;
var28 = -4 * t156 - 4 * t157 + 4 * b14;
t160 = a32 * b14;
t161 = a12 * b34;
var29 = 4 * t160 - 4 * t161;
var30 = -4 * t161 - 4 * t160;
t164 = a13 * b24;
t165 = a23 * b14;
var31 = 4 * t164 - 4 * t165;
var32 = -4 * t164 - 4 * t165;
t168 = a33 * b14;
t169 = a13 * b34;
var33 = 4 * t168 - 4 * t169 - 4 * b14;
var34 = -4 * t169 - 4 * t168 + 4 * b14;
t172 = a31 * b24;
t173 = a21 * b34;
var35 = -4 * t172 + 4 * t173;
var36 = -4 * t172 - 4 * t173;
t176 = a22 * b34;
t177 = a32 * b24;
var37 = 4 * t176 - 4 * t177 - 4 * b34;
var38 = 4 * b34 - 4 * t176 - 4 * t177;
t180 = a23 * b34;
t181 = a33 * b24;
var39 = 4 * t180 - 4 * t181 + 4 * b24;
var40 = -4 * t181 + 4 * b24 - 4 * t180;
t184 = a11 * b11;
t185 = 4 * t184;
t186 = a22 * b22;
t187 = 4 * t186;
t188 = a23 * b23;
t189 = 4 * t188;
t190 = a32 * b32;
t191 = 4 * t190;
t192 = a33 * b33;
t193 = 4 * t192;
t195 = 8 * a32 * b23;
t196 = a22 * b33;
t197 = 8 * t196;
t199 = 8 * a23 * b32;
t200 = a33 * b22;
t201 = 8 * t200;
t202 = a11 * a11;
t203 = 2 * t202;
t204 = a12 * a12;
t205 = 2 * t204;
t206 = a13 * a13;
t207 = 2 * t206;
t208 = a21 * a21;
t209 = 2 * t208;
t210 = a22 * a22;
t211 = 2 * t210;
t212 = a23 * a23;
t213 = 2 * t212;
t214 = -t185 + t187 + t189 + t191 + t193 + t195 - t197 + t199 - t201 + t203 + t205 + t207 + t209 + t211 + t213;
t215 = a31 * a31;
t216 = a32 * a32;
t217 = a33 * a33;
t218 = b11 * b11;
t219 = b12 * b12;
t220 = b13 * b13;
t221 = b14 * b14;
t222 = b21 * b21;
t223 = b22 * b22;
t224 = b23 * b23;
t225 = b24 * b24;
t226 = b31 * b31;
t227 = b32 * b32;
t228 = b33 * b33;
t229 = b34 * b34;
t230 = t215 + t216 + t217 + t218 + t219 + t220 + t221 + t222 + t223 + t224 + t225 + t226 + t227 + t228 + t229;
t231 = 2 * t230;
var41 = t214 + t231;
t232 = a13 * b13;
t233 = 4 * t232;
t234 = a31 * b31;
t235 = 4 * t234;
t236 = a33 * b11;
t237 = 8 * t236;
t239 = 8 * a31 * b13;
t240 = a11 * b33;
t241 = 8 * t240;
t243 = 8 * a13 * b31;
t244 = t185 - t187 + t193 + t233 + t235 - t237 + t239 - t241 + t243 + t203 + t205 + t207 + t209 + t211 + t213;
var42 = t244 + t231;
t245 = a12 * b12;
t246 = 4 * t245;
t247 = a21 * b21;
t248 = 4 * t247;
t249 = a22 * b11;
t250 = 8 * t249;
t251 = a11 * b22;
t252 = 8 * t251;
t254 = 8 * a12 * b21;
t256 = 8 * a21 * b12;
t257 = t185 + t187 - t193 + t246 + t248 - t250 - t252 + t254 + t256 + t203 + t205 + t207 + t209 + t211 + t213;
var43 = t257 + t231;
t258 = t185 + t187 - t193 - t246 - t248 - t250 - t252 - t254 - t256 + t203 + t205 + t207 + t209 + t211 + t213;
var44 = t258 + t231;
t259 = t185 - t187 + t193 - t233 - t235 - t237 - t239 - t241 - t243 + t203 + t205 + t207 + t209 + t211 + t213;
var45 = t259 + t231;
t260 = -t185 + t187 - t189 - t191 + t193 - t195 - t197 - t199 - t201 + t203 + t205 + t207 + t209 + t211 + t213;
var46 = t260 + t231;
t261 = -t16 - t26 + t32 + t8 + t30 + t38 - t34 - t42 + t22 - t28 - t20 + t18;
var47 = 4 * t261;
t262 = -t28 + t26 + t20 + t34 - t30 - t8 - t16 + t42 + t18 + t22 - t32 - t38;
var48 = 4 * t262;
t263 = -t34 + t8 + t20 - t26 + t28 + t38 + t22 + t18 + t42 + t16 - t30 - t32;
var49 = 4 * t263;
t264 = t18 + t28 + t22 - t38 - t8 + t16 + t34 - t20 + t32 - t42 + t26 + t30;
var50 = 4 * t264;
t265 = -t62 + t66 - t60 + t74 - t46 - t70 + t54 + t68 + t78 - t52 - t76 + t80;
var51 = 4 * t265;
t266 = t62 + t76 - t70 + t46 - t54 - t60 - t66 + t74 - t68 + t52 + t78 - t80;
var52 = 4 * t266;
t267 = -t54 + t74 + t78 + t70 - t46 + t60 + t80 + t62 + t52 - t76 + t68 - t66;
var53 = 4 * t267;
t268 = -t62 + t66 + t76 + t74 + t78 + t46 + t54 - t52 - t68 + t70 + t60 - t80;
var54 = 4 * t268;
t269 = t104 - t120 + t116 - t114 + t96 + t94 - t108 + t110 - t112 + t84 - t90 - t122;
var55 = 4 * t269;
t270 = t108 + t112 + t90 - t94 - t110 - t96 + t116 - t120 - t84 - t122 + t114 + t104;
var56 = 4 * t270;
t271 = -t90 - t110 + t122 + t108 - t114 + t104 + t94 + t96 + t120 + t112 - t84 + t116;
var57 = 4 * t271;
t272 = t114 - t112 + t122 + t90 - t94 + t84 + t104 - t108 + t110 + t120 + t116 - t96;
var58 = 4 * t272;
var59 = 16 * t251 - 16 * t200 - 16 * t240 - 16 * t249 + 16 * t236 + 16 * t196;
var60 = t215 - 2 * a11 + t208 + 1 + t202;
var61 = t204 + 1 - 2 * a22 + t216 + t210;
var62 = t206 + 1 - 2 * a33 + t212 + t217;
t277 = 2 * t184;
t278 = 2 * t186;
t279 = 2 * t188;
t280 = 2 * t190;
t281 = 2 * t192;
t282 = 2 * t232;
t283 = 2 * t234;
t284 = 2 * t245;
t285 = 2 * t247;
t286 = -t277 - t278 - t279 - t280 - t281 - t282 - t283 - t284 - t285 + t202 + t204 + t206 + t208 + t210 + t212;
var63 = t286 + t230;
t287 = -t277 - t278 - t279 - t280 - t281 + t282 + t283 + t284 + t285 + t202 + t204 + t206 + t208 + t210 + t212;
var64 = t287 + t230;
t288 = -t277 - t278 + t279 + t280 - t281 - t282 - t283 + t284 + t285 + t202 + t204 + t206 + t208 + t210 + t212;
var65 = t288 + t230;
t289 = -t277 - t278 + t279 + t280 - t281 + t282 + t283 - t284 - t285 + t202 + t204 + t206 + t208 + t210 + t212;
var66 = t289 + t230;
t290 = a11 * b14;
t291 = a21 * b24;
t292 = a31 * b34;
var67 = -2 * t290 - 2 * t291 + 2 * b14 - 2 * t292;
var68 = -2 * t290 + 2 * t292 + 2 * t291 + 2 * b14;
var69 = -2 * t291 + 2 * t290 - 2 * b14 + 2 * t292;
var70 = 2 * t290 - 2 * b14 + 2 * t291 - 2 * t292;
t297 = a22 * b24;
t298 = a32 * b34;
t299 = a12 * b14;
var71 = -2 * t297 - 2 * t298 + 2 * b24 - 2 * t299;
var72 = -2 * b24 - 2 * t299 + 2 * t297 + 2 * t298;
var73 = 2 * t299 + 2 * t298 - 2 * t297 + 2 * b24;
var74 = -2 * t298 + 2 * t299 + 2 * t297 - 2 * b24;
t304 = a33 * b34;
t305 = a23 * b24;
t306 = a13 * b14;
var75 = -2 * t304 + 2 * b34 - 2 * t305 - 2 * t306;
var76 = -2 * b34 + 2 * t304 - 2 * t306 + 2 * t305;
var77 = 2 * t304 + 2 * t306 - 2 * t305 - 2 * b34;
var78 = -2 * t304 + 2 * b34 + 2 * t306 + 2 * t305;
var79 = 2 * a31 * a32 - 2 * a21 + 2 * a11 * a12 - 2 * a12 + 2 * a21 * a22;
var80 = -2 * a31 + 2 * a31 * a33 + 2 * a21 * a23 - 2 * a13 + 2 * a11 * a13;
var81 = -2 * a32 + 2 * a12 * a13 - 2 * a23 + 2 * a22 * a23 + 2 * a32 * a33;
t323 = a34 * b34;
t324 = a24 * b24;
t325 = a14 * b14;
var82 = -2 * t323 - 2 * t324 - 2 * t325;
var83 = 2 * t324 + 2 * t323 - 2 * t325;
var84 = 2 * t323 - 2 * t324 + 2 * t325;
var85 = -2 * t323 + 2 * t325 + 2 * t324;


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

}
