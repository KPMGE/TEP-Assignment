#ifdef TYPED
#ifdef TYPE
#ifdef FORMAT

#define EPSILON 0.0001

struct TYPED(complex) {
	TYPE *real;
	TYPE *imag;
};

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


// get/set values into a complex number
TYPE TYPED(getRealPart)(TYPED(Complex_t*) num) {
	return *(num)->real;
}

TYPE TYPED(getImaginaryPart)(TYPED(Complex_t*) num) {
	return *(num)->imag;
}

double TYPED(getModuleComplexNumber)(TYPED(Complex_t*) num) {
	return sqrt(pow(TYPED(getRealPart)(num), 2) + pow(TYPED(getImaginaryPart)(num), 2));
}

double TYPED(getAngleComplexNumber)(TYPED(Complex_t*) num) {
	double module = TYPED(getModuleComplexNumber)(num);

	return acos(TYPED(getRealPart)(num) / module);
}

void TYPED(setValueToRealPart)(TYPED(Complex_t*) num, double value) {
	*(num)->real = value;
}

void TYPED(setValueToImaginaryPart)(TYPED(Complex_t*) num, double value) {
	*(num)->imag = value;
}

void TYPED(setModuleComplex)(TYPED(Complex_t*) num) {
	// we need to adjust angle!
	// we need to implement it
} 

void TYPED(setAngleComplex)(TYPED(Complex_t*) num) {
	// we need to adjust module!
	// we need to implement it
}

void TYPED(assignComplexNumberTo)(TYPED(Complex_t*) num) {
	// we need to implement it
}

void TYPED(copyComplexNumberTo)(TYPED(Complex_t*) num) {
	// we need to implement it
}


// comparison
int TYPED(isModuleZero)(TYPED(Complex_t*) num) {
	// we need to implement it
}

int TYPED(isOnlyRealNumber)(TYPED(Complex_t*) num) {
	// we need to implement it
}
int TYPED(isOnlyImaginaryNumber)(TYPED(Complex_t*) num) {
	// we need to implement it
}

int TYPED(compareComplex)(TYPED(Complex_t*) num1, TYPED(Complex_t*) num2) {
	if (abs(TYPED(getModuleComplexNumber)(num1) - TYPED(getModuleComplexNumber)(num2)) < EPSILON) {
		return 0;
	}
	else if (TYPED(getModuleComplexNumber)(num1) > TYPED(getModuleComplexNumber)(num2)) {
		return 1;
	}
	else {
		return -1;
	}
}

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

void TYPED(displayComplexNumber)(TYPED(Complex_t*) num) {
  printf(FORMAT, TYPED(getRealPart)(num));
  printf("/ ");
  printf(FORMAT, TYPED(getImaginaryPart)(num));
  printf("\n");
}

#endif
#endif
#endif