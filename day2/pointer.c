#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    long l;
    int *p = &i;

    printf("%d %d %d %lu\n",
	    sizeof (i), sizeof (l),
	    sizeof (p), sizeof (*p));
    return 0;
}
