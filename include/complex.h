#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#define TYPE long int

typedef struct complex Complex_t;

Complex_t* createComplexNumber(TYPE real, TYPE imag);
void freeComplexNumber(Complex_t* num);
void displayComplexNumber(Complex_t* num);
void assignComplexNumberTo(Complex_t* num);
void copyComplexNumberTo(Complex_t* num);

// we need to create functions to perform conversions

// get/set values into a complex number
TYPE getRealPart(Complex_t* num);
TYPE getImaginaryPart(Complex_t* num);
double getModuleComplexNumber(Complex_t* num);
double getAngleComplexNumber(Complex_t* num);
void setValueToRealPart(Complex_t* num, double value);
void setValueToImaginaryPart(Complex_t* num, double value);
void setModuleComplex(Complex_t* num); // we need to adjust angle!
void setAngleComplex(Complex_t* num); // we need to adjust module!

// comparison
int isModuleZero(Complex_t* num);
int isOnlyRealNumber(Complex_t* num);
int isOnlyImaginaryNumber(Complex_t* num);
int compareComplex(Complex_t* num1, Complex_t* num2);

#endif
