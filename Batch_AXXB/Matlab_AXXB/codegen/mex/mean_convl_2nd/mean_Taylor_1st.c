/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_Taylor_1st.c
 *
 * Code generation for function 'mean_Taylor_1st'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "mean_Taylor_1st.h"
#include "orthog.h"
#include "mean_convl_2nd_emxutil.h"
#include "mean_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 20, "mean_Taylor_1st",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_1st.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 8, 26, "mean_Taylor_1st",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_1st.m"
};

static emlrtECInfo e_emlrtECI = { 2, 15, 13, "mean_Taylor_1st",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_1st.m"
};

static emlrtBCInfo f_emlrtBCI = { -1, -1, 15, 25, "X", "mean_Taylor_1st",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_1st.m",
  0 };

static emlrtRTEInfo p_emlrtRTEI = { 14, 1, "mean_Taylor_1st",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_1st.m"
};

/* Function Definitions */
void b_mean_Taylor_1st(const emlrtStack *sp, const real_T X[16], real_T M_t1[16])
{
  real_T dv0[16];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  This function calculates the 1st order approximation of the mean of a */
  /*  bunch of matrices based on the Taylor expansion of the matrix logarithm */
  /*  and the definition of mean of a probability density function. */
  /*  Input: X is a 4 by 4*n rigid transformation matrices */
  /*  Output: M_T1 is the mean of the 1st order approximation of Taylor */
  /*  expansion */
  /*  Note that M_hat doesn't belong to SE(3) */
  memcpy(&dv0[0], &X[0], sizeof(real_T) << 4);
  st.site = &v_emlrtRSI;
  orthog(&st, dv0, M_t1);
}

void mean_Taylor_1st(const emlrtStack *sp, const emxArray_real_T *X, real_T
                     M_t1[16])
{
  real_T n;
  real_T M_hat[16];
  int32_T i;
  emxArray_real_T *b_X;
  emxArray_real_T *c_X;
  int32_T i14;
  uint32_T u0;
  int32_T i15;
  int32_T i16;
  int32_T b_i;
  int32_T iv14[2];
  int32_T loop_ub;
  int32_T i17;
  int32_T d_X[2];
  real_T y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  This function calculates the 1st order approximation of the mean of a */
  /*  bunch of matrices based on the Taylor expansion of the matrix logarithm */
  /*  and the definition of mean of a probability density function. */
  /*  Input: X is a 4 by 4*n rigid transformation matrices */
  /*  Output: M_T1 is the mean of the 1st order approximation of Taylor */
  /*  expansion */
  n = (real_T)X->size[1] / 4.0;
  memset(&M_hat[0], 0, sizeof(real_T) << 4);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
    &p_emlrtRTEI, sp);
  i = 0;
  emxInit_real_T(sp, &b_X, 2, &j_emlrtRTEI, true);
  emxInit_real_T(sp, &c_X, 2, &j_emlrtRTEI, true);
  while (i <= (int32_T)n - 1) {
    i14 = (i << 2) + 1;
    u0 = (uint32_T)(1 + i) << 2;
    if ((uint32_T)i14 > u0) {
      i14 = 0;
      i15 = 0;
    } else {
      i15 = X->size[1];
      if (i14 < i15) {
        i16 = i14;
      } else {
        i16 = emlrtDynamicBoundsCheckR2012b(i14, 1, i15, &f_emlrtBCI, sp);
      }

      i14 = i16 - 1;
      i15 = X->size[1];
      b_i = (int32_T)u0;
      if ((b_i >= 1) && (b_i < i15)) {
        i15 = b_i;
      } else {
        i15 = emlrtDynamicBoundsCheckR2012b(b_i, 1, i15, &f_emlrtBCI, sp);
      }
    }

    for (b_i = 0; b_i < 2; b_i++) {
      iv14[b_i] = 4;
    }

    b_i = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 4;
    b_X->size[1] = i15 - i14;
    emxEnsureCapacity(sp, (emxArray__common *)b_X, b_i, (int32_T)sizeof(real_T),
                      &j_emlrtRTEI);
    loop_ub = i15 - i14;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      for (i17 = 0; i17 < 4; i17++) {
        b_X->data[i17 + b_X->size[0] * b_i] = X->data[i17 + X->size[0] * (i14 +
          b_i)];
      }
    }

    for (b_i = 0; b_i < 2; b_i++) {
      d_X[b_i] = b_X->size[b_i];
    }

    if ((4 != d_X[0]) || (4 != d_X[1])) {
      emlrtSizeEqCheckNDR2012b(iv14, d_X, &e_emlrtECI, sp);
    }

    b_i = c_X->size[0] * c_X->size[1];
    c_X->size[0] = 4;
    c_X->size[1] = i15 - i14;
    emxEnsureCapacity(sp, (emxArray__common *)c_X, b_i, (int32_T)sizeof(real_T),
                      &j_emlrtRTEI);
    loop_ub = i15 - i14;
    for (i15 = 0; i15 < loop_ub; i15++) {
      for (b_i = 0; b_i < 4; b_i++) {
        c_X->data[b_i + c_X->size[0] * i15] = X->data[b_i + X->size[0] * (i14 +
          i15)];
      }
    }

    for (i14 = 0; i14 < 4; i14++) {
      for (i15 = 0; i15 < 4; i15++) {
        M_hat[i15 + (i14 << 2)] += c_X->data[i15 + (i14 << 2)];
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&c_X);
  emxFree_real_T(&b_X);
  y = 1.0 / n;
  for (i14 = 0; i14 < 16; i14++) {
    M_hat[i14] *= y;
  }

  /*  Note that M_hat doesn't belong to SE(3) */
  st.site = &v_emlrtRSI;
  orthog(&st, M_hat, M_t1);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mean_Taylor_1st.c) */
