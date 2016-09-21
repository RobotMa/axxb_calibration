/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_convl_2nd_mexutil.c
 *
 * Code generation for function 'mean_convl_2nd_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "mean_convl_2nd_mexutil.h"
#include <stdio.h>

/* Function Definitions */
const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m5);
  return y;
}

/* End of code generation (mean_convl_2nd_mexutil.c) */
