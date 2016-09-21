/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide.h
 *
 * Code generation for function 'mrdivide'
 *
 */

#ifndef __MRDIVIDE_H__
#define __MRDIVIDE_H__

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
extern void b_mrdivide(const emlrtStack *sp, real_T A[16], const real_T B[16]);
extern void eml_xgetrf(const emlrtStack *sp, real_T A[16], int32_T ipiv[4],
  int32_T *info);
extern void mrdivide(const emlrtStack *sp, const real_T A_data[], const int32_T
                     A_size[2], const real_T B[16], real_T y_data[], int32_T
                     y_size[2]);

#endif

/* End of code generation (mrdivide.h) */
