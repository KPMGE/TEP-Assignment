#ifdef TYPE_NAME_VECTOR
#ifdef DATA_TYPE_VECTOR

struct TYPE_NAME_VECTOR(_vectComplex) {
	int amountElements;
	int maxCapacity;
	int index;
	DATA_TYPE_VECTOR* array;
};

void TYPE_NAME_VECTOR(adjustVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	if (vector->amountElements >= vector->maxCapacity)
	{
		vector->maxCapacity *= 2;
	}
	if (vector->amountElements < (vector->maxCapacity)/4)
	{
		vector->maxCapacity /= 2;
	}

	vector->array = (DATA_TYPE_VECTOR*) realloc(vector->array, vector->maxCapacity * sizeof(DATA_TYPE_VECTOR*));
}

TYPE_NAME_VECTOR(VectComplex_t*) TYPE_NAME_VECTOR(createVector)(int n, int i) {
	TYPE_NAME_VECTOR(VectComplex_t*) vector = (TYPE_NAME_VECTOR(VectComplex_t*))  malloc(sizeof(TYPE_NAME_VECTOR(VectComplex_t)));
	vector->amountElements = n;
	vector->maxCapacity = 100;
	vector->index = i;
	vector->array = (DATA_TYPE_VECTOR*) malloc(vector->maxCapacity * sizeof(DATA_TYPE_VECTOR));

	for (int j = 0; j < vector->maxCapacity; j++) {
    vector->array[j] = NULL;
	}

	TYPE_NAME_VECTOR(adjustVector)(vector);

	return vector;
}

void TYPE_NAME_VECTOR(freeVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	if (vector != NULL)
	{

    for (int i = 0; i < vector->maxCapacity; i++) {
      if (vector->array[i] != NULL) {
        TYPE_NAME(freeComplexNumber)(vector->array[i]);
        vector->array[i] = NULL;
      }
    }

    free(vector->array);
		free(vector);
		vector = NULL;
	}
}

void TYPE_NAME_VECTOR(displayVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
  for (int i = 0; i < vector->amountElements; i++) {
    TYPE_NAME(displayComplexNumber)(vector->array[i]);
  }
}

#endif 
#endif