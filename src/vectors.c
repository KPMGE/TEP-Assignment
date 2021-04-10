#ifdef DATA_TYPE
#ifdef TYPE_NAME
#ifdef IO_FORMAT

#define TRUE 1
#define FALSE 0

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

DATA_TYPE TYPE_NAME(getValueByIndex)(TYPE_NAME(vect_t *) vector, int i)
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
	DATA_TYPE trash = TYPE_NAME(getValueByIndex)(vector, i);
	trash = 0;

	*(vector->array + vector->index) = v;

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

#endif
#endif
#endif
