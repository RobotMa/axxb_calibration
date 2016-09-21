//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean_Taylor_2nd.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 15-Jul-2015 12:00:44
//

// Include Files
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "mean_Taylor_2nd.h"
#include "mean_convl_2nd_emxutil.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "orthog.h"
#include <stdio.h>

// Function Definitions

//
// coder.extrinsic('mean_Taylor_1st_mex');
// Arguments    : const emxArray_real_T *X
//                signed char noise
//                short num
//                double MX[16]
// Return Type  : void
//
void mean_Taylor_2nd(const emxArray_real_T *X, signed char noise, short num,
                     double MX[16])
{
  double n;
  double M_hat[16];
  int i;
  emxArray_real_T *b_X;
  int i7;
  unsigned int u1;
  int i8;
  int i9;
  int loop_ub;
  double y;
  double M_t1[16];
  double dv0[16];
  double CA;
  signed char E[96];
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
  emxArray_real_T *X_k;
  emxArray_real_T *C;
  emxArray_real_T *a;
  boolean_T exitg1;
  double n_step;
  int j;
  int b_j;
  double b_a;
  double c_a[16];
  double MX1[16];
  double MX2[16];
  double MX2sum[16];
  int k;
  int tmp_size[2];
  int cr;
  int ic;
  int br;
  int ar;
  int ib;
  int ia;
  double b_M_hat;
  double b_MX2sum;
  double b_y;
  double CA1;
  double CA2;

  //  This function calculates the 2nd order approximation of the mean of a
  //  bunch of matrices based on the Taylor expansion of the matrix logarithm
  //  and the definition of mean of a probability density function.
  //  Input: X is a cell of 4 by 4*n rigid transformation matrices
  //  Output: M_T1 is the mean of the 1st order approximation of Taylor
  //  expansion
  //  Output: MX is the 2nd order approximation of the Taylor expansion
  //  This function calculates the 1st order approximation of the mean of a
  //  bunch of matrices based on the Taylor expansion of the matrix logarithm
  //  and the definition of mean of a probability density function.
  //  Input: X is a 4 by 4*n rigid transformation matrices
  //  Output: M_T1 is the mean of the 1st order approximation of Taylor
  //  expansion
  n = (double)X->size[1] / 4.0;
  memset(&M_hat[0], 0, sizeof(double) << 4);
  i = 0;
  emxInit_real_T(&b_X, 2);
  while (i <= (int)n - 1) {
    i7 = (i << 2) + 1;
    u1 = (unsigned int)(1 + i) << 2;
    if ((unsigned int)i7 > u1) {
      i7 = 0;
      i8 = 0;
    } else {
      i7--;
      i8 = (int)u1;
    }

    i9 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 4;
    b_X->size[1] = i8 - i7;
    emxEnsureCapacity((emxArray__common *)b_X, i9, (int)sizeof(double));
    loop_ub = i8 - i7;
    for (i8 = 0; i8 < loop_ub; i8++) {
      for (i9 = 0; i9 < 4; i9++) {
        b_X->data[i9 + b_X->size[0] * i8] = X->data[i9 + X->size[0] * (i7 + i8)];
      }
    }

    for (i7 = 0; i7 < 4; i7++) {
      for (i8 = 0; i8 < 4; i8++) {
        M_hat[i8 + (i7 << 2)] += b_X->data[i8 + (i7 << 2)];
      }
    }

    i++;
  }

  emxFree_real_T(&b_X);
  y = 1.0 / n;
  for (i7 = 0; i7 < 16; i7++) {
    M_hat[i7] *= y;
  }

  //  Note that M_hat doesn't belong to SE(3)
  orthog(M_hat, M_t1);

  //  Potential further refinement
  //  This function calculates the 1st order approximation of the mean of a
  //  bunch of matrices based on the Taylor expansion of the matrix logarithm
  //  and the definition of mean of a probability density function.
  //  Input: X is a 4 by 4*n rigid transformation matrices
  //  Output: M_T1 is the mean of the 1st order approximation of Taylor
  //  expansion
  //  Note that M_hat doesn't belong to SE(3)
  memcpy(&dv0[0], &M_t1[0], sizeof(double) << 4);
  orthog(dv0, M_t1);
  n = (double)X->size[1] / 4.0;

  //  Perturb M_t1 along each direction defined by the Lie algebra element of
  //  SE(3)
  CA = rtInf;
  for (i7 = 0; i7 < 4; i7++) {
    for (i8 = 0; i8 < 4; i8++) {
      E[i8 + (i7 << 2)] = iv6[i8 + (i7 << 2)];
      E[16 + (i8 + (i7 << 2))] = iv7[i8 + (i7 << 2)];
      E[32 + (i8 + (i7 << 2))] = iv8[i8 + (i7 << 2)];
      E[48 + (i8 + (i7 << 2))] = iv9[i8 + (i7 << 2)];
      E[64 + (i8 + (i7 << 2))] = iv10[i8 + (i7 << 2)];
      E[80 + (i8 + (i7 << 2))] = iv11[i8 + (i7 << 2)];
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
  emxInit_real_T(&X_k, 2);
  emxInit_real_T(&C, 2);
  emxInit_real_T(&a, 2);
  exitg1 = false;
  while ((!exitg1) && (fabs(CA) > 1.0E-12)) {
    count++;
    n_step = 0.0;

    //  Approximation of rotation is good so far so we only further optimize
    //  on translation
    for (j = 0; j <= 5 - m; j++) {
      b_j = m + j;

      //  disp(step)
      b_a = step * 0.001;
      for (i7 = 0; i7 < 4; i7++) {
        for (i8 = 0; i8 < 4; i8++) {
          c_a[i8 + (i7 << 2)] = b_a * (double)E[(i8 + (i7 << 2)) + (b_j << 4)];
        }
      }

      expm(c_a, M_hat);
      b_a = -step * 0.001;
      for (i7 = 0; i7 < 4; i7++) {
        for (i8 = 0; i8 < 4; i8++) {
          MX1[i7 + (i8 << 2)] = 0.0;
          for (i9 = 0; i9 < 4; i9++) {
            MX1[i7 + (i8 << 2)] += MX[i7 + (i9 << 2)] * M_hat[i9 + (i8 << 2)];
          }

          c_a[i8 + (i7 << 2)] = b_a * (double)E[(i8 + (i7 << 2)) + (b_j << 4)];
        }
      }

      expm(c_a, M_hat);
      for (i7 = 0; i7 < 4; i7++) {
        for (i8 = 0; i8 < 4; i8++) {
          MX2[i7 + (i8 << 2)] = 0.0;
          for (i9 = 0; i9 < 4; i9++) {
            MX2[i7 + (i8 << 2)] += MX[i7 + (i9 << 2)] * M_hat[i9 + (i8 << 2)];
          }
        }
      }

      for (i7 = 0; i7 < 16; i7++) {
        M_hat[i7] = 0.0;
        MX2sum[i7] = 0.0;
      }

      for (k = 0; k < (int)n; k++) {
        i7 = (k << 2) + 1;
        u1 = (unsigned int)(1 + k) << 2;
        if ((unsigned int)i7 > u1) {
          i7 = 1;
          i8 = 1;
        } else {
          i8 = (int)u1 + 1;
        }

        i9 = X_k->size[0] * X_k->size[1];
        X_k->size[0] = 4;
        X_k->size[1] = i8 - i7;
        emxEnsureCapacity((emxArray__common *)X_k, i9, (int)sizeof(double));
        loop_ub = i8 - i7;
        for (i9 = 0; i9 < loop_ub; i9++) {
          for (i = 0; i < 4; i++) {
            X_k->data[i + X_k->size[0] * i9] = X->data[i + X->size[0] * ((i7 +
              i9) - 1)];
          }
        }

        mrdivide(X_k, MX1, c_a, tmp_size);
        i9 = a->size[0] * a->size[1];
        a->size[0] = 4;
        a->size[1] = 4;
        emxEnsureCapacity((emxArray__common *)a, i9, (int)sizeof(double));
        for (i9 = 0; i9 < 16; i9++) {
          a->data[i9] = c_a[i9];
        }

        i9 = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity((emxArray__common *)C, i9, (int)sizeof(double));
        i9 = C->size[0] * C->size[1];
        C->size[1] = i8 - i7;
        emxEnsureCapacity((emxArray__common *)C, i9, (int)sizeof(double));
        loop_ub = (i8 - i7) << 2;
        for (i9 = 0; i9 < loop_ub; i9++) {
          C->data[i9] = 0.0;
        }

        if (i8 - i7 == 0) {
        } else {
          i = ((i8 - i7) - 1) << 2;
          for (cr = 0; cr <= i; cr += 4) {
            for (ic = cr + 1; ic <= cr + 4; ic++) {
              C->data[ic - 1] = 0.0;
            }
          }

          br = 0;
          for (cr = 0; cr <= i; cr += 4) {
            ar = 0;
            for (ib = br; ib + 1 <= br + 4; ib++) {
              if (X->data[ib % 4 + X->size[0] * ((i7 + (ib >> 2)) - 1)] != 0.0)
              {
                ia = ar;
                for (ic = cr; ic + 1 <= cr + 4; ic++) {
                  ia++;
                  C->data[ic] += X->data[ib % 4 + X->size[0] * ((i7 + (ib >> 2))
                    - 1)] * a->data[ia - 1];
                }
              }

              ar += 4;
            }

            br += 4;
          }
        }

        for (i9 = 0; i9 < 16; i9++) {
          b_M_hat = M_hat[i9] + C->data[i9];
          M_hat[i9] = b_M_hat;
        }

        mrdivide(X_k, MX2, c_a, tmp_size);
        i9 = a->size[0] * a->size[1];
        a->size[0] = 4;
        a->size[1] = 4;
        emxEnsureCapacity((emxArray__common *)a, i9, (int)sizeof(double));
        for (i9 = 0; i9 < 16; i9++) {
          a->data[i9] = c_a[i9];
        }

        i9 = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity((emxArray__common *)C, i9, (int)sizeof(double));
        i9 = C->size[0] * C->size[1];
        C->size[1] = i8 - i7;
        emxEnsureCapacity((emxArray__common *)C, i9, (int)sizeof(double));
        loop_ub = (i8 - i7) << 2;
        for (i9 = 0; i9 < loop_ub; i9++) {
          C->data[i9] = 0.0;
        }

        if (i8 - i7 == 0) {
        } else {
          i = ((i8 - i7) - 1) << 2;
          for (cr = 0; cr <= i; cr += 4) {
            for (ic = cr + 1; ic <= cr + 4; ic++) {
              C->data[ic - 1] = 0.0;
            }
          }

          br = 0;
          for (cr = 0; cr <= i; cr += 4) {
            ar = 0;
            for (ib = br; ib + 1 <= br + 4; ib++) {
              if (X->data[ib % 4 + X->size[0] * ((i7 + (ib >> 2)) - 1)] != 0.0)
              {
                ia = ar;
                for (ic = cr; ic + 1 <= cr + 4; ic++) {
                  ia++;
                  C->data[ic] += X->data[ib % 4 + X->size[0] * ((i7 + (ib >> 2))
                    - 1)] * a->data[ia - 1];
                }
              }

              ar += 4;
            }

            br += 4;
          }
        }

        for (i7 = 0; i7 < 16; i7++) {
          b_MX2sum = MX2sum[i7] + C->data[i7];
          MX2sum[i7] = b_MX2sum;
        }
      }

      y = 0.5 / n;
      b_y = 0.5 / n;
      for (i7 = 0; i7 < 16; i7++) {
        M_hat[i7] = (2.0 * M_t1[i7] - y * M_hat[i7]) - 1.5 * MX1[i7];
        MX2sum[i7] = (2.0 * M_t1[i7] - b_y * MX2sum[i7]) - 1.5 * MX2[i7];
      }

      if (noise == 0) {
        b_a = norm(*(double (*)[3])&M_hat[12]);
        CA1 = b_a * b_a;
        b_a = norm(*(double (*)[3])&MX2sum[12]);
        CA2 = b_a * b_a;
      } else if (noise == 1) {
        b_a = b_norm(M_hat);
        CA1 = b_a * b_a;
        b_a = b_norm(MX2sum);
        CA2 = b_a * b_a;
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

  emxFree_real_T(&a);
  emxFree_real_T(&C);
  emxFree_real_T(&X_k);

  //  fprintf('\n')
  f_fprintf(count);

  //  fprintf('\n')
  //  fprintf('\n')
}

//
// File trailer for mean_Taylor_2nd.cpp
//
// [EOF]
//
