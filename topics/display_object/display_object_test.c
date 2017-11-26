#include <stdio.h>

#include "display_object/display_object.h"

#define ROWS 20
#define COLUMNS 20

int main (void){

    void *display;
    int x0, y0, x1, y1, i, j;
    unsigned char pixel;
    
    x0 = 0;
    y0 = 0;
    x1 = ROWS;
    y1 = COLUMNS;

    display = display_create(ROWS, COLUMNS);
    
    bresenham_line (display, x0, y0, x1, y1);
    
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
