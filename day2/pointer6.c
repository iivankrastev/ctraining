#include <stdio.h>
#include <stdlib.h>


int main(void){
    
    int *b, i;
    void *mem;
    mem = malloc(5*sizeof(int));
    b = NULL;

    printf("%lu\n",(unsigned long)b);
    for(i=0;i<5;i++)
	printf("%d\n",b[i]);
    free(b);

    return 0;
}
