#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

typedef struct TYPED(complex) TYPED(Complex_t);

TYPED(Complex_t*) TYPED(createComplexNumber)(TYPE real, TYPE imag);
void TYPED(freeComplexNumber)(TYPED(Complex_t*) num);
void TYPED(displayComplexNumber)(TYPED(Complex_t*) num);
void TYPED(assignComplexNumberTo)(TYPED(Complex_t*) num);
void TYPED(copyComplexNumberTo)(TYPED(Complex_t*) num);

// we need to create functions to perform conversions

// get/set values into a complex number
TYPE TYPED(getRealPart)(TYPED(Complex_t*) num);
TYPE TYPED(getImaginaryPart)(TYPED(Complex_t*) num);
double TYPED(getModuleComplexNumber)(TYPED(Complex_t*) num);
double TYPED(getAngleComplexNumber)(TYPED(Complex_t*) num);
void TYPED(setValueToRealPart)(TYPED(Complex_t*), double value);
void TYPED(setValueToImaginaryPart)(TYPED(Complex_t*) num, double value);
void TYPED(setModuleComplex)(TYPED(Complex_t*) num); // we need to adjust angle!
void TYPED(setAngleComplex)(TYPED(Complex_t*) num); // we need to adjust module!

// comparison
int TYPED(isModuleZero)(TYPED(Complex_t*) num);
int TYPED(isOnlyRealNumber)(TYPED(Complex_t*) num);
int TYPED(isOnlyImaginaryNumber)(TYPED(Complex_t*) num);
int TYPED(compareComplex)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);

// operations
TYPED(Complex_t*) TYPED(calculateConjugateComplex)(TYPED(Complex_t*) num);
TYPED(Complex_t*) TYPED(sumComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(subtractComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(multiplyComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(divideComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(accumulateComplexSum)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);
TYPED(Complex_t*) TYPED(accumulateComplexMulti)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2);


// function to evalue each operation
TYPED(Complex_t*) TYPED(evaluateComplexOperation)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2, char *op);

#endif
