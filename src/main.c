#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/complex-int.h"
#include "../include/complex-double.h"
#include "../include/complex-rational.h"
#include "../include/rational-numbers.h"
#include "../include/conversions.h"
#include "../include/vectors-int.h"


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
	INT_insertIndexPosValue(my_vect, 5078269, 5);
	printf("Element "); printf(IO_FORMAT, INT_getValueByIndex(my_vect, INT_getIndex(my_vect))); printf(" in %d position\n", INT_getIndex(my_vect));
	INT_insertLastPosValue(my_vect, 555555);
	printf("Element "); printf(IO_FORMAT, INT_getValueByIndex(my_vect, INT_getIndex(my_vect))); printf(" in %d position\n", INT_getIndex(my_vect));
	printf("Element "); printf(IO_FORMAT, INT_deletePosition(my_vect, INT_getIndex(my_vect))); printf(" in %d position\n", INT_getIndex(my_vect));
	printf("\nVector size: %d and capacity: %d before cleaning.\n", INT_getAmountElements(my_vect), INT_getMaxCapacity(my_vect));
	INT_clearAllVector(my_vect);
	printf("Vector size: %d and capacity: %d after cleaning.\n", INT_getAmountElements(my_vect), INT_getMaxCapacity(my_vect));
	INT_freeVector(my_vect);

  return 0;
}
