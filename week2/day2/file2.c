#include <stdio.h>


int main (void){
    
    int i;
    FILE *f;
    f = fopen("file2","w+");

    for (i=0; i<10; i++){
	fputc(i,f);
	printf("%ld\n", ftell(f));
    }

    fclose(f);
}
