#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/rational-numbers.h"
#include "../include/complex.h"

int main(void) {
  Complex_t *num = createComplexNumber(1, 4);

  displayComplexNumber(num);

  setValueToRealPart(num, sqrt(3));
  setValueToImaginaryPart(num, 1);

  printf("\nUpdated number:\n");
  displayComplexNumber(num);

  printf("\nmodule: %.3lf\n", getModuleComplexNumber(num));
  printf("angle: %.3lf\n", getAngleComplexNumber(num));

  freeComplexNumber(num);

  return 0;
}
