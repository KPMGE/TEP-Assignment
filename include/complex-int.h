#ifndef COMPLEX_INT_H_INCLUDED
#define COMPLEX_INT_H_INCLUDED

  #undef COMPLEX_H_INCLUDED
  #undef DATA_TYPE
  #undef TYPE_NAME
  #undef IO_FORMAT

  #define DATA_TYPE long int
  #define TYPE_NAME(SOMETHING) INT_ ## SOMETHING
  #define IO_FORMAT "%ld "
  #include "complex.h"

#endif