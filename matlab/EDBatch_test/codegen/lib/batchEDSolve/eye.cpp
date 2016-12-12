//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eye.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//

// Include Files
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "eye.h"

// Function Definitions

//
// Arguments    : double I[9]
// Return Type  : void
//
void eye(double I[9])
{
  int k;
  memset(&I[0], 0, 9U * sizeof(double));
  for (k = 0; k < 3; k++) {
    I[k + 3 * k] = 1.0;
  }
}

//
// File trailer for eye.cpp
//
// [EOF]
//
