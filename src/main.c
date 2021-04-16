#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/complex-int.h"
#include "../include/complex-double.h"
#include "../include/complex-rational.h"
#include "../include/rational-numbers.h"
#include "../include/conversions.h"
#include "../include/vectors-int.h"
#include "../include/vectors-double.h"

#include "../include/vectors-complex-double.h"


int main(void) {
  DOUBLE_VECT_VectComplex_t* test = DOUBLE_VECT_createVector(10, 0);
  DOUBLE_displayVector(test);
  DOUBLE_VECT_freeVector(test);

  
 // create a vector
  return 0;
}
