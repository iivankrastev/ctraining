/*
Exercise 2-9. In a two’s complement number system, x &= (x-1) deletes the
rightmost 1-bit in x . Explain why. Use this observation to write a faster version
of bitcount .
*/

#include <stdio.h>

int bitcount(unsigned x);
char test(char a);

int main (void){

    unsigned int x = 15;
    char y = -15;
   
    printf ("%x\n",test(y));
    //printf("The number %d has %d ones in binary\n", x, bitcount(x));

    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned int x) {
    
    int b;

    for (b = 0; x != 0; x >>= 1)
	if (x & 01)
	    b++;

    return b;
}

char test(char a){
    
    return  (a &= (a-1));
}
