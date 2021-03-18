#include <stdio.h>
#include <stdlib.h>
#include "../include/rational-numbers.h"

int main(void) {
  FILE *myFile = fopen("testFile.csv", "w");

  Rational_t *num1 = createRationalNumber(1, 4);
  Rational_t *num2 = createRationalNumber(4, 5);
  Rational_t *sum = sumRationalNumbers(num1, num2);

  for (int i = 0; i < 10; i++) {
    writeRationalNumberInCsv(sum, myFile);
  }

  freeRationalNumber(num1);
  freeRationalNumber(num2);
  freeRationalNumber(sum);

  return 0;
}