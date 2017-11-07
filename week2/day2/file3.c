#include <stdio.h>


int main (void){
    
    FILE *f;
    int i;

    f = fopen("file","r+");

    fseek(f,0,SEEK_END);
    for (i = 0; i<5; i++)
	fputc('z',f);

    fclose(f);
}
