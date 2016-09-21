/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * se3_vec.h
 *
 * Code generation for function 'se3_vec'
 *
 */

#ifndef __SE3_VEC_H__
#define __SE3_VEC_H__

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
extern void se3_vec(const emlrtStack *sp, const mxArray *X, real_T g_data[],
                    int32_T g_size[2]);

#endif

/* End of code generation (se3_vec.h) */
