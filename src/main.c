#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/rational-numbers.h"
#include "../include/complex-int.h"
#include "../include/complex-double.h"

int main(void) {
  // implementation with long int
  printf("Implementation with int type:\n\n");
  INT_Complex_t* num = INT_createComplexNumber(1, 4);

  INT_displayComplexNumber(num);

  INT_setValueToRealPart(num, sqrt(3));
  INT_setValueToImaginaryPart(num, 1);

  printf("\nUpdated number:\n");
  INT_displayComplexNumber(num);

  printf("\nmodule: %.3lf\n", INT_getModuleComplexNumber(num));
  printf("angle: %.3lf\n", INT_getAngleComplexNumber(num));

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
