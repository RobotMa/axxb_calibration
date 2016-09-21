/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_distibutionPropsMex_api.c
 *
 * Code generation for function '_coder_distibutionPropsMex_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "_coder_distibutionPropsMex_api.h"
#include "distibutionPropsMex_emxutil.h"
#include "distibutionPropsMex_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, 1, "_coder_distibutionPropsMex_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u[36]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const real_T u[16]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u[36])
{
  const mxArray *y;
  static const int32_T iv15[2] = { 0, 0 };

  const mxArray *m5;
  static const int32_T iv16[2] = { 6, 6 };

  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv15, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m5, (void *)u);
  emlrtSetDimensions((mxArray *)m5, iv16, 2);
  emlrtAssign(&y, m5);
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
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const real_T u[16])
{
  const mxArray *y;
  static const int32_T iv13[2] = { 0, 0 };

  const mxArray *m4;
  static const int32_T iv14[2] = { 4, 4 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv13, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)u);
  emlrtSetDimensions((mxArray *)m4, iv14, 2);
  emlrtAssign(&y, m4);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv18[2];
  int32_T i15;
  int32_T iv19[2];
  boolean_T bv0[2] = { false, true };

  for (i15 = 0; i15 < 2; i15++) {
    iv18[i15] = 4 + -5 * i15;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv18, &bv0[0],
    iv19);
  ret->size[0] = iv19[0];
  ret->size[1] = iv19[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void distibutionPropsMex_api(const mxArray * const prhs[1], const mxArray *plhs
  [2])
{
  real_T (*M)[16];
  real_T (*Sig)[36];
  emxArray_real_T *X;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  M = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));
  Sig = (real_T (*)[36])mxMalloc(sizeof(real_T [36]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &X, 2, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X", X);

  /* Invoke the target function */
  distibutionPropsMex(&st, X, *M, *Sig);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*M);
  plhs[1] = b_emlrt_marshallOut(*Sig);
  X->canFreeData = false;
  emxFree_real_T(&X);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_distibutionPropsMex_api.c) */
