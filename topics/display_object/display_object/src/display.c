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
    
   // printf("time to SET!\n");
    if ((x < 0) || (x >= d->rows)) return;
    if ((y < 0) || (y >= d->columns)) return;
  //  printf("check COMPLETE\n"); 
    d->d[x * d->columns + y] = value;
    printf("OK\n");
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
	//printf("before SET!\n");
	setpixel(_display, x, y, 1);
	printf("after SET");
	if (D > 0){
	    y = y + 1;
	    D = D - 2 * dx;
	}
	D = D + 2 * dy;
    }
}
