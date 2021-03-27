#ifdef TYPED
#ifdef TYPE
#ifdef FORMAT
#ifndef RATIONAL_INCLUDED
  // define tolerance
  #define EPSILON 0.00001
  #define EPSILON2 0.0001

  // define boolean types
  #define TRUE 1
  #define FALSE 0

  // main struct
  struct TYPED(complex) {
    TYPE *real;
    TYPE *imag;
  };

  // function that allocates a complex number and returs it
  TYPED(Complex_t*) TYPED(createComplexNumber)(TYPE real, TYPE imag) {
    TYPED(Complex_t) *allocatedComplex = (TYPED(Complex_t*)) malloc(sizeof(TYPED(Complex_t)));

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


  // get real part of a complex number
  TYPE TYPED(getRealPart)(TYPED(Complex_t*) num) {
    return *(num)->real;
  }

  // get imaginary part of a complex number
  TYPE TYPED(getImaginaryPart)(TYPED(Complex_t*) num) {
    return *(num)->imag;
  }

  // get module of a complex number
  double TYPED(getModuleComplexNumber)(TYPED(Complex_t*) num) {
    return sqrt(pow(TYPED(getRealPart)(num), 2) + pow(TYPED(getImaginaryPart)(num), 2));
  }

  // get angle of a complex number
  double TYPED(getAngleComplexNumber)(TYPED(Complex_t*) num) {
    double module = TYPED(getModuleComplexNumber)(num);

    return acos(TYPED(getRealPart)(num) / module);
  }

  // set new value to real part of a complex number
  void TYPED(setValueToRealPart)(TYPED(Complex_t*) num, double value) {
    *(num)->real = value;
  }

  // set new value to imaginary part of a complex number
  void TYPED(setValueToImaginaryPart)(TYPED(Complex_t*) num, double value) {
    *(num)->imag = value;
  }

  // set new value to module of a complex number without modify its angle
  void TYPED(setModuleComplex)(TYPED(Complex_t*) num) {
    // we need to adjust angle!
    // we need to implement it
  } 

  // set new value to angle of a complex number without modify its module
  void TYPED(setAngleComplex)(TYPED(Complex_t*) num) {
    // we need to adjust module!
    // we need to implement it
  }

  // assign number2 into number 1
  void TYPED(assignComplexNumberTo)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
    TYPED(setValueToRealPart)(num1, TYPED(getRealPart)(num2));
    TYPED(setValueToImaginaryPart)(num1, TYPED(getImaginaryPart)(num2));
  }

  // returns an allocated copied complex number
  TYPED(Complex_t*) TYPED(copyComplexNumberTo)(TYPED(Complex_t*) num) {
    TYPED(Complex_t*) copy = TYPED(createComplexNumber)(TYPED(getRealPart)(num), TYPED(getImaginaryPart)(num));
    return copy;
  }

  // is module 0?
  int TYPED(isModuleZero)(TYPED(Complex_t*) num) {
    if (TYPED(getModuleComplexNumber)(num) <= EPSILON) {
      return TRUE;
    } 
    return FALSE;
  }

  // is only real number?
  int TYPED(isOnlyRealNumber)(TYPED(Complex_t*) num) {
    if (TYPED(getImaginaryPart)(num) <= EPSILON) {
      return TRUE;
    } 
    return FALSE;
  }

  // is only imaginary number?
  int TYPED(isOnlyImaginaryNumber)(TYPED(Complex_t*) num) {
    if (TYPED(getRealPart)(num) <= EPSILON) {
      return TRUE;
    }
    return FALSE;
  }

  // 1 - number1 > number2
  // 0 - number1 == number2
  // -1 - number1 < number2
  int TYPED(compareComplex)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
    if (abs(TYPED(getModuleComplexNumber)(num1) - TYPED(getModuleComplexNumber)(num2)) < EPSILON2) {
      return 0;
    }
    else if (TYPED(getModuleComplexNumber)(num1) > TYPED(getModuleComplexNumber)(num2)) {
      return 1;
    }
    else {
      return -1;
    }
  }

  // free a complex number
  void TYPED(freeComplexNumber)(TYPED(Complex_t*) num) {
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
  TYPED(Complex_t*) TYPED(calculateConjugateComplex)(TYPED(Complex_t*) num) {
    TYPE realPart = TYPED(getRealPart)(num);
    TYPE imaginaryPart = -(TYPED(getImaginaryPart)(num)); // * -1
    TYPED(Complex_t*) conjugate = TYPED(createComplexNumber)(realPart, imaginaryPart);

    return conjugate;
  }

  // sum operation
  TYPED(Complex_t*) TYPED(sumComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
    // calculate real part sum
    TYPE sumReal = TYPED(getRealPart)(num1) + TYPED(getRealPart)(num2);
    // calculate imaginary part sum
    TYPE sumImaginary = TYPED(getImaginaryPart)(num1) + TYPED(getImaginaryPart)(num2);
    // create allocated sum num
    TYPED(Complex_t*) sum = TYPED(createComplexNumber)(sumReal, sumImaginary);
    // return it
    return sum;
  }

  // subtraction operation
  TYPED(Complex_t*) TYPED(subtractComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
    // calculate real part sum
    TYPE subReal = TYPED(getRealPart)(num1) - TYPED(getRealPart)(num2);
    // calculate imaginary part sum
    TYPE subImaginary = TYPED(getImaginaryPart)(num1) - TYPED(getImaginaryPart)(num2);
    // create allocated subtract num
    TYPED(Complex_t*) sub = TYPED(createComplexNumber)(subReal, subImaginary);
    // return it
    return sub;
  }

  // multiplication operation
  TYPED(Complex_t*) TYPED(multiplyComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
    // calculate real part sum
    TYPE multiReal = TYPED(getRealPart)(num1) * TYPED(getRealPart)(num2) - TYPED(getImaginaryPart)(num1) * TYPED(getImaginaryPart)(num2);
    // calculate imaginary part sum
    TYPE multiImaginary = TYPED(getRealPart)(num1) * TYPED(getImaginaryPart)(num2) + TYPED(getImaginaryPart)(num1) * TYPED(getRealPart)(num2);
    
    // create allocated multi num
    TYPED(Complex_t*) multi = TYPED(createComplexNumber)(multiReal, multiImaginary);
    // return it
    return multi;
  }

  // division operation
  TYPED(Complex_t*) TYPED(divideComplexNumbers)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
    // calculate denominator
    TYPE denominator = pow(TYPED(getRealPart)(num2), 2) + pow(TYPED(getImaginaryPart)(num2), 2);
    // calculate real part
    TYPE divRealPart = (TYPED(getRealPart)(num1) * TYPED(getRealPart)(num2) + TYPED(getImaginaryPart)(num1) * TYPED(getImaginaryPart)(num2)) / denominator;
    // calculate imaginary part
    TYPE divImaginaryPart = (TYPED(getRealPart)(num2) * TYPED(getImaginaryPart)(num1) - TYPED(getRealPart)(num1) * TYPED(getImaginaryPart)(num2)) / denominator;

    // create allocated div num
    TYPED(Complex_t*) div = TYPED(createComplexNumber)(divRealPart, divImaginaryPart);
    // return it
    return div;
  }

  // accumulate num2 into num1 with a sum operation
  void TYPED(accumulateComplexSum)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
    // calculate sum
    TYPED(Complex_t*) sumNum = TYPED(sumComplexNumbers)(num1, num2);

    // set values to number 1
    TYPED(setValueToRealPart)(num1, TYPED(getRealPart)(sumNum));
    TYPED(setValueToImaginaryPart)(num1, TYPED(getImaginaryPart)(sumNum));

    // free allocated num
    TYPED(freeComplexNumber)(sumNum);
  }

  // accumulate num2 into num1 with a multiplication operation
  void TYPED(accumulateComplexMulti)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
    // calculate sum
    TYPED(Complex_t*) multiNum = TYPED(multiplyComplexNumbers)(num1, num2);

    // set values to number 1
    TYPED(setValueToRealPart)(num1, TYPED(getRealPart)(multiNum));
    TYPED(setValueToImaginaryPart)(num1, TYPED(getImaginaryPart)(multiNum));

    // free allocated num
    TYPED(freeComplexNumber)(multiNum);
  }

  // function to evaluate operation
  TYPED(Complex_t*) TYPED(evaluateComplexOperation)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2, char *op) {
    if (!strcmp(op, "+")) {
      return TYPED(sumComplexNumbers)(num1, num2);
    } else if (!strcmp(op, "-")) {
      return TYPED(subtractComplexNumbers)(num1, num2);
    } else if (!strcmp(op, "*")) {
      return TYPED(multiplyComplexNumbers)(num1, num2);
    } else if(!strcmp(op, "/")) {
      return TYPED(divideComplexNumbers)(num1, num2);
    } else if (!strcmp(op, "+=")) {
      TYPED(accumulateComplexSum)(num1, num2);
    } else if (!strcmp(op, "*=")) {
      TYPED(accumulateComplexMulti)(num1, num2);
    }
  }


  // display complex number
  void TYPED(displayComplexNumber)(TYPED(Complex_t*) num) {
    TYPE imaginary = TYPED(getImaginaryPart)(num); 
    printf(FORMAT, TYPED(getRealPart)(num));

    if (imaginary >= 0) {
      printf("+ ");
    }

    printf(FORMAT, imaginary);
    printf("i");
    printf("\n");
  }


// if rational included
#else
  struct TYPED(complex) {
    TYPE *real;
    TYPE *imag;
  };


  TYPED(Complex_t*) TYPED(createComplexNumber)(TYPE* real, TYPE* imag) {
    TYPED(Complex_t) *allocatedComplex = (TYPED(Complex_t*)) malloc(sizeof(TYPED(Complex_t)));

    if (allocatedComplex == NULL) {
      printf("Insuficient Space!");
      exit(1);
    }

    allocatedComplex->real = createRationalNumber(getNumerator(real), getDenominator(real));
    allocatedComplex->imag = createRationalNumber(getNumerator(imag), getDenominator(imag));

    return allocatedComplex;
  }

  void TYPED(displayComplexNumber)(TYPED(Complex_t*) num) {
    displayRationalNumber(num->real);
    printf(" + ");
    displayRationalNumber(num->imag);
    printf("i");
  }

  void TYPED(freeComplexNumber)(TYPED(Complex_t*) num) {
    freeRationalNumber(num->real);
    freeRationalNumber(num->imag);
    free(num);
  }
#endif
#endif
#endif
#endif