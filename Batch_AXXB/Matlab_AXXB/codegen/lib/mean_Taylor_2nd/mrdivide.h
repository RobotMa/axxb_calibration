//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mrdivide.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 30-Aug-2015 22:24:42
//
#ifndef __MRDIVIDE_H__
#define __MRDIVIDE_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "mean_Taylor_2nd_types.h"

// Function Declarations
extern void eml_xgetrf(double A[16], int ipiv[4], int *info);
extern void mrdivide(const emxArray_real_T *A, const double B[16], double
                     y_data[], int y_size[2]);

#endif

//
// File trailer for mrdivide.h
//
// [EOF]
//
