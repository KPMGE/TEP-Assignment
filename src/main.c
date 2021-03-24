#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/rational-numbers.h"
#include "../include/complex-int.h"
#include "../include/complex-double.h"

int main(void) {
  // implementation with long int
  printf("Implementation with int type:\n\n");

  // create numbers
  INT_Complex_t* num = INT_createComplexNumber(3, 5);
  INT_Complex_t* numTest = INT_createComplexNumber(2, 3);
  INT_Complex_t *sum, *sub, *multi, *div, *conj;

 
  // display numbers
  printf("num1: ");
  INT_displayComplexNumber(num);
  printf("num2: ");
  INT_displayComplexNumber(numTest);
  printf("\n");


  // doing operations
  // sum
  printf("sum: ");
  sum = INT_evaluateComplexOperation(num, numTest, "+");
  INT_displayComplexNumber(sum);

  // subraction
  printf("sub: ");
  sub = INT_evaluateComplexOperation(num, numTest, "-");
  INT_displayComplexNumber(sub);

  // multiplication
  printf("multi: ");
  multi = INT_evaluateComplexOperation(num, numTest, "*");
  INT_displayComplexNumber(multi);

  // division
  printf("div: ");
  div = INT_evaluateComplexOperation(num, numTest, "/");
  INT_displayComplexNumber(div);

  // display conjulgate
  printf("conjulgate of num1: ");
  conj = INT_calculateConjugateComplex(num);
  INT_displayComplexNumber(conj);

  // accumulate sum
  printf("num 1 after accumulate sum function: ");
  INT_accumulateComplexSum(num, numTest);
  INT_evaluateComplexOperation(num, numTest, "+=");
  INT_displayComplexNumber(num);

  // accumulate multi
  printf("num 1 after accumulate multi function: ");
  INT_evaluateComplexOperation(num, numTest, "*=");
  INT_displayComplexNumber(num);
  printf("\n\n");


  // testing compare function
  if (INT_compareComplex(num, numTest) == 0) {
    printf("the numbers are the same!");
  } else if (INT_compareComplex(num, numTest) == 1) {
    printf("the number 1 is greater than number 2");
  } else {
    printf("the number 2 is greater than number 1");
  }

  // setting new values
  INT_setValueToRealPart(num, sqrt(3));
  INT_setValueToImaginaryPart(num, 1);

  // display updated number
  printf("\nUpdated number:\n");
  INT_displayComplexNumber(num);

  // display module and angle
  printf("\nmodule: %.3lf\n", INT_getModuleComplexNumber(num));
  printf("angle: %.3lf\n", INT_getAngleComplexNumber(num));

  // release allocated number
  INT_freeComplexNumber(num);
  INT_freeComplexNumber(numTest);
  INT_freeComplexNumber(sum);
  INT_freeComplexNumber(sub);
  INT_freeComplexNumber(multi);
  INT_freeComplexNumber(div);
  INT_freeComplexNumber(conj);

  return 0;
}