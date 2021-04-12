#undef COMPLEX_H_INCLUDED
#undef DATA_TYPE
#undef TYPE_NAME
#undef IO_FORMAT

#define DATA_TYPE double
#define TYPE_NAME(SOMETHING) DOUBLE_##SOMETHING
#define IO_FORMAT "%lf "
#include "complex.h"
