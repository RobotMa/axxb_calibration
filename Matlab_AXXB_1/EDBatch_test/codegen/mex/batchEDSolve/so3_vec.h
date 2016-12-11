/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * so3_vec.h
 *
 * Code generation for function 'so3_vec'
 *
 */

#ifndef __SO3_VEC_H__
#define __SO3_VEC_H__

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
extern void so3_vec(const emlrtStack *sp, const creal_T X_data[], const int32_T
                    X_size[2], creal_T g_data[], int32_T g_size[2]);

#endif

/* End of code generation (so3_vec.h) */
