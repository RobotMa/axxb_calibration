//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: distibutionPropsMex_types.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 05-Jul-2015 23:05:44
//
#ifndef __DISTIBUTIONPROPSMEX_TYPES_H__
#define __DISTIBUTIONPROPSMEX_TYPES_H__

// Include Files
#include "rtwtypes.h"

// Type Definitions
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
// File trailer for distibutionPropsMex_types.h
//
// [EOF]
//
