#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/complex-rational.h"

#ifdef TYPED
#ifdef TYPE
// define tolerance
#define EPSILON 0.00001
#define EPSILON2 0.0001

// define boolean types
#define TRUE 1
#define FALSE 0

// complex for complex numbers with rationals
struct TYPED(complex) {
  TYPE *real;
  TYPE *imag;
};

// create a complex number
TYPED(Complex_t*) TYPED(createComplexNumber)(TYPE* real, TYPE* imag) {
  TYPED(Complex_t) *allocatedComplex = (TYPED(Complex_t*)) malloc(sizeof(TYPED(Complex_t)));

  if (allocatedComplex == NULL) {
    printf("Insuficient Space!");
    exit(1);
  }

  allocatedComplex->real = createRationalNumber(getNumerator(real), getDenominator(real));
  allocatedComplex->imag = createRationalNumber(getNumerator(imag), getDenominator(imag));

  return allocatedComplex;
}

// get real part of a complex number
TYPE* RATIONAL_getRealPart(TYPED(Complex_t*) num) {
  return num->real;
}

// get imaginary part of a complex number
TYPE* RATIONAL_getImaginaryPart(TYPED(Complex_t*) num) {
  return num->imag;
}

// get module of a complex number
double TYPED(getModuleComplexNumber)(TYPED(Complex_t*) num) {
  double doubleReal = convertRationalToDouble(TYPED(getRealPart)(num));
  double doubleImag = convertRationalToDouble(TYPED(getImaginaryPart)(num));

  return sqrt(pow(doubleReal, 2) + pow(doubleImag, 2));
}

// get angle of a complex number
double TYPED(getAngleComplexNumber)(TYPED(Complex_t*) num) {
  double module = TYPED(getModuleComplexNumber)(num);

  return acos(convertRationalToDouble(TYPED(getRealPart)(num)) / module);
}

// set new value to real part of a complex number
void TYPED(setValueToRealPart)(TYPED(Complex_t*) num, TYPE* value) {
  setDenominator(num->real, getDenominator(value));
  setNumerator(num->real, getNumerator(value));
}

// set new value to imaginary part of a complex number
void TYPED(setValueToImaginaryPart)(TYPED(Complex_t*) num, TYPE* value) {
  setDenominator(num->imag, getDenominator(value));
  setNumerator(num->imag, getNumerator(value));
}

// set new value to module of a complex number without modify its angle
void TYPED(setModuleComplexNumber)(TYPED(Complex_t*) num, double module) {
  double angle = TYPED(getAngleComplexNumber)(num); // get angle of num

  double a2 = module * cos(angle); // calculate real part
  double b2 = module * sin(angle); // calculate imaginary part

  // convert double numbers a2 and b2 into rationals ones
  Rational_t* a2Rational = convertDoubleToRational(a2);
  Rational_t* b2Rational = convertDoubleToRational(b2);

  // set new values to old number
  TYPED(setValueToRealPart)(num, a2Rational);
  TYPED(setValueToImaginaryPart)(num, b2Rational);

  // free allocated memory
  freeRationalNumber(a2Rational);
  freeRationalNumber(b2Rational);
} 

// set new value to angle of a complex number without modify its module
void TYPED(setAngleComplexNumber)(TYPED(Complex_t*) num, double angle) {
  double module = TYPED(getModuleComplexNumber)(num);

  double a2 = module * cos(angle); // calculate real part
  double b2 = module * sin(angle); // calculate imaginary part

  // convert double numbers a2 and b2 into rationals ones
  Rational_t* a2Rational = convertDoubleToRational(a2);
  Rational_t* b2Rational = convertDoubleToRational(b2);

  // set new values to old number
  TYPED(setValueToRealPart)(num, a2Rational);
  TYPED(setValueToImaginaryPart)(num, b2Rational);

  // free allocated memory
  freeRationalNumber(a2Rational);
  freeRationalNumber(b2Rational);
}

// assign number2 into number 1
void TYPED(assignComplexNumberTo)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
  TYPED(setValueToRealPart)(num1, TYPED(getRealPart)(num2));
  TYPED(setValueToImaginaryPart)(num1, TYPED(getImaginaryPart)(num2));
}

// returns an allocated copied complex number
TYPED(Complex_t*) TYPED(copyComplexNumberTo)(TYPED(Complex_t*) num) {
  TYPED(Complex_t*) copy = TYPED(createComplexNumber)(TYPED(getRealPart)(num), TYPED(getImaginaryPart)(num));
  return copy;
}

