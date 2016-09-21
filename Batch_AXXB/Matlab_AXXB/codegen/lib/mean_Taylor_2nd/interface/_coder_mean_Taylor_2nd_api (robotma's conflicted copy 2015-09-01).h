/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mean_Taylor_2nd_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Jul-2015 23:10:02
 */

#ifndef ___CODER_MEAN_TAYLOR_2ND_API_H__
#define ___CODER_MEAN_TAYLOR_2ND_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_mean_Taylor_2nd_api.h"

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
extern void mean_Taylor_2nd(emxArray_real_T *X, real_T noise, int16_T num,
  real_T MX[16]);
extern void mean_Taylor_2nd_api(const mxArray *prhs[3], const mxArray *plhs[1]);
extern void mean_Taylor_2nd_atexit(void);
extern void mean_Taylor_2nd_initialize(void);
extern void mean_Taylor_2nd_terminate(void);
extern void mean_Taylor_2nd_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mean_Taylor_2nd_api.h
 *
 * [EOF]
 */
