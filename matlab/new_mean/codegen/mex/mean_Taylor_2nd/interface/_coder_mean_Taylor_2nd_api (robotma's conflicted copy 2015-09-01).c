/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mean_Taylor_2nd_api.c
 *
 * Code generation for function '_coder_mean_Taylor_2nd_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_2nd.h"
#include "_coder_mean_Taylor_2nd_api.h"
#include "mean_Taylor_2nd_emxutil.h"
#include "fprintf.h"
#include "mean_Taylor_2nd_mexutil.h"
#include "mean_Taylor_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = { 1, 1, "_coder_mean_Taylor_2nd_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u[16]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static int16_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *num,
  const char_T *identifier);
static int16_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static int16_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u[16])
{
  const mxArray *y;
  static const int32_T iv14[2] = { 0, 0 };

  const mxArray *m4;
  static const int32_T iv15[2] = { 4, 4 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv14, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)u);
  emlrtSetDimensions((mxArray *)m4, iv15, 2);
  emlrtAssign(&y, m4);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(X), &thisId, y);
  emlrtDestroyArray(&X);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static int16_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *num,
  const char_T *identifier)
{
  int16_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(num), &thisId);
  emlrtDestroyArray(&num);
  return y;
}

static int16_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int16_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv16[2];
  int32_T i13;
  int32_T iv17[2];
  boolean_T bv0[2] = { false, true };

  for (i13 = 0; i13 < 2; i13++) {
    iv16[i13] = 4 + -5 * i13;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv16, &bv0[0],
    iv17);
  ret->size[0] = iv17[0];
  ret->size[1] = iv17[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static int16_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int16_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int16", false, 0U, 0);
  ret = *(int16_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void mean_Taylor_2nd_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
  real_T (*MX)[16];
  emxArray_real_T *X;
  real_T noise;
  int16_T num;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  MX = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &X, 2, &e_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X", X);
  noise = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "noise");
  num = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "num");

  /* Invoke the target function */
  mean_Taylor_2nd(&st, X, noise, num, *MX);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*MX);
  X->canFreeData = false;
  emxFree_real_T(&X);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_mean_Taylor_2nd_api.c) */
