#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void xchg (int *t0, int *t1);

int main(void){

    int a = 10, 
	b = 20;

    printf("a : %d\nb : %d\n",a,b);
    xchg(&a, &b);
    printf("a : %d\nb : %d\n",a,b);

    return 0;
}

void xchg (int *t0, int *t1){

    int t;

    t = *t0;
    *t0 = *t1;
    *t1 = t;
        
    return;

}
