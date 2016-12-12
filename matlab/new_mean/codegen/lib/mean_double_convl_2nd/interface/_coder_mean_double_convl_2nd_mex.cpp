/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mean_double_convl_2nd_mex.cpp
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 11-Jun-2015 01:46:04
 */

/* Include Files */
#include "_coder_mean_double_convl_2nd_api.h"
#include "_coder_mean_double_convl_2nd_mex.h"
#include <stdio.h>

/* Function Declarations */
static void c_mean_double_convl_2nd_mexFunc(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[8]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[8]
 * Return Type  : void
 */
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

/*
 * Arguments    : int32_T nlhs
 *                const mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
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

/*
 * File trailer for _coder_mean_double_convl_2nd_mex.cpp
 *
 * [EOF]
 */
