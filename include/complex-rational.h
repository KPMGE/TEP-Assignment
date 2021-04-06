#include "rational-numbers.h"
#define TYPE Rational_t
#define RATIONAL_INCLUDED
#define TYPED(SOMETHING) RATIONAL_ ## SOMETHING

typedef struct TYPED(complex) TYPED(Complex_t);

TYPED(Complex_t*) TYPED(createComplexNumber)(TYPE* real, TYPE* imag);
void TYPED(displayComplexNumber)(TYPED(Complex_t*) num);
void TYPED(freeComplexNumber)(TYPED(Complex_t*) num);
TYPE* TYPED(getRealPart)(TYPED(Complex_t*) num);
TYPE* TYPED(getImaginaryPart)(TYPED(Complex_t*) num);
void TYPED(setValueToRealPart)(TYPED(Complex_t*), TYPE* value);
void TYPED(setValueToImaginaryPart)(TYPED(Complex_t*), TYPE* value);
void TYPED(setModuleComplexNumber)(TYPED(Complex_t*) num, double module);
void TYPED(setAngleComplexNumber)(TYPED(Complex_t*) num, double angle);
void TYPED(accumulateComplexSum)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);

TYPED(Complex_t*) TYPED(evaluateComplexOperation)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2, char *op);


double TYPED(getModuleComplexNumber)(TYPED(Complex_t*) num);
double TYPED(getAngleComplexNumber)(TYPED(Complex_t*) num);
void TYPED(assignComplexNumberTo)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(copyComplexNumberTo)(TYPED(Complex_t*) num);

int TYPED(isModuleZero)(TYPED(Complex_t*) num);
int TYPED(isOnlyRealNumber)(TYPED(Complex_t*) num);
int TYPED(isOnlyImaginaryNumber)(TYPED(Complex_t*) num);
int TYPED(compareComplex)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(calculateConjugateComplex)(TYPED(Complex_t*) num);
TYPED(Complex_t*) TYPED(sumComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(subtractComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(multiplyComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(divideComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);

// conversions
TYPED(Complex_t*) TYPED(convertIntoComplexRational)(double real, double imag);