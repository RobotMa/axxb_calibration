//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: so3_vec.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//

// Include Files
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "so3_vec.h"

// Function Definitions

//
// Arguments    : const creal_T X_data[]
//                const int X_size[2]
//                creal_T g_data[]
//                int g_size[2]
// Return Type  : void
//
void so3_vec(const creal_T X_data[], const int X_size[2], creal_T g_data[], int
             g_size[2])
{
  creal_T X[3];
  int i9;
  creal_T dcv1[9];
  int i10;

  // Function to vectorize or hat an element in so(3)
  // files needed:
  // none
  if (X_size[1] == 3) {
    // If input is skew-sym change to vector
    X[0].re = -X_data[1 + (X_size[0] << 1)].re;
    X[0].im = -X_data[1 + (X_size[0] << 1)].im;
    X[1] = X_data[X_size[0] << 1];
    X[2].re = -X_data[X_size[0]].re;
    X[2].im = -X_data[X_size[0]].im;
    g_size[0] = 3;
    g_size[1] = 1;
    for (i9 = 0; i9 < 3; i9++) {
      g_data[i9] = X[i9];
    }
  } else {
    // If input is vector change to skew-sym
    dcv1[0].re = 0.0;
    dcv1[0].im = 0.0;
    dcv1[3].re = -X_data[2].re;
    dcv1[3].im = -X_data[2].im;
    dcv1[6] = X_data[1];
    dcv1[1] = X_data[2];
    dcv1[4].re = 0.0;
    dcv1[4].im = 0.0;
    dcv1[7].re = -X_data[0].re;
    dcv1[7].im = -X_data[0].im;
    dcv1[2].re = -X_data[1].re;
    dcv1[2].im = -X_data[1].im;
    dcv1[5] = X_data[0];
    dcv1[8].re = 0.0;
    dcv1[8].im = 0.0;
    g_size[0] = 3;
    g_size[1] = 3;
    for (i9 = 0; i9 < 3; i9++) {
      for (i10 = 0; i10 < 3; i10++) {
        g_data[i10 + 3 * i9] = dcv1[i10 + 3 * i9];
      }
    }
  }
}

//
// File trailer for so3_vec.cpp
//
// [EOF]
//
