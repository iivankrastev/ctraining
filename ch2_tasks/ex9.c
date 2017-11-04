/*
Exercise 2-9. In a two’s complement number system, x &= (x-1) deletes the
rightmost 1-bit in x . Explain why. Use this observation to write a faster version
of bitcount .
*/

#include <stdio.h>

int bitcount2 (unsigned int x);

int main (void){

    unsigned int a = 15;
   
    printf("The number %d has %d ones in binary\n", a, bitcount2(a));

    return 0;
}

int bitcount2 (unsigned int x){
    
    int b;

    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}
