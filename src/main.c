#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/complex-int.h"
#include "../include/complex-double.h"
#include "../include/complex-rational.h"
#include "../include/rational-numbers.h"

#define PI 3.141592

int main(void) {
  // create tests
  
  DOUBLE_Complex_t* num = DOUBLE_createComplexNumber(2.3, 5.2);

  printf("Original number: ");
  DOUBLE_displayComplexNumber(num);
  printf("\n");

  printf("module: %f\n", DOUBLE_getModuleComplexNumber(num));
  printf("angle: %f\n", DOUBLE_getAngleComplexNumber(num));

  printf("\n\nSet new module....\n\n");

  DOUBLE_setModuleComplexNumber(num, 20);

  printf("New number: ");
  DOUBLE_displayComplexNumber(num);
  printf("\n");

  printf("module: %f\n", DOUBLE_getModuleComplexNumber(num));
  printf("angle: %f\n", DOUBLE_getAngleComplexNumber(num));


  DOUBLE_freeComplexNumber(num);

  /*
  // create a number
  Rational_t* number = createRationalNumber(2, 1);
  // calculate square root
  Rational_t* root = squareRootRationalNumber(number);

  // show results
  printf("Original number: ");
  displayRationalNumber(number);
  printf("\nSquare root: ");
  displayRationalNumber(root);

  // free allocated memory
  freeRationalNumber(number);
  freeRationalNumber(root);
  */


  /*
  // create a complex int number
  INT_Complex_t* intTest = INT_createComplexNumber(5, 3);
  printf("int number: ");
  INT_displayComplexNumber(intTest);

  // get real and imag parts
  int intReal = INT_getRealPart(intTest);
  int intImag = INT_getImaginaryPart(intTest);

  // convert into rational
  RATIONAL_Complex_t* conv = RATIONAL_convertIntoComplexRational(intReal, intImag);
  printf("\nConverted number: ");
  RATIONAL_displayComplexNumber(conv);


  DOUBLE_Complex_t* Dtest = DOUBLE_createComplexNumber(0.25, 3.333333);
  printf("\n\ndouble number: ");
  DOUBLE_displayComplexNumber(Dtest);

  double Dreal = DOUBLE_getRealPart(Dtest);
  double Dimag = DOUBLE_getImaginaryPart(Dtest);

  RATIONAL_Complex_t* conv2 = RATIONAL_convertIntoComplexRational(Dreal, Dimag);
  printf("\nConverted number: ");
  RATIONAL_displayComplexNumber(conv2);


  // free allocated number
  INT_freeComplexNumber(intTest);
  DOUBLE_freeComplexNumber(Dtest);
  RATIONAL_freeComplexNumber(conv);
  RATIONAL_freeComplexNumber(conv2);
  */


  /*
  double num = 0.25;
  double num2 = 3.33333;

  // convert into rational
  Rational_t* conv = convertDoubleToRational(num);
  Rational_t* conv2 = convertDoubleToRational(num2);


  printf("double 1: %f\n", num);
  printf("Rational 1: ");
  displayRationalNumber(conv);

  printf("\n\ndouble 2: %f\n", num2);
  printf("Rational 2: ");
  displayRationalNumber(conv2);

  freeRationalNumber(conv);
  freeRationalNumber(conv2);
  */

  
  /*
  // test conversions 
  printf("------- CONVERSIONS WITH DOUBLE AND INT  -------\n\n");
  DOUBLE_Complex_t* num = DOUBLE_createComplexNumber(2.7, 3.3);
  printf("\noriginal number: ");
  DOUBLE_displayComplexNumber(num);

  // convert double into int
  INT_Complex_t* convertedNumber = INT_convertComplexNumber(DOUBLE_getRealPart(num), DOUBLE_getImaginaryPart(num));
  printf("\nConvert into int: ");
  INT_displayComplexNumber(convertedNumber);

  // convert int into double
  DOUBLE_Complex_t* convertedNumber2 = DOUBLE_convertComplexNumber(INT_getRealPart(convertedNumber), INT_getImaginaryPart(convertedNumber));
  printf("\nConvert into double: ");
  DOUBLE_displayComplexNumber(convertedNumber2);



  printf("\n\n------- CONVERSIONS WITH RATIONAL -------\n\n");
  // create rational numbers to real and imaginaty part
  Rational_t* real = createRationalNumber(2, 3);
  Rational_t* imag = createRationalNumber(5, 7);

  // create a rational number
  RATIONAL_Complex_t* rational = RATIONAL_createComplexNumber(real, imag);
  printf("Original number: ");
  RATIONAL_displayComplexNumber(rational);

  // convert rational into int
  INT_Complex_t* convertedInt = INT_convertComplexRationalTo(real, imag);
  printf("\nconvert to int: ");
  INT_displayComplexNumber(convertedInt);

  // convert rational into doble
  DOUBLE_Complex_t* convertedDouble = DOUBLE_convertComplexRationalTo(real, imag);
  printf("\nconvert to double: ");
  DOUBLE_displayComplexNumber(convertedDouble);
  

  // free allocated memory
  DOUBLE_freeComplexNumber(num);
  DOUBLE_freeComplexNumber(convertedNumber2);
  INT_freeComplexNumber(convertedNumber);
  freeRationalNumber(real);
  freeRationalNumber(imag);
  RATIONAL_freeComplexNumber(rational);
  DOUBLE_freeComplexNumber(convertedDouble);
  INT_freeComplexNumber(convertedInt);
  */

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
       
  /*
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


  // set new angle
  printf("\nOld number: ");
  INT_displayComplexNumber(num);
  printf("\nmodule: %.3lf\n", INT_getModuleComplexNumber(num));
  printf("angle: %.3lf\n", INT_getAngleComplexNumber(num));

  printf("\nset new angle...\n\n");
  INT_setAngleComplexNumber(num, 0.3);
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
  */

  return 0;
}
