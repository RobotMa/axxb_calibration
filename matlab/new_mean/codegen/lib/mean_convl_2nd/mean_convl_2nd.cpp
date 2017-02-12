//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean_convl_2nd.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 15-Jul-2015 12:00:44
//

// Include Files
#include "rt_nonfinite.h"
#include "mean_convl_2nd.h"
#include "mean_convl_2nd_emxutil.h"
#include "mrdivide.h"
#include "fprintf.h"
#include "norm.h"
#include "expm.h"
#include "mean_Taylor_2nd.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const emxArray_real_T *X1
//                const emxArray_real_T *X2
//                signed char s1
//                signed char s2
//                short n_search
//                double M12_f[16]
// Return Type  : void
//
void mean_convl_2nd(const emxArray_real_T *X1, const emxArray_real_T *X2, signed
                    char s1, signed char s2, short n_search, double M12_f[16])
{
  double n1;
  double n2;
  double M1[16];
  double M2[16];
  int i0;
  int i1;
  double M12[16];
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
  emxArray_real_T *X1_i;
  emxArray_real_T *X2_k;
  emxArray_real_T *y;
  emxArray_real_T *a;
  boolean_T exitg1;
  double eps;
  int j;
  int b_j;
  double b_a;
  double c_a[16];
  double M12_r[16];
  double M12_l[16];
  int i;
  int k;
  unsigned int u0;
  int loop_ub;
  int i3;
  int i4;
  int i5;
  int i6;
  int b_k;
  int c;
  int cr;
  int ic;
  int br;
  int ar;
  int ib;
  int ia;
  int tmp_size[2];
  double b_M1;
  double b_M2;
  double b_y;
  double c_y;
  double CA1;
  double CA2;

  //  This fucntion calculate the 2nd order approximation of the mean of the
  //  convolution of two probability density functions on SE(3).
  //  Input: X1 and X2 denote the data streams
  n1 = (double)X1->size[1] / 4.0;
  n2 = (double)X2->size[1] / 4.0;
  if (n1 != n2) {
    b_fprintf();
  }

  mean_Taylor_2nd(X1, s1, n_search, M1);
  mean_Taylor_2nd(X2, s2, n_search, M2);
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      M12[i0 + (i1 << 2)] = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        M12[i0 + (i1 << 2)] += M1[i0 + (i2 << 2)] * M2[i2 + (i1 << 2)];
      }
    }
  }

  //  Initial guess of M12
  memcpy(&M12_f[0], &M12[0], sizeof(double) << 4);

  //  Final M12
  //  Perturb M_t1 along each direction defined by the Lie algebra element of
  //  SE(3)
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

  step = 1.0;
  n_step = 0.0;
  if (s1 == 0) {
    m = 4;
  } else {
    m = (s1 == 1);
  }

  emxInit_real_T(&X1_i, 2);
  emxInit_real_T(&X2_k, 2);
  emxInit_real_T(&y, 2);
  emxInit_real_T(&a, 2);
  exitg1 = false;
  while ((!exitg1) && (fabs(CA) > 1.0E-12)) {
    //  Adjust the step length
    if (fabs(CA) > 0.001) {
      eps = 0.05;
    } else if (fabs(CA) < 1.0E-6) {
      eps = 0.0001;
    } else if (fabs(CA) < 1.0E-8) {
      eps = 1.0E-5;
    } else if (fabs(CA) < 1.0E-9) {
      eps = 1.0E-6;
    } else {
      eps = 0.001;
    }

    //  Approximation of rotation is good so far so we only further optimize
    //  on translation
    for (j = -1; j + 1 <= 6 - m; j++) {
      b_j = m + j;

      //  disp(step)
      b_a = step * eps;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          c_a[i1 + (i0 << 2)] = b_a * (double)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      expm(c_a, M1);
      b_a = -step * eps;
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          M12_r[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            M12_r[i0 + (i1 << 2)] += M12_f[i0 + (i2 << 2)] * M1[i2 + (i1 << 2)];
          }

          c_a[i1 + (i0 << 2)] = b_a * (double)E[(i1 + (i0 << 2)) + (b_j << 4)];
        }
      }

      expm(c_a, M1);
      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          M12_l[i0 + (i1 << 2)] = 0.0;
          for (i2 = 0; i2 < 4; i2++) {
            M12_l[i0 + (i1 << 2)] += M12_f[i0 + (i2 << 2)] * M1[i2 + (i1 << 2)];
          }
        }
      }

      for (i0 = 0; i0 < 16; i0++) {
        M1[i0] = 0.0;
        M2[i0] = 0.0;
      }

      for (i = 0; i < (int)n1; i++) {
        for (k = 0; k < (int)n2; k++) {
          i0 = (i << 2) + 1;
          u0 = (unsigned int)(1 + i) << 2;
          if ((unsigned int)i0 > u0) {
            i0 = 1;
            i1 = 1;
          } else {
            i1 = (int)u0 + 1;
          }

          i2 = X1_i->size[0] * X1_i->size[1];
          X1_i->size[0] = 4;
          X1_i->size[1] = i1 - i0;
          emxEnsureCapacity((emxArray__common *)X1_i, i2, (int)sizeof(double));
          loop_ub = i1 - i0;
          for (i2 = 0; i2 < loop_ub; i2++) {
            for (i3 = 0; i3 < 4; i3++) {
              X1_i->data[i3 + X1_i->size[0] * i2] = X1->data[i3 + X1->size[0] *
                ((i0 + i2) - 1)];
            }
          }

          i2 = (k << 2) + 1;
          u0 = (unsigned int)(1 + k) << 2;
          if ((unsigned int)i2 > u0) {
            i2 = 1;
            i3 = 1;
          } else {
            i3 = (int)u0 + 1;
          }

          i4 = X2_k->size[0] * X2_k->size[1];
          X2_k->size[0] = 4;
          X2_k->size[1] = i3 - i2;
          emxEnsureCapacity((emxArray__common *)X2_k, i4, (int)sizeof(double));
          loop_ub = i3 - i2;
          for (i4 = 0; i4 < loop_ub; i4++) {
            for (i5 = 0; i5 < 4; i5++) {
              X2_k->data[i5 + X2_k->size[0] * i4] = X2->data[i5 + X2->size[0] *
                ((i2 + i4) - 1)];
            }
          }

          if (i1 - i0 == 1) {
            i4 = y->size[0] * y->size[1];
            y->size[0] = 4;
            y->size[1] = X2_k->size[1];
            emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
            for (i4 = 0; i4 < 4; i4++) {
              loop_ub = X2_k->size[1];
              for (i5 = 0; i5 < loop_ub; i5++) {
                y->data[i4 + y->size[0] * i5] = 0.0;
                for (i6 = 0; i6 < 4; i6++) {
                  y->data[i4 + y->size[0] * i5] += X1_i->data[i4 + (i6 << 2)] *
                    X2_k->data[i6 + X2_k->size[0] * i5];
                }
              }
            }
          } else {
            b_k = i1 - i0;
            i4 = y->size[0] * y->size[1];
            y->size[0] = 4;
            emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
            i4 = y->size[0] * y->size[1];
            y->size[1] = i3 - i2;
            emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
            loop_ub = (i3 - i2) << 2;
            for (i4 = 0; i4 < loop_ub; i4++) {
              y->data[i4] = 0.0;
            }

            if (i3 - i2 == 0) {
            } else {
              c = ((i3 - i2) - 1) << 2;
              for (cr = 0; cr <= c; cr += 4) {
                for (ic = cr + 1; ic <= cr + 4; ic++) {
                  y->data[ic - 1] = 0.0;
                }
              }

              br = 0;
              for (cr = 0; cr <= c; cr += 4) {
                ar = 0;
                i4 = br + b_k;
                for (ib = br; ib + 1 <= i4; ib++) {
                  if (X2->data[ib % 4 + X2->size[0] * ((i2 + (ib >> 2)) - 1)] !=
                      0.0) {
                    ia = ar;
                    for (ic = cr; ic + 1 <= cr + 4; ic++) {
                      ia++;
                      y->data[ic] += X2->data[ib % 4 + X2->size[0] * ((i2 + (ib >>
                        2)) - 1)] * X1->data[(ia - 1) % 4 + X1->size[0] * ((i0 +
                        ((ia - 1) >> 2)) - 1)];
                    }
                  }

                  ar += 4;
                }

                br += b_k;
              }
            }
          }

          mrdivide(y, M12_r, c_a, tmp_size);
          i4 = a->size[0] * a->size[1];
          a->size[0] = 4;
          a->size[1] = 4;
          emxEnsureCapacity((emxArray__common *)a, i4, (int)sizeof(double));
          for (i4 = 0; i4 < 16; i4++) {
            a->data[i4] = c_a[i4];
          }

          i4 = y->size[0] * y->size[1];
          y->size[0] = 4;
          emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
          i4 = y->size[0] * y->size[1];
          y->size[1] = i1 - i0;
          emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
          loop_ub = (i1 - i0) << 2;
          for (i4 = 0; i4 < loop_ub; i4++) {
            y->data[i4] = 0.0;
          }

          if (i1 - i0 == 0) {
          } else {
            c = ((i1 - i0) - 1) << 2;
            for (cr = 0; cr <= c; cr += 4) {
              for (ic = cr + 1; ic <= cr + 4; ic++) {
                y->data[ic - 1] = 0.0;
              }
            }

            br = 0;
            for (cr = 0; cr <= c; cr += 4) {
              ar = 0;
              for (ib = br; ib + 1 <= br + 4; ib++) {
                if (X1->data[ib % 4 + X1->size[0] * ((i0 + (ib >> 2)) - 1)] !=
                    0.0) {
                  ia = ar;
                  for (ic = cr; ic + 1 <= cr + 4; ic++) {
                    ia++;
                    y->data[ic] += X1->data[ib % 4 + X1->size[0] * ((i0 + (ib >>
                      2)) - 1)] * a->data[ia - 1];
                  }
                }

                ar += 4;
              }

              br += 4;
            }
          }

          if (y->size[1] == 1) {
            i4 = a->size[0] * a->size[1];
            a->size[0] = 4;
            a->size[1] = X2_k->size[1];
            emxEnsureCapacity((emxArray__common *)a, i4, (int)sizeof(double));
            for (i4 = 0; i4 < 4; i4++) {
              loop_ub = X2_k->size[1];
              for (i5 = 0; i5 < loop_ub; i5++) {
                a->data[i4 + a->size[0] * i5] = 0.0;
                for (i6 = 0; i6 < 4; i6++) {
                  a->data[i4 + a->size[0] * i5] += y->data[i4 + (i6 << 2)] *
                    X2_k->data[i6 + X2_k->size[0] * i5];
                }
              }
            }
          } else {
            b_k = y->size[1];
            i4 = a->size[0] * a->size[1];
            a->size[0] = 4;
            emxEnsureCapacity((emxArray__common *)a, i4, (int)sizeof(double));
            i4 = a->size[0] * a->size[1];
            a->size[1] = i3 - i2;
            emxEnsureCapacity((emxArray__common *)a, i4, (int)sizeof(double));
            loop_ub = (i3 - i2) << 2;
            for (i4 = 0; i4 < loop_ub; i4++) {
              a->data[i4] = 0.0;
            }

            if (i3 - i2 == 0) {
            } else {
              c = ((i3 - i2) - 1) << 2;
              for (cr = 0; cr <= c; cr += 4) {
                for (ic = cr + 1; ic <= cr + 4; ic++) {
                  a->data[ic - 1] = 0.0;
                }
              }

              br = 0;
              for (cr = 0; cr <= c; cr += 4) {
                ar = 0;
                i4 = br + b_k;
                for (ib = br; ib + 1 <= i4; ib++) {
                  if (X2->data[ib % 4 + X2->size[0] * ((i2 + (ib >> 2)) - 1)] !=
                      0.0) {
                    ia = ar;
                    for (ic = cr; ic + 1 <= cr + 4; ic++) {
                      ia++;
                      a->data[ic] += X2->data[ib % 4 + X2->size[0] * ((i2 + (ib >>
                        2)) - 1)] * y->data[ia - 1];
                    }
                  }

                  ar += 4;
                }

                br += b_k;
              }
            }
          }

          for (i4 = 0; i4 < 16; i4++) {
            b_M1 = M1[i4] + a->data[i4];
            M1[i4] = b_M1;
          }

          if (i1 - i0 == 1) {
            i4 = y->size[0] * y->size[1];
            y->size[0] = 4;
            y->size[1] = X2_k->size[1];
            emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
            for (i4 = 0; i4 < 4; i4++) {
              loop_ub = X2_k->size[1];
              for (i5 = 0; i5 < loop_ub; i5++) {
                y->data[i4 + y->size[0] * i5] = 0.0;
                for (i6 = 0; i6 < 4; i6++) {
                  y->data[i4 + y->size[0] * i5] += X1_i->data[i4 + (i6 << 2)] *
                    X2_k->data[i6 + X2_k->size[0] * i5];
                }
              }
            }
          } else {
            b_k = i1 - i0;
            i4 = y->size[0] * y->size[1];
            y->size[0] = 4;
            emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
            i4 = y->size[0] * y->size[1];
            y->size[1] = i3 - i2;
            emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
            loop_ub = (i3 - i2) << 2;
            for (i4 = 0; i4 < loop_ub; i4++) {
              y->data[i4] = 0.0;
            }

            if (i3 - i2 == 0) {
            } else {
              c = ((i3 - i2) - 1) << 2;
              for (cr = 0; cr <= c; cr += 4) {
                for (ic = cr + 1; ic <= cr + 4; ic++) {
                  y->data[ic - 1] = 0.0;
                }
              }

              br = 0;
              for (cr = 0; cr <= c; cr += 4) {
                ar = 0;
                i4 = br + b_k;
                for (ib = br; ib + 1 <= i4; ib++) {
                  if (X2->data[ib % 4 + X2->size[0] * ((i2 + (ib >> 2)) - 1)] !=
                      0.0) {
                    ia = ar;
                    for (ic = cr; ic + 1 <= cr + 4; ic++) {
                      ia++;
                      y->data[ic] += X2->data[ib % 4 + X2->size[0] * ((i2 + (ib >>
                        2)) - 1)] * X1->data[(ia - 1) % 4 + X1->size[0] * ((i0 +
                        ((ia - 1) >> 2)) - 1)];
                    }
                  }

                  ar += 4;
                }

                br += b_k;
              }
            }
          }

          mrdivide(y, M12_l, c_a, tmp_size);
          i4 = a->size[0] * a->size[1];
          a->size[0] = 4;
          a->size[1] = 4;
          emxEnsureCapacity((emxArray__common *)a, i4, (int)sizeof(double));
          for (i4 = 0; i4 < 16; i4++) {
            a->data[i4] = c_a[i4];
          }

          i4 = y->size[0] * y->size[1];
          y->size[0] = 4;
          emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
          i4 = y->size[0] * y->size[1];
          y->size[1] = i1 - i0;
          emxEnsureCapacity((emxArray__common *)y, i4, (int)sizeof(double));
          loop_ub = (i1 - i0) << 2;
          for (i4 = 0; i4 < loop_ub; i4++) {
            y->data[i4] = 0.0;
          }

          if (i1 - i0 == 0) {
          } else {
            c = ((i1 - i0) - 1) << 2;
            for (cr = 0; cr <= c; cr += 4) {
              for (ic = cr + 1; ic <= cr + 4; ic++) {
                y->data[ic - 1] = 0.0;
              }
            }

            br = 0;
            for (cr = 0; cr <= c; cr += 4) {
              ar = 0;
              for (ib = br; ib + 1 <= br + 4; ib++) {
                if (X1->data[ib % 4 + X1->size[0] * ((i0 + (ib >> 2)) - 1)] !=
                    0.0) {
                  ia = ar;
                  for (ic = cr; ic + 1 <= cr + 4; ic++) {
                    ia++;
                    y->data[ic] += X1->data[ib % 4 + X1->size[0] * ((i0 + (ib >>
                      2)) - 1)] * a->data[ia - 1];
                  }
                }

                ar += 4;
              }

              br += 4;
            }
          }

          if (y->size[1] == 1) {
            i0 = a->size[0] * a->size[1];
            a->size[0] = 4;
            a->size[1] = X2_k->size[1];
            emxEnsureCapacity((emxArray__common *)a, i0, (int)sizeof(double));
            for (i0 = 0; i0 < 4; i0++) {
              loop_ub = X2_k->size[1];
              for (i1 = 0; i1 < loop_ub; i1++) {
                a->data[i0 + a->size[0] * i1] = 0.0;
                for (i2 = 0; i2 < 4; i2++) {
                  a->data[i0 + a->size[0] * i1] += y->data[i0 + (i2 << 2)] *
                    X2_k->data[i2 + X2_k->size[0] * i1];
                }
              }
            }
          } else {
            b_k = y->size[1];
            i0 = a->size[0] * a->size[1];
            a->size[0] = 4;
            emxEnsureCapacity((emxArray__common *)a, i0, (int)sizeof(double));
            i0 = a->size[0] * a->size[1];
            a->size[1] = i3 - i2;
            emxEnsureCapacity((emxArray__common *)a, i0, (int)sizeof(double));
            loop_ub = (i3 - i2) << 2;
            for (i0 = 0; i0 < loop_ub; i0++) {
              a->data[i0] = 0.0;
            }

            if (i3 - i2 == 0) {
            } else {
              c = ((i3 - i2) - 1) << 2;
              for (cr = 0; cr <= c; cr += 4) {
                for (ic = cr + 1; ic <= cr + 4; ic++) {
                  a->data[ic - 1] = 0.0;
                }
              }

              br = 0;
              for (cr = 0; cr <= c; cr += 4) {
                ar = 0;
                i0 = br + b_k;
                for (ib = br; ib + 1 <= i0; ib++) {
                  if (X2->data[ib % 4 + X2->size[0] * ((i2 + (ib >> 2)) - 1)] !=
                      0.0) {
                    ia = ar;
                    for (ic = cr; ic + 1 <= cr + 4; ic++) {
                      ia++;
                      a->data[ic] += X2->data[ib % 4 + X2->size[0] * ((i2 + (ib >>
                        2)) - 1)] * y->data[ia - 1];
                    }
                  }

                  ar += 4;
                }

                br += b_k;
              }
            }
          }

          for (i0 = 0; i0 < 16; i0++) {
            b_M2 = M2[i0] + a->data[i0];
            M2[i0] = b_M2;
          }
        }
      }

      b_y = 0.25 / (n1 * n1);
      c_y = 0.25 / (n1 * n1);
      for (i0 = 0; i0 < 16; i0++) {
        M1[i0] = (M12[i0] - b_y * M1[i0]) - 0.75 * M12_r[i0];
        M2[i0] = (M12[i0] - c_y * M2[i0]) - 0.75 * M12_l[i0];
      }

      if (m == 4) {
        b_a = norm(*(double (*)[3])&M1[12]);
        CA1 = b_a * b_a;
        b_a = norm(*(double (*)[3])&M2[12]);
        CA2 = b_a * b_a;
      } else if (m == 1) {
        b_a = b_norm(M1);
        CA1 = b_a * b_a;
        b_a = b_norm(M2);
        CA2 = b_a * b_a;
      } else {
        CA1 = -1.0;
        CA2 = -1.0;
      }

      if ((CA1 <= CA2) && (CA1 < CA)) {
        CA = CA1;
        memcpy(&M12_f[0], &M12_r[0], sizeof(double) << 4);
        step = 1.0;

        //  fprintf('Found a descent direction along %d \n', j)
        //  disp(MX1cost)
        //  disp(CA)
      } else if ((CA2 < CA1) && (CA2 < CA)) {
        CA = CA2;
        memcpy(&M12_f[0], &M12_l[0], sizeof(double) << 4);
        step = 1.0;

        //  fprintf('Found a descent direction along -%d \n', j)
        //  disp(MX2cost)
        //  disp(CA)
      } else {
        //  fprintf('Not a descent direction along +/-%d \n', j)
        n_step++;
        if (n_step == (6.0 - (double)m) + 1.0) {
          n_step = 0.0;
          step++;
        }
      }

      h_fprintf(CA);
    }

    if (step == n_search) {
      h_fprintf(CA);
      exitg1 = true;
    }
  }

  emxFree_real_T(&a);
  emxFree_real_T(&y);
  emxFree_real_T(&X2_k);
  emxFree_real_T(&X1_i);
}

//
// File trailer for mean_convl_2nd.cpp
//
// [EOF]
//
