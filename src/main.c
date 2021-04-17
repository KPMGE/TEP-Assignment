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


int main(void) {
  DOUBLE_Complex_t* num = DOUBLE_createComplexNumber(2.2, 3.1);
  DOUBLE_Complex_t* num2 = DOUBLE_createComplexNumber(5.5, 9.1);
  DOUBLE_Complex_t* num3 = DOUBLE_createComplexNumber(34.7, 23.32);


  DOUBLE_VECT_VectComplex_t* vectTest = DOUBLE_VECT_createVector(10, 0);
  DOUBLE_VECT_insertIndexPosValue(vectTest, num, 0);
  DOUBLE_VECT_insertIndexPosValue(vectTest, num2, 1);
  DOUBLE_VECT_insertLastPosValue(vectTest, num3);
  DOUBLE_VECT_insertLastPosValue(vectTest, num);

  printf("--------- ORIGINAL VECTOR ---------\n");
  DOUBLE_VECT_displayVector(vectTest);

  printf("\n--------- GREATEST MODULE ---------\n");
  DOUBLE_Complex_t* greatest = DOUBLE_VECT_getHigherAbs(vectTest);
  DOUBLE_displayComplexNumber(greatest);

  printf("\n\n--------- SMALLEST MODULE ---------\n");
  DOUBLE_Complex_t* smallest = DOUBLE_VECT_getLowerAbs(vectTest);
  DOUBLE_displayComplexNumber(smallest);


  printf("\n\n--------- AMOUNT EQUALS ---------\n");
  printf("equals: %d", DOUBLE_VECT_countEquals(vectTest, num));
  
  printf("\n\n--------- POSITION 0 DELETED ---------\n");
  DOUBLE_VECT_deletePosition(vectTest, 0);
  DOUBLE_VECT_displayVector(vectTest);

  printf("\n--------- CLEARED VECTOR ---------\n");
  DOUBLE_VECT_clearAllVector(vectTest); 
  DOUBLE_VECT_displayVector(vectTest);


  DOUBLE_freeComplexNumber(num);
  DOUBLE_freeComplexNumber(num2);
  DOUBLE_freeComplexNumber(num3);
  DOUBLE_VECT_freeVector(vectTest);


  
 // create a vector
  return 0;
}
