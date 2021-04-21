#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/complex-rational.h"

#ifdef TYPE_NAME
#ifdef DATA_TYPE
// define tolerance
#define EPSILON 0.00001
#define EPSILON2 0.0001

// define boolean types
#define TRUE 1
#define FALSE 0

// complex for complex numbers with rationals
struct TYPE_NAME(complex) {
  DATA_TYPE *real;
  DATA_TYPE *imag;
};

// create a complex number
TYPE_NAME(Complex_t*) TYPE_NAME(createComplexNumber)(DATA_TYPE* real, DATA_TYPE* imag) {
  TYPE_NAME(Complex_t) *allocatedComplex = (TYPE_NAME(Complex_t*)) malloc(sizeof(TYPE_NAME(Complex_t)));

  if (allocatedComplex == NULL) {
    printf("Insuficient Space!");
    exit(1);
  }

  allocatedComplex->real = createRationalNumber(getNumerator(real), getDenominator(real));
  allocatedComplex->imag = createRationalNumber(getNumerator(imag), getDenominator(imag));

  return allocatedComplex;
}

// get real part of a complex number
DATA_TYPE* RATIONAL_getRealPart(TYPE_NAME(Complex_t*) num) {
  return num->real;
}

// get imaginary part of a complex number
DATA_TYPE* RATIONAL_getImaginaryPart(TYPE_NAME(Complex_t*) num) {
  return num->imag;
}

// get module of a complex number
double TYPE_NAME(getModuleComplexNumber)(TYPE_NAME(Complex_t*) num) {
  double doubleReal = convertRationalToDouble(TYPE_NAME(getRealPart)(num));
  double doubleImag = convertRationalToDouble(TYPE_NAME(getImaginaryPart)(num));

  return sqrt(pow(doubleReal, 2) + pow(doubleImag, 2));
}

// get angle of a complex number
double TYPE_NAME(getAngleComplexNumber)(TYPE_NAME(Complex_t*) num) {
  double module = TYPE_NAME(getModuleComplexNumber)(num);

  return acos(convertRationalToDouble(TYPE_NAME(getRealPart)(num)) / module);
}

// set new value to real part of a complex number
void TYPE_NAME(setValueToRealPart)(TYPE_NAME(Complex_t*) num, DATA_TYPE* value) {
  setDenominator(num->real, getDenominator(value));
  setNumerator(num->real, getNumerator(value));
}

// set new value to imaginary part of a complex number
void TYPE_NAME(setValueToImaginaryPart)(TYPE_NAME(Complex_t*) num, DATA_TYPE* value) {
  setDenominator(num->imag, getDenominator(value));
  setNumerator(num->imag, getNumerator(value));
}

// set new value to module of a complex number without modify its angle
void TYPE_NAME(setModuleComplexNumber)(TYPE_NAME(Complex_t*) num, double module) {
  double angle = TYPE_NAME(getAngleComplexNumber)(num); // get angle of num

  double a2 = module * cos(angle); // calculate real part
  double b2 = module * sin(angle); // calculate imaginary part

  // convert double numbers a2 and b2 into rationals ones
  Rational_t* a2Rational = convertDoubleToRational(a2);
  Rational_t* b2Rational = convertDoubleToRational(b2);

  // set new values to old number
  TYPE_NAME(setValueToRealPart)(num, a2Rational);
  TYPE_NAME(setValueToImaginaryPart)(num, b2Rational);

  // free allocated memory
  freeRationalNumber(a2Rational);
  freeRationalNumber(b2Rational);
} 

// set new value to angle of a complex number without modify its module
void TYPE_NAME(setAngleComplexNumber)(TYPE_NAME(Complex_t*) num, double angle) {
  double module = TYPE_NAME(getModuleComplexNumber)(num);

  double a2 = module * cos(angle); // calculate real part
  double b2 = module * sin(angle); // calculate imaginary part

  // convert double numbers a2 and b2 into rationals ones
  Rational_t* a2Rational = convertDoubleToRational(a2);
  Rational_t* b2Rational = convertDoubleToRational(b2);

  // set new values to old number
  TYPE_NAME(setValueToRealPart)(num, a2Rational);
  TYPE_NAME(setValueToImaginaryPart)(num, b2Rational);

  // free allocated memory
  freeRationalNumber(a2Rational);
  freeRationalNumber(b2Rational);
}

// assign number2 into number 1
void TYPE_NAME(assignComplexNumberTo)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  TYPE_NAME(setValueToRealPart)(num1, TYPE_NAME(getRealPart)(num2));
  TYPE_NAME(setValueToImaginaryPart)(num1, TYPE_NAME(getImaginaryPart)(num2));
}

// returns an allocated copied complex number
TYPE_NAME(Complex_t*) TYPE_NAME(copyComplexNumberTo)(TYPE_NAME(Complex_t*) num) {
  TYPE_NAME(Complex_t*) copy = TYPE_NAME(createComplexNumber)(TYPE_NAME(getRealPart)(num), TYPE_NAME(getImaginaryPart)(num));
  return copy;
}

