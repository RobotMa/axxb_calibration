/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * det.h
 *
 * Code generation for function 'det'
 *
 */

#ifndef __DET_H__
#define __DET_H__

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
extern creal_T det(const emlrtStack *sp, const creal_T x_data[], const int32_T
                   x_size[2]);

#endif

/* End of code generation (det.h) */
