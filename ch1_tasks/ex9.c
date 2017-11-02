/*
Exercise 1-9. Write a program to copy its input to its output,
replacing each string of one or more blanks by a single blank.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int blank = 0;
    int r;

    for (r = fgetc(stdin); r >= 0; r = fgetc(stdin)){
        if (!blank || r != ' ')
            fputc(r,stdout);
        blank = (r == ' ');
    }

    return 0;
}
