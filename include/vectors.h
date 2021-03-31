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

#endif
