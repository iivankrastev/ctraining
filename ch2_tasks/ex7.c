/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
the others unchanged.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned char invert (unsigned char x,
		      unsigned char p,
		      unsigned char n);


unsigned char getbits(unsigned char x,
		      unsigned char p,
		      unsigned char n);

int main (void){
    
    unsigned char a = 0xB6u;

    printf("%x\n",invert(a,5,4));
    //printf("%x\n",getbits(a,4,4));

    return 0;
}

unsigned char invert (unsigned char x,
		      unsigned char p,
		      unsigned char n){
    unsigned char a, b, c, d, e, f, y, w, z;

    w = x & (0xffu << (p + 1));
    z = x & (0xffu >> (p - 1 + n));
    
    a = x >> (p + 1 - n);
    b = ~(0xffu << n);
    c = a & b;
    d = (~c) & b;
    e = d << (p + 1 - n);

    y = w | z | e;

    return y;
}

unsigned char getbits(unsigned char x,
		      unsigned char p,
		      unsigned char n){

    return /*(x >> (p+1-n)) & ~*/(0xffu << n);
}
