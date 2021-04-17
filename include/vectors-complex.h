#ifndef VECTORS_COMPLEX_INCLUDED
#define VECTORS_COMPLEX_INCLUDED

  typedef struct TYPE_NAME_VECTOR(_vectComplex) TYPE_NAME_VECTOR(VectComplex_t);

  // function to adjust size of vector
  void TYPE_NAME_VECTOR(adjustVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to create a vector of complex int or double
  TYPE_NAME_VECTOR(VectComplex_t*) TYPE_NAME_VECTOR(createVector)(int n, int i);
  // function to free the vector
  void TYPE_NAME_VECTOR(freeVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to display the vector
  void TYPE_NAME_VECTOR(displayVector)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to get amount of elments of vector
  int TYPE_NAME_VECTOR(getAmountElements)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to get max capacity of vector elements
  int TYPE_NAME_VECTOR(getMaxCapacity)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to get the current inded of vector elements
  int TYPE_NAME_VECTOR(getIndex)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function  to get the first element of the vector
  DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getFirstElement)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to get the next element of the vector
  DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getNextElement)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to get the previous element of the vector
  DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getPrevElement)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to get last element of the vector
  DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getLastElement)(TYPE_NAME_VECTOR(VectComplex_t*) vector);
  // function to get an elment given an index
  DATA_TYPE_VECTOR TYPE_NAME_VECTOR(getElementByIndex)(TYPE_NAME_VECTOR(VectComplex_t*) vector, int i);
  // function to insert a new element in the vector at a given index
  void TYPE_NAME_VECTOR(insertIndexPosValue)(TYPE_NAME_VECTOR(VectComplex_t*) vector, DATA_TYPE_VECTOR v, int i);
  // function to insert an element sequentialy
  void TYPE_NAME_VECTOR(insertLastPosValue)(TYPE_NAME_VECTOR(VectComplex_t*) vector, DATA_TYPE_VECTOR v);
  // function to delete a given position of the vector
  DATA_TYPE_VECTOR TYPE_NAME_VECTOR(deletePosition)(TYPE_NAME_VECTOR(VectComplex_t*) vector, int i);

#endif