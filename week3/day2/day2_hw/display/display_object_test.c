#include <stdio.h>

#include "display_object/display_object.h"

#define ROWS 50
#define COLUMNS 50

int main (void){

    void *display;
    int i, j;
    unsigned char d[ROWS * COLUMNS], pixel;

    for (i = 0; i < (ROWS * COLUMNS); i++)
	d[i] = 0u;

    display = display_create(d, ROWS, COLUMNS);
    
    bresenham_line (display, 0, 0, ROWS, COLUMNS);
    bresenham_circle (display, ROWS/2, COLUMNS/2, 10);
    bresenham_ellipse (display, ROWS/2, COLUMNS/2, 15, 15);
    
    for (i = 0; i < ROWS; i++) {
	printf("|");
	for (j = 0; j < COLUMNS; j++) {
	    pixel = getpixel(display, i, j);
	    printf("%c", pixel ? '*' : ' ');
	}
	printf("|\n");
    }

    display_destroy(display);

    return 0;
}
