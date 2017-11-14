#include <stdlib.h>
#include <stdio.h>

#include "display_object.h"
#include "internal/display.h"

void *display_create(int M, int N){
    
    display *d = (display *)malloc(sizeof(display));

    if (!d) return NULL;
    
    d->rows = M;
    d->columns = N;
    d->d = (unsigned char *)calloc(d->rows * d->columns, sizeof(unsigned char));
    
    return (void *)d;

}

void display_destroy(void *_display){

    free(_display);
    return;
}

void setpixel(void *_display, int x, int y, unsigned char value) {
    
    display *d = (display *)_display;
    
    if ((x < 0) || (x >= d->rows)) return;
    if ((y < 0) || (y >= d->columns)) return;
    d->d[x * d->columns + y] = value;
    return;
}

unsigned char getpixel(void *_display, int x, int y) {

    display *d = (display *)_display;
    
    if ((x < 0) || (x >= d->rows)) return 0u;
    if ((y < 0) || (y >= d->columns)) return 0u;
    
    return d->d[x * d->columns + y];
}

void bresenham_line (void *_display, int x0, int y0, int x1, int y1){
    
    int x, y, dx, dy, D;
    
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
  
    D = 2*dy - dx;
    
    y = y0;

    for (x = 0; x < x1; x++){
	setpixel(_display, x, y, 1);
	if (D > 0){
	    y = y + 1;
	    D = D - 2 * dx;
	}
	D = D + 2 * dy;
    }
}

void bresenham_circle (void *_display, int x0, int y0, int radius){

    int x, y, dx, dy, err;
    
    x = radius - 1;
    y = 0;
    dx = 1;
    dy = 1;
    err = dx - (radius << 1);

    while (x >= y) {
        setpixel(_display, x0 + x, y0 + y, 1);
        setpixel(_display, x0 + y, y0 + x, 1);
	setpixel(_display, x0 - y, y0 + x, 1);
        setpixel(_display, x0 - x, y0 + y, 1);
        setpixel(_display, x0 - x, y0 - y, 1);
        setpixel(_display, x0 - y, y0 - x, 1);
        setpixel(_display, x0 + y, y0 - x, 1);
        setpixel(_display, x0 + x, y0 - y, 1);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0) {
            x--;
            dx += 2;
            err += (-radius << 1) + dx;
        }
    }
}
