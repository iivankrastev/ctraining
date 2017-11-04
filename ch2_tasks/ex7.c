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

int main (void){
    
    unsigned char a = 0xe9u;

    printf("%x\n",invert(a,6,4));

    return 0;
}

unsigned char invert (unsigned char x,
		      unsigned char p,
		      unsigned char n){
    
    const unsigned char mask_left = (0xffu << (p + 1)),
			mask_right = (0xffu >> (8 - (p + 1) + n)),
			shift_const = (p + 1 - n);
    unsigned char a, t;
    
    if (p > 7){					    
	printf("Invalid position!\n");
	return 1;
    }

    if (p < (n - 1)){				    
	printf("Invalid field of bits!\n");
	return 2;
    }

    t = (x & mask_left) | (x & mask_right);    
    x >>= shift_const;
    a = ~x & ~(0xffu << n);
    a <<= shift_const; 

    return (t | a);
}


