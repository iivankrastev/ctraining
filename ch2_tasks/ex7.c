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
    
    unsigned char a = 0xffu;

    printf("%x\n",invert(a,6,7));

    return 0;
}

unsigned char invert (unsigned char x,
		      unsigned char p,
		      unsigned char n){
 
    unsigned char a, b, c, d, e, f, y, w, z;
    
    if (p < 0 || p > 7)			    /*if position is out of range*/
	y = 'Z';

    if (p < (n + 2))			    /*if desired bits are out of range*/
	y = 'Z';


    w = x & (0xffu << (p + 1));		    
    z = x & (0xffu >> (8 - (p + 1) + n));  
    
    a = x >> (p + 1 - n);		    
    b = ~(0xffu << n);			    
    c = a & b;				    
    d = (~c) & b;	
    e = d << (p + 1 - n);

    y = w | z | e;

    return y;
}


