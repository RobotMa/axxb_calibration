//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mpower.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 05-Jul-2015 23:05:44
//
#ifndef __MPOWER_H__
#define __MPOWER_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "distibutionPropsMex_types.h"

// Function Declarations
extern void eml_lapack_xgetrf(double A[16], int ipiv[4], int *info);
extern void eml_xtrsm(const double A[16], double B[16]);
extern void mpower(const double a[16], double c[16]);

#endif

//
// File trailer for mpower.h
//
// [EOF]
//
