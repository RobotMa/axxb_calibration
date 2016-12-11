/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * twistlog.h
 *
 * Code generation for function 'twistlog'
 *
 */

#ifndef __TWISTLOG_H__
#define __TWISTLOG_H__

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
extern void twistlog(const emlrtStack *sp, const emxArray_real_T *h, real_T
                     xi_hat[16]);

#endif

/* End of code generation (twistlog.h) */
