/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * param_extract.c
 *
 * Code generation for function 'param_extract'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "param_extract.h"
#include "eml_error.h"
#include "eml_warning.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI = { 15, "acos",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/elfun/acos.m" };

static emlrtRSInfo sf_emlrtRSI = { 12, "param_extract",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/param_extract.m"
};

static emlrtRSInfo tf_emlrtRSI = { 25, "param_extract",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/param_extract.m"
};

static emlrtRSInfo uf_emlrtRSI = { 26, "param_extract",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/param_extract.m"
};

static emlrtRSInfo vf_emlrtRSI = { 231, "linsolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/linsolve.m" };

static emlrtRSInfo wf_emlrtRSI = { 54, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

static emlrtRSInfo xf_emlrtRSI = { 155, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

/* Function Definitions */
void param_extract(const emlrtStack *sp, const real_T X_in[16], real_T *theta,
                   real_T N[9], real_T *d, real_T p[3])
{
  real_T a21;
  int32_T r1;
  real_T x;
  int32_T r2;
  real_T g[3];
  real_T u[3];
  real_T A[4];
  real_T B[2];
  real_T a22;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;

  /* Function to extract Plucker parameters from a g \in SE(3) */
  /* files needed: */
  /* so3_vec().m */
  /* extract theta--------------------------------- */
  a21 = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    a21 += X_in[r1 + (r1 << 2)];
  }

  x = (a21 - 1.0) / 2.0;
  st.site = &sf_emlrtRSI;
  if ((x < -1.0) || (1.0 < x)) {
    b_st.site = &kb_emlrtRSI;
    eml_error(&b_st);
  }

  *theta = muDoubleScalarAcos(x);

  /* ---------------------------------------------- */
  /* extract N--------------------------------- */
  a21 = 2.0 * muDoubleScalarSin(*theta);
  for (r1 = 0; r1 < 3; r1++) {
    for (r2 = 0; r2 < 3; r2++) {
      N[r2 + 3 * r1] = (X_in[r2 + (r1 << 2)] - X_in[r1 + (r2 << 2)]) / a21;
    }
  }

  /* ---------------------------------------------- */
  /* extract d--------------------------------- */
  /* Function to vectorize or hat an element in so(3) */
  /* files needed: */
  /* none */
  /* If input is skew-sym change to vector */
  g[0] = -N[7];
  g[1] = N[6];
  g[2] = -N[3];
  *d = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    *d += X_in[12 + r1] * g[r1];
  }

  /* ---------------------------------------------- */
  /* extract p--------------------------------- */
  /* Function to vectorize or hat an element in so(3) */
  /* files needed: */
  /* none */
  /* If input is skew-sym change to vector */
  st.site = &tf_emlrtRSI;
  x = -N[7] * -N[7] + N[6] * N[6];
  if (x < 0.0) {
    b_st.site = &yd_emlrtRSI;
    d_eml_error(&b_st);
  }

  a21 = 1.0 / muDoubleScalarSqrt(x);
  u[0] = a21 * -N[6];
  u[1] = a21 * -N[7];
  u[2] = a21 * 0.0;
  a21 = 0.0;
  g[0] = N[6] * u[2] - -N[3] * u[1];
  g[1] = -N[3] * u[0] - -N[7] * u[2];
  g[2] = -N[7] * u[1] - N[6] * u[0];
  x = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    a21 += X_in[12 + r1] * u[r1];
    x += X_in[12 + r1] * g[r1];
  }

  st.site = &uf_emlrtRSI;
  A[0] = 1.0 - muDoubleScalarCos(*theta);
  A[2] = muDoubleScalarSin(*theta);
  A[1] = -muDoubleScalarSin(*theta);
  A[3] = 1.0 - muDoubleScalarCos(*theta);
  B[0] = a21;
  B[1] = x;
  b_st.site = &vf_emlrtRSI;
  c_st.site = &wf_emlrtRSI;
  if (muDoubleScalarAbs(A[1]) > muDoubleScalarAbs(A[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = A[r2] / A[r1];
  a22 = A[2 + r2] - a21 * A[2 + r1];
  if ((a22 == 0.0) || (A[r1] == 0.0)) {
    d_st.site = &xf_emlrtRSI;
    e_st.site = &ec_emlrtRSI;
    eml_warning(&e_st);
  }

  x = B[r2] - B[r1] * a21;
  a21 = x / a22;
  x = (B[r1] - x / a22 * A[2 + r1]) / A[r1];
  p[0] = x * u[0] + a21 * (N[6] * u[2] - -N[3] * u[1]);
  p[1] = x * u[1] + a21 * (-N[3] * u[0] - -N[7] * u[2]);
  p[2] = x * u[2] + a21 * (-N[7] * u[1] - N[6] * u[0]);

  /* ---------------------------------------------- */
}

/* End of code generation (param_extract.c) */
