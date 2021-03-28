#undef VECTOR_INCLUDED
#undef TYPE
#undef TYPED

#define TYPE long int
#define TYPED(SOMETHING) INT_ ## SOMETHING
#include "complex.h"
#include "vectors.h"

