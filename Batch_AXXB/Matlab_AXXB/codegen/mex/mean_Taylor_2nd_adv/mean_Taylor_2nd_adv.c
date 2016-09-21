/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_Taylor_2nd_adv.c
 *
 * Code generation for function 'mean_Taylor_2nd_adv'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_2nd_adv.h"
#include "mean_Taylor_2nd_adv_emxutil.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "mean_Taylor_1st.h"
#include "mean_Taylor_2nd_adv_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 129, 9, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 130, 9, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 135, 1, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo emlrtRSI = { 24, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo b_emlrtRSI = { 75, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo c_emlrtRSI = { 76, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo d_emlrtRSI = { 83, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo e_emlrtRSI = { 84, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo f_emlrtRSI = { 94, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo g_emlrtRSI = { 95, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo h_emlrtRSI = { 129, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo i_emlrtRSI = { 130, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo j_emlrtRSI = { 135, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRSInfo tc_emlrtRSI = { 68, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

static emlrtRSInfo uc_emlrtRSI = { 54, "eml_xgemm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };

static emlrtRTEInfo d_emlrtRTEI = { 11, 15, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 82, 13, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 20, 1, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 21, 25, "X", "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m",
  0 };

static emlrtECInfo emlrtECI = { 2, 21, 13, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtBCInfo b_emlrtBCI = { 1, 6, 75, 39, "E", "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m",
  0 };

static emlrtRTEInfo i_emlrtRTEI = { 81, 9, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtBCInfo c_emlrtBCI = { -1, -1, 82, 23, "X", "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m",
  0 };

static emlrtECInfo b_emlrtECI = { 2, 83, 22, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

static emlrtECInfo c_emlrtECI = { 2, 84, 22, "mean_Taylor_2nd_adv",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd_adv.m"
};

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m5);
  return y;
}

void mean_Taylor_2nd_adv(const emlrtStack *sp, const emxArray_real_T *X, real_T
  noise, int16_T num, real_T MX[16])
{
  real_T M_hat[16];
  real_T n;
  int32_T i;
  emxArray_real_T *b_X;
  emxArray_real_T *c_X;
  int32_T i0;
  uint32_T unnamed_idx_1;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T iv0[2];
  int32_T b_i;
  int32_T loop_ub;
  int32_T a_size[2];
  real_T CA;
  real_T CA1;
  real_T CA2;
  int8_T E[96];
  static const int8_T iv1[16] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv2[16] = { 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv3[16] = { 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv4[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0
  };

  static const int8_T iv5[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0
  };

  static const int8_T iv6[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0
  };

  real_T count;
  int32_T m;
  real_T step;
  emxArray_real_T *X_k;
  emxArray_real_T *C;
  emxArray_real_T *r0;
  boolean_T exitg1;
  real_T n_step;
  int32_T j;
  int32_T b_j;
  real_T a;
  real_T b_a[16];
  real_T MX1sum[16];
  real_T MX1[16];
  real_T MX2[16];
  real_T MX2sum[16];
  int32_T k;
  int32_T i4;
  real_T alpha1;
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  real_T b_MX1sum;
  real_T b_MX2sum;
  real_T y;
  real_T b_y;
  real_T c_y;
  real_T d_y;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  This function calculates the 2nd order approximation of the mean of a */
  /*  bunch of matrices based on the Taylor expansion of the matrix logarithm */
  /*  and the definition of mean of a probability density function. */
  /*  Input: X is a cell of 4 by 4*n rigid transformation matrices */
  /*  Output: M_T1 is the mean of the 1st order approximation of Taylor */
  /*  expansion */
  /*  Output: MX is the 2nd order approximation of the Taylor expansion */
  /*  coder.extrinsic('mean_Taylor_1st_mex'); */
  memset(&M_hat[0], 0, sizeof(real_T) << 4);
  n = (real_T)X->size[1] / 4.0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
    &h_emlrtRTEI, sp);
  i = 0;
  emxInit_real_T(sp, &b_X, 2, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &c_X, 2, &d_emlrtRTEI, true);
  while (i <= (int32_T)n - 1) {
    i0 = (i << 2) + 1;
    unnamed_idx_1 = (uint32_T)(1 + i) << 2;
    if ((uint32_T)i0 > unnamed_idx_1) {
      i0 = 0;
      i1 = 0;
    } else {
      i1 = X->size[1];
      if (i0 < i1) {
        i2 = i0;
      } else {
        i2 = emlrtDynamicBoundsCheckR2012b(i0, 1, i1, &emlrtBCI, sp);
      }

      i0 = i2 - 1;
      i1 = X->size[1];
      i3 = (int32_T)unnamed_idx_1;
      if ((i3 >= 1) && (i3 < i1)) {
        i1 = i3;
      } else {
        i1 = emlrtDynamicBoundsCheckR2012b(i3, 1, i1, &emlrtBCI, sp);
      }
    }

    for (b_i = 0; b_i < 2; b_i++) {
      iv0[b_i] = 4;
    }

    i3 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 4;
    b_X->size[1] = i1 - i0;
    emxEnsureCapacity(sp, (emxArray__common *)b_X, i3, (int32_T)sizeof(real_T),
                      &d_emlrtRTEI);
    loop_ub = i1 - i0;
    for (i3 = 0; i3 < loop_ub; i3++) {
      for (b_i = 0; b_i < 4; b_i++) {
        b_X->data[b_i + b_X->size[0] * i3] = X->data[b_i + X->size[0] * (i0 + i3)];
      }
    }

    for (i3 = 0; i3 < 2; i3++) {
      a_size[i3] = b_X->size[i3];
    }

    if ((4 != a_size[0]) || (4 != a_size[1])) {
      emlrtSizeEqCheckNDR2012b(iv0, a_size, &emlrtECI, sp);
    }

    i3 = c_X->size[0] * c_X->size[1];
    c_X->size[0] = 4;
    c_X->size[1] = i1 - i0;
    emxEnsureCapacity(sp, (emxArray__common *)c_X, i3, (int32_T)sizeof(real_T),
                      &d_emlrtRTEI);
    loop_ub = i1 - i0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i3 = 0; i3 < 4; i3++) {
        c_X->data[i3 + c_X->size[0] * i1] = X->data[i3 + X->size[0] * (i0 + i1)];
      }
    }

    for (i0 = 0; i0 < 4; i0++) {
      for (i1 = 0; i1 < 4; i1++) {
        M_hat[i1 + (i0 << 2)] += c_X->data[i1 + (i0 << 2)];
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&c_X);
  emxFree_real_T(&b_X);
  st.site = &emlrtRSI;
  mean_Taylor_1st(&st, X, MX);

  /*  Potential further refinement */
  /*  M_t1 = mean_Taylor_1st( M_t1 ); */
  /*  Perturb M_t1 along each direction defined by the Lie algebra element of */
  /*  SE(3) */
  CA = rtInf;
  CA1 = rtInf;
  CA2 = rtInf;
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      E[i1 + (i0 << 2)] = iv1[i1 + (i0 << 2)];
      E[16 + (i1 + (i0 << 2))] = iv2[i1 + (i0 << 2)];
      E[32 + (i1 + (i0 << 2))] = iv3[i1 + (i0 << 2)];
      E[48 + (i1 + (i0 << 2))] = iv4[i1 + (i0 << 2)];
      E[64 + (i1 + (i0 << 2))] = iv5[i1 + (i0 << 2)];
      E[80 + (i1 + (i0 << 2))] = iv6[i1 + (i0 << 2)];
    }
  }

  count = 0.0;
  if (noise == 0.0) {
    m = 3;
  } else if (noise == 1.0) {
    m = 0;
  } else {
    m = -1;
  }

  step = 1.0;

  /*  Change the step lengths if descent direction is not found */
  /*  fprintf('---------------------------------------------- \n') */
  /*  fprintf('Search gradient descent direction from %f to 6 \n', m) */
  /*  fprintf('---------------------------------------------- \n') */
  emxInit_real_T(sp, &X_k, 2, &e_emlrtRTEI, true);
  emxInit_real_T(sp, &C, 2, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 2, &d_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (muDoubleScalarAbs(CA) > 1.0E-12)) {
    count++;
    n_step = 0.0;

    /*  Approximation of rotation is good so far so we only further optimize */
    /*  on translation */
    j = 0;
    while (j <= 5 - m) {
      b_j = m + j;
      a = step * 0.001;
      i0 = b_j + 1;
      emlrtDynamicBoundsCheckR2012b(i0, 1, 6, &b_emlrtBCI, sp);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          b_a[i1 + (i0 << 2)] = a * (real_T)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      st.site = &b_emlrtRSI;
      expm(&st, b_a, MX1sum);
      a = -step * 0.001;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          MX1[i0 + (i1 << 2)] = 0.0;
          for (i3 = 0; i3 < 4; i3++) {
            MX1[i0 + (i1 << 2)] += MX[i0 + (i3 << 2)] * MX1sum[i3 + (i1 << 2)];
          }

          b_a[i1 + (i0 << 2)] = a * (real_T)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      st.site = &c_emlrtRSI;
      expm(&st, b_a, MX1sum);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          MX2[i0 + (i1 << 2)] = 0.0;
          for (i3 = 0; i3 < 4; i3++) {
            MX2[i0 + (i1 << 2)] += MX[i0 + (i3 << 2)] * MX1sum[i3 + (i1 << 2)];
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        MX1sum[i0] = 0.0;
        MX2sum[i0] = 0.0;
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
        &i_emlrtRTEI, sp);
      k = 0;
      while (k <= (int32_T)n - 1) {
        i0 = (k << 2) + 1;
        unnamed_idx_1 = (uint32_T)(1 + k) << 2;
        if ((uint32_T)i0 > unnamed_idx_1) {
          i0 = 1;
          i1 = 1;
        } else {
          i1 = X->size[1];
          if (i0 < i1) {
          } else {
            i0 = emlrtDynamicBoundsCheckR2012b(i0, 1, i1, &c_emlrtBCI, sp);
          }

          i1 = X->size[1];
          i3 = (int32_T)unnamed_idx_1;
          if ((i3 >= 1) && (i3 < i1)) {
            i4 = i3;
          } else {
            i4 = emlrtDynamicBoundsCheckR2012b(i3, 1, i1, &c_emlrtBCI, sp);
          }

          i1 = i4 + 1;
        }

        i3 = X_k->size[0] * X_k->size[1];
        X_k->size[0] = 4;
        X_k->size[1] = i1 - i0;
        emxEnsureCapacity(sp, (emxArray__common *)X_k, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        loop_ub = i1 - i0;
        for (i3 = 0; i3 < loop_ub; i3++) {
          for (b_i = 0; b_i < 4; b_i++) {
            X_k->data[b_i + X_k->size[0] * i3] = X->data[b_i + X->size[0] * ((i0
              + i3) - 1)];
          }
        }

        st.site = &d_emlrtRSI;
        mrdivide(&st, X_k, MX1, b_a, a_size);
        st.site = &d_emlrtRSI;
        b_i = i1 - i0;
        unnamed_idx_1 = (uint32_T)(i1 - i0);
        i3 = r0->size[0] * r0->size[1];
        r0->size[0] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        i3 = r0->size[0] * r0->size[1];
        r0->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        loop_ub = b_i << 2;
        for (i3 = 0; i3 < loop_ub; i3++) {
          r0->data[i3] = 0.0;
        }

        b_st.site = &tc_emlrtRSI;
        c_st.site = &uc_emlrtRSI;
        i3 = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity(&c_st, (emxArray__common *)C, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        i3 = C->size[0] * C->size[1];
        C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&c_st, (emxArray__common *)C, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        loop_ub = b_i << 2;
        for (i3 = 0; i3 < loop_ub; i3++) {
          C->data[i3] = 0.0;
        }

        if (i1 - i0 < 1) {
        } else {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)4;
          n_t = (ptrdiff_t)(i1 - i0);
          k_t = (ptrdiff_t)4;
          lda_t = (ptrdiff_t)4;
          ldb_t = (ptrdiff_t)4;
          ldc_t = (ptrdiff_t)4;
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &b_a[0], &lda_t,
                &X_k->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
        }

        for (i = 0; i < 2; i++) {
          iv0[i] = 4;
        }

        for (i3 = 0; i3 < 2; i3++) {
          a_size[i3] = C->size[i3];
        }

        if ((4 != a_size[0]) || (4 != a_size[1])) {
          emlrtSizeEqCheckNDR2012b(iv0, a_size, &b_emlrtECI, sp);
        }

        for (i3 = 0; i3 < 16; i3++) {
          b_MX1sum = MX1sum[i3] + C->data[i3];
          MX1sum[i3] = b_MX1sum;
        }

        st.site = &e_emlrtRSI;
        mrdivide(&st, X_k, MX2, b_a, a_size);
        st.site = &e_emlrtRSI;
        b_i = i1 - i0;
        unnamed_idx_1 = (uint32_T)(i1 - i0);
        i3 = r0->size[0] * r0->size[1];
        r0->size[0] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        i3 = r0->size[0] * r0->size[1];
        r0->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        loop_ub = b_i << 2;
        for (i3 = 0; i3 < loop_ub; i3++) {
          r0->data[i3] = 0.0;
        }

        b_st.site = &tc_emlrtRSI;
        c_st.site = &uc_emlrtRSI;
        i3 = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity(&c_st, (emxArray__common *)C, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        i3 = C->size[0] * C->size[1];
        C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&c_st, (emxArray__common *)C, i3, (int32_T)sizeof
                          (real_T), &d_emlrtRTEI);
        loop_ub = b_i << 2;
        for (i3 = 0; i3 < loop_ub; i3++) {
          C->data[i3] = 0.0;
        }

        if (i1 - i0 < 1) {
        } else {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)4;
          n_t = (ptrdiff_t)(i1 - i0);
          k_t = (ptrdiff_t)4;
          lda_t = (ptrdiff_t)4;
          ldb_t = (ptrdiff_t)4;
          ldc_t = (ptrdiff_t)4;
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &b_a[0], &lda_t,
                &X_k->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
        }

        for (i = 0; i < 2; i++) {
          iv0[i] = 4;
        }

        for (i0 = 0; i0 < 2; i0++) {
          a_size[i0] = C->size[i0];
        }

        if ((4 != a_size[0]) || (4 != a_size[1])) {
          emlrtSizeEqCheckNDR2012b(iv0, a_size, &c_emlrtECI, sp);
        }

        for (i0 = 0; i0 < 16; i0++) {
          b_MX2sum = MX2sum[i0] + C->data[i0];
          MX2sum[i0] = b_MX2sum;
        }

        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      y = 2.0 / n;
      b_y = 0.5 / n;
      c_y = 2.0 / n;
      d_y = 0.5 / n;
      for (i0 = 0; i0 < 16; i0++) {
        MX1sum[i0] = (y * M_hat[i0] - b_y * MX1sum[i0]) - 1.5 * MX1[i0];
        MX2sum[i0] = (c_y * M_hat[i0] - d_y * MX2sum[i0]) - 1.5 * MX2[i0];
      }

      if (noise == 0.0) {
        a = norm(*(real_T (*)[3])&MX1sum[12]);
        CA1 = a * a;
        a = norm(*(real_T (*)[3])&MX2sum[12]);
        CA2 = a * a;
      } else if (noise == 1.0) {
        st.site = &f_emlrtRSI;
        a = b_norm(&st, MX1sum);
        CA1 = a * a;
        st.site = &g_emlrtRSI;
        a = b_norm(&st, MX2sum);
        CA2 = a * a;
      } else {
        CA1 = -1.0;
        CA2 = -1.0;
      }

      if ((CA1 <= CA2) && (CA1 < CA)) {
        CA = CA1;
        memcpy(&MX[0], &MX1[0], sizeof(real_T) << 4);
        step = 1.0;

        /*  fprintf('Found a descent direction along %d \n', j) */
        /*  disp(MX1cost) */
        /*  disp(CA) */
      } else if ((CA2 < CA1) && (CA2 < CA)) {
        CA = CA2;
        memcpy(&MX[0], &MX2[0], sizeof(real_T) << 4);
        step = 1.0;

        /*  fprintf('Found a descent direction along -%d \n', j) */
        /*  disp(MX2cost) */
        /*  disp(CA) */
      } else {
        /*  fprintf('Not a descent direction along +/-%d \n', j) */
        n_step++;
        if (n_step == 6.0) {
          step++;
        }
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }

    if (count == num) {
      st.site = &h_emlrtRSI;
      emlrtDisplayR2012b(emlrt_marshallOut(d_fprintf(&st, CA1)), "ans",
                         &emlrtRTEI, sp);
      st.site = &i_emlrtRSI;
      emlrtDisplayR2012b(emlrt_marshallOut(f_fprintf(&st, CA2)), "ans",
                         &b_emlrtRTEI, sp);
      exitg1 = true;
    }
  }

  emxFree_real_T(&r0);
  emxFree_real_T(&C);
  emxFree_real_T(&X_k);
  st.site = &j_emlrtRSI;
  emlrtDisplayR2012b(emlrt_marshallOut(h_fprintf(&st, count)), "ans",
                     &c_emlrtRTEI, sp);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mean_Taylor_2nd_adv.c) */
