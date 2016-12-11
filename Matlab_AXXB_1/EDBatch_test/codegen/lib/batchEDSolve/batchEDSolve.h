//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: batchEDSolve.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//
#ifndef __BATCHEDSOLVE_H__
#define __BATCHEDSOLVE_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "batchEDSolve_types.h"

// Function Declarations
extern void batchEDSolve(const emxArray_real_T *A, const emxArray_real_T *B,
  creal_T X[16], double MeanA[16], double MeanB[16], double SigA[36], double
  SigB[36]);

#endif

//
// File trailer for batchEDSolve.h
//
// [EOF]
//
