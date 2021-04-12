#ifndef COMPLEX_H_INCLUDED

  #define COMPLEX_H_INCLUDED

  // create a Complext_t for a specific used type
  typedef struct TYPE_NAME(complex) TYPE_NAME(Complex_t);

  // create complex number of a given type
  TYPE_NAME(Complex_t*) TYPE_NAME(createComplexNumber)(DATA_TYPE real, DATA_TYPE imag);
  // free complex a complex number of a given type
  void TYPE_NAME(freeComplexNumber)(TYPE_NAME(Complex_t*) num);
  // display a complex number of a given type
  void TYPE_NAME(displayComplexNumber)(TYPE_NAME(Complex_t*) num);
  // assign a complex number to another one
  void TYPE_NAME(assignComplexNumberTo)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // return a copy of a given complex number
  TYPE_NAME(Complex_t*) TYPE_NAME(copyComplexNumberTo)(TYPE_NAME(Complex_t*) num);
  // get real part of a complex number
  DATA_TYPE TYPE_NAME(getRealPart)(TYPE_NAME(Complex_t*) num);
  // get imaginary part of a complex number
  DATA_TYPE TYPE_NAME(getImaginaryPart)(TYPE_NAME(Complex_t*) num);
  // get module of a complex number
  double TYPE_NAME(getModuleComplexNumber)(TYPE_NAME(Complex_t*) num);
  // get angle of a complex number
  double TYPE_NAME(getAngleComplexNumber)(TYPE_NAME(Complex_t*) num);
  // set new value to real part of a complex number
  void TYPE_NAME(setValueToRealPart)(TYPE_NAME(Complex_t*), double value);
  // set a new value to imaginary part of a complex number
  void TYPE_NAME(setValueToImaginaryPart)(TYPE_NAME(Complex_t*) num, double value);
  // set a new value to module of a complex number without modify your angle
  void TYPE_NAME(setModuleComplexNumber)(TYPE_NAME(Complex_t*) num, double k);
  // set a new value to angle of a complex number without modify your module
  void TYPE_NAME(setAngleComplexNumber)(TYPE_NAME(Complex_t*) num, double angle);
  // check if the module of a complex number is zero
  int TYPE_NAME(isModuleZero)(TYPE_NAME(Complex_t*) num);
  // check if a complex number is actually a real number
  int TYPE_NAME(isOnlyRealNumber)(TYPE_NAME(Complex_t*) num);
  // check if a complex number is only a imaginary number
  int TYPE_NAME(isOnlyImaginaryNumber)(TYPE_NAME(Complex_t*) num);
  // compare two complex numbers with respect to module
  int TYPE_NAME(compareComplexModule)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // compare two complex numbers with respect to angle
  int TYPE_NAME(compareComplexAngle)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // calculate the conjugate of a complex number
  TYPE_NAME(Complex_t*) TYPE_NAME(calculateConjugateComplex)(TYPE_NAME(Complex_t*) num);
  // calculate the sum of two complex numbers
  TYPE_NAME(Complex_t*) TYPE_NAME(sumComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // subract complex numbers
  TYPE_NAME(Complex_t*) TYPE_NAME(subtractComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // multiply complex numbers
  TYPE_NAME(Complex_t*) TYPE_NAME(multiplyComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // divide complex numbers
  TYPE_NAME(Complex_t*) TYPE_NAME(divideComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // assign sum of two complex numbers into number1
  void TYPE_NAME(accumulateComplexSum)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // assign multiplication of two complex numbers into number1
  void TYPE_NAME(accumulateComplexMulti)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2);
  // function to evalue each operation
  TYPE_NAME(Complex_t*) TYPE_NAME(evaluateComplexOperation)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2, char *op);

#endif