/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * distibutionPropsMex_terminate.c
 *
 * Code generation for function 'distibutionPropsMex_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "distibutionPropsMex_terminate.h"
#include "distibutionPropsMex_data.h"

/* Function Definitions */
void distibutionPropsMex_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void distibutionPropsMex_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (distibutionPropsMex_terminate.c) */
