/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_batchEDSolve_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 24-Jul-2015 17:07:45
 */

#ifndef ___CODER_BATCHEDSOLVE_API_H__
#define ___CODER_BATCHEDSOLVE_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_batchEDSolve_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void batchEDSolve(emxArray_real_T *A, emxArray_real_T *B, creal_T X[16],
  real_T MeanA[16], real_T MeanB[16], real_T SigA[36], real_T SigB[36]);
extern void batchEDSolve_api(const mxArray *prhs[2], const mxArray *plhs[5]);
extern void batchEDSolve_atexit(void);
extern void batchEDSolve_initialize(void);
extern void batchEDSolve_terminate(void);
extern void batchEDSolve_xil_terminate(void);

#endif

/*
 * File trailer for _coder_batchEDSolve_api.h
 *
 * [EOF]
 */
