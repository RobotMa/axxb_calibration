//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: expm.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 05-Jul-2015 23:05:44
//

// Include Files
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "expm.h"
#include "mpower.h"
#include "norm.h"

// Function Declarations
static void PadeApproximantOfDegree(const double A[16], double m, double F[16]);
static double rt_powd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : const double A[16]
//                double m
//                double F[16]
// Return Type  : void
//
static void PadeApproximantOfDegree(const double A[16], double m, double F[16])
{
  int kAcol;
  int info;
  double A2[16];
  int jBcol;
  int k;
  double A4[16];
  double V[16];
  double d;
  double A3[16];
  double b_A4[16];
  int ipiv[4];
  int i;
  for (kAcol = 0; kAcol < 4; kAcol++) {
    for (info = 0; info < 4; info++) {
      A2[kAcol + (info << 2)] = 0.0;
      for (jBcol = 0; jBcol < 4; jBcol++) {
        A2[kAcol + (info << 2)] += A[kAcol + (jBcol << 2)] * A[jBcol + (info <<
          2)];
      }
    }
  }

  if (m == 3.0) {
    memcpy(&F[0], &A2[0], sizeof(double) << 4);
    for (k = 0; k < 4; k++) {
      F[k + (k << 2)] += 60.0;
    }

    for (kAcol = 0; kAcol < 4; kAcol++) {
      for (info = 0; info < 4; info++) {
        A4[kAcol + (info << 2)] = 0.0;
        for (jBcol = 0; jBcol < 4; jBcol++) {
          A4[kAcol + (info << 2)] += A[kAcol + (jBcol << 2)] * F[jBcol + (info <<
            2)];
        }
      }
    }

    for (kAcol = 0; kAcol < 4; kAcol++) {
      for (info = 0; info < 4; info++) {
        F[info + (kAcol << 2)] = A4[info + (kAcol << 2)];
      }
    }

    for (kAcol = 0; kAcol < 16; kAcol++) {
      V[kAcol] = 12.0 * A2[kAcol];
    }

    d = 120.0;
  } else {
    for (kAcol = 0; kAcol < 4; kAcol++) {
      for (info = 0; info < 4; info++) {
        A3[kAcol + (info << 2)] = 0.0;
        for (jBcol = 0; jBcol < 4; jBcol++) {
          A3[kAcol + (info << 2)] += A2[kAcol + (jBcol << 2)] * A2[jBcol + (info
            << 2)];
        }
      }
    }

    if (m == 5.0) {
      for (kAcol = 0; kAcol < 16; kAcol++) {
        F[kAcol] = A3[kAcol] + 420.0 * A2[kAcol];
      }

      for (k = 0; k < 4; k++) {
        F[k + (k << 2)] += 15120.0;
      }

      for (kAcol = 0; kAcol < 4; kAcol++) {
        for (info = 0; info < 4; info++) {
          A4[kAcol + (info << 2)] = 0.0;
          for (jBcol = 0; jBcol < 4; jBcol++) {
            A4[kAcol + (info << 2)] += A[kAcol + (jBcol << 2)] * F[jBcol + (info
              << 2)];
          }
        }
      }

      for (kAcol = 0; kAcol < 4; kAcol++) {
        for (info = 0; info < 4; info++) {
          F[info + (kAcol << 2)] = A4[info + (kAcol << 2)];
        }
      }

      for (kAcol = 0; kAcol < 16; kAcol++) {
        V[kAcol] = 30.0 * A3[kAcol] + 3360.0 * A2[kAcol];
      }

      d = 30240.0;
    } else {
      for (kAcol = 0; kAcol < 4; kAcol++) {
        for (info = 0; info < 4; info++) {
          b_A4[kAcol + (info << 2)] = 0.0;
          for (jBcol = 0; jBcol < 4; jBcol++) {
            b_A4[kAcol + (info << 2)] += A3[kAcol + (jBcol << 2)] * A2[jBcol +
              (info << 2)];
          }
        }
      }

      if (m == 7.0) {
        for (kAcol = 0; kAcol < 16; kAcol++) {
          F[kAcol] = (b_A4[kAcol] + 1512.0 * A3[kAcol]) + 277200.0 * A2[kAcol];
        }

        for (k = 0; k < 4; k++) {
          F[k + (k << 2)] += 8.64864E+6;
        }

        for (kAcol = 0; kAcol < 4; kAcol++) {
          for (info = 0; info < 4; info++) {
            A4[kAcol + (info << 2)] = 0.0;
            for (jBcol = 0; jBcol < 4; jBcol++) {
              A4[kAcol + (info << 2)] += A[kAcol + (jBcol << 2)] * F[jBcol +
                (info << 2)];
            }
          }
        }

        for (kAcol = 0; kAcol < 4; kAcol++) {
          for (info = 0; info < 4; info++) {
            F[info + (kAcol << 2)] = A4[info + (kAcol << 2)];
          }
        }

        for (kAcol = 0; kAcol < 16; kAcol++) {
          V[kAcol] = (56.0 * b_A4[kAcol] + 25200.0 * A3[kAcol]) + 1.99584E+6 *
            A2[kAcol];
        }

        d = 1.729728E+7;
      } else if (m == 9.0) {
        for (kAcol = 0; kAcol < 4; kAcol++) {
          for (info = 0; info < 4; info++) {
            V[kAcol + (info << 2)] = 0.0;
            for (jBcol = 0; jBcol < 4; jBcol++) {
              V[kAcol + (info << 2)] += b_A4[kAcol + (jBcol << 2)] * A2[jBcol +
                (info << 2)];
            }
          }
        }

        for (kAcol = 0; kAcol < 16; kAcol++) {
          F[kAcol] = ((V[kAcol] + 3960.0 * b_A4[kAcol]) + 2.16216E+6 * A3[kAcol])
            + 3.027024E+8 * A2[kAcol];
        }

        for (k = 0; k < 4; k++) {
          F[k + (k << 2)] += 8.8216128E+9;
        }

        for (kAcol = 0; kAcol < 4; kAcol++) {
          for (info = 0; info < 4; info++) {
            A4[kAcol + (info << 2)] = 0.0;
            for (jBcol = 0; jBcol < 4; jBcol++) {
              A4[kAcol + (info << 2)] += A[kAcol + (jBcol << 2)] * F[jBcol +
                (info << 2)];
            }
          }
        }

        for (kAcol = 0; kAcol < 4; kAcol++) {
          for (info = 0; info < 4; info++) {
            F[info + (kAcol << 2)] = A4[info + (kAcol << 2)];
          }
        }

        for (kAcol = 0; kAcol < 16; kAcol++) {
          V[kAcol] = ((90.0 * V[kAcol] + 110880.0 * b_A4[kAcol]) + 3.027024E+7 *
                      A3[kAcol]) + 2.0756736E+9 * A2[kAcol];
        }

        d = 1.76432256E+10;
      } else {
        for (kAcol = 0; kAcol < 16; kAcol++) {
          F[kAcol] = (3.352212864E+10 * b_A4[kAcol] + 1.05594705216E+13 *
                      A3[kAcol]) + 1.1873537964288E+15 * A2[kAcol];
        }

        for (k = 0; k < 4; k++) {
          F[k + (k << 2)] += 3.238237626624E+16;
          for (kAcol = 0; kAcol < 4; kAcol++) {
            A4[kAcol + (k << 2)] = (b_A4[kAcol + (k << 2)] + 16380.0 * A3[kAcol
              + (k << 2)]) + 4.08408E+7 * A2[kAcol + (k << 2)];
          }
        }

        for (kAcol = 0; kAcol < 4; kAcol++) {
          for (info = 0; info < 4; info++) {
            d = 0.0;
            for (jBcol = 0; jBcol < 4; jBcol++) {
              d += b_A4[kAcol + (jBcol << 2)] * A4[jBcol + (info << 2)];
            }

            V[kAcol + (info << 2)] = d + F[kAcol + (info << 2)];
          }
        }

        for (kAcol = 0; kAcol < 4; kAcol++) {
          for (info = 0; info < 4; info++) {
            F[kAcol + (info << 2)] = 0.0;
            for (jBcol = 0; jBcol < 4; jBcol++) {
              F[kAcol + (info << 2)] += A[kAcol + (jBcol << 2)] * V[jBcol +
                (info << 2)];
            }

            A4[info + (kAcol << 2)] = (182.0 * b_A4[info + (kAcol << 2)] +
              960960.0 * A3[info + (kAcol << 2)]) + 1.32324192E+9 * A2[info +
              (kAcol << 2)];
          }
        }

        for (kAcol = 0; kAcol < 4; kAcol++) {
          for (info = 0; info < 4; info++) {
            d = 0.0;
            for (jBcol = 0; jBcol < 4; jBcol++) {
              d += b_A4[kAcol + (jBcol << 2)] * A4[jBcol + (info << 2)];
            }

            V[kAcol + (info << 2)] = ((d + 6.704425728E+11 * b_A4[kAcol + (info <<
              2)]) + 1.29060195264E+14 * A3[kAcol + (info << 2)]) +
              7.7717703038976E+15 * A2[kAcol + (info << 2)];
          }
        }

        d = 6.476475253248E+16;
      }
    }
  }

  for (k = 0; k < 4; k++) {
    V[k + (k << 2)] += d;
  }

  for (k = 0; k < 16; k++) {
    V[k] -= F[k];
    F[k] *= 2.0;
  }

  eml_lapack_xgetrf(V, ipiv, &info);
  for (info = 0; info < 3; info++) {
    if (ipiv[info] != info + 1) {
      jBcol = ipiv[info] - 1;
      for (kAcol = 0; kAcol < 4; kAcol++) {
        d = F[info + (kAcol << 2)];
        F[info + (kAcol << 2)] = F[jBcol + (kAcol << 2)];
        F[jBcol + (kAcol << 2)] = d;
      }
    }
  }

  for (info = 0; info < 4; info++) {
    jBcol = info << 2;
    for (k = 0; k < 4; k++) {
      kAcol = k << 2;
      if (F[k + jBcol] != 0.0) {
        for (i = k + 1; i + 1 < 5; i++) {
          F[i + jBcol] -= F[k + jBcol] * V[i + kAcol];
        }
      }
    }
  }

  eml_xtrsm(V, F);
  for (k = 0; k < 4; k++) {
    F[k + (k << 2)]++;
  }
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d2;
  double d3;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d2 = fabs(u0);
    d3 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d2 == 1.0) {
        y = rtNaN;
      } else if (d2 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d3 == 0.0) {
      y = 1.0;
    } else if (d3 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

//
// Arguments    : double A[16]
//                double F[16]
// Return Type  : void
//
void expm(double A[16], double F[16])
{
  double normA;
  int eint;
  boolean_T exitg1;
  static const double theta[5] = { 0.01495585217958292, 0.253939833006323,
    0.95041789961629319, 2.097847961257068, 5.3719203511481517 };

  static const signed char iv6[5] = { 3, 5, 7, 9, 13 };

  double s;
  int j;
  double b_F[16];
  int i5;
  int i6;
  normA = norm(A);
  if (normA <= 5.3719203511481517) {
    eint = 0;
    exitg1 = false;
    while ((!exitg1) && (eint < 5)) {
      if (normA <= theta[eint]) {
        PadeApproximantOfDegree(A, (double)iv6[eint], F);
        exitg1 = true;
      } else {
        eint++;
      }
    }
  } else {
    normA /= 5.3719203511481517;
    if ((!rtIsInf(normA)) && (!rtIsNaN(normA))) {
      normA = frexp(normA, &eint);
    } else {
      eint = 0;
    }

    s = eint;
    if (normA == 0.5) {
      s = (double)eint - 1.0;
    }

    normA = rt_powd_snf(2.0, s);
    for (eint = 0; eint < 16; eint++) {
      A[eint] /= normA;
    }

    PadeApproximantOfDegree(A, 13.0, F);
    for (j = 0; j < (int)s; j++) {
      for (eint = 0; eint < 4; eint++) {
        for (i5 = 0; i5 < 4; i5++) {
          b_F[eint + (i5 << 2)] = 0.0;
          for (i6 = 0; i6 < 4; i6++) {
            b_F[eint + (i5 << 2)] += F[eint + (i6 << 2)] * F[i6 + (i5 << 2)];
          }
        }
      }

      for (eint = 0; eint < 4; eint++) {
        for (i5 = 0; i5 < 4; i5++) {
          F[i5 + (eint << 2)] = b_F[i5 + (eint << 2)];
        }
      }
    }
  }
}

//
// File trailer for expm.cpp
//
// [EOF]
//
