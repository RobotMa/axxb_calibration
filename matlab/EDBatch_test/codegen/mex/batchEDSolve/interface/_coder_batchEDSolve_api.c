/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_batchEDSolve_api.c
 *
 * Code generation for function '_coder_batchEDSolve_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "_coder_batchEDSolve_api.h"
#include "batchEDSolve_emxutil.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, 1, "_coder_batchEDSolve_api", "" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u[16]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *A, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *c_emlrt_marshallOut(const real_T u[36]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u[16]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u[16])
{
  const mxArray *y;
  static const int32_T iv27[2] = { 0, 0 };

  const mxArray *m7;
  static const int32_T iv28[2] = { 4, 4 };

  y = NULL;
  m7 = emlrtCreateNumericArray(2, iv27, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m7, (void *)u);
  emlrtSetDimensions((mxArray *)m7, iv28, 2);
  emlrtAssign(&y, m7);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *A, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(A), &thisId, y);
  emlrtDestroyArray(&A);
}

static const mxArray *c_emlrt_marshallOut(const real_T u[36])
{
  const mxArray *y;
  static const int32_T iv29[2] = { 0, 0 };

  const mxArray *m8;
  static const int32_T iv30[2] = { 6, 6 };

  y = NULL;
  m8 = emlrtCreateNumericArray(2, iv29, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m8, (void *)u);
  emlrtSetDimensions((mxArray *)m8, iv30, 2);
  emlrtAssign(&y, m8);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u[16])
{
  const mxArray *y;
  static const int32_T iv26[2] = { 4, 4 };

  const mxArray *m6;
  creal_T b_u[16];
  y = NULL;
  m6 = emlrtCreateNumericArray(2, iv26, mxDOUBLE_CLASS, mxCOMPLEX);
  memcpy(&b_u[0], &u[0], sizeof(creal_T) << 4);
  emlrtExportNumericArrayR2013b(sp, m6, b_u, 8);
  emlrtAssign(&y, m6);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv32[2];
  int32_T i29;
  int32_T iv33[2];
  boolean_T bv0[2] = { false, true };

  for (i29 = 0; i29 < 2; i29++) {
    iv32[i29] = 4 + -5 * i29;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv32, &bv0[0],
    iv33);
  ret->size[0] = iv33[0];
  ret->size[1] = iv33[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void batchEDSolve_api(const mxArray * const prhs[2], const mxArray *plhs[5])
{
  real_T (*MeanA)[16];
  real_T (*MeanB)[16];
  real_T (*SigA)[36];
  real_T (*SigB)[36];
  emxArray_real_T *A;
  emxArray_real_T *B;
  creal_T X[16];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  MeanA = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));
  MeanB = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));
  SigA = (real_T (*)[36])mxMalloc(sizeof(real_T [36]));
  SigB = (real_T (*)[36])mxMalloc(sizeof(real_T [36]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &A, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &B, 2, &b_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "A", A);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "B", B);

  /* Invoke the target function */
  batchEDSolve(&st, A, B, X, *MeanA, *MeanB, *SigA, *SigB);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, X);
  plhs[1] = b_emlrt_marshallOut(*MeanA);
  plhs[2] = b_emlrt_marshallOut(*MeanB);
  plhs[3] = c_emlrt_marshallOut(*SigA);
  plhs[4] = c_emlrt_marshallOut(*SigB);
  B->canFreeData = false;
  emxFree_real_T(&B);
  A->canFreeData = false;
  emxFree_real_T(&A);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_batchEDSolve_api.c) */
