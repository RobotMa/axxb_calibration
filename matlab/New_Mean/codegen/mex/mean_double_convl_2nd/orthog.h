/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * orthog.h
 *
 * Code generation for function 'orthog'
 *
 */

#ifndef __ORTHOG_H__
#define __ORTHOG_H__

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
extern void orthog(const emlrtStack *sp, const real_T M_hat[16], real_T T[16]);

#endif

/* End of code generation (orthog.h) */
