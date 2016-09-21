/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * expm.c
 *
 * Code generation for function 'expm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "expm.h"
#include "mpower.h"
#include "eml_warning.h"
#include "norm.h"
#include "distibutionPropsMex_data.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 51, "expm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/expm.m" };

static emlrtRSInfo ab_emlrtRSI = { 61, "expm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/expm.m" };

static emlrtRSInfo bb_emlrtRSI = { 174, "expm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/expm.m" };

static emlrtRSInfo cb_emlrtRSI = { 1, "mldivide",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/mldivide.p" };

static emlrtRSInfo db_emlrtRSI = { 42, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

static emlrtRSInfo eb_emlrtRSI = { 92, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

static emlrtRSInfo fb_emlrtRSI = { 90, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

static emlrtRSInfo tb_emlrtRSI = { 76, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

static emlrtRTEInfo g_emlrtRTEI = { 62, 5, "expm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/expm.m" };

/* Function Declarations */
static void PadeApproximantOfDegree(const emlrtStack *sp, const real_T A[16],
  real_T m, real_T F[16]);

/* Function Definitions */
static void PadeApproximantOfDegree(const emlrtStack *sp, const real_T A[16],
  real_T m, real_T F[16])
{
  int32_T kAcol;
  int32_T info;
  real_T A2[16];
  int32_T jBcol;
  int32_T k;
  real_T A4[16];
  real_T V[16];
  real_T d;
  real_T A3[16];
  real_T b_A4[16];
  int32_T ipiv[4];
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
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
    memcpy(&F[0], &A2[0], sizeof(real_T) << 4);
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

  st.site = &bb_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  d_st.site = &fb_emlrtRSI;
  e_st.site = &gb_emlrtRSI;
  eml_lapack_xgetrf(&e_st, V, ipiv, &info);
  if (info > 0) {
    d_st.site = &eb_emlrtRSI;
    e_st.site = &tb_emlrtRSI;
    eml_warning(&e_st);
  }

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

void expm(const emlrtStack *sp, real_T A[16], real_T F[16])
{
  real_T normA;
  int32_T eint;
  boolean_T exitg1;
  static const real_T theta[5] = { 0.01495585217958292, 0.253939833006323,
    0.95041789961629319, 2.097847961257068, 5.3719203511481517 };

  static const int8_T iv8[5] = { 3, 5, 7, 9, 13 };

  real_T s;
  int32_T j;
  real_T b_F[16];
  int32_T i10;
  int32_T i11;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  normA = norm(A);
  if (normA <= 5.3719203511481517) {
    eint = 0;
    exitg1 = false;
    while ((!exitg1) && (eint < 5)) {
      if (normA <= theta[eint]) {
        st.site = &y_emlrtRSI;
        PadeApproximantOfDegree(&st, A, iv8[eint], F);
        exitg1 = true;
      } else {
        eint++;
      }
    }
  } else {
    normA /= 5.3719203511481517;
    if ((!muDoubleScalarIsInf(normA)) && (!muDoubleScalarIsNaN(normA))) {
      normA = frexp(normA, &eint);
    } else {
      eint = 0;
    }

    s = eint;
    if (normA == 0.5) {
      s = (real_T)eint - 1.0;
    }

    normA = muDoubleScalarPower(2.0, s);
    for (eint = 0; eint < 16; eint++) {
      A[eint] /= normA;
    }

    st.site = &ab_emlrtRSI;
    PadeApproximantOfDegree(&st, A, 13.0, F);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, s, mxDOUBLE_CLASS, (int32_T)s,
      &g_emlrtRTEI, sp);
    for (j = 0; j < (int32_T)s; j++) {
      for (eint = 0; eint < 4; eint++) {
        for (i10 = 0; i10 < 4; i10++) {
          b_F[eint + (i10 << 2)] = 0.0;
          for (i11 = 0; i11 < 4; i11++) {
            b_F[eint + (i10 << 2)] += F[eint + (i11 << 2)] * F[i11 + (i10 << 2)];
          }
        }
      }

      for (eint = 0; eint < 4; eint++) {
        for (i10 = 0; i10 < 4; i10++) {
          F[i10 + (eint << 2)] = b_F[i10 + (eint << 2)];
        }
      }
    }
  }
}

/* End of code generation (expm.c) */
