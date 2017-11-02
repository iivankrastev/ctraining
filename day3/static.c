#include <stdio.h>

int get (void){
    static int i = -1;
    return ++i;
}


int main(void){
    
    int i;

    for(i = 0; i < 10; i++)
	printf("%d\n", get());
    return 0;
}
