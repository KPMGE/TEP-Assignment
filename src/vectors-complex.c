#ifdef TYPE_NAME_VECTOR
#ifdef DATA_TYPE_VECTOR

struct TYPE_NAME_VECTOR(_vectComplex) {
	int amountElements;
	int maxCapacity;
	int index;
	DATA_TYPE_VECTOR* array;
};

void TYPE_NAME_VECTOR(adjustVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	if (vector->amountElements >= vector->maxCapacity) {
		vector->maxCapacity *= 2;
	}
	if (vector->amountElements < (vector->maxCapacity)/4) {
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

  for (int i = 0; i < TYPE_NAME_VECTOR(getMaxCapacity)(vector); i++) {
    vector->array[i] = NULL;
	}

	TYPE_NAME_VECTOR(adjustVector)(vector);

	return vector;
}

void TYPE_NAME_VECTOR(freeVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	if (vector != NULL) {
    for (int i = 0; i < TYPE_NAME_VECTOR(getMaxCapacity)(vector); i++) {
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
  for (int i = 0; i < TYPE_NAME_VECTOR(getMaxCapacity)(vector); i++) {
    if (vector->array[i] != NULL) {
      TYPE_NAME(displayComplexNumber)(TYPE_NAME_VECTOR(getElementByIndex)(vector, i));
      printf("\n");
    }
  }
}

int TYPE_NAME_VECTOR(getAmountElements)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	return vector->amountElements;
}

int TYPE_NAME_VECTOR(getMaxCapacity)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	return vector->maxCapacity;
}

int TYPE_NAME_VECTOR(getIndex)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	return vector->index;
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getFirstElement)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	vector->index = 0;

	return *(vector->array + vector->index);
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getNextElement)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	vector->index += 1;

	return vector->array[vector->index];
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getPrevElement)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	vector->index -= 1;

	return *(vector->array + vector->index);
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getLastElement)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	vector->index = vector->amountElements;

	return *(vector->array + vector->index);
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getElementByIndex)(TYPE_NAME_VECTOR(VectComplex_t*) vector, int i) {
	if (i > vector->amountElements) {
		vector->index = vector->amountElements - 1;
	} else {
		vector->index = i;
	}

	return *(vector->array + vector->index);
}

void TYPE_NAME_VECTOR(insertIndexPosValue)(TYPE_NAME_VECTOR(VectComplex_t*) vector, DATA_TYPE_VECTOR v, int i) {
	if (i >= 0 && i <= vector->amountElements) {
		vector->index = i;
    vector->array[i] = TYPE_NAME(copyComplexNumberTo)(v);
	}

	TYPE_NAME_VECTOR(adjustVector)(vector);
}

void TYPE_NAME_VECTOR(insertLastPosValue)(TYPE_NAME_VECTOR(VectComplex_t*) vector, DATA_TYPE_VECTOR v) {
	vector->amountElements++;
	vector->index = vector->amountElements - 1;

	*(vector->array + vector->index) = TYPE_NAME(copyComplexNumberTo)(v);

	TYPE_NAME_VECTOR(adjustVector)(vector);
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(deletePosition)(TYPE_NAME_VECTOR(VectComplex_t*) vector, int i) {
  // free element
  TYPE_NAME(freeComplexNumber)(vector->array[i]);

	for (int j = i; j < vector->amountElements; j++) {
		*(vector->array + j) = *(vector->array + (j+1));
	}
	vector->amountElements--;

	TYPE_NAME_VECTOR(adjustVector)(vector);

	return *(vector->array + i);
}

#endif 
#endif