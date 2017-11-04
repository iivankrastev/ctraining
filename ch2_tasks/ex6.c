/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y , leaving the other
bits unchanged.
*/

#include <stdio.h>

unsigned char setbits(unsigned char x,
		      unsigned char p,
		      unsigned char n,
		      unsigned char y);

int main (void){
	
	unsigned char num1 = 0xfeu,
		      num2 = 0x40u,
		      p = 6,
		      n = 3;

	if ((p > 8) || (n > 8)){
		printf ("The postion and the amount of bits must be less than 8 bits. \n");
		return(1);
	} else  if (p < (n-2)){
		printf ("The postion should be bigger than the amount of bits. \n");
		return (1); 
	} else{
	    printf("%x\n", setbits(num1, p, n, num2));
	}

	return(0);
}

unsigned char setbits(unsigned char x,
		      unsigned char p,
		      unsigned char n,
		      unsigned char y){

	return ((x & ~(~(~0 << n) << p+1-n)) | ((~(~0 << n) & y) << p+1-n));
}


