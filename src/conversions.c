#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/conversions.h"

INT_Complex_t* convertComplexDoubleToInt(DOUBLE_Complex_t* num) {
  // get real and imaginary parts and rounding them
  long int convertedReal = round(DOUBLE_getRealPart(num));
  long int convertedImag = round(DOUBLE_getImaginaryPart(num));

  // create converted number of complex int type
  INT_Complex_t* convertedInt = INT_createComplexNumber(convertedReal, convertedImag);

  // returning it
  return convertedInt;
}

INT_Complex_t* convertComplexRationalToInt(RATIONAL_Complex_t* num) {
  // getting real and imaginary parts of num
  Rational_t* realPart = RATIONAL_getRealPart(num);
  Rational_t* imagPart = RATIONAL_getImaginaryPart(num); 

  // converting into integer numbers
  long int convertedReal = round(convertRationalToDouble(realPart));
  long int convertedImag = round(convertRationalToDouble(imagPart));

  // crate a complex integer number
  INT_Complex_t* convertedInt = INT_createComplexNumber(convertedReal, convertedImag);

  // return it
  return convertedInt;
}

DOUBLE_Complex_t* convertComplexIntToDouble(INT_Complex_t* num) {
  // get real and imaginary parts and casting them
  double convertedReal = (double) INT_getRealPart(num);
  double convertedImag = (double) INT_getImaginaryPart(num);

  // create converted number of complex double type
  DOUBLE_Complex_t* convertedDouble = DOUBLE_createComplexNumber(convertedReal, convertedReal);

  // returning it
  return convertedDouble;
}

DOUBLE_Complex_t* convertComplexRationalToDouble(RATIONAL_Complex_t* num) {
  // getting real and imaginary parts of num
  Rational_t* realPart = RATIONAL_getRealPart(num);
  Rational_t* imagPart = RATIONAL_getImaginaryPart(num); 

  // converting into integer numbers
  double convertedReal = convertRationalToDouble(realPart);
  double convertedImag = convertRationalToDouble(imagPart);

  // crate a complex integer number
  DOUBLE_Complex_t* convertedDouble = DOUBLE_createComplexNumber(convertedReal, convertedImag);

  // return it
  return convertedDouble;
}

RATIONAL_Complex_t* convertComplexIntToRational(INT_Complex_t* num) {
  // get real and imaginary parts and converting them into rational numbers
  Rational_t* convertedReal = convertDoubleToRational(INT_getRealPart(num));
  Rational_t* convertedImag = convertDoubleToRational(INT_getImaginaryPart(num));

  // create converted number of complex double type
  RATIONAL_Complex_t* convertedRational = RATIONAL_createComplexNumber(convertedReal, convertedImag);

  // free allocated memory
  freeRationalNumber(convertedReal);
  freeRationalNumber(convertedImag);

  // returning number
  return convertedRational;
}

RATIONAL_Complex_t* convertComplexDoubleToRational(DOUBLE_Complex_t* num) {
  // get real and imaginary parts and converting them into rational numbers
  Rational_t* convertedReal = convertDoubleToRational(DOUBLE_getRealPart(num));
  Rational_t* convertedImag = convertDoubleToRational(DOUBLE_getImaginaryPart(num));

  // create converted number of complex double type
  RATIONAL_Complex_t* convertedRational = RATIONAL_createComplexNumber(convertedReal, convertedImag);

  // free allocated memory
  freeRationalNumber(convertedReal);
  freeRationalNumber(convertedImag);

  // returning number
  return convertedRational;
}