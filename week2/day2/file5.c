#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    int a[16], i;

    FILE *f;

    f = fopen("file2","w+");

    for (i = 0; i>-16; i--)
	a[abs(i)] = i;
    
    fwrite(a, 1, sizeof(a), f);

    fclose(f);
}
