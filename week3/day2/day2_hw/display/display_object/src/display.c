#include <stdlib.h>
#include <stdio.h>

#include "display_object.h"
#include "internal/display.h"

void *display_create(unsigned char *_d, int M, int N){
    
    display *d = (display *)malloc(sizeof(display));

    if (!d) return NULL;
    
    d->rows = M;
    d->columns = N;
    d->d = _d;
    
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

void bresenham_ellipse (void *_display, int xc, int yc, int rx, int ry){
    
    int x, y, p;

    x = 0;
    y = ry;
    p = (ry * ry) - (rx * rx * ry) + ((rx * rx) / 4);
    
    while ( (2 * x * ry * ry) < (2 * y * rx * rx) ) {
        setpixel(_display, xc+x, yc-y, 1);
        setpixel(_display, xc-x, yc+y, 1);
        setpixel(_display, xc+x, yc+y, 1);
        setpixel(_display, xc-x, yc-y, 1);

        if (p < 0) {
	    x = x + 1;
	    p = p + (2 * ry * ry * x) + (ry * ry);
        } else {
	    x = x + 1;
	    y = y - 1;
	    p = p + (2 * ry * ry * x + ry * ry) - (2 * rx * rx * y);
        }
    }

    p = ((float)x + 0.5) * ((float)x + 0.5) * ry * ry + 
	(y - 1) * (y - 1) * rx * rx - rx * rx * ry * ry;

    while (y >= 0) {
	setpixel(_display, xc+x, yc-y, 1);
        setpixel(_display, xc-x, yc+y, 1);
        setpixel(_display, xc+x, yc+y, 1);
        setpixel(_display, xc-x, yc-y, 1);

        if (p > 0) {
	    y = y - 1;
	    p = p -(2 * rx * rx * y) + (rx * rx);
        } else {
	    y = y - 1;
	    x = x + 1;
	    p = p + (2 * ry * ry * x) - (2 * rx * rx * y) - (rx * rx);
        }
    }
}

