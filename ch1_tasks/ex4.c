/*
Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit
table.
*/
#include <stdio.h>

int main(void){

    int fahr, celsius, lower = 0,
                       upper = 300,
                       step = 20;
    fahr = lower;
    printf("******Celsius-> Fahrenheit Table******\n");
    printf("Celsius:\tFahrenheit:\n");
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t\t%d\n", celsius, fahr);
        fahr = fahr + step;
    }
    return 0;
}
