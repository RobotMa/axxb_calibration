/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mean_Taylor_2nd_adv_mex.c
 *
 * Code generation for function '_coder_mean_Taylor_2nd_adv_mex'
 *
 */

/* Include files */
#include "mean_Taylor_2nd_adv.h"
#include "_coder_mean_Taylor_2nd_adv_mex.h"
#include "mean_Taylor_2nd_adv_terminate.h"
#include "_coder_mean_Taylor_2nd_adv_api.h"
#include "mean_Taylor_2nd_adv_initialize.h"
#include "mean_Taylor_2nd_adv_data.h"
#include <stdio.h>

/* Function Declarations */
static void mean_Taylor_2nd_adv_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */
static void mean_Taylor_2nd_adv_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        19, "mean_Taylor_2nd_adv");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "mean_Taylor_2nd_adv");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  mean_Taylor_2nd_adv_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  mean_Taylor_2nd_adv_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(mean_Taylor_2nd_adv_atexit);

  /* Module initialization. */
  mean_Taylor_2nd_adv_initialize();

  /* Dispatch the entry-point. */
  mean_Taylor_2nd_adv_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_mean_Taylor_2nd_adv_mex.c) */
