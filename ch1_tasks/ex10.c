/*
Exercise 1-10. Write a program to copy its input to its output, replacing each
tab by \t, each backspace by \b, and each backslash by \\. This makes tabs
and backspaces visible in an unambiguous way.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int r;

	for(r=fgetc(stdin);r>=0;r=fgetc(stdin)){
        if (r == '\t')
            printf("\\t");
        else if (r == '\b')
            printf("\\b");
        else if (r == '\\')
            printf("\\\\");
        else
            fputc(r,stdout);
    }

    return 0;
}
