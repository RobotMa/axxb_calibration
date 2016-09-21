//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean_Taylor_2nd_adv.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 31-Aug-2015 00:46:55
//

// Include Files
#include "rt_nonfinite.h"
#include "mean_Taylor_2nd_adv.h"
#include "mean_Taylor_2nd_adv_emxutil.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "mean_Taylor_1st.h"
#include <stdio.h>

// Function Definitions

//
// coder.extrinsic('mean_Taylor_1st_mex');
// Arguments    : const emxArray_real_T *X
//                double noise
//                short num
//                double MX[16]
// Return Type  : void
//
void mean_Taylor_2nd_adv(const emxArray_real_T *X, double noise, short num,
  double MX[16])
{
  double M_hat[16];
  double n;
  int i;
  emxArray_real_T *b_X;
  int i0;
  unsigned int u0;
  int i1;
  int i2;
  int loop_ub;
  double CA;
  double CA1;
  double CA2;
  signed char E[96];
  static const signed char iv0[16] = { 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv1[16] = { 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv2[16] = { 0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv3[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const signed char iv4[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0 };

  static const signed char iv5[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0 };

  double count;
  int m;
  double step;
  emxArray_real_T *X_k;
  emxArray_real_T *C;
  boolean_T exitg1;
  double n_step;
  int j;
  int b_j;
  double a;
  double b_a[16];
  double MX1sum[16];
  double MX1[16];
  double MX2[16];
  double MX2sum[16];
  int k;
  int a_size[2];
  int cr;
  int ic;
  int br;
  int ar;
  int ib;
  int ia;
  double b_MX1sum;
  double b_MX2sum;
  double y;
  double b_y;
  double c_y;
  double d_y;

  //  This function calculates the 2nd order approximation of the mean of a
  //  bunch of matrices based on the Taylor expansion of the matrix logarithm
  //  and the definition of mean of a probability density function.
  //  Input: X is a cell of 4 by 4*n rigid transformation matrices
  //  Output: M_T1 is the mean of the 1st order approximation of Taylor
  //  expansion
  //  Output: MX is the 2nd order approximation of the Taylor expansion
  memset(&M_hat[0], 0, sizeof(double) << 4);
  n = (double)X->size[1] / 4.0;
  i = 0;
  emxInit_real_T(&b_X, 2);
  while (i <= (int)n - 1) {
    i0 = (i << 2) + 1;
    u0 = (unsigned int)(1 + i) << 2;
    if ((unsigned int)i0 > u0) {
      i0 = 0;
      i1 = 0;
    } else {
      i0--;
      i1 = (int)u0;
    }

    i2 = b_X->size[0] * b_X->size[1];
    b_X->size[0] = 4;
    b_X->size[1] = i1 - i0;
    emxEnsureCapacity((emxArray__common *)b_X, i2, (int)sizeof(double));
    loop_ub = i1 - i0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < 4; i2++) {
        b_X->data[i2 + b_X->size[0] * i1] = X->data[i2 + X->size[0] * (i0 + i1)];
      }
    }

    for (i0 = 0; i0 < 4; i0++) {
      for (i1 = 0; i1 < 4; i1++) {
        M_hat[i1 + (i0 << 2)] += b_X->data[i1 + (i0 << 2)];
      }
    }

    i++;
  }

  emxFree_real_T(&b_X);
  mean_Taylor_1st(X, MX);

  //  Potential further refinement
  //  M_t1 = mean_Taylor_1st( M_t1 );
  //  Perturb M_t1 along each direction defined by the Lie algebra element of
  //  SE(3)
  CA = rtInf;
  CA1 = rtInf;
  CA2 = rtInf;
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      E[i1 + (i0 << 2)] = iv0[i1 + (i0 << 2)];
      E[16 + (i1 + (i0 << 2))] = iv1[i1 + (i0 << 2)];
      E[32 + (i1 + (i0 << 2))] = iv2[i1 + (i0 << 2)];
      E[48 + (i1 + (i0 << 2))] = iv3[i1 + (i0 << 2)];
      E[64 + (i1 + (i0 << 2))] = iv4[i1 + (i0 << 2)];
      E[80 + (i1 + (i0 << 2))] = iv5[i1 + (i0 << 2)];
    }
  }

  count = 0.0;
  if (noise == 0.0) {
    m = 3;
  } else if (noise == 1.0) {
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
  exitg1 = false;
  while ((!exitg1) && (fabs(CA) > 1.0E-12)) {
    count++;
    n_step = 0.0;

    //  Approximation of rotation is good so far so we only further optimize
    //  on translation
    for (j = 0; j <= 5 - m; j++) {
      b_j = m + j;
      a = step * 0.001;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          b_a[i1 + (i0 << 2)] = a * (double)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      expm(b_a, MX1sum);
      a = -step * 0.001;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          MX1[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            MX1[i0 + (i1 << 2)] += MX[i0 + (i2 << 2)] * MX1sum[i2 + (i1 << 2)];
          }

          b_a[i1 + (i0 << 2)] = a * (double)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      expm(b_a, MX1sum);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          MX2[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            MX2[i0 + (i1 << 2)] += MX[i0 + (i2 << 2)] * MX1sum[i2 + (i1 << 2)];
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        MX1sum[i0] = 0.0;
        MX2sum[i0] = 0.0;
      }

      for (k = 0; k < (int)n; k++) {
        i0 = (k << 2) + 1;
        u0 = (unsigned int)(1 + k) << 2;
        if ((unsigned int)i0 > u0) {
          i0 = 0;
          i1 = 0;
        } else {
          i0--;
          i1 = (int)u0;
        }

        i2 = X_k->size[0] * X_k->size[1];
        X_k->size[0] = 4;
        X_k->size[1] = i1 - i0;
        emxEnsureCapacity((emxArray__common *)X_k, i2, (int)sizeof(double));
        loop_ub = i1 - i0;
        for (i2 = 0; i2 < loop_ub; i2++) {
          for (i = 0; i < 4; i++) {
            X_k->data[i + X_k->size[0] * i2] = X->data[i + X->size[0] * (i0 + i2)];
          }
        }

        mrdivide(X_k, MX1, b_a, a_size);
        i2 = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity((emxArray__common *)C, i2, (int)sizeof(double));
        i2 = C->size[0] * C->size[1];
        C->size[1] = i1 - i0;
        emxEnsureCapacity((emxArray__common *)C, i2, (int)sizeof(double));
        loop_ub = (i1 - i0) << 2;
        for (i2 = 0; i2 < loop_ub; i2++) {
          C->data[i2] = 0.0;
        }

        if (i1 - i0 == 0) {
        } else {
          i = ((i1 - i0) - 1) << 2;
          for (cr = 0; cr <= i; cr += 4) {
            for (ic = cr; ic + 1 <= cr + 4; ic++) {
              C->data[ic] = 0.0;
            }
          }

          br = 0;
          for (cr = 0; cr <= i; cr += 4) {
            ar = 0;
            for (ib = br; ib + 1 <= br + 4; ib++) {
              if (X->data[ib % 4 + X->size[0] * (i0 + (ib >> 2))] != 0.0) {
                ia = ar;
                for (ic = cr; ic + 1 <= cr + 4; ic++) {
                  ia++;
                  C->data[ic] += X->data[ib % 4 + X->size[0] * (i0 + (ib >> 2))]
                    * b_a[ia - 1];
                }
              }

              ar += 4;
            }

            br += 4;
          }
        }

        for (i2 = 0; i2 < 16; i2++) {
          b_MX1sum = MX1sum[i2] + C->data[i2];
          MX1sum[i2] = b_MX1sum;
        }

        mrdivide(X_k, MX2, b_a, a_size);
        i2 = C->size[0] * C->size[1];
        C->size[0] = 4;
        emxEnsureCapacity((emxArray__common *)C, i2, (int)sizeof(double));
        i2 = C->size[0] * C->size[1];
        C->size[1] = i1 - i0;
        emxEnsureCapacity((emxArray__common *)C, i2, (int)sizeof(double));
        loop_ub = (i1 - i0) << 2;
        for (i2 = 0; i2 < loop_ub; i2++) {
          C->data[i2] = 0.0;
        }

        if (i1 - i0 == 0) {
        } else {
          i = ((i1 - i0) - 1) << 2;
          for (cr = 0; cr <= i; cr += 4) {
            for (ic = cr; ic + 1 <= cr + 4; ic++) {
              C->data[ic] = 0.0;
            }
          }

          br = 0;
          for (cr = 0; cr <= i; cr += 4) {
            ar = 0;
            for (ib = br; ib + 1 <= br + 4; ib++) {
              if (X->data[ib % 4 + X->size[0] * (i0 + (ib >> 2))] != 0.0) {
                ia = ar;
                for (ic = cr; ic + 1 <= cr + 4; ic++) {
                  ia++;
                  C->data[ic] += X->data[ib % 4 + X->size[0] * (i0 + (ib >> 2))]
                    * b_a[ia - 1];
                }
              }

              ar += 4;
            }

            br += 4;
          }
        }

        for (i0 = 0; i0 < 16; i0++) {
          b_MX2sum = MX2sum[i0] + C->data[i0];
          MX2sum[i0] = b_MX2sum;
        }
      }

      y = 2.0 / n;
      b_y = 0.5 / n;
      c_y = 2.0 / n;
      d_y = 0.5 / n;
      for (i0 = 0; i0 < 16; i0++) {
        MX1sum[i0] = (y * M_hat[i0] - b_y * MX1sum[i0]) - 1.5 * MX1[i0];
        MX2sum[i0] = (c_y * M_hat[i0] - d_y * MX2sum[i0]) - 1.5 * MX2[i0];
      }

      if (noise == 0.0) {
        a = norm(*(double (*)[3])&MX1sum[12]);
        CA1 = a * a;
        a = norm(*(double (*)[3])&MX2sum[12]);
        CA2 = a * a;
      } else if (noise == 1.0) {
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
      d_fprintf(CA1);
      f_fprintf(CA2);
      exitg1 = true;
    }
  }

  emxFree_real_T(&C);
  emxFree_real_T(&X_k);
  h_fprintf(count);
}

//
// File trailer for mean_Taylor_2nd_adv.cpp
//
// [EOF]
//
