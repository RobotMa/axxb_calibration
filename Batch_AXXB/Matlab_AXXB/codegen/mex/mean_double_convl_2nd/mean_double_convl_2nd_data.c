/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_double_convl_2nd_data.c
 *
 * Code generation for function 'mean_double_convl_2nd_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "mean_double_convl_2nd_data.h"
#include <stdio.h>

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL,
  "mean_double_convl_2nd", NULL, false, { 2045744189U, 2170104910U, 2743257031U,
    4284093946U }, NULL };

emlrtRSInfo ab_emlrtRSI = { 14, "svd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/svd.m" };

emlrtRSInfo cb_emlrtRSI = { 13, "eml_xgesvd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m" };

emlrtRSInfo db_emlrtRSI = { 8, "eml_lapack_xgesvd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"
};

emlrtRSInfo fb_emlrtRSI = { 329, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo gb_emlrtRSI = { 348, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo hb_emlrtRSI = { 346, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo ib_emlrtRSI = { 400, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo jb_emlrtRSI = { 387, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo kb_emlrtRSI = { 384, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo lb_emlrtRSI = { 373, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo mb_emlrtRSI = { 264, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo pb_emlrtRSI = { 116, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo qb_emlrtRSI = { 110, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo rb_emlrtRSI = { 78, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo sb_emlrtRSI = { 73, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo tb_emlrtRSI = { 19, "eml_xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m" };

emlrtRSInfo ub_emlrtRSI = { 1, "xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"
};

emlrtRSInfo vb_emlrtRSI = { 1, "xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"
};

emlrtRSInfo wb_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

emlrtRSInfo xb_emlrtRSI = { 1, "scaleVectorByRecip",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"
};

emlrtRSInfo dc_emlrtRSI = { 18, "eml_xrotg",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m" };

emlrtRSInfo ec_emlrtRSI = { 1, "xrotg",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"
};

emlrtRSInfo gc_emlrtRSI = { 7, "eml_xgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m" };

emlrtRSInfo hc_emlrtRSI = { 7, "eml_lapack_xgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"
};

emlrtRSInfo ic_emlrtRSI = { 36, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo jc_emlrtRSI = { 50, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo kc_emlrtRSI = { 58, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo lc_emlrtRSI = { 20, "eml_ixamax",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m" };

emlrtRSInfo mc_emlrtRSI = { 1, "ixamax",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"
};

emlrtRSInfo nc_emlrtRSI = { 1, "ixamax",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"
};

emlrtRSInfo oc_emlrtRSI = { 41, "eml_xgeru",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m" };

emlrtRSInfo pc_emlrtRSI = { 1, "xgeru",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"
};

emlrtRSInfo qc_emlrtRSI = { 1, "xger",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xger.p" };

emlrtRSInfo rc_emlrtRSI = { 1, "xger",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"
};

emlrtRSInfo sc_emlrtRSI = { 1, "xgerx",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"
};

emlrtRSInfo yc_emlrtRSI = { 42, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo ad_emlrtRSI = { 92, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo bd_emlrtRSI = { 90, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo cd_emlrtRSI = { 76, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo ed_emlrtRSI = { 68, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

emlrtRSInfo fd_emlrtRSI = { 21, "eml_mtimes_helper",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m" };

emlrtRSInfo gd_emlrtRSI = { 54, "eml_xgemm",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };

emlrtRSInfo hd_emlrtRSI = { 1, "xgemm",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"
};

/* End of code generation (mean_double_convl_2nd_data.c) */
