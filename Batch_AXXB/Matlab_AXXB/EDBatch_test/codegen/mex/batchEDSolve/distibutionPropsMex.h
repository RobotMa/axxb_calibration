/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * distibutionPropsMex.h
 *
 * Code generation for function 'distibutionPropsMex'
 *
 */

#ifndef __DISTIBUTIONPROPSMEX_H__
#define __DISTIBUTIONPROPSMEX_H__

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
extern void distibutionPropsMex(const emlrtStack *sp, const emxArray_real_T *X,
  real_T M[16], real_T Sig[36]);

#endif

/* End of code generation (distibutionPropsMex.h) */
