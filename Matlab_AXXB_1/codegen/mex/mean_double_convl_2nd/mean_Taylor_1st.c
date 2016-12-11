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
#include "mean_double_convl_2nd.h"
#include "mean_Taylor_1st.h"
#include "orthog.h"
#include "mean_double_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 20, "mean_Taylor_1st",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_1st.m"
};

static emlrtECInfo e_emlrtECI = { 2, 15, 13, "mean_Taylor_1st",
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
  st.site = &u_emlrtRSI;
  orthog(&st, dv0, M_t1);
}

void mean_Taylor_1st(const emlrtStack *sp, const real_T X[800], real_T M_t1[16])
{
  real_T M_hat[16];
  int32_T i;
  int32_T i12;
  int32_T i13;
  int16_T X_size[2];
  int32_T iv13[2];
  int32_T b_X[2];
  int32_T b_i;
  real_T X_data[800];
  int32_T i14;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  This function calculates the 1st order approximation of the mean of a */
  /*  bunch of matrices based on the Taylor expansion of the matrix logarithm */
  /*  and the definition of mean of a probability density function. */
  /*  Input: X is a 4 by 4*n rigid transformation matrices */
  /*  Output: M_T1 is the mean of the 1st order approximation of Taylor */
  /*  expansion */
  memset(&M_hat[0], 0, sizeof(real_T) << 4);
  i = 0;
  while (i < 50) {
    i12 = (i << 2) + 1;
    i13 = (1 + i) << 2;
    if (i12 > i13) {
      i12 = 0;
      i13 = 0;
    } else {
      i12--;
    }

    X_size[0] = 4;
    X_size[1] = (int16_T)(i13 - i12);
    for (b_i = 0; b_i < 2; b_i++) {
      iv13[b_i] = 4;
      b_X[b_i] = X_size[b_i];
    }

    if ((4 != b_X[0]) || (4 != b_X[1])) {
      emlrtSizeEqCheckNDR2012b(iv13, b_X, &e_emlrtECI, sp);
    }

    b_i = i13 - i12;
    for (i13 = 0; i13 < b_i; i13++) {
      for (i14 = 0; i14 < 4; i14++) {
        X_data[i14 + (i13 << 2)] = X[i14 + ((i12 + i13) << 2)];
      }
    }

    for (i12 = 0; i12 < 4; i12++) {
      for (i13 = 0; i13 < 4; i13++) {
        M_hat[i13 + (i12 << 2)] += X_data[i13 + (i12 << 2)];
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i12 = 0; i12 < 16; i12++) {
    M_hat[i12] *= 0.02;
  }

  /*  Note that M_hat doesn't belong to SE(3) */
  st.site = &u_emlrtRSI;
  orthog(&st, M_hat, M_t1);
}

/* End of code generation (mean_Taylor_1st.c) */
