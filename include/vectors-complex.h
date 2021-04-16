#ifndef VECTORS_COMPLEX_INCLUDED
#define VECTORS_COMPLEX_INCLUDED

typedef struct TYPE_NAME_VECTOR(_vectComplex) TYPE_NAME_VECTOR(VectComplex_t);

void TYPE_NAME_VECTOR(adjustVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
TYPE_NAME_VECTOR(VectComplex_t*) TYPE_NAME_VECTOR(createVector)(int n, int i);
void TYPE_NAME_VECTOR(freeVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
void TYPE_NAME_VECTOR(displayVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector);

#endif