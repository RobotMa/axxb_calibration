/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_mean_convl_2nd_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 15-Jul-2015 12:00:44
 */

#ifndef ___CODER_MEAN_CONVL_2ND_API_H__
#define ___CODER_MEAN_CONVL_2ND_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_mean_convl_2nd_api.h"

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
extern void mean_convl_2nd(emxArray_real_T *X1, emxArray_real_T *X2, int8_T s1,
  int8_T s2, int16_T n_search, real_T M12_f[16]);
extern void mean_convl_2nd_api(const mxArray *prhs[5], const mxArray *plhs[1]);
extern void mean_convl_2nd_atexit(void);
extern void mean_convl_2nd_initialize(void);
extern void mean_convl_2nd_terminate(void);
extern void mean_convl_2nd_xil_terminate(void);

#endif

/*
 * File trailer for _coder_mean_convl_2nd_api.h
 *
 * [EOF]
 */
