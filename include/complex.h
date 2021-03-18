#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#define TYPE long int

typedef struct complex Complex_t;

Complex_t* createComplexNumber(TYPE real, TYPE imag);
TYPE getRealPart(Complex_t *num);
TYPE getImaginaryPart(Complex_t *num);
void freeComplexNumber(Complex_t* num);
void displayComplexNumber(Complex_t* num);

#endif
