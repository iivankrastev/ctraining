#include <stdio.h>
#include <stdlib.h>

int main (void){
    
    char a = 0xffu;
    
    printf("%x %d\n", a, a);
    a >>= 3;

    printf("%x %d\n", a, a);
    
    return 0;
}
