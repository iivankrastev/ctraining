#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    char *s="012345";	//points to first element (0)
    char *p;

    printf("%s\n",s);
    printf("%p\n",s);

    for(p=s;*p;p++)
	printf("%p %c\n",p,*p);

    return 0;
}
