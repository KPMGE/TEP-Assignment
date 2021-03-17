#include <stdio.h>
#include <stdlib.h>
#include "../include/rational-numbers.h"

int main(void) {
  Rational_t *num1 = createRationalNumber(5, 2);
  Rational_t *num2 = createRationalNumber(6, 3);
  Rational_t *sum = sumRationalNumbers(num1, num2);

  printf("num1: %d, %d\n", getNumerator(num1), getDenominator(num1));
  printf("num1: %d, %d\n", getNumerator(num2), getDenominator(num2));
  printf("sum: %d, %d\n", getNumerator(sum), getDenominator(sum));

  freeRationalNumber(num1);
  freeRationalNumber(num2);
  freeRationalNumber(sum);

  return 0;
}