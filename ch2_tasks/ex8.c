/*
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions.
*/

#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);

int main(void){
  
    unsigned int num = 10,
		 n = 3;

    printf("%u, %u: %x\n", num, n, rightrot(num, n));
      
    return (0);
}

unsigned int rightrot (unsigned int x, unsigned int n){
    
    while (n > 0) {
        if ((x & 1) == 1)
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = (x >> 1);
        n--;
    }
    return x;
}
