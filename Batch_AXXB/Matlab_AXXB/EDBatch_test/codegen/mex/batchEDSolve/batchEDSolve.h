/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * batchEDSolve.h
 *
 * Code generation for function 'batchEDSolve'
 *
 */

#ifndef __BATCHEDSOLVE_H__
#define __BATCHEDSOLVE_H__

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
extern void batchEDSolve(const emlrtStack *sp, const emxArray_real_T *A, const
  emxArray_real_T *B, creal_T X[16], real_T MeanA[16], real_T MeanB[16], real_T
  SigA[36], real_T SigB[36]);

#endif

/* End of code generation (batchEDSolve.h) */
