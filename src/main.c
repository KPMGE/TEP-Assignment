#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/complex-int.h"
#include "../include/complex-double.h"
#include "../include/complex-rational.h"
#include "../include/rational-numbers.h"
#include "../include/conversions.h"
#include "../include/vectors-int.h"
#include "../include/vectors-double.h"


int main(void) {
  // create tests
  DOUBLE_Complex_t* doubleNum = DOUBLE_createComplexNumber(2.3, 3.6);
  INT_Complex_t* intNum = convertComplexDoubleToInt(doubleNum);
  RATIONAL_Complex_t* rationalNum = convertComplexDoubleToRational(doubleNum);

  printf("double number:\n");
  DOUBLE_displayComplexNumber(doubleNum);

  printf("\n\n\nInt number:\n");
  INT_displayComplexNumber(intNum);

  printf("\n\nRational number\n");
  RATIONAL_displayComplexNumber(rationalNum);


  printf("\n\nSet new values to rational number: \n");
  Rational_t* real = createRationalNumber(12, 7);
  Rational_t* imag = createRationalNumber(35, 9);
  RATIONAL_setValueToRealPart(rationalNum, real);
  RATIONAL_setValueToImaginaryPart(rationalNum, imag);

  printf("\n\nNew Rational number\n");
  RATIONAL_displayComplexNumber(rationalNum);

  printf("\n\nNew double:\n");
  DOUBLE_Complex_t* doubleNum2 = convertComplexRationalToDouble(rationalNum);
  DOUBLE_displayComplexNumber(doubleNum2);


  printf("\n\nNew int\n");
  INT_Complex_t* intNum2 = convertComplexRationalToInt(rationalNum);
  INT_displayComplexNumber(intNum2);


  INT_freeComplexNumber(intNum);
  INT_freeComplexNumber(intNum2);
  DOUBLE_freeComplexNumber(doubleNum);
  DOUBLE_freeComplexNumber(doubleNum2);
  RATIONAL_freeComplexNumber(rationalNum);
  freeRationalNumber(real);
  freeRationalNumber(imag);

  	/* ------------------------------------ VECTOR FUNCTIONS ------------------------------------ */
	printf("\n\n");


	INT_vect_t *my_vect = INT_createVector(32, 15);

	INT_insertIndexPosValue(my_vect, 555555, 5);
	INT_insertIndexPosValue(my_vect, -1, 23);
	printf("Element %ld in %d position\n", INT_getElementByIndex(my_vect, INT_getIndex(my_vect)), INT_getIndex(my_vect));
	INT_insertLastPosValue(my_vect, 5078269);
	printf("Element %ld in %d position\n", INT_getElementByIndex(my_vect, INT_getIndex(my_vect)), INT_getIndex(my_vect));
	printf("Element %ld in %d position\n", INT_deletePosition(my_vect, INT_getIndex(my_vect)), INT_getIndex(my_vect));
	printf("\nMax: %ld - Min: %ld vector values\n", INT_getHigherAbs(my_vect), INT_getLowerAbs(my_vect));

	INT_insertIndexPosValue(my_vect, 1234, 2); INT_insertIndexPosValue(my_vect, 1234, 4);
	INT_insertIndexPosValue(my_vect, 1234, 18); INT_insertIndexPosValue(my_vect, 1234, 31);
	printf("\nFinded '%d' values to '%d' on vector\n", INT_countEquals(my_vect, 1234), 1234);

	INT_vect_t *equalsIndex = INT_indexOfEquals(my_vect, 1234);
	INT_displayVector(my_vect);
	INT_displayVector(equalsIndex);

	printf("\nVector size: %d and capacity: %d before cleaning.\n", INT_getAmountElements(my_vect), INT_getMaxCapacity(my_vect));
	INT_clearAllVector(my_vect);
	printf("Vector size: %d and capacity: %d after cleaning.\n", INT_getAmountElements(my_vect), INT_getMaxCapacity(my_vect));
	INT_freeVector(my_vect);
	INT_freeVector(equalsIndex);


  // create a vector
  INT_vect_t* vect1 = INT_createVector(3, 0);
  // assign values
  INT_insertIndexPosValue(vect1, 3, 0);
  INT_insertIndexPosValue(vect1, 8, 1);
  INT_insertIndexPosValue(vect1, 1, 2);

  // create another vector
  INT_vect_t* vect2 = INT_createVector(3, 0);
  // assign values
  INT_insertIndexPosValue(vect2, 2, 0);
  INT_insertIndexPosValue(vect2, 4, 1);
  INT_insertIndexPosValue(vect2, 1, 2);

  // displaying vectors
  printf("\n\nNew Vectors:\n");
  INT_displayVector(vect1);
  INT_displayVector(vect2);

  // calculate sum of vector1 and vector2
  INT_vect_t* sum = INT_sumVectors(vect1, vect2);
  printf("Sum vector:\n");
  INT_displayVector(sum);

  // calculate subtraction of vector1 and vector2
  INT_vect_t* sub = INT_subtractVectors(vect1, vect2);
  printf("Sub vector:\n");
  INT_displayVector(sub);

  // displaying scalar product
  printf("Scalar Product: %.3f\n\n", INT_calculateScalarProduct(vect1, vect2));

  // freeing vectors
  INT_freeVector(vect1);
  INT_freeVector(vect2);
  INT_freeVector(sum);
  INT_freeVector(sub);


  return 0;
}
