#undef COMPLEX_H_INCLUDED
#undef TYPE
#undef TYPED
#undef FORMAT

#define TYPE double
#define TYPED(SOMETHING) DOUBLE_##SOMETHING
#define FORMAT "%lf "
#include "complex.h"
