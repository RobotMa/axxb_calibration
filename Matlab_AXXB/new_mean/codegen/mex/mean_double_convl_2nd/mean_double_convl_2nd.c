/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_double_convl_2nd.c
 *
 * Code generation for function 'mean_double_convl_2nd'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "mean_Taylor_2nd.h"
#include "mean_double_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 21, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo b_emlrtRSI = { 23, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo c_emlrtRSI = { 25, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo d_emlrtRSI = { 31, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo e_emlrtRSI = { 88, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo f_emlrtRSI = { 89, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo g_emlrtRSI = { 100, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo h_emlrtRSI = { 101, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo i_emlrtRSI = { 113, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo j_emlrtRSI = { 114, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtRSInfo k_emlrtRSI = { 149, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtECInfo emlrtECI = { 2, 101, 34, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtECInfo b_emlrtECI = { 2, 100, 34, "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m"
};

static emlrtBCInfo emlrtBCI = { 1, 6, 88, 46, "E", "mean_double_convl_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_double_convl_2nd.m",
  0 };

static emlrtRTEInfo f_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

/* Function Definitions */
void dynamic_size_checks(const emlrtStack *sp, const int32_T a_size[2])
{
  if (!(a_size[1] == 4)) {
    emlrtErrorWithMessageIdR2012b(sp, &f_emlrtRTEI, "Coder:MATLAB:innerdim", 0);
  }
}

