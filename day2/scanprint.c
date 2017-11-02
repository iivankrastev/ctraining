#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    
    int r;
    char c;

    for(r=fgetc(stdin);r>=0;r=fgetc(stdin)){
	
	c=(char)(r&0xff);
	fputc(c,stdout);
    }


    return 0;
}
