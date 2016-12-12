/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "sqrt.h"
#include "eml_error.h"
#include "batchEDSolve_data.h"

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, real_T *x)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (*x < 0.0) {
    st.site = &yd_emlrtRSI;
    d_eml_error(&st);
  }

  *x = muDoubleScalarSqrt(*x);
}

void c_sqrt(creal_T *x)
{
  real_T absxi;
  real_T absxr;
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      absxi = 0.0;
      absxr = muDoubleScalarSqrt(muDoubleScalarAbs(x->re));
    } else {
      absxi = muDoubleScalarSqrt(x->re);
      absxr = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      absxi = muDoubleScalarSqrt(-x->im / 2.0);
      absxr = -absxi;
    } else {
      absxi = muDoubleScalarSqrt(x->im / 2.0);
      absxr = absxi;
    }
  } else if (muDoubleScalarIsNaN(x->re) || muDoubleScalarIsNaN(x->im)) {
    absxi = rtNaN;
    absxr = rtNaN;
  } else if (muDoubleScalarIsInf(x->im)) {
    absxi = rtInf;
    absxr = x->im;
  } else if (muDoubleScalarIsInf(x->re)) {
    if (x->re < 0.0) {
      absxi = 0.0;
      absxr = rtInf;
    } else {
      absxi = rtInf;
      absxr = 0.0;
    }
  } else {
    absxr = muDoubleScalarAbs(x->re);
    absxi = muDoubleScalarAbs(x->im);
    if ((absxr > 4.4942328371557893E+307) || (absxi > 4.4942328371557893E+307))
    {
      absxr *= 0.5;
      absxi *= 0.5;
      absxi = muDoubleScalarHypot(absxr, absxi);
      if (absxi > absxr) {
        absxi = muDoubleScalarSqrt(absxi) * muDoubleScalarSqrt(1.0 + absxr /
          absxi);
      } else {
        absxi = muDoubleScalarSqrt(absxi) * 1.4142135623730951;
      }
    } else {
      absxi = muDoubleScalarSqrt((muDoubleScalarHypot(absxr, absxi) + absxr) *
        0.5);
    }

    if (x->re > 0.0) {
      absxr = 0.5 * (x->im / absxi);
    } else {
      if (x->im < 0.0) {
        absxr = -absxi;
      } else {
        absxr = absxi;
      }

      absxi = 0.5 * (x->im / absxr);
    }
  }

  x->re = absxi;
  x->im = absxr;
}

/* End of code generation (sqrt.c) */
