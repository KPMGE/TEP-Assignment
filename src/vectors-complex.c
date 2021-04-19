#ifdef TYPE_NAME_VECTOR
#ifdef DATA_TYPE_VECTOR

#define TRUE 1
#define FALSE 0
#define EPSILON 0.0001


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

	return vector->array[0];
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

void TYPE_NAME_VECTOR(clearAllVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	for (int i = 0; i <= vector->amountElements; i++) {
    TYPE_NAME(freeComplexNumber)(vector->array[i]);
    vector->array[i] = NULL;
	}
	vector->amountElements = 2;

	TYPE_NAME_VECTOR(adjustVector)(vector);
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getHigherAbs)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
  // get first element of the vector
	DATA_TYPE_VECTOR higherValue = TYPE_NAME_VECTOR(getFirstElement)(vector);

	for (int i = 0; i < (vector->amountElements + 1); i++) {
    // current element
    DATA_TYPE_VECTOR currentElement = TYPE_NAME_VECTOR(getElementByIndex)(vector, i);

    // case current element is NULL skip it
    if (currentElement == NULL) {
      continue;
    }

    // module of the current element
    double moduleCurrent = TYPE_NAME(getModuleComplexNumber)(currentElement);

		if (moduleCurrent > TYPE_NAME(getModuleComplexNumber)(higherValue)) {
      higherValue = vector->array[i];
			vector->index = i;
		}
	}

	return higherValue;
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getLowerAbs)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
  // get first element of the vector
	DATA_TYPE_VECTOR lowerValue = TYPE_NAME_VECTOR(getFirstElement)(vector);

	for (int i = 0; i < (vector->amountElements + 1); i++) {
    // current element
    DATA_TYPE_VECTOR currentElement = TYPE_NAME_VECTOR(getElementByIndex)(vector, i);

    // case current element is NULL skip it
    if (currentElement == NULL) {
      continue;
    }

    // module of the current element
    double moduleCurrent = TYPE_NAME(getModuleComplexNumber)(currentElement);

		if (moduleCurrent < TYPE_NAME(getModuleComplexNumber)(lowerValue)) {
      lowerValue = vector->array[i];
			vector->index = i;
		}
	}

	return lowerValue;
}

