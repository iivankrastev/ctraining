#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    
    int a, sum=0;

    scanf("%d",&a);
    while(a){
	    sum+=a;
	    scanf("%d",&a);
    }
    printf("%d\n",sum);
    return 0;
}
