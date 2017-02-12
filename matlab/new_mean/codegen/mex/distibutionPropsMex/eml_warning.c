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
#include "distibutionPropsMex.h"
#include "eml_warning.h"

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 16, 13, "eml_warning",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtMCInfo c_emlrtMCI = { 16, 5, "eml_warning",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtRSInfo id_emlrtRSI = { 16, "eml_warning",
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
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m9, 2, pArrays, "message", true, location);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m6;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m6, 1, &pArray, "message", true, location);
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
  int32_T i13;
  static const char_T varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T u[33];
  const mxArray *y;
  static const int32_T iv11[2] = { 1, 33 };

  const mxArray *m3;
  char_T b_u[14];
  const mxArray *b_y;
  static const int32_T iv12[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i13 = 0; i13 < 33; i13++) {
    u[i13] = varargin_1[i13];
  }

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 33, m3, &u[0]);
  emlrtAssign(&y, m3);
  for (i13 = 0; i13 < 14; i13++) {
    b_u[i13] = varargin_2[i13];
  }

  b_y = NULL;
  m3 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 14, m3, &b_u[0]);
  emlrtAssign(&b_y, m3);
  st.site = &id_emlrtRSI;
  warning(&st, b_message(&st, y, b_y, &b_emlrtMCI), &c_emlrtMCI);
}

void eml_warning(const emlrtStack *sp)
{
  int32_T i12;
  static const char_T varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T u[27];
  const mxArray *y;
  static const int32_T iv9[2] = { 1, 27 };

  const mxArray *m1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i12 = 0; i12 < 27; i12++) {
    u[i12] = varargin_1[i12];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 27, m1, &u[0]);
  emlrtAssign(&y, m1);
  st.site = &id_emlrtRSI;
  warning(&st, message(&st, y, &b_emlrtMCI), &c_emlrtMCI);
}

/* End of code generation (eml_warning.c) */