// is module 0?
int TYPED(isModuleZero)(TYPED(Complex_t*) num) {
  double module = TYPED(getModuleComplexNumber)(num); 

  if (module <= EPSILON) {
    return TRUE;
  } 
  return FALSE;
}

// is only real number?
int TYPED(isOnlyRealNumber)(TYPED(Complex_t*) num) {
  double real = convertRationalToDouble(TYPED(getImaginaryPart)(num));

  if (real <= EPSILON) {
    return TRUE;
  } 
  return FALSE;
}

// is only imaginary number?
int TYPED(isOnlyImaginaryNumber)(TYPED(Complex_t*) num) {
  double imag = convertRationalToDouble(TYPED(getRealPart)(num));

  if (imag <= EPSILON) {
    return TRUE;
  }
  return FALSE;
}

// 1 - number1 > number2
// 0 - number1 == number2
// -1 - number1 < number2
int TYPED(compareComplex)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
  double moduleNum1 = TYPED(getModuleComplexNumber)(num1);
  double moduleNum2 = TYPED(getModuleComplexNumber)(num2);

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
TYPED(Complex_t*) TYPED(calculateConjugateComplex)(TYPED(Complex_t*) num) {
  TYPE* realPart = TYPED(getRealPart)(num);
  TYPE* imaginaryPart = TYPED(getImaginaryPart)(num); // * -1

  setDenominator(imaginaryPart, -getDenominator(imaginaryPart));

  TYPED(Complex_t*) conjugate = TYPED(createComplexNumber)(realPart, imaginaryPart);

  return conjugate;
}

// sum operation
TYPED(Complex_t*) TYPED(sumComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
  // calculate real part sum
  TYPE* sumReal =  sumRationalNumbers(TYPED(getRealPart)(num1), TYPED(getRealPart)(num2));
  // calculate imaginary part sum
  TYPE* sumImaginary = sumRationalNumbers(TYPED(getImaginaryPart)(num1), TYPED(getImaginaryPart)(num2));
  // create allocated sum num
  TYPED(Complex_t*) sum = TYPED(createComplexNumber)(sumReal, sumImaginary);

  // free memory
  freeRationalNumber(sumReal);
  freeRationalNumber(sumImaginary);

  return sum;
}

// subtraction operation
TYPED(Complex_t*) TYPED(subtractComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
  // calculate real part sum
  TYPE* subReal = subtractRationalNumbers(TYPED(getRealPart)(num1), TYPED(getRealPart)(num2));
  // calculate imaginary part sum
  TYPE* subImaginary = subtractRationalNumbers(TYPED(getImaginaryPart)(num1), TYPED(getImaginaryPart)(num2));
  // create allocated subtract num
  TYPED(Complex_t*) sub = TYPED(createComplexNumber)(subReal, subImaginary);

  // free allocated memory
  freeRationalNumber(subReal);
  freeRationalNumber(subImaginary);

  return sub;
}

