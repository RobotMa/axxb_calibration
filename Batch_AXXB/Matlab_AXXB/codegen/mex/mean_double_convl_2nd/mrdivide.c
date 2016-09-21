/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide.c
 *
 * Code generation for function 'mrdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "mrdivide.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "mean_double_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo dd_emlrtRSI = { 1, "mrdivide",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/mrdivide.p" };

static emlrtRTEInfo e_emlrtRTEI = { 1, 1, "mrdivide",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/mrdivide.p" };

/* Function Definitions */
void b_mrdivide(const emlrtStack *sp, real_T A[16], const real_T B[16])
{
  real_T b_A[16];
  int32_T info;
  int32_T ipiv[4];
  int32_T jp;
  int32_T jAcol;
  int32_T k;
  int32_T kBcol;
  int32_T i;
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &yc_emlrtRSI;
  memcpy(&b_A[0], &B[0], sizeof(real_T) << 4);
  c_st.site = &bd_emlrtRSI;
  eml_xgetrf(&c_st, b_A, ipiv, &info);
  if (info > 0) {
    c_st.site = &ad_emlrtRSI;
    d_st.site = &cd_emlrtRSI;
    eml_warning(&d_st);
  }

  for (info = 0; info < 4; info++) {
    jp = info << 2;
    jAcol = info << 2;
    for (k = 0; k + 1 <= info; k++) {
      kBcol = k << 2;
      if (b_A[k + jAcol] != 0.0) {
        for (i = 0; i < 4; i++) {
          A[i + jp] -= b_A[k + jAcol] * A[i + kBcol];
        }
      }
    }

    temp = 1.0 / b_A[info + jAcol];
    for (i = 0; i < 4; i++) {
      A[i + jp] *= temp;
    }
  }

  for (info = 3; info > -1; info += -1) {
    jp = info << 2;
    jAcol = info << 2;
    for (k = info + 1; k + 1 < 5; k++) {
      kBcol = k << 2;
      if (b_A[k + jAcol] != 0.0) {
        for (i = 0; i < 4; i++) {
          A[i + jp] -= b_A[k + jAcol] * A[i + kBcol];
        }
      }
    }
  }

  for (info = 2; info > -1; info += -1) {
    if (ipiv[info] != info + 1) {
      jp = ipiv[info] - 1;
      for (jAcol = 0; jAcol < 4; jAcol++) {
        temp = A[jAcol + (info << 2)];
        A[jAcol + (info << 2)] = A[jAcol + (jp << 2)];
        A[jAcol + (jp << 2)] = temp;
      }
    }
  }
}

void eml_xgetrf(const emlrtStack *sp, real_T A[16], int32_T ipiv[4], int32_T
                *info)
{
  int32_T iy;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T smax;
  int32_T jy;
  real_T s;
  int32_T b;
  int32_T b_j;
  boolean_T b_iy;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  b_st.site = &hc_emlrtRSI;
  for (iy = 0; iy < 4; iy++) {
    ipiv[iy] = 1 + iy;
  }

  *info = 0;
  for (j = 0; j < 3; j++) {
    c = j * 5;
    c_st.site = &ic_emlrtRSI;
    d_st.site = &lc_emlrtRSI;
    e_st.site = &mc_emlrtRSI;
    iy = 0;
    ix = c;
    smax = muDoubleScalarAbs(A[c]);
    f_st.site = &nc_emlrtRSI;
    for (jy = 2; jy <= 4 - j; jy++) {
      ix++;
      s = muDoubleScalarAbs(A[ix]);
      if (s > smax) {
        iy = jy - 1;
        smax = s;
      }
    }

    if (A[c + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (j + iy) + 1;
        ix = j;
        iy += j;
        for (jy = 0; jy < 4; jy++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 4;
          iy += 4;
        }
      }

      b = (c - j) + 4;
      c_st.site = &jc_emlrtRSI;
      for (iy = c + 1; iy + 1 <= b; iy++) {
        A[iy] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    c_st.site = &kc_emlrtRSI;
    d_st.site = &oc_emlrtRSI;
    e_st.site = &pc_emlrtRSI;
    f_st.site = &qc_emlrtRSI;
    g_st.site = &rc_emlrtRSI;
    iy = c;
    jy = c + 4;
    for (b_j = 1; b_j <= 3 - j; b_j++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = c + 1;
        b = (iy - j) + 8;
        h_st.site = &sc_emlrtRSI;
        if (iy + 6 > b) {
          b_iy = false;
        } else {
          b_iy = (b > 2147483646);
        }

        if (b_iy) {
          i_st.site = &wb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }

        for (ijA = iy + 5; ijA + 1 <= b; ijA++) {
          A[ijA] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 4;
      iy += 4;
    }
  }

  if ((*info == 0) && (!(A[15] != 0.0))) {
    *info = 4;
  }
}

void mrdivide(const emlrtStack *sp, const real_T A_data[], const int32_T A_size
              [2], const real_T B[16], real_T y_data[], int32_T y_size[2])
{
  real_T A[16];
  int32_T info;
  int32_T ipiv[4];
  int32_T jp;
  int32_T jAcol;
  int32_T k;
  int32_T kBcol;
  int32_T i;
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (4 == A_size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &e_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  st.site = &dd_emlrtRSI;
  b_st.site = &yc_emlrtRSI;
  memcpy(&A[0], &B[0], sizeof(real_T) << 4);
  c_st.site = &bd_emlrtRSI;
  eml_xgetrf(&c_st, A, ipiv, &info);
  if (info > 0) {
    c_st.site = &ad_emlrtRSI;
    d_st.site = &cd_emlrtRSI;
    eml_warning(&d_st);
  }

  y_size[0] = 4;
  y_size[1] = A_size[1];
  info = A_size[0] * A_size[1];
  for (jp = 0; jp < info; jp++) {
    y_data[jp] = A_data[jp];
  }

  for (info = 0; info < 4; info++) {
    jp = info << 2;
    jAcol = info << 2;
    for (k = 0; k + 1 <= info; k++) {
      kBcol = k << 2;
      if (A[k + jAcol] != 0.0) {
        for (i = 0; i < 4; i++) {
          y_data[i + jp] -= A[k + jAcol] * y_data[i + kBcol];
        }
      }
    }

    temp = 1.0 / A[info + jAcol];
    for (i = 0; i < 4; i++) {
      y_data[i + jp] *= temp;
    }
  }

  for (info = 3; info > -1; info += -1) {
    jp = info << 2;
    jAcol = info << 2;
    for (k = info + 1; k + 1 < 5; k++) {
      kBcol = k << 2;
      if (A[k + jAcol] != 0.0) {
        for (i = 0; i < 4; i++) {
          y_data[i + jp] -= A[k + jAcol] * y_data[i + kBcol];
        }
      }
    }
  }

  for (info = 2; info > -1; info += -1) {
    if (ipiv[info] != info + 1) {
      jp = ipiv[info] - 1;
      for (jAcol = 0; jAcol < 4; jAcol++) {
        temp = y_data[jAcol + (info << 2)];
        y_data[jAcol + (info << 2)] = y_data[jAcol + (jp << 2)];
        y_data[jAcol + (jp << 2)] = temp;
      }
    }
  }
}

/* End of code generation (mrdivide.c) */
