//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean_Taylor_2nd.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 30-Aug-2015 22:24:42
//

// Include Files
#include "rt_nonfinite.h"
#include "mean_Taylor_2nd.h"
#include "mean_Taylor_2nd_emxutil.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "det.h"
#include <stdio.h>

// Function Declarations
static void b_eml_xaxpy(int n, double a, const double x[9], int ix0, double y[3],
  int iy0);
static double b_eml_xnrm2(const double x[3], int ix0);
static void c_eml_xaxpy(int n, double a, const double x[3], int ix0, double y[9],
  int iy0);
static void eml_xaxpy(int n, double a, int ix0, double y[9], int iy0);
static double eml_xdotc(int n, const double x[9], int ix0, const double y[9],
  int iy0);
static void eml_xgesvd(const double A[9], double U[9], double S[3], double V[9]);
static double eml_xnrm2(int n, const double x[9], int ix0);
static void eml_xrot(double x[9], int ix0, int iy0, double c, double s);
static void eml_xscal(double a, double x[9], int ix0);
static void eml_xswap(double x[9], int ix0, int iy0);

// Function Definitions

//
// Arguments    : int n
//                double a
//                const double x[9]
//                int ix0
//                double y[3]
//                int iy0
// Return Type  : void
//
static void b_eml_xaxpy(int n, double a, const double x[9], int ix0, double y[3],
  int iy0)
{
  int ix;
  int iy;
  int k;
  if (a == 0.0) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

//
// Arguments    : const double x[3]
//                int ix0
// Return Type  : double
//
static double b_eml_xnrm2(const double x[3], int ix0)
{
  double y;
  double scale;
  int k;
  double absxk;
  double t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = ix0; k <= ix0 + 1; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

//
// Arguments    : int n
//                double a
//                const double x[3]
//                int ix0
//                double y[9]
//                int iy0
// Return Type  : void
//
static void c_eml_xaxpy(int n, double a, const double x[3], int ix0, double y[9],
  int iy0)
{
  int ix;
  int iy;
  int k;
  if (a == 0.0) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

//
// Arguments    : int n
//                double a
//                int ix0
//                double y[9]
//                int iy0
// Return Type  : void
//
static void eml_xaxpy(int n, double a, int ix0, double y[9], int iy0)
{
  int ix;
  int iy;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

//
// Arguments    : int n
//                const double x[9]
//                int ix0
//                const double y[9]
//                int iy0
// Return Type  : double
//
static double eml_xdotc(int n, const double x[9], int ix0, const double y[9],
  int iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  d = 0.0;
  if (n < 1) {
  } else {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

//
// Arguments    : const double A[9]
//                double U[9]
//                double S[3]
//                double V[9]
// Return Type  : void
//
static void eml_xgesvd(const double A[9], double U[9], double S[3], double V[9])
{
  double b_A[9];
  double s[3];
  double e[3];
  double work[3];
  int kase;
  int q;
  int qs;
  boolean_T apply_transform;
  double ztest0;
  int ii;
  int m;
  double rt;
  double ztest;
  int iter;
  double snorm;
  int32_T exitg3;
  boolean_T exitg2;
  double f;
  double varargin_1[5];
  double mtmp;
  boolean_T exitg1;
  double sqds;
  memcpy(&b_A[0], &A[0], 9U * sizeof(double));
  for (kase = 0; kase < 3; kase++) {
    s[kase] = 0.0;
    e[kase] = 0.0;
    work[kase] = 0.0;
  }

  for (kase = 0; kase < 9; kase++) {
    U[kase] = 0.0;
    V[kase] = 0.0;
  }

  for (q = 0; q < 2; q++) {
    qs = q + 3 * q;
    apply_transform = false;
    ztest0 = eml_xnrm2(3 - q, b_A, qs + 1);
    if (ztest0 > 0.0) {
      apply_transform = true;
      if (b_A[qs] < 0.0) {
        s[q] = -ztest0;
      } else {
        s[q] = ztest0;
      }

      if (fabs(s[q]) >= 1.0020841800044864E-292) {
        ztest0 = 1.0 / s[q];
        kase = (qs - q) + 3;
        for (ii = qs; ii + 1 <= kase; ii++) {
          b_A[ii] *= ztest0;
        }
      } else {
        kase = (qs - q) + 3;
        for (ii = qs; ii + 1 <= kase; ii++) {
          b_A[ii] /= s[q];
        }
      }

      b_A[qs]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (ii = q + 1; ii + 1 < 4; ii++) {
      kase = q + 3 * ii;
      if (apply_transform) {
        eml_xaxpy(3 - q, -(eml_xdotc(3 - q, b_A, qs + 1, b_A, kase + 1) / b_A[q
                           + 3 * q]), qs + 1, b_A, kase + 1);
      }

      e[ii] = b_A[kase];
    }

    for (ii = q; ii + 1 < 4; ii++) {
      U[ii + 3 * q] = b_A[ii + 3 * q];
    }

    if (q + 1 <= 1) {
      ztest0 = b_eml_xnrm2(e, 2);
      if (ztest0 == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          ztest0 = -ztest0;
        }

        e[0] = ztest0;
        if (fabs(ztest0) >= 1.0020841800044864E-292) {
          ztest0 = 1.0 / ztest0;
          for (ii = 1; ii + 1 < 4; ii++) {
            e[ii] *= ztest0;
          }
        } else {
          for (ii = 1; ii + 1 < 4; ii++) {
            e[ii] /= ztest0;
          }
        }

        e[1]++;
        e[0] = -e[0];
        for (ii = 2; ii < 4; ii++) {
          work[ii - 1] = 0.0;
        }

        for (ii = 1; ii + 1 < 4; ii++) {
          b_eml_xaxpy(2, e[ii], b_A, 3 * ii + 2, work, 2);
        }

        for (ii = 1; ii + 1 < 4; ii++) {
          c_eml_xaxpy(2, -e[ii] / e[1], work, 2, b_A, 3 * ii + 2);
        }
      }

      for (ii = 1; ii + 1 < 4; ii++) {
        V[ii] = e[ii];
      }
    }
  }

  m = 1;
  s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  for (ii = 0; ii < 3; ii++) {
    U[6 + ii] = 0.0;
  }

  U[8] = 1.0;
  for (q = 1; q > -1; q += -1) {
    qs = q + 3 * q;
    if (s[q] != 0.0) {
      for (ii = q + 1; ii + 1 < 4; ii++) {
        kase = (q + 3 * ii) + 1;
        eml_xaxpy(3 - q, -(eml_xdotc(3 - q, U, qs + 1, U, kase) / U[qs]), qs + 1,
                  U, kase);
      }

      for (ii = q; ii + 1 < 4; ii++) {
        U[ii + 3 * q] = -U[ii + 3 * q];
      }

      U[qs]++;
      ii = 1;
      while (ii <= q) {
        U[3] = 0.0;
        ii = 2;
      }
    } else {
      for (ii = 0; ii < 3; ii++) {
        U[ii + 3 * q] = 0.0;
      }

      U[qs] = 1.0;
    }
  }

  for (q = 2; q > -1; q += -1) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      for (ii = 0; ii < 2; ii++) {
        kase = 2 + 3 * (ii + 1);
        eml_xaxpy(2, -(eml_xdotc(2, V, 2, V, kase) / V[1]), 2, V, kase);
      }
    }

    for (ii = 0; ii < 3; ii++) {
      V[ii + 3 * q] = 0.0;
    }

    V[q + 3 * q] = 1.0;
  }

  for (q = 0; q < 3; q++) {
    ztest0 = e[q];
    if (s[q] != 0.0) {
      rt = fabs(s[q]);
      ztest = s[q] / rt;
      s[q] = rt;
      if (q + 1 < 3) {
        ztest0 = e[q] / ztest;
      }

      eml_xscal(ztest, U, 1 + 3 * q);
    }

    if ((q + 1 < 3) && (ztest0 != 0.0)) {
      rt = fabs(ztest0);
      ztest = rt / ztest0;
      ztest0 = rt;
      s[q + 1] *= ztest;
      eml_xscal(ztest, V, 1 + 3 * (q + 1));
    }

    e[q] = ztest0;
  }

  iter = 0;
  snorm = 0.0;
  for (ii = 0; ii < 3; ii++) {
    ztest0 = fabs(s[ii]);
    ztest = fabs(e[ii]);
    if ((ztest0 >= ztest) || rtIsNaN(ztest)) {
    } else {
      ztest0 = ztest;
    }

    if ((snorm >= ztest0) || rtIsNaN(ztest0)) {
    } else {
      snorm = ztest0;
    }
  }

  while ((m + 2 > 0) && (!(iter >= 75))) {
    ii = m;
    do {
      exitg3 = 0;
      q = ii + 1;
      if (ii + 1 == 0) {
        exitg3 = 1;
      } else {
        ztest0 = fabs(e[ii]);
        if ((ztest0 <= 2.2204460492503131E-16 * (fabs(s[ii]) + fabs(s[ii + 1])))
            || (ztest0 <= 1.0020841800044864E-292) || ((iter > 20) && (ztest0 <=
              2.2204460492503131E-16 * snorm))) {
          e[ii] = 0.0;
          exitg3 = 1;
        } else {
          ii--;
        }
      }
    } while (exitg3 == 0);

    if (ii + 1 == m + 1) {
      kase = 4;
    } else {
      qs = m + 2;
      kase = m + 2;
      exitg2 = false;
      while ((!exitg2) && (kase >= ii + 1)) {
        qs = kase;
        if (kase == ii + 1) {
          exitg2 = true;
        } else {
          ztest0 = 0.0;
          if (kase < m + 2) {
            ztest0 = fabs(e[kase - 1]);
          }

          if (kase > ii + 2) {
            ztest0 += fabs(e[kase - 2]);
          }

          ztest = fabs(s[kase - 1]);
          if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
               1.0020841800044864E-292)) {
            s[kase - 1] = 0.0;
            exitg2 = true;
          } else {
            kase--;
          }
        }
      }

      if (qs == ii + 1) {
        kase = 3;
      } else if (qs == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      f = e[m];
      e[m] = 0.0;
      for (ii = m; ii + 1 >= q + 1; ii--) {
        ztest0 = s[ii];
        eml_xrotg(&ztest0, &f, &ztest, &rt);
        s[ii] = ztest0;
        if (ii + 1 > q + 1) {
          f = -rt * e[0];
          e[0] *= ztest;
        }

        eml_xrot(V, 1 + 3 * ii, 1 + 3 * (m + 1), ztest, rt);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (ii = q; ii + 1 <= m + 2; ii++) {
        eml_xrotg(&s[ii], &f, &ztest, &rt);
        f = -rt * e[ii];
        e[ii] *= ztest;
        eml_xrot(U, 1 + 3 * ii, 1 + 3 * (q - 1), ztest, rt);
      }
      break;

     case 3:
      varargin_1[0] = fabs(s[m + 1]);
      varargin_1[1] = fabs(s[m]);
      varargin_1[2] = fabs(e[m]);
      varargin_1[3] = fabs(s[q]);
      varargin_1[4] = fabs(e[q]);
      kase = 1;
      mtmp = varargin_1[0];
      if (rtIsNaN(varargin_1[0])) {
        ii = 2;
        exitg1 = false;
        while ((!exitg1) && (ii < 6)) {
          kase = ii;
          if (!rtIsNaN(varargin_1[ii - 1])) {
            mtmp = varargin_1[ii - 1];
            exitg1 = true;
          } else {
            ii++;
          }
        }
      }

      if (kase < 5) {
        while (kase + 1 < 6) {
          if (varargin_1[kase] > mtmp) {
            mtmp = varargin_1[kase];
          }

          kase++;
        }
      }

      f = s[m + 1] / mtmp;
      ztest0 = s[m] / mtmp;
      ztest = e[m] / mtmp;
      sqds = s[q] / mtmp;
      rt = ((ztest0 + f) * (ztest0 - f) + ztest * ztest) / 2.0;
      ztest0 = f * ztest;
      ztest0 *= ztest0;
      if ((rt != 0.0) || (ztest0 != 0.0)) {
        ztest = sqrt(rt * rt + ztest0);
        if (rt < 0.0) {
          ztest = -ztest;
        }

        ztest = ztest0 / (rt + ztest);
      } else {
        ztest = 0.0;
      }

      f = (sqds + f) * (sqds - f) + ztest;
      ztest0 = sqds * (e[q] / mtmp);
      for (ii = q + 1; ii <= m + 1; ii++) {
        eml_xrotg(&f, &ztest0, &ztest, &rt);
        if (ii > q + 1) {
          e[0] = f;
        }

        f = ztest * s[ii - 1] + rt * e[ii - 1];
        e[ii - 1] = ztest * e[ii - 1] - rt * s[ii - 1];
        ztest0 = rt * s[ii];
        s[ii] *= ztest;
        eml_xrot(V, 1 + 3 * (ii - 1), 1 + 3 * ii, ztest, rt);
        s[ii - 1] = f;
        eml_xrotg(&s[ii - 1], &ztest0, &ztest, &rt);
        f = ztest * e[ii - 1] + rt * s[ii];
        s[ii] = -rt * e[ii - 1] + ztest * s[ii];
        ztest0 = rt * e[ii];
        e[ii] *= ztest;
        eml_xrot(U, 1 + 3 * (ii - 1), 1 + 3 * ii, ztest, rt);
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        eml_xscal(-1.0, V, 1 + 3 * q);
      }

      kase = q + 1;
      while ((q + 1 < 3) && (s[q] < s[kase])) {
        rt = s[q];
        s[q] = s[kase];
        s[kase] = rt;
        eml_xswap(V, 1 + 3 * q, 1 + 3 * (q + 1));
        eml_xswap(U, 1 + 3 * q, 1 + 3 * (q + 1));
        q = kase;
        kase++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  for (ii = 0; ii < 3; ii++) {
    S[ii] = s[ii];
  }
}

//
// Arguments    : int n
//                const double x[9]
//                int ix0
// Return Type  : double
//
static double eml_xnrm2(int n, const double x[9], int ix0)
{
  double y;
  double scale;
  int kend;
  int k;
  double absxk;
  double t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

//
// Arguments    : double x[9]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
static void eml_xrot(double x[9], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 3; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

//
// Arguments    : double a
//                double x[9]
//                int ix0
// Return Type  : void
//
static void eml_xscal(double a, double x[9], int ix0)
{
  int k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

//
// Arguments    : double x[9]
//                int ix0
//                int iy0
// Return Type  : void
//
static void eml_xswap(double x[9], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 3; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

//
// coder.extrinsic('mean_Taylor_1st_mex');
// Arguments    : const emxArray_real_T *X
//                double noise
//                short num
//                double MX[16]
// Return Type  : void
//
void mean_Taylor_2nd(const emxArray_real_T *X, double noise, short num, double
                     MX[16])
{
  double n;
  double M_hat[16];
  int i;
  emxArray_real_T *b_X;
  int i0;
  unsigned int u0;
  int i1;
  int i2;
  int loop_ub;
  double y;
  double b_M_hat[9];
  double V[9];
  double s[3];
  double U[9];
  double Rx[9];
  double M_t1[16];
  static const signed char iv0[4] = { 0, 0, 0, 1 };

  double CA;
  signed char E[96];
  static const signed char iv1[16] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv2[16] = { 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv3[16] = { 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv4[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const signed char iv5[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0 };

  static const signed char iv6[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0 };

  double count;
  int m;
  double step;
  emxArray_real_T *X_k;
  emxArray_real_T *C;
  boolean_T exitg1;
  double n_step;
  int j;
  int b_j;
  double a;
  double b_a[16];
  double MX1[16];
  double MX2[16];
  double MX2sum[16];
  int k;
  int a_size[2];
  int cr;
  int ic;
  int br;
  int ar;
  int ib;
  int ia;
  double c_M_hat;
  double b_MX2sum;
  double b_y;
  double CA1;
  double CA2;

  //  This function calculates the 2nd order approximation of the mean of a
  //  bunch of matrices based on the Taylor expansion of the matrix logarithm
  //  and the definition of mean of a probability density function.
  //  Input: X is a cell of 4 by 4*n rigid transformation matrices
  //  Output: M_T1 is the mean of the 1st order approximation of Taylor
  //  expansion
  //  Output: MX is the 2nd order approximation of the Taylor expansion
  //  This function calculates the 1st order approximation of the mean of a
  //  bunch of matrices based on the Taylor expansion of the matrix logarithm
  //  and the definition of mean of a probability density function.
  //  Input: X is a 4 by 4*n rigid transformation matrices
  //  Output: M_T1 is the mean of the 1st order approximation of Taylor
  //  expansion
  //  Change of this m file doesn't automatically change the executable generated by  
  //  mean_Taylor_2nd.m
  n = (double)X->size[1] / 4.0;
  memset(&M_hat[0], 0, sizeof(double) << 4);
  i = 0;
  emxInit_real_T(&b_X, 2);
  while (i <= (int)n - 1) {
    i0 = (i << 2) + 1;
    u0 = (unsigned int)(1 + i) << 2;
    if ((unsigned int)i0 > u0) {
      i0 = 0;
      i1 = 0;
    } else {
      i0--;
      i1 = (int)u0;
    }

    i2 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 4;
    b_X->size[1] = i1 - i0;
    emxEnsureCapacity((emxArray__common *)b_X, i2, (int)sizeof(double));
    loop_ub = i1 - i0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 4; i2++) {
        b_X->data[i2 + b_X->size[0] * i1] = X->data[i2 + X->size[0] * (i0 + i1)];
      }
    }

    for (i0 = 0; i0 < 4; i0++) {
      for (i1 = 0; i1 < 4; i1++) {
        M_hat[i1 + (i0 << 2)] += b_X->data[i1 + (i0 << 2)];
      }
    }

    i++;
  }

  emxFree_real_T(&b_X);
  y = 1.0 / n;
  for (i0 = 0; i0 < 16; i0++) {
    M_hat[i0] *= y;
  }

  //  Note that M_hat doesn't belong to SE(3)
  //  This function takes in a 4 by 4 matrix which has the form of
  //  [3 by 4; 0 0 0 n] and return a rigig transformation matrix by
  //  orthogonalizing the upper left 3 by 3 matrix into a rotation matrix
  //  opt = 1: Orthogonalize only the rotation part of M_hat
  //  opt = 2: SVD the whole M_hat to obtain a transformation matrix
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_M_hat[i1 + 3 * i0] = M_hat[i1 + (i0 << 2)];
    }
  }

  eml_xgesvd(b_M_hat, U, s, V);

  //  The order of V and U might be flipped
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      Rx[i0 + 3 * i1] = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        Rx[i0 + 3 * i1] += U[i0 + 3 * i2] * V[i1 + 3 * i2];
      }
    }
  }

  //      Rx = V*U';
  if (det(Rx) < 0.0) {
    for (i0 = 0; i0 < 3; i0++) {
      Rx[6 + i0] = -Rx[6 + i0];
    }
  }

  if (fabs(det(Rx) - 1.0) > 1.0E-8) {
    b_fprintf();
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      M_t1[i1 + (i0 << 2)] = Rx[i1 + 3 * i0];
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    M_t1[12 + i0] = M_hat[12 + i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    M_t1[3 + (i0 << 2)] = iv0[i0];
  }

  //  Potential further refinement
  //  M_t1 = mean_Taylor_1st( M_t1 );
  n = (double)X->size[1] / 4.0;

  //  Perturb M_t1 along each direction defined by the Lie algebra element of
  //  SE(3)
  CA = rtInf;
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      E[i1 + (i0 << 2)] = iv1[i1 + (i0 << 2)];
      E[16 + (i1 + (i0 << 2))] = iv2[i1 + (i0 << 2)];
      E[32 + (i1 + (i0 << 2))] = iv3[i1 + (i0 << 2)];
      E[48 + (i1 + (i0 << 2))] = iv4[i1 + (i0 << 2)];
      E[64 + (i1 + (i0 << 2))] = iv5[i1 + (i0 << 2)];
      E[80 + (i1 + (i0 << 2))] = iv6[i1 + (i0 << 2)];
    }
  }

  memcpy(&MX[0], &M_t1[0], sizeof(double) << 4);
  count = 0.0;
  if (noise == 0.0) {
    m = 3;
  } else if (noise == 1.0) {
    m = 0;
  } else {
    m = -1;
  }

  step = 1.0;

  //  Change the step lengths if descent direction is not found
  //  fprintf('---------------------------------------------- \n')
  //  fprintf('Search gradient descent direction from %f to 6 \n', m)
  //  fprintf('---------------------------------------------- \n')
  emxInit_real_T(&X_k, 2);
  emxInit_real_T(&C, 2);
  exitg1 = false;
  while ((!exitg1) && (fabs(CA) > 1.0E-12)) {
    count++;
    n_step = 0.0;

    //  Approximation of rotation is good so far so we only further optimize
    //  on translation
    for (j = 0; j <= 5 - m; j++) {
      b_j = m + j;

      //  disp(step)
      a = step * 0.001;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          b_a[i1 + (i0 << 2)] = a * (double)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      expm(b_a, M_hat);
      a = -step * 0.001;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          MX1[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            MX1[i0 + (i1 << 2)] += MX[i0 + (i2 << 2)] * M_hat[i2 + (i1 << 2)];
          }

          b_a[i1 + (i0 << 2)] = a * (double)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      expm(b_a, M_hat);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          MX2[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            MX2[i0 + (i1 << 2)] += MX[i0 + (i2 << 2)] * M_hat[i2 + (i1 << 2)];
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        M_hat[i0] = 0.0;
        MX2sum[i0] = 0.0;
      }

      for (k = 0; k < (int)n; k++) {
        i0 = (k << 2) + 1;
        u0 = (unsigned int)(1 + k) << 2;
        if ((unsigned int)i0 > u0) {
          i0 = 0;
          i1 = 0;
        } else {
          i0--;
          i1 = (int)u0;
        }

        i2 = X_k->size[0] * X_k->size[1];
        X_k->size[0] = 4;
        X_k->size[1] = i1 - i0;
        emxEnsureCapacity((emxArray__common *)X_k, i2, (int)sizeof(double));
        loop_ub = i1 - i0;
        for (i2 = 0; i2 < loop_ub; i2++) {
          for (i = 0; i < 4; i++) {
            X_k->data[i + X_k->size[0] * i2] = X->data[i + X->size[0] * (i0 + i2)];
          }
        }

        mrdivide(X_k, MX1, b_a, a_size);
        i2 = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity((emxArray__common *)C, i2, (int)sizeof(double));
        i2 = C->size[0] * C->size[1];
        C->size[1] = i1 - i0;
        emxEnsureCapacity((emxArray__common *)C, i2, (int)sizeof(double));
        loop_ub = (i1 - i0) << 2;
        for (i2 = 0; i2 < loop_ub; i2++) {
          C->data[i2] = 0.0;
        }

        if (i1 - i0 == 0) {
        } else {
          i = ((i1 - i0) - 1) << 2;
          for (cr = 0; cr <= i; cr += 4) {
            for (ic = cr; ic + 1 <= cr + 4; ic++) {
              C->data[ic] = 0.0;
            }
          }

          br = 0;
          for (cr = 0; cr <= i; cr += 4) {
            ar = 0;
            for (ib = br; ib + 1 <= br + 4; ib++) {
              if (X->data[ib % 4 + X->size[0] * (i0 + (ib >> 2))] != 0.0) {
                ia = ar;
                for (ic = cr; ic + 1 <= cr + 4; ic++) {
                  ia++;
                  C->data[ic] += X->data[ib % 4 + X->size[0] * (i0 + (ib >> 2))]
                    * b_a[ia - 1];
                }
              }

              ar += 4;
            }

            br += 4;
          }
        }

        for (i2 = 0; i2 < 16; i2++) {
          c_M_hat = M_hat[i2] + C->data[i2];
          M_hat[i2] = c_M_hat;
        }

        mrdivide(X_k, MX2, b_a, a_size);
        i2 = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity((emxArray__common *)C, i2, (int)sizeof(double));
        i2 = C->size[0] * C->size[1];
        C->size[1] = i1 - i0;
        emxEnsureCapacity((emxArray__common *)C, i2, (int)sizeof(double));
        loop_ub = (i1 - i0) << 2;
        for (i2 = 0; i2 < loop_ub; i2++) {
          C->data[i2] = 0.0;
        }

        if (i1 - i0 == 0) {
        } else {
          i = ((i1 - i0) - 1) << 2;
          for (cr = 0; cr <= i; cr += 4) {
            for (ic = cr; ic + 1 <= cr + 4; ic++) {
              C->data[ic] = 0.0;
            }
          }

          br = 0;
          for (cr = 0; cr <= i; cr += 4) {
            ar = 0;
            for (ib = br; ib + 1 <= br + 4; ib++) {
              if (X->data[ib % 4 + X->size[0] * (i0 + (ib >> 2))] != 0.0) {
                ia = ar;
                for (ic = cr; ic + 1 <= cr + 4; ic++) {
                  ia++;
                  C->data[ic] += X->data[ib % 4 + X->size[0] * (i0 + (ib >> 2))]
                    * b_a[ia - 1];
                }
              }

              ar += 4;
            }

            br += 4;
          }
        }

        for (i0 = 0; i0 < 16; i0++) {
          b_MX2sum = MX2sum[i0] + C->data[i0];
          MX2sum[i0] = b_MX2sum;
        }
      }

      y = 0.5 / n;
      b_y = 0.5 / n;
      for (i0 = 0; i0 < 16; i0++) {
        M_hat[i0] = (2.0 * M_t1[i0] - y * M_hat[i0]) - 1.5 * MX1[i0];
        MX2sum[i0] = (2.0 * M_t1[i0] - b_y * MX2sum[i0]) - 1.5 * MX2[i0];
      }

      if (noise == 0.0) {
        a = norm(*(double (*)[3])&M_hat[12]);
        CA1 = a * a;
        a = norm(*(double (*)[3])&MX2sum[12]);
        CA2 = a * a;
      } else if (noise == 1.0) {
        a = b_norm(M_hat);
        CA1 = a * a;
        a = b_norm(MX2sum);
        CA2 = a * a;
      } else {
        CA1 = -1.0;
        CA2 = -1.0;
      }

      if ((CA1 <= CA2) && (CA1 < CA)) {
        CA = CA1;
        memcpy(&MX[0], &MX1[0], sizeof(double) << 4);
        step = 1.0;

        //  fprintf('Found a descent direction along %d \n', j)
        //  disp(MX1cost)
        //  disp(CA)
      } else if ((CA2 < CA1) && (CA2 < CA)) {
        CA = CA2;
        memcpy(&MX[0], &MX2[0], sizeof(double) << 4);
        step = 1.0;

        //  fprintf('Found a descent direction along -%d \n', j)
        //  disp(MX2cost)
        //  disp(CA)
      } else {
        //  fprintf('Not a descent direction along +/-%d \n', j)
        n_step++;
        if (n_step == 6.0) {
          step++;
        }
      }
    }

    if (count == num) {
      exitg1 = true;
    }
  }

  emxFree_real_T(&C);
  emxFree_real_T(&X_k);

  //  fprintf('\n')
  d_fprintf(count);

  //  fprintf('\n')
  //  fprintf('\n')
}

//
// File trailer for mean_Taylor_2nd.cpp
//
// [EOF]
//
