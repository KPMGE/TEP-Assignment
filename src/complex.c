#ifdef TYPE_NAME
#ifdef DATA_TYPE
#ifdef IO_FORMAT
// define tolerance
#define EPSILON 0.00001
#define EPSILON2 0.0001

// define boolean types
#define TRUE 1
#define FALSE 0

// main struct
struct TYPE_NAME(complex) {
  DATA_TYPE *real;
  DATA_TYPE *imag;
};

// function that allocates a complex number and returs it
TYPE_NAME(Complex_t*) TYPE_NAME(createComplexNumber)(DATA_TYPE real, DATA_TYPE imag) {
  TYPE_NAME(Complex_t) *allocatedComplex = (TYPE_NAME(Complex_t*)) malloc(sizeof(TYPE_NAME(Complex_t)));

  if (allocatedComplex == NULL) {
    printf("Insuficient Space!");
    exit(1);
  }

  allocatedComplex->real = (DATA_TYPE *) malloc(sizeof(DATA_TYPE));
  allocatedComplex->imag = (DATA_TYPE *) malloc(sizeof(DATA_TYPE));

  *(allocatedComplex)->real = real;
  *(allocatedComplex)->imag = imag;

  return allocatedComplex;
}


// get real part of a complex number
DATA_TYPE TYPE_NAME(getRealPart)(TYPE_NAME(Complex_t*) num) {
  return *(num)->real;
}

// get imaginary part of a complex number
DATA_TYPE TYPE_NAME(getImaginaryPart)(TYPE_NAME(Complex_t*) num) {
  return *(num)->imag;
}

// get module of a complex number
double TYPE_NAME(getModuleComplexNumber)(TYPE_NAME(Complex_t*) num) {
  return sqrt(pow(TYPE_NAME(getRealPart)(num), 2) + pow(TYPE_NAME(getImaginaryPart)(num), 2));
}

// get angle of a complex number
double TYPE_NAME(getAngleComplexNumber)(TYPE_NAME(Complex_t*) num) {
  double module = TYPE_NAME(getModuleComplexNumber)(num);

  return acos(TYPE_NAME(getRealPart)(num) / module);
}

// set new value to real part of a complex number
void TYPE_NAME(setValueToRealPart)(TYPE_NAME(Complex_t*) num, double value) {
  *(num)->real = value;
}

// set new value to imaginary part of a complex number
void TYPE_NAME(setValueToImaginaryPart)(TYPE_NAME(Complex_t*) num, double value) {
  *(num)->imag = value;
}

// set new value to module of a complex number without modify its angle
void TYPE_NAME(setModuleComplexNumber)(TYPE_NAME(Complex_t*) num, double module) {
  double angle = TYPE_NAME(getAngleComplexNumber)(num); // get angle of num

  double a2 = module * cos(angle); // calculate real part
  double b2 = module * sin(angle); // calculate imaginary part

  // set new values to old number
  TYPE_NAME(setValueToRealPart)(num, a2);
  TYPE_NAME(setValueToImaginaryPart)(num, b2);
} 

// set new value to angle of a complex number without modify its module
void TYPE_NAME(setAngleComplexNumber)(TYPE_NAME(Complex_t*) num, double angle) {
  double module = TYPE_NAME(getModuleComplexNumber)(num);
  double a2 = module * cos(angle); // calculate real part
  double b2 = module * sin(angle); // calculate imaginary part

  // set new values to complex number
  TYPE_NAME(setValueToRealPart)(num, a2);
  TYPE_NAME(setValueToImaginaryPart)(num, b2);
}

// assign number2 into number 1
void TYPE_NAME(assignComplexNumberTo)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  TYPE_NAME(setValueToRealPart)(num1, TYPE_NAME(getRealPart)(num2));
  TYPE_NAME(setValueToImaginaryPart)(num1, TYPE_NAME(getImaginaryPart)(num2));
}

// returns an allocated copied complex number
TYPE_NAME(Complex_t*) TYPE_NAME(copyComplexNumberTo)(TYPE_NAME(Complex_t*) num) {
  TYPE_NAME(Complex_t*) copy = TYPE_NAME(createComplexNumber)(TYPE_NAME(getRealPart)(num), TYPE_NAME(getImaginaryPart)(num));
  return copy;
}

