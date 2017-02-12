/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_mean_double_convl_2nd_mex.c
 *
 * Code generation for function '_coder_mean_double_convl_2nd_mex'
 *
 */

/* Include files */
#include "mean_double_convl_2nd.h"
#include "_coder_mean_double_convl_2nd_mex.h"
#include "mean_double_convl_2nd_terminate.h"
#include "_coder_mean_double_convl_2nd_api.h"
#include "mean_double_convl_2nd_initialize.h"
#include "mean_double_convl_2nd_data.h"
#include <stdio.h>

/* Function Declarations */
static void c_mean_double_convl_2nd_mexFunc(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[8]);

/* Function Definitions */
static void c_mean_double_convl_2nd_mexFunc(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[8])
{
  int32_T n;
  const mxArray *inputs[8];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        21, "mean_double_convl_2nd");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "mean_double_convl_2nd");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  mean_double_convl_2nd_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  mean_double_convl_2nd_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(mean_double_convl_2nd_atexit);

  /* Module initialization. */
  mean_double_convl_2nd_initialize();

  /* Dispatch the entry-point. */
  c_mean_double_convl_2nd_mexFunc(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_mean_double_convl_2nd_mex.c) */
