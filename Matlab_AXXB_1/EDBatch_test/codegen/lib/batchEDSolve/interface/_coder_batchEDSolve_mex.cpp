/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_batchEDSolve_mex.cpp
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 24-Jul-2015 17:07:45
 */

/* Include Files */
#include "_coder_batchEDSolve_api.h"
#include "_coder_batchEDSolve_mex.h"

/* Function Declarations */
static void batchEDSolve_mexFunction(int32_T nlhs, mxArray *plhs[5], int32_T
  nrhs, const mxArray *prhs[2]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[5]
 *                int32_T nrhs
 *                const mxArray *prhs[2]
 * Return Type  : void
 */
static void batchEDSolve_mexFunction(int32_T nlhs, mxArray *plhs[5], int32_T
  nrhs, const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[5];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        12, "batchEDSolve");
  }

  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "batchEDSolve");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
  }

  /* Call the function. */
  batchEDSolve_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  batchEDSolve_terminate();
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
  mexAtExit(batchEDSolve_atexit);

  /* Module initialization. */
  batchEDSolve_initialize();

  /* Dispatch the entry-point. */
  batchEDSolve_mexFunction(nlhs, plhs, nrhs, prhs);
}

/*
 * File trailer for _coder_batchEDSolve_mex.cpp
 *
 * [EOF]
 */
