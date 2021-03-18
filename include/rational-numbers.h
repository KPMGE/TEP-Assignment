#ifndef RATIONAL_NUMBERS_H_INCLUDED
#define RATIONAL_NUMBERS_H_INCLUDED

typedef struct rational Rational_t;

Rational_t* createRationalNumber(int num, int den);

int getNumerator(Rational_t *num);
int getDenominator(Rational_t *num);
void setNumerator(Rational_t *num, int value);
void setDenominator(Rational_t *num, int value);

void freeRationalNumber(Rational_t *num);
void copyRationalNumbers(Rational_t *num1, Rational_t *num2);
int compareRationalNumbers(Rational_t*num1, Rational_t *num2);
int isEquivalent(Rational_t *num1, Rational_t *num2);
int isZeroDenominator(Rational_t *num);
int isZeroNumerator(Rational_t *num);
int isZeroOverZero(Rational_t *num);
Rational_t* sumRationalNumbers(Rational_t *num1, Rational_t *num2);
void accumulateRationalNumbers(Rational_t *num1, Rational_t *num2);
Rational_t* subtractRationalNumbers(Rational_t *num1, Rational_t *num2);
Rational_t* multiplyRationalNumbers(Rational_t *num1, Rational_t *num2);
void multiplyRationalInside(Rational_t *num1, Rational_t *num2);
Rational_t* divideRationalNumbers(Rational_t *num1, Rational_t *num2);
Rational_t* powRationalNumber(Rational_t *num, float power);
double squareRootRationalNumber(Rational_t *num);
double convertRationalToDouble(Rational_t *num);
Rational_t* convertDoubleToRational(double num);
int canBeConvertedToInt(Rational_t *num);
void writeRationalNumberInCsv(Rational_t *num, FILE *file);
//Rational_t* readRationalNumberFromCsv(FILE *file);

void displayRational(Rational_t *num);

#endif