#ifndef VECTOR_INCLUDED
#define VECTOR_INCLUDED

typedef struct TYPED(vector) TYPED(Vector_t);

TYPED(Vector_t*) TYPED(createVector)();
void TYPED(freeVector)(TYPED(Vector_t*) vec);
void TYPED(displayVector)(TYPED(Vector_t*) vec);

#endif