/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mean_convl_2nd_api.c
 *
 * Code generation for function '_coder_mean_convl_2nd_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "_coder_mean_convl_2nd_api.h"
#include "mean_convl_2nd_emxutil.h"
#include "mean_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo k_emlrtRTEI = { 1, 1, "_coder_mean_convl_2nd_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u[16]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X1, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static int8_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *s1, const
  char_T *identifier);
static int8_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static int16_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n_search,
  const char_T *identifier);
static int16_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static int8_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static int16_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u[16])
{
  const mxArray *y;
  static const int32_T iv24[2] = { 0, 0 };

  const mxArray *m6;
  static const int32_T iv25[2] = { 4, 4 };

  y = NULL;
  m6 = emlrtCreateNumericArray(2, iv24, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m6, (void *)u);
  emlrtSetDimensions((mxArray *)m6, iv25, 2);
  emlrtAssign(&y, m6);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X1, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(X1), &thisId, y);
  emlrtDestroyArray(&X1);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static int8_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *s1, const
  char_T *identifier)
{
  int8_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(s1), &thisId);
  emlrtDestroyArray(&s1);
  return y;
}

static int8_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int8_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static int16_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n_search,
  const char_T *identifier)
{
  int16_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = h_emlrt_marshallIn(sp, emlrtAlias(n_search), &thisId);
  emlrtDestroyArray(&n_search);
  return y;
}

static int16_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int16_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv26[2];
  int32_T i25;
  int32_T iv27[2];
  boolean_T bv0[2] = { false, true };

  for (i25 = 0; i25 < 2; i25++) {
    iv26[i25] = 4 + -5 * i25;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv26, &bv0[0],
    iv27);
  ret->size[0] = iv27[0];
  ret->size[1] = iv27[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static int8_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  int8_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int8", false, 0U, 0);
  ret = *(int8_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static int16_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int16_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int16", false, 0U, 0);
  ret = *(int16_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void mean_convl_2nd_api(const mxArray * const prhs[5], const mxArray *plhs[1])
{
  real_T (*M12_f)[16];
  emxArray_real_T *X1;
  emxArray_real_T *X2;
  int8_T s1;
  int8_T s2;
  int16_T n_search;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  M12_f = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &X1, 2, &k_emlrtRTEI, true);
  emxInit_real_T(&st, &X2, 2, &k_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X1", X1);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X2", X2);
  s1 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "s1");
  s2 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "s2");
  n_search = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "n_search");

  /* Invoke the target function */
  mean_convl_2nd(&st, X1, X2, s1, s2, n_search, *M12_f);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*M12_f);
  X2->canFreeData = false;
  emxFree_real_T(&X2);
  X1->canFreeData = false;
  emxFree_real_T(&X1);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_mean_convl_2nd_api.c) */
