#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

// create a Complext_t for a specific used type
typedef struct TYPED(complex) TYPED(Complex_t);

// if rational wasn't included
#ifndef RATIONAL_INCLUDED
  // create complex number of a given type
  TYPED(Complex_t*) TYPED(createComplexNumber)(TYPE real, TYPE imag);
  // free complex a complex number of a given type
  void TYPED(freeComplexNumber)(TYPED(Complex_t*) num);
  // display a complex number of a given type
  void TYPED(displayComplexNumber)(TYPED(Complex_t*) num);
  // assign a complex number to another one
  void TYPED(assignComplexNumberTo)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // return a copy of a given complex number
  TYPED(Complex_t*) TYPED(copyComplexNumberTo)(TYPED(Complex_t*) num);

  // we need to create functions to perform conversions here

  // get/set values into a complex number
  // get real part of a complex number
  TYPE TYPED(getRealPart)(TYPED(Complex_t*) num);
  // get imaginary part of a complex number
  TYPE TYPED(getImaginaryPart)(TYPED(Complex_t*) num);
  // get module of a complex number
  double TYPED(getModuleComplexNumber)(TYPED(Complex_t*) num);
  // get angle of a complex number
  double TYPED(getAngleComplexNumber)(TYPED(Complex_t*) num);
  // set new value to real part of a complex number
  void TYPED(setValueToRealPart)(TYPED(Complex_t*), double value);
  // set a new value to imaginary part of a complex number
  void TYPED(setValueToImaginaryPart)(TYPED(Complex_t*) num, double value);
  // set a new value to module of a complex number without modify your angle
  void TYPED(setModuleComplexNumber)(TYPED(Complex_t*) num, TYPE k);
  // set a new value to angle of a complex number without modify your module
  void TYPED(setAngleComplex)(TYPED(Complex_t*) num); // we need to adjust module!

  // comparison
  // check if the module of a complex number is zero
  int TYPED(isModuleZero)(TYPED(Complex_t*) num);
  // check if a complex number is actually a real number
  int TYPED(isOnlyRealNumber)(TYPED(Complex_t*) num);
  // check if a complex number is only a imaginary number
  int TYPED(isOnlyImaginaryNumber)(TYPED(Complex_t*) num);
  // compare two complex numbers
  int TYPED(compareComplex)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);

  // operations
  // calculate the conjugate of a complex number
  TYPED(Complex_t*) TYPED(calculateConjugateComplex)(TYPED(Complex_t*) num);
  // calculate the sum of two complex numbers
  TYPED(Complex_t*) TYPED(sumComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // subract complex numbers
  TYPED(Complex_t*) TYPED(subtractComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // multiply complex numbers
  TYPED(Complex_t*) TYPED(multiplyComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // divide complex numbers
  TYPED(Complex_t*) TYPED(divideComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // assign sum of two complex numbers into number1
  void TYPED(accumulateComplexSum)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  // assign multiplication of two complex numbers into number1
  void TYPED(accumulateComplexMulti)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);

  // function to evalue each operation
  TYPED(Complex_t*) TYPED(evaluateComplexOperation)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2, char *op);

// if rational included
#else 
  TYPED(Complex_t*) TYPED(createComplexNumber)(TYPE* real, TYPE* imag);
  void TYPED(displayComplexNumber)(TYPED(Complex_t*) num);
  void TYPED(freeComplexNumber)(TYPED(Complex_t*) num);
  TYPE* TYPED(getRealPart)(TYPED(Complex_t*) num);
  TYPE* TYPED(getImaginaryPart)(TYPED(Complex_t*) num);
  void TYPED(setValueToRealPart)(TYPED(Complex_t*), TYPE* value);
  void TYPED(setValueToImaginaryPart)(TYPED(Complex_t*), TYPE* value);


  double TYPED(getModuleComplexNumber)(TYPED(Complex_t*) num);
  double TYPED(getAngleComplexNumber)(TYPED(Complex_t*) num);
  void TYPED(assignComplexNumberTo)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  TYPED(Complex_t*) TYPED(copyComplexNumberTo)(TYPED(Complex_t*) num);

  int TYPED(isModuleZero)(TYPED(Complex_t*) num);
  int TYPED(isOnlyRealNumber)(TYPED(Complex_t*) num);
  int TYPED(isOnlyImaginaryNumber)(TYPED(Complex_t*) num);
  int TYPED(compareComplex)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  TYPED(Complex_t*) TYPED(calculateConjugateComplex)(TYPED(Complex_t*) num);
  TYPED(Complex_t*) TYPED(sumComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  TYPED(Complex_t*) TYPED(subtractComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  TYPED(Complex_t*) TYPED(multiplyComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
  TYPED(Complex_t*) TYPED(divideComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
#endif
#endif
