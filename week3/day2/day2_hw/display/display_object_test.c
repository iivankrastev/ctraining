#include <stdio.h>

#include "display_object/display_object.h"

#define ROWS 50
#define COLUMNS 50

int main (void){

    void *display;
    int x0, y0, x1, y1, xc, yc, r, rx, ry, i, j;
    unsigned char pixel;
    
    x0 = ROWS/2;
    y0 = COLUMNS/2;
    x1 = ROWS;
    y1 = COLUMNS;
    xc = 20;
    yc = 20;
    rx = 20;
    ry = 20;
    r = 10;

    display = display_create(ROWS, COLUMNS);
    
    //bresenham_line (display, x0, y0, x1, y1);
    //bresenham_circle (display, x0, y0, r);
    bresenham_ellipse (display, xc, yc, rx, ry);
    
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
