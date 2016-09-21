/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_convl_2nd.h
 *
 * Code generation for function 'mean_convl_2nd'
 *
 */

#ifndef __MEAN_CONVL_2ND_H__
#define __MEAN_CONVL_2ND_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "mean_convl_2nd_types.h"

/* Function Declarations */
extern void mean_convl_2nd(const emlrtStack *sp, const emxArray_real_T *X1,
  const emxArray_real_T *X2, int8_T s1, int8_T s2, int16_T n_search, real_T
  M12_f[16]);

#endif

/* End of code generation (mean_convl_2nd.h) */
