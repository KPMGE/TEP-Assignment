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


  DOUBLE_VECT_VectComplex_t* test = DOUBLE_VECT_createVector(10, 0);
  DOUBLE_VECT_insertIndexPosValue(test, num, 0);
  DOUBLE_VECT_insertIndexPosValue(test, num2, 1);
  DOUBLE_VECT_insertLastPosValue(test, num3);

  printf("--------- ORIGINAL VECTOR ---------\n");
  DOUBLE_VECT_displayVector(test);

  printf("\n--------- POSITION 0 DELETED ---------\n");
  DOUBLE_VECT_deletePosition(test, 0);
  DOUBLE_VECT_displayVector(test);


  DOUBLE_freeComplexNumber(num);
  DOUBLE_freeComplexNumber(num2);
  DOUBLE_freeComplexNumber(num3);
  DOUBLE_VECT_freeVector(test);


  
 // create a vector
  return 0;
}
