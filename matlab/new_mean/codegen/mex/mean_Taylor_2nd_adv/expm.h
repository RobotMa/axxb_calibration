/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * expm.h
 *
 * Code generation for function 'expm'
 *
 */

#ifndef __EXPM_H__
#define __EXPM_H__

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
#include "mean_Taylor_2nd_adv_types.h"

/* Function Declarations */
extern void expm(const emlrtStack *sp, real_T A[16], real_T F[16]);

#endif

/* End of code generation (expm.h) */
