//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: batchEDSolve.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 24-Jul-2015 17:07:45
//

// Include Files
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "norm.h"
#include "eye.h"
#include "det.h"
#include "so3_vec.h"
#include "mpower.h"
#include "param_extract.h"
#include "eig.h"
#include "distibutionPropsMex.h"
#include "batchEDSolve_rtwutil.h"

// Function Declarations
static void eml_xgemm(int m, int n, const creal_T A_data[], int lda, const
                      creal_T B_data[], creal_T C_data[], int ldc);

// Function Definitions

//
// Arguments    : int m
//                int n
//                const creal_T A_data[]
//                int lda
//                const creal_T B_data[]
//                creal_T C_data[]
//                int ldc
// Return Type  : void
//
static void eml_xgemm(int m, int n, const creal_T A_data[], int lda, const
                      creal_T B_data[], creal_T C_data[], int ldc)
{
  int c;
  int cr;
  int i13;
  int ic;
  int br;
  int ar;
  int ib;
  double temp_re;
  double temp_im;
  int ia;
  if ((m == 0) || (n == 0)) {
  } else {
    c = ldc * (n - 1);
    cr = 0;
    while ((ldc > 0) && (cr <= c)) {
      i13 = cr + m;
      for (ic = cr; ic + 1 <= i13; ic++) {
        C_data[ic].re = 0.0;
        C_data[ic].im = 0.0;
      }

      cr += ldc;
    }

    br = 0;
    cr = 0;
    while ((ldc > 0) && (cr <= c)) {
      ar = -1;
      for (ib = br; ib + 1 <= br + 3; ib++) {
        if ((B_data[ib].re != 0.0) || (B_data[ib].im != 0.0)) {
          temp_re = B_data[ib].re - 0.0 * B_data[ib].im;
          temp_im = B_data[ib].im + 0.0 * B_data[ib].re;
          ia = ar;
          i13 = cr + m;
          for (ic = cr; ic + 1 <= i13; ic++) {
            ia++;
            C_data[ic].re += temp_re * A_data[ia].re - temp_im * A_data[ia].im;
            C_data[ic].im += temp_re * A_data[ia].im + temp_im * A_data[ia].re;
          }
        }

        ar += lda;
      }

      br += 3;
      cr += ldc;
    }
  }
}

