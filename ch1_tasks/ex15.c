/*
Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
use a function for conversion.
*/

#include <stdio.h>

enum {
    LOWER = 0,
    UPPER = 300,
    STEP = 20,
};

void print_fahr_cels_table (int low, int upp, int st);

int main (void) {

    print_fahr_cels_table (LOWER ,UPPER, STEP);
    return 0;
}

void print_fahr_cels_table(int low, int upp, int st) {

    int fahr, celsius;

    fahr = low;
    printf ("******Fahrenheit -> Celsius Table******\n");
    printf ("Fahrenheit:\tCelsius:\n");
    while (fahr <= upp) {
        celsius = 5 * (fahr - 32) / 9;
        printf ("%d\t\t%d\n", fahr, celsius);
        fahr = fahr + st;
    }

    return;
}