// is module 0?
int TYPE_NAME(isModuleZero)(TYPE_NAME(Complex_t*) num) {
  double module = TYPE_NAME(getModuleComplexNumber)(num); 

  if (module <= EPSILON) {
    return TRUE;
  } 
  return FALSE;
}

// is only real number?
int TYPE_NAME(isOnlyRealNumber)(TYPE_NAME(Complex_t*) num) {
  double real = convertRationalToDouble(TYPE_NAME(getImaginaryPart)(num));

  if (real <= EPSILON) {
    return TRUE;
  } 
  return FALSE;
}

// is only imaginary number?
int TYPE_NAME(isOnlyImaginaryNumber)(TYPE_NAME(Complex_t*) num) {
  double imag = convertRationalToDouble(TYPE_NAME(getRealPart)(num));

  if (imag <= EPSILON) {
    return TRUE;
  }
  return FALSE;
}

// 1 - number1 > number2
// 0 - number1 == number2
// -1 - number1 < number2
int TYPE_NAME(compareComplex)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  double moduleNum1 = TYPE_NAME(getModuleComplexNumber)(num1);
  double moduleNum2 = TYPE_NAME(getModuleComplexNumber)(num2);

  if (fabs(moduleNum1 - moduleNum2) < EPSILON2) {
    return 0;
  }
  else if (moduleNum1 > moduleNum2) {
    return 1;
  }
  else {
    return -1;
  }
}

// calculate the conjugate of a complex number
TYPE_NAME(Complex_t*) TYPE_NAME(calculateConjugateComplex)(TYPE_NAME(Complex_t*) num) {
  DATA_TYPE* realPart = TYPE_NAME(getRealPart)(num);
  DATA_TYPE* imaginaryPart = TYPE_NAME(getImaginaryPart)(num); // * -1

  setDenominator(imaginaryPart, -getDenominator(imaginaryPart));

  TYPE_NAME(Complex_t*) conjugate = TYPE_NAME(createComplexNumber)(realPart, imaginaryPart);

  return conjugate;
}

// sum operation
TYPE_NAME(Complex_t*) TYPE_NAME(sumComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate real part sum
  DATA_TYPE* sumReal =  sumRationalNumbers(TYPE_NAME(getRealPart)(num1), TYPE_NAME(getRealPart)(num2));
  // calculate imaginary part sum
  DATA_TYPE* sumImaginary = sumRationalNumbers(TYPE_NAME(getImaginaryPart)(num1), TYPE_NAME(getImaginaryPart)(num2));
  // create allocated sum num
  TYPE_NAME(Complex_t*) sum = TYPE_NAME(createComplexNumber)(sumReal, sumImaginary);

  // free memory
  freeRationalNumber(sumReal);
  freeRationalNumber(sumImaginary);

  return sum;
}

// subtraction operation
TYPE_NAME(Complex_t*) TYPE_NAME(subtractComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate real part sum
  DATA_TYPE* subReal = subtractRationalNumbers(TYPE_NAME(getRealPart)(num1), TYPE_NAME(getRealPart)(num2));
  // calculate imaginary part sum
  DATA_TYPE* subImaginary = subtractRationalNumbers(TYPE_NAME(getImaginaryPart)(num1), TYPE_NAME(getImaginaryPart)(num2));
  // create allocated subtract num
  TYPE_NAME(Complex_t*) sub = TYPE_NAME(createComplexNumber)(subReal, subImaginary);

  // free allocated memory
  freeRationalNumber(subReal);
  freeRationalNumber(subImaginary);

  return sub;
}

// multiplication operation
TYPE_NAME(Complex_t*) TYPE_NAME(multiplyComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  DATA_TYPE* multiplicationReal1 = multiplyRationalNumbers(TYPE_NAME(getRealPart)(num1), TYPE_NAME(getRealPart)(num2));
  DATA_TYPE* multiplicationReal2 = multiplyRationalNumbers(TYPE_NAME(getImaginaryPart)(num1), TYPE_NAME(getImaginaryPart)(num2));
  DATA_TYPE* multiplicationImaginary1 = multiplyRationalNumbers(TYPE_NAME(getRealPart)(num1), TYPE_NAME(getImaginaryPart)(num2)); 
  DATA_TYPE* multiplicationImaginary2 = multiplyRationalNumbers(TYPE_NAME(getImaginaryPart)(num1), TYPE_NAME(getRealPart)(num2));

  // calculate real part sum
  DATA_TYPE* multiReal = subtractRationalNumbers(multiplicationReal1, multiplicationReal2);
  // calculate imaginary part sum
  DATA_TYPE* multiImaginary = sumRationalNumbers(multiplicationImaginary1, multiplicationImaginary2) ;
  
  // create allocated multi num
  TYPE_NAME(Complex_t*) multi = TYPE_NAME(createComplexNumber)(multiReal, multiImaginary);

  // free allocated memory
  freeRationalNumber(multiplicationReal1);
  freeRationalNumber(multiplicationReal2);
  freeRationalNumber(multiplicationImaginary1);
  freeRationalNumber(multiplicationImaginary2);
  freeRationalNumber(multiReal);
  freeRationalNumber(multiImaginary);

  return multi;
}

