/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * distibutionPropsMex_mexutil.h
 *
 * Code generation for function 'distibutionPropsMex_mexutil'
 *
 */

#ifndef __DISTIBUTIONPROPSMEX_MEXUTIL_H__
#define __DISTIBUTIONPROPSMEX_MEXUTIL_H__

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
extern void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[16]);
extern void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_logm, const
  char_T *identifier, real_T y[16]);
extern void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[16]);

#endif

/* End of code generation (distibutionPropsMex_mexutil.h) */
