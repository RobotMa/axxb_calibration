/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * batchEDSolve.c
 *
 * Code generation for function 'batchEDSolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "norm.h"
#include "eye.h"
#include "det.h"
#include "so3_vec.h"
#include "mpower.h"
#include "param_extract.h"
#include "eig.h"
#include "distibutionPropsMex.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 8, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo b_emlrtRSI = { 9, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo c_emlrtRSI = { 11, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo d_emlrtRSI = { 12, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo e_emlrtRSI = { 42, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo f_emlrtRSI = { 43, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo g_emlrtRSI = { 50, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo h_emlrtRSI = { 52, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo i_emlrtRSI = { 54, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo j_emlrtRSI = { 61, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo k_emlrtRSI = { 62, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtRSInfo hg_emlrtRSI = { 21, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

static emlrtRTEInfo c_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

static emlrtRTEInfo d_emlrtRTEI = { 98, 23, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

static emlrtECInfo emlrtECI = { 2, 64, 5, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtECInfo b_emlrtECI = { 2, 61, 47, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtECInfo c_emlrtECI = { 2, 54, 25, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtECInfo d_emlrtECI = { 2, 52, 116, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

static emlrtECInfo e_emlrtECI = { 2, 50, 99, "batchEDSolve",
  "/home/rpk/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/EDBatch_test/batchEDSolve.m"
};

/* Function Declarations */
static void eml_xgemm(int32_T m, int32_T n, const creal_T A_data[], int32_T lda,
                      const creal_T B_data[], creal_T C_data[], int32_T ldc);

/* Function Definitions */
static void eml_xgemm(int32_T m, int32_T n, const creal_T A_data[], int32_T lda,
                      const creal_T B_data[], creal_T C_data[], int32_T ldc)
{
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  static const creal_T beta1 = { 0.0, 0.0 };

  static const creal_T alpha1 = { 1.0, 0.0 };

  if ((m < 1) || (n < 1)) {
  } else {
    TRANSB = 'N';
    TRANSA = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)ldc;
    zgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, (real_T *)&alpha1, (real_T *)
          &A_data[0], &lda_t, (real_T *)&B_data[0], &ldb_t, (real_T *)&beta1,
          (real_T *)&C_data[0], &ldc_t);
  }
}

void batchEDSolve(const emlrtStack *sp, const emxArray_real_T *A, const
                  emxArray_real_T *B, creal_T X[16], real_T MeanA[16], real_T
                  MeanB[16], real_T SigA[36], real_T SigB[36])
{
  real_T b_SigA[9];
  int32_T i0;
  int32_T i1;
  creal_T unusedU0[9];
  creal_T VA[9];
  creal_T unusedU1[9];
  creal_T Rx_solved[72];
  creal_T dcv0[9];
  static const int8_T iv0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  creal_T b_VA[9];
  creal_T dcv1[9];
  int32_T i2;
  real_T unusedU2;
  real_T unusedU3;
  static const int8_T iv1[9] = { -1, 0, 0, 0, -1, 0, 0, 0, 1 };

  static const int8_T iv2[9] = { -1, 0, 0, 0, 1, 0, 0, 0, -1 };

  static const int8_T iv3[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T iv4[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const int8_T iv5[9] = { 1, 0, 0, 0, 1, 0, 0, 0, -1 };

  static const int8_T iv6[9] = { 1, 0, 0, 0, -1, 0, 0, 0, 1 };

  static const int8_T iv7[9] = { -1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T pa[3];
  real_T Na[9];
  real_T pb[3];
  real_T Nb[9];
  real_T na[3];
  real_T nb[3];
  real_T min2;
  int32_T i;
  int32_T i3;
  int32_T b_i;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  creal_T y_data[72];
  int32_T Rx_solved_size_idx_0;
  int32_T i7;
  int32_T loop_ub;
  int32_T i8;
  creal_T a_data[72];
  int8_T tmp_size[2];
  static const creal_T beta1 = { 0.0, 0.0 };

  creal_T tmp_data[576];
  int32_T a_size[2];
  int32_T iv8[2];
  int32_T b_tmp_size[2];
  creal_T b_tmp_data[576];
  creal_T b_a_data[576];
  creal_T b_y_data[72];
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  static const creal_T alpha1 = { 1.0, 0.0 };

  int32_T y_size[2];
  int32_T tx_temp_size[2];
  creal_T tx_temp_data[9];
  int32_T Rx_solved_size[2];
  creal_T dc0;
  boolean_T guard1 = false;
  creal_T b_nb[3];
  creal_T b_na[3];
  int32_T c_tmp_size[2];
  creal_T c_tmp_data[9];
  creal_T b_pa[3];
  creal_T Rx_data[72];
  int32_T b_y_size[2];
  creal_T c_a_data[72];
  creal_T tx_data[9];
  creal_T d_tmp_data[81];
  static const int8_T iv9[4] = { 0, 0, 0, 1 };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  distibutionPropsMex(&st, A, MeanA, SigA);
  st.site = &b_emlrtRSI;
  distibutionPropsMex(&st, B, MeanB, SigB);
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_SigA[i1 + 3 * i0] = SigA[i1 + 6 * i0];
    }
  }

  st.site = &c_emlrtRSI;
  eig(&st, b_SigA, VA, unusedU0);
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_SigA[i1 + 3 * i0] = SigB[i1 + 6 * i0];
    }
  }

  st.site = &d_emlrtRSI;
  eig(&st, b_SigA, unusedU0, unusedU1);
  memset(&Rx_solved[0], 0, 72U * sizeof(creal_T));

  /*  if ~isreal(VA) || ~isreal(VB) */
  /*      fprintf('SVD of either SigA or SigB is not real.') */
  /*  end */
  /*  Rx_solved(:,:,1) = VA*Q1*VB'; */
  /*  Rx_solved(:,:,2) = VA*Q2*VB'; */
  /*  Rx_solved(:,:,3) = VA*Q3*VB'; */
  /*  Rx_solved(:,:,4) = VA*Q4*VB'; */
  /*  Rx_solved(:,:,5) = VA*-Q1*VB'; */
  /*  Rx_solved(:,:,6) = VA*-Q2*VB'; */
  /*  Rx_solved(:,:,7) = VA*-Q3*VB'; */
  /*  Rx_solved(:,:,8) = VA*-Q4*VB'; */
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      dcv0[i1 + 3 * i0].re = iv0[i1 + 3 * i0];
      dcv0[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * i2].re * dcv0[i2 + 3 * i1].re -
          VA[i0 + 3 * i2].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * i2].re * 0.0 + VA[i0 + 3 * i2].im *
          dcv0[i2 + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * i1].re = 0.0;
      Rx_solved[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = unusedU0[i1 + 3 * i2].re;
        unusedU3 = -unusedU0[i1 + 3 * i2].im;
        Rx_solved[i0 + 3 * i1].re += b_VA[i0 + 3 * i2].re * unusedU2 - b_VA[i0 +
          3 * i2].im * unusedU3;
        Rx_solved[i0 + 3 * i1].im += b_VA[i0 + 3 * i2].re * unusedU3 + b_VA[i0 +
          3 * i2].im * unusedU2;
      }

      dcv1[i1 + 3 * i0].re = iv1[i1 + 3 * i0];
      dcv1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * i2].re * dcv1[i2 + 3 * i1].re -
          VA[i0 + 3 * i2].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * i2].re * 0.0 + VA[i0 + 3 * i2].im *
          dcv1[i2 + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (3 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (3 + i1)].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = unusedU0[i1 + 3 * i2].re;
        unusedU3 = -unusedU0[i1 + 3 * i2].im;
        Rx_solved[i0 + 3 * (3 + i1)].re += b_VA[i0 + 3 * i2].re * unusedU2 -
          b_VA[i0 + 3 * i2].im * unusedU3;
        Rx_solved[i0 + 3 * (3 + i1)].im += b_VA[i0 + 3 * i2].re * unusedU3 +
          b_VA[i0 + 3 * i2].im * unusedU2;
      }

      dcv0[i1 + 3 * i0].re = iv2[i1 + 3 * i0];
      dcv0[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * i2].re * dcv0[i2 + 3 * i1].re -
          VA[i0 + 3 * i2].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * i2].re * 0.0 + VA[i0 + 3 * i2].im *
          dcv0[i2 + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (6 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (6 + i1)].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = unusedU0[i1 + 3 * i2].re;
        unusedU3 = -unusedU0[i1 + 3 * i2].im;
        Rx_solved[i0 + 3 * (6 + i1)].re += b_VA[i0 + 3 * i2].re * unusedU2 -
          b_VA[i0 + 3 * i2].im * unusedU3;
        Rx_solved[i0 + 3 * (6 + i1)].im += b_VA[i0 + 3 * i2].re * unusedU3 +
          b_VA[i0 + 3 * i2].im * unusedU2;
      }

      dcv1[i1 + 3 * i0].re = iv3[i1 + 3 * i0];
      dcv1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * i2].re * dcv1[i2 + 3 * i1].re -
          VA[i0 + 3 * i2].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * i2].re * 0.0 + VA[i0 + 3 * i2].im *
          dcv1[i2 + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (9 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (9 + i1)].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = unusedU0[i1 + 3 * i2].re;
        unusedU3 = -unusedU0[i1 + 3 * i2].im;
        Rx_solved[i0 + 3 * (9 + i1)].re += b_VA[i0 + 3 * i2].re * unusedU2 -
          b_VA[i0 + 3 * i2].im * unusedU3;
        Rx_solved[i0 + 3 * (9 + i1)].im += b_VA[i0 + 3 * i2].re * unusedU3 +
          b_VA[i0 + 3 * i2].im * unusedU2;
      }

      dcv0[i1 + 3 * i0].re = iv4[i1 + 3 * i0];
      dcv0[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * i2].re * dcv0[i2 + 3 * i1].re -
          VA[i0 + 3 * i2].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * i2].re * 0.0 + VA[i0 + 3 * i2].im *
          dcv0[i2 + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (12 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (12 + i1)].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = unusedU0[i1 + 3 * i2].re;
        unusedU3 = -unusedU0[i1 + 3 * i2].im;
        Rx_solved[i0 + 3 * (12 + i1)].re += b_VA[i0 + 3 * i2].re * unusedU2 -
          b_VA[i0 + 3 * i2].im * unusedU3;
        Rx_solved[i0 + 3 * (12 + i1)].im += b_VA[i0 + 3 * i2].re * unusedU3 +
          b_VA[i0 + 3 * i2].im * unusedU2;
      }

      dcv1[i1 + 3 * i0].re = iv5[i1 + 3 * i0];
      dcv1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * i2].re * dcv1[i2 + 3 * i1].re -
          VA[i0 + 3 * i2].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * i2].re * 0.0 + VA[i0 + 3 * i2].im *
          dcv1[i2 + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (15 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (15 + i1)].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = unusedU0[i1 + 3 * i2].re;
        unusedU3 = -unusedU0[i1 + 3 * i2].im;
        Rx_solved[i0 + 3 * (15 + i1)].re += b_VA[i0 + 3 * i2].re * unusedU2 -
          b_VA[i0 + 3 * i2].im * unusedU3;
        Rx_solved[i0 + 3 * (15 + i1)].im += b_VA[i0 + 3 * i2].re * unusedU3 +
          b_VA[i0 + 3 * i2].im * unusedU2;
      }

      dcv0[i1 + 3 * i0].re = iv6[i1 + 3 * i0];
      dcv0[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * i2].re * dcv0[i2 + 3 * i1].re -
          VA[i0 + 3 * i2].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * i2].re * 0.0 + VA[i0 + 3 * i2].im *
          dcv0[i2 + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (18 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (18 + i1)].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = unusedU0[i1 + 3 * i2].re;
        unusedU3 = -unusedU0[i1 + 3 * i2].im;
        Rx_solved[i0 + 3 * (18 + i1)].re += b_VA[i0 + 3 * i2].re * unusedU2 -
          b_VA[i0 + 3 * i2].im * unusedU3;
        Rx_solved[i0 + 3 * (18 + i1)].im += b_VA[i0 + 3 * i2].re * unusedU3 +
          b_VA[i0 + 3 * i2].im * unusedU2;
      }

      dcv1[i1 + 3 * i0].re = iv7[i1 + 3 * i0];
      dcv1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * i2].re * dcv1[i2 + 3 * i1].re -
          VA[i0 + 3 * i2].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * i2].re * 0.0 + VA[i0 + 3 * i2].im *
          dcv1[i2 + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (21 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (21 + i1)].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = unusedU0[i1 + 3 * i2].re;
        unusedU3 = -unusedU0[i1 + 3 * i2].im;
        Rx_solved[i0 + 3 * (21 + i1)].re += b_VA[i0 + 3 * i2].re * unusedU2 -
          b_VA[i0 + 3 * i2].im * unusedU3;
        Rx_solved[i0 + 3 * (21 + i1)].im += b_VA[i0 + 3 * i2].re * unusedU3 +
          b_VA[i0 + 3 * i2].im * unusedU2;
      }
    }
  }

  st.site = &e_emlrtRSI;
  param_extract(&st, MeanA, &unusedU2, Na, &unusedU3, pa);
  st.site = &f_emlrtRSI;
  param_extract(&st, MeanB, &unusedU2, Nb, &unusedU3, pb);

  /* Function to vectorize or hat an element in so(3) */
  /* files needed: */
  /* none */
  /* If input is skew-sym change to vector */
  na[0] = -Na[7];
  na[1] = Na[6];
  na[2] = -Na[3];

  /* Function to vectorize or hat an element in so(3) */
  /* files needed: */
  /* none */
  /* If input is skew-sym change to vector */
  nb[0] = -Nb[7];
  nb[1] = Nb[6];
  nb[2] = -Nb[3];

  /* min=inf; */
  min2 = rtInf;
  i = 0;
  while (i < 8) {
    i0 = 3 * i + 1;
    i1 = 3 * (1 + i);
    if (i0 > i1) {
      i0 = 0;
      i1 = 0;
    } else {
      i0--;
    }

    i2 = 3 * i + 1;
    i3 = 3 * (1 + i);
    if (i2 > i3) {
      i2 = 0;
      i3 = 0;
    } else {
      i2--;
    }

    b_i = 3 * i + 1;
    i4 = 3 * (1 + i);
    if (b_i > i4) {
      b_i = 0;
      i4 = 0;
    } else {
      b_i--;
    }

    i5 = 3 * i + 1;
    i6 = 3 * (1 + i);
    if (i5 > i6) {
      i5 = 0;
      i6 = 0;
    } else {
      i5--;
    }

    Rx_solved_size_idx_0 = i4 - b_i;
    for (i7 = 0; i7 < 3; i7++) {
      loop_ub = i4 - b_i;
      for (i8 = 0; i8 < loop_ub; i8++) {
        y_data[i8 + Rx_solved_size_idx_0 * i7].re = Rx_solved[i7 + 3 * (b_i + i8)]
          .re;
        y_data[i8 + Rx_solved_size_idx_0 * i7].im = -Rx_solved[i7 + 3 * (b_i +
          i8)].im;
      }
    }

    for (b_i = 0; b_i < 3; b_i++) {
      for (i4 = 0; i4 < 3; i4++) {
        unusedU1[i4 + 3 * b_i].re = SigA[i4 + 6 * (3 + b_i)];
        unusedU1[i4 + 3 * b_i].im = 0.0;
      }
    }

    for (b_i = 0; b_i < Rx_solved_size_idx_0; b_i++) {
      for (i4 = 0; i4 < 3; i4++) {
        a_data[b_i + Rx_solved_size_idx_0 * i4].re = 0.0;
        a_data[b_i + Rx_solved_size_idx_0 * i4].im = 0.0;
        for (i7 = 0; i7 < 3; i7++) {
          a_data[b_i + Rx_solved_size_idx_0 * i4].re += y_data[b_i +
            Rx_solved_size_idx_0 * i7].re * unusedU1[i7 + 3 * i4].re -
            y_data[b_i + Rx_solved_size_idx_0 * i7].im * 0.0;
          a_data[b_i + Rx_solved_size_idx_0 * i4].im += y_data[b_i +
            Rx_solved_size_idx_0 * i7].re * 0.0 + y_data[b_i +
            Rx_solved_size_idx_0 * i7].im * unusedU1[i7 + 3 * i4].re;
        }
      }
    }

    st.site = &g_emlrtRSI;
    tmp_size[0] = (int8_T)Rx_solved_size_idx_0;
    tmp_size[1] = (int8_T)(i6 - i5);
    loop_ub = Rx_solved_size_idx_0 * (i6 - i5);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      tmp_data[b_i] = beta1;
    }

    loop_ub = i6 - i5;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      for (i4 = 0; i4 < 3; i4++) {
        y_data[i4 + 3 * b_i] = Rx_solved[i4 + 3 * (i5 + b_i)];
      }
    }

    b_st.site = &rc_emlrtRSI;
    eml_xgemm(Rx_solved_size_idx_0, i6 - i5, a_data, Rx_solved_size_idx_0,
              y_data, tmp_data, Rx_solved_size_idx_0);
    for (b_i = 0; b_i < 2; b_i++) {
      a_size[b_i] = 3;
      iv8[b_i] = tmp_size[b_i];
    }

    if ((3 != iv8[0]) || (3 != iv8[1])) {
      emlrtSizeEqCheckNDR2012b(a_size, iv8, &e_emlrtECI, sp);
    }

    Rx_solved_size_idx_0 = i1 - i0;
    for (b_i = 0; b_i < 3; b_i++) {
      loop_ub = i1 - i0;
      for (i4 = 0; i4 < loop_ub; i4++) {
        y_data[i4 + Rx_solved_size_idx_0 * b_i].re = Rx_solved[b_i + 3 * (i0 +
          i4)].re;
        y_data[i4 + Rx_solved_size_idx_0 * b_i].im = -Rx_solved[b_i + 3 * (i0 +
          i4)].im;
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        unusedU1[i1 + 3 * i0].re = SigA[i1 + 6 * i0];
        unusedU1[i1 + 3 * i0].im = 0.0;
      }
    }

    for (i0 = 0; i0 < Rx_solved_size_idx_0; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        a_data[i0 + Rx_solved_size_idx_0 * i1].re = 0.0;
        a_data[i0 + Rx_solved_size_idx_0 * i1].im = 0.0;
        for (b_i = 0; b_i < 3; b_i++) {
          a_data[i0 + Rx_solved_size_idx_0 * i1].re += y_data[i0 +
            Rx_solved_size_idx_0 * b_i].re * unusedU1[b_i + 3 * i1].re -
            y_data[i0 + Rx_solved_size_idx_0 * b_i].im * 0.0;
          a_data[i0 + Rx_solved_size_idx_0 * i1].im += y_data[i0 +
            Rx_solved_size_idx_0 * b_i].re * 0.0 + y_data[i0 +
            Rx_solved_size_idx_0 * b_i].im * unusedU1[b_i + 3 * i1].re;
        }
      }
    }

    st.site = &g_emlrtRSI;
    b_tmp_size[0] = Rx_solved_size_idx_0;
    b_tmp_size[1] = i3 - i2;
    loop_ub = Rx_solved_size_idx_0 * (i3 - i2);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_tmp_data[i0] = beta1;
    }

    loop_ub = i3 - i2;
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        y_data[i1 + 3 * i0] = Rx_solved[i1 + 3 * (i2 + i0)];
      }
    }

    b_st.site = &rc_emlrtRSI;
    eml_xgemm(Rx_solved_size_idx_0, i3 - i2, a_data, Rx_solved_size_idx_0,
              y_data, b_tmp_data, Rx_solved_size_idx_0);
    st.site = &g_emlrtRSI;
    b_mpower(&st, b_tmp_data, b_tmp_size, b_a_data, a_size);
    st.site = &g_emlrtRSI;
    for (i0 = 0; i0 < 3; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        unusedU0[i1 + 3 * i0].re = SigB[i1 + 6 * (3 + i0)] - tmp_data[i1 + 3 *
          i0].re;
        unusedU0[i1 + 3 * i0].im = 0.0 - tmp_data[i1 + 3 * i0].im;
      }
    }

    b_st.site = &hg_emlrtRSI;
    if (!(a_size[1] == 3)) {
      if ((a_size[0] == 1) && (a_size[1] == 1)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &d_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &c_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }
    }

    loop_ub = (int8_T)a_size[0] * 3;
    for (i0 = 0; i0 < loop_ub; i0++) {
      a_data[i0] = beta1;
    }

    b_st.site = &rc_emlrtRSI;
    loop_ub = (int8_T)a_size[0] * 3;
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_y_data[i0] = beta1;
    }

    if (a_size[0] < 1) {
    } else {
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)a_size[0];
      n_t = (ptrdiff_t)3;
      k_t = (ptrdiff_t)3;
      lda_t = (ptrdiff_t)a_size[0];
      ldb_t = (ptrdiff_t)3;
      ldc_t = (ptrdiff_t)a_size[0];
      zgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, (real_T *)&alpha1, (real_T *)
            &b_a_data[0], &lda_t, (real_T *)&unusedU0[0], &ldb_t, (real_T *)
            &beta1, (real_T *)&b_y_data[0], &ldc_t);
    }

    y_size[0] = 3;
    y_size[1] = (int8_T)a_size[0];
    loop_ub = (int8_T)a_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        y_data[i1 + 3 * i0].re = b_y_data[i0 + (int8_T)a_size[0] * i1].re;
        y_data[i1 + 3 * i0].im = -b_y_data[i0 + (int8_T)a_size[0] * i1].im;
      }
    }

    st.site = &g_emlrtRSI;
    so3_vec(&st, y_data, y_size, tx_temp_data, tx_temp_size);
    i0 = 3 * i + 1;
    i1 = 3 * (1 + i);
    if (i0 > i1) {
      i0 = 0;
      i1 = 0;
    } else {
      i0--;
    }

    Rx_solved_size[0] = 3;
    Rx_solved_size[1] = i1 - i0;
    loop_ub = i1 - i0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 3; i2++) {
        y_data[i2 + 3 * i1] = Rx_solved[i2 + 3 * (i0 + i1)];
      }
    }

    st.site = &h_emlrtRSI;
    dc0 = det(&st, y_data, Rx_solved_size);
    guard1 = false;
    if (muDoubleScalarHypot(dc0.re - 1.0, dc0.im) < 0.001) {
      i0 = 3 * i + 1;
      i1 = 3 * (1 + i);
      if (i0 > i1) {
        i0 = 0;
        i1 = 0;
      } else {
        i0--;
      }

      st.site = &h_emlrtRSI;
      b_st.site = &hg_emlrtRSI;
      if (!(i1 - i0 == 3)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &c_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }

      loop_ub = i1 - i0;
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < 3; i2++) {
          y_data[i2 + 3 * i1] = Rx_solved[i2 + 3 * (i0 + i1)];
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        b_nb[i0].re = nb[i0];
        b_nb[i0].im = 0.0;
      }

      for (i0 = 0; i0 < 3; i0++) {
        unusedU2 = 0.0;
        unusedU3 = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          unusedU2 += y_data[i0 + 3 * i1].re * b_nb[i1].re - y_data[i0 + 3 * i1]
            .im * 0.0;
          unusedU3 += y_data[i0 + 3 * i1].re * 0.0 + y_data[i0 + 3 * i1].im *
            b_nb[i1].re;
        }

        b_na[i0].re = na[i0] - unusedU2;
        b_na[i0].im = 0.0 - unusedU3;
      }

      if (genpnorm(b_na) < 1.5) {
        i0 = 3 * i + 1;
        i1 = 3 * (1 + i);
        if (i0 > i1) {
          i0 = 0;
          i1 = 0;
        } else {
          i0--;
        }

        eye(Na);
        for (i2 = 0; i2 < 3; i2++) {
          for (i3 = 0; i3 < 3; i3++) {
            unusedU1[i2 + 3 * i3].re = Na[i2 + 3 * i3] - na[i2] * na[i3];
            unusedU1[i2 + 3 * i3].im = 0.0;
          }
        }

        c_tmp_size[0] = 3;
        c_tmp_size[1] = tx_temp_size[1];
        for (i2 = 0; i2 < 3; i2++) {
          loop_ub = tx_temp_size[1];
          for (i3 = 0; i3 < loop_ub; i3++) {
            c_tmp_data[i2 + 3 * i3].re = 0.0;
            c_tmp_data[i2 + 3 * i3].im = 0.0;
            for (b_i = 0; b_i < 3; b_i++) {
              c_tmp_data[i2 + 3 * i3].re += unusedU1[i2 + 3 * b_i].re *
                tx_temp_data[b_i + tx_temp_size[0] * i3].re - 0.0 *
                tx_temp_data[b_i + tx_temp_size[0] * i3].im;
              c_tmp_data[i2 + 3 * i3].im += unusedU1[i2 + 3 * b_i].re *
                tx_temp_data[b_i + tx_temp_size[0] * i3].im + 0.0 *
                tx_temp_data[b_i + tx_temp_size[0] * i3].re;
            }
          }
        }

        for (i2 = 0; i2 < 2; i2++) {
          a_size[i2] = 3 + -2 * i2;
          iv8[i2] = c_tmp_size[i2];
        }

        if ((a_size[0] != iv8[0]) || (a_size[1] != iv8[1])) {
          emlrtSizeEqCheckNDR2012b(a_size, iv8, &d_emlrtECI, sp);
        }

        st.site = &h_emlrtRSI;
        b_st.site = &hg_emlrtRSI;
        if (!(i1 - i0 == 3)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &c_emlrtRTEI,
            "Coder:MATLAB:innerdim", 0);
        }

        loop_ub = i1 - i0;
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (i2 = 0; i2 < 3; i2++) {
            y_data[i2 + 3 * i1] = Rx_solved[i2 + 3 * (i0 + i1)];
          }
        }

        for (i0 = 0; i0 < 3; i0++) {
          b_nb[i0].re = pb[i0];
          b_nb[i0].im = 0.0;
        }

        for (i0 = 0; i0 < 3; i0++) {
          b_na[i0].re = 0.0;
          b_na[i0].im = 0.0;
          for (i1 = 0; i1 < 3; i1++) {
            b_na[i0].re += y_data[i0 + 3 * i1].re * b_nb[i1].re - y_data[i0 + 3 *
              i1].im * 0.0;
            b_na[i0].im += y_data[i0 + 3 * i1].re * 0.0 + y_data[i0 + 3 * i1].im
              * b_nb[i1].re;
          }

          b_pa[i0].re = pa[i0] - (b_na[i0].re + c_tmp_data[i0].re);
          b_pa[i0].im = 0.0 - (b_na[i0].im + c_tmp_data[i0].im);
        }

        if (genpnorm(b_pa) < min2) {
          /* min=norm(na-Rx_solved(1:3,1:3,i)*nb); */
          i0 = 3 * i + 1;
          i1 = 3 * (1 + i);
          if (i0 > i1) {
            i0 = 0;
            i1 = 0;
          } else {
            i0--;
          }

          eye(Na);
          for (i2 = 0; i2 < 3; i2++) {
            for (i3 = 0; i3 < 3; i3++) {
              unusedU1[i2 + 3 * i3].re = Na[i2 + 3 * i3] - na[i2] * na[i3];
              unusedU1[i2 + 3 * i3].im = 0.0;
            }
          }

          c_tmp_size[0] = 3;
          c_tmp_size[1] = tx_temp_size[1];
          for (i2 = 0; i2 < 3; i2++) {
            loop_ub = tx_temp_size[1];
            for (i3 = 0; i3 < loop_ub; i3++) {
              c_tmp_data[i2 + 3 * i3].re = 0.0;
              c_tmp_data[i2 + 3 * i3].im = 0.0;
              for (b_i = 0; b_i < 3; b_i++) {
                c_tmp_data[i2 + 3 * i3].re += unusedU1[i2 + 3 * b_i].re *
                  tx_temp_data[b_i + tx_temp_size[0] * i3].re - 0.0 *
                  tx_temp_data[b_i + tx_temp_size[0] * i3].im;
                c_tmp_data[i2 + 3 * i3].im += unusedU1[i2 + 3 * b_i].re *
                  tx_temp_data[b_i + tx_temp_size[0] * i3].im + 0.0 *
                  tx_temp_data[b_i + tx_temp_size[0] * i3].re;
              }
            }
          }

          for (i2 = 0; i2 < 2; i2++) {
            a_size[i2] = 3 + -2 * i2;
            iv8[i2] = c_tmp_size[i2];
          }

          if ((a_size[0] != iv8[0]) || (a_size[1] != iv8[1])) {
            emlrtSizeEqCheckNDR2012b(a_size, iv8, &c_emlrtECI, sp);
          }

          st.site = &i_emlrtRSI;
          b_st.site = &hg_emlrtRSI;
          if (!(i1 - i0 == 3)) {
            emlrtErrorWithMessageIdR2012b(&b_st, &c_emlrtRTEI,
              "Coder:MATLAB:innerdim", 0);
          }

          loop_ub = i1 - i0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < 3; i2++) {
              y_data[i2 + 3 * i1] = Rx_solved[i2 + 3 * (i0 + i1)];
            }
          }

          for (i0 = 0; i0 < 3; i0++) {
            b_nb[i0].re = pb[i0];
            b_nb[i0].im = 0.0;
          }

          for (i0 = 0; i0 < 3; i0++) {
            b_na[i0].re = 0.0;
            b_na[i0].im = 0.0;
            for (i1 = 0; i1 < 3; i1++) {
              b_na[i0].re += y_data[i0 + 3 * i1].re * b_nb[i1].re - y_data[i0 +
                3 * i1].im * 0.0;
              b_na[i0].im += y_data[i0 + 3 * i1].re * 0.0 + y_data[i0 + 3 * i1].
                im * b_nb[i1].re;
            }

            b_pa[i0].re = pa[i0] - (b_na[i0].re + c_tmp_data[i0].re);
            b_pa[i0].im = 0.0 - (b_na[i0].im + c_tmp_data[i0].im);
          }

          min2 = genpnorm(b_pa);
          i0 = 3 * i + 1;
          i1 = 3 * (1 + i);
          if (i0 > i1) {
            i0 = 0;
            i1 = 0;
          } else {
            i0--;
          }

          b_i = i1 - i0;
          loop_ub = i1 - i0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (i2 = 0; i2 < 3; i2++) {
              Rx_data[i2 + 3 * i1] = Rx_solved[i2 + 3 * (i0 + i1)];
            }
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      b_i = 3;
      memset(&Rx_data[0], 0, 9U * sizeof(creal_T));
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      unusedU1[i1 + 3 * i0].re = SigA[i1 + 6 * (3 + i0)];
      unusedU1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < b_i; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      a_data[i0 + b_i * i1].re = 0.0;
      a_data[i0 + b_i * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = Rx_data[i2 + 3 * i0].re;
        unusedU3 = -Rx_data[i2 + 3 * i0].im;
        a_data[i0 + b_i * i1].re += unusedU2 * unusedU1[i2 + 3 * i1].re -
          unusedU3 * 0.0;
        a_data[i0 + b_i * i1].im += unusedU2 * 0.0 + unusedU3 * unusedU1[i2 + 3 *
          i1].re;
      }
    }
  }

  st.site = &j_emlrtRSI;
  tmp_size[0] = (int8_T)b_i;
  tmp_size[1] = (int8_T)b_i;
  loop_ub = b_i * b_i;
  for (i0 = 0; i0 < loop_ub; i0++) {
    tmp_data[i0] = beta1;
  }

  b_st.site = &rc_emlrtRSI;
  eml_xgemm(b_i, b_i, a_data, b_i, Rx_data, tmp_data, b_i);
  for (i = 0; i < 2; i++) {
    a_size[i] = 3;
    iv8[i] = tmp_size[i];
  }

  if ((3 != iv8[0]) || (3 != iv8[1])) {
    emlrtSizeEqCheckNDR2012b(a_size, iv8, &b_emlrtECI, sp);
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      unusedU1[i1 + 3 * i0].re = SigA[i1 + 6 * i0];
      unusedU1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < b_i; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      a_data[i0 + b_i * i1].re = 0.0;
      a_data[i0 + b_i * i1].im = 0.0;
      for (i2 = 0; i2 < 3; i2++) {
        unusedU2 = Rx_data[i2 + 3 * i0].re;
        unusedU3 = -Rx_data[i2 + 3 * i0].im;
        a_data[i0 + b_i * i1].re += unusedU2 * unusedU1[i2 + 3 * i1].re -
          unusedU3 * 0.0;
        a_data[i0 + b_i * i1].im += unusedU2 * 0.0 + unusedU3 * unusedU1[i2 + 3 *
          i1].re;
      }
    }
  }

  st.site = &j_emlrtRSI;
  b_tmp_size[0] = b_i;
  b_tmp_size[1] = b_i;
  loop_ub = b_i * b_i;
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_tmp_data[i0] = beta1;
  }

  b_st.site = &rc_emlrtRSI;
  eml_xgemm(b_i, b_i, a_data, b_i, Rx_data, b_tmp_data, b_i);
  st.site = &j_emlrtRSI;
  b_mpower(&st, b_tmp_data, b_tmp_size, b_a_data, a_size);
  st.site = &j_emlrtRSI;
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      unusedU0[i1 + 3 * i0].re = SigB[i1 + 6 * (3 + i0)] - tmp_data[i1 + 3 * i0]
        .re;
      unusedU0[i1 + 3 * i0].im = 0.0 - tmp_data[i1 + 3 * i0].im;
    }
  }

  b_st.site = &hg_emlrtRSI;
  if (!(a_size[1] == 3)) {
    if ((a_size[0] == 1) && (a_size[1] == 1)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &d_emlrtRTEI,
        "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2012b(&b_st, &c_emlrtRTEI, "Coder:MATLAB:innerdim",
        0);
    }
  }

  b_st.site = &rc_emlrtRSI;
  loop_ub = (int8_T)a_size[0] * 3;
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_y_data[i0] = beta1;
  }

  if (a_size[0] < 1) {
  } else {
    TRANSB = 'N';
    TRANSA = 'N';
    m_t = (ptrdiff_t)a_size[0];
    n_t = (ptrdiff_t)3;
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)a_size[0];
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)a_size[0];
    zgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, (real_T *)&alpha1, (real_T *)
          &b_a_data[0], &lda_t, (real_T *)&unusedU0[0], &ldb_t, (real_T *)&beta1,
          (real_T *)&b_y_data[0], &ldc_t);
  }

  b_y_size[0] = 3;
  b_y_size[1] = (int8_T)a_size[0];
  loop_ub = (int8_T)a_size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      y_data[i1 + 3 * i0].re = b_y_data[i0 + (int8_T)a_size[0] * i1].re;
      y_data[i1 + 3 * i0].im = -b_y_data[i0 + (int8_T)a_size[0] * i1].im;
    }
  }

  st.site = &j_emlrtRSI;
  so3_vec(&st, y_data, b_y_size, tx_temp_data, tx_temp_size);
  st.site = &k_emlrtRSI;
  loop_ub = 3 * b_i;
  for (i0 = 0; i0 < loop_ub; i0++) {
    c_a_data[i0].re = -Rx_data[i0].re;
    c_a_data[i0].im = -Rx_data[i0].im;
  }

  b_st.site = &hg_emlrtRSI;
  if (!(b_i == 3)) {
    emlrtErrorWithMessageIdR2012b(&b_st, &c_emlrtRTEI, "Coder:MATLAB:innerdim",
      0);
  }

  b_st.site = &rc_emlrtRSI;
  loop_ub = 3 * (int8_T)tx_temp_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    tx_data[i0] = beta1;
  }

  TRANSB = 'N';
  TRANSA = 'N';
  m_t = (ptrdiff_t)3;
  n_t = (ptrdiff_t)tx_temp_size[1];
  k_t = (ptrdiff_t)3;
  lda_t = (ptrdiff_t)3;
  ldb_t = (ptrdiff_t)3;
  ldc_t = (ptrdiff_t)3;
  zgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, (real_T *)&alpha1, (real_T *)
        &c_a_data[0], &lda_t, (real_T *)&tx_temp_data[0], &ldb_t, (real_T *)
        &beta1, (real_T *)&tx_data[0], &ldc_t);
  for (i0 = 0; i0 < b_i; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      d_tmp_data[i1 + 3 * i0] = Rx_data[i1 + 3 * i0];
    }
  }

  loop_ub = (int8_T)tx_temp_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      d_tmp_data[i1 + 3 * (i0 + b_i)] = tx_data[i1 + 3 * i0];
    }
  }

  i0 = b_i + (int8_T)tx_temp_size[1];
  if (4 != i0) {
    emlrtDimSizeEqCheckR2012b(4, i0, &emlrtECI, sp);
  }

  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      X[i1 + (i0 << 2)] = d_tmp_data[i1 + 3 * i0];
    }

    X[3 + (i0 << 2)].re = iv9[i0];
    X[3 + (i0 << 2)].im = 0.0;
  }
}

/* End of code generation (batchEDSolve.c) */
