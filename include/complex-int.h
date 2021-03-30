#undef COMPLEX_H_INCLUDED
#undef TYPE
#undef TYPED
#undef FORMAT
#undef COMPLEX_INT_INCLUDED

#define COMPLEX_INT_INCLUDED
#define TYPE long int
#define TYPED(SOMETHING) INT_ ## SOMETHING
#define FORMAT "%ld "
#include "complex.h"