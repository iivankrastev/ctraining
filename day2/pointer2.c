#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int a[10],i,*p;
    
    for(i=0;i<10;i++)
	a[i]=i;
    for(p=a,i=0;i<10;i++)   //*a == a[0]    a==&a[0]
	printf("%p %d\n",p+i,*(p+i));

    return 0;
}
