#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int a[10];
    int i;

    for(i=0;i<10;i++){
	a[i]=i;
	printf("%d",a[i]);
    }

    return 0;
}
