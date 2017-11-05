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

    //int *p = (int *)calloc(1,sizeof(int));
    int *p = (int *)malloc(sizeof(int));

    printf ("pointer p addr : %p\n", p);
    printf ("pointer p value : %d\n", *p);
    *p = *t0;
    printf ("pointer p addr : %p\n", p);
    printf ("pointer p value : %d\n", *p);
    *t0 = *t1;
    *t1 = *p;
    printf ("pointer p addr : %p\n", p);
    printf ("pointer p value : %d\n", *p);
    /*
    int t;
    t = *t0;
    *t0 = *t1;
    *t1 = t;
    */  
    return;

}
