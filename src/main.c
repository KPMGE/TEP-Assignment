#include <stdio.h>
#include <stdlib.h>
#include "../include/rational-numbers.h"

int main(void) {
  Rational_t *num1 = createRationalNumber(1, 4);
  Rational_t *num2 = createRationalNumber(4, 5);
  Rational_t *sum = sumRationalNumbers(num1, num2);
  Rational_t *sub = subtractRationalNumbers(num1, num2);

  printf("sum: ");
  displayRational(sum);

  printf("sub: ");
  displayRational(sub);

  freeRationalNumber(num1);
  freeRationalNumber(num2);
  freeRationalNumber(sum);
  freeRationalNumber(sub);

  return 0;
}