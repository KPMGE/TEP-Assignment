#ifdef TYPED
#ifdef TYPE

// struct to vector
struct TYPED(vector) {
  int amountElements;
  int maxCapacity;
  int index;
  TYPED(Complex_t**) vector;
};

// function that creates a vector
TYPED(Vector_t*) TYPED(createVector)() {
  // allocate vector structure
  TYPED(Vector_t*) allocatedVectorStructure =  (TYPED(Vector_t*)) malloc(sizeof(TYPED(Vector_t)));

  // allocate inner vector of complex structure
  allocatedVectorStructure->vector = (TYPED(Complex_t**)) malloc(10 * sizeof(TYPED(Complex_t*)));

  // assigning some values into  vector of complex numbers
  for (int i = 0; i < 10; i++) {
    allocatedVectorStructure->vector[i] = TYPED(createComplexNumber)(i, i+2);

    // update amount of elements
    allocatedVectorStructure->amountElements++;
  }

  return allocatedVectorStructure;
}

// free a vector
void TYPED(freeVector)(TYPED(Vector_t*) vec) {
  for (int i = 0; i < vec->amountElements; i++) {
    TYPED(freeComplexNumber)(vec->vector[i]);
  }
  free(vec);
}

// display a vector
void TYPED(displayVector)(TYPED(Vector_t*) vec) {
  for (int i = 0; i < vec->amountElements; i++) {
    TYPED(displayComplexNumber)(vec->vector[i]);
  }
}

#endif
#endif