/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * batchEDSolve_data.c
 *
 * Code generation for function 'batchEDSolve_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "batchEDSolve_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL, "batchEDSolve",
  NULL, false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

emlrtRSInfo jb_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

emlrtRSInfo ub_emlrtRSI = { 7, "eml_xgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m" };

emlrtRSInfo vb_emlrtRSI = { 7, "eml_lapack_xgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"
};

emlrtRSInfo wb_emlrtRSI = { 50, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo xb_emlrtRSI = { 58, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo yb_emlrtRSI = { 41, "eml_xgeru",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m" };

emlrtRSInfo ac_emlrtRSI = { 1, "xgeru",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"
};

emlrtRSInfo ec_emlrtRSI = { 76, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo fc_emlrtRSI = { 54, "eml_xtrsm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m" };

emlrtRSInfo gc_emlrtRSI = { 1, "xtrsm",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"
};

emlrtRSInfo hc_emlrtRSI = { 1, "xtrsm",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"
};

emlrtRSInfo nc_emlrtRSI = { 170, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

emlrtRSInfo oc_emlrtRSI = { 187, "inv",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/inv.m" };

emlrtRSInfo rc_emlrtRSI = { 68, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

emlrtRSInfo tc_emlrtRSI = { 1, "xgemm",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"
};

emlrtRSInfo ad_emlrtRSI = { 329, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo bd_emlrtRSI = { 348, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo cd_emlrtRSI = { 346, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo dd_emlrtRSI = { 400, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo ed_emlrtRSI = { 387, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo fd_emlrtRSI = { 384, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo id_emlrtRSI = { 116, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo ld_emlrtRSI = { 78, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo qd_emlrtRSI = { 1, "scaleVectorByRecip",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"
};

emlrtRSInfo rd_emlrtRSI = { 1, "xscal",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xscal.p"
};

emlrtRSInfo sd_emlrtRSI = { 1, "xscal",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xscal.p"
};

emlrtRSInfo yd_emlrtRSI = { 14, "sqrt",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/elfun/sqrt.m" };

emlrtRSInfo ae_emlrtRSI = { 18, "eml_xrotg",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m" };

emlrtRSInfo be_emlrtRSI = { 1, "xrotg",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"
};

emlrtRSInfo ge_emlrtRSI = { 16, "eml_lapack_xgeev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeev.m"
};

emlrtRSInfo he_emlrtRSI = { 17, "eml_lapack_xgeev",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgeev.m"
};

emlrtRSInfo cg_emlrtRSI = { 30, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo dg_emlrtRSI = { 44, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo eg_emlrtRSI = { 26, "eml_xswap",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m" };

emlrtRSInfo fg_emlrtRSI = { 1, "xswap",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"
};

emlrtRSInfo gg_emlrtRSI = { 1, "xswap",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"
};

/* End of code generation (batchEDSolve_data.c) */
