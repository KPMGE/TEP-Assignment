#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/complex.h"

#define TYPE long int

struct complex {
  TYPE *real;
  TYPE *imag;
};

Complex_t* createComplexNumber(TYPE real, TYPE imag) {
  Complex_t *allocatedComplex = (Complex_t *) malloc(sizeof(Complex_t));

  if (allocatedComplex == NULL) {
    printf("Insuficient Space!");
    exit(1);
  }

  allocatedComplex->real = (TYPE *) malloc(sizeof(TYPE));
  allocatedComplex->imag = (TYPE *) malloc(sizeof(TYPE));

  *(allocatedComplex)->real = real;
  *(allocatedComplex)->imag = imag;

  return allocatedComplex;
}


// get/set values into a complex number
TYPE getRealPart(Complex_t *num) {
  return *(num)->real;
}

TYPE getImaginaryPart(Complex_t *num) {
  return *(num)->imag;
}

double getModuleComplexNumber(Complex_t* num) {
  return sqrt(pow(getRealPart(num), 2) + pow(getImaginaryPart(num), 2));
}

double getAngleComplexNumber(Complex_t* num) {
  double module = getModuleComplexNumber(num);

  return acos(getRealPart(num) / module);
}

void setValueToRealPart(Complex_t* num, double value) {
  *(num)->real = value;
}

void setValueToImaginaryPart(Complex_t* num, double value) {
  *(num)->imag = value;
}

void setModuleComplex(Complex_t* num) {
  // we need to adjust angle!
  // we need to implement it
} 

void setAngleComplex(Complex_t* num) {
  // we need to adjust module!
  // we need to implement it
}

void assignComplexNumberTo(Complex_t* num) {
  // we need to implement it
}

void copyComplexNumberTo(Complex_t* num) {
  // we need to implement it
}


// comparison
int isModuleZero(Complex_t* num) {
  // we need to implement it
}

int isOnlyRealNumber(Complex_t* num) {
  // we need to implement it
}
int isOnlyImaginaryNumber(Complex_t* num) {
  // we need to implement it
}

int compareComplex(Complex_t* num1, Complex_t* num2) {
  // we need to implement it
}

void freeComplexNumber(Complex_t* num) {
  free(num->real);
  free(num->imag);
  free(num);
}

void displayComplexNumber(Complex_t* num) {
  printf("real: %ld\n", getRealPart(num));
  printf("imag: %ld\n", getImaginaryPart(num));
}
