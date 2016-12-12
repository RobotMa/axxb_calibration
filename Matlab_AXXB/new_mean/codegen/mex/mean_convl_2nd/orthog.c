/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * orthog.c
 *
 * Code generation for function 'orthog'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "orthog.h"
#include "eml_error.h"
#include "fprintf.h"
#include "det.h"
#include "norm.h"
#include "eml_int_forloop_overflow_check.h"
#include "sqrt.h"
#include "mean_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 21, "orthog",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/orthog.m" };

static emlrtRSInfo x_emlrtRSI = { 25, "orthog",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/orthog.m" };

static emlrtRSInfo y_emlrtRSI = { 29, "orthog",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/orthog.m" };

static emlrtRSInfo ab_emlrtRSI = { 30, "orthog",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/orthog.m" };

static emlrtRSInfo cb_emlrtRSI = { 58, "svd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/svd.m" };

static emlrtRSInfo fb_emlrtRSI = { 421, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo ob_emlrtRSI = { 247, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo pb_emlrtRSI = { 236, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

static emlrtRSInfo ac_emlrtRSI = { 1, "xscal",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"
};

static emlrtRSInfo bc_emlrtRSI = { 1, "xscal",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"
};

static emlrtRSInfo cc_emlrtRSI = { 28, "eml_xscal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m" };

/* Function Declarations */
static void b_eml_xaxpy(int32_T n, real_T a, const real_T x[9], int32_T ix0,
  real_T y[3], int32_T iy0);
static real_T b_eml_xnrm2(const emlrtStack *sp, const real_T x[3], int32_T ix0);
static void c_eml_xaxpy(int32_T n, real_T a, const real_T x[3], int32_T ix0,
  real_T y[9], int32_T iy0);
static int32_T div_nzp_s32_floor(int32_T numerator, int32_T denominator);
static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0);
static real_T eml_xdotc(int32_T n, const real_T x[9], int32_T ix0, const real_T
  y[9], int32_T iy0);
static void eml_xgesvd(const emlrtStack *sp, const real_T A[9], real_T U[9],
  real_T S[3], real_T V[9]);
static real_T eml_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[9],
  int32_T ix0);
static void eml_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T s);
static void eml_xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0);
static void eml_xswap(real_T x[9], int32_T ix0, int32_T iy0);

/* Function Definitions */
static void b_eml_xaxpy(int32_T n, real_T a, const real_T x[9], int32_T ix0,
  real_T y[3], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
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

static real_T b_eml_xnrm2(const emlrtStack *sp, const real_T x[3], int32_T ix0)
{
  real_T y;
  real_T scale;
  boolean_T b_ix0;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ub_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &vb_emlrtRSI;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  c_st.site = &wb_emlrtRSI;
  if (ix0 > ix0 + 1) {
    b_ix0 = false;
  } else {
    b_ix0 = (ix0 + 1 > 2147483646);
  }

  if (b_ix0) {
    d_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = ix0; k <= ix0 + 1; k++) {
    absxk = muDoubleScalarAbs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

static void c_eml_xaxpy(int32_T n, real_T a, const real_T x[3], int32_T ix0,
  real_T y[9], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
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

static int32_T div_nzp_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  uint32_T tempAbsQuotient;
  if (numerator >= 0) {
    absNumerator = (uint32_T)numerator;
  } else {
    absNumerator = (uint32_T)-numerator;
  }

  if (denominator >= 0) {
    absDenominator = (uint32_T)denominator;
  } else {
    absDenominator = (uint32_T)-denominator;
  }

  quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
  tempAbsQuotient = absNumerator / absDenominator;
  if (quotientNeedsNegation) {
    absNumerator %= absDenominator;
    if (absNumerator > 0U) {
      tempAbsQuotient++;
    }
  }

  if (quotientNeedsNegation) {
    quotient = -(int32_T)tempAbsQuotient;
  } else {
    quotient = (int32_T)tempAbsQuotient;
  }

  return quotient;
}

static void eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
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

static real_T eml_xdotc(int32_T n, const real_T x[9], int32_T ix0, const real_T
  y[9], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
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

static void eml_xgesvd(const emlrtStack *sp, const real_T A[9], real_T U[9],
  real_T S[3], real_T V[9])
{
  real_T b_A[9];
  real_T s[3];
  real_T e[3];
  real_T work[3];
  int32_T kase;
  int32_T q;
  int32_T qs;
  boolean_T apply_transform;
  real_T ztest0;
  int32_T ii;
  int32_T m;
  real_T rt;
  real_T ztest;
  int32_T iter;
  real_T snorm;
  boolean_T exitg1;
  int32_T exitg4;
  boolean_T exitg3;
  real_T f;
  real_T varargin_1[5];
  real_T mtmp;
  boolean_T exitg2;
  real_T sqds;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &eb_emlrtRSI;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
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
    c_st.site = &tb_emlrtRSI;
    ztest0 = eml_xnrm2(&c_st, 3 - q, b_A, qs + 1);
    if (ztest0 > 0.0) {
      apply_transform = true;
      if (b_A[qs] < 0.0) {
        s[q] = -ztest0;
      } else {
        s[q] = ztest0;
      }

      if (muDoubleScalarAbs(s[q]) >= 1.0020841800044864E-292) {
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
      c_st.site = &rb_emlrtRSI;
      ztest0 = b_eml_xnrm2(&c_st, e, 2);
      if (ztest0 == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          ztest0 = -ztest0;
        }

        e[0] = ztest0;
        if (muDoubleScalarAbs(ztest0) >= 1.0020841800044864E-292) {
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
      rt = muDoubleScalarAbs(s[q]);
      ztest = s[q] / rt;
      s[q] = rt;
      if (q + 1 < 3) {
        ztest0 = e[q] / ztest;
      }

      c_st.site = &pb_emlrtRSI;
      eml_xscal(&c_st, ztest, U, 1 + 3 * q);
    }

    if ((q + 1 < 3) && (ztest0 != 0.0)) {
      rt = muDoubleScalarAbs(ztest0);
      ztest = rt / ztest0;
      ztest0 = rt;
      s[q + 1] *= ztest;
      c_st.site = &ob_emlrtRSI;
      eml_xscal(&c_st, ztest, V, 1 + 3 * (q + 1));
    }

    e[q] = ztest0;
  }

  iter = 0;
  snorm = 0.0;
  for (ii = 0; ii < 3; ii++) {
    snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(s[ii]),
      muDoubleScalarAbs(e[ii])));
  }

  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      c_st.site = &nb_emlrtRSI;
      b_eml_error(&c_st);
    } else {
      ii = m;
      do {
        exitg4 = 0;
        q = ii + 1;
        if (ii + 1 == 0) {
          exitg4 = 1;
        } else {
          ztest0 = muDoubleScalarAbs(e[ii]);
          if ((ztest0 <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii]) +
                muDoubleScalarAbs(s[ii + 1]))) || (ztest0 <=
               1.0020841800044864E-292) || ((iter > 20) && (ztest0 <=
                2.2204460492503131E-16 * snorm))) {
            e[ii] = 0.0;
            exitg4 = 1;
          } else {
            ii--;
          }
        }
      } while (exitg4 == 0);

      if (ii + 1 == m + 1) {
        kase = 4;
      } else {
        qs = m + 2;
        kase = m + 2;
        exitg3 = false;
        while ((!exitg3) && (kase >= ii + 1)) {
          qs = kase;
          if (kase == ii + 1) {
            exitg3 = true;
          } else {
            ztest0 = 0.0;
            if (kase < m + 2) {
              ztest0 = muDoubleScalarAbs(e[kase - 1]);
            }

            if (kase > ii + 2) {
              ztest0 += muDoubleScalarAbs(e[kase - 2]);
            }

            ztest = muDoubleScalarAbs(s[kase - 1]);
            if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
                 1.0020841800044864E-292)) {
              s[kase - 1] = 0.0;
              exitg3 = true;
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
        varargin_1[0] = muDoubleScalarAbs(s[m + 1]);
        varargin_1[1] = muDoubleScalarAbs(s[m]);
        varargin_1[2] = muDoubleScalarAbs(e[m]);
        varargin_1[3] = muDoubleScalarAbs(s[q]);
        varargin_1[4] = muDoubleScalarAbs(e[q]);
        kase = 1;
        mtmp = varargin_1[0];
        if (muDoubleScalarIsNaN(varargin_1[0])) {
          ii = 2;
          exitg2 = false;
          while ((!exitg2) && (ii < 6)) {
            kase = ii;
            if (!muDoubleScalarIsNaN(varargin_1[ii - 1])) {
              mtmp = varargin_1[ii - 1];
              exitg2 = true;
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
          ztest = rt * rt + ztest0;
          c_st.site = &mb_emlrtRSI;
          b_sqrt(&c_st, &ztest);
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
          c_st.site = &fb_emlrtRSI;
          eml_xscal(&c_st, -1.0, V, 1 + 3 * q);
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
  }

  for (ii = 0; ii < 3; ii++) {
    S[ii] = s[ii];
  }
}

static real_T eml_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[9],
  int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  boolean_T b_ix0;
  int32_T k;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ub_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &vb_emlrtRSI;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  kend = (ix0 + n) - 1;
  c_st.site = &wb_emlrtRSI;
  if (ix0 > kend) {
    b_ix0 = false;
  } else {
    b_ix0 = (kend > 2147483646);
  }

  if (b_ix0) {
    d_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = ix0; k <= kend; k++) {
    absxk = muDoubleScalarAbs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * muDoubleScalarSqrt(y);
}

static void eml_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T temp;
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

static void eml_xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0)
{
  boolean_T b_ix0;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ac_emlrtRSI;
  c_st.site = &bc_emlrtRSI;
  if (ix0 > ix0 + 2) {
    b_ix0 = false;
  } else {
    b_ix0 = (ix0 + 2 > 2147483646);
  }

  if (b_ix0) {
    d_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

static void eml_xswap(real_T x[9], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T temp;
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

void orthog(const emlrtStack *sp, const real_T M_hat[16], real_T T[16])
{
  int32_T k;
  real_T b_M_hat[9];
  int32_T i18;
  real_T V[9];
  real_T s[3];
  real_T U[9];
  real_T Rx[9];
  int32_T i19;
  real_T x;
  static const int8_T iv15[4] = { 0, 0, 0, 1 };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  This function takes in a 4 by 4 matrix which has the form of */
  /*  [3 by 4; 0 0 0 n] and return a rigig transformation matrix by */
  /*  orthogonalizing the upper left 3 by 3 matrix into a rotation matrix */
  /*  opt = 1: Orthogonalize only the rotation part of M_hat  */
  /*  opt = 2: SVD the whole M_hat to obtain a transformation matrix */
  st.site = &w_emlrtRSI;
  for (k = 0; k < 9; k++) {
    if (!((!muDoubleScalarIsInf(M_hat[k % 3 + (div_nzp_s32_floor(k, 3) << 2)])) &&
          (!muDoubleScalarIsNaN(M_hat[k % 3 + (div_nzp_s32_floor(k, 3) << 2)]))))
    {
      b_st.site = &bb_emlrtRSI;
      eml_error(&b_st);
    }
  }

  for (k = 0; k < 3; k++) {
    for (i18 = 0; i18 < 3; i18++) {
      b_M_hat[i18 + 3 * k] = M_hat[i18 + (k << 2)];
    }
  }

  b_st.site = &cb_emlrtRSI;
  eml_xgesvd(&b_st, b_M_hat, U, s, V);
  for (k = 0; k < 3; k++) {
    for (i18 = 0; i18 < 3; i18++) {
      Rx[k + 3 * i18] = 0.0;
      for (i19 = 0; i19 < 3; i19++) {
        Rx[k + 3 * i18] += V[k + 3 * i19] * U[i18 + 3 * i19];
      }
    }
  }

  st.site = &x_emlrtRSI;
  if (det(&st, Rx) < 0.0) {
    for (k = 0; k < 3; k++) {
      Rx[6 + k] = -Rx[6 + k];
    }
  }

  st.site = &y_emlrtRSI;
  x = det(&st, Rx) - 1.0;
  if (muDoubleScalarAbs(x) > 1.0E-8) {
    st.site = &ab_emlrtRSI;
    d_fprintf(&st);
  }

  for (k = 0; k < 3; k++) {
    for (i18 = 0; i18 < 3; i18++) {
      T[i18 + (k << 2)] = Rx[i18 + 3 * k];
    }
  }

  for (k = 0; k < 3; k++) {
    T[12 + k] = M_hat[12 + k];
  }

  for (k = 0; k < 4; k++) {
    T[3 + (k << 2)] = iv15[k];
  }
}

/* End of code generation (orthog.c) */
