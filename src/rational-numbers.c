#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "../include/rational-numbers.h"

#define FALSE 0
#define TRUE 1
#define EPSILON 0.00001 

struct rational {
  int numerator;
  int denominator;
};

Rational_t* createRationalNumber(int num, int den) {
  Rational_t *allocatedRational = (Rational_t *) malloc(sizeof(Rational_t));

  if (allocatedRational == NULL) {
    printf("Insuficient space!");
    exit(1);
  }

  allocatedRational->numerator = num;
  allocatedRational->denominator = den;

  // check if denominator is zero
  if (isZeroDenominator(allocatedRational)) {
    printf("Your number doesn't exist! k/0!");
    exit(1);
  } 

  // simplify allocated number
  simplifyRationalNumber(allocatedRational);

  return allocatedRational;
}


int getNumerator(Rational_t *num) {
  return num->numerator;
}

int getDenominator(Rational_t *num) {
  return num->denominator;
}

void setNumerator(Rational_t *num, int value) {
  num->numerator = value;
}

void setDenominator(Rational_t *num, int value) {
  num->denominator = value;
}

void freeRationalNumber(Rational_t *num) {
  free(num);
}

void copyRationalNumbers(Rational_t *num1, Rational_t *num2) {
  setNumerator(num1, getNumerator(num2));
  setDenominator(num1, getDenominator(num2));
}

int compareRationalNumbers(Rational_t *num1, Rational_t *num2) {
  double doubleNum1 = convertRationalToDouble(num1);
  double doubleNum2 = convertRationalToDouble(num2);

  if (doubleNum1 == doubleNum2) {
    return 0;
  } else if (doubleNum1 < doubleNum2) {
    return -1;
  } else {
    return 1;
  }
}

int isEquivalent(Rational_t *num1, Rational_t *num2) {
  return (abs(convertRationalToDouble(num1) - convertRationalToDouble(num2)) < EPSILON) ? TRUE : FALSE;
}

int isZeroNumerator(Rational_t *num) {
  return (getNumerator(num) == 0) ? TRUE : FALSE;
}

int isZeroDenominator(Rational_t *num) {
  return (getDenominator(num) == 0) ? TRUE : FALSE;
}

int isZeroOverZero(Rational_t *num) {
  return (isZeroNumerator(num) && isZeroDenominator(num)) ? TRUE : FALSE;
}

int greatestCommonDivisorRecursive(int num, int den) {
  if (den == 0) {
    return num;
  } else {
    return greatestCommonDivisorRecursive(den, num % den);
  }
}

int greatestCommonDivisorIterative(int num, int den) {
  int remainder;

  while (den != 0) {
    remainder = num % den;
    num = den;
    den = remainder;
  }
  return num;
}

void simplifyRationalNumber(Rational_t* num) {
  // get numerator and denominator from num
  int numerator = getNumerator(num); 
  int denominator = getDenominator(num);
  // get greatest commonn divisor 
  int mdc = greatestCommonDivisorIterative(numerator, denominator);

  // simplify fraction
  numerator /= mdc;
  denominator /= mdc;

  // change num fraction
  setNumerator(num, numerator);
  setDenominator(num, denominator);
}

Rational_t* sumRationalNumbers(Rational_t *num1, Rational_t *num2) {
  int sumNumerator = (getNumerator(num1) * getDenominator(num2)) + (getDenominator(num1) * getNumerator(num2));
  int sumDenominator = getDenominator(num1) * getDenominator(num2);

  Rational_t *sum = createRationalNumber(sumNumerator, sumDenominator);

  // simplify  number
  simplifyRationalNumber(sum);

  return sum;
}

void accumulateRationalNumbers(Rational_t *num1, Rational_t *num2) {
  Rational_t* sum = sumRationalNumbers(num1, num2);
  
  setNumerator(num1, getNumerator(sum));
  setDenominator(num1, getDenominator(sum));

  freeRationalNumber(sum);
}

Rational_t* subtractRationalNumbers(Rational_t *num1, Rational_t *num2) {
  int subNumerator = (getNumerator(num1) * getDenominator(num2)) - (getDenominator(num1) * getNumerator(num2));
  int subDenominator = getDenominator(num1) * getDenominator(num2);

  Rational_t *sub = createRationalNumber(subNumerator, subDenominator);

  // simplify  number
  simplifyRationalNumber(sub);

  return sub;
}

