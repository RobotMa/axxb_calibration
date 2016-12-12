/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean_Taylor_2nd_adv_data.c
 *
 * Code generation for function 'mean_Taylor_2nd_adv_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mean_Taylor_2nd_adv.h"
#include "mean_Taylor_2nd_adv_data.h"
#include <stdio.h>

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL,
  "mean_Taylor_2nd_adv", NULL, false, { 2045744189U, 2170104910U, 2743257031U,
    4284093946U }, NULL };

emlrtRSInfo p_emlrtRSI = { 14, "svd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/matfun/svd.m" };

emlrtRSInfo r_emlrtRSI = { 13, "eml_xgesvd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m" };

emlrtRSInfo s_emlrtRSI = { 8, "eml_lapack_xgesvd",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m"
};

emlrtRSInfo u_emlrtRSI = { 329, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo v_emlrtRSI = { 348, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo w_emlrtRSI = { 346, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo x_emlrtRSI = { 400, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo y_emlrtRSI = { 387, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo ab_emlrtRSI = { 384, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo bb_emlrtRSI = { 373, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo cb_emlrtRSI = { 264, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo fb_emlrtRSI = { 116, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo gb_emlrtRSI = { 110, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo hb_emlrtRSI = { 78, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo ib_emlrtRSI = { 73, "eml_matlab_zsvdc",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m"
};

emlrtRSInfo jb_emlrtRSI = { 19, "eml_xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m" };

emlrtRSInfo kb_emlrtRSI = { 1, "xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"
};

emlrtRSInfo lb_emlrtRSI = { 1, "xnrm2",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"
};

emlrtRSInfo mb_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

emlrtRSInfo nb_emlrtRSI = { 1, "scaleVectorByRecip",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/scaleVectorByRecip.p"
};

emlrtRSInfo sb_emlrtRSI = { 18, "eml_xrotg",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m" };

emlrtRSInfo tb_emlrtRSI = { 1, "xrotg",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xrotg.p"
};

emlrtRSInfo vb_emlrtRSI = { 7, "eml_xgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m" };

emlrtRSInfo wb_emlrtRSI = { 7, "eml_lapack_xgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"
};

emlrtRSInfo xb_emlrtRSI = { 36, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo yb_emlrtRSI = { 50, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo ac_emlrtRSI = { 58, "eml_matlab_zgetrf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"
};

emlrtRSInfo bc_emlrtRSI = { 20, "eml_ixamax",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m" };

emlrtRSInfo cc_emlrtRSI = { 1, "ixamax",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"
};

emlrtRSInfo dc_emlrtRSI = { 1, "ixamax",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"
};

emlrtRSInfo ec_emlrtRSI = { 41, "eml_xgeru",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m" };

emlrtRSInfo fc_emlrtRSI = { 1, "xgeru",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"
};

emlrtRSInfo gc_emlrtRSI = { 1, "xger",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xger.p" };

emlrtRSInfo hc_emlrtRSI = { 1, "xger",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"
};

emlrtRSInfo ic_emlrtRSI = { 1, "xgerx",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"
};

emlrtRSInfo oc_emlrtRSI = { 42, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo pc_emlrtRSI = { 92, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo qc_emlrtRSI = { 90, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo rc_emlrtRSI = { 76, "eml_lusolve",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_lusolve.m" };

emlrtRSInfo vc_emlrtRSI = { 1, "xgemm",
  "/usr/local/MATLAB/R2015a/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"
};

/* End of code generation (mean_Taylor_2nd_adv_data.c) */
