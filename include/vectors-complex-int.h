#ifndef VECTORS_COMPLEX_INT_INCLUDED
#define VECTORS_COMPLEX_INT_INCLUDED

#undef VECTORS_COMPLEX_INCLUDED
#undef TYPE_NAME_VECTOR
#undef DATA_TYPE_VECTOR 

#include "complex-int.h"
#define TYPE_NAME_VECTOR(SOMETHING) INT_VECT_ ## SOMETHING
#define DATA_TYPE_VECTOR INT_Complex_t*
#include "vectors-complex.h"

#endif