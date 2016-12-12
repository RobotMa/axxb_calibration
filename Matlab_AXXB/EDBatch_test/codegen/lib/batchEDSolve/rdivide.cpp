//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rdivide.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//

// Include Files
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "rdivide.h"

// Function Definitions

//
// Arguments    : const creal_T x
//                const creal_T y
// Return Type  : creal_T
//
creal_T rdivide(const creal_T x, const creal_T y)
{
  creal_T z;
  double brm;
  double bim;
  double d;
  if (y.im == 0.0) {
    if (x.im == 0.0) {
      z.re = x.re / y.re;
      z.im = 0.0;
    } else if (x.re == 0.0) {
      z.re = 0.0;
      z.im = x.im / y.re;
    } else {
      z.re = x.re / y.re;
      z.im = x.im / y.re;
    }
  } else if (y.re == 0.0) {
    if (x.re == 0.0) {
      z.re = x.im / y.im;
      z.im = 0.0;
    } else if (x.im == 0.0) {
      z.re = 0.0;
      z.im = -(x.re / y.im);
    } else {
      z.re = x.im / y.im;
      z.im = -(x.re / y.im);
    }
  } else {
    brm = fabs(y.re);
    bim = fabs(y.im);
    if (brm > bim) {
      bim = y.im / y.re;
      d = y.re + bim * y.im;
      z.re = (x.re + bim * x.im) / d;
      z.im = (x.im - bim * x.re) / d;
    } else if (bim == brm) {
      if (y.re > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (y.im > 0.0) {
        d = 0.5;
      } else {
        d = -0.5;
      }

      z.re = (x.re * bim + x.im * d) / brm;
      z.im = (x.im * bim - x.re * d) / brm;
    } else {
      bim = y.re / y.im;
      d = y.im + bim * y.re;
      z.re = (bim * x.re + x.im) / d;
      z.im = (bim * x.im - x.re) / d;
    }
  }

  return z;
}

//
// File trailer for rdivide.cpp
//
// [EOF]
//
