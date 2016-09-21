/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mpower.h
 *
 * Code generation for function 'mpower'
 *
 */

#ifndef __MPOWER_H__
#define __MPOWER_H__

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
#include "distibutionPropsMex_types.h"

/* Function Declarations */
extern void eml_lapack_xgetrf(const emlrtStack *sp, real_T A[16], int32_T ipiv[4],
  int32_T *info);
extern void eml_xtrsm(const real_T A[16], real_T B[16]);
extern void mpower(const emlrtStack *sp, const real_T a[16], real_T c[16]);

#endif

/* End of code generation (mpower.h) */
