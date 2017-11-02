/*
Exercise 1-12. Write a program that prints its input one word per line.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int r;
	for(r=fgetc(stdin);r>=0;r=fgetc(stdin)){
        if (r == ' ')
            printf("\n");
        else
            fputc(r,stdout);
    }

    return 0;
}
