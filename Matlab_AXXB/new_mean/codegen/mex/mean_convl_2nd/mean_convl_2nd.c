/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_convl_2nd.c
 *
 * Code generation for function 'mean_convl_2nd'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "mean_convl_2nd_emxutil.h"
#include "mrdivide.h"
#include "fprintf.h"
#include "norm.h"
#include "expm.h"
#include "mean_Taylor_2nd.h"
#include "mean_convl_2nd_mexutil.h"
#include "mean_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 12, 5, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 132, 5, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 127, 9, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo emlrtRSI = { 12, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo b_emlrtRSI = { 18, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo c_emlrtRSI = { 20, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo d_emlrtRSI = { 75, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo e_emlrtRSI = { 76, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo f_emlrtRSI = { 85, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo g_emlrtRSI = { 86, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo h_emlrtRSI = { 97, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo i_emlrtRSI = { 98, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo j_emlrtRSI = { 127, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRSInfo k_emlrtRSI = { 132, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 6, 18, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 83, 17, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 84, 17, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

static emlrtECInfo emlrtECI = { 2, 86, 29, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtECInfo b_emlrtECI = { 2, 85, 29, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 84, 29, "X2", "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 83, 29, "X1", "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m",
  0 };

static emlrtRTEInfo m_emlrtRTEI = { 82, 13, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 81, 9, "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m"
};

static emlrtBCInfo c_emlrtBCI = { 1, 6, 75, 44, "E", "mean_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_convl_2nd.m",
  0 };

/* Function Definitions */
void mean_convl_2nd(const emlrtStack *sp, const emxArray_real_T *X1, const
                    emxArray_real_T *X2, int8_T s1, int8_T s2, int16_T n_search,
                    real_T M12_f[16])
{
  real_T n1;
  real_T n2;
  real_T M1[16];
  real_T M2[16];
  int32_T i0;
  int32_T i1;
  real_T M12[16];
  int32_T i2;
  real_T CA;
  int8_T E[96];
  static const int8_T iv0[16] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv1[16] = { 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv2[16] = { 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv3[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0
  };

  static const int8_T iv4[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0
  };

  static const int8_T iv5[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0
  };

  real_T step;
  real_T n_step;
  int32_T m;
  emxArray_real_T *X1_i;
  emxArray_real_T *X2_k;
  emxArray_real_T *C;
  emxArray_real_T *r0;
  emxArray_real_T *a;
  boolean_T exitg1;
  real_T eps;
  int32_T j;
  int32_T b_j;
  real_T b_a;
  real_T c_a[16];
  real_T M12_r[16];
  real_T M12_l[16];
  int32_T i;
  int32_T k;
  uint32_T unnamed_idx_1;
  int32_T i3;
  int32_T loop_ub;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
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
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T d_a[2];
  real_T b_M1;
  real_T b_M2;
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

  /*  This fucntion calculate the 2nd order approximation of the mean of the */
  /*  convolution of two probability density functions on SE(3). */
  /*  Input: X1 and X2 denote the data streams */
  n1 = (real_T)X1->size[1] / 4.0;
  n2 = (real_T)X2->size[1] / 4.0;
  if (n1 != n2) {
    st.site = &emlrtRSI;
    emlrtDisplayR2012b(emlrt_marshallOut(b_fprintf(&st)), "ans", &emlrtRTEI, sp);
  }

  st.site = &b_emlrtRSI;
  mean_Taylor_2nd(&st, X1, s1, n_search, M1);
  st.site = &c_emlrtRSI;
  mean_Taylor_2nd(&st, X2, s2, n_search, M2);
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      M12[i0 + (i1 << 2)] = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        M12[i0 + (i1 << 2)] += M1[i0 + (i2 << 2)] * M2[i2 + (i1 << 2)];
      }
    }
  }

  /*  Initial guess of M12 */
  memcpy(&M12_f[0], &M12[0], sizeof(real_T) << 4);

  /*  Final M12 */
  /*  Perturb M_t1 along each direction defined by the Lie algebra element of */
  /*  SE(3) */
  CA = rtInf;
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      E[i1 + (i0 << 2)] = iv0[i1 + (i0 << 2)];
      E[16 + (i1 + (i0 << 2))] = iv1[i1 + (i0 << 2)];
      E[32 + (i1 + (i0 << 2))] = iv2[i1 + (i0 << 2)];
      E[48 + (i1 + (i0 << 2))] = iv3[i1 + (i0 << 2)];
      E[64 + (i1 + (i0 << 2))] = iv4[i1 + (i0 << 2)];
      E[80 + (i1 + (i0 << 2))] = iv5[i1 + (i0 << 2)];
    }
  }

  step = 1.0;
  n_step = 0.0;
  if (s1 == 0) {
    m = 4;
  } else {
    m = (s1 == 1);
  }

  emxInit_real_T(sp, &X1_i, 2, &f_emlrtRTEI, true);
  emxInit_real_T(sp, &X2_k, 2, &g_emlrtRTEI, true);
  emxInit_real_T(sp, &C, 2, &e_emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 2, &e_emlrtRTEI, true);
  emxInit_real_T(sp, &a, 2, &e_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (muDoubleScalarAbs(CA) > 1.0E-12)) {
    /*  Adjust the step length */
    if (muDoubleScalarAbs(CA) > 0.001) {
      eps = 0.05;
    } else if (muDoubleScalarAbs(CA) < 1.0E-6) {
      eps = 0.0001;
    } else if (muDoubleScalarAbs(CA) < 1.0E-8) {
      eps = 1.0E-5;
    } else if (muDoubleScalarAbs(CA) < 1.0E-9) {
      eps = 1.0E-6;
    } else {
      eps = 0.001;
    }

    /*  Approximation of rotation is good so far so we only further optimize */
    /*  on translation */
    j = -1;
    while (j + 1 <= 6 - m) {
      b_j = m + j;

      /*  disp(step) */
      b_a = step * eps;
      i0 = b_j + 1;
      emlrtDynamicBoundsCheckR2012b(i0, 1, 6, &c_emlrtBCI, sp);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          c_a[i1 + (i0 << 2)] = b_a * (real_T)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      st.site = &d_emlrtRSI;
      expm(&st, c_a, M1);
      b_a = -step * eps;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          M12_r[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            M12_r[i0 + (i1 << 2)] += M12_f[i0 + (i2 << 2)] * M1[i2 + (i1 << 2)];
          }

          c_a[i1 + (i0 << 2)] = b_a * (real_T)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      st.site = &e_emlrtRSI;
      expm(&st, c_a, M1);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          M12_l[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            M12_l[i0 + (i1 << 2)] += M12_f[i0 + (i2 << 2)] * M1[i2 + (i1 << 2)];
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        M1[i0] = 0.0;
        M2[i0] = 0.0;
      }

      emlrtForLoopVectorCheckR2012b(1.0, 1.0, n1, mxDOUBLE_CLASS, (int32_T)n1,
        &n_emlrtRTEI, sp);
      i = 0;
      while (i <= (int32_T)n1 - 1) {
        emlrtForLoopVectorCheckR2012b(1.0, 1.0, n2, mxDOUBLE_CLASS, (int32_T)n2,
          &m_emlrtRTEI, sp);
        k = 0;
        while (k <= (int32_T)n2 - 1) {
          i0 = (i << 2) + 1;
          unnamed_idx_1 = (uint32_T)(1 + i) << 2;
          if ((uint32_T)i0 > unnamed_idx_1) {
            i0 = 0;
            i1 = 0;
          } else {
            i1 = X1->size[1];
            if (i0 < i1) {
              i3 = i0;
            } else {
              i3 = emlrtDynamicBoundsCheckR2012b(i0, 1, i1, &b_emlrtBCI, sp);
            }

            i0 = i3 - 1;
            i1 = X1->size[1];
            i2 = (int32_T)unnamed_idx_1;
            if ((i2 >= 1) && (i2 < i1)) {
              i1 = i2;
            } else {
              i1 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &b_emlrtBCI, sp);
            }
          }

          i2 = X1_i->size[0] * X1_i->size[1];
          X1_i->size[0] = 4;
          X1_i->size[1] = i1 - i0;
          emxEnsureCapacity(sp, (emxArray__common *)X1_i, i2, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = i1 - i0;
          for (i2 = 0; i2 < loop_ub; i2++) {
            for (i4 = 0; i4 < 4; i4++) {
              X1_i->data[i4 + X1_i->size[0] * i2] = X1->data[i4 + X1->size[0] *
                (i0 + i2)];
            }
          }

          i2 = (k << 2) + 1;
          unnamed_idx_1 = (uint32_T)(1 + k) << 2;
          if ((uint32_T)i2 > unnamed_idx_1) {
            i2 = 0;
            i4 = 0;
          } else {
            i4 = X2->size[1];
            if (i2 < i4) {
              i5 = i2;
            } else {
              i5 = emlrtDynamicBoundsCheckR2012b(i2, 1, i4, &emlrtBCI, sp);
            }

            i2 = i5 - 1;
            i4 = X2->size[1];
            i6 = (int32_T)unnamed_idx_1;
            if ((i6 >= 1) && (i6 < i4)) {
              i4 = i6;
            } else {
              i4 = emlrtDynamicBoundsCheckR2012b(i6, 1, i4, &emlrtBCI, sp);
            }
          }

          i6 = X2_k->size[0] * X2_k->size[1];
          X2_k->size[0] = 4;
          X2_k->size[1] = i4 - i2;
          emxEnsureCapacity(sp, (emxArray__common *)X2_k, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = i4 - i2;
          for (i6 = 0; i6 < loop_ub; i6++) {
            for (i7 = 0; i7 < 4; i7++) {
              X2_k->data[i7 + X2_k->size[0] * i6] = X2->data[i7 + X2->size[0] *
                (i2 + i6)];
            }
          }

          st.site = &f_emlrtRSI;
          b_st.site = &fd_emlrtRSI;
          if (!(i1 - i0 == 4)) {
            emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
              "Coder:MATLAB:innerdim", 0);
          }

          if (i1 - i0 == 1) {
            i6 = C->size[0] * C->size[1];
            C->size[0] = 4;
            C->size[1] = X2_k->size[1];
            emxEnsureCapacity(&st, (emxArray__common *)C, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            for (i6 = 0; i6 < 4; i6++) {
              loop_ub = X2_k->size[1];
              for (i7 = 0; i7 < loop_ub; i7++) {
                C->data[i6 + C->size[0] * i7] = 0.0;
                for (i8 = 0; i8 < 4; i8++) {
                  C->data[i6 + C->size[0] * i7] += X1_i->data[i6 + (i8 << 2)] *
                    X2_k->data[i8 + X2_k->size[0] * i7];
                }
              }
            }
          } else {
            unnamed_idx_0 = i4 - i2;
            unnamed_idx_1 = (uint32_T)(i4 - i2);
            i6 = r0->size[0] * r0->size[1];
            r0->size[0] = 4;
            emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            i6 = r0->size[0] * r0->size[1];
            r0->size[1] = (int32_T)unnamed_idx_1;
            emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            loop_ub = unnamed_idx_0 << 2;
            for (i6 = 0; i6 < loop_ub; i6++) {
              r0->data[i6] = 0.0;
            }

            b_st.site = &ed_emlrtRSI;
            c_st.site = &gd_emlrtRSI;
            i6 = C->size[0] * C->size[1];
            C->size[0] = 4;
            emxEnsureCapacity(&c_st, (emxArray__common *)C, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            i6 = C->size[0] * C->size[1];
            C->size[1] = (int32_T)unnamed_idx_1;
            emxEnsureCapacity(&c_st, (emxArray__common *)C, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            loop_ub = unnamed_idx_0 << 2;
            for (i6 = 0; i6 < loop_ub; i6++) {
              C->data[i6] = 0.0;
            }

            if ((i4 - i2 < 1) || (i1 - i0 < 1)) {
            } else {
              alpha1 = 1.0;
              beta1 = 0.0;
              TRANSB = 'N';
              TRANSA = 'N';
              m_t = (ptrdiff_t)4;
              n_t = (ptrdiff_t)(i4 - i2);
              k_t = (ptrdiff_t)(i1 - i0);
              lda_t = (ptrdiff_t)4;
              ldb_t = (ptrdiff_t)(i1 - i0);
              ldc_t = (ptrdiff_t)4;
              dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &X1_i->data[0],
                    &lda_t, &X2_k->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
            }
          }

          st.site = &f_emlrtRSI;
          b_st.site = &f_emlrtRSI;
          mrdivide(&b_st, C, M12_r, c_a, tmp_size);
          i6 = a->size[0] * a->size[1];
          a->size[0] = 4;
          a->size[1] = 4;
          emxEnsureCapacity(&st, (emxArray__common *)a, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          for (i6 = 0; i6 < 16; i6++) {
            a->data[i6] = c_a[i6];
          }

          b_st.site = &fd_emlrtRSI;
          unnamed_idx_0 = i1 - i0;
          unnamed_idx_1 = (uint32_T)(i1 - i0);
          i6 = r0->size[0] * r0->size[1];
          r0->size[0] = 4;
          emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          i6 = r0->size[0] * r0->size[1];
          r0->size[1] = (int32_T)unnamed_idx_1;
          emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = unnamed_idx_0 << 2;
          for (i6 = 0; i6 < loop_ub; i6++) {
            r0->data[i6] = 0.0;
          }

          b_st.site = &ed_emlrtRSI;
          c_st.site = &gd_emlrtRSI;
          i6 = C->size[0] * C->size[1];
          C->size[0] = 4;
          emxEnsureCapacity(&c_st, (emxArray__common *)C, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          i6 = C->size[0] * C->size[1];
          C->size[1] = (int32_T)unnamed_idx_1;
          emxEnsureCapacity(&c_st, (emxArray__common *)C, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = unnamed_idx_0 << 2;
          for (i6 = 0; i6 < loop_ub; i6++) {
            C->data[i6] = 0.0;
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
            dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a->data[0],
                  &lda_t, &X1_i->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
          }

          st.site = &f_emlrtRSI;
          b_st.site = &fd_emlrtRSI;
          if (!(C->size[1] == 4)) {
            emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
              "Coder:MATLAB:innerdim", 0);
          }

          unnamed_idx_0 = i4 - i2;
          unnamed_idx_1 = (uint32_T)(i4 - i2);
          i6 = r0->size[0] * r0->size[1];
          r0->size[0] = 4;
          emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          i6 = r0->size[0] * r0->size[1];
          r0->size[1] = (int32_T)unnamed_idx_1;
          emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = unnamed_idx_0 << 2;
          for (i6 = 0; i6 < loop_ub; i6++) {
            r0->data[i6] = 0.0;
          }

          b_st.site = &ed_emlrtRSI;
          c_st.site = &gd_emlrtRSI;
          i6 = a->size[0] * a->size[1];
          a->size[0] = 4;
          emxEnsureCapacity(&c_st, (emxArray__common *)a, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          i6 = a->size[0] * a->size[1];
          a->size[1] = (int32_T)unnamed_idx_1;
          emxEnsureCapacity(&c_st, (emxArray__common *)a, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = unnamed_idx_0 << 2;
          for (i6 = 0; i6 < loop_ub; i6++) {
            a->data[i6] = 0.0;
          }

          if (i4 - i2 < 1) {
          } else {
            alpha1 = 1.0;
            beta1 = 0.0;
            TRANSB = 'N';
            TRANSA = 'N';
            m_t = (ptrdiff_t)4;
            n_t = (ptrdiff_t)(i4 - i2);
            k_t = (ptrdiff_t)4;
            lda_t = (ptrdiff_t)4;
            ldb_t = (ptrdiff_t)4;
            ldc_t = (ptrdiff_t)4;
            dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &C->data[0],
                  &lda_t, &X2_k->data[0], &ldb_t, &beta1, &a->data[0], &ldc_t);
          }

          for (b_i = 0; b_i < 2; b_i++) {
            tmp_size[b_i] = 4;
          }

          for (i6 = 0; i6 < 2; i6++) {
            d_a[i6] = a->size[i6];
          }

          if ((4 != d_a[0]) || (4 != d_a[1])) {
            emlrtSizeEqCheckNDR2012b(tmp_size, d_a, &b_emlrtECI, sp);
          }

          for (i6 = 0; i6 < 16; i6++) {
            b_M1 = M1[i6] + a->data[i6];
            M1[i6] = b_M1;
          }

          st.site = &g_emlrtRSI;
          b_st.site = &fd_emlrtRSI;
          if (!(i1 - i0 == 4)) {
            emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
              "Coder:MATLAB:innerdim", 0);
          }

          if (i1 - i0 == 1) {
            i6 = C->size[0] * C->size[1];
            C->size[0] = 4;
            C->size[1] = X2_k->size[1];
            emxEnsureCapacity(&st, (emxArray__common *)C, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            for (i6 = 0; i6 < 4; i6++) {
              loop_ub = X2_k->size[1];
              for (i7 = 0; i7 < loop_ub; i7++) {
                C->data[i6 + C->size[0] * i7] = 0.0;
                for (i8 = 0; i8 < 4; i8++) {
                  C->data[i6 + C->size[0] * i7] += X1_i->data[i6 + (i8 << 2)] *
                    X2_k->data[i8 + X2_k->size[0] * i7];
                }
              }
            }
          } else {
            unnamed_idx_0 = i4 - i2;
            unnamed_idx_1 = (uint32_T)(i4 - i2);
            i6 = r0->size[0] * r0->size[1];
            r0->size[0] = 4;
            emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            i6 = r0->size[0] * r0->size[1];
            r0->size[1] = (int32_T)unnamed_idx_1;
            emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            loop_ub = unnamed_idx_0 << 2;
            for (i6 = 0; i6 < loop_ub; i6++) {
              r0->data[i6] = 0.0;
            }

            b_st.site = &ed_emlrtRSI;
            c_st.site = &gd_emlrtRSI;
            i6 = C->size[0] * C->size[1];
            C->size[0] = 4;
            emxEnsureCapacity(&c_st, (emxArray__common *)C, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            i6 = C->size[0] * C->size[1];
            C->size[1] = (int32_T)unnamed_idx_1;
            emxEnsureCapacity(&c_st, (emxArray__common *)C, i6, (int32_T)sizeof
                              (real_T), &e_emlrtRTEI);
            loop_ub = unnamed_idx_0 << 2;
            for (i6 = 0; i6 < loop_ub; i6++) {
              C->data[i6] = 0.0;
            }

            if ((i4 - i2 < 1) || (i1 - i0 < 1)) {
            } else {
              alpha1 = 1.0;
              beta1 = 0.0;
              TRANSB = 'N';
              TRANSA = 'N';
              m_t = (ptrdiff_t)4;
              n_t = (ptrdiff_t)(i4 - i2);
              k_t = (ptrdiff_t)(i1 - i0);
              lda_t = (ptrdiff_t)4;
              ldb_t = (ptrdiff_t)(i1 - i0);
              ldc_t = (ptrdiff_t)4;
              dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &X1_i->data[0],
                    &lda_t, &X2_k->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
            }
          }

          st.site = &g_emlrtRSI;
          b_st.site = &g_emlrtRSI;
          mrdivide(&b_st, C, M12_l, c_a, tmp_size);
          i6 = a->size[0] * a->size[1];
          a->size[0] = 4;
          a->size[1] = 4;
          emxEnsureCapacity(&st, (emxArray__common *)a, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          for (i6 = 0; i6 < 16; i6++) {
            a->data[i6] = c_a[i6];
          }

          b_st.site = &fd_emlrtRSI;
          unnamed_idx_0 = i1 - i0;
          unnamed_idx_1 = (uint32_T)(i1 - i0);
          i6 = r0->size[0] * r0->size[1];
          r0->size[0] = 4;
          emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          i6 = r0->size[0] * r0->size[1];
          r0->size[1] = (int32_T)unnamed_idx_1;
          emxEnsureCapacity(&st, (emxArray__common *)r0, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = unnamed_idx_0 << 2;
          for (i6 = 0; i6 < loop_ub; i6++) {
            r0->data[i6] = 0.0;
          }

          b_st.site = &ed_emlrtRSI;
          c_st.site = &gd_emlrtRSI;
          i6 = C->size[0] * C->size[1];
          C->size[0] = 4;
          emxEnsureCapacity(&c_st, (emxArray__common *)C, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          i6 = C->size[0] * C->size[1];
          C->size[1] = (int32_T)unnamed_idx_1;
          emxEnsureCapacity(&c_st, (emxArray__common *)C, i6, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = unnamed_idx_0 << 2;
          for (i6 = 0; i6 < loop_ub; i6++) {
            C->data[i6] = 0.0;
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
            dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a->data[0],
                  &lda_t, &X1_i->data[0], &ldb_t, &beta1, &C->data[0], &ldc_t);
          }

          st.site = &g_emlrtRSI;
          b_st.site = &fd_emlrtRSI;
          if (!(C->size[1] == 4)) {
            emlrtErrorWithMessageIdR2012b(&b_st, &l_emlrtRTEI,
              "Coder:MATLAB:innerdim", 0);
          }

          unnamed_idx_0 = i4 - i2;
          unnamed_idx_1 = (uint32_T)(i4 - i2);
          i0 = r0->size[0] * r0->size[1];
          r0->size[0] = 4;
          emxEnsureCapacity(&st, (emxArray__common *)r0, i0, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          i0 = r0->size[0] * r0->size[1];
          r0->size[1] = (int32_T)unnamed_idx_1;
          emxEnsureCapacity(&st, (emxArray__common *)r0, i0, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = unnamed_idx_0 << 2;
          for (i0 = 0; i0 < loop_ub; i0++) {
            r0->data[i0] = 0.0;
          }

          b_st.site = &ed_emlrtRSI;
          c_st.site = &gd_emlrtRSI;
          i0 = a->size[0] * a->size[1];
          a->size[0] = 4;
          emxEnsureCapacity(&c_st, (emxArray__common *)a, i0, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          i0 = a->size[0] * a->size[1];
          a->size[1] = (int32_T)unnamed_idx_1;
          emxEnsureCapacity(&c_st, (emxArray__common *)a, i0, (int32_T)sizeof
                            (real_T), &e_emlrtRTEI);
          loop_ub = unnamed_idx_0 << 2;
          for (i0 = 0; i0 < loop_ub; i0++) {
            a->data[i0] = 0.0;
          }

          if (i4 - i2 < 1) {
          } else {
            alpha1 = 1.0;
            beta1 = 0.0;
            TRANSB = 'N';
            TRANSA = 'N';
            m_t = (ptrdiff_t)4;
            n_t = (ptrdiff_t)(i4 - i2);
            k_t = (ptrdiff_t)4;
            lda_t = (ptrdiff_t)4;
            ldb_t = (ptrdiff_t)4;
            ldc_t = (ptrdiff_t)4;
            dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &C->data[0],
                  &lda_t, &X2_k->data[0], &ldb_t, &beta1, &a->data[0], &ldc_t);
          }

          for (b_i = 0; b_i < 2; b_i++) {
            tmp_size[b_i] = 4;
          }

          for (i0 = 0; i0 < 2; i0++) {
            d_a[i0] = a->size[i0];
          }

          if ((4 != d_a[0]) || (4 != d_a[1])) {
            emlrtSizeEqCheckNDR2012b(tmp_size, d_a, &emlrtECI, sp);
          }

          for (i0 = 0; i0 < 16; i0++) {
            b_M2 = M2[i0] + a->data[i0];
            M2[i0] = b_M2;
          }

          k++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        i++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      y = 0.25 / (n1 * n1);
      b_y = 0.25 / (n1 * n1);
      for (i0 = 0; i0 < 16; i0++) {
        M1[i0] = (M12[i0] - y * M1[i0]) - 0.75 * M12_r[i0];
        M2[i0] = (M12[i0] - b_y * M2[i0]) - 0.75 * M12_l[i0];
      }

      if (m == 4) {
        b_a = norm(*(real_T (*)[3])&M1[12]);
        CA1 = b_a * b_a;
        b_a = norm(*(real_T (*)[3])&M2[12]);
        CA2 = b_a * b_a;
      } else if (m == 1) {
        st.site = &h_emlrtRSI;
        b_a = b_norm(&st, M1);
        CA1 = b_a * b_a;
        st.site = &i_emlrtRSI;
        b_a = b_norm(&st, M2);
        CA2 = b_a * b_a;
      } else {
        CA1 = -1.0;
        CA2 = -1.0;
      }

      if ((CA1 <= CA2) && (CA1 < CA)) {
        CA = CA1;
        memcpy(&M12_f[0], &M12_r[0], sizeof(real_T) << 4);
        step = 1.0;

        /*  fprintf('Found a descent direction along %d \n', j) */
        /*  disp(MX1cost) */
        /*  disp(CA) */
      } else if ((CA2 < CA1) && (CA2 < CA)) {
        CA = CA2;
        memcpy(&M12_f[0], &M12_l[0], sizeof(real_T) << 4);
        step = 1.0;

        /*  fprintf('Found a descent direction along -%d \n', j) */
        /*  disp(MX2cost) */
        /*  disp(CA) */
      } else {
        /*  fprintf('Not a descent direction along +/-%d \n', j) */
        n_step++;
        if (n_step == (6.0 - (real_T)m) + 1.0) {
          n_step = 0.0;
          step++;
        }
      }

      st.site = &j_emlrtRSI;
      emlrtDisplayR2012b(emlrt_marshallOut(h_fprintf(&st, CA)), "ans",
                         &c_emlrtRTEI, sp);
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }

    if (step == n_search) {
      st.site = &k_emlrtRSI;
      emlrtDisplayR2012b(emlrt_marshallOut(h_fprintf(&st, CA)), "ans",
                         &b_emlrtRTEI, sp);
      exitg1 = true;
    }
  }

  emxFree_real_T(&a);
  emxFree_real_T(&r0);
  emxFree_real_T(&C);
  emxFree_real_T(&X2_k);
  emxFree_real_T(&X1_i);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mean_convl_2nd.c) */
