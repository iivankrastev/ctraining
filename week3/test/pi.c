#include <stdio.h>
#include <math.h>


int main void(void){
 
    double delta_x, x;
    double pi;

    scanf("%lf", delta_x);

    for (pi = 0.0, x = -1.0; x < 1.0; x += delta_x)
	pi += sqrt(1.0 - x * x) * delta_x;

    pi * = 2.0

    printf ("%0.10lf\n", pi);

}
