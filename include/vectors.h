#ifndef VECTOR_TAD_H

	#define VECTOR_TAD_H // pre-compilation program

	/* type definitions */
	typedef struct TYPE_NAME(vect_s) TYPE_NAME(vect_t); // struct pointer
	typedef int (*TYPE_NAME(fptrI_DD))(DATA_TYPE, DATA_TYPE); // function pointer

	/* functions prototypes */
	void TYPE_NAME(adjustVector)(TYPE_NAME(vect_t *) vector); // adjust max array size and elements amount
	TYPE_NAME(vect_t *) TYPE_NAME(createVector)(int n, int i); // allocate vector space in memory with basic values
	void TYPE_NAME(freeVector)(TYPE_NAME(vect_t *) vector); // free allocation in memory and atribute NULL valute to the pointers
	void TYPE_NAME(copyToExistingVector)(TYPE_NAME(vect_t *) v1, TYPE_NAME(vect_t *) v2); // copy vector to existing vector
	TYPE_NAME(vect_t *) TYPE_NAME(copyToNewVector)(TYPE_NAME(vect_t *) v1); // copy vector to new vector and return its address
	int TYPE_NAME(getAmountElements)(TYPE_NAME(vect_t *) vector); // elements amount getter
	int TYPE_NAME(getMaxCapacity)(TYPE_NAME(vect_t *) vector); // elements max size getter
	int TYPE_NAME(getIndex)(TYPE_NAME(vect_t *) vector); // index getter
	DATA_TYPE TYPE_NAME(getFirstElement)(TYPE_NAME(vect_t *) vector); // first element getter
	DATA_TYPE TYPE_NAME(getNextElement)(TYPE_NAME(vect_t *) vector); // next element getter
	DATA_TYPE TYPE_NAME(getPrevElement)(TYPE_NAME(vect_t *) vector); // previous element getter
	DATA_TYPE TYPE_NAME(getLastElement)(TYPE_NAME(vect_t *) vector); // last element getter
	DATA_TYPE TYPE_NAME(getElementByIndex)(TYPE_NAME(vect_t *) vector, int i); // indexed element getter
	void TYPE_NAME(insertIndexPosValue)(TYPE_NAME(vect_t *) vector, DATA_TYPE v, int i); // insert data on indexed position
	void TYPE_NAME(insertLastPosValue)(TYPE_NAME(vect_t *) vector, DATA_TYPE v); // insert data on last position
	DATA_TYPE TYPE_NAME(deletePosition)(TYPE_NAME(vect_t *) vector, int i); // remove data from position and reorganize elements
	void TYPE_NAME(clearAllVector)(TYPE_NAME(vect_t *) vector); // remove all elements and resize the array size
	DATA_TYPE TYPE_NAME(getBiggestAbs)(TYPE_NAME(vect_t *) vector); // get value from the biggest absolute
	DATA_TYPE TYPE_NAME(getSmallestAbs)(TYPE_NAME(vect_t *) vector); // get value from the smallest absolute
	int TYPE_NAME(countEquals)(TYPE_NAME(vect_t *) vector, DATA_TYPE value); // count equal values in vector
	TYPE_NAME(vect_t *) TYPE_NAME(indexOfEquals)(TYPE_NAME(vect_t *) vector, DATA_TYPE value); // list index of equals values
	void TYPE_NAME(sortVector)(TYPE_NAME(vect_t *) vector, TYPE_NAME(fptrI_DD) criteria); // sort the vector using bubbleSort
	TYPE_NAME(vect_t *) TYPE_NAME(regularlyInsert)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2, TYPE_NAME(fptrI_DD) criteria); // regularly insert two vectors values in another vector
	TYPE_NAME(vect_t *) TYPE_NAME(sumVectors)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2); // 
	TYPE_NAME(vect_t *) TYPE_NAME(subtractVectors)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2); // 
	void TYPE_NAME(multiplyVectorByScalar)(TYPE_NAME(vect_t *) vector, DATA_TYPE scalar); // 
	double TYPE_NAME(calculateScalarProduct)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2); // 
	void TYPE_NAME(accumulateVectors)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2); // 
	double TYPE_NAME(calculateMean)(TYPE_NAME(vect_t *) vector); // calculate arithmetic mean
	double TYPE_NAME(calculateVariance)(TYPE_NAME(vect_t *) vector); // calculate variance
	double TYPE_NAME(calculateDeviation)(TYPE_NAME(vect_t *) vector); // calculate standart deviation
	double TYPE_NAME(calculateMedian)(TYPE_NAME(vect_t *) vector); // calculate median (form 1)
	double TYPE_NAME(calculateMedianUsually)(TYPE_NAME(vect_t *) vector); // calculate median (usually form)
	int TYPE_NAME(sortingCriter)(DATA_TYPE a, DATA_TYPE b); // sorting criteria with comparison return
	float TYPE_NAME(diffValues)(DATA_TYPE v1, DATA_TYPE v2); // return difference of values
	void TYPE_NAME(displayVector)(TYPE_NAME(vect_t *) vector); // display vector in stdout

#endif
