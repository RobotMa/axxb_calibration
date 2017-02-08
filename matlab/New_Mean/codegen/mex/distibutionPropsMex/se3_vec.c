/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * se3_vec.c
 *
 * Code generation for function 'se3_vec'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "se3_vec.h"
#include "distibutionPropsMex_mexutil.h"

/* Variable Definitions */
static emlrtMCInfo j_emlrtMCI = { 9, 5, "se3_vec",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Review_AXXB/Matlab_AXXB/Batch Method (ED - GSI)/se3_vec.m"
};

static emlrtRSInfo wc_emlrtRSI = { 15, "se3_vec",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Review_AXXB/Matlab_AXXB/Batch Method (ED - GSI)/se3_vec.m"
};

static emlrtRSInfo bd_emlrtRSI = { 23, "se3_vec",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Review_AXXB/Matlab_AXXB/Batch Method (ED - GSI)/se3_vec.m"
};

static emlrtRSInfo cd_emlrtRSI = { 9, "se3_vec",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Review_AXXB/Matlab_AXXB/Batch Method (ED - GSI)/se3_vec.m"
};

/* Function Declarations */
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_size,
  const char_T *identifier);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, real_T y[6]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6]);
static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6]);
static const mxArray *size(const emlrtStack *sp, const mxArray *b, const mxArray
  *c, emlrtMCInfo *location);

/* Function Definitions */
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_size,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(b_size), &thisId);
  emlrtDestroyArray(&b_size);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X, const
  char_T *identifier, real_T y[6])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  h_emlrt_marshallIn(sp, emlrtAlias(X), &thisId, y);
  emlrtDestroyArray(&X);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[6])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[6])
{
  int32_T iv17[1];
  int32_T i14;
  iv17[0] = 6;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv17);
  for (i14 = 0; i14 < 6; i14++) {
    ret[i14] = (*(real_T (*)[6])mxGetData(src))[i14];
  }

  emlrtDestroyArray(&src);
}

static const mxArray *size(const emlrtStack *sp, const mxArray *b, const mxArray
  *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m14;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m14, 2, pArrays, "size", true, location);
}

void se3_vec(const emlrtStack *sp, const mxArray *X, real_T g_data[], int32_T
             g_size[2])
{
  const mxArray *y;
  const mxArray *m5;
  real_T n;
  real_T X_init[16];
  real_T b_X_init[6];
  int32_T i9;
  real_T dv0[16];
  int32_T i10;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* Function to vectorize or hat an element of se(3) */
  /* files needed: */
  /* none */
  y = NULL;
  m5 = emlrtCreateDoubleScalar(2.0);
  emlrtAssign(&y, m5);
  st.site = &cd_emlrtRSI;
  n = e_emlrt_marshallIn(&st, size(&st, emlrtAlias(X), y, &j_emlrtMCI), "size");
  if (n == 4.0) {
    /* If input is skew-sym change to vector */
    st.site = &wc_emlrtRSI;
    emlrt_marshallIn(&st, emlrtAlias(X), "X", X_init);
    b_X_init[0] = -X_init[9];
    b_X_init[1] = X_init[8];
    b_X_init[2] = -X_init[4];
    b_X_init[3] = X_init[12];
    b_X_init[4] = X_init[13];
    b_X_init[5] = X_init[14];
    g_size[0] = 6;
    g_size[1] = 1;
    for (i9 = 0; i9 < 6; i9++) {
      g_data[i9] = b_X_init[i9];
    }
  } else {
    /* If input is vector change to skew-sym  */
    st.site = &bd_emlrtRSI;
    g_emlrt_marshallIn(&st, emlrtAlias(X), "X", b_X_init);
    dv0[0] = 0.0;
    dv0[4] = -b_X_init[2];
    dv0[8] = b_X_init[1];
    dv0[12] = b_X_init[3];
    dv0[1] = b_X_init[2];
    dv0[5] = 0.0;
    dv0[9] = -b_X_init[0];
    dv0[13] = b_X_init[4];
    dv0[2] = -b_X_init[1];
    dv0[6] = b_X_init[0];
    dv0[10] = 0.0;
    dv0[14] = b_X_init[5];
    for (i9 = 0; i9 < 4; i9++) {
      dv0[3 + (i9 << 2)] = 0.0;
    }

    g_size[0] = 4;
    g_size[1] = 4;
    for (i9 = 0; i9 < 4; i9++) {
      for (i10 = 0; i10 < 4; i10++) {
        g_data[i10 + (i9 << 2)] = dv0[i10 + (i9 << 2)];
      }
    }
  }

  emlrtDestroyArray(&X);
}

/* End of code generation (se3_vec.c) */
