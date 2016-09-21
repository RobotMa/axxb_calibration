/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * twistlog.c
 *
 * Code generation for function 'twistlog'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "twistlog.h"
#include "eml_int_forloop_overflow_check.h"
#include "distibutionPropsMex_data.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 22, "twistlog",
  "/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws/twistlog.m"
};

static emlrtRSInfo o_emlrtRSI = { 23, "twistlog",
  "/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws/twistlog.m"
};

static emlrtRSInfo p_emlrtRSI = { 23, "skewlog",
  "/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws/skewlog.m"
};

static emlrtRSInfo q_emlrtRSI = { 23, "isequalf",
  "/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/util/isequalf.m"
};

static emlrtRSInfo r_emlrtRSI = { 16, "max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/datafun/max.m" };

static emlrtRSInfo s_emlrtRSI = { 18, "eml_min_or_max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

static emlrtRSInfo t_emlrtRSI = { 108, "eml_min_or_max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

static emlrtRSInfo u_emlrtRSI = { 229, "eml_min_or_max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

static emlrtRSInfo v_emlrtRSI = { 202, "eml_min_or_max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

static emlrtRSInfo x_emlrtRSI = { 12, "skewcoords",
  "/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws/skewcoords.m"
};

static emlrtMCInfo emlrtMCI = { 20, 5, "error",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/lang/error.m" };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 26, 12, "h", "twistlog",
  "/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws/twistlog.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 22, 24, "h", "twistlog",
  "/home/roma/Dropbox/2014Summer/Robotics Research/kinematics/kinematics/screws/twistlog.m",
  0 };

static emlrtRSInfo hd_emlrtRSI = { 20, "error",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/lang/error.m" };

/* Function Declarations */
static void error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  emlrtMCInfo *location);

/* Function Definitions */
static void error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                  emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

void twistlog(const emlrtStack *sp, const emxArray_real_T *h, real_T xi_hat[16])
{
  real_T R[9];
  int32_T iy;
  int32_T i;
  int32_T ix;
  int32_T b_ix;
  int32_T c_ix;
  real_T A_inv[9];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T m[3];
  int32_T d_ix;
  real_T mtmp;
  boolean_T e_ix;
  boolean_T exitg4;
  boolean_T f_ix;
  boolean_T y;
  boolean_T exitg3;
  real_T w_hat[9];
  real_T t;
  real_T val;
  real_T theta;
  real_T B;
  real_T x[9];
  boolean_T p;
  boolean_T b_p;
  boolean_T exitg2;
  static const char_T varargin_1[17] = { 'S', 'C', 'R', 'E', 'W', 'S', ':', 's',
    'k', 'e', 'w', 'c', 'o', 'o', 'r', 'd', 's' };

  char_T u[17];
  const mxArray *b_y;
  static const int32_T iv6[2] = { 1, 17 };

  const mxArray *m0;
  static const char_T varargin_2[37] = { 'R', ' ', 'm', 'u', 's', 't', ' ', 'b',
    'e', ' ', 'a', ' ', '3', 'x', '3', ' ', 's', 'k', 'e', 'w', '-', 's', 'y',
    'm', 'm', 'e', 't', 'r', 'i', 'c', ' ', 'm', 'a', 't', 'r', 'i', 'x' };

  char_T b_u[37];
  const mxArray *c_y;
  static const int32_T iv7[2] = { 1, 37 };

  real_T w[3];
  real_T w_norm;
  real_T scale;
  real_T absxk;
  real_T d_y[3];
  boolean_T exitg1;
  real_T e_y;
  real_T d1;
  real_T b_A_inv;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  st.prev = sp;
  st.tls = sp->tls;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;

  /* TWISTLOG  calculate the log of a homogeneous transformation */
  /*  */
  /* 	[XI_HAT] = TWISTLOG(H) */
  /*  */
  /*  See also: TWIST, SKEWEXP, TWISTEXP, SKEWLOG. */
  /*  $Id: twistlog.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $ */
  /*  Copyright (C) 2005, by Brad Kratochvil */
  /*  this algorithm from Murray pg. 414 */
  /*  Commented out for .mex */
  /*  global DebugLevel; */
  /*   */
  /*  if isempty(DebugLevel) || (DebugLevel > 1) */
  /*    if ~isrot(h(1:3,1:3)), */
  /*      error('ROBOTLINKS:skewlog','H is not a homogeneous transformation') */
  /*    end */
  /*  end */
  st.site = &n_emlrtRSI;
  for (iy = 0; iy < 3; iy++) {
    for (i = 0; i < 3; i++) {
      ix = h->size[1];
      b_ix = 1 + iy;
      if (b_ix < ix) {
        c_ix = b_ix;
      } else {
        c_ix = emlrtDynamicBoundsCheckR2012b(b_ix, 1, ix, &g_emlrtBCI, &st);
      }

      R[i + 3 * iy] = h->data[i + h->size[0] * (c_ix - 1)];
    }
  }

  /* SKEWLOG  calculate the log of a rotation matrix */
  /*  */
  /* 	[W_HAT] = SKEWLOG(R) */
  /*  */
  /*  */
  /*  See also: TWIST, SKEWEXP, TWISTEXP, TWISTLOG. */
  /*  $Id: skewlog.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $ */
  /*  Copyright (C) 2005, by Brad Kratochvil */
  /*  this algorithm from Murray pg. 414 */
  /*  Commented out for .mex */
  /*  global DebugLevel; */
  /*   */
  /*  if isempty(DebugLevel) || (DebugLevel > 1) */
  /*    if ~isrot(R), */
  /*      error('ROBOTLINKS:skewlog','R is not a rotation matrix') */
  /*    end */
  /*  end */
  b_st.site = &p_emlrtRSI;

  /* ISEQUALF  Returns true if the two quantities are equal within a threshold */
  /*  */
  /* 	t = ISEQUALF(A, B) */
  /* 	[t reason] = ISEQUALF(A, B, THRESH) */
  /*  */
  /*  This function is useful for floating point values, where there may be */
  /*  a small difference. */
  /*  */
  /*  See also: ISEQUAL. */
  /*  $Id: isequalf.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $ */
  /*  Copyright (C) 2005, by Brad Kratochvil */
  for (iy = 0; iy < 9; iy++) {
    A_inv[iy] = muDoubleScalarAbs(R[iy] - (real_T)b[iy]);
  }

  c_st.site = &q_emlrtRSI;
  d_st.site = &r_emlrtRSI;
  e_st.site = &s_emlrtRSI;
  d_ix = 0;
  iy = -1;
  for (i = 0; i < 3; i++) {
    d_ix += 3;
    f_st.site = &t_emlrtRSI;
    b_ix = d_ix - 2;
    mtmp = A_inv[d_ix - 3];
    if (muDoubleScalarIsNaN(A_inv[d_ix - 3])) {
      g_st.site = &v_emlrtRSI;
      if (d_ix - 1 > d_ix) {
        e_ix = false;
      } else {
        e_ix = (d_ix > 2147483646);
      }

      if (e_ix) {
        h_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      ix = d_ix - 1;
      exitg4 = false;
      while ((!exitg4) && (ix <= d_ix)) {
        b_ix = ix;
        if (!muDoubleScalarIsNaN(A_inv[ix - 1])) {
          mtmp = A_inv[ix - 1];
          exitg4 = true;
        } else {
          ix++;
        }
      }
    }

    if (b_ix < d_ix) {
      g_st.site = &u_emlrtRSI;
      if (b_ix + 1 > d_ix) {
        f_ix = false;
      } else {
        f_ix = (d_ix > 2147483646);
      }

      if (f_ix) {
        h_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      while (b_ix + 1 <= d_ix) {
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
  exitg3 = false;
  while ((!exitg3) && (iy < 3)) {
    if (!!(m[iy] > 1.0E-6)) {
      y = true;
      exitg3 = true;
    } else {
      iy++;
    }
  }

  if (!y) {
    memset(&w_hat[0], 0, 9U * sizeof(real_T));
  } else {
    t = 0.0;
    for (iy = 0; iy < 3; iy++) {
      t += h->data[iy + h->size[0] * iy];
    }

    val = (t - 1.0) / 2.0;

    /*  this is to clamp the values to +-1, which sometimes */
    /*  doesn't happen due to floating point noise */
    if (val > 1.0) {
      val = 1.0;
    } else {
      if (val < -1.0) {
        val = -1.0;
      }
    }

    theta = muDoubleScalarAcos(val);
    if (0.0 == theta) {
      memset(&w_hat[0], 0, 9U * sizeof(real_T));
    } else {
      B = 2.0 * muDoubleScalarSin(theta);
      for (iy = 0; iy < 3; iy++) {
        for (i = 0; i < 3; i++) {
          w_hat[i + 3 * iy] = (R[i + 3 * iy] - R[iy + 3 * i]) / B * theta;
        }
      }
    }
  }

  st.site = &o_emlrtRSI;

  /* SKEWCOORDS  generates a vector w given a skew-symmetric matrix R */
  /*  */
  /* 	w = SKEWCOORDS(R) */
  /*  */
  /*  See also: ROTAXIS, SKEWEXP, SKEW. */
  /*  $Id: skewcoords.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $ */
  /*  Copyright (C) 2005, by Brad Kratochvil */
  /*  function [out, varargout] = isskew(r) */
  /* ISSKEW  returns true if the matrix is a skew-semmetric matrix */
  /*  */
  /* 	T = ISSKEW(R) */
  /* 	[T REASON] = ISSKEW(R) */
  /*  */
  /*  if REASON is supplied as an output, a text based message as to why the */
  /*  test failed will be returned. */
  /*  */
  /*  TODO: we should probably check the magnitude of omega   */
  /*  */
  /*  See also: ISTWIST, ISROT, ISHOM. */
  /*  $Id: isskew.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $ */
  /*  Copyright (C) 2005, by Brad Kratochvil */
  /*  Commented out for .mex */
  /*    global DebugLevel; */
  /*     */
  y = true;

  /*    % varargout = {'skew'}; */
  /*     */
  /*    if isempty(DebugLevel) || (DebugLevel > 1) */
  /*     */
  for (iy = 0; iy < 3; iy++) {
    for (i = 0; i < 3; i++) {
      x[i + 3 * iy] = -w_hat[iy + 3 * i];
    }
  }

  p = false;
  b_p = true;
  iy = 0;
  exitg2 = false;
  while ((!exitg2) && (iy < 9)) {
    if (!(w_hat[iy] == x[iy])) {
      b_p = false;
      exitg2 = true;
    } else {
      iy++;
    }
  }

  if (!b_p) {
  } else {
    p = true;
  }

  if (!p) {
    y = false;

    /*  varargout = {'matrix not skew'}; */
  } else {
    /*       */
    /*    end */
  }

  if (!y) {
    b_st.site = &x_emlrtRSI;
    for (iy = 0; iy < 17; iy++) {
      u[iy] = varargin_1[iy];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(&b_st, 17, m0, &u[0]);
    emlrtAssign(&b_y, m0);
    for (iy = 0; iy < 37; iy++) {
      b_u[iy] = varargin_2[iy];
    }

    c_y = NULL;
    m0 = emlrtCreateCharArray(2, iv7);
    emlrtInitCharArrayR2013a(&b_st, 37, m0, &b_u[0]);
    emlrtAssign(&c_y, m0);
    c_st.site = &hd_emlrtRSI;
    error(&c_st, b_y, c_y, &emlrtMCI);
  }

  w[0] = w_hat[5];
  w[1] = w_hat[6];
  w[2] = w_hat[1];
  w_norm = 0.0;
  scale = 2.2250738585072014E-308;
  for (iy = 0; iy < 3; iy++) {
    absxk = muDoubleScalarAbs(w[iy]);
    if (absxk > scale) {
      t = scale / absxk;
      w_norm = 1.0 + w_norm * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      w_norm += t * t;
    }
  }

  w_norm = scale * muDoubleScalarSqrt(w_norm);
  iy = h->size[1];
  emlrtDynamicBoundsCheckR2012b(4, 1, iy, &f_emlrtBCI, sp);

  /* ISEQUALF  Returns true if the two quantities are equal within a threshold */
  /*  */
  /* 	t = ISEQUALF(A, B) */
  /* 	[t reason] = ISEQUALF(A, B, THRESH) */
  /*  */
  /*  This function is useful for floating point values, where there may be */
  /*  a small difference. */
  /*  */
  /*  See also: ISEQUAL. */
  /*  $Id: isequalf.m,v 1.1 2009-03-17 16:40:18 bradleyk Exp $ */
  /*  Copyright (C) 2005, by Brad Kratochvil */
  /*  it's machine dependent now */
  for (iy = 0; iy < 3; iy++) {
    w[iy] = 0.0 - h->data[iy + h->size[0] * 3];
  }

  for (iy = 0; iy < 3; iy++) {
    d_y[iy] = muDoubleScalarAbs(w[iy]);
  }

  iy = 1;
  mtmp = d_y[0];
  if (muDoubleScalarIsNaN(d_y[0])) {
    d_ix = 2;
    exitg1 = false;
    while ((!exitg1) && (d_ix < 4)) {
      iy = d_ix;
      if (!muDoubleScalarIsNaN(d_y[d_ix - 1])) {
        mtmp = d_y[d_ix - 1];
        exitg1 = true;
      } else {
        d_ix++;
      }
    }
  }

  if (iy < 3) {
    while (iy + 1 < 4) {
      if (d_y[iy] > mtmp) {
        mtmp = d_y[iy];
      }

      iy++;
    }
  }

  if (!!!(mtmp > 2.2204460492503131E-14)) {
    memset(&A_inv[0], 0, 9U * sizeof(real_T));
  } else if ((0.0 == muDoubleScalarSin(w_norm)) || (0.0 == w_norm)) {
    memset(&A_inv[0], 0, 9U * sizeof(real_T));
    for (iy = 0; iy < 3; iy++) {
      A_inv[iy + 3 * iy] = 1.0;
    }
  } else {
    memset(&x[0], 0, 9U * sizeof(real_T));
    for (iy = 0; iy < 3; iy++) {
      x[iy + 3 * iy] = 1.0;
    }

    e_y = (2.0 * muDoubleScalarSin(w_norm) - w_norm * (1.0 + muDoubleScalarCos
            (w_norm))) / (2.0 * (w_norm * w_norm) * muDoubleScalarSin(w_norm));
    for (iy = 0; iy < 3; iy++) {
      for (i = 0; i < 3; i++) {
        d1 = 0.0;
        for (ix = 0; ix < 3; ix++) {
          d1 += e_y * w_hat[iy + 3 * ix] * w_hat[ix + 3 * i];
        }

        A_inv[iy + 3 * i] = (x[iy + 3 * i] - w_hat[iy + 3 * i] / 2.0) + d1;
      }
    }
  }

  for (iy = 0; iy < 3; iy++) {
    d_y[iy] = 0.0;
    for (i = 0; i < 3; i++) {
      b_A_inv = d_y[iy] + A_inv[iy + 3 * i] * h->data[i + h->size[0] * 3];
      d_y[iy] = b_A_inv;
    }
  }

  for (iy = 0; iy < 3; iy++) {
    for (i = 0; i < 3; i++) {
      xi_hat[i + (iy << 2)] = w_hat[i + 3 * iy];
    }
  }

  for (iy = 0; iy < 3; iy++) {
    xi_hat[12 + iy] = d_y[iy];
  }

  for (iy = 0; iy < 4; iy++) {
    xi_hat[3 + (iy << 2)] = 0.0;
  }
}

/* End of code generation (twistlog.c) */
