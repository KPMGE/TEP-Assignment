#ifdef DATA_TYPE
#ifdef TYPE_NAME
#ifdef IO_FORMAT

#define TRUE 1
#define FALSE 0
#define EPSILON 0.0001

struct TYPE_NAME(vect_s)
{
	int amountElements;
	int maxCapacity;
	int index;
	DATA_TYPE *array;
};

void TYPE_NAME(adjustVector)(TYPE_NAME(vect_t *) vector)
{
	if (vector->amountElements >= vector->maxCapacity)
	{
		vector->maxCapacity *= 2;
	}
	if (vector->amountElements < (vector->maxCapacity)/4)
	{
		vector->maxCapacity /= 2;
	}

	vector->array = (DATA_TYPE *) realloc(vector->array, vector->maxCapacity * sizeof(DATA_TYPE));
}

TYPE_NAME(vect_t *) TYPE_NAME(createVector)(int n, int i)
{
	TYPE_NAME(vect_t) *vector = (TYPE_NAME(vect_t *)) malloc(sizeof(TYPE_NAME(vect_t)));
	vector->amountElements = n;
	vector->maxCapacity = 100;
	vector->index = i;
	vector->array = (DATA_TYPE *) malloc(vector->maxCapacity * sizeof(DATA_TYPE));

	for (int j = 0; j < vector->maxCapacity; j++)
	{
		*(vector->array + j) = 0;
	}

	TYPE_NAME(adjustVector)(vector);

	return vector;
}

void TYPE_NAME(freeVector)(TYPE_NAME(vect_t *) vector)
{
	if (vector != NULL)
	{
		if (vector->array != NULL)
		{
			free(vector->array);
			vector->array = NULL;
		}

		free(vector);
		vector = NULL;
	}
}

void TYPE_NAME(copyToExistingVector)(TYPE_NAME(vect_t *) v1, TYPE_NAME(vect_t *) v2)
{
	v2->amountElements = v1->amountElements;
	v2->maxCapacity = v1->maxCapacity;
	v2->index = v1->index;
	v2->array = (DATA_TYPE *) realloc(v2->array, v2->maxCapacity * sizeof(DATA_TYPE));

	for (int i = 0; i < v1->maxCapacity; i++)
	{
		*(v2->array + i) = *(v1->array + i);
	}

	TYPE_NAME(adjustVector)(v1);
	TYPE_NAME(adjustVector)(v2);
}

TYPE_NAME(vect_t *) TYPE_NAME(copyToNewVector)(TYPE_NAME(vect_t *) v1)
{
	TYPE_NAME(vect_t) *v2 = TYPE_NAME(createVector)(50, 0);

	v2->amountElements = v1->amountElements;
	v2->maxCapacity = v1->maxCapacity;
	v2->index = v1->index;
	v2->array = (DATA_TYPE *) realloc(v2->array, v2->maxCapacity * sizeof(DATA_TYPE));

	for (int i = 0; i < v1->maxCapacity; i++)
	{
		*(v2->array + i) = *(v1->array + i);
	}

	TYPE_NAME(adjustVector)(v1);
	TYPE_NAME(adjustVector)(v2);

	return v2;
}

int TYPE_NAME(getAmountElements)(TYPE_NAME(vect_t *) vector)
{
	return vector->amountElements;
}

int TYPE_NAME(getMaxCapacity)(TYPE_NAME(vect_t *) vector)
{
	return vector->maxCapacity;
}

int TYPE_NAME(getIndex)(TYPE_NAME(vect_t *) vector)
{
	return vector->index;
}

DATA_TYPE TYPE_NAME(getFirstElement)(TYPE_NAME(vect_t *) vector)
{
	vector->index = 0;

	return *(vector->array + vector->index);
}

DATA_TYPE TYPE_NAME(getNextElement)(TYPE_NAME(vect_t *) vector)
{
	vector->index += 1;

	return *(vector->array + vector->index);
}

