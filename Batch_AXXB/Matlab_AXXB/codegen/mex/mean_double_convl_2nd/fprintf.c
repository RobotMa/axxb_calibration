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
#include "mean_double_convl_2nd.h"
#include "fprintf.h"
#include "mean_double_convl_2nd_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo tc_emlrtRSI = { 35, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo kd_emlrtRSI = { 38, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo md_emlrtRSI = { 69, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

/* Function Declarations */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, const
  mxArray *g, emlrtMCInfo *location);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2, real_T varargin_3);

/* Function Definitions */
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m8, 4, pArrays, "feval", true, location);
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, const
  mxArray *g, emlrtMCInfo *location)
{
  const mxArray *pArrays[6];
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  pArrays[5] = g;
  return emlrtCallMATLABR2012b(sp, 1, &m9, 6, pArrays, "feval", true, location);
}

static real_T c_fprintf(const emlrtStack *sp)
{
  int32_T i17;
  static const char_T cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv15[2] = { 1, 7 };

  const mxArray *m0;
  const mxArray *b_y;
  static const char_T formatSpec[33] = { 'A', ' ', 'n', 'o', 'n', ' ', 'r', 'o',
    't', 'a', 't', 'i', 'o', 'n', ' ', 'm', 'a', 't', 'r', 'i', 'x', ' ', 'i',
    's', ' ', 'r', 'e', 't', 'u', 'r', 'n', 'e', 'd' };

  char_T b_u[33];
  const mxArray *c_y;
  static const int32_T iv16[2] = { 1, 33 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i17 = 0; i17 < 7; i17++) {
    u[i17] = cv1[i17];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv15);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m0);
  for (i17 = 0; i17 < 33; i17++) {
    b_u[i17] = formatSpec[i17];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(sp, 33, m0, &b_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &md_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  int32_T i20;
  static const char_T cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv19[2] = { 1, 7 };

  const mxArray *m2;
  const mxArray *b_y;
  static const char_T formatSpec[26] = { 'N', 'u', 'm', 'b', 'e', 'r', ' ', 'o',
    'f', ' ', 'i', 't', 'e', 'r', 'a', 't', 'i', 'o', 'n', 's', ' ', 'i', 's',
    ' ', '%', 'f' };

  char_T b_u[26];
  const mxArray *c_y;
  static const int32_T iv20[2] = { 1, 26 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i20 = 0; i20 < 7; i20++) {
    u[i20] = cv2[i20];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv19);
  emlrtInitCharArrayR2013a(sp, 7, m2, &u[0]);
  emlrtAssign(&y, m2);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m2);
  for (i20 = 0; i20 < 26; i20++) {
    b_u[i20] = formatSpec[i20];
  }

  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv20);
  emlrtInitCharArrayR2013a(sp, 26, m2, &b_u[0]);
  emlrtAssign(&c_y, m2);
  d_y = NULL;
  m2 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m2);
  st.site = &md_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &emlrtMCI),
    "feval");
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m6, 3, pArrays, "feval", true, location);
}

static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1, real_T
  varargin_2, real_T varargin_3)
{
  int32_T i21;
  static const char_T cv3[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv21[2] = { 1, 7 };

  const mxArray *m3;
  const mxArray *b_y;
  static const char_T formatSpec[46] = { 'V', 'a', 'l', 'u', 'e', ' ', 'o', 'f',
    ' ', 't', 'h', 'e', ' ', 'c', 'o', 's', 't', ' ', 'f', 'u', 'n', 'c', 't',
    'i', 'o', 'n', ' ', 'i', 's', ' ', '%', 'f', ',', ' ', '%', 'f', ' ', 'a',
    'n', 'd', ' ', '%', 'f', ' ', '\\', 'n' };

  char_T b_u[46];
  const mxArray *c_y;
  static const int32_T iv22[2] = { 1, 46 };

  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i21 = 0; i21 < 7; i21++) {
    u[i21] = cv3[i21];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv21);
  emlrtInitCharArrayR2013a(sp, 7, m3, &u[0]);
  emlrtAssign(&y, m3);
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m3);
  for (i21 = 0; i21 < 46; i21++) {
    b_u[i21] = formatSpec[i21];
  }

  c_y = NULL;
  m3 = emlrtCreateCharArray(2, iv22);
  emlrtInitCharArrayR2013a(sp, 46, m3, &b_u[0]);
  emlrtAssign(&c_y, m3);
  d_y = NULL;
  m3 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m3);
  e_y = NULL;
  m3 = emlrtCreateDoubleScalar(varargin_2);
  emlrtAssign(&e_y, m3);
  f_y = NULL;
  m3 = emlrtCreateDoubleScalar(varargin_3);
  emlrtAssign(&f_y, m3);
  st.site = &md_emlrtRSI;
  return emlrt_marshallIn(&st, c_feval(&st, y, b_y, c_y, d_y, e_y, f_y,
    &emlrtMCI), "feval");
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tc_emlrtRSI;
  c_fprintf(&st);
}

real_T d_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kd_emlrtRSI;
  return e_fprintf(&st, formatSpec);
}

void f_fprintf(const emlrtStack *sp, real_T formatSpec, real_T varargin_1,
               real_T varargin_2)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kd_emlrtRSI;
  g_fprintf(&st, formatSpec, varargin_1, varargin_2);
}

/* End of code generation (fprintf.c) */
