#ifndef RATIONAL_INCLUDED

  #undef DATA_TYPE
  #undef TYPE_NAME

  // define macros for a complex rational number
  #define RATIONAL_INCLUDED
  #define DATA_TYPE Rational_t
  #define TYPE_NAME(SOMETHING) RATIONAL_ ## SOMETHING
  #include "rational-numbers.h"

  // structure for a rational complex type
  typedef struct TYPE_NAME(complex) TYPE_NAME(Complex_t);

  // function to create a complex rational number
  TYPE_NAME(Complex_t*) TYPE_NAME(createComplexNumber)(DATA_TYPE* real, DATA_TYPE* imag);
  // function to display a complex rational number
  void TYPE_NAME(displayComplexNumber)(TYPE_NAME(Complex_t*) num);
  // function to free a complex allocated rational number
  void TYPE_NAME(freeComplexNumber)(TYPE_NAME(Complex_t*) num);
  // function to get real part from a complex rational number
  DATA_TYPE* TYPE_NAME(getRealPart)(TYPE_NAME(Complex_t*) num);
  // function to get imaginarypart from a complex rational number
  DATA_TYPE* TYPE_NAME(getImaginaryPart)(TYPE_NAME(Complex_t*) num);
  // function to set a new value to real part of a complex rational number
  void TYPE_NAME(setValueToRealPart)(TYPE_NAME(Complex_t*), DATA_TYPE* value);
  // function to set a new value to imaginary part of a complex rational number
  void TYPE_NAME(setValueToImaginaryPart)(TYPE_NAME(Complex_t*), DATA_TYPE* value);
  // function to change module of a complex rational number without modify the orininal angle
  void TYPE_NAME(setModuleComplexNumber)(TYPE_NAME(Complex_t*) num, double module);
  // function to change the angle of a complex rational number without modify your original module
  void TYPE_NAME(setAngleComplexNumber)(TYPE_NAME(Complex_t*) num, double angle);
  // function to accumulate num1 += num2
  void TYPE_NAME(accumulateComplexSum)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // function to calculate module of a complex rational number
  double TYPE_NAME(getModuleComplexNumber)(TYPE_NAME(Complex_t*) num);
  // function to calculate the angle of a complex rational number
  double TYPE_NAME(getAngleComplexNumber)(TYPE_NAME(Complex_t*) num);
  // function to assign numbers num1 = num2 by changing inside them
  void TYPE_NAME(assignComplexNumberTo)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // function to return a copy of a given complex rational number
  TYPE_NAME(Complex_t*) TYPE_NAME(copyComplexNumberTo)(TYPE_NAME(Complex_t*) num);
  // check if module of complex number is zero
  int TYPE_NAME(isModuleZero)(TYPE_NAME(Complex_t*) num);
  // check if the complex number has only the real part
  int TYPE_NAME(isOnlyRealNumber)(TYPE_NAME(Complex_t*) num);
  // check if the complex number has only the imaginary part
  int TYPE_NAME(isOnlyImaginaryNumber)(TYPE_NAME(Complex_t*) num);
  // function to compare two complex rational numbers
  int TYPE_NAME(compareComplex)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // function to calculate the conjugate of a complex rational number
  TYPE_NAME(Complex_t*) TYPE_NAME(calculateConjugateComplex)(TYPE_NAME(Complex_t*) num);
  // function to sum of two complex numbers
  TYPE_NAME(Complex_t*) TYPE_NAME(sumComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // function to subtract of two complex numbers
  TYPE_NAME(Complex_t*) TYPE_NAME(subtractComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // function to multiply of two complex numbers
  TYPE_NAME(Complex_t*) TYPE_NAME(multiplyComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // function to divide of two complex numbers
  TYPE_NAME(Complex_t*) TYPE_NAME(divideComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // function to evaluate operation for a complex rational number
  TYPE_NAME(Complex_t*) TYPE_NAME(evaluateComplexOperation)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2, char *op);

#endif 