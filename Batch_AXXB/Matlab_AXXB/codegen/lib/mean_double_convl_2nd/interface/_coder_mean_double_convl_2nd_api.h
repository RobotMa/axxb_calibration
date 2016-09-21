/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mean_double_convl_2nd_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 11-Jun-2015 01:46:04
 */

#ifndef ___CODER_MEAN_DOUBLE_CONVL_2ND_API_H__
#define ___CODER_MEAN_DOUBLE_CONVL_2ND_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_mean_double_convl_2nd_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void mean_double_convl_2nd(real_T X1[800], real_T X2[800], real_T X3[800],
  int8_T s1, int8_T s2, int8_T s3, int16_T n_search, real_T diff, real_T M123_f
  [16]);
extern void mean_double_convl_2nd_api(const mxArray *prhs[8], const mxArray
  *plhs[1]);
extern void mean_double_convl_2nd_atexit(void);
extern void mean_double_convl_2nd_initialize(void);
extern void mean_double_convl_2nd_terminate(void);
extern void mean_double_convl_2nd_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mean_double_convl_2nd_api.h
 *
 * [EOF]
 */
