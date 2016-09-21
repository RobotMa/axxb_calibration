/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mean_Taylor_1st_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 30-Aug-2015 22:36:03
 */

#ifndef ___CODER_MEAN_TAYLOR_1ST_API_H__
#define ___CODER_MEAN_TAYLOR_1ST_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_mean_Taylor_1st_api.h"

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
extern void mean_Taylor_1st(emxArray_real_T *X, real_T M_1[16], real_T M_hat[16]);
extern void mean_Taylor_1st_api(const mxArray *prhs[1], const mxArray *plhs[2]);
extern void mean_Taylor_1st_atexit(void);
extern void mean_Taylor_1st_initialize(void);
extern void mean_Taylor_1st_terminate(void);
extern void mean_Taylor_1st_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mean_Taylor_1st_api.h
 *
 * [EOF]
 */
