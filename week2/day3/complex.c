#include <stdio.h>

#include "complex.h"

int main (void){
    
    complex t0, t1, z;

    Re(t0) = 1.0;
    Im(t0) = 1.0;
    Re(t1) = -1.0;
    Im(t1) = -1.0;

    MUL3(z, t0, t1);   /* t0 *= t1 */

    printf ("(%lf, %lf)\n", Re(z), Im(z));

    return 0;
}
