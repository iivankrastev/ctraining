#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

int set_pixel (unsigned char **display, int m, int n, unsigned char value);

int main (void){
    
    int i, j;
    unsigned char **display = (unsigned char **)calloc(ROWS, sizeof(unsigned char *));

    for (i = 0; i < ROWS; i++)
	display[i] = (unsigned char *)calloc(COLUMNS, sizeof(unsigned char));
   
    (void)set_pixel(display, 5, 6, 0xABu);

    for (i = 0; i < ROWS; i++){
	for (j = 0; j < COLUMNS; j++){
	    printf ("%d\t", display[i][j]);		
	}
	printf("\n");
    }

}

int set_pixel (unsigned char **display, int m, int n, unsigned char value){
    
    if (m > ROWS || n > COLUMNS)
	return 0;
    
    display[m][n] = value;

    return 1;
}






