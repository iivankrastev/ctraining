/*
Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
*/
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int c;

    if ((c = fgetc(stdin)) != EOF)
        fputc('1',stdout);
    else
        fputc('0',stdout);
}
