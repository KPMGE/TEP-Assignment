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
#include "../include/vectors-complex-double.h"
#include "../include/vectors-complex-int.h"


int main(void) {
	// testing int
	INT_Complex_t* numInt = INT_createComplexNumber(2, 3);
	INT_Complex_t* numInt2 = INT_createComplexNumber(4, 7);
	INT_Complex_t* numInt3 = INT_createComplexNumber(1, 9);

	INT_VECT_VectComplex_t* vectInt = INT_VECT_createVector(5, 0);
	INT_VECT_insertIndexPosValue(vectInt, numInt2, 0);
	INT_VECT_insertIndexPosValue(vectInt, numInt, 1);
	INT_VECT_insertIndexPosValue(vectInt, numInt3, 2);

	printf("--------- ORIGINAL VECTOR INT ---------\n\n");
	INT_VECT_displayVector(vectInt);

  INT_Complex_t* variance = INT_VECT_calculateVariance(vectInt);
  printf("Variance: ");
  INT_displayComplexNumber(variance);
  INT_freeComplexNumber(variance);

  INT_Complex_t* median = INT_VECT_calculateMedianUsually(vectInt);
  printf("Median: ");
  INT_displayComplexNumber(median);

	printf("\n\n---------  ORDERED VECTOR ---------\n\n");
  INT_VECT_sortVector(vectInt, INT_compareComplexModule);
	INT_VECT_displayVector(vectInt);

	printf("--------- MEAN ---------\n\n");
  INT_Complex_t* mean = INT_VECT_calculateMean(vectInt);
  INT_displayComplexNumber(mean);

  printf("\n\n--------- ACCUMULATE VECTOR IN ITSELF ---------\n\n");
  INT_VECT_accumulateVectors(vectInt, vectInt); 
	INT_VECT_displayVector(vectInt);

	printf("\n\n--------- MULTPLY BY 3 + 2i ---------\n");
	INT_Complex_t* complexScalarInt = INT_createComplexNumber(3, 2);
	INT_VECT_multiplyVectorByScalar(vectInt, complexScalarInt);
	INT_VECT_displayVector(vectInt);

	printf("\n\n--------- POSITION 0 DELETED ---------\n");
	INT_VECT_deletePosition(vectInt, 0);
	INT_VECT_displayVector(vectInt);

	printf("\n--------- CLEARED VECTOR ---------\n");
	INT_VECT_clearAllVector(vectInt); 
	INT_VECT_displayVector(vectInt);

	INT_freeComplexNumber(numInt);
	INT_freeComplexNumber(numInt2);
	INT_freeComplexNumber(numInt3);
  INT_freeComplexNumber(median);
	INT_freeComplexNumber(complexScalarInt);
  INT_freeComplexNumber(mean);
	INT_VECT_freeVector(vectInt);

  /*

	// create types for double
	DOUBLE_Complex_t* num = DOUBLE_createComplexNumber(2.2, 3.1);
	DOUBLE_Complex_t* num2 = DOUBLE_createComplexNumber(5.5, 9.1);
	DOUBLE_Complex_t* num3 = DOUBLE_createComplexNumber(4.7, 2.32);

	DOUBLE_VECT_VectComplex_t* vectTest = DOUBLE_VECT_createVector(10, 0);
	DOUBLE_VECT_insertIndexPosValue(vectTest, num, 0);
	DOUBLE_VECT_insertIndexPosValue(vectTest, num2, 1);
	DOUBLE_VECT_insertLastPosValue(vectTest, num3);
	DOUBLE_VECT_insertLastPosValue(vectTest, num);

  printf("\n\n\n================ IMPLEMENTATION WITH DOUBLE ==================");
	printf("\n\n\n--------- ORIGINAL VECTOR DOUBLE ---------\n");
	DOUBLE_VECT_displayVector(vectTest);

	printf("\n--------- GREATEST MODULE ---------\n");
	DOUBLE_Complex_t* greatest = DOUBLE_VECT_getHigherAbs(vectTest);
	DOUBLE_displayComplexNumber(greatest);

	printf("\n\n--------- SMALLEST MODULE ---------\n");
	DOUBLE_Complex_t* smallest = DOUBLE_VECT_getLowerAbs(vectTest);
	DOUBLE_displayComplexNumber(smallest);

	printf("\n\n--------- SCALAR PRODUCT ---------\n");
	DOUBLE_Complex_t* scalarProduct = DOUBLE_VECT_calculateScalarProduct(vectTest, vectTest);
	DOUBLE_displayComplexNumber(scalarProduct);
	DOUBLE_freeComplexNumber(scalarProduct);

	printf("\n\n--------- SUM SAME VECT ---------\n");
	DOUBLE_VECT_VectComplex_t* sumSameVect = DOUBLE_VECT_sumVectors(vectTest, vectTest);
	DOUBLE_VECT_displayVector(sumSameVect);

	printf("\n\n--------- SUB SAME VECT ---------\n");
	DOUBLE_VECT_VectComplex_t* subSameVect = DOUBLE_VECT_subtractVectors(vectTest, vectTest);
	DOUBLE_VECT_displayVector(subSameVect);

	printf("\n\n--------- AMOUNT EQUALS ---------\n");
	printf("equals: %d", DOUBLE_VECT_countEquals(vectTest, num));

	printf("\n\n--------- MULTPLY BY 3 + 2i ---------\n");
	DOUBLE_Complex_t* complexScalar = DOUBLE_createComplexNumber(3, 2);
	DOUBLE_VECT_multiplyVectorByScalar(vectTest, complexScalar);
	DOUBLE_VECT_displayVector(vectTest);

	printf("\n\n--------- POSITION 0 DELETED ---------\n");
	DOUBLE_VECT_deletePosition(vectTest, 0);
	DOUBLE_VECT_displayVector(vectTest);

	printf("\n--------- CLEARED VECTOR ---------\n");
	DOUBLE_VECT_clearAllVector(vectTest); 
	DOUBLE_VECT_displayVector(vectTest);


	DOUBLE_freeComplexNumber(num);
	DOUBLE_freeComplexNumber(num2);
	DOUBLE_freeComplexNumber(num3);
	DOUBLE_freeComplexNumber(complexScalar);
	DOUBLE_VECT_freeVector(vectTest);
	DOUBLE_VECT_freeVector(sumSameVect);
	DOUBLE_VECT_freeVector(subSameVect);

  // ------------------------------------ VECTOR FUNCTIONS ------------------------------------ 
	// INT test
	printf("\n\n");

	INT_vect_t *my_vect = INT_createVector(32, 15);

	INT_insertIndexPosValue(my_vect, 555555, 5);
	INT_insertIndexPosValue(my_vect, -1, 23);
	printf("Element %ld in %d position\n", INT_getElementByIndex(my_vect, INT_getIndex(my_vect)), INT_getIndex(my_vect));
	INT_insertLastPosValue(my_vect, 5078269);
	printf("Element %ld in %d position\n", INT_getElementByIndex(my_vect, INT_getIndex(my_vect)), INT_getIndex(my_vect));
	printf("Element %ld in %d position\n", INT_deletePosition(my_vect, INT_getIndex(my_vect)), INT_getIndex(my_vect));
	printf("\nMax: %ld - Min: %ld vector values\n", INT_getBiggestAbs(my_vect), INT_getSmallestAbs(my_vect));

	INT_insertIndexPosValue(my_vect, 1234, 2); INT_insertIndexPosValue(my_vect, 1234, 4);
	INT_insertIndexPosValue(my_vect, 1234, 18); INT_insertIndexPosValue(my_vect, 1234, 31);
	printf("\nFinded '%d' values to '%d' on vector\n", INT_countEquals(my_vect, 1234), 1234);

	INT_vect_t *equalsIndex = INT_indexOfEquals(my_vect, 1234);
	INT_displayVector(my_vect);
	INT_displayVector(equalsIndex);
	INT_sortVector(my_vect, &INT_sortingCriter);
	INT_displayVector(my_vect);

	printf("\nMean: %lf, Median: %lf, Variance: %lf, Standard Deviation: %lf\n", INT_calculateMean(equalsIndex), INT_calculateMedianUsually(equalsIndex), INT_calculateVariance(equalsIndex), INT_calculateDeviation(equalsIndex));

	printf("\nVector size: %d and capacity: %d before cleaning.\n", INT_getAmountElements(my_vect), INT_getMaxCapacity(my_vect));
	INT_clearAllVector(my_vect);
	printf("Vector size: %d and capacity: %d after cleaning.\n", INT_getAmountElements(my_vect), INT_getMaxCapacity(my_vect));
	INT_freeVector(my_vect);
	INT_freeVector(equalsIndex);


	// DOUBLE test
	printf("\n\n");

	DOUBLE_vect_t *vect_test = DOUBLE_createVector(32, 15);

	DOUBLE_insertIndexPosValue(vect_test, 555555, 5);
	DOUBLE_insertIndexPosValue(vect_test, -1, 23);
	printf("Element %lf in %d position\n", DOUBLE_getElementByIndex(vect_test, DOUBLE_getIndex(vect_test)), DOUBLE_getIndex(vect_test));
	DOUBLE_insertLastPosValue(vect_test, 5078269);
	printf("Element %lf in %d position\n", DOUBLE_getElementByIndex(vect_test, DOUBLE_getIndex(vect_test)), DOUBLE_getIndex(vect_test));
	printf("Element %lf in %d position\n", DOUBLE_deletePosition(vect_test, DOUBLE_getIndex(vect_test)), DOUBLE_getIndex(vect_test));
	printf("\nMax: %lf - Min: %lf vector values\n", DOUBLE_getBiggestAbs(vect_test), DOUBLE_getSmallestAbs(vect_test));

	DOUBLE_insertIndexPosValue(vect_test, 1234, 2); DOUBLE_insertIndexPosValue(vect_test, 1234, 4);
	DOUBLE_insertIndexPosValue(vect_test, 1234, 18); DOUBLE_insertIndexPosValue(vect_test, 1234, 31);
	printf("\nFinded '%d' values to '%d' on vector\n", DOUBLE_countEquals(vect_test, 1234), 1234);

	DOUBLE_vect_t *indexEquals = DOUBLE_indexOfEquals(vect_test, 1234);
	DOUBLE_displayVector(vect_test);
	DOUBLE_displayVector(indexEquals);

	printf("\nMean: %lf, Median: %lf, Variance: %lf, Standard Deviation: %lf\n", DOUBLE_calculateMean(indexEquals), DOUBLE_calculateMedianUsually(indexEquals), DOUBLE_calculateVariance(indexEquals), DOUBLE_calculateDeviation(indexEquals));

	printf("\nVector size: %d and capacity: %d before cleaning.\n", DOUBLE_getAmountElements(vect_test), DOUBLE_getMaxCapacity(vect_test));
	DOUBLE_clearAllVector(vect_test);
	printf("Vector size: %d and capacity: %d after cleaning.\n", DOUBLE_getAmountElements(vect_test), DOUBLE_getMaxCapacity(vect_test));
	DOUBLE_freeVector(vect_test);
	DOUBLE_freeVector(indexEquals);

  */

	return 0;
}
