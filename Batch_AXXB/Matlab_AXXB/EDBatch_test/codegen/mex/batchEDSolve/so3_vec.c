/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * so3_vec.c
 *
 * Code generation for function 'so3_vec'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "so3_vec.h"

/* Variable Definitions */
static emlrtBCInfo h_emlrtBCI = { -1, -1, 15, 18, "X", "so3_vec",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/so3_vec.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 15, 23, "X", "so3_vec",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/so3_vec.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 16, 9, "X", "so3_vec",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/so3_vec.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 16, 26, "X", "so3_vec",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/so3_vec.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 17, 10, "X", "so3_vec",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/so3_vec.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 17, 17, "X", "so3_vec",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/so3_vec.m",
  0 };

/* Function Definitions */
void so3_vec(const emlrtStack *sp, const creal_T X_data[], const int32_T X_size
             [2], creal_T g_data[], int32_T g_size[2])
{
  creal_T X[3];
  int32_T i25;
  creal_T dcv2[9];
  int32_T i26;

  /* Function to vectorize or hat an element in so(3) */
  /* files needed: */
  /* none */
  if (X_size[1] == 3) {
    /* If input is skew-sym change to vector */
    X[0].re = -X_data[1 + (X_size[0] << 1)].re;
    X[0].im = -X_data[1 + (X_size[0] << 1)].im;
    X[1] = X_data[X_size[0] << 1];
    X[2].re = -X_data[X_size[0]].re;
    X[2].im = -X_data[X_size[0]].im;
    g_size[0] = 3;
    g_size[1] = 1;
    for (i25 = 0; i25 < 3; i25++) {
      g_data[i25] = X[i25];
    }
  } else {
    /* If input is vector change to skew-sym  */
    i25 = 3 * X_size[1];
    emlrtDynamicBoundsCheckR2012b(3, 1, i25, &h_emlrtBCI, sp);
    i25 = 3 * X_size[1];
    emlrtDynamicBoundsCheckR2012b(2, 1, i25, &i_emlrtBCI, sp);
    i25 = 3 * X_size[1];
    emlrtDynamicBoundsCheckR2012b(3, 1, i25, &j_emlrtBCI, sp);
    i25 = 3 * X_size[1];
    emlrtDynamicBoundsCheckR2012b(1, 1, i25, &k_emlrtBCI, sp);
    i25 = 3 * X_size[1];
    emlrtDynamicBoundsCheckR2012b(2, 1, i25, &l_emlrtBCI, sp);
    i25 = 3 * X_size[1];
    emlrtDynamicBoundsCheckR2012b(1, 1, i25, &m_emlrtBCI, sp);
    dcv2[0].re = 0.0;
    dcv2[0].im = 0.0;
    dcv2[3].re = -X_data[2].re;
    dcv2[3].im = -X_data[2].im;
    dcv2[6] = X_data[1];
    dcv2[1] = X_data[2];
    dcv2[4].re = 0.0;
    dcv2[4].im = 0.0;
    dcv2[7].re = -X_data[0].re;
    dcv2[7].im = -X_data[0].im;
    dcv2[2].re = -X_data[1].re;
    dcv2[2].im = -X_data[1].im;
    dcv2[5] = X_data[0];
    dcv2[8].re = 0.0;
    dcv2[8].im = 0.0;
    g_size[0] = 3;
    g_size[1] = 3;
    for (i25 = 0; i25 < 3; i25++) {
      for (i26 = 0; i26 < 3; i26++) {
        g_data[i26 + 3 * i25] = dcv2[i26 + 3 * i25];
      }
    }
  }
}

/* End of code generation (so3_vec.c) */
