#undef COMPLEX_H_INCLUDED
#undef TYPE
#undef TYPED
#undef FORMAT
#undef RATIONAL_INCLUDED

#include "rational-numbers.h"
#define TYPE Rational_t
#define RATIONAL_INCLUDED
#define TYPED(SOMETHING) RATIONAL_ ## SOMETHING
#define FORMAT "%ld "
#include "complex.h"