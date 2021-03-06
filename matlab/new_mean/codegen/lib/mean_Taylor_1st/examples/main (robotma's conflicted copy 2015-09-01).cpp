//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 05-Jul-2015 23:07:58
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
#include "mean_Taylor_1st.h"
#include "main.h"
#include "mean_Taylor_1st_terminate.h"
#include "mean_Taylor_1st_emxAPI.h"
#include "mean_Taylor_1st_initialize.h"
#include <stdio.h>

// Function Declarations
static emxArray_real_T *argInit_4xUnbounded_real_T();
static double argInit_real_T();
static void main_mean_Taylor_1st();

// Function Definitions

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_4xUnbounded_real_T()
{
  emxArray_real_T *result;
  static int iv1[2] = { 4, 2 };

  int b_j0;
  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(2, *(int (*)[2])&iv1[0]);

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
static void main_mean_Taylor_1st()
{
  emxArray_real_T *X;
  double M_hat[16];
  double M_t1[16];

  // Initialize function 'mean_Taylor_1st' input arguments.
  // Initialize function input argument 'X'.
  X = argInit_4xUnbounded_real_T();

  // Call the entry-point 'mean_Taylor_1st'.
  mean_Taylor_1st(X, M_t1, M_hat);
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
  mean_Taylor_1st_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_mean_Taylor_1st();

  // Terminate the application.
  // You do not need to do this more than one time.
  mean_Taylor_1st_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
