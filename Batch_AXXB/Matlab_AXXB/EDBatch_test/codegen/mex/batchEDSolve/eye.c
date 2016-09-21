/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eye.c
 *
 * Code generation for function 'eye'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "batchEDSolve.h"
#include "eye.h"

/* Function Definitions */
void eye(real_T I[9])
{
  int32_T k;
  memset(&I[0], 0, 9U * sizeof(real_T));
  for (k = 0; k < 3; k++) {
    I[k + 3 * k] = 1.0;
  }
}

/* End of code generation (eye.c) */
