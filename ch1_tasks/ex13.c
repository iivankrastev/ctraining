/*
Ex.1.13 Write a program to print a histogram of the lengths of words
in its input. It is easy to draw the histogram with the bars horizontal; a vertical
orientation is more challenging.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int r;

	for(r=fgetc(stdin);r>=0;r=fgetc(stdin)){
        if ( r == ' ' || r == '\n' || r == '\t')
            fputc('\n',stdout);
        else {
            fputc('*',stdout);
        }
    }

    return 0;
}
