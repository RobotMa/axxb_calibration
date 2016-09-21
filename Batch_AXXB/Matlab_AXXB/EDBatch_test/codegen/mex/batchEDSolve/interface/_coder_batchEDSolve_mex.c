/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_batchEDSolve_mex.c
 *
 * Code generation for function '_coder_batchEDSolve_mex'
 *
 */

/* Include files */
#include "batchEDSolve.h"
#include "_coder_batchEDSolve_mex.h"
#include "batchEDSolve_terminate.h"
#include "_coder_batchEDSolve_api.h"
#include "batchEDSolve_initialize.h"
#include "batchEDSolve_data.h"

/* Function Declarations */
static void batchEDSolve_mexFunction(int32_T nlhs, mxArray *plhs[5], int32_T
  nrhs, const mxArray *prhs[2]);

/* Function Definitions */
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
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
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

/* End of code generation (_coder_batchEDSolve_mex.c) */