// multiplication operation
TYPED(Complex_t*) TYPED(multiplyComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
  TYPE* multiplicationReal1 = multiplyRationalNumbers(TYPED(getRealPart)(num1), TYPED(getRealPart)(num2));
  TYPE* multiplicationReal2 = multiplyRationalNumbers(TYPED(getImaginaryPart)(num1), TYPED(getImaginaryPart)(num2));
  TYPE* multiplicationImaginary1 = multiplyRationalNumbers(TYPED(getRealPart)(num1), TYPED(getImaginaryPart)(num2)); 
  TYPE* multiplicationImaginary2 = multiplyRationalNumbers(TYPED(getImaginaryPart)(num1), TYPED(getRealPart)(num2));

  // calculate real part sum
  TYPE* multiReal = subtractRationalNumbers(multiplicationReal1, multiplicationReal2);
  // calculate imaginary part sum
  TYPE* multiImaginary = sumRationalNumbers(multiplicationImaginary1, multiplicationImaginary2) ;
  
  // create allocated multi num
  TYPED(Complex_t*) multi = TYPED(createComplexNumber)(multiReal, multiImaginary);

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
TYPED(Complex_t*) TYPED(divideComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
  // calculate denominator
  TYPE* pow1 = powRationalNumber(TYPED(getRealPart)(num2), 2);
  TYPE* pow2 = powRationalNumber(TYPED(getImaginaryPart)(num2), 2);
  TYPE* denominator = sumRationalNumbers(pow1, pow2);

  // free allocated memory
  freeRationalNumber(pow1);
  freeRationalNumber(pow2);

  // calculate real part
  TYPE* multiReal1 = multiplyRationalNumbers(TYPED(getRealPart)(num1), TYPED(getRealPart)(num2));
  TYPE* multiReal2 = multiplyRationalNumbers(TYPED(getImaginaryPart)(num1), TYPED(getImaginaryPart)(num2));
  TYPE* sum = sumRationalNumbers(multiReal1, multiReal2);
  TYPE* divRealPart = divideRationalNumbers(sum, denominator);

  // free allocated memory
  freeRationalNumber(multiReal1);
  freeRationalNumber(multiReal2);
  freeRationalNumber(sum);

  // calculate imaginary part
  TYPE* multiImag1 = multiplyRationalNumbers(TYPED(getRealPart)(num2), TYPED(getImaginaryPart)(num1));
  TYPE* multiImag2 = multiplyRationalNumbers(TYPED(getRealPart)(num1), TYPED(getImaginaryPart)(num2));
  TYPE* sub = subtractRationalNumbers(multiImag1, multiImag2);
  TYPE* divImaginaryPart = divideRationalNumbers(sub, denominator);

  // free allocated memory
  freeRationalNumber(multiImag1);
  freeRationalNumber(multiImag2);
  freeRationalNumber(sub);

  // create allocated div num
  TYPED(Complex_t*) div = TYPED(createComplexNumber)(divRealPart, divImaginaryPart);

  // free allocated memory
  freeRationalNumber(denominator);
  freeRationalNumber(divRealPart);
  freeRationalNumber(divImaginaryPart);

  return div;
}

// accumulate num2 into num1 with a sum operation
void TYPED(accumulateComplexSum)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
  // calculate sum
  TYPED(Complex_t*) sumNum = TYPED(sumComplexNumbers)(num1, num2);

  // set values to number 1
  TYPED(setValueToRealPart)(num1, TYPED(getRealPart)(sumNum));
  TYPED(setValueToImaginaryPart)(num1, TYPED(getImaginaryPart)(sumNum));

  // free allocated num
  TYPED(freeComplexNumber)(sumNum);
}

// accumulate num2 into num1 with a multiplication operation
void TYPED(accumulateComplexMulti)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
  // calculate sum
  TYPED(Complex_t*) multiNum = TYPED(multiplyComplexNumbers)(num1, num2);

  // set values to number 1
  TYPED(setValueToRealPart)(num1, TYPED(getRealPart)(multiNum));
  TYPED(setValueToImaginaryPart)(num1, TYPED(getImaginaryPart)(multiNum));

  // free allocated num
  TYPED(freeComplexNumber)(multiNum);
}

// function to evaluate operation
TYPED(Complex_t*) TYPED(evaluateComplexOperation)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2, char *op) {
  if (!strcmp(op, "+")) {
    return TYPED(sumComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "-")) {
    return TYPED(subtractComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "*")) {
    return TYPED(multiplyComplexNumbers)(num1, num2);
  } else if(!strcmp(op, "/")) {
    return TYPED(divideComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "+=")) {
    TYPED(accumulateComplexSum)(num1, num2);
  } else if (!strcmp(op, "*=")) {
    TYPED(accumulateComplexMulti)(num1, num2);
  }
}

// convert two double numbers into a complex rational number
TYPED(Complex_t*) TYPED(convertIntoComplexRational)(double real, double imag) {
  // convert real and imag double numbers into complex numbers
  Rational_t* rationalReal = convertDoubleToRational(real);
  Rational_t* rationalImag = convertDoubleToRational(imag);

  // create converted number
  TYPED(Complex_t*) converted = TYPED(createComplexNumber)(rationalReal, rationalImag);

  // free allocated memory
  freeRationalNumber(rationalReal);
  freeRationalNumber(rationalImag);
  return converted;
}

// display a rational complex number
void TYPED(displayComplexNumber)(TYPED(Complex_t*) num) {
  displayRationalNumber(TYPED(getRealPart)(num));
  printf(" + ");
  displayRationalNumber(TYPED(getImaginaryPart)(num));
  printf("i");
}

// free a rational number
void TYPED(freeComplexNumber)(TYPED(Complex_t*) num) {
  freeRationalNumber(TYPED(getRealPart)(num));
  freeRationalNumber(TYPED(getImaginaryPart)(num));
  free(num);
}

#endif 
#endif