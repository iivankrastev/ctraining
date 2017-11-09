#include <stdio.h>

#include "complex.h"
#include <math.h>

int main(void) {

	complex z;
	//double abs;

	z.Re = 5.0;
	z.Im = -8.0;

	//ABSC(abs, z);
	//EULER(z, 1.0, M_PI / 6.0);
	//ABSC(z);

	printf("%lf\n", ABSC(z));
	//printf("(%lf, %lf)\n", LEN(z), ARG(z));

	return 0;
}
