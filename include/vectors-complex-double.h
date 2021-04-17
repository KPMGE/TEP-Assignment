#ifndef VECTORS_COMPLEX_DOUBLE_INCLUDED
#define VECTORS_COMPLEX_DOUBLE_INCLUDED

#undef TYPE_NAME_VECTOR
#undef DATA_TYPE_VECTOR 

#include "complex-double.h"
#define TYPE_NAME_VECTOR(SOMETHING) DOUBLE_VECT_ ## SOMETHING
#define DATA_TYPE_VECTOR DOUBLE_Complex_t*
#include "vectors-complex.h"

#endif