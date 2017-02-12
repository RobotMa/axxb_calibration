/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_distibutionPropsMex_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Jul-2015 23:05:44
 */

#ifndef ___CODER_DISTIBUTIONPROPSMEX_API_H__
#define ___CODER_DISTIBUTIONPROPSMEX_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_distibutionPropsMex_api.h"

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
extern void distibutionPropsMex(emxArray_real_T *X, real_T M[16], real_T Sig[36]);
extern void distibutionPropsMex_api(const mxArray *prhs[1], const mxArray *plhs
  [2]);
extern void distibutionPropsMex_atexit(void);
extern void distibutionPropsMex_initialize(void);
extern void distibutionPropsMex_terminate(void);
extern void distibutionPropsMex_xil_terminate(void);

#endif

/*
 * File trailer for _coder_distibutionPropsMex_api.h
 *
 * [EOF]
 */
