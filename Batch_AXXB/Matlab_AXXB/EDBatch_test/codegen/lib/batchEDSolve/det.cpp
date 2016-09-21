//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: det.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//

// Include Files
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "det.h"

// Function Declarations
static void b_eml_xgetrf(int n, creal_T A_data[], int ipiv_data[], int
  ipiv_size[2]);

// Function Definitions

//
// Arguments    : int n
//                creal_T A_data[]
//                int ipiv_data[]
//                int ipiv_size[2]
// Return Type  : void
//
static void b_eml_xgetrf(int n, creal_T A_data[], int ipiv_data[], int
  ipiv_size[2])
{
  int yk;
  int b_n;
  int y_data[24];
  int jy;
  int i16;
  int j;
  int c;
  int ix;
  double smax;
  double brm;
  double temp_im;
  int i17;
  double A_data_re;
  double A_data_im;
  double b_A_data_im;
  int b_j;
  int ijA;
  if (3 <= n) {
    yk = 3;
  } else {
    yk = n;
  }

  if (yk < 1) {
    b_n = 0;
  } else {
    b_n = yk;
  }

  if (b_n > 0) {
    y_data[0] = 1;
    yk = 1;
    for (jy = 2; jy <= b_n; jy++) {
      yk++;
      y_data[jy - 1] = yk;
    }
  }

  ipiv_size[0] = 1;
  ipiv_size[1] = b_n;
  for (i16 = 0; i16 < b_n; i16++) {
    ipiv_data[i16] = y_data[i16];
  }

  if (n < 1) {
  } else {
    if (2 <= n) {
      i16 = 2;
    } else {
      i16 = 1;
    }

    for (j = 1; j <= i16; j++) {
      c = (j - 1) << 2;
      yk = 0;
      ix = c;
      smax = fabs(A_data[c].re) + fabs(A_data[c].im);
      for (jy = 1; jy + 1 <= 4 - j; jy++) {
        ix++;
        brm = fabs(A_data[ix].re) + fabs(A_data[ix].im);
        if (brm > smax) {
          yk = jy;
          smax = brm;
        }
      }

      if ((A_data[c + yk].re != 0.0) || (A_data[c + yk].im != 0.0)) {
        if (yk != 0) {
          ipiv_data[j - 1] = j + yk;
          ix = j - 1;
          yk = (j + yk) - 1;
          for (jy = 1; jy <= n; jy++) {
            smax = A_data[ix].re;
            temp_im = A_data[ix].im;
            A_data[ix] = A_data[yk];
            A_data[yk].re = smax;
            A_data[yk].im = temp_im;
            ix += 3;
            yk += 3;
          }
        }

        i17 = (c - j) + 4;
        for (yk = c + 1; yk + 1 <= i17; yk++) {
          A_data_re = A_data[yk].re;
          A_data_im = A_data[yk].im;
          temp_im = A_data[c].re;
          b_A_data_im = A_data[c].im;
          if (b_A_data_im == 0.0) {
            if (A_data_im == 0.0) {
              A_data[yk].re = A_data_re / temp_im;
              A_data[yk].im = 0.0;
            } else if (A_data_re == 0.0) {
              A_data[yk].re = 0.0;
              A_data[yk].im = A_data_im / temp_im;
            } else {
              A_data[yk].re = A_data_re / temp_im;
              A_data[yk].im = A_data_im / temp_im;
            }
          } else if (temp_im == 0.0) {
            if (A_data_re == 0.0) {
              A_data[yk].re = A_data_im / b_A_data_im;
              A_data[yk].im = 0.0;
            } else if (A_data_im == 0.0) {
              A_data[yk].re = 0.0;
              A_data[yk].im = -(A_data_re / b_A_data_im);
            } else {
              A_data[yk].re = A_data_im / b_A_data_im;
              A_data[yk].im = -(A_data_re / b_A_data_im);
            }
          } else {
            brm = fabs(temp_im);
            smax = fabs(b_A_data_im);
            if (brm > smax) {
              brm = b_A_data_im / temp_im;
              smax = temp_im + brm * b_A_data_im;
              A_data[yk].re = (A_data_re + brm * A_data_im) / smax;
              A_data[yk].im = (A_data_im - brm * A_data_re) / smax;
            } else if (smax == brm) {
              if (temp_im > 0.0) {
                temp_im = 0.5;
              } else {
                temp_im = -0.5;
              }

              if (b_A_data_im > 0.0) {
                smax = 0.5;
              } else {
                smax = -0.5;
              }

              A_data[yk].re = (A_data_re * temp_im + A_data_im * smax) / brm;
              A_data[yk].im = (A_data_im * temp_im - A_data_re * smax) / brm;
            } else {
              brm = temp_im / b_A_data_im;
              smax = b_A_data_im + brm * temp_im;
              A_data[yk].re = (brm * A_data_re + A_data_im) / smax;
              A_data[yk].im = (brm * A_data_im - A_data_re) / smax;
            }
          }
        }
      }

      yk = n - j;
      b_n = c;
      jy = c + 3;
      for (b_j = 1; b_j <= yk; b_j++) {
        if ((A_data[jy].re != 0.0) || (A_data[jy].im != 0.0)) {
          smax = -A_data[jy].re - A_data[jy].im * 0.0;
          temp_im = A_data[jy].re * 0.0 + -A_data[jy].im;
          ix = c + 1;
          i17 = (b_n - j) + 7;
          for (ijA = 4 + b_n; ijA + 1 <= i17; ijA++) {
            A_data_im = A_data[ix].re * temp_im + A_data[ix].im * smax;
            A_data[ijA].re += A_data[ix].re * smax - A_data[ix].im * temp_im;
            A_data[ijA].im += A_data_im;
            ix++;
          }
        }

        jy += 3;
        b_n += 3;
      }
    }
  }
}

//
// Arguments    : const creal_T x_data[]
//                const int x_size[2]
// Return Type  : creal_T
//
creal_T det(const creal_T x_data[], const int x_size[2])
{
  creal_T y;
  int loop_ub;
  int i11;
  creal_T b_x_data[72];
  int ipiv_size[2];
  int ipiv_data[3];
  double y_re;
  boolean_T isodd;
  if (x_size[1] == 0) {
    y.re = 1.0;
    y.im = 0.0;
  } else {
    loop_ub = x_size[0] * x_size[1];
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_x_data[i11] = x_data[i11];
    }

    b_eml_xgetrf(x_size[1], b_x_data, ipiv_data, ipiv_size);
    y = b_x_data[0];
    for (loop_ub = 0; loop_ub < 2; loop_ub++) {
      y_re = y.re;
      y.re = y.re * b_x_data[(loop_ub + 3 * (1 + loop_ub)) + 1].re - y.im *
        b_x_data[(loop_ub + 3 * (1 + loop_ub)) + 1].im;
      y.im = y_re * b_x_data[(loop_ub + 3 * (1 + loop_ub)) + 1].im + y.im *
        b_x_data[(loop_ub + 3 * (1 + loop_ub)) + 1].re;
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

//
// File trailer for det.cpp
//
// [EOF]
//
