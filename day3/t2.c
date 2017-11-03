#include <stdio.h>

extern const int global;

void modify(void){
    
    printf("%d\n",global);

    return;
}
