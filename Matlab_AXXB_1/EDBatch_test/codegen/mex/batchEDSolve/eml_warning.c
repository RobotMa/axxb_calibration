/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_warning.c
 *
 * Code generation for function 'eml_warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "eml_warning.h"

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 16, 13, "eml_warning",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtMCInfo c_emlrtMCI = { 16, 5, "eml_warning",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtRSInfo jg_emlrtRSI = { 16, "eml_warning",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_warning.m" };

/* Function Declarations */
static const mxArray *b_message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);
static void warning(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

/* Function Definitions */
static const mxArray *b_message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m12;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m12, 2, pArrays, "message", true,
    location);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m9;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m9, 1, &pArray, "message", true, location);
}

static void warning(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "warning", true, location);
}

void b_eml_warning(const emlrtStack *sp, const char_T varargin_2[14])
{
  int32_T i22;
  static const char_T varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T u[33];
  const mxArray *y;
  static const int32_T iv21[2] = { 1, 33 };

  const mxArray *m3;
  char_T b_u[14];
  const mxArray *b_y;
  static const int32_T iv22[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i22 = 0; i22 < 33; i22++) {
    u[i22] = varargin_1[i22];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv21);
  emlrtInitCharArrayR2013a(sp, 33, m3, &u[0]);
  emlrtAssign(&y, m3);
  for (i22 = 0; i22 < 14; i22++) {
    b_u[i22] = varargin_2[i22];
  }

  b_y = NULL;
  m3 = emlrtCreateCharArray(2, iv22);
  emlrtInitCharArrayR2013a(sp, 14, m3, &b_u[0]);
  emlrtAssign(&b_y, m3);
  st.site = &jg_emlrtRSI;
  warning(&st, b_message(&st, y, b_y, &b_emlrtMCI), &c_emlrtMCI);
}

void c_eml_warning(const emlrtStack *sp)
{
  int32_T i23;
  static const char_T varargin_1[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e',
    'i', 'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c',
    'e' };

  char_T u[24];
  const mxArray *y;
  static const int32_T iv24[2] = { 1, 24 };

  const mxArray *m4;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i23 = 0; i23 < 24; i23++) {
    u[i23] = varargin_1[i23];
  }

  y = NULL;
  m4 = emlrtCreateCharArray(2, iv24);
  emlrtInitCharArrayR2013a(sp, 24, m4, &u[0]);
  emlrtAssign(&y, m4);
  st.site = &jg_emlrtRSI;
  warning(&st, message(&st, y, &b_emlrtMCI), &c_emlrtMCI);
}

void eml_warning(const emlrtStack *sp)
{
  int32_T i21;
  static const char_T varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T u[27];
  const mxArray *y;
  static const int32_T iv19[2] = { 1, 27 };

  const mxArray *m1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i21 = 0; i21 < 27; i21++) {
    u[i21] = varargin_1[i21];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv19);
  emlrtInitCharArrayR2013a(sp, 27, m1, &u[0]);
  emlrtAssign(&y, m1);
  st.site = &jg_emlrtRSI;
  warning(&st, message(&st, y, &b_emlrtMCI), &c_emlrtMCI);
}

/* End of code generation (eml_warning.c) */
