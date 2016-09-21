//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: inv.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//

// Include Files
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "inv.h"
#include "rdivide.h"

// Function Declarations
static void b_eml_xtrsm(int m, int n, const creal_T A_data[], int lda, creal_T
  B_data[], int B_size[2], int ldb);
static void eml_ipiv2perm(const int ipiv_data[], const int ipiv_size[2], int m,
  int perm_data[], int perm_size[2]);
static void eml_xgetrf(int m, int n, creal_T A_data[], int lda, int ipiv_data[],
  int ipiv_size[2]);
static void eml_xswap(int n, creal_T x_data[], int ix0, int incx, int iy0, int
                      incy);

// Function Definitions

//
// Arguments    : int m
//                int n
//                const creal_T A_data[]
//                int lda
//                creal_T B_data[]
//                int B_size[2]
//                int ldb
// Return Type  : void
//
static void b_eml_xtrsm(int m, int n, const creal_T A_data[], int lda, creal_T
  B_data[], int B_size[2], int ldb)
{
  int j;
  int jBcol;
  int k;
  int kAcol;
  int i;
  double B_data_im;
  if ((n == 0) || ((B_size[0] == 0) || (B_size[1] == 0))) {
  } else {
    for (j = 1; j <= n; j++) {
      jBcol = ldb * (j - 1) - 1;
      for (k = m; k > 0; k--) {
        kAcol = lda * (k - 1) - 1;
        if ((B_data[k + jBcol].re != 0.0) || (B_data[k + jBcol].im != 0.0)) {
          B_data[k + jBcol] = rdivide(B_data[k + jBcol], A_data[k + kAcol]);
          for (i = 1; i < k; i++) {
            B_data_im = B_data[k + jBcol].re * A_data[i + kAcol].im + B_data[k +
              jBcol].im * A_data[i + kAcol].re;
            B_data[i + jBcol].re -= B_data[k + jBcol].re * A_data[i + kAcol].re
              - B_data[k + jBcol].im * A_data[i + kAcol].im;
            B_data[i + jBcol].im -= B_data_im;
          }
        }
      }
    }
  }
}

//
// Arguments    : const int ipiv_data[]
//                const int ipiv_size[2]
//                int m
//                int perm_data[]
//                int perm_size[2]
// Return Type  : void
//
static void eml_ipiv2perm(const int ipiv_data[], const int ipiv_size[2], int m,
  int perm_data[], int perm_size[2])
{
  int n;
  int yk;
  int k;
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

//
// Arguments    : int m
//                int n
//                creal_T A_data[]
//                int lda
//                int ipiv_data[]
//                int ipiv_size[2]
// Return Type  : void
//
static void eml_xgetrf(int m, int n, creal_T A_data[], int lda, int ipiv_data[],
  int ipiv_size[2])
{
  int b_n;
  int yk;
  int jy;
  int i14;
  int j;
  int mmj;
  int c;
  int ix;
  double smax;
  double s;
  int i15;
  double A_data_re;
  double A_data_im;
  double b_A_data_re;
  double b_A_data_im;
  double brm;
  int b_j;
  int ijA;
  if (m <= n) {
    b_n = m;
  } else {
    b_n = n;
  }

  if (b_n < 1) {
    b_n = 0;
  }

  ipiv_size[0] = 1;
  ipiv_size[1] = b_n;
  if (b_n > 0) {
    ipiv_data[0] = 1;
    yk = 1;
    for (jy = 2; jy <= b_n; jy++) {
      yk++;
      ipiv_data[jy - 1] = yk;
    }
  }

  if ((m < 1) || (n < 1)) {
  } else {
    if (m - 1 <= n) {
      i14 = m - 1;
    } else {
      i14 = n;
    }

    for (j = 1; j <= i14; j++) {
      mmj = (m - j) + 1;
      c = (j - 1) * (lda + 1);
      if (mmj < 1) {
        b_n = -1;
      } else {
        b_n = 0;
        if (mmj > 1) {
          ix = c;
          smax = fabs(A_data[c].re) + fabs(A_data[c].im);
          for (jy = 1; jy + 1 <= mmj; jy++) {
            ix++;
            s = fabs(A_data[ix].re) + fabs(A_data[ix].im);
            if (s > smax) {
              b_n = jy;
              smax = s;
            }
          }
        }
      }

      if ((A_data[c + b_n].re != 0.0) || (A_data[c + b_n].im != 0.0)) {
        if (b_n != 0) {
          ipiv_data[j - 1] = j + b_n;
          eml_xswap(n, A_data, j, lda, j + b_n, lda);
        }

        i15 = c + mmj;
        for (b_n = c + 1; b_n + 1 <= i15; b_n++) {
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
            brm = fabs(b_A_data_re);
            smax = fabs(b_A_data_im);
            if (brm > smax) {
              s = b_A_data_im / b_A_data_re;
              smax = b_A_data_re + s * b_A_data_im;
              A_data[b_n].re = (A_data_re + s * A_data_im) / smax;
              A_data[b_n].im = (A_data_im - s * A_data_re) / smax;
            } else if (smax == brm) {
              if (b_A_data_re > 0.0) {
                s = 0.5;
              } else {
                s = -0.5;
              }

              if (b_A_data_im > 0.0) {
                smax = 0.5;
              } else {
                smax = -0.5;
              }

              A_data[b_n].re = (A_data_re * s + A_data_im * smax) / brm;
              A_data[b_n].im = (A_data_im * s - A_data_re * smax) / brm;
            } else {
              s = b_A_data_re / b_A_data_im;
              smax = b_A_data_im + s * b_A_data_re;
              A_data[b_n].re = (s * A_data_re + A_data_im) / smax;
              A_data[b_n].im = (s * A_data_im - A_data_re) / smax;
            }
          }
        }
      }

      b_n = n - j;
      yk = c + lda;
      jy = c + lda;
      for (b_j = 1; b_j <= b_n; b_j++) {
        if ((A_data[jy].re != 0.0) || (A_data[jy].im != 0.0)) {
          smax = -A_data[jy].re - A_data[jy].im * 0.0;
          s = A_data[jy].re * 0.0 + -A_data[jy].im;
          ix = c + 1;
          i15 = mmj + yk;
          for (ijA = 1 + yk; ijA + 1 <= i15; ijA++) {
            A_data_im = A_data[ix].re * s + A_data[ix].im * smax;
            A_data[ijA].re += A_data[ix].re * smax - A_data[ix].im * s;
            A_data[ijA].im += A_data_im;
            ix++;
          }
        }

        jy += lda;
        yk += lda;
      }
    }
  }
}

