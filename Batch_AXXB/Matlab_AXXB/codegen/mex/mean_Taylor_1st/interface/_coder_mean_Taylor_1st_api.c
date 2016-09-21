/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mean_Taylor_1st_api.c
 *
 * Code generation for function '_coder_mean_Taylor_1st_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_1st.h"
#include "_coder_mean_Taylor_1st_api.h"
#include "mean_Taylor_1st_emxutil.h"
#include "mean_Taylor_1st_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, 1, "_coder_mean_Taylor_1st_api", "" };

/* Function Declarations */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const real_T u[16]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
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
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const real_T u[16])
{
  const mxArray *y;
  static const int32_T iv4[2] = { 0, 0 };

  const mxArray *m1;
  static const int32_T iv5[2] = { 4, 4 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv4, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)u);
  emlrtSetDimensions((mxArray *)m1, iv5, 2);
  emlrtAssign(&y, m1);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv6[2];
  int32_T i5;
  int32_T iv7[2];
  boolean_T bv0[2] = { false, true };

  for (i5 = 0; i5 < 2; i5++) {
    iv6[i5] = 4 + -5 * i5;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv6, &bv0[0],
    iv7);
  ret->size[0] = iv7[0];
  ret->size[1] = iv7[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void mean_Taylor_1st_api(const mxArray * const prhs[1], const mxArray *plhs[2])
{
  real_T (*M_1)[16];
  real_T (*M_hat)[16];
  emxArray_real_T *X;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  M_1 = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));
  M_hat = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &X, 2, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X", X);

  /* Invoke the target function */
  mean_Taylor_1st(&st, X, *M_1, *M_hat);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*M_1);
  plhs[1] = emlrt_marshallOut(*M_hat);
  X->canFreeData = false;
  emxFree_real_T(&X);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_mean_Taylor_1st_api.c) */
