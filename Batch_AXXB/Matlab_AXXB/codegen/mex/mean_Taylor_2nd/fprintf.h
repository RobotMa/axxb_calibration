/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fprintf.h
 *
 * Code generation for function 'fprintf'
 *
 */

#ifndef __FPRINTF_H__
#define __FPRINTF_H__

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
extern void b_fprintf(const emlrtStack *sp);
extern real_T d_fprintf(const emlrtStack *sp, real_T formatSpec);

#ifdef __WATCOMC__

#pragma aux d_fprintf value [8087];

#endif
#endif

/* End of code generation (fprintf.h) */
