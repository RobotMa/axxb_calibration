/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mean_double_convl_2nd.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 11-Jun-2015 01:24:21
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "mrdivide.h"
#include "norm.h"
#include "expm.h"
#include "fprintf.h"
#include "mean_Taylor_2nd.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : int n
 *                int k
 *                const double A_data[]
 *                const double B_data[]
 *                int ldb
 *                double C_data[]
 * Return Type  : void
 */
void eml_xgemm(int n, int k, const double A_data[], const double B_data[], int
               ldb, double C_data[])
{
  int c;
  int cr;
  int ic;
  int br;
  int ar;
  int i22;
  int ib;
  int ia;
  if (n == 0) {
  } else {
    c = (n - 1) << 2;
    for (cr = 0; cr <= c; cr += 4) {
      for (ic = cr + 1; ic <= cr + 4; ic++) {
        C_data[ic - 1] = 0.0;
      }
    }

    br = 0;
    for (cr = 0; cr <= c; cr += 4) {
      ar = -1;
      i22 = br + k;
      for (ib = br; ib + 1 <= i22; ib++) {
        if (B_data[ib] != 0.0) {
          ia = ar;
          for (ic = cr; ic + 1 <= cr + 4; ic++) {
            ia++;
            C_data[ic] += B_data[ib] * A_data[ia];
          }
        }

        ar += 4;
      }

      br += ldb;
    }
  }
}

/*
 * Arguments    : const double X1[800]
 *                const double X2[800]
 *                const double X3[800]
 *                signed char s1
 *                signed char s2
 *                signed char s3
 *                short n_search
 *                double diff
 *                double M123_f[16]
 * Return Type  : void
 */
