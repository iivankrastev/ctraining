#include <stdlib.h>

#include "display_object.h"
#include "internal/display.h"

void *display_create(int M, int N){
    
    display *d = (display *)calloc(N*M, sizeof(display));
    if (!d) return NULL;

    d->rows = M;
    d->columns = N;
    
    return (void *)d;

}

void display_destroy(void *_display){

    free(_display);
    return;
}

void setpixel(void *_display, int M, int N, int x, int y, unsigned char value) {
    
    display *d = (display *)_display;

    if ((x < 0) || (x >= M)) return;
    if ((y < 0) || (y >= N)) return;
    
    d->d[x * N + y] = value;

    return;
}

unsigned char getpixel(void *_display, int M, int N, int x, int y) {

    display *d = (display *)_display;
    
    if ((x < 0) || (x >= M)) return 0u;
    if ((y < 0) || (y >= N)) return 0u;
    
    return d->d[x * N + y];
}

void bresenham_line (void *_display, int M, int N, int x0, int y0, int x1, int y1){
    
    display *d = (display *)_display;

    int x, y, dx, dy, D;
    
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
  
    D = 2*dy - dx;
    
    y = y0;

    for (x = 0; x < x1; x++){

	setpixel(_display, M, N, x, y, 255);
	
	if (D > 0){
	    y = y + 1;
	    D = D - 2 * dx;
	}
	D = D + 2 * dy;
    }
}
