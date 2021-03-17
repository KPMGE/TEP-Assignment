#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/rational-numbers.h"

#define FALSE 0
#define TRUE 1
#define EPSILON 0.002 

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

int compareRationalNumbers(Rational_t*num1, Rational_t *num2) {
  return ((getNumerator(num1) == getNumerator(num2)) && (getDenominator(num1) == getDenominator(num2))) ? TRUE : FALSE;
}

int isEquivalent(Rational_t *num1, Rational_t *num2) {
  return (abs(convertRationalToDouble(num1) - convertRationalToDouble(num2)) < EPSILON) ? TRUE : FALSE;
}

int isZeroDenominator(Rational_t *num) {
  return (getDenominator(num) == 0) ? TRUE : FALSE;
}

int isZeroNumerator(Rational_t *num) {
  return (getNumerator(num) == 0) ? TRUE : FALSE;
}

int isZeroOverZero(Rational_t *num) {
  return (isZeroNumerator(num) && isZeroDenominator(num)) ? TRUE : FALSE;
}

Rational_t* sumRationalNumbers(Rational_t *num1, Rational_t *num2) {
  int sumNumerator = getNumerator(num1) + getNumerator(num2);
  int sumDenominator = getDenominator(num1) + getDenominator(num2);

  Rational_t *sum = createRationalNumber(sumNumerator, sumDenominator);

  return sum;
}

void accumulateRationalNumbers(Rational_t *num1, Rational_t *num2) {
  int sumNumerator = getNumerator(num1) + getNumerator(num2);
  int sumDenominator = getDenominator(num1) + getDenominator(num2);
  
  setNumerator(num1, sumNumerator);
  setDenominator(num1, sumDenominator);
}

Rational_t* subtractRationalNumbers(Rational_t *num1, Rational_t *num2) {
  int subNumerator = getNumerator(num1) - getNumerator(num2);
  int subDenominator = getDenominator(num1) - getDenominator(num2);

  Rational_t *sub = createRationalNumber(subNumerator, subDenominator);

  return sub;
}

Rational_t* multiplyRationalNumbers(Rational_t *num1, Rational_t *num2) {
  int multiNumerator = getNumerator(num1) * getNumerator(num2);
  int multiDenominator = getDenominator(num1) * getDenominator(num2);

  Rational_t *multi = createRationalNumber(multiNumerator, multiDenominator);

  return multi;
}

void multiplyRationalInside(Rational_t *num1, Rational_t *num2) {
  int multiNumerator = getNumerator(num1) * getNumerator(num2);
  int multiDenominator = getDenominator(num1) * getDenominator(num2);

  setNumerator(num1, multiNumerator);
  setDenominator(num1, multiDenominator);
}

Rational_t* divideRationalNumbers(Rational_t *num1, Rational_t *num2) {
  int divNumerator = getNumerator(num1) * getDenominator(num2);
  int divDenominator = getDenominator(num1) * getNumerator(num1);

  Rational_t *div = createRationalNumber(divNumerator, divDenominator);

  return div;
}

Rational_t* powRationalNumber(Rational_t *num, float power) {
  int powNumerator = pow(getNumerator(num), power);
  int powDenominator = pow(getDenominator(num), power);

  Rational_t *powNum = createRationalNumber(powNumerator, powDenominator);

  return powNum;
}

Rational_t* squareRootRationalNumber(Rational_t *num1, float power) {
}

double convertRationalToDouble(Rational_t *num) {
  return getNumerator(num) / (double)getDenominator(num);
}

Rational_t* conbertDoubleToRational(double num) {

}

int canBeConvertedToInt(Rational_t *num) {
  return (convertRationalToDouble(num) < EPSILON) ? TRUE : FALSE;
}

void writeRationalNumberInCsv(Rational_t *num, FILE *file) {

}

Rational_t* readRationalNumberFromCsv(FILE *file) {

}