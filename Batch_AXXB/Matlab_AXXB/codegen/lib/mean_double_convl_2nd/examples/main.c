/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 11-Jun-2015 01:24:21
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "mean_double_convl_2nd.h"
#include "main.h"
#include "mean_double_convl_2nd_terminate.h"
#include "mean_double_convl_2nd_initialize.h"
#include <stdio.h>

/* Function Declarations */
static void argInit_4x200_real_T(double result[800]);
static short argInit_int16_T(void);
static signed char argInit_int8_T(void);
static double argInit_real_T(void);
static void main_mean_double_convl_2nd(void);

/* Function Definitions */

/*
 * Arguments    : double result[800]
 * Return Type  : void
 */
static void argInit_4x200_real_T(double result[800])
{
  int b_j0;
  int b_j1;

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < 4; b_j0++) {
    for (b_j1 = 0; b_j1 < 200; b_j1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[b_j0 + (b_j1 << 2)] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : short
 */
static short argInit_int16_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : signed char
 */
static signed char argInit_int8_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_mean_double_convl_2nd(void)
{
  double dv1[800];
  double dv2[800];
  double dv3[800];
  double M123_f[16];

  /* Initialize function 'mean_double_convl_2nd' input arguments. */
  /* Initialize function input argument 'X1'. */
  /* Initialize function input argument 'X2'. */
  /* Initialize function input argument 'X3'. */
  /* Call the entry-point 'mean_double_convl_2nd'. */
  argInit_4x200_real_T(dv1);
  argInit_4x200_real_T(dv2);
  argInit_4x200_real_T(dv3);
  mean_double_convl_2nd(dv1, dv2, dv3, argInit_int8_T(), argInit_int8_T(),
                        argInit_int8_T(), argInit_int16_T(), argInit_real_T(),
                        M123_f);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  mean_double_convl_2nd_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_mean_double_convl_2nd();

  /* Terminate the application.
     You do not need to do this more than one time. */
  mean_double_convl_2nd_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