//
// Arguments    : int n
//                creal_T x_data[]
//                int ix0
//                int incx
//                int iy0
//                int incy
// Return Type  : void
//
static void eml_xswap(int n, creal_T x_data[], int ix0, int incx, int iy0, int
                      incy)
{
  int ix;
  int iy;
  int k;
  double temp_re;
  double temp_im;
  ix = ix0 - 1;
  iy = iy0 - 1;
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

//
// Arguments    : const creal_T x_data[]
//                const int x_size[2]
//                creal_T y_data[]
//                int y_size[2]
// Return Type  : void
//
void invNxN(const creal_T x_data[], const int x_size[2], creal_T y_data[], int
            y_size[2])
{
  int n;
  int k;
  int c;
  creal_T b_x_data[576];
  int ipiv_size[2];
  int ipiv_data[24];
  int p_size[2];
  int p_data[24];
  int j;
  int i;
  double y_data_im;
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

  eml_xgetrf(x_size[0], x_size[0], b_x_data, x_size[0], ipiv_data, ipiv_size);
  eml_ipiv2perm(ipiv_data, ipiv_size, x_size[0], p_data, p_size);
  for (k = 0; k + 1 <= n; k++) {
    c = p_data[k] - 1;
    y_data[k + y_size[0] * (p_data[k] - 1)].re = 1.0;
    y_data[k + y_size[0] * (p_data[k] - 1)].im = 0.0;
    for (j = k; j + 1 <= n; j++) {
      if ((y_data[j + y_size[0] * c].re != 0.0) || (y_data[j + y_size[0] * c].im
           != 0.0)) {
        for (i = j + 1; i + 1 <= n; i++) {
          y_data_im = y_data[j + y_size[0] * c].re * b_x_data[i + x_size[0] * j]
            .im + y_data[j + y_size[0] * c].im * b_x_data[i + x_size[0] * j].re;
          y_data[i + y_size[0] * c].re -= y_data[j + y_size[0] * c].re *
            b_x_data[i + x_size[0] * j].re - y_data[j + y_size[0] * c].im *
            b_x_data[i + x_size[0] * j].im;
          y_data[i + y_size[0] * c].im -= y_data_im;
        }
      }
    }
  }

  b_eml_xtrsm(x_size[0], x_size[0], b_x_data, x_size[0], y_data, y_size, x_size
              [0]);
}

//
// File trailer for inv.cpp
//
// [EOF]
//
