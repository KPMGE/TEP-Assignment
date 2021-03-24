#undef COMPLEX_H_INCLUDED
#undef TYPE
#undef TYPED
#undef FORMAT

#define TYPE long int
#define TYPED(SOMETHING) INT_ ## SOMETHING
#define FORMAT "%ld "
#include "complex.h"