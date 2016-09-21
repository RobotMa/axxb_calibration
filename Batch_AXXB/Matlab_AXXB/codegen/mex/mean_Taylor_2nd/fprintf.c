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
#include "mean_Taylor_2nd.h"
#include "fprintf.h"
#include "mean_Taylor_2nd_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo hc_emlrtRSI = { 35, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo wc_emlrtRSI = { 38, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo yc_emlrtRSI = { 69, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

/* Function Declarations */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 4, pArrays, "feval", true, location);
}

static real_T c_fprintf(const emlrtStack *sp)
{
  int32_T i7;
  static const char_T cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 7 };

  const mxArray *m0;
  const mxArray *b_y;
  static const char_T formatSpec[33] = { 'A', ' ', 'n', 'o', 'n', ' ', 'r', 'o',
    't', 'a', 't', 'i', 'o', 'n', ' ', 'm', 'a', 't', 'r', 'i', 'x', ' ', 'i',
    's', ' ', 'r', 'e', 't', 'u', 'r', 'n', 'e', 'd' };

  char_T b_u[33];
  const mxArray *c_y;
  static const int32_T iv9[2] = { 1, 33 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i7 = 0; i7 < 7; i7++) {
    u[i7] = cv1[i7];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m0);
  for (i7 = 0; i7 < 33; i7++) {
    b_u[i7] = formatSpec[i7];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 33, m0, &b_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &yc_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  int32_T i10;
  static const char_T cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv12[2] = { 1, 7 };

  const mxArray *m2;
  const mxArray *b_y;
  static const char_T formatSpec[26] = { 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o',
    'f', ' ', 'i', 't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', ' ', 'i', 's',
    ' ', '%', 'f' };

  char_T b_u[26];
  const mxArray *c_y;
  static const int32_T iv13[2] = { 1, 26 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i10 = 0; i10 < 7; i10++) {
    u[i10] = cv2[i10];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 7, m2, &u[0]);
  emlrtAssign(&y, m2);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m2);
  for (i10 = 0; i10 < 26; i10++) {
    b_u[i10] = formatSpec[i10];
  }

  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv13);
  emlrtInitCharArrayR2013a(sp, 26, m2, &b_u[0]);
  emlrtAssign(&c_y, m2);
  d_y = NULL;
  m2 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m2);
  st.site = &yc_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &emlrtMCI),
    "feval");
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 3, pArrays, "feval", true, location);
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hc_emlrtRSI;
  c_fprintf(&st);
}

real_T d_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  return e_fprintf(&st, formatSpec);
}

/* End of code generation (fprintf.c) */
