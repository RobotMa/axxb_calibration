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
#include "mean_double_convl_2nd.h"
#include "mean_Taylor_2nd.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "mean_Taylor_1st.h"
#include "mean_double_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 127, 1, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo l_emlrtRSI = { 17, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo m_emlrtRSI = { 20, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo n_emlrtRSI = { 68, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo o_emlrtRSI = { 69, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo p_emlrtRSI = { 76, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo q_emlrtRSI = { 77, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo r_emlrtRSI = { 87, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo s_emlrtRSI = { 88, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtRSInfo t_emlrtRSI = { 127, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtECInfo c_emlrtECI = { 2, 77, 22, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtECInfo d_emlrtECI = { 2, 76, 22, "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m"
};

static emlrtBCInfo b_emlrtBCI = { 1, 6, 68, 39, "E", "mean_Taylor_2nd",
  "/home/roma/Dropbox/2015Spring/AXXB Journal/Batch_AXXB/Matlab_AXXB/mean_Taylor_2nd.m",
  0 };

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m4;
  y = NULL;
  m4 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m4);
  return y;
}

void mean_Taylor_2nd(const emlrtStack *sp, const real_T X[800], int8_T noise,
                     int16_T num, real_T MX[16])
{
  real_T M_t1[16];
  real_T b_M_t1[16];
  real_T CA;
  int8_T E[96];
  int32_T i9;
  int32_T i10;
  static const int8_T iv6[16] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv7[16] = { 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv8[16] = { 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

  static const int8_T iv9[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0
  };

  static const int8_T iv10[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0 };

  static const int8_T iv11[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0 };

  real_T count;
  int32_T m;
  real_T step;
  boolean_T exitg1;
  real_T n_step;
  int32_T j;
  int32_T b_j;
  real_T a;
  real_T b_a[16];
  real_T MX1sum[16];
  real_T MX1[16];
  int32_T i;
  real_T MX2[16];
  real_T MX2sum[16];
  int32_T k;
  int32_T X_k_size[2];
  int32_T loop_ub;
  int32_T i11;
  real_T X_k_data[800];
  int32_T tmp_size[2];
  real_T tmp_data[16];
  int32_T a_size[2];
  real_T a_data[800];
  uint8_T b_tmp_size[2];
  real_T b_tmp_data[800];
  int32_T iv12[2];
  real_T b_MX1sum;
  real_T b_MX2sum;
  real_T CA1;
  real_T CA2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  This function calculates the 2nd order approximation of the mean of a */
  /*  bunch of matrices based on the Taylor expansion of the matrix logarithm */
  /*  and the definition of mean of a probability density function. */
  /*  Input: X is a cell of 4 by 4*n rigid transformation matrices */
  /*  Output: M_T1 is the mean of the 1st order approximation of Taylor */
  /*  expansion */
  /*  Output: MX is the 2nd order approximation of the Taylor expansion */
  /*  coder.extrinsic('mean_Taylor_1st_mex'); */
  st.site = &l_emlrtRSI;
  mean_Taylor_1st(&st, X, M_t1);

  /*  Potential further refinement */
  memcpy(&b_M_t1[0], &M_t1[0], sizeof(real_T) << 4);
  st.site = &m_emlrtRSI;
  b_mean_Taylor_1st(&st, b_M_t1, M_t1);

  /*  Perturb M_t1 along each direction defined by the Lie algebra element of */
  /*  SE(3) */
  CA = rtInf;
  for (i9 = 0; i9 < 4; i9++) {
    for (i10 = 0; i10 < 4; i10++) {
      E[i10 + (i9 << 2)] = iv6[i10 + (i9 << 2)];
      E[16 + (i10 + (i9 << 2))] = iv7[i10 + (i9 << 2)];
      E[32 + (i10 + (i9 << 2))] = iv8[i10 + (i9 << 2)];
      E[48 + (i10 + (i9 << 2))] = iv9[i10 + (i9 << 2)];
      E[64 + (i10 + (i9 << 2))] = iv10[i10 + (i9 << 2)];
      E[80 + (i10 + (i9 << 2))] = iv11[i10 + (i9 << 2)];
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
      a = step * 0.001;
      i9 = b_j + 1;
      emlrtDynamicBoundsCheckR2012b(i9, 1, 6, &b_emlrtBCI, sp);
      for (i9 = 0; i9 < 4; i9++) {
        for (i10 = 0; i10 < 4; i10++) {
          b_a[i10 + (i9 << 2)] = a * (real_T)E[(i10 + (i9 << 2)) + (b_j << 4)];
        }
      }

      st.site = &n_emlrtRSI;
      expm(&st, b_a, MX1sum);
      a = -step * 0.001;
      for (i9 = 0; i9 < 4; i9++) {
        for (i10 = 0; i10 < 4; i10++) {
          MX1[i9 + (i10 << 2)] = 0.0;
          for (i = 0; i < 4; i++) {
            MX1[i9 + (i10 << 2)] += MX[i9 + (i << 2)] * MX1sum[i + (i10 << 2)];
          }

          b_a[i10 + (i9 << 2)] = a * (real_T)E[(i10 + (i9 << 2)) + (b_j << 4)];
        }
      }

      st.site = &o_emlrtRSI;
      expm(&st, b_a, MX1sum);
      for (i9 = 0; i9 < 4; i9++) {
        for (i10 = 0; i10 < 4; i10++) {
          MX2[i9 + (i10 << 2)] = 0.0;
          for (i = 0; i < 4; i++) {
            MX2[i9 + (i10 << 2)] += MX[i9 + (i << 2)] * MX1sum[i + (i10 << 2)];
          }
        }
      }

      for (i9 = 0; i9 < 16; i9++) {
        MX1sum[i9] = 0.0;
        MX2sum[i9] = 0.0;
      }

      k = 0;
      while (k < 50) {
        i9 = (k << 2) + 1;
        i10 = (1 + k) << 2;
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        X_k_size[0] = 4;
        X_k_size[1] = i10 - i9;
        loop_ub = i10 - i9;
        for (i = 0; i < loop_ub; i++) {
          for (i11 = 0; i11 < 4; i11++) {
            X_k_data[i11 + (i << 2)] = X[i11 + ((i9 + i) << 2)];
          }
        }

        st.site = &p_emlrtRSI;
        b_st.site = &p_emlrtRSI;
        mrdivide(&b_st, X_k_data, X_k_size, MX1, tmp_data, tmp_size);
        a_size[0] = 4;
        a_size[1] = 4;
        memcpy(&a_data[0], &tmp_data[0], sizeof(real_T) << 4);
        b_st.site = &fd_emlrtRSI;
        dynamic_size_checks(&b_st, a_size);
        b_tmp_size[0] = 4;
        b_tmp_size[1] = (uint8_T)(i10 - i9);
        loop_ub = (uint8_T)(i10 - i9) << 2;
        for (i = 0; i < loop_ub; i++) {
          b_tmp_data[i] = 0.0;
        }

        eml_xgemm(i10 - i9, 4, a_data, X_k_data, 4, b_tmp_data);
        for (i = 0; i < 2; i++) {
          tmp_size[i] = 4;
          iv12[i] = b_tmp_size[i];
        }

        if ((4 != iv12[0]) || (4 != iv12[1])) {
          emlrtSizeEqCheckNDR2012b(tmp_size, iv12, &d_emlrtECI, sp);
        }

        for (i = 0; i < 16; i++) {
          b_MX1sum = MX1sum[i] + b_tmp_data[i];
          MX1sum[i] = b_MX1sum;
        }

        st.site = &q_emlrtRSI;
        b_st.site = &q_emlrtRSI;
        mrdivide(&b_st, X_k_data, X_k_size, MX2, tmp_data, tmp_size);
        a_size[0] = 4;
        a_size[1] = 4;
        memcpy(&a_data[0], &tmp_data[0], sizeof(real_T) << 4);
        b_st.site = &fd_emlrtRSI;
        dynamic_size_checks(&b_st, a_size);
        b_tmp_size[0] = 4;
        b_tmp_size[1] = (uint8_T)(i10 - i9);
        loop_ub = (uint8_T)(i10 - i9) << 2;
        for (i = 0; i < loop_ub; i++) {
          b_tmp_data[i] = 0.0;
        }

        eml_xgemm(i10 - i9, 4, a_data, X_k_data, 4, b_tmp_data);
        for (i = 0; i < 2; i++) {
          tmp_size[i] = 4;
          iv12[i] = b_tmp_size[i];
        }

        if ((4 != iv12[0]) || (4 != iv12[1])) {
          emlrtSizeEqCheckNDR2012b(tmp_size, iv12, &c_emlrtECI, sp);
        }

        for (i9 = 0; i9 < 16; i9++) {
          b_MX2sum = MX2sum[i9] + b_tmp_data[i9];
          MX2sum[i9] = b_MX2sum;
        }

        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      for (i9 = 0; i9 < 16; i9++) {
        MX1sum[i9] = (2.0 * M_t1[i9] - 0.01 * MX1sum[i9]) - 1.5 * MX1[i9];
        MX2sum[i9] = (2.0 * M_t1[i9] - 0.01 * MX2sum[i9]) - 1.5 * MX2[i9];
      }

      if (noise == 0) {
        a = norm(*(real_T (*)[3])&MX1sum[12]);
        CA1 = a * a;
        a = norm(*(real_T (*)[3])&MX2sum[12]);
        CA2 = a * a;
      } else if (noise == 1) {
        st.site = &r_emlrtRSI;
        a = b_norm(&st, MX1sum);
        CA1 = a * a;
        st.site = &s_emlrtRSI;
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
      exitg1 = true;
    }
  }

  /*  fprintf('\n') */
  st.site = &t_emlrtRSI;
  emlrtDisplayR2012b(emlrt_marshallOut(d_fprintf(&st, count)), "ans", &emlrtRTEI,
                     sp);

  /*  fprintf('\n') */
  /*  fprintf('\n') */
}

/* End of code generation (mean_Taylor_2nd.c) */