void eml_xgemm(int32_T n, int32_T k, const real_T A_data[], const real_T B_data[],
               int32_T ldb, real_T C_data[])
{
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
  if ((n < 1) || (k < 1)) {
  } else {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB = 'N';
    TRANSA = 'N';
    m_t = (ptrdiff_t)4;
    n_t = (ptrdiff_t)n;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)4;
    ldb_t = (ptrdiff_t)ldb;
    ldc_t = (ptrdiff_t)4;
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &A_data[0], &lda_t,
          &B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

void mean_double_convl_2nd(const emlrtStack *sp, const real_T X1[800], const
  real_T X2[800], const real_T X3[800], int8_T s1, int8_T s2, int8_T s3, int16_T
  n_search, real_T diff, real_T M123_f[16])
{
  real_T M1[16];
  real_T M2[16];
  real_T unusedExpr[16];
  int32_T i0;
  int32_T i1;
  real_T M123[16];
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
  real_T CA1;
  real_T CA2;
  boolean_T exitg1;
  real_T eps;
  int32_T j;
  int32_T b_j;
  real_T a;
  real_T b_a[16];
  real_T M123_r[16];
  real_T M123_l[16];
  int32_T i;
  int32_T k;
  int32_T l;
  int32_T X1_i_size[2];
  int32_T loop_ub;
  int32_T i3;
  real_T X1_i_data[800];
  int32_T X2_k_size_idx_1;
  int32_T i4;
  int32_T i5;
  real_T X2_k_data[800];
  int32_T X3_j_size_idx_1;
  int32_T i6;
  int32_T i7;
  real_T X3_j_data[800];
  int32_T a_size[2];
  real_T a_data[800];
  int32_T i8;
  int32_T b_a_size[2];
  real_T b_a_data[800];
  int32_T tmp_size[2];
  real_T tmp_data[16];
  int32_T unnamed_idx_0;
  int32_T c_a[2];
  int32_T b_i;
  real_T b_M1;
  real_T b_M2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  This fucntion calculate the 2nd order approximation of the mean of the */
  /*  convolution of two probability density functions on SE(3). */
  /*  Input: M1_hat and M2_hat denotes the mean before orthogonalization */
  /*  Future Work: To be determined which is the better M12 */
  st.site = &emlrtRSI;
  mean_Taylor_2nd(&st, X1, s1, n_search, M1);
  st.site = &b_emlrtRSI;
  mean_Taylor_2nd(&st, X2, s2, n_search, M2);
  st.site = &c_emlrtRSI;
  mean_Taylor_2nd(&st, X3, s3, n_search, unusedExpr);

  /*  This initial guess is not good */
  /*  M123 = M1*M2*M3; % Initial guess of M12 */
  /*  Another possible way to calculate M123 */
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      M123[i0 + (i1 << 2)] = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        M123[i0 + (i1 << 2)] += M1[i0 + (i2 << 2)] * M2[i2 + (i1 << 2)];
      }
    }
  }

  st.site = &d_emlrtRSI;
  b_mrdivide(&st, M123, M1);
  memcpy(&M123_f[0], &M123[0], sizeof(real_T) << 4);

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

  /*  diff = 10^-12; */
  step = 1.0;
  n_step = 0.0;
  if (s1 == 0) {
    m = 4;
  } else {
    m = (s1 == 1);
  }

  CA1 = 0.0;
  CA2 = 0.0;
  exitg1 = false;
  while ((!exitg1) && (muDoubleScalarAbs(CA) > diff)) {
    /*  Adjust the step length */
    if (muDoubleScalarAbs(CA) > 100.0) {
      eps = 1.0;
    } else if ((muDoubleScalarAbs(CA) > 1.0) && (muDoubleScalarAbs(CA) < 100.0))
    {
      eps = 0.1;
    } else if ((muDoubleScalarAbs(CA) > 0.01) && (muDoubleScalarAbs(CA) < 1.0))
    {
      eps = 0.001;
    } else if (muDoubleScalarAbs(CA) < 0.01) {
      eps = 0.0001;
    } else if (muDoubleScalarAbs(CA) < 1.0E-8) {
      eps = 1.0E-5;
    } else {
      eps = 0.001;
    }

    j = -1;
    while (j + 1 <= 6 - m) {
      b_j = m + j;

      /*  disp(step) */
      a = step * eps;
      i0 = b_j + 1;
      emlrtDynamicBoundsCheckR2012b(i0, 1, 6, &emlrtBCI, sp);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          b_a[i1 + (i0 << 2)] = a * (real_T)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      st.site = &e_emlrtRSI;
      expm(&st, b_a, M1);
      a = -step * eps;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          M123_r[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            M123_r[i0 + (i1 << 2)] += M123_f[i0 + (i2 << 2)] * M1[i2 + (i1 << 2)];
          }

          b_a[i1 + (i0 << 2)] = a * (real_T)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      st.site = &f_emlrtRSI;
      expm(&st, b_a, M1);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          M123_l[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            M123_l[i0 + (i1 << 2)] += M123_f[i0 + (i2 << 2)] * M1[i2 + (i1 << 2)];
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        M1[i0] = 0.0;
        M2[i0] = 0.0;
      }

      i = 0;
      while (i < 50) {
        k = 0;
        while (k < 50) {
          l = 0;
          while (l < 50) {
            i0 = (i << 2) + 1;
            i1 = (1 + i) << 2;
            if (i0 > i1) {
              i0 = 0;
              i1 = 0;
            } else {
              i0--;
            }

            X1_i_size[0] = 4;
            X1_i_size[1] = i1 - i0;
            loop_ub = i1 - i0;
            for (i2 = 0; i2 < loop_ub; i2++) {
              for (i3 = 0; i3 < 4; i3++) {
                X1_i_data[i3 + (i2 << 2)] = X1[i3 + ((i0 + i2) << 2)];
              }
            }

            i2 = (k << 2) + 1;
            i3 = (1 + k) << 2;
            if (i2 > i3) {
              i2 = 0;
              i3 = 0;
            } else {
              i2--;
            }

            X2_k_size_idx_1 = i3 - i2;
            loop_ub = i3 - i2;
            for (i4 = 0; i4 < loop_ub; i4++) {
              for (i5 = 0; i5 < 4; i5++) {
                X2_k_data[i5 + (i4 << 2)] = X2[i5 + ((i2 + i4) << 2)];
              }
            }

            i4 = (l << 2) + 1;
            i5 = (1 + l) << 2;
            if (i4 > i5) {
              i4 = 0;
              i5 = 0;
            } else {
              i4--;
            }

            X3_j_size_idx_1 = i5 - i4;
            loop_ub = i5 - i4;
            for (i6 = 0; i6 < loop_ub; i6++) {
              for (i7 = 0; i7 < 4; i7++) {
                X3_j_data[i7 + (i6 << 2)] = X2[i7 + ((i4 + i6) << 2)];
              }
            }

            st.site = &g_emlrtRSI;
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, X1_i_size);
            if (i1 - i0 == 1) {
              a_size[0] = 4;
              a_size[1] = X2_k_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X2_k_size_idx_1; i7++) {
                  a_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    a_data[i6 + (i7 << 2)] += X1_i_data[i6 + (i8 << 2)] *
                      X2_k_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              a_size[0] = 4;
              a_size[1] = (uint8_T)(i3 - i2);
              loop_ub = (uint8_T)(i3 - i2) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                a_data[i6] = 0.0;
              }

              eml_xgemm(i3 - i2, i1 - i0, X1_i_data, X2_k_data, i1 - i0, a_data);
            }

            st.site = &g_emlrtRSI;
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, a_size);
            if (a_size[1] == 1) {
              b_a_size[0] = 4;
              b_a_size[1] = X3_j_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X3_j_size_idx_1; i7++) {
                  b_a_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    b_a_data[i6 + (i7 << 2)] += a_data[i6 + (i8 << 2)] *
                      X3_j_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              b_a_size[0] = 4;
              b_a_size[1] = (uint8_T)(i5 - i4);
              loop_ub = (uint8_T)(i5 - i4) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                b_a_data[i6] = 0.0;
              }

              eml_xgemm(i5 - i4, a_size[1], a_data, X3_j_data, a_size[1],
                        b_a_data);
            }

            st.site = &g_emlrtRSI;
            b_st.site = &g_emlrtRSI;
            mrdivide(&b_st, b_a_data, b_a_size, M123_r, tmp_data, tmp_size);
            a_size[0] = 4;
            a_size[1] = 4;
            memcpy(&a_data[0], &tmp_data[0], sizeof(real_T) << 4);
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, a_size);
            unnamed_idx_0 = i1 - i0;
            b_a_size[0] = 4;
            b_a_size[1] = (uint8_T)(i1 - i0);
            loop_ub = (uint8_T)unnamed_idx_0 << 2;
            for (i6 = 0; i6 < loop_ub; i6++) {
              b_a_data[i6] = 0.0;
            }

            eml_xgemm(i1 - i0, 4, a_data, X1_i_data, 4, b_a_data);
            st.site = &g_emlrtRSI;
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, b_a_size);
            if ((uint8_T)unnamed_idx_0 == 1) {
              a_size[0] = 4;
              a_size[1] = X2_k_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X2_k_size_idx_1; i7++) {
                  a_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    a_data[i6 + (i7 << 2)] += b_a_data[i6 + (i8 << 2)] *
                      X2_k_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              a_size[0] = 4;
              a_size[1] = (uint8_T)(i3 - i2);
              loop_ub = (uint8_T)(i3 - i2) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                a_data[i6] = 0.0;
              }

              eml_xgemm(i3 - i2, (uint8_T)unnamed_idx_0, b_a_data, X2_k_data,
                        (uint8_T)unnamed_idx_0, a_data);
            }

            st.site = &g_emlrtRSI;
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, a_size);
            if (a_size[1] == 1) {
              b_a_size[0] = 4;
              b_a_size[1] = X3_j_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X3_j_size_idx_1; i7++) {
                  b_a_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    b_a_data[i6 + (i7 << 2)] += a_data[i6 + (i8 << 2)] *
                      X3_j_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              b_a_size[0] = 4;
              b_a_size[1] = (uint8_T)(i5 - i4);
              loop_ub = (uint8_T)(i5 - i4) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                b_a_data[i6] = 0.0;
              }

              eml_xgemm(i5 - i4, a_size[1], a_data, X3_j_data, a_size[1],
                        b_a_data);
            }

            for (b_i = 0; b_i < 2; b_i++) {
              tmp_size[b_i] = 4;
              c_a[b_i] = b_a_size[b_i];
            }

            if ((4 != c_a[0]) || (4 != c_a[1])) {
              emlrtSizeEqCheckNDR2012b(tmp_size, c_a, &b_emlrtECI, sp);
            }

            for (i6 = 0; i6 < 16; i6++) {
              b_M1 = M1[i6] + b_a_data[i6];
              M1[i6] = b_M1;
            }

            st.site = &h_emlrtRSI;
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, X1_i_size);
            if (i1 - i0 == 1) {
              a_size[0] = 4;
              a_size[1] = X2_k_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X2_k_size_idx_1; i7++) {
                  a_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    a_data[i6 + (i7 << 2)] += X1_i_data[i6 + (i8 << 2)] *
                      X2_k_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              a_size[0] = 4;
              a_size[1] = (uint8_T)(i3 - i2);
              loop_ub = (uint8_T)(i3 - i2) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                a_data[i6] = 0.0;
              }

              eml_xgemm(i3 - i2, i1 - i0, X1_i_data, X2_k_data, i1 - i0, a_data);
            }

            st.site = &h_emlrtRSI;
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, a_size);
            if (a_size[1] == 1) {
              b_a_size[0] = 4;
              b_a_size[1] = X3_j_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X3_j_size_idx_1; i7++) {
                  b_a_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    b_a_data[i6 + (i7 << 2)] += a_data[i6 + (i8 << 2)] *
                      X3_j_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              b_a_size[0] = 4;
              b_a_size[1] = (uint8_T)(i5 - i4);
              loop_ub = (uint8_T)(i5 - i4) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                b_a_data[i6] = 0.0;
              }

              eml_xgemm(i5 - i4, a_size[1], a_data, X3_j_data, a_size[1],
                        b_a_data);
            }

            st.site = &h_emlrtRSI;
            b_st.site = &h_emlrtRSI;
            mrdivide(&b_st, b_a_data, b_a_size, M123_l, tmp_data, tmp_size);
            a_size[0] = 4;
            a_size[1] = 4;
            memcpy(&a_data[0], &tmp_data[0], sizeof(real_T) << 4);
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, a_size);
            unnamed_idx_0 = i1 - i0;
            b_a_size[0] = 4;
            b_a_size[1] = (uint8_T)(i1 - i0);
            loop_ub = (uint8_T)unnamed_idx_0 << 2;
            for (i6 = 0; i6 < loop_ub; i6++) {
              b_a_data[i6] = 0.0;
            }

            eml_xgemm(i1 - i0, 4, a_data, X1_i_data, 4, b_a_data);
            st.site = &h_emlrtRSI;
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, b_a_size);
            if ((uint8_T)unnamed_idx_0 == 1) {
              a_size[0] = 4;
              a_size[1] = X2_k_size_idx_1;
              for (i0 = 0; i0 < 4; i0++) {
                for (i1 = 0; i1 < X2_k_size_idx_1; i1++) {
                  a_data[i0 + (i1 << 2)] = 0.0;
                  for (i2 = 0; i2 < 4; i2++) {
                    a_data[i0 + (i1 << 2)] += b_a_data[i0 + (i2 << 2)] *
                      X2_k_data[i2 + (i1 << 2)];
                  }
                }
              }
            } else {
              a_size[0] = 4;
              a_size[1] = (uint8_T)(i3 - i2);
              loop_ub = (uint8_T)(i3 - i2) << 2;
              for (i0 = 0; i0 < loop_ub; i0++) {
                a_data[i0] = 0.0;
              }

              eml_xgemm(i3 - i2, (uint8_T)unnamed_idx_0, b_a_data, X2_k_data,
                        (uint8_T)unnamed_idx_0, a_data);
            }

            st.site = &h_emlrtRSI;
            b_st.site = &fd_emlrtRSI;
            dynamic_size_checks(&b_st, a_size);
            if (a_size[1] == 1) {
              b_a_size[0] = 4;
              b_a_size[1] = X3_j_size_idx_1;
              for (i0 = 0; i0 < 4; i0++) {
                for (i1 = 0; i1 < X3_j_size_idx_1; i1++) {
                  b_a_data[i0 + (i1 << 2)] = 0.0;
                  for (i2 = 0; i2 < 4; i2++) {
                    b_a_data[i0 + (i1 << 2)] += a_data[i0 + (i2 << 2)] *
                      X3_j_data[i2 + (i1 << 2)];
                  }
                }
              }
            } else {
              b_a_size[0] = 4;
              b_a_size[1] = (uint8_T)(i5 - i4);
              loop_ub = (uint8_T)(i5 - i4) << 2;
              for (i0 = 0; i0 < loop_ub; i0++) {
                b_a_data[i0] = 0.0;
              }

              eml_xgemm(i5 - i4, a_size[1], a_data, X3_j_data, a_size[1],
                        b_a_data);
            }

            for (b_i = 0; b_i < 2; b_i++) {
              tmp_size[b_i] = 4;
              c_a[b_i] = b_a_size[b_i];
            }

            if ((4 != c_a[0]) || (4 != c_a[1])) {
              emlrtSizeEqCheckNDR2012b(tmp_size, c_a, &emlrtECI, sp);
            }

            for (i0 = 0; i0 < 16; i0++) {
              b_M2 = M2[i0] + b_a_data[i0];
              M2[i0] = b_M2;
            }

            l++;
            if (*emlrtBreakCheckR2012bFlagVar != 0) {
              emlrtBreakCheckR2012b(sp);
            }
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

      for (i0 = 0; i0 < 16; i0++) {
        M1[i0] = (M123[i0] - 0.0001 * M1[i0]) - 0.75 * M123_r[i0];
        M2[i0] = (M123[i0] - 0.0001 * M2[i0]) - 0.75 * M123_l[i0];
      }

      if (m == 4) {
        a = norm(*(real_T (*)[3])&M1[12]);
        CA1 = a * a;
        a = norm(*(real_T (*)[3])&M2[12]);
        CA2 = a * a;
      } else if (m == 1) {
        st.site = &i_emlrtRSI;
        a = b_norm(&st, M1);
        CA1 = a * a;
        st.site = &j_emlrtRSI;
        a = b_norm(&st, M2);
        CA2 = a * a;
      } else {
        CA1 = -1.0;
        CA2 = -1.0;
      }

      if ((CA1 <= CA2) && (CA1 < CA)) {
        CA = CA1;
        memcpy(&M123_f[0], &M123_r[0], sizeof(real_T) << 4);
        step = 1.0;

        /*  fprintf('Found a descent direction along %d \n', j) */
        /*  disp(MX1cost) */
        /*  disp(CA) */
      } else if ((CA2 < CA1) && (CA2 < CA)) {
        CA = CA2;
        memcpy(&M123_f[0], &M123_l[0], sizeof(real_T) << 4);
        step = 1.0;

        /*  fprintf('Found a descent direction along -%d \n', j) */
        /*  disp(MX2cost) */
        /*  disp(CA) */
      } else {
        /*  fprintf('Not a descent direction along +/-%d \n', j) */
        if (CA > 10.0) {
          step = 1.0;
        } else {
          n_step++;
          if (n_step == (6.0 - (real_T)m) + 1.0) {
            n_step = 0.0;
            step++;
          }
        }
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    st.site = &k_emlrtRSI;
    f_fprintf(&st, CA1, CA2, CA);

    /*  fprintf('Value of the cost function is %f \n', CA2); */
    /*  fprintf('Value of the cost function is %f \n', CA); */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }

    if (step == 20.0) {
      exitg1 = true;
    }
  }
}

/* End of code generation (mean_double_convl_2nd.c) */
