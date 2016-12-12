/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * param_extract.h
 *
 * Code generation for function 'param_extract'
 *
 */

#ifndef __PARAM_EXTRACT_H__
#define __PARAM_EXTRACT_H__

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
#include "batchEDSolve_types.h"

/* Function Declarations */
extern void param_extract(const emlrtStack *sp, const real_T X_in[16], real_T
  *theta, real_T N[9], real_T *d, real_T p[3]);

#endif

/* End of code generation (param_extract.h) */
