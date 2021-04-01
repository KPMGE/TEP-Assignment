#ifndef RATIONAL_NUMBERS_H_INCLUDED
#define RATIONAL_NUMBERS_H_INCLUDED

// creating a Rational_t type
typedef struct rational Rational_t;

// create a rational number
Rational_t* createRationalNumber(int num, int den);
// get numerator of a rational number
int getNumerator(Rational_t *num);
// get denominator of a rational number
int getDenominator(Rational_t *num);
// set a new value to numerator
void setNumerator(Rational_t *num, int value);
// set a new value to denominator
void setDenominator(Rational_t *num, int value);
// free a rational number
void freeRationalNumber(Rational_t *num);
// copy a rational to another
void copyRationalNumbers(Rational_t *num1, Rational_t *num2);
// compare two rationals
int compareRationalNumbers(Rational_t*num1, Rational_t *num2);
// verify if two rationals are equivalent
int isEquivalent(Rational_t *num1, Rational_t *num2);
// verify is denominator is 0
int isZeroDenominator(Rational_t *num);
// verify is numerator is 0
int isZeroNumerator(Rational_t *num);
// verify if rational number is 0/0
int isZeroOverZero(Rational_t *num);
// get greatest common divisor recursively
int greatestCommonDivisorRecursive(int num, int den);
// get greatest common divisor iteratively
int greatestCommonDivisorIterative(int num, int den);
// funcion that simplifies a rational number
void simplifyRationalNumber(Rational_t* num);
// sum two rational numbers and return a third rational
Rational_t* sumRationalNumbers(Rational_t *num1, Rational_t *num2);
// assign the sum of num1 and num2 inside num1
void accumulateRationalNumbers(Rational_t *num1, Rational_t *num2);
// subtract two rational numbers and return a thrird one
Rational_t* subtractRationalNumbers(Rational_t *num1, Rational_t *num2);
// multiply two rational numbers and return a third one
Rational_t* multiplyRationalNumbers(Rational_t *num1, Rational_t *num2);
// multiply two rationals and assign num1 with the outcome
void multiplyRationalInside(Rational_t *num1, Rational_t *num2);
// divide two rational numbers
Rational_t* divideRationalNumbers(Rational_t *num1, Rational_t *num2);
// power two rational numbers
Rational_t* powRationalNumber(Rational_t *num, float power);
// calculate square root of a rational number
Rational_t* squareRootRationalNumber(Rational_t *num);
// convert a rational number to a double
double convertRationalToDouble(Rational_t *num);
// convert a double number to a rational one
Rational_t* convertDoubleToRational(double num);
// verify if a rational number can be converted to integer
int canBeConvertedToInt(Rational_t *num);
// write a rational number into CSV
void writeRationalNumberInCsv(Rational_t *num, FILE *file);
// read a rational number from a CSV
Rational_t* readRationalNumberFromCsv(FILE *file);
// display a rational number
void displayRationalNumber(Rational_t *num);

#endif