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
#include "mean_convl_2nd.h"
#include "fprintf.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 35, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo kd_emlrtRSI = { 38, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo md_emlrtRSI = { 69, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_fprintf(const emlrtStack *sp);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_feval,
  const char_T *identifier);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1);
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T i_fprintf(const emlrtStack *sp, real_T varargin_1);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m9, 4, pArrays, "feval", true, location);
}

static real_T c_fprintf(const emlrtStack *sp)
{
  int32_T i9;
  static const char_T cv0[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 7 };

  const mxArray *m0;
  const mxArray *b_y;
  static const char_T formatSpec[32] = { 'S', 'i', 'z', 'e', 's', ' ', 'o', 'f',
    ' ', 'X', '1', ' ', 'a', 'n', 'd', ' ', 'X', '2', ' ', 'd', 'o', ' ', 'n',
    'o', 't', ' ', 'm', 'a', 't', 'c', 'h', '.' };

  char_T b_u[32];
  const mxArray *c_y;
  static const int32_T iv7[2] = { 1, 32 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i9 = 0; i9 < 7; i9++) {
    u[i9] = cv0[i9];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m0);
  for (i9 = 0; i9 < 32; i9++) {
    b_u[i9] = formatSpec[i9];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 32, m0, &b_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &md_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp)
{
  int32_T i20;
  static const char_T cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv16[2] = { 1, 7 };

  const mxArray *m1;
  const mxArray *b_y;
  static const char_T formatSpec[33] = { 'A', ' ', 'n', 'o', 'n', ' ', 'r', 'o',
    't', 'a', 't', 'i', 'o', 'n', ' ', 'm', 'a', 't', 'r', 'i', 'x', ' ', 'i',
    's', ' ', 'r', 'e', 't', 'u', 'r', 'n', 'e', 'd' };

  char_T b_u[33];
  const mxArray *c_y;
  static const int32_T iv17[2] = { 1, 33 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i20 = 0; i20 < 7; i20++) {
    u[i20] = cv2[i20];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(sp, 7, m1, &u[0]);
  emlrtAssign(&y, m1);
  b_y = NULL;
  m1 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m1);
  for (i20 = 0; i20 < 33; i20++) {
    b_u[i20] = formatSpec[i20];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv17);
  emlrtInitCharArrayR2013a(sp, 33, m1, &b_u[0]);
  emlrtAssign(&c_y, m1);
  st.site = &md_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &emlrtMCI), "feval");
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_feval,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(c_feval), &thisId);
  emlrtDestroyArray(&c_feval);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 3, pArrays, "feval", true, location);
}

static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  int32_T i23;
  static const char_T cv3[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv20[2] = { 1, 7 };

  const mxArray *m3;
  const mxArray *b_y;
  static const char_T formatSpec[26] = { 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o',
    'f', ' ', 'i', 't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', ' ', 'i', 's',
    ' ', '%', 'f' };

  char_T b_u[26];
  const mxArray *c_y;
  static const int32_T iv21[2] = { 1, 26 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i23 = 0; i23 < 7; i23++) {
    u[i23] = cv3[i23];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv20);
  emlrtInitCharArrayR2013a(sp, 7, m3, &u[0]);
  emlrtAssign(&y, m3);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m3);
  for (i23 = 0; i23 < 26; i23++) {
    b_u[i23] = formatSpec[i23];
  }

  c_y = NULL;
  m3 = emlrtCreateCharArray(2, iv21);
  emlrtInitCharArrayR2013a(sp, 26, m3, &b_u[0]);
  emlrtAssign(&c_y, m3);
  d_y = NULL;
  m3 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m3);
  st.site = &md_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &emlrtMCI),
    "feval");
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T i_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  int32_T i24;
  static const char_T cv4[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv22[2] = { 1, 7 };

  const mxArray *m4;
  const mxArray *b_y;
  static const char_T formatSpec[31] = { 'V', 'a', 'l', 'u', 'e', ' ', 'o', 'f',
    ' ', 'c', 'o', 's', 't', ' ', 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n', ' ',
    'i', 's', ' ', '%', 'f', ' ', '\\', 'n' };

  char_T b_u[31];
  const mxArray *c_y;
  static const int32_T iv23[2] = { 1, 31 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i24 = 0; i24 < 7; i24++) {
    u[i24] = cv4[i24];
  }

  y = NULL;
  m4 = emlrtCreateCharArray(2, iv22);
  emlrtInitCharArrayR2013a(sp, 7, m4, &u[0]);
  emlrtAssign(&y, m4);
  b_y = NULL;
  m4 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m4);
  for (i24 = 0; i24 < 31; i24++) {
    b_u[i24] = formatSpec[i24];
  }

  c_y = NULL;
  m4 = emlrtCreateCharArray(2, iv23);
  emlrtInitCharArrayR2013a(sp, 31, m4, &b_u[0]);
  emlrtAssign(&c_y, m4);
  d_y = NULL;
  m4 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m4);
  st.site = &md_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &emlrtMCI),
    "feval");
}

real_T b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  return c_fprintf(&st);
}

void d_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  e_fprintf(&st);
}

real_T f_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kd_emlrtRSI;
  return g_fprintf(&st, formatSpec);
}

real_T h_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kd_emlrtRSI;
  return i_fprintf(&st, formatSpec);
}

/* End of code generation (fprintf.c) */
