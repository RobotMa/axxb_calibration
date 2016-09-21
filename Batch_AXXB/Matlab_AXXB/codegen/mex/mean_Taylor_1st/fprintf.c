/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_1st.h"
#include "fprintf.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo yb_emlrtRSI = { 35, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo ac_emlrtRSI = { 69, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_feval,
  const char_T *identifier);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_fprintf(const emlrtStack *sp)
{
  int32_T i4;
  static const char_T cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 7 };

  const mxArray *m0;
  const mxArray *b_y;
  static const char_T formatSpec[33] = { 'A', ' ', 'n', 'o', 'n', ' ', 'r', 'o',
    't', 'a', 't', 'i', 'o', 'n', ' ', 'm', 'a', 't', 'r', 'i', 'x', ' ', 'i',
    's', ' ', 'r', 'e', 't', 'u', 'r', 'n', 'e', 'd' };

  char_T b_u[33];
  const mxArray *c_y;
  static const int32_T iv3[2] = { 1, 33 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i4 = 0; i4 < 7; i4++) {
    u[i4] = cv1[i4];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m0);
  for (i4 = 0; i4 < 33; i4++) {
    b_u[i4] = formatSpec[i4];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 33, m0, &b_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &ac_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &emlrtMCI), "feval");
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_feval,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_feval), &thisId);
  emlrtDestroyArray(&b_feval);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m2;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m2, 3, pArrays, "feval", true, location);
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yb_emlrtRSI;
  c_fprintf(&st);
}

/* End of code generation (fprintf.c) */
