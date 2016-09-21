/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * det.c
 *
 * Code generation for function 'det'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_2nd.h"
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "mean_Taylor_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo sb_emlrtRSI = { 20, "det",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/det.m" };

/* Function Definitions */
real_T det(const emlrtStack *sp, const real_T x[9])
{
  real_T y;
  real_T A[9];
  int8_T ipiv[3];
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
  boolean_T isodd;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sb_emlrtRSI;
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
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  b_st.site = &tb_emlrtRSI;
  c_st.site = &ub_emlrtRSI;
  memcpy(&A[0], &x[0], 9U * sizeof(real_T));
  for (iy = 0; iy < 3; iy++) {
    ipiv[iy] = (int8_T)(1 + iy);
  }

  for (j = 0; j < 2; j++) {
    c = j << 2;
    d_st.site = &vb_emlrtRSI;
    e_st.site = &yb_emlrtRSI;
    f_st.site = &ac_emlrtRSI;
    iy = 0;
    ix = c;
    smax = muDoubleScalarAbs(A[c]);
    g_st.site = &bc_emlrtRSI;
    for (jy = 2; jy <= 3 - j; jy++) {
      ix++;
      s = muDoubleScalarAbs(A[ix]);
      if (s > smax) {
        iy = jy - 1;
        smax = s;
      }
    }

    if (A[c + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (int8_T)((j + iy) + 1);
        ix = j;
        iy += j;
        for (jy = 0; jy < 3; jy++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 3;
          iy += 3;
        }
      }

      b = (c - j) + 3;
      d_st.site = &wb_emlrtRSI;
      for (iy = c + 1; iy + 1 <= b; iy++) {
        A[iy] /= A[c];
      }
    }

    d_st.site = &xb_emlrtRSI;
    e_st.site = &cc_emlrtRSI;
    f_st.site = &dc_emlrtRSI;
    g_st.site = &ec_emlrtRSI;
    h_st.site = &fc_emlrtRSI;
    iy = c;
    jy = c + 3;
    for (b_j = 1; b_j <= 2 - j; b_j++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = c + 1;
        b = (iy - j) + 6;
        i_st.site = &gc_emlrtRSI;
        if (iy + 5 > b) {
          b_iy = false;
        } else {
          b_iy = (b > 2147483646);
        }

        if (b_iy) {
          j_st.site = &kb_emlrtRSI;
          check_forloop_overflow_error(&j_st);
        }

        for (ijA = iy + 4; ijA + 1 <= b; ijA++) {
          A[ijA] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 3;
      iy += 3;
    }
  }

  y = A[0];
  isodd = false;
  for (jy = 0; jy < 2; jy++) {
    y *= A[(jy + 3 * (jy + 1)) + 1];
    if (ipiv[jy] > 1 + jy) {
      isodd = !isodd;
    }
  }

  if (isodd) {
    y = -y;
  }

  return y;
}

/* End of code generation (det.c) */
