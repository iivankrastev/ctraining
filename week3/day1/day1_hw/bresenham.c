#include    <stdio.h>
#include    <stdlib.h>

void setpixel(unsigned char *, int, int, int, int, unsigned char);
unsigned char getpixel(unsigned char *, int, int, int, int);
void bresenham_line (unsigned char *, int, int, int, int);
void init_display (unsigned char *, int, int);

enum {
    ROWS = 20,
    COLUMNS = 20
};

int main(){
     
    int x0 , y0, x1, y1 ,i ,j;
    unsigned char display[ROWS * COLUMNS], pixel;
    	
    init_display (display, ROWS, COLUMNS);
    x0 = 0;
    y0 = 0;
    x1 = 20;
    y1 = 20;

    if ( (x1 > ROWS) || (y1 > COLUMNS) ){
	printf("OUT OF RANGE!\n");
	return 1;
    }

    bresenham_line (display, x0, y0, x1, y1);

    for (i = 0; i < ROWS; i++) {
	printf("|");
	for (j = 0; j < COLUMNS; j++) {
	    pixel = getpixel(display, ROWS, COLUMNS, i, j);
	    printf("%c", pixel ? '*' : ' ');
	}
	printf("|\n");
    }

    return 0;
}


void setpixel(unsigned char *display, int M, int N, int i, int j, unsigned char value) {
	if ((i < 0) || (i >= M)) return;
	if ((j < 0) || (j >= N)) return;
	display[i * N + j] = value;
	return;
}

unsigned char getpixel(unsigned char *display, int M, int N, int i, int j) {
	if ((i < 0) || (i >= M)) return 0u;
	if ((j < 0) || (j >= N)) return 0u;
	return display[i * N + j];
}

void init_display (unsigned char *display, int M, int N){
    int i;

    for (i = 0; i < M * N; i++)
	display[i] = 0u;
}

void bresenham_line (unsigned char *display, int x0, int y0, int x1, int y1){
    
    int x, y, dx, dy, D;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
  
    D = 2*dy - dx;
    
    y = y0;

    for (x = 0; x < x1; x++){
	setpixel(display, ROWS, COLUMNS, x, y, 255);
	    
	if (D > 0){
	    y = y + 1;
	    D = D - 2 * dx;
	}
	D = D + 2 * dy;
    }

    return;
}
