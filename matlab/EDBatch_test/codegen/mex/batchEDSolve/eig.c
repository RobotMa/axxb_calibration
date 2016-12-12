/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "eig.h"
#include "rdivide.h"
#include "eml_warning.h"
#include "eml_int_forloop_overflow_check.h"
#include "mod.h"
#include "eml_error.h"
#include "sqrt.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
static emlrtRSInfo ce_emlrtRSI = { 65, "eig",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/eig.m" };

static emlrtRSInfo de_emlrtRSI = { 71, "eig",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/eig.m" };

static emlrtRSInfo ee_emlrtRSI = { 8, "eml_xgeev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/eml_xgeev.m" };

static emlrtRSInfo fe_emlrtRSI = { 8, "eml_lapack_xgeev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeev.m"
};

static emlrtRSInfo ie_emlrtRSI = { 39, "eml_matlab_zggev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"
};

static emlrtRSInfo je_emlrtRSI = { 84, "eml_matlab_zggev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"
};

static emlrtRSInfo ke_emlrtRSI = { 100, "eml_matlab_zggev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"
};

static emlrtRSInfo le_emlrtRSI = { 101, "eml_matlab_zggev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"
};

static emlrtRSInfo me_emlrtRSI = { 106, "eml_matlab_zggev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggev.m"
};

static emlrtRSInfo ne_emlrtRSI = { 23, "eml_matlab_zggbal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"
};

static emlrtRSInfo oe_emlrtRSI = { 27, "eml_matlab_zggbal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"
};

static emlrtRSInfo pe_emlrtRSI = { 36, "eml_matlab_zggbal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"
};

static emlrtRSInfo qe_emlrtRSI = { 40, "eml_matlab_zggbal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"
};

static emlrtRSInfo re_emlrtRSI = { 140, "eml_matlab_zggbal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"
};

static emlrtRSInfo se_emlrtRSI = { 77, "eml_matlab_zggbal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"
};

static emlrtRSInfo te_emlrtRSI = { 102, "eml_matlab_zggbal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"
};

static emlrtRSInfo ue_emlrtRSI = { 106, "eml_matlab_zggbal",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zggbal.m"
};

static emlrtRSInfo ve_emlrtRSI = { 62, "eml_matlab_zgghrd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"
};

static emlrtRSInfo we_emlrtRSI = { 64, "eml_matlab_zgghrd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"
};

static emlrtRSInfo xe_emlrtRSI = { 77, "eml_matlab_zgghrd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"
};

static emlrtRSInfo ye_emlrtRSI = { 79, "eml_matlab_zgghrd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgghrd.m"
};

static emlrtRSInfo af_emlrtRSI = { 67, "eml_matlab_zlartg",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"
};

static emlrtRSInfo bf_emlrtRSI = { 93, "eml_matlab_zlartg",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"
};

static emlrtRSInfo cf_emlrtRSI = { 102, "eml_matlab_zlartg",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"
};

static emlrtRSInfo df_emlrtRSI = { 106, "eml_matlab_zlartg",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlartg.m"
};

static emlrtRSInfo ef_emlrtRSI = { 10, "eml_zrot_rows",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_rows.m"
};

static emlrtRSInfo ff_emlrtRSI = { 10, "eml_zrot_cols",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_zrot_cols.m"
};

static emlrtRSInfo gf_emlrtRSI = { 447, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo hf_emlrtRSI = { 435, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo if_emlrtRSI = { 423, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo jf_emlrtRSI = { 421, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo kf_emlrtRSI = { 412, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo lf_emlrtRSI = { 409, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo mf_emlrtRSI = { 402, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo nf_emlrtRSI = { 110, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo of_emlrtRSI = { 37, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

static emlrtRSInfo pf_emlrtRSI = { 20, "eml_matlab_zlanhs",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"
};

static emlrtRSInfo qf_emlrtRSI = { 21, "eml_matlab_zlanhs",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"
};

static emlrtRSInfo rf_emlrtRSI = { 57, "eml_matlab_zlanhs",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zlanhs.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 113, 5, "eml_matlab_ztgevc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_ztgevc.m"
};

static emlrtRSInfo mg_emlrtRSI = { 332, "eml_matlab_zhgeqz",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zhgeqz.m"
};

/* Function Declarations */
static void b_eml_matlab_zlartg(const emlrtStack *sp, const creal_T f, const
  creal_T g, real_T *cs, creal_T *sn);
static void eml_matlab_zggbak(creal_T V[9], int32_T ilo, int32_T ihi, const
  int32_T rscale[3]);
static void eml_matlab_zggev(const emlrtStack *sp, creal_T A[9], int32_T *info,
  creal_T alpha1[3], creal_T beta1[3], creal_T V[9]);
static void eml_matlab_zhgeqz(const emlrtStack *sp, creal_T A[9], int32_T ilo,
  int32_T ihi, creal_T Z[9], int32_T *info, creal_T alpha1[3], creal_T beta1[3]);
static real_T eml_matlab_zlangeM(const creal_T x[9]);
static void eml_matlab_zlartg(const emlrtStack *sp, const creal_T f, const
  creal_T g, real_T *cs, creal_T *sn, creal_T *r);
static void eml_matlab_zlascl(real_T cfrom, real_T cto, creal_T A[9]);
static void eml_matlab_ztgevc(const emlrtStack *sp, const creal_T A[9], creal_T
  V[9]);

/* Function Definitions */
static void b_eml_matlab_zlartg(const emlrtStack *sp, const creal_T f, const
  creal_T g, real_T *cs, creal_T *sn)
{
  real_T scale;
  real_T f2s;
  real_T g2;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2s;
  boolean_T b6;
  boolean_T b7;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  scale = muDoubleScalarAbs(f.re);
  f2s = muDoubleScalarAbs(f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  f2s = muDoubleScalarAbs(g.re);
  g2 = muDoubleScalarAbs(g.im);
  if (g2 > f2s) {
    f2s = g2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (1.0 > g2) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        scale = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / scale;
        sn->im = -gs_im / scale;
      } else {
        st.site = &af_emlrtRSI;
        if (g2 < 0.0) {
          b_st.site = &yd_emlrtRSI;
          d_eml_error(&b_st);
        }

        g2s = muDoubleScalarSqrt(g2);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        f2s = muDoubleScalarAbs(f.re);
        g2 = muDoubleScalarAbs(f.im);
        if (g2 > f2s) {
          f2s = g2;
        }

        if (f2s > 1.0) {
          scale = muDoubleScalarHypot(f.re, f.im);
          fs_re = f.re / scale;
          fs_im = f.im / scale;
        } else {
          f2s = 7.4428285367870146E+137 * f.re;
          g2 = 7.4428285367870146E+137 * f.im;
          scale = muDoubleScalarHypot(f2s, g2);
          fs_re = f2s / scale;
          fs_im = g2 / scale;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      st.site = &bf_emlrtRSI;
      f2s = 1.0 + g2 / scale;
      if (f2s < 0.0) {
        b_st.site = &yd_emlrtRSI;
        d_eml_error(&b_st);
      }

      f2s = muDoubleScalarSqrt(f2s);
      *cs = 1.0 / f2s;
      scale += g2;
      fs_re = f2s * fs_re / scale;
      fs_im = f2s * fs_im / scale;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
      if (rescaledir > 0) {
        st.site = &cf_emlrtRSI;
        if (1 > count) {
          b6 = false;
        } else {
          b6 = (count > 2147483646);
        }

        if (b6) {
          b_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
      } else {
        if (rescaledir < 0) {
          st.site = &df_emlrtRSI;
          if (1 > count) {
            b7 = false;
          } else {
            b7 = (count > 2147483646);
          }

          if (b7) {
            b_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }
        }
      }
    }
  }
}

static void eml_matlab_zggbak(creal_T V[9], int32_T ilo, int32_T ihi, const
  int32_T rscale[3])
{
  int32_T i;
  int32_T k;
  int32_T j;
  real_T tmp_re;
  real_T tmp_im;
  if (ilo > 1) {
    for (i = ilo - 2; i + 1 >= 1; i--) {
      k = rscale[i] - 1;
      if (rscale[i] != i + 1) {
        for (j = 0; j < 3; j++) {
          tmp_re = V[i + 3 * j].re;
          tmp_im = V[i + 3 * j].im;
          V[i + 3 * j] = V[k + 3 * j];
          V[k + 3 * j].re = tmp_re;
          V[k + 3 * j].im = tmp_im;
        }
      }
    }
  }

  if (ihi < 3) {
    for (i = ihi; i + 1 < 4; i++) {
      k = rscale[i] - 1;
      if (rscale[i] != i + 1) {
        for (j = 0; j < 3; j++) {
          tmp_re = V[i + 3 * j].re;
          tmp_im = V[i + 3 * j].im;
          V[i + 3 * j] = V[k + 3 * j];
          V[k + 3 * j].re = tmp_re;
          V[k + 3 * j].im = tmp_im;
        }
      }
    }
  }
}

static void eml_matlab_zggev(const emlrtStack *sp, creal_T A[9], int32_T *info,
  creal_T alpha1[3], creal_T beta1[3], creal_T V[9])
{
  real_T anrm;
  int32_T i;
  int32_T ii;
  boolean_T ilascl;
  real_T anrmto;
  creal_T b_A[9];
  int32_T rscale[3];
  int32_T ilo;
  int32_T ihi;
  int32_T exitg2;
  int32_T j;
  boolean_T found;
  boolean_T exitg5;
  int32_T nzcount;
  boolean_T b1;
  int32_T jj;
  boolean_T exitg6;
  boolean_T guard2 = false;
  creal_T atmp;
  boolean_T b2;
  int32_T exitg1;
  boolean_T b_ilo;
  boolean_T exitg3;
  boolean_T c_ilo;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T b3;
  static const int8_T iv23[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T mul;
  real_T stemp_re;
  real_T stemp_im;
  real_T cfrom1;
  real_T cto1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  *info = 0;
  st.site = &ie_emlrtRSI;
  anrm = eml_matlab_zlangeM(A);
  if (!((!muDoubleScalarIsInf(anrm)) && (!muDoubleScalarIsNaN(anrm)))) {
    for (i = 0; i < 3; i++) {
      alpha1[i].re = rtNaN;
      alpha1[i].im = 0.0;
      beta1[i].re = rtNaN;
      beta1[i].im = 0.0;
    }

    for (ii = 0; ii < 9; ii++) {
      V[ii].re = rtNaN;
      V[ii].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      eml_matlab_zlascl(anrm, anrmto, A);
    }

    st.site = &je_emlrtRSI;
    memcpy(&b_A[0], &A[0], 9U * sizeof(creal_T));
    for (i = 0; i < 3; i++) {
      rscale[i] = 0;
    }

    ilo = 1;
    ihi = 3;
    do {
      exitg2 = 0;
      b_st.site = &ne_emlrtRSI;
      i = 0;
      j = 0;
      found = false;
      ii = ihi;
      exitg5 = false;
      while ((!exitg5) && (ii > 0)) {
        nzcount = 0;
        i = ii;
        j = ihi;
        c_st.site = &re_emlrtRSI;
        if (1 > ihi) {
          b1 = false;
        } else {
          b1 = (ihi > 2147483646);
        }

        if (b1) {
          d_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        jj = 1;
        exitg6 = false;
        while ((!exitg6) && (jj <= ihi)) {
          guard2 = false;
          if ((b_A[(ii + 3 * (jj - 1)) - 1].re != 0.0) || (b_A[(ii + 3 * (jj - 1))
               - 1].im != 0.0) || (ii == jj)) {
            if (nzcount == 0) {
              j = jj;
              nzcount = 1;
              guard2 = true;
            } else {
              nzcount = 2;
              exitg6 = true;
            }
          } else {
            guard2 = true;
          }

          if (guard2) {
            jj++;
          }
        }

        if (nzcount < 2) {
          found = true;
          exitg5 = true;
        } else {
          ii--;
        }
      }

      if (!found) {
        exitg2 = 2;
      } else {
        b_st.site = &oe_emlrtRSI;
        if (i != ihi) {
          for (ii = 0; ii < 3; ii++) {
            atmp = b_A[(i + 3 * ii) - 1];
            b_A[(i + 3 * ii) - 1] = b_A[(ihi + 3 * ii) - 1];
            b_A[(ihi + 3 * ii) - 1] = atmp;
          }
        }

        if (j != ihi) {
          c_st.site = &se_emlrtRSI;
          if (1 > ihi) {
            b2 = false;
          } else {
            b2 = (ihi > 2147483646);
          }

          if (b2) {
            d_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          for (ii = 0; ii + 1 <= ihi; ii++) {
            atmp = b_A[ii + 3 * (j - 1)];
            b_A[ii + 3 * (j - 1)] = b_A[ii + 3 * (ihi - 1)];
            b_A[ii + 3 * (ihi - 1)] = atmp;
          }
        }

        rscale[ihi - 1] = j;
        ihi--;
        if (ihi == 1) {
          rscale[0] = 1;
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);

    if (exitg2 == 1) {
    } else {
      do {
        exitg1 = 0;
        b_st.site = &pe_emlrtRSI;
        i = 0;
        j = 0;
        found = false;
        c_st.site = &te_emlrtRSI;
        if (ilo > ihi) {
          b_ilo = false;
        } else {
          b_ilo = (ihi > 2147483646);
        }

        if (b_ilo) {
          d_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        jj = ilo;
        exitg3 = false;
        while ((!exitg3) && (jj <= ihi)) {
          nzcount = 0;
          i = ihi;
          j = jj;
          c_st.site = &ue_emlrtRSI;
          if (ilo > ihi) {
            c_ilo = false;
          } else {
            c_ilo = (ihi > 2147483646);
          }

          if (c_ilo) {
            d_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }

          ii = ilo;
          exitg4 = false;
          while ((!exitg4) && (ii <= ihi)) {
            guard1 = false;
            if ((b_A[(ii + 3 * (jj - 1)) - 1].re != 0.0) || (b_A[(ii + 3 * (jj -
                   1)) - 1].im != 0.0) || (ii == jj)) {
              if (nzcount == 0) {
                i = ii;
                nzcount = 1;
                guard1 = true;
              } else {
                nzcount = 2;
                exitg4 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              ii++;
            }
          }

          if (nzcount < 2) {
            found = true;
            exitg3 = true;
          } else {
            jj++;
          }
        }

        if (!found) {
          exitg1 = 1;
        } else {
          b_st.site = &qe_emlrtRSI;
          if (i != ilo) {
            for (ii = ilo - 1; ii + 1 < 4; ii++) {
              atmp = b_A[(i + 3 * ii) - 1];
              b_A[(i + 3 * ii) - 1] = b_A[(ilo + 3 * ii) - 1];
              b_A[(ilo + 3 * ii) - 1] = atmp;
            }
          }

          if (j != ilo) {
            c_st.site = &se_emlrtRSI;
            if (1 > ihi) {
              b3 = false;
            } else {
              b3 = (ihi > 2147483646);
            }

            if (b3) {
              d_st.site = &jb_emlrtRSI;
              check_forloop_overflow_error(&d_st);
            }

            for (ii = 0; ii + 1 <= ihi; ii++) {
              atmp = b_A[ii + 3 * (j - 1)];
              b_A[ii + 3 * (j - 1)] = b_A[ii + 3 * (ilo - 1)];
              b_A[ii + 3 * (ilo - 1)] = atmp;
            }
          }

          rscale[ilo - 1] = j;
          ilo++;
          if (ilo == ihi) {
            rscale[ilo - 1] = ilo;
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }

    st.site = &ke_emlrtRSI;
    for (ii = 0; ii < 9; ii++) {
      V[ii].re = iv23[ii];
      V[ii].im = 0.0;
    }

    if (ihi < ilo + 2) {
    } else {
      ii = ilo;
      while (ii < 2) {
        b_st.site = &ve_emlrtRSI;
        eml_matlab_zlartg(&b_st, b_A[1], b_A[2], &mul, &atmp, &b_A[1]);
        b_A[2].re = 0.0;
        b_A[2].im = 0.0;
        b_st.site = &we_emlrtRSI;
        c_st.site = &ef_emlrtRSI;
        for (j = 0; j < 2; j++) {
          stemp_re = mul * b_A[1 + 3 * (j + 1)].re + (atmp.re * b_A[2 + 3 * (j +
            1)].re - atmp.im * b_A[2 + 3 * (j + 1)].im);
          stemp_im = mul * b_A[1 + 3 * (j + 1)].im + (atmp.re * b_A[2 + 3 * (j +
            1)].im + atmp.im * b_A[2 + 3 * (j + 1)].re);
          cfrom1 = b_A[1 + 3 * (j + 1)].im;
          cto1 = b_A[1 + 3 * (j + 1)].re;
          b_A[2 + 3 * (j + 1)].re = mul * b_A[2 + 3 * (j + 1)].re - (atmp.re *
            b_A[1 + 3 * (j + 1)].re + atmp.im * b_A[1 + 3 * (j + 1)].im);
          b_A[2 + 3 * (j + 1)].im = mul * b_A[2 + 3 * (j + 1)].im - (atmp.re *
            cfrom1 - atmp.im * cto1);
          b_A[1 + 3 * (j + 1)].re = stemp_re;
          b_A[1 + 3 * (j + 1)].im = stemp_im;
        }

        atmp.re = -atmp.re;
        atmp.im = -atmp.im;
        b_st.site = &xe_emlrtRSI;
        c_st.site = &ff_emlrtRSI;
        for (i = ilo - 1; i + 1 < 4; i++) {
          stemp_re = mul * b_A[6 + i].re + (atmp.re * b_A[3 + i].re - atmp.im *
            b_A[3 + i].im);
          stemp_im = mul * b_A[6 + i].im + (atmp.re * b_A[3 + i].im + atmp.im *
            b_A[3 + i].re);
          cfrom1 = b_A[6 + i].im;
          cto1 = b_A[6 + i].re;
          b_A[3 + i].re = mul * b_A[3 + i].re - (atmp.re * b_A[6 + i].re +
            atmp.im * b_A[6 + i].im);
          b_A[3 + i].im = mul * b_A[3 + i].im - (atmp.re * cfrom1 - atmp.im *
            cto1);
          b_A[6 + i].re = stemp_re;
          b_A[6 + i].im = stemp_im;
        }

        b_st.site = &ye_emlrtRSI;
        c_st.site = &ff_emlrtRSI;
        for (i = 0; i < 3; i++) {
          stemp_re = mul * V[6 + i].re + (atmp.re * V[3 + i].re - atmp.im * V[3
            + i].im);
          stemp_im = mul * V[6 + i].im + (atmp.re * V[3 + i].im + atmp.im * V[3
            + i].re);
          cfrom1 = V[6 + i].im;
          cto1 = V[6 + i].re;
          V[3 + i].re = mul * V[3 + i].re - (atmp.re * V[6 + i].re + atmp.im *
            V[6 + i].im);
          V[3 + i].im = mul * V[3 + i].im - (atmp.re * cfrom1 - atmp.im * cto1);
          V[6 + i].re = stemp_re;
          V[6 + i].im = stemp_im;
        }

        ii = 2;
      }
    }

    st.site = &le_emlrtRSI;
    eml_matlab_zhgeqz(&st, b_A, ilo, ihi, V, info, alpha1, beta1);
    if (*info != 0) {
    } else {
      st.site = &me_emlrtRSI;
      eml_matlab_ztgevc(&st, b_A, V);
      eml_matlab_zggbak(V, ilo, ihi, rscale);
      for (ii = 0; ii < 3; ii++) {
        cfrom1 = muDoubleScalarAbs(V[3 * ii].re) + muDoubleScalarAbs(V[3 * ii].
          im);
        for (nzcount = 0; nzcount < 2; nzcount++) {
          cto1 = muDoubleScalarAbs(V[(nzcount + 3 * ii) + 1].re) +
            muDoubleScalarAbs(V[(nzcount + 3 * ii) + 1].im);
          if (cto1 > cfrom1) {
            cfrom1 = cto1;
          }
        }

        if (cfrom1 >= 6.7178761075670888E-139) {
          cfrom1 = 1.0 / cfrom1;
          for (nzcount = 0; nzcount < 3; nzcount++) {
            V[nzcount + 3 * ii].re *= cfrom1;
            V[nzcount + 3 * ii].im *= cfrom1;
          }
        }
      }

      if (ilascl) {
        ilascl = true;
        while (ilascl) {
          cfrom1 = anrmto * 2.0041683600089728E-292;
          cto1 = anrm / 4.9896007738368E+291;
          if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(anrm)) && (anrm !=
               0.0)) {
            mul = 2.0041683600089728E-292;
            anrmto = cfrom1;
          } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(anrmto)) {
            mul = 4.9896007738368E+291;
            anrm = cto1;
          } else {
            mul = anrm / anrmto;
            ilascl = false;
          }

          for (ii = 0; ii < 3; ii++) {
            alpha1[ii].re *= mul;
            alpha1[ii].im *= mul;
          }
        }
      }
    }
  }
}

static void eml_matlab_zhgeqz(const emlrtStack *sp, creal_T A[9], int32_T ilo,
  int32_T ihi, creal_T Z[9], int32_T *info, creal_T alpha1[3], creal_T beta1[3])
{
  int32_T i;
  real_T eshift_re;
  real_T eshift_im;
  creal_T ctemp;
  real_T rho_re;
  real_T rho_im;
  real_T anorm;
  real_T sumsq;
  boolean_T firstNonZero;
  boolean_T b_ilo;
  int32_T j;
  int32_T jp1;
  boolean_T c_ilo;
  real_T reAij;
  real_T imAij;
  real_T temp1;
  real_T temp2;
  real_T b_atol;
  boolean_T failed;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T ifirst;
  int32_T istart;
  int32_T ilast;
  int32_T ilastm1;
  int32_T iiter;
  int32_T maxit;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  boolean_T b8;
  int32_T jiter;
  int32_T exitg1;
  boolean_T exitg3;
  boolean_T b_guard1 = false;
  creal_T t1;
  creal_T d;
  boolean_T exitg2;
  boolean_T b9;
  boolean_T b10;
  boolean_T b11;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  *info = 0;
  for (i = 0; i < 3; i++) {
    alpha1[i].re = 0.0;
    alpha1[i].im = 0.0;
    beta1[i].re = 1.0;
    beta1[i].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  rho_re = 0.0;
  rho_im = 0.0;
  st.site = &of_emlrtRSI;
  anorm = 0.0;
  if (ilo > ihi) {
  } else {
    anorm = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    b_st.site = &pf_emlrtRSI;
    if (ilo > ihi) {
      b_ilo = false;
    } else {
      b_ilo = (ihi > 2147483646);
    }

    if (b_ilo) {
      c_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (j = ilo; j <= ihi; j++) {
      jp1 = j + 1;
      if (ihi < j + 1) {
        jp1 = ihi;
      }

      b_st.site = &qf_emlrtRSI;
      if (ilo > jp1) {
        c_ilo = false;
      } else {
        c_ilo = (jp1 > 2147483646);
      }

      if (c_ilo) {
        c_st.site = &jb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (i = ilo; i <= jp1; i++) {
        reAij = A[(i + 3 * (j - 1)) - 1].re;
        imAij = A[(i + 3 * (j - 1)) - 1].im;
        if (reAij != 0.0) {
          temp1 = muDoubleScalarAbs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            anorm = temp1;
            firstNonZero = false;
          } else if (anorm < temp1) {
            temp2 = anorm / temp1;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            anorm = temp1;
          } else {
            temp2 = temp1 / anorm;
            sumsq += temp2 * temp2;
          }
        }

        if (imAij != 0.0) {
          temp1 = muDoubleScalarAbs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            anorm = temp1;
            firstNonZero = false;
          } else if (anorm < temp1) {
            temp2 = anorm / temp1;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            anorm = temp1;
          } else {
            temp2 = temp1 / anorm;
            sumsq += temp2 * temp2;
          }
        }
      }
    }

    b_st.site = &rf_emlrtRSI;
    if (sumsq < 0.0) {
      c_st.site = &yd_emlrtRSI;
      d_eml_error(&c_st);
    }

    anorm *= muDoubleScalarSqrt(sumsq);
  }

  reAij = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (reAij > 2.2250738585072014E-308) {
    b_atol = reAij;
  }

  temp1 = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    temp1 = anorm;
  }

  imAij = 1.0 / temp1;
  failed = true;
  for (j = ihi; j + 1 < 4; j++) {
    alpha1[j] = A[j + 3 * j];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    iiter = 0;
    maxit = 30 * ((ihi - ilo) + 1);
    goto60 = false;
    goto70 = false;
    goto90 = false;
    st.site = &nf_emlrtRSI;
    if (1 > maxit) {
      b8 = false;
    } else {
      b8 = (maxit > 2147483646);
    }

    if (b8) {
      b_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= maxit) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (muDoubleScalarAbs(A[ilast + 3 * ilastm1].re) +
                   muDoubleScalarAbs(A[ilast + 3 * ilastm1].im) <= b_atol) {
          A[ilast + 3 * ilastm1].re = 0.0;
          A[ilast + 3 * ilastm1].im = 0.0;
          goto60 = true;
        } else {
          j = ilastm1;
          exitg3 = false;
          while ((!exitg3) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              firstNonZero = true;
            } else if (muDoubleScalarAbs(A[j + 3 * (j - 1)].re) +
                       muDoubleScalarAbs(A[j + 3 * (j - 1)].im) <= b_atol) {
              A[j + 3 * (j - 1)].re = 0.0;
              A[j + 3 * (j - 1)].im = 0.0;
              firstNonZero = true;
            } else {
              firstNonZero = false;
            }

            if (firstNonZero) {
              ifirst = j + 1;
              goto70 = true;
              exitg3 = true;
            } else {
              j--;
            }
          }
        }

        if (goto60 || goto70) {
          firstNonZero = true;
        } else {
          firstNonZero = false;
        }

        if (!firstNonZero) {
          for (i = 0; i < 3; i++) {
            alpha1[i].re = rtNaN;
            alpha1[i].im = 0.0;
            beta1[i].re = rtNaN;
            beta1[i].im = 0.0;
          }

          for (jp1 = 0; jp1 < 9; jp1++) {
            Z[jp1].re = rtNaN;
            Z[jp1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else {
          b_guard1 = false;
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = A[ilast + 3 * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              b_guard1 = true;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              st.site = &mg_emlrtRSI;
              if (b_mod(&st, iiter) != 0) {
                reAij = -(A[ilast + 3 * ilast].re - A[ilastm1 + 3 * ilastm1].re);
                temp1 = -(A[ilast + 3 * ilast].im - A[ilastm1 + 3 * ilastm1].im);
                if (temp1 == 0.0) {
                  t1.re = reAij / 2.0;
                  t1.im = 0.0;
                } else if (reAij == 0.0) {
                  t1.re = 0.0;
                  t1.im = temp1 / 2.0;
                } else {
                  t1.re = reAij / 2.0;
                  t1.im = temp1 / 2.0;
                }

                d.re = (t1.re * t1.re - t1.im * t1.im) + (A[ilastm1 + 3 * ilast]
                  .re * A[ilast + 3 * ilastm1].re - A[ilastm1 + 3 * ilast].im *
                  A[ilast + 3 * ilastm1].im);
                d.im = (t1.re * t1.im + t1.im * t1.re) + (A[ilastm1 + 3 * ilast]
                  .re * A[ilast + 3 * ilastm1].im + A[ilastm1 + 3 * ilast].im *
                  A[ilast + 3 * ilastm1].re);
                c_sqrt(&d);
                rho_re = A[ilastm1 + 3 * ilastm1].re - (t1.re - d.re);
                rho_im = A[ilastm1 + 3 * ilastm1].im - (t1.im - d.im);
                anorm = A[ilastm1 + 3 * ilastm1].re - (t1.re + d.re);
                reAij = A[ilastm1 + 3 * ilastm1].im - (t1.im + d.im);
                if (muDoubleScalarHypot(rho_re - A[ilast + 3 * ilast].re, rho_im
                     - A[ilast + 3 * ilast].im) <= muDoubleScalarHypot(anorm -
                     A[ilast + 3 * ilast].re, reAij - A[ilast + 3 * ilast].im))
                {
                  anorm = rho_re;
                  reAij = rho_im;
                  rho_re = t1.re - d.re;
                  rho_im = t1.im - d.im;
                } else {
                  rho_re = t1.re + d.re;
                  rho_im = t1.im + d.im;
                }
              } else {
                eshift_re += A[ilast + 3 * ilastm1].re;
                eshift_im += A[ilast + 3 * ilastm1].im;
                anorm = eshift_re;
                reAij = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp.re = A[j + 3 * j].re - anorm;
                ctemp.im = A[j + 3 * j].im - reAij;
                temp1 = imAij * (muDoubleScalarAbs(ctemp.re) + muDoubleScalarAbs
                                 (ctemp.im));
                temp2 = imAij * (muDoubleScalarAbs(A[jp1 + 3 * j].re) +
                                 muDoubleScalarAbs(A[jp1 + 3 * j].im));
                sumsq = temp1;
                if (temp2 > temp1) {
                  sumsq = temp2;
                }

                if ((sumsq < 1.0) && (sumsq != 0.0)) {
                  temp1 /= sumsq;
                  temp2 /= sumsq;
                }

                if ((muDoubleScalarAbs(A[j + 3 * (j - 1)].re) +
                     muDoubleScalarAbs(A[j + 3 * (j - 1)].im)) * temp2 <= temp1 *
                    b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                if (ifirst == ilastm1 + 1) {
                  ctemp.re = rho_re;
                  ctemp.im = rho_im;
                } else {
                  ctemp.re = A[(ifirst + 3 * (ifirst - 1)) - 1].re - anorm;
                  ctemp.im = A[(ifirst + 3 * (ifirst - 1)) - 1].im - reAij;
                }

                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              st.site = &mf_emlrtRSI;
              b_eml_matlab_zlartg(&st, ctemp, A[istart + 3 * (istart - 1)],
                                  &temp1, &t1);
              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  st.site = &lf_emlrtRSI;
                  eml_matlab_zlartg(&st, A[1 + 3 * jp1], A[j + 3 * jp1], &temp1,
                                    &t1, &A[1 + 3 * jp1]);
                  A[j + 3 * jp1].re = 0.0;
                  A[j + 3 * jp1].im = 0.0;
                }

                st.site = &kf_emlrtRSI;
                b_st.site = &ef_emlrtRSI;
                for (jp1 = j - 1; jp1 + 1 < 4; jp1++) {
                  d.re = temp1 * A[(j + 3 * jp1) - 1].re + (t1.re * A[j + 3 *
                    jp1].re - t1.im * A[j + 3 * jp1].im);
                  d.im = temp1 * A[(j + 3 * jp1) - 1].im + (t1.re * A[j + 3 *
                    jp1].im + t1.im * A[j + 3 * jp1].re);
                  anorm = A[(j + 3 * jp1) - 1].im;
                  reAij = A[(j + 3 * jp1) - 1].re;
                  A[j + 3 * jp1].re = temp1 * A[j + 3 * jp1].re - (t1.re * A[(j
                    + 3 * jp1) - 1].re + t1.im * A[(j + 3 * jp1) - 1].im);
                  A[j + 3 * jp1].im = temp1 * A[j + 3 * jp1].im - (t1.re * anorm
                    - t1.im * reAij);
                  A[(j + 3 * jp1) - 1] = d;
                }

                t1.re = -t1.re;
                t1.im = -t1.im;
                jp1 = j + 2;
                if (ilast + 1 < j + 2) {
                  jp1 = ilast + 1;
                }

                st.site = &jf_emlrtRSI;
                b_st.site = &ff_emlrtRSI;
                if (1 > jp1) {
                  b9 = false;
                } else {
                  b9 = (jp1 > 2147483646);
                }

                if (b9) {
                  c_st.site = &jb_emlrtRSI;
                  check_forloop_overflow_error(&c_st);
                }

                for (i = 0; i + 1 <= jp1; i++) {
                  d.re = temp1 * A[i + 3 * j].re + (t1.re * A[i + 3 * (j - 1)].
                    re - t1.im * A[i + 3 * (j - 1)].im);
                  d.im = temp1 * A[i + 3 * j].im + (t1.re * A[i + 3 * (j - 1)].
                    im + t1.im * A[i + 3 * (j - 1)].re);
                  anorm = A[i + 3 * j].im;
                  reAij = A[i + 3 * j].re;
                  A[i + 3 * (j - 1)].re = temp1 * A[i + 3 * (j - 1)].re - (t1.re
                    * A[i + 3 * j].re + t1.im * A[i + 3 * j].im);
                  A[i + 3 * (j - 1)].im = temp1 * A[i + 3 * (j - 1)].im - (t1.re
                    * anorm - t1.im * reAij);
                  A[i + 3 * j] = d;
                }

                st.site = &if_emlrtRSI;
                b_st.site = &ff_emlrtRSI;
                for (i = 0; i < 3; i++) {
                  d.re = temp1 * Z[i + 3 * j].re + (t1.re * Z[i + 3 * (j - 1)].
                    re - t1.im * Z[i + 3 * (j - 1)].im);
                  d.im = temp1 * Z[i + 3 * j].im + (t1.re * Z[i + 3 * (j - 1)].
                    im + t1.im * Z[i + 3 * (j - 1)].re);
                  anorm = Z[i + 3 * j].im;
                  reAij = Z[i + 3 * j].re;
                  Z[i + 3 * (j - 1)].re = temp1 * Z[i + 3 * (j - 1)].re - (t1.re
                    * Z[i + 3 * j].re + t1.im * Z[i + 3 * j].im);
                  Z[i + 3 * (j - 1)].im = temp1 * Z[i + 3 * (j - 1)].im - (t1.re
                    * anorm - t1.im * reAij);
                  Z[i + 3 * j] = d;
                }

                jp1 = j - 1;
                j++;
              }
            }

            b_guard1 = true;
          }

          if (b_guard1) {
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      st.site = &hf_emlrtRSI;
      if (1 > ilast + 1) {
        b10 = false;
      } else {
        b10 = (ilast + 1 > 2147483646);
      }

      if (b10) {
        b_st.site = &jb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (jp1 = 0; jp1 + 1 <= ilast + 1; jp1++) {
        alpha1[jp1].re = rtNaN;
        alpha1[jp1].im = 0.0;
        beta1[jp1].re = rtNaN;
        beta1[jp1].im = 0.0;
      }

      for (jp1 = 0; jp1 < 9; jp1++) {
        Z[jp1].re = rtNaN;
        Z[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    st.site = &gf_emlrtRSI;
    if (1 > ilo - 1) {
      b11 = false;
    } else {
      b11 = (ilo - 1 > 2147483646);
    }

    if (b11) {
      b_st.site = &jb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (j = 0; j + 1 < ilo; j++) {
      alpha1[j] = A[j + 3 * j];
    }
  }
}

static real_T eml_matlab_zlangeM(const creal_T x[9])
{
  real_T y;
  int32_T k;
  boolean_T exitg1;
  real_T absxk;
  y = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    absxk = muDoubleScalarHypot(x[k].re, x[k].im);
    if (muDoubleScalarIsNaN(absxk)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > y) {
        y = absxk;
      }

      k++;
    }
  }

  return y;
}

static void eml_matlab_zlartg(const emlrtStack *sp, const creal_T f, const
  creal_T g, real_T *cs, creal_T *sn, creal_T *r)
{
  real_T scale;
  real_T f2s;
  real_T g2;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2s;
  boolean_T b4;
  boolean_T b5;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  scale = muDoubleScalarAbs(f.re);
  f2s = muDoubleScalarAbs(f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  f2s = muDoubleScalarAbs(g.re);
  g2 = muDoubleScalarAbs(g.im);
  if (g2 > f2s) {
    f2s = g2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (1.0 > g2) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = muDoubleScalarHypot(g.re, g.im);
        r->im = 0.0;
        f2s = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / f2s;
        sn->im = -gs_im / f2s;
      } else {
        st.site = &af_emlrtRSI;
        if (g2 < 0.0) {
          b_st.site = &yd_emlrtRSI;
          d_eml_error(&b_st);
        }

        g2s = muDoubleScalarSqrt(g2);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        f2s = muDoubleScalarAbs(f.re);
        g2 = muDoubleScalarAbs(f.im);
        if (g2 > f2s) {
          f2s = g2;
        }

        if (f2s > 1.0) {
          f2s = muDoubleScalarHypot(f.re, f.im);
          fs_re = f.re / f2s;
          fs_im = f.im / f2s;
        } else {
          g2 = 7.4428285367870146E+137 * f.re;
          scale = 7.4428285367870146E+137 * f.im;
          f2s = muDoubleScalarHypot(g2, scale);
          fs_re = g2 / f2s;
          fs_im = scale / f2s;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = *cs * f.re + (sn->re * g.re - sn->im * g.im);
        r->im = *cs * f.im + (sn->re * g.im + sn->im * g.re);
      }
    } else {
      st.site = &bf_emlrtRSI;
      f2s = 1.0 + g2 / scale;
      if (f2s < 0.0) {
        b_st.site = &yd_emlrtRSI;
        d_eml_error(&b_st);
      }

      f2s = muDoubleScalarSqrt(f2s);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      f2s = scale + g2;
      g2 = r->re / f2s;
      f2s = r->im / f2s;
      sn->re = g2 * gs_re - f2s * -gs_im;
      sn->im = g2 * -gs_im + f2s * gs_re;
      if (rescaledir > 0) {
        st.site = &cf_emlrtRSI;
        if (1 > count) {
          b4 = false;
        } else {
          b4 = (count > 2147483646);
        }

        if (b4) {
          b_st.site = &jb_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }

        for (rescaledir = 1; rescaledir <= count; rescaledir++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else {
        if (rescaledir < 0) {
          st.site = &df_emlrtRSI;
          if (1 > count) {
            b5 = false;
          } else {
            b5 = (count > 2147483646);
          }

          if (b5) {
            b_st.site = &jb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          for (rescaledir = 1; rescaledir <= count; rescaledir++) {
            r->re *= 1.3435752215134178E-138;
            r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

static void eml_matlab_zlascl(real_T cfrom, real_T cto, creal_T A[9])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  real_T cfrom1;
  real_T cto1;
  real_T mul;
  int32_T i30;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) && (ctoc != 0.0))
    {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    for (i30 = 0; i30 < 9; i30++) {
      A[i30].re *= mul;
      A[i30].im *= mul;
    }
  }
}

static void eml_matlab_ztgevc(const emlrtStack *sp, const creal_T A[9], creal_T
  V[9])
{
  real_T rworka[3];
  int32_T j;
  real_T anorm;
  int32_T b_j;
  real_T y;
  real_T scale;
  real_T ascale;
  int32_T je;
  real_T temp;
  real_T salpha_re;
  real_T salpha_im;
  real_T acoeff;
  boolean_T b12;
  boolean_T b13;
  real_T b_y;
  real_T acoefa;
  creal_T work1[3];
  int32_T jr;
  real_T dmin;
  creal_T d;
  creal_T b_work1;
  creal_T work2[3];
  for (j = 0; j < 3; j++) {
    rworka[j] = 0.0;
  }

  anorm = muDoubleScalarAbs(A[0].re) + muDoubleScalarAbs(A[0].im);
  for (b_j = 0; b_j < 2; b_j++) {
    for (j = 0; j <= b_j; j++) {
      rworka[b_j + 1] += muDoubleScalarAbs(A[j + 3 * (b_j + 1)].re) +
        muDoubleScalarAbs(A[j + 3 * (b_j + 1)].im);
    }

    y = rworka[b_j + 1] + (muDoubleScalarAbs(A[(b_j + 3 * (b_j + 1)) + 1].re) +
      muDoubleScalarAbs(A[(b_j + 3 * (b_j + 1)) + 1].im));
    if (y > anorm) {
      anorm = y;
    }
  }

  scale = anorm;
  if (2.2250738585072014E-308 > anorm) {
    scale = 2.2250738585072014E-308;
  }

  ascale = 1.0 / scale;
  for (je = 0; je < 3; je++) {
    scale = (muDoubleScalarAbs(A[(3 * (2 - je) - je) + 2].re) +
             muDoubleScalarAbs(A[(3 * (2 - je) - je) + 2].im)) * ascale;
    if (1.0 > scale) {
      scale = 1.0;
    }

    temp = 1.0 / scale;
    salpha_re = ascale * (temp * A[(3 * (2 - je) - je) + 2].re);
    salpha_im = ascale * (temp * A[(3 * (2 - je) - je) + 2].im);
    acoeff = temp * ascale;
    if ((muDoubleScalarAbs(temp) >= 2.2250738585072014E-308) &&
        (muDoubleScalarAbs(acoeff) < 3.0062525400134592E-292)) {
      b12 = true;
    } else {
      b12 = false;
    }

    if ((muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im) >=
         2.2250738585072014E-308) && (muDoubleScalarAbs(salpha_re) +
         muDoubleScalarAbs(salpha_im) < 3.0062525400134592E-292)) {
      b13 = true;
    } else {
      b13 = false;
    }

    scale = 1.0;
    if (b12) {
      scale = anorm;
      if (3.3264005158911995E+291 < anorm) {
        scale = 3.3264005158911995E+291;
      }

      scale *= 3.0062525400134592E-292 / muDoubleScalarAbs(temp);
    }

    if (b13) {
      y = 3.0062525400134592E-292 / (muDoubleScalarAbs(salpha_re) +
        muDoubleScalarAbs(salpha_im));
      if (y > scale) {
        scale = y;
      }
    }

    if (b12 || b13) {
      y = muDoubleScalarAbs(acoeff);
      b_y = muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im);
      if (1.0 > y) {
        y = 1.0;
      }

      if (b_y > y) {
        y = b_y;
      }

      y = 1.0 / (2.2250738585072014E-308 * y);
      if (y < scale) {
        scale = y;
      }

      if (b12) {
        acoeff = ascale * (scale * temp);
      } else {
        acoeff *= scale;
      }

      if (b13) {
        salpha_re *= scale;
        salpha_im *= scale;
      } else {
        salpha_re *= scale;
        salpha_im *= scale;
      }
    }

    acoefa = muDoubleScalarAbs(acoeff);
    for (jr = 0; jr < 3; jr++) {
      work1[jr].re = 0.0;
      work1[jr].im = 0.0;
    }

    work1[2 - je].re = 1.0;
    work1[2 - je].im = 0.0;
    dmin = 2.2204460492503131E-16 * acoefa * anorm;
    y = 2.2204460492503131E-16 * (muDoubleScalarAbs(salpha_re) +
      muDoubleScalarAbs(salpha_im));
    if (y > dmin) {
      dmin = y;
    }

    if (2.2250738585072014E-308 > dmin) {
      dmin = 2.2250738585072014E-308;
    }

    for (jr = 0; jr <= 1 - je; jr++) {
      work1[jr].re = acoeff * A[jr + 3 * (2 - je)].re;
      work1[jr].im = acoeff * A[jr + 3 * (2 - je)].im;
    }

    work1[2 - je].re = 1.0;
    work1[2 - je].im = 0.0;
    emlrtForLoopVectorCheckR2012b((3.0 + -(real_T)je) - 1.0, -1.0, 1.0,
      mxDOUBLE_CLASS, 2 - je, &n_emlrtRTEI, sp);
    for (b_j = 0; b_j <= 1 - je; b_j++) {
      j = (-je - b_j) + 1;
      d.re = acoeff * A[j + 3 * j].re - salpha_re;
      d.im = acoeff * A[j + 3 * j].im - salpha_im;
      if (muDoubleScalarAbs(d.re) + muDoubleScalarAbs(d.im) <= dmin) {
        d.re = dmin;
        d.im = 0.0;
      }

      if ((muDoubleScalarAbs(d.re) + muDoubleScalarAbs(d.im) < 1.0) &&
          (muDoubleScalarAbs(work1[j].re) + muDoubleScalarAbs(work1[j].im) >=
           1.4980776123852632E+307 * (muDoubleScalarAbs(d.re) +
            muDoubleScalarAbs(d.im)))) {
        temp = 1.0 / (muDoubleScalarAbs(work1[j].re) + muDoubleScalarAbs(work1[j]
          .im));
        for (jr = 0; jr <= 2 - je; jr++) {
          work1[jr].re *= temp;
          work1[jr].im *= temp;
        }
      }

      b_work1.re = -work1[j].re;
      b_work1.im = -work1[j].im;
      work1[j] = rdivide(b_work1, d);
      if (j + 1 > 1) {
        if (muDoubleScalarAbs(work1[1].re) + muDoubleScalarAbs(work1[1].im) >
            1.0) {
          temp = 1.0 / (muDoubleScalarAbs(work1[1].re) + muDoubleScalarAbs
                        (work1[1].im));
          if (acoefa * rworka[1] >= 1.4980776123852632E+307 * temp) {
            for (jr = 0; jr <= 2 - je; jr++) {
              work1[jr].re *= temp;
              work1[jr].im *= temp;
            }
          }
        }

        scale = acoeff * work1[1].re;
        b_y = acoeff * work1[1].im;
        work1[0].re += scale * A[3].re - b_y * A[3].im;
        work1[0].im += scale * A[3].im + b_y * A[3].re;
      }
    }

    for (jr = 0; jr < 3; jr++) {
      work2[jr].re = 0.0;
      work2[jr].im = 0.0;
    }

    for (j = 0; j <= 2 - je; j++) {
      for (jr = 0; jr < 3; jr++) {
        work2[jr].re += V[jr + 3 * j].re * work1[j].re - V[jr + 3 * j].im *
          work1[j].im;
        work2[jr].im += V[jr + 3 * j].re * work1[j].im + V[jr + 3 * j].im *
          work1[j].re;
      }
    }

    scale = muDoubleScalarAbs(work2[0].re) + muDoubleScalarAbs(work2[0].im);
    for (jr = 0; jr < 2; jr++) {
      y = muDoubleScalarAbs(work2[jr + 1].re) + muDoubleScalarAbs(work2[jr + 1].
        im);
      if (y > scale) {
        scale = y;
      }
    }

    if (scale > 2.2250738585072014E-308) {
      temp = 1.0 / scale;
      for (jr = 0; jr < 3; jr++) {
        V[jr + 3 * (2 - je)].re = temp * work2[jr].re;
        V[jr + 3 * (2 - je)].im = temp * work2[jr].im;
      }
    } else {
      for (jr = 0; jr < 3; jr++) {
        V[jr + 3 * (2 - je)].re = 0.0;
        V[jr + 3 * (2 - je)].im = 0.0;
      }
    }
  }
}

void eig(const emlrtStack *sp, const real_T A[9], creal_T V[9], creal_T D[9])
{
  creal_T b_A[9];
  int32_T j;
  creal_T beta1[3];
  creal_T alpha1[3];
  int32_T info;
  int32_T coltop;
  real_T colnorm;
  real_T scale;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ce_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ee_emlrtRSI;
  for (j = 0; j < 9; j++) {
    b_A[j].re = A[j];
    b_A[j].im = 0.0;
  }

  c_st.site = &fe_emlrtRSI;
  eml_matlab_zggev(&c_st, b_A, &info, alpha1, beta1, V);
  for (coltop = 0; coltop < 8; coltop += 3) {
    colnorm = 0.0;
    scale = 2.2250738585072014E-308;
    for (j = coltop; j + 1 <= coltop + 3; j++) {
      absxk = muDoubleScalarAbs(V[j].re);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }

      absxk = muDoubleScalarAbs(V[j].im);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }
    }

    colnorm = scale * muDoubleScalarSqrt(colnorm);
    for (j = coltop; j + 1 <= coltop + 3; j++) {
      scale = V[j].im;
      if (V[j].im == 0.0) {
        V[j].re /= colnorm;
        V[j].im = 0.0;
      } else if (V[j].re == 0.0) {
        V[j].re = 0.0;
        V[j].im = scale / colnorm;
      } else {
        V[j].re /= colnorm;
        V[j].im = scale / colnorm;
      }
    }
  }

  for (j = 0; j < 9; j++) {
    D[j].re = 0.0;
    D[j].im = 0.0;
  }

  for (j = 0; j < 3; j++) {
    D[j + 3 * j] = rdivide(alpha1[j], beta1[j]);
  }

  if (info != 0) {
    st.site = &de_emlrtRSI;
    c_eml_warning(&st);
  }
}

/* End of code generation (eig.c) */