int TYPE_NAME_VECTOR(countEquals)(TYPE_NAME_VECTOR(VectComplex_t*) vector, DATA_TYPE_VECTOR value) {
	int count = 0;

	for (int i = 0; i < (vector->amountElements + 1); i++) {
    DATA_TYPE_VECTOR vectValue = vector->array[i];

    // case current element is NULL skip it
    if (vectValue == NULL) {
      continue;
    }

    if (TYPE_NAME(compareComplexModule)(vectValue, value) == 0) {
      count++;
    }
	}

	return count;
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(calculateScalarProduct)(TYPE_NAME_VECTOR(VectComplex_t*) vector1, TYPE_NAME_VECTOR(VectComplex_t*) vector2) {
  int amountElementsVector1 = TYPE_NAME_VECTOR(getAmountElements)(vector1); 
  int amountElementsVector2 = TYPE_NAME_VECTOR(getAmountElements)(vector2); 

  if (amountElementsVector1 != amountElementsVector2) {
    printf("Your vectors don't have the same amount of elements!");
    exit(1);
  }

  // create variable to hold scalar product
  DATA_TYPE_VECTOR scalarProduct = TYPE_NAME(createComplexNumber)(0.0, 0.0);
  for (int i = 0; i < amountElementsVector1; i++) {
    // if the position of vector is valid
    if (vector1->array[i] != NULL && vector2->array[i] != NULL) {
      // calculate the conjugate of array's first element
      DATA_TYPE_VECTOR conjugate = TYPE_NAME(calculateConjugateComplex)(vector1->array[i]);
      // multiply conjugate times vector2's element
      DATA_TYPE_VECTOR multi = TYPE_NAME(multiplyComplexNumbers)(conjugate, vector2->array[i]);
      // accumulate that num into scalar product variable
      TYPE_NAME(accumulateComplexSum)(scalarProduct, multi);

      // free allocated memory
      TYPE_NAME(freeComplexNumber)(conjugate);
      TYPE_NAME(freeComplexNumber)(multi);
    }
  }

  return scalarProduct;
}

TYPE_NAME_VECTOR(VectComplex_t*)  TYPE_NAME_VECTOR(sumVectors)(TYPE_NAME_VECTOR(VectComplex_t*) vector1, TYPE_NAME_VECTOR(VectComplex_t*) vector2) {
  int amountElementsVector1 = TYPE_NAME_VECTOR(getAmountElements)(vector1); 
  int amountElementsVector2 = TYPE_NAME_VECTOR(getAmountElements)(vector2); 

  if (amountElementsVector1 != amountElementsVector2) {
    printf("Your vectors don't have the same amount of elements!");
    exit(1);
  }

  // creating allocated vector
  TYPE_NAME_VECTOR(VectComplex_t*) sumVector = TYPE_NAME_VECTOR(createVector)(amountElementsVector1, 0);

  // doing calculations
  for (int i = 0; i < amountElementsVector1; i++) { 
    // get elements of each vector
    DATA_TYPE_VECTOR elementVect1 = TYPE_NAME_VECTOR(getElementByIndex)(vector1, i);
    DATA_TYPE_VECTOR elementVect2 = TYPE_NAME_VECTOR(getElementByIndex)(vector2, i);

    // if element is not valid, skip it
    if (elementVect1 == NULL || elementVect2 == NULL) {
      continue;
    }

    // calculate sum
    DATA_TYPE_VECTOR sum =  TYPE_NAME(sumComplexNumbers)(elementVect1, elementVect2);

    // assign it into sumVector
    TYPE_NAME_VECTOR(insertIndexPosValue)(sumVector, sum, i); 

    // free allocated memory
    TYPE_NAME(freeComplexNumber)(sum);
  }

  return sumVector;
}

TYPE_NAME_VECTOR(VectComplex_t*)  TYPE_NAME_VECTOR(subtractVectors)(TYPE_NAME_VECTOR(VectComplex_t*) vector1, TYPE_NAME_VECTOR(VectComplex_t*) vector2) {
  int amountElementsVector1 = TYPE_NAME_VECTOR(getAmountElements)(vector1); 
  int amountElementsVector2 = TYPE_NAME_VECTOR(getAmountElements)(vector2); 

  if (amountElementsVector1 != amountElementsVector2) {
    printf("Your vectors don't have the same amount of elements!");
    exit(1);
  }

  // creating allocated vector
  TYPE_NAME_VECTOR(VectComplex_t*) subVector = TYPE_NAME_VECTOR(createVector)(amountElementsVector1, 0);

  // doing calculations
  for (int i = 0; i < amountElementsVector1; i++) { 
    // get elements of each vector
    DATA_TYPE_VECTOR elementVect1 = TYPE_NAME_VECTOR(getElementByIndex)(vector1, i);
    DATA_TYPE_VECTOR elementVect2 = TYPE_NAME_VECTOR(getElementByIndex)(vector2, i);

    // if element is not valid, skip it
    if (elementVect1 == NULL || elementVect2 == NULL) {
      continue;
    }

    // calculate subtraction
    DATA_TYPE_VECTOR sub =  TYPE_NAME(subtractComplexNumbers)(elementVect1, elementVect2);

    // assign it into sumVector
    TYPE_NAME_VECTOR(insertIndexPosValue)(subVector, sub, i); 

    // free allocated memory
    TYPE_NAME(freeComplexNumber)(sub);
  }

  return subVector;
}

void TYPE_NAME_VECTOR(multiplyVectorByScalar)(TYPE_NAME_VECTOR(VectComplex_t*) vector, DATA_TYPE_VECTOR value) {
  // iterate over vector
  for (int i = 0; i < TYPE_NAME_VECTOR(getAmountElements)(vector); i++) {
    // get current element from vector
    DATA_TYPE_VECTOR currentElement = TYPE_NAME_VECTOR(getElementByIndex)(vector, i);

    if (currentElement == NULL) {
      continue;
    }

    // calculate multiplication
    DATA_TYPE_VECTOR multi = TYPE_NAME(multiplyComplexNumbers)(currentElement, value);

    // set this value into vector
    TYPE_NAME_VECTOR(insertIndexPosValue)(vector, multi, i);

    // free allocated memory
    TYPE_NAME(freeComplexNumber)(multi);
    TYPE_NAME(freeComplexNumber)(currentElement);
  }
}

void TYPE_NAME_VECTOR(accumulateVectors)(TYPE_NAME_VECTOR(VectComplex_t*) vector1, TYPE_NAME_VECTOR(VectComplex_t*) vector2) {
  int amountElementsVector1 = TYPE_NAME_VECTOR(getAmountElements)(vector1);
  int amountElementsVector2 = TYPE_NAME_VECTOR(getAmountElements)(vector2);

  if (amountElementsVector1 != amountElementsVector2) {
    printf("Your vectors don't have the same amount of elements!");
    exit(1);
  }

  for (int i = 0; i < amountElementsVector1; i++) {
    // if element is not valid, skip it
    if (vector1->array[i] == NULL || vector2->array[i] == NULL) {
      continue;
    }

    TYPE_NAME(accumulateComplexSum)(vector1->array[i], vector2->array[i]);
  }
}

/* without typedef it would be necessary to insert all function pointer notation */
void TYPE_NAME_VECTOR(sortVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector, TYPE_NAME_VECTOR(fptrI_DD) criteria) {
	int shift = TRUE, i, j;
	DATA_TYPE_VECTOR memory;
	int size = TYPE_NAME_VECTOR(getAmountElements)(vector);

	for (j = (size - 1); (j >= 1) && (shift); j--) {
		shift = FALSE;

		for (i = 0; i < j; i++) {
			DATA_TYPE_VECTOR value1 = TYPE_NAME_VECTOR(getElementByIndex)(vector, i);
			DATA_TYPE_VECTOR value2 = TYPE_NAME_VECTOR(getElementByIndex)(vector, i+1);

      // if some value is not valid, skip it
      if (value1 == NULL || value2 == NULL) {
        continue;
      }

			if (criteria(value1, value2) == 1) {
        memory = vector->array[i];
        vector->array[i] = vector->array[i + 1];
        vector->array[i + 1] = memory;

				shift = TRUE;
			}
		}
	}
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(calculateMean)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
  int qtd = 0;
	DATA_TYPE_VECTOR sum = TYPE_NAME(createComplexNumber)(0, 0);

	for (int i = 0; i < (TYPE_NAME_VECTOR(getAmountElements)(vector)); i++) {
    DATA_TYPE_VECTOR element = vector->array[i];

    // if is not valid, skip it
    if (element == NULL) {
      continue;
    }

    TYPE_NAME(accumulateComplexSum)(sum, element);
    qtd++;
	}

  if (qtd == 0) {
    printf("You don't actually have a vector!");
    exit(0);
  }

  // calculate real and imaginary parts for mean complex number
  double real = TYPE_NAME(getRealPart)(sum) / qtd;
  double imag = TYPE_NAME(getImaginaryPart)(sum) / qtd;

  // free allocated memory
  TYPE_NAME(freeComplexNumber)(sum);

  return TYPE_NAME(createComplexNumber)(real, imag);
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(calculateVariance)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	DATA_TYPE_VECTOR  mean = TYPE_NAME_VECTOR(calculateMean)(vector);
  double realMean = TYPE_NAME(getRealPart)(mean);
  double imagMean = TYPE_NAME(getImaginaryPart)(mean);
	double varReal = 0;
  double varImag = 0;

  int amountElements = TYPE_NAME_VECTOR(getAmountElements)(vector);


	for (int i = 0; i < amountElements; i++) {
    DATA_TYPE_VECTOR currentNum = TYPE_NAME_VECTOR(getElementByIndex)(vector, i);

    if (currentNum == NULL) {
      continue;
    }

    varReal += pow((TYPE_NAME(getRealPart)(currentNum) - realMean), 2);
    varImag += pow((TYPE_NAME(getImaginaryPart)(currentNum) - imagMean), 2);
	}

  varReal = varReal / amountElements - 1;
  varImag = varImag / amountElements - 1;

  // free allocated memory
  TYPE_NAME(freeComplexNumber)(mean);

  return TYPE_NAME(createComplexNumber)(varReal, varImag);
}


DATA_TYPE_VECTOR TYPE_NAME_VECTOR(calculateDeviation)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
  DATA_TYPE_VECTOR variance = TYPE_NAME_VECTOR(calculateVariance)(vector);
  DATA_TYPE real = TYPE_NAME(getRealPart)(variance);
  DATA_TYPE imag = TYPE_NAME(getImaginaryPart)(variance);

  // free allocated memory
  TYPE_NAME(freeComplexNumber)(variance);

  return TYPE_NAME(createComplexNumber)(sqrt(real), sqrt(imag));
}