DATA_TYPE TYPE_NAME(getPrevElement)(TYPE_NAME(vect_t *) vector)
{
	vector->index -= 1;

	return *(vector->array + vector->index);
}

DATA_TYPE TYPE_NAME(getLastElement)(TYPE_NAME(vect_t *) vector)
{
	vector->index = vector->amountElements;

	return *(vector->array + vector->index);
}

DATA_TYPE TYPE_NAME(getElementByIndex)(TYPE_NAME(vect_t *) vector, int i)
{
	if (i > vector->amountElements)
	{
		vector->index = vector->amountElements - 1;
	}
	else
	{
		vector->index = i;
	}

	return *(vector->array + vector->index);
}

void TYPE_NAME(insertIndexPosValue)(TYPE_NAME(vect_t *) vector, DATA_TYPE v, int i)
{
	if (i >= 0 && i <= vector->amountElements)
	{
		vector->index = i;
		*(vector->array + vector->index) = v;
	}

	TYPE_NAME(adjustVector)(vector);
}

void TYPE_NAME(insertLastPosValue)(TYPE_NAME(vect_t *) vector, DATA_TYPE v)
{
	vector->amountElements++;
	vector->index = vector->amountElements - 1;

	*(vector->array + vector->index) = v;

	TYPE_NAME(adjustVector)(vector);
}

DATA_TYPE TYPE_NAME(deletePosition)(TYPE_NAME(vect_t *) vector, int i)
{
	for (int j = i; j < vector->amountElements; j++)
	{
		*(vector->array + j) = *(vector->array + (j+1));
	}
	vector->amountElements--;

	TYPE_NAME(adjustVector)(vector);

	return *(vector->array + i);
}

void TYPE_NAME(clearAllVector)(TYPE_NAME(vect_t *) vector)
{
	for (int i = 0; i <= vector->amountElements; i++)
	{
		*(vector->array + i) = 0;
	}
	vector->amountElements = 2;

	TYPE_NAME(adjustVector)(vector);
}

DATA_TYPE TYPE_NAME(getHigherAbs)(TYPE_NAME(vect_t *) vector)
{
	DATA_TYPE higherValue = 0;

	for (int i = 0; i < vector->amountElements; i++)
	{
		if (abs(*(vector->array + i)) > higherValue)
		{
			higherValue = *(vector->array + i);
			vector->index = i;
		}
	}

	return higherValue;
}

DATA_TYPE TYPE_NAME(getLowerAbs)(TYPE_NAME(vect_t *) vector)
{
	DATA_TYPE lowerValue = 0;

	for (int i = 0; i < vector->amountElements; i++)
	{
		if (abs(*(vector->array + i)) < lowerValue)
		{
			lowerValue = *(vector->array + i);
			vector->index = i;
		}
	}

	return lowerValue;
}

int TYPE_NAME(countEquals)(TYPE_NAME(vect_t *) vector, DATA_TYPE value)
{
	int count = 0;
	DATA_TYPE vecValue = 0;

	for (int i = 0; i < vector->amountElements; i++)
	{
		vecValue = *(vector->array + i);

		if (TYPE_NAME(diffValues)(vecValue, value) <= EPSILON)
		{
			count++;
		}
	}

	return count;
}

TYPE_NAME(vect_t *) TYPE_NAME(indexOfEquals)(TYPE_NAME(vect_t *) vector, DATA_TYPE value)
{
	int count = 0;
	DATA_TYPE vecValue = 0;
	TYPE_NAME(vect_t) *indexVector = TYPE_NAME(createVector)(1, 0);

	for (int i = 0; i < vector->amountElements; i++)
	{
		vecValue = *(vector->array + i);

		if (TYPE_NAME(diffValues)(vecValue, value) <= EPSILON)
		{
			*(indexVector->array + count) = (DATA_TYPE) i;
			count++;
			indexVector->amountElements = count;
			TYPE_NAME(adjustVector)(indexVector);
		}
	}
	indexVector->amountElements = count;
	TYPE_NAME(adjustVector)(indexVector);

	return indexVector;
}

