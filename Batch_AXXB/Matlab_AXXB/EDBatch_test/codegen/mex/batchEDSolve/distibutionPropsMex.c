/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * distibutionPropsMex.c
 *
 * Code generation for function 'distibutionPropsMex'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "distibutionPropsMex.h"
#include "batchEDSolve_emxutil.h"
#include "twistlog.h"
#include "mpower.h"
#include "norm.h"
#include "expm.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 23, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo m_emlrtRSI = { 27, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo n_emlrtRSI = { 50, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo o_emlrtRSI = { 51, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo p_emlrtRSI = { 53, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo q_emlrtRSI = { 54, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo r_emlrtRSI = { 57, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo s_emlrtRSI = { 58, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo t_emlrtRSI = { 73, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo u_emlrtRSI = { 74, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo v_emlrtRSI = { 82, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo w_emlrtRSI = { 83, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo x_emlrtRSI = { 105, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo sc_emlrtRSI = { 54, "eml_xgemm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 23, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 19, 1, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 23, 27, "X", "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

static emlrtRTEInfo f_emlrtRTEI = { 69, 9, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtBCInfo b_emlrtBCI = { -1, -1, 73, 44, "X", "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 74, 44, "X", "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

static emlrtRTEInfo g_emlrtRTEI = { 101, 1, "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 105, 43, "X", "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 105, 80, "X", "distibutionPropsMex",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

/* Function Definitions */
void distibutionPropsMex(const emlrtStack *sp, const emxArray_real_T *X, real_T
  M[16], real_T Sig[36])
{
  real_T Xsum[16];
  real_T n;
  int32_T j;
  emxArray_real_T *b_X;
  int32_T b_j1;
  uint32_T j2;
  int32_T i9;
  int32_T i10;
  int32_T c_j1;
  int32_T i11;
  int32_T loop_ub;
  real_T M1sum[16];
  real_T y;
  real_T b_y[16];
  real_T C_old;
  real_T C;
  int8_T E[96];
  static const int8_T iv10[16] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv11[16] = { 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv12[16] = { 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv13[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0 };

  static const int8_T iv14[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0 };

  static const int8_T iv15[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0 };

  int32_T count;
  emxArray_real_T *b_C;
  emxArray_real_T *b;
  emxArray_real_T *r0;
  real_T M1[16];
  real_T M2[16];
  real_T a;
  real_T M2sum[16];
  real_T d0;
  int32_T k;
  int32_T k1;
  uint32_T k2;
  int32_T i12;
  int32_T i13;
  int32_T unnamed_idx_0;
  uint32_T unnamed_idx_1;
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
  real_T M1X_logm[16];
  int32_T i14;
  real_T C1;
  real_T C2;
  int32_T i;
  emxArray_real_T *c_C;
  int32_T i1;
  uint32_T i2;
  int32_T i15;
  int32_T i16;
  int32_T i17;
  int32_T i18;
  real_T b_M1sum[6];
  real_T b_Xsum[6];
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

  /*  Note: the Matlab bulit-in function logm() is not convertable */
  /*  into a standalone for c/c++ code generation. Another SE3 to twist matrix */
  /*  logarithm is used instead.  */
  /*  addpath('/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws') */
  /*  is needed in the main file that calls this function */
  memset(&Xsum[0], 0, sizeof(real_T) << 4);
  n = (real_T)X->size[1] / 4.0;

  /*  Number of matrices */
  /*  1. Use X to calculate the mean of se(3) Lie algebra */
  /*  2. Exponentiate the mean of se(3) into Lie group SE(3) */
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
    &e_emlrtRTEI, sp);
  j = 0;
  emxInit_real_T(sp, &b_X, 2, &emlrtRTEI, true);
  while (j <= (int32_T)n - 1) {
    b_j1 = (j << 2) + 1;
    j2 = (uint32_T)(1 + j) << 2;
    if ((uint32_T)b_j1 > j2) {
      i9 = 0;
      i10 = 0;
    } else {
      i9 = X->size[1];
      if (b_j1 < i9) {
        c_j1 = b_j1;
      } else {
        c_j1 = emlrtDynamicBoundsCheckR2012b(b_j1, 1, i9, &emlrtBCI, sp);
      }

      i9 = c_j1 - 1;
      i10 = X->size[1];
      i11 = (int32_T)j2;
      if ((i11 >= 1) && (i11 < i10)) {
        i10 = i11;
      } else {
        i10 = emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &emlrtBCI, sp);
      }
    }

    i11 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 4;
    b_X->size[1] = i10 - i9;
    emxEnsureCapacity(sp, (emxArray__common *)b_X, i11, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = i10 - i9;
    for (i10 = 0; i10 < loop_ub; i10++) {
      for (i11 = 0; i11 < 4; i11++) {
        b_X->data[i11 + b_X->size[0] * i10] = X->data[i11 + X->size[0] * (i9 +
          i10)];
      }
    }

    st.site = &l_emlrtRSI;
    twistlog(&st, b_X, M1sum);
    for (i9 = 0; i9 < 16; i9++) {
      Xsum[i9] += M1sum[i9];
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_X);
  y = 1.0 / n;
  for (i9 = 0; i9 < 16; i9++) {
    b_y[i9] = y * Xsum[i9];
  }

  st.site = &m_emlrtRSI;
  expm(&st, b_y, M);
  C_old = rtInf;
  C = 0.0;

  /*  The six Lie algebra elements for SE(3) */
  for (i9 = 0; i9 < 4; i9++) {
    for (i10 = 0; i10 < 4; i10++) {
      E[i10 + (i9 << 2)] = iv10[i10 + (i9 << 2)];
      E[16 + (i10 + (i9 << 2))] = iv11[i10 + (i9 << 2)];
      E[32 + (i10 + (i9 << 2))] = iv12[i10 + (i9 << 2)];
      E[48 + (i10 + (i9 << 2))] = iv13[i10 + (i9 << 2)];
      E[64 + (i10 + (i9 << 2))] = iv14[i10 + (i9 << 2)];
      E[80 + (i10 + (i9 << 2))] = iv15[i10 + (i9 << 2)];
    }
  }

  count = 0;
  emxInit_real_T(sp, &b_C, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);
  while ((muDoubleScalarAbs(C - C_old) > 0.05) && (count < 10)) {
    C_old = C;
    j = 0;
    while (j < 6) {
      if (C_old > 20.0) {
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            b_y[i10 + (i9 << 2)] = 0.02 * (real_T)E[(i10 + (i9 << 2)) + (j << 4)];
          }
        }

        st.site = &n_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            M1[i9 + (i10 << 2)] = 0.0;
            for (i11 = 0; i11 < 4; i11++) {
              M1[i9 + (i10 << 2)] += M[i9 + (i11 << 2)] * Xsum[i11 + (i10 << 2)];
            }

            b_y[i10 + (i9 << 2)] = -0.02 * (real_T)E[(i10 + (i9 << 2)) + (j << 4)];
          }
        }

        st.site = &o_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            M2[i9 + (i10 << 2)] = 0.0;
            for (i11 = 0; i11 < 4; i11++) {
              M2[i9 + (i10 << 2)] += M[i9 + (i11 << 2)] * Xsum[i11 + (i10 << 2)];
            }
          }
        }
      } else if (C_old > 1.0) {
        a = 0.001 * C_old;
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            b_y[i10 + (i9 << 2)] = a * (real_T)E[(i10 + (i9 << 2)) + (j << 4)];
          }
        }

        st.site = &p_emlrtRSI;
        expm(&st, b_y, Xsum);
        a = -0.001 * C_old;
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            M1[i9 + (i10 << 2)] = 0.0;
            for (i11 = 0; i11 < 4; i11++) {
              M1[i9 + (i10 << 2)] += M[i9 + (i11 << 2)] * Xsum[i11 + (i10 << 2)];
            }

            b_y[i10 + (i9 << 2)] = a * (real_T)E[(i10 + (i9 << 2)) + (j << 4)];
          }
        }

        st.site = &q_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            M2[i9 + (i10 << 2)] = 0.0;
            for (i11 = 0; i11 < 4; i11++) {
              M2[i9 + (i10 << 2)] += M[i9 + (i11 << 2)] * Xsum[i11 + (i10 << 2)];
            }
          }
        }
      } else {
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            b_y[i10 + (i9 << 2)] = 0.001 * (real_T)E[(i10 + (i9 << 2)) + (j << 4)];
          }
        }

        st.site = &r_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            M1[i9 + (i10 << 2)] = 0.0;
            for (i11 = 0; i11 < 4; i11++) {
              M1[i9 + (i10 << 2)] += M[i9 + (i11 << 2)] * Xsum[i11 + (i10 << 2)];
            }

            b_y[i10 + (i9 << 2)] = -0.001 * (real_T)E[(i10 + (i9 << 2)) + (j <<
              4)];
          }
        }

        st.site = &s_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i9 = 0; i9 < 4; i9++) {
          for (i10 = 0; i10 < 4; i10++) {
            M2[i9 + (i10 << 2)] = 0.0;
            for (i11 = 0; i11 < 4; i11++) {
              M2[i9 + (i10 << 2)] += M[i9 + (i11 << 2)] * Xsum[i11 + (i10 << 2)];
            }
          }
        }
      }

      for (i9 = 0; i9 < 16; i9++) {
        M1sum[i9] = 0.0;
        M2sum[i9] = 0.0;
      }

      d0 = (real_T)X->size[1] / 4.0;
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)d0,
        &f_emlrtRTEI, sp);
      k = 0;
      while (k <= (int32_T)d0 - 1) {
        k1 = (k << 2) + 1;
        k2 = (uint32_T)(1 + k) << 2;
        if ((uint32_T)k1 > k2) {
          i9 = 1;
          i10 = 1;
        } else {
          i9 = X->size[1];
          if (k1 < i9) {
            i9 = k1;
          } else {
            i9 = emlrtDynamicBoundsCheckR2012b(k1, 1, i9, &b_emlrtBCI, sp);
          }

          i10 = X->size[1];
          i11 = (int32_T)k2;
          if ((i11 >= 1) && (i11 < i10)) {
            i12 = i11;
          } else {
            i12 = emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &b_emlrtBCI, sp);
          }

          i10 = i12 + 1;
        }

        st.site = &t_emlrtRSI;
        mpower(&st, M1, Xsum);
        st.site = &t_emlrtRSI;
        i11 = b->size[0] * b->size[1];
        b->size[0] = 4;
        b->size[1] = i10 - i9;
        emxEnsureCapacity(&st, (emxArray__common *)b, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = i10 - i9;
        for (i11 = 0; i11 < loop_ub; i11++) {
          for (i13 = 0; i13 < 4; i13++) {
            b->data[i13 + b->size[0] * i11] = X->data[i13 + X->size[0] * ((i9 +
              i11) - 1)];
          }
        }

        unnamed_idx_0 = i10 - i9;
        unnamed_idx_1 = (uint32_T)(i10 - i9);
        i11 = r0->size[0] * r0->size[1];
        r0->size[0] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        i11 = r0->size[0] * r0->size[1];
        r0->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i11 = 0; i11 < loop_ub; i11++) {
          r0->data[i11] = 0.0;
        }

        b_st.site = &rc_emlrtRSI;
        c_st.site = &sc_emlrtRSI;
        i11 = b_C->size[0] * b_C->size[1];
        b_C->size[0] = 4;
        emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        i11 = b_C->size[0] * b_C->size[1];
        b_C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i11 = 0; i11 < loop_ub; i11++) {
          b_C->data[i11] = 0.0;
        }

        if (i10 - i9 < 1) {
        } else {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)4;
          n_t = (ptrdiff_t)(i10 - i9);
          k_t = (ptrdiff_t)4;
          lda_t = (ptrdiff_t)4;
          ldb_t = (ptrdiff_t)4;
          ldc_t = (ptrdiff_t)4;
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xsum[0], &lda_t,
                &b->data[0], &ldb_t, &beta1, &b_C->data[0], &ldc_t);
        }

        st.site = &t_emlrtRSI;
        twistlog(&st, b_C, M1X_logm);
        if (k1 > (int32_T)k2) {
          i9 = 1;
          i10 = 1;
        } else {
          i9 = X->size[1];
          if (k1 < i9) {
            i9 = k1;
          } else {
            i9 = emlrtDynamicBoundsCheckR2012b(k1, 1, i9, &c_emlrtBCI, sp);
          }

          i10 = X->size[1];
          i11 = (int32_T)k2;
          if ((i11 >= 1) && (i11 < i10)) {
            i14 = i11;
          } else {
            i14 = emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &c_emlrtBCI, sp);
          }

          i10 = i14 + 1;
        }

        st.site = &u_emlrtRSI;
        mpower(&st, M2, Xsum);
        st.site = &u_emlrtRSI;
        i11 = b->size[0] * b->size[1];
        b->size[0] = 4;
        b->size[1] = i10 - i9;
        emxEnsureCapacity(&st, (emxArray__common *)b, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = i10 - i9;
        for (i11 = 0; i11 < loop_ub; i11++) {
          for (i13 = 0; i13 < 4; i13++) {
            b->data[i13 + b->size[0] * i11] = X->data[i13 + X->size[0] * ((i9 +
              i11) - 1)];
          }
        }

        unnamed_idx_0 = i10 - i9;
        unnamed_idx_1 = (uint32_T)(i10 - i9);
        i11 = r0->size[0] * r0->size[1];
        r0->size[0] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        i11 = r0->size[0] * r0->size[1];
        r0->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i11 = 0; i11 < loop_ub; i11++) {
          r0->data[i11] = 0.0;
        }

        b_st.site = &rc_emlrtRSI;
        c_st.site = &sc_emlrtRSI;
        i11 = b_C->size[0] * b_C->size[1];
        b_C->size[0] = 4;
        emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        i11 = b_C->size[0] * b_C->size[1];
        b_C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i11, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i11 = 0; i11 < loop_ub; i11++) {
          b_C->data[i11] = 0.0;
        }

        if (i10 - i9 < 1) {
        } else {
          alpha1 = 1.0;
          beta1 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)4;
          n_t = (ptrdiff_t)(i10 - i9);
          k_t = (ptrdiff_t)4;
          lda_t = (ptrdiff_t)4;
          ldb_t = (ptrdiff_t)4;
          ldc_t = (ptrdiff_t)4;
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xsum[0], &lda_t,
                &b->data[0], &ldb_t, &beta1, &b_C->data[0], &ldc_t);
        }

        st.site = &u_emlrtRSI;
        twistlog(&st, b_C, Xsum);
        for (i9 = 0; i9 < 16; i9++) {
          M1sum[i9] += M1X_logm[i9];
          M2sum[i9] += Xsum[i9];
        }

        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      st.site = &v_emlrtRSI;
      a = b_norm(&st, M1sum);
      C1 = a * a;
      st.site = &w_emlrtRSI;
      a = b_norm(&st, M2sum);
      C2 = a * a;
      if (C1 <= C2) {
        C = C1;
        memcpy(&M[0], &M1[0], sizeof(real_T) << 4);
      } else {
        C = C2;
        memcpy(&M[0], &M2[0], sizeof(real_T) << 4);
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    count++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  memset(&Sig[0], 0, 36U * sizeof(real_T));
  d0 = (real_T)X->size[1] / 4.0;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)d0,
    &g_emlrtRTEI, sp);
  i = 0;
  emxInit_real_T(sp, &c_C, 2, &emlrtRTEI, true);
  while (i <= (int32_T)d0 - 1) {
    i1 = (i << 2) + 1;
    i2 = (uint32_T)(1 + i) << 2;
    if ((uint32_T)i1 > i2) {
      i9 = 1;
      i10 = 1;
    } else {
      i9 = X->size[1];
      if (i1 < i9) {
        i9 = i1;
      } else {
        i9 = emlrtDynamicBoundsCheckR2012b(i1, 1, i9, &d_emlrtBCI, sp);
      }

      i10 = X->size[1];
      i11 = (int32_T)i2;
      if ((i11 >= 1) && (i11 < i10)) {
        i15 = i11;
      } else {
        i15 = emlrtDynamicBoundsCheckR2012b(i11, 1, i10, &d_emlrtBCI, sp);
      }

      i10 = i15 + 1;
    }

    if (i1 > (int32_T)i2) {
      i11 = 1;
      i13 = 1;
    } else {
      i11 = X->size[1];
      if (i1 < i11) {
        i11 = i1;
      } else {
        i11 = emlrtDynamicBoundsCheckR2012b(i1, 1, i11, &e_emlrtBCI, sp);
      }

      i13 = X->size[1];
      i16 = (int32_T)i2;
      if ((i16 >= 1) && (i16 < i13)) {
        i17 = i16;
      } else {
        i17 = emlrtDynamicBoundsCheckR2012b(i16, 1, i13, &e_emlrtBCI, sp);
      }

      i13 = i17 + 1;
    }

    st.site = &x_emlrtRSI;
    mpower(&st, M, Xsum);
    st.site = &x_emlrtRSI;
    i16 = b->size[0] * b->size[1];
    b->size[0] = 4;
    b->size[1] = i10 - i9;
    emxEnsureCapacity(&st, (emxArray__common *)b, i16, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = i10 - i9;
    for (i16 = 0; i16 < loop_ub; i16++) {
      for (i18 = 0; i18 < 4; i18++) {
        b->data[i18 + b->size[0] * i16] = X->data[i18 + X->size[0] * ((i9 + i16)
          - 1)];
      }
    }

    unnamed_idx_0 = i10 - i9;
    unnamed_idx_1 = (uint32_T)(i10 - i9);
    i16 = r0->size[0] * r0->size[1];
    r0->size[0] = 4;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i16, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i16 = r0->size[0] * r0->size[1];
    r0->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i16, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = unnamed_idx_0 << 2;
    for (i16 = 0; i16 < loop_ub; i16++) {
      r0->data[i16] = 0.0;
    }

    b_st.site = &rc_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    i16 = b_C->size[0] * b_C->size[1];
    b_C->size[0] = 4;
    emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i16, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    i16 = b_C->size[0] * b_C->size[1];
    b_C->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i16, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = unnamed_idx_0 << 2;
    for (i16 = 0; i16 < loop_ub; i16++) {
      b_C->data[i16] = 0.0;
    }

    if (i10 - i9 < 1) {
    } else {
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)4;
      n_t = (ptrdiff_t)(i10 - i9);
      k_t = (ptrdiff_t)4;
      lda_t = (ptrdiff_t)4;
      ldb_t = (ptrdiff_t)4;
      ldc_t = (ptrdiff_t)4;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xsum[0], &lda_t,
            &b->data[0], &ldb_t, &beta1, &b_C->data[0], &ldc_t);
    }

    st.site = &x_emlrtRSI;
    mpower(&st, M, Xsum);
    st.site = &x_emlrtRSI;
    i9 = b->size[0] * b->size[1];
    b->size[0] = 4;
    b->size[1] = i13 - i11;
    emxEnsureCapacity(&st, (emxArray__common *)b, i9, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = i13 - i11;
    for (i9 = 0; i9 < loop_ub; i9++) {
      for (i10 = 0; i10 < 4; i10++) {
        b->data[i10 + b->size[0] * i9] = X->data[i10 + X->size[0] * ((i11 + i9)
          - 1)];
      }
    }

    unnamed_idx_0 = i13 - i11;
    unnamed_idx_1 = (uint32_T)(i13 - i11);
    i9 = r0->size[0] * r0->size[1];
    r0->size[0] = 4;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i9, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i9 = r0->size[0] * r0->size[1];
    r0->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i9, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = unnamed_idx_0 << 2;
    for (i9 = 0; i9 < loop_ub; i9++) {
      r0->data[i9] = 0.0;
    }

    b_st.site = &rc_emlrtRSI;
    c_st.site = &sc_emlrtRSI;
    i9 = c_C->size[0] * c_C->size[1];
    c_C->size[0] = 4;
    emxEnsureCapacity(&c_st, (emxArray__common *)c_C, i9, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i9 = c_C->size[0] * c_C->size[1];
    c_C->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(&c_st, (emxArray__common *)c_C, i9, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = unnamed_idx_0 << 2;
    for (i9 = 0; i9 < loop_ub; i9++) {
      c_C->data[i9] = 0.0;
    }

    if (i13 - i11 < 1) {
    } else {
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)4;
      n_t = (ptrdiff_t)(i13 - i11);
      k_t = (ptrdiff_t)4;
      lda_t = (ptrdiff_t)4;
      ldb_t = (ptrdiff_t)4;
      ldc_t = (ptrdiff_t)4;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xsum[0], &lda_t,
            &b->data[0], &ldb_t, &beta1, &c_C->data[0], &ldc_t);
    }

    st.site = &x_emlrtRSI;
    twistlog(&st, b_C, Xsum);

    /* Function to vectorize or hat an element of se(3) */
    /* files needed: */
    /* none */
    /* If input is skew-sym change to vector */
    st.site = &x_emlrtRSI;
    twistlog(&st, c_C, M1sum);

    /* Function to vectorize or hat an element of se(3) */
    /* files needed: */
    /* none */
    /* If input is skew-sym change to vector */
    b_M1sum[0] = -M1sum[9];
    b_M1sum[1] = M1sum[8];
    b_M1sum[2] = -M1sum[4];
    b_M1sum[3] = M1sum[12];
    b_M1sum[4] = M1sum[13];
    b_M1sum[5] = M1sum[14];
    b_Xsum[0] = -Xsum[9];
    b_Xsum[1] = Xsum[8];
    b_Xsum[2] = -Xsum[4];
    b_Xsum[3] = Xsum[12];
    b_Xsum[4] = Xsum[13];
    b_Xsum[5] = Xsum[14];
    for (i9 = 0; i9 < 6; i9++) {
      for (i10 = 0; i10 < 6; i10++) {
        Sig[i9 + 6 * i10] += b_Xsum[i9] * b_M1sum[i10];
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&r0);
  emxFree_real_T(&b);
  emxFree_real_T(&c_C);
  emxFree_real_T(&b_C);
  y = 1.0 / (real_T)X->size[1] / 4.0;
  for (i9 = 0; i9 < 36; i9++) {
    Sig[i9] *= y;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (distibutionPropsMex.c) */
