/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * inv.c
 *
 * Code generation for function 'inv'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "inv.h"
#include "eml_int_forloop_overflow_check.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRSInfo yf_emlrtRSI = { 174, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo ag_emlrtRSI = { 177, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo bg_emlrtRSI = { 180, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

/* Function Declarations */
static void b_eml_xtrsm(int32_T m, int32_T n, const creal_T A_data[], int32_T
  lda, creal_T B_data[], int32_T ldb);
static void eml_ipiv2perm(const int32_T ipiv_data[], const int32_T ipiv_size[2],
  int32_T m, int32_T perm_data[], int32_T perm_size[2]);
static void eml_xgetrf(const emlrtStack *sp, int32_T m, int32_T n, creal_T
  A_data[], int32_T lda, int32_T ipiv_data[], int32_T ipiv_size[2]);
static void eml_xswap(const emlrtStack *sp, int32_T n, creal_T x_data[], int32_T
                      ix0, int32_T incx, int32_T iy0, int32_T incy);

/* Function Definitions */
static void b_eml_xtrsm(int32_T m, int32_T n, const creal_T A_data[], int32_T
  lda, creal_T B_data[], int32_T ldb)
{
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  static const creal_T alpha1 = { 1.0, 0.0 };

  if ((m < 1) || (n < 1)) {
  } else {
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'L';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    ztrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, (real_T *)&alpha1, (real_T *)
          &A_data[0], &lda_t, (real_T *)&B_data[0], &ldb_t);
  }
}

static void eml_ipiv2perm(const int32_T ipiv_data[], const int32_T ipiv_size[2],
  int32_T m, int32_T perm_data[], int32_T perm_size[2])
{
  int32_T n;
  int32_T yk;
  int32_T k;
  if (m < 1) {
    n = 0;
  } else {
    n = m;
  }

  perm_size[0] = 1;
  perm_size[1] = n;
  if (n > 0) {
    perm_data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      perm_data[k - 1] = yk;
    }
  }

  for (k = 0; k < ipiv_size[1]; k++) {
    if (ipiv_data[k] > 1 + k) {
      n = perm_data[ipiv_data[k] - 1];
      perm_data[ipiv_data[k] - 1] = perm_data[k];
      perm_data[k] = n;
    }
  }
}

