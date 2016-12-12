//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 05-Jul-2015 23:05:44
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "distibutionPropsMex.h"
#include "main.h"
#include "distibutionPropsMex_terminate.h"
#include "distibutionPropsMex_emxAPI.h"
#include "distibutionPropsMex_initialize.h"

// Function Declarations
static emxArray_real_T *argInit_4xUnbounded_real_T();
static double argInit_real_T();
static void main_distibutionPropsMex();

// Function Definitions

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_4xUnbounded_real_T()
{
  emxArray_real_T *result;
  static int iv7[2] = { 4, 2 };

  int b_j0;
  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(2, *(int (*)[2])&iv7[0]);

  // Loop over the array to initialize each element.
  for (b_j0 = 0; b_j0 < 4; b_j0++) {
    for (b_j1 = 0; b_j1 < result->size[1U]; b_j1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result->data[b_j0 + result->size[0] * b_j1] = argInit_real_T();
    }
  }

  return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_distibutionPropsMex()
{
  emxArray_real_T *X;
  double Sig[36];
  double M[16];

  // Initialize function 'distibutionPropsMex' input arguments.
  // Initialize function input argument 'X'.
  X = argInit_4xUnbounded_real_T();

  // Call the entry-point 'distibutionPropsMex'.
  distibutionPropsMex(X, M, Sig);
  emxDestroyArray_real_T(X);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  distibutionPropsMex_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_distibutionPropsMex();

  // Terminate the application.
  // You do not need to do this more than one time.
  distibutionPropsMex_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
