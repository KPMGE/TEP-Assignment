#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/rational-numbers.h"
#include "../include/complex-int.h"
#include "../include/complex-double.h"

int main(void) {
  // implementation with long int
  printf("Implementation with int type:\n\n");
  INT_Complex_t* num = INT_createComplexNumber(8, 4);
  INT_Complex_t* numTest = INT_createComplexNumber(1, 4);
  
  printf("num1:\n");
  INT_displayComplexNumber(num);
  printf("num2:\n");
  INT_displayComplexNumber(numTest);
  
  // testing compare function
  if (INT_compareComplex(num, numTest) == 0) {
    printf("the numbers are the same!");
  } else if (INT_compareComplex(num, numTest) == 1) {
    printf("the number 1 is greater than number 2");
  } else {
    printf("the number 2 is greater than number 1");
  }

  // setting new values
  INT_setValueToRealPart(num, sqrt(3));
  INT_setValueToImaginaryPart(num, 1);

  printf("\nUpdated number:\n");
  INT_displayComplexNumber(num);

  printf("\nmodule: %.3lf\n", INT_getModuleComplexNumber(num));
  printf("angle: %.3lf\n", INT_getAngleComplexNumber(num));


  // release allocated number
  INT_freeComplexNumber(num);


  // implementation with double
  printf("\n\nImplementation with double type:\n\n");
  DOUBLE_Complex_t* num2 = DOUBLE_createComplexNumber(1, 4);

  DOUBLE_displayComplexNumber(num2);

  DOUBLE_setValueToRealPart(num2, sqrt(3));
  DOUBLE_setValueToImaginaryPart(num2, 1);

  printf("\nUpdated number:\n");
  DOUBLE_displayComplexNumber(num2);

  printf("\nmodule: %.3lf\n", DOUBLE_getModuleComplexNumber(num2));
  printf("angle: %.3lf\n", DOUBLE_getAngleComplexNumber(num2));

  DOUBLE_freeComplexNumber(num2);

  return 0;
}