Rational_t* multiplyRationalNumbers(Rational_t *num1, Rational_t *num2) {
  int multiNumerator = getNumerator(num1) * getNumerator(num2);
  int multiDenominator = getDenominator(num1) * getDenominator(num2);

  Rational_t *multi = createRationalNumber(multiNumerator, multiDenominator);

  // simplify  number
  simplifyRationalNumber(multi);

  return multi;
}

void multiplyRationalInside(Rational_t *num1, Rational_t *num2) {
  int multiNumerator = getNumerator(num1) * getNumerator(num2);
  int multiDenominator = getDenominator(num1) * getDenominator(num2);

  setNumerator(num1, multiNumerator);
  setDenominator(num1, multiDenominator);
}

Rational_t* divideRationalNumbers(Rational_t *num1, Rational_t *num2) {
  // if numerator of our num2 is 0, we cannot do the following operation
  if (isZeroNumerator(num2)) {
    printf("Impossible do this operation!");
    exit(1);
  }

  // calculate numerator and denominator
  int divNumerator = getNumerator(num1) * getDenominator(num2);
  int divDenominator = getDenominator(num1) * getNumerator(num2);

  // create rational number
  Rational_t *div = createRationalNumber(divNumerator, divDenominator);

  // simplify  number
  simplifyRationalNumber(div);

  return div;
}

Rational_t* powRationalNumber(Rational_t *num, float power) {
  // calculate numetor and operator
  int powNumerator = pow(getNumerator(num), power);
  int powDenominator = pow(getDenominator(num), power);

  // create rational number fro outcome
  Rational_t *powNum = createRationalNumber(powNumerator, powDenominator);

  return powNum;
}

Rational_t* squareRootRationalNumber(Rational_t *num) {
  double xn = 1; // initial approximation
  double previous = 0; // value of previous approximation
  double number = convertRationalToDouble(num); // convert rational number into double one

  while (TRUE) {
    previous = xn; // previous approximation 
    xn = xn - (pow(xn, 2) - number) / (2 * xn); // calculate nª aproximation

    // if difference between numbers is less than EPSILON
    if (fabs(previous - xn) < EPSILON) {
      break;
    }
  }

  // convert square root into a rational number again
  Rational_t* root = convertDoubleToRational(xn);

  // simplify number
  //simplifyRationalNumber(root);

  return root;
}

double convertRationalToDouble(Rational_t *num) {
  return getNumerator(num) / (double)getDenominator(num);
}

Rational_t* convertDoubleToRational(double num) {
	/* continued fraction and check denominator each step */
	int64_t a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 };
	int64_t x, d, n = 1, md = 10000;
	int neg = 0;

  if (num < 0) { neg = 1; num = -num; }
 
	while (num != floor(num)) { n <<= 1; num *= 2; }
	d = num;

	for (int i = 0; i < 64; i++) {
		a = n ? d / n : 0;
		if (i && !a) break;
 
		x = d; d = n; n = x % n;
 
		x = a;
		if (k[1] * a + k[0] >= md) {
			x = (md - k[0]) / k[1];
			if (x * 2 >= a || k[1] >= md)
				i = 65;
			else
				break;
		}
 
		h[2] = x * h[1] + h[0]; h[0] = h[1]; h[1] = h[2];
		k[2] = x * k[1] + k[0]; k[0] = k[1]; k[1] = k[2];
	}

	int64_t denominator = k[1];
	int64_t numerator = neg ? -h[1] : h[1];

  Rational_t* converted = createRationalNumber(numerator, denominator);
  return converted;
}

int canBeConvertedToInt(Rational_t *num) {
  double number = convertRationalToDouble(num);
  int intPart = number;

  return ((number - intPart) < EPSILON) ? TRUE : FALSE;
}

void writeRationalNumberInCsv(Rational_t *num, FILE *file) {
  fprintf(file, "%d/%d,", getNumerator(num), getDenominator(num));
}

Rational_t* readRationalNumberFromCsv(FILE *file) {
  // we need to implement it
}

void displayRationalNumber(Rational_t *num) {
  printf("%d/%d", getNumerator(num), getDenominator(num));
}

Rational_t* findRationalBetween(double num1, double num2) {
  double aprox = 0;

  for (float i = 0 ;; i += 0.995) {
    aprox += 1.0/pow(16, i) * ((4.0 / (8*i + 1)) - (2.0/(8*i + 4)) - (1.0/(8*i + 5)) - (1.0/(8*i + 6)));

    if (aprox > num1 && aprox < num2) {
      break;
    }

    if (i > 100000) {
      printf("infinity loop!");
      exit(1);
    }
  }

  return convertDoubleToRational(aprox);
}
