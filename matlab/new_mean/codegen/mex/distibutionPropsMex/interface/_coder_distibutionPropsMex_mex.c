/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_distibutionPropsMex_mex.c
 *
 * Code generation for function '_coder_distibutionPropsMex_mex'
 *
 */

/* Include files */
#include "distibutionPropsMex.h"
#include "_coder_distibutionPropsMex_mex.h"
#include "distibutionPropsMex_terminate.h"
#include "_coder_distibutionPropsMex_api.h"
#include "distibutionPropsMex_initialize.h"
#include "distibutionPropsMex_data.h"

/* Function Declarations */
static void distibutionPropsMex_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void distibutionPropsMex_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[1])
{
  int32_T n;
  const mxArray *inputs[1];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        19, "distibutionPropsMex");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "distibutionPropsMex");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  distibutionPropsMex_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  distibutionPropsMex_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(distibutionPropsMex_atexit);

  /* Module initialization. */
  distibutionPropsMex_initialize();

  /* Dispatch the entry-point. */
  distibutionPropsMex_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_distibutionPropsMex_mex.c) */
