#ifndef RATIONAL_INCLUDED

  #undef TYPE
  #undef TYPED

  // define macros for a complex rational number
  #define RATIONAL_INCLUDED
  #define TYPE Rational_t
  #define TYPED(SOMETHING) RATIONAL_ ## SOMETHING
  #include "rational-numbers.h"

  // structure for a rational complex type
  typedef struct TYPED(complex) TYPED(Complex_t);

  // function to create a complex rational number
  TYPED(Complex_t*) TYPED(createComplexNumber)(TYPE* real, TYPE* imag);
  // function to display a complex rational number
  void TYPED(displayComplexNumber)(TYPED(Complex_t*) num);
  // function to free a complex allocated rational number
  void TYPED(freeComplexNumber)(TYPED(Complex_t*) num);
  // function to get real part from a complex rational number
  TYPE* TYPED(getRealPart)(TYPED(Complex_t*) num);
  // function to get imaginarypart from a complex rational number
  TYPE* TYPED(getImaginaryPart)(TYPED(Complex_t*) num);
  // function to set a new value to real part of a complex rational number
  void TYPED(setValueToRealPart)(TYPED(Complex_t*), TYPE* value);
  // function to set a new value to imaginary part of a complex rational number
  void TYPED(setValueToImaginaryPart)(TYPED(Complex_t*), TYPE* value);
  // function to change module of a complex rational number without modify the orininal angle
  void TYPED(setModuleComplexNumber)(TYPED(Complex_t*) num, double module);
  // function to change the angle of a complex rational number without modify your original module
  void TYPED(setAngleComplexNumber)(TYPED(Complex_t*) num, double angle);
  // function to accumulate num1 += num2
  void TYPED(accumulateComplexSum)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // function to calculate module of a complex rational number
  double TYPED(getModuleComplexNumber)(TYPED(Complex_t*) num);
  // function to calculate the angle of a complex rational number
  double TYPED(getAngleComplexNumber)(TYPED(Complex_t*) num);
  // function to assign numbers num1 = num2 by changing inside them
  void TYPED(assignComplexNumberTo)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // function to return a copy of a given complex rational number
  TYPED(Complex_t*) TYPED(copyComplexNumberTo)(TYPED(Complex_t*) num);
  // check if module of complex number is zero
  int TYPED(isModuleZero)(TYPED(Complex_t*) num);
  // check if the complex number has only the real part
  int TYPED(isOnlyRealNumber)(TYPED(Complex_t*) num);
  // check if the complex number has only the imaginary part
  int TYPED(isOnlyImaginaryNumber)(TYPED(Complex_t*) num);
  // function to compare two complex rational numbers
  int TYPED(compareComplex)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // function to calculate the conjugate of a complex rational number
  TYPED(Complex_t*) TYPED(calculateConjugateComplex)(TYPED(Complex_t*) num);
  // function to sum of two complex numbers
  TYPED(Complex_t*) TYPED(sumComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // function to subtract of two complex numbers
  TYPED(Complex_t*) TYPED(subtractComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // function to multiply of two complex numbers
  TYPED(Complex_t*) TYPED(multiplyComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // function to divide of two complex numbers
  TYPED(Complex_t*) TYPED(divideComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // function to evaluate operation for a complex rational number
  TYPED(Complex_t*) TYPED(evaluateComplexOperation)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2, char *op);

#endif 