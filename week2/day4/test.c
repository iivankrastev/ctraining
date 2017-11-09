#include <stdio.h>
#include <math.h>

#include "complex.h"

int main (void){
    
    complex z;
    int j;

    for (j = 0; j < 6; j++){
	EULER(z, 1.0, (double)j * M_PI / 6.0);
	printf ("(%lf, %lf)\n", Re(z), Im(z));
    }

    return 0;
}
