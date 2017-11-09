#include <stdio.h>
#include "complex.h"

int main (void){

    complex z;
    double a;

    Re(z) = 8.0;
    Im(z) = 3.0;

    //SINC(a, z);
    SINC(a, z);
    //LOGC(z);
    //EXPC(z);
    printf ("%lf\n", a); 
    //printf ("(%lf + %lf)\n", Re(z), Im(z) );

    return 0;
}
