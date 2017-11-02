/*Exercise 1-3. Modify the temperature conversion program to print a heading
above the table.*/

#include <stdio.h>

int main(void){

    int fahr, celsius, lower = 0,
                       upper = 300,
                       step = 20;
    fahr = lower;
    printf("******Fahrenheit -> Celsius Table******\n");
    printf("Fahrenheit:\tCelsius:\n");
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
