#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/rational-numbers.h"
#include "../include/complex-int.h"
#include "../include/complex-double.h"
#include "../include/complex-rational.h"


int main(void) {
  // implementation with rational type
  printf("\n\n####### IMPLEMENTATION WITH RATIONAL TYPE #######\n\n");
  // create two rational numbers
  Rational_t* real = createRationalNumber(5, 2);
  Rational_t* imag = createRationalNumber(4, 2);
  
  // create complex of rational
  RATIONAL_Complex_t* teste = RATIONAL_createComplexNumber(real, imag);
  // displaying it
  RATIONAL_displayComplexNumber(teste);

  // free allocated memory
  RATIONAL_freeComplexNumber(teste);
  freeRationalNumber(real);
  freeRationalNumber(imag);
       
  
  // implementation with int type
  printf("\n\n####### IMPLEMENTATION WITH INT TYPE #######\n\n");

  // create numbers
  INT_Complex_t* num = INT_createComplexNumber(0, 2);
  INT_Complex_t* numTest = INT_createComplexNumber(2, 3);
  INT_Complex_t *sum, *sub, *multi, *div, *conj, *copy;


  // display numbers
  printf("-------------------- ORIGINAL NUMBERS ---------------\n\n");
  printf("num1: ");
  INT_displayComplexNumber(num);
  printf("num2: ");
  INT_displayComplexNumber(numTest);
  printf("\n");


  printf("\n\n-------------------- IS ONLY REAL/IMAGINARY ---------------\n\n");
  if (INT_isOnlyRealNumber(num)) {
    printf("Num1 is only real\n");
  } else {
    printf("Num1 is not only real\n");
  }

  if (INT_isOnlyImaginaryNumber(num)) {
    printf("Num1 is only imaginary\n");
  } else {
    printf("Num1 is not only imaginary\n");
  }


  // doing operations
  printf("\n\n-------------------- OPERATIONS ---------------\n\n");
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


  // testing compare function
  printf("\n\n-------------------- COMPARISON ---------------\n\n");
  if (INT_compareComplex(num, numTest) == 0) {
    printf("the numbers are the same!");
  } else if (INT_compareComplex(num, numTest) == 1) {
    printf("the number 1 is greater than number 2");
  } else {
    printf("the number 2 is greater than number 1");
  }

  printf("\n\n-------------------- COPY ---------------\n\n");
  // copy without modify original values
  copy = INT_copyComplexNumberTo(num);
  printf("Copy num1 into an other complex number, by returning it\n");
  printf("num1: ");
  INT_displayComplexNumber(num);
  printf("Copy num1: ");
  INT_displayComplexNumber(copy);

  printf("\n\n-------------------- ASSIGNING ---------------\n\n");
  // assign numTest into num 
  INT_assignComplexNumberTo(num, numTest);
  printf("assign num1 with num2:\n");
  printf("num1: ");
  INT_displayComplexNumber(num);
  printf("num2: ");
  INT_displayComplexNumber(numTest);


  printf("\n\n-------------------- MODULE and ANGLE ---------------\n\n");
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
  INT_freeComplexNumber(copy);

  return 0;
}