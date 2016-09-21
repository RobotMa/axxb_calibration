//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: norm.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 15-Jul-2015 12:00:44
//

// Include Files
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "norm.h"
#include <stdio.h>

// Function Declarations
static double b_eml_xdotc(int n, const double x[16], int ix0, const double y[16],
  int iy0);
static double c_eml_xnrm2(int n, const double x[16], int ix0);
static void d_eml_xaxpy(int n, double a, int ix0, double y[16], int iy0);
static double d_eml_xnrm2(int n, const double x[4], int ix0);
static void e_eml_xaxpy(int n, double a, const double x[16], int ix0, double y[4],
  int iy0);
static void f_eml_xaxpy(int n, double a, const double x[4], int ix0, double y[16],
  int iy0);

// Function Definitions

//
// Arguments    : int n
//                const double x[16]
//                int ix0
//                const double y[16]
//                int iy0
// Return Type  : double
//
static double b_eml_xdotc(int n, const double x[16], int ix0, const double y[16],
  int iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  d = 0.0;
  ix = ix0;
  iy = iy0;
  for (k = 1; k <= n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

//
// Arguments    : int n
//                const double x[16]
//                int ix0
// Return Type  : double
//
static double c_eml_xnrm2(int n, const double x[16], int ix0)
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
// Arguments    : int n
//                double a
//                int ix0
//                double y[16]
//                int iy0
// Return Type  : void
//
static void d_eml_xaxpy(int n, double a, int ix0, double y[16], int iy0)
{
  int ix;
  int iy;
  int k;
  if (a == 0.0) {
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
//                const double x[4]
//                int ix0
// Return Type  : double
//
static double d_eml_xnrm2(int n, const double x[4], int ix0)
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
// Arguments    : int n
//                double a
//                const double x[16]
//                int ix0
//                double y[4]
//                int iy0
// Return Type  : void
//
static void e_eml_xaxpy(int n, double a, const double x[16], int ix0, double y[4],
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
//                const double x[4]
//                int ix0
//                double y[16]
//                int iy0
// Return Type  : void
//
static void f_eml_xaxpy(int n, double a, const double x[4], int ix0, double y[16],
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
// Arguments    : const double x[16]
// Return Type  : double
//
double b_norm(const double x[16])
{
  double y;
  double A[16];
  double s[4];
  double e[4];
  double work[4];
  int kase;
  int q;
  int qs;
  boolean_T apply_transform;
  double ztest0;
  int ixstart;
  int m;
  double ztest;
  double rt;
  int iter;
  double snorm;
  int32_T exitg3;
  boolean_T exitg2;
  double f;
  double varargin_1[5];
  double mtmp;
  boolean_T exitg1;
  double sqds;
  memcpy(&A[0], &x[0], sizeof(double) << 4);
  for (kase = 0; kase < 4; kase++) {
    s[kase] = 0.0;
    e[kase] = 0.0;
    work[kase] = 0.0;
  }

  for (q = 0; q < 3; q++) {
    qs = q + (q << 2);
    apply_transform = false;
    ztest0 = c_eml_xnrm2(4 - q, A, qs + 1);
    if (ztest0 > 0.0) {
      apply_transform = true;
      if (A[qs] < 0.0) {
        s[q] = -ztest0;
      } else {
        s[q] = ztest0;
      }

      if (fabs(s[q]) >= 1.0020841800044864E-292) {
        y = 1.0 / s[q];
        kase = (qs - q) + 4;
        for (ixstart = qs; ixstart + 1 <= kase; ixstart++) {
          A[ixstart] *= y;
        }
      } else {
        kase = (qs - q) + 4;
        for (ixstart = qs; ixstart + 1 <= kase; ixstart++) {
          A[ixstart] /= s[q];
        }
      }

      A[qs]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (kase = q + 1; kase + 1 < 5; kase++) {
      ixstart = q + (kase << 2);
      if (apply_transform) {
        d_eml_xaxpy(4 - q, -(b_eml_xdotc(4 - q, A, qs + 1, A, ixstart + 1) / A[q
                             + (q << 2)]), qs + 1, A, ixstart + 1);
      }

      e[kase] = A[ixstart];
    }

    if (q + 1 <= 2) {
      ztest0 = d_eml_xnrm2(3 - q, e, q + 2);
      if (ztest0 == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -ztest0;
        } else {
          e[q] = ztest0;
        }

        ztest0 = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          y = 1.0 / e[q];
          for (ixstart = q + 1; ixstart + 1 < 5; ixstart++) {
            e[ixstart] *= y;
          }
        } else {
          for (ixstart = q + 1; ixstart + 1 < 5; ixstart++) {
            e[ixstart] /= ztest0;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (kase = q + 1; kase + 1 < 5; kase++) {
          work[kase] = 0.0;
        }

        for (kase = q + 1; kase + 1 < 5; kase++) {
          e_eml_xaxpy(3 - q, e[kase], A, (q + (kase << 2)) + 2, work, q + 2);
        }

        for (kase = q + 1; kase + 1 < 5; kase++) {
          f_eml_xaxpy(3 - q, -e[kase] / e[q + 1], work, q + 2, A, (q + (kase <<
            2)) + 2);
        }
      }
    }
  }

  m = 2;
  s[3] = A[15];
  e[2] = A[14];
  e[3] = 0.0;
  for (q = 0; q < 4; q++) {
    ztest = e[q];
    if (s[q] != 0.0) {
      rt = fabs(s[q]);
      ztest0 = s[q] / rt;
      s[q] = rt;
      if (q + 1 < 4) {
        ztest = e[q] / ztest0;
      }
    }

    if ((q + 1 < 4) && (ztest != 0.0)) {
      rt = fabs(ztest);
      ztest0 = ztest;
      ztest = rt;
      s[q + 1] *= rt / ztest0;
    }

    e[q] = ztest;
  }

  iter = 0;
  snorm = 0.0;
  for (kase = 0; kase < 4; kase++) {
    y = fabs(s[kase]);
    ztest0 = fabs(e[kase]);
    if ((y >= ztest0) || rtIsNaN(ztest0)) {
      ztest0 = y;
    }

    if ((snorm >= ztest0) || rtIsNaN(ztest0)) {
    } else {
      snorm = ztest0;
    }
  }

  while ((m + 2 > 0) && (!(iter >= 75))) {
    kase = m;
    do {
      exitg3 = 0;
      q = kase + 1;
      if (kase + 1 == 0) {
        exitg3 = 1;
      } else {
        ztest0 = fabs(e[kase]);
        if ((ztest0 <= 2.2204460492503131E-16 * (fabs(s[kase]) + fabs(s[kase + 1])))
            || (ztest0 <= 1.0020841800044864E-292) || ((iter > 20) && (ztest0 <=
              2.2204460492503131E-16 * snorm))) {
          e[kase] = 0.0;
          exitg3 = 1;
        } else {
          kase--;
        }
      }
    } while (exitg3 == 0);

    if (kase + 1 == m + 1) {
      kase = 4;
    } else {
      qs = m + 2;
      ixstart = m + 2;
      exitg2 = false;
      while ((!exitg2) && (ixstart >= kase + 1)) {
        qs = ixstart;
        if (ixstart == kase + 1) {
          exitg2 = true;
        } else {
          ztest0 = 0.0;
          if (ixstart < m + 2) {
            ztest0 = fabs(e[ixstart - 1]);
          }

          if (ixstart > kase + 2) {
            ztest0 += fabs(e[ixstart - 2]);
          }

          ztest = fabs(s[ixstart - 1]);
          if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
               1.0020841800044864E-292)) {
            s[ixstart - 1] = 0.0;
            exitg2 = true;
          } else {
            ixstart--;
          }
        }
      }

      if (qs == kase + 1) {
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
      for (ixstart = m; ixstart + 1 >= q + 1; ixstart--) {
        ztest0 = s[ixstart];
        eml_xrotg(&ztest0, &f, &ztest, &rt);
        s[ixstart] = ztest0;
        if (ixstart + 1 > q + 1) {
          f = -rt * e[ixstart - 1];
          e[ixstart - 1] *= ztest;
        }
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      while (q + 1 <= m + 2) {
        eml_xrotg(&s[q], &f, &ztest, &rt);
        f = -rt * e[q];
        e[q] *= ztest;
        q++;
      }
      break;

     case 3:
      varargin_1[0] = fabs(s[m + 1]);
      varargin_1[1] = fabs(s[m]);
      varargin_1[2] = fabs(e[m]);
      varargin_1[3] = fabs(s[q]);
      varargin_1[4] = fabs(e[q]);
      ixstart = 1;
      mtmp = varargin_1[0];
      if (rtIsNaN(varargin_1[0])) {
        kase = 2;
        exitg1 = false;
        while ((!exitg1) && (kase < 6)) {
          ixstart = kase;
          if (!rtIsNaN(varargin_1[kase - 1])) {
            mtmp = varargin_1[kase - 1];
            exitg1 = true;
          } else {
            kase++;
          }
        }
      }

      if (ixstart < 5) {
        while (ixstart + 1 < 6) {
          if (varargin_1[ixstart] > mtmp) {
            mtmp = varargin_1[ixstart];
          }

          ixstart++;
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
      for (ixstart = q + 1; ixstart <= m + 1; ixstart++) {
        eml_xrotg(&f, &ztest0, &ztest, &rt);
        if (ixstart > q + 1) {
          e[ixstart - 2] = f;
        }

        f = ztest * s[ixstart - 1] + rt * e[ixstart - 1];
        e[ixstart - 1] = ztest * e[ixstart - 1] - rt * s[ixstart - 1];
        ztest0 = rt * s[ixstart];
        s[ixstart] *= ztest;
        s[ixstart - 1] = f;
        eml_xrotg(&s[ixstart - 1], &ztest0, &ztest, &rt);
        f = ztest * e[ixstart - 1] + rt * s[ixstart];
        s[ixstart] = -rt * e[ixstart - 1] + ztest * s[ixstart];
        ztest0 = rt * e[ixstart];
        e[ixstart] *= ztest;
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
      }

      kase = q + 1;
      while ((q + 1 < 4) && (s[q] < s[kase])) {
        rt = s[q];
        s[q] = s[kase];
        s[kase] = rt;
        q = kase;
        kase++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  for (ixstart = 0; ixstart < 4; ixstart++) {
    e[ixstart] = s[ixstart];
  }

  return e[0];
}

//
// Arguments    : double *a
//                double *b
//                double *c
//                double *s
// Return Type  : void
//
void eml_xrotg(double *a, double *b, double *c, double *s)
{
  double roe;
  double absa;
  double absb;
  double scale;
  double ads;
  double bds;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    scale = 0.0;
    *b = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }
  }

  *a = scale;
}

//
// Arguments    : const double x[3]
// Return Type  : double
//
double norm(const double x[3])
{
  double y;
  double scale;
  int k;
  double absxk;
  double t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 3; k++) {
    absxk = fabs(x[k]);
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
// File trailer for norm.cpp
//
// [EOF]
//