// is module 0?
int TYPE_NAME(isModuleZero)(TYPE_NAME(Complex_t*) num) {
  if (TYPE_NAME(getModuleComplexNumber)(num) <= EPSILON) {
    return TRUE;
  } 
  return FALSE;
}

// is only real number?
int TYPE_NAME(isOnlyRealNumber)(TYPE_NAME(Complex_t*) num) {
  if (TYPE_NAME(getImaginaryPart)(num) <= EPSILON) {
    return TRUE;
  } 
  return FALSE;
}

// is only imaginary number?
int TYPE_NAME(isOnlyImaginaryNumber)(TYPE_NAME(Complex_t*) num) {
  if (TYPE_NAME(getRealPart)(num) <= EPSILON) {
    return TRUE;
  }
  return FALSE;
}

// 1 - number1 > number2
// 0 - number1 == number2
// -1 - number1 < number2
int TYPE_NAME(compareComplexModule)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  if (fabs(TYPE_NAME(getModuleComplexNumber)(num1) - TYPE_NAME(getModuleComplexNumber)(num2)) < EPSILON2) {
    return 0;
  }
  else if (TYPE_NAME(getModuleComplexNumber)(num1) > TYPE_NAME(getModuleComplexNumber)(num2)) {
    return 1;
  }
  else {
    return -1;
  }
}

// 1 - number1 > number2
// 0 - number1 == number2
// -1 - number1 < number2
int TYPE_NAME(compareComplexAngle)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  if (fabs(TYPE_NAME(getAngleComplexNumber)(num1) - TYPE_NAME(getAngleComplexNumber)(num2)) < EPSILON2) {
    return 0;
  }
  else if (TYPE_NAME(getAngleComplexNumber)(num1) > TYPE_NAME(getAngleComplexNumber)(num2)) {
    return 1;
  }
  else {
    return -1;
  }
}

// free a complex number
void TYPE_NAME(freeComplexNumber)(TYPE_NAME(Complex_t*) num) {
  if (num != NULL) {
    if (num->real != NULL) {
      free(num->real);
      num->real = NULL;
    }
    if (num->imag != NULL) {
      free(num->imag);
      num->imag = NULL;
    }
    free(num);
    num = NULL;
  }
}

// calculate the conjugate of a complex number
TYPE_NAME(Complex_t*) TYPE_NAME(calculateConjugateComplex)(TYPE_NAME(Complex_t*) num) {
  DATA_TYPE realPart = TYPE_NAME(getRealPart)(num);
  DATA_TYPE imaginaryPart = -(TYPE_NAME(getImaginaryPart)(num)); // * -1
  TYPE_NAME(Complex_t*) conjugate = TYPE_NAME(createComplexNumber)(realPart, imaginaryPart);

  return conjugate;
}

// sum operation
TYPE_NAME(Complex_t*) TYPE_NAME(sumComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate real part sum
  DATA_TYPE sumReal = TYPE_NAME(getRealPart)(num1) + TYPE_NAME(getRealPart)(num2);
  // calculate imaginary part sum
  DATA_TYPE sumImaginary = TYPE_NAME(getImaginaryPart)(num1) + TYPE_NAME(getImaginaryPart)(num2);
  // create allocated sum num
  TYPE_NAME(Complex_t*) sum = TYPE_NAME(createComplexNumber)(sumReal, sumImaginary);
  // return it
  return sum;
}

// subtraction operation
TYPE_NAME(Complex_t*) TYPE_NAME(subtractComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate real part sum
  DATA_TYPE subReal = TYPE_NAME(getRealPart)(num1) - TYPE_NAME(getRealPart)(num2);
  // calculate imaginary part sum
  DATA_TYPE subImaginary = TYPE_NAME(getImaginaryPart)(num1) - TYPE_NAME(getImaginaryPart)(num2);
  // create allocated subtract num
  TYPE_NAME(Complex_t*) sub = TYPE_NAME(createComplexNumber)(subReal, subImaginary);
  // return it
  return sub;
}

