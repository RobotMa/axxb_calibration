/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_2nd_adv.h"
#include "sqrt.h"
#include "eml_error.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = { 14, "sqrt",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/elfun/sqrt.m" };

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, real_T *x)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (*x < 0.0) {
    st.site = &rb_emlrtRSI;
    c_eml_error(&st);
  }

  *x = muDoubleScalarSqrt(*x);
}

/* End of code generation (sqrt.c) */
