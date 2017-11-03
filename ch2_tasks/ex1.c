/*
Exercise 2-1. Write a program to determine the ranges of char , short , int ,
and long variables, both signed and unsigned , by printing appropriate
values from standard headers and by direct computation. Harder if you com-
pute them: determine the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>

int main(void){

    printf("MAX value -> char: %d\n", CHAR_MAX);        
    printf("MIN value -> char: %d\n", CHAR_MIN);      
    printf("MAX value -> unsigned char: %u\n\n", (unsigned char)UCHAR_MAX);    
  
    printf("MAX value -> short: %d\n", SHRT_MAX);               
    printf("MIN value -> short: %d\n", SHRT_MIN);             
    printf("MAX value -> unsigned short: %u\n\n", (unsigned short)USHRT_MAX);   

    printf("MAX value -> int: %d\n", INT_MAX);                  
    printf("MIN value -> int: %d\n", INT_MIN);                
    printf("MAX value -> unsigned int: %u\n\n", (unsigned int)UINT_MAX);        

    printf("MAX value -> long: %ld\n", LONG_MAX);               
    printf("MAX value -> long: %ld\n", LONG_MIN);             
    printf("MAX value -> unsigned long: %lu\n", (unsigned long)ULONG_MAX);   

    return 0;
}
