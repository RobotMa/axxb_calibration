/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * distibutionPropsMex_mexutil.c
 *
 * Code generation for function 'distibutionPropsMex_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "distibutionPropsMex_mexutil.h"

/* Function Definitions */
void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[16])
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_logm, const char_T *
                      identifier, real_T y[16])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(b_logm), &thisId, y);
  emlrtDestroyArray(&b_logm);
}

void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[16])
{
  int32_T iv15[2];
  int32_T i;
  int32_T i12;
  for (i = 0; i < 2; i++) {
    iv15[i] = 4;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv15);
  for (i = 0; i < 4; i++) {
    for (i12 = 0; i12 < 4; i12++) {
      ret[i12 + (i << 2)] = (*(real_T (*)[16])mxGetData(src))[i12 + (i << 2)];
    }
  }

  emlrtDestroyArray(&src);
}

/* End of code generation (distibutionPropsMex_mexutil.c) */
