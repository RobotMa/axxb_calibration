//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: norm.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 31-Aug-2015 00:46:55
//
#ifndef __NORM_H__
#define __NORM_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "mean_Taylor_2nd_adv_types.h"

// Function Declarations
extern double b_norm(const double x[16]);
extern void eml_xrotg(double *a, double *b, double *c, double *s);
extern double norm(const double x[3]);

#endif

//
// File trailer for norm.h
//
// [EOF]
//
