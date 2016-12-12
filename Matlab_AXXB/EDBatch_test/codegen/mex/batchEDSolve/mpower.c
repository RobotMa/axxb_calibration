/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mpower.c
 *
 * Code generation for function 'mpower'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "mpower.h"
#include "eml_warning.h"
#include "norm.h"
#include "inv.h"
#include "eml_int_forloop_overflow_check.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRSInfo bc_emlrtRSI = { 1, "xger",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xger.p" };

static emlrtRSInfo cc_emlrtRSI = { 1, "xger",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"
};

static emlrtRSInfo dc_emlrtRSI = { 1, "xgerx",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"
};

static emlrtRSInfo ic_emlrtRSI = { 41, "mpower",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/mpower.m" };

static emlrtRSInfo jc_emlrtRSI = { 13, "matrix_to_integer_power",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/private/matrix_to_integer_power.m"
};

static emlrtRSInfo kc_emlrtRSI = { 75, "matrix_to_integer_power",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/private/matrix_to_integer_power.m"
};

static emlrtRSInfo lc_emlrtRSI = { 17, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo mc_emlrtRSI = { 18, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo pc_emlrtRSI = { 40, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo qc_emlrtRSI = { 44, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtMCInfo d_emlrtMCI = { 29, 23, "eml_flt2str",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

static emlrtMCInfo e_emlrtMCI = { 29, 15, "eml_flt2str",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

static emlrtRTEInfo k_emlrtRTEI = { 33, 15, "mpower",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/mpower.m" };

static emlrtRTEInfo l_emlrtRTEI = { 14, 15, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo kg_emlrtRSI = { 29, "eml_flt2str",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static const mxArray *c_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_sprintf,
  const char_T *identifier, char_T y[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m10;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m10, 3, pArrays, "sprintf", true,
    location);
}

static const mxArray *c_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m11;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m11, 2, pArrays, "sprintf", true,
    location);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  int32_T iv31[2];
  int32_T i28;
  for (i28 = 0; i28 < 2; i28++) {
    iv31[i28] = 1 + 13 * i28;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, iv31);
  emlrtImportCharArrayR2014b(sp, src, ret, 14);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(d_sprintf), &thisId, y);
  emlrtDestroyArray(&d_sprintf);
}

void b_mpower(const emlrtStack *sp, const creal_T a_data[], const int32_T
              a_size[2], creal_T c_data[], int32_T c_size[2])
{
  real_T n1x;
  real_T n1xinv;
  real_T rc;
  int32_T i24;
  static const char_T cv3[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T u[8];
  const mxArray *y;
  static const int32_T iv25[2] = { 1, 8 };

  const mxArray *m5;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  char_T cv4[14];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  if (a_size[0] == a_size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &k_emlrtRTEI, "Coder:MATLAB:square", 0);
  }

  st.site = &ic_emlrtRSI;
  b_st.site = &jc_emlrtRSI;
  c_st.site = &kc_emlrtRSI;
  if (a_size[0] == a_size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &l_emlrtRTEI, "Coder:MATLAB:square", 0);
  }

  d_st.site = &lc_emlrtRSI;
  invNxN(&d_st, a_data, a_size, c_data, c_size);
  d_st.site = &mc_emlrtRSI;
  n1x = c_norm(a_data, a_size);
  n1xinv = c_norm(c_data, c_size);
  rc = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (rc == 0.0)) {
    e_st.site = &pc_emlrtRSI;
    eml_warning(&e_st);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      e_st.site = &qc_emlrtRSI;
      for (i24 = 0; i24 < 8; i24++) {
        u[i24] = cv3[i24];
      }

      y = NULL;
      m5 = emlrtCreateCharArray(2, iv25);
      emlrtInitCharArrayR2013a(&e_st, 8, m5, &u[0]);
      emlrtAssign(&y, m5);
      b_y = NULL;
      m5 = emlrtCreateDoubleScalar(14.0);
      emlrtAssign(&b_y, m5);
      c_y = NULL;
      m5 = emlrtCreateDoubleScalar(6.0);
      emlrtAssign(&c_y, m5);
      d_y = NULL;
      m5 = emlrtCreateDoubleScalar(rc);
      emlrtAssign(&d_y, m5);
      f_st.site = &kg_emlrtRSI;
      emlrt_marshallIn(&f_st, c_sprintf(&f_st, b_sprintf(&f_st, y, b_y, c_y,
        &d_emlrtMCI), d_y, &e_emlrtMCI), "sprintf", cv4);
      e_st.site = &qc_emlrtRSI;
      b_eml_warning(&e_st, cv4);
    }
  }
}

void eml_lapack_xgetrf(const emlrtStack *sp, real_T A[16], int32_T ipiv[4],
  int32_T *info)
{
  int32_T iy;
  int32_T j;
  int32_T c;
  int32_T ix;
  real_T smax;
  int32_T jy;
  real_T s;
  int32_T b;
  int32_T b_j;
  boolean_T b_iy;
  int32_T ijA;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  for (iy = 0; iy < 4; iy++) {
    ipiv[iy] = 1 + iy;
  }

  *info = 0;
  for (j = 0; j < 3; j++) {
    c = j * 5;
    iy = 0;
    ix = c;
    smax = muDoubleScalarAbs(A[c]);
    for (jy = 2; jy <= 4 - j; jy++) {
      ix++;
      s = muDoubleScalarAbs(A[ix]);
      if (s > smax) {
        iy = jy - 1;
        smax = s;
      }
    }

    if (A[c + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (j + iy) + 1;
        ix = j;
        iy += j;
        for (jy = 0; jy < 4; jy++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 4;
          iy += 4;
        }
      }

      b = (c - j) + 4;
      b_st.site = &wb_emlrtRSI;
      for (iy = c + 1; iy + 1 <= b; iy++) {
        A[iy] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    b_st.site = &xb_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    d_st.site = &ac_emlrtRSI;
    e_st.site = &bc_emlrtRSI;
    f_st.site = &cc_emlrtRSI;
    iy = c;
    jy = c + 4;
    g_st.site = &dc_emlrtRSI;
    for (b_j = 1; b_j <= 3 - j; b_j++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = c + 1;
        b = (iy - j) + 8;
        g_st.site = &dc_emlrtRSI;
        if (iy + 6 > b) {
          b_iy = false;
        } else {
          b_iy = (b > 2147483646);
        }

        if (b_iy) {
          h_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }

        for (ijA = iy + 5; ijA + 1 <= b; ijA++) {
          A[ijA] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 4;
      iy += 4;
    }
  }

  if ((*info == 0) && (!(A[15] != 0.0))) {
    *info = 4;
  }
}

void eml_xtrsm(const real_T A[16], real_T B[16])
{
  int32_T j;
  int32_T jBcol;
  int32_T k;
  int32_T kAcol;
  int32_T i;
  for (j = 0; j < 4; j++) {
    jBcol = j << 2;
    for (k = 3; k > -1; k += -1) {
      kAcol = k << 2;
      if (B[k + jBcol] != 0.0) {
        B[k + jBcol] /= A[k + kAcol];
        for (i = 0; i + 1 <= k; i++) {
          B[i + jBcol] -= B[k + jBcol] * A[i + kAcol];
        }
      }
    }
  }
}

void mpower(const emlrtStack *sp, const real_T a[16], real_T c[16])
{
  real_T x[16];
  int32_T b_c;
  int32_T ipiv[4];
  int8_T p[4];
  int32_T k;
  int32_T j;
  int32_T i;
  real_T n1x;
  real_T n1xinv;
  real_T rc;
  static const char_T cv1[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T u[8];
  const mxArray *y;
  static const int32_T iv20[2] = { 1, 8 };

  const mxArray *m2;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  char_T cv2[14];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ic_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &jc_emlrtRSI;
  c_st.site = &kc_emlrtRSI;
  d_st.site = &lc_emlrtRSI;
  memset(&c[0], 0, sizeof(real_T) << 4);
  e_st.site = &nc_emlrtRSI;
  memcpy(&x[0], &a[0], sizeof(real_T) << 4);
  f_st.site = &ub_emlrtRSI;
  eml_lapack_xgetrf(&f_st, x, ipiv, &b_c);
  for (b_c = 0; b_c < 4; b_c++) {
    p[b_c] = (int8_T)(1 + b_c);
  }

  for (k = 0; k < 3; k++) {
    if (ipiv[k] > 1 + k) {
      b_c = p[ipiv[k] - 1];
      p[ipiv[k] - 1] = p[k];
      p[k] = (int8_T)b_c;
    }
  }

  for (k = 0; k < 4; k++) {
    b_c = p[k] - 1;
    c[k + ((p[k] - 1) << 2)] = 1.0;
    for (j = k; j + 1 < 5; j++) {
      if (c[j + (b_c << 2)] != 0.0) {
        for (i = j + 1; i + 1 < 5; i++) {
          c[i + (b_c << 2)] -= c[j + (b_c << 2)] * x[i + (j << 2)];
        }
      }
    }
  }

  e_st.site = &oc_emlrtRSI;
  eml_xtrsm(x, c);
  d_st.site = &mc_emlrtRSI;
  n1x = norm(a);
  n1xinv = norm(c);
  rc = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (rc == 0.0)) {
    e_st.site = &pc_emlrtRSI;
    eml_warning(&e_st);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      e_st.site = &qc_emlrtRSI;
      for (b_c = 0; b_c < 8; b_c++) {
        u[b_c] = cv1[b_c];
      }

      y = NULL;
      m2 = emlrtCreateCharArray(2, iv20);
      emlrtInitCharArrayR2013a(&e_st, 8, m2, &u[0]);
      emlrtAssign(&y, m2);
      b_y = NULL;
      m2 = emlrtCreateDoubleScalar(14.0);
      emlrtAssign(&b_y, m2);
      c_y = NULL;
      m2 = emlrtCreateDoubleScalar(6.0);
      emlrtAssign(&c_y, m2);
      d_y = NULL;
      m2 = emlrtCreateDoubleScalar(rc);
      emlrtAssign(&d_y, m2);
      f_st.site = &kg_emlrtRSI;
      emlrt_marshallIn(&f_st, c_sprintf(&f_st, b_sprintf(&f_st, y, b_y, c_y,
        &d_emlrtMCI), d_y, &e_emlrtMCI), "sprintf", cv2);
      e_st.site = &qc_emlrtRSI;
      b_eml_warning(&e_st, cv2);
    }
  }
}

/* End of code generation (mpower.c) */