// division operation
TYPE_NAME(Complex_t*) TYPE_NAME(divideComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate denominator
  DATA_TYPE* pow1 = powRationalNumber(TYPE_NAME(getRealPart)(num2), 2);
  DATA_TYPE* pow2 = powRationalNumber(TYPE_NAME(getImaginaryPart)(num2), 2);
  DATA_TYPE* denominator = sumRationalNumbers(pow1, pow2);

  // free allocated memory
  freeRationalNumber(pow1);
  freeRationalNumber(pow2);

  // calculate real part
  DATA_TYPE* multiReal1 = multiplyRationalNumbers(TYPE_NAME(getRealPart)(num1), TYPE_NAME(getRealPart)(num2));
  DATA_TYPE* multiReal2 = multiplyRationalNumbers(TYPE_NAME(getImaginaryPart)(num1), TYPE_NAME(getImaginaryPart)(num2));
  DATA_TYPE* sum = sumRationalNumbers(multiReal1, multiReal2);
  DATA_TYPE* divRealPart = divideRationalNumbers(sum, denominator);

  // free allocated memory
  freeRationalNumber(multiReal1);
  freeRationalNumber(multiReal2);
  freeRationalNumber(sum);

  // calculate imaginary part
  DATA_TYPE* multiImag1 = multiplyRationalNumbers(TYPE_NAME(getRealPart)(num2), TYPE_NAME(getImaginaryPart)(num1));
  DATA_TYPE* multiImag2 = multiplyRationalNumbers(TYPE_NAME(getRealPart)(num1), TYPE_NAME(getImaginaryPart)(num2));
  DATA_TYPE* sub = subtractRationalNumbers(multiImag1, multiImag2);
  DATA_TYPE* divImaginaryPart = divideRationalNumbers(sub, denominator);

  // free allocated memory
  freeRationalNumber(multiImag1);
  freeRationalNumber(multiImag2);
  freeRationalNumber(sub);

  // create allocated div num
  TYPE_NAME(Complex_t*) div = TYPE_NAME(createComplexNumber)(divRealPart, divImaginaryPart);

  // free allocated memory
  freeRationalNumber(denominator);
  freeRationalNumber(divRealPart);
  freeRationalNumber(divImaginaryPart);

  return div;
}

// accumulate num2 into num1 with a sum operation
void TYPE_NAME(accumulateComplexSum)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate sum
  TYPE_NAME(Complex_t*) sumNum = TYPE_NAME(sumComplexNumbers)(num1, num2);

  // set values to number 1
  TYPE_NAME(setValueToRealPart)(num1, TYPE_NAME(getRealPart)(sumNum));
  TYPE_NAME(setValueToImaginaryPart)(num1, TYPE_NAME(getImaginaryPart)(sumNum));

  // free allocated num
  TYPE_NAME(freeComplexNumber)(sumNum);
}

// accumulate num2 into num1 with a multiplication operation
void TYPE_NAME(accumulateComplexMulti)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate sum
  TYPE_NAME(Complex_t*) multiNum = TYPE_NAME(multiplyComplexNumbers)(num1, num2);

  // set values to number 1
  TYPE_NAME(setValueToRealPart)(num1, TYPE_NAME(getRealPart)(multiNum));
  TYPE_NAME(setValueToImaginaryPart)(num1, TYPE_NAME(getImaginaryPart)(multiNum));

  // free allocated num
  TYPE_NAME(freeComplexNumber)(multiNum);
}

// function to evaluate operation
TYPE_NAME(Complex_t*) TYPE_NAME(evaluateComplexOperation)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2, char *op) {
  if (!strcmp(op, "+")) {
    return TYPE_NAME(sumComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "-")) {
    return TYPE_NAME(subtractComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "*")) {
    return TYPE_NAME(multiplyComplexNumbers)(num1, num2);
  } else if(!strcmp(op, "/")) {
    return TYPE_NAME(divideComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "+=")) {
    TYPE_NAME(accumulateComplexSum)(num1, num2);
  } else if (!strcmp(op, "*=")) {
    TYPE_NAME(accumulateComplexMulti)(num1, num2);
  }
}

// display a rational complex number
void TYPE_NAME(displayComplexNumber)(TYPE_NAME(Complex_t*) num) {
  displayRationalNumber(TYPE_NAME(getRealPart)(num));
  printf(" + ");
  displayRationalNumber(TYPE_NAME(getImaginaryPart)(num));
  printf("i");
}

// free a rational number
void TYPE_NAME(freeComplexNumber)(TYPE_NAME(Complex_t*) num) {
  freeRationalNumber(TYPE_NAME(getRealPart)(num));
  freeRationalNumber(TYPE_NAME(getImaginaryPart)(num));
  free(num);
}

#endif 
#endif