//

float TYPE_NAME(diffValues)(DATA_TYPE v1, DATA_TYPE v2)
{
	if (v1 >= v2)
		return (v1 - v2);
	else
		return (v2 - v1);
}

void TYPE_NAME(displayVector)(TYPE_NAME(vect_t *) vector)
{
	printf("\n\n");
	for (int i = 0; i < vector->amountElements; i++)
	{
		printf(IO_FORMAT, *(vector->array + i));
		printf(", ");
	}
	printf("\n\n");
}

double TYPE_NAME(calculateScalarProduct)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2) {
  double scalarProduct = 0;

  int amountElementsVector1 = TYPE_NAME(getAmountElements)(vector1); 
  int amountElementsVector2 = TYPE_NAME(getAmountElements)(vector2); 

  if (amountElementsVector1 != amountElementsVector2) {
    printf("Your vectors don't have the same amount of elements!");
    exit(1);
  }

  for (int i = 0; i < amountElementsVector1; i++) {
    scalarProduct += (TYPE_NAME(getElementByIndex)(vector1, i) * TYPE_NAME(getElementByIndex)(vector2, i));
  }

  return scalarProduct;
}

TYPE_NAME(vect_t*)  TYPE_NAME(sumVectors)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t*) vector2) {
  int amountElementsVector1 = TYPE_NAME(getAmountElements)(vector1); 
  int amountElementsVector2 = TYPE_NAME(getAmountElements)(vector2); 

  if (amountElementsVector1 != amountElementsVector2) {
    printf("Your vectors don't have the same amount of elements!");
    exit(1);
  }

  // creating allocated vector
  TYPE_NAME(vect_t*) sumVector = TYPE_NAME(createVector)(amountElementsVector1, 0);

  // doing calculations
  for (int i = 0; i < amountElementsVector1; i++) { 
    // calculate sum
    DATA_TYPE sum = TYPE_NAME(getElementByIndex)(vector1, i) + TYPE_NAME(getElementByIndex)(vector2, i);
    // assign it into sumVector
    TYPE_NAME(insertIndexPosValue)(sumVector, sum, i); 
  }

  return sumVector;
}

TYPE_NAME(vect_t*)  TYPE_NAME(subtractVectors)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t*) vector2) {
  int amountElementsVector1 = TYPE_NAME(getAmountElements)(vector1); 
  int amountElementsVector2 = TYPE_NAME(getAmountElements)(vector2); 

  if (amountElementsVector1 != amountElementsVector2) {
    printf("Your vectors don't have the same amount of elements!");
    exit(1);
  }

  // creating allocated vector
  TYPE_NAME(vect_t*) subVector = TYPE_NAME(createVector)(amountElementsVector1, 0);

  // doing calculations
  for (int i = 0; i < amountElementsVector1; i++) { 
    // calculate sum
    DATA_TYPE sub = TYPE_NAME(getElementByIndex)(vector1, i) - TYPE_NAME(getElementByIndex)(vector2, i);
    // assign it into sumVector
    TYPE_NAME(insertIndexPosValue)(subVector, sub, i); 
  }

  return subVector;
}

TYPE_NAME(vect_t*) TYPE_NAME(multiplyVectorByScalar)(TYPE_NAME(vect_t *) vector, DATA_TYPE value) {
  // iterate over vector
  for (int i = 0; i < TYPE_NAME(getAmountElements)(vector); i++) {
    // calculate multiplication
    DATA_TYPE multi = value * TYPE_NAME(getElementByIndex)(vector, i);
    // set this value into vector
    TYPE_NAME(insertIndexPosValue)(vector, multi, i);
  }
}

#endif
#endif
#endif
