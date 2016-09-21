/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_Taylor_2nd.c
 *
 * Code generation for function 'mean_Taylor_2nd'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "mean_Taylor_2nd.h"
#include "mean_convl_2nd_emxutil.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "mean_Taylor_1st.h"
#include "mean_convl_2nd_mexutil.h"
#include "mean_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo d_emlrtRTEI = { 127, 1, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo m_emlrtRSI = { 17, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo n_emlrtRSI = { 20, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo o_emlrtRSI = { 68, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo p_emlrtRSI = { 69, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo q_emlrtRSI = { 76, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo r_emlrtRSI = { 77, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo s_emlrtRSI = { 87, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo t_emlrtRSI = { 88, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo u_emlrtRSI = { 127, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 11, 15, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 75, 13, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtECInfo c_emlrtECI = { 2, 77, 22, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtECInfo d_emlrtECI = { 2, 76, 22, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 75, 23, "X", "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m",
  0 };

static emlrtRTEInfo o_emlrtRTEI = { 74, 9, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtBCInfo e_emlrtBCI = { 1, 6, 68, 39, "E", "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m",
  0 };

/* Function Definitions */
void mean_Taylor_2nd(const emlrtStack *sp, const emxArray_real_T *X, int8_T
                     noise, int16_T num, real_T MX[16])
{
  real_T M_t1[16];
  real_T b_M_t1[16];
  real_T n;
  real_T CA;
  int8_T E[96];
  int32_T i10;
  int32_T i11;
  static const int8_T iv8[16] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv9[16] = { 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv10[16] = { 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv11[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0 };

  static const int8_T iv12[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0 };

  static const int8_T iv13[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0 };

  real_T count;
  int32_T m;
  real_T step;
  emxArray_real_T *X_k;
  emxArray_real_T *C;
  emxArray_real_T *a;
  emxArray_real_T *r1;
  boolean_T exitg1;
  real_T n_step;
  int32_T j;
  int32_T b_j;
  real_T b_a;
  real_T c_a[16];
  real_T MX1sum[16];
  real_T MX1[16];
  int32_T i;
  real_T MX2[16];
  real_T MX2sum[16];
  int32_T k;
  uint32_T unnamed_idx_1;
  int32_T i12;
  int32_T loop_ub;
  int32_T i13;
  int32_T tmp_size[2];
  int32_T unnamed_idx_0;
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
  int32_T b_C[2];
  real_T b_MX1sum;
  real_T b_MX2sum;
  real_T y;
  real_T b_y;
  real_T CA1;
  real_T CA2;
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
  st.site = &m_emlrtRSI;
  mean_Taylor_1st(&st, X, M_t1);

  /*  Potential further refinement */
  memcpy(&b_M_t1[0], &M_t1[0], sizeof(real_T) << 4);
  st.site = &n_emlrtRSI;
  b_mean_Taylor_1st(&st, b_M_t1, M_t1);
  n = (real_T)X->size[1] / 4.0;

  /*  Perturb M_t1 along each direction defined by the Lie algebra element of */
  /*  SE(3) */
  CA = rtInf;
  for (i10 = 0; i10 < 4; i10++) {
    for (i11 = 0; i11 < 4; i11++) {
      E[i11 + (i10 << 2)] = iv8[i11 + (i10 << 2)];
      E[16 + (i11 + (i10 << 2))] = iv9[i11 + (i10 << 2)];
      E[32 + (i11 + (i10 << 2))] = iv10[i11 + (i10 << 2)];
      E[48 + (i11 + (i10 << 2))] = iv11[i11 + (i10 << 2)];
      E[64 + (i11 + (i10 << 2))] = iv12[i11 + (i10 << 2)];
      E[80 + (i11 + (i10 << 2))] = iv13[i11 + (i10 << 2)];
    }
  }

  memcpy(&MX[0], &M_t1[0], sizeof(real_T) << 4);
  count = 0.0;
  if (noise == 0) {
    m = 3;
  } else if (noise == 1) {
    m = 0;
  } else {
    m = -1;
  }

  step = 1.0;

  /*  Change the step lengths if descent direction is not found */
  /*  fprintf('---------------------------------------------- \n') */
  /*  fprintf('Search gradient descent direction from %f to 6 \n', m) */
  /*  fprintf('---------------------------------------------- \n') */
  emxInit_real_T(sp, &X_k, 2, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &C, 2, &h_emlrtRTEI, true);
  emxInit_real_T(sp, &a, 2, &h_emlrtRTEI, true);
  emxInit_real_T(sp, &r1, 2, &h_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (muDoubleScalarAbs(CA) > 1.0E-12)) {
    count++;
    n_step = 0.0;

    /*  Approximation of rotation is good so far so we only further optimize */
    /*  on translation */
    j = 0;
    while (j <= 5 - m) {
      b_j = m + j;

      /*  disp(step) */
      b_a = step * 0.001;
      i10 = b_j + 1;
      emlrtDynamicBoundsCheckR2012b(i10, 1, 6, &e_emlrtBCI, sp);
      for (i10 = 0; i10 < 4; i10++) {
        for (i11 = 0; i11 < 4; i11++) {
          c_a[i11 + (i10 << 2)] = b_a * (real_T)E[(i11 + (i10 << 2)) + (b_j << 4)];
        }
      }

      st.site = &o_emlrtRSI;
      expm(&st, c_a, MX1sum);
      b_a = -step * 0.001;
      for (i10 = 0; i10 < 4; i10++) {
        for (i11 = 0; i11 < 4; i11++) {
          MX1[i10 + (i11 << 2)] = 0.0;
          for (i = 0; i < 4; i++) {
            MX1[i10 + (i11 << 2)] += MX[i10 + (i << 2)] * MX1sum[i + (i11 << 2)];
          }

          c_a[i11 + (i10 << 2)] = b_a * (real_T)E[(i11 + (i10 << 2)) + (b_j << 4)];
        }
      }

      st.site = &p_emlrtRSI;
      expm(&st, c_a, MX1sum);
      for (i10 = 0; i10 < 4; i10++) {
        for (i11 = 0; i11 < 4; i11++) {
          MX2[i10 + (i11 << 2)] = 0.0;
          for (i = 0; i < 4; i++) {
            MX2[i10 + (i11 << 2)] += MX[i10 + (i << 2)] * MX1sum[i + (i11 << 2)];
          }
        }
      }

      for (i10 = 0; i10 < 16; i10++) {
        MX1sum[i10] = 0.0;
        MX2sum[i10] = 0.0;
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
        &o_emlrtRTEI, sp);
      k = 0;
      while (k <= (int32_T)n - 1) {
        i10 = (k << 2) + 1;
        unnamed_idx_1 = (uint32_T)(1 + k) << 2;
        if ((uint32_T)i10 > unnamed_idx_1) {
          i10 = 0;
          i11 = 0;
        } else {
          i11 = X->size[1];
          if (i10 < i11) {
            i12 = i10;
          } else {
            i12 = emlrtDynamicBoundsCheckR2012b(i10, 1, i11, &d_emlrtBCI, sp);
          }

          i10 = i12 - 1;
          i11 = X->size[1];
          i = (int32_T)unnamed_idx_1;
          if ((i >= 1) && (i < i11)) {
            i11 = i;
          } else {
            i11 = emlrtDynamicBoundsCheckR2012b(i, 1, i11, &d_emlrtBCI, sp);
          }
        }

        i = X_k->size[0] * X_k->size[1];
        X_k->size[0] = 4;
        X_k->size[1] = i11 - i10;
        emxEnsureCapacity(sp, (emxArray__common *)X_k, i, (int32_T)sizeof(real_T),
                          &h_emlrtRTEI);
        loop_ub = i11 - i10;
        for (i = 0; i < loop_ub; i++) {
          for (i13 = 0; i13 < 4; i13++) {
            X_k->data[i13 + X_k->size[0] * i] = X->data[i13 + X->size[0] * (i10
              + i)];
          }
        }

        st.site = &q_emlrtRSI;
        b_st.site = &q_emlrtRSI;
        mrdivide(&b_st, X_k, MX1, c_a, tmp_size);
        i = a->size[0] * a->size[1];
        a->size[0] = 4;
        a->size[1] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)a, i, (int32_T)sizeof(real_T),
                          &h_emlrtRTEI);
        for (i = 0; i < 16; i++) {
          a->data[i] = c_a[i];
        }

        b_st.site = &fd_emlrtRSI;
        unnamed_idx_0 = i11 - i10;
        unnamed_idx_1 = (uint32_T)(i11 - i10);
        i = r1->size[0] * r1->size[1];
        r1->size[0] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)r1, i, (int32_T)sizeof(real_T),
                          &h_emlrtRTEI);
        i = r1->size[0] * r1->size[1];
        r1->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)r1, i, (int32_T)sizeof(real_T),
                          &h_emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i = 0; i < loop_ub; i++) {
          r1->data[i] = 0.0;
        }

        b_st.site = &ed_emlrtRSI;
        c_st.site = &gd_emlrtRSI;
        i = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity(&c_st, (emxArray__common *)C, i, (int32_T)sizeof
                          (real_T), &h_emlrtRTEI);
        i = C->size[0] * C->size[1];
        C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&c_st, (emxArray__common *)C, i, (int32_T)sizeof
                          (real_T), &h_emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i = 0; i < loop_ub; i++) {
          C->data[i] = 0.0;
        }

        if (i11 - i10 < 1) {
        } else {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)4;
          n_t = (ptrdiff_t)(i11 - i10);
          k_t = (ptrdiff_t)4;
          lda_t = (ptrdiff_t)4;
          ldb_t = (ptrdiff_t)4;
          ldc_t = (ptrdiff_t)4;
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a->data[0], &lda_t,
                &X_k->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
        }

        for (i = 0; i < 2; i++) {
          tmp_size[i] = 4;
        }

        for (i = 0; i < 2; i++) {
          b_C[i] = C->size[i];
        }

        if ((4 != b_C[0]) || (4 != b_C[1])) {
          emlrtSizeEqCheckNDR2012b(tmp_size, b_C, &d_emlrtECI, sp);
        }

        for (i = 0; i < 16; i++) {
          b_MX1sum = MX1sum[i] + C->data[i];
          MX1sum[i] = b_MX1sum;
        }

        st.site = &r_emlrtRSI;
        b_st.site = &r_emlrtRSI;
        mrdivide(&b_st, X_k, MX2, c_a, tmp_size);
        i = a->size[0] * a->size[1];
        a->size[0] = 4;
        a->size[1] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)a, i, (int32_T)sizeof(real_T),
                          &h_emlrtRTEI);
        for (i = 0; i < 16; i++) {
          a->data[i] = c_a[i];
        }

        b_st.site = &fd_emlrtRSI;
        unnamed_idx_0 = i11 - i10;
        unnamed_idx_1 = (uint32_T)(i11 - i10);
        i = r1->size[0] * r1->size[1];
        r1->size[0] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)r1, i, (int32_T)sizeof(real_T),
                          &h_emlrtRTEI);
        i = r1->size[0] * r1->size[1];
        r1->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)r1, i, (int32_T)sizeof(real_T),
                          &h_emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i = 0; i < loop_ub; i++) {
          r1->data[i] = 0.0;
        }

        b_st.site = &ed_emlrtRSI;
        c_st.site = &gd_emlrtRSI;
        i = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity(&c_st, (emxArray__common *)C, i, (int32_T)sizeof
                          (real_T), &h_emlrtRTEI);
        i = C->size[0] * C->size[1];
        C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&c_st, (emxArray__common *)C, i, (int32_T)sizeof
                          (real_T), &h_emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i = 0; i < loop_ub; i++) {
          C->data[i] = 0.0;
        }

        if (i11 - i10 < 1) {
        } else {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)4;
          n_t = (ptrdiff_t)(i11 - i10);
          k_t = (ptrdiff_t)4;
          lda_t = (ptrdiff_t)4;
          ldb_t = (ptrdiff_t)4;
          ldc_t = (ptrdiff_t)4;
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a->data[0], &lda_t,
                &X_k->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
        }

        for (i = 0; i < 2; i++) {
          tmp_size[i] = 4;
        }

        for (i10 = 0; i10 < 2; i10++) {
          b_C[i10] = C->size[i10];
        }

        if ((4 != b_C[0]) || (4 != b_C[1])) {
          emlrtSizeEqCheckNDR2012b(tmp_size, b_C, &c_emlrtECI, sp);
        }

        for (i10 = 0; i10 < 16; i10++) {
          b_MX2sum = MX2sum[i10] + C->data[i10];
          MX2sum[i10] = b_MX2sum;
        }

        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      y = 0.5 / n;
      b_y = 0.5 / n;
      for (i10 = 0; i10 < 16; i10++) {
        MX1sum[i10] = (2.0 * M_t1[i10] - y * MX1sum[i10]) - 1.5 * MX1[i10];
        MX2sum[i10] = (2.0 * M_t1[i10] - b_y * MX2sum[i10]) - 1.5 * MX2[i10];
      }

      if (noise == 0) {
        b_a = norm(*(real_T (*)[3])&MX1sum[12]);
        CA1 = b_a * b_a;
        b_a = norm(*(real_T (*)[3])&MX2sum[12]);
        CA2 = b_a * b_a;
      } else if (noise == 1) {
        st.site = &s_emlrtRSI;
        b_a = b_norm(&st, MX1sum);
        CA1 = b_a * b_a;
        st.site = &t_emlrtRSI;
        b_a = b_norm(&st, MX2sum);
        CA2 = b_a * b_a;
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
      exitg1 = true;
    }
  }

  emxFree_real_T(&r1);
  emxFree_real_T(&a);
  emxFree_real_T(&C);
  emxFree_real_T(&X_k);

  /*  fprintf('\n') */
  st.site = &u_emlrtRSI;
  emlrtDisplayR2012b(emlrt_marshallOut(f_fprintf(&st, count)), "ans",
                     &d_emlrtRTEI, sp);

  /*  fprintf('\n') */
  /*  fprintf('\n') */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mean_Taylor_2nd.c) */
