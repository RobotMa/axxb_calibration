/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mean_Taylor_1st.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 11-Jun-2015 01:24:21
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "mean_Taylor_1st.h"
#include "orthog.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : const double X[16]
 *                double M_t1[16]
 * Return Type  : void
 */
void b_mean_Taylor_1st(const double X[16], double M_t1[16])
{
  double dv0[16];

  /*  This function calculates the 1st order approximation of the mean of a */
  /*  bunch of matrices based on the Taylor expansion of the matrix logarithm */
  /*  and the definition of mean of a probability density function. */
  /*  Input: X is a 4 by 4*n rigid transformation matrices */
  /*  Output: M_T1 is the mean of the 1st order approximation of Taylor */
  /*  expansion */
  /*  Note that M_hat doesn't belong to SE(3) */
  memcpy(&dv0[0], &X[0], sizeof(double) << 4);
  orthog(dv0, M_t1);
}

/*
 * Arguments    : const double X[800]
 *                double M_t1[16]
 * Return Type  : void
 */
void mean_Taylor_1st(const double X[800], double M_t1[16])
{
  double M_hat[16];
  int i;
  int i13;
  int i14;
  double X_data[800];
  int loop_ub;
  int i15;

  /*  This function calculates the 1st order approximation of the mean of a */
  /*  bunch of matrices based on the Taylor expansion of the matrix logarithm */
  /*  and the definition of mean of a probability density function. */
  /*  Input: X is a 4 by 4*n rigid transformation matrices */
  /*  Output: M_T1 is the mean of the 1st order approximation of Taylor */
  /*  expansion */
  memset(&M_hat[0], 0, sizeof(double) << 4);
  for (i = 0; i < 50; i++) {
    i13 = (i << 2) + 1;
    i14 = (1 + i) << 2;
    if (i13 > i14) {
      i13 = 0;
      i14 = 0;
    } else {
      i13--;
    }

    loop_ub = i14 - i13;
    for (i14 = 0; i14 < loop_ub; i14++) {
      for (i15 = 0; i15 < 4; i15++) {
        X_data[i15 + (i14 << 2)] = X[i15 + ((i13 + i14) << 2)];
      }
    }

    for (i13 = 0; i13 < 4; i13++) {
      for (i14 = 0; i14 < 4; i14++) {
        M_hat[i14 + (i13 << 2)] += X_data[i14 + (i13 << 2)];
      }
    }
  }

  for (i13 = 0; i13 < 16; i13++) {
    M_hat[i13] *= 0.02;
  }

  /*  Note that M_hat doesn't belong to SE(3) */
  orthog(M_hat, M_t1);
}

/*
 * File trailer for mean_Taylor_1st.c
 *
 * [EOF]
 */
