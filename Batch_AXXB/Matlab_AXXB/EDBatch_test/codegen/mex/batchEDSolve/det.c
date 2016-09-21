/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * det.c
 *
 * Code generation for function 'det'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRSInfo ig_emlrtRSI = { 20, "det",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/det.m" };

static emlrtRTEInfo m_emlrtRTEI = { 11, 15, "det",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/det.m" };

/* Function Declarations */
static void b_eml_xgetrf(const emlrtStack *sp, int32_T n, creal_T A_data[],
  int32_T ipiv_data[], int32_T ipiv_size[2]);

/* Function Definitions */
static void b_eml_xgetrf(const emlrtStack *sp, int32_T n, creal_T A_data[],
  int32_T ipiv_data[], int32_T ipiv_size[2])
{
  int32_T yk;
  int32_T b_n;
  int32_T y_data[24];
  int32_T k;
  int32_T b;
  int32_T j;
  int32_T c;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  real_T temp_re;
  real_T temp_im;
  real_T A_data_re;
  real_T A_data_im;
  real_T b_A_data_re;
  real_T b_A_data_im;
  real_T brm;
  ptrdiff_t m_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  static const creal_T alpha1 = { -1.0, 0.0 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ub_emlrtRSI;
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
  b_st.site = &vb_emlrtRSI;
  yk = muIntScalarMin_sint32(3, n);
  if (yk < 1) {
    b_n = 0;
  } else {
    b_n = yk;
  }

  if (b_n > 0) {
    y_data[0] = 1;
    yk = 1;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }

  ipiv_size[0] = 1;
  ipiv_size[1] = b_n;
  for (yk = 0; yk < b_n; yk++) {
    ipiv_data[yk] = y_data[yk];
  }

  if (n < 1) {
  } else {
    b = muIntScalarMin_sint32(2, n);
    c_st.site = &cg_emlrtRSI;
    for (j = 1; j <= b; j++) {
      c = (j - 1) << 2;
      n_t = (ptrdiff_t)(4 - j);
      incx_t = (ptrdiff_t)1;
      n_t = izamax(&n_t, (real_T *)&A_data[c], &incx_t);
      yk = (int32_T)n_t - 1;
      if ((A_data[c + yk].re != 0.0) || (A_data[c + yk].im != 0.0)) {
        if (yk != 0) {
          ipiv_data[j - 1] = j + yk;
          c_st.site = &dg_emlrtRSI;
          d_st.site = &eg_emlrtRSI;
          e_st.site = &fg_emlrtRSI;
          b_n = j - 1;
          yk = (j + yk) - 1;
          f_st.site = &gg_emlrtRSI;
          if (n > 2147483646) {
            g_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }

          for (k = 1; k <= n; k++) {
            temp_re = A_data[b_n].re;
            temp_im = A_data[b_n].im;
            A_data[b_n] = A_data[yk];
            A_data[yk].re = temp_re;
            A_data[yk].im = temp_im;
            b_n += 3;
            yk += 3;
          }
        }

        yk = (c - j) + 4;
        c_st.site = &wb_emlrtRSI;
        for (b_n = c + 1; b_n + 1 <= yk; b_n++) {
          A_data_re = A_data[b_n].re;
          A_data_im = A_data[b_n].im;
          b_A_data_re = A_data[c].re;
          b_A_data_im = A_data[c].im;
          if (b_A_data_im == 0.0) {
            if (A_data_im == 0.0) {
              A_data[b_n].re = A_data_re / b_A_data_re;
              A_data[b_n].im = 0.0;
            } else if (A_data_re == 0.0) {
              A_data[b_n].re = 0.0;
              A_data[b_n].im = A_data_im / b_A_data_re;
            } else {
              A_data[b_n].re = A_data_re / b_A_data_re;
              A_data[b_n].im = A_data_im / b_A_data_re;
            }
          } else if (b_A_data_re == 0.0) {
            if (A_data_re == 0.0) {
              A_data[b_n].re = A_data_im / b_A_data_im;
              A_data[b_n].im = 0.0;
            } else if (A_data_im == 0.0) {
              A_data[b_n].re = 0.0;
              A_data[b_n].im = -(A_data_re / b_A_data_im);
            } else {
              A_data[b_n].re = A_data_im / b_A_data_im;
              A_data[b_n].im = -(A_data_re / b_A_data_im);
            }
          } else {
            brm = muDoubleScalarAbs(b_A_data_re);
            temp_re = muDoubleScalarAbs(b_A_data_im);
            if (brm > temp_re) {
              temp_im = b_A_data_im / b_A_data_re;
              temp_re = b_A_data_re + temp_im * b_A_data_im;
              A_data[b_n].re = (A_data_re + temp_im * A_data_im) / temp_re;
              A_data[b_n].im = (A_data_im - temp_im * A_data_re) / temp_re;
            } else if (temp_re == brm) {
              if (b_A_data_re > 0.0) {
                temp_im = 0.5;
              } else {
                temp_im = -0.5;
              }

              if (b_A_data_im > 0.0) {
                temp_re = 0.5;
              } else {
                temp_re = -0.5;
              }

              A_data[b_n].re = (A_data_re * temp_im + A_data_im * temp_re) / brm;
              A_data[b_n].im = (A_data_im * temp_im - A_data_re * temp_re) / brm;
            } else {
              temp_im = b_A_data_re / b_A_data_im;
              temp_re = b_A_data_im + temp_im * b_A_data_re;
              A_data[b_n].re = (temp_im * A_data_re + A_data_im) / temp_re;
              A_data[b_n].im = (temp_im * A_data_im - A_data_re) / temp_re;
            }
          }
        }
      }

      b_n = n - j;
      c_st.site = &xb_emlrtRSI;
      d_st.site = &yb_emlrtRSI;
      if (b_n < 1) {
      } else {
        e_st.site = &ac_emlrtRSI;
        m_t = (ptrdiff_t)(3 - j);
        n_t = (ptrdiff_t)b_n;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)3;
        lda_t = (ptrdiff_t)3;
        zgeru(&m_t, &n_t, (real_T *)&alpha1, (real_T *)&A_data[c + 1], &incx_t,
              (real_T *)&A_data[c + 3], &incy_t, (real_T *)&A_data[c + 4],
              &lda_t);
      }
    }
  }
}

creal_T det(const emlrtStack *sp, const creal_T x_data[], const int32_T x_size[2])
{
  creal_T y;
  int32_T loop_ub;
  int32_T i27;
  creal_T b_x_data[72];
  int32_T ipiv_size[2];
  int32_T ipiv_data[3];
  real_T y_re;
  boolean_T isodd;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (3 == x_size[1]) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &m_emlrtRTEI, "Coder:MATLAB:square", 0);
  }

  if (x_size[1] == 0) {
    y.re = 1.0;
    y.im = 0.0;
  } else {
    loop_ub = x_size[0] * x_size[1];
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_x_data[i27] = x_data[i27];
    }

    st.site = &ig_emlrtRSI;
    b_eml_xgetrf(&st, x_size[1], b_x_data, ipiv_data, ipiv_size);
    y = b_x_data[0];
    for (loop_ub = 0; loop_ub < 2; loop_ub++) {
      y_re = y.re;
      y.re = y.re * b_x_data[(loop_ub + 3 * (loop_ub + 1)) + 1].re - y.im *
        b_x_data[(loop_ub + 3 * (loop_ub + 1)) + 1].im;
      y.im = y_re * b_x_data[(loop_ub + 3 * (loop_ub + 1)) + 1].im + y.im *
        b_x_data[(loop_ub + 3 * (loop_ub + 1)) + 1].re;
    }

    isodd = false;
    for (loop_ub = 0; loop_ub <= ipiv_size[1] - 2; loop_ub++) {
      if (ipiv_data[loop_ub] > 1 + loop_ub) {
        isodd = !isodd;
      }
    }

    if (isodd) {
      y.re = -y.re;
      y.im = -y.im;
    }
  }

  return y;
}

/* End of code generation (det.c) */
