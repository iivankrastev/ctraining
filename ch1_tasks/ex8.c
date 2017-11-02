/*
Exercise 1-8. Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int r, bl = 0,
           tb = 0,
           nl = 0;

    for(r = fgetc(stdin); r >= 0; r = fgetc(stdin)) {
        if (r == '\n')
            ++nl;
        if (r == ' ')
            ++bl;
        if (r == '\t')
            ++tb;
    }
    printf("Blanks: %d\n Tabs: %d\n Newlines: %d\n",bl,tb,nl);

    return 0;
}

