//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean_Taylor_2nd.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 11-Jun-2015 01:46:04
//

// Include Files
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "mean_Taylor_2nd.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "mean_Taylor_1st.h"
#include <stdio.h>

// Function Definitions

//
// coder.extrinsic('mean_Taylor_1st_mex');
// Arguments    : const double X[800]
//                signed char noise
//                short num
//                double MX[16]
// Return Type  : void
//
void mean_Taylor_2nd(const double X[800], signed char noise, short num, double
                     MX[16])
{
  double M_t1[16];
  double b_M_t1[16];
  double CA;
  signed char E[96];
  int i9;
  int i10;
  static const signed char iv6[16] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv7[16] = { 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv8[16] = { 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv9[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const signed char iv10[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0 };

  static const signed char iv11[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0 };

  double count;
  int m;
  double step;
  boolean_T exitg1;
  double n_step;
  int j;
  int b_j;
  double a;
  double b_a[16];
  double MX1sum[16];
  double MX1[16];
  int i11;
  double MX2[16];
  double MX2sum[16];
  double X_k_data[800];
  double a_data[800];
  double tmp_data[800];
  int k;
  int X_k_size[2];
  int loop_ub;
  int i12;
  int tmp_size[2];
  double b_tmp_data[16];
  double CA1;
  double CA2;

  //  This function calculates the 2nd order approximation of the mean of a
  //  bunch of matrices based on the Taylor expansion of the matrix logarithm
  //  and the definition of mean of a probability density function.
  //  Input: X is a cell of 4 by 4*n rigid transformation matrices
  //  Output: M_T1 is the mean of the 1st order approximation of Taylor
  //  expansion
  //  Output: MX is the 2nd order approximation of the Taylor expansion
  mean_Taylor_1st(X, M_t1);

  //  Potential further refinement
  memcpy(&b_M_t1[0], &M_t1[0], sizeof(double) << 4);
  b_mean_Taylor_1st(b_M_t1, M_t1);

  //  Perturb M_t1 along each direction defined by the Lie algebra element of
  //  SE(3)
  CA = rtInf;
  for (i9 = 0; i9 < 4; i9++) {
    for (i10 = 0; i10 < 4; i10++) {
      E[i10 + (i9 << 2)] = iv6[i10 + (i9 << 2)];
      E[16 + (i10 + (i9 << 2))] = iv7[i10 + (i9 << 2)];
      E[32 + (i10 + (i9 << 2))] = iv8[i10 + (i9 << 2)];
      E[48 + (i10 + (i9 << 2))] = iv9[i10 + (i9 << 2)];
      E[64 + (i10 + (i9 << 2))] = iv10[i10 + (i9 << 2)];
      E[80 + (i10 + (i9 << 2))] = iv11[i10 + (i9 << 2)];
    }
  }

  memcpy(&MX[0], &M_t1[0], sizeof(double) << 4);
  count = 0.0;
  if (noise == 0) {
    m = 3;
  } else if (noise == 1) {
    m = 0;
  } else {
    m = -1;
  }

  step = 1.0;

  //  Change the step lengths if descent direction is not found
  //  fprintf('---------------------------------------------- \n')
  //  fprintf('Search gradient descent direction from %f to 6 \n', m)
  //  fprintf('---------------------------------------------- \n')
  exitg1 = false;
  while ((!exitg1) && (fabs(CA) > 1.0E-12)) {
    count++;
    n_step = 0.0;

    //  Approximation of rotation is good so far so we only further optimize
    //  on translation
    for (j = 0; j <= 5 - m; j++) {
      b_j = m + j;

      //  disp(step)
      a = step * 0.001;
      for (i9 = 0; i9 < 4; i9++) {
        for (i10 = 0; i10 < 4; i10++) {
          b_a[i10 + (i9 << 2)] = a * (double)E[(i10 + (i9 << 2)) + (b_j << 4)];
        }
      }

      expm(b_a, MX1sum);
      a = -step * 0.001;
      for (i9 = 0; i9 < 4; i9++) {
        for (i10 = 0; i10 < 4; i10++) {
          MX1[i9 + (i10 << 2)] = 0.0;
          for (i11 = 0; i11 < 4; i11++) {
            MX1[i9 + (i10 << 2)] += MX[i9 + (i11 << 2)] * MX1sum[i11 + (i10 << 2)];
          }

          b_a[i10 + (i9 << 2)] = a * (double)E[(i10 + (i9 << 2)) + (b_j << 4)];
        }
      }

      expm(b_a, MX1sum);
      for (i9 = 0; i9 < 4; i9++) {
        for (i10 = 0; i10 < 4; i10++) {
          MX2[i9 + (i10 << 2)] = 0.0;
          for (i11 = 0; i11 < 4; i11++) {
            MX2[i9 + (i10 << 2)] += MX[i9 + (i11 << 2)] * MX1sum[i11 + (i10 << 2)];
          }
        }
      }

      for (i9 = 0; i9 < 16; i9++) {
        MX1sum[i9] = 0.0;
        MX2sum[i9] = 0.0;
      }

      for (k = 0; k < 50; k++) {
        i9 = (k << 2) + 1;
        i10 = (1 + k) << 2;
        if (i9 > i10) {
          i9 = 0;
          i10 = 0;
        } else {
          i9--;
        }

        X_k_size[0] = 4;
        X_k_size[1] = i10 - i9;
        loop_ub = i10 - i9;
        for (i11 = 0; i11 < loop_ub; i11++) {
          for (i12 = 0; i12 < 4; i12++) {
            X_k_data[i12 + (i11 << 2)] = X[i12 + ((i9 + i11) << 2)];
          }
        }

        mrdivide(X_k_data, X_k_size, MX1, b_tmp_data, tmp_size);
        memcpy(&a_data[0], &b_tmp_data[0], sizeof(double) << 4);
        loop_ub = (unsigned char)(i10 - i9) << 2;
        for (i11 = 0; i11 < loop_ub; i11++) {
          tmp_data[i11] = 0.0;
        }

        eml_xgemm(i10 - i9, 4, a_data, X_k_data, 4, tmp_data);
        for (i11 = 0; i11 < 16; i11++) {
          MX1sum[i11] += tmp_data[i11];
        }

        mrdivide(X_k_data, X_k_size, MX2, b_tmp_data, tmp_size);
        memcpy(&a_data[0], &b_tmp_data[0], sizeof(double) << 4);
        loop_ub = (unsigned char)(i10 - i9) << 2;
        for (i11 = 0; i11 < loop_ub; i11++) {
          tmp_data[i11] = 0.0;
        }

        eml_xgemm(i10 - i9, 4, a_data, X_k_data, 4, tmp_data);
        for (i9 = 0; i9 < 16; i9++) {
          MX2sum[i9] += tmp_data[i9];
        }
      }

      for (i9 = 0; i9 < 16; i9++) {
        MX1sum[i9] = (2.0 * M_t1[i9] - 0.01 * MX1sum[i9]) - 1.5 * MX1[i9];
        MX2sum[i9] = (2.0 * M_t1[i9] - 0.01 * MX2sum[i9]) - 1.5 * MX2[i9];
      }

      if (noise == 0) {
        a = norm(*(double (*)[3])&MX1sum[12]);
        CA1 = a * a;
        a = norm(*(double (*)[3])&MX2sum[12]);
        CA2 = a * a;
      } else if (noise == 1) {
        a = b_norm(MX1sum);
        CA1 = a * a;
        a = b_norm(MX2sum);
        CA2 = a * a;
      } else {
        CA1 = -1.0;
        CA2 = -1.0;
      }

      if ((CA1 <= CA2) && (CA1 < CA)) {
        CA = CA1;
        memcpy(&MX[0], &MX1[0], sizeof(double) << 4);
        step = 1.0;

        //  fprintf('Found a descent direction along %d \n', j)
        //  disp(MX1cost)
        //  disp(CA)
      } else if ((CA2 < CA1) && (CA2 < CA)) {
        CA = CA2;
        memcpy(&MX[0], &MX2[0], sizeof(double) << 4);
        step = 1.0;

        //  fprintf('Found a descent direction along -%d \n', j)
        //  disp(MX2cost)
        //  disp(CA)
      } else {
        //  fprintf('Not a descent direction along +/-%d \n', j)
        n_step++;
        if (n_step == 6.0) {
          step++;
        }
      }
    }

    if (count == num) {
      exitg1 = true;
    }
  }

  //  fprintf('\n')
  d_fprintf(count);

  //  fprintf('\n')
  //  fprintf('\n')
}

//
// File trailer for mean_Taylor_2nd.cpp
//
// [EOF]
//
