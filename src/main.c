#include <stdio.h>
#include <stdlib.h>
#include "../include/rational-numbers.h"
#include "../include/complex.h"

int main(void) {
  Complex_t *num = createComplexNumber(1, 4);

  displayComplexNumber(num);

  freeComplexNumber(num);

  return 0;
}
