#ifndef VECTOR_TAD_H

	#define VECTOR_TAD_H

	// type definition and pre-compilation program
	typedef struct TYPE_NAME(vect_s) TYPE_NAME(vect_t);

	// functions prototypes
	void TYPE_NAME(adjustVector)(TYPE_NAME(vect_t *) vector);
	TYPE_NAME(vect_t *) TYPE_NAME(createVector)(int n, int i);
	void TYPE_NAME(freeVector)(TYPE_NAME(vect_t *) vector);
	void TYPE_NAME(copyToExistingVector)(TYPE_NAME(vect_t *) v1, TYPE_NAME(vect_t *) v2);
	TYPE_NAME(vect_t *) TYPE_NAME(copyToNewVector)(TYPE_NAME(vect_t *) v1);
	int TYPE_NAME(getAmountElements)(TYPE_NAME(vect_t *) vector);
	int TYPE_NAME(getMaxCapacity)(TYPE_NAME(vect_t *) vector);
	int TYPE_NAME(getIndex)(TYPE_NAME(vect_t *) vector);
	DATA_TYPE TYPE_NAME(getFirstElement)(TYPE_NAME(vect_t *) vector);
	DATA_TYPE TYPE_NAME(getNextElement)(TYPE_NAME(vect_t *) vector);
	DATA_TYPE TYPE_NAME(getPrevElement)(TYPE_NAME(vect_t *) vector);
	DATA_TYPE TYPE_NAME(getLastElement)(TYPE_NAME(vect_t *) vector);
	DATA_TYPE TYPE_NAME(getElementByIndex)(TYPE_NAME(vect_t *) vector, int i);
	void TYPE_NAME(insertIndexPosValue)(TYPE_NAME(vect_t *) vector, DATA_TYPE v, int i);
	void TYPE_NAME(insertLastPosValue)(TYPE_NAME(vect_t *) vector, DATA_TYPE v);
	DATA_TYPE TYPE_NAME(deletePosition)(TYPE_NAME(vect_t *) vector, int i);
	void TYPE_NAME(clearAllVector)(TYPE_NAME(vect_t *) vector);
	DATA_TYPE TYPE_NAME(getHigherAbs)(TYPE_NAME(vect_t *) vector);
	DATA_TYPE TYPE_NAME(getLowerAbs)(TYPE_NAME(vect_t *) vector);
	int TYPE_NAME(countEquals)(TYPE_NAME(vect_t *) vector, DATA_TYPE value);
	TYPE_NAME(vect_t *) TYPE_NAME(indexOfEquals)(TYPE_NAME(vect_t *) vector, DATA_TYPE value);
	//
	//
	TYPE_NAME(vect_t *) TYPE_NAME(sumVectors)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2);
	TYPE_NAME(vect_t *) TYPE_NAME(subtractVectors)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2);
	void TYPE_NAME(multiplyVectorByScalar)(TYPE_NAME(vect_t *) vector, DATA_TYPE scalar);
	double TYPE_NAME(calculateScalarProduct)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2);
	void TYPE_NAME(accumulateVectors)(TYPE_NAME(vect_t *) vector1, TYPE_NAME(vect_t *) vector2);
	double TYPE_NAME(calculateMean)(TYPE_NAME(vect_t *) vector);
	double TYPE_NAME(calculateVariance)(TYPE_NAME(vect_t *) vector);
	double TYPE_NAME(calculateDeviation)(TYPE_NAME(vect_t *) vector);
	DATA_TYPE TYPE_NAME(calculateMedian)(TYPE_NAME(vect_t *) vector);
	float TYPE_NAME(diffValues)(DATA_TYPE v1, DATA_TYPE v2);
	void TYPE_NAME(displayVector)(TYPE_NAME(vect_t *) vector);

#endif
