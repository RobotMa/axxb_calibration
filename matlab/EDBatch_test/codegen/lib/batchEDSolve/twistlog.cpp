//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: twistlog.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//

// Include Files
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "twistlog.h"

// Function Definitions

//
// TWISTLOG  calculate the log of a homogeneous transformation
//
//  [XI_HAT] = TWISTLOG(H)
//
//  See also: TWIST, SKEWEXP, TWISTEXP, SKEWLOG.
// Arguments    : const emxArray_real_T *h
//                double xi_hat[16]
// Return Type  : void
//
void twistlog(const emxArray_real_T *h, double xi_hat[16])
{
  double R[9];
  int iy;
  int i;
  double A_inv[9];
  static const signed char b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  double m[3];
  int ix;
  int b_ix;
  double mtmp;
  int c_ix;
  boolean_T exitg3;
  boolean_T y;
  boolean_T exitg2;
  double w_hat[9];
  double t;
  double val;
  double theta;
  double B;
  double w[3];
  double w_norm;
  double scale;
  double absxk;
  double b_y[3];
  boolean_T exitg1;
  double x[9];
  double c_y;
  double d1;
  double b_A_inv;

  //  $Id: twistlog.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $
  //  Copyright (C) 2005, by Brad Kratochvil
  //  this algorithm from Murray pg. 414
  //  Commented out for .mex
  //  global DebugLevel;
  //
  //  if isempty(DebugLevel) || (DebugLevel > 1)
  //    if ~isrot(h(1:3,1:3)),
  //      error('ROBOTLINKS:skewlog','H is not a homogeneous transformation')
  //    end
  //  end
  for (iy = 0; iy < 3; iy++) {
    for (i = 0; i < 3; i++) {
      R[i + 3 * iy] = h->data[i + h->size[0] * iy];
    }
  }

  // SKEWLOG  calculate the log of a rotation matrix
  //
  // 	[W_HAT] = SKEWLOG(R)
  //
  //
  //  See also: TWIST, SKEWEXP, TWISTEXP, TWISTLOG.
  //  $Id: skewlog.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $
  //  Copyright (C) 2005, by Brad Kratochvil
  //  this algorithm from Murray pg. 414
  //  Commented out for .mex
  //  global DebugLevel;
  //
  //  if isempty(DebugLevel) || (DebugLevel > 1)
  //    if ~isrot(R),
  //      error('ROBOTLINKS:skewlog','R is not a rotation matrix')
  //    end
  //  end
  // ISEQUALF  Returns true if the two quantities are equal within a threshold
  //
  // 	t = ISEQUALF(A, B)
  // 	[t reason] = ISEQUALF(A, B, THRESH)
  //
  //  This function is useful for floating point values, where there may be
  //  a small difference.
  //
  //  See also: ISEQUAL.
  //  $Id: isequalf.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $
  //  Copyright (C) 2005, by Brad Kratochvil
  for (iy = 0; iy < 9; iy++) {
    A_inv[iy] = fabs(R[iy] - (double)b[iy]);
  }

  ix = 0;
  iy = -1;
  for (i = 0; i < 3; i++) {
    ix += 3;
    b_ix = ix - 2;
    mtmp = A_inv[ix - 3];
    if (rtIsNaN(A_inv[ix - 3])) {
      c_ix = ix - 1;
      exitg3 = false;
      while ((!exitg3) && (c_ix <= ix)) {
        b_ix = c_ix;
        if (!rtIsNaN(A_inv[c_ix - 1])) {
          mtmp = A_inv[c_ix - 1];
          exitg3 = true;
        } else {
          c_ix++;
        }
      }
    }

    if (b_ix < ix) {
      while (b_ix + 1 <= ix) {
        if (A_inv[b_ix] > mtmp) {
          mtmp = A_inv[b_ix];
        }

        b_ix++;
      }
    }

    iy++;
    m[iy] = mtmp;
  }

  y = false;
  iy = 0;
  exitg2 = false;
  while ((!exitg2) && (iy < 3)) {
    if (!!(m[iy] > 1.0E-6)) {
      y = true;
      exitg2 = true;
    } else {
      iy++;
    }
  }

  if (!y) {
    memset(&w_hat[0], 0, 9U * sizeof(double));
  } else {
    t = 0.0;
    for (iy = 0; iy < 3; iy++) {
      t += h->data[iy + h->size[0] * iy];
    }

    val = (t - 1.0) / 2.0;

    //  this is to clamp the values to +-1, which sometimes
    //  doesn't happen due to floating point noise
    if (val > 1.0) {
      val = 1.0;
    } else {
      if (val < -1.0) {
        val = -1.0;
      }
    }

    theta = acos(val);
    if (0.0 == theta) {
      memset(&w_hat[0], 0, 9U * sizeof(double));
    } else {
      B = 2.0 * sin(theta);
      for (iy = 0; iy < 3; iy++) {
        for (i = 0; i < 3; i++) {
          w_hat[i + 3 * iy] = (R[i + 3 * iy] - R[iy + 3 * i]) / B * theta;
        }
      }
    }
  }

  // SKEWCOORDS  generates a vector w given a skew-symmetric matrix R
  //
  // 	w = SKEWCOORDS(R)
  //
  //  See also: ROTAXIS, SKEWEXP, SKEW.
  //  $Id: skewcoords.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $
  //  Copyright (C) 2005, by Brad Kratochvil
  w[0] = w_hat[5];
  w[1] = w_hat[6];
  w[2] = w_hat[1];
  w_norm = 0.0;
  scale = 2.2250738585072014E-308;
  for (iy = 0; iy < 3; iy++) {
    absxk = fabs(w[iy]);
    if (absxk > scale) {
      t = scale / absxk;
      w_norm = 1.0 + w_norm * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      w_norm += t * t;
    }
  }

  w_norm = scale * sqrt(w_norm);

  // ISEQUALF  Returns true if the two quantities are equal within a threshold
  //
  // 	t = ISEQUALF(A, B)
  // 	[t reason] = ISEQUALF(A, B, THRESH)
  //
  //  This function is useful for floating point values, where there may be
  //  a small difference.
  //
  //  See also: ISEQUAL.
  //  $Id: isequalf.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $
  //  Copyright (C) 2005, by Brad Kratochvil
  //  it's machine dependent now
  for (iy = 0; iy < 3; iy++) {
    w[iy] = 0.0 - h->data[iy + h->size[0] * 3];
  }

  for (iy = 0; iy < 3; iy++) {
    b_y[iy] = fabs(w[iy]);
  }

  iy = 1;
  mtmp = b_y[0];
  if (rtIsNaN(b_y[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 4)) {
      iy = ix;
      if (!rtIsNaN(b_y[ix - 1])) {
        mtmp = b_y[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (iy < 3) {
    while (iy + 1 < 4) {
      if (b_y[iy] > mtmp) {
        mtmp = b_y[iy];
      }

      iy++;
    }
  }

  if (!!!(mtmp > 2.2204460492503131E-14)) {
    memset(&A_inv[0], 0, 9U * sizeof(double));
  } else if ((0.0 == sin(w_norm)) || (0.0 == w_norm)) {
    memset(&A_inv[0], 0, 9U * sizeof(double));
    for (iy = 0; iy < 3; iy++) {
      A_inv[iy + 3 * iy] = 1.0;
    }
  } else {
    memset(&x[0], 0, 9U * sizeof(double));
    for (iy = 0; iy < 3; iy++) {
      x[iy + 3 * iy] = 1.0;
    }

    c_y = (2.0 * sin(w_norm) - w_norm * (1.0 + cos(w_norm))) / (2.0 * (w_norm *
      w_norm) * sin(w_norm));
    for (iy = 0; iy < 3; iy++) {
      for (i = 0; i < 3; i++) {
        d1 = 0.0;
        for (c_ix = 0; c_ix < 3; c_ix++) {
          d1 += c_y * w_hat[iy + 3 * c_ix] * w_hat[c_ix + 3 * i];
        }

        A_inv[iy + 3 * i] = (x[iy + 3 * i] - w_hat[iy + 3 * i] / 2.0) + d1;
      }
    }
  }

  for (iy = 0; iy < 3; iy++) {
    b_y[iy] = 0.0;
    for (i = 0; i < 3; i++) {
      b_A_inv = b_y[iy] + A_inv[iy + 3 * i] * h->data[i + h->size[0] * 3];
      b_y[iy] = b_A_inv;
    }
  }

  for (iy = 0; iy < 3; iy++) {
    for (i = 0; i < 3; i++) {
      xi_hat[i + (iy << 2)] = w_hat[i + 3 * iy];
    }
  }

  for (iy = 0; iy < 3; iy++) {
    xi_hat[12 + iy] = b_y[iy];
  }

  for (iy = 0; iy < 4; iy++) {
    xi_hat[3 + (iy << 2)] = 0.0;
  }
}

//
// File trailer for twistlog.cpp
//
// [EOF]
//
