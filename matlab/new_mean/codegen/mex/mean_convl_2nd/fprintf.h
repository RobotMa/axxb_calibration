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
#include "mean_convl_2nd_types.h"

/* Function Declarations */
extern real_T b_fprintf(const emlrtStack *sp);

#ifdef __WATCOMC__

#pragma aux b_fprintf value [8087];

#endif

extern void d_fprintf(const emlrtStack *sp);
extern real_T f_fprintf(const emlrtStack *sp, real_T formatSpec);

#ifdef __WATCOMC__

#pragma aux f_fprintf value [8087];

#endif

extern real_T h_fprintf(const emlrtStack *sp, real_T formatSpec);

#ifdef __WATCOMC__

#pragma aux h_fprintf value [8087];

#endif
#endif

/* End of code generation (fprintf.h) */
