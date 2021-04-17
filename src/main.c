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


int main(void)
{
	// testing int
	INT_Complex_t* numInt = INT_createComplexNumber(2, 3);
	INT_Complex_t* numInt2 = INT_createComplexNumber(4, 7);
	INT_Complex_t* numInt3 = INT_createComplexNumber(1, 9);

	INT_VECT_VectComplex_t* vectInt = INT_VECT_createVector(5, 0);
	INT_VECT_insertIndexPosValue(vectInt, numInt, 0);
	INT_VECT_insertIndexPosValue(vectInt, numInt2, 1);
	INT_VECT_insertIndexPosValue(vectInt, numInt3, 2);

	printf("--------- ORIGINAL VECTOR INT ---------\n\n");
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
	INT_freeComplexNumber(complexScalarInt);
	INT_VECT_freeVector(vectInt);


	// create types for double
	DOUBLE_Complex_t* num = DOUBLE_createComplexNumber(2.2, 3.1);
	DOUBLE_Complex_t* num2 = DOUBLE_createComplexNumber(5.5, 9.1);
	DOUBLE_Complex_t* num3 = DOUBLE_createComplexNumber(4.7, 2.32);

	DOUBLE_VECT_VectComplex_t* vectTest = DOUBLE_VECT_createVector(10, 0);
	DOUBLE_VECT_insertIndexPosValue(vectTest, num, 0);
	DOUBLE_VECT_insertIndexPosValue(vectTest, num2, 1);
	DOUBLE_VECT_insertLastPosValue(vectTest, num3);
	DOUBLE_VECT_insertLastPosValue(vectTest, num);

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

	printf("\nMean: %lf, Median: %lf, Variance: %lf, Standard Deviation: %lf\n", INT_calculateMean(equalsIndex), INT_calculateMedianUsually(equalsIndex), INT_calculateVariance(equalsIndex), INT_calculateDeviation(equalsIndex));

	printf("\nVector size: %d and capacity: %d before cleaning.\n", INT_getAmountElements(my_vect), INT_getMaxCapacity(my_vect));
	INT_clearAllVector(my_vect);
	printf("Vector size: %d and capacity: %d after cleaning.\n", INT_getAmountElements(my_vect), INT_getMaxCapacity(my_vect));
	INT_freeVector(my_vect);
	INT_freeVector(equalsIndex);

	return 0;
}
