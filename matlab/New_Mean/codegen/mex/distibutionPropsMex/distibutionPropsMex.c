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
#include "distibutionPropsMex.h"
#include "distibutionPropsMex_emxutil.h"
#include "twistlog.h"
#include "mpower.h"
#include "norm.h"
#include "expm.h"
#include "distibutionPropsMex_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 23, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo b_emlrtRSI = { 27, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo c_emlrtRSI = { 50, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo d_emlrtRSI = { 51, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo e_emlrtRSI = { 53, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo f_emlrtRSI = { 54, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo g_emlrtRSI = { 57, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo h_emlrtRSI = { 58, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo i_emlrtRSI = { 73, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo j_emlrtRSI = { 74, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo k_emlrtRSI = { 82, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo l_emlrtRSI = { 83, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo m_emlrtRSI = { 105, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRSInfo dc_emlrtRSI = { 68, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

static emlrtRSInfo ec_emlrtRSI = { 54, "eml_xgemm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 23, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 19, 1, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 23, 27, "X", "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

static emlrtRTEInfo d_emlrtRTEI = { 69, 9, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtBCInfo b_emlrtBCI = { -1, -1, 73, 44, "X", "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 74, 44, "X", "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

static emlrtRTEInfo e_emlrtRTEI = { 101, 1, "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 105, 43, "X", "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 105, 80, "X", "distibutionPropsMex",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/distibutionPropsMex.m",
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
  int32_T i0;
  int32_T i1;
  int32_T c_j1;
  int32_T i2;
  int32_T loop_ub;
  real_T M1sum[16];
  real_T y;
  real_T b_y[16];
  real_T C_old;
  real_T C;
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
  int32_T i3;
  int32_T i4;
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
  int32_T i5;
  real_T C1;
  real_T C2;
  int32_T i;
  emxArray_real_T *c_C;
  int32_T b_i1;
  uint32_T b_i2;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
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
    &c_emlrtRTEI, sp);
  j = 0;
  emxInit_real_T(sp, &b_X, 2, &emlrtRTEI, true);
  while (j <= (int32_T)n - 1) {
    b_j1 = (j << 2) + 1;
    j2 = (uint32_T)(1 + j) << 2;
    if ((uint32_T)b_j1 > j2) {
      i0 = 0;
      i1 = 0;
    } else {
      i0 = X->size[1];
      if (b_j1 < i0) {
        c_j1 = b_j1;
      } else {
        c_j1 = emlrtDynamicBoundsCheckR2012b(b_j1, 1, i0, &emlrtBCI, sp);
      }

      i0 = c_j1 - 1;
      i1 = X->size[1];
      i2 = (int32_T)j2;
      if ((i2 >= 1) && (i2 < i1)) {
        i1 = i2;
      } else {
        i1 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &emlrtBCI, sp);
      }
    }

    i2 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 4;
    b_X->size[1] = i1 - i0;
    emxEnsureCapacity(sp, (emxArray__common *)b_X, i2, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = i1 - i0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 4; i2++) {
        b_X->data[i2 + b_X->size[0] * i1] = X->data[i2 + X->size[0] * (i0 + i1)];
      }
    }

    st.site = &emlrtRSI;
    twistlog(&st, b_X, M1sum);
    for (i0 = 0; i0 < 16; i0++) {
      Xsum[i0] += M1sum[i0];
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_X);
  y = 1.0 / n;
  for (i0 = 0; i0 < 16; i0++) {
    b_y[i0] = y * Xsum[i0];
  }

  st.site = &b_emlrtRSI;
  expm(&st, b_y, M);
  C_old = rtInf;
  C = 0.0;

  /*  The six Lie algebra elements for SE(3) */
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

  count = 0;
  emxInit_real_T(sp, &b_C, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);
  while ((muDoubleScalarAbs(C - C_old) > 0.05) && (count < 10)) {
    C_old = C;
    j = 0;
    while (j < 6) {
      if (C_old > 20.0) {
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            b_y[i1 + (i0 << 2)] = 0.02 * (real_T)E[(i1 + (i0 << 2)) + (j << 4)];
          }
        }

        st.site = &c_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            M1[i0 + (i1 << 2)] = 0.0;
            for (i2 = 0; i2 < 4; i2++) {
              M1[i0 + (i1 << 2)] += M[i0 + (i2 << 2)] * Xsum[i2 + (i1 << 2)];
            }

            b_y[i1 + (i0 << 2)] = -0.02 * (real_T)E[(i1 + (i0 << 2)) + (j << 4)];
          }
        }

        st.site = &d_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            M2[i0 + (i1 << 2)] = 0.0;
            for (i2 = 0; i2 < 4; i2++) {
              M2[i0 + (i1 << 2)] += M[i0 + (i2 << 2)] * Xsum[i2 + (i1 << 2)];
            }
          }
        }
      } else if (C_old > 1.0) {
        a = 0.001 * C_old;
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            b_y[i1 + (i0 << 2)] = a * (real_T)E[(i1 + (i0 << 2)) + (j << 4)];
          }
        }

        st.site = &e_emlrtRSI;
        expm(&st, b_y, Xsum);
        a = -0.001 * C_old;
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            M1[i0 + (i1 << 2)] = 0.0;
            for (i2 = 0; i2 < 4; i2++) {
              M1[i0 + (i1 << 2)] += M[i0 + (i2 << 2)] * Xsum[i2 + (i1 << 2)];
            }

            b_y[i1 + (i0 << 2)] = a * (real_T)E[(i1 + (i0 << 2)) + (j << 4)];
          }
        }

        st.site = &f_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            M2[i0 + (i1 << 2)] = 0.0;
            for (i2 = 0; i2 < 4; i2++) {
              M2[i0 + (i1 << 2)] += M[i0 + (i2 << 2)] * Xsum[i2 + (i1 << 2)];
            }
          }
        }
      } else {
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            b_y[i1 + (i0 << 2)] = 0.001 * (real_T)E[(i1 + (i0 << 2)) + (j << 4)];
          }
        }

        st.site = &g_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            M1[i0 + (i1 << 2)] = 0.0;
            for (i2 = 0; i2 < 4; i2++) {
              M1[i0 + (i1 << 2)] += M[i0 + (i2 << 2)] * Xsum[i2 + (i1 << 2)];
            }

            b_y[i1 + (i0 << 2)] = -0.001 * (real_T)E[(i1 + (i0 << 2)) + (j << 4)];
          }
        }

        st.site = &h_emlrtRSI;
        expm(&st, b_y, Xsum);
        for (i0 = 0; i0 < 4; i0++) {
          for (i1 = 0; i1 < 4; i1++) {
            M2[i0 + (i1 << 2)] = 0.0;
            for (i2 = 0; i2 < 4; i2++) {
              M2[i0 + (i1 << 2)] += M[i0 + (i2 << 2)] * Xsum[i2 + (i1 << 2)];
            }
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        M1sum[i0] = 0.0;
        M2sum[i0] = 0.0;
      }

      d0 = (real_T)X->size[1] / 4.0;
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, d0, mxDOUBLE_CLASS, (int32_T)d0,
        &d_emlrtRTEI, sp);
      k = 0;
      while (k <= (int32_T)d0 - 1) {
        k1 = (k << 2) + 1;
        k2 = (uint32_T)(1 + k) << 2;
        if ((uint32_T)k1 > k2) {
          i0 = 1;
          i1 = 1;
        } else {
          i0 = X->size[1];
          if (k1 < i0) {
            i0 = k1;
          } else {
            i0 = emlrtDynamicBoundsCheckR2012b(k1, 1, i0, &b_emlrtBCI, sp);
          }

          i1 = X->size[1];
          i2 = (int32_T)k2;
          if ((i2 >= 1) && (i2 < i1)) {
            i3 = i2;
          } else {
            i3 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &b_emlrtBCI, sp);
          }

          i1 = i3 + 1;
        }

        st.site = &i_emlrtRSI;
        mpower(&st, M1, Xsum);
        st.site = &i_emlrtRSI;
        i2 = b->size[0] * b->size[1];
        b->size[0] = 4;
        b->size[1] = i1 - i0;
        emxEnsureCapacity(&st, (emxArray__common *)b, i2, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = i1 - i0;
        for (i2 = 0; i2 < loop_ub; i2++) {
          for (i4 = 0; i4 < 4; i4++) {
            b->data[i4 + b->size[0] * i2] = X->data[i4 + X->size[0] * ((i0 + i2)
              - 1)];
          }
        }

        unnamed_idx_0 = i1 - i0;
        unnamed_idx_1 = (uint32_T)(i1 - i0);
        i2 = r0->size[0] * r0->size[1];
        r0->size[0] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i2, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        i2 = r0->size[0] * r0->size[1];
        r0->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i2, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i2 = 0; i2 < loop_ub; i2++) {
          r0->data[i2] = 0.0;
        }

        b_st.site = &dc_emlrtRSI;
        c_st.site = &ec_emlrtRSI;
        i2 = b_C->size[0] * b_C->size[1];
        b_C->size[0] = 4;
        emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i2, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        i2 = b_C->size[0] * b_C->size[1];
        b_C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i2, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_C->data[i2] = 0.0;
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
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xsum[0], &lda_t,
                &b->data[0], &ldb_t, &beta1, &b_C->data[0], &ldc_t);
        }

        st.site = &i_emlrtRSI;
        twistlog(&st, b_C, M1X_logm);
        if (k1 > (int32_T)k2) {
          i0 = 1;
          i1 = 1;
        } else {
          i0 = X->size[1];
          if (k1 < i0) {
            i0 = k1;
          } else {
            i0 = emlrtDynamicBoundsCheckR2012b(k1, 1, i0, &c_emlrtBCI, sp);
          }

          i1 = X->size[1];
          i2 = (int32_T)k2;
          if ((i2 >= 1) && (i2 < i1)) {
            i5 = i2;
          } else {
            i5 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &c_emlrtBCI, sp);
          }

          i1 = i5 + 1;
        }

        st.site = &j_emlrtRSI;
        mpower(&st, M2, Xsum);
        st.site = &j_emlrtRSI;
        i2 = b->size[0] * b->size[1];
        b->size[0] = 4;
        b->size[1] = i1 - i0;
        emxEnsureCapacity(&st, (emxArray__common *)b, i2, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = i1 - i0;
        for (i2 = 0; i2 < loop_ub; i2++) {
          for (i4 = 0; i4 < 4; i4++) {
            b->data[i4 + b->size[0] * i2] = X->data[i4 + X->size[0] * ((i0 + i2)
              - 1)];
          }
        }

        unnamed_idx_0 = i1 - i0;
        unnamed_idx_1 = (uint32_T)(i1 - i0);
        i2 = r0->size[0] * r0->size[1];
        r0->size[0] = 4;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i2, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        i2 = r0->size[0] * r0->size[1];
        r0->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&st, (emxArray__common *)r0, i2, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i2 = 0; i2 < loop_ub; i2++) {
          r0->data[i2] = 0.0;
        }

        b_st.site = &dc_emlrtRSI;
        c_st.site = &ec_emlrtRSI;
        i2 = b_C->size[0] * b_C->size[1];
        b_C->size[0] = 4;
        emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i2, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        i2 = b_C->size[0] * b_C->size[1];
        b_C->size[1] = (int32_T)unnamed_idx_1;
        emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i2, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = unnamed_idx_0 << 2;
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_C->data[i2] = 0.0;
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
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xsum[0], &lda_t,
                &b->data[0], &ldb_t, &beta1, &b_C->data[0], &ldc_t);
        }

        st.site = &j_emlrtRSI;
        twistlog(&st, b_C, Xsum);
        for (i0 = 0; i0 < 16; i0++) {
          M1sum[i0] += M1X_logm[i0];
          M2sum[i0] += Xsum[i0];
        }

        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      st.site = &k_emlrtRSI;
      a = b_norm(&st, M1sum);
      C1 = a * a;
      st.site = &l_emlrtRSI;
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
    &e_emlrtRTEI, sp);
  i = 0;
  emxInit_real_T(sp, &c_C, 2, &emlrtRTEI, true);
  while (i <= (int32_T)d0 - 1) {
    b_i1 = (i << 2) + 1;
    b_i2 = (uint32_T)(1 + i) << 2;
    if ((uint32_T)b_i1 > b_i2) {
      i0 = 1;
      i1 = 1;
    } else {
      i0 = X->size[1];
      if (b_i1 < i0) {
        i0 = b_i1;
      } else {
        i0 = emlrtDynamicBoundsCheckR2012b(b_i1, 1, i0, &d_emlrtBCI, sp);
      }

      i1 = X->size[1];
      i2 = (int32_T)b_i2;
      if ((i2 >= 1) && (i2 < i1)) {
        i6 = i2;
      } else {
        i6 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &d_emlrtBCI, sp);
      }

      i1 = i6 + 1;
    }

    if (b_i1 > (int32_T)b_i2) {
      i2 = 1;
      i4 = 1;
    } else {
      i2 = X->size[1];
      if (b_i1 < i2) {
        i2 = b_i1;
      } else {
        i2 = emlrtDynamicBoundsCheckR2012b(b_i1, 1, i2, &e_emlrtBCI, sp);
      }

      i4 = X->size[1];
      i7 = (int32_T)b_i2;
      if ((i7 >= 1) && (i7 < i4)) {
        i8 = i7;
      } else {
        i8 = emlrtDynamicBoundsCheckR2012b(i7, 1, i4, &e_emlrtBCI, sp);
      }

      i4 = i8 + 1;
    }

    st.site = &m_emlrtRSI;
    mpower(&st, M, Xsum);
    st.site = &m_emlrtRSI;
    i7 = b->size[0] * b->size[1];
    b->size[0] = 4;
    b->size[1] = i1 - i0;
    emxEnsureCapacity(&st, (emxArray__common *)b, i7, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = i1 - i0;
    for (i7 = 0; i7 < loop_ub; i7++) {
      for (i9 = 0; i9 < 4; i9++) {
        b->data[i9 + b->size[0] * i7] = X->data[i9 + X->size[0] * ((i0 + i7) - 1)];
      }
    }

    unnamed_idx_0 = i1 - i0;
    unnamed_idx_1 = (uint32_T)(i1 - i0);
    i7 = r0->size[0] * r0->size[1];
    r0->size[0] = 4;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i7, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i7 = r0->size[0] * r0->size[1];
    r0->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i7, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = unnamed_idx_0 << 2;
    for (i7 = 0; i7 < loop_ub; i7++) {
      r0->data[i7] = 0.0;
    }

    b_st.site = &dc_emlrtRSI;
    c_st.site = &ec_emlrtRSI;
    i7 = b_C->size[0] * b_C->size[1];
    b_C->size[0] = 4;
    emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i7, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i7 = b_C->size[0] * b_C->size[1];
    b_C->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(&c_st, (emxArray__common *)b_C, i7, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = unnamed_idx_0 << 2;
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_C->data[i7] = 0.0;
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
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xsum[0], &lda_t,
            &b->data[0], &ldb_t, &beta1, &b_C->data[0], &ldc_t);
    }

    st.site = &m_emlrtRSI;
    mpower(&st, M, Xsum);
    st.site = &m_emlrtRSI;
    i0 = b->size[0] * b->size[1];
    b->size[0] = 4;
    b->size[1] = i4 - i2;
    emxEnsureCapacity(&st, (emxArray__common *)b, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = i4 - i2;
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < 4; i1++) {
        b->data[i1 + b->size[0] * i0] = X->data[i1 + X->size[0] * ((i2 + i0) - 1)];
      }
    }

    unnamed_idx_0 = i4 - i2;
    unnamed_idx_1 = (uint32_T)(i4 - i2);
    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = 4;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i0 = r0->size[0] * r0->size[1];
    r0->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(&st, (emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = unnamed_idx_0 << 2;
    for (i0 = 0; i0 < loop_ub; i0++) {
      r0->data[i0] = 0.0;
    }

    b_st.site = &dc_emlrtRSI;
    c_st.site = &ec_emlrtRSI;
    i0 = c_C->size[0] * c_C->size[1];
    c_C->size[0] = 4;
    emxEnsureCapacity(&c_st, (emxArray__common *)c_C, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i0 = c_C->size[0] * c_C->size[1];
    c_C->size[1] = (int32_T)unnamed_idx_1;
    emxEnsureCapacity(&c_st, (emxArray__common *)c_C, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = unnamed_idx_0 << 2;
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_C->data[i0] = 0.0;
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
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xsum[0], &lda_t,
            &b->data[0], &ldb_t, &beta1, &c_C->data[0], &ldc_t);
    }

    st.site = &m_emlrtRSI;
    twistlog(&st, b_C, Xsum);

    /* Function to vectorize or hat an element of se(3) */
    /* files needed: */
    /* none */
    /* If input is skew-sym change to vector */
    st.site = &m_emlrtRSI;
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
    for (i0 = 0; i0 < 6; i0++) {
      for (i1 = 0; i1 < 6; i1++) {
        Sig[i0 + 6 * i1] += b_Xsum[i0] * b_M1sum[i1];
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
  for (i0 = 0; i0 < 36; i0++) {
    Sig[i0] *= y;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (distibutionPropsMex.c) */
