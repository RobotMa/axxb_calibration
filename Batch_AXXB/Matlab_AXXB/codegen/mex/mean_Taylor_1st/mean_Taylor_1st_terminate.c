/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_Taylor_1st_terminate.c
 *
 * Code generation for function 'mean_Taylor_1st_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_1st.h"
#include "mean_Taylor_1st_terminate.h"
#include "mean_Taylor_1st_data.h"
#include <stdio.h>

/* Function Definitions */
void mean_Taylor_1st_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void mean_Taylor_1st_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (mean_Taylor_1st_terminate.c) */