DATA_TYPE_VECTOR TYPE_NAME_VECTOR(calculateMedianUsually)(TYPE_NAME_VECTOR(VectComplex_t*) vector) {
	DATA_TYPE_VECTOR median;

	int size = TYPE_NAME_VECTOR(getAmountElements)(vector);
	TYPE_NAME_VECTOR(VectComplex_t*) newVector = TYPE_NAME_VECTOR(createVector)(size, 0);

  // copy vector to new vector
  int realSize = 0;
  for (int i = 0; i < size; i++) {
    if (vector->array[i] == NULL) {
      continue;
    }

    newVector->array[i] = TYPE_NAME(copyComplexNumberTo)(vector->array[i]);
    realSize++;
  }

  // sorting vector
	TYPE_NAME_VECTOR(sortVector)(newVector, TYPE_NAME(compareComplexModule));

  // if amount of elements is even
	if (realSize % 2 == 0) {
    DATA_TYPE_VECTOR element1 = TYPE_NAME_VECTOR(getElementByIndex)(newVector, (realSize-1)/2); 
    DATA_TYPE_VECTOR element2 = TYPE_NAME_VECTOR(getElementByIndex)(newVector, (realSize-1)/2 + 1); 

		median = TYPE_NAME(sumComplexNumbers)(element1, element2);
    TYPE_NAME(setValueToRealPart)(median, TYPE_NAME(getRealPart)(median) / 2.0);
    TYPE_NAME(setValueToImaginaryPart)(median, TYPE_NAME(getImaginaryPart)(median) / 2.0);
	} else {
    DATA_TYPE_VECTOR med = TYPE_NAME_VECTOR(getElementByIndex)(newVector, (realSize-2)/2 + 1);
		median = TYPE_NAME(copyComplexNumberTo)(med);
	}

  // free allocated memory
  TYPE_NAME_VECTOR(freeVector)(newVector);

	return median;
}

#endif 
#endif