//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mpower.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 05-Jul-2015 23:05:44
//

// Include Files
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "mpower.h"

// Function Definitions

//
// Arguments    : double A[16]
//                int ipiv[4]
//                int *info
// Return Type  : void
//
void eml_lapack_xgetrf(double A[16], int ipiv[4], int *info)
{
  int i7;
  int j;
  int c;
  int iy;
  int ix;
  double smax;
  int jy;
  double s;
  int b_j;
  int ijA;
  for (i7 = 0; i7 < 4; i7++) {
    ipiv[i7] = 1 + i7;
  }

  *info = 0;
  for (j = 0; j < 3; j++) {
    c = j * 5;
    iy = 0;
    ix = c;
    smax = fabs(A[c]);
    for (jy = 2; jy <= 4 - j; jy++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        iy = jy - 1;
        smax = s;
      }
    }

    if (A[c + iy] != 0.0) {
      if (iy != 0) {
        ipiv[j] = (j + iy) + 1;
        ix = j;
        iy += j;
        for (jy = 0; jy < 4; jy++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 4;
          iy += 4;
        }
      }

      i7 = (c - j) + 4;
      for (iy = c + 1; iy + 1 <= i7; iy++) {
        A[iy] /= A[c];
      }
    } else {
      *info = j + 1;
    }

    iy = c;
    jy = c + 4;
    for (b_j = 1; b_j <= 3 - j; b_j++) {
      smax = A[jy];
      if (A[jy] != 0.0) {
        ix = c + 1;
        i7 = (iy - j) + 8;
        for (ijA = 5 + iy; ijA + 1 <= i7; ijA++) {
          A[ijA] += A[ix] * -smax;
          ix++;
        }
      }

      jy += 4;
      iy += 4;
    }
  }

  if ((*info == 0) && (!(A[15] != 0.0))) {
    *info = 4;
  }
}

//
// Arguments    : const double A[16]
//                double B[16]
// Return Type  : void
//
void eml_xtrsm(const double A[16], double B[16])
{
  int j;
  int jBcol;
  int k;
  int kAcol;
  int i;
  for (j = 0; j < 4; j++) {
    jBcol = j << 2;
    for (k = 3; k > -1; k += -1) {
      kAcol = k << 2;
      if (B[k + jBcol] != 0.0) {
        B[k + jBcol] /= A[k + kAcol];
        for (i = 0; i + 1 <= k; i++) {
          B[i + jBcol] -= B[k + jBcol] * A[i + kAcol];
        }
      }
    }
  }
}

//
// Arguments    : const double a[16]
//                double c[16]
// Return Type  : void
//
void mpower(const double a[16], double c[16])
{
  double x[16];
  int b_c;
  int ipiv[4];
  signed char p[4];
  int k;
  int j;
  int i;
  for (b_c = 0; b_c < 16; b_c++) {
    c[b_c] = 0.0;
    x[b_c] = a[b_c];
  }

  eml_lapack_xgetrf(x, ipiv, &b_c);
  for (b_c = 0; b_c < 4; b_c++) {
    p[b_c] = (signed char)(1 + b_c);
  }

  for (k = 0; k < 3; k++) {
    if (ipiv[k] > 1 + k) {
      b_c = p[ipiv[k] - 1];
      p[ipiv[k] - 1] = p[k];
      p[k] = (signed char)b_c;
    }
  }

  for (k = 0; k < 4; k++) {
    b_c = p[k] - 1;
    c[k + ((p[k] - 1) << 2)] = 1.0;
    for (j = k; j + 1 < 5; j++) {
      if (c[j + (b_c << 2)] != 0.0) {
        for (i = j + 1; i + 1 < 5; i++) {
          c[i + (b_c << 2)] -= c[j + (b_c << 2)] * x[i + (j << 2)];
        }
      }
    }
  }

  eml_xtrsm(x, c);
}

//
// File trailer for mpower.cpp
//
// [EOF]
//
