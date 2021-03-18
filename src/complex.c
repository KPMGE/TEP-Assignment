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

  *(allocatedComplex)->real = real;
  *(allocatedComplex)->imag = imag;

  return allocatedComplex;
}

TYPE getRealPart(Complex_t *num) {
  return *(num)->real;
}

TYPE getImaginaryPart(Complex_t *num) {
  return *(num)->imag;
}

void freeComplexNumber(Complex_t* num) {
  free(num);
}

void displayComplexNumber(Complex_t* num) {
  printf("real: %ld\n", getRealPart(num));
  printf("imag: %ld", getImaginaryPart(num));
}
