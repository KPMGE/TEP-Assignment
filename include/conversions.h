#ifndef CONVERSIONS_H_INCLUDED

  #define CONVERSIONS_H_INCLUDED

  #include "complex-int.h"
  #include "complex-double.h"
  #include "complex-rational.h"

  // convert of complex double into complex int
  INT_Complex_t* convertComplexDoubleToInt(DOUBLE_Complex_t* num);
  // convert of complex rational into complex int
  INT_Complex_t* convertComplexRationalToInt(RATIONAL_Complex_t* num);
  // convert of complex int into complex double
  DOUBLE_Complex_t* convertComplexIntToDouble(INT_Complex_t* num);
  // convert of complex rational into complex double
  DOUBLE_Complex_t* convertComplexRationalToDouble(RATIONAL_Complex_t* num);
  // convert of complex int into complex rational
  RATIONAL_Complex_t* convertComplexIntToRational(INT_Complex_t* num);
  // convert of complex double into complex rational
  RATIONAL_Complex_t* convertComplexDoubleToRational(DOUBLE_Complex_t* num); 

#endif