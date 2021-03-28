#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/rational-numbers.h"
#include "../include/complex-int.h"
#include "../include/complex-double.h"
#include "../include/complex-rational.h"
#include "../include/vectors-int.h"

int main(void) {
  /*
  // implementation with rational type
  printf("\n\n####### IMPLEMENTATION WITH RATIONAL TYPE #######\n\n");
  // create two rational numbers
  Rational_t* real = createRationalNumber(5, 2);
  Rational_t* imag = createRationalNumber(4, 2);
  Rational_t* testeRat1 = createRationalNumber(1, 2);
  Rational_t* testeRat2 = createRationalNumber(1, 3);
  
  // create complex of rational
  RATIONAL_Complex_t* teste = RATIONAL_createComplexNumber(real, imag);
  RATIONAL_Complex_t* num2, *sum, *sub, *copy, *multi, *div;
  num2 = RATIONAL_createComplexNumber(testeRat1, testeRat2);


  printf("original num1: ");
  RATIONAL_displayComplexNumber(teste);
  printf("\nOriginal num2: ");
  RATIONAL_displayComplexNumber(num2);


  if(RATIONAL_isModuleZero(teste)) {
    printf("\nmodule is 0\n");
  } else {
    printf("\nmodule is not 0\n");
  }


  if (RATIONAL_isOnlyRealNumber(teste)) {
    printf("is only real number!\n");
  } else {
    printf("is not only real number!\n");
  }

  if (RATIONAL_isOnlyRealNumber(teste)) {
    printf("is only imaginary number!\n");
  } else {
    printf("is not only imaginary number!\n");
  }


  printf("\nmodule: %.3f\n", RATIONAL_getModuleComplexNumber(teste));
  printf("\nangle: %.3f\n", RATIONAL_getAngleComplexNumber(teste));




  printf("\nsum: ");
  sum = RATIONAL_sumComplexNumbers(teste, num2);
  RATIONAL_displayComplexNumber(sum);
  printf("\n");

  printf("\nsub: ");
  sub = RATIONAL_subtractComplexNumbers(teste, num2);
  RATIONAL_displayComplexNumber(sub);
  printf("\n");

  printf("\nmulti: ");
  multi = RATIONAL_multiplyComplexNumbers(teste, num2);
  RATIONAL_displayComplexNumber(multi);
  printf("\n");

  printf("\nmulti: ");
  div = RATIONAL_divideComplexNumbers(teste, num2);
  RATIONAL_displayComplexNumber(div);
  printf("\n");



  printf("\nchanged real part: ");
  RATIONAL_setValueToRealPart(teste, testeRat1);
  RATIONAL_displayComplexNumber(teste);

  printf("\nchange imaginary part: ");
  RATIONAL_setValueToImaginaryPart(teste, testeRat2);
  RATIONAL_displayComplexNumber(teste);


  printf("\ncopy num to another num: ");
  copy = RATIONAL_copyComplexNumberTo(teste);
  RATIONAL_displayComplexNumber(copy);

  printf("\nassign num inside another num: ");
  RATIONAL_assignComplexNumberTo(num2, teste);
  RATIONAL_displayComplexNumber(num2);


  if (RATIONAL_compareComplex(teste, num2) < 0) {
    printf("\nnum1 < num2\n");
  } else if (RATIONAL_compareComplex(teste, num2) == 0) {
    printf("\nnum1 == num2\n");
  } else {
    printf("\nnum1 > num2\n");
  }

  // free allocated memory
  RATIONAL_freeComplexNumber(teste);
  RATIONAL_freeComplexNumber(copy);
  RATIONAL_freeComplexNumber(num2);
  RATIONAL_freeComplexNumber(sum);
  RATIONAL_freeComplexNumber(sub);
  RATIONAL_freeComplexNumber(multi);
  RATIONAL_freeComplexNumber(div);
  freeRationalNumber(real);
  freeRationalNumber(imag);
  freeRationalNumber(testeRat1);
  freeRationalNumber(testeRat2);
  */
       


  
  // implementation with int type
  printf("\n\n####### IMPLEMENTATION WITH INT TYPE #######\n\n");

  // create numbers
  INT_Complex_t* num = INT_createComplexNumber(1, 2);
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
  printf("Old number: ");
  INT_displayComplexNumber(num);
  printf("\nmodule: %.3lf\n", INT_getModuleComplexNumber(num));
  printf("angle: %.3lf\n", INT_getAngleComplexNumber(num));

  printf("\nset new module...\n\n");
  INT_setModuleComplexNumber(num, 20);
  printf("New number: ");
  INT_displayComplexNumber(num);
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