/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mean_double_convl_2nd_api.c
 *
 * Code generation for function '_coder_mean_double_convl_2nd_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "_coder_mean_double_convl_2nd_api.h"
#include "fprintf.h"
#include "mean_double_convl_2nd_mexutil.h"
#include "mean_double_convl_2nd_data.h"
#include <stdio.h>

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u[16]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X1,
  const char_T *identifier))[800];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[800];
static int8_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *s1, const
  char_T *identifier);
static int8_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static int16_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *n_search,
  const char_T *identifier);
static int16_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[800];
static int8_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static int16_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u[16])
{
  const mxArray *y;
  static const int32_T iv23[2] = { 0, 0 };

  const mxArray *m5;
  static const int32_T iv24[2] = { 4, 4 };

  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv23, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m5, (void *)u);
  emlrtSetDimensions((mxArray *)m5, iv24, 2);
  emlrtAssign(&y, m5);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X1,
  const char_T *identifier))[800]
{
  real_T (*y)[800];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(X1), &thisId);
  emlrtDestroyArray(&X1);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[800]
{
  real_T (*y)[800];
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
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

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[800]
{
  real_T (*ret)[800];
  int32_T iv25[2];
  int32_T i22;
  for (i22 = 0; i22 < 2; i22++) {
    iv25[i22] = 4 + 196 * i22;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv25);
  ret = (real_T (*)[800])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static int8_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
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

void mean_double_convl_2nd_api(const mxArray * const prhs[8], const mxArray
  *plhs[1])
{
  real_T (*M123_f)[16];
  real_T (*X1)[800];
  real_T (*X2)[800];
  real_T (*X3)[800];
  int8_T s1;
  int8_T s2;
  int8_T s3;
  int16_T n_search;
  real_T diff;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  M123_f = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));

  /* Marshall function inputs */
  X1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X1");
  X2 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X2");
  X3 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "X3");
  s1 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "s1");
  s2 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "s2");
  s3 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "s3");
  n_search = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "n_search");
  diff = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "diff");

  /* Invoke the target function */
  mean_double_convl_2nd(&st, *X1, *X2, *X3, s1, s2, s3, n_search, diff, *M123_f);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(*M123_f);
}

/* End of code generation (_coder_mean_double_convl_2nd_api.c) */