void mean_double_convl_2nd(const double X1[800], const double X2[800], const
  double X3[800], signed char s1, signed char s2, signed char s3, short n_search,
  double diff, double M123_f[16])
{
  double M1[16];
  double M2[16];
  double unusedExpr[16];
  int i0;
  int i1;
  double M123[16];
  int i2;
  double CA;
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

  double step;
  double n_step;
  int m;
  double CA1;
  double CA2;
  boolean_T exitg1;
  double eps;
  int j;
  int b_j;
  double a;
  double b_a[16];
  double M123_r[16];
  double M123_l[16];
  double X1_i_data[800];
  double X2_k_data[800];
  double X3_j_data[800];
  double y_data[800];
  double b_y_data[800];
  double a_data[800];
  int i;
  int k;
  int l;
  int loop_ub;
  int i3;
  int X2_k_size_idx_1;
  int i4;
  int i5;
  int X3_j_size_idx_1;
  int i6;
  int i7;
  int y_size_idx_1;
  int i8;
  int y_size[2];
  int tmp_size[2];
  double tmp_data[16];
  int unnamed_idx_0;

  /*  This fucntion calculate the 2nd order approximation of the mean of the */
  /*  convolution of two probability density functions on SE(3). */
  /*  Input: M1_hat and M2_hat denotes the mean before orthogonalization */
  /*  Future Work: To be determined which is the better M12 */
  mean_Taylor_2nd(X1, s1, n_search, M1);
  mean_Taylor_2nd(X2, s2, n_search, M2);
  mean_Taylor_2nd(X3, s3, n_search, unusedExpr);

  /*  This initial guess is not good */
  /*  M123 = M1*M2*M3; % Initial guess of M12 */
  /*  Another possible way to calculate M123 */
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      M123[i0 + (i1 << 2)] = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        M123[i0 + (i1 << 2)] += M1[i0 + (i2 << 2)] * M2[i2 + (i1 << 2)];
      }
    }
  }

  b_mrdivide(M123, M1);
  memcpy(&M123_f[0], &M123[0], sizeof(double) << 4);

  /*  Final M12 */
  /*  Perturb M_t1 along each direction defined by the Lie algebra element of */
  /*  SE(3) */
  CA = rtInf;
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

  /*  diff = 10^-12; */
  step = 1.0;
  n_step = 0.0;
  if (s1 == 0) {
    m = 4;
  } else {
    m = (s1 == 1);
  }

  CA1 = 0.0;
  CA2 = 0.0;
  exitg1 = false;
  while ((!exitg1) && (fabs(CA) > diff)) {
    /*  Adjust the step length */
    if (fabs(CA) > 100.0) {
      eps = 1.0;
    } else if ((fabs(CA) > 1.0) && (fabs(CA) < 100.0)) {
      eps = 0.1;
    } else if ((fabs(CA) > 0.01) && (fabs(CA) < 1.0)) {
      eps = 0.001;
    } else if (fabs(CA) < 0.01) {
      eps = 0.0001;
    } else if (fabs(CA) < 1.0E-8) {
      eps = 1.0E-5;
    } else {
      eps = 0.001;
    }

    for (j = -1; j + 1 <= 6 - m; j++) {
      b_j = m + j;

      /*  disp(step) */
      a = step * eps;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          b_a[i1 + (i0 << 2)] = a * (double)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      expm(b_a, M1);
      a = -step * eps;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          M123_r[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            M123_r[i0 + (i1 << 2)] += M123_f[i0 + (i2 << 2)] * M1[i2 + (i1 << 2)];
          }

          b_a[i1 + (i0 << 2)] = a * (double)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      expm(b_a, M1);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          M123_l[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            M123_l[i0 + (i1 << 2)] += M123_f[i0 + (i2 << 2)] * M1[i2 + (i1 << 2)];
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        M1[i0] = 0.0;
        M2[i0] = 0.0;
      }

      for (i = 0; i < 50; i++) {
        for (k = 0; k < 50; k++) {
          for (l = 0; l < 50; l++) {
            i0 = (i << 2) + 1;
            i1 = (1 + i) << 2;
            if (i0 > i1) {
              i0 = 0;
              i1 = 0;
            } else {
              i0--;
            }

            loop_ub = i1 - i0;
            for (i2 = 0; i2 < loop_ub; i2++) {
              for (i3 = 0; i3 < 4; i3++) {
                X1_i_data[i3 + (i2 << 2)] = X1[i3 + ((i0 + i2) << 2)];
              }
            }

            i2 = (k << 2) + 1;
            i3 = (1 + k) << 2;
            if (i2 > i3) {
              i2 = 0;
              i3 = 0;
            } else {
              i2--;
            }

            X2_k_size_idx_1 = i3 - i2;
            loop_ub = i3 - i2;
            for (i4 = 0; i4 < loop_ub; i4++) {
              for (i5 = 0; i5 < 4; i5++) {
                X2_k_data[i5 + (i4 << 2)] = X2[i5 + ((i2 + i4) << 2)];
              }
            }

            i4 = (l << 2) + 1;
            i5 = (1 + l) << 2;
            if (i4 > i5) {
              i4 = 0;
              i5 = 0;
            } else {
              i4--;
            }

            X3_j_size_idx_1 = i5 - i4;
            loop_ub = i5 - i4;
            for (i6 = 0; i6 < loop_ub; i6++) {
              for (i7 = 0; i7 < 4; i7++) {
                X3_j_data[i7 + (i6 << 2)] = X2[i7 + ((i4 + i6) << 2)];
              }
            }

            if (i1 - i0 == 1) {
              y_size_idx_1 = X2_k_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X2_k_size_idx_1; i7++) {
                  y_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    y_data[i6 + (i7 << 2)] += X1_i_data[i6 + (i8 << 2)] *
                      X2_k_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              y_size_idx_1 = (unsigned char)(i3 - i2);
              loop_ub = (unsigned char)(i3 - i2) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                y_data[i6] = 0.0;
              }

              eml_xgemm(i3 - i2, i1 - i0, X1_i_data, X2_k_data, i1 - i0, y_data);
            }

            if (y_size_idx_1 == 1) {
              y_size[0] = 4;
              y_size[1] = X3_j_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X3_j_size_idx_1; i7++) {
                  b_y_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    b_y_data[i6 + (i7 << 2)] += y_data[i6 + (i8 << 2)] *
                      X3_j_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              y_size[0] = 4;
              y_size[1] = (unsigned char)(i5 - i4);
              loop_ub = (unsigned char)(i5 - i4) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                b_y_data[i6] = 0.0;
              }

              eml_xgemm(i5 - i4, y_size_idx_1, y_data, X3_j_data, y_size_idx_1,
                        b_y_data);
            }

            mrdivide(b_y_data, y_size, M123_r, tmp_data, tmp_size);
            memcpy(&a_data[0], &tmp_data[0], sizeof(double) << 4);
            unnamed_idx_0 = i1 - i0;
            loop_ub = (unsigned char)unnamed_idx_0 << 2;
            for (i6 = 0; i6 < loop_ub; i6++) {
              y_data[i6] = 0.0;
            }

            eml_xgemm(i1 - i0, 4, a_data, X1_i_data, 4, y_data);
            if ((unsigned char)unnamed_idx_0 == 1) {
              y_size[1] = X2_k_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X2_k_size_idx_1; i7++) {
                  b_y_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    b_y_data[i6 + (i7 << 2)] += y_data[i6 + (i8 << 2)] *
                      X2_k_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              y_size[1] = (unsigned char)(i3 - i2);
              loop_ub = (unsigned char)(i3 - i2) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                b_y_data[i6] = 0.0;
              }

              eml_xgemm(i3 - i2, (unsigned char)unnamed_idx_0, y_data, X2_k_data,
                        (unsigned char)unnamed_idx_0, b_y_data);
            }

            if (y_size[1] == 1) {
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X3_j_size_idx_1; i7++) {
                  a_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    a_data[i6 + (i7 << 2)] += b_y_data[i6 + (i8 << 2)] *
                      X3_j_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              loop_ub = (unsigned char)(i5 - i4) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                a_data[i6] = 0.0;
              }

              eml_xgemm(i5 - i4, y_size[1], b_y_data, X3_j_data, y_size[1],
                        a_data);
            }

            for (i6 = 0; i6 < 16; i6++) {
              M1[i6] += a_data[i6];
            }

            if (i1 - i0 == 1) {
              y_size_idx_1 = X2_k_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X2_k_size_idx_1; i7++) {
                  y_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    y_data[i6 + (i7 << 2)] += X1_i_data[i6 + (i8 << 2)] *
                      X2_k_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              y_size_idx_1 = (unsigned char)(i3 - i2);
              loop_ub = (unsigned char)(i3 - i2) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                y_data[i6] = 0.0;
              }

              eml_xgemm(i3 - i2, i1 - i0, X1_i_data, X2_k_data, i1 - i0, y_data);
            }

            if (y_size_idx_1 == 1) {
              y_size[0] = 4;
              y_size[1] = X3_j_size_idx_1;
              for (i6 = 0; i6 < 4; i6++) {
                for (i7 = 0; i7 < X3_j_size_idx_1; i7++) {
                  b_y_data[i6 + (i7 << 2)] = 0.0;
                  for (i8 = 0; i8 < 4; i8++) {
                    b_y_data[i6 + (i7 << 2)] += y_data[i6 + (i8 << 2)] *
                      X3_j_data[i8 + (i7 << 2)];
                  }
                }
              }
            } else {
              y_size[0] = 4;
              y_size[1] = (unsigned char)(i5 - i4);
              loop_ub = (unsigned char)(i5 - i4) << 2;
              for (i6 = 0; i6 < loop_ub; i6++) {
                b_y_data[i6] = 0.0;
              }

              eml_xgemm(i5 - i4, y_size_idx_1, y_data, X3_j_data, y_size_idx_1,
                        b_y_data);
            }

            mrdivide(b_y_data, y_size, M123_l, tmp_data, tmp_size);
            memcpy(&a_data[0], &tmp_data[0], sizeof(double) << 4);
            unnamed_idx_0 = i1 - i0;
            loop_ub = (unsigned char)unnamed_idx_0 << 2;
            for (i6 = 0; i6 < loop_ub; i6++) {
              y_data[i6] = 0.0;
            }

            eml_xgemm(i1 - i0, 4, a_data, X1_i_data, 4, y_data);
            if ((unsigned char)unnamed_idx_0 == 1) {
              y_size[1] = X2_k_size_idx_1;
              for (i0 = 0; i0 < 4; i0++) {
                for (i1 = 0; i1 < X2_k_size_idx_1; i1++) {
                  b_y_data[i0 + (i1 << 2)] = 0.0;
                  for (i2 = 0; i2 < 4; i2++) {
                    b_y_data[i0 + (i1 << 2)] += y_data[i0 + (i2 << 2)] *
                      X2_k_data[i2 + (i1 << 2)];
                  }
                }
              }
            } else {
              y_size[1] = (unsigned char)(i3 - i2);
              loop_ub = (unsigned char)(i3 - i2) << 2;
              for (i0 = 0; i0 < loop_ub; i0++) {
                b_y_data[i0] = 0.0;
              }

              eml_xgemm(i3 - i2, (unsigned char)unnamed_idx_0, y_data, X2_k_data,
                        (unsigned char)unnamed_idx_0, b_y_data);
            }

            if (y_size[1] == 1) {
              for (i0 = 0; i0 < 4; i0++) {
                for (i1 = 0; i1 < X3_j_size_idx_1; i1++) {
                  a_data[i0 + (i1 << 2)] = 0.0;
                  for (i2 = 0; i2 < 4; i2++) {
                    a_data[i0 + (i1 << 2)] += b_y_data[i0 + (i2 << 2)] *
                      X3_j_data[i2 + (i1 << 2)];
                  }
                }
              }
            } else {
              loop_ub = (unsigned char)(i5 - i4) << 2;
              for (i0 = 0; i0 < loop_ub; i0++) {
                a_data[i0] = 0.0;
              }

              eml_xgemm(i5 - i4, y_size[1], b_y_data, X3_j_data, y_size[1],
                        a_data);
            }

            for (i0 = 0; i0 < 16; i0++) {
              M2[i0] += a_data[i0];
            }
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        M1[i0] = (M123[i0] - 0.0001 * M1[i0]) - 0.75 * M123_r[i0];
        M2[i0] = (M123[i0] - 0.0001 * M2[i0]) - 0.75 * M123_l[i0];
      }

      if (m == 4) {
        a = norm(*(double (*)[3])&M1[12]);
        CA1 = a * a;
        a = norm(*(double (*)[3])&M2[12]);
        CA2 = a * a;
      } else if (m == 1) {
        a = b_norm(M1);
        CA1 = a * a;
        a = b_norm(M2);
        CA2 = a * a;
      } else {
        CA1 = -1.0;
        CA2 = -1.0;
      }

      if ((CA1 <= CA2) && (CA1 < CA)) {
        CA = CA1;
        memcpy(&M123_f[0], &M123_r[0], sizeof(double) << 4);
        step = 1.0;

        /*  fprintf('Found a descent direction along %d \n', j) */
        /*  disp(MX1cost) */
        /*  disp(CA) */
      } else if ((CA2 < CA1) && (CA2 < CA)) {
        CA = CA2;
        memcpy(&M123_f[0], &M123_l[0], sizeof(double) << 4);
        step = 1.0;

        /*  fprintf('Found a descent direction along -%d \n', j) */
        /*  disp(MX2cost) */
        /*  disp(CA) */
      } else {
        /*  fprintf('Not a descent direction along +/-%d \n', j) */
        if (CA > 10.0) {
          step = 1.0;
        } else {
          n_step++;
          if (n_step == (6.0 - (double)m) + 1.0) {
            n_step = 0.0;
            step++;
          }
        }
      }
    }

    f_fprintf(CA1, CA2, CA);

    /*  fprintf('Value of the cost function is %f \n', CA2); */
    /*  fprintf('Value of the cost function is %f \n', CA); */
    if (step == 20.0) {
      exitg1 = true;
    }
  }
}

/*
 * File trailer for mean_double_convl_2nd.c
 *
 * [EOF]
 */
