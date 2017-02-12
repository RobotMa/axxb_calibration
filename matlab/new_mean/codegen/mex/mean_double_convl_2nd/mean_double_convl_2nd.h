/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_double_convl_2nd.h
 *
 * Code generation for function 'mean_double_convl_2nd'
 *
 */

#ifndef __MEAN_DOUBLE_CONVL_2ND_H__
#define __MEAN_DOUBLE_CONVL_2ND_H__

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
#include "mean_double_convl_2nd_types.h"

/* Function Declarations */
extern void dynamic_size_checks(const emlrtStack *sp, const int32_T a_size[2]);
extern void eml_xgemm(int32_T n, int32_T k, const real_T A_data[], const real_T
                      B_data[], int32_T ldb, real_T C_data[]);
extern void mean_double_convl_2nd(const emlrtStack *sp, const real_T X1[800],
  const real_T X2[800], const real_T X3[800], int8_T s1, int8_T s2, int8_T s3,
  int16_T n_search, real_T diff, real_T M123_f[16]);

#endif

/* End of code generation (mean_double_convl_2nd.h) */
