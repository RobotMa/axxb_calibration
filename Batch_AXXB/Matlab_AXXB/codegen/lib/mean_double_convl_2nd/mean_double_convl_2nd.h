//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean_double_convl_2nd.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 11-Jun-2015 01:46:04
//
#ifndef __MEAN_DOUBLE_CONVL_2ND_H__
#define __MEAN_DOUBLE_CONVL_2ND_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "mean_double_convl_2nd_types.h"

// Function Declarations
extern void eml_xgemm(int n, int k, const double A_data[], const double B_data[],
                      int ldb, double C_data[]);
extern void mean_double_convl_2nd(const double X1[800], const double X2[800],
  const double X3[800], signed char s1, signed char s2, signed char s3, short
  n_search, double diff, double M123_f[16]);

#endif

//
// File trailer for mean_double_convl_2nd.h
//
// [EOF]
//
