//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean_Taylor_2nd_adv_types.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 31-Aug-2015 00:46:55
//
#ifndef __MEAN_TAYLOR_2ND_ADV_TYPES_H__
#define __MEAN_TAYLOR_2ND_ADV_TYPES_H__

// Include Files
#include "rtwtypes.h"

// Type Definitions
#include <stdio.h>
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray__common

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_real_T
#endif

//
// File trailer for mean_Taylor_2nd_adv_types.h
//
// [EOF]
//
