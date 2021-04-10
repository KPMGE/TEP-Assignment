#undef VECTOR_TAD_H
#undef DATA_TYPE
#undef TYPE_NAME
#undef IO_FORMAT

#define DATA_TYPE long int
#define TYPE_NAME(SOMETHING) INT_ ## SOMETHING
#define IO_FORMAT "%ld"
#include "vectors.h"
