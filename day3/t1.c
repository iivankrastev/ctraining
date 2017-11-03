#include <stdio.h>

const int global = 69;

void modify(void);

int main(void){

    modify();
    printf("%d\n",global);

    return 0;
}

