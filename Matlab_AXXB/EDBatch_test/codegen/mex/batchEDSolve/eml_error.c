/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_error.c
 *
 * Code generation for function 'eml_error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "eml_error.h"

/* Variable Definitions */
static emlrtRTEInfo i_emlrtRTEI = { 20, 5, "eml_error",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_error.m" };

/* Function Definitions */
void b_eml_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &i_emlrtRTEI,
    "Coder:MATLAB:svd_matrixWithNaNInf", 0);
}

void c_eml_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &i_emlrtRTEI,
    "Coder:MATLAB:svd_NoConvergence", 0);
}

void d_eml_error(const emlrtStack *sp)
{
  static const char_T varargin_1[4] = { 's', 'q', 'r', 't' };

  emlrtErrorWithMessageIdR2012b(sp, &i_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, varargin_1);
}

void eml_error(const emlrtStack *sp)
{
  static const char_T varargin_1[4] = { 'a', 'c', 'o', 's' };

  emlrtErrorWithMessageIdR2012b(sp, &i_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, varargin_1);
}

/* End of code generation (eml_error.c) */