//
// Arguments    : const emxArray_real_T *A
//                const emxArray_real_T *B
//                creal_T X[16]
//                double MeanA[16]
//                double MeanB[16]
//                double SigA[36]
//                double SigB[36]
// Return Type  : void
//
void batchEDSolve(const emxArray_real_T *A, const emxArray_real_T *B, creal_T X
                  [16], double MeanA[16], double MeanB[16], double SigA[36],
                  double SigB[36])
{
  double b_SigA[9];
  int i0;
  int i1;
  creal_T unusedU0[9];
  creal_T VA[9];
  creal_T unusedU1[9];
  creal_T Rx_solved[72];
  static const signed char iv0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  creal_T b_VA[9];
  creal_T dcv0[9];
  int ic;
  double temp_re;
  double temp_im;
  static const signed char iv1[9] = { -1, 0, 0, 0, -1, 0, 0, 0, 1 };

  static const signed char iv2[9] = { -1, 0, 0, 0, 1, 0, 0, 0, -1 };

  static const signed char iv3[9] = { 1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const signed char iv4[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  static const signed char iv5[9] = { 1, 0, 0, 0, 1, 0, 0, 0, -1 };

  static const signed char iv6[9] = { 1, 0, 0, 0, -1, 0, 0, 0, 1 };

  static const signed char iv7[9] = { -1, 0, 0, 0, 1, 0, 0, 0, 1 };

  double pa[3];
  double Na[9];
  double pb[3];
  double Nb[9];
  double na[3];
  double nb[3];
  double min2;
  int i;
  int k;
  int m;
  int c;
  int cr;
  int br;
  creal_T y_data[72];
  int ar;
  int ib;
  int loop_ub;
  int ia;
  creal_T b_y_data[72];
  creal_T tmp_data[576];
  int y_size[2];
  creal_T c_y_data[576];
  int a_size[2];
  creal_T a_data[576];
  int y_size_idx_0;
  int b_y_size[2];
  creal_T tx_temp_data[9];
  int Rx_solved_size[2];
  creal_T dc0;
  boolean_T guard1 = false;
  creal_T b_nb[3];
  creal_T b_na[3];
  creal_T Na_data[9];
  int Rx_size_idx_1;
  creal_T Rx_data[72];
  int c_y_size[2];
  creal_T b_a_data[72];
  creal_T tx_data[9];
  creal_T b_Rx_data[81];
  static const signed char iv8[4] = { 0, 0, 0, 1 };

  distibutionPropsMex(A, MeanA, SigA);
  distibutionPropsMex(B, MeanB, SigB);
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_SigA[i1 + 3 * i0] = SigA[i1 + 6 * i0];
    }
  }

  eig(b_SigA, VA, unusedU0);
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_SigA[i1 + 3 * i0] = SigB[i1 + 6 * i0];
    }
  }

  eig(b_SigA, unusedU0, unusedU1);
  memset(&Rx_solved[0], 0, 72U * sizeof(creal_T));

  //  if ~isreal(VA) || ~isreal(VB)
  //      fprintf('SVD of either SigA or SigB is not real.')
  //  end
  //  Rx_solved(:,:,1) = VA*Q1*VB';
  //  Rx_solved(:,:,2) = VA*Q2*VB';
  //  Rx_solved(:,:,3) = VA*Q3*VB';
  //  Rx_solved(:,:,4) = VA*Q4*VB';
  //  Rx_solved(:,:,5) = VA*-Q1*VB';
  //  Rx_solved(:,:,6) = VA*-Q2*VB';
  //  Rx_solved(:,:,7) = VA*-Q3*VB';
  //  Rx_solved(:,:,8) = VA*-Q4*VB';
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      unusedU1[i1 + 3 * i0].re = iv0[i1 + 3 * i0];
      unusedU1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * ic].re * unusedU1[ic + 3 * i1].re -
          VA[i0 + 3 * ic].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * ic].re * 0.0 + VA[i0 + 3 * ic].im *
          unusedU1[ic + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * i1].re = 0.0;
      Rx_solved[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = unusedU0[i1 + 3 * ic].re;
        temp_im = -unusedU0[i1 + 3 * ic].im;
        Rx_solved[i0 + 3 * i1].re += b_VA[i0 + 3 * ic].re * temp_re - b_VA[i0 +
          3 * ic].im * temp_im;
        Rx_solved[i0 + 3 * i1].im += b_VA[i0 + 3 * ic].re * temp_im + b_VA[i0 +
          3 * ic].im * temp_re;
      }

      dcv0[i1 + 3 * i0].re = iv1[i1 + 3 * i0];
      dcv0[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * ic].re * dcv0[ic + 3 * i1].re -
          VA[i0 + 3 * ic].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * ic].re * 0.0 + VA[i0 + 3 * ic].im *
          dcv0[ic + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (3 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (3 + i1)].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = unusedU0[i1 + 3 * ic].re;
        temp_im = -unusedU0[i1 + 3 * ic].im;
        Rx_solved[i0 + 3 * (3 + i1)].re += b_VA[i0 + 3 * ic].re * temp_re -
          b_VA[i0 + 3 * ic].im * temp_im;
        Rx_solved[i0 + 3 * (3 + i1)].im += b_VA[i0 + 3 * ic].re * temp_im +
          b_VA[i0 + 3 * ic].im * temp_re;
      }

      unusedU1[i1 + 3 * i0].re = iv2[i1 + 3 * i0];
      unusedU1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * ic].re * unusedU1[ic + 3 * i1].re -
          VA[i0 + 3 * ic].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * ic].re * 0.0 + VA[i0 + 3 * ic].im *
          unusedU1[ic + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (6 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (6 + i1)].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = unusedU0[i1 + 3 * ic].re;
        temp_im = -unusedU0[i1 + 3 * ic].im;
        Rx_solved[i0 + 3 * (6 + i1)].re += b_VA[i0 + 3 * ic].re * temp_re -
          b_VA[i0 + 3 * ic].im * temp_im;
        Rx_solved[i0 + 3 * (6 + i1)].im += b_VA[i0 + 3 * ic].re * temp_im +
          b_VA[i0 + 3 * ic].im * temp_re;
      }

      dcv0[i1 + 3 * i0].re = iv3[i1 + 3 * i0];
      dcv0[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * ic].re * dcv0[ic + 3 * i1].re -
          VA[i0 + 3 * ic].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * ic].re * 0.0 + VA[i0 + 3 * ic].im *
          dcv0[ic + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (9 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (9 + i1)].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = unusedU0[i1 + 3 * ic].re;
        temp_im = -unusedU0[i1 + 3 * ic].im;
        Rx_solved[i0 + 3 * (9 + i1)].re += b_VA[i0 + 3 * ic].re * temp_re -
          b_VA[i0 + 3 * ic].im * temp_im;
        Rx_solved[i0 + 3 * (9 + i1)].im += b_VA[i0 + 3 * ic].re * temp_im +
          b_VA[i0 + 3 * ic].im * temp_re;
      }

      unusedU1[i1 + 3 * i0].re = iv4[i1 + 3 * i0];
      unusedU1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * ic].re * unusedU1[ic + 3 * i1].re -
          VA[i0 + 3 * ic].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * ic].re * 0.0 + VA[i0 + 3 * ic].im *
          unusedU1[ic + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (12 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (12 + i1)].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = unusedU0[i1 + 3 * ic].re;
        temp_im = -unusedU0[i1 + 3 * ic].im;
        Rx_solved[i0 + 3 * (12 + i1)].re += b_VA[i0 + 3 * ic].re * temp_re -
          b_VA[i0 + 3 * ic].im * temp_im;
        Rx_solved[i0 + 3 * (12 + i1)].im += b_VA[i0 + 3 * ic].re * temp_im +
          b_VA[i0 + 3 * ic].im * temp_re;
      }

      dcv0[i1 + 3 * i0].re = iv5[i1 + 3 * i0];
      dcv0[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * ic].re * dcv0[ic + 3 * i1].re -
          VA[i0 + 3 * ic].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * ic].re * 0.0 + VA[i0 + 3 * ic].im *
          dcv0[ic + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (15 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (15 + i1)].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = unusedU0[i1 + 3 * ic].re;
        temp_im = -unusedU0[i1 + 3 * ic].im;
        Rx_solved[i0 + 3 * (15 + i1)].re += b_VA[i0 + 3 * ic].re * temp_re -
          b_VA[i0 + 3 * ic].im * temp_im;
        Rx_solved[i0 + 3 * (15 + i1)].im += b_VA[i0 + 3 * ic].re * temp_im +
          b_VA[i0 + 3 * ic].im * temp_re;
      }

      unusedU1[i1 + 3 * i0].re = iv6[i1 + 3 * i0];
      unusedU1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * ic].re * unusedU1[ic + 3 * i1].re -
          VA[i0 + 3 * ic].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * ic].re * 0.0 + VA[i0 + 3 * ic].im *
          unusedU1[ic + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (18 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (18 + i1)].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = unusedU0[i1 + 3 * ic].re;
        temp_im = -unusedU0[i1 + 3 * ic].im;
        Rx_solved[i0 + 3 * (18 + i1)].re += b_VA[i0 + 3 * ic].re * temp_re -
          b_VA[i0 + 3 * ic].im * temp_im;
        Rx_solved[i0 + 3 * (18 + i1)].im += b_VA[i0 + 3 * ic].re * temp_im +
          b_VA[i0 + 3 * ic].im * temp_re;
      }

      dcv0[i1 + 3 * i0].re = iv7[i1 + 3 * i0];
      dcv0[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_VA[i0 + 3 * i1].re = 0.0;
      b_VA[i0 + 3 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        b_VA[i0 + 3 * i1].re += VA[i0 + 3 * ic].re * dcv0[ic + 3 * i1].re -
          VA[i0 + 3 * ic].im * 0.0;
        b_VA[i0 + 3 * i1].im += VA[i0 + 3 * ic].re * 0.0 + VA[i0 + 3 * ic].im *
          dcv0[ic + 3 * i1].re;
      }
    }

    for (i1 = 0; i1 < 3; i1++) {
      Rx_solved[i0 + 3 * (21 + i1)].re = 0.0;
      Rx_solved[i0 + 3 * (21 + i1)].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = unusedU0[i1 + 3 * ic].re;
        temp_im = -unusedU0[i1 + 3 * ic].im;
        Rx_solved[i0 + 3 * (21 + i1)].re += b_VA[i0 + 3 * ic].re * temp_re -
          b_VA[i0 + 3 * ic].im * temp_im;
        Rx_solved[i0 + 3 * (21 + i1)].im += b_VA[i0 + 3 * ic].re * temp_im +
          b_VA[i0 + 3 * ic].im * temp_re;
      }
    }
  }

  param_extract(MeanA, &temp_re, Na, &temp_im, pa);
  param_extract(MeanB, &temp_re, Nb, &temp_im, pb);

  // Function to vectorize or hat an element in so(3)
  // files needed:
  // none
  // If input is skew-sym change to vector
  na[0] = -Na[7];
  na[1] = Na[6];
  na[2] = -Na[3];

  // Function to vectorize or hat an element in so(3)
  // files needed:
  // none
  // If input is skew-sym change to vector
  nb[0] = -Nb[7];
  nb[1] = Nb[6];
  nb[2] = -Nb[3];

  // min=inf;
  min2 = rtInf;
  for (i = 0; i < 8; i++) {
    i0 = 3 * i + 1;
    i1 = 3 * (1 + i);
    if (i0 > i1) {
      i0 = 0;
      i1 = 0;
    } else {
      i0--;
    }

    ic = 3 * i + 1;
    k = 3 * (1 + i);
    if (ic > k) {
      ic = 1;
      k = 1;
    } else {
      k++;
    }

    m = 3 * i + 1;
    c = 3 * (1 + i);
    if (m > c) {
      m = 0;
      c = 0;
    } else {
      m--;
    }

    cr = 3 * i + 1;
    br = 3 * (1 + i);
    if (cr > br) {
      cr = 1;
      br = 1;
    } else {
      br++;
    }

    ar = c - m;
    for (ib = 0; ib < 3; ib++) {
      loop_ub = c - m;
      for (ia = 0; ia < loop_ub; ia++) {
        y_data[ia + ar * ib].re = Rx_solved[ib + 3 * (m + ia)].re;
        y_data[ia + ar * ib].im = -Rx_solved[ib + 3 * (m + ia)].im;
      }
    }

    for (m = 0; m < 3; m++) {
      for (c = 0; c < 3; c++) {
        unusedU1[c + 3 * m].re = SigA[c + 6 * (3 + m)];
        unusedU1[c + 3 * m].im = 0.0;
      }
    }

    for (m = 0; m < ar; m++) {
      for (c = 0; c < 3; c++) {
        b_y_data[m + ar * c].re = 0.0;
        b_y_data[m + ar * c].im = 0.0;
        for (ib = 0; ib < 3; ib++) {
          b_y_data[m + ar * c].re += y_data[m + ar * ib].re * unusedU1[ib + 3 *
            c].re - y_data[m + ar * ib].im * 0.0;
          b_y_data[m + ar * c].im += y_data[m + ar * ib].re * 0.0 + y_data[m +
            ar * ib].im * unusedU1[ib + 3 * c].re;
        }
      }
    }

    loop_ub = ar * (br - cr);
    for (m = 0; m < loop_ub; m++) {
      tmp_data[m].re = 0.0;
      tmp_data[m].im = 0.0;
    }

    loop_ub = br - cr;
    for (m = 0; m < loop_ub; m++) {
      for (c = 0; c < 3; c++) {
        y_data[c + 3 * m] = Rx_solved[c + 3 * ((cr + m) - 1)];
      }
    }

    eml_xgemm(ar, br - cr, b_y_data, ar, y_data, tmp_data, ar);
    ar = i1 - i0;
    for (m = 0; m < 3; m++) {
      loop_ub = i1 - i0;
      for (c = 0; c < loop_ub; c++) {
        y_data[c + ar * m].re = Rx_solved[m + 3 * (i0 + c)].re;
        y_data[c + ar * m].im = -Rx_solved[m + 3 * (i0 + c)].im;
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        unusedU1[i1 + 3 * i0].re = SigA[i1 + 6 * i0];
        unusedU1[i1 + 3 * i0].im = 0.0;
      }
    }

    for (i0 = 0; i0 < ar; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_y_data[i0 + ar * i1].re = 0.0;
        b_y_data[i0 + ar * i1].im = 0.0;
        for (m = 0; m < 3; m++) {
          b_y_data[i0 + ar * i1].re += y_data[i0 + ar * m].re * unusedU1[m + 3 *
            i1].re - y_data[i0 + ar * m].im * 0.0;
          b_y_data[i0 + ar * i1].im += y_data[i0 + ar * m].re * 0.0 + y_data[i0
            + ar * m].im * unusedU1[m + 3 * i1].re;
        }
      }
    }

    y_size[0] = ar;
    y_size[1] = k - ic;
    loop_ub = ar * (k - ic);
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_y_data[i0].re = 0.0;
      c_y_data[i0].im = 0.0;
    }

    loop_ub = k - ic;
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        y_data[i1 + 3 * i0] = Rx_solved[i1 + 3 * ((ic + i0) - 1)];
      }
    }

    eml_xgemm(ar, k - ic, b_y_data, ar, y_data, c_y_data, ar);
    b_mpower(c_y_data, y_size, a_data, a_size);
    for (i0 = 0; i0 < 3; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        unusedU0[i1 + 3 * i0].re = SigB[i1 + 6 * (3 + i0)] - tmp_data[i1 + 3 *
          i0].re;
        unusedU0[i1 + 3 * i0].im = 0.0 - tmp_data[i1 + 3 * i0].im;
      }
    }

    if (a_size[1] == 1) {
      y_size_idx_0 = a_size[0];
      loop_ub = a_size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        for (i1 = 0; i1 < 3; i1++) {
          b_y_data[i0 + y_size_idx_0 * i1].re = 0.0;
          b_y_data[i0 + y_size_idx_0 * i1].im = 0.0;
          ic = 0;
          while (ic <= 0) {
            b_y_data[i0 + y_size_idx_0 * i1].re += a_data[i0].re * unusedU0[3 *
              i1].re - a_data[i0].im * unusedU0[3 * i1].im;
            b_y_data[i0 + y_size_idx_0 * i1].im += a_data[i0].re * unusedU0[3 *
              i1].im + a_data[i0].im * unusedU0[3 * i1].re;
            ic = 1;
          }
        }
      }
    } else {
      k = a_size[1];
      m = a_size[0];
      y_size_idx_0 = (signed char)a_size[0];
      loop_ub = (signed char)a_size[0] * 3;
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_y_data[i0].re = 0.0;
        b_y_data[i0].im = 0.0;
      }

      if (a_size[0] == 0) {
      } else {
        c = a_size[0] << 1;
        cr = 0;
        while ((m > 0) && (cr <= c)) {
          i0 = cr + m;
          for (ic = cr; ic + 1 <= i0; ic++) {
            b_y_data[ic].re = 0.0;
            b_y_data[ic].im = 0.0;
          }

          cr += m;
        }

        br = 0;
        cr = 0;
        while ((m > 0) && (cr <= c)) {
          ar = -1;
          i0 = br + k;
          for (ib = br; ib + 1 <= i0; ib++) {
            if ((unusedU0[ib].re != 0.0) || (unusedU0[ib].im != 0.0)) {
              temp_re = unusedU0[ib].re - 0.0 * unusedU0[ib].im;
              temp_im = unusedU0[ib].im + 0.0 * unusedU0[ib].re;
              ia = ar;
              i1 = cr + m;
              for (ic = cr; ic + 1 <= i1; ic++) {
                ia++;
                b_y_data[ic].re += temp_re * a_data[ia].re - temp_im * a_data[ia]
                  .im;
                b_y_data[ic].im += temp_re * a_data[ia].im + temp_im * a_data[ia]
                  .re;
              }
            }

            ar += m;
          }

          br += k;
          cr += m;
        }
      }
    }

    b_y_size[0] = 3;
    b_y_size[1] = y_size_idx_0;
    for (i0 = 0; i0 < y_size_idx_0; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        y_data[i1 + 3 * i0].re = b_y_data[i0 + y_size_idx_0 * i1].re;
        y_data[i1 + 3 * i0].im = -b_y_data[i0 + y_size_idx_0 * i1].im;
      }
    }

    so3_vec(y_data, b_y_size, tx_temp_data, a_size);
    i0 = 3 * i + 1;
    i1 = 3 * (1 + i);
    if (i0 > i1) {
      i0 = 0;
      i1 = 0;
    } else {
      i0--;
    }

    Rx_solved_size[0] = 3;
    Rx_solved_size[1] = i1 - i0;
    loop_ub = i1 - i0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (ic = 0; ic < 3; ic++) {
        y_data[ic + 3 * i1] = Rx_solved[ic + 3 * (i0 + i1)];
      }
    }

    dc0 = det(y_data, Rx_solved_size);
    guard1 = false;
    if (rt_hypotd_snf(dc0.re - 1.0, dc0.im) < 0.001) {
      i0 = 3 * i + 1;
      i1 = 3 * (1 + i);
      if (i0 > i1) {
        i0 = 0;
        i1 = 0;
      } else {
        i0--;
      }

      loop_ub = i1 - i0;
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (ic = 0; ic < 3; ic++) {
          y_data[ic + 3 * i1] = Rx_solved[ic + 3 * (i0 + i1)];
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        b_nb[i0].re = nb[i0];
        b_nb[i0].im = 0.0;
      }

      for (i0 = 0; i0 < 3; i0++) {
        temp_re = 0.0;
        temp_im = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          temp_re += y_data[i0 + 3 * i1].re * b_nb[i1].re - y_data[i0 + 3 * i1].
            im * 0.0;
          temp_im += y_data[i0 + 3 * i1].re * 0.0 + y_data[i0 + 3 * i1].im *
            b_nb[i1].re;
        }

        b_na[i0].re = na[i0] - temp_re;
        b_na[i0].im = 0.0 - temp_im;
      }

      if (genpnorm(b_na) < 1.5) {
        i0 = 3 * i + 1;
        i1 = 3 * (1 + i);
        if (i0 > i1) {
          i0 = 0;
          i1 = 0;
        } else {
          i0--;
        }

        eye(Na);
        loop_ub = i1 - i0;
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (ic = 0; ic < 3; ic++) {
            y_data[ic + 3 * i1] = Rx_solved[ic + 3 * (i0 + i1)];
          }
        }

        for (i0 = 0; i0 < 3; i0++) {
          b_nb[i0].re = pb[i0];
          b_nb[i0].im = 0.0;
        }

        for (i0 = 0; i0 < 3; i0++) {
          b_na[i0].re = 0.0;
          b_na[i0].im = 0.0;
          for (i1 = 0; i1 < 3; i1++) {
            b_na[i0].re += y_data[i0 + 3 * i1].re * b_nb[i1].re - y_data[i0 + 3 *
              i1].im * 0.0;
            b_na[i0].im += y_data[i0 + 3 * i1].re * 0.0 + y_data[i0 + 3 * i1].im
              * b_nb[i1].re;
          }
        }

        for (i0 = 0; i0 < 3; i0++) {
          for (i1 = 0; i1 < 3; i1++) {
            unusedU1[i0 + 3 * i1].re = Na[i0 + 3 * i1] - na[i0] * na[i1];
            unusedU1[i0 + 3 * i1].im = 0.0;
          }
        }

        for (i0 = 0; i0 < 3; i0++) {
          loop_ub = a_size[1];
          for (i1 = 0; i1 < loop_ub; i1++) {
            Na_data[i0 + 3 * i1].re = 0.0;
            Na_data[i0 + 3 * i1].im = 0.0;
            for (ic = 0; ic < 3; ic++) {
              Na_data[i0 + 3 * i1].re += unusedU1[i0 + 3 * ic].re *
                tx_temp_data[ic + a_size[0] * i1].re - 0.0 * tx_temp_data[ic +
                a_size[0] * i1].im;
              Na_data[i0 + 3 * i1].im += unusedU1[i0 + 3 * ic].re *
                tx_temp_data[ic + a_size[0] * i1].im + 0.0 * tx_temp_data[ic +
                a_size[0] * i1].re;
            }
          }
        }

        for (i0 = 0; i0 < 3; i0++) {
          b_nb[i0].re = pa[i0] - (b_na[i0].re + Na_data[i0].re);
          b_nb[i0].im = 0.0 - (b_na[i0].im + Na_data[i0].im);
        }

        if (genpnorm(b_nb) < min2) {
          // min=norm(na-Rx_solved(1:3,1:3,i)*nb);
          i0 = 3 * i + 1;
          i1 = 3 * (1 + i);
          if (i0 > i1) {
            i0 = 0;
            i1 = 0;
          } else {
            i0--;
          }

          eye(Na);
          loop_ub = i1 - i0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (ic = 0; ic < 3; ic++) {
              y_data[ic + 3 * i1] = Rx_solved[ic + 3 * (i0 + i1)];
            }
          }

          for (i0 = 0; i0 < 3; i0++) {
            b_nb[i0].re = pb[i0];
            b_nb[i0].im = 0.0;
          }

          for (i0 = 0; i0 < 3; i0++) {
            b_na[i0].re = 0.0;
            b_na[i0].im = 0.0;
            for (i1 = 0; i1 < 3; i1++) {
              b_na[i0].re += y_data[i0 + 3 * i1].re * b_nb[i1].re - y_data[i0 +
                3 * i1].im * 0.0;
              b_na[i0].im += y_data[i0 + 3 * i1].re * 0.0 + y_data[i0 + 3 * i1].
                im * b_nb[i1].re;
            }
          }

          for (i0 = 0; i0 < 3; i0++) {
            for (i1 = 0; i1 < 3; i1++) {
              unusedU1[i0 + 3 * i1].re = Na[i0 + 3 * i1] - na[i0] * na[i1];
              unusedU1[i0 + 3 * i1].im = 0.0;
            }
          }

          for (i0 = 0; i0 < 3; i0++) {
            loop_ub = a_size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              Na_data[i0 + 3 * i1].re = 0.0;
              Na_data[i0 + 3 * i1].im = 0.0;
              for (ic = 0; ic < 3; ic++) {
                Na_data[i0 + 3 * i1].re += unusedU1[i0 + 3 * ic].re *
                  tx_temp_data[ic + a_size[0] * i1].re - 0.0 * tx_temp_data[ic +
                  a_size[0] * i1].im;
                Na_data[i0 + 3 * i1].im += unusedU1[i0 + 3 * ic].re *
                  tx_temp_data[ic + a_size[0] * i1].im + 0.0 * tx_temp_data[ic +
                  a_size[0] * i1].re;
              }
            }
          }

          for (i0 = 0; i0 < 3; i0++) {
            b_nb[i0].re = pa[i0] - (b_na[i0].re + Na_data[i0].re);
            b_nb[i0].im = 0.0 - (b_na[i0].im + Na_data[i0].im);
          }

          min2 = genpnorm(b_nb);
          i0 = 3 * i + 1;
          i1 = 3 * (1 + i);
          if (i0 > i1) {
            i0 = 0;
            i1 = 0;
          } else {
            i0--;
          }

          Rx_size_idx_1 = i1 - i0;
          loop_ub = i1 - i0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            for (ic = 0; ic < 3; ic++) {
              Rx_data[ic + 3 * i1] = Rx_solved[ic + 3 * (i0 + i1)];
            }
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      Rx_size_idx_1 = 3;
      memset(&Rx_data[0], 0, 9U * sizeof(creal_T));
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      unusedU1[i1 + 3 * i0].re = SigA[i1 + 6 * (3 + i0)];
      unusedU1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < Rx_size_idx_1; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_y_data[i0 + Rx_size_idx_1 * i1].re = 0.0;
      b_y_data[i0 + Rx_size_idx_1 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = Rx_data[ic + 3 * i0].re;
        temp_im = -Rx_data[ic + 3 * i0].im;
        b_y_data[i0 + Rx_size_idx_1 * i1].re += temp_re * unusedU1[ic + 3 * i1].
          re - temp_im * 0.0;
        b_y_data[i0 + Rx_size_idx_1 * i1].im += temp_re * 0.0 + temp_im *
          unusedU1[ic + 3 * i1].re;
      }
    }
  }

  loop_ub = Rx_size_idx_1 * Rx_size_idx_1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    tmp_data[i0].re = 0.0;
    tmp_data[i0].im = 0.0;
  }

  eml_xgemm(Rx_size_idx_1, Rx_size_idx_1, b_y_data, Rx_size_idx_1, Rx_data,
            tmp_data, Rx_size_idx_1);
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      unusedU1[i1 + 3 * i0].re = SigA[i1 + 6 * i0];
      unusedU1[i1 + 3 * i0].im = 0.0;
    }
  }

  for (i0 = 0; i0 < Rx_size_idx_1; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_y_data[i0 + Rx_size_idx_1 * i1].re = 0.0;
      b_y_data[i0 + Rx_size_idx_1 * i1].im = 0.0;
      for (ic = 0; ic < 3; ic++) {
        temp_re = Rx_data[ic + 3 * i0].re;
        temp_im = -Rx_data[ic + 3 * i0].im;
        b_y_data[i0 + Rx_size_idx_1 * i1].re += temp_re * unusedU1[ic + 3 * i1].
          re - temp_im * 0.0;
        b_y_data[i0 + Rx_size_idx_1 * i1].im += temp_re * 0.0 + temp_im *
          unusedU1[ic + 3 * i1].re;
      }
    }
  }

  y_size[0] = Rx_size_idx_1;
  y_size[1] = Rx_size_idx_1;
  loop_ub = Rx_size_idx_1 * Rx_size_idx_1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    c_y_data[i0].re = 0.0;
    c_y_data[i0].im = 0.0;
  }

  eml_xgemm(Rx_size_idx_1, Rx_size_idx_1, b_y_data, Rx_size_idx_1, Rx_data,
            c_y_data, Rx_size_idx_1);
  b_mpower(c_y_data, y_size, a_data, a_size);
  for (i0 = 0; i0 < 3; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      unusedU0[i1 + 3 * i0].re = SigB[i1 + 6 * (3 + i0)] - tmp_data[i1 + 3 * i0]
        .re;
      unusedU0[i1 + 3 * i0].im = 0.0 - tmp_data[i1 + 3 * i0].im;
    }
  }

  if (a_size[1] == 1) {
    y_size_idx_0 = a_size[0];
    loop_ub = a_size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_y_data[i0 + y_size_idx_0 * i1].re = 0.0;
        b_y_data[i0 + y_size_idx_0 * i1].im = 0.0;
        ic = 0;
        while (ic <= 0) {
          b_y_data[i0 + y_size_idx_0 * i1].re += a_data[i0].re * unusedU0[3 * i1]
            .re - a_data[i0].im * unusedU0[3 * i1].im;
          b_y_data[i0 + y_size_idx_0 * i1].im += a_data[i0].re * unusedU0[3 * i1]
            .im + a_data[i0].im * unusedU0[3 * i1].re;
          ic = 1;
        }
      }
    }
  } else {
    k = a_size[1];
    m = a_size[0];
    y_size_idx_0 = (signed char)a_size[0];
    loop_ub = (signed char)a_size[0] * 3;
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_y_data[i0].re = 0.0;
      b_y_data[i0].im = 0.0;
    }

    if (a_size[0] == 0) {
    } else {
      c = a_size[0] << 1;
      cr = 0;
      while ((m > 0) && (cr <= c)) {
        i0 = cr + m;
        for (ic = cr; ic + 1 <= i0; ic++) {
          b_y_data[ic].re = 0.0;
          b_y_data[ic].im = 0.0;
        }

        cr += m;
      }

      br = 0;
      cr = 0;
      while ((m > 0) && (cr <= c)) {
        ar = -1;
        i0 = br + k;
        for (ib = br; ib + 1 <= i0; ib++) {
          if ((unusedU0[ib].re != 0.0) || (unusedU0[ib].im != 0.0)) {
            temp_re = unusedU0[ib].re - 0.0 * unusedU0[ib].im;
            temp_im = unusedU0[ib].im + 0.0 * unusedU0[ib].re;
            ia = ar;
            i1 = cr + m;
            for (ic = cr; ic + 1 <= i1; ic++) {
              ia++;
              b_y_data[ic].re += temp_re * a_data[ia].re - temp_im * a_data[ia].
                im;
              b_y_data[ic].im += temp_re * a_data[ia].im + temp_im * a_data[ia].
                re;
            }
          }

          ar += m;
        }

        br += k;
        cr += m;
      }
    }
  }

  c_y_size[0] = 3;
  c_y_size[1] = y_size_idx_0;
  for (i0 = 0; i0 < y_size_idx_0; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      y_data[i1 + 3 * i0].re = b_y_data[i0 + y_size_idx_0 * i1].re;
      y_data[i1 + 3 * i0].im = -b_y_data[i0 + y_size_idx_0 * i1].im;
    }
  }

  so3_vec(y_data, c_y_size, tx_temp_data, a_size);
  loop_ub = 3 * Rx_size_idx_1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_a_data[i0].re = -Rx_data[i0].re;
    b_a_data[i0].im = -Rx_data[i0].im;
  }

  if (Rx_size_idx_1 == 1) {
    k = a_size[1];
    for (i0 = 0; i0 < 3; i0++) {
      loop_ub = a_size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        tx_data[i0 + 3 * i1].re = 0.0;
        tx_data[i0 + 3 * i1].im = 0.0;
        for (ic = 0; ic < 3; ic++) {
          tx_data[i0 + 3 * i1].re += b_a_data[i0 + 3 * ic].re * tx_temp_data[ic
            + a_size[0] * i1].re - b_a_data[i0 + 3 * ic].im * tx_temp_data[ic +
            a_size[0] * i1].im;
          tx_data[i0 + 3 * i1].im += b_a_data[i0 + 3 * ic].re * tx_temp_data[ic
            + a_size[0] * i1].im + b_a_data[i0 + 3 * ic].im * tx_temp_data[ic +
            a_size[0] * i1].re;
        }
      }
    }
  } else {
    k = (signed char)a_size[1];
    loop_ub = 3 * (signed char)a_size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      tx_data[i0].re = 0.0;
      tx_data[i0].im = 0.0;
    }

    c = 3 * (a_size[1] - 1);
    for (cr = 0; cr <= c; cr += 3) {
      for (ic = cr; ic + 1 <= cr + 3; ic++) {
        tx_data[ic].re = 0.0;
        tx_data[ic].im = 0.0;
      }
    }

    br = 0;
    for (cr = 0; cr <= c; cr += 3) {
      ar = -1;
      i0 = br + Rx_size_idx_1;
      for (ib = br; ib + 1 <= i0; ib++) {
        if ((tx_temp_data[ib].re != 0.0) || (tx_temp_data[ib].im != 0.0)) {
          temp_re = tx_temp_data[ib].re - 0.0 * tx_temp_data[ib].im;
          temp_im = tx_temp_data[ib].im + 0.0 * tx_temp_data[ib].re;
          ia = ar;
          for (ic = cr; ic + 1 <= cr + 3; ic++) {
            ia++;
            tx_data[ic].re += temp_re * b_a_data[ia].re - temp_im * b_a_data[ia]
              .im;
            tx_data[ic].im += temp_re * b_a_data[ia].im + temp_im * b_a_data[ia]
              .re;
          }
        }

        ar += 3;
      }

      br += Rx_size_idx_1;
    }
  }

  for (i0 = 0; i0 < Rx_size_idx_1; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_Rx_data[i1 + 3 * i0] = Rx_data[i1 + 3 * i0];
    }
  }

  for (i0 = 0; i0 < k; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      b_Rx_data[i1 + 3 * (i0 + Rx_size_idx_1)] = tx_data[i1 + 3 * i0];
    }
  }

  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 3; i1++) {
      X[i1 + (i0 << 2)] = b_Rx_data[i1 + 3 * i0];
    }

    X[3 + (i0 << 2)].re = iv8[i0];
    X[3 + (i0 << 2)].im = 0.0;
  }
}

//
// File trailer for batchEDSolve.cpp
//
// [EOF]
//
