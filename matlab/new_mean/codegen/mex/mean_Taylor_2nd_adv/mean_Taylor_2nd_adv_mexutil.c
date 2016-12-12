/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_Taylor_2nd_adv_mexutil.c
 *
 * Code generation for function 'mean_Taylor_2nd_adv_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_2nd_adv.h"
#include "mean_Taylor_2nd_adv_mexutil.h"
#include "fprintf.h"
#include <stdio.h>

/* Function Definitions */
real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_feval, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(c_feval), &thisId);
  emlrtDestroyArray(&c_feval);
  return y;
}

real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/* End of code generation (mean_Taylor_2nd_adv_mexutil.c) */
