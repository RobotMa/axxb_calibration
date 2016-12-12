//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: param_extract.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//

// Include Files
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "param_extract.h"

// Function Definitions

//
// Arguments    : const double X_in[16]
//                double *theta
//                double N[9]
//                double *d
//                double p[3]
// Return Type  : void
//
void param_extract(const double X_in[16], double *theta, double N[9], double *d,
                   double p[3])
{
  double a21;
  int r1;
  int r2;
  double g[3];
  double u[3];
  double c;
  double A[4];
  double B[2];
  double a22;

  // Function to extract Plucker parameters from a g \in SE(3)
  // files needed:
  // so3_vec().m
  // extract theta---------------------------------
  a21 = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    a21 += X_in[r1 + (r1 << 2)];
  }

  *theta = acos((a21 - 1.0) / 2.0);

  // ----------------------------------------------
  // extract N---------------------------------
  a21 = 2.0 * sin(*theta);
  for (r1 = 0; r1 < 3; r1++) {
    for (r2 = 0; r2 < 3; r2++) {
      N[r2 + 3 * r1] = (X_in[r2 + (r1 << 2)] - X_in[r1 + (r2 << 2)]) / a21;
    }
  }

  // ----------------------------------------------
  // extract d---------------------------------
  // Function to vectorize or hat an element in so(3)
  // files needed:
  // none
  // If input is skew-sym change to vector
  g[0] = -N[7];
  g[1] = N[6];
  g[2] = -N[3];
  *d = 0.0;

  // ----------------------------------------------
  // extract p---------------------------------
  // Function to vectorize or hat an element in so(3)
  // files needed:
  // none
  // If input is skew-sym change to vector
  a21 = 1.0 / sqrt(-N[7] * -N[7] + N[6] * N[6]);
  u[0] = a21 * -N[6];
  u[1] = a21 * -N[7];
  u[2] = a21 * 0.0;
  a21 = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    *d += X_in[12 + r1] * g[r1];
    a21 += X_in[12 + r1] * u[r1];
  }

  g[0] = N[6] * u[2] - -N[3] * u[1];
  g[1] = -N[3] * u[0] - -N[7] * u[2];
  g[2] = -N[7] * u[1] - N[6] * u[0];
  c = 0.0;
  for (r1 = 0; r1 < 3; r1++) {
    c += X_in[12 + r1] * g[r1];
  }

  A[0] = 1.0 - cos(*theta);
  A[2] = sin(*theta);
  A[1] = -sin(*theta);
  A[3] = 1.0 - cos(*theta);
  B[0] = a21;
  B[1] = c;
  if (fabs(A[1]) > fabs(A[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = A[r2] / A[r1];
  a22 = A[2 + r2] - a21 * A[2 + r1];
  c = B[r2] - B[r1] * a21;
  a21 = c / a22;
  c = (B[r1] - c / a22 * A[2 + r1]) / A[r1];
  p[0] = c * u[0] + a21 * (N[6] * u[2] - -N[3] * u[1]);
  p[1] = c * u[1] + a21 * (-N[3] * u[0] - -N[7] * u[2]);
  p[2] = c * u[2] + a21 * (-N[7] * u[1] - N[6] * u[0]);

  // ----------------------------------------------
}

//
// File trailer for param_extract.cpp
//
// [EOF]
//