static void eml_xgetrf(const emlrtStack *sp, int32_T m, int32_T n, creal_T
  A_data[], int32_T lda, int32_T ipiv_data[], int32_T ipiv_size[2])
{
  int32_T yk;
  int32_T b_n;
  int32_T k;
  int32_T b;
  int32_T j;
  int32_T mmj;
  int32_T c;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  boolean_T b_c;
  real_T A_data_re;
  real_T A_data_im;
  real_T b_A_data_re;
  real_T b_A_data_im;
  real_T brm;
  real_T bim;
  real_T s;
  ptrdiff_t m_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  static const creal_T alpha1 = { -1.0, 0.0 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ub_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &vb_emlrtRSI;
  yk = muIntScalarMin_sint32(m, n);
  if (yk < 1) {
    b_n = 0;
  } else {
    b_n = yk;
  }

  ipiv_size[0] = 1;
  ipiv_size[1] = b_n;
  if (b_n > 0) {
    ipiv_data[0] = 1;
    yk = 1;
    for (k = 2; k <= b_n; k++) {
      yk++;
      ipiv_data[k - 1] = yk;
    }
  }

  if ((m < 1) || (n < 1)) {
  } else {
    yk = m - 1;
    b = muIntScalarMin_sint32(yk, n);
    c_st.site = &cg_emlrtRSI;
    for (j = 1; j <= b; j++) {
      mmj = m - j;
      c = (j - 1) * (lda + 1);
      if (mmj + 1 < 1) {
        yk = -1;
      } else {
        n_t = (ptrdiff_t)(mmj + 1);
        incx_t = (ptrdiff_t)1;
        n_t = izamax(&n_t, (real_T *)&A_data[c], &incx_t);
        yk = (int32_T)n_t - 1;
      }

      if ((A_data[c + yk].re != 0.0) || (A_data[c + yk].im != 0.0)) {
        if (yk != 0) {
          ipiv_data[j - 1] = j + yk;
          c_st.site = &dg_emlrtRSI;
          eml_xswap(&c_st, n, A_data, j, lda, j + yk, lda);
        }

        yk = (c + mmj) + 1;
        c_st.site = &wb_emlrtRSI;
        if (c + 2 > yk) {
          b_c = false;
        } else {
          b_c = (yk > 2147483646);
        }

        if (b_c) {
          d_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (k = c + 1; k + 1 <= yk; k++) {
          A_data_re = A_data[k].re;
          A_data_im = A_data[k].im;
          b_A_data_re = A_data[c].re;
          b_A_data_im = A_data[c].im;
          if (b_A_data_im == 0.0) {
            if (A_data_im == 0.0) {
              A_data[k].re = A_data_re / b_A_data_re;
              A_data[k].im = 0.0;
            } else if (A_data_re == 0.0) {
              A_data[k].re = 0.0;
              A_data[k].im = A_data_im / b_A_data_re;
            } else {
              A_data[k].re = A_data_re / b_A_data_re;
              A_data[k].im = A_data_im / b_A_data_re;
            }
          } else if (b_A_data_re == 0.0) {
            if (A_data_re == 0.0) {
              A_data[k].re = A_data_im / b_A_data_im;
              A_data[k].im = 0.0;
            } else if (A_data_im == 0.0) {
              A_data[k].re = 0.0;
              A_data[k].im = -(A_data_re / b_A_data_im);
            } else {
              A_data[k].re = A_data_im / b_A_data_im;
              A_data[k].im = -(A_data_re / b_A_data_im);
            }
          } else {
            brm = muDoubleScalarAbs(b_A_data_re);
            bim = muDoubleScalarAbs(b_A_data_im);
            if (brm > bim) {
              s = b_A_data_im / b_A_data_re;
              bim = b_A_data_re + s * b_A_data_im;
              A_data[k].re = (A_data_re + s * A_data_im) / bim;
              A_data[k].im = (A_data_im - s * A_data_re) / bim;
            } else if (bim == brm) {
              if (b_A_data_re > 0.0) {
                s = 0.5;
              } else {
                s = -0.5;
              }

              if (b_A_data_im > 0.0) {
                bim = 0.5;
              } else {
                bim = -0.5;
              }

              A_data[k].re = (A_data_re * s + A_data_im * bim) / brm;
              A_data[k].im = (A_data_im * s - A_data_re * bim) / brm;
            } else {
              s = b_A_data_re / b_A_data_im;
              bim = b_A_data_im + s * b_A_data_re;
              A_data[k].re = (s * A_data_re + A_data_im) / bim;
              A_data[k].im = (s * A_data_im - A_data_re) / bim;
            }
          }
        }
      }

      b_n = n - j;
      c_st.site = &xb_emlrtRSI;
      if ((mmj < 1) || (b_n < 1)) {
      } else {
        m_t = (ptrdiff_t)mmj;
        n_t = (ptrdiff_t)b_n;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)lda;
        lda_t = (ptrdiff_t)lda;
        zgeru(&m_t, &n_t, (real_T *)&alpha1, (real_T *)&A_data[c + 1], &incx_t,
              (real_T *)&A_data[c + lda], &incy_t, (real_T *)&A_data[(c + lda) +
              1], &lda_t);
      }
    }
  }
}

static void eml_xswap(const emlrtStack *sp, int32_T n, creal_T x_data[], int32_T
                      ix0, int32_T incx, int32_T iy0, int32_T incy)
{
  int32_T ix;
  int32_T iy;
  boolean_T b14;
  int32_T k;
  real_T temp_re;
  real_T temp_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &fg_emlrtRSI;
  ix = ix0 - 1;
  iy = iy0 - 1;
  c_st.site = &gg_emlrtRSI;
  if (1 > n) {
    b14 = false;
  } else {
    b14 = (n > 2147483646);
  }

  if (b14) {
    d_st.site = &jb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 1; k <= n; k++) {
    temp_re = x_data[ix].re;
    temp_im = x_data[ix].im;
    x_data[ix] = x_data[iy];
    x_data[iy].re = temp_re;
    x_data[iy].im = temp_im;
    ix += incx;
    iy += incy;
  }
}

void invNxN(const emlrtStack *sp, const creal_T x_data[], const int32_T x_size[2],
            creal_T y_data[], int32_T y_size[2])
{
  int32_T n;
  int32_T k;
  int32_T c;
  creal_T b_x_data[576];
  int32_T ipiv_size[2];
  int32_T ipiv_data[24];
  int32_T p_size[2];
  int32_T p_data[24];
  int32_T j;
  boolean_T b_y_data;
  int32_T i;
  real_T y_data_re;
  real_T y_data_im;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  n = x_size[0];
  y_size[0] = x_size[0];
  y_size[1] = x_size[1];
  k = x_size[0] * x_size[1];
  for (c = 0; c < k; c++) {
    y_data[c].re = 0.0;
    y_data[c].im = 0.0;
  }

  k = x_size[0] * x_size[1];
  for (c = 0; c < k; c++) {
    b_x_data[c] = x_data[c];
  }

  st.site = &nc_emlrtRSI;
  eml_xgetrf(&st, x_size[0], x_size[0], b_x_data, x_size[0], ipiv_data,
             ipiv_size);
  eml_ipiv2perm(ipiv_data, ipiv_size, x_size[0], p_data, p_size);
  st.site = &yf_emlrtRSI;
  for (k = 0; k + 1 <= n; k++) {
    c = p_data[k] - 1;
    y_data[k + y_size[0] * (p_data[k] - 1)].re = 1.0;
    y_data[k + y_size[0] * (p_data[k] - 1)].im = 0.0;
    st.site = &ag_emlrtRSI;
    for (j = k; j + 1 <= n; j++) {
      b_y_data = ((y_data[j + y_size[0] * c].re != 0.0) || (y_data[j + y_size[0]
        * c].im != 0.0));
      if (b_y_data) {
        st.site = &bg_emlrtRSI;
        for (i = j + 1; i + 1 <= n; i++) {
          y_data_re = y_data[j + y_size[0] * c].re * b_x_data[i + x_size[0] * j]
            .re - y_data[j + y_size[0] * c].im * b_x_data[i + x_size[0] * j].im;
          y_data_im = y_data[j + y_size[0] * c].re * b_x_data[i + x_size[0] * j]
            .im + y_data[j + y_size[0] * c].im * b_x_data[i + x_size[0] * j].re;
          y_data[i + y_size[0] * c].re -= y_data_re;
          y_data[i + y_size[0] * c].im -= y_data_im;
        }
      }
    }
  }

  st.site = &oc_emlrtRSI;
  b_eml_xtrsm(x_size[0], x_size[0], b_x_data, x_size[0], y_data, x_size[0]);
}

/* End of code generation (inv.c) */
