/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_Taylor_1st.h
 *
 * Code generation for function 'mean_Taylor_1st'
 *
 */

#ifndef __MEAN_TAYLOR_1ST_H__
#define __MEAN_TAYLOR_1ST_H__

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
#include "mean_Taylor_2nd_types.h"

/* Function Declarations */
extern void mean_Taylor_1st(const emlrtStack *sp, const emxArray_real_T *X,
  real_T M_1[16]);

#endif

/* End of code generation (mean_Taylor_1st.h) */