// multiplication operation
TYPE_NAME(Complex_t*) TYPE_NAME(multiplyComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate real part sum
  DATA_TYPE multiReal = TYPE_NAME(getRealPart)(num1) * TYPE_NAME(getRealPart)(num2) - TYPE_NAME(getImaginaryPart)(num1) * TYPE_NAME(getImaginaryPart)(num2);
  // calculate imaginary part sum
  DATA_TYPE multiImaginary = TYPE_NAME(getRealPart)(num1) * TYPE_NAME(getImaginaryPart)(num2) + TYPE_NAME(getImaginaryPart)(num1) * TYPE_NAME(getRealPart)(num2);
  
  // create allocated multi num
  TYPE_NAME(Complex_t*) multi = TYPE_NAME(createComplexNumber)(multiReal, multiImaginary);
  // return it
  return multi;
}

// division operation
TYPE_NAME(Complex_t*) TYPE_NAME(divideComplexNumbers)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate denominator
  DATA_TYPE denominator = pow(TYPE_NAME(getRealPart)(num2), 2) + pow(TYPE_NAME(getImaginaryPart)(num2), 2);
  // calculate real part
  DATA_TYPE divRealPart = (TYPE_NAME(getRealPart)(num1) * TYPE_NAME(getRealPart)(num2) + TYPE_NAME(getImaginaryPart)(num1) * TYPE_NAME(getImaginaryPart)(num2)) / denominator;
  // calculate imaginary part
  DATA_TYPE divImaginaryPart = (TYPE_NAME(getRealPart)(num2) * TYPE_NAME(getImaginaryPart)(num1) - TYPE_NAME(getRealPart)(num1) * TYPE_NAME(getImaginaryPart)(num2)) / denominator;

  // create allocated div num
  TYPE_NAME(Complex_t*) div = TYPE_NAME(createComplexNumber)(divRealPart, divImaginaryPart);
  // return it
  return div;
}

// accumulate num2 into num1 with a sum operation
void TYPE_NAME(accumulateComplexSum)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate sum
  TYPE_NAME(Complex_t*) sumNum = TYPE_NAME(sumComplexNumbers)(num1, num2);

  // set values to number 1
  TYPE_NAME(setValueToRealPart)(num1, TYPE_NAME(getRealPart)(sumNum));
  TYPE_NAME(setValueToImaginaryPart)(num1, TYPE_NAME(getImaginaryPart)(sumNum));

  // free allocated num
  TYPE_NAME(freeComplexNumber)(sumNum);
}

// accumulate num2 into num1 with a multiplication operation
void TYPE_NAME(accumulateComplexMulti)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2) {
  // calculate sum
  TYPE_NAME(Complex_t*) multiNum = TYPE_NAME(multiplyComplexNumbers)(num1, num2);

  // set values to number 1
  TYPE_NAME(setValueToRealPart)(num1, TYPE_NAME(getRealPart)(multiNum));
  TYPE_NAME(setValueToImaginaryPart)(num1, TYPE_NAME(getImaginaryPart)(multiNum));

  // free allocated num
  TYPE_NAME(freeComplexNumber)(multiNum);
}

// function to evaluate operation
TYPE_NAME(Complex_t*) TYPE_NAME(evaluateComplexOperation)(TYPE_NAME(Complex_t*) num1, TYPE_NAME(Complex_t*) num2, char *op) {
  if (!strcmp(op, "+")) {
    return TYPE_NAME(sumComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "-")) {
    return TYPE_NAME(subtractComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "*")) {
    return TYPE_NAME(multiplyComplexNumbers)(num1, num2);
  } else if(!strcmp(op, "/")) {
    return TYPE_NAME(divideComplexNumbers)(num1, num2);
  } else if (!strcmp(op, "+=")) {
    TYPE_NAME(accumulateComplexSum)(num1, num2);
  } else if (!strcmp(op, "*=")) {
    TYPE_NAME(accumulateComplexMulti)(num1, num2);
  }
}

// display complex number
void TYPE_NAME(displayComplexNumber)(TYPE_NAME(Complex_t*) num) {
  DATA_TYPE imaginary = TYPE_NAME(getImaginaryPart)(num); 
  printf(IO_FORMAT, TYPE_NAME(getRealPart)(num));

  if (imaginary >= 0) {
    printf("+ ");
  }

  printf(IO_FORMAT, imaginary);
  printf("i");
}

#endif
#endif
#endif
