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
#include "mean_Taylor_2nd_adv.h"
#include "fprintf.h"
#include "mean_Taylor_2nd_adv_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 35, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo yc_emlrtRSI = { 38, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo bd_emlrtRSI = { 69, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

/* Function Declarations */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1);
static real_T i_fprintf(const emlrtStack *sp, real_T varargin_1);

/* Function Definitions */
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
  static const char_T cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv9[2] = { 1, 7 };

  const mxArray *m0;
  const mxArray *b_y;
  static const char_T formatSpec[33] = { 'A', ' ', 'n', 'o', 'n', ' ', 'r', 'o',
    't', 'a', 't', 'i', 'o', 'n', ' ', 'm', 'a', 't', 'r', 'i', 'x', ' ', 'i',
    's', ' ', 'r', 'e', 't', 'u', 'r', 'n', 'e', 'd' };

  char_T b_u[33];
  const mxArray *c_y;
  static const int32_T iv10[2] = { 1, 33 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i9 = 0; i9 < 7; i9++) {
    u[i9] = cv1[i9];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m0);
  for (i9 = 0; i9 < 33; i9++) {
    b_u[i9] = formatSpec[i9];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 33, m0, &b_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &bd_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  int32_T i12;
  static const char_T cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv13[2] = { 1, 7 };

  const mxArray *m2;
  const mxArray *b_y;
  static const char_T formatSpec[18] = { 'E', 'r', 'r', 'o', 'r', ' ', 'C', 'A',
    '1', ' ', 'i', 's', ' ', '%', 'f', ' ', '\\', 'n' };

  char_T b_u[18];
  const mxArray *c_y;
  static const int32_T iv14[2] = { 1, 18 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i12 = 0; i12 < 7; i12++) {
    u[i12] = cv2[i12];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv13);
  emlrtInitCharArrayR2013a(sp, 7, m2, &u[0]);
  emlrtAssign(&y, m2);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m2);
  for (i12 = 0; i12 < 18; i12++) {
    b_u[i12] = formatSpec[i12];
  }

  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv14);
  emlrtInitCharArrayR2013a(sp, 18, m2, &b_u[0]);
  emlrtAssign(&c_y, m2);
  d_y = NULL;
  m2 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m2);
  st.site = &bd_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &emlrtMCI),
    "feval");
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
  int32_T i13;
  static const char_T cv3[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv15[2] = { 1, 7 };

  const mxArray *m3;
  const mxArray *b_y;
  static const char_T formatSpec[18] = { 'E', 'r', 'r', 'o', 'r', ' ', 'C', 'A',
    '2', ' ', 'i', 's', ' ', '%', 'f', ' ', '\\', 'n' };

  char_T b_u[18];
  const mxArray *c_y;
  static const int32_T iv16[2] = { 1, 18 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i13 = 0; i13 < 7; i13++) {
    u[i13] = cv3[i13];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv15);
  emlrtInitCharArrayR2013a(sp, 7, m3, &u[0]);
  emlrtAssign(&y, m3);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m3);
  for (i13 = 0; i13 < 18; i13++) {
    b_u[i13] = formatSpec[i13];
  }

  c_y = NULL;
  m3 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(sp, 18, m3, &b_u[0]);
  emlrtAssign(&c_y, m3);
  d_y = NULL;
  m3 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m3);
  st.site = &bd_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &emlrtMCI),
    "feval");
}

static real_T i_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  int32_T i14;
  static const char_T cv4[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv17[2] = { 1, 7 };

  const mxArray *m4;
  const mxArray *b_y;
  static const char_T formatSpec[29] = { 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o',
    'f', ' ', 'i', 't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', ' ', 'i', 's',
    ' ', '%', 'f', ' ', '\\', 'n' };

  char_T b_u[29];
  const mxArray *c_y;
  static const int32_T iv18[2] = { 1, 29 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i14 = 0; i14 < 7; i14++) {
    u[i14] = cv4[i14];
  }

  y = NULL;
  m4 = emlrtCreateCharArray(2, iv17);
  emlrtInitCharArrayR2013a(sp, 7, m4, &u[0]);
  emlrtAssign(&y, m4);
  b_y = NULL;
  m4 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m4);
  for (i14 = 0; i14 < 29; i14++) {
    b_u[i14] = formatSpec[i14];
  }

  c_y = NULL;
  m4 = emlrtCreateCharArray(2, iv18);
  emlrtInitCharArrayR2013a(sp, 29, m4, &b_u[0]);
  emlrtAssign(&c_y, m4);
  d_y = NULL;
  m4 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m4);
  st.site = &bd_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &emlrtMCI),
    "feval");
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jc_emlrtRSI;
  c_fprintf(&st);
}

real_T d_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yc_emlrtRSI;
  return e_fprintf(&st, formatSpec);
}

real_T f_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yc_emlrtRSI;
  return g_fprintf(&st, formatSpec);
}

real_T h_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yc_emlrtRSI;
  return i_fprintf(&st, formatSpec);
}

/* End of code generation (fprintf.c) */